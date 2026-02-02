/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/07              Virginia Yun
Refine for PSP                                     2014/12/29              Virginia Yun
Add balance type				   2016/01/06		   LokMan Chow
Modify ProcessPartyBalance			   2016/06/24		   Elvis Wong
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
#include "BOOLAdjustment.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOOLAdjustment(char    cdebug)
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

DEBUGLOG(("GetCurrentCode::Call OLAdjustmentType: GetMaxCode\n"));

	DBObjPtr = CreateObj(DBPtr,"DBOLAdjustmentType","GetMaxCode");
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
ERRLOG("BOOLAdjustment::GetCurrentCode::GetMaxCode not found!!\n");
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
DEBUGLOG(("ValidateProcess START!\n"));

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
DEBUGLOG(("ValidateProcess Action [%d]\n", cAction));

		if (cAction != PD_ACTION_ADD) { 

			DBObjPtr = CreateObj(DBPtr,"DBOLAdjustmentType","GetAdjustmentTypeRec");
			if ((*DBObjPtr)(cPartyType, csCode, rRecordSet) == PD_OK) {

				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_Char(hRec,"dc_ind",&cCurrentDCInd)) {
DEBUGLOG(("ValidateProcess::GetOLAdjustmentTypeRec::dc_ind = [%c]\n",cCurrentDCInd));
					}

					if (GetField_Int(hRec, "disabled", &iCurrentDisabled)) {
DEBUGLOG(("ValidateProcess::GetOLAdjustmentTypeRec::disabled = [%d]\n",iCurrentDisabled));
					}

					if (GetField_Int(hRec, "allow_modify", &iCurrentAllowModify)) {
DEBUGLOG(("ValidateProcess::GetOLAdjustmentTypeRec::allow_modify = [%d]\n",iCurrentAllowModify));
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("ValidateProces::GetOLAdjustmentTypeRec:: failed\n"));
ERRLOG("BOOLAdjustment::ValidateProcess::GetOLAdjustmentTypeRec:: failed!!\n");
			}

			/* **special handling disabled field** */
			if (cAction == PD_ACTION_UPDATE) {

					/* If there is no disabled field passed, get the existing one */
					if (!GetField_Int(hInRec, "disabled", &iNewDisabled)) {
						PutField_Int(hInRec, "disabled", iCurrentDisabled);
DEBUGLOG(("ValidateProcess::GetOLAdjustmentTypeRec::Assigne disabled = [%d]\n",iCurrentDisabled));
					}

			}

			if (iRet == PD_OK) {

DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","ChkTxnCodeExist");
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
DEBUGLOG(("ValidateProcess::GetOLAdjustmentTypeRec::dc_ind = [%c] not match with new dc_ind [%c], not allow update\n",cCurrentDCInd, cNewDCInd));
							iRet = PD_ERR;
						}
                        		}
                		}
                		else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist: NOT FOUND\n"));
                		}
				else {
DEBUGLOG(("ValidateProcess::Call Transaction: ChkTxnCodeExist: ERR\n"));
ERRLOG("BOOLAdjustment::ValidateProcess::Call Transaction: ChkTxnCode Exist :: ERR!!\n");
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
	char	cBalType;

	char	*csCode = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;	
	char	*csUpdateUser = NULL;
        double  dAmt=0.0;
        double  dFeeAmt=0.0;
	double  dNetAmt=0.0;
        double  dTmp=0.0;
	//double  dAvaBalance = 0.0;
        //double  dMerchOpenBal = 0.0; 

	//char	*csPspId = NULL;
	char	*csBaid = NULL;
	char	*csMerchantId = NULL;
	char	*csServiceCode = NULL;

	int	iDisabled;
	int	iVoidFlag = PD_FALSE;
	int	iBalanceTransfer = PD_FALSE;
	int	iAllowBalNegative;
	int	iAllowModify;
	int     iReturnMerchFee = PD_FALSE;

	double  dMarkupAmt = 0.0;
        char    *csMarkupCcy = NULL;

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

/* balance_transfer */
	if (GetField_Int(hInRec, "balance_transfer", &iBalanceTransfer)) {
DEBUGLOG(("ProcessPartyBalance::balance_transfer [%d]\n", iBalanceTransfer));
	}

	recordset_init(rRecordSet, 0);


	if (iBalanceTransfer == PD_FALSE) {	

DEBUGLOG(("ProcessPartyBalance::Call DBOLAdjustment:GetAdjustmentTypeRec\n"));

		DBObjPtr = CreateObj(DBPtr,"DBOLAdjustmentType","GetAdjustmentTypeRec");
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
DEBUGLOG(("ProcessPartyBalance::GetOLAdjustmentTypeRec::allow_bal_neg= [%d]\n", iAllowBalNegative));
					PutField_Int(hInRec, "allow_bal_neg", iAllowBalNegative);
				}

				if (GetField_Char(hRec,"bal_type",&cBalType)) {
DEBUGLOG(("ProcessPartyBalance::GetAdjustmentTypeRec::bal_type = [%c]\n",cBalType));
					PutField_Char(hInRec, "bal_type", cBalType);
				}

				if (GetField_Int(hRec, "disabled", &iDisabled)) {
DEBUGLOG(("ProcessPartyBalance::GetOLAdjustmentTypeRec::disabled = [%d]\n",iDisabled));

					if (iDisabled == PD_DISABLED) {

DEBUGLOG(("ProcessPartyBalance::GetOLAdjustmentTypeRec::not allow to use the code\n"));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::GetOLAdjustmentTypeRec:: code in disabled!!\n");
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
DEBUGLOG(("ProcessPartyBalance::GetOLAdjustmentTypeRec:: failed\n"));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::GetOLAdjustmentTypeRec:: failed!!\n");

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

		if (GetField_Int(hInRec,"void_flag",&iVoidFlag)) {
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::void_flag = [%d]\n", iVoidFlag));
                }

		if (GetField_Int(hInRec,"return_mfee",&iReturnMerchFee)) {
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::return_mfee= [%d]\n",iReturnMerchFee));
		}

		PutField_Int(hInRec, "allow_modify", PD_FALSE);
		PutField_Int(hInRec, "allow_bal_neg", PD_FALSE);
	}

/* udpate_user */
        if(GetField_CString(hInRec,"add_user",&csUpdateUser)){
DEBUGLOG(("ProcessPartyBalance::add_user= [%s]\n",csUpdateUser));
		PutField_CString(hInRec, "update_user", csUpdateUser);

	}

/* src txn fee */
        if(GetField_Double(hInRec,"src_txn_fee",&dFeeAmt)){
DEBUGLOG(("ProcessPartyBalance::src_txn_fee= [%f]\n",dFeeAmt));

		if ((iBalanceTransfer == PD_TRUE) && (iVoidFlag == PD_TRUE) && (iReturnMerchFee == PD_FALSE)) {
               		dFeeAmt = 0.0;
        	}
DEBUGLOG(("ProcessPartyBalance::txn_fee= [%f]\n",dFeeAmt));
	}
	else {
		dFeeAmt = 0.0;
DEBUGLOG(("ProcessPartyBalance::src_txn_fee (by default) = [%f]\n",dFeeAmt));
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


/* for psp */
    if (iRet == PD_OK) {
		if (cPartyType == PD_TYPE_PSP) {
			if (GetField_CString(hInRec, "baid", &csBaid)) {
DEBUGLOG(("ProcessPartyBalance::baid [%s]\n", csBaid));
			} else {
DEBUGLOG(("ProcessPartyBalance::baid missing\n"));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::baid missing!!\n");
				iRet = INT_ERR;
				PutField_Int(hInRec, "internal_error", iRet);
			}

			PutField_Double(hInRec, "display_amt", dNetAmt);
			PutField_Double(hInRec, "txn_amount", dAmt);


			if (iVoidFlag == PD_FALSE) {
				PutField_Char(hInRec, "amt_type", cDCInd);
			} else {
				if (cDCInd == PD_ADJ_TYPE_DEBIT) {
					PutField_Char(hInRec, "amt_type", PD_ADJ_TYPE_CREDIT);
				} else {
					PutField_Char(hInRec, "amt_type", PD_ADJ_TYPE_DEBIT);
				}
			}
			PutField_CString(hInRec, "pool", PD_ACCT_BAL_POOL);


			if (iRet == PD_OK) {
DEBUGLOG(("BOOLAdjustment::ProcessPartyBalance::Call BOOLBalance:UpdateAmount\n"));
				BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
				if ((unsigned long)((*BOObjPtr)(hInRec) == PD_OK)) {
					if (GetField_CString(hInRec, "approval_date", &csTmp)) {
DEBUGLOG(("BOOLAdjustment::ProcessPartyBalance::BAID approval_date [%s]\n", csTmp));
					}

					if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("BOOLAdjustment::ProcessPartyBalance::BAID approval_timestamp [%s]\n", csTmp));
					}


					// Open Balance
					if (GetField_Double(hTxn, "open_balance", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::open_balance = [%f]\n", dTmp));
						PutField_Double(hInRec, "psp_open_bal", dTmp);
					}

					if (GetField_Double(hTxn, "open_in_transit", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::open_in_transit = [%f]\n", dTmp));
						PutField_Double(hInRec, "psp_open_in_transit", dTmp);
					}


					// Close Balance
					if (GetField_Double(hInRec, "bal", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::balance = [%f]\n", dTmp));
						PutField_Double(hInRec, "current_bal", dTmp);
					}

					if (GetField_Double(hInRec, "total_hold", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::total_hold = [%f]\n", dTmp));
					}

					if (GetField_Double(hInRec, "prepaid", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::prepaid = [%f]\n", dTmp));
					}

					if (GetField_Double(hInRec, "in_transit", &dTmp)) {
DEBUGLOG(("BOOLAdjustment::in_transit = [%f]\n", dTmp));
					}

				} else {
DEBUGLOG(("BOOLAdjustment::DBOLBalance:UpdateAmount Failed\n"));
ERRLOG("BOOLAdjustment::DBOLBalance:UpdateAmount Failed\n");
					iRet = INT_ERR;
				}
			}

		} else if (cPartyType == PD_TYPE_MERCHANT) {
/* for merchant */
			/* merchant_id */
			if (GetField_CString(hInRec, "merchant_id", &csMerchantId)) {
DEBUGLOG(("ProcessPartyBalance::merchant_id [%s]\n", csMerchantId));
			}
			else {
DEBUGLOG(("ProcessPartyBalance::merchant_id missing\n"));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::merchant_id missing!!\n");
				iRet = INT_ERR;

				PutField_Int(hInRec, "internal_error", iRet);
			}

			/* service_code */
			if (GetField_CString(hInRec, "service_code", &csServiceCode)) {
DEBUGLOG(("ProcessPartyBalance::service_code [%s]\n", csServiceCode));
			}
			else {
DEBUGLOG(("ProcessPartyBalance::service_code missing\n"));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::service_code missing!!\n");
				iRet = INT_ERR;
			}

			if (iVoidFlag == PD_FALSE) {
				if (cDCInd == PD_ADJ_TYPE_DEBIT) {
					PutField_Char(hInRec, "dc_type", PD_IND_DEBIT);
				} else {
					PutField_Char(hInRec, "dc_type", PD_IND_CREDIT);
				}
			} else {
				if (cDCInd == PD_ADJ_TYPE_DEBIT) {
                                        PutField_Char(hInRec, "dc_type", PD_IND_CREDIT);
                                } else {
                                        PutField_Char(hInRec, "dc_type", PD_IND_DEBIT);
                                }
			}




			if (iRet == PD_OK) {
DEBUGLOG(("BOOLAdjustment::ProcessPartyBalance::Call BOOLBalance:ProcessMerchantAdjAmount\n"));
				BOObjPtr = CreateObj(BOPtr,"BOOLBalance","ProcessMerchantAdjAmount");
				iRet = (unsigned long)(*BOObjPtr)(hInRec); 
				if(iRet!=PD_OK){
DEBUGLOG(("BOOLAdjustment::BOOLBalance:ProcessMerchantAdjAmount Failed\n"));
ERRLOG("BOOLAdjustment::BOOLBalance:ProcessMerchantAdjAmount Failed\n");
					PutField_Int(hInRec, "internal_error", iRet);
				} else {
DEBUGLOG(("BOOLAdjustment::BOOLBalance:ProcessMerchantAdjAmount Succ!\n"));
					if (GetField_CString(hInRec, "approval_date", &csTmp))  {
DEBUGLOG(("BOOLAdjustment::BOOLBalance:ProcessMerchantAdjAmount approval_date [%s]!\n", csTmp));
					}
				
					if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("BOOLAdjustment::BOOLBalance:ProcessMerchantAdjAmount approval_timestamp [%s]!\n", csTmp));
					}

				}
			}



		}
		else {
			iRet = INT_ERR;
DEBUGLOG(("ProcessPartyBalance::Incorrect PartyType [%c]\n", cPartyType));
ERRLOG("BOOLAdjustment::ProcessPartyBalance::Incorrect PartyType [%c]\n", cPartyType);

			PutField_Int(hInRec, "internal_error", iRet);
		}

    }


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(hTxn);


DEBUGLOG(("ProcessPartyBalance::Return iRet [%d]\n", iRet));

	return iRet;	
}

