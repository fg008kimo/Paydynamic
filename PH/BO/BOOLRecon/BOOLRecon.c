/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/05              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "BOOLRecon.h"
#include "myrecordset.h"
#include "myhash.h"
#include "math.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(BO);
OBJPTR(DB);

void BOOLRecon(char cdebug)
{
	cDebug = cdebug;
}

int GetTxnInfo(const char* csTxnSeq, hash_t *hContext, hash_t *hTxn);

/*
int ProcessPayoutRecon(hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int iRet = PD_OK;
	int iTmpRet;

	char *csBaidTxnId;

	hash_t *hBaidTxn;
	hBaidTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hBaidTxn, 0);

	if (GetField_CString(hContext, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("ProcessPayoutRecon:: baid txn id = [%s]\n", csBaidTxnId));
	} else {
DEBUGLOG(("ProcessPayoutRecon:: cannot get baid txn id from context\n"));
		iRet = PD_ERR;
	}

	// MatchRespTxn (lock baid txn)
	if (iRet == PD_OK) {
DEBUGLOG(("ProcessPayoutRecon:: call DBOLBAIDTxn:: MatchRespTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "MatchRespTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId, PD_COMPLETE);
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("ProcessPayoutRecon:: call DBOLBAIDTxn:: MatchRespTxn() failed\n"));
			iRet = PD_ERR;
		}
	}

	// get baid txn details
	if (iRet == PD_OK) {
DEBUGLOG(("ProcessPayoutRecon:: call DBOLBAIDTxn:: GetBaidTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId, hBaidTxn);
		if (iTmpRet != PD_OK) {
DEBUGLOG(("ProcessPayoutRecon:: call DBOLBAIDTxn:: GetBaidTxn() failed\n"));
			iRet = PD_ERR;
		}
	}

	return iRet;
}
*/

/*
	hContext:
		status, upload_status, txn_list, baid_txn_id
	hRequest:
		add_user
*/
int PostPayoutRecon(hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int iRet = PD_OK;
	char *csTmp;

DEBUGLOG(("PostPayoutRecon:: Call BOOLPayout: HandleReconGenerate\n"));
	BOObjPtr = CreateObj(BOPtr, "BOOLPayout", "HandleReconGenerate");
	if ((unsigned long)(*BOObjPtr)(hContext, hRequest, hResponse) != PD_OK) {
DEBUGLOG(("PostPayoutRecon:: Call BOOLPayout: HandleReconGenerate failed!!\n"));
ERRLOG("BOOLRecon:: PostPayoutRecon:: Call BOOLPayout: HandleReconGenerate failed!!\n");
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "baid_txn_id", &csTmp)) {
DEBUGLOG(("PostPayoutRecon:: baid txn id = [%s]\n", csTmp));

DEBUGLOG(("PostPayoutRecon:: Call BOOLBaid: PostBaidTxn\n"));
			BOObjPtr = CreateObj(BOPtr, "BOOLBaid", "PostBaidTxn");
			if ((unsigned long)(*BOObjPtr)(csTmp) != PD_OK) {
DEBUGLOG(("PostPayoutRecon:: Call BOOLBaid: PostBaidTxn failed!!\n"));
ERRLOG("BOOLRecon:: PostPayoutRecon:: Call BOOLBaid: PostBaidTxn failed!!\n");
				iRet = PD_ERR;
			}
		} else {
DEBUGLOG(("PostPayoutRecon:: cannot get baid txn id from context\n"));
			iRet = PD_ERR;
		}
	}

	return iRet;
}

