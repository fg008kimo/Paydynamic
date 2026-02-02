/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/07/20              [MIC]
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "dbutility.h"
#include "TxnMgtByUsCPA.h"
#include "myrecordset.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

int CheckFieldName(const char* csTmp, const char* csType);

void TxnMgtByUsCPA(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		const hash_t* hRequest,
		hash_t* hResponse)
{
	int	    iRet = PD_OK;
	char	*csRet;
	int	    iDtlRet = PD_OK;
	char	*csTmp = NULL;
	char	csTmpBuf[PD_TMP_BUF_LEN+1];
	int     iDecodeLen = 0;
	int     iLength;
	int     i;
	int     iPos1;
	int     iPos2;
	int     iPspReplicateEn;
	
	char	csPrefix[PD_PSP_ID_PREFIX_LEN + 1];
	char	csReplicatePspId[PD_PSP_ID_LEN + 1];
	//char	*csReplicatePspId;
	char	csCreatePspId[PD_PSP_ID_LEN + 1];
	char	csPspChannel[PD_PSP_ID_LEN + 1];
	char	csPspName[PD_PSP_NAME_LEN + 1];
	char	csPspMerchantId[PD_PSP_MID_LEN + 1];
	char	csPspKey[PD_MD5_KEY_LEN + 1];
	char	csPspUrl[PD_TLG_URL_LEN + 1]={0};
	char	csPspReqTxnUrl[PD_FUNCTION_URL_LEN + 1];
	char	csServPspUrl[PD_VALUE_LEN + 1] = "";
	char	csProcessorName[PD_PROCESSOR_NAME_LEN + 1];
	char    csGroup[PD_GROUP_LEN + 1];
	char    csGroup1[PD_GROUP_LEN + 1];
	//char    *csTmpVal[PD_MAX_TAG];
	
	char *p1;
	char *p2;
	char	*csUser;

	hash_t *hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);
	
	
	hash_t *hGetAttribute = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hGetAttribute,0);
	

//API: user
		if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: user not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: user not found!!\n");
		}

