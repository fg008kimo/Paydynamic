/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/08/06              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsAFX.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);


int UpdateAFXContext(hash_t* hContext,hash_t* hAFXContext);
int UpdateRecvContext(hash_t* hContext,hash_t* hAFXContext);
void TxnMmmByUsAFX(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csPtr;
	hash_t	*hAFXContext;
	hash_t	*hRcvContext;
	hash_t	*hData;
DEBUGLOG(("Authorize()\n"));

	hAFXContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hAFXContext,0);
	hRcvContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRcvContext,0);
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	UpdateAFXContext(hContext,hAFXContext);

	if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize() txn_ccy = [%s]\n",csPtr));
		PutField_CString(hData,"txn_ccy",csPtr);
		PutField_CString(hAFXContext,"txn_ccy",csPtr);
		PutField_CString(hAFXContext,"net_ccy",csPtr);
	}

/* ip_addr */
	if (GetField_CString(hRequest,"ip_addr",&csPtr)) {
DEBUGLOG(("Authorize() ip_addr = [%s]\n",csPtr));
		PutField_CString(hData,"ip_addr",csPtr);
	}

	PutField_CString(hAFXContext,"process_code",PD_PROCESS_CODE_DEF);
        PutField_CString(hAFXContext,"process_type",PD_PROCESS_TYPE_DEF);

	PutField_Int(hAFXContext,"db_commit",PD_FALSE);
DEBUGLOG(("Authorizeset db_commit to [%d]\n",PD_FALSE));

	BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
        iRet = (unsigned long)(BOObjPtr)(hAFXContext,hData);

	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","RemitTxn");
        	iRet = (unsigned long)(BOObjPtr)(hAFXContext,hData);
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
		PutField_Int(hAFXContext,"internal_error",iInternalErr);


		PutField_Char(hAFXContext,"ar_ind",PD_ACCEPT);
		PutField_Char(hAFXContext,"status",PD_COMPLETE);
		PutField_CString(hAFXContext,"sub_status",PD_COMPLETED);
		BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","UpdateTxnLog");
		iRet = (unsigned long)(BOObjPtr)(hAFXContext,hRequest,hRsp);
		FREE_ME(csBuf);
       	}

	if (iRet == PD_OK) {
		hash_t	*hRsp;
		hRsp = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(hRsp,0);

		UpdateAFXContext(hAFXContext,hRcvContext);
		BOObjPtr = CreateObj(BOPtr,"TxnMmmByUsRFM","Authorize");
        	iRet = (unsigned long)(BOObjPtr)(hRcvContext,hData,hRsp);
	
		FREE_ME(hRsp);
	}

	FREE_ME(hAFXContext);
	FREE_ME(hRcvContext);
	FREE_ME(hData);
