/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/09              Cody Chan
Separate Get Online and Offline Txn Info	   2015/08/12		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsSF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Msg);

int Send2Host(const hash_t* hData);
int GetTxnInfo(const char* csTxnId, hash_t* hData);
int GetOLTxnInfo(const char* csTxnId, hash_t* hData);

void TxnMmcByUsSF(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	recordset_t     *rRecordSet;
	hash_t		*hRec;
	char	cMode;

DEBUGLOG(("Authorize()\n"));
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	if (GetField_Char(hRequest,"mode",&cMode)) {
DEBUGLOG(("Authorize() mode [%c]\n",cMode));

		if (cMode == PD_MMS_SERVER )  {
DEBUGLOG(("Authorize() try to get pending SF record(s)\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsStoreForward","GetPendingSF");
			iRet = (unsigned long)(*DBObjPtr)(PD_MMS_SERVER,rRecordSet);
DEBUGLOG(("Authorize iRet = [%d] return from MmsStoreForward GetPendingSF\n",iRet));
			if (iRet == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {	
					iRet = Send2Host(hRec);
					if (iRet != PD_OK) {
						break;
					}
					hRec = RecordSet_GetNext(rRecordSet);
				}
			}
		}
		else {
DEBUGLOG(("Authorize mode error!!! should not be [%c]\n",cMode));
ERRLOG("TxnMmcByUsSF::Authorize mode error!!! should not be [%c]\n",cMode);
		}
	}
	else {
DEBUGLOG(("Authorize() unable to find mode\n"));
	}

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
DEBUGLOG(("TxnMmcByUsSF Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int Send2Host(const hash_t* hData)
{
	int	iRet = PD_OK;

	char    *csMyReqQ,*csMyRspQ,*csNodeKey, *csEncType, *csTxnId, *csNodeId;
	hash_t  *hContext, *hReq;

	hex_t   *h_msg;
        long    lKey;
        struct msg_t* msg;

DEBUGLOG(("Send2Host()\n"));

	hContext = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hContext,0);

	hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);

/* process code */
	PutField_CString(hReq,"process_code",PD_PROCESS_CODE_MMX_STT);

/* process type */
	PutField_CString(hReq,"process_type",PD_PROCESS_TYPE_FIN);

/* node_id */
     	if (GetField_CString(hData,"node_id",&csNodeId)) {
DEBUGLOG(("Send2Host() Authorize node_id = [%s]\n",csNodeId));
           	//PutField_CString(hContext,"node_id",csNodeId);
           	PutField_CString(hReq,"req_node_id",csNodeId);
       	}
        else {
DEBUGLOG(("Send2Host()  node_id not found\n"));
ERRLOG("TxnMmcByUsSF::Send2Host() node_id not found\n");
                        iRet = PD_ERR;
       	}

/* baid */
	if (iRet == PD_OK) {
		PutField_CString(hReq,"baid",PD_MMS_DEFAULT_BAID);

		ChannelObjPtr = CreateObj(ChannelPtr,"MMCChannel","UpdateContext");
        	if ((unsigned long)(*ChannelObjPtr)(hContext) == PD_OK) {

        	}
		else {
DEBUGLOG(("Send2Host() UpdateContext Error\n"));
ERRLOG("TxnMmsByUsSF:Send2Host() UpdateContext Error\n");
			iRet = PD_ERR;
		}
	}	

	if (iRet == PD_OK) {
/* txn_id */
                if (GetField_CString(hData,"txn_id",&csTxnId)) {
DEBUGLOG(("Send2Host() Authorize txn_id = [%s]\n",csTxnId));
			PutField_CString(hReq,"node_ref",csTxnId);
                }
                else {
DEBUGLOG(("Send2Host()  txn_id not found\n"));
ERRLOG("TxnMmcByUsSF::Send2Host() txn_id not found\n");
                        iRet = PD_ERR;
                }

	/* Get Request Queue */

	/* Get Request Queue */
                if (GetField_CString(hContext,"request_queue_name",&csMyReqQ)) {
DEBUGLOG(("Send2Host() Authorize request_queue_name = [%s]\n",csMyReqQ));
                }
                else {
ERRLOG("TxnMmcByUsSF::Send2Host() Request Q not found\n");
                        iRet = PD_ERR;
                }

/* Get Response Queue */
                if (GetField_CString(hContext,"response_queue_name",&csMyRspQ)) {
DEBUGLOG(("Send2Host() Authorize response_queue_name = [%s]\n",csMyRspQ));
                }
                else {
ERRLOG("TxnMmcByUsSF::Send2Host() Response Q not found\n");
                        iRet = PD_ERR;
                }

		if (GetField_CString(hContext,"mms_key",&csNodeKey)) {
DEBUGLOG(("Send2Host() Authorize mms key = [%s]\n",csNodeKey));
		}
               	else {
DEBUGLOG(("Send2Host() Authorize mms key not found\n"));
ERRLOG("TxnMmcByUsSync::Send2Host() Authorize mms key not found\n");
               		iRet = PD_ERR;
               	}

/* enc type */
		if (GetField_CString(hContext,"enctype",&csEncType)) {
DEBUGLOG(("Send2Host() Authorize enctype = [%s]\n",csEncType));
			PutField_CString(hReq,"enctype",csEncType);
		}
               	else {
DEBUGLOG(("Send2Host() Authorize enctype not found\n"));
ERRLOG("TxnMmcByUsSync::Send2Host() enctype not found\n");
               		iRet = PD_ERR;
               	}
	}
	
	if (iRet == PD_OK) {
/* Get Txn/OLTxn Info */
		if (!strcmp(csNodeId,PD_MMS_NODE_ID_ONLINE)) {	
			GetTxnInfo(csTxnId,hReq);
		} else if (!strcmp(csNodeId,PD_MMS_NODE_ID_OFFLINE)) {
			GetOLTxnInfo(csTxnId,hReq);
		}
	}

	if (iRet == PD_OK) {
		MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","BuildAuthData");
                iRet = (unsigned long) (*MsgObjPtr)(hReq);
		if (iRet != PD_OK) {
DEBUGLOG(("Send2Host() BuildAuthData Error\n"));
ERRLOG("TxnMmcByUsSync::Send2Host() BuildAuthData Error\n");
		}
	}

	if (iRet == PD_OK )  {
		char    csTmpFunc[PD_TMP_BUF_LEN  +1];
                char    *csMac;
                char    *csData;
                csMac = (char*) malloc (PD_TMP_MSG_BUF_LEN  +1);

                GetField_CString(hReq,"auth_data",&csData);
DEBUGLOG(("Authorize auth data = [%s]\n",csData));

                if (!strcmp(csEncType,PD_ENC_TYPE_MD5))
               		strcpy(csTmpFunc,"GenerateMD5Mac");
                else if (!strcmp(csEncType,PD_ENC_TYPE_MD5))
                        strcpy(csTmpFunc,"GenerateSHA1Mac");
                BOObjPtr = CreateObj(BOPtr,"BOSecurity", csTmpFunc);
                iRet = (unsigned long) (*BOObjPtr)(csNodeKey,csData,strlen(csData),csMac);
                if (iRet == PD_OK) {
                	PutField_CString(hReq,"mac",csMac);
DEBUGLOG(("Authorize MAC = [%s]\n",csMac));
                }
                FREE_ME(csMac);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMmcByUsSF Calling MmcMsg->[FormatMsg]\n"));
		MsgObjPtr = CreateObj(MsgPtr,"MmcMsg","FormatMsg");
                h_msg = (hex_t*) malloc (sizeof(hex_t));
                if ((*MsgObjPtr)(hReq,h_msg->msg,&h_msg->len) == PD_OK) {
DEBUGLOG(("h_ms->len = [%d]\n",h_msg->len));
                lKey = GetMQKey((unsigned char*)csMyReqQ);
DEBUGLOG(("REQ Q = [%s] RSP Q = [%s]\n",csMyReqQ,csMyRspQ));
                msg = (struct msg_t*)malloc(sizeof(struct msg_t)+MAX_MSG_SIZE);
                msg->mtype  = 1;
                memset(msg->mtext,0,sizeof(msg->mtext));
                MQ_build_header((unsigned char*)msg->mtext,
                	MQ_REQ,
                        "MMC",
			0,
                        csMyRspQ,
                	lKey);
                memcpy(&msg->mtext[MQ_HEADER_LEN],h_msg->msg,h_msg->len);
                msg->mtext[MQ_HEADER_LEN + h_msg->len] = '\0';
DEBUGLOG(("send len = [%d]\n",MQ_HEADER_LEN + h_msg->len));

			/* The Response will be handle by the Channel and Gateway */
                	iRet = MQSend(lKey,msg,MQ_HEADER_LEN + h_msg->len);
                }
		else {
DEBUGLOG(("FormatMsg Error\n"));
ERRLOG("TxnMmcByUsSF::FormatMsg Error\n");
			iRet = INT_FORMAT_ERR;
		}
                FREE_ME(h_msg);
	}


        FREE_ME(hContext);	

	hash_destroy(hReq);
        FREE_ME(hReq);	

	FREE_ME(h_msg);
DEBUGLOG(("Send2Host() normal Return iRet = [%d]\n",iRet));
	return iRet;

}

int GetTxnInfo(const char* csTxnId, hash_t* hData)
{
        int     iRet = PD_OK;

        double  dTmp = 0.0;

       	char    *csPspId = NULL;
       	char    *csPtr = NULL;

       	hash_t  *hRec = NULL;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("GetTxnInfo()\n"));

	// Get Txn Header
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo Call GetTxnHeader\n"));
      		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        	iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
		if (iRet == PD_OK) {
                        
			hRec = RecordSet_GetFirst(rRecordSet);
               		while (hRec) {

/* txn amt */
                		if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("GetTxnInfo Txn Amt = [%lf]\n",dTmp));
                          		PutField_Double(hData,"txn_amt",dTmp);
                     		}

/* txn code */
                   		if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("GetTxnInfo Node Txn Code = [%s]\n",csPtr));
                        	     	PutField_CString(hData,"node_txn_code",csPtr);
                      		}

