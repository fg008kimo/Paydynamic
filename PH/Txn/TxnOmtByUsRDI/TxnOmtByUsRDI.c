/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/02/16              David Wong
Add return rbd_txn_seq for TxnOmtByUsRDR use       2015/06/10              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsRDI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DEFAULT_DATE_FORMAT "%Y%m%d"
#define PD_DEFAULT_TIME_FORMAT "%H%M%S"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnOmtByUsRDI(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
				hash_t* hRequest,
				hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet;

	char *csOrgTxnSeq;
	char *csServiceCode, *csSubStatus, *csDstTxnId;
	char *csCcy, *csCountry;
	char *csPspCcy;
	char *csTmp;
	char csNewPspTxnSeq[PD_TXN_SEQ_LEN + 1];
	char *csNetCcy;
	char *csUser;
	char csTxnCountry[PD_COUNTRY_LEN + 1];

	int iReturnMerchFee = PD_FALSE;
	int iReleased = PD_FALSE;

	double dTxnAmt = 0.0;
	double dNetAmt = 0.0;
	double dReserveAmt = 0.0;
	double dPspTxnAmt = 0.0;
	double dTmp;

	char cTmp;
	char csDate[PD_DATE_LEN + 1] = "";
	char csTime[PD_TIME_LEN + 1] = "";

	hash_t *hOrgTxn;
	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);

	hash_t *hNewPspTxn;
	hNewPspTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hNewPspTxn, 0);

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);

	hash_t *hTmp2;
	hTmp2 = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp2, 0);

	hash_t *hRec;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	char csTxnDateTime[PD_DATETIME_LEN + 1];

DEBUGLOG(("TxnOmtByUsRDI: Authroize()\n"));

/* get input */
	// get org_txn_seq
	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("Authorize:: org_txn_seq = [%s]\n", csOrgTxnSeq));
		PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
		PutField_Char(hOrgTxn, "status", PD_REVERSED);
		PutField_CString(hOrgTxn, "sub_status", PD_VOID);
	}

	// get return_mfee
	if (GetField_Int(hRequest, "return_mfee", &iReturnMerchFee)) {
		if (iReturnMerchFee) {
DEBUGLOG(("Authorize:: return merchant fee\n"));
		} else {
DEBUGLOG(("Authorize:: not return merchant fee\n"));
		}
	}

	// get remark
	if (GetField_CString(hRequest, "remark", &csTmp)) {
DEBUGLOG(("Authorize:: remark = [%s]\n", csTmp));
		PutField_CString(hContext, "remark", csTmp);
	}

	// get user
	if (GetField_CString(hContext, "update_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user/update_user = [%s]\n", csUser));
		PutField_CString(hContext, "add_user", csUser);
	}

