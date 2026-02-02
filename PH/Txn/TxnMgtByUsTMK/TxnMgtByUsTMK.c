/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/01              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTMK.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);

int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnMgtByUsTMK(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	*csTmp;
	char	csTag[PD_TMP_BUF_LEN+1];

	char	*csMerchantId;
	char	*csOldMerchKeyValue;
	char	*csOldEffectDate;
	char	*csUser;
	char	csEffectDate[PD_DATETIME_LEN + 1];;
	char	cBusinessType;

	char	csDateTime[PD_DATETIME_LEN + 1];
	char	csTmpKey[PD_ITT_MD5_KEN_LEN+1];
	
	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hMerchKeys = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hMerchKeys,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//Get Values from API
	if (iRet == PD_OK) {

//API: merchant_id
		if (GetField_CString(hRequest, "merchant_id", &csMerchantId)) {
DEBUGLOG(("Authorize() merchant_id = [%s]\n", csMerchantId));
		} else {
			iRet = INT_MERCHANT_ID_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsTMK:: Authorize:: merchant_id not found!!\n");
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
ERRLOG("TxnMgtByUsTMK::Authorize() user NOT FOUND!!!\n");
		}

	}

//Call DBMerchKeys:CheckAvailableForGenSTK
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBMerchKeys", "CheckAvailableForGenSTK");
		iRet = (unsigned long)(*DBObjPtr)(csMerchantId);

		if (iRet != PD_OK) {
			iRet = INT_ITT_NOT_NEW_MERCHANT;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() merchant not available for update key!!!\n"));
ERRLOG("TxnMgtByUsTMK::Authorize() merchant not available for update key!!!\n");
		}
	}


//Get PHDate
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "FindCode");
		if ((unsigned long)(*DBObjPtr)("CTPHDATE", csEffectDate) == FOUND) {
printf("Current Processor Hub Date = [%s]\n", csEffectDate);
		} else {
			iRet = INT_ERR;
printf("Current Processor Hub Date Not Found\n");
		}
	}


//Get Next Log BatchID Sequence
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog","GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (*DBObjPtr)());
DEBUGLOG(("Authorize() LogBatchId = [%s]\n",csLogBatchId));

		PutField_CString(hITTLog,"batch_id",csLogBatchId);
		PutField_CString(hITTLog,"api_code",PD_ITT_API_GEN_MERCH_KEY);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}



