/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/20              Virginia Yun
Modify						   2016/07/08		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVPP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

int     GetTxnInfo(const unsigned char *csTxnSeq, hash_t * hTxn);

void 	TxnMgtByUsVPP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int     iMiniMMMOn = PD_FALSE;
        int     iSupportMiniMMM = PD_FALSE;
        int     iRetErrIfNotMi = PD_FALSE;

	double  dTmp = 0.0;

	char    *csOrgTxnSeq = NULL;	
	char    *csRemark = NULL;	
        char	*csDate = NULL;
	char    *csUser = NULL;
	char	*csTmp = NULL;

	hash_t	*hOrgTxn;
	hOrgTxn = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hOrgTxn, 0);

	hash_t	*hTxn;
	hTxn = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

/* org_txn_seq */
	if (GetField_CString(hRequest, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("Authorize::org_txn_seq = [%s]\n",csOrgTxnSeq));
                PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
                PutField_CString(hContext, "org_txn_seq", csOrgTxnSeq);
	}

/* remark */
       	if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("Authorize::remark = [%s]\n",csRemark));
  	} else {
DEBUGLOG(("Authorize::remark not found!!\n"));
ERRLOG("TxnMgtByUsVPP::Authorize::remark not found!!\n");
              	iRet = INT_REMARK_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* add_user */
	if (GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user = [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}

/* PHDATE */
	if (GetField_CString(hContext, "PHDATE", &csDate)) {
DEBUGLOG(("Authorize::PHDATE = [%s]\n",csDate));
	}

	// Get Txn Info
	if (iRet == PD_OK) {

		iRet = GetTxnInfo((const unsigned char *)csOrgTxnSeq, hTxn);
		if (iRet == PD_OK) {

/* psp_id */
			if (GetField_CString(hTxn, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize::psp_id = [%s]\n",csTmp));
                        	PutField_CString(hContext, "psp_id", csTmp);
			}

/* txn_amt */
			if (GetField_Double(hTxn, "txn_amt", &dTmp)) {
DEBUGLOG(("Authorize::txn_amt = [%lf]\n",dTmp));
                	        PutField_Double(hContext, "txn_amt", dTmp);
			}

/* src_txn_fee */
			if (GetField_Double(hTxn, "src_txn_fee", &dTmp)) {
DEBUGLOG(("Authorize::fee = [%lf]\n",dTmp));
                	        PutField_Double(hContext, "src_txn_fee", dTmp);
			}

/* net_ccy */
			if (GetField_CString(hTxn, "net_ccy", &csTmp)) {
DEBUGLOG(("Authorize::net_ccy = [%s]\n",csTmp));
                	        PutField_CString(hContext, "net_ccy", csTmp);
                	}

/* txn_ccy */
                	if (GetField_CString(hTxn, "txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::txn_ccy = [%s]\n",csTmp));
                	        PutField_CString(hContext, "txn_ccy", csTmp);
                	}

/* txn_country */
                	if (GetField_CString(hTxn, "txn_country", &csTmp)) {
DEBUGLOG(("Authorize::txn_country = [%s]\n",csTmp));
                	        PutField_CString(hContext, "txn_country", csTmp);
                	}
		} else {
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Set Txn Info
	if (iRet == PD_OK) {

		// party_type
		PutField_Char(hContext, "party_type", PD_TYPE_PSP);

		// void_flag
		PutField_Int(hContext, "void_flag", PD_TRUE);
		
		// dc_ind
		PutField_Char(hContext, "dc_ind", PD_IND_DEBIT); 
		
		// chg_bal_mode
		PutField_Int(hContext, "chg_bal_mode", PD_TRUE); 
	}

	/**************************************************************************************************************/
	// Check Mini-MMM Mode
        if (iRet == PD_OK) {
                char*   csValue;
                csValue = (char*) malloc (128);
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)(PD_MINI_MMM_ENABLE,csValue) == FOUND) {
DEBUGLOG(("Authorize::Mini-MMM Mode = [%s]\n",csValue));
                        if (!strcmp(csValue, PD_ENABLE_MMSMODE)){
                                iMiniMMMOn = PD_TRUE;
                        }
                }
                FREE_ME(csValue);
        }

	// Check mi_mode_txn_ctl
        if (iRet == PD_OK && iMiniMMMOn) {
                hash_t  *hData;
                hData = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hData,0);

                DBObjPtr = CreateObj(DBPtr,"DBMiModeTxnCtl","GetMiModeTxnCtl");
                iRet = (unsigned long) (*DBObjPtr)(PD_MI_TXN_TYPE_VOID_PSP_FUNDIN,hData);
                if(iRet == PD_OK){
                        GetField_Int(hData,"err_if_not_mi",&iRetErrIfNotMi);
                        GetField_Int(hData,"mi_support",&iSupportMiniMMM);
                        if(!iSupportMiniMMM){
                                iMiniMMMOn = PD_FALSE;
DEBUGLOG(("Authorize::this transaction type does not support Mini-MMM mode\n"));
                        }
                        else{
DEBUGLOG(("Authorize::this transaction type support Mini-MMM mode\n"));
                        }
                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::Call DBMiModeTxnCtl:GetMiModeTxnCtl() Failed!!\n"));
ERRLOG("TxnMgtByUsVPP:: Authorize:: Call DBMiModeTxnCtl:GetMiModeTxnCtl() Failed!!\n");
                }

                FREE_ME(hData);
        }

	if (!iMiniMMMOn && iRetErrIfNotMi) {
                iRet = INT_MINI_MMM_MODE_DISABLED;
        }
	
	// Restore SEB Balance
        if (iRet == PD_OK && !iMiniMMMOn) {
DEBUGLOG(("Authroize::Call BOBalance:RestoreSebBalance()\n"));
                BOObjPtr = CreateObj(BOPtr,"BOBalance","RestoreSebBalance");
                if((unsigned long)(*BOObjPtr)(hContext,hRequest)!=PD_OK)
                        iRet = INT_ERR;
DEBUGLOG(("Authroize::BOBalance:RestoreSebBalance() result = [%d]\n",iRet));
        }
	/**************************************************************************************************************/

	// Update PSP Balance
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOBalance: ProcessFundinPayout\n"));
                BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessFundinPayout");
                iRet = (unsigned long)((*BOObjPtr)(hContext));
	}
	
	// Update Txn Header (Org Txn Seq)
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call Update Org Transaction\n"));

		// status
		PutField_Char(hOrgTxn,"status",PD_REVERSED);

		// sub_status
		//PutField_CString(hOrgTxn,"sub_status",PD_VOID);	// Approved_Refund
		PutField_CString(hOrgTxn,"sub_status",PD_UNDO);	// Voided

		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		if ((unsigned long) ((*DBObjPtr)(hOrgTxn)) != PD_OK) {
			iRet = INT_ERR;
		}
	}

	// Add Txn Detail
	if (iRet == PD_OK) {

		// remark
               	PutField_CString(hContext, "remark", csRemark);

DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		if((unsigned long) ((*DBObjPtr)(hContext)) != PD_OK){
			iRet = INT_ERR;
		}
	}

	// Add Txn Psp Detail
	if (iRet == PD_OK) {

		// desc
		//PutField_CString(hContext, "desc", "Void Fund In to PSP For Payout");	// for HS
		//PutField_CString(hContext, "desc", "Void Fund in payout for PSP");	// for AP
		//PutField_CString(hContext, "desc", "Void PSP Fund-In For Payout");	// for AP
		PutField_CString(hContext, "desc", "Void FundIn Payout for PSP");

		// txn_date
		PutField_CString(hContext, "txn_date", csDate);
		
		// PHDATE
		PutField_CString(hContext, "PHDATE", csDate);

/* report_date */
        	if (GetField_CString(hRequest, "report_date", &csTmp)) {
DEBUGLOG(("Authorize::report_date = [%s]\n",csTmp));
			PutField_CString(hContext, "report_date", csTmp);
        	} else {
			PutField_CString(hContext, "report_date", csDate);
		}
	
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
		if ((unsigned long) ((*DBObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
		}

		if (iRet==PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
			if ((unsigned long) ((*DBObjPtr)(hContext)) != PD_OK) {
				iRet = INT_ERR;
			}
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
	if (iRet == PD_OK ){

/* txn_seq */
		if (GetField_CString(hContext,"txn_seq",&csTmp)) {
			PutField_CString(hResponse,"org_txn_seq",csTmp);
		}
	}

	FREE_ME(hOrgTxn);
	FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsVPP Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int	GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn)
{
	int     iRet = PD_OK;

        double  dTxnAmt = 0.0;
        double  dTxnFee = 0.0;
	double  dTmp = 0.0;
	
	char	cPartyType;

	char	*csTmp;

	hash_t		*hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

	// Set Party Type
	cPartyType = PD_TYPE_PSP;

	// Get Txn Header
        if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnHeader\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetTxnHeader::found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/* net_ccy */
                                if (GetField_CString(hRec,"net_ccy",&csTmp)) {
                                        PutField_CString(hTxn,"net_ccy",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnHeader::net_ccy = [%s]\n",csTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
                else{
DEBUGLOG(("GetTxnInfo::GetTxnHeader:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVPP::Authorize::GetTxnHeader::not found record!!\n");
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
ERRLOG("TxnMgtByUsVPP::GetTxnInfo::GetTxnDetail::not found record!!\n");
			iRet=INT_NOT_RECORD;
		}

		RecordSet_Destroy(rRecordSet);
        }

	// Get Txn PSP Detail
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnPspDetail:GetTxnPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail::found record = [%s]\n",csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
/* psp_id */
				if (GetField_CString(hRec, "psp_id", &csTmp)) {
					PutField_CString(hTxn,"psp_id",csTmp);
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail::psp_id = [%s]\n",csTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
DEBUGLOG(("GetTxnInfo::GetTxnPspDetail:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsVPP::GetTxnPspInfo::GetTxnPspDetail::not found record!!\n");
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
ERRLOG("TxnMgtByUsVPP::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n", PD_ELEMENT_TXN_AMT, csTxnSeq);
			iRet=INT_NOT_RECORD;
		}

		RecordSet_Destroy(rRecordSet);
	}

	// Get Txn Elements (Txn Fee) 
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTxnElements:GetFeeChgDetailByType [%s]\n", PD_ELEMENT_TXN_FEE));
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
ERRLOG("TxnMgtByUsVPP::GetTxnInfo::GetFeeChgDetailByType:: [%s] not found record for [%s]!!\n", PD_ELEMENT_TXN_FEE, csTxnSeq);
			iRet=INT_NOT_RECORD;
		}

		RecordSet_Destroy(rRecordSet);
	}

        FREE_ME(rRecordSet);

        return iRet;
}
