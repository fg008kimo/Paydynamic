/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/25              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVHB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsVHB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char	*csTmp = NULL;

        char	*csTxnSeq = NULL;
	char	*csOrgTxnSeq = NULL;

	int	iReleased = PD_FALSE;


        char	*csMerchantId = NULL;
        char	*csService = NULL;
        char	*csTxnCountry = NULL;
        char	*csTxnCcy = NULL;
        char	*csUpdateUser = NULL;  
	char	*csReleaseDate = NULL;

        double	dTxnAmt=0.0;
        double	dNetAmt=0.0;
	double  dReserveAmt=0.0;

	int	iTmp;
	double	dTmp =0.0;

	recordset_t 	*rRecordSet;
	hash_t		*hRec;

	rRecordSet = (recordset_t*) malloc(sizeof(recordset_t));
	

	// Release Fixed Amount Holdback --need to update org. sub_status to 121-Release Holdback Amount, 
        // update reserved_release_date


/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
                //PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTxnSeq));
		//PutField_CString(hContext, "from_txn_seq", csTxnSeq);
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMgtByUsVHB::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* org txn_seq */
	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("Authorize:: org_txn_seq= [%s]\n",csOrgTxnSeq));
	}


/* add_user*/
        if(GetField_CString(hRequest,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
                PutField_CString(hContext,"add_user",csUpdateUser);
                PutField_CString(hContext,"update_user",csUpdateUser);
        }

/* remark */
        if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
                PutField_CString(hContext,"remark",csTmp);
        }

/* reserve_released */
	if (GetField_Int(hContext,"reserve_released", &iReleased)) {
DEBUGLOG(("Authorize:: Released = [%d]\n",iReleased ));
		// Check if already Released
		if (iReleased == PD_TRUE) {
			iRet=INT_INVALID_TXN; 
			PutField_Int(hContext, "internal_eror", iRet);
		}
	} 

	if (iRet == PD_OK) {
		// Lock Org. Txn Record
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxnStatus");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_COMPLETE, PD_ACCEPT) == PD_FOUND) {
DEBUGLOG(("Authorize:: Found Txn Record [%s]\n", csOrgTxnSeq));

			recordset_init(rRecordSet, 0);

DEBUGLOG(("Authorize::Call DBTransaction:GetTxnHeader\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
			if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("Authorize:: GetTxnHeader:client_id = [%s]\n",csTmp));
					}
					if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
						PutField_CString(hRequest,"merchant_id",csMerchantId);
						PutField_CString(hContext,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize:: GetTxnHeader:merchant_id = [%s]\n",csMerchantId));
					}
					if (GetField_Double(hRec,"txn_amt",&dTxnAmt)) {
						PutField_Double(hContext,"txn_amt",dTxnAmt);
						//PutField_Double(hContext,"org_txn_amt",dTxnAmt);
DEBUGLOG(("Authorize:: GetTxnHeader:txn_amt = [%lf]\n",dTxnAmt));
					}
					if (GetField_Double(hRec,"net_amt",&dNetAmt)) {
						PutField_Double(hContext,"net_amt",dNetAmt);
DEBUGLOG(("Authorize:: GetTxnHeader:net_amt = [%lf]\n",dNetAmt));
					}
					if (GetField_Double(hRec,"reserve_amt",&dReserveAmt)) {
						PutField_Double(hRequest,"reserve_amt",dReserveAmt);
DEBUGLOG(("Authorize:: GetTxnHeader:reserve_amt = [%lf]\n",dReserveAmt));
					}
					if (GetField_CString(hRec,"service_code",&csService)) {
DEBUGLOG(("Authorize:: GetTxnHeader:service_code = [%s]\n",csService));
						PutField_CString(hRequest,"service_code",csService);
						PutField_CString(hContext,"service_code",csService);
					}
					if (GetField_CString(hRec,"net_ccy",&csTmp)) {
DEBUGLOG(("Authorize:: GetTxnHeader:net_ccy = [%s]\n",csTmp));
						PutField_CString(hRequest,"net_ccy",csTmp);
						PutField_CString(hContext,"net_ccy",csTmp);
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			RecordSet_Destroy(rRecordSet);

			recordset_init(rRecordSet, 0);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
			if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_CString(hRec,"txn_country",&csTxnCountry)) {
DEBUGLOG(("Authorize:: GetTxnDetail:txn_country = [%s]\n",csTxnCountry));
						PutField_CString(hRequest,"txn_country",csTxnCountry);
						PutField_CString(hContext,"txn_country",csTxnCountry);
					}
					if (GetField_CString(hRec,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("Authorize:: GetTxnDetail:txn_ccy = [%s]\n",csTxnCcy));
						PutField_CString(hRequest,"txn_ccy",csTxnCcy);
						PutField_CString(hContext,"txn_ccy",csTxnCcy);
					}
					hRec = RecordSet_GetNext(rRecordSet);
                                }
                        }
			RecordSet_Destroy(rRecordSet);
		}
	}


        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext, "sub_status", PD_APPROVED);

	PutField_Char(hContext, "hb_dc_type", PD_IND_DEBIT);
	//PutField_CString(hContext, "amount_type",PD_CR); // element debit

        //Handle Balance
        if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessFixedAmtHoldBack");
                iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack Failed Ret [%d]\n", iRet));
ERRLOG("TxnMgtByUsVHB::BOBalance::ProcessFixedAmtHoldBack Failed Ret [%d]\n", iRet);
			if (iRet == INT_INSUFFICIENT_FUND) {
				PutField_Int(hContext,"internal_error",iRet);
			}
		} else {

			if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack merchant_open_bal [%lf]\n", dTmp));
				PutField_Double(hContext, "open_bal", dTmp);
			}

			if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack merchant_open_bal_settlement [%lf]\n", dTmp));
				PutField_Double(hContext, "open_bal_settlement", dTmp);
			}

			if (GetField_CString(hContext, "approval_date", &csReleaseDate)) {
DEBUGLOG(("Authorize::BOBalance:ProcessFixedAmtHoldBack approval_date [%s]\n", csReleaseDate));
			}
		}
	}


       if(GetField_Int(hContext,"do_logging",&iTmp)){
DEBUGLOG(("Authorize::do_logging [%d]\n", iTmp));
                if(iTmp!=PD_ADD_LOG) {
			/* nothing */
		}
		else {

        		if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
		                        iRet = INT_ERR;
			}
  
			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
                		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnDetailLog");
		                if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
               		        	iRet = INT_ERR;
                		}
			}
		}

		/* Element already added on VOT
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOTxnElements:AddReserveAmtElement\n"));
	                BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddReserveAmtElement");
			if ((unsigned long)((*BOObjPtr)(hContext)) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize::BOTxnElements:AddReserveAmtElement Failed\n"));
			}
		}
		*/

		// Update OrgTxn
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Update org txn's release reserve date\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateReleaseReserveDate");
			iRet = (unsigned long)DBObjPtr(csOrgTxnSeq,csReleaseDate,PD_RESERVE_RELEASED, csUpdateUser);
		}		
	}
	
	if(iRet != PD_OK){
		RemoveField_CString(hContext, "sub_status");
		RemoveField_CString(hContext, "approval_date");
		RemoveField_CString(hContext, "approval_timestamp");
	}

	RecordSet_Destroy(rRecordSet);

DEBUGLOG(("TxnMgtByUsVHB Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


