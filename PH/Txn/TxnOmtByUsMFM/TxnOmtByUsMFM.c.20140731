/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMFM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

void TxnOmtByUsMFM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csMerchantId;
	char*	csServiceCode;
	char*	csTxnCcy;
	char*	csTxnCountry;
	char*	csPostingDate;
	char*	csUser;
	char*	csTmp;
	double	dTmp=0.0;
	double	dAmt=0.0;
	double	dNetAval=0.0;
	double	dActualPayoutBal=0.0;
	double	dAvalPayoutBal=0.0;


DEBUGLOG(("Authorize\n"));
        if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
                PutField_CString(hContext,"merchant_id",csMerchantId);
        }
        else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnOmtByUsMFM::Authorize::merchant_id not found!!\n");
                iRet=INT_MERCHANT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }
        if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
                PutField_CString(hContext,"service_code",csServiceCode);
        }
        else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnOmtByUsMFM::Authorize::service_code not found!!\n");
                iRet=INT_SERVICE_CODE_MISSING;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
                PutField_CString(hContext,"txn_ccy",csTxnCcy);
                PutField_CString(hContext,"net_ccy",csTxnCcy);
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsMFM::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
                PutField_CString(hContext,"txn_country",csTxnCountry);
        }
        else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnOmtByUsMFM::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_Double(hContext,"txn_amt",&dAmt)){
                PutField_Double(hContext,"txn_amt",dAmt);
                PutField_Double(hContext,"net_amt",dAmt);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsMFM::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	if(GetField_CString(hRequest,"add_user",&csUser)){
		PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize::user = [%s]\n",csUser));
	}

	//find net available payout(current available payout - fundin payout)
	if(iRet==PD_OK){
DEBUGLOG(("CheckAvalBalance::Call BOOLBalance:GetAvalPayoutBalance\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLBalance","GetAvalPayoutBalance");
		if((unsigned long)(*BOObjPtr)(hContext,
					hRequest,
					&dActualPayoutBal,
					&dAvalPayoutBal)==PD_OK){
			/*
			if(GetField_Double(hContext,"merchant_net_float",&dNetAval)){
DEBUGLOG(("CheckAvalBalance::GetAvalBalance for payout: Net Available[%f]\n",dNetAval));
			}
			*/
			if(GetField_Double(hContext,"merchant_ava_po_move",&dNetAval)){
DEBUGLOG(("CheckAvalBalance::GetAvalBalance for payout: Net Available[%f]\n",dNetAval));
			}
DEBUGLOG(("CheckAvalBalance::GetAvalBalance for payout: Actual[%f] Available[%f]\n",dActualPayoutBal,dAvalPayoutBal));
		}
		else{
DEBUGLOG(("CheckAvalBalance::GetAvalPayoutBalance Error\n"));
ERRLOG("TxnOmtByUsMFM::CheckAvalBalance::GetAvalPayoutBalance Error!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	//check if dAmt <= net available payout
	if(iRet==PD_OK){
		if(dNetAval<dAmt){
			iRet=INT_INSUFFICIENT_FUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("CheckAvalBalance::Net Aval Payout Amt[%f] < Request Amt[%f]\n",dNetAval,dAmt));
ERRLOG("TxnOmtByUsMFM::CheckAvalBalance::insufficient aval payout balance!!\n");
		}
	}
	
	//log dAmt as AF with PHDATE to ol_merchant_bucket
	if(iRet==PD_OK){
		if(GetField_CString(hContext,"PHDATE",&csPostingDate)){
			PutField_CString(hContext,"post_date",csPostingDate);
DEBUGLOG(("Authorize::PHDATE = [%s]\n",csPostingDate));
		}

		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBucket","CreditMerchantAmount");
		if ((*DBObjPtr)(csPostingDate,
				csMerchantId,
				csTxnCountry,
				csTxnCcy,
				csServiceCode,
				PD_DEFAULT_PSP,
				PD_BUCKET_TYPE_AFTER_PAYOUT_FLOAT,
				dAmt,
				csUser) != PD_OK) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("BOOLBalance:CreditMerchantAmount [After Payout Float]Failed\n"));
ERRLOG("TxnOmtByUsMFM::CreditMerchantAmount [After Payout Float]Failed !!\n");
		}
		
	}

	//get the opening balance
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetOpenBalanceForUpdate");
                if ((*DBObjPtr)(hContext,
                                csMerchantId,
                                csTxnCcy,
                                csTxnCountry,
                                csServiceCode) != PD_OK) {
                        iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("DBOLMerchantBalance: GetOpenBalanceForUpdate Failed\n"));
ERRLOG("TxnOmtByUsMFM::DBOLMerchantBalance GetOpenBalanceForUpdate Failed!!\n");
                }
	}
	
	//add dAmt to om_total_float_after_payout
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","Rls2AfterPOFloat");
		if((unsigned long)(DBObjPtr)(csMerchantId,
					     csTxnCountry,
					     csTxnCcy,
					     csServiceCode,
					     dAmt,
					     csUser)!=PD_OK){
                        iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("DBOLMerchantBalance: Rls2AfterPOFloat Failed\n"));
ERRLOG("TxnOmtByUsMFM::DBOLMerchantBalance Rls2AfterPOFloat Failed!!\n");
		}
	}

	//GetCurrentValues
	if(iRet==PD_OK){
		hash_t* hVal;
		hVal = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hVal,0);

                DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetCurrentValues");
                if((unsigned long)(*DBObjPtr)(csMerchantId,csTxnCcy,csTxnCountry,csServiceCode,hVal)!=PD_ERR){
                        if(GetField_Double(hVal,"current_bal",&dTmp)){
                                PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("BOOLBalance: current_bal= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
                                PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("BOOLBalance: total_reserved_amount= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold",&dTmp)){
                                PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("BOOLBalance: total_hold= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
                                PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("BOOLBalance: current_bal_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
                                PutField_Double(hContext,"total_float_settlement",dTmp);
DEBUGLOG(("BOOLBalance: total_float_settlement= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_hold_settlement",&dTmp)){
                                PutField_Double(hContext,"total_hold_settlement",dTmp);
DEBUGLOG(("BOOLBalance: total_hold= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"fundin_payout",&dTmp)){
                                PutField_Double(hContext,"fundin_payout",dTmp);
DEBUGLOG(("BOOLBalance: fundin_payout= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"reserved_payout",&dTmp)){
                                PutField_Double(hContext,"reserved_payout",dTmp);
DEBUGLOG(("BOOLBalance: reserved_payout= [%f]\n",dTmp));
                        }
                        if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
                                PutField_Double(hContext,"total_float_after_payout",dTmp);
DEBUGLOG(("BOOLBalance: total_float_after_payout= [%f]\n",dTmp));
                        }


DEBUGLOG(("Authorize::Call OMTChannel:UpdateTxnDetailLog\n"));
			ChannelObjPtr = CreateObj(ChannelPtr, "OMTChannel","UpdateTxnDetailLog");
			if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
				iRet = INT_ERR;
			}
		}
		FREE_ME(hVal);
	}

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hResponse,"org_txn_seq",csTmp);
	}
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
                (*DBObjPtr)(hContext);
DEBUGLOG(("TxnOmtByUsMFM:Authorize  SystemControl::GetApprovalDT called\n"));
	}


	if(iRet==PD_OK){
		PutField_CString(hContext, "sub_status", PD_APPROVED);
	}

DEBUGLOG(("TxnOmtByUsMFM Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
