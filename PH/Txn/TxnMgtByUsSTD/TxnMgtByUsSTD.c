/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/18              LokMan Chow
Call BOSettlement to handle			   2011/11/11		   LokMan Chow
split two mode: deliver and update		   2012/11/23		   LokMan Chow
Add Receive Net Ccy and Amt                        2014/02/04              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsSTD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	ACTION_DELIVER 'D'

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsSTD(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	cMode;
	char	*csTmp;
	double	dTmp;
	char	*csBankDate;

	char	*csReceiveCcy = NULL;
	char	*csReceiveAmt = NULL;

	hash_t  *hTxn;
	hTxn= (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);


DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hRequest,"org_txn_seq",&csTmp)){
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
		PutField_CString(hContext,"txn_seq",csTmp);
		PutField_CString(hTxn,"txn_seq",csTmp);
	}
	else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMgtByUsSTD:Authorize::txnid not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

///update mode : 'U' - update date,  'D' - deliver
	if(GetField_CString(hRequest,"mode",&csTmp)){
		cMode = csTmp[0];
DEBUGLOG(("Authorize::update_mode = [%c]\n",cMode));
	}
	else{
		cMode = ACTION_DELIVER;
DEBUGLOG(("Authorize::update_mode(default) = [%c]\n",cMode));
	}


	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
	}



	if(iRet==PD_OK && cMode==ACTION_DELIVER){

		if (GetField_CString(hRequest, "receive_ccy", &csReceiveCcy)) {
DEBUGLOG(("Authorize::receive_ccy = [%s]\n",csReceiveCcy));
			PutField_CString(hContext, "receive_ccy", csReceiveCcy);
		}
		if (GetField_CString(hRequest, "receive_amt", &csReceiveAmt)) {
DEBUGLOG(("Authorize::receive_amt = [%s]\n",csReceiveAmt));
		}
	
		if (((csReceiveCcy != NULL) && (csReceiveAmt == NULL)) || ((csReceiveCcy == NULL) && (csReceiveAmt != NULL))) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: receive_ccy and receive_amt should exists in a pair!!\n"));
ERRLOG("TxnMgtByUsSTD:Authorize::receive_ccy and receive_amt should exists in a pair!!\n");
		}

		if ((iRet == PD_OK) && (csReceiveAmt != NULL)) {
			int iCheck = PD_FALSE;
			char *p = NULL;

			p = (char*)strchr(csReceiveAmt, '.');
			if (p == NULL) {
				iCheck = is_numeric(csReceiveAmt);
				if (iCheck != PD_FALSE) {
					if (sscanf(csReceiveAmt, "%lf", &dTmp) == 1) {
						PutField_Double(hContext, "receive_amt", dTmp);
DEBUGLOG(("Authorize::receive_amt (double) = [%lf]\n", dTmp));
					}
				}
			} else {
				if (sscanf(csReceiveAmt, "%lf", &dTmp) == 1) {
					PutField_Double(hContext, "receive_amt", dTmp);
DEBUGLOG(("Authorize::receive_amt (double) = [%lf]\n", dTmp));
					iCheck = PD_TRUE;
				}
			}

			if (iCheck == PD_FALSE) {
	                        iRet =  INT_INVALID_PAY_AMOUNT;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() receive_amt Invalid[%s]\n",csReceiveAmt));
ERRLOG("TxnMgtByUsSTD::Authorize() receive_amt Invalid\n");

			}

		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOSettlement:ProcessSettlementTxn\n"));
	                BOObjPtr = CreateObj(BOPtr,"BOSettlement","ProcessSettlementTxn");
			iRet = (unsigned long) (*BOObjPtr)(hContext,hRequest,hResponse);
		}
        }

	if(iRet==PD_OK && cMode==PD_ACTION_UPDATE){
		//update bank statement date
		if(GetField_CString(hRequest,"bank_date",&csBankDate)){
DEBUGLOG(("Authorize::bank_date = [%s]\n",csBankDate));

DEBUGLOG(("Authorize::Call DBMerchantSettlementDetail:Update\n"));
			PutField_CString(hTxn,"bank_statement_date",csBankDate);

			DBObjPtr = CreateObj(DBPtr,"DBMerchantSettlementDetail","Update");
			if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK)
				iRet = INT_ERR;
		}
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsSTD Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
