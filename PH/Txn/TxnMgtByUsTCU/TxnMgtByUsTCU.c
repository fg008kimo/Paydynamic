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
#include "TxnMgtByUsTCU.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);


int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnMgtByUsTCU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csTmp;
	char	csTag[PD_TMP_BUF_LEN+1];
	int	iTmp;

	char	*csServiceCode = NULL;
	char	*csMerchantId = NULL;
	char	*csCountry = NULL;
	char	*csURL = NULL;
	char	*csUser;
	int	iDisabled = 0;
	int	iActiveCnt = 0;
	int	iSameURL;

	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hServiceConsumerURL = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hServiceConsumerURL,0);

	recordset_t *rsServiceConsumerURL = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsServiceConsumerURL,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: service_code
	if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
		PutField_CString(hContext,"service_code",csServiceCode);
DEBUGLOG(("Authorize() service_code = [%s]\n",csServiceCode));
	} else {
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() service_code NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() service_code NOT FOUND!!!\n");
	}

//API: merchant_id
//	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
	if (GetField_CString(hRequest,"merch_id",&csMerchantId)) {
		PutField_CString(hContext,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize() merchant_id = [%s]\n",csMerchantId));
	} else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() merchant_id NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() merchant_id NOT FOUND!!!\n");
	}

//API: country
	if (GetField_CString(hRequest,"txn_country",&csCountry)) {
		PutField_CString(hContext,"country",csCountry);
		PutField_CString(hContext,"txn_country",csCountry);
DEBUGLOG(("Authorize() country = [%s]\n",csCountry));
	} else {
		iRet = INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() country NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() country NOT FOUND!!!\n");
	}

//API: disabled
	if (GetField_CString(hRequest,"disabled",&csTmp)) {
		iDisabled = atoi(csTmp);
		PutField_Int(hContext,"disabled",iDisabled);
DEBUGLOG(("Authorize() disabled = [%d]\n",iDisabled));
	} else {
		iRet = INT_DISABLED_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() disabled NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() disabled NOT FOUND!!!\n");
	}

//API: url
	if (GetField_CString(hRequest,"url",&csURL)) {
		PutField_CString(hContext,"url",csURL);
DEBUGLOG(("Authorize() url = [%s]\n",csURL));
	} else {
		iRet = INT_ITT_URL_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() url NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() url NOT FOUND!!!\n");
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
ERRLOG("TxnMgtByUsTCU::Authorize() user NOT FOUND!!!\n");
	}


//Get Next Log BatchID Sequence
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog","GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (*DBObjPtr)());
DEBUGLOG(("Authorize() LogBatchId = [%s]\n",csLogBatchId));

		PutField_CString(hITTLog,"batch_id",csLogBatchId);
		PutField_CString(hITTLog,"api_code",PD_ITT_API_CONSUMER_URL);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}



/*
 * If action = DisableURL, Check For Active URL count (not include passing-in URL)
 */
	if (iRet == PD_OK && iDisabled == PD_TRUE) {
		hash_t *hTmp = NULL;
		recordset_init(rsServiceConsumerURL,0);

DEBUGLOG(("CALL DBServiceConsumerURL:GetURLByMerchId\n"));
		DBObjPtr = CreateObj(DBPtr, "DBServiceConsumerUrl","GetURLByMerchId");
		iRet = (unsigned long)(*DBObjPtr)(hContext,rsServiceConsumerURL);
//		iRet = (unsigned long)(*DBObjPtr)(hRequest,rsServiceConsumerURL);

		if (iRet == PD_OK) {
			hTmp = RecordSet_GetFirst(rsServiceConsumerURL);
			while (hTmp && iRet==PD_OK) {
				if (GetField_CString(hTmp,"url",&csTmp)) {
					if (!strcmp(csTmp,csURL)) {
						iSameURL = PD_TRUE;
					} else iSameURL = PD_FALSE;
				}

				if (GetField_Int(hTmp,"disabled",&iTmp)) {
					if (!iSameURL && iTmp == 0) {
						iActiveCnt++;
					}
				}

				hTmp = RecordSet_GetNext(rsServiceConsumerURL);
			}
		} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() Call DBServiceConsumerURL:GetURLByMerchId FAILED!!!\n"));
ERRLOG("TxnMgtByUsTCU:: Authorize() Call DBServiceConsumerURL:GetURLByMerchId FAILED!!!\n");
		}
	}

	if (iRet == PD_OK && iActiveCnt == 0 && iDisabled == PD_TRUE) {
		iRet = INT_ITT_NEED_AT_LEAST_ONE_ACTIVE_URL;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() At least need 1 active URL other than [%s]!!!\n",csURL));
ERRLOG("TxnMgtByUsTCU::Authorize() At least need 1 active URL other than [%s]!!!\n",csURL);
	}



	if (iRet == PD_OK) {
DEBUGLOG(("CALL DBServiceConsumerURL:UpdateDisabled\n"));
		sprintf(csTag,"%s||%s||%s||%s",csServiceCode,csMerchantId,csCountry,csURL);

		char csTRUE[PD_TMP_BUF_LEN+1];
		char csFALSE[PD_TMP_BUF_LEN+1];
		sprintf(csTRUE,"%d",PD_TRUE);
		sprintf(csFALSE,"%d",PD_FALSE);
		
		if (iDisabled == PD_TRUE) {
			AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_DISABLE_URL,PD_ITT_LOG_UPDATE,"SERVICE_CONSUMER_URL",csTag,"CU_DISABLED",csTRUE,csFALSE);
		} else {
			AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_ENABLE_URL,PD_ITT_LOG_UPDATE,"SERVICE_CONSUMER_URL",csTag,"CU_DISABLED",csFALSE,csTRUE);
		}

		DBObjPtr = CreateObj(DBPtr, "DBServiceConsumerUrl","UpdateDisabled");
		iRet = (unsigned long)(*DBObjPtr)(hContext);

		if (iRet == PD_OK) {
DEBUGLOG(("  update SUCCESS!\n"));
		} else {
DEBUGLOG(("  ERROR!! update FAILED!!!\n"));	
ERRLOG("TxnMgtByUsTCU CALL DBServiceConsumerURL:UpdateDisabled FAILED!!!\n");
		}
	}



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


	recordset_destroy(rsServiceConsumerURL);
	FREE_ME(rsServiceConsumerURL);

	hash_destroy(hServiceConsumerURL);
	FREE_ME(hServiceConsumerURL);

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
