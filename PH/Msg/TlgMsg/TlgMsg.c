/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version (Clone from OLN)                      2017/05/15              Dirk Wong
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TlgMsg.h"
#include "common.h"
#include "utilitys.h"
#include "b64.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"

char	cDebug;

OBJPTR(Msg);
OBJPTR(DB);

void	TlgMsg(char cdebug)
{
	cDebug = cdebug;
}


int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	
	char    *csPtr;
	char    *csTag;
	char    *csTmp;
        hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

        if (Str2Cls(hRec,(char*)inMsg,MY_TLG_TOKEN, MY_TLG_FIELD_TOKEN) == PD_OK) {	
		csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
		csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);

/* rtn_enc_tid */
		if (GetField_CString(hRec,"rtn_enc_tid",&csPtr)) {
                        PutField_CString(hOut,"rtn_enc_tid",csPtr);
DEBUGLOG(("BreakDownMsg:: rtn_enc_tid = [%s]\n",csPtr));
                }

/* rd_domain */
		if (GetField_CString(hRec,"rd_domain",&csPtr)) {
                        PutField_CString(hOut,"rd_domain",csPtr);
DEBUGLOG(("BreakDownMsg:: rd_domain = [%s]\n",csPtr));
                }

/* client_ipaddr */
		if (GetField_CString(hRec,"client_ipaddr",&csPtr)) {
                        PutField_CString(hOut,"client_ipaddr",csPtr);
DEBUGLOG(("BreakDownMsg:: client_ipaddr = [%s]\n",csPtr));
                }

/* rcv_ts */
		if (GetField_CString(hRec,"rcv_ts",&csPtr)) {
                        PutField_CString(hOut,"rcv_ts",csPtr);
DEBUGLOG(("BreakDownMsg:: rcv_ts = [%s]\n",csPtr));
                }

		FREE_ME(csTag);
		FREE_ME(csTmp);
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
                iRet = PD_ERR;
        }

        hash_destroy(hRec);
        FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));

	return iRet;
}
