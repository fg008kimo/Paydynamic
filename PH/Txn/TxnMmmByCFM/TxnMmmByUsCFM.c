/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/26              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsCFM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);


void TxnMmmByUsCFM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

DEBUGLOG(("Authorize()\n"));
	BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","RemitTxn");
	iRet = (unsigned long)((BOObjPtr)(hContext,hRequest));
DEBUGLOG(("TxnMmmByUsCFM Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

