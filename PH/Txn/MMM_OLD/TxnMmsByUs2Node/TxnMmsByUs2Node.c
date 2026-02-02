/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/15              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUs2Node.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Msg);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(DB);

void TxnMmsByUs2Node(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	long	lKey;
	long	lRspKey;
	char	*csNodeId;
	char    *csTxnSeq;
	char    *csDtlTxnSeq;
	hex_t   *h_msg;
	struct  msg_t *msg;
	int     iSendLen,iRecvLen;
	char	*csTmp;

	int	iNodeRet = 0;
	char    cAutoReverse;	

	int 	iTest2NodeErr = PD_FALSE; /*PD_FALSE;*/
	int 	iTestReverseErr = PD_FALSE; /*PD_FALSE;*/
	char	cTmp;


DEBUGLOG(("Authorize\n"));
	if(GetField_CString(hContext,"new_txn_seq",&csTxnSeq)){
		PutField_CString(hRequest,"org_txn_seq",csTxnSeq);
DEBUGLOG(("txn_seq = [%s]\n",csTxnSeq));
	}
	else{
        	if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
			PutField_CString(hRequest,"org_txn_seq",csTxnSeq);
DEBUGLOG(("txn_seq = [%s]\n",csTxnSeq));
		}
	}

         if(GetField_CString(hContext,"dtl_txn_seq",&csDtlTxnSeq)){
		//PutField_CString(hRequest,"org_dtl_txn_seq",csDtlTxnSeq);
DEBUGLOG(("dtl_txn_seq = [%s]\n",csDtlTxnSeq));
	}

