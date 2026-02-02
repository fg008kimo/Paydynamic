/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/10/15             Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsWTD.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(Txn);

void TxnWebOnUsWTD(char    cdebug)
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
	char	csValue[PD_VALUE_LEN +1];
	char*	csPspId = NULL;
	double	dTmp;
	hash_t	*hReq,*hRps;

	hReq = (hash_t*) malloc (sizeof(hash_t));
	hRps = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hReq,0);
	hash_init(hRps,0);

	//double	dTmp;

DEBUGLOG(("TxnWebOnUsWTD: Authroize()\n"));

/* txn_code */
	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: txn_code = [%s]\n",csTmp));
		PutField_CString(hReq,"txn_code",csTmp);
	}

/* txn_seq */
	if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: txn_seq = [%s]\n",csTmp));
		PutField_CString(hReq,"order_num",csTmp);
	}
/* psp Url */
	if (GetField_CString(hContext,"psp_url",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: psp_url = [%s]\n",csTmp));
		PutField_CString(hReq,"psp_url",csTmp);
	}
/* request_function */
	if (GetField_CString(hContext,"request_function",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: request_function = [%s]\n",csTmp));
		PutField_CString(hReq,"request_function",csTmp);
	}

/* action */
	if (GetField_CString(hContext,"action",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: action = [%s]\n",csTmp));
		PutField_CString(hReq,"action",csTmp);
	}

/* access_key */
	if (GetField_CString(hContext,"psp_key",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: access_key = [%s]\n",csTmp));
		PutField_CString(hReq,"access_key",csTmp);
	}

/* txn_amt */

	if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: txn_amt = [%f]\n",dTmp));
		PutField_Double(hReq,"txn_amt",dTmp);
	}


/* bank_code */
	if (GetField_CString(hRequest,"bank_code",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: bank_code = [%s]\n",csTmp));
		PutField_CString(hReq,"bank_code",csTmp);
	}

/* branch_name */
	if (GetField_CString(hRequest,"branch_name",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: branch_name = [%s]\n",csTmp));
		PutField_CString(hReq,"branch_name",csTmp);
	}
/* account_id */
	if (GetField_CString(hRequest,"account_id",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: account_id = [%s]\n",csTmp));
		PutField_CString(hReq,"account_id",csTmp);
	}
/* account_name */
	if (GetField_CString(hRequest,"account_name",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: account_name = [%s]\n",csTmp));
		PutField_CString(hReq,"account_name",csTmp);
	}
/* identity_id */
	if (GetField_CString(hRequest,"identity_id",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTD: identity_id = [%s]\n",csTmp));
		PutField_CString(hReq,"identity_id",csTmp);
	}



/* psp id */
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("TxnWebOnUsWTD: psp_id = [%s]\n",csPspId));
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsWTD can't find PSP ID\n");
		iRet = INT_ERR;
	}
	if (iRet == PD_OK) {
        	csHandler = (char*) malloc (20);
        	sprintf(csHandler,"TxnWebOnUs2%s",csPspId);
DEBUGLOG(("TxnWebOnUsWTD Txn Object [%s]\n",csHandler));
        	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
        	FREE_ME(csHandler);
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hReq,hRps);
DEBUGLOG(("iRet = [%d]\n",iRet));	
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsWTD Format Sucess Resp\n"));
		if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
			PutField_CString(hResponse,"local_tm_date",csTmp);
DEBUGLOG(("TxnWebOnUsWTD Format local_tm_date = [%s]\n",csTmp));
		}
		if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
			PutField_CString(hResponse,"local_tm_time",csTmp);
DEBUGLOG(("TxnWebOnUsWTD Format local_tm_time = [%s]\n",csTmp));
		}
/* hardcode */
		PutField_CString(hResponse,"service_fee","1");
		PutField_CString(hResponse,"service_currency","HKD");

		if (GetField_Double(hContext,"net_amt",&dTmp)) {
			dtoc(dTmp,PD_DIGIT_LEN,0,(unsigned char *)csTmp);
			trim_leading_zero(csValue,csTmp);
			PutField_CString(hResponse,"net_amount",csValue);
			PutField_Double(hResponse,"net_amt",dTmp);
DEBUGLOG(("TxnWebOnUsWTD Format net_amt = [%s]\n",csValue));
		}

		if (GetField_CString(hContext,"based_ccy",&csTmp)) {
			PutField_CString(hResponse,"net_ccy",csTmp);
DEBUGLOG(("TxnWebOnUsWTD Format net_ccy = [%s]\n",csTmp));
		}
		if (GetField_CString(hContext,"redirect_url",&csTmp)) {
			PutField_CString(hResponse,"redirect_url",csTmp);
DEBUGLOG(("TxnWebOnUsWTD Format redirect_url = [%s]\n",csTmp));
		}
	}

	FREE_ME(csTmp);
	FREE_ME(csPspId);
	
	hash_destroy(hReq);
	hash_destroy(hRps);
	FREE_ME(hReq);
	FREE_ME(hRps);
DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