//API: psp_id
		if (GetField_CString(hRequest, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize() psp_id = [%s]\n", csTmp));
			strcpy(csReplicatePspId, csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_id not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_id not found!!\n");
		}
		
//API: psp_name
		if (GetField_CString(hRequest, "psp_name", &csTmp)) {
DEBUGLOG(("Authorize() psp_name = [%s]\n", csTmp));
			strcpy(csPspName, csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_name not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_name not found!!\n");
		}
		
//API: psp_merchant_id
		if (GetField_CString(hRequest, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("Authorize() psp_merchant_id = [%s]\n", csTmp));
			strcpy(csPspMerchantId, csTmp);
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_merchant_id not found!!\n");
		}
		
//API: psp_key
		if (GetField_CString(hRequest, "psp_key", &csTmp)) {
			urldecode((const unsigned char*)csTmp, strlen(csTmp),(unsigned char *)csPspKey, &iDecodeLen);
DEBUGLOG(("Authorize() psp_key = [%s]\n", csPspKey));
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_key not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_key not found!!\n");
		}
		
		
//API: psp_url
		if (GetField_CString(hRequest, "psp_url", &csTmp)) {
			urldecode((const unsigned char*)csTmp, strlen(csTmp),(unsigned char *)csPspUrl, &iDecodeLen);
DEBUGLOG(("Authorize() psp_url = [%s]\n", csPspUrl));
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_url not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_url not found!!\n");
		}
		
		
//API: psp_req_txn_url
		if (GetField_CString(hRequest, "psp_req_txn_url", &csTmp)) {
			urldecode((const unsigned char*)csTmp, strlen(csTmp),(unsigned char *)csPspReqTxnUrl, &iDecodeLen);
DEBUGLOG(("Authorize() psp_req_txn_url = [%s]\n", csPspReqTxnUrl));
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: psp_req_txn_url not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_req_txn_url not found!!\n");
		}
		
//API: serv_psp_url
		if (GetField_CString(hRequest, "serv_psp_url", &csTmp)) {
			urldecode((const unsigned char*)csTmp, strlen(csTmp),(unsigned char *)csServPspUrl, &iDecodeLen);
DEBUGLOG(("Authorize() serv_psp_url = [%s]\n", csServPspUrl));
		} else {
DEBUGLOG(("Authorize:: serv_psp_url not found!!\n"));
		}

		
//API: psp_channel
		if (GetField_CString(hRequest, "psp_channel", &csTmp)) {
DEBUGLOG(("Authorize() psp_channel = [%s]\n", csTmp));
			strcpy(csPspChannel, csTmp);
		} else {
DEBUGLOG(("Authorize:: psp_channel not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: psp_channel not found!!\n");
		}


		
	
//Check field name
	if (iRet == PD_OK) {
		iDtlRet = CheckFieldName(csPspName, PD_PSP_ACCOUNT_NAME);
		if(iDtlRet == PD_ERR){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_name [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csPspName, iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName psp_name [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csPspName, iDtlRet);
		}
		else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_name [%s] contain valid char set!!! iDtlRet = [%d]\n", csPspName, iDtlRet));
		}
			
		
		iDtlRet = CheckFieldName(csPspMerchantId, PD_PSP_MERCHANT_ID);
		if(iDtlRet == PD_ERR){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_merchant_id [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csPspMerchantId, iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName psp_merchant_id [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csPspMerchantId, iDtlRet);
		}
		else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_merchant_id [%s] contain valid char set!!! iDtlRet = [%d]\n", csPspMerchantId, iDtlRet));
		}
		
		iDtlRet = CheckFieldName(csPspKey, PD_PSP_KEY);
		if(iDtlRet == PD_ERR){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_key [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csPspKey, iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName psp_key [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csPspKey, iDtlRet);
		}
		else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_key [%s] contain valid char set!!! iDtlRet = [%d]\n", csPspKey, iDtlRet));
		}
		
		iDtlRet = CheckFieldName(csPspUrl, PD_PSP_URL);
		if(iDtlRet == PD_ERR){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_url [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csPspUrl, iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName psp_url [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csPspUrl, iDtlRet);
		}
		else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_url [%s] contain valid char set!!! iDtlRet = [%d]\n", csPspUrl, iDtlRet));
		}
		
		iDtlRet = CheckFieldName(csPspReqTxnUrl, PD_PSP_REQUEST_URL);
		if(iDtlRet == PD_ERR){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_req_txn_url [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csPspReqTxnUrl,  iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName psp_req_txn_url [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csPspReqTxnUrl, iDtlRet);
		}
		else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName psp_req_txn_url [%s] contain valid char set!!! iDtlRet = [%d]\n", csPspReqTxnUrl, iDtlRet));
		}		
		
		
		if (strcmp(csServPspUrl, "")) {
			iDtlRet = CheckFieldName(csServPspUrl, PD_SERVICE_PSP_URL);
			if(iDtlRet == PD_ERR){
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName serv_psp_url [%s] contains NOT Support Character Set!!! iDtlRet = [%d]\n", csServPspUrl, iDtlRet));
ERRLOG("TxnMgtByUsCPA::CheckFieldName serv_psp_url [%s] contains NOT Support Character Set!! iDtlRet = [%d]\n", csServPspUrl, iDtlRet);
			}
			else{
DEBUGLOG(("Call TxnMgtByUsCPA:CheckFieldName serv_psp_url [%s] contain valid char set!!! iDtlRet = [%d]\n", csServPspUrl, iDtlRet));	
			}
		}
	}
	
	
/*check flag*/
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBPspDetail","GetPspDetail");
		iDtlRet = (unsigned long)(*DBObjPtr)(csReplicatePspId, hGetAttribute);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspDetail::GetPspDetail() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspDetail::GetPspDetail Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspDetail::GetPspDetail( SUCCESS!!!\n"));
			if(GetField_Int(hGetAttribute, "psp_replicate_en", &iPspReplicateEn)){
				if(iPspReplicateEn != PD_TRUE){
DEBUGLOG(("Call TxnMgtByUsCPA: psp_id [%s] - psp_replicate_en [%d] is disable!!!\n", csReplicatePspId, iPspReplicateEn));
ERRLOG("TxnMgtByUsCPA: psp_id [%s] - psp_replicate_en [%d] is disable!!!\n", csReplicatePspId, iPspReplicateEn);
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
				}
				else{
DEBUGLOG(("Call TxnMgtByUsCPA: psp_id [%s] - psp_replicate_en [%d] is enable!!!\n", csReplicatePspId, iPspReplicateEn));
				}
			}
			else{
DEBUGLOG(("Authorize() psp_replicate_en not found!!\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspDetail::GetPspDetail psp_replicate_en NOT FOUND!!\n");
				
			}
		}
	}
		
/*psp_url convert symbol ? -> %3F for COP Channel*/
	if (iRet == PD_OK) {
		if(!strcmp(csPspChannel, PD_CHANNEL_CLOUD123PAY)){
			iLength = (PD_TLG_URL_LEN - strlen("%3F") - 1);
			for(i=0;i <=iLength;i++){
				
				if(i == iLength){
					csRet = strchr(&csPspUrl[i+1], '?');
					if(csRet != NULL){
DEBUGLOG(("Call TxnMgtByUsCPA: psp_url [%s] conversion length exceed max length [%d] !!!\n", csPspUrl, PD_TLG_URL_LEN));
ERRLOG("TxnMgtByUsCPA: psp_url [%s] conversion length exceed max length [%d] !!!\n", csPspUrl, PD_TLG_URL_LEN);
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
						break;
					}
				}
					
				if(csPspUrl[i] == '?'){
					if(csPspUrl[i+1] != '\0'){
						strcpy(csTmpBuf, &csPspUrl[i+1]);
					}
					else{
						memset(csTmpBuf, 0x00, sizeof(csTmpBuf));
					}
					strncpy(&csPspUrl[i], "%3F", strlen("%3F"));
					csPspUrl[i+3] = '\0';
					
					
					if((i + strlen("%3F") + strlen(csTmpBuf)) > PD_TLG_URL_LEN){
DEBUGLOG(("Call TxnMgtByUsCPA: psp_url [%s] conversion length exceed max length [%d] !!!\n", csPspUrl, PD_TLG_URL_LEN));
ERRLOG("TxnMgtByUsCPA: psp_url [%s] conversion length exceed max length [%d] !!!\n", csPspUrl, PD_TLG_URL_LEN);
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
						break;
					}
					else{
						strcat(csPspUrl, csTmpBuf);
DEBUGLOG(("Call TxnMgtByUsCPA: converted psp_url [%s] \n", csPspUrl));
					}
				}
			}
		}
	}

	
/*psp_detail*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
	
/*Get System Paramaeter Prefix*/
		DBObjPtr = CreateObj(DBPtr, "DBSystemParameter","FindCode");
		iDtlRet = (unsigned long)(*DBObjPtr)("PSP_DETAIL_PSP_ID_PREFIX", csPrefix);
		
		if (iDtlRet != FOUND) {
DEBUGLOG(("Authorize() call DBSystemParameter::FindCode() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBSystemParameter::FindCode Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBSystemParameter::FindCode( SUCCESS - Prefix : [%s]!!!\n", csPrefix));
		}
	


	
		DBObjPtr = CreateObj(DBPtr, "DBTxnSeq","GetNextPspIdSeq");
		strcpy(csCreatePspId,(*DBObjPtr)(csPrefix));
		if(!strcmp(csCreatePspId, "")){
DEBUGLOG(("Authorize() call DBTxnSeq::GetNextPspIdSeq() FAILURE!!! CreatePspId is Null\n"));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBTxnSeq::GetNextPspIdSeq Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
DEBUGLOG(("Authorize() call DBTxnSeq::GetNextPspIdSeq() SUCCESS - CreatePspId: [%s]\n", csCreatePspId));
			
		}
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"psp_name", csPspName);
		p1 = (char*)strchr(csPspName, '-');
		iPos1 = p1 - csPspName + 1;
		p2 = (char*)strchr(&csPspName[p1 - csPspName + 1], '-');
		iPos2 = p2 - csPspName + 1;
		sprintf(csProcessorName, "%.*s", iPos2 - iPos1 - 1, &csPspName[iPos1]);
		csProcessorName[iPos2 - iPos1 - 1] = '\0';
DEBUGLOG(("Authorize() ProcessorName: [%s]!!\n",csProcessorName));
		


		PutField_CString(hRec,"processor_name", csProcessorName);
		PutField_CString(hRec,"create_user", csUser);
		PutField_CString(hRec,"psp_merchant_id", csPspMerchantId);
		PutField_CString(hRec,"oride_bank_code_channel", csCreatePspId);
		
		DBObjPtr = CreateObj(DBPtr, "DBPspDetail","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspDetail::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspDetail::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspDetail::Replicate SUCCESS!!!\n"));
		}
	}
	