DEBUGLOG(("TxnMmmByUsAFX Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int UpdateAFXContext(hash_t* hContext,hash_t* hAFXContext)
{
        int     iRet = PD_OK;
	int	iBalCnt = 0,i;
        char    *csPtr;
        char    csTxnSeq[PD_TXN_SEQ_LEN +1];
	char	csTag[PD_TAG_LEN +1];
	double	dTmp;
	double	dPercent;

DEBUGLOG(("UpdateAFXContext()\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hAFXContext,"txn_seq",csTxnSeq);
DEBUGLOG(("UpdateAFXContext() txn_seq = [%s]\n",csTxnSeq));

	PutField_CString(hAFXContext,"txn_code",PD_TXN_CODE_MMS_REMIT);
/* action_txn_seq */
        if (GetField_CString(hContext,"action_txn_seq",&csPtr)) {
                PutField_CString(hAFXContext,"action_txn_seq",csPtr);
DEBUGLOG(("UpdateAFXContext() action_txn_seq = [%s]\n",csPtr));
        }

/* entity_id */
        if (GetField_CString(hContext,"entity_id",&csPtr)) {
                PutField_CString(hAFXContext,"entity_id",csPtr);
                PutField_CString(hAFXContext,"dst.entity_id",csPtr);
DEBUGLOG(("UpdateAFXContext() entity_id = [%s]\n",csPtr));
        }

/* entity_type */
        if (GetField_CString(hContext,"entity_type",&csPtr)) {
                PutField_CString(hAFXContext,"entity_type",csPtr);
                PutField_CString(hAFXContext,"dst.entity_type",csPtr);
DEBUGLOG(("UpdateAFXContext() entity_type = [%s]\n",csPtr));
        }

/* channel_code */
        if (GetField_CString(hContext,"channel_code",&csPtr)) {
                PutField_CString(hAFXContext,"channel_code",csPtr);
DEBUGLOG(("UpdateAFXContext() channel_code = [%s]\n",csPtr));
        }

/* PHDATE */
        if (GetField_CString(hContext,"PHDATE",&csPtr)) {
                PutField_CString(hAFXContext,"PHDATE",csPtr);
DEBUGLOG(("UpdateAFXContext() PHDATE = [%s]\n",csPtr));
        }

/* local_tm_date */
        if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                PutField_CString(hAFXContext,"local_tm_date",csPtr);
DEBUGLOG(("UpdateAFXContext() local_tm_date = [%s]\n",csPtr));
        }

/* local_tm_time */
        if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                PutField_CString(hAFXContext,"local_tm_time",csPtr);
DEBUGLOG(("UpdateAFXContext() local_tm_time = [%s]\n",csPtr));
        }

/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
                PutField_CString(hAFXContext,"req_node_id",csPtr);
DEBUGLOG(("UpdateAFXContext() req_node_id = [%s]\n",csPtr));
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
                PutField_CString(hAFXContext,"node_ref",csPtr);
DEBUGLOG(("UpdateAFXContext() node_ref = [%s]\n",csPtr));
        }

/* transmission_datetime */
        if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
                PutField_CString(hAFXContext,"transmission_datetime",csPtr);
DEBUGLOG(("UpdateAFXContext() transmission_datetime = [%s]\n",csPtr));
        }

/* tm_date */
        if (GetField_CString(hContext,"tm_date",&csPtr)) {
                PutField_CString(hAFXContext,"tm_date",csPtr);
DEBUGLOG(("UpdateAFXContext() tm_date = [%s]\n",csPtr));
        }

/* tm_time */
        if (GetField_CString(hContext,"tm_time",&csPtr)) {
                PutField_CString(hAFXContext,"tm_time",csPtr);
DEBUGLOG(("UpdateAFXContext() tm_time = [%s]\n",csPtr));
        }

/* txn_amt */
        if (GetField_Double(hContext,"net_amt",&dTmp)) {
                PutField_Double(hAFXContext,"net_amt",dTmp);
                PutField_Double(hAFXContext,"remaining_amt",dTmp);
                PutField_Double(hAFXContext,"txn_amt",dTmp);
DEBUGLOG(("UpdateAFXContext() txn_amt = [%lf]\n",dTmp));
        }

	if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("UpdateAFXContext() BalCnt = [%d]\n",iBalCnt));
		PutField_Int(hAFXContext,"bal_cnt",iBalCnt);
        }


	for (i = 1; i <= iBalCnt; i ++) {
		sprintf(csTag,"bal.%d.sel_type",i);
		PutField_Char(hAFXContext,csTag,PD_MMS_SELECT_BAL);
DEBUGLOG(("UpdateAFXContext() %s = [%c]\n",csTag,PD_MMS_SELECT_BAL));

		sprintf(csTag,"bal.%d.nature_id",i);
		if (GetField_CString(hContext,csTag,&csPtr)) {
DEBUGLOG(("UpdateAFXContext() %s = [%s]\n",csTag,csPtr));
			PutField_CString(hAFXContext,csTag,csPtr);
		}
		sprintf(csTag,"bal.%d.percent",i);
                if (GetField_Double(hContext,csTag,&dPercent)) {
DEBUGLOG(("UpdateAFXContext() %s = [%lf]\n",csTag,dPercent));
			PutField_Double(hAFXContext,csTag,dPercent);
                }
		sprintf(csTag,"bal.%d.net_amt",i);
                if (GetField_Double(hContext,csTag,&dTmp)) {
DEBUGLOG(("UpdateAFXContext() %s = [%lf]\n",csTag,dTmp));
			sprintf(csTag,"bal.%d.amt",i);
			PutField_Double(hAFXContext,csTag,dTmp);
                }
	}

/* provided_fx_rate */
	if (GetField_Double(hContext,"provided_fx_rate",&dTmp)) {
		PutField_Double(hAFXContext,"provided_fx_rate",dTmp);
DEBUGLOG(("UpdateAFXContext() provided_fx_rate = [%lf]\n",dTmp));
	}
