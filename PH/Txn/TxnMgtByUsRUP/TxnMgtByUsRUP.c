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
#include "TxnMgtByUsRUP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsRUP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
DEBUGLOG(("Authorize\n"));
	char	csPath[PD_TMP_BUF_LEN+1];

	sprintf(csPath,"%s/deposit_files/",getenv("REPORT_DATA"));
	PutField_CString(hResponse,"upload_path",csPath);
DEBUGLOG(("TxnMgtByUsRUP upload_path = [%s]\n",csPath));

DEBUGLOG(("TxnMgtByUsRUP Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
