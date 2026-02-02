/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/02/05              [ANC]
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
#include "TxnOmtByUsPRC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	PD_DETAIL_TAG	"dt"

static char cDebug;

void TxnOmtByUsPRC(char cdebug)
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
	int iCnt = 0;
	char *csUser;
	char *csPspTxnId, *csBaidTxnId;

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
ERRLOG("TxnOmtByUsPRC:: Authorize:: action not accepted!!\n");
			iRet = INT_ACTION_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize:: action not found!!\n"));
ERRLOG("TxnOmtByUsPRC:: Authorize:: action not found!!\n");
		iRet = INT_ACTION_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* total cnt */
	if (GetField_CString(hRequest, "total_cnt", &csTmp)) {
		iCnt = atoi(csTmp);
DEBUGLOG(("Authorize:: total_cnt = [%d]\n", iCnt));
	} else {
DEBUGLOG(("Authorize:: total_cnt not found!!\n"));
ERRLOG("TxnOmtByUsPRC:: Authorize:: total_cnt not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* user */
	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: user = [%s]\n", csUser));
	} else {
DEBUGLOG(("Authorize:: user not found!!\n"));
ERRLOG("TxnOmtByUsPRC:: Authorize:: user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (iRet == PD_OK) {
		for (i = 1; i <= iCnt; i++) {
			// get psp_txn_id
			sprintf(csTag, "%s_psp_txn_id_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csPspTxnId)) {
DEBUGLOG(("Authorize:: [%s] = [%s]\n", csTag, csPspTxnId));
			} else {
DEBUGLOG(("Authorize:: [%s] not found!!\n", csTag));
ERRLOG("TxnOmtByUsPRC:: Authorize:: [%s] not found!!\n", csTag);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
				break;
			}

			// get baid_txn_id
			sprintf(csTag, "%s_baid_txn_id_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csBaidTxnId)) {
DEBUGLOG(("Authorize:: [%s] = [%s]\n", csTag, csBaidTxnId));
			} else {
DEBUGLOG(("Authorize:: [%s] not found!!\n", csTag));
ERRLOG("TxnOmtByUsPRC:: Authorize:: [%s] not found!!\n", csTag);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
				break;
			}

			// remove from wait recon confirm list
			hash_init(hTmp, 0);
			PutField_CString(hTmp, "psp_txn_id", csPspTxnId);
			PutField_CString(hTmp, "baid_txn_id", csBaidTxnId);
DEBUGLOG(("Authorize:: call DBOLWaitPayoutReconCfmList::DeleteSingle()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLWaitPayoutReconCfmList", "DeleteSingle"); 
			iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
			if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: delete return success\n"));
			} else {
DEBUGLOG(("Authorize:: delete return failed\n"));
			}
			hash_destroy(hTmp);


			// set hold_recon to false (BaidTxn)
			hash_init(hTmp, 0);
			PutField_CString(hTmp, "txn_seq", csBaidTxnId);
			PutField_CString(hTmp, "update_user", csUser);
			PutField_Int(hTmp, "hold_recon", PD_FALSE);
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::Update()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
			iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
			if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: Update [%s] hold_recon success\n", csBaidTxnId));
			} else {
DEBUGLOG(("Authorize:: Update [%s] hold_recon failed\n", csBaidTxnId));
			}
			hash_destroy(hTmp);

			if (cAction == 'C') {
				// call manual recon function
				hash_init(hTmp, 0);
				PutField_CString(hTmp, "activity", "RECON");
				PutField_CString(hTmp, "bank_stmt_type", "PAYOUT");
				PutField_CString(hTmp, "recon_type", "SAME");
				PutField_CString(hTmp, "trigger_type", "manual");
				PutField_CString(hTmp, "input_channel", "OMT");				
				PutField_CString(hTmp, "use_pf", "1");
				PutField_CString(hTmp, "have_charge", "0");
				PutField_CString(hTmp, "have_interest", "0");
				PutField_CString(hTmp, "add_user", csUser);
				PutField_CString(hTmp, "txn_cnt", "1");
				PutField_CString(hTmp, "txnid_1", csPspTxnId);
				PutField_CString(hTmp, "stmt_cnt", "1");
				PutField_CString(hTmp, "stmt_txnid_1", csBaidTxnId);
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

	hash_destroy(hTxnDtl);
	FREE_ME(hTxnDtl);
	FREE_ME(hTmp);

DEBUGLOG(("Authorize: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
