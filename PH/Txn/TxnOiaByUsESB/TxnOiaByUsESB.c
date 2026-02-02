/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/11/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaByUsESB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOiaByUsESB(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csBAID = NULL; 
	char    *csTmp = NULL;

	hash_t  *hBAIDBalDetails = NULL;
        hBAIDBalDetails = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBAIDBalDetails,0);

DEBUGLOG(("TxnOiaByUsESB::Authorize\n"));

/* baid */
	if (GetField_CString(hRequest, "baid", &csBAID)) {
DEBUGLOG(("Get Details of baid [%s]\n", csBAID));
	} else {
DEBUGLOG(("Get Details of baid not found!!\n"));
ERRLOG("TxnOiaByUsESB::Authorize::baid not found!!\n");
                iRet=INT_BANK_ACCT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

	// Get BAID Balance Details
	if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBaid","GetBAIDBalDetails");
                iRet = (unsigned long)(BOObjPtr)(csBAID,hBAIDBalDetails);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBaid::GetBAIDBalDetails Success!!\n"));

			// BAID
                       	PutField_CString(hResponse, "baid", csBAID);	

/* prov_id */
                   	if (GetField_CString(hBAIDBalDetails,"provider_id",&csTmp)) {
DEBUGLOG((" prov_id = [%s]\n", csTmp));
                            	PutField_CString(hResponse,"prov_id",csTmp);
                     	}

/* prov_name */
                 	if (GetField_CString(hBAIDBalDetails,"provider_name",&csTmp)) {
DEBUGLOG((" prov_name = [%s]\n", csTmp));
                               	PutField_CString(hResponse,"prov_name",csTmp);
                      	}

/* baid_status */
                    	if (GetField_CString(hBAIDBalDetails,"baid_status",&csTmp)) {
DEBUGLOG((" baid_status = [%s]\n", csTmp));
                             	PutField_CString(hResponse,"baid_status",csTmp);
                  	}
	
/* bank_nature */
                     	if (GetField_CString(hBAIDBalDetails,"bank_nature",&csTmp)) {
DEBUGLOG((" bank_nature = [%s]\n", csTmp));
                               	PutField_CString(hResponse,"bank_nature",csTmp);
                     	}

/* bank_name */
                    	if (GetField_CString(hBAIDBalDetails,"bank_name",&csTmp)) {
DEBUGLOG((" bank_name = [%s]\n", csTmp));
                             	PutField_CString(hResponse,"bank_name",csTmp);
                      	}

/* owner_name */
                    	if (GetField_CString(hBAIDBalDetails,"owner_name",&csTmp)) {
DEBUGLOG((" owner_name = [%s]\n", csTmp));
                            	PutField_CString(hResponse,"owner_name",csTmp);
                	}

/* branch_name */
                       	if (GetField_CString(hBAIDBalDetails,"branch_name",&csTmp)) {
DEBUGLOG((" branch_name = [%s]\n", csTmp));
                               	PutField_CString(hResponse,"branch_name",csTmp);
                       	}

/* acct_short_name */
                     	if (GetField_CString(hBAIDBalDetails,"bank_acct_short_name",&csTmp)) {
DEBUGLOG((" acct_short_name = [%s]\n", csTmp));
                              	PutField_CString(hResponse,"acct_short_name",csTmp);
                   	}

/* acct_num */
                     	if (GetField_CString(hBAIDBalDetails,"bank_acct_num",&csTmp)) {
DEBUGLOG((" acct_num = [%s]\n", csTmp));
                              	PutField_CString(hResponse,"acct_num",csTmp);
                      	}

/* acct_status */
                     	if (GetField_CString(hBAIDBalDetails,"bank_acct_status",&csTmp)) {
DEBUGLOG((" acct_status = [%s]\n", csTmp));
                            	PutField_CString(hResponse,"acct_status",csTmp);
                     	}

/* merchant_id */
                     	if (GetField_CString(hBAIDBalDetails,"merchant_id",&csTmp)) {
DEBUGLOG((" merchant_id = [%s]\n", csTmp));
                            	PutField_CString(hResponse,"merchant_id",csTmp);
                     	}

        	} else {
DEBUGLOG(("Call BOOLBaid::GetBAIDBalDetails Failure!!\n"));
ERRLOG("TxnOiaByUsESB::Authorize::Call BOOLBaid::GetBAIDBalDetails Failure!!\n");
			PutField_Int(hContext,"internal_error",iRet);
        	}
	}

	// Not Update TxnReqRef
	PutField_Int(hContext,"not_update_log",PD_TRUE);

	hash_destroy(hBAIDBalDetails);
        FREE_ME(hBAIDBalDetails);

DEBUGLOG(("TxnOiaByUsESB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