/* fx_rate */
	if (GetField_Double(hContext,"fx_rate",&dTmp)) {
		PutField_Double(hAFXContext,"fx_rate",dTmp);
DEBUGLOG(("UpdateAFXContext() fx_rate = [%lf]\n",dTmp));
	}

/* cl_amt */
	PutField_Double(hAFXContext,"cl_amt",0);
DEBUGLOG(("UpdateAFXContext() cl_amt = [%lf]\n",0));

/* cl_rate */
	PutField_Double(hAFXContext,"cl_rate",0);
DEBUGLOG(("UpdateAFXContext() cl_rate = [%lf]\n",0));

/* cl_flat_rate */
	PutField_Double(hAFXContext,"cl_flat_rate",0);
DEBUGLOG(("UpdateAFXContext() cl_flat_rate = [%lf]\n",0));

/* next_action_txn_ccy */
        if (GetField_CString(hContext,"next_action_ccy",&csPtr)) {
DEBUGLOG(("UpdateAFXContext() next_txn_ccy = [%s]\n",csPtr));
                PutField_CString(hAFXContext,"next_action_ccy",csPtr);
        }

/* relate txn id */
	if (GetField_CString(hContext,"txn_seq",&csPtr)) {
		PutField_CString(hAFXContext,"related_txn_id",csPtr);
	}
/* FX_TXN */
	PutField_Char(hAFXContext,"fx_txn",PD_YES);

DEBUGLOG(("UpdateAFXContext() Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}

int UpdateRcvContext(hash_t* hContext,hash_t* hRcvContext)
{
        int     iRet = PD_OK;
	int	iBalCnt = 0,i;
        char    *csPtr;
        char    csTxnSeq[PD_TXN_SEQ_LEN +1];
	char	csTag[PD_TAG_LEN +1];
	double	dTmp;
	double	dPercent;

DEBUGLOG(("UpdateRcvContext()\n"));

        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hRcvContext,"txn_seq",csTxnSeq);
DEBUGLOG(("UpdateRcvContext() txn_seq = [%s]\n",csTxnSeq));

	PutField_CString(hRcvContext,"txn_code",PD_TXN_CODE_MMS_RECV);
/* action_txn_seq */
        if (GetField_CString(hContext,"action_txn_seq",&csPtr)) {
                PutField_CString(hRcvContext,"action_txn_seq",csPtr);
DEBUGLOG(("UpdateRcvContext() action_txn_seq = [%s]\n",csPtr));
        }

/* entity_id */
        if (GetField_CString(hContext,"entity_id",&csPtr)) {
                PutField_CString(hRcvContext,"entity_id",csPtr);
                PutField_CString(hRcvContext,"dst.entity_id",csPtr);
DEBUGLOG(("UpdateRcvContext() entity_id = [%s]\n",csPtr));
        }

/* entity_type */
        if (GetField_CString(hContext,"entity_type",&csPtr)) {
                PutField_CString(hRcvContext,"entity_type",csPtr);
                PutField_CString(hRcvContext,"dst.entity_type",csPtr);
DEBUGLOG(("UpdateRcvContext() entity_type = [%s]\n",csPtr));
        }

/* channel_code */
        if (GetField_CString(hContext,"channel_code",&csPtr)) {
                PutField_CString(hRcvContext,"channel_code",csPtr);
DEBUGLOG(("UpdateRcvContext() channel_code = [%s]\n",csPtr));
        }

/* PHDATE */
        if (GetField_CString(hContext,"PHDATE",&csPtr)) {
                PutField_CString(hRcvContext,"PHDATE",csPtr);
DEBUGLOG(("UpdateRcvContext() PHDATE = [%s]\n",csPtr));
        }

/* local_tm_date */
        if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                PutField_CString(hRcvContext,"local_tm_date",csPtr);
DEBUGLOG(("UpdateRcvContext() local_tm_date = [%s]\n",csPtr));
        }

/* local_tm_time */
        if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                PutField_CString(hRcvContext,"local_tm_time",csPtr);
DEBUGLOG(("UpdateRcvContext() local_tm_time = [%s]\n",csPtr));
        }

/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
                PutField_CString(hRcvContext,"req_node_id",csPtr);
DEBUGLOG(("UpdateRcvContext() req_node_id = [%s]\n",csPtr));
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
                PutField_CString(hRcvContext,"node_ref",csPtr);
