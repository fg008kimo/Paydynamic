/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/02/24              [ZBL]
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
#include "TxnMgtByUsTMT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);

void TxnMgtByUsTMT(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext, const hash_t *hRequest, hash_t *hResponse)
{
	char		*csMerchantId = NULL;
	char		*csStatus = NULL;
	char		*csUser = NULL;
	char		*csTmp = NULL;
	char		csLogBatchId[PD_TXN_SEQ_LEN + 1];
	int		iDtlRet = PD_ERR;
	int		iHandThreshold = 0;
	int		iInitThreshold = 0;
	int		iRet = PD_OK;
	int		iTmp = 0;
	hash_t		*hITTLog = NULL;
	hash_t		*hTxn = NULL;
	recordset_t	*rRecordSet;

	memset(csLogBatchId, 0, PD_TXN_SEQ_LEN + 1);

	hITTLog = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hITTLog, 0);

	hTxn = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

	rRecordSet = (recordset_t*)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

DEBUGLOG(("TxnMgtByUsTMT::Authorize\n"));

	/* merchant_id */
	if (GetField_CString(hRequest, "merchant_id", &csMerchantId))
	{
DEBUGLOG(("- merchant_id = [%s]\n", csMerchantId));
		PutField_CString(hTxn, "merchant_id", csMerchantId);
	}
	else
	{
DEBUGLOG(("- merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: merchant_id not found!!\n");

		iRet = INT_MERCHANT_ID_NOT_FOUND;
	}

	/* hand_threshold */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "hand_threshold", &csTmp))
		{
			if (is_numeric(csTmp) != PD_FALSE)
			{
				if (IsValidRange(csTmp, &iHandThreshold) == PD_OK)
				{
DEBUGLOG(("- hand_threshold = [%d]\n", iHandThreshold));
					PutField_Int(hTxn, "max_handshake_count", iHandThreshold);
				}
				else
				{
DEBUGLOG(("- Invalid hand_threshold!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize() Invalid hand_threshold!!\n");

					iRet = INT_ERR;
				}
			}
			else
			{
DEBUGLOG(("- Invalid hand_threshold!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize() Invalid hand_threshold!!\n");

				iRet = INT_ERR;
			}
		}
		else
		{
DEBUGLOG(("- hand_threshold not found!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: hand_threshold not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* init_threshold */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "init_threshold", &csTmp))
		{
			if (is_numeric(csTmp) != PD_FALSE)
			{
				if (IsValidRange(csTmp, &iInitThreshold) == PD_OK)
				{
DEBUGLOG(("- init_threshold = [%d]\n", iInitThreshold));
					PutField_Int(hTxn, "max_init_count", iInitThreshold);
				}
				else
				{
DEBUGLOG(("- Invalid init_threshold!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize() Invalid init_threshold!!\n");

					iRet = INT_ERR;
				}
			}
			else
			{
DEBUGLOG(("- Invalid init_threshold!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize() Invalid init_threshold!!\n");

				iRet = INT_ERR;
			}
		}
		else
		{
DEBUGLOG(("- init_threshold not found!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: init_threshold not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* status */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hRequest, "status", &csStatus))
		{
DEBUGLOG(("- status = [%s]\n", csStatus));

			iTmp = atoi(csStatus);

			if (iTmp == PD_TRUE)
				PutField_Int(hTxn, "disabled", PD_TRUE);
			else if (iTmp == PD_FALSE)
				PutField_Int(hTxn, "disabled", PD_FALSE);
			else
			{
DEBUGLOG(("- Invalid status!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize() Invalid status!!\n");

				iRet = INT_ERR;
			}
		}
		else
		{
DEBUGLOG(("- status not found!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: status not found!!\n");

			iRet = INT_ERR;
		}
	}

	/* user */
	if (iRet == PD_OK)
	{
		if (GetField_CString(hContext, "add_user", &csUser))
		{
DEBUGLOG(("- update_user = [%s]\n", csUser));
			PutField_CString(hTxn, "update_user", csUser);
		}
		else
		{
DEBUGLOG(("- update_user not found!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: update_user not found!!\n");

			iRet = INT_USER_NOT_FOUND;
		}
	}

	// Check The Merchant ID Exist Or Not
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBMerchDetail::ChkMerchIDExist\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchDetail", "ChkMerchIDExist");
		iDtlRet = (unsigned long)(DBObjPtr)(csMerchantId);

DEBUGLOG(("- DBMerchDetail::ChkMerchIDExist iRet = [%d]\n", iDtlRet));

		if (iDtlRet == PD_FOUND)
		{
DEBUGLOG(("- Calling DBMerchDetail::ChkMerchIDExist Found!!\n"));
		}
		else if (iDtlRet == PD_NOT_FOUND)
		{
DEBUGLOG(("- Calling DBMerchDetail::ChkMerchIDExist Not Found!!\n"));

			iRet = INT_ERR;
		}
		else
		{
DEBUGLOG(("- Calling DBMerchDetail::ChkMerchIDExist Error!!\n"));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling DBMerchDetail::ChkMerchIDExist Error!!\n");

			iRet = INT_ERR;
		}
	}

	// Prepare To Update hreshold (Hand-Shake And Initiated) And Status By Merchant ID
	// Step 1: Get The Next Log BatchID Sequence
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBIttTaskLog::GetNextITTTaskBatchSeq\n"));
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog", "GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (DBObjPtr)());

DEBUGLOG(("- LogBatchId = [%s]\n", csLogBatchId));

		PutField_CString(hITTLog, "batch_id", csLogBatchId);
		PutField_CString(hITTLog, "api_code", PD_ITT_API_UPDATE_CHECK_HAND_SHAKE);
		PutField_CString(hITTLog, "create_user", csUser);
		PutField_CString(hITTLog, "update_user", csUser);
	}

	/*
	 * Step 2
	 *  - 1: Get The Original Threshold (Hand-Shake And Initiated) And Status By Merchant ID
	 *  - 2: Add The Original And New Threshold (Hand-Shake And Initiated) And Status To Task Log
	 */
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBCheckHandShake::GetThresholdByMID\n"));
		DBObjPtr = CreateObj(DBPtr, "DBCheckHandShake", "GetThresholdByMID");
		iDtlRet = (unsigned long)(DBObjPtr)(csMerchantId, rRecordSet);

		if (iDtlRet == PD_FOUND)
		{
			int	iCnt = 0;
			int	iLogBatchSeq = 1;
			hash_t	*hRec = NULL;

			hRec = RecordSet_GetFirst(rRecordSet);

			while (hRec && iRet == PD_OK)
			{
				char *csNBuf;
				char *csPBuf;
				char csTag[PD_TMP_BUF_LEN + 1];

				csNBuf = (char*)malloc(PD_TMP_BUF_LEN);
				csPBuf = (char*)malloc(PD_TMP_BUF_LEN);

				memset(csTag, 0, PD_TMP_BUF_LEN + 1);
				sprintf(csTag, "%s", csMerchantId);

				/* max_handshake_count */
				if (GetField_Int(hRec, "max_handshake_count", &iTmp))
				{
DEBUGLOG(("- [%d] Original max_handshake_count = [%d]\n", iCnt, iTmp));

					sprintf(csNBuf, "%d", iHandThreshold);
					sprintf(csPBuf, "%d", iTmp);
					//sprintf(csTag, "%s||%s", csMerchantId, PD_HANDSHAKE_THRESHOLD);

					if (AddTaskLog(hITTLog, iLogBatchSeq, PD_ITT_ACTION_UPDATE_CHECK_HAND_SHAKE, PD_ITT_LOG_UPDATE, "CHECK_HAND_SHAKE", csTag, "CH_MAX_HANDSHAKE_COUNT", csNBuf, csPBuf) != PD_OK)
					{
DEBUGLOG(("- [%d] Calling AddTaskLog For Hand-Shake Threshold Error!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling AddTaskLog For Hand-Shake Threshold Error!!\n");

						iRet = INT_ERR;
					}
				}
				else
				{
DEBUGLOG(("- [%d] Original max_handshake_count not found!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling DBCheckHandShake::GetThresholdByMID Original max_handshake_count not found!!\n");

					iRet = INT_ERR;
				}

				/* max_init_count */
				if (iRet == PD_OK)
				{
					if (GetField_Int(hRec, "max_init_count", &iTmp))
					{
DEBUGLOG(("- [%d] Original max_init_count = [%d]\n", iCnt, iTmp));

						sprintf(csNBuf, "%d", iInitThreshold);
						sprintf(csPBuf, "%d", iTmp);
						//sprintf(csTag, "%s||%s", csMerchantId, PD_INITIATED_THRESHOLD);

						if (AddTaskLog(hITTLog, iLogBatchSeq, PD_ITT_ACTION_UPDATE_CHECK_HAND_SHAKE, PD_ITT_LOG_UPDATE, "CHECK_HAND_SHAKE", csTag, "CH_MAX_INIT_COUNT", csNBuf, csPBuf) != PD_OK)
						{
DEBUGLOG(("- [%d] Calling AddTaskLog For Initiated Threshold Error!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling AddTaskLog For Initiated Threshold Error!!\n");

							iRet = INT_ERR;
						}
					}
					else
					{
DEBUGLOG(("- [%d] Original max_init_count not found!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling DBCheckHandShake::GetThresholdByMID Original max_init_count not found!!\n");

						iRet = INT_ERR;
					}
				}

				/* disabled */
				if (iRet == PD_OK)
				{
					if (GetField_Int(hRec, "disabled", &iTmp))
					{
DEBUGLOG(("- [%d] Original disabled = [%d]\n", iCnt, iTmp));

						sprintf(csPBuf, "%d", iTmp);
						//sprintf(csTag, "%s||%s", csMerchantId, PD_STATUS_THRESHOLD);

						if (AddTaskLog(hITTLog, iLogBatchSeq, PD_ITT_ACTION_UPDATE_CHECK_HAND_SHAKE, PD_ITT_LOG_UPDATE, "CHECK_HAND_SHAKE", csTag, "CH_DISABLED", csStatus, csPBuf) != PD_OK)
						{
DEBUGLOG(("- [%d] Calling AddTaskLog For Status Error!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling AddTaskLog For Status Error!!\n");

							iRet = INT_ERR;
						}
					}
					else
					{
DEBUGLOG(("- [%d] Original disabled not found!!\n", iCnt));
ERRLOG("TxnMgtByUsTMT::Authorize:: Calling DBCheckHandShake::GetThresholdByMID Original disabled not found!!\n");

						iRet = INT_ERR;
					}
				}

				FREE_ME(csNBuf);
				FREE_ME(csPBuf);

				iCnt++;
				iLogBatchSeq++;

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else if (iDtlRet == PD_NOT_FOUND)
		{
DEBUGLOG(("- Calling DBMerchDetail::ChkMerchIDExist Not Found!!\n"));

			iRet = INT_ERR;
		}
		else
		{
DEBUGLOG(("- Calling DBCheckHandShake::GetThresholdByMID Error!!\n"));
ERRLOG("TxnOmtByUsTMT::Authorize:: Calling DBCheckHandShake::GetThresholdByMID Error!!\n");

			iRet = INT_ERR;
		}
	}

	// Step 3: Update Hand-Shake And Initiated Threshold By Merchant ID
	if (iRet == PD_OK)
	{
DEBUGLOG(("- Calling DBCheckHandShake::UpdateThresholdByMID\n"));
		DBObjPtr = CreateObj(DBPtr, "DBCheckHandShake", "UpdateThresholdByMID");

		if ((unsigned long)(DBObjPtr)(hTxn) != PD_OK)
			iRet = INT_ERR;

DEBUGLOG(("- DBCheckHandShake::UpdateThresholdByMID iRet = [%d]\n", iRet));
	}

	// Step 4: Update The Result Code To Task Log
	if (iRet == PD_OK)
	{
		PutField_Int(hITTLog, "ret_code", iRet);

DEBUGLOG(("- Calling DBIttTaskLog::UpdateTaskLogByBatch\n"));
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog", "UpdateRetCodeByBatch");

		iRet = (unsigned long)(DBObjPtr)(hITTLog);
		
DEBUGLOG(("- DBIttTaskLog::UpdateTaskLogByBatch iRet = [%d]\n", iRet));
	}

	if (iRet != PD_OK)
		PutField_Int(hContext, "internal_error", iRet);

	hash_destroy(hITTLog);
	FREE_ME(hITTLog);

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnMgtByUsTMT Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

int AddTaskLog(hash_t *hITTLog, int iLogBatchSeq, char *csTaskAction, char cActionType, char *csObject, char *csKey, char *csField, char *csValue, char *csOldValue)
{
	int iRet = PD_OK;

	PutField_Int(hITTLog, "batch_seq", iLogBatchSeq);
	PutField_CString(hITTLog, "task_action", csTaskAction);
	PutField_Char(hITTLog, "action_type", cActionType);
	PutField_CString(hITTLog, "object", csObject);
	PutField_Int(hITTLog, "ret_code", PD_ITT_INIT_RET_CODE);

	RemoveField_CString(hITTLog, "key");
	RemoveField_CString(hITTLog, "field");
	RemoveField_CString(hITTLog, "value");
	RemoveField_CString(hITTLog, "old_value");

	if (cActionType == PD_ITT_LOG_INSERT)
	{
		PutField_CString(hITTLog, "field", csField);
		PutField_CString(hITTLog, "value", csValue);
	}
	else if (cActionType == PD_ITT_LOG_UPDATE)
	{
		PutField_CString(hITTLog, "key", csKey);
		PutField_CString(hITTLog, "field", csField);
		PutField_CString(hITTLog, "value", csValue);
		PutField_CString(hITTLog, "old_value", csOldValue);
	}
	else if (cActionType == PD_ITT_LOG_DELETE || cActionType == PD_ITT_LOG_FUNCTION)
		PutField_CString(hITTLog, "key", csKey);
	else 
	{
DEBUGLOG(("- Invalid Action Type!!\n"));
		return PD_ERR;
	}

DEBUGLOG(("- Calling DBIttTaskLog::AddTaskLog\n"));
	DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog", "Add");
	iRet = (unsigned long)(DBObjPtr)(hITTLog);

DEBUGLOG(("- DBIttTaskLog::AddTaskLog iRet = [%d]\n", iRet));
	return iRet;
}

int IsValidRange(char *csValue, int *iValue)
{
	if (sscanf(csValue, "%d", iValue) == PD_TRUE)
	{
		if (*iValue >= 0 && *iValue <= 100)
			return PD_OK;
		else
			return PD_ERR;
	}
	else
		return PD_ERR;
}
