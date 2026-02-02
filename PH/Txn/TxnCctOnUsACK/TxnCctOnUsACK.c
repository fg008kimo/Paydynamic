/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/28              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnCctOnUsACK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
void TxnCctOnUsACK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csMerchantRef;
	char	csOrgTxnId[PD_TXN_SEQ_LEN +1];


DEBUGLOG(("TxnCctOnUsACK ()\n"));
	if (GetField_CString(hContext,"merchant_ref",&csMerchantRef)) {
DEBUGLOG(("TxnCctOnUsACK () merchant_ref=[%s]\n",csMerchantRef));
		PutField_CString(hResponse,"merchant_ref",csMerchantRef);
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxnByRemark");
        	iRet = (unsigned long)(*DBObjPtr)(csMerchantRef,PD_COMPLETE,csOrgTxnId);
		if (iRet == PD_FOUND) {
			PutField_CString(hContext,"org_txn_seq",csOrgTxnId);
			PutField_CString(hContext,"channel_code","CCT");
DEBUGLOG(("TxnCctOnUsACK () found org txn id =[%s] by using remark = [%s]\n",csOrgTxnId,csMerchantRef));
			TxnObjPtr = CreateObj(TxnPtr,"TxnCctByUsACK","Authorize");
        		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		}
	}
DEBUGLOG(("TxnCctOnUsACK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
