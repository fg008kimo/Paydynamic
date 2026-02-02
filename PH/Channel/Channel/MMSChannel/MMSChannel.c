/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/03              Cody Chan
Move TxnLog to BO				   2015/07/07		   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "MMSChannel.h"
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

OBJPTR(Msg);
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);


int     UpdateContext(hash_t* hContext);

int     process_network_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response);
int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response);

void MMSChannel(char	cdebug)
{
	cDebug = cdebug;
}



int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	int	iRet = INT_NO_ERR;
	int	iInternalErr;
	long    lResponseQueueMtype;

	hex_t   *h_msg;
       	struct msg_t* msg;

	char	cTxnType;
	char*   csChannelCode;
	char*	csProcessType;
	char*	csProcessCode;
	char*	csTxnCode;
	char*	csTxnDesc;
	char*	csPtr;
	char*	csMac;
	char*	csAuthData;
	char*	csEncType;
	char*	csNodeKey;
	char*	csReqNodeId;
	char*	csReqNodeRef;
	char	csRespProcessType[PD_PROCESS_TYPE_LEN +1];


	hash_t  *hRequest,*hResponse;

DEBUGLOG(("process_txn ()\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);
        hash_init(hResponse,0);	

  	h_msg = (hex_t*) malloc (sizeof(hex_t));
       	msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);

	csTxnCode = (char*) malloc (PD_TXN_CODE_LEN +1 );
        csTxnDesc = (char*) malloc (PD_DESC_LEN + 1);	

	GetField_Char(hContext,"txn_type",&cTxnType);
DEBUGLOG(("txn type = [%c]\n",cTxnType));

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
*/

        }
/*
        else if (cTxnType == MQ_BOUNCE_BACK) {
DEBUGLOG(("Bounce Backup Txn!!!\n"));
                return process_WEB_bounce_txn(hContext,inMsg,outMsg);
        }
*/

DEBUGLOG(("Call MmsMsg\n"));
        MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BreakDownMsg");
        if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