/* get ODI txn header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, rRecordSet);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("Authorize:: client_id = [%s]\n", csTmp));
				PutField_CString(hContext, "merchant_client_id", csTmp);
			}

			if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize:: merchant_id = [%s]\n", csTmp));
				PutField_CString(hContext, "merchant_id", csTmp);
				PutField_CString(hContext, "org_merchant_id", csTmp);
			}

			if (GetField_CString(hRec, "merchant_ref", &csTmp)) {
DEBUGLOG(("Authorize:: merchant_ref = [%s]\n", csTmp));
				PutField_CString(hContext, "merchant_ref", csTmp);
			}

			if (GetField_Double(hRec, "txn_amt", &dTxnAmt)) {
DEBUGLOG(("Authorize:: txn_amt = [%lf]\n", dTxnAmt));
				PutField_Double(hContext, "txn_amt", dTxnAmt);
				// PutField_Double(hContext, "org_txn_amt", dTxnAmt);
			}

			if (GetField_CString(hRec, "service_code", &csServiceCode)) {
DEBUGLOG(("Authorize:: service_code = [%s]\n", csServiceCode));
				PutField_CString(hContext, "service_code", csServiceCode);
				PutField_CString(hContext, "org_service_code", csServiceCode);
			}

			if (GetField_CString(hRec, "net_ccy", &csTmp)) {
DEBUGLOG(("Authorize:: net_ccy = [%s]\n", csTmp));
				PutField_CString(hContext, "net_ccy", csTmp);
			}

			if (GetField_Double(hRec, "net_amt", &dNetAmt)) {
DEBUGLOG(("Authorize:: net_amt = [%lf]\n", dNetAmt));
				PutField_Double(hContext, "org_net_amt", dNetAmt);
			}

			if (GetField_Double(hRec, "reserve_amt", &dReserveAmt)) {
DEBUGLOG(("Authorize:: reserve_amt = [%lf]\n", dReserveAmt));
				PutField_Double(hContext, "reserve_amt", dReserveAmt);
			}

			if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
DEBUGLOG(("Authorize:: sub_status = [%s]\n", csSubStatus));
			}

			if (!strcmp(csSubStatus, PD_RESERVE_RELEASED)) {
				if (GetField_CString(hRec, "reserved_release_date", &csTmp)) {
DEBUGLOG(("Authorize:: reserved_release_date = [%s]\n", csTmp));
					iReleased = PD_TRUE;
				}
			}

			if (GetField_CString(hRec, "dst_txn_id", &csDstTxnId)) {
DEBUGLOG(("Authorize:: dst_txn_id = [%s]\n", csDstTxnId));
				PutField_CString(hNewPspTxn, "org_txn_seq", csDstTxnId);
			}

			if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
DEBUGLOG(("Authorize:: ex_supplier = [%c]\n", cTmp));
				PutField_Char(hContext, "ex_party", cTmp);
			}

			if (GetField_Double(hRec, "ex_rate", &dTmp)) {
DEBUGLOG(("Authorize:: ex_rate = [%lf]\n", dTmp));
				PutField_Double(hContext, "ex_rate", dTmp);
			}
		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction:GetTxnHeader() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* get ODI txn detail */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		RecordSet_Destroy(rRecordSet);
		recordset_init(rRecordSet, 0);
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, rRecordSet);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hRec, "txn_ccy", &csCcy)) {
DEBUGLOG(("Authorize:: txn_ccy = [%s]\n", csCcy));
				PutField_CString(hContext, "org_txn_ccy", csCcy);
				// PutField_CString(hContext, "txn_ccy", csCcy);
				// PutField_CString(hRequest, "txn_ccy", csCcy);
			}

			if (GetField_CString(hRec, "txn_country", &csCountry)) {
DEBUGLOG(("Authorize:: txn_country = [%s]\n", csCountry));
				PutField_CString(hContext, "org_txn_country", csCountry);
				PutField_CString(hContext, "txn_country", csCountry);
				// PutField_CString(hRequest, "txn_country", csCountry);
			}

			if (GetField_CString(hRec, "pay_method", &csTmp)) {
DEBUGLOG(("Authorize:: pay_method = [%s]\n", csTmp));
				// PutField_CString(hContext, "pay_method", csTmp);
			}

			if (GetField_CString(hRec, "bank_acct_num", &csTmp)) {
DEBUGLOG(("Authorize:: bank_acct_num = [%s]\n", csTmp));
				PutField_CString(hContext, "bank_acct_num", csTmp);
			}

			if (GetField_CString(hRec, "deposit_bank_code", &csTmp)) {
DEBUGLOG(("Authorize:: deposit_bank_code = [%s]\n", csTmp));
				PutField_CString(hContext, "deposit_bank_code", csTmp);
			}

			if (GetField_CString(hRec, "deposit_bank", &csTmp)) {
DEBUGLOG(("Authorize:: deposit_bank = [%s]\n", csTmp));
				PutField_CString(hContext, "deposit_bank", csTmp);
			}

			if (GetField_CString(hRec, "deposit_ref", &csTmp)) {
DEBUGLOG(("Authorize:: deposit_ref = [%s]\n", csTmp));
				PutField_CString(hContext, "deposit_ref", csTmp);
			}

			if (GetField_CString(hRec, "bank_code", &csTmp)) {
DEBUGLOG(("Authorize:: bank_code = [%s]\n", csTmp));
				PutField_CString(hContext, "bank_code", csTmp);
			}

			if (GetField_CString(hRec, "bank_name", &csTmp)) {
DEBUGLOG(("Authorize:: bank_name = [%s]\n", csTmp));
				PutField_CString(hContext, "bank_name", csTmp);
			}

			if (GetField_CString(hRec, "language", &csTmp)) {
DEBUGLOG(("Authorize:: language = [%s]\n", csTmp));
				PutField_CString(hContext, "language", csTmp);
			}

			if (GetField_CString(hRec, "encrypt_type", &csTmp)) {
DEBUGLOG(("Authorize:: encrypt_type = [%s]\n", csTmp));
				// PutField_CString(hContext, "encrypt_type", csTmp);
			}

			if (GetField_CString(hRec, "selected_pay_method", &csTmp)) {
DEBUGLOG(("Authorize:: selected_pay_method = [%s]\n", csTmp));
				// PutField_CString(hContext, "selected_pay_method", csTmp);
			}
		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction:GetTxnDetail() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* check return merchant fee */
	if (iRet == PD_OK && !iReturnMerchFee) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		RecordSet_Destroy(rRecordSet);
		recordset_init(rRecordSet, 0);
