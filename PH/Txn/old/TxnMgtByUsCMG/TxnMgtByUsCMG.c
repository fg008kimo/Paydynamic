/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/21              Stan Poon
Exclude Update Magic Num                           2013/09/24              Stan Poon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCMG.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsCMG(char    cdebug)
{
	cDebug = cdebug;
}

int	Authorize(hash_t* hContext,
			const hash_t* hRequest,
			hash_t* hResponse)
{

	int	iRet = PD_OK;
	char	*csTmp;
	char	*csClientId;
	char	*csCustId;
	char	csNewMagicNum[PD_MAGIC_NUM_LEN + 1];
	char	csMagicNum[PD_MAGIC_NUM_LEN + 1];
	char	cAction;

DEBUGLOG(("TxnMgtByUsCMG::Authorize\n"));

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));
		if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE && cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::action [%d] not support!!\n", cAction));
ERRLOG("TxnMgtByUsCMG::Authorize::action not support!!\n");
			iRet=INT_ACTION_NOT_FOUND;
		}
	} else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::action not found!!\n");
		iRet=INT_ACTION_NOT_FOUND;
	}


/* client_id */
	if (GetField_CString(hRequest, "client_id", &csClientId)) {
DEBUGLOG(("Authorize::client_id = [%s]\n", csClientId));
		PutField_CString(hContext, "client_id", csClientId);
	} else {
DEBUGLOG(("Authorize::client_id not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::client_id not found\n");
		iRet = INT_FORMAT_ERR;
	}

/* magic_num */
	if (GetField_CString(hRequest, "magic_num", &csTmp)) {
		snprintf(csNewMagicNum,sizeof(csNewMagicNum)-1,"%s",csTmp);
DEBUGLOG(("Authorize::magic_num = [%s]\n", csNewMagicNum));
		PutField_CString(hContext, "magic_num", csNewMagicNum);
	} else if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::magic_num not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::magic_num not found\n");
		iRet = INT_FORMAT_ERR;
	} else {
		strcpy(csNewMagicNum,"");
	}

/* magic_word */
	if (GetField_CString(hRequest, "magic_word", &csTmp)) {
DEBUGLOG(("Authorize::magic_word = [%s]\n", csTmp));
		PutField_CString(hContext, "magic_word", csTmp);
	} else if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::magic_word not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::magic_word not found\n");
		iRet = INT_FORMAT_ERR;
	}

/* cust_id */
	if (GetField_CString(hRequest, "cust_id", &csCustId)) {
DEBUGLOG(("Authorize::cust_id = [%s]\n", csCustId));
		PutField_CString(hContext, "customer_id", csCustId);
	} else {
DEBUGLOG(("Authorize::cust_id not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::cust_id not found\n");
		iRet = INT_FORMAT_ERR;
	}

/* disabled */
	if (GetField_CString(hRequest, "disabled", &csTmp)) {
DEBUGLOG(("Authorize::disabled = [%s]\n", csTmp));
		PutField_Int(hContext, "disabled", atoi(csTmp));
	} else if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::disabled not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::disabled not found\n");
		iRet = INT_FORMAT_ERR;
	}

/* add_user */
	if(GetField_CString(hRequest,"add_user",&csTmp)) {
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
		PutField_CString(hContext,"create_user",csTmp);
		PutField_CString(hContext, "update_user", csTmp);
	} else {
DEBUGLOG(("Authorize::add_user not found\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::add_user not found\n");
		iRet = INT_FORMAT_ERR;
	}


	if(iRet==PD_OK && cAction==PD_ACTION_ADD){
DEBUGLOG(("Authorize::Call DBClientMagic:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBClientMagic","Add");
		if((unsigned long)((*DBObjPtr)(hContext) != PD_OK)){
DEBUGLOG(("Authorize::DBClientMagic:Add Failed\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::DBClientMagic:Add Failed\n");
			iRet = INT_ERR;
		} else {
DEBUGLOG(("Authorize::DBClientMagic:Add Succ\n"));
		}
	}
	else if(iRet==PD_OK && cAction==PD_ACTION_UPDATE){
DEBUGLOG(("Authorize::Call DBClientMagic:GetMagicNumById\n"));
		DBObjPtr = CreateObj(DBPtr,"DBClientMagic","GetMagicNumById");
		if((unsigned long)((*DBObjPtr)(csClientId, csCustId, csMagicNum) != PD_OK)){
DEBUGLOG(("Authorize::DBClientMagic:GetMagicNumById Failed\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::DBClientMagic:GetMagicNumById Failed\n");
			iRet = INT_ERR;
		} else {
			if (!strcmp(csNewMagicNum,csMagicNum) || !strcmp(csNewMagicNum,"")) {
DEBUGLOG(("Authorize::DBClientMagic:GetMagicNumById Succ\n"));
				DBObjPtr = CreateObj(DBPtr,"DBClientMagic","Update");
				if((unsigned long)((*DBObjPtr)(hContext) != PD_OK)){
DEBUGLOG(("Authorize::DBClientMagic:Update Failed\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::DBClientMagic:Update Failed\n");
					iRet = INT_ERR;
				} else {
DEBUGLOG(("Authorize::DBClientMagic:Update Succ\n"));
				}
			} else {
				iRet = INT_INVALID_MAGIC_NUM;
DEBUGLOG(("Authorize::DBClientMagic:GetMagicNumById Magic Num Cannot be updated!!!\n"));
			}
		}
	}
	else if(iRet==PD_OK && cAction==PD_ACTION_DELETE){
DEBUGLOG(("Authorize::Call DBClientMagic:Delete\n"));
		DBObjPtr = CreateObj(DBPtr,"DBClientMagic","Delete");
		if((unsigned long)((*DBObjPtr)(hContext) != PD_OK)){
DEBUGLOG(("Authorize::DBClientMagic:Delete Failed\n"));
ERRLOG("TxnMgtByUsCMG::Authorize::DBClientMagic:Delete Failed\n");
			iRet = INT_ERR;
		} else {
DEBUGLOG(("Authorize::DBClientMagic:Delete Succ\n"));
		}
	}

DEBUGLOG(("TxnMgtByUsCMG Normal Exit() iRet = [%d]\n",iRet));
	if (iRet != PD_OK) {
		PutField_Int(hContext,"internal_error",iRet);
	}

	return iRet;
}
