/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/23              David Wong
Add client_sett_bank_id				   2014/11/17		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMCF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOmtByUsMCF(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		const hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csTmp = NULL;
	int iTmp;
	double dTmp;
	char cAction;

	char	*csSettCcy = NULL;

	char	*csMid = NULL;
	char	*csService = NULL;
	char	*csCountry = NULL;
	char	*csCcy = NULL;
	char	*csUser = NULL;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	hash_t  *hTxnGet;
        hTxnGet = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("TxnOmtByUsMCF:: Authorize\n"));

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize:: action = [%c]\n", cAction));
		// not support delete
		if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize:: action [%d] not accepted\n", cAction));
ERRLOG("TxnOmtByUsMCF:: Authorize:: action not accepted\n");
			iRet = INT_ACTION_NOT_FOUND;
		}
	} else {
DEBUGLOG(("Authorize:: action not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: action not found\n");
		iRet = INT_ACTION_NOT_FOUND;
	}

/* mid */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "merchant_id", &csMid)) {
DEBUGLOG(("Authorize:: merchant_id = [%s]\n", csMid));
			PutField_CString(hTxn, "merchant_id", csMid);
		} else {
DEBUGLOG(("Authorize:: merchant_id not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: merchant_id not found\n");
			iRet = INT_MERCHANT_ID_NOT_FOUND;
		}
	}

/* ccy */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "txn_ccy", &csCcy)) {
DEBUGLOG(("Authorize:: txn_ccy = [%s]\n", csCcy));
			PutField_CString(hTxn, "currency_id", csCcy);
		} else {
DEBUGLOG(("Authorize:: txn_ccy not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: txn_ccy not found\n");
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
		}
	}

/* country */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "txn_country", &csCountry)) {
DEBUGLOG(("Authorize:: txn_country = [%s]\n", csCountry));
			PutField_CString(hTxn, "country_id", csCountry);
		} else {
DEBUGLOG(("Authorize:: txn_country not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: txn_country not found\n");
			iRet = INT_TXN_COUNTRY_NOT_FOUND;
		}
	}

/* service */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "service_code", &csService)) {
DEBUGLOG(("Authorize:: service_code = [%s]\n", csService));
			PutField_CString(hTxn, "service_code", csService);
		} else {
DEBUGLOG(("Authorize:: service_code not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: service_code not found\n");
			iRet = INT_SERVICE_CODE_MISSING;
		}
	}

/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
			PutField_CString(hTxn, "create_user", csUser);
			PutField_CString(hTxn, "update_user", csUser);
		}
	}

/* fifo */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "fifo", &csTmp)) {
			iTmp = atoi(csTmp);
DEBUGLOG(("Authorize:: fifo = [%d]\n", iTmp));
			PutField_Int(hTxn, "match_fifo", iTmp);
		} else {
			if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: fifo not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: fifo not found\n");
				iRet = INT_ERR;
			}
		}
	}

/* fifo_amt */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "fifo_amt", &csTmp)) {
			dTmp = atof(csTmp);
DEBUGLOG(("Authorize:: fifo_amt = [%f]\n", dTmp));
			PutField_Double(hTxn, "match_fifo_amt_limit", dTmp);
		} else {
			if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: fifo_amt not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: fifo_amt not found\n");
				iRet = INT_ERR;
			}
		}
	}

/* sett_ccy */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "sett_ccy", &csSettCcy)) {
DEBUGLOG(("Authorize:: sett_ccy = [%s]\n", csSettCcy));
			PutField_CString(hTxn, "preferred_settle_ccy", csSettCcy);
		} else {
			if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: sett_ccy not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: sett_ccy not found\n");
				iRet = INT_ERR;
			}
		}
	}

/* min_settle_amt */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "min_settle_amt", &csTmp)) {
			dTmp = atof(csTmp);
DEBUGLOG(("Authorize:: min_settle_amt = [%f]\n", dTmp));
			PutField_Double(hTxn, "min_settle_amt", dTmp);
		} else {
			if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: min_settle_amt not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: min_settle_amt not found\n");
				iRet = INT_ERR;
			}
		}
	}

/* apply_to_admin */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "apply_to_admin", &csTmp)) {
			iTmp = atoi(csTmp);
DEBUGLOG(("Authorize:: apply_to_admin = [%d]\n", iTmp));
			PutField_Int(hTxn, "min_settle_amt_apply_admin", iTmp);
		} else {
			if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: apply_to_admin not found\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: apply_to_admin not found\n");
				iRet = INT_ERR;
			}
		}
	}

