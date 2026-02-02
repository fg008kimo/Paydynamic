/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/28              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOMP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnOmtByUsOMP(char	cdebug)
{
	cDebug = cdebug;
}

int	Authorize(hash_t* hContext,
			hash_t* hRequest,
			hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csTxnId = NULL;
	char	*csUser = NULL;
	char	*csMerchantId = NULL;
	char	*csTxnCountry=strdup("");
	char	*csTxnCcy = NULL;
	//char	*csDstTxnCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csTmp = NULL;
	double	dOrgAmt = 0.0;
	double	dSrcNetAmt = 0.0;
	//double	dDstAmt = 0.0;
	double	dTmp = 0.0;
	//char	cTmp;
	//int	iId = 0;
	//char    csId[PD_TXN_SEQ_LEN+1];

	//double	dMarkupAmt = 0.0;
	//double	dExRate = 0.0;
	//char	*csMarkupCcy = NULL;

	hash_t	*hReq;
	hReq = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hReq, 0);
	hash_t	*hTxn;
	hTxn = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

/* add_user */
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}

/* merchant_id */
	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hContext,"merchant_id",csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* service_code */
	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hContext,"service_code",csServiceCode);
	}
	else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_ccy */
	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
		PutField_CString(hContext,"net_ccy",csTxnCcy);
		PutField_CString(hContext,"dst_txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_country */
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
ERRLOG("TxnOmtByUsOMP:Authorize::invalid service code [%s]\n",csServiceCode);

				PutField_Int(hContext,"internal_error",iRet);
			}
		}
*/
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_amt */
	if(GetField_Double(hContext,"txn_amt",&dOrgAmt)){
		PutField_Double(hContext,"txn_amt",dOrgAmt);
		PutField_Double(hContext,"net_amt",dOrgAmt);
		PutField_Double(hContext,"dst_txn_amt",dOrgAmt);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dOrgAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* remark */
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
	}


/* GetMerchantTxnInfo */
	if (iRet == PD_OK) {
		PutField_CString(hReq, "merchant_id", csMerchantId);
		PutField_CString(hReq, "service_code", csServiceCode);
		PutField_CString(hReq, "txn_ccy", csTxnCcy);
		PutField_CString(hReq, "txn_country", csTxnCountry);

DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hReq);
DEBUGLOG(("Authorize() BOOLMerchant->GetMerchantTxnInfo = [%d]\n",iRet));
	}

//get fee
	if(iRet == PD_OK){
		BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hReq);
DEBUGLOG(("Authorize() GetTxnFee [%d]\n",iRet));
	}
	if (iRet == PD_OK) {
		GetField_Double(hContext,"total_dst_txn_fee",&dTmp);
DEBUGLOG(("Authorize total fee = [%lf]\n",dTmp));
		PutField_Double(hContext, "actual_txn_fee", dTmp);

		if (GetField_CString(hContext, "dst_txn_fee_ccy", &csTmp)) {
DEBUGLOG(("Authorize fee ccy (from Fee) = [%s]\n",csTmp));
                        PutField_CString(hContext, "actual_txn_fee_ccy", csTmp);
		}

		if (GetField_Double(hContext,"net_amt",&dSrcNetAmt)) {
DEBUGLOG(("Authorize net amount (from Fee) = [%lf]\n",dSrcNetAmt));
		}
	}


	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetOpenBalanceForUpdate");
                iRet = (unsigned long)(*DBObjPtr)(hContext,
                                                  csMerchantId,
						  csTxnCcy,
						  csTxnCountry,
						  csServiceCode);
                if (iRet == PD_OK) {
                        if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize merchant_open_bal = [%lf]\n",dTmp));
                        }
                        if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize merchant_open_bal_settlement = [%lf]\n",dTmp));
                        }
                } else {
DEBUGLOG(("Authorize GetOpenBalanceForUpdate FAILED!\n"));
ERRLOG("TxnOmtByUsOMP::Authorize From GetOpenBalanceForUpdate FAILED\n");
                }

	}

	if(iRet==PD_OK){
		PutField_Char(hContext,"dc_type", PD_IND_CREDIT); 
		PutField_Double(hContext,"actual_net_amt",dSrcNetAmt); 
		//PutField_Double(hContext,"org_actual_prev_ft",dSrcNetAmt);
		//PutField_Double(hContext,"actual_net_amt",dOrgAmt); 
		PutField_Double(hContext,"org_actual_prev_ft",dOrgAmt);

DEBUGLOG(("Authorize() BOOLBalance:ProcessTransferAvaPO\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLBalance","ProcessTransferAvaPayout");
		iRet = (unsigned long)(*BOObjPtr)(hContext);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize() BOOLBalance:ProcessTransferAvaPO FAILED\n"));
ERRLOG("TxnOmtByUsOMP: Authorize() BOOLBalance.ProcessTransferAvaPO FAILED\n");
                }
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnDetailLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "OMTChannel","UpdateTxnDetailLog");
		if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "sub_status", PD_APPROVED);
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"txn_seq",&csTxnId)){
			PutField_CString(hResponse,"org_txn_seq",csTxnId);
		}
	}

	hash_destroy(hReq);
	FREE_ME(hReq);
	FREE_ME(hTxn);

	FREE_ME(csTxnCountry);
DEBUGLOG(("TxnOmtByUsOMP Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
