/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/23              Virginia Yun
Modify						   2016/09/26		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVTO.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

int GetTxnInfo(const unsigned char *csTxnSeq, hash_t * hTxn);

void TxnMgtByUsVTO(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iReturnMerchFee = PD_FALSE;

        double  dTmp = 0.0;

	char	cDCInd;

	char	*csSysParaVal = (char*) malloc (128);
        char    *csOrgTxnSeq;
        char    *csMerchantId = NULL;
        char    *csServiceCode = NULL;
        char    *csRemark = NULL;
        char    *csDate = NULL;
        char    *csUser = NULL;
        char    *csTmp = NULL;

        hash_t  *hOrgTxn;
        hOrgTxn = (hash_t*) malloc(sizeof(hash_t));
        hash_init(hOrgTxn, 0);

        hash_t  *hTxn;
        hTxn = (hash_t *)malloc(sizeof(hash_t));
        hash_init(hTxn, 0);

/* org_txn_seq */
        if (GetField_CString(hRequest, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("Authorize::org_txn_seq = [%s]\n",csOrgTxnSeq));
                PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
                PutField_CString(hContext, "org_txn_seq", csOrgTxnSeq);
        }

/* add_user */
        if (GetField_CString(hRequest,"add_user",&csUser)) {
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
                PutField_CString(hContext,"update_user",csUser);
        }

/* merchant_id */
        if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
                PutField_CString(hContext,"merchant_id",csMerchantId);
        }
        else {
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsVTO::Authorize::merchant_id not found!!\n");
                iRet=INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* service_code */
        if (GetField_CString(hRequest,"service_code",&csServiceCode)) {
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
                PutField_CString(hContext,"service_code",csServiceCode);
        }
        else {
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsVTO::Authorize::service_code not found!!\n");
                iRet=INT_SERVICE_CODE_MISSING;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* remark */
        if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("Authorize::remark = [%s]\n",csRemark));
        } else {
DEBUGLOG(("Authorize::remark not found!!\n"));
ERRLOG("TxnMgtByUsVTO::Authorize::remark not found!!\n");
                iRet = INT_REMARK_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* return_mfee */
        if (GetField_Int(hRequest,"return_mfee",&iReturnMerchFee)) {
DEBUGLOG(("Authorize::return_mfee = [%d]\n",iReturnMerchFee));
                PutField_Int(hContext,"return_mfee",iReturnMerchFee);
        }

/* PHDATE */
        if (GetField_CString(hContext, "PHDATE", &csDate)) {
DEBUGLOG(("Authorize::PHDATE = [%s]\n",csDate));
        }

	// Get Txn Info
	if (iRet == PD_OK) {

                iRet = GetTxnInfo((const unsigned char *)csOrgTxnSeq, hTxn);
                if (iRet == PD_OK) {

/* txn_amt */
                        if (GetField_Double(hTxn, "txn_amt", &dTmp)) {
DEBUGLOG(("Authorize::txn_amt = [%lf]\n",dTmp));
                                PutField_Double(hContext, "txn_amt", dTmp);
                        }

/* src_txn_fee */
                        if (GetField_Double(hTxn, "src_txn_fee", &dTmp)) {
DEBUGLOG(("Authorize::fee = [%lf]\n",dTmp));
			
				if (iReturnMerchFee == PD_TRUE) {
                                	PutField_Double(hContext, "src_txn_fee", dTmp);
				}
                        }

/* net_ccy */
                        if (GetField_CString(hTxn, "net_ccy", &csTmp)) {
DEBUGLOG(("Authorize::txn_ccy (net_ccy) = [%s]\n",csTmp));
                                PutField_CString(hContext, "txn_ccy", csTmp);
                                PutField_CString(hContext, "net_ccy", csTmp);
                        } else {

/* txn_ccy */
                                if (GetField_CString(hTxn, "txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::txn_ccy = [%s]\n",csTmp));
                                        PutField_CString(hContext, "txn_ccy", csTmp);
                                }
                        }

/* txn_country */
                        if (GetField_CString(hTxn, "txn_country", &csTmp)) {
DEBUGLOG(("Authorize::txn_country = [%s]\n",csTmp));
                                PutField_CString(hContext, "txn_country", csTmp);
                        }

/* header_txn_amt */
                        if (GetField_Double(hTxn, "header_txn_amt", &dTmp)) {
DEBUGLOG(("Authorize::txn_amt = [%lf]\n",dTmp));
                                PutField_Double(hContext, "header_txn_amt", dTmp);
                        }

/* detail_txn_ccy */
                        if (GetField_CString(hTxn, "detail_txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::txn_ccy = [%s]\n",csTmp));
                                PutField_CString(hContext, "detail_txn_ccy", csTmp);
                        }

                } else {
                        PutField_Int(hContext, "internal_error", iRet);
                }
        }

	// Set Txn Info
        if (iRet == PD_OK) {

                // party_type
                PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);

		// balance_transfer 
		PutField_Int(hContext, "balance_transfer", PD_TRUE);

                // void_flag
                PutField_Int(hContext, "void_flag", PD_TRUE);

		// dc_ind
		PutField_Char(hContext, "dc_ind", PD_IND_DEBIT);
        }			

	// Update Merchant Balance
	if (iRet == PD_OK){

		// Update Current Balance of Settlement
DEBUGLOG(("Authorize::Call BOAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOAdjustment","ProcessPartyBalance");
                iRet = (unsigned long)((*BOObjPtr)(hContext));
                if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsVTO::BOADjustment::ProcesspartyBalance Failed Ret [%d]\n", iRet);
                } else {

/* dc_ind */
                       	if (GetField_Char(hContext,"dc_ind",&cDCInd)) {
DEBUGLOG(("Authorize::dc_ind = [%c]\n", cDCInd));

                                if (cDCInd == PD_ADJ_TYPE_CREDIT) {
                                        PutField_CString(hContext, "amount_type", PD_CR);
                                } else if (cDCInd == PD_ADJ_TYPE_DEBIT) {
                                        PutField_CString(hContext, "amount_type", PD_DR);
                                }

/* merchant_open_bal */
                                if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance merchant_open_bal [%lf]\n", dTmp));
                                        PutField_Double(hContext, "open_bal", dTmp);
                                }

/* merchant_open_bal_settlement */
                                if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance merchant_open_bal_settlement [%lf]\n", dTmp));
                                        PutField_Double(hContext, "open_bal_settlement", dTmp);
                                }

                        } else {
DEBUGLOG(("Authorize::BOAdjustment:ProcessPartyBalance Failed to get dc_ind\n"));
ERRLOG("TxnMgtByUsVTO::BOAdjustment::ProcesspartyBalance Failed to get dc_ind\n");
                                iRet = INT_ERR;
                        }
                }
	}

	// Update Txn Header (Org Txn Seq)
        if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Update Org Transaction\n"));

                // status
                PutField_Char(hOrgTxn,"status",PD_REVERSED);

                // sub_status
                //PutField_CString(hOrgTxn,"sub_status",PD_VOID);       // Approved_Refund
                PutField_CString(hOrgTxn,"sub_status",PD_UNDO); // Voided

