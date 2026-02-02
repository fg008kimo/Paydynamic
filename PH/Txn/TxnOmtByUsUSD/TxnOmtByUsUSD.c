/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/23              Cody Chan
Amend for API Method 3                             2014/09/02              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsUSD.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOmtByUsUSD(char    cdebug)
{
        cDebug = cdebug;
}

int     UpdateTxnLog(const hash_t* hContext,
			const hash_t* hRequest,
			const hash_t* hResponse);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csOrgTxnSeq;
	char*	csTxnSeq;
	char*	csPtr;
	double	dTmp;
	recordset_t     *rRecordSet;
	hash_t	*hRec;

	int 	iResend = PD_FALSE;


	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
DEBUGLOG(("TxnOmtByUsUSD::Authroize()\n"));


	if (GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("TxnOmtByUsUSD::txn seq  = [%s]\n",csTxnSeq));
	}
	

	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("TxnOmtByUsUSD::from txn seq  = [%s]\n",csOrgTxnSeq));
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);

		PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
	}
	else if (GetField_CString(hRequest,"enc_txn_seq",&csPtr)) {
DEBUGLOG(("TxnOmtByUsUSD::org encrypted txn seq  = [%s]\n",csPtr));
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
		char* csTmpBuf;
		csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
                (BOObjPtr)(csPtr,csTmpBuf);
		csOrgTxnSeq = strdup(csTmpBuf);
DEBUGLOG(("TxnOmtByUsUSD:org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);
		FREE_ME(csTmpBuf);

		PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
	}
	else {
DEBUGLOG(("TxnOmtByUsUSD::org txn seq not found\n"));
		iRet = INT_ORG_TXN_NOT_FOUND;
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","MatchRespTxnReadOnly");
                if((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_TO_PSP)==PD_FOUND){
DEBUGLOG(("TxnOmtByUsUSD::transaction [%s] with status [%c] found\n",csOrgTxnSeq,PD_TO_PSP));
			//iRet = UpdateTxnLog(hContext,hRequest,hResponse);
		}
		else {
DEBUGLOG(("TxnOmtByUsUSD::transaction [%s] with status [%c] not found'\n",csOrgTxnSeq,PD_TO_PSP));
		}
	}

	if (iRet == PD_OK) {
		char*	csBankCode;

		char*	csBankAcctNum;
		recordset_init(rRecordSet,0);	
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
		if ((DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn header found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_Double(hRec,"display_amt",&dTmp)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - display_amt = [%lf]\n",dTmp));
                                        PutField_Double(hResponse,"display_amt",dTmp);
					break;
                                }
				hRec = RecordSet_GetNext(rRecordSet);
                        }
		}
		RecordSet_Destroy(rRecordSet);	

		recordset_init(rRecordSet,0);	
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
		if ((DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn detail found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec,"success_url",&csPtr)) {
DEBUGLOG(("Authorize::success url = [%s]\n",csPtr));
					PutField_CString(hResponse,"redirect_url",csPtr);
				}
			 	if (GetField_CString(hRec,"bank_code",&csBankCode)) {
DEBUGLOG(("Authorize::GetTxnDetail - bank_code = [%s]\n",csBankCode));
                                     PutField_CString(hResponse,"int_bank_code",csBankCode);
                                }
                                if (GetField_CString(hRec,"bank_acct_num",&csBankAcctNum)) {
DEBUGLOG(("Authorize::GetTxnDetail - bank_acct_num = [%s]\n",csBankAcctNum));
                               		PutField_CString(hResponse,"bank_acct_num",csBankAcctNum);
                                }
				if (GetField_CString(hRec,"deposit_ref", &csPtr)) {
DEBUGLOG(("Authorize::GetTxnDetail - deposit_ref = [%s]\n",csPtr));
                               		PutField_CString(hContext,"deposit_ref",csPtr);
                               		PutField_CString(hResponse,"deposit_ref",csPtr);
				}

				hRec = RecordSet_GetNext(rRecordSet);
                        }
		}
		RecordSet_Destroy(rRecordSet);	

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts()\n"));
                        hash_t * hTxn;
                        hTxn  = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(hTxn,0);
                        DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
                        if ((unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum,hTxn) == PD_OK) {
                                if(GetField_CString(hTxn,"owner_name",&csPtr)){
                                        PutField_CString(hResponse,"owner_name",csPtr);
                                }
                                if(GetField_CString(hTxn,"branch_name",&csPtr)){
                                        PutField_CString(hResponse,"branch_name",csPtr);
                                }
                        }
                        FREE_ME(hTxn);
		}

		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","ChkTxnExistsByOrgTxnSeq");
	                if((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_TXN_UPDATE_CUST_REF,PD_COMPLETE)==PD_FOUND){
				iResend = PD_TRUE;
			}
		}

		if (iResend == PD_FALSE) {
			if (GetField_CString(hRequest,"deposit_ref",&csPtr)) {
DEBUGLOG(("Authorize:: depoist_ref [%s]\n", csPtr));
				PutField_CString(hResponse,"deposit_ref",csPtr);
			}
		} 
	}

	if (iRet == PD_OK) {
		PutField_Int(hContext, "resent", iResend);
		iRet = UpdateTxnLog(hContext,hRequest,hResponse);
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext,"internal_error",iRet);
	}

	FREE_ME(rRecordSet);
DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}

int     UpdateTxnLog(const hash_t* hContext,
			const hash_t* hRequest,
			const hash_t* hResponse)
{
        int iRet = PD_OK;
        hash_t  *hCon;
        char*   csTmp;
	
	int	iResend;

        hCon = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hCon,0);

/* txn_seq  */
        if (GetField_CString(hContext,"from_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hCon,"txn_seq",csTmp);
        }


/* deposit_ref  */
	if (GetField_Int(hContext, "resent", &iResend)) {
		if (iResend == PD_FALSE) {
        		if (GetField_CString(hRequest,"deposit_ref",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: deposit_ref = [%s]\n",csTmp));
				PutField_CString(hCon,"deposit_ref",csTmp);
			}
        	}
	}


	if (iRet == PD_OK) {
        	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","UpdateDetail");
        	iRet = (unsigned long)(*DBObjPtr)(hCon);
	}

        hash_destroy(hCon);
        FREE_ME(hCon);

        return iRet;
};

