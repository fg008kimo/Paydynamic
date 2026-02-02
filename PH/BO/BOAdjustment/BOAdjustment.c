/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/07              Virginia Yun
Amend ProcessPartyBalance for void 	           2012/01/27              Virginia Yun
Check allow_modify and allow_bal_neg		   2013/02/22		   David Wong
Handle Get Approve Date after lock Balance         2013/06/11              Virginia Yun
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
#include "BOAdjustment.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOAdjustment(char    cdebug)
{
        cDebug = cdebug;
}

int GetCurrentCode(hash_t *hRec)
{
        int     iRet = PD_OK;

	char	cPartyType;
	char	cAction;

	int	iMaxCodeInNum = -1;	

	if (GetField_Char(hRec, "party_type", &cPartyType)) {
DEBUGLOG(("GetCurrentCode::party_type [%c]\n", cPartyType));
	}

	if (GetField_Char(hRec, "action", &cAction)) {
DEBUGLOG(("GetCurrentCode::action [%c]\n", cAction));
	}

DEBUGLOG(("GetCurrentCode::Call AdjustmentType: GetMaxCode\n"));

	DBObjPtr = CreateObj(DBPtr,"DBAdjustmentType","GetMaxCode");
        if((unsigned long)((*DBObjPtr)(cPartyType, &iMaxCodeInNum)) ==PD_OK) {

DEBUGLOG(("GetCurrentCode::CurrentCode Get [%d]\n", iMaxCodeInNum));

		/* No Current Code Found */
		if (iMaxCodeInNum < 0) {
			iMaxCodeInNum = 0 ;
		}
		else {
			iMaxCodeInNum++;

			if (iMaxCodeInNum > PD_ADJ_TYPE_MAX_CODE) {
				/* handle over 99 later */
				iRet = INT_ERR;
			}
		}


DEBUGLOG(("GetCurrentCode::CurrentCode Assigned CodeInNum [%d]\n", iMaxCodeInNum));
                PutField_Int(hRec, "code_in_num", iMaxCodeInNum);
	}
        else {
DEBUGLOG(("GetCurrentCode:GetMaxCode not found\n"));
ERRLOG("BOAdjustment::GetCurrentCode::GetMaxCode not found!!\n");
		iRet=INT_ERR;
        }

DEBUGLOG(("GetCurrentCode: return iRet [%d]\n", iRet));

	return 	iRet;
}