DEBUGLOG(("Authorize::Call DBTransaction:Update\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                if((unsigned long) ((*DBObjPtr)(hOrgTxn))!=PD_OK) {
                        iRet = INT_ERR;
                }	
	}

	// Update Txn Header
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Update Void Transaction\n"));

/* header_txn_amt */
              	if (GetField_Double(hContext, "header_txn_amt", &dTmp)) {
                   	PutField_Double(hContext, "txn_amt", dTmp);
              	}

DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnLog\n"));
              	ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnLog");
             	if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
                     	iRet = INT_ERR;
         	}
     	}

	// Add Txn Detail
        if (iRet == PD_OK) {

/* detail_txn_ccy */
                if (GetField_CString(hContext, "detail_txn_ccy", &csTmp)) {
                        PutField_CString(hContext, "txn_ccy", csTmp);
                }	

		// remark
                PutField_CString(hContext, "remark", csRemark);

DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
                }
        }

	// Update Txn Detail
        if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
                ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnDetailLog");
                if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
                        iRet = INT_ERR;
                }
        }

	// Remove Fields
        if (iRet == PD_OK) {

                // remark
                RemoveField_CString(hContext,"remark");
        }

	// Update Txn Header
        if (iRet == PD_OK) {

                // approval_date
                PutField_CString(hContext, "approval_date", csDate);

                // sub_status
                PutField_CString(hContext, "sub_status", PD_APPROVED);
        }

	// Update Response
        if (iRet == PD_OK) {

/* txn_seq */
                if(GetField_CString(hContext,"txn_seq",&csTmp)){
                        PutField_CString(hResponse,"org_txn_seq",csTmp);
                }
        }

	FREE_ME(csSysParaVal);

	FREE_ME(hOrgTxn);
        FREE_ME(hTxn);

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}

