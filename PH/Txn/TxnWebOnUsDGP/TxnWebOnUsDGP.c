/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/16              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsDGP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(DB);
void TxnWebOnUsDGP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*	csPtr;
	hash_t  *hTxn;


DEBUGLOG(("TxnWebOnUsDGP Authorize\n"));

	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

/* service_code */
	if (GetField_CString(hRequest,"service_code",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsDGP service_code = [%s]\n",csPtr));
		PutField_CString(hTxn,"service_code",csPtr);

		PutField_CString(hResponse, "service_code", csPtr);
	}
	else {
DEBUGLOG(("TxnWebOnUsDGP service_code is missing\n"));
		iRet = INT_FORMAT_ERR;
	}

/* key_id */
	if (GetField_CString(hRequest,"key_id",&csPtr) && iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsDGP key_id = [%s]\n",csPtr));
		PutField_CString(hTxn,"client_id",csPtr);
	}
	else {
DEBUGLOG(("TxnWebOnUsDGP key_id is missing\n"));
		iRet = INT_FORMAT_ERR;
	}

	if(GetField_CString(hRequest,"vp_txn_gp_id",&csPtr)  && iRet == PD_OK){
DEBUGLOG(("TxnWebOnUsDGP vp_txn_gp_id = [%s]\n",csPtr));
		PutField_Int(hTxn,"txn_gp_id",atoi(csPtr));
	}


	PutField_CString(hTxn, "create_user", PD_UPDATE_USER);
	PutField_Char(hTxn, "status", PD_VP_CLOSE);


	if (iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsDGP Call DBClientMagicGpStatus::Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBClientMagicGpStatus","Add");
		iRet = (unsigned long)(*DBObjPtr)(hTxn);
	}

	hash_destroy(hTxn);
        FREE_ME(hTxn);

DEBUGLOG(("TxnWebOnUsDGP Authorize iRet = [%d]\n",iRet));
	return iRet;
}
