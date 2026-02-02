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
#include "TxnOiaByUsLUA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define  MAXIMUM_BANK_ACCT_COUNT          5

static char cDebug;
OBJPTR(BO);

void TxnOiaByUsLUA(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int     iBankAcctCnt = 0;
	int     iMaxBankAcctCnt = 0;
	char    *csReqDatetime = NULL;
	char    *csBankCode = NULL;
	char    *csBankAcctNum = NULL;
	char    *csTmp = NULL;
	char    csTag[PD_TAG_LEN + 1];

	hash_t  *hBankAcctsDetails = NULL;
        recordset_t *rBankAcctsDetails;
        rBankAcctsDetails = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rBankAcctsDetails, 0);

DEBUGLOG(("Authorize()\n"));
	
/* req_dt */
        if (GetField_CString(hRequest, "req_dt", &csReqDatetime)) {
DEBUGLOG(("req_dt [%s]\n", csReqDatetime));
        } else {
DEBUGLOG(("req_dt not found!!\n"));
ERRLOG("TxnOiaByUsLUA::Authorize::req_dt not found!!\n");
                iRet=INT_REQ_DATETIME_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* bank_code */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest, "bank_code", &csBankCode)) {
DEBUGLOG(("bank_code [%s]\n", csBankCode));
        	} else {
DEBUGLOG(("bank_code not found!!\n"));
        	}
	}

/* acct_num */	
	if (iRet == PD_OK) {
                if (GetField_CString(hRequest, "acct_num", &csBankAcctNum)) {
DEBUGLOG(("acct_num [%s]\n", csBankAcctNum));
                } else {
DEBUGLOG(("acct_num not found!!\n"));
                }
	}

/* max_bank_acct_cnt */
        if (iRet == PD_OK) {
                if (GetField_Int(hContext,"max_bank_acct_cnt",&iMaxBankAcctCnt)) {
DEBUGLOG(("max_bank_acct_cnt [%d]\n",iMaxBankAcctCnt));
                } else {
			iMaxBankAcctCnt = MAXIMUM_BANK_ACCT_COUNT;
DEBUGLOG(("max_bank_acct_cnt [%d][default]\n",iMaxBankAcctCnt));
                }
        }

        // Get Bank Accts Details
        if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBankAccts","GetLastUpdBankAcctsDetails");
                iRet = (unsigned long)(BOObjPtr)(csReqDatetime,csBankCode,csBankAcctNum,iMaxBankAcctCnt,rBankAcctsDetails);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBankAccts::GetLastUpdBankAcctsDetails Success!!\n"));

			hBankAcctsDetails = RecordSet_GetFirst(rBankAcctsDetails);
                        while (hBankAcctsDetails) {
				iBankAcctCnt++;
				hBankAcctsDetails = RecordSet_GetNext(rBankAcctsDetails);
                        }

