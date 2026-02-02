/*
PDProTech(c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version (Clone from OPL)                      2017/05/10              Dirk Wong
*/



#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "TLGChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"
#include "dbutility.h"
#include "langconvert.h"


char	cDebug;

void TLGChannel(char	cdebug)
{
	cDebug = cdebug;
}


OBJPTR(Msg);
OBJPTR(Txn);

int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response);

int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	hash_t	*hRequest,*hResponse;
	long	lResponseQueueMtype;

	char	cTxnType;
	char*	csChannelCode;

	int	iRet = INT_NO_ERR;
	
DEBUGLOG(("process_txn\n"));

DEBUGLOG(("msg len = [%d]\n",inMsg->len));
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);


	GetField_Char(hContext,"txn_type",&cTxnType);
DEBUGLOG(("txn type = [%c]\n",cTxnType));

	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
DEBUGLOG(("channel code = [%s]\n",csChannelCode));
	}
	else  {
DEBUGLOG(("unable to get channel code queue mtype\n"));
		iRet = PD_ERR;
	}

	PutField_Char(hContext,"dont_convert",PD_DOPD_CONVERT);
	if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("response queue mtype = [%ld]\n",lResponseQueueMtype));
	}
	else  {
DEBUGLOG(("unable to get response queue mtype\n"));
		iRet = PD_ERR;
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Call TlgMsg [%d]\n",inMsg->len));
        	MsgObjPtr = CreateObj(MsgPtr,"TlgMsg","BreakDownMsg");
        	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
               		iRet = INT_BREAKDOWN_ERR;
                	PutField_Int(hContext,"internal_error",iRet);
ERRLOG("BreakDown TLGMsg Error\n");
DEBUGLOG(("process_txn:BreakDown TLGMsg Error\n"));
        	}
	}

	if (iRet == PD_OK) {
		iRet = process_input_txn(hContext,hRequest,hResponse);  
	}

	FREE_ME(hRequest);
	FREE_ME(hResponse);
	return iRet;
}


int     process_input_txn(hash_t *hContext,
                                const hash_t *Request,
                                hash_t *Response)
{
        int     iRet = PD_OK;

DEBUGLOG(("process_input\n"));

        if (iRet == PD_OK ) {
        	TxnObjPtr = CreateObj(TxnPtr,"TxnTlgOnUsCOM","Authorize");
                iRet = (unsigned long)(*TxnObjPtr)(hContext,Request,Response);
        }

DEBUGLOG(("process_input() exit iRet = [%d]\n",iRet));
        return iRet;
}