/* settlement ACR pool */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "acr", &csTmp)) {
DEBUGLOG(("Authorize:: preferred_acr_pool = [%s]\n", csTmp));
			PutField_CString(hTxn, "preferred_acr_pool", csTmp);
		} 
		else{
			PutField_CString(hTxn, "preferred_acr_pool", PD_CCY_UNKNOWN);
		}
	}

/* max_auto_cb_amt */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "max_auto_cb_amt", &csTmp)) {
			dTmp = atof(csTmp);
			PutField_Double(hTxn, "max_auto_cb_amt", dTmp);
DEBUGLOG(("Authorize:: max_auto_cb_amt = [%.2lf]\n", dTmp));
		} else {
			if (cAction == PD_ACTION_ADD) {
				iTmp = 0.0;
				PutField_Double(hTxn, "max_auto_cb_amt", dTmp);
DEBUGLOG(("Authorize:: max_auto_cb_amt (default) = [%.2lf]\n", dTmp));
			}
		}
	}

/* client_sett_bank_id */
	if (iRet == PD_OK) {
		hash_init(hTxnGet, 0);

                if (GetField_CString(hRequest, "client_sett_bank_id", &csTmp)) {
                        iTmp = atoi(csTmp);
DEBUGLOG(("Authorize:: client_sett_bank_id = [%d]\n", iTmp));
                        PutField_Int(hTxn, "client_sett_bank_id", iTmp);

DEBUGLOG(("Authorize:: Call DBClientSettBank: Get\n"));
                      	DBObjPtr = CreateObj(DBPtr,"DBClientSettBank","GetClientSettBank");
                    	if ((unsigned long)((*DBObjPtr)(iTmp,hTxnGet)) == PD_FOUND){
DEBUGLOG(("Authorize:: client_sett_bank_id found!!!\n"));

				if(GetField_CString(hTxnGet,"bank_ac_ccy",&csTmp)){
DEBUGLOG(("Authorize:: bank_ac_ccy = [%s]\n",csTmp));
					
					if (!strcmp(csSettCcy, csTmp)) {
DEBUGLOG(("Authorize:: currency id match!!!\n"));

                        		} else {
						iRet = INT_CURRENCY_ID_NOT_MATCH;
DEBUGLOG(("Authorize:: currency id not match!!!\n"));
ERRLOG("TxnOmtByUsMCF:: currency id not match!!!\n");

                        		}

                                }

			} else {
                     		iRet = INT_INVALID_BANK_ID;
DEBUGLOG(("Authorize:: Invalid client_sett_bank_id [%d] [%d]\n",iRet,iTmp));
ERRLOG("TxnOmtByUsMCF:: Authorize:: Invalid client_sett_bank_id [%d] [%d]\n",iRet,iTmp);
                    	}

                } else {
			if (cAction == PD_ACTION_UPDATE) {
                       		iTmp = -1;
DEBUGLOG(("Authorize:: client_sett_bank_id = [%d]\n", iTmp));
                          	PutField_Int(hTxn, "client_sett_bank_id", iTmp);
                     	}
                }
		hash_destroy(hTxnGet);
        }

/* OLMerchConfig */
	if (iRet == PD_OK) {
		if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize:: Call DBOLMerchConfig: Add\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLMerchConfig", "Add");
			if ((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)) {
DEBUGLOG(("Authorize:: DBOLMerchConfig: Add failed\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: DBOLMerchConfig: Add failed\n");
				iRet = INT_ERR;
			} else {
DEBUGLOG(("Authorize:: DBOLMerchConfig: Add success\n"));
			}

			if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLMerchantBalance:Add\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","Add");
				if((unsigned long)((*DBObjPtr)(csMid,csCountry,csCcy,csService,csUser) != PD_OK)){
DEBUGLOG(("Authorize:: DBOLMerchantBalance:Add Failed\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize::DBOLMerchantBalance:Add Failed\n");
					iRet = INT_ERR;
				}
			}

		} else if (cAction == PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize:: Call DBOLMerchConfig: Update\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLMerchConfig", "Update");
			if ((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)) {
DEBUGLOG(("Authorize:: DBOLMerchConfig: Update failed\n"));
ERRLOG("TxnOmtByUsMCF:: Authorize:: DBOLMerchConfig: Update failed\n");
				iRet = INT_ERR;
			} else {
DEBUGLOG(("Authorize:: DBOLMerchConfig: Update success\n"));
			}
		}
	}

	if (iRet != PD_OK) {
		PutField_Int(hContext, "internal_error", iRet);
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	FREE_ME(hTxnGet);

DEBUGLOG(("TxnOmtByUsMCF Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
