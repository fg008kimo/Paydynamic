/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/04/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2BFQ.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"
#include <time.h>

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);
OBJPTR(BO);
int     UpdatePreBFQRespTxnLog(hash_t *hContext,
                	hash_t* hResponse);

int     AddBFQTxnLog(hash_t *hContext,
                const hash_t* hRequest);

void TxnWebOnUs2BFQ(char    cdebug)
{
        cDebug = cdebug;
}
int     AddBFQTxnLog(hash_t *hContext,
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
DEBUGLOG(("AddBFQTxnLog:: txn_seq = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"txn_seq",csTmp);
        }
/* psp id */
        if (GetField_CString(hContext,"psp_id",&csTmp)) {
DEBUGLOG(("AddBFQTxnLog:: psp_id = [%s]\n",csTmp));
		PutField_CString(hPspDetail,"psp_id",csTmp);
        }

/* txn amt*/
        if (GetField_Double(hContext,"txn_amt",&dTmp)) {
DEBUGLOG(("AddBFQTxnLog:: txn_amt = [%f]\n",dTmp));
       		PutField_Double(hPspDetail,"txn_amt",dTmp);
        }
/* txn_ccy*/
       if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("AddBFQTxnLog:: txn_ccy = [%s]\n",csTmp));
      		PutField_CString(hPspDetail,"txn_ccy",csTmp);
       }

/* txn_desc */
       if (GetField_CString(hContext,"txn_desc",&csTmp)) {
DEBUGLOG(("AddBFQTxnLog:: txn_desc = [%s]\n",csTmp));
       		PutField_CString(hPspDetail,"desc",csTmp);
        }
        DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Add");
       	iRet = (unsigned long)(*DBObjPtr)(hPspDetail);

        hash_destroy(hPspDetail);
        FREE_ME(hPspDetail);

	return iRet;
}


int     UpdatePreBFQRespTxnLog(hash_t *hContext,
                	hash_t* hResponse)

{
        int     iRet = PD_OK;
        char    *csTmp = NULL;
        char    *csTxnSeq= NULL;
        char    *csStatus;
	char	*csPtr;
	int	iTmp;
	double	dAmt = 0.0;
	hash_t	*hPspDetail;
	hash_t	*hLog;
	hash_t	*hTxn;
	hash_t	*hRec;
DEBUGLOG(("TxnWebOnUs2BFQ::UpdateRespTxnLog()\n"));

        hPspDetail = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspDetail,0);

	hLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hLog,0);

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

/* return_code */
	char*	csTmpStatus;
	if (GetField_CString(hResponse,"return_code",&csStatus)) {
DEBUGLOG(("UpdateTxnLog RESP:: return_code = [%s]\n",csStatus))
		csTmpStatus=strdup(csStatus);
	}
	else {
DEBUGLOG(("UpdateTxnLog RESP:: return_code not found\n"));
		csTmpStatus=strdup(" ");
	}

/* code_url */
	if (GetField_CString(hResponse,"code_url",&csPtr)) {
DEBUGLOG(("UpdateTxnLog RESP:: code_url = [%s]\n",csPtr))
		PutField_CString(hPspDetail,"deposit_url",csPtr);
	}

	DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","Update");
	iRet = (unsigned long)(*DBObjPtr)(hPspDetail);
DEBUGLOG(("UpdateTxnLog  iRet = [%d] after Update TxnPspDetail\n",iRet));

// Add QR request log
	PutField_CString(hLog, "txn_id", csTxnSeq);
	if (GetField_Int(hContext, "time_expire", &iTmp)) {
		PutField_Int(hLog, "expiry", iTmp);
	}
	if (GetField_Int(hContext, "time_enable", &iTmp)) {
		PutField_Int(hLog, "enable_button", iTmp);
	}
	if (GetField_Int(hContext, "time_auto_check", &iTmp)) {
		PutField_Int(hLog, "auto_check_txn_status", iTmp);
	}
	if (GetField_Int(hContext, "time_redirect", &iTmp)) {
		PutField_Int(hLog, "redirect", iTmp);
	}
	PutField_CString(hLog, "create_user", PD_UPDATE_USER);

	DBObjPtr = CreateObj(DBPtr, "DBTxnQrRequestLog", "Add");
	iRet = (unsigned long)(*DBObjPtr)(hLog);