/*psp_country*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"country", PD_CHINA);
		PutField_CString(hRec,"psp_id", csCreatePspId);
		PutField_CString(hRec,"ccy", PD_CCY_ISO_CNY);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspCountry","Add");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspCountry::Add() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspCountry::Add Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspCountry::Add( SUCCESS!!!\n"));
		}
	}
	
/*psp_payment_method*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspPayMethod","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspPayMethod::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspPayMethod::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspPayMethod::Replicate( SUCCESS!!!\n"));
		}
	}
	
	
	

/*psp_costs*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspCosts","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspCosts::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspCosts::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspCosts::Replicate( SUCCESS!!!\n"));
		}
	}
	


/*rule_psp_release_period*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBRulePspReleasePeriod","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBRulePspReleasePeriod::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBRulePspReleasePeriod::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBRulePspReleasePeriod::Replicate( SUCCESS!!!\n"));
		}
	}

/*crr_psp_product_code_map*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBCrrPspProductCodeMap","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBCrrPspProductCodeMap::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBCrrPspProductCodeMap::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBCrrPspProductCodeMap::Replicate( SUCCESS!!!\n"));
		}
	}

	
/*psp_keys*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"key_value", csPspKey);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspKeys","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspKeys::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspKeys::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspKeys::Replicate( SUCCESS!!!\n"));
		}
	}
	

/*psp_url*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"psp_url", csPspUrl);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspUrl","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspUrl::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspUrl::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspUrl::Replicate( SUCCESS!!!\n"));
		}
	}
	

/*psp_request_txn_url*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"request_function", csPspReqTxnUrl);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspRequestTxnUrl","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspRequestTxnUrl::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspRequestTxnUrl::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspRequestTxnUrl::Replicate( SUCCESS!!!\n"));
		}
	}
	
/*txn_be_url*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBTxnBeUrl","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBTxnBeUrl::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBTxnBeUrl::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBTxnBeUrl::Replicate( SUCCESS!!!\n"));
		}
	}
	
/*psp_cognos_map*/

	if (iRet == PD_OK) {
		PutField_CString(hRec,"psp_id", csCreatePspId);
		
		p1 = (char*)strchr(csPspName, '-');
		iPos1 = p1 - csPspName + 1;
		p2 = (char*)strchr(&csPspName[p1 - csPspName + 1], '-');
		iPos2 = p2 - csPspName + 1;
		sprintf(csGroup, "%.*s", iPos2 - 1, csPspName);
		sprintf(csGroup1, "%.*s", iPos2 - 1, csPspName);
DEBUGLOG(("Authorize() csGroup: [%s]!!\n",csGroup));
DEBUGLOG(("Authorize() csGroup1: [%s]!!\n",csGroup1));
		
		PutField_CString(hRec,"group", csGroup);
		PutField_CString(hRec,"group_1", csGroup1);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspCognosMap","Add");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspCognosMap::Add() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspCognosMap::Add Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspCognosMap::Add( SUCCESS!!!\n"));
		}
	}
	
