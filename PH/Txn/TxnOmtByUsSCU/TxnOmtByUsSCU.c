/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/12/19              Stan Poon
Revised Sim Card Management			   2014/08/25		   Dirk Wong
Modify sim_package to varchar                      2015/02/03              Dirk Wong
Add Expired Date				   2015/02/26		   Dirk Wong
Add Sim Nature					   2015/08/18		   Dirk Wong
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsSCU.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsSCU(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	cAction;
	char	*csTmp;
	char	cTmp;
	double	dTmp;
	int	iTmp;

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize() action = [%c]\n", cAction));
		PutField_Char(hContext,"action",cAction);
	} else {
DEBUGLOG(("Authorize:: action not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: action not found!!\n");
                iRet = INT_ACTION_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* mobile */
	if (GetField_CString(hRequest, "reg_mob_num", &csTmp)) {
DEBUGLOG(("Authorize() mobile = [%s]\n", csTmp));
		PutField_CString(hContext,"mob_num",csTmp);
	} else {
DEBUGLOG(("Authorize:: mobile not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: mobile not found!!\n");
                iRet = INT_MOBILE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* carriers */
	if (GetField_CString(hRequest, "carriers", &csTmp)) {
DEBUGLOG(("Authorize() carriers = [%s]\n", csTmp));
		PutField_CString(hContext,"carriers",csTmp);
	} else {
DEBUGLOG(("Authorize:: carriers not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: carriers not found!!\n");
                iRet = INT_CARRIERS_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* owner_name */
	if (GetField_CString(hRequest, "owner_name", &csTmp)) {
DEBUGLOG(("Authorize() owner_name = [%s]\n", csTmp));
		PutField_CString(hContext,"owner_name",csTmp);
	}

/* sim_credit */
	if (GetField_CString(hRequest, "sim_credit", &csTmp)) {
		dTmp = atof(csTmp);
DEBUGLOG(("Authorize() sim_credit = [%.2f]\n", dTmp));
		PutField_Double(hContext,"sim_credit",dTmp);
	} else {
DEBUGLOG(("Authorize:: sim credit not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: sim credit not found!!\n");
                iRet = INT_SIM_CREDIT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* sim_package */
	if (GetField_CString(hRequest, "sim_package", &csTmp)) {
DEBUGLOG(("Authorize() sim_package = [%s]\n", csTmp));
		PutField_CString(hContext,"sim_package",csTmp);
	} else {
DEBUGLOG(("Authorize:: sim package not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: sim package not found!!\n");
                iRet = INT_SIM_PACKAGE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* billed_date */
	if (GetField_CString(hRequest, "billed_date", &csTmp)) {
		iTmp = atoi(csTmp);
DEBUGLOG(("Authorize() billed_date = [%d]\n", iTmp));
		PutField_Int(hContext,"billed_date",iTmp);
	}

/* last_topup_date */
	if (GetField_CString(hRequest, "last_topup_date", &csTmp)) {
DEBUGLOG(("Authorize() last_topup_date = [%s]\n", csTmp));
		PutField_CString(hContext,"last_topup_date",csTmp);
	} else {
DEBUGLOG(("Authorize:: last topup date not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: mlast topup date not found!!\n");
                iRet = INT_LAST_TOPUP_DATE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* next_topup_date */
	if (GetField_CString(hRequest, "next_topup_date", &csTmp)) {
DEBUGLOG(("Authorize() next_topup_date = [%s]\n", csTmp));
		PutField_CString(hContext,"next_topup_date",csTmp);
	} else {
DEBUGLOG(("Authorize:: next topup date not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: next topup date not found!!\n");
                iRet = INT_NEXT_TOPUP_DATE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* expired_date */
	if (GetField_CString(hRequest, "expired_date", &csTmp)) {
DEBUGLOG(("Authorize() expired_date = [%s]\n", csTmp));
		PutField_CString(hContext, "expired_date",csTmp);
	} else {
DEBUGLOG(("Authorize:: expired date not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: expired date not found!!\n");
                iRet = INT_EXPIRED_DATE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* password */
	if (GetField_CString(hRequest, "password", &csTmp)) {
DEBUGLOG(("Authorize() password = [%s]\n", csTmp));
		PutField_CString(hContext,"password",csTmp);
	}

/* status */
	if (GetField_CString(hRequest, "status", &csTmp)) {
		cTmp = csTmp[0];
DEBUGLOG(("Authorize() status = [%c]\n", cTmp));
		PutField_Char(hContext,"status",cTmp);
	} else {
DEBUGLOG(("Authorize:: status not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: status not found!!\n");
                iRet = INT_STATUS_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* remark */
	if (GetField_CString(hRequest, "remark", &csTmp)) {
DEBUGLOG(("Authorize() remark = [%s]\n", csTmp));
                PutField_CString(hContext,"remark",csTmp);
        }

/* sim_nature */
	if (GetField_CString(hRequest, "sim_nature", &csTmp)) {
DEBUGLOG(("Authorize() sim_nature = [%s]\n", csTmp));
                PutField_CString(hContext,"sim_nature",csTmp);
        }

/* user */
        if (GetField_CString(hRequest, "add_user", &csTmp)) {
DEBUGLOG(("Authorize() user = [%s]\n", csTmp));
                PutField_CString(hContext,"create_user",csTmp);
                PutField_CString(hContext,"update_user",csTmp);
        } else {
                iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsSCU::Authorize() user NOT FOUND!!!\n");
        }

	if (iRet == PD_OK) {	
		if (cAction == PD_ACTION_ADD) {	
/* country */
                        if (GetField_CString(hRequest, "sim_country", &csTmp)) {
DEBUGLOG(("Authorize() country = [%s]\n", csTmp));
                                PutField_CString(hContext,"country",csTmp);
                        } else {
DEBUGLOG(("Authorize:: sim_country not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: sim_country not found!!\n");
				iRet = INT_SIM_COUNTRY_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
        		}

/* currency */
                        if (GetField_CString(hRequest, "sim_ccy", &csTmp)) {
DEBUGLOG(("Authorize() currency = [%s]\n", csTmp));
                                PutField_CString(hContext,"currency",csTmp);
                        } else {
DEBUGLOG(("Authorize:: currency not found!!\n"));
ERRLOG("TxnOmtByUsSCU:: Authorize:: currency not found!!\n");
                                iRet = INT_CURRENCY_CODE_NOT_FOUND;
                                PutField_Int(hContext,"internal_error",iRet);
                        }

DEBUGLOG(("Authorize() call DBOLSimCards::Add()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLSimCards", "Add");
			iRet = (unsigned long)(*DBObjPtr)(hContext);
			if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLSimCards::Add() FAILURE!!!\n"));
			}
		}
		else if (cAction == PD_ACTION_UPDATE) { 
DEBUGLOG(("Authorize() call DBOLSimCards::Update()\n"));
                        DBObjPtr = CreateObj(DBPtr, "DBOLSimCards", "Update");
                        iRet = (unsigned long)(*DBObjPtr)(hContext);
                        if (iRet != PD_OK) {
DEBUGLOG(("Authorize() call DBOLSimCards::Update() FAILURE!!!\n"));
			}
		}	
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	}

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}
