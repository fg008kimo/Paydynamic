/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/06              Dirk Wong  
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
#include "BOMMMBalance.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOMMMBalance(char    cdebug)
{
	cDebug = cdebug;
}


int UpdateAmount(hash_t* hBal)
{
	int iRet = PD_OK;

	char	*csEntityId;
	char	*csFromCcy;
	char	*csCcy;
	char	*csImitatePid;
	char	*csPool;
	char	cAmtType;
	double	dAmt = 0.0;
	char	*csUpdateUser = strdup("");
	double	dAcctBal = 0.0;
	double	dPrepaid = 0.0;
	double	dIntransit = 0.0;
	double	dLien = 0.0;

	hash_t *hVal;
	hVal = (hash_t*) malloc (sizeof(hash_t));

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "entity_id", &csEntityId)) {
DEBUGLOG(("UpdateAmount: entity_id = [%s]\n", csEntityId));
		} else {
DEBUGLOG(("UpdateAmount: entity_id NOT FOUND!!\n"));
ERRLOG("BOMMMBalance::UpdateAmount: entity_id NOT FOUND!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "from_ccy", &csFromCcy)) {
DEBUGLOG(("UpdateAmount: from_ccy = [%s]\n", csFromCcy));
		} else {
DEBUGLOG(("UpdateAmount: from_ccy NOT FOUND!!\n"));
ERRLOG("BOMMMBalance::UpdateAmount: from_ccy NOT FOUND!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "ccy", &csCcy)) {
DEBUGLOG(("UpdateAmount: ccy = [%s]\n", csCcy));
		} else {
DEBUGLOG(("UpdateAmount: ccy NOT FOUND!!\n"));
ERRLOG("BOMMMBalance::UpdateAmount: ccy NOT FOUND!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "imitate_pid", &csImitatePid)) {
DEBUGLOG(("UpdateAmount: imitate_pid = [%s]\n", csImitatePid));
		} else {
DEBUGLOG(("UpdateAmount: imitate_pid NOT FOUND!!\n"));
ERRLOG("BOMMMBalance::UpdateAmount: imitate_pid NOT FOUND!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_Char(hBal, "amt_type", &cAmtType)) {
DEBUGLOG(("UpdateAmount:: amt_type = [%c]\n", cAmtType));
		} else {
DEBUGLOG(("UpdateAmount:: amt_type not found!!\n"));
ERRLOG("BOMMMBalance: UpdateAmount:: amt_type not found!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hBal, "txn_amt", &dAmt)) {
DEBUGLOG(("UpdateAmount:: txn_amt = [%lf]\n", dAmt));
		} else {
DEBUGLOG(("UpdateAmount:: txn_amt not found!!\n"));
ERRLOG("BOMMMBalalnce: UpdateAmount:: txn_amt not found!!\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "update_user", &csUpdateUser)) {
DEBUGLOG(("UpdateAmount:: update_user = [%s]\n", csUpdateUser));
		} else {
DEBUGLOG(("UpdateAmount:: update_user not found!!\n"));
			csUpdateUser = strdup(PD_UPDATE_USER);	
			//sprintf(csUpdateUser, PD_UPDATE_USER);
DEBUGLOG(("UpdateAmount:: update_user (default) = [%s]\n", csUpdateUser));
		}
	}


	if (iRet == PD_OK) {
DEBUGLOG(("UpdateAmount:: DBMmsEntityBalance:GetEntityBalanceForUpdate\n"));
		hash_init(hVal,0);
                DBObjPtr = CreateObj(DBPtr,"DBMmsEntityBalance","GetEntityBalanceForUpdate");
                if ((*DBObjPtr)(hBal, hVal) != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("UpdateAmount:: DBMmsEntityBalance:GetEntityBalanceForUpdate Failed!!\n"));
		}
		else{
			if(GetField_Double(hVal, "acct_bal",&dAcctBal)){
				PutField_Double(hBal, "acct_bal",dAcctBal);
			}
			if(GetField_Double(hVal, "prepaid", &dPrepaid)) {
				PutField_Double(hBal, "prepaid", dPrepaid);
			}
			if(GetField_Double(hVal, "intransit", &dIntransit)) {
				PutField_Double(hBal, "intransit", dIntransit);
			}
			if(GetField_Double(hVal, "lien", &dLien)) {
				PutField_Double(hBal, "lien", dLien);
			}
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hBal, "pool", &csPool)) {
DEBUGLOG(("UpdateAmount:: pool = [%s]\n", csPool));
		} else {
DEBUGLOG(("UpdateAmount:: pool not found!!\n"));
ERRLOG("BOMMMBalalnce: UpdateAmount:: pool not found!!\n");
                        iRet = INT_ERR;
                }
        }

	if (iRet == PD_OK) {
		if (!strcmp(csPool, PD_ACCT_BAL_POOL)) {
			if (cAmtType == PD_IND_CREDIT) {
				dAcctBal += dAmt;
			} else {
				dAcctBal += (-1) * dAmt;
			}
			PutField_Double(hBal, "acct_bal", dAcctBal);
		} else if (!strcmp(csPool, PD_PREPAID_POOL)) {
			if (cAmtType == PD_IND_CREDIT) {
				dPrepaid += dAmt;
			} else {
				dPrepaid += (-1) * dAmt;
			}
			PutField_Double(hBal, "prepaid", dPrepaid);
		} else if (!strcmp(csPool, PD_INTRANSIT_POOL)) {
			if (cAmtType == PD_IND_CREDIT) {
				dIntransit += dAmt;
			} else {
				dIntransit += (-1) * dAmt;
			}
			PutField_Double(hBal, "intransit", dIntransit);
		} else if (!strcmp(csPool, PD_LIEN_POOL)) {
			if (cAmtType == PD_IND_CREDIT) {
				dLien += dAmt;
			} else {
				dLien += (-1) * dAmt;
			}
			PutField_Double(hBal, "lien", dLien);
		} else {
			iRet = INT_ERR;
DEBUGLOG(("UpdateAmount:: invalid pool!!\n"));
ERRLOG("BOMMMBalalnce: UpdateAmount:: invalid pool!!\n");
		}

		if(iRet==PD_OK){
DEBUGLOG(("UpdateAmount:: Call DBMmsEntityBalance:Update\n"));
			DBObjPtr = CreateObj(DBPtr, "DBMmsEntityBalance", "Update");
			if ((*DBObjPtr)(hBal) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("UpdateAmount:: Call DBMmsEntityBalance:Update failed!!\n"));
ERRLOG("BOMMMBalalnce: UpdateAmount:: Call DBMmsEntityBalance:Update failed!!\n");
			}
		}
	}


	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
        (*DBObjPtr)(hBal);
DEBUGLOG(("BOMMMBalalnce:CreditDepositAmount()  SystemControl::GetApprovalDT called\n"));

	if(iRet == PD_OK){
		hash_init(hVal,0);
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityBalance","GetEntityBalance");
		if((unsigned long)(*DBObjPtr)(hVal)!=PD_ERR){
			if(GetField_Double(hVal,"acct_bal",&dAcctBal)){
				PutField_Double(hBal,"bal",dAcctBal);
DEBUGLOG(("UpdateAmount:psp_balance = [%f]\n",dAcctBal));
			}
			if(GetField_Double(hVal,"prepaid",&dPrepaid)){
				PutField_Double(hBal,"prepaid",dPrepaid);
DEBUGLOG(("UpdateAmount:psp_total_hold = [%f]\n",dPrepaid));
			}
			if (GetField_Double(hVal, "intransit", &dIntransit)) {
				PutField_Double(hBal, "intransit", dIntransit);
DEBUGLOG(("UpdateAmount: prepaid = [%f]\n", dIntransit));
			}
			if (GetField_Double(hVal, "lien", &dLien)) {
				PutField_Double(hBal, "lien", dLien);
DEBUGLOG(("UpdateAmount: in_transit = [%f]\n", dLien));
			}
		}
	}

	FREE_ME(hVal);
	FREE_ME(csUpdateUser);
DEBUGLOG(("UpdateAmount:: iRet = [%d]\n", iRet));
	return iRet;
}

