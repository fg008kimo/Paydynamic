/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/08/14              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BODepositTrace.h"

static char cDebug;

void BODepositTrace(char cdebug)
{
	cDebug = cdebug;
}

OBJPTR(DB);

int CheckTxnStatus(hash_t *hContext)
{
	int	iRet = PD_OK;
	char	*csTxnId = NULL;
	char	cStatus = 'X';
	char	*csSubStatus = "XXX";

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hash_t *hRec;

DEBUGLOG(("BODepositTrace::CheckTxnStatus() start\n"));

	if (GetField_CString(hContext, "txn_seq", &csTxnId)) {
DEBUGLOG(("txn_seq = [%s]\n", csTxnId));
	} else {
DEBUGLOG(("txn_seq is missing!!!\n"));
ERRLOG("BODepositTrace::CheckTxnStatus() txn_seq is missing!!!\n");
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		if ((*DBObjPtr)(csTxnId, rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Char(hRec, "status", &cStatus)) {
DEBUGLOG(("status = [%c]\n", cStatus));
				}
				if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
DEBUGLOG(("sub_status = [%s]\n", csSubStatus));
				}

				if ((cStatus == PD_TO_PSP) && (csSubStatus = PD_SENT_TO_PSP)) {
DEBUGLOG(("Valid txn status for deposit trace\n"));
				} else {
DEBUGLOG(("Invalid txn status for deposit trace\n"));
					iRet = INT_INVALID_TXN;
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("No record found for txn_seq [%s]\n", csTxnId));
			iRet = INT_INVALID_TXN;
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("iRet = [%d]\n", iRet));
	return iRet;
}


int CheckTraceStatus(hash_t *hContext)
{
	int	iRet = PD_OK;
	char	*csTxnId = NULL;
	char	cPartyType;
	int	iSeq;

	char	cTmp;
	int	iTmp;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hash_t *hRec;

DEBUGLOG(("BODepositTrace::CheckTraceStatus() start\n"));

	if (GetField_CString(hContext, "txn_seq", &csTxnId)) {
DEBUGLOG(("txn_seq = [%s]\n", csTxnId));
	} else {
DEBUGLOG(("txn_seq is missing!!!\n"));
ERRLOG("BODepositTrace::CheckTxnStatus() txn_seq is missing!!!\n");
		iRet = INT_ERR;
	}

	if (GetField_Char(hContext, "party_type", &cPartyType)) {
DEBUGLOG(("curr party_type = [%c]\n", cPartyType));
	} else {
DEBUGLOG(("curr party_type is missing!!!\n"));
ERRLOG("BODepositTrace::CheckTxnStatus() curr party_type is missing!!!\n");
		iRet = INT_ERR;
	}

	if (GetField_Int(hContext, "trace_seq", &iSeq)) {
DEBUGLOG(("curr trace_seq = [%d]\n", iSeq));
	} else {
DEBUGLOG(("curr trace_seq is missing!!!\n"));
ERRLOG("BODepositTrace::CheckTxnStatus() curr trace_seq is missing!!!\n");
		iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBDepositTrace", "GetAllTrace");
		if ((*DBObjPtr)(csTxnId, rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Char(hRec, "party_type", &cTmp)) {
DEBUGLOG(("party_type = [%c]\n", cTmp));
				} else {
DEBUGLOG(("party_type is missing!!!\n"));
					iRet = INT_ERR;
					break;
				}

				if (GetField_Int(hRec, "seq", &iTmp)) {
DEBUGLOG(("seq = [%d]\n", iTmp));
				} else {
DEBUGLOG(("seq is missing!!!\n"));
					iRet = INT_ERR;
					break;
				}

				if ((cPartyType == PD_TYPE_MERCHANT) && (cTmp == PD_TYPE_MERCHANT) && (iTmp != iSeq)) {
DEBUGLOG(("Another merchant deposit trace exists\n"));
					iRet = INT_INVALID_TXN;
					break;
				}

				if (GetField_Char(hRec, "enquiry_status", &cTmp)) {
DEBUGLOG(("enquiry_status = [%c]\n", cTmp));
					if (cTmp == PD_ACCEPT || cTmp == PD_REJECT) {
DEBUGLOG(("Deposit trace already sent to PSP and returned [%s]\n", (cTmp == PD_ACCEPT)? "Success" : "Failed"));
						iRet = INT_INVALID_TXN;
						break;
					}
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("No record found for txn_seq [%s]\n", csTxnId));
			iRet = INT_INVALID_TXN;
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("iRet = [%d]\n", iRet));
	return iRet;
}

