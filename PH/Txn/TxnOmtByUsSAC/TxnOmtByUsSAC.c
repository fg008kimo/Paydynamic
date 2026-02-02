/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/02/04              David Wong
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
#include "TxnOmtByUsSAC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;

void TxnOmtByUsSAC(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(Msg);
OBJPTR(Txn);
OBJPTR(DB);

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csTmp;
	int i, iTmpRet;
	char csTag[PD_TAG_LEN + 1];

	char cAction;
	char cReconType;
	int iCnt = 0;
	char *csUser;
	char *csBaidTxnId1, *csBaidTxnId2;
	double dTxnAmt = 0.0, dEstNetAmt = 0.0, dBankCharge = 0.0;
	char *csBankCharge;
	csBankCharge = (char*) malloc (128);

	hash_t *hTxnDtl;
	hTxnDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnDtl, 0);

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("Authorize\n"));

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize:: action = [%c]\n", cAction))
		if (cAction != 'C' && cAction != 'F') {
DEBUGLOG(("Authorize:: action not accepted!!\n"));
ERRLOG("TxnOmtByUsSAC:: Authorize:: action not accepted!!\n");
			iRet = INT_ACTION_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize:: action not found!!\n"));
ERRLOG("TxnOmtByUsSAC:: Authorize:: action not found!!\n");
		iRet = INT_ACTION_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* total cnt */
	if (GetField_CString(hRequest, "total_cnt", &csTmp)) {
		iCnt = atoi(csTmp);
DEBUGLOG(("Authorize:: total_cnt = [%d]\n", iCnt));
	} else {
DEBUGLOG(("Authorize:: total_cnt not found!!\n"));
ERRLOG("TxnOmtByUsSAC:: Authorize:: total_cnt not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* user */
	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: user = [%s]\n", csUser));
	} else {
DEBUGLOG(("Authorize:: user not found!!\n"));
ERRLOG("TxnOmtByUsSAC:: Authorize:: user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (iRet == PD_OK) {
		for (i = 1; i <= iCnt; i++) {
			// get baid_txn_id_1
			sprintf(csTag, "%s_baid_txn_id_1_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csBaidTxnId1)) {
DEBUGLOG(("Authorize:: [%s] = [%s]\n", csTag, csBaidTxnId1));
			} else {
DEBUGLOG(("Authorize:: [%s] not found!!\n", csTag));
ERRLOG("TxnOmtByUsSAC:: Authorize:: [%s] not found!!\n", csTag);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// get sender bank charge (if any)
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::GetBaidTxn()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
			iTmpRet = (unsigned long)(*DBObjPtr)(csBaidTxnId1, hTxnDtl);
			if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::GetBaidTxn() failed\n"));
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			} else {
					// get txn_amt
					if (GetField_Double(hTxnDtl, "txn_amt", &dTxnAmt)) {
DEBUGLOG(("Authorize:: sender txn_amt = [%lf]\n", dTxnAmt));
					}
					// get est_net_amount
					if (GetField_Double(hTxnDtl, "est_net_amount", &dEstNetAmt)) {
DEBUGLOG(("Authorize:: sender est_net_amount = [%lf]\n", dEstNetAmt));
						dBankCharge = dTxnAmt - dEstNetAmt;
						sprintf(csBankCharge, "%lf", dBankCharge);
					}
			}

			// get baid_txn_id_2
			sprintf(csTag, "%s_baid_txn_id_2_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csBaidTxnId2)) {
DEBUGLOG(("Authorize:: [%s] = [%s]\n", csTag, csBaidTxnId2));
			} else {
DEBUGLOG(("Authorize:: [%s] not found!!\n", csTag));
ERRLOG("TxnOmtByUsSAC:: Authorize:: [%s] not found!!\n", csTag);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// get recon_type
			sprintf(csTag, "%s_recon_type_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
				cReconType = csTmp[0];
DEBUGLOG(("Authorize:: [%s] = [%c]\n", csTag, cReconType));
			} else {
DEBUGLOG(("Authorize:: [%s] not found!!\n", csTag));
ERRLOG("TxnOmtByUsSAC:: Authorize:: [%s] not found!!\n", csTag);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}

			// if (cAction == 'F') {
				// remove from wait recon confirm list
				hash_init(hTmp, 0);
				PutField_CString(hTmp, "baid_txn_id_1", csBaidTxnId1);
				PutField_CString(hTmp, "baid_txn_id_2", csBaidTxnId2);
DEBUGLOG(("Authorize:: call DBOLWaitReconCfmList::DeleteSingle()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLWaitReconCfmList", "DeleteSingle");
				iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: delete return success\n", csBaidTxnId1));
				} else {
DEBUGLOG(("Authorize:: delete return failed\n", csBaidTxnId1));
				}
				hash_destroy(hTmp);

				// set hold_recon to false (sender)
				hash_init(hTmp, 0);
				PutField_CString(hTmp, "txn_seq", csBaidTxnId1);
				PutField_CString(hTmp, "update_user", csUser);
				PutField_Int(hTmp, "hold_recon", PD_FALSE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
				iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csBaidTxnId1));
				} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csBaidTxnId1));
				}
				hash_destroy(hTmp);

				// set hold_recon to false (recipient)
				hash_init(hTmp, 0);
				PutField_CString(hTmp, "txn_seq", csBaidTxnId2);
				PutField_CString(hTmp, "update_user", csUser);
				PutField_Int(hTmp, "hold_recon", PD_FALSE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
				iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csBaidTxnId2));
				} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csBaidTxnId2));
				}
				hash_destroy(hTmp);
			// } else
			if (cAction == 'C') {
				// call manual recon function
				hash_init(hTmp, 0);
				PutField_CString(hTmp, "activity", "RECON");
				if (cReconType == 'N') {
					PutField_CString(hTmp, "bank_stmt_type", "BALANCE_TRANSFER_INTRA");
					PutField_CString(hTmp, "recon_type", "CROSS");
				} else {
					PutField_CString(hTmp, "bank_stmt_type", "RETURN_SWEEP_OUT_NOTXN");
					PutField_CString(hTmp, "recon_type", "RETURN");
				}
				PutField_CString(hTmp, "trigger_type", "manual");
				PutField_CString(hTmp, "input_channel", "OMT");
				PutField_CString(hTmp, "use_pf", "0");
				if (dBankCharge == 0.0) {
					PutField_CString(hTmp, "have_charge", "0");
					//PutField_CString(hTmp, "bank_charge", "0.00");
				} else {
					PutField_CString(hTmp, "have_charge", "1");
					PutField_CString(hTmp, "bank_charge", csBankCharge);
				}
				PutField_CString(hTmp, "have_interest", "0");
				//PutField_CString(hTmp, "interest", "0.00");
				PutField_CString(hTmp, "add_user", csUser);
				PutField_CString(hTmp, "txn_cnt", "0");
				PutField_CString(hTmp, "stmt_cnt", "2");
				PutField_CString(hTmp, "stmt_txnid_1", csBaidTxnId1);
				PutField_CString(hTmp, "stmt_txnid_2", csBaidTxnId2);
DEBUGLOG(("Authorize:: call TxnOmtByUsREC::Authorize()\n"));
				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsREC", "Authorize");
				iTmpRet = (unsigned long)(*TxnObjPtr)(hTmp, hTmp, hTmp);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: recon return success\n"));
					TxnCommit();
				} else {
DEBUGLOG(("Authorize:: recon return failed\n"));
					TxnAbort();
					iRet = iTmpRet;
					PutField_Int(hContext, "internal_error", iRet);
				}
				hash_destroy(hTmp);
			}
		}
	}

	FREE_ME(csBankCharge);
	hash_destroy(hTxnDtl);
	FREE_ME(hTxnDtl);
	FREE_ME(hTmp);

DEBUGLOG(("Authorize: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
