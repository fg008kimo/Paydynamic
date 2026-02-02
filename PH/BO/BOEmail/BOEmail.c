/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/20              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOEmail.h"
#include "queue_utility.h"
#include "mq_db.h"

char    cDebug;

OBJPTR(Msg);

void BOEmail(char    cdebug)
{
        cDebug = cdebug;
}

int SendMyMail(hash_t hReq) 
{
	int	iRet = PD_OK;
	int	iSendLen;
	long	lKey;
	struct	msg_t	*msg;

	hex_t   *h_msg;
DEBUGLOG(("BOEmail:SendMyMail()\n"));
	h_msg = (hex_t*) malloc (sizeof(hex_t));
	
	MsgObjPtr = CreateObj(MsgPtr,"EmlMsg","FormatMsg");
	if ((*MsgObjPtr)(hReq,h_msg->msg,&h_msg->len) == PD_OK) {
        }
	else {
        	iRet = INT_FORMAT_ERR;
	}

	if (iRet == PD_OK) {
		lKey = GetMQKey((const unsigned char *)"EMAILREQQ");
		msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);	
		msg->mtype = 1;
		memset(msg->mtext,0,sizeof(msg->mtext));
                        MQ_build_header((unsigned char*)msg->mtext,
                        MQ_REQ,
                        "EML",
                        0,
                        NULL,
                        0);

		memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
                iSendLen = MQ_HEADER_LEN + h_msg->len;

		if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Request() Sent Error\n"));
                       iRet = PD_ERR;
                }

		FREE_ME(msg);
	}


	FREE_ME(h_msg);
DEBUGLOG(("BOEmail:SendMyMail() exit iRet = [%d]\n",iRet));
	return iRet;
}
