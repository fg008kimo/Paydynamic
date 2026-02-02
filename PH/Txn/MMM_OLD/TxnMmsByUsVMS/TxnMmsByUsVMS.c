/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/20              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmsByUsVMS.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
#define	PD_RETRY	'R'

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
void TxnMmsByUsVMS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	csHostRef[PD_REMARK_LEN];
	char*	csTxnSeq;
	char*	csTxnCcy;
	char*	csOrgTxnCode;
	char*	csMerchantId;
	char*	csClientId;
	char*	csServiceCode;
	char*	csPspId;
	char*	csOrgTxnSeq;
	char*	csOrgDtlTxnSeq;
	char	cTmp;
	char	*csTmp = NULL;
	double	dAmt = 0.0;
	hash_t  *hRec;
	hash_t  *hOrgTxn, *hTxn, *hTmpReq, *hTmpCon;

	hOrgTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);
	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);
	hTmpReq= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTmpReq,0);
	hTmpCon= (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTmpCon,0);



	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


DEBUGLOG(("TxnMmsByUsVMS Authorize()\n"));

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
		PutField_CString(hTmpCon,"txn_seq",csTmp);
DEBUGLOG(("TxnMmsByUsVMS txn_seq = [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)){
		PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);
DEBUGLOG(("TxnMmsByUsVMS org_txn_seq = [%s]\n",csOrgTxnSeq));
	}
	else{
DEBUGLOG(("TxnMmsByUsVMS org_txn_seq is missing!!!!\n"));
		iRet = INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"org_dtl_txn_seq",&csOrgDtlTxnSeq)){
DEBUGLOG(("TxnMmsByUsVMS org_dtl_txn_seq = [%s]\n",csOrgDtlTxnSeq));
	}
	else{
		if (GetField_CString(hRequest, "host_dtl_ref", &csOrgDtlTxnSeq)) {
DEBUGLOG(("TxnMmsByUsVMS org_dtl_txn_seq (host_dtl_ref) = [%s]\n",csOrgDtlTxnSeq));
		} else {
DEBUGLOG(("TxnMmsByUsVMS org_dtl_txn_seq is missing!!!!\n"));
			iRet = INT_INVALID_TXN;
			PutField_Int(hContext,"internal_error",iRet);
		}
	}

	if (GetField_Char(hRequest, "isd_ind", &cTmp)) {
		PutField_Char(hTxn, "isd_ind", cTmp);
DEBUGLOG(("TxnMmsByUsVMS isd_ind = [%c]\n",cTmp));
	}
	else {
DEBUGLOG(("TxnMmsByUsVMS isd_ind is missing!!!!\n"));
		iRet = INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest, "add_user", &csTmp)) {
		PutField_CString(hTxn, "add_user", csTmp);
		PutField_CString(hTxn, "update_user", csTmp);
DEBUGLOG(("TxnMmsByUsVMS user = [%s]\n",csTmp));
	}
	else {
DEBUGLOG(("TxnMmsByUsVMS user set default [%s]\n", PD_UPDATE_USER));
		PutField_CString(hTxn, "add_user", PD_UPDATE_USER);
		PutField_CString(hTxn, "update_user", PD_UPDATE_USER);
	}




	if(iRet == PD_OK){
		sprintf(csHostRef,"%sm%s",csOrgTxnSeq,csOrgDtlTxnSeq);
//Find original txn
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetMmsDetail");
		if ((unsigned long)((*DBObjPtr)(csHostRef,rRecordSet)) != PD_FOUND) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_CString(hRec,"txn_seq",&csTxnSeq)){
					PutField_CString(hTmpCon,"org_txn_seq",csTxnSeq);
					PutField_CString(hTxn,"org_txn_seq",csTxnSeq);
					PutField_CString(hOrgTxn,"txn_seq",csTxnSeq);
DEBUGLOG(("GetMmsTxnDetail: txn_id[%s]\n",csTxnSeq));
				}
				if(GetField_CString(hRec,"txn_code",&csOrgTxnCode)){
					PutField_CString(hTmpReq,"org_txn_code",csOrgTxnCode);
DEBUGLOG(("GetMmsTxnDetail: txn_code[%s]\n",csOrgTxnCode));
				}
				if(GetField_CString(hRec,"merchant_id",&csMerchantId)){
					PutField_CString(hTxn,"merchant_id",csMerchantId);
					/*
					PutField_CString(hTxn,"src_party_type",PD_MMS_PARTY_MERCH);
					PutField_CString(hTxn,"dst_party_type",PD_MMS_PARTY_MERCH);
					*/
					PutField_CString(hTxn,"party_type",PD_MMS_PARTY_MERCH);
DEBUGLOG(("GetMmsTxnDetail: marchant_id[%s]\n",csMerchantId));
				}
				if(GetField_CString(hRec,"client_id",&csClientId)){
					PutField_CString(hTxn,"merchant_client_id",csClientId);
DEBUGLOG(("GetMmsTxnDetail: client_id[%s]\n",csClientId));
				}
				if(GetField_CString(hRec,"service_code",&csServiceCode)){
					PutField_CString(hTxn,"service_code",csServiceCode);
DEBUGLOG(("GetMmsTxnDetail: service_code[%s]\n",csServiceCode));
				}
				if(GetField_CString(hRec,"psp_id",&csPspId)){
					PutField_CString(hTxn,"psp_id",csPspId);
					/*
					PutField_CString(hTxn,"src_party_type",PD_MMS_PARTY_PSP);
					PutField_CString(hTxn,"dst_party_type",PD_MMS_PARTY_PSP);
					*/
					PutField_CString(hTxn,"party_type",PD_MMS_PARTY_PSP);
DEBUGLOG(("GetMmsTxnDetail: psp_id[%s]\n",csPspId));
				}
				if(GetField_CString(hRec,"txn_ccy",&csTxnCcy)){
					PutField_CString(hTxn,"txn_ccy",csTxnCcy);
DEBUGLOG(("GetMmsTxnDetail: txn_ccy[%s]\n",csTxnCcy));
				}

				if(GetField_Double(hRec,"txn_amt",&dAmt)){
					PutField_Double(hTxn,"txn_amt",dAmt);
DEBUGLOG(("GetMmsTxnDetail: txn_amt[%lf]\n",dAmt));
				}

				if(GetField_Char(hRec,"status",&cTmp)){
DEBUGLOG(("GetMmsTxnDetail: status[%c]\n",cTmp));
					if(cTmp!=PD_COMPLETE){
						iRet = INT_INVALID_TXN;
						PutField_Int(hContext,"internal_error",iRet);
					}
				}
				if(GetField_Char(hRec,"ar_ind",&cTmp)){
DEBUGLOG(("GetMmsTxnDetail: ar_ind[%c]\n",cTmp));
					if(cTmp!=PD_ACCEPT){
						iRet = INT_INVALID_TXN;
						PutField_Int(hContext,"internal_error",iRet);
					}
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

	}

	if(iRet==PD_OK){
		if(!strcmp(csOrgTxnCode,PD_TRAN_TO_PSP))
			PutField_CString(hContext,"txn_code",PD_REV_TRAN_TO_PSP);
		if(!strcmp(csOrgTxnCode,PD_TRAN_FROM_PSP))
			PutField_CString(hContext,"txn_code",PD_REV_TRAN_FROM_PSP);
		if(!strcmp(csOrgTxnCode,PD_TRAN_TO_MERCH))
			PutField_CString(hContext,"txn_code",PD_REV_TRAN_TO_MERCH);
		if(!strcmp(csOrgTxnCode,PD_TRAN_FROM_MERCH))
			PutField_CString(hContext,"txn_code",PD_REV_TRAN_FROM_MERCH);
	}

