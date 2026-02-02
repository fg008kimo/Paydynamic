/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/24              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCCG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsCCG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csFromCustomerGroup;
	char	*csToCustomerGroup;
	char	*csMerchantId;
	char	*csCcy;
	char	*csCountry;
	char	*csServiceCode;
	char	*csCustomerId;
	char	*csDate;
	char	*csUser;

	hash_t  *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

	if(GetField_CString(hRequest,"from_cust_grp",&csFromCustomerGroup)){
		PutField_CString(hTxn,"from_customer_group",csFromCustomerGroup);
DEBUGLOG(("Authorize::from_customer_group= [%s]\n",csFromCustomerGroup));
	}
	else{
DEBUGLOG(("Authorize::from_customer_group not found!!\n"));
ERRLOG("TxnMgtByUsCCG::Authorize::from_customer_group not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"to_cust_grp",&csToCustomerGroup)){
		PutField_CString(hTxn,"to_customer_group",csToCustomerGroup);
DEBUGLOG(("Authorize::to_customer_group= [%s]\n",csToCustomerGroup));
	}
	else{
DEBUGLOG(("Authorize::to_customer_group not found!!\n"));
ERRLOG("TxnMgtByUsCCG::Authorize::to_customer_group not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	
	if(GetField_CString(hRequest,"add_user",&csUser)){
		PutField_CString(hTxn,"update_user",csUser);
DEBUGLOG(("Authorize::update_user= [%s]\n",csUser));
	}

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
		PutField_CString(hTxn,"merchant_id",csMerchantId);
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsCCG::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csCcy)){
		PutField_CString(hTxn,"txn_ccy",csCcy);
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csCcy));
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_CString(hRequest,"txn_country",&csCountry)){
		PutField_CString(hTxn,"txn_country",csCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csCountry));
        }
        else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

        if(GetField_CString(hRequest,"service_code",&csServiceCode)){
		PutField_CString(hTxn,"service_code",csServiceCode);
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
        }

	if(GetField_CString(hRequest,"cust_tag",&csCustomerId)){
		PutField_CString(hTxn,"customer_tag",csCustomerId);
DEBUGLOG(("Authorize::customer_id= [%s]\n",csCustomerId));
	}
	else{
DEBUGLOG(("Authorize::customer_id not found!!\n"));
ERRLOG("TxnMgtByUsCCG::Authorize::customer_id not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hContext,"PHDATE",&csDate)){
		PutField_CString(hTxn,"date",csDate);
DEBUGLOG(("Authorize::PHDATE= [%s]\n",csDate));
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOCustomerGroup:ChangeGroup\n"));
		BOObjPtr = CreateObj(BOPtr,"BOCustomerGroup","ChangeGroup");
		iRet = (unsigned long) (*BOObjPtr)(hTxn);
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsCCG Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
