/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/27              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsRTX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsRTX(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  	hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;

	//char	cTmp;
        char    *csTmp;
	char    *csTxnSeq = NULL;
	char	*csDtlTxnSeq = NULL;

	char	csTag[PD_TAG_LEN+1];
	char	cIsd_ind;

        double  dTmp = 0.0;

	hash_t *hTxn;   /* for logging */
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t	*hRec;
	recordset_t *rRecordSet;
	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);


        if(GetField_CString(hRequest,"txn_seq",&csTxnSeq)){
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTxnSeq));

		PutField_CString(hRequest, "host_ref", csTxnSeq);
                PutField_CString(hTxn,"txn_seq",csTxnSeq);

        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
        }         


	/* previous dtl_txn_sesq */
        if(GetField_CString(hRequest,"dtl_txn_seq",&csDtlTxnSeq)){
DEBUGLOG(("Authorize::dtl_txn_seq= [%s]\n",csDtlTxnSeq));
                PutField_CString(hTxn,"dtl_txn_seq",csDtlTxnSeq);

        }
        else{
DEBUGLOG(("Authorize::dtl_txnid not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::dtl_txnid not found!!\n");
                iRet=INT_INVALID_TXN;

		PutField_Int(hContext,"internal_error",iRet);
        }         

	/* current dtl_txn_Seq */
	if (GetField_CString(hContext, "dtl_txn_seq", &csTmp)) {
DEBUGLOG(("Authorize::current dtl_txn_seq= [%s]\n",csTmp));
		PutField_CString(hRequest, "host_dtl_ref", csTmp);

	}
        else{
DEBUGLOG(("Authorize::current dtl_txnid not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::current dtl_txnid not found!!\n");
                iRet=INT_INVALID_TXN;

		PutField_Int(hContext,"internal_error",iRet);
        }         


        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
                PutField_CString(hTxn,"update_user",csTmp);
        }

        if(GetField_CString(hRequest,"transmission_datetime",&csTmp)){
DEBUGLOG(("Authorize::transmission_datetime = [%s]\n",csTmp));
        }
        else{
DEBUGLOG(("Authorize::transmission_datetime not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::transmission_datetime not found!!\n");
                iRet=INT_TRASMISSION_TIME_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }         

 
/*********************/
/* GET AMOUNT DETAIL */
/*********************/
/* txn_amt */
       if(GetField_Double(hContext,"txn_amt",&dTmp)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_ccy */
	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTmp));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* adjustment*/
       if(GetField_Double(hContext,"adjustment",&dTmp)){
DEBUGLOG(("Authorize::adjustment = [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::adjustment not found!!\n"));
        }

/* rate */
       if(GetField_Double(hContext,"exchange_rate",&dTmp)){
DEBUGLOG(("Authorize::exchange_rate = [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::exchange_rate not found!!\n"));
        }

/* processing_cost */
       if(GetField_Double(hContext,"processing_cost",&dTmp)){
DEBUGLOG(("Authorize::processing_cost = [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::processing_cost not found!!\n"));
//ERRLOG("TxnMmcByUsRTX::Authorize::processing_cost not found!!\n");
        }

/* bank_charge */
       if(GetField_Double(hContext,"bank_charge",&dTmp)){
DEBUGLOG(("Authorize::bank_charge = [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::bank_charge not found!!\n"));
//ERRLOG("TxnMmcByUsRTX::Authorize::bank_charge not found!!\n");
        }

/* bank_charge_refund */
       if(GetField_Double(hContext,"bank_charge_refund",&dTmp)){
DEBUGLOG(("Authorize::bank_charge_refund = [%f]\n",dTmp));
        }
        else{
DEBUGLOG(("Authorize::bank_charge_refund not found!!\n"));
//ERRLOG("TxnMmcByUsRTX::Authorize::bank_charge_refund not found!!\n");
        }


/* filing Number */
       if(GetField_Double(hRequest,"filing_number",&csTmp)){
DEBUGLOG(("Authorize::filing_number = [%d]\n",csTmp));
        }
        else{
DEBUGLOG(("Authorize::filing_number not found!!\n"));
//ERRLOG("TxnMmcByUsRTX::Authorize::filing_number not found!!\n");
        }


/****************************/
/* check org txn status 'W' */
/****************************/

	if(iRet==PD_OK){

DEBUGLOG(("Authorize::Call DBMmsTransaction:CheckTxnPending\n"));
                DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","CheckTxnPending");
                if((unsigned long) ((*DBObjPtr)(csTxnSeq,csDtlTxnSeq)) != PD_OK){

DEBUGLOG(("Authorize::Call DBMmsTransaction:CheckTxnPending Fail\n"));

                        iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
                }
	}	


/**************************/
/* GET Request Txn Record */
/**************************/
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail\n"));

		DBObjPtr = CreateObj(DBPtr, "DBMmsTransaction", "GetMmsTxnDetail");
                if ((unsigned long)((*DBObjPtr)(csTxnSeq, csDtlTxnSeq, rRecordSet)) != PD_OK) {

DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail FAIL\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::Call DBMmsTransaction:GetMmsTxnDetail FAIL\n");

                        iRet = INT_ERR;
                        PutField_Int(hContext,"internal_error",iRet);
                }
                else{
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec, "txn_code", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail txn_code [%s]\n", csTmp));
				}
	
				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail merchant_id [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_type", PD_MMS_PARTY_MERCH);
					PutField_CString(hRequest, "mms_from_id", csTmp);
				}

				if (GetField_CString(hRec, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail psp_id [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_type", PD_MMS_PARTY_PSP);
					PutField_CString(hRequest, "mms_from_id", csTmp);
				}

				if (GetField_CString(hRec, "mb_id", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail mb_id [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_type", PD_MMS_PARTY_MB);
					PutField_CString(hRequest, "mms_from_id", csTmp);
				}

				if (GetField_CString(hRec, "bank_id", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail bank_id [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_type", PD_MMS_PARTY_BANK);
					PutField_CString(hRequest, "mms_from_id", csTmp);
				}

				if (GetField_CString(hRec, "party_node_id", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail party_node_id [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_node", csTmp);
				}

				if (GetField_CString(hRec, "service_code", &csTmp)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail service_code [%s]\n", csTmp));
					PutField_CString(hRequest, "mms_from_service", csTmp);
				}

				if (GetField_Char(hRec, "isd_ind", &cIsd_ind)) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetail isd_ind [%c]\n", cIsd_ind));

					memset(csTag, 0, sizeof(csTag));

					if (cIsd_ind == PD_DESTINATION) {
						sprintf(csTag, "%s", "RSA");
					}
					else {
						sprintf(csTag, "%s", "RDA");
					}
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}


/******************/
/* GET PARTY INFO */
/******************/
	if (iRet == PD_OK)  {

		if (GetField_CString(hRequest, "party_type", &csTmp)) {
DEBUGLOG(("Authorize::party_type = [%s]\n",csTmp));
			PutField_CString(hRequest, "mms_to_type", csTmp);
		}
		else {
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::party_type not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

		if (cIsd_ind !=  PD_DESTINATION) {

			if (GetField_CString(hRequest, "party_id", &csTmp)) {
DEBUGLOG(("Authorize::party_id = [%s]\n",csTmp));
				PutField_CString(hRequest, "mms_to_id", csTmp);
			}
			else {
DEBUGLOG(("Authorize::party_id not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::party_id not found!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if (GetField_CString(hRequest, "party_node", &csTmp)) {
DEBUGLOG(("Authorize::party_node = [%s]\n",csTmp));
				PutField_CString(hRequest, "mms_to_node", csTmp);
			}
			else {
DEBUGLOG(("Authorize::party_node not found!!\n"));
ERRLOG("TxnMmcByUsRTX::Authorize::party_node not found!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if (GetField_CString(hRequest, "party_service", &csTmp)) {
DEBUGLOG(("Authorize::party_service = [%s]\n",csTmp));
                        	PutField_CString(hRequest, "mms_to_service", csTmp);
                	}
			else {
DEBUGLOG(("Authorize::party_service not found\n"));
			}
		}
	}


	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call TxnMmsByUs%s: Authorize\n", csTag));
		char *csHandler;

                csHandler = (char*) malloc (20);
                sprintf(csHandler,"TxnMmcByUs%s",csTag);
		
	
		TxnObjPtr = CreateObj(TxnPtr, csHandler, "Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
DEBUGLOG(("Authorize::Call TxnMmsByUs%s iRet=[%d]\n", csTag, iRet));
	
		FREE_ME(csHandler);	
	}


 
	if (iRet == PD_OK) {

		PutField_Char(hTxn, "status", PD_COMPLETE);
		PutField_Char(hTxn, "ar_ind", PD_ACCEPT);

DEBUGLOG(("Authorize::Call DBMmsTransaction:UpdateDetail\n"));

		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateDetail");
		if((unsigned long) ((*DBObjPtr)(hTxn)) != PD_OK){
			iRet = INT_ERR;
		}
	}


	hash_destroy(hTxn);
	FREE_ME(hTxn);


DEBUGLOG(("TxnMmcByUsRTX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
