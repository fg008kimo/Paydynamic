/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/17              Cody Chan
/////Add to merchant_bucket 'RS'			   2012/11/05		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsRLR.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsRLR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
	int	iRet = PD_ERR;
	char	csTxnSeq[PD_TXN_SEQ_LEN +1];
	char	*csOrgTxnSeq;
	char	*csMerchantId;
	char	*csTxnCcy;
	char	*csTxnCountry;
	char	*csService;
	char	*csTmp;
	char	*csPostingDate;
	char	csDateTime[PD_DATETIME_LEN +1];
	char	csDate[PD_DATE_LEN +1];
	char	csTime[PD_TIME_LEN +1];
	double	dReserveAmt = 0.0;
	double	dBalance = 0.0;
	double	dTmp = 0.0;
	hash_t  *hRec,*hEle;
	recordset_t     *rRecordSet;

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
  	recordset_init(rRecordSet,0);

	hEle = (hash_t*)  malloc (sizeof(hash_t));

DEBUGLOG(("Authorize\n"));
	if (GetField_CString(hRequest,"txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("txn_seq = [%s]\n",csOrgTxnSeq));
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","MatchRespTxnStatus");
		if ((unsigned long)(*DBObjPtr)(csOrgTxnSeq,
				 PD_COMPLETE,
                                 PD_ACCEPT) == PD_FOUND) {
DEBUGLOG(("Found record\n"));
/* org txn id */
			PutField_CString(hContext,"org_txn_seq",csOrgTxnSeq);

			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
			if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
/* client id */
					if (GetField_CString(hRec,"client_id",&csTmp)) {
DEBUGLOG(("client_id = [%s]\n",csTmp));
						PutField_CString((hash_t*)hRequest,"client_id",csTmp);
					}
/* merchant id */
					if (GetField_CString(hRec,"merchant_id",&csMerchantId)) {
DEBUGLOG(("merchant id = [%s]\n",csMerchantId));
						PutField_CString((hash_t*)hRequest,"merchant_id",csMerchantId);
					}
/* merchant ref */
					if (GetField_CString(hRec,"merchant_ref",&csTmp)) {
DEBUGLOG(("merchant ref = [%s]\n",csTmp));
						PutField_CString((hash_t*)hRequest,"merchant_ref",csTmp);
					}
/* server_code */
					if (GetField_CString(hRec,"service_code",&csService)) {
DEBUGLOG(("service_code = [%s]\n",csService));
						PutField_CString((hash_t*)hRequest,"service_code",csService);
					}
/* net_ccy */
					if (GetField_CString(hRec,"net_ccy",&csTmp)) {
DEBUGLOG(("net_ccy = [%s]\n",csTmp));
						PutField_CString((hash_t*)hRequest,"net_ccy",csTmp);
					}
/* reserve amount */
					if (GetField_Double(hRec,"reserve_amt",&dReserveAmt)) {
DEBUGLOG(("reserve amount = [%f]\n",dReserveAmt));
						PutField_Double((hash_t*)hRequest,"reserve_amt",dReserveAmt);
					}
			 		hRec = RecordSet_GetNext(rRecordSet);
                		}
				iRet = PD_OK;
			}
			RecordSet_Destroy(rRecordSet);
  			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
			if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
/* txn country */
					if (GetField_CString(hRec,"txn_country",&csTxnCountry)) {
DEBUGLOG(("txn_country = [%s]\n",csTxnCountry));
						PutField_CString((hash_t*)hRequest,"txn_country",csTxnCountry);
					}
/* txn ccy */
					if (GetField_CString(hRec,"txn_ccy",&csTxnCcy)) {
DEBUGLOG(("txn_ccy = [%s]\n",csTxnCcy));
						PutField_CString((hash_t*)hRequest,"txn_ccy",csTxnCcy);
					}
					
			 		hRec = RecordSet_GetNext(rRecordSet);
				}
			}
			
/* new txn id */
			strcpy(csDateTime,getdatetime());
			memcpy(csDate,csDateTime,PD_DATE_LEN);
			csDate[PD_DATE_LEN] = '\0';
			memcpy(csTime,&csDateTime[PD_DATE_LEN],PD_TIME_LEN);
			csTime[PD_TIME_LEN] = '\0';
			PutField_CString(hContext,"transmission_datetime",csDateTime);
			PutField_CString(hContext,"local_tm_date",csDate);
			PutField_CString(hContext,"local_tm_time",csTime);


			DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextMgtTxnSeq");
        		strcpy(csTxnSeq,(*DBObjPtr)());
DEBUGLOG(("new txn id [%s]\n",csTxnSeq));
			PutField_CString(hContext,"txn_seq",csTxnSeq);

			ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","AddTxnLog");
        		iRet = (unsigned long)ChannelObjPtr(hContext,hRequest);

			if (iRet == PD_OK) {
				BOObjPtr = CreateObj(BOPtr,"BOBalance","GetTotalReverseForUpdate");
        			iRet = (unsigned long)BOObjPtr(hContext,csTxnCountry,csTxnCcy,csService,csMerchantId,&dBalance);
			}

