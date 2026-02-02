/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/29              Cody Chan

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOlnOnUsCOM.h"
#include "myrecordset.h"
#include <math.h>

char cDebug;

void TxnOlnOnUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(BO);
OBJPTR(DB);
int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	char	*csPtr;
	char	*csBuf;
	char	*csTxnCode;
	char	*csOrgTxnCode;
	char	*csTxnCcy;
	char	*csChannelCode;
	char	*csTxnCountry;
	char*	csServiceCodeForURL=strdup("");
	char*	csServiceCode;
	char*	csLanguage;
	char*	csMerchantId;
	double	dTxnAmt = 0.0;
	long	lTmp;
	

DEBUGLOG(("TxnOlnOnUsCOM: Authroize()\n"));	
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant id[%s]\n",csMerchantId));
	}

/* field checking */

	GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("Authorize::txn_code Context[%s]\n",csTxnCode));

	if (GetField_CString(hResponse,"org_txn_code",&csOrgTxnCode)) {
DEBUGLOG(("Authorize::org_txn_code [%s]\n",csOrgTxnCode));
	}


	GetField_CString(hContext,"channel_code",&csChannelCode);
DEBUGLOG(("Authorize::channel_code Context[%s]\n",csChannelCode));

	
	if (strcmp(csTxnCode,PD_INITIAL_REQ_OLN_TXN_CODE)) {
        	if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("Authorize:: txn_country = [%s]\n",csTxnCountry));
        	}
		else  {
			iRet =	INT_TXN_COUNTRY_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() txn_country is missing\n"));
ERRLOG("Authorize() txn_country is missing\n");
		}

/*check currency code*/
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
				DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindCurrency");
				if ((unsigned long)(DBObjPtr)(csTxnCcy) == FOUND) {
DEBUGLOG(("Authorize() DBCurrency->FindCurrency [%s]success\n",csTxnCcy));
/* net ccy */
					PutField_CString(hContext,"net_ccy",csTxnCcy);
					PutField_CString(hContext,"org_txn_ccy",csTxnCcy);
				}
				else{
					iRet = INT_INVALID_CURRENCY_CODE;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Currency code invalid [%s]\n",csTxnCcy));
ERRLOG("TxnOlnOnUsCOM:Authorize() Currency code invalid\n");
				}
			}
			else{
				iRet = INT_CURRENCY_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Currency code not found\n"));
ERRLOG(("TxnOlnOnUsCOM:Authorize() Currency code not found\n"));
			}
		}

/*check pay amount*/
		if (iRet == PD_OK) {
			if(GetField_CString(hRequest,"txn_amt",&csTmp))
			{
				int iCheck = PD_FALSE;
DEBUGLOG(("Authorize()txn_amt from request[%s]\n",csTmp));
				iCheck = is_numeric(csTmp);
				if(iCheck==PD_FALSE){
					iRet =	INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnOlnOnUsCOM::Authorize() txn_amt Invalid\n");
				}	
				else {
					if(strlen(csTmp)>(PD_DIGIT_LEN+PD_DECIMAL_LEN)){
						iRet =	INT_INVALID_PAY_AMOUNT;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()txn_amt length too long[%s]\n",csTmp));
ERRLOG("TxnOlnOnUsCOM::Authorize() txn_amt length too long\n");
					}
					else{
						dTxnAmt = myctod((const unsigned char *)csTmp,strlen(csTmp) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
						PutField_Double(hContext,"txn_amt",dTxnAmt);
						PutField_Double(hContext,"org_txn_amt",dTxnAmt);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTxnAmt));

						if (dTxnAmt <= 0) {
							iRet = INT_INVALID_PAY_AMOUNT;
							PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() txn_amt cannot be zero\n"));
ERRLOG("TxnOlnOnUsCOM::Authorize() txn_amt cannot be zero\n");
						}
					}
				}
/* if TWD */
				if (iRet==PD_OK) {
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() check is support decimal\n"));
					DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
					if ((unsigned long)((DBObjPtr)(csTxnCcy))!=PD_TRUE){
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() [%s] doesn't support decimal\n",csTxnCcy));
						lTmp = (long) dTxnAmt;
						if (dTxnAmt > lTmp) {
							iRet = INT_UNSUPPORTED_PAY_AMOUNT;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
						}
					}
				}
/* if TW */
				if(iRet==PD_OK){
					if(!strcmp(csTxnCountry,PD_TAIWAN)){
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() [%s] doesn't support decimal\n",csTxnCountry));
						lTmp = (long) dTxnAmt;
						if (dTxnAmt > lTmp) {
							iRet = INT_UNSUPPORTED_PAY_AMOUNT;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
						}
					}
				}


/*************************/
			}
			else {
				iRet = INT_PAY_AMOUNT_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() txn_amt not found\n"));
ERRLOG(("TxnOlnOnUsCOM:Authorize() txn_amt not found\n"));
			}	
		}


