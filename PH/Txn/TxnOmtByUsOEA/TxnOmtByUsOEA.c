/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/09/06              Elvis Wong
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsOEA.h"
#include "myrecordset.h"
#include "dbutility.h"

#define       PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

int ProcessMerchTxn(hash_t * hMerchTxnRec);

void TxnOmtByUsOEA(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t* hContext,
		hash_t* hRequest,
		hash_t* hResponse)
{
	int	iRet = PD_OK;
	int	iDtlRet = PD_OK;
	int	iTmpRet = PD_FOUND;
	int	iPairNum = 0;
	int	iCnt = 0;
	int	i = 0;
	int 	iTxnRecNum = 0;
	int	iTmp = 0;
	double 	dTmp = 0.0;
	char    cType;
	char	cPartyType;
	char	cDCInd;
	char	cTmp;
	char	*csIPAddr = NULL;
	char	*csPHDate = NULL;
	char	*csLocalDate = NULL;
	char	*csLocalTime = NULL;
	char	*csMerchTxnId = NULL;
	char	*csBaidStmtTxnId = NULL;
	char	csBaidTxnId[PD_TXN_SEQ_LEN + 1]; 
	char	*csUser = NULL;
	char	*csTmp = NULL;
	char    csTxnDateTime[PD_DATETIME_LEN + 1];
	char	csMerchPspBatchSeq[PD_TXN_SEQ_LEN + 1];
	char    csTag[PD_TAG_LEN+1];

	hash_t *hBatchRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBatchRec, 0);

	hash_t  *hMerchTxnRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hMerchTxnRec,0);

        hash_t  *hPspTxnRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hPspTxnRec,0);

	hash_t	*hTxnRelRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTxnRelRec,0);

	hash_t *hAddTxn;
	hash_t *hGetTxn;
        recordset_t *rTxnRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rTxnRecordSet,0);

	hash_t *hGetTxnRel;
	recordset_t *rTxnRelRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rTxnRelRecordSet,0);

DEBUGLOG(("Authorize::TxnOmtByUsOEA Begin\n"));

/* type */
	if (GetField_CString(hRequest, "type", &csTmp)) {
		cType = csTmp[0];
DEBUGLOG(("Authorize() type = [%c]\n", cType));
        } else {
                iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() type NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsOEA::Authorize() type NOT FOUND!!!\n");
        }

/* user */
        if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize() user = [%s]\n", csUser));
                PutField_CString(hContext,"update_user",csUser);
        } else {
                iRet = INT_USER_NOT_FOUND;
		PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() user NOT FOUND!!!\n"));
ERRLOG("TxnOmtByUsOEA::Authorize() user NOT FOUND!!!\n");
        }

/* ip_addr */
	if (GetField_CString(hRequest, "ip_addr", &csIPAddr)) {
DEBUGLOG(("Authorize() ip_addr = [%s]\n", csIPAddr));
        }

/* PHDATE */
        if (GetField_CString(hContext, "PHDATE", &csPHDate)) {
DEBUGLOG(("Authorize() PHDATE = [%s]\n",csPHDate));
        }

/* transmission_datetime */
	if (GetField_CString(hContext, "local_tm_date", &csLocalDate)) {
DEBUGLOG(("Authorize() local_tm_date [%s]\n", csLocalDate));

             	strcpy(csTxnDateTime, csLocalDate);

       		if (GetField_CString(hContext, "local_tm_time", &csLocalTime)) {
DEBUGLOG(("Authorize() local_tm_time [%s]\n", csLocalTime));
                                
			strcat(csTxnDateTime, csLocalTime);
               	}
      	}

