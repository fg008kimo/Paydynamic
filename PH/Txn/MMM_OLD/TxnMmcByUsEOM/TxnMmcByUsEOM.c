/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/21              LokMan Chow
Handle multiple records                            2011/03/15              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsEOM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DT_ELEMENT           "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMmcByUsEOM(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;

	int	iTotalCnt = 0;
	int	i;

	char    csTag[PD_TAG_LEN + 1];
        char    *csTxnSeq = NULL;
        char    *csDtlTxnSeq = NULL;
        char    *csTmp;

	hash_t *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	if (GetField_Int(hContext, "total_cnt", &iTotalCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n",iTotalCnt));
	}
	else {
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnMmcByUsEOM::Authorize::total_cnt not found!!\n");
                iRet=INT_ERR;
	}

        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
                PutField_CString(hTxn,"update_user",csTmp);
        }

	for (i = 1; i <= iTotalCnt; i++) {
		PutField_Int(hResponse, "total_cnt", i);

		if (iRet == PD_OK) {
			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_txnid_%d", PD_DT_ELEMENT, i);
			if (GetField_CString(hRequest, csTag, &csTxnSeq)) {
				PutField_CString(hTxn, "txn_seq", csTxnSeq);
DEBUGLOG(("Authorize::txnid= [%s]\n",csTxnSeq));
			}

			memset(csTag, 0, sizeof(csTag));		
			sprintf(csTag, "%s_dtl_txnid_%d", PD_DT_ELEMENT, i);
			if (GetField_CString(hRequest, csTag, &csDtlTxnSeq)) {
				PutField_CString(hTxn, "dtl_txn_seq", csDtlTxnSeq);
DEBUGLOG(("Authorize::dtl_txnid= [%s]\n",csDtlTxnSeq));
			}

			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:CheckTxnPending\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","CheckTxnPending");
				if((unsigned long) ((*DBObjPtr)(csTxnSeq,csDtlTxnSeq)) != PD_OK){
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
				}
				else {
					PutField_Char(hTxn, "status", PD_ACCEPT);

DEBUGLOG(("Authorize::Call DBMmsTransaction:UpdateDetail\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateDetail");
					if((unsigned long) ((*DBObjPtr)(hTxn)) != PD_OK){
						iRet = INT_ERR;
					}

DEBUGLOG(("Authorize::Call DBMmsTransaction:CheckPendingTxnByTxnId\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","CheckPendingTxnByTxnId");

					int iTmp = PD_FOUND;

					iTmp = (unsigned long) ((*DBObjPtr)(csTxnSeq));
					if (iTmp == PD_NOT_FOUND) {
DEBUGLOG(("Authorize::Call DBMmsTransaction:UpdateHeader\n"));

						PutField_Char(hTxn, "status", PD_COMPLETE);
						PutField_Char(hTxn, "ar_ind", PD_ACCEPT);

						DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","UpdateHeader");
						if((unsigned long) ((*DBObjPtr)(hTxn)) != PD_OK) {
							iRet = INT_ERR;
						}
					}
			
				}
			}
		}

		sprintf(csTag,"ret_%d",i);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iRet));
		PutField_Int(hResponse,csTag,iRet);	
		
	}


	hash_destroy(hTxn);
	FREE_ME(hTxn);

DEBUGLOG(("TxnMmcByUsEOM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
