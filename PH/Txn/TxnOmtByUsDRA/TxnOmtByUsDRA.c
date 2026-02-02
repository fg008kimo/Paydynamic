/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/07              Stan Poon
Table locking GetDepositHeaderForUpdate		   2014/03/13		   Stan Poon
Rescue Boat Logging                                2015/07/03              Virginia Yun
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsDRA.h"
#include "myrecordset.h"
#include "math.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnOmtByUsDRA(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csFileId = NULL, *csUser = NULL;
	char	cAction, cOrgParty, cParty, cOrgStatus;

	char	*csMerchantId;

	char	*csTmp = NULL;

	hash_t *hRec;

	PutField_CString(hContext,"input_channel",PD_DEPOSIT_REQUEST_FILE);

/* Action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize() action = [%c]\n",cAction));
		if (cAction == PD_DEPOSIT_FILE_CANCEL) {
			PutField_Char(hContext,"status",PD_DEPOSIT_FILE_DECLINED);
		} else if (cAction == PD_DEPOSIT_FILE_APPROVE) {
			PutField_Char(hContext,"status",PD_DEPOSIT_FILE_APPROVED);
		}

		if (cAction != PD_DEPOSIT_FILE_CANCEL && cAction != PD_DEPOSIT_FILE_APPROVE) {
			iRet = INT_ACTION_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() action [%c] not accepted!!\n", cAction));
ERRLOG("TxnOmtByUsDRA::Authorize() action not found!!\n");
		}
	} else {
                iRet = INT_ACTION_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() action not found!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() action not found!!\n");
	}
/* batch_id */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "batch_id", &csFileId)) {
			PutField_CString(hContext,"file_id",csFileId);
DEBUGLOG(("Authorize() file_id = [%s]\n", csFileId));
		} else {
			iRet = INT_FILE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() batch_id is missing!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() batch_id is missing!!!\n");
		}
	}
/* Party */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "party", &csTmp)) {
			cParty = csTmp[0];
			PutField_Char(hContext,"party",cParty);
DEBUGLOG(("Authorize() party [%c]\n", cParty));
		} else {
			iRet = INT_PARTY_TYPE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() party is missing!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() party is missing!!!\n");
		}
	}
/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
			PutField_CString(hContext,"create_user",csUser);
			PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() user is missing!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() user is missing!!!\n");
		}
	}
/* ip_addr */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
			PutField_CString(hContext,"ip_addr",csTmp);
DEBUGLOG(("Authorize() ip_addr = [%s]\n", csTmp));
		}
	}



/* get Deposit Header */
	if (iRet == PD_OK) {
		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec,0);

DEBUGLOG(("Authorize() call DBOLDepositRequest::GetDepositHeaderForUpdate()\n"));
		BOObjPtr = CreateObj(BOPtr, "DBOLDepositRequest", "GetDepositHeaderForUpdate");
		iRet = (unsigned long)(*BOObjPtr)(csFileId, hRec);
		if (iRet != PD_OK) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() call DBOLDepositRequest::GetDepositHeaderForUpdate() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() call DBOLDepositRequest::GetDepositHeaderForUpdate() FAILURE!!!\n");
		} else {
			if (GetField_CString(hRec,"filename",&csTmp)) {
				PutField_CString(hContext,"filename",csTmp);
DEBUGLOG(("Authorize() filename = [%s]\n",csTmp));
			}

			if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
				PutField_CString(hContext,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize() merchant_id = [%s]\n",csMerchantId));
			}
			if (GetField_Char(hRec,"party",&cOrgParty)) {
DEBUGLOG(("Authorize() party = [%c]\n",cOrgParty));
			}
			if (GetField_Char(hRec,"status",&cOrgStatus)) {
DEBUGLOG(("Authorize() status = [%c]\n",cOrgStatus));
			}

			if (cOrgParty != cParty) {
				iRet = INT_INVALID_PARTY_TYPE;
				PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() org_party FAILURE!!! [%c]\n",cOrgParty));
ERRLOG("TxnOmtByUsDRA::Authorize() org_party FAILURE!!! [%c]\n",cOrgParty);
			}
			if (cOrgStatus != PD_DEPOSIT_FILE_PENDING) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() org status FAILURE!!! [%c]\n",cOrgStatus));
ERRLOG("TxnOmtByUsDRA::Authorize() org status FAILURE!!! [%c]\n",cOrgStatus);
			}
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}



/* Confirm Deposit Request */
	if (iRet == PD_OK && cAction == PD_DEPOSIT_FILE_APPROVE) {
DEBUGLOG(("Authorize() call BOOLDepositReq::ConfirmDepositReq()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLDepositReq", "ConfirmDepositReq");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call BOOLDepositReq::ConfirmDepositReq() SUCCESS\n"));
		} else {
DEBUGLOG(("Authorize() call BOOLDepositReq::ConfirmDepositReq() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() DBOLDepositRequest::ConfirmDepositReq() FAILURE!!!\n"); 
		}
	}



/* Update Deposit Header */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLDepositRequest::UpdateHeader()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLDepositRequest","UpdateHeader");
		if ((*DBObjPtr)(hContext) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLDepositRequest::UpdateHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsDRA::Authorize() DBOLDepositRequest::UpdateHeader() FAILURE!!!\n"); 
		}
	}

/* Rescue Boat Logging */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() Rescue Boat Result %s,%s,%c,%c\n", csFileId, csMerchantId, cAction, cParty));
	}


DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