int     ValidateProcess(hash_t* hInRec)
{
        int     iRet = PD_OK;
	int	iTmpRet = PD_OK;

        char    cAction;
        char    cPartyType;
        char    *csCode = NULL;

	int	iCodeInNum;

        char    cNewDCInd;
        char    cCurrentDCInd;

	int	iNewDisabled;
	int	iCurrentDisabled;

	int	iCurrentAllowModify;
		

        hash_t          *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

        recordset_init(rRecordSet, 0);

        if (!(GetField_Char(hInRec, "action", &cAction))) {
DEBUGLOG(("ValidateProcess:: Not Complete Information cAction [%c]\n", cAction));
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		if (!(GetField_Char(hInRec, "party_type", &cPartyType) &&
	                GetField_CString(hInRec, "code", &csCode) &&
			GetField_Int(hInRec, "code_in_num", &iCodeInNum) &&
                	GetField_Char(hInRec, "dc_ind", &cNewDCInd))) {
DEBUGLOG(("ValidateProcess:: Not Complete Information cPartyType [%c] csCode [%s] iCodeInNum [%d] cNewDCInd [%c]\n", cAction, cPartyType, csCode, iCodeInNum, cNewDCInd));
			iRet = PD_ERR;

		} 
	}
	else {
DEBUGLOG(("ValidateProcess:: cPartyType [%c] csCode [%s] iCodeInNum[%d] cNewDCInd [%c]\n", cPartyType, csCode, iCodeInNum, cNewDCInd));
	}



        /* if record exists and action is delete, not allow */
        /* if record exists and action is update, only allow update desc */

        if (iRet == PD_OK) {

		if (cAction != PD_ACTION_ADD) { 

			DBObjPtr = CreateObj(DBPtr,"DBAdjustmentType","GetAdjustmentTypeRec");
			if ((*DBObjPtr)(cPartyType, csCode, rRecordSet) == PD_OK) {

				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_Char(hRec,"dc_ind",&cCurrentDCInd)) {
DEBUGLOG(("ValidateProcess::GetAdjustmentTypeRec::dc_ind = [%c]\n",cCurrentDCInd));
					}

					if (GetField_Int(hRec, "disabled", &iCurrentDisabled)) {
DEBUGLOG(("ValidateProcess::GetAdjustmentTypeRec::disabled = [%d]\n",iCurrentDisabled));
					}

					if (GetField_Int(hRec, "allow_modify", &iCurrentAllowModify)) {
DEBUGLOG(("ValidateProcess::GetAdjustmentTypeRec::allow_modify = [%d]\n",iCurrentAllowModify));
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("ValidateProces::GetAdjustmentTypeRec:: failed\n"));
ERRLOG("BOAdjustment::ValidateProcess::GetAdjustmentTypeRec:: failed!!\n");
			}

			/* **special handling disabled field** */
			if (cAction == PD_ACTION_UPDATE) {

					/* If there is no disabled field passed, get the existing one */
					if (!GetField_Int(hInRec, "disabled", &iNewDisabled)) {
						PutField_Int(hInRec, "disabled", iCurrentDisabled);
DEBUGLOG(("ValidateProcess::GetAdjustmentTypeRec::Assigne disabled = [%d]\n",iCurrentDisabled));
					}

			}

			if (iRet == PD_OK) {

DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBTransaction","ChkTxnCodeExist");
				iTmpRet = (unsigned long)(*DBObjPtr)(csCode);

				if (iTmpRet == PD_FOUND) 
				{
DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist: FOUND\n"));

					if (cAction == PD_ACTION_DELETE) {
DEBUGLOG(("ValidateProcess::Not Allow Delete\n"));
       	                         		iRet = PD_ERR;
                        		}
                        		else if (cAction == PD_ACTION_UPDATE) {
						if (cNewDCInd != cCurrentDCInd) {
DEBUGLOG(("ValidateProcess::GetAdjustmentTypeRec::dc_ind = [%c] not match with new dc_ind [%c], not allow update\n",cCurrentDCInd, cNewDCInd));
							iRet = PD_ERR;
						}
                        		}
                		}
                		else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist: NOT FOUND\n"));
                		}
				else {
DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist: ERR\n"));
ERRLOG("BOAdjustment::ValidateProcess::Call Transaction: ChkTxnCode Exist :: ERR!!\n");
					iRet = PD_ERR;
				}	
			}

			if (iCurrentAllowModify == PD_FALSE) {
DEBUGLOG(("ValidateProcess::Not Allow Modify\n"));
				iRet = PD_ERR;
			}

		}
		else {
			if (!GetField_Int(hInRec, "disabled", &iNewDisabled)) {
                        	PutField_Int(hInRec, "disabled", 0); /* default enable*/
DEBUGLOG(("ValidateProcess::Add assigned default disable\n"));
			}
DEBUGLOG(("ValidateProcess::OK for Add\n"));
		}	
	}
        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);


DEBUGLOG(("ValidateProcess::Return iRet [%d]\n", iRet));

        return iRet;
}


int     ProcessPartyBalance(hash_t* hInRec)
{
	int	iRet = PD_OK;

	char	cPartyType;
	char	cDCInd;

	char	*csCode = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;	
	char	*csUpdateUser = NULL;
//	char	*csDate = NULL;
        double  dAmt=0.0;
        double  dFeeAmt=0.0;
	double  dNetAmt=0.0;
        double  dTmp=0.0;
	double	dAvaBalance = 0.0;
        //double  dMerchOpenBal = 0.0; 

	char	*csPspId = NULL;
	char	*csMerchantId = NULL;
	char	*csServiceCode = NULL;

	int	iDisabled;
	int	iVoidFlag = PD_FALSE;
	int	iBalanceTransfer = PD_FALSE;
	int	iAllowBalNegative;
	int	iAllowModify;

	double	dMarkupAmt = 0.0;
	char	*csMarkupCcy = NULL;

	char	*csTmp = NULL;
	

        hash_t          *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

	hash_t	*hTxn;
	hTxn = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hTxn, 0);
	
	

