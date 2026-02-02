/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/29              Virginia Yun
combine Hanlder and process balance		   2011/12/21		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOMmsBalance.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOMmsBalance(char    cdebug)
{
	cDebug = cdebug;
}

int GetPspCountry(hash_t *hRls);
int GetMerchCountry(hash_t *hRls);

int ProcessPspBalance(hash_t *hRls);
int ProcessMBBalance(hash_t *hRls);
int ProcessBankBalance(hash_t *hRls);
int ProcessMerchantBalance(hash_t *hRls);



int TxnTypeHandler(hash_t *hRls)
{
	int	iRet = PD_OK;
	char	cTmp;
	char	*csTmp;

/* isd_ind */
	if (GetField_Char(hRls, "isd_ind", &cTmp)) {
DEBUGLOG(("BOMmsBalance::TxnTypeHandler: isd_ind [%c]\n", cTmp));
		if (cTmp != PD_SOURCE && cTmp != PD_DESTINATION) {
DEBUGLOG(("BOMmsBalance::TxnTypeHandler: invalid isd_ind [%c]\n", cTmp));
ERRLOG("BOMmsBalance::TxnTypeHandler: invalid isd_ind [%c]\n", cTmp);
			iRet = INT_ERR;
		}
	}
	else {
DEBUGLOG(("BOMmsBalance::TxnTypeHandler: get isd_ind failed\n"));
ERRLOG("BOMmsBalance::TxnTypeHandler: get isd_ind failed\n");
		iRet = INT_ERR;
	}

/* Ccy */
        if(GetField_CString(hRls,"txn_ccy",&csTmp)){
DEBUGLOG(("BOMmsBalance::TxnTypeHandler:ccy = [%s]\n",csTmp));
        }
        else{
DEBUGLOG(("BOMmsBalance::TxnTypeHandler:ccy not found!!\n"));
ERRLOG("BOMmsBalance::TxnTypeHandler::ccy not found!!\n");
                iRet = INT_CURRENCY_CODE_NOT_FOUND;
        }


	if (iRet == PD_OK) {
		if (GetField_CString(hRls,"party_type",&csTmp)) {
			if(!strcmp(csTmp,PD_MMS_PARTY_PSP)) {
				iRet = ProcessPspBalance(hRls);
			} else if (!strcmp(csTmp,PD_MMS_PARTY_MERCH)) {
				iRet = ProcessMerchantBalance(hRls);
			} else if(!strcmp(csTmp,PD_MMS_PARTY_MB)) {
				iRet = ProcessMBBalance(hRls);
			} else if(!strcmp(csTmp,PD_MMS_PARTY_BANK)) {
				iRet = ProcessBankBalance(hRls);
			} else {
DEBUGLOG(("BOMmsBalance::TxnTypeHandler: invalid party_type [%s]\n", csTmp));
ERRLOG("BOMmsBalance::TxnTypeHandler: invalid party_type [%s]\n", csTmp);
				iRet = INT_ERR;
			}
		} 
		else {
DEBUGLOG(("BOMmsBalance::TxnTypeHandler: get party_type failed\n"));
ERRLOG("BOMmsBalance::TxnTypeHandler: get party_type failed\n");
			iRet = INT_ERR;
		}
	}

DEBUGLOG(("BOMmsBalance::TxnTypeHandlerHandler: exit iRet = [%d]\n", iRet));
	
	return 	iRet;
}


int GetPspCountry(hash_t *hRls)
{
	char *csPspId = NULL;
	char *csTxnCountry = NULL;
	hash_t  *hRec;
	int	iRet = PD_OK;

	recordset_t     *rRecordSet;


	if (GetField_CString(hRls, "txn_country", &csTxnCountry)) {
DEBUGLOG(("GetPspCountry::country = [%s]\n",csTxnCountry));
		return iRet;
	}

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("BOMmsBalance::GetPspCountry:Call PspCountry:GetPspCountry\n"));

	GetField_CString(hRls, "psp_id", &csPspId);

DEBUGLOG(("BOMmsBalance::GetPspContry:psp_id [%s]\n", csPspId));

	DBObjPtr = CreateObj(DBPtr,"DBPspCountry","GetPspCountry");
	if ((*DBObjPtr)(csPspId, rRecordSet) == PD_OK) {
DEBUGLOG(("GetPspCountry::found record = [%s]\n", csPspId));
		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {
			if (GetField_CString(hRec,"country",&csTxnCountry)) {
DEBUGLOG(("GetPspCountry::country = [%s]\n",csTxnCountry));
				PutField_CString(hRls, "txn_country", csTxnCountry);
			}
			hRec = RecordSet_GetNext(rRecordSet);
		}
	}	
	else{
DEBUGLOG(("GetPspCountry:: not found record for [%s]\n",csPspId));
ERRLOG("BOMmsBalance:GetPspCountry::GetPspCountry::not found record!!\n");
		iRet = INT_NOT_RECORD;
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;

}

