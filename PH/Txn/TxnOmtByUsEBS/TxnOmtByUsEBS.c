/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/10              Stan Poon
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsEBS.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnOmtByUsEBS(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	char	*csTmp=NULL;
	char	*csOrgTxnSeq=NULL, *csTxnSeq=NULL;
	char	*csOrgTxnCode=NULL, csTxnCode[PD_TXN_CODE_LEN+1];
	char	*csOrgSubStatus=NULL, csSubStatus[PD_SUB_STATUS_LEN + 1];
	char	*csRemark=NULL, *csAutoExpired=NULL, *csUser=NULL;
	char	*csBankCode=NULL, *csBankAcctNum=NULL, *csBranchName=NULL, *csOwnerName=NULL;
	char	*csMerchantId=NULL, *csClientId=NULL;
	char	*csService=NULL, *csPayMethod=NULL;
	char	csCountry[PD_COUNTRY_LEN + 1];
	int	iSharedAcct=1;

	char	cStatus, cArInd, *csCcy=NULL;
	double	dAmt=0.0;
	char	csTxnDateTime[PD_DATETIME_LEN+1];
	double	dTmp;
	double	dOpenBal=0.0, dOpenBalSett=0.0;

	hash_t *hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));

	recordset_t* myRec;
	hash_t *hRec;

/* txn_seq */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "org_txn_seq", &csOrgTxnSeq)) {
			PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n", csOrgTxnSeq));
		} else {
			iRet = INT_TXN_ID_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() txn_seq is missing!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() txn_seq is missing!!!\n");
		}
	}
/* remark */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "remark", &csRemark)) {
			PutField_CString(hContext,"remark",csRemark);
DEBUGLOG(("Authorize() remark = [%s]\n", csRemark));
		}
	}
/* auto_expired */
	if (iRet == PD_OK) {
		strcpy(csTxnCode,PD_MANUAL_EXPIRED_TXN_CODE);
		strcpy(csSubStatus,PD_MANUAL_ACCEPTED);
		if (GetField_CString(hRequest, "auto_expired", &csAutoExpired)) {
			if (csAutoExpired[0] == 'Y') {
				strcpy(csTxnCode,PD_AUTO_EXPIRED_TXN_CODE);
				strcpy(csSubStatus,PD_AUTO_EXPIRED);
			}
DEBUGLOG(("Authorize() auto_expired = [%c]\n", csAutoExpired[0]));
		}
	}
/* user */
	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "add_user", &csUser)) {
			PutField_CString(hContext,"create_user",csUser);
			PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
		} else {
			iRet = INT_USER_NOT_FOUND;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() user is missing!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() user is missing!!!\n");
		}
	}


/* MatchRespTxn */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction:: MatchRespTxn()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "MatchRespTxn");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_COMPLETE) != PD_FOUND) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() call DBOLTransaction:: MatchRespTxn() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction:: MatchRespTxn() FAILURE!!!\n");
		}
	}


/* Get Ol Txn Psp Detail - bank_code, bank_acct_num */
	if (iRet == PD_OK) {
		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec,0);

DEBUGLOG(("Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "GetTxnPspDetail");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,hRec) != PD_OK) {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() FAILURE!!!\n");
		} else {
			if (!GetField_CString(hRec,"bank_code",&csBankCode)) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() bank code NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() bank code NOT FOUND!!!\n");
			} else if (!GetField_CString(hRec,"bank_acct_num",&csBankAcctNum)) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() bank_acct_num NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTxnPspDetail:: GetTxnPspDetail() bank_acct_num NOT FOUND!!!\n");
			}
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}


/* get bank country */
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBBankDesc::GetBankCountry()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBBankDesc","GetBankCountry");
		if ((unsigned long)(*DBObjPtr)(csBankCode,csCountry) != FOUND) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBBankDesc::GetBankCountry() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBBankDesc::GetBankCountry() FAILURE!!!\n");
		}
	}


/* GetBankAccts - shared_acct, branch_name, owner_name */
	if (iRet == PD_OK) {
		hRec = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hRec,0);

