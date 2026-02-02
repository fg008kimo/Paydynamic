/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/01/10              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaByUsLST.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define  MAXIMUM_BAID_COUNT          40

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnOiaByUsLST(char    cdebug)
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
        char    *csRecDate = NULL;
	char    *csTmp = NULL;
	char    csTag[PD_TAG_LEN + 1];

	hash_t  *hLastSMSCreateDT = NULL;
        recordset_t *rLastSMSCreateDT;
        rLastSMSCreateDT = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rLastSMSCreateDT, 0);

DEBUGLOG(("TxnOiaByUsLST::Authorize\n"));
	
/* baid */
        if (GetField_CString(hRequest, "baid", &csBAID)) {
DEBUGLOG(("Get baid [%s]\n", csBAID));
                //PutField_CString(hResponse, "baid", csBAID);
        } else {
DEBUGLOG(("Get baid not found!!\n"));
ERRLOG("TxnOiaByUsLST::Authorize::baid not found!!\n");
                iRet=INT_BANK_ACCT_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* rec_date */
	if (iRet == PD_OK) {
       		if (GetField_CString(hRequest,"rec_date",&csRecDate)) {
DEBUGLOG(("Get rec_date [%s]\n",csRecDate));
        	} else {
DEBUGLOG(("Get rec_date not found!!\n"));
ERRLOG("TxnOiaByUsLST::Authorize::rec_date not found!!\n");
                	iRet=INT_SMS_CREATE_DATE_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
        	}
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

        // Get Last SMS Creation Time
        if (iRet == PD_OK) {

		BOObjPtr = CreateObj(BOPtr,"BOOLBaid","GetLastSMSCreationTime");
                iRet = (unsigned long)(BOObjPtr)(csBAID,csRecDate,iMaxBAIDCnt,rLastSMSCreateDT);
                if (iRet == PD_OK) {
DEBUGLOG(("Call BOOLBaid::GetLastSMSCreationTime Success!!\n"));

                        hLastSMSCreateDT = RecordSet_GetFirst(rLastSMSCreateDT);
               	        while (hLastSMSCreateDT) {

/* baid */
                                if (GetField_CString(hLastSMSCreateDT,"baid",&csTmp)) {
DEBUGLOG(("[%d] baid = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.baid", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* create_dt */
                                if (GetField_CString(hLastSMSCreateDT,"create_dt",&csTmp)) {
DEBUGLOG(("[%d] create_dt = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.create_dt", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

/* rec_end_ind */
                                if (GetField_CString(hLastSMSCreateDT,"rec_end_ind",&csTmp)) {
DEBUGLOG(("[%d] rec_end_ind = [%s]\n", iBAIDCnt, csTmp));
                                        sprintf(csTag, "r_list.%d.rec_end_ind", iBAIDCnt);
                                        PutField_CString(hResponse,csTag,csTmp);
                                }

                                iBAIDCnt++;

                                hLastSMSCreateDT = RecordSet_GetNext(rLastSMSCreateDT);
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
DEBUGLOG(("Call BOOLBaid::GetLastSMSCreationTime Failure!!\n"));
ERRLOG("TxnOiaByUsLST::Authorize::Call BOOLBaid::GetLastSMSCreationTime Failure!!\n");
                     	PutField_Int(hContext,"internal_error",iRet);
            	}
	}

	// Not Update TxnReqRef
        PutField_Int(hContext,"not_update_log",PD_TRUE);

	RecordSet_Destroy(rLastSMSCreateDT);
        FREE_ME(rLastSMSCreateDT);

DEBUGLOG(("TxnOiaByUsLST Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