int GetMerchCountry(hash_t *hRls)
{
	char	*csServiceCode = NULL;
	int	iRet = PD_OK;

	char    *csTxnCountry = strdup("");

	if (GetField_CString(hRls, "txn_country", &csTxnCountry)) {
DEBUGLOG(("GetPspCountry::country = [%s]\n",csTxnCountry));  
		return iRet;
	}

	if (!GetField_CString(hRls, "service_code", &csServiceCode)) {
DEBUGLOG(("GetMerchCountry:: service_code not found\n"));
ERRLOG("BOMmsBalance:GetMerchCountry::service_code not found!\n");
		iRet = PD_ERR;
	}

	/* Get Country by Service */
	if (iRet == PD_OK) {
DEBUGLOG(("BOMmsBalance::GetMerchCountry:Call Service:FindCountryByService\n"));
		DBObjPtr = CreateObj(DBPtr,"DBService","FindCountryByService");
		if ((unsigned long)((*DBObjPtr)(csServiceCode, csTxnCountry)) == FOUND) {

DEBUGLOG(("GetMerchCountry::country = [%s]\n",csTxnCountry));
			PutField_CString(hRls, "txn_country", csTxnCountry);
		}
		else {
DEBUGLOG(("GetMerchCountry:: country not found for service [%s]\n",csTxnCountry));
ERRLOG("BOMmsBalance:GetMerchCountry::Service::FindCountryByService::not found record!!\n");
			iRet = INT_NOT_RECORD;
		}
	}

	FREE_ME(csTxnCountry);

	return iRet;

}


