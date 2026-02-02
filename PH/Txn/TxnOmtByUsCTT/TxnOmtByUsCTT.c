/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/03              David Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsCTT.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsCTT(char cdebug)
{
	cDebug = cdebug;
}

/* remarks:
	1. assume to_txntype is valid
	2. assume pid_txn_hold_ind & pid_sys_match_ind keep unchanged
*/
int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	char *csTmp=NULL;
	char *csOrgTxnSeq=NULL, csToTxnSeq[PD_TXN_SEQ_LEN + 1];
	char *csToTxnCode=NULL;
	char *csRemark=NULL, *csUser=NULL;
	char *csStatTxnId=NULL;
	char *csPID=NULL;
	char *csBankAcctType=NULL;
	int iRealTimePost;
	char csTxnDateTime[PD_DATETIME_LEN + 1];
	int iTmp;
	double dTmp;

	hash_t *hOrgBaidTxn;
	hOrgBaidTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgBaidTxn, 0);

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

// txnid
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "org_txn_seq", &csOrgTxnSeq)) {
			PutField_CString(hContext, "baid_txn_seq", csOrgTxnSeq);
DEBUGLOG(("Authorize() txnid = [%s]\n", csOrgTxnSeq));
		} else {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() txnid is missing\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() txnid is missing\n");
		}
	}

// to_txntype
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "to_txntype", &csToTxnCode)) {
DEBUGLOG(("Authorize() to_txntype = [%s]\n", csToTxnCode));
		} else {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() to_txntype is missing\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() to_txntype is missing\n");
		}
	}

// remark
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("Authorize() remark = [%s]\n", csRemark));
		}
	}

// user
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() user is missing\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() user is missing\n");
		}
	}


// MatchRespTxn (lock org baid txn)
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLBAIDTxn::MatchRespTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "MatchRespTxn");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_COMPLETE) != PD_FOUND) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLBAIDTxn::MatchRespTxn() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLBAIDTxn::MatchRespTxn() failed\n");
		}
	}


// get org baid txn
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLBAIDTxn::GetBaidTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq, hOrgBaidTxn) != PD_OK) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLBAIDTxn::GetBaidTxn() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLBAIDTxn::GetBaidTxn() failed\n");
		}
	}


// check org baid txn is voidable
	if (iRet == PD_OK) {
		// get org baid txn code
		GetField_CString(hOrgBaidTxn, "txn_code", &csTmp);

DEBUGLOG(("Authorize() call DBOLBAIDTxnCode::IsVoidable()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxnCode", "IsVoidable");
		if ((unsigned long)(*DBObjPtr)(csTmp) != PD_TRUE) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLBAIDTxnCode::IsVoidable() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLBAIDTxnCode::IsVoidable() failed\n");
		}
	}


// call void baid txn handler
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call TxnOmtByUsVBT::Authorize()\n"));
		PutField_Int(hContext, "fr_convert_type", PD_TRUE);
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsVBT","Authorize");
		if ((unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse) != PD_OK) {
			iRet = INT_INVALID_TXN;
DEBUGLOG(("Authorize() call TxnOmtByUsVBT::Authorize() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call TxnOmtByUsVBT::Authorize() failed\n");
		} else {
DEBUGLOG(("Authorize() call TxnOmtByUsVBT::Authorize() SUCC\n"));
		}
	}


