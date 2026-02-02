/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/27              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsWRA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsWRA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csMerchantId = NULL;
	char	*csTxnCountry = NULL;
	char	*csTxnCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csTmp = NULL;

	char	*csEffectDate;

	int	iCnt;
	int	i;
	char    csTag[PD_TAG_LEN +1];
	char    *csPtr;

        int     iCheck;
	char	*p;
        double  dTmp;
	long    lTmp;
	

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

	csEffectDate = (char *)malloc(PD_DATETIME_LEN + 1);

// add_user
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hTxn, "add_user", csUser);
	}  else {
DEBUGLOG(("Authorize::add_user not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::add_user not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

// merchant_id
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hTxn, "merchant_id", csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

//txn_ccy
	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hTxn, "txn_ccy", csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

//txn_country
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hTxn, "txn_country", csTxnCountry);
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

//service_code
	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hTxn, "service_code", csServiceCode);
	}
        else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::service_code not found!!\n");
                iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
        }

//status
	if (GetField_CString(hRequest, "status", &csTmp)) {
DEBUGLOG(("Authorize:: status = [%s]\n",csTmp));
		PutField_CString(hTxn, "status", csTmp);
	}
	else {
DEBUGLOG(("Authorize::statusnot found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::status not found!!\n");
		iRet=INT_STATUS_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

//eff_date
	if (GetField_CString(hRequest, "eff_date", &csTmp)) {
DEBUGLOG(("Authorize:: eff_date = [%s]\n",csTmp));
		PutField_CString(hTxn, "eff_date", csTmp);

	} else {
DEBUGLOG(("Authorize::eff_date not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::eff_date not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

// amt_type
	if (GetField_CString(hRequest, "amt_type", &csTmp)) {
DEBUGLOG(("Authorize:: amt_type = [%s]\n",csTmp));
		PutField_CString(hTxn, "amt_type", csTmp);
	}
	else {
DEBUGLOG(("Authorize::amt_type not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::amt_type not found!!\n");
		iRet = INT_AMT_TYPE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

// total_cnt
	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
		if (iCnt != 7) {
DEBUGLOG(("Authorize::unexpected number of count iCnt [%d]!!\n", iCnt));
ERRLOG("TxnMgtByUsWRA::Authorize::expected number of count !!\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
		}
	} else {
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnMgtByUsWRA::Authorize::total_cnt not found!!\n");

		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}


	if (iRet == PD_OK) {
		if (GetField_Int(hContext,"total_cnt",&iCnt)) {

			//PutField_Int(hResponse,"total_cnt",iCnt);

DEBUGLOG(("Authorize::() total_cnt = [%d]\n",iCnt));
			for (i=0; i < iCnt; i++) {
				if (iRet == PD_OK) {
					sprintf(csTag, "%s_dow_%d", PD_DETAIL_TAG,i+1);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csPtr));
						PutField_CString(hTxn,"dow",csPtr);
					} else {
						iRet = INT_INVALID_TXN;
					}

					sprintf(csTag, "%s_txnamt_%d", PD_DETAIL_TAG,i+1);
					if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csPtr));

						// sync with TxnMgtByUsCOM
						iCheck = PD_FALSE;
						p = (char*)strchr(csPtr, '.');
						if (p == NULL){
							iCheck = is_numeric(csPtr);
							if(iCheck!=PD_FALSE){
								if(sscanf(csPtr,"%lf",&dTmp)==1){
									PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTmp));
	                                			}
							}
						} else {
							if(sscanf(csPtr,"%lf",&dTmp)==1){
								iCheck = PD_TRUE;
								PutField_Double(hTxn,"txn_amt",dTmp);
DEBUGLOG(("Authorize() txn_amt = [%f]\n",dTmp));
							}
							DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
							if ((unsigned long)((DBObjPtr)(csTxnCcy)) != PD_TRUE){
DEBUGLOG(("TxnMgtOnUsWRA::Authorize() [%s] doesn't support decimal\n",csTxnCcy));
								lTmp = (long) dTmp;
								if (dTmp > lTmp) {
									iRet = INT_UNSUPPORTED_PAY_AMOUNT;
DEBUGLOG(("TxnMgtOnUsWRA::Authorize() unsupported transaction amount [%f]\n",dTmp));
ERRLOG("TxnMgtOnUsWRA::Authorize() unsupported transaction amount [%f]\n",dTmp);
								}
								else if(lTmp==0l){
									iRet =  INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csPtr));
ERRLOG("TxnMgtByUsWRA::Authorize() txn_amt Invalid\n");
								}
							}
						}
						if (iCheck == PD_FALSE) {
							iRet =  INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csPtr));
ERRLOG("TxnMgtByUsWRA::Authorize() txn_amt Invalid\n");
						}
					} else {
DEBUGLOG(("Authorize()txn_amt not found[%s]\n",csPtr));
ERRLOG("TxnMgtByUsWRA::Authorize() txn_amt not found\n");
						iRet = INT_PAY_AMOUNT_NOT_FOUND;
					}

					if (iRet == PD_OK) {
                                		TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsRAU","Authorize");
	                                	iRet = (unsigned long)(*TxnObjPtr)(hTxn, hTxn, hResponse);

					//sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iRet));
					//PutField_Int(hResponse, csTag, iRet);
					}

					if (iRet != PD_OK) {
						break;
					}
                        	}
			}
		} else {
			iRet = INT_FORMAT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	FREE_ME(csEffectDate);

DEBUGLOG(("TxnMgtByUsWRA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
