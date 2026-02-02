/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/23              Virginia Yun
Add handling for payout pool			   2016/01/06		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMAD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnOmtByUsMAD(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char        *csTmp = NULL;
        char        *csMerchantId = NULL;
        char        *csCode = NULL;
        char        *csOrgTxnCode = NULL;

        char        *csService = NULL;
        char        *csTxnCountry = NULL;
        char        *csTxnCcy = NULL;
        char        *csUpdateUser = NULL;  
        double       dAmt=0.0;

	int	    iTmp;
	double      dTmp =0.0;

	char	    cDCInd;
	char	    cBalType = PD_MERCH_AVA_SETT_POOL;



/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTmp)){
                PutField_CString(hResponse,"org_txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
		PutField_CString(hContext, "from_txn_seq", csTmp);
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_code*/
        if(GetField_CString(hRequest,"txn_code",&csOrgTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csOrgTxnCode));
        }
        else{
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;

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
ERRLOG("TxnOmtByUsMAD::Authorize::merchant_id not found!!\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* code */
        if(GetField_CString(hRequest,"code",&csCode)){
DEBUGLOG(("Authorize::code = [%s]\n",csCode));
                PutField_CString(hContext,"code",csCode);

DEBUGLOG(("Authorize::Assign new Txn code = [%s]\n",csCode));
                PutField_CString(hContext, "new_txn_code", csCode);
        } 
	else {
DEBUGLOG(("Authorize::code not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::code not found!!\n");
                        iRet=INT_CODE_ERROR;
                	PutField_Int(hContext,"internal_error",iRet);
	}

/* service_code */
        if(GetField_CString(hRequest,"service_code",&csService)){
DEBUGLOG(("Authorize::service = [%s]\n",csService));
                PutField_CString(hContext,"service_code",csService);
        }
        else {
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::serivce_code not found!!\n");
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
ERRLOG("TxnOmtByUsMAD::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_ccy */
        if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
                PutField_CString(hContext,"txn_ccy",csTxnCcy);
                PutField_CString(hContext,"org_txn_ccy",csTxnCcy);

		PutField_CString(hContext, "net_ccy", csTxnCcy);
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_amt */
        if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
		PutField_Double(hContext, "org_txn_amt", dAmt);

		PutField_Double(hContext, "net_amt", dAmt);
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsMAD::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }


	PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);

        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext, "sub_status", PD_APPROVED);


	//************* Get Fee *******************
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));

                PutField_CString(hContext,"txn_code",csCode);

                BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                if ((unsigned long)((*BOObjPtr)(hContext, hRequest)) != PD_OK)  {
DEBUGLOG(("Authorize::BOFee:GetTxnFee Failed Ret [%d]\n", iRet));
ERRLOG("TxnOmtByUsMAD::BOFee::GetTxnFee Failed Ret [%d]\n", iRet);
			iRet = INT_ERR;
                } 	
		else {
			if (GetField_Double(hContext, "src_txn_fee", &dTmp)) {
DEBUGLOG(("Authorize::BOFee:GetTxnFee src_txn_fee [%lf]\n", dTmp));
			}
			else {
				dTmp = 0.0;
				PutField_Double(hContext, "src_txn_fee", dTmp);
DEBUGLOG(("Authorize::BOFee:GetTxnFee src_txn_fee (by default) [%lf]\n", dTmp));
			}

			if (GetField_CString(hContext, "src_txn_fee_ccy", &csTmp)) {
DEBUGLOG(("Authorize::BOFee:GetTxnFee src_txn_fee_ccy [%s]\n", csTmp));
			}
			else {
				PutField_CString(hContext, "src_txn_fee_ccy", csTxnCcy);
			}
		}

                PutField_CString(hContext,"txn_code",csOrgTxnCode);
	}

 
	//Update Balance
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOOLAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLAdjustment","ProcessPartyBalance");
		iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOOLAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnOmtByUsMAD::BOOLAdjustment::ProcesspartyBalance Failed Ret [%d]\n", iRet);
		} else {	
			if (GetField_Char(hContext,"bal_type",&cBalType)) {
DEBUGLOG(("Authorize::bal_type = [%c]\n", cBalType));
			}
			if (GetField_Char(hContext,"dc_ind",&cDCInd)) {
DEBUGLOG(("Authorize::dc_ind = [%c]\n", cDCInd));
				if (cDCInd == PD_ADJ_TYPE_CREDIT) {
					PutField_CString(hContext, "amount_type", PD_CR);
				}
				else if (cDCInd == PD_ADJ_TYPE_DEBIT) {
					PutField_CString(hContext, "amount_type", PD_DR);
				}

				if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize::BOOLAdjustment:ProcessPartyBalance merchant_open_bal [%lf]\n", dTmp));
					PutField_Double(hContext, "open_bal", dTmp);
				}

				if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize::BOOLAdjustment:ProcessPartyBalance merchant_open_bal_settlement [%lf]\n", dTmp));
					PutField_Double(hContext, "open_bal_settlement", dTmp);
				}
			}
			else {
DEBUGLOG(("Authorize::BOOLAdjustment:ProcessPartyBalance Failed to get dc_ind\n"));
ERRLOG("TxnOmtByUsMAD::BOOLAdjustment::ProcesspartyBalance Failed to get dc_ind\n");
				iRet = PD_ERR;
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
DEBUGLOG(("Authorize::Call DBOLTransaction:AddDetail\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","AddDetail");
                		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
		                        iRet = INT_ERR;
			}
  
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnDetailLog\n"));
                		ChannelObjPtr = CreateObj(ChannelPtr, "OMTChannel","UpdateTxnDetailLog");
		                if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
               		        	iRet = INT_ERR;
                		}
			}
		}

	}
	
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOOLTxnElements:AddTxnAmtElement\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnAmtElement");
		if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
		}
	}


        if (iRet == PD_OK) {
		PutField_CString(hContext, "amount_type", PD_DR);

DEBUGLOG(("Authorize::Call BOOLTxnElements:AddTxnFeeElements\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddTxnFeeElements");
                if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
                        iRet = INT_ERR;
                }

        }

	if(iRet!= PD_OK){
		RemoveField_CString(hContext, "sub_status");
		RemoveField_CString(hContext, "approval_date");
		RemoveField_CString(hContext, "approval_timestamp");
		
	}




DEBUGLOG(("TxnOmtByUsMAD Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
