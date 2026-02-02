/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/21              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOplByUsACK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define PD_ACK_RESEND   "resend_opl_rck.sh"
char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);
void TxnOplByUsACK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iTmp;
	long	lKey;
	long	lRspKey;
	double	dTmp;
        char    *csValue = strdup("");
        char    *csChannelCode = strdup("");
	char	csTmpChannelCode[PD_CHANNEL_CODE_LEN *2  +1];
	char*	csPtr = NULL;
	char*	csOrgTxnSeq;
	char*	csBatchTxnSeq;
	char	*csOrgProcessType;
	char	*csOrgProcessCode;
	char	*csMerchantId;
	char	cArInd;
 	struct msg_t* msg;
	hash_t  *hRec;
	hex_t   *h_msg;
	
	hash_t  *hRsp, *hAck;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	recordset_t     *rMerchantSet;
        rMerchantSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rMerchantSet,0);
	
        hRsp = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRsp,0);
        hAck = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hAck,0);


DEBUGLOG(("TxnOplByUsACK Authorize()\n"));
	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {

/* ACK LOG  */
		PutField_CString(hAck,"org_txn_seq",csOrgTxnSeq);
		if (GetField_CString(hRequest,"add_user",&csPtr)) {
			PutField_CString(hAck,"add_user",csPtr);
		}
		else {
			PutField_CString(hAck,"add_user",PD_UPDATE_USER);
		}
		PutField_Char(hAck,"status",PD_TO_PSP);

		if (GetField_CString(hContext,"batch_txn_seq",&csBatchTxnSeq)) {
        		PutField_CString(hAck,"txn_seq",csBatchTxnSeq);
DEBUGLOG(("TxnOplByUsACK batch_txn_seq = [%s]\n",csBatchTxnSeq));
		}
		else {
			char	csTxnSeq[PD_TXN_SEQ_LEN +1];
			DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
        		strcpy(csTxnSeq,(*DBObjPtr)());
			csBatchTxnSeq = csTxnSeq;
        		PutField_CString(hAck,"txn_seq",csTxnSeq);
DEBUGLOG(("TxnOplByUsACK batch_txn_seq (new)= [%s]\n",csTxnSeq));
		}
/* end ack log */

		PutField_CString(hRsp,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnOplByUsACK org_txn_seq = [%s]\n",csOrgTxnSeq));
        	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnOplByUsACK found record = [%s]\n",csOrgTxnSeq));
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                       	 	if (GetField_CString(hRec,"process_type",&csOrgProcessType)) {
DEBUGLOG(("TxnOplByUsACK:process_type= [%s]\n",csOrgProcessType));
					PutField_CString(hRsp,"process_type",PD_PROCESS_TYPE_ACK);
				}
                       	 	if (GetField_CString(hRec,"process_code",&csOrgProcessCode)) {
DEBUGLOG(("TxnOplByUsACK:process_code= [%s]\n",csOrgProcessCode));
					PutField_CString(hRsp,"process_code",csOrgProcessCode);
				}
                       	 	if (GetField_CString(hRec,"response_code",&csPtr)) {
DEBUGLOG(("TxnOplByUsACK:response_code= [%s]\n",csPtr));
					PutField_CString(hRsp,"response_code",csPtr);
				}

                       	 	if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("TxnOplByUsACK:ar_ind= [%c]\n",cArInd));
					PutField_Char(hRsp,"ar_ind",cArInd);
				}
                       	 	if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
DEBUGLOG(("TxnOplByUsACK:merchant_id= [%s]\n",csMerchantId));
					PutField_CString(hRsp,"merchant_id",csMerchantId);
                        	}
                       	 	if (GetField_CString(hRec,"merchant_ref",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:merchant_id= [%s]\n",csValue));
					PutField_CString(hRsp,"merchant_ref",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"transmission_datetime",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:transmission_datetime= [%s]\n",csValue));
					PutField_CString(hRsp,"transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"local_transmission_datetime",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:local_transmission_datetime= [%s]\n",csValue));
					PutField_CString(hRsp,"local_transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"channel_code",&csChannelCode)) {
DEBUGLOG(("TxnOplByUsACK:channel_code= [%s]\n",csChannelCode));
                        	}
                       	 	if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("TxnOplByUsACK:net_amt= [%f]\n",dTmp));
					PutField_Double(hRsp,"net_amt",dTmp);
                        	}
                       	 	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnOplByUsACK:txn_amt= [%f]\n",dTmp));
					PutField_Double(hRsp,"txn_amt",dTmp);
                        	}
                       	 	if (GetField_Int(hRec,"internal_error",&iTmp)) {
DEBUGLOG(("TxnOplByUsACK:internal_error= [%d]\n",iTmp));
					PutField_Int(hRsp,"internal_error",iTmp);
                        	}


                        	hRec = RecordSet_GetNext(rRecordSet);

                	}
        	}
		else {
DEBUGLOG(("TxnOplByUsACK not found record for [%s]\n",csOrgTxnSeq));
			iRet = INT_ORG_TXN_NOT_FOUND;
		}

