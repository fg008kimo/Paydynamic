/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/20              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOMD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnOmtByUsOMD(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet;

	char *csOptTxnId = NULL;
	char *csUpdateUser = NULL;
	char *csTxnCode = NULL;
	char cStatus;
	char cArInd;
	char *csSubStatus = NULL;
	char cReconStatus;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	recordset_t *rTxnHeader;
	rTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnHeader, 0);
	hash_t *hTxnHeader;

DEBUGLOG(("Authorize:: Start\n"));

	// org_txn_seq
	if (GetField_CString(hRequest, "org_txn_seq", &csOptTxnId)) {
DEBUGLOG(("Authorize:: org_txn_seq = [%s]\n", csOptTxnId));
		PutField_CString(hContext, "txn_seq", csOptTxnId);
	} else {
DEBUGLOG(("Authorize:: org_txn_seq not found!!\n"));
ERRLOG("TxnOmtByUsOMD:: Authorize:: org_txn_seq not found!!\n");
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
ERRLOG("TxnOmtByUsOMD:: Authorize:: add_user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// check psp settlement txn status and sub status
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csOptTxnId, rTxnHeader)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBOLTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnOmtByUsOMD:Authorize:: DBOLTransaction:GetTxnHeader() not found\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hTxnHeader = RecordSet_GetFirst(rTxnHeader);

			if (GetField_CString(hTxnHeader, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: OPT txn header txn code = [%s]\n", csTxnCode));
			}

			if (GetField_Char(hTxnHeader, "status", &cStatus)) {
DEBUGLOG(("Authorize:: OPT txn header status = [%c]\n", cStatus));
			}

			if (GetField_Char(hTxnHeader, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: OPT txn header ar ind = [%c]\n", cArInd));
			}

			if (GetField_CString(hTxnHeader, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: OPT txn header sub status = [%s]\n", csSubStatus));
			}

			if (GetField_Char(hTxnHeader, "recon_status", &cReconStatus)) {
DEBUGLOG(("Authorize:: OPT txn header recon status = [%c]\n", cReconStatus));
			}

			if ((strcmp(csTxnCode, PD_PSP_SETTLEMENT_TXN_CODE)) ||
				(cStatus != PD_COMPLETE) ||
				(cArInd != PD_ACCEPT) ||
				(strcmp(csSubStatus, PD_APPROVED)) ||
				(cReconStatus != PD_RECONCILED)) {
DEBUGLOG(("Authorize:: not approved PSP Settlement [%s]\n", csOptTxnId));
ERRLOG("TxnOmtByUsOMD:Authorize:: not approved PSP Settlement [%s]\n", csOptTxnId);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	// update psp settlement txn
	if (iRet == PD_OK) {
		hash_destroy(hTxn);
		hash_init(hTxn, 0);

		PutField_CString(hTxn, "txn_seq", csOptTxnId);
		PutField_CString(hTxn, "sub_status", PD_MANUAL_DELIVERED);
		PutField_CString(hTxn, "update_user", csUpdateUser);

DEBUGLOG(("Authorize:: Call DBOLTransaction:Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBOLTransaction:Update() failed\n"));
ERRLOG("TxnOmtByUsOMD:Authorize:: DBOLTransaction:Update() failed\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// hash destroy
	hash_destroy(hTxn);
	FREE_ME(hTxn);
	// recordset destroy
	RecordSet_Destroy(rTxnHeader);
	FREE_ME(rTxnHeader);

DEBUGLOG(("TxnOmtByUsOMD Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

