/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/06/18              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmmByUsELA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);


void TxnMmmByUsELA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_ERR;
	char	*csPtr;
	char	cAction;
	double	dTxnAmt;

	hash_t  *hData;
DEBUGLOG(("Authorize()\n"));

	hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);	

	if (GetField_Char(hRequest,"action",&cAction)) {
DEBUGLOG(("Authorize() action = [%c]\n",cAction));
		iRet = PD_OK;
		if ((cAction != PD_MMS_ACTION_LIEN_CREATE) && (cAction != PD_MMS_ACTION_LIEN_RELEASE)) {
			iRet = INT_MMS_INVALID_ACTION;
DEBUGLOG(("Authorize() invalid action = [%c]\n",cAction));
ERRLOG("TxnMmmByUsELA:Authorize() invalid action = [%c]\n",cAction);
			PutField_Int(hContext,"internal_error",iRet);
		}
	}
	else {
DEBUGLOG(("Authorize() invalid action = [%c]\n",cAction));
ERRLOG("TxnMmmByUsELA:Authorize() invalid action = [%c]\n",cAction);
	}
	
	if (iRet == PD_OK) {
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
DEBUGLOG(("Authorize() Nature ID = [%s]\n",csPtr));
                	PutField_CString(hData,"nature_id",csPtr);
        	}
        	else {
DEBUGLOG(("Authorize() Nature ID not found\n"));
        	}

/* txn_ccy */
        	if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
DEBUGLOG(("Authorize() from_ccy = [%s]\n",csPtr));
                	PutField_CString(hData,"from_ccy",csPtr);
                	PutField_CString(hData,"ccy",csPtr);
                	PutField_CString(hContext,"net_ccy",csPtr);
        	}
        	else {
DEBUGLOG(("Authorize() txn_ccy not found\n"));
        	}

		if (cAction == PD_MMS_ACTION_LIEN_CREATE)  {
			BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","CreditLien");
			PutField_CString(hContext,"txn_code",PD_HOLD_BALANCE_PSP);
		}
		else  {
			BOObjPtr = CreateObj(BOPtr,"BOMMSEntityBalance","DebitLien");
			PutField_CString(hContext,"txn_code",PD_UNHOLD_BALANCE_PSP);
		}

		iRet = (unsigned long)((BOObjPtr)(hContext,hData));
DEBUGLOG(("Authorize() iRet = [%d] from BOMMSEntityBalance Lien\n",iRet));

		if (iRet == PD_OK) {
			PutField_CString(hContext,"sub_status",PD_APPROVED);
                	if (GetField_Double(hContext,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("Authorize() nature txn amt = [%lf]\n",dTxnAmt));
                        	PutField_Double(hContext,"net_amt",dTxnAmt);
                	}
        	}
	}

	FREE_ME(hData);
DEBUGLOG(("TxnMmmByUsELA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

