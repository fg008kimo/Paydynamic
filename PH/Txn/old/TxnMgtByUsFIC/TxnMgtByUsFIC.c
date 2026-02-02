/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/18              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsFIC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);


void TxnMgtByUsFIC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csTmp;
	hash_t  *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("Authorize\n"));

        if(GetField_CString(hRequest,"fin_id",&csTmp)){
		PutField_CString(hTxn,"fundsin_id",csTmp);
DEBUGLOG(("Authorize::fin_id = [%s]\n",csTmp));
        }

        if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"approve_user",csTmp);
DEBUGLOG(("Authorize::approve_user = [%s]\n",csTmp));
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call DBFundsIn->UpdateApprove\n"));
		DBObjPtr = CreateObj(DBPtr,"DBFundsIn","UpdateApprove");
		iRet = (unsigned long)(*DBObjPtr)(hTxn);
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsFIC Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
