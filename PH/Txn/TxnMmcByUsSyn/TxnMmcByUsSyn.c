/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/29              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsSyn.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Msg);
OBJPTR(BO);

void TxnMmcByUsSyn(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	hash_t	*hReq;
	char	*csPtr;
	char	*csNodeKey;
	char	*csEncType;

DEBUGLOG(("Authorize()\n"));
	hReq = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hReq,0);


/* process_type */
	PutField_CString(hReq,"process_type",PD_PROCESS_TYPE_NETWORK);

/* process_code */
	PutField_CString(hReq,"process_code",PD_PROCESS_CODE_SYN);

/* req_node_id */
	if (GetField_CString(hContext,"node_id",&csPtr)) {
DEBUGLOG(("Authorize req_node_id = [%s]\n",csPtr));
		PutField_CString(hReq,"req_node_id",csPtr);
	}

/* client_id */
	if (GetField_CString(hRequest,"client_id",&csPtr)) {
DEBUGLOG(("Authorize req_client_id = [%s]\n",csPtr));
		PutField_CString(hReq,"client_id",csPtr);
	}
/* client_name */
	if (GetField_CString(hRequest,"client_name",&csPtr)) {
DEBUGLOG(("Authorize client_name = [%s]\n",csPtr));
		PutField_CString(hReq,"client_name",csPtr);
	}


/* psp_id */
	if (GetField_CString(hRequest,"psp_id",&csPtr)) {
DEBUGLOG(("Authorize psp_id = [%s]\n",csPtr));
		PutField_CString(hReq,"psp_id",csPtr);
	}

/* psp_name */
	if (GetField_CString(hRequest,"psp_name",&csPtr)) {
DEBUGLOG(("Authorize psp_name = [%s]\n",csPtr));
		PutField_CString(hReq,"psp_name",csPtr);
	}

/* baid */
	if (GetField_CString(hRequest,"baid",&csPtr)) {
DEBUGLOG(("Authorize baid = [%s]\n",csPtr));
		PutField_CString(hReq,"baid",csPtr);
	}

/* baid_name */
	if (GetField_CString(hRequest,"baid_name",&csPtr)) {
DEBUGLOG(("Authorize baid_name = [%s]\n",csPtr));
		PutField_CString(hReq,"baid_name",csPtr);
	}

/* country */
	if (GetField_CString(hRequest,"country",&csPtr)) {
DEBUGLOG(("Authorize country = [%s]\n",csPtr));
		PutField_CString(hReq,"country",csPtr);
	}


/* enctype */
	if (GetField_CString(hContext,"enctype",&csEncType)) {
DEBUGLOG(("Authorize enctype = [%s]\n",csEncType));
		PutField_CString(hReq,"enctype",csEncType);
	}


	if (iRet == PD_OK) {
		char    csTmpChannelCode[PD_CHANNEL_CODE_LEN *2  +1];
		hex_t   *h_msg;
		long    lKey;
		struct msg_t* msg;
		char	*csMyReqQ,*csMyRspQ;

/* Get Request Queue */
		if (GetField_CString(hContext,"request_queue_name",&csMyReqQ)) {
DEBUGLOG(("Authorize request_queue_name = [%s]\n",csMyReqQ));
		}
		else {
ERRLOG("TxnMmcByUsSyn Request Q not found\n");
			iRet = PD_ERR;
		}

/* Get Response Queue */
		if (GetField_CString(hContext,"response_queue_name",&csMyRspQ)) {
DEBUGLOG(("Authorize response_queue_name = [%s]\n",csMyRspQ));
		}
		else {
ERRLOG("TxnMmcByUsSyn Response Q not found\n");
			iRet = PD_ERR;
		}
		sprintf(csTmpChannelCode,"MmcMsg");
	 	MsgObjPtr = CreateObj(MsgPtr,csTmpChannelCode,"BuildNetworkAuthData");
        	iRet = (unsigned long) (*MsgObjPtr)(hReq);
	
		if (iRet == PD_OK) {
			if (GetField_CString(hContext,"mms_key",&csNodeKey)) {
DEBUGLOG(("Authorize mms key = [%s]\n",csNodeKey));
			}
			else {
DEBUGLOG(("Authorize mms key not found\n"));
ERRLOG("TxnMmcByUsSync:Authorize mms key not found\n");
				iRet = PD_ERR;
			}
		}

/* try to cal the sign value */
		if (iRet == PD_OK )  {
			char    csTmpFunc[PD_TMP_BUF_LEN  +1];
			char	*csMac;
			char	*csData;
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
DEBUGLOG(("TxnMmcByUsSyn Calling [%s]->[FormatMsg]\n",csTmpChannelCode));
	 		MsgObjPtr = CreateObj(MsgPtr,csTmpChannelCode,"FormatNetworkMsg");
        		h_msg = (hex_t*) malloc (sizeof(hex_t));
        		if ((*MsgObjPtr)(hReq,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
				lKey = GetMQKey((unsigned char*)csMyReqQ);
       	         		msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                		msg->mtype  = 1;
                		memset(msg->mtext,0,sizeof(msg->mtext));
                       	 	MQ_build_header((unsigned char*)msg->mtext,
                       			MQ_REQ,
	                        	"MMC",
					0,
					NULL,
					0);
       	         		memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                		msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));
                
                		iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
			}
			FREE_ME(h_msg);
		}
	}

	FREE_ME(hReq);
DEBUGLOG(("TxnMmcByUsSyn Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
