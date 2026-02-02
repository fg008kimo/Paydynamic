/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/08/31              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2TWV.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);
int     UpdatePreTWVRespTxnLog(hash_t *hContext,
                	hash_t* hResponse);
int     UpdatePreTWVBatchRespTxnLog(hash_t *hContext,
                	hash_t* hResponse);

int     AddTWVTxnLog(hash_t *hContext,
                const hash_t* hRequest);

void TxnWebOnUs2TWV(char    cdebug)
{
        cDebug = cdebug;
}
int     AddTWVTxnLog(hash_t *hContext,
                const hash_t* hRequest)
{
	int iRet = PD_OK;
	hash_t	*hPspDetail;
	char*	csTmp;
	double	dTmp;

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);

        PutField_CString(hPspDetail,"add_user",PD_UPDATE_USER);
/* txn_seq  */
        if (GetField_CString(hContext,"from_txn_seq",&csTmp)) {
		PutField_CString(hPspDetail,"txn_seq",csTmp);
	}
        else if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("AddTWVTxnLog:: txn_seq = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* psp id */
        if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddTWVTxnLog:: psp_id = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"psp_id",csTmp);
        }

/* txn amt*/
        if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("AddTWVTxnLog:: txn_amt = [%f]\n",dTmp));
       		PutField_Double(hPspDetail,"txn_amt",dTmp);
        }
/* txn_ccy*/
       if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddTWVTxnLog:: txn_ccy = [%s]\n",csTmp));
      		PutField_CString(hPspDetail,"txn_ccy",csTmp);
       }

/* txn_desc */
       if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddTWVTxnLog:: txn_desc = [%s]\n",csTmp));
       		PutField_CString(hPspDetail,"desc",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
       	iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

	return iRet;
};


int     UpdatePreTWVRespTxnLog(hash_t *hContext,
                	hash_t* hResponse)

{
        int     iRet = PD_OK;
        char    *csTmp = NULL;
        char    *csStatus = strdup("");
	hash_t	*hPspDetail;
DEBUGLOG(("TxnWebOnUs2TWV::UpdateRespTxnLog()\n"));

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);


/* txn_seq from response */
        if (GetField_CString(hContext,"from_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_seq",csTmp);
	}
        else if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* tid */
        if (GetField_CString(hResponse,"tid",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: tid = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"tid",csTmp);
        }
/* txn_date */
        if (GetField_CString(hResponse,"txn_date",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: txn_date = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"txn_date",csTmp);
        }

/* status */
        if (GetField_CString(hResponse,"status",&csStatus)) {
DEBUGLOG(("UpdateTxnLog RESP:: status = [%s]\n",csStatus))
                PutField_CString(hPspDetail,"status",csStatus);
        }
/* error_code */
        if (GetField_CString(hResponse,"error_code",&csStatus)) {
DEBUGLOG(("UpdateTxnLog RESP:: error_code = [%s]\n",csStatus))
                PutField_CString(hPspDetail,"error_code",csStatus);
        }

