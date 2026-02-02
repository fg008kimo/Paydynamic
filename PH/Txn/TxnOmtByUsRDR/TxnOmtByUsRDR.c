/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/08              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRDR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsRDR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet = PD_OK;
	char *csTmp = NULL;

	char	*csBaidTxnId = NULL;
	char	*csPspTxnId = NULL;
	char	*csMerchTxnId = NULL;
	int	iReturnMFee = 0;

	char	*csBaidTxn_AcctNo = NULL;
	char	*csBaidTxn_TxnCode = NULL;
	double	dBaidTxn_TxnAmt = 0.0;

	char	*csPspTxn_AcctNo = NULL;
	double	dPspTxn_TxnAmt = 0.0;

	char	*csMerchTxn_AcctNo;
	double	dMerchTxn_TxnAmt = 0.0;

	char	*csRBDTxnId = NULL;

	char	*csUser = NULL;

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);

	hash_t *hRec;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);


DEBUGLOG(("TxnOmtByUsRDR: Authroize()\n"));

/* get input */
	// get Baid txn id
	if (GetField_CString(hRequest, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("Authorize:: baid_txn_id = [%s]\n", csBaidTxnId));
	} else {
DEBUGLOG(("Authorize:: baid_txn_id missing!\n"));
ERRLOG("TxnOmtByUsRDR:Authorize:: baid_txn_id missing!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get Psp txn id
	if (GetField_CString(hRequest, "psp_txn_id", &csPspTxnId)) {
DEBUGLOG(("Authorize:: psp_txn_id = [%s]\n", csPspTxnId));
	} else {
DEBUGLOG(("Authorize:: psp_txn_id missing!\n"));
ERRLOG("TxnOmtByUsRDR:Authorize:: psp_txn_id missing!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get Merch txn id
	if (GetField_CString(hRequest, "merch_txn_id", &csMerchTxnId)) {
DEBUGLOG(("Authorize:: merch_txn_id = [%s]\n", csMerchTxnId));
	//	PutField_CString(hContext, "txn_seq", csMerchTxnId);
		PutField_CString(hRequest, "org_txn_seq", csMerchTxnId);
	} else {
DEBUGLOG(("Authorize:: merch_txn_id missing!\n"));
ERRLOG("TxnOmtByUsRDR:Authorize:: merch_txn_id missing!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get Return Merch Fee
	if(GetField_CString(hRequest,"return_mfee",&csTmp)){
		iReturnMFee = atoi(csTmp);
		PutField_Int(hRequest,"return_mfee",iReturnMFee);
DEBUGLOG(("Authorize:: retunr_mfee = [%d]\n", iReturnMFee));
	} else {
DEBUGLOG(("Authorize:: return_mfee missing!\n"));
ERRLOG("TxnOmtByUsRDR:Authorize:: return_mfee missing!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get user
	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user/update_user = [%s]\n", csUser));
		PutField_CString(hContext, "add_user", csUser);
	} else {
DEBUGLOG(("Authorize:: add_user missing!\n"));
ERRLOG("TxnOmtByUsRDR:Authorize:: add_user missing!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}


/* get BAID txn detail (UBD) */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBAIDTxn:GetBaidTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId, hTmp);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csBaidTxnId));

			if (GetField_CString(hTmp,"bank_acct_num",&csBaidTxn_AcctNo)) {
DEBUGLOG(("Authorize:: AcctNo = [%s]\n", csBaidTxn_AcctNo));
			}

			if (GetField_CString(hTmp,"txn_code",&csBaidTxn_TxnCode)) {
DEBUGLOG(("Authorize:: txn_code = [%s]\n", csBaidTxn_TxnCode));
				if (strcmp(csBaidTxn_TxnCode,PD_TXN_CODE_UNKNOWN_DEBIT) != 0 &&
				    strcmp(csBaidTxn_TxnCode,PD_TXN_CODE_UNKNOWN_SWEEP_OUT) != 0 ) {
DEBUGLOG(("Authorize:: txn_code not allow! return ERROR\n"));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLBAIDTxn:GetBaidTxn() txn_code not allow!");
					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}

			if (GetField_Double(hTmp,"txn_amt",&dBaidTxn_TxnAmt)) {
DEBUGLOG(("Authorize:: txn_amt = [%f]\n", dBaidTxn_TxnAmt));
			}

		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csBaidTxnId));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLBAIDTxn:GetBaidTxn() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}


/* get PSP txn detail (OBD) */
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csPspTxnId, rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csPspTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hRec,"sub_status",&csTmp)){
DEBUGLOG(("Authorize:: sub_status = [%s]\n", csTmp));
				if (!strcmp(csTmp,PD_VOID)) {
DEBUGLOG(("Authorize:: sub_status can not be voided!!\n"));
ERRLOG("TxnOmtByUsRDR: Authorize:: sub_status can not be voided!!\n");
				}
			}

		} else{
DEBUGLOG(("Authorize:: record not found for [%s]\n", csPspTxnId));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLTransaction:GetTxnHeader() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	if (iRet == PD_OK) {
		hash_init(hTmp,0);
		recordset_init(rRecordSet,0);
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail:GetTxnPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(csPspTxnId, hTmp);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csPspTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hTmp,"bank_acct_num",&csPspTxn_AcctNo)) {
DEBUGLOG(("Authorize:: AcctNo = [%s]\n", csPspTxn_AcctNo));
			}

			if (GetField_Double(hTmp,"txn_amount",&dPspTxn_TxnAmt)) {
DEBUGLOG(("Authorize:: txn_amt = [%f]\n", dPspTxn_TxnAmt));
			}

		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csPspTxnId));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLTxnPspDetail:GetTxnPspDetail() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}


