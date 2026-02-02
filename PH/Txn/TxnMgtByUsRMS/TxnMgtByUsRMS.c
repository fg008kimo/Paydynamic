/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/18              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRMS.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(BO);

void TxnMgtByUsRMS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;
	
DEBUGLOG(("Authorize()\n"));

/* eid (entity_id) */
	if (GetField_CString(hContext,"entity_id",&csTmp)) {
		PutField_CString(hData,"entity_id",csTmp);
DEBUGLOG(("Authorize: eid = [%s]\n",csTmp));
	} else {
DEBUGLOG(("Authorize:: eid missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: eid missing!!\n");
		iRet = INT_MMS_ENTITY_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* user */
	if (GetField_CString(hRequest,"user",&csTmp)) {
		PutField_CString(hData,"user",csTmp);
DEBUGLOG(("Authorize: user = [%s]\n",csTmp));
	} else {
DEBUGLOG(("Authorize:: user missing!!\n"));
ERRLOG("TxnMmsByUsEPA:: Authorize:: user missing!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	// Response
	PutField_CString(hResponse,"reply_txn_code",PD_TXN_CODE_MMS_DEFAULT_NID);
        PutField_Int(hResponse,"ret",iRet);

DEBUGLOG(("TxnMgtByUsRMS Normal Exit() reply_txn_code = [%s], iRet = [%d]\n","RSE",iRet));
	return iRet;
}