DEBUGLOG(("Authorize() call DBOLBankAccts:: GetBankAccts()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLBankAccts", "GetBankAccts");
		if ((unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum,hRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts:: GetBankAccts() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLBankAccts:: GetBankAccts() FAILURE!!!\n");
		} else {
			if (GetField_Int(hRec,"shared_acct",&iSharedAcct)) {
DEBUGLOG(("Authorize() call DBOLBankAccts:: GetBankAccts() shared_acct = [%d]\n",iSharedAcct));
			}

			if (!GetField_CString(hRec,"branch_name",&csBranchName)) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts() branch_name NOT FOUND!!!\n"));
			} else if (!GetField_CString(hRec,"owner_name",&csOwnerName)) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts() owner_name NOT FOUND!!!\n"));
			}

		/* not shared bank acct */
			if (iSharedAcct != 0) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() call DBOLBankAccts:: shared_acct NOT SUPPORT!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLBankAccts:: shared_acct NOT SUPPORT!!!\n");
			}
		}

		hash_destroy(hRec);
		FREE_ME(hRec);
	}


/* FindDetailByBankAcct - merchant_id, service_code */
	if (iRet == PD_OK) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

DEBUGLOG(("Authorize() call DBOLMerchantBankAcct:: FindDetailByBankAcct()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLMerchantBankAcct", "FindDetailByBankAcct");
		if ((unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum,myRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLMerchantBankAcct:: FindDetailByBankAcct() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLMerchantBankAcct:: FindDetailByBankAcct() FAILURE!!!\n");
		} else {
			hRec = RecordSet_GetFirst(myRec);
			if (hRec) {
				if (!GetField_CString(hRec,"merchant_id",&csMerchantId)) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts() merchant_id NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLMerchantBankAcct:: merchant_id NOT FOUND!!\n");
				}
			/* not shared bank acct */
				if (!GetField_CString(hRec,"service_code",&csService)) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts() service_code NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLMerchantBankAcct:: service_code NOT FOUND!!!\n");
				}
			}
		}

		RecordSet_Destroy(myRec);
		FREE_ME(myRec);
	}


/* GetMerchant - client_id */
	if (iRet == PD_OK) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

DEBUGLOG(("Authorize() call DBOLMerchDetail:: GetMerchant()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLMerchDetail", "GetMerchant");
		if ((unsigned long)(*DBObjPtr)(csMerchantId,myRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLMerchDetail:: GetMerchant() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLMerchDetail:: GetMerchant() FAILURE!!!\n");
		} else {
			hRec = RecordSet_GetFirst(myRec);
			if (hRec) {
				if (!GetField_CString(hRec,"merchant_client_id",&csClientId)) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts() client_id NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLMerchDetail:: client_id NOT FOUND!!\n");
				}
			}
		}

		RecordSet_Destroy(myRec);
		FREE_ME(myRec);
	}


/* pay_method */
	if (iRet == PD_OK) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

		char*	csValueTmp;
		int iCnt;
		csValueTmp = (char*) malloc (128);
DEBUGLOG(("Authorize() Call DBSystemParameter FindCode\n"));
		DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
		if ((unsigned long)(DBObjPtr)(PD_SERVICE_PAY_METHOD,csValueTmp) == FOUND) {
DEBUGLOG(("Authorize() %s [%s]\n",PD_SERVICE_PAY_METHOD,csValueTmp));
			if(strcmp(csValueTmp,"Y")==0){
				iCnt = 0;
DEBUGLOG(("Authorize() Call DBServicePayMethod FindPayMethod\n"));
				DBObjPtr = CreateObj(DBPtr,"DBServicePayMethod","FindPayMethod");
				if ((unsigned long)(DBObjPtr)(csService,myRec) == PD_OK) {
					hRec = RecordSet_GetFirst(myRec);
					if (GetField_CString(hRec,"pay_method",&csPayMethod)) {
						iCnt++;
DEBUGLOG(("Authorize() pay_method [%s]\n",csPayMethod));
DEBUGLOG(("Authorize() Call DBMerchantPayMethod:Add\n"));
					}
				}
				if(iCnt==0){
					iRet = INT_ERR;
DEBUGLOG(("Authorize() cannot find pay_method from service[%s]\n",csService));
ERRLOG("TxnOmtByUsEBS::Authorize() cannot find pay_method from service\n");
				}
			} else {
				//csValueTmp not "Y" ->  do nothing
			}
		} else {
			iRet = INT_ERR;
ERRLOG("TxnOmtByUsEBS::Authorize() DBSystemParameter FindCode fail!!!\n");
		}
		FREE_ME(csValueTmp);

		RecordSet_Destroy(myRec);
		FREE_ME(myRec);
	}


