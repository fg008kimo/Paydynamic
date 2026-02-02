/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/28              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "ATCChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"
#include "dbutility.h"
#include "langconvert.h"

char cDebug;

void ATCChannel(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(Msg);
OBJPTR(BO);
OBJPTR(DB);

int process_txn(hash_t *hContext,
		const hex_t *inMsg,
		hex_t *outMsg)
{
	int iRet = PD_OK;
	hash_t *hRequest;
	char *csBaidTxnId;
	int iTmpRet;

DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	if (iRet == PD_OK) {
DEBUGLOG(("process_txn: Call AtcMsg [%d]\n", inMsg->len));
		MsgObjPtr = CreateObj(MsgPtr, "AtcMsg", "BreakDownMsg");
		if ((*MsgObjPtr)(hRequest, inMsg->msg, inMsg->len) != PD_OK) {
			iRet = PD_ERR;
DEBUGLOG(("process_txn: BreakDown AtcMsg Error\n"));
ERRLOG("ATCChannel: process_txn: BreakDown AtcMsg Error\n");
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "baid_txn_id", &csBaidTxnId)) {
DEBUGLOG(("process_txn: baid_txn_id = [%s]\n", csBaidTxnId));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("process_txn: Cannot Get Baid Txn ID\n"));
ERRLOG("ATCChannel: process_txn: Cannot Get Baid Txn ID\n");
		}
	}

	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr, "BOOLStmtEngine", "ProcessUnknownMatching");
		iTmpRet = (unsigned long)(*BOObjPtr)(hRequest);
		if (iTmpRet == PD_FOUND) {
			iRet = PD_OK;
		} else {
			iRet = PD_ERR;
		}
	}

	hash_destroy(hRequest);
	FREE_ME(hRequest);

DEBUGLOG(("process_txn: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

