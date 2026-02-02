/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/23              LoKMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUsSRV.h"
#include "myrecordset.h"
#include "dbutility.h"

char cDebug;
#define	PD_MAX_TRY	5

OBJPTR(DB);
void TxnMmsByUsSRV(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csCmd[PD_MAX_FILE_LEN + 1];

	char    *csValue;
	char    *csDtlTxnId;
	hash_t	*hRec;
	hash_t  *hReverse;

        hReverse = (hash_t*) malloc (sizeof(hash_t));	
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBMmsReverseRetry","GetPendingReverse");
        if ((*DBObjPtr)(PD_MAX_TRY,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"txn_id",&csValue) && GetField_CString(hRec,"dtl_txn_id",&csDtlTxnId)) {
				hash_init(hReverse,0);
				PutField_Char(hReverse,"status",PD_COMPLETE);
				PutField_CString(hReverse,"txn_seq",csValue);
				PutField_CString(hReverse,"dtl_txn_seq",csDtlTxnId);
DEBUGLOG(("TxnMmsByUsSRV txn_id = [%s]\n",csValue));
DEBUGLOG(("TxnMmsByUsSRV dtl_txn_id = [%s]\n",csDtlTxnId));
				DBObjPtr = CreateObj(DBPtr,"DBMmsReverseRetry","Update");

				if ((*DBObjPtr)(hReverse) == PD_OK) {
					TxnCommit();
					sprintf(csCmd,"resend_mms_reverse.sh %s %s",csValue,csDtlTxnId);
DEBUGLOG(("TxnMmsByUsSRV cmd = [%s]\n",csCmd));
					system(csCmd);
				}
				hash_destroy(hReverse);
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }

//DEBUGLOG(("TxnMmsByUsSRV Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
