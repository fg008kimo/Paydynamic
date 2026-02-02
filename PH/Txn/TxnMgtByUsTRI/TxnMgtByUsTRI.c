/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTRI.h"
#include "myrecordset.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Msg);

void TxnMgtByUsTRI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	char    csOrgDateTime[PD_DATETIME_LEN +1];
	char*	csEncTxnSeq;
	//char	*csPayMethod;
	char	*csTxnCcy;
	char	*csOrgTxnCountry;
	char	*csOrgChannelCode;
	char	*csOrgServiceCode;
	char	*csOrgMerchantId;
	char	*csSubStatus;
	//char	*csSelectedPID = NULL;
	char*	csPtr;
	char*	csIpAddr;
	char*	csUserAgent;
	//double	dTmp;
	double	dTxnAmt;
	recordset_t     *rRecordSet;   
	hash_t	*hRec;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
DEBUGLOG(("Authorize()\n"));
	memset(csTxnSeq,0,PD_TXN_SEQ_LEN);

	if (GetField_CString(hRequest,"enc_txn_seq",&csEncTxnSeq)) {
DEBUGLOG(("Authorize() enc_txn_seq = [%s]\n",csEncTxnSeq));
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
                (BOObjPtr)(csEncTxnSeq,csTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
		PutField_CString(hContext,"org_txn_seq",csTxnSeq);
	}
	else {
		iRet = INT_ENC_TXN_ID_MISSING;
DEBUGLOG(("Authorize() enc_txn_seq is missing\n"));
ERRLOG("TxnMgtByUsTRI::Authorize() enc_txn_seq is missing\n");
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (iRet == PD_OK){
		if (GetField_CString(hRequest,"ip_addr",&csIpAddr)) {
DEBUGLOG(("Authorize() ip_addr = [%s]\n",csIpAddr));
		}
		if (GetField_CString(hRequest,"user_agent",&csUserAgent)) {
DEBUGLOG(("Authorize() user_agent = [%s]\n",csUserAgent));
		}
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn_ReadOnly");
                if ((unsigned long)(DBObjPtr)(csTxnSeq,PD_INIT) != PD_FOUND) {
	        	iRet = INT_TXN_ID_NOT_FOUND;    
DEBUGLOG(("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_INIT));
//ERRLOG("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_INIT);
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
			int iRange = PD_DEF_TXN_EXPIRE_TIME;
			int iTmpRet = PD_FALSE;
			char*   csValueTmp;
			csValueTmp = (char*) malloc (10);
			DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
			if ((unsigned long)(DBObjPtr)("TXN_EXPIRE_TIME",csValueTmp) == FOUND) {
				if(is_numeric(csValueTmp)){
					iRange = atoi(csValueTmp);
				}
			}
DEBUGLOG(("Authorize::Transaction Expire Time (min) = [%d]\n",iRange));
			FREE_ME(csValueTmp);

			DBObjPtr = CreateObj(DBPtr,"DBTransaction","IsCreateTimeWithinRange");
			iTmpRet = (unsigned long)(DBObjPtr)(csTxnSeq,iRange);
			if(iTmpRet==PD_TRUE){
DEBUGLOG(("Authorize::Transaction not yet expired\n"));
			}
			else if(iTmpRet==PD_FALSE){
				iRet = INT_TXN_EXPIRED;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::Transaction is expired!!!!\n"));
			}
			else{
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBTransaction::IsCreateTimeWithinRange Error!!!!\n"));
			}
                }
	}
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_Double(hRec,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize::GetTxnHeader - txn_amt = [%lf]\n",dTxnAmt));
                                        PutField_Double(hResponse,"txn_amt",dTxnAmt);
                                 }
                                 if (GetField_CString(hRec,"net_ccy",&csTxnCcy)) {
					PutField_CString(hResponse,"txn_ccy",csTxnCcy);
DEBUGLOG(("Authorize::GetTxnHeader - net_ccy = [%s]\n",csTxnCcy));
				 }
                                 if (GetField_CString(hRec,"merchant_id",&csOrgMerchantId)) {
                                        PutField_CString(hResponse,"merchant_id",csOrgMerchantId);
DEBUGLOG(("Authorize::GetTxnHeader - merchant_id = [%s]\n",csOrgMerchantId));
                                 }
                                 if (GetField_CString(hRec,"merchant_ref",&csPtr)) {
                                        PutField_CString(hResponse,"merchant_ref",csPtr);
				 }
                                 if (GetField_CString(hRec,"channel_code",&csOrgChannelCode)) {
DEBUGLOG(("Authorize::GetTxnHeader - channel_code = [%s]\n",csOrgChannelCode));
                                 }
                                 if (GetField_CString(hRec,"service_code",&csOrgServiceCode)) {
DEBUGLOG(("Authorize::GetTxnHeader - service code = [%s]\n",csOrgServiceCode));
                                 }
				 if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
                                        strcpy(csOrgDateTime,csPtr);
                                 }
                                 if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
                                        memcpy(&csOrgDateTime[PD_DATE_LEN],csPtr,PD_TIME_LEN);
                                        csOrgDateTime[PD_DATETIME_LEN] = '\0';
DEBUGLOG(("Authorize::GetTxnHeader - org_local_tm_datetime = [%s]\n",csOrgDateTime));
                                        PutField_CString(hContext,"org_local_tm_datetime",csOrgDateTime);
                                 }
				 if (GetField_CString(hRec,"sub_status",&csSubStatus)) {
DEBUGLOG(("Authorize::GetTxnHeader - sub_status = [%s]\n",csSubStatus));
                                 }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        	RecordSet_Destroy(rRecordSet);
        }
/***** ***/
	if (iRet == INT_TXN_ID_NOT_FOUND) {
		char	cStatus;
		char	*csOrgTxnCode;
		char	*csOrgServiceCode;
		char	*csOrgPayMethod;
		char	*csOrgLanguage;
		char	*csUrl;
		recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("Authorize::GetTxnHeader - status = [%c]\n",cStatus));
                                 }
                                 if (GetField_CString(hRec,"service_code",&csOrgServiceCode)) {
DEBUGLOG(("Authorize::GetTxnHeader - service code = [%s]\n",csOrgServiceCode));
                                 }
                                 if (GetField_CString(hRec,"txn_code",&csOrgTxnCode)) {
DEBUGLOG(("Authorize::GetTxnHeader - txn code = [%s]\n",csOrgTxnCode));
                                 }


                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                RecordSet_Destroy(rRecordSet);

		recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn detail found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_CString(hRec,"selected_pay_method",&csOrgPayMethod)) {
DEBUGLOG(("Authorize::GetTxnDetail - selected_method = [%s]\n",csOrgPayMethod));
                                 }
                                 if (GetField_CString(hRec,"txn_country",&csOrgTxnCountry)) {
DEBUGLOG(("Authorize::GetTxnDetail - txn country = [%s]\n",csOrgTxnCountry));
                                 }

                                 if (GetField_CString(hRec,"language",&csOrgLanguage)) {
DEBUGLOG(("Authorize::GetTxnDetail - language= [%s]\n",csOrgLanguage));
                                 }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                RecordSet_Destroy(rRecordSet);


		if (cStatus == PD_TO_PSP && (!strcmp(csOrgPayMethod,PD_NET_BANKING) || !strcmp(csOrgPayMethod,PD_CONVENIENCE_STORE) || !strcmp(csOrgPayMethod,PD_ATM_PAYMENT))) {
			iRet = PD_OK;
ERRLOG("Authorize() org txn id record [%s] not found for status = [%c],but using previous record stored\n",csTxnSeq,PD_INIT);
			recordset_init(rRecordSet,0);
                	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                	if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn psp detail found record = [%s]\n",csTxnSeq));
                        	hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {
                                	if (GetField_CString(hRec,"url",&csUrl)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - url = [%s]\n",csUrl));
						PutField_CString(hResponse,"redirect_url",csUrl);
                               		}

                                	hRec = RecordSet_GetNext(rRecordSet);
                        	}
                	}
                	RecordSet_Destroy(rRecordSet);

