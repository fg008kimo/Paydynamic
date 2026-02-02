/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/08/31              Cody Chan
Add ESKYPAY support				   2011/01/10		   Cody Chan
call DBService,DBTxnBeUrl->FindURL		   2011/02/14		   LokMan Chow
don't get FE URL if CMP				   2011/11/10		   Cody Chan
check limit before bank selection		   2013/03/19		   Stan Poon
check merchant support delta amount		   2013/04/09		   LokMan Chow
replace DBTxnBeUrl:FindURL by GetBeUrl		   2013/04/23		   LokMan Chow
Check Magic num and Magic Word if exist		   2013/08/21		   Cody Chan
Add Create BO Customer Group 			   2013/09/10		   Cody Chan
Support to get FE URL with New UI		   2013/10/03		   LokMan Chow
Add code for switching service VNC<->VHS	   2013/10/04		   LokMan Chow
remove auto switch and add check vp group	   2013/10/16		   LokMan Chow
Handle Non CCY Recal Fee                           2017/05/24              Virginia Yun
PRD052 check customer blacklist			   2018/04/06		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsCOM.h"
#include "myrecordset.h"
#include <math.h>

char cDebug;

void TxnWebOnUsCOM(char    cdebug)
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
	//char	csVal[PD_VALUE_LEN +1];
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
	char*	csPspId;
	char*	csMerchantId;
	char    *csPspCcy;
        char    csOrgTxnSeq[PD_TXN_SEQ_LEN +1];
	//char*	csIpAddr;
	char	cTmp;
	double	dTxnAmt = 0.0;
	double	dDeltaAmt = 0.0;
	double	dDeltaAmtLow = 0.0;
	double  dTmp= 0.0;
	long	lTmp;
	int	iTmp = 0;
	char*	csMagicNum = NULL;
	char*	csMagicWord = NULL;
	char*	csClientId = NULL;
	char*	csCustomerId = NULL;
	int	iVPGrpId = -1;
	char	cStatus = PD_VP_CLOSE;
	//char	csTag[PD_TAG_LEN+1];
	//char*	csPriService;
	//char*	csToService;
	int	iVPErr = PD_FALSE;

DEBUGLOG(("TxnWebOnUsCOM: Authroize()\n"));	
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant id[%s]\n",csMerchantId));
	}