/**********************
 * 1) Update PTK Key  *
 * ********************/

	if (iRet == PD_OK) {

DEBUGLOG(("Authorize() - Update PTK Key\n"))

		hash_t *hTmpMerchKeys;
		recordset_t *rsTmpMerchKeys = (recordset_t *) malloc (sizeof(recordset_t));
		recordset_init(rsTmpMerchKeys,0);

		DBObjPtr = CreateObj(DBPtr, "DBMerchKeys","GetMerchantKey");
		iDtlRet = (unsigned long)(*DBObjPtr)(csMerchantId,PD_PTK_KEY_NAME,rsTmpMerchKeys);
DEBUGLOG(("Call DBMerchKeys:GetMerchantKey\n"));

		if (iDtlRet == PD_OK) {
			hTmpMerchKeys = RecordSet_GetFirst(rsTmpMerchKeys);
			while (hTmpMerchKeys && iDtlRet == PD_OK) {

				if (GetField_CString(hTmpMerchKeys,"key_value",&csOldMerchKeyValue)) {
DEBUGLOG(("Old MD5 key_value = [%s]\n",csOldMerchKeyValue));
				} else {
					iDtlRet = INT_ERR;
DEBUGLOG(("Call DBMerchKeys:GetMerchantKey() key_value NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTMK: Call DBMerchKeys:GetMerchantKey() key_value NOT FOUND!!!\n");
	                        }

				if (GetField_CString(hTmpMerchKeys,"effect_date",&csOldEffectDate)) {
DEBUGLOG(("Old effect_date = [%s]\n",csOldEffectDate));
				} else {
					iDtlRet = INT_ERR;
DEBUGLOG(("Call DBMerchKeys:GetMerchantKey() effect_date NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTMK: Call DBMerchKeys:GetMerchantKey() effect_date NOT FOUND!!!\n");
	                        }

				//Go To next PSP Acct Type
				hTmpMerchKeys = RecordSet_GetNext(rsTmpMerchKeys);

			}
		} else {
DEBUGLOG(("Call DBMerchKeys:GetMerchantKey() FAILED!!!\n"));
ERRLOG("TxnMgtByUsTMK: Call DBMerchKeys:GetMerchantKey() FAILED!!!\n");
		}

		RecordSet_Destroy(rsTmpMerchKeys);
		FREE_ME(rsTmpMerchKeys);

	}
	

	if (iDtlRet != PD_OK) {
		iRet = iDtlRet;
	}


	if (iRet == PD_OK) {	

		memset(csTmpKey, 0, sizeof(csTmpKey));
		strcpy(csTmpKey, random_gen(PD_ITT_MD5_KEN_LEN));
		csTmpKey[PD_ITT_MD5_KEN_LEN]='\0';
DEBUGLOG(("New MD5 key_value = [%s]\n", csTmpKey));


//merchant_id
		PutField_CString(hMerchKeys,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize() - Update:: merchant_id = [%s]\n",csMerchantId));

//key_value
		PutField_CString(hMerchKeys,"key_value",(char*)csTmpKey);
DEBUGLOG(("Authorize() - Update:: key_value = [%s]\n",(char*)csTmpKey));

//key
		PutField_CString(hMerchKeys,"key",PD_PTK_KEY_NAME);
DEBUGLOG(("Authorize() - Update:: key = [%s]\n",PD_PTK_KEY_NAME));

//udpate_user
		PutField_CString(hMerchKeys,"update_user",csUser);
DEBUGLOG(("Authorize() - Update:: update_user = [%s]\n",csUser));

//effect_date
		PutField_CString(hMerchKeys,"effect_date",(char*)csEffectDate);
DEBUGLOG(("Authorize() - Update:: effect_date = [%s]\n",(char*)csEffectDate));


		sprintf(csTag,"%s||%s",csMerchantId,PD_PTK_KEY_NAME);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_UPDATE_MD5_KEY,PD_ITT_LOG_UPDATE,"MERCH_KEYS",csTag,"key_value",(char*)csTmpKey,csOldMerchKeyValue);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_UPDATE_MD5_KEY,PD_ITT_LOG_UPDATE,"MERCH_KEYS",csTag,"effect_date",(char*)csEffectDate,csOldEffectDate);


//Call DBMerchKeys::Update
DEBUGLOG(("Call DBMerchKeys:UpdateKey\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchKeys","UpdateKey");
		iDtlRet = (unsigned long)(*DBObjPtr)(hMerchKeys);

		if (iDtlRet == PD_OK) {
DEBUGLOG(("  SUCCESS\n"));
		} else {
			iRet = iDtlRet;
DEBUGLOG(("Call DBMerchKeys:UpdateKey FAILED!!!\n"));
ERRLOG("TxnMgtByUsTMK Call DBMerchKeys:UpdateKey FAILED!!!\n");
		}

	}

	iLogBatchSeq++;

//End Update PTK Key



/**********************
 * 2) create STK Key  *
 * ********************/

	if (iRet == PD_OK) {

DEBUGLOG(("Authorize() - Create STK Key\n"))

		SHA1Context sha;
		int i;

		strcpy(csDateTime,getdatetime());
		csDateTime[PD_DATETIME_LEN]='\0';

		memset(csTmpKey, 0, sizeof(csTmpKey));

		SHA1Reset(&sha);
		SHA1Input(&sha, (const unsigned char *)csDateTime, strlen(csDateTime));
		if (SHA1Result(&sha)) {
			for(i = 0; i < 4 ; i++) {
				sprintf(&csTmpKey[i*8], "%08X", sha.Message_Digest[i]);
			}
			csTmpKey[PD_SHA_KEY_LEN]='\0';
DEBUGLOG(("Auto generate: SHA1 [%s]\n", csTmpKey));
		}


//merchant_id
		PutField_CString(hMerchKeys,"merchant_id",csMerchantId);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_SHA1_KEY,PD_ITT_LOG_INSERT,"MERCH_KEYS","","merchant_id",csMerchantId,"");
DEBUGLOG(("Authorize() - Insert:: merchant_id = [%s]\n",csMerchantId));

//key_value
		PutField_CString(hMerchKeys,"key_value",(char*)csTmpKey);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_SHA1_KEY,PD_ITT_LOG_INSERT,"MERCH_KEYS","","key_value",csTmpKey,"");
DEBUGLOG(("Authorize() - Insert:: key_value = [%s]\n",(char*)csTmpKey));

//key
		PutField_CString(hMerchKeys,"key",PD_SHA1_KEY_NAME);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_SHA1_KEY,PD_ITT_LOG_INSERT,"MERCH_KEYS","","key",PD_SHA1_KEY_NAME,"");
DEBUGLOG(("Authorize() - Insert:: key = [%s]\n",PD_SHA1_KEY_NAME));

//create_user
		PutField_CString(hMerchKeys,"create_user",csUser);
DEBUGLOG(("Authorize() - Insert:: create_user = [%s]\n",csUser));

//effect_date
		PutField_CString(hMerchKeys,"effect_date",(char*)csEffectDate);
		AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_SHA1_KEY,PD_ITT_LOG_INSERT,"MERCH_KEYS","","effect_date",csEffectDate,"");
DEBUGLOG(("Authorize() - Insert:: effect_date = [%s]\n",(char*)csEffectDate));



