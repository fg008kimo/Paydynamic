/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/03              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsOnUsSYN.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);

void TxnMmsOnUsSYN(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csPtr;
	hash_t	*hData;

DEBUGLOG(("Authorize()\n"));
	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

/* req_node_id */
	if (GetField_CString(hRequest,"req_node_id",&csPtr)) {
DEBUGLOG(("Authorize: req_node_id = [%s]\n",csPtr));
		PutField_CString(hData,"node_id",csPtr);
	}

/* client_id */
	if (GetField_CString(hRequest,"client_id",&csPtr)) {
DEBUGLOG(("Authorize: client_id = [%s]\n",csPtr));
		PutField_CString(hData,"client_id",csPtr);
	}

/* psp_id */
	if (GetField_CString(hRequest,"psp_id",&csPtr)) {
DEBUGLOG(("Authorize: psp_id = [%s]\n",csPtr));
		PutField_CString(hData,"psp_id",csPtr);
	}

/* baid */
	if (GetField_CString(hRequest,"baid",&csPtr)) {
DEBUGLOG(("Authorize: baid = [%s]\n",csPtr));
		PutField_CString(hData,"baid",csPtr);
	}

/* client_name */
	if (GetField_CString(hRequest,"client_name",&csPtr)) {
DEBUGLOG(("Authorize: client_name = [%s]\n",csPtr));
		PutField_CString(hData,"client_name",csPtr);
	}

/* psp_name */
	if (GetField_CString(hRequest,"psp_name",&csPtr)) {
DEBUGLOG(("Authorize: psp_name = [%s]\n",csPtr));
		PutField_CString(hData,"psp_name",csPtr);
	}

/* baid_name */
	if (GetField_CString(hRequest,"baid_name",&csPtr)) {
DEBUGLOG(("Authorize: baid_name = [%s]\n",csPtr));
		PutField_CString(hData,"baid_name",csPtr);
	}

/* country */
	if (GetField_CString(hRequest,"country",&csPtr)) {
DEBUGLOG(("Authorize: country = [%s]\n",csPtr));
		PutField_CString(hData,"country",csPtr);
	}

	PutField_CString(hData,"create_user",PD_UPDATE_USER);

	DBObjPtr = CreateObj(DBPtr,"DBMmsEntityPsp","Sync");
        iRet = (unsigned long) (*DBObjPtr)(hData);

	FREE_ME(hData);
DEBUGLOG(("TxnMmsOnUsSYN Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