// add new baid txn
	if (iRet == PD_OK) {
		PutField_Int(hRec, "db_commit", PD_FALSE);

		// get baid_txn_seq
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextBaidTxnSeq");
		strcpy(csToTxnSeq, (*DBObjPtr)());
		PutField_CString(hRec, "txn_seq", csToTxnSeq);

		// channel_code
		GetField_CString(hContext, "channel_code", &csTmp);
		PutField_CString(hRec, "channel_code", csTmp);

		// status
		PutField_Char(hRec, "status", PD_COMPLETE);

		// ar_ind
		PutField_Char(hRec, "ar_ind", PD_ACCEPT);

		// sub_status
		PutField_CString(hRec, "sub_status", PD_APPROVED);

		// stat_txn_id
		GetField_CString(hOrgBaidTxn, "stat_txn_id", &csStatTxnId);
		PutField_CString(hRec, "stat_txn_id", csStatTxnId);

		// org_voided_txn_id
		PutField_CString(hRec, "org_voided_txn_id", csOrgTxnSeq);

		// txn_code
		PutField_CString(hRec, "txn_code", csToTxnCode);

		// pid
		GetField_CString(hOrgBaidTxn, "pid", &csPID);
		PutField_CString(hRec, "pid", csPID);

		// baid
		GetField_CString(hOrgBaidTxn, "baid", &csTmp);
		PutField_CString(hRec, "baid", csTmp);

		// host_posting_date
		if (GetField_CString(hContext, "PHDATE", &csTmp)) {
			PutField_CString(hRec, "posting_date", csTmp);
		}

		// transmission_datetime
		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
			strcpy(csTxnDateTime, csTmp);
			PutField_CString(hRec, "transmission_datetime", csTxnDateTime);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
			strcat(csTxnDateTime, csTmp);
			PutField_CString(hRec, "transmission_datetime", csTxnDateTime);
		}

		// txn_ccy
		GetField_CString(hOrgBaidTxn, "txn_ccy", &csTmp);
		PutField_CString(hRec, "txn_ccy", csTmp);

		// txn_amt
		GetField_Double(hOrgBaidTxn, "txn_amt", &dTmp);
		PutField_Double(hRec, "txn_amt", dTmp);

		// open_bal
		PutField_Double(hRec, "open_bal", 0.0);

		// curr_bal
		GetField_Double(hOrgBaidTxn, "curr_bal", &dTmp);
		PutField_Double(hRec, "curr_bal", dTmp);

		// approval_date & approval_timestamp
		DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "GetApprovalDT");
		(*DBObjPtr)(hRec);

		// bank_code
		GetField_CString(hOrgBaidTxn, "bank_code", &csTmp);
		PutField_CString(hRec, "bank_code", csTmp);

		// bank_acct_num
		GetField_CString(hOrgBaidTxn, "bank_acct_num", &csTmp);
		PutField_CString(hRec, "bank_acct_num", csTmp);

		// pid_txn_hold_ind
		GetField_Int(hOrgBaidTxn, "pid_txn_hold_ind", &iTmp);
		PutField_Int(hRec, "pid_txn_hold_ind", iTmp);

		// pid_sys_match_ind
		GetField_Int(hOrgBaidTxn, "pid_sys_match_ind", &iTmp);
		PutField_Int(hRec, "pid_sys_match_ind", iTmp);

		// posted_ind
		PutField_Int(hRec, "posted_ind", 0);

		// remark
		if (csRemark != NULL) {
			PutField_CString(hRec, "remark", csRemark);
		}

		// create_user
		PutField_CString(hRec, "add_user", csUser);

DEBUGLOG(("Authorize() call DBOLBAIDTxn::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Add");
		if ((unsigned long)(*DBObjPtr)(hRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBAIDTxn::Add() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLBAIDTxn::Add() failed\n");
		}

		if (iRet == PD_OK) {
			hash_destroy(hRec);
			hash_init(hRec, 0);

			// update_user
			PutField_CString(hRec, "update_user", csUser);

			// txn_id
			PutField_CString(hRec, "txn_id", csToTxnSeq);

			// stat_txn_id
			PutField_CString(hRec, "stat_txn_id", csStatTxnId);

DEBUGLOG(("Authorize() call DBOLStatement::UpdateTxnId()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "UpdateTxnId");
			if ((unsigned long)(*DBObjPtr)(hRec) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLStatement::UpdateTxnId() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLStatement::UpdateTxnId() failed\n");
			}
		}
	}


// real time post new baid txn if necessary
	if (iRet == PD_OK) {
		hash_destroy(hRec);
		hash_init(hRec, 0);

		// get psp detail
DEBUGLOG(("Authorize() call DBOLPspDetail::GetPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
		if ((unsigned long)(*DBObjPtr)(csPID, hRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLPspDetail::GetPspDetail() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLPspDetail::GetPspDetail() failed\n");
		} else {
			// get bank_acct_type
			GetField_CString(hRec, "bank_acct_type", &csBankAcctType);
		}

		if (iRet == PD_OK) {
			hash_destroy(hRec);
			hash_init(hRec, 0);

			// get txn code
DEBUGLOG(("Authorize() call DBOLBAIDTxnCode::GetDetail()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxnCode", "GetDetail");
			if ((unsigned long)(*DBObjPtr)(csToTxnCode, csBankAcctType, hRec) != PD_FOUND) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBAIDTxnCode::GetDetail() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call DBOLBAIDTxnCode::GetDetail() failed\n");
			} else {
				// get real_time_post
				GetField_Int(hRec, "real_time_post", &iRealTimePost);
			}
		}

		// post ol_baid_txn
		if (iRet == PD_OK && iRealTimePost) {
DEBUGLOG(("Authorize:: call BOOLBaid::PostBaidTxn()\n"));
			BOObjPtr = CreateObj(BOPtr, "BOOLBaid", "PostBaidTxn");
			if ((unsigned long)(*BOObjPtr)(csToTxnSeq) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call BOOLBaid::PostBaidTxn() failed\n"));
ERRLOG("TxnOmtByUsCTT::Authorize() call BOOLBaid::PostBaidTxn() failed\n");
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hResponse, "to_txn_seq", csToTxnSeq);
	}

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

