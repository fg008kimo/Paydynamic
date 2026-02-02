/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/11/19              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsRCK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
#define	PD_RETRY	'R'

OBJPTR(DB);
void TxnWebByUsRCK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csOrgTxnSeq;
	char	csDateTime[PD_DATETIME_LEN + 1];
	char	csDate[PD_DATE_LEN +1];
	char	csTime[PD_TIME_LEN +1];
	hash_t  *hReq;

	hReq = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hReq,0);

DEBUGLOG(("TxnWebByUsRCK Authorize()\n"));
	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("TxnWebByUsRCK org_txn_seq = [%s]\n",csOrgTxnSeq));
/* txn_seq */
		PutField_CString(hReq,"txn_seq",csOrgTxnSeq);

/* user */	PutField_CString(hReq,"add_user",PD_UPDATE_USER);


		strcpy(csDateTime,getdatetime());
DEBUGLOG(("TxnWebByUsRCK local transmission date time = [%s]\n",csDateTime));

		memcpy(csDate,csDateTime,PD_DATE_LEN);
		csDate[PD_DATE_LEN] = '\0';
/* tm_date */	PutField_CString(hReq,"local_tm_date",csDate);
DEBUGLOG(("TxnWebByUsRCK local transmission date = [%s]\n",csDate));

		memcpy(csTime,&csDateTime[PD_DATE_LEN],PD_DATE_LEN);
		csTime[PD_TIME_LEN] = '\0';
/* tm_time */	PutField_CString(hReq,"local_tm_time",csTime);
DEBUGLOG(("TxnWebByUsRCK local transmission time = [%s]\n",csTime));

/* status */
		PutField_Char(hReq,"status",PD_RETRY);
		DBObjPtr = CreateObj(DBPtr,"DBTxnAckRetry","Add");
		iRet = (unsigned long) (*DBObjPtr)(hReq);
	}
	else 	
		iRet = INT_ERR;
	
	FREE_ME(hReq);
DEBUGLOG(("TxnWebByUsRCK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
