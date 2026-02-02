/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/22              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsHBR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsHBR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char	*csTmp = NULL;

        char	*csTxnSeq = NULL;
        char	*csMerchantId = NULL;
        char	*csService = NULL;
        char	*csTxnCountry = NULL;
        char	*csTxnCcy = NULL;
        char	*csUpdateUser = NULL;  
        double	dAmt=0.0;

	int	iTmp;
	double	dTmp =0.0;

	//char	cDCInd;

	// Fixed Amount Holdback -- check current bal
	// Release Fixed Amount Holdback --need to update org. sub_status to 121-Release Holdback Amount, 
        // update reserved_release_date


/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
                PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTxnSeq));
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user*/
        if(GetField_CString(hRequest,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
                PutField_CString(hContext,"add_user",csUpdateUser);
                PutField_CString(hContext,"update_user",csUpdateUser);
        }

/* remark */
        if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
                PutField_CString(hContext,"remark",csTmp);
        }


/* merchant_id */
        if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csMerchantId));
                PutField_CString(hContext,"merchant_id",csMerchantId);
        }
	else {
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::merchant_id not found!!\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* service_code */
        if(GetField_CString(hRequest,"service_code",&csService)){
DEBUGLOG(("Authorize::service = [%s]\n",csService));
                PutField_CString(hContext,"service_code",csService);
        }
        else {
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::serivce_code not found!!\n");
                iRet = INT_SERVICE_CODE_MISSING;

                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_country */
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
                PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
        }
        else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_ccy */
        if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
                PutField_CString(hContext,"txn_ccy",csTxnCcy);
		PutField_CString(hContext, "org_txn_ccy", csTxnCcy); // For element

		PutField_CString(hContext, "net_ccy", csTxnCcy);
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_amt */
        if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
		PutField_Double(hContext, "net_amt", dAmt);

		PutField_Double(hContext, "reserve_amt", dAmt); // for element
		PutField_Double(hRequest, "reserve_amt", dAmt); // for header
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsHBR::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext, "sub_status", PD_APPROVED);

	PutField_Char(hContext, "hb_dc_type", PD_IND_CREDIT);
	PutField_CString(hContext, "amount_type",PD_DR); // element debit


        //Handle Balance
        if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessFixedAmtHoldBack");
                iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsHBR::BOBalance::ProcessFixedAmtHoldBack Failed Ret [%d]\n", iRet);
			if (iRet == INT_INSUFFICIENT_FUND) {
				PutField_Int(hContext,"internal_error",iRet);
			}
		} else {

			if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack merchant_open_bal [%lf]\n", dTmp));
				PutField_Double(hContext, "open_bal", dTmp);
			}

			if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack merchant_open_bal_settlement [%lf]\n", dTmp));
				PutField_Double(hContext, "open_bal_settlement", dTmp);
			}
		}
	}


       if(GetField_Int(hContext,"do_logging",&iTmp)){
DEBUGLOG(("Authorize::do_logging [%d]\n", iTmp));
                if(iTmp!=PD_ADD_LOG) {
			/* nothing */
		}
		else {

        		if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
		                        iRet = INT_ERR;
			}
  
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
                		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnDetailLog");
		                if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
               		        	iRet = INT_ERR;
                		}
			}
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOTxnElements:AddReserveAmtElement\n"));

			PutField_CString(hContext, "org_txn_seq", csTxnSeq);
	                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddReserveAmtElement");
			if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize::BOTxnElements:AddReserveAmtElement Failed\n"));
			}
			RemoveField_CString(hContext, "org_txn_seq"); // to prevent log
		}

	}
	
	if(iRet != PD_OK){
		RemoveField_CString(hContext, "sub_status");
		RemoveField_CString(hContext, "approval_date");
		RemoveField_CString(hContext, "approval_timestamp");
		
	}

DEBUGLOG(("TxnMgtByUsHBR Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