/*
	if(iRet==PD_OK){
//Find original txn
        	recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBMmsTransaction","GetMmsTxnDetail");
		if ((unsigned long)((*DBObjPtr)(csOrgTxnSeq,csOrgDtlTxnSeq,rRecordSet)) != PD_FOUND) {
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else{
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec) {
				if(GetField_Char(hRec,"isd_ind",&cTmp)){
					PutField_Char(hTxn,"isd_ind",cTmp);
DEBUGLOG(("GetMmsTxnDetail: isd_ind[%c]\n",cTmp));
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
		}

	}
*/

	if(iRet==PD_OK){
//reverse balance
		PutField_Int(hTxn, "void_flag", PD_TRUE);

		BOObjPtr = CreateObj(BOPtr,"BOMmsBalance","TxnTypeHandler");
                iRet = (unsigned long)((*BOObjPtr)(hTxn));


	}

	PutField_Int(hTxn,"input_txn_elements",PD_FALSE);

	if(iRet==PD_OK){
//Call TxnMgtByUsMML
		TxnObjPtr = CreateObj(TxnPtr, "TxnMgtByUsMML","Authorize");
		iRet = (unsigned long)(*TxnObjPtr)(hContext,hTxn,hResponse);
DEBUGLOG(("Call TxnMgtByUsMML iRet[%d]\n",iRet));
	}

	if(iRet==PD_OK){
		BOObjPtr = CreateObj(BOPtr,"BOTxnElements","VoidOrgTxnElements");
		iRet = (unsigned long)(*BOObjPtr)(hTmpCon,hTmpReq);
DEBUGLOG(("Call BOTxnElements:VoidOrgTxnElements iRet[%d]\n",iRet));
	}

	if(iRet==PD_OK){
		PutField_Char(hOrgTxn,"status",PD_REVERSING);
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		iRet = (unsigned long)(*DBObjPtr)(hOrgTxn);
DEBUGLOG(("Call DBTransaction:Update iRet[%d]\n",iRet));
	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(hTxn);
	FREE_ME(hOrgTxn);
	FREE_ME(hTmpReq);
	FREE_ME(hTmpCon);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnMmsByUsVMS Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