/* Voucher Payment Check*/
	if(GetField_CString(hRequest,"magic_num",&csMagicNum)){
DEBUGLOG(("Authorize::magic number from request[%s]\n",csMagicNum));
		if(GetField_CString(hRequest,"magic_word",&csMagicWord)) {
DEBUGLOG(("Authorize::magic word from request[%s]\n",csMagicWord));
		}
		else {
			PutField_Int(hContext,"internal_error",INT_INVALID_MAGIC_NUM);
			iRet = INT_INVALID_MAGIC_NUM;
DEBUGLOG(("Authorize::magic word not found\n"));
ERRLOG("TxnWebOnUsCOM::Authorize::magic word not found\n");
		}

		if (iRet == PD_OK) {
			hash_t  *hRec;
			recordset_t     *rRecordSet;
        		rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        		recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchant");
                	if ((*DBObjPtr)(csMerchantId,
                        	 rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {
					if (GetField_CString(hRec,"merchant_client_id",&csClientId)) {
DEBUGLOG(("merchant_client_id = [%s]\n",csClientId));

						break;
                                        }
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
DEBUGLOG(("Authorize:: call GetMerchantInfo Error\n"));
ERRLOG("Authorize:: call GetMerchantInfo Error\n");
				PutField_Int(hContext,"internal_error",INT_INVALID_MAGIC_NUM);
				iRet = INT_INVALID_MAGIC_NUM;
			}

			FREE_ME(rRecordSet);

			if (iRet == PD_OK) {
				/*
				char	csTmp[PD_MAGIC_CUST_ID_LEN+1];
				//csTmp = (char*) malloc (PD_TMP_BUF_LEN +1 );
				DBObjPtr = CreateObj(DBPtr,"DBClientMagic","GetCustomerIdByMagic");
                		if ((*DBObjPtr)(csClientId,csMagicNum,csMagicWord,csTmp) != PD_OK) {
DEBUGLOG(("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId));
ERRLOG("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId);
					PutField_Int(hContext,"internal_error",INT_INVALID_MAGIC_NUM);
					iRet = INT_INVALID_MAGIC_NUM;
				}
				else{
					PutField_CString(hContext,"customer_id",csTmp);
DEBUGLOG(("Authorize:: customer id found[%s]\n",csTmp));
				}
				*/

				hash_t *hMagic;
				hMagic = (hash_t*) malloc (sizeof(hash_t));
				hash_init(hMagic, 0);
				int	iTmpDisabled = PD_TRUE;

				DBObjPtr = CreateObj(DBPtr,"DBClientMagic","GetClientMagic");
                                if ((*DBObjPtr)(csClientId, csMagicNum, csMagicWord, hMagic ) != PD_OK) {

DEBUGLOG(("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId));
ERRLOG("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId);

                                        PutField_Int(hContext,"internal_error",INT_INVALID_MAGIC_NUM);
                                        iRet = INT_INVALID_MAGIC_NUM;
					iVPErr = PD_TRUE;
                                }
                                else{
					if (GetField_Int(hMagic, "magic_disabled", &iTmpDisabled)) {
DEBUGLOG(("Authorize:: Magic Disabled [%d]\n", iTmpDisabled));
					}

					if (iTmpDisabled == PD_TRUE) {

DEBUGLOG(("Authorize:: Magic num [%s][%s] disabled!\n", csMagicNum, csMagicWord));
ERRLOG("Authorize:: Magic num [%s][%s] disabled!\n", csMagicNum,csMagicWord);

	                                        PutField_Int(hContext,"internal_error", INT_CUSTOMER_ACCT_DISABLED);
						iRet = INT_CUSTOMER_ACCT_DISABLED;
						iVPErr = PD_TRUE;
					} else {
						if (GetField_CString(hMagic, "customer_id", &csCustomerId)) {
	                                        	PutField_CString(hContext,"customer_id",csCustomerId);
DEBUGLOG(("Authorize:: customer id found[%s]\n",csCustomerId));
						} else {

DEBUGLOG(("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId));
ERRLOG("Authorize:: Magic num [%s][%s] not found for client id [%s]\n",csMagicNum,csMagicWord,csClientId);

							PutField_Int(hContext,"internal_error",INT_INVALID_MAGIC_NUM);
							iRet = INT_INVALID_MAGIC_NUM;
							iVPErr = PD_TRUE;
						}

						if (GetField_Int(hMagic, "txn_gp_id", &iVPGrpId)) {
DEBUGLOG(("Authorize:: VPGrpId [%d]\n",iVPGrpId));
	                                        	PutField_Int(hContext,"txn_gp_id",iVPGrpId);
							//iRet = INT_VP_GROUP_CLOSED;
							DBObjPtr = CreateObj(DBPtr,"DBClientMagicGpStatus","GetStatus");
							if ((*DBObjPtr)(csClientId, iVPGrpId, &cStatus) == PD_OK) {
DEBUGLOG(("Authorize: VP Status [%c]\n", cStatus));
								if(cStatus == PD_VP_OPEN){
									iRet = PD_OK;
								} else {
									iRet = INT_VP_GROUP_CLOSED;
	                                        			PutField_Int(hContext,"internal_error", INT_VP_GROUP_CLOSED);
									iVPErr = PD_TRUE;
								}
							}
						}
						else{
							iRet = INT_VP_GROUP_CLOSED;
							PutField_Int(hContext,"internal_error", INT_VP_GROUP_CLOSED);
							iVPErr = PD_TRUE;
						}
					}
                                }
				


				hash_destroy(hMagic);
				FREE_ME(hMagic);
			}
		}
	}
/* end of voucher payment */

/* field checking */

	GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("Authorize::txn_code Context[%s]\n",csTxnCode));

	if (GetField_CString(hResponse,"org_txn_code",&csOrgTxnCode)) {
DEBUGLOG(("Authorize::org_txn_code [%s]\n",csOrgTxnCode));
	}


	GetField_CString(hContext,"channel_code",&csChannelCode);
DEBUGLOG(("Authorize::channel_code Context[%s]\n",csChannelCode));

	
	if (strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
        	if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("Authorize:: txn_country = [%s]\n",csTxnCountry));
        	}
		else 
			csTxnCountry = strdup("");

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
ERRLOG("TxnWebOnUsCOM:Authorize() Currency code invalid\n");
				}
			}
			else{
				iRet = INT_CURRENCY_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Currency code not found\n"));
ERRLOG(("TxnWebOnUsCOM:Authorize() Currency code not found\n"));
			}
		}

/*check pay amount*/
		if (iRet == PD_OK || iVPErr == PD_TRUE) {
			if(GetField_CString(hRequest,"txn_amt",&csTmp))
			{
				int iCheck = PD_FALSE;
DEBUGLOG(("Authorize()txn_amt from request[%s]\n",csTmp));
				iCheck = is_numeric(csTmp);
				if(iCheck==PD_FALSE){
					iRet =	INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnWebOnUsCOM::Authorize() txn_amt Invalid\n");
				}	
				else {
					if(strlen(csTmp)>(PD_DIGIT_LEN+PD_DECIMAL_LEN)){
						iRet =	INT_INVALID_PAY_AMOUNT;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()txn_amt length too long[%s]\n",csTmp));
ERRLOG("TxnWebOnUsCOM::Authorize() txn_amt length too long\n");
					}
					else{
						dTxnAmt = myctod((const unsigned char *)csTmp,strlen(csTmp) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
						PutField_Double(hContext,"txn_amt",dTxnAmt);
						PutField_Double(hContext,"org_txn_amt",dTxnAmt);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTxnAmt));
					}
				}
/* if TWD */
				if (iRet==PD_OK) {
DEBUGLOG(("TxnWebOnUsCOM::Authorize() check is support decimal\n"));
					DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
					if ((unsigned long)((DBObjPtr)(csTxnCcy))!=PD_TRUE){
DEBUGLOG(("TxnWebOnUsCOM::Authorize() [%s] doesn't support decimal\n",csTxnCcy));
						lTmp = (long) dTxnAmt;
						if (dTxnAmt > lTmp) {
							iRet = INT_UNSUPPORTED_PAY_AMOUNT;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnWebOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
						}
					}
				}
/* if TW */
				if(iRet==PD_OK){
					if(!strcmp(csTxnCountry,PD_TAIWAN)){
DEBUGLOG(("TxnWebOnUsCOM::Authorize() [%s] doesn't support decimal\n",csTxnCountry));
						lTmp = (long) dTxnAmt;
						if (dTxnAmt > lTmp) {
							iRet = INT_UNSUPPORTED_PAY_AMOUNT;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnWebOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
						}
					}
				}


/*************************/
			}
			else {
				iRet = INT_PAY_AMOUNT_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() txn_amt not found\n"));
ERRLOG(("TxnWebOnUsCOM:Authorize() txn_amt not found\n"));
			}	
		}

/* check txn control */
/*
		if (iRet == PD_OK) {
			double dTxnAmt;
			double dLimit;
			if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
				DBObjPtr = CreateObj(DBPtr,"DBTxnControl","FindTxnControl");
				if ((unsigned long) (DBObjPtr)(csChannelCode,
					csTxnCode,
					csTxnCountry,
					csTxnCcy,
					&dLimit) == PD_FOUND) {
DEBUGLOG(("TxnWebOnUsCOM:Authorize() txn control limit = [%f]\n",dLimit));
					if (dLimit > 0.0) {
						if (dLimit > dTxnAmt) {
DEBUGLOG(("TxnWebOnUsCOM:Authorize() INT_INVALID_PAY_AMOUNT too small min*[%f] > Txn Amt[%f]\n",dLimit,dTxnAmt)); 
ERRLOG("TxnWebOnUsCOM:Authorize() INT_INVALID_PAY_AMOUNT too small min*[%f] > [%f]\n",dLimit,dTxnAmt); 
							iRet = INT_INVALID_PAY_AMOUNT;
							PutField_Int(hContext,"internal_error",INT_INVALID_PAY_AMOUNT);
						}
					}
				}
			}
		}
*/

/*check reference*/

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"merchant_ref",&csTmp)){
DEBUGLOG(("Authorize() merchant_ref = [%s]\n",csTmp));
				}
			else{
				iRet = INT_REFERENCE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()reference not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() reference not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() transmission_datetime invalid\n"));
				}
			}
			else{
				iRet = INT_TRASMISSION_TIME_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()transmission_datetime not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() transmission_datetime not found\n"));
			}
		}

	}

	if (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE) ||
	    !strcmp(csTxnCode,PD_INITIAL_TXN_CODE) || 
	    !strcmp(csTxnCode,PD_MOBILE_DSP_CODE)) {

		//char *csCountry = NULL;
		//char csBankCode[PD_BANK_CODE_LEN+1];

/* check service code */
                if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
                        PutField_CString(hContext,"service_code",csServiceCode);
                        csServiceCodeForURL = strdup(csServiceCode);
DEBUGLOG(("Authorize() service_code = [%s]\n",csServiceCode));
                }
                else {
DEBUGLOG(("Authorize() service code not found!!!\n"));
ERRLOG("TxnWebOnUsCOM::Authorize() service code not found!!!\n");
                        iRet = INT_SERVICE_CODE_MISSING;
                        PutField_Int(hContext,"internal_error",iRet);
                }

