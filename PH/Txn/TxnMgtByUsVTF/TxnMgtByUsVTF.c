/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/05/24              LokMan Chow
Logic change                                       2016/07/15              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsVTF.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

int GetTxnInfo(hash_t *hContext, hash_t *hRequest);
int UpdateTxnLog(hash_t* hContext, hash_t* hOrgTxn);

void TxnMgtByUsVTF(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;
	char	*csOrgTxnSeq;
	char	*csTmp;
	char	*csUpdateUser;
	char	*csRemark;
	double	dNetAmt = 0.0;
	double	dTxnFee = 0.0;
	unsigned char	csNewTxnSeq[PD_TXN_SEQ_LEN +1];
	char	*csPHPostingDate;
	int	iInternalErr = 0;
	int	iTmp;
	double	dTmp = 0.0;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hash_t *hOrgTxn;
	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);

DEBUGLOG(("TxnMgtByUsVTF: Authroize()\n"));

	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("TxnMgtByUsVTF: org_txn_seq = [%s]\n", csOrgTxnSeq));
DEBUGLOG(("TxnMgtByUsVTF: (FROM) Call DBTransaction:MatchRespTxn\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MatchRespTxn");
		iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_COMPLETE);
		if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("TxnMgtByUsVTF: cannot lock FROM record\n"));
ERRLOG("TxnMgtByUsVTF: Authroize:: cannot lock FROM record\n");
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext, "internal_error", iRet);
                }
	}

	if (GetField_CString(hContext, "to_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("TxnMgtByUsVTF: to_txn_seq = [%s]\n", csOrgTxnSeq));
DEBUGLOG(("TxnMgtByUsVTF: (TO) Call DBTransaction:MatchRespTxn\n"));
                DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MatchRespTxn");
                iTmpRet = (unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_COMPLETE);
                if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("TxnMgtByUsVTF: cannot lock TO record\n"));
ERRLOG("TxnMgtByUsVTF: Authroize:: cannot lock TO record\n");
                        iRet = INT_INVALID_TXN;
                        PutField_Int(hContext, "internal_error", iRet);
                }
	}

