/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/16              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsTAD.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);

#define PD_DETAIL_TAG   "dt"

int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnMgtByUsTAD(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	csTag[PD_TMP_BUF_LEN+1];

	int	iCnt = 0;
	int	i;

	char	*csTxnId = NULL;
	char	*csOrgRptDate = NULL;
	char	*csOrgSettleDate = NULL;
	char	*csRptDate = NULL;
	char	*csSettleDate = NULL;
	char	*csUser;
	char	*csTxnCode;

	int	iNeedUpdateRptDate = PD_FALSE;
	int	iNeedUpdateSettleDate = PD_FALSE;
	int	iTmpNeedUpdateFlag = PD_FALSE;
	
	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hTmp;

	recordset_t *rsTmpTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTmpTxnHeader,0);

	recordset_t *rsTxnMiDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTxnMiDetail,0);

	hash_t *hTxnPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnPspDetail,0);

	hash_t *hTxnMiDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnMiDetail,0);

	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: total_cnt
	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
DEBUGLOG(("Authorize() total_cnt = [%d]\n",iCnt));
	} else {
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() total_cnt NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTAD:: Authorize() total_cnt NOT FOUND!!!\n");
	}

//API: user
	if (GetField_CString(hRequest, "add_user", &csUser)) {
		PutField_CString(hContext,"create_user",csUser);
		PutField_CString(hContext,"update_user",csUser);
			
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
	} else {
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTMK::Authorize() user NOT FOUND!!!\n");
	}


//Get Next Log BatchID Sequence
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog","GetNextITTTaskBatchSeq");
		strcpy(csLogBatchId, (*DBObjPtr)());
DEBUGLOG(("Authorize() LogBatchId = [%s]\n",csLogBatchId));

		PutField_CString(hITTLog,"batch_id",csLogBatchId);
		PutField_CString(hITTLog,"api_code",PD_ITT_API_TXN_RPT_DATE_AMEND);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}


	if (iRet == PD_OK) {
		//loop total_cnt to process update remark
		for (i = 0; i < iCnt; i++) {

			iNeedUpdateRptDate = PD_FALSE;
			iNeedUpdateSettleDate = PD_FALSE;
			csOrgRptDate = NULL;
			csOrgSettleDate = NULL;

DEBUGLOG(("START iCnt = [%d]\n",i));

//API: txnid
			sprintf(csTag,"%s_txnid_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csTxnId)) {
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csTxnId));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize()   [%s] NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTAD:: Authorize() [%s] NOT FOUND!!!\n");
				break;
			}

//API: rpt_date
			sprintf(csTag,"%s_rpt_date_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csRptDate)) {
				iNeedUpdateRptDate = PD_TRUE;
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csRptDate));
			}

//API: settle_date
			sprintf(csTag,"%s_settle_date_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csSettleDate)) {
				iNeedUpdateSettleDate = PD_TRUE;
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csSettleDate));
			}