/*convert bank code*/
/*
		if(iRet == PD_OK){

			int iChk = 0;
                        DBObjPtr = CreateObj(DBPtr,"DBService","IsSelectBank");
                        iChk= (unsigned long)(DBObjPtr)(csServiceCode);
                        if(iChk == PD_ERR){
                                iRet = INT_ERR;
                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() check IsSelectBank Error!!!\n"));
ERRLOG("TxnWebOnUsCOM::Authorize() check IsSelectBank Error!!!\n");
                        }
                        else if(iChk == PD_TRUE) {
				if(GetField_CString(hRequest,"bank_code",&csTmp)){
DEBUGLOG(("Authorize() bank_code =[%s]\n",csTmp));
					GetField_CString(hRequest,"txn_country",&csCountry);
DEBUGLOG(("Authorize() txn_country =[%s]\n",csCountry));

					DBObjPtr = CreateObj(DBPtr,"DBBankMerchantMapping","e2iBankCodeMapping");
					if ((unsigned long)(DBObjPtr)(csTmp,csMerchantId,csCountry,csBankCode) == FOUND) {
						//PutField_CString(hContext,"internal_bank_code",csBankCode);
						PutField_CString(hContext,"bank_code",csBankCode);
DEBUGLOG(("Authorize() internal_bank_code found [%s]\n",csBankCode));
					}
					else{
						iRet = INT_BANK_CODE_NOT_FOUND;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()  bank_code not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() bank_code not found\n"));
					}
				}
				else{
DEBUGLOG(("Authorize()  bank_code not found\n"));
					char *csCmd=(char*) malloc(PD_MAX_FILE_LEN  +1);
					sprintf(csCmd,"warn_bankcode.sh %s %s", csTmp,csMerchantId);
					system(csCmd);
					FREE_ME(csCmd);
				}
			}
		}
*/
/******** re????? ****
		if(iRet == PD_OK && !strcmp(csChannelCode,PD_CHANNEL_XPAY)){
			if(GetField_CString(hRequest,"pay_method",&csTmp)){
				PutField_CString(hContext,"selected_pay_method",csTmp);
DEBUGLOG(("Authorize() pay_method =[%s]\n",csTmp));
			}
			else{
				iRet = INT_PAYMETHOD_NOT_FOUND;
				PutField_Int(hContext,"internal_error",INT_PAYMETHOD_NOT_FOUND);
DEBUGLOG(("Authorize()  pay_method not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() pay_method not found\n"));
			}
		}
************/
/* check pay method for DSI */
/***********************************/
		if (!strcmp(csTxnCode,PD_INITIAL_TXN_CODE)
	  	 || !strcmp(csTxnCode,PD_MOBILE_DSP_CODE)) {
			if (GetField_CString(hRequest,"pay_method",&csTmp)) {
				int iMaxField = (int)(PD_PAY_METHOD_LIST_LEN/PD_PAY_METHOD_LEN);
				char csList[iMaxField][PD_PAY_METHOD_LEN];
				char csSelectedMethod[PD_PAY_METHOD_LEN];
				char *p;
				int iFieldCnt = 0;
				int iValidCnt = 0;
				int i;

				p = strtok (csTmp,",");
				while (p != NULL)
				{
					strcpy(csList[iFieldCnt],p);
					csList[iFieldCnt][strlen(p)]='\0';
					p = strtok (NULL,",");
					iFieldCnt++;
				}

				for(i=0;i<iFieldCnt;i++){
					DBObjPtr = CreateObj(DBPtr,"DBServicePayMethod","IsServicePayMethodSupported");
					if ((unsigned long)(DBObjPtr)(csServiceCode,csList[i]) == PD_TRUE) {
						iValidCnt++;
						strcpy(csSelectedMethod,csList[i]);
					}
				}
				if(iValidCnt==1){
					PutField_CString(hContext,"selected_pay_method",csSelectedMethod);
DEBUGLOG(("Authorize() pay_method selected[%s]\n",csSelectedMethod));
				}
				else if(iValidCnt==0){
					iRet = INT_UNSUPPORTED_PAY_METHOD;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() pay_method invalid\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() pay_method invalid\n"));
				}
				else{
DEBUGLOG(("Authorize() more than one pay_method\n"));
				}
			}
			else{
				hash_t	*hRec;
				recordset_t     *rRecordSet;
				rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
				recordset_init(rRecordSet,0);
				char csSelectedMethod[PD_PAY_METHOD_LEN];
				int iCnt = 0;

				DBObjPtr = CreateObj(DBPtr,"DBServicePayMethod","FindPayMethod");
				if ((unsigned long)(DBObjPtr)(csServiceCode,rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while(hRec){
						if (GetField_CString(hRec,"pay_method",&csTmp)) {
							strcpy(csSelectedMethod,csTmp);
							iCnt++;
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
					if(iCnt==1){
						PutField_CString(hContext,"selected_pay_method",csSelectedMethod);
DEBUGLOG(("Authorize() pay_method selected[%s]\n",csSelectedMethod));
					}
					else if(iCnt==0){
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() cannot find pay_method from service[%s]\n",csServiceCode));
ERRLOG(("TxnWebOnUsCOM::Authorize() cannot find pay_method from service\n"));
					}
				}

				RecordSet_Destroy(rRecordSet);
				FREE_ME(rRecordSet);
			}
		}


/*check show paypage*/
		if(iRet == PD_OK){
			if(GetField_Char(hRequest,"show_paypage",&cTmp)){
				if((cTmp='N') || (cTmp='Y')){
DEBUGLOG(("Authorize() show paypage = [%c]\n",cTmp));
				}
				else{
					iRet = INT_INVALID_SHOW_PAYPAGE;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() show paypage invalid [%c]\n", cTmp));
ERRLOG("TxnWebOnUsCOM::Authorize() show paypage invalid\n");
				}
			}
			else{
/*				iRet = INT_SHOW_PAYPAGE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",INT_SHOW_PAYPAGE_NOT_FOUND);
*/
DEBUGLOG(("Authorize() show paypage not found\n"));
//ERRLOG(("TxnWebOnUsCOM::Authorize() show paypage not found\n"));
			}
		}
/* check selected pid */
		if (iRet == PD_OK) {
			if(GetField_CString(hRequest,"selected_pid",&csTmp)){
DEBUGLOG(("Authorize() ***selected_pid = [%s]\n",csTmp));
				BOObjPtr = CreateObj(BOPtr,"BOPsp","CheckPspStatus");
				if ((unsigned long)(*BOObjPtr)(csTmp) != PD_OK) {
					iRet = INT_PSP_NOT_AVAILABLE;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() selected_pid not open\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() selected_pid not open\n"));
				}
			}
		}
	}
	else if (!strcmp(csTxnCode,PD_WITHDRAW_TXN_CODE)||
		 !strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH)) {
/*check bank code*/
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"bank_code",&csTmp)){
DEBUGLOG(("TxnWebOnUsCOM::Authorize() bank_code = [%s]\n",csTmp));
			}
			else{
				iRet = INT_BANK_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() bank_code not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() bank_code not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() branch_name not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() account_id not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() account_NAMEid not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() identity_id not found\n"));
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
	    strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
/*check url*/
		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"success_url",&csTmp)){
DEBUGLOG(("Authorize() success_url =[%s]\n",csTmp));
			}
			else{
				iRet = INT_SUCC_URL_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() success_url not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() success_url not found\n"));
			}
		}

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"failure_url",&csTmp)){
DEBUGLOG(("Authorize() failure_url =[%s]\n",csTmp));
			}
			else{
				iRet = INT_FAIL_URL_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() failure_url not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() failure_url not found\n"));
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
ERRLOG(("TxnWebOnUsCOM::Authorize() success_callback_url not found\n"));
		}
		}

		if(iRet == PD_OK){
			if(GetField_CString(hRequest,"failure_callback_url",&csTmp)){
DEBUGLOG(("Authorize() failure_callback_url =[%s]\n",csTmp));
			}
			else{
				iRet = INT_FAIL_CB_URL_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() failure_callback_url not found\n"));
ERRLOG(("TxnWebOnUsCOM::Authorize() failure_callback_url not found\n"));
			}
		}

	}


