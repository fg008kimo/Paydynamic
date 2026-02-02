/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/29              Dirk Wong
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
#include "BOOLPspCosts.h"

char    cDebug;

int GeneratePspCosts(hash_t *hContext);

void BOOLPspCosts(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(DB);

int CalOLPspCostsByParty(hash_t *hRequest, hash_t *hResponse)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;

	char*	csTmp;
	double	dTmp;

DEBUGLOG(("BOOLPspCosts::CalOLPspCostsByParty\n"));

	if (GetField_CString(hRequest,"provider_id",&csTmp)) {
DEBUGLOG(("CalOLPspCostsByParty() provider_id = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByParty() provider_id NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() provider_id NOT FOUND\n");
	}

	if (GetField_CString(hRequest,"psp_id",&csTmp)) {
DEBUGLOG(("CalOLPspCostsByParty() psp_id = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByParty() psp_id NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() psp_id NOT FOUND\n");
	}

	if (GetField_CString(hRequest,"baid",&csTmp)) {
DEBUGLOG(("CalOLPspCostsByParty() baid = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByParty() baid NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() baid NOT FOUND\n");
	}

	if (GetField_CString(hRequest,"org_txn_code",&csTmp)) {
DEBUGLOG(("CalOLPspCostsByParty() org_txn_code = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByParty() org_txn_code NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() org_txn_code NOT FOUND\n");
	}

	if (GetField_Double(hRequest,"txn_amt",&dTmp)) {
DEBUGLOG(("CalOLPspCostsByParty() txn_amt = [%f]\n",dTmp));
		PutField_Double(hResponse,"txn_amt",dTmp);
	} else {
DEBUGLOG(("CalOLPspCostsByParty() txn_amt NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() txn_amt NOT FOUND\n");
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CalOLPspCostsByParty() Call DBOLPspCosts::GetOLPspCostsByParty\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLPspCosts","GetOLPspCostsByParty");
		iTmpRet = (unsigned long)(*DBObjPtr)(hRequest,hResponse);
		if (iTmpRet == PD_FOUND) {
DEBUGLOG(("CalOLPspCostsByParty() Call DBOLPspCosts::GetOLPspCostsByParty FOUND\n"));
			iRet = GeneratePspCosts(hResponse);
			if (iRet != PD_OK) {
DEBUGLOG(("CalOLPspCostsByParty() DBOLPspCosts::GetOLPspCostsByParty FAILED\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() DBOLPspCosts::GetOLPspCostsByParty FAILED\n");
			}
		}
	} else {
DEBUGLOG(("CalOLPspCostsByParty() Call GeneratePspCostsByParty FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByParty() Call GeneratePspCostsByParty FOUND\n");
	}

	return iRet;
}

int CalOLPspCostsByID(hash_t *hRequest, hash_t *hResponse)
{
	int	iRet = PD_OK;

	char*	csTmp;
	int	iTmp;

DEBUGLOG(("BOOLPspCosts::CalOLPspCostsByID\n"));

	if (GetField_Int(hRequest,"rule_id",&iTmp)) {
DEBUGLOG(("CalOLPspCostsByID() rule_id = [%d]\n",iTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByID() rule_id NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByID() rule_id NOT FOUND\n");
	}

	if (GetField_CString(hRequest,"org_txn_code",&csTmp)) {
DEBUGLOG(("CalOLPspCostsByID() org_txn_code = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByID() org_txn_code NOT FOUND\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByID() org_txn_code NOT FOUND\n");
	}

	if (iRet == PD_OK) {
DEBUGLOG(("CalOLPspCostsByID() Call DBOLPspCosts::GetOLPspCostsById\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLPspCosts","GetOLPspCostsById");
		if ((unsigned long)(*DBObjPtr)(hRequest,hResponse) == PD_FOUND) {
DEBUGLOG(("CalOLPspCostsByID() Call GeneratePspCosts\n"));
			iRet = GeneratePspCosts(hResponse);
			if (iRet != PD_OK) {
DEBUGLOG(("CalOLPspCostsByID() GeneratePspCosts FAILED\n"));
ERRLOG("BOOLPspCosts::CalOLPspCostsByID() GeneratePspCosts FAILED\n");
			}
		} else {
			iRet = INT_ERR;
DEBUGLOG(("CalOLPspCostsByID() DBOLPspCosts::GetOLPspCosts NOT FOUND\n"));
		}
	}

	return iRet;
}

int GeneratePspCosts(hash_t *hContext)
{
	int	iRet = PD_OK;

	char	cCostingMethod;
	double	dValue=0.0;
	double	dAddValue=0.0;
	double	dMinValue=0.0;
	double	dMaxValue=0.0;
	char	cValueType;
	int	iScale = 0;
	double	dTxnAmt;
	double	dFee=0.0;

//	recordset_t     *rRecordSet;
//	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
//	recordset_init(rRecordSet,0);

DEBUGLOG(("BOOLPspCosts::GeneratePspCosts()\n"));

 	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("GeneratePspCosts() txn_amt = [%f]\n",dTxnAmt));
        }
        else {
DEBUGLOG(("GeneratePspCosts() txn_amt not found!!!\n"));
        }

	if (GetField_Char(hContext,"costing_method",&cCostingMethod)) {
DEBUGLOG(("GeneratePspCosts() Precal_type = [%c]\n",cCostingMethod));
	}

	if (GetField_Double(hContext,"value",&dValue)) {
DEBUGLOG(("GeneratePspCosts() value = [%f]\n",dValue));
	}

	if (GetField_Double(hContext,"add_value",&dAddValue)) {
DEBUGLOG(("GeneratePspCosts() additional_value = [%f]\n",dAddValue));
	}

	if (GetField_Double(hContext,"min_value",&dMinValue)) {
DEBUGLOG(("GeneratePspCosts() min_value = [%f]\n",dMinValue));
	}

	if (GetField_Double(hContext,"max_value",&dMaxValue)) {
DEBUGLOG(("GeneratePspCosts() max_value = [%f]\n",dMaxValue));
	}

	if (GetField_Char(hContext,"value_type",&cValueType)) {
DEBUGLOG(("GeneratePspCosts() value_type = [%c]\n",cValueType));
	}

	if (GetField_Int(hContext,"scale",&iScale)) {
DEBUGLOG(("GeneratePspCosts() scale = [%d]\n",iScale));
	}

DEBUGLOG(("GeneratePspCosts() Precal costs Now!!!\n"));
	double dTmp = 0;
	if (cCostingMethod == PD_PRECENTAGE) {
		dTmp = dTxnAmt * (dValue/100);
	}
	else if (cCostingMethod == PD_FIXED_AMOUNT) {
		dTmp = dValue;
	}
	else if(cCostingMethod == PD_PRECENT_WITH_FIX){
		dTmp = dTxnAmt * (dValue/100);
		dTmp += dAddValue;
	}
DEBUGLOG(("GeneratePspCosts() costs before rounding = [%f]\n",dTmp));
	if (cValueType == PD_ROUNDING) {
		dFee = newround(dTmp,iScale);
	}
	else if (cValueType == PD_TRUNC) {
		dFee = newtrunc(dTmp,iScale);
	}
	else if (cValueType == PD_CELING) {
		dFee = newceling(dTmp,iScale);
	}
	else {
DEBUGLOG(("GeneratePspCosts() undefine value_type = [%c]\n",cValueType));
ERRLOG("BOOLPspCosts::GeneratePspCosts() undefine value_type = [%c]\n",cValueType);
	}

	if(dFee<dMinValue && dMinValue>0){
		dFee = dMinValue;
	}
	if(dFee>dMaxValue && dMaxValue>0){
		dFee = dMaxValue;
	}
		

DEBUGLOG(("GeneratePspCosts() Precal fee = [%f]\n",dFee));
	PutField_Double(hContext,"precal_fee",dFee);


DEBUGLOG(("GeneratePspCosts() exit = [%d]\n",iRet));
	return iRet;

}


