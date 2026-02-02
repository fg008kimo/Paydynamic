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
#include "TxnMinByUsRMD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMinByUsRMD(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet = PD_NOT_FOUND;

	char *csDloTxnId = NULL;
	char *csPstRitTxnId = NULL;
	char *csUpdateUser = NULL;
	int iFoundPstRit = PD_FALSE;
	char *csTxnCode = NULL;
	char cStatus;
	char cArInd;
	char *csSubStatus = NULL;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	hash_t *hTmpTxnId;

	recordset_t *rBatchDetail;
	rBatchDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rBatchDetail, 0);
	hash_t *hBatchDetail;

	recordset_t *rTxnHeader;
	rTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnHeader, 0);
	hash_t *hTxnHeader;

	recordset_t *rUpdateTxnId;
	rUpdateTxnId = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rUpdateTxnId, 0);
	hash_t *hUpdateTxnId;

DEBUGLOG(("Authorize:: Start\n"));

	// get rsp delivery out txn id
	if (GetField_CString(hContext, "txn_seq", &csDloTxnId)) {
DEBUGLOG(("Authorize:: rsp delivery out txn id = [%s]\n", csDloTxnId));
	} else {
DEBUGLOG(("Authorize:: rsp delivery out txn id not found!!\n"));
ERRLOG("TxnMinByUsRMD:: Authorize:: rsp delivery out txn id not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// get update user
	if (GetField_CString(hContext, "update_user", &csUpdateUser)) {
DEBUGLOG(("Authorize:: update user = [%s]\n", csUpdateUser));
	} else {
DEBUGLOG(("Authorize:: update user not found!!\n"));
ERRLOG("TxnMinByUsRMD:: Authorize:: update user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// unlike psp settlement, no need to check rsp delivery out txn id exists in table mi_txn_log

	// check rsp delivery out txn status and sub status
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csDloTxnId, rTxnHeader)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:GetTxnHeader() not found\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hTxnHeader = RecordSet_GetFirst(rTxnHeader);

			if (GetField_CString(hTxnHeader, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: DLO txn header txn code = [%s]\n", csTxnCode));
			}

			if (GetField_Char(hTxnHeader, "status", &cStatus)) {
DEBUGLOG(("Authorize:: DLO txn header status = [%c]\n", cStatus));
			}

			if (GetField_Char(hTxnHeader, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: DLO txn header ar ind = [%c]\n", cArInd));
			}

			if (GetField_CString(hTxnHeader, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: DLO txn header sub status = [%s]\n", csSubStatus));
			}

			if ((strcmp(csTxnCode, PD_MI_TXN_CODE_RSP_DELIVERY_IN)) ||
				(cStatus != PD_COMPLETE) ||
				(cArInd != PD_ACCEPT) ||
				(strcmp(csSubStatus, PD_APPROVED))) {
DEBUGLOG(("Authorize:: not approved RSP Delivery In [%s]\n", csDloTxnId));
ERRLOG("TxnMinByUsRMD:Authorize:: not approved RSP Delivery In [%s]\n", csDloTxnId);
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	// get psp settlement txn id & rsp in-transit txn id
	if (iRet == PD_OK) {
		PutField_CString(hTxn, "txn_id", csDloTxnId);
		PutField_Char(hTxn, "oper_ind", PD_MI_BATCH_TXN_OPER_INSERT);

DEBUGLOG(("Authorize:: Call DBMiBatchDetail:GetAllDetailByTxnId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "GetAllDetailByTxnId");
		iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn, rBatchDetail)));
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: DBMiBatchDetail:GetAllDetailByTxnId() not found\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBMiBatchDetail:GetAllDetailByTxnId() not found\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			hBatchDetail = RecordSet_GetFirst(rBatchDetail);
			while (hBatchDetail) {
				// get txn id
				if (GetField_CString(hBatchDetail, "txn_id", &csPstRitTxnId)) {
DEBUGLOG(("Authorize:: batch detail txn id = [%s]\n", csPstRitTxnId));
				}

				// check txn header
				RecordSet_Destroy(rTxnHeader);
				recordset_init(rTxnHeader, 0);

DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnHeader()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
				iTmpRet = ((unsigned long)((*DBObjPtr)(csPstRitTxnId, rTxnHeader)));
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:GetTxnHeader() not found\n");
				} else {
					hTxnHeader = RecordSet_GetFirst(rTxnHeader);

					if (GetField_CString(hTxnHeader, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: PST?/RIT? txn header txn code = [%s]\n", csTxnCode));
						if (!strcmp(csTxnCode, PD_PSP_SETTLEMENT) ||
							!strcmp(csTxnCode, PD_MI_TXN_CODE_RSP_IN_TRANSIT)) {
							if (GetField_Char(hTxnHeader, "status", &cStatus)) {
DEBUGLOG(("Authorize:: PST/RIT txn header status = [%c]\n", cStatus));
								if (cStatus == PD_COMPLETE) {
									if (GetField_Char(hTxnHeader, "ar_ind", &cArInd)) {
DEBUGLOG(("Authorize:: PST/RIT txn header ar ind = [%c]\n", cArInd));
										if (cArInd == PD_ACCEPT) {
											if (GetField_CString(hTxnHeader, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: PST/RIT txn header sub status = [%s]\n", csSubStatus));
												if (!strcmp(csSubStatus, PD_DELIVERING)) {
DEBUGLOG(("Authorize:: approved PSP Settlement / RSP In-Transit [%s] found\n", csPstRitTxnId));
													iFoundPstRit = PD_TRUE;
													hTmpTxnId = (hash_t*) malloc (sizeof(hash_t));
													hash_init(hTmpTxnId, 0);

													PutField_CString(hTmpTxnId, "update_txn_id", csPstRitTxnId);
													RecordSet_Add(rUpdateTxnId, hTmpTxnId);
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

	if (iRet == PD_OK && iFoundPstRit) {
		hash_destroy(hTxn);
		hash_init(hTxn, 0);

		// update rsp delivery out txn

		PutField_CString(hTxn, "txn_seq", csDloTxnId);
		PutField_CString(hTxn, "sub_status", PD_MANUAL_DELIVERED);
		PutField_CString(hTxn, "update_user", csUpdateUser);

DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnIdForUpdateNoWait()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnIdForUpdateNoWait");
		iTmpRet = ((unsigned long)((*DBObjPtr)(csDloTxnId)));
		if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:Update()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
			iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn)));
			if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:Update() failed\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:Update() failed\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}

		// update psp settlement / rsp in-transit txn

		if (iRet == PD_OK) {
			hUpdateTxnId = RecordSet_GetFirst(rUpdateTxnId);
			while (hUpdateTxnId) {
				GetField_CString(hUpdateTxnId, "update_txn_id", &csPstRitTxnId);
				PutField_CString(hTxn, "txn_seq", csPstRitTxnId);

DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnIdForUpdateNoWait(%s)\n", csPstRitTxnId));
				DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnIdForUpdateNoWait");
				iTmpRet = ((unsigned long)((*DBObjPtr)(csPstRitTxnId)));
				if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:GetTxnIdForUpdateNoWait() Transaction locked by others!!\n");
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext, "internal_error", iRet);
					break;
				}

				if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:Update(%s)\n", csPstRitTxnId));
					DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
					iTmpRet = ((unsigned long)((*DBObjPtr)(hTxn)));
					if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:Update() failed\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: DBTransaction:Update() failed\n");
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
						break;
					}
				}

				hUpdateTxnId = RecordSet_GetNext(rUpdateTxnId);
			}
		}
	} else {
DEBUGLOG(("Authorize:: approved PSP Settlement / RSP In-Transit not found\n"));
ERRLOG("TxnMinByUsRMD:Authorize:: approved PSP Settlement / RSP In-Transit not found\n");
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
	RecordSet_Destroy(rUpdateTxnId);
	FREE_ME(rUpdateTxnId);

DEBUGLOG(("TxnMinByUsRMD Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