/*******************/

	if (strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
		if ( iRet == PD_OK) {
/* Check Merchant */
DEBUGLOG(("Authorize() call BOMerchant->GetMerchantTxnInfo\n"));
 			BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantTxnInfo");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOMerchant->GetMerchantTxnInfo = [%d]\n",iRet));
	
		}

		if(iRet == PD_OK){
			if(!GetField_Double(hContext,"delta_amt_low",&dDeltaAmtLow))
				dDeltaAmtLow = PD_DELTA_AMT_BOUNDARY_1;

			dDeltaAmt = abs(dTxnAmt - round(dTxnAmt / 100.0) * 100);
DEBUGLOG(("Authorize() delta amt range (low) = [%lf], txn delta amount = [%lf]\n",dDeltaAmtLow,dDeltaAmt));

			if((dTxnAmt >= 100) && (dDeltaAmt < dDeltaAmtLow)){

				if(GetField_Int(hContext,"support_delta_amt",&iTmp)){
					if(iTmp == PD_FALSE){
						 iRet =  INT_INVALID_PAY_AMOUNT;
						 PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()delta amount too small[%lf]<[%lf]!!!!\n",dDeltaAmt,dDeltaAmtLow));
ERRLOG("TxnWebOnUsCOM::Authorize() delta amount too small[%lf]<[%lf]!!!!\n",dDeltaAmt,dDeltaAmtLow);
					}
				}

			}
		}

/* Check PSP */
		if (iRet == PD_OK && strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) {
 			BOObjPtr = CreateObj(BOPtr,"BOPsp","GetTxnPsp");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOPsp->GetTxnPsp = [%d]\n",iRet));
		}

/* check restricted ccy*/
/*
		if(iRet == PD_OK){
			char *csDstCcy;

			GetField_CString(hContext,"dst_txn_ccy",&csDstCcy);
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsRestricted");
			if((unsigned long)(*DBObjPtr)(csTxnCcy)==PD_TRUE){
				if(strcmp(csTxnCcy,csDstCcy)==0){
					iRet = INT_INVALID_CURRENCY_CODE;
				}
			}
		}
*/

/* skipcheck for WTB */

/* check merchant limit */
		if (iRet == PD_OK && 
		    /*strcmp(csTxnCode,PD_INITIAL_TXN_CODE) &&*/
		    strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) &&
		    strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH)) {
DEBUGLOG(("Authorize() call BOTxnLimit->TxnLimit\n"));
 			BOObjPtr = CreateObj(BOPtr,"BOTxnLimit","TxnLimit");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOTxnLimit->TxnLimit = [%d]\n",iRet));

		}

/* check Psp limit */
		int iSTP = PD_FALSE;
		if(iRet == PD_OK && !strcmp(csTxnCode,PD_INITIAL_TXN_CODE)){
			if ((GetField_CString(hContext,"selected_pid",&csTmp)) || (GetField_CString(hRequest,"selected_pid",&csTmp))) {


				if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize() selected_pid merchant_id =[%s]\n",csMerchantId));
				}

				iSTP = PD_TRUE;
			} 
			else {
				char *csCountry;

				hash_t	*hRec;
				recordset_t     *rRecordSet;
				rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
				recordset_init(rRecordSet,0);

				if(GetField_CString(hRequest,"txn_country",&csCountry)){
DEBUGLOG(("Authorize() txn_country =[%s]\n",csCountry));
				}

				if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize() merchant_id =[%s]\n",csMerchantId));
				}

