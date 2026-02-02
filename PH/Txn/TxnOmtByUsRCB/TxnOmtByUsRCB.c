/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/24              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRCB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

#define	PD_DETAIL_TAG	"dt"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);

void TxnOmtByUsRCB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iCnt = 0,i;
	char	csTag[PD_TAG_LEN +1];
	char	*csPtr;
DEBUGLOG(("Authorize::()\n"));

/* txn ack log */
        char    csBatchTxnSeq[PD_TXN_SEQ_LEN +1];
        DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOmtTxnSeq");
        strcpy(csBatchTxnSeq,(*DBObjPtr)());
        PutField_CString(hContext,"batch_txn_seq",csBatchTxnSeq);
/* end txn ack log */

	if (GetField_Int(hContext,"total_cnt",&iCnt)) {
		PutField_Int(hResponse,"total_cnt",iCnt);
DEBUGLOG(("Authorize::() total_cnt = [%d]\n",iCnt));
		for (i = 0; i< iCnt; i++) {
			sprintf(csTag,"%s_txnid_%d",PD_DETAIL_TAG,i+1);
			if (GetField_CString(hRequest,csTag,&csPtr)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n",csTag,csPtr));

				PutField_CString(hContext,"org_txn_seq",csPtr);
				TxnObjPtr = CreateObj(TxnPtr,"TxnOlnByUsACK","Authorize");
                		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

				sprintf(csTag,"ret_%d",i+1);
DEBUGLOG(("Authorize::() [%s] = [%d]\n",csTag,iRet));
                                PutField_Int(hResponse,csTag,iRet);
			}
		}
	}
	else {
		iRet = INT_FORMAT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
DEBUGLOG(("TxnOmtByUsRCB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
