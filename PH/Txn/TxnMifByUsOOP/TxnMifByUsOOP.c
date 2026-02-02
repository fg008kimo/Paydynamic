/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/23              David Wong
mantis 1401, 1402                                  2016/03/08              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMifByUsOOP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMifByUsOOP(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	int iTmpRet;

	char *csTmp = NULL;

	char *csIxxTxnId = NULL;
	char *csUpdateUser = NULL;
	char *csPspId = NULL;
	char *csBaid = NULL;
	char *csBankCode = NULL;
	char *csBankAcctNum = NULL;
	char csTxnCountry[PD_COUNTRY_LEN + 1];
	char *csTxnCcy = NULL;
	char csWtiTxnId[PD_TXN_SEQ_LEN + 1];
	char csTxnDateTime[PD_DATETIME_LEN + 1];
	char *csIpAddr = NULL;
	char *csBankAcctType = NULL;
	char *csRemark = NULL;
	char *csReportDate = NULL;
	char cExParty = PD_INT_EX;
	char csBatchSeq[PD_TXN_SEQ_LEN + 1];
//	char csDefaultPspId[PD_PSP_ID_LEN + 1];
	double dTxnAmt = 0.0;
	double dExRate = 1.0;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxn, 0);

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);

	hash_t *hTxnDetail;
	hTxnDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnDetail, 0);