/*check reference*/

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"merchant_ref",&csTmp)){
DEBUGLOG(("Authorize() merchant_ref = [%s]\n",csTmp));
				}
			else{
				iRet = INT_REFERENCE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()reference not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() reference not found\n"));
			}
		}

/*check time*/

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"transmission_datetime",&csTmp)){
DEBUGLOG(("Authorize()transmission_datetime = [%s]\n",csTmp));
				if(check_valid_datetime(csTmp)!=PD_OK){
					iRet = INT_TRASMISSION_TIME_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()transmission_datetime invalid\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() transmission_datetime invalid\n"));
				}
			}
			else{
				iRet = INT_TRASMISSION_TIME_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()transmission_datetime not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() transmission_datetime not found\n"));
			}
		}

	}

	if (!strcmp(csTxnCode,PD_INITIAL_OLN_TXN_CODE) ||
		!strcmp(csTxnCode,PD_INITIAL_OLN_TXN_M2_CODE)) {


/* check service code */
                if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
                        PutField_CString(hContext,"service_code",csServiceCode);
                        csServiceCodeForURL = strdup(csServiceCode);
DEBUGLOG(("Authorize() service_code = [%s]\n",csServiceCode));
                }
                else {
DEBUGLOG(("Authorize() service code not found!!!\n"));
ERRLOG("TxnOlnOnUsCOM::Authorize() service code not found!!!\n");
                        iRet = INT_SERVICE_CODE_MISSING;
                        PutField_Int(hContext,"internal_error",iRet);
                }

/* check pay method */
		if (!strcmp(csTxnCode, PD_INITIAL_OLN_TXN_CODE) ||
			!strcmp(csTxnCode,PD_INITIAL_OLN_TXN_M2_CODE)) {
			if (GetField_CString(hRequest, "pay_method", &csTmp)) {
				int iMaxField = (int)(PD_PAY_METHOD_LIST_LEN / PD_PAY_METHOD_LEN);
				char csList[iMaxField][PD_PAY_METHOD_LEN];
				char csSelectedMethod[PD_PAY_METHOD_LEN];
				char *p;
				int iFieldCnt = 0;
				int iValidCnt = 0;
				int i;

				p = strtok(csTmp, ", ");
				while (p != NULL) {
					strcpy(csList[iFieldCnt], p);
					csList[iFieldCnt][strlen(p)] = '\0';
					p = strtok (NULL, ", ");
					iFieldCnt++;
				}

				for (i = 0; i < iFieldCnt; i++) {
					DBObjPtr = CreateObj(DBPtr, "DBServicePayMethod", "IsServicePayMethodSupported");
					if ((unsigned long)(DBObjPtr)(csServiceCode, csList[i]) == PD_TRUE) {
						iValidCnt++;
						strcpy(csSelectedMethod, csList[i]);
					}
				}

				if (iValidCnt == 1) {
					PutField_CString(hContext, "selected_pay_method", csSelectedMethod);
DEBUGLOG(("Authorize() pay_method selected [%s]\n", csSelectedMethod));
				} else if (iValidCnt == 0) {
					iRet = INT_UNSUPPORTED_PAY_METHOD;
					PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() pay_method invalid\n"));
ERRLOG(("TxnOlnOnUsCOM:: Authorize() pay_method invalid\n"));
				} else {
DEBUGLOG(("Authorize() more than one pay_method\n"));
				}
			} else {
				hash_t *hRec;
				recordset_t *rRecordSet;
				rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
				recordset_init(rRecordSet,0);
				char csSelectedMethod[PD_PAY_METHOD_LEN];
				int iCnt = 0;

				DBObjPtr = CreateObj(DBPtr, "DBServicePayMethod", "FindPayMethod");
				if ((unsigned long)(DBObjPtr)(csServiceCode, rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {
						if (GetField_CString(hRec, "pay_method", &csTmp)) {
							strcpy(csSelectedMethod, csTmp);
							iCnt++;
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}

					if (iCnt == 1) {
						PutField_CString(hContext, "selected_pay_method", csSelectedMethod);
DEBUGLOG(("Authorize() pay_method selected [%s]\n", csSelectedMethod));
					} else if (iCnt == 0) {
						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() cannot find pay_method from service [%s]\n", csServiceCode));
ERRLOG(("TxnOlnOnUsCOM::Authorize() cannot find pay_method from service\n"));
					}
				}

				RecordSet_Destroy(rRecordSet);
				FREE_ME(rRecordSet);
			}
		}

	}
	else if (!strcmp(csTxnCode,PD_WITHDRAW_TXN_CODE)||
		 !strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH)) {
/*check bank code*/
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"bank_code",&csTmp)){
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() bank_code = [%s]\n",csTmp));
			}
			else{
				iRet = INT_BANK_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_code not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() bank_code not found\n"));
			}
		}
