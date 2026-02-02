/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/16       	   Elvis Wong       
Add ack batch_txn_seq                              2017/04/26              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOPX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

//#define       PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
//OBJPTR(Txn);
//OBJPTR(Channel);

void TxnOmtByUsOPX(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iErrRetCode = PD_OK;

	char    *csBatchId= strdup("");
        char    *csUser = NULL;
        char    *csTmp = NULL;

	hash_t *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);
	
DEBUGLOG(("Authorize\n"));

/* batch_id */
	if (GetField_CString(hRequest, "batch_id", &csBatchId)) {
		PutField_CString(hContext, "batch_id", csBatchId);
DEBUGLOG(("Authorize:: batch_id = [%s]\n", csBatchId));
	} else {
DEBUGLOG(("Authorize:: batch_id not found!!\n"));
ERRLOG("TxnOmtByUsOPX: Authorize:: batch_id not found!!\n");
		iRet = INT_BATCH_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hContext, "txn_seq", &csTmp)){
DEBUGLOG(("Authorize:: batch_txn_seq (for ack use)= [%s]\n", csTmp));
		PutField_CString(hContext, "batch_txn_seq", csTmp);
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
DEBUGLOG(("Authorize:: add_user not found!!\n"));
ERRLOG("TxnOmtByUsOPX: Authorize:: add_user not found!!\n");
                	iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Get Payout API Records	
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOOLPayout::GetPayoutApiRecords\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","GetPayoutApiRecords");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
                if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call BOOLPayout::GetPayoutApiRecords Failure!!!\n"));
ERRLOG("TxnOmtByUsOPX: Authorize::Call BOOLPayout::GetPayoutApiRecords Failure!!!\n");
			PutField_Int(hContext,"internal_error",iRet);
                }
	}
			
	// Handle Cancel Payout API
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOOLPayout::HandleCancelPayoutApi\n"));
          	BOObjPtr = CreateObj(BOPtr,"BOOLPayout","HandleCancelPayoutApi");
            	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call BOOLPayout::HandleCancelPayoutApi Failure!!!\n"));
ERRLOG("TxnOmtByUsOPX: Authorize::Call BOOLPayout::HandleCancelPayoutApi Failure!!!\n");
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	// Update Error Return Code
	if (GetField_Int(hContext,"internal_error",&iErrRetCode)) {
DEBUGLOG(("Authorize::internal_error = [%d]\n", iErrRetCode));
	
                TxnAbort();
DEBUGLOG(("Authorize::Call TxnAbort()\n"));
	
                PutField_CString(hTxn,"batch_id",csBatchId);
                PutField_Int(hTxn,"ret_code",iErrRetCode);
                PutField_CString(hTxn,"update_user",csUser);

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId\n"));
              	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchDT", "UpdateByBatchId");
              	iRet = (unsigned long)(*DBObjPtr)(hTxn);
            	if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId Failure!!!\n"));
ERRLOG("TxnOmtByUsOPX::Authorize::Call DBOLPayoutApiBatchDT:: UpdateByBatchId Failure!!!\n");
                     	iRet = INT_ERR;
               	}

		if (iRet == PD_OK) {

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update\n"));
                	DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchHD", "Update");
                	iRet = (unsigned long)(*DBObjPtr)(hTxn);
                	if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n"));
ERRLOG("TxnOmtByUsOPX::Authorize::Call DBOLPayoutApiBatchHD:: Update Failure!!!\n");
                        	iRet = INT_ERR;
                	}
                }

		if (iRet == PD_OK) {
			TxnCommit();
DEBUGLOG(("Authorize::Call TxnCommit()\n"));

			iRet = iErrRetCode;
		}
	
		// Remove internal_error
		RemoveField_Int(hContext, "internal_error");
 	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	FREE_ME(csBatchId);

DEBUGLOG(("TxnOmtByUsOPX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
