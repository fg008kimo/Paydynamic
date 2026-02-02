/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/10/18             Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsWTB.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Msg);

void TxnWebOnUsWTB(char    cdebug)
{
        cDebug = cdebug;
}

int     AddWTBTxnLog(const hash_t *hContext,
                const hash_t* hRequest);


int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	char*   csHandler = NULL;
        int     iRet = PD_OK;
	char*	csTmp = NULL;
	char*	csPspId = NULL;
	char	csTag[PD_TAG_LEN +1];
	double	dTmp;
	int	iTotal = 0,i;
	int	iErr = 0;
	char	csTxnSeq[PD_TXN_SEQ_LEN + 1];
	char	*csTxnSeqPtr;
	char	csBuf[PD_TMP_BUF_LEN +1];

	recordset_t     *rRecordSet;
	hex_t	*h_msg;
	hash_t	*hRec;
	struct	msg_t* msg;
	long	lKey;
	long	lResponseQueueMtype;

	//double	dTmp;

DEBUGLOG(("TxnWebOnUsWTB: Authroize()\n"));

/* txn_code */
	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTB: txn_code = [%s]\n",csTmp));
		PutField_CString((hash_t*)hRequest,"txn_code",csTmp);
	}

	GetField_Int(hRequest,"total",&iTotal);
DEBUGLOG(("TxnWebOnUsWTB: total = [%d]\n",iTotal));


/* psp Url */
	if (GetField_CString(hContext,"psp_url",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTB: psp_url = [%s]\n",csTmp));
		PutField_CString((hash_t*)hRequest,"psp_url",csTmp);
	}
/* request_function */
	if (GetField_CString(hContext,"request_function",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTB: request_function = [%s]\n",csTmp));
		PutField_CString((hash_t*)hRequest,"request_function",csTmp);
	}

/* action */
	if (GetField_CString(hContext,"action",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTB: action = [%s]\n",csTmp));
		PutField_CString((hash_t*)hRequest,"action",csTmp);
	}

/* access_key */
	if (GetField_CString(hContext,"psp_key",&csTmp)) {
DEBUGLOG(("TxnWebOnUsWTB: access_key = [%s]\n",csTmp));
		PutField_CString((hash_t*)hRequest,"access_key",csTmp);
	}

	for (i = 0; i < iTotal; i ++ ) {
/* txn_seq */
		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
		sprintf(csTag,"order_num_%d",i);
       		strcpy(csTxnSeq,(*DBObjPtr)());
DEBUGLOG(("TxnWebOnUsWTB: %s = [%s]\n",csTag,csTxnSeq));
		PutField_CString((hash_t*)hRequest,csTag,strdup(csTxnSeq));

		sprintf(csTag,"txn_amt_%d",i);
		if (GetField_Double(hContext,csTag,&dTmp)) {
			PutField_Double((hash_t*) hRequest,csTag,dTmp);
DEBUGLOG(("TxnWebOnUsWTB: %s = [%f]\n",csTag,dTmp));
		}

		sprintf(csTag,"merchant_client_id_%d",i);
		if (GetField_CString(hContext,csTag,&csTmp)) {
			PutField_CString((hash_t*) hRequest,csTag,csTmp);
DEBUGLOG(("TxnWebOnUsWTB: %s = [%s]\n",csTag,csTmp));
		}

	}


/* psp id */
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("TxnWebOnUsWTB: psp_id = [%s]\n",csPspId));
	}
	else {
		PutField_Int(hContext,"internal_error",INT_ERR);
ERRLOG("TxnWebOnUsWTB can't find PSP ID\n");
		iRet = INT_ERR;
	}
	if (iRet == PD_OK) {
		iRet = AddWTBTxnLog(hContext,hRequest);
	}
	if (iRet == PD_OK) {
        	csHandler = (char*) malloc (20);
        	sprintf(csHandler,"TxnWebOnUs2%s",csPspId);
DEBUGLOG(("TxnWebOnUsWTB Txn Object [%s]\n",csHandler));
        	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
        	FREE_ME(csHandler);
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
DEBUGLOG(("iRet = [%d]\n",iRet));	
	}
	if (iRet == PD_OK) {
		PutField_Int(hResponse,"total",iTotal);
		for (i = 0; i < iTotal; i ++ ) {
DEBUGLOG(("TxnWebOnUsWTB: copy to response \n"));
			sprintf(csTag,"merchant_id_%d",i);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				PutField_CString(hResponse,csTag,csTmp);
DEBUGLOG(("TxnWebOnUsWTB: copy to response %s = %s\n",csTag,csTmp));
			}

			sprintf(csTag,"merchant_ref_%d",i);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				PutField_CString(hResponse,csTag,csTmp);
DEBUGLOG(("TxnWebOnUsWTB: copy to response %s = %s\n",csTag,csTmp));

			}
/* batch id */
			sprintf(csTag,"batch_id_%d",i);
			if (GetField_CString(hRequest,csTag,&csTmp)) {
				PutField_CString(hResponse,csTag,csTmp);
DEBUGLOG(("TxnWebOnUsWTB: copy to response %s = %s\n",csTag,csTmp));

			}

			iErr = PD_OK;
			sprintf(csTag,"internal_error_%d",i);
			if (GetField_Int(hRequest,csTag,&iErr)) {
DEBUGLOG(("TxnWebOnUsWTB: %s = [%d] \n",csTag,iErr));
			}
			if (iErr ==  INT_DUP_MERCHANT_REF) {
				sprintf(csTag,"response_code_%d",i);
				sprintf(csBuf,"%d",iErr);
				PutField_CString(hResponse,csTag,csBuf);
				continue;
			}
/* copy to response */
			sprintf(csTag,"order_num_%d",i);
			if (GetField_CString(hRequest,csTag,&csTxnSeqPtr)) {
DEBUGLOG(("TxnWebOnUsWTB: copy to response %s = %s\n",csTag,csTxnSeqPtr));
				sprintf(csTag,"txn_seq_%d",i);
				PutField_CString(hResponse,csTag,csTxnSeqPtr);
			}

			
			rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        		recordset_init(rRecordSet,0);

			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                       if ((*DBObjPtr)(csTxnSeqPtr,rRecordSet) == PD_OK) {
DEBUGLOG(("found record = [%s]\n",csTxnSeqPtr));
                       		hRec = RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                	if (GetField_CString(hRec,"response_code",&csTmp)) {
						sprintf(csTag,"response_code_%d",i);
						PutField_CString(hResponse,csTag,csTmp);
DEBUGLOG(("%s = %s\n",csTag,csTmp));
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
              			}
			}
			RecordSet_Destroy(rRecordSet);
        		FREE_ME(rRecordSet);  


		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("call FormatBatchMsg\n"));
                h_msg = (hex_t*) malloc (sizeof(hex_t));
		memset(h_msg->msg,0,sizeof(h_msg->msg));
		MsgObjPtr = CreateObj(MsgPtr,"WebMsg","FormatBatchMsg");
                if ((*MsgObjPtr)(hResponse,h_msg->msg,&h_msg->len) == PD_OK) {
                }

DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
		if (GetField_CString(hContext,"reply_queue",&csTmp)) {
DEBUGLOG(("UpdateContext:reply queue = [%s]\n",csTmp));
                	lKey = GetMQKey((unsigned char*)csTmp);
DEBUGLOG(("UpdateContext:reply queue key = [%ld]\n",lKey));
        	}

 		if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("response queue mtype = [%ld]\n",lResponseQueueMtype));
                }
                msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                msg->mtype  = lResponseQueueMtype;
                memset(msg->mtext,0,sizeof(msg->mtext));
                MQ_build_header((unsigned char*)msg->mtext,
                	MQ_RESP,
                	"WEB",
                         0,
                    	NULL,
			0);
                memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

                iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
                FREE_ME(h_msg);
                FREE_ME(msg);
	}

	FREE_ME(csTmp);
	FREE_ME(csPspId);
	
DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}

int     AddWTBTxnLog(const hash_t *hContext,
                const hash_t* hRequest)

{
        hash_t  *hTxn;
        hash_t  *hDetail;
        hash_t  *hPsp;
        int iRet = PD_OK;
	int	iTotal,i;
	int	iInternalErr = 0;
	double	dTmp;

        char    *csTmp = strdup("");
	char	csTag[PD_TAG_LEN +1];
        
        
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hDetail= (hash_t*)  malloc (sizeof(hash_t));
        hPsp= (hash_t*)  malloc (sizeof(hash_t));

	GetField_Int(hRequest,"total",&iTotal);
DEBUGLOG(("AddTxnLog:: total = [%d]\n",iTotal));

	for (i = 0; i < iTotal; i++) {
        	hash_init(hTxn,0); 
        	hash_init(hDetail,0); 
        	hash_init(hPsp,0); 

		sprintf(csTag,"internal_error_%d",i);
		GetField_Int(hRequest,csTag,&iInternalErr);
DEBUGLOG(("AddTxnLog: %s = [%d]\n",csTag,iInternalErr));

		if (iInternalErr == INT_DUP_MERCHANT_REF)
			continue; //skip
		
		sprintf(csTag,"order_num_%d",i);
DEBUGLOG(("try to get %s\n",csTag));
        	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_seq = [%s]\n",csTmp));
                	PutField_CString(hTxn,"txn_seq",csTmp);
                	PutField_CString(hDetail,"txn_seq",csTmp);
                	PutField_CString(hPsp,"txn_seq",csTmp);
                
                	PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
                	PutField_CString(hDetail,"add_user",PD_UPDATE_USER);
                
                	if (GetField_CString(hContext,"channel_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: channel_code = [%s]\n",csTmp));
                       		PutField_CString(hTxn,"channel_code",csTmp);
                	}
                	if (GetField_CString(hContext,"txn_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_code = [%s]\n",csTmp));
                        	PutField_CString(hTxn,"txn_code",csTmp);
                	}
                	if (GetField_CString(hContext,"PHDATE",&csTmp)) {
DEBUGLOG(("AddTxnLog:: host_posting_date = [%s]\n",csTmp));
                       		PutField_CString(hTxn,"host_posting_date",csTmp);
                	}
                	if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_date = [%s]\n",csTmp));
                       		PutField_CString(hTxn,"local_tm_date",csTmp);
                	}

                	if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
