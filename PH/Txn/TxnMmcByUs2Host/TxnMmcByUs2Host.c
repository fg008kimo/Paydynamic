/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    -----------            --------------
Init Version                                       2015/06/05             Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUs2Host.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);

void TxnMmcByUs2Host(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     	iRet = PD_OK;
	char*		csCode;
	char*		csValue;
	char*		csTxnCode;
	char*		csPtr;
	char		csMyNode[PD_MMS_NODE_ID_LEN +1];

	hash_t		*hData, *hRec;
	recordset_t     *rRecordSet;

DEBUGLOG(("Authorize()\n"));
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	recordset_init(rRecordSet,0);

        DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","GetAllCodes");
        if ((unsigned long)(DBObjPtr)(rRecordSet) == PD_OK) {
   	     hRec = RecordSet_GetFirst(rRecordSet);
             while (hRec) {
            	if (GetField_CString(hRec,"code",&csCode)) {
                	if (GetField_CString(hRec,"value",&csValue)) {
                        	if (!strcmp(csCode, PD_MMCID)) {
DEBUGLOG(("Authorize()::node id = [%s]\n",csValue));
                               		strcpy(csMyNode,csValue);
                                        PutField_CString(hData,"node_id",csValue);
                                }
                        }
                }
                hRec = RecordSet_GetNext(rRecordSet);
            }
        }
        else {
DEBUGLOG(("Authorize() :NOT RECORD\n"));
       		iRet = PD_ERR;
ERRLOG("TxnMmcByUs2Host::Authorize() Internal Error SystemControl Record Not Found\n");
        }

	if (iRet == PD_OK ) {
/* direction to */
		if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("Authorize() txn_code = [%s]\n",csTxnCode));

			if ((!strcmp(csTxnCode, PD_OFFLINE_SWEEP_IN_TO_POA)) 
			    || (!strcmp(csTxnCode, PD_OFFLINE_SWEEP_IN_TO_ITM))
			    || (!strcmp(csTxnCode, PD_OFFLINE_SWEEP_IN_TO_PDF))	
			)	
			{
				PutField_Char(hData,"direction_to",PD_MMS_CLIENT);
DEBUGLOG(("Authorize() txn_seq = [%c]\n",PD_MMS_CLIENT));
			} else {
				PutField_Char(hData,"direction_to",PD_MMS_SERVER);
DEBUGLOG(("Authorize() txn_seq = [%c]\n",PD_MMS_SERVER));
			}
		} else {
			PutField_Char(hData,"direction_to",PD_MMS_SERVER);
DEBUGLOG(("Authorize() txn_seq = [%c]\n",PD_MMS_SERVER));
		}
/* txn seq */
		if (GetField_CString(hContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csPtr));
			PutField_CString(hData,"txn_seq",csPtr);
		}
/* status */
		PutField_Char(hData,"status",PD_MMS_SF_RETRY);
DEBUGLOG(("Authorize() status = [%c]\n",PD_MMS_SF_RETRY));

		DBObjPtr = CreateObj(DBPtr,"DBMmsStoreForward","Add");
        	iRet = (unsigned long) (*DBObjPtr)(hData);
	}


	FREE_ME(rRecordSet);
	FREE_ME(hData);
DEBUGLOG(("Authorize() Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
