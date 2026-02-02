/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/17              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMinByUsPMD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMinByUsPMD(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet = PD_NOT_FOUND;

	char *csPstTxnId = NULL;
	char *csRitTxnId = NULL;
	char *csUpdateUser = NULL;
	int iFoundRit = PD_FALSE;
	char *csTxnCode = NULL;
	char cStatus;
	char cArInd;
	char *csSubStatus = NULL;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	recordset_t *rBatchDetail;
	rBatchDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rBatchDetail, 0);
	hash_t *hBatchDetail;

	recordset_t *rTxnHeader;
	rTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnHeader, 0);
	hash_t *hTxnHeader;

DEBUGLOG(("Authorize:: Start\n"));

	// get psp settlement txn id
	if (GetField_CString(hContext, "txn_seq", &csPstTxnId)) {
DEBUGLOG(("Authorize:: psp settlement txn id = [%s]\n", csPstTxnId));
	} else {
DEBUGLOG(("Authorize:: psp settlement txn id not found!!\n"));
ERRLOG("TxnMinByUsPMD:: Authorize:: psp settlement txn id not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get update user
	if (GetField_CString(hContext, "update_user", &csUpdateUser)) {
DEBUGLOG(("Authorize:: update user = [%s]\n", csUpdateUser));
	} else {
DEBUGLOG(("Authorize:: update user not found!!\n"));
ERRLOG("TxnMinByUsPMD:: Authorize:: update user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// check psp settlement txn id exists in table mi_txn_log
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBMiTxnLog:CheckTxnIdExist()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiTxnLog", "CheckTxnIdExist");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csPstTxnId)));
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: DBMiTxnLog:CheckTxnIdExist() not found, not mini-mmm txn\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBMiTxnLog:CheckTxnIdExist() not found, not mini-mmm txn\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// check psp settlement txn status and sub status
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csPstTxnId, rTxnHeader)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:GetTxnHeader() not found\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hTxnHeader = RecordSet_GetFirst(rTxnHeader);

			if (GetField_CString(hTxnHeader, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: PST txn header txn code = [%s]\n", csTxnCode));
			}

			if (GetField_Char(hTxnHeader, "status", &cStatus)) {
DEBUGLOG(("Authorize:: PST txn header status = [%c]\n", cStatus));
			}

			if (GetField_Char(hTxnHeader, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: PST txn header ar ind = [%c]\n", cArInd));
			}

			if (GetField_CString(hTxnHeader, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: PST txn header sub status = [%s]\n", csSubStatus));
			}

			if ((strcmp(csTxnCode, PD_PSP_SETTLEMENT)) ||
				(cStatus != PD_COMPLETE) ||
				(cArInd != PD_ACCEPT) ||
				(strcmp(csSubStatus, PD_APPROVED))) {
DEBUGLOG(("Authorize:: not approved PSP Settlement [%s]\n", csPstTxnId));
ERRLOG("TxnMinByUsPMD:Authorize:: not approved PSP Settlement [%s]\n", csPstTxnId);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	// get rsp in-transit txn id
	if (iRet == PD_OK) {
		PutField_CString(hTxn, "txn_id", csPstTxnId);
		//PutField_Char(hTxn, "oper_ind", PD_MI_BATCH_TXN_OPER_INSERT);

DEBUGLOG(("Authorize:: Call DBMiBatchDetail:GetAllDetailByTxnId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "GetAllDetailByTxnId");
		iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn, rBatchDetail)));
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: DBMiBatchDetail:GetAllDetailByTxnId() not found\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBMiBatchDetail:GetAllDetailByTxnId() not found\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hBatchDetail = RecordSet_GetFirst(rBatchDetail);
			while (hBatchDetail) {
				// get txn id
				if (GetField_CString(hBatchDetail, "txn_id", &csRitTxnId)) {
DEBUGLOG(("Authorize:: batch detail txn id = [%s]\n", csRitTxnId));
				}

				// check txn header
				RecordSet_Destroy(rTxnHeader);
				recordset_init(rTxnHeader, 0);

DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnHeader()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
				iTmpRet = ((unsigned long)((*DBObjPtr)(csRitTxnId, rTxnHeader)));
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:GetTxnHeader() not found\n");
				} else {
					hTxnHeader = RecordSet_GetFirst(rTxnHeader);

					if (GetField_CString(hTxnHeader, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: RIT? txn header txn code = [%s]\n", csTxnCode));
						if (!strcmp(csTxnCode, PD_MI_TXN_CODE_RSP_IN_TRANSIT)) {
							if (GetField_Char(hTxnHeader, "status", &cStatus)) {
DEBUGLOG(("Authorize:: RIT txn header status = [%c]\n", cStatus));
								if (cStatus == PD_COMPLETE) {
									if (GetField_Char(hTxnHeader, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: RIT txn header ar ind = [%c]\n", cArInd));
										if (cArInd == PD_ACCEPT) {
											if (GetField_CString(hTxnHeader, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: RIT txn header sub status = [%s]\n", csSubStatus));
												if (!strcmp(csSubStatus, PD_APPROVED)) {
DEBUGLOG(("Authorize:: approved RSP In-Transit [%s] found\n", csRitTxnId));
													iFoundRit = PD_TRUE;
													break;
												}
											}
										}
									}
								}
							}
						}
					}
				}
				hBatchDetail = RecordSet_GetNext(rBatchDetail);
			}
		}
	}

	if (iRet == PD_OK && iFoundRit) {
		hash_destroy(hTxn);
		hash_init(hTxn, 0);

		// update psp settlement txn

		PutField_CString(hTxn, "txn_seq", csPstTxnId);
		PutField_CString(hTxn, "sub_status", PD_MANUAL_DELIVERED);
		PutField_CString(hTxn, "update_user", csUpdateUser);

DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnIdForUpdateNoWait()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnIdForUpdateNoWait");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csPstTxnId)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:Update()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
			iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn)));
			if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:Update() failed\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:Update() failed\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}

		// update rsp in-transit txn

		PutField_CString(hTxn, "txn_seq", csRitTxnId);

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnIdForUpdateNoWait()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnIdForUpdateNoWait");
			iTmpRet = ((unsigned long)((*DBObjPtr)(csRitTxnId)));
			if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n");
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:Update()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
			iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn)));
			if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:Update() failed\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: DBTransaction:Update() failed\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	} else {
DEBUGLOG(("Authorize:: approved RSP In-Transit not found\n"));
ERRLOG("TxnMinByUsPMD:Authorize:: approved RSP In-Transit not found\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// hash destroy
	hash_destroy(hTxn);
	FREE_ME(hTxn);
	// recordset destroy
	RecordSet_Destroy(rBatchDetail);
	FREE_ME(rBatchDetail);
	RecordSet_Destroy(rTxnHeader);
	FREE_ME(rTxnHeader);

DEBUGLOG(("TxnMinByUsPMD Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

