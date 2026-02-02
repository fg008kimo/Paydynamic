/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/30              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMinByUsVRO.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

int	CheckBatchIdValid(hash_t* hRls);
int	CheckBatchDtValid(hash_t* hRls);
int	ProcessVoidTxn(hash_t* hContext, const hash_t* hRequest, hash_t* hRls);
int	CallUpdateEntityBalance(hash_t *hData);


void TxnMinByUsVRO(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
        int	iRet = PD_OK;

	char	*csTmp = NULL;
	char	*csNewTxnId = NULL;

	hash_t *hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData, 0);

DEBUGLOG(("Authorize::TxnMinByUsVRO Begin\n"));

/* txn_seq */
        if (GetField_CString(hContext,"txn_seq",&csNewTxnId)) {
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csNewTxnId));
		PutField_CString(hData,"txn_seq",csNewTxnId);
        } else {
DEBUGLOG(("Authorize::txn_seq not found!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::txn_seq not found!!\n");
                iRet = INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* batch_id */
        if (GetField_CString(hContext,"batch_id",&csTmp)) {
DEBUGLOG(("Authorize::batch_id = [%s]\n",csTmp));
		PutField_CString(hData,"batch_id",csTmp);
        } else {
DEBUGLOG(("Authorize::batch_id not found!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::batch_id not found!!\n");
                iRet = INT_MI_BATCH_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* org_batch_id */
        if (GetField_CString(hContext,"org_batch_id",&csTmp)) {
DEBUGLOG(("Authorize::org_batch_id = [%s]\n",csTmp));
		PutField_CString(hData,"org_batch_id",csTmp);
        } else {
DEBUGLOG(("Authorize::batch_id not found!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::batch_id not found!!\n");
                iRet = INT_MI_BATCH_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* process_type */
        if (GetField_CString(hContext,"mini_txn_type",&csTmp)) {
DEBUGLOG(("Authorize::process_type = [%s]\n",csTmp));
		PutField_CString(hData,"process_type",csTmp);
        } else {
DEBUGLOG(("Authorize::process_type not found!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::process_type not found!!\n");
                iRet = INT_MI_PROCESS_TYPE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* org_process_type */
        if (GetField_CString(hContext,"org_process_type",&csTmp)) {
DEBUGLOG(("Authorize::org_process_type = [%s]\n",csTmp));
		PutField_CString(hData,"org_process_type",csTmp);
        } else {
DEBUGLOG(("Authorize::process_type not found!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::process_type not found!!\n");
                iRet = INT_MI_PROCESS_TYPE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if (GetField_CString(hContext,"add_user",&csTmp)) {
DEBUGLOG(("Authorize::add_user = [%s]\n",csTmp));
		PutField_CString(hData,"add_user",csTmp);
		PutField_CString(hData,"update_user",csTmp);
        }

/* update_user */
        if (GetField_CString(hContext,"update_user",&csTmp)) {
DEBUGLOG(("Authorize::update_user = [%s]\n",csTmp));
        }

	// Check Org Batch Id and Void Batch Id Valid	
	if (iRet == PD_OK) {
		iRet = CheckBatchIdValid(hData);
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	// Check Org Batch Detail: Txn substatus Valid
	if (iRet == PD_OK) {
		iRet = CheckBatchDtValid(hData);
		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	// Process Void Rsp Delivery Out
	if (iRet == PD_OK) {
                iRet = ProcessVoidTxn(hContext,hRequest,hData);
        }


	hash_destroy(hData);
        FREE_ME(hData);

DEBUGLOG(("TxnMinByUsVRO Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


int     CheckBatchIdValid(hash_t* hRls)
{
	int     iRet = PD_OK;
	int	iDtlRet = PD_NOT_FOUND;

	char    *csOrgBatchId = NULL;
	char    *csProcessType = NULL;
	char    *csOrgProcessType = NULL;

	char	cStatus;

	hash_t  *hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec,0);

/* org_batch_id */
        if (GetField_CString(hRls,"org_batch_id",&csOrgBatchId)) {
DEBUGLOG(("CheckBatchIdValid::org_batch_id = [%s]\n",csOrgBatchId));
        }

/* process_type */
        if (GetField_CString(hRls,"process_type",&csProcessType)) {
DEBUGLOG(("CheckBatchIdValid::process_type = [%s]\n",csProcessType));

		// Compare process type - PD_MI_TXN_TYPE_VOID_DELIV_IN
		if (!strcmp(csProcessType, PD_MI_TXN_TYPE_VOID_DELIV_IN)) {
			/*Do Nothing*/
		} else {
DEBUGLOG(("CheckBatchIdValid::process_type invalid!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::process_type invalid!!\n");
			iRet = INT_ERR;
                }
        }

/* org_process_type */
        if (GetField_CString(hRls,"org_process_type",&csOrgProcessType)) {
DEBUGLOG(("CheckBatchIdValid::org_process_type = [%s]\n",csOrgProcessType));
		
		// Compare org process type - PD_MI_TXN_TYPE_DELIV_IN
                if (!strcmp(csOrgProcessType, PD_MI_TXN_TYPE_DELIV_IN)) {
			/*Do Nothing*/
		} else {
DEBUGLOG(("CheckBatchIdValid::org_process_type invalid!!\n"));
ERRLOG("TxnMinByUsVRO::Authorize::org_process_type invalid!!\n");
                        iRet = INT_ERR;
                }
        }
	
	// Check Org Batch Id
	if (iRet == PD_OK) {
		
DEBUGLOG(("CheckBatchIdValid::Call DBMiBatchHeader:: GetBatchHeader\n"));
          	DBObjPtr = CreateObj(DBPtr,"DBMiBatchHeader","GetBatchHeader");
              	iDtlRet = (unsigned long)(*DBObjPtr)(csOrgBatchId,hRec);
              	if (iDtlRet == PD_FOUND) {

/* status */
			if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("CheckBatchIdValid::status = [%c]\n",cStatus));
					
				// Compare Status - PD_MI_BATCH_STATUS_INOPERATIVE
				if (cStatus == PD_MI_BATCH_STATUS_INOPERATIVE) {
DEBUGLOG(("CheckBatchIdValid::Call DBMiBatchHeader:: GetBatchHeader batch is inoperative\n"));
ERRLOG("TxnMinByUsVRO::Authorize::Call DBMiBatchHeader:: GetBatchHeader batch is inoperative\n");
                 		       iRet = INT_ERR;
                		}				
			} else {
DEBUGLOG(("CheckBatchIdValid::Call DBMiBatchHeader:: GetBatchHeader status not found\n"));
ERRLOG("TxnMinByUsVRO::Authorize::Call DBMiBatchHeader:: GetBatchHeader status not found\n");
                              	iRet = INT_ERR;
			}
		} else {
DEBUGLOG(("CheckBatchIdValid:::Call DBMiBatchHeader:: GetBatchHeader Failed\n"));
ERRLOG("TxnMinByUsVRO::Authorize:::Call DBMiBatchHeader:: GetBatchHeader Failed\n");
			iRet = INT_ERR;
		}
	}	

	hash_destroy(hRec);
        FREE_ME(hRec);

DEBUGLOG(("CheckBatchIdValid Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


int     CheckBatchDtValid(hash_t* hRls)
{
	int     iRet = PD_OK;
	int	iDtlRet = PD_NOT_FOUND;

	int	iCnt = 0;
	char	csTag[PD_TAG_LEN+1];
	char    *csOrgBatchId = NULL;
	char	*csSubStatus = NULL;
	char	*csTmp = NULL;
	char	*csTmpTxn = NULL;

	hash_t	*hMiBatchDetail;
	recordset_t *rMiBatchDetail;
	rMiBatchDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rMiBatchDetail,0);

	hash_t	*hTxnHeader;
	recordset_t *rTxnHeader;
	rTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnHeader,0);

	hash_t	*hTxnMiDetail;
	recordset_t *rTxnMiDetail;
	rTxnMiDetail = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnMiDetail,0);

/* org_batch_id */
        if (GetField_CString(hRls,"org_batch_id",&csOrgBatchId)) {
DEBUGLOG(("CheckBatchDtValid::org_batch_id = [%s]\n",csOrgBatchId));
        }

DEBUGLOG(("CheckBatchDtValid::Call DBMiBatchDetail:: GetAllDetailByBatchId\n"));
	DBObjPtr = CreateObj(DBPtr,"DBMiBatchDetail","GetAllDetailByBatchId");
	iDtlRet = (unsigned long)(*DBObjPtr)(csOrgBatchId,rMiBatchDetail);

	if (iDtlRet != PD_FOUND) {
DEBUGLOG(("CheckBatchDtValid:: DBMiBatchDetail:GetAllDetailByBatchId() not found\n"));
ERRLOG("TxnMinByUsVRO:Authorize:: DBMiBatchDetail:GetAllDetailByBatchId() not found\n");
		iRet = INT_ERR;
	} else {
DEBUGLOG(("CheckBatchDtValid:: Found\n"));
		iDtlRet = PD_OK;
		hMiBatchDetail = RecordSet_GetFirst(rMiBatchDetail);

		while ((hMiBatchDetail) && (iDtlRet==PD_OK)) {
			iCnt += 1;
DEBUGLOG(("CheckBatchDtValid:: count = [%d]\n",iCnt));
	
			if (GetField_CString(hMiBatchDetail,"entity_id",&csTmp)) {
				sprintf(csTag,"org_b%d_entityid",iCnt);
				PutField_CString(hRls,csTag,csTmp);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmp));
			}

			if (GetField_CString(hMiBatchDetail,"party_type",&csTmp)) {
				sprintf(csTag,"org_b%d_partytype",iCnt);
				PutField_CString(hRls,csTag,csTmp);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmp));
			}

			if (GetField_CString(hMiBatchDetail,"party_id",&csTmp)) {
				sprintf(csTag,"org_b%d_partyid",iCnt);
				PutField_CString(hRls,csTag,csTmp);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmp));
			}

			if (GetField_CString(hMiBatchDetail,"txn_id",&csTmpTxn)) {
/*
				sprintf(csTag,"org_b%d_txn_id",iCnt);
				PutField_CString(hRls,csTag,csTmpTxn);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmpTxn));
*/
				RecordSet_Destroy(rTxnHeader);
				recordset_init(rTxnHeader,0);

				//Call DBTransaction::GetTxnHeader
DEBUGLOG(("CheckBatchDtValid::Call DBTransaction:: GetTxnHeader\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
				iDtlRet = (unsigned long)(*DBObjPtr)(csTmpTxn,rTxnHeader);

				if (iDtlRet != PD_OK) {
DEBUGLOG(("CheckBatchDtValid:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsVRO:Authorize:: DBTransaction:GetTxnHeader() not found\n");
				} else {
					hTxnHeader = RecordSet_GetFirst(rTxnHeader);
DEBUGLOG(("CheckBatchDtValid:: txn_id = [%s]\n",csTmpTxn));

					//Put TxnId for later use
					sprintf(csTag,"org_b%d_txn_id",iCnt);
					PutField_CString(hRls,csTag,csTmpTxn);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmpTxn));

					//Check TxnCode
					if (GetField_CString(hTxnHeader,"txn_code",&csTmp)) {
DEBUGLOG(("CheckBatchDtValid:: txn_code = [%s]\n",csTmp));

						sprintf(csTag,"org_b%d_txncode",iCnt);
						PutField_CString(hRls,csTag,csTmp);
DEBUGLOG(("CheckBatchDtValid:: Set [%s] = [%s]\n",csTag,csTmp));

						if (GetField_CString(hTxnHeader,"sub_status",&csSubStatus)) {
DEBUGLOG(("CheckBatchDtValid:: sub_status = [%s]\n",csSubStatus));
						} else {
DEBUGLOG(("CheckBatchDtValid:: sub_status not found!\n"));
ERRLOG("TxnMinByUsVRO::CheckBatchDtValid:: sub_status not found!\n");
							iDtlRet = INT_ERR;
						}

						// DLO:	(1)SubStatus = 118
						//	(2)NextTxnId = NULL
						if (!strcmp(csTmp,PD_MI_TXN_CODE_RSP_DELIVERY_IN)) {
							if (strcmp(csSubStatus,PD_APPROVED)) {
DEBUGLOG(("CheckBatchDtValid:: Invalud sub_status!!\n"));
ERRLOG("TxnMinByUsVRO::CheckBatchDtValid:: Invalud sub_status!!\n");
								iDtlRet = INT_ERR;
							}
							if (iDtlRet == PD_OK) {
DEBUGLOG(("CheckBatchDtValid:: Call DBTxnMiDetail::GetTxnMiDetail\n"));
								DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","GetTxnMiDetail");
								iDtlRet = (unsigned long)(*DBObjPtr)(csTmpTxn,rTxnMiDetail);

								if (iDtlRet != PD_OK) {
DEBUGLOG(("CheckBatchDtValid:: DBTxnMiDetail:GetTxnMiDetail() not found\n"));
ERRLOG("TxnMinByUsVRO:Authorize:: DBTxnMiDetail:GetTxnMiDetail() not found\n");
								} else {
									hTxnMiDetail = RecordSet_GetFirst(rTxnMiDetail);

									if (GetField_CString(hTxnMiDetail,"next_grp_txn_id",&csTmp)) {
DEBUGLOG(("CheckBatchDtValid:: next_grp_txn_id is not null!!\n"));
ERRLOG("TxnMinByUsVRO:Authorize:: next_grp_txn_id is not null!!\n");
										iDtlRet = INT_ERR;
									}
								}
							}
						}
						// PST:	(1)SubStatus = 129
						else if (!strcmp(csTmp,PD_PSP_SETTLEMENT)) {
							if (strcmp(csSubStatus,PD_DELIVERING)) {
DEBUGLOG(("CheckBatchDtValid:: Invalud sub_status!!\n"));
ERRLOG("TxnMinByUsVRO::CheckBatchDtValid:: Invalud sub_status!!\n");
								iDtlRet = INT_ERR;
							}
						}
						// RIT: (1)SubStatus = 129
						else if (!strcmp(csTmp,PD_MI_TXN_CODE_RSP_IN_TRANSIT)) {
							if (strcmp(csSubStatus,PD_DELIVERING)) {
DEBUGLOG(("CheckBatchDtValid:: Invalud sub_status!!\n"));
ERRLOG("TxnMinByUsVRO::CheckBatchDtValid:: Invalud sub_status!!\n");
								iDtlRet = INT_ERR;
							}
						}
					}
				}

				if (iDtlRet != PD_OK) {
					iRet = INT_ERR;
					break;
				}
			}

			hMiBatchDetail = RecordSet_GetNext(rMiBatchDetail);
		}

		PutField_Int(hRls,"org_batch_dt_cnt",iCnt);
	}

	RecordSet_Destroy(rMiBatchDetail);
	FREE_ME(rMiBatchDetail);

	RecordSet_Destroy(rTxnHeader);
	FREE_ME(rTxnHeader);

DEBUGLOG(("CheckBatchDtValid Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int     ProcessVoidTxn(hash_t* hContext, const hash_t* hRequest, hash_t* hRls)
{
	int     iRet = PD_OK;

	int	iBatchDtCnt = 0;
	int	iTmp = 0;
        double  dTmp = 0.0;
        double  dNetAmt = 0.0;
        double  dTxnAmt = 0.0;
        double  dCostAmt = 0.0;
        double  dOpenAcctBal = 0.0;
        double  dOpenIntransit = 0.0;
        double  dOpenArBal = 0.0;
	char	cTmp;
	char	csTag[PD_TAG_LEN+1];
        char    *csTmp = NULL;
        char    *csTmpTxn = NULL;
        char    *csNewTxnId = NULL;
	char	*csEntityId = NULL;
	char	*csPartyType = NULL;
	char	*csPartyId = NULL;

	hash_t 	*hBatchRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBatchRec, 0);

DEBUGLOG(("===== PrcoessVoidTxn ===== START!!\n"));


/* txn_seq */
        if (GetField_CString(hContext, "txn_seq", &csNewTxnId)) {
DEBUGLOG(("ProcessVoidTxn:: txn_seq [%s]\n", csNewTxnId));
	}

	// Txn Header
	if (iRet == PD_OK) {
		// status
                PutField_Char(hContext,"status",PD_COMPLETE);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: status [%c]\n", PD_COMPLETE));

		// ar_ind
                PutField_Char(hContext,"ar_ind",PD_COMPLETE);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: status [%c]\n", PD_COMPLETE));

		// sub_status
                PutField_CString(hContext,"sub_status",PD_APPROVED);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: sub_status [%s]\n", PD_APPROVED));

		// txn_code
                PutField_CString(hContext, "txn_code", PD_MI_TXN_CODE_VOID_RSP_DELIVERY_IN);
                PutField_CString(hContext, "new_txn_code", PD_MI_TXN_CODE_VOID_RSP_DELIVERY_IN);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: txn_code [%s]\n", PD_MI_TXN_CODE_VOID_RSP_DELIVERY_IN));

		// process_type
                PutField_CString(hContext,"process_code", PD_PROCESS_CODE_DEF);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: process_code [%s]\n", PD_PROCESS_CODE_DEF));

		// process_code
                PutField_CString(hContext,"process_type", PD_PROCESS_TYPE_DEF);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: process_type [%s]\n", PD_PROCESS_TYPE_DEF));

		// PHDATE
                if (GetField_CString(hContext,"PHDATE",&csTmp)) {
                        PutField_CString(hContext,"txn_date",csTmp);
                        PutField_CString(hContext,"report_date",csTmp);
DEBUGLOG(("ProcessVoidTxn (TxnLog):: PHDATE [%s]\n", csTmp));
                }

		// txn_amt
                if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: txn_amt = [%lf]\n",dTmp));
                }

		// net_amt
                if (GetField_Double(hContext,"net_amt",&dNetAmt)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: net_amt = [%lf]\n",dNetAmt));
                }

		// net_ccy
                if (GetField_CString(hContext,"net_ccy",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: net_ccy = [%s]\n",csTmp));
                }

		// ex_supplier
		if (GetField_Char(hContext,"ex_supplier",&cTmp)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: ex_supplier [%c]\n", cTmp));
		}

		// ex_rate
                if (GetField_Double(hContext,"ex_rate",&dTmp)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: ex_rate = [%lf]\n",dTmp));
		}
        }

	// Txn Detail
	if (iRet == PD_OK) {
		// txn_country
                if (GetField_CString(hContext, "txn_country", &csTmp)) {
DEBUGLOG(("ProcessVoidTxn (TxnLog):: txn_country = [%s]\n", csTmp));
                }
        }

	// Txn Mi Detail
	if (iRet == PD_OK) {

		// entity_id
                if (GetField_CString(hContext,"entity_id",&csEntityId)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: entity_id = [%s]\n", csEntityId));
                }

		// party_type
                if (GetField_CString(hContext,"party_type",&csPartyType)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: party_type = [%s]\n", csPartyType));
                }

		// party_id
                if (GetField_CString(hContext,"party_id",&csPartyId)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: party_id = [%s]\n", csPartyId));
                }

		// txn_ccy
                if (GetField_CString(hContext,"txn_ccy",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: txn_ccy = [%s]\n", csTmp));
                        PutField_CString(hContext,"ccy",csTmp);
                }

		// txn_country
                if (GetField_CString(hContext,"txn_country",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: txn_country = [%s]\n", csTmp));
                        PutField_CString(hContext,"country",csTmp);
                }

		// txn_product
                if (GetField_CString(hContext,"txn_product",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: txn_product = [%s]\n", csTmp));
                }

		// cost_rate
                if (GetField_Double(hContext,"cost_rate",&dTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: cost_rate = [%lf]\n", dTmp));
                }

		// actual_cost
                if (GetField_Double(hContext,"actual_cost",&dCostAmt)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: actual_cost = [%lf]\n", dCostAmt));
                }

		// remittance_slip_date
                if (GetField_CString(hContext,"remittance_slip_date",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: remittance_slip_date = [%s]\n", csTmp));
                }

		// remit_rate
                if (GetField_Double(hContext,"remit_rate",&dTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: remit_rate = [%lf]\n", dTmp));
                }

		// converted_ccy
                if (GetField_CString(hContext,"converted_ccy",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: converted_ccy = [%s]\n", csTmp));
                }

		// converted_amount
                if (GetField_Double(hContext,"converted_amount",&dTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: converted_amount = [%lf]\n", dTmp));
                }

		// entity_ccy
                if (GetField_CString(hContext,"entity_ccy",&csTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: entity_ccy = [%s]\n", csTmp));
                }

		// entity_txn_amount
                if (GetField_Double(hContext,"entity_txn_amount",&dTxnAmt)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: entity_txn_amount = [%f]\n", dTxnAmt));
                }

		// acr_prorata
		if (GetField_Int(hContext,"acr_prorata",&iTmp)) {
DEBUGLOG(("ProcessVoidTxn::Call TxnMiDetail:GetTxnMiDetail: acr_prorata = [%d]\n", iTmp));
       		}
	}


	//To Do: DR Acct Balance (TxnAmt)
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - DR AcctBal\n"));

		//update_element (Set PD_FALSE for void case)
		PutField_Int(hContext, "update_element", PD_FALSE);

		//amt_type
		PutField_CString(hContext, "amt_type", PD_DR);
DEBUGLOG(("ProcessVoidTxn::amt_type = [%s]\n",PD_DR));

		//bal_type
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_ACCT_BAL);
DEBUGLOG(("ProcessVoidTxn::bal_type = [%c]\n",PD_MI_ENTITY_POOL_ACCT_BAL));

		//cost_amt
		RemoveField_Double(hContext, "cost_amt");

		//Update Entity Balance
		iRet = CallUpdateEntityBalance(hContext);
DEBUGLOG(("ProcessVoidTxn::CallUpdateEntityBalance() ret [%d]\n",iRet));

		//To record down open_acct_bal, open_intransit, open_ar_bal
		if (!GetField_Double(hContext,"open_acct_bal",&dOpenAcctBal)) {
			iRet = INT_ERR;
		}
		if (!GetField_Double(hContext,"open_intransit",&dOpenIntransit)) {
			iRet = INT_ERR;
		}
		if (!GetField_Double(hContext,"open_ar_bal",&dOpenArBal)) {
			iRet = INT_ERR;
		}

		if (iRet == PD_OK) {
			BOObjPtr = CreateObj(BOPtr,"BOTxnElements","VoidOrgTxnElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize:: BOTxnElements:VoidOrgTxnElements iRet = [%d]\n",iRet));
		}
	}


	//To Do: CR Intransit Pool (TxnAmt + CostAmt)
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - CR Intransit\n"));

		//update_element (Set PD_FALSE for void case)
		PutField_Int(hContext, "update_element", PD_FALSE);

		//amt_type
		PutField_CString(hContext, "amt_type", PD_CR);
DEBUGLOG(("ProcessVoidTxn::amt_type = [%s]\n",PD_CR));

		//bal_type
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_INTRANSIT);
DEBUGLOG(("ProcessVoidTxn::bal_type = [%c]\n",PD_MI_ENTITY_POOL_INTRANSIT));

		//txn_amt
		PutField_Double(hContext, "txn_amt", dNetAmt);
DEBUGLOG(("ProcessVoidTxn::cost_amt = [%lf]\n",dNetAmt));

		//Update Entity Balance
		iRet = CallUpdateEntityBalance(hContext);
DEBUGLOG(("ProcessVoidTxn::CallUpdateEntityBalance() ret [%d]\n",iRet));

		if (iRet == PD_OK) {
			BOObjPtr = CreateObj(BOPtr,"BOTxnElements","VoidOrgTxnElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("Authorize:: BOTxnElements:VoidOrgTxnElements iRet = [%d]\n",iRet));
		}
	}


	//Reset hContext
	PutField_Double(hContext,"cost_amt",dCostAmt);
	PutField_Double(hContext,"txn_amt",dTxnAmt);


	//To Do: Add TxnDetail
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - Add TxnDetail\n"));

		//Call DBTransaction:AddDetail()
DEBUGLOG(("ProcessVoidTxn::Call DBTransaction::AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		iRet = (unsigned long)(*DBObjPtr)(hContext);

		if (iRet != PD_OK) {
DEBUGLOG(("Call DBTransaction:AddDetail FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsVRO::Call DBTransaction:AddDetail FAILED!! ret [%d]\n",iRet);
		} else {
DEBUGLOG(("Call DBTransaction:AddDetail ret [%d]\n",iRet));
		}

	}


	//To Do: Add TxnMiDetail
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - Add TxnMiDetail\n"));

		//Put Open Balance into hContext
		PutField_Double(hContext,"open_acct_bal",dOpenAcctBal);
		PutField_Double(hContext,"open_intransit",dOpenIntransit);
		PutField_Double(hContext,"open_ar_bal",dOpenArBal);

		PutField_CString(hContext,"party_type",PD_MI_ENTITY_RSP);

		//Call DBTxnMiDetail:Add()
DEBUGLOG(("ProcessVoidTxn::Call DBTxnMiDetail::Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","Add");
		iRet = (unsigned long)(*DBObjPtr)(hContext);

		if (iRet != PD_OK) {
DEBUGLOG(("Call DBTxnMiDetail:Add FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsVRO::Call DBTxnMiDetail:Add FAILED!! ret [%d]\n",iRet);
		} else {
DEBUGLOG(("Call DBTxnMiDetail:Add ret [%d]\n",iRet));
		}

	}


	//To Do: Add MiTxnLog
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - Add MiTxnLog\n"));

DEBUGLOG(("ProcessVoidTxn::Call DBTransaction:: AddMiTxnLog\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddMiTxnLog");
		iRet = (unsigned long)(*DBObjPtr)(csNewTxnId);

		if (iRet != PD_OK) {
DEBUGLOG(("Call DBTransaction:: AddMiTxnLog Failed\n"));
ERRLOG("TxnMinByUsVRO::Call DBTransaction:: AddMiTxnLog Failed\n");
		} else {
DEBUGLOG(("Call DBTransaction:: AddMiTxnLog ret [%d]\n",iRet));
		}
	}


	//To Do: Add MiBatchHeader
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - AddMiBatchHeader\n"));

		if (GetField_CString(hContext,"batch_id",&csTmp)) {
			PutField_CString(hBatchRec,"batch_id",csTmp);
DEBUGLOG(("ProcessVoidTxn::batch_id = [%s]\n",csTmp));
		}
		if (GetField_CString(hContext,"mini_txn_type",&csTmp)) {
			PutField_CString(hBatchRec,"process_type",csTmp);
DEBUGLOG(("ProcessVoidTxn::process_type = [%s]\n",csTmp));
		}
		PutField_Char(hBatchRec,"status",PD_MI_BATCH_STATUS_NORMAL);
DEBUGLOG(("ProcessVoidTxn::status = [%c]\n",PD_MI_BATCH_STATUS_NORMAL));
		if (GetField_CString(hContext,"add_user",&csTmp)) {
			PutField_CString(hBatchRec,"add_user",csTmp);
DEBUGLOG(("ProcessVoidTxn::add_user = [%s]\n",csTmp));
		}

DEBUGLOG(("ProcessVoidTxn::Call MiBatchHeader::Add\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchHeader", "Add");
		iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
DEBUGLOG(("Call MiBatchHeader::Add ret [%d]\n",iRet));
		if (iRet != PD_OK) {
DEBUGLOG(("Call MiBatchHeader::Add FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsDLO::Call MiBatchHeader::Add FAILED!! ret [%d]\n",iRet);
		}

	}


	//To Do: Add MiBatchDetail (New Create Txn)
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - Add MiBatchDetail\n"));

		iBatchDtCnt += 1;
		if (GetField_CString(hContext,"batch_id",&csTmp)) {
			PutField_CString(hBatchRec,"batch_id",csTmp);
		}

		PutField_Int(hBatchRec,"seq",iBatchDtCnt);
DEBUGLOG(("ProcessVoidTxn:: seq = [%d]\n",iBatchDtCnt));

		PutField_CString(hBatchRec,"entity_id",csEntityId);
DEBUGLOG(("ProcessVoidTxn:: entity_id = [%s]\n",csEntityId));

		PutField_CString(hBatchRec,"party_type",csPartyType);
DEBUGLOG(("ProcessVoidTxn:: party_type = [%s]\n",csPartyType));

		PutField_CString(hBatchRec,"party_id",csPartyId);
DEBUGLOG(("ProcessVoidTxn:: party_id = [%s]\n",csPartyId));

		PutField_CString(hBatchRec,"txn_id",csNewTxnId);
DEBUGLOG(("ProcessVoidTxn:: txn_id = [%s]\n",csNewTxnId));

		PutField_Char(hBatchRec,"txn_oper_ind",PD_MI_BATCH_TXN_OPER_INSERT);
DEBUGLOG(("ProcessVoidTxn:: txn_oper_ind = [%c]\n",PD_MI_BATCH_TXN_OPER_INSERT));


DEBUGLOG(("ProcessVoidTxn::Call MiBatchDetail: Add \n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
		iRet = (unsigned long)(*DBObjPtr)(hBatchRec);

		if (iRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("ProcessVoidTxn::Call MiBatchDetail:: Add Failed ret = [%d]\n",iRet));
		}

	}


	//To Do: Update Original Batch All Txn
	//	 Insert into batch detail
	if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: ToDo - Update Original Batch Transaction, Add MiBatchDetail\n"))

		hash_t* hTxnHeader = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTxnHeader,0);

		if (GetField_Int(hRls,"org_batch_dt_cnt",&iTmp)) {
DEBUGLOG(("ProcessVoidTxn:: [org_batch_dt_cnt] = [%d]\n",iTmp));

			int i;
			for (i=1;i<=iTmp;i++) {

				hash_destroy(hTxnHeader);
				hash_init(hTxnHeader,0);

				sprintf(csTag,"org_b%d_txn_id",i);
				if (GetField_CString(hRls,csTag,&csTmpTxn)) {
DEBUGLOG(("ProcessVoidTxn:: [%s] = [%s]\n",csTag,csTmpTxn));
					PutField_CString(hTxnHeader,"txn_seq",csTmpTxn);
DEBUGLOG(("ProcessVoidTxn:: txn_seq = [%s]\n",csTmpTxn));
				} else {
DEBUGLOG(("ProcessVoidTxn:: [%s] NOT FOUND!!\n",csTag));
				}

				if (GetField_CString(hContext,"update_user",&csTmp)) {
					PutField_CString(hTxnHeader,"update_user",csTmp);
DEBUGLOG(("ProcessVoidTxn:: update_user = [%s]\n",csTmp));
				}

				sprintf(csTag,"org_b%d_txncode",i);
				if (GetField_CString(hRls,csTag,&csTmp)) {
DEBUGLOG(("ProcessVoidTxn:: [%s] = [%s]\n",csTag,csTmp));

					//DLO: (1)Status = R; SubStatus = 130
					if (!strcmp(csTmp,PD_MI_TXN_CODE_RSP_DELIVERY_IN)) {
						PutField_Char(hTxnHeader,"status",PD_REVERSED);
						PutField_CString(hTxnHeader,"sub_status",PD_UNDO);
DEBUGLOG(("ProcessVoidTxn:: sub_status = [%s] for txncode [%s]\n",PD_UNDO,PD_MI_TXN_CODE_RSP_DELIVERY_IN));
					}
					//PST: (1)SubStatus = 118
					else if (!strcmp(csTmp,PD_PSP_SETTLEMENT)) {
						PutField_CString(hTxnHeader,"sub_status",PD_APPROVED);
DEBUGLOG(("ProcessVoidTxn:: sub_status = [%s] for txncode [%s]\n",PD_APPROVED,PD_PSP_SETTLEMENT));
					}
					//RIT: (1)SubStatus = 118
					else if (!strcmp(csTmp,PD_MI_TXN_CODE_RSP_IN_TRANSIT)) {
						PutField_CString(hTxnHeader,"sub_status",PD_APPROVED);
DEBUGLOG(("ProcessVoidTxn:: sub_status = [%s] for txncode [%s]\n",PD_APPROVED,PD_MI_TXN_CODE_RSP_IN_TRANSIT));

						//Call DBTxnMiDetail::UpdateNextGrpTxnId2NULL
DEBUGLOG(("ProcessVoidTxn:: Call DBTxnMiDetail::UpdateNextGrpTxnId2NULL\n"));
						DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","UpdateNextGrpTxnId2NULL");
						iRet = (unsigned long)(*DBObjPtr)(hTxnHeader);
DEBUGLOG(("Call DBTxnMiDetail:Update iRet = [%d]\n",iRet));

					}
				}

				if (iRet == PD_OK) {

DEBUGLOG(("ProcessVoidTxn:: Call DBTransaction::Update\n"));
					DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
					iRet = (unsigned long)(*DBObjPtr)(hTxnHeader);
DEBUGLOG(("Call DBTransaction:Update iRet = [%d]\n",iRet));

				}

				if (iRet == PD_OK) {
					char	*csPartyType = NULL;

					iBatchDtCnt += 1;
					PutField_Int(hBatchRec,"seq",iBatchDtCnt);
DEBUGLOG(("ProcessVoidTxn:: seq = [%d]\n",iBatchDtCnt));

					sprintf(csTag,"org_b%d_partytype",i);
					if (GetField_CString(hRls,csTag,&csPartyType)) {
DEBUGLOG(("ProcessVoidTxn:: [%s] = [%s]\n",csTag,csPartyType));
						PutField_CString(hBatchRec,"party_type",csPartyType);
DEBUGLOG(("ProcessVoidTxn:: party_type = [%s]\n",csPartyType));
					}

					sprintf(csTag,"org_b%d_partyid",i);
					if (GetField_CString(hRls,csTag,&csTmp)) {
DEBUGLOG(("ProcessVoidTxn:: [%s] = [%s]\n",csTag,csTmp));
						PutField_CString(hBatchRec,"party_id",csTmp);
DEBUGLOG(("ProcessVoidTxn:: party_id = [%s]\n",csTmp));
					}

					if (!strcmp(csPartyType, PD_MI_ENTITY_PSP)) {
						RemoveField_CString(hBatchRec,"entity_id");
					} else {
						sprintf(csTag,"org_b%d_entityid",i);
                                        	if (GetField_CString(hRls,csTag,&csTmp)) {
DEBUGLOG(("ProcessVoidTxn:: [%s] = [%s]\n",csTag,csTmp));
                                                	PutField_CString(hBatchRec,"entity_id",csTmp);
DEBUGLOG(("ProcessVoidTxn:: entity_id = [%s]\n",csTmp));
                                        	}
					}

					PutField_CString(hBatchRec,"txn_id",csTmpTxn);
DEBUGLOG(("ProcessVoidTxn:: txn_id = [%s]\n",csNewTxnId));

					PutField_Char(hBatchRec,"txn_oper_ind",PD_MI_BATCH_TXN_OPER_UPDATE);
DEBUGLOG(("ProcessVoidTxn:: txn_oper_ind = [%c]\n",PD_MI_BATCH_TXN_OPER_UPDATE));

DEBUGLOG(("ProcessVoidTxn::Call MiBatchDetail: Add \n"));
					DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
					iRet = (unsigned long)(*DBObjPtr)(hBatchRec);

					if (iRet != PD_OK) {
DEBUGLOG(("ProcessVoidTxn::Call MiBatchDetail:: Add Failed ret = [%d]\n",iRet));
					}

				}

			}

		}

		hash_destroy(hTxnHeader);
		FREE_ME(hTxnHeader);

	}


DEBUGLOG(("PrcoessVoidTxn:: iRet [%d]\n", iRet));
DEBUGLOG(("===== PrcoessVoidTxn ===== END !!\n"));

	hash_destroy(hBatchRec);
        FREE_ME(hBatchRec);

DEBUGLOG(("ProcessVoidTxn Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


int CallUpdateEntityBalance(hash_t *hData)
{
	int iRet = PD_OK;

	char* csTmp=NULL;
	double dTmp=0.0;

DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance::UpdateEntityBalance\n"));
		BOObjPtr = CreateObj(BOPtr, "BOMiEntityBalance", "UpdateEntityBalance");
		iRet = (unsigned long)(*BOObjPtr)(hData,hData);

		if (iRet != PD_OK) {
DEBUGLOG(("Call BOMiEntityBalance::UpdateEntityBalance FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsDLO::Call BOMiEntityBalance::UpdateEntityBalance FAILED!! ret [%d]\n",iRet);
		} else {

			if (GetField_CString(hData, "approval_date", &csTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: approval_date [%s]\n", csTmp));
			}

			if (GetField_CString(hData, "approval_timestamp", &csTmp))  {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: approval_timestamp [%s]\n", csTmp));
			}

			//Open Balance
			if (GetField_Double(hData, "open_acct_bal", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: open_acct_bal = [%f]\n", dTmp));
			}

			if (GetField_Double(hData, "open_intransit", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: open_intransit = [%f]\n", dTmp));
			}

			if (GetField_Double(hData, "open_ar_bal", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: open_ar_bal = [%f]\n", dTmp));
			}

			//Closing Balance
			if (GetField_Double(hData, "acct_bal", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: closing acct_bal = [%f]\n", dTmp));
			}

			if (GetField_Double(hData, "intransit", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: closing intransit = [%f]\n", dTmp));
			}

			if (GetField_Double(hData, "ar_bal", &dTmp)) {
DEBUGLOG(("CallUpdateEntityBalance()::Call BOMiEntityBalance:: closing ar_bal = [%f]\n", dTmp));
			}

		}

	return iRet;
}
