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
#include "TxnMmmByUsPPY.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(DB);

int UpdatePrepaidContext(hash_t* hContext,hash_t* hPrepaidContext, hash_t *hOverpaidContext);

void TxnMmmByUsPPY(char    cdebug)
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
	double	dTxnAmt = 0.0;
	double	dRemainingAmt = 0.0;
	double	dPrecent = 0.0;
        char    csTag[PD_TAG_LEN +1];
        char    *csPtr;
        hash_t  *hPrepaidContext;
        hash_t  *hOverpaidContext;
        hash_t  *hData;

DEBUGLOG(("Authorize()\n"));

        hPrepaidContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hPrepaidContext,0);
        hOverpaidContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hOverpaidContext,0);
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);


        iRet = UpdatePrepaidContext(hContext,hPrepaidContext, hOverpaidContext);
DEBUGLOG(("Authorize iRet = [%d] from UpdatePrepaidContext\n",iRet));

        if (iRet == PD_OK) {

		if (GetField_Double(hPrepaidContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize txn_amt = [%lf]\n",dTxnAmt));
			dRemainingAmt = dTxnAmt;
		}
/* relate txn id */
                if (GetField_CString(hContext,"related_txn_id",&csPtr)) {
                        PutField_CString(hPrepaidContext,"related_txn_id",csPtr);
                }
/* txn seq */
                if (GetField_CString(hPrepaidContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize txn_seq = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_seq",csPtr);
                        PutField_CString(hOverpaidContext,"txn_seq",csPtr);
                }
/* entity_id */
                if (GetField_CString(hPrepaidContext,"entity_id",&csPtr)) {
DEBUGLOG(("Authorize entity_id = [%s]\n",csPtr));
                        PutField_CString(hData,"entity_id",csPtr);
                }
/* entity_type */
                if (GetField_CString(hPrepaidContext,"entity_type",&csPtr)) {
DEBUGLOG(("Authorize entity_type = [%s]\n",csPtr));
                        PutField_CString(hData,"entity_id",csPtr);
                }

/* txn_country */
                if (GetField_CString(hRequest,"txn_country",&csPtr)) {
DEBUGLOG(("Authorize txn_country = [%s]\n",csPtr));
                        PutField_CString(hData,"country",csPtr);
                }

/* txn_ccy */
                if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize txn_ccy = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_ccy",csPtr);
                        PutField_CString(hData,"ccy",csPtr);
                        PutField_CString(hPrepaidContext,"net_ccy",csPtr);
                }

/* ip_addr */
                if (GetField_CString(hRequest,"ip_addr",&csPtr)) {
DEBUGLOG(("Authorize ip_addr = [%s]\n",csPtr));
                        PutField_CString(hData,"ip_addr",csPtr);
                }

                PutField_CString(hPrepaidContext,"txn_code",PD_TXN_CODE_MMS_PREPAID);
                PutField_CString(hPrepaidContext,"process_code",PD_PROCESS_CODE_DEF);
                PutField_CString(hPrepaidContext,"process_type",PD_PROCESS_TYPE_DEF);

/* set db commit to false */
                PutField_Int(hPrepaidContext,"db_commit",PD_FALSE);
DEBUGLOG(("Authorizeset db_commit to [%d]\n",PD_FALSE));

                BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
                iRet = (unsigned long)(BOObjPtr)(hPrepaidContext,hRequest);
        }


        if (iRet == PD_OK) {

                if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
                        PutField_Int(hPrepaidContext,"bal_cnt",iBalCnt);
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
                                	PutField_CString(hPrepaidContext,csTag,csPtr);
                                	PutField_CString(hOverpaidContext,csTag,csPtr);
DEBUGLOG(("Authorize() [%s] = [%s]\n",csTag,csPtr));
                        	}

				sprintf(csTag,"bal.%d.sel_type",i+1);
				PutField_Char(hOverpaidContext,csTag,PD_MMS_SELECT_TXN);

                        	sprintf(csTag,"bal.%d.percent",i+1);
                        	if (GetField_Double(hContext,csTag,&dPrecent)) {
DEBUGLOG(("Authorize() [%s] = [%lf]\n",csTag,dPrecent));
					if (i == iBalCnt -1) {
						dTmp = dRemainingAmt;
					}
					else {
						dTmp = newround(dTxnAmt * dPrecent,PD_DECIMAL_LEN);
						dRemainingAmt -= dTmp;
					}
DEBUGLOG(("Authorize() nature txn amt  = [%lf]\n",dTmp));
                        	}

                        	sprintf(csTag,"bal.%d.amt",i+1);
                              	PutField_Double(hPrepaidContext,csTag,dTmp);
                              	PutField_Double(hOverpaidContext,csTag,dTmp);
DEBUGLOG(("Authorize() [%s] = [%lf]\n",csTag,dTmp));
                        	sprintf(csTag,"bal.%d.net_amt",i+1);
                              	PutField_Double(hPrepaidContext,csTag,dTmp);
                              	PutField_Double(hOverpaidContext,csTag,dTmp);
DEBUGLOG(("Authorize() [%s] = [%lf]\n",csTag,dTmp));
                	}

                	BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","CreditAcctBal");
                	iRet = (unsigned long)((BOObjPtr)(hPrepaidContext,hData));
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
                        PutField_Int(hPrepaidContext,"internal_error",iInternalErr);


                        PutField_Char(hPrepaidContext,"ar_ind",PD_ACCEPT);
                        PutField_Char(hPrepaidContext,"status",PD_COMPLETE);
                        PutField_CString(hPrepaidContext,"sub_status",PD_PENDING);
                        BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","UpdateTxnLog");
                        iRet = (unsigned long)(BOObjPtr)(hPrepaidContext,hRequest,hRsp);
                        FREE_ME(csBuf);
                }
        }

	if (iRet == PD_OK) {
/* create overpaid */
DEBUGLOG(("Authorize() call CreateOverpaid\n"));
               	BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","CreateOverpaid");
               	iRet = (unsigned long)((BOObjPtr)(hOverpaidContext,hData));
DEBUGLOG(("Authorize() call CreateOverpaid iRet = [%d]\n",iRet));

	}

	FREE_ME(hOverpaidContext);
        FREE_ME(hPrepaidContext);
        FREE_ME(hData);


