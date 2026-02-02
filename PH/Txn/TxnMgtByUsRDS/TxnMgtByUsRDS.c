/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/30              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRDS.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsRDS(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int iRet = PD_OK;
	hash_t *hOrgTxn;
	char *csOrgTxnSeq;
	char *csOrgPostDate;
	char *csMerchantId;
	char *csServiceCode;
	char *csCountry;
	char *csCcy;
	char *csPspCcy;
	char *csSubStatus;
	char *csTmp;
	double dPreFee = 0.0;
	double dTxnAmt = 0.0;
	double dNetAmt = 0.0;
	double dReserveAmt = 0.0;
	double dPspTxnAmt = 0.0;
	double dServiceFee = 0.0;
	double dTmp;
	hash_t *hRec;

	int iTmp;
	// int iReturnPspFee = PD_FALSE;
	int iReturnMerchFee = PD_FALSE;
	int iReleased = PD_FALSE;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);

DEBUGLOG(("TxnMgtByUsRDS: Authroize()\n"));

	// get org_txn_seq
	if (GetField_CString(hContext, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("org txn seq = [%s]\n", csOrgTxnSeq));
		PutField_CString(hOrgTxn, "txn_seq", csOrgTxnSeq);
		PutField_Char(hOrgTxn, "status", PD_REVERSED);
		PutField_CString(hOrgTxn, "sub_status", PD_UNDO);
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
		PutField_CString(hContext, "remark", csTmp);
DEBUGLOG(("Authorize:: remark = [%s]\n", csTmp));
	}

	// get txn header
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction: GetTxnHeader\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnHeader");
		if ((*DBObjPtr)(csOrgTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnHeader:: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "merchant_id", &csMerchantId)) {
					PutField_CString(hContext, "org_merchant_id", csMerchantId);
					PutField_CString(hContext, "merchant_id", csMerchantId);
DEBUGLOG(("GetTxnHeader:: merchant_id = [%s]\n", csMerchantId));
				}

				if (GetField_CString(hRec, "merchant_ref", &csTmp)) {
					PutField_CString(hContext, "merchant_ref", csTmp);
DEBUGLOG(("GetTxnHeader:: merchant_ref = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "service_code", &csServiceCode)) {
					PutField_CString(hContext, "org_service_code", csServiceCode);
					PutField_CString(hContext, "service_code", csServiceCode);
DEBUGLOG(("GetTxnHeader:: service_code = [%s]\n", csServiceCode));
				}

				if (GetField_CString(hRec, "net_ccy", &csTmp)) {
					PutField_CString(hContext, "net_ccy", csTmp);
DEBUGLOG(("GetTxnHeader:: net_ccy = [%s]\n", csTmp));
				}

				if (GetField_Double(hRec, "txn_amt", &dTxnAmt)) {
					PutField_Double(hContext, "txn_amt", dTxnAmt);
					PutField_Double(hContext, "org_txn_amt", dTxnAmt);
DEBUGLOG(("GetTxnHeader:: txn_amt = [%lf]\n", dTxnAmt));
				}

				if (GetField_Double(hRec, "net_amt", &dNetAmt)) {
DEBUGLOG(("GetTxnHeader:: net_amt = [%lf]\n", dNetAmt));
				}

				if (GetField_Double(hRec, "reserve_amt", &dReserveAmt)) {
					PutField_Double(hContext, "reserve_amt", dReserveAmt);
DEBUGLOG(("GetTxnHeader:: reserve_amt = [%lf]\n", dReserveAmt));
				}

				if (GetField_CString(hRec, "sub_status", &csSubStatus)) {
DEBUGLOG(("GetTxnHeader:: sub_status = [%s]\n", csSubStatus));
				}
				if (!strcmp(csSubStatus, PD_RESERVE_RELEASED)) {
					if (GetField_CString(hRec, "reserved_release_date", &csTmp)) {
						iReleased = PD_TRUE;
DEBUGLOG(("GetTxnHeader:: reserved_release_date = [%s]\n", csTmp));
					}
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnMgtByUsRDS: Authorize:: GetTxnHeader:: not found record!!\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get txn detail
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction: GetTxnDetail\n"));
		recordset_init(rRecordSet, 0);
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "GetTxnDetail");
		if ((*DBObjPtr)(csOrgTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnDetail:: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "txn_ccy", &csCcy)) {
					PutField_CString(hContext, "org_txn_ccy", csCcy);
					PutField_CString(hContext, "txn_ccy", csCcy);
					PutField_CString(hRequest, "txn_ccy", csCcy);
DEBUGLOG(("GetTxnDetail:: txn_ccy = [%s]\n", csCcy));
				}

				if (GetField_CString(hRec, "txn_country", &csCountry)) {
					PutField_CString(hContext, "org_txn_country", csCountry);
					PutField_CString(hContext, "txn_country", csCountry);
					PutField_CString(hRequest, "txn_country", csCountry);
DEBUGLOG(("GetTxnDetail:: txn_country = [%s]\n", csCountry));
				}

				if (GetField_CString(hRec, "pay_method", &csTmp)) {
					PutField_CString(hContext, "pay_method", csTmp);
DEBUGLOG(("GetTxnDetail:: pay_method = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "bank_code", &csTmp)) {
					PutField_CString(hContext, "bank_code", csTmp);
DEBUGLOG(("GetTxnDetail:: bank_code = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "language", &csTmp)) {
					PutField_CString(hContext, "language", csTmp);
DEBUGLOG(("GetTxnDetail:: language = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "encrypt_type", &csTmp)) {
					PutField_CString(hContext, "encrypt_type", csTmp);
DEBUGLOG(("GetTxnDetail:: encrypt_type = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "selected_pay_method", &csTmp)) {
					PutField_CString(hContext, "selected_pay_method", csTmp);
DEBUGLOG(("GetTxnDetail:: selected_pay_method = [%s]\n", csTmp));
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnDetail:: not found record for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnMgtByUsRDS: Authorize:: GetTxnDetail:: not found record!!\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get txn psp detail
	if (iRet == PD_OK){
DEBUGLOG(("Authorize:: Call DBTransaction: GetTxnPspDetail\n"));
		recordset_init(rRecordSet, 0);
		DBObjPtr = CreateObj(DBPtr, "DBTxnPspDetail", "GetTxnPspDetail");
		if ((*DBObjPtr)(csOrgTxnSeq, rRecordSet) == PD_OK) {
DEBUGLOG(("GetTxnPspDetail:: found record for [%s]\n", csOrgTxnSeq));
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "psp_id", &csTmp)) {
					PutField_CString(hContext, "org_psp_id", csTmp);
					PutField_CString(hContext, "psp_id", csTmp);
DEBUGLOG(("GetTxnPspDetail:: psp_id = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "txn_ccy", &csPspCcy)) {
					PutField_CString(hContext, "org_dst_txn_ccy", csPspCcy);
					PutField_CString(hContext, "txn_ccy", csPspCcy);
DEBUGLOG(("GetTxnPspDetail:: psp_txn_ccy = [%s]\n", csPspCcy));
				}

				if (GetField_Double(hRec, "txn_amt", &dPspTxnAmt)) {
					PutField_Double(hContext, "org_dst_net_amt", dPspTxnAmt);
					PutField_Double(hContext, "psp_txn_amt", dPspTxnAmt);
DEBUGLOG(("GetTxnPspDetail:: psp_txn_amt = [%lf]\n", dPspTxnAmt));
				}
 
				if (GetField_CString(hRec, "txn_date", &csOrgPostDate)) {
DEBUGLOG(("GetTxnPspDetail:: txn_date = [%s]\n", csOrgPostDate));
				}

				if (GetField_CString(hRec, "tid", &csTmp)) {
					PutField_CString(hContext, "tid", csTmp);
DEBUGLOG(("GetTxnPspDetail:: tid = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "bank_code", &csTmp)) {
					PutField_CString(hContext, "bank_code", csTmp);
DEBUGLOG(("GetTxnPspDetail:: bank_code = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "fundin_date", &csTmp)) {
					PutField_CString(hContext, "fundin_date", csTmp);
DEBUGLOG(("GetTxnPspDetail:: fundin_date = [%s]\n", csTmp));
				}

				if (GetField_CString(hRec, "bank_bill_no", &csTmp)) {
					PutField_CString(hContext, "bank_bill_no", csTmp);
DEBUGLOG(("GetTxnPspDetail:: bank_bill_no = [%s]\n", csTmp));
				}

				if (GetField_Int(hRec, "recon_ind", &iTmp)) {
					PutField_Int(hContext, "recon_ind", iTmp);
DEBUGLOG(("GetTxnPspDetail:: recon_ind = [%d]\n", iTmp));
					// if (!iTmp) {
// DEBUGLOG(("GetTxnPspDetail:: not allow to reverse before recon\n"));
						// iRet = INT_INVALID_TXN;
						// PutField_Int(hContext, "internal_error", iRet);
						// break;
					// }
				}

				hRec = RecordSet_GetNext(rRecordSet);
			}
		} else {
DEBUGLOG(("GetTxnPspDetail:: not found record for [%s]\n", csOrgTxnSeq));
ERRLOG("TxnMgtByUsRDS: Authorize:: GetTxnDetail:: not found record!!\n");
			iRet = INT_NOT_RECORD;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// get previous charge
	if (iRet == PD_OK && iReturnMerchFee) {
DEBUGLOG(("Authorize:: Call DBTxnElements: GetFeeChgDetailByType\n"));
		recordset_init(rRecordSet, 0);
		DBObjPtr = CreateObj(DBPtr, "DBTxnElements", "GetFeeChgDetailByType");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq, PD_ELEMENT_TXN_FEE, PD_TYPE_MERCHANT, rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_Double(hRec, "amount", &dTmp)) {
					dPreFee += dTmp;
DEBUGLOG(("GetFeeChgDetailByType:: previous fee = [%lf]\n", dTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_code", PD_VOID_TXN_CODE);
		PutField_CString(hContext, "sub_txn_code", PD_DEPOSIT_VOID);
DEBUGLOG(("Authorize:: Call BOFee: GetTxnFee\n"));
		BOObjPtr = CreateObj(BOPtr, "BOFee", "GetTxnFee");
		if ((unsigned long)(*BOObjPtr)(hContext, hRequest) == PD_OK) {
			if (GetField_Double(hContext, "net_amt", &dTmp)) {
DEBUGLOG(("Authorize:: deposit (void) net amt = [%f]\n", dTmp));
				/* real net amt = net amt - previous fee */
				if (iReturnMerchFee) {
					PutField_Double(hContext, "net_amt", (dTmp - dPreFee));
DEBUGLOG(("Authorize:: deposit (void) real net amt = [%f]\n", (dTmp - dPreFee)));
				}
			}
			PutField_CString(hContext, "txn_code", PD_DEPOSIT_REFUND_M);

			// add txn fee element
DEBUGLOG(("Authorize:: Call BOTxnElements: AddTxnFeeElements\n"));
			BOObjPtr = CreateObj(BOPtr, "BOTxnElements", "AddTxnFeeElements");
			iRet = (unsigned long)(*BOObjPtr)(hContext);
		} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: BOFee: GetTxnFee Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: BOFee: GetTxnFee Error\n");
		}
		PutField_CString(hContext, "txn_code", PD_DEPOSIT_REFUND_M);
	}

	if (iRet == PD_OK) {
		dServiceFee = 0.0;
		PutField_Double(hContext, "precal_fee", dServiceFee);
		PutField_Double(hContext, "service_fee", dServiceFee);
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_code", PD_VOID_TXN_CODE);
		PutField_CString(hContext, "sub_txn_code", PD_DEPOSIT_REFUND_M);
		PutField_Int(hContext, "reserve_released", iReleased);
DEBUGLOG(("Authorize:: Call BOBalance: UpdateTxnAmount\n"));
		BOObjPtr = CreateObj(BOPtr, "BOBalance", "UpdateTxnAmount");
		if ((unsigned long)(*BOObjPtr)(hContext, hRequest) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: BOBalance: UpdateTxnAmount Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: BOBalance: UpdateTxnAmount Error\n");
		}
		PutField_CString(hContext, "txn_code", PD_DEPOSIT_REFUND_M);
		PutField_CString(hContext, "sub_txn_code", PD_DEPOSIT_VOID);
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call DBTransaction: Update\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "Update");
		if ((unsigned long)((*DBObjPtr)(hOrgTxn)) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBTransaction: Update Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: DBTransaction: Update Error\n");
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_ccy", csCcy);
DEBUGLOG(("Authorize:: Call DBTransaction: AddDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "AddDetail");
		if ((unsigned long)((*DBObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBTransaction: AddDetail Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: DBTransaction: AddDetail Error\n");
		}
	}

	if (iRet == PD_OK) {
		if (GetField_Double(hContext, "merchant_open_bal", &dTmp)) {
			PutField_Double(hContext, "open_bal", dTmp);
		}
		if (GetField_Double(hContext, "merchant_open_bal_settlement", &dTmp)) {
			PutField_Double(hContext, "open_bal_settlement", dTmp);
		}
DEBUGLOG(("Authorize:: Call DBTransaction: UpdateDetail\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "UpdateDetail");
		if ((unsigned long)((*DBObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBTransaction: UpdateDetail Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: DBTransaction: UpdateDetail Error\n");
		}
	}

/*
	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_ccy", csPspCcy);
		if (GetField_CString(hRequest, "psp_date", &csTmp)) {
			PutField_CString(hContext, "txn_date", csTmp);
		} else {
			if (GetField_CString(hContext, "PHDATE", &csTmp)) {
				PutField_CString(hContext, "txn_date", csTmp);
			}
		}
		if (GetField_CString(hRequest, "report_date", &csTmp)) {
			PutField_CString(hContext, "report_date", csTmp);
		}
		PutField_CString(hContext, "desc", "Void Deposit");
		PutField_Double(hContext, "service_fee", dServiceFee);
		PutField_Double(hContext, "txn_amt", dPspTxnAmt);

DEBUGLOG(("Authorize:: Call DBTxnPspDetail: Add\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnPspDetail", "Add");
		if ((unsigned long)((*DBObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBTxnPspDetail: Add Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: DBTxnPspDetail: Add Error\n");
		}

		PutField_Double(hContext, "txn_amt", dTxnAmt); // restore the txn_amt
	}
*/

/*
	if (iRet == PD_OK) {
		if( GetField_Double(hContext, "psp_balance", &dTmp)) {
			PutField_Double(hContext, "bal", dTmp);
		}
		if (GetField_Double(hContext, "psp_total_float", &dTmp)){
			PutField_Double(hContext, "total_float", dTmp);
		}
		if (GetField_Double(hContext, "psp_total_hold", &dTmp)) {
			PutField_Double(hContext, "total_hold", dTmp);
		}

DEBUGLOG(("Authorize:: Call DBTxnPspDetail: Update\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnPspDetail", "Update");
		if ((unsigned long)((*DBObjPtr)(hContext)) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize:: DBTxnPspDetail: Update Error\n"));
ERRLOG("TxnMgtByUsRDS: Authorize:: DBTxnPspDetail: Update Error\n");
		}
	}
*/

	RecordSet_Destroy(rRecordSet);
	FREE_ME(hOrgTxn);
	FREE_ME(rRecordSet);

DEBUGLOG(("Normal exit iRet = [%d]\n", iRet));
	return iRet;
}
