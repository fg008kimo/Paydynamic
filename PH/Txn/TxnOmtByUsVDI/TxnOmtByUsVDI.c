/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/04              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsVDI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsVDI(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext,
	hash_t *hRequest,
	hash_t *hResponse)
{
	int iRet = PD_OK;

	char *csRbdTxnSeq;
	char *csBaidTxnId;
	char *csUser;

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("Authorize\n"));

	if (GetField_CString(hRequest, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("Authorize:: baid_txn_id = [%s]\n", csBaidTxnId));
	} else {
DEBUGLOG(("Authorize:: baid_txn_id not found!!\n"));
ERRLOG("TxnOmtByUsVDI: Authorize:: baid_txn_id not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call TxnOmtByUsVOT: Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsVOT", "Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "rbd_txn_seq", &csRbdTxnSeq)) {
DEBUGLOG(("Authorize:: rbd_txn_seq = [%s]\n", csRbdTxnSeq));
		} else {
DEBUGLOG(("Authorize:: rbd_txn_seq not found!!\n"));
ERRLOG("TxnOmtByUsVDI: Authorize:: rbd_txn_seq not found!!\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
		}

		// call manual recon function
		hash_init(hTmp, 0);
		PutField_CString(hTmp, "activity", "RECON");
		PutField_CString(hTmp, "bank_stmt_type", "RETURN_MATCHED_DEPOSIT");
		PutField_CString(hTmp, "recon_type", "SAME");
		PutField_CString(hTmp, "trigger_type", "manual");
		PutField_CString(hTmp, "input_channel", "OMT");
		PutField_CString(hTmp, "use_pf", "0");
		PutField_CString(hTmp, "have_charge", "0");
		PutField_CString(hTmp, "have_interest", "0");
		PutField_CString(hTmp, "add_user", csUser);
		PutField_CString(hTmp, "txn_cnt", "1");
		PutField_CString(hTmp, "txnid_1", csRbdTxnSeq);
		PutField_CString(hTmp, "stmt_cnt", "1");
		PutField_CString(hTmp, "stmt_txnid_1", csBaidTxnId);
DEBUGLOG(("Authorize:: call TxnOmtByUsREC: Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsREC", "Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hTmp, hTmp, hTmp);
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: recon return success\n"));
		} else {
DEBUGLOG(("Authorize:: recon return failed\n"));
		}
		hash_destroy(hTmp);
	}

	FREE_ME(hTmp);

DEBUGLOG(("TxnOmtByUsVDI Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
