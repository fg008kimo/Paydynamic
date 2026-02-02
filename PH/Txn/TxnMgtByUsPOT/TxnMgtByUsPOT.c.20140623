/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/29              LokMan Chow
Get txn_seq from confirm Txn			   2013/02/26		   LokMan Chow
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
#include "TxnMgtByUsPOT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsPOT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char    *csTxnSeq;
	int	iChk = PD_OK;


DEBUGLOG(("Authorize\n"));

/*
DEBUGLOG(("Authorize: Call GetNextBatchTxnSeq\n"));
	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextBatchTxnSeq");
	csTxnSeq  = strdup((*DBObjPtr)());
DEBUGLOG(("Authorize: GenerateBatchSeq: [%s]\n",csTxnSeq));
	PutField_CString(hContext,"txn_seq",csTxnSeq);
	FREE_ME(csTxnSeq);

	PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext,"process_code","000000");
	PutField_Int(hContext,"do_logging",PD_TRUE);

DEBUGLOG(("Authorize::Call MGTChannel:AddTxnLog\n"));
	ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","AddTxnLog");
	if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest))!=PD_OK){
		iRet = INT_ERR;
DEBUGLOG(("Authorize::MGTChannel:AddTxnLog Failed\n"));
	}
*/

	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));
	}

DEBUGLOG(("Authorize::call DBMerchantUploadFileDetail->MatchRespTxn_ForUpdate\n"));
	DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","MatchRespTxn_ForUpdate");
	iChk = (unsigned long)(*DBObjPtr)(csTxnSeq,PAYOUT_MASTER_TRANSACTION_CONFIRMED);
	if(iChk==PD_NOT_FOUND){
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: The Transaction is not for approval\n"));
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call DBTransaction->MatchRespTxn\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn");
		iChk = (unsigned long)(*DBObjPtr)(csTxnSeq,PD_TO_PSP);
		if(iChk==PD_NOT_FOUND){
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: The Transaction is not for approval\n"));
		}
	}

	if(iRet==PD_OK){
		RemoveField_Double(hContext,"total_src_txn_fee");
		RemoveField_Double(hContext,"total_dst_txn_fee");
DEBUGLOG(("Authorize::call BOPayout->GetPayoutFee\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","GetPayoutFee");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if(iRet==PD_OK){
		PutField_Char(hContext,"party_type",PD_TYPE_MERCHANT);
		PutField_Char(hContext,"response_mode",PD_ACCEPT);
DEBUGLOG(("Authorize::call BOPayout->HandleTxnPayoutBalance\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","HandleTxnPayoutBalance");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if(iRet==PD_OK){
		PutField_Int(hContext,"status",PAYOUT_MASTER_TRANSACTION_APPROVED);
DEBUGLOG(("Authorize::call BOPayout->UpdateDetailByTxn\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","UpdateDetailByTxn");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if(iRet==PD_OK){
		PutField_Int(hContext,"do_logging",PD_TRUE);
		PutField_CString(hContext,"sub_status",PD_APPROVED_FOR_GENERATED);
		PutField_Char(hContext,"status",PD_COMPLETE);
		PutField_Char(hContext,"ar_ind",PD_ACCEPT);
		PutField_Int(hContext,"internal_code",PD_OK);
		PutField_CString(hContext,"response_code","0");
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","UpdateTxnLog");
		if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("Authorize::MGTChannel:AddTxnLog Failed\n"));
		}
		PutField_Int(hContext,"do_logging",PD_FALSE);

		if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
			ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","UpdateTxnDetailLog");
			if((unsigned long) ((*ChannelObjPtr)(hContext,hRequest,hResponse))!=PD_OK){
				iRet = INT_ERR;
DEBUGLOG(("Authorize::MGTChannel:AddTxnDetailLog Failed\n"));
			}
			else{
				TxnCommit();
			}
		}

	}

DEBUGLOG(("TxnMgtByUsPOT Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