DEBUGLOG(("Authorize: is redirect_url found?\n"));
			if (!GetField_CString(hResponse,"redirect_url",&csUrl)) {
DEBUGLOG(("Authorize: redirect_url not found\n"));
				recordset_init(rRecordSet,0);
DEBUGLOG(("call\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnRptUrl","GetRptUrl");
DEBUGLOG(("call function ptr created\n"));
                        	if ((DBObjPtr)(csOrgTxnCode,csOrgServiceCode,csOrgLanguage,csOrgPayMethod,rRecordSet) == PD_OK) {
DEBUGLOG(("call and record found??\n"));
                                	hRec = RecordSet_GetFirst(rRecordSet);
                                	while(hRec){
                                        	if (GetField_CString(hRec,"rpt_url",&csPtr)) {
							char	*csBuf;
							csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
DEBUGLOG(("Authorize:: GetRptUrl - url only = [%s]\n",csPtr));
                                                	PutField_CString(hResponse,"rpt_url_only",csPtr);

                                                       	sprintf(csBuf,"%s?sessionid=%s",csPtr,csEncTxnSeq);
                                                       	PutField_CString(hResponse,"rpt_url",csBuf);

DEBUGLOG(("Authorize:: redirect_url = [%s]\n",csBuf));
							FREE_ME(csBuf);
                                        	}
                                        	hRec = RecordSet_GetNext(rRecordSet);
                                	}
                        	}
				else {
DEBUGLOG(("Authorize: not rpt record found\n"));
				}
                        	RecordSet_Destroy(rRecordSet);
			}
		}
		
		else if(cStatus == PD_TO_PSP){
			TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsTSI","ResendToPsp");
			iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
			if(iRet != PD_RESEND_TO_PSP){
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize: ResendToPsp failed = [%d]\n",iRet));
ERRLOG("TxnMgtByUsTRI:Authorize: ResendToPsp failed = [%d]\n",iRet);
			}
		}
		else{
ERRLOG("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_INIT);
		}

	}
	else if(iRet==PD_OK){ //init record found 
		if(!strcmp(csSubStatus,PD_HAND_SHAKEN)){
			hash_t*	hCon;
			hCon = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hCon,0);

			PutField_CString(hCon,"txn_seq",csTxnSeq);
			PutField_CString(hCon,"ip_addr",csIpAddr);
			PutField_CString(hCon,"user_agent",csUserAgent);
			PutField_CString(hCon,"sub_status",PD_INITIATED);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
			if ((DBObjPtr)(hCon) == PD_OK) {
DEBUGLOG(("Authorize() update txn_header sub-status[%s]\n",csTxnSeq));
			}
			FREE_ME(hCon);
		}
