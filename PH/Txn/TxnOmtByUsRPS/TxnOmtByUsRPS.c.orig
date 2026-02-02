/*
PDProTech(c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/07/18              Ethan Yip
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRPS.h"
#include "myrecordset.h"

static char cDebug;
OBJPTR(DB);

void TxnOmtByUsRPS(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int     iRet = PD_OK;
	int 	iDBRet = INT_ERR;
        char    *csTmp;

DEBUGLOG(("Authorize() Begin\n"));

/* int_bank_code */
        if (GetField_CString(hRequest, "int_bank_code", &csTmp))
	{
DEBUGLOG(("int_bank_code = [%s]\n", csTmp));
                PutField_CString(hContext, "int_bank_code", csTmp);
        } 
	else 
	{
                iRet = INT_BANK_CODE_NOT_FOUND;
DEBUGLOG(("int_bank_code is missing!\n"));
ERRLOG("TxnOmtByUsRPS:: Authorize() int_bank_code is missing!\n");
	}

/* bank_acct_type */
        if (GetField_CString(hRequest, "bank_acct_type", &csTmp))
        {
DEBUGLOG(("bank_acct_type = [%s]\n", csTmp));                                                                                     
                PutField_CString(hContext, "bank_acct_type", csTmp);                                                   
	} 
        else                                                                                                  
	{
                iRet = INT_BANK_ACCT_TYPE_NOT_FOUND;                                                                            
DEBUGLOG(("bank_acct_type is missing!\n"));                                                                                       
ERRLOG("TxnOmtByUsRPS:: Authorize() bank_acct_type is missing!\n");
        }

/* recon_txn_code */
        if (GetField_CString(hRequest, "recon_txn_code", &csTmp))
        {
DEBUGLOG(("recon_txn_code = [%s]\n", csTmp));                                                                                     
                PutField_CString(hContext, "recon_txn_code", csTmp);                                                   
	} 
        else                                                                                                  
	{
                iRet = INT_TXN_CODE_NOT_FOUND;                                                                            
DEBUGLOG(("recon_txn_code is missing!\n"));                                                                                       
ERRLOG("TxnOmtByUsRPS:: Authorize() recon_txn_code is missing!\n");
        }

/* config_code */
        if (GetField_CString(hRequest, "config_code", &csTmp))
        {
DEBUGLOG(("config_code = [%s]\n", csTmp));                                                                                     
                PutField_CString(hContext, "config_code", csTmp);
	} 
        else                                                                                                  
	{
                iRet = INT_ENGINE_CONFIG_CODE_NOT_FOUND;
DEBUGLOG(("config_code is missing!\n"));
ERRLOG("TxnOmtByUsRPS:: Authorize() config_code is missing!\n");
        }

/* config_value */
        if (GetField_CString(hRequest, "config_value", &csTmp))
        {
DEBUGLOG(("config_value = [%s]\n", csTmp));                                                                                     
                PutField_CString(hContext, "config_value", csTmp);
	} 
        else                                                                                                  
	{
                iRet = INT_STMT_MATCH_CONFIG_VAL_NOT_FOUND;
DEBUGLOG(("config_value is missing!\n"));
ERRLOG("TxnOmtByUsRPS:: Authorize() config_value is missing!\n");
        }

/* user */
        if (GetField_CString(hRequest, "add_user", &csTmp))
	{
DEBUGLOG(("user = [%s]\n", csTmp));
                PutField_CString(hContext, "update_user", csTmp);
        } 
	else
	{
                PutField_CString(hContext, "update_user", PD_UPDATE_USER);
DEBUGLOG(("update_user is missing, assign to default user SYSTEM\n"));
        }

/* call DB OLStmtMatchConfig: Update */
	if (iRet == PD_OK) 
	{
DEBUGLOG(("call DBOLStmtMatchConfig::Update()\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLStmtMatchConfig", "Update");
		iDBRet = (unsigned long)((*DBObjPtr)(hContext));
                if (iDBRet != PD_OK) 
		{
			iRet = INT_ERR;
DEBUGLOG(("call DBOLStmtMatchConfig::Update() Failed\n"));
ERRLOG("TxnOmtByUsRPS:: Authorize::call DBOLStmtMatchConfig::Update Failed, iDBRet=%d\n", iDBRet);
                } 
		else 
		{
DEBUGLOG(("call DBOLStmtMatchConfig::Update() Success\n"));
                }
	}

        if (iRet != PD_OK)
	{
                PutField_Int(hContext, "internal_error", iRet);
        }

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;
}
