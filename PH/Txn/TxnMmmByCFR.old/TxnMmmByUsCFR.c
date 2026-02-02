/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/16              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsCFR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

int UpdateRecvContext(hash_t* hContext,hash_t* hRecvContext);

void TxnMmmByUsCFR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char    *csPtr;
        hash_t  *hRecvContext;
        hash_t  *hData;

DEBUGLOG(("Authorize()\n"));


        hRecvContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRecvContext,0);
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);


        iRet = UpdateRecvContext(hContext,hRecvContext);
DEBUGLOG(("Authorize iRet = [%d] from UpdateRecvContext\n",iRet));


        if (iRet == PD_OK) {

/* relate txn id */
                if (GetField_CString(hContext,"txn_seq",&csPtr)) {
                        PutField_CString(hRecvContext,"related_txn_id",csPtr);
                }
/* txn seq */
                if (GetField_CString(hRecvContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize txn_seq = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_id",csPtr);
                }

/* txn_country */
                if (GetField_CString(hRequest,"txn_country",&csPtr)) {
DEBUGLOG(("Authorize txn_country = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_country",csPtr);
                }

/* txn_ccy */
                if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize txn_ccy = [%s]\n",csPtr));
                        PutField_CString(hData,"txn_ccy",csPtr);
                        PutField_CString(hRecvContext,"net_ccy",csPtr);
                }



                PutField_CString(hRecvContext,"txn_code",PD_TXN_CODE_MMS_RECV);
                PutField_CString(hRecvContext,"process_code",PD_PROCESS_CODE_DEF);
                PutField_CString(hRecvContext,"process_type",PD_PROCESS_TYPE_DEF);

/* set db commit to false */
                PutField_Int(hRecvContext,"db_commit",PD_FALSE);
DEBUGLOG(("Authorize set db_commit to [%d]\n",PD_FALSE));

                BOObjPtr = CreateObj(BOPtr,"BOMMSTransaction","AddTxnLog");
                iRet = (unsigned long)(BOObjPtr)(hRecvContext,hRequest);
        }

        if (iRet == PD_OK) {
		double	dOpenBal = 0.0;
		double	dOpenIntransit = 0.0;
		double	dOpenPrepaid = 0.0;
		double	dOpenLien = 0.0;
                BOObjPtr = CreateObj(BOPtr,"BOMMSTxnEng","RemoveFromIntransitForRecv");
                iRet = (unsigned long)(BOObjPtr)(hRecvContext,hData);

		if (iRet == PD_OK) {
/*open_acct_bal */
			if (GetField_Double(hContext,"acct_bal",&dOpenBal)) {
DEBUGLOG(("Authorize() open_acct_bal = [%lf]\n",dOpenBal));
                        }

/*opening_prepaid */
                        if (GetField_Double(hContext,"prepaid",&dOpenPrepaid)) {
DEBUGLOG(("Authorize() open_prepaid = [%lf]\n",dOpenPrepaid));
                        }

/*opening_intransit */
                        if (GetField_Double(hContext,"intransit",&dOpenIntransit)) {
DEBUGLOG(("Authorize() open_intransit = [%lf]\n",dOpenIntransit));
                        }
/*opening_lien */
                        if (GetField_Double(hContext,"lien",&dOpenLien)) {
DEBUGLOG(("Authorize() open_lien = [%lf]\n",dOpenLien));
                        }
		}
        }

        FREE_ME(hRecvContext);
        FREE_ME(hData);


DEBUGLOG(("TxnMmmByUsCFR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}


int UpdateRecvContext(hash_t* hContext,hash_t* hRecvContext)
{
        int     iRet = PD_OK;
        int     iTxnCnt = 0,i;
        char    *csPtr;
	char	*csTxnCountry;
	char	*csTxnCcy;
        char    *csEntityId;
        double  dTmp,dTotalAmt = 0;
        double  dTxnAmt;
        char    csTxnSeq[PD_TXN_SEQ_LEN +1];
        char    csTag[PD_TAG_LEN +1];
        hash_t  *hRec;
        recordset_t     *rRecordSet;

DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext()\n"));
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmmTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hRecvContext,"txn_seq",csTxnSeq);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_seq = [%s]\n",csTxnSeq));

/* entity_id */
        if (GetField_CString(hContext,"entity_id",&csEntityId)) {
                PutField_CString(hRecvContext,"entity_id",csEntityId);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() entity_id = [%s]\n",csEntityId));
        }

/* entity_type */
        if (GetField_CString(hContext,"entity_type",&csPtr)) {
                PutField_CString(hRecvContext,"entity_type",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() entity_type = [%s]\n",csPtr));
        }


/* channel_code */
        if (GetField_CString(hContext,"channel_code",&csPtr)) {
                PutField_CString(hRecvContext,"channel_code",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() channel_code = [%s]\n",csPtr));
        }

/* PHDATE */
        if (GetField_CString(hContext,"PHDATE",&csPtr)) {
                PutField_CString(hRecvContext,"PHDATE",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() PHDATE = [%s]\n",csPtr));
        }

/* local_tm_date */
        if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
                PutField_CString(hRecvContext,"local_tm_date",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() local_tm_date = [%s]\n",csPtr));
        }

/* local_tm_time */
        if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
                PutField_CString(hRecvContext,"local_tm_time",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() local_tm_time = [%s]\n",csPtr));
        }

/* req_node_id */
        if (GetField_CString(hContext,"req_node_id",&csPtr)) {
                PutField_CString(hRecvContext,"req_node_id",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() req_node_id = [%s]\n",csPtr));
        }

/* node_ref */
        if (GetField_CString(hContext,"node_ref",&csPtr)) {
                PutField_CString(hRecvContext,"node_ref",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() node_ref = [%s]\n",csPtr));
        }

/* transmission_datetime */
        if (GetField_CString(hContext,"transmission_datetime",&csPtr)) {
                PutField_CString(hRecvContext,"transmission_datetime",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() transmission_datetime = [%s]\n",csPtr));
        }


/* tm_date */
        if (GetField_CString(hContext,"tm_date",&csPtr)) {
                PutField_CString(hRecvContext,"tm_date",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() tm_date = [%s]\n",csPtr));
        }

/* tm_time */
        if (GetField_CString(hContext,"tm_time",&csPtr)) {
                PutField_CString(hRecvContext,"tm_time",csPtr);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() tm_time = [%s]\n",csPtr));
        }

/* txn_amt */
        if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
                PutField_Double(hRecvContext,"txn_amt",dTxnAmt);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_amt = [%lf]\n",dTxnAmt));
        }

/* txn_ccy */
        if (GetField_CString(hContext,"txn_ccy",&csTxnCcy)) {
                PutField_CString(hRecvContext,"txn_ccy",csTxnCcy);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_ccy = [%s]\n",csTxnCcy));
        }

/* txn_country */
        if (GetField_CString(hContext,"txn_country",&csTxnCountry)) {
                PutField_CString(hRecvContext,"txn_country",csTxnCountry);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_country = [%s]\n",csTxnCountry));
        }

        if (GetField_Int(hContext,"txn_cnt",&iTxnCnt)) {
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_cnt = [%d]\n",iTxnCnt));
        }

        for (i = 0 ; i < iTxnCnt; i++) {
                sprintf(csTag,"tid.%d.txn_id",i+1);
                if (GetField_CString(hContext,csTag,&csPtr)) {
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() [%s] = [%s]\n",csTag,csPtr));
                        DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetTxnNatureDetail");
                        if (((unsigned long)(DBObjPtr)(csPtr,rRecordSet)) == PD_OK) {
                                hRec =  RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        if (GetField_Double(hRec,"txn_amt",&dTmp)) {
                                                dTotalAmt += dTmp;
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_amt = [%lf] [%lf]\n",dTmp,dTotalAmt));
                                        }
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
                        }
                        else {
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() Error Return from DBMmsTransaction:GetTxnNatureDetail\n"));
ERRLOG("BOMMSTxnEng:UpdateRecvContext() Error Return from DBMmsTransaction:GetTxnNatureDetail\n");
                                iRet = PD_ERR;
                                break;
                        }
                        if (iRet == PD_OK) {
				int j = 0;
                                double  dNatureTxnAmt = 0.0;
                                double  dRemainingAmt = dTxnAmt;
                                hRec =  RecordSet_GetFirst(rRecordSet);
                                while (hRec) {
                                        if (GetField_CString(hRec,"nature_id",&csPtr)) {
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() nature_id = [%s]\n",csPtr));
                                        }
                                        if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() txn_amt = [%lf]\n",dTmp));
                                        }
/* last record */
                                        if (i == (iTxnCnt -1 )) {
                                                dNatureTxnAmt = dRemainingAmt;
                                        }
                                        else {
                                                dNatureTxnAmt = dTxnAmt * (dTmp / dTotalAmt);
                                                dRemainingAmt -= dNatureTxnAmt;
                                        }
/* nature id */
					sprintf(csTag,"bal.%d.nature_id",j+1);
					PutField_Double(hRecvContext,csTag,dNatureTxnAmt);

					sprintf(csTag,"bal.%d.nature_txn_ccy",j+1);
					PutField_CString(hRecvContext,csTag,csTxnCcy);

					j++;
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() nature txn amt = [%lf]\n",dNatureTxnAmt));
                                        hRec = RecordSet_GetNext(rRecordSet);
                                }
				PutField_Int(hRecvContext,"bal_cnt",j);
                        }

                }
        }

        FREE_ME(rRecordSet);
DEBUGLOG(("BOMMSTxnEng:UpdateRecvContext() Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}