//Call DBMerchKeys::Add
DEBUGLOG(("Call DBMerchKeys:Add\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchKeys","Add");
		iDtlRet = (unsigned long)(*DBObjPtr)(hMerchKeys);

		if (iDtlRet == PD_OK) {
DEBUGLOG(("  SUCCESS\n"));
		} else {
			iRet = iDtlRet;
DEBUGLOG(("Call DBMerchKeys:Add FAILED!!!\n"));
ERRLOG("TxnMgtByUsTMK Call DBMerchKeys:Add FAILED!!!\n");
		}

	}

	iLogBatchSeq++;

//End Create STK Key



//Get Merchant's Business Type
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"merchant_client_id",&csTmp)) {
			hash_t* hClients = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hClients,0);

			DBObjPtr = CreateObj(DBPtr,"DBClients","GetClients");
			iRet = (unsigned long)(*DBObjPtr)(csTmp,hClients);

			if (iRet == PD_OK) {
				if (GetField_Char(hClients,"business_type",&cBusinessType)) {
DEBUGLOG(("client_id [%s] :: business_type [%c]\n",csTmp,cBusinessType));
				} else {
					iRet = INT_ERR;
DEBUGLOG(("business_type not found!!!\n"));
ERRLOG("TxnMgtByUsTMK business_type not found!!!\n");
				}
			}

			hash_destroy(hClients);
			FREE_ME(hClients);
		} else {
			iRet = INT_ERR;
DEBUGLOG(("client_id not found!!!\n"));
ERRLOG("TxnMgtByUsTMK client_id not found!!!\n");
		}
	}


//Create check_hand_shake rule if new merchant = non-game & not live-test
	if (iRet == PD_OK) {

		if (cBusinessType == PD_BUSINESS_TYPE_NON_GAMING) {
DEBUGLOG(("Non-game & Non-Live-test Merchant, expected to add check_hand_shake_rule\n"));
DEBUGLOG(("Call DBRuleCheckHandShake\n"))
			hash_t* hCheckHandShake = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hCheckHandShake,0);

			DBObjPtr = CreateObj(DBPtr,"DBRuleCheckHandShake","Find");
			iRet = (unsigned long)(*DBObjPtr)(cBusinessType,hCheckHandShake);

			if (iRet == PD_OK) {
DEBUGLOG(("  Find!! Call DBCheckHandShake::Add\n"));

				int iTmp;

				PutField_CString(hCheckHandShake,"party_id",csMerchantId);
				AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","party_id",csMerchantId,"");
DEBUGLOG(("  Add party_id = [%s]\n",csMerchantId));

				if (GetField_Int(hCheckHandShake,"check_count",&iTmp)) {
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","check_count",csTag,"");
DEBUGLOG(("  Add check_count = [%d]\n",iTmp));
				}

				if (GetField_Int(hCheckHandShake,"max_handshake_count",&iTmp)) {
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","max_handshake_count",csTag,"");
DEBUGLOG(("  Add max_handshake_count = [%d]\n",iTmp));
				}

				if (GetField_Int(hCheckHandShake,"start_buffer_period",&iTmp)) {
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","start_buffer_period",csTag,"");
DEBUGLOG(("  Add start_buffer_period = [%d]\n",iTmp));
				}

				if (GetField_Int(hCheckHandShake,"min_total",&iTmp)) {
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","min_total",csTag,"");
DEBUGLOG(("  Add min_total = [%d]\n",iTmp));
				}

				if (GetField_Int(hCheckHandShake,"max_init_count",&iTmp)) {
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","max_init_count",csTag,"");
DEBUGLOG(("  Add max_init_count = [%d]\n",iTmp));
				}

				PutField_Int(hCheckHandShake, "disabled", PD_FALSE);
					sprintf(csTag,"%d",iTmp);
					AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_INSERT_CHECK_HAND_SHAKE,PD_ITT_LOG_INSERT,"CHECK_HAND_SHAKE","","disabled",csTag,"");
DEBUGLOG(("  Add: disabled = [%d]\n",PD_FALSE));

				PutField_CString(hCheckHandShake, "create_user", csUser);
DEBUGLOG(("  Add: create_user = [%s]\n",csUser));


				//Call DBCheckHandShake::Add
				DBObjPtr = CreateObj(DBPtr,"DBCheckHandShake","Add");
				iDtlRet = (unsigned long)(*DBObjPtr)(hCheckHandShake);

				if (iDtlRet == PD_OK) {
DEBUGLOG(("Call DBCheckHandShake::Add SUCCESS!\n")); 
				} else {
					iRet = iDtlRet;
DEBUGLOG(("Call DBCheckHandShake::Add FAILED, iRet = [%d]\n",iRet));
ERRLOG("TxnMgtByUsTMK Call DBCheckHandShake::Add FAILED, iRet = [%d]\n",iRet);
				}
			}

			hash_destroy(hCheckHandShake);
			FREE_ME(hCheckHandShake);
		}
	}

	iLogBatchSeq++;


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



	hash_destroy(hMerchKeys);
	FREE_ME(hMerchKeys);

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
		PutField_CString(hITTLog,"old_value",csOldValue);
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
