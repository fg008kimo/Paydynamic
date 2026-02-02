/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/10              Elvis Wong
Refine                                             2014/09/26              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMDC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsMDC(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	int	iTmpRet;

	char	*csTmp = NULL;
	double  dTmp = 0;	
	int	iTmp = 0;
	int	iCnt, i;
	
	char	cAction;
	char	*csMid = NULL;
	char	*csService = NULL;	
	char	*csCountry = NULL;	

        char    csTag[PD_TAG_LEN +1];

	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

DEBUGLOG(("TxnMgtByUsMDC::Authorize\n"));

/* mid */
        if (GetField_CString(hRequest, "merchant_id", &csMid)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n", csMid));
	}
	else {
DEBUGLOG(("Authorize::merchant_Id not found\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::merchant_id not found\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* action */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "action", &csTmp)) {
			cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n",cAction));

			// not support delete
			if (cAction != PD_ACTION_ADD && cAction != PD_ACTION_UPDATE) {
DEBUGLOG(("Authorize::action [%c] not accepted!!\n", cAction));
ERRLOG("TxnMgtByUsMDC::Authorize::action not found!!\n");
	        	        iRet=INT_ACTION_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
		else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::action not found!!\n");
                	iRet=INT_ACTION_NOT_FOUND;
                	PutField_Int(hContext,"internal_error",iRet);
		}
	}

/* total_cnt */
	if (iRet == PD_OK) {
		if (GetField_Int(hContext, "total_cnt", &iCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
			PutField_Int(hResponse, "total_cnt", iCnt);
		}
		else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::total_cnt not found\n");
			iRet = INT_FORMAT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

/* disabled */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "disabled", &csTmp)) {
			iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::disabled = [%d]\n",iTmp));
			PutField_Int(hTxn, "disabled", iTmp);
		}
		else {
DEBUGLOG(("Authorize::disabled not found!!\n"));
			PutField_Int(hTxn, "disabled", PD_FALSE);
		}
	}

/* add_user */
	if (iRet == PD_OK) {
		if(GetField_CString(hRequest,"add_user",&csTmp)) {
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
			PutField_CString(hTxn,"create_user",csTmp);
			PutField_CString(hTxn, "update_user", csTmp);
        	}
	}

	if (iRet == PD_OK) {
		for (i = 0; i < iCnt; i++) {
/* merchant_id */
			PutField_CString(hTxn, "merchant_id", csMid);

/* service */
			memset(csTag, 0, sizeof(csTag));	
			sprintf(csTag, "%s_service_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csService)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csService));
                                PutField_CString(hTxn, "service_code", csService); // for add
                                PutField_CString(hTxn, "service", csService); // for update
                        } 
                        else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsMDC::Authorize::[%s] not found\n", csTag);
                                iDtlRet = INT_SERVICE_CODE_MISSING;
                        }

/* country */
			if (iDtlRet == PD_OK) {
				memset(csTag, 0, sizeof(csTag));	
				sprintf(csTag, "%s_country_%d", PD_DETAIL_TAG, i+1);
                        	if (GetField_CString(hRequest, csTag, &csCountry)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csCountry));
                                	PutField_CString(hTxn, "country", csCountry);
                        	} 
                        	else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsMDC::Authorize::[%s] not found\n", csTag);
                                	iDtlRet = INT_TXN_COUNTRY_NOT_FOUND;
                        	}
			}

/* daily_cap */
			if (iDtlRet == PD_OK) {
				memset(csTag, 0, sizeof(csTag));	
				sprintf(csTag, "%s_daily_cap_%d", PD_DETAIL_TAG, i+1);
				if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));
					sscanf(csTmp, "%lf", &dTmp);
					PutField_Double(hTxn, "daily_cap", dTmp);
				} else {
					//dTmp = 0.0;
                                	//PutField_Double(hTxn, "daily_cap", dTmp);
DEBUGLOG(("Authorize::daily_cap(default) = [%f]\n",dTmp));
                        	}
			}

			if (iDtlRet == PD_OK && cAction == PD_ACTION_ADD) {

				/* Merchant Limit Daily Capacity*/
				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:GetRecord\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBMerchLimDailyCap","GetRecord");
					iTmpRet = (unsigned long)(DBObjPtr)(hTxn);
                                        if (iTmpRet == FOUND) {
						GetField_Int(hTxn, "org_disabled", &iTmp);
						if (!iTmp) {
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:Record Found!!!\n"));
                                                	iDtlRet = INT_REC_ALREADY_EXISTS;
                                                	iRet = INT_REC_ALREADY_EXISTS;
						} else {
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:Record Found Disabled!!!\n"));
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:UpdateMerchLimDailyCap\n"));
							DBObjPtr = CreateObj(DBPtr,"DBMerchLimDailyCap","Update");
                                        		if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Update Failed\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::DBMerchLimDailyCap:Update Failed\n");
                                                		iDtlRet = INT_ERR;
                                                		iRet = INT_ERR;
							}
                                        		else {
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Update Succ\n"));
                                        		}
						}
					}
					else {
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:Record Not Found!!!\n"));
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:Add\n"));
						DBObjPtr = CreateObj(DBPtr,"DBMerchLimDailyCap","Add");
						if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Add Failed\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::DBMerchLimDailyCap:Add Failed\n");
							iDtlRet = INT_ERR;
							iRet = INT_ERR;
                				}
			                	else {
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Add Succ\n"));
                				}
					}
        			}
			}
			else if (iDtlRet == PD_OK && cAction == PD_ACTION_UPDATE) {

				/* Merchant Limit Daily Capacity*/
				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchLimDailyCap:UpdateMerchLimDailyCap\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMerchLimDailyCap","Update");
                                        if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Update Failed\n"));
ERRLOG("TxnMgtByUsMDC::Authorize::DBMerchLimDailyCap:Update Failed\n");
                                                iDtlRet = INT_ERR;
                                                iRet = INT_ERR;
                                        }
                                        else {
DEBUGLOG(("Authorize::DBMerchLimDailyCap:Update Succ\n"));
                                        }
				}
			}
			
			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "ret_%d", i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag, iDtlRet));
			PutField_Int(hResponse, csTag ,iDtlRet);

			if (iDtlRet != PD_OK) {
				if (iDtlRet == INT_REC_ALREADY_EXISTS)
				{
					iRet = INT_REC_ALREADY_EXISTS;
				} else {
					iRet = INT_ERR;
				}
                		PutField_Int(hContext,"internal_error",iRet);

				break;
			}
		}
	}

        hash_destroy(hTxn);
        FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsMDC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

