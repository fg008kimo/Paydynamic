/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 		Change Date             Change By
-------------------------------                    		------------            --------------
Init Version                                       		2019/07/24              Michael Chow
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
#include "TxnOmtByUsBUC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);


void TxnOmtByUsBUC(char cdebug)
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
	char csTxnSeq[PD_TXN_SEQ_LEN + 1];

	char* csBatchId = NULL;
	char* csTxnCode = NULL;
	char* csUser = NULL;

	char* csLocalTmDate = NULL;
	char* csLocalTmTime = NULL;
	char* csPhdate = NULL;

	hash_t* hBulkHeader;
	hBulkHeader = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBulkHeader,0);

	hash_t* hRec = NULL;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("TxnOmtByUsBUC:: Authorize\n"));

	// get batch_id
	if(GetField_CString(hRequest, "batch_id", &csBatchId)){
DEBUGLOG(("batch_id = [%s]\n", csBatchId));
		PutField_CString(hBulkHeader, "batch_id", csBatchId);
	}
	else{
DEBUGLOG(("batch_id not found!!\n"));
ERRLOG("TxnOmtByUsBUC:: Authorize:: batch_id not found!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: txn_code not found!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: add_user not found!!\n");
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// local_tm_date
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"local_tm_date",&csLocalTmDate)) {
DEBUGLOG((" [%d]local_tm_date = [%s]\n", iCnt, csLocalTmDate));
		}
		else{
DEBUGLOG(("local_tm_date not found!!\n"));
		}
	}

	// local_tm_time
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"local_tm_time",&csLocalTmTime)) {
DEBUGLOG((" [%d]local_tm_time = [%s]\n", iCnt, csLocalTmTime));
		}
		else{
DEBUGLOG(("local_tm_time not found!!\n"));
		}
	}

	// host_posting_date
	if(iRet == PD_OK){
		if (GetField_CString(hContext,"PHDATE",&csPhdate)) {
DEBUGLOG((" [%d]PHDATE = [%s]\n", iCnt, csPhdate));
		}
		else{
DEBUGLOG(("PHDATE not found!!\n"));
ERRLOG("TxnOmtByUsBUC:: Authorize:: PHDATE not found!!\n");
			iRet = INT_PHDATE_NOT_FOUND;
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkHeader::Get record_cnt not found!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkHeader::Get status not found!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkHeader::Get Error!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkHeader::Update Failure!!\n");
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}

		// loop bulk detail records
		if(iRet == PD_OK){
			iCnt = 0;

			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){

				int iRetCode = PD_OK;
				int iTmpRet = PD_OK;
	
				int iSeq = 0;

				double dTmp = 0.0;

				char* csBuf = (char*)malloc(64); 
				char* csTmp = NULL;

				char* csBaid = NULL;
				char* csCountry = NULL;
				char* csCurrency = NULL;

				hash_t* hBulkDetail;
				hBulkDetail = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hBulkDetail,0);

				hash_t* hGetAttribute;
				hGetAttribute = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hGetAttribute,0);

				hash_t* hTxnBADReq;
				hTxnBADReq = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hTxnBADReq,0);
				