int ProcessPspBalance(hash_t *hRls)
{
	int	iRet = PD_OK;

	char	*csPspId = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;
	char	*csUpdateUser = NULL;

	double	dAmt = 0.0;
	double  dProcessingCost = 0.0;
	double  dBankCharge= 0.0;
	double  dBankChargeRefund= 0.0;
	double  dAdjustment = 0.0;

	char 	cType;
	double  dAvaBalance = 0.0;
	double  dTransferAmt= 0.0;

	int	iVoidFlag = PD_FALSE;
	char    csTagAction[PD_TAG_LEN + 1];


	if (GetField_Char(hRls,"isd_ind",&cType)) {
DEBUGLOG(("ProcessPspBalance::isd_ind= [%c]\n",cType));
	}

/* psp_id */
	if(GetField_CString(hRls,"psp_id",&csPspId)){
DEBUGLOG(("ProcessPspBalance::psp_id = [%s]\n",csPspId));
	}
	else{
DEBUGLOG(("ProcessPspBalance:psp_id not found!!\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::psp_id not found\n");
		iRet = INT_PSP_ID_NOT_FOUND;
	}

/* Ccy */
	if(GetField_CString(hRls,"txn_ccy",&csCcy)){
DEBUGLOG(("ProcessPspBalance::ccy = [%s]\n",csCcy));
	}


/* Update_user */
	if(GetField_CString(hRls,"update_user",&csUpdateUser)){
DEBUGLOG(("ProcessPspBalance::update_user = [%s]\n",csUpdateUser));
	}
	else{
DEBUGLOG(("ProcessPspBalance:update_user not found!!\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::update_user Failed\n");
	}

/* For in-transit */
/* Amt */
	if(GetField_Double(hRls,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessPspBalance::txn_amt = [%lf]\n",dAmt));
	}
	else{
DEBUGLOG(("ProcessPspBalance:txn_amt not found!!\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::txn_amt Failed\n");
		iRet = INT_TXN_AMT_MISSING;
	}

/* For processing_cost */
	if(GetField_Double(hRls,"processing_cost",&dProcessingCost)){
DEBUGLOG(("ProcessPspBalance::processing_cost = [%lf]\n",dProcessingCost));
	}
	else{
DEBUGLOG(("ProcessPspBalance:processing_cost not found!!\n"));
		dProcessingCost = 0.0;
	}

/* For bank_charge */
        if(GetField_Double(hRls,"bank_charge",&dBankCharge)){
DEBUGLOG(("ProcessPspBalance::bank_charge = [%lf]\n",dBankCharge));
        }
        else{
DEBUGLOG(("ProcessPspBalance:bank_charge not found!!\n"));
                dBankCharge = 0.0;
        }

/* For bank_charge_refund */
        if(GetField_Double(hRls,"bank_charge_refund",&dBankChargeRefund)){
DEBUGLOG(("ProcessPspBalance::bank_charge_refund = [%lf]\n",dBankChargeRefund));
        }
        else{
DEBUGLOG(("ProcessPspBalance:bank_charge_refund not found!!\n"));
                dBankChargeRefund = 0.0;
        }

/* For Adjustment */
        if(GetField_Double(hRls,"adjustment",&dAdjustment)){
DEBUGLOG(("ProcessPspBalance::adjustment = [%lf]\n",dAdjustment));
        }
        else{
DEBUGLOG(("ProcessPspBalance:adjustment not found!!\n"));
                dAdjustment = 0.0;
        }

/* Get Country */
	if (iRet == PD_OK){

		if (GetField_CString(hRls, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessPspBalance::txn_country = [%s]\n",csCountry));
		}
		else {
			if (GetPspCountry(hRls) == PD_OK) {
				if (GetField_CString(hRls, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessPspBalance::txn_country = [%s]\n",csCountry));
				}
				else {
DEBUGLOG(("ProcessPspBalance::txn_country Failed\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::txn_country Failed\n");
					iRet = INT_COUNTRY_PSP_NOT_AVABILE;
				}
			} else {
DEBUGLOG(("ProcessPspBalance::GetPspCountry Failed\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::GetPpsCountry Failed\n");
				iRet = INT_COUNTRY_PSP_NOT_AVABILE;
			}
		}
	}


	if (GetField_Int(hRls, "void_flag", &iVoidFlag)) {
DEBUGLOG(("ProcessPspBalance::void_flag = [%d]\n",iVoidFlag));
	}


/* Debit Balance - Amt */
	if (iRet == PD_OK){
DEBUGLOG(("BOMmsBalance::ProcessPspBalance::Call BOBalance:GetAvalPspBalanceForUpdate\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","GetAvalPspBalanceForUpdate");
		if((unsigned long)((*BOObjPtr)(csCountry, csCcy, csPspId, &dAvaBalance) != PD_OK)) {
DEBUGLOG(("BOMmsBalance::ProcessPspBalance::BOBalance:GetAvalPspBalanceForUpdate Failed\n"));
ERRLOG("BOMmsBalance::ProcessPspBalance::BOBalance:GetAvalPspBalanceForUpdate Failed\n");
			iRet=INT_ERR;
		}
		else {
DEBUGLOG(("BOMmsBalance::ProcessPspBalance::PSP Balance [%lf]\n", dAvaBalance));
		}
	}


	if (iRet == PD_OK) {
		memset(csTagAction, 0, sizeof(csTagAction));

		if (cType == PD_SOURCE) {
			dTransferAmt = dAmt + dProcessingCost + dBankCharge + dAdjustment - dBankChargeRefund;

DEBUGLOG(("ProcessPspBalance::Type[%c] Void[%d] TransferAmt [%lf]\n", dTransferAmt));

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "DebitBalance");
				if ((dAvaBalance - dTransferAmt) <  0.0) {
					iRet = INT_INSUFFICIENT_FUND;
				}
			} else {
				sprintf(csTagAction, "%s", "CreditBalance");
				if ((dAvaBalance + dTransferAmt) < 0.0){
					iRet = INT_INSUFFICIENT_FUND;
				}
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessPspBalance::Type[%c] Void[%d] Not enought Ava Balance for pps[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csPspId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessPspBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
		else { //DEST
			dTransferAmt = dAmt;

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "CreditBalance");
				if ((dAvaBalance + dTransferAmt) <0.0){
					iRet = INT_INSUFFICIENT_FUND;
				} 
			}
			else {
				sprintf(csTagAction, "%s", "DebitBalance");
				if ((dAvaBalance - dTransferAmt) < 0.0) {
					iRet = INT_INSUFFICIENT_FUND;
				}
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessPspBalance::Type[%c] Void[%d] Not enought Ava Balance for pps[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csPspId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessPspBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}

DEBUGLOG(("ProcessPspBalance::Type [%c] Action = [%s]\n", cType, csTagAction)); 

		if(iRet == PD_OK){
DEBUGLOG(("ProcessPspBalance::Type = [%c] void = [%d] Call DBPspBalance:[%s]\n", cType, iVoidFlag, csTagAction));
			DBObjPtr = CreateObj(DBPtr,"DBPspBalance", csTagAction);
			if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dTransferAmt, csUpdateUser) != PD_OK) {

DEBUGLOG(("ProcessPspBalance::DBPspBalance:Type = [%c] void = [%d] %s [%lf] Failed\n", cType, iVoidFlag, csTagAction, dTransferAmt));
ERRLOG("BOMmsBalance::ProcessPspBalance::DBPspBalance:Type [%c] void = [%d] %s [%lf] failed\n",cType, iVoidFlag, csTagAction, dTransferAmt);
				iRet = INT_ERR;
			}
		}


		if (iRet == PD_OK) {
			hash_t *hVal;
	                hVal = (hash_t*) malloc (sizeof(hash_t));
	                hash_init(hVal,0);

			double dTmp = 0.0;

                	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetBalance");
                	if((unsigned long)(*DBObjPtr)(csPspId,csCountry,csCcy,hVal)!=PD_ERR){

	                        if(GetField_Double(hVal,"balance",&dTmp)){
					PutField_Double(hRls,"psp_balance",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessPspBalance:psp_balance = [%f]\n",dTmp));
                        	}
	                        if(GetField_Double(hVal,"total_float",&dTmp)){
	                                PutField_Double(hRls,"psp_total_float",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessPspBalance:psp_total_float = [%f]\n",dTmp));
                        	}
	                        if(GetField_Double(hVal,"total_hold",&dTmp)){
	                                PutField_Double(hRls,"psp_total_hold",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessPspBalance:psp_total_hold = [%f]\n",dTmp));
        	                }
			}

			FREE_ME(hVal);
		}

	}

	if (iRet == PD_OK) {
		PutField_Double(hRls, "net_amt", dTransferAmt);
	}


	return iRet;		
}

int ProcessMBBalance(hash_t *hRls)
{
	int     iRet = PD_OK;

	char    *csMBId = NULL;
	char    *csCcy = NULL;
	char    *csUpdateUser = NULL;

	double  dAmt = 0.0;
	double  dProcessingCost = 0.0;
	double  dBankCharge = 0.0;
	double	dBankChargeRefund = 0.0;
	double	dAdjustment = 0.0;

	char	cType;
	double  dAvaBalance = 0.0;
	double  dTransferAmt= 0.0;

	int	iVoidFlag = PD_FALSE;
	char	csTagAction[PD_TAG_LEN + 1];

	if (GetField_Char(hRls,"isd_ind",&cType)) {
DEBUGLOG(("ProcessMBBalance::isd_ind= [%c]\n",cType));
	}

/* mb_id */
	if(GetField_CString(hRls,"mb_id",&csMBId)){
DEBUGLOG(("ProcessMBBalance::mb_id = [%s]\n",csMBId));
	}
	else{
DEBUGLOG(("ProcessMBBalance:mb_id not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMBBalance::mb_id not found\n");
		iRet = INT_MB_ID_NOT_FOUND;
	}

/* Ccy */
	if(GetField_CString(hRls,"txn_ccy",&csCcy)){
DEBUGLOG(("ProcessMBBalance::ccy = [%s]\n",csCcy));
	}

/* Update_user */
	if(GetField_CString(hRls,"update_user",&csUpdateUser)){
DEBUGLOG(("ProcessMBBalance::update_user = [%s]\n",csUpdateUser));
	}
	else{
DEBUGLOG(("ProcessMBBalance::update_user not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMBBalance::update_user Failed\n");
	}

/* For in-transit */
/* Amt */
	if(GetField_Double(hRls,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessMBBalance::txn_amt = [%lf]\n",dAmt));
	}
	else{
DEBUGLOG(("ProcessMBBalance:txn_amt not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMBBalance::txn_amt Failed\n");
		iRet = INT_TXN_AMT_MISSING;
	}

/* For processing_cost */
        if(GetField_Double(hRls,"processing_cost",&dProcessingCost)){
DEBUGLOG(("ProcessMBBalance::processing_cost = [%lf]\n",dProcessingCost));
        }
        else{
DEBUGLOG(("ProcessMBBlance::processing_cost not found!!\n"));
                dProcessingCost = 0.0;
        }

/* For bank_charge */
        if(GetField_Double(hRls,"bank_charge",&dBankCharge)){
DEBUGLOG(("ProcessMBBalance::bank_charge = [%lf]\n",dBankCharge));
        }
        else{
DEBUGLOG(("ProcessMBBalance::bank_charge not found!!\n"));
                dBankCharge = 0.0;
        }

/* For bank_charge_refund */
        if(GetField_Double(hRls,"bank_charge_refund",&dBankChargeRefund)){
DEBUGLOG(("ProcessMBBalance::bank_charge_refund = [%lf]\n",dBankChargeRefund));
        }
        else{
DEBUGLOG(("ProcessMBBalance:bank_charge_refund not found!!\n"));
                dBankChargeRefund = 0.0;
        }

/* For Adjustment */
        if(GetField_Double(hRls,"adjustment",&dAdjustment)){
DEBUGLOG(("ProcessMBBalance::adjustment = [%lf]\n",dAdjustment));
        }
        else{
DEBUGLOG(("ProcessMBBalance:adjustment not found!!\n"));
                dAdjustment = 0.0;
        }


/* void flag */
	if (GetField_Int(hRls, "void_flag", &iVoidFlag)) {
DEBUGLOG(("ProcessMBBalance::void_flag = [%d]\n",iVoidFlag));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("BOMmsBalance::ProcessMBBalance::Call MmsMBBalance:GetAvalMBBalance\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsMBBalance", "GetAvalMBBalance");
		if((unsigned long)(*DBObjPtr)(csMBId, csCcy, &dAvaBalance) != PD_OK){

DEBUGLOG(("BOMmsBalance::ProcessMBBalance::MmsMBBalance:GetAvalMBBalance Failed\n"));
ERRLOG("BOMmsBalance::ProcessMBBalance::MmsMBBalance:GetAvalMBBalance Failed\n");
			iRet=INT_ERR;
		}
		else {
DEBUGLOG(("BOMmsBalance::ProcessMBBalance::MB Balance [%lf]\n", dAvaBalance));
		}

	}

	if (iRet == PD_OK){
		memset(csTagAction, 0, sizeof(csTagAction));

		if(cType==PD_SOURCE){
			dTransferAmt = dAmt + dProcessingCost + dBankCharge + dAdjustment - dBankChargeRefund;

DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] TransferAmt [%lf]\n", cType, iVoidFlag, dTransferAmt));

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "DebitBalance");
				if ((dAvaBalance - dTransferAmt) < 0.0) {
					iRet = INT_INSUFFICIENT_FUND;
				} 
			} else {
				sprintf(csTagAction, "%s", "CreditBalance");
				if ((dAvaBalance + dTransferAmt) < 0.0) {
					iRet = INT_INSUFFICIENT_FUND;
				}
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] Not enought Ava Balance for mb_id[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csMBId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
		else{ //DEST

			dTransferAmt = dAmt;

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "CreditBalance");
				if ((dAvaBalance + dTransferAmt) < 0.0) {
					iRet = INT_INSUFFICIENT_FUND;
				}
			} else {
				sprintf(csTagAction, "%s", "DebitBalance");

				if ((dAvaBalance - dTransferAmt) < 0.0) {
					iRet = INT_INSUFFICIENT_FUND;
                                }
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] Not enought Ava Balance for mb_id[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csMBId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
DEBUGLOG(("ProcessMBBalance::Type [%c] Action = [%s]\n", cType, csTagAction));

		if (iRet == PD_OK) {
DEBUGLOG(("ProcessMBBalance::Type = [%c] void = [%d] Call DBMmsMBBalance:[%s]\n", cType, iVoidFlag, csTagAction));
			DBObjPtr = CreateObj(DBPtr,"DBMmsMBBalance",csTagAction);
			if ((*DBObjPtr)(csMBId,csCcy, dTransferAmt, csUpdateUser) != PD_OK) {
DEBUGLOG(("ProcessMBBalance::DBMmsMBBalance:Type = [%c] void = [%d] %s[%lf] Failed\n",cType, iVoidFlag, csTagAction, dTransferAmt));
ERRLOG("BOMmsBalance::ProcessMBBalance::DBMmsMBBalance: Type = [%c] void = [%d] %s [%lf] failed\n",cType, iVoidFlag, csTagAction, dTransferAmt);
				iRet = INT_ERR;
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_Double(hRls, "net_amt", dTransferAmt);
	}

	return iRet;

}

int ProcessBankBalance(hash_t *hRls)
{
	int     iRet = PD_OK;

	char    *csBankId = NULL;
	char    *csCcy = NULL;
	char    *csUpdateUser = NULL;

	double  dAmt = 0.0;
	double  dProcessingCost = 0.0;
	double  dBankCharge = 0.0;
	double	dBankChargeRefund = 0.0;
	double	dAdjustment = 0.0;

	char	cType;
	double  dAvaBalance = 0.0;
	double  dTransferAmt= 0.0;

	int	iVoidFlag = PD_FALSE;
	char	csTagAction[PD_TAG_LEN + 1];

	if (GetField_Char(hRls,"isd_ind",&cType)) {
DEBUGLOG(("ProcessBankBalance::isd_ind= [%c]\n",cType));
	}

/* bank_id */
	if(GetField_CString(hRls,"bank_id",&csBankId)){
DEBUGLOG(("ProcessBankBalance::bank_id = [%s]\n",csBankId));
	}
	else{
DEBUGLOG(("ProcessBankBalance:bank_id not found!!\n"));
ERRLOG("BOMmsBalance::ProcessBankBalance::bank_id not found\n");
		iRet = INT_BANK_ID_NOT_FOUND;
	}

/* Ccy */
	if(GetField_CString(hRls,"txn_ccy",&csCcy)){
DEBUGLOG(("ProcessBankBalance::ccy = [%s]\n",csCcy));
	}

/* Update_user */
	if(GetField_CString(hRls,"update_user",&csUpdateUser)){
DEBUGLOG(("ProcessBankBalance::update_user = [%s]\n",csUpdateUser));
	}
	else{
DEBUGLOG(("ProcessBankBalance:update_user not found!!\n"));
ERRLOG("BOMmsBalance::ProcessBankBalance::update_user Failed\n");
	}

/* For in-transit */
/* Amt */
	if(GetField_Double(hRls,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessBankBalance::txn_amt = [%lf]\n",dAmt));
	}
	else{
DEBUGLOG(("ProcessBankBalance:txn_amt not found!!\n"));
ERRLOG("BOMmsBalance::ProcessBankBalance::txn_amt Failed\n");
		iRet = INT_TXN_AMT_MISSING;
	}

/* For processing_cost */
	if(GetField_Double(hRls,"processing_cost",&dProcessingCost)){
DEBUGLOG(("ProcessBankBalance::processing_cost = [%lf]\n",dProcessingCost));
	}
	else{
DEBUGLOG(("ProcessBankBalance:processing_cost not found!!\n"));
		dProcessingCost = 0.0;
	}

/* For bank_charge */
        if(GetField_Double(hRls,"bank_charge",&dBankCharge)){
DEBUGLOG(("ProcessBankBalance::bank_charge = [%lf]\n",dBankCharge));
        }
        else{
DEBUGLOG(("ProcessBankBalance:bank_charge not found!!\n"));
                dBankCharge = 0.0;
        }

/* For bank_charge_refund */
        if(GetField_Double(hRls,"bank_charge_refund",&dBankChargeRefund)){
DEBUGLOG(("ProcessBankBalance::bank_charge_refund = [%lf]\n",dBankChargeRefund));
        }
        else{
DEBUGLOG(("ProcessBankBalance:bank_charge_refund not found!!\n"));
                dBankChargeRefund = 0.0;
        }

/* For Adjustment */
        if(GetField_Double(hRls,"adjustment",&dAdjustment)){
DEBUGLOG(("ProcessBankBalance::adjustment = [%lf]\n",dAdjustment));
        }
        else{
DEBUGLOG(("ProcessBankBalance:adjustment not found!!\n"));
                dAdjustment = 0.0;
        }


/* Void Flag */
	if (GetField_Int(hRls, "void_flag", &iVoidFlag)) {
DEBUGLOG(("ProcessBankBalance::void_flag = [%d]\n",iVoidFlag ));
                dBankCharge = 0.0;
	}

	if (iRet == PD_OK) {
DEBUGLOG(("BOMmsBalance::ProcessBankBalance::Call MmsBankBalance:GetAvalBankBalance\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsBankBalance", "GetAvalBankBalance");
		if((unsigned long)(*DBObjPtr)(csBankId,csCcy,&dAvaBalance) != PD_OK){

DEBUGLOG(("BOMmsBalance::ProcessBankBalance::MmsBankBalance:GetAvalBankBalance Failed\n"));
ERRLOG("BOMmsBalance::ProcessBankBalance::MmsBankBalance:GetAvalBankBalance Failed\n");
			iRet=INT_ERR;
		}
		else {
DEBUGLOG(("BOMmsBalance::ProcessBankBalance::Bank Balance [%lf]\n", dAvaBalance));
		}
	}

	if (iRet == PD_OK){
		memset(csTagAction, 0, sizeof(csTagAction));


		if(cType==PD_SOURCE){
			dTransferAmt = dAmt + dProcessingCost + dBankCharge + dBankChargeRefund + dAdjustment - dBankCharge;

DEBUGLOG(("BOMmsBalance::ProcessBankBalance::TransferAmt [%lf]\n", dTransferAmt));

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "DebitBalance");
				if ((dAvaBalance - dTransferAmt) < 0.0) {
                                        iRet = INT_INSUFFICIENT_FUND;
				}
			}
			else {
				sprintf(csTagAction, "%s", "CrecditBalance");
				if ((dAvaBalance + dTransferAmt) < 0.0) {
                                        iRet = INT_INSUFFICIENT_FUND;
				}
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessBankBalance::Type[%c] Void[%d] Not enought Ava Balance for bank_id[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csBankId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
		else{//DEST
			dTransferAmt = dAmt;

DEBUGLOG(("BOMmsBalance::ProcessBankBalance::TransferAmt [%lf]\n", dTransferAmt));

			if (iVoidFlag == PD_FALSE) {
				sprintf(csTagAction, "%s", "CreditBalance");				
				if ((dAvaBalance + dTransferAmt) < 0.0) {
                                        iRet = INT_INSUFFICIENT_FUND;
                                }
			}
			else {
                                sprintf(csTagAction, "%s", "DebitBalance");
                                if ((dAvaBalance - dTransferAmt) < 0.0) {
                                        iRet = INT_INSUFFICIENT_FUND;
                                }
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessBankBalance::Type[%c] Void[%d] Not enought Ava Balance for bank_id[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csBankId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMBBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
DEBUGLOG(("ProcessBankBalance::Type [%c] Action = [%s]\n", cType, csTagAction));

               if (iRet == PD_OK) {
DEBUGLOG(("ProcessBankBalance::Type = [%c] void = [%d] Call DBMmsBankBalance:[%s]\n", cType, iVoidFlag, csTagAction));
                        DBObjPtr = CreateObj(DBPtr,"DBMmsBankBalance",csTagAction);
                        if ((*DBObjPtr)(csBankId,csCcy, dTransferAmt, csUpdateUser) != PD_OK) {
DEBUGLOG(("ProcessBankBalance::DBMmsBankBalance:Type = [%c] void = [%d] %s[%lf] Failed\n",cType, iVoidFlag, csTagAction, dTransferAmt));
ERRLOG("BOMmsBalance::ProcessBankBalance::DBMmsBankBalance: Type = [%c] void = [%d] %s [%lf] failed\n",cType, iVoidFlag, csTagAction, dTransferAmt);
                                iRet = INT_ERR;
                        }
                }
	}

	if (iRet == PD_OK) {
		PutField_Double(hRls, "net_amt", dTransferAmt);
	}

	return iRet;

}

int ProcessMerchantBalance(hash_t *hRls)
{
	int     iRet = PD_OK;

	char	*csTmp = NULL;

	char    *csMerchId = NULL;
	char    *csCountry = NULL;
	char    *csService = NULL;
	char    *csCcy = NULL;
	char    *csUpdateUser = NULL;

	double  dAmt = 0.0;
	double  dProcessingCost = 0.0;
	double	dBankCharge = 0.0;
	double	dBankChargeRefund = 0.0;
	double	dAdjustment = 0.0;

	char	cType;
	double  dAvaBalance = 0.0;
	double  dTransferAmt= 0.0;
	double  dActionAmt= 0.0;

	int	iVoidFlag = PD_FALSE;


	if (GetField_Char(hRls,"isd_ind",&cType)) {
DEBUGLOG(("ProcessMerchantBalance::isd_ind= [%c]\n",cType));
	}

/* merchant_id */
	if(GetField_CString(hRls,"merchant_id",&csMerchId)){
DEBUGLOG(("ProcessMerchantBalance::merchant_id = [%s]\n",csMerchId));
	}
	else{
DEBUGLOG(("ProcessMerchantBalance:merchant_id not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::merchant_id not found\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;
	}


/* Ccy */
	if(GetField_CString(hRls,"txn_ccy",&csCcy)){
DEBUGLOG(("ProcessMerchantBalance::ccy = [%s]\n",csCcy));
	}

/* Update_user */
	if(GetField_CString(hRls,"update_user",&csUpdateUser)){
DEBUGLOG(("ProcessMerchantBalance::update_user = [%s]\n",csUpdateUser));
	}
	else{
DEBUGLOG(("ProcessMerchantBalance:update_user not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::update_user Failed\n");
	}

/* For in-transit */
/* Amt */
	if(GetField_Double(hRls,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessMerchantBalance::txn_amt = [%lf]\n",dAmt));
	}
	else{
DEBUGLOG(("ProcessMerchantBalance:txn_amt not found!!\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::txn_amt Failed\n");
		iRet = INT_TXN_AMT_MISSING;
	}

/* For processing_cost */
	if(GetField_Double(hRls,"processing_cost",&dProcessingCost)){
DEBUGLOG(("ProcessMerchantBalance::processing_cost = [%lf]\n",dProcessingCost));
	}
	else{
DEBUGLOG(("ProcessMerchantBalance:processing_cost not found!!\n"));
		dProcessingCost = 0.0;
	}

/* For bank_charge */
        if(GetField_Double(hRls,"bank_charge",&dBankCharge)){
DEBUGLOG(("ProcessMerchantBalance::bank_charge = [%lf]\n",dBankCharge));
        }
        else{
DEBUGLOG(("ProcessMerchantBalance:bank_charge not found!!\n"));
                dBankCharge = 0.0;
        }

/* For bank_charge_refund */
        if(GetField_Double(hRls,"bank_charge_refund",&dBankChargeRefund)){
DEBUGLOG(("ProcessMerchantBalance::bank_charge_refund = [%lf]\n",dBankChargeRefund));
        }
        else{
DEBUGLOG(("ProcessMerchantBalance:bank_charge_refund not found!!\n"));
                dBankChargeRefund = 0.0;
        }

/* For Adjustment */
        if(GetField_Double(hRls,"adjustment",&dAdjustment)){
DEBUGLOG(("ProcessMerchantBalance::adjustment = [%lf]\n",dAdjustment));
        }
        else{
DEBUGLOG(("ProcessMerchantBalance:adjustment not found!!\n"));
                dAdjustment = 0.0;
        }

/* Get Country */
	if (iRet == PD_OK){
		if (GetMerchCountry(hRls) == PD_OK) {

			if (GetField_CString(hRls, "service_code", &csService)) {
DEBUGLOG(("ProcessMerchantBalance::service_code = [%s]\n",csService));
			}
			else {
DEBUGLOG(("ProcessMerchantBalance::service_code Failed\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::service_code Failed\n");
				iRet = INT_ERR;
			}

			if (GetField_CString(hRls, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessMerchantBalance::txn_country = [%s]\n",csCountry));
			}
			else {
DEBUGLOG(("ProcessMerchantBalance::txn_country Failed\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::txn_country Failed\n");
				iRet = INT_ERR;
			}

		} else {
DEBUGLOG(("ProcessMerchantBalance::GetMerchCountry Failed\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::GetMerchCountry Failed\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hRls, "txn_country", csCountry);
		PutField_CString(hRls, "service_code", csService);

DEBUGLOG(("ProcessMerchantBalance::Call BOMerchant:GetMerchantTxnInfo\n"));
		BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantTxnInfo");

		hash_t *hMerchInfo;
		hMerchInfo= (hash_t*) malloc (sizeof(hash_t));
		hash_init(hMerchInfo,0);

		if ((unsigned long)((*BOObjPtr)(hMerchInfo, hRls) != PD_OK)) {
DEBUGLOG(("BOMmsBalance::ProcessMerchantBalance::BOMerchant:GetMerchantTxnInfo Failed\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::BOBMerchant:GetmerchantTxnInfo Failed\n");
			iRet=INT_ERR;
		}
		else {
			if (GetField_CString(hMerchInfo, "merchant_client_id", &csTmp)) {
DEBUGLOG(("BOMmsBalance::ProcessMerchantBalance::merchant_client_id  = [%s]\n", csTmp));
				PutField_CString(hRls, "merchant_client_id", csTmp);
			}
		}
		
	}

	if (GetField_Int(hRls, "void_flag", &iVoidFlag)) {
DEBUGLOG(("ProcessMerchantBalance::void_flag = [%d]\n",iVoidFlag ));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("BOMmsBalance::ProcessMerchantBalance::Call BOBalance:GetAvalBalanceForUpdate\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","GetAvalBalanceForUpdate");
		if((unsigned long)((*BOObjPtr)(csCountry, csCcy, csService, csMerchId, &dAvaBalance) != PD_OK)) {
DEBUGLOG(("BOMmsBalance::ProcessMerchantBalance::BOBalance:GetAvalBalanceForUpdate Failed\n"));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::BOBalance:GetAvalBalanceForUpdate Failed\n");
			iRet=INT_ERR;
		}
		else {
DEBUGLOG(("BOMmsBalance::ProcessMerchantBalance::Merch Balance [%lf]\n", dAvaBalance));
		}
	}

	if (iRet == PD_OK) {
		if(cType==PD_SOURCE){
			dTransferAmt = dAmt + dProcessingCost + dBankChargeRefund + dAdjustment - dBankCharge;

			if (iVoidFlag == PD_FALSE) {
				dActionAmt = dTransferAmt * (-1);  // debit + void = credit

				if((dAvaBalance-dTransferAmt)<0.0){
					iRet = INT_INSUFFICIENT_FUND;
				}
			}
			else {
				dActionAmt = dTransferAmt; 

				if((dAvaBalance+dTransferAmt)<0.0){ // credit + void = debit 
					iRet = INT_INSUFFICIENT_FUND;
				}
			}

			if  (iRet != PD_OK) {
DEBUGLOG(("ProcessMerchantBalance::Type[%c] Void[%d] Not enought Ava Balance for pps[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csMerchId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMerchantBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}
		else{ //DEST

			dTransferAmt = dAmt;

			if (iVoidFlag == PD_FALSE) {
				dActionAmt = dTransferAmt;

	                        if((dAvaBalance + dTransferAmt)<0.0){
					iRet = INT_INSUFFICIENT_FUND;
                        	}
			}
			else {
				dActionAmt = dTransferAmt *(-1); 
				
                                if((dAvaBalance - dTransferAmt)<0.0){
                                        iRet = INT_INSUFFICIENT_FUND;
                                }
			}

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessMerchantBalance::Type[%c] Void[%d] Not enought Ava Balance for pps[%s] balance[%lf] TransferAmt[%lf]\n", cType, iVoidFlag, csMerchId, dAvaBalance, dTransferAmt));
DEBUGLOG(("ProcessMerchantBalance::Type[%c] Void[%d] === amt[%lf] processing_cost[%lf] bank_charge[%lf] bank_charge_refund[%lf] Adjustment[%lf]\n", cType, iVoidFlag, dAmt, dProcessingCost, dBankCharge, dBankChargeRefund, dAdjustment));
			}
		}

DEBUGLOG(("ProcessMerchantBalance::Type [%c] dActionAmt = [%lf]\n", cType, dActionAmt));

                if(iRet == PD_OK){
DEBUGLOG(("ProcessMerchantBalance::Type = [%c] void = [%d] Call BOBalance:UpdateMerchantAvalAmt ActionAmt[%lf]\n", cType, iVoidFlag, dActionAmt));
			BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdateMerchantAvalAmt");
			if ((unsigned long)((*BOObjPtr)(hRls, csCountry, csService, csCcy, csMerchId,dActionAmt) != PD_OK)) {

DEBUGLOG(("ProcessMerchantBalance::BOBalance:UpdateMerchantAvalAmt:Type [%c] void[%d] dActionAmt [%lf] Failed\n",cType, iVoidFlag, dActionAmt));
ERRLOG("BOMmsBalance::ProcessMerchantBalance::UpdateMerchantAvalAmt: Type [%c] void[%d] dActionAmt [%lf] failed\n",cType, iVoidFlag, dActionAmt);
				iRet=INT_ERR;
			}
                }

		if (iRet == PD_OK) {
			double dOpenBal = 0.0;
			GetField_Double(hRls, "merchant_open_bal", &dOpenBal);
DEBUGLOG(("ProcessMerchantBalance::Merchant Open Bal [%lf]\n", dOpenBal)); 
		}

		if (iRet == PD_OK) {

			hash_t *hVal;
	                hVal = (hash_t*) malloc (sizeof(hash_t));
	                hash_init(hVal,0);

			double dTmp = 0.0;
		

			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
			if((unsigned long)(*DBObjPtr)(csMerchId,csCcy,csCountry,csService,hVal)!=PD_ERR){
				if(GetField_Double(hVal,"current_bal",&dTmp)){
					PutField_Double(hRls,"current_bal",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessMerchantBalance: current_bal= [%f]\n",dTmp));
				}
				if(GetField_Double(hVal,"total_float",&dTmp)){
					PutField_Double(hRls,"total_float",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessMerchantBalance: total_float= [%f]\n",dTmp));
                                }
                                if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
                                	PutField_Double(hRls,"total_reserved_amount",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessMerchantBalance: total_reserved_amount= [%f]\n",dTmp));
                                }
                                if(GetField_Double(hVal,"total_hold",&dTmp)){
                                	PutField_Double(hRls,"total_hold",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessMerchantBalance: total_hold= [%f]\n",dTmp));
                                }
                                if(GetField_Double(hVal,"settlement_in_transit",&dTmp)){
                                	PutField_Double(hRls,"settlement_in_transit",dTmp);
DEBUGLOG(("BOMmsBalance:ProcessMerchantBalance: settlement_in_transit= [%f]\n",dTmp));
                                }
                        }
			FREE_ME (hVal);
		}

	}

	if (iRet == PD_OK) {
		PutField_Double(hRls, "net_amt", dTransferAmt);
	}

	return iRet;   

}
