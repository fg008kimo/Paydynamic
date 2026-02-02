/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/29              Virginia Yun
Handle update_user                                 2014/05/05              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOTF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

void TxnOmtByUsOTF(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	double	dTxnAmt;
	char	*csFromMid;
	char	*csToMid;
	char	*csFromService;
	char	*csToService;
	char	*csFromCcy;
	char	*csToCcy;
	char	*csCountry;
	//char	*csFromCountry = NULL;
	char	*csToCountry = NULL;
	char	*csTxnSeq;
	char	*csTmp;
	double	dFromBalance = 0.0;
	double	dTotalSrcFee = 0.0;
	double	dTotalFee = 0.0;
	double	dNetAmt = 0.0;
	char	*csPHPostingDate;
	char	*csPtr;
	int	iInternalErr = 0;

	double  dDstTxnAmt = 0.0;

	double	dMarkupAmt = 0.0;
	char	*csMarkupCcy = NULL;
	double	dExRate = 0.0;
	double	dTmp;

	char	*csFromClientID;
	char	*csToClientID;
	

DEBUGLOG(("Authorize::()\n"));
	if (GetField_CString(hContext,"PHDATE",&csPHPostingDate)) {
DEBUGLOG(("Authorize::()PH DATe = [%s]\n",csPHPostingDate));
	}
/* txn amt */
	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize::() txn_amt = [%f]\n",dTxnAmt));
	}
	else {
		iRet = INT_TXN_AMT_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_amt is missing\n"));
ERRLOG("TxnOmtOnUsOTF:Authorize() txn amount is missing\n");
	}

	if (dTxnAmt <= 0 ) {
		iRet = INT_INVALID_PAY_AMOUNT;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_amt is missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() txn amount is missing\n");
	}

/* mrechant_id */
	if (GetField_CString(hRequest,"merchant_id",&csFromMid)) {
DEBUGLOG(("Authorize::() merchant_id = [%s]\n",csFromMid));
	}
	else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() merchant_id missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() merchant_id is missing\n");
	}

/* to merchant_id */
	if (GetField_CString(hRequest,"to_merchant_id",&csToMid)) {
DEBUGLOG(("Authorize::() to_merchant_id = [%s]\n",csToMid));
	}
	else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() to_merchant_id missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() to_merchant_id is missing\n");
	}

/* service */
	if (GetField_CString(hRequest,"service_code",&csFromService)) {
DEBUGLOG(("Authorize::() service = [%s]\n",csFromService));
	}
	else {
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() service missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() service is missing\n");
	}

/* to service */
	if (GetField_CString(hRequest,"to_service_code",&csToService)) {
DEBUGLOG(("Authorize::() to_service = [%s]\n",csToService));
	}
	else {
		iRet = INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() to_service missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() to_service is missing\n");
	}

/* txn_ccy */
	if (GetField_CString(hRequest,"txn_ccy",&csFromCcy)) {
DEBUGLOG(("Authorize::() txn_ccy = [%s]\n",csFromCcy));
	}
	else {
		iRet = INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_ccy missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() txn_ccy is missing\n");
	}

/* to txn_ccy */
	if (GetField_CString(hRequest,"dst_txn_ccy",&csToCcy)) {
DEBUGLOG(("Authorize::() dst_txn_ccy = [%s]\n",csToCcy));
	}
	else {
		iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("Authorize::() dst_txn_ccy missing\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() dst_txn_ccy is missing\n");
	}

/* from country */
	if (GetField_CString(hRequest,"from_country",&csCountry)) {
		PutField_CString(hRequest,"txn_country",csCountry);
DEBUGLOG(("Authorize::() from_country = [%s]\n",csCountry));
	}

/* to_country */
	if (GetField_CString(hRequest,"to_country",&csToCountry)) {
		//PutField_CString(hContext,"_country",csToCountry);
DEBUGLOG(("Authorize::() to_country = [%s]\n",csToCountry));
	}