/*service_psp_url*/

	if (iRet == PD_OK) {
		if (strcmp(csServPspUrl, "")){
			PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
			PutField_CString(hRec,"create_psp_id", csCreatePspId);
			PutField_CString(hRec,"service_psp_url", csServPspUrl);
			PutField_CString(hRec,"create_user", csUser);
			DBObjPtr = CreateObj(DBPtr, "DBServicePspUrl","Replicate");
			iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
			
			if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBServicePspUrl::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBServicePspUrl::Replicate Failure!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			} 
			else {
DEBUGLOG(("Authorize() call DBServicePspUrl::Replicate( SUCCESS!!!\n"));
			}
		}
	}

/*psp_payout_file_format_mapping*/
	if (iRet == PD_OK) {
			PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
			PutField_CString(hRec,"create_psp_id", csCreatePspId);
			PutField_CString(hRec,"create_user", csUser);
			DBObjPtr = CreateObj(DBPtr, "DBPspPayoutFileFormatMapping","Replicate");
			iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
			
			if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspPayoutFileFormatMapping::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspPayoutFileFormatMapping::Replicate Failure!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			} 
			else {
DEBUGLOG(("Authorize() call DBPspPayoutFileFormatMapping::Replicate( SUCCESS!!!\n"));
			}
	}

	
	
