/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/06              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsREM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"



char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsREM(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csTmp;
	char*	csDate;
	char*	csPspId;
	char*	csChannelCode;
	char*   csCode;
	char*   csValue;
	char    csCmd[PD_TMP_BUF_LEN+1];
	csChannelCode= (char*) malloc (128);

	hash_t *hRec, *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn,0);
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hRequest,"psp_id",&csPspId)){
DEBUGLOG(("Authorize: psp_id [%s]\n",csPspId));
	}

	if(GetField_CString(hRequest,"txn_date",&csDate)){
DEBUGLOG(("Authorize: txn_date [%s]\n",csDate));
	}


	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTEODDATE")) {
DEBUGLOG(("Authorize::current EOD DATE = [%s]\n",csValue));
						break;
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
	else {
		iRet = INT_ERR;
ERRLOG("TxnMgtByUsREM::Authorize:Unable to find EOD DATE\n");
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
		if ((unsigned long)(*DBObjPtr)(csPspId,hTxn) == PD_OK) {
			if (GetField_CString(hTxn,"psp_channel_code",&csTmp)) {
DEBUGLOG(("Authorize: channel_code  = [%s]\n",csTmp));
				U2L(csTmp,strlen(csTmp),csChannelCode);
			}
		}
		else{
			iRet = INT_ERR;
ERRLOG("TxnMgtByUsREM::Authorize: Unable to find channel code\n");
		}
	}

	if(iRet==PD_OK){
		if(!strncmp(csValue,csDate,PD_DATE_LEN)){
			sprintf(csCmd,"extract_%s_data.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
			sprintf(csCmd,"match_%s_dsp.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
			sprintf(csCmd,"%s_to_cms_report.sh",csChannelCode);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
		}
		else{
			sprintf(csCmd,"extract_%s_data_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
			sprintf(csCmd,"match_%s_dsp_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
			sprintf(csCmd,"%s_to_cms_report_by_date.sh %s",csChannelCode,csDate);
DEBUGLOG(("Authorize: run command = [%s]\n",csCmd));
			system(csCmd);
		}

	}	


	FREE_ME(hTxn);
	FREE_ME(csChannelCode);
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);


DEBUGLOG(("TxnMgtByUsREM Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