/*support same country only*/
	if (iRet == PD_OK) {
		if (strcmp(csCountry, csToCountry)) {
			iRet = INT_NOT_ALLOW_DIFF_COUNTRY;
DEBUGLOG(("Authorize::() difference country not allow\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() difference country not allow\n");
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
/* check same account */
	if (iRet == PD_OK) {
		if (!strcmp(csFromMid,csToMid) && !strcmp(csFromService,csToService) && !strcmp(csFromCcy,csToCcy)) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() same account transfer\n"));
ERRLOG("TxnOmtByUsOTF:Authorize() same account transfer\n");
		}
	}

/* user */
	if (GetField_CString(hRequest,"add_user",&csPtr)) {
		PutField_CString(hContext,"add_user",csPtr);
		PutField_CString(hContext,"update_user",csPtr);
	}


/* check merchant account */
	if (iRet == PD_OK) {
        	hash_t *hReq;
        	hReq = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hReq,0);

		PutField_CString(hContext,"merchant_id",csFromMid);
		PutField_CString(hContext,"service_code",csFromService);
		PutField_CString(hContext,"txn_ccy",csFromCcy);
		PutField_CString(hContext,"txn_country",csCountry);
		PutField_CString(hContext,"net_ccy",csFromCcy);

		PutField_CString(hReq,"merchant_id",csFromMid);
		PutField_CString(hReq,"service_code",csFromService);
		PutField_CString(hReq,"txn_ccy",csFromCcy);
		PutField_CString(hReq,"txn_country",csCountry);
		if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csTxnSeq));
		}

DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hReq);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo = [%d]\n",iRet));
		hash_destroy(hReq);
        	FREE_ME(hReq);

		if (iRet == PD_OK) {
			if (GetField_CString(hContext, "merchant_client_id", &csFromClientID)) {
DEBUGLOG(("Authorize() Client ID = [%s]\n", csFromClientID));
			}
		}


/* check balance */
		if (iRet == PD_OK) {
			// Check Available Settlement Balance

DEBUGLOG(("Authorize() GetSettAvalBalance\n"));

                        DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetSettAvalBalance");
                        iRet = (unsigned long)(*DBObjPtr)(hContext,
                                                        csFromMid,
                                                        csFromCcy,
                                                        csCountry,
                                                        csFromService,
                                                        &dFromBalance);

DEBUGLOG(("Authorize() aval balance (from) = [%lf]\n",dFromBalance));
		
		}

/* check from fee */
		if (iRet == PD_OK) {
			BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize() [%d] from GetTxnFee\n",iRet));
		}

		if (iRet == PD_OK) {
			GetField_Double(hContext,"total_src_txn_fee",&dTotalSrcFee);
DEBUGLOG(("Authorize total fee = [%lf]\n",dTotalSrcFee));

			/*** Remove dst_txn_fee from source ***/
			RemoveField_Double(hContext, "dst_txn_fee");

			GetField_Double(hContext,"net_amt",&dNetAmt);
DEBUGLOG(("Authorize net amount = [%lf]\n",dNetAmt));
			if (dNetAmt > dFromBalance) {
				iRet = INT_INSUFFICIENT_FUND;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize insufficient fund [%s] [%s] [%s] [%s] [%lf]\n",csCountry,csFromCcy,csFromService,csFromMid,dFromBalance));
ERRLOG("TxnOmtByUsOTF::Authorize insufficient fund [%s] [%s] [%s] [%s] [%lf]\n",csCountry,csFromCcy,csFromService,csFromMid,dFromBalance);
			}
		}

/* update merchant balance */
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize  try to debitMerchant Settlement amount\n"));
		
			PutField_Char(hContext, "dc_type", PD_IND_DEBIT);

			BOObjPtr = CreateObj(BOPtr,"BOOLBalance","ProcessMerchantAdjAmount");
                	iRet = (unsigned long)(*BOObjPtr)(hContext);
		}

		RemoveField_CString(hContext,"org_txn_seq");
		if (iRet == PD_OK) {
			if(GetField_CString(hContext,"txn_seq",&csTmp)){
				PutField_CString(hContext,"from_txn_seq",csTmp);
				PutField_CString(hResponse,"txn_seq_tf",csTmp);
			}
			PutField_CString(hContext,"org_txn_ccy",csFromCcy);
			PutField_CString(hContext,"amount_type",PD_DR);
			PutField_Double(hContext,"org_txn_amt",dTxnAmt);
DEBUGLOG(("TxnOmtByUsOTF:: Call BOOLTxnElements:AddTxnAmtElement\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnAmtElement");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsOTF:: ret from AddTxnAmtElements = [%d]\n",iRet));
		}
		if (iRet == PD_OK) {
			PutField_CString(hContext,"src_txn_fee_ccy",csFromCcy);
			PutField_Double(hContext,"src_txn_fee",dTotalSrcFee);
DEBUGLOG(("TxnOmtByUsOTF:: Call BOOLTxnElements:AddTxnFeeElement\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnFeeElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsOTF:: BOOLTxnElements: AddTxnFeeElements result = [%d]\n",iRet));
		}


		if (iRet == PD_OK) {
			ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnDetailLog");
               		iRet = (unsigned long)(*ChannelObjPtr)(hContext,hRequest,hResponse);
		}
	}


