/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/03/15              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPOU.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"



char cDebug;
OBJPTR(BO);

void TxnMgtByUsPOU(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	//unsigned long	lBatchId = 0l;
	hash_t  *hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hRequest,"batch_id",&csTmp)){
		//lBatchId = ctol((const unsigned char *)csTmp,strlen(csTmp));
		PutField_CString(hTxn,"batch_id",csTmp);
DEBUGLOG(("Authorize: batch_id [%s]\n",csTmp));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG(("Authorize: batch_id is missing!!!!\n"));
	}

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call BOPayout->GetPayoutRecords\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","GetPayoutRecords");
                iRet = (unsigned long)(*BOObjPtr)(hTxn,hContext,hRequest);
	}

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::call BOPayout->UpdateDetail\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","UpdateDetail");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsPOU Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
