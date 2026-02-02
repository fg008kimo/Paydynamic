/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/05/13              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOlnByUsSCK.h"
#include "myrecordset.h"
#include "dbutility.h"

char cDebug;
#define	PD_MAX_TRY	5

OBJPTR(DB);
void TxnOlnByUsSCK(char    cdebug)
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
	char    *csBatchTxnId;
	hash_t	*hRec;
	hash_t  *hAck;

        hAck = (hash_t*) malloc (sizeof(hash_t));	
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBOLTxnAckRetry","GetPendingAck");
        if ((*DBObjPtr)(PD_MAX_TRY,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"txn_id",&csValue) && GetField_CString(hRec,"batch_txn_id",&csBatchTxnId)) {
				hash_init(hAck,0);
				PutField_Char(hAck,"status",PD_COMPLETE);
				PutField_CString(hAck,"txn_seq",csValue);
				PutField_CString(hAck,"batch_txn_seq",csBatchTxnId);
DEBUGLOG(("TxnOlnByUsSCK txn_id = [%s]\n",csValue));
DEBUGLOG(("TxnOlnByUsSCK batch_txn_id = [%s]\n",csBatchTxnId));
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnAckRetry","Update");

				if ((*DBObjPtr)(hAck) == PD_OK) {
					TxnCommit();
					sprintf(csCmd,"resend_oln_ack.sh %s %s",csValue,csBatchTxnId);
DEBUGLOG(("TxnOlnByUsSCK cmd = [%s]\n",csCmd));
					system(csCmd);
				}
				hash_destroy(hAck);
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }

//DEBUGLOG(("TxnOlnByUsSCK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
