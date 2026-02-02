/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/23              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2CCT.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);
int     process_resp_txn(hash_t *hContext,
			 hash_t *hResponse,
                                const hex_t* inMsg);
int     process_ack_resp_txn(hash_t *hContext,
			 hash_t *hResponse);

void TxnWebOnUs2CCT(char    cdebug)
{
        cDebug = cdebug;
}

int     process_resp_txn(hash_t *hContext,
			 hash_t *hResponse,
                                const hex_t* inMsg)
{
        int     iRet = PD_OK;
        
DEBUGLOG(("process_resp_txn()\n"));

     	MsgObjPtr = CreateObj(MsgPtr,"CctMsg","BreakDownMsg");

        if ((*MsgObjPtr)(hResponse,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_resp_txn:BreakDown Msg Error\n"));
        }
        else {
        }

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}               

int     process_ack_resp_txn(hash_t *hContext,
                         hash_t *hResponse)
{
        int     iRet = PD_OK;

DEBUGLOG(("process_ack_resp_txn()\n"));

        MsgObjPtr = CreateObj(MsgPtr,"CctMsg","BreakDownAckMsg");

        if ((*MsgObjPtr)(hResponse) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_ack_resp_txn:BreakAckDown Msg Error\n"));
        }
        else {
        }

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}

int     Encrypt(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;
	hex_t   *h_msg;
        char    *csTxnSeq;
	char	*csPtr;


DEBUGLOG(("TxnWebOnUs2CCT: Encrypt()\n"));

	if (iRet == PD_OK) {
        	if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) 
        		GetField_CString(hContext,"txn_seq",&csTxnSeq);
                        
		PutField_CString((hash_t*)hRequest,"txn_seq",csTxnSeq);

		if (GetField_CString(hContext,"transmission_datetime",&csPtr))
			PutField_CString((hash_t*)hRequest,"transmission_datetime",csPtr);

       		MsgObjPtr = CreateObj(MsgPtr,"CctMsg","FormatEnMsg");

        	h_msg = (hex_t*) malloc (sizeof(hex_t));
        	if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
			PutField_CString(hResponse,"emsg",(const char*)h_msg->msg);
        	}     
        	else {
                	iRet = INT_FORMAT_ERR;
        	}       
        	FREE_ME(h_msg);
	}

DEBUGLOG(("TxnWebOnUs2CCT: Encrypt exit iret = [%d]\n",iRet));
	return iRet;
}

int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;

DEBUGLOG(("TxnWebOnUs2CCT: Decrypt()\n"));

	if (iRet == PD_OK) {
		iRet = process_ack_resp_txn(hContext,hRequest);
	}

DEBUGLOG(("TxnWebOnUs2CCT::Decrypt: noraml exit iret = [%d]\n",iRet));
	return iRet;
}

int     Request(hash_t* hContext,
			unsigned char* inBuf,
			int iLen,
			unsigned char* outBuf,
			int *oLen)
{
        int iRet = PD_OK;
        struct msg_t *msg;
        int     iSendLen,iRecvLen;
        long    lKey,lRspKey;
        char    *csTxnSeq;

DEBUGLOG(("Request()\n"));

DEBUGLOG(("Request() [%d][%s]\n",iLen,inBuf));
	if (iRet == PD_OK) {
		if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq))
                        GetField_CString(hContext,"txn_seq",&csTxnSeq);

DEBUGLOG(("Request() txn_seq = [%s]\n",csTxnSeq));
                lKey = GetMQKey((const unsigned char *)"CCTPREQQ");
                lRspKey = GetMQKey((const unsigned char *)"CCTPRSPQ");

                msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                msg->mtype  = ctol((const unsigned char *)csTxnSeq,strlen(csTxnSeq));
                memset(msg->mtext,0,sizeof(msg->mtext));
                	MQ_build_header((unsigned char*)msg->mtext,
                        MQ_RESP,
                        "WEB",
                        0,
                        NULL,
                        0);

                memcpy(&msg->mtext[MQ_HEADER_LEN],inBuf,iLen);
                msg->mtext[MQ_HEADER_LEN + iLen] = '\0';
                iSendLen = MQ_HEADER_LEN + iLen;
DEBUGLOG(("Request() send msg = [%s] send len = [%d]\n",msg->mtext,iSendLen));
DEBUGLOG(("Request() rspkey = [%ld][%ld]\n",lRspKey,msg->mtype));


                if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Request() Sent Error\n"));
                       iRet = PD_ERR;
                }
		else {
        		memset(msg->mtext,0,sizeof(msg->mtext));
                       	if (MQRecv(lRspKey,msg,&iRecvLen,10) != MQ_OK ) {
DEBUGLOG(("Request() recv Error\n"));
                       		iRet = PD_ERR;
                        }
                        else {
                       		msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("Request() recv len = [%d]\n",iRecvLen));
				*oLen = iRecvLen - MQ_HEADER_LEN;
				memcpy(outBuf,&msg->mtext[MQ_HEADER_LEN],*oLen);
				outBuf[*oLen] = '\0';
               		}
		}
                        FREE_ME(msg);
        }

DEBUGLOG(("Request() noraml exit iret = [%d]\n",iRet));
	return iRet;
}