/*
	hRequest:
		is_unknown_baid_txn, baid_txn_id, new_baid_txn_code
		move_baid_bal, txn_id,
		remark(optional), add_user
*/
int PostBalTfrIntraRecon(hash_t *hContext, hash_t *hRequest, hash_t *hResponse)
{
	int iRet = PD_OK;
	int iTmpRet;
	char *csTmp;
	char *csUser;
	int iMoveBaidBal;
	char *csTxnId;
	char csVoidTxnSeq[PD_TXN_SEQ_LEN + 1];
	char csNewTxnSeq[PD_TXN_SEQ_LEN + 1];
	int iIsUnknownBaidTxn;
	char *csBaidTxnId;
	char *csNewBaidTxnCode;
	char *csNewBaidTxnId;

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));

	hash_t *hOrgTxn;
	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);

	hash_t *hVoidTxn;
	hVoidTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hVoidTxn, 0);

	hash_t *hNewTxn;
	hNewTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hNewTxn, 0);

	// get user
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("PostBalTfrIntraRecon:: add_user = [%s]\n", csUser));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: add_user is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: add_user is missing\n");
		}
	}

	// check whether need to move baid balance
	if (iRet == PD_OK) {
		if (GetField_Int(hRequest, "move_baid_bal", &iMoveBaidBal)) {
DEBUGLOG(("PostBalTfrIntraRecon:: move_baid_bal = [%d]\n", iMoveBaidBal));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: move_baid_bal is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: move_baid_bal is missing\n");
		}
	}

	// get txn_id
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "txn_id", &csTxnId)) {
DEBUGLOG(("PostBalTfrIntraRecon:: txn_id = [%s]\n", csTxnId));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: txn_id is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: txn_id is missing\n");
		}
	}

	// move baid balance
	if (iRet == PD_OK && iMoveBaidBal) {
		// get txn info
		if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call GetTxnInfo\n"));
			iTmpRet = GetTxnInfo(csTxnId, hContext, hOrgTxn);
			if (iTmpRet != PD_OK) {
				iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call GetTxnInfo failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call GetTxnInfo failed!!\n");
			}
		}

		// void org txn
		if (iRet == PD_OK) {
			hash_init(hRec, 0);

			PutField_CString(hRec, "txn_seq", csTxnId);
			PutField_CString(hRec, "update_user", csUser);
			PutField_Char(hRec, "status", PD_REVERSED);
			PutField_CString(hRec, "sub_status", PD_UNDO);

DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTransaction: Update\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
			if ((unsigned long)(*DBObjPtr)(hRec) != PD_OK) {
				iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTransaction: Update failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call DBOLTransaction: Update failed!!\n");
			}

			hash_destroy(hRec);
		}

		// prepare void txn
		if (iRet == PD_OK) {
			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTxnSeq: GetNextOmtTxnSeq\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
				strcpy(csVoidTxnSeq, (*DBObjPtr)());

DEBUGLOG(("PostBalTfrIntraRecon:: Call TxnOmtByUsVBT: FormVoidTxn\n"));
				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsVBT", "FormVoidTxn");
				if ((unsigned long)(*TxnObjPtr)(csVoidTxnSeq, csTxnId, hContext, hOrgTxn, hVoidTxn) != PD_OK) {
					iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call TxnOmtByUsVBT: FormVoidTxn failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call TxnOmtByUsVBT: FormVoidTxn failed!!\n");
				}
			}

			PutField_CString(hVoidTxn, "add_user", csUser);

			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTransaction: Add\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Add");
				if ((unsigned long)(*DBObjPtr)(hVoidTxn) != PD_OK) {
					iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTransaction: Add failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call DBOLTransaction: Add failed!!\n");
				}
			}

			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTxnPspDetail: Add\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
				if ((unsigned long)(*DBObjPtr)(hVoidTxn) != PD_OK) {
					iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTxnPspDetail: Add failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call DBOLTxnPspDetail:: Add failed!!\n");
				}
			}

			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call BOOLTxnElements: VoidOrgTxnElements\n"));
				BOObjPtr = CreateObj(BOPtr, "BOOLTxnElements", "VoidOrgTxnElements");
				if ((unsigned long)(*BOObjPtr)(hVoidTxn, hVoidTxn) != PD_OK) {
					iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call BOOLTxnElements: VoidOrgTxnElements failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call BOOLTxnElements:: VoidOrgTxnElements failed!!\n");
				}
			}

			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon() Call DBOLTransaction: Add\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
				if ((unsigned long)(*DBObjPtr)(hVoidTxn) != PD_OK) {
					iRet = INT_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTransaction: Update failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call DBOLTransaction: Update failed!!\n");
				}
			}
		}

		// prepare new txn
		if (iRet == PD_OK) {
			if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLTxnSeq: GetNextOmtTxnSeq\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
				strcpy(csNewTxnSeq, (*DBObjPtr)());
			}

			PutField_CString(hNewTxn, "add_user", csUser);

			// add txn header
			// add txn detail
			// add txn psp detail
			// add tnx elements
			// void temp balance
			// update real balance
		}
	}

	// check whether need to change baid txn type
	if (iRet == PD_OK) {
		if (GetField_Int(hRequest, "is_unknown_baid_txn", &iIsUnknownBaidTxn)) {
DEBUGLOG(("PostBalTfrIntraRecon:: is_unknown_baid_txn = [%d]\n", iIsUnknownBaidTxn));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: is_unknown_baid_txn is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: is_unknown_baid_txn is missing\n");
		}
	}

	// get baid_txn_id
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("PostBalTfrIntraRecon:: baid_txn_id = [%s]\n", csBaidTxnId));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: baid_txn_id is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: baid_txn_id is missing\n");
		}
	}

	// change baid txn type
	if (iRet == PD_OK && iIsUnknownBaidTxn) {
		hash_init(hRec, 0);

		PutField_CString(hRec, "org_txn_seq", csBaidTxnId);

		if (iRet == PD_OK) {
			if (GetField_CString(hRequest, "new_baid_txn_code", &csNewBaidTxnCode)) {
				PutField_CString(hRec, "to_txntype", csNewBaidTxnCode);
DEBUGLOG(("PostBalTfrIntraRecon:: new_baid_txn_code = [%s]\n", csNewBaidTxnCode));
			} else {
				iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: new_baid_txn_code is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: new_baid_txn_code is missing\n");
			}
		}

		if (iRet == PD_OK) {
			if (GetField_CString(hRequest, "remark", &csTmp)) {
				PutField_CString(hRec, "remark", csTmp);
DEBUGLOG(("PostBalTfrIntraRecon:: remark = [%s]\n", csTmp));
			}
		}

		PutField_CString(hRec, "add_user", csUser);

		if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call TxnOmtByUsCTT: Authorize\n"));
			TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsCTT", "Authorize");
			if ((unsigned long)(*TxnObjPtr)(hContext, hRec, hResponse) != PD_OK) {
				iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call TxnOmtByUsCTT: Authorize failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call TxnOmtByUsCTT: Authorize failed!!\n");
			} else {
				if (GetField_CString(hResponse, "to_txn_seq", &csNewBaidTxnId)) {
DEBUGLOG(("PostBalTfrIntraRecon:: new_baid_txn_id = [%s]\n", csNewBaidTxnId));
				} else {
					iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: new_baid_txn_id is missing\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: new_baid_txn_id is missing\n");
				}
			}
		}

		hash_destroy(hRec);
	}

	// relate bank stmt to txn
	if (iRet == PD_OK) {
		hash_init(hRec, 0);

		if (iIsUnknownBaidTxn) {
			PutField_CString(hRec, "org_txn_seq", csNewBaidTxnId);
		} else {
			PutField_CString(hRec, "org_txn_seq", csBaidTxnId);
		}

		PutField_CString(hRec, "txn_seq", csTxnId);

		if (iRet == PD_OK) {
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLBAIDTxn: Update\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
			if ((unsigned long)(*DBObjPtr)(hRec) != PD_OK) {
				iRet = PD_ERR;
DEBUGLOG(("PostBalTfrIntraRecon:: Call DBOLBAIDTxn: Update failed!!\n"));
ERRLOG("BOOLRecon:: PostBalTfrIntraRecon:: Call DBOLBAIDTxn: Update failed!!\n");
			}
		}

		hash_destroy(hRec);
	}

	hash_destroy(hOrgTxn);
	FREE_ME(hOrgTxn);
	hash_destroy(hVoidTxn);
	FREE_ME(hVoidTxn);
	hash_destroy(hNewTxn);
	FREE_ME(hNewTxn);
	FREE_ME(hRec);

	return iRet;
}

