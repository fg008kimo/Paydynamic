/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/07/25              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPOR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(BO);

void TxnMgtByUsPOR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        char    *csTmp;

DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hRequest,"merchant_id",&csTmp)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csTmp));
        }
        
        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOPayout->ProcessPayoutTxn\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","ProcessPayoutTxn");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
	}

        if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }


DEBUGLOG(("TxnMgtByUsPOR Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