/* Get Seq, baid, country, currency, adj_txn_code, adj_rpt_date, adj_remark */

				if(GetField_Int(hRec, "seq", &iSeq)){
DEBUGLOG((" [%d]seq = [%d]\n", iCnt, iSeq));
				}
				else{
DEBUGLOG((" [%d]seq not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId seq not found!!\n");
					iRetCode = INT_SEQ_NOT_FOUND;
				}

/*baid*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "baid", &csBaid)){
DEBUGLOG((" [%d]baid = [%s]\n", iCnt, csBaid));
					}
					else{
DEBUGLOG((" [%d]baid not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId baid not found!!\n");
						iRetCode = INT_BAID_NOT_FOUND;
					}
				}
/*country*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "country", &csCountry)){
DEBUGLOG((" [%d]country = [%s]\n", iCnt, csCountry));
					}
					else{
DEBUGLOG((" [%d]country not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId country not found!!\n");
						iRetCode = INT_TXN_COUNTRY_NOT_FOUND;
					}
				}
/*currency*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "currency", &csCurrency)){
DEBUGLOG((" [%d]currency = [%s]\n", iCnt, csCurrency));
					}
					else{
DEBUGLOG((" [%d]currency not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId currency not found!!\n");
						iRetCode = INT_CURRENCY_CODE_NOT_FOUND;
					}
				}
/*adj_txn_code*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "adj_txn_code", &csTmp)){
DEBUGLOG((" [%d]adj_txn_code = [%s]\n", iCnt, csTmp));
						PutField_CString(hTxnBADReq, "code", csTmp);
					}
					else{
DEBUGLOG((" [%d]adj_txn_code not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::GetByBatchId adj_txn_code not found!!\n");
						iRetCode = INT_ADJ_TXN_CODE_NOT_FOUND;
					}
				}

/*adj_rpt_date*/
				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "adj_rpt_date", &csTmp)){
DEBUGLOG((" [%d]adj_rpt_date = [%s]\n", iCnt, csTmp));
						PutField_CString(hTxnBADReq, "report_date", csTmp);
					}
					else{
DEBUGLOG((" [%d]adj_rpt_date not found!!\n", iCnt));
					}
				}
/*adj_remark*/

				if(iRetCode == PD_OK){
					if(GetField_CString(hRec, "adj_remark", &csTmp)){
DEBUGLOG((" [%d]adj_remark = [%s]\n", iCnt, csTmp));
						PutField_CString(hTxnBADReq, "remark", csTmp);
					}
					else{
DEBUGLOG((" [%d]adj_remark not found!!\n", iCnt));
					}
				}

