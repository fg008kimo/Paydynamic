/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/08/28              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnCctByUsSCK.h"
#include "myrecordset.h"
#include "dbutility.h"

char cDebug;
#define	PD_MAX_TRY	5

OBJPTR(DB);
void TxnCctByUsSCK(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csCmd[PD_MAX_FILE_LEN + 1];

	char    *csMerchantId;
	char    *csMerchantRef;
	hash_t	*hRec;
	hash_t  *hAck;

        hAck = (hash_t*) malloc (sizeof(hash_t));	
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	DBObjPtr = CreateObj(DBPtr,"DBTxnCctAckRetry","GetPendingAck");
        if ((*DBObjPtr)(PD_MAX_TRY,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"merchant_id",&csMerchantId) &&
                            GetField_CString(hRec,"merchant_ref",&csMerchantRef)) {
				hash_init(hAck,0);
				PutField_Char(hAck,"status",PD_COMPLETE);
				PutField_CString(hAck,"merchant_id",csMerchantId);
				PutField_CString(hAck,"merchant_ref",csMerchantRef);
				DBObjPtr = CreateObj(DBPtr,"DBTxnCctAckRetry","Update");

				if ((*DBObjPtr)(hAck) == PD_OK) {
					TxnCommit();
//DEBUGLOG(("TxnCctByUsSCK txn_id = [%s]\n",csValue));
					sprintf(csCmd,"resend_cct_ack.sh %s %s",csMerchantId,csMerchantRef);
//DEBUGLOG(("TxnCctByUsSCK cmd = [%s]\n",csCmd));
					system(csCmd);
				}
				hash_destroy(hAck);
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }

//DEBUGLOG(("TxnCctByUsSCK Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
