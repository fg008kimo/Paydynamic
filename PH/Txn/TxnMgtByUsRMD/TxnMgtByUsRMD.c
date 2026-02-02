/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/18              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRMD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsRMD(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csTmp = NULL;
	char *csUpdateUser = NULL;

DEBUGLOG(("Authorize:: Start\n"));

	// org_txn_seq
	if (GetField_CString(hRequest, "org_txn_seq", &csTmp)) {
DEBUGLOG(("Authorize:: org_txn_seq = [%s]\n", csTmp));
		PutField_CString(hContext, "txn_seq", csTmp);
	} else {
DEBUGLOG(("Authorize:: org_txn_seq not found!!\n"));
ERRLOG("TxnMgtByUsRMD:: Authorize:: org_txn_seq not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// add_user
	if (GetField_CString(hRequest, "add_user", &csUpdateUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUpdateUser));
		PutField_CString(hContext, "add_user", csUpdateUser);
		PutField_CString(hContext, "update_user", csUpdateUser);
	} else {
DEBUGLOG(("Authorize:: add_user not found!!\n"));
ERRLOG("TxnMgtByUsRMD:: Authorize:: add_user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// check support mini-mmm or not
	if (iRet == PD_OK) {
		PutField_CString(hContext, "mini_txn_type", PD_MI_TXN_TYPE_PSP_SETTLE);

DEBUGLOG(("Authorize:: Call TxnMgtByUs2MiniMMM:Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnMgtByUs2MiniMMM", "Authorize");
		iRet = (unsigned long)((*TxnObjPtr)(hContext, hRequest, hResponse));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: TxnMgtByUs2MiniMMM:Authorize() Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsRMD:Authorize:: TxnMgtByUs2MiniMMM:Authorize() Failed Ret [%d]\n", iRet);
		}
	}

DEBUGLOG(("TxnMgtByUsRMD Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

