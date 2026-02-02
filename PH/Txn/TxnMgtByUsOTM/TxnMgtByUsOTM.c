/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/09/28              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsOTM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsOTM(char    cdebug)
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
	char    *csTxnCountry=strdup("");
	char	*csTxnCcy = NULL;
	char	*csDstTxnCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csTmp = NULL;
	double	dOrgAmt = 0.0;
	double	dDstAmt = 0.0;
	double	dTmp = 0.0;
	char	cTmp;

	double	dMarkupAmt = 0.0;
	double	dExRate = 0.0;
	char	*csMarkupCcy = NULL;

	char	cDCInd;
	char	*csTxnSeq;

	hash_t	*hReq;
	hReq = (hash_t*) malloc(sizeof(hash_t));

	hash_init(hReq, 0);

	if (GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hContext, "from_txn_seq", csTxnSeq);
	}	
	else {
DEBUGLOG(("Authorize::txn_seq not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::txn_seq not found!!\n");
		iRet=INT_ERR; 
		PutField_Int(hContext,"internal_error",iRet);
	}

	
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}

/* remark */
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark= [%s]\n",csTmp));
		PutField_CString(hContext,"remark",csTmp);
	}

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hContext,"merchant_id",csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hContext,"service_code",csServiceCode);
	}
	else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"dst_txn_ccy",&csDstTxnCcy)){
DEBUGLOG(("Authorize::dst_txn_ccy= [%s]\n",csDstTxnCcy));
		PutField_CString(hContext,"dst_txn_ccy",csDstTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::dst_ccy not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::dst_ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}


	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hContext,"txn_country",csTxnCountry);
	}
	else{
/*
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBService","FindCountryByService");
                        if ((unsigned long)(DBObjPtr)(csServiceCode,csTxnCountry) == PD_FOUND) {
                                PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::Found Country [%s] for Service [%s]\n",csTxnCountry,csServiceCode));
                        }
                        else{
                                iRet = INT_INVALID_SERVICE_CODE;
DEBUGLOG(("Authorize::invalid service code[%s]\n",csServiceCode));
ERRLOG("TxnMgtByUsOTM:Authorize::invalid service code [%s]\n",csServiceCode);

                                PutField_Int(hContext,"internal_error",iRet);
                        }
                }
*/
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}


	if(GetField_Double(hContext,"txn_amt",&dOrgAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dOrgAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsOTM::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}


	if (iRet == PD_OK) {
		PutField_CString(hReq, "merchant_id", csMerchantId);
		PutField_CString(hReq, "service_code", csServiceCode);
		PutField_CString(hReq, "txn_ccy", csDstTxnCcy);
		PutField_CString(hReq, "txn_country", csTxnCountry);
		
DEBUGLOG(("Authorize() BOMerchant->GetMerchantTxnInfo\n"));
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hReq);
DEBUGLOG(("Authorize() BOMerchant->GetMerchantTxnInfo = [%d]\n",iRet));
	}


	if (iRet == PD_OK) {


		BOObjPtr = CreateObj(DBPtr,"BOExchange","GetExchangeInfo");
		if ((*BOObjPtr)(hContext,hRequest) == PD_OK) {
DEBUGLOG(("GetExternalExchangeInfo Success\n"));
			if(GetField_Double(hContext,"dst_txn_amt",&dDstAmt)){
DEBUGLOG(("Destination Amount=[%lf]\n",dDstAmt));
				PutField_Double(hContext, "txn_amt", dDstAmt);
				PutField_CString(hContext,"txn_ccy", csDstTxnCcy);
				PutField_CString(hRequest,"txn_ccy", csDstTxnCcy);
			}

                        if(GetField_Double(hContext,"ex_rate",&dExRate)){
DEBUGLOG(("Exchange rate=[%lf]\n",dExRate));
                        }

                        if(GetField_Double(hContext,"markup_amt",&dMarkupAmt)){
DEBUGLOG(("Markup Amount=[%lf]\n",dMarkupAmt));
                        }
                        if(GetField_Double(hContext,"markup_rate",&dTmp)){
DEBUGLOG(("Markup rate=[%lf]\n",dTmp));
                        }
                        if(GetField_Char(hContext,"ex_party",&cTmp)){
                                PutField_Char(hContext,"ex_supplier",cTmp);
DEBUGLOG(("Exchange Party=[%c]\n",cTmp));
                        }

			if (GetField_CString(hContext, "markup_ccy", &csMarkupCcy)) {
DEBUGLOG(("Markup ccy =[%s]\n", csMarkupCcy));
			}

			if (dMarkupAmt > 0.0) {
				if (strcmp(csMarkupCcy, csDstTxnCcy)) {
					dMarkupAmt = dMarkupAmt * dExRate;

DEBUGLOG(("Actaul Markup amt [%lf] in Ccy [%s]\n", dMarkupAmt, csDstTxnCcy));
	
					PutField_Double(hContext, "markup_amt", dMarkupAmt);
					PutField_CString(hContext, "markup_ccy", csDstTxnCcy);
				}
			}

			dTmp = dDstAmt + dMarkupAmt;
			PutField_Double(hContext, "txn_amt", dTmp); 

		}
		else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize::GetExchangeInfo Error\n"));
ERRLOG("TxnMgtByUsOTM:Authorize::GetExchangeInfo Error\n");
                }
	}
	

	PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
	PutField_Char(hContext, "dc_ind", PD_IND_CREDIT); 
	PutField_Int(hContext, "balance_transfer", PD_TRUE); 

	PutField_CString(hContext, "selected_pay_method", PD_ALL_METHOD); // for find Fee


	// **************** Get Fee ***************
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));


		//PutField_CString(hRequest,"txn_ccy",csTxnCcy);

		BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
		if ((unsigned long)((*BOObjPtr)(hContext, hRequest)) != PD_OK)  {
DEBUGLOG(("Authorize::BOFee:GetTxnFee Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsOTM::BOFee::GetTxnFee Failed Ret [%d]\n", iRet);
			iRet = INT_ERR;
		}
		else {
                        if (GetField_Double(hContext, "dst_txn_fee", &dTmp)) {
DEBUGLOG(("Authorize::BOFee:GetTxnFee dst_txn_fee [%lf]\n", dTmp));
				PutField_Double(hContext, "src_txn_fee", dTmp);
                        }
                        else {
                                dTmp = 0.0;
                                PutField_Double(hContext, "src_txn_fee", dTmp);
DEBUGLOG(("Authorize::BOFee:GetTxnFee dst_txn_fee (by default) [%lf]\n", dTmp));
                        }

                        if (GetField_CString(hContext, "dst_txn_fee_ccy", &csTmp)) {
DEBUGLOG(("Authorize::BOFee:GetTxnFee dst_txn_fee_ccy [%s]\n", csTmp));
                                PutField_CString(hContext, "src_txn_fee_ccy", csTmp);
			
                        }
                        else {
                                PutField_CString(hContext, "src_txn_fee_ccy", csDstTxnCcy);
                        }

		}

		RemoveField_Double(hContext, "dst_txn_fee");
	}

	RemoveField_CString(hContext, "selected_pay_method");

        //Update Balance
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOAdjustment","ProcessPartyBalance");
                iRet = (unsigned long)((*BOObjPtr)(hContext));

                if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsMTO::BOADjustment::ProcesspartyBalance Failed Ret [%d]\n", iRet);
                } else {
                        if (GetField_Char(hContext,"dc_ind",&cDCInd)) {
DEBUGLOG(("Authorize::dc_ind = [%c]\n", cDCInd));
                                if (cDCInd == PD_ADJ_TYPE_CREDIT) {
                                        PutField_CString(hContext, "amount_type", PD_CR);
                                }
                                else if (cDCInd == PD_ADJ_TYPE_DEBIT) {
                                        PutField_CString(hContext, "amount_type", PD_DR);
                                }

                                if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance merchant_open_bal [%lf]\n", dTmp));
                                        PutField_Double(hContext, "open_bal", dTmp);
                                }

                                if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance merchant_open_bal_settlement [%lf]\n", dTmp));
                                        PutField_Double(hContext, "open_bal_settlement", dTmp);
                                }


                        }
                        else {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed to get dc_ind\n"));
ERRLOG("TxnMgtByUsMTO::BOADjustment::ProcesspartyBalance Failed to get dc_ind\n");
                                iRet = PD_ERR;
                        }


                }
        }


	if (iRet == PD_OK) {
		PutField_Double(hContext, "txn_amt", dOrgAmt);
		PutField_CString(hContext,"txn_ccy", csTxnCcy);
		PutField_CString(hContext,"net_ccy",csDstTxnCcy);
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
                ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnDetailLog");
                if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
                        iRet = INT_ERR;
                }
	}

	if (iRet == PD_OK) {
		/*
		GetField_CString(hContext, "PHDATE", &csTmp);

		// for add approve timestamp
		PutField_CString(hContext, "approval_date", csTmp);
		*/

		if (GetField_CString(hContext, "approval_date", &csTmp)) {
DEBUGLOG(("Authorize:: approval_date [%s]\n", csTmp));
		}
		if (GetField_CString(hContext, "approval_timestamp", &csTmp)) {
DEBUGLOG(("Authorize:: approval_timestamp[%s]\n", csTmp));
		}

		PutField_CString(hContext, "sub_status", PD_APPROVED);
		
	}


        if (iRet == PD_OK) {
		//dTmp = dDstAmt + dMarkupAmt;
		dTmp = dDstAmt;

		PutField_Double(hContext, "org_txn_amt", dTmp);
		PutField_CString(hContext, "org_txn_ccy",csDstTxnCcy);
                PutField_CString(hContext, "amount_type", PD_CR);

DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnAmtElement\n"));
                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
                        iRet = INT_ERR;
                }

        }

	if (iRet == PD_OK) {
                PutField_CString(hContext, "amount_type", PD_DR);
		PutField_Char(hContext, "org_party_type", PD_TYPE_MERCHANT);
		//PutField_Char(hContext, "org_party_type", PD_TYPE_CUSTOMER);

		if (dMarkupAmt > 0.0)  {
DEBUGLOG(("Authorize::Call BOTxnElements:AddMarkupAmtElement\n"));

	                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddMarkupAmtElement");
			if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
                        	iRet = INT_ERR;
                	}
		}
		
	}


        if (iRet == PD_OK) {
                PutField_CString(hContext, "amount_type", PD_DR);

DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnFeeElements\n"));
                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
                if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
                        iRet = INT_ERR;
                }

        }


	if (iRet == PD_OK) {
		PutField_CString(hResponse, "org_txn_seq", csTxnSeq);
	}

	hash_destroy(hReq);
	FREE_ME(hReq);


	FREE_ME(csTxnCountry);
DEBUGLOG(("TxnMgtByUsOTM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