/* total_cnt */
	if (GetField_CString(hRequest, "total_cnt", &csTmp)) {
DEBUGLOG(("Authorize() total_cnt = [%s]\n", csTmp));
		iCnt = atoi(csTmp);
	} else {
		iRet = INT_ERR;
		PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize() total_cnt not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::total_cnt not found\n");
	}

	if (iRet == PD_OK) {
		for (i = 0; i < iCnt; i++) {

			hAddTxn = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(hAddTxn, 0);

/* pair_num */
			sprintf(csTag, "%s_pair_num_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
				iTmp = atoi(csTmp); 
DEBUGLOG(("Authorize::() [%s] = [%d]\n", csTag, iTmp));

				PutField_Int(hAddTxn,"pair_num",iTmp);
			} else {
				iDtlRet = INT_ERR;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
			}

/* party_type */
			sprintf(csTag, "%s_party_type_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
				cPartyType = csTmp[0];
DEBUGLOG(("Authorize::() [%s] = [%c]\n", csTag, cPartyType));
				
				PutField_Char(hAddTxn,"party_type",cPartyType);
			} else {
                                iDtlRet = INT_PARTY_TYPE_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        }

/* party_id */
			sprintf(csTag, "%s_party_id_%d", PD_DETAIL_TAG, i+1);
			if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                PutField_CString(hAddTxn,"party_id",csTmp);
			} else {
				iDtlRet = INT_PARTY_ID_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
			}

/* dc_ind */
			sprintf(csTag, "%s_dc_ind_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
				cTmp = csTmp[0];
DEBUGLOG(("Authorize::() [%s] = [%c]\n", csTag, cTmp));

                                PutField_Char(hAddTxn,"dc_ind",cTmp);
                        } else {
                                iDtlRet = INT_DC_IND_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        }

/* ccy */
                        sprintf(csTag, "%s_ccy_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                PutField_CString(hAddTxn,"txn_ccy",csTmp);
                        } else {
                                iDtlRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        }

/* txnamt */
                        sprintf(csTag, "%s_txnamt_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
				dTmp = string2double((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::() [%s] = [%f]\n", csTag, dTmp));

                                PutField_Double(hAddTxn,"txn_amt",dTmp);
                        } else {
                                iDtlRet = INT_PAY_AMOUNT_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        }

/* remark */
                        sprintf(csTag, "%s_remark_%d", PD_DETAIL_TAG, i+1);
                        if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                PutField_CString(hAddTxn,"remark",csTmp);
                        } else {
                                iDtlRet = INT_REMARK_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        }

			// Party Type
			if (cPartyType == PD_TYPE_MERCHANT) {
							
/* service */
                        	sprintf(csTag, "%s_service_%d", PD_DETAIL_TAG, i+1);
                        	if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                	PutField_CString(hAddTxn,"service",csTmp);
                        	} else {
                        	        iDtlRet = INT_SERVICE_CODE_MISSING;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        	}			

/* country */
                        	sprintf(csTag, "%s_country_%d", PD_DETAIL_TAG, i+1);
                        	if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                        PutField_CString(hAddTxn,"txn_country",csTmp);
                        	} else {
                        	        iDtlRet = INT_TXN_COUNTRY_NOT_FOUND;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                        	}
			} else if (cPartyType == PD_TYPE_PSP) {

/* stmt_txnid */
                                sprintf(csTag, "%s_stmt_txnid_%d", PD_DETAIL_TAG, i+1);
                                if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));

                                        PutField_CString(hAddTxn,"stmt_txnid",csTmp);

