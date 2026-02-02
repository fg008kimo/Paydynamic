/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version (Clone from OPL)                      2017/05/15              Dirk Wong

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnTlgOnUsCOM.h"
#include "myrecordset.h"
#include <math.h>
#include <ctype.h>

#define PD_MAX_NON_ASCII_CHAR 5

char cDebug;

void TxnTlgOnUsCOM(char    cdebug)
{
        cDebug = cdebug;
}

OBJPTR(DB);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iLen;
	char	*csTmp;
	char	*csEncTmp;
	char	*csPtr;

	hash_t	*hRDLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRDLog,0);

DEBUGLOG(("TxnTlgOnUsCOM: Authroize()\n"));	


/* field checking */


//rtn_enc_tid  
	if (GetField_CString(hRequest,"rtn_enc_tid",&csEncTmp)) {
DEBUGLOG(("Authorize:: rtn_enc_tid = [%s]\n",csEncTmp));
		csPtr = (char*) malloc (PD_TXN_SEQ_LEN);
		memset(csPtr,0,PD_TXN_SEQ_LEN+1);
		iLen = base64_decode(csEncTmp,(unsigned char*)csPtr,PD_TXN_SEQ_LEN);
		PutField_CString(hRDLog,"rtn_tid",csPtr);
DEBUGLOG(("Authorize:: rtn_tid = [%s]\n",csPtr));

		FREE_ME(csPtr);
	} 


//rd_domain 
	if (GetField_CString(hRequest,"rd_domain",&csTmp)) {
		PutField_CString(hRDLog,"rd_domain",csTmp);
DEBUGLOG(("Authorize:: rd_domain = [%s]\n",csTmp));
	}


//client_ipaddr 
	if (GetField_CString(hRequest,"client_ipaddr",&csTmp)) {
		PutField_CString(hRDLog,"client_ipaddr",csTmp);
DEBUGLOG(("Authorize:: client_ipaddr = [%s]\n",csTmp));
	}


//rcv_ts 
	if (GetField_CString(hRequest,"rcv_ts",&csTmp)) {
		PutField_CString(hRDLog,"rcv_ts",csTmp);
DEBUGLOG(("Authorize:: rcv_ts = [%s]\n",csTmp));
	}


//create_user ('SYSTEM')
	PutField_CString(hRDLog,"create_user",PD_UPDATE_USER);
DEBUGLOG(("Authorize:: create_user= [%s]\n",PD_UPDATE_USER));


//Call DBPspRedirectLog:Add
DEBUGLOG(("Call DBPspRedirectLog:Add\n"));
	DBObjPtr = CreateObj(DBPtr,"DBPspRedirectLog","Add");
	iRet = (unsigned long)((*DBObjPtr)(hRDLog));

	if (iRet == PD_OK) {
DEBUGLOG(("  return SUCCESS!\n"));
	} else {
DEBUGLOG(("  FAILED, iRet = [%d]\n",iRet));
	}

	hash_destroy(hRDLog);
	FREE_ME(hRDLog);

DEBUGLOG(("TxnTlgOnUsCOM:: exit = [%d]\n",iRet));
	return iRet;
}
