/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/10              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMBA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOmtByUsMBA(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;

	char	*csTmp = NULL;	
	char	*csMid = NULL;
	char	*csService = NULL;
	char	*csBankCode = NULL;
	char	*csAcctNum = NULL;
	char    csCountry[PD_COUNTRY_LEN+1];
	char	*csCcy = NULL;
	char	*csUser = NULL;

	char	*csStatus = NULL;
	char	*csRecMid = NULL;
	char	*csRecStatus = NULL;

	char	cAction;
	int	iShareAcct = PD_FALSE;

        hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

        hash_t  *hAcctInfo;
        hAcctInfo = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hAcctInfo, 0);

	hash_t  *hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("TxnOmtByUsMBA::Authorize\n"));

/* mid */
        if (GetField_CString(hRequest, "merchant_id", &csMid)){
		PutField_CString(hTxn, "merchant_id", csMid);
DEBUGLOG(("Authorize::merchant_id = [%s]\n", csMid));
	}
	else {
DEBUGLOG(("Authorize::merchant_Id not found\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::merchant_id not found\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));

		// not support delete
		if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::action [%d] not accepted!!\n", cAction));
ERRLOG("TxnOmtByUsMBA::Authorize::action not found!!\n");
	                iRet=INT_ACTION_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
	else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::action not found!!\n");
                iRet=INT_ACTION_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* bank_code */
	if (GetField_CString(hRequest, "int_bank_code", &csBankCode)) {
DEBUGLOG(("Authorize::() int_bank_code = [%s]\n",csBankCode));
		PutField_CString(hTxn, "int_bank_code", csBankCode);
	} 
	else {
DEBUGLOG(("Authorize::bank_code not found\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::bank_code not found\n");
		iRet = INT_BANK_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* acct_num */
	if (GetField_CString(hRequest, "bank_acct_num", &csAcctNum)) {
DEBUGLOG(("Authorize::() bank_acct_num = [%s]\n",csAcctNum));
		PutField_CString(hTxn, "bank_acct_num", csAcctNum);
	} 
	else {
DEBUGLOG(("Authorize::acct_num not found\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::acct_num not found\n");
		iRet = INT_BANK_AC_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* service */
	if (GetField_CString(hRequest, "service_code", &csService)) {
DEBUGLOG(("Authorize::() service_code = [%s]\n", csService));
		PutField_CString(hTxn, "service_code", csService);
	} 
	else {
DEBUGLOG(("Authorize::service_code not found\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::service_code not found\n");
		iRet = INT_SERVICE_CODE_MISSING;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* status */
	if (GetField_CString(hRequest,"status", &csStatus)){
DEBUGLOG(("Authorize::() status = [%s]\n",csStatus));
		PutField_CString(hTxn, "status", csStatus);
	}
	else{
		if(cAction == PD_ACTION_ADD){
			PutField_CString(hTxn, "status",PD_ACC_OPEN);
DEBUGLOG(("Authorize::status(default) = [%s]\n",PD_ACC_OPEN));
		}
	}

/* txn_type */
	if (GetField_CString(hRequest, "txn_type", &csTmp)) {
DEBUGLOG(("Authorize::() txn_type = [%s]\n",csTmp));
		PutField_Char(hTxn, "txn_type", csTmp[0]);
	}


/* add_user */
	if(GetField_CString(hRequest,"add_user",&csUser)) {
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hTxn,"create_user",csUser);
		PutField_CString(hTxn, "update_user", csUser);
	}


/* need to check shared acct for Add and Update */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLBankAccts:GetBankAccts\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
		if((unsigned long)((*DBObjPtr)(csBankCode,csAcctNum,hAcctInfo) != PD_OK)){
DEBUGLOG(("Authorize::DBOLBankAccts:GetBankAccts Failed\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::DBOLBankAccts:GetBankAccts Failed\n");
			iRet = INT_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
		}
		else {
DEBUGLOG(("Authorize::DBOLBankAccts:GetBankAccts Succ\n"));
			if(GetField_CString(hAcctInfo,"acct_ccy",&csCcy)){
DEBUGLOG(("Authorize::() acct_ccy = [%s]\n",csCcy));
			}

			if(GetField_Int(hAcctInfo,"shared_acct", &iShareAcct)){
DEBUGLOG(("Authorize::() shared_acct = [%d]\n",iShareAcct));
			}
		}
	}

	if (iRet == PD_OK &&  cAction == PD_ACTION_ADD) {
/* disabled */	
		PutField_Int(hTxn, "disabled", PD_FALSE);

		//found ccy and country by bank acct
		if(iRet==PD_OK && !iShareAcct){
			recordset_init(rRecordSet,0);

			//if bank acct using by another merchant, check bank acct is share or not
DEBUGLOG(("Authorize::Call DBOLMerchantBankAcct:FindDetailByBankAcct\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBankAcct","FindDetailByBankAcct");
			if((unsigned long)((*DBObjPtr)(csBankCode,csAcctNum,rRecordSet) == PD_OK)){
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"status",&csTmp)){
						if(!strcmp(PD_ACC_OPEN,csTmp)){
							iRet = INT_BANK_ACCT_DUPLICATE;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::FindDetailByBankAcct Bank Account FOUND! Cannot share\n"));
ERRLOG("Authorize::FindDetailByBankAcct Bank Account FOUND! Cannot share\n");
						}
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			RecordSet_Destroy(rRecordSet);	
		}	

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBBankDesc:GetBankCountry\n"));
			DBObjPtr = CreateObj(DBPtr,"DBBankDesc","GetBankCountry");
			if((unsigned long)(DBObjPtr)(csBankCode,csCountry) != PD_FOUND){
DEBUGLOG(("Authorize::DBBankDesc:GetBankCountry Failed\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::DBBankDesc:GetBankCountry Failed\n");
				iRet = INT_ERR;
                		PutField_Int(hContext,"internal_error",iRet);
			}
			else {
DEBUGLOG(("Authorize::DBBankDesc:GetBankCountry Succ\n"));
DEBUGLOG(("Authorize::() acct_country = [%s]\n",csCountry));
			}

		}

		/* Merchant Bal Acct*/
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLMerchantBankAcct:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBankAcct","Add");
			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:Add Failed\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::DBOLMerchantBankAcct:Add Failed\n");
				iRet = INT_ERR;
			}
			else {
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:Add Succ\n"));
			}
		}

		//Merchant Balance 
		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLMerchantBalance:Add\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","Add");
			if((unsigned long)((*DBObjPtr)(csMid,csCountry,csCcy,csService,csUser) != PD_OK)){
DEBUGLOG(("Authorize::DBOLMerchantBalance:Add Failed\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::DBOLMerchantBalance:Add Failed\n");
				iRet = INT_ERR;
			}
			else {
DEBUGLOG(("Authorize::DBOLMerchantBalance:Add Succ\n"));
			}
		}

	}
	else if (iRet == PD_OK && cAction == PD_ACTION_UPDATE) {

/* check Share Acct whether active in another MID */
		if(iRet==PD_OK && !iShareAcct){

			if (!strcmp(csStatus, PD_ACC_OPEN)) {
				recordset_init(rRecordSet,0);

				//if bank acct using by another merchant, check bank acct is share or not
DEBUGLOG(("Authorize::Call DBOLMerchantBankAcct:FindDetailByBankAcct\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBankAcct","FindDetailByBankAcct");
				if((unsigned long)((*DBObjPtr)(csBankCode,csAcctNum,rRecordSet) == PD_OK)){
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec) {

						if (GetField_CString(hRec, "merchant_id", &csRecMid)) {
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:FindDetailByBankAcct: merchant_id [%s]\n", csRecMid));
						}
	
						if (GetField_CString(hRec, "status", &csRecStatus)) {
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:FindDetailByBankAcct: status [%s]\n", csRecStatus));
						}

						// Diff MID and Open Status
						if (strcmp(csRecMid, csMid) && !strcmp(csRecStatus, PD_ACC_OPEN)) {
							iRet = INT_INVALID_MERCH_ID;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::FindDetailByBankAcct Another Merchant Account FOUND! Cannot share\n"));
ERRLOG("Authorize::FindDetailByBankAcct Another Merchant Account FOUND! Cannot share\n");
						}

						hRec = RecordSet_GetNext(rRecordSet);
					}
				}
				RecordSet_Destroy(rRecordSet);
			}
		}


		if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLMerchantBankAcct:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBankAcct","Update");
			if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:Update Failed\n"));
ERRLOG("TxnOmtByUsMBA::Authorize::DBOLMerchantBankAcct:Update Failed\n");
				iRet = INT_ERR;
			}
			else {
DEBUGLOG(("Authorize::DBOLMerchantBankAcct:Update Succ\n"));
			}
		}
	}

/*			
	if (iRet != PD_OK) {
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


        hash_destroy(hTxn);
        FREE_ME(hTxn);
        hash_destroy(hAcctInfo);
	FREE_ME(hAcctInfo);

	FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsMBA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

