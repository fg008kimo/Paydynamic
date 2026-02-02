/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/20              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebOnUsWTV.h"
#include "myrecordset.h"
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnWebOnUsWTV(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_OK;
	hash_t  *hOrgTxn,*hTxn,*hRec, *hIn;
	recordset_t     *rRecordSet;
	char	*csOrgTxnSeq;
	char	*csTxnSeq=strdup("");
	char	*csTmp;
	unsigned long lBatchId;
	double	dTmp;
	double	dOrgSrcAmt=0.0;
	int	iTmp;
	char	cTmp;
	int	iDayOfWeek = 0;

	hOrgTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hOrgTxn,0);

	hTxn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hIn = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hIn,0);


	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("TxnWebOnUsWTV:Authroize()\n"));
	if (GetField_CString(hRequest,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hOrgTxn,"txn_seq",csOrgTxnSeq);
		PutField_CString(hTxn,"org_txn_seq",csOrgTxnSeq);
		PutField_Int(hOrgTxn,"status",PAYOUT_MASTER_TRANSACTION_REVERSED);
	}

DEBUGLOG(("New Txn*************\n"));
	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        csTxnSeq[strlen(csTxnSeq)]='\0';
        PutField_CString(hTxn,"txn_seq",csTxnSeq);
        PutField_CString(hContext,"txn_seq",csTxnSeq);
	PutField_CString(hOrgTxn,"aux_txn_seq",csTxnSeq);
DEBUGLOG(("New Txn txn seq = [%s]\n",csTxnSeq));

	PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	PutField_CString(hContext,"add_user",PD_UPDATE_USER);
	PutField_CString(hContext,"update_user",PD_UPDATE_USER);

/*db_commit */
	PutField_Int(hTxn,"db_commit",PD_FALSE);

/* ar_id */
	PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
/* status */
	PutField_Char(hTxn,"status",PD_COMPLETE);

/* process type */
	PutField_CString(hTxn,"process_type","0200");

/* process code */
	PutField_CString(hTxn,"process_code","220008");

/* txn_code*/
	PutField_CString(hTxn,"txn_code",PD_WITHDRAW_VOID_TXN_CODE);
	PutField_CString(hContext,"txn_code",PD_WITHDRAW_VOID_TXN_CODE);

/*channel*/
	if(GetField_CString(hContext,"channel_code",&csTmp)){
		PutField_CString(hTxn,"channel_code",csTmp);
	}
	else{
		PutField_CString(hTxn,"channel_code","WEB");
	}

	if(GetField_CString(hContext,"ip_addr",&csTmp)){
		PutField_CString(hTxn,"ip_addr",csTmp);
	}

/* posting date */
	if (GetField_CString(hContext,"PHDATE",&csTmp)) {
DEBUGLOG(("host_posting_date = [%s]\n",csTmp));
        	PutField_CString(hTxn,"host_posting_date",csTmp);
        	PutField_CString(hTxn,"approval_date",csTmp);

		iDayOfWeek=day_of_week((const unsigned char*)csTmp);
DEBUGLOG(("Authorize::day_of_week= [%d]\n",iDayOfWeek));
                PutField_Int(hContext,"day_of_week",iDayOfWeek);
        }

/* local_tm_date */
	if (GetField_CString(hContext,"local_tm_date",&csTmp)) {
DEBUGLOG(("local_tm_date = [%s]\n",csTmp));
        	PutField_CString(hTxn,"local_tm_date",csTmp);
        }

/* local_tm_time */
	if (GetField_CString(hContext,"local_tm_time",&csTmp)) {
DEBUGLOG(("local_tm_time = [%s]\n",csTmp));
        	PutField_CString(hTxn,"local_tm_time",csTmp);
        }


//MerchantUploadFileDetail
DEBUGLOG(("Authorize::Call DBMerchantUploadFileDetail:GetDetailByTxnId\n"));
	DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","GetDetailByTxnId");
        if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
		hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
/* batch_id */
			if (GetField_CString(hRec,"batch_id",&csTmp)) {
				lBatchId = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("batch_id = [%ld]\n",lBatchId));
			}
/*psp_id*/
			if (GetField_CString(hRec,"psp_id",&csTmp)) {
DEBUGLOG(("psp_id = [%s]\n",csTmp));
				PutField_CString(hContext,"org_psp_id",csTmp);
			}
