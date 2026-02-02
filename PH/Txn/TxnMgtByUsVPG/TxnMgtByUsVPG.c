/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Initial Version					   2012/04/27		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVPG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnMgtByUsVPG(char    cdebug)
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

        
        if(GetField_CString(hRequest,"gen_txn_id",&csTmp)){
DEBUGLOG(("Authorize::gen_txn_id= [%s]\n",csTmp));
        }

        if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hContext,"add_user",csTmp);
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOPayout->ProcessPayoutTxn\n"));
		BOObjPtr = CreateObj(BOPtr,"BOPayout","ProcessPayoutTxn");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
	}


DEBUGLOG(("TxnMgtByUsVPG Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
