/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/02/17              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUsIPI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmsByUsIPI(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	cBusinessType;
	char	*csTmp;
        char    csTag[PD_TAG_LEN +1];

        hash_t *hRec;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


        if (GetField_Char(hRequest, "business_type", &cBusinessType)) {
DEBUGLOG(("Authorize::business_type = [%c]\n",cBusinessType));
        }
        else {
DEBUGLOG(("Authorize::business_type not found!!\n"));
ERRLOG("TxnMmsByUsIPI::Authorize::business_type not found!!\n");
                iRet = INT_ERR;

		PutField_Int(hContext,"internal_error",iRet);
        }


DEBUGLOG(("Authorize::Call DBPspDetail: GetPspDetailByType\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetailByType");
	if ((unsigned long)((*DBObjPtr)(cBusinessType, rRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBPspDetail:GetPspDetailByType Failed!!\n"));
ERRLOG("TxnMmsByUsIPI::Authorize::DBPspDeail:GetPspDetailByType Failed!!\n");
		iRet = INT_ERR;
	}
	else {
		int	iTmp = 0;

		hRec = RecordSet_GetFirst(rRecordSet);
		while (hRec) {

			iTmp++;

			if (GetField_CString(hRec, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize::DBPspDetail [%d] psp_id = [%s]\n", iTmp, csTmp));

        			memset(csTag, 0, sizeof(csTag));
				sprintf(csTag,"party_id_%d",iTmp);
				PutField_CString(hResponse, csTag, csTmp);
			}

			if (GetField_CString(hRec, "psp_name", &csTmp)) {
DEBUGLOG(("Authorize::DBPspDetail [%d] psp_name = [%s]\n", iTmp, csTmp));
			
				memset(csTag, 0, sizeof(csTag));	
				sprintf(csTag, "party_name_%d", iTmp);
				PutField_CString(hResponse, csTag, csTmp);
			}

			PutField_Int(hResponse,"total_cnt",iTmp);

			hRec = RecordSet_GetNext(rRecordSet);
		} 
	}


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);


DEBUGLOG(("TxnMmsByUsIPI Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
