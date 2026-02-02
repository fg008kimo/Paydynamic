/*
PDProTech (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/07/11              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsILG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);

void TxnOmtByUsILG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iDtlRet = PD_OK;

DEBUGLOG(("Authorize::()\n"));

	char	*csTmp;
	char	*csStmtTxnId;
	char	*csBankCode;
	char	*csBankAcctNum;
	unsigned long	lBatchId;

	hash_t *hTmp = NULL;
	recordset_t *rsLogGen = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsLogGen,0);

	hash_t *hStmtDtl = (hash_t*) malloc (sizeof(hash_t));
	hash_t *hBankAcct = (hash_t*) malloc (sizeof(hash_t));

// batchid
	if (GetField_CString(hRequest, "batch_id", &csTmp)) {
		lBatchId = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("Authorize:: batch_id = [%ld]\n", lBatchId));
	} else {
DEBUGLOG(("Authorize:: batch_id not found!!\n"));
ERRLOG("TxnOmtByUsILG: Authorize:: batch_id not found!!\n");
		iRet = INT_BATCH_ID_NOT_FOUND;
	}


	if (iRet == PD_OK) {
//		hash_init(hTmp,0);
		recordset_init(rsLogGen,0);
DEBUGLOG(("Call DBOLBaidInterLogGen:GetDetailByBatchId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLBaidInterLogGen","GetDetailByBatchId");
		iDtlRet = (unsigned long)(*DBObjPtr)(lBatchId,rsLogGen);

		if (iDtlRet == PD_OK) {
			hTmp = RecordSet_GetFirst(rsLogGen);
			while ((hTmp) && (iRet != INT_ERR)) {
				if (GetField_CString(hTmp,"stmt_txn_id",&csStmtTxnId)) {
DEBUGLOG(("  stmt_txn_id = [%s]\n",csStmtTxnId));
				} else {
					iRet = INT_ERR;
					break;
DEBUGLOG(("  stmt_tnx_id NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsILG:: DBOLBaidInterLogGen:GetDetailByBatchId stmt_tnx_id NOT FOUND!!!\n");
				}

				// (1) Check Stmt AmtType = CR
				hash_init(hStmtDtl,0);
				DBObjPtr = CreateObj(DBPtr,"DBOLStatement","GetStmtDtl");
				if ((unsigned long)((*DBObjPtr)(csStmtTxnId,hStmtDtl) == PD_OK)) {
					if (GetField_CString(hStmtDtl,"amt_type",&csTmp)) {
						if (strcmp(csTmp,PD_CR) != 0) {
							iRet = INT_ERR;
DEBUGLOG(("  ERROR!!! DBOLStatement:GetStmtDtl amt_type = [%s]\n",csTmp));
						}
					} else {
						iRet = INT_ERR;
					}

					if (!GetField_CString(hStmtDtl,"int_bank_code",&csBankCode)) {
						iRet = INT_BANK_CODE_NOT_FOUND;
DEBUGLOG(("  ERROR!!! DBOLStatement:GetStmtDtl int_bank_code NOT FOUND\n"));
					}

					if (!GetField_CString(hStmtDtl,"bank_acct_num",&csBankAcctNum)) {
						iRet = INT_BANK_ACCT_NOT_FOUND;
DEBUGLOG(("  ERROR!!! DBOLStatement:GetStmtDtl bank_acct_num NOT FOUND\n"));
					}
				} else {
					iRet = INT_ERR;
				}

				// (2) Check Stmt AcctType = ITM
				hash_init(hBankAcct,0);
				DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
				if ((unsigned long)((*DBObjPtr)(csBankCode,csBankAcctNum,hBankAcct) == PD_OK)) {
					if (GetField_CString(hBankAcct,"acct_type",&csTmp)) {
						if (strcmp(csTmp,PD_NATURE_INTERMEDIATE) != 0) {
							iRet = INT_ERR;
DEBUGLOG(("  ERROR!!! DBOLBankAccts:GetBankAccts acct_type = [%s]\n",csTmp));
						}
					} else {
						iRet = INT_ERR;
					}
				} else {
					iRet = INT_ERR;
				}
				
				hTmp = RecordSet_GetNext(rsLogGen);
			}
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("TxnOmtByUsILG:: Call DBOLBaidInterLogGen:GetDetailByBatchId FAILED!!, iDtlRet = [%d]\n",iDtlRet));
		}
	}

	FREE_ME(hBankAcct);
	FREE_ME(hStmtDtl);
	FREE_ME(rsLogGen);


	// Call system job to run log gen in background
	if (iRet == PD_OK) {
		char *csCmd= (char*) malloc (PD_MAX_FILE_LEN  +1);
		sprintf(csCmd,"ol_bal_trf_in_inter_log_gen.sh %ld &",lBatchId);
DEBUGLOG(("TxnOmtByUsILG:: Call system job to run log gen in background\n"));
		system(csCmd);
		FREE_ME(csCmd);
	}


DEBUGLOG(("TxnOmtByUsILG Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
