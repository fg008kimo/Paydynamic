/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/14              LokMan Chow
Add DBPayoutActionLock
only allow one preview/generate in the same time   2015/09/21		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsPOP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define       PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnOmtByUsPOP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        char    *csTmp;
	int	i = 0;
	int	iCnt = 0;
	char	csTag[PD_TAG_LEN+1];
	char	cGrp;

DEBUGLOG(("Authorize\n"));

DEBUGLOG(("Call DBPayoutActionLock::CheckTheActionCtl\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","CheckTheActionCtl");
        iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
	if(iRet==PD_OK){
DEBUGLOG(("Call DBPayoutActionLock::TakeTheActionCtl\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","TakeTheActionCtl");
		iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
	}

        if(iRet!=PD_OK){
		iRet = INT_OTHER_PAYOUT_PROCESSING;
		PutField_Int(hResponse,"preview_id",0);
		PutField_Int(hResponse,"total_cnt",0);
DEBUGLOG(("Call DBPayoutActionLock::TakeTheActionCtl Failed!!\n"));
	}
	else{
		TxnCommit();
	}


	if(GetField_CString(hRequest,"merchant_id",&csTmp)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csTmp));
        }

	if(GetField_CString(hRequest,"date",&csTmp)){
DEBUGLOG(("Authorize::approve date = [%s]\n",csTmp));
        }

	if(GetField_CString(hRequest,"po_grp",&csTmp)){
		cGrp = csTmp[0];
		PutField_Char(hContext,"psp_group",cGrp);
DEBUGLOG(("Authorize::psp_group = [%c]\n",cGrp));
        }

	if(GetField_Int(hContext, "total_cnt", &iCnt)){
		PutField_Int(hContext,"total_batch_cnt",iCnt);
DEBUGLOG(("Authorize::batch_cnt = [%d]\n", iCnt));
		for (i = 0; i < iCnt; i++) {
			sprintf(csTag, "%s_batchid_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));
				sprintf(csTag, "batch_id_%d",i);
				PutField_CString(hContext,csTag,csTmp);
			}
		}
	}
        
        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOOLPayout->ProcessPayoutTxn\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLPayout","ProcessPayoutTxn");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
	}

        if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }

	if(iRet!=INT_OTHER_PAYOUT_PROCESSING){	
DEBUGLOG(("Call DBPayoutActionLock::ReleaseTheActionCtl\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPayoutActionLock","ReleaseTheActionCtl");
		iRet = (unsigned long)(*DBObjPtr)(PD_OFFLINE);
DEBUGLOG(("DBPayoutActionLock::ReleaseTheActionCtl iRet = [%d]\n",iRet));
	}

DEBUGLOG(("TxnOmtByUsPOP Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