DEBUGLOG(("Call DBTransaction:GetTxnHeader\n"));
//Call DBTransaction::GetTxnHeader

			recordset_init(rsTmpTxnHeader,0);

			DBObjPtr = CreateObj(DBPtr, "DBTransaction","GetTxnHeader");
			iRet = (unsigned long)(*DBObjPtr)(csTxnId,rsTmpTxnHeader);

			if (iRet == PD_OK) {
				hTmp = RecordSet_GetFirst(rsTmpTxnHeader);
				while (hTmp && iRet==PD_OK) {

					if (GetField_CString(hTmp,"txn_code",&csTxnCode)) {
DEBUGLOG(("  txn_code = [%s]\n",csTxnCode));
					}

					hTmp = RecordSet_GetNext(rsTmpTxnHeader);
				}
			} else {
DEBUGLOG(("Authorize()   Call DBTransaction:GetTxnHeader FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAD:: Authorize() Call DBTransaction:GetTxnHeader FAILED!!!\n");
				break;
			}


		//TxnPspDetail
			if (iRet == PD_OK) {
				hash_destroy(hTxnPspDetail);
				hash_init(hTxnPspDetail,0);

				iTmpNeedUpdateFlag = PD_FALSE;

DEBUGLOG(("Call DBTxnPspDetail:GetDatesByTxnId\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetDatesByTxnId");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,hTxnPspDetail);

				if (iDtlRet == PD_OK) {
					if (GetField_CString(hTxnPspDetail,"report_date",&csOrgRptDate)) {
						iTmpNeedUpdateFlag = PD_TRUE;
DEBUGLOG(("   report_date (Original) = [%s]\n",csOrgRptDate));
					}

					if (GetField_CString(hTxnPspDetail,"txn_date",&csOrgSettleDate)) {
						iTmpNeedUpdateFlag = PD_TRUE;
DEBUGLOG(("   txn_date (Original) = [%s]\n",csOrgSettleDate));
					}
				} else {
					iRet = iDtlRet;
DEBUGLOG(("  FAILED!! Call DBTxnPspDetail return [%d], break!!!\n",iRet));
ERRLOG("TxnMgtByUsTAD:: Call DBTxnPspDetail FAILED, iRet = [%d]!!!\n",iRet);
				}

				if (iTmpNeedUpdateFlag) {
DEBUGLOG(("Call DBTxnPspDetail:Update\n"));
					PutField_CString(hTxnPspDetail,"txn_seq",csTxnId);
DEBUGLOG(("  txn_seq = [%s]\n",csTxnId));

					PutField_CString(hTxnPspDetail,"update_user",csUser);
DEBUGLOG(("  update_user = [%s]\n",csUser));

					if (iNeedUpdateRptDate) {
						PutField_CString(hTxnPspDetail,"report_date",csRptDate);
						AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_UPD_RPT_DATE,PD_ITT_LOG_UPDATE,"TXN_PSP_DETAIL",csTxnId,"tp_report_date",csRptDate,csOrgRptDate);
					}

					if (iNeedUpdateSettleDate) {
						PutField_CString(hTxnPspDetail,"txn_date",csSettleDate);
						AddTaskLog(hITTLog,iLogBatchSeq,PD_ITT_ACTION_UPD_SETTLE_DATE,PD_ITT_LOG_UPDATE,"TXN_PSP_DETAIL",csTxnId,"tp_txn_date",csSettleDate,csOrgSettleDate);
					}

					iLogBatchSeq++;

					DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
					iDtlRet = (unsigned long)(*DBObjPtr)(hTxnPspDetail);

					if (iDtlRet == PD_OK) {
DEBUGLOG(("  update success!\n"));
					} else {
						iRet = iDtlRet;
DEBUGLOG(("  FAILED!! Call DBTxnPspDetail:Update return [%d], break!!!\n",iRet));
ERRLOG("TxnMgtByUsTAD:: Call DBTxnPspDetail:Update FAILED, iRet = [%d]!!!\n",iRet);
					}
				}
			} //End TxnPspDetail


		//TxnMiDetail
			if (iRet == PD_OK) {
				recordset_init(rsTxnMiDetail,0);

				iTmpNeedUpdateFlag = PD_FALSE;

DEBUGLOG(("Call DBTxnMiDetail:GetTxnMiDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","GetTxnMiDetail");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,rsTxnMiDetail);

				if (iDtlRet == PD_OK) {
					hTmp = RecordSet_GetFirst(rsTxnMiDetail);
					while (hTmp) {

						if (GetField_CString(hTmp,"report_date",&csOrgRptDate)) {
							iTmpNeedUpdateFlag = PD_TRUE;
DEBUGLOG(("   report_date (Original) = [%s]\n",csOrgRptDate));
						}

						hTmp = RecordSet_GetNext(rsTxnMiDetail);
					}
				} else {
					iRet = iDtlRet;
DEBUGLOG(("  FAILED!! Call DBTxnPspDetail return [%d], break!!!\n",iRet));
ERRLOG("TxnMgtByUsTAD:: Call DBTxnPspDetail FAILED, iRet = [%d]!!!\n",iRet);
				}

				if (iTmpNeedUpdateFlag) {
DEBUGLOG(("Call DBTxnMiDetail:Update\n"));
					PutField_CString(hTxnMiDetail,"txn_seq",csTxnId);
DEBUGLOG(("  txn_seq = [%s]\n",csTxnId));

					PutField_CString(hTxnMiDetail,"update_user",csUser);
DEBUGLOG(("  update_user = [%s]\n",csUser));

					if (iNeedUpdateRptDate) {
						PutField_CString(hTxnMiDetail,"report_date",csRptDate);
						AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPD_RPT_DATE,PD_ITT_LOG_UPDATE,"TXN_MI_DETAIL",csTxnId,"tm_report_date",csRptDate,csOrgRptDate);
					}

					DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","Update");
					iDtlRet = (unsigned long)(*DBObjPtr)(hTxnMiDetail);

					if (iDtlRet == PD_OK) {
DEBUGLOG(("  update success!\n"));
					} else {
						iRet = iDtlRet;
DEBUGLOG(("  FAILED!! Call DBTxnMiDetail:Update return [%d], break!!!\n",iRet));
ERRLOG("TxnMgtByUsTAD:: Call DBTxnMiDetail:Update FAILED, iRet = [%d]!!!\n",iRet);
					}
				}
			} //End TxnMiDetail


