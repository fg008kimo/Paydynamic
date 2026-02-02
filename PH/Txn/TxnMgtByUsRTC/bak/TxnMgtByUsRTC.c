/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/18              Virginia Yun
Change input para to country, service, psp_type    2013/07/05              David Wong
& reset daily AMT and CNT request counter
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRTC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsRTC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csTmp = NULL;
	char	cPartyType;

	
DEBUGLOG(("Authorize\n"));

/* txn_code */
/*
	if (GetField_CString(hRequest, "req_txn_code", &csTmp)) {
DEBUGLOG(("Authorize::req_txn_code = [%s]\n",csTmp));
		PutField_CString(hContext, "req_txn_code", csTmp);
	}
	else {
DEBUGLOG(("Authorize::req_txn_code not found!!\n"));
	}
*/

/* country */ /* must */
	if (GetField_CString(hRequest, "txn_country", &csTmp)) {
DEBUGLOG(("Authorize::country = [%s]\n",csTmp));
		PutField_CString(hContext, "country", csTmp);
	}
	else {
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMgtByUsRTC::Authorize::txn_country not found!!\n");
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* ch_code */
/*
	if (GetField_CString(hRequest, "ch_code", &csTmp)) {
DEBUGLOG(("Authorize::channel_code = [%s]\n",csTmp));
		PutField_CString(hContext, "ch_code", csTmp);
	}
	else {
DEBUGLOG(("Authorize::channel_code not found!!\n"));
	}
*/


/* service_code */ /* must */
        if (GetField_CString(hRequest, "service_code", &csTmp)) {
DEBUGLOG(("Authorize::service_code = [%s]\n",csTmp));
		PutField_CString(hContext, "service", csTmp);
        }
        else {
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsRTC::Authorize::service_code not found!!\n");
                iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* psp_type */ /* must */
        if (GetField_CString(hRequest, "psp_type", &csTmp)) {
DEBUGLOG(("Authorize::psp_type = [%s]\n",csTmp));
                PutField_CString(hContext, "psp_type", csTmp);
        }
        else {
DEBUGLOG(("Authorize::psp_type not found!!\n"));
ERRLOG("TxnMgtByUsRTC::Authorize::psp_type not found!!\n");
                iRet=INT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* pay_method */
/*
        if (GetField_CString(hRequest, "pay_method", &csTmp)) {
DEBUGLOG(("Authorize::pay_method = [%s]\n",csTmp));
                PutField_CString(hContext, "pay_method", csTmp);
        }
        else {
DEBUGLOG(("Authorize::pay_method not found!!\n"));
        }
*/

/* type */
	PutField_Char(hContext, "type", PD_DAILY);
DEBUGLOG(("Authorize::type = [%c]\n",PD_DAILY));

/* category */
/*
	PutField_CString(hContext, "category", PD_VALUE_TYPE_AMT);
DEBUGLOG(("Authorize::category = [%s]\n",PD_VALUE_TYPE_AMT));
*/

/* party_type */
//	if (GetField_CString(hRequest, "party_type", &csTmp)) {
//		cPartyType = csTmp[0];
//	} 
//	else {
//DEBUGLOG(("Authorize::party_type not found!!\n"));
		cPartyType = PD_TYPE_PSP;
//	}
	PutField_Char(hContext, "party_type", cPartyType);
DEBUGLOG(("Authorize::party_type = [%c]\n",cPartyType));


/* party_id */
/*
        if (GetField_CString(hRequest, "party_id", &csTmp)) {
DEBUGLOG(("Authorize::party_id = [%s]\n",csTmp));
		PutField_CString(hContext, "party_id", csTmp);
        }
        else {
DEBUGLOG(("Authorize::party_id not found!!\n"));
        }
*/

/* currency */
/*
        if (GetField_CString(hRequest, "txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::ccy = [%s]\n",csTmp));
                PutField_CString(hContext, "ccy", csTmp);
        }
        else {
DEBUGLOG(("Authorize::ccy not found!!\n"));
        }
*/

/* counter */
	PutField_Int(hContext, "counter", 0);

/* user */
	if (GetField_CString(hRequest, "add_user", &csTmp)) {
DEBUGLOG(("Authorize::user = [%s]\n",csTmp));
                PutField_CString(hContext, "update_user", csTmp);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnCounters:ResetReqCounter\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnCounters","ResetReqCounter");
		if ((*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize::TxnCounters:ResetReqCounters Succ\n"));
		}
		else {
DEBUGLOG(("Authorize::TxnCounters:ResetReqCounters Fail\n"));
			iRet = INT_ERR;
		}
	}

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMgtByUsRTC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