/* check to merchant account */
        if (iRet == PD_OK) {
DEBUGLOG(("check To merchant\n"));

DEBUGLOG(("to mid = [%s]\n",csToMid));
DEBUGLOG(("to service = [%s]\n",csToService));
DEBUGLOG(("to txn_ccy = [%s]\n",csToCcy));
DEBUGLOG(("to txn_country = [%s]\n",csCountry));
        	hash_t *hReq,*hNewContext;
        	hReq = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hReq,0);
        	hNewContext = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hNewContext,0);

DEBUGLOG(("Authorize() new txn for TFT\n"));
		unsigned char   csTmpTxnSeq[PD_TXN_SEQ_LEN +1];

/* don't commit */
                PutField_Int(hNewContext,"db_commit",PD_FALSE);

		DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
                strcpy((char*)csTmpTxnSeq,(*DBObjPtr)());
/* new txn seq */
                PutField_CString(hNewContext,"txn_seq",(const char*)csTmpTxnSeq);
		PutField_CString(hResponse,"txn_seq_tt",(const char*)csTmpTxnSeq);
/* org txn seq */
		PutField_CString(hNewContext,"org_txn_seq",csTxnSeq);

/* local tm date */
		if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
			PutField_CString(hNewContext,"local_tm_date",csPtr);
		}
/* local tm time */
		if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
			PutField_CString(hNewContext,"local_tm_time",csPtr);
		}
/* add user */
		if (GetField_CString(hRequest,"add_user",&csPtr)) {
			PutField_CString(hNewContext,"add_user",csPtr);
			PutField_CString(hNewContext,"update_user",csPtr);
		}
/* ip addr */
		if (GetField_CString(hRequest,"ip_addr",&csPtr)) {
			PutField_CString(hReq,"ip_addr",csPtr);
		}
/* host_posting_date */
		if (GetField_CString(hContext,"PHDATE",&csPtr)) {
			PutField_CString(hNewContext,"PHDATE",csPtr);
		}
	
		PutField_CString(hNewContext,"channel_code",PD_CHANNEL_OMT);
		PutField_CString(hNewContext,"txn_code",PD_OFL_MERCHANT_BAL_TFT);
		PutField_CString(hNewContext,"process_code",PD_PROCESS_CODE_DEF);
		PutField_CString(hNewContext,"process_type",PD_PROCESS_TYPE_DEF);

/* txn amt */	
		PutField_Double(hNewContext,"txn_amt",dTxnAmt);
/* update context */
		ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateContext");
               	iRet = (unsigned long)(*ChannelObjPtr)(hContext);


		PutField_CString(hNewContext,"merchant_id",csToMid);
		PutField_CString(hNewContext,"service_code",csToService);
		PutField_CString(hNewContext,"txn_ccy",csFromCcy);
		PutField_CString(hNewContext,"dst_txn_ccy",csToCcy);
		PutField_CString(hNewContext,"bal_ccy",csToCcy);
DEBUGLOG(("Authorize() dst_txn_ccy = [%s]\n",csToCcy));
		PutField_CString(hNewContext,"txn_country",csCountry);
		PutField_CString(hNewContext,"net_ccy",csToCcy);

		PutField_CString(hReq,"merchant_id",csToMid);
		PutField_CString(hReq,"service_code",csToService);
/* txn currency will be same as source */
		//PutField_CString(hReq,"txn_ccy",csFromCcy);
		PutField_CString(hReq,"txn_ccy",csToCcy);
		PutField_CString(hReq,"txn_country",csCountry);

/* update merchant info */
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo to merchant\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hNewContext,hReq);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo for To Merchant = [%d]\n",iRet));

		if (iRet == PD_OK) {
			if (GetField_CString(hNewContext, "merchant_client_id", &csToClientID)) {
DEBUGLOG(("Authorize()(TO) Client ID = [%s]\n", csToClientID));
			}
		}

