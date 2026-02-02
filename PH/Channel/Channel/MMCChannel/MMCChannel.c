/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/29              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "MMCChannel.h"
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

void MMCChannel(char	cdebug)
{
	cDebug = cdebug;
}


int     UpdateContext(hash_t* hContext);

int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	hash_t	*hRequest,*hResponse;
	hex_t   *h_msg;
	struct msg_t* msg;
	long	lResponseQueueMtype;
	long 	lKey;
	int	iRet = INT_NO_ERR;

	char*	csChannelCode;
	char*   csProcessType;
        char*   csProcessCode;
	char*   csTxnDesc;
	char*	csTxnCode;
	char*	csTxnSeq;
	int     iInternalErr = 0;
	int     iTmp= 0;
	char*	csBuf;
	
DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);

	csTxnSeq = (char*) malloc (PD_TXN_SEQ_LEN +1 );
	csTxnCode = (char*) malloc (PD_TXN_CODE_LEN +1 );
        csTxnDesc = (char*) malloc (PD_DESC_LEN + 1);
        csProcessCode = (char*) malloc (PD_PROCESS_CODE_LEN + 1);
        csProcessType = (char*) malloc (PD_PROCESS_TYPE_LEN + 1);

	if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("response queue mtype = [%ld]\n",lResponseQueueMtype));
	}
	else  {
DEBUGLOG(("unable to get response queue mtype\n"));
		iRet = PD_ERR;
	}
	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("channel code = [%s]\n",csChannelCode));
	}
	else  {
DEBUGLOG(("unable to get channel code queue mtype\n"));
		iRet = PD_ERR;
	}


DEBUGLOG(("Call MmcMsg\n"));
	MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","BreakDownMsg");
	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
		iRet = INT_BREAKDOWN_ERR;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("BreakDown MmcMsg Error\n");
DEBUGLOG(("process_txn:BreakDown MmcMsg Error\n"));
	}
	else {
		char*	csPtr;
		if (GetField_CString(hRequest,"add_user",&csPtr))
			PutField_CString(hContext,"add_user",csPtr);
		if (GetField_CString(hRequest,"txn_seq",&csPtr))
			PutField_CString(hContext,"txn_seq",csPtr);
	}


	if (iRet == PD_OK) {
		 //txn seq 
		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmsTxnSeq");
		strcpy(csTxnSeq,(*DBObjPtr)());
		PutField_CString(hContext,"txn_seq",csTxnSeq);
DEBUGLOG(("process_txn:txn_seq = [%s]\n",csTxnSeq));
		if (GetField_CString(hRequest,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_txn:txn_code = [%s]\n",csTxnCode));

			DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCode","FindProcessCode");
			if (!(*DBObjPtr)(csTxnCode,
					csTxnDesc,
					csProcessType,
					csProcessCode)) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find ProcessCode\n"));
ERRLOG("MMCChannel:Unsupported transaction [%s]\n",csTxnCode);
			}
			else {
				PutField_CString(hContext,"process_code",csProcessCode);
				PutField_CString(hContext,"process_type",csProcessType);
DEBUGLOG(("process_txn:ProcessType = [%s]\n",csProcessType));
DEBUGLOG(("process_txn:ProcessCode = [%s]\n",csProcessCode));
			}
		}
		else {
/* Find Txn Code */
                	if (GetField_CString(hRequest,"process_type",&csProcessType)) {
DEBUGLOG(("process_txn:process_type = [%s]\n",csProcessType));
                	}
                	if (!GetField_CString(hRequest,"process_code",&csProcessCode)) {
                	        csProcessCode = strdup(PD_PROCESS_CODE_DEF);
                	}
DEBUGLOG(("process_txn:process_code = [%s]\n",csProcessCode));

                	DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCode","FindTxnCode");
                	if (!(*DBObjPtr)(csTxnCode,
                        	         csTxnDesc,
                                        csProcessType,
                                        csProcessCode)) {
                        	iRet = INT_INVALID_TXN;
                        	PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find TxnCode\n"));
ERRLOG("MMSChannel:Unsupported transaction [%s][%s]\n",csProcessType,csProcessCode);
                	}
                	else {
                        	PutField_CString(hContext,"txn_code",csTxnCode);
                        	PutField_CString(hContext,"txn_desc",csTxnDesc);
DEBUGLOG(("process_txn:TxnCode = [%s]\n",csTxnCode));
DEBUGLOG(("process_txn:TxnDesc = [%s]\n",csTxnDesc));
                	}
		}

		if(iRet==PD_OK){
			DBObjPtr = CreateObj(DBPtr,"DBMmsTxnSupported","FindMmsTxnSupported");
			if ((*DBObjPtr)(csChannelCode,
					csTxnCode) != PD_OK) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find TxnCode\n"));
ERRLOG("MMCChannel:Unsupported transaction [%s][%s]\n",csChannelCode,csTxnCode);
			}
			else
                       		PutField_CString(hContext,"txn_code",csTxnCode);
		}
	}

	if (iRet == PD_OK) {
		iRet  = (UpdateContext(hContext));
	}

	if(iRet == PD_OK){
		if(GetField_Int(hContext,"init_txn",&iTmp)){
			if(iTmp==PD_TRUE){
				DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmsTxnSeq");
				strcpy(csTxnSeq,(*DBObjPtr)());
				PutField_CString(hContext,"txn_seq",csTxnSeq);
DEBUGLOG(("process_txn:txn_seq = [%s]\n",csTxnSeq));
			}
			else {
				if (GetField_CString(hRequest, "txn_seq", &csTxnSeq)) {
					PutField_CString(hContext, "txn_seq", csTxnSeq);
				}
			}
		}
	}