/*bank_mapping*/
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRec);
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBBankMapping::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBBankMapping::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBBankMapping::Replicate( SUCCESS!!!\n"));
		}
	}
	
	
/*psp_txn_check*/
			
	if (iRet == PD_OK) {
		PutField_CString(hRec,"replicate_psp_id", csReplicatePspId);
		PutField_CString(hRec,"create_psp_id", csCreatePspId);
		PutField_CString(hRec,"create_user", csUser);
		DBObjPtr = CreateObj(DBPtr, "DBPspTxnCheck","Replicate");
		iDtlRet = (unsigned long)(*DBObjPtr)();
		
		if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize() call DBPspTxnCheck::Replicate() FAILURE!!! iDtlRet = [%d]\n",iDtlRet));
ERRLOG("TxnMgtByUsCPA:: Authorize:: call DBPspTxnCheck::Replicate Failure!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		} 
		else {
DEBUGLOG(("Authorize() call DBPspTxnCheck::Replicate( SUCCESS!!!\n"));
		}
	}

	
	PutField_CString(hResponse,"psp_id",csCreatePspId);
	
	if(iRet != PD_OK){
		TxnAbort();
	}

	hash_destroy(hRec);
	FREE_ME(hRec);	
	
	hash_destroy(hGetAttribute);
	FREE_ME(hGetAttribute);




DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}



