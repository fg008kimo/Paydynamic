/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/20              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOReport.h"

char    cDebug;

void BOReport(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(DB);


int GetPspDepositTxn(const char* csPspId,
		     const char* csTxnDate,
		     recordset_t* myRec)
{
        int     iRet = PD_OK;
	
DEBUGLOG(("BOReport: GetPspDepositTxn - psp_id = [%s]\n",csPspId));
DEBUGLOG(("BOReport: GetPspDepositTxn - txn_date= [%s]\n",csTxnDate));

/* Get Txn PSP Detail */
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetPspReportDetail");
		iRet = (unsigned long)(*DBObjPtr)(csPspId,csTxnDate,myRec);
		
	}

DEBUGLOG(("BOReport: GetPspDepositTxn: Normal exit = [%d]\n",iRet));
	return iRet;
}


int GetEODMatchJobId(const unsigned char* csPspId,
		     hash_t* hRec)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csChannel = strdup("");
	char	*csjob = strdup("");
	char	*csjobId = strdup("");
	int	iJobCnt = 2;

	DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
	if ((*DBObjPtr)(csPspId,hRec) == PD_OK) {
		if (GetField_CString(hRec,"psp_channel_code",&csPtr)) {
DEBUGLOG(("BOReport: GetPspDetail - channel_code  = [%s]\n",csPtr));
			U2L(csPtr,strlen(csPtr),csChannel);
DEBUGLOG(("BOReport: GetPspDetail - channel_code  = [%s]\n",csChannel));
		}
		else {
DEBUGLOG(("BOReport: GetPspDetail - channel_code not found\n"));
			iRet = INT_ERR;
		}
	}

	if(iRet==PD_OK){
		sprintf(csJob,"extract_%s_data.sh",csChannel);
		PutField_CString(hRec,"script_1",csJob);
		sprintf(csJob,"match_%s_dsp.sh",csChannel);
		PutField_CString(hRec,"script_2",csJob);

		for(i=1;i<=iJobCnt;i++){
			DBObjPtr = CreateObj(DBPtr,"DBEODJobs","GetJobId");
			if ((*DBObjPtr)(hRec,csJobId) == PD_OK) {
			}
		}
	}


	FREE_ME(csChannel);
	FREE_ME(csJob);
	FREE_ME(csJobId);
	return iRet;
}
