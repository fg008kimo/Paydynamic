/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/13              [MSN]
Add Delete in MerchantLoginPolicy                  2021/04/08              [MIC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsDLC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#include "sha1.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsDLC(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	char	*csClient;

DEBUGLOG(("TxnMgtByUsDLC::Authorize\n"));

	if (GetField_CString(hRequest, "client_id", &csClient)){
DEBUGLOG(("Authorize::client_id = [%s]\n",csClient));
	}
	else {
DEBUGLOG(("Authorize::client_id not found!!\n"));
ERRLOG("TxnMgtByUsDLC::Authorize::client_id not found!!\n");
		iRet=INT_CLIENT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBClients:Delete\n"));
                DBObjPtr = CreateObj(DBPtr,"DBClients","Delete");
                if((unsigned long)((*DBObjPtr)(csClient) != PD_OK)){
DEBUGLOG(("Authorize::DBClients:Delete Failed\n"));
ERRLOG("TxnMgtByUsDLC::Authorize::DBClients:Delete Failed\n");
                        iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
                }
		else {
DEBUGLOG(("Authorize::DBClients:Delete Succ\n"));
		}
        }


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBMerchantLoginPolicy:Delete\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantLoginPolicy","Delete");
		if((unsigned long)((*DBObjPtr)(csClient) != PD_OK)){
DEBUGLOG(("Authorize::DBMerchantLoginPolicy:Delete Failed\n"));
ERRLOG("TxnMgtByUsDLC::Authorize::DBMerchantLoginPolicy:Delete Failed\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else {
DEBUGLOG(("Authorize::DBMerchantLoginPolicy:Delete Succ\n"));
		}
	}



DEBUGLOG(("TxnMgtByUsDLC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

