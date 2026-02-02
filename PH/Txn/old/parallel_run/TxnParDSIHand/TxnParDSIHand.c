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
#include "TxnParDSIHand.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(Txn);

void TxnParDSIHand(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp= NULL;
	char	*csMerchantId = NULL;
	char	*csPayMethod = NULL;
	int	iTmp = 0;

	int	iInternalErr;
	char	*csBuf;
	double	dTmp = 0.0;

	hash_t  *hRec;

	recordset_t 	*rRecordSet;
	rRecordSet = (recordset_t *) malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	// Form txn_header and txn_detail data
		
	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize:txn_seq [%s]\n", csTmp));
	}
	else {
		DEBUGLOG(("TxnParDSIHand::Authorize:txn_seq not found!\n"));
		iRet = PD_ERR;
	}

	PutField_CString(hContext, "channel_code", PD_CHANNEL_XPAY); // XPY
	PutField_CString(hContext, "txn_code", PD_INITIAL_TXN_CODE); // DSI
	PutField_CString(hRequest, "process_type", "0200"); 
	PutField_CString(hRequest, "process_code", "200002"); 

	if (GetField_CString(hRequest, "merchant_id", &csMerchantId)) {
		DEBUGLOG(("TxnParDSIHand::Authorize:mechant_id [%s]\n", csMerchantId));
	}
	else {
		DEBUGLOG(("TxnParDSIHand::Authorize:merchant_id not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hRequest, "merchant_ref", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize:mechant_ref [%s]\n", csTmp));
	}
	else {
		DEBUGLOG(("TxnParDSIHand::Authorize:merchant_ref not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: PHDATE [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "transmission_datetime", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: transmission_datetime [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "tm_date", &csTmp)) { 
		DEBUGLOG(("TxnParDSIHand::Authorize: tm_date [%s]\n", csTmp));
	}
	if (GetField_CString(hRequest, "tm_time", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: tm_time [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "local_tm_date", &csTmp)) { 
		DEBUGLOG(("TxnParDSIHand::Authorize: local_tm_date [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "local_tm_time", &csTmp)) { 
		DEBUGLOG(("TxnParDSIHand::Authorize: local_tm_time [%s]\n", csTmp));
	}

	if (GetField_CString(hContext, "add_user", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: add_user [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "service_code", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: service_code [%s]\n", csTmp));
	}

	//PutField_CString(hContext, "sub_status", PD_HAND_SHAKEN);

	// txn_detail
	if (GetField_CString(hRequest, "txn_ccy", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: txn_ccy [%s]\n", csTmp));
	}

	// or get country by Service?
	if (GetField_CString(hRequest, "txn_country", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: txn_country [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "pay_method", &csPayMethod)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: pay_method [%s]\n", csPayMethod));
	}

	if (GetField_CString(hRequest, "language", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: language [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "success_url", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: success_url [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "failure_url", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: failure_url [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "success_callback_url", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: success_callback_url [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "failure_callback_url", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: failure_callback_url [%s]\n", csTmp));
	}

	if (GetField_CString(hRequest, "encrypt_type", &csTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: encrypt_type [%s]\n", csTmp));
	}

	if (GetField_Int(hRequest, "version_no", &iTmp)) {
		DEBUGLOG(("TxnParDSIHand::Authorize: version_no [%d]\n", iTmp));
	}

	ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","AddTxnLog");
        iRet = (unsigned long)((*ChannelObjPtr)(hContext, hRequest));

        if (iRet == PD_OK) {
		DEBUGLOG(("TxnParDSIHand::Authorize: WEBChannel.AddTxnLog Succ\n"));
	}

	if (iRet == PD_OK) {
		// Get Client ID
		DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","GetMerchant");
		if ((*DBObjPtr)(csMerchantId, rRecordSet) != PD_OK) {

			iRet = INT_MERCHANT_ID_NOT_FOUND;
			DEBUGLOG(("TxnParDSIHand::Authorize: DBMerchDetail.GetMerchant FAIL!\n"));
		}
		else {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "merchant_client_id", &csTmp)) {
					DEBUGLOG(("TxnParDSIHand::Authorize: merchant_client_id [%s]\n", csTmp));
					PutField_CString(hContext,"merchant_client_id",csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		//DSI.Authoize, add txn_psp_detail

			if (GetField_CString(hContext, "psp_id", &csTmp)) {
				DEBUGLOG(("TxnParDSIHand::Authorize: psp_id [%s]\n", csTmp));
			}
			PutField_CString(hContext, "txn_desc", "DSP Initial Mode");

			TxnObjPtr = CreateObj(TxnPtr,"TxnWebOnUsDSI","Authorize");
			iRet = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

	}

	if (iRet == PD_OK) {
		if (GetField_Int(hContext, "internal_error", &iInternalErr)) {
			csBuf = (char *)malloc (128);
			sprintf(csBuf, "%d", iInternalErr);
			PutField_CString(hResponse, "response_code", csBuf);
			FREE_ME(csBuf);

			PutField_Int(hContext, "internal_code", iInternalErr);
		}

		PutField_Char(hResponse,"status",PD_INIT);
		PutField_Char(hContext,"status",PD_INIT);
		PutField_CString(hContext,"sub_status",PD_HAND_SHAKEN);

		if (GetField_CString(hRequest, "pay_method", &csPayMethod)) {
			PutField_CString(hContext, "selected_pay_method", csPayMethod);
		}

		if (GetField_Double(hContext, "txn_amt", &dTmp)) {
			DEBUGLOG(("TxnParDSIHand::Authorize: txn_amt [%f]\n", dTmp));
		}

		if (GetField_CString(hRequest, "net_ccy", &csTmp)) {
			DEBUGLOG(("TxnParDSIHand::Authorize: net_ccy [%s]\n", csTmp));
		}

		ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","UpdateTxnLog");
	        iRet = (unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse));

		if (iRet == PD_OK) {
			DEBUGLOG(("TxnParDSIHand::Authorize: WEBChannel.UpdateTxnLog Succ\n"));
		}
	}
		

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnParDSIHand Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
