/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/18              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMinByUsDLO.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

int CallUpdateEntityBalance(hash_t *hData);


void TxnMinByUsDLO(char    cdebug)
{
        cDebug = cdebug;
}

int	Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;

	int	iCnt = 0;
	int	i=0;
	char	csTag[PD_TAG_LEN+1];
	char	*csTmp = NULL;
	char	*csUpdateUser = NULL;
	char	*csTxnSeq = NULL;
	char	*csEntityId = NULL;
	char	*csPartyId = NULL;
	char	csBatchId[PD_TXN_SEQ_LEN + 1];
	double	dTmp = 0.0;
	double	dTxnAmt = 0.0;
	double	dCostAmt = 0.0;
	double	dOpenAcctBal = 0.0;
	double	dOpenIntransit = 0.0;
	double	dOpenArBal = 0.0;

DEBUGLOG(("Authorize::Start\n"));
/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
DEBUGLOG(("Authorize::txn_seq = [%s]\n", csTxnSeq));
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_code*/
        if(GetField_CString(hContext,"txn_code",&csTmp)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csTmp));
        }
        else{
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;

                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if(GetField_CString(hContext,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
        }

/* remark */
        if(GetField_CString(hContext,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
	} else{
DEBUGLOG(("Authorize::remark not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::remark not found!!\n");
                iRet=INT_MI_REMARK_NOT_FOUND;
        }

/* entity_id */
        if(GetField_CString(hContext,"entity_id",&csEntityId)){
DEBUGLOG(("Authorize::entity_id = [%s]\n",csEntityId));
        }
	else {
DEBUGLOG(("Authorize::entity_id not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::entity_id not found!!\n");
		iRet = INT_MI_ENTITY_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}
/* party_id */
        if(GetField_CString(hContext,"party_id",&csPartyId)){
DEBUGLOG(("Authorize::party_id = [%s]\n",csPartyId));
        }
	else {
DEBUGLOG(("Authorize::party_id not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::party_id not found!!\n");
		iRet = INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_country */
	if(GetField_CString(hContext,"txn_country",&csTmp)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTmp));
	} else {
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::txn_country not found!!\n");
		iRet=INT_COUNTRY_PSP_NOT_AVABILE;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* product_code */
        if(GetField_CString(hContext,"product_code",&csTmp)){
DEBUGLOG(("Authorize::product_code = [%s]\n",csTmp));
        } 
	else {
DEBUGLOG(("Authorize::product_code not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::product_code not found!!\n");
		iRet=INT_MI_PRODUCT_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_ccy */
        if(GetField_CString(hContext,"txn_ccy",&csTmp)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTmp));
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_amt */
        if(GetField_Double(hContext,"txn_amt",&dTxnAmt)){
		//dTxnAmt = newround(dTxnAmt,PD_DECIMAL_LEN);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dTxnAmt));
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* cost_rate */
	if(GetField_Double(hContext,"cost_rate",&dTmp)){
DEBUGLOG(("Authorize: cost_rate = [%f]\n",dTmp));
	}

/* cost_amt */
	if(GetField_Double(hContext,"cost_amt",&dCostAmt)){
		//dCostAmt = newround(dCostAmt,PD_DECIMAL_LEN);
DEBUGLOG(("Authorize: cost_amt = [%f]\n",dCostAmt));
		PutField_Double(hContext,"actual_cost",dCostAmt);
	} else{
DEBUGLOG(("Authorize::cost_amt not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::cost_amt not found!!\n");
                iRet=INT_MI_COST_AMT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* remit_slip_date */
        if(GetField_CString(hContext,"remit_slip_date",&csTmp)){
DEBUGLOG(("Authorize::remit_slip_date = [%s]\n", csTmp)); 
		PutField_CString(hContext,"remittance_slip_date",csTmp);
        }

/* remit_rate */
	if(GetField_Double(hContext,"remit_rate",&dTmp)){
DEBUGLOG(("Authorize: remit_rate = [%f]\n",dTmp));
	}

/* cvt_ccy */
        if(GetField_CString(hContext,"cvt_ccy",&csTmp)){
DEBUGLOG(("Authorize::cvt_ccy= [%s]\n",csTmp));
		PutField_CString(hContext,"converted_ccy",csTmp);
        }

/* cvt_amt */
	if(GetField_Double(hContext,"cvt_amt",&dTmp)){
DEBUGLOG(("Authorize: cvt_amt = [%f]\n",dTmp));
		PutField_Double(hContext,"converted_amount",dTmp);
	}
	
/* total_cnt */
	if(GetField_Int(hContext,"total_cnt",&iCnt)) {
DEBUGLOG(("Authorize::total_cnt= [%d]\n",iCnt));
	} else {
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnMinByUsDLO::Authorize::total_cnt not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (iRet == PD_OK) {

		hash_t *hTxnHeader;
		recordset_t *rTxnHeader;
		rTxnHeader = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(rTxnHeader,0);

		double dTotalTxnAmt=0.0;

		iDtlRet = PD_OK;
		for (i=0; i<iCnt; i++) {

			/* PSP Settlement TxnID */
			sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_PSP, i);
			if (GetField_CString(hContext, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
			} else {
				iDtlRet = INT_ERR;
			}


			/* Get PSP Settlement Txn for update */
			if (iDtlRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction:MatchTxnStatusforUpdate()\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchTxnStatusforUpdate");
				iDtlRet = ((unsigned long)(*DBObjPtr)(csTmp,PD_COMPLETE));
				if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("Authorize:: DBTransaction:MatchTxnStatusforUpdate() not found\n"));
ERRLOG("TxnMinByUsDLO:Authorize:: DBTransaction:MatchTxnStatusforUpdate() not found\n");
					iDtlRet = INT_INVALID_TXN;
				} else {
					iDtlRet = PD_OK;
				}
			}

			//Sum txn_amt for PSP Settlement
			if (iDtlRet == PD_OK) {
				RecordSet_Destroy(rTxnHeader);
				recordset_init(rTxnHeader, 0);
DEBUGLOG(("Authorize:: Call DBTransaction:GetTxnHeader()\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
				iDtlRet = ((unsigned long)(*DBObjPtr)(csTmp,rTxnHeader));
			}

			if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize:: DBTransaction:GetTxnHeader() not found\n"));
ERRLOG("TxnMinByUsDLO:Authorize:: DBTransaction:GetTxnHeader() not found\n");
				iDtlRet = INT_ERR;
			} else {
				hTxnHeader = RecordSet_GetFirst(rTxnHeader);

				if (GetField_Double(hTxnHeader,"txn_amt",&dTmp)) {
					//dTmp = newround(dTmp,PD_DECIMAL_LEN);
					dTotalTxnAmt += dTmp;
DEBUGLOG(("Authorize:: GetTxnHeader txn_amt = [%f]\n",dTmp));
DEBUGLOG(("Authorize:: total_txnamt = [%f]\n", dTotalTxnAmt));
				}
			}


			/* RSP Settlement TxnID */
			if (iDtlRet == PD_OK) {
				sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_RSP, i);
				if (GetField_CString(hContext, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
				} else {
					iDtlRet = INT_ERR;
				}
			}

			if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize:: iDtlRet [%d], BREAK!!\n",iDtlRet));
ERRLOG("TxnMinByUsDLO:Authorize:: iDtlRet [%d], BREAK!!\n",iDtlRet);
				break;
			}
		}

		if (iDtlRet != PD_OK) {
			iRet = iDtlRet;
			PutField_Int(hContext,"internal_error",iRet);
		}

		//cross-check Total PSP Settlement txnamt & API txnamt+costamt
		//if (newround(dTotalTxnAmt,PD_DECIMAL_LEN) != newround(dTxnAmt,PD_DECIMAL_LEN) + newround(dCostAmt,PD_DECIMAL_LEN)) {
		if (newround(dTotalTxnAmt,PD_DECIMAL_LEN) != newround(dTxnAmt+dCostAmt,PD_DECIMAL_LEN)) {
DEBUGLOG(("Authorize:: total_txnamt [%.20f] not equal to txnamt [%.20f] + costamt [%.20f]\n", newround(dTotalTxnAmt,PD_DECIMAL_LEN),newround(dTxnAmt,PD_DECIMAL_LEN),newround(dCostAmt,PD_DECIMAL_LEN)));
DEBUGLOG(("Authorize:: total_txnamt [%f] not equal to txnamt [%f] + costamt [%f]\n", dTotalTxnAmt, dTxnAmt, dCostAmt));
DEBUGLOG(("Authorize:: total_txnamt [%.20f] not equal to txnamt [%.20f] + costamt [%.20f]\n", dTotalTxnAmt, dTxnAmt, dCostAmt));
ERRLOG("TxnMgtByUsDLO::Authorize:: total_txnamt [%f] not equal to txnamt [%f] + costamt [%f]\n", dTotalTxnAmt, dTxnAmt, dCostAmt);
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

		RecordSet_Destroy(rTxnHeader);
		FREE_ME(rTxnHeader);
	}

	PutField_Char(hContext, "batch_mode", PD_ONLINE);
DEBUGLOG(("Authorize::batch_mode = [%c]\n",PD_ONLINE));


//To Do: DR Intransit Pool (Txnamt)
	if (iRet == PD_OK) {

DEBUGLOG(("Authorize:: ToDo - DR Intransit Pool\n"));

		//amt_type
		PutField_CString(hContext, "amt_type", PD_DR);
DEBUGLOG(("Authorize::amt_type = [%s]\n",PD_DR));

		//bal_type
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_INTRANSIT);
DEBUGLOG(("Authorize::bal_type = [%c]\n",PD_MI_ENTITY_POOL_INTRANSIT));

		//Update Entity Balance
		iRet = CallUpdateEntityBalance(hContext);
DEBUGLOG(("Authorize::CallUpdateEntityBalance() ret [%d]\n",iRet));

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
	}

//To Do: CR Acct Balance (Txnamt)
	if (iRet == PD_OK) {

DEBUGLOG(("Authorize:: ToDo - CR AcctBal\n"));

		//amt_type
		PutField_CString(hContext, "amt_type", PD_CR);
DEBUGLOG(("Authorize::amt_type = [%s]\n",PD_CR));

		//bal_type
		PutField_Char(hContext, "bal_type", PD_MI_ENTITY_POOL_ACCT_BAL);
DEBUGLOG(("Authorize::bal_type = [%c]\n",PD_MI_ENTITY_POOL_ACCT_BAL));

		RemoveField_Double(hContext, "cost_amt");

		//Update Entity Balance
		iRet = CallUpdateEntityBalance(hContext);
DEBUGLOG(("Authorize::CallUpdateEntityBalance() ret [%d]\n",iRet));

	}


//To Do: Add TxnMiDetail

	if (iRet == PD_OK) {			

		//Put Open Balance into hContext
		PutField_Double(hContext,"open_acct_bal",dOpenAcctBal);
		PutField_Double(hContext,"open_intransit",dOpenIntransit);
		PutField_Double(hContext,"open_ar_bal",dOpenArBal);

		PutField_CString(hContext,"party_type",PD_MI_ENTITY_RSP);
		PutField_Int(hContext, "acr_prorata", PD_FALSE);

		//Call DBTxnMiDetail:Add()
DEBUGLOG(("Authorize::Call DBTxnMiDetail::Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","Add");
		iRet = (unsigned long)(*DBObjPtr)(hContext);

		if (iRet != PD_OK) {
DEBUGLOG(("Call DBTxnMiDetail:Add FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsDLO::Call DBTxnMiDetail:Add FAILED!! ret [%d]\n",iRet);
		} else {
DEBUGLOG(("Call DBTxnMiDetail:Add ret [%d]\n",iRet));
		}

	}


//To Do: Add TxnDetail

	if (iRet == PD_OK) {

DEBUGLOG(("Authorize::Call DBTransaction::AddDetail\n"))
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		iRet = (unsigned long)(*DBObjPtr)(hContext);

		if (iRet != PD_OK) {
DEBUGLOG(("Call DBTransaction:AddDetail FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsDLO::Call DBTransaction:AddDetail FAILED!! ret [%d]\n",iRet);
		} else {
DEBUGLOG(("Call DBTransaction:AddDetail ret [%d]\n",iRet));
		}

	}



	if (iRet == PD_OK) {
		iDtlRet = PD_OK;

		hash_t* hTxnHeader;
		hTxnHeader = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTxnHeader,0);

		hash_t* hTxnMiDetail;
		hTxnMiDetail = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTxnMiDetail,0);

		for (i=0; i<iCnt; i++) {

			//To Do: Update original PSP Settlement Txn
			// (1) Sub status

			if (iDtlRet == PD_OK) {
				sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_PSP, i);
				if (GetField_CString(hContext, csTag, &csTmp)) {
DEBUGLOG(("Call DBTransaction:Update\n"));

					PutField_CString(hTxnHeader,"txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTmp));
					PutField_CString(hTxnHeader,"sub_status",PD_DELIVERING);
DEBUGLOG(("Authorize::sub_status = [%s]\n",PD_DELIVERING));
					PutField_CString(hTxnHeader,"update_user",csUpdateUser);
DEBUGLOG(("Authorize::update_user = [%s]\n",csUpdateUser));

					DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
					iDtlRet = (unsigned long)(*DBObjPtr)(hTxnHeader);
					if (iDtlRet != PD_OK) {
DEBUGLOG(("Call DBTransaction:Update FAILED, iDtlRet [%d]\n",iDtlRet));
ERRLOG("TxnMinByUsDLO::Call DBTransaction:Update FAILED, iDtlRet [%d]\n",iDtlRet);
						iDtlRet = INT_ERR;
					} else {
DEBUGLOG(("Call DBTransaction:Update iDtlRet = [%d]\n",iDtlRet));
					}
				} else {
					iDtlRet = INT_ERR;
				}
			}

			//To Do: Update original RSP Intransit Txn
			// (1) TxnHeader:   Sub status
			// (2) TxnMiDetail: next_grp_txn_id = this delivery_out txn id

			if (iDtlRet == PD_OK) {
				sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_RSP, i);
				if (GetField_CString(hContext, csTag, &csTmp)) {
DEBUGLOG(("Call DBTransaction:Update\n"));

					PutField_CString(hTxnHeader,"txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTmp));
					PutField_CString(hTxnHeader,"sub_status",PD_DELIVERING);
DEBUGLOG(("Authorize::sub_status = [%s]\n",PD_DELIVERING));
					PutField_CString(hTxnHeader,"update_user",csUpdateUser);
DEBUGLOG(("Authorize::update_user = [%s]\n",csUpdateUser));

					DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
					iDtlRet = (unsigned long)(*DBObjPtr)(hTxnHeader);
					if (iDtlRet != PD_OK) {
DEBUGLOG(("Call DBTransaction:Update FAILED, iDtlRet [%d]\n",iDtlRet));
ERRLOG("TxnMinByUsDLO::Call DBTransaction:Update FAILED, iDtlRet [%d]\n",iDtlRet);
						iDtlRet = INT_ERR;
					} else {
DEBUGLOG(("Call DBTransaction:Update iDtlRet = [%d]\n",iDtlRet));
					}

					if (iDtlRet == PD_OK) {
DEBUGLOG(("Call DBTxnMiDetail:Update\n"));
						PutField_CString(hTxnMiDetail,"txn_seq",csTmp);
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTmp));
						PutField_CString(hTxnMiDetail,"next_grp_txn_id",csTxnSeq);
DEBUGLOG(("Authorize::next_grp_txn_id = [%s]\n",csTxnSeq));
						PutField_CString(hTxnMiDetail,"update_user",csUpdateUser);
DEBUGLOG(("Authorize::update_user = [%s]\n",csUpdateUser));

						DBObjPtr = CreateObj(DBPtr,"DBTxnMiDetail","Update");
						iDtlRet = (unsigned long)(*DBObjPtr)(hTxnMiDetail);
						if (iDtlRet != PD_OK) {
DEBUGLOG(("Call DBTxnMiDetail:Update FAILED, iDtlRet [%d]\n",iDtlRet));
ERRLOG("TxnMinByUsDLO::Call DBTxnMiDetail:Update FAILED, iDtlRet [%d]\n",iDtlRet);
							iDtlRet = INT_ERR;
						} else {
DEBUGLOG(("Call DBTxnMiDetail:Update iDtlRet = [%d]\n",iDtlRet));
						}
					}
				} else {
					iDtlRet = INT_ERR;
				}
			}

			if (iDtlRet != PD_OK) {
DEBUGLOG(("Authorize:: iDtlRet [%d], BREAK!!\n",iDtlRet));
ERRLOG("TxnMinByUsDLO:Authorize:: iDtlRet [%d], BREAK!!\n",iDtlRet);
				break;
			}
		}

		if (iDtlRet != PD_OK) {
			iRet = iDtlRet;
DEBUGLOG(("Authorize: Call DBTransaction:Update or DBTxnMiDetail:Update FAILED!! iDtlRet = [%d]\n", iDtlRet));
ERRLOG("TxnMinByUsDLO::Authorize: Call DBTransaction:Update or DBTxnMiDetail:Update FAILED!! iDtlRet = [%d]\n", iDtlRet);
		}

		hash_destroy(hTxnHeader);
		FREE_ME(hTxnHeader);

		hash_destroy(hTxnMiDetail);
		FREE_ME(hTxnMiDetail);
	}

//To Do: Add Mi Batch
	if (iRet == PD_OK) {

		//Generate Batch Id
DEBUGLOG(("Authorize::Call TxnSeq::GetNextMiActionBatchSeq\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnSeq", "GetNextMiActionBatchSeq");
		strcpy(csBatchId, (*DBObjPtr)());

		hash_t *hBatchRec;
		hBatchRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hBatchRec,0);

		//Add Batch Header 
		if (iRet == PD_OK) {
			PutField_CString(hBatchRec,"batch_id",csBatchId);
			PutField_CString(hBatchRec,"process_type",PD_MI_TXN_TYPE_DELIV_IN);
			PutField_Char(hBatchRec,"status",PD_MI_BATCH_STATUS_NORMAL);
			PutField_CString(hBatchRec,"add_user",csUpdateUser);

DEBUGLOG(("Authorize::Call MiBatchHeader::Add\n"));
			DBObjPtr = CreateObj(DBPtr, "DBMiBatchHeader", "Add");
			iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
DEBUGLOG(("Call MiBatchHeader::Add ret [%d]\n",iRet));
			if (iRet != PD_OK) {
DEBUGLOG(("Call MiBatchHeader::Add FAILED!! ret [%d]\n",iRet));
ERRLOG("TxnMinByUsDLO::Call MiBatchHeader::Add FAILED!! ret [%d]\n",iRet);
			}
		}

		//Add Batch Detail
		if (iRet == PD_OK) {
			int iBatchCnt=1;

			PutField_Int(hBatchRec,"seq",iBatchCnt);
			PutField_CString(hBatchRec,"entity_id",csEntityId);
			PutField_CString(hBatchRec,"party_type",PD_MI_ENTITY_RSP);
			PutField_CString(hBatchRec,"party_id",csPartyId);
			PutField_CString(hBatchRec,"txn_id",csTxnSeq);
			PutField_Char(hBatchRec,"txn_oper_ind",PD_MI_BATCH_TXN_OPER_INSERT);

DEBUGLOG(("Authorize::Call MiBatchDetail: Add \n"));
			DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
			iRet = (unsigned long)(*DBObjPtr)(hBatchRec);

			if (iRet != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize::Call MiBatchDetail:: Add Failed ret = [%d]\n",iRet));
			} else {
				for (i=0; i<iCnt; i++) {
					iBatchCnt++;

					//RSP Txn
					PutField_Int(hBatchRec,"seq",iBatchCnt);
					sprintf(csTag, "%s_entityid_%d", PD_MI_ENTITY_RSP, i);
					if (GetField_CString(hContext, csTag, &csTmp)) {
						PutField_CString(hBatchRec,"party_id",csTmp);
					}
					PutField_CString(hBatchRec,"party_type",PD_MI_ENTITY_RSP);
					PutField_CString(hBatchRec,"entity_id",csEntityId);
					sprintf(csTag, "%s_partyid_%d", PD_MI_ENTITY_RSP, i);
					if (GetField_CString(hContext, csTag, &csTmp)) {
						PutField_CString(hBatchRec,"party_id",csTmp);
					}
					sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_RSP, i);
					if (GetField_CString(hContext, csTag, &csTmp)) {
						PutField_CString(hBatchRec,"txn_id",csTmp);
					}
					PutField_Char(hBatchRec,"txn_oper_ind",PD_MI_BATCH_TXN_OPER_UPDATE);

DEBUGLOG(("Authorize::Call MiBatchDetail: Add \n"));
					DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
					iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
DEBUGLOG(("Authorize::Call MiBatchDetail:: Add ret = [%d]\n",iRet));

					iBatchCnt++;

					if (iRet == PD_OK) {
						//PSP Txn
						PutField_Int(hBatchRec,"seq",iBatchCnt);
						RemoveField_CString(hBatchRec,"entity_id");
						PutField_CString(hBatchRec,"party_type",PD_MI_ENTITY_PSP);
						sprintf(csTag, "%s_partyid_%d", PD_MI_ENTITY_PSP, i);
						if (GetField_CString(hContext, csTag, &csTmp)) {
							PutField_CString(hBatchRec,"party_id",csTmp);
						}
						sprintf(csTag, "%s_txnid_%d", PD_MI_ENTITY_PSP, i);
						if (GetField_CString(hContext, csTag, &csTmp)) {
							PutField_CString(hBatchRec,"txn_id",csTmp);
						}
						PutField_Char(hBatchRec,"txn_oper_ind",PD_MI_BATCH_TXN_OPER_UPDATE);

DEBUGLOG(("Authorize::Call MiBatchDetail: Add \n"));
						DBObjPtr = CreateObj(DBPtr, "DBMiBatchDetail", "Add");
						iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
DEBUGLOG(("Authorize::Call MiBatchDetail:: Add ret = [%d]\n",iRet));
					}

					if (iRet == PD_OK) {
						//Batch Relation
						sprintf(csTag, "batchid_%d", i);
						if (GetField_CString(hContext, csTag, &csTmp)) {
							PutField_CString(hBatchRec,"org_batch_id",csTmp);
						}
						PutField_Char(hBatchRec,"relation_type",PD_MI_BATCH_RELATION_TYPE_LINKAGE);

DEBUGLOG(("Authorize::Call MiBatchRelation: Add \n"));
						DBObjPtr = CreateObj(DBPtr, "DBMiBatchRelation","Add");
						iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
DEBUGLOG(("Authorize::Call MiBatchRelation:: Add ret = [%d]\n",iRet));

						if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: iRet [%d], BREAK!!\n",iRet));
ERRLOG("TxnMinByUsDLO:Authorize:: iRet [%d], BREAK!!\n",iRet);
							break;
						}
					}
				}
			}
		}

		PutField_Double(hContext, "net_amt", dTxnAmt+dCostAmt);
		PutField_CString(hContext, "sub_status", PD_APPROVED);
		PutField_Char(hContext,"ex_party",PD_INT_EX);
		PutField_Double(hContext,"ex_rate",1);

		hash_destroy(hBatchRec);
		FREE_ME(hBatchRec);
	}


DEBUGLOG(("TxnMinByUsDLO Normal Exit() iRet = [%d]\n",iRet));
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
