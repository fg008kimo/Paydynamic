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
#include "TxnMgtByUsHDR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsHDR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char	cHoldType;
	char	*csEntityId = NULL;
	char	*csTmp = NULL;
	double	dTxnAmt = 0.0;
	int	iDtlRet = PD_ERR;
	int	iRet = PD_OK;
	hash_t	*hRec = NULL;
	hash_t	*hRSPBalAcct = NULL;

//	hRec = (hash_t*)malloc(sizeof(hash_t));
//	hash_init(hRec, 0);

	hRSPBalAcct = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hRSPBalAcct, 0);

DEBUGLOG(("TxnMgtByUsHDR::Authorize\n"));

	/* txn_seq */
	if (GetField_CString(hContext, "txn_seq", &csTmp))
	{
DEBUGLOG(("- txn_seq = [%s]\n", csTmp));
		PutField_CString(hResponse, "org_txn_seq", csTmp);
	}
	else
	{
DEBUGLOG(("- txn_seq not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_seq not found!!\n");

		iRet = INT_INVALID_TXN;
	}

	/* add_user */
	if (GetField_CString(hContext, "add_user", &csTmp))
	{
DEBUGLOG(("- add_user = [%s]\n", csTmp));
		PutField_CString(hContext, "update_user", csTmp);
	}
	else
	{
DEBUGLOG(("- add_user not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() add_user not found!!\n");

		iRet = INT_USER_NOT_FOUND;
	}

	/* hold_type */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "hold_type", &csTmp))
		{
			cHoldType = csTmp[0];
DEBUGLOG(("- hold_type = [%c]\n", cHoldType));

			if (cHoldType != PD_HOLD && cHoldType != PD_UNHOLD)
			{
DEBUGLOG(("- Invalid hold_type!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Invalid hold_type!!\n");

				iRet = INT_ERR;
			}
			else
			{
				PutField_Char(hContext, "hold_type", cHoldType);
				// For Mini MMM Transaction Handler To Process Money Movement - TxnMgtByUs2MiniMMM::Authorize()
				PutField_CString(hContext, "mini_txn_type", (cHoldType == PD_HOLD) ? PD_MI_TXN_TYPE_RSP_HOLD : PD_MI_TXN_TYPE_RSP_UNHOLD);

				// Replace The Transaction Code To "Release Lien For RSP" If "hold_type" Is Equal To "Unhold"
				if (cHoldType == PD_UNHOLD)
					PutField_CString(hContext, "new_txn_code", PD_UNHOLD_BALANCE_RSP);
			}
		}
		else
		{
DEBUGLOG(("- hold_type not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() hold_type not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* entity_id */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "entity_id", &csEntityId))
		{
DEBUGLOG(("- entity_id = [%s]\n", csEntityId));

			PutField_CString(hContext, "entity_id", csEntityId);
			PutField_CString(hRSPBalAcct, "entity_id", csEntityId);
		}
		else
		{
DEBUGLOG(("- entity_id not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() entity_id not found!!\n");

			iRet = INT_MI_ENTITY_ID_NOT_FOUND;
		}
	}

	/* txn_ccy */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "txn_ccy", &csTmp))
		{
DEBUGLOG(("- txn_ccy = [%s]\n", csTmp));

			PutField_CString(hContext, "ccy", csTmp);
			PutField_CString(hContext, "entity_ccy", csTmp);
			PutField_CString(hContext, "net_ccy", csTmp);
			PutField_CString(hContext, "txn_ccy", csTmp);
			PutField_CString(hRSPBalAcct, "ccy", csTmp);
		}
		else
		{
DEBUGLOG(("- txn_ccy not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_ccy not found!!\n");

			iRet = INT_CURRENCY_CODE_NOT_FOUND;
		}
	}

	/* txn_country */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "txn_country", &csTmp))
		{
DEBUGLOG(("- txn_country = [%s]\n", csTmp));

			PutField_CString(hContext, "country", csTmp);
			PutField_CString(hContext, "txn_country", csTmp);
			PutField_CString(hRSPBalAcct, "country", csTmp);
		}
		else
		{
DEBUGLOG(("- txn_country not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_country not found!!\n");

			iRet = INT_TXN_COUNTRY_NOT_FOUND;
		}
	}

	/* txn_amt */
	if (iRet == PD_OK)
	{
		if (GetField_Double(hContext, "txn_amt", &dTxnAmt))
		{
DEBUGLOG(("- txn_amt = [%lf]\n", dTxnAmt));

			if (dTxnAmt <= 0.0)
			{
DEBUGLOG(("- txn_amt is not allowed to hold / unhold the zero or negative amount!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_amt is not allowed to hold / unhold the zero or negative amount!!\n");

				iRet = INT_ERR;
			}
			else
			{
				// For Mini MMM Transaction Detail Log - DBTxnMiDetail::Add()
				PutField_Double(hContext, "entity_txn_amount", dTxnAmt);
				PutField_Double(hContext, "net_amt", dTxnAmt);
			}
		}
		else
		{
DEBUGLOG(("- txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_amt not found!!\n");

			iRet = INT_TXN_AMT_MISSING;
		}
	}

	/* product_code */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "product_code", &csTmp))
		{
DEBUGLOG(("- product_code = [%s]\n", csTmp));

			// Check The CRR Product Code Exist Or Not (It Should Be Existed)
DEBUGLOG(("- Calling DefProduct::FindProduct()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBDefProduct", "FindProduct");
			iDtlRet = (unsigned long)(DBObjPtr)(csTmp);

			if (iDtlRet == PD_FOUND)
				PutField_CString(hContext, "txn_product", csTmp);
			else if (iDtlRet == PD_NOT_FOUND)
			{
DEBUGLOG(("- Calling DefProduct::FindProduct() Not Found!!\n"));

				iRet = INT_ERR;
			}
			else
			{
DEBUGLOG(("- Calling DefProduct::FindProduct() Error!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DefProduct::FindProduct() Error!!\n");

				iRet = INT_ERR;
			}
		}
		else
		{
DEBUGLOG(("- product_code not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() product_code not found!!\n");

			iRet = INT_MI_PRODUCT_CODE_NOT_FOUND;
		}
	}

	/* report_date */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "report_date", &csTmp))
		{
DEBUGLOG(("- report_date = [%s]\n", csTmp));
			PutField_CString(hContext, "report_date", csTmp);
		}
		else
		{
DEBUGLOG(("- report_date not found!!\n"));

			if (GetField_CString(hContext, "PHDATE", &csTmp))
			{
DEBUGLOG(("- report_date (PH Date) = [%s]\n", csTmp));
				PutField_CString(hContext, "report_date", csTmp);
			}
			else
			{
DEBUGLOG(("- report_date (PH Date) not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() report_date (PH Date) not found!!\n");

				iRet = INT_PHDATE_NOT_FOUND;
			}
		}
	}

	/* remark */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "remark", &csTmp))
		{
DEBUGLOG(("- remark = [%s]\n", csTmp));

			if (strlen(csTmp) > PD_REMARK_LEN)
			{
DEBUGLOG(("- remark is not allowed to input more than 255 characters!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() remark is not allowed to input more than 255 characters!!\n");

				iRet = INT_ERR;
			}
			else
				PutField_CString(hContext, "remark", csTmp);
		}
	}

	// For Mini MMM Transaction Detail Log - DBTxnMiDetail::Add()
	/* txn_date */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "PHDATE", &csTmp))
		{
DEBUGLOG(("- txn_date (PH Date) = [%s]\n", csTmp));

			PutField_CString(hContext, "txn_date", csTmp);
		}
		else
		{
DEBUGLOG(("- txn_date (PH Date) not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() txn_date (PH Date) not found!!\n");

				iRet = INT_PHDATE_NOT_FOUND;
		}
	}


	// Update "update_user" Of The Transaction Detail Log For RSP Hold / Unhold Transaction Request
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling MGTChannel::UpdateTxnDetailLog()\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateTxnDetailLog");

		if ((unsigned long)(ChannelObjPtr)(hContext, hRequest, hResponse) != PD_OK)
		{
DEBUGLOG(("- Calling MGTChannel::UpdateTxnDetailLog() Failed!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling MGTChannel::UpdateTxnDetailLog() Failed!!\n");

			iRet = INT_ERR;
		}
	}

	// Check The Entity Type Is RSP Or Not By "entity_id" (It Should Be RSP)
	if (iRet == PD_OK)
	{
		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

DEBUGLOG(("- Calling DBMiEntityDetail::GetEntityType()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiEntityDetail", "GetEntityType");
		iDtlRet = (unsigned long)(DBObjPtr)(csEntityId, hRec);

		if (iDtlRet == PD_FOUND)
		{
			/* entity_type */
			if (GetField_CString(hRec, "entity_type", &csTmp))
			{
DEBUGLOG(("- entity_type = [%s]\n", csTmp));

				if (strcmp(csTmp, PD_MI_ENTITY_RSP))
				{
DEBUGLOG(("- Invalid entity_type!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Invalid entity_type!!\n");

					iRet = INT_ERR;
				}
				else
					PutField_CString(hContext, "entity_type", csTmp);
			}
			else
			{
DEBUGLOG(("- entity_type not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() entity_type not found!!\n");

				iRet = INT_ERR;
			}
		}
		else if (iDtlRet == PD_NOT_FOUND)
		{
DEBUGLOG(("- Calling DBMiEntityDetail::GetEntityType() Not Found!!\n"));

			iRet = INT_ERR;
		}
		else
		{
DEBUGLOG(("- Calling DBMiEntityDetail::GetEntityType() Error!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityDetail::GetEntityType() Error!!\n");

			iRet = INT_ERR;
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}

	// Check The Status Of RSP Is Enabled Or Not By "entity_id" (It Should Be Enabled)
	if (iRet == PD_OK)
	{
		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

DEBUGLOG(("- Calling DBMiEntityRsp::GetRSPInfoByEntityId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiEntityRsp", "GetRSPInfoByEntityId");

		if ((unsigned long)(DBObjPtr)(csEntityId, hRec) != PD_OK)
		{
DEBUGLOG(("- Calling DBMiEntityRsp::GetRSPInfoByEntityId() Error!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityRsp::GetRSPInfoByEntityId() Error!!\n");

			iRet = INT_ERR;
		}
		else
		{
			/* status */
			if (GetField_CString(hRec, "status", &csTmp))
			{
DEBUGLOG(("- status (RSP) = [%s]\n", csTmp));

				if (strcmp(csTmp, PD_MI_ENTITY_BAL_ACCT_STATUS_OPEN))
				{
DEBUGLOG(("- Invalid status (RSP)!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityRsp::GetRSPInfoByEntityId() Invalid status (RSP)!!\n");

					iRet = INT_ERR;
				}
			}
			else
			{
DEBUGLOG(("- status (RSP) not found!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityRsp::GetRSPInfoByEntityId() status (RSP) not found!!\n");

				iRet = INT_ERR;
			}
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}

	// Check The RSP Balance Account Exist Or Not (It Should Be Existed)
	if (iRet == PD_OK)
	{
		hRec = (hash_t*)malloc(sizeof(hash_t));
		hash_init(hRec, 0);

DEBUGLOG(("- Calling DBMiEntityBalAcct::GetEntityBalAcct()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiEntityBalAcct", "GetEntityBalAcct");
		iDtlRet = (unsigned long)(DBObjPtr)(hRSPBalAcct, hRec);

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
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityBalAcct::GetEntityBalAcct() Invalid status (RSP Balance Account)!!\n");

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
ERRLOG("TxnMgtByUsHDR::Authorize() Calling DBMiEntityBalAcct::GetEntityBalAcct() Error!!\n");

			iRet = INT_ERR;
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}

	if (iRet != PD_OK)
		PutField_Int(hContext, "internal_error", iRet);

	// Call Mini MMM Transaction Handler To Process Money Movement
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling TxnMgtByUs2MiniMMM::Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnMgtByUs2MiniMMM", "Authorize");
		iRet = (unsigned long)(TxnObjPtr)(hContext, hRequest, hResponse);

DEBUGLOG(("- TxnMgtByUs2MiniMMM::Authorize() iRet = [%d]\n", iRet));

		if (iRet != PD_OK)
		{
DEBUGLOG(("- Calling TxnMgtByUs2MiniMMM::Authorize() Failure!!\n"));
ERRLOG("TxnMgtByUsHDR::Authorize() Calling TxnMgtByUs2MiniMMM::Authorize() Failure!!\n");
		}
	}

//	hash_destroy(hRec);
//	FREE_ME(hRec);

	hash_destroy(hRSPBalAcct);
	FREE_ME(hRSPBalAcct);

DEBUGLOG(("TxnMgtByUsHDR Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
