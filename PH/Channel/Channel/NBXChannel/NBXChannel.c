/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/02              Cody Chan
*/


#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "NBXChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"
#include "dbutility.h"
#include "langconvert.h"

#define	PD_ACK_RESEND	"resend_nbx_rck.sh"
char	cDebug;

void NBXChannel(char	cdebug)
{
	cDebug = cdebug;
}


OBJPTR(DB);
OBJPTR(Msg);
OBJPTR(Txn);
OBJPTR(BO);

int     UpdateContext(hash_t* hContext);
int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest);
int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse);

int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response);
int     process_resp_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg);

int     process_NBX_bounce_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg);
int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	hex_t   *h_msg;
	struct msg_t* msg;
	hash_t	*hRequest,*hResponse;

	long	lResponseQueueMtype;
	long    lKey;


	int	iRet = INT_NO_ERR;
	int     iInternalErr = 0;

	char*	csTxnSeq;
	char*	csChannelCode;
	char*	csTxnCode;
	char*	csTxnDesc;
	char*	csProcessType;
	char*	csProcessCode;
	char*	csBuf;
	char	cTxnType;
	char*	csMerchantId;
	char*	csMerchantRef;
	char*	csPtr;
	
DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);

	csTxnCode = (char*) malloc (PD_TXN_CODE_LEN +1 );
	csTxnDesc = (char*) malloc (PD_DESC_LEN +1 );

	GetField_Char(hContext,"txn_type",&cTxnType);
DEBUGLOG(("txn type = [%c]\n",cTxnType));


	PutField_Char(hContext,"dont_convert",PD_DOPD_CONVERT);
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
	if (cTxnType ==  MQ_RESP ) {
                iRet  = (UpdateContext(hContext));
DEBUGLOG(("updatecontext = [%d]\n",iRet));
		if (iRet == PD_OK) {	
DEBUGLOG(("call process_resp_txn\n"));
			return process_resp_txn(hContext,inMsg,outMsg);
		}
		else 
			return iRet;
		
	}
	else if (cTxnType == MQ_BOUNCE_BACK) {
DEBUGLOG(("Bounce Backup Txn!!!\n"));
		return process_NBX_bounce_txn(hContext,inMsg,outMsg);
	}

/* Set define return channel */
	PutField_CString(hContext,"channel_code",csChannelCode);
	if (iRet == PD_OK) {
DEBUGLOG(("Call NbxMsg\n"));
        	MsgObjPtr = CreateObj(MsgPtr,"NbxMsg","BreakDownMsg");
        	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
               		iRet = INT_BREAKDOWN_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
ERRLOG("BreakDown WEBMsg Error\n");
DEBUGLOG(("process_txn:BreakDown WEBMsg Error\n"));
        	}
	}
        if (iRet == PD_OK) {
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

		DBObjPtr = CreateObj(DBPtr,"DBTxnCode","FindTxnCode");
                if (!(*DBObjPtr)(csTxnCode,
                                 csTxnDesc,
                                 csProcessType,
                                 csProcessCode)) {
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext,"internal_error",INT_INVALID_TXN);
DEBUGLOG(("process_txn:Can't Find TxnCode\n"));
ERRLOG("NBXChannel:Unsupported transaction [%s][%s]\n",csProcessType,csProcessCode);
                }
                else {
DEBUGLOG(("try to create obj 3\n"))
                        PutField_CString(hContext,"txn_code",csTxnCode);
                        PutField_CString(hResponse,"txn_code",csTxnCode);
DEBUGLOG(("process_txn:TxnCode = [%s]\n",csTxnCode));
                }
//Response Process Type
		csProcessType[PD_PROCESS_TYPE_LEN-1] = PD_PROCESS_TYPE_RESP_CODE;
			PutField_CString(hResponse,"process_type",csProcessType);
        }
	


	if ((iRet == PD_OK) && strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
               	if (!GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Merchant Id Not found\n"));
               	}
		else {
DEBUGLOG(("Merchant Id = [%s]\n",csMerchantId));
		}

               	if (!GetField_CString(hRequest,"merchant_ref",&csMerchantRef)) {
DEBUGLOG(("Merchant Ref Not Found\n"));
               	}
		else {
DEBUGLOG(("Merchant Ref = [%s]\n",csMerchantRef));
		}
//txn seq 
        	GetField_CString(hContext,"txn_seq",&csTxnSeq);


		if (iRet == PD_OK ) {
			MsgObjPtr = CreateObj(MsgPtr,"NbxMsg","initReplyFromRequest");
               		if ((*MsgObjPtr)(hRequest,hResponse) != PD_OK)  {
                       		iRet = INT_BREAKDOWN_ERR;
                       		PutField_Int(hContext,"internal_error",iRet);
               		}
		}

		if (iRet == PD_OK) {
               		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","MatchMerchantRef");
               		if ((unsigned long)(DBObjPtr)(csMerchantId,csMerchantRef) == PD_FOUND) {
                       		iRet = INT_DUP_MERCHANT_REF;
                       		PutField_Int(hContext,"internal_error",INT_DUP_MERCHANT_REF);
ERRLOG("Channel:[WEB] - MerchantId[%s][%s]Duplicate Merchant Ref\n",csMerchantId,csMerchantRef);
DEBUGLOG(("Channel:[WEB] - MerchantId[%s][%s]Duplicate Merchant Ref\n",csMerchantId,csMerchantRef));
               			AddTxnLog(hContext,hRequest);
               		}
		}

		if (iRet == PD_OK ) {
               		iRet = AddTxnLog(hContext,hRequest);
       		}


	}

	if (iRet == PD_OK) {
/* add default psp_pd to avoid insert error */
		PutField_CString(hContext,"psp_id",PD_DEFAULT_PSP);
               	iRet = process_input_txn(hContext,hRequest,hResponse);
        }


	if (strcmp(csTxnCode, PD_WITHDRAW_BATCH_TXN_CODE))   {//none batch
		if (iRet == PD_OK || GetField_Int(hContext,"internal_error",&iInternalErr))  {

	 		csBuf = (char*) malloc (128);
               		sprintf(csBuf,"%d",iInternalErr);
                	PutField_CString(hResponse,"response_code",csBuf);
DEBUGLOG(("Result_Code = %s iInternetalErr = [%d]\n",csBuf,iInternalErr));
                	FREE_ME(csBuf);
                //PutField_Char(hContext,"ar_ind",PD_ACCEPT); /* update until come back PSP */
                	PutField_Char(hContext,"status",PD_TO_PSP);
                	PutField_Int(hContext,"internal_code",iInternalErr);

                	if (iInternalErr != 0 ) {
DEBUGLOG(("*****Format Out Reject Message\n"));
                        	PutField_Char(hContext,"ar_ind",PD_REJECT);
                        	PutField_Char(hResponse,"ar_ind",PD_REJECT);
                		PutField_Char(hContext,"status",PD_COMPLETE);
                		PutField_Char(hResponse,"status",PD_COMPLETE);
				iRet = PD_OK;
                	}
                	else {
                        	iInternalErr = INT_NO_ERR;

				if (!strcmp(csTxnCode, PD_INITIAL_TXN_CODE))   {// initial
					PutField_Char(hResponse,"status",PD_INIT);
					PutField_Char(hContext,"status",PD_INIT);
				}
				else {
                			PutField_Char(hResponse,"status",PD_TO_PSP);
DEBUGLOG(("here\n"));
				}

			}


			if (iRet == PD_OK) {
				if (iInternalErr != 0) {
DEBUGLOG(("put failure_url into redirect_url\n"));
					if (GetField_CString(hRequest,"failure_url",&csPtr)) {
						PutField_CString(hResponse,"redirect_url",csPtr);
						PutField_Int(hResponse,"internal_error",iInternalErr);
					}
				}

                		if (iInternalErr != 0 && !(strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) ) {
					MsgObjPtr = CreateObj(MsgPtr,"OlnMsg","FormatFEMsg");
				}else {
					MsgObjPtr = CreateObj(MsgPtr,"OlnMsg","FormatMsg");
DEBUGLOG(("return from FormatMsg\n"));
				}

               			h_msg = (hex_t*) malloc (sizeof(hex_t));
               			if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) == PD_OK && iInternalErr == 0) {
               				iRet = UpdateTxnLog(hContext,hRequest,hResponse);
DEBUGLOG(("iRet = [%d] updatetxnlog internal error = [%d]\n",iRet,iInternalErr));
               			}
				else {
DEBUGLOG(("FormatMsg error\n"));
				}

		
DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
DEBUGLOG(("h_msg->msg = [%s]\n",h_msg->msg));
				GetField_Long(hContext,"queue_key",&lKey);
				msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
				msg->mtype  = lResponseQueueMtype;
				long	lRemoteKey = 0l;
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

                		iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);

				FREE_ME(h_msg);
                		FREE_ME(msg);
			}
		}
		else {
ERRLOG("NBXCHANNEL internal error? [%d]\n",iRet);
		}
	}

