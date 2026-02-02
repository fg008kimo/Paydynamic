/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/08              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmxByUsSF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);

void TxnMmxByUsSF(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	cMode;
	char	csHandler[PD_TMP_BUF_LEN +1];

DEBUGLOG(("Authorize()\n"));

	if (GetField_Char(hRequest,"mode",&cMode)) {
DEBUGLOG(("Authorize() mode [%s]\n",cMode));
		if (cMode == PD_MMS_HOST ) 
			strcpy(csHandler,"TxnMmsByUsSF");
		else if (cMode == PD_MMS_CLIENT ) 
			strcpy(csHandler,"TxnMmcByUsSF");
		TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("Authorize iRet = [%d] return from [%s]\n",csHandler));
	}
	else {
DEBUGLOG(("Authorize() unable to find mode\n"));
	}

DEBUGLOG(("TxnMmxByUsSF Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
