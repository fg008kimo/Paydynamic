/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    -----------            --------------
Init Version                                       2015/07/30             Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUs2Host.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);

void TxnMmsByUs2Host(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     	iRet = PD_OK;
	char*		csPtr;
	char*		csEntityId;
	char*		csNodeId;

	hash_t*		hData;

DEBUGLOG(("Authorize()\n"));
	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	if (GetField_CString(hContext,"entity_id",&csEntityId)) {
		DBObjPtr = CreateObj(DBPtr,"DBMmsEntityPsp","GetPspEntityIdInfo");
       		iRet = (unsigned long) (*DBObjPtr)(csEntityId,hData);
	}
	else {
DEBUGLOG(("Authorize() enitity id not found\n"));
ERRLOG("TxnMmsByUs2Host:Authorize() enitity id not found\n");
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hData,"node_id",&csNodeId)) {
DEBUGLOG(("Authorize() node_id = [%s]\n",csNodeId));
		}
		else {
DEBUGLOG(("Authorize() node_id not found\n"));
ERRLOG("TxnMmsByUs2Host:Authorize() node_id not found\n");
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK ) {
		PutField_Char(hData,"direction_to",PD_MMS_CLIENT);
		PutField_CString(hData,"node_id",csNodeId);
/* txn seq */
		if (GetField_CString(hContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csPtr));
			PutField_CString(hData,"txn_seq",csPtr);
		}
/* status */
		PutField_Char(hData,"status",PD_MMS_SF_RETRY);

		DBObjPtr = CreateObj(DBPtr,"DBMmsStoreForward","Add");
        	iRet = (unsigned long) (*DBObjPtr)(hData);
	}


	FREE_ME(hData);
DEBUGLOG(("Authorize() Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