int GetTxnInfo(const char* csTxnSeq, hash_t *hContext, hash_t *hTxn)
{
	int iRet = PD_OK;

	hash_t *hRec;

	char *csTmp;
	char cTmp;
	double dTmp = 0.0;
	int iTmp;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hash_t *hTxnPspDetail;
	hTxnPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnPspDetail, 0);

DEBUGLOG(("GetTxnInfo:: Call DBOLTransaction: GetTxnHeader\n"));
	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
	if ((*DBObjPtr)(csTxnSeq, rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec, "txn_code", &csTmp)) {
				PutField_CString(hTxn, "txn_code", csTmp);
DEBUGLOG(("GetTxnInfo:: txn_code = [%s]\n", csTmp));
			}

			if (GetField_Char(hRec, "status", &cTmp)) {
				PutField_Char(hTxn, "status", cTmp);
DEBUGLOG(("GetTxnInfo:: status = [%c]\n", cTmp));
			}

			if (GetField_Char(hRec, "ar_ind", &cTmp)) {
				PutField_Char(hTxn, "ar_ind", cTmp);
DEBUGLOG(("GetTxnInfo:: ar_ind = [%c]\n", cTmp));
			}

			if (GetField_CString(hRec, "sub_status", &csTmp)) {
				PutField_CString(hTxn, "sub_status", csTmp);
DEBUGLOG(("GetTxnInfo:: sub_status = [%s]\n", csTmp));
			}

			if (GetField_Double(hRec, "txn_amt", &dTmp)) {
				PutField_Double(hTxn, "txn_amt", dTmp);
DEBUGLOG(("GetTxnInfo:: txn_amt = [%lf]\n", dTmp));
			}

			if (GetField_Double(hRec, "net_amt", &dTmp)) {
				PutField_Double(hTxn, "net_amt", dTmp);
DEBUGLOG(("GetTxnInfo:: net_amt = [%lf]\n", dTmp));
			}

			if (GetField_CString(hRec, "net_ccy", &csTmp)) {
				PutField_CString(hTxn, "net_ccy", csTmp);
DEBUGLOG(("GetTxnInfo:: net_ccy = [%lf]\n", csTmp));
			}

			if (GetField_Double(hRec, "deposit_amt", &dTmp)) {
				PutField_Double(hTxn, "deposit_amt", dTmp);
DEBUGLOG(("GetTxnInfo:: deposit_amt = [%lf]\n", dTmp));
			}

			if (GetField_Double(hRec, "display_amt", &dTmp)) {
				PutField_Double(hTxn, "display_amt", dTmp);
DEBUGLOG(("GetTxnInfo:: display_amt = [%lf]\n", dTmp));
			}

			hRec = RecordSet_GetNext(rRecordSet);
		}
	} else {
DEBUGLOG(("GetTxnInfo:: not found record for [%s]\n", csTxnSeq));
		iRet = INT_INVALID_TXN;
		// PutField_Int(hContext, "internal_error", iRet);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo:: Call OLTxnPspDetail: GetTxnPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
		if ((*DBObjPtr)(csTxnSeq, hTxnPspDetail) == PD_OK) {
			if (GetField_CString(hTxnPspDetail, "psp_id", &csTmp)) {
				PutField_CString(hTxn, "psp_id", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "baid", &csTmp)) {
				PutField_CString(hTxn, "baid", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "txn_ccy", &csTmp)) {
				PutField_CString(hTxn, "txn_ccy", csTmp);
			}

			if (GetField_Double(hTxnPspDetail, "txn_amount", &dTmp)) {
				PutField_Double(hTxn, "txn_amount", dTmp);
			}

			if (GetField_CString(hTxnPspDetail, "bank_code", &csTmp)) {
				PutField_CString(hTxn, "bank_code", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "bank_acct_num", &csTmp)) {
				PutField_CString(hTxn, "bank_acct_num", csTmp);
			}

			if (GetField_Double(hTxnPspDetail, "cost", &dTmp)) {
				PutField_Double(hTxn, "cost", dTmp);
			}

			if (GetField_Int(hTxnPspDetail, "txn_hold_ind", &iTmp)) {
				PutField_Int(hTxn, "txn_hold_ind", iTmp);
			}

			if (GetField_Int(hTxnPspDetail, "sys_match_ind", &iTmp)) {
				PutField_Int(hTxn, "sys_match_ind", iTmp);
			}
		} else {
			iRet = INT_INVALID_TXN;
			// PutField_Int(hContext, "internal_error", iRet);
		}
	}

	hash_destroy(hTxnPspDetail);
	FREE_ME(hTxnPspDetail);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
}

