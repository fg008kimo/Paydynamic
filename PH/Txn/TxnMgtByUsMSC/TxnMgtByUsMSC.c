/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/03/03              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMSC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsMSC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iTmpRet = PD_OK;
	int	iCnt = 0,i;
	//char	*csIP;
	char	*csUser;
	char	csTag[PD_TAG_LEN +1];
	char	*csPtr;
	char	*csCustId;
	//char	*csPspTxnDate;
	int	iChgHistorical = PD_FALSE;
	  
	hash_t	*hReq;//, *hRsp;
DEBUGLOG(("Authorize::()\n"));

	if (GetField_CString(hRequest,"add_user",&csUser)) {
DEBUGLOG(("Authorize::() user = [%s]\n",csUser));
	}

	if (GetField_CString(hRequest,"chg_his",&csPtr)) {
		iChgHistorical = atoi(csPtr);
DEBUGLOG(("Authorize::() is_change_historical = [%d]\n",iChgHistorical));
	}

	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
		PutField_Int(hResponse,"total_cnt",iCnt);
DEBUGLOG(("Authorize::() total_cnt = [%d]\n",iCnt));
		for (i = 0; i< iCnt; i++) {
			sprintf(csTag,"%s_custid_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csCustId)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csCustId));
        			hReq = (hash_t*) malloc (sizeof(hash_t));
        			hash_init(hReq,0);

				PutField_Int(hReq,"is_change_his",iChgHistorical);
				PutField_CString(hReq,"customer_tag", csCustId);
				PutField_CString(hReq,"update_user",csUser);

				sprintf(csTag,"%s_mid_%d",PD_DETAIL_TAG,i+1);
				if(GetField_CString(hRequest,csTag,&csPtr)){
					 PutField_CString(hReq, "merchant_id", csPtr);
				}

				sprintf(csTag,"%s_fr_grp_%d",PD_DETAIL_TAG,i+1);
				if(GetField_CString(hRequest,csTag,&csPtr)){
					 PutField_CString(hReq, "from_customer_group", csPtr);
				}

				sprintf(csTag,"%s_to_grp_%d",PD_DETAIL_TAG,i+1);
				if(GetField_CString(hRequest,csTag,&csPtr)){
					 PutField_CString(hReq, "to_customer_group", csPtr);
				}

				BOObjPtr = CreateObj(BOPtr,"BOCustomerGroup","ChangeGroup");
				iTmpRet = (unsigned long) (*BOObjPtr)(hReq);
DEBUGLOG(("Authorize::() ChangeGroup for [%s], iRet = [%d]\n",csCustId,iTmpRet));


				sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iTmpRet));
				PutField_Int(hResponse,csTag,iTmpRet);
				
        			FREE_ME(hReq);
			}
		}
	}
	else {
		iRet = INT_FORMAT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
DEBUGLOG(("TxnMgtByUsMSC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
