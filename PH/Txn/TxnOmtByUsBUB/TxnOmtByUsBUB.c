/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 		Change Date             Change By
-------------------------------                    		------------            --------------
Init Version                                       		2019/08/19              Michael Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsBUB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsBUB(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext, const hash_t* hRequest, hash_t* hResponse)
{
	int iRet = PD_OK;
	int iDtlRet = FOUND;
	int iUpdHdRet = PD_ERR;

	int iRecordCnt = 0;
	int iSuccessCnt = 0;
	int iCnt = 0;

	char cStatus;

	char* csBatchId = NULL;
	char* csTxnCode = NULL;
	char* csUser = NULL;

	hash_t* hBulkHeader;
	hBulkHeader = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBulkHeader,0);

	hash_t* hRec = NULL;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("TxnOmtByUsBUB:: Authorize\n"));

	// get batch_id
	if(GetField_CString(hRequest, "batch_id", &csBatchId)){
DEBUGLOG(("batch_id = [%s]\n", csBatchId));
		PutField_CString(hBulkHeader, "batch_id", csBatchId);
	}
	else{
DEBUGLOG(("batch_id not found!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: batch_id not found!!\n");
		iRet = INT_BATCH_ID_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}
	
	// get txn_code	
	if(iRet == PD_OK){
		if(GetField_CString(hContext, "txn_code", &csTxnCode)){
DEBUGLOG(("txn_code = [%s]\n", csTxnCode));
			PutField_CString(hBulkHeader, "txn_code", csTxnCode);
		}
		else{
DEBUGLOG(("txn_code not found!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: txn_code not found!!\n");
			iRet = INT_TXN_CODE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get user
	if(iRet == PD_OK){
		if(GetField_CString(hContext, "add_user", &csUser)){
DEBUGLOG(("add_user = [%s]\n", csUser));
		}
		else{
DEBUGLOG(("add_user not found!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: add_user not found!!\n");
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get OLBulkHeader
	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLBulkHeader","Get");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBatchId, csTxnCode, hBulkHeader);
		if(iDtlRet == FOUND){
DEBUGLOG(("call OLBulkHeader::Get Found!!\n"));

			// check record_cnt
			if(GetField_Int(hBulkHeader, "record_cnt", &iRecordCnt)){
DEBUGLOG((" record_cnt = [%d]\n", iRecordCnt));
			}
			else{
DEBUGLOG((" record_cnt not found!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkHeader::Get record_cnt not found!!\n");
				iRet = INT_RECORD_CNT_NOT_FOUND;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// check status exists
			if(iRet == PD_OK){
				if(GetField_Char(hBulkHeader, "status", &cStatus)){
DEBUGLOG((" status = [%c]\n", cStatus));
					if(cStatus != PD_BULK_STATUS_INIT){
DEBUGLOG((" status not [I]!!\n")); 
						iRet = INT_INVALID_INIT_STATUS;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}
				else{
DEBUGLOG((" status not found!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkHeader::Get status not found!!\n");
					iRet = INT_STATUS_NOT_FOUND;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}

		}
		else if(iDtlRet == NOT_FOUND){
DEBUGLOG(("call OLBulkHeader::Get Not Found!!\n"));
			iRet = INT_RECORD_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else{
DEBUGLOG(("call OLBulkHeader::Get Error!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkHeader::Get Error!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}

		// update bulk header status to 'P'
		if(iRet == PD_OK){
			PutField_Char(hBulkHeader, "status", PD_BULK_STATUS_PROCESS); 

			DBObjPtr = CreateObj(DBPtr, "DBOLBulkHeader", "Update");
			iUpdHdRet = (unsigned long)(*DBObjPtr)(hBulkHeader);
			if(iUpdHdRet == PD_OK){
DEBUGLOG(("call OLBulkHeader::Update status[%c] Success!!\n", PD_BULK_STATUS_PROCESS));
				TxnCommit();
			}
			else{
DEBUGLOG(("call OLBulkHeader::Update status[%c] Failure!!\n", PD_BULK_STATUS_PROCESS));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkHeader::Update Failure!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	// get OLBulkDetail
	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLBulkDetail","GetByBatchId");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBatchId, rRecordSet);
		if(iDtlRet == FOUND){
DEBUGLOG(("call OLBulkDetail::GetByBatchId Found!!\n"));

			// Count no. of record in bulk detail
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				iCnt++;
				hRec = RecordSet_GetNext(rRecordSet);
			}

			// check if count valid
			if(iCnt == 0){
DEBUGLOG((" bulk detail record not found!!\n"));
				iRet = INT_RECORD_NOT_FOUND;
				PutField_Int(hContext, "internal_error", iRet);
			}
			else if(iCnt != iRecordCnt){
DEBUGLOG((" bulk detail cnt [%d] is not equal to bulk header cnt [%d]!!\n", iCnt, iRecordCnt));
				iRet = INT_INVALID_COUNT;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
		else if(iDtlRet == NOT_FOUND){
DEBUGLOG(("call OLBulkDetail:: GetByBatchId Not Found!!\n"));
			iRet = INT_RECORD_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else{
DEBUGLOG(("call OLBulkDetail::GetByBatchId Error!!\n"));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::GetByBatchId Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}

		// loop bulk detail records
		if(iRet == PD_OK){
			iCnt = 0;

			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){

				int iRetCode = PD_OK;

				int iSeq = 0;

				char* csBuf = (char*)malloc(64); 
				char* csTmp = NULL;
				char* csOrgStatus = NULL;
				char* csNewStatus = NULL;

				char* csBaid = NULL;
				

				hash_t* hBulkDetail;
				hBulkDetail = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hBulkDetail,0);

				hash_t* hGetAttribute;
				hGetAttribute = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hGetAttribute,0);

				hash_t* hTxnBAIReq;
				hTxnBAIReq = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hTxnBAIReq,0);




/* Get baid, baid_org_status, baid_new_status*/

				if(GetField_Int(hRec, "seq", &iSeq)){
DEBUGLOG((" [%d]seq = [%d]\n", iCnt, iSeq));
				}
				else{
DEBUGLOG((" [%d]seq not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::GetByBatchId seq not found!!\n");
					iRetCode = INT_SEQ_NOT_FOUND;
				}
/*baid*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "baid", &csBaid)){
DEBUGLOG((" [%d]baid = [%s]\n", iCnt, csBaid));
					}
					else{
DEBUGLOG((" [%d]baid not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::GetByBatchId baid not found!!\n");
						iRetCode = INT_BAID_NOT_FOUND;
					}
				}

/*baid_new_status*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "baid_new_status", &csNewStatus)){
DEBUGLOG((" [%d]baid_new_status = [%s]\n", iCnt, csNewStatus));
					}
					else{
DEBUGLOG((" [%d]baid_new_status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::GetByBatchId baid_new_status not found!!\n");
						iRetCode = INT_STATUS_NOT_FOUND;
					}
				}

/*baid_org_status*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "baid_org_status", &csOrgStatus)){
DEBUGLOG((" [%d]baid_org_status = [%s]\n", iCnt, csOrgStatus));
					}
					else{
DEBUGLOG((" [%d]baid_org_status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::GetByBatchId baid_org_status not found!!\n");
						iRetCode = INT_STATUS_NOT_FOUND;
					}
				}



				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetBankAcctIdDtl");
					iRetCode = (unsigned long)(*DBObjPtr)(csBaid, hGetAttribute);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call OLBankAcctId::GetBankAcctIdDtl Found!!\n", iCnt));
/*status*/
						if(GetField_CString(hGetAttribute, "status", &csTmp)){
DEBUGLOG((" [%d]status = [%s]\n", iCnt, csTmp));
							if(strcmp(csTmp,csOrgStatus) || !strcmp(csTmp, PD_BAID_STATUS_CLOSE)){	
DEBUGLOG((" [%d]invalid status!!\n", iCnt));
								iRetCode = INT_INVALID_BAID_STATUS;
							}
							else{
								PutField_CString(hTxnBAIReq, "status", csNewStatus);
							}
						}
						else{
DEBUGLOG((" [%d]status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBankAcctId::GetBankAcctIdDtl status not found!!\n");
							iRetCode = INT_STATUS_NOT_FOUND;
							
						}

						if(iRetCode == PD_OK){
							sprintf(csBuf, "%c", PD_ACTION_UPDATE);
							PutField_CString(hTxnBAIReq, "action", csBuf);
							PutField_CString(hTxnBAIReq, "new_baid", csBaid);
							PutField_CString(hTxnBAIReq, "add_user", csUser);
							TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBAI","Authorize");
							iRetCode = (unsigned long)(*TxnObjPtr)(hTxnBAIReq,hTxnBAIReq,hTxnBAIReq);
							if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call TxnOmtByUsBAI::Authorize Success!!\n", iCnt));
								iSuccessCnt++;
								TxnCommit();
							}
							else{
DEBUGLOG((" [%d]call TxnOmtByUsBAI::Authorize Failure!!\n", iCnt));
								TxnAbort();
							}
						}
					}
					else{
DEBUGLOG((" [%d]call OLBankAcctId::GetBankAcctIdDtl Not Found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBankAcctId::GetBankAcctIdDtl Not Found!!\n");
						iRetCode = INT_BAID_NOT_FOUND;
					}	
									

				}

				// Update return code to bulk detail
				PutField_CString(hBulkDetail, "batch_id", csBatchId);
				PutField_Int(hBulkDetail, "seq", iSeq);
				PutField_Int(hBulkDetail, "ret_code", iRetCode); 

				DBObjPtr = CreateObj(DBPtr,"DBOLBulkDetail","Update");
                     		if ((unsigned long)(*DBObjPtr)(hBulkDetail) == PD_OK){
DEBUGLOG((" [%d]call OLBulkDetail::Update ret_code[%d] Success!!\n", iCnt, iRetCode));
					TxnCommit();
				}
				else{
DEBUGLOG((" [%d]call OLBulkDetail::Update ret_code[%d] Failure!!\n", iCnt, iRetCode));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkDetail::Update Failure!!\n");
					TxnAbort();
				} 

				FREE_ME(csBuf);

				hash_destroy(hGetAttribute);
				FREE_ME(hGetAttribute);
				hash_destroy(hTxnBAIReq);
				FREE_ME(hTxnBAIReq);
				hash_destroy(hBulkDetail);
				FREE_ME(hBulkDetail);

				iCnt++;
				hRec = RecordSet_GetNext(rRecordSet);
			}

			if(iRet == PD_OK){
DEBUGLOG((" bulk detail, cnt = [%d], success_cnt = [%d]\n", iCnt, iSuccessCnt));
				if(iCnt != iSuccessCnt){
DEBUGLOG((" bulk detail not all record(s) success!!\n"));
					iRet = INT_PARTIAL_RECORD_INVALID;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
		}
	}

	if(iRet != PD_OK){
		TxnAbort();
	}

	// update bulk header status to 'C' and return code
	if(iUpdHdRet == PD_OK){

		PutField_Int(hBulkHeader, "ret_code", iRet);
		PutField_Char(hBulkHeader, "status", PD_BULK_STATUS_COMPLETE);

		DBObjPtr = CreateObj(DBPtr, "DBOLBulkHeader", "Update");
		iUpdHdRet = (unsigned long)(*DBObjPtr)(hBulkHeader);
		if(iUpdHdRet == PD_OK){
DEBUGLOG(("call OLBulkHeader::Update status[%c] ret_code[%d] Success!!\n", PD_BULK_STATUS_COMPLETE, iRet));
		}
		else{
DEBUGLOG(("call OLBulkHeader::Update status[%c] ret_code[%d] Failure!!\n", PD_BULK_STATUS_COMPLETE, iRet));
ERRLOG("TxnOmtByUsBUB:: Authorize:: call OLBulkHeader::Update Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	hash_destroy(hBulkHeader);
	FREE_ME(hBulkHeader);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


DEBUGLOG(("TxnOmtByUsBUB Normal Exit() iRet = [%d]\n", iRet));
        return iRet;
}

