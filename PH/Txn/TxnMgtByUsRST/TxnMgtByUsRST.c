/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/18              Elvis Wong
Allow Delivered to Returned			   2015/09/04		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRST.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(DB);

void TxnMgtByUsRST(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iDtlRet = PD_FOUND;

	double	dReceiveAmt = 0.0;

	char    *csTxnSeq = NULL;
	char	*csUser = NULL;
	char	*csSubStatus = NULL;
	char    *csReceiveCcy = NULL;
	char	*csReceiveAmt = NULL;
	char	*csRemark = NULL;

	hash_t  *hRec = NULL;

	hash_t  *hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	recordset_t     *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
	
DEBUGLOG(("Authorize()\n"));

/* txn_seq */
	if (GetField_CString(hRequest,"txn_seq",&csTxnSeq)) {
		PutField_CString(hContext,"txn_seq",csTxnSeq);
		PutField_CString(hData,"txn_seq",csTxnSeq);
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));
	} else {
DEBUGLOG(("Authorize:: txn_id not found!!\n"));
ERRLOG("TxnMgtByUsRST:: Authorize:: txn_id not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* receive_ccy */
	if (GetField_CString(hRequest, "receive_ccy", &csReceiveCcy)) {
                PutField_CString(hContext,"receive_ccy",csReceiveCcy);
                PutField_CString(hData,"receive_ccy",csReceiveCcy);
DEBUGLOG(("Authorize:: receive_ccy = [%s]\n",csReceiveCcy));
	}

/* receive_amt */
	if (GetField_CString(hRequest, "receive_amt", &csReceiveAmt)) {
		dReceiveAmt = string2double((const unsigned char*)csReceiveAmt);
                PutField_Double(hContext,"receive_amt",dReceiveAmt);
                PutField_Double(hData,"receive_amt",dReceiveAmt);
DEBUGLOG(("Authorize:: receive_amt = [%lf]\n",dReceiveAmt));
	}

	if (((csReceiveCcy != NULL) && (csReceiveAmt == NULL)) || ((csReceiveCcy == NULL) && (csReceiveAmt != NULL))) {
            	iRet = INT_ERR;
               	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: receive_ccy and receive_amt should exist in a pair!!\n"));
ERRLOG("TxnMgtByUsRST: Authorize:: receive_ccy and receive_amt should exist in a pair!!\n");
       	}

/* remark */
	if (GetField_CString(hRequest,"remark",&csRemark)) {
                PutField_CString(hContext,"remark",csRemark);
                PutField_CString(hData,"remark",csRemark);
DEBUGLOG(("Authorize: remark = [%s]\n",csRemark));
        } 

/* user */
	if (GetField_CString(hRequest,"add_user",&csUser)) {
		PutField_CString(hData,"update_user",csUser);
DEBUGLOG(("Authorize: user = [%s]\n",csUser));
	} else {
DEBUGLOG(("Authorize:: user not found!!\n"));
ERRLOG("TxnMgtByUsRST:: Authorize:: user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	// Select Txn for update
	if (iRet == PD_OK) {
	
		// Match Txn Status for update (Status is complete)
DEBUGLOG(("Authorize:: Call DBTransaction:: MatchTxnStatusforUpdate() [%s][%c]\n",csTxnSeq,PD_COMPLETE));
                DBObjPtr = CreateObj(DBPtr, "DBTransaction","MatchTxnStatusforUpdate");
                iDtlRet = (unsigned long)(*DBObjPtr)(csTxnSeq,PD_COMPLETE);
                if (iDtlRet == PD_FOUND) {
DEBUGLOG(("Authorize:: Call DBTransaction:: Success!!!\n"));
                } else {
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: Invalid Txn Id!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Invalid Txn Id!!!\n");
                }

		if (iRet == PD_OK) {

			// Get Txn Header Info (Sub Status)
DEBUGLOG(("Authorize:: Call DBTransaction: GetTxnHeader() [%s]\n", csTxnSeq));
                	DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
                	iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet);
                	if (iRet == PD_OK) {
                        	hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {

/* sub_status */
					if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: Call DBTransaction: sub_status = [%s]\n",csSubStatus));

						// Check sub_status is NOT in_process
						if (!strcmp(csSubStatus, PD_IN_PROCESS)) {
DEBUGLOG(("Authorize:: Call DBTransaction:: [sub_status] = [in_process]\n"));
						} else if (!strcmp(csSubStatus, PD_DELIVERED)) {
DEBUGLOG(("Authorize:: Call DBTransaction:: [sub_status] = [delivered]\n"));
						} else {
							iRet = INT_INVALID_TXN;
                                			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: INT_INVALID_TXN!!! [sub_status] != [in_process/delivered]\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: INT_INVALID_TXN!!! [sub_status] != [in_process/delivered]\n");
						}
                                	} else {
						iRet = INT_INVALID_TXN;
                                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: Invalid Txn Id (sub_status not found)!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Invalid Txn Id (sub_status not found)!!!\n");
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			} else {
                        	iRet = INT_INVALID_TXN;
                        	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: Invalid Txn Id!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Invalid Txn Id!!!\n");
                	}
		}
	}

	// Update Merchant Settlement Detail (receive_ccy, receive_amt, remark)
        if (iRet == PD_OK) {

		if (((csReceiveCcy != NULL) && (csReceiveAmt != NULL))
		    || (csRemark != NULL)
		) {

/* receive_ccy */ 
DEBUGLOG(("Authorize: receive_ccy = [%s]\n",csReceiveCcy));
	
/* receive_amt */ 
DEBUGLOG(("Authorize: receive_amt = [%lf]\n",dReceiveAmt));

/* remark */
DEBUGLOG(("Authorize: remark = [%s]\n",csRemark));

DEBUGLOG(("Authorize:: Call DBMerchantSettlementDetail:: Update()\n"));
             		DBObjPtr = CreateObj(DBPtr,"DBMerchantSettlementDetail","Update");
                	iRet = (unsigned long)(*DBObjPtr)(hData);
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBMerchantSettlementDetail:: Success!!!\n"));
                	} else {
                	        iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBMerchantSettlementDetail:: Failure!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBMerchantSettlementDetail:: Failure!!!\n");
                	}
		}               
        }

	// Update Txn Detail (remark)
	if (iRet == PD_OK) {
	
		if (csRemark != NULL) {
	
DEBUGLOG(("Authorize: remark = [%s]\n",csRemark));	

DEBUGLOG(("Authorize:: Call DBTransaction:: UpdateDetail()\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBTransaction","UpdateDetail");
                	iRet = (unsigned long)(*DBObjPtr)(hData);
                	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:: Success!!!\n"));
                	} else {
                	        iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBTransaction:: Failure!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Failure!!!\n");
			}
		}
	}

	// Update Txn Header (sub_status)
	if (iRet == PD_OK) {

/* sub_status */
                PutField_CString(hData,"sub_status",PD_RETURNED);
DEBUGLOG(("Authorize: sub_status = [%s]\n",PD_RETURNED));

DEBUGLOG(("Authorize:: Call DBTransaction:: Update()\n"));
                DBObjPtr = CreateObj(DBPtr, "DBTransaction","Update");
                iRet = (unsigned long)(*DBObjPtr)(hData);
                if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:: Success!!!\n"));
                } else {
                        iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBTransaction:: Failure!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Failure!!!\n");
                }
        }

/*
	// Add Txn Remarks
	if (iRet == PD_OK) {

		if (csRemark != NULL) {

// txn_seq 
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));

// txn_code 
               		PutField_CString(hData,"txn_code",PD_SETTLEMENT_REQUEST);
DEBUGLOG(("Authorize: txn_code = [%s]\n",PD_SETTLEMENT_REQUEST));

// status 
                	PutField_Char(hData,"status",PD_COMPLETE);
DEBUGLOG(("Authorize: status = [%c]\n",PD_COMPLETE));

// ar_ind 
                	PutField_Char(hData,"ar_ind",PD_ACCEPT);
DEBUGLOG(("Authorize: status = [%c]\n",PD_ACCEPT));

// sub_status 
DEBUGLOG(("Authorize: sub_status = [%s]\n",PD_RETURNED));

// remark 
DEBUGLOG(("Authorize: remark = [%s]\n",csRemark));

// add_user
			PutField_CString(hData,"add_user",csUser);
DEBUGLOG(("Authorize: user = [%s]\n",csUser));

DEBUGLOG(("Authorize() call DBTxnRemarks:: Add()\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBTxnRemarks", "Add");
                	iRet = (unsigned long)(*DBObjPtr)(hData);
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBTxnRemarks:: Success!!!\n"));
			} else { 
                	        iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBTxnRemarks:: Failure!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize() call DBTxnRemarks:: Failure!!!\n");
                	}	
		}
	}
*/

	hash_destroy(hData);
        FREE_ME(hData);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnMgtByUsRST Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