/* r_list */
                        if (iBankAcctCnt > iMaxBankAcctCnt) {
DEBUGLOG((" - record count > maximum record count!!\n"));
                                iRet=INT_FORMAT_ERR;
                                PutField_Int(hContext,"internal_error",iRet);
                        } else {
DEBUGLOG((" - record count = [%d]\n", iBankAcctCnt));
                                PutField_Int(hResponse,"r_list",iBankAcctCnt);
                        }
		
                } else {
DEBUGLOG(("Call BOOLBankAccts::GetLastUpdBankAcctsDetails Failure!!\n"));
ERRLOG("TxnOiaByUsLUA::Authorize::Call BOOLBankAccts::GetLastUpdBankAcctsDetails Failure!!\n");
                        PutField_Int(hContext,"internal_error",iRet);
                }
		
		// Put Response Field(s)
		if (iRet == PD_OK) {

			iBankAcctCnt = 0;

                        hBankAcctsDetails = RecordSet_GetFirst(rBankAcctsDetails);
               	        while (hBankAcctsDetails) {

/* prov_id */
                                if (GetField_CString(hBankAcctsDetails,"provider_id",&csTmp)) {
DEBUGLOG((" [%d] prov_id = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.prov_id", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* prov_name */
                                if (GetField_CString(hBankAcctsDetails,"provider_name",&csTmp)) {
DEBUGLOG((" [%d] prov_name = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.prov_name", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_code */
                                if (GetField_CString(hBankAcctsDetails,"int_bank_code",&csTmp)) {
DEBUGLOG((" [%d] bank_code = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_code", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_name */
                                if (GetField_CString(hBankAcctsDetails,"bank_name",&csTmp)) {
DEBUGLOG((" [%d] bank_name = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_name", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_num */
                                if (GetField_CString(hBankAcctsDetails,"bank_acct_num",&csTmp)) {
DEBUGLOG((" [%d] acct_num = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_num", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_status */
                                if (GetField_CString(hBankAcctsDetails,"bank_acct_status",&csTmp)) {
DEBUGLOG((" [%d] acct_status = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_status", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_nature */
                                if (GetField_CString(hBankAcctsDetails,"bank_acct_nature",&csTmp)) {
DEBUGLOG((" [%d] bank_nature = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_nature", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_abbrev */
                                if (GetField_CString(hBankAcctsDetails,"bank_abbrev_name",&csTmp)) {
DEBUGLOG((" [%d] bank_abbrev = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_abbrev", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* acct_short_name */
                                if (GetField_CString(hBankAcctsDetails,"bank_acct_short_name",&csTmp)) {
DEBUGLOG((" [%d] acct_short_name = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.acct_short_name", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* owner_name */
                                if (GetField_CString(hBankAcctsDetails,"owner_name",&csTmp)) {
DEBUGLOG((" [%d] owner_name = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.owner_name", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* province */
                                if (GetField_CString(hBankAcctsDetails,"province",&csTmp)) {
DEBUGLOG((" [%d] province = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.province", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* city */
                                if (GetField_CString(hBankAcctsDetails,"city",&csTmp)) {
DEBUGLOG((" [%d] city = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.city", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* branch_name */
                                if (GetField_CString(hBankAcctsDetails,"branch_name",&csTmp)) {
DEBUGLOG((" [%d] branch_name = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.branch_name", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* reg_mob_no */
                                if (GetField_CString(hBankAcctsDetails,"reg_mob_num",&csTmp)) {
DEBUGLOG((" [%d] reg_mob_no = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.reg_mob_no", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* bank_upd_ts */
                                if (GetField_CString(hBankAcctsDetails,"bank_upd_ts",&csTmp)) {
DEBUGLOG((" [%d] bank_upd_ts = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.bank_upd_ts", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* baid */
                                if (GetField_CString(hBankAcctsDetails,"baid",&csTmp)) {
DEBUGLOG((" [%d] baid = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.baid", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* baid_status */
                                if (GetField_CString(hBankAcctsDetails,"baid_status",&csTmp)) {
DEBUGLOG((" [%d] baid_status = [%s]\n", iBankAcctCnt, csTmp));
					sprintf(csTag, "r_list.%d.baid_status", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* pid_nature */
                                if (GetField_CString(hBankAcctsDetails,"pid_bank_nature",&csTmp)) {
DEBUGLOG((" [%d] pid_nature = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.pid_nature", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* baid_upd_ts */
                                if (GetField_CString(hBankAcctsDetails,"baid_upd_ts",&csTmp)) {
DEBUGLOG((" [%d] baid_upd_ts = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.baid_upd_ts", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* merchant_id */
                                if (GetField_CString(hBankAcctsDetails,"merchant_id",&csTmp)) {
DEBUGLOG((" [%d] merchant_id = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.merchant_id", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* rec_end_ind */
                                if (GetField_CString(hBankAcctsDetails,"rec_end_ind",&csTmp)) {
DEBUGLOG((" [%d] rec_end_ind = [%s]\n", iBankAcctCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.rec_end_ind", iBankAcctCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

                                iBankAcctCnt++;

                                hBankAcctsDetails = RecordSet_GetNext(rBankAcctsDetails);
			}
            	}
	}

	// Not Update TxnReqRef
        PutField_Int(hContext,"not_update_log",PD_TRUE);

	RecordSet_Destroy(rBankAcctsDetails);
        FREE_ME(rBankAcctsDetails);

DEBUGLOG(("Authorize() iRet = [%d]\n",iRet));
	return iRet;
}