DEBUGLOG(("Authorize:: call DBOLBAIDTxn::MatchRespTxnNoWait()\n"));
					DBObjPtr = CreateObj (DBPtr, "DBOLBAIDTxn", "MatchRespTxnNoWait");
					iTmpRet = (unsigned long) (*DBObjPtr) (csTmp, PD_COMPLETE);
					if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: call DBOLBAIDTxn::MatchRespTxnNoWait() failed\n"));
						iRet = INT_RECON_IN_ANOTHER_PROCESS;
						PutField_Int(hContext, "internal_error", iRet);
						break;
					}
                                } else {
                                        iDtlRet = INT_ERR;
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnOmtByUsOEA::Authorize::[%s] not found\n", csTag);
                                }
			}

			RecordSet_Add(rTxnRecordSet, hAddTxn);
		}

		if(iDtlRet!=PD_OK){
			iRet = iDtlRet;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	// Handle Merch PSP Batch 
	if (iRet == PD_OK) {

		// Get Merch PSP Batch Seq	
DEBUGLOG(("Authorize::Call DBOLTxnSeq: GetNextMerchPspBatchSeq\n"));
              	DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextMerchPspBatchSeq");
             	strcpy(csMerchPspBatchSeq, (*DBObjPtr)());	
DEBUGLOG(("Authorize::Call DBOLTxnSeq: GetNextMerchPspBatchSeq, csMerchPspBatchSeq = [%s]\n", csMerchPspBatchSeq));

		// Batch Relation Info 
		PutField_CString(hBatchRec,"batch_id",csMerchPspBatchSeq);
                PutField_Char(hBatchRec,"type",cType);		
		PutField_CString(hBatchRec,"create_user",csUser);

		// Add Merch PSP Batch Type
DEBUGLOG(("Authorize::Call DBOLMerchPspBatchType:Add\n"));
             	DBObjPtr = CreateObj(DBPtr, "DBOLMerchPspBatchType", "Add");
             	iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
               	if (iRet != PD_OK) {
                      	iRet = INT_ERR;
DEBUGLOG(("Authorize::Call DBOLMerchPspBatchType Add::failed!!!\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::call DBOLMerchPspBatchType Add::failed!!!\n");
             	}
      	}

	// Handle Merchant and PSP Transactions
	if (iRet == PD_OK) {

		hGetTxn = RecordSet_GetFirst(rTxnRecordSet);
                while ((iRet == PD_OK) && (hGetTxn)) {

			if (iTxnRecNum%2 == 0) {
				hash_init(hMerchTxnRec,0);
                        	hash_init(hPspTxnRec,0);
			}

			iTxnRecNum++;
			
/* pair_num */
                        if (GetField_Int(hGetTxn, "pair_num", &iPairNum)) {
DEBUGLOG(("Authorize::() pair_num = [%d]\n", iPairNum));
                        } else {
                                iDtlRet = INT_ERR;
DEBUGLOG(("Authorize::pair_num not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::pair_num not found\n");
                        }

/* party_type */
                        if (GetField_Char(hGetTxn, "party_type", &cPartyType)) {
DEBUGLOG(("Authorize::() party_type = [%c]\n", cPartyType));
	
				if (cPartyType == PD_TYPE_MERCHANT) {
                                    	PutField_Char(hMerchTxnRec,"party_type",cPartyType);
                               	} else if (cPartyType == PD_TYPE_PSP) {
                                    	PutField_Char(hPspTxnRec,"party_type",cPartyType);
                            	}
                        } else {
                                iDtlRet = INT_PARTY_TYPE_NOT_FOUND;
DEBUGLOG(("Authorize::party_type not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::party_type not found\n");
                        }

/* party_id */
                        if (GetField_CString(hGetTxn, "party_id", &csTmp)) {
DEBUGLOG(("Authorize::() party_id = [%s]\n", csTmp));

				if (cPartyType == PD_TYPE_MERCHANT) {
                                	PutField_CString(hMerchTxnRec,"merchant_id",csTmp);
				} else if (cPartyType == PD_TYPE_PSP) {
                                	PutField_CString(hPspTxnRec,"psp_id",csTmp);
                        	}
                        } else {
                                iDtlRet = INT_PARTY_ID_NOT_FOUND;
DEBUGLOG(("Authorize::party_id not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::party_id not found\n");
                        }

/* dc_ind */
                        if (GetField_Char(hGetTxn, "dc_ind", &cTmp)) {
DEBUGLOG(("Authorize::() dc_ind = [%c]\n", cTmp));

                                if (cPartyType == PD_TYPE_MERCHANT) {
                                        PutField_Char(hMerchTxnRec,"dc_ind",cTmp);
                                } else if (cPartyType == PD_TYPE_PSP) {
                                        PutField_Char(hPspTxnRec,"dc_ind",cTmp);
                                }
                        } else {
                                iDtlRet = INT_DC_IND_NOT_FOUND;
DEBUGLOG(("Authorize::dc_ind not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::dc_ind not found\n");
                        }

/* txn_ccy */
                        if (GetField_CString(hGetTxn, "txn_ccy", &csTmp)) {
DEBUGLOG(("Authorize::() txn_ccy = [%s]\n", csTmp));

				if (cPartyType == PD_TYPE_MERCHANT) {
                                        PutField_CString(hMerchTxnRec,"txn_ccy",csTmp);
                                } else if (cPartyType == PD_TYPE_PSP) {
                                        PutField_CString(hPspTxnRec,"txn_ccy",csTmp);
                                }
                        } else {
                                iDtlRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("Authorize::txn_ccy not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::txn_ccy not found\n");
                        }

/* txn_amt */
                        if (GetField_Double(hGetTxn, "txn_amt", &dTmp)) {
DEBUGLOG(("Authorize::() txn_amt = [%f]\n", dTmp));

				if (cPartyType == PD_TYPE_MERCHANT) {
                                        PutField_Double(hMerchTxnRec,"txn_amt",dTmp);
                                } else if (cPartyType == PD_TYPE_PSP) {
                                        PutField_Double(hPspTxnRec,"txn_amt",dTmp);
                                }
                        } else {
                                iDtlRet = INT_PAY_AMOUNT_NOT_FOUND;
DEBUGLOG(("Authorize::txn_amt not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::txn_amt not found\n");
                        }

/* remark */
                        if (GetField_CString(hGetTxn, "remark", &csTmp)) {
DEBUGLOG(("Authorize::() remark = [%s]\n", csTmp));

                                if (cPartyType == PD_TYPE_MERCHANT) {
                                        PutField_CString(hMerchTxnRec,"remark",csTmp);
                                } else if (cPartyType == PD_TYPE_PSP) {
                                        PutField_CString(hPspTxnRec,"remark",csTmp);
                                }
                        } else {
                                iDtlRet = INT_REMARK_NOT_FOUND;
DEBUGLOG(("Authorize::remark not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::remark not found\n");
                        }

			if (cPartyType == PD_TYPE_MERCHANT) {

/* service */
                        	if (GetField_CString(hGetTxn, "service", &csTmp)) {
DEBUGLOG(("Authorize::() service = [%s]\n", csTmp));

                               		PutField_CString(hMerchTxnRec,"service",csTmp);
                        	} else {
                        	        iDtlRet = INT_SERVICE_CODE_MISSING;
DEBUGLOG(("Authorize::service not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::service not found\n");
                        	}

/* txn_country */
                                if (GetField_CString(hGetTxn, "txn_country", &csTmp)) {
DEBUGLOG(("Authorize::() txn_country = [%s]\n", csTmp));

                                     	PutField_CString(hMerchTxnRec,"txn_country",csTmp);
                                } else {
                                        iDtlRet = INT_TXN_COUNTRY_NOT_FOUND;
DEBUGLOG(("Authorize::txn_country not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::txn_country not found\n");
                                }

				// type
				PutField_Char(hMerchTxnRec,"type",cType);

				// ip_addr
				PutField_CString(hMerchTxnRec,"ip_addr",csIPAddr);

				// PHDATE
				PutField_CString(hMerchTxnRec,"PHDATE",csPHDate);
		
				// local_tm_date
				PutField_CString(hMerchTxnRec,"local_tm_date",csLocalDate);

				// local_tm_time
				PutField_CString(hMerchTxnRec,"local_tm_time",csLocalTime);
	
				// transmission_datetime
				PutField_CString(hMerchTxnRec,"transmission_datetime",csTxnDateTime);
	
				// user
                                PutField_CString(hMerchTxnRec,"add_user",csUser);

			} else if (cPartyType == PD_TYPE_PSP) {
		
/* stmt_txnid */
                                if (GetField_CString(hGetTxn, "stmt_txnid", &csTmp)) {
DEBUGLOG(("Authorize::() stmt_txnid = [%s]\n", csTmp));

                                        PutField_CString(hPspTxnRec,"stmt_txnid",csTmp);
                                } else {
                                        iDtlRet = INT_ERR;
DEBUGLOG(("Authorize::stmt_txnid not found\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::stmt_txnid not found\n");
                                }	
				
				// user
				PutField_CString(hPspTxnRec,"add_user",csUser);
			}

			if(iDtlRet!=PD_OK){
                        	iRet = iDtlRet;
                	}

			hGetTxn = RecordSet_GetNext(rTxnRecordSet);

			if (iTxnRecNum%2 == 0) {

				// Handle BAID Txn (Call OL Txn Engine)
				if (iRet == PD_OK) {

					// Set Txn Engine Info
					if (cType == PD_MERCH_PSP_BATCH_TYPE) {
						PutField_CString(hPspTxnRec,"activity",PD_TXN_ENGING_ACTIVITIY_RECON);
						if (GetField_Char(hPspTxnRec, "dc_ind", &cDCInd)) {
							if (cDCInd == PD_IND_CREDIT) {
								PutField_CString(hPspTxnRec,"bank_stmt_type","ERROR_ADJUSTMENT_CR");
							} else if (cDCInd == PD_IND_DEBIT) {
								PutField_CString(hPspTxnRec,"bank_stmt_type","ERROR_ADJUSTMENT_DR");
							}
						}
						PutField_CString(hPspTxnRec,"trigger_type",PD_TRIGGER_MANUAL);
						PutField_CString(hPspTxnRec,"input_channel",PD_CHANNEL_OMT);
						PutField_CString(hPspTxnRec,"recon_type",PD_ENGINE_RECON_SAME);
						PutField_CString(hPspTxnRec,"use_pf","0");
						PutField_CString(hPspTxnRec,"have_charge","0");
						PutField_CString(hPspTxnRec,"have_interest","0");
						PutField_CString(hPspTxnRec,"add_user",csUser);
						if (GetField_CString(hPspTxnRec, "stmt_txnid", &csBaidStmtTxnId)) {
							PutField_Int(hPspTxnRec,"baid_txn_cnt",1);
							PutField_CString(hPspTxnRec,"baid_txn_id_0",csBaidStmtTxnId);
						}
					}

DEBUGLOG(("Authorize::Call BOOLTxnEngine:DoAction\n"));
					BOObjPtr = CreateObj(BOPtr,"BOOLTxnEngine","DoAction");
                                        iRet = (unsigned long)(*BOObjPtr)(hPspTxnRec);
                                        if (iRet != PD_OK) {
DEBUGLOG(("Authorize::call BOOLTxnEngine::DoAction::failed!!!\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::call BOOLTxnEngine::DoAction::failed!!!\n");
                                        } else {

/* baid_txn_id */
						hash_init(hTxnRelRec, 0);
						PutField_Char(hTxnRelRec, "party_type", PD_TYPE_PSP);
						PutField_CString(hTxnRelRec, "p1_txn_id", csBaidStmtTxnId);
						PutField_Char(hTxnRelRec, "txn_level", PD_STMT_LEVEL);
						PutField_Char(hTxnRelRec, "relation_type", PD_REL_LINKAGE);
DEBUGLOG(("Authorize:: Call DBOLTxnRelation:GetP2TxnId\n"));
						DBObjPtr = CreateObj(DBPtr, "DBOLTxnRelation", "GetP2TxnId");
						iTmpRet = (unsigned long)(*DBObjPtr)(hTxnRelRec, rTxnRelRecordSet);
						if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: Call DBOLTxnRelation:GetP2TxnId failed!!!\n"));
ERRLOG("TxnOmtByUsOEA:: Authorize:: Call DBOLTxnRelation:GetP2TxnId failed!!!\n");
							iRet = PD_ERR;
						} else {
							hGetTxnRel = RecordSet_GetFirst(rTxnRelRecordSet);
							GetField_CString(hGetTxnRel, "p2_txn_id", &csTmp);

DEBUGLOG(("Authorize:: Call DBOLStmtTxnRelation:GetTxnIdByStmtTxnId\n"));
							DBObjPtr = CreateObj(DBPtr, "DBOLStmtTxnRelation", "GetTxnIdByStmtTxnId");
							iTmpRet = (unsigned long)(*DBObjPtr)(csTmp, csBaidTxnId);
							if (iTmpRet != PD_FOUND) {
DEBUGLOG(("Authorize:: Call DBOLStmtTxnRelation:GetTxnIdByStmtTxnId failed!!!\n"));
ERRLOG("TxnOmtByUsOEA:: Authorize:: Call DBOLStmtTxnRelation:GetTxnIdByStmtTxnId failed!!!\n");
								iRet = PD_ERR;
							} else {
DEBUGLOG(("Authorize:: baid_txn_id = [%s]\n", csBaidTxnId));
								hash_destroy(hTxnRelRec);
								hash_init(hTxnRelRec, 0);

								PutField_CString(hTxnRelRec, "txn_seq", csBaidTxnId);
								GetField_CString(hPspTxnRec, "remark", &csTmp);
								PutField_CString(hTxnRelRec, "remark", csTmp);
								PutField_CString(hTxnRelRec, "update_user", csUser);
DEBUGLOG(("Authorize:: Call DBOLTransaction:UpdateTxnDetailRemark\n"));
								DBObjPtr = CreateObj(DBPtr, "DBOLTransaction", "UpdateTxnDetailRemark");
								iTmpRet = (unsigned long)(*DBObjPtr)(hTxnRelRec);
								if (iTmpRet != PD_OK) {
DEBUGLOG(("Authorize:: Call DBOLTransaction:UpdateTxnDetailRemark failed!!!\n"));
ERRLOG("TxnOmtByUsOEA:: Authorize:: Call DBOLTransaction:UpdateTxnDetailRemark failed!!!\n");
									iRet = PD_ERR;
								}
							}
						}

						hash_destroy(hTxnRelRec);
					}
				}
			
				// Handle Merchant Txn (Generate Txn)
				if (iRet == PD_OK) {
				
					// Prcoess Merchant Txn
					if (iRet == PD_OK) {

						iRet = ProcessMerchTxn(hMerchTxnRec);
						if (iRet == PD_OK) {

/* merch_txn_id */
							if (GetField_CString(hMerchTxnRec, "merch_txn_id", &csMerchTxnId)) {
DEBUGLOG(("Authorize::() merch_txn_id = [%s]\n", csMerchTxnId));
                                			} 				
						} else {
							TxnAbort();
							iRet = INT_INSUFFICIENT_FUND;
							PutField_Int(hContext,"internal_error",iRet);
						}
					}
				}

				// Handle Merch PSP Batch
				if (iRet == PD_OK) {

					// Batch Relation Info
					PutField_Int(hBatchRec,"pair_seq",iPairNum);
					PutField_CString(hBatchRec,"merchant_txn_id",csMerchTxnId);
					PutField_CString(hBatchRec,"baid_txn_id",csBaidTxnId);

					// Add Merch PSP Batch Relation
DEBUGLOG(("Authorize::Call DBOLMerchPspBatchRelation:Add\n"));
					if (iRet == PD_OK) {
                				DBObjPtr = CreateObj(DBPtr, "DBOLMerchPspBatchRelation", "Add");
                				iRet = (unsigned long)(*DBObjPtr)(hBatchRec);
                				if (iRet != PD_OK) {
                        				iRet = INT_ERR;
DEBUGLOG(("Authorize::Call DBOLMerchPspBatchRelation Add::failed!!!\n"));
ERRLOG("TxnOmtByUsOEA::Authorize::call DBOLMerchPspBatchRelation Add::failed!!!\n");
                				}
					}
				}

				hash_destroy(hMerchTxnRec);
				hash_destroy(hPspTxnRec);	
			}
		}
        }

	// Update Response
	if (iRet == PD_OK) {

/* batch_id */
		if(GetField_CString(hBatchRec,"batch_id",&csTmp)){
                        PutField_CString(hResponse,"batch_id",csTmp);
                }
	}

	FREE_ME(hMerchTxnRec);
	FREE_ME(hPspTxnRec);
	FREE_ME(hBatchRec);
	FREE_ME(hTxnRelRec);

	RecordSet_Destroy(rTxnRecordSet);
        FREE_ME(rTxnRecordSet);
	RecordSet_Destroy(rTxnRelRecordSet);
	FREE_ME(rTxnRelRecordSet);

DEBUGLOG(("Authorize() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;
}

int ProcessMerchTxn(hash_t *hMerchTxnRec) 
{
	int	iRet = PD_OK;	

	int	iTmp = 0;	
	double	dTxnAmt = 0.0;
	double	dTmp = 0.0;	
	char	cType;
	char	cPartyType;
	char	cDCInd;
	char	*csMerchantId = NULL;
	char	*csServiceCode = NULL;
	char	*csTxnCountry = NULL;
	char	*csTxnCcy = NULL;
	char	*csDate = NULL;
	char	*csUser = NULL;
	char	*csResponseCode = (char*) malloc (128);
	char 	*csTmp = NULL;
	char    csTxnSeq[PD_TXN_SEQ_LEN + 1];

	hash_t  *hTxnRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxnRequest,0);

        hash_t  *hTxnContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxnContext,0);	

/* type */
	if (GetField_Char(hMerchTxnRec,"type",&cType)) {
DEBUGLOG(("ProcessMerchTxn::() type = [%c]\n",cType));
        }

/* ip_addr */
        if (GetField_CString(hMerchTxnRec,"ip_addr",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn::() ip_addr = [%s]\n",csTmp));
		PutField_CString(hTxnRequest,"ip_addr",csTmp);
        }

/* PHDATE */
        if (GetField_CString(hMerchTxnRec,"PHDATE",&csDate)) {
DEBUGLOG(("ProcessMerchTxn::() PHDATE = [%s]\n",csDate));
		PutField_CString(hTxnContext,"PHDATE",csDate);	
        }

/* local_tm_date */
	if (GetField_CString(hMerchTxnRec,"local_tm_date",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn::() local_tm_date = [%s]\n",csTmp));
                PutField_CString(hTxnContext,"local_tm_date",csTmp);
        }

/* local_tm_time */
        if (GetField_CString(hMerchTxnRec,"local_tm_time",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn::() local_tm_time = [%s]\n",csTmp));
                PutField_CString(hTxnContext,"local_tm_time",csTmp);
        }

/* transmission_datetime */
        if (GetField_CString(hMerchTxnRec,"transmission_datetime",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn::() transmission_datetime = [%s]\n",csTmp));
                PutField_CString(hTxnContext,"transmission_datetime",csTmp);
        }

/* party_type */
	if (GetField_Char(hMerchTxnRec,"party_type",&cPartyType)) {
DEBUGLOG(("ProcessMerchTxn::() party_type = [%c]\n",cPartyType));
		PutField_Char(hTxnContext,"party_type",cPartyType);
        } else {
                iRet = INT_PARTY_TYPE_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() party_type not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() party_type not found\n");
        }

/* merchant_id */
        if (GetField_CString(hMerchTxnRec,"merchant_id",&csMerchantId)) {
DEBUGLOG(("ProcessMerchTxn::() merchant_id = [%s]\n",csMerchantId));
		PutField_CString(hTxnRequest,"merchant_id",csMerchantId);
		PutField_CString(hTxnContext,"merchant_id",csMerchantId);
        } else {
                iRet = INT_MERCHANT_ID_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() merchant_id not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() merchant_id not found\n");
        }

/* dc_ind */
	if (GetField_Char(hMerchTxnRec, "dc_ind", &cDCInd)) {
DEBUGLOG(("ProcessMerchTxn::() dc_ind = [%c]\n", cDCInd));
		PutField_Char(hTxnContext,"dc_ind",cDCInd);
        } else {
            	iRet = INT_DC_IND_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() dc_ind not found\n"));
ERRLOG("TxnOmtByUsOEA::ProcessMerchTxn::dc_ind not found\n");
     	}

/* service */
        if (GetField_CString(hMerchTxnRec,"service",&csServiceCode)) {
DEBUGLOG(("ProcessMerchTxn::() service = [%s]\n",csServiceCode));
		PutField_CString(hTxnRequest,"service_code",csServiceCode);
		PutField_CString(hTxnContext,"service_code",csServiceCode);
        } else {
                iRet = INT_SERVICE_CODE_MISSING;
DEBUGLOG(("ProcessMerchTxn::() service not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() service not found\n");
        }

/* txn_country */
        if (GetField_CString(hMerchTxnRec,"txn_country",&csTxnCountry)) {
DEBUGLOG(("ProcessMerchTxn::() txn_country = [%s]\n",csTxnCountry));
		PutField_CString(hTxnRequest,"txn_country",csTxnCountry);
		PutField_CString(hTxnContext,"txn_country",csTxnCountry);
        } else {
                iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() txn_country not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() txn_country not found\n");
        }

/* txn_ccy */
        if (GetField_CString(hMerchTxnRec,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("ProcessMerchTxn::() txn_ccy = [%s]\n",csTxnCcy));
		PutField_CString(hTxnRequest,"txn_ccy",csTxnCcy);
		PutField_CString(hTxnContext,"txn_ccy",csTxnCcy);
		PutField_CString(hTxnContext,"net_ccy",csTxnCcy);
        } else {
                iRet = INT_CURRENCY_CODE_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() txn_ccy not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() txn_ccy not found\n");
        }

/* txn_amt */
        if (GetField_Double(hMerchTxnRec,"txn_amt",&dTxnAmt)) {
DEBUGLOG(("ProcessMerchTxn::() txn_amt = [%f]\n",dTxnAmt));

		if (dTxnAmt <= 0) {
                	iRet = INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("ProcessMerchTxn::() txn_amt is invalid\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() txn_amt is invalid\n");
        	} else {
			PutField_Double(hTxnContext, "txn_amt", dTxnAmt);
			PutField_Double(hTxnContext, "net_amt", dTxnAmt);
		}	
        } else {
                iRet = INT_PAY_AMOUNT_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() txn_amt not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() txn_amt not found\n");
        }

/* remark */
        if (GetField_CString(hMerchTxnRec,"remark",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn::() remark = [%s]\n",csTmp));
		PutField_CString(hTxnRequest,"remark",csTmp);
		PutField_CString(hTxnContext,"remark",csTmp);
        } else {
                iRet = INT_REMARK_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() remark not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() remark not found\n");
        }

/* add_user */
        if (GetField_CString(hMerchTxnRec,"add_user",&csUser)) {
DEBUGLOG(("ProcessMerchTxn::() user = [%s]\n",csUser));
		PutField_CString(hTxnRequest,"add_user",csUser);
		PutField_CString(hTxnRequest,"update_user",csUser);
		PutField_CString(hTxnContext,"add_user",csUser);
		PutField_CString(hTxnContext,"update_user",csUser);
        } else {
                iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("ProcessMerchTxn::() user not found\n"));
ERRLOG("TxnOmtByUsOEA:ProcessMerchTxn() user not found\n");
        }

	// Generate OL Next Txn Seq
        if (iRet == PD_OK) {
DEBUGLOG(("ProcessMerchTxn:: Call DBOLTxnSeq: GetNextOmtTxnSeq\n"));
                DBObjPtr = CreateObj(DBPtr, "DBOLTxnSeq", "GetNextOmtTxnSeq");
                strcpy((char*)csTxnSeq, (*DBObjPtr)());

                PutField_CString(hMerchTxnRec, "merch_txn_id", (const char *)csTxnSeq);
DEBUGLOG(("ProcessMerchTxn:: Call DBTxnSeq: txn_seq = [%s]\n", csTxnSeq));
        }

	// Get Merchant Txn Info
	if (iRet == PD_OK) {
DEBUGLOG(("ProcessMerchTxn:: Call BOOLMerchant->GetMerchantTxnInfo to merchant\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetMerchantTxnInfo");
                iRet = (unsigned long)(*BOObjPtr)(hTxnContext,hTxnRequest);
		if (iRet == PD_OK) {

/* client_id */
			if (GetField_CString(hTxnContext,"merchant_client_id",&csTmp)) {
DEBUGLOG(("ProcessMerchTxn:: merchant_client_id = [%s]\n",csTmp));
				PutField_CString(hTxnRequest,"client_id",csTmp);
			}
		} else {
			iRet = INT_ERR;
DEBUGLOG(("ProcessMerchTxn:: Call BOOLMerchant->GetMerchantTxnInfo for To Merchant Failed\n"));
		}
	}
	
	// Add OL Txn Log
	if (iRet == PD_OK) {

		// do_logging
		PutField_Int(hTxnContext,"do_logging",PD_TRUE);	
	
		// db_commit
		PutField_Int(hTxnContext,"db_commit",PD_FALSE);

		// txn_seq 
		PutField_CString(hTxnContext,"txn_seq",(const char*)csTxnSeq);

		// channel_code
		PutField_CString(hTxnContext, "channel_code", PD_CHANNEL_OMT);
		
		// status
		PutField_Char(hTxnContext,"status",PD_PROCESSING);

		// txn_code
		if (cType == PD_MERCH_PSP_BATCH_TYPE) {
			if (cDCInd == PD_IND_CREDIT) {
				PutField_CString(hTxnContext, "txn_code", PD_OFL_ERROR_ADJUSTMENT_CR);
			} else if (cDCInd == PD_IND_DEBIT) {
                                PutField_CString(hTxnContext, "txn_code", PD_OFL_ERROR_ADJUSTMENT_DR);
			}
		}

		// process_code
		PutField_CString(hTxnContext,"process_code", PD_PROCESS_CODE_DEF);

		// process_type
		PutField_CString(hTxnContext,"process_type", PD_PROCESS_TYPE_DEF);

		// internal_code
		PutField_Int(hTxnContext, "internal_code", 0);

		// ex_supplier
                PutField_Char(hTxnContext,"ex_supplier",PD_INT_EX);		

		// ex_rate
		PutField_Double(hTxnContext,"ex_rate",1);

DEBUGLOG(("ProcessMerchTxn:: Call OMTChannel: AddTxnLog\n"));
                ChannelObjPtr = CreateObj(ChannelPtr,"OMTChannel","AddTxnLog");
                iRet = (unsigned long)(*ChannelObjPtr)(hTxnContext,hTxnRequest);
                if (iRet != PD_OK) {
DEBUGLOG(("ProcessMerchTxn:: Call MGTChannel: AddTxnLog Failed\n"));
                        iRet = INT_ERR;
                }
	}
	
	// Update OL Merchant Balance (Available for Payout)
	if (iRet == PD_OK) {

		// Process Available for Payout Balance
		PutField_CString(hTxnContext, "from_txn_seq", csTxnSeq);
                PutField_CString(hTxnContext, "org_txn_ccy", csTxnCcy);
                PutField_Double(hTxnContext, "org_txn_amt", dTxnAmt);

DEBUGLOG(("ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout()\n"));
              	BOObjPtr = CreateObj(BOPtr, "BOOLBalance", "ProcessAvaPayout");
              	if ((unsigned long)(*BOObjPtr)(hTxnContext) != PD_OK) {
                   	iRet = INT_ERR;
DEBUGLOG(("ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout() failed\n"));
ERRLOG("TxnOmtByUsOEA:: ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout() failed\n");		
		} else {

/* merchant_open_bal */
			if (GetField_Double(hTxnContext,"merchant_open_bal",&dTmp)) {
DEBUGLOG(("ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout() merchant_open_bal [%f]\n", dTmp));
				PutField_Double(hTxnContext, "open_bal", dTmp);
                        }

/* merchant_open_bal_settlement */
                        if (GetField_Double(hTxnContext,"merchant_open_bal_settlement",&dTmp)) {
DEBUGLOG(("ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout() merchant_open_bal_settlement [%f]\n", dTmp));
				PutField_Double(hTxnContext, "open_bal_settlement", dTmp);
                        }

/* approval_date */
			if (GetField_CString(hTxnContext,"approval_date",&csTmp)) {	
DEBUGLOG(("ProcessMerchTxn:: Call BOOLBalance::ProcessAvaPayout() approval_date [%s]\n", csTmp));
			}
		}
	}	
	
	// Update OL Txn Detail
	if (iRet == PD_OK) {
	
		// txn_country
           	//PutField_CString(hTxnContext, "txn_country", csTxnCountry);

		if(GetField_Int(hTxnContext,"do_logging",&iTmp)) {
DEBUGLOG(("ProcessMerchTxn::do_logging [%d]\n", iTmp));

			if (iTmp != PD_ADD_LOG) {
				/* do nothing */
			} else {
				
				// Update TxnDetail
				if (iRet == PD_OK) {

DEBUGLOG(("ProcessMerchTxn::Call DBOLTransaction:: Update\n"));
                                        DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","UpdateDetail");
                                        iRet = (unsigned long)(*DBObjPtr)(hTxnContext);
                                        if (iRet != PD_OK) {
DEBUGLOG(("ProcessMerchTxn::Call DBOLTransaction:: Update Failed\n"));
                                                iRet = INT_ERR;
                                        }
                                }	
			}
		}
	}

	// Update OL Txn Header
	if (iRet == PD_OK) {

/* status */
                PutField_Char(hTxnContext,"status",PD_COMPLETE);
DEBUGLOG(("ProcessMerchTxn::status [%c]\n", PD_COMPLETE));

/* ar_ind */
                PutField_Char(hTxnContext,"ar_ind",PD_ACCEPT);
DEBUGLOG(("ProcessMerchTxn::ar_ind [%c]\n", PD_ACCEPT));

/* sub_status */
                PutField_CString(hTxnContext,"sub_status",PD_APPROVED);
DEBUGLOG(("ProcessMerchTxn::sub_status [%s]\n", PD_APPROVED));

/* approval_date */
               	//PutField_CString(hTxnContext, "approval_date", csDate);
//DEBUGLOG(("ProcessMerchTxn::approval_date [%s]\n", csDate));

/* approval_timestamp */
                //PutField_CString(hTxnContext, "approval_timestamp", csApprovalTimestamp);
//DEBUGLOG(("ProcessMerchTxn::approval_timestamp [%s]\n", csApprovalTimestamp));

/* response_code */
		sprintf(csResponseCode,"%d",iRet);
		PutField_CString(hTxnContext,"response_code",csResponseCode);
DEBUGLOG(("ProcessMerchTxn::response_code [%s]\n", csResponseCode));

/* do_logging */
                PutField_Int(hTxnContext, "do_logging", PD_FALSE);
DEBUGLOG(("ProcessMerchTxn:: do_logging [%d]\n", PD_FALSE));

DEBUGLOG(("ProcessMerchTxn::Call DBOLTransaction: Update \n"));
                DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Update");
                iRet = (unsigned long)(*DBObjPtr)(hTxnContext);
                if (iRet != PD_OK) {
                        iRet = INT_ERR;
DEBUGLOG(("ProcessMerchTxn::Call DBOLTransaction:: Update Failed\n"));
                }	
	}

	FREE_ME(csResponseCode);
	
	hash_destroy(hTxnRequest);
        FREE_ME(hTxnRequest);

	hash_destroy(hTxnContext);
       	FREE_ME(hTxnContext);
	
DEBUGLOG(("ProcessMerchTxn() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;
}

