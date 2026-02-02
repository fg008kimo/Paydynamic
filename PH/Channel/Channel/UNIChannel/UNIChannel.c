/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/04              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "queue_utility.h"
#include "UNIChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"
#include "mydb.h"
#include "mq_db.h"
#include "dbutility.h"
#include "langconvert.h"

#define	PD_ACK_RESEND	"resend_web_rck.sh"
char	cDebug;

void UNIChannel(char	cdebug)
{
	cDebug = cdebug;
}


OBJPTR(Channel);
OBJPTR(DB);
OBJPTR(Msg);

int     UpdateContext(hash_t* hContext);


int     process_bounce_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg);
int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	hash_t	*hRequest,*hResponse;

	long	lResponseQueueMtype;


	int	iRet = INT_NO_ERR;

	char*	csChannelCode = strdup("");
	char	cTxnType;
	
DEBUGLOG(("process_txn\n"));

	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest,0);
	hash_init(hResponse,0);

	GetField_Char(hContext,"txn_type",&cTxnType);
DEBUGLOG(("txn type = [%c]\n",cTxnType));


	PutField_Char(hContext,"dont_convert",PD_DOPD_CONVERT);
	if (GetField_Long(hContext,"response_queue_mtype",&lResponseQueueMtype)) {
DEBUGLOG(("response queue mtype = [%ld]\n",lResponseQueueMtype));
	}
	else  {
DEBUGLOG(("unable to get response queue mtype\n"));
		iRet = PD_ERR;
	}
	if (GetField_CString(hContext,"channel_code",&csChannelCode)) {
/* set default return channel code */
		PutField_CString(hResponse,"channel_code",csChannelCode);
DEBUGLOG(("channel code = [%s]\n",csChannelCode));
	}
	else  {
DEBUGLOG(("unable to get channel code queue mtype\n"));
		iRet = PD_ERR;
	}
	if (cTxnType ==  MQ_RESP ) {
                iRet  = (UpdateContext(hContext));
		if (iRet == PD_OK) {
DEBUGLOG(("Call WEBChannel process_psp_resp_txn\n"));
			PutField_CString(hContext,"return_psp_channel",PD_CHANNEL_UNIPAY);
			ChannelObjPtr = CreateObj(ChannelPtr,"WEBChannel","process_psp_resp_txn");
        		return (unsigned long)((*ChannelObjPtr)(hContext,inMsg,outMsg));
		}
	}
	else if (cTxnType == MQ_BOUNCE_BACK) {
DEBUGLOG(("Bounce Backup Txn!!!\n"));
		return process_bounce_txn(hContext,inMsg,outMsg);
	}


DEBUGLOG(("Normal RET = [%d]\n",iRet));
	FREE_ME(hRequest);
	FREE_ME(hResponse);
	FREE_ME(csChannelCode);
DEBUGLOG(("process_txn RET =[%d]\n",iRet));
	return iRet;
}




int     UpdateContext(hash_t* hContext)
{
	int	iRet = PD_OK;
        long    lKey;
	hash_t  *hRec;
	char    *csCode = strdup("");
        char    *csValue = strdup("");
	char*	csQueueName = strdup("");
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

	if (GetField_CString(hContext,"reply_queue",&csQueueName)) {
DEBUGLOG(("UpdateContext:reply queue = [%s]\n",csQueueName));
		lKey = GetMQKey((unsigned char*)csQueueName);
        	PutField_Long(hContext,"queue_key",lKey);
DEBUGLOG(("UpdateContext:reply queue key = [%ld]\n",lKey));
	}


        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("UpdateContext: return \n"));
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));
                                                PutField_CString(hContext,"PHDATE",csValue);
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("Internal Error:UNI Channel:SystemControl Record Not Found\n");
        }

	if (iRet == PD_OK) {
        	DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)(PD_BASED_CCY,csValue) == FOUND) {
DEBUGLOG(("based ccy  = [%s]\n",csValue));
                        PutField_CString(hContext,"based_ccy",csValue);
                }
                else {
                        iRet = INT_ERR;
ERRLOG("Unable to find based ccy\n");
                }
        }

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(csCode);
        FREE_ME(csValue);
        FREE_ME(csQueueName);

	return iRet;
}


int     process_bounce_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	int	iRet = PD_OK;
	char	*csOrgTxnSeq;
	char	csCmd[PD_MAX_FILE_LEN +1];
	hash_t  *hRequest;

	hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);

DEBUGLOG(("process_bounce_txn:: ()\n"));

	MsgObjPtr = CreateObj(MsgPtr,"PftMsg","DeBlockBounceBackData");
        if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_bounce_txn:BreakDown UNIMsg Error\n"));
        }
        else {
      		if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("process_bounce_txn:org txn seq = [%s]\n",csOrgTxnSeq));
			sprintf(csCmd,"%s %s",PD_ACK_RESEND,csOrgTxnSeq);
DEBUGLOG(("process_bounce_txn:cmd = [%s]\n",csCmd));
			system(csCmd);
		}
	}

	FREE_ME(hRequest);
	return iRet;
}
