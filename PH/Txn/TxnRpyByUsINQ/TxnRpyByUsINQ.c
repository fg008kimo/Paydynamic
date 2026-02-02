/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/09              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnRpyByUsINQ.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define	PD_SUPPORTED_PSP_CHANNEL 	"RPY"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);

int BreakDownInqRespMsg(const char* csMsg, hash_t* hMsg);

void TxnRpyByUsINQ(char    cdebug)
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
		char*   csValueTmp;
                csValueTmp = (char*) malloc (128);
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)("RPY_INQ_URL",csValueTmp) == FOUND) {
                  	PutField_CString((hash_t*)hRequest,"psp_url",csValueTmp);
DEBUGLOG(("psp url = [%s]\n",csValueTmp));
                }
		else{
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
		FREE_ME(csValueTmp);
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
			MsgObjPtr = CreateObj(MsgPtr,"RpyMsg","FormatInqMsg");
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
TXNLOG("RPY INQ RECV\n");
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

DEBUGLOG(("recv len = [%d]\n",iRecvLen));
							char	*csTmpBuf;
							csTmpBuf = (char*) malloc (iRecvLen *2 +1);
							csTmpBuf[0] = '\0';
       	                                 		msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN]));

							sprintf(csTmpBuf,"%s",&msg->mtext[MQ_HEADER_LEN]);

							hash_t *hMsg;
							hMsg = (hash_t*) malloc (sizeof(hash_t));
							hash_init(hMsg,0);
							int iTmpRet = BreakDownInqRespMsg(csTmpBuf,hMsg);
							int iBufLen = 0;

							if(iTmpRet==PD_OK){
								//RpyMsg:BuildRspAuthData
								MsgObjPtr = CreateObj(MsgPtr,"RpyMsg","BuildRspAuthData");
								if ((*MsgObjPtr)(hMsg) == PD_OK) {
									//BOSecurity
									BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMD5Sign");
									iRet = (unsigned long)(*BOObjPtr)(hContext,hMsg);
									if(iRet == PD_OK){
										csTmpBuf[0] = '\0';
										if(GetField_CString(hMsg,"auth_data",&csPtr)){
											strcat(csTmpBuf,csPtr);
										}
										if(GetField_CString(hMsg,"sign",&csPtr)){
											strcat(csTmpBuf,"&sign=");
											strcat(csTmpBuf,csPtr);
										}
										iBufLen = strlen(csTmpBuf);
DEBUGLOG(("Response Msg = [%s]\n",csTmpBuf));
									}
								}
								//send to WEBChannel
								MQ_build_header((unsigned char*)msg->mtext,
										MQ_RESP,
										"RPY",
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
							}

							FREE_ME(hMsg);
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

DEBUGLOG(("TxnRpyByUsINQ iRet = [%d]\n",iRet));
	return iRet;
}


int BreakDownInqRespMsg(const char* csMsg, hash_t* hMsg)
{
	int iRet = PD_OK;
	char *p;
	char *stat;
	char *ret;
	char *retmsg;
	char csStatus[PD_EXT_MESSAGE_CODE_LEN+1];
	char csPayDate[PD_DATETIME_LEN+6];

	csStatus[0] = '\0';
	csPayDate[0] = '\0';

DEBUGLOG(("BreakDownInqRespMsg\n"));
	p = strstr((char*)csMsg,"<status>");
	if(p){
		stat = GetXmlField((char*)csMsg, "<status>",'<');
		if (stat) {
			if(!strcmp(stat,"completed")){
				sprintf(csStatus,"TRADE_FINISHED");
				PutField_CString(hMsg,"status",csStatus);
			}
DEBUGLOG(("status [%s], after format [%s]\n",stat,csStatus));
		}
	}
	p = strstr((char*)csMsg,"<created_time>");
	if(p){
		p = GetXmlField((char*)csMsg, "<created_time>",'<');
		if (p) {
			PutField_CString(hMsg,"gmt_create",p);
DEBUGLOG(("created_time [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<trade_date>");
	if(p){
		p = GetXmlField((char*)csMsg, "<trade_date>",'<');
		if (p) {
			sprintf(csPayDate,"%.*s-%.*s-%.*s 00:00:00",PD_YYYY_LEN,p,PD_MM_LEN,&p[PD_YYYY_LEN],PD_DD_LEN,&p[PD_YYYYMM_LEN]);
			PutField_CString(hMsg,"gmt_payment",csPayDate);
DEBUGLOG(("trade_date [%s], after format [%s]\n",p,csPayDate));
		}
	}
	p = strstr((char*)csMsg,"<subject>");
	if(p){
		p = GetXmlField((char*)csMsg, "<subject>",'<');
		if (p) {
			PutField_CString(hMsg,"title",p);
DEBUGLOG(("subject [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<amount>");
	if(p){
		p = GetXmlField((char*)csMsg, "<amount>",'<');
		if (p) {
			PutField_CString(hMsg,"txn_amt",p);
DEBUGLOG(("amount [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<out_trade_no>");
	if(p){
		p = GetXmlField((char*)csMsg, "<out_trade_no>",'<');
		if (p) {
			PutField_CString(hMsg,"txn_seq",p);
DEBUGLOG(("out_trade_no [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<trade_no>");
	if(p){
		p = GetXmlField((char*)csMsg, "<trade_no>",'<');
		if (p) {
			PutField_CString(hMsg,"tid",p);
DEBUGLOG(("trade_no [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<timestamp>");
	if(p){
		p = GetXmlField((char*)csMsg, "<timestamp>",'<');
		if (p) {
			PutField_CString(hMsg,"gmt_logistics_modify",p);
DEBUGLOG(("timestamp [%s]\n",p));
		}
	}
	p = strstr((char*)csMsg,"<result_code>");
	if(p){
		retmsg = GetXmlField((char*)csMsg, "<result_code>",'<');
		if (retmsg) {
DEBUGLOG(("result_code [%s]\n",retmsg));
		}
	}
	p = strstr((char*)csMsg,"<is_success>");
	if(p){
		ret = GetXmlField((char*)csMsg, "<is_success>",'<');
		if (ret) {
DEBUGLOG(("is_success [%s]\n",ret));
		}
	}


	if(strcmp(ret,"T")||
	   strcmp(stat,"completed")){
		iRet = PD_ERR;
DEBUGLOG(("not a success response\n"));
	}
	else{
		PutField_CString(hMsg,"sign_type","MD5");
		PutField_CString(hMsg,"body","body");
	}

DEBUGLOG(("BreakDownInqRespMsg iRet = [%d]\n",iRet));
	return iRet;
}
