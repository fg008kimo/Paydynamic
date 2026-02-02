#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include "queue_utility.h"
#include "XPYChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"

char	cDebug;

void XPYChannel(char	cdebug)
{
	cDebug = cdebug;
}


OBJPTR(DB);
OBJPTR(Msg);
OBJPTR(Txn);


int     UpdateContext(hash_t* hContext);
int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response);

int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t outMsg)
{
	hash_t	*hRequest,*hResponse;
	hex_t   *h_msg;
	struct msg_t* msg;

	long	lResponseQueueMtype;
        long    lKey; 


	int	iRet = INT_NO_ERR;
	int     iInternalErr = 0;

	char*	csChannelCode = strdup("");
	char*	csTxnCode = strdup("");
	char*	csTxnSeq = strdup("");
	char*	csBuf;

	char*   csMerchantId = strdup("");
        char*   csMerchantRef = strdup("");
        char*   csProcessType = strdup("");
        char*   csProcessCode = strdup("");
	char*   csTxnDesc = strdup("");
	
DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);



	if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("response queue mtype = [%ld]\n",lResponseQueueMtype));
	}
	else  {
DEBUGLOG(("unable to get response queue mtype\n"));
		iRet = PD_ERR;
	}
	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
/* set default return channel code */
		PutField_CString(hResponse,"channel_code",csChannelCode);
DEBUGLOG(("channel code = [%s]\n",csChannelCode));
	}
	else  {
DEBUGLOG(("unable to get channel code queue mtype\n"));
		iRet = PD_ERR;
	}

/* Set define return channel */
	PutField_CString(hContext,"channel_code",csChannelCode);
DEBUGLOG(("Call XpyMsg\n"));
	if (iRet == PD_OK) {
        	MsgObjPtr = CreateObj(MsgPtr,"XpyMsg","BreakDownMsg");
        	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
               		iRet = INT_BREAKDOWN_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
ERRLOG("BreakDown XpyMsg Error\n");
DEBUGLOG(("process_txn:BreakDown XpyMsg Error\n"));
        	}
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
        
                DBObjPtr = CreateObj(DBPtr,"DBTxnCode","FindTxnCode");
                if (!(*DBObjPtr)(csTxnCode,
                                 csTxnDesc,
                                        csProcessType,
                                        csProcessCode)) {
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find TxnCode\n"));
ERRLOG("WEBChannel:Unsupported transaction [%s][%s]\n",csProcessType,csProcessCode);
                }
                else {
                        PutField_CString(hContext,"txn_code",csTxnCode);
                        PutField_CString(hContext,"txn_desc",csTxnDesc);
                        PutField_CString(hResponse,"txn_code",csTxnCode);
DEBUGLOG(("process_txn:TxnCode = [%s]\n",csTxnCode));
                }
        }

	if (iRet == PD_OK) {
DEBUGLOG(("Call XpyMsg InitReplyFromRequest\n"));
                MsgObjPtr = CreateObj(MsgPtr,"XpyMsg","initReplyFromRequest");
                if ((*MsgObjPtr)(hRequest,hResponse) != PD_OK)  {
                        iRet = INT_BREAKDOWN_ERR;
                        PutField_Int(hContext,"internal_error",iRet);
                }
	}

	if (iRet == PD_OK) {
                if (!GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Merchant Id Not found\n"));
                }

                if (!GetField_CString(hRequest,"merchant_ref",&csMerchantRef)) {
DEBUGLOG(("Merchant Ref Not Found\n"));
                }

        }

	if (iRet == PD_OK) {    
                iRet  = (UpdateContext(hContext));
        }

	
        if (iRet == PD_OK) {
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchMerchantRef");
                if ((unsigned long)(DBObjPtr)(csMerchantId,csMerchantRef) == PD_FOUND) {
                        iRet = INT_DUP_MERCHANT_REF;
                        PutField_Int(hContext,"internal_error",INT_DUP_MERCHANT_REF);
ERRLOG("Channel:[XPY] - MerchantId[%s][%s]Duplicate Merchant Ref\n",csMerchantId,csMerchantRef);
DEBUGLOG(("Channel:[XPY] - MerchantId[%s][%s]Duplicate Merchant Ref\n",csMerchantId,csMerchantRef));
                }
        }

	
        if (iRet == PD_OK) {
/* add default psp_pd to avoid insert error */
                PutField_CString(hContext,"psp_id",PD_DEFAULT_PSP);
                iRet = process_input_txn(hContext,hRequest,hResponse);
        }


	
	if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iInternalErr))  {
		csBuf = (char*) malloc (128);
                sprintf(csBuf,"%d",iInternalErr);
                PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("Result_Code = %s\n",csBuf));
                FREE_ME(csBuf);

/* Front End txn mode */
		PutField_CString(hResponse,"txn_mode",PD_FE_TXN);
                MsgObjPtr = CreateObj(MsgPtr,"XpyMsg","FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));
                if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) == PD_OK) {
                }

DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
                GetField_Long(hContext,"queue_key",&lKey);
DEBUGLOG(("key = [%ld]\n",lKey));
                msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                msg->mtype  = lResponseQueueMtype;
                memset(msg->mtext,0,sizeof(msg->mtext));
                        MQ_build_header((unsigned char*)msg->mtext,
                        MQ_RESP,
                        "WEB");
                memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

               iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
	       FREE_ME(h_msg);
               FREE_ME(msg);
	}

	FREE_ME(hRequest);
	FREE_ME(hResponse);
	FREE_ME(csChannelCode);
	FREE_ME(csTxnCode);
	FREE_ME(csTxnSeq);
	FREE_ME(csTxnDesc);
	FREE_ME(csProcessType);
	FREE_ME(csProcessCode);
	FREE_ME(csMerchantId);
	FREE_ME(csMerchantRef);
DEBUGLOG(("process_txn RET =[%d] Internal Error = [%d]\n",iRet,iInternalErr));
	return iRet;
}


int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response)
{
        int     iRet = PD_OK;
	char*	csHandler = NULL;
	char*	csTxnCode = NULL;
DEBUGLOG(("process_input\n"));

	if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_input_txn:txn_code = [%s]\n",csTxnCode));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("process_input_txn:txn_code not found\n"));
        }
        if (iRet == PD_OK) {
        	TxnObjPtr = CreateObj(TxnPtr,"TxnXpyByUsCOM","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext,Request,Response);
        }

        if (iRet == PD_OK ) {
                csHandler = (char*) malloc (20);
                sprintf(csHandler,"TxnXpyByUs%s",csTxnCode);
DEBUGLOG(("process_input_txn Create Txn Object [%s]\n",csHandler));
                TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
                FREE_ME(csHandler);

                iRet = (unsigned long)(*TxnObjPtr)(hContext,Request,Response);
DEBUGLOG(("iRet = [%d]\n",iRet));
        }

        FREE_ME(csTxnCode);

DEBUGLOG(("process_input() exit\n"));
        return iRet;
}



int     UpdateContext(hash_t* hContext)
{
	int	iRet = PD_OK;
        long    lKey;

        lKey = GetMQKey((unsigned char*)"XPAYRSPQ");
        PutField_Long(hContext,"queue_key",lKey);




	return iRet;
}

                                        
