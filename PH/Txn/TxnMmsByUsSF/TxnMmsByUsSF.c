/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/09              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUsSF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Msg);

int Send2Host(const hash_t* hData);
void TxnMmsByUsSF(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	recordset_t     *rRecordSet;
	hash_t		*hRec;
	char	cMode;

DEBUGLOG(("Authorize()\n"));
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	if (GetField_Char(hRequest,"mode",&cMode)) {
DEBUGLOG(("Authorize() mode [%c]\n",cMode));
		if (cMode == PD_MMS_HOST )  {
			DBObjPtr = CreateObj(DBPtr,"DBMmsStoreForward","GetPendingSF");
			iRet = (unsigned long)(*DBObjPtr)(PD_MMS_HOST,rRecordSet);
DEBUGLOG(("Authorize iRet = [%d] return from MmsStoreForward GetPendingSF\n"));
			if (iRet == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {	
					iRet = Send2Host(hRec);
					if (iRet != PD_OK) {
						break;
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
		else {
DEBUGLOG(("Authorize mode error!!! should not be [%c]\n",cMode));
ERRLOG("TxnMmsByUsSF::Authorize mode error!!! should not be [%c]\n",cMode);
		}
	}
	else {
DEBUGLOG(("Authorize() unable to find mode\n"));
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
DEBUGLOG(("TxnMmsByUsSF Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int Send2Host(const hash_t* hData)
{
	int	iRet = PD_OK;

	char    *csMyReqQ,*csMyRspQ,*csNodeKey, *csEncType;
	hash_t  *hContext, *hReq;

	hex_t   *h_msg;
        long    lKey;
        struct msg_t* msg;
DEBUGLOG(("Send2Host()\n"));

	hContext = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hContext,0);

	hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);

	ChannelObjPtr = CreateObj(ChannelPtr,"MMCChannel","UpdateContext");
        if ((unsigned long)(*ChannelObjPtr)(hContext) == PD_OK) {

        }
	else {
DEBUGLOG(("Send2Host() UpdateContext Error\n"));
ERRLOG("TxnMmsByUsSF:Send2Host() UpdateContext Error\n");
		iRet = PD_ERR;
	}

	
	if (iRet == PD_OK) {
	/* Get Request Queue */
                if (GetField_CString(hContext,"request_queue_name",&csMyReqQ)) {
DEBUGLOG(("Send2Host() Authorize request_queue_name = [%s]\n",csMyReqQ));
                }
                else {
ERRLOG("TxnMmsByUsSF::Send2Host() Request Q not found\n");
                        iRet = PD_ERR;
                }

/* Get Response Queue */
                if (GetField_CString(hContext,"response_queue_name",&csMyRspQ)) {
DEBUGLOG(("Send2Host() Authorize response_queue_name = [%s]\n",csMyRspQ));
                }
                else {
ERRLOG("TxnMmsByUsSF::Send2Host() Response Q not found\n");
                        iRet = PD_ERR;
                }

		if (GetField_CString(hContext,"mms_key",&csNodeKey)) {
DEBUGLOG(("Send2Host() Authorize mms key = [%s]\n",csNodeKey));
		}
               	else {
DEBUGLOG(("Send2Host() Authorize mms key not found\n"));
ERRLOG("TxnMmsByUsSync::Send2Host() Authorize mms key not found\n");
               		iRet = PD_ERR;
               	}

		if (GetField_CString(hContext,"enctype",&csEncType)) {
DEBUGLOG(("Send2Host() Authorize enctype = [%s]\n",csEncType));
		}
               	else {
DEBUGLOG(("Send2Host() Authorize enctype not found\n"));
ERRLOG("TxnMmsByUsSync::Send2Host() enctype not found\n");
               		iRet = PD_ERR;
               	}
	}
	
	if (iRet == PD_OK) {
/* put fields into request */
	
	
	}

	if (iRet == PD_OK) {
		MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BuildAuthData");
                iRet = (unsigned long) (*MsgObjPtr)(hReq);
		if (iRet != PD_OK) {
DEBUGLOG(("Send2Host() BuildAuthData Error\n"));
ERRLOG("TxnMmsByUsSync::Send2Host() BuildAuthData Error\n");
		}
	}

	if (iRet == PD_OK )  {
		char    csTmpFunc[PD_TMP_BUF_LEN  +1];
                char    *csMac;
                char    *csData;
                csMac = (char*) malloc (PD_TMP_MSG_BUF_LEN  +1);

                GetField_CString(hReq,"auth_data",&csData);
DEBUGLOG(("Authorize auth data = [%s]\n",csData));

                if (!strcmp(csEncType,PD_ENC_TYPE_MD5))
               		strcpy(csTmpFunc,"GenerateMD5Mac");
                else if (!strcmp(csEncType,PD_ENC_TYPE_MD5))
                        strcpy(csTmpFunc,"GenerateSHA1Mac");
                BOObjPtr = CreateObj(BOPtr,"BOSecurity", csTmpFunc);
                iRet = (unsigned long) (*BOObjPtr)(csNodeKey,csData,strlen(csData),csMac);
                if (iRet == PD_OK) {
                	PutField_CString(hReq,"mac",csMac);
DEBUGLOG(("Authorize MAC = [%s]\n",csMac));
                }
                FREE_ME(csMac);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMmsByUsSF Calling MmsMsg->[FormatMsg]\n"));
		MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));
                if ((*MsgObjPtr)(hReq,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("h_ms->len = [%d]\n",h_msg->len));
		/* the request will be sent to the Response Queue (Host to Client ) */
                lKey = GetMQKey((unsigned char*)csMyRspQ);
DEBUGLOG(("queue_name = [%s]\n",csMyRspQ));

                msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                msg->mtype  = 1;
                memset(msg->mtext,0,sizeof(msg->mtext));
                MQ_build_header((unsigned char*)msg->mtext,
                	MQ_RESP,
                        "MMS",
                        0,
                        NULL,
                0);
                memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

			/* The Response will be handle by the Channel and Gateway */
                	iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
                }
                FREE_ME(h_msg);
	}

	hash_destroy(hContext);
        FREE_ME(hContext);	

	hash_destroy(hReq);
        FREE_ME(hReq);	

	FREE_ME(h_msg);
DEBUGLOG(("Send2Host() normal Return iRet = [%d]\n",iRet));
	return iRet;

}
