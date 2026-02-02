/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/30              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRDM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

int GetTxnInfo(const unsigned char *csTxnSeq,
		hash_t * hContext,
		hash_t * hRequest);

void TxnMgtByUsRDM(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csTxnSeq;
	char *csTxnSeqOpt;
	char *csTmp;
	char *csTxnCode;
	char *csHandler;
	int iReturnMerchFee = PD_FALSE;
	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("Authorize\n"));

	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
		PutField_CString(hContext, "from_txn_seq", csTmp);
DEBUGLOG(("Authorize:: txn_seq = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "org_txn_seq", &csTxnSeq)) {
		PutField_CString(hContext, "org_txn_seq", csTxnSeq);
DEBUGLOG(("Authorize:: org_txn_seq = [%s]\n", csTxnSeq));
	} else {
DEBUGLOG(("Authorize:: txnid not found!!\n"));
ERRLOG("TxnMgtByUsRDM: Authorize:: txnid not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (GetField_CString(hRequest, "org_txn_seq_to", &csTxnSeqOpt)) {
		PutField_CString(hContext, "to_txn_seq", csTxnSeqOpt);
DEBUGLOG(("Authorize:: org_txn_seq (optional) = [%s]\n", csTxnSeqOpt));
	}

	if (GetField_CString(hRequest, "add_user", &csTmp)) {
		PutField_CString(hContext, "update_user", csTmp);
DEBUGLOG(("Authorize:: update_user = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "remark", &csTmp)) {
DEBUGLOG(("Authorize:: remark = [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "return_mfee", &csTmp)) {
		iReturnMerchFee = atoi(csTmp);
		PutField_Int(hRequest, "return_mfee", iReturnMerchFee);
DEBUGLOG(("Authorize:: return_merchantfee = [%d]\n", iReturnMerchFee));
	} else {
		PutField_Int(hRequest, "return_mfee", PD_FALSE);
DEBUGLOG(("Authorize:: return_merchantfee (default) = [%d]\n", PD_FALSE));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call MatchTxnStatusforUpdate\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchTxnStatusforUpdate");
		if ((unsigned long)(DBObjPtr)(csTxnSeq,PD_COMPLETE) != PD_FOUND) {
			iRet = INT_INVALID_TXN;
		}
	}

	if (iRet == PD_OK) {

		iRet = GetTxnInfo((const unsigned char*)csTxnSeq, hContext, hRequest);
DEBUGLOG(("Authorize:: GetTxnInfo iRet = [%d]\n",iRet));

		if (iRet == PD_OK) {
			GetField_CString(hRequest, "org_txn_code", &csTxnCode);
			PutField_CString(hContext, "sub_txn_code", PD_DEPOSIT_REFUND_M);

DEBUGLOG(("Authorize:: Call BOTxnElements: VoidOrgTxnElements\n"));
			BOObjPtr = CreateObj(BOPtr, "BOTxnElements", "VoidOrgTxnElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
DEBUGLOG(("Authorize:: BOTxnElements: VoidOrgTxnElements iRet = [%d]\n", iRet));

			RemoveField_CString(hContext, "sub_txn_code");

			if (iRet == PD_OK) {
				csHandler = (char*) malloc (20);

				PutField_CString(hContext, "new_txn_code", "RDS");
				sprintf(csHandler, "TxnMgtByUs%s", "RDS");

DEBUGLOG(("Authorize:: Call %s: Authorize\n", csHandler));
				TxnObjPtr = CreateObj(TxnPtr, csHandler, "Authorize");
				iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
DEBUGLOG(("Authorize:: %s: Authorize iRet = [%d]\n", csHandler, iRet));

				FREE_ME(csHandler);
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "sub_status", PD_APPROVED);
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnMgtByUsRDM Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

int GetTxnInfo(const unsigned char *csTxnSeq,
		hash_t * hContext,
		hash_t * hRequest)
{
	int iRet = PD_OK;
	char *csTxnCode;
	char *csProcessCode;
	char *csProcessType;
	char *csSubStatus;
	char *csTmp;
	char cTmp;
	int iReleased = PD_FALSE;
	hash_t *hRec;
	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("Authorize:: Call DBTransaction: GetTxnHeader\n"));
	DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
	if ((*DBObjPtr)(csTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader:: found record for [%s]\n", csTxnSeq));
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec, "host_posting_date", &csTmp)) {
				PutField_CString(hContext, "org_posting_date", csTmp);
DEBUGLOG(("GetTxnHeader:: host_posting_date = [%s]\n", csTmp));
			}

			if (GetField_CString(hRec, "txn_code", &csTxnCode)) {
				PutField_CString(hRequest, "org_txn_code", csTxnCode);
DEBUGLOG(("GetTxnHeader:: txn_code = [%s]\n", csTxnCode));
			}

			if (GetField_CString(hRec, "process_code", &csProcessCode)) {
DEBUGLOG(("GetTxnHeader:: process_code = [%s]\n", csProcessCode));
			}

			if (GetField_CString(hRec, "process_type", &csProcessType)) {
DEBUGLOG(("GetTxnHeader:: process_type = [%s]\n", csProcessType));
			}

			if (GetField_CString(hRec, "merchant_id", &csTmp)) {
				PutField_CString(hRequest, "merchant_id", csTmp);
DEBUGLOG(("GetTxnHeader:: merchant_id = [%s]\n", csTmp));
			}

			if (GetField_CString(hRec, "service_code", &csTmp)) {
				PutField_CString(hRequest, "service_code", csTmp);
				PutField_CString(hContext, "service_code", csTmp);
DEBUGLOG(("GetTxnHeader:: service_code = [%s]\n", csTmp));
			}

			if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetTxnHeader:: status = [%c]\n", cTmp));
				if (cTmp != PD_COMPLETE) {
					iRet = INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader:: Invalid status [%c]\n", cTmp));
ERRLOG("TxnMgtByUsRDM: GetTxnHeader:: Invalid status!!\n");
				} else{
					if (GetField_Char(hRec, "ar_ind", &cTmp)) {
DEBUGLOG(("GetTxnHeader:: ar_ind = [%c]\n", cTmp));
						if (cTmp != PD_ACCEPT) {
							iRet = INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader:: Invalid ar_ind [%c]\n", cTmp));
ERRLOG("TxnMgtByUsRDM: GetTxnHeader:: Invalid ar_ind!!\n");
						}
					}
				}
			}

			if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
				PutField_CString(hContext, "org_sub_status", csSubStatus);
DEBUGLOG(("GetTxnHeader:: sub_status = [%s]\n", csSubStatus));

				if (!strcmp(csSubStatus, PD_PSP_CONFIRMED)) {
					iRet = INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader:: GetTxnHeader:: Invalid Sub_status !!\n"));
ERRLOG("TxnMgtByUsRDM: GetTxnHeader:: Invalid sub_status!!\n");
				}
			

			}
			if (!strcmp(csSubStatus, PD_RESERVE_RELEASED)) {
				if (GetField_CString(hRec, "reserved_release_date", &csTmp)) {
					iReleased = PD_TRUE;
DEBUGLOG(("GetTxnHeader:: reserved_release_date = [%s]\n", csTmp));
				}
			}
			PutField_Int(hContext, "reserve_released", iReleased);

			hRec = RecordSet_GetNext(rRecordSet);
		}
	} else {
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n", csTxnSeq));
		iRet = INT_NOT_RECORD;
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTxnCode: IsVoidable\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnCode", "IsVoidable");
		if ((unsigned long)(*DBObjPtr)(csTxnCode, csProcessType, csProcessCode) != PD_TRUE) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("IsVoidable:: un-voidable for [%s][%s][%s]\n", csTxnCode, csProcessCode, csProcessType));
ERRLOG("TxnMgtByUsRDM: Authorize:: un-voidable txn!!\n");
		}
	}

	if (iRet == PD_OK) {
		// get merchant_client_id
		if (GetField_CString(hRequest, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize:: Call BOMerchant: GetMerchantDetail\n"));
			BOObjPtr = CreateObj(BOPtr, "BOMerchant", "GetMerchantDetail");
			iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	return iRet;
}
