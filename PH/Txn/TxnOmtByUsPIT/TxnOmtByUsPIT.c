/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version (clone from POT)                      2017/03/24              David Wong
Add checking for the -ve psp amount		   2017/05/11		   LokMan Chow
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
#include "TxnOmtByUsPIT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnOmtByUsPIT(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csTxnSeq;
	char	*csTmp;
	//int	iChk = PD_OK;
	int	iTmp = 0;
	double	dTmp = 0.0;

	hash_t	*hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp,0);

DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));
        }

	if(iRet==PD_OK){
		RemoveField_Double(hContext,"total_src_txn_fee");
                RemoveField_Double(hContext,"total_dst_txn_fee");
		PutField_CString(hContext,"txn_code",PD_REQ_OPL_TXN_CODE);
		PutField_CString(hContext,"channel_code",PD_CHANNEL_OPL);
DEBUGLOG(("Authorize::call BOOLPayout->GetPayoutFee\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","GetPayoutFee");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
		PutField_CString(hContext,"txn_code",PD_OL_PAYOUT_API_APPROVE);
		PutField_CString(hContext,"channel_code",PD_CHANNEL_OMT);

		if(iRet==PD_OK){
			if (GetField_Double(hContext, "dst_net_amt", &dTmp)) {
				if(dTmp<=0){
					iRet = INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("Authorize::payout_amount = [%lf] which is invalid\n", dTmp));
				}
			}
		}
	}

	if(iRet==PD_OK){
		PutField_Char(hContext,"party_type",PD_TYPE_MERCHANT);
		PutField_Char(hContext,"response_mode",PD_ACCEPT);
DEBUGLOG(("Authorize::call BOOLPayout->HandleTxnPayoutBalance\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLPayout","HandleTxnPayoutBalance");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

		GetField_CString(hContext, "batch_id", &csTmp);
		PutField_CString(hTmp, "batch_id", csTmp);
DEBUGLOG(("batch_id = [%s]\n", csTmp));
		GetField_Int(hContext, "seq_num", &iTmp);
		PutField_Int(hTmp, "seq", iTmp);
DEBUGLOG(("seq = [%d]\n", iTmp));
		PutField_CString(hTmp, "txn_id", csTxnSeq);
DEBUGLOG(("txn_id = [%s]\n", csTxnSeq));
		PutField_Int(hTmp, "ret_code", iRet);
DEBUGLOG(("ret_code = [%d]\n", iRet));
		GetField_CString(hContext, "update_user", &csTmp);
		PutField_CString(hTmp, "update_user", csTmp);
DEBUGLOG(("update_user = [%s]\n", csTmp));

DEBUGLOG(("Authorize::Call DBOLPayoutApiBatchDT:UpdateByTxnId\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutApiBatchDT", "UpdateByTxnId");
		iRet = (unsigned long)(*DBObjPtr)(hTmp);
	}

	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

		PutField_CString(hTmp, "txn_seq", csTxnSeq);
DEBUGLOG(("txn_seq = [%s]\n", csTxnSeq));
		if (GetField_Double(hContext, "dst_net_amt", &dTmp)) {
			PutField_Double(hTmp, "payout_amount", dTmp);
DEBUGLOG(("payout_amount = [%lf]\n", dTmp));
		}
		if (GetField_CString(hContext, "src_txn_fee_ccy", &csTmp)) {
			PutField_CString(hTmp, "merchant_fee_ccy", csTmp);
DEBUGLOG(("merchant_fee_ccy = [%s]\n", csTmp));
		}
		if (GetField_Double(hContext, "src_txn_fee", &dTmp)) {
			PutField_Double(hTmp, "merchant_fee", dTmp);
DEBUGLOG(("merchant_fee = [%lf]\n", dTmp));
		}
		if (GetField_CString(hContext, "dst_txn_fee_ccy", &csTmp)) {
			PutField_CString(hTmp, "member_fee_ccy", csTmp);
DEBUGLOG(("member_fee_ccy = [%s]\n", csTmp));
		}
		if (GetField_Double(hContext, "dst_txn_fee", &dTmp)) {
			PutField_Double(hTmp, "member_fee", dTmp);
DEBUGLOG(("member_fee = [%lf]\n", dTmp));
		}
		if (GetField_CString(hContext, "markup_ccy", &csTmp)) {
			PutField_CString(hTmp, "markup_ccy", csTmp);
DEBUGLOG(("markup_ccy = [%s]\n", csTmp));
		}
		if (GetField_Double(hContext, "markup_amt", &dTmp)) {
			PutField_Double(hTmp, "markup_amt", dTmp);
DEBUGLOG(("markup_amt = [%lf]\n", dTmp));
		}
		PutField_Int(hTmp, "status", PAYOUT_MASTER_TRANSACTION_APPROVED);
DEBUGLOG(("status = [%d]\n", PAYOUT_MASTER_TRANSACTION_APPROVED));
		GetField_CString(hContext, "update_user", &csTmp);
		PutField_CString(hTmp, "update_user", csTmp);
DEBUGLOG(("update_user = [%s]\n", csTmp));

DEBUGLOG(("Authorize::Call DBOLPayoutRequest:Update\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPayoutRequest", "Update");
		iRet = (unsigned long)(*DBObjPtr)(hTmp);
	}

	if(iRet==PD_OK){
		PutField_Int(hContext,"do_logging",PD_TRUE);
		PutField_CString(hContext,"sub_status",PD_APPROVED_FOR_GENERATED);
		PutField_Char(hContext,"status",PD_COMPLETE);
		PutField_Char(hContext,"ar_ind",PD_ACCEPT);
		PutField_Int(hContext,"internal_code",PD_OK);
		PutField_CString(hContext,"response_code","0");
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnLog");
		if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("Authorize::OMTChannel:AddTxnLog Failed\n"));
		}
		PutField_Int(hContext,"do_logging",PD_FALSE);

		if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnDetailLog\n"));
			ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","UpdateTxnDetailLog");
			if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
				iRet = INT_ERR;
DEBUGLOG(("Authorize::OMTChannel:AddTxnDetailLog Failed\n"));
			}
			else{
				TxnCommit();
			}
		}

	}

	if(iRet==PD_OK){
		PutField_CString(hContext,"org_txn_seq",csTxnSeq);

DEBUGLOG(("Authorize::Call TxnOplByUsACK:Authorize\n"));
		TxnObjPtr = CreateObj(TxnPtr,"TxnOplByUsACK","Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::TxnOplByUsACK:Authorize Failed\n"));
ERRLOG("TxnOmtByUsPIT::Authorize::TxnOplByUsACK:Authorize Failed\n");
			iRet = INT_ERR;
		}

		RemoveField_CString(hContext, "org_txn_seq");
	}

	hash_destroy(hTmp);
	FREE_ME(hTmp);

DEBUGLOG(("TxnOmtByUsPIT Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

