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
#include "TxnMgtByUsTAR.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);

#define PD_DETAIL_TAG   "dt"

int AddTaskLog(hash_t* hITTLog, int iLogBatchSeq, char* csTaskAction, char cActionType, char* csObject, char* csKey, char* csField, char* csValue, char* csOldValue);

void TxnMgtByUsTAR(char cdebug)
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
	int	iUpdateCnt = 0;

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

	recordset_t *rsTmpTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTmpTxnHeader,0);

	recordset_t *rsTxnDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTxnDetail,0);

	recordset_t *rsTxnMiDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rsTxnMiDetail,0);
	
	hash_t *hTxnDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnDetail,0);
	
	hash_t *hTxnMiDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnMiDetail,0);
	
	hash_t *hMerchantSettleDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hMerchantSettleDetail,0);
	
	hash_t *hTxnRemarks = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnRemarks,0);
	
	hash_t *hITTLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hITTLog,0);



//API: total_cnt
	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
DEBUGLOG(("Authorize() total_cnt = [%d]\n",iCnt));
	} else {
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() total_cnt NOT FOUND!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() total_cnt NOT FOUND!!!\n");
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
ERRLOG("TxnMgtByUsTAR:: Authorize() [%s] NOT FOUND!!!\n");
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
ERRLOG("TxnMgtByUsTAR:: Authorize() [%s] NOT FOUND!!!\n");
				break;
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
				iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBTransaction:GetTxnHeader FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() Call DBTransaction:GetTxnHeader FAILED!!!\n");
				break;
			}


			if (iRet == PD_OK) {
				if (!strcmp(csTxnCode,PD_SETTLEMENT_REQUEST)) {
					hash_init(hTxnRemarks,0);

DEBUGLOG(("Call DBTxnRemarks:Get\n"));
//Call DBTxnRemarks::Get
					DBObjPtr = CreateObj(DBPtr, "DBTxnRemarks","Get");
					iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,iSeq,hTxnRemarks);

					if (iDtlRet == PD_OK) {

						if (GetField_Char(hTxnRemarks,"status",&cTmp)) {
DEBUGLOG(("  status = [%c]\n",cTmp));
							if (cTmp != cStatus) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! status not sync with API:status [%c]\n",cStatus));
ERRLOG("TxnMgtByUsTAR:: status not sync with API:status [%c]\n",cStatus);
								break;
							}
						}

						if (GetField_Int(hTxnRemarks,"ar_ind",&cTmp)) {
DEBUGLOG(("  ar_ind = [%c]\n",cTmp));
							if (cTmp != cARInd) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! ar_ind not sync with API:ar_ind [%d]\n",cARInd));
ERRLOG("TxnMgtByUsTAR:: ar_ind not sync with API:ar_ind [%c]\n",cARInd);
								break;
							}
						}

						if (GetField_CString(hTxnRemarks,"sub_status",&csTmp)) {
DEBUGLOG(("  sub_status = [%s]\n",csTmp));
							if (strcmp(csTmp,csSubStatus)!= 0) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! sub_status not sync with API:sub_status [%s]\n",csSubStatus));
ERRLOG("TxnMgtByUsTAR:: sub_status not sync with API:sub_status [%s]\n",csSubStatus);
								break;
							}
						}

						if (GetField_Int(hTxnRemarks,"exec_seq",&iTmp)) {
DEBUGLOG(("  exec_seq = [%d]\n",iTmp));
							if (iTmp != iSeq) {
								iDtlRet = INT_ERR;
DEBUGLOG(("  BREAK!! exec_seq not sync with API:seq [%d]\n",iSeq));
ERRLOG("TxnMgtByUsTAR:: exec_seq not sync with API:seq [%d]\n",iSeq);
								break;
							}
						}

						if (GetField_Int(hTxnRemarks,"maxseq_td",&iTmp)) {
DEBUGLOG(("  maxseq_td = [%d]\n",iTmp));
							if (iTmp != iSeq) {
								iNeedUpdateTxnDetail = PD_FALSE;
							}
						}

						if (GetField_Int(hTxnRemarks,"maxseq_sd",&iTmp)) {
DEBUGLOG(("  maxseq_sd = [%d]\n",iTmp));
							if (iTmp == iSeq) {
								iNeedUpdateMerchSettDt = PD_TRUE;
							}
						}

						if (GetField_CString(hTxnRemarks,"remark",&csTmp)) {
DEBUGLOG(("  remark = [%s]\n",csTmp));
							//Verify DB remark = API: org_remark
							if (!strcmp(csTmp,csOrgRemark)) {
								//Call DBTxnRemarks::UpdateRemark
DEBUGLOG(("UPDATE DBTxnRemarks::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
								PutField_CString(hTxnRemarks,"txn_seq",csTxnId);
DEBUGLOG(("  exec_seq = [%d]\n",iSeq));
								PutField_Int(hTxnRemarks,"exec_seq",iSeq);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
								PutField_CString(hTxnRemarks,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csUser));
								PutField_CString(hTxnRemarks,"update_user",csUser);

								DBObjPtr = CreateObj(DBPtr, "DBTxnRemarks","UpdateRemark");
								iDtlRet = (unsigned long)(*DBObjPtr)(hTxnRemarks);

								if (iDtlRet == PD_OK) {
									iUpdateCnt++;
DEBUGLOG(("  UPDATE SUCCESS!\n"));
								} else {
									iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBTxnRemarks::UpdateRemark FAILED!!\n"));
ERRLOG("TxnMgtByUsTAR:: call DBTxnRemarks::UpdateRemark FAILED!!\n");
									break;
								}

								sprintf(csTag,"%s||%d",csTxnId,iSeq);
								AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"TXN_REMARKS",csTag,"tr_remark",csNewRemark,csOrgRemark);
							}
						}

					} else {
						iRet = iDtlRet;
DEBUGLOG(("Authorize()   Call DBTxnRemarks:Get FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() Call DBTxnRemarks:Get FAILED!!!\n");
						break;
					}


					if (iDtlRet == PD_OK && iNeedUpdateMerchSettDt) {
DEBUGLOG(("Call DBMerchantSettlementDetail:GetRemark\n"));
//Call DBMerchantSettlementDetail::GetRemark
						hash_init(hMerchantSettleDetail,0);

						DBObjPtr = CreateObj(DBPtr, "DBMerchantSettlementDetail","GetRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,hMerchantSettleDetail);

						if (iDtlRet == PD_OK) {

							if (GetField_CString(hMerchantSettleDetail,"remark",&csTmp)) {
DEBUGLOG(("  remark = [%s]\n",csTmp));
								//Verify DB remark = API: org_remark
								if (!strcmp(csTmp,csOrgRemark)) {
									//Call DBMerchantSettlementDetail::UpdateRemark
DEBUGLOG(("UPDATE DBMerchantSettlementDetail::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
									PutField_CString(hMerchantSettleDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
									PutField_CString(hMerchantSettleDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csUser));
									PutField_CString(hMerchantSettleDetail,"update_user",csUser);


									DBObjPtr = CreateObj(DBPtr, "DBMerchantSettlementDetail","UpdateRemark");
									iDtlRet = (unsigned long)(*DBObjPtr)(hMerchantSettleDetail);

									if (iDtlRet == PD_OK) {
										iUpdateCnt++;
DEBUGLOG(("  UPDATE SUCCESS!\n"));
									} else {
										iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBMerchantSettlementDetail::UpdateRemark FAILED!!\n"));
ERRLOG("TxnMgtByUsTAR:: call DBMerchantSettlementDetail::UpdateRemark FAILED!!\n");
										break;
									}

									AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"MERCHANT_SETTLEMENT_DETAIL",csTxnId,"sd_remark",csNewRemark,csOrgRemark);
								}
							}

						} else {
							iRet = iDtlRet;
DEBUGLOG(("Authorize()   Call DBMerchantSettlementDetail:GetRemark FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() Call DBMerchantSettlementDetail:GetRemark FAILED!!!\n");
							break;
						}
					} //End Call DBMerchantSettlementDetail:GetRemark

				} //End for txntype[Settlement Request (STR)]
			}


			if (iRet == PD_OK && iNeedUpdateTxnDetail) {
				recordset_init(rsTxnDetail,0);
				recordset_init(rsTxnMiDetail,0);

DEBUGLOG(("Call DBTransaction:GetTxnDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,rsTxnDetail);

				if (iDtlRet == PD_OK) {
					hash_init(hTxnDetail,0);

					hTmp = RecordSet_GetFirst(rsTxnDetail);
					while (hTmp && iDtlRet==PD_OK) {
						//Call DBTransaction::UpdateTxnDetailRemark
DEBUGLOG(("UPDATE DBTransaction::UpdateTxnDetailRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
						PutField_CString(hTxnDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
						PutField_CString(hTxnDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csUser));
						PutField_CString(hTxnDetail,"update_user",csUser);


						DBObjPtr = CreateObj(DBPtr, "DBTransaction","UpdateTxnDetailRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(hTxnDetail);

						if (iDtlRet == PD_OK) {
							iUpdateCnt++;
DEBUGLOG(("  UPDATE SUCCESS!\n"));
						} else {
							iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBTransaction::UpdateTxnDetailRemark FAILED!!\n"));
ERRLOG("TxnMgtByUsTAR:: call DBTransaction::UpdateTxnDetailRemark FAILED!!\n");
							break;
						}

						AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"TXN_DETAIL",csTxnId,"td_remark",csNewRemark,csOrgRemark);

						hTmp = RecordSet_GetNext(rsTxnDetail);
					}
				} else {
					iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBTransaction:GetTxnDetail FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() Call DBTransaction:GetTxnDetail FAILED!!!\n");
					break;
				}


DEBUGLOG(("Call DBTxnMiDetail:GetTxnMiDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","GetTxnMiDetail");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTxnId,rsTxnMiDetail);

				if (iDtlRet == PD_OK) {
					hash_init(hTxnMiDetail,0);

					hTmp = RecordSet_GetFirst(rsTxnMiDetail);
					while (hTmp && iDtlRet==PD_OK) {
						//Call DBTxnMiDetail::UpdateRemark
DEBUGLOG(("UPDATE DBTxnMiDetail::UpdateRemark\n"));
DEBUGLOG(("  txn_id = [%s]\n",csTxnId));
						PutField_CString(hTxnMiDetail,"txn_seq",csTxnId);
DEBUGLOG(("  remark = [%s]\n",csNewRemark));
						PutField_CString(hTxnMiDetail,"remark",csNewRemark);
DEBUGLOG(("  update_user = [%s]\n",csUser));
						PutField_CString(hTxnMiDetail,"update_user",csUser);


						DBObjPtr = CreateObj(DBPtr, "DBTxnMiDetail","UpdateRemark");
						iDtlRet = (unsigned long)(*DBObjPtr)(hTxnMiDetail);

						if (iDtlRet == PD_OK) {
							iUpdateCnt++;
DEBUGLOG(("  UPDATE SUCCESS!\n"));
						} else {
							iRet = iDtlRet;
DEBUGLOG(("  BREAK!! call DBTxnMiDetail::UpdateRemark FAILED!!\n"));
ERRLOG("TxnMgtByUsTAR:: call DBTxnMiDetail::UpdateRemark FAILED!!\n");
							break;
						}

						AddTaskLog(hITTLog,iLogBatchSeq++,PD_ITT_ACTION_UPDATE_TXN_REMARK,PD_ITT_LOG_UPDATE,"TXN_MI_DETAIL",csTxnId,"tm_remark",csNewRemark,csOrgRemark);

						hTmp = RecordSet_GetNext(rsTxnMiDetail);
					}
				} else {
					iRet = INT_ERR;
DEBUGLOG(("Authorize()   Call DBTxnMiDetail:GetTxnMiDetail FAILED!!!\n"));
ERRLOG("TxnMgtByUsTAR:: Authorize() Call DBTxnMiDetail:GetTxnMiDetail FAILED!!!\n");
					break;
				}


			} //End Update TxnDetail / TxnMiDetail

DEBUGLOG(("END iCnt = [%d]\n",i));
		} //end loop for detail cnt
	}


	if (iRet == PD_OK) {
		if (iUpdateCnt > 0) {
DEBUGLOG(("UpdateTaskLogByBatch()\n"));
			PutField_Int(hITTLog,"ret_code",iRet);
			DBObjPtr = CreateObj(DBPtr,"DBIttTaskLog","UpdateRetCodeByBatch");
			iRet = (unsigned long)(*DBObjPtr)(hITTLog);
			if (iRet != PD_OK) {
DEBUGLOG(("  FAILURE!!! iRet = [%d]\n",iRet));
			} else {
DEBUGLOG(("  SUCCESS!!!\n"));
			}
		} else {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("No data update!\n"));
ERRLOG("TxnMgtByUsTAR:: No data update!\n");
		}
	}


	hash_destroy(hTxnRemarks);
	FREE_ME(hTxnRemarks);

	hash_destroy(hMerchantSettleDetail);
	FREE_ME(hMerchantSettleDetail);

	hash_destroy(hTxnDetail);
	FREE_ME(hTxnDetail);

	hash_destroy(hTxnMiDetail);
	FREE_ME(hTxnMiDetail);

	hash_destroy(hITTLog);
	FREE_ME(hITTLog);

	recordset_destroy(rsTxnMiDetail);
	FREE_ME(rsTxnMiDetail);

	recordset_destroy(rsTxnDetail);
	FREE_ME(rsTxnDetail);

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
