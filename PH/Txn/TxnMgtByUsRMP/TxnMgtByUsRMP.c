/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/03              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRMP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsRMP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csPspId;
DEBUGLOG(("Authorize\n"));
	
	if(GetField_CString(hRequest,"psp_id",&csPspId)){
DEBUGLOG(("TxnMgtByUsRMP psp_id [%s]\n",csPspId));
	}


	
	

DEBUGLOG(("TxnMgtByUsRMP Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