//NLOG("[%s]Normal RET = [%d]{%s[%s]}\n",csTxnSeq,iRet,csTxnCode,csChannelCode);
	FREE_ME(hRequest);
	FREE_ME(hResponse);
	FREE_ME(csTxnCode);
	FREE_ME(csTxnDesc);
	return iRet;
}


int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response)
{
        int     iRet = PD_OK;
	char*	csHandler = NULL;
	char*   csTxnCode;
DEBUGLOG(("process_input\n"));
	if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("process_input_txn:txn_code = [%s]\n",csTxnCode));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("process_input_txn:txn_code not found\n"));
        }
	        
        if (iRet == PD_OK) {
                TxnObjPtr = CreateObj(TxnPtr,"TxnCctOnUsCOM","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext,Request,Response);
        }     

        if (iRet == PD_OK ) {
                csHandler = (char*) malloc (20);
		sprintf(csHandler,"TxnOlnOnUs%s",csTxnCode);
DEBUGLOG(("process_input_txn Create Txn Object [%s]\n",csHandler));
                TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
                FREE_ME(csHandler);
                iRet = (unsigned long)(*TxnObjPtr)(hContext,Request,Response);
DEBUGLOG(("iRet = [%d]\n",iRet));
        }

DEBUGLOG(("process_input() exit iRet = [%d]\n",iRet));
        return iRet;
}



int     UpdateContext(hash_t* hContext)
{
	int	iRet = PD_OK;
        long    lKey;
	hash_t  *hRec;
	char    *csCode;
        char    *csValue;
	char*	csQueueName;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

//        lKey = GetMQKey((unsigned char*)"WEBRSPQ");
	if (GetField_CString(hContext,"reply_queue",&csQueueName)) {
DEBUGLOG(("UpdateContext:reply queue = [%s]\n",csQueueName));
		lKey = GetMQKey((unsigned char*)csQueueName);
        	PutField_Long(hContext,"queue_key",lKey);
DEBUGLOG(("UpdateContext:reply queue key = [%ld]\n",lKey));
	}


        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("UpdateContext: return \n"));
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));
                                                PutField_CString(hContext,"PHDATE",csValue);
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("UpdateContext::Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

	if (iRet == PD_OK) {
		char*	csValueTmp;
		csValueTmp = (char*) malloc (128);
        	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)(PD_BASED_CCY,csValueTmp) == FOUND) {
DEBUGLOG(("UpdateContext::based ccy  = [%s]\n",csValueTmp));
                        PutField_CString(hContext,"based_ccy",csValueTmp);
                }
                else {
                        iRet = INT_ERR;
ERRLOG("UpdateContext::Unable to find based ccy\n");
                }
		FREE_ME(csValueTmp);
        }

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(csCode);
        FREE_ME(csValue);
        FREE_ME(csQueueName);
DEBUGLOG(("UpdateContext::iRet = [%d]\n",iRet));

	return iRet;
}

                                        
int     AddTxnLog(const hash_t *hContext,
                const hash_t* hRequest)
{                       
        hash_t  *hDetail;
        char    *csTmp;
        int iRet = PD_OK;

	double	dTmp;

        hDetail= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hDetail,0); 
        if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hDetail,"txn_seq",csTmp);
        
                PutField_CString(hDetail,"add_user",PD_UPDATE_USER);

                                