/*
int FormNewTxn(const char *csNewTxnSeq, const char *csOrgTxnSeq, hash_t *hContext, hash_t *hOrgTxn, hash_t *hNewTxn)
{
	int iRet = PD_OK;

	char *csTmp;
	char csTxnDateTime[PD_DATETIME_LEN + 1];
	double dTmp = 0.0;
	int iTmp;
	double dTxnAmt = 0.0;

	PutField_Int(hNewTxn, "db_commit", PD_FALSE);

						// if (GetField_CString(hOrgTxn, "txn_code", &csTmp)) {
							// PutField_CString(hNewTxn, "org_txn_code", csTmp);
						// }

	// txn_id
	PutField_CString(hNewTxn, "txn_seq", csNewTxnSeq);
	PutField_CString(hNewTxn, "org_txn_seq", csOrgTxnSeq);

	// input_channel
	if (GetField_CString(hOrgTxn, "channel_code", &csTmp)) {
		PutField_CString(hNewTxn, "channel_code", csTmp);
	}

	// status
	PutField_Char(hNewTxn, "status", PD_COMPLETE);

	// txn_code
	PutField_CString(hNewTxn, "txn_code", csNewTxnCode);

	// process_type
	if (GetField_CString(hOrgTxn, "process_type", &csTmp)) {
		PutField_CString(hNewTxn, "process_type", csTmp);
	}

	// process_code
	if (GetField_CString(hOrgTxn, "process_code", &csTmp)) {
		PutField_CString(hNewTxn, "process_code", csTmp);
	}

	// host_posting_date
	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
		PutField_CString(hNewTxn, "host_posting_date", csTmp);
	}

	// internal_code
	if (GetField_Int(hOrgTxn, "internal_code", &iTmp)) {
		PutField_Int(hNewTxn, "internal_code", iTmp);
	}

	// response_code
	if (GetField_CString(hOrgTxn, "response_code", &csTmp)) {
		PutField_CString(hNewTxn, "response_code", csTmp);
	}

	// transaction_amount
	if (GetField_Double(hOrgTxn, "txn_amt", &dTmp)) {
		PutField_Double(hNewTxn, "txn_amt", dTmp);
	}

	// transmission_datetime
	// local_tm_date
	// local_tm_time
	// tm_date
	// tm_time
	if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
		PutField_CString(hNewTxn, "local_tm_date", csTmp);
		strcpy(csTxnDateTime, csTmp);
		PutField_CString(hNewTxn, "transmission_datetime", csTxnDateTime);
		PutField_CString(hNewTxn, "tm_date", csTmp);
	}
	if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
		PutField_CString(hNewTxn, "local_tm_time", csTmp);
		strcat(csTxnDateTime, csTmp);
		PutField_CString(hNewTxn, "transmission_datetime", csTxnDateTime);
		PutField_CString(hNewTxn, "tm_time", csTmp);
	}

	// create_user
	// ???

	// psp_id
	if (GetField_CString(hOrgTxn, "psp_id", &csTmp)) {
		PutField_CString(hNewTxn, "psp_id", csTmp);
	}

	// baid
	if (GetField_CString(hOrgTxn, "baid", &csTmp)) {
		PutField_CString(hNewTxn, "baid", csTmp);
	}

	// txn_ccy
	if (GetField_CString(hOrgTxn, "txn_ccy", &csTmp)) {
		PutField_CString(hNewTxn, "txn_ccy", csTmp);
	}

	// txn_amount
	if (GetField_Double(hOrgTxn, "txn_amount", &dTxnAmt)) {
		PutField_Double(hNewTxn, "txn_amount", dTxnAmt);
	}

	tNow = time(0);
	tStruct = localtime(&tNow);

	// txn_date
	strftime(csBuf, sizeof(csBuf), "%Y%m%d", tStruct);
	PutField_CString(hNewTxn, "txn_date", csBuf);

	// txn_time
	strftime(csBuf, sizeof(csBuf), "%H%M%S", tStruct);
	PutField_CString(hNewTxn, "txn_time", csBuf);

	// bank_code
	if (GetField_CString(hOrgTxn, "bank_code", &csTmp)) {
		PutField_CString(hNewTxn, "bank_code", csTmp);
	}

	// bank_acct_num
	if (GetField_CString(hOrgTxn, "bank_acct_num", &csTmp)) {
		PutField_CString(hNewTxn, "bank_acct_num", csTmp);
	}

	// cost
	if (GetField_Double(hOrgTxn, "cost", &dTmp)) {
		PutField_Double(hNewTxn, "cost", dTmp);
	}

	// open_bal
	if (GetField_Double(hOrgTxn, "open_bal", &dTmp)) {
		PutField_Double(hNewTxn, "open_bal", dTmp);
	}

	// total_hold
	if (GetField_Double(hOrgTxn, "total_hold", &dTmp)) {
		PutField_Double(hNewTxn, "total_hold", dTmp);
	}

	// bal
	if (GetField_Double(hOrgTxn, "balance", &dTmp)) {
		PutField_Double(hNewTxn, "bal", dTmp);
	}

	// txn_hold_ind
	if (GetField_Int(hOrgTxn, "txn_hold_ind", &iTmp)) {
		PutField_Int(hNewTxn, "txn_hold_int", iTmp);
	}

	// sys_match_ind
	if (GetField_Int(hOrgTxn, "sys_match_ind", &iTmp)) {
		PutField_Int(hNewTxn, "sys_match_ind", iTmp);
	}

	return iRet;
}
*/