/* txn date */
                     		if (GetField_CString(hRec,"transmission_datetime",&csPtr)) {
DEBUGLOG(("GetTxnInfo Node Txn Date = [%s]\n",csPtr));
                        	  	PutField_CString(hData,"node_txn_date",csPtr);
                    		}

/* approval date */
                     		if (GetField_CString(hRec,"approval_date",&csPtr)) {
DEBUGLOG(("GetTxnInfo Approval Date = [%s]\n",csPtr));
                        	     	PutField_CString(hData,"node_approval_date",csPtr);
                       		}

                     		hRec = RecordSet_GetNext(rRecordSet);
               		}
     		}

		RecordSet_Destroy(rRecordSet);
	}

	// Get Txn Psp Detail
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
		
DEBUGLOG(("GetTxnInfo Call GetTxnPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
		if (iRet == PD_OK) {
		
			hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

/* psp id */
				if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("GetTxnInfo psp_id = [%s]\n",csPspId));
        	                     	PutField_CString(hData,"psp_id",csPspId);
                	        }	
			
/* txn ccy */
				if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("GetTxnInfo txn_ccy = [%s]\n",csPtr));
                                        PutField_CString(hData,"txn_ccy",csPtr);
                                }

                     		hRec = RecordSet_GetNext(rRecordSet);
			}
		}

		RecordSet_Destroy(rRecordSet);
        }

	// Get Txn Detail
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo Call GetTxnDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
                if (iRet == PD_OK) {

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

/* txn_country */
                                if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("GetTxnInfo txn_country = [%s]\n",csPtr));
                                        PutField_CString(hData,"txn_country",csPtr);
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }

                RecordSet_Destroy(rRecordSet);
        } 

	// Get Psp Detail
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo Call GetPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
                iRet = (unsigned long)(*DBObjPtr)(csPspId,hData);
		if (iRet == PD_OK) {

/* client id */
			if (GetField_CString(hData,"psp_client_id",&csPtr)) {
DEBUGLOG(("GetTxnInfo client_id = [%s]\n",csPtr));
                                PutField_CString(hData,"client_id",csPtr);
                        }
		} else {
DEBUGLOG(("GetTxnInfo:internal error select psp detail\n"));
ERRLOG("TxnMmcByUsSF:GetTxnInfo() internal error select psp detail\n");
                    	iRet = PD_ERR;
                }

		RecordSet_Destroy(rRecordSet);
	}

	FREE_ME(rRecordSet);

