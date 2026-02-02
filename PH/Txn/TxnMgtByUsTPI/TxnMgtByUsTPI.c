/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/15              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTPI.h"
#include "myrecordset.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsTPI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	char*	csEncTxnSeq;
	char*	csPtr;
	double	dTmp;
	recordset_t     *rRecordSet;   
	hash_t	*hRec;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
DEBUGLOG(("Authorize()\n"));
	memset(csTxnSeq,0,PD_TXN_SEQ_LEN);

	if (GetField_CString(hRequest,"enc_txn_seq",&csEncTxnSeq)) {
DEBUGLOG(("Authorize() enc_txn_seq = [%s]\n",csEncTxnSeq));
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
                (BOObjPtr)(csEncTxnSeq,csTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
		PutField_CString(hContext,"org_txn_seq",csTxnSeq);
	}
	else {
		iRet = INT_ENC_TXN_ID_MISSING;
DEBUGLOG(("Authorize() enc_txn_seq is missing\n"));
ERRLOG("TxnMgtByUsTPI::Authorize() enc_txn_seq is missing\n");
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn");
                if ((unsigned long)(DBObjPtr)(csTxnSeq,PD_TO_PSP) != PD_FOUND) {
	        	iRet = INT_TXN_ID_NOT_FOUND;    
DEBUGLOG(("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_TO_PSP));
ERRLOG("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_TO_PSP);
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	 if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn psp detail found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_CString(hRec,"pay_center_number",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - pay_center_number = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"pay_center_number",csPtr);
                                 }
                                 if (GetField_CString(hRec,"customer_number",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - customer_number = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"customer_number",csPtr);
                                 }
                                 if (GetField_CString(hRec,"conf_number",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - conf_number = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"conf_number",csPtr);
                                 }
                                 if (GetField_CString(hRec,"store_id",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - store_id = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"store_id",csPtr);
                                 }
                                 if (GetField_CString(hRec,"receipt_number",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnPspDetail - receipt_number = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"receipt_number",csPtr);
                                 }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        }

        RecordSet_Destroy(rRecordSet);

	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("Authorize::GetTxnHeader - txn_amt = [%lf]\n",dTmp));
                                        PutField_Double(hResponse,"txn_amt",dTmp);
                                 }


                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        }
        RecordSet_Destroy(rRecordSet);
DEBUGLOG(("Authorize() normal exit = [%d]\n",iRet));
	return iRet;
}