ERRLOG("MMSChannel:BreakDown MmcMsg Error\n");
DEBUGLOG(("process_txn:BreakDown MmsMsg Error\n"));
        }
        else {
                char*   csPtr;
                if (GetField_CString(hRequest,"add_user",&csPtr))
                        PutField_CString(hContext,"add_user",csPtr);
/* process type */
                if (GetField_CString(hRequest,"process_type",&csProcessType)) {
                        PutField_CString(hContext,"process_type",csProcessType);
DEBUGLOG(("process_txn: process_type = [%s]\n",csProcessType));
		}
/* process code */
                if (GetField_CString(hRequest,"process_code",&csProcessCode)) {
                        PutField_CString(hContext,"process_code",csProcessCode);
DEBUGLOG(("process_txn: process_code = [%s]\n",csProcessCode));
		}
        }

	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"req_node_id",&csPtr)){
DEBUGLOG(("process_txn: req_node_id = [%s]\n",csPtr));
			PutField_CString(hContext,"req_node_id",csPtr);
		}

		if (GetField_CString(hRequest,"enctype",&csPtr)){
DEBUGLOG(("process_txn: enctype = [%s]\n",csPtr));
			PutField_CString(hContext,"enctype",csPtr);
		}

                iRet  = (UpdateContext(hContext));
        }

	if (iRet == PD_OK) {
/* Find Txn Code */
                if (GetField_CString(hRequest,"process_type",&csProcessType)) {
DEBUGLOG(("process_txn:process_type = [%s]\n",csProcessType));
                }
                if (!GetField_CString(hRequest,"process_code",&csProcessCode)) {
                        csProcessCode = strdup("000000");
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
DEBUGLOG(("try to create obj 3\n"))
                        PutField_CString(hContext,"txn_code",csTxnCode);
                        PutField_CString(hContext,"txn_desc",csTxnDesc);
                        PutField_CString(hResponse,"txn_code",csTxnCode);
DEBUGLOG(("process_txn:TxnCode = [%s]\n",csTxnCode));
DEBUGLOG(("process_txn:TxnDesc = [%s]\n",csTxnDesc));
                }
//Response Process Type
		strcpy(csRespProcessType,csProcessType);
               	csRespProcessType[PD_PROCESS_TYPE_LEN-1] = PD_PROCESS_TYPE_RESP_CODE;
               	PutField_CString(hResponse,"process_type",csRespProcessType);
	}


	if (iRet == PD_OK ) {
		if (GetField_CString(hRequest,"auth_data",&csAuthData)) {
DEBUGLOG(("process_txn: auth_data = [%s]\n",csAuthData));
		}
		else {
DEBUGLOG(("process_txn: auth_data not found\n"));
		}

		if (GetField_CString(hRequest,"mac",&csMac)) {
DEBUGLOG(("process_txn: mac = [%s]\n",csMac));
		}
		else {
DEBUGLOG(("process_txn: mac not found\n"));
		}

		if (GetField_CString(hRequest,"enctype",&csEncType)) {
DEBUGLOG(("process_txn: enctype = [%s]\n",csEncType));
		}
		else {
DEBUGLOG(("process_txn: enctype not found\n"));
		}

		if (GetField_CString(hContext,"mms_key",&csNodeKey)) {
DEBUGLOG(("process_txn: mms_key = [%s]\n",csNodeKey));
		}
		else {
DEBUGLOG(("process_txn: mms_key not found\n"));
		}

		if (!strcmp(csEncType,PD_ENC_TYPE_MD5)) {
			BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyMD5Mac");
		}
		else if (!strcmp(csEncType,PD_ENC_TYPE_SHA1)) {
			BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifySHA1Mac");
		}
		
		iRet = (unsigned long) (*BOObjPtr)(csMac,csNodeKey,csAuthData,strlen(csAuthData));
DEBUGLOG(("process_txn return from BOSecurity VerifyMac= [%d]\n",iRet));
	}
	if (iRet == PD_OK) {
		MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","initReplyFromRequest");
                if ((*MsgObjPtr)(hRequest,hResponse) != PD_OK)  {
                	iRet = INT_BREAKDOWN_ERR;
                        PutField_Int(hContext,"internal_error",iRet);
                }
	}

	if (iRet == PD_OK ) {
DEBUGLOG(("process_txn [%s] == [%s]?\n",csProcessType,PD_PROCESS_TYPE_NETWORK));
		if (!strcmp(csProcessType,PD_PROCESS_TYPE_NETWORK)) {
/* process_network */
			iRet = process_network_txn(hContext,hRequest,hResponse);
		}
		else {
			 char    csTxnSeq[PD_TXN_SEQ_LEN +1];
        
        		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        		strcpy(csTxnSeq,(*DBObjPtr)());
        		PutField_CString(hContext,"txn_seq",csTxnSeq);
        		PutField_CString(hContext,"action_txn_seq",csTxnSeq);
        		PutField_CString(hContext,"remote_node_ref",csTxnSeq);
DEBUGLOG(("Txn Seq = [%s]\n",csTxnSeq));

/* process_input */
			GetField_CString(hRequest,"req_node_id",&csReqNodeId);
DEBUGLOG(("process_txn::req_node_id = [%s]\n",csReqNodeId));
			GetField_CString(hRequest,"node_ref",&csReqNodeRef);
DEBUGLOG(("process_txn::req_node_Ref = [%s]\n",csReqNodeRef));

			DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","MatchNodeRef");
                        if ((unsigned long)(DBObjPtr)(csReqNodeId,csReqNodeRef) == PD_FOUND) {
                        	iRet = INT_DUP_MERCHANT_REF;
                                PutField_Int(hContext,"internal_error",INT_DUP_MERCHANT_REF);
ERRLOG("Channel:[MMS] - NodeID[%s][%s]Duplicate Node Ref\n",csReqNodeId,csReqNodeRef);
DEBUGLOG(("Channel:[MMS] - NodeID[%s][%s]Duplicate Node Ref\n",csReqNodeId,csReqNodeRef));

                        }
			if (iRet == PD_OK) {
				BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
                		iRet = (unsigned long)(BOObjPtr)(hContext,hRequest);
			}

			if (iRet == PD_OK) {
				iRet = process_input_txn(hContext,hRequest,hResponse);
DEBUGLOG(("proces_txn:: return from process_input_txn iRet = [%d]\n",iRet));
			}
		}
	}


	if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iInternalErr))  {

		char*	csBuf;
		csBuf = (char*) malloc (PD_TMP_BUF_LEN +1);

		if ( iRet != PD_OK ) {
DEBUGLOG(("*****Format Out Reject Message\n"));
               		PutField_Char(hContext,"ar_ind",PD_REJECT);
                        PutField_Char(hResponse,"ar_ind",PD_REJECT);
                        PutField_Char(hContext,"status",PD_COMPLETE);
                        PutField_Char(hResponse,"status",PD_COMPLETE);
                        iRet = PD_OK;
                	sprintf(csBuf,"%d",iInternalErr);
                	PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("Result_Code = %s iInternetalErr = [%d]\n",csBuf,iInternalErr));
                }
                else {
               		PutField_Char(hContext,"ar_ind",PD_ACCEPT);
                        PutField_Char(hResponse,"ar_ind",PD_ACCEPT);
                        PutField_Char(hContext,"status",PD_COMPLETE);
                        PutField_Char(hResponse,"status",PD_COMPLETE);
                        PutField_CString(hContext,"sub_status",PD_PENDING);
                	iInternalErr = INT_NO_ERR;
			PutField_Int(hContext,"internal_error",iInternalErr);
                	sprintf(csBuf,"%d",iRet);
                	PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("Result_Code = %s iInternetalErr = [%d]\n",csBuf,iInternalErr));
		}
                FREE_ME(csBuf);	
	}

	if (iRet == PD_OK && strcmp(csProcessType,PD_PROCESS_TYPE_NETWORK) ) {
		BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","UpdateTxnLog");
                iRet = (unsigned long)(BOObjPtr)(hContext,hRequest,hResponse);
	}

	if (iRet == PD_OK && strcmp(csProcessType,PD_PROCESS_TYPE_NETWORK) ) {
		char	*csTmpMac;

		csTmpMac = (char*) malloc (PD_TMP_BUF_LEN +1 );

		if (GetField_CString(hResponse,"process_code",&csPtr)) {
DEBUGLOG(("process_intput_txn::process_code = [%s]\n",csPtr));
		}

		MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BuildAuthData");
              	if ((*MsgObjPtr)(hResponse) == PD_OK) {
			if (GetField_CString(hResponse,"auth_data",&csAuthData)) {
DEBUGLOG(("process_intput_txn::response auth_data = [%s]\n",csAuthData));
			}

			if (!strcmp(csEncType,PD_ENC_TYPE_MD5)) {
                       		BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMD5Mac");
                	}
                	else if (!strcmp(csEncType,PD_ENC_TYPE_SHA1)) {
                        	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateSHA1Mac");
                	}

			iRet = (unsigned long) (*BOObjPtr)(csNodeKey,csAuthData,strlen(csAuthData),csTmpMac);

			if (iRet == PD_OK ){
/* mac */
DEBUGLOG(("process_intput_txn::response mac = [%s]\n",csTmpMac));
				PutField_CString(hResponse,"mac",csTmpMac);
				MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","FormatMsg");

                		if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) != PD_OK) {
				iRet = PD_ERR;
DEBUGLOG(("process_input:: FormatMsg Error\n"));
ERRLOG("process_input:: FormatMsg Error\n");
				}
			}
		}
		else {
DEBUGLOG(("process_input:: BuildAuthData Error\n"));
ERRLOG("process_input:: BuildAuthData Error\n");
			iRet = PD_ERR;
		}
		FREE_ME(csTmpMac);
	}

	if (iRet == PD_OK && strcmp(csProcessType,PD_PROCESS_TYPE_NETWORK)) {
		long	lKey;
		long	lResponseKey;

        	GetField_Long(hContext,"queue_key",&lKey);
        	GetField_Long(hContext,"response_queue_key",&lResponseKey);
DEBUGLOG(("h_msg->msg = [%s]\n",h_msg->msg));
DEBUGLOG(("h_msg->len = [%d] key = [%ld] reponse key = [%d]\n",h_msg->len,lKey,lResponseKey));
                msg->mtype  = lResponseQueueMtype;

                memset(msg->mtext,0,sizeof(msg->mtext));
                MQ_build_header((unsigned char*)msg->mtext,
               		MQ_RESP,
                        csChannelCode,
                        0,
                        NULL,
                        0);

         	memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

                iRet = MQSend(lResponseKey,msg,MQ_HEADER_LEN + h_msg->len);

        }
	FREE_ME(hRequest);
        FREE_ME(hResponse)

	FREE_ME(csTxnCode);
	FREE_ME(csTxnDesc);

        FREE_ME(h_msg);
        FREE_ME(msg);
