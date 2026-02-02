/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/08              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsPOL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
void TxnWebOnUsPOL(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char*   csHandler;
	char*	csPspChannel;
	char*	csOrgTxnSeq;
	char*	csPspId;
	char*	csPtr;
	char	cPtr;
	char*	csSuccessCode;
	char	csPayMethod[4];
	int	iSkip = PD_FALSE;
	double	dTmp;
	hash_t  *hReq, *hRsp,*hRec,*hPsp;

	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	hReq = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hReq,0);
        hRsp = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRsp,0);

        hPsp = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hPsp,0);


	if (GetField_CString(hContext,"psp_id",&csPspId)) {
DEBUGLOG(("TxnWebOnUsPOL::psp_id = [%s]\n",csPspId));
	}

/* pay method */
/*
        if (GetField_CString(hRequest,"pay_method",&csPayMethod)) {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp- pay method = [%s]\n",csPayMethod));
        }
        else if (GetField_CString(hContext,"selected_pay_method",&csPayMethod)) {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp- pay method = [%s]\n",csPayMethod));
        }
        else
        {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp- pay_method not found\n"));
ERRLOG("TxnWebOnUsPOL: GetMerchatDetail- pay_method not found\n");
                iRet = INT_ERR;
        }
*/
	strcpy(csPayMethod,"010");

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
                if (!(*DBObjPtr)(csPspId, hPsp)) {
                	if (GetField_CString(hPsp,"psp_channel_code",&csPspChannel)) {
                        	PutField_CString(hContext,"psp_channel_code",csPspChannel);
                        	PutField_CString(hContext,"return_psp_channel",csPspChannel);
DEBUGLOG(("TxnWebOnUsPOL:GetPspDetail - psp_channel_code = [%s]\n",csPspChannel));
                        }
                        if (GetField_CString(hPsp,"psp_merchant_id",&csPtr)) {
                                PutField_CString(hContext,"psp_merchant_id",csPtr);
DEBUGLOG(("TxnWebOnUsPOL:GetPspDetail - psp_merchant_id = [%s]\n",csPtr));
                	}
			if (GetField_CString(hPsp,"status",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL:GetPspDetail - Status = [%s]\n",csPtr));
				if(strcmp(csPtr,PD_ACC_OPEN)){
DEBUGLOG(("TxnWebOnUsPOL:GetPspDetail psp account [%s] not opened\n",csPspId));
					iRet = INT_ACCOUNT_DISABLED;
				}
			}
             	}
                                        
		if (strcmp(csPspChannel,PD_CHANNEL_PGEN)) {
			iSkip = PD_TRUE;	
		}

		if (!iSkip) {
                	DBObjPtr = CreateObj(DBPtr,"DBPspKeys","GetPspKey");
                	if (!(*DBObjPtr)(csPspId,"PTK",rRecordSet)) {
                		hRec = RecordSet_GetFirst(rRecordSet);
                       		while(hRec){
                        		if (GetField_CString(hRec,"key_value",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPspByPspId - psp_key = [%s]\n",csPtr));
                       				PutField_CString(hContext,"psp_key",csPtr);
                        		}
                        		if (GetField_CString(hRec,"key_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPspByPspId - psp_key_id = [%s]\n",csPtr));
                       				PutField_CString(hContext,"psp_key_id",csPtr);
                        		}
                        		hRec = RecordSet_GetNext(rRecordSet);
                        	}
                	}
                	RecordSet_Destroy(rRecordSet);

                	/* Get PSP URL */
                	if (iRet == PD_OK) {
                 		DBObjPtr = CreateObj(DBPtr,"DBPspUrl","GetPspUrl");
                        	if (!(*DBObjPtr)(csPspId,hPsp)) {
                       			if (GetField_CString(hPsp,"url",&csPtr)) {
                                		PutField_CString(hContext,"psp_url",csPtr);
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp - psp_url = [%s]\n",csPtr));
                               		}
                                	else {
ERRLOG("TxnWebOnUsPOL: GetTxnPSP - no such for [%s]\n",csPspId);
                               			iRet = INT_ERR;
                                	}
                        	}
                	}

			/* Get PSP Reqest Txn URL */
		        if (iRet == PD_OK) {
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp - GetPspRequestTxnUrl\n"));
               			DBObjPtr = CreateObj(DBPtr,"DBPspRequestTxnUrl","GetPspRequestTxnUrl");
                		if (!(*DBObjPtr)(csPspId,PD_POLL_TXN_CODE,csPayMethod, hPsp)) {
                        		if (GetField_CString(hPsp,"request_function",&csPtr)) {
                                		PutField_CString(hContext,"request_function",csPtr);
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp - request_function = [%s]\n",csPtr));
                        		}
                        		else {
ERRLOG("TxnWebOnUsPOL: GetTxnPSP - no such function url for [%s] [%s]\n",csPspId,PD_POLL_TXN_CODE);
                                		iRet = INT_ERR;
                        		}
                        		if (GetField_CString(hPsp,"action",&csPtr)) {
                                		PutField_CString(hContext,"action",csPtr);
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp - action = [%s]\n",csPtr));
                        		}
                        
                        		if(GetField_CString(hPsp,"url_method",&csPtr)){
                                		PutField_CString(hContext,"url_method",csPtr); 
DEBUGLOG(("TxnWebOnUsPOL: GetTxnPsp - url_method = [%s]\n",csPtr));
                        		}               
                		}               
        		}                       

		}

      	}



