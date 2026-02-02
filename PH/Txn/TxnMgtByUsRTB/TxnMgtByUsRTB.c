/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/13              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRTB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;

OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsRTB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iCnt  = 0, i;

        char    csTag[PD_TAG_LEN +1];
	char	*csPtr;
	char	*csUser = NULL;

        hash_t  *hReq;

        hReq = (hash_t*) malloc (sizeof(hash_t));


DEBUGLOG(("TxnMgtByUsRTB Authorize()\n"));
/* txn ack log */
        char    csBatchTxnSeq[PD_TXN_SEQ_LEN +1];

/*
        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMgtTxnSeq");
        strcpy(csBatchTxnSeq,(*DBObjPtr)());
*/
/* end txn ack log */

	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize::user = [%s]\n", csUser));
	}

        if (GetField_Int(hContext,"total_cnt",&iCnt)) {
		PutField_Int(hResponse, "total_cnt", iCnt);
DEBUGLOG(("Authorize::() total_cnt = [%d]\n",iCnt));

		for (i = 0; i < iCnt; i++) {

			//hash_destroy(hReq);
			hReq = (hash_t*) malloc (sizeof(hash_t));
        		hash_init(hReq,0);

			if (csUser != NULL) {
				PutField_CString(hReq, "update_user", csUser);
			}
			
                        sprintf(csTag,"%s_txnid_%d",PD_DETAIL_TAG,i+1);
                        if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csPtr));
                        	sprintf(csTag,"%s_batchid_%d",PD_DETAIL_TAG,i+1);
        			if (!GetField_CString(hRequest,csTag,&csBatchTxnSeq)) {
/*******/

DEBUGLOG(("Authorize::Call DBTxnAckRetry:FindMaxBatchID\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTxnAckRetry","FindMaxBatchID");

					if ((*DBObjPtr)(csPtr, &csBatchTxnSeq) == PD_OK) {
DEBUGLOG(("Authorize::Max Batch ID = [%s]\n", csBatchTxnSeq));
						PutField_CString(hReq,"batch_txn_seq",csBatchTxnSeq);
					}
					else {
DEBUGLOG(("Authorize::Call DBTxnAckRetry:FindMaxBatchID Fail!\n"));
ERRLOG("TxnMgtByUsRTB::Authorize::Call DBTxnAckRetry:FindMaxBatchID FAIL\n");
						iRet = INT_ERR;
                				PutField_Int(hContext,"internal_error",iRet);
					}
/*******************/
				}

				/* txn_seq */
				PutField_CString(hReq,"txn_seq",csPtr);
				PutField_CString(hContext,"org_txn_seq",csPtr);

				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnAckRetry:CounterReset\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTxnAckRetry","CounterReset");

					if ((*DBObjPtr)(hReq) != PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnAckRetry:CounterReset FAIL\n"));
ERRLOG("TxnMgtByUsRTB::Authorize::Call DBTxnAckRetry:CounterReset FAIL\n");
						iRet = INT_ERR;
					}

/*

DEBUGLOG(("Authorize::Call DBTxnWebByUsACK:Authorize\n"));

						TxnObjPtr = CreateObj(TxnPtr,"TxnWebByUsACK","Authorize");
						iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

DEBUGLOG(("Authorize::Call DBTxnWebByUsACK return [%d]\n", iRet));
					}
*/
				}
				sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iRet));
	                        PutField_Int(hResponse,csTag,iRet);
			}
		}
	}
	else {
                iRet = INT_FORMAT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
	}

	hash_destroy(hReq);
	FREE_ME(hReq);


DEBUGLOG(("TxnMgtByUsRTB Normal Exit() iRet = [%d]\n",iRet));

	return iRet;
}