/**** From Request */
		if (GetField_CString(hRequest,"txn_amt",&csTmp)) {
			int iCheck = PD_FALSE;
DEBUGLOG(("Authorize()txn_amt from request[%s]\n",csTmp));
                       	iCheck = is_numeric(csTmp);
                        if(iCheck==PD_FALSE){
DEBUGLOG(("AddTxnLog::txn_amt Invalid[%s]\n",csTmp));
                        }
                        else {
                        	dTmp = myctod((const unsigned char *)csTmp,strlen(csTmp) - PD_DECIMAL_LEN,PD_DECIMAL_LEN);
                                PutField_Double(hDetail,"txn_amt",dTmp);
DEBUGLOG(("AddTxnLog txn_amt = [%f]\n",dTmp));
                       }
DEBUGLOG(("UpdateTxnLog:: txn_amt = [%f]\n",dTmp));
                        PutField_Double(hDetail,"txn_amt",dTmp);
                }

/* remark */
                if (GetField_CString(hRequest,"remark",&csTmp)) {
DEBUGLOG(("AddTxnLog:: Remark = [%s]\n",csTmp));
                        PutField_CString(hDetail,"remark",csTmp);
                }

/* merchant no */
                if (GetField_CString(hRequest,"merchant_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: merchant_id = [%s]\n",csTmp));
                        PutField_CString(hDetail,"merchant_id",csTmp);
                }
/* merchant ref */
                if (GetField_CString(hRequest,"merchant_ref",&csTmp)) {
DEBUGLOG(("AddTxnLog:: merchant_ref = [%s]\n",csTmp));
                        PutField_CString(hDetail,"merchant_ref",csTmp);
                }


                if (GetField_CString(hRequest,"transmission_datetime",&csTmp)) {
DEBUGLOG(("AddTxnLog:: transmission_datetime = [%s]\n",csTmp));
                        PutField_CString(hDetail,"transmission_datetime",csTmp);
                }

                if (GetField_CString(hRequest,"tm_date",&csTmp)) {
DEBUGLOG(("AddTxnLog:: tm_date = [%s]\n",csTmp));
                        PutField_CString(hDetail,"tm_date",csTmp);
                }
                if (GetField_CString(hRequest,"tm_time",&csTmp)) {
DEBUGLOG(("AddTxnLog:: tm_time = [%s]\n",csTmp));
                        PutField_CString(hDetail,"tm_time",csTmp);
                }

/* service code */
                if (GetField_CString(hRequest,"service_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: service_code = [%s]\n",csTmp));
                        PutField_CString(hDetail,"service_code",csTmp);
                }

/* client ip */
                if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
DEBUGLOG(("AddTxnLog:: client_ip = [%s]\n",csTmp));
                        PutField_CString(hDetail,"ip_addr",csTmp);
                }

/* user_agent*/
                if (GetField_CString(hRequest,"user_agent",&csTmp)) {
DEBUGLOG(("AddTxnLog:: user_agent = [%s]\n",csTmp));
                        PutField_CString(hDetail,"user_agent",csTmp);
                }

/* add to detail ********************************/

/* txn ccy */
                if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTmp));
                        PutField_CString(hDetail,"txn_ccy",csTmp);
                }

/* txn country */
                if (GetField_CString(hRequest,"txn_country",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_country = [%s]\n",csTmp));
                        PutField_CString(hDetail,"txn_country",csTmp);
                }

/* pay method */
                if (GetField_CString(hRequest,"pay_method",&csTmp)) {
DEBUGLOG(("AddTxnLog:: pay_method  = [%s]\n",csTmp));
                        PutField_CString(hDetail,"pay_method",csTmp);
                }


/* language  */
                if (GetField_CString(hRequest,"language",&csTmp)) {
DEBUGLOG(("AddTxnLog:: language = [%s]\n",csTmp));
                        PutField_CString(hDetail,"language",csTmp);
                }

/* success url  */
                if (GetField_CString(hRequest,"success_url",&csTmp)) {
DEBUGLOG(("AddTxnLog:: success_url = [%s]\n",csTmp));
                        PutField_CString(hDetail,"success_url",csTmp);
                }

/* failure url  */
                if (GetField_CString(hRequest,"failure_url",&csTmp)) {
DEBUGLOG(("AddTxnLog:: failure_url = [%s]\n",csTmp));
                        PutField_CString(hDetail,"failure_url",csTmp);
                }




                PutField_Char(hDetail,"status",PD_PROCESSING);

		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Add");
                iRet = (unsigned long) ((*DBObjPtr)(hDetail));

		if (iRet == PD_OK ) {
                        DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","AddDetail");
                        iRet = (unsigned long) ((*DBObjPtr)(hDetail));
                }
        }
        else
                iRet = PD_ERR;

        hash_destroy(hDetail);
        FREE_ME(hDetail);
        FREE_ME(csTmp);
DEBUGLOG(("AddTxnLog RET = [%d]\n",iRet));
        return  iRet;
}

int     UpdateTxnLog(const hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse)
{                       
        hash_t  *hTxn;
        char    *csTmp = strdup("");
        char    *csTxnSeq = strdup(""); 
	char	*csTag;
	char	*csTxnCode;
        char    cTmp;
        int     iTmp;
        double  dTmp;   
        int 	iRet = PD_OK; 
                
DEBUGLOG(("UpdateTxnLog::()\n"));

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0); 


	csTag = (char*) malloc (PD_TMP_BUF_LEN +1);


        if (GetField_CString(hContext,"txn_code",&csTxnCode)) {
DEBUGLOG(("UpdateTxnLog:: txn_code = [%s]\n",csTxnCode));
	}
	else {
		csTxnCode = strdup(" ");
DEBUGLOG(("UpdateTxnLog:: txn_code not found\n"));
	}
	if (!strcmp(csTxnCode,PD_INITIAL_REQ_TXN_CODE)) {
		strcpy(csTag,"from_txn_seq");
	}
	else {
		strcpy(csTag,"txn_seq");
	}

DEBUGLOG(("UpdateTxnlog try to get txn seq\n"));

        if (GetField_CString(hContext,csTag,&csTxnSeq)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);
                        
	        PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
