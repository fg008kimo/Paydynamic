/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/04/28              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsATM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

void TxnOmtByUsATM(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(Msg);

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csTxnSeq;
	long lKey;
	hex_t *h_msg;
	struct msg_t *msg;
	int iSendLen;

DEBUGLOG(("Authorize\n"));

	if (GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authorize: txn_seq = [%s]\n", csTxnSeq));
	} else {
DEBUGLOG(("Authorize: txn_seq not found\n"));
ERRLOG("TxnOmtByUsATM: Authorize: txn_seq not found\n");
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
		hash_t *hReq;
		hReq = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hReq, 0);

/* statement transaction id */
		PutField_CString(hReq, "stmt_txn_id", csTxnSeq);

/* Request Host Queue */
		lKey = GetMQKey((const unsigned char *)"ATMREQQ");

		h_msg = (hex_t*) malloc (sizeof(hex_t));
		MsgObjPtr = CreateObj(MsgPtr, "AtmMsg", "FormatMsg");
		if ((*MsgObjPtr)(hReq, h_msg->msg, &h_msg->len) == PD_OK) {
DEBUGLOG(("Authorize: h_msg->msg = [%s] h_msg->len = [%d]\n", h_msg->msg, h_msg->len));
			msg = (struct msg_t*) malloc (sizeof(struct msg_t) + MAX_MSG_SIZE);
			msg->mtype = ctol((const unsigned char *)csTxnSeq, strlen(csTxnSeq));
			memset(msg->mtext, 0, sizeof(msg->mtext));
			MQ_build_header((unsigned char*)msg->mtext,
				MQ_REQ,
				"ATM",
				0,
				"ATMRSPQ",
				0);
DEBUGLOG(("Authorize: msg->mtext = [%s]\n", msg->mtext));
			memcpy(&msg->mtext[MQ_HEADER_LEN], h_msg->msg, h_msg->len);
			msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
			iSendLen = MQ_HEADER_LEN + h_msg->len;
DEBUGLOG(("Authorize: Request Queue = [ATMREQQ]\n"));
			if (MQSend(lKey, msg, iSendLen) != MQ_OK) {
DEBUGLOG(("Authorize: Sent Error\n"));
ERRLOG("TxnOmtByUsATM: Authorize: Sent Error\n");
				iRet = PD_ERR;
			}
			FREE_ME(msg);
		} else {
DEBUGLOG(("Authorize: call AtmMsg:FormatMsg() failed\n"));
ERRLOG("TxnOmtByUsATM: Authorize: call AtmMsg:FormatMsg() failed\n");
			iRet = PD_ERR;
		}
		FREE_ME(h_msg);

		hash_destroy(hReq);
		FREE_ME(hReq);
	}

DEBUGLOG(("Authorize: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
