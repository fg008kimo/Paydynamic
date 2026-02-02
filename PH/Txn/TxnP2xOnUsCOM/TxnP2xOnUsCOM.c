/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/27              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnP2xOnUsCOM.h"
#include "myrecordset.h"

char cDebug;

void TxnP2xOnUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(BO);
OBJPTR(DB);
int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csPtr;
	char*	csTxnCcy;
	long 	lTmp;
	double	dTmp;

DEBUGLOG(("TxnP2xOnUsCOM: Authroize()\n"));	
/* field checking */

	if ( iRet == PD_OK) {
/* Check Merchant */
 		BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("BOMerchant->GetMerchantDetail = [%d]\n",iRet));

	}

/* check currency code*/
     	if(iRet == PD_OK){
       		if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
               		DBObjPtr = CreateObj(DBPtr,"DBCurrency","FindCurrency");
                        if ((unsigned long)(DBObjPtr)(csTxnCcy) != FOUND) {
                        	iRet = INT_INVALID_CURRENCY_CODE;
                                PutField_Int(hContext,"internal_error",INT_INVALID_CURRENCY_CODE);
DEBUGLOG(("Authorize() Currency code invalid [%s]\n",csTxnCcy));
ERRLOG("TxnP2xOnUsCOM:Authorize() Currency code invalid\n");
                        }
		}
                else{
                	iRet = INT_CURRENCY_CODE_NOT_FOUND;
                        PutField_Int(hContext,"internal_error",INT_CURRENCY_CODE_NOT_FOUND);
DEBUGLOG(("Authorize() Currency code not found\n"));
ERRLOG(("TxnP2xOnUsCOM:Authorize() Currency code not found\n"));
                }
	}

/*check pay amount*/
        if (iRet == PD_OK) {
        	if(GetField_CString(hRequest,"txn_amt",&csPtr)){
               		int iCheck = PD_FALSE;
DEBUGLOG(("Authorize()txn_amt from request[%s]\n",csPtr));
                        iCheck = is_numeric(csPtr);
                        if(iCheck==PD_FALSE){
                       		iRet =  INT_INVALID_PAY_AMOUNT;
                                PutField_Int(hContext,"internal_error",INT_INVALID_PAY_AMOUNT);
DEBUGLOG(("Authorize()txn_amt Invalid[%s]\n",csPtr));
ERRLOG("TxnP2xOnUsCOM::Authorize() txn_amt Invalid\n");
                        }
			else {
				dTmp = myctod((const unsigned char *)csPtr,strlen(csPtr) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
			}
			if (iRet == PD_OK) {
DEBUGLOG(("TxnP2xOnUsCOM::Authorize() check is support decimal\n"));
                   		DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
                        	if ((unsigned long)((DBObjPtr)(csTxnCcy))!=PD_TRUE){
DEBUGLOG(("TxnP2xOnUsCOM::Authorize() [%s] doesn't support decimal\n",csTxnCcy));
                                        lTmp = (long) dTmp;
                                        if (dTmp > lTmp) {
                                                iRet = INT_UNSUPPORTED_PAY_AMOUNT;
                                                PutField_Int(hContext,"internal_error",INT_UNSUPPORTED_PAY_AMOUNT);
ERRLOG("TxnP2xOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTmp);
                                        }
                                }
                        	}
                        	else {
                                	iRet = INT_PAY_AMOUNT_NOT_FOUND;
                                	PutField_Int(hContext,"internal_error",INT_PAY_AMOUNT_NOT_FOUND);
DEBUGLOG(("Authorize() txn_amt not found\n"));
ERRLOG(("TxnP2xOnUsCOM:Authorize() txn_amt not found\n"));
                        	}
			}
                }

DEBUGLOG(("exit = [%d]\n",iRet));

	return iRet;
}
