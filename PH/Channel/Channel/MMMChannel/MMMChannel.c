/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/16              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "MMMChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"
#include "dbutility.h"
#include "langconvert.h"

char	cDebug;

OBJPTR(DB);
OBJPTR(Msg);
OBJPTR(Txn);
OBJPTR(BO);

void MMMChannel(char	cdebug)
{
	cDebug = cdebug;
}




int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	hash_t	*hRequest,*hResponse;
	hex_t   *h_msg;
        struct msg_t* msg;
	long	lResponseQueueMtype;
	long	lKey;
	int	iRet = INT_NO_ERR;
	int     iInternalErr = 0;
	char    csTxnSeq[PD_TXN_SEQ_LEN +1];
	char*   csTxnCode;
	char*	csChannelCode;
	char	cTxnType;
	char	csTxnDateTime[PD_DATE_LEN + PD_TIME_LEN + 1];
	char*	csPtr;

	
DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);

	GetField_Char(hContext,"txn_type",&cTxnType);
DEBUGLOG(("process_txn::txn type = [%c]\n",cTxnType));

	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hContext,"txn_seq",csTxnSeq);
        PutField_CString(hContext,"action_txn_seq",csTxnSeq);
DEBUGLOG(("process_txn:txn_seq = [%s]\n",csTxnSeq));

	if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("process_txn:response queue mtype = [%ld]\n",lResponseQueueMtype));
	}
	else  {
DEBUGLOG(("unable to get response queue mtype\n"));
		iRet = PD_ERR;
	}
	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("process_txn:channel code = [%s]\n",csChannelCode));
	}
	else  {
DEBUGLOG(("process_txn:unable to get channel code queue mtype\n"));
		iRet = PD_ERR;
	}

/* txndate time */
	if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
		strcpy(csTxnDateTime,csPtr);
		PutField_CString(hContext,"tm_date",csPtr);
	}

	if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
		strcat(csTxnDateTime,csPtr);
		PutField_CString(hContext,"tm_time",csPtr);
		PutField_CString(hContext,"transmission_datetime",csTxnDateTime);
	}

	if (cTxnType ==  MQ_RESP ) {
/*
		iRet  = (UpdateContext(hContext));
DEBUGLOG(("updatecontext = [%d]\n",iRet));
                if (iRet == PD_OK) {
DEBUGLOG(("call process_resp_txn\n"));
                        return process_resp_txn(hContext,inMsg,outMsg);
                }
                else
       			return iRet;

		else if (cTxnType == MQ_BOUNCE_BACK) {
DEBUGLOG(("Bounce Backup Txn!!!\n"));
                	return process_WEB_bounce_txn(hContext,inMsg,outMsg);
        	}
*/
	}


DEBUGLOG(("process_txn:Call MmmMsg[%d]\n",inMsg->len));
	MsgObjPtr = CreateObj(MsgPtr,"MmmMsg","BreakDownMsg");
	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
		iRet = INT_BREAKDOWN_ERR;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("MMMChannel::process_txn BreakDown MmmMsg Error\n");
DEBUGLOG(("process_txn BreakDown MmmMsg Error\n"));
	}
	else {
		char*	csPtr;
		if (GetField_CString(hRequest,"add_user",&csPtr))
			PutField_CString(hContext,"add_user",csPtr);
	}

	if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBTxnSupported","FindTxnSupported");
                if (GetField_CString(hRequest,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_txn:txn_code = [%s]\n",csTxnCode));
			PutField_CString(hContext,"txn_code",csTxnCode);
                }
                if ((*DBObjPtr)(csChannelCode,
                                csTxnCode) != PD_OK) {
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find TxnCode\n"));
ERRLOG("MMMChannel:Unsupported transaction [%s][%s]\n",csChannelCode,csTxnCode);
                }
                else {
                        PutField_CString(hContext,"txn_code",csTxnCode);
                }
        }

//	if (iRet == PD_OK) {
 //               iRet  = (UpdateContext(hContext));
 	UpdateContext(hContext);
//DEBUGLOG(("process_txn: iRet = [%d] from UpdateContext()\n",iRet));
  //      }

	if (iRet == PD_OK ) {
		BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
                iRet = (unsigned long)(BOObjPtr)(hContext,hRequest);
DEBUGLOG(("process_txn: iRet = [%d] from AddTxnLog()\n",iRet));
	}

	if (iRet == PD_OK) {
		iRet = process_input_txn(hContext,hRequest,hResponse);
DEBUGLOG(("proces_txn:: return from process_input_txn iRet = [%d]\n",iRet));
        }


	if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iInternalErr))  {
		char	*csBuf;
		csBuf = (char*) malloc (PD_TMP_BUF_LEN +1);
		if ( iRet != PD_OK ) {
			TxnAbort();
DEBUGLOG(("process_txn: *****Format Out Reject Message\n"));
                        PutField_Char(hContext,"ar_ind",PD_REJECT);
                        PutField_Char(hResponse,"ar_ind",PD_REJECT);
                        PutField_Char(hContext,"status",PD_COMPLETE);
                        PutField_Char(hResponse,"status",PD_COMPLETE);
                        iRet = PD_OK;
                        sprintf(csBuf,"%d",iInternalErr);
                        PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("process_txn: Result_Code = %s iInternetalErr = [%d]\n",csBuf,iInternalErr));
                }
                else {
                        PutField_Char(hContext,"ar_ind",PD_ACCEPT);
                        PutField_Char(hResponse,"ar_ind",PD_ACCEPT);
                        PutField_Char(hContext,"status",PD_COMPLETE);
                        PutField_Char(hResponse,"status",PD_COMPLETE);
                        iInternalErr = INT_NO_ERR;
                        PutField_Int(hContext,"internal_error",iInternalErr);
                        sprintf(csBuf,"%d",iRet);
                        PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("process_txn: Result_Code = %s iInternetalErr = [%d]\n",csBuf,iInternalErr));
                }
                FREE_ME(csBuf);

