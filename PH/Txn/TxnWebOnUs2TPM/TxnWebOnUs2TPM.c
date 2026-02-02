/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/08/12              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2TPM.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);
OBJPTR(BO);
int     UpdatePreTPMRespTxnLog(hash_t *hContext,
                	hash_t* hResponse);

int     AddTPMTxnLog(hash_t *hContext,
                const hash_t* hRequest);

void TxnWebOnUs2TPM(char    cdebug)
{
        cDebug = cdebug;
}
int     AddTPMTxnLog(hash_t *hContext,
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
DEBUGLOG(("AddTPMTxnLog:: txn_seq = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* psp id */
        if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddTPMTxnLog:: psp_id = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"psp_id",csTmp);
        }

/* txn amt*/
        if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("AddTPMTxnLog:: txn_amt = [%f]\n",dTmp));
       		PutField_Double(hPspDetail,"txn_amt",dTmp);
        }
/* txn_ccy*/
       if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddTPMTxnLog:: txn_ccy = [%s]\n",csTmp));
      		PutField_CString(hPspDetail,"txn_ccy",csTmp);
       }

/* txn_desc */
       if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddTPMTxnLog:: txn_desc = [%s]\n",csTmp));
       		PutField_CString(hPspDetail,"desc",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
       	iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

	return iRet;
};


int     UpdatePreTPMRespTxnLog(hash_t *hContext,
                	hash_t* hResponse)

{
        int     iRet = PD_OK;
        char    *csTmp = NULL;
        char    *csTxnSeq= NULL;
        char    *csStatus;
	char	*csPtr;
	double	dAmt = 0.0;
	hash_t	*hPspDetail;
	hash_t	*hTxn;
	hash_t	*hRec;
DEBUGLOG(("TxnWebOnUs2TPM::UpdateRespTxnLog()\n"));

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);

        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

/* txn_seq from response */
        if (GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateTxnLog RESP:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hPspDetail,"txn_seq",csTxnSeq);
	}
        else if (GetField_CString(hContext,"txn_seq",&csTxnSeq)) {
DEBUGLOG(("UpdateTxnLog RESP:: txn_seq = [%s]\n",csTxnSeq));
                PutField_CString(hPspDetail,"txn_seq",csTxnSeq);
        }

/* notice status */
	char*	csTmpStatus;
        if (GetField_CString(hResponse,"notice_status",&csStatus)) {
DEBUGLOG(("UpdateTxnLog RESP:: notice_status = [%s]\n",csStatus))
                PutField_CString(hPspDetail,"notice_status",csStatus);
		csTmpStatus=strdup(csStatus);
        }
	else {
DEBUGLOG(("UpdateTxnLog RESP:: notice_status not found\n"));
		csTmpStatus=strdup(" ");
		
	}

/* sc */
        if (GetField_CString(hResponse,"sc",&csPtr)) {
DEBUGLOG(("UpdateTxnLog RESP:: sc = [%s]\n",csPtr))
                PutField_CString(hPspDetail,"sc",csPtr);
                PutField_CString(hContext,"sc",csPtr);
        }


        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
        iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

