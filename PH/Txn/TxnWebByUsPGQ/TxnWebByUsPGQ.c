/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/18		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsPGQ.h"
#include "myrecordset.h"
#include "dbutility.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnWebByUsPGQ(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iTmp=0;
	char	csDateTime[PD_DATETIME_LEN + 1];
	char	csDate[PD_DATE_LEN + 1];
	char	csTime[PD_TIME_LEN + 1];

	char    *csTmp;
	//char    *csPspId;
	
	hash_t	*hRec;
	hash_t  *hUpd;

        hUpd = (hash_t*) malloc (sizeof(hash_t));	
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	PutField_CString(hContext,"txn_code",PD_PAYOUT_GENERATE);
	PutField_CString(hRequest,"txn_code",PD_PAYOUT_GENERATE);
	PutField_CString(hContext,"channel_code",PD_CHANNEL_MGT);

	DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","GetPreGenHeader");
        if ((*DBObjPtr)(PD_PAYOUTFILE_WAITING_GENERATE,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while ((hRec) && (iRet==PD_OK)) {
DEBUGLOG(("TxnWebByUsPGQ GetPreGenHeader OK\n"));
                        if (GetField_CString(hRec,"file_id",&csTmp)){
DEBUGLOG(("TxnWebByUsPGQ file_id = [%s]\n",csTmp));
				hash_init(hUpd,0);
				PutField_Int(hUpd,"status",PD_PAYOUTFILE_PROCESSING_GENERATE);
				PutField_CString(hUpd,"file_id",csTmp);

				DBObjPtr = CreateObj(DBPtr,"DBPayoutGeneratedFileHD","Update");
				if ((*DBObjPtr)(hUpd) == PD_OK) {

					if(GetField_CString(hRec,"file_date",&csTmp)){
						PutField_CString(hContext,"PHDATE",csTmp);
					}
					
					//get current datetime
					strcpy(csDateTime,getdatetime());
					sprintf(csDate,"%.*s",PD_DATE_LEN,csDateTime);
					sprintf(csTime,"%.*s",PD_TIME_LEN,&csDateTime[PD_DATE_LEN]);
					PutField_CString(hContext,"local_tm_date",csDate);
					PutField_CString(hContext,"local_tm_time",csTime);

					//Call handle_PayoutGenerate 
DEBUGLOG(("TxnWebByUsPGQ::call handle_PayoutGenerate\n"));
					BOObjPtr = CreateObj(BOPtr,"BOPayout","handle_PayoutGenerate");
					iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);

				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnWebByUsPGQ DBPayoutGeneratedFileHD:Update file[%d] Failed!!!!!!!\n",iTmp));
				}
				hash_destroy(hUpd);
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }


	FREE_ME(hUpd);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
DEBUGLOG(("TxnWebByUsPGQ Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
