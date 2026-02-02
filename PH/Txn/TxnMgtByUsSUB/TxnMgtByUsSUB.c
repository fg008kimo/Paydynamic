/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/11              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsSUB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;
OBJPTR(DB);


void TxnMgtByUsSUB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csOrgTxnSeq;
	char	*csTmp;
	hash_t	*hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
                PutField_CString(hTxn,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("Authorize::org txn seq = [%s]\n",csOrgTxnSeq));
	}
	else {
		iRet = INT_TXN_ID_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnMgtByUsSUB: Authorize::org txn seq is missing\n");
	}

	if (GetField_CString(hRequest,"logmsg",&csTmp)){
		PutField_CString(hTxn,"logmsg",csTmp);
DEBUGLOG(("Authorize::logmsg = [%s]\n",csTmp));
	}
	else{
		iRet = INT_DESC_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnMgtByUsSUB: Authorize::logmsg is missing\n");
	}

	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"add_user",csTmp);
DEBUGLOG(("Authorize::user = [%s]\n",csTmp));
	}
	else{
		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	}


	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTxnWebLog:AddTxnWebLog\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTxnWebLog","AddTxnWebLog");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBTxnWebLog:AddTxnWebLog Failed\n"));
ERRLOG("TxnMgtByUsSUB: Authorize::DBTxnWebLog:AddTxnWebLog Failed\n");
                }
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsSUB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
