/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/13              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMPM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsMPM(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;

	char	*csTmp = NULL;	
	int	iCnt, i ;

	char	*csMid = NULL;

        char    csTag[PD_TAG_LEN +1];

	char	cAction;
	int	iTmp;

        hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));

	recordset_t 	*rRecordSet;
	rRecordSet = (recordset_t *)malloc(sizeof(recordset_t));
	recordset_init(rRecordSet,0);


DEBUGLOG(("TxnMgtByUsMPM::Authorize\n"));

/* mid */
        if (GetField_CString(hRequest, "merchant_id", &csMid)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n", csMid));
	}
	else {
DEBUGLOG(("Authorize::merchant_Id not found\n"));
ERRLOG("TxnMgtByUsMPM::Authorize::merchant_id not found\n");
		iRet = INT_MERCHANT_ID_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}

/* action */
	if (GetField_CString(hRequest, "action", &csTmp)) {
		cAction = csTmp[0];
DEBUGLOG(("Authorize::action = [%c]\n", cAction));
	}
	else {
DEBUGLOG(("Authorize::action not found!!\n"));
ERRLOG("TxnMgtByUsMPM::Authorize::action not found!!\n");
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
ERRLOG("TxnMgtByUsMPM::Authorize::total_cnt not found\n");
		iRet = INT_FORMAT_ERR;

		PutField_Int(hContext,"internal_error",iRet);
	}


	if (iRet == PD_OK) {
		for (i = 0; i < iCnt; i++) {
       	 		hash_init(hTxn, 0);

/* merchant_id */
			PutField_CString(hTxn, "merchant_id", csMid);

/* pay_method */
			memset(csTag, 0, sizeof(csTag));	
			sprintf(csTag, "%s_pay_method_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));
                		PutField_CString(hTxn, "pay_method", csTmp);
			}	
			else {		
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsMPM::Authorize::[%s] not found\n", csTag);
				iDtlRet = INT_PAYMETHOD_NOT_FOUND;
			}

/* add_user */
			if(GetField_CString(hRequest,"add_user",&csTmp)) {
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
				PutField_CString(hTxn,"create_user",csTmp);
				PutField_CString(hTxn,"update_user",csTmp);
        		}

/* disabled */	
			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_disabled_%d", PD_DETAIL_TAG, i+1);

			if (GetField_CString(hRequest, csTag, &csTmp)) {
				iTmp = atoi(csTmp);
DEBUGLOG(("Authorize::disabled = [%d]\n",iTmp));
                                PutField_Int(hTxn, "disabled", iTmp);
			} else {
				if (cAction == PD_ACTION_ADD) {
DEBUGLOG(("Authorize::disabled set defult\n"));
					PutField_Int(hTxn, "disabled", PD_FALSE);
				}
				else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsMPM::Authorize::[%s] not found\n", csTag);
					iDtlRet = INT_ERR;
				}
			
			}

			if (iDtlRet == PD_OK && cAction == PD_ACTION_ADD) {

				// MerchantPayMethod 

				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchantPayMethod:Add\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMerchantPayMethod","Add");
					if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantPayMethod:Add Failed\n"));
ERRLOG("TxnMgtByUsMPM::Authorize::DBMerchantPayMethod:Add Failed\n");

						iDtlRet = INT_ERR;
						iRet = INT_ERR;
                			}
			                else {
DEBUGLOG(("Authorize::DBMerchantPayMethod:Add Succ\n"));
                			}
        			}
			} else if (iDtlRet == PD_OK && cAction == PD_ACTION_UPDATE) {
				//Update

				if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchantPayMethod:Update\n"));
					DBObjPtr = CreateObj(DBPtr,"DBMerchantPayMethod","Update");
					if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantPayMethod:Update Failed\n"));
ERRLOG("TxnMgtByUsMPM::Authorize::DBMerchantPayMethod:Update Failed\n");

						iDtlRet = INT_ERR;
						iRet = INT_ERR;
                			}
					else {
DEBUGLOG(("Authorize::DBMerchantPayMethod:Update Succ\n"));
					}
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


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);


DEBUGLOG(("TxnMgtByUsMPM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