/* get Merch txn detail (ODI) */
	if (iRet == PD_OK) {
		hash_init(hTmp,0);
		recordset_init(rRecordSet,0);
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","GetTxnDetail");
		if ((*DBObjPtr)(csMerchTxnId, rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csMerchTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hRec,"bank_acct_num",&csMerchTxn_AcctNo)){
DEBUGLOG(("Authorize:: AcctNo = [%s]\n", csMerchTxn_AcctNo));
			}

		} else{
DEBUGLOG(("Authorize:: record not found for [%s]\n", csMerchTxnId));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLTransaction:GetTxnDetail() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csMerchTxnId, rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csMerchTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_Double(hRec,"txn_amt",&dMerchTxn_TxnAmt)){
DEBUGLOG(("Authorize:: txn_amt = [%f]\n", dMerchTxn_TxnAmt));
			}

		} else{
DEBUGLOG(("Authorize:: record not found for [%s]\n", csMerchTxnId));
ERRLOG("TxnOmtByUsRDR: Authorize:: DBOLTransaction:GetTxnHeader() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}


/* check if bank_acct / txn_amt are all same */
	if (iRet == PD_OK) {
		if (strcmp(csBaidTxn_AcctNo,csPspTxn_AcctNo) != 0 ||
		    strcmp(csBaidTxn_AcctNo,csMerchTxn_AcctNo) != 0 ||
		    dBaidTxn_TxnAmt != dPspTxn_TxnAmt ||
		    dBaidTxn_TxnAmt != dMerchTxn_TxnAmt) {
DEBUGLOG(("Authorize:: BankAcct / TxnAmt not the same within BAIDTxn,PSPTxn,MerchTxn!\n"));
ERRLOG("TxnOmtByUsRDR: Authorize:: BankAcct / TxnAmt not the same within BAIDTxn,PSPTxn,MerchTxn!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}



/* Return Deposit Transaction */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call TxnOmtByUsVOT:Authorize\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsVOT", "Authorize");
		iTmpRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: TxnOmtByUsVOT return fail\n"));
ERRLOG("TxnOmtByUsRDR: Authorize:: TxnOmtByUsVOT return fail\n");
			iRet = iTmpRet;
		}
	}


/* Recon with RBD */
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"rbd_txn_seq",&csRBDTxnId)) {
DEBUGLOG(("Authorize:: RBD Txn Id = [%s]\n",csRBDTxnId));
		}
	
		hash_init(hTmp, 0);
		int	iTxnCount = 1;
		char	csBuf[PD_TAG_LEN];
		sprintf(csBuf,"%d",PD_FALSE);

		PutField_CString(hTmp, "activity", PD_TXN_ENGING_ACTIVITIY_RECON);
		PutField_CString(hTmp, "bank_stmt_type", PD_RETURN_MATCHED_DEPOSIT);
		PutField_CString(hTmp, "recon_type", PD_ENGINE_RECON_SAME);
		PutField_CString(hTmp, "trigger_type", PD_TRIGGER_MANUAL);
		PutField_CString(hTmp, "input_channel", PD_CHANNEL_OMT);
		PutField_CString(hTmp, "use_pf", csBuf);
		PutField_CString(hTmp, "have_charge", csBuf);
		PutField_CString(hTmp, "have_interest",csBuf);
		PutField_CString(hTmp, "add_user", csUser);
		sprintf(csBuf,"%d",iTxnCount);
		PutField_CString(hTmp, "txn_cnt", csBuf);
		PutField_CString(hTmp, "txnid_1", csRBDTxnId);
		PutField_CString(hTmp, "stmt_cnt", csBuf);
		PutField_CString(hTmp, "stmt_txnid_1", csBaidTxnId);
DEBUGLOG(("Authorize:: call TxnOmtByUsREC::Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsREC", "Authorize");
		iTmpRet = (unsigned long)(*TxnObjPtr)(hContext, hTmp, hResponse);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: recon return success\n"));
		} else {
DEBUGLOG(("Authorize:: recon return failed\n"));
			iRet = iTmpRet;
		}
	}


	hash_destroy(hTmp);
	FREE_ME(hTmp);


DEBUGLOG(("TxnOmtByUsRDR Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
