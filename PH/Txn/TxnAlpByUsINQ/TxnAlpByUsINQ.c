/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/14              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnAlpByUsINQ.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	PD_SUPPORTED_PSP_CHANNEL 	"ALP"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);
void TxnAlpByUsINQ(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTxnSeq = NULL;
	char	*csOrgTxnSeq;
	char	*csPtr;
	char	*csPspId;
	char	*csPspChannel;
	long    lKey,lRspKey;
	struct msg_t *msg;
	hex_t   *h_msg;
	hash_t	*hRec;
	hash_t	*hPsp;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hPsp = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hPsp,0);

DEBUGLOG(("Authorize\n"));
	if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("txn seq = [%s]\n",csTxnSeq));
	}
	else {
DEBUGLOG(("txn seq not found\n"));
	}
	
	if (GetField_CString(hContext,"org_txn_id",&csOrgTxnSeq)) {
DEBUGLOG(("org_txn_id = [%s]\n",csOrgTxnSeq));
		PutField_CString((hash_t*) hRequest,"org_txn_seq",csOrgTxnSeq);
	}
// txn code
 	PutField_CString((hash_t*) hRequest,"txn_code",PD_INQ_TXN_CODE);
/*
	DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn");
        if ((unsigned long)(DBObjPtr)(csOrgTxnSeq,PD_TO_PSP) != PD_FOUND) {
  		iRet = INT_TXN_ID_NOT_FOUND;
DEBUGLOG(("org txn id record [%s] not found for status = [%c]\n",csOrgTxnSeq,PD_TO_PSP));
        	PutField_Int(hContext,"internal_error",iRet);
	}
*/
	
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnWebByUsACK found record = [%s]\n",csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("txn_code = [%s]\n",csPtr));
/*
					if (strcmp(csPtr,PD_INITIAL_TXN_CODE) && strcmp(csPtr,PD_DEPOSIT_TXN_CODE)) {
DEBUGLOG(("support pool [%s] and [%s] only\n",PD_INITIAL_TXN_CODE,PD_DEPOSIT_TXN_CODE));
						iRet = PD_ERR;
						break;
					}
*/
				}
				if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("local_tm_date = [%s]\n",csPtr));
					PutField_CString((hash_t*)hRequest,"org_local_tm_date",csPtr);
				}
				if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("local_tm_time = [%s]\n",csPtr));
					PutField_CString((hash_t*)hRequest,"org_local_tm_time",csPtr);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
		 if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("psp_id = [%s]\n",csPspId));
			 		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
               				 if (!(*DBObjPtr)(csPspId, hPsp)) {
                        			if (GetField_CString(hPsp,"psp_channel_code",&csPspChannel)) {
							if (strcmp(PD_SUPPORTED_PSP_CHANNEL,csPspChannel)) {
DEBUGLOG(("GetPspDetail - unsupported [%s],[%s] only\n",csPspChannel,PD_SUPPORTED_PSP_CHANNEL));
								iRet = PD_ERR;
								break;
							}
                                			PutField_CString(hContext,"psp_channel_code",csPspChannel);
                                			PutField_CString(hContext,"return_psp_channel",csPspChannel);
DEBUGLOG(("GetPspDetail - psp_channel_code = [%s]\n",csPspChannel));
                        			}
                			}
					if (GetField_CString(hPsp,"psp_merchant_id",&csPtr)) {
                                		PutField_CString((hash_t *)hRequest,"psp_merchant_id",csPtr);
DEBUGLOG(("GetPspDetail - psp_merchant_id = [%s]\n",csPtr));
                        		}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBPspKeys","GetPspKey");
                if (!(*DBObjPtr)(csPspId,"PTK",rRecordSet)) {
                	hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                        	if (GetField_CString(hRec,"key_value",&csPtr)) {
DEBUGLOG(("GetTxnPspByPspId - psp_key = [%s]\n",csPtr));
                        		PutField_CString(hContext,"psp_key",csPtr);
                        	}
                        	hRec = RecordSet_GetNext(rRecordSet);
                      	}
     		}
                        RecordSet_Destroy(rRecordSet);
	}

	if (iRet == PD_OK) {
		char* p = NULL;
		p = getenv("PSP_URL");
		if (!p) {
DEBUGLOG(("PSP_URL = [%s]\n",p));
			DBObjPtr = CreateObj(DBPtr,"DBPspUrl","GetPspUrl");
                	if (!(*DBObjPtr)(csPspId,hPsp)) {
                       		if (GetField_CString(hPsp,"url",&csPtr)) {
                                	PutField_CString((hash_t*)hRequest,"psp_url",csPtr);
DEBUGLOG(("GetTxnPsp - psp_url = [%s]\n",csPtr));
                        	}
                        	else {
DEBUGLOG(("GetTxnPSP - no such for [%s]\n",csPspId));
                                	iRet = INT_ERR;
                        	}
                	}
		}
		else {
                  	PutField_CString((hash_t*)hRequest,"psp_url",p);
DEBUGLOG(("psp url = [%s]\n",p));
		}
	}