DEBUGLOG(("TxnMmmByUsPPY Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int UpdatePrepaidContext(hash_t* hContext,hash_t* hPrepaidContext,hash_t* hOverpaidContext)
{
        int     iRet = PD_OK;
        char    *csPtr;
	char	*csRelatedTxnId;
        double  dTmp;
        char    csTxnSeq[PD_TXN_SEQ_LEN +1];

DEBUGLOG(("UpdatePrepaidContext()\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hPrepaidContext,"txn_seq",csTxnSeq);

        if (GetField_CString(hContext,"related_txn_id",&csRelatedTxnId)) {
DEBUGLOG(("UpdatePrepaidContext() related_txn_id = [%s]\n",csRelatedTxnId));
	}

/* action_txn_seq */
        if (GetField_CString(hContext,"action_txn_seq",&csPtr)) {
                PutField_CString(hPrepaidContext,"action_txn_seq",csPtr);
                PutField_CString(hOverpaidContext,"action_txn_seq",csPtr);
DEBUGLOG(("UpdatePrepaidContext() action_txn_seq = [%s]\n",csPtr));
        }
/* entity_id */
        if (GetField_CString(hContext,"entity_id",&csPtr)) {
                PutField_CString(hPrepaidContext,"entity_id",csPtr);
DEBUGLOG(("UpdatePrepaidContext() entity_id = [%s]\n",csPtr));
        }

/* entity_type */
        if (GetField_CString(hContext,"entity_type",&csPtr)) {
                PutField_CString(hPrepaidContext,"entity_type",csPtr);
DEBUGLOG(("UpdatePrepaidContext() entity_type = [%s]\n",csPtr));
        }

/* channel_code */
        if (GetField_CString(hContext,"channel_code",&csPtr)) {
                PutField_CString(hPrepaidContext,"channel_code",csPtr);
                PutField_CString(hOverpaidContext,"channel_code",csPtr);
DEBUGLOG(("UpdatePrepaidContext() channel_code = [%s]\n",csPtr));
        }

/* PHDATE */
        if (GetField_CString(hContext,"PHDATE",&csPtr)) {
                PutField_CString(hPrepaidContext,"PHDATE",csPtr);
                PutField_CString(hOverpaidContext,"PHDATE",csPtr);
DEBUGLOG(("UpdatePrepaidContext() PHDATE = [%s]\n",csPtr));
        }

/* local_tm_date */
        if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                PutField_CString(hPrepaidContext,"local_tm_date",csPtr);
                PutField_CString(hOverpaidContext,"local_tm_date",csPtr);
DEBUGLOG(("UpdatePrepaidContext() local_tm_date = [%s]\n",csPtr));
        }

/* local_tm_time */
        if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                PutField_CString(hPrepaidContext,"local_tm_time",csPtr);
                PutField_CString(hOverpaidContext,"local_tm_time",csPtr);
DEBUGLOG(("UpdatePrepaidContext() local_tm_time = [%s]\n",csPtr));
        }

/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
                PutField_CString(hPrepaidContext,"req_node_id",csPtr);
                PutField_CString(hOverpaidContext,"req_node_id",csPtr);
DEBUGLOG(("UpdatePrepaidContext() req_node_id = [%s]\n",csPtr));
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
                PutField_CString(hPrepaidContext,"node_ref",csPtr);
                PutField_CString(hOverpaidContext,"node_ref",csPtr);
DEBUGLOG(("UpdatePrepaidContext() node_ref = [%s]\n",csPtr));
        }

/* transmission_datetime */
        if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
                PutField_CString(hPrepaidContext,"transmission_datetime",csPtr);
                PutField_CString(hOverpaidContext,"transmission_datetime",csPtr);
DEBUGLOG(("UpdatePrepaidContext() transmission_datetime = [%s]\n",csPtr));
        }

/* tm_date */
        if (GetField_CString(hContext,"tm_date",&csPtr)) {
                PutField_CString(hPrepaidContext,"tm_date",csPtr);
                PutField_CString(hOverpaidContext,"tm_date",csPtr);
DEBUGLOG(("UpdatePrepaidContext() tm_date = [%s]\n",csPtr));
        }

/* tm_time */
        if (GetField_CString(hContext,"tm_time",&csPtr)) {
                PutField_CString(hPrepaidContext,"tm_time",csPtr);
                PutField_CString(hOverpaidContext,"tm_time",csPtr);
DEBUGLOG(("UpdatePrepaidContext() tm_time = [%s]\n",csPtr));
        }

/* txn_amt */
        if (GetField_Double(hContext,"amt_diff",&dTmp)) {
                PutField_Double(hPrepaidContext,"txn_amt",dTmp);
                PutField_Double(hPrepaidContext,"net_amt",dTmp);

                PutField_Double(hOverpaidContext,"txn_amt",dTmp);
                PutField_Double(hOverpaidContext,"net_amt",dTmp);
                PutField_Double(hOverpaidContext,"remaining_amt",dTmp);
DEBUGLOG(("UpdatePrepaidContext() txn_amt = [%lf]\n",dTmp));
	}

/* txn_ccy */
        if (GetField_CString(hContext,"txn_ccy",&csPtr)) {
                PutField_CString(hPrepaidContext,"txn_ccy",csPtr);
                PutField_CString(hOverpaidContext,"txn_ccy",csPtr);
DEBUGLOG(("UpdatePrepaidContext() txn_ccy = [%s]\n",csPtr));
        }
/* amt_reason */
        if (GetField_CString(hContext,"amt_reason",&csPtr)) {
                PutField_CString(hPrepaidContext,"override_element_type",csPtr);
DEBUGLOG(("UpdatePrepaidContext() override_element_type = [%s]\n",csPtr));
        }

	/* find related id of related id */
	hash_t*	hData;

        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);
	BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","GetTxnInfo");
        iRet = (unsigned long)(BOObjPtr)(csRelatedTxnId,hData);
	if (iRet == PD_OK) {
		if (GetField_CString(hData,"related_txn_id",&csRelatedTxnId)) {
DEBUGLOG(("UpdatePrepaidContext() related_txn_id = [%s] for overpaid txn\n",csRelatedTxnId));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("UpdatePrepaidContext() unable to related txn id for [%s]\n",csRelatedTxnId));
ERRLOG("UpdatePrepaidContext() unable to related txn id for [%s]\n",csRelatedTxnId);
		}
	}
	
	if (iRet == PD_OK) {
		PutField_CString(hOverpaidContext,"related_txn_id",csRelatedTxnId);
        	hash_init(hData,0);
		BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","GetTxnInfo");
        	iRet = (unsigned long)(BOObjPtr)(csRelatedTxnId,hData);

		if (iRet == PD_OK) {
			if (GetField_CString(hData,"entity_id",&csPtr)) {
DEBUGLOG(("UpdatePrepaidContext() dst.entity_id = [%s] for overpaid txn\n",csPtr));
				PutField_CString(hOverpaidContext,"dst.entity_id",csPtr);
			}
		}
	}

	FREE_ME(hData);
DEBUGLOG(("UpdatePrepaidContext() Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}

