/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/17              Dirk Wong
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
#include "BOMMMCreditLimit.h"

char    cDebug;

void BOMMMCreditLimit(char cdebug)
{
        cDebug = cdebug;
}

OBJPTR(DB);

int CalCreditLimit(hash_t *hContext)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;

	char	*csTmp;

	char	cRAType;
	double	dRAValue = 0.0;
	double	dRAAddValue = 0.0;
	double	dRAMinValue = 0.0;
	double	dRAMaxValue = 0.0;

	double	dAcctBal = 0.0;
	double	dCreditLimit = 0.0;

	hash_t	*hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp,0);

DEBUGLOG(("BOMMMCreditLimit::CalCreditLimit\n"));

//entity_id
	if (GetField_CString(hContext,"entity_id",&csTmp)) {
DEBUGLOG(("CalCreditLimit() entity_id = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit() entity_id NOT FOUND!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit() entity_id NOT FOUND!\n");
	}

//ccy
	if (GetField_CString(hContext,"ccy",&csTmp)) {
DEBUGLOG(("CalCreditLimit() ccy = [%c]\n", csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit() ccy NOT FOUND!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit() ccy NOT FOUND!\n");
	}

//country
	if (GetField_CString(hContext,"country",&csTmp)) {
DEBUGLOG(("CalCreditLimit() country = [%c]\n", csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit() country NOT FOUND!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit() country NOT FOUND!\n");
	}

//txn_code
	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("CalCreditLimit() txn_code = [%c]\n", csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit() txn_code NOT FOUND!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit() txn_code NOT FOUND!\n");
	}

//acct_bal
	if (GetField_Double(hContext,"acct_bal",&dAcctBal)) {
DEBUGLOG(("CalCreditLimit() acct_bal = [%.f]\n", dAcctBal));
		if (dAcctBal < 0)
			dAcctBal = 0.0;
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit() acct_bal NOT FOUND!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit() acct_bal NOT FOUND!\n");
	}



	if (iRet == PD_OK) {
DEBUGLOG(("CalCreditLimit() CALL DBMmsRuleCreditLimit:GetMmsRuleCreditLimit\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsRuleCreditLimit","GetMmsRuleCreditLimit");
		iTmpRet = (unsigned long)(*DBObjPtr)(hContext,hTmp);
		if (iTmpRet == PD_FOUND) {
			//Start Calculate...
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit: Rule Found!\n"));
			if (GetField_Char(hTmp, "ra_type", &cRAType)) {
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit:GetMmsRuleCreditLimit ra_type=[%.f]\n", cRAType));
			}
			if (GetField_Double(hTmp, "ra_value", &dRAValue)) {
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit:GetMmsRuleCreditLimit ra_value=[%.f]\n", dRAValue));
			}
			if (GetField_Double(hTmp, "ra_add_value", &dRAAddValue)) {
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit:GetMmsRuleCreditLimit ra_add_value=[%.f]\n", dRAAddValue));
			}
			if (GetField_Double(hTmp, "ra_min_value", &dRAMinValue)) {
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit:GetMmsRuleCreditLimit ra_min_value=[%.f]\n", dRAMinValue));
			}
			if (GetField_Double(hTmp, "ra_max_value", &dRAMaxValue)) {
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit:GetMmsRuleCreditLimit ra_max_value=[%.f]\n", dRAMaxValue));
			}

DEBUGLOG(("CalCreditLimit:: Calculate START\n"));

			switch (cRAType) {
				case PD_PRECENTAGE:
					dCreditLimit = dAcctBal + (dAcctBal * (dRAValue/100));
					break;
				case PD_FIXED_AMOUNT:
					dCreditLimit = dAcctBal + dRAValue;
					break;
				case PD_PRECENT_WITH_FIX:
					dCreditLimit = dAcctBal + (dRAAddValue + (dAcctBal * (dRAValue/100)));
					break;
				default:
					iRet = INT_ERR;
DEBUGLOG(("CalCreditLimit:: DBMmsRuleCreditLimit: unknown ra_type!\n"));
ERRLOG("BOMMMCreditLimit::CalCreditLimit:: DBMmsRuleCreditLimit: unknown ra_type!!\n");
					break;
			}

			if (dCreditLimit < dRAMinValue && dRAMinValue > 0) {
DEBUGLOG(("CalCreditLimit:: Min value applied!\n"));
				dCreditLimit = dRAMinValue;
			}
			if (dCreditLimit > dRAMaxValue && dRAMaxValue > 0) {
DEBUGLOG(("CalCreditLimit:: Max value applied!\n"));
				dCreditLimit = dRAMaxValue;
			}

DEBUGLOG(("CalCreditLimit:: credit_limit = [%f]\n", dCreditLimit));
			PutField_Double(hContext,"credit_limit",dCreditLimit);
		} else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("CalCreditLimit:: No rule found, credit_limit = 0\n"));
			PutField_Double(hContext,"credit_limit",0);
		} else {
			iRet = iTmpRet;
DEBUGLOG(("CalCreditLimit() CALL DBMmsRuleCreditLimit:GetMmsRuleCreditLimit return ERROR!\n"));
		}
	}

	FREE_ME(hTmp);

	return iRet;
}

