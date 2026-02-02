/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/09		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnWebByUsMAQ.h"
#include "myrecordset.h"
#include "dbutility.h"

char cDebug;

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

void TxnWebByUsMAQ(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iChk = PD_OK;
        int     iApproveId=0;
        int     iSeqNum=0;
	//char	csCmd[PD_MAX_FILE_LEN + 1];
	char	csDateTime[PD_DATETIME_LEN + 1];
	char	csDate[PD_DATE_LEN + 1];
	char	csTime[PD_TIME_LEN + 1];

	char    *csTmp;
	char    *csBatchId;
	//char    *csPspId;
	double	dTmp = 0.0;
	double	dAmt = 0.0;
	
	hash_t	*hRec;
	hash_t	*hDtl;
	hash_t  *hUpd;

        hUpd = (hash_t*) malloc (sizeof(hash_t));	
	
	recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);
	recordset_t     *rDtlSet;
        rDtlSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rDtlSet,0);

	PutField_CString(hContext,"txn_code",PD_PAYOUT_APPROVE);
	PutField_CString(hContext,"channel_code",PD_CHANNEL_MGT);

	DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueHd","GetWaitingApproveHd");
        if ((*DBObjPtr)(PD_INIT,rRecordSet) == PD_OK) {
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_Int(hRec,"approve_id",&iApproveId)){
DEBUGLOG(("TxnWebByUsMAQ approve_id = [%d]\n",iApproveId));
				hash_init(hUpd,0);
				PutField_Char(hUpd,"status",PD_PROCESSING);
				PutField_Int(hUpd,"approve_id",iApproveId);

				DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueHd","UpdateStatus");
				if ((*DBObjPtr)(hUpd) == PD_OK) {

					if(GetField_CString(hRec,"posting_date",&csTmp)){
						PutField_CString(hContext,"approval_date",csTmp);
						PutField_CString(hContext,"posting_date",csTmp);
						PutField_CString(hContext,"PHDATE",csTmp);
					}
					if(GetField_CString(hRec,"service_code",&csTmp)){
						PutField_CString(hContext,"service_code",csTmp);
						PutField_CString(hRequest,"service_code",csTmp);
					}
					if(GetField_CString(hRec,"merchant_id",&csTmp)){
						PutField_CString(hContext,"merchant_id",csTmp);
						PutField_CString(hRequest,"merchant_id",csTmp);
					}
					if(GetField_CString(hRec,"client_id",&csTmp)){
						PutField_CString(hRequest,"client_id",csTmp);
						PutField_CString(hContext,"merchant_client_id",csTmp);
					}
					if(GetField_CString(hRec,"txn_ccy",&csTmp)){
						PutField_CString(hContext,"net_ccy",csTmp);
						PutField_CString(hContext,"txn_ccy",csTmp);
						PutField_CString(hRequest,"txn_ccy",csTmp);
					}
					if(GetField_CString(hRec,"txn_country",&csTmp)){
						PutField_CString(hContext,"txn_country",csTmp);
						PutField_CString(hRequest,"txn_country",csTmp);
					}
					if(GetField_Double(hRec,"total_req_amt",&dTmp)){
						PutField_Double(hContext,"total_net_amt",dTmp);
					}
					if(GetField_CString(hRec,"add_user",&csTmp)){
						PutField_CString(hContext,"add_user",csTmp);
					}

					/////Check aval balance
DEBUGLOG(("TxnWebByUsMAQ::call BOPayout->CheckAvalBalance\n"));
					BOObjPtr = CreateObj(BOPtr,"BOPayout","CheckAvalBalance");
					iChk = (unsigned long)(*BOObjPtr)(hContext,hRequest);
					if(iChk==PD_OK){
						if(GetField_Double(hContext,"merchant_net_float",&dTmp)){
							PutField_Double(hContext,"remain_merchant_net_float",dTmp);
DEBUGLOG(("TxnWebByUsMAQ::merchant_net_float = [%lf]\n",dTmp));
						}
						if(GetField_Double(hContext,"merchant_reserved_po",&dTmp)){
							PutField_Double(hContext,"remain_merchant_reserved_po",dTmp);
DEBUGLOG(("TxnWebByUsMAQ::merchant_reserved_po = [%lf]\n",dTmp));
						}
						if(GetField_Double(hContext,"merchant_fundin_po",&dTmp)){
DEBUGLOG(("TxnWebByUsMAQ::merchant_fundin_po = [%lf]\n",dTmp));
						}
					}
					
					if(iChk==PD_OK){
						recordset_init(rDtlSet,0);
						DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueDt","GetWaitingApproveDt");
						if ((*DBObjPtr)(iApproveId,rDtlSet) == PD_OK) {
							hDtl = RecordSet_GetFirst(rDtlSet);
							while(hDtl){
								if(GetField_CString(hDtl,"batch_id",&csBatchId)){
									PutField_CString(hContext,"batch_id",csBatchId);
									PutField_CString(hUpd,"batch_id",csBatchId);
								}
								if(GetField_Int(hDtl,"seq_num",&iSeqNum)){
									PutField_Int(hContext,"seq_num",iSeqNum);
									PutField_Int(hUpd,"seq_num",iSeqNum);
								}
								if(GetField_CString(hDtl,"merchant_ref",&csTmp)){
									PutField_CString(hRequest,"merchant_ref",csTmp);
								}
								if(GetField_CString(hDtl,"payout_ccy",&csTmp)){
									PutField_CString(hRequest,"dst_txn_ccy",csTmp);
								}
								if(GetField_Double(hDtl,"request_amount",&dAmt)){
									PutField_Double(hRequest,"txn_amt",dAmt);
									PutField_Double(hUpd,"txn_amt",dAmt);
								}
								if(GetField_Double(hDtl,"payout_amount",&dTmp)){
									PutField_Double(hRequest,"payout_amount",dTmp);
								}
								if(GetField_CString(hDtl,"bank_name",&csTmp)){
									PutField_CString(hRequest,"bank_name",csTmp);
								}
								if(GetField_CString(hDtl,"bank_code",&csTmp)){
									PutField_CString(hRequest,"bank_code",csTmp);
								}
								if(GetField_CString(hDtl,"branch",&csTmp)){
									PutField_CString(hRequest,"branch",csTmp);
								}
								if(GetField_CString(hDtl,"account_id",&csTmp)){
									PutField_CString(hRequest,"account_id",csTmp);
								}
								if(GetField_CString(hDtl,"account_name",&csTmp)){
									PutField_CString(hRequest,"account_name",csTmp);
								}

								//get current datetime
								strcpy(csDateTime,getdatetime());
								sprintf(csDate,"%.*s",PD_DATE_LEN,csDateTime);
								sprintf(csTime,"%.*s",PD_TIME_LEN,&csDateTime[PD_DATE_LEN]);
								PutField_CString(hContext,"local_tm_date",csDate);
								PutField_CString(hContext,"local_tm_time",csTime);

								//Call TxnMgtByUsPOT
DEBUGLOG(("TxnWebByUsMAQ::call TxnMgtByUsPOT\n"));
								TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsPOT","Authorize");
								iChk = (unsigned long)(*TxnObjPtr)(hContext,hRequest,hResponse);

								if(iChk==PD_OK)
									PutField_Char(hUpd,"status",PD_ACCEPT);
								else
									PutField_Char(hUpd,"status",PD_REJECT);

								DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueDt","UpdateStatus");
								if ((*DBObjPtr)(hUpd) != PD_OK) {
DEBUGLOG(("TxnWebByUsMAQ DBMerchantApproveQueueDt:UpdateStatus[%d:%s:%d] Failed!!!\n",iApproveId,csBatchId,iSeqNum));
								}

								if(iChk==PD_OK){
									DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueHd","UpdateSuccCnt");
									if ((*DBObjPtr)(hUpd) != PD_OK) {
DEBUGLOG(("TxnWebByUsMAQ DBMerchantApproveQueueHd:UpdateSuccCnt[%d:%f] Failed!!!\n",iApproveId,dAmt));
									}
								}

								hDtl = RecordSet_GetNext(rDtlSet);
							}

						}
						TxnCommit();
						PutField_Char(hUpd,"status",PD_COMPLETE);
					}
					else
						PutField_Char(hUpd,"status",PD_REJECT);

					DBObjPtr = CreateObj(DBPtr,"DBMerchantApproveQueueHd","UpdateStatus");
					if ((*DBObjPtr)(hUpd) == PD_OK) {
DEBUGLOG(("TxnWebByUsMAQ DBMerchantApproveQueueHd:UpdateStatus[%d] Success\n",iApproveId));
					}
					else{
DEBUGLOG(("TxnWebByUsMAQ DBMerchantApproveQueueHd:UpdateStatus[%d] Failed!!!!\n",iApproveId));
					}
				}
				else{
					iRet = INT_ERR;
DEBUGLOG(("TxnWebByUsMAQ DBMerchantApproveQueueHd:UpdateStatus[%d] Failed!!!!!!!\n",iApproveId));
				}
				hash_destroy(hUpd);
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }


	FREE_ME(hUpd);
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
	RecordSet_Destroy(rDtlSet);
	FREE_ME(rDtlSet);
//DEBUGLOG(("TxnWebByUsMAQ Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
