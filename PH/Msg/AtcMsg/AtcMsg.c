/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/28              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AtcMsg.h"
#include "common.h"
#include "utilitys.h"
#include "b64.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"

char cDebug;

void AtcMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr;

DEBUGLOG(("FormatMsg\n"));

	outMsg[0] = '\0';
	*outLen = 0;

	if (GetField_CString(hIn, "baid_txn_id", &csPtr)) {
DEBUGLOG(("FormatMsg: baid_txn_id = [%s]\n", csPtr));
		strcat((char*)outMsg, "baid_txn_id");
		strcat((char*)outMsg, MY_ATC_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_ATC_TOKEN);
	}

	*outLen = strlen((const char*)outMsg);
	DEBUGLOG(("FormatMsg: outMsg = [%s] outLen = [%d]\n", outMsg, *outLen));

DEBUGLOG(("FormatMsg: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int iRet = PD_OK;
	char *csPtr;
	hash_t *hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownMsg\n"));
DEBUGLOG(("BreakDownMsg: DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char*)inMsg, MY_ATC_TOKEN, MY_ATC_FIELD_TOKEN) == PD_OK) {
/* statement transaction id */
		if (GetField_CString(hRec, "baid_txn_id", &csPtr)) {
			PutField_CString(hOut, "baid_txn_id", csPtr);
DEBUGLOG(("BreakDownMsg: baid_txn_id = [%s]\n", csPtr));
		}
	} else {
DEBUGLOG(("BreakDownMsg: Error\n"));
ERRLOG("AtcMsg: BreakDownMsg: Error\n");
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
