/*
PDProTech (c)2020. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2020/03/03              [WMC]
Revised						   2020/04/07		   [MSN]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnBalOnUsUPDBAL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

static char cDebug;
OBJPTR(BO);
OBJPTR(DB);


void TxnBalOnUsUPDBAL(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;

	double	dPtr = 0.0;
	
	char	*csTxnSeq = NULL;
	char	*csTxnCode = NULL;
	char	*csMerchantId = NULL;
	char	*csCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csPspId = NULL;
	char	*csPspCcy = NULL;
	char	*csPtr = NULL;

	char	cPtr;
	char	cUpdateStatus = PD_COMPLETE;
	
	hash_t  *hTxn;
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t  *hPspTxn;
        hPspTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hPspTxn,0);

DEBUGLOG(("Authorize()\n"));

/* txnid */
	if (GetField_CString(hContext,"txnid",&csTxnSeq)) {
DEBUGLOG((" txnid = [%s]\n",csTxnSeq));
                PutField_CString(hTxn,"txn_seq",csTxnSeq);
                PutField_CString(hPspTxn,"txn_seq",csTxnSeq);
	} else {
                iRet = INT_TXN_ID_NOT_FOUND;
DEBUGLOG((" txnid missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() txnid missing!!\n");
	}

/* txncode */
	if (iRet == PD_OK) {
        	if (GetField_CString(hContext, "txncode", &csTxnCode)) {
DEBUGLOG((" txncode = [%s]\n",csTxnCode));
        	} else {
			iRet = INT_TXN_CODE_NOT_FOUND;
DEBUGLOG((" txncode missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() txncode missing!!\n");
        	}
	}

/* country */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "country", &csPtr)) {
DEBUGLOG((" country = [%s]\n",csPtr));
                } else {
			iRet = INT_TXN_COUNTRY_NOT_FOUND;
DEBUGLOG((" country missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() country missing!!\n");
                }
        }

/* mid */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "mid", &csMerchantId)) {
DEBUGLOG((" mid = [%s]\n",csMerchantId));
                } else {
			iRet = INT_MERCHANT_ID_NOT_FOUND;
DEBUGLOG((" mid missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() mid missing!!\n");
                }
        }

/* ccy */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "ccy", &csCcy)) {
DEBUGLOG((" ccy = [%s]\n",csCcy));
                } else {
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG((" ccy missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() ccy missing!!\n");
                }
        }

/* service_code */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "service_code", &csServiceCode)) {
DEBUGLOG((" service_code = [%s]\n",csServiceCode));
                } else {
			iRet = INT_SERVICE_CODE_MISSING;
DEBUGLOG((" service_code missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() service_code missing!!\n");
                }
        }

/* open_bal */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "open_bal", &dPtr)) {
DEBUGLOG((" open_bal = [%.2f]\n", dPtr));
			PutField_Double(hTxn, "open_bal", dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" open_bal missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() open_bal missing!!\n");
                }
        }

/* bal */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "bal", &dPtr)) {
DEBUGLOG((" bal = [%.2f]\n", dPtr));
			PutField_Double(hTxn, "current_bal", dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" bal missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() bal missing!!\n");
                }
        }

/* float */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "float", &dPtr)) {
DEBUGLOG((" float = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_float",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" float missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() float missing!!\n");
                }
        }

/* holdback */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "holdback", &dPtr)) {
DEBUGLOG((" holdback = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_reserved_amount",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" holdback missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() holdback missing!!\n");
                }
        }

/* hold */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "hold", &dPtr)) {
DEBUGLOG((" hold = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_hold",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" hold missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() hold missing!!\n");
                }
        }

/* open_bal_sett */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "open_bal_sett", &dPtr)) {
DEBUGLOG((" open_bal_sett = [%.2f]\n", dPtr));
			PutField_Double(hTxn, "open_bal_settlement", dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" open_bal_sett missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() open_bal_sett missing!!\n");
                }
        }

/* bal_sett */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "bal_sett", &dPtr)) {
DEBUGLOG((" bal_sett = [%.2f]\n", dPtr));
			PutField_Double(hTxn, "current_bal_settlement", dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" bal_sett missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() bal_sett missing!!\n");
                }
        }

/* float_sett */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "float_sett", &dPtr)) {
DEBUGLOG((" float_sett = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_float_settlement",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" float_sett missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() float_sett missing!!\n");
                }
        }