DEBUGLOG(("Authorize:: Call DBOLTxnElements:GetFeeChgDetailByType()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnElements", "GetFeeChgDetailByType");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_ELEMENT_TXN_FEE, PD_TYPE_MERCHANT, rRecordSet);
		if (iTmpRet == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Double(hRec, "amount", &dTmp)) {
DEBUGLOG(("Authorize:: previous merchant fee = [%lf]\n", dTmp));
					dNetAmt = dNetAmt + dTmp;
DEBUGLOG(("Authorize:: new net_amt = [%lf]\n", dNetAmt));
					PutField_Double(hContext, "org_net_amt", dNetAmt);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

/* update txn amount */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		PutField_Char(hContext, "amt_type", PD_IND_DEBIT);
		PutField_Char(hContext, "party_type", PD_TYPE_MERCHANT);
		PutField_Int(hContext, "reserve_released", iReleased);
DEBUGLOG(("Authorize:: Call BOOLBalance:UpdateTxnAmount()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateTxnAmount");
		iTmpRet = (unsigned long)(*BOObjPtr)(hContext);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: BOOLBalance: UpdateTxnAmount Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: BOOLBalance: UpdateTxnAmount Error\n");
		}
	}

/* prepare update RDI txn header */
	if (iRet == PD_OK) {
		PutField_Double(hContext, "net_amt", dNetAmt);
		PutField_Double(hContext, "display_amt", dNetAmt);
	}

/* create RDI txn details */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		PutField_CString(hContext, "txn_ccy", csCcy);
DEBUGLOG(("Authorize:: Call DBOLTransaction:AddDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "AddDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(hContext);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: AddDetail Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction: AddDetail Error\n");
		}
	}

/* update RDI txn details */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
			PutField_Double(hContext, "open_bal", dTmp);
		}
		if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
			PutField_Double(hContext, "open_bal_settlement", dTmp);
		}
DEBUGLOG(("Authorize:: Call DBOLTransaction:UpdateDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "UpdateDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(hContext);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: UpdateDetail Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction: UpdateDetail Error\n");
		}
	}

/* create RDI-ODI relation */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		hash_destroy(hTmp);
		hash_init(hTmp, 0);
		PutField_Char(hTmp, "party", PD_TYPE_PSP);
		GetField_CString(hContext, "txn_seq", &csTmp);
		PutField_CString(hTmp, "p1_txn_id", csTmp);
		PutField_CString(hTmp, "p2_txn_id", csOrgTxnSeq);
		PutField_Char(hTmp, "txn_level", PD_TXN_LEVEL);
		PutField_Char(hTmp, "relation_type", PD_REL_VOID);
		PutField_CString(hTmp, "create_user", csUser);
DEBUGLOG(("Authorize:: Call DBOLTxnRelation:Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnRelation", "Add");
		iTmpRet = (unsigned long)(*DBObjPtr)(hTmp);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTxnRelation: Add Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTxnRelation:Add Error\n");
		}
	}

