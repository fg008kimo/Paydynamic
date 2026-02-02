/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMSN.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#include "sha1.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMgtByUsMSN(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	char	*csTmp;
	char	cTmp;
	
	hash_t  *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

DEBUGLOG(("TxnMgtByUsMSN::Authorize\n"));

	if (GetField_CString(hRequest, "service_code", &csTmp)){
		PutField_CString(hTxn, "service_code", csTmp);
DEBUGLOG(("Authorize::service_code = [%s]\n",csTmp));
	}
	else {
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsMSN::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest, "name", &csTmp)){
		PutField_CString(hTxn, "name", csTmp);
DEBUGLOG(("Authorize::service name = [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"use_lb",&csTmp)){
		cTmp = csTmp[0];
DEBUGLOG(("Authorize:: use load balancing = [%c]\n",cTmp));
		if(cTmp==PD_YES){
			PutField_Int(hTxn,"use_lb",PD_TRUE);
		}
		else if (cTmp==PD_NO){
			PutField_Int(hTxn,"use_lb",PD_FALSE);
		}
		else{
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: invalid value!!!\n"));
ERRLOG("TxnMgtByUsMSN::Authorize::invalid 'use_lb' value!!\n");
		}
	}

	if(GetField_CString(hRequest,"select_bank",&csTmp)){
		cTmp = csTmp[0];
DEBUGLOG(("Authorize:: select bank = [%c]\n",cTmp));
		if(cTmp==PD_YES){
			PutField_Int(hTxn,"select_bank",PD_TRUE);
		}
		else if (cTmp==PD_NO){
			PutField_Int(hTxn,"select_bank",PD_FALSE);
		}
		else{
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: invalid value!!!\n"));
ERRLOG("TxnMgtByUsMSN::Authorize::invalid 'select_bank' value!!\n");
		}
        }
	
	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"update_user",csTmp);
DEBUGLOG(("Authorize::update_user= [%s]\n",csTmp));
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBDefServiceCode:Update\n"));
                DBObjPtr = CreateObj(DBPtr,"DBDefServiceCode","Update");
                if((unsigned long)((*DBObjPtr)(hTxn) != PD_OK)){
DEBUGLOG(("Authorize::DBDefServiceCode:Update Failed\n"));
ERRLOG("TxnMgtByUsMSN::Authorize::DBDefServiceCode:Update Failed\n");
                        iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
                }
		else {
DEBUGLOG(("Authorize::DBDefServiceCode:Update Succ\n"));
		}
        }

	hash_destroy(hTxn);
	FREE_ME(hTxn);

DEBUGLOG(("TxnMgtByUsMSN Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

