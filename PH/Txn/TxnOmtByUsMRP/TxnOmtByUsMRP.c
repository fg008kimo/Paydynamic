/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/02/13              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMRP.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsMRP(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csTxnCode = NULL;
	char	*csTxnSeq = NULL;
	char	*csOPATxnId = NULL;
	char	*csRemark = NULL;
	char	*csUser = NULL;
	char	*csTmp = NULL;

	int	iReturnFee = PD_FALSE; 	

	hash_t *hTxnHeader = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxnHeader, 0);

DEBUGLOG(("TxnOmtByUsMRP: Authroize()\n"));

/* tc */
	if (GetField_CString(hRequest, "txn_code", &csTxnCode)) {
DEBUGLOG(("Authorize:: tc = [%s]\n", csTxnCode));
	} else {
		//iRet = INT_ERR;
		//PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize:: tc not found\n"));
//ERRLOG("TxnOmtByUsMRP:: Authorize:: tc not found\n");
	}

/* merchant returned payout txn id */
 	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authroize:: Merchant Returned Payout Txn ID = [%s]\n", csTxnSeq));
                	//PutField_CString(hContext, "from_txn_seq", csTxnSeq);
                	PutField_CString(hTxnHeader, "txn_seq", csTxnSeq);
        	} else {
                	iRet = INT_TXN_ID_MISSING;
                	PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize:: Merchant Returned Payout Txn ID not found\n"));
ERRLOG("TxnOmtByUsMRP:: Authorize:: Merchant Returned Payout Txn ID not found\n");
        	}
	}

/* merchant payout txn id */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "org_txn_seq", &csOPATxnId)) {
DEBUGLOG(("Authroize:: Merchant Payout Txn ID = [%s]\n", csOPATxnId));
        	        //PutField_CString(hContext, "org_txn_seq", csOPATxnId);
		} else {
               		iRet = INT_TXN_ID_MISSING;
                	PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize:: Merchant Payout Txn ID not found\n"));
ERRLOG("TxnOmtByUsMRP:: Authorize:: Merchant Payout Txn ID not found\n");
        	}
	}

/* return merchant fee */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "return_mfee", &csTmp)) {
        	        iReturnFee = atoi(csTmp);
        	        //PutField_Int(hRequest, "return_mfee", iReturnFee);
DEBUGLOG(("Authorize:: return merchant fee = [%d]\n", iReturnFee));
        	}
	}

/* remark */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("Authorize:: remark = [%s]\n", csRemark));
        	}
	}

/* user */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
        	        //PutField_CString(hContext, "update_user", csUser);
        	}
	}
	
	// Call TxnOmtByUsOPR::Authorize()
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call TxnOmtByUsOPR::Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsOPR", "Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call TxnOmtByUsOPR::Authorize() Error\n"));
		}			
	}

	// Update txn_code and sub_state
	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_code", PD_OL_PAYOUT_VOID_MERCHANT);
		PutField_CString(hTxnHeader, "txn_code", PD_OL_PAYOUT_VOID_MERCHANT);
		PutField_CString(hContext, "sub_status", PD_MERCHANT_APPROVED);
		PutField_CString(hTxnHeader, "sub_status", PD_MERCHANT_APPROVED);
DEBUGLOG(("Authorize:: txn_code = [%s]\n", PD_OL_PAYOUT_VOID_MERCHANT));
DEBUGLOG(("Authorize:: sub_status = [%s]\n", PD_MERCHANT_APPROVED));

DEBUGLOG(("Authorize:: Call DBOLTransaction::Update()\n"));
              	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Update");
              	if ((unsigned long)((*DBObjPtr)(hTxnHeader)) != PD_OK) {
                     	iRet = INT_ERR;
DEBUGLOG(("Authorize:: Call DBOLTransaction::Update() Failed\n"));
              	}
	}

	hash_destroy(hTxnHeader);
	FREE_ME(hTxnHeader);

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));
	return iRet;
}

