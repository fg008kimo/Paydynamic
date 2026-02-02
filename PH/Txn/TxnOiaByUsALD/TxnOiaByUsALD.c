/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/22              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaByUsALD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(BO);

void TxnOiaByUsALD(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csBankCode = NULL; 
	char	*csBankAcctNum = NULL; 
	char    *csTmp = NULL;

	hash_t  *hBankAcctDetails = NULL;
        hBankAcctDetails = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBankAcctDetails,0);

DEBUGLOG(("Authorize()\n"));

/* bank_code */
	if (GetField_CString(hRequest, "bank_code", &csBankCode)) {
DEBUGLOG(("bank_code [%s]\n", csBankCode));
	} else {
DEBUGLOG(("bank_code not found!!\n"));
ERRLOG("TxnOiaByUsALD::Authorize::bank_code not found!!\n");
                iRet=INT_BANK_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* acct_num */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "acct_num", &csBankAcctNum)) {
DEBUGLOG(("acct_num [%s]\n", csBankAcctNum));
        	} else {
DEBUGLOG(("acct_num not found!!\n"));
ERRLOG("TxnOiaByUsALD::Authorize::acct_num not found!!\n");
        	        iRet=INT_BANK_ACCT_NOT_FOUND;
        	        PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Get Bank Acct Details
	if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBankAccts","GetBankAcctLatestDetails");
                iRet = (unsigned long)(BOObjPtr)(csBankCode,csBankAcctNum,hBankAcctDetails);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBankAccts::GetBankAcctLatestDetails Success!!\n"));

			// bank_code
                       	PutField_CString(hResponse, "bank_code", csBankCode);	
DEBUGLOG((" - bank_code = [%s]\n", csBankCode));

			// acct_num
			PutField_CString(hResponse, "acct_num", csBankAcctNum);
DEBUGLOG((" - acct_num = [%s]\n", csBankAcctNum));

/* prov_id */
                        if (GetField_CString(hBankAcctDetails,"provider_id",&csTmp)) {
DEBUGLOG((" - prov_id = [%s]\n", csTmp));
                                PutField_CString(hResponse,"prov_id",csTmp);
                        }

/* prov_name */
                        if (GetField_CString(hBankAcctDetails,"provider_name",&csTmp)) {
DEBUGLOG((" - prov_name = [%s]\n", csTmp));
                                PutField_CString(hResponse,"prov_name",csTmp);
                        }

/* bank_name */
                        if (GetField_CString(hBankAcctDetails,"bank_name",&csTmp)) {
DEBUGLOG((" - bank_name = [%s]\n", csTmp));
                                PutField_CString(hResponse,"bank_name",csTmp);
                        }

/* acct_status */
                        if (GetField_CString(hBankAcctDetails,"bank_acct_status",&csTmp)) {
DEBUGLOG((" - acct_status = [%s]\n", csTmp));
                                PutField_CString(hResponse,"acct_status",csTmp);
                        }

/* bank_nature */
                        if (GetField_CString(hBankAcctDetails,"bank_acct_nature",&csTmp)) {
DEBUGLOG((" - bank_nature = [%s]\n", csTmp));
                                PutField_CString(hResponse,"bank_nature",csTmp);
                        }

/* bank_abbrev */
                        if (GetField_CString(hBankAcctDetails,"bank_abbrev_name",&csTmp)) {
DEBUGLOG((" - bank_abbrev = [%s]\n", csTmp));
                                PutField_CString(hResponse,"bank_abbrev",csTmp);
                        }

/* acct_short_name */
                        if (GetField_CString(hBankAcctDetails,"bank_acct_short_name",&csTmp)) {
DEBUGLOG((" - acct_short_name = [%s]\n", csTmp));
                                PutField_CString(hResponse,"acct_short_name",csTmp);
                        }

/* owner_name */
                        if (GetField_CString(hBankAcctDetails,"owner_name",&csTmp)) {
DEBUGLOG((" - owner_name = [%s]\n", csTmp));
                                PutField_CString(hResponse,"owner_name",csTmp);
                        }

/* province */
                        if (GetField_CString(hBankAcctDetails,"province",&csTmp)) {
DEBUGLOG((" - province = [%s]\n", csTmp));
                                PutField_CString(hResponse,"province",csTmp);
                        }

/* city */
                        if (GetField_CString(hBankAcctDetails,"city",&csTmp)) {
DEBUGLOG((" - city = [%s]\n", csTmp));
                                PutField_CString(hResponse,"city",csTmp);
                        }

/* branch_name */
                        if (GetField_CString(hBankAcctDetails,"branch_name",&csTmp)) {
DEBUGLOG((" - branch_name = [%s]\n", csTmp));
                                PutField_CString(hResponse,"branch_name",csTmp);
                        }

/* reg_mob_no */
                        if (GetField_CString(hBankAcctDetails,"reg_mob_num",&csTmp)) {
DEBUGLOG((" - reg_mob_no = [%s]\n", csTmp));
                                PutField_CString(hResponse,"reg_mob_no",csTmp);
                        }

/* baid */
                 	if (GetField_CString(hBankAcctDetails,"baid",&csTmp)) {
DEBUGLOG((" - baid = [%s]\n", csTmp));
                               	PutField_CString(hResponse,"baid",csTmp);
                      	}

/* baid_status */
                    	if (GetField_CString(hBankAcctDetails,"baid_status",&csTmp)) {
DEBUGLOG((" - baid_status = [%s]\n", csTmp));
                             	PutField_CString(hResponse,"baid_status",csTmp);
                  	}
	
/* pid_nature */
                        if (GetField_CString(hBankAcctDetails,"pid_bank_nature",&csTmp)) {
DEBUGLOG((" - pid_nature = [%s]\n", csTmp));
                                PutField_CString(hResponse,"pid_nature",csTmp);
                        }

/* merchant_id */
                     	if (GetField_CString(hBankAcctDetails,"merchant_id",&csTmp)) {
DEBUGLOG((" - merchant_id = [%s]\n", csTmp));
                            	PutField_CString(hResponse,"merchant_id",csTmp);
                     	}

        	} else {
DEBUGLOG(("Call BOOLBankAccts::GetBankAcctLatestDetails Failure!!\n"));
ERRLOG("TxnOiaByUsALD::Authorize::Call BOOLBankAccts::GetBankAcctLatestDetails Failure!!\n");
			PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Not Update TxnReqRef
	PutField_Int(hContext,"not_update_log",PD_TRUE);

	hash_destroy(hBankAcctDetails);
        FREE_ME(hBankAcctDetails);

DEBUGLOG(("Authorize() iRet = [%d]\n",iRet));
	return iRet;
}