/* code */
	if (GetField_CString(hInRec, "code", &csCode)) {
DEBUGLOG(("ProcessPartyBalance::code [%s]\n", csCode));
	}

/* party_type */
	if (GetField_Char(hInRec, "party_type", &cPartyType)) {
DEBUGLOG(("ProcessPartyBalance::party_type [%c]\n", cPartyType));
	}

/* country */
	if (GetField_CString(hInRec, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessPartyBalance::country [%s]\n", csCountry));
	}

/* ccy */
	if (GetField_CString(hInRec, "txn_ccy", &csCcy)) {
DEBUGLOG(("ProcessPartyBalance::ccy [%s]\n", csCcy));
	}

/* void_flag */
	if (GetField_Int(hInRec, "void_flag", &iVoidFlag)) {
DEBUGLOG(("ProcessPartyBalance::void_flag [%d]\n", iVoidFlag));
	}

/* balance_transfer */
	if (GetField_Int(hInRec, "balance_transfer", &iBalanceTransfer)) {
DEBUGLOG(("ProcessPartyBalance::balance_transfer [%d]\n", iBalanceTransfer));
	}

	recordset_init(rRecordSet, 0);


	if (iBalanceTransfer == PD_FALSE) {	

DEBUGLOG(("ProcessPartyBalance::Call DBAdjustment:GetAdjustmentTypeRec\n"));

		DBObjPtr = CreateObj(DBPtr,"DBAdjustmentType","GetAdjustmentTypeRec");
		if ((*DBObjPtr)(cPartyType, csCode, rRecordSet) == PD_OK) {

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Char(hRec,"dc_ind",&cDCInd)) {
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::dc_ind = [%c]\n",cDCInd));

					PutField_Char(hInRec, "dc_ind", cDCInd);
				}

				if (GetField_Int(hRec, "allow_modify", &iAllowModify)) {
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::allow_modify = [%d]\n", iAllowModify));
					PutField_Int(hInRec, "allow_modify", iAllowModify);
				}

				if (GetField_Int(hRec, "allow_bal_neg", &iAllowBalNegative)) {
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::allow_bal_neg= [%d]\n", iAllowBalNegative));
					PutField_Int(hInRec, "allow_bal_neg", iAllowBalNegative);
				}

				if (GetField_Int(hRec, "disabled", &iDisabled)) {
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::disabled = [%d]\n",iDisabled));

					if (iDisabled == PD_DISABLED && iVoidFlag == PD_FALSE) { // if void, no need to chk disabled?

DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::not allow to use the code\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::GetAdjustmentTypeRec:: code in disabled!!\n");
						iRet = INT_CODE_DISABLED;

						PutField_Int(hInRec, "internal_error", iRet);
						break;
					}
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec:: failed\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::GetAdjustmentTypeRec:: failed!!\n");

			PutField_Int(hInRec, "internal_error", iRet);
	
		}
	}
	else {
		GetField_Char(hInRec, "dc_ind", &cDCInd);
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::dc_ind = [%c]\n",cDCInd));

		// Markup  only exists in balance transfer
		if (GetField_Double(hInRec, "markup_amt", &dMarkupAmt)) {
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::markup_amt = [%lf]\n", dMarkupAmt));
		}

		if (GetField_CString(hInRec, "markup_ccy", &csMarkupCcy)) {
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::markup_ccy = [%s]\n", csMarkupCcy));
		}

		if (GetField_CString(hInRec, "markup_rate", &dTmp)) {
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::markup_rate = [%lf]\n", dTmp));
		}
		PutField_Int(hInRec, "allow_modify", PD_FALSE);
		PutField_Int(hInRec, "allow_bal_neg", PD_FALSE);
	}

/* udpate_user */
        if(GetField_CString(hInRec,"add_user",&csUpdateUser)){
DEBUGLOG(("ProcessPartyBalance::add_user= [%s]\n",csUpdateUser));
	}

/* src txn fee */
        if(GetField_Double(hInRec,"src_txn_fee",&dFeeAmt)){

DEBUGLOG(("ProcessPartyBalance::txn_fee= [%f]\n",dFeeAmt));
	}
	else {
		dFeeAmt = 0.0;
DEBUGLOG(("ProcessPartyBalance::txn_fee (by default) = [%f]\n",dFeeAmt));
	}

/* txn_amt */
        if(GetField_Double(hInRec,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessPartyBalance::txn_amt= [%f]\n",dAmt));
		//PutField_Double(hInRec, "txn_amt", dAmt);
        }

/* net_amt */	
	if (cDCInd == PD_ADJ_TYPE_CREDIT) {
		dNetAmt = dAmt - dFeeAmt - dMarkupAmt;

		dNetAmt = newround(dNetAmt, 2);
		PutField_Double(hInRec, "net_amt", dNetAmt);
	} else if (cDCInd == PD_ADJ_TYPE_DEBIT) {
		dNetAmt = dAmt + dFeeAmt + dMarkupAmt;

		dNetAmt = newround(dNetAmt, 2);
		PutField_Double(hInRec, "net_amt", dNetAmt);
	}

DEBUGLOG(("ProcessPartyBalance::net_amt= [%f]\n",dNetAmt));



/* approval_date */
/*
        if(!GetField_CString(hInRec,"approval_date",&csDate)){
                if(!GetField_CString(hInRec,"PHDATE",&csDate)){
DEBUGLOG(("ProcessPartyBalance::approval_date not found!!\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::approval_date not found!!\n");
                        iRet=INT_INVALID_TXN;

			PutField_Int(hInRec, "internal_error", iRet);
                }
		else {
			PutField_CString(hInRec, "approval_date", csDate);
DEBUGLOG(("ProcessPartyBalance::approval_date = [%s]\n", csDate));
		}
        }
*/

/* for psp */
    if (iRet == PD_OK) {
	if (cPartyType == PD_TYPE_PSP) {

		if (GetField_CString(hInRec, "psp_id", &csPspId)) {
DEBUGLOG(("ProcessPartyBalance::psp_id [%s]\n", csPspId));
		}
		else {
DEBUGLOG(("ProcessPartyBalance::psp_id missing\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::psp_id missing!!\n");
			iRet = INT_ERR;

			PutField_Int(hInRec, "internal_error", iRet);
		}


		if (iRet == PD_OK) {
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::Call BOBalance:GetAvalPspBalanceForUpdate\n"));
                        BOObjPtr = CreateObj(BOPtr,"BOBalance","GetAvalPspBalanceForUpdate");
                        if((unsigned long)((*BOObjPtr)(csCountry, csCcy, csPspId, &dAvaBalance) != PD_OK)) {
DEBUGLOG(("BOAdjustment::BOBalance:GetAvalPspBalanceForUpdate Failed\n"));
ERRLOG("BOAdjustment::BOBalance:GetAvalPspBalanceForUpdate Failed\n");
                                iRet=INT_ERR;
                        }
                        else {
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::PSP Balance [%lf]\n", dAvaBalance));

				/** get approval date and approval timestamp **/
				DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
				(*DBObjPtr)(hInRec);

				if (GetField_CString(hInRec, "approval_date", &csTmp))  {
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::PSP approval_date [%s]\n", csTmp));
				}

				if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::PSP approval_timestamp [%s]\n", csTmp));
				}

                        }

                }


		if (iVoidFlag == PD_FALSE) {
			if (cDCInd == PD_ADJ_TYPE_DEBIT) {
				if (iRet == PD_OK) {
					/* ChkBalance?? */
					//if (dAmt > dAvaBalance) 
					if (newround(dNetAmt,PD_DECIMAL_LEN) > newround(dAvaBalance,PD_DECIMAL_LEN))
					{
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::CANNOT process as not enought PSP [%s] Balance [%lf] Amt [%lf] NetAmt [%lf]\n", csPspId, dAvaBalance, dAmt, dNetAmt));
						iRet = INT_INSUFFICIENT_FUND;
						PutField_Int(hInRec, "internal_error", iRet);
					}
				}

				if (iRet==PD_OK) {
DEBUGLOG(("BOAdjustment::Call DBPspBalance:DebitBalance\n"));
					DBObjPtr = CreateObj(DBPtr,"DBPspBalance","DebitBalance");
					//if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dAmt, csUpdateUser) != PD_OK)
					if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dNetAmt, csUpdateUser) != PD_OK) 
					{
DEBUGLOG(("BOAdjustment::DBPspBalance:DebitBalance Failed\n"));
						iRet = INT_ERR;
					}
				}
			} else if (cDCInd == PD_ADJ_TYPE_CREDIT)  {
                        	if (iRet==PD_OK) {
DEBUGLOG(("BOAdjustment::Call DBPspBalance:CreditBalance\n"));
                                	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
	                                //if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dAmt, csUpdateUser) != PD_OK) 
	                                if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dNetAmt, csUpdateUser) != PD_OK) 
					{
DEBUGLOG(("BOAdjustment::DBPspBalance:CreditBalance Failed\n"));
						iRet = INT_ERR;
                                	}
                        	}
			}
		} else {
			/******* Void *******/

                        if (cDCInd == PD_ADJ_TYPE_DEBIT) { // convert to credit as void
                                if (iRet==PD_OK) {
DEBUGLOG(("BOAdjustment::(Void) Call DBPspBalance:CreditBalance\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
                                        //if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dAmt, csUpdateUser) != PD_OK) 
                                        if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dNetAmt, csUpdateUser) != PD_OK) 
					{
DEBUGLOG(("BOAdjustment::(Void) DBPspBalance:CreditBalance Failed\n"));
                                                iRet = INT_ERR;
                                        }
                                }

			} else if (cDCInd == PD_ADJ_TYPE_CREDIT) { // convert to debit as void

				if (iRet == PD_OK) {
					/* ChkBalance?? */
					//if (dAmt > dAvaBalance) 
					//if (dNetAmt > dAvaBalance) 
					if (newround(dNetAmt,PD_DECIMAL_LEN) > newround(dAvaBalance,PD_DECIMAL_LEN))
					{
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::CANNOT process as not enought PSP [%s] Balance [%lf] Amt [%lf] NetAmt [%lf]\n", csPspId, dAvaBalance, dAmt, dNetAmt));
                                        	iRet = INT_INSUFFICIENT_FUND;
						PutField_Int(hInRec, "internal_error", iRet);
					}
				}

                                if (iRet==PD_OK) {
DEBUGLOG(("BOAdjustment::(Void) Call DBPspBalance:DebitBalance\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBPspBalance","DebitBalance");
                                        //if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dAmt, csUpdateUser) != PD_OK) 
                                        if ((*DBObjPtr)(csPspId,csCountry, csCcy, PD_PSP_BAL, dNetAmt, csUpdateUser) != PD_OK) 
					{
DEBUGLOG(("BOAdjustment::(Void) DBPspBalance:DebitBalance Failed\n"));
                                                iRet = INT_ERR;
                                        }
                                }
                        } 
		}

		/* Get PSP Balance */
                hash_init(hTxn,0);
DEBUGLOG(("BOAdjustment::Call DBPspBalance:GetBalance\n"));
                DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetBalance");
                if ((*DBObjPtr)(csPspId, csCountry, csCcy, hTxn) == PD_OK) {

                        if (GetField_Double(hTxn, "balance", &dTmp)) {
DEBUGLOG(("Psp GetBalance::balance = [%f]\n",dTmp));
                                PutField_Double(hInRec, "bal", dTmp);
				PutField_Double(hInRec, "current_bal", dTmp);
                        }

                        if (GetField_Double(hTxn, "total_float", &dTmp)) {
DEBUGLOG(("Psp GetBalance::total_float = [%f]\n",dTmp));
                                PutField_Double(hInRec, "total_float", dTmp);
                        }

                        if (GetField_Double(hTxn, "total_hold", &dTmp)) {
DEBUGLOG(("Psp GetBalance::total_hold = [%f]\n",dTmp));
                                PutField_Double(hInRec, "total_hold", dTmp);
                        }
                }
                else {
ERRLOG("BOAdjustment::PSP GetBalance::Balance for PspId[%s] not found\n",csPspId);
DEBUGLOG(("Psp GetBalance::Balance for PspId[%s] not found\n", csPspId));
                        iRet = INT_ERR;
                }

		hash_destroy(hTxn);


	}else if (cPartyType == PD_TYPE_MERCHANT) {
/* for merchant */
		/* merchant_id */
		if (GetField_CString(hInRec, "merchant_id", &csMerchantId)) {
DEBUGLOG(("ProcessPartyBalance::merchant_id [%s]\n", csMerchantId));
		}
		else {
DEBUGLOG(("ProcessPartyBalance::merchant_id missing\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::merchant_id missing!!\n");
			iRet = INT_ERR;

			PutField_Int(hInRec, "internal_error", iRet);
		}

		/* service_code */
		if (GetField_CString(hInRec, "service_code", &csServiceCode)) {
DEBUGLOG(("ProcessPartyBalance::service_code [%s]\n", csServiceCode));
		}
		else {
DEBUGLOG(("ProcessPartyBalance::service_code missing\n"));
ERRLOG("BOAdjustment::ProcessPartyBalance::service_code missing!!\n");
			iRet = INT_ERR;
		}

		if ( (iVoidFlag == PD_FALSE && cDCInd == PD_ADJ_TYPE_DEBIT) ||
		     (iVoidFlag == PD_TRUE  && cDCInd == PD_ADJ_TYPE_CREDIT) ) {
			PutField_Char(hInRec, "dc_type", PD_IND_DEBIT);
		}
		
		if ( (iVoidFlag == PD_FALSE && cDCInd == PD_ADJ_TYPE_CREDIT) ||
		     (iVoidFlag == PD_TRUE  && cDCInd == PD_ADJ_TYPE_DEBIT) ) {

			PutField_Char(hInRec, "dc_type", PD_IND_CREDIT);
		}


		if (iRet == PD_OK) {
DEBUGLOG(("BOAdjustment::ProcessPartyBalance::Call BOBalance:ProcessMerchantAdjAmount\n"));
                        BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessMerchantAdjAmount");
                        iRet = (unsigned long)(*BOObjPtr)(hInRec); 
			if(iRet!=PD_OK){
DEBUGLOG(("BOAdjustment::BOBalance:ProcessMerchantAdjAmount Failed\n"));
ERRLOG("BOAdjustment::BOBalance:ProcessMerchantAdjAmount Failed\n");
                                PutField_Int(hInRec, "internal_error", iRet);
                        } else {
DEBUGLOG(("BOAdjustment::BOBalance:ProcessMerchantAdjAmount Succ!\n"));
				if (GetField_CString(hInRec, "approval_date", &csTmp))  {
DEBUGLOG(("BOAdjustment::BOBalance:ProcessMerchantAdjAmount approval_date [%s]!\n", csTmp));
				}
				
				if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("BOAdjustment::BOBalance:ProcessMerchantAdjAmount approval_timestamp [%s]!\n", csTmp));
				}

			}
		}



	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("ProcessPartyBalance::Incorrect PartyType [%c]\n", cPartyType));
ERRLOG("BOAdjustment::ProcessPartyBalance::Incorrect PartyType [%c]\n", cPartyType);

		PutField_Int(hInRec, "internal_error", iRet);
	}
    }


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(hTxn);


DEBUGLOG(("ProcessPartyBalance::Return iRet [%d]\n", iRet));

	return iRet;	
}