/*
			if(iRet==PD_OK && dReserveAmt > 0){
				if (GetField_CString(hContext,"PHDATE",&csPostingDate)) {
DEBUGLOG(("posting date = [%s]\n",csPostingDate));
				}
				DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","CreditMerchantAmount");
				if ((*DBObjPtr)(csPostingDate,
							csMerchantId,
							csTxnCountry,
							csTxnCcy,
							csService,
							PD_DEFAULT_PSP,
							PD_BUCKET_TYPE_RESERVED,
							dReserveAmt,
							PD_UPDATE_USER) != PD_OK) {
					iRet = INT_ERR;
DEBUGLOG(("update merchant_bucket [reserve] Failed\n"));
				}
			}
*/

			if (iRet == PD_OK) {
DEBUGLOG(("total reserve amount = [%f]\n",dBalance));
				if (dBalance < dReserveAmt) {
					iRet = INT_INSUFFICIENT_FUND;
				}
				else {
					dBalance = dBalance - dReserveAmt;
DEBUGLOG(("new total reserve amount = [%f]\n",dBalance));
					BOObjPtr = CreateObj(BOPtr,"BOBalance","ReleaseMerchantResAmount");
        				iRet = (unsigned long)BOObjPtr(csMerchantId,csTxnCountry,csTxnCcy,csService,dReserveAmt);
				}
			}

			PutField_Int(hContext,"internal_code",iRet);
			PutField_Char(hContext,"status",PD_COMPLETE);
			if (iRet == PD_OK) {
				PutField_Char(hContext,"ar_ind",PD_ACCEPT);

				/***** update  Context for approval date and approval timestamp */
				DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
				(*DBObjPtr)(hContext);
DEBUGLOG(("SystemControl::GetApprovalDT called\n"));

				if (GetField_CString(hContext,"PHDATE",&csPostingDate)) {
DEBUGLOG(("posting date = [%s]\n",csPostingDate));
                                	//PutField_CString(hContext,"approval_date",csPostingDate);
				}
                               	PutField_CString(hContext,"sub_status",PD_APPROVED);

/* current bal */
				if (GetField_Double(hContext,"merchant_open_bal",&dTmp)) {
                        		PutField_Double(hContext,"current_bal",dTmp);
DEBUGLOG(("current_bal= [%f]\n",dTmp));
                		}
/* current bal settlement */
				if (GetField_Double(hContext,"merchant_open_bal_settlement",&dTmp)) {
                        		PutField_Double(hContext,"current_bal_settlement",dTmp);
DEBUGLOG(("current_bal_settlement= [%f]\n",dTmp));
                		}
/* total reserve amount */
                       		PutField_Double(hContext,"total_reserved_amount",dBalance);

/* Add Txn Element */
				hash_init(hEle,0);
DEBUGLOG(("txn seq = [%s]\n",csTxnSeq));
				PutField_CString(hEle,"txn_seq",csTxnSeq);

/* chg type */
                        	PutField_CString(hEle,"txn_element_type",PD_ELEMENT_RES_AMT);

/* party type */
                                PutField_Char(hEle,"party_type",PD_TYPE_MERCHANT);

/* txn_ccy */
                        	PutField_CString(hEle,"ccy",csTxnCcy);

/* amount */
                        	PutField_Double(hEle,"amount",dReserveAmt);

/* user */              	PutField_CString(hEle,"add_user",PD_UPDATE_USER);

/* amount type */
                                PutField_CString(hEle,"amount_type",PD_CR);


				DBObjPtr = CreateObj(DBPtr,"DBTxnElements","Add");
				iRet = (unsigned long)(*DBObjPtr)(hEle);
				hash_destroy(hEle);
			}
			else	
				 PutField_Char(hContext,"ar_ind",PD_REJECT);

			ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","UpdateTxnLog");
        		iRet = (unsigned long)ChannelObjPtr(hContext,hRequest);
			if (iRet == PD_OK) {
				ChannelObjPtr = CreateObj(ChannelPtr,"MGTChannel","UpdateTxnDetailLog");
        			iRet = (unsigned long)ChannelObjPtr(hContext,hRequest);
			}
			if (iRet == PD_OK) {
DEBUGLOG(("Try to update org txn's release reserve date\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateReleaseReserveDate");
        			iRet = (unsigned long)DBObjPtr(csOrgTxnSeq,csPostingDate,PD_RESERVE_RELEASED,PD_UPDATE_USER);
			}
		}
	}

	FREE_ME(hEle);
	RecordSet_Destroy(rRecordSet);
DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
}
