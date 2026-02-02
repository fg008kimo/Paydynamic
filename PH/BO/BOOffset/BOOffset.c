/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/04/12              Elvis Wong
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
#include "BOOffset.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOOffset(char    cdebug)
{
        cDebug = cdebug;
}

int     ProcessPartyBalance(hash_t* hInRec)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_FOUND;
	int	iTmp = 0;
	int	iDisabled = 0;

	double  dAmt = 0.0;
        double  dAvaBalance = 0.0;
        double  dTmp = 0.0;

	char	*csCode = NULL;
	char	*csPspId = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;	
	char	*csUser = NULL;
	char	*csAmtType = NULL;
	char	*csTmp = NULL;

	char    cPartyType;
	char	cBalType;
	char	cPspBalType;
	char	cTmp;

	hash_t          *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);	

	hash_t	*hTxn;
	hTxn = (hash_t *)malloc(sizeof(hash_t));
	hash_init(hTxn, 0);
	
/* code */
	if (GetField_CString(hInRec, "code", &csCode)) {
DEBUGLOG(("ProcessPartyBalance::code [%s]\n", csCode));
	} else {
DEBUGLOG(("ProcessPartyBalance::code missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::code missing!!\n");
                iRet = INT_CODE_ERROR;
                PutField_Int(hInRec, "internal_error", iRet);
        }

/* party_type */
	if (GetField_Char(hInRec,"party_type",&cPartyType)) {
DEBUGLOG(("ProcessPartyBalance::party_tye [%c]\n",cPartyType));
        } else {
DEBUGLOG(("ProcessPartyBalance::party_type missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::party_type missing!!\n");
                iRet = INT_PARTY_TYPE_NOT_FOUND;
                PutField_Int(hInRec, "internal_error", iRet);
	}

/* psp_id */
	if (cPartyType == PD_TYPE_PSP) {
		if (GetField_CString(hInRec, "psp_id", &csPspId)) {
DEBUGLOG(("ProcessPartyBalance::psp_id [%s]\n", csPspId));
       		} else {
DEBUGLOG(("ProcessPartyBalance::psp_id missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::psp_id missing!!\n");
             		iRet = INT_PSP_RETURN_ERROR;
               		PutField_Int(hInRec, "internal_error", iRet);
    		}
	}

/* country */
	if (GetField_CString(hInRec, "txn_country", &csCountry)) {
DEBUGLOG(("ProcessPartyBalance::country [%s]\n", csCountry));
	} else {
DEBUGLOG(("ProcessPartyBalance::country missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::country missing!!\n");
                iRet = INT_COUNTRY_PSP_NOT_AVABILE;
                PutField_Int(hInRec, "internal_error", iRet);
        }

/* ccy */
	if (GetField_CString(hInRec, "txn_ccy", &csCcy)) {
DEBUGLOG(("ProcessPartyBalance::ccy [%s]\n", csCcy));
	} else {
DEBUGLOG(("ProcessPartyBalance::ccy missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::ccy missing!!\n");
                iRet = INT_CURRENCY_CODE_NOT_FOUND;
                PutField_Int(hInRec, "internal_error", iRet);
        }

/* txn_amt */
        if (GetField_Double(hInRec,"txn_amt",&dAmt)){
DEBUGLOG(("ProcessPartyBalance::txn_amt= [%f]\n",dAmt));
                PutField_Double(hInRec, "net_amt", dAmt);
	} else {
DEBUGLOG(("ProcessPartyBalance::txn_amt missing\n"));
ERRLOG("BOOffset::ProcessPartyBalance::txn_amt missing!!\n");
                iRet = INT_PAY_AMOUNT_NOT_FOUND;
                PutField_Int(hInRec, "internal_error", iRet);
        }         

/* udpate_user */
        if (GetField_CString(hInRec,"add_user",&csUser)){
DEBUGLOG(("ProcessPartyBalance::add_user= [%s]\n",csUser));
	}

	// Check and Get Offset Txn Type Record
	if (iRet == PD_OK) {
	
DEBUGLOG(("ProcessPartyBalance::Call DBOffsetTxnType:GetOffsetTxnRec\n"));
                DBObjPtr = CreateObj(DBPtr,"DBOffsetTxnType","GetOffsetTxnRec");
                iDtlRet = (unsigned long)(*DBObjPtr)(cPartyType, csCode, rRecordSet);
                if (iDtlRet == PD_FOUND) {

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

/* desc */
				if (GetField_CString(hRec,"desc",&csTmp)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::desc = [%s]\n",csTmp));

                                        PutField_CString(hInRec, "desc", csTmp);
                                }

/* amt_type */
                                if (GetField_CString(hRec,"amt_type",&csAmtType)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::amt_type = [%s]\n",csAmtType));

					// amount_type
                                       	PutField_CString(hInRec, "amount_type", csAmtType);
                                }

/* bal_type */
				if (GetField_Char(hRec,"bal_type",&cBalType)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::bal_type = [%c]\n",cBalType));

					// psp_bal_type
					if (cBalType == PD_OFFSET_TXN_TYPE_PSP_BALANCE) {
						cPspBalType = PD_PSP_BAL;
					} else if (cBalType == PD_OFFSET_TXN_TYPE_PSP_FLOAT) {	
						cPspBalType = PD_PSP_FLOAT;	
					}
                                }

/* allow_modify */
				if (GetField_Int(hRec, "allow_modify", &iTmp)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::allow_modify = [%d]\n", iTmp));
                                }

/* allow_bal_negative */
                                if (GetField_Int(hRec, "allow_bal_negative", &iTmp)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::allow_bal_negative = [%d]\n", iTmp));
                                }

/* nature */
                                if (GetField_Char(hRec, "nature", &cTmp)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::nature = [%c]\n", cTmp));
                                }

/* disabled */
                                if (GetField_Int(hRec, "disabled", &iDisabled)) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::disabled = [%d]\n",iDisabled));

                                        if (iDisabled == PD_DISABLED) {

DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec::not allow to use the txn code\n"));
ERRLOG("BOOffset::ProcessPartyBalance::GetOffsetTxnRec:: txn code in disabled!!\n");
                                                iRet = INT_CODE_DISABLED;
                                                PutField_Int(hInRec, "internal_error", iRet);
                                                break;
                                        }
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
		else if (iDtlRet == PD_NOT_FOUND) {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec:: txn_code not available\n"));
ERRLOG("BOOffset::ProcessPartyBalance::GetOffsetTxnRec:: txn_code not available!!\n");
                        iRet = INT_TXN_CODE_NOT_AVAILABLE;
                        PutField_Int(hInRec, "internal_error", iRet);			
		}
                else {
DEBUGLOG(("ProcessPartyBalance::GetOffsetTxnRec:: failed\n"));
ERRLOG("BOOffset::ProcessPartyBalance::GetOffsetTxnRec:: failed!!\n");
                        iRet = INT_ERR;
                        PutField_Int(hInRec, "internal_error", iRet);
                }
	}
	
	// Check Party Type
	if (cPartyType == PD_TYPE_PSP) {
/*
 * PSP Balance = PSP Available + PSP Lien (Hold) 
 *
 * PSP Available Balance = PSP Available + PSP Float
 * 
 * PSP Total Balance = PSP Available + PSP Float + PSP Lien (Hold)
 */

		// Get PSP Available Balance for Update
		if (iRet == PD_OK) {
DEBUGLOG(("ProcessPartyBalance::Call BOBalance:GetAvalPspBalanceForUpdate\n"));
        		BOObjPtr = CreateObj(BOPtr,"BOBalance","GetAvalPspBalanceForUpdate");
              		if((unsigned long)((*BOObjPtr)(csCountry, csCcy, csPspId, &dAvaBalance) != PD_OK)) {
DEBUGLOG(("ProcessPartyBalance::BOBalance:GetAvalPspBalanceForUpdate Failed\n"));
ERRLOG("BOOffset::BOBalance:GetAvalPspBalanceForUpdate Failed\n");
                	   	iRet=INT_ERR;
               		} else {
DEBUGLOG(("ProcessPartyBalance::BOBalance:PSP Balance [%lf]\n", dAvaBalance));
			
				// Get approval date and approval timestamp
				DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
				if ((*DBObjPtr)(hInRec) == PD_OK) {
					if (GetField_CString(hInRec, "approval_date", &csTmp))  {
DEBUGLOG(("ProcessPartyBalance::BOBalance:PSP approval_date [%s]\n", csTmp));
					}

					if (GetField_CString(hInRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("ProcessPartyBalance::BOBalance:PSP approval_timestamp [%s]\n", csTmp));
					}
				}
              		}
      		}

		// Credit/Debit PSP Balance
		if (iRet == PD_OK) {

			// Check Amt Type
			if (!strcmp(csAmtType, PD_DR)) {

				// Check Balance (PSP Available Balance)
				if (newround(dAmt,PD_DECIMAL_LEN) > newround(dAvaBalance,PD_DECIMAL_LEN)) {
DEBUGLOG(("ProcessPartyBalance::CANNOT process as not enought PSP [%s] Balance [%lf] Amt [%lf]\n", csPspId, dAvaBalance, dAmt));
					iRet = INT_INSUFFICIENT_FUND;
					PutField_Int(hInRec, "internal_error", iRet);
				}

				// Debit Balance (PSP Balance)
				if (iRet == PD_OK) {
DEBUGLOG(("ProcessPartyBalance::Call DBPspBalance:DebitBalance\n"));
					DBObjPtr = CreateObj(DBPtr,"DBPspBalance","DebitBalance");
					if ((*DBObjPtr)(csPspId,csCountry, csCcy, cPspBalType, dAmt, csUser) != PD_OK) {
DEBUGLOG(("ProcessPartyBalance::DBPspBalance:DebitBalance Failed\n"));
						iRet = INT_ERR;
					}
				}
			} else if (!strcmp(csAmtType, PD_CR)) {
		
				// Credit Balance (PSP Balance)
DEBUGLOG(("ProcessPartyBalance::Call DBPspBalance:CreditBalance\n"));
        	              	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","CreditBalance");
        	             	if ((*DBObjPtr)(csPspId,csCountry, csCcy, cPspBalType, dAmt, csUser) != PD_OK) {
DEBUGLOG(("ProcessPartyBalance::DBPspBalance:DebitBalance Failed\n"));
        	                     	iRet = INT_ERR;
        	              	}			
			}
		}

		// Get PSP Total Balance (PSP Balance, PSP Float and PSP Lien)
		if (iRet == PD_OK) {

DEBUGLOG(("ProcessPartyBalance::Call DBPspBalance:GetBalance\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBPspBalance","GetBalance");
                	if ((*DBObjPtr)(csPspId, csCountry, csCcy, hTxn) == PD_OK) {

                	        if (GetField_Double(hTxn, "balance", &dTmp)) {
DEBUGLOG(("ProcessPartyBalance::Psp GetBalance::balance = [%f]\n",dTmp));
                	                PutField_Double(hInRec, "bal", dTmp);
					PutField_Double(hInRec, "current_bal", dTmp);
                	        }

                	        if (GetField_Double(hTxn, "total_float", &dTmp)) {
DEBUGLOG(("ProcessPartyBalance::Psp GetBalance::total_float = [%f]\n",dTmp));
                	                PutField_Double(hInRec, "total_float", dTmp);
                	        }
	
        	                if (GetField_Double(hTxn, "total_hold", &dTmp)) {
DEBUGLOG(("ProcessPartyBalance::Psp GetBalance::total_hold = [%f]\n",dTmp));
        	                        PutField_Double(hInRec, "total_hold", dTmp);
        	                }
        	        }
        	        else {
ERRLOG("BOOffset::PSP GetBalance::Balance for PspId[%s] not found\n",csPspId);
DEBUGLOG(("ProcessPartyBalance::Psp GetBalance::Balance for PspId[%s] not found\n", csPspId));
        	                iRet = INT_ERR;
        	        }
		}
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("ProcessPartyBalance::Return iRet [%d]\n", iRet));

	return iRet;	
}