DEBUGLOG(("TxnWebOnUsCOM:: Call GetStpPsp\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnLbStp","GetStpPsp");
				if ((*DBObjPtr)(csTxnCountry,
							csMerchantId,
							rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					if (hRec)
						iSTP = PD_TRUE;
				}
				RecordSet_Destroy(rRecordSet);
       				FREE_ME(rRecordSet);
			}
DEBUGLOG(("Authorize() iSTP = [%d]\n",iSTP));
			if (iRet == PD_OK && 
					iSTP == PD_FALSE) {
				int iChk = 0;
DEBUGLOG(("TxnWebOnUsCOM:: Call IsUseLB\n"));
				DBObjPtr = CreateObj(DBPtr,"DBService","IsUseLB");
				iChk= (unsigned long)(DBObjPtr)(csServiceCode);
DEBUGLOG(("Authorize() Service->IsUserLB iChk = [%d]\n",iChk));
				if(iChk == PD_TRUE){
DEBUGLOG(("TxnWebOnUsCOM:: Call CheckAllPossiblePspLimit\n"));
					BOObjPtr = CreateObj(BOPtr,"BOTxnLb","CheckAllPossiblePspLimit");
					iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOTxnLb->CheckAllPossiblePspLimit iRet = [%d]\n",iRet));

				}
			}
		}

		if (iRet == PD_OK) {
			if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) &&
			    strcmp(csTxnCode,PD_ONLINE_WITHDRAW_BATCH)) {
			
				GetField_CString(hContext,"psp_id",&csPspId);
DEBUGLOG(("Authorize() psp_id = [%s]\n",csPspId));

				

				GetField_CString(hRequest,"txn_country",&csTxnCountry);
DEBUGLOG(("Authorize() country = [%s]\n",csTxnCountry));

				/*DBObjPtr = CreateObj(DBPtr,"DBService","FindURL");
				if ((unsigned long)(DBObjPtr)(csServiceCodeForURL,csPspId,csVal) == FOUND) {
DEBUGLOG(("Authorize() Return url domain: = [%s]\n",csVal));
				}
				else{
					 csServiceCodeForURL = strdup(PD_DEFAULT_SERVICE);
DEBUGLOG(("Authorize() url for service_code[%s] undefine, use default one[%s]\n",csServiceCode, csServiceCodeForURL));
				}*/


//find BE url
				if (strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) { //if not CMP
					hash_t  *hRec;
					recordset_t     *rRecordSet;
					rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
					recordset_init(rRecordSet,0);

					DBObjPtr = CreateObj(DBPtr,"DBTxnBeUrl","GetBeUrl");
					if ((unsigned long)(DBObjPtr)(csTxnCode,csServiceCodeForURL,csPspId,rRecordSet) == PD_OK) {
						hRec = RecordSet_GetFirst(rRecordSet);
                                                while(hRec){
                                                        if (GetField_CString(hRec,"be_url",&csPtr)) {
DEBUGLOG(("Authorize() Return url: = [%s]\n",csPtr));
								csBuf = (char*)  malloc (PD_VALUE_LEN * 2 + 1);
								if (GetField_CString(hContext,"txn_seq",&csTmp)) {
									sprintf(csBuf,"%s?order_num=%s",csPtr,csTmp);
									PutField_CString(hContext,"return_url",csBuf);
									PutField_CString(hContext,"return_url_only",csPtr);
DEBUGLOG(("Authorize() Return url     : = [%s]\n",csBuf));
DEBUGLOG(("Authorize() Return url only: = [%s]\n",csPtr));
								}
								FREE_ME(csBuf);
							}
							hRec = RecordSet_GetNext(rRecordSet);
						}
					}
					else {
/* try to find default */
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnWebOnUsCOM::Authorize() Unable to find return BE URL for PSP ID[%s]\n",csPspId);
DEBUGLOG(("TxnWebOnUsCOM::Authorize() Unable to find return BE URL for PSP ID[%s]\n",csPspId));
					}
					RecordSet_Destroy(rRecordSet);
       					FREE_ME(rRecordSet);

				}

//				if (strcmp(PD_CHINA_MOBILE_SERVICE,csServiceCode)) {
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

					int	iUseNewUI = PD_FALSE;
					int	i = 0;
					int	iCtlCnt = 0;
					char	*csTagValue;
					char	*csFindTag;
					char	csTag[PD_TAG_LEN+1];
					hash_t* hTag;
					hTag = (hash_t*) malloc (sizeof(hash_t));
                                	hash_init(hTag, 0);
					DBObjPtr = CreateObj(DBPtr,"DBServiceUIRelease","IsUseNewUI");
					if((unsigned long)(DBObjPtr)(csServiceCode,csMerchantId,csTxnCountry)==PD_TRUE){
						DBObjPtr = CreateObj(DBPtr,"DBServiceUIReleaseCtl","GetCtlTag");
						if((unsigned long)(DBObjPtr)(hTag)==PD_OK){
							GetField_Int(hTag,"tag_cnt",&iCtlCnt);
						}
					}
					for (i=0; i<iCtlCnt; i++){
						csTagValue = NULL;
						sprintf(csTag,"ctl_tag_%d",i);
						if(GetField_CString(hTag,csTag,&csFindTag)){
							if(!GetField_CString(hRequest,csFindTag,&csTagValue)){
								if(!GetField_CString(hContext,csFindTag,&csTagValue))
									continue;
							}
							DBObjPtr = CreateObj(DBPtr,"DBServiceUIReleaseCtl","MatchCtlValue");
							if((unsigned long)(DBObjPtr)(csFindTag,csTagValue)==PD_TRUE){
								iUseNewUI = PD_TRUE;
								break;
							}
						}
					}

					int iBlackList = PD_FALSE;
					if(cDirection==PD_TXN_REQUEST){
						//check customer blacklist
						char *csCustomerTag = NULL;
						if(GetField_CString(hRequest,"customer_tag",&csCustomerTag)){
DEBUGLOG(("Authorize() customer_tag = [%s]\n",csCustomerTag));
						
							DBObjPtr = CreateObj(DBPtr,"DBCustomerBlackList","IsBlacklisted");
							if((unsigned long)(DBObjPtr)(csMerchantId,csCustomerTag)==PD_TRUE){
								iBlackList = PD_TRUE;
							}
						}
					}

					if(iUseNewUI){
						if(iBlackList){
DEBUGLOG(("Authorize Call GetFeUrl_NewUI_wBL\n"));
							DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl_NewUI_wBL");
						}
						else{
DEBUGLOG(("Authorize Call GetFeUrl_NewUI\n"));
							DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl_NewUI");
						}	
						iRet = (unsigned long)(DBObjPtr)(csTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet);
					}
					else{
						if(iBlackList){
DEBUGLOG(("Authorize Call GetFeUrl_wBL\n"));
							DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl_wBL");
						}
						else{
DEBUGLOG(("Authorize Call GetFeUrl\n"));
							DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl");
						}
						iRet = (unsigned long)(DBObjPtr)(csTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet);
					}

					if(iRet == PD_OK) {
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
ERRLOG("TxnWebOnUsCOM::Authorize() Unable to find FE URL for [%s][%s][%s] Direction[%c]\n",csTxnCode,csServiceCode,csTxnCountry,cDirection);
					}
			
					RecordSet_Destroy(rRecordSet);
       					FREE_ME(rRecordSet);
					}
//				}
		}


	}
	else  {
/************************************ DSR */
		if (!GetField_CString(hResponse,"service_code",&csServiceCode)) {
DEBUGLOG(("Authorize() service code not found\n"));
DEBUGLOG(("TxnWebOnUsCOM [%s]Authorize() service code not found\n",csTxnCode));
			iRet = PD_ERR;
		}

		char*	csSelectedPayMethod;
		if (GetField_CString(hContext,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("TxnWebOnUsCOM::Authorize() selected_pay_method = [%s]\n",csSelectedPayMethod));
		}
		if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("TxnWebOnUsCOM::Authorize() txn_ccy = [%s]\n",csTxnCcy));
                }
                else if(GetField_CString(hContext,"org_txn_ccy",&csTxnCcy)){
DEBUGLOG(("TxnWebOnUsCOM::Authorize() org_txn_ccy = [%s]\n",csTxnCcy));
                }

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call BOTxnLimit->TxnLimit\n"));
 			BOObjPtr = CreateObj(BOPtr,"BOTxnLimit","TxnLimit");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOTxnLimit->TxnLimit = [%d]\n",iRet));
		}
/* Add BO Customer Group */
                if  (iRet == PD_OK) {
                	BOObjPtr = CreateObj(BOPtr,"BOCustomerGroup","CreateCustomerGroup");
                        iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("Authorize() BOCustomerGroup->CreateCustomerGroup = [%d]\n",iRet));
                }
/* Check PSP */
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize () check txn psp\n"));
			PutField_CString(hContext,"service_code",csServiceCode);
 			BOObjPtr = CreateObj(BOPtr,"BOPsp","GetTxnPsp");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOPsp->GetTxnPsp = [%d]\n",iRet));
		}

		if (!GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("Authorize() psp_id not found\n"));

DEBUGLOG(("TxnWebOnUsCOM [%s]Authorize() psp not found\n",csTxnCode));
			iRet = PD_ERR;
		}

		char csDstCcy[PD_CCY_ID_LEN+1];
		if (iRet==PD_OK && GetField_CString(hContext,"psp_ccy",&csPspCcy)) {
			DBObjPtr = CreateObj(DBPtr,"DBDefPayMethod","FindPayMethodCurrencyCurrency");
			if((unsigned long)(*DBObjPtr)(csSelectedPayMethod,csDstCcy)==PD_OK){
				if(strcmp(csPspCcy,csDstCcy)){
DEBUGLOG(("Authorize() psp currency id and dstination currency id mismatched\n"));
ERRLOG(("TxnWebOnUsCOM:Authorize() psp currency id and dstination currency id mismatched\n"));
					iRet=INT_CURRENCY_ID_NOT_MATCH;
					PutField_Int(hContext,"internal_error",iRet);
				}
			}
			
		}
		
