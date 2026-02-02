/*
PDProTech (c)2016. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/06/24              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVBF.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

int GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn);

void TxnMgtByUsVBF(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext,
		hash_t *hRequest,
		hash_t *hResponse)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_FOUND;
	char	*csOrgTxnSeq = NULL, *csOrgTxnSeqTo = NULL;
	char	*csVoidTxnSeq = NULL;
	char	csVoidTxnSeqTo[PD_TXN_SEQ_LEN + 1];
	int	iReturnMerchFee = PD_FALSE, iReturnToMerchFee = PD_FALSE;
	char	*csRemark = NULL;
	char	*csUser = NULL;
	char	*csTmp = NULL;
	double	dTmp = 0.0;

// for txn info
	char	*csMid = NULL;
	char	*csNetCcy = NULL;
	char	*csCountry = NULL;
	char	*csService = NULL;

// for txn element
	double	dAmount = 0.0;
	char	*csCcy = NULL;
	char	*csAmtType = NULL;
	double	dRate = 0.0;
	double	dTxnAmount = 0.0;
	double	dNetAmount = 0.0;
	double	dFee = 0.0;
	int	iAffectFIN = PD_FALSE;
	int	iAffectPOR = PD_FALSE;
	int	iAffectFLT = PD_FALSE;

// for calculate balance
	double	dAvaPOBal = 0.0;
	double	dRemainTxnAmt = 0.0;
	double	dDeductFundin = 0.0;
	double	dDeductResvPO = 0.0;
	double	dDeductPrevFt = 0.0;
	double	dOrgDeductPrevFt = 0.0;
	double	dOrgDeductResvPO = 0.0;
	double	dOrgDeductFundin = 0.0;

// OrgTxn	-- Original sender transaction to be voided
// OrgTxnTo	-- Original recipient transaction to be voided
// hVoidTxn	-- Transaction to void original sender transaction
// hVoidTxnTo	-- Transaction to void original recipient transaction

	hash_t *hOrgTxn;
	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);

	hash_t *hOrgTxnTo;
	hOrgTxnTo = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxnTo, 0);

	recordset_t *rOrgTxnEle;
	rOrgTxnEle = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rOrgTxnEle, 0);

	recordset_t *rOrgTxnToEle;
	rOrgTxnToEle = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rOrgTxnToEle, 0);

	hash_t *hTmp;
	hTmp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTmp, 0);

	hash_t *hVoidTxnEle;
	hVoidTxnEle = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hVoidTxnEle, 0);

	hash_t *hVoidTxnToEle;
	hVoidTxnToEle = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hVoidTxnToEle, 0);

	hash_t *hTxnEle;

DEBUGLOG(("Authroize\n"));
DEBUGLOG(("Authroize:: Void RTF\n"));

	if (GetField_CString(hContext, "from_txn_seq", &csVoidTxnSeq)) {
DEBUGLOG(("Authroize:: from_txn_seq = [%s]\n", csVoidTxnSeq));
		PutField_CString(hResponse, "txn_seq_tf", csVoidTxnSeq);
	} else {
DEBUGLOG(("Authroize:: from_txn_seq not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: from_txn_seq not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// sender transaction id to be voided
	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("Authroize:: org_txn_seq = [%s]\n", csOrgTxnSeq));
	} else {
DEBUGLOG(("Authroize:: org_txn_seq not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: org_txn_seq not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// recipient transaction id to be voided
	if (GetField_CString(hContext, "to_txn_seq", &csOrgTxnSeqTo)) {
DEBUGLOG(("Authroize:: to_txn_seq = [%s]\n", csOrgTxnSeqTo));
	} else {
DEBUGLOG(("Authroize:: to_txn_seq not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: to_txn_seq not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// return sender transaction fee or not
	if (GetField_Int(hRequest, "return_mfee", &iReturnMerchFee)) {
DEBUGLOG(("Authroize:: return_mfee = [%d]\n", iReturnMerchFee));
	} else {
DEBUGLOG(("Authroize:: return_mfee not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: return_mfee not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// return recipient transaction fee or not
	if (GetField_Int(hRequest, "return_to_mfee", &iReturnToMerchFee)) {
DEBUGLOG(("Authroize:: return_to_mfee = [%d]\n", iReturnToMerchFee));
	} else {
DEBUGLOG(("Authroize:: return_to_mfee not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: return_to_mfee not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	// remark 
	if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("Authroize:: remark = [%s]\n", csRemark));
	} else {
DEBUGLOG(("Authroize:: remark not found\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: remark not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (GetField_CString(hContext, "update_user", &csUser)) {
DEBUGLOG(("Authorize:: update_user = [%s]\n", csUser));
	} else {
DEBUGLOG(("Authorize:: update_user = [%s] (default)\n", PD_UPDATE_USER));
		strcpy(csUser, PD_UPDATE_USER);
	}

// lock FROM record
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (FROM) Call DBTransaction:MatchRespTxn\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MatchRespTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_COMPLETE);
		if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("Authroize:: cannot lock FROM record\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: cannot lock FROM record\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

// lock TO record
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call DBTransaction:MatchRespTxn\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MatchRespTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeqTo, PD_COMPLETE);
		if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("Authroize:: cannot lock TO record\n"));
ERRLOG("TxnMgtByUsVBF:: Authroize:: cannot lock TO record\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

// get FROM txn info (for Void FROM txn_header)
	if (iRet == PD_OK) {
		iRet = GetTxnInfo((const unsigned char*)csOrgTxnSeq, hOrgTxn);
	}

// lock FROM txn balance
	if (iRet == PD_OK) {
		if (GetField_CString(hOrgTxn, "merchant_id", &csMid)) {
DEBUGLOG(("Authorize:: FROM Merchant = [%s]\n", csMid));
			PutField_CString(hVoidTxnEle, "merchant_id", csMid);
		}
		if (GetField_CString(hOrgTxn, "net_ccy", &csNetCcy)) {
DEBUGLOG(("Authorize:: FROM Ccy = [%s]\n", csNetCcy));
			PutField_CString(hVoidTxnEle, "txn_ccy", csNetCcy);
		}
		if (GetField_CString(hOrgTxn, "txn_country", &csCountry)) {
DEBUGLOG(("Authorize:: FROM Country = [%s]\n", csCountry));
			PutField_CString(hVoidTxnEle, "txn_country", csCountry);
		}
		if (GetField_CString(hOrgTxn, "service_code", &csService)) {
DEBUGLOG(("Authorize:: FROM Service = [%s]\n", csService));
			PutField_CString(hVoidTxnEle, "service_code", csService);
		}

DEBUGLOG(("Authorize:: (FROM) Call DBMerchantBalance:GetOpenBalanceForUpdate\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchantBalance", "GetOpenBalanceForUpdate");
		iRet = (unsigned long)(*DBObjPtr)(hOrgTxn,
				csMid,
				csNetCcy,
				csCountry,
				csService);
		if (iRet == PD_OK) {
			if (GetField_Double(hOrgTxn, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize:: FROM merchant_open_bal = [%lf]\n", dTmp));
				PutField_Double(hVoidTxnEle, "open_bal", dTmp);
			}
			if (GetField_Double(hOrgTxn, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize:: FROM merchant_open_bal_settlement = [%lf]\n", dTmp));
				PutField_Double(hVoidTxnEle, "open_bal_settlement", dTmp);
			}
		} else {
DEBUGLOG(("Authorize:: (FROM) Call DBMerchantBalance:GetOpenBalanceForUpdate FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (FROM) Call DBMerchantBalance:GetOpenBalanceForUpdate FAILED\n");
			iRet = INT_ERR;
		}
	}

// get FROM txn elements & prepare Void FROM txn elements
	if (iRet == PD_OK) {
		dNetAmount = 0.0;
		dFee = 0.0;
		iAffectFIN = PD_FALSE;
		iAffectPOR = PD_FALSE;
		iAffectFLT = PD_FALSE;

		PutField_Int(hVoidTxnEle, "db_commit", PD_FALSE);
		PutField_CString(hVoidTxnEle, "txn_seq", csVoidTxnSeq);
		PutField_Char(hVoidTxnEle, "dc_type", PD_IND_CREDIT);
		PutField_Int(hVoidTxnEle, "void_flag", PD_TRUE);
		PutField_CString(hVoidTxnEle, "add_user", csUser);
		PutField_CString(hVoidTxnEle, "update_user", csUser);

DEBUGLOG(("Authorize:: (FROM) Call DBTxnElements:GetAllFeeChgDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnElements", "GetAllFeeChgDetail");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq, rOrgTxnEle) == PD_OK) {
			hTxnEle = RecordSet_GetFirst(rOrgTxnEle);
			while (hTxnEle && (iRet == PD_OK)) {
				if (GetField_CString(hTxnEle, "amt_type", &csAmtType)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: amt_type = [%s]\n", csAmtType));
				}
				if (GetField_CString(hTxnEle, "ccy", &csCcy)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: ccy = [%s]\n", csCcy));
				}
				if (GetField_Double(hTxnEle, "amount", &dAmount)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: amount = [%lf]\n", dAmount));
				}
				if (GetField_CString(hTxnEle, "txn_element_type", &csTmp)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: txn_element_type = [%s]\n", csTmp));
					if (!strcmp(csTmp, PD_ELEMENT_MFIN_AMT)) {
						PutField_Double(hVoidTxnEle, "actual_fundin", dAmount);
						PutField_Double(hVoidTxnEle, "org_actual_fundin", dAmount);
						dNetAmount = dNetAmount + dAmount;
						iAffectFIN = PD_TRUE;
					} else if (!strcmp(csTmp, PD_ELEMENT_MPOR_AMT)) {
						PutField_Double(hVoidTxnEle, "actual_resv_po", dAmount);
						PutField_Double(hVoidTxnEle, "org_actual_resv_po", dAmount);
						dNetAmount = dNetAmount + dAmount;
						iAffectPOR = PD_TRUE;
					} else if (!strcmp(csTmp, PD_ELEMENT_MFLT_AMT)) {
						PutField_Double(hVoidTxnEle, "org_actual_prev_ft", dAmount);
						dNetAmount = dNetAmount + dAmount;
						iAffectFLT = PD_TRUE;
					} else if (!strcmp(csTmp, PD_ELEMENT_TXN_FEE)) {
						if (iReturnMerchFee) {
							// return fee
							PutField_CString(hVoidTxnEle, "actual_txn_fee_ccy", csCcy);
							PutField_Double(hVoidTxnEle, "actual_txn_fee", dAmount);
							dNetAmount = dNetAmount + dAmount;
							dFee = dAmount;
						}
					}
				}
				hTxnEle = RecordSet_GetNext(rOrgTxnEle);
			}

			PutField_Double(hVoidTxnEle, "actual_net_amt", dNetAmount);
			if ((iReturnMerchFee) && (dFee > 0.0) && (!iAffectFLT)) {
				if (iAffectPOR) {
					GetField_Double(hVoidTxnEle, "actual_resv_po", &dAmount);
					dAmount = dAmount + dFee;
					PutField_Double(hVoidTxnEle, "actual_resv_po", dAmount);
				} else if (iAffectFIN) {
					GetField_Double(hVoidTxnEle, "actual_fundin", &dAmount);
					dAmount = dAmount + dFee;
					PutField_Double(hVoidTxnEle, "actual_fundin", dAmount);
				} else {
					// should not happen
				}
			}
		} else {
DEBUGLOG(("Authorize:: (FROM) Call DBTxnElements:GetAllFeeChgDetail FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (FROM) Call DBTxnElements:GetAllFeeChgDetail FAILED\n");
			iRet = INT_ERR;
		}
	}

// process Void FROM txn elements and balance
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (FROM) Call BOBalance:ProcessTransferAvaPayout\n"));
		BOObjPtr = CreateObj(BOPtr, "BOBalance", "ProcessTransferAvaPayout");
		iRet = (unsigned long)(*BOObjPtr)(hVoidTxnEle);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: (FROM) Call BOBalance:ProcessTransferAvaPayout FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (FROM) Call BOBalance:ProcessTransferAvaPayout FAILED\n");
			iRet = INT_ERR;
		}
	}

// update Void FROM txn_header & txn_detail
	if (iRet == PD_OK) {
		PutField_CString(hContext, "merchant_id", csMid);
		if (GetField_Double(hOrgTxn, "txn_amt", &dTmp)) {
			PutField_Double(hContext, "txn_amt", dTmp);
		}
		PutField_Double(hContext, "net_amt", dNetAmount);
		if (GetField_CString(hVoidTxnEle, "approval_date", &csTmp)) {
			PutField_CString(hContext, "approval_date", csTmp);
		}
		PutField_CString(hContext, "net_ccy", csNetCcy);
		if (GetField_CString(hVoidTxnEle, "approval_timestamp", &csTmp)) {
			PutField_CString(hContext, "approval_timestamp", csTmp);
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hVoidTxnEle, "remark", csRemark);

DEBUGLOG(("Authorize:: (FROM) Call DBTransaction:AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "AddDetail");
		iRet = (unsigned long)(*DBObjPtr)(hVoidTxnEle);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (FROM) Call DBTransaction:UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "UpdateDetail");
		iRet = (unsigned long)(*DBObjPtr)(hVoidTxnEle);
	}

// get TO txn info (for Void TO txn_header)
	if (iRet == PD_OK) {
		iRet = GetTxnInfo((const unsigned char*)csOrgTxnSeqTo, hOrgTxnTo);
	}

// lock TO txn balance
	if (iRet == PD_OK) {
		if (GetField_CString(hOrgTxnTo, "merchant_id", &csMid)) {
DEBUGLOG(("Authorize:: TO Merchant = [%s]\n", csMid));
			PutField_CString(hVoidTxnToEle, "merchant_id", csMid);
		}
		if (GetField_CString(hOrgTxnTo, "net_ccy", &csNetCcy)) {
DEBUGLOG(("Authorize:: TO Ccy = [%s]\n", csNetCcy));
			PutField_CString(hVoidTxnToEle, "txn_ccy", csNetCcy);
		}
		if (GetField_CString(hOrgTxnTo, "txn_country", &csCountry)) {
DEBUGLOG(("Authorize:: TO Country = [%s]\n", csCountry));
			PutField_CString(hVoidTxnToEle, "txn_country", csCountry);
		}
		if (GetField_CString(hOrgTxnTo, "service_code", &csService)) {
DEBUGLOG(("Authorize:: TO Service = [%s]\n", csService));
			PutField_CString(hVoidTxnToEle, "service_code", csService);
		}

DEBUGLOG(("Authorize:: (TO) Call DBMerchantBalance:GetOpenBalanceForUpdate\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchantBalance", "GetOpenBalanceForUpdate");
		iRet = (unsigned long)(*DBObjPtr)(hOrgTxnTo,
				csMid,
				csNetCcy,
				csCountry,
				csService);
		if (iRet == PD_OK) {
			if (GetField_Double(hOrgTxnTo, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("Authorize:: TO merchant_open_bal = [%lf]\n", dTmp));
				PutField_Double(hVoidTxnToEle, "merchant_open_bal", dTmp);
			}
			if (GetField_Double(hOrgTxnTo, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("Authorize:: TO merchant_open_bal_settlement = [%lf]\n", dTmp));
				PutField_Double(hVoidTxnToEle, "merchant_open_bal_settlement", dTmp);
			}
		} else {
DEBUGLOG(("Authorize:: (TO) Call DBMerchantBalance:GetOpenBalanceForUpdate FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (TO) Call DBMerchantBalance:GetOpenBalanceForUpdate FAILED\n");
			iRet = INT_ERR;
		}
	}

// prepare Void TO txn id
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call DBTxnSeq:GetNextMgtTxnSeq\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnSeq", "GetNextMgtTxnSeq");
		strcpy((char*)csVoidTxnSeqTo, (*DBObjPtr)());
		PutField_CString(hResponse, "txn_seq_tt", (const char*)csVoidTxnSeqTo);
	}

// create Void TO txn_header & txn_detail
	if (iRet == PD_OK) {
		PutField_Int(hOrgTxnTo, "db_commit", PD_FALSE);
		PutField_CString(hOrgTxnTo, "txn_seq", csVoidTxnSeqTo);
		PutField_CString(hOrgTxnTo, "org_txn_seq", csOrgTxnSeqTo);
		PutField_CString(hOrgTxnTo, "channel_code", PD_CHANNEL_MGT);
		PutField_CString(hOrgTxnTo, "txn_code", PD_VOID_AVA_PAYOUT_REQ_TF_TO);
		PutField_CString(hOrgTxnTo, "process_type", PD_PROCESS_TYPE_DEF);
		PutField_CString(hOrgTxnTo, "process_code", PD_PROCESS_CODE_DEF);
		if (GetField_CString(hContext, "PHDATE", &csTmp)) {
			PutField_CString(hOrgTxnTo, "PHDATE", csTmp);
		}
		if (GetField_CString(hContext, "transmission_datetime", &csTmp)) {
			PutField_CString(hOrgTxnTo, "transmission_datetime", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
			PutField_CString(hOrgTxnTo, "local_tm_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
			PutField_CString(hOrgTxnTo, "local_tm_time", csTmp);
		}
		if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
			PutField_CString(hOrgTxnTo, "ip_addr", csTmp);
		}
		PutField_CString(hOrgTxnTo, "remark", csRemark);
		PutField_CString(hOrgTxnTo, "add_user", csUser);

DEBUGLOG(("Authorize:: (TO) Call MGTChannel:AddTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "AddTxnLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hOrgTxnTo, hOrgTxnTo);
	}

// get TO txn elements & prepare Void TO txn elements
	if (iRet == PD_OK) {
		dTxnAmount = 0.0;
		dNetAmount = 0.0;
                dFee = 0.0;

		PutField_Int(hVoidTxnToEle, "db_commit", PD_FALSE);
		PutField_CString(hVoidTxnToEle, "txn_seq", csVoidTxnSeqTo);
		PutField_Char(hVoidTxnToEle, "dc_type", PD_IND_DEBIT);
		PutField_Int(hVoidTxnToEle, "void_flag", PD_TRUE);
		PutField_CString(hVoidTxnToEle, "update_user", csUser);

DEBUGLOG(("Authorize:: (TO) Call DBTxnElements:GetAllFeeChgDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnElements", "GetAllFeeChgDetail");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeqTo, rOrgTxnToEle) == PD_OK) {
			hTxnEle = RecordSet_GetFirst(rOrgTxnToEle);
			while (hTxnEle && (iRet == PD_OK)) {
				if (GetField_CString(hTxnEle, "amt_type", &csAmtType)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: amt_type = [%s]\n", csAmtType));
				}
				if (GetField_CString(hTxnEle, "ccy", &csCcy)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: ccy = [%s]\n", csCcy));
				}
				if (GetField_Double(hTxnEle, "amount", &dAmount)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: amount = [%lf]\n", dAmount));
				}
				if (GetField_CString(hTxnEle, "txn_element_type", &csTmp)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: txn_element_type = [%s]\n", csTmp));
					if (!strcmp(csTmp, PD_ELEMENT_MFIN_AMT)) {
						dTxnAmount = dAmount;
						dNetAmount = dNetAmount + dAmount;
					} else if (!strcmp(csTmp, PD_ELEMENT_TXN_FEE)) {
						if (iReturnToMerchFee) {
							// return fee
							PutField_CString(hVoidTxnToEle, "actual_txn_fee_ccy", csCcy);
							PutField_Double(hVoidTxnToEle, "actual_txn_fee", dAmount);
							dNetAmount = dNetAmount - dAmount;
							dFee = dAmount;
						}
					} else if (!strcmp(csTmp, PD_ELEMENT_MARKUP_AMT)) {
						if (GetField_Double(hTxnEle, "rate", &dRate)) {
DEBUGLOG(("Authorize:: GetAllFeeChgDetail: rate = [%lf]\n", dRate));
							PutField_Double(hVoidTxnToEle, "markup_rate", dRate);
						}
						PutField_CString(hVoidTxnToEle, "markup_ccy", csCcy);
						PutField_Double(hVoidTxnToEle, "markup_amt", dAmount);
					}
				}
				hTxnEle = RecordSet_GetNext(rOrgTxnToEle);
			}
		} else {
DEBUGLOG(("Authorize:: (TO) Call DBTxnElements:GetAllFeeChgDetail FAILED\n"));
ERRLOG("Authorize:: (TO) Call DBTxnElements:GetAllFeeChgDetail FAILED\n");
			iRet = INT_ERR;
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call DBMerchantBalance:GetRemainPOBalance\n"));
		DBObjPtr = CreateObj(DBPtr, "DBMerchantBalance", "GetRemainPOBalance");
		iRet = (unsigned long)(*DBObjPtr)(hOrgTxnTo,
				csMid,
				csNetCcy,
				csCountry,
				csService,
				&dTmp);
		if (iRet == PD_OK) {
			if (GetField_Double(hOrgTxnTo, "merchant_aval_po", &dAvaPOBal)) {
DEBUGLOG(("Authorize:: TO merchant_aval_po = [%lf]\n", dAvaPOBal));
			}
		} else {
DEBUGLOG(("Authorize:: (TO) Call DBMerchantBalance:GetRemainPOBalance FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (TO) Call DBMerchantBalance:GetRemainPOBalance FAILED\n");
			iRet = INT_ERR;
		}

		if (iRet == PD_OK) {
			if (dNetAmount > dAvaPOBal) {
DEBUGLOG(("Authorize:: insufficient fund [%s] [%s] [%s] [%lf] [%lf]\n", csMid, csNetCcy, csService, dAvaPOBal, dNetAmount));
ERRLOG("TxnMgtByUsVBF:: Authorize:: insufficient fund [%s] [%s] [%s] [%lf] [%lf]\n", csMid, csNetCcy, csService, dAvaPOBal, dNetAmount);
				iRet = INT_INSUFFICIENT_FUND;
				PutField_Int(hContext, "internal_error", iRet);
				PutField_CString(hOrgTxnTo, "remark", "Insufficient Availiable For Payout Amount");
			}
		}
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hOrgTxnTo, "merchant_net_float", &dTmp)) {
			if (dTmp < 0.0) {
DEBUGLOG(("Authorize:: TO merchant_net_float problem [%lf]\n", dTmp));
ERRLOG("TxnMgtByUsVBF:: Authorize:: TO merchant_net_float problem [%lf]\n", dTmp);
				iRet = INT_ERR;
			}
		}
	}

	if (iRet == PD_OK) {
		// prepare balance
		if (GetField_Double(hOrgTxnTo, "merchant_fundin_po", &dTmp)) {
			if (dNetAmount >= dTmp) {
				dDeductFundin = dTmp;
				dRemainTxnAmt = dNetAmount - dTmp;
			} else {
				dDeductFundin = dNetAmount;
				dRemainTxnAmt = 0.0;
			}
		}

		if (GetField_Double(hOrgTxnTo, "merchant_reserved_po", &dTmp)) {
			if (dRemainTxnAmt > 0.0) {
				if (dRemainTxnAmt >= dTmp) {
					dDeductResvPO = dTmp;
					dRemainTxnAmt = dRemainTxnAmt - dTmp;
				} else {
					dDeductResvPO = dRemainTxnAmt;
					dRemainTxnAmt = 0.0;
				}
			} else {
				dDeductResvPO = 0.0;
			}
		}

		if (dRemainTxnAmt > 0.0) {
			dDeductPrevFt = dRemainTxnAmt;
		} else {
			dDeductPrevFt = 0.0;
		}

		// prepare element
		if (iReturnToMerchFee) {
			if (GetField_Double(hOrgTxnTo, "merchant_fundin_po", &dTmp)) {
				if (dTxnAmount >= dTmp) {
					dOrgDeductFundin = dTmp;
					dRemainTxnAmt = dTxnAmount - dTmp;
				} else {
					dOrgDeductFundin = dTxnAmount;
					dRemainTxnAmt = 0.0;
				}
			}

			if (GetField_Double(hOrgTxnTo, "merchant_reserved_po", &dTmp)) {
				if (dRemainTxnAmt > 0.0) {
					if (dRemainTxnAmt >= dTmp) {
						dOrgDeductResvPO = dTmp;
						dRemainTxnAmt = dRemainTxnAmt - dTmp;
					} else {
						dOrgDeductResvPO = dRemainTxnAmt;
						dRemainTxnAmt = 0.0;
					}
				} else {
					dOrgDeductResvPO = 0.0;
				}
			}

			if (dRemainTxnAmt > 0.0) {
				dOrgDeductPrevFt = dRemainTxnAmt;
			} else {
				dOrgDeductPrevFt = 0.0;
			}
		} else {
			dOrgDeductFundin = dDeductFundin;
			dOrgDeductResvPO = dDeductResvPO;
			dOrgDeductPrevFt = dDeductPrevFt;
		}

		PutField_Double(hVoidTxnToEle, "actual_fundin", dDeductFundin);
		PutField_Double(hVoidTxnToEle, "actual_resv_po", dDeductResvPO);
		PutField_Double(hVoidTxnToEle, "actual_net_amt", dNetAmount);
		PutField_Double(hVoidTxnToEle, "org_actual_fundin", dOrgDeductFundin);
		PutField_Double(hVoidTxnToEle, "org_actual_resv_po", dOrgDeductResvPO);
		PutField_Double(hVoidTxnToEle, "org_actual_prev_ft", dOrgDeductPrevFt);
	}

// process Void TO txn elements and balance
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call BOBalance:ProcessTransferAvaPayout\n"));
		BOObjPtr = CreateObj(BOPtr, "BOBalance", "ProcessTransferAvaPayout");
		iRet = (unsigned long)(*BOObjPtr)(hVoidTxnToEle);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call BOBalance:ProcessTransferAvaPayout FAILED\n"));
ERRLOG("TxnMgtByUsVBF:: Authorize:: (TO) Call BOBalance:ProcessTransferAvaPayout FAILED\n");
			iRet = INT_ERR;
		}
	}

// update Void TO txn_header & txn_detail
	if (iRet == PD_OK) {
		PutField_Char(hOrgTxnTo, "status", PD_COMPLETE);
		PutField_Char(hOrgTxnTo, "ar_ind", PD_ACCEPT);
		PutField_Int(hOrgTxnTo, "internal_code", 0);
		PutField_CString(hOrgTxnTo, "response_code", "0");
		PutField_Double(hOrgTxnTo, "net_amt", dNetAmount);
		if (GetField_CString(hVoidTxnToEle, "approval_date", &csTmp)) {
			PutField_CString(hOrgTxnTo, "approval_date", csTmp);
		}
		if (GetField_CString(hVoidTxnToEle, "approval_timestamp", &csTmp)) {
			PutField_CString(hOrgTxnTo, "approval_timestamp", csTmp);
		}
		PutField_CString(hOrgTxnTo, "sub_status", PD_APPROVED);
		PutField_CString(hOrgTxnTo, "update_user", csUser);

DEBUGLOG(("Authorize:: (TO) Call MGTChannel:UpdateTxnLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateTxnLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hOrgTxnTo, hOrgTxnTo, hOrgTxnTo);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: (TO) Call MGTChannel:UpdateTxnDetailLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateTxnDetailLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hVoidTxnToEle, hVoidTxnToEle, hVoidTxnToEle);
	}

/* update org_txn_seq */
	if (iRet == PD_OK) {
		PutField_CString(hTmp, "txn_seq", csOrgTxnSeq);
		PutField_Char(hTmp, "status", PD_REVERSED);
		PutField_CString(hTmp, "sub_status", PD_UNDO);
		PutField_CString(hTmp, "update_user", csUser);

DEBUGLOG(("Authorize:: (Org FROM) Call DBTransaction:Update\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
		iRet = (unsigned long)(*DBObjPtr)(hTmp);
	}

/* update to_txn_seq */
	if (iRet == PD_OK) {
		PutField_CString(hTmp, "txn_seq", csOrgTxnSeqTo);

DEBUGLOG(("Authorize:: (ORG TO) Call DBTransaction:Update\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		iRet = (unsigned long)(*DBObjPtr)(hTmp);
	}

	if (iRet != PD_OK) {
		TxnAbort();
		if (GetField_Double(hContext, "net_amt", &dTmp)) {
			RemoveField_Double(hContext, "net_amt");
		}
		if (GetField_CString(hContext, "approval_date", &csTmp)) {
			RemoveField_CString(hContext, "approval_date");
		}
		if (GetField_CString(hContext, "approval_timestamp", &csTmp)) {
			RemoveField_CString(hContext, "approval_timestamp");
		}
	}

	hash_destroy(hOrgTxn);
	FREE_ME(hOrgTxn);

	hash_destroy(hOrgTxnTo);
	FREE_ME(hOrgTxnTo);

	RecordSet_Destroy(rOrgTxnEle);
	FREE_ME(rOrgTxnEle);

	RecordSet_Destroy(rOrgTxnToEle);
	FREE_ME(rOrgTxnToEle);

	hash_destroy(hTmp);
	FREE_ME(hTmp);

	hash_destroy(hVoidTxnEle);
	FREE_ME(hVoidTxnEle);

	hash_destroy(hVoidTxnToEle);
	FREE_ME(hVoidTxnToEle);

DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}

int GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn) {
	int iRet = PD_OK;
	hash_t *hRec;
	char *csTmp = NULL;
	double dTmp = 0.0;
	char cTmp;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo:: Call DBTransaction:GetTxnHeader\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		if ((unsigned long)(*DBObjPtr)(csTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: found record of [%s]\n", csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "client_id", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: client_id = [%s]\n", csTmp));
					PutField_CString(hTxn, "client_id", csTmp);
				}

				if (GetField_CString(hRec, "merchant_id", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: merchant_id = [%s]\n", csTmp));
					PutField_CString(hTxn, "merchant_id", csTmp);
				}

				if (GetField_CString(hRec, "net_ccy", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: net_ccy = [%s]\n", csTmp));
					PutField_CString(hTxn, "net_ccy", csTmp); 
				}

				if (GetField_CString(hRec, "service_code", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: service_code = [%s]\n", csTmp));
					PutField_CString(hTxn, "service_code", csTmp);
				}

				if (GetField_Double(hRec, "txn_amt", &dTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: txn_amt = [%lf]\n", dTmp));
					PutField_Double(hTxn, "txn_amt", dTmp);
				}

				if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: ex_supplier = [%c]\n", cTmp));
					PutField_Char(hTxn, "ex_party", cTmp);
				}

				if (GetField_Double(hRec, "ex_rate", &dTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: ex_rate = [%lf]\n", dTmp));
					PutField_Double(hTxn, "ex_rate", dTmp);
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnInfo:: GetTxnHeader: cannot found record of [%s]\n", csTxnSeq));
ERRLOG("TxnMgtByUsVBF:: GetTxnInfo:: GetTxnHeader: cannot found record\n");
			iRet = INT_NOT_RECORD;
		}
	}

	if (iRet == PD_OK) {
		recordset_init(rRecordSet, 0);
DEBUGLOG(("GetTxnInfo:: Call DBTransaction:GetTxnDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnDetail");
		if ((unsigned long)(*DBObjPtr)(csTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnInfo:: GetTxnDetail: found record of [%s]\n", csTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "txn_ccy", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnDetail: txn_ccy = [%s]\n", csTmp));
					PutField_CString(hTxn, "txn_ccy", csTmp);
				}

				if (GetField_CString(hRec, "txn_country", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: GetTxnDetail: txn_country = [%s]\n", csTmp));
					PutField_CString(hTxn, "txn_country", csTmp);
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnInfo:: GetTxnDetail: cannot found record of [%s]\n", csTxnSeq));
ERRLOG("TxnMgtByUsVBF:: GetTxnInfo:: GetTxnDetail: cannot found record\n");
			iRet = INT_NOT_RECORD;
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
}

