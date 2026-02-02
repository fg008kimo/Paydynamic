/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/30              Virginia Yun
updated	                                           2012/09/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCFR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(BO);

void TxnMgtByUsCFR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csCmd[PD_TMP_BUF_LEN*2+1];
	char	*csPspId;

DEBUGLOG(("Authorize\n"));

	if (GetField_CString(hRequest, "psp_id", &csPspId)) {
DEBUGLOG(("Authorize::psp_id = [%s]\n",csPspId));
        }
        else {
                iRet = INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() psp_id is missing\n"));
ERRLOG("TxnMgtOnUSCFR:Authorize() psp_id is missing\n");
        }       
 

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call reset_checkpsp_cutoff.sh\n"));
		sprintf(csCmd,"reset_checkpsp_cutoff.sh %s",csPspId);
		iRet = system(csCmd);
	}


DEBUGLOG(("TxnMgtByUsCFR Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
