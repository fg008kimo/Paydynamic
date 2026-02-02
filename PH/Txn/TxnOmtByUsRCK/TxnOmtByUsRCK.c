/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/24              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRCK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);
void TxnOmtByUsRCK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csOrgTxnSeq;
DEBUGLOG(("TxnOmtByUsRCK Authorize()\n"));
	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
		PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnOmtByUsRCK txn seq = [%s]\n",csOrgTxnSeq));
		TxnObjPtr = CreateObj(TxnPtr,"TxnOlnByUsACK","Authorize");
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
	}
	else {
		iRet = INT_TXN_ID_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
	}
DEBUGLOG(("TxnOmtByUsRCK Ret = [%d]\n",iRet));
	return iRet;
}
