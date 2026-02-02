/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/04              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPSI.h"
#include "myrecordset.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsPSI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	double	dTmp;
	char    *csRemarkTxnId;
	recordset_t     *rRecordSet;   
	hash_t	*hRec;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
DEBUGLOG(("Authorize()\n"));
	memset(csTxnSeq,0,PD_TXN_SEQ_LEN);

	if (GetField_CString(hRequest,"remarktxnid",&csRemarkTxnId)) {
DEBUGLOG(("Authorize::remarktxnid = [%s]\n",csRemarkTxnId));

        }
        else {
                iRet = INT_TXN_ID_MISSING;
                PutField_Int(hContext,"internal_error",iRet);
        }


	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxnByRemark");
                if ((unsigned long)(DBObjPtr)(csRemarkTxnId,PD_TO_PSP,csTxnSeq) != PD_FOUND) {
DEBUGLOG(("Authorize::txn for remarktxnid = [%s] not found\n",csRemarkTxnId));
	        	iRet = INT_TXN_ID_NOT_FOUND;    
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

/*
	 if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn detail found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_CString(hRec,"pay_method",&csPtr)) {
DEBUGLOG(("Authorize::GetTxnDetail - org_pay_method = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"pay_method",csPtr);
                                 }


                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        }

        RecordSet_Destroy(rRecordSet);
*/

	if (iRet == PD_OK) {
                recordset_init(rRecordSet,0);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("Authorize::txn Header found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("Authorize::GetTxnHeader - txn_amt = [%lf]\n",dTmp));
                                        PutField_Double(hResponse,"txn_amt",dTmp);
                                 }


                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
        	RecordSet_Destroy(rRecordSet);
        }
DEBUGLOG(("Authorize() normal exit = [%d]\n",iRet));
	return iRet;
}