/* batch_id */
        if (GetField_CString(hResponse,"batch_id",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: batch_id = [%s]\n",csTmp))
                PutField_CString(hPspDetail,"batch_id",csTmp);
        }

/* deposit_url */
        if (GetField_CString(hResponse,"deposit_url",&csTmp)) {
DEBUGLOG(("UpdateTxnLog RESP:: deposit_url = [%s]\n",csTmp));
                PutField_CString(hPspDetail,"deposit_url",csTmp);
                PutField_CString(hContext,"redirect_url",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
        iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        if (iRet == PD_OK) {

                if (strcmp(csStatus,"1")) {
			iRet = ctos((const unsigned char *)csStatus,strlen(csStatus));
			PutField_Int(hContext,"internal_error",iRet);			
			RemoveField_CString(hContext,"redirect_url");
/*
			char *csCmd=(char*) malloc(PD_MAX_FILE_LEN  +1);
                        sprintf(csCmd,"send_twv_error.sh");
                        system(csCmd);
                        FREE_ME(csCmd);
*/
                }
        }


        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

        FREE_ME(csStatus);
DEBUGLOG(("UpdateRespTxnLog Exit [%d]\n",iRet));
        return iRet;
}

int     process_twv_resp_txn(hash_t *hContext,
                                const hex_t* inMsg)
{
        int     iRet = PD_OK;
	char	*csTxnCode;
        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);
        
DEBUGLOG(("process_twv_resp_txn()\n"));

	GetField_CString(hContext,"txn_code",&csTxnCode);
        if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)) //if none batch txn
       		MsgObjPtr = CreateObj(MsgPtr,"TwvMsg","BreakDownMsg");
	else 
       		MsgObjPtr = CreateObj(MsgPtr,"TwvMsg","BreakDownBatchMsg");

        if ((*MsgObjPtr)(hResponse,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_resp_txn:BreakDown TwvMsg Error\n"));
        }
        else {
DEBUGLOG(("process_twv_resp_txn() call Update\n"));

		if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)) //if none batch txn
			iRet = UpdatePreTWVRespTxnLog(hContext,hResponse);
		else 
			iRet = UpdatePreTWVBatchRespTxnLog(hContext,hResponse);
        }
        hash_destroy(hResponse);
        FREE_ME(hResponse);

DEBUGLOG(("process_tww_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}               

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;
	hex_t   *h_msg;
        struct msg_t *msg;
        int     iSendLen,iRecvLen;
        long    lKey,lRspKey;
        char    *csTxnSeq;
	char	*csTxnCode;


DEBUGLOG(("TxnWebOnUs2TWV: Authroize()\n"));
	if (!GetField_CString(hContext,"org_txn_code",&csTxnCode))
		GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("TxbWebOnUs2TWV: txn_code = [%s]\n",csTxnCode));

	if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) && strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) //if none batch txn
		iRet = AddTWVTxnLog(hContext,hRequest);

	if (iRet == PD_OK) {
        if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) 
        	GetField_CString(hContext,"txn_seq",&csTxnSeq);
                        

		if (!strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE)) //if batch txn
        		MsgObjPtr = CreateObj(MsgPtr,"TwvMsg","FormatBatchMsg");
		else
       		 	MsgObjPtr = CreateObj(MsgPtr,"TwvMsg","FormatMsg");

        	h_msg = (hex_t*) malloc (sizeof(hex_t));
        	if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
        
               		lKey = GetMQKey((const unsigned char *)"TWVPREQQ");
                	lRspKey = GetMQKey((const unsigned char *)"TWVPRSPQ");
        
                	msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                	msg->mtype  = ctol((const unsigned char *)csTxnSeq,strlen(csTxnSeq));
                	memset(msg->mtext,0,sizeof(msg->mtext));
                        	MQ_build_header((unsigned char*)msg->mtext,
                        	MQ_RESP,
                        	"WEB",
				0,
				NULL,
				0);
                	memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                	msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
                	iSendLen = MQ_HEADER_LEN + h_msg->len;
DEBUGLOG(("send msg = [%s] send len = [%d]\n",msg->mtext,iSendLen));
DEBUGLOG(("rspkey = [%ld][%ld]\n",lRspKey,msg->mtype));


                	if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Sent Error\n"));
                       		iRet = PD_ERR;
                	}
                	else {
                		memset(msg->mtext,0,sizeof(msg->mtext));
                		if (MQRecv(lRspKey,msg,&iRecvLen,PD_MQ_RECV_TIMEOUT*3) != MQ_OK ) {
DEBUGLOG(("recv Error\n"));
	                        	iRet = PD_ERR;
				}
				else {
					msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("TxnWebOnUs2TWV:  recv len = [%d]\n",iRecvLen));
DEBUGLOG(("TxnWebOnUs2TWV:  recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN));
					memcpy(h_msg->msg,&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);
					iRet = process_twv_resp_txn(hContext,h_msg);
DEBUGLOG(("TxnWebOnUs2TWV: after process_twv_resp_txn iret = [%d]\n",iRet));
				}
                	}
        		FREE_ME(msg);
        	}     
        	else {
                	iRet = INT_FORMAT_ERR;
        	}       
        	FREE_ME(h_msg);
	}

