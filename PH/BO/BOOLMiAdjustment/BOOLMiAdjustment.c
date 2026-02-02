/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/05              Dirk Wong
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
#include "BOOLMiAdjustment.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOOLMiAdjustment(char    cdebug)
{
        cDebug = cdebug;
}

int GetCurrentCode(hash_t *hRec)
{
        int     iRet = PD_OK;

	char	*csEntityType;
	char	cAction;

	int	iMaxCodeInNum = -1;	

	if (GetField_CString(hRec, "entity_type", &csEntityType)) {
DEBUGLOG(("GetCurrentCode::Entity_type [%s]\n", csEntityType));
	}

	if (GetField_Char(hRec, "action", &cAction)) {
DEBUGLOG(("GetCurrentCode::action [%c]\n", cAction));
	}

DEBUGLOG(("GetCurrentCode::Call MiOLAdjustmentType: GetMaxCode\n"));

	DBObjPtr = CreateObj(DBPtr,"DBMiOLAdjustmentType","GetMaxCode");
        if((unsigned long)((*DBObjPtr)(csEntityType, &iMaxCodeInNum)) ==PD_OK) {

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
ERRLOG("BOOLMiAdjustment::GetCurrentCode::GetMaxCode not found!!\n");
		iRet=INT_ERR;
        }

DEBUGLOG(("GetCurrentCode: return iRet [%d]\n", iRet));

	return 	iRet;
}


int     ValidateProcess(hash_t* hInRec)
{
DEBUGLOG(("ValidateProcess:: Begin\n"));
        int     iRet = PD_OK;
	int	iTmpRet = PD_OK;

        char    cAction;
        char	*csEntityType; 
        char    *csCode = NULL;

	int	iCodeInNum;

	char	*csNewAmtType;
	char	*csCurrentAmtType;

        char    cNewNature;
        char    cCurrentNature;

        char    cNewBalType;
        char    cCurrentBalType;

	int	iNewDisabled;
	int	iCurrentDisabled;

	int	iNewIsProrata;
	int	iCurrentIsProrata;

        hash_t          *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));

        recordset_init(rRecordSet, 0);

        if (!(GetField_Char(hInRec, "action", &cAction))) {
DEBUGLOG(("ValidateProcess:: Not Complete Information cAction [%c]\n", cAction));
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		if (!(GetField_CString(hInRec, "entity_type", &csEntityType) &&
	                GetField_CString(hInRec, "code", &csCode) &&
			GetField_Int(hInRec, "code_in_num", &iCodeInNum) &&
			GetField_CString(hInRec, "amt_type", &csNewAmtType) && 
			GetField_Char(hInRec, "bal_type", &cNewBalType) && 
			GetField_Char(hInRec, "nature", &cNewNature) && 
			GetField_Int(hInRec, "is_prorata", &iNewIsProrata))) {
DEBUGLOG(("ValidateProcess:: Not Complete Information csEntityType [%s] csCode [%s] iCodeInNum [%d] csAmtType [%s] cBalType [%c] cNature [%c] iIsProrata [d]\n",
							 csEntityType, csCode, iCodeInNum, csNewAmtType, cNewBalType, cNewNature, iNewIsProrata));
			iRet = PD_ERR;

		} 
	}
	else {
DEBUGLOG(("ValidateProcess:: csEntityType [%s] csCode [%s] iCodeInNum[%d] csAmtType[%s] cBalType[%c] cNature[%c] iIsProrata[d]\n", 
				csEntityType, csCode, iCodeInNum, csNewAmtType, cNewBalType, cNewNature, iNewIsProrata));
	}



        /* if record exists and action is delete, not allow */
        /* if record exists and action is update, only allow update desc */

        if (iRet == PD_OK) {

		if (cAction != PD_ACTION_ADD) { 

			DBObjPtr = CreateObj(DBPtr,"DBMiOLAdjustmentType","GetMiOLAdjustmentTypeRec");
			if ((*DBObjPtr)(csEntityType, csCode, rRecordSet) == PD_OK) {

				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_Int(hRec, "disabled", &iCurrentDisabled)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::disabled = [%d]\n",iCurrentDisabled));
					}

					if (GetField_CString(hRec, "amt_type", &csCurrentAmtType)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::amt_type = [%s]\n",csCurrentAmtType));
					}

					if (GetField_Char(hRec, "bal_type", &cCurrentBalType)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::bal_type = [%c]\n",cCurrentBalType));
					}

					if (GetField_Char(hRec, "nature", &cCurrentNature)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::nature = [%c]\n",cCurrentNature));
					}

					if (GetField_Int(hRec, "is_prorata", &iCurrentIsProrata)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::is_prorata = [%d]\n",iCurrentIsProrata));
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("ValidateProces::GetMiOLAdjustmentTypeRec:: failed\n"));
ERRLOG("BOOLMiAdjustment::ValidateProcess::GetMiOLAdjustmentTypeRec:: failed!!\n");
			}

			/* **special handling disabled field** */
			if (cAction == PD_ACTION_UPDATE) {

					/* If there is no disabled field passed, get the existing one */
					if (!GetField_Int(hInRec, "disabled", &iNewDisabled)) {
						PutField_Int(hInRec, "disabled", iCurrentDisabled);
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::Assigne disabled = [%d]\n",iCurrentDisabled));
					}

			}

			if (iRet == PD_OK) {

DEBUGLOG(("ValidateProcess::Call OLTransaction: ChkTxnCodeExist\n"));
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
						if (strcmp(csNewAmtType, csCurrentAmtType)) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::amt_type = [%s] not match with new amt_type [%s], not allow update\n",csCurrentAmtType, csNewAmtType));
							iRet = PD_ERR;
						}

						if (cNewBalType != cCurrentBalType) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::bal_type = [%c] not match with new bal_type [%c], not allow update\n",cCurrentBalType, cNewBalType));
							iRet = PD_ERR;
						}

						if (cNewNature != cCurrentNature) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::Nature = [%c] not match with new nature [%c], not allow update\n",cCurrentNature, cNewNature));
							iRet = PD_ERR;
						}

						if (iNewIsProrata != iCurrentIsProrata) {
DEBUGLOG(("ValidateProcess::GetMiOLAdjustmentTypeRec::is_prorata = [%d] not match with new is_prorata [%d], not allow update\n",iCurrentIsProrata, iNewIsProrata));
							iRet = PD_ERR;
						}
                        		}
                		}
                		else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("ValidateProcess::Call OLTransaction: ChkTxnCodeExist: NOT FOUND\n"));
                		}
				else {
DEBUGLOG(("ValidateProcess::Call OLTransaction: ChkTxnCodeExist: ERR\n"));
ERRLOG("BOOLMiAdjustment::ValidateProcess::Call Transaction: ChkTxnCode Exist :: ERR!!\n");
					iRet = PD_ERR;
				}	
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

	char	*csEntityType;

	char	*csCode = NULL;
	char	*csCountry = NULL;
	char	*csFrCcy = NULL;
	char	*csCcy = NULL;	
	char	*csProductCode = NULL;
	char	*csUpdateUser = NULL;

	char	*csAmtType = NULL;
	char	cBalType;
	char	cNature;
	int	iIsProrata;

	double	dFrAmt=0.0;
        double  dAmt=0.0;
	double  dNetAmt=0.0;
        double  dTmp=0.0;

	int	iDisabled;
	int	iBalanceTransfer = PD_FALSE;

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

