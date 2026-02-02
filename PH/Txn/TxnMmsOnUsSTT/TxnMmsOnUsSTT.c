/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/12              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsOnUsSTT.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMmsOnUsSTT(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csPtr;
	char	*csTxnCcy;
	double	dTxnAmt;
	char	csIntTxnCode[PD_TXN_CODE_LEN +1];
	char	*csNodeTxnCode;

	hash_t  *hData;

DEBUGLOG(("Authorize()\n"));
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	if (GetField_CString(hRequest,"node_txn_code",&csNodeTxnCode)) {
DEBUGLOG(("Authorize() node_txn_code = [%s]\n",csNodeTxnCode));
		DBObjPtr = CreateObj(DBPtr,"DBMmsTxnCodeMap","FindTxnCode");
		if ((unsigned long)(DBObjPtr)(csNodeTxnCode,csIntTxnCode) == PD_FOUND) {
DEBUGLOG(("Authorize() int_txn_code = [%s]\n",csIntTxnCode));
			PutField_CString(hContext,"txn_code",csIntTxnCode);
		}
		else {
DEBUGLOG(("Authorize() int_txn_code for [%s] not found\n",csNodeTxnCode));
ERRLOG("Authorize() int_txn_code for [%s] not found\n",csNodeTxnCode);
			iRet = PD_ERR;
		}
	}
	else {
DEBUGLOG(("Authorize() node_txn_code not found\n"));
ERRLOG("Authorize() node_txn_code not found\n");
		iRet = PD_ERR;
	}

	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize() nature txn amt = [%lf]\n",dTxnAmt));
		PutField_Double(hContext,"net_amt",dTxnAmt);
		PutField_Double(hContext,"remaining_amt",dTxnAmt);
	}

/* txn seq*/
	if (GetField_CString(hContext,"txn_seq",&csPtr)) {
DEBUGLOG(("Authorize() txn_seq = [%s]\n",csPtr));
		PutField_CString(hData,"txn_seq",csPtr);
        }
        else {
DEBUGLOG(("Authorize() txn_seq not found\n"));
        }

/* Entity Id */
	if (GetField_CString(hContext,"entity_id",&csPtr)) {
DEBUGLOG(("Authorize() Entity ID = [%s]\n",csPtr));
                PutField_CString(hData,"entity_id",csPtr);
        }
        else {
DEBUGLOG(("Authorize() Entity ID not found\n"));
        }

/* txn_country */
	if (GetField_CString(hRequest,"txn_country",&csPtr)) {
DEBUGLOG(("Authorize() txn_country = [%s]\n",csPtr));
                PutField_CString(hData,"country",csPtr);
        }
        else {
DEBUGLOG(("Authorize() txn_country not found\n"));
        }

/* Nature Id */
	if (GetField_CString(hContext,"nature_id",&csPtr)) {
		char	csTag[PD_TAG_LEN + 1];
		int	i = 1;
DEBUGLOG(("Authorize() Nature ID = [%s]\n",csPtr));

/* bal_cnt */
		PutField_Int(hContext,"bal_cnt",i);

/* nat_cnt */
		sprintf(csTag,"bal.%d.nat_cnt",i);
		PutField_Int(hContext,csTag,i);
/* nature_id */
		sprintf(csTag,"bal.%d.nature_id",i);
		PutField_CString(hContext,csTag,csPtr);
/* amt */
		sprintf(csTag,"bal.%d.amt",i);
		PutField_Double(hContext,csTag,dTxnAmt);
        }
        else {
DEBUGLOG(("Authorize() Nature ID not found\n"));
        }

/* txn_ccy */
	if (GetField_CString(hRequest,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("Authorize() from_ccy = [%s]\n",csTxnCcy));
                PutField_CString(hData,"from_ccy",csTxnCcy);
                PutField_CString(hData,"ccy",csTxnCcy);
                PutField_CString(hContext,"net_ccy",csTxnCcy);
        }
        else {
DEBUGLOG(("Authorize() txn_ccy not found\n"));
        }


	if (iRet == PD_OK) {
		BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","CreditIntransit");
		iRet = (unsigned long)((BOObjPtr)(hContext,hData));

DEBUGLOG(("Authorize() iRet = [%d] from BOMMSEntityBalance:CreditIntransit\n",iRet));
	}



	if (iRet == PD_OK) {	
/* add PH Txn Log */
        	hash_init(hData,0);
		BOObjPtr = CreateObj(BOPtr,"BOMMSPhTxn","AddLog");
		iRet = (unsigned long)((BOObjPtr)(hContext,hRequest));
	}

	hash_destroy(hData);
	FREE_ME(hData);



DEBUGLOG(("TxnMmsOnUsSTT Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