/* Context */   
                if (GetField_CString(hContext,"org_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: org_txn_seq = [%s]\n",csTmp));
                        PutField_CString(hTxn,"org_txn_seq",csTmp);
                }
                if (GetField_Char(hContext,"status",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: status = [%c]\n",cTmp));
                        PutField_Char(hTxn,"status",cTmp);
                }
                
                if (GetField_Char(hContext,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateTxnLog:: ar_ind = [%c]\n",cTmp));
                        PutField_Char(hTxn,"ar_ind",cTmp);
                }

                if (GetField_Int(hContext,"internal_code",&iTmp)) {
DEBUGLOG(("UpdateTxnLog:: internal_code = [%d]\n",iTmp));
                	PutField_Int(hTxn,"internal_code",iTmp);
                }

                if (GetField_CString(hContext,"merchant_client_id",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: merchant_client_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"client_id",csTmp);
                }

                if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"txn_amt",dTmp);
                }
                if (GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: net_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"net_amt",dTmp);
                }

		if(GetField_Double(hContext,"ex_rate",&dTmp)){
DEBUGLOG(("UpdateTxnLog:: ex_rate = [%f]\n",dTmp));
                        PutField_Double(hTxn,"ex_rate",dTmp);
		}

                if(GetField_Char(hContext,"ex_party",&cTmp)){
DEBUGLOG(("UpdateTxnLog:: ex_party = [%c]\n",cTmp));
                        PutField_Char(hTxn,"ex_supplier",cTmp);
		}

/* request */
                if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: ip_addr = [%s]\n",csTmp));
                        PutField_CString(hTxn,"ip_addr",csTmp);
                }

/* Response */
                if (GetField_CString(hResponse,"expiry_date",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: expiry_date = [%s]\n",csTmp));
                        PutField_CString(hTxn,"expiry_date",csTmp);
                }
                if (GetField_CString(hResponse,"response_code",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: response_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"response_code",csTmp);
                }
                if (GetField_Double(hResponse,"net_amt",&dTmp) || GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: net_amt = [%f]\n",dTmp));
                        PutField_Double(hTxn,"net_amt",dTmp);
                }

/* detail */
/************/
                if (GetField_CString(hContext,"internal_bank_code",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: internal_bank_code = [%s]\n",csTmp));
                        PutField_CString(hTxn,"bank_code",csTmp);
		}

                if (GetField_CString(hRequest,"pay_method",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: pay_method = [%s]\n",csTmp));
                        PutField_CString(hTxn,"pay_method",csTmp);
		}
        
/* txn psp detail */
		if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: psp_id = [%s]\n",csTmp));
                        PutField_CString(hTxn,"psp_id",csTmp);
		}
		if (GetField_Double(hContext,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: psp_txn_amt = [%lf]\n",dTmp));
                        PutField_Double(hTxn,"txn_amount",dTmp);
		}
		if (GetField_CString(hContext,"psp_txn_ccy",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: psp_txn_ccy = [%s]\n",csTmp));
                        PutField_CString(hTxn,"txn_ccy",csTmp);
		}


                if (iRet == PD_OK) {
                        DBObjPtr = CreateObj(DBPtr,"DBCctTxn","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
                }       

        }
        else                    
                iRet = PD_ERR;

        hash_destroy(hTxn);
        FREE_ME(hTxn);          

                        
        FREE_ME(csTmp);
        FREE_ME(csTxnSeq); 
	FREE_ME(csTag);
        return  iRet;   
}


int     process_resp_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	int	iRet = PD_OK;
ERRLOG("NBXChannel::process_resp_txn should not have this function\n");
DEBUGLOG(("NBXChannel::process_resp_txn should not have this function\n"));
DEBUGLOG(("process_resp_txn::Normal RET = [%d]\n",iRet));
	return iRet;
}
	


int     process_NBX_bounce_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	int	iRet = PD_OK;
	char	*csMerchantId;
	char	*csMerchantRef;
	char	csCmd[PD_MAX_FILE_LEN +1];
	hash_t  *hRequest;

	hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

DEBUGLOG(("process_NBX_bounce_txn:: ()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"OlnMsg","DeBlockWebBounceBackData");
        if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_NBX_bounce_txn:BreakDown OlnMsg Error\n"));
        }
        else {
      		if (GetField_CString(hRequest,"merchant_id",&csMerchantId) && 
		    GetField_CString(hRequest,"merchant_ref",&csMerchantRef)) {
			sprintf(csCmd,"%s %s %s",PD_ACK_RESEND,csMerchantId,csMerchantRef);
DEBUGLOG(("process_NBX_bounce_txn:cmd = [%s]\n",csCmd));
			system(csCmd);
		}
	}

	FREE_ME(hRequest);
	return iRet;
}

int     process_psp_resp_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
DEBUGLOG(("process_psp_resp_txn\n"));
	int	iRet = PD_OK;
	char	*csOrgTxnSeq;
	char	*csChannelCode;
	char	*csTxnCode;
	char	*csPostingDate;
	char	*csOrgPostingDate=NULL;
	char	*csPtr;
	char	cPtr;
	char	cArPtr;
	char    csTmpChannelCode[PD_CHANNEL_CODE_LEN *2  +1];
	char	*csReturnPspChannel;
	int	iUpdateOnly = PD_FALSE;

	double	dTmp;
	long	lKey,lResponseQueueMtype;
	hash_t	*hRequest,*hResponse,*hRsp, *hRec, *hLRsp;
	hex_t   *h_msg;
	recordset_t     *rRecordSet;
	struct	msg_t*	msg;

	int	iVoidTxn = PD_FALSE;

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);

	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResponse,0);

	hRsp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRsp,0);


        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
DEBUGLOG(("process_psp_resp_txn()\n"));

	if (GetField_CString(hContext,"return_psp_channel",&csReturnPspChannel)) {
DEBUGLOG(("process_psp_resp_txn() return psp_channel = [%s]\n",csReturnPspChannel));
	}
	else {
DEBUGLOG(("process_psp_resp_txn() return psp missing!!!!\n"));
ERRLOG("process_psp_resp_txn() return psp missing!!!!\n");
	}

/*HaiPay*/
	if (!strcmp(csReturnPspChannel,PD_CHANNEL_HPAY)) {
        	MsgObjPtr = CreateObj(MsgPtr,"HpyMsg","BreakDownMsg");
	}
/*linkinpay */
	else if (!strcmp(csReturnPspChannel,PD_CHANNEL_LKPAY)) {
        	MsgObjPtr = CreateObj(MsgPtr,"LkpMsg","BreakDownMsg");
	}
/* hohopay */
	else if (!strcmp(csReturnPspChannel,PD_CHANNEL_HHPAY)) {
        	MsgObjPtr = CreateObj(MsgPtr,"HhpMsg","BreakDownMsg");
	}
