/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/17              Virginia Yun
add mini-mmm checking				   2015/12/02              LokMan Chow
PRD067 Manual input exchange rate		   2017/04/24		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsFPM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsFPM(char	cdebug)
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
	char	*csDstTxnCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csTmp = NULL;
	double	dOrgAmt = 0.0;
	double	dDstAmt = 0.0;
	double	dTmp = 0.0;
	char	cTmp;
	int	iId = 0;
	char    csId[PD_TXN_SEQ_LEN+1];

	double	dMarkupAmt = 0.0;
	double	dExRate = 0.0;
	char	*csMarkupCcy = NULL;

	int     iSkipTolCheck=PD_FALSE;
	int     iMiniMMMOn = PD_FALSE;
	int     iSupportMiniMMM = PD_FALSE;
	int     iRetErrIfNotMi = PD_FALSE;

	char	*csInputRate = NULL;
	char	*csRefRateType = NULL;
	char	*csRefRate = NULL;
	char	*csMinRefTol = NULL;
	char	*csMaxRefTol = NULL;
	char	*csMinRefRate = NULL;
	char	*csMaxRefRate = NULL;
	int	iExceedTol;

	hash_t	*hReq;
	hReq = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hReq, 0);
	hash_t	*hTxn;
	hTxn = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);
	hash_t  *hTxnExDt;
	hTxnExDt = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hTxnExDt, 0);

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
ERRLOG("TxnMgtByUsFPM::Authorize::merchant_id not found!!\n");
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
ERRLOG("TxnMgtByUsFPM::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_ccy */
	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* dst_txn_ccy */
	if(GetField_CString(hRequest,"dst_txn_ccy",&csDstTxnCcy)){
DEBUGLOG(("Authorize::dst_txn_ccy= [%s]\n",csDstTxnCcy));
		PutField_CString(hContext,"dst_txn_ccy",csDstTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::dst_ccy not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::dst_ccy not found!!\n");
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
ERRLOG("TxnMgtByUsFPM:Authorize::invalid service code [%s]\n",csServiceCode);

				PutField_Int(hContext,"internal_error",iRet);
			}
		}
*/
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_amt */
	if(GetField_Double(hContext,"txn_amt",&dOrgAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dOrgAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"skip_tol_check",&csTmp)){
		iSkipTolCheck = atoi(csTmp);
DEBUGLOG(("Authorize::skip_tol_check = [%d]\n",iSkipTolCheck));
	}
	else{
DEBUGLOG(("Authorize::skip_tol_check (default) = [%d]\n",iSkipTolCheck));
	}

/* input_rate */
	if (GetField_CString(hRequest, "input_rate", &csInputRate)) {
		if (sscanf(csInputRate, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::input_rate = [%lf]\n", dTmp));
			PutField_Double(hContext, "input_ex_rate", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid input_rate!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid input_rate!!\n");
			iRet = INT_EX_RATE_ERROR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::input_rate not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::input_rate not found!!\n");
		iRet = INT_EX_RATE_ERROR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* ref_rate_type */
	if (GetField_CString(hRequest, "ref_rate_type", &csRefRateType)) {
DEBUGLOG(("Authorize::ref_rate_type = [%s]\n", csRefRateType));
		PutField_CString(hTxnExDt, "ref_ex_rate_type", csRefRateType);
	} else {
DEBUGLOG(("Authorize::ref_rate_type not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::ref_rate_type not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* ref_rate */
	if (GetField_CString(hRequest, "ref_rate", &csRefRate)) {
		if (sscanf(csRefRate, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::ref_rate = [%lf]\n", dTmp));
			PutField_Double(hTxnExDt, "ref_ex_rate", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid ref_rate!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid ref_rate!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::ref_rate not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::ref_rate not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* min_ref_tol */
	if (GetField_CString(hRequest, "min_ref_tol", &csMinRefTol)) {
		if (sscanf(csMinRefTol, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::min_ref_tol = [%lf]\n", dTmp));
			PutField_Double(hTxnExDt, "min_ref_tolerance", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid min_ref_tol!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid min_ref_tol!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::min_ref_tol not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::min_ref_tol not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* max_ref_tol */
	if (GetField_CString(hRequest, "max_ref_tol", &csMaxRefTol)) {
		if (sscanf(csMaxRefTol, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::max_ref_tol = [%lf]\n", dTmp));
			PutField_Double(hTxnExDt, "max_ref_tolerance", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid max_ref_tol!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid max_ref_tol!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::max_ref_tol not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::max_ref_tol not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* min_ref_rate */
	if (GetField_CString(hRequest, "min_ref_rate", &csMinRefRate)) {
		if (sscanf(csMinRefRate, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::min_ref_rate = [%lf]\n", dTmp));
			PutField_Double(hTxnExDt, "min_ref_ex_rate", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid min_ref_rate!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid min_ref_rate!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::min_ref_rate not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::min_ref_rate not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* max_ref_rate */
	if (GetField_CString(hRequest, "max_ref_rate", &csMaxRefRate)) {
		if (sscanf(csMaxRefRate, "%lf", &dTmp) == 1) {
DEBUGLOG(("Authorize::max_ref_rate = [%lf]\n", dTmp));
			PutField_Double(hTxnExDt, "max_ref_ex_rate", dTmp);
		} else {
DEBUGLOG(("Authorize::invalid max_ref_rate!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::invalid max_ref_rate!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	} else {
DEBUGLOG(("Authorize::max_ref_rate not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::max_ref_rate not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* exceed_tol */
	if (GetField_CString(hRequest, "exceed_tol", &csTmp)){
		iExceedTol = atoi(csTmp);
DEBUGLOG(("Authorize::exceed_tol = [%d]\n", iExceedTol));
	} else {
DEBUGLOG(("Authorize::exceed_tol not found!!\n"));
ERRLOG("TxnMgtByUsFPM::Authorize::exceed_tol not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
	}

	/* GetMerchantTxnInfo */
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

	/* GetExchangeInfo */
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

		}
		else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize::GetExchangeInfo Error\n"));
ERRLOG("TxnMgtByUsFPM:Authorize::GetExchangeInfo Error\n");
		}
	}
	

	PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
	PutField_Char(hContext, "dc_ind", PD_IND_CREDIT); 
	PutField_Int(hContext, "chg_bal_mode", PD_TRUE); 


	// **************** Get Fee ***************
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));


		//PutField_CString(hRequest,"txn_ccy",csTxnCcy);

		BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
		if ((unsigned long)((*BOObjPtr)(hContext, hRequest)) != PD_OK) {
DEBUGLOG(("Authorize::BOFee:GetTxnFee Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsFPM::BOFee::GetTxnFee Failed Ret [%d]\n", iRet);
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
				PutField_CString(hContext, "src_txn_fee_ccy", csTxnCcy);
			}

		}

		RemoveField_Double(hContext, "dst_txn_fee");
	}



	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOBalance: ProcessFundinPayout\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessFundinPayout");
		iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (GetField_Double(hContext, "net_amt", &dTmp)) {
DEBUGLOG(("Authorize::Call BOBalance: ProcessFundinPayout net_amt [%lf]\n", dTmp));
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

	//check Mini-MMM Mode
	if (iRet == PD_OK) {
		char*   csValue;
		csValue = (char*) malloc (128);
		DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
		if ((unsigned long)(DBObjPtr)(PD_MINI_MMM_ENABLE,csValue) == FOUND) {
DEBUGLOG(("Mini-MMM Mode = [%s]\n",csValue));
			if (!strcmp(csValue, PD_ENABLE_MMSMODE)){
				iMiniMMMOn = PD_TRUE;
			}
		}
		FREE_ME(csValue);
	}

	//check mi_mode_txn_ctl
	if(iRet == PD_OK && iMiniMMMOn){
		hash_t  *hCtl;
		hCtl = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hCtl,0);

		DBObjPtr = CreateObj(DBPtr,"DBMiModeTxnCtl","GetMiModeTxnCtl");
		iRet = (unsigned long) (*DBObjPtr)(PD_MI_TXN_TYPE_MERCH_FUNDIN,hCtl);
		if(iRet == PD_OK){
			GetField_Int(hCtl,"err_if_not_mi",&iRetErrIfNotMi);
			GetField_Int(hCtl,"mi_support",&iSupportMiniMMM);
			if(!iSupportMiniMMM){
				iMiniMMMOn = PD_FALSE;
DEBUGLOG(("Authorize() this transaction type does not support Mini-MMM mode\n"));
			}
			else{
DEBUGLOG(("Authorize() this transaction type support Mini-MMM mode\n"));
			}
		}
		else{
			iRet = INT_ERR;
DEBUGLOG(("Authorize() Call DBMiModeTxnCtl:GetMiModeTxnCtl() Failed!!\n"));
ERRLOG("TxnMgtByUsFPM:: Authorize() Call DBMiModeTxnCtl:GetMiModeTxnCtl() Failed!!\n");
		}

		FREE_ME(hCtl);
	}

	if(!iMiniMMMOn && iRetErrIfNotMi){
		iRet = INT_MINI_MMM_MODE_DISABLED;
	}

	if(iRet==PD_OK && !iMiniMMMOn){
		PutField_Double(hRequest,"bank_amt",dOrgAmt);
		PutField_CString(hRequest,"bank_ccy",csTxnCcy);
		PutField_Double(hRequest,"fin_amt",dOrgAmt);
		PutField_CString(hRequest,"fin_ccy",csTxnCcy);
		PutField_Int(hRequest,"skip_tol_check",iSkipTolCheck);
DEBUGLOG(("Authorize::Call TxnMgtByUsFIR\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnMgtByUsFIR","Authorize");
		iRet = (unsigned long)((*TxnObjPtr)(hContext, hRequest, hResponse));
		if(iRet!=PD_OK){
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
                        if(GetField_Int(hContext,"fundsin_id",&iId)){
DEBUGLOG(("Authorize::TxnMgtByUsFIR return fundsin_id[%d]\n",iId));
                                sprintf(csId,"%d",iId);
                                PutField_CString(hTxn,"td_batch_id",csId);
				//Update td_batch_id
				PutField_CString(hTxn,"txn_seq",csTxnId);
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
				if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
DEBUGLOG(("Authorize::TxnMgtByUsFIR DBTransaction->UpdateDetail Failed\n"));
				}
                        }
                }
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "txn_seq", &csTxnId)) {
			PutField_CString(hTxnExDt, "txn_seq", csTxnId);
		}

		PutField_CString(hTxnExDt, "add_user", csUser);

		DBObjPtr = CreateObj(DBPtr, "DBTxnExDetail", "Add");
		if ((unsigned long)(*DBObjPtr)(hTxnExDt) != PD_OK) {
DEBUGLOG(("Authorize::TxnMgtByUsFPM DBTxnExDetail->Add Failed\n"));
		}
	}

	if (iRet == PD_OK && iExceedTol) {
		int iTmpRet = 0;
		int iDynCnt = 0;

		char csRefRateTypeDesc[PD_TMP_BUF_LEN];
		char csStr[PD_TMP_BUF_LEN];

		hash_t *hTmp;
		hTmp = (hash_t *) malloc (sizeof(hash_t));
		hash_init(hTmp, 0);

		time_t tNow;
		struct tm * tStruct;
		char csBuf[PD_TMP_BUF_LEN];

		PutField_CString(hTmp, "source", "BATCH");
		PutField_CString(hTmp, "funct", "MERCH_FUND_IN");
		PutField_Char(hTmp, "party_type", 'G');
		PutField_CString(hTmp, "party_id", "000");

		tNow = time(0);
		tStruct = localtime(&tNow);
		strftime(csBuf, sizeof(csBuf), "%d-%m-%Y %H:%M:%S", tStruct);
		iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "ALERT_TIME", "GLO", "STR", csBuf);

		if (GetField_CString(hContext, "txn_seq", &csTxnId)) {
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "TXN_ID", "GLO", "STR", csTxnId);
		}

		if (GetField_CString(hContext, "merchant_short_name", &csTmp)) {
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "MERCH_SHORT_NAME", "GLO", "STR", csTmp);
		}

		if (csInputRate != NULL) {
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "EX_RATE", "GLO", "STR", csInputRate);
		}

		if (csRefRateType != NULL) {
			if (!strcmp(csRefRateType, "MAXASK"))
				strcpy(csRefRateTypeDesc, "Max Ask");
			else if (!strcmp(csRefRateType, "MEDASK"))
				strcpy(csRefRateTypeDesc, "Med Ask");
			else if (!strcmp(csRefRateType, "MINASK"))
				strcpy(csRefRateTypeDesc, "Min Ask");
			else if (!strcmp(csRefRateType, "MAXBID"))
				strcpy(csRefRateTypeDesc, "Max Bid");
			else if (!strcmp(csRefRateType, "MEDBID"))
				strcpy(csRefRateTypeDesc, "Med Bid");
			else if (!strcmp(csRefRateType, "MINBID"))
				strcpy(csRefRateTypeDesc, "Min Bid");

			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "REF_EX_RATE_TYPE", "GLO", "STR", csRefRateTypeDesc);
		}

		if (csRefRate != NULL) {
			if (!strcmp(csMinRefTol, csMaxRefTol)) {
				sprintf(csStr, "%s (±%s%% of Current %s is from %s to %s)", csRefRate, csMaxRefTol, csRefRateTypeDesc, csMinRefRate, csMaxRefRate);
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "REF_EX_RATE", "GLO", "STR", csStr);
				sprintf(csStr, "Merchant Fund In - Exchange Rate exceeds ±%s%% of Current Min Bid", csMaxRefTol);
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "DYNAMIC_MAIL_SUBJECT", "GLO", "STR", csStr);
			} else {
				sprintf(csStr, "%s (-%s%% and +%s%% of Current %s is from %s to %s)", csRefRate, csMinRefTol, csMaxRefTol, csRefRateTypeDesc, csMinRefRate, csMaxRefRate);
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "REF_EX_RATE", "GLO", "STR", csStr);
				sprintf(csStr, "Merchant Fund In - Exchange Rate exceeds -%s%% or +%s%% of Current Min Bid", csMinRefTol, csMaxRefTol);
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "DYNAMIC_MAIL_SUBJECT", "GLO", "STR", csStr);
			}
		}

		if (csTxnCcy != NULL && dOrgAmt != 0.0) {
			sprintf(csStr, "%s %.2f", csTxnCcy, dOrgAmt);
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "MERCH_REQ_AMT", "GLO", "STR", csStr);
		}

		if (GetField_CString(hContext, "src_txn_fee_ccy", &csTmp) && GetField_Double(hContext, "src_txn_fee", &dTmp)) {
			if (dTmp > 0.0) {
				sprintf(csStr, "%s %.2f", csTmp, dTmp);
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "TXN_FEE", "GLO", "STR", csStr);
			} else {
				iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "TXN_FEE", "GLO", "STR", "0.00");
			}
		}

		if (csDstTxnCcy != NULL && GetField_Double(hContext, "net_amt", &dTmp)) {
			sprintf(csStr, "%s %.2f", csDstTxnCcy, dTmp);
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "MERCH_REC_NET_AMT", "GLO", "STR", csStr);
		}

		if (csDstTxnCcy != NULL && dMarkupAmt != 0.0) {
			sprintf(csStr, "%s %.2f", csDstTxnCcy, dMarkupAmt);
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "MARKUP_AMT", "GLO", "STR", csStr);
		} else {
			iDynCnt = set_tpl_dyn_cstring(hTmp, iDynCnt, "MARKUP_AMT", "GLO", "STR", "0.00");
		}

		PutField_Int(hTmp, "total_dyn", iDynCnt);

DEBUGLOG(("Authorize::TxnMgtByUsFPM call BOAlertEmail::ProcessTpl\n"));
		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iTmpRet = (unsigned long)(*BOObjPtr)(hTmp);

		hash_destroy(hTmp);
		FREE_ME(hTmp);
	}

	if (iRet == PD_OK) {
		GetField_CString(hContext, "PHDATE", &csTmp);

		// for add approve timestamp
		//PutField_CString(hContext, "approval_date", csTmp);
		PutField_CString(hContext, "sub_status", PD_APPROVED);
		
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"txn_seq",&csTxnId)){
			PutField_CString(hResponse,"org_txn_seq",csTxnId);
		}
	}

	hash_destroy(hReq);
	hash_destroy(hTxnExDt);
	FREE_ME(hReq);
	FREE_ME(hTxnExDt);
	FREE_ME(hTxn);

	FREE_ME(csTxnCountry);
DEBUGLOG(("TxnMgtByUsFPM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
