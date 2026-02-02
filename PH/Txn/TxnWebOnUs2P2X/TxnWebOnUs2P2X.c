/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/27              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUs2P2X.h"
#include "myrecordset.h"
#include "mq_db.h"
#include "mydb.h"
#include "queue_utility.h"
#include "dbutility.h"

char cDebug;
OBJPTR(Msg);
OBJPTR(DB);
int     process_resp_txn(hash_t *hContext,
			 hash_t *hResponse,
                                const hex_t* inMsg);
int     process_ack_resp_txn(hash_t *hContext,
			 hash_t *hResponse);

void TxnWebOnUs2P2X(char    cdebug)
{
        cDebug = cdebug;
}

int     process_resp_txn(hash_t *hContext,
			 hash_t *hResponse,
                                const hex_t* inMsg)
{
        int     iRet = PD_OK;
        
DEBUGLOG(("process_resp_txn()\n"));

     	MsgObjPtr = CreateObj(MsgPtr,"P2xMsg","BreakDownMsg");

        if ((*MsgObjPtr)(hResponse,inMsg->msg,inMsg->len) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_resp_txn:BreakDown Msg Error\n"));
        }
        else {
        }

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}               

int     process_ack_resp_txn(hash_t *hContext,
                         hash_t *hResponse)
{
        int     iRet = PD_OK;

DEBUGLOG(("process_ack_resp_txn()\n"));

        MsgObjPtr = CreateObj(MsgPtr,"P2xMsg","BreakDownAckMsg");

        if ((*MsgObjPtr)(hResponse) != PD_OK)  {
                iRet = INT_BREAKDOWN_ERR;
                PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("process_ack_resp_txn:BreakAckDown Msg Error\n"));
        }
        else {
        }

DEBUGLOG(("process_resp_txn:exit iret = [%d]\n",iRet));
        return iRet;
}

int     Encrypt(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;
	hex_t   *h_msg;
        char    *csTxnSeq;
	char	*csPtr;


DEBUGLOG(("TxnWebOnUs2P2X: Encrypt()\n"));

	if (iRet == PD_OK) {
        	if (!GetField_CString(hContext,"from_txn_seq",&csTxnSeq)) 
        		GetField_CString(hContext,"txn_seq",&csTxnSeq);
                        
		PutField_CString((hash_t*)hRequest,"txn_seq",csTxnSeq);

		if (GetField_CString(hContext,"transmission_datetime",&csPtr))
			PutField_CString((hash_t*)hRequest,"transmission_datetime",csPtr);

		if (GetField_CString(hResponse,"fe_url",&csPtr)) {
			PutField_CString((hash_t*)hRequest,"fe_url",csPtr);
		}
       		MsgObjPtr = CreateObj(MsgPtr,"P2xMsg","FormatEnMsg");

        	h_msg = (hex_t*) malloc (sizeof(hex_t));
        	if ((*MsgObjPtr)(hRequest,h_msg->msg,&h_msg->len) == PD_OK) {
			PutField_CString(hResponse,"emsg",(const char*)h_msg->msg);
        	}     
        	else {
                	iRet = INT_FORMAT_ERR;
        	}       
        	FREE_ME(h_msg);
	}

DEBUGLOG(("TxnWebOnUs2P2X: Encrypt exit iret = [%d]\n",iRet));
	return iRet;
}

int     Decrypt(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
	int iRet = PD_OK;

DEBUGLOG(("TxnWebOnUs2P2X: Decrypt()\n"));

	if (iRet == PD_OK) {
		iRet = process_ack_resp_txn(hContext,hRequest);
	}

DEBUGLOG(("TxnWebOnUs2P2X::Decrypt: noraml exit iret = [%d]\n",iRet));
	return iRet;
}

