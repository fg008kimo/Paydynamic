/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/11              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsBTV.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

void TxnOmtByUsBTV(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csFromMid; 
	char	*csToMid;

	char	*csFromService;
	char	*csToService;

	char	*csFromCcy;
	char	*csToCcy;

	char	*csFromClientID;
	char	*csToClientID;

	double	dTxnAmt;

	char	*csFromCountry = NULL;
	char	*csToCountry = NULL;

	char	*csEnqTxnCode;
	char	*csTmp;

	//int	iInternalErr;

	double  dDstTxnAmt = 0.0;

	double	dMarkupAmt = 0.0;
	double  dMarkupRate = 0.0;
	char	*csMarkupCcy = NULL;

	double	dExRate = 0.0;
	
	double 	dTotalSrcFee = 0.0;
	double 	dTotalFee = 0.0;
	double	dNetAmt = 0.0;
	
	char	cPartyType;
	char	cTmp;
	

DEBUGLOG(("Authorize::()\n"));


/* mrechant_id */
	if (GetField_CString(hRequest,"merchant_id",&csFromMid)) {
DEBUGLOG(("Authorize::() merchant_id = [%s]\n",csFromMid));

	}
	else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() merchant_id missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() merchant_id is missing\n");
	}

/* to merchant_id */
	if (GetField_CString(hRequest,"to_merchant_id",&csToMid)) {
DEBUGLOG(("Authorize::() to_merchant_id = [%s]\n",csToMid));
	}
	else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() to_merchant_id missing\n"));
ERRLOG("TxnOmtByUSBTP:Authorize() to_merchant_id is missing\n");
	}

/* service */
	if (GetField_CString(hRequest,"service_code",&csFromService)) {
DEBUGLOG(("Authorize::() service = [%s]\n",csFromService));
	}
	else {
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() service missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() service is missing\n");
	}

/* to service */
	if (GetField_CString(hRequest,"to_service_code",&csToService)) {
DEBUGLOG(("Authorize::() to_service = [%s]\n",csToService));
	}
	else {
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() to_service missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() to_service is missing\n");
	}

/* txn_ccy */
	if (GetField_CString(hRequest,"txn_ccy",&csFromCcy)) {
DEBUGLOG(("Authorize::() service = [%s]\n",csFromCcy));
	}
	else {
		iRet = INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_ccy missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() txn_ccy is missing\n");
	}

/* to txn_ccy */
	if (GetField_CString(hRequest,"dst_txn_ccy",&csToCcy)) {
DEBUGLOG(("Authorize::() dst_txn_ccy = [%s]\n",csToCcy));
	}
	else {
		iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("Authorize::() dst_txn_ccy missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() dst_txn_ccy is missing\n");
	}

/* from country */
	if (GetField_CString(hRequest,"from_country",&csFromCountry)) {
		//PutField_CString(hContext,"_country",csFromCountry);
DEBUGLOG(("Authorize::() from_country = [%s]\n",csFromCountry));
	}
	else {
		iRet = INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() from_country is missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() from_country is missing\n");
	}

/* to_country */
	if (GetField_CString(hRequest,"to_country",&csToCountry)) {
		//PutField_CString(hContext,"_country",csToCountry);
DEBUGLOG(("Authorize::() to_country = [%s]\n",csToCountry));
	}
	else {
		iRet = INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() to_country missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() to_country is missing\n");
	}


/* txn amt */
	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize::() txn_amt = [%f]\n",dTxnAmt));
	}
	else {
		iRet = INT_TXN_AMT_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_amt is missing\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() txn amount is missing\n");
	}

	if (dTxnAmt <= 0 ) {
		iRet = INT_INVALID_PAY_AMOUNT;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_amt is missing\n"));
ERRLOG("TxnOmtByUSBTP:Authorize() txn amount is missing\n");
	}

