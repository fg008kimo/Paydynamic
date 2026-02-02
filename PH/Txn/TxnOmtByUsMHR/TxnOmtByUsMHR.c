/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/09/07              [WWK]
Revise Paramter In 
Calling DBOLBankAcctId::GetBankAcctIdDtl           2020/05/11              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsMHR.h"
#include "myrecordset.h"

char cDebug;

OBJPTR(DB);

void TxnOmtByUsMHR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                  hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	cTmp;
	char	*csTmp;

	int	iFlag = 0;
	char	cHoldType;
	char	cTxnType;
	char    *csTxnSeq;
	char	*csUser;

	char	*csBankCode;
	char	*csBankAcctNum;

	hash_t  *hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

	hash_t	*hTemp = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTemp,0);

	hash_t	*hRec = NULL;
	recordset_t     *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);	

DEBUGLOG(("Authorize()\n"));

// hold_type
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"hold_type",&csTmp)) {
			cHoldType = csTmp[0];
DEBUGLOG(("Authorize: hold_type = [%c]\n",cHoldType));
		} else {
DEBUGLOG(("Authorize:: hold_type not found!!\n"));
ERRLOG("TxnOmtByUsMHR:: Authorize:: hold_type not found!!\n");
			iRet = INT_HOLD_TYPE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// txn_type
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"txn_type",&csTmp)) {
			cTxnType = csTmp[0];
DEBUGLOG(("Authorize: txn_type = [%c]\n",cTxnType));
		} else {
DEBUGLOG(("Authorize:: txn_type not found!!\n"));
ERRLOG("TxnOmtByUsMHR:: Authorize:: txn_type not found!!\n");
			iRet = INT_TXN_TYPE_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// txn_seq
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"org_txn_seq",&csTxnSeq)) {
DEBUGLOG(("Authorize: txn_seq = [%s]\n",csTxnSeq));
		} else {
DEBUGLOG(("Authorize:: txn_id not found!!\n"));
ERRLOG("TxnOmtByUsMHR:: Authorize:: txn_id not found!!\n");
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// user
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest,"add_user",&csUser)) {
DEBUGLOG(("Authorize: user = [%s]\n",csUser));
		} else {
DEBUGLOG(("Authorize:: user not found!!\n"));
ERRLOG("TxnOmtByUsMHR:: Authorize:: user not found!!\n");
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (iRet == PD_OK) {

		//Check case for Txn Level
		if (cTxnType == PD_TXN_LEVEL) {
			recordset_init(rRecordSet,0);

			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnIdForUpdateNoWait");
			iRet = (unsigned long)(*DBObjPtr)(csTxnSeq);
			if (iRet != PD_OK) {
				iRet = INT_TXN_ID_IS_LOCKED;
			}
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLTransaction:GetTxnIdForUpdate\n",iRet));

			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
				iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLTransaction:GetTxnHeader\n",iRet));
			}

			if (iRet == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
					if (GetField_CString(hRec, "txn_code", &csTmp)) {
						if (strcmp(csTmp,PD_OFFSYS_PAYOUT_GEN_TXN_CODE)) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! Txn code not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! Txn code not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! Txn code not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! Txn Code not found\n");
					}

					if (GetField_Char(hRec, "recon_status", &cTmp)) {
						if (cTmp == PD_RECONCILED) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! recon status not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! recon status not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! recon status not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! recon status not found\n");
					}

					if (GetField_Char(hRec, "status", &cTmp)) {
						if (cTmp != PD_COMPLETE) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! status not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! status not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! status not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! status not found\n");
					}

					if (GetField_Char(hRec, "ar_ind", &cTmp)) {
						if (cTmp != PD_ACCEPT) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! ar_ind not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! ar_ind not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! ar_ind not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! ar_ind not found\n");
					}

					hRec = RecordSet_GetNext(rRecordSet);
				}
			} else {
				PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLTransaction:GetTxnHeader\n",iRet);
			}

			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
				iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,hData);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLTxnPspDetail:GetTxnPspDetail\n",iRet));

				if (iRet == PD_OK) {
					if (GetField_CString(hData,"baid",&csTmp)) {
DEBUGLOG(("Authorize:: baid = [%s]\n",csTmp));
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLTxnPspDetail:GetTxnPspDetail\n",iRet);
				}
			}

			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBankAcctIdDtl");
				iRet = (unsigned long)(*DBObjPtr)(csTmp, hTemp);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLBankAcctId:GetBankAcctIdDtl\n",iRet));

				if (iRet == PD_OK) {
					if (GetField_CString(hTemp, "category", &csTmp)) {
						if (strcmp(csTmp,PD_BAID_CAT_TEMP)) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! baid category not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! baid category not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! baid category not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! baid category not found\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLBankAcctId:GetBankAcctIdDtl\n",iRet);
				}
			}

		} else if (cTxnType == PD_STMT_LEVEL) {
		
		//Check case for Stmt Level
			DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "MatchRespTxnNoWait");
			iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,PD_COMPLETE);
			if (iRet != PD_FOUND) {
				iRet = INT_TXN_ID_IS_LOCKED;
			} else iRet = PD_OK;
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLBAIDTxn:MatchRespTxn\n",iRet));

			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "GetBaidTxn");
				iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,hData);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLBAIDTxn:GetBaidTxn\n",iRet));
			}

			if (iRet == PD_OK) {

				if (GetField_CString(hData,"bank_code",&csBankCode)) {
DEBUGLOG(("Authorize:: bank_code = [%s]\n",csBankCode));
				}

				if (GetField_CString(hData,"bank_acct_num",&csBankAcctNum)) {
DEBUGLOG(("Authorize:: bank_acct_num = [%s]\n",csBankAcctNum));
				}

				if (GetField_CString(hData,"txn_code",&csTmp)) {
					if (strcmp(csTmp,PD_TXN_CODE_UNKNOWN_CREDIT) &&
					    strcmp(csTmp,PD_TXN_CODE_UNKNOWN_DEBIT) &&
					    strcmp(csTmp,PD_TXN_CODE_UNKNOWN_SWEEP_IN) &&
					    strcmp(csTmp,PD_TXN_CODE_UNKNOWN_SWEEP_OUT)) {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! txn code not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! txn code not allow\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! txn code not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! txn code not found\n");
				}

				if (GetField_Char(hData,"recon_status",&cTmp)) {
					if (cTmp == PD_RECONCILED) {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! recon status not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! recon status not allow\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! recon status not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! recon status not found\n");
				}

				if (GetField_Char(hData, "status", &cTmp)) {
					if (cTmp != PD_COMPLETE) {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! status not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! status not allow\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! status not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! status not found\n");
				}

				if (GetField_Char(hData, "ar_ind", &cTmp)) {
					if (cTmp != PD_ACCEPT) {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! ar_ind not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! ar_ind not allow\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! ar_ind not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! ar_ind not found\n");
				}

			} else {
				PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLBAIDTxn:GetBaidTxn\n",iRet);
			}

			if (iRet == PD_OK) {
				DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "GetBankAccts");
				iRet = (unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum,hData);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLBankAccts:GetBankAccts\n",iRet));

				if (iRet == PD_OK) {
					if (GetField_CString(hData,"acct_type",&csTmp)) {
						if (!strcmp(csTmp,PD_NATURE_DEPOSIT)) {
							DBObjPtr = CreateObj(DBPtr, "DBOLStatement", "GetStmtDtlByBAIDTxnId");
							iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,hData);
DEBUGLOG(("Authorize:: iRet [%d] Call DBOLStatement:GetDetail\n",iRet));

							if (iRet == PD_OK) {
								if (!GetField_CString(hData,"stmt_ref",&csTmp)) {
									iRet = INT_ERR;
									PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! SMS stmt not allow \n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! SMS stmt not allow\n");
								}
							} else {
								iRet = INT_ERR;
								PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLStatement:GetDetail\n",iRet);
							}

						} else if (strcmp(csTmp,PD_NATURE_INTERMEDIATE) &&
							   strcmp(csTmp,PD_NATURE_PAYOUT)) {
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! bank acct type not allow\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! bank acct type not allow\n");
						}
					} else {
						iRet = INT_ERR;
						PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize:: Invalid transaction!!! bank acct type not found\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid transaction!!! bank acct type not found\n");
					}
				} else {
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
ERRLOG("Authorize:: iRet [%d] Call DBOLBankAccts:GetBankAccts\n",iRet);
				}

			}

		} else {
DEBUGLOG(("Authorize:: Invalid txn_type!!!\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid txn_type!!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}

        	if (iRet == PD_OK) {
			if (!GetField_Int(hData,"manual_hold_recon",&iFlag)) {
				iFlag = 0;
			}
DEBUGLOG(("Authorize:: Existing manual_hold_recon = [%d]\n",iFlag));

			if (cHoldType == PD_HOLD) {
				if (iFlag != PD_MANUAL_UNHOLD_RECON_DEFAULT && iFlag != PD_MANUAL_UNHOLD_RECON) {
DEBUGLOG(("Authorize:: Invaild hold_type!!\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid hold_type!!!\n");
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
				} else {
					PutField_Int(hData,"manual_hold_recon",PD_MANUAL_HOLD_RECON);
DEBUGLOG(("Authorize:: New manual_hold_recon = [%d]\n",iFlag));
				}
			} else if (cHoldType == PD_UNHOLD) {
				if (iFlag != PD_MANUAL_HOLD_RECON) {
DEBUGLOG(("Authorize:: Invaild hold_type!!\n"));
ERRLOG("TxnOmtByUsMHR::Authorize:: Invalid hold_type!!!\n");
					iRet = INT_ERR;
					PutField_Int(hContext,"internal_error",iRet);
				} else {
					PutField_Int(hData,"manual_hold_recon",PD_MANUAL_UNHOLD_RECON);
DEBUGLOG(("Authorize:: New manual_hold_recon = [%d]\n",iFlag));
				}
			}
		}

		if (iRet == PD_OK) {
			PutField_CString(hData,"update_user",csUser);
			PutField_CString(hData,"txn_seq",csTxnSeq);

			if (cTxnType == PD_TXN_LEVEL) {
DEBUGLOG(("Authorize:: Call DBOLTxnPspDetail:Update()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Update");
				iRet = (unsigned long)(*DBObjPtr)(hData);
			} else if (cTxnType == PD_STMT_LEVEL) {
DEBUGLOG(("Authorize:: Call DBOLBAIDTxn:Update()\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBAIDTxn", "Update");
				iRet = (unsigned long)(*DBObjPtr)(hData);
			}

DEBUGLOG(("Authorize:: iRet [%d] for Update()\n",iRet));
			if (iRet != PD_OK) {
ERRLOG("Authorize:: iRet [%d] for Update()\n",iRet);
			}
		}

	}

	hash_destroy(hData);
        FREE_ME(hData);

	hash_destroy(hTemp);
	FREE_ME(hTemp);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsMHR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

