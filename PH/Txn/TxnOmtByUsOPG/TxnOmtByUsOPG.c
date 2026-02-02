/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/16              LokMan Chow
no need to call DBOLPayoutGeneratedTmp		   2015/09/21		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOPG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnOmtByUsOPG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csPreviewId;
        char    *csUser;
        char    *csReportDate;
        char    *csMerchantId;
	int	iOnlinePayout = PD_FALSE;
	char    csCmd[PD_TMP_BUF_LEN*2+1];
	int	iGenId = 0;

DEBUGLOG(("Authorize\n"));

DEBUGLOG(("Call DBPayoutActionLock::CheckTheActionCtl_ReadOnly\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","CheckTheActionCtl_ReadOnly");
	iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
	if(iRet!=PD_OK){
		iRet = INT_OTHER_PAYOUT_PROCESSING;
	}


        if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));

		DBObjPtr = CreateObj(DBPtr,"DBRulePayoutOnlineMode","ChkRuleExistsByMerchant");
		if ((unsigned long)(DBObjPtr)(csMerchantId) == PD_FOUND){
			//PutField_Int(hContext,"online_payout",PD_TRUE);
			iOnlinePayout = PD_TRUE;
		}
        }

        if(GetField_CString(hRequest,"preview_id",&csPreviewId)){
		iGenId = atoi(csPreviewId);
DEBUGLOG(("Authorize::preview_id= [%s]\n",csPreviewId));
        }
	else{
		iRet = INT_ERR;
DEBUGLOG(("Authorize::preview_id is missing!!!!!!!!\n"));
ERRLOG("Authorize::preview_id is missing!!!!!!!!\n");
	}

        if(GetField_CString(hRequest,"report_date",&csReportDate)){
DEBUGLOG(("Authorize::report_date= [%s]\n",csReportDate));
        }

        if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call offline_payout_generate\n"));
		sprintf(csCmd,"offline_payout_generate.exec -p %s -o %d -u %s &",csPreviewId,iOnlinePayout,csUser);
		system(csCmd);
	}

        if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }

DEBUGLOG(("TxnOmtByUsOPG Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
