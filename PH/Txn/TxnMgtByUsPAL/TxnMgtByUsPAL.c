/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/10/18             Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPAL.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(Txn);

void TxnMgtByUsPAL(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	char*   csHandler = NULL;
        int     iRet = PD_OK;
	char*	csTmp = NULL;
	char*	csPspId = NULL;
	hash_t	*hReq,*hRps;

	hReq = (hash_t*) malloc (sizeof(hash_t));
	hRps = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hReq,0);
	hash_init(hRps,0);

	//double	dTmp;

DEBUGLOG(("TxnMgtByUsPAL: Authroize()\n"));

/* txn_code */
	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("TxnMgtByUsPAL: txn_code = [%s]\n",csTmp));
		PutField_CString(hReq,"txn_code",csTmp);
	}

/* access_key */
	if (GetField_CString(hContext,"psp_key",&csTmp)) {
DEBUGLOG(("TxnMgtByUsPAL: access_key = [%s]\n",csTmp));
		PutField_CString(hReq,"access_key",csTmp);
	}


/* psp id */
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("TxnMgtByUsPAL: psp_id = [%s]\n",csPspId));
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnMgtByUsPAL can't find PSP ID\n");
		iRet = INT_ERR;
	}
	if (iRet == PD_OK) {
        	csHandler = (char*) malloc (20);
        	sprintf(csHandler,"TxnWebOnUs2%s",csPspId);
DEBUGLOG(("TxnMgtByUsPAL Txn Object [%s]\n",csHandler));
        	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
        	FREE_ME(csHandler);
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hReq,hRps);
DEBUGLOG(("iRet = [%d]\n",iRet));	
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMgtByUsPAL Format Sucess Resp\n"));
		if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
			PutField_CString(hResponse,"local_tm_date",csTmp);
DEBUGLOG(("TxnMgtByUsPAL Format local_tm_date = [%s]\n",csTmp));
		}
	}

	FREE_ME(csTmp);
	FREE_ME(csPspId);
	
	hash_destroy(hReq);
	hash_destroy(hRps);
	FREE_ME(hReq);
	FREE_ME(hRps);
DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