//Get psp_id, bank_acct_num, int_bank_code
				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetBankAcctIdDtl");
					iRetCode = (unsigned long)(*DBObjPtr)(csBaid, hGetAttribute);
					if(iRetCode == PD_OK){

/*psp_id*/
						if(GetField_CString(hGetAttribute, "psp_id", &csTmp)){
DEBUGLOG((" [%d]psp_id = [%s]\n", iCnt, csTmp));
							PutField_CString(hTxnBADReq, "baid_psp_id", csTmp);
						}
						else{
DEBUGLOG((" [%d]psp_id not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBankAcctId::GetBankAcctIdDtl psp_id not found!!\n");
							iRetCode = INT_PSP_ID_NOT_FOUND;
						}	

/*bank_acct_num*/
						if(iRetCode == PD_OK){
							if(GetField_CString(hGetAttribute, "bank_acct_num", &csTmp)){
DEBUGLOG((" [%d]bank_acct_num = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBADReq, "baid_bank_acct_num", csTmp);
							}
							else{
DEBUGLOG((" [%d]bank_acct_num not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBankAcctId::GetBankAcctIdDtl bank_acct_num not found!!\n");
								iRetCode = INT_BANK_ACCT_ID_NOT_FOUND;
							}
						}

/*int_bank_code*/
						if(iRetCode == PD_OK){
							if(GetField_CString(hGetAttribute, "int_bank_code", &csTmp)){
DEBUGLOG((" [%d]int_bank_code = [%s]\n", iCnt, csTmp));
								PutField_CString(hTxnBADReq, "baid_bank_code", csTmp);
							}
							else{
DEBUGLOG((" [%d]int_bank_code not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBankAcctId::GetBankAcctIdDtl int_bank_code not found!!\n");
								iRetCode = INT_BANK_CODE_NOT_FOUND;
							}
						}
					}
					else{
DEBUGLOG((" [%d]call DBDBOLBankAcctId::GetBankAcctIdDtl Not Found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call DBDBOLBankAcctId::GetBankAcctIdDtl Not Found!!\n");
                                                iRetCode = INT_BAID_NOT_FOUND;
					}
				}
/*Get balance*/
				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr,"DBOLBAIDBal","GetBalanceForUpdate");
					iRetCode = (unsigned long)(*DBObjPtr)(csBaid, csCountry, csCurrency, hGetAttribute);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call DBOLBAIDBal::GetBalance Found!!\n", iCnt));

/* balance */
						if(GetField_Double(hGetAttribute, "balance", &dTmp)){
DEBUGLOG((" [%d]balance = [%.2f]\n", iCnt, dTmp));
							if(dTmp > 0.0){
								PutField_Double(hTxnBADReq, "txn_amt", dTmp);
							}
							else{
DEBUGLOG((" [%d]Invalid BAID Balance!!\n", iCnt));
								iRetCode = INT_INVALID_BAID_BALANCE;
							}
						}
						else{
DEBUGLOG((" [%d]balance not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call DBOLBAIDBal::GetBalance balance not found!!\n");
							iRetCode = INT_BAID_BALANCE_NOT_FOUND;
						}
/* in_transit */
						if(iRetCode == PD_OK){
							if(GetField_Double(hGetAttribute, "in_transit", &dTmp)){
DEBUGLOG((" [%d]in_transit = [%.2f]\n", iCnt, dTmp));
								if(dTmp != 0.0){
DEBUGLOG((" [%d]Invalid In Transit!!\n", iCnt));
									iRetCode = INT_INVALID_IN_TRANSIT;
								}
							}
							else{
DEBUGLOG((" [%d]in_transit not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call DBOLBAIDBal::GetBalance in_transit not found!!\n");
								iRetCode = INT_IN_TRANSIT_NOT_FOUND;
							}	
						}
/* total_hold */
						if(iRetCode == PD_OK){
							if(GetField_Double(hGetAttribute, "total_hold", &dTmp)){
DEBUGLOG((" [%d]total_hold = [%.2f]\n", iCnt, dTmp));
								if(dTmp != 0.0){
DEBUGLOG((" [%d]Invalid Total Hold!!\n", iCnt));
									iRetCode = INT_INVALID_TOTAL_HOLD;
								}
							}
							else{
DEBUGLOG((" [%d]total_hold not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call DBOLBAIDBal::GetBalance total_hold not found!!\n");
								iRetCode = INT_TOTAL_HOLD_NOT_FOUND;
							}
						}
					}
					else{
DEBUGLOG((" [%d]call DBOLBAIDBal::GetBalance Not Found!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call DBOLBAIDBal::GetBalance Not Found!!\n");
						iRetCode = INT_BAID_BALANCE_NOT_FOUND;
					}
				}
				
//Generate Next Txn Seq
				if(iRetCode == PD_OK){
					DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
                                        strcpy((char*)csTxnSeq, (*DBObjPtr)());
DEBUGLOG((" [%d]call DBOLTxnSeq:: GetNextOmtTxnSeq, txn_seq = [%s]\n", iCnt, csTxnSeq));

                                        PutField_CString(hTxnBADReq, "txn_seq", (const char *)csTxnSeq);
                                        PutField_Int(hTxnBADReq, "db_commit", PD_FALSE);
				}

//Update Context
				if(iRetCode == PD_OK){

					PutField_CString(hTxnBADReq, "add_user", csUser);
					PutField_CString(hTxnBADReq, "update_user",csUser);

					PutField_CString(hTxnBADReq,"channel_code",PD_CHANNEL_OMT);
					PutField_CString(hTxnBADReq,"txn_code","BAD");
                                        PutField_CString(hTxnBADReq,"process_code",PD_PROCESS_CODE_DEF);
                                        PutField_CString(hTxnBADReq,"process_type",PD_PROCESS_TYPE_DEF);
			
					ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateContext");
                                        iRetCode = (unsigned long)(*ChannelObjPtr)(hTxnBADReq);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call OMTChannel::UpdateContext Success!!\n", iCnt));
					}
                                        else{
DEBUGLOG((" [%d]call OMTChannel::UpdateContext Failure!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OMTChannel::UpdateContext Failure!!\n");
                                        }
				}

//Add Txn Log
				if(iRetCode == PD_OK){
					PutField_CString(hTxnBADReq, "txn_country", csCountry);
					PutField_CString(hTxnBADReq, "txn_ccy", csCurrency);
					PutField_CString(hTxnBADReq,"local_tm_date",csLocalTmDate);
					PutField_CString(hTxnBADReq,"local_tm_time",csLocalTmTime);
					PutField_CString(hTxnBADReq,"PHDATE",csPhdate);

					ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
					iRetCode = (unsigned long)(*ChannelObjPtr)(hTxnBADReq, hTxnBADReq);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call OMTChannel::AddTxnLog Success!!\n", iCnt));
                                	}
					else{
DEBUGLOG((" [%d]call OMTChannel::AddTxnLog Failure!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OMTChannel::AddTxnLog Failure!!\n");
                                	}
				}

//Call TxnOmtByUsBAD
				if(iRetCode == PD_OK){
					PutField_CString(hTxnBADReq, "baid", csBaid);

					TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUsBAD","Authorize");
					iRetCode = (unsigned long)(*TxnObjPtr)(hTxnBADReq,hTxnBADReq,hTxnBADReq);
					if(iRetCode == PD_OK){
DEBUGLOG((" [%d]call TxnOmtByUsBAD::Authorize Success!!\n", iCnt));
                                	}
					else{
DEBUGLOG((" [%d]call TxnOmtByUsBAD::Authorize Failure!!\n", iCnt));
ERRLOG("TxnOmtByUsBUC:: Authorize:: call TxnOmtByUsBAD::Authorize Failure!!\n");
                                	}
				}


/* response_code, internal_code, status, sub_status, ar_ind */
				sprintf(csBuf, "%d", iRetCode);
				PutField_CString(hTxnBADReq, "response_code", csBuf);
				PutField_Int(hTxnBADReq, "internal_code", iRetCode);
				PutField_Char(hTxnBADReq, "status", PD_COMPLETE);
				PutField_CString(hTxnBADReq, "sub_status", PD_APPROVED);
				if (iRetCode != 0 ) {
					PutField_Char(hTxnBADReq, "ar_ind", PD_REJECT);
				} else {
					PutField_Char(hTxnBADReq, "ar_ind", PD_ACCEPT);
				}

/* Avoid service_code print to ol_txn_header*/
				RemoveField_CString(hTxnBADReq, "service_code");
				RemoveField_CString(hTxnBADReq, "org_txn_seq");

//Update Txn Log
				if(iRetCode == PD_OK){
					ChannelObjPtr = CreateObj(ChannelPtr, "OMTChannel", "UpdateTxnLog");
					iTmpRet = (unsigned long)(*ChannelObjPtr)(hTxnBADReq, hTxnBADReq, hTxnBADReq);
					if(iTmpRet == PD_OK) {
DEBUGLOG((" [%d]call OMTChannel::UpdateTxnLog Success!!\n", iCnt));
						iSuccessCnt++;
					}
					else{
DEBUGLOG((" [%d]call OMTChannel::UpdateTxnLog Failure!! iRetCode = [%d]\n", iCnt, iRetCode));
						iRetCode = iTmpRet;
					}
				}

				if(iRetCode == PD_OK){
					TxnCommit();
				}
				else{
					TxnAbort();
				}

//Update return code to bulk detail
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkDetail::Update Failure!!\n");
					TxnAbort();
				} 

				FREE_ME(csBuf);

				hash_destroy(hGetAttribute);
				FREE_ME(hGetAttribute);
				hash_destroy(hBulkDetail);
				FREE_ME(hBulkDetail);
				hash_destroy(hTxnBADReq);
				FREE_ME(hTxnBADReq);
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
ERRLOG("TxnOmtByUsBUC:: Authorize:: call OLBulkHeader::Update Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	hash_destroy(hBulkHeader);
	FREE_ME(hBulkHeader);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


DEBUGLOG(("TxnOmtByUsBUC Normal Exit() iRet = [%d]\n", iRet));
        return iRet;
}