/* hold_sett */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "hold_sett", &dPtr)) {
DEBUGLOG((" hold_sett = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_hold_settlement",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" hold_sett missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() hold_sett missing!!\n");
                }
        }

/* fundin_po */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "fundin_po", &dPtr)) {
DEBUGLOG((" fundin_po = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"fundin_payout",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" fundin_po missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() fundin_po missing!!\n");
                }
        }

/* resv_po */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "resv_po", &dPtr)) {
DEBUGLOG((" resv_po = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"reserved_payout",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" resv_po missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() resv_po missing!!\n");
                }
        }

/* afpo_float */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "afpo_float", &dPtr)) {
DEBUGLOG((" afpo_float = [%.2f]\n",dPtr));
			PutField_Double(hTxn,"total_float_after_payout",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" afpo_float missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() afpo_float missing!!\n");
                }
        }

/* psp_id */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "psp_id", &csPspId)) {
DEBUGLOG((" psp_id = [%s]\n", csPspId));
                } else {
			iRet = INT_PSP_ID_NOT_FOUND;
DEBUGLOG((" psp_id missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_id missing!!\n");
                }
        }

/* psp_ccy */
        if (iRet == PD_OK) {
                if (GetField_CString(hContext, "psp_ccy", &csPspCcy)) {
DEBUGLOG((" psp_ccy = [%s]\n", csPspCcy));
                } else {
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG((" psp_ccy missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_ccy missing!!\n");
                }
        }

/* psp_bal */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "psp_bal", &dPtr)) {
DEBUGLOG((" psp_bal = [%.2f]\n",dPtr));
			PutField_Double(hPspTxn,"bal",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" psp_bal missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_bal missing!!\n");
                }
        }

/* psp_float */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "psp_float", &dPtr)) {
DEBUGLOG((" psp_float = [%.2f]\n",dPtr));
			PutField_Double(hPspTxn,"total_float",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" psp_float missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_float missing!!\n");
                }
        }

