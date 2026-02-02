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
#include "TxnOmtByUsROS.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(DB);

void TxnOmtByUsROS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;

	char    cStatus;

	double  dReceiveAmt = 0.0;
	        
	char    *csTxnSeq = NULL;
        char    *csUser = NULL;
	char    *csSubStatus = NULL;
	char    *csReceiveCcy = NULL;
        char    *csReceiveAmt = NULL;
        char    *csRemark = NULL;

	hash_t  *hRec = NULL;

	hash_t  *hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);
	
	recordset_t     *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);	

	cStatus = ' ';

DEBUGLOG(("Authorize()\n"));

/* txn_seq */
	if (GetField_CString(hRequest,"txn_seq",&csTxnSeq)) {
		PutField_CString(hContext,"txn_seq",csTxnSeq);
		PutField_CString(hData,"txn_seq",csTxnSeq);
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));
	} else {
DEBUGLOG(("Authorize:: txn_id not found!!\n"));
ERRLOG("TxnOmtByUsROS:: Authorize:: txn_id not found!!\n");
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
ERRLOG("TxnMgtByUsROS: Authorize:: receive_ccy and receive_amt should exist in a pair!!\n");
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
ERRLOG("TxnOmtByUsROS:: Authorize:: user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	// Select OL Txn for update
	if (iRet == PD_OK) {

		// Get OL Txn Id for update
DEBUGLOG(("Authorize:: Call DBOLTransaction: GetTxnIdForUpdate() [%s]\n", csTxnSeq));
        	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnIdForUpdate");
        	iRet = (unsigned long)(*DBObjPtr)(csTxnSeq);
        	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Success!!!\n"));
        	} else {
        	        iRet = INT_INVALID_TXN;
        	        PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Invalid Txn Id!!!\n"));
ERRLOG("TxnOmtByUsROS::Authorize::Call DBOLTransaction:: Invalid Txn Id!!!\n");
        	}

		if (iRet == PD_OK) {
	
			// Get OL Txn Header Info (Status and Sub Status)
DEBUGLOG(("Authorize:: Call DBOLTransaction: GetTxnHeader() [%s]\n", csTxnSeq));
                        DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
                        iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet);
                        if (iRet == PD_OK) {
                                hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {

/* status */
					if (GetField_Char(hRec, "status", &cStatus)) {
DEBUGLOG(("Authorize:: Call DBTransaction: status = [%c]\n",cStatus));
					} else {
						iRet = INT_INVALID_TXN;
                                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: Invalid Txn Id (status not found)!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Invalid Txn Id (status not found)!!!\n");
					}
		
/* sub_status */
					if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: Call DBTransaction: sub_status = [%s]\n",csSubStatus));
                                        } else {
                                                iRet = INT_INVALID_TXN;
                                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: Invalid Txn Id (sub_status not found)!!!\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: Invalid Txn Id (sub_status not found)!!!\n");
                                        }
	
					// 
					// Check: status = [complete] 
					// 	  AND sub_status = [in_process] or [delivered]
					//
					if (iRet == PD_OK) {
						if (cStatus != PD_COMPLETE) {
							iRet = INT_INVALID_TXN;
                                                        PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: INT_INVALID_TXN!!! [status] != [complete]\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: INT_INVALID_TXN!!! [status] != [complete]\n");
						} else {
  							if (!strcmp(csSubStatus, PD_IN_PROCESS)) {
DEBUGLOG(("Authorize:: Call DBTransaction: sub_status = [in_process]\n"));
							} else if (!strcmp(csSubStatus, PD_DELIVERED)) {
DEBUGLOG(("Authorize:: Call DBTransaction: sub_status = [delivered]\n"));
							} else {
								iRet = INT_INVALID_TXN;
	                                                        PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBTransaction:: INT_INVALID_TXN!!! [status] != [complete] or [sub_status] != [in_process/delivered]\n"));
ERRLOG("TxnMgtByUsRST::Authorize::Call DBTransaction:: INT_INVALID_TXN!!! [status] != [complete] or [sub_status] != [in_process/delivered]\n");
							}
						}
					}

					hRec = RecordSet_GetNext(rRecordSet);
                                }
                        } else {
                                iRet = INT_INVALID_TXN;
                                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Invalid Txn Id!!!\n"));
ERRLOG("TxnMgtByUsROS::Authorize::Call DBOLTransaction:: Invalid Txn Id!!!\n");
                        }
		}
	}

	// Update OL Merchant Settlement Detail (receive_ccy, receive_amt, remark)
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

DEBUGLOG(("Authorize:: Call DBOLMerchantSettlementDetail:: Update()\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBOLMerchantSettlementDetail","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hData);
                        if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLMerchantSettlementDetail:: Success!!!\n"));
                        } else {
                                iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBOLMerchantSettlementDetail:: Failure!!!\n"));
ERRLOG("TxnMgtByUsROS::Authorize::Call DBOLMerchantSettlementDetail:: Failure!!!\n");
                        }
                }
        }

	// Update OL Txn Detail (remark)
/*
        if (iRet == PD_OK) {

                if (csRemark != NULL) {

DEBUGLOG(("Authorize: remark = [%s]\n",csRemark));

DEBUGLOG(("Authorize:: Call DBOLTransaction:: UpdateDetail()\n"));
                        DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","UpdateDetail");
                        iRet = (unsigned long)(*DBObjPtr)(hData);
                        if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Success!!!\n"));
                        } else {
                                iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Failure!!!\n"));
ERRLOG("TxnMgtByUsROS::Authorize::Call DBOLTransaction:: Failure!!!\n");
                        }
                }
        }
*/

	// Update OL Txn Header (sub_status)
	if (iRet == PD_OK) {

/* sub_status */
		PutField_CString(hData,"sub_status",PD_RETURNED);
DEBUGLOG(("Authorize: sub_status = [%s]\n",PD_RETURNED));
				
DEBUGLOG(("Authorize:: Call DBOLTransaction Update()\n"));
            	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","Update");
               	iRet = (unsigned long)(*DBObjPtr)(hData);
             	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Success!!!\n"));
               	} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBOLTransaction:: Failure!!!\n"));
ERRLOG("TxnOmtByUsROS::Authorize::Call DBOLTransaction:: Failure!!!\n");
            	}
      	}


/*
	// Add OL Txn Remarks
	if (iRet == PD_OK) {

		if (csRemark != NULL) {
// txn_seq 
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));

// txn_code 
                	PutField_CString(hData,"txn_code",PD_OL_SETTLEMENT_REQUEST);
DEBUGLOG(("Authorize: txn_code = [%s]\n",PD_OL_SETTLEMENT_REQUEST));

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

DEBUGLOG(("Authorize() call DBOLTransaction:: Add()\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBOLTxnRemarks", "Add");
                	iRet = (unsigned long)(*DBObjPtr)(hData);
                	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction:: Success!!!\n"));
                	} else {
                	        iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction:: Failure!!!\n"));
ERRLOG("TxnOmtByUsROS::Authorize() call DBOLTransaction:: Failure!!!\n");
                	}
		}
        }
*/


	hash_destroy(hData);
        FREE_ME(hData);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsROS Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