/*ESKY */
	else if (!strcmp(csReturnPspChannel,PD_CHANNEL_ESKY)) {
        	MsgObjPtr = CreateObj(MsgPtr,"ESkyMsg","BreakDownMsg");
	}
/*TWV */
	else if (!strcmp(csReturnPspChannel,PD_CHANNEL_TWV)) {
        	MsgObjPtr = CreateObj(MsgPtr,"TwvMsg","BreakDownMsg");
	}


        if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
     		iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_psp_resp_txn:BreakDown HPYMsg Error\n"));
       	}
	else {
		if (!GetField_Char(hRequest,"FERESP",&cPtr)) {
			if (GetField_CString(hRequest,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("process_psp_resp_txn:org txn seq = [%s]\n",csOrgTxnSeq));
				PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
                		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn");
                		if ((unsigned long)(DBObjPtr)(csOrgTxnSeq,PD_TO_PSP) != PD_FOUND) {
                     	  	 	iRet = INT_ORG_TXN_NOT_FOUND;
                       	 		PutField_Int(hContext,"internal_error",iRet);

					PutField_CString(hRsp,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("process_psp_resp_txn::org_txn_seq = [%s]\n",csOrgTxnSeq));
                                	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
					cPtr = ' ';
                                	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("process_psp_resp_txn::found record = [%s]\n",csOrgTxnSeq));
                                        	hRec = RecordSet_GetFirst(rRecordSet);
                                        	while (hRec) {
                                                	if (GetField_Char(hRec,"status",&cPtr)){
DEBUGLOG(("process_psp_resp_txn::status = [%c]\n",cPtr));
							}
                                                	if (GetField_Char(hRec,"ar_ind",&cArPtr)){
DEBUGLOG(("process_psp_resp_txn::ar_ind = [%c]\n",cArPtr));
							}
							else{
								cArPtr=' ';
							}
							if(GetField_CString(hRec,"txn_code",&csTxnCode)){
DEBUGLOG(("process_psp_resp_txn::txn_code = [%s]\n",csTxnCode));
							}


                                        		hRec = RecordSet_GetNext(rRecordSet);
                                        	}
                               		 }
					if (cPtr == PD_COMPLETE) {
						if(cArPtr == PD_ACCEPT){
							if(strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)){
DEBUGLOG(("*process_psp_resp_txn org txn id [%s] Re-send update txn psp detail!!!\n",csOrgTxnSeq));
ERRLOG("*process_psp_resp_txn org txn id [%s] Re-send update txn psp detail!!!\n",csOrgTxnSeq);
								iUpdateOnly = PD_TRUE;
/* update psp detaill */
							}
							else{
								
DEBUGLOG(("process_psp_resp_txn:: Void Txn\n"));
								iVoidTxn = PD_TRUE;
								iRet = PD_OK;
								
							}
						}
						else{
DEBUGLOG(("*process_psp_resp_txn org txn id [%s] Re-send Message where AR_IND[%c]\n",csOrgTxnSeq,cArPtr));
ERRLOG("*process_psp_resp_txn org txn id [%s] Re-send Message where AR_IND[%c]\n",csOrgTxnSeq,cArPtr);
							iRet = PD_OK;
						}
					}
					else {
DEBUGLOG(("*process_psp_resp_txn org txn id [%s] not found!\n",csOrgTxnSeq));
ERRLOG("*process_psp_resp_txn org txn id [%s] not found!\n",csOrgTxnSeq);
					}
				}
                	}
			else  {
				iRet = INT_TXN_ID_NOT_FOUND;	
DEBUGLOG(("process_psp_resp_txn txn id not found\n"));
ERRLOG("process_psp_resp_txn  txn id not found\n");
			}
/*VerifyPspSign*/
			if (iRet == PD_OK || iUpdateOnly == PD_TRUE) {

DEBUGLOG(("process_psp_resp_txn::VerifySign\n"));
				char*	csPspId=strdup("");
				char*	csTmp;
		                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                		if (!(*DBObjPtr)(csOrgTxnSeq,rRecordSet)) {
		                        hRec = RecordSet_GetFirst(rRecordSet);
               				        while(hRec){
                                		if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("process_psp_resp_txn::GetTxnPsp - psp_id = [%s]\n",csPspId));
							PutField_CString(hContext,"org_psp_id",csPspId);
                                		}

                                		if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
DEBUGLOG(("process_psp_resp_txn::GetTxnPsp - psp_txn_ccy = [%s]\n",csTmp));
							PutField_CString(hContext,"org_psp_txn_ccy",csTmp);
                                		}

                                		if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("process_psp_resp_txn::GetTxnPsp - txn amt = [%lf]\n",dTmp));
							PutField_Double(hContext,"org_psp_txn_amt",dTmp);
                                		}

                                		hRec = RecordSet_GetNext(rRecordSet);
                        		}
                		}
                		else{
ERRLOG("process_psp_resp_txn:: PSP NOT FOUND\n");
DEBUGLOG(("hannel process_psp_resp_txn:: PSP NOT FOUND\n"));
                		}
		                DBObjPtr = CreateObj(DBPtr,"DBPspKeys","GetPspKey");
                		if (!(*DBObjPtr)(csPspId,PD_PTK_KEY_NAME,rRecordSet)) {
		                        hRec = RecordSet_GetFirst(rRecordSet);
               				        while(hRec){
                                		if (GetField_CString(hRec,"key_value",&csTmp)) {
DEBUGLOG(("process_psp_resp_txn::GetTxnPsp - psp_key = [%s]\n",csTmp));
                               	         		PutField_CString(hContext,"merchant_key",csTmp);
                                		}
                                		hRec = RecordSet_GetNext(rRecordSet);
                        		}
                		}
                		else{
ERRLOG("process_psp_resp_txn::GetTxnPSP - no psp_key for [%s]\n",csPspId);
DEBUGLOG(("process_psp_resp_txn::GetTxnPSP - no psp_key for [%s]\n",csPspId));
                		}

/* VerifyPspSign */
				BOObjPtr = CreateObj(BOPtr,"BOSecurity","VerifyPspSign");
                                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
				if (iRet != PD_OK) {
ERRLOG("process_psp_resp_txn::Invalid Sign!! txn id [%s] dropped\n",csOrgTxnSeq);
				}
