/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version 					   2015/06/05		   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUs2Host.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(Txn);

void TxnOmtByUs2Host(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;


DEBUGLOG(("Authorize\n")); 

	TxnObjPtr = CreateObj(TxnPtr,"TxnMmcByUs2Host","Authorize");
        iRet = (unsigned long) (*TxnObjPtr)(hContext,hRequest,hResponse);

DEBUGLOG(("TxnOmtByUs2Host Normal Exit() iRet = [%d]\n",iRet));
	
        return iRet;
}