/* get OBD txn header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		RecordSet_Destroy(rRecordSet);
		recordset_init(rRecordSet, 0);
DEBUGLOG(("Authorize:: Call DBOLTransaction:GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		iTmpRet = (unsigned long)(*DBObjPtr)(csDstTxnId, rRecordSet);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csDstTxnId));
			hRec = RecordSet_GetFirst(rRecordSet);

			if (GetField_CString(hRec, "net_ccy", &csNetCcy)) {
DEBUGLOG(("Authorize:: net_ccy = [%s]\n", csNetCcy));
			}

			if (GetField_Double(hRec, "txn_amt", &dTmp)) {
DEBUGLOG(("Authorize:: txn_amt = [%lf]\n", dTmp));
				PutField_Double(hNewPspTxn, "txn_amt", dTmp);
			}

			if (GetField_Double(hRec, "net_amt", &dNetAmt)) {
DEBUGLOG(("Authorize:: net_amt = [%lf]\n", dNetAmt));
			}

			if (GetField_Double(hRec, "display_amt", &dTmp)) {
DEBUGLOG(("Authorize:: display_amt = [%lf]\n", dTmp));
				PutField_Double(hNewPspTxn, "display_amt", dTmp);
			}

			if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
DEBUGLOG(("Authorize:: ex_supplier = [%c]\n", cTmp));
				PutField_Char(hNewPspTxn, "ex_supplier", cTmp);
			}

			if (GetField_Double(hRec, "ex_rate", &dTmp)) {
DEBUGLOG(("Authorize:: ex_rate = [%lf]\n", dTmp));
				PutField_Double(hNewPspTxn, "ex_rate", dTmp);
			}
		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csDstTxnId));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction:GetTxnHeader() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* get OBD txn psp detail */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		hash_destroy(hTmp);
		hash_init(hTmp, 0);
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail:GetTxnPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
		iTmpRet = (unsigned long)(*DBObjPtr)(csDstTxnId, hTmp);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize:: record found for [%s]\n", csDstTxnId));

			if (GetField_CString(hTmp, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize:: psp_id = [%s]\n", csTmp));
				PutField_CString(hNewPspTxn, "org_psp_id", csTmp);
				PutField_CString(hNewPspTxn, "psp_id", csTmp);
			}

			if (GetField_CString(hTmp, "baid", &csTmp)) {
DEBUGLOG(("Authorize:: baid = [%s]\n", csTmp));
				PutField_CString(hNewPspTxn, "org_baid", csTmp);
				PutField_CString(hNewPspTxn, "baid", csTmp);
			}

			if (GetField_CString(hTmp, "txn_ccy", &csPspCcy)) {
DEBUGLOG(("Authorize:: psp_txn_ccy = [%s]\n", csPspCcy));
				PutField_CString(hNewPspTxn, "org_dst_txn_ccy", csPspCcy);
				PutField_CString(hNewPspTxn, "org_txn_ccy", csPspCcy);
				PutField_CString(hNewPspTxn, "txn_ccy", csPspCcy);
			}

			if (GetField_Double(hTmp, "txn_amount", &dPspTxnAmt)) {
DEBUGLOG(("Authorize:: psp_txn_amt = [%lf]\n", dPspTxnAmt));
				PutField_Double(hNewPspTxn, "org_dst_net_amt", dPspTxnAmt);
				PutField_Double(hNewPspTxn, "txn_amount", dPspTxnAmt);
			}

			if (GetField_CString(hTmp, "bank_code", &csTmp)) {
DEBUGLOG(("Authorize:: bank_code = [%s]\n", csTmp));
				PutField_CString(hNewPspTxn, "bank_code", csTmp);

				// get bank country
DEBUGLOG(("Authorize:: call DBBankDesc::GetBankCountry()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBBankDesc", "GetBankCountry");
				iTmpRet = (unsigned long)(*DBObjPtr)(csTmp, csTxnCountry);
				if (iTmpRet != FOUND) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize:: call DBBankDesc::GetBankCountry() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsRDI:: Authorize:: call DBBankDesc::GetBankCountry() FAILURE!!!\n");
				} else {
					PutField_CString(hNewPspTxn, "org_txn_country", csTxnCountry);
				}
			}

			if (GetField_CString(hTmp, "bank_acct_num", &csTmp)) {
DEBUGLOG(("Authorize:: bank_acct_num = [%s]\n", csTmp));
				PutField_CString(hNewPspTxn, "bank_acct_num", csTmp);
			}
		} else {
DEBUGLOG(("Authorize:: record not found for [%s]\n", csDstTxnId));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTxnPspDetail:GetTxnPspDetail() record not found\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

/* create RBD txn header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		PutField_Int(hNewPspTxn, "db_commit", PD_FALSE);

DEBUGLOG(("Authorize:: Call DBOLTxnSeq:GetNextOmtTxnSeq()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
		strcpy((char*)csNewPspTxnSeq, (*DBObjPtr)());

DEBUGLOG(("Authorize:: txn_seq = [%s]\n", csNewPspTxnSeq));
		PutField_CString(hNewPspTxn, "txn_seq", csNewPspTxnSeq);
		PutField_CString(hContext, "rbd_txn_seq", csNewPspTxnSeq);

		if (GetField_CString(hContext, "channel_code", &csTmp)) {
DEBUGLOG(("Authorize:: channel_code = [%s]\n", csTmp));
			PutField_CString(hNewPspTxn, "channel_code", csTmp);
		}

DEBUGLOG(("Authorize:: status = [%c]\n", PD_TO_PSP));
		PutField_Char(hNewPspTxn, "status", PD_TO_PSP);

DEBUGLOG(("Authorize:: txn_code = [%s]\n", "RBD"));
		PutField_CString(hNewPspTxn, "txn_code", "RBD"); // to be modified

DEBUGLOG(("Authorize:: process_type = [%s]\n", PD_PROCESS_TYPE_DEF));
		PutField_CString(hNewPspTxn, "process_type", PD_PROCESS_TYPE_DEF);

DEBUGLOG(("Authorize:: process_code = [%s]\n", PD_PROCESS_CODE_DEF));
		PutField_CString(hNewPspTxn, "process_code", PD_PROCESS_CODE_DEF);

		if (GetField_CString(hContext, "PHDATE", &csTmp)) {
DEBUGLOG(("Authorize:: host_posting_date = [%s]\n", csTmp));
			PutField_CString(hNewPspTxn, "host_posting_date", csTmp);
		}

DEBUGLOG(("Authorize:: internal_code = [%d]\n", 0));
		PutField_Int(hNewPspTxn, "internal_code", 0);

DEBUGLOG(("Authorize:: response_code = [%s]\n", "0"));
		PutField_CString(hNewPspTxn, "response_code", "0");

		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
DEBUGLOG(("Authorize:: local_tm_date = [%s]\n", csTmp));
			PutField_CString(hNewPspTxn, "local_tm_date", csTmp);
			strcpy(csTxnDateTime, csTmp);
			PutField_CString(hNewPspTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hNewPspTxn, "tm_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
DEBUGLOG(("Authorize:: local_tm_time = [%s]\n", csTmp));
			PutField_CString(hNewPspTxn, "local_tm_time", csTmp);
			strcat(csTxnDateTime, csTmp);
			PutField_CString(hNewPspTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hNewPspTxn, "tm_time", csTmp);
		}

DEBUGLOG(("Authorize:: recon_status = [%c]\n", PD_UNRECONCILED));
		PutField_Char(hNewPspTxn, "recon_status", PD_UNRECONCILED);

DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
		PutField_CString(hNewPspTxn, "add_user", csUser);

DEBUGLOG(("Authorize:: Call DBOLTransaction:Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Add");
		iTmpRet = (unsigned long)(*DBObjPtr)(hNewPspTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: Add Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction:Add Error\n");
		}
	}

/* update txn amount */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		PutField_Char(hNewPspTxn, "amt_type", PD_IND_DEBIT);
		PutField_Char(hNewPspTxn, "party_type", PD_TYPE_PSP);
DEBUGLOG(("Authorize:: Call BOOLBalance:UpdateTxnAmount()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateTxnAmount");
		iTmpRet = (unsigned long)(*BOObjPtr)(hNewPspTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: BOOLBalance: UpdateTxnAmount Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: BOOLBalance: UpdateTxnAmount Error\n");
		} else {
			if (GetField_Double(hNewPspTxn, "balance", &dTmp)) {
				PutField_Double(hNewPspTxn, "bal", dTmp);
			}
		}
	}

/* create RBD txn psp detail */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		time_t tNow = time(NULL);
		struct tm tStruct = *localtime(&tNow);
		strftime(csDate, sizeof(csDate), PD_DEFAULT_DATE_FORMAT, &tStruct);
		strftime(csTime, sizeof(csTime), PD_DEFAULT_TIME_FORMAT, &tStruct);
		PutField_CString(hNewPspTxn, "txn_date", csDate);
		PutField_CString(hNewPspTxn, "txn_time", csTime);
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail:Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
		iTmpRet = (unsigned long)(*DBObjPtr)(hNewPspTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTxnPspDetail: Add Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTxnPspDetail: Add Error\n");
		}
	}