DEBUGLOG(("UpdateTxnLog  iRet = [%d] after Insert TxnQrRequestLog\n",iRet));

        if (iRet == PD_OK) {
		int	iResult;
        	DBObjPtr = CreateObj(DBPtr,"DBMessages","c2i");
        	iRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_BFBAO_QR,&iResult,csTmpStatus);

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
	hash_destroy(hLog);
	FREE_ME(hLog);
	hash_destroy(hTxn);
        FREE_ME(hTxn);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("UpdateRespTxnLog Exit [%d]\n",iRet));
        return iRet;
}

int     process_resp_txn(hash_t *hContext,
                                const hex_t* inMsg,
				const hash_t *hRequest)
{
        int	iRet = PD_OK;
	int	iTmpRet;
	int	iSendAlert = PD_FALSE;
	char	*csTxnCode;
	char	*csTmp;
	char	*csTxnSeq= NULL;
	char	*csPspId= NULL;
	char	*csPspName = NULL;
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];
	double	dTmp;
	char *csCmd = (char*) malloc (PD_MAX_FILE_LEN + 1);
        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);
        
DEBUGLOG(("process_resp_txn()\n"));

	PutField_CString(hContext,"psp_channel_code",PD_CHANNEL_BFBAO_QR);
	PutField_CString(hContext,"return_psp_channel",PD_CHANNEL_BFBAO_QR);
	GetField_CString(hContext,"txn_code",&csTxnCode);
	GetField_CString(hContext,"psp_id",&csPspId);
	GetField_CString(hRequest,"psp_name",&csPspName);
      	MsgObjPtr = CreateObj(MsgPtr,"BfqMsg","BreakDownInitRspMsg");

        if ((*MsgObjPtr)(hResponse,inMsg->msg,inMsg->len) != PD_OK)  {
		iRet = INT_BREAKDOWN_ERR;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_resp_txn:BreakDown BfqMsg Error\n"));
	}
