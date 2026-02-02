/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/17              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRCP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

//#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(Txn);
OBJPTR(BO);
OBJPTR(DB);

void TxnOmtByUsRCP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int     iErrRetCode = PD_OK;

	int	i = 0;
	int	iTotalCnt = 0;
	
	char    *csBatchId= strdup("");
	char	*csUser;
	char	*csTmp;

        char    csBatchTxnSeq[PD_TXN_SEQ_LEN +1];
	char	csTag[PD_TAG_LEN +1];

	hash_t *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn, 0);

DEBUGLOG(("Authorize::()\n"));

/* batch_id */
        if (GetField_CString(hRequest, "batch_id", &csBatchId)) {
                PutField_CString(hContext, "batch_id", csBatchId);
DEBUGLOG(("Authorize:: batch_id = [%s]\n", csBatchId));
        } else {
DEBUGLOG(("Authorize:: batch_id not found!!\n"));
ERRLOG("TxnOmtByUsRCP: Authorize:: batch_id not found!!\n");
                iRet = INT_BATCH_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* ip_addr */
	if (iRet == PD_OK) {
       	 	if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
DEBUGLOG(("Authorize:: ip_addr = [%s]\n", csTmp));
        	}
	}

/* user */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "add_user", &csUser)) {
                	PutField_CString(hContext, "update_user", csUser);
                	PutField_CString(hContext, "add_user", csUser);
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
        	} else {
DEBUGLOG(("Authorize:: update_user not found!!\n"));
ERRLOG("TxnOmtByUsRCP: Authorize:: update_user not found!!\n");
                        iRet = INT_USER_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
	}

// Get Payout API Records (status Approved and ACK retry)
	if (iRet == PD_OK) {

		PutField_Int(hContext, "is_process_approve", PD_TRUE);		

DEBUGLOG(("Authorize::Call BOOLPayout::GetPayoutApiRecords\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","GetPayoutApiRecords");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
                if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call BOOLPayout::GetPayoutApiRecords Failure!!!\n"));
ERRLOG("TxnOmtByUsRCP: Authorize::Call BOOLPayout::GetPayoutApiRecords Failure!!!\n");
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }

// Update OL_PAYOUT_API_BATCH_HD
	if (iRet == PD_OK) {

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "MatchBatchStatus_ForUpdate_ByBatchId");
                if ((unsigned long)(*DBObjPtr)(csBatchId,PD_OL_PO_API_PENDING) == PD_FOUND) {

			hash_destroy(hTxn);
                	hash_init(hTxn, 0);

                	PutField_CString(hTxn,"batch_id",csBatchId);
                	PutField_Char(hTxn,"status",PD_OL_PO_API_PROCESSING);
                	PutField_CString(hTxn,"update_user",csUser);

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "Update");
                	iRet = (unsigned long)(*DBObjPtr)(hTxn);
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: TxnCommit\n"));
                                TxnCommit();
                        } else {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n"));
ERRLOG("BOOLPayout::Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n");
                        	iRet = INT_ERR;
                		PutField_Int(hContext,"internal_error",iRet);
                	}
		} else {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId Failure!!!\n"));
ERRLOG("BOOLPayout::Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId Failure!!!\n");
                        iRet = INT_TXN_STATUS_NOT_MATCH;
			PutField_Int(hContext,"internal_error",iRet);
                }
	}

// Resend Payout API Callback Message
	if (iRet == PD_OK) {

/* Generate batch_txn_seq */
        	DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
        	strcpy(csBatchTxnSeq,(*DBObjPtr)());
        	PutField_CString(hContext,"batch_txn_seq",csBatchTxnSeq);
DEBUGLOG(("Authorize::Call DBOLTxnSeq::GetNextOmtTxnSeq:: batch_txn_seq = [%s]\n", csBatchTxnSeq));

/* total_cnt */
		if (GetField_Int(hContext, "total_cnt", &iTotalCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iTotalCnt));

			for (i=0; i<iTotalCnt; i++) {

/* org_txn_id */
				sprintf(csTag,"org_txn_id_%d",i);
                        	if (GetField_CString(hContext,csTag,&csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag,csTmp));

                                	PutField_CString(hContext,"org_txn_seq",csTmp);

DEBUGLOG(("Authorize::Call TxnOplByUsACK::Authorize\n"));
					TxnObjPtr = CreateObj(TxnPtr,"TxnOplByUsACK","Authorize");
                                	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
                                	sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::[%s] = [%d]\n",csTag,iRet));
                                	PutField_Int(hResponse,csTag,iRet);
				}
			}
        	} else {
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnOmtByUsRCP: Authorize::total_cnt not found!!\n");
			iRet = INT_FORMAT_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
        	} 
	}

// Update OL_PAYOUT_API_BATCH_DT and OL_PAYOUT_API_BATCH_HD
	if ((iRet == PD_OK) || (GetField_Int(hContext,"internal_error",&iErrRetCode))) {

		if (iErrRetCode != 0) {
                	TxnAbort();
DEBUGLOG(("Authorize::Call TxnAbort()\n"));
		}

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "MatchBatchStatus_ForUpdate_ByBatchId");
               	if ((unsigned long)(*DBObjPtr)(csBatchId,PD_OL_PO_API_PROCESSING) == PD_FOUND) {

                        hash_destroy(hTxn);
                        hash_init(hTxn, 0);

                        PutField_CString(hTxn,"batch_id",csBatchId);
			if (iRet == PD_OK) {
                        	PutField_Char(hTxn,"status",PD_OL_PO_API_COMPLETE);
				PutField_Int(hTxn,"ret_code",PD_OK);
			} else { 
				PutField_Int(hTxn,"ret_code",iErrRetCode);
			}
                        PutField_CString(hTxn,"update_user",csUser);

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchDT", "UpdateByBatchId");
                	iRet = (unsigned long)(*DBObjPtr)(hTxn);
                	if (iRet == PD_OK) {

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update\n"));
                        	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "Update");
                        	iRet = (unsigned long)(*DBObjPtr)(hTxn);
                        	if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n"));
ERRLOG("BOOLPayout::Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n");
                                	iRet = INT_ERR;
                        	}
			} else {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId Failure!!!\n"));
ERRLOG("BOOLPayout::Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId Failure!!!\n");
                        	iRet = INT_ERR;
                	}
                } else {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId Failure!!!\n"));
ERRLOG("BOOLPayout::Authorize::Call DBOLPayoutApiBatchHD:: MatchBatchStatus_ForUpdate_ByBatchId Failure!!!\n");
                        iRet = INT_TXN_STATUS_NOT_MATCH;
                }

		if (iRet == PD_OK) {
                        TxnCommit();
DEBUGLOG(("Authorize::Call TxnCommit()\n"));
                }

		// Remove internal_error
		if (iErrRetCode != 0) {
			RemoveField_Int(hContext, "internal_error");
		}
	}

	hash_destroy(hTxn);
        FREE_ME(hTxn);

	FREE_ME(csBatchId);

DEBUGLOG(("TxnOmtByUsRCP Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