DEBUGLOG(("process_psp_resp_txn::VerifySign Completed!!!\n"));
			}
/* Get Txn Detail */
			if (iRet == PD_OK) {
				RecordSet_Destroy(rRecordSet);
                		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                		if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("process_psp_resp_txn::found record = [%s]\n",csOrgTxnSeq));
                        		hRec = RecordSet_GetFirst(rRecordSet);
                        		while (hRec) {
/*org txn country */
                                		if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("process_psp_resp_txn::Org txn country = [%s]\n",csPtr));
							PutField_CString(hContext,"org_txn_country",csPtr);
                                		}
/*org txn ccy */
                                		if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("process_psp_resp_txn::Org txn ccy = [%s]\n",csPtr));
							PutField_CString(hContext,"org_txn_ccy",csPtr);
                                		}
/* pay_method */
                                		if (GetField_CString(hRec,"pay_method",&csPtr)) {
DEBUGLOG(("process_psp_resp_txn::Org pay_method = [%s]\n",csPtr));
							PutField_CString(hContext,"org_pay_method",csPtr);
                                		}

 	                              		hRec = RecordSet_GetNext(rRecordSet);
                        		}
				}
			}
/* check if it is none same date response */
			if (iRet == PD_OK) {
                       		if (GetField_CString(hContext,"PHDATE",&csPostingDate)) {
DEBUGLOG(("process_psp_resp_txn::Posting Date = [%s]\n",csPostingDate));
					if (strcmp(csPostingDate,csOrgPostingDate)) {
						hLRsp = (hash_t*) malloc (sizeof(hash_t));
						hash_init(hLRsp,0);
/* txn seq */
						PutField_CString(hLRsp,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("process_psp_resp_txn::!!! none same date response \n"));
ERRLOG("[%s]-[%s]none same date response [%s][%s]\n",csTxnCode,csOrgTxnSeq,csPostingDate,csOrgPostingDate);


/* current posting date */
						PutField_CString(hLRsp,"host_posting_date",csPostingDate);
/* local tm date */
						if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                        				PutField_CString(hLRsp,"local_tm_date",csPtr);
                				}

				                if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                        				PutField_CString(hLRsp,"local_tm_time",csPtr);
                				}
/* create and update user */
                        			PutField_CString(hLRsp,"create_user",PD_UPDATE_USER);
                        			PutField_CString(hLRsp,"update_user",PD_UPDATE_USER);

      						DBObjPtr = CreateObj(DBPtr,"DBNonPostingDateResp","Add");
                				iRet = (unsigned long)(DBObjPtr)(hLRsp);
       						hash_destroy(hLRsp);
       						FREE_ME(hLRsp);          
						
					}
					else {
DEBUGLOG(("process_psp_resp_txn::!!! same date response \n"));
					}
                        	}
			}

			if (iRet == PD_OK && iVoidTxn == PD_TRUE) {
				char*   csTxn;
                                csTxn = (char*) malloc (sizeof(PD_TMP_BUF_LEN));
                                sprintf(csTxn,"TxnWebOnUs%s",PD_WITHDRAW_VOID_TXN_CODE);
                                TxnObjPtr = CreateObj(TxnPtr,csTxn,"Authorize");
                                iRet=(unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("process_psp_resp_txn:: iRet [%d] from %s\n",iRet,csTxn));
                                if (iRet == PD_OK)
                                	iRet = PD_SKIP_OK;
			}
			else {	


				if (iRet == PD_OK && iUpdateOnly != PD_TRUE)  {
DEBUGLOG(("process_psp_resp_txn Call UpdateRespTxnLog\n"));
					iRet = UpdateRespTxnLog(hContext,hRequest,hResponse);
/* commit txn before send out ack */
					TxnCommit();
				}

/* Send ACK */
				if ((iRet == PD_OK  && iUpdateOnly != PD_TRUE) && 
					(!(strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE)) ||
					!(strcmp(csTxnCode,PD_INITIAL_TXN_CODE)))
					) {
      					TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsACK","Authorize");
               				iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
				}
/*********/
			}

		}
		else {
DEBUGLOG(("process_psp_resp_txn FERESP*** DO NOTHING\n"));

      			TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsFEK","Authorize");
               		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
			if (iRet == PD_OK) {
				if (GetField_CString(hResponse,"channel_code",&csChannelCode)) {
DEBUGLOG(("process_psp_resp_txn org channel code [%s]found\n",csChannelCode));
				}

				sprintf(csTmpChannelCode,"%c%c%cMsg",csChannelCode[0],tolower(csChannelCode[1]),tolower(csChannelCode[2]));	

DEBUGLOG(("process_psp_resp_txn try to call [%s]->FormatFEMsg\n",csTmpChannelCode));
				MsgObjPtr = CreateObj(MsgPtr,csTmpChannelCode,"FormatFEMsg");
                		h_msg = (hex_t*) malloc (sizeof(hex_t));
                		if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) == PD_OK) {
                		}

DEBUGLOG(("process_psp_resp_txn::h_msg->len = [%d][%s]\n",h_msg->len,h_msg->msg));
				GetField_Long(hContext,"queue_key",&lKey);

				if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("process_psp_resp_txn::response queue mtype = [%ld]\n",lResponseQueueMtype));
				}
                		msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                		msg->mtype  = lResponseQueueMtype;
DEBUGLOG(("process_psp_resp_txn::key = [%ld] mtype = [%ld]\n",lKey,lResponseQueueMtype));

				long lRemoteKey = 0l;

				GetField_Long(hContext,"remote_reply_key",&lRemoteKey);
                		memset(msg->mtext,0,sizeof(msg->mtext));
                        		MQ_build_header((unsigned char*)msg->mtext,
                        		MQ_RESP,
                        		csChannelCode,
					0,
					NULL,
					lRemoteKey);
DEBUGLOG(("process_psp_resp_txn::build header\n"));
                		memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                		msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("process_psp_resp_txn::send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

                		iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);

                		FREE_ME(h_msg);
                		FREE_ME(msg);
			}
			else {
DEBUGLOG(("process_psp_resp_txn:FEK return iRet = [%d]\n",iRet));
			}
		}
	}

       	hash_destroy(hRequest);
       	FREE_ME(hRequest);          

       	hash_destroy(hResponse);
       	FREE_ME(hResponse);          

       	hash_destroy(hRsp);
       	FREE_ME(hRsp);          

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	if (iRet == PD_SKIP_OK)
		iRet = PD_OK;