/* Get Ol Txn Header */
	if (iRet == PD_OK) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,myRec) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction:: GetTxnHeader() FAILURE!!!\n");
		} else {
			hRec = RecordSet_GetFirst(myRec);
			if (hRec) {
				if (GetField_CString(hRec,"txn_code",&csOrgTxnCode)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() txn_code = [%s]\n",csOrgTxnCode));
				}
				if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() status = [%c]\n",cStatus));
				}
				if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() ar_ind = [%c]\n",cArInd));
				}
				if (GetField_CString(hRec,"sub_status",&csOrgSubStatus)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() sub_status = [%s]\n",csOrgSubStatus));
				}
				if (GetField_Double(hRec,"txn_amt",&dAmt)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() txn_amt = [%.2lf]\n",dAmt));
				}
				if (GetField_CString(hRec,"net_ccy",&csCcy)) {
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() net_ccy= [%s]\n",csCcy));
				}

			/* status, ar_ind, sub_status */
				if (cStatus != PD_COMPLETE) {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Invalid status = [%c]\n",cStatus));
ERRLOG("TxnOmtByUsEBS::Authorize() Invalid status!!!\n");
				}
				if (cArInd != PD_ACCEPT) {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Invalid ar_ind = [%c]\n",cArInd));
ERRLOG("TxnOmtByUsEBS::Authorize() Invalid ar_ind!!!\n");
				}
				if (strcmp(csOrgSubStatus,PD_UNALLOCATED)) {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() Invalid sub_status = [%s]\n",csOrgSubStatus));
ERRLOG("TxnOmtByUsEBS::Authorize() Invalid sub_status!!!\n");
				}
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction:: GetTxnHeader() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction:: GetTxnHeader() FAILURE!!!\n");
			}
		}

		RecordSet_Destroy(myRec);
		FREE_ME(myRec);
	}


/* Add Txn Header */
	if (iRet == PD_OK) {
		hash_init(hTxn,0);

		PutField_Int(hTxn,"db_commit",PD_FALSE);
		if (GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
			PutField_CString(hTxn,"txn_seq",csTxnSeq);
DEBUGLOG(("Authorize() txn_seq = [%s]\n", csTxnSeq));
		}
		PutField_CString(hTxn,"org_txn_seq",csOrgTxnSeq);

		PutField_CString(hTxn,"channel_code","OMT");
		PutField_Char(hTxn,"status",PD_TO_PSP);

		PutField_CString(hTxn,"txn_code",csTxnCode);
		PutField_CString(hTxn,"process_type","0000");
		PutField_CString(hTxn,"process_code","000000");
		PutField_CString(hTxn,"merchant_id",csMerchantId);
		PutField_CString(hTxn,"client_id",csClientId);
		if (GetField_CString(hContext,"PHDATE",&csTmp)) {
			PutField_CString(hTxn,"host_posting_date",csTmp);
		}
		PutField_Int(hTxn,"internal_code",0);
		PutField_CString(hTxn,"response_code","0");
		PutField_Double(hTxn,"txn_amt",dAmt);

		if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
			PutField_CString(hTxn, "local_tm_date", csTmp);
			strcpy(csTxnDateTime, csTmp);
			PutField_CString(hTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hTxn, "tm_date", csTmp);
		}
		if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
			PutField_CString(hTxn, "local_tm_time", csTmp);
			strcat(csTxnDateTime, csTmp);
			PutField_CString(hTxn, "transmission_datetime", csTxnDateTime);
			PutField_CString(hTxn, "tm_time", csTmp);
		}

		if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
			PutField_CString(hTxn,"ip_addr",csTmp);
		}
		PutField_CString(hTxn,"service_code",csService);
		if (GetField_CString(hRequest,"user_agent",&csTmp)) {
			PutField_CString(hTxn,"user_agent",csTmp);
		}

		PutField_CString(hTxn,"add_user",csUser);
DEBUGLOG(("Authorize() call DBOLTransaction::Add()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Add");
		if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction::Add() FAILURE!!!\n");
		}

		hash_destroy(hTxn);
	}


