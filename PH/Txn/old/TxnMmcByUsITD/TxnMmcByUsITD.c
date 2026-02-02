/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/04              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsITD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnMmcByUsITD(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;

	char	*csTmp = NULL;
	char	cTmp;

	char	*csTmpTxnId = NULL;

	double	dTmp = 0.0;
	int	iTmp = 0;

	int	iMaxRtn;
	
	char	*csTxnSeq = NULL;
	char	*csUser = NULL;

	char	*csMmsTxnSeq = NULL;
	char	*csDtlTxnSeq = NULL;

	char	cStatus;

        char    csTxnInqSeq[PD_TXN_SEQ_LEN +1];	

/*
	char	*csNextTxnSeq = strdup("");
	char	*csNextDtlTxnSeq = strdup("");
*/
	char	csNextTxnSeq[PD_TXN_SEQ_LEN + 1];
	char	csNextDtlTxnSeq[PD_TXN_SEQ_LEN + 1]; 

	char	csTag[PD_TAG_LEN + 1];


        hash_t *hRec;
        hash_t *hDtlRec;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

        recordset_t     *rDtlRecordSet;
        rDtlRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rDtlRecordSet,0);

        hash_t  *hTxn;
        hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

        hash_t  *hDtlTxn;
        hDtlTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hDtlTxn,0);


/* node_id */
	if (GetField_CString(hContext, "node_id", &csTmp)) {
DEBUGLOG(("Authorize::node_id= [%s]\n",csTmp));
	}
	else {
DEBUGLOG(("Authorize::node_id not found!!\n"));
	}

/* inq_id */
	memset(csTxnInqSeq, 0, sizeof(csTxnInqSeq));

	if (GetField_CString(hRequest, "inq_id", &csTmp)) {
		strcpy(csTxnInqSeq, csTmp);
DEBUGLOG(("Authorize::inq_id = [%s]\n",csTxnInqSeq));
		PutField_CString(hTxn, "inq_seq", csTxnInqSeq);
	}
	else {
DEBUGLOG(("Authorize::inq_id not found (new query)!!\n"));
	}

/* req_txn_seq */	
        if(GetField_CString(hRequest,"req_txnid",&csTxnSeq)){
DEBUGLOG(("Authorize::req txn_seq= [%s]\n",csTxnSeq));
		PutField_CString(hTxn, "req_txn_seq", csTxnSeq); 
        }
        else{
DEBUGLOG(("Authorize::req_txnid not found!! \n"));
        }

