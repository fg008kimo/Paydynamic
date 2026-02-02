/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/09/21              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsDPT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;

OBJPTR(DB);
OBJPTR(BO);
void TxnMgtByUsDPT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csOrgTxnSeq = NULL;
	char*	csPspId = NULL;
	char*	csPspChannelCode = NULL;
	char	cArInd = 'X';
	char	cStatus = 'X';
	int	iTraceOn = PD_FALSE;
	char    csCmd[PD_TMP_BUF_LEN*2 + 1];
	int	iSeq = 0;
	char	*csPtr;
	char	cParty = PD_TYPE_ADMIN;

	hash_t  *hRec;
	hash_t  *hTmp;
	hTmp = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTmp,0);
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	

DEBUGLOG(("TxnMgtByUsDPT Authorize()\n"));


	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("org_txn_seq = [%s]\n",csOrgTxnSeq));
	}
	else{
		iRet = INT_TXN_ID_MISSING;
DEBUGLOG(("txn_id is missing !!!!\n"));
	}

	if (GetField_CString(hRequest,"seq",&csPtr)) {
		iSeq = atoi(csPtr);
DEBUGLOG(("seq = [%d]\n", iSeq));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("seq is missing !!!!\n"));
	}

	if (GetField_CString(hRequest,"party_type",&csPtr)) {
		cParty = csPtr[0];
DEBUGLOG(("party_type = [%c]\n", cParty));
	}


	//GetTxnHeader
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG((" TxnHeader found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

                                if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("status = [%c]\n",cStatus));
                                }
                                if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("ar_ind = [%c]\n",cArInd));
                                }

				if(cStatus != PD_TO_PSP){
					iRet = INT_INVALID_TXN;
DEBUGLOG(("transaction status invalid!\n"));
				}

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
                        iRet = INT_INVALID_TXN;
DEBUGLOG(("not found record for [%s]\n",csOrgTxnSeq));
                }
                RecordSet_Destroy(rRecordSet);
	}

	//Get TxnPspDetail
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		if ((*DBObjPtr)(csOrgTxnSeq,  rRecordSet) == PD_OK) {
DEBUGLOG((" TxnHeader found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec, "psp_id", &csPspId)) {
DEBUGLOG(("psp_id = [%s]\n", csPspId));
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}

		}
		else{
			iRet = INT_ERR;
		}
	}


	//Get psp Channel Code
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
		if ((*DBObjPtr)(csPspId, hTmp) == PD_OK) {
			if (GetField_CString(hTmp, "psp_channel_code", &csPspChannelCode)) {
DEBUGLOG(("psp_channel_code = [%s]\n", csPspChannelCode));
			}
		}
		else{
			iRet = INT_ERR;
		}
	}


	//check config
	if (iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBPspDepositTrace","IsTraceOn");
		iTraceOn = (unsigned long)(*DBObjPtr)(csPspChannelCode);

		if(iTraceOn == PD_TRUE){
DEBUGLOG((" deposit trace is ON\n"));
		}
		else if(iTraceOn == PD_FALSE){
			iRet = INT_DEPOSIT_TRACE_OFF;
DEBUGLOG((" deposit trace is OFF\n"));
		}
		else{
			iRet = INT_ERR;
		}
	}


	if(iRet == PD_OK){
		sprintf(csCmd, "deposit_trace.sh %s %s %s %d %c &", csPspChannelCode, csPspId, csOrgTxnSeq, iSeq, cParty);
		system(csCmd);
	}


	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(hTmp);


DEBUGLOG(("TxnMgtByUsDPT Normal Exit [%d]\n",iRet));
	return iRet;
}