DEBUGLOG(("AddTxnLog:: local_tm_time = [%s]\n",csTmp));
                        	PutField_CString(hTxn,"local_tm_time",csTmp);
                	}

/**** From Request */
                	if (GetField_CString(hRequest,"process_type",&csTmp)) {
DEBUGLOG(("AddTxnLog:: process_type = [%s]\n",csTmp));
                        	PutField_CString(hTxn,"process_type",csTmp);
                	}

                	if (GetField_CString(hRequest,"process_code",&csTmp)) {
DEBUGLOG(("AddTxnLog:: process_code = [%s]\n",csTmp));
                       		PutField_CString(hTxn,"process_code",csTmp);
                	}

/* merchant no */
			sprintf(csTag,"merchant_id_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hTxn,"merchant_id",csTmp);
                	}
/* merchant ref */
			sprintf(csTag,"merchant_ref_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                       		PutField_CString(hTxn,"merchant_ref",csTmp);
                	}
/* client id  */
			sprintf(csTag,"merchant_client_id_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                       		PutField_CString(hTxn,"client_id",csTmp);
                	}


/* transmission_datetime */
			sprintf(csTag,"transmission_datetime_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hTxn,"transmission_datetime",csTmp);
                	}


/* add to detail ********************************/

/* txn ccy */
			sprintf(csTag,"txn_ccy_%d",i);
 	               	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
       		                PutField_CString(hDetail,"txn_ccy",csTmp);
                	}

/* txn country */
			sprintf(csTag,"txn_country_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"txn_country",csTmp);
                	}

/* bank code */
			sprintf(csTag,"bank_code_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"bank_code",csTmp);
                	}
/* bank name */
			sprintf(csTag,"bank_name_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"bank_name",csTmp);
                	}
/* branch_name */
			sprintf(csTag,"branch_name_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {

DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                       		PutField_CString(hDetail,"branch_name",csTmp);
                	}

/* account_id */
			sprintf(csTag,"account_id_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"account_id",csTmp);
                	}
/* account_name */
			sprintf(csTag,"account_name_%d",i);
                	if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"account_name",csTmp);
                	}
/* identity_id */
			sprintf(csTag,"identity_id_%d",i);
	                if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hDetail,"identity_id",csTmp);
       		        }

/* batch_id */
			sprintf(csTag,"batch_id_%d",i);
	                if (GetField_CString(hRequest,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
       		                PutField_CString(hDetail,"batch_id",csTmp);
                	}
/* add txn psp */
/* psp id */
                	if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddTxnLog:: psp_id = [%s]\n",csTmp));
                        	PutField_CString(hPsp,"psp_id",csTmp);
                	}
/* txn_desc */
                	if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddTxnLog:: txn_desc = [%s]\n",csTmp));
                        	PutField_CString(hPsp,"desc",csTmp);
                	}
/* txn_ccy */
			sprintf(csTag,"txn_ccy_%d",i);
                	if (GetField_CString(hContext,csTag,&csTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%s]\n",csTag,csTmp));
                        	PutField_CString(hPsp,"txn_ccy",csTmp);
                	}
/* txn_amt */
			sprintf(csTag,"txn_amt_%d",i);
                	if (GetField_Double(hContext,csTag,&dTmp)) {
DEBUGLOG(("AddTxnLog:: %s = [%f]\n",csTag,dTmp));
                        	PutField_Double(hPsp,"txn_amt",dTmp);
                        	PutField_Double(hTxn,"txn_amt",dTmp);
			}

                	PutField_Char(hTxn,"status",PD_PROCESSING);

                	DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
                	iRet = (unsigned long) ((*DBObjPtr)(hTxn));

                	if (iRet == PD_OK ) {
                        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                        	iRet = (unsigned long) ((*DBObjPtr)(hDetail));
                	}
                	if (iRet == PD_OK ) {
                        	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
                        	iRet = (unsigned long) ((*DBObjPtr)(hPsp));
                	}

        	}
        	else
                	iRet = PD_ERR;
        	hash_destroy(hTxn);
        	hash_destroy(hDetail);
        	hash_destroy(hPsp);
	}

        FREE_ME(hTxn);
        FREE_ME(hDetail);
        FREE_ME(csTmp);
DEBUGLOG(("AddTxnLog RET = [%d]\n",iRet));
        return  iRet;

}
