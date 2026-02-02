/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRAU.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnOmtByUsRAU(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csMerchantId = NULL;
	char	*csTxnCountry = NULL;
	char	*csTxnCcy = NULL;
	char	*csServiceCode = NULL;
        char    *csPhDate = NULL;
        int     iDayOfWeek;
	char	*csTmp = NULL;
	double	dAmt = 0.0;
	char	cAmtType; // for daily cap or reserved amt
	char	cStatus;

	double	dOrgDailyCap = 0.0;
	double  dOrgRemainDailyCap = 0.0;
	double	dDiffAmt = 0.0;
	char	*csEffectDate;

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

	csEffectDate = (char *)malloc(PD_DATETIME_LEN + 1);

	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);

		PutField_CString(hTxn, "add_user", csUser);
	}

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hContext,"merchant_id",csMerchantId);

		PutField_CString(hTxn, "merchant_id", csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));

		PutField_CString(hTxn, "txn_ccy", csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hContext,"txn_country",csTxnCountry);

		PutField_CString(hTxn, "txn_country", csTxnCountry);
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hContext,"service_code",csServiceCode);

		PutField_CString(hTxn, "service_code", csServiceCode);
	}
        else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::service_code not found!!\n");
                iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
        }


        if(GetField_CString(hRequest,"dow",&csTmp)){
DEBUGLOG(("Authorize::day_of_week= [%s]\n",csTmp));
                iDayOfWeek = atoi(csTmp);
DEBUGLOG(("Authorize::iDayOfWeek= [%d]\n",iDayOfWeek));
                PutField_Int(hContext,"dow",iDayOfWeek);

		PutField_Int(hTxn, "dow", iDayOfWeek);
        }
        else{
                if(GetField_CString(hContext,"PHDATE",&csPhDate)){

DEBUGLOG(("Authorize::phdate= [%s]\n",csPhDate));

                        iDayOfWeek = day_of_week((const unsigned char *)csPhDate);
DEBUGLOG(("Authorize::iDayOfWeek= [%i]\n",iDayOfWeek));

                        PutField_Int(hContext,"dow",iDayOfWeek);

			PutField_Int(hTxn, "dow", iDayOfWeek);
                }
                else{
DEBUGLOG(("Authorize::phdate not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::phdate not found!!\n");
                        iRet=INT_PHDATE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
                }
        }


	if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));

		PutField_Double(hTxn, "txn_amt", dAmt);
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest, "amt_type", &csTmp)) {
		cAmtType = csTmp[0];
DEBUGLOG(("Authorize:: amt_type = [%c]\n",cAmtType));

		PutField_Char(hTxn, "amt_type", cAmtType);
	}
	else {
DEBUGLOG(("Authorize::amt_type not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::amt_type not found!!\n");
		iRet = INT_AMT_TYPE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}


	if (GetField_CString(hRequest, "status", &csTmp)) {
		cStatus = csTmp[0];
DEBUGLOG(("Authorize:: status = [%c]\n",cStatus));

		PutField_Char(hTxn, "status", cStatus);
	}
	else{
DEBUGLOG(("Authorize::status not found!!\n"));
ERRLOG("TxnOmtByUsRAU::Authorize::status not found!!\n");
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest, "eff_date", &csTmp)) {
DEBUGLOG(("Authorize:: eff_date = [%s]\n",csTmp));
		PutField_CString(hTxn, "effect_date", csTmp);
	}
	
	if (iRet == PD_OK) {
		if (cAmtType == PD_RES_AMT_DAILY_CAP) {

DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: GetDailyCap\n"));

			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantReservedAmt","GetDailyCapforUpdate");
			if((unsigned long) ((*DBObjPtr)(csMerchantId, csTxnCountry, csTxnCcy, csServiceCode, iDayOfWeek, 
							&dOrgDailyCap, &dOrgRemainDailyCap, csEffectDate))!=PD_OK){
ERRLOG("TxnOmtByUsRAU::MerchantReservedAmt:GetDailyCap FAILED!!\n");
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: GetDailyCap FAILED!!\n"));
				iRet = INT_ERR;
			}

			if (iRet == PD_OK) {
				dDiffAmt = dAmt - dOrgDailyCap;
DEBUGLOG(("Authorize::Diff Amt [%lf]\n", dDiffAmt));

				dDiffAmt = dDiffAmt + dOrgRemainDailyCap;
				if(dDiffAmt < 0.0)
					dDiffAmt = 0.0;
				PutField_Double(hTxn, "remain_daily_cap", dDiffAmt);
			}			

			if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Add\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLMerchantReservedAmt","Add");
				if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){

ERRLOG("TxnOmtByUsRAU::MerchantReservedAmt:Add FAILED!!\n");
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Add FAILED!!\n"));
					iRet = INT_ERR;
				}
			}
			
		}
		else {
			if (cStatus == PD_RES_AMT_STATUS_PENDING) {
				// Chk any existing pending record
				// if yes, update, else insert
			
				DBObjPtr = CreateObj(DBPtr, "DBOLMerchantReservedAmt", "ChkRecExist");		
				if((unsigned long) ((*DBObjPtr)(hTxn)) == PD_FOUND){
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: ChkRecExist FOUND\n"));

					// Update
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Update PENDING\n"));
					DBObjPtr = CreateObj(DBPtr, "DBOLMerchantReservedAmt", "Update");
					if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){

ERRLOG("TxnOmtByUsRAU::MerchantReservedAmt:Update PENDING FAILED !!\n");
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Update PENDING FAILED!!\n"));
						iRet = INT_ERR;
					}
				}
				else {
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: ChkRecExist NOT FOUND\n"));
					// insert
					DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Add\n"));
					DBObjPtr = CreateObj(DBPtr,"DBOLMerchantReservedAmt","Add");
					if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){

ERRLOG("TxnOmtByUsRAU::MerchantReservedAmt:Add PENDING FAILED!!\n");
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Add PENDING FAILED!!\n"));
						iRet = INT_ERR;
					}	
				}
				
			}
			else {
				// Update to Approve
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Update APPROVE\n"));
                                        DBObjPtr = CreateObj(DBPtr, "DBOLMerchantReservedAmt", "Update");
                                        if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){

ERRLOG("TxnOmtByUsRAU::MerchantReservedAmt:Update APPROVE FAILED !!\n");
DEBUGLOG(("Authorize::Call DBOLMerchantReservedAmt: Update APPROVE FAILED!!\n"));
                                                iRet = INT_ERR;
                                        }
				
			}
		
		}
	}


	hash_destroy(hTxn);
	FREE_ME(hTxn);

	FREE_ME(csEffectDate);

DEBUGLOG(("TxnOmtByUsRAU Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
