/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 		Change Date             Change By
-------------------------------                    		------------            --------------
Init Version                                       		2019/06/05              CheukFung Lee
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
#include "TxnOmtByUsBUA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsBUA(char cdebug)
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

DEBUGLOG(("TxnOmtByUsBUA:: Authorize\n"));

	// get batch_id
	if(GetField_CString(hRequest, "batch_id", &csBatchId)){
DEBUGLOG(("batch_id = [%s]\n", csBatchId));
		PutField_CString(hBulkHeader, "batch_id", csBatchId);
	}
	else{
DEBUGLOG(("batch_id not found!!\n"));
ERRLOG("TxnOmtByUsBUA:: Authorize:: batch_id not found!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: txn_code not found!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: add_user not found!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkHeader::Get record_cnt not found!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkHeader::Get status not found!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkHeader::Get Error!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkHeader::Update Failure!!\n");
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId Failure!!\n");
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
				int iTmp = 0;

				char* csBuf = (char*)malloc(64); 
				char* csTmp = NULL;
				char* csOrgStatus = NULL;
				char* csNewStatus = NULL;

				char* csBankCode = NULL;
				char* csAcctNum = NULL;

				hash_t* hBulkDetail;
				hBulkDetail = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hBulkDetail,0);

				hash_t* hBankAccts;
				hBankAccts = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hBankAccts,0);

				hash_t* hTxnBKAReq;
				hTxnBKAReq = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hTxnBKAReq,0);

				hash_t* hTxnBKARes;
				hTxnBKARes = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hTxnBKARes,0);

				// Get Seq, bank code, acct num, original status, new status
				if(GetField_Int(hRec, "seq", &iSeq)){
DEBUGLOG((" [%d]seq = [%d]\n", iCnt, iSeq));
				}
				else{
DEBUGLOG((" [%d]seq not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId seq not found!!\n");
					iRetCode = INT_SEQ_NOT_FOUND;
				}

				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "int_bank_code", &csBankCode)){
DEBUGLOG((" [%d]int_bank_code = [%s]\n", iCnt, csBankCode));
					}
					else{
DEBUGLOG((" [%d]int_bank_code not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId int_bank_code not found!!\n");
						iRetCode = INT_BANK_CODE_NOT_FOUND;
					}
				}

				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "bank_acct_num", &csAcctNum)){
DEBUGLOG((" [%d]bank_acct_num = [%s]\n", iCnt, csAcctNum));
					}
					else{
DEBUGLOG((" [%d]bank_acct_num not found!!, iCnt\n"));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId bank_acct_num not found!!\n");
						iRetCode = INT_BANK_ACCT_NOT_FOUND;
					}
				}

				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "bank_acct_org_status", &csOrgStatus)){
DEBUGLOG((" [%d]bank_acct_org_status = [%s]\n", iCnt, csOrgStatus));
					}
					else{
DEBUGLOG((" [%d]bank_acct_org_status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId bank_acct_org_status not found!!\n");
						iRetCode = INT_STATUS_NOT_FOUND;
					}
				}

				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "bank_acct_new_status", &csNewStatus)){
DEBUGLOG((" [%d]bank_acct_new_status = [%s]\n", iCnt, csNewStatus));
					}
					else{
DEBUGLOG((" [%d]bank_acct_new_status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::GetByBatchId bank_acct_new_status not found!!\n");
						iRetCode = INT_STATUS_NOT_FOUND;
					}
				}

				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
					iRetCode = (unsigned long)(*DBObjPtr)(csBankCode, csAcctNum, hBankAccts);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call OLBankAccts::GetBankAccts Found!!\n", iCnt));
						/* Status Type */
						if(GetField_CString(hBankAccts, "status_type", &csTmp)){
DEBUGLOG((" [%d]status_type = [%s]\n", iCnt, csTmp));
							if(strcmp(csTmp, csOrgStatus) || !strcmp(csTmp, PD_BANK_ACCT_STATUS_DISPOSED)){
DEBUGLOG((" [%d]invalid status_type!!\n", iCnt));
								iRetCode = INT_INVALID_BANK_ACCT_STATUS;
							}
							else{
								PutField_CString(hTxnBKAReq, "status_type", csNewStatus);
							}
						}
						else{
DEBUGLOG((" [%d]status_type not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBankAccts::GetBankAccts status_type not found!!\n");
							iRetCode = INT_STATUS_NOT_FOUND;
						}

						/* Bank Acct Name */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "bank_acct_name", &csTmp)){
DEBUGLOG((" [%d]bank_acct_name = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "name", csTmp);
							}
							else{
DEBUGLOG((" [%d]bank_acct_name not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBankAccts::GetBankAccts bank_acct_name not found!!\n");
								iRetCode = INT_BANK_ACCT_NAME_NOT_FOUND;
							}
						}

						/* Bank Acct Short Name */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "bank_acct_short_name", &csTmp)){
DEBUGLOG((" [%d]bank_acct_short_name = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "short_name", csTmp);
							}
							else{
DEBUGLOG((" [%d]bank_acct_short_name not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBankAccts::GetBankAccts bank_acct_short_name not found!!\n");
								iRetCode = INT_BANK_ACCT_SHORT_NAME_NOT_FOUND;
							}
						}

						/* Acct Type */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "acct_type", &csTmp)){
DEBUGLOG((" [%d]acct_type = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "acct_type", csTmp);
							}
							else{
DEBUGLOG((" [%d]acct_type not found!!\n", iCnt));
							}
						}

						/* Support SMS STMT */
						if(iRetCode == PD_OK){
							if(GetField_Int(hBankAccts, "support_sms_stmt", &iTmp)){
DEBUGLOG((" [%d]support_sms_stmt = [%d]\n", iCnt, iTmp));
								sprintf(csBuf, "%d", iTmp);
								PutField_CString(hTxnBKAReq, "sms_stmt", csBuf);
							}
							else{
DEBUGLOG((" [%d]support_sms_stmt not found!!\n", iCnt));
							}
						}

						/* Sys Switch */
						if(iRetCode == PD_OK){
							if(GetField_Int(hBankAccts, "sys_switch_enabled", &iTmp)){
DEBUGLOG((" [%d]sys_switch_enabled = [%d]\n", iCnt, iTmp));
								sprintf(csBuf, "%d", iTmp);
								PutField_CString(hTxnBKAReq, "sys_switch", csBuf);
							}
							else{
DEBUGLOG((" [%d]sys_switch_enabled not found!!\n", iCnt));
							}
						}

						/* Reg Mobile Num */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "reg_mob_num", &csTmp)){
DEBUGLOG((" [%d]reg_mob_num = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "reg_mob_num", csTmp);
							}
							else{
DEBUGLOG((" [%d]reg_mob_num not found!!\n", iCnt));
							}
						}

						/* Remark */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "acct_remark", &csTmp)){
DEBUGLOG((" [%d]remark = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "remark", csTmp);
							}
							else{
DEBUGLOG((" [%d]remark not found!!\n", iCnt));
							}
						}

						/* Swift Code */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "swift_code", &csTmp)){
DEBUGLOG((" [%d]swift_code = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "swift_code", csTmp);
							}
							else{
DEBUGLOG((" [%d]swift_code not found!!\n", iCnt));
							}
						}

						/* Branch Code */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "branch_code", &csTmp)){
DEBUGLOG((" [%d]branch_code = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "branch_code", csTmp);
							}
							else{
DEBUGLOG((" [%d]branch_code not found!!\n", iCnt));
							}
						}

						/* Owner ID */
						if(iRetCode == PD_OK){
							if(GetField_CString(hBankAccts, "owner_id", &csTmp)){
DEBUGLOG((" [%d]owner_id = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBKAReq, "owner_id", csTmp);
							}
							else{
DEBUGLOG((" [%d]owner_id not found!!\n", iCnt));
							}
						}

						if(iRetCode == PD_OK){
							sprintf(csBuf, "%c", PD_ACTION_UPDATE);
							PutField_CString(hTxnBKAReq, "action", csBuf);
							PutField_CString(hTxnBKAReq, "int_bank_code", csBankCode);
							PutField_CString(hTxnBKAReq, "new_acct_num", csAcctNum);
							PutField_CString(hTxnBKAReq, "add_user", csUser);
							PutField_CString(hTxnBKAReq, "update_user", csUser);

							TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBKA","Authorize");
							iRetCode = (unsigned long)(*TxnObjPtr)(hContext,hTxnBKAReq,hTxnBKARes);	
							if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call TxnOmtByUsBKA::Authorize Success!!\n", iCnt));
								iSuccessCnt++;
								TxnCommit();
							}
							else{
DEBUGLOG((" [%d]call TxnOmtByUsBKA::Authorize Failure!!\n", iCnt));
								TxnAbort();
							}
						}
					}
					else{
DEBUGLOG((" [%d]call OLBankAccts::GetBankAccts Not Found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBankAccts::GetBankAccts Not Found!!\n");
						iRetCode = INT_BANK_ACCT_NOT_FOUND;
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkDetail::Update Failure!!\n");
				} 

				FREE_ME(csBuf);

				hash_destroy(hBankAccts);
				FREE_ME(hBankAccts);
				hash_destroy(hTxnBKAReq);
				FREE_ME(hTxnBKAReq);
				hash_destroy(hTxnBKARes);
				FREE_ME(hTxnBKARes);
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
ERRLOG("TxnOmtByUsBUA:: Authorize:: call OLBulkHeader::Update Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	hash_destroy(hBulkHeader);
	FREE_ME(hBulkHeader);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


DEBUGLOG(("TxnOmtByUsBUA Normal Exit() iRet = [%d]\n", iRet));
        return iRet;
}