/* fee charge detail */
		if (iRet == PD_OK) {
                	recordset_init(rRecordSet,0);
        		DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetFeeChgDetailByType");
        		if ((*DBObjPtr)(csOrgTxnSeq,PD_ELEMENT_TXN_FEE,PD_TYPE_MERCHANT,rRecordSet) == PD_OK) {
               			hRec = RecordSet_GetFirst(rRecordSet);
                		while (hRec) {
                       	 		if (GetField_Double(hRec,"amount",&dTmp)) {
DEBUGLOG(("TxnOplByUsACK:fee= [%f]\n",dTmp));
						PutField_Double(hRsp,"service_fee",dTmp);
					}

                        		hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
	}
	else 	
		iRet = INT_ERR;
	
	if (iRet == PD_OK ) {
        	recordset_init(rRecordSet,0);
        	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
				if (GetField_CString(hRec,"success_callback_url",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:success_callback_url= [%s]\n",csValue));
					PutField_CString(hRsp,"success_callback_url",csValue);
				}
				if (GetField_CString(hRec,"failure_callback_url",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:failure_callback_url= [%s]\n",csValue));
					PutField_CString(hRsp,"failure_callback_url",csValue);
				}

				if(GetField_CString(hRec,"encrypt_type",&csValue)){
DEBUGLOG(("TxnOplByUsACK:encrypt_type= [%s]\n",csValue));
                                        PutField_CString(hRsp,"encrypt_type",csValue);
                                        PutField_CString(hRsp,"po_encrypt_type",csValue);
                                }
                                else{
DEBUGLOG(("TxnOplByUsACK:use default encrypt_type= [1]\n"));
                                        PutField_CString(hRsp,"encrypt_type","1");
                                        PutField_CString(hRsp,"po_encrypt_type","1");
                                }
/* remark */
                       	 	if (GetField_CString(hRec,"remark",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:remark= [%s]\n",csValue));
					PutField_CString(hRsp,"remark",csValue);
                        	}
/* txn_ccy */
                       	 	if (GetField_CString(hRec,"txn_ccy",&csValue)) {
DEBUGLOG(("TxnOplByUsACK:txn_ccy= [%s]\n",csValue));
					PutField_CString(hRsp,"txn_ccy",csValue);
					PutField_CString(hRsp,"net_ccy",csValue);
					PutField_CString(hRsp,"service_fee_ccy",csValue);
                        	}

                       		hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		if (cArInd == PD_ACCEPT) {
			if (!GetField_CString(hRsp,"success_callback_url",&csPtr)) {
DEBUGLOG(("TxnOplByUsACK: unable to get success_callback_url!!!\n")); 
				iRet = INT_SUCC_CB_URL_NOT_FOUND;
			}
		} else {
			if (!GetField_CString(hRsp,"failure_callback_url",&csPtr)) {
DEBUGLOG(("TxnOplByUsACK: unable to get failure_callback_url!!!\n")); 
				iRet = INT_SUCC_CB_URL_NOT_FOUND;
			}
		}
	}

        
	if (iRet == PD_OK) {
DEBUGLOG(("TxnOplByUsACK:BUILD AckAuthData\n"));
		MsgObjPtr = CreateObj(MsgPtr,"OplMsg","BuildAckAuthData");
        	iRet = (unsigned long)(*MsgObjPtr)(hRsp);
	}

	if (iRet == PD_OK) {
/* Check Merchant Sign*/
               	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMac");
               	iRet = (unsigned long)(*BOObjPtr)(hContext,hRsp,hRsp);
DEBUGLOG(("BOSecurity->GenerateMac = [%d]\n",iRet));
	}

	if (iRet == PD_OK) {
		sprintf(csTmpChannelCode,"%c%c%cMsg",csChannelCode[0],tolower(csChannelCode[1]),tolower(csChannelCode[2]));
DEBUGLOG(("TxnOplByUsACK Calling [%s]->[FormatAckMsg]\n",csTmpChannelCode));
	 	MsgObjPtr = CreateObj(MsgPtr,csTmpChannelCode,"FormatAckMsg");
        	h_msg = (hex_t*) malloc (sizeof(hex_t));
        	if ((*MsgObjPtr)(hRsp,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
			lKey = GetMQKey((unsigned char*)"OPLACKQ");
			lRspKey = GetMQKey((unsigned char*)"OPLACKRSPQ");
       	         	msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                       	msg->mtype  = ctol((const unsigned char *)csOrgTxnSeq,strlen(csOrgTxnSeq));
                	memset(msg->mtext,0,sizeof(msg->mtext));
                        MQ_build_header((unsigned char*)msg->mtext,
                       		 MQ_REQ,
                        	"OPK",
				0,
				"OPLACKRSPQ",
				0);
                		memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                		msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

/* set batch txn id to remote reply queue name without 'G' */
			memcpy(&msg->mtext[MQ_REMOTE_REPLY_QUEUE_ID_OS],&csBatchTxnSeq[1],PD_TXN_SEQ_LEN - 1);
                
                	iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);

			if(iRet == PD_OK){
				DBObjPtr = CreateObj(DBPtr,"DBOLPayoutTxnAckLog","Add");
				if ((*DBObjPtr)(hAck) != PD_OK) {
DEBUGLOG(("DBOLPayoutTxnAckLog: Add Failed\n"));
					iRet = INT_ERR;
				}

			}
			else {
				PutField_Char(hAck,"status",PD_REJECT);
				PutField_Int(hAck,"internal_erro",iRet);
				DBObjPtr = CreateObj(DBPtr,"DBOLPayoutTxnAckLog","Add");
				if ((*DBObjPtr)(hAck) != PD_OK) {
DEBUGLOG(("DBOLPayoutTxnAckLog: Add Failed\n"));
					iRet = INT_ERR;
				}
			}
			TxnCommit();
		}
		FREE_ME(h_msg);
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        RecordSet_Destroy(rMerchantSet);
        FREE_ME(rMerchantSet);
	FREE_ME(hRsp);
	FREE_ME(csPtr);
        FREE_ME(csValue);

DEBUGLOG(("TxnOplByUsACK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
