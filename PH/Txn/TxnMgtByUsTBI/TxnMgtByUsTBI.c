/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/04/06              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTBI.h"
#include "myrecordset.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Msg);

void TxnMgtByUsTBI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	//char    csOrgDateTime[PD_DATETIME_LEN +1];
	char*	csEncTxnSeq;
	//char	*csPayMethod;
	//char	*csTxnCcy;
	//char	*csOrgTxnCountry;
	//char	*csOrgChannelCode;
	//char	*csOrgServiceCode;
	char	*csOrgMerchantId;
	char	*csSubStatus;
	//char	*csSelectedPID = NULL;
	char*	csPtr;
	char*	csIpAddr;
	char*	csUserAgent;
	//double	dTmp;
	//double	dTxnAmt;
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
ERRLOG("TxnMgtByUsTBI::Authorize() enc_txn_seq is missing\n");
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (iRet == PD_OK){
		if (GetField_CString(hRequest,"ip_addr",&csIpAddr)) {
DEBUGLOG(("Authorize() ip_addr = [%s]\n",csIpAddr));
		}
		if (GetField_CString(hRequest,"user_agent",&csUserAgent)) {
DEBUGLOG(("Authorize() user_agent = [%s]\n",csUserAgent));
		}
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn_ReadOnly");
                if ((unsigned long)(DBObjPtr)(csTxnSeq,PD_INIT) != PD_FOUND) {
	        	iRet = INT_TXN_ID_NOT_FOUND;    
DEBUGLOG(("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_INIT));
//ERRLOG("Authorize() org txn id record [%s] not found for status = [%c]\n",csTxnSeq,PD_INIT);
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
			int iRange = PD_DEF_TXN_EXPIRE_TIME;
			int iTmpRet = PD_FALSE;
			char*   csValueTmp;
			csValueTmp = (char*) malloc (10);
			DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
			if ((unsigned long)(DBObjPtr)("TXN_EXPIRE_TIME",csValueTmp) == FOUND) {
				if(is_numeric(csValueTmp)){
					iRange = atoi(csValueTmp);
				}
			}
DEBUGLOG(("Authorize::Transaction Expire Time (min) = [%d]\n",iRange));
			FREE_ME(csValueTmp);

			DBObjPtr = CreateObj(DBPtr,"DBTransaction","IsCreateTimeWithinRange");
			iTmpRet = (unsigned long)(DBObjPtr)(csTxnSeq,iRange);
			if(iTmpRet==PD_TRUE){
DEBUGLOG(("Authorize::Transaction not yet expired\n"));
			}
			else if(iTmpRet==PD_FALSE){
				iRet = INT_TXN_EXPIRED;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::Transaction is expired!!!!\n"));
			}
			else{
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBTransaction::IsCreateTimeWithinRange Error!!!!\n"));
			}
                }
	}
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_CString(hRec,"merchant_id",&csOrgMerchantId)) {
DEBUGLOG(("Authorize::GetTxnHeader - merchant_id = [%s]\n",csOrgMerchantId));
                                 }
                                 if (GetField_CString(hRec,"merchant_ref",&csPtr)) {
				 }
				 if (GetField_CString(hRec,"sub_status",&csSubStatus)) {
DEBUGLOG(("Authorize::GetTxnHeader - sub_status = [%s]\n",csSubStatus));
                                 }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        	RecordSet_Destroy(rRecordSet);
        }
/***** ***/
	if(iRet==PD_OK){ //init record found 
		if(!strcmp(csSubStatus,PD_HAND_SHAKEN)){
			hash_t*	hCon;
			hCon = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hCon,0);

			PutField_CString(hCon,"txn_seq",csTxnSeq);
			PutField_CString(hCon,"ip_addr",csIpAddr);
			PutField_CString(hCon,"user_agent",csUserAgent);
			PutField_CString(hCon,"sub_status",PD_INITIATED);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
			if ((DBObjPtr)(hCon) == PD_OK) {
DEBUGLOG(("Authorize() update txn_header sub-status[%s]\n",csTxnSeq));
			}
			FREE_ME(hCon);
		}
DEBUGLOG(("Authorize() transaction is valid[%s]\n",csTxnSeq));
	}
	else{
		PutField_Int(hContext,"internal_error",iRet);
	}

	FREE_ME(rRecordSet);
DEBUGLOG(("Authorize() normal exit = [%d]\n",iRet));
	return iRet;
}
