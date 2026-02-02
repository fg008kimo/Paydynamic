/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/13              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCBS.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsCBS(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csTmp;
	char	*csUser;
	int	iResendCnt = 0;

	hash_t  	*hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hash_t		*hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	char    *csTxnId = NULL;

/* txn_id */
	if (GetField_CString(hRequest, "org_txn_seq", &csTxnId)) {
DEBUGLOG(("Authorize::txn_id = [%s]\n", csTxnId));
		PutField_CString(hTxn, "txn_seq", csTxnId);
	} else {
DEBUGLOG(("Authorize:: txn_id not found!!\n"));
ERRLOG("TxnMgtByUsCBS:: Authorize:: txn_id not found!!\n");
		iRet = INT_TXN_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* user */
        if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
                PutField_CString(hTxn,"update_user",csUser);
        } else {
                iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsCBS::Authorize() user NOT FOUND!!!\n");
		PutField_Int(hContext,"internal_error",iRet);
        }

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csTxnId,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::found record = [%s]\n",csTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"sub_status", &csTmp)) {
DEBUGLOG(("Authorize:: sub_status = [%s]\n",csTmp));
					if(strcmp(csTmp,PD_PENDING_ACK_RETRY)) {
DEBUGLOG(("Authorize:: sub_status is not %s\n", PD_PENDING_ACK_RETRY));
ERRLOG("TxnMgtByUsCBS::Authorize() sub_status is not %s\n", PD_PENDING_ACK_RETRY);
						iRet = INT_INVALID_TXN;
						PutField_Int(hContext,"internal_error",iRet);
					}
				}

				if (GetField_CString(hRec,"ack_status", &csTmp)) {
DEBUGLOG(("Authorize:: ack_status = [%s]\n",csTmp));
					if(strcmp(csTmp,PD_PENDING_ACK_RETRY)) {
DEBUGLOG(("Authorize:: ack_status is not %s\n", PD_PENDING_ACK_RETRY));
ERRLOG("TxnMgtByUsCBS::Authorize() ack_status is not %s\n", PD_PENDING_ACK_RETRY);
						iRet = INT_INVALID_TXN;
						PutField_Int(hContext,"internal_error",iRet);
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("Authorize:: not found txn record for [%s]\n",csTxnId));
ERRLOG("TxnMgtByUsCBS::Authorize() not found txn record for [%s]\n",csTxnId);
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTxnAckRetry","GetResendCount");
		if ((*DBObjPtr)(csTxnId,&iResendCnt) == PD_OK) {
DEBUGLOG(("Authorize:: resend_count = [%d]\n", iResendCnt));
			if (iResendCnt != PD_ACK_MAX_RETRY) {
DEBUGLOG(("Authorize:: resend count is not equal to %d\n",PD_ACK_MAX_RETRY));
ERRLOG("TxnMgtByUsCBS::Authorize() resend count is not equal to %d\n",PD_ACK_MAX_RETRY);
				iRet = INT_ACK_RETRY_PROCESSING;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hTxn, "sub_status", PD_ACK_TO_MERCHANT);
		PutField_CString(hTxn, "ack_status", PD_ACK_TO_MERCHANT);

		DBObjPtr = CreateObj(DBPtr, "DBTransaction","Update");
		if ((*DBObjPtr)(hTxn) == PD_OK) {
DEBUGLOG(("Authorize:: Update success\n"));
		} else {
DEBUGLOG(("Authorize:: Update ERROR\n"));
ERRLOG("TxnMgtByUsCBS::Authorize() Update ERROR\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(hTxn);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}