/* bank branch name */
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"branch_name",&csTmp)){
DEBUGLOG(("Authorize() branch_name = [%s]\n",csTmp));
			}
			else{
				iRet = INT_BRANCH_NAME_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() branch_name not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() branch_name not found\n"));
			}
		}
/* bank account id */
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"account_id",&csTmp)){
DEBUGLOG(("Authorize() account_id = [%s]\n",csTmp));
			}
			else{
				iRet = INT_BANK_AC_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() account_id not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() account_id not found\n"));
			}
		}
/* bank account name */
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"account_name",&csTmp)){
DEBUGLOG(("Authorize() account_name =[%s]\n",csTmp));
			}
			else{
				iRet = INT_BANK_AC_NAME_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() account_NAME not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() account_NAMEid not found\n"));
			}
		}
/* identity id */
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"identity_id",&csTmp)){
DEBUGLOG(("Authorize() identity_id = [%s]\n",csTmp));
			}
			else{
				iRet = INT_IDENTITY_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() identity_id not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() identity_id not found\n"));
			}
		}
	}

/*check language*/
	if(GetField_CString(hResponse,"org_language",&csTmp)){
DEBUGLOG(("Authorize() language =[%s]\n",csTmp));
		csLanguage = strdup(csTmp);
		PutField_CString(hResponse,"language",csLanguage);
	}
	else if(GetField_CString(hRequest,"language",&csTmp)){
DEBUGLOG(("Authorize() language =[%s]\n",csTmp));
		csLanguage = strdup(csTmp);
		PutField_CString(hResponse,"language",csLanguage);
	}
	else{
		PutField_CString(hResponse,"language",PD_DEF_LANGUAGE);
		csLanguage = strdup(PD_DEF_LANGUAGE);
DEBUGLOG(("Authorize() DEF language =[%s]\n",csLanguage));
	}

	if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) &&
	    strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH) &&
	    strcmp(csTxnCode,PD_INITIAL_REQ_OLN_TXN_CODE)) {
/*check url*/
		if(iRet == PD_OK){
			if (strcmp(csTxnCode, PD_INITIAL_OLN_TXN_M2_CODE)) {

				if(GetField_CString(hRequest,"success_url",&csTmp)){
DEBUGLOG(("Authorize() success_url =[%s]\n",csTmp));
				}
				else{
					iRet = INT_SUCC_URL_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() success_url not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() success_url not found\n"));
				}
			}
		}

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"success_callback_url",&csTmp)){
DEBUGLOG(("Authorize() success_callback_url =[%s]\n",csTmp));
			}
			else{
				iRet = INT_SUCC_CB_URL_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() success_callback_url not found\n"));
ERRLOG(("TxnOlnOnUsCOM::Authorize() success_callback_url not found\n"));
			}
		}
	}


