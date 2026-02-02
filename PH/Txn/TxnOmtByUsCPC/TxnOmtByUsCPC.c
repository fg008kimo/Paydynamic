/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/10              Virginia Yun
Modify structure				   2015/02/06		   Dirk Wong
Modify Offset Transaction recon status 	           2015/05/05		   Virginia Yun
  to "Not Required"
Modify to add BatchSubType & TxnType for 	   2015/05/13		   Dirk Wong
  OLBatchTxnRelation
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsCPC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);


int	ProcessOffset(const char* csTxnID, char *csOffsetTxnID, hash_t *hContext);
int	GetTxnInfo(const char *csTxnID, hash_t *hContext, hash_t *hTxn);
int	FormOffsetTxn(hash_t *hOrgTxn, hash_t *hOfstTxn, hash_t *hContext);
int	ProcessOffsetTxn(hash_t *hOfstTxn, hash_t *hContext);
int	ProcessOrgTxn(hash_t *hOrgTxn, hash_t *hContext);


void TxnOmtByUsCPC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csBaid = NULL;
	char    *csTxnCountry=strdup("");
	char	*csTxnCcy = NULL;

	char	*csTxnSeq= NULL;

	char	*csTmp = NULL;
	double	dTxnAmt = 0.0;
	double	dTmp = 0.0;
	double	dCheckTmp = 0.0;
	char	cDCInd;

	char	*csDtlTxnID;
	char	csOffsetTxnID[PD_TXN_SEQ_LEN + 1];
	char	csBatchSeq[PD_TXN_SEQ_LEN + 1];
	char	csNewTxnCode[PD_TXN_CODE_LEN + 1];

	char 	*csElementCcy;
	double  dElementAmt = 0.0;
	char	*csAmtType;
	char	cPartyType;
	int	iElementCnt = 0;
	double  dTotalElementAmt = 0.0;

	double	dTotalAcctBal = 0.0;	
	double	dTotalIntransit = 0.0;	
	

	char    csTag[PD_TAG_LEN+1];
	int	i;
	int	iCnt = 0;

	char	cABalAmtType;
	char	cIntrAmtType;


	hash_t	*hTxnRec;
	hTxnRec = (hash_t*) malloc (sizeof(hash_t));
	

	hash_t	*hRec;
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));

	hash_t *hAmountRec;
	hAmountRec = (hash_t *) malloc(sizeof(hash_t));

	memset(csNewTxnCode, 0, sizeof(csNewTxnCode));

DEBUGLOG(("Authorize::TxnOmtByUsCPC: START!!!!!!!!!\n"));

// user
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}

// txn_seq
	if(GetField_CString(hContext, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTxnSeq));
		PutField_CString(hContext,"txn_seq",csTxnSeq);
		PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
	}

