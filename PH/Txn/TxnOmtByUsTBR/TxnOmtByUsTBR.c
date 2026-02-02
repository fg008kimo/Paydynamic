/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/08              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsTBR.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);


int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnOmtByUsTBR(char cdebug)
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

	char	*csBAID;
	char	*csBankCode = NULL;
	char	*csBankAcctNum = NULL;
	char	*csCountry = strdup("");
	char	*csCurrency = NULL;
	char	*csUser;
	double	dTmp = 0.0;

	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hOLBankAcctId = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLBankAcctId,0);
	
	hash_t *hOLBankAccts = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLBankAccts,0);
	
	hash_t *hOLBAIDBal = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLBAIDBal,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: baid
	if (GetField_CString(hRequest,"baid",&csBAID)) {
DEBUGLOG(("Authorize() baid = [%s]\n",csBAID));
	} else {
		iRet = INT_BANK_AC_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() baid NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTBR:: Authorize() baid NOT FOUND!!!\n");
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
ERRLOG("TxnOmtByUsTBR::Authorize() user NOT FOUND!!!\n");
	}


//Get Next Log BatchID Sequence
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog","GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (*DBObjPtr)());
DEBUGLOG(("Authorize() LogBatchId = [%s]\n",csLogBatchId));

		PutField_CString(hITTLog,"batch_id",csLogBatchId);
		PutField_CString(hITTLog,"api_code",PD_ITT_API_BAID_REMOVAL);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}



	if (iRet == PD_OK) {
//Call DBOLBankAcctId:GetBankAcctIdDtl
		hash_init(hOLBankAcctId,0);
DEBUGLOG(("CALL DBOLBankAcctId:GetBankAcctIdDtl\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId","GetBankAcctIdDtl");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID, hOLBankAcctId);

		if (iDtlRet == PD_OK) {

			if (GetField_CString(hOLBankAcctId,"int_bank_code",&csBankCode)) {
DEBUGLOG(("  int_bank_code = [%s]\n",csBankCode));
			}

			if (GetField_CString(hOLBankAcctId,"bank_acct_num",&csBankAcctNum)) {
DEBUGLOG(("  bank_acct_num = [%s]\n",csBankAcctNum));
			}

		} else {
			iRet = INT_BANK_AC_ID_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call DBOLBankAcctId:GetBankAcctIdDtl FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBankAcctId:GetBankAcctIdDtl FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLBankAcctId:GetBankAcctIdCountry
DEBUGLOG(("CALL DBOLBankAcctId:GetBankAcctIdCountry\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId","GetBankAcctIdCountry");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID, csCountry);

		if (iDtlRet == PD_FOUND) {
DEBUGLOG(("  country = [%s]\n",csCountry));
		} else {
			iRet = INT_BAID_COUNTRY_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call DBOLBankAcctId:GetBankAcctIdCountry FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBankAcctId:GetBankAcctIdCountry FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLBankAccts:GetBankAccts
		hash_init(hOLBankAccts,0);
DEBUGLOG(("CALL DBOLBankAccts:GetBankAccts\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts","GetBankAccts");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum, hOLBankAccts);

		if (iDtlRet == PD_OK) {

			if (GetField_CString(hOLBankAccts,"acct_ccy",&csCurrency)) {
DEBUGLOG(("  acct_ccy = [%s]\n",csCurrency));
			}

		} else {
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call DBOLBankAccts:GetBankAccts FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBankAccts:GetBankAccts FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLTxnPspDetail:GetTxnCountByBankAcct
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail","GetTxnCountByBankAcct");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum);

		if (iDtlRet != 0) {
			iRet = INT_ITT_TXN_EXISTS_FOR_BANK_AC;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() OLTxnPspDetail found for BAID, BREAK!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() OLTxnPspDetail found for BAID, BREAK!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLStatement:GetCountByBankAcct
		DBObjPtr = CreateObj(DBPtr, "DBOLStatement","GetCountByBankAcct");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum);

		if (iDtlRet != 0) {
			iRet = INT_ITT_BANK_STATEMENT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Bank Statement found for BAID, BREAK!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Bank Statement found for BAID, BREAK!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLBAIDTxn:GetCountByBAID
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn","GetCountByBAID");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID);

		if (iDtlRet != 0) {
			iRet = INT_ITT_BAID_TXN_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() OLBAIDTxn found for BAID, BREAK!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() OLBAIDTxn found for BAID, BREAK!!!\n");
		}
	}



	if (iRet == PD_OK) {
//Call DBOLResourceLock:GetBankAcctForUpdate
		DBObjPtr = CreateObj(DBPtr,"DBOLResourceLock","GetBankAcctForUpdate");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum);

		if (iDtlRet != PD_OK) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call OLResourceLock:GetBankAcctForUpdate FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call OLResourceLock:GetBankAcctForUpdate FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
//Call DBOLBALDBal:GetBalanceForUpdate
		hash_init(hOLBAIDBal,0);

		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDBal","GetBalanceForUpdate");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID,csCountry,csCurrency,hOLBAIDBal);

		if (iDtlRet == PD_OK) {

			if (GetField_Double(hOLBAIDBal,"balance",&dTmp)) {
				if (dTmp != 0) {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() balance = [%f], BREAK!\n",dTmp));
				}
			}

			if (GetField_Double(hOLBAIDBal,"prepaid",&dTmp)) {
				if (dTmp != 0) {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() prepaid = [%f], BREAK!\n",dTmp));
				}
			}

			if (GetField_Double(hOLBAIDBal,"in_transit",&dTmp)) {
				if (dTmp != 0) {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() in_transit = [%f], BREAK!\n",dTmp));
				}
			}

			if (GetField_Double(hOLBAIDBal,"total_hold",&dTmp)) {
				if (dTmp != 0) {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() total_hold = [%f], BREAK!\n",dTmp));
				}
			}

		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Call DBOLBALDBal:GetBalance FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBALDBal:GetBalance FAILED!!!\n");
		}
	}



//DELETE START
	if (iRet == PD_OK) {
DEBUGLOG(("START delete:: Call DBOLBAIDBal:DeleteBaidBal\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBAIDBal","DeleteBaidBal");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID,csCountry,csCurrency);

		sprintf(csTag,"%s||%s||%s",csBAID,csCountry,csCurrency);
		AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_REMOVE_BAID,PD_ITT_LOG_DELETE,"OL_BAID_BAL",csTag,"","","");

		if (iDtlRet == PD_OK) {
DEBUGLOG(("  success!\n"));
		} else {
			iRet = iDtlRet;
DEBUGLOG(("Authorize() Call DBOLBALDBal:DeleteBaidBal FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBALDBal:DeleteBaidBal FAILED!!!\n");
		}
	}


	if (iRet == PD_OK) {
DEBUGLOG(("START delete:: Call DBOLBankAcctId:Delete\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId","Delete");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBAID);

		sprintf(csTag,"%s",csBAID);
		AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_REMOVE_BAID,PD_ITT_LOG_DELETE,"OL_BANK_ACCT_ID",csTag,"","","");

		if (iDtlRet == PD_OK) {
DEBUGLOG(("  success!\n"));
		} else {
			iRet = iDtlRet;
DEBUGLOG(("Authorize() Call DBOLBankAcctId:Delete FAILED!!!\n"));
ERRLOG("TxnOmtByUsTBR::Authorize() Call DBOLBankAcctId:Delete FAILED!!!\n");
		}
	}
//DELETE FINISH



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



	FREE_ME(csCountry);

	hash_destroy(hOLBAIDBal);
	FREE_ME(hOLBAIDBal);

	hash_destroy(hOLBankAccts);
	FREE_ME(hOLBankAccts);

	hash_destroy(hOLBankAcctId);
	FREE_ME(hOLBankAcctId);

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