/* Sweep In from Online (IXX) txn_seq */
	if (GetField_CString(hContext, "txn_seq", &csIxxTxnId)) {
DEBUGLOG(("Authorize:: txn_seq = [%s]\n", csIxxTxnId));
	} else {
DEBUGLOG(("Authorize:: txn_seq not found!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: txn_seq not found!!\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* add_user */
	if (GetField_CString(hContext, "add_user", &csUpdateUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUpdateUser));
		PutField_CString(hTxn, "add_user", csUpdateUser);
		PutField_CString(hTxn, "update_user", csUpdateUser);
	} else {
DEBUGLOG(("Authorize:: add_user not found!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: add_user not found!!\n");
		iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* client_ip */
	if (GetField_CString(hRequest, "ip_addr", &csIpAddr)) {
DEBUGLOG(("Authorize:: ip_addr = [%s]\n", csIpAddr));
		PutField_CString(hTxn, "ip_addr", csIpAddr);
	}

/* remark */
	if (GetField_CString(hContext, "remark", &csRemark)) {
DEBUGLOG(("Authorize:: remark = [%s]\n", csRemark));
		PutField_CString(hTxn, "remark", csRemark);
	}

/* report_date */
	if (GetField_CString(hContext, "report_date", &csReportDate)) {
DEBUGLOG(("Authorize:: report_date = [%s]\n", csReportDate));
		PutField_CString(hTxn, "report_date", csReportDate);
	}

/* psp_id */
	if (GetField_CString(hContext, "psp_id", &csPspId)) {
DEBUGLOG(("Authorize:: psp_id = [%s]\n", csPspId));
		PutField_CString(hTxn, "psp_id", csPspId);
	} else {
DEBUGLOG(("Authorize:: psp_id not found!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: psp_id not found!!\n");
		iRet = INT_PSP_ID_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* txn_ccy */
	if (GetField_CString(hContext, "txn_ccy", &csTxnCcy)) {
DEBUGLOG(("Authorize:: txn_ccy = [%s]\n", csTxnCcy));
		PutField_CString(hTxn, "txn_ccy", csTxnCcy);
	} else {
DEBUGLOG(("Authorize:: txn_ccy not found!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: txn_ccy not found!!\n");
		iRet = INT_CURRENCY_CODE_NOT_FOUND;;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* txn_amt */
	if (GetField_Double(hContext, "txn_amt", &dTxnAmt)) {
DEBUGLOG(("Authorize:: txn_amt = [%f]\n", dTxnAmt));
		PutField_Double(hTxn, "txn_amt", dTxnAmt);
		PutField_Double(hTxn, "display_amt", dTxnAmt);
		PutField_Double(hTxn, "txn_amount", dTxnAmt);
	} else {
DEBUGLOG(("Authorize:: txn_amt not found!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: txn_amt not found!!\n");
		iRet = INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
	}

/* ex_rate */
	if (GetField_Double(hContext, "ex_rate", &dExRate)) {
DEBUGLOG(("Authorize:: ex_rate = [%f]\n", dExRate));
	}

/* ex_party */
	if (GetField_Char(hContext, "ex_party", &cExParty)) {
DEBUGLOG(("Authorize:: ex_party = [%c]\n", cExParty));
	}

/* Get default PSP ID */
/*
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBMiOLDefDefaultBIT::GetDefaultPspId()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMiOLDefDefaultBIT", "GetDefaultPspId");
		iTmpRet = (unsigned long)((*DBObjPtr)(csPspId, csDefaultPspId));
		if (iTmpRet != FOUND) {
DEBUGLOG(("Authorize:: Call DBMiOLDefDefaultBIT::GetDefaultPspId() failed\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBMiOLDefDefaultBIT::GetDefaultPspId() failed\n");
			iRet = INT_INVALID_BAID;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: default_psp_id for BIT = [%s]\n", csDefaultPspId));
			PutField_CString(hTxn, "psp_id", csDefaultPspId);
		}
	}
*/

/* Get BIT baid */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBaidByPspCategory()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBaidByPspCategory");
//		iRet = (unsigned long)((*DBObjPtr)(csDefaultPspId, (const char*)PD_BAID_CAT_BIT, hTmp));
		iRet = (unsigned long)((*DBObjPtr)(csPspId, (const char*)PD_BAID_CAT_BIT, hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBaidByPspCategory() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLBankAcctId::GetBaidByPspCategory() failed!!\n");
			iRet = INT_INVALID_BAID;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			if (GetField_CString(hTmp, "baid", &csBaid)) {
DEBUGLOG(("Authorize:: baid = [%s]\n", csBaid));
				PutField_CString(hTxn, "baid", csBaid);
			}
		}
	}

/* Get BIT baid detail  */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBankAcctIdDtl()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBankAcctIdDtl");
		iRet = (unsigned long)((*DBObjPtr)(csBaid, hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBankAcctIdDtl() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLBankAcctId::GetBankAcctIdDtl() failed!!\n");
			iRet = INT_BANK_ACCT_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			/* bank code */

			if (GetField_CString(hTmp, "int_bank_code", &csBankCode)) {
DEBUGLOG(("Authorize:: bank_code = [%s]\n", csBankCode));
				PutField_CString(hTxn, "bank_code", csBankCode);
			}

			/* bank_acct_num */

			if (GetField_CString(hTmp, "bank_acct_num", &csBankAcctNum)) {
DEBUGLOG(("Authorize:: bank_acct_num = [%s]\n", csBankAcctNum));
				PutField_CString(hTxn, "bank_acct_num", csBankAcctNum);
			}
		}
	}

/* txn_country */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBankAcctIdCountry()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBankAcctIdCountry");
		iTmpRet = (unsigned long)((*DBObjPtr)(csBaid, csTxnCountry));
		if (iTmpRet != FOUND) {
DEBUGLOG(("Authorize:: Call DBOLBankAcctId::GetBankAcctIdCountry() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLBankAcctId::GetBankAcctIdCountry() failed!!\n");
			iRet = INT_BAID_COUNTRY_NOT_FOUND;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: txn_country = [%s]\n", csTxnCountry));
			PutField_CString(hTxn, "txn_country", csTxnCountry);
		}
	}

/* bank_acct_type */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

DEBUGLOG(("Authorize:: Call DBOLPspDetail::GetPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail", "GetPspDetail");
		iRet = (unsigned long)((*DBObjPtr)(csPspId, hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLPspDetail::GetPspDetail() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLPspDetail::GetPspDetail() failed!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		} else {
			if (GetField_CString(hTmp, "bank_acct_type", &csBankAcctType)) {
DEBUGLOG(("Authorize:: bank_acct_type = [%s]\n", csBankAcctType));
				PutField_CString(hTxn, "bank_acct_type", csBankAcctType);
			}
		}
	}

/* WTI txn_seq */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTxnSeq::GetNextOmtTxnSeq()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
		strcpy((char*)csWtiTxnId, (*DBObjPtr)());
		PutField_CString(hTxn, "txn_seq", csWtiTxnId);
DEBUGLOG(("Authorize:: Call DBOLTxnSeq::GetNextOmtTxnSeq() WTI txn_seq = [%s]\n", csWtiTxnId));
	}

/* Add txn_header */
	if (iRet == PD_OK) {
		PutField_Int(hTxn, "db_commit", PD_FALSE);
		PutField_CString(hTxn, "channel_code", PD_CHANNEL_OMT);
		PutField_Char(hTxn, "status", PD_PROCESSING);
		PutField_CString(hTxn, "txn_code", PD_MI_TXN_CODE_BAID_BAL_TRF_IN_IN_TRAN);
		PutField_CString(hTxn, "process_type", PD_PROCESS_TYPE_DEF);
		PutField_CString(hTxn, "process_code", PD_PROCESS_CODE_DEF);
		if (GetField_CString(hContext, "PHDATE", &csTmp)) {
			PutField_CString(hTxn, "host_posting_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
			PutField_CString(hTxn, "local_tm_date", csTmp);
			strcpy(csTxnDateTime, csTmp);
			PutField_CString(hTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hTxn, "tm_date", csTmp);
			PutField_CString(hTxn, "txn_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
			PutField_CString(hTxn, "local_tm_time", csTmp);
			strcat(csTxnDateTime, csTmp);
			PutField_CString(hTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hTxn, "tm_time", csTmp);
			PutField_CString(hTxn, "txn_time", csTmp);
		}
		PutField_Int(hTxn, "internal_code", 0);
		PutField_CString(hTxn, "response_code", "0");

DEBUGLOG(("Authorize:: Call DBOLTransaction::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Add");
		iRet = (unsigned long)((*DBObjPtr)(hTxn));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction::Add() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTransaction::Add() failed!!\n");
			iRet = INT_ERR;
		}
	}

/* Update balance */
	if (iRet == PD_OK) {
		PutField_Char(hTxn, "amt_type", PD_IND_DEBIT);
		// For pending fund, debit account balance instead of in-transit balance
		if (!strcmp(csBankAcctType, PD_NATURE_PENDING_FUND)) {
			PutField_CString(hTxn, "pool", PD_ACCT_BAL_POOL);
		} else {
			PutField_CString(hTxn, "pool", PD_INTRANSIT_POOL);
		}

DEBUGLOG(("Authorize:: Call BOOLBalance::UpdateAmount()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
		iRet = (unsigned long)((*BOObjPtr)(hTxn));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call BOOLBalance::UpdateAmount() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call BOOLBalance::UpdateAmount failed!!\n");
			iRet = INT_ERR;
		}
        }

/* Add txn_detail */
	if (iRet == PD_OK) {
		PutField_CString(hTxnDetail, "txn_seq", csWtiTxnId);
		PutField_CString(hTxnDetail, "txn_ccy", csTxnCcy);
		if (csRemark != NULL) {
			PutField_CString(hTxnDetail, "remark", csRemark);
		}
		PutField_CString(hTxnDetail, "add_user", csUpdateUser);
		PutField_CString(hTxnDetail, "update_user", csUpdateUser);

DEBUGLOG(("Authorize:: Call DBOLTransaction::AddDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "AddDetail");
		iRet = (unsigned long)((*DBObjPtr)(hTxnDetail));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction::AddDetail() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTransaction::AddDetail() failed!!\n");
			iRet = INT_ERR;
		}
	}

/* Add txn_psp_detail */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail::Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
		iRet = (unsigned long)((*DBObjPtr)(hTxn));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail::Add() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTxnPspDetail::Add() failed!!\n");
			iRet = INT_ERR;
		}
	}

/* Add txn_elements */
	if (iRet == PD_OK) {
		// For pending fund, debit account balance instead of in-transit balance
		if (!strcmp(csBankAcctType, PD_NATURE_PENDING_FUND)) {
			PutField_CString(hTxn, "txn_element_type", PD_ELEMENT_TXN_AMT);
		} else {
			PutField_CString(hTxn, "txn_element_type", PD_ELEMENT_IN_TRANSIT);
		}
		PutField_CString(hTxn, "amount_type", PD_DR);

DEBUGLOG(("Authorize:: Call BOOLTxnElements::AddPspTxnElement()\n"));
		BOObjPtr = CreateObj(BOPtr, "BOOLTxnElements", "AddPspTxnElement");
		iRet = (unsigned long)((*BOObjPtr)(hTxn));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call BOOLTxnElements::AddPspTxnElement() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call BOOLTxnElements::AddPspTxnElement() failed!!\n");
			iRet = INT_ERR;
		}
	}

/* Update txn_header */
	if (iRet == PD_OK) {
		PutField_Char(hTxn, "status", PD_COMPLETE);
		PutField_Char(hTxn, "ar_ind", PD_ACCEPT);
		PutField_CString(hTxn, "sub_status", PD_APPROVED);
		PutField_Double(hTxn, "net_amt", dTxnAmt);
		PutField_CString(hTxn, "net_ccy", csTxnCcy);
		PutField_Double(hTxn, "reserve_amt", 0.0);
		PutField_Double(hTxn, "ex_rate", dExRate);
		PutField_Char(hTxn, "ex_supplier", cExParty);
		PutField_Char(hTxn, "recon_status", PD_RECON_NOT_REQ);

DEBUGLOG(("Authorize:: Call DBOLTransaction::Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iRet = (unsigned long)((*DBObjPtr)(hTxn));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction::Update() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTransaction::Update() failed!!\n");
			iRet = INT_ERR;
		}
	}

/* Update txn_header (IXX) */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

		PutField_CString(hTmp, "txn_seq", csIxxTxnId);
		PutField_CString(hTmp, "org_txn_seq", csWtiTxnId);

DEBUGLOG(("Authorize:: Call DBOLTransaction::Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iRet = (unsigned long)((*DBObjPtr)(hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction::Update() failed!!\n"));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTransaction::Update() failed!!\n");
			iRet = INT_ERR;
                }
	}

/* Add txn relation */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

		PutField_Char(hTmp, "party", PD_TYPE_PSP);
		PutField_CString(hTmp, "p1_txn_id", csWtiTxnId);
		PutField_CString(hTmp, "p2_txn_id", csIxxTxnId);
		PutField_Char(hTmp, "txn_level", PD_TXN_LEVEL);
		PutField_Char(hTmp, "relation_type", PD_REL_BAL_TRF);
		PutField_CString(hTmp, "create_user", csUpdateUser);

DEBUGLOG(("Authorize:: Call DBOLTxnRelation::Add() [%s][%s]\n", csWtiTxnId, csIxxTxnId));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnRelation", "Add");
		iRet = (unsigned long)((*DBObjPtr)(hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTxnRelation::Add() [%s][%s] failed!!\n", csWtiTxnId, csIxxTxnId));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLTxnRelation::Add() [%s][%s] failed!!\n", csWtiTxnId, csIxxTxnId);
			iRet = INT_ERR;
		}
	}

/* Add batch txn relation */
	if (iRet == PD_OK) {
		hash_destroy(hTmp);
		hash_init(hTmp, 0);

DEBUGLOG(("Authorize:: Call DBOLTxnSeq::GetNextActionBatchSeq()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextActionBatchSeq");
		strcpy(csBatchSeq, (*DBObjPtr)());
		PutField_CString(hTmp, "batch_txn_seq", csBatchSeq);
DEBUGLOG(("Authorize:: Call DBOLTxnSeq::GetNextActionBatchSeq() new_batch_id = [%s]\n", csBatchSeq));

		PutField_Char(hTmp, "batch_type", PD_GENERAL);
		PutField_Char(hTmp, "batch_sub_type", PD_GENERAL_BAL_TRF);
		PutField_CString(hTmp, "batch_id", csBatchSeq);
		PutField_Char(hTmp, "txn_level", PD_TXN_LEVEL);
		PutField_Int(hTmp, "is_input_txn", 1);
		PutField_Int(hTmp, "is_regen_txn", 0);
		PutField_CString(hTmp, "create_user", csUpdateUser);

		// From Txn Seq
		PutField_CString(hTmp, "txn_id", csWtiTxnId);

DEBUGLOG(("Authorize:: Call DBOLBatchTxnRelation::Add() fr_txn_seq = [%s]\n", csWtiTxnId));
		DBObjPtr = CreateObj(DBPtr, "DBOLBatchTxnRelation", "Add");
		iRet = (unsigned long)((*DBObjPtr)(hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBatchTxnRelation::Add() fr_txn_seq = [%s] failed!!\n", csWtiTxnId));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLBatchTxnRelation::Add() fr_txn_seq = [%s] failed!!\n", csWtiTxnId);
			iRet = INT_ERR;
		}

		// To Txn Seq
		PutField_CString(hTmp, "txn_id", csIxxTxnId);

DEBUGLOG(("Authorize:: Call DBOLBatchTxnRelation::Add() to_txn_seq = [%s]\n", csIxxTxnId));
		DBObjPtr = CreateObj(DBPtr, "DBOLBatchTxnRelation", "Add");
		iRet = (unsigned long)((*DBObjPtr)(hTmp));
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLBatchTxnRelation::Add() to_txn_seq = [%s] failed!!\n", csIxxTxnId));
ERRLOG("TxnMifByUsOOP::Authorize:: Call DBOLBatchTxnRelation::Add() to_txn_seq = [%s] failed!!\n", csIxxTxnId);
			iRet = INT_ERR;
		}
	}

	hash_destroy(hTxn);
	FREE_ME(hTxn);

	hash_destroy(hTmp);
	FREE_ME(hTmp);

	hash_destroy(hTxnDetail);
	FREE_ME(hTxnDetail);

DEBUGLOG(("TxnMifByUsOOP Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