DEBUGLOG(("GetTxnInfo() normal Return iRet = [%d]\n",iRet));
        return iRet;
}

int GetOLTxnInfo(const char* csTxnId, hash_t* hData)
{
        int     iRet = PD_OK;

        double  dTmp = 0.0;

       	char    *csPspId = NULL;
       	char    *csPtr = NULL;

        hash_t  *hReq;
	hReq = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hReq,0);

       	hash_t  *hRec = NULL;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

DEBUGLOG(("GetOLTxnInfo()\n"));

	// Get OL Txn Header
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetOLTxnInfo Call GetOLTxnHeader\n"));
      		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
        	iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
		if (iRet == PD_OK) {
                        
			hRec = RecordSet_GetFirst(rRecordSet);
               		while (hRec) {

/* txn amt */
                		if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("GetOLTxnInfo Txn Amt = [%lf]\n",dTmp));
                          		PutField_Double(hData,"txn_amt",dTmp);
                     		}

/* txn code */
                   		if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo Node Txn Code = [%s]\n",csPtr));
                        	     	PutField_CString(hData,"node_txn_code",csPtr);
                      		}

/* txn date */
                     		if (GetField_CString(hRec,"transmission_datetime",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo Node Txn Date = [%s]\n",csPtr));
                        	  	PutField_CString(hData,"node_txn_date",csPtr);
                    		}

/* approval date */
                     		if (GetField_CString(hRec,"approval_date",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo Approval Date = [%s]\n",csPtr));
                        	     	PutField_CString(hData,"node_approval_date",csPtr);
                       		}

                     		hRec = RecordSet_GetNext(rRecordSet);
               		}
     		}

		RecordSet_Destroy(rRecordSet);
	}

	// Get OL Txn Psp Detail
	if (iRet == PD_OK) {
		
DEBUGLOG(("GetOLTxnInfo Call GetOLTxnPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","GetTxnPspDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId,hReq);
		if (iRet == PD_OK) {
		
/* psp id */
			if (GetField_CString(hReq,"psp_id",&csPspId)) {
DEBUGLOG(("GetOLTxnInfo psp_id = [%s]\n",csPspId));
        	                PutField_CString(hData,"psp_id",csPspId);
               		}	
		
/* baid */
                        if (GetField_CString(hReq,"baid",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo baid = [%s]\n",csPtr));
                                PutField_CString(hData,"baid",csPtr);
                        }
	
/* txn ccy */
			if (GetField_CString(hReq,"txn_ccy",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo txn_ccy = [%s]\n",csPtr));
                                PutField_CString(hData,"txn_ccy",csPtr);
                      	}
		}
        }

	// Get OL Txn Detail
	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);

DEBUGLOG(("GetOLTxnInfo Call GetOLTxnDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
                iRet = (unsigned long)(*DBObjPtr)(csTxnId,rRecordSet);
                if (iRet == PD_OK) {

                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {

/* txn_country */
                                if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo txn_country = [%s]\n",csPtr));
                                        PutField_CString(hData,"txn_country",csPtr);
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }

                RecordSet_Destroy(rRecordSet);
        } 

	// Get OL Psp Detail
	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetOLTxnInfo Call GetOLPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLPspDetail","GetPspDetail");
                iRet = (unsigned long)(*DBObjPtr)(csPspId,hData);
		if (iRet == PD_OK) {

/* client id */
			if (GetField_CString(hData,"client_id",&csPtr)) {
DEBUGLOG(("GetOLTxnInfo client_id = [%s]\n",csPtr));
                                PutField_CString(hData,"client_id",csPtr);
                        }
		} else {
DEBUGLOG(("GetOLTxnInfo:internal error select psp detail\n"));
ERRLOG("TxnMmcByUsSF:GetOLTxnInfo() internal error select psp detail\n");
                    	iRet = PD_ERR;
                }

		RecordSet_Destroy(rRecordSet);
	}

        hash_destroy(hReq);
        FREE_ME(hReq);

	FREE_ME(rRecordSet);

DEBUGLOG(("GetOLTxnInfo() normal Return iRet = [%d]\n",iRet));
        return iRet;
}

