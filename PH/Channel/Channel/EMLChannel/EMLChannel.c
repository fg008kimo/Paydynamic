/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/21              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <ctype.h>
#include "EMLChannel.h"
#include "utilitys.h"
#include "common.h"
#include "ObjPtr.h"
#include "myrecordset.h"
#include "internal.h"

char	cDebug;
OBJPTR(Msg);
OBJPTR(DB);

void EMLChannel(char	cdebug)
{
	cDebug = cdebug;
}

int 	AddTxnLog(hash_t* hContext,
		const hash_t* hRequest);

int	process_txn(hash_t *hContext,
			   	const hex_t* inMsg,
				hex_t *outMsg)
{
	int	iRet = PD_OK;
	hash_t  *hRequest,*hResponse;
	char	*csTxnSeq;
DEBUGLOG(("process_txn\n"));
DEBUGLOG(("[%d][%s]\n",inMsg->len,inMsg->msg));
	hRequest = (hash_t*) malloc (sizeof(hash_t));
        hResponse = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest,0);
        hash_init(hResponse,0);
	csTxnSeq = (char*) malloc (PD_TXN_SEQ_LEN +1 );

	MsgObjPtr = CreateObj(MsgPtr,"EmlMsg","BreakDownMsg");
    	if ((*MsgObjPtr)(hRequest,inMsg->msg,inMsg->len) != PD_OK)  {
       		iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
ERRLOG("BreakDown EMLMsg Error\n");
DEBUGLOG(("process_txn:BreakDown EMLMsg Error\n"));
 	}
	if (iRet == PD_OK) {
		//txn seq
		DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextEmlTxnSeq");
		strcpy(csTxnSeq,(*DBObjPtr)());
		PutField_CString(hContext,"txn_seq",csTxnSeq);
	}

	if (iRet == PD_OK)
		iRet = AddTxnLog(hContext,hRequest);

	FREE_ME(hRequest);
        FREE_ME(hResponse);
	FREE_ME(csTxnSeq);
	return iRet;
}


int 	AddTxnLog(hash_t* hContext,
		const hash_t* hRequest)
{
	int	iRet = PD_OK;
	hash_t  *hTxn;
	char	*csPtr;
	int	iPtr;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
DEBUGLOG(("AddTxnLog()\n"));
	if (GetField_CString(hContext,"txn_seq",&csPtr)) {
DEBUGLOG(("AddTxnLog() txn_seq = [%s]\n",csPtr));
		PutField_CString(hTxn,"txn_seq",csPtr);
/* sender */
		if (GetField_CString(hRequest,"sender",&csPtr)) {
DEBUGLOG(("AddTxnLog() sender = [%s]\n",csPtr));
			PutField_CString(hTxn,"sender",csPtr);
		}
/* ref_num */
		if (GetField_Int(hRequest,"ref_num",&iPtr)) {
DEBUGLOG(("AddTxnLog() ref_num = [%d]\n",iPtr));
			PutField_Int(hTxn,"ref_num",iPtr);
		}
/* seq_num */
		if (GetField_Int(hRequest,"seq_num",&iPtr)) {
DEBUGLOG(("AddTxnLog() seq_num = [%d]\n",iPtr));
			PutField_Int(hTxn,"seq_num",iPtr);
		}
/* total */
		if (GetField_Int(hRequest,"total",&iPtr)) {
DEBUGLOG(("AddTxnLog() total = [%d]\n",iPtr));
			PutField_Int(hTxn,"total",iPtr);
		}

/* send_datetime */
		if (GetField_CString(hRequest,"send_datetime",&csPtr)) {
DEBUGLOG(("AddTxnLog() send_datetime = [%s]\n",csPtr));
			PutField_CString(hTxn,"send_datetime",csPtr);
		}

/* local_tm_date */
		if (GetField_CString(hContext,"local_tm_date",&csPtr)) {
DEBUGLOG(("AddTxnLog() local_tm_date = [%s]\n",csPtr));
			PutField_CString(hTxn,"local_tm_date",csPtr);
		}

/* local_tm_time */
		if (GetField_CString(hContext,"local_tm_time",&csPtr)) {
DEBUGLOG(("AddTxnLog() local_tm_time = [%s]\n",csPtr));
			PutField_CString(hTxn,"local_tm_time",csPtr);
		}

/* tag */
		if (GetField_CString(hRequest,"tag",&csPtr)) {
DEBUGLOG(("AddTxnLog() tag = [%s]\n",csPtr));
			PutField_CString(hTxn,"tag",csPtr);
		}

/* has_missing_parts */
		if (GetField_Int(hRequest,"has_missing_parts",&iPtr)) {
DEBUGLOG(("AddTxnLog() has_missing_parts = [%d]\n",iPtr));
			PutField_Int(hTxn,"has_missing_parts",iPtr);
		}

/* sms_center */
		if (GetField_CString(hRequest,"smsc",&csPtr)) {
DEBUGLOG(("AddTxnLog() sms_center = [%s]\n",csPtr));
			PutField_CString(hTxn,"sms_center",csPtr);
		}

/* sender_num_type */
		if (GetField_Int(hRequest,"sender_num_type",&iPtr)) {
DEBUGLOG(("AddTxnLog() has_sender_num_type = [%d]\n",iPtr));
			PutField_Int(hTxn,"sender_num_type",iPtr);
		}

/* mail_body */
		if (GetField_CString(hRequest,"mail_body",&csPtr)) {
DEBUGLOG(("AddTxnLog() mail_body = [%s]\n",csPtr));
			PutField_CString(hTxn,"mail_body",csPtr);
		}
/* status */	
		PutField_Char(hTxn,"status",PD_EML_STATUS_NEW);
		DBObjPtr = CreateObj(DBPtr,"DBEmlMessages","Add");
                iRet = (unsigned long) ((*DBObjPtr)(hTxn));

	}

	hash_destroy(hTxn);
        FREE_ME(hTxn)
DEBUGLOG(("AddTxnLog exit iRet = [%d]\n",iRet));
	return 	iRet;
}
