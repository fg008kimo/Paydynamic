/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/10              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsMSI.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(BO);
OBJPTR(DB);

void TxnWebOnUsMSI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	char*   csHandler = NULL;
        int     iRet = PD_OK;
	char*	csTmp = NULL;
	char*	csPspId;
	char*	csPspChannel;
	double	dTmp;
	hash_t	*hReq,*hRps;

	hReq = (hash_t*) malloc (sizeof(hash_t));
	hRps = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hReq,0);
	hash_init(hRps,0);

	//double	dTmp;

DEBUGLOG(("TxnWebOnUsMSI::Authorize(): Authroize()\n"));

/* txn_code */
	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): txn_code = [%s]\n",csTmp));
		PutField_CString(hReq,"txn_code",csTmp);
	}

/* txn_seq */
	if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): txn_seq = [%s]\n",csTmp));
		PutField_CString(hReq,"order_num",csTmp);
	}

/* psp Url */
	if (GetField_CString(hContext,"psp_url",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_url = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_url",csTmp);
	}

/* psp merchant id */
	if (GetField_CString(hContext,"psp_merchant_id",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_merchant_id = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_merchant_id",csTmp);
	}
/* request_function */
	if (GetField_CString(hContext,"request_function",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): request_function = [%s]\n",csTmp));
		PutField_CString(hReq,"request_function",csTmp);
	}

/* psp_key */
	if (GetField_CString(hContext,"psp_key",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_key = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_key",csTmp);
	}
/* psp_key_id */
	if (GetField_CString(hContext,"psp_key_id",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_key_id = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_key_id",csTmp);
	}
/* psp_key_uid */
	if (GetField_CString(hContext,"psp_key_uid",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_key_uid = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_key_uid",csTmp);
	}

/* txn_ccy */
	if (GetField_CString(hContext,"dst_txn_ccy",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): dst_txn_ccy = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_txn_ccy",csTmp);
	}


/* psp_txn_amt */
	if (GetField_Double(hContext,"dst_txn_amt",&dTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): dst_txn_amt = [%f]\n",dTmp));
		PutField_Double(hReq,"psp_txn_amt",dTmp);
	}

/* return_url_only */

	if (GetField_CString(hContext,"return_url_only",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): return_url_only= [%s]\n",csTmp));
		PutField_CString(hReq,"return_url_only",csTmp);
	}



/* request_function */
	if (GetField_CString(hContext,"request_function",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): request_function = [%s]\n",csTmp));
		PutField_CString(hReq,"request_function",csTmp);
	}

/* action */
	if (GetField_CString(hContext,"action",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): action = [%s]\n",csTmp));
		PutField_CString(hReq,"action",csTmp);
	}

/* url_method */
	if (GetField_CString(hContext,"url_method",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): url_method = [%s]\n",csTmp));
		PutField_CString(hReq,"url_method",csTmp);
	}

/* psp id */
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_id = [%s]\n",csPspId));
		PutField_CString(hReq,"psp_id",csPspId);
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsMSI::Authorize() can't find PSP ID\n");
		iRet = INT_ERR;
	}

/* psp channel code */
	if (GetField_CString(hContext,"psp_channel_code",&csPspChannel)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): psp_channel_code = [%s]\n",csPspChannel));
		PutField_CString(hReq,"psp_channel_code",csPspChannel);
		PutField_CString(hResponse,"psp_channel_code",csPspChannel);
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsMSI::Authorize() can't find PSP Channel Code\n");
		iRet = INT_ERR;
	}

/* customer_tel */
/*
	if (GetField_CString(hRequest,"customer_tel",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): customer_tel = [%s]\n",csTmp));
		PutField_CString(hReq,"customer_tel",csTmp);
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsMSI::Authorize() can't find customer_tel\n");
		iRet = INT_ERR;
	}
*/
	if (GetField_CString(hRequest,"customer_tel",&csTmp)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize(): customer_tel = [%s]\n",csTmp));
		PutField_CString(hReq,"customer_tel",csTmp);
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsMSI::Authorize() can't find customer_tel\n");
		iRet = INT_ERR;
	}


	if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
		PutField_CString(hReq,"local_tm_date",csTmp);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() Format local_tm_date = [%s]\n",csTmp));
	}
	if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
		PutField_CString(hReq,"local_tm_time",csTmp);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() Format local_tm_time = [%s]\n",csTmp));
	}


/* tr_at */
        PutField_CString(hReq,"tr_at","PAY");
/* fcode */
        PutField_CString(hReq,"fcode","TRANSACTION");

	char* csInternalBankCode;
	char* csOrgTxnCountry;
	char    csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];

