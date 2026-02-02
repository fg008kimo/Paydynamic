/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/08              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsPOL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);
void TxnWebByUsPOL(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csPspId;
	char	*csSuccessCode;

	char    csTxnSeq[PD_TXN_SEQ_LEN +1];


        DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmsTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        PutField_CString(hContext,"txn_seq",csTxnSeq);
	
DEBUGLOG(("TxnWebByUsPOL()\n"));
	if (GetField_CString(hContext,"psp_id",&csPspId)) {
		PutField_CString(hContext,"org_txn_code",PD_POLL_TXN_CODE);
DEBUGLOG(("TxnWebByUsPOL() psp_id = [%s]\n",csPspId));
		ChannelObjPtr = CreateObj(ChannelPtr,"WEBChannel","UpdateContext");
 	  	iRet = (unsigned long)((*ChannelObjPtr)(hContext));

		for (;;) {
DEBUGLOG(("TxnWebByUsPOL() call TxnWebOnUsPOL\n"));
        		TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsPOL","Authorize");
        		iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
			if (GetField_CString(hResponse,"success_code",&csSuccessCode)) {
DEBUGLOG(("TxnWebByUsPOL::Authorize() success_code = [%s]\n",csSuccessCode));
				if (!strcmp(csSuccessCode,PD_PGEN_SUCCESS))  {
					TxnCommit();
					TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsACK","Authorize");
                                        iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);
				}
				if (strcmp(csSuccessCode,PD_PGEN_SUCCESS)) 
					break;
				else {
DEBUGLOG(("TxnWebByUsPOL::Authorize()  May be more to come\n"));
				}
                	}
			else 
				break;
		}
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("TxnWebByUsPOL() psp_id is missing!!!\n"));
	}

DEBUGLOG(("TxnWebByUsPOL() exit = [%d]\n",iRet));
	return	iRet;
}
