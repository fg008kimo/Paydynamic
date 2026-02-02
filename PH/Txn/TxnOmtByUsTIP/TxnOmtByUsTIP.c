/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/12              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsTIP.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);


int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnOmtByUsTIP(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	csTag[PD_TMP_BUF_LEN+1];

	char	*csBankCode = NULL;
	char	*csBankAcctNum = NULL;
	char	*csOldProviderId = NULL;
	char	*csNewProviderId = NULL;
	char	*csStatusType = NULL;
	char	*csUser;

	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hOLBankAccts = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLBankAccts,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: bank_acct_num
	if (GetField_CString(hRequest,"bank_acct_num",&csBankAcctNum)) {
DEBUGLOG(("Authorize() bank_acct_num = [%s]\n",csBankAcctNum));
	} else {
		iRet = INT_BANK_ACCT_NUM;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_acct_num NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTIP:: Authorize() bank_acct_num NOT FOUND!!!\n");
	}

//API: bank_code
	if (GetField_CString(hRequest,"int_bank_code",&csBankCode)) {
DEBUGLOG(("Authorize() bank_code = [%s]\n",csBankCode));
	} else {
		iRet = INT_BANK_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_code NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTIP:: Authorize() bank_code NOT FOUND!!!\n");
	}

//API: new_provider_id
	if (GetField_CString(hRequest,"new_provider_id",&csNewProviderId)) {
DEBUGLOG(("Authorize() new_provider_id = [%s]\n",csNewProviderId));
	} else {
		iRet = INT_BANK_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_code NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTIP:: Authorize() bank_code NOT FOUND!!!\n");
	}

//API: user
	if (GetField_CString(hRequest, "add_user", &csUser)) {
		PutField_CString(hContext,"create_user",csUser);
		PutField_CString(hContext,"update_user",csUser);
			
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
	} else {
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() user NOT FOUND!!!\n");
	}


//Get Next Log BatchID Sequence
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog","GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (*DBObjPtr)());
DEBUGLOG(("Authorize() LogBatchId = [%s]\n",csLogBatchId));

		PutField_CString(hITTLog,"batch_id",csLogBatchId);
		PutField_CString(hITTLog,"api_code",PD_ITT_API_UDP_BANK_AC_PROV);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}



//Check Status
	if (iRet == PD_OK) {
		hash_init(hOLBankAccts,0);
DEBUGLOG(("CALL DBOLBankAccts:GetBankAccts\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts","GetBankAccts");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hOLBankAccts);

		if (iDtlRet == PD_OK) {

			if (GetField_CString(hOLBankAccts,"status_type",&csStatusType)) {
				if (strcmp(csStatusType,PD_BANK_ACCT_STATUS_NEW) != 0 && strcmp(csStatusType,PD_BANK_ACCT_STATUS_ACTIVE) != 0) {
DEBUGLOG(("  ERROR! status_type = [%s], only support new or active(%s/%s)\n",csStatusType,PD_BANK_ACCT_STATUS_NEW,PD_BANK_ACCT_STATUS_ACTIVE));
					iRet = INT_ITT_BANK_ACCT_STATUS_NOT_SUPPORT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() status_type not support!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() status_type not support!!!\n");
				}
			}

			if (GetField_CString(hOLBankAccts,"init_provider_id",&csOldProviderId)) {
DEBUGLOG(("  init_provider_id = [%s]\n",csOldProviderId));
			}

		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call DBOLBankAccts:GetBankAccts FAILED!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() Call DBOLBankAccts:GetBankAccts FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLBankAcctId:GetDtlByBankAcct
		hash_t* hTmp = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTmp,0);

		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId","GetDtlByBankAcct");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hTmp);

		if (iDtlRet == PD_OK) {
			iRet = INT_ITT_BAID_LINKED;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() OLBankAcctId found for BAID, BREAK!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() OLBankAcctId found for BAID, BREAK!!!\n");
		}

		hash_destroy(hTmp);
		FREE_ME(hTmp);
	}


	if (iRet == PD_OK) {
//Call DBOLStatement:GetCountByBankAcct
		DBObjPtr = CreateObj(DBPtr, "DBOLStatement","GetCountByBankAcct");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum);

		if (iDtlRet != 0) {
			iRet = INT_ITT_BANK_STATEMENT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Bank Statement found for BAID, BREAK!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() Bank Statement found for BAID, BREAK!!!\n");
		}
	}



	if (iRet == PD_OK) {
		hash_destroy(hOLBankAccts);
		hash_init(hOLBankAccts,0);


DEBUGLOG(("START Update:: Call DBOLBankAcctId:Update\n"));
		PutField_CString(hOLBankAccts,"bank_code",csBankCode);
DEBUGLOG(("  bank_code = [%s]\n",csBankCode));
		PutField_CString(hOLBankAccts,"new_acct_num",csBankAcctNum);
DEBUGLOG(("  new_acct_num = [%s]\n",csBankAcctNum));
		PutField_CString(hOLBankAccts,"init_provider_id",csNewProviderId);
DEBUGLOG(("  init_provider_id = [%s]\n",csNewProviderId));
		PutField_CString(hOLBankAccts,"update_user",csUser);
DEBUGLOG(("  update_user = [%s]\n",csUser));

		DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts","Update");
		iDtlRet = (unsigned long)(*DBObjPtr)(hOLBankAccts);

		sprintf(csTag,"%s||%s",csBankCode, csBankAcctNum);
		AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UDP_BANK_AC_PROV,PD_ITT_LOG_UPDATE,"OL_BANK_ACCTS",csTag,"OB_INIT_PROVIDER_ID",csNewProviderId,csOldProviderId);

		if (iDtlRet == PD_OK) {
DEBUGLOG(("  UPDATE success!\n"));
		} else {
			iRet = iDtlRet;
DEBUGLOG(("Authorize() Call DBOLBankAccts:Update FAILED!!!\n"));
ERRLOG("TxnOmtByUsTIP::Authorize() Call DBOLBankAccts:Update FAILED!!!\n");
		}
	}
