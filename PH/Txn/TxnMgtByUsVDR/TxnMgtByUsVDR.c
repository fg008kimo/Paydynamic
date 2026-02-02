/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/12/05              LokMan Chow
Add Txn Code - Deposit Chargeback                  2015/12/17              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVDR.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsVDR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	hash_t  *hOrgTxn;//, *hElement;
	char	*csOrgTxnSeq;
	char	*csOrgPostDate;
	char	*csMerchantId;
	char	*csServiceCode;
	char	*csCountry;
	char	*csCcy;
	char	*csPspCcy;
	char	*csSubStatus;
	char	*csNewTxnCode;
	char	*csTmp;
	double	dFee = 0.0;
	double	dPreFee = 0.0;
	double	dTxnAmt= 0.0;
	double	dNetAmt= 0.0;
	double	dReserveAmt= 0.0;
	double	dPspTxnAmt= 0.0;
	double	dServiceFee= 0.0;
	double	dTmp;
	hash_t  *hRec;

	int	iTmp;
	int	iReturnPspFee = PD_FALSE;
	int	iReleased = PD_FALSE;
	int     iDepositChargeback = PD_FALSE;
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hOrgTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);
	//hElement = (hash_t*)  malloc (sizeof(hash_t));
        //hash_init(hElement,0);

DEBUGLOG(("TxnMgtByUsVDR: Authroize()\n"));

	if(GetField_Int(hContext,"is_deposit_chargeback",&iDepositChargeback)){
DEBUGLOG(("is_deposit_chargeback = [%d]\n",iDepositChargeback));
        }

	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hOrgTxn,"txn_seq",csOrgTxnSeq);
		PutField_Char(hOrgTxn,"status",PD_REVERSED);
		if (iDepositChargeback == PD_FALSE) {
                        PutField_CString(hOrgTxn,"sub_status",PD_VOID);
                } else {
                        PutField_CString(hOrgTxn,"sub_status",PD_APPROVED_CHARGEBACK);
                }
	}

	if(GetField_Int(hRequest,"return_pspfee",&iReturnPspFee)){
                if(iReturnPspFee==PD_TRUE){
DEBUGLOG(("Authorize::return psp fee\n"));
                }
                else{
DEBUGLOG(("Authorize::not return psp fee\n"));
                }
        }

	if(GetField_CString(hRequest,"remark",&csTmp)){
                PutField_CString(hContext,"remark",csTmp);
DEBUGLOG(("Authorize::remark= [%s]\n",csTmp));
        }

	//if (GetField_CString(hContext,"from_txn_seq",&csTmp)) {
	//	PutField_CString(hElement,"from_txn_seq",csTmp);
	//}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnHeader\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
                                        PutField_CString(hContext,"org_merchant_id",csMerchantId);
                                        PutField_CString(hContext,"merchant_id",csMerchantId);