/*
		if (iRet == PD_OK) {
 			BOObjPtr = CreateObj(BOPtr,"BOPsp","GetTxnPspByPspId");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,csPspId,csOrgTxnCode);
		}
*/
/* fine FE */
		if (iRet == PD_OK) {
			hash_t  *hRec;
                        recordset_t     *rRecordSet;
                        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
                        recordset_init(rRecordSet,0);
                        char cDirection;
                                
DEBUGLOG(("try to call find FE URL\n"));
			if (GetField_CString(hContext,"org_txn_country",&csTxnCountry)) {
DEBUGLOG(("Authorize:: txn_country = [%s]\n",csTxnCountry));
                	}
			if (GetField_CString(hContext,"org_merchant_id",&csMerchantId)) {
DEBUGLOG(("Authorize:: merchant_id = [%s]\n",csMerchantId));
                	}
        
                      	cDirection='R';

			int iUseNewUI = PD_FALSE;
			int	i = 0;
			int	iCtlCnt = 0;
			char	*csTagValue;
			char	*csFindTag;
			char	csTag[PD_TAG_LEN+1];
			hash_t* hTag;
			hTag = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hTag, 0);
			
			DBObjPtr = CreateObj(DBPtr,"DBServiceUIRelease","IsUseNewUI");
			if((unsigned long)(DBObjPtr)(csServiceCode,csMerchantId,csTxnCountry)==PD_TRUE){
				DBObjPtr = CreateObj(DBPtr,"DBServiceUIReleaseCtl","GetCtlTag");
				if((unsigned long)(DBObjPtr)(hTag)==PD_OK){
					GetField_Int(hTag,"tag_cnt",&iCtlCnt);
				}
			}
			for (i=0; i<iCtlCnt; i++){
				csTagValue = NULL;
				sprintf(csTag,"ctl_tag_%d",i);
				if(GetField_CString(hTag,csTag,&csFindTag)){
					if(!GetField_CString(hRequest,csFindTag,&csTagValue)){
						if(!GetField_CString(hContext,csFindTag,&csTagValue))
							continue;
					}
					DBObjPtr = CreateObj(DBPtr,"DBServiceUIReleaseCtl","MatchCtlValue");
					if((unsigned long)(DBObjPtr)(csFindTag,csTagValue)==PD_TRUE){
						iUseNewUI = PD_TRUE;
						break;
					}
				}
			}

			if(iUseNewUI){
DEBUGLOG(("Authorize Call GetFeUrl_NewUI\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl_NewUI");
				iRet = (unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet);
			}
			else{
DEBUGLOG(("Authorize Call GetFeUrl\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnFeUrl","GetFeUrl");
				iRet = (unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csMerchantId,csTxnCountry,csLanguage,cDirection,rRecordSet);
			}

			if(iRet == PD_OK) {
                       		hRec = RecordSet_GetFirst(rRecordSet);
                                while(hRec){
                               		if (GetField_CString(hRec,"fe_url",&csPtr)) {
DEBUGLOG(("DBTxnFeUrl:: GetFeUrl - url only = [%s]\n",csPtr));
                                       		PutField_CString(hResponse,"fe_url_only",csPtr);

                                                csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
                                                if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
							char* csTmpBuf;
							csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
							BOObjPtr = CreateObj(DBPtr,"BOSecurity","Encrypt3DESTxnSeq");
							(BOObjPtr)(csTmp,csTmpBuf);
DEBUGLOG(("Authroize tmpbuf = [%s]\n",csTmpBuf));
                                                        sprintf(csBuf,"%s?%s=%s",csPtr,PD_SESSION_ID,csTmpBuf);
							FREE_ME(csTmpBuf);
                                                        PutField_CString(hResponse,"fe_url",csBuf);
DEBUGLOG(("DBTxnFeUrl:: GetFeUrl - url = [%s]\n",csBuf));
                                                }
						else {
DEBUGLOG(("Authroize:: txn_seq is missing\n"));
						}
                                                iRet = PD_OK;
                                                FREE_ME(csBuf);
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
                        }
                        else{
                       		iRet = INT_ERR;
ERRLOG("TxnWebOnUsCOM::Authorize() Unable to find FE URL for [%s][%s] Direction[%c]\n",csOrgTxnCode,csServiceCode,cDirection);
                        }

			
/* check rpt url */
			DBObjPtr = CreateObj(DBPtr,"DBTxnRptUrl","GetRptUrl");
                        if ((unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csLanguage,csSelectedPayMethod,rRecordSet) == PD_OK) {
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while(hRec){
					if (GetField_CString(hRec,"rpt_url",&csPtr)) {
DEBUGLOG(("DBTxnRptUrl:: GetRptUrl - url only = [%s]\n",csPtr));
                                                PutField_CString(hResponse,"rpt_url_only",csPtr);

                                                csBuf = (char*)  malloc (PD_TMP_BUF_LEN + 1);
                                                if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
                                                        char* csTmpBuf;
                                                        csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
                                                        BOObjPtr = CreateObj(DBPtr,"BOSecurity","Encrypt3DESTxnSeq");
                                                        (BOObjPtr)(csTmp,csTmpBuf);
DEBUGLOG(("Authroize tmpbuf = [%s]\n",csTmpBuf));
                                                        sprintf(csBuf,"%s?%s=%s",csPtr,PD_SESSION_ID,csTmpBuf);
                                                        FREE_ME(csTmpBuf);
                                                        PutField_CString(hResponse,"rpt_url",csBuf);
DEBUGLOG(("DBTxnRptUrl:: GetRptUrl - url = [%s]\n",csBuf));
                                                }
                                                else {
DEBUGLOG(("Authroize:: txn_seq is missing\n"));
                                                }
                                                iRet = PD_OK;
                                                FREE_ME(csBuf);
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
			}
                        RecordSet_Destroy(rRecordSet);
                        FREE_ME(rRecordSet);
		}

/* find BE */
		if (iRet == PD_OK) {
			hash_t  *hRec;
			recordset_t     *rRecordSet;
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
			recordset_init(rRecordSet,0);

			DBObjPtr = CreateObj(DBPtr,"DBTxnBeUrl","GetBeUrl");
			if ((unsigned long)(DBObjPtr)(csOrgTxnCode,csServiceCode,csPspId,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while(hRec){
					if (GetField_CString(hRec,"be_url",&csPtr)) {
DEBUGLOG(("Authorize() Return url: = [%s]\n",csPtr));
						csBuf = (char*)  malloc (PD_VALUE_LEN * 2 + 1);
						if (GetField_CString(hResponse,"txn_seq",&csTmp)) {
							sprintf(csBuf,"%s?order_num=%s",csPtr,csTmp);
							PutField_CString(hContext,"return_url",csBuf);
							PutField_CString(hContext,"return_url_only",csPtr);
DEBUGLOG(("Authorize() Return url     : = [%s]\n",csBuf));
DEBUGLOG(("Authorize() Return url only: = [%s]\n",csPtr));
						}
						FREE_ME(csBuf);
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
/* try to find default */
				iRet = INT_ERR;
ERRLOG("TxnWebOnUsCOM::Authorize() Unable to find return BE URL for PSP ID[%s]\n",csPspId);
DEBUGLOG(("TxnWebOnUsCOM::Authorize() Unable to find return BE URL for PSP ID[%s]\n",csPspId));
			}

			RecordSet_Destroy(rRecordSet);
			FREE_ME(rRecordSet);
		}

	}


                
        if (strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) {
		if (!strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)){
			PutField_Int(hContext,"init_mode",PD_TRUE);
		}


//////////for difference currency
		if (iRet == PD_OK) {
			int     iAddElement = PD_TRUE;
DEBUGLOG(("Authorize() Compare [%s][%s]\n",csTxnCcy,csPspCcy));
                        if(strcmp(csTxnCcy,csPspCcy)){
DEBUGLOG(("Authorize() Different currency flow...\n"));
                                PutField_CString(hContext,"src_txn_fee_ccy",csTxnCcy);
                                PutField_CString(hContext,"dst_txn_fee_ccy",csPspCcy);
                                if (GetField_CString(hRequest,"org_encrypted_txn_seq",&csPtr)) {
DEBUGLOG(("Authorize() org encrypted txn seq  = [%s]\n",csPtr));
                                        BOObjPtr = CreateObj(DBPtr,"BOSecurity","Decrypt3DESTxnSeq");
                                        char* csTmpBuf;
                                        csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
                                        (BOObjPtr)(csPtr,csTmpBuf);
                                        strcpy(csOrgTxnSeq,csTmpBuf);
DEBUGLOG(("Authorize() org txn seq = [%s]\n",csOrgTxnSeq));
                                        FREE_ME(csTmpBuf);
                                }


                                DBObjPtr = CreateObj(DBPtr,"DBTmpCalAmount","GetTmpCalAmount");
                                if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,hContext) == PD_FOUND) {
DEBUGLOG(("Authorize() GetTmpCalAmount Record Found\n"));
                                        if(GetField_Double(hContext,"src_net_amt",&dTmp)){
                                                PutField_Double(hContext,"net_amt",dTmp);
                                        }
                                        if(GetField_Double(hContext,"src_fee",&dTmp)){
                                                PutField_Double(hContext,"src_txn_fee",dTmp);
                                        }
                                        if(GetField_Double(hContext,"dst_fee",&dTmp)){
                                                PutField_Double(hContext,"dst_txn_fee",dTmp);
                                        }
                                        if(GetField_Double(hContext,"markup_amt",&dTmp)){
						if(dTmp<=0.0)
							iAddElement = PD_FALSE;
                                        }


					if (GetOverridedFee(hContext,hRequest) == PD_OK)  {

						if (GetField_Double(hContext, "override_src_net_amt", &dTmp)) {
                                                	PutField_Double(hContext,"net_amt",dTmp);
						}

						if (GetField_Double(hContext, "override_src_fee", &dTmp)) {
                                                	PutField_Double(hContext,"src_txn_fee",dTmp);
						}

						if (GetField_Double(hContext, "override_dst_net_amt", &dTmp)) {
							PutField_Double(hContext, "dst_net_amt", dTmp);
						}

						if (GetField_Double(hContext, "override_dst_fee", &dTmp)) {
                                                	PutField_Double(hContext,"dst_txn_fee",dTmp);
						}

					}

                                        hash_t  *hRec;
                                        recordset_t     *rRecordSet;
                                        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
                                        recordset_init(rRecordSet,0);

                                        DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
                                        if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_ELEMENT_MARKUP_AMT,PD_TYPE_CUSTOMER,rRecordSet) == PD_OK) {
                                                hRec = RecordSet_GetFirst(rRecordSet);
                                                while (hRec) {
                                                        if (GetField_Double(hRec,"amount",&dTmp)) {
DEBUGLOG(("Authorize() GetFeeChgDetailByType: previous markup = [%lf]\n",dTmp));
                                                                iAddElement = PD_FALSE;
                                                        }
                                                        hRec = RecordSet_GetNext(rRecordSet);
                                                }
                                        }
                                        if(iAddElement){
DEBUGLOG(("Authorize() Call AddMarkupAmtElement\n"));
                                                PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
                                                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddMarkupAmtElement");
                                                if((unsigned long)(*BOObjPtr)(hContext)!=PD_OK){
DEBUGLOG(("Authorize() AddMarkupAmtElement Failed!!\n"));
ERRLOG("TxnWebOnUsCOM: Authorize() AddMarkupAmtElement Failed!!\n");
                                                }
                                        }
                                        RecordSet_Destroy(rRecordSet);
					FREE_ME(rRecordSet);

                                        iRet = PD_SKIP_OK;
                                }
                                else{
DEBUGLOG(("Authorize() GetTmpCalAmount Record Not Found\n"));
                                }
                        }
                }

////normal flow
		if(iRet==PD_OK){
DEBUGLOG(("Authorize() Normal flow...\n"));
/* GetExchangeInfo */

DEBUGLOG(("TxnWebOnUsCOM:: Call Exchange\n"));
       			BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
               		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo = [%d]\n",iRet));

/* txn fee */

			if (iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsCOM:: Call BOFee\n"));
  				BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
				iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsCOM:: GetTxnFee result = [%d]\n",iRet));
			}
		}
		if(iRet == PD_SKIP_OK)
                        iRet = PD_OK;
	}


