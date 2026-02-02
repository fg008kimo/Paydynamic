/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/12              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsSUB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);


void TxnOmtByUsSUB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp;
	char    csTxnSeq[PD_TXN_SEQ_LEN +1];


	hash_t	*hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

// enc_txn_seq
	if (GetField_CString(hRequest, "enc_txn_seq", &csTmp)) {
DEBUGLOG(("Authorize() enc_txn_seq [%s]\n", csTmp));
		PutField_CString(hTxn, "session_id", csTmp);

		memset(csTxnSeq, 0, sizeof(csTxnSeq));

		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
		(BOObjPtr)(csTmp, csTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hTxn, "txn_seq", csTxnSeq);
	} else {
		iRet = INT_TXN_ID_MISSING;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOmtByUsSUB: Authorize::org txn seq is missing\n");
	}

// bank_code
	if (GetField_CString(hRequest, "int_bank_code", &csTmp)) {
		PutField_CString(hTxn,"bank_code",csTmp);
	}

	if (GetField_CString(hRequest,"logmsg",&csTmp)){
		PutField_CString(hTxn,"logmsg",csTmp);
DEBUGLOG(("Authorize::logmsg = [%s]\n",csTmp));
	}
	else{
		iRet = INT_DESC_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
ERRLOG("TxnOmtByUsSUB: Authorize::logmsg is missing\n");
	}


// user
	if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hTxn,"add_user",csTmp);
DEBUGLOG(("Authorize::user = [%s]\n",csTmp));
	}
	else{
		PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	}


	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBOLTxnWebLog:Add\n"));
                DBObjPtr = CreateObj(DBPtr,"DBOLTxnWebLog","Add");
                if((unsigned long) ((*DBObjPtr)(hTxn))!=PD_OK){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBOLTxnWebLog:Add Failed\n"));
ERRLOG("TxnOmtByUsSUB: Authorize::DBOLTxnWebLog:Add Failed\n");
                }
	}

	FREE_ME(hTxn);
DEBUGLOG(("TxnOmtByUsSUB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
