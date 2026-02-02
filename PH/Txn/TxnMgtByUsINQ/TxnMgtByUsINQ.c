/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/05/18              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsINQ.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsINQ(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csOrgTxnSeq;
	char	*csPtr;
	double	dTmp;
	hash_t	*hRec;
	recordset_t     *rRecordSet;

	
	GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq);
DEBUGLOG(("Authorize::org txn seq = [%s]\n",csOrgTxnSeq));

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::found record = [%s]\n",csOrgTxnSeq));
        	hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {

                        if (GetField_CString(hRec,"host_posting_date",&csPtr)) {
DEBUGLOG(("Authorize::Org Posting Date = [%s]\n",csPtr));
				PutField_CString(hResponse,"host_posting_date",csPtr);
                        }
                        if (GetField_CString(hRec,"merchant_id",&csPtr)) {
DEBUGLOG(("Authorize::Org merchant id = [%s]\n",csPtr));
				PutField_CString(hResponse,"merchant_id",csPtr);
                        }
                        if (GetField_CString(hRec,"merchant_ref",&csPtr)) {
DEBUGLOG(("Authorize::Org merchant ref = [%s]\n",csPtr));
				PutField_CString(hResponse,"merchant_ref",csPtr);
                        }
                        if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize::Org txn ccy = [%s]\n",csPtr));
				PutField_CString(hResponse,"txn_ccy",csPtr);
                        }
                        if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("Authorize::Org txn amt = [%lf]\n",dTmp));
				PutField_Double(hResponse,"txn_amt",dTmp);
                        }

                        if (GetField_Double(hRec,"net_amt",&dTmp)) {
DEBUGLOG(("Authorize::Org net amt = [%lf]\n",dTmp));
				PutField_Double(hResponse,"net_amt",dTmp);
                        }
                        if (GetField_Double(hRec,"fee",&dTmp)) {
DEBUGLOG(("Authorize::org fee = [%lf]\n",dTmp));
				PutField_Double(hResponse,"fee",dTmp);
                        }

                        hRec = RecordSet_GetNext(rRecordSet);
		}
        }
        else {
DEBUGLOG(("Authorize:: not found record for [%s]\n",csOrgTxnSeq));
		iRet = INT_NOT_RECORD;
                PutField_Int(hContext,"internal_error",iRet);
	}
	RecordSet_Destroy(rRecordSet);

	if (iRet == PD_OK) {
        	recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
        	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::found record = [%s]\n",csOrgTxnSeq));
               		hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
                        	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize::org_txn_ccy = [%s]\n",csPtr));
					PutField_CString(hResponse,"txn_ccy",csPtr);
					PutField_CString(hResponse,"net_ccy",csPtr);
                        	}
                        	if (GetField_CString(hRec,"txn_country",&csPtr)) {
DEBUGLOG(("Authorize::org_txn_country = [%s]\n",csPtr));
					PutField_CString(hResponse,"txn_country",csPtr);
                        	}
                        	hRec = RecordSet_GetNext(rRecordSet);
                	}
        	}
        	else {
DEBUGLOG(("Authorize:: not found record for [%s]\n",csOrgTxnSeq));
               		iRet = INT_NOT_RECORD;
        	}
        	RecordSet_Destroy(rRecordSet);
                PutField_Int(hContext,"internal_error",iRet);
	}

	
        if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTxnPspDetail","GetTxnPspDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::found record = [%s]\n",csOrgTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"psp_id",&csPtr)) {
DEBUGLOG(("Authorize::org_psp_id = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"psp_id",csPtr);
                                }
                                if (GetField_CString(hRec,"tid",&csPtr)) {
DEBUGLOG(("Authorize::org_psp_tid = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"psp_tid",csPtr);
                                }
                                if (GetField_CString(hRec,"txn_date",&csPtr)) {
DEBUGLOG(("Authorize::org_psp_tid = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"psp_txn_date",csPtr);
                                }
                        	if (GetField_Double(hRec,"service_fee",&dTmp)) {
DEBUGLOG(("Authorize::service_fee = [%lf]\n",dTmp));
					PutField_Double(hResponse,"service_fee",dTmp);
                        	}
                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                }
                else {
DEBUGLOG(("Authorize:: not found record for [%s]\n",csOrgTxnSeq));
                        iRet = INT_NOT_RECORD;
                	PutField_Int(hContext,"internal_error",iRet);
                }
                RecordSet_Destroy(rRecordSet);
        }
        FREE_ME(rRecordSet);
DEBUGLOG(("TxnMgtByUsINQ Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
