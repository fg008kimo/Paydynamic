/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/01/02              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsDMR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(BO);

void TxnMgtByUsDMR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csCmd[PD_TMP_BUF_LEN*2+1];
	char	csLogFile[PD_TMP_BUF_LEN+1];
	char	csReturnCode[PD_RESPONSE_CODE_LEN];
	char	*csDate;

DEBUGLOG(("Authorize\n"));
	sprintf(csLogFile, "%s/%s", getenv("LOGPATH"),"dsp_match_stat.txt");

	if (GetField_CString(hRequest, "date", &csDate)) {
DEBUGLOG(("Authorize::date = [%s]\n",csDate));
        }
        else {
                iRet = INT_TRASMISSION_TIME_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() date is missing\n"));
ERRLOG("TxnMgtOnUSDMR:Authorize() date is missing\n");
        }       
 

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call deposit_match_stat.sh\n"));
		sprintf(csCmd,"deposit_match_stat.sh %s ; echo $? > %s",csDate,csLogFile);
		iRet = system(csCmd);
	}

	if(iRet==PD_OK){
		FILE    *fp;
		fp = fopen(csLogFile, "r");
                if (fp == NULL) {
DEBUGLOG(("Authorize::Open logfile [%s] problem\n", csLogFile));
ERRLOG("TxnMgtByUsDMR:Authorize::Open logfile problem!!\n");
                        iRet=INT_ERR;
                }
		else{
			fgets(csReturnCode,PD_RESPONSE_CODE_LEN,fp);
			if (csReturnCode[strlen(csReturnCode) - 1] == 0x0A)
				csReturnCode[strlen(csReturnCode)-1] = '\0';
DEBUGLOG(("Authorize::return code = [%s]\n", csReturnCode));

			if(atoi(csReturnCode)!=1){
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::deposit_match_stat.sh failed!!!!!!\n"));
			}
		}

		fclose(fp);
		sprintf(csCmd,"rm %s",csLogFile);
		system(csCmd);

	}

DEBUGLOG(("TxnMgtByUsDMR Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