/*******************/

	if (strcmp(csTxnCode,PD_INITIAL_REQ_OLN_TXN_CODE)) {

		if ( iRet == PD_OK) {
/* Check Merchant */
DEBUGLOG(("Authorize() call BOOLMerchant->GetMerchantTxnInfo\n"));
                        BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                        iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo = [%d]\n",iRet));

                }
/* skipcheck for WTB */
		if (iRet == PD_OK) {
			if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) &&
			    strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH) &&
			    strcmp(csTxnCode,PD_INITIAL_OLN_TXN_M2_CODE)) {
			

				GetField_CString(hRequest,"txn_country",&csTxnCountry);
DEBUGLOG(("Authorize() country = [%s]\n",csTxnCountry));

//find FE url
				hash_t  *hRec;
       	 			recordset_t     *rRecordSet;
       	 			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
       	 			recordset_init(rRecordSet,0);
				char cDirection;

DEBUGLOG(("Authorize() try to call find FE URL\n"));

				if (strcmp(csTxnCode,PD_INITIAL_TXN_CODE))
					cDirection=PD_TXN_RESPONSE;
				else
					cDirection=PD_TXN_REQUEST;

				DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl");
				if ((unsigned long)(DBObjPtr)(csTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while(hRec){
						if (GetField_CString(hRec,"domain",&csPtr)) {
							PutField_CString(hContext,"fe_domain",csPtr);
DEBUGLOG(("Authorize() GetFeUrl - domain = [%s]\n",csPtr));
						}
						if (GetField_CString(hRec,"fe_url",&csPtr)) {
DEBUGLOG(("Authorize() GetFeUrl - url only = [%s]\n",csPtr));
							PutField_CString(hResponse,"fe_url_only",csPtr);

							csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
							if (GetField_CString(hContext,"txn_seq",&csTmp)) {
								char*	csTmpBuf;
								csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
								BOObjPtr = CreateObj(BOPtr,"BOSecurity","Encrypt3DESTxnSeq");
								(BOObjPtr)(csTmp,csTmpBuf);
DEBUGLOG(("Authroize tmpbuf = [%s]\n",csTmpBuf));
								sprintf(csBuf,"%s?%s=%s",csPtr,PD_SESSION_ID,csTmpBuf);
								PutField_CString(hResponse,"fe_url",csBuf);
								FREE_ME(csTmpBuf);
DEBUGLOG(("Authorize() GetFeUrl - url = [%s]\n",csBuf));
							}
               	               		          	iRet = PD_OK;
							FREE_ME(csBuf);
               	               		  	}
               	               		  	hRec = RecordSet_GetNext(rRecordSet);
					}
				}
				else{
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() Unable to find FE URL for [%s][%s][%s] Direction[%c]\n",csTxnCode,csServiceCode,csTxnCountry,cDirection);
				}
			
				RecordSet_Destroy(rRecordSet);
       				FREE_ME(rRecordSet);
			}
		}
		if(iRet == PD_OK){
			if (!strcmp(csTxnCode,PD_INITIAL_OLN_TXN_M2_CODE)) {
				char	cDepositFlow;
				if (GetField_Char(hRequest,"deposit_flow",&cDepositFlow)) {
DEBUGLOG(("deposit_flow = [%c]\n",cDepositFlow));
				}
				else {
					iRet = INT_DEPOSIT_FLOW_MISSING;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() deposit_flow is missing from request\n");
				}

/* cust deposit date */
				if (iRet == PD_OK) {
					if (cDepositFlow == PD_DEPOSIT_FLOW_TYPE_1) {
						if (GetField_CString(hRequest,"cust_deposit_datetime",&csPtr)) {
DEBUGLOG(("cust_deposit_date = [%s]\n",csPtr));
						}
						else {
							iRet = INT_CUST_DEPOSIT_DATE_MISSING;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() cust_deposit_date is missing from request\n");
						}
					} 

					// check valid date
					if (GetField_CString(hRequest, "cust_deposit_datetime", &csPtr)) {
						if (strlen(csPtr) != 12) {
							iRet = INT_INVALID_TXN;
							PutField_Int(hContext, "internal_error", iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() cust_deposit_date invalid\n");
						} else {
							strcat(csPtr, "00");
							if (check_valid_datetime(csPtr) != PD_OK) {
                                        			iRet = INT_INVALID_TXN;
                                        			PutField_Int(hContext, "internal_error", iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() cust_deposit_date invalid\n");
                                			}
						}
					}
				}
/* bank_acct_num */
				if (iRet == PD_OK) {
					if (GetField_CString(hRequest,"bank_acct_num",&csPtr)) {
DEBUGLOG(("bank_acct_num = [%s]\n",csPtr));
					}
					else {
						iRet = INT_BANK_ACCT_NUM;
						PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() bank_acct_num is missing from request\n");
					}
				}
/* deposit bank */
				if (iRet == PD_OK) {
					if (GetField_CString(hRequest,"deposit_bank",&csPtr)) {
DEBUGLOG(("deposit_bank = [%s]\n",csPtr));
					}
					else {
						iRet = INT_DEPOSIT_BANK_MISSING;
						PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOlnOnUsCOM::Authorize() deposit_bank is missing from request\n");
					}
				}


			}
		}

	}
	else  {
/************************************ ODR */
		if (!GetField_CString(hResponse,"service_code",&csServiceCode)) {
DEBUGLOG(("Authorize() service code not found\n"));
DEBUGLOG(("TxnOlnOnUsCOM [%s]Authorize() service code not found\n",csTxnCode));
			iRet = PD_ERR;
		}

		char*	csSelectedPayMethod;
		if (GetField_CString(hContext,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() selected_pay_method = [%s]\n",csSelectedPayMethod));
		}
		if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() txn_ccy = [%s]\n",csTxnCcy));
                }
                else if(GetField_CString(hContext,"org_txn_ccy",&csTxnCcy)){
DEBUGLOG(("TxnOlnOnUsCOM::Authorize() org_txn_ccy = [%s]\n",csTxnCcy));
                }

/*
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call BOTxnLimit->TxnLimit\n"));
 			BOObjPtr = CreateObj(BOPtr,"BOTxnLimit","TxnLimit");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOTxnLimit->TxnLimit = [%d]\n",iRet));
		}
*/
	}



	FREE_ME(csServiceCodeForURL);
	FREE_ME(csLanguage);
DEBUGLOG(("TxnOlnOnUsCOM:: exit = [%d]\n",iRet));
	return iRet;
}