/* internal bank code */
	if (GetField_CString(hContext,"bank_code",&csInternalBankCode)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize() internal bank_code = [%s]\n",csInternalBankCode));
	}
	if (GetField_CString(hRequest,"txn_country",&csOrgTxnCountry)) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize() org_txn_country = [%s]\n",csOrgTxnCountry));
	}

	DBObjPtr = CreateObj(DBPtr,"DBBankMapping","i2eBankCodeMapping");
	if ((DBObjPtr)(csInternalBankCode,csPspChannel,csOrgTxnCountry,csOutBankCode)) {
DEBUGLOG(("TxnWebOnUsMSI:: Authorize() channel bank code = [%s]\n",csOutBankCode));
// bcd 
DEBUGLOG(("TxnWebOnUsMSI:: Authorize() put bank_code\n"));
		PutField_CString(hReq,"bank_code",csOutBankCode);
	}
        else {
DEBUGLOG(("TxnWebOnUsDSR:: Authorize() can't find channek bank code [%s] for channel [%s]\n",csInternalBankCode,csPspChannel));
ERRLOG("TxnWebOnUsDSR:: Authorize() can't find channel bank code [%s] for channel [%s]\n",csInternalBankCode,csPspChannel);
        	iRet = INT_BANK_CODE_NOT_FOUND;
      		PutField_Int(hContext,"internal_error",INT_BANK_CODE_NOT_FOUND);
       }

	if (iRet == PD_OK) {

        	csHandler = (char*) malloc (20);
        	sprintf(csHandler,"TxnWebOnUs2%s",csPspChannel);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() Txn Object [%s]\n",csHandler));
        	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
        	FREE_ME(csHandler);
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hReq,hRps);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() iRet = [%d]\n",iRet));	
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize() Format Sucess Resp\n"));
		char	csPspURL[PD_TMP_BUF_LEN + 1];
		char    csPostMethod[PD_URL_METHOD_LEN +1];

		DBObjPtr = CreateObj(DBPtr,"DBMobileBankUrl","GetBankUrl");
		if ((DBObjPtr)(csInternalBankCode,csPspURL,csPostMethod) == PD_OK) {
DEBUGLOG(("TxnWebOnUsMSI::Authorize() PSP_URL = [%s]\n",csPspURL));
DEBUGLOG(("TxnWebOnUsMSI::Authorize() post_method = [%s]\n",csPostMethod));
			PutField_CString(hResponse,"redirect_url",csPspURL);
			PutField_CString(hResponse,"post_method",csPostMethod);
		}
		else {
DEBUGLOG(("TxnWebOnUsMSI::Authorize() PSP_URL not define\n"));
			iRet = PD_ERR;
		}
		if (GetField_CString(hContext,"psp_merchant_id",&csTmp)) {
			PutField_CString(hResponse,"psp_merchant_id",csTmp);
		}
		if (GetField_CString(hContext,"sc",&csTmp)) {
			PutField_CString(hResponse,"sc",csTmp);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() sc = [%s]\n",csTmp));
		}

	}

	FREE_ME(csTmp);
	FREE_ME(csPspId);
	
	hash_destroy(hReq);
	hash_destroy(hRps);
	FREE_ME(hReq);
	FREE_ME(hRps);
DEBUGLOG(("TxnWebOnUsMSI::Authorize() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
int     PostTxn(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int 	iRet = PD_OK;
DEBUGLOG(("TxnWebOnUsMSI::PostTxn()\n"));
/* Get ReserveAmount */
/*
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOReserve\n"));
	BOObjPtr = CreateObj(BOPtr,"BOReserve","GetReserveAmount");
        iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: GetReserve result = [%d]\n",iRet));

	if (iRet == PD_OK) {

DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOTxnFee\n"));
	BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
        iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: GetTxnFee result = [%d]\n",iRet));
	}
*/
	
/* precal psp fee if define */
	if (iRet == PD_OK) {
		/* Update Stat */
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOPsp CalPspCosts\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspCosts");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: BOStat::CalPspFee() result = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		/* Update Stat */
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOStat\n"));
                BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspStat");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: BOStat::UpdateDspStat() result = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		/* Update Stat */
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOStat\n"));
                BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspMerchantStat");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: BOStat::UpdateDspMerchantStat() result = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		/* Update Balance */
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: Call BOBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdateTxnAmount");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnWebOnUsMSI::PostTxn():: updatetxnamount result = [%d]\n",iRet));
	}

DEBUGLOG(("TxnWebOnUsMSI::PostTxn() Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
