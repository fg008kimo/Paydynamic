/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/02              Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsTAR.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);

#define PD_DETAIL_TAG   "dt"

int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnOmtByUsTAR(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	*csTmp;
	char	csTag[PD_TMP_BUF_LEN+1];
	char	cTmp;
	int	iTmp;

	int	iCnt = 0;
	int	i;

	char	*csTxnId = NULL;
	char	*csSubStatus = NULL;
	char	*csOrgRemark = NULL;
	char	*csNewRemark = NULL;
	char	*csUser;
	char	*csTxnCode;
	char	cStatus;
	char	cARInd;
	int	iSeq;

	int	iNeedUpdateTxnDetail = PD_TRUE;
	int	iNeedUpdateMerchSettDt = PD_FALSE;

	char	csLogBatchId[PD_TXN_SEQ_LEN+1];
	int	iLogBatchSeq = 1;

	hash_t *hTmp = NULL;

	recordset_t *rsTmpOLTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTmpOLTxnHeader,0);

	recordset_t *rsOLTxnDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsOLTxnDetail,0);

	recordset_t *rsOLTxnMiDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsOLTxnMiDetail,0);
	
	hash_t *hOLTxnDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLTxnDetail,0);
	
	hash_t *hOLTxnMiDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLTxnMiDetail,0);
	
	hash_t *hOLMerchantSettleDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLMerchantSettleDetail,0);
	
	hash_t *hOLTxnRemarks = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOLTxnRemarks,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: total_cnt
	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
DEBUGLOG(("Authorize() total_cnt = [%d]\n",iCnt));
	} else {
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() total_cnt NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() total_cnt NOT FOUND!!!\n");
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
		PutField_CString(hITTLog,"api_code",PD_ITT_API_TXN_REMARK_AMEND);
		PutField_CString(hITTLog,"create_user",csUser);
		PutField_CString(hITTLog,"update_user",csUser);
	}


	if (iRet == PD_OK) {
		//loop total_cnt to process update remark
		for (i = 0; i < iCnt; i++) {

			iNeedUpdateTxnDetail = PD_TRUE;
			iNeedUpdateMerchSettDt = PD_FALSE;
			csOrgRemark = NULL;


DEBUGLOG(("START iCnt = [%d]\n",i));

//API: txnid
			sprintf(csTag,"%s_txnid_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csTxnId)) {
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csTxnId));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize()   [%s] NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() [%s] NOT FOUND!!!\n");
				break;
			}

//API: seq
			sprintf(csTag,"%s_seq_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				iSeq = atoi(csTmp);
DEBUGLOG(("Authorize()   [%s] = [%d]\n",csTag,iSeq));
			}

//API: status
			sprintf(csTag,"%s_status_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				cStatus = csTmp[0];
DEBUGLOG(("Authorize()   [%s] = [%c]\n",csTag,cStatus));
			}

//API: ar_ind
			sprintf(csTag,"%s_ar_ind_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				cARInd = csTmp[0];
DEBUGLOG(("Authorize()   [%s] = [%c]\n",csTag,cARInd));
			}

//API: sub_status
			sprintf(csTag,"%s_sub_status_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csSubStatus)) {
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csSubStatus));
			}

//API: org_remark
			sprintf(csTag,"%s_org_remark_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csOrgRemark)) {
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csOrgRemark));
			}

//API: new_remark
			sprintf(csTag,"%s_new_remark_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csNewRemark)) {
DEBUGLOG(("Authorize()   [%s] = [%s]\n",csTag,csNewRemark));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize()   [%s] NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() [%s] NOT FOUND!!!\n");
				break;
			}