//	FREE_ME(csTxnCode);
//	FREE_ME(csTxnCcy);
	FREE_ME(csServiceCodeForURL);
	FREE_ME(csLanguage);
DEBUGLOG(("TxnWebOnUsCOM:: exit = [%d]\n",iRet));
	return iRet;
}


int	GetOverridedFee(hash_t* hContext, const hash_t* hRequest) 
{

	int     iRet = PD_OK;

	hash_t 	*hNewContext;
	hNewContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hNewContext,0);

	int     iInitMode = PD_FALSE;
        double  dTxnAmt = 0.0;
        double  dDstTxnAmt = 0.0;
	char    *csDstTxnCcy = NULL;
	char	*csTxnCode = NULL;
	char	*csTxnCountry = NULL;
	char	*csTxnCcy = NULL;
	char	*csChannelCode = NULL;
	char	*csSelectedPayMethod = NULL;
	char	*csServiceCode = NULL;
	char	*csMerchantId = NULL;
	char	*csClientId = NULL;
	char	*csBankCode = NULL;


	double	dNewSrcAmt = 0.0;
	double	dNewSrcFee = 0.0;

	double	dNewDstAmt = 0.0;
	double	dNewDstFee = 0.0;
	
	double  dTmpDstNetAmt = 0.0;
	double  dTmpDstFee = 0.0;

