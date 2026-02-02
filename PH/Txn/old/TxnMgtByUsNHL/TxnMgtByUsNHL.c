/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/03/27              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsNHL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#include "sha1.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsNHL(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	char	*csTmp;
	char	*csCountry;
	char	*csDate;
	char	cAction;
	char	csTag[PD_TAG_LEN+1];
	int	i = 0;
	int	iCnt = 0;
	
	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

DEBUGLOG(("TxnMgtByUsNHL::Authorize\n"));

/* action */
        if (GetField_CString(hRequest, "action", &csTmp)) {
                cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));
		//support add, update(desc) and delete
		if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE && cAction != PD_ACTION_DELETE) {
DEBUGLOG(("Authorize::action [%d] not support!!\n", cAction));
ERRLOG("TxnMgtByUsMBA::Authorize::action not support!!\n");
                        iRet=INT_ACTION_NOT_FOUND;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }
        else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsNHL::Authorize::action not found!!\n");
                iRet=INT_ACTION_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }


/* total_cnt */
        if (GetField_Int(hContext, "total_cnt", &iCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
                PutField_Int(hResponse, "total_cnt", iCnt);
        }
        else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnMgtByUsMBA::Authorize::total_cnt not found\n");
                iRet = INT_FORMAT_ERR;

                PutField_Int(hContext,"internal_error",iRet);
        }

	if (iRet == PD_OK) {
                for (i = 0; i < iCnt; i++) {
                        hash_init(hTxn, 0);

                        memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "%s_country_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csCountry)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csCountry));
                                PutField_CString(hTxn, "country", csCountry);
                        }
                        else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsNHL::Authorize::[%s] not found\n", csTag);
                                iDtlRet = INT_TXN_COUNTRY_NOT_FOUND;
                        }

			memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "%s_date_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csDate)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csDate));
                                PutField_CString(hTxn, "date", csDate);
                        }
                        else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsNHL::Authorize::[%s] not found\n", csTag);
                                iDtlRet = INT_ERR;
                        }
			
			memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "%s_desc_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));
                                PutField_CString(hTxn, "desc", csTmp);
                        }
                        else if (cAction==PD_ACTION_UPDATE){
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsNHL::Authorize::[%s] not found\n", csTag);
                                iDtlRet = INT_ERR;
                        }

			if(GetField_CString(hRequest,"add_user",&csTmp)){
				PutField_CString(hTxn,"create_user",csTmp);
				PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("Authorize::create_user= [%s]\n",csTmp));
DEBUGLOG(("Authorize::update_user= [%s]\n",csTmp));
			}

			if(iDtlRet==PD_OK && cAction==PD_ACTION_ADD){
DEBUGLOG(("Authorize::Call DBNonHoliday:Add\n"));
                		DBObjPtr = CreateObj(DBPtr,"DBNonHoliday","Add");
                		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBNonHoliday:Add Failed\n"));
ERRLOG("TxnMgtByUsNHL::Authorize::DBNonHoliday:Add Failed\n");
                        		iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
                		}
				else {
DEBUGLOG(("Authorize::DBNonHoliday:Add Succ\n"));
				}
        		}
			else if(iDtlRet==PD_OK && cAction==PD_ACTION_UPDATE){
DEBUGLOG(("Authorize::Call DBNonHoliday:UpdateDesc\n"));
                		DBObjPtr = CreateObj(DBPtr,"DBNonHoliday","UpdateDesc");
                		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBNonHoliday:UpdateDesc Failed\n"));
ERRLOG("TxnMgtByUsNHL::Authorize::DBNonHoliday:UpdateDesc Failed\n");
                        		iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
                		}
				else {
DEBUGLOG(("Authorize::DBNonHoliday:UpdateDesc Succ\n"));
				}
        		}
			else if(iDtlRet==PD_OK && cAction==PD_ACTION_DELETE){
DEBUGLOG(("Authorize::Call DBNonHoliday:Delete\n"));
                		DBObjPtr = CreateObj(DBPtr,"DBNonHoliday","Delete");
                		if((unsigned long)((*DBObjPtr)(csCountry,csDate) != PD_OK)){
DEBUGLOG(("Authorize::DBNonHoliday:Delete Failed\n"));
ERRLOG("TxnMgtByUsNHL::Authorize::DBNonHoliday:Delete Failed\n");
                        		iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
                		}
				else {
DEBUGLOG(("Authorize::DBNonHoliday:Delete Succ\n"));
				}
        		}

			memset(csTag, 0, sizeof(csTag));
                        sprintf(csTag, "ret_%d", i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag, iDtlRet));
                        PutField_Int(hResponse, csTag ,iDtlRet);

                        if (iDtlRet != PD_OK) {
                                iRet = INT_ERR;
                        }
		}
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsNHL Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