DEBUGLOG(("Authorize() transaction is valid[%s]\n",csTxnSeq));
	}
	else{
		PutField_Int(hContext,"internal_error",iRet);
	}

	FREE_ME(rRecordSet);
DEBUGLOG(("Authorize() normal exit = [%d]\n",iRet));
	return iRet;
}


/*
int	ResendToPsp(hash_t* hContext,
		    const hash_t* hRequest,
		    hash_t* hResponse)
{
	int iRet = PD_RESEND_TO_PSP;
	int iChk = PD_OK;
	hex_t   *h_msg;
	//struct msg_t* msg;

	char* csPtr;
	char* csTmp;
	char* csTxnSeq;
	char* csTmpTxnCode;
	char* csOrgTxnCode;
	char* csTxnCcy;
	char* csTxnCountry;
	char* csServiceCode;
	char* csMerchantId;
	char* csPspChannel;
	char* csSelectedPayMethod;
	char* csLanguage;
	char* csPspId;
	//char* csPspUrl;
	char* csInternalBankCode;
	//char* csRequestFunction;
	//char* csMethod;
	//char  csTmpBuf[PD_TMP_BUF_LEN + 1];
	char  csBankCodeChannel[PD_PSP_ID_LEN +1];
	char  csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	double	dTxnAmt = 0.0;
	char	cStatus;

	hash_t	*hRec;
	recordset_t     *rRecordSet;   
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

	hash_t *myHash;
	myHash = (hash_t*) malloc (sizeof(hash_t));
	hash_init(myHash,0);

	if(GetField_CString(hContext,"org_txn_seq",&csTxnSeq)){
		PutField_CString(hResponse,"txn_seq",csTxnSeq);
	}
	if(GetField_CString(hContext,"txn_code",&csTmpTxnCode)){
		PutField_CString(hContext,"tmp_txn_code",csTmpTxnCode);
	}
DEBUGLOG(("ResendToPsp:: txn_seq [%s], txn_code [%s]\n",csTxnSeq, csTmpTxnCode));
ERRLOG("ResendToPsp:: txn_seq [%s], txn_code [%s]\n",csTxnSeq, csTmpTxnCode);

	if (iChk == PD_OK) {
////////get txn header
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("ResendToPsp::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec,"service_code",&csServiceCode)) {
DEBUGLOG(("ResendToPsp::GetTxnHeader - service_code = [%s]\n",csServiceCode));
					PutField_CString(hResponse,"service_code",csServiceCode);
				}
				if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
DEBUGLOG(("ResendToPsp::GetTxnHeader - merchant_id = [%s]\n",csMerchantId));
					PutField_CString(hResponse,"merchant_id",csMerchantId);
				}
				if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
					PutField_CString(hResponse,"local_tm_date",csPtr);
				}
				if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
					PutField_CString(hResponse,"local_tm_time",csPtr);
				}
				if (GetField_CString(hRec,"txn_code",&csOrgTxnCode)) {
DEBUGLOG(("ResendToPsp::GetTxnHeader - org_txn_code = [%s]\n",csOrgTxnCode));
					PutField_CString(hContext,"org_txn_code",csOrgTxnCode);
					PutField_CString(hResponse,"org_txn_code",csOrgTxnCode);
				}
				if(GetField_Char(hRec,"status",&cStatus)){
					PutField_Char(hResponse,"status",cStatus);
DEBUGLOG(("ResendToPsp::GetTxnHeader - status = [%c]\n",cStatus));
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iChk = INT_ERR;
		}
        }
	if (iChk== PD_OK) {
////////get txn detail 
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
		if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("ResendToPsp::txn detail found record = [%s]\n",csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"txn_country",&csTxnCountry)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - txn_country = [%s]\n",csTxnCountry));
                                        PutField_CString(hResponse,"txn_country",csTxnCountry);
                                 }
				if (GetField_CString(hRec,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - org_pay_method = [%s]\n",csSelectedPayMethod));
                                        PutField_CString(hResponse,"selected_pay_method",csSelectedPayMethod);
                                 }
				if (GetField_CString(hRec,"failure_url",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - org_failure_url = [%s]\n",csPtr));
					PutField_CString(hResponse,"failure_url",csPtr);
				}
				if (GetField_CString(hRec,"success_url",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - org_success_url = [%s]\n",csPtr));
					PutField_CString(hResponse,"success_url",csPtr);
				}
				if (GetField_CString(hRec,"language",&csLanguage)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - org_language = [%s]\n",csLanguage));
					PutField_CString(hResponse,"org_language",csLanguage);
					PutField_CString(hResponse,"language",csLanguage);
				}
				if (GetField_CString(hRec,"encrypt_type",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - encrypt_type = [%s]\n",csPtr));
					PutField_CString(hResponse,"encrypt_type",csPtr);
				}
				if (GetField_CString(hRec,"customer_tel",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnDetail - customer_tel = [%s]\n",csPtr));
					PutField_CString(hResponse,"customer_tel",csPtr);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iChk = INT_ERR;
		}
	}

	if (iChk== PD_OK) {
////////get txn psp detail 
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("ResendToPsp::txn psp detail found record = [%s]\n",csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("ResendToPsp::GetTxnPspDetail - psp_id = [%s]\n",csPspId));
					PutField_CString(hResponse,"psp_id",csPspId);
				}
				if (GetField_CString(hRec,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("ResendToPsp::GetTxnPspDetail - txn_ccy = [%s]\n",csTxnCcy));
					PutField_CString(hResponse,"psp_txn_ccy",csTxnCcy);
				}
				if (GetField_Double(hRec,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("ResendToPsp::GetTxnPspDetail - txn_amt = [%lf]\n",dTxnAmt));
					//PutField_Double(hResponse,"txn_amt",dTxnAmt);
					PutField_Double(hResponse,"psp_txn_amt",dTxnAmt);
				}
				if (GetField_CString(hRec,"bank_code",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnPspDetail - bank_code = [%s]\n",csPtr));
					PutField_CString(hContext,"bank_code",csPtr);
				}
				if (GetField_CString(hRec,"sc",&csPtr)) {
DEBUGLOG(("ResendToPsp::GetTxnPspDetail - sc = [%s]\n",csPtr));
					PutField_CString(hResponse,"sc",csPtr);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iChk = INT_ERR;
		}
	}
	if (iChk== PD_OK) {
////////get psp detail 
		hash_init(myHash,0);
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
		if ((DBObjPtr)(csPspId,myHash) == PD_OK) {
			if (GetField_CString(myHash,"psp_merchant_id",&csPtr)) {
				PutField_CString(hContext,"psp_merchant_id",csPtr);
				PutField_CString(hResponse,"psp_merchant_id",csPtr);
DEBUGLOG(("ResendToPsp::GetPspDetail - psp_merchant id = [%s]\n",csPtr));
			}
			if (GetField_CString(myHash,"psp_channel_code",&csPspChannel)) {
DEBUGLOG(("ResendToPsp::GetPspDetail - channel_code  = [%s]\n",csPspChannel));
				strcpy(csBankCodeChannel,csPspChannel);
				PutField_CString(hContext,"psp_channel_code",csPspChannel);
				PutField_CString(hResponse,"psp_channel_code",csPspChannel);
			}
			if (GetField_CString(myHash,"overrided_bank_code_channel",&csPtr)) {
				strcpy(csBankCodeChannel,csPtr);
DEBUGLOG(("ResendToPsp::GetPspDetail overrided_bank_code_channel = [%s]\n",csBankCodeChannel));
			}
			csBankCodeChannel[strlen(csBankCodeChannel)]='\0';
		}
	}
	if(iChk == PD_OK){
////////get psp key 
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBPspKeys","GetPspKey");
		if (!(*DBObjPtr)(csPspId,PD_PTK_KEY_NAME,rRecordSet)) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"key_value",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_key = [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_key",csTmp);
				}
				if (GetField_CString(hRec,"key_id",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_key_id= [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_key_id",csTmp);
				}
				if (GetField_CString(hRec,"key_uid",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_key_uid= [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_key_uid",csTmp);
				}
				if (GetField_CString(hRec,"privatepem",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_privatepem= [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_privatepem",csTmp);
				}
				if (GetField_CString(hRec,"publiccert",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_publiccert= [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_publiccert",csTmp);
				}
				if (GetField_CString(hRec,"passphrase",&csTmp)) {
DEBUGLOG(("ResendToPsp:: GetPspKey - psp_passphrase= [%s]\n",csTmp));
                                        PutField_CString(hContext,"psp_passphrase",csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iChk = INT_ERR;
ERRLOG("TxnMgtByUsTRI::ResendToPsp::GetPspKey - no psp_key for [%s]\n",csPspId);
DEBUGLOG(("ResendToPsp::GetPspKey - no psp_key for [%s]\n",csPspId));
		}
	}

	if (iChk== PD_OK) {
////////get psp url
		hash_init(myHash,0);
		DBObjPtr = CreateObj(DBPtr,"DBPspUrl","GetPspUrl");
		if (!(*DBObjPtr)(csPspId,myHash)) {
			if (GetField_CString(myHash,"url",&csTmp)) {
				PutField_CString(hContext,"psp_url",csTmp);
DEBUGLOG(("ResendToPsp::GetPspUrl - psp_url = [%s]\n",csTmp));
			}
			else {
ERRLOG("TxnMgtByUsTRI::ResendToPsp::GetPspUrl - no such for [%s]\n",csPspId);
                                iChk = INT_ERR;
			}
		}
	}

	if (iChk== PD_OK) {
///////Get PSP Reqest Txn URL
		hash_init(myHash,0);
		DBObjPtr = CreateObj(DBPtr,"DBPspRequestTxnUrl","GetPspRequestTxnUrl");
		if (!(*DBObjPtr)(csPspId,csOrgTxnCode,csSelectedPayMethod, myHash)) {
			if (GetField_CString(myHash,"request_function",&csTmp)) {
				PutField_CString(hContext,"request_function",csTmp);
				PutField_CString(hResponse,"request_function",csTmp);
DEBUGLOG(("ResendToPsp: GetPspRequestTxnUrl - request_function = [%s]\n",csTmp));
			}
			else {
ERRLOG("ResendToPsp: GetPspRequestTxnUrl - no such function url for [%s] [%s]\n",csPspId,csOrgTxnCode);
                                iRet = INT_ERR;
			}
			if (GetField_CString(myHash,"action",&csTmp)) {
				PutField_CString(hContext,"action",csTmp);
				PutField_CString(hResponse,"action",csTmp);
DEBUGLOG(("ResendToPsp: GetPspRequestTxnUrl - action = [%s]\n",csTmp));
			}

			if(GetField_CString(myHash,"url_method",&csTmp)){
				PutField_CString(hContext,"url_method",csTmp);
				PutField_CString(hResponse,"url_method",csTmp);
DEBUGLOG(("ResendToPsp: GetPspRequestTxnUrl - url_method = [%s]\n",csTmp));
			}
		}

	}

//find FE
	if (iChk== PD_OK) {
		char cDirection='R';
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl");
		if ((unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet) == PD_OK){
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"fe_url",&csPtr)) {
DEBUGLOG(("ResendToPsp:: GetFeUrl - url only = [%s]\n",csPtr));
					PutField_CString(hResponse,"fe_url_only",csPtr);

					char *csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
					if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
						char* csTmpBuf;
						csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
						BOObjPtr = CreateObj(DBPtr,"BOSecurity","Encrypt3DESTxnSeq");
						(BOObjPtr)(csTmp,csTmpBuf);
DEBUGLOG(("ResendToPsp:: tmpbuf = [%s]\n",csTmpBuf));
						sprintf(csBuf,"%s?%s=%s",csPtr,PD_SESSION_ID,csTmpBuf);
						FREE_ME(csTmpBuf);
						PutField_CString(hContext,"fe_url",csBuf);
						PutField_CString(hResponse,"fe_url",csBuf);
DEBUGLOG(("ResendToPsp:: GetFeUrl - url = [%s]\n",csBuf));
					}
					FREE_ME(csBuf);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
			iChk= INT_ERR;
ERRLOG("TxnMgtByUsTRI::ResendToPsp: Unable to find FE URL for [%s][%s] Direction[%c]\n",csOrgTxnCode,csServiceCode,cDirection);
		}
	}

//check rpt url
	if (iChk== PD_OK) {
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnRptUrl","GetRptUrl");
		if ((unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csLanguage,csSelectedPayMethod,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"rpt_url",&csPtr)) {
DEBUGLOG(("ResendToPsp:: GetRptUrl - url only = [%s]\n",csPtr));
					PutField_CString(hResponse,"rpt_url_only",csPtr);

					char *csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
					if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
						char* csTmpBuf;
						csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
						BOObjPtr = CreateObj(DBPtr,"BOSecurity","Encrypt3DESTxnSeq");
						(BOObjPtr)(csTmp,csTmpBuf);
DEBUGLOG(("ResendToPsp:: tmpbuf = [%s]\n",csTmpBuf));
						sprintf(csBuf,"%s?%s=%s",csPtr,PD_SESSION_ID,csTmpBuf);
						FREE_ME(csTmpBuf);
						PutField_CString(hResponse,"rpt_url",csBuf);
DEBUGLOG(("ResendToPsp:: GetRptUrl - url = [%s]\n",csBuf));
					}
					FREE_ME(csBuf);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

//find BE
	if (iChk== PD_OK) {
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnBeUrl","GetBeUrl");
		if ((unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csPspId,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while(hRec){
				if (GetField_CString(hRec,"be_url",&csPtr)) {
DEBUGLOG(("ResendToPsp:: Return url: = [%s]\n",csPtr));
					char *csBuf = (char*)  malloc (PD_VALUE_LEN * 2 + 1);
					if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
						sprintf(csBuf,"%s?order_num=%s",csPtr,csTmp);
						PutField_CString(hContext,"return_url",csBuf);
						PutField_CString(hContext,"return_url_only",csPtr);
						PutField_CString(hResponse,"return_url_only",csPtr);
DEBUGLOG(("ResendToPsp:: Return url     : = [%s]\n",csBuf));
DEBUGLOG(("ResendToPsp:: Return url only: = [%s]\n",csPtr));
					}
					FREE_ME(csBuf);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
			iChk = INT_ERR;
ERRLOG("TxnMgtByUsTRI::ResendToPsp: Unable to find return BE URL for PSP ID[%s]\n",csPspId);
DEBUGLOG(("ResendToPsp:: Unable to find return BE URL for PSP ID[%s]\n",csPspId));
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(myHash);

///////////////////////////////////////////////
	
	if(iChk== PD_OK){
		if (GetField_CString(hContext,"bank_code",&csInternalBankCode)) {
DEBUGLOG(("ResendToPsp:: bank_code = [%s]\n",csInternalBankCode));
			PutField_CString(hContext,"internal_bank_code",csInternalBankCode);
			if (strcmp(csBankCodeChannel,PD_CHANNEL_TWV) &&
			    strcmp(csBankCodeChannel,PD_CHANNEL_PGEN)) {
				DBObjPtr = CreateObj(DBPtr,"DBBankMapping","i2eBankCodeMapping");
				if ((DBObjPtr)(csInternalBankCode,csBankCodeChannel,csTxnCountry,csOutBankCode)) {
DEBUGLOG(("ResendToPsp:: channel bank code = [%s]\n",csOutBankCode));
					PutField_CString(hResponse,"bank_code",csOutBankCode);
				}
				else {
DEBUGLOG(("ResendToPsp:: can't find channel bank code [%s] for channel [%s]\n",csInternalBankCode,csBankCodeChannel));
ERRLOG("TxnMgtByUsTRI:: ResendToPsp can't find channel bank code [%s] for channel [%s]\n",csInternalBankCode,csBankCodeChannel);
					iChk = INT_BANK_CODE_NOT_FOUND;
				}
			}
		}
	}

	if(iChk== PD_OK && (!strcmp(csPspChannel,PD_CHANNEL_51EPAY))){ 
DEBUGLOG(("ResendToPsp:: Format Sucess Resp\n"));
		char    csPspURL[PD_TMP_BUF_LEN + 1];
		char    csPostMethod[PD_URL_METHOD_LEN +1];

		DBObjPtr = CreateObj(DBPtr,"DBMobileBankUrl","GetBankUrl");
		if ((DBObjPtr)(csInternalBankCode,csPspURL,csPostMethod) == PD_OK) {
DEBUGLOG(("ResendToPsp:: PSP_URL = [%s]\n",csPspURL));
DEBUGLOG(("ResendToPsp:: post_method = [%s]\n",csPostMethod));
			PutField_CString(hResponse,"redirect_url",csPspURL);
			PutField_CString(hResponse,"post_method",csPostMethod);
		}
		else {
DEBUGLOG(("ResendToPsp:: PSP_URL not define\n"));
			iChk = INT_ERR;
		}
		if (GetField_CString(hContext,"sc",&csPtr)) {
			PutField_CString(hResponse,"sc",csPtr);
DEBUGLOG(("ResendToPsp:: sc = [%s]\n",csPtr));
		}

	}
///////////////////////////////////////////////	

	if (iChk == PD_OK && strcmp(csTmpTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
DEBUGLOG(("** PSP_ID = [%s]\n",csPspChannel));
		char* csMethod;
		char* csPspUrl;
		char* csRequestFunction;
		char  csTmpBuf[PD_TMP_BUF_LEN + 1];
		GetField_CString(hContext,"psp_url",&csPspUrl);
		GetField_CString(hContext,"request_function",&csRequestFunction);
		sprintf(csTmpBuf,"%s/%s",csPspUrl,csRequestFunction);
// don't override the redirect_url if twv or paygen///
		if (strcmp(csPspChannel,PD_CHANNEL_TWV) &&
		    strcmp(csPspChannel,PD_CHANNEL_PGEN) &&
		    strcmp(csPspChannel,PD_CHANNEL_51EPAY))
			PutField_CString(hResponse,"redirect_url",csTmpBuf);
DEBUGLOG(("redirect_url = [%s]\n",csTmpBuf));

		if (GetField_CString(hContext,"url_method",&csMethod)) {
DEBUGLOG(("url_method = [%s]\n",csMethod));
			PutField_CString(hResponse,"url_method",csMethod);
		}

		if (!strcmp(csPspChannel,PD_CHANNEL_HPAY) || !strcmp(csPspChannel,PD_CHANNEL_LKPAY)
				|| !strcmp(csPspChannel,PD_CHANNEL_HHPAY)
				|| !strcmp(csPspChannel,PD_CHANNEL_GOPAY)
				|| !strcmp(csPspChannel,PD_CHANNEL_HAIPAY)
				|| !strcmp(csPspChannel,PD_CHANNEL_HPAY_CNP)) {
			PutField_CString(hResponse,"recvenctype","01");
		}

////Generate PSP sign 
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","GeneratePspSign");
		iChk = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("BOSecurity->GeneratePspSign = [%d]\n",iChk));

	}

	if (iChk == PD_OK && strcmp(csTmpTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
DEBUGLOG(("Build Auth Data\n"));
		MsgObjPtr = CreateObj(MsgPtr,"WebMsg","BuildRespAuthData");
		iChk = (unsigned long)(*MsgObjPtr)(hResponse);
DEBUGLOG(("WebMsg->BuildRespAuthData = [%d]\n",iChk));
	}
	if(iChk == PD_OK && strcmp(csTmpTxnCode,PD_INITIAL_REQ_TXN_CODE)){
		PutField_CString(hResponse,"txn_code",PD_INITIAL_REQ_TXN_CODE);
		MsgObjPtr = CreateObj(MsgPtr,"WebMsg","FormatMsg");
		h_msg = (hex_t*) malloc (sizeof(hex_t));
		if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) == PD_OK) {

			PutField_CString(hResponse,"redirect_url",(const char*)h_msg->msg);
DEBUGLOG(("redirect_url = [%s][%d]\n",h_msg->msg, h_msg->len));

			FREE_ME(h_msg);
		}
		PutField_CString(hResponse,"txn_code",csTmpTxnCode);
		RemoveField_CString(hResponse,"org_txn_seq");
		RemoveField_CString(hResponse,"merchant_id");
		RemoveField_CString(hResponse,"txn_country");
		RemoveField_CString(hResponse,"psp_id");
	}

	if(iChk != PD_OK){
		iRet = iChk;
ERRLOG("ResendToPsp Failed!!\n");
	}
	else{
		RemoveField_Int(hContext,"internal_error");
	}

DEBUGLOG(("ResendToPsp::iRet = [%d]\n",iRet));
	return iRet;
}
*/
