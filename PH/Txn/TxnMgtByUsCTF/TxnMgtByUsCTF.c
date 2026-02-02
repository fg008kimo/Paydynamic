/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/17              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCTF.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"


char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Channel);

int	GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn, const hash_t *hReq);
int	UpdateHeaderLog(const hash_t *hContext, const hash_t *hRequest);


void TxnMgtByUsCTF(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp;

	char	*csTxnSeq;
	char	*csTxnSeqTo;
	char	cParty;
	int	iDoLog = 0;
	char	*csUser;

	hash_t	*hFrContext, *hToContext;
	
	hFrContext = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hFrContext, 0);
	
	hToContext = (hash_t*)malloc(sizeof(hash_t));
	hash_init(hToContext, 0);
	

DEBUGLOG(("Authorize::()\n"));

	if (GetField_CString(hRequest, "org_txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authorize:: txn_seq = [%s]\n", csTxnSeq));
		PutField_CString(hFrContext, "txn_seq", csTxnSeq);
	}
	else {
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_seq is missing\n"));
ERRLOG("TxnMgtByUsCTF:Authorize() txn seq is missing\n");
        }

	if (GetField_CString(hRequest, "org_txn_seq_to", &csTxnSeqTo)) {
DEBUGLOG(("Authorize:: txn_seq_to = [%s]\n", csTxnSeqTo));
		PutField_CString(hToContext, "txn_seq", csTxnSeqTo);

	}
	else {
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_seq_to is missing\n"));
ERRLOG("TxnMgtByUsCTF:Authorize() txn seq to is missing\n");
	}

	if (GetField_CString(hRequest, "party", &csTmp)) {
DEBUGLOG(("Authorize:: party = [%s]\n", csTmp));
		cParty = csTmp[0];
		PutField_Char(hFrContext, "action_party", cParty);
		PutField_Char(hToContext, "action_party", cParty);
	} 

	if(GetField_CString(hRequest,"add_user",&csUser)){
		PutField_CString(hContext,"update_user",csUser);
DEBUGLOG(("Authorize::update_user= [%s]\n",csUser));

		PutField_CString(hFrContext, "update_user", csUser);
		PutField_CString(hToContext, "update_user", csUser);

	}


	// From GetTxnInfo
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::(FROM) GetTxnInfo\n"));
		iRet = GetTxnInfo((const unsigned char*) csTxnSeq, hFrContext, hRequest);

		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::GetTxnInfo (From party) Failed!\n"));
		}  else {
			if (GetField_CString(hFrContext, "txn_code", &csTmp)) {
				if (strcmp(csTmp, PD_AVA_PAYOUT_REQ_TF_FROM))  {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_code [%s] is not expected\n", csTmp));
ERRLOG("TxnMgtByUsCTF:Authorize() txn code [%s] is not expected\n", csTmp);
				}
			}
		}
		
	}


	// To GetTxnInfo
	if (iRet == PD_OK) { 	
DEBUGLOG(("Authorize::(TO) GetTxnInfo\n"));
		iRet = GetTxnInfo((const unsigned char*) csTxnSeqTo, hToContext, hRequest);

		if (iRet != PD_OK) {
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::GetTxnInfo (To party) Failed!\n"));
		} else {
			if (GetField_CString(hFrContext, "txn_code", &csTmp)) {
				if (strcmp(csTmp, PD_AVA_PAYOUT_REQ_TF_TO))  {
					iRet = INT_INVALID_TXN;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() txn_code [%s] is not expected\n", csTmp));
ERRLOG("TxnMgtByUsCTF:Authorize() txn code [%s] is not expected\n", csTmp);
				}
			}
		}
	}


	// Chk the inputted txn_seq is a pair
	if (iRet == PD_OK) {
		if (GetField_CString(hToContext, "org_txn_id", &csTmp)) {
			if (strcmp(csTmp, csTxnSeq)) {
				iRet = INT_INVALID_TXN;
				PutField_Int(hContext, "internal_error", iRet);
DEBUGLOG(("Authorize::() the inputted seq is not in a pair\n"));
ERRLOG("TxnMgtByUsCTF:Authorize() the inpuuted seq is not in a pair\n");
			}
		}
		else {
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::() org_txn_id is missing on TO information\n"));
ERRLOG("TxnMgtByUsCTF:Authorize() org_txn_idis missing on TO information\n");
		}
	}

	// Logging
	if (iRet == PD_OK) {
		GetField_Int(hContext, "do_logging", &iDoLog);

		PutField_Int(hFrContext, "do_logging", iDoLog);
		PutField_Int(hToContext, "do_logging", iDoLog);
	}