/* Add New Txn */
		if (iRet == PD_OK) {
			PutField_CString(hReq,"txn_ccy",csFromCcy);

			ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
               		iRet = (unsigned long)(*ChannelObjPtr)(hNewContext,hReq);
		}
		else {
			RemoveField_Int(hNewContext,"internal_error");
			PutField_Int(hContext,"internal_error",iRet);
		}



		if ( iRet == PD_OK) {
/* GetExchangeInfo */
DEBUGLOG(("Authorize:: Call Exchange\n"));
			//Exchange Markup is apply to the receiver
			PutField_CString(hNewContext,"txn_code",PD_OFL_MERCHANT_BAL_TFT);
			PutField_CString(hReq,"txn_ccy",csFromCcy);

                        BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
                        iRet = (unsigned long)(*BOObjPtr)(hNewContext,hReq);
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo = [%d]\n",iRet));


			if (GetField_Double(hNewContext, "dst_txn_amt", &dDstTxnAmt)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo dst_txn_amt [%f]\n", dDstTxnAmt));
			}

			if (GetField_Double(hNewContext, "ex_rate", &dExRate)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo ex_rate [%f]\n", dExRate));
			}
			if (GetField_Double(hNewContext, "markup_rate", &dTmp)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_rate [%f]\n", dTmp));
			}
			if (GetField_Double(hNewContext, "markup_amt", &dMarkupAmt)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_amt [%f]\n", dMarkupAmt));
			}

			if (GetField_CString(hNewContext, "markup_ccy", &csMarkupCcy)) {
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo markup_ccy [%s]\n", csMarkupCcy));
				if (dMarkupAmt > 0.0) {
					if (strcmp(csMarkupCcy, csToCcy)) {
						dMarkupAmt = dMarkupAmt * dExRate;
DEBUGLOG(("Authorize() BOExchange->GetExchangeInfo converted markup_ccy [%s] markup_amt [%lf]\n", csToCcy, dMarkupAmt));

                                                PutField_Double(hNewContext, "markup_amt", dMarkupAmt);
                                                PutField_CString(hNewContext, "markup_ccy", csToCcy);
	
					}
				}
			}
                }

/* net amount */
		if (iRet == PD_OK) {
			//txn_code back to TFF
			//PutField_CString(hNewContext,"txn_code",PD_MERCHANT_BAL_TFF);
			PutField_CString(hNewContext,"txn_code",PD_OFL_MERCHANT_BAL_TFF);


/* check from fee */ 
			PutField_CString(hReq,"merchant_id",csFromMid); // to get the source rule
			PutField_CString(hNewContext,"merchant_client_id",csFromClientID); // to get the source rule
			PutField_CString(hReq,"service_code",csFromService ); // to get the source rule

DEBUGLOG(("[%s][%s][%s]\n",csFromMid, csFromClientID, csFromService));

                        BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                        iRet = (unsigned long)(*BOObjPtr)(hNewContext,hReq);

			PutField_CString(hReq,"merchant_id",csToMid); 
			PutField_CString(hNewContext,"merchant_client_id",csToClientID); 
			PutField_CString(hReq,"service_code",csToService ); 
			
			//GetField_Double(hNewContext,"total_src_txn_fee",&dTotalFee);
			GetField_Double(hNewContext,"total_dst_txn_fee",&dTotalFee);
DEBUGLOG(("Authorize total fee = [%lf]\n",dTotalFee));

			dNetAmt = dDstTxnAmt - dTotalFee;
			PutField_Double(hNewContext, "net_amt", dNetAmt);
DEBUGLOG(("Authorize:: dst net amt = [%lf]\n",dNetAmt));

                }

		//PutField_CString(hNewContext,"txn_code",PD_MERCHANT_BAL_TFT);
		PutField_CString(hNewContext,"txn_code",PD_OFL_MERCHANT_BAL_TFT);

