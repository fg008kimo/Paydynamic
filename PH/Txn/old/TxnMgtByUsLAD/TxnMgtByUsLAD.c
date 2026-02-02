/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/28              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsLAD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsLAD(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csMerchantId = NULL;
	char	*csPHDate= NULL;
	char    *csTxnCountry=NULL;
	char	*csTxnCcy = NULL;
	char	*csServiceCode = NULL;

	hash_t  *hTxn;
	hTxn = (hash_t*) malloc(sizeof(hash_t));
	hash_init(hTxn, 0);

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hTxn,"merchant_id",csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsLAD::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hTxn,"service_code",csServiceCode);
	}
	else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsLAD::Authorize::service_code not found!!\n");
               	iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hTxn,"txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsLAD::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hTxn,"txn_country",csTxnCountry);
	}
	else{
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hContext,"PHDATE",&csPHDate)){
DEBUGLOG(("Authorize::PHDATE= [%s]\n",csPHDate));
	}

	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hTxn,"create_user",csUser);
	}

	if(iRet==PD_OK){
		PutField_Char(hTxn,"status",PD_REJECT);
		PutField_Char(hTxn,"rule_type",PD_EVERY_X_DAY_RULE);
		PutField_CString(hTxn,"settlement_date",csPHDate);

DEBUGLOG(("Authorize::Call DBAutoSettlementExecLog:Add\n"));
                DBObjPtr = CreateObj(DBPtr,"DBAutoSettlementExecLog","Add");
                iRet = (unsigned long)((*DBObjPtr)(hTxn));
	
	}

	FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsLAD Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
