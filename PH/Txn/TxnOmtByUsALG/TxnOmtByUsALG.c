/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/08/24              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsALG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsALG(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char		*csTmp = NULL;
	char		*csUser = NULL;
	int		iCnt = 0;
	int		iProcessCnt = 0;
	int		iDtlRet = PD_ERR;
	int		iRet = PD_OK;
	unsigned long	lBatchId;
	hash_t		*hRec = NULL;
	recordset_t	*rRecordSet;

	rRecordSet = (recordset_t*)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("TxnOmtByUsALG::Authorize\n"));

	/* user */
	if (GetField_CString(hContext, "add_user", &csUser))
	{
DEBUGLOG(("- add_user = [%s]\n", csUser));
	}
	else
	{
DEBUGLOG(("- add_user not found!!\n"));
ERRLOG("TxnOmtByUsALG::Authorize:: add_user not found!!\n");

		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	/* batch_id */
	if (GetField_CString(hRequest, "batch_id", &csTmp))
	{
		lBatchId = (unsigned long)ctol((const unsigned char*)csTmp, strlen(csTmp));
DEBUGLOG(("- batch_id = [%lu]\n", lBatchId));
	}
	else
	{
DEBUGLOG(("- batch_id not found!!\n"));
ERRLOG("TxnOmtByUsALG::Authorize:: batch_id not found!!\n");

		iRet = INT_BATCH_ID_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// Get Records From BAID Intra Log Generate
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBOLBaidIntraLogGen::GetDetailByBatchId\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBaidIntraLogGen", "GetDetailByBatchId");
		iDtlRet = (unsigned long)(DBObjPtr)(lBatchId, rRecordSet);

DEBUGLOG(("- DBOLBaidIntraLogGen::GetDetailByBatchId iRet = [%d]\n", iDtlRet));

		if (iDtlRet == PD_FOUND)
		{
DEBUGLOG(("- Calling DBOLBaidIntraLogGen::GetDetailByBatchId Found!!\n"));

			// Loop BAID Intra Log Generate Records
			hRec = RecordSet_GetFirst(rRecordSet);

			while (hRec && iRet == PD_OK)
			{
				char	cStatus;
				char	*csBankAcctNum = NULL;
				char	*csBankCode = NULL;
				char	*csStmtTxnId = NULL;
				char	*csTmp = NULL;
				int	iSkip = PD_FALSE;
				hash_t	*hBankAccts;
				hash_t	*hStmtDetail;

				hBankAccts = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hBankAccts, 0);

				hStmtDetail = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hStmtDetail, 0);

				/* stmt_txn_id */
				if (GetField_CString(hRec, "stmt_txn_id", &csStmtTxnId))
				{
DEBUGLOG(("- [%d] stmt_txn_id = [%s]\n", iCnt, csStmtTxnId));
				}
				else
				{
DEBUGLOG(("- [%d] stmt_txn_id not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBaidIntraLogGen::GetDetailByBatchId stmt_txn_id not found!!\n");

					iRet = INT_TXN_ID_NOT_FOUND;
					PutField_Int(hContext, "internal_error", iRet);
				}

				/* status */
				if (iRet == PD_OK)
				{
					if (GetField_Char(hRec, "status", &cStatus))
					{
DEBUGLOG(("- [%d] status = [%c]\n", iCnt, cStatus));

						if (cStatus != PD_PROCESSING)
						{
DEBUGLOG(("- [%d] Skipped!! Status is not processing!!\n", iCnt));
							iSkip = PD_TRUE;
						}
					}
					else
					{
DEBUGLOG(("- [%d] status not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBaidIntraLogGen::GetDetailByBatchId status not found!!\n");

						iRet = INT_STATUS_NOT_FOUND;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}

				// Check Bank Statement Amount Type And Get Internal Bank Code And Bank Account Number
				if (iRet == PD_OK && !iSkip)
				{
DEBUGLOG(("- [%d] Calling DBOLStatement::GetStmtDtl\n", iCnt));
					DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "GetStmtDtl");

					if ((unsigned long)((DBObjPtr)(csStmtTxnId, hStmtDetail) == PD_OK))
					{
						/* amt_type */
						if (GetField_CString(hStmtDetail, "amt_type", &csTmp))
						{
DEBUGLOG(("- [%d] amt_type = [%s]\n", iCnt, csTmp));

							if (strcmp(csTmp, PD_CR) && strcmp(csTmp, PD_DR))
							{
DEBUGLOG(("- [%d] Error!! Calling DBOLStatement::GetStmtDtl amt_type is not expected value!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLStatement::GetStmtDtl amt_type is not expected value!!\n");

								iRet = INT_ERR;
								PutField_Int(hContext, "internal_error", iRet);
							}
						}
						else
						{
DEBUGLOG(("- [%d] amt_type not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLStatement::GetStmtDtl amt_type not found!!\n");

							iRet = INT_AMT_TYPE_NOT_FOUND;
							PutField_Int(hContext, "internal_error", iRet);
						}

						/* int_bank_code */
						if (iRet == PD_OK)
						{
							if (GetField_CString(hStmtDetail, "int_bank_code", &csBankCode))
							{
DEBUGLOG(("- [%d] int_bank_code = [%s]\n", iCnt, csBankCode));
							}
							else
							{
DEBUGLOG(("- [%d] int_bank_code not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLStatement::GetStmtDtl int_bank_code not found!!\n");

								iRet = INT_BANK_CODE_NOT_FOUND;
								PutField_Int(hContext, "internal_error", iRet);
							}
						}

						/* bank_acct_num */
						if (iRet == PD_OK)
						{
							if (GetField_CString(hStmtDetail, "bank_acct_num", &csBankAcctNum))
							{
DEBUGLOG(("- [%d] bank_acct_num = [%s]\n", iCnt, csBankAcctNum));
							}
							else
							{
DEBUGLOG(("- [%d] bank_acct_num not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLStatement::GetStmtDtl bank_acct_num not found!!\n");

								iRet = INT_BANK_ACCT_NOT_FOUND;
								PutField_Int(hContext, "internal_error", iRet);
							}
						}
					}
					else
					{
DEBUGLOG(("- [%d] Calling DBOLStatement::GetStmtDtl Error!!\n"));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLStatement::GetStmtDtl Error!!\n");

						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}

				// Check Bank Statement Account Type (Intermediate / Payout)
				if (iRet == PD_OK && !iSkip)
				{
DEBUGLOG(("- [%d] Calling DBOLBankAccts::GetBankAccts\n", iCnt));
					DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "GetBankAccts");

					if ((unsigned long)((DBObjPtr)(csBankCode, csBankAcctNum, hBankAccts) == PD_OK))
					{
						/* acct_type */
						if (GetField_CString(hBankAccts, "acct_type", &csTmp))
						{
DEBUGLOG(("- [%d] acct_type = [%s]\n", iCnt, csTmp));

							if (strcmp(csTmp, PD_NATURE_INTERMEDIATE) && strcmp(csTmp, PD_NATURE_PAYOUT))
							{
DEBUGLOG(("- [%d] Error!! Calling DBOLBankAccts::GetBankAccts acct_type is not expected value!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBankAccts::GetBankAccts acct_type is not expected value!!\n");

								iRet = INT_BANK_ACCT_NATURE_NOT_MATCH;
								PutField_Int(hContext, "internal_error", iRet);
							}
						}
						else
						{
DEBUGLOG(("- [%d] acct_type not found!!\n", iCnt));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBankAccts::GetBankAccts acct_type not found!!\n");

							iRet = INT_ACCT_NATURE_NOT_FOUND;
							PutField_Int(hContext, "internal_error", iRet);
						}
					}
					else
					{
DEBUGLOG(("- [%d] Calling DBOLBankAccts::GetBankAccts Error!!\n"));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBankAccts::GetBankAccts Error!!\n");

						iRet = INT_ERR;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}

				// Calculate Counts Which Need To Run BAID Intra Log Generate In Background
				if (iRet == PD_OK && !iSkip)
					iProcessCnt++;

				iCnt++;

				hash_destroy(hBankAccts);
				FREE_ME(hBankAccts);

				hash_destroy(hStmtDetail);
				FREE_ME(hStmtDetail);

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else if (iDtlRet == PD_NOT_FOUND)
		{
DEBUGLOG(("- Calling DBOLBaidIntraLogGen::GetDetailByBatchId Not Found!!\n"));

			iRet = INT_RECORD_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else
		{
DEBUGLOG(("- Calling DBOLBaidIntraLogGen::GetDetailByBatchId Error!!\n"));
ERRLOG("TxnOmtByUsALG::Authorize:: Calling DBOLBaidIntraLogGen::GetDetailByBatchId Error!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Call System Job To Run BAID Intra Log Generate In Background
	if (iRet == PD_OK && iProcessCnt)
	{
		char *csCmd = (char*)malloc(PD_TMP_BUF_LEN + 1);

		sprintf(csCmd, "ol_bal_trf_in_intra_log_gen.sh %lu &", lBatchId);

DEBUGLOG(("TxnOmtByUsALG::Authorize:: Calling System Job To Run BAID Intra Log Generate [%d] Records In Background!!\n", iProcessCnt));
		system(csCmd);

		FREE_ME(csCmd);
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsALG Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
