/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/13              LokMan Chow
Check transaction amt, payout_group                2017//06/02             Virginia Yun

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOplOnUsOPI.h"
#include "myrecordset.h"
#include <math.h>

char cDebug;
#define PD_MY_TOEKN	' '

void TxnOplOnUsOPI(char    cdebug)
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
	char	*csPtr = NULL;
	char	*csTxnSeq = NULL;
	char	*csPoGrp = NULL;
	long	lTmp;

	char	*csTxnCcy = NULL;
	char	*csTxnCountry = NULL;
	double	dTxnAmt = 0.0;
	hash_t  *hTxn;

	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("TxnOplOnUsOPI: Authroize()\n"));	
	
	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
		PutField_CString(hTxn, "txn_seq", csTxnSeq);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
		PutField_CString(hTxn, "request_currency", csTxnCcy);
	} 

	if(GetField_CString(hRequest,"dest_txn_ccy",&csPtr)){
		PutField_CString(hTxn, "payout_currency", csPtr);
	}

        if (GetField_CString(hRequest,"txn_country",&csTxnCountry)) {
DEBUGLOG(("TxnOplOnUsOPI:Authorize:: txn_country = [%s]\n",csTxnCountry));
        }


	if(GetField_Double(hContext,"txn_amt",&dTxnAmt)){
		PutField_Double(hTxn, "request_amount", dTxnAmt);
	}else if(GetField_CString(hRequest,"txn_amt",&csPtr)){

DEBUGLOG(("TxnOplOnUsOPI:Authorize() txn_amt from request[%s]\n",csPtr));

		int iCheck = PD_FALSE;

		iCheck = is_numeric(csPtr);
		if(iCheck==PD_FALSE){

			iRet =  INT_INVALID_PAY_AMOUNT;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("TxnOplOnUsOPI:Authorize() txn_amt Invalid[%s]\n",csPtr));
ERRLOG("TxnOplOnUsOPI:Authorize() txn_amt Invalid\n");
		}
		else {
			if(strlen(csPtr)>(PD_DIGIT_LEN+PD_DECIMAL_LEN)){
				iRet =  INT_INVALID_PAY_AMOUNT;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("TxnOplOnUsOPI:Authorize() txn_amt length too long[%s]\n",csPtr));
ERRLOG("TxnOplOnUsOPI:Authorize() txn_amt length too long\n");
			}
			else{
				dTxnAmt = myctod((const unsigned char *)csPtr,strlen(csPtr) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
				PutField_Double(hTxn, "request_amount", dTxnAmt);

				PutField_Double(hContext,"txn_amt",dTxnAmt);

DEBUGLOG(("TxnOplOnUsOPI:Authorize() txn_amt = [%f]\n",dTxnAmt));

				if (dTxnAmt <= 0) {
					iRet = INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("TxnOplOnUsOPI:Authorize() txn_amt cannot be zero\n"));
ERRLOG("TxnOplOnUsOPI:Authorize() txn_amt cannot be zero\n");
				}
			}
		}

/* if TWD */
		if (iRet==PD_OK && csTxnCcy != NULL) {
DEBUGLOG(("TxnOplOnUsOPI:Authorize() check is support decimal\n"));
			DBObjPtr = CreateObj(DBPtr,"DBCurrency","IsSupportDecimal");
			if ((unsigned long)((DBObjPtr)(csTxnCcy))!=PD_TRUE){
DEBUGLOG(("TxnOplOnUsOPI:Authorize() [%s] doesn't support decimal\n",csTxnCcy));
				lTmp = (long) dTxnAmt;
				if (dTxnAmt > lTmp) {
					iRet = INT_UNSUPPORTED_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOplOnUsOPI:Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
				}
			}
		} 

/* if TW */
		if(iRet==PD_OK && csTxnCountry!= NULL) {
			if(!strcmp(csTxnCountry,PD_TAIWAN)){
DEBUGLOG(("Authorize() [%s] doesn't support decimal\n",csTxnCountry));
				lTmp = (long) dTxnAmt;
				if (dTxnAmt > lTmp) {
					iRet = INT_UNSUPPORTED_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOplOnUsCOM::Authorize() unsupported transaction amount [%f]\n",dTxnAmt);
				}
			}
		}
		/*
		dTxnAmt = myctod((const unsigned char *)csPtr,strlen(csPtr) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
		PutField_Double(hTxn, "request_amount", dTxnAmt);
		*/
	}


	if(GetField_CString(hRequest,"payout_group",&csPtr)){
		csPoGrp = TrimAllChar((const unsigned char*)csPtr,strlen(csPtr),PD_MY_TOEKN);
		PutField_CString(hTxn, "merchant_payout_grp", csPoGrp);
	}

	PutField_CString(hTxn, "add_user", PD_UPDATE_USER);


DEBUGLOG(("TxnOplOnUsOPI: Add to OLPayoutRequest [%s]\n",csTxnSeq));	
	DBObjPtr = CreateObj(DBPtr,"DBOLPayoutRequest","Add");
	iRet = (unsigned long)(*DBObjPtr)(hTxn);
	if(iRet!=PD_OK){
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("TxnOplOnUsOPI: Add to OLPayoutRequest Failed\n"));	
	}

	FREE_ME(hTxn);

DEBUGLOG(("TxnOplOnUsOPI::Authroize exit = [%d]\n",iRet));
	return iRet;
}



int Update(hash_t* hContext,
           const hash_t* hRequest,
           hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csTxnSeq = NULL;
	double	dTmp = 0.0;
	int	iTmpErr = 0;
	hash_t  *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("TxnOplOnUsOPI: Update()\n"));	

	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
		PutField_CString(hTxn, "txn_seq", csTxnSeq);
	}

	
	if(GetField_CString(hContext,"payout_group",&csPtr)){
		DBObjPtr = CreateObj(DBPtr,"DBOLDefPayoutGroup","IsDefaultPayoutGroup");
		if((unsigned long)(*DBObjPtr)(csPtr)){
			PutField_CString(hTxn, "psp_payout_grp", csPtr);
		}
	}

	if(GetField_Double(hContext,"txn_amt",&dTmp)){
		PutField_Double(hTxn, "request_amount", dTmp);
	}

	GetField_Int(hContext,"internal_error",&iTmpErr);
	if(iTmpErr!=0){
		PutField_Int(hTxn, "status", PAYOUT_MASTER_TRANSACTION_REJECTED);
	}
	else{
		PutField_Int(hTxn, "status", PAYOUT_MASTER_TRANSACTION_CONFIRMED);
	}
	PutField_CString(hTxn, "update_user", PD_UPDATE_USER);


DEBUGLOG(("TxnOplOnUsOPI: Update OLPayoutRequest [%s]\n",csTxnSeq));	
	DBObjPtr = CreateObj(DBPtr,"DBOLPayoutRequest","Update");
	iRet = (unsigned long)(*DBObjPtr)(hTxn);
	if(iRet!=PD_OK){
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("TxnOplOnUsOPI: Update OLPayoutRequest Failed\n"));	
	}

	FREE_ME(hTxn);

DEBUGLOG(("TxnOplOnUsOPI::Update exit = [%d]\n",iRet));
	return iRet;
}
