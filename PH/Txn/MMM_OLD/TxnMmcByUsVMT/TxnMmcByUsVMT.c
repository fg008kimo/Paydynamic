/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/12              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsVMT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsVMT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTxnSeq = NULL;
	char	*csDtlTxnSeq = NULL;

	char	csMaxDtlTxnSeq[PD_MMS_TXN_SEQ_LEN + 1];

	char	*csTmpTxnSeq = NULL;
	char	*csTmpDtlTxnSeq = NULL;

	char	*csTmp;
	char	cTmp;

	hash_t  *hTxn;
	hash_t  *hRec, *hDtlRec;
	recordset_t     *rRecordSet;
	recordset_t	*rDtlRecordSet;

	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("TxnMmcByUsVMT: Authorize()\n"));

	if(GetField_CString(hRequest,"txn_seq",&csTxnSeq)){
DEBUGLOG(("TxnMmcByUsVMT: txn_seq = [%s]\n",csTxnSeq));
	}
	else {
DEBUGLOG(("TxnMmcByUsVMT: txn_seq is missing!!!\n"));
ERRLOG("TxnMmcByUsVMT: txn_seq is missing!!!\n");
		iRet = INT_TXN_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"dtl_txn_seq",&csDtlTxnSeq)){
DEBUGLOG(("TxnMmcByUsVMT: dtl_txn_seq = [%s]\n",csDtlTxnSeq));
	}
	else {
DEBUGLOG(("TxnMmcByUsVMT: dtl_txn_seq is missing!!!\n"));
ERRLOG("TxnMmcByUsVMT: dtl_txn_seq is missing!!!\n");
		iRet = INT_TXN_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
		PutField_CString(hTxn,"txn_seq",csTmp);
DEBUGLOG(("TxnMmcByUsVMT: txn_seq = [%s]\n",csTmp));
	}	

	if(GetField_CString(hRequest,"update_user",&csTmp)){
		PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("TxnMmcByUsVMT: update_user = [%s]\n",csTmp));
	}


	// 
	// Validate input mms_txn 
	// 

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMmsTxnDetail\n"));

		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetail");
		if ((unsigned long)((*DBObjPtr)(csTxnSeq, csDtlTxnSeq, rRecordSet)) != PD_OK) {

DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMmsTxnDetail fail\n"));
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetMmsTxnDetail: status [%c]\n",cTmp));
					if (cTmp != PD_MMC_PENDING) {
						iRet = INT_INVALID_TXN;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("GetMmsTxnDetail: unexpected status [%c] for manual void\n",cTmp));
						break;
					}
				}			

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		memset(csMaxDtlTxnSeq, 0, sizeof(csMaxDtlTxnSeq));

DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMaxDetailSeq\n"));
                DBObjPtr = CreateObj(DBPtr,"DBMmsMBDetail","GetMaxDetailSeq");
		if ((unsigned long)((*DBObjPtr)(csTxnSeq, &csMaxDtlTxnSeq)) != FOUND) {
DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMaxDetailSeq fail\n"));
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else {
			if (strcmp(csMaxDtlTxnSeq, csDtlTxnSeq)) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("GetMmsTxnDetail: not the latest mms_txn for manual void\n"));
			}
		}
	}

	if (iRet == PD_OK) {
		RecordSet_Destroy(rRecordSet);
        	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize:: call DBMmsRelatedTxn:GetNextId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsRelatedTxn","GetNextId");
		if ((unsigned long)((*DBObjPtr)(csTxnSeq,csDtlTxnSeq,rRecordSet)) == PD_FOUND) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {

				csTmpTxnSeq = NULL;
				csTmpDtlTxnSeq = NULL;

				if (GetField_CString(hRec, "txn_seq", &csTmpTxnSeq)) {
DEBUGLOG(("Authorize:: call DBMmsRelatedTxn:GetNextId txn_seq = [%s]\n", csTmpTxnSeq));
				}

				if (GetField_CString(hRec, "dtl_txn_seq", &csTmpDtlTxnSeq)) {
DEBUGLOG(("Authorize:: call DBMmsRelatedTxn:GetNextId dtl_txn_seq = [%s]\n", csTmpDtlTxnSeq));
				}

				RecordSet_Destroy(rDtlRecordSet);
				rDtlRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
				recordset_init(rDtlRecordSet,0);

DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMmsTxnDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetail");
				if ((unsigned long)((*DBObjPtr)(csTmpTxnSeq, csTmpDtlTxnSeq, rDtlRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize:: call DBMmsTransaction:GetMmsTxnDetail fail\n"));
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
				}
				else {
					hDtlRec = RecordSet_GetFirst(rDtlRecordSet);
					while (hDtlRec) {
						if (GetField_Char(hDtlRec, "status", &cTmp)) {
DEBUGLOG(("GetMmsTxnDetail: status [%c]\n",cTmp));
							if (cTmp == PD_MMC_PENDING || cTmp == PD_ACCEPT) {
								iRet = INT_INVALID_TXN;
								PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("GetMmsTxnDetail: unexpected status [%c] for manual void\n",cTmp));
								break;
							}		
						}
						hDtlRec = RecordSet_GetNext(rDtlRecordSet);
					}
				}		
	
				if (iRet != PD_OK) {
					break;
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	} 
	// Complete Validate input mms_txn 

	//
	// Find Need to void records
	//

	if (iRet == PD_OK) {
		
	}

/*********************************************************************/


	FREE_ME(hTxn);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	RecordSet_Destroy(rDtlRecordSet);
	FREE_ME(rDtlRecordSet);

DEBUGLOG(("TxnMmcByUsVMT:  Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int ProcessBackwardVoid(char *csTxnSeq, char *csDtlTxnSeq, hash_t *hTxn)
{
	int 	iRet = PD_OK;
	char	cTmp;
	char	*csTmp= NULL;
	char	*csPrevDtlTxnSeq = NULL;
	char	*csVoidDtlTxnSeq = NULL;

	hash_t 	*hVoidLog;

	hVoidLog = (hash_t*) malloc(sizeof(hash_t));	
	hash_init(hVoidLog, 0);	

	hash_t          *hRec;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("ProcessBackwardVoid:: call DBMmsTransaction:GetMmsTxnDetail\n"));

	if (GetField_CString(hTxn, "txn_seq", &csTmp)) {
		PutField_CString(hVoidLog, "txn_seq", csTmp);
	}

	if (GetField_CString(hTxn,"update_user",&csTmp)) {
		PutField_CString(hVoidLog, "update_user", csTmp);
	}


	DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetail");
	if ((unsigned long)((*DBObjPtr)(csTxnSeq, csDtlTxnSeq, rRecordSet)) != PD_OK) {

DEBUGLOG(("ProcessBackwardVoid:: call DBMmsTransaction:GetMmsTxnDetail fail\n"));
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
	else {
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetMmsTxnDetail: status [%c]\n",cTmp));
				if (cTmp != PD_MMC_PENDING && cTmp != PD_ACCEPT) {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("GetMmsTxnDetail: unexpected status [%c] for manual void\n",cTmp));
					break;
				}
			}			

			if (GetField_CString(hRec, "prev_dtl_txn_seq", &csTmp)) {
DEBUGLOG(("GetMmsTxnDetail: prev_dtl_txn_seq [%s]\n",csTmp));
				PutField_CString(hVoidLog, "prev_dtl_txn_seq", csTmp);
			}

			hRec = RecordSet_GetNext(rRecordSet);
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hVoidLog, "prev_dtl_txn_seq", &csPrevDtlTxnSeq)) {

			RecordSet_Destroy(rRecordSet);
		        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
		        recordset_init(rRecordSet,0);

DEBUGLOG(("ProcessBackwardVoid:: call DBMmsTransaction:GetMmsTxnDetailByPrevId\n"));

			DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetailByPrevId");
			if ((unsigned long)((*DBObjPtr)(csTxnSeq, csPrevDtlTxnSeq, rRecordSet)) != PD_OK) {
DEBUGLOG(("ProcessBackwardVoid:: call DBMmsTransaction:GetMmsTxnDetailByPrevId fail\n"));
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
			else {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {

					PutField_CString(hVoidLog, "void_txn_seq", csTxnSeq);

					if (GetField_CString(hRec, "dtl_txn_seq", &csVoidDtlTxnSeq)) {
DEBUGLOG(("GetMmsTxnDetailByPrevId: csReverseDtlTxnSeq [%s]\n", csVoidDtlTxnSeq));
						PutField_CString(hVoidLog, "void_dtl_txn_seq", csVoidDtlTxnSeq);
					}

					if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetMmsTxnDetailByPrevId: status [%c]\n", cTmp));
						if (cTmp == PD_MMC_PENDING || cTmp == PD_ACCEPT) {
DEBUGLOG(("ProcessBackwardVoid:: call DBMmsManualVoidTxn:Add\n"));
							DBObjPtr = CreateObj(DBPtr,"DBMmsManualVoidTxn","Add");
							if ((unsigned long)((*DBObjPtr)(hVoidLog)) != PD_OK) {
DEBUGLOG(("ProcessBackwardVoid:: call DBMmsManualVoidTxn:Add fail\n"));
								iRet = INT_ERR;
								PutField_Int(hContext, "internal_error", iRet);
							} 
							else {
								ProcessForwardVoid(csTxnSeq, csPrevDtlTxnSeq, hTxn);
							}

					
						}					
					}

					
					hRec = RecordSet_GetNext(rRecordSet);
				}

			
			}
			
		} 
		else {
		}	
	}

	hash_destroy(hVoidLog);
	FREE_ME(hVoidLog);	

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
	
}