// baid
	if(GetField_CString(hRequest,"baid",&csBaid)){
DEBUGLOG(("Authorize::psp_id= [%s]\n",csBaid));
		PutField_CString(hContext,"baid",csBaid);
	}
	else{
DEBUGLOG(("Authorize::psp_id not found!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::psp_id not found!!\n");
		iRet=INT_INVALID_BAID;
		PutField_Int(hContext,"internal_error",iRet);
	}

//psp_id
        if  (GetField_CString(hContext, "baid_psp_id", &csTmp)) {
                PutField_CString(hContext, "psp_id", csTmp);
        }

// status
        if (GetField_CString(hContext, "baid_status", &csTmp)) {
		// if not open, return error
		if (strcmp(csTmp, PD_BAID_STATUS_OPEN)) {
DEBUGLOG(("Authorize::baid status is not open !!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::baid status is not open!!\n");
			iRet=INT_INVALID_BAID;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// bank_code
	if (GetField_CString(hContext, "baid_bank_code", &csTmp)) {
		PutField_CString(hContext, "bank_code", csTmp);
	}

// bank_acct_num
	if (GetField_CString(hContext, "baid_bank_acct_num", &csTmp)) {
		PutField_CString(hContext, "bank_acct_num", csTmp);
	}

// category
	if (GetField_CString(hContext, "baid_category", &csTmp)) {
		//if not IQ, reject
		if (strcmp(csTmp, PD_BAID_CAT_IQ)) {
DEBUGLOG(("Authorize::baid category is not matched!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::baid category is not matched!!\n");
			iRet=INT_INVALID_BAID;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

// country
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hContext,"txn_country",csTxnCountry);
	}
	else{
DEBUGLOG(("Authorize:: Call DBOLBankAcctId: GetBankAcctIdCountry\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBankAcctIdCountry");
                if ((unsigned long)(*DBObjPtr)(csBaid, csTxnCountry) == FOUND) {
DEBUGLOG(("Authorize:: txn_country by baid = [%s]\n", csTxnCountry));
                        PutField_CString(hContext, "txn_country", csTxnCountry);
                        PutField_CString(hRequest, "txn_country", csTxnCountry);
                } else {
DEBUGLOG(("Authorize:: txn_country not found!!\n"));
ERRLOG("TxnOmtByUsCPC:: Authorize:: txn_country not found!!\n");
                        iRet = INT_COUNTRY_PSP_NOT_AVABILE;
                        PutField_Int(hContext, "internal_error", iRet);
                }
	}

// ccy
	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
		PutField_CString(hContext,"net_ccy",csTxnCcy);
		PutField_CString(hContext,"org_txn_ccy",csTxnCcy);
		PutField_CString(hContext,"dst_txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

// txn_amt
	if(GetField_Double(hContext,"txn_amt",&dTxnAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dTxnAmt));
		PutField_Double(hContext, "net_amt", dTxnAmt);
		PutField_Double(hContext, "display_amt", dTxnAmt);
		PutField_Double(hContext, "txn_amount", dTxnAmt);
		PutField_Double(hContext, "org_txn_amt", dTxnAmt);
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

// dc_ind
	if (GetField_CString(hRequest, "dc_ind", &csTmp)) {
		cDCInd = csTmp[0];

		if (cDCInd != PD_IND_DEBIT) {
DEBUGLOG(("Authorize::dc_ind must be DR!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::dc_ind must be DR!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
DEBUGLOG(("Authorize::dc_ind = [%c]\n",cDCInd));
	} else {
DEBUGLOG(("Authorize::dc_ind not found!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::dc_ind not found!!\n");
		iRet=INT_DC_IND_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

/* report_date */
        if(!GetField_CString(hRequest,"report_date",&csTmp)){
DEBUGLOG(("Authorize::report_date not found!!\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::report_date not found!!\n");
                if(GetField_CString(hContext,"PHDATE",&csTmp)){
                        PutField_CString(hContext, "report_date", csTmp);
DEBUGLOG(("Authorize::report_date (PH date) = [%s]\n", csTmp));
                }
        }
        else {
                PutField_CString(hContext, "report_date", csTmp);
DEBUGLOG(("Authorize::report_date = [%s]\n", csTmp));
        }

/* remark */
        if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n", csTmp));
	}


/* total_cnt */
        if (GetField_Int(hContext, "total_cnt", &iCnt)){
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
        } else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnOmtByUsCPC::Authorize::total_cnt not found\n");
                iRet = INT_FORMAT_ERR;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_id  to sum up amount */
	if (iRet == PD_OK) {
		dTotalElementAmt = 0.0;

		for (i = 1; i < iCnt + 1; i++) {

			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_txnid_%d", PD_DETAIL_TAG, i);
			if (GetField_CString(hRequest, csTag, &csDtlTxnID)) {
DEBUGLOG(("Authorize:: [%s] = [%s]\n", csTag, csDtlTxnID));

				iElementCnt = 0;
				recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize:: call DBOLTxnElements:GetAllFeeChgDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetAllFeeChgDetail");
				if ((unsigned long)(*DBObjPtr)(csDtlTxnID,rRecordSet) == PD_OK) {
					hRec = RecordSet_GetFirst(rRecordSet);
					while (hRec && (iRet == PD_OK)) {
						iElementCnt++;

						if (GetField_Char(hRec, "party_type", &cPartyType)) {
DEBUGLOG(("Authorize:: txn_id[%s] Cnt[%d] party_type = [%c]\n", csDtlTxnID, iElementCnt, cPartyType));

							if (cPartyType == PD_TYPE_PSP) {

								if (GetField_CString(hRec, "ccy", &csElementCcy)) {
DEBUGLOG(("Authorize:: txn_id[%s] Cnt[%d] ccy = [%s]\n", csDtlTxnID, iElementCnt, csElementCcy));
									if(strcmp(csTxnCcy, csElementCcy)) {
										continue;
									}
								}	
		
								if (GetField_CString(hRec, "amt_type", &csAmtType)) {
DEBUGLOG(("Authorize:: txn_id[%s] Cnt[%d] amt_type = [%s]\n", csDtlTxnID, iElementCnt, csAmtType));
								} else {
									continue;
								}
	
								if (GetField_Double(hRec, "amount", &dElementAmt)) {
DEBUGLOG(("Authorize:: txn_id[%s] Cnt[%d] amt_type = [%f]\n", csDtlTxnID, iElementCnt, dElementAmt));
									if (!strcmp(csAmtType, PD_CR)) {
										dTotalElementAmt = dTotalElementAmt + dElementAmt;
									} else if (!strcmp(csAmtType, PD_DR)) {
										dTotalElementAmt = dTotalElementAmt - dElementAmt;
									}
								}
							}
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
				}
			}
			RecordSet_Destroy(rRecordSet);
		}
DEBUGLOG(("Authorize:: total Expected Amt [%f]\n", dTotalElementAmt));


		if (dTotalElementAmt < 0.0) {
			dTotalElementAmt = dTotalElementAmt * (-1.0);
		}

		dTotalElementAmt = newround(dTotalElementAmt, PD_DECIMAL_LEN);
		dCheckTmp = newround(dTxnAmt, PD_DECIMAL_LEN);

/*
		if (cDCInd == PD_IND_CREDIT) {
			dTmp = dTxnAmt;
			strcpy(csNewTxnCode, PD_OFFLINE_RTN_PROV_CHARGE);

		} else if (cDCInd == PD_IND_DEBIT) {
			dTmp = (-1.0) * dTxnAmt;
			strcpy(csNewTxnCode, PD_OFFLINE_PROV_CHARGE);
		} else {
DEBUGLOG(("Authorize:: Unexpected dc_ind\n"));
ERRLOG(("TxnOmtByUsCPC::Authorize:: Unexpected dc_ind\n"));
			iRet = INT_INVALID_TXN;
                	PutField_Int(hContext,"internal_error",iRet);
		}
*/
		strcpy(csNewTxnCode, PD_OFL_PROV_CHARGE_OUTSTANDING);

DEBUGLOG(("Authorize:: pass in Amt [%f]\n", dTmp));

		if (dCheckTmp!= dTotalElementAmt) {
DEBUGLOG(("Authorize:: Unexpected amount\n"));
ERRLOG(("TxnOmtByUsCPC::Authorize:: Unexpected amount\n"));
			iRet = INT_INVALID_TXN;
                	PutField_Int(hContext,"internal_error",iRet);
		} else {
DEBUGLOG(("Authorize:: Amount Match!!!!\n"));
		}
	}


// handle Offset passin txn_id 
 	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextActionBatchSeq");
		strcpy(csBatchSeq, (*DBObjPtr)());
		PutField_CString(hContext, "batch_txn_seq", csBatchSeq);
	}


	if (iRet == PD_OK) {
		for (i = 1; i < iCnt + 1; i++) {
			memset(csTag, 0, sizeof(csTag));
			sprintf(csTag, "%s_txnid_%d", PD_DETAIL_TAG, i);

			if (GetField_CString(hRequest, csTag, &csDtlTxnID)) {

// START TO PROCESS TXN

				iRet = ProcessOffset(csDtlTxnID, csOffsetTxnID, hContext);

				if (GetField_Double(hContext, "element_acct_bal", &dTmp)) {
					dTotalAcctBal += dTmp;
				}

				if (GetField_Double(hContext, "element_intransit", &dTmp)) {
					dTotalIntransit += dTmp;
				}

				RemoveField_Double(hContext, "element_acct_bal");
				RemoveField_Double(hContext, "element_intransit");
			}
		}

                if (iRet == PD_OK) {
			hash_t *hRelation;
			hRelation = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hRelation, 0);

                        PutField_Char(hRelation, "batch_type", PD_COMBINE);
                        PutField_Char(hRelation, "batch_sub_type", PD_COMBINE_RECON);
			PutField_Int(hRelation, "is_input_txn", 0);
                        PutField_CString(hRelation, "batch_id", csBatchSeq);
                        PutField_Char(hRelation, "txn_level", PD_TXN_LEVEL);
                        PutField_CString(hRelation, "txn_id", csTxnSeq);
			PutField_CString(hRelation, "create_user", csUser);

                        DBObjPtr = CreateObj(DBPtr, "DBOLBatchTxnRelation", "Add");
                        if ((unsigned long)(*DBObjPtr)(hRelation) != PD_OK) {
                                iRet = INT_ERR;
                        }
                }
	}




// Update the Combine Txn Balance + Update Log


// Get Exchange Rate
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize:: Call BOExchange: GetExchangeInfo\n"));
		BOObjPtr = CreateObj(BOPtr, "BOExchange", "GetExchangeInfo");
		iRet = (unsigned long)(*BOObjPtr)(hContext, hRequest);
		if (iRet != PD_OK) {
DEBUGLOG(("Authorize:: Call: BOExchange.GetExchangeInfo failed, return = [%d]\n", iRet));
ERRLOG("TxnOmtByUsCPC:: Authorize:: Call: BOExchange.GetExhcnageInfo failed, return = [%d]\n", iRet);
		}
	}

// Update Balance 
	int iGetOpenBal = PD_FALSE;

	// Reversal Offset
	if (dTotalAcctBal > 0.0) {
		cABalAmtType = PD_IND_DEBIT;
	} else if (dTotalAcctBal < 0.0) {
		dTotalAcctBal = dTotalAcctBal * (-1.0);
		cABalAmtType = PD_IND_CREDIT;
	}

	if (iRet == PD_OK && dTotalAcctBal > 0.0) {
		hash_init(hAmountRec, 0);
		
		PutField_CString(hAmountRec, "baid", csBaid);
		PutField_CString(hAmountRec, "txn_country", csTxnCountry);
		PutField_CString(hAmountRec, "txn_ccy", csTxnCcy);
		PutField_Char(hAmountRec, "amt_type", cABalAmtType);
		PutField_Double(hAmountRec, "txn_amt", dTotalAcctBal);
		PutField_CString(hAmountRec, "pool", PD_ACCT_BAL_POOL); 

DEBUGLOG(("Authorize::Call BOOLBalance:UpdateAmount (Acct Bal)\n"));
		BOObjPtr = CreateObj(BOPtr,"BOOLBalance","UpdateAmount");
		iRet = (unsigned long)(*BOObjPtr)(hAmountRec);
		if (iRet == PD_OK) {
			iGetOpenBal = PD_TRUE;

                        if (GetField_Double(hAmountRec, "open_bal", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:open_bal [%f]\n", dTmp));
				PutField_Double(hContext, "open_bal", dTmp);
                        }

                        if (GetField_Double(hAmountRec, "open_in_transit", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:open_in_transit [%f]\n", dTmp));
				PutField_Double(hContext, "open_in_transit", dTmp);
                        }

                        if (GetField_CString(hAmountRec, "approval_date", &csTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:approval_date [%s]\n", csTmp));
				PutField_CString(hContext, "approval_date", csTmp);
                        }

                        if (GetField_CString(hAmountRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("Authorize::Call BOOLBalance:approval_timestamp [%s]\n", csTmp));
				PutField_CString(hContext, "approval_timestamp", csTmp);
                        }

                        if (GetField_Double(hAmountRec, "bal", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:balance = [%f]\n", dTmp));
				PutField_Double(hContext, "bal", dTmp);
                        }

                        if (GetField_Double(hAmountRec, "total_hold", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:total_hold = [%f]\n", dTmp));
				PutField_Double(hContext, "total_hold", dTmp);
                        }

                        if (GetField_Double(hAmountRec, "prepaid", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:prepaid = [%f]\n", dTmp));
				PutField_Double(hContext, "prepaid", dTmp);
                        }

                        if (GetField_Double(hAmountRec, "in_transit", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:in_transit = [%f]\n", dTmp));
				PutField_Double(hContext, "in_transit", dTmp);
                        }
		
		}
		hash_destroy(hAmountRec);	
	}

	if (iRet == PD_OK) {
	        if (dTotalIntransit > 0.0) {
			cIntrAmtType= PD_IND_DEBIT;
	        } else if (dTotalIntransit < 0.0) {
			dTotalIntransit = dTotalIntransit * (-1.0);
      			cIntrAmtType= PD_IND_CREDIT;
		}

		if (iRet == PD_OK && dTotalIntransit > 0.0) {
			hash_init(hAmountRec, 0);

			PutField_CString(hAmountRec, "baid", csBaid);
			PutField_CString(hAmountRec, "txn_country", csTxnCountry);
			PutField_CString(hAmountRec, "txn_ccy", csTxnCcy);
			PutField_Char(hAmountRec, "amt_type", cIntrAmtType);
			PutField_Double(hAmountRec, "txn_amt", dTotalIntransit);
			PutField_CString(hAmountRec, "pool", PD_INTRANSIT_POOL);

DEBUGLOG(("Authorize::Call BOOLBalance:UpdateAmount (Acct Bal)\n"));
			BOObjPtr = CreateObj(BOPtr,"BOOLBalance","UpdateAmount");
			iRet = (unsigned long)(*BOObjPtr)(hAmountRec);
			if (iRet == PD_OK) {
				if (iGetOpenBal == PD_FALSE) {
					if (GetField_Double(hAmountRec, "open_bal", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:open_bal [%f]\n", dTmp));
                                		PutField_Double(hContext, "open_bal", dTmp);
                        		}

                        		if (GetField_Double(hAmountRec, "open_in_transit", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:open_in_transit [%f]\n", dTmp));
						PutField_Double(hContext, "open_in_transit", dTmp);
                        		}

		                        if (GetField_CString(hAmountRec, "approval_date", &csTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:approval_date [%s]\n", csTmp));
						PutField_CString(hContext, "approval_date", csTmp);
					}

					if (GetField_CString(hAmountRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("Authorize::Call BOOLBalance:approval_timestamp [%s]\n", csTmp));
						PutField_CString(hContext, "approval_timestamp", csTmp);
                        		}
				}

				if (GetField_Double(hAmountRec, "bal", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:balance = [%f]\n", dTmp));
					PutField_Double(hContext, "bal", dTmp);
                        	}

				if (GetField_Double(hContext, "total_hold", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:total_hold = [%f]\n", dTmp));
					PutField_Double(hContext, "total_hold", dTmp);
                        	}

				if (GetField_Double(hContext, "prepaid", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:prepaid = [%f]\n", dTmp));
					PutField_Double(hContext, "prepaid", dTmp);
                        	}

				if (GetField_Double(hContext, "in_transit", &dTmp)) {
DEBUGLOG(("Authorize::Call BOOLBalance:in_transit = [%f]\n", dTmp));
					PutField_Double(hContext, "in_transit", dTmp);
                        	}
			}
	
                	hash_destroy(hAmountRec);
                }
	}

	if(iRet==PD_OK){

		DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","Add");
		if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
			iRet = INT_ERR;

		if(iRet==PD_OK){
			if(GetField_CString(hContext,"PHDATE",&csTmp)){
				PutField_CString(hContext,"txn_date",csTmp);
			}
DEBUGLOG(("Authorize::Call DBTxnPspDetail:Update\n"));
			DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","Update");
			if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK) {
				iRet = INT_ERR;
			}
		}
	}

	if (iRet == PD_OK) {
		hash_init(hAmountRec, 0);
		// TxnElements
		PutField_CString(hAmountRec, "txn_seq", csTxnSeq);
		PutField_CString(hAmountRec, "txn_ccy", csTxnCcy);
		PutField_Char(hAmountRec, "party_type", PD_TYPE_PSP);

		if (dTotalAcctBal > 0.0) {
			PutField_Double(hAmountRec, "txn_amt", dTotalAcctBal);
			PutField_CString(hAmountRec, "txn_element_type", PD_ELEMENT_TXN_AMT);

			if (cABalAmtType == PD_IND_CREDIT) {
				PutField_CString(hAmountRec, "amount_type", PD_CR);
			} else if (cABalAmtType == PD_IND_DEBIT) {
				PutField_CString(hAmountRec, "amount_type", PD_DR);
			}

DEBUGLOG(("Authorize::Call BOOLTxnElements:AddTxnAmtElement (AcctBal)\n"));
                	BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddPspTxnElement");
			if ((unsigned long)((*BOObjPtr)(hAmountRec)) != PD_OK) {
                        	iRet = INT_ERR;
                	}
		}

		if (iRet == PD_OK && dTotalIntransit > 0.0) {
			PutField_Double(hAmountRec, "txn_amt", dTotalIntransit);
			PutField_CString(hContext, "txn_element_type", PD_ELEMENT_IN_TRANSIT);

			if (cIntrAmtType== PD_IND_CREDIT) {
				PutField_CString(hAmountRec, "amount_type", PD_CR);
			} else if (cIntrAmtType== PD_IND_DEBIT) {
				PutField_CString(hAmountRec, "amount_type", PD_DR);
			}

DEBUGLOG(("Authorize::Call BOOLTxnElements:AddTxnAmtElement (Intransit)\n"));
                	BOObjPtr = CreateObj(BOPtr,"BOOLTxnElements","AddPspTxnElement");
			if ((unsigned long)((*BOObjPtr)(hAmountRec)) != PD_OK) {
                        	iRet = INT_ERR;
			}
		}
		hash_destroy(hAmountRec);
        }


	if (iRet == PD_OK) {
		PutField_CString(hContext, "new_txn_code", csNewTxnCode);

		PutField_CString(hContext, "sub_status", PD_APPROVED);
		PutField_Char(hContext, "recon_status", PD_UNRECONCILED);
		
	}

	FREE_ME(rRecordSet);
	FREE_ME(hAmountRec);

	FREE_ME(csTxnCountry);
DEBUGLOG(("TxnOmtByUsCPC Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}

int	ProcessOffset(const char* csTxnID, char *csOffsetTxnID, hash_t* hContext)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;


	hash_t	*hOrgTxn;
	hOrgTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOrgTxn, 0);


	hash_t	*hOfstTxn;
	hOfstTxn = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hOfstTxn, 0);

DEBUGLOG(("===== ProcessOffset ===== START!!\n"));	

	// Lock Org Txn + Get Org Txn
	iRet = GetTxnInfo(csTxnID, hContext, hOrgTxn);

	// Check Txn code 
	if (iRet == PD_OK) {
		if (GetField_CString(hOrgTxn, "txn_code", &csTmp)) {
			if (!strcmp(csTmp, PD_OFFLINE_PROV_CHARGE) ||
			    !strcmp(csTmp, PD_OFFLINE_RTN_PROV_CHARGE) ||
			    !strcmp(csTmp, PD_OFL_PROV_CHARGE_OUTSTANDING)) {
			} else {
DEBUGLOG(("ProcessOffset:: Txn_Code not expected [%s]\n", csTmp));
ERRLOG("TxnOmtByUsCPC::ProcessOFfset:: TxnCode not expected [%s]\n", csTmp);

				iRet = INT_INVALID_TXN;
			}
		}
	}

	// Form Offset Txn (include reversal CR / DR sign)
	if (iRet == PD_OK) {
		iRet = FormOffsetTxn(hOrgTxn, hOfstTxn, hContext);
	}


	// Create Txn + Update Balance (with add approval_date, approval_timestamp)
	if (iRet == PD_OK) {
		iRet = ProcessOffsetTxn(hOfstTxn, hContext);
	}

	// Update Org Txn to (void)
	if (iRet == PD_OK) {
		iRet = ProcessOrgTxn(hOrgTxn, hContext);
	}

DEBUGLOG(("===== ProcessOffset ===== END !!\n"));	

	hash_destroy(hOrgTxn);
	hash_destroy(hOfstTxn);

	FREE_ME(hOrgTxn);
	FREE_ME(hOfstTxn);

	return iRet;
}

int	GetTxnInfo(const char *csTxnSeq, hash_t *hContext, hash_t *hTxn)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	double	dTmp = 0.0;
	char	cTmp;
	int	iTmp = 0;
	char	*csBaid;

	int	iTotalElement = 0;

	hash_t	*hRec;

	char    csTag[PD_TAG_LEN+1];
	char	csBaidCountry[PD_COUNTRY_LEN + 1];

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

        hash_t  *hTxnPspDetail;
        hTxnPspDetail = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxnPspDetail, 0);

        hash_t  *hBaidDetail;
        hBaidDetail = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBaidDetail, 0);

DEBUGLOG(("GetTxnInfo:: Call DBOLTransaction:GetTxnIdForUpdate [%s]\n", csTxnSeq));
	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnIdForUpdate");
	if ((unsigned long)(*DBObjPtr)(csTxnSeq) != PD_OK) {
		iRet = INT_INVALID_TXN;
	}

	PutField_CString(hTxn, "txn_seq", csTxnSeq);

	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

// Header
DEBUGLOG(("GetTxnInfo:: Call DBOLTransaction:GetTxnHeader [%s]\n", csTxnSeq));
		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "GetTxnHeader");
		if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if (GetField_CString(hRec, "txn_code", &csTmp)) {
					PutField_CString(hTxn, "txn_code", csTmp);
DEBUGLOG(("GetTxnInfo (Header):: txn_code = [%s]\n", csTmp));
				}
				if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: status = [%c]\n", cTmp));
					if (cTmp != PD_COMPLETE) {
ERRLOG("TxnOmtByUsCPC::GetTxnInfo (Header):: status = [%c]\n", cTmp);
						iRet = INT_INVALID_TXN;
						break;
					} 
				}

				if (GetField_Char(hRec, "ar_ind", &cTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: ar_ind = [%c]\n", cTmp));
					if (cTmp != PD_ACCEPT) {
ERRLOG("TxnOmtByUsCPC::GetTxnInfo (Header):: ar_ind = [%c]\n", cTmp);
						iRet = INT_INVALID_TXN;
						break;
					}
				}

				if (GetField_CString(hRec, "sub_status", &csTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: sub_status = [%s]\n", csTmp));
					if (strcmp(csTmp, PD_APPROVED)) {
ERRLOG("TxnOmtByUsCPC::GetTxnInfo (Header):: sub_status = [%s]\n", csTmp);
						iRet = INT_INVALID_TXN;
						break;
					}
				}
					
				if (GetField_Char(hRec, "recon_status", &cTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: recon_status = [%c]\n", cTmp));
					if (cTmp != PD_UNRECONCILED) {
ERRLOG("TxnOmtByUsCPC::GetTxnInfo (Header):: recon_status = [%s]\n", cTmp);
						iRet = INT_INVALID_TXN;
						break;
					}
				}

DEBUGLOG(("GetTxnInfo (Header):: Get TxnAmt Information\n"));

				if (GetField_Double(hRec, "txn_amt", &dTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: txn_amt = [%lf]\n", dTmp));
					PutField_Double(hTxn, "txn_amt", dTmp);
				}

				if (GetField_Double(hRec, "net_amt", &dTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: net_amt = [%lf]\n", dTmp));
					PutField_Double(hTxn, "net_amt", dTmp);
				}

				if (GetField_CString(hRec, "net_ccy", &csTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: net_ccy = [%lf]\n",csTmp));
					PutField_CString(hTxn,"net_ccy",csTmp);
				}

				if (GetField_Double(hRec, "deposit_amt", &dTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: deposit_amt = [%lf]\n",dTmp));
					PutField_Double(hTxn,"deposit_amt",dTmp);
				}

				if (GetField_Double(hRec, "display_amt", &dTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: display_amt= [%lf]\n",dTmp));
					PutField_Double(hTxn,"display_amt",dTmp);
				}

				if (GetField_Char(hRec, "ex_supplier", &cTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: ex_supplier = [%c]\n", cTmp));
					PutField_Char(hTxn,"ex_supplier",cTmp);
				}

				if (GetField_Double(hRec, "ex_rate", &dTmp)) {
DEBUGLOG(("GetTxnInfo (Header):: ex_rate = [%lf]\n", dTmp));
					PutField_Double(hTxn,"ex_rate",dTmp);
				}
                        	hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
DEBUGLOG(("GetTxnInfo (Header):: not found record for [%s]\n",csTxnSeq));
			iRet = INT_INVALID_TXN;
		}

		RecordSet_Destroy(rRecordSet);
	}


// TxnPspDetail
	if (iRet == PD_OK) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail)::Call OLTxnPspDetail:GetTxnPspDetail\n"));
		DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","GetTxnPspDetail");
		if ((*DBObjPtr)(csTxnSeq,hTxnPspDetail) == PD_OK) {
			if (GetField_CString(hTxnPspDetail, "psp_id", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: psp_id = [%s]\n", csTmp));
				PutField_CString(hTxn, "psp_id", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "baid", &csBaid)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: baid = [%s]\n", csBaid));

				PutField_CString(hTxn, "baid", csBaid);

				// check status	
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: Call DBOLBankAcctId: GetBankAcctIdDtl\n"));
				DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetBankAcctIdDtl");
				iRet = (unsigned long)(*DBObjPtr)(csBaid, hBaidDetail);
				if (iRet == PD_OK) {	
					if (!GetField_CString(hBaidDetail, "status", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: baid [%s] status not found!\n"));

						iRet = INT_INVALID_TXN;
					} else {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: baid [%s] status [%s]\n", csBaid, csTmp));
						if (strcmp(csTmp, PD_BAID_STATUS_OPEN)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: baid status is not open !!\n"));
							iRet=INT_INVALID_BAID;
                				}
					}
				}

			// check baid country !!
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: Call DBOLBAnkAcctId: GetBankAcctIdCountry\n"));
				DBObjPtr = CreateObj(DBPtr, "DBOLBankAcctId", "GetBankAcctIdCountry");
				if ((unsigned long)(*DBObjPtr)(csBaid, csBaidCountry) == FOUND) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: baid country = [%s]\n", csBaidCountry));

				} else {
					iRet = INT_INVALID_TXN;
				}
			}

			if (iRet == PD_OK) {
				GetField_CString(hContext, "txn_country", &csTmp);
				if (strcmp(csTmp, csBaidCountry)) {
DEBUGLOG(("Authorize:: country not the same !!\n"));
ERRLOG("Authorize:: TxnOmtByUsCPC:: Authorize:: country not the same found!!\n");
					iRet = INT_INVALID_TXN;
				}
			}

			if (GetField_CString(hTxnPspDetail, "txn_ccy", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: txn_ccy = [%s]\n", csTmp));
				PutField_CString(hTxn, "txn_ccy", csTmp);
			}

			if (GetField_Double(hTxnPspDetail, "txn_amount", &dTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: txn_amount = [%f]\n", dTmp));
				PutField_Double(hTxn, "txn_amount", dTmp);
			}

			if (GetField_CString(hTxnPspDetail, "bank_code", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: bank_code = [%s]\n", csTmp));
				PutField_CString(hTxn, "bank_code", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "bank_acct_num", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: bank_acct_num = [%s]\n", csTmp));
				PutField_CString(hTxn, "bank_acct_num", csTmp);
			}

			if (GetField_Double(hTxnPspDetail, "cost", &dTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: cost = [%lf]\n", dTmp));
				PutField_Double(hTxn, "cost", dTmp);
			}

			if (GetField_Int(hTxnPspDetail, "txn_hold_ind", &iTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: txn_hold_ind = [%d]\n", iTmp));
				PutField_Int(hTxn, "txn_hold_ind", iTmp);
			}

			if (GetField_Int(hTxnPspDetail, "sys_match_ind", &iTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: sys_match_ind = [%d]\n", iTmp));
				PutField_Int(hTxn, "sys_match_ind", iTmp);
			}

			if (GetField_CString(hTxnPspDetail, "customer_text", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: customer_text = [%s]\n", csTmp));
				PutField_CString(hTxn, "customer_text", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "sender_name", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: sender_name = [%s]\n", csTmp));
				PutField_CString(hTxn, "sender_name", csTmp);
			}

			if (GetField_CString(hTxnPspDetail, "txn_ref_num", &csTmp)) {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: txn_ref_num = [%s]\n", csTmp));
				PutField_CString(hTxn, "txn_ref_num", csTmp);
			}
		}
		else {
DEBUGLOG(("GetTxnInfo (TxnPspDetail):: not found record for [%s]\n",csTxnSeq));
			iRet = INT_INVALID_TXN;
		}
	}

	if (iRet == PD_OK) {
// Elements
DEBUGLOG(("GetTxnInfo (TxnElements:: call DBOLTxnElements:GetAllFeeChgDetail\n"));

		DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","GetAllFeeChgDetail");
		if ((unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {

			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && (iRet == PD_OK)) {
				iTotalElement++;

				if (GetField_CString(hRec, "txn_element_type", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] element_type = [%s]\n", csTxnSeq, iTotalElement, csTmp));
					sprintf(csTag, "element_type_%d", iTotalElement);
					PutField_CString(hTxn, csTag, csTmp);
				}

				if (GetField_Double(hRec, "amount", &dTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] amt_type = [%f]\n", csTxnSeq, iTotalElement, dTmp));
					sprintf(csTag, "element_amount_%d", iTotalElement);
					PutField_Double(hTxn, csTag, dTmp);
				}
			
				if (GetField_CString(hRec, "ccy", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] ccy = [%s]\n", csTxnSeq, iTotalElement, csTmp));
					sprintf(csTag, "element_ccy_%d", iTotalElement);
					PutField_CString(hTxn, csTag, csTmp);
				}
				
				if (GetField_CString(hRec, "amt_type", &csTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] amt_type = [%s]\n", csTxnSeq, iTotalElement, csTmp));
					sprintf(csTag, "element_amt_type_%d", iTotalElement);
					PutField_CString(hTxn, csTag, csTmp);
				}

				if (GetField_Char(hRec, "party_type", &cTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] party_type = [%c]\n", csTxnSeq, iTotalElement, cTmp));
					sprintf(csTag, "element_party_type_%d", iTotalElement);
					PutField_Char(hTxn, csTag, cTmp);
				}

				if (GetField_Double(hRec, "rate", &dTmp)) {
DEBUGLOG(("GetTxnInfo:: txn_id[%s] Cnt[%d] rate = [%f]\n", csTxnSeq, iTotalElement, dTmp));
					sprintf(csTag, "element_rate_%d", iTotalElement);
					PutField_Double(hTxn, csTag, dTmp);
				}

				hRec = RecordSet_GetNext(rRecordSet);
                        }

			sprintf(csTag, "element_total_cnt");
			PutField_Int(hTxn, csTag, iTotalElement);

DEBUGLOG(("Authorize:: total Expected Element [%d]\n", iTotalElement));
                        RecordSet_Destroy(rRecordSet);
                }
	}


	hash_destroy(hTxnPspDetail);
	FREE_ME(hTxnPspDetail);

	hash_destroy(hBaidDetail);
	FREE_ME(hBaidDetail);

	FREE_ME(rRecordSet);

	return iRet;
}

int	FormOffsetTxn(hash_t *hOrgTxn, hash_t *hOfstTxn, hash_t *hContext)
{
	int	iRet = PD_OK;

	char 	csOfstTxnSeq[PD_TXN_SEQ_LEN +1];
	char    csTxnDateTime[PD_DATETIME_LEN + 1];
	char    csTag[PD_TAG_LEN+1];

	char	*csTmp = NULL;
	double	dTmp = 0.0;
	char	cTmp;
	int	iTmp = 0;
	int	iElementCnt = 0;

	DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
	strcpy(csOfstTxnSeq, (*DBObjPtr)());

// txn_id
	PutField_CString(hOfstTxn, "txn_seq", csOfstTxnSeq);
DEBUGLOG(("FormOffsetTxn::Offset TxnSeq (Generated!!) [%s]\n", csOfstTxnSeq));

// org_txn_id
	if (GetField_CString(hOrgTxn, "txn_seq", &csTmp)) {
DEBUGLOG(("FormOffsetTxn::org_txn_seq [%s]\n", csTmp));
		PutField_CString(hOfstTxn, "org_txn_seq", csTmp);
	}
// channel
	if (GetField_CString(hContext, "channel_code", &csTmp)) {
		PutField_CString(hOfstTxn, "channel_code", csTmp);
	}	

// status
	 PutField_Char(hOfstTxn,"status",PD_PROCESSING);

// txn_code
	if (GetField_CString(hOrgTxn, "txn_code", &csTmp)) {
		if (!strcmp(csTmp, PD_OFFLINE_PROV_CHARGE)) {
			PutField_CString(hOfstTxn, "txn_code", PD_OFFLINE_PROV_CHARGE_OFST);
DEBUGLOG(("FormOffsetTxn::Offset TxnCode [%s]\n", PD_OFFLINE_PROV_CHARGE_OFST));
			PutField_Char(hOfstTxn, "amt_type", PD_IND_CREDIT);
		} else if (!strcmp(csTmp, PD_OFFLINE_RTN_PROV_CHARGE)) {
				PutField_CString(hOfstTxn, "txn_code", PD_OFFLINE_RTN_PROV_CHARGE_OFST);
DEBUGLOG(("FormOffsetTxn::Offset TxnCode [%s]\n", PD_OFFLINE_RTN_PROV_CHARGE_OFST));
				PutField_Char(hOfstTxn, "amt_type", PD_IND_DEBIT);
		} else if (!strcmp(csTmp, PD_OFL_PROV_CHARGE_OUTSTANDING)) {
				PutField_CString(hOfstTxn, "txn_code", PD_OFL_PROV_CHARGE_OUTSTANDING_OFST);
DEBUGLOG(("FormOffsetTxn::Offset TxnCode [%s]\n", PD_OFL_PROV_CHARGE_OUTSTANDING_OFST));
				PutField_Char(hOfstTxn, "amt_type", PD_IND_CREDIT);
		} else {
DEBUGLOG(("FormOffsetTxn::Offset TxnCode UNKNOWN!\n"));
		}
	}

// process_type, process_code
	PutField_CString(hOfstTxn,"process_code", PD_PROCESS_CODE_DEF);
	PutField_CString(hOfstTxn,"process_type", PD_PROCESS_TYPE_DEF);

// host_posting_date
	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
		PutField_CString(hOfstTxn, "host_posting_date", csTmp);
	}
// transmission_datetime
	if (GetField_CString(hContext, "local_tm_date", &csTmp)) {
		PutField_CString(hOfstTxn, "local_tm_date", csTmp);
		PutField_CString(hOfstTxn, "tm_date", csTmp);

                strcpy(csTxnDateTime, csTmp);
                PutField_CString(hOfstTxn, "transmission_datetime", csTxnDateTime);

                if (GetField_CString(hContext, "local_tm_time", &csTmp)) {
                        PutField_CString(hOfstTxn, "local_tm_time", csTmp);
                        strcat(csTxnDateTime, csTmp);
                        PutField_CString(hOfstTxn, "transmission_datetime", csTxnDateTime);
                }
        }

// transaction_amount
	if  (GetField_Double(hOrgTxn, "txn_amt", &dTmp)) {
		PutField_Double(hOfstTxn, "txn_amt", dTmp);
	}

// net_amt
	if (GetField_Double(hOrgTxn, "net_amt", &dTmp)) {
		PutField_Double(hOfstTxn,"net_amt",dTmp);
	}

// net_ccy
	if (GetField_CString(hOrgTxn, "net_ccy", &csTmp)) {
		PutField_CString(hOfstTxn,"net_ccy",csTmp);
	}

// deposit_amt
        if (GetField_Double(hOrgTxn, "deposit_amt", &dTmp)) {
                PutField_Double(hOfstTxn,"deposit_amt",dTmp);
        }

// display_amt
        if (GetField_Double(hOrgTxn, "display_amt", &dTmp)) {
                PutField_Double(hOfstTxn,"display_amt",dTmp);
        }

// ex_supplier
	if (GetField_Char(hOrgTxn, "ex_supplier", &cTmp)) {
		PutField_Char(hOfstTxn,"ex_supplier",cTmp);
	}

// ex_rate
	if (GetField_Double(hOrgTxn, "ex_rate", &dTmp)) {
		PutField_Double(hOfstTxn,"ex_rate",dTmp);
	}

	PutField_CString(hOfstTxn, "response_code", "0");
	PutField_Int(hOfstTxn, "internal_code", 0);


// *** TxnPspDetail ***
// psp_id
	if (GetField_CString(hOrgTxn, "psp_id", &csTmp)) {
		PutField_CString(hOfstTxn, "psp_id", csTmp);
        }

// baid
        if (GetField_CString(hOrgTxn, "baid", &csTmp)) {
                PutField_CString(hOfstTxn, "baid", csTmp);
        }

//txn_date
	if (GetField_CString(hContext, "PHDATE", &csTmp)) {
		PutField_CString(hOfstTxn, "txn_date", csTmp);
	}

// txn_ccy
        if (GetField_CString(hOrgTxn, "txn_ccy", &csTmp)) {
                PutField_CString(hOfstTxn, "txn_ccy", csTmp);
        }

// txn_amount
        if (GetField_Double(hOrgTxn, "txn_amount", &dTmp)) {
                PutField_Double(hOfstTxn, "txn_amount", dTmp);
        }

// bank_code
        if (GetField_CString(hOrgTxn, "bank_code", &csTmp)) {
                PutField_CString(hOfstTxn, "bank_code", csTmp);
        }

// back_acct_num
        if (GetField_CString(hOrgTxn, "bank_acct_num", &csTmp)) {
                PutField_CString(hOfstTxn, "bank_acct_num", csTmp);
        }

// cost
        if (GetField_Double(hOrgTxn, "cost", &dTmp)) {
                PutField_Double(hOfstTxn, "cost", dTmp);
        }

// txn_hold_ind
        if (GetField_Int(hOrgTxn, "txn_hold_ind", &iTmp)) {
                PutField_Int(hOfstTxn, "txn_hold_int", iTmp);
        }

// sys_match_ind
        if (GetField_Int(hOrgTxn, "sys_match_ind", &iTmp)) {
                PutField_Int(hOfstTxn, "sys_match_ind", iTmp);
        }

//customer_text 
        if (GetField_CString(hOrgTxn, "customer_text", &csTmp)) {
                PutField_CString(hOfstTxn, "customer_text", csTmp);
	}

//sender_name
        if (GetField_CString(hOrgTxn, "sender_name", &csTmp)) {
                PutField_CString(hOfstTxn, "sender_name", csTmp);
	}

//txn_ref_num
        if (GetField_CString(hOrgTxn, "txn_ref_num", &csTmp)) {
                PutField_CString(hOfstTxn, "txn_ref_num", csTmp);
	}

// *** TxnElements ***

	char	cPartyType; 	
	char	*csOrgCcy = NULL;
	char	*csOrgElementCcy = NULL;
	char	*csOrgElementType = NULL;
	char	*csOrgElementAmtType = NULL;
	double  dOrgElementAmount = 0.0;

	char	cTmpDCInd;
	int	i;

	double	dTotalAcctBal = 0.0;
	double	dTotalIntransitBal = 0.0;
	
	GetField_CString(hOrgTxn, "txn_ccy", &csOrgCcy);


	if (GetField_Int(hOrgTxn, "element_total_cnt", &iElementCnt)) {
		PutField_Int(hOfstTxn, "element_total_cnt", iElementCnt);

DEBUGLOG(("FormOffsetTxn::total element [%d]\n", iElementCnt));

		for (i = 1; i < iElementCnt + 1; i++) {
DEBUGLOG(("FormOffsetTxn:: Element!!\n"));
		// convert DR / CR
		// Count diff_pool PD_ACCT_BAL_POOL / INTRANSIT_POOL

			sprintf(csTag, "element_party_type_%d", i);
			if (GetField_Char(hOrgTxn, csTag, &cPartyType)) {

DEBUGLOG(("FormOffsetTxn: [%d] party_type [%c]\n", i, cPartyType));
				PutField_Char(hOfstTxn, csTag, cPartyType);
			}

			sprintf(csTag, "element_ccy_%d", i);
			if (GetField_CString(hOrgTxn, csTag, &csOrgElementCcy)) {
				PutField_CString(hOfstTxn, csTag, csOrgElementCcy);
DEBUGLOG(("FormOffsetTxn: [%d] ccy [%s]\n", i, csOrgElementCcy));
			}
			
			sprintf(csTag, "element_amt_type_%d", i);
			if (GetField_CString(hOrgTxn, csTag, &csOrgElementAmtType)) {
				PutField_CString(hOfstTxn, csTag, csOrgElementAmtType);

				// Convert DR or CR
				if (!strcmp(csOrgElementAmtType, PD_CR)) {
					PutField_CString(hOfstTxn, csTag, PD_DR);

					cTmpDCInd = PD_IND_DEBIT;

				} else if (!strcmp(csOrgElementAmtType, PD_DR)) {
					PutField_CString(hOfstTxn, csTag, PD_CR);
					cTmpDCInd = PD_IND_CREDIT;
				}
DEBUGLOG(("FormOffsetTxn: [%d] DR / CR [%c]\n", i, cTmpDCInd));
			}

			sprintf(csTag, "element_amount_%d", i);
			if (GetField_Double(hOrgTxn, csTag, &dOrgElementAmount)) {
				PutField_Double(hOfstTxn, csTag, dOrgElementAmount);
			}

			sprintf(csTag, "element_type_%d", i);
			if (GetField_CString(hOrgTxn, csTag, &csOrgElementType)) {
				PutField_CString(hOfstTxn, csTag, csOrgElementType);


				if (!strcmp(csOrgElementCcy, csOrgCcy) &&
					(cPartyType == PD_TYPE_PSP) ) {

					if (!strcmp(csOrgElementType, PD_ELEMENT_TXN_AMT) ||
					    !strcmp(csOrgElementType, PD_ELEMENT_TXN_FEE)) {
						if (cTmpDCInd == PD_IND_DEBIT) {
							dTotalAcctBal = dTotalAcctBal - dOrgElementAmount;
						} else if (cTmpDCInd == PD_IND_CREDIT) {
							dTotalAcctBal = dTotalAcctBal + dOrgElementAmount;
						}
					}
					else {
						if (cTmpDCInd == PD_IND_DEBIT) {
							dTotalIntransitBal = dTotalIntransitBal - dOrgElementAmount;
						} else if (cTmpDCInd == PD_IND_CREDIT) {
							dTotalIntransitBal = dTotalIntransitBal + dOrgElementAmount;
						}
					}
				}
			}

			sprintf(csTag, "element_rate_%d", i);
			if (GetField_Double(hOrgTxn, csTag, &dTmp)) {
				PutField_Double(hOfstTxn, csTag, dTmp);
			}
		}

		dTotalAcctBal = newround(dTotalAcctBal, PD_DECIMAL_LEN);
		dTotalIntransitBal= newround(dTotalIntransitBal, PD_DECIMAL_LEN);

DEBUGLOG(("FormOffsetTxn:: AcctBal [%lf]\n", dTotalAcctBal));
DEBUGLOG(("FormOffsetTxn:: Intansit[%lf]\n", dTotalIntransitBal));

		PutField_Double(hContext, "element_acct_bal", dTotalAcctBal);
		PutField_Double(hContext, "element_intransit", dTotalIntransitBal);
	}

	return iRet;
}


int	ProcessOffsetTxn(hash_t *hTxn, hash_t *hContext)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	cTmp;

	double	dTotalAcctBal = 0.0;
	double	dTotalIntransitBal = 0.0;

	char	*csOrgTxnSeq = NULL;
	char	*csTxnSeq = NULL;
	char	*csBatchSeq = NULL;

	char	cAmtType;
	int	iElementCnt = 0;
	int	i;
	char	csTag[PD_TAG_LEN + 1];
	double	dTmp = 0.0;

	hash_t	*hTxnRec;
	hTxnRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnRec, 0);

	hash_t *hTxnElement;
	hTxnElement = (hash_t*) malloc(sizeof(hash_t));

	hash_t *hRelation;
	hRelation = (hash_t*) malloc(sizeof(hash_t));


	if (GetField_CString(hTxn, "txn_seq", &csTxnSeq)) {
DEBUGLOG(("ProcessOffsetTxn::TxnSeq [%s]\n", csTxnSeq));
	}

	if (GetField_CString(hContext, "batch_txn_seq", &csBatchSeq)) {
DEBUGLOG(("ProcessOffsetTxn:: BatchTxnSeq[%s]\n", csBatchSeq));
	}

	if (GetField_CString(hTxn, "org_txn_seq", &csOrgTxnSeq)) {
DEBUGLOG(("ProcessOffsetTxn:: OrgTxnSeq [%s]\n", csOrgTxnSeq));
	}


	if (GetField_CString(hContext, "update_user", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn:: update_user [%s]\n", csTmp));

		PutField_CString(hTxnRec, "add_user", csTmp);
		PutField_CString(hTxnRec, "update_user", csTmp);
		PutField_CString(hTxnRec, "create_user", csTmp);

		PutField_CString(hTxn, "add_user", csTmp);
		PutField_CString(hTxn, "update_user", csTmp);
		PutField_CString(hTxn, "create_user", csTmp);
	}

	PutField_Int(hTxn, "db_commit", PD_FALSE);
DEBUGLOG(("ProcessOffsetTxn: Call OMTChannel: AddTxnLog\n"));

	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Add");
	iRet = (unsigned long)(*DBObjPtr)(hTxn);

	if (iRet == PD_OK) {
		if (GetField_CString(hTxn, "baid", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn:: baid [%s]\n", csTmp));
			PutField_CString(hTxnRec, "baid", csTmp);
		}

		if (GetField_CString(hContext, "txn_country", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn:: txn_country [%s]\n", csTmp));
			PutField_CString(hTxnRec, "txn_country", csTmp);
		}

		if (GetField_CString(hContext, "txn_ccy", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn:: txn_ccy [%s]\n", csTmp));
			PutField_CString(hTxnRec, "txn_ccy", csTmp);
		}

		if (GetField_Double(hContext, "element_acct_bal", &dTotalAcctBal)) {
DEBUGLOG(("ProcessOffsetTxn:: acct_bal [%lf]\n", dTotalAcctBal));
		}

		if (GetField_Double(hContext, "element_intransit", &dTotalIntransitBal)) {
DEBUGLOG(("ProcessOffsetTxn:: intransit [%lf]\n", dTotalIntransitBal));
		}
	

		if (dTotalAcctBal < 0.0) {
			dTotalAcctBal = dTotalAcctBal * (-1.0);
			cAmtType = PD_IND_DEBIT;
		} else if (dTotalAcctBal > 0.0) {
			cAmtType = PD_IND_CREDIT;
		}

		// Acct Bal
		int	iGetOpenBal = PD_FALSE;

		if (dTotalAcctBal > 0.0) {
			PutField_Char(hTxnRec, "amt_type", cAmtType);
			PutField_Double(hTxnRec, "txn_amt", dTotalAcctBal);
			PutField_CString(hTxnRec, "pool", PD_ACCT_BAL_POOL);
DEBUGLOG(("ProcessOffsetTxn:: Call BOOLBalance: UpdateAmount\n"));
			BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
			iRet = (unsigned long)(*BOObjPtr)(hTxnRec);

			if (iRet == PD_OK) {

				iGetOpenBal = PD_TRUE;

                        	if (GetField_Double(hTxnRec, "open_bal", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:open_bal [%f]\n", dTmp));
					PutField_Double(hTxn, "open_bal", dTmp);
                        	}

                        	if (GetField_Double(hTxnRec, "open_in_transit", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:open_in_transit [%f]\n", dTmp));
					PutField_Double(hTxn, "open_in_transit", dTmp);
                        	}

                        	if (GetField_CString(hTxnRec, "approval_date", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:approval_date [%s]\n", csTmp));
					PutField_CString(hTxn, "approval_date", csTmp);
                        	}
		
                        	if (GetField_CString(hTxnRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:approval_timestamp [%s]\n", csTmp));
					PutField_CString(hTxn, "approval_timestamp", csTmp);
                        	}

                        	if (GetField_Double(hTxnRec, "bal", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:balance = [%f]\n", dTmp));
					PutField_Double(hTxn, "bal", dTmp);
                        	}

                        	if (GetField_Double(hTxnRec, "total_hold", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:total_hold = [%f]\n", dTmp));
					PutField_Double(hTxn, "total_hold", dTmp);
                        	}

                        	if (GetField_Double(hTxnRec, "prepaid", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:prepaid = [%f]\n", dTmp));
					PutField_Double(hTxn, "prepaid", dTmp);
                        	}

                        	if (GetField_Double(hTxnRec, "in_transit", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:in_transit = [%f]\n", dTmp));
					PutField_Double(hTxn, "in_transit", dTmp);
                        	}
			}
		}

		// Intransit
		if (iRet == PD_OK) {
		        if (dTotalIntransitBal < 0.0) {
				dTotalIntransitBal = dTotalIntransitBal * (-1.0);
				cAmtType = PD_IND_DEBIT;
			} else if (dTotalIntransitBal > 0.0) {
                		cAmtType = PD_IND_CREDIT;
        		}

			if (dTotalIntransitBal > 0.0) {
				PutField_Char(hTxnRec, "amt_type", cAmtType);
				PutField_Double(hTxnRec, "txn_amt", dTotalIntransitBal);
				PutField_CString(hTxnRec, "pool", PD_INTRANSIT_POOL);

DEBUGLOG(("ProcessOffsetTxn:: Call BOOLBalance: UpdateAmount\n"));
				BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "UpdateAmount");
				iRet = (unsigned long)(*BOObjPtr)(hTxnRec);

				if (iRet == PD_OK) {
					if (iGetOpenBal == PD_FALSE) {
                                		if (GetField_Double(hTxnRec, "open_bal", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:open_bal [%f]\n", dTmp));
		                                        PutField_Double(hTxn, "open_bal", dTmp);
						}
                                		if (GetField_Double(hTxnRec, "open_in_transit", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:open_in_transit [%f]\n", dTmp));
							PutField_Double(hTxn, "open_in_transit", dTmp);
                                		}
						if (GetField_CString(hTxnRec, "approval_date", &csTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:approval_date [%s]\n", csTmp));
							PutField_CString(hTxn, "approval_date", csTmp);
                                		}
                                		if (GetField_CString(hTxnRec, "approval_timestamp", &csTmp))  {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:approval_timestamp [%s]\n", csTmp));
							PutField_CString(hTxn, "approval_timestamp", csTmp);
                                		}
					}

					if (GetField_Double(hTxnRec, "bal", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:balance = [%f]\n", dTmp));
						PutField_Double(hTxn, "bal", dTmp);
					}

					if (GetField_Double(hTxnRec, "total_hold", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:total_hold = [%f]\n", dTmp));
						PutField_Double(hTxn, "total_hold", dTmp);
					}

					if (GetField_Double(hTxnRec, "prepaid", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:prepaid = [%f]\n", dTmp));
						PutField_Double(hTxn, "prepaid", dTmp);
					}

					if (GetField_Double(hTxnRec, "in_transit", &dTmp)) {
DEBUGLOG(("ProcessOffsetTxn::Call BOOLBalance:in_transit = [%f]\n", dTmp));
						PutField_Double(hTxn, "in_transit", dTmp);
					}
				}
			}
		}
	}


	// Add Element
	if (iRet == PD_OK) {

		if (GetField_Int(hTxn, "element_total_cnt", &iElementCnt)) {
DEBUGLOG(("ProcessOffsetTxn:: element_total_cnt [%d]\n", iElementCnt));
		}

		hash_init(hTxnElement, 0);

		if (GetField_CString(hContext, "update_user", &csTmp)) {
			PutField_CString(hTxnElement, "update_user", csTmp);
			PutField_CString(hTxnElement, "add_user", csTmp);
			PutField_CString(hTxnElement, "create_user", csTmp);
		}

		for (i = 1 ; i < iElementCnt + 1; i++) {
			PutField_CString(hTxnElement, "txn_seq", csTxnSeq);

			sprintf(csTag, "element_ccy_%d", i);
			if (GetField_CString(hTxn, csTag, &csTmp)) {
				PutField_CString(hTxnElement, "txn_ccy", csTmp);
			}

			sprintf(csTag, "element_amount_%d", i);
			if (GetField_Double(hTxn, csTag, &dTmp)) {
				PutField_Double(hTxnElement, "txn_amt", dTmp);
			}

			sprintf(csTag, "element_type_%d", i);
			if (GetField_CString(hTxn, csTag, &csTmp)) {
				PutField_CString(hTxnElement, "txn_element_type", csTmp);
			}

			sprintf(csTag, "part_type_%d", i);
                        if (GetField_Char(hTxn, csTag, &cTmp)) {
                                PutField_Char(hTxnElement, "party_type", cTmp);
                        }
		
			sprintf(csTag, "element_amt_type_%d", i);			
			if (GetField_CString(hTxn, csTag, &csTmp)) {
                                PutField_CString(hTxnElement, "amount_type", csTmp);
			}

DEBUGLOG(("ProcessOffsetTxn Call BOOLTxnElements:AddPspTxnElement [%d]\n",i ));
			BOObjPtr = CreateObj(BOPtr, "BOOLTxnElements", "AddPspTxnElement");
			iRet = (unsigned long)(*BOObjPtr)(hTxnElement);

			if (iRet != PD_OK) {
DEBUGLOG(("ProcessOffsetTxn Call BOOLTxnElements:AddPspTxnElement [%d] error\n",i ));
				break;	
			} else {
DEBUGLOG(("ProcessOffsetTxn Call BOOLTxnElements:AddPspTxnElement [%d] completed\n",i ));
			}
		}

		hash_destroy(hTxnElement);

	}	


	if (iRet == PD_OK) {
		PutField_Char(hTxn, "status", PD_COMPLETE);
		PutField_Char(hTxn, "ar_ind", PD_ACCEPT);
		PutField_CString(hTxn, "sub_status", PD_APPROVED);
		//PutField_Char(hTxn, "recon_status", PD_UNRECONCILED);
		PutField_Char(hTxn, "recon_status", PD_RECON_NOT_REQ);
		

DEBUGLOG(("ProcessOffsetTxn Call DBOLTransaction:Update\n"));

		DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
		iRet = (unsigned long)(*DBObjPtr)(hTxn);
	}
	
	if (iRet == PD_OK) {
DEBUGLOG(("ProcessOffsetTxn Call DBOLTxnPspDetail:Add\n"));

                DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Add");
                if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
                        iRet = INT_ERR;
                }
        }

        if (iRet == PD_OK) {
DEBUGLOG(("ProcessOffsetTxn Call DBOLTxnPspDetail:Update\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLTxnPspDetail", "Update");
                if ((unsigned long)(*DBObjPtr)(hTxn) != PD_OK) {
                        iRet = INT_ERR;
                }
	}

	if (iRet == PD_OK) {
		hash_init(hRelation, 0);
		PutField_Char(hRelation, "party", PD_TYPE_PSP);
		PutField_CString(hRelation, "p1_txn_id", csOrgTxnSeq);
		PutField_CString(hRelation, "p2_txn_id", csTxnSeq);
		PutField_Char(hRelation, "txn_level", PD_TXN_LEVEL);
		PutField_Char(hRelation, "relation_type", PD_REL_LINKAGE);
		
		if (GetField_CString(hContext, "update_user", &csTmp)) {
			PutField_CString(hRelation, "update_user", csTmp);
			PutField_CString(hRelation, "add_user", csTmp);
			PutField_CString(hRelation, "create_user", csTmp);
		}

DEBUGLOG(("ProcessOffsetTxn Call DBOLTxnRelation:Add [%s][%s]\n", csOrgTxnSeq, csTxnSeq));

                DBObjPtr = CreateObj(DBPtr, "DBOLTxnRelation", "Add");
                if ((unsigned long)(*DBObjPtr)(hRelation) != PD_OK) {
                        iRet = INT_ERR;
                }

		if (iRet == PD_OK) {
			PutField_CString(hRelation, "p1_txn_id", csTxnSeq);

			if (GetField_CString(hContext, "txn_seq", &csTmp)) {
				PutField_CString(hRelation, "p2_txn_id", csTmp);

DEBUGLOG(("ProcessOffsetTxn Call DBOLTxnRelation:Add [%s][%s]\n", csTxnSeq, csTmp));
			}

                	DBObjPtr = CreateObj(DBPtr, "DBOLTxnRelation", "Add");
	                if ((unsigned long)(*DBObjPtr)(hRelation) != PD_OK) {
       	                	iRet = INT_ERR;
			}
		}


		if (iRet == PD_OK) {

DEBUGLOG(("ProcessOffsetTxn  BatchTxnRelation!\n"));
			PutField_Char(hRelation, "batch_type", PD_COMBINE);
			PutField_Char(hRelation, "batch_sub_type", PD_COMBINE_RECON);
			PutField_Int(hRelation, "is_input_txn", 1);
			PutField_Int(hRelation, "is_regen_txn", 0);
			PutField_CString(hRelation, "batch_id", csBatchSeq);
			PutField_Char(hRelation, "txn_level", PD_TXN_LEVEL);
			PutField_CString(hRelation, "txn_id", csOrgTxnSeq);

DEBUGLOG(("ProcessOffsetTxn Call DBOLBatchTxnRelation:Add [%s][%c][%s]\n", csBatchSeq, PD_TXN_LEVEL, csOrgTxnSeq));

                	DBObjPtr = CreateObj(DBPtr, "DBOLBatchTxnRelation", "Add");
			if ((unsigned long)(*DBObjPtr)(hRelation) != PD_OK) {
                        	iRet = INT_ERR;
                	}
		}

		if (iRet == PD_OK) {
			PutField_CString(hRelation, "txn_id", csTxnSeq);
			PutField_Int(hRelation, "is_input_txn", 0);
			PutField_Int(hRelation, "is_regen_txn", 0);

DEBUGLOG(("ProcessOffsetTxn Call DBOLBatchTxnRelation:Add [%s][%c][%s]\n", csBatchSeq, PD_TXN_LEVEL, csTxnSeq));

                	DBObjPtr = CreateObj(DBPtr, "DBOLBatchTxnRelation", "Add");
			if ((unsigned long)(*DBObjPtr)(hRelation) != PD_OK) {
                        	iRet = INT_ERR;
                	}
		}

		hash_destroy(hRelation);
	}

	
	hash_destroy(hTxnRec);
	hash_destroy(hTxnElement);
	hash_destroy(hRelation);

	FREE_ME(hTxnRec);
	FREE_ME(hTxnElement);
	FREE_ME(hRelation);

	return iRet;
}
		
int	ProcessOrgTxn(hash_t *hOrgTxn, hash_t *hContext)
{
	int	iRet = PD_OK;

	char	*csTmp = NULL; 
	char	*csTxnSeq = NULL;

	hash_t	*hRec;	
	hRec = (hash_t*) malloc (sizeof(hash_t));

	hash_init(hRec, 0);
	
	if (GetField_CString(hOrgTxn, "txn_seq", &csTxnSeq)) {
		PutField_CString(hRec, "txn_seq", csTxnSeq);
DEBUGLOG(("ProcessOrgTxn txn_seq [%s]\n", csTxnSeq));
	}

	if (GetField_CString(hContext, "update_user", &csTmp)) {
DEBUGLOG(("ProcessOrgTxn upate_user [%s]\n", csTmp));
		PutField_CString(hRec, "update_user", csTmp);
	}

	PutField_Char(hRec, "status", PD_REVERSED);
	PutField_CString(hRec, "sub_status", PD_UNDO); 

DEBUGLOG(("Authorize() call DBOLTransaction::Update()\n"));
	DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "Update");
	if ((unsigned long)(*DBObjPtr)(hRec) != PD_OK) {
		iRet = INT_ERR;
DEBUGLOG(("Authorize() call DBOLTransaction::Update() failed\n"));
ERRLOG("TxnOmtByUsVBT::Authorize() call DBOLTransaction::Update() failed\n");
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

	return iRet;
}