DEBUGLOG(("process_txn RET =[%d]\n",iRet));
	return iRet;
}

int     process_network_txn(hash_t *hContext,
                                const hash_t *hRequest,
                                hash_t *hResponse)
{
        int     iRet = PD_OK;
	hash_t	*hData;

	char*   csTxnCode;

//DEBUGLOG(("process_network_txn\n"));
	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);



/* txn_code */
	if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_network_txn: txn_code = [%s]\n",csTxnCode));
	}
	
	if (iRet == PD_OK) {
		char*	csHandler;
		csHandler = (char*) malloc (PD_TMP_BUF_LEN +1);
                sprintf(csHandler,"TxnMmsOnUs%s",csTxnCode);
DEBUGLOG(("process_network_txn Create Txn Object [%s]\n",csHandler));
                TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
		iRet = (unsigned long) (*TxnObjPtr)(hContext,hRequest,hResponse);

DEBUGLOG(("process_network_txn return from Object [%s] = [%d]\n",csHandler,iRet));
                FREE_ME(csHandler);
	}

	hash_destroy(hData);
        FREE_ME(hData);
DEBUGLOG(("process_network_txn iRet = [%d]\n",iRet));
	return iRet;
}		

int     UpdateContext(hash_t* hContext)
{
        int             iRet = PD_OK;
        char            *csPtr;
        char            *csReqNodeId;
	long		lKey;

        hash_t          *hData;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);


	if (GetField_CString(hContext,"req_node_id",&csReqNodeId)) {
DEBUGLOG(("UpdateContext::Req Node ID = [%s]\n",csReqNodeId));
	}
	else {
DEBUGLOG(("UpdateContext::Req Node ID Not Found\n"));
		iRet = PD_ERR;
	}

	char csTmpDate[PD_DATETIME_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","FindCode");

        if ((unsigned long)(*DBObjPtr)("CTPHDATE",csTmpDate) == FOUND) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csTmpDate));
                PutField_CString(hContext,"PHDATE",csTmpDate);
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("UpdateContext::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }


        if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBMmxNodes","GetQByNode");
                if ((unsigned long)(DBObjPtr)(csReqNodeId,hData) == PD_FOUND) {
                        if (GetField_CString(hData,"request_queue_name",&csPtr)) {
DEBUGLOG(("UpdateContext::Request Queue Name = [%s]\n",csPtr));
                                PutField_CString(hContext,"request_queue_name",csPtr);
				lKey = GetMQKey((unsigned char*)csPtr);
                		PutField_Long(hContext,"queue_key",lKey);
                        }

                        if (GetField_CString(hData,"response_queue_name",&csPtr)) {
DEBUGLOG(("UpdateContext::Response Queue Name = [%s]\n",csPtr));
                                PutField_CString(hContext,"response_queue_name",csPtr);
				lKey = GetMQKey((unsigned char*)csPtr);
                		PutField_Long(hContext,"response_queue_key",lKey);
                        }

                }
                else {
                        iRet = PD_ERR;
                }
        }

        if (iRet == PD_OK) {
		char	*csEncType;
		char	csKeyName[PD_KEY_NAME_LEN +1];

		if (GetField_CString(hContext,"enctype",&csEncType)) {
DEBUGLOG(("UpdateContext:: EncType = [%s]\n",csEncType));
			if (!strcmp(csEncType, PD_ENC_TYPE_MD5)) {
				strcpy(csKeyName,PD_PTK_KEY_NAME);
			}
			else if (!strcmp(csEncType, PD_ENC_TYPE_SHA1)) {
				strcpy(csKeyName,PD_SHA1_KEY_NAME);
			}

                	hash_init(hData,0);
                	DBObjPtr = CreateObj(DBPtr,"DBMmsKeys","GetMmsKey");
                	if ((unsigned long)(DBObjPtr)(csReqNodeId,csKeyName,hData) == PD_FOUND) {
                        	if (GetField_CString(hData,"mms_key",&csPtr)) {
DEBUGLOG(("UpdateContext::mms_key = [%s]\n",csPtr));
                               		PutField_CString(hContext,"mms_key",csPtr);
                        	}
                	}
                	else {
                        	iRet = PD_ERR;
                	}
		}
		else {
DEBUGLOG(("UpdateContext:: EncType Not Found\n"));
ERRLOG("MMSChannel:UpdateContext:: EncType Not Found\n");
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

int     process_input_txn(hash_t *hContext,
                                const hash_t *hRequest,
                                hash_t *hResponse)
{
        int     iRet = PD_OK;
        char*   csTxnCode = NULL;
        char*   csHandler = NULL;
DEBUGLOG(("process_intput_txn:: \n"));

DEBUGLOG(("process_input\n"));
        if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_input_txn:txn_code = [%s]\n",csTxnCode));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("process_input_txn:txn_code not found\n"));
        }

        if (iRet == PD_OK) {
                TxnObjPtr = CreateObj(TxnPtr,"TxnMmsOnUsCOM","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
        }
        if (iRet == PD_OK ) {
                csHandler = (char*) malloc (PD_TMP_BUF_LEN +1);
                sprintf(csHandler,"TxnMmsOnUs%s",csTxnCode);
DEBUGLOG(("process_input_txn Create Txn Object [%s]\n",csHandler));
                TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
                FREE_ME(csHandler);

                iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("iRet = [%d]\n",iRet));
        }

DEBUGLOG(("process_input() exit iRet = [%d]\n",iRet));
        return iRet;

}