/* entity_type */
	if (GetField_CString(hInRec, "entity_type", &csEntityType)) {
DEBUGLOG(("ProcessPartyBalance::Entity_type [%s]\n", csEntityType));
	}

/* country */
	if (GetField_CString(hInRec, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessPartyBalance::country [%s]\n", csCountry));
		PutField_CString(hInRec, "country", csCountry);
	}

/* product_code */
	if (GetField_CString(hInRec, "product_code", &csProductCode)) {
DEBUGLOG(("ProcessPartyBalance::product_code [%s]\n", csProductCode));
	}

/* fr_ccy */
	if (GetField_CString(hInRec, "fr_ccy", &csFrCcy)) {
DEBUGLOG(("ProcessPartyBalance::fr_ccy [%s]\n", csFrCcy));
	}

/* ccy */
	if (GetField_CString(hInRec, "txn_ccy", &csCcy)) {
DEBUGLOG(("ProcessPartyBalance::ccy [%s]\n", csCcy));
		PutField_CString(hInRec, "ccy", csCcy);
	}

/* balance_transfer */
	if (GetField_Int(hInRec, "balance_transfer", &iBalanceTransfer)) {
DEBUGLOG(("ProcessPartyBalance::balance_transfer [%d]\n", iBalanceTransfer));
	}

	recordset_init(rRecordSet, 0);


	if (iBalanceTransfer == PD_FALSE) {	

DEBUGLOG(("ProcessPartyBalance::Call DBMiOLAdjustment:GetMiOLAdjustmentTypeRec\n"));

		DBObjPtr = CreateObj(DBPtr,"DBMiOLAdjustmentType","GetMiOLAdjustmentTypeRec");
		if ((*DBObjPtr)(csEntityType, csCode, rRecordSet) == PD_OK) {

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"amt_type",&csAmtType)) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::amt_type = [%s]\n",csAmtType));
					PutField_CString(hInRec, "amt_type", csAmtType);
				}

				if (GetField_Char(hRec, "bal_type", &cBalType)) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::bal_type = [%c]\n", cBalType));
					PutField_Char(hInRec, "bal_type", cBalType);
				}

				if (GetField_Char(hRec, "nature", &cNature)) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::nature = [%c]\n", cNature));
					PutField_Char(hInRec, "nature", cNature);
				}

				if (GetField_Int(hRec, "is_prorata", &iIsProrata)) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::is_prorata= [%d]\n", iIsProrata));
					PutField_Int(hInRec, "is_prorata", iIsProrata);
					PutField_Int(hInRec, "acr_prorata", iIsProrata);
				}

				if (GetField_Int(hRec, "disabled", &iDisabled)) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::disabled = [%d]\n",iDisabled));

					if (iDisabled == PD_DISABLED) {
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec::not allow to use the code\n"));
ERRLOG("BOOLMiAdjustment::ProcessPartyBalance::GetMiOLAdjustmentTypeRec:: code in disabled!!\n");
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
DEBUGLOG(("ProcessPartyBalance::GetMiOLAdjustmentTypeRec:: failed\n"));
ERRLOG("BOMiAdjustment::ProcessPartyBalance::GetMiOLAdjustmentTypeRec:: failed!!\n");
			PutField_Int(hInRec, "internal_error", iRet);
		}
	}
	else {
		GetField_CString(hInRec, "amt_type", &csAmtType);
DEBUGLOG(("ProcessPartyBalance::BalanceTransfer::amt_type = [%s]\n",csAmtType));
	}

	if (iRet == PD_OK) {
// update_user
	        if(GetField_CString(hInRec,"add_user",&csUpdateUser)){
DEBUGLOG(("ProcessPartyBalance::add_user= [%s]\n",csUpdateUser));
			PutField_CString(hInRec, "update_user", csUpdateUser);
		}

/* fr_txnamt */
	        if(GetField_Double(hInRec,"fr_txnamt",&dFrAmt)){
DEBUGLOG(("ProcessPartyBalance::fr_txnamt= [%f]\n",dFrAmt));
	        }

/* net_amt */
	        if(GetField_Double(hInRec,"net_amt",&dNetAmt)){
DEBUGLOG(("ProcessPartyBalance::net_amt= [%f]\n",dNetAmt));
	        }
	}


	if (iRet == PD_OK) {
		PutField_Double(hInRec, "display_amt", dNetAmt);
		PutField_Double(hInRec, "txn_amount", dAmt);
		PutField_Char(hInRec, "batch_mode", PD_OFFLINE);

		if (iRet == PD_OK) {
DEBUGLOG(("BOMiAdjustment::ProcessPartyBalance::Call BOMiEntityBalance:UpdateEntityBalance\n"));
			BOObjPtr = CreateObj(BOPtr, "BOMiEntityBalance", "UpdateEntityBalance");
			iRet = (unsigned long)((*BOObjPtr)(hInRec,hInRec));
			if(iRet == PD_OK) {
				if (GetField_CString(hInRec, "approval_date", &csTmp)) {
DEBUGLOG(("BOMiAdjustment::ProcessPartyBalance::BAID approval_date [%s]\n", csTmp));
				}

				if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("BOMiAdjustment::ProcessPartyBalance::BAID approval_timestamp [%s]\n", csTmp));
				}

				// Open Balance
				if (GetField_Double(hTxn, "open_acct_bal", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::open_acct_bal = [%f]\n", dTmp));
					PutField_Double(hInRec, "rsp_open_acct_bal", dTmp);
				}

				if (GetField_Double(hTxn, "open_intransit", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::open_intransit = [%f]\n", dTmp));
					PutField_Double(hInRec, "rsp_open_intransit", dTmp);
				}

				if (GetField_Double(hTxn, "open_ar_bal", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::open_ar_bal = [%f]\n", dTmp));
					PutField_Double(hInRec, "rsp_open_ar_bal", dTmp);
				}


				// Close Balance
				if (GetField_Double(hInRec, "acct_bal", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::closing acct_bal = [%f]\n", dTmp));
					PutField_Double(hInRec, "acct_bal", dTmp);
				}

				if (GetField_Double(hInRec, "intransit", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::closing intransit = [%f]\n", dTmp));
				}

				if (GetField_Double(hInRec, "ar_bal", &dTmp)) {
DEBUGLOG(("BOMiAdjustment::closing ar_bal = [%f]\n", dTmp));
				}

			} else {
DEBUGLOG(("BOMiAdjustment::UpdateEntityBalance Failed\n"));
ERRLOG("BOMiAdjustment::UpdateEntityBalance Failed\n");
			}
		}
	}


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(hTxn);


DEBUGLOG(("ProcessPartyBalance::Return iRet [%d]\n", iRet));

	return iRet;	
}