DEBUGLOG(("process_psp_resp_txn::Normal RET = [%d]\n",iRet));
	return iRet;
}
	


int     UpdateRespTxnLog(hash_t *hContext,
                const hash_t* hRequest,
                const hash_t* hResponse)
{                       
        hash_t  *hTxn,*hPspDetail;
        char    *csTmp;
        char    *csTxnSeq;
	char	*csTxnCode;
	char*	csStatus = strdup("");
	double	dTmp;
        int 	iRet = PD_OK; 
	char	*csResultCode;
	char	*csPspChannelCode;
	char	cStatus;
	



        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0); 

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0); 

	GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("UpdateRespTxnLog:: txn_code = [%s]\n",csTxnCode));

	if(GetField_CString(hContext,"return_psp_channel",&csPspChannelCode)) {
DEBUGLOG(("UpdateRespTxnLog:: return_psp_channel = [%s]\n",csPspChannelCode));
	}
	else {
DEBUGLOG(("UpdateRespTxnLog:: return_psp_channel missing!!\n"));
ERRLOG("NBXChannel::UpdateRespTxnLog:: return_psp_channel missing!!\n");
		iRet = PD_ERR;
	}



        if (GetField_CString(hRequest,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateRespTxnLog:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);
                PutField_CString(hPspDetail,"txn_seq",csTxnSeq);
                        
        	PutField_CString(hTxn,"update_user",PD_UPDATE_USER);

DEBUGLOG(("UpdateRespTxnLog:: get status \n"));
/* response */
                if (GetField_CString(hRequest,"status",&csStatus)) {
DEBUGLOG(("UpdateRespTxnLog:: status = [%s]\n",csStatus));
                        PutField_CString(hPspDetail,"notice_status",csStatus);
                }
		else {
DEBUGLOG(("UpdateRespTxnLog:: status not found\n"));
		}

               	PutField_Char(hTxn,"status",PD_COMPLETE);
DEBUGLOG(("UpdateRespTxnLog:: status = [%c]\n",PD_COMPLETE));
                
		if (!strcmp(csPspChannelCode,PD_CHANNEL_TWV)) {
			csResultCode = strdup(PD_TWV_SUCCESS);
		}
		else if (!strcmp(csPspChannelCode,PD_CHANNEL_ESKY)) {
			csResultCode = strdup(PD_ESKY_SUCCESS);
		}
		else if (!strcmp(csPspChannelCode,PD_CHANNEL_PGEN)) {
			csResultCode = strdup(PD_PGEN_SUCCESS);
		}
		else 
			csResultCode = strdup(PD_CN_PSP_SUCCESS);
		
			
		if (!strcmp(csStatus,csResultCode))   {
                	PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
			cStatus='A';
DEBUGLOG(("UpdateRespTxnLog:: ar_ind = [%c]\n",PD_ACCEPT));
			if (GetField_CString(hContext,"PHDATE",&csTmp)) {
DEBUGLOG(("UpdateRespTxnLog:: approval_date = [%s]\n",csTmp));
                                PutField_CString(hTxn,"approval_date",csTmp);
                        }
			if (!strcmp(csTxnCode,PD_DEPOSIT_TXN_CODE) ||
                            !strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) {
DEBUGLOG(("Handle Post Txn\n"));
				char*	csTxn;
				csTxn = (char*) malloc (PD_TMP_BUF_LEN +1);
				sprintf(csTxn,"TxnWebOnUs%s",csTxnCode);
                                TxnObjPtr = CreateObj(TxnPtr,csTxn,"PostTxn");
       		        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("UpdateRespTxnLog:: response from [%s] = [%d]\n",csTxn,iRet));
				FREE_ME(csTxn);

				if (GetField_Double(hContext,"net_amt",&dTmp)) {
DEBUGLOG(("UpdateRespTxnLog:: net_amt = [%lf]\n",dTmp));
					PutField_Double(hTxn,"net_amt",dTmp);
				}
			}

			else if(!strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)){
DEBUGLOG(("UpdateRespTxnLog:: Call BOPsp CalPspFee\n"));
				BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspFee");
				iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("UpdateRespTxnLog:: BOStat::CalPspFee() result = [%d]\n",iRet));

DEBUGLOG(("UpdateRespTxnLog Call BOBalance::UpdatePayoutResponse\n"));
				PutField_Char(hContext,"response_mode",PD_ACCEPT);

				BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdatePayoutResponse");
				iRet = (unsigned long)(BOObjPtr)(hContext);
				if(iRet!=PD_OK){
DEBUGLOG(("BOBalance::UpdatePayoutResponse failed\n"));
				}

			}


		}
		else {
                	PutField_Char(hTxn,"ar_ind",PD_REJECT);
			cStatus='R';
DEBUGLOG(("UpdateRespTxnLog:: ar_ind = [%c]\n",PD_REJECT));

			if(!strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)){
DEBUGLOG(("UpdateRespTxnLog Call BOBalance::UpdatePayoutAmount\n"));
				PutField_Char(hContext,"bal_trf_mode",PD_I2P);

				BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdatePayoutAmount");
				iRet = (unsigned long)(BOObjPtr)(hContext);
				if(iRet!=PD_OK){
DEBUGLOG(("BOBalance::UpdatePayoutAmount failed\n"));
				}
			}

		}

