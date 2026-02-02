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
#include "TxnParDSIPSP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);
OBJPTR(Txn);

void TxnParDSIPSP(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp= NULL;
	char	*csOrgTxnSeq;


	int	iInternalErr;
	char	*csBuf;

	double	dFee = 0.0;
	double	dTxnAmt = 0.0;
	double	dMarkupAmt = 0.0;
	double	dNetAmt	= 0.0;
	double	dPspAmt	= 0.0;
	double  dRate = 0.0;

	hash_t  *hRec;

	recordset_t 	*rRecordSet;

	// Form txn_header and txn_detail data
		
	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
		DEBUGLOG(("TxnParDSIPSP::Authorize:txn_seq [%s]\n", csTmp));
	}
	else {
		DEBUGLOG(("TxnParDSIPSP::Authorize:txn_seq not found!\n"));
		iRet = PD_ERR;
	}

	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
		DEBUGLOG(("TxnParDSIPSP::Authorize:org_txn_seq [%s]\n", csOrgTxnSeq));
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
	}
	else {
		DEBUGLOG(("TxnParDSIPSP::Authorize:org_txn_seq not found!\n"));
		iRet = PD_ERR;
	}


	rRecordSet = (recordset_t *) malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {	
			hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                if (GetField_CString(hRec,"txn_code",&csTmp)) {
					DEBUGLOG(("TxnParDSIPSP::Authorize:txn_header.txn_code [%s]\n", csTmp));
                                        PutField_CString(hContext,"org_txn_code",csTmp);
                                 }


				if (GetField_Double(hRec,"txn_amt",&dTxnAmt)) {
					DEBUGLOG(("TxnParDSIPSP::Authorize:txn_header.txn_amt [%lf]\n", dTxnAmt));

                                        PutField_Double(hContext,"org_txn_amt",dTxnAmt);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}
	RecordSet_Destroy(rRecordSet);

	rRecordSet = (recordset_t *) malloc(sizeof(recordset_t));
	recordset_init(rRecordSet, 0);
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
		if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec,"txn_ccy",&csTmp)) {
					DEBUGLOG(("TxnParDSIPSP::Authorize:txn_detail.txn_ccy [%d]\n", csTmp));
					
					PutField_CString(hContext,"org_txn_ccy",csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}
	RecordSet_Destroy(rRecordSet);


	if (iRet == PD_OK) {
		PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
		PutField_CString(hContext, "amount_type", PD_CR);

		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
		iRet = (unsigned long)(*BOObjPtr)(hContext);

		DEBUGLOG(("TxnParDSIPSP::Authorize:BOTxnElements.AddTxnAmtElement return [%d]\n", iRet));
	}
		
	// Markup Rate
	if (iRet == PD_OK) {	
		if (GetField_Double(hRequest, "ex_rate", &dRate)) {
			PutField_Double(hContext, "markup_rate", dRate);
			PutField_Double(hContext, "ex_rate", dRate);
		}
		PutField_Char(hContext, "ex_party", PD_INT_EX);
	
		if (GetField_Double(hRequest, "markup_amt", &dMarkupAmt)) {
			PutField_Double(hContext, "markup_amt", dMarkupAmt);
		}
		PutField_CString(hContext, "amount_type", PD_DR);

		if (dMarkupAmt > 0.0) {
                	BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddMarkupAmtElement");
	                iRet = (unsigned long)(*BOObjPtr)(hContext);

			DEBUGLOG(("TxnParDSIPSP::Authorize:BOTxnElements.AddMarkupAmtElement return [%d]\n", iRet));
		}
	}


	if (iRet == PD_OK) {
		PutField_Char(hContext, "status", PD_TO_PSP); // W
		PutField_CString(hContext, "sub_status", PD_SENT_TO_PSP); // 102

		if (GetField_Int(hContext, "internal_error", &iInternalErr)) {
			csBuf = (char *)malloc (128);
			sprintf(csBuf, "%d", iInternalErr);
			PutField_CString(hResponse, "response_code", csBuf);
			FREE_ME(csBuf);

			PutField_Int(hContext, "internal_code", iInternalErr);
		}

		if (GetField_Double(hRequest, "fee", &dFee)) {
			dNetAmt	= dTxnAmt - dFee;
		}
		else {
			dNetAmt = dTxnAmt;
		}
		PutField_Double(hContext, "net_amt", dNetAmt);
		DEBUGLOG(("TxnParDSIPSP::Authorize:NetAmt [%lf]\n", dNetAmt));

		if (GetField_CString(hRequest, "bank_code", &csTmp)) {
			DEBUGLOG(("TxnParDSIPSP::Authorize:bank_code [%s]\n", csTmp));
		}

		dPspAmt = (dTxnAmt + dMarkupAmt) * dRate;
		PutField_Double(hContext, "txn_amount", dPspAmt);

		//PSPccy?


		ChannelObjPtr = CreateObj(ChannelPtr, "WEBChannel","UpdateTxnLog");
	        iRet = (unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse));

		if (iRet == PD_OK) {
			DEBUGLOG(("TxnParDSIPSP::Authorize: WEBChannel.UpdateTxnLog Succ\n"));
		}
	}


	FREE_ME(rRecordSet);

DEBUGLOG(("TxnParDSIPSP Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
