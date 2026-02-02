/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/30              Cody Chan
using self encrypt/decrypt function		   2011/12/28		   Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnCctOnUsCCT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
OBJPTR(Msg);
void TxnCctOnUsCCT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char*	csMerchantId;
	char	*csKey;
	hash_t		*hRec;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
DEBUGLOG(("TxnCctOnUsCCT()\n"));
	if (GetField_CString(hRequest,"merchant_id",&csMerchantId)) {
DEBUGLOG(("Authorize::GetMerchantTxnInfo() merchant_id = [%s]\n",csMerchantId));
        }
        else
                iRet = INT_MERCHANT_ID_NOT_FOUND;
	
	if (iRet == PD_OK) {
                char*   csValueTmp;
                csValueTmp = (char*) malloc (128);
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
/* redirect url */
                if ((unsigned long)(DBObjPtr)("S_REDIRECT_URL",csValueTmp) == FOUND) {
DEBUGLOG(("Authorize::S_REDIRECT_URL  = [%s]\n",csValueTmp));
        		PutField_CString(hResponse,"redirect_url",csValueTmp);
                }
                else {
ERRLOG("Authorize::Unable to find S_REDIRECT_URL\n");
                }
		FREE_ME(csValueTmp);

        }


	if (iRet == PD_OK ) {
                DBObjPtr = CreateObj(DBPtr,"DBMerchKeys","GetMerchantKey");
                if ((*DBObjPtr)(csMerchantId,"CCK",rRecordSet) != PD_OK) {
                        iRet = INT_ERR;
ERRLOG("Authorize::GetMerchantTxnInfo() Merchant Key for Account[%s] not found\n",csMerchantId);
DEBUGLOG(("Authorize::GetMerchantTxnInfo() Merchant key for Account[%s] not found\n",csMerchantId));
                }
                else{
                        iRet = INT_ERR;
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                if (GetField_CString(hRec,"key_value",&csKey)) {
DEBUGLOG(("Authorize::GetMerchantTxnInfo() GetMerchantKey - merchant_key_value = [%s]\n",csKey));
					PutField_CString(hRequest,"merchant_key",csKey);
                                        iRet = PD_OK;
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        }


/*merchant id */
/* encrypt url */
	PutField_CString(hRequest,"tot_token","0");
	PutField_CString(hRequest,"server_ip","202.175.89.123");
	PutField_CString(hRequest,"txn_msg","TESTING");

	if (iRet == PD_OK) {
		TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2CCT","Encrypt");
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("TxnCctOnUsCCT::Encrypt() iRet = [%d] from TxnWebOnUs2CCT:Encrypt\n",iRet));
	}
	
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	return	iRet;
}

int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char*	csPtr;
	char*	csMerchantId;
	char*	csKey;
	hash_t		*hRec;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	
DEBUGLOG(("TxnCctOnUsCCT() Decrypt\n"));
	if (GetField_CString(hRequest,"merchantid",&csMerchantId)) {
DEBUGLOG(("Decrypt:: merchantid = [%s]\n",csMerchantId));
		PutField_CString(hRequest,"merchant_id",csMerchantId);
        }
        else {
DEBUGLOG(("Decrypt::merchant id is missing!!!\n"));
                iRet = INT_MERCHANT_ID_NOT_FOUND;
	}

	if (iRet == PD_OK ) {
                DBObjPtr = CreateObj(DBPtr,"DBMerchKeys","GetMerchantKey");
                if ((*DBObjPtr)(csMerchantId,"CCK",rRecordSet) != PD_OK) {
                        iRet = INT_ERR;
ERRLOG("Decrypt::GetMerchantTxnInfo() Merchant Key for Account[%s] not found\n",csMerchantId);
DEBUGLOG(("Decrypt::GetMerchantTxnInfo() Merchant key for Account[%s] not found\n",csMerchantId));
                }
                else{
                        iRet = INT_ERR;
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while(hRec){
                                if (GetField_CString(hRec,"key_value",&csKey)) {
DEBUGLOG(("Decrypt::GetMerchantTxnInfo() GetMerchantKey - merchant_key_value = [%s]\n",csKey));
					PutField_CString(hRequest,"merchant_key",csKey);
                                        iRet = PD_OK;
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        }
	

        TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2CCT","Decrypt");
        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("Decrypt::Decrypt() iRet = [%d]\n",iRet));
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"merchant_ref",&csPtr)) {
			PutField_CString(hContext,"merchant_ref",csPtr);
        		TxnObjPtr = CreateObj(TxnPtr,"TxnCctOnUsACK","Authorize");
        		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		}
	}
	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	return	iRet;
}
int     Request(hash_t *hContext,unsigned char* inBuf,
		int *iLen)
{
	char	outBuf[PD_TMP_MSG_BUF_LEN +1];
	int	oLen = 0;
	char	outBuf2[PD_TMP_MSG_BUF_LEN +1];
	int	oLen2 = 0;
	char*	csTxnSeq;
	long	lKey = 0L,lRspKey = 0L;
	char	csPostfix[] = "&process_type=0200&process_code=200002&service_code=JLN";

        struct   msg_t *sMsg;
        struct   msg_t *rMsg;
	int     iSendLen,iRecvLen;
	int	iRet = PD_OK;

DEBUGLOG(("TxnCctOnUsCCT::Request()\n"));
DEBUGLOG(("TxnCctOnUsCCT::Request()[%d][%s]\n",*iLen,inBuf));


	if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq))
  		GetField_CString(hContext,"txn_seq",&csTxnSeq);
