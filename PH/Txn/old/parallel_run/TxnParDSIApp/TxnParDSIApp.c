/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/11             Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnParDSIApp.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(Txn);

void TxnParDSIApp(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csOrgTxnSeq = NULL;

	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
		DEBUGLOG(("TxnParDSIApp::Authorize:org_txn_seq [%s]\n", csOrgTxnSeq));
		PutField_CString(hContext, "from_txn_seq", csOrgTxnSeq);
	}
	else {
		DBUGLOG(("TxnParDSIApp::Authorize:org_txn_seq not found!\n"));
		iRet = PD_ERR;
	}

		
	//GetService (from table: par_merch_profile, by merchant_id, get service)
	//GetReserveAmount (from table: par_merch_rule_reserve, by mid, ccy, service, get reserve_rate);
	//Cal Float Amt and Reserve Amt
	
	
	
//BOBalance.UpdateTxnAmount
//	// Handle Bucket 
	// Get Open Balance for update
	// Update Float and Balance (Merch)
	// TxnElement: Float Amt
	// Update Reserve Amt	
	// TxnElement: Reserve Amt
	// Credit Balance (float; PSP)
	// Get Current Values (Merch , PSP)

	// DBTransaction.Update (status:C; ar_ind:A; sub_status:103)
	// DBTransaction.UpdateDetail
	// DBTxnPspDetail.Update


DEBUGLOG(("TxnParDSIApp Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
