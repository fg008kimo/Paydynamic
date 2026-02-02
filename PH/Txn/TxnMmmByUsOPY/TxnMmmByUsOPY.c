/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/24              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsOPY.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

int UpdateOverpaidContext(hash_t* hContext,hash_t* hOverpaidContext);

void TxnMmmByUsOPY(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iBalCnt = 0,i;
        double  dTmp;
        char    csTag[PD_TAG_LEN +1];
        char    *csPtr;
        hash_t  *hOverpaidContext;
        hash_t  *hData;
	char	cCostCal = ' ';

DEBUGLOG(("Authorize()\n"));

        hOverpaidContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hOverpaidContext,0);
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	GetField_Char(hContext,"cost_cal",&cCostCal);

        iRet = UpdateOverpaidContext(hContext,hOverpaidContext);
DEBUGLOG(("Authorize iRet = [%d] from UpdateOverpaidContext\n",iRet));

        if (iRet == PD_OK) {

/* relate txn id */
                if (GetField_CString(hContext,"txn_seq",&csPtr)) {
                        PutField_CString(hOverpaidContext,"related_txn_id",csPtr);
                }
/* txn seq */
                if (GetField_CString(hOverpaidContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize txn_seq = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_seq",csPtr);
                }
/* entity_id */
                if (GetField_CString(hOverpaidContext,"entity_id",&csPtr)) {
DEBUGLOG(("Authorize entity_id = [%s]\n",csPtr));
                        PutField_CString(hData,"entity_id",csPtr);
                }

/* txn_ccy */
                if (GetField_CString(hOverpaidContext,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize txn_ccy = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_ccy",csPtr);
                        PutField_CString(hData,"ccy",csPtr);
                        PutField_CString(hOverpaidContext,"net_ccy",csPtr);
                }
/* ip_addr */
                if (GetField_CString(hRequest,"ip_addr",&csPtr)) {
DEBUGLOG(("Authorize ip_addr = [%s]\n",csPtr));
                        PutField_CString(hData,"ip_addr",csPtr);
                }

               	PutField_CString(hOverpaidContext,"txn_code",PD_TXN_CODE_MMS_OVERPAID);
                PutField_CString(hOverpaidContext,"process_code",PD_PROCESS_CODE_DEF);
                PutField_CString(hOverpaidContext,"process_type",PD_PROCESS_TYPE_DEF);

/* set db commit to false */
                PutField_Int(hOverpaidContext,"db_commit",PD_FALSE);
DEBUGLOG(("Authorizeset db_commit to [%d]\n",PD_FALSE));

                BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
                iRet = (unsigned long)(BOObjPtr)(hOverpaidContext,hRequest);
        }


        if (iRet == PD_OK) {

                if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
                        PutField_Int(hOverpaidContext,"bal_cnt",iBalCnt);
DEBUGLOG(("Authorize() bal_cnt = [%d]\n",iBalCnt));
                }
		else {
			iRet = PD_ERR;
DEBUGLOG(("Authorize() bal_cnt not found\n"));
ERRLOG("Authorize() bal_cnt not found\n");
		}
		if  (iRet == PD_OK) {
                	for (i = 0 ; i < iBalCnt; i++) {
                        	sprintf(csTag,"bal.%d.nature_id",i+1);
                        	if (GetField_CString(hContext,csTag,&csPtr)) {
                                	PutField_CString(hOverpaidContext,csTag,csPtr);
DEBUGLOG(("Authorize() [%s] = [%s]\n",csTag,csPtr));
                        	}

                                sprintf(csTag,"bal.%d.amt",i+1);
                                if (GetField_Double(hContext,csTag,&dTmp)) {
                        	        PutField_Double(hOverpaidContext,csTag,dTmp);
DEBUGLOG(("Authorize() [%s] = [%lf]\n",csTag,dTmp));
                                }
                	}

               		//BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","DebitAcctBal");
       		   	//iRet = (unsigned long)((BOObjPtr)(hOverpaidContext,hData));
DEBUGLOG(("Authorize iRet = [%d] from DebitAcctBal\n",iRet));
			if (iRet == PD_OK) {
               		//	BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","PutOpen");
       		   	//	iRet = (unsigned long)((BOObjPtr)(hOverpaidContext));

				PutField_CString(hOverpaidContext,"override_element_type",PD_ELEMENT_OVERPAID);
               			BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","CreditPrepaid");
       		   		iRet = (unsigned long)((BOObjPtr)(hOverpaidContext,hData));
DEBUGLOG(("Authorize iRet = [%d] from CreditPrepaid\n",iRet));
               	//		BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","GetOpen");
       		 //  		iRet = (unsigned long)((BOObjPtr)(hOverpaidContext));
			}

		}

                if (iRet == PD_OK) {
                        int     iInternalErr = 0;
                        char    *csBuf;
                        csBuf = (char*) malloc (PD_TMP_BUF_LEN +1);

                        hash_t  *hRsp;
                        hRsp = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(hRsp,0);

                        sprintf(csBuf,"%d",iInternalErr);
                        PutField_CString(hRsp,"response_code",csBuf);
                        PutField_Int(hOverpaidContext,"internal_error",iInternalErr);


                        PutField_Char(hOverpaidContext,"ar_ind",PD_ACCEPT);
                        PutField_Char(hOverpaidContext,"status",PD_COMPLETE);
                        PutField_CString(hOverpaidContext,"sub_status",PD_PENDING);
                        BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","UpdateTxnLog");
                        iRet = (unsigned long)(BOObjPtr)(hOverpaidContext,hRequest,hRsp);
                        FREE_ME(csBuf);
                }
        }

        FREE_ME(hOverpaidContext);
        FREE_ME(hData);


DEBUGLOG(("TxnMmmByUsOPY Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int UpdateOverpaidContext(hash_t* hContext,hash_t* hOverpaidContext)
{
        int     iRet = PD_OK;
        char    *csPtr;
        double  dTmp;
        char    csTxnSeq[PD_TXN_SEQ_LEN +1];

DEBUGLOG(("UpdateOverpaidContext()\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hOverpaidContext,"txn_seq",csTxnSeq);
DEBUGLOG(("UpdateOverpaidContext() txn_seq = [%s]\n",csTxnSeq));

/* action_txn_seq */
        if (GetField_CString(hContext,"action_txn_seq",&csPtr)) {
                PutField_CString(hOverpaidContext,"action_txn_seq",csPtr);
DEBUGLOG(("UpdateOverpaidContext() action_txn_seq = [%s]\n",csPtr));
        }
/* entity_id */
        if (GetField_CString(hContext,"dst.entity_id",&csPtr)) {
                PutField_CString(hOverpaidContext,"entity_id",csPtr);
DEBUGLOG(("UpdateOverpaidContext() entity_id = [%s]\n",csPtr));
        }


/* channel_code */
        if (GetField_CString(hContext,"channel_code",&csPtr)) {
                PutField_CString(hOverpaidContext,"channel_code",csPtr);
DEBUGLOG(("UpdateOverpaidContext() channel_code = [%s]\n",csPtr));
        }

/* PHDATE */
        if (GetField_CString(hContext,"PHDATE",&csPtr)) {
                PutField_CString(hOverpaidContext,"PHDATE",csPtr);
DEBUGLOG(("UpdateOverpaidContext() PHDATE = [%s]\n",csPtr));
        }

/* local_tm_date */
        if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                PutField_CString(hOverpaidContext,"local_tm_date",csPtr);
DEBUGLOG(("UpdateOverpaidContext() local_tm_date = [%s]\n",csPtr));
        }

/* local_tm_time */
        if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                PutField_CString(hOverpaidContext,"local_tm_time",csPtr);
DEBUGLOG(("UpdateOverpaidContext() local_tm_time = [%s]\n",csPtr));
        }

/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
                PutField_CString(hOverpaidContext,"req_node_id",csPtr);
DEBUGLOG(("UpdateOverpaidContext() req_node_id = [%s]\n",csPtr));
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
                PutField_CString(hOverpaidContext,"node_ref",csPtr);
DEBUGLOG(("UpdateOverpaidContext() node_ref = [%s]\n",csPtr));
        }

/* transmission_datetime */
        if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
                PutField_CString(hOverpaidContext,"transmission_datetime",csPtr);
DEBUGLOG(("UpdateOverpaidContext() transmission_datetime = [%s]\n",csPtr));
        }

/* tm_date */
        if (GetField_CString(hContext,"tm_date",&csPtr)) {
                PutField_CString(hOverpaidContext,"tm_date",csPtr);
DEBUGLOG(("UpdateOverpaidContext() tm_date = [%s]\n",csPtr));
        }

/* tm_time */
        if (GetField_CString(hContext,"tm_time",&csPtr)) {
                PutField_CString(hOverpaidContext,"tm_time",csPtr);
DEBUGLOG(("UpdateOverpaidContext() tm_time = [%s]\n",csPtr));
        }

/* txn_amt */
        if (GetField_Double(hContext,"txn_amt",&dTmp)) {
                PutField_Double(hOverpaidContext,"net_amt",dTmp);
                PutField_Double(hOverpaidContext,"remaining_amt",dTmp);
                PutField_Double(hOverpaidContext,"txn_amt",dTmp);
DEBUGLOG(("UpdateOverpaidContext() txn_amt = [%lf]\n",dTmp));
        }

/* txn_ccy */
        if (GetField_CString(hContext,"txn_ccy",&csPtr)) {
                PutField_CString(hOverpaidContext,"txn_ccy",csPtr);
DEBUGLOG(("UpdateOverpaidContext() txn_ccy = [%s]\n",csPtr));
        }

DEBUGLOG(("UpdateOverpaidContext() Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}