//UPDATE FINISH



	if (iRet == PD_OK) {
DEBUGLOG(("UpdateTaskLogByBatch()\n"));
		PutField_Int(hITTLog,"ret_code",iRet);
		DBObjPtr = CreateObj(DBPtr,"DBIttTaskLog","UpdateRetCodeByBatch");
		iRet = (unsigned long)(*DBObjPtr)(hITTLog);
		if (iRet != PD_OK) {
DEBUGLOG(("  FAILURE!!! iRet = [%d]\n",iRet));
		} else {
DEBUGLOG(("  SUCCESS!!!\n"));
		}
	}


	hash_destroy(hOLBankAccts);
	FREE_ME(hOLBankAccts);

	hash_destroy(hITTLog);
	FREE_ME(hITTLog);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}


int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue)
{
	int iRet = PD_OK;

	PutField_Int(hITTLog,"batch_seq",iLogBatchSeq);
	PutField_CString(hITTLog,"task_action",csTaskAction);
	PutField_Char(hITTLog,"action_type",cActionType);
	PutField_CString(hITTLog,"object",csObject);
	PutField_Int(hITTLog,"ret_code",PD_ITT_INIT_RET_CODE);

	RemoveField_CString(hITTLog,"key");
	RemoveField_CString(hITTLog,"field");
	RemoveField_CString(hITTLog,"value");
	RemoveField_CString(hITTLog,"old_value");

	if (cActionType == PD_ITT_LOG_INSERT) {
		PutField_CString(hITTLog,"field",csField);
		PutField_CString(hITTLog,"value",csValue);
	} 

	if (cActionType == PD_ITT_LOG_UPDATE) {
		PutField_CString(hITTLog,"key",csKey);
		PutField_CString(hITTLog,"field",csField);
		PutField_CString(hITTLog,"value",csValue);
		if (csOldValue != NULL) {
			PutField_CString(hITTLog,"old_value",csOldValue);
		}
	}

	if (cActionType == PD_ITT_LOG_DELETE) {
		PutField_CString(hITTLog,"key",csKey);
	} 

	if (cActionType == PD_ITT_LOG_FUNCTION) {
		PutField_CString(hITTLog,"key",csKey);
	}

DEBUGLOG(("AddTaskLog()\n"));
	DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog", "Add");
	iRet = (unsigned long)(*DBObjPtr)(hITTLog);
	if (iRet != PD_OK) {
DEBUGLOG(("  FAILURE!!! iRet = [%d]\n",iRet));
	} else {
DEBUGLOG(("  SUCCESS!!!\n"));
	}


	return iRet;
}
