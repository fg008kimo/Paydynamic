/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/11              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVWB.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsVWB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csOrgTxnSeq;
	char	*csTmp;
	//char	cTmp;
	double	dTmp;
	double	dPspTxnAmt=0;
	double	dServiceFee=0;
	int	iStatus;
	int	iReturnFee = PD_FALSE;
	double	dOrgSrcAmt;
	unsigned long lBatchId;
	int	iDayOfWeek=0;
	hash_t  *hRec, *hOrgTxn, *hIn, *hPspDetail;
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hOrgTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);

	hIn= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hIn,0);

	hPspDetail= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);

DEBUGLOG(("TxnMgtByUsVWB: Authroize()\n"));

	if(GetField_CString(hContext,"VPFEE",&csTmp)){
DEBUGLOG(("TxnMgtByUsVWB: Void Payout Fee Return [%s]\n",csTmp));
		if(!strcmp(csTmp,"Y")){
			iReturnFee = PD_TRUE;
		}
	}

	if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("txn seq = [%s]\n",csTmp));
		PutField_CString(hOrgTxn,"aux_txn_seq",csTmp);
                PutField_CString(hPspDetail,"txn_seq",csTmp);
		PutField_CString(hContext,"from_txn_seq",csTmp);
	}

	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hOrgTxn,"txn_seq",csOrgTxnSeq);
	}

	if(GetField_CString(hContext,"update_user",&csTmp)){
                PutField_CString(hOrgTxn,"update_user",csTmp);
                PutField_CString(hPspDetail,"add_user",csTmp);
DEBUGLOG(("Authorize::update_user= [%s]\n",csTmp));
        }

	if(GetField_CString(hContext,"PHDATE",&csTmp)){
		iDayOfWeek=day_of_week((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::day_of_week= [%d]\n",iDayOfWeek));
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
		PutField_CString(hPspDetail,"txn_date",csTmp);
		PutField_CString(hContext,"approval_date",csTmp);
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnHeader\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"merchant_id",&csTmp)) {
                                        PutField_CString(hContext,"org_merchant_id",csTmp);
                                        PutField_CString(hContext,"merchant_id",csTmp);
                                        PutField_CString(hRequest,"merchant_id",csTmp);
DEBUGLOG(("GetTxnHeader::merchant_id = [%s]\n",csTmp));
                                }
                                if (GetField_CString(hRec,"merchant_ref",&csTmp)) {
                                        PutField_CString(hContext,"merchant_ref",csTmp);
DEBUGLOG(("GetTxnHeader::merchant_ref = [%s]\n",csTmp));
                                }
                                if (GetField_CString(hRec,"client_id",&csTmp)) {
                                        PutField_CString(hContext,"merchant_client_id",csTmp);
DEBUGLOG(("GetTxnHeader::client_id = [%s]\n",csTmp));
                                }
                                if (GetField_CString(hRec,"service_code",&csTmp)) {
                                        PutField_CString(hContext,"org_service_code",csTmp);
                                        PutField_CString(hContext,"service_code",csTmp);
DEBUGLOG(("GetTxnHeader::service_code= [%s]\n",csTmp));
                                }
                                if (GetField_Double(hRec,"txn_amt",&dTmp)) {
                                        PutField_Double(hContext,"txn_amt",dTmp);
                                        PutField_Double(hContext,"org_txn_amt",dTmp);
DEBUGLOG(("GetTxnHeader::txn_amt = [%lf]\n",dTmp));
                                }
                                if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("GetTxnHeader::net_amt = [%lf]\n",dTmp));
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
		else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVWB:Authorize::GetTxnHeader::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                        PutField_Int(hContext,"internal_error",iRet);
                }

	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnPspDetail\n"));
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnPspDetail::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_Double(hRec,"txn_amt",&dPspTxnAmt)) {
                                        PutField_Double(hContext,"org_dst_net_amt",dPspTxnAmt);
                                        PutField_Double(hContext,"txn_amt",dPspTxnAmt);
DEBUGLOG(("GetTxnPspDetail::txn_amt = [%lf]\n",dPspTxnAmt));
                                }
                                if (GetField_Double(hRec,"service_fee",&dServiceFee)) {
                                        PutField_Double(hContext,"precal_fee",dServiceFee);
                                        PutField_Double(hContext,"service_fee",dServiceFee);
DEBUGLOG(("GetTxnPspDetail::service_fee = [%lf]\n",dServiceFee));
                                }
                                if (GetField_CString(hRec,"txn_date",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::txn_date = [%s]\n",csTmp));
                                }
				hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("GetTxnPspDetail:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVWB:Authorize::GetTxnDetail:: not found record!!\n");
                        iRet = INT_NOT_RECORD;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }



	if(iRet==PD_OK){
//MerchantUploadFileDetail
DEBUGLOG(("Authorize::Call DBMerchantUploadFileDetail:GetDetailByTxnId\n"));
        	DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","GetDetailByTxnId");
        	iRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq,rRecordSet);
	}

	if(iRet==PD_OK){
                hRec = RecordSet_GetFirst(rRecordSet);
               	while ((hRec) && (iRet==PD_OK)) {
/* batch_id */          
                       	if (GetField_CString(hRec,"batch_id",&csTmp)) {
                       	        lBatchId = (unsigned long)ctol((const unsigned char *)csTmp,strlen(csTmp));
DEBUGLOG(("batch_id = [%ld]\n",lBatchId));
                       	}
/*psp_id*/              
                       	if (GetField_CString(hRec,"psp_id",&csTmp)) {
DEBUGLOG(("psp_id = [%s]\n",csTmp));
                               	PutField_CString(hContext,"org_psp_id",csTmp);
				PutField_CString(hContext,"psp_id",csTmp);
                               	PutField_CString(hPspDetail,"psp_id",csTmp);
                       	}
/*country*/
                       	if (GetField_CString(hRec,"txn_country",&csTmp)) {
DEBUGLOG(("txn_country = [%s]\n",csTmp));
                               	PutField_CString(hIn,"txn_country",csTmp);
                               	PutField_CString(hContext,"txn_country",csTmp);
                               	PutField_CString(hContext,"org_txn_country",csTmp);
				PutField_CString(hRequest,"txn_country",csTmp);
                       	}       
/*payout_ccy*/          
                	if (GetField_CString(hRec,"payout_ccy",&csTmp)) {
DEBUGLOG(("payout_ccy = [%s]\n",csTmp));
                               	PutField_CString(hIn,"txn_ccy",csTmp);
                               	PutField_CString(hContext,"txn_ccy",csTmp);
                               	PutField_CString(hPspDetail,"txn_ccy",csTmp);
                               	PutField_CString(hContext,"org_txn_ccy",csTmp);
				PutField_CString(hContext,"org_dst_txn_ccy",csTmp);
				PutField_CString(hRequest,"txn_ccy",csTmp);
                               	PutField_CString(hContext,"org_psp_txn_ccy",csTmp);
                               	PutField_CString(hContext,"dst_txn_ccy",csTmp);
                       	}
/*request_ccy*/
                       	if (GetField_CString(hRec,"request_ccy",&csTmp)){
                               	//PutField_CString(hContext,"org_psp_txn_ccy",csTmp);
                               	//PutField_CString(hContext,"dst_txn_ccy",csTmp);
DEBUGLOG(("request_ccy = [%s]\n",csTmp));
                       	}
/*payout_amount*/
                       	if (GetField_Double(hRec,"payout_amount",&dTmp)) {
DEBUGLOG(("payout_amount = [%f]\n",dTmp));
				dOrgSrcAmt = dTmp;
				PutField_Double(hPspDetail,"txn_amt",dTmp);
				PutField_Double(hContext,"org_dst_txn_amt",dTmp);
                       	}
/*request_amount*/
                       	if (GetField_Double(hRec,"request_amount",&dTmp)) {
DEBUGLOG(("request_amount = [%f]\n",dTmp));
                               	PutField_Double(hContext,"org_dst_net_amt",dTmp);
                      	}
/*member_fee*/
                       	if (GetField_Double(hRec,"member_fee",&dTmp)) {
DEBUGLOG(("member_fee = [%f]\n",dTmp));
                       	}

			if(iReturnFee==PD_TRUE){
/*merchant_fee*/
                       		if (GetField_Double(hRec,"merchant_fee",&dTmp)) {
DEBUGLOG(("merchant_fee = [%f]\n",dTmp));
                               		dOrgSrcAmt += dTmp;
                       		}
			}

			PutField_Double(hContext,"txn_amt",dOrgSrcAmt);
			PutField_Double(hContext,"org_src_txn_amt",dOrgSrcAmt);


/*status*/
                       	if (GetField_Int(hRec,"status",&iStatus)) {
DEBUGLOG(("status = [%d]\n",iStatus));
                               	if(iStatus!=PAYOUT_MASTER_TRANSACTION_ACCEPT){
					iRet = INT_ERR;
DEBUGLOG(("Authorize::Invalid Status. Txn cannot be voided\n"));
				}
			}
                       	hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        RecordSet_Destroy(rRecordSet);

	if(iRet==PD_OK){
		/*Add TxnAmtElement for Merchant*/
		if(GetField_Double(hContext,"org_src_txn_amt",&dTmp)){
			PutField_Double(hContext,"org_txn_amt",dTmp);
		}
		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
		iRet = (unsigned long)(*BOObjPtr)(hContext);
	}

/*
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOExchange:GetExchangeInfo\n"));
                BOObjPtr = CreateObj(DBPtr,"BOExchange","GetExchangeInfo");
                if ((*BOObjPtr)(hContext,hIn) == PD_OK) {
                        if(GetField_Char(hContext,"ex_party",&cTmp)){
                                PutField_Char(hContext,"ex_supplier",cTmp);
                        }

                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::GetExchangeInfo Error\n"));
ERRLOG("TxnMgtByUsVWB:Authorize::GetExchangeInfo Error\n");
                }
        }
*/
        if (iRet == PD_OK) {
		PutField_CString(hContext,"sub_txn_code",PD_PAYOUT_VOID);
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));
                BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                if((unsigned long)(*BOObjPtr)(hContext,hIn)==PD_OK){
                        if(GetField_Double(hContext,"src_txn_fee",&dTmp)){
DEBUGLOG(("Authorize::void payout txn fee=[%f]\n",dTmp));
                        }
                        if(GetField_Double(hContext,"net_amt",&dTmp)){
DEBUGLOG(("Authorize::void payout net amt=[%f]\n",dTmp));
                                PutField_Double(hContext,"org_net_amt",dTmp);
                        }
//                        if(GetField_Double(hContext,"dst_txn_amt",&dTmp)){
//DEBUGLOG(("Authorize::void payout dest net amt=[%f]\n",dTmp));
//                              PutField_Double(hContext,"org_dst_net_amt",dTmp);
//                        }

			/*Add TxnFeeElements*/
			BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext);

                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::GetTxnFee Error\n"));
ERRLOG("TxnMgtByUsVWB:Authorize::GetTxnFee Error\n");
                }
        }



	if (iRet == PD_OK) {
DEBUGLOG(("Call BOBalance:UpdatePayoutAmount()\n"));
		PutField_Char(hContext,"response_mode",PD_REVERSED);

		BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdatePayoutAmount");
		if((unsigned long)(*BOObjPtr)(hContext)!=PD_OK)
			iRet = INT_ERR;
DEBUGLOG(("TxnMgtByUsVWB: Authroize:: BOBalance:UpdatePayoutAmount() result = [%d]\n",iRet));
	}
	else{
		if(GetField_Double(hContext,"merchant_open_bal",&dTmp)){
			PutField_Double(hContext,"open_bal",dTmp);
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchantUploadFileDetail:UpdateDetailByTxnId\n"));
		PutField_Int(hOrgTxn,"status",PAYOUT_MASTER_TRANSACTION_REVERSED);
                DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByTxnId");
                if ((*DBObjPtr)(csOrgTxnSeq,hOrgTxn) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBMerchantUploadFileDetail:UpdateDetailByBatchId Failed\n"));
                }
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call Update Org Transaction\n"));
		PutField_Char(hOrgTxn,"status",PD_REVERSED);
                PutField_CString(hOrgTxn,"sub_status",PD_VOID);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                if((unsigned long) ((*DBObjPtr)(hOrgTxn))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:Update Failed\n"));
		}
        }

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:AddDetail Failed\n"));
                }
        }
        
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:UpdateDetail Failed\n"));
                }
        }

	if(iRet==PD_OK){
		PutField_CString(hPspDetail,"desc","Payout Refund");
                if (GetField_Double(hContext,"psp_balance",&dTmp)) {
                        PutField_Double(hPspDetail,"bal",dTmp);
DEBUGLOG(("Authorize:: psp_balance = [%f]\n",dTmp));
                }
                if (GetField_Double(hContext,"psp_total_float",&dTmp)) {
                        PutField_Double(hPspDetail,"total_float",dTmp);
DEBUGLOG(("Authorize:: psp_total_float = [%f]\n",dTmp));
                }
                if (GetField_Double(hContext,"psp_total_hold",&dTmp)) {
                        PutField_Double(hPspDetail,"total_hold",dTmp);
DEBUGLOG(("Authorize:: psp_total_hold = [%f]\n",dTmp));
                }
		if(iStatus!=PAYOUT_MASTER_TRANSACTION_APPROVED){

			/*Add TxnAmtElement for PSP*/
			PutField_Double(hContext,"org_txn_amt",dPspTxnAmt+dServiceFee);
			PutField_Char(hContext,"party_type",PD_TYPE_PSP);
			BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
			iRet = (unsigned long)(*BOObjPtr)(hContext);

DEBUGLOG(("Authorize::Call DBTxnPspDetail:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
			if((unsigned long) ((*DBObjPtr)(hPspDetail))!=PD_OK){
				iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTxnPspDetail:Add Failed\n"));
                	}
			if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
				if((unsigned long) ((*DBObjPtr)(hPspDetail))!=PD_OK){
					iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTxnPspDetail:Add Failed\n"));
				}
			}
		}
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(hOrgTxn);
        FREE_ME(hPspDetail);
	FREE_ME(rRecordSet);

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}
