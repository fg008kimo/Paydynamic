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
#include "TxnMgtByUsRLP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(BO);

void TxnMgtByUsRLP(char    cdebug)
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
	char	*csMode;
	char	cPreview;


DEBUGLOG(("Authorize\n"));
	sprintf(csLogFile, "%s/%s", getenv("LOGPATH"),"float_2AFPO.txt");

	/*if(GetField_CString(hRequest,"preview",&csTmp)){
		cPreview = csTmp[0];
DEBUGLOG(("Authorize::preview = [%c]\n",cPreview));
        }*/
	if (GetField_CString(hRequest, "req_mode", &csMode)) {
		if (!strcmp(csMode, PD_RLS_SETT_MODE_PREVIEW))
			cPreview = PD_YES;
		else if (!strcmp(csMode, PD_RLS_SETT_MODE_CUTOFF))
			cPreview = PD_NO;
DEBUGLOG(("Authorize::req_mode = [%s], preview = [%c]\n",csMode,cPreview));
        }
        else {
                iRet = INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() req_mode is missing\n"));
ERRLOG("TxnMgtOnUSRLP:Authorize() req_mode is missing\n");
        }       
 

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call handle_daily_float_2AFPO.sh\n"));
		sprintf(csCmd,"handle_daily_float_2AFPO.sh %c ; echo $? > %s",cPreview,csLogFile);
		iRet = system(csCmd);
	}

	if(iRet==PD_OK){
		FILE    *fp;
		fp = fopen(csLogFile, "r");
                if (fp == NULL) {
DEBUGLOG(("Authorize::Open Payoutfile [%s] problem\n", csLogFile));
ERRLOG("TxnMgtByUsRLP:Authorize::Open Payoutfile problem!!\n");
                        iRet=INT_ERR;
                }
		else{
			fgets(csReturnCode,PD_RESPONSE_CODE_LEN,fp);
			if (csReturnCode[strlen(csReturnCode) - 1] == 0x0A)
				csReturnCode[strlen(csReturnCode)-1] = '\0';
DEBUGLOG(("Authorize::return code = [%s]\n", csReturnCode));

			if(cPreview == PD_YES){
				if(atoi(csReturnCode)==5){
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::preview failed!!!!!!\n"));
				}
				else{
DEBUGLOG(("Authorize::preview success!!!!!!\n"));
				}
			}
			else{
				if(atoi(csReturnCode)!=2){
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::handle_daily_float_2AFPO failed!!!!!!\n"));
				}
			}
		}

		fclose(fp);
		sprintf(csCmd,"rm %s",csLogFile);
		system(csCmd);

	}

	if(iRet == PD_OK){
		if(cPreview == PD_NO){
DEBUGLOG(("Authorize::call handle_daily_float_2_settfl\n"));
			sprintf(csCmd,"handle_daily_float_2_settfl.exec");
			iRet = system(csCmd);
		}
	}


DEBUGLOG(("TxnMgtByUsRLP Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