/************************************************************************/

	if (iRet == PD_OK && !iSkip) {
/* try to put value */
		PutField_CString(hReq,"telegram_kind","091");

//		if (GetField_CString(hRequest,"txn_seq",&csPtr)) {
//DEBUGLOG(("TxnWebOnUsPOL::Authorize(): txn_seq = [%s]\n",csPtr));
//			PutField_CString(hReq,"order_num",csPtr);
//		}

/* psp merchant id */
        	if (GetField_CString(hContext,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize(): psp_merchant_id = [%s]\n",csPtr));
			PutField_CString(hReq,"psp_merchant_id",csPtr);
        	}
/* psp_url */
        	if (GetField_CString(hContext,"psp_url",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize(): psp_url = [%s]\n",csPtr));
       			PutField_CString(hReq,"psp_url",csPtr);
        	}

/* request_function */
	        if (GetField_CString(hContext,"request_function",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize(): request_function = [%s]\n",csPtr));
       		 	PutField_CString(hReq,"request_function",csPtr);
       	 	}

/* psp_key */
        	if (GetField_CString(hContext,"psp_key",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize(): psp_key = [%s]\n",csPtr));
       			PutField_CString(hReq,"psp_key",csPtr);
        	}

/* psp_id */
        	if (GetField_CString(hContext,"psp_key_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize(): psp_key_id = [%s]\n",csPtr));
       			PutField_CString(hReq,"psp_key_id",csPtr);
        	}

		if (GetField_CString(hContext,"psp_channel_code",&csPspChannel)) {
DEBUGLOG(("TxnWebOnUsPOL:: psp channel = [%s]\n",csPspChannel));
		}
		else {
DEBUGLOG(("TxnWebOnUsPOL:: psp channel = [%s]\n",csPspChannel));
		}


        	csHandler = (char*) malloc (20);
        	sprintf(csHandler,"TxnWebOnUs2%s",csPspChannel);
DEBUGLOG(("TxnWebOnUsPOL::Authorize() Txn Object [%s]\n",csHandler));
        	TxnObjPtr = CreateObj(TxnPtr,csHandler,"Authorize");
        	iRet = (unsigned long)(*TxnObjPtr)(hContext,hReq,hRsp);
DEBUGLOG(("TxnWebOnUsPOL::Authorize() Ret = [%d] fromTxn Object [%s]\n",iRet,csHandler));
       	        FREE_ME(csHandler);
	}


	if (iRet == PD_OK) {
		if (GetField_CString(hRsp,"success_code",&csSuccessCode)) {
			PutField_CString(hResponse,"success_code",csSuccessCode);
DEBUGLOG(("TxnWebOnUsPOL::Authorize() success_code = [%s]\n",csSuccessCode));
		}
		else {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() success_code is missing\n!!!\n"));
		}
	}

	if (iRet == PD_OK && !strcmp(csSuccessCode,PD_PGEN_SUCCESS) && !iSkip) {

		PutField_CString(hResponse,"status",csSuccessCode);
		GetField_CString(hRsp,"txn_seq",&csOrgTxnSeq);
/* get header */
DEBUGLOG(("TxnWebOnUsPOL::Authorize()org_txn_seq = [%s]\n",csOrgTxnSeq));
ERRLOG("Polled Success Txn  [%s]\n",csOrgTxnSeq);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()found record = [%s]\n",csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                        	if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()TXN CODE= [%s]\n",csPtr));
                        		PutField_CString(hContext,"txn_code",csPtr);
                        	}

                      		if (GetField_CString(hRec,"host_posting_date",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org Posting Date = [%s]\n",csPtr));
                                }
                                if (GetField_CString(hRec,"merchant_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org merchant id = [%s]\n",csPtr));
                               		PutField_CString(hContext,"org_merchant_id",csPtr);
                                }
                                if (GetField_CString(hRec,"client_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org client_id = [%s]\n",csPtr));
                                	PutField_CString(hContext,"org_client_id",csPtr);
                                }
                                if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org txn amt = [%lf]\n",dTmp));
                                	PutField_Double(hContext,"org_txn_amt",dTmp);
                                }
                                if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org net amt = [%lf]\n",dTmp));
                                	PutField_Double(hContext,"org_net_amt",dTmp);
                                        PutField_Double(hContext,"org_merchant_txn_amt",dTmp);
                                }