DEBUGLOG(("UpdateRcvContext() node_ref = [%s]\n",csPtr));
        }

/* transmission_datetime */
        if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
                PutField_CString(hRcvContext,"transmission_datetime",csPtr);
DEBUGLOG(("UpdateRcvContext() transmission_datetime = [%s]\n",csPtr));
        }

/* tm_date */
        if (GetField_CString(hContext,"tm_date",&csPtr)) {
                PutField_CString(hRcvContext,"tm_date",csPtr);
DEBUGLOG(("UpdateRcvContext() tm_date = [%s]\n",csPtr));
        }

/* tm_time */
        if (GetField_CString(hContext,"tm_time",&csPtr)) {
                PutField_CString(hRcvContext,"tm_time",csPtr);
DEBUGLOG(("UpdateRcvContext() tm_time = [%s]\n",csPtr));
        }

/* txn_amt */
        if (GetField_Double(hContext,"net_amt",&dTmp)) {
                PutField_Double(hRcvContext,"net_amt",dTmp);
                PutField_Double(hRcvContext,"remaining_amt",dTmp);
                PutField_Double(hRcvContext,"txn_amt",dTmp);
DEBUGLOG(("UpdateRcvContext() txn_amt = [%lf]\n",dTmp));
        }

	if (GetField_Int(hContext,"bal_cnt",&iBalCnt)) {
DEBUGLOG(("UpdateRcvContext() BalCnt = [%d]\n",iBalCnt));
		PutField_Int(hRcvContext,"bal_cnt",iBalCnt);
        }


	for (i = 1; i <= iBalCnt; i ++) {
		sprintf(csTag,"bal.%d.sel_type",i);
		PutField_Char(hRcvContext,csTag,PD_MMS_SELECT_BAL);
DEBUGLOG(("UpdateRcvContext() %s = [%c]\n",csTag,PD_MMS_SELECT_BAL));

		sprintf(csTag,"bal.%d.nature_id",i);
		if (GetField_CString(hContext,csTag,&csPtr)) {
DEBUGLOG(("UpdateRcvContext() %s = [%s]\n",csTag,csPtr));
			PutField_CString(hRcvContext,csTag,csPtr);
		}
		sprintf(csTag,"bal.%d.percent",i);
                if (GetField_Double(hContext,csTag,&dPercent)) {
DEBUGLOG(("UpdateRcvContext() %s = [%lf]\n",csTag,dPercent));
			PutField_Double(hRcvContext,csTag,dPercent);
                }
		sprintf(csTag,"bal.%d.net_amt",i);
                if (GetField_Double(hContext,csTag,&dTmp)) {
DEBUGLOG(("UpdateRcvContext() %s = [%lf]\n",csTag,dTmp));
			sprintf(csTag,"bal.%d.amt",i);
			PutField_Double(hRcvContext,csTag,dTmp);
                }
	}

/* provided_fx_rate */
	if (GetField_Double(hContext,"provided_fx_rate",&dTmp)) {
		PutField_Double(hRcvContext,"provided_fx_rate",dTmp);
DEBUGLOG(("UpdateRcvContext() provided_fx_rate = [%lf]\n",dTmp));
	}
/* fx_rate */
	if (GetField_Double(hContext,"fx_rate",&dTmp)) {
		PutField_Double(hRcvContext,"fx_rate",dTmp);
DEBUGLOG(("UpdateRcvContext() fx_rate = [%lf]\n",dTmp));
	}

/* cl_amt */
	PutField_Double(hRcvContext,"cl_amt",0);
DEBUGLOG(("UpdateRcvContext() cl_amt = [%lf]\n",0));

/* cl_rate */
	PutField_Double(hRcvContext,"cl_rate",0);
DEBUGLOG(("UpdateRcvContext() cl_rate = [%lf]\n",0));

/* cl_flat_rate */
	PutField_Double(hRcvContext,"cl_flat_rate",0);
DEBUGLOG(("UpdateRcvContext() cl_flat_rate = [%lf]\n",0));

/* relate txn id */
	if (GetField_CString(hContext,"txn_seq",&csPtr)) {
		PutField_CString(hRcvContext,"related_txn_id",csPtr);
	}

/* FX_TXN */
	PutField_Char(hRcvContext,"fx_txn",PD_YES);

DEBUGLOG(("UpdateRcvContext() Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}
