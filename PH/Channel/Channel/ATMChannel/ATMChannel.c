/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/04/25              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "ATMChannel.h"
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

void ATMChannel(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(Msg);
OBJPTR(BO);

int process_txn(hash_t *hContext,
		const hex_t *inMsg,
		hex_t *outMsg)
{
	int iRet = PD_OK;
	hash_t *hRequest;
	char *csStmtTxnId;

DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	if (iRet == PD_OK) {
DEBUGLOG(("process_txn: Call AtmMsg [%d]\n", inMsg->len));
		MsgObjPtr = CreateObj(MsgPtr, "AtmMsg", "BreakDownMsg");
		if ((*MsgObjPtr)(hRequest, inMsg->msg, inMsg->len) != PD_OK) {
			iRet = PD_ERR;
DEBUGLOG(("process_txn: BreakDown AtmMsg Error\n"));
ERRLOG("ATMChannel: process_txn: BreakDown AtmMsg Error\n");
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "stmt_txn_id", &csStmtTxnId)) {
DEBUGLOG(("process_txn: stmt_txn_id = [%s]\n", csStmtTxnId));
		} else {
			iRet = PD_ERR;
DEBUGLOG(("process_txn: Cannot Get Stmt Txn ID\n"));
ERRLOG("ATMChannel: process_txn: Cannot Get Stmt Txn ID\n");
		}
	}

	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr, "BOOLDepositMatch", "ProcessMatching");
		iRet = (unsigned long)(*BOObjPtr)(hRequest);
	}

	hash_destroy(hRequest);
	FREE_ME(hRequest);

DEBUGLOG(("process_txn: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
