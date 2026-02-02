/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsNWM.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);

void TxnWebByUsNWM(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		const hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;

	char *csServiceCode;
	char *csClientId;
	char *csAction;
	char csTmpChannelCode[PD_CHANNEL_CODE_LEN * 2 + 1];
	hex_t *h_msg;
	long lKey;
	struct msg_t* msg;

	hash_t *hRsp;
	hRsp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRsp, 0);

DEBUGLOG(("TxnWebByUsNWM Authorize()\n"));

	/* service_code */
	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "service_code", &csServiceCode)) {
DEBUGLOG(("TxnWebByUsNWM :: service_code = [%s]\n", csServiceCode));
			PutField_CString(hRsp, "service_code", csServiceCode);
		} else {
DEBUGLOG(("TxnWebByUsNWM :: service_code not found\n"));
			iRet = PD_ERR;
		}
	}

	/* client_id */
	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "client_id", &csClientId)) {
DEBUGLOG(("TxnWebByUsNWM :: client_id = [%s]\n", csClientId));
			PutField_CString(hRsp, "key_id", csClientId);
		} else {
DEBUGLOG(("TxnWebByUsNWM :: client_id not found\n"));
			iRet = PD_ERR;
		}
	}

	/* action - enable or disable */
	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "action", &csAction)) {
DEBUGLOG(("TxnWebByUsNWM :: action = [%s]\n", csAction));
			if (!strcmp(csAction, "enable")) {
				PutField_CString(hRsp, "process_type", "0608");
				PutField_CString(hRsp, "process_code", "210001");
			} else if (!strcmp(csAction, "disable")) {
				PutField_CString(hRsp, "process_type", "0608");
				PutField_CString(hRsp, "process_code", "210002");
			} else {
DEBUGLOG(("TxnWebByUsNWM :: unknown action\n"));
				iRet = PD_ERR;
			}
		} else {
DEBUGLOG(("TxnWebByUsNWM :: action not found\n"));
			iRet = PD_ERR;
		}
	}

	/* hard-coded */
	if (iRet == PD_OK) {
		PutField_CString(hRsp, "encrypt_type", "1");
		strcpy(csTmpChannelCode, "WebMsg");
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnWebByUsNWM :: build AckAuthData\n"));
		MsgObjPtr = CreateObj(MsgPtr, "WebMsg", "BuildAckAuthData");
		iRet = (unsigned long)(*MsgObjPtr)(hRsp);
	}

	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr, "BOSecurity", "GenerateNetworkMac");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest, hRsp);
DEBUGLOG(("BOSecurity->GenerateMac = [%d]\n", iRet));
	}

/////
	if(iRet == PD_OK){
		char*   csValueTmp;
		csValueTmp = (char*) malloc (128);
		DBObjPtr = CreateObj(DBPtr,"DBVoucherPaymentParameter","FindCode");
		if ((unsigned long)(DBObjPtr)(PD_VP_NETWORK_MSG_URL,csValueTmp) == FOUND) {
DEBUGLOG(("TxnWebByUsNWM:: Network Msg URL  = [%s]\n",csValueTmp));
                        PutField_CString(hRsp,"success_callback_url",csValueTmp);
		}
		FREE_ME(csValueTmp);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnWebByUsNWM Calling [Web]->[FormatAckMsg]\n"));
		MsgObjPtr = CreateObj(MsgPtr, "Web", "FormatAckMsg");
		h_msg = (hex_t*) malloc (sizeof(hex_t));
		if ((*MsgObjPtr)(hRsp, h_msg->msg, &h_msg->len) == PD_OK) {
DEBUGLOG(("h_msg->len = [%d]\n", h_msg->len));
			lKey = GetMQKey((unsigned char*)"ACKQ");
			// lRspKey = GetMQKey((unsigned char*)"ACKRSPQ");
			msg = (struct msg_t*) malloc (sizeof(struct msg_t) + MAX_MSG_SIZE);
			// msg->mtype = ctol((const unsigned char *)csOrgTxnSeq, strlen(csOrgTxnSeq));
			memset(msg->mtext, 0, sizeof(msg->mtext));
                        
			MQ_build_header((unsigned char*)msg->mtext,
							MQ_REQ,
							"ACK",
							0,
							"ACKRSPQ",
							0);
			
			/*MQ_build_header((unsigned char*)msg->mtext,
							MQ_RESP,
							PD_CHANNEL_WEB,
							0,
							NULL,
							0);
			*/
			memcpy(&msg->mtext[MQ_HEADER_LEN], h_msg->msg, h_msg->len);
			msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n", MQ_HEADER_LEN + h_msg->len));

/* set batch txn id to remote reply queue name without 'G' */
			// memcpy(&msg->mtext[MQ_REMOTE_REPLY_QUEUE_ID_OS], &csBatchTxnSeq[1], PD_TXN_SEQ_LEN - 1);
			iRet = MQSend(lKey, msg, MQ_HEADER_LEN + h_msg->len);
		}
		FREE_ME(h_msg);
	}

	FREE_ME(hRsp);

DEBUGLOG(("TxnWebByUsNWM Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