/*
	if (iRet == PD_OK ) {
		iRet = AddTxnLog(hContext,hRequest);
	}
*/

	if (iRet == PD_OK) {
       		MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","initReplyFromRequest");
               iRet = (unsigned long)(*MsgObjPtr)(hRequest,hResponse);
DEBUGLOG(("process_txn:RET = [%d] from initReply\n",iRet));
     	}

/*
	if (iRet == PD_OK) {
		iRet = process_input_txn(hContext,hRequest,hResponse);
	}
*/

	if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iInternalErr))  {
		csBuf = (char*) malloc (128);
		sprintf(csBuf,"%d",iInternalErr);
		PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("Result_Code = %s\n",csBuf));
		FREE_ME(csBuf);
	

		if (iInternalErr != 0 ) {
DEBUGLOG(("*****Format Out Reject Message\n"));
                	PutField_Char(hContext,"status",PD_COMPLETE);
                        PutField_Char(hContext,"ar_ind",PD_REJECT);
                }
                else{
                	PutField_Char(hContext,"status",PD_MMC_PENDING);
                	//PutField_Char(hContext,"status",PD_COMPLETE);
                	//PutField_Char(hContext,"ar_ind",PD_ACCEPT);
                        iInternalErr = INT_NO_ERR;
		}

                PutField_Int(hContext,"internal_code",iInternalErr);

DEBUGLOG(("Created Msg Object\n"));
		MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));
                iRet = (unsigned long)(*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len);
/*
		if (iRet == PD_OK) {
                       	iRet = UpdateTxnLog(hContext,hRequest,hResponse);
                }
*/
		if (iRet == PD_OK) {
DEBUGLOG(("Preparing to [%s]send back\n",csChannelCode));

DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));           
                       GetField_Long(hContext,"queue_key",&lKey);
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
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));


                        iRet = MQSend(lKey,msg,h_msg->len + MQ_HEADER_LEN);
                        FREE_ME(msg);
			if (iRet  != MQ_OK ) {
DEBUGLOG(("Can't send Message\n"));
                                PutField_Int(hContext,"internal_code",iInternalErr);
                                iRet = PD_ERR;
                        }
			else {
DEBUGLOG(("Message Sent\n"));
				iRet = PD_OK;
			}
		}
                FREE_ME(h_msg);
	}
	
DEBUGLOG(("Normal RET = [%d]\n",iRet));
	FREE_ME(hRequest);
	FREE_ME(hResponse);
	FREE_ME(csTxnSeq);
	FREE_ME(csTxnCode);
	FREE_ME(csTxnDesc);
	FREE_ME(csProcessCode);
	FREE_ME(csProcessType);
DEBUGLOG(("process_txn RET =[%d]\n",iRet));
	return iRet;
}


int     UpdateContext(hash_t* hContext)
{
        int     	iRet = PD_OK;
	char		*csPtr;
	char		*csCode,*csValue;
	char		csMyNode[PD_MMS_NODE_ID_LEN +1];
	char		*csKeyName;

	hash_t		*hRec,*hData;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	if(iRet ==PD_OK){
		recordset_init(rRecordSet,0);

                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","GetAllCodes");
                if ((unsigned long)(DBObjPtr)(rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"code",&csCode)) {
					if (GetField_CString(hRec,"value",&csValue)) {
                                		if (!strcmp(csCode, PD_MMCID)) {
DEBUGLOG(("UpdateContext::node id = [%s]\n",csValue));
							strcpy(csMyNode,csValue);
                                       			PutField_CString(hContext,"node_id",csValue);
                                        	}
					}
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                        iRet = PD_ERR;
ERRLOG("MMCChannel::Internal Error SystemControl Record Not Found\n");
                }
	}

	if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBMmxNodes","GetQByNode");
                if ((unsigned long)(DBObjPtr)(csMyNode,hData) == PD_FOUND) {
			if (GetField_CString(hData,"request_queue_name",&csPtr)) {
DEBUGLOG(("UpdateContext::Request Queue Name = [%s]\n",csPtr));
				PutField_CString(hContext,"request_queue_name",csPtr);
			}

			if (GetField_CString(hData,"response_queue_name",&csPtr)) {
DEBUGLOG(("UpdateContext::Response Queue Name = [%s]\n",csPtr));
				PutField_CString(hContext,"response_queue_name",csPtr);
			}

			if (GetField_CString(hData,"encrypt_key",&csKeyName)) {
DEBUGLOG(("UpdateContext::Encrypt Key = [%s]\n",csKeyName));
				PutField_CString(hContext,"encrypt_key",csKeyName);
			}

			if (!strcmp(csKeyName,PD_PTK_KEY_NAME)) {
DEBUGLOG(("UpdateContext::enctype = [%s]\n",PD_ENC_TYPE_MD5));
				PutField_CString(hContext,"enctype",PD_ENC_TYPE_MD5);
			}
		}
		else {
			iRet = PD_ERR;
		}
	}

	if (iRet == PD_OK) {
        	hash_init(hData,0);
                DBObjPtr = CreateObj(DBPtr,"DBMmsKeys","GetMmsKey");
                if ((unsigned long)(DBObjPtr)(csMyNode,csKeyName,hData) == PD_FOUND) {
			if (GetField_CString(hData,"mms_key",&csPtr)) {
DEBUGLOG(("UpdateContext::mms_key = [%s]\n",csPtr));
				PutField_CString(hContext,"mms_key",csPtr);
			}
		}
		else {
			iRet = PD_ERR;
		}
	}


        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

        hash_destroy(hData);
        FREE_ME(hData);
DEBUGLOG(("UpdateContext:: Noraml Return = [%d]\n",iRet));
        return iRet;
}