DEBUGLOG(("Request() txn_seq = [%s]\n",csTxnSeq));

	if (iRet == PD_OK) {
		TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUs2CCT","Request");
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,inBuf,*iLen,&outBuf,&oLen);
DEBUGLOG(("TxnCctOnUsCCT::Request() iRet = [%d] from TxnWebOnUs2CCT:Request\n",iRet));
DEBUGLOG(("TxnCctOnUsCCT::Request() [%d[%s]\n",oLen,outBuf));
	}
	
	if (iRet == PD_OK) {
       		MsgObjPtr = CreateObj(MsgPtr,"CctMsg","GetResult");
        	iRet = (unsigned long)(*MsgObjPtr)(outBuf,oLen,&outBuf2,&oLen2);
		if (iRet == PD_OK) {
//Commit current
			TxnCommit();
                        lKey = GetMQKey((const unsigned char *)"SYSIQ");
                        lRspKey = GetMQKey((const unsigned char *)"CCTPRSPQ");
			sMsg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                        sMsg->mtype  = ctol((const unsigned char *)csTxnSeq,strlen(csTxnSeq));

			rMsg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                        rMsg->mtype  = ctol((const unsigned char *)csTxnSeq,strlen(csTxnSeq));

			memset(sMsg->mtext,0,sizeof(sMsg->mtext));
			memset(rMsg->mtext,0,sizeof(rMsg->mtext));
                	MQ_build_header((unsigned char*)sMsg->mtext,
                        	MQ_REQ,
                                "XPY",
                                0,
                                "CCTPRSPQ",
                                0);
			memcpy(&sMsg->mtext[MQ_HEADER_LEN],outBuf2,oLen2);
			iSendLen = MQ_HEADER_LEN + oLen2;
			memcpy(&sMsg->mtext[iSendLen],csPostfix,strlen(csPostfix));
			iSendLen += strlen(csPostfix);

                        sMsg->mtext[iSendLen] = '\0';

DEBUGLOG(("Request:: send to SYSIQ\n"));
			if (MQSendRecv(lKey,sMsg,iSendLen,lRspKey,rMsg,&iRecvLen,10) == MQ_OK) {
				memset(outBuf,0,sizeof(outBuf));
				memcpy(outBuf,&rMsg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);
				oLen = iRecvLen - MQ_HEADER_LEN;
				outBuf[oLen] = '\0';
DEBUGLOG(("Request:: Recv MSG = [%s]\n",outBuf));

				memset(inBuf,0,sizeof(inBuf));
				sprintf((char*)inBuf,"%s&url_method=POST",outBuf);
				*iLen = strlen((const char*)inBuf);
DEBUGLOG(("Request:: RET MSG = [%s]\n",inBuf));
			}
			else {
ERRLOG("TxnCctOnUsCCT: Request MQSendRecv error for txn id [%s]\n",csTxnSeq);
DEBUGLOG(("TxnCctOnUsCCT: Request MQSendRecv error for txn id [%s]\n",csTxnSeq));
			}

		}
	}
	return	iRet;
}