/*
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::() Call UpdateHeaderLog (FROM)\n"));
		iRet = UpdateHeaderLog(hFrContext, hRequest);

		if (iRet != PD_OK) {
			iRet = INT_INVALID_TXN;
		}
	}
*/

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::() Call UpdateHeaderLog (TO)\n"));
		iRet = UpdateHeaderLog(hToContext, hRequest);

		if (iRet != PD_OK) {
			iRet = INT_INVALID_TXN;
		}
	}

	if (iRet == PD_OK) {
		PutField_CString(hContext, "txn_seq", csTxnSeq);

                if (GetField_Char(hFrContext, "action_party", &cParty)) {
                        if (cParty == PD_TYPE_MERCHANT) {
                                PutField_CString(hContext,"sub_status",PD_MERCHANT_CANCELLED);
                        } else {
                                PutField_CString(hContext,"sub_status",PD_ADMIN_CANCELLED);
                        }
                } else {
                        PutField_CString(hContext,"sub_status",PD_ADMIN_CANCELLED);
                }

		RemoveField_CString(hResponse, "org_txn_seq");
	}



	hash_destroy(hFrContext);
	FREE_ME(hFrContext);

	hash_destroy(hToContext);
	FREE_ME(hToContext);


DEBUGLOG(("TxnMgtByUsCTF Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}



int	GetTxnInfo(const unsigned char *csTxnSeq, hash_t *hTxn, const hash_t *hReq)
{
	int	iRet = PD_OK;
	
	char	*csTmp;
	char	cTmp;

	hash_t	*hRec;

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

	if (iRet == PD_OK) {
		recordset_init(rRecordSet,0);

DEBUGLOG(("GetTxnInfo::Call DBTransaction:GetTxnHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
		if ((*DBObjPtr)(csTxnSeq,rRecordSet) == PD_OK) {

DEBUGLOG(("GetTxnHeader::found record = [%s]\n",csTxnSeq));
                        hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_CString(hRec, "org_txn_id", &csTmp)) {
					PutField_CString(hTxn, "org_txn_id", csTmp);
DEBUGLOG(("GetTxnHeader::org_txn_id = [%s]\n",csTmp));
				}

                        	if (GetField_CString(hRec,"txn_code",&csTmp)) {
					PutField_CString(hTxn,"org_txn_code",csTmp);
DEBUGLOG(("GetTxnHeader::txn_code = [%s]\n",csTmp));
                        	}

				if (GetField_Char(hRec, "status", &cTmp)) {
DEBUGLOG(("GetTxnHeader::status = [%c]\n",cTmp));

					if (cTmp != PD_PROCESSING) {
						iRet = INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader::Invalid status[%c]\n",cTmp));
ERRLOG("TxnMgtByUsCTF:GetTxnHeader::Invalid status!!\n");
					} 
					else {
						if (GetField_Char(hRec, "ar_ind", &cTmp)) {
							iRet = INT_INVALID_TXN;
DEBUGLOG(("GetTxnHeader::Invalid ar_ind [%c]\n",cTmp));
ERRLOG("TxnMgtByUsCTF:GetTxnHeader::Invalid ar_ind!!\n");
						}
					}
				}		

				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		else {
DEBUGLOG(("GetTxnHeader:: not found record for [%s]\n",csTxnSeq));
ERRLOG("TxnMgtByUsCTF:Authorize::GetTxnHeader::not found record!!\n");
			iRet=INT_NOT_RECORD;
		}
                RecordSet_Destroy(rRecordSet);
	}


	return iRet;
}

int	UpdateHeaderLog(const hash_t *hContext, const hash_t *hRequest)
{
	int	iRet = PD_OK;

	int	iTmp = 0;
	char	*csTmp = NULL;
	char	cParty;

	hash_t  *hHeaderTxn;
	hHeaderTxn = (hash_t*)malloc(sizeof(hash_t));


	GetField_Int(hContext, "do_logging", &iTmp);

	if (iTmp != PD_NO_LOG) {
		hash_init(hHeaderTxn, 0);

		PutField_Int(hHeaderTxn, "do_logging", iTmp);

		if (GetField_CString(hContext, "txn_seq", &csTmp)) {
			PutField_CString(hHeaderTxn, "txn_seq", csTmp);
		}

		if (GetField_CString(hContext, "update_user", &csTmp)) {
                        PutField_CString(hHeaderTxn, "update_user", csTmp);
		}


		PutField_Char(hHeaderTxn, "status", PD_COMPLETE);

		if (GetField_Char(hContext, "action_party", &cParty)) {
			if (cParty == PD_TYPE_MERCHANT) {
				PutField_CString(hHeaderTxn,"sub_status",PD_MERCHANT_CANCELLED);
			} else {
				PutField_CString(hHeaderTxn,"sub_status",PD_ADMIN_CANCELLED);
			}
		} else {
			PutField_CString(hHeaderTxn,"sub_status",PD_ADMIN_CANCELLED);
		}

		PutField_Char(hHeaderTxn, "ar_ind", PD_REJECT);

		if (iRet == PD_OK) {
DEBUGLOG(("Authorize:UpdateHeaderLog:Call MGTChannel:UpdateTxnLog\n"));
			ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnLog");

			if ((unsigned long)((*ChannelObjPtr)(hHeaderTxn, hRequest, hHeaderTxn)) != PD_OK) {
DEBUGLOG(("Authorize:UpdateHeaderLog:Call MGTChannel:UpdateTxnLog FAILED\n"));
ERRLOG("TxnMgtByUsCTF:Authorize() UpdateHeaderLog Call MGTChannel:UpdateTxnLog FAILED\n");
				iRet = INT_ERR;
			}
		}
		hash_destroy(hHeaderTxn);
	}
	
	FREE_ME(hHeaderTxn);

	return iRet;
}