DEBUGLOG(("TxnWebOnUsCOM::GetOverridedFee()\n"));

	if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("GetOverridedFee()  txn_code = [%s]\n", csTxnCode));

		if (!strcmp(csTxnCode, PD_INITIAL_REQ_TXN_CODE)) {

			PutField_CString(hNewContext,"txn_code", PD_INITIAL_TXN_CODE);
			PutField_CString(hNewContext,"org_txn_code", PD_INITIAL_TXN_CODE);

			if (GetField_Int(hContext,"init_mode", &iInitMode)) {
				PutField_Int(hNewContext, "init_mode", iInitMode);
			}


// Change to get from TmpCalAmount
/*

			if (GetField_Double(hContext,"dst_txn_amt",&dDstTxnAmt)) {
DEBUGLOG(("GetOverridedFee()  dst_txn_amt = [%lf]\n",dDstTxnAmt));
	
				PutField_Double(hNewContext,"dst_txn_amt", dDstTxnAmt);

				if (GetField_CString(hContext,"dst_txn_fee_ccy",&csDstTxnCcy)) {
DEBUGLOG(("GetOverridedFee()  dst_txn_fee_ccy = [%s]\n",csDstTxnCcy));
					PutField_CString(hNewContext,"dst_txn_ccy",csDstTxnCcy);
				}
		                else {
DEBUGLOG(("GetOverridedFee()  dst_txn_fee_ccy is missing!!!\n"));
				}
			} else {
DEBUGLOG(("GetOverridedFee()  dst_txn_amt is missing, try dst_net_amt !!!\n"));

				// For specific PID in Mock
				if (GetField_Double(hContext,"dst_net_amt",&dTmpDstNetAmt)) {	
DEBUGLOG(("GetOverridedFee()  dst_net_amt = [%lf]\n", dTmpDstNetAmt));

					if (GetField_Double(hContext,"dst_fee",&dTmpDstFee)) {	
DEBUGLOG(("GetOverridedFee()  dst_fee = [%lf]\n", dTmpDstFee));
					}

					dDstTxnAmt = newround(dTmpDstNetAmt - dTmpDstFee, PD_DECIMAL_LEN);

					PutField_Double(hNewContext,"dst_txn_amt", dDstTxnAmt);
DEBUGLOG(("GetOverridedFee()  dst_txn_amt (by TmpCalAmount) = [%lf]\n",dDstTxnAmt));

					GetField_CString(hContext,"dst_ccy",&csDstTxnCcy);
DEBUGLOG(("GetOverridedFee()  dst_ccy  = [%s]\n",csDstTxnCcy));
					PutField_CString(hNewContext,"dst_txn_ccy",csDstTxnCcy);
                                }
				else {
DEBUGLOG(("GetOverridedFee()  dst_net_amt is missing!!!!!!!\n"));
				}
			}
*/

			//Get from TmpCalAmount
                        if (GetField_Double(hContext,"dst_net_amt",&dTmpDstNetAmt)) {
DEBUGLOG(("GetOverridedFee()  dst_net_amt = [%lf]\n", dTmpDstNetAmt));

                                if (GetField_Double(hContext,"dst_fee",&dTmpDstFee)) {
DEBUGLOG(("GetOverridedFee()  dst_fee = [%lf]\n", dTmpDstFee));
                                }

                                dDstTxnAmt = newround(dTmpDstNetAmt - dTmpDstFee, PD_DECIMAL_LEN);

                                PutField_Double(hNewContext,"dst_txn_amt", dDstTxnAmt);
DEBUGLOG(("GetOverridedFee()  dst_txn_amt = [%lf]\n",dDstTxnAmt));


                                GetField_CString(hContext,"dst_ccy",&csDstTxnCcy);
DEBUGLOG(("GetOverridedFee()  dst_ccy  = [%s]\n",csDstTxnCcy));
                                PutField_CString(hNewContext,"dst_txn_ccy",csDstTxnCcy);
                        }
                        else {
DEBUGLOG(("GetOverridedFee()  dst_net_amt is missing!!!!!!!\n"));
                        }



			if (GetField_Double(hContext,"org_txn_amt", &dTxnAmt)) {
DEBUGLOG(("GetOverridedFee()  org_txn_amt = [%lf]\n", dTxnAmt));
				PutField_Double(hNewContext,"org_txn_amt",dTxnAmt);
			}

			if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("GetOverridedFee()  txn_code = [%s]\n", csTxnCode));

				if (!strcmp(csTxnCode, PD_INITIAL_REQ_TXN_CODE)) {
					PutField_CString(hNewContext,"org_txn_code", PD_INITIAL_TXN_CODE);
				}
DEBUGLOG(("GetOverridedFee()  (set new) txn_code = [%s]\n", csTxnCode));
			}
	
			if (GetField_CString(hContext,"org_txn_country",&csTxnCountry)) {
DEBUGLOG(("GetOverridedFee()  org_txn_country = [%s]\n", csTxnCountry));
				PutField_CString(hNewContext,"org_txn_country", csTxnCountry);
			}

			if (GetField_CString(hContext,"org_txn_ccy", &csTxnCcy)) {
DEBUGLOG(("GetOverridedFee()  org_txn_ccy = [%s]\n", csTxnCcy));
				PutField_CString(hNewContext,"org_txn_ccy",csTxnCcy);
			}

			if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("GetOverridedFee()  org_channel_code = [%s]\n", csChannelCode));
				PutField_CString(hNewContext,"org_channel_code",csChannelCode);
			}

			if (GetField_CString(hContext,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("GetOverridedFee()  selected_pay_method  [%s]\n", csSelectedPayMethod));
				PutField_CString(hNewContext, "selected_pay_method", csSelectedPayMethod);
			}

			if (GetField_CString(hContext, "service_code", &csServiceCode)) {
DEBUGLOG(("GetOverridedFee()  service_code [%s]\n", csServiceCode));
				PutField_CString(hNewContext,"org_service_code",csServiceCode);
			}

			if (GetField_CString(hContext,"org_merchant_id",&csMerchantId)) {
DEBUGLOG(("GetOverridedFee()  org_merchant_id [%s]\n", csMerchantId));
				PutField_CString(hNewContext,"org_merchant_id",csMerchantId);
			}

			if (GetField_CString(hContext,"org_client_id",&csClientId)) {
DEBUGLOG(("GetOverridedFee()  org_client_id [%s]\n", csClientId));
				PutField_CString(hNewContext,"org_client_id",csClientId);
			}

			if (GetField_CString(hRequest,"bank_code",&csBankCode)){
DEBUGLOG(("GetOverridedFee()  bank_code [%s]\n", csBankCode));
				PutField_CString(hNewContext,"bank_code",csBankCode);
			}

			if (iRet == PD_OK) {
DEBUGLOG(("GetOverridedFee::BOFee::GetTxnFee\n"));
				BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
				iRet = (unsigned long)(*BOObjPtr)(hNewContext,hNewContext);
DEBUGLOG(("GetOverridedFee result = [%d]\n",iRet));
			}
	

			if (iRet == PD_OK) {
				if (GetField_Double(hNewContext, "net_amt", &dNewSrcAmt)) {
					PutField_Double(hContext, "override_src_net_amt", dNewSrcAmt);
				}

				if (GetField_Double(hNewContext, "src_txn_fee", &dNewSrcFee)) {
					PutField_Double(hContext, "override_src_fee", dNewSrcFee);
				}

				if (GetField_Double(hNewContext, "dst_net_amt", &dNewDstAmt)) {
					PutField_Double(hContext, "override_dst_net_amt", dNewDstAmt);
				}

				if (GetField_Double(hNewContext, "dst_txn_fee", &dNewDstFee)) {
					PutField_Double(hContext, "override_dst_fee", dNewDstFee);
				}

DEBUGLOG(("GetOverridedFee src_net_amt = [%lf] src_fee = [%lf] dst_fee = [%lf]\n",dNewSrcAmt, dNewSrcFee, dNewDstFee));
			}	
		}
	}

	FREE_ME(hNewContext);

	return iRet;
}


