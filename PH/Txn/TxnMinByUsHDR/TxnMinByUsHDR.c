/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/04/13              [ZBL]
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
#include "TxnMinByUsHDR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMinByUsHDR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char	cHoldType;
	char	csBatchId[PD_TXN_SEQ_LEN + 1];
	char	*csEntityId = NULL;
	char	*csPartyId = NULL;
	char	*csTmp = NULL;
	char	*csTxnSeq = NULL;
	char	*csUser = NULL;
	double	dCIntransit = 0.0;
	double	dOIntransit = 0.0;
	double	dTmp = 0.0;
	double	dTxnAmt = 0.0;
	int	iDtlRet = PD_ERR;
	int	iRet = PD_OK;
	hash_t	*hBatch = NULL;
	hash_t	*hRec = NULL;

	hRec = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hRec, 0);

	hBatch = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBatch, 0);

	memset(csBatchId, 0, PD_TXN_SEQ_LEN + 1);

DEBUGLOG(("TxnMinByUsHDR::Authorize\n"));

	/* txn_seq */
	if (GetField_CString(hContext, "txn_seq", &csTxnSeq))
	{
DEBUGLOG(("- txn_seq = [%s]\n", csTxnSeq));
	}
	else
	{
DEBUGLOG(("- txn_seq not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_seq not found!!\n");

		iRet = INT_INVALID_TXN;
	}

	/* txn_code */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "txn_code", &csTmp))
		{
DEBUGLOG(("- txn_code = [%s]\n", csTmp));
		}
		else
		{
DEBUGLOG(("- txn_code not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_code not found!!\n");

			iRet = INT_INVALID_TXN;
		}
	}

	/* add_user */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "add_user", &csUser))
		{
DEBUGLOG(("- add_user = [%s]\n", csUser));
		}
		else
		{
DEBUGLOG(("- add_user not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() add_user not found!!\n");

			iRet = INT_USER_NOT_FOUND;
		}
	}

	/* hold_type */
	if (iRet == PD_OK)
	{
		if (GetField_Char(hContext, "hold_type", &cHoldType))
		{
DEBUGLOG(("- hold_type = [%c]\n", cHoldType));

			if (cHoldType != PD_HOLD && cHoldType != PD_UNHOLD)
			{
DEBUGLOG(("- Invalid hold_type!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Invalid hold_type!!\n");

				iRet = INT_ERR;
			}
			else
			{
				// Get The New Transaction Code If "hold_type" Is Equal To "Unhold"
				/* new_txn_code */
				if (cHoldType == PD_UNHOLD)
				{
					if (GetField_CString(hContext, "new_txn_code", &csTmp))
					{
DEBUGLOG(("- new_txn_code = [%s]\n", csTmp));
					}
					else
					{
DEBUGLOG(("- new_txn_code not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() new_txn_code not found!!\n");

						iRet = INT_INVALID_TXN;
					}
				}
			}
		}
		else
		{
DEBUGLOG(("- hold_type not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() hold_type not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* entity_id */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "entity_id", &csEntityId))
		{
DEBUGLOG(("- entity_id = [%s]\n", csEntityId));
		}
		else
		{
DEBUGLOG(("- entity_id not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() entity_id not found!!\n");

			iRet = INT_MI_ENTITY_ID_NOT_FOUND;
		}
	}

	// From RSP Information When Calling TxnMinByUsCOM::Authorize() Before
	/* party_id */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "party_id", &csPartyId))
		{
DEBUGLOG(("- party_id = [%s]\n", csPartyId));
		}
		else
		{
DEBUGLOG(("- party_id not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() party_id not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* txn_ccy */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "txn_ccy", &csTmp))
		{
DEBUGLOG(("- txn_ccy = [%s]\n", csTmp));
		}
		else
		{
DEBUGLOG(("- txn_ccy not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_ccy not found!!\n");

			iRet = INT_CURRENCY_CODE_NOT_FOUND;
		}
	}

	/* txn_country */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "txn_country", &csTmp))
		{
DEBUGLOG(("- txn_country = [%s]\n", csTmp));
		}
		else
		{
DEBUGLOG(("- txn_country not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_country not found!!\n");

			iRet = INT_TXN_COUNTRY_NOT_FOUND;
		}
	}

	/* txn_amt */
	if (iRet == PD_OK)
	{
		if (GetField_Double(hContext, "txn_amt", &dTxnAmt))
		{
DEBUGLOG(("- txn_amt = [%lf]\n", dTxnAmt));
		}
		else
		{
DEBUGLOG(("- txn_amt not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_amt not found!!\n");

			iRet = INT_TXN_AMT_MISSING;
		}
	}

	/* report_date */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "report_date", &csTmp))
		{
DEBUGLOG(("- report_date = [%s]\n", csTmp));
		}
		else
		{
DEBUGLOG(("- report_date not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() report_date not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* remark */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "remark", &csTmp))
		{
DEBUGLOG(("- remark = [%s]\n", csTmp));
		}
	}

	/* txn_date */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "txn_date", &csTmp))
		{
DEBUGLOG(("- txn_date = [%s]\n", csTmp));
		}
		else
		{
DEBUGLOG(("- txn_date not found!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() txn_date not found!!\n");

			iRet = INT_ERR;
		}
	}

	// Check The RSP Balance Account Exist Or Not (It Should Be Existed)
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBMiEntityBalAcct::GetEntityBalAcct()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiEntityBalAcct", "GetEntityBalAcct");
		iDtlRet = (unsigned long)(DBObjPtr)(hContext, hRec);

		if (iDtlRet == PD_FOUND)
		{
			// Check The Status Of RSP Balance Account Is Enabled Or Not (It Should Be Enabled)
			/* status */
			if (GetField_CString(hRec, "status", &csTmp))
			{
DEBUGLOG(("- status (RSP Balance Account) = [%s]\n", csTmp));

				if (strcmp(csTmp, PD_MI_ENTITY_BAL_ACCT_STATUS_OPEN))
				{
DEBUGLOG(("- Invalid status (RSP Balance Account)!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling DBMiEntityBalAcct::GetEntityBalAcct() Invalid status (RSP Balance Account)!!\n");

					iRet = INT_ERR;
				}
			}
		}
		else if (iDtlRet == PD_NOT_FOUND)
		{
DEBUGLOG(("- Calling DBMiEntityBalAcct::GetEntityBalAcct() Not Found!!\n"));

			iRet = INT_ERR;
		}
		else
		{
DEBUGLOG(("- Calling DBMiEntityBalAcct::GetEntityBalAcct() Error!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling DBMiEntityBalAcct::GetEntityBalAcct() Error!!\n");

			iRet = INT_ERR;
		}
	}

	if (iRet != PD_OK)
		PutField_Int(hContext, "internal_error", iRet);

	// Prepare To Update RSP In-Transit Balance
	if (iRet == PD_OK)
	{
		/* batch_mode */
DEBUGLOG(("- batch_mode (RSP In-Transit Balance) = [%c]\n", PD_ONLINE));
		PutField_Char(hContext, "batch_mode", PD_ONLINE);

		/* amt_type */
DEBUGLOG(("- amt_type (RSP In-Transit Balance) = [%s]\n", ((cHoldType == PD_HOLD) ? PD_DR : PD_CR)));
		PutField_CString(hContext, "amt_type", ((cHoldType == PD_HOLD) ? PD_DR : PD_CR));

		/* bal_type */
DEBUGLOG(("- bal_type (RSP In-Transit Balance) = [%c]\n", PD_MI_ENTITY_POOL_INTRANSIT));
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_INTRANSIT);

		// Call Mini MMM Entity Balance Handler To Update RSP In-Transit Balance
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP In-Transit Balance\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMiEntityBalance", "UpdateEntityBalance");
		iDtlRet = (unsigned long)(BOObjPtr)(hContext, hContext);

		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP In-Transit Balance Success!!\n"));

			/* approval_date */
			if (GetField_CString(hContext, "approval_date", &csTmp))
			{
DEBUGLOG(("- approval_date (RSP In-Transit Balance) = [%s]\n", csTmp));
			}

			/* approval_timestamp */
			if (GetField_CString(hContext, "approval_timestamp", &csTmp))
			{
DEBUGLOG(("- approval_timestamp (RSP In-Transit Balance) = [%s]\n", csTmp));
			}

			/* Open Balance */
			if (GetField_Double(hContext, "open_acct_bal", &dTmp))
			{
DEBUGLOG(("- open_acct_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_intransit", &dTmp))
			{
DEBUGLOG(("- open_intransit (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_ar_bal", &dTmp))
			{
DEBUGLOG(("- open_ar_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_lien_bal", &dTmp))
			{
DEBUGLOG(("- open_lien_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			/* Close Balance */
			if (GetField_Double(hContext, "acct_bal", &dTmp))
			{
DEBUGLOG(("- Closing acct_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "intransit", &dTmp))
			{
DEBUGLOG(("- Closing intransit (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "ar_bal", &dTmp))
			{
DEBUGLOG(("- Closing ar_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "lien_bal", &dTmp))
			{
DEBUGLOG(("- Closing lien_bal (RSP In-Transit Balance) = [%lf]\n", dTmp));
			}
		}
		else
		{
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP In-Transit Balance Failure!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling BOMiEntityBalance::UpdateEntityBalance() For RSP In-Transit Balance Failure!!\n");

			iRet = iDtlRet;
		}
	}

	// Prepare To Update RSP Lien Balance
	if (iRet == PD_OK)
	{
		// Store The Open / Closing Balance Of RSP In-Transit Balance Before Updating RSP Lien Balance
		GetField_Double(hContext, "open_intransit", &dOIntransit);
		GetField_Double(hContext, "intransit", &dCIntransit);

		/* batch_mode */
DEBUGLOG(("- batch_mode (RSP Lien Balance) = [%c]\n", PD_ONLINE));
//		PutField_Char(hContext, "batch_mode", PD_ONLINE);

		/* amt_type */
DEBUGLOG(("- amt_type (RSP Lien Balance) = [%s]\n", ((cHoldType == PD_HOLD) ? PD_CR : PD_DR)));
		PutField_CString(hContext, "amt_type", ((cHoldType == PD_HOLD) ? PD_CR : PD_DR));

		/* bal_type */
DEBUGLOG(("- bal_type (RSP Lien Balance) = [%c]\n", PD_MI_ENTITY_POOL_LIEN));
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_LIEN);

		// Call Mini MMM Entity Balance Handler To Update RSP Lien Balance
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP Lien Balance\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMiEntityBalance", "UpdateEntityBalance");
		iDtlRet = (unsigned long)(BOObjPtr)(hContext, hContext);

		if (iDtlRet == PD_OK)
		{
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP Lien Balance Success!!\n"));

			/* approval_date */
			if (GetField_CString(hContext, "approval_date", &csTmp))
			{
DEBUGLOG(("- approval_date (RSP Lien Balance) = [%s]\n", csTmp));
			}

			/* approval_timestamp */
			if (GetField_CString(hContext, "approval_timestamp", &csTmp))
			{
DEBUGLOG(("- approval_timestamp (RSP Lien Balance) = [%s]\n", csTmp));
			}

			/* Open Balance */
			if (GetField_Double(hContext, "open_acct_bal", &dTmp))
			{
DEBUGLOG(("- open_acct_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_intransit", &dTmp))
			{
DEBUGLOG(("- open_intransit (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_ar_bal", &dTmp))
			{
DEBUGLOG(("- open_ar_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "open_lien_bal", &dTmp))
			{
DEBUGLOG(("- open_lien_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			/* Close Balance */
			if (GetField_Double(hContext, "acct_bal", &dTmp))
			{
DEBUGLOG(("- Closing acct_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "intransit", &dTmp))
			{
DEBUGLOG(("- Closing intransit (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "ar_bal", &dTmp))
			{
DEBUGLOG(("- Closing ar_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}

			if (GetField_Double(hContext, "lien_bal", &dTmp))
			{
DEBUGLOG(("- Closing lien_bal (RSP Lien Balance) = [%lf]\n", dTmp));
			}
		}
		else
		{
DEBUGLOG(("- Calling BOMiEntityBalance::UpdateEntityBalance() For RSP Lien Balance Failure!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling BOMiEntityBalance::UpdateEntityBalance() For RSP Lien Balance Failure!!\n");

			iRet = iDtlRet;
		}
	}

	// Add A Mini MMM Transaction Log For RSP Hold / Unhold Transaction Request (RSP In-Transit / Lien Balance)
	if (iRet == PD_OK)
	{
		// Add Open / Closing Balance For RSP In-Transit / Lien Balance
		// Restore The Open / Closing Balance Of RSP In-Transit Balance To Context Hash After Updating RSP Lien Balance
		/* open_intransit / intransit */
		PutField_Double(hContext, "open_intransit", dOIntransit);
		PutField_Double(hContext, "intransit", dCIntransit);

		/* party_type / actual_cost / acr_prorata */
		PutField_CString(hContext, "party_type", PD_MI_ENTITY_RSP);
		PutField_Double(hContext, "actual_cost", 0);
		PutField_Int(hContext, "acr_prorata", PD_FALSE);

DEBUGLOG(("- Calling DBTxnMiDetail::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnMiDetail", "Add");

		if ((unsigned long)(DBObjPtr)(hContext, hContext) != PD_OK)
		{
DEBUGLOG(("- Calling DBTxnMiDetail::Add() Failed!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling DBTxnMiDetail::Add() Failed!!\n");

			iRet = INT_ERR;
		}
	}

	// Get The New Mini MMM Action Batch Sequence To Add A Mini MMM Batch Header Log For RSP Hold / Unhold Transaction Request
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBTxnSeq::GetNextMiActionBatchSeq()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnSeq", "GetNextMiActionBatchSeq");
		strcpy(csBatchId, (DBObjPtr)());

DEBUGLOG(("- Mini MMM Action Batch Sequence = [%s]\n", csBatchId));

		/* batch_id / process_type / status / add_user */
		PutField_CString(hBatch, "batch_id", csBatchId);
		PutField_CString(hBatch, "process_type", ((cHoldType == PD_HOLD) ? PD_MI_TXN_TYPE_RSP_HOLD : PD_MI_TXN_TYPE_RSP_UNHOLD));
		PutField_Char(hBatch, "status", PD_MI_BATCH_STATUS_NORMAL);
		PutField_CString(hBatch, "add_user", csUser);

DEBUGLOG(("- Calling DBMiBatchHeader::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchHeader", "Add");

		if ((unsigned long)(DBObjPtr)(hBatch) != PD_OK)
		{
DEBUGLOG(("- Calling DBMiBatchHeader::Add() Failed!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling DBMiBatchHeader::Add() Failed!!\n");

			iRet = INT_ERR;
		}
	}

	// Add A Mini MMM Batch Detail Log RSP Hold / Unhold Transaction Request
	if (iRet == PD_OK)
	{
		int iSeq = 1;

		/* seq / entity_id / party_type / party_id / txn_id / txn_oper_ind */
		PutField_Int(hBatch, "seq", iSeq);
		PutField_CString(hBatch, "entity_id", csEntityId);
		PutField_CString(hBatch, "party_type", PD_MI_ENTITY_RSP);
		PutField_CString(hBatch, "party_id", csPartyId);
		PutField_CString(hBatch, "txn_id", csTxnSeq);
		PutField_Char(hBatch, "txn_oper_ind", PD_MI_BATCH_TXN_OPER_INSERT);

DEBUGLOG(("- Calling DBMiBatchDetail::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");

		if ((unsigned long)(DBObjPtr)(hBatch) != PD_OK)
		{
DEBUGLOG(("- Calling DBMiBatchDetail::Add() Failed!!\n"));
ERRLOG("TxnMinByUsHDR::Authorize() Calling DBMiBatchDetail::Add() Failed!!\n");

			iRet = INT_ERR;
		}
	}

	// Prepare To Setup The Information For RSP Hold / Unhold Transaction Request
	if (iRet == PD_OK)
	{
		/* ex_party / ex_rate / sub_status */
		PutField_Char(hContext, "ex_party", PD_INT_EX);
		PutField_Double(hContext, "ex_rate", 1);
		PutField_CString(hContext, "sub_status", PD_APPROVED);
	}

	hash_destroy(hBatch);
	FREE_ME(hBatch);

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("TxnMinByUsHDR Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