/* psp_hold */
        if (iRet == PD_OK) {
                if (GetField_Double(hContext, "psp_hold", &dPtr)) {
DEBUGLOG((" psp_hold = [%.2f]\n",dPtr));
			PutField_Double(hPspTxn,"total_hold",dPtr);
                } else {
			iRet = INT_ERR;
DEBUGLOG((" psp_hold missing!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_hold missing!!\n");
                }
        }


	// update_user
        PutField_CString(hTxn,"update_user",PD_UPDATE_USER);
        PutField_CString(hPspTxn,"update_user",PD_UPDATE_USER);


	//lock txn_header
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MatchRespTxn");
		if ((unsigned long)(DBObjPtr)(csTxnSeq, PD_COMPLETE) != PD_FOUND) {
			iRet = INT_INVALID_TXN;
DEBUGLOG((" Transaction [%s] status is not [%c]\n", csTxnSeq, PD_COMPLETE));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() Transaction [%s] status is not [%c]\n", csTxnSeq, PD_COMPLETE);
		}
	}

	// Get txn_header & txn_psp_detail
	if (iRet == PD_OK) {
DEBUGLOG(("Call BOTransaction::GetTxnInfo()\n"));
		
		hash_t  *hIn;
		hIn = (hash_t*)  malloc (sizeof(hash_t));
		hash_init(hIn,0);

		hash_t  *hOut;
		hOut = (hash_t*)  malloc (sizeof(hash_t));
		hash_init(hOut,0);

		PutField_CString(hIn, "txn_seq", csTxnSeq);
		PutField_Int(hIn, "get_txn_header", PD_TRUE);
		PutField_Int(hIn, "get_txn_psp_detail", PD_TRUE);

		BOObjPtr = CreateObj(BOPtr, "BOTransaction", "GetTxnInfo");
          	if ((*BOObjPtr)(hIn, hOut) == PD_OK) {

/* check txn_code */
			if(GetField_CString(hOut, "txn_code", &csPtr)){
				if(strcmp(csTxnCode, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" txn_code not matched!! [%s][%s]\n", csTxnCode, csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() txn_code not matched!! [%s][%s]\n", csTxnCode, csPtr);
				}
			}

/* check merchant_id */
			if(GetField_CString(hOut, "merchant_id", &csPtr)){
				if(strcmp(csMerchantId, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" merchant_id not matched!! [%s][%s]\n", csMerchantId, csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() merchant_id not matched!! [%s][%s]\n", csMerchantId, csPtr);
				}
			}

/* check net_ccy */
			if(GetField_CString(hOut, "net_ccy", &csPtr)){
				if(strcmp(csCcy, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" net_ccy not matched!! [%s][%s]\n", csCcy, csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() net_ccy not matched!! [%s][%s]\n", csCcy, csPtr);
				}
			}

/* check service_code */
			if(GetField_CString(hOut, "service_code", &csPtr)){
				if(strcmp(csServiceCode, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" service_code not matched!! [%s][%s]\n", csServiceCode, csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() service_code not matched!! [%s][%s]\n", csServiceCode, csPtr);
				}
			}

/* check psp_id */
			if(GetField_CString(hOut, "psp_id", &csPtr)){
				if(strcmp(csPspId, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" psp_id not matched!! [%s][%s]\n", csPspId, csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_id not matched!! [%s][%s]\n", csPspId, csPtr);
				}
			}

/* check psp_txn_ccy */
			if(GetField_CString(hOut, "psp_txn_ccy", &csPtr)){
				if(strcmp(csPspCcy, csPtr)){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" psp_txn_ccy not matched!! [%s][%s]\n",csPspCcy , csPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() psp_txn_ccy not matched!! [%s][%s]\n", csPspCcy, csPtr);
				}
			}

/* check ar_ind */
			if(GetField_Char(hOut, "ar_ind", &cPtr)){
				if(cPtr != PD_ACCEPT){
					iRet = INT_INVALID_TXN;
DEBUGLOG((" txn ar_ind invalid!! [%c]\n",cPtr));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() txn ar_ind invalid!! [%c]\n",cPtr);
				}
			}

		} else {
                   	iRet = INT_ERR;
DEBUGLOG(("GetTxnInfo for [%s] failed, csTxnSeq\n"));
		}

		hash_destroy(hIn);
		FREE_ME(hIn);

		hash_destroy(hOut);
		FREE_ME(hOut);
	}

/* Update merchant balance information in Txn Detail if not exist */
	if (iRet == PD_OK) {

DEBUGLOG(("Call DBTransaction::MerchBalInTxnDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "MerchBalInTxnDetail");
             	if ((unsigned long)(*DBObjPtr)(csTxnSeq) == PD_TRUE) {
			cUpdateStatus = PD_EXPIRED;
DEBUGLOG(("balance information alrady exists in txn_detail, skip update\n"));
		} else {
			// Update Txn Detail
DEBUGLOG(("Call DBTransaction::UpdateDetail()\n"));
          		DBObjPtr = CreateObj(DBPtr, "DBTransaction", "UpdateDetail");
             		iRet = (unsigned long)(*DBObjPtr)(hTxn);
			if (iRet != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("UpdateDetail failed!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() Call DBTransaction::UpdateDetail() failed!!\n");
			}
    		}
	}
	
/* Update psp balance information in Txn Psp Detail if not exist */
	if (iRet == PD_OK) {

DEBUGLOG(("Call DBTxnPspDetail::PspBalInTxnPspDetail()\n"));
 	        DBObjPtr = CreateObj(DBPtr, "DBTxnPspDetail", "PspBalInTxnPspDetail");
                if ((unsigned long)(*DBObjPtr)(csTxnSeq) == PD_TRUE) {
			cUpdateStatus = PD_EXPIRED;
DEBUGLOG(("balance information alrady exists in txn_psp_detail, skip update\n"));
                } else {
			// Update Txn Psp Detail
DEBUGLOG(("Call DBTxnPspDetail::Update()\n"));
        	       	DBObjPtr = CreateObj(DBPtr, "DBTxnPspDetail", "Update");
        	     	iRet = (unsigned long)(*DBObjPtr)(hPspTxn);
			if (iRet != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Update failed!!\n"));
ERRLOG("TxnBalOnUsUPDBAL::Authorize() Call DBTxnPspDetail::Update() failed!!\n");
			}
      		}
	}

/* update status in txn_balance_detail */
	if (iRet == PD_OK) {
DEBUGLOG(("Call DBTxnBalanceDetail::UpdateStatus()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBTxnBalanceDetail", "UpdateStatus");
		if ((unsigned long)(*DBObjPtr)(csTxnSeq, cUpdateStatus) != PD_OK) {
DEBUGLOG(("UpdateStatus failed!!\n"));
		}
	}

	hash_destroy(hTxn);
        FREE_ME(hTxn);	

	hash_destroy(hPspTxn);
        FREE_ME(hPspTxn);

DEBUGLOG(("Authorize() iRet = [%d]\n",iRet));
	return iRet;
}