DEBUGLOG(("UpdateTxnLog  iRet = [%d] after Update TxnPspDetail\n",iRet));
        if (iRet == PD_OK) {
		int	iResult;
        	DBObjPtr = CreateObj(DBPtr,"DBMessages","c2i");
        	iRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_TENMOBPAY,&iResult,csTmpStatus);

                if (iResult != PD_OK) {
			iRet = iResult;
			PutField_Int(hContext,"internal_error",iRet);			
			RemoveField_CString(hContext,"redirect_url");


			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
			if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"txn_code",&csTmp)){
						PutField_CString(hTxn,"txn_code",csTmp);
DEBUGLOG(("GetTxnHeader::txn_code = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"channel_code",&csTmp)){
						PutField_CString(hTxn,"org_channel_code",csTmp);
DEBUGLOG(("GetTxnHeader::channel_code = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"service_code",&csTmp)){
						PutField_CString(hTxn,"org_service_code",csTmp);
DEBUGLOG(("GetTxnHeader::service_code = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"merchant_id",&csTmp)){
						PutField_CString(hTxn,"org_merchant_id",csTmp);
DEBUGLOG(("GetTxnHeader::merchant_id = [%s]\n",csTmp));
					}
					if(GetField_Double(hRec,"txn_amt",&dAmt)){
						PutField_Double(hTxn,"org_txn_amt",dAmt);
DEBUGLOG(("GetTxnHeader::txn_amt = [%f]\n",dAmt));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
			if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if(GetField_CString(hRec,"txn_ccy",&csTmp)){
						PutField_CString(hTxn,"org_txn_ccy",csTmp);
DEBUGLOG(("GetTxnDetail::txn_ccy = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"txn_country",&csTmp)){
						PutField_CString(hTxn,"org_txn_country",csTmp);
DEBUGLOG(("GetTxnDetail::txn_country = [%s]\n",csTmp));
					}
					if(GetField_CString(hRec,"selected_pay_method",&csTmp)){
						PutField_CString(hTxn,"selected_pay_method",csTmp);
DEBUGLOG(("GetTxnDetail::selected_pay_method = [%s]\n",csTmp));
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			if (GetField_CString(hContext,"psp_id",&csTmp)) {
				PutField_CString(hTxn,"psp_id",csTmp);
DEBUGLOG(("GetTxnPspDetail::psp_id = [%s]\n",csTmp));
			}
			if (GetField_CString(hContext,"dst_txn_ccy",&csTmp)) {
				PutField_CString(hTxn,"dst_txn_ccy",csTmp);
DEBUGLOG(("GetTxnPspDetail::psp_txn_ccy = [%s]\n",csTmp));
			}
			if (GetField_Double(hContext,"dst_net_amt",&dAmt)) {
				PutField_Double(hTxn,"dst_txn_amt",dAmt);
DEBUGLOG(("GetTxnPspDetail::txn_amt = [%lf]\n",dAmt));
			}

			//update request counter
DEBUGLOG(("update txn counter!\n"));
			BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspReqStat");
			if ((BOObjPtr)(hTxn,hTxn,hResponse) == PD_OK) {
				BOObjPtr = CreateObj(BOPtr,"BOStat","UpdateDspReqMerchantStat");
				(BOObjPtr)(hTxn,hTxn,hResponse);
			}
                }
        }

	FREE_ME(csTmpStatus);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);
        FREE_ME(hTxn);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("UpdateRespTxnLog Exit [%d]\n",iRet));
        return iRet;
}

int     process_resp_txn(hash_t *hContext,
                                const hex_t* inMsg)
{
        int     iRet = PD_OK;
	char	*csTxnCode;
        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);
        
DEBUGLOG(("process_resp_txn()\n"));

	PutField_CString(hContext,"psp_channel_code",PD_CHANNEL_TENMOBPAY);
	GetField_CString(hContext,"txn_code",&csTxnCode);
      	MsgObjPtr = CreateObj(MsgPtr,"TpmMsg","BreakDownMsg");

        if ((*MsgObjPtr)(hResponse,inMsg->msg,inMsg->len) != PD_OK)  {
		iRet = INT_BREAKDOWN_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_resp_txn:BreakDown FepMsg Error\n"));
	}
	else {
DEBUGLOG(("process_resp_txn() call Update\n"));
		iRet = UpdatePreTPMRespTxnLog(hContext,hResponse);
	}
        hash_destroy(hResponse);
        FREE_ME(hResponse);

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}               

int     process_resp_err_txn(hash_t *hContext) 
{
        int     iRet = PD_OK;
	char	*csTxnCode;
        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);
        
DEBUGLOG(("process_resp_err_txn()\n"));

	PutField_CString(hContext,"psp_channel_code",PD_CHANNEL_TENMOBPAY);
	GetField_CString(hContext,"txn_code",&csTxnCode);
	PutField_CString(hResponse,"notice_status","INV_OTH");

DEBUGLOG(("process_resp_err_txn() call Update\n"));
	iRet = UpdatePreTPMRespTxnLog(hContext,hResponse);

        hash_destroy(hResponse);
        FREE_ME(hResponse);

DEBUGLOG(("process_resp_err_txn:exit iret = [%d]\n",iRet));
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


DEBUGLOG(("TxnWebOnUs2TPM: Authroize()\n"));
	if (!GetField_CString(hContext,"org_txn_code",&csTxnCode))
		GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("TxbWebOnUs2TPM: txn_code = [%s]\n",csTxnCode));

	if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) && strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) //if none batch txn
		iRet = AddTPMTxnLog(hContext,hRequest);

	if (iRet == PD_OK) {

//ver
		PutField_CString((hash_t*)hRequest,"ver","2.0");
//charset
		PutField_CString((hash_t*)hRequest,"charset","1");
//bank_code
		PutField_CString((hash_t*)hRequest,"bank_code","0");
//txn_desc
		PutField_CString((hash_t*)hRequest,"txn_desc","DSP");
//free_type
		PutField_CString((hash_t*)hRequest,"free_type","1");

	        if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) 
       		 	GetField_CString(hContext,"txn_seq",&csTxnSeq);

       		 	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GeneratePspSign");
       		 	if ((*BOObjPtr)(hContext,hRequest,hRequest) == PD_OK) {
			
       		 		MsgObjPtr = CreateObj(MsgPtr,"TpmMsg","FormatMsg");
       		 		h_msg = (hex_t*) malloc (sizeof(hex_t));
       		 		if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
        
       	        			lKey = GetMQKey((const unsigned char *)"TPYPREQQ");
       		         		lRspKey = GetMQKey((const unsigned char *)"TPYPRSPQ");
        
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
					//wait for 32 secs
                			if (MQRecv(lRspKey,msg,&iRecvLen,PD_MQ_RECV_TIMEOUT * 3 + 2) != MQ_OK ) {
                			//if (MQRecv(lRspKey,msg,&iRecvLen,1) != MQ_OK ) {
DEBUGLOG(("recv Error\n"));
	               		         	//iRet = PD_ERR;
						iRet = process_resp_err_txn(hContext);
DEBUGLOG(("TxnWebOnUs2TPM: after process_resp_err_txn iret = [%d]\n",iRet));
					}
					else {
						msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("TxnWebOnUs2TPM:  recv len = [%d]\n",iRecvLen));
DEBUGLOG(("TxnWebOnUs2TPM:  recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN));
						memcpy(h_msg->msg,&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);
						iRet = process_resp_txn(hContext,h_msg);
DEBUGLOG(("TxnWebOnUs2TPM: after process_resp_txn iret = [%d]\n",iRet));
					}
                		}
        			FREE_ME(msg);
        		}     
        		else {
               		 	iRet = INT_FORMAT_ERR;
        		}       
        		FREE_ME(h_msg);
		}
		else {
DEBUGLOG(("TxnWebOnUs2TPM: BuildData Error\n"));
		}
	}

DEBUGLOG(("TxnWebOnUs2TPM: noraml exit iret = [%d]\n",iRet));
	return iRet;
}