int 	GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn)
{
	int     iRet = PD_OK;

	double  dTmp = 0.0;
        double  dTxnAmt = 0.0;
        double  dTxnFee = 0.0;

	char    cPartyType;

	char    *csTmp = NULL;

        hash_t  *hRec;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	// Set Party Type
	cPartyType = PD_TYPE_MERCHANT;

	// Get Txn Header
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnHeader\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/* txn_amt */
                                if (GetField_Double(hRec,"txn_amt",&dTmp)) {
                                        PutField_Double(hTxn,"header_txn_amt",dTmp);
DEBUGLOG(("GetTxnHeader::txn_amt = [%lf]\n",dTmp));
                                }

/* net_amt */
                                if (GetField_Double(hRec,"net_amt",&dTmp)) {
                                        PutField_Double(hTxn,"net_amt",dTmp);
DEBUGLOG(("GetTxnHeader::net_amt = [%lf]\n",dTmp));
                                }

/* net_ccy */
                                if (GetField_CString(hRec,"net_ccy",&csTmp)) {
                                        PutField_CString(hTxn,"net_ccy",csTmp);
DEBUGLOG(("GetTxnHeader::net_ccy = [%s]\n",csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVTO:Authorize::GetTxnHeader::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                }

                RecordSet_Destroy(rRecordSet);
        }

	// Get Txn Detail
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetTxnDetail::found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/* txn_ccy */
                                if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
                                        PutField_CString(hTxn,"detail_txn_ccy",csTmp);
                                        PutField_CString(hTxn,"txn_ccy",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnDetail::txn_ccy = [%s]\n",csTmp));
                                }

/* txn_country */
                                if (GetField_CString(hRec,"txn_country",&csTmp)) {
                                        PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnDetail::txn_country = [%s]\n",csTmp));
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{
DEBUGLOG(("GetTxnInfo::GetTxnDetail:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVTO::GetTxnInfo::GetTxnDetail::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                }

                RecordSet_Destroy(rRecordSet);
        }	

	// Get Txn Elements (Txn Amount)
        if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnElements:GetFeeChgDetailByType [%s]\n", PD_ELEMENT_TXN_AMT));
                DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
                if ((*DBObjPtr)(csTxnSeq, PD_ELEMENT_TXN_AMT, cPartyType, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] found record = [%s]\n",PD_ELEMENT_TXN_AMT, csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/* amount */
                                if (GetField_Double(hRec, "amount", &dTmp)) {
                                        dTxnAmt += dTmp;
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] dTxnAmt = [%lf]\n",PD_ELEMENT_TXN_AMT, dTxnAmt));

                        // txn_amt
                        PutField_Double(hTxn, "txn_amt", dTxnAmt);
                }
                else{
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]\n",PD_ELEMENT_TXN_AMT, csTxnSeq));
ERRLOG("TxnMgtByUsVTO::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n", PD_ELEMENT_TXN_AMT, csTxnSeq);
                        iRet=INT_NOT_RECORD;
                }

                RecordSet_Destroy(rRecordSet);
        }
	
	// Get Txn Elements (Txn Fee)
        if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnElements:GetFeeChgDetailByType [%s]\n",  PD_ELEMENT_TXN_FEE ));
                DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
                if ((*DBObjPtr)(csTxnSeq,  PD_ELEMENT_TXN_FEE , cPartyType, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] found record = [%s]\n", PD_ELEMENT_TXN_FEE, csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/* amount */
                                if (GetField_Double(hRec, "amount", &dTmp)) {
                                        dTxnFee += dTmp;
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType::[%s] dTxnFee = [%lf]\n", PD_ELEMENT_TXN_FEE , dTxnFee));

                        // src_txn_fee
                        PutField_Double(hTxn, "src_txn_fee", dTxnFee);
                }
                else{
DEBUGLOG(("GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]\n", PD_ELEMENT_TXN_FEE , csTxnSeq));
ERRLOG("TxnMgtByUsVTO::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n",  PD_ELEMENT_TXN_FEE , csTxnSeq);
                        iRet=INT_NOT_RECORD;
                }

                RecordSet_Destroy(rRecordSet);
        }

	FREE_ME(rRecordSet);

	return iRet;
}

