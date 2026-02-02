/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/09              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnRpyByUsPOL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
void TxnRpyByUsPOL(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csSuccessCode;

	char    csTxnSeq[PD_TXN_SEQ_LEN +1];
	char	csLocalTxnDateTime[PD_DATETIME_LEN +1];
	char	*csPtr;


        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hContext,"txn_seq",csTxnSeq);
	strcpy(csLocalTxnDateTime,getdatetime());	
	PutField_CString((hash_t*)hRequest,"local_tm_datetime",csLocalTxnDateTime);
	
DEBUGLOG(("TxnRpyByUsPOL()\n"));
	if (GetField_CString(hContext,"psp_id",&csPtr)) {
		PutField_CString(hContext,"org_txn_id",csPtr);
		PutField_CString(hContext,"org_txn_code",PD_POLL_TXN_CODE);
		ChannelObjPtr = CreateObj(ChannelPtr,"WEBChannel","UpdateContext");
   		iRet = (unsigned long)((*ChannelObjPtr)(hContext));

DEBUGLOG(("TxnRpyByUsPOL() call TxnRpyOnUsPOL\n"));
     		TxnObjPtr = CreateObj(TxnPtr,"TxnRpyByUsINQ","Authorize");
       		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
		if (GetField_CString(hResponse,"success_code",&csSuccessCode)) {
DEBUGLOG(("TxnRpyByUsPOL::Authorize() success_code = [%s]\n",csSuccessCode));
        	}
	}

DEBUGLOG(("TxnRpyByUsPOL() exit = [%d]\n",iRet));
	return	iRet;
}