/* Req txn code */
	if (GetField_CString(hRequest, "enq_txn_code", &csEnqTxnCode)) {
DEBUGLOG(("Authorize::() enq_txn_code = [%s]\n",csEnqTxnCode));
	} else {
		iRet = INT_CODE_ERROR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() req_txn_code is missing\n"));
ERRLOG("TxnOmtByUSBTP:Authorize() req_txn_code is missing\n");
	}

	if (strcmp(csEnqTxnCode, PD_OFL_AVA_PAYOUT_REQ_TF_FROM) &&
            strcmp(csEnqTxnCode, PD_OFL_MERCHANT_BAL_TFF)) {
		iRet = INT_CODE_ERROR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() unexpected req_txn_code\n"));
ERRLOG("TxnOmtByUSBTP:Authorize() unexpected req_txn_code\n");
	}


/* party type */
	if (GetField_CString(hRequest, "party_type", &csTmp)) {
		cPartyType = csTmp[0];
DEBUGLOG(("Authorize::() party_type = [%c]\n",cPartyType));
	}
	else {
		cPartyType = PD_TYPE_MERCHANT;
DEBUGLOG(("Authorize::() (Default) party_type = [%c]\n",cPartyType));
	}


/*support same country only*/
	if (iRet == PD_OK) {
		if (strcmp(csFromCountry, csToCountry)) {
			iRet = INT_NOT_ALLOW_DIFF_COUNTRY;
DEBUGLOG(("Authorize::() difference country not allow\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() difference country not allow\n");
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
/* check same account */
	if (iRet == PD_OK) {
		if (!strcmp(csFromMid,csToMid) && !strcmp(csFromService,csToService) && !strcmp(csFromCcy,csToCcy)) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() same account transfer\n"));
ERRLOG("TxnOmtByUsBTV:Authorize() same account transfer\n");
		}
	}

/* user */
/*
	if (GetField_CString(hRequest,"add_user",&csTmp)) {
		PutField_CString(hContext,"add_user",csTmp);
	}
*/

	if (iRet == PD_OK) {
                hash_t *hTmpContext, *hReq;

                hReq = (hash_t*) malloc (sizeof(hash_t));
                hTmpContext= (hash_t*) malloc (sizeof(hash_t));

                hash_init(hReq,0);
                hash_init(hTmpContext,0);

                PutField_CString(hReq,"service_code",csFromService);
                PutField_CString(hReq,"merchant_id",csFromMid);
                PutField_CString(hReq,"txn_ccy",csFromCcy);
                PutField_CString(hReq,"txn_country",csFromCountry);

DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hTmpContext,hReq);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo = [%d]\n",iRet));		
		if (iRet == PD_OK) {
			if (GetField_CString(hTmpContext, "merchant_client_id", &csFromClientID)) {
DEBUGLOG(("Authorize() From Client ID = [%s]\n", csFromClientID));		
			}
		}
		
		hash_destroy(hReq);
		hash_destroy(hTmpContext);


                hash_init(hReq,0);
                hash_init(hTmpContext,0);

                PutField_CString(hReq,"service_code",csToService);
                PutField_CString(hReq,"merchant_id",csToMid);
                PutField_CString(hReq,"txn_ccy",csToCcy);
                PutField_CString(hReq,"txn_country",csToCountry);

DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hTmpContext,hReq);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo = [%d]\n",iRet));		
		if (iRet == PD_OK) {
			if (GetField_CString(hTmpContext, "merchant_client_id", &csToClientID)) {
DEBUGLOG(("Authorize() To Client ID = [%s]\n", csToClientID));		
			}
		}
		hash_destroy(hReq);
		hash_destroy(hTmpContext);


		FREE_ME(hReq);
		FREE_ME(hTmpContext);


	}





	if (iRet == PD_OK) {
/* GetExchangeInfo */
DEBUGLOG(("Authorize:: Call Exchange\n"));

		if (!strcmp(csEnqTxnCode, PD_OFL_AVA_PAYOUT_REQ_TF_FROM)){
			PutField_CString(hContext,"txn_code", PD_OFL_AVA_PAYOUT_REQ_TF_TO);
		} 
		if(!strcmp(csEnqTxnCode, PD_OFL_MERCHANT_BAL_TFF)) {
			PutField_CString(hContext,"txn_code", PD_OFL_MERCHANT_BAL_TFT);
		}

		//PutField_CString(hContext,"txn_code", csEnqTxnCode);
		PutField_CString(hContext, "dst_txn_ccy", csToCcy);
		PutField_CString(hRequest, "txn_country", csFromCountry);
		PutField_CString(hContext, "channel_code", PD_CHANNEL_OMT);
		PutField_CString(hRequest, "service_code", csToService);
		//PutField_CString(hContext, "service_code", csToService);
		PutField_CString(hRequest, "merchant_id", csToMid);
		PutField_CString(hContext, "merchant_client_id", csToClientID);

		BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo = [%d]\n",iRet));

		if (iRet == PD_OK) {
			if (GetField_Double(hContext, "dst_txn_amt", &dDstTxnAmt)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo dst_txn_amt [%f]\n", dDstTxnAmt));
                        }

                        if (GetField_Double(hContext, "ex_rate", &dExRate)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo ex_rate [%f]\n", dExRate));
                        }
                        if (GetField_Double(hContext, "markup_rate", &dMarkupRate)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_rate [%f]\n", dMarkupRate));
                        }
                        if (GetField_Double(hContext, "markup_amt", &dMarkupAmt)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_amt [%f]\n", dMarkupAmt));
                        }

                        if (GetField_CString(hContext, "markup_ccy", &csMarkupCcy)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_ccy [%s]\n", csMarkupCcy));
                                if (dMarkupAmt > 0.0) {
                                        if (strcmp(csMarkupCcy, csToCcy)) {
                                                dMarkupAmt = dMarkupAmt * dExRate;
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo converted markup_ccy [%s] markup_amt [%lf]\n", csToCcy, dMarkupAmt));

                                                PutField_Double(hContext, "markup_amt", dMarkupAmt);
                                                PutField_CString(hContext, "markup_ccy", csToCcy);
                                        }
                                }
                        }

			if (GetField_Char(hContext, "ex_party", &cTmp)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo ex_party [%c]\n", cTmp));
			}


		}

		if (iRet == PD_OK) {
			PutField_CString(hContext,"txn_code", csEnqTxnCode);
			PutField_CString(hRequest, "merchant_id", csFromMid);
			PutField_CString(hContext, "merchant_client_id", csFromClientID);
			PutField_CString(hRequest, "service_code", csFromService);
	
/* check from fee */
			BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);

			if (iRet == PD_OK) {
				if (GetField_Double(hContext, "total_src_txn_fee", &dTotalSrcFee)) {
DEBUGLOG(("Authorize() BOFee->GetTxnFee total src fee [%lf]\n", dTotalSrcFee));
				}

				if (GetField_Double(hContext, "total_dst_txn_fee", &dTotalFee)) {
DEBUGLOG(("Authorize() BOFee->GetTxnFee total dst fee [%lf]\n", dTotalFee));
				}

				dNetAmt = dDstTxnAmt - dTotalFee;
DEBUGLOG(("Authorize() NetAmt [%lf]\n", dNetAmt));
				
			}
		}	
	}

	if (iRet == PD_OK) {
		PutField_Double(hResponse, "src_fee", dTotalSrcFee);
		PutField_Double(hResponse, "fee", dTotalFee);
		PutField_Double(hResponse, "markup_amt", dMarkupAmt);
		//PutField_Double(hResponse, "ex_rate", dExRate*(1-dMarkupRate));
		PutField_Double(hResponse, "ex_rate", dExRate);
		PutField_Double(hResponse, "net_amt", dNetAmt);
		PutField_CString(hResponse, "net_ccy", csToCcy);

	}


DEBUGLOG(("TxnOmtByUsBTV Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