/* node id */
	if (GetField_CString(hRequest,"mms_node_id",&csNodeId)) {
DEBUGLOG(("node id  = [%s]\n",csNodeId));
        }

	if (!GetField_CString(hRequest, "service_code", &csTmp)) {
		if (GetField_CString(hContext,"service_code",&csTmp)) {
DEBUGLOG(("set service_code = [%s]\n",csTmp));
			PutField_CString(hRequest, "service_code", csTmp);
		}
	}


	MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BuildAuthData");
        if ((*MsgObjPtr)(hRequest) == PD_OK) {
/* version_no */
		PutField_CString(hRequest,"version_no","1");
/* md5 */
              	PutField_CString(hRequest,"encrypt_type",PD_ENC_TYPE_MD5);
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMMSMac");
                if ((*BOObjPtr)(hContext,hRequest,hRequest) == PD_OK) {
			char csQueueName[PD_QUEUE_LEN +1];
			char csRspQueueName[PD_QUEUE_LEN +1];
                        sprintf(csQueueName,"MMS%sREQQ",csNodeId);
                        sprintf(csRspQueueName,"MMS%sRSPQ",csNodeId);
/* Request Host Queue */
                        lKey = GetMQKey((const unsigned char *)csQueueName);
DEBUGLOG(("lKey = [%ld]\n",lKey));
/* Client Response Queue */
                        lRspKey = GetMQKey((const unsigned char *)csRspQueueName);
DEBUGLOG(("lRspKey = [%ld]\n",lRspKey));

                        MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","FormatMsg");
			h_msg = (hex_t*) malloc (sizeof(hex_t));
                        if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
				msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                       		msg->mtype  = ctol((const unsigned char *)(&csTxnSeq[1]),strlen(csTxnSeq) -1);
                                memset(msg->mtext,0,sizeof(msg->mtext));
                                MQ_build_header((unsigned char*)msg->mtext,
                                MQ_REQ,
                                "MMS",
                                0,
                                csRspQueueName,
                                0);
                                memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
                                iSendLen = MQ_HEADER_LEN + h_msg->len;
DEBUGLOG(("Response Queue = [MMSREQQ] Request Queue = [%s]\n",csQueueName));
DEBUGLOG(("send msg = [%s] send len = [%d]\n",msg->mtext,iSendLen));
DEBUGLOG(("rspkey = [%ld][%ld]\n",lRspKey,msg->mtype));
				if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Sent Error\n"));
                               		iRet = PD_ERR;
					PutField_Int(hContext, "internal_error", iRet);
                               	}
				else {
                                	memset(msg->mtext,0,sizeof(msg->mtext));
                                        if (MQRecv(lRspKey,msg,&iRecvLen,2) != MQ_OK ) {
DEBUGLOG(("recv Error\n"));
						iRet = PD_ERR;
						PutField_Int(hContext, "internal_error", iRet);
                                        }
                                       	else {
/****** TESTING *****/
if ((iTest2NodeErr == PD_TRUE)  || GetField_Char(hContext, "test_case", &cTmp)) {
iRet = PD_ERR;
PutField_Int(hContext, "internal_error", iRet);
} else {
/****** TESTING *****/

                                        	msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("recv len = [%d]\n",iRecvLen));
                               			memcpy(h_msg->msg,&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);

DEBUGLOG(("Call MmsMsg:BreakDownNodeMsg\n"));
						MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BreakDownNodeMsg");
						if ((*MsgObjPtr)(hResponse,h_msg->msg,(iRecvLen-MQ_HEADER_LEN)) != PD_OK)  {
							iRet = INT_BREAKDOWN_ERR;
							PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnMmsByUs2Node::BreakDownNodeMsg MmsMsg Error\n");
DEBUGLOG(("TxnMmsByUs2Node:BreakDownNodeMsg MmsMsg Error\n"));
						} else {
							iNodeRet = PD_OK;
							if (GetField_Int(hResponse, "response_code", &iNodeRet)) {
DEBUGLOG(("Node return result = [%d]\n",iNodeRet));
								if (iNodeRet == PD_OK) {
									RemoveField_Int(hResponse, "response_code");
								}
							}
						}
/***** TESTING *****/
}
/***** TESTING *****/
                                        }
                           	}

				FREE_ME(msg);
			}

			/**** for TESTING *****/
			//iRet = PD_ERR; 
			//PutField_Int(hContext, "internal_error", iRet);
			/**** for TESTING *****/


			if (GetField_Char(hRequest, "auto_reverse", &cAutoReverse)) {
				if (iRet == PD_OK) {
					if (GetField_Int(hResponse, "response_code", &iNodeRet)) {
DEBUGLOG(("TxnMmsByUs2Node: auto_reverse case, receive error code\n"));
						PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_PENDING);
					} else {
DEBUGLOG(("TxnMmsByUs2Node: auto_reverse case, succ to send and recv\n"));
						PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_SUCC);
					}
				}
				else {
DEBUGLOG(("TxnMmsByUs2Node: auto_reverse case, error result\n"));
				PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_PENDING);

				}
			}
			
			int iRevRet = PD_OK;
			char	*csOrgHostDtlRef = NULL;
			char	csNewSubTxnCode[PD_TXN_CODE_LEN];

			if (iRet!=PD_OK && !GetField_Char(hRequest, "auto_reverse", &cAutoReverse)) {
//send reversing to node//
DEBUGLOG(("TxnMmsByUs2Node: Send reversing to Node\n"));

				memset(csNewSubTxnCode, 0, sizeof(csNewSubTxnCode));

				/* host_dtl_ref */
				if (GetField_CString(hRequest, "host_dtl_ref", &csOrgHostDtlRef)) {
DEBUGLOG(("TxnMmsByUs2Node::Org host_dtl_ref = [%s]\n",csOrgHostDtlRef));
				}


				PutField_CString(hRequest,"process_type",PD_MMS_PROCESS_REV);
				PutField_CString(hRequest,"process_code",PD_MMS_REV_MONEY_MOVEMENT);
		
				if (iRevRet == PD_OK) {	

					MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","FormatMsg");
					h_msg = (hex_t*) malloc (sizeof(hex_t));

					if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {

						msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
						msg->mtype  = ctol((const unsigned char *)(&csTxnSeq[2]),strlen(csTxnSeq) -2);
						memset(msg->mtext,0,sizeof(msg->mtext));

						MQ_build_header((unsigned char*)msg->mtext,
								MQ_REQ,
								"MMS",
								0,
								csRspQueueName,
								0);

						memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
						msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
						iSendLen = MQ_HEADER_LEN + h_msg->len;
DEBUGLOG(("Response Queue = [MMSREQQ] Request Queue = [%s]\n",csQueueName));
DEBUGLOG(("send msg = [%s] send len = [%d]\n",msg->mtext,iSendLen));
DEBUGLOG(("rspkey = [%ld][%ld]\n",lRspKey,msg->mtype));
					
						if (MQSend(lKey,msg,iSendLen) != MQ_OK ) {
DEBUGLOG(("Sent Error\n"));
							iRevRet = PD_ERR;
						}
						else {
/****** TESTING ******/
if ((iTestReverseErr == PD_TRUE)  || GetField_Char(hContext, "test_case", &cTmp)) {
iRevRet = PD_ERR;
DEBUGLOG(("Simulate Recv Reverse problem\n"));
} else {
/****** TESTING ******/

							memset(msg->mtext,0,sizeof(msg->mtext));
							if (MQRecv(lRspKey,msg,&iRecvLen,2) != MQ_OK ) {
DEBUGLOG(("recv Error\n"));
								iRevRet = PD_ERR;
							}
							else {
								msg->mtext[iRecvLen] = '\0';
DEBUGLOG(("recv len = [%d]\n",iRecvLen));
								memcpy(h_msg->msg,&msg->mtext[MQ_HEADER_LEN],iRecvLen - MQ_HEADER_LEN);

DEBUGLOG(("Call MmsMsg:BreakDownNodeMsg\n"));
								MsgObjPtr = CreateObj(MsgPtr,"MmsMsg","BreakDownNodeMsg");
								if ((*MsgObjPtr)(hResponse,h_msg->msg,(iRecvLen-MQ_HEADER_LEN)) != PD_OK)  {
									iRevRet = INT_BREAKDOWN_ERR;
ERRLOG("TxnMmsByUs2Node::BreakDownNodeMsg MmsMsg Error\n");
DEBUGLOG(("TxnMmsByUs2Node:BreakDownNodeMsg MmsMsg Error\n"));
								} else {
									iNodeRet = PD_OK;
									if (GetField_Int(hResponse, "response_code", &iNodeRet)) {
DEBUGLOG(("Node return result = [%d]\n",iNodeRet));
										if (iNodeRet == PD_OK) {
											RemoveField_Int(hResponse, "response_code");
										}
									}
								}
							}
/****** TESTING ******/
}
/****** TESTING ******/
						}
						FREE_ME(msg);
					}
				}

///////TESTING
				//iRevRet = PD_ERR;
//////////

				if (iRevRet == PD_OK) {
					if (GetField_Int(hResponse, "response_code", &iNodeRet)) {
DEBUGLOG(("Assign auto_reverse to [%c] reponse_code [%d]\n", PD_MMS_SYS_REV_PENDING, iNodeRet));
						PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_PENDING);
					}
					else {
						PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_SUCC);
DEBUGLOG(("Assign auto_reverse to [%c]\n", PD_MMS_SYS_REV_SUCC));
					}
				}
				else {
					PutField_Char(hResponse, "auto_reverse", PD_MMS_SYS_REV_PENDING);
DEBUGLOG(("Assign auto_reverse to [%c]\n", PD_MMS_SYS_REV_PENDING));
				}
			} 

			//if (!GetField_Char(hRequest, "auto_reverse", &cTmp)) {

				if (GetField_Char(hResponse, "auto_reverse", &cAutoReverse)) {
DEBUGLOG(("response auto_reverse [%c]\n", cAutoReverse));
					if (cAutoReverse == PD_MMS_SYS_REV_PENDING) {
					//pending reverse
DEBUGLOG(("Insert into mms_reverse_retry\n"));
						TxnObjPtr = CreateObj(TxnPtr,"TxnMmsByUsREV","Authorize");
						iRevRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hRequest);

DEBUGLOG(("Call TxnMmsByUsREV return = [%d]\n",iRevRet));
					}
				}
			//}

			FREE_ME(h_msg);

		}
	}

DEBUGLOG(("exit iret = [%d]\n",iRet));
	return 	iRet;
}
