/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/10/22              Cody Chan
encrypt type not hard code			   2011/01/27		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnCctByUsACK.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define START_POS       3
#define CONTENT_POS     9
char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Msg);
void TxnCctByUsACK(char    cdebug)
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
	double	dTmp;
	char 	csNewTxnID[PD_TXN_SEQ_LEN +1];
        char    *csValue = strdup("");
        char    *csChannelCode = strdup("");
	char	csTmpChannelCode[PD_CHANNEL_CODE_LEN *2  +1];
	char*	csPtr = NULL;
	char*	csOrgTxnSeq;
	char	cPtr;
	char*	csCCTTxnSeq;
 	struct msg_t* msg;
	hash_t  *hRec;
	hex_t   *h_msg;
	
	hash_t  *hRsp;
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	
        hRsp = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRsp,0);

DEBUGLOG(("TxnCctByUsACK Authorize()\n"));
	if (GetField_CString(hContext,"org_txn_seq",&csOrgTxnSeq)) {
	

		PutField_CString(hRsp,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnCctByUsACK org_txn_seq = [%s]\n",csOrgTxnSeq));
        	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnCctByUsACK found record = [%s]\n",csOrgTxnSeq));
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                       	 	if (GetField_CString(hRec,"process_type",&csPtr)) {
DEBUGLOG(("TxnCctByUsACK:process_type= [%s]\n",csPtr));
					PutField_CString(hRsp,"process_type",csPtr);
				}
                       	 	if (GetField_CString(hRec,"process_code",&csPtr)) {
DEBUGLOG(("TxnCctByUsACK:process_code= [%s]\n",csPtr));
					PutField_CString(hRsp,"process_code",csPtr);
				}
                       	 	if (GetField_CString(hRec,"response_code",&csPtr)) {
DEBUGLOG(("TxnCctByUsACK:response_code= [%s]\n",csPtr));
					PutField_CString(hRsp,"response_code",csPtr);
				}

                       	 	if (GetField_Char(hRec,"ar_ind",&cPtr)) {
DEBUGLOG(("TxnCctByUsACK:ar_ind= [%c]\n",cPtr));
					PutField_Char(hRsp,"ar_ind",cPtr);
				}
                       	 	if (GetField_CString(hRec,"merchant_id",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:merchant_id= [%s]\n",csValue));
					PutField_CString(hRsp,"merchant_id",csValue);
                        	}

                       	 	if (GetField_CString(hRec,"merchant_ref",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:merchant_ref= [%s]\n",csValue));
					sprintf(csNewTxnID,"%c%s",csValue[START_POS],&csValue[CONTENT_POS]);
			//		PutField_CString(hRsp,"txn_seq",csNewTxnID);
DEBUGLOG(("TxnCctByUsACK:***txn_id= [%s]\n",csNewTxnID));
                        	}
				else {
DEBUGLOG(("TxnCctByUsACK:merchant_ref is missing!!!\n"));
				}

/*
                       	 	if (GetField_CString(hRec,"transmission_datetime",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:transmission_datetime= [%s]\n",csValue));
					PutField_CString(hRsp,"transmission_datetime",csValue);
                        	}
*/
                       	 	if (GetField_CString(hRec,"local_transmission_datetime",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:local_transmission_datetime= [%s]\n",csValue));
					PutField_CString(hRsp,"local_transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("TxnCctByUsACK:channel_code= [%s]\n",csChannelCode));
                        	}
                       	 	if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("TxnCctByUsACK:net_amt= [%f]\n",dTmp));
					PutField_Double(hRsp,"net_amt",dTmp);
                        	}
                       	 	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnCctByUsACK:txn_amt= [%f]\n",dTmp));
					PutField_Double(hRsp,"txn_amt",dTmp);
                        	}
                       	 	if (GetField_Int(hRec,"internal_error",&iTmp)) {
DEBUGLOG(("TxnCctByUsACK:internal_error= [%d]\n",iTmp));
					PutField_Int(hRsp,"internal_error",iTmp);
                        	}
                       	 	if (GetField_Double(hRec,"fee",&dTmp)) {
DEBUGLOG(("TxnCctByUsACK:fee= [%f]\n",dTmp));
					PutField_Double(hRsp,"service_fee",dTmp);
                        	}
                        	hRec = RecordSet_GetNext(rRecordSet);
                	}
        	}
		else {
DEBUGLOG(("TxnCctByUsACK not found record for [%s]\n",csOrgTxnSeq));
			iRet = PD_ERR;
		}
        	RecordSet_Destroy(rRecordSet);

	}
	else 	
		iRet = INT_ERR;

	if (iRet == PD_OK) {
		if (GetField_CString(hRsp,"merchant_id",&csPtr)) {
DEBUGLOG(("TxnCctByUsACK merchant id = [%s]\n",csPtr));
			char*	csMerchantRef;
			if (GetField_CString(hResponse,"merchant_ref",&csMerchantRef)) {
DEBUGLOG(("TxnCctByUsACK CCT merchant ref = [%s]\n",csMerchantRef));
			}
			else {
DEBUGLOG(("TxnCctByUsACK CCT merchant ref is missing!!!\n"));
			}
        		recordset_init(rRecordSet,0);
        		DBObjPtr = CreateObj(DBPtr,"DBCctTxn","GetTxnId");
        		if ((unsigned long)(*DBObjPtr)(csPtr,csMerchantRef,rRecordSet) == PD_FOUND) {
DEBUGLOG(("TxnCctByUsACK CCT Record Found\n"));
				hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {
                                	if (GetField_CString(hRec,"txn_id",&csCCTTxnSeq)) {
DEBUGLOG(("TxnCctByUsACK:CCT CCT Txn Seq= [%s]\n",csCCTTxnSeq));
                                	}
                                	hRec = RecordSet_GetNext(rRecordSet);
                        	}
			}
			else {
DEBUGLOG(("TxnCctByUsACK CCT Record Not Found!!\n"));
			}
        		RecordSet_Destroy(rRecordSet);
		}
	}
	
        if ( iRet == PD_OK) {
/* Check Merchant */
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRsp);
DEBUGLOG(("BOMerchant->GetMerchantDetail = [%d]\n",iRet));

        }
	if (iRet == PD_OK) {
		if (GetField_CString(hContext,"merchant_key",&csPtr)) {
DEBUGLOG(("BPMerchant: GetMerchantDetail - merchant_key = [%s]\n",csPtr));
                	PutField_CString(hRsp,"merchant_key",csPtr);
                 }
	}
	if (iRet == PD_OK ) {
        	recordset_init(rRecordSet,0);
        	DBObjPtr = CreateObj(DBPtr,"DBCctTxn","GetTxn");
        	if ((*DBObjPtr)(csCCTTxnSeq,rRecordSet) == PD_OK) {
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                       	 	if (GetField_CString(hRec,"success_url",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:success_url= [%s]\n",csValue));
					PutField_CString(hRsp,"success_url",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"success_callback_url",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:success_callback_url= [%s]\n",csValue));
					PutField_CString(hRsp,"success_callback_url",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"failure_url",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:failure_url= [%s]\n",csValue));
					PutField_CString(hRsp,"failure_url",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"failure_callback_url",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:failure_callback_url= [%s]\n",csValue));
					PutField_CString(hRsp,"failure_callback_url",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"merchant_ref",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:merchant_ref= [%s]\n",csValue));
					PutField_CString(hRsp,"merchant_ref",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"transmission_datetime",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:transmission_datetime= [%s]\n",csValue));
					PutField_CString(hRsp,"transmission_datetime",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"echo_msg_1",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:echo_msg_1= [%s]\n",csValue));
					PutField_CString(hRsp,"echo_msg_1",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"echo_msg_2",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:echo_msg_2= [%s]\n",csValue));
					PutField_CString(hRsp,"echo_msg_2",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"echo_msg_3",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:echo_msg_3= [%s]\n",csValue));
					PutField_CString(hRsp,"echo_msg_3",csValue);
                        	}

				if(GetField_CString(hRec,"encrypt_type",&csValue)){
DEBUGLOG(("TxnCctByUsACK:encrypt_type= [%s]\n",csValue));
                                        PutField_CString(hRsp,"encrypt_type",csValue);
                                }
                                else{
DEBUGLOG(("TxnCctByUsACK:use default encrypt_type= [01]\n"));
                                        PutField_CString(hRsp,"encrypt_type","01");
                                }
                       	 	if (GetField_CString(hRec,"remark",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:remark= [%s]\n",csValue));
					PutField_CString(hRsp,"remark",csValue);
                        	}
                       	 	if (GetField_CString(hRec,"txn_ccy",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:txn_ccy= [%s]\n",csValue));
					PutField_CString(hRsp,"txn_ccy",csValue);
					PutField_CString(hRsp,"net_ccy",csValue);
					PutField_CString(hRsp,"service_fee_ccy",csValue);
                        	}
                       		hRec = RecordSet_GetNext(rRecordSet);
			}
		}
        	RecordSet_Destroy(rRecordSet);
	}
	
	if (iRet == PD_OK ) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {  
                                if (GetField_CString(hRec,"selected_pay_method",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:selected_pay_method= [%s]\n",csValue));
                                        PutField_CString(hRsp,"selected_pay_method",csValue);
                                }       
                                hRec = RecordSet_GetNext(rRecordSet);
                        }       
                }
                RecordSet_Destroy(rRecordSet);
        }            

	if (iRet == PD_OK ) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"tid",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:tid= [%s]\n",csValue));
                                        PutField_CString(hRsp,"tid",csValue);
                                }
                                if (GetField_CString(hRec,"fundin_date",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:fundin_date= [%s]\n",csValue));
                                        PutField_CString(hRsp,"fundin_date",csValue);
                                }
                                if (GetField_CString(hRec,"txn_date",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:txn_date= [%s]\n",csValue));
                                        PutField_CString(hRsp,"txn_date",csValue);
                                }
                                if (GetField_CString(hRec,"notice_status",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:notice_status= [%s]\n",csValue));
                                        PutField_CString(hRsp,"notice_status",csValue);
                                }
                                if (GetField_CString(hRec,"error_code",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:error_code= [%s]\n",csValue));
                                        PutField_CString(hRsp,"error_code",csValue);
                                }
                                if (GetField_CString(hRec,"convenience_store",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:convenience_store= [%s]\n",csValue));
                                        PutField_CString(hRsp,"conv_store",csValue);
                                }
                                if (GetField_CString(hRec,"bank_code",&csValue)) {
DEBUGLOG(("TxnCctByUsACK:bank_code= [%s]\n",csValue));
                                	if (!GetField_CString(hRec,"convenience_store",&csPtr)) {
                                        	PutField_CString(hRsp,"bank_code",csValue);
					}
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
        	RecordSet_Destroy(rRecordSet);
        }
        
	if (iRet == PD_OK) {
/* reformated txn_seq */
		PutField_CString(hRsp,"txn_seq",csNewTxnID);
DEBUGLOG(("TxnCctByUsACK:BUILD AckAuthData\n"));
		MsgObjPtr = CreateObj(MsgPtr,"WebMsg","BuildAckAuthData");
        	iRet = (unsigned long)(*MsgObjPtr)(hRsp);
	}

	if (iRet == PD_OK) {
/* Check Merchant Sign*/
               	BOObjPtr = CreateObj(BOPtr,"BOSecurity","GenerateMac");
               	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hRsp);
	}

	if (iRet == PD_OK) {
		sprintf(csTmpChannelCode,"WebMsg");
DEBUGLOG(("TxnCctByUsACK Calling [%s]->[FormatAckMsg]\n",csTmpChannelCode));
	 	MsgObjPtr = CreateObj(MsgPtr,csTmpChannelCode,"FormatAckMsg");
        	h_msg = (hex_t*) malloc (sizeof(hex_t));
        	if ((*MsgObjPtr)(hRsp,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("h_msg->len = [%d]\n",h_msg->len));
			lKey = GetMQKey((unsigned char*)"CCTACKQ");
       	         	msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                	msg->mtype  = 1;
                	memset(msg->mtext,0,sizeof(msg->mtext));
                        MQ_build_header((unsigned char*)msg->mtext,
                       		 MQ_RESP,
                        	"CCT",
				0,
				NULL,
				0);
                		memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                		msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));
                
                	iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
		}
		FREE_ME(h_msg);
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
	FREE_ME(hRsp);
	FREE_ME(csPtr);
        FREE_ME(csValue);

DEBUGLOG(("TxnCctByUsACK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