DEBUGLOG(("END iCnt = [%d]\n",i));
		} //end loop for detail cnt
	}


	if (iRet == PD_OK) {
DEBUGLOG(("UpdateTaskLogByBatch()\n"));
		PutField_Int(hITTLog,"ret_code",iRet);
		DBObjPtr = CreateObj(DBPtr,"DBIttTaskLog","UpdateRetCodeByBatch");
		iRet = (unsigned long)(*DBObjPtr)(hITTLog);
		if (iRet != PD_OK) {
DEBUGLOG(("  FAILURE!!! iRet = [%d]\n",iRet));
		} else {
DEBUGLOG(("  SUCCESS!!!\n"));
		}
	}


	hash_destroy(hTxnMiDetail);
	FREE_ME(hTxnMiDetail);

	hash_destroy(hTxnPspDetail);
	FREE_ME(hTxnPspDetail);

	hash_destroy(hITTLog);
	FREE_ME(hITTLog);

	recordset_destroy(rsTxnMiDetail);
	FREE_ME(rsTxnMiDetail);

	recordset_destroy(rsTmpTxnHeader);
	FREE_ME(rsTmpTxnHeader);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}


int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue)
{
	int iRet = PD_OK;

	PutField_Int(hITTLog,"batch_seq",iLogBatchSeq);
	PutField_CString(hITTLog,"task_action",csTaskAction);
	PutField_Char(hITTLog,"action_type",cActionType);
	PutField_CString(hITTLog,"object",csObject);
	PutField_Int(hITTLog,"ret_code",PD_ITT_INIT_RET_CODE);

	RemoveField_CString(hITTLog,"key");
	RemoveField_CString(hITTLog,"field");
	RemoveField_CString(hITTLog,"value");
	RemoveField_CString(hITTLog,"old_value");

	if (cActionType == PD_ITT_LOG_INSERT) {
		PutField_CString(hITTLog,"field",csField);
		PutField_CString(hITTLog,"value",csValue);
	} 

	if (cActionType == PD_ITT_LOG_UPDATE) {
		PutField_CString(hITTLog,"key",csKey);
		PutField_CString(hITTLog,"field",csField);
		PutField_CString(hITTLog,"value",csValue);
		if (csOldValue != NULL) {
			PutField_CString(hITTLog,"old_value",csOldValue);
		}
	}

	if (cActionType == PD_ITT_LOG_DELETE) {
		PutField_CString(hITTLog,"key",csKey);
	} 

	if (cActionType == PD_ITT_LOG_FUNCTION) {
		PutField_CString(hITTLog,"key",csKey);
	}

DEBUGLOG(("AddTaskLog()\n"));
	DBObjPtr = CreateObj(DBPtr, "DBIttTaskLog", "Add");
	iRet = (unsigned long)(*DBObjPtr)(hITTLog);
	if (iRet != PD_OK) {
DEBUGLOG(("  FAILURE!!! iRet = [%d]\n",iRet));
	} else {
DEBUGLOG(("  SUCCESS!!!\n"));
	}


	return iRet;
}
