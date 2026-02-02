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
#include "TxnOiaByUsENB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define  MAXIMUM_BAID_COUNT          8

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOiaByUsENB(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int     iBAIDCnt = 0;
	int     iMaxBAIDCnt = 0;
	char    *csBAID = NULL;
	char    *csTmp = NULL;
	char    csTag[PD_TAG_LEN + 1];

	hash_t  *hNewBAIDDetails = NULL;
        recordset_t *rNewBAIDDetails;
        rNewBAIDDetails = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rNewBAIDDetails, 0);

DEBUGLOG(("TxnOiaByUsENB::Authorize\n"));
	
/* baid */
        if (GetField_CString(hRequest, "baid", &csBAID)) {
DEBUGLOG(("Get baid [%s]\n", csBAID));
                //PutField_CString(hResponse, "baid", csBAID);
        } else {
DEBUGLOG(("Get baid not found!!\n"));
ERRLOG("TxnOiaByUsENB::Authorize::baid not found!!\n");
                iRet=INT_BANK_ACCT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* max_baid_cnt */
        if (iRet == PD_OK) {
                if (GetField_Int(hContext,"max_baid_cnt",&iMaxBAIDCnt)) {
DEBUGLOG(("Get max_baid_cnt [%d]\n",iMaxBAIDCnt));
                } else {
			iMaxBAIDCnt = MAXIMUM_BAID_COUNT;
DEBUGLOG(("Get max_baid_cnt [%d][default]\n",iMaxBAIDCnt));
                }
        }

        // Get New BAID Details
        if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBaid","GetNewBAIDDetails");
                iRet = (unsigned long)(BOObjPtr)(csBAID,iMaxBAIDCnt,rNewBAIDDetails);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBaid::GetNewBAIDDetails Success!!\n"));

                        hNewBAIDDetails = RecordSet_GetFirst(rNewBAIDDetails);
               	        while (hNewBAIDDetails) {

/* baid */
                                if (GetField_CString(hNewBAIDDetails,"baid",&csTmp)) {
DEBUGLOG(("[%d] baid = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.baid", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* prov_id */
                                if (GetField_CString(hNewBAIDDetails,"provider_id",&csTmp)) {
DEBUGLOG(("[%d] prov_id = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.prov_id", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* prov_name */
                                if (GetField_CString(hNewBAIDDetails,"provider_name",&csTmp)) {
DEBUGLOG(("[%d] prov_name = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.prov_name", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* baid_status */
                                if (GetField_CString(hNewBAIDDetails,"baid_status",&csTmp)) {
DEBUGLOG(("[%d] baid_status = [%s]\n", iBAIDCnt, csTmp));
					sprintf(csTag, "r_list.%d.baid_status", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* pid_nature */
                                if (GetField_CString(hNewBAIDDetails,"pid_bank_nature",&csTmp)) {
DEBUGLOG(("[%d] pid_nature = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.pid_nature", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_nature */
                                if (GetField_CString(hNewBAIDDetails,"bank_nature",&csTmp)) {
DEBUGLOG(("[%d] bank_nature = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_nature", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_name */
                                if (GetField_CString(hNewBAIDDetails,"bank_name",&csTmp)) {
DEBUGLOG(("[%d] bank_name = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_name", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* owner_name */
                                if (GetField_CString(hNewBAIDDetails,"owner_name",&csTmp)) {
DEBUGLOG(("[%d] owner_name = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.owner_name", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* branch_name */
                                if (GetField_CString(hNewBAIDDetails,"branch_name",&csTmp)) {
DEBUGLOG(("[%d] branch_name = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.branch_name", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_num */
                                if (GetField_CString(hNewBAIDDetails,"bank_acct_num",&csTmp)) {
DEBUGLOG(("[%d] acct_num = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_num", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_short_name */
                                if (GetField_CString(hNewBAIDDetails,"bank_acct_short_name",&csTmp)) {
DEBUGLOG(("[%d] acct_short_name = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_short_name", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_status */
                                if (GetField_CString(hNewBAIDDetails,"bank_acct_status",&csTmp)) {
DEBUGLOG(("[%d] acct_status = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_status", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* merchant_id */
                                if (GetField_CString(hNewBAIDDetails,"merchant_id",&csTmp)) {
DEBUGLOG(("[%d] merchant_id = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.merchant_id", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* rec_end_ind */
                                if (GetField_CString(hNewBAIDDetails,"rec_end_ind",&csTmp)) {
DEBUGLOG(("[%d] rec_end_ind = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.rec_end_ind", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

                                iBAIDCnt++;

                                hNewBAIDDetails = RecordSet_GetNext(rNewBAIDDetails);
			}

/* r_list */
                        if (iBAIDCnt > iMaxBAIDCnt) {
DEBUGLOG(("baid count > maximum baid count!!\n"));
                                iRet=INT_FORMAT_ERR;
                                PutField_Int(hContext,"internal_error",iRet);
                        } else {
DEBUGLOG(("baid count = [%d]\n", iBAIDCnt));
                                PutField_Int(hResponse,"r_list",iBAIDCnt);
                        }

           	} else {
DEBUGLOG(("Call BOOLBaid::GetNewBAIDDetails Failure!!\n"));
ERRLOG("TxnOiaByUsENB::Authorize::Call BOOLBaid::GetNewBAIDDetails Failure!!\n");
                     	PutField_Int(hContext,"internal_error",iRet);
            	}
	}

	// Not Update TxnReqRef
        PutField_Int(hContext,"not_update_log",PD_TRUE);

	RecordSet_Destroy(rNewBAIDDetails);
        FREE_ME(rNewBAIDDetails);

DEBUGLOG(("TxnOiaByUsENB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