/* Get PSP Reqest Txn URL */
        if (iRet == PD_OK) {
DEBUGLOG(("GetTxnPsp - GetPspRequestTxnUrl\n"));
                DBObjPtr = CreateObj(DBPtr,"DBPspRequestTxnUrl","GetPspRequestTxnUrl");
                if (!(*DBObjPtr)(csPspId,PD_INQ_TXN_CODE, "000", hPsp)) {
                        if (GetField_CString(hPsp,"request_function",&csPtr)) {
                                PutField_CString((hash_t*)hRequest,"request_function",csPtr);
DEBUGLOG(("GetTxnPsp - request_function = [%s]\n",csPtr));
                        }
                        else {
DEBUGLOG(("GetTxnPSP - no such function url for [%s] [%s]\n",csPspId,PD_INQ_TXN_CODE));
                                iRet = INT_ERR;
                        }
                        if (GetField_CString(hPsp,"action",&csPtr)) {
                                PutField_CString((hash_t*)hRequest,"action",csPtr);
DEBUGLOG(("GetTxnPsp - action = [%s]\n",csPtr));
                        }

                        if(GetField_CString(hPsp,"url_method",&csPtr)){
                                PutField_CString((hash_t*)hRequest,"url_method",csPtr);
DEBUGLOG(("GetTxnPsp - url_method = [%s]\n",csPtr));
                        }
                }
        }
	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","GeneratePspSignINQ");
                if (!(*BOObjPtr)(hContext,hRequest,hResponse)) {
			h_msg = (hex_t*) malloc (sizeof(hex_t));
			MsgObjPtr = CreateObj(MsgPtr,"AlpMsg","FormatInqMsg");
			if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("Format OK\n"));
				int	iSendLen = 0 ,iRecvLen = 0;
				lKey = GetMQKey((const unsigned char *)"PSPINQREQQ");
                        	lRspKey = GetMQKey((const unsigned char *)"PSPINQRSPQ");

DEBUGLOG(("txn seq = [%s]\n",csTxnSeq));
				msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                        	msg->mtype  = ctol((const unsigned char *)csTxnSeq,strlen(csTxnSeq));
                        	memset(msg->mtext,0,sizeof(msg->mtext));

                                MQ_build_header((unsigned char*)msg->mtext,
                                MQ_RESP,
                                "WEB",
                                0,
                                NULL,
                                0);

DEBUGLOG(("here\n"));
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
TXNLOG("ALP INQ RECV\n");
                                	memset(msg->mtext,0,sizeof(msg->mtext));
                                	if (MQRecv(lRspKey,msg,&iRecvLen,5) != MQ_OK ) {
DEBUGLOG(("recv Error\n"));
                                        	iRet = PD_ERR;
                                	}
                                	else {
//DEBUGLOG(("*recv len = [%d]\n",iRecvLen - MQ_HEADER_LEN));
//DEBUGLOG(("recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN]));
						iRecvLen = iRecvLen - MQ_HEADER_LEN;
						if (iRecvLen == 0) {
DEBUGLOG(("invalid status response\n"));
							iRet = PD_ERR;
						}
						else {
							int	iBufLen = 0;
							char	*csTmpBuf;
							csTmpBuf = (char*) malloc (iRecvLen *2 +1);
							csTmpBuf[0] = '\0';
       	                                 		msg->mtext[iRecvLen] = '\0';
//DEBUGLOG(("recv len = [%d]\n",iRecvLen));
//DEBUGLOG(("recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN]));
							urldecode((unsigned char*)&msg->mtext[MQ_HEADER_LEN], iRecvLen,(unsigned char*)csTmpBuf,&iBufLen);
DEBUGLOG(("decoded\n"));
DEBUGLOG(("recv len = [%d]\n",iBufLen));
DEBUGLOG(("recv = [%s]\n",csTmpBuf));

// send to WEB Channel
							MQ_build_header((unsigned char*)msg->mtext,
                                		 			MQ_RESP,
                               	 					"ALP",
                                					0,
                                					NULL,
                                					0);
							MQ_build_header2((unsigned char*)msg->mtext,
							0,
                        				"DUMPQ");

							memcpy(&msg->mtext[MQ_HEADER_LEN],csTmpBuf,iBufLen);
                                			iSendLen = MQ_HEADER_LEN + iBufLen;
                        				msg->mtext[iSendLen] = '\0';

							lKey = GetMQKey((const unsigned char *)"SYSIQ");
							if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Sent to SYSIQ Error\n"));
                                				iRet = PD_ERR;
                        				}
							else {
DEBUGLOG(("Send to SYSINQ\n"));
								lRspKey = GetMQKey((const unsigned char *)"DUMPQ");
								iRet = MQRecv(lRspKey,msg,&iRecvLen,2);
							}

							FREE_ME(csTmpBuf);
						}
                                	}
				}
                        }
			else {
				iRet = PD_ERR;
DEBUGLOG(("Format Failed\n"));
			}
			
                        FREE_ME(msg);
			FREE_ME(h_msg);
		}
		else {
			iRet = PD_ERR;
		}
	}
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	hash_destroy(hPsp);
        FREE_ME(hPsp);

	return iRet;
}