/* update merchant balance */
                if (iRet == PD_OK) {
DEBUGLOG(("Authorize call ProcessMerchantAdjAmount\n"));

			PutField_Char(hNewContext, "dc_type", PD_IND_CREDIT);
			PutField_CString(hNewContext, "txn_ccy", csToCcy);

                        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","ProcessMerchantAdjAmount");
                        iRet = (unsigned long)(*BOObjPtr)(hNewContext);
                }

		if (iRet == PD_OK) {
			PutField_CString(hContext,"from_txn_seq",(char*)csTmpTxnSeq);
			PutField_CString(hContext,"org_txn_ccy",csToCcy);
			PutField_CString(hContext,"amount_type",PD_CR);

			dTmp = dDstTxnAmt;
			PutField_Double(hContext,"org_txn_amt",dTmp);

DEBUGLOG(("TxnOmtByUsOTF:: Call BOOLTxnElements:AddTxnAmtElement\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnAmtElement");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsOTF:: ret from AddTxnAmtElements = [%d]\n",iRet));
		}

		if (iRet == PD_OK) {
			if (dMarkupAmt > 0.0) {
DEBUGLOG(("TxnOmtByUsOTF:: Prepare Call BOOLTxnElements:AddMarkupAmtElement\n"));
				if (GetField_CString(hNewContext,"dst_txn_ccy",&csTmp)) {
					PutField_CString(hContext, "dst_txn_ccy", csTmp);
				}

				PutField_Char(hContext, "org_party_type", PD_TYPE_MERCHANT);
	
				if (GetField_Double(hNewContext, "markup_rate", &dTmp)) {
					PutField_Double(hContext, "markup_rate", dTmp);
				}
				PutField_Double(hContext, "markup_amt", dMarkupAmt);
				PutField_CString(hContext,"amount_type",PD_DR);

DEBUGLOG(("TxnOmtByUsOTF:: Call BOOLTxnElements:AddMarkupAmtElement\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddMarkupAmtElement");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsOTF:: BOOLTxnElements: AddMarkupAmtElement result = [%d]\n",iRet));
			}
		}

		
		if (iRet == PD_OK) {
			PutField_CString(hContext,"src_txn_fee_ccy",csToCcy);
			PutField_Double(hContext,"src_txn_fee",dTotalFee);
			PutField_CString(hContext,"amount_type",PD_DR);
DEBUGLOG(("TxnOmtByUsOTF:: Call BOOLTxnElements:AddTxnFeeElement\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnFeeElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsOTF:: BOOLTxnElements: AddTxnFeeElements result = [%d]\n",iRet));
		}
		

                if (iRet == PD_OK) {
DEBUGLOG(("Authorize call UpdateTxnDetailLog\n"));
                        ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnDetailLog");
                        iRet = (unsigned long)(*ChannelObjPtr)(hNewContext,hReq,hResponse);
                }

/* update txn header */
		if (iRet == PD_OK || GetField_Int(hNewContext,"internal_error",&iInternalErr)) {
			char* csBuf = (char*) malloc (128);
                	sprintf(csBuf,"%d",iInternalErr);
                	PutField_CString(hNewContext,"response_code",csBuf);
			PutField_Int(hNewContext,"internal_code",iInternalErr);
DEBUGLOG(("Result_Code = %s\n",csBuf));
                	FREE_ME(csBuf);

                        PutField_Char(hNewContext,"status",PD_COMPLETE);
                        PutField_CString(hNewContext,"sub_status",PD_APPROVED);
                        PutField_CString(hContext,"sub_status",PD_APPROVED);

			if (iInternalErr != 0 ) {
                       	 	PutField_Char(hNewContext,"ar_ind",PD_REJECT);
                	}
			else {
				PutField_Char(hNewContext,"ar_ind",PD_ACCEPT);
			}


			if (GetField_CString(hNewContext, "approval_date", &csTmp)) {
DEBUGLOG(("Authorize:: newcontext approval_date [%s]\n", csTmp));
			}
			if (GetField_CString(hNewContext, "approval_timestamp", &csTmp)) {
DEBUGLOG(("Authorize:: newcontext approval_timestamp [%s]\n", csTmp));
			}
			
			ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnLog");
               		iRet = (unsigned long)(*ChannelObjPtr)(hNewContext,hReq,hResponse);
		}


		hash_destroy(hReq);
        	FREE_ME(hReq);
		hash_destroy(hNewContext);
        	FREE_ME(hNewContext);
        }

	if (iRet == PD_OK) {
		
		if (GetField_CString(hContext, "approval_date", &csTmp)) {
DEBUGLOG(("Authorize:: context approval_date [%s]\n", csTmp));
		}
		if (GetField_CString(hContext, "approval_timestamp", &csTmp)) {
DEBUGLOG(("Authorize:: context approval_timestamp [%s]\n", csTmp));
		}
	}

DEBUGLOG(("TxnOmtByUsOTF Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
