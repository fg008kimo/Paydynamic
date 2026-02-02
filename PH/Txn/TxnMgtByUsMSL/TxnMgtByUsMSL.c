/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/03/13              LokMan Chow
Add alert email					   2015/03/30		   LokMan Chow
Add checking for customer count			   2015/04/21		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsMSL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsMSL(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csUser;
	char	*csPtr;
	char	*csGroup;
	int	iIsExceedAmt = PD_FALSE;
	int	iIsExceedCnt = PD_FALSE;
	int	iOrgIsExceedAmt = PD_FALSE;
	int	iOrgIsExceedCnt = PD_FALSE;
	int	iTmp = 0;
	double	dTmp = 0.0;
	int	iExCnt = PD_FALSE;
	int	iExAmt = PD_FALSE;
	char    csCmd[PD_MAX_FILE_LEN + 1];
	int	iCustCnt = 0;
	double	dAmtLimit = 0.0;
	int	iNewCustCnt = 0;
	  
	hash_t	*hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);

DEBUGLOG(("Authorize::()\n"));

	if (GetField_CString(hRequest,"add_user",&csUser)) {
		PutField_CString(hTxn,"update_user",csUser);
DEBUGLOG(("Authorize::() user = [%s]\n",csUser));
	}
	else{
		iRet = INT_INVALID_TXN;
DEBUGLOG(("Authorize::() user is missing!!!\n"));
	}

	if (GetField_CString(hRequest,"group",&csGroup)) {
DEBUGLOG(("Authorize::() group = [%s]\n",csGroup));
	}
	else{
		iRet = INT_INVALID_TXN;
DEBUGLOG(("Authorize::() group is missing!!!\n"));
	}

	if (GetField_CString(hRequest,"exceed_amt",&csPtr)) {
		iIsExceedAmt = atoi(csPtr);
		PutField_Int(hTxn,"is_exceed_amt",iIsExceedAmt);
DEBUGLOG(("Authorize::() exceed_amt = [%d]\n",iIsExceedAmt));
	}

	if (GetField_CString(hRequest,"amt_limit",&csPtr)) {
		sscanf(csPtr,"%lf",&dTmp);
		PutField_Double(hTxn,"amt_limit",dTmp);
DEBUGLOG(("Authorize::() amt_limit = [%lf]\n",dTmp));
	}

	if (GetField_CString(hRequest,"exceed_cnt",&csPtr)) {
		iIsExceedCnt = atoi(csPtr);
		PutField_Int(hTxn,"is_exceed_cnt",iIsExceedCnt);
DEBUGLOG(("Authorize::() exceed_cnt = [%d]\n",iIsExceedCnt));
	}

	if (GetField_CString(hRequest,"cust_cnt",&csPtr)) {
		iNewCustCnt = atoi(csPtr);
		PutField_Int(hTxn,"cust_cnt",iNewCustCnt);
DEBUGLOG(("Authorize::() cust_cnt = [%d]\n",iNewCustCnt));
	}


	if(iRet == PD_OK){
		hash_t	*hSeg;
		hSeg = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hSeg,0);
		DBObjPtr = CreateObj(DBPtr,"DBMobSegmentThreshold","GetThreshold");
		if ((unsigned long)(*DBObjPtr)(csGroup,hSeg) == PD_FOUND) {

			if(GetField_Int(hSeg,"cust_cnt",&iCustCnt)){
DEBUGLOG(("Authorize() org cust_cnt = [%d]\n",iCustCnt));
			}
			if(GetField_Int(hSeg,"is_exceed_cnt",&iOrgIsExceedCnt)){
DEBUGLOG(("Authorize() org is_exceed_cnt = [%d]\n",iOrgIsExceedCnt));
			}
			if(GetField_Double(hSeg,"amt_limit",&dAmtLimit)){
DEBUGLOG(("Authorize() org amt_limit = [%lf]\n",dAmtLimit));
			}
			if(GetField_Int(hSeg,"is_exceed_amt",&iOrgIsExceedAmt)){
DEBUGLOG(("Authorize() org is_exceed_amt = [%d]\n",iOrgIsExceedAmt));
			}
		}
		FREE_ME(hSeg);
	}

	if(iRet == PD_OK){
		if(iIsExceedCnt==PD_FALSE && iOrgIsExceedCnt==PD_TRUE){
			hash_t* hRec;
			recordset_t     *rRecordSet;
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupDetail","GetCustomerCntBySegmentForAllMerchant");
			iRet = (unsigned long)(*DBObjPtr)(csGroup,rRecordSet);
			if(iRet==PD_OK){
				hRec = RecordSet_GetFirst(rRecordSet);
				while(hRec){
					if(GetField_CString(hRec,"merchant_id",&csPtr) &&
					   GetField_Int(hRec,"cust_cnt",&iTmp)){
						if(iTmp>=iNewCustCnt){
							iRet = INT_CUST_CNT_EXCEED_LIMIT;
DEBUGLOG(("HandleMobSegmentThreshold() Customer Count [%d] of Segment [%s] exceed [%d]\n",iTmp,csGroup,iNewCustCnt));
							break;
						}
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}

			RecordSet_Destroy(rRecordSet);
			FREE_ME(rRecordSet);
		}
	}

	if(iRet == PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMobSegmentThreshold","Update");
		iRet = (unsigned long)(*DBObjPtr)(csGroup,hTxn);
DEBUGLOG(("Authorize::() DBMobSegmentThreshold: Update iRet = [%d]\n",iRet));

		if(iRet==PD_OK){
			if(iIsExceedCnt==PD_TRUE && iOrgIsExceedCnt==PD_FALSE)  iExCnt = PD_TRUE;
			if(iIsExceedAmt==PD_TRUE && iOrgIsExceedAmt==PD_FALSE)  iExAmt = PD_TRUE;

			if(iExCnt || iExAmt){
				sprintf(csCmd,"mobile_segment_threshold.sh %s %d %d %s %d %.2f>/dev/null 2>&1",csGroup,iExCnt,iExAmt,csUser,iCustCnt,dAmtLimit);
				system(csCmd);
			}
		}
		
	}

	if(iRet !=PD_OK)
		PutField_Int(hContext,"internal_error",iRet);


	FREE_ME(hTxn);
DEBUGLOG(("TxnMgtByUsMSL Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