/*merchant_ref*/
			if (GetField_CString(hRec,"merchant_ref",&csTmp)) {
DEBUGLOG(("merchant_ref = [%s]\n",csTmp));
				PutField_CString(hTxn,"merchant_ref",csTmp);
			}
/*country*/
			if (GetField_CString(hRec,"txn_country",&csTmp)) {
DEBUGLOG(("txn_country = [%s]\n",csTmp));
				PutField_CString(hIn,"txn_country",csTmp);
				PutField_CString(hContext,"txn_country",csTmp);
				PutField_CString(hContext,"org_txn_country",csTmp);
			}
/*payout_ccy*/
			if (GetField_CString(hRec,"payout_ccy",&csTmp)) {
DEBUGLOG(("payout_ccy = [%s]\n",csTmp));
				PutField_CString(hIn,"txn_ccy",csTmp);
				PutField_CString(hContext,"txn_ccy",csTmp);
				PutField_CString(hContext,"org_txn_ccy",csTmp);
			}
/*request_ccy*/
			if (GetField_CString(hRec,"request_ccy",&csTmp)){
                                PutField_CString(hContext,"org_psp_txn_ccy",csTmp);
DEBUGLOG(("request_ccy= [%s]\n",csTmp));
                        }
/*payout_amount*/
			if (GetField_Double(hRec,"payout_amount",&dTmp)) {
DEBUGLOG(("payout_amount = [%f]\n",dTmp));
				dOrgSrcAmt = dTmp;
			}
/*request_amount*/
			if (GetField_Double(hRec,"request_amount",&dTmp)) {
DEBUGLOG(("request_amount = [%f]\n",dTmp));
				PutField_Double(hContext,"org_dst_net_amt",dTmp);
			}
/*member_fee*/
			if (GetField_Double(hRec,"member_fee",&dTmp)) {
DEBUGLOG(("member_fee = [%f]\n",dTmp));
			}
/*merchant_fee*/
			if (GetField_Double(hRec,"merchant_fee",&dTmp)) {
DEBUGLOG(("merchant_fee = [%f]\n",dTmp));
				dOrgSrcAmt += dTmp;
			}
/*markup_amt*/
			if (GetField_Double(hRec,"markup_amt",&dTmp)) {
DEBUGLOG(("markup_amt = [%f]\n",dTmp));
				dOrgSrcAmt += dTmp;
			}
/*service_fee
			if (GetField_Double(hRec,"service_fee",&dTmp)) {
DEBUGLOG(("service_fee = [%f]\n",dTmp));
				PutField_Double(hContext,"precal_fee",dTmp);
			}
			else{
DEBUGLOG(("Authorize::Call BOPsp CalPspFee\n"));
                		BOObjPtr = CreateObj(BOPtr,"BOPsp","CalPspFee");
                		iRet = (unsigned long)(*BOObjPtr)(hContext,hIn);
			}
*/
/*status*/
			if (GetField_Int(hRec,"status",&iTmp)) {
DEBUGLOG(("status = [%d]\n",iTmp));
				if(!(iTmp==PAYOUT_MASTER_TRANSACTION_TO_PSP ||
				   iTmp==PAYOUT_MASTER_TRANSACTION_ACCEPT)){
					iRet = INT_ERR;
DEBUGLOG(("Authorize::Invalid Status. Txn cannot be voided\n"));
				}
			}

			PutField_Double(hContext,"txn_amt",dOrgSrcAmt);
			PutField_Double(hTxn,"txn_amt",dOrgSrcAmt);

			hRec = RecordSet_GetNext(rRecordSet);
		}
        }
	RecordSet_Destroy(rRecordSet);