/* psp detail */
/* error code */
        	if (GetField_CString(hRequest,"error_code",&csTmp)) {
			char *csBuf;
			char *csPspChannelCode;
			int  iDefErr=1;
			int  iIntErr=0;

			PutField_CString(hPspDetail,"error_code",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: error_code = [%s]\n",csTmp));

			if(GetField_CString(hContext,"psp_channel_code",&csPspChannelCode)){
				DBObjPtr = CreateObj(DBPtr,"DBMessages","c2i");
				if ((*DBObjPtr)(csPspChannelCode,iIntErr,csTmp) == PD_OK) {
					iDefErr=0;
					csBuf = (char*) malloc (128);
					sprintf(csBuf,"%d",iIntErr);
					PutField_CString(hTxn,"response_code",csBuf);
DEBUGLOG(("UpdateRespTxnLog:: [%s] error_code[%s]->response_code[%s]\n",csPspChannelCode,csTmp,csBuf));
					FREE_ME(csBuf);
				}
			}
			
			if(iDefErr){
				PutField_CString(hTxn,"response_code",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: response_code = %s\n",csTmp));
			}


//			PutField_CString(hTxn,"response_code",csTmp);
//DEBUGLOG(("UpdateRespTxnLog:: response_code = [%s]\n",csTmp));
/* ******************** */
		}
/* txn_date */
        	if (GetField_CString(hRequest,"txn_date",&csTmp)) {
			PutField_CString(hPspDetail,"txn_date",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: txn_date = [%s]\n",csTmp));
		}
/* bank code */
        	//if (GetField_CString(hRequest,"bank_code",&csTmp)) {
        	if (GetField_CString(hRequest,"internal_bank_code",&csTmp)) {
			PutField_CString(hPspDetail,"bank_code",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: bank_code = [%s]\n",csTmp));
		}
/* bank name */
        	if (GetField_CString(hRequest,"bank_name",&csTmp)) {
			PutField_CString(hPspDetail,"bank_name",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: bank_name = [%s]\n",csTmp));
		}
/* bank_branch */
        	if (GetField_CString(hRequest,"bank_branch",&csTmp)) {
			PutField_CString(hPspDetail,"bank_branch",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: bank_branch = [%s]\n",csTmp));
		}
/* account_name */
        	if (GetField_CString(hRequest,"account_name",&csTmp)) {
		//	strcpy(csAccName,code_convert(PD_BIG5_CODE,PD_HOST_CODE,csTmp));
		//	PutField_CString(hPspDetail,"account_name",csAccName);
			PutField_CString(hPspDetail,"account_name",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: account_name = [%s]\n",csTmp));
		}
/* account_no */
        	if (GetField_CString(hRequest,"account_no",&csTmp)) {
			PutField_CString(hPspDetail,"account_no",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: account_no = [%s]\n",csTmp));
		}
/* batch_id */
        	if (GetField_CString(hRequest,"batch_id",&csTmp)) {
			PutField_CString(hPspDetail,"batch_id",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: batch_id = [%s]\n",csTmp));
		}
/* fundin_date */
        	if (GetField_CString(hRequest,"fundin_date",&csTmp)) {
			PutField_CString(hPspDetail,"fundin_date",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: fundin_date = [%s]\n",csTmp));
		}

/* fundout_date */
        	if (GetField_CString(hRequest,"fundout_date",&csTmp)) {
			PutField_CString(hPspDetail,"fundout_date",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: fundout_date = [%s]\n",csTmp));
		}
/* service_fee */
        	if (GetField_Double(hContext,"precal_fee",&dTmp)) {
DEBUGLOG(("UpdateRespTxnLog:: precal service_fee = [%f]\n",dTmp));
			PutField_Double(hPspDetail,"service_fee",dTmp);
		}
		else {
        		if (GetField_Double(hRequest,"service_fee",&dTmp)) {
				PutField_Double(hPspDetail,"service_fee",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: service_fee = [%f]\n",dTmp));
			}
		}
/* tid */
        	if (GetField_CString(hRequest,"tid",&csTmp)) {
			PutField_CString(hPspDetail,"tid",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: tid = [%s]\n",csTmp));
		}
        
/* bank_bill_no */
        	if (GetField_CString(hRequest,"bank_bill_no",&csTmp)) {
			PutField_CString(hPspDetail,"bank_bill_no",csTmp);
DEBUGLOG(("UpdateRespTxnLog:: bank_bill_no = [%s]\n",csTmp));
		}
        
/* current_bal */
        	if (GetField_Double(hContext,"current_bal",&dTmp)) {
			PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: current_bal= [%f]\n",dTmp));
		}
        
/* total_float*/
        	if (GetField_Double(hContext,"total_float",&dTmp)) {
			PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: total_float= [%f]\n",dTmp));
		}
        
/* total_reserved_amount*/
        	if (GetField_Double(hContext,"total_reserved_amount",&dTmp)) {
			PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: total_reserved_amount= [%f]\n",dTmp));
		}
        
/* total_hold*/
        	if (GetField_Double(hContext,"total_hold",&dTmp)) {
			PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: total_hold= [%f]\n",dTmp));
		}
        
/* settlement_in_transit*/
        	if (GetField_Double(hContext,"settlement_in_transit",&dTmp)) {
			PutField_Double(hTxn,"settlement_in_transit",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: settlement_in_transit= [%f]\n",dTmp));
		}

/* psp_balance*/
        	if (GetField_Double(hContext,"psp_balance",&dTmp)) {
			PutField_Double(hPspDetail,"bal",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: psp_balance = [%f]\n",dTmp));
		}
/* psp_total_float*/
        	if (GetField_Double(hContext,"psp_total_float",&dTmp)) {
			PutField_Double(hPspDetail,"total_float",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: psp_total_float = [%f]\n",dTmp));
		}
/* psp_total_hold*/
        	if (GetField_Double(hContext,"psp_total_hold",&dTmp)) {
			PutField_Double(hPspDetail,"total_hold",dTmp);
DEBUGLOG(("UpdateRespTxnLog:: psp_total_hold = [%f]\n",dTmp));
		}
        
		if (GetField_Double(hContext,"reserve_amt",&dTmp)) {
DEBUGLOG(("UpdateRespTxnLog:: reserve_amt = [%f]\n",dTmp));
                	PutField_Double(hTxn,"reserve_amt",dTmp);
                }
        
                if (iRet == PD_OK) {
DEBUGLOG(("UpdateRespTxnLog:: Call Update Transaction\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
                }       
                if (iRet == PD_OK) {
DEBUGLOG(("UpdateRespTxnLog:: Call Update Transaction Detail\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
                }       
                if (iRet == PD_OK) {
DEBUGLOG(("UpdateRespTxnLog:: Call Update TxnPspDetail\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hPspDetail);
                }
                        
        }
        else                    
                iRet = PD_ERR;

        hash_destroy(hTxn);
        FREE_ME(hTxn);          

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);          
                        
	FREE_ME(csStatus);
DEBUGLOG(("UpdateRespTxnLog:: Ret [%d]\n",iRet));
        return  iRet;   
}

