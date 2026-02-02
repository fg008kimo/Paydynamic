/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/21              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsSTC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnOmtByUsSTC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTmp;
	char	cParty;

DEBUGLOG(("Authorize\n"));

	if(GetField_CString(hRequest,"org_txn_seq",&csTmp)){
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
		PutField_CString(hContext,"txn_seq",csTmp);
	}
	else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnOmtByUsSTC:Authorize::txnid not found!!\n");
		iRet=INT_INVALID_TXN;
	}

	if(GetField_CString(hRequest,"party",&csTmp)){
DEBUGLOG(("Authorize::party = [%s]\n",csTmp));
		cParty = csTmp[0];
		PutField_Char(hRequest,"action_party",cParty);
	}
	
	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOOLSettlement:ProcessSettlementTxn\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLSettlement","ProcessSettlementTxn");
                iRet = (unsigned long) (*BOObjPtr)(hContext,hRequest,hResponse);
        }

	if(iRet!=PD_OK){
                PutField_Int(hContext,"internal_error",iRet);
        }

DEBUGLOG(("TxnOmtByUsSTC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