//MerchantUploadFileHeader
	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchantUploadFileHeader:GetHeader\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileHeader","GetHeader");
        	if ((*DBObjPtr)(lBatchId,rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
                	while (hRec) {
/* merchant_id */
				if (GetField_CString(hRec,"merchant_id",&csTmp)) {
DEBUGLOG(("merchant_id = [%s]\n",csTmp));
					PutField_CString(hIn,"merchant_id",csTmp);
					PutField_CString(hTxn,"merchant_id",csTmp);
					PutField_CString(hContext,"org_merchant_id",csTmp);
				}
/* service_code */
				if (GetField_CString(hRec,"service_code",&csTmp)) {
DEBUGLOG(("service_code = [%s]\n",csTmp));
					PutField_CString(hIn,"service_code",csTmp);
					PutField_CString(hTxn,"service_code",csTmp);
					PutField_CString(hContext,"org_service_code",csTmp);
				}
				hRec = RecordSet_GetNext(rRecordSet);
			}
        	}

	}
	RecordSet_Destroy(rRecordSet);

	if(!GetField_CString(hContext,"merchant_client_id",&csTmp)){
//////get merchant_client_id
DEBUGLOG(("Authorize::Call BOMerchant:GetMerchantDetail\n"));
                BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantDetail");
                if((unsigned long)(*BOObjPtr)(hContext,hIn)!=PD_OK){
                        iRet = INT_ERR;
		}
	}
	PutField_CString(hTxn,"client_id",csTmp);

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOExchange:GetExchangeInfo\n"));
                BOObjPtr = CreateObj(DBPtr,"BOExchange","GetExchangeInfo");
                if ((*BOObjPtr)(hContext,hIn) == PD_OK) {
                        if(GetField_Char(hContext,"ex_party",&cTmp)){
                                PutField_Char(hTxn,"ex_supplier",cTmp);
                        }
                        if(GetField_Double(hContext,"ex_rate",&dTmp)){
                                PutField_Double(hTxn,"ex_rate",dTmp);
                        }

                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::GetExchangeInfo Error\n"));
ERRLOG("TxnMgtOnUsWTV:Authorize::GetExchangeInfo Error\n");
                }
        }

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call BOFee:GetTxnFee\n"));
                BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
                if((unsigned long)(*BOObjPtr)(hContext,hIn)==PD_OK){
                        if(GetField_Double(hContext,"src_txn_fee",&dTmp)){
DEBUGLOG(("Authorize::void payout txn fee=[%f]\n",dTmp));
                        }
                        if(GetField_Double(hContext,"net_amt",&dTmp)){
DEBUGLOG(("Authorize::void payout net amt=[%f]\n",dTmp));
				PutField_Double(hContext,"org_net_amt",dTmp);
                        }
//                        if(GetField_Double(hContext,"dst_txn_amt",&dTmp)){
//DEBUGLOG(("Authorize::void payout dest net amt=[%f]\n",dTmp));
//				PutField_Double(hContext,"org_dst_net_amt",dTmp);
//                        }
                }
                else{
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::GetTxnFee Error\n"));
ERRLOG("TxnMgtOnUsWTV:Authorize::GetTxnFee Error\n");
                }
	}

	if (iRet == PD_OK) {
DEBUGLOG(("call BOBalance:UpdatePayoutResponse()\n"));
		PutField_Char(hContext,"response_mode",PD_REVERSED);

		BOObjPtr = CreateObj(BOPtr,"BOBalance","UpdatePayoutAmount");
		iRet = (unsigned long)(*BOObjPtr)(hContext);
		if(iRet !=PD_OK){
DEBUGLOG(("BOBalance:UpdatePayoutResponse() Failed\n"));
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBMerchantUploadFileDetail:UpdateDetailByTxnId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByTxnId");
                if ((*DBObjPtr)(csOrgTxnSeq,hOrgTxn) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("Authorize::DBMerchantUploadFileDetail:UpdateDetailByBatchId Failed\n"));
		}
	}

	if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call DBTransaction:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
                if((unsigned long)((*DBObjPtr)(hTxn))!=PD_OK){
			iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:Add Failed\n"));
		}
	}

	if(iRet == PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:AddDetail Failed\n"));
                }
        }

        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
                DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                        iRet = INT_ERR;
DEBUGLOG(("Authorize::DBTransaction:UpdateDetail Failed\n"));
                }
        }

//	iRet = PD_ERR;

	hash_destroy(hOrgTxn);
        FREE_ME(hOrgTxn);

	hash_destroy(hTxn);
        FREE_ME(hTxn);

	hash_destroy(hIn);
        FREE_ME(hIn);

	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

	FREE_ME(csTxnSeq);
DEBUGLOG(("Normal exit iRet = [%d]\n",iRet));	
	return iRet;
}

