/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/05/05              [ZBL]
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
#include "TxnOmtByUsBHR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnOmtByUsBHR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char		cStatus;
	char 		*csBatchId = NULL;
	char		*csTxnCode = NULL;
	char		*csUser = NULL;
	int		iCnt = 0;
	int		iRecordCnt = 0;
	int		iDtlRet	= PD_ERR;
	int		iHdrRet	= PD_ERR;
	int		iRet = PD_OK;
	hash_t		*hBulkDetail;
	hash_t		*hBulkHeader;
	hash_t		*hRec = NULL;
	recordset_t	*rRecordSet;

	hBulkDetail = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBulkDetail, 0);

	hBulkHeader = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hBulkHeader, 0);

	rRecordSet = (recordset_t*)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("TxnOmtByUsBHR::Authorize\n"));

	/* batch_id */
	if (GetField_CString(hRequest, "batch_id", &csBatchId))
	{
DEBUGLOG(("- batch_id = [%s]\n", csBatchId));
		PutField_CString(hBulkHeader, "batch_id", csBatchId);
	}
	else
	{
DEBUGLOG(("- batch_id not found!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: batch_id not found!!\n");

		iRet = INT_BATCH_ID_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

	/* txn_code */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "txn_code", &csTxnCode))
		{
DEBUGLOG(("- txn_code = [%s]\n", csTxnCode));
			PutField_CString(hBulkHeader, "txn_code", csTxnCode);
		}
		else
		{
DEBUGLOG(("- txn_code not found!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: txn_code not found!!\n");

			iRet = INT_TXN_CODE_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	/* user */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "add_user", &csUser))
		{
DEBUGLOG(("- add_user = [%s]\n", csUser));
			PutField_CString(hBulkHeader, "update_user", csUser);
		}
		else
		{
DEBUGLOG(("- add_user not found!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: add_user not found!!\n");

			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Get Record Counts And Status From Bulk Header
	if (iRet == PD_OK)
	{
		DBObjPtr = CreateObj(DBPtr, "DBOLBulkHeader", "Get");
		iHdrRet = (unsigned long)(*DBObjPtr)(csBatchId, csTxnCode, hBulkHeader);

DEBUGLOG(("- DBOLBulkHeader::Get iRet = [%d]\n", iHdrRet));

		if (iHdrRet == FOUND)
		{
DEBUGLOG(("- Calling DBOLBulkHeader::Get Found!!\n"));

			/* record_cnt */
			if (GetField_Int(hBulkHeader, "record_cnt", &iRecordCnt))
			{
DEBUGLOG(("- record_cnt = [%d]\n", iRecordCnt));

				if (iRecordCnt <= 0)
				{
DEBUGLOG(("- record_cnt should be greater than 0!!\n"));

					iRet = INT_RECORD_CNT_INVALID;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
			else
			{
DEBUGLOG(("- record_cnt not found!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkHeader::Get record_cnt not found!!\n");

				iRet = INT_RECORD_CNT_NOT_FOUND;
				PutField_Int(hContext, "internal_error", iRet);
			}

			/* status */
			if (iRet == PD_OK)
			{
				if (GetField_Char(hBulkHeader, "status", &cStatus))
				{
DEBUGLOG(("- status = [%c]\n", cStatus));

					if (cStatus != PD_BULK_STATUS_INIT)
					{
DEBUGLOG(("- status not [I]!!\n"));

						iRet = INT_INVALID_INIT_STATUS;
						PutField_Int(hContext, "internal_error", iRet);
					}
				}
				else
				{
DEBUGLOG(("- status not found!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkHeader::Get status not found!!\n");

					iRet = INT_STATUS_NOT_FOUND;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
		}
		else if (iHdrRet == NOT_FOUND)
		{
DEBUGLOG(("- Calling DBOLBulkHeader::Get Not Found!!\n"));

			iRet = INT_RECORD_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else
		{
DEBUGLOG(("- Calling DBOLBulkHeader::Get Error!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkHeader::Get Error!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}

		// Update Bulk Header Status To Processing('P')
		if (iRet == PD_OK)
		{
			PutField_Char(hBulkHeader, "status", PD_BULK_STATUS_PROCESS); 

			DBObjPtr = CreateObj(DBPtr, "DBOLBulkHeader", "Update");

			if ((unsigned long)(*DBObjPtr)(hBulkHeader) == PD_OK)
			{
DEBUGLOG(("- Calling DBOLBulkHeader::Update status [%c] Success!!\n", PD_BULK_STATUS_PROCESS));
				TxnCommit();
			}
			else
			{
DEBUGLOG(("- Calling DBOLBulkHeader::Update status [%c] Failure!!\n", PD_BULK_STATUS_PROCESS));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkHeader::Update Failure!!\n");

				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	// Get Seq, Transaction ID, Original Hold Type And Hold Type From Bulk Detail
	if (iRet == PD_OK)
	{
		DBObjPtr = CreateObj(DBPtr, "DBOLBulkDetail", "GetByBatchId");
		iDtlRet = (unsigned long)(*DBObjPtr)(csBatchId, rRecordSet);

DEBUGLOG(("- DBOLBulkDetail::GetByBatchId iRet = [%d]\n", iDtlRet));

		if (iDtlRet == FOUND)
		{
DEBUGLOG(("- Calling DBOLBulkDetail::GetByBatchId Found!!\n"));

			// Loop Bulk Detail Records
			hRec = RecordSet_GetFirst(rRecordSet);

			while (hRec && iRet == PD_OK)
			{
				char	cHoldType;
				char	cOrgHoldType;
				char	*csTmp = (char*)malloc(PD_TMP_BUF_LEN);
				char	*csTxnId = NULL;
				int	iSeq = 0;
				hash_t	*hTxnMHRReq;

				memset(csTmp, 0, PD_TMP_BUF_LEN);

				hTxnMHRReq = (hash_t*)malloc(sizeof(hash_t));
				hash_init(hTxnMHRReq, 0);

				/* seq */
				if (GetField_Int(hRec, "seq", &iSeq))
				{
DEBUGLOG(("- [%d] seq = [%d]\n", iCnt, iSeq));
				}

				/* txn_id / org_hold_type / hold_type */
				if (GetField_CString(hRec, "txn_id", &csTxnId) && 
				    GetField_Char(hRec, "org_hold_type", &cOrgHoldType) && 
				    GetField_Char(hRec, "hold_type", &cHoldType))
				{
DEBUGLOG(("- [%d] txn_id = [%s], org_hold_type = [%c], hold_type = [%c]\n", iCnt, csTxnId, cOrgHoldType, cHoldType));
					PutField_CString(hTxnMHRReq, "org_txn_seq", csTxnId);
				}
				else
				{
DEBUGLOG(("- [%d] txn_id not found!!\n", iCnt));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkDetail::GetByBatchId txn_id not found!!\n");

					iRet = INT_ERR;
				}

				if (iRet == PD_OK)
				{
					if (cOrgHoldType == cHoldType)
					{
DEBUGLOG(("- [%d] org_hold_type and hold_type are the same. Skipped!!\n", iCnt));
					}
					else
					{
DEBUGLOG(("- [%d] org_hold_type is different from hold_type!!\n", iCnt));

						/* hold_type */
						sprintf(csTmp, "%c", cHoldType);
						PutField_CString(hTxnMHRReq, "hold_type", csTmp);

						/* txn_type */
						sprintf(csTmp, "%c", PD_TXN_LEVEL);
						PutField_CString(hTxnMHRReq, "txn_type", csTmp);

						/* user */
						PutField_CString(hTxnMHRReq, "add_user", csUser);

						// Call Manual Hold Reconciliation Transaction
						TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsMHR", "Authorize");
						iRet = (unsigned long)(*TxnObjPtr)(hContext, hTxnMHRReq, hTxnMHRReq);

DEBUGLOG(("- [%d] TxnOmtByUsMHR::Authorize iRet = [%d]\n", iCnt, iRet));

						if (iRet == PD_OK)
						{
DEBUGLOG(("- [%d] Calling TxnOmtByUsMHR::Authorize Success!!\n", iCnt));
						}
						else
						{
DEBUGLOG(("- [%d] Calling TxnOmtByUsMHR::Authorize Failure [%d]!!\n", iCnt, iRet));
							TxnAbort();
						}

						// Update Ret Code To Bulk Detail
						PutField_CString(hBulkDetail, "batch_id", csBatchId);
						PutField_Int(hBulkDetail, "seq", iSeq);
						PutField_Int(hBulkDetail, "ret_code", iRet);
						PutField_CString(hBulkDetail, "update_user", csUser);

						DBObjPtr = CreateObj(DBPtr, "DBOLBulkDetail", "Update");

						if ((unsigned long)(*DBObjPtr)(hBulkDetail) == PD_OK)
						{
DEBUGLOG(("- [%d] Calling DBOLBulkDetail::Update ret_code [%d] on seq [%d] Success!!\n", iCnt, iRet, iSeq));
						}
						else
						{
DEBUGLOG(("- [%d] Calling DBOLBulkDetail::Update ret_code [%d] on seq [%d] Failure!!\n", iCnt, iRet, iSeq));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkDetail::Update Failure!!\n");

							iRet = INT_ERR;
							PutField_Int(hContext, "internal_error", iRet);
						}
					}
				}

				FREE_ME(csTmp);

				hash_destroy(hTxnMHRReq);
				FREE_ME(hTxnMHRReq);

				if (iRet == PD_OK)
					iCnt++;

				hRec = RecordSet_GetNext(rRecordSet);
			}

DEBUGLOG(("- Bulk Detail Record Counts = [%d], Success Count = [%d]\n", iRecordCnt, iCnt));

			if (iRet == PD_OK)
			{
				// Check Counts
				if (iCnt != iRecordCnt)
				{
DEBUGLOG(("- Bulk Detail Record Counts [%d] is not equal to Bulk Header Record Counts [%d]!!\n", iCnt, iRecordCnt));

					iRet = INT_INVALID_COUNT;
					PutField_Int(hContext, "internal_error", iRet);

					TxnAbort();
				}
			}
		}
		else if (iDtlRet == NOT_FOUND)
		{
DEBUGLOG(("- Calling DBOLBulkDetail::GetByBatchId Not Found!!\n"));

			iRet = INT_RECORD_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		}
		else
		{
DEBUGLOG(("- Calling DBOLBulkDetail::GetByBatchId Error!!\n"));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkDetail::Get Error!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Update Bulk Header Status And Ret Code
	if (iHdrRet == FOUND)
	{
		PutField_Int(hBulkHeader, "ret_code", iRet);

		if (iRet != PD_OK)
			PutField_Char(hBulkHeader, "status", PD_BULK_STATUS_REJECT);
		else
			PutField_Char(hBulkHeader, "status", PD_BULK_STATUS_COMPLETE);

		DBObjPtr = CreateObj(DBPtr, "DBOLBulkHeader", "Update");

		if ((unsigned long)(*DBObjPtr)(hBulkHeader) == PD_OK)
		{
DEBUGLOG(("- Calling DBOLBulkHeader::Update status [%c] Success!!\n", iRet == PD_OK ? PD_BULK_STATUS_COMPLETE : PD_BULK_STATUS_REJECT));
		}
		else
		{
DEBUGLOG(("- Calling DBOLBulkHeader::Update status [%c] Failure!!\n", iRet == PD_OK ? PD_BULK_STATUS_COMPLETE : PD_BULK_STATUS_REJECT));
ERRLOG("TxnOmtByUsBHR::Authorize:: Calling DBOLBulkHeader::Update Failure!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	hash_destroy(hBulkDetail);
	FREE_ME(hBulkDetail);

	hash_destroy(hBulkHeader);
	FREE_ME(hBulkHeader);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsBHR Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
