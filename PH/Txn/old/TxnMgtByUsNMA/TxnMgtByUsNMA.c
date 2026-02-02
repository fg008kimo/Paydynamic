/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/22              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsNMA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsNMA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{

        int     iRet = PD_OK;

	char	*csMerchantId;
        char	*csTxnCountry;
	char	*csTxnCcy;
	char	*csServiceCode;
        char    *csTmp;
	char	csUser[PD_CREATE_USER_LEN+1];


	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsNMA::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsNMA::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsNMA::Authorize::country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
	}
        else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsNMA::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;

        } 

	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
		strcpy(csUser,csTmp);
	}
	else{
		strcpy(csUser,PD_UPDATE_USER);
	}
	csUser[strlen(csUser)]='\0';


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBMerhantBalance:UpdateFloat\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","UpdateFloat");
		if((unsigned long) ((*DBObjPtr)(csMerchantId,csTxnCountry,csTxnCcy,
                                                csServiceCode,0.0,csUser))!=PD_OK)
                        iRet = INT_ERR;
                
		else{
DEBUGLOG(("Authorize::New MerhantBalance Account added\n"));
		}
                
	}


	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}


DEBUGLOG(("TxnMgtByUsNMA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