/* update RBD txn psp detail */

/* create RBD txn elements */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		hash_destroy(hTmp);
		hash_init(hTmp, 0);
		hash_destroy(hTmp2);
		hash_init(hTmp2, 0);
		PutField_CString(hTmp, "txn_seq", csNewPspTxnSeq);
		PutField_CString(hTmp, "org_txn_seq", csDstTxnId);
		PutField_CString(hTmp2, "org_txn_code", "OBD"); // to be modified
DEBUGLOG(("Authorize:: Call TxnOmtByUsVOT:GetTxnInfo()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsVOT", "GetTxnInfo");
		iTmpRet = (unsigned long)(*TxnObjPtr)(csDstTxnId, hTmp, hTmp2);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: TxnOmtByUsVOT: GetTxnInfo Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: TxnOmtByUsVOT:GetTxnInfo Error\n");
		}

DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
DEBUGLOG(("Authorize:: Call BOOLTxnElements:VoidOrgTxnElements()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLTxnElements", "VoidOrgTxnElements");
		iTmpRet = (unsigned long)(*BOObjPtr)(hTmp, hTmp2);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: TxnOmtByUsVOT: GetTxnInfo Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: TxnOmtByUsVOT:GetTxnInfo Error\n");
		}
	}

/* update RBD txn header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));

DEBUGLOG(("Authorize:: status = [%c]\n", PD_COMPLETE));
		PutField_Char(hNewPspTxn, "status", PD_COMPLETE);

DEBUGLOG(("Authorize:: ar_ind = [%c]\n", PD_ACCEPT));
		PutField_Char(hNewPspTxn, "ar_ind", PD_ACCEPT);

DEBUGLOG(("Authorize:: sub_status = [%s]\n", PD_APPROVED));
		PutField_CString(hNewPspTxn, "sub_status", PD_APPROVED);

DEBUGLOG(("Authorize:: net_amt = [%lf]\n", dNetAmt));
		PutField_Double(hNewPspTxn, "net_amt", dNetAmt);

DEBUGLOG(("Authorize:: net_ccy = [%s]\n", csNetCcy));
		PutField_CString(hNewPspTxn, "net_ccy", csNetCcy);

DEBUGLOG(("Authorize:: Call DBSystemControl:GetApprovalDT()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBSystemControl", "GetApprovalDT");
		(*DBObjPtr)(hNewPspTxn);

DEBUGLOG(("Authorize:: Call DBOLTransaction:Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iTmpRet = (unsigned long)(*DBObjPtr)(hNewPspTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: Update Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction:Update Error\n");
		}
	}

/* update ODI txn header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
DEBUGLOG(("Authorize:: Call DBOLTransaction:Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iTmpRet = (unsigned long)(*DBObjPtr)(hOrgTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: Update Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction: Update Error\n");
		}
	}

/* update OBD txn_header */
	if (iRet == PD_OK) {
DEBUGLOG(("---------- ---------- ---------- ---------- ----------\n"));
		PutField_CString(hOrgTxn, "txn_seq", csDstTxnId);
DEBUGLOG(("Authorize:: Call DBOLTransaction:Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iTmpRet = (unsigned long)(*DBObjPtr)(hOrgTxn);
		if (iTmpRet != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBOLTransaction: Update Error\n"));
ERRLOG("TxnOmtByUsRDI: Authorize:: DBOLTransaction: Update Error\n");
		}
	}

	hash_destroy(hOrgTxn);
	FREE_ME(hOrgTxn);
	hash_destroy(hNewPspTxn);
	FREE_ME(hNewPspTxn);
	hash_destroy(hTmp);
	FREE_ME(hTmp);
	hash_destroy(hTmp2);
	FREE_ME(hTmp2);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsRDI Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}