/* channel code */
                                if (GetField_CString(hRec,"channel_code",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org Channel Code = [%s]\n",csPtr));
                                	PutField_CString(hContext,"org_channel_code",csPtr);
                                }
/* service code */
                                if (GetField_CString(hRec,"service_code",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize()Org service code = [%s]\n",csPtr));
                                	PutField_CString(hContext,"org_service_code",csPtr);
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
             		}
          	}
                else {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() not found record for [%s]\n",csOrgTxnSeq));
                }
        	RecordSet_Destroy(rRecordSet);


/* get detail */
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() found record = [%s]\n",csOrgTxnSeq));
                	hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
/*org txn country */
                       		if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() Org txn country = [%s]\n",csPtr));
                               		PutField_CString(hContext,"org_txn_country",csPtr);
                               	}
/*org txn ccy */
                               	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() Org txn ccy = [%s]\n",csPtr));
                               		PutField_CString(hContext,"org_txn_ccy",csPtr);
                                }
/* pay_method */
                                if (GetField_CString(hRec,"pay_method",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() Org pay_method = [%s]\n",csPtr));
                                	PutField_CString(hContext,"org_pay_method",csPtr);
                                }

                                hRec = RecordSet_GetNext(rRecordSet);
                           }
                }
        	RecordSet_Destroy(rRecordSet);


/* get txn psp detail */
		DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if (!(*DBObjPtr)(csOrgTxnSeq,rRecordSet)) {
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while(hRec){
               			if (GetField_CString(hRec,"psp_id",&csPspId)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() GetTxnPsp - psp_id = [%s]\n",csPspId));
                       			PutField_CString(hContext,"org_psp_id",csPspId);
                        	}

                        	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() GetTxnPsp - psp_txn_ccy = [%s]\n",csPtr));
					PutField_CString(hContext,"org_dst_txn_ccy",csPtr);
                        	}

                        	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() GetTxnPsp - txn amt = [%lf]\n",dTmp));
                       			PutField_Double(hContext,"org_dst_net_amt",dTmp);
                        	}
                              
                        	hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else{   
ERRLOG("TxnWebOnUsPOL::Authorize()  PSP NOT FOUND\n");
DEBUGLOG(("hannel TxnWebOnUsPOL::Authorize()  PSP NOT FOUND\n"));
                }
        	RecordSet_Destroy(rRecordSet);
DEBUGLOG(("TxnWebOnUsPOL::Authorize()  call WEBChannel::UpdateRespTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr,"WEBChannel","UpdateRespTxnLog");
                iRet = (unsigned long)((*ChannelObjPtr)(hContext,hRsp,hRsp));
	}


	if (iRet == PD_OK && !iSkip) {
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnWebOnUsFEK org_txn_seq = [%s]\n",csOrgTxnSeq));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnWebOnUsFEK found record = [%s]\n",csOrgTxnSeq));
                 	hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"merchant_id",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() merchant_id= [%s]\n",csPtr));
                                        PutField_CString(hResponse,"merchant_id",csPtr);
                                }
                                if (GetField_CString(hRec,"merchant_ref",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() merchant_ref= [%s]\n",csPtr));
                                        PutField_CString(hResponse,"merchant_ref",csPtr);
                                }
                                if (GetField_CString(hRec,"channel_code",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() channel_code= [%s]\n",csPtr));
                                        PutField_CString(hResponse,"channel_code",csPtr);
                                }
                                if (GetField_Char(hRec,"status",&cPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() status= [%c]\n",cPtr));
                                        PutField_Char(hResponse,"status",cPtr);
                                }
                                if (GetField_Char(hRec,"ar_ind",&cPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() ar_ind= [%c]\n",cPtr));
                                        PutField_Char(hResponse,"ar_ind",cPtr);
                                }
                                if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("TxnWebOnUsPOL::Authorize() txn_code= [%s]\n",csPtr));
                                        PutField_CString(hContext,"txn_code",csPtr);
                                }
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
		}
        	RecordSet_Destroy(rRecordSet);
	}

DEBUGLOG(("TxnWebOnUsPOL() try to free\n"));

	hash_destroy(hReq);
        FREE_ME(hReq);

        hash_destroy(hRsp);
        FREE_ME(hRsp);

DEBUGLOG(("TxnWebOnUsPOL() exit = [%d]\n",iRet));
	return	iRet;
}
