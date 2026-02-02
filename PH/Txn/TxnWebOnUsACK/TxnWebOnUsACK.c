/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/21              Cody Chan
encrypt type and ccy code not hard code		   2011/01/27		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsACK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);
void TxnWebOnUsACK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	TxnObjPtr = CreateObj(TxnPtr,"TxnWebByUsACK","Authorize");
        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("TxnWebOnUsACK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