/* Add Ol Txn Detail */
	if (iRet == PD_OK) {
		hash_init(hTxn,0);

		PutField_CString(hTxn,"txn_seq",csTxnSeq);
		PutField_CString(hTxn,"txn_ccy",csCcy);
		PutField_CString(hTxn,"txn_country",csCountry);
		if (csPayMethod != NULL)
			PutField_CString(hTxn,"pay_method",csPayMethod);
		PutField_CString(hTxn,"bank_acct_num",csBankAcctNum);
		PutField_CString(hTxn,"bank_code",csBankCode);
		PutField_CString(hTxn,"branch_name",csBranchName);
		PutField_CString(hTxn,"account_id",csOwnerName);
		if (csPayMethod != NULL)
			PutField_CString(hTxn,"selected_pay_method",csPayMethod);
		PutField_CString(hTxn,"remark",csRemark);

		PutField_CString(hTxn,"add_user",csUser);
		PutField_CString(hTxn,"update_user",csUser);
DEBUGLOG(("Authorize() call DBOLTransaction::AddDetail()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","AddDetail");
		if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::AddDetail() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction::AddDetail() FAILURE!!!\n");
		}

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction::UpdateDetail()\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","UpdateDetail");
			if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::UpdateDetail() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction::UpdateDetail() FAILURE!!!\n");
			}
		}

		hash_destroy(hTxn);
	}


/* Add Ol Txn Fee */
	if (iRet == PD_OK) {
		myRec = (recordset_t*) malloc (sizeof(recordset_t));
		recordset_init(myRec,0);

		DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetAllFeeChgDetail");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,myRec) == PD_OK) {
			hRec = RecordSet_GetFirst(myRec);
			while (hRec && iRet == PD_OK) {
				hash_init(hTxn,0);

				PutField_CString(hTxn,"txn_seq",csTxnSeq);
				if(GetField_CString(hRec,"txn_element_type",&csTmp)){
					PutField_CString(hTxn,"txn_element_type",csTmp);
				}
				PutField_Char(hTxn,"party_type",PD_TYPE_MERCHANT);
				if(GetField_Double(hRec,"amount",&dTmp)){
					PutField_Double(hTxn,"amount",dTmp);
				}
				if(GetField_CString(hRec,"ccy",&csTmp)){
					PutField_CString(hTxn,"ccy",csTmp);
				}
				if(GetField_CString(hRec,"amt_type",&csTmp)){
					PutField_CString(hTxn,"amount_type",csTmp);
				}
				PutField_CString(hTxn,"add_user",csUser);
DEBUGLOG(("Authorize() call DBOLTxnElements::Add()\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");
				if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
					iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTxnElements::Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTxnElements::Add() FAILURE!!!\n");
				}

				hash_destroy(hTxn);
				hRec = RecordSet_GetNext(myRec);
			}
		}

		RecordSet_Destroy(myRec);
		FREE_ME(myRec);
	}


/* Update Ol Txn Header - org */
	if (iRet == PD_OK) {
		hash_init(hTxn,0);

		PutField_CString(hTxn,"txn_seq",csOrgTxnSeq);
		PutField_Char(hTxn,"status",PD_COMPLETE);
		PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
		PutField_CString(hTxn,"sub_status",csSubStatus);
		PutField_CString(hTxn,"update_user",PD_UPDATE_USER);

DEBUGLOG(("Authorize() call DBOLTransaction::Update()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		if ((unsigned long)(*DBObjPtr)(hTxn) == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction::Update() Success\n"));
		} else {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction::Update() FAILURE!!!\n");
		}

		hash_destroy(hTxn);
	}


/* Add Ol Txn Remarks - new */
	if (iRet == PD_OK) {
		hash_init(hTxn,0);

		PutField_CString(hTxn,"txn_seq",csTxnSeq);
		PutField_CString(hTxn,"txn_code",csTxnCode);
		PutField_CString(hTxn,"remark",csRemark);
		PutField_CString(hTxn,"add_user",csUser);
DEBUGLOG(("Authorize() call DBOLTransaction:: Add()\n"));
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnRemarks", "Add");
		if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction:: Add() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction:: Add() FAILURE!!!\n");
		}

		hash_destroy(hTxn);
	}

/*
 *
 *
 * */
