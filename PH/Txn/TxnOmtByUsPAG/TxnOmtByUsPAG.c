/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/29              Elvis Wong
Get pregen info by action_id                       2017/07/06              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsPAG.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);
//OBJPTR(BO);


void TxnOmtByUsPAG(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	int	iOnlinePayout = PD_FALSE;

	char    *csActionId= strdup("");        
	char    *csMerchantId = NULL;
        char    *csUser = NULL;
        char    *csTmp = NULL;

	char    csCmd[PD_TMP_BUF_LEN*2+1];

DEBUGLOG(("Authorize\n"));

	// Check Payout Action Read Only (Offline)
DEBUGLOG(("Authorize::Call DBPayoutActionLock::CheckTheActionCtl_ReadOnly\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","CheckTheActionCtl_ReadOnly");
	iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
	if (iRet != PD_OK) {
		iRet = INT_OTHER_PAYOUT_PROCESSING;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::Call DBPayoutActionLock::CheckTheActionCtl_ReadOnly Failed!!\n"));
	}

/* action_id */
      	if (GetField_CString(hRequest, "action_id", &csActionId)) {
DEBUGLOG(("Authorize::action_id = [%s]\n", csActionId));
    	} else {
DEBUGLOG(("Authorize:action_id not found!!\n"));
ERRLOG("TxnOmtByUsPAG::Authorize::action_id not found!!\n");
          	iRet = INT_BATCH_ID_NOT_FOUND;
            	PutField_Int(hContext,"internal_error",iRet);
        }
	
/* merchant_id */
	if (iRet == PD_OK) {
        	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));

DEBUGLOG(("Authorize::Call DBRulePayoutOnlineMode::ChkRuleExistsByMerchant\n"));
			DBObjPtr = CreateObj(DBPtr,"DBRulePayoutOnlineMode","ChkRuleExistsByMerchant");
			if ((unsigned long)(DBObjPtr)(csMerchantId) == PD_FOUND) {
				//PutField_Int(hContext,"online_payout",PD_TRUE);
				iOnlinePayout = PD_TRUE;
			}
		}
        }

/* ip_addr */
        if (iRet == PD_OK) {
                if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
DEBUGLOG(("Authorize::ip_addr = [%s]\n", csTmp));
                }
        }

/* user */
        if (iRet == PD_OK) {
                if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize::add_user = [%s]\n", csUser));
                } else {
DEBUGLOG(("Authorize:: add_user not found!!\n"));
ERRLOG("TxnOmtByUsPAG: Authorize:: add_user not found!!\n");
                        iRet = INT_USER_NOT_FOUND;
                        PutField_Int(hContext,"internal_error",iRet);
                }
        }

	// Call Offline Payout Api Generate (Background)
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::call offline_payout_api_generate\n"));
		sprintf(csCmd,"offline_payout_api_generate.exec -a %s -o %d -u %s &",csActionId,iOnlinePayout,csUser);
		system(csCmd);
	}
	
	FREE_ME(csActionId);

DEBUGLOG(("TxnOmtByUsPAG Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}