DEBUGLOG(("TxnWebOnUs2TWV: noraml exit iret = [%d]\n",iRet));
	return iRet;
}
int     UpdatePreTWVBatchRespTxnLog(hash_t *hContext,
                	hash_t* hResponse)

{
        int     iRet = PD_OK;
        char    *csTmp = NULL;
	char	csTag[PD_TAG_LEN + 1];
        char    *csStatus = strdup("");
	
	hash_t	*hPspDetail;
	hash_t	*hTxn;

	int	iTotal = 0,i;
DEBUGLOG(("TxnWebOnUs2TWV::UpdateBatchRespTxnLog()\n"));

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hTxn = (hash_t*)  malloc (sizeof(hash_t));


	GetField_Int(hResponse,"total",&iTotal);
DEBUGLOG(("UpdateBatchTxnLog RESP:: total = [%d]\n",iTotal));

	for (i = 0; i < iTotal; i++) {
        	hash_init(hPspDetail,0);
        	hash_init(hTxn,0);
/* txn_seq from response */
		sprintf(csTag,"order_num_%d",i);
        	if (GetField_CString(hResponse,csTag,&csTmp)) {
			sprintf(csTag,"txn_seq_%d",i);
DEBUGLOG(("UpdateBatchTxnLog RESP:: %s = [%s]\n",csTag,csTmp));
               		PutField_CString(hPspDetail,"txn_seq",csTmp);
               		PutField_CString(hTxn,"txn_seq",csTmp);
        	}
/* tid */
		sprintf(csTag,"tid_%d",i);
        	if (GetField_CString(hResponse,csTag,&csTmp)) {
DEBUGLOG(("UpdateBatchTxnLog RESP:: %s = [%s]\n",csTag,csTmp));
                	PutField_CString(hPspDetail,"tid",csTmp);
        	}

/* status */
		sprintf(csTag,"status_%d",i);
        	if (GetField_CString(hResponse,csTag,&csStatus)) {
DEBUGLOG(("UpdateBatchTxnLog RESP:: %s = [%s]\n",csTag,csStatus))
                	PutField_CString(hPspDetail,"status",csStatus);
        	}

/* batch_id */
		sprintf(csTag,"batch_id_%d",i);
        	if (GetField_CString(hResponse,csTag,&csTmp)) {
DEBUGLOG(("UpdateBatchTxnLog RESP:: %s = [%s]\n",csTag,csTmp))
               		PutField_CString(hPspDetail,"batch_id",csTmp);
        	}

        	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
        	iRet = (unsigned long)(*DBObjPtr)(hPspDetail);
		if (iRet == PD_OK) {
			iRet = ctos((const unsigned char *)csStatus,strlen(csStatus));
			PutField_Int(hTxn,"internal_code",iRet);			
                	if (!strcmp(csStatus,"1")) {
				PutField_Char(hTxn,"status",PD_TO_PSP);	
			}
			else {
				PutField_Char(hTxn,"status",PD_COMPLETE);	
				PutField_Char(hTxn,"ar_ind",PD_REJECT);	
			}
			PutField_CString(hTxn,"response_code",csStatus);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                        iRet = (unsigned long)(*DBObjPtr)(hTxn);
			TxnCommit();
		}

        	hash_destroy(hPspDetail);
        	hash_destroy(hTxn);

	}


        FREE_ME(hPspDetail);
        FREE_ME(hTxn);
	FREE_ME(csStatus);

DEBUGLOG(("UpdateBatchRespTxnLog Exit [%d]\n",iRet));
        return iRet;
}