//	else {
		// testing
		//RemoveField_CString(hResponse, "code_url");

		if (GetField_CString(hResponse, "return_code", &csTmp)) {
DEBUGLOG(("process_resp_txn: returned return_code = [%s]\n", csTmp));

			if (!strcmp(csTmp, PD_SUCCESS_STATUS)) {
				// verify returned txn_id
				if (GetField_CString(hResponse, "ret_txn_id", &csTmp)) {
DEBUGLOG(("process_resp_txn: returned txn_id = [%s]\n", csTmp));
					if (GetField_CString(hRequest, "order_num", &csTxnSeq)) {
DEBUGLOG(("process_resp_txn: sent txn_id = [%s]\n", csTxnSeq));
					}
					if (strcmp(csTmp, csTxnSeq)) {
DEBUGLOG(("process_resp_txn: txn_id not match!!!\n"));
						PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
						iSendAlert = PD_TRUE;
						// PD_TXN_SEQ_MISMATCH
						sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
						goto skipped;
					}
				} else {
DEBUGLOG(("process_resp_txn: cannot get returned txn_id!!!\n"));
					PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
					iSendAlert = PD_TRUE;
					// PD_MISS_TXN_SEQ
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
					goto skipped;
				}

				// verify returned txn_amt
				if (GetField_CString(hResponse, "amount", &csTmp)) {
DEBUGLOG(("process_resp_txn: returned txn_amt = [%s]\n", csTmp));
					if (GetField_Double(hRequest, "psp_txn_amt", &dTmp)) {
						//sprintf((char*)csTmpAmt, "%.2f", dTmp);
						sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
DEBUGLOG(("process_resp_txn: sent txn_amt = [%s]\n", csTmpAmt));
					}
					if (strcmp(csTmp, csTmpAmt)) {
DEBUGLOG(("process_resp_txn: txn_amt not match!!!\n"));
						PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
						iSendAlert = PD_TRUE;
						// PD_TXN_AMT_MISMATCH
						sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
						goto skipped;
					}
				} else {
DEBUGLOG(("process_resp_txn: cannot get amount!!!\n"));
					PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
					iSendAlert = PD_TRUE;
					// PD_MISS_TXN_AMT
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
					goto skipped;
				}

				// get code_url
				if (!GetField_CString(hResponse, "code_url", &csTmp)) {
DEBUGLOG(("process_resp_txn: cannot get code_url!!!\n"));
					PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
					iSendAlert = PD_TRUE;
					// PD_MISS_CODE_URL
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
					goto skipped;
				}

				// verify returned signature
				if (GetField_CString(hResponse, "sign", &csTmp)) {
DEBUGLOG(("process_resp_txn: returned signature = [%s]\n", csTmp));
					BOObjPtr = CreateObj(BOPtr, "BOSecurity", "VerifyPspSign");
					iTmpRet = (unsigned long)(*BOObjPtr)(hContext, hResponse, hResponse);
					if (iTmpRet != PD_OK) {
DEBUGLOG(("process_resp_txn: signature not match!!!\n"));
						PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
						iSendAlert = PD_TRUE;
						// PD_SIGN_MISMATCH
						sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
						goto skipped;
					}
				} else {
DEBUGLOG(("process_resp_txn: cannot get signature!!!\n"));
					PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
					iSendAlert = PD_TRUE;
					// PD_MISS_SIGNATURE
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_INVALID_FIELD, csPspId, csPspName);
					goto skipped;
				}
			} else {
DEBUGLOG(("process_resp_txn: PSP return FAIL!!!\n"));
				PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
				iSendAlert = PD_TRUE;

				if (GetField_CString(hResponse, "return_msg", &csTmp)) {
DEBUGLOG(("process_resp_txn: returned return_msg = [%s]\n", csTmp));
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\" \"%s\"", PD_PSP_RETURN_FAIL, csPspId, csPspName, csTmp);
					goto skipped;
				} else {
					sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_PSP_RETURN_FAIL, csPspId, csPspName);
					goto skipped;
				}
			}
		} else {
DEBUGLOG(("process_resp_txn: cannot get return_code!!!\n"));
			PutField_CString(hResponse, "return_code", PD_FAIL_STATUS);
			iSendAlert = PD_TRUE;
			// PD_MISS_RETURN_CODE
			sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_PSP_RETURN_FAIL, csPspId, csPspName);
			goto skipped;
		}

skipped:

		if (iSendAlert) {
DEBUGLOG(("process_resp_txn: csCmd = [%s]\n", csCmd));
			system(csCmd);
		}

DEBUGLOG(("process_resp_txn() call Update\n"));
		iRet = UpdatePreBFQRespTxnLog(hContext,hResponse);

		if (GetField_CString(hResponse, "return_code", &csTmp)) {
DEBUGLOG(("process_resp_txn: return_code = [%s]\n", csTmp));
			PutField_CString(hContext, "return_code", csTmp);
		}

		if (GetField_CString(hResponse, "code_url", &csTmp)) {
DEBUGLOG(("process_resp_txn: code_url = [%s]\n", csTmp));
			PutField_CString(hContext, "code_url", csTmp);
		}
//	}
	FREE_ME(csCmd);
        hash_destroy(hResponse);
        FREE_ME(hResponse);

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}               

int     process_resp_err_txn(hash_t *hContext,
				const hash_t *hRequest) 
{
        int     iRet = PD_OK;
	char	*csPspId = NULL;
	char	*csPspName = NULL;
        hash_t  *hResponse;
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hResponse,0);
        
DEBUGLOG(("process_resp_err_txn()\n"));

	PutField_CString(hContext,"psp_channel_code",PD_CHANNEL_BFBAO_QR);
	PutField_CString(hResponse,"return_code",PD_FAIL_STATUS);
	GetField_CString(hContext,"psp_id",&csPspId);
	GetField_CString(hRequest,"psp_name",&csPspName);

	char *csCmd = (char*) malloc (PD_MAX_FILE_LEN + 1);
	sprintf(csCmd, "send_init_req_error.sh \"%s\" \"%s\" \"%s\"", PD_GW_TIMEOUT, csPspId, csPspName);
DEBUGLOG(("process_resp_txn: csCmd = [%s]\n", csCmd));
	system(csCmd);
	FREE_ME(csCmd);