/* status */
	if(GetField_CString(hRequest, "status", &csTmp)) {
		cStatus = csTmp[0];
DEBUGLOG(("Authorize::status = [%c]\n", cStatus));
		PutField_Char(hTxn, "req_txn_status", cStatus); 
	}
	else {
DEBUGLOG(("Authorize::status not found\n"));

		if ((strlen(csTxnInqSeq) == 0) && (csTxnSeq == NULL)) {

DEBUGLOG(("Authorize::not enought information provided - no inq_id, txnid, status\n"));
ERRLOG("TxnMmcByUsITD::Authorize::not enought information provided - no inq_id, txnid, status\n");

			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (strlen(csTxnInqSeq) > 0) {
/* mms_txn_id */
		if (GetField_CString(hRequest, "txn_seq", &csMmsTxnSeq)) {
DEBUGLOG(("Authorize::mms_txn_seq= [%s]\n",csMmsTxnSeq));
			PutField_CString(hTxn, "mms_txn_seq", csMmsTxnSeq); 
		}
		else {
DEBUGLOG(("Authorize::mms_txn_seq not found!!\n"));
ERRLOG("TxnMmcbyUsITD::Authorize::mms_txn_seq not found!!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}

/* dtl_txn_id */
		if (GetField_CString(hRequest, "dtl_txn_seq", &csDtlTxnSeq)) {
DEBUGLOG(("Authorize::dtl_txn_seq= [%s]\n",csDtlTxnSeq));
			PutField_CString(hTxn, "mms_dtl_txn_seq", csDtlTxnSeq); 
		}
		else {
DEBUGLOG(("Authorize::dtl_txn_seq not found!!\n"));
ERRLOG("TxnMmcbyUsITD::Authorize::dtl_txn_seq not found!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}


/* max_rtn */
	if (iRet == PD_OK) {
		if (GetField_Int(hContext, "itd_max_rtn", &iTmp)) {
DEBUGLOG(("Authorize: ipy_max_return record = [%d]\n", iTmp));
	 		PutField_Int(hContext, "max_rtn", iTmp);
		}
                else {
                        iRet = INT_ERR;
DEBUGLOG(("Authorize: unable to find ITD_max_rtn\n"));
ERRLOG("TxnMmcByUsIPY::Authorize:Unable to find ITD max rtn\n");

                        PutField_Int(hContext,"internal_error",iRet);
                }
	}


/* user */
        if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));

		PutField_CString(hTxn, "add_user", csUser);
		PutField_CString(hTxn, "update_user", csUser);
        }
	else {
DEBUGLOG(("Authorize::user not found!!\n"));
	}


	// ***** Send to MMS (and Node?) *****
	if (iRet == PD_OK) {

		// New Query, fetch records !!
		if (strlen(csTxnInqSeq) == 0) 
		//if (!GetField_CString(hTxn, "inq_id", &csTxnInqSeq)) 
		{
			
			// ***** Gen a new inq_id *****
			DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMmsTxnInqSeq");
                        strcpy(csTxnInqSeq,(*DBObjPtr)());
                        PutField_CString(hTxn,"inq_seq",csTxnInqSeq);

DEBUGLOG(("Authorize::gen inq_seq [%s]\n", csTxnInqSeq));


			// ***** Get mms_txn_header record 
			recordset_init(rRecordSet, 0);

DEBUGLOG(("Authorize::Call DBMmsTransaction: GetMmsTxnHeaderRec\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnHeaderRec");

			if ((unsigned long)((*DBObjPtr)(hTxn, rRecordSet)) != PD_OK) {

DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnHeaderRec Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsTransaction:GetMmsTxnHeaderRec Failed\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if (iRet == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {

					if (iRet == PD_OK) {
	
						if (GetField_CString(hRec, "txn_seq", &csTmpTxnId)) {
DEBUGLOG(("Authorize::process record ..... txn_seq [%s]\n", csTmpTxnId));
							PutField_CString(hTxn, "txn_seq", csTmpTxnId);
						}

						// add record into cache table header
						PutField_Char(hTxn, "status", PD_PROCESSING); // processing status

DEBUGLOG(("Authorize::Call MmsInstantTxnInqHd: Add\n"));
						DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqHd","Add");
						if ((unsigned long)((*DBObjPtr)(hTxn)) == PD_OK) {
DEBUGLOG(("Authorize::MmsInstantTxnInqHd: Add Succ\n"));


							// Get Detail Txn Record
							recordset_init(rDtlRecordSet, 0);

DEBUGLOG(("Authorize::Call DBMmsTransaction: GetMmsTxnDetailByTxnId\n"));

							DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetailByTxnId");
							if ((unsigned long)((*DBObjPtr)(csTmpTxnId, rDtlRecordSet)) == PD_OK) {
								hDtlRec = RecordSet_GetFirst(rDtlRecordSet);
	
								while (hDtlRec) {
									hash_destroy(hDtlTxn);
									hDtlTxn = (hash_t*)  malloc (sizeof(hash_t));
									hash_init(hDtlTxn,0);

									PutField_CString(hDtlTxn, "inq_seq", csTxnInqSeq);
									PutField_CString(hDtlTxn, "txn_seq", csTmpTxnId);

									PutField_CString(hDtlTxn, "add_user", csUser);
									PutField_CString(hDtlTxn, "update_user", csUser);

									if (GetField_CString(hDtlRec, "dtl_txn_seq", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: dtl_txn_seq [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "dtl_txn_seq", csTmp);
									}

									if (GetField_CString(hDtlRec, "txn_code", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: txn_code [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "txn_code", csTmp);
									}

									if (GetField_CString(hDtlRec, "merchant_id", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: merchant_id [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "merchant_id", csTmp);
									}

									if (GetField_CString(hDtlRec, "psp_id", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: psp_id [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "psp_id", csTmp);
									}

									if (GetField_CString(hDtlRec, "mb_id", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: mb_id [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "mb_id", csTmp);
									}

									if (GetField_CString(hDtlRec, "bank_id", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: bank_id [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "bank_id", csTmp);
									}

									if (GetField_Char(hDtlRec, "status", &cTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: status [%c]\n", cTmp));
										PutField_Char(hDtlTxn, "status", cTmp);
									}

									if (GetField_Char(hDtlRec, "ar_ind", &cTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: ar_ind [%c]\n", cTmp));
										PutField_Char(hDtlTxn, "ar_ind", cTmp);
									}

									if (GetField_Char(hDtlRec, "isd_ind", &cTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: isd_ind [%c]\n", cTmp));
										PutField_Char(hDtlTxn, "isd_ind", cTmp);
									}

									if (GetField_CString(hDtlRec, "transmission_datetime", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: txn_date [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "txn_date", csTmp);
									}

									if (GetField_Double(hDtlRec, "txn_amt", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: txn_amt [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "txn_amt", dTmp);
									}

									if (GetField_CString(hDtlRec, "txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: txn_ccy [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "txn_ccy", csTmp);
									}

									if (GetField_Double(hDtlRec, "adjustment", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: adjustment [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "adjustment", dTmp);
									}

									if (GetField_Double(hDtlRec, "exchange_rate", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: exchange_rate [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "exhchange_rate", dTmp);
									}

									if (GetField_Double(hDtlRec, "processing_cost", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: processing_cost [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "processing_cost", dTmp);
									}

									if (GetField_Double(hDtlRec, "bank_charge", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: bank_charge [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "bank_charge", dTmp);
									}

									if (GetField_Double(hDtlRec, "bank_charge_refund", &dTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: bank_charge_refund [%lf]\n", dTmp));
										PutField_Double(hDtlTxn, "bank_charge_refund", dTmp);
									}
	
									if (GetField_CString(hDtlRec, "filing_number", &csTmp)) {
DEBUGLOG(("Authorize::DBMmsTransaction: filing_number [%s]\n", csTmp));
										PutField_CString(hDtlTxn, "filing_number", csTmp);
									}

									// add Record into cache table detail
DEBUGLOG(("Authorize::Call MmsInstantTxnInqDt: Add\n"));
									DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqDt","Add");
									if ((unsigned long)((*DBObjPtr)(hDtlTxn)) == PD_OK) {
DEBUGLOG(("Authorize::MmsInstantTxnInqDt: Add Succ\n"));
									}
									else {
DEBUGLOG(("Authorize::Call DBMmsInstantTxnInqDt:Add Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsInstantTxnInqDt:Add Failed\n");
										iRet = INT_ERR;
										break;
									}
									hDtlRec = RecordSet_GetNext(rDtlRecordSet);
								}
							}
							else {
DEBUGLOG(("Authorize::Call DBMmsTransaction:GetMmsTxnDetailbyTxnId Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsTransaction:GetMmsTxnDetailbyTxnId Failed\n");
								iRet = INT_ERR;
							}
						}
						else {
DEBUGLOG(("Authorize::Call DBMmsInstantTxnInqHd:Add Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsInstantTxnInqHd:Add Failed\n");
							iRet = INT_ERR;
						}
						hRec = RecordSet_GetNext(rRecordSet);
					}
					//Update Header Status
					if (iRet == PD_OK) {
						PutField_Char(hTxn, "status", PD_COMPLETE);

DEBUGLOG(("Authorize::Call MmsInstantTxnInqHd: Update\n"));
						DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqHd","Update");
						if ((unsigned long)((*DBObjPtr)(hTxn)) == PD_OK) {
DEBUGLOG(("Authorize::MmsInstantTxnInqHd: Update Succ\n"));
						}
						else {
DEBUGLOG(("Authorize::Call DBMmsInstantTxnInqHd:Update Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsInstantTxnInqHd:Update Failed\n");
							iRet = INT_ERR;
						}
					}
				}
			}
		}
	}
	// ***** End Send to MMS (and Node?) *****

//. *****************************************************************

	// ***** ChkValidHeader on Cache Table
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call MmsInstantTxnInqHd: ChkValidHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqHd","ChkValidHeader");
		if ((unsigned long)((*DBObjPtr)(&csTxnInqSeq, PD_COMPLETE)) == PD_FOUND) {
DEBUGLOG(("Authorize::MmsInstantTxnInqHd: ChkValidHeader Succ\n"));
		}
		else {
DEBUGLOG(("Authorize::Call DBMmsInstantTxnInqHd:ChkValidHeader Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::Call DBMmsInstantTxnInqHd:ChkValidHeader Failed\n");
			iRet = INT_ERR;
		}
	}

	// ***** Get Next txn_seq and dtl_txn_seq 
	if (iRet == PD_OK) {
		hash_destroy(hDtlTxn);
		hDtlTxn = (hash_t*)  malloc (sizeof(hash_t));
		hash_init(hDtlTxn,0);


		if (GetField_CString(hTxn, "inq_seq", &csTmp)) {
DEBUGLOG(("Authorize::Prepare to get detail - inq_id [%s]\n", csTmp));
			PutField_CString(hDtlTxn, "inq_id", csTmp);
		}

		if (GetField_CString(hTxn, "mms_txn_seq", &csTmp)) {
			PutField_CString(hDtlTxn, "txn_id", csTmp); 
DEBUGLOG(("Authorize::Prepare to get detail - txn_id [%s]\n", csTmp));
		}

		if (GetField_CString(hTxn, "mms_dtl_txn_seq", &csTmp)) {
			PutField_CString(hDtlTxn, "dtl_txn_id", csTmp); 
DEBUGLOG(("Authorize::Prepare to get detail - dtl_txn_id [%s]\n", csTmp));
		}

DEBUGLOG(("Authorize::Call MmsInstantTxnInqDt: GetNextRecSeq\n"));
		memset(csNextTxnSeq, 0, sizeof(csNextTxnSeq));
		memset(csNextDtlTxnSeq, 0, sizeof(csNextDtlTxnSeq));

		DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqDt","GetNextRecSeq");
		iTmpRet = (unsigned long)((*DBObjPtr)(hDtlTxn, &csNextTxnSeq, &csNextDtlTxnSeq));

		if (iTmpRet == PD_OK) {
DEBUGLOG(("Authorize::Call MmsInstantTxnInqDt: GetNextRecSeq Succ\n"));
DEBUGLOG(("Authorize::Call MmsInstantTxnInqDt: NextTxnSeq [%s] NextDtlTxnSeq [%s]\n", csNextTxnSeq, csNextDtlTxnSeq));

			PutField_CString(hDtlTxn, "start_txn_id", csNextTxnSeq);
			PutField_CString(hDtlTxn, "start_dtl_txn_id", csNextDtlTxnSeq);
			
		}
		else if (iTmpRet == PD_NOT_FOUND) {
DEBUGLOG(("Authorize::Call MmsInstantTxnInqDt: GetNextRecSeq Succ - no more next record\n"));
		}
		else {
			iRet = INT_ERR;
		}
	}	
	 
	// ***** Get cache detail record
	if (iRet == PD_OK) {
		if (GetField_Int(hContext, "max_rtn", &iMaxRtn)) {
			PutField_Int(hDtlTxn, "max_rtn", iMaxRtn);
		}

		PutField_CString(hResponse, "inq_id", csTxnInqSeq);

		if (iTmpRet == PD_OK) { // still having pending record
			// ****** Get MmsInstantTxnInqDetail ******
			RecordSet_Destroy(rDtlRecordSet);
        		rDtlRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        		recordset_init(rDtlRecordSet,0);
			
DEBUGLOG(("Authorize::Call DBMmsInstantTxnInqDt: GetDetailbyRange\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMmsInstantTxnInqDt","GetDetailbyRange");

			if ((unsigned long)((*DBObjPtr)(hDtlTxn, rDtlRecordSet)) != PD_OK) {
DEBUGLOG(("Authorize::DBMmsInstantTxnSeqDt:GetDetailbyRange Failed\n"));
ERRLOG("TxnMmcByUsITD::Authorize::DBMmsInstantTxnSeqDt:GetDetailbyRange Failed\n");
				iRet=INT_ERR;
			}
			else {

DEBUGLOG(("Authorize::DBMmsInstantTxnSeqDt:GetDetailbyRange Succ\n"));
				iTmp = 0;

				PutField_Int(hResponse, "total_cnt", iTmp);
				PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);

				hDtlRec = RecordSet_GetFirst(rDtlRecordSet);

				while (hDtlRec) {
					iTmp++;

					if (iTmp <= iMaxRtn) {

DEBUGLOG(("Authorize::DBMmsInstantTxnSeqDt:GetDetailRec fetching...\n"));

						if (GetField_CString(hDtlRec, "txn_seq", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] txn_seq = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "dtl_txn_seq", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "dtl_txn_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] dtl_txn_seq = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "txn_code", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_code_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] txn_code = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "merchant_id", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "merchant_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] merchant_id = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "psp_id", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "psp_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] psp_id = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "mb_id", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "mb_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] mb_id = [%s]\n", iTmp, csTmp));
						}

						if (GetField_CString(hDtlRec, "bank_id", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "bank_id_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] bank_id = [%s]\n", iTmp, csTmp));
						}

						if (GetField_Char(hDtlRec, "status", &cTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_status_%d", iTmp);
							PutField_Char(hResponse, csTag, cTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] status = [%c]\n", iTmp, cTmp));
						}

						if (GetField_Char(hDtlRec, "ar_ind", &cTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "ar_ind_%d", iTmp);
							PutField_Char(hResponse, csTag, cTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] ar_ind = [%c]\n", iTmp, cTmp));
						}

						if (GetField_Char(hDtlRec, "isd_ind", &cTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "isd_ind_%d", iTmp);
							PutField_Char(hResponse, csTag, cTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] isd_ind = [%c]\n", iTmp, cTmp));
						}

						if (GetField_CString(hDtlRec, "txn_date", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_date_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] txn_date = [%s]\n", iTmp, csTmp));
						}

						if (GetField_Double(hDtlRec, "txn_amt", &dTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_amt_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] txn_amt = [%lf]\n", iTmp, dTmp));
						}

						if (GetField_CString(hDtlRec, "txn_ccy", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "txn_ccy_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] txn_ccy = [%s]\n", iTmp, csTmp));
						}

						if (GetField_Double(hDtlRec, "adjustment", &dTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "adjustment_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] adjustment = [%lf]\n", iTmp, dTmp));
						}


						if (GetField_Double(hDtlRec, "exchange_rate", &dTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "exchange_rate_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] exchange_rate = [%lf]\n", iTmp, dTmp));
						}


						if (GetField_Double(hDtlRec, "processing_cost", &dTmp)) { 
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "processing_cost_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] processing_cost = [%lf]\n", iTmp, dTmp));
						}

						if (GetField_Double(hDtlRec, "bank_charge", &dTmp)) { 
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "bank_charge_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] bank_charge = [%lf]\n", iTmp, dTmp)); 
						}

						if (GetField_Double(hDtlRec, "bank_charge_refund", &dTmp)) { 
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "bank_charge_refund_%d", iTmp);
							PutField_Double(hResponse, csTag, dTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] bank_charge_refund = [%lf]\n", iTmp, dTmp)); 
						}

						if (GetField_CString(hDtlRec, "filing_number", &csTmp)) {
							memset(csTag, 0, sizeof(csTag));
							sprintf(csTag, "filing_number_%d", iTmp);
							PutField_CString(hResponse, csTag, csTmp);
DEBUGLOG(("Authorize::GetDetailbyRange [%d] filing_number = [%s]\n", iTmp, csTmp));
						}

						PutField_Int(hResponse, "total_cnt", iTmp);
					}
					else {
						PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_PENDING);
						break;
					}
					hDtlRec = RecordSet_GetNext(rDtlRecordSet);
				}
			}
		}
		else {
			PutField_Int(hResponse, "total_cnt", 0);
			PutField_Int(hResponse, "end_ind", PD_MMS_FETCH_END);
		}
	}

	// Remove the cache data??
	/* 	
	if (iRet == PD_OK) {
		if (GetField_Int(hResponse, "end_ind", iTmp)) {
			if (iTmp == PD_MMS_FETCH_END) {
				// Delete Data from cache????

			}
		}
	}
	*/


	RecordSet_Destroy(rRecordSet);
	RecordSet_Destroy(rDtlRecordSet);
	FREE_ME(rRecordSet);
	FREE_ME(rDtlRecordSet);

	hash_destroy(hTxn);
	hash_destroy(hDtlTxn);
	FREE_ME(hTxn);
	FREE_ME(hDtlTxn);

/*
	FREE_ME(csNextTxnSeq);
	FREE_ME(csNextDtlTxnSeq);
*/

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMmcByUsITD Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