//////Void TFF
DEBUGLOG(("TxnMgtByUsVTF: Void TFF first\n"));

	if (GetField_CString(hContext, "txn_seq", &csTmp)) {
DEBUGLOG(("TxnMgtByUsVTF: VTF txn_seq = [%s]\n", csTmp));
		PutField_CString(hResponse, "txn_seq_tf", csTmp);
	}
	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("TxnMgtByUsVTF: org_txn_seq = [%s]\n", csOrgTxnSeq));
		PutField_CString(hContext, "find_txn_seq", csOrgTxnSeq);
		PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
	}
	if (GetField_CString(hContext, "update_user", &csUpdateUser)) {
DEBUGLOG(("TxnMgtByUsVTF: update_user = [%s]\n", csUpdateUser));
		PutField_CString(hOrgTxn, "update_user", csUpdateUser);
	}
	if (GetField_CString(hRequest, "remark", &csRemark)) {
DEBUGLOG(("TxnMgtByUsVTF: remark = [%s]\n", csRemark));
		PutField_CString(hContext, "remark", csRemark);
	} else {
DEBUGLOG(("TxnMgtByUsVTF:: remark not found\n"));
ERRLOG("TxnMgtByUsVTF:: Authroize:: remark not found\n");
		iRet = INT_INVALID_TXN;
		PutField_Int (hContext, "internal_error", iRet);
        }

	if (iRet == PD_OK) {
		iRet = GetTxnInfo(hContext, hRequest);

		if (GetField_Int(hRequest, "return_mfee", &iTmp)) {
DEBUGLOG(("TxnMgtByUsVTF: return_mfee = [%d]\n", iTmp));
			if (!iTmp) {
				if (GetField_Double(hContext, "src_txn_fee", &dTxnFee)) {
					if (GetField_Double(hContext, "net_amt", &dNetAmt)) {
						dNetAmt = dNetAmt - dTxnFee;
						PutField_Double(hContext, "net_amt", dNetAmt);
					}
				}
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_Char(hContext, "dc_type", PD_IND_CREDIT);

		BOObjPtr = CreateObj(BOPtr, "BOBalance", "ProcessMerchantAdjAmount");
		iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnMgtByUsVTF: BOBalance:ProcessMerchantAdjAmount [%d]\n", iRet));
		if (iRet != PD_OK) {
ERRLOG("TxnMgtByUsVTF: BOBalance:ProcessMerchantAdjAmount [%d]\n", iRet);
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	if (iRet == PD_OK) {
		PutField_Char(hOrgTxn, "status", PD_REVERSED);
		PutField_CString(hOrgTxn, "sub_status", PD_UNDO);

		iRet = UpdateTxnLog(hContext, hOrgTxn);
	}

//////Void TFT
DEBUGLOG(("TxnMgtByUsVTF: Void TFT\n"));

	hash_t *hReq, *hNewContext;
	hReq = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hReq, 0);
	hNewContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hNewContext, 0);

	if (GetField_CString(hContext, "to_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("TxnMgtByUsVTF: to_txn_seq = [%s]\n", csOrgTxnSeq));
		PutField_CString(hNewContext, "find_txn_seq", csOrgTxnSeq);
		PutField_CString(hNewContext, "org_txn_seq", csOrgTxnSeq);
		PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
	}

	if (iRet == PD_OK) {
		iRet = GetTxnInfo(hNewContext, hReq);

		if (GetField_Int(hRequest, "return_to_mfee", &iTmp)) {
DEBUGLOG(("TxnMgtByUsVTF: return_to_mfee = [%d]\n", iTmp));
			if (!iTmp) {
				if (GetField_Double(hNewContext, "src_txn_fee", &dTxnFee)) {
					if (GetField_Double(hNewContext, "net_amt", &dNetAmt)) {
						dNetAmt = dNetAmt + dTxnFee;
						PutField_Double(hNewContext, "net_amt", dNetAmt);
					}
				}
			}
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMgtByUsVTF: new txn for VTT\n"));
		PutField_Int(hNewContext, "db_commit", PD_FALSE);

		DBObjPtr = CreateObj(DBPtr, "DBTxnSeq", "GetNextMgtTxnSeq");
		strcpy((char*)csNewTxnSeq, (*DBObjPtr)());
DEBUGLOG(("TxnMgtByUsVTF: VTT txn_seq = [%s]\n", csNewTxnSeq));
		PutField_CString(hNewContext, "txn_seq", (const char*)csNewTxnSeq);
		PutField_CString(hResponse, "txn_seq_tt", (const char*)csNewTxnSeq);

		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
			PutField_CString(hNewContext, "local_tm_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
			PutField_CString(hNewContext, "local_tm_time", csTmp);
		}
		PutField_CString(hNewContext, "add_user", csUpdateUser);
		PutField_CString(hNewContext, "update_user", csUpdateUser);
		PutField_CString(hNewContext, "remark", csRemark);
		if (GetField_CString(hRequest, "ip_addr", &csTmp)) {
			PutField_CString(hReq, "ip_addr", csTmp);
		}
		if (GetField_CString(hContext, "PHDATE", &csPHPostingDate)) {
			PutField_CString(hNewContext, "PHDATE", csPHPostingDate);
		}
		PutField_CString(hNewContext, "channel_code", PD_CHANNEL_MGT);
		PutField_CString(hNewContext, "txn_code", PD_MERCHANT_BAL_TFT_VOID);
		PutField_CString(hNewContext, "process_code", PD_PROCESS_CODE_DEF);
		PutField_CString(hNewContext, "process_type", PD_PROCESS_TYPE_DEF);

		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateContext");
		iRet = (unsigned long)(*ChannelObjPtr)(hContext);

		if (iRet == PD_OK) {
			if (GetField_CString(hContext, "detail_txn_ccy", &csTmp)) {
				PutField_CString(hNewContext, "txn_ccy", csTmp);
			}

			ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "AddTxnLog");
			iRet = (unsigned long)(*ChannelObjPtr)(hNewContext, hReq);

			if (GetField_CString(hNewContext, "net_ccy", &csTmp)) {
				PutField_CString(hNewContext, "txn_ccy", csTmp);
				PutField_CString(hReq, "txn_ccy", csTmp);
			}
		} else {
			RemoveField_Int(hNewContext, "internal_error");
			PutField_Int(hContext, "internal_error", iRet);
		}

		if (iRet == PD_OK) {
			if (GetField_Int(hRequest, "return_to_mfee", &iTmp)) {
DEBUGLOG(("TxnMgtByUsVTF: return_to_mfee = [%d]\n", iTmp));
				PutField_Int(hReq, "return_mfee", iTmp);
			}

			BOObjPtr = CreateObj(BOPtr, "BOTxnElements", "VoidOrgTxnElements");
			iRet = (unsigned long)(*BOObjPtr)(hNewContext, hReq);
DEBUGLOG(("TxnMgtByUsVTF: VoidOrgTxnElements iRet = [%d]\n", iRet));
		}
	}

	if (iRet == PD_OK) {
		PutField_Char(hNewContext, "dc_type", PD_IND_DEBIT);

		BOObjPtr = CreateObj(BOPtr, "BOBalance", "ProcessMerchantAdjAmount");
		iRet = (unsigned long)(*BOObjPtr)(hNewContext);
DEBUGLOG(("TxnMgtByUsVTF: BOBalance:ProcessMerchantAdjAmount [%d]\n", iRet));
		if (iRet != PD_OK) {
ERRLOG("TxnMgtByUsVTF: BOBalance:ProcessMerchantAdjAmount [%d]\n", iRet);
			PutField_Int(hContext, "internal_error", iRet);
		}      
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMgtByUsVTF: Call UpdateTxnDetailLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateTxnDetailLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hNewContext, hReq, hResponse);
	}

	if (iRet == PD_OK) {
		PutField_CString(hNewContext, "response_code", "0");
		PutField_Int(hNewContext, "internal_code", 0);

		PutField_Char(hNewContext, "status", PD_COMPLETE);

		if (iInternalErr != 0) {
			PutField_Char(hNewContext, "ar_ind", PD_REJECT);
		} else {
			PutField_Char(hNewContext, "ar_ind", PD_ACCEPT);
			PutField_CString(hNewContext, "sub_status", PD_APPROVED);
		}

		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel", "UpdateTxnLog");
		iRet = (unsigned long)(*ChannelObjPtr)(hNewContext, hReq, hResponse);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("TxnMgtByUsVTF: Call Update Org Transaction\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
		if ((unsigned long)(*DBObjPtr)(hOrgTxn) != PD_OK)
			iRet = INT_ERR;
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

	hash_destroy(hNewContext);
	FREE_ME(hNewContext);
	hash_destroy(hReq);
	FREE_ME(hReq);
	hash_destroy(hOrgTxn);
	FREE_ME(hOrgTxn);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("Normal exit iRet = [%d]\n", iRet));
	return iRet;
}


int GetTxnInfo(hash_t *hContext, hash_t *hRequest)
{
	int	iRet = PD_OK;
	char*	csOrgTxnSeq;
	char*	csMerchantId;
	char*	csServiceCode;
	char*	csCcy;
	char*	csCountry;
	char*	csTmp;
	double	dTmp = 0.0;
	hash_t*	hRec;
	char	cTmp;
	char	cPartyType = PD_TYPE_MERCHANT;
	double	dTxnFee = 0.0;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	if (GetField_CString(hContext, "find_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("GetTxnInfo: find_txn_seq = [%s]\n", csOrgTxnSeq));
	}

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo: Call DBTransaction:GetTxnHeader\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		if ((*DBObjPtr)(csOrgTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "client_id", &csTmp)) {
					PutField_CString(hContext, "merchant_client_id", csTmp);
					PutField_CString(hContext, "client_id", csTmp);
DEBUGLOG(("GetTxnHeader: client_id = [%s]\n", csTmp));
				}
				if (GetField_CString(hRec, "merchant_id", &csMerchantId)) {
					PutField_CString(hRequest, "merchant_id", csMerchantId);
					PutField_CString(hContext, "merchant_id", csMerchantId);
DEBUGLOG(("GetTxnHeader: merchant_id = [%s]\n", csMerchantId));
				}
				if (GetField_CString(hRec, "merchant_ref", &csTmp)) {
					PutField_CString(hContext, "merchant_ref", csTmp);
DEBUGLOG(("GetTxnHeader: merchant_ref = [%s]\n", csTmp));
				}
				if (GetField_CString(hRec, "txn_code", &csTmp)) {
					PutField_CString(hRequest, "org_txn_code", csTmp);
DEBUGLOG(("GetTxnHeader: txn_code = [%s]\n", csTmp));
				}
				if (GetField_CString(hRec, "service_code", &csServiceCode)) {
					PutField_CString(hRequest, "service_code", csServiceCode);
					PutField_CString(hContext, "service_code", csServiceCode);
DEBUGLOG(("GetTxnHeader: service_code = [%s]\n", csServiceCode));
				}
				if (GetField_Double(hRec, "txn_amt", &dTmp)) {
					PutField_Double(hContext, "txn_amt", dTmp);
					PutField_Double(hContext, "header_txn_amt", dTmp);
DEBUGLOG(("GetTxnHeader: txn_amt = [%lf]\n", dTmp));
				}
				if (GetField_Double(hRec, "net_amt", &dTmp)) {
					PutField_Double(hContext, "net_amt", dTmp);
DEBUGLOG(("GetTxnHeader: net_amt = [%lf]\n", dTmp));
				}
				if (GetField_CString(hRec, "net_ccy", &csTmp)) {
					PutField_CString(hContext, "net_ccy", csTmp);
DEBUGLOG(("GetTxnHeader: net_ccy = [%s]\n", csTmp));
				}
				if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
					PutField_Char(hContext, "ex_party", cTmp);
DEBUGLOG(("GetTxnHeader: ex_supplier = [%c]\n", cTmp));

					if (GetField_Double(hRec, "ex_rate", &dTmp)) {
						PutField_Double(hContext, "ex_rate", dTmp);
DEBUGLOG(("GetTxnHeader: ex_rate = [%lf]\n", dTmp));
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnHeader: not found record for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnMgtByUsVTF: Authorize: GetTxnHeader: not found record!!\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo: Call DBTransaction:GetTxnDetail\n"));
		recordset_init(rRecordSet, 0);
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnDetail");
		if ((*DBObjPtr)(csOrgTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnDetail: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "txn_ccy", &csCcy)) {
					PutField_CString(hContext, "txn_ccy", csCcy);
					PutField_CString(hRequest, "txn_ccy", csCcy);
					PutField_CString(hContext, "detail_txn_ccy", csCcy);
DEBUGLOG(("GetTxnDetail: txn_ccy = [%s]\n", csCcy));
				}
				if (GetField_CString(hRec, "txn_country", &csCountry)) {
					PutField_CString(hContext, "txn_country", csCountry);
					PutField_CString(hRequest, "txn_country", csCountry);
DEBUGLOG(("GetTxnDetail: txn_country = [%s]\n", csCountry));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnDetail: not found record for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnMgtByUsVTF: Authorize: GetTxnDetail: not found record!!\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo: Call DBTxnElements:GetFeeChgDetailByType\n"));
		recordset_init(rRecordSet, 0);
		DBObjPtr = CreateObj(DBPtr, "DBTxnElements", "GetFeeChgDetailByType");
		if ((*DBObjPtr)(csOrgTxnSeq, PD_ELEMENT_TXN_FEE, cPartyType, rRecordSet) == PD_OK) {
DEBUGLOG(("GetFeeChgDetailByType: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Double(hRec, "amount", &dTmp)) {
					dTxnFee += dTmp;
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
DEBUGLOG(("GetFeeChgDetailByType: src_txn_fee = [%lf]\n", dTxnFee));
			PutField_Double(hContext, "src_txn_fee", dTxnFee);
		} else {
DEBUGLOG(("GetFeeChgDetailByType: not found record for [%s]\n", csOrgTxnSeq));
		}
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
}


int UpdateTxnLog(hash_t* hContext, hash_t* hOrgTxn)
{
	int	iRet = PD_OK;
	double	dTmp;

	if (iRet == PD_OK) {
DEBUGLOG(("UpdateTxnLog: Call Update Org Transaction\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
		if ((unsigned long)(*DBObjPtr)(hOrgTxn) != PD_OK)
			iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
DEBUGLOG(("UpdateTxnLog: Call Add Transaction Detail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "AddDetail");
		if ((unsigned long)(*DBObjPtr)(hContext) != PD_OK)
			iRet = INT_ERR;
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
DEBUGLOG(("UpdateTxnLog: merchant_open_bal [%lf]\n", dTmp));
			PutField_Double(hContext, "open_bal", dTmp);
		}

		if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
DEBUGLOG(("UpdateTxnLog: merchant_open_bal_settlement [%lf]\n", dTmp));
			PutField_Double(hContext, "open_bal_settlement", dTmp);
		}

DEBUGLOG(("UpdateTxnLog: Call Update Transaction Detail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "UpdateDetail");
		if ((unsigned long)(*DBObjPtr)(hContext) != PD_OK)
			iRet = INT_ERR;
	}

	return iRet;
}