int CheckFieldName(const char* csTmp, const char* csType)
{
	
	if(!strcmp(csType, PD_PSP_ACCOUNT_NAME)){
		while (*csTmp) {
			if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				!(*csTmp >= 'A' && *csTmp <= 'Z') &&
				!(*csTmp >= '0' && *csTmp <= '9') && 
				!(*csTmp == '-')
				) {
					return PD_ERR;
DEBUGLOG(("Authorize()::CheckFieldName %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp));
ERRLOG("TxnMgtByUsCPA::Authorize::CheckFieldName() %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp);
				break;
			} else {
	// DEBUGLOG(("Authorize() int_prov_flr_name [%c]\n",*csTmp));
			}
			csTmp++;
		}
	}
	
	else if(!strcmp(csType, PD_PSP_MERCHANT_ID)){
		while (*csTmp) {
			if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				!(*csTmp >= 'A' && *csTmp <= 'Z') &&
				!(*csTmp >= '0' && *csTmp <= '9') &&
				!(*csTmp == '-' || *csTmp == '_')) {
					return PD_ERR;
DEBUGLOG(("Authorize()::CheckFieldName %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp));
ERRLOG("TxnMgtByUsCPA::Authorize::CheckFieldName() %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp);
				break;
			} else {
	// DEBUGLOG(("Authorize() int_prov_flr_name [%c]\n",*csTmp));
			}
			csTmp++;
		}
	}
	
	//~!@#$%^&*()_+`-=[]\;',./{}|:"<>?
	else if(!strcmp(csType, PD_PSP_KEY)){
		while (*csTmp) {
			if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				!(*csTmp >= 'A' && *csTmp <= 'Z') &&
				!(*csTmp >= '0' && *csTmp <= '9') &&
				!(	*csTmp == '~' || *csTmp == '!' || *csTmp == '@'
					|| *csTmp == '#' || *csTmp == '$' || *csTmp == '%'
					|| *csTmp == '^' || *csTmp == '&' || *csTmp == '*'
					|| *csTmp == '(' || *csTmp == ')' || *csTmp == '_'
					|| *csTmp == '+' || *csTmp == '`' || *csTmp == '-'
					|| *csTmp == '=' || *csTmp == '[' || *csTmp == ']'
					|| *csTmp == 0x5c || *csTmp == ';' || *csTmp == 0x27
					|| *csTmp == ',' || *csTmp == '.' || *csTmp == '/'
					|| *csTmp == '{' || *csTmp == '}' || *csTmp == '|'
					|| *csTmp == ':' || *csTmp == '"' || *csTmp == '<'
					|| *csTmp == '>' || *csTmp == '?'
					)) {
					return PD_ERR;
DEBUGLOG(("Authorize()::CheckFieldName %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp));
ERRLOG("TxnMgtByUsCPA::Authorize::CheckFieldName() %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp);
				break;
			} else {
	// DEBUGLOG(("Authorize() int_prov_flr_name [%c]\n",*csTmp));
			}
			csTmp++;
		}
	}
	
	//-._~:/?#[]@!$&'()*+,;=%
	else if(!strcmp(csType, PD_PSP_URL)
		|| !strcmp(csType, PD_PSP_REQUEST_URL)
		|| !strcmp(csType, PD_SERVICE_PSP_URL)
			){
		while (*csTmp) {
			if (!(*csTmp >= 'a' && *csTmp <= 'z') &&
				!(*csTmp >= 'A' && *csTmp <= 'Z') &&
				!(*csTmp >= '0' && *csTmp <= '9') &&
				!(	*csTmp == '-' || *csTmp == '.' || *csTmp == '_'
					|| *csTmp == '~' || *csTmp == ':' || *csTmp == '/'
					|| *csTmp == '?' || *csTmp == '#' || *csTmp == '['
					|| *csTmp == ']' || *csTmp == '@' || *csTmp == '!'
					|| *csTmp == '$' || *csTmp == '&' || *csTmp == 0x27
					|| *csTmp == '(' || *csTmp == ')' || *csTmp == '*'
					|| *csTmp == '+' || *csTmp == ',' || *csTmp == ';'
					|| *csTmp == '=' || *csTmp == '%')) {
					return PD_ERR;
DEBUGLOG(("Authorize()::CheckFieldName %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp));
ERRLOG("TxnMgtByUsCPA::Authorize::CheckFieldName() %s char[%c] NOT MATCH [a-zA-Z0-9/-_]!!!\n", csTmp, *csTmp);
				break;
			} else {
	// DEBUGLOG(("Authorize() int_prov_flr_name [%c]\n",*csTmp));
			}
			csTmp++;
		}
	}
	
	
	
	return PD_OK;
}





