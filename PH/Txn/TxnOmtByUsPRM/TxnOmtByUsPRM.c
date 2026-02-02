/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/02/02              [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsPRM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"



static char cDebug;
OBJPTR(DB);

int Verify_ProvId(const char* csProvId, hash_t* hRec);

void TxnOmtByUsPRM(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	
	char *csCreateTsFr = NULL;
	char *csCreateTsTo = NULL;
	char *csProvId = NULL;
	char *csTrigSeq = NULL;			
	char *csCmd = (char*)malloc(PD_TMP_MSG_BUF_LEN);
	char cStatus;

	int iDtlRet = PD_ERR;
	int iRet = PD_OK;

	unsigned long	lTrigSeq;

	
	hash_t* hGetAttribute;
	hGetAttribute = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hGetAttribute,0);
	
	hash_t* hTriggerLog;
	hTriggerLog = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hTriggerLog,0);
DEBUGLOG(("TxnOmtByUsPRM::Authorize\n"));



	/* create_ts_from */
	if (GetField_CString(hRequest, "create_ts_from", &csCreateTsFr)){
DEBUGLOG(("- create_ts_from = [%s]\n", csCreateTsFr));
	}
	else{
DEBUGLOG(("- create_ts_from not found!!\n"));
ERRLOG("TxnOmtByUsPRM::Authorize:: create_ts_from not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}
	
	/* create_ts_to */
	if (iRet == PD_OK){
		if (GetField_CString(hRequest, "create_ts_to", &csCreateTsTo)){
DEBUGLOG(("- create_ts_to = [%s]\n", csCreateTsTo));
		}
		else{
DEBUGLOG(("- create_ts_to not found!!\n"));
ERRLOG("TxnOmtByUsPRM::Authorize:: create_ts_to not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	
	/* provider_id */
	if (iRet == PD_OK){
		if (GetField_CString(hRequest, "provider_id", &csProvId))
		{
DEBUGLOG(("- provider_id = [%s]\n", csProvId));
		}
		else
		{
DEBUGLOG(("- provider_id not found!!\n"));
ERRLOG("TxnOmtByUsPRM::Authorize:: provider_id not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}
	
	/*trigger_seq*/
	if (iRet == PD_OK){
		if (GetField_CString(hRequest, "trigger_seq", &csTrigSeq))
		{
DEBUGLOG(("- trigger_seq = [%s]\n", csTrigSeq));
			lTrigSeq = (unsigned long)ctol((const unsigned char*)csTrigSeq,strlen(csTrigSeq));
		}
		else
		{
DEBUGLOG(("- trigger_seq not found!!\n"));
ERRLOG("TxnOmtByUsPRM::Authorize:: trigger_seq not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	
	/*datetime Validation*/
	/* create_ts_from */
	if (iRet == PD_OK){
		iDtlRet = check_valid_datetime(csCreateTsFr);
		if(iDtlRet != PD_OK){
DEBUGLOG(("- call check_valid_datetime() CreateFromTimestamp [%s] failed\n", csCreateTsFr));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			
		}
	}
	
	/* create_ts_to */
	if (iRet == PD_OK){
		iDtlRet = check_valid_datetime(csCreateTsTo);
		if(iDtlRet != PD_OK){
DEBUGLOG(("- call check_valid_datetime() CreateToTimestamp [%s] failed\n", csCreateTsTo));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			
		}
	}

	/*provider_id Validation*/
	/* provider_id */
	if (iRet == PD_OK){
		iDtlRet = Verify_ProvId(csProvId, hGetAttribute);
		if(iDtlRet != PD_OK){
DEBUGLOG(("- call Verify_ProvId() [%s] failed\n", csProvId));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			
		}
	}
	
	// Get Trigger Status By Trigger Seq from OL_PAYOUT_RECON_TRIGGER_LOG
	if (iRet == PD_OK){
DEBUGLOG(("- Calling DBOLPayoutReconTriggerLog::GetHeaderByFileId\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutReconTriggerLog", "GetHeaderByFileId");
		iDtlRet = (unsigned long)(*DBObjPtr)(lTrigSeq, hTriggerLog);

DEBUGLOG(("- DBOLPayoutReconTriggerLog::GetHeaderByFileId iRet = [%d]\n", iDtlRet));

		if (iDtlRet == PD_OK){
			// Check Status That Should Be Initialized
			/* status */
			if (GetField_Char(hTriggerLog, "trigger_status", &cStatus)){
DEBUGLOG(("- trigger_status = [%c]\n", cStatus));
				if (cStatus != PD_TRIGGER_STATUS_INIT){
DEBUGLOG(("- trigger_status is not expected value \"I\"!!\n"));
					iRet = INT_ERR;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
			else{
DEBUGLOG(("- status not found!!\n"));
ERRLOG("TxnOmtByUsPRM::Authorize:: Calling DBOLPayoutReconTriggerLog::GetHeaderByFileId status not found!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
		else{
DEBUGLOG(("call DBOLPayoutReconTriggerLog::GetHeaderByFileId Error!!\n"));
ERRLOG("TxnOmtByUsPRM:: Authorize:: call OLPayoutReconTriggerLog::GetHeaderByFileId Error!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
			
		}
	}

	
	// check conflict
	if (iRet == PD_OK){
DEBUGLOG(("- call DBOLPayoutReconTriggerLog::CheckConflict()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutReconTriggerLog", "CheckConflict");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRequest);
		if (iDtlRet == PD_FOUND) {
DEBUGLOG(("- conflict found\n"));
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} 
		else {
DEBUGLOG(("- conflict not found\n"));
		}
	}
				
	
	// Call System Job To Run Trigger Pre-reconciliation
	if (iRet == PD_OK)
	{
		memset(csCmd, 0, PD_TMP_MSG_BUF_LEN);
		snprintf(csCmd, PD_TMP_MSG_BUF_LEN, "ol_payout_recon_ignore_bank_match.sh %s %s %s %s &", csCreateTsFr, csCreateTsTo, csProvId, csTrigSeq);

DEBUGLOG(("- TxnOmtByUsPRM::Authorize Calling System Job [%s] To Run Payout Reconciliation Ignore Bank Matching In Background!!\n", csCmd));
		system(csCmd);
	}

	FREE_ME(csCmd);
	
	
	hash_destroy(hGetAttribute);
	FREE_ME(hGetAttribute);
	
	
	hash_destroy(hTriggerLog);
	FREE_ME(hTriggerLog);
	

DEBUGLOG(("TxnOmtByUsPRM Normal Exit() iRet = [%d]\n", iRet));
	return iRet;	
}



int Verify_ProvId(const char* csProvId, hash_t* hRec)
{
	int iRet = PD_ERR;
	int iDtlRet = PD_ERR;
	char* csClientStatus;
	char* csModeType;
	
	
	DBObjPtr = CreateObj(DBPtr,"DBPspMaster","GetClientByClientId");
	iDtlRet = (unsigned long)(*DBObjPtr)(csProvId, hRec);
	if (iDtlRet == PD_FOUND) {
DEBUGLOG(("  Verify_ProvId: call DBPspMaster::GetClientByClientId Found!!\n"));
		if(GetField_CString(hRec,"client_status", &csClientStatus)){
DEBUGLOG(("  Verify_ProvId: client_status = [%s]\n", csClientStatus));
			if(!strcmp(csClientStatus, PD_ACC_OPEN)){
DEBUGLOG(("  Verify_ProvId: client_status is open!!\n"));
				iRet = PD_OK;
			}
			else{
DEBUGLOG(("  Verify_ProvId: client_status should not be closed!!\n"));
				iRet = PD_ERR;
			}
		}
		else{
DEBUGLOG(("  Verify_ProvId: client_status not found!!\n"));
			iRet = PD_ERR;
			
		}
		if(iRet == PD_OK){
			if(GetField_CString(hRec,"mode_type", &csModeType)){
DEBUGLOG(("  Verify_ProvId: mode_type = [%s]\n", csModeType));
				if(!strcmp(csModeType, PD_PSP_MASTER_MODE_OFFLINE) 
					|| !strcmp(csModeType, PD_PSP_MASTER_MODE_ALL)){
					iRet = PD_OK;
				}
				else{
					iRet = PD_ERR;
				}
			}
			else{
DEBUGLOG(("  Verify_ProvId: mode_type not found!!\n"));
				iRet = PD_ERR;
			}
		}
	}
	else if(iDtlRet == PD_NOT_FOUND){
DEBUGLOG(("  Verify_ProvId: call DBPspMaster::GetClientByClientId Not Found!!\n"));
		iRet = PD_ERR;
	}
	else{
DEBUGLOG(("  Verify_ProvId: call DBPspMaster::GetClientByClientId Error!!\n"));
ERRLOG("TxnOmtByUsPRM:: Authorize:: Verify_ProvId:: call DBPspMaster::GetClientByClientId Error!!\n");
		iRet = INT_ERR;
	}

	return iRet;
}