//reset iRet  to PD_OK;
		iRet = PD_OK;

		PutField_Int(hContext,"internal_code",iInternalErr);

DEBUGLOG(("process_txn:Created Msg Object\n"));
                MsgObjPtr = CreateObj(MsgPtr,"MmmMsg","FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));

                iRet = (unsigned long)(*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len);

                if (iRet == PD_OK) {
			BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","UpdateTxnLog");
                	iRet = (unsigned long)(BOObjPtr)(hContext,hRequest,hResponse);
                }
		
		if (iRet == PD_OK) {
DEBUGLOG(("process_txn:Preparing to [%s]send back\n",csChannelCode));

DEBUGLOG(("process_txn:h_msg->len = [%d]\n",h_msg->len));

                       GetField_Long(hContext,"queue_key",&lKey);
DEBUGLOG(("process_txn: lkey = [%ld]\n",lKey));
                       msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                       msg->mtype  = lResponseQueueMtype;
                       long    lRemoteKey = 0l;
                       GetField_Long(hContext,"remote_reply_key",&lRemoteKey);
                       memset(msg->mtext,0,sizeof(msg->mtext));
                       MQ_build_header((unsigned char*)msg->mtext,
                                MQ_RESP,
                                csChannelCode,
                                0,
                                NULL,
                                lRemoteKey);
                       memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                        msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("process_txn:send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));


                        iRet = MQSend(lKey,msg,h_msg->len + MQ_HEADER_LEN);
                        FREE_ME(msg);
                        if (iRet  != MQ_OK ) {
DEBUGLOG(("process_txn:Can't send Message\n"));
ERRLOG("MMMChannel::process_txn:Can't send Message\n");
                                PutField_Int(hContext,"internal_code",iInternalErr);
                                iRet = PD_ERR;
                        }
		}
		FREE_ME(h_msg);
		FREE_ME(msg);
	}
	
DEBUGLOG(("process_txn: Normal RET = [%d]\n",iRet));
	FREE_ME(hRequest);
	FREE_ME(hResponse);
      

DEBUGLOG(("process_txn RET =[%d]\n",iRet));
	return iRet;
}


int     UpdateContext(hash_t* hContext)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csChannelCode,*csTxnCode;
	long	lKey;

DEBUGLOG(("UpdateContext()\n"));

	 if (GetField_CString(hContext,"reply_queue",&csPtr)) {
DEBUGLOG(("UpdateContext:reply queue = [%s]\n",csPtr));
                lKey = GetMQKey((unsigned char*)csPtr);
                PutField_Long(hContext,"queue_key",lKey);
DEBUGLOG(("UpdateContext:reply queue key = [%ld]\n",lKey));
        }

/* node id */
//	PutField_CString(hContext,"req_node_id",PD_MMS_HOST_NODE_ID);

/* node ref */
 //       if(GetField_CString(hContext,"txn_seq",&csPtr))
//		PutField_CString(hContext,"node_ref",csPtr);

/* System Parameters */
	char csTmpDate[PD_DATETIME_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csTmpDate));
                PutField_CString(hContext,"PHDATE",csTmpDate);
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("MMMChannel: UpdateContext::Internal Error SystemControl Record Not Found\n");
        }

        if(iRet==PD_OK){
DEBUGLOG(("UpdateContext\n"));
                int iDoLog = PD_NO_LOG;

                GetField_CString(hContext,"channel_code",&csChannelCode);
DEBUGLOG(("UpdateContext Channel Code [%s]\n",csChannelCode));
                if(GetField_CString(hContext,"txn_code",&csTxnCode)){
DEBUGLOG(("UpdateContext Txn Code [%s]\n",csTxnCode));
                        DBObjPtr = CreateObj(DBPtr,"DBTxnSupported","IsDoLogging");
                        iDoLog = (unsigned long)(*DBObjPtr)(csChannelCode,csTxnCode);
                }
                else {
DEBUGLOG(("UpdateContext::unable to get txn_code\n"));
                }
DEBUGLOG(("UpdateContext::do_logging = [%d]\n",iDoLog));
                PutField_Int(hContext,"do_logging",iDoLog);
        }

        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");

DEBUGLOG(("UpdateContext()normal exit iRet = [%d]\n",iRet));
	return iRet;
}



int     process_input_txn(hash_t *hContext,
                                const hash_t *hRequest,
                                hash_t *hResponse)
{

	int	iRet = PD_OK;
	char	*csTxnCode;
	char	*csHandler;
DEBUGLOG(("process_input_txn()\n"));
        if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_input_txn:txn_code = [%s]\n",csTxnCode));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("process_input_txn:txn_code not found\n"));
        }

        if (iRet == PD_OK) {
                TxnObjPtr = CreateObj(TxnPtr,"TxnMmmByUsCOM","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
        }
        if (iRet == PD_OK ) {
                csHandler = (char*) malloc (PD_TMP_BUF_LEN +1);
                sprintf(csHandler,"TxnMmmByUs%s",csTxnCode);
DEBUGLOG(("process_input_txn Create Txn Object [%s]\n",csHandler));
                TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
                FREE_ME(csHandler);

                iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("iRet = [%d]\n",iRet));
        }


DEBUGLOG(("process_input_txn Normal Exit iRet = [%d]\n",iRet));
	return iRet;
}
