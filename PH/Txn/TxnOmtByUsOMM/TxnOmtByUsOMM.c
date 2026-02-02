/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/11/06              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOMM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOmtByUsOMM(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		const hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;
	char	*csTmp = NULL;

	char	*csStmtTxnId, *csTxnId, *csAddUser;
	char	cMatchingType;
	int	iOverrideAmt;

	char	*csMerchRef = NULL;
	char	*csChannelCode = NULL;
	char	*csTxnCode = NULL;
	char	*csSubStatus = NULL;
	char	*csTxnCcy = NULL;
	char	*csBankCode = NULL;
	char	*csBankAcctNum = NULL;
	char	cStatus;
	char	cArInd;
	double	dDepositAmt = 0.0;
	int	iTxnHoldInd = 0;

	recordset_t *rStmtTxnHdr;
	rStmtTxnHdr = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rStmtTxnHdr, 0);
	hash_t *hStmtTxnHdr;

	hash_t *hStmtTxnPspDtl;
	hStmtTxnPspDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hStmtTxnPspDtl, 0);

	recordset_t *rMerchTxnHdr;
	rMerchTxnHdr = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rMerchTxnHdr, 0);
	hash_t *hMerchTxnHdr;

DEBUGLOG(("TxnOmtByUsOMM:: Authorize\n"));

/* stmt_txnid */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "stmt_txnid", &csStmtTxnId)) {
DEBUGLOG(("Authorize:: stmt_txnid = [%s]\n", csStmtTxnId));
		} else {
DEBUGLOG(("Authorize:: stmt_txnid not found!!\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: stmt_txnid not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* get stmt txn info (for fallback grep log) */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		iTmpRet = (unsigned long)(*DBObjPtr)(csStmtTxnId, rStmtTxnHdr);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnHeader() failed\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: call DBOLTransaction::GetTxnHeader() failed\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hStmtTxnHdr = RecordSet_GetFirst(rStmtTxnHdr);

			// channel_code
			if (!GetField_CString(hStmtTxnHdr, "channel_code", &csChannelCode)) {
DEBUGLOG(("Authorize:: channel_code not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: channel_code not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// status
			if (!GetField_Char(hStmtTxnHdr, "status", &cStatus)) {
DEBUGLOG(("Authorize:: status not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: status not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// ar_ind
			if (!GetField_Char(hStmtTxnHdr, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: ar_ind not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: ar_ind not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// txn_code
			if (!GetField_CString(hStmtTxnHdr, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: txn_code not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: txn_code not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// sub_status
			if (!GetField_CString(hStmtTxnHdr, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: sub_status not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: sub_status not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// deposit_amt
			if (!GetField_Double(hStmtTxnHdr, "deposit_amt", &dDepositAmt)) {
DEBUGLOG(("Authorize:: deposit_amt not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: deposit_amt not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTxnPspDetail::GetTxnPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(csStmtTxnId, hStmtTxnPspDtl);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTxnPspDetail::GetTxnPspDetail() failed\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: call DBOLTxnPspDetail::GetTxnPspDetail() failed\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			// txn_hold_ind
			if (!GetField_Int(hStmtTxnPspDtl, "txn_hold_ind", &iTxnHoldInd)) {
DEBUGLOG(("Authorize:: txn_hold_ind not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: txn_hold_ind not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// txn_ccy
			if (!GetField_CString(hStmtTxnPspDtl, "txn_ccy", &csTxnCcy)) {
DEBUGLOG(("Authorize:: txn_ccy not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: txn_ccy not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// bank_code
			if (!GetField_CString(hStmtTxnPspDtl, "bank_code", &csBankCode)) {
DEBUGLOG(("Authorize:: bank_code not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: bank_code not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// bank_acct_num
			if (!GetField_CString(hStmtTxnPspDtl, "bank_acct_num", &csBankAcctNum)) {
DEBUGLOG(("Authorize:: bank_acct_num not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: bank_acct_num not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

/* txn_id */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "org_txn_seq", &csTxnId)) {
DEBUGLOG(("Authorize:: txn_id = [%s]\n", csTxnId));
		} else {
DEBUGLOG(("Authorize:: txn_id not found!!\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: txn_id not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* get merch txn info (for fallback grep log) */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		iTmpRet = (unsigned long)(*DBObjPtr)(csTxnId, rMerchTxnHdr);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLTransaction::GetTxnHeader() failed\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: call DBOLTransaction::GetTxnHeader() failed\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hMerchTxnHdr = RecordSet_GetFirst(rMerchTxnHdr);

			// merchant_ref
			if (!GetField_CString(hMerchTxnHdr, "merchant_ref", &csMerchRef)) {
DEBUGLOG(("Authorize:: merchant_ref not found\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: merchant_ref not found\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

/* override_amt */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "override_amt", &csTmp)) {
			iOverrideAmt = atoi(csTmp);
DEBUGLOG(("Authorize:: override_amt = [%d]\n", iOverrideAmt));
		} else {
DEBUGLOG(("Authorize:: override_amt not found!!\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: override_amt not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* matching_type */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "matching_type", &csTmp)) {
			cMatchingType = csTmp[0];
DEBUGLOG(("Authorize:: matching_type = [%c]\n", cMatchingType));
		} else {
DEBUGLOG(("Authorize:: matching_type not found!!\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: matching_type not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csAddUser)) {
DEBUGLOG(("Authorize:: user = [%s]\n", csAddUser));
		} else {
DEBUGLOG(("Authorize:: add_user not found!!\n"));
ERRLOG("TxnOmtByUsOMM:: Authorize:: add_user not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* for fallback grep log */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() for fallback grep log %c,%d,%s,%s,%s,%s,%s,%s,%s,%c,%c,%.2lf,%d\n",
		cMatchingType, iOverrideAmt, csMerchRef, csChannelCode, csTxnCode, csSubStatus, csTxnCcy, csBankCode, csBankAcctNum, cStatus, cArInd, dDepositAmt, iTxnHoldInd));
	}

/* complete matching */
	BOObjPtr = CreateObj(BOPtr, "BOOLDepositMatch", "CompleteMatching");
	iRet = (unsigned long)(*BOObjPtr)(csStmtTxnId, csTxnId, iOverrideAmt, cMatchingType, csAddUser);
	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	}

	RecordSet_Destroy(rStmtTxnHdr);
	FREE_ME(rStmtTxnHdr);

	hash_destroy(hStmtTxnPspDtl);
	FREE_ME(hStmtTxnPspDtl);

	RecordSet_Destroy(rMerchTxnHdr);
	FREE_ME(rMerchTxnHdr);

DEBUGLOG(("TxnOmtByUsOMM Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

