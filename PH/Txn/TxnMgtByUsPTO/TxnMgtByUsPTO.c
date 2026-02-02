/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/23              Virginia Yun
cater manual input fee                             2013/11/12              Virginia Yun
Call TxnMgtByUs2MiniMMM()                          2015/11/20              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPTO.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsPTO(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char        *csTmp = NULL;
        char        *csPspId = NULL;
        //char        *csCode = NULL;
	char        *csOrgTxnCode = NULL;

        char        *csTxnCountry = NULL;
        char        *csTxnCcy = NULL;
        char        *csUpdateUser = NULL;  
        //char        *csDate = NULL;  
        double       dAmt=0.0;
	int	    iTmp;
	//double       dTmp = 0.0;	
	char	    cDCInd;

	hash_t	    *hTxnDetail;
	hTxnDetail = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hTxnDetail, 0);

        hash_t      *hRec;

	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize::Start\n"));
/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hResponse,"org_txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq = [%s]\n", csTmp));
                PutField_CString(hContext, "from_txn_seq", csTmp);
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_code*/
        if(GetField_CString(hRequest,"txn_code",&csOrgTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csTmp));
        }
        else{
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;

                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if(GetField_CString(hRequest,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
                PutField_CString(hContext,"add_user",csUpdateUser);
                PutField_CString(hContext,"update_user",csUpdateUser);
        }

/* remark */
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark= [%s]\n",csTmp));
		PutField_CString(hContext,"remark",csTmp);
	}

/* psp_id */
        if(GetField_CString(hRequest,"psp_id",&csPspId)){
DEBUGLOG(("Authorize::psp_id = [%s]\n",csPspId));
                PutField_CString(hContext,"psp_id",csPspId);
        }
	else {
DEBUGLOG(("Authorize::psp_id not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::psp_id not found!!\n");
		iRet = INT_PSP_RETURN_ERROR;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_country */
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
                PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
        }
        else{
DEBUGLOG(("Authorize::Call DBPspCountry:GetPspCountry\n"));
                DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
                if((unsigned long) ((*DBObjPtr)(csPspId,rRecordSet))==PD_OK){
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                if (GetField_CString(hRec,"country",&csTxnCountry)) {
                                        PutField_CString(hContext,"txn_country",csTxnCountry);
                                        PutField_CString(hRequest,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country by psp_id = [%s]\n",csTxnCountry));
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::txn_country not found!!\n");
                        iRet=INT_COUNTRY_PSP_NOT_AVABILE;
                	PutField_Int(hContext,"internal_error",iRet);
                }
        }

/* txn_ccy */
        if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
                PutField_CString(hContext,"txn_ccy",csTxnCcy);
                PutField_CString(hContext,"org_txn_ccy",csTxnCcy);
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }


/* txn_amt */
        if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
                PutField_Double(hContext, "org_txn_amt", dAmt);
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* approval_date */
/*
        if(!GetField_CString(hRequest,"approval_date",&csDate)){
                if(!GetField_CString(hContext,"PHDATE",&csDate)){
DEBUGLOG(("Authorize::approval_date not found!!\n"));
ERRLOG("TxnMgtByUsPTO::Authorize::approval_date not found!!\n");
                        iRet=INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
                }
                else {
                        PutField_CString(hContext, "approval_date", csDate);
DEBUGLOG(("Authorize::approval_date (phdate) = [%s]\n", csDate)); 
                }
        }
	else {
		PutField_CString(hContext, "approval_date", csDate);
DEBUGLOG(("Authorize::approval_date = [%s]\n", csDate)); 
	}
*/
/* report_date */
        if(!GetField_CString(hRequest,"report_date",&csTmp)){
DEBUGLOG(("Authorize::report_date not found!!\n"));
                if(GetField_CString(hContext,"PHDATE",&csTmp)){
                        PutField_CString(hContext, "report_date", csTmp);
DEBUGLOG(("Authorize::report_date (PH date) = [%s]\n", csTmp));
                }
        }
        else {
                PutField_CString(hContext, "report_date", csTmp);
DEBUGLOG(("Authorize::report_date = [%s]\n", csTmp));
        }

/* service_fee */
        if(GetField_Double(hContext,"service_fee",&dAmt)){
DEBUGLOG(("Authorize::service_fee = [%f]\n",dAmt));
                PutField_Double(hContext, "src_txn_fee", dAmt);
		PutField_CString(hContext, "src_txn_fee_ccy", csTxnCcy);
        } else {
DEBUGLOG(("Authorize::No manual Input Fee\n")); 
	}


	PutField_CString(hRequest, "service_code", PD_DEFAULT_SERVICE);
	PutField_Char(hContext, "party_type", PD_TYPE_PSP);

	PutField_Int(hContext, "balance_transfer", PD_TRUE);
	PutField_Char(hContext, "dc_ind", PD_ADJ_TYPE_DEBIT);

        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext, "sub_status", PD_APPROVED);

	PutField_Char(hContext, "ex_party", PD_INT_EX);
	PutField_Double(hContext, "ex_rate", 1);

        //************* Get Fee *******************// /* no need to apply fee on PSP */
/*        
        if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));

                PutField_CString(hContext,"txn_code",csCode);

                BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                if ((unsigned long)((*BOObjPtr)(hContext, hRequest)) != PD_OK)  {
DEBUGLOG(("Authorize::BOFee:GetTxnFee Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsPTO::BOFee::GetTxnFee Failed Ret [%d]\n", iRet);
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
*/
 
	//Update Balance
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOAdjustment","ProcessPartyBalance");
		iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsPTO::BOADjustment::ProcesspartyBalance Failed [%d]\n", iRet);
		} else {
                        if (GetField_Char(hContext,"dc_ind",&cDCInd)) {
DEBUGLOG(("Authorize::dc_ind = [%c]\n", cDCInd));
                                if (cDCInd == PD_ADJ_TYPE_CREDIT) {
                                        PutField_CString(hContext, "amount_type", PD_CR);
                                }
                                else if (cDCInd == PD_ADJ_TYPE_DEBIT) {
                                        PutField_CString(hContext, "amount_type", PD_DR);
                                }
                        }
                        else {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed to get dc_ind\n"));
ERRLOG("TxnMgtByUsPTO::BOADjustment::ProcesspartyBalance Failed to get dc_ind\n");
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
		
			PutField_CString(hContext, "net_ccy", csTxnCcy);

        		if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
				if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
					iRet = INT_ERR;
        		}
   
        		if(iRet==PD_OK){
				// To prevent update current bal, total_float and total_hold
				
				if (GetField_CString(hContext, "txn_seq", &csTmp)) {
					PutField_CString(hTxnDetail, "txn_seq", csTmp);
				}
				if (GetField_CString(hContext, "txn_country", &csTmp)) {
					PutField_CString(hTxnDetail, "txn_country", csTmp);
				}
				if (GetField_CString(hContext, "update_user", &csTmp)) {
					PutField_CString(hTxnDetail, "update_user", csTmp);
				}


DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
                		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
	                	if((unsigned long) ((*DBObjPtr)(hTxnDetail))!=PD_OK)
       		                 	iRet = INT_ERR;
       	 		}
		}
	}


        // for handling TXNPSPDETAIL??
        if(iRet==PD_OK){
                if (GetField_CString(hContext, "PHDATE", &csTmp)) {
DEBUGLOG(("Authorize::PHDATE = [%s]\n",csTmp));
                    PutField_CString(hContext, "txn_date", csTmp);
                }

DEBUGLOG(("Authorize::Call DBTxnPspDetail:Add\n"));
		PutField_CString(hContext, "desc", "Psp Balance Transfer to Other System");

                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK) {
                        iRet = INT_ERR;
                } 
        }

	if (iRet==PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK) {
			iRet = INT_ERR;
		}
	}
         
        if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnAmtElement\n"));
                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
                        iRet = INT_ERR;
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




	FREE_ME(hTxnDetail);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	//check support mini-mmm or not
	if (iRet == PD_OK) {
		PutField_CString(hContext, "mini_txn_type", PD_MI_TXN_TYPE_BALTRF_OUT);

DEBUGLOG(("Authorize:: Call TxnMgtByUs2MiniMMM:Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnMgtByUs2MiniMMM", "Authorize");
		iRet = (unsigned long)((*TxnObjPtr)(hContext, hRequest, hResponse));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: TxnMgtByUs2MiniMMM:Authorize() Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsPTO:Authorize:: TxnMgtByUs2MiniMMM:Authorize() Failed Ret [%d]\n", iRet);
		}
	}

DEBUGLOG(("TxnMgtByUsPTO Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
