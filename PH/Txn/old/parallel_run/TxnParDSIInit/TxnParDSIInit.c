/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/06/08              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnParDSIInit.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(Txn);

void TxnParDSIInit(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csOrgTxnSeq;
	char	*csTmp = NULL;

	int	iInternalErr;
	char	*csBuf;

	hash_t  *hOrgTxnLog;

	hOrgTxnLog = (hash_t *) malloc(sizeof(hash_t));
	hash_init(hOrgTxnLog, 0);


	// Form txn_header and txn_detail data
	PutField_Int(hContext, "do_logging", PD_ADD_LOG);


	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
		DEBUGLOG(("TxnParDSIInit::Authorize:txn_seq [%s]\n", csTmp));
	}
	else {
		DEBUGLOG(("TxnParDSIInit::Authorize:txn_seq not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
		DEBUGLOG(("TxnParDSIInit::Authorize:org_txn_seq [%s]\n", csOrgTxnSeq));
		
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxn");
			if ((unsigned long)(DBObjPtr)(csOrgTxnSeq,PD_INIT) != PD_FOUND) {
				DEBUGLOG(("TxnParDSIInit::Authorize:DBTransaction.MatchRespTxn FAIL\n"));
				iRet = INT_TXN_ID_NOT_FOUND;
			}
		}
	}
	else {
		DEBUGLOG(("TxnParDSIInit::Authorize:Org Txn Seq not found !\n"));
		iRet = INT_TXN_ID_NOT_FOUND;
	}

	PutField_CString(hContext, "channel_code", PD_CHANNEL_MGT); // MGT
	PutField_CString(hContext, "txn_code", "TSI"); // DSI

	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
		DEBUGLOG(("TxnParDSIInit::Authorize: PHDATE [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "transmission_datetime", &csTmp)) {
		DEBUGLOG(("TxnParDSIInit::Authorize: transmission_datetime [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "tm_date", &csTmp)) { 
		DEBUGLOG(("TxnParDSIInit::Authorize: tm_date [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "local_tm_date", &csTmp)) { 
		DEBUGLOG(("TxnParDSIInit::Authorize: local_tm_date [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "local_tm_time", &csTmp)) { 
		DEBUGLOG(("TxnParDSIInit::Authorize: local_tm_time [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
		DEBUGLOG(("TxnParDSIInit::Authorize: ip_addr [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "add_user", &csTmp)) {
		DEBUGLOG(("TxnParDSIInit::Authorize: add_user [%s]\n", csTmp));
		PutField_CString(hContext, "update_user", csTmp);
	}

	// Add TSI txn log
	ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","AddTxnLog");
        iRet = (unsigned long)((*ChannelObjPtr)(hContext, hRequest));

        if (iRet == PD_OK) {
		DEBUGLOG(("TxnParDSIInit::Authorize: WEBChannel.AddTxnLog Succ\n"));
	}

	if (iRet == PD_OK) {
		// Update org txn log
	
		PutField_CString(hOrgTxnLog, "txn_seq", csOrgTxnSeq);
		PutField_CString(hOrgTxnLog, "sub_status", PD_INITIATED);
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
                if ((DBObjPtr)(hOrgTxnLog) != PD_OK) {
			DEBUGLOG(("TxnParDSIInit::Authorize: DBTransaction.Update\n"));
			iRet = PD_ERR;

                }
	}

	if (iRet == PD_OK) {
		PutField_CString(hRequest, "process_type", "0000"); 
		PutField_CString(hRequest, "process_code", "000000"); 
	
		if (GetField_Int(hContext, "internal_error", &iInternalErr)) {
			csBuf = (char *)malloc (128);
			sprintf(csBuf, "%d", iInternalErr);
			PutField_CString(hResponse, "response_code", csBuf);
			FREE_ME(csBuf);

			PutField_Int(hContext, "internal_code", iInternalErr);
		} 

		PutField_Char(hContext,"ar_ind",PD_ACCEPT);
		PutField_Char(hContext,"status",PD_COMPLETE);


		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnLog");
	        iRet = (unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse));

		if (iRet == PD_OK) {
			DEBUGLOG(("TxnParDSIInit::Authorize: WEBChannel.UpdateTxnLog Succ\n"));
		}
	}
		
	hash_destroy(hOrgTxnLog);
	FREE_ME(hOrgTxnLog);
	

DEBUGLOG(("TxnParDSIInit Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