/* Update OL Merchant Balance */
	if (iRet == PD_OK) {
		hash_init(hTxn,0);

		DBObjPtr = CreateObj(DBPtr, "DBOLMerchantBalance", "GetCurrentValuesForUpdate");
		if ((unsigned long)(*DBObjPtr)(csMerchantId, csCcy, csCountry, csService, hTxn) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLMerchantBalance::GetCurrentValuesForUpdate() FAILED!!!\n"));
ERRLOG("TxnOmtByUsEBS: Authorize() call DBOLMerchantBalance::GetCurrentValuesForUpdate() FAILED!!!\n");
		} else {
			if (GetField_Double(hTxn, "current_bal", &dOpenBal)) {
				PutField_Double(hContext, "open_bal", dOpenBal);
DEBUGLOG(("Authorize() call DBOLMerchantBalance::GetCurrentValuesForUpdate() current_bal = [%f]\n", dOpenBal));
			}
			if (GetField_Double(hTxn, "current_bal_settlement", &dOpenBalSett)) {
				PutField_Double(hContext, "open_bal_settlement", dOpenBalSett);
DEBUGLOG(("Authorize() call DBOLMerchantBalance::GetCurrentValuesForUpdate() current_bal_settlement = [%f]\n", dOpenBalSett));
			}
		}

		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
			(*DBObjPtr)(hContext);

			DBObjPtr = CreateObj(DBPtr, "DBOLMerchantBalance", "UpdateCurrBal");
			if ((unsigned long)(*DBObjPtr)(csMerchantId, csCountry, csCcy, csService,
								dAmt, PD_UPDATE_USER) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() DBOLMerchantBalance::UpdateCurrBal failed!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() DBOLMerchantBalance::UpdateCurrBal failed!!!\n");
			}
		}

		if (iRet==PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetCurrentValues");
			if((unsigned long)(*DBObjPtr)(csMerchantId,csCcy,csCountry,csService,hTxn)!=PD_ERR) {
					if(GetField_Double(hTxn,"current_bal",&dTmp)){
						PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("Authorize() current_bal= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"current_bal_settlement",&dTmp)){
						PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("Authorize() current_bal_settlement= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"total_float_settlement",&dTmp)){
						PutField_Double(hContext,"total_float_settlement",dTmp);
DEBUGLOG(("Authorize() total_float_settlement= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"total_reserved_amount",&dTmp)){
						PutField_Double(hContext,"total_reserved_amount",dTmp);
DEBUGLOG(("Authorize() total_reserved_amount= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"total_hold",&dTmp)){
						PutField_Double(hContext,"total_hold",dTmp);
DEBUGLOG(("Authorize() total_hold= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"total_hold_settlement",&dTmp)){
						PutField_Double(hContext,"total_hold_settlement",dTmp);
DEBUGLOG(("Authorize() total_hold_settlement= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"total_float_after_payout",&dTmp)){
						PutField_Double(hContext,"total_float_after_payout",dTmp);
DEBUGLOG(("Authorize() total_float_after_payout= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"fundin_payout",&dTmp)){
						PutField_Double(hContext,"fundin_payout",dTmp);
DEBUGLOG(("Authorize() fundin_payout= [%f]\n",dTmp));
					}
					if(GetField_Double(hTxn,"reserved_payout",&dTmp)){
						PutField_Double(hContext,"reserved_payout",dTmp);
DEBUGLOG(("Authorize() reserved_payout= [%f]\n",dTmp));
					}
			}
		}

	/* Update Ol Txn Detail */
		if (iRet == PD_OK) {
			PutField_CString(hContext, "txn_seq", csTxnSeq);
			PutField_CString(hContext, "update_user", csUser);

DEBUGLOG(("Authorize() call DBOLTransaction::UpdateDetail()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "UpdateDetail");
			if ((unsigned long)(*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction::UpdateDetail() Success\n"));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() DBOLTransaction:UpdateDetail FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() DBOLTransaction::UpdateDetail FAILURE!!!\n");
			}
		}

	/* Update Ol Txn Header */
		if (iRet == PD_OK) {
			PutField_Char(hContext,"status",PD_COMPLETE);
			PutField_Char(hContext,"ar_ind",PD_ACCEPT);
			PutField_Double(hContext,"net_amt",dAmt);
			PutField_CString(hContext,"net_ccy",csCcy);

DEBUGLOG(("Authorize() call DBOLTransaction::Update()\n"));
			DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
			if ((unsigned long)(*DBObjPtr)(hContext) == PD_OK) {
DEBUGLOG(("Authorize() call DBOLTransaction::Update() Success\n"));
			} else {
				iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::Update() FAILURE!!!\n"));
ERRLOG("TxnOmtByUsEBS::Authorize() call DBOLTransaction::Update() FAILURE!!!\n");
			}
		}

		hash_destroy(hTxn);
	}


	FREE_ME(hTxn);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