DEBUGLOG(("GetTxnHeader::merchant_id = [%s]\n",csMerchantId));
                                }
                                if (GetField_CString(hRec,"merchant_ref",&csTmp)) {
                                        PutField_CString(hContext,"merchant_ref",csTmp);
DEBUGLOG(("GetTxnHeader::merchant_ref = [%s]\n",csTmp));
                                }
                                if (GetField_CString(hRec,"service_code",&csServiceCode)) {
                                        PutField_CString(hContext,"org_service_code",csServiceCode);
                                        PutField_CString(hContext,"service_code",csServiceCode);
DEBUGLOG(("GetTxnHeader::service_code= [%s]\n",csServiceCode));
                                }
                                if (GetField_CString(hRec,"net_ccy",&csTmp)) {
                                        PutField_CString(hContext,"net_ccy",csTmp);
DEBUGLOG(("GetTxnHeader::net_ccy= [%s]\n",csTmp));
                                }
				if (GetField_Double(hRec,"txn_amt",&dTxnAmt)) {
					PutField_Double(hContext,"txn_amt",dTxnAmt);
					PutField_Double(hContext,"org_txn_amt",dTxnAmt);
DEBUGLOG(("GetTxnHeader::txn_amt = [%lf]\n",dTxnAmt));
                                }
				if (GetField_Double(hRec,"net_amt",&dNetAmt)) {
					//PutField_Double(hContext,"txn_amt",dNetAmt);
					//PutField_Double(hElement,"org_txn_amt",dNetAmt);
DEBUGLOG(("GetTxnHeader::net_amt = [%lf]\n",dNetAmt));
                                }
				if (GetField_Double(hRec,"reserve_amt",&dReserveAmt)) {
					PutField_Double(hContext,"reserve_amt",dReserveAmt);
DEBUGLOG(("GetTxnHeader::reserve_amt = [%lf]\n",dReserveAmt));
                                }

				if(GetField_CString(hRec,"sub_status",&csSubStatus)){
DEBUGLOG(("GetTxnHeader::sub_status = [%s]\n",csSubStatus));
				}
				if(!strcmp(csSubStatus,PD_RESERVE_RELEASED)){
                                	if (GetField_CString(hRec,"reserved_release_date",&csTmp)) {
						iReleased = PD_TRUE;
DEBUGLOG(("GetTxnHeader::reserved_release_date = [%s]\n",csTmp));
                                	}
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else{
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnHeader::not found record!!\n");
                        iRet=INT_NOT_RECORD;
                	PutField_Int(hContext,"internal_error",iRet);
                }
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:GetTxnDetail\n"));
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnDetail::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"txn_ccy",&csCcy)) {
                                        PutField_CString(hContext,"org_txn_ccy",csCcy);
                                        //PutField_CString(hElement,"org_txn_ccy",csCcy);
                                        PutField_CString(hContext,"txn_ccy",csCcy);
                                        PutField_CString(hRequest,"txn_ccy",csCcy);
DEBUGLOG(("GetTxnDetail::txn_ccy = [%s]\n",csCcy));
                                }
                                if (GetField_CString(hRec,"txn_country",&csCountry)) {
                                        PutField_CString(hContext,"org_txn_country",csCountry);
                                        PutField_CString(hContext,"txn_country",csCountry);
                                        PutField_CString(hRequest,"txn_country",csCountry);
DEBUGLOG(("GetTxnDetail::txn_country = [%s]\n",csCountry));
                                }

                                if (GetField_CString(hRec,"pay_method",&csTmp)) {
                                        PutField_CString(hContext,"pay_method",csTmp);
DEBUGLOG(("GetTxnDetail::pay_method = [%s]\n",csTmp));
				}
                                if (GetField_CString(hRec,"bank_code",&csTmp)) {
                                        PutField_CString(hContext,"bank_code",csTmp);
DEBUGLOG(("GetTxnDetail::bank_code = [%s]\n",csTmp));
				}
                                if (GetField_CString(hRec,"language",&csTmp)) {
                                        PutField_CString(hContext,"language",csTmp);
DEBUGLOG(("GetTxnDetail::language = [%s]\n",csTmp));
				}
                                if (GetField_CString(hRec,"encrypt_type",&csTmp)) {
                                        PutField_CString(hContext,"encrypt_type",csTmp);
DEBUGLOG(("GetTxnDetail::encrypt_type = [%s]\n",csTmp));
				}
                                if (GetField_CString(hRec,"selected_pay_method",&csTmp)) {
                                        PutField_CString(hContext,"selected_pay_method",csTmp);
DEBUGLOG(("GetTxnDetail::selected_pay_method = [%s]\n",csTmp));
				}
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("GetTxnDetail:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnDetail:: not found record!!\n");
                        iRet = INT_NOT_RECORD;
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
				if (GetField_CString(hRec,"psp_id",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::psp_id = [%s]\n",csTmp));
					PutField_CString(hContext,"org_psp_id",csTmp);
					PutField_CString(hContext,"psp_id",csTmp);
				}
				if (GetField_CString(hRec,"txn_ccy",&csPspCcy)) {
DEBUGLOG(("GetTxnPspDetail::psp_txn_ccy = [%s]\n",csPspCcy));
					PutField_CString(hContext,"org_dst_txn_ccy",csPspCcy);
					PutField_CString(hContext,"txn_ccy",csPspCcy);
				}
				if (GetField_Double(hRec,"txn_amt",&dPspTxnAmt)) {
					PutField_Double(hContext,"org_dst_net_amt",dPspTxnAmt);
					PutField_Double(hContext,"psp_txn_amt",dPspTxnAmt);
DEBUGLOG(("GetTxnPspDetail::psp_txn_amt = [%lf]\n",dPspTxnAmt));
				}
/*
				if (GetField_Double(hRec,"service_fee",&dServiceFee)) {
					//PutField_Double(hContext,"precal_fee",dServiceFee);
					//PutField_Double(hContext,"service_fee",dServiceFee);
DEBUGLOG(("GetTxnPspDetail::service_fee = [%lf]\n",dServiceFee));
					if(iReturnPspFee==PD_FALSE){
						dServiceFee = 0.0;
					}
					PutField_Double(hContext,"precal_fee",dServiceFee);
					PutField_Double(hContext,"service_fee",dServiceFee);
				}
*/
				if (GetField_CString(hRec,"txn_date",&csOrgPostDate)) {
DEBUGLOG(("GetTxnPspDetail::txn_date = [%s]\n",csOrgPostDate));
				}
				if (GetField_CString(hRec,"tid",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::tid = [%s]\n",csTmp));
					PutField_CString(hContext,"tid",csTmp);
				}
				if (GetField_CString(hRec,"bank_code",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::bank_code = [%s]\n",csTmp));
					PutField_CString(hContext,"bank_code",csTmp);
				}
				if (GetField_CString(hRec,"fundin_date",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::fundin_date = [%s]\n",csTmp));
					PutField_CString(hContext,"fundin_date",csTmp);
				}
				if (GetField_CString(hRec,"bank_bill_no",&csTmp)) {
DEBUGLOG(("GetTxnPspDetail::bank_bill_no = [%s]\n",csTmp));
					PutField_CString(hContext,"bank_bill_no",csTmp);
				}

				if (GetField_Int(hRec, "recon_ind", &iTmp)) {
					PutField_Int(hContext,"recon_ind",iTmp);
DEBUGLOG(("GetTxnPspDetail::recon_ind = [%d]\n",iTmp));

					if (iTmp == PD_FALSE) {
DEBUGLOG(("GetTxnPspDetail::not allow to reverse before recon\n"));
						iRet = INT_INVALID_TXN;
                				PutField_Int(hContext,"internal_error",iRet);
						break;
					}

				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
DEBUGLOG(("GetTxnPspDetail:: not found record for [%s]\n",csOrgTxnSeq));
ERRLOG("TxnMgtByUsVDR:Authorize::GetTxnDetail:: not found record!!\n");
                        iRet = INT_NOT_RECORD;
                	PutField_Int(hContext,"internal_error",iRet);
                }
	}
/*
	if (iRet == PD_OK) {

//add txn amt element//
DEBUGLOG(("Authorize::Call BOTxnElements:AddTxnAmtElement\n"));
		PutField_CString(hElement,"amount_type",PD_DR);
		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
		iRet = (unsigned long)(*BOObjPtr)(hElement);
	}
*/

	if (iRet == PD_OK) {
//get previous charge
                recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTxnElements","GetFeeChgDetailByType");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_ELEMENT_TXN_FEE,PD_TYPE_MERCHANT,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Double(hRec,"amount",&dTmp)) {
					dPreFee += dTmp;
DEBUGLOG(("BOFee:GetFeeChgDetailByType() previous fee = [%lf]\n",dTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		
	}


	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));
		PutField_CString(hContext,"txn_code",PD_VOID_TXN_CODE);
		if(GetField_CString(hContext,"new_txn_code",&csNewTxnCode)){
                        if(!strcmp(csNewTxnCode, PD_DEPOSIT_CHARGEBACK_WITH_FEE)){
                                PutField_CString(hContext,"sub_txn_code",PD_DEPOSIT_CHARGEBACK);
                        }else{
                                PutField_CString(hContext,"sub_txn_code",PD_DEPOSIT_VOID);
                        }
                }else{
                        PutField_CString(hContext,"sub_txn_code",PD_DEPOSIT_VOID);
                }
                BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                if((unsigned long)(*BOObjPtr)(hContext,hRequest)==PD_OK){
                        if(GetField_Double(hContext,"src_txn_fee",&dFee)){
DEBUGLOG(("Authorize::deposit (void) txn fee=[%f]\n",dFee));
			}
			if(GetField_Double(hContext,"net_amt",&dTmp)){
DEBUGLOG(("Authorize::deposit (void) net amt=[%f]\n",dTmp));

				/*real net amt = net amt - previous fee*/
				PutField_Double(hContext,"net_amt",(dTmp-dPreFee));
DEBUGLOG(("Authorize::deposit (void) real net amt=[%f]\n",(dTmp-dPreFee)));
				
                        }

			/*add txn fee element*/
			BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnFeeElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext);

                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::BOFee:GetTxnFee Error\n"));
ERRLOG("TxnMgtByUsVDR:Authorize::BOFee:GetTxnFee Error\n");
                }
	}

/*	
	if((iRet == PD_OK) && (dFee>0)){
DEBUGLOG(("Authorize::Call BOBalance:UpdateMerchantAvalAmt\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdateMerchantAvalAmt");
                if((unsigned long)(*BOObjPtr)(csCountry,csServiceCode,csCcy,csMerchantId,dFee*(-1))!=PD_OK)
			iRet = INT_ERR;
	}
*/

	if(iRet==PD_OK){
                if(iReturnPspFee==PD_FALSE){
                        dServiceFee = 0.0;
                }
                else{
			char    csRemark[PD_REMARK_LEN+1];
                        if (GetField_Double(hContext,"actual_psp_fee",&dServiceFee)) {
DEBUGLOG(("Authorize::actual_psp_fee = [%lf]\n",dServiceFee));
				sprintf(csRemark,"Return PSP actual fee: %lf",dServiceFee);
				if (iDepositChargeback == PD_FALSE) {
					sprintf(csRemark,"Return PSP actual fee: %lf",dServiceFee);
                                } else {
                                        sprintf(csRemark,"Chargeback PSP actual fee: %lf",dServiceFee);
                                }
                                PutField_CString(hContext,"remark",csRemark);
                        }
                }
                PutField_Double(hContext,"precal_fee",dServiceFee);
                PutField_Double(hContext,"service_fee",dServiceFee);
        }

	if (iRet == PD_OK) {
		PutField_Int(hContext,"reserve_released",iReleased);
DEBUGLOG(("Authorize::Call BOBalance:UpdateTxnAmount\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdateTxnAmount");
                if((unsigned long)(*BOObjPtr)(hContext,hRequest)!=PD_OK)
			iRet = INT_ERR;
	}


	if(iRet==PD_OK){
DEBUGLOG(("Call Update Org Transaction\n"));
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		if((unsigned long) ((*DBObjPtr)(hOrgTxn))!=PD_OK)
                        iRet = INT_ERR;
	}

	if(iRet==PD_OK){
DEBUGLOG(("Call Add Transaction Detail\n"));
		PutField_CString(hContext,"txn_ccy",csCcy);
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
	}


	if(iRet==PD_OK){
DEBUGLOG(("Call Update Transaction Detail\n"));
		if(GetField_Double(hContext,"merchant_open_bal",&dTmp)){
			PutField_Double(hContext,"open_bal",dTmp);
		}
		if(GetField_Double(hContext,"merchant_open_bal_settlement",&dTmp)){
			PutField_Double(hContext,"open_bal_settlement",dTmp);
		}
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
	}

	if(iRet==PD_OK){
DEBUGLOG(("Call Add TxnPspDetail\n"));
		PutField_CString(hContext,"txn_ccy",csPspCcy);
		if(GetField_CString(hRequest,"psp_date",&csTmp)){
			PutField_CString(hContext,"txn_date",csTmp);
		}
		else{
			if(GetField_CString(hContext,"PHDATE",&csTmp)){
				PutField_CString(hContext,"txn_date",csTmp);
			}
		}
		if (iDepositChargeback == PD_FALSE) {
			PutField_CString(hContext,"desc","Void Deposit with merchant fee");
                } else {
			PutField_CString(hContext,"desc","Chargeback Deposit with merchant fee");
                }
		PutField_Double(hContext,"service_fee",dServiceFee);
		PutField_Double(hContext,"txn_amt",dPspTxnAmt);
        	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
		PutField_Double(hContext,"txn_amt",dTxnAmt);//resume the txn_amt
	}

	if(iRet==PD_OK){
		if(GetField_Double(hContext,"psp_balance",&dTmp)){
			PutField_Double(hContext,"bal",dTmp);
		}
		if(GetField_Double(hContext,"psp_total_float",&dTmp)){
			PutField_Double(hContext,"total_float",dTmp);
		}
		if(GetField_Double(hContext,"psp_total_hold",&dTmp)){
			PutField_Double(hContext,"total_hold",dTmp);
		}
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        iRet = INT_ERR;
	}

/*
	if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }
*/
	RecordSet_Destroy(rRecordSet);
        //FREE_ME(hElement);
        FREE_ME(hOrgTxn);
	FREE_ME(rRecordSet);

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}