DEBUGLOG(("Call DBOLTransaction:GetTxnHeader\n"));
//Call DBOLTransaction::GetTxnHeader

			recordset_init(rsTmpOLTxnHeader,0);

			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","GetTxnHeader");
			iRet = (unsigned long)(*DBObjPtr)(csTxnId,rsTmpOLTxnHeader);

			if (iRet == PD_OK) {
				hTmp = RecordSet_GetFirst(rsTmpOLTxnHeader);
				while (hTmp && iRet==PD_OK) {

					if (GetField_CString(hTmp,"txn_code",&csTxnCode)) {
DEBUGLOG(("  txn_code = [%s]\n",csTxnCode));
					}

					hTmp = RecordSet_GetNext(rsTmpOLTxnHeader);
				}
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBOLTransaction:GetTxnHeader FAILED!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() Call DBOLTransaction:GetTxnHeader FAILED!!!\n");
				break;
			}


			if (iRet == PD_OK) {
				if (!strcmp(csTxnCode,PD_OL_SETTLEMENT_REQUEST)) {
					hash_init(hOLTxnRemarks,0);

DEBUGLOG(("Call DBOLTxnRemarks:Get\n"));
//Call DBOLTxnRemarks::Get
					DBObjPtr = CreateObj(DBPtr, "DBOLTxnRemarks","Get");
					iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,iSeq,hOLTxnRemarks);

					if (iDtlRet == PD_OK) {

						if (GetField_Char(hOLTxnRemarks,"status",&cTmp)) {
DEBUGLOG(("  status = [%c]\n",cTmp));
							if (cTmp != cStatus) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! status not sync with API:status [%c]\n",cStatus));
ERRLOG("TxnOmtByUsTAR:: status not sync with API:status [%c]\n",cStatus);
								break;
							}

							if (cTmp != PD_PROCESSING) {
								iNeedUpdateTxnDetail = PD_FALSE;
							}
						}

						if (GetField_Int(hOLTxnRemarks,"ar_ind",&cTmp)) {
DEBUGLOG(("  ar_ind = [%c]\n",cTmp));
							if (cTmp != cARInd) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! ar_ind not sync with API:ar_ind [%d]\n",cARInd));
ERRLOG("TxnOmtByUsTAR:: ar_ind not sync with API:ar_ind [%c]\n",cARInd);
								break;
							}
						}

						if (GetField_CString(hOLTxnRemarks,"sub_status",&csTmp)) {
DEBUGLOG(("  sub_status = [%s]\n",csTmp));
							if (strcmp(csTmp,csSubStatus)!= 0) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! sub_status not sync with API:sub_status [%s]\n",csSubStatus));
ERRLOG("TxnOmtByUsTAR:: sub_status not sync with API:sub_status [%s]\n",csSubStatus);
								break;
							}
						}

						if (GetField_Int(hOLTxnRemarks,"exec_seq",&iTmp)) {
DEBUGLOG(("  exec_seq = [%d]\n",iTmp));
							if (iTmp != iSeq) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! exec_seq not sync with API:seq [%d]\n",iSeq));
ERRLOG("TxnOmtByUsTAR:: exec_seq not sync with API:seq [%d]\n",iSeq);
								break;
							}
						}

						if (GetField_Int(hOLTxnRemarks,"maxseq",&iTmp)) {
DEBUGLOG(("  maxseq = [%d]\n",iTmp));
							if (iTmp == iSeq) {
								iNeedUpdateMerchSettDt = PD_TRUE;
							}
						}

						if (GetField_CString(hOLTxnRemarks,"remark",&csTmp)) {
DEBUGLOG(("  remark = [%s]\n",csTmp));
							//Verify DB remark = API: org_remark
							if (!strcmp(csTmp,csOrgRemark)) {
								//Call DBOLTxnRemarks::UpdateRemark
DEBUGLOG(("UPDATE DBOLTxnRemarks::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
								PutField_CString(hOLTxnRemarks,"txn_seq",csTxnId);
DEBUGLOG(("  exec_seq = [%d]\n",iSeq));
								PutField_Int(hOLTxnRemarks,"exec_seq",iSeq);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
								PutField_CString(hOLTxnRemarks,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csNewRemark));
								PutField_CString(hOLTxnRemarks,"update_user",csUser);

								DBObjPtr = CreateObj(DBPtr, "DBOLTxnRemarks","UpdateRemark");
								iDtlRet = (unsigned long)(*DBObjPtr)(hOLTxnRemarks);

								if (iDtlRet == PD_OK) {
DEBUGLOG(("  UPDATE SUCCESS!\n"));
								} else {
									iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBOLTxnRemarks::UpdateRemark FAILED!!\n"));
ERRLOG("TxnOmtByUsTAR:: call DBOLTxnRemarks::UpdateRemark FAILED!!\n");
									break;
								}

								sprintf(csTag,"%s||%d",csTxnId,iSeq);
								AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"OL_TXN_REMARKS",csTag,"otr_remark",csNewRemark,csOrgRemark);
							}
						}

					} else {
						iRet = iDtlRet;
DEBUGLOG(("Authorize()   Call DBOLTxnRemarks:Get FAILED!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() Call DBOLTxnRemarks:Get FAILED!!!\n");
						break;
					}


					if (iDtlRet == PD_OK && iNeedUpdateMerchSettDt) {
DEBUGLOG(("Call DBOLMerchantSettlementDetail:GetRemark\n"));
//Call DBOLMerchantSettlementDetail::GetRemark
						hash_init(hOLMerchantSettleDetail,0);

						DBObjPtr = CreateObj(DBPtr, "DBOLMerchantSettlementDetail","GetRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,hOLMerchantSettleDetail);

						if (iDtlRet == PD_OK) {

							if (GetField_CString(hOLMerchantSettleDetail,"remark",&csTmp)) {
DEBUGLOG(("  remark = [%s]\n",csTmp));
								//Verify DB remark = API: org_remark
								if (!strcmp(csTmp,csOrgRemark)) {
									//Call DBOLMerchantSettlementDetail::UpdateRemark
DEBUGLOG(("UPDATE DBOLMerchantSettlementDetail::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
									PutField_CString(hOLMerchantSettleDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
									PutField_CString(hOLMerchantSettleDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csNewRemark));
									PutField_CString(hOLMerchantSettleDetail,"update_user",csUser);


									DBObjPtr = CreateObj(DBPtr, "DBOLMerchantSettlementDetail","UpdateRemark");
									iDtlRet = (unsigned long)(*DBObjPtr)(hOLMerchantSettleDetail);

									if (iDtlRet == PD_OK) {
DEBUGLOG(("  UPDATE SUCCESS!\n"));
									} else {
										iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBOLMerchantSettlementDetail::UpdateRemark FAILED!!\n"));
ERRLOG("TxnOmtByUsTAR:: call DBOLMerchantSettlementDetail::UpdateRemark FAILED!!\n");
										break;
									}

									AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"OL_MERCHANT_SETTLEMENT_DETAIL",csTxnId,"osd_remark",csNewRemark,csOrgRemark);
								}
							}

						} else {
							iRet = iDtlRet;
DEBUGLOG(("Authorize()   Call DBOLMerchantSettlementDetail:GetRemark FAILED!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() Call DBOLMerchantSettlementDetail:GetRemark FAILED!!!\n");
							break;
						}
					} //End Call DBOLMerchantSettlementDetail:GetRemark

				} //End for txntype[OL Settlement Request (OSR)]
			}


			if (iRet == PD_OK && iNeedUpdateTxnDetail) {
				recordset_init(rsOLTxnDetail,0);
				recordset_init(rsOLTxnMiDetail,0);

DEBUGLOG(("Call DBOLTransaction:GetTxnDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,rsOLTxnDetail);

				if (iDtlRet == PD_OK) {
					hash_init(hOLTxnDetail,0);

					hTmp = RecordSet_GetFirst(rsOLTxnDetail);
					while (hTmp && iDtlRet==PD_OK) {
						//Call DBOLTransaction::UpdateTxnDetailRemark
DEBUGLOG(("UPDATE DBOLTransaction::UpdateTxnDetailRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
						PutField_CString(hOLTxnDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
						PutField_CString(hOLTxnDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csNewRemark));
						PutField_CString(hOLTxnDetail,"update_user",csUser);


						DBObjPtr = CreateObj(DBPtr, "DBOLTransaction","UpdateTxnDetailRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(hOLTxnDetail);

						if (iDtlRet == PD_OK) {
DEBUGLOG(("  UPDATE SUCCESS!\n"));
						} else {
							iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBOLTransaction::UpdateTxnDetailRemark FAILED!!\n"));
ERRLOG("TxnOmtByUsTAR:: call DBOLTransaction::UpdateTxnDetailRemark FAILED!!\n");
							break;
						}

						AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"OL_TXN_DETAIL",csTxnId,"otd_remark",csNewRemark,csOrgRemark);

						hTmp = RecordSet_GetNext(rsOLTxnDetail);
					}
				} else {
					iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBOLTransaction:GetTxnDetail FAILED!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() Call DBOLTransaction:GetTxnDetail FAILED!!!\n");
					break;
				}


DEBUGLOG(("Call DBOLTxnMiDetail:GetOLTxnMiDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnMiDetail","GetOLTxnMiDetail");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,rsOLTxnMiDetail);

				if (iDtlRet == PD_OK) {
					hash_init(hOLTxnMiDetail,0);

					hTmp = RecordSet_GetFirst(rsOLTxnMiDetail);
					while (hTmp && iDtlRet==PD_OK) {
						//Call DBTxnMiDetail::UpdateRemark
DEBUGLOG(("UPDATE DBOLTxnMiDetail::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
						PutField_CString(hOLTxnMiDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
						PutField_CString(hOLTxnMiDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csNewRemark));
						PutField_CString(hOLTxnMiDetail,"update_user",csUser);


						DBObjPtr = CreateObj(DBPtr, "DBOLTxnMiDetail","UpdateRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(hOLTxnMiDetail);

						if (iDtlRet == PD_OK) {
DEBUGLOG(("  UPDATE SUCCESS!\n"));
						} else {
							iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBOLTxnMiDetail::UpdateRemark FAILED!!\n"));
ERRLOG("TxnOmtByUsTAR:: call DBOLTxnMiDetail::UpdateRemark FAILED!!\n");
							break;
						}

						AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"OL_TXN_MI_DETAIL",csTxnId,"otm_remark",csNewRemark,csOrgRemark);

						hTmp = RecordSet_GetNext(rsOLTxnMiDetail);
					}
				} else {
					iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBOLTxnMiDetail:GetOLTxnMiDetail FAILED!!!\n"));
ERRLOG("TxnOmtByUsTAR:: Authorize() Call DBOLTxnMiDetail:GetOLTxnMiDetail FAILED!!!\n");
					break;
				}


			} //End Update OLTxnDetail / OLTxnMiDetail

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


	hash_destroy(hOLTxnRemarks);
	FREE_ME(hOLTxnRemarks);

	hash_destroy(hOLMerchantSettleDetail);
	FREE_ME(hOLMerchantSettleDetail);

	hash_destroy(hOLTxnDetail);
	FREE_ME(hOLTxnDetail);

	hash_destroy(hOLTxnMiDetail);
	FREE_ME(hOLTxnMiDetail);

	hash_destroy(hITTLog);
	FREE_ME(hITTLog);

	recordset_destroy(rsOLTxnMiDetail);
	FREE_ME(rsOLTxnMiDetail);

	recordset_destroy(rsOLTxnDetail);
	FREE_ME(rsOLTxnDetail);

	recordset_destroy(rsTmpOLTxnHeader);
	FREE_ME(rsTmpOLTxnHeader);

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