DEBUGLOG(("process_resp_err_txn() call Update\n"));
	iRet = UpdatePreBFQRespTxnLog(hContext,hResponse);

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
	char	*csServiceCode = NULL;
	char	*csPid = NULL;
	int	iTmp;

	hash_t	*hQrTimeParam;
	hQrTimeParam = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hQrTimeParam, 0);


DEBUGLOG(("TxnWebOnUs2BFQ: Authorize()\n"));
	if (!GetField_CString(hContext,"org_txn_code",&csTxnCode))
		GetField_CString(hContext,"txn_code",&csTxnCode);
DEBUGLOG(("TxbWebOnUs2BFQ: txn_code = [%s]\n",csTxnCode));

	if (strcmp(csTxnCode,PD_WITHDRAW_BATCH_TXN_CODE) && strcmp(csTxnCode,PD_INITIAL_TXN_CODE)) //if none batch txn
		iRet = AddBFQTxnLog(hContext,hRequest);

	if (iRet == PD_OK) {

//QR time parameters
		GetField_CString(hContext,"org_service_code",&csServiceCode);
		GetField_CString(hContext,"psp_id",&csPid);

		DBObjPtr = CreateObj(DBPtr,"DBPaypageQrTimeParam","GetByPspId");
		if ((*DBObjPtr)(csServiceCode,csPid,hQrTimeParam) == PD_OK) {
			if (GetField_Int(hQrTimeParam,"expiry",&iTmp)) {
				PutField_Int((hash_t*)hRequest,"time_expire",iTmp);
				PutField_Int((hash_t*)hContext,"time_expire",iTmp);
DEBUGLOG(("TxbWebOnUs2BFQ: time_expire = [%d]\n",iTmp));
			}
			if (GetField_Int(hQrTimeParam,"enable_button",&iTmp)) {
				PutField_Int((hash_t*)hContext,"time_enable",iTmp);
DEBUGLOG(("TxbWebOnUs2BFQ: time_enable = [%d]\n",iTmp));
			}
			if (GetField_Int(hQrTimeParam,"auto_check_txn_status",&iTmp)) {
				PutField_Int((hash_t*)hContext,"time_auto_check",iTmp);
DEBUGLOG(("TxbWebOnUs2BFQ: time_auto_check = [%d]\n",iTmp));
			}
			if (GetField_Int(hQrTimeParam,"redirect",&iTmp)) {
				PutField_Int((hash_t*)hContext,"time_redirect",iTmp);
DEBUGLOG(("TxbWebOnUs2BFQ: time_redirect = [%d]\n",iTmp));
			}
		}

	        if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) 
       		 	GetField_CString(hContext,"txn_seq",&csTxnSeq);

       		 	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GeneratePspSign");
       		 	if ((*BOObjPtr)(hContext,hRequest,hRequest) == PD_OK) {
			
       		 		MsgObjPtr = CreateObj(MsgPtr,"BfqMsg","FormatInitMsg");
       		 		h_msg = (hex_t*) malloc (sizeof(hex_t));
       		 		if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
        
       	        			lKey = GetMQKey((const unsigned char *)"PSPPREQQ");
       		         		lRspKey = GetMQKey((const unsigned char *)"PSPPRSPQ");
        
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
DEBUGLOG(("recv Error\n"));
						iRet = process_resp_err_txn(hContext,hRequest);
DEBUGLOG(("TxnWebOnUs2BFQ: after process_resp_err_txn iret = [%d]\n",iRet));
					}
					else {
						msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("TxnWebOnUs2BFQ:  recv len = [%d]\n",iRecvLen));
DEBUGLOG(("TxnWebOnUs2BFQ:  recv = [%s]\n",&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN));
						memcpy(h_msg->msg,&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);
						iRet = process_resp_txn(hContext,h_msg,hRequest);
DEBUGLOG(("TxnWebOnUs2BFQ: after process_resp_txn iret = [%d]\n",iRet));
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
DEBUGLOG(("TxnWebOnUs2BFQ: BuildData Error\n"));
		}
	}

	hash_destroy(hQrTimeParam);
	FREE_ME(hQrTimeParam);

DEBUGLOG(("TxnWebOnUs2BFQ: noraml exit iret = [%d]\n",iRet));
	return iRet;
}

