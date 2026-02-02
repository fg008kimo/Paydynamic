/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Copy from TxnParOnUsDPTPend			   	   2012/12/05		   Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnParOnUsDPTPend.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(BO);

void TxnParOnUsDPTPend(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	int	iPayMethodFound = PD_FALSE;
	char*	csOrgTxnSeq;
	char*	csOrgTxnCountry;
	char*   csPspId;
	//char*   csPspChannel;
	char*   csServiceCode;
	char*	csPtr;
	char	*csClientId;
	char*	csTmp;
	char	cPtr;
	char*	csSelectedPayMethod;
	char*	csOrgMerchantId;
	double	dTmp;
	char	csOrgDateTime[PD_DATETIME_LEN +1];

	hash_t	*hRec;
	//hash_t  *hReq, *hRsp;

	recordset_t     *rRecordSet;   


DEBUGLOG(("TxnParOnUsDPTPend::Authroize()\n"));

	if (GetField_CString(hContext, "txn_seq", &csOrgTxnSeq)) {
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);
	} else {
DEBUGLOG(("TxnParOnUsDPTPend::org txn seq not found\n"));
	}

	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));

        recordset_init(rRecordSet,0);
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnParOnUsDPTPend::found record = [%s]\n",csOrgTxnSeq));
                	hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                        	if (GetField_Char(hRec,"status",&cPtr)){
DEBUGLOG(("TxnParOnUsDPTPend::status = [%c]\n",cPtr));
                                }
                                 if (GetField_CString(hRec,"service_code",&csServiceCode)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - service_code = [%s]\n",csServiceCode));
                                 	PutField_CString(hResponse,"service_code",csServiceCode);
                                 	PutField_CString(hContext,"org_service_code",csServiceCode);
                                 }
                                 if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
                                 	PutField_CString(hResponse,"local_tm_date",csPtr);
                                 }
				 if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
                                        PutField_CString(hResponse,"local_tm_time",csPtr);
                                 }
                                 if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_txn_code = [%s]\n",csPtr));
                                 	PutField_CString(hResponse,"org_txn_code",csPtr);
                                 	PutField_CString(hContext,"org_txn_code",csPtr);
                                 }
                                 if (GetField_CString(hRec,"client_id",&csClientId)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_client_id = [%s]\n",csClientId));
                                 	PutField_CString(hContext,"merchant_client_id",csClientId);
                                 	PutField_CString(hContext,"org_client_id",csClientId);
                                 }

                                 if (GetField_CString(hRec,"merchant_id",&csOrgMerchantId)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_merchant_id = [%s]\n",csOrgMerchantId));
                                 	PutField_CString(hContext,"merchant_id",csOrgMerchantId);
                                 	PutField_CString(hContext,"org_merchant_id",csOrgMerchantId);
                                 }
                                 if (GetField_CString(hRec,"channel_code",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_channel_code = [%s]\n",csPtr));
                                 	PutField_CString(hContext,"org_channel_code",csPtr);
                                 }

                                 if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_txn_amt = [%lf]\n",dTmp));
                                 	PutField_Double(hContext,"org_txn_amt",dTmp);
                                 }
                                 if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
					strcpy(csOrgDateTime,csPtr);
                                 }
                                 if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
					memcpy(&csOrgDateTime[PD_DATE_LEN],csPtr,PD_TIME_LEN);
					csOrgDateTime[PD_DATETIME_LEN] = '\0';
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnHeader - org_local_tm_datetime = [%s]\n",csOrgDateTime));
                                 	PutField_CString(hContext,"org_local_tm_datetime",csOrgDateTime);
                                 }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
                 }
	}
 	RecordSet_Destroy(rRecordSet);

	if (iRet == PD_OK) {
        	recordset_init(rRecordSet,0);
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnDetail");
                if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnParOnUsDPTPend::txn detail found record = [%s]\n",csOrgTxnSeq));
                	hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
                                 if (GetField_CString(hRec,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_pay_method = [%s]\n",csSelectedPayMethod));
                                 	PutField_CString(hContext,"selected_pay_method",csSelectedPayMethod);
					iPayMethodFound = PD_TRUE;
                                 }

                                 if (GetField_CString(hRec,"txn_country",&csOrgTxnCountry)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_txn_country = [%s]\n",csOrgTxnCountry));
					PutField_CString(hContext,"org_txn_country",csOrgTxnCountry);
                                 }

                                 if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_txn_ccy = [%s]\n",csPtr));
                                 	PutField_CString(hContext,"txn_ccy",csPtr);
                                 	PutField_CString(hContext,"org_txn_ccy",csPtr);
                                 }
                                 if (GetField_CString(hRec,"failure_url",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_failure_url = [%s]\n",csPtr));
                                 	PutField_CString(hResponse,"failure_url",csPtr);
				 }
                                 if (GetField_CString(hRec,"success_url",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_success_url = [%s]\n",csPtr));
                                 	PutField_CString(hResponse,"success_url",csPtr);
				 }
                                 if (GetField_CString(hRec,"language",&csPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend::GetTxnDetail - org_language = [%s]\n",csPtr));
                                 	PutField_CString(hResponse,"org_language",csPtr);
				 }

                                hRec = RecordSet_GetNext(rRecordSet);
                        }
		}
 		RecordSet_Destroy(rRecordSet);
	}

/* check paymethod */
	if (iRet == PD_OK) {
DEBUGLOG(("iPayMethodFound = [%d]\n",iPayMethodFound));
		if (!iPayMethodFound) {
			if(GetField_CString(hRequest,"selected_pay_method",&csSelectedPayMethod)){
				DBObjPtr = CreateObj(DBPtr,"DBServicePayMethod","IsServicePayMethodSupported");
				if ((unsigned long)(DBObjPtr)(csServiceCode,csSelectedPayMethod) == PD_TRUE) {
					PutField_CString(hContext,"selected_pay_method",csSelectedPayMethod);
				}
				else{
					iRet = INT_INVALID_PAY_AMOUNT;
DEBUGLOG(("TxnParOnUsDPTPend: pay_method invalid\n"));
ERRLOG(("TxnParOnUsDPTPend::Authorize() pay_method invalid\n"));
				}
			}
			else if (GetField_CString(hRequest,"selected_pay_method",&csSelectedPayMethod)) {
DEBUGLOG(("TxnParOnUsDPTPend: selected_pay_method from Selection Page = [%s]\n",csSelectedPayMethod));
				PutField_CString(hContext,"selected_pay_method",csSelectedPayMethod);
			}
			else{
				iRet = INT_PAYMETHOD_NOT_FOUND;
				PutField_Int(hContext,"internal_error",INT_PAYMETHOD_NOT_FOUND);
DEBUGLOG(("TxnParOnUsDPTPend: pay_method not found\n"));
ERRLOG(("TxnParOnUsDPTPend::Authorize() pay_method not found\n"));
			}
		}
	}


	if (iRet == PD_OK) {
        	recordset_init(rRecordSet,0);

		DBObjPtr = CreateObj(DBPtr,"DBClients","GetClients");
                if ((*DBObjPtr)(csClientId,rRecordSet) == PD_OK) {
                	hRec = RecordSet_GetFirst(rRecordSet);
                        while (hRec) {
				if (GetField_Char(hRec,"business_type",&cPtr)) {
DEBUGLOG(("TxnParOnUsDPTPend:: business_type [%c]\n",cPtr));
                                 	PutField_Char(hContext,"org_merchant_type",cPtr);
				}
                                hRec = RecordSet_GetNext(rRecordSet);
			}
		}
 		RecordSet_Destroy(rRecordSet);
	}

/* Add Txn Amt Element */
	if (iRet == PD_OK) {
DEBUGLOG(("TxnParOnUsDPTPend:: Try to Add\n"));
DEBUGLOG(("TxnParOnUsDPTPend:: Exectue\n"));
		 BOObjPtr = CreateObj(BOPtr,"BOTxnElements","AddTxnAmtElement");
                 iRet = (unsigned long)(*BOObjPtr)(hContext);
DEBUGLOG(("TxnParOnUsDPTPend:: ret from AddTxnAmtElements = [%d]\n",iRet));
	}


	if (iRet == PD_OK) {
		hash_t	*hPspDetail;

		// Org call TxnWebOnUsCOM.Authorize to get PSP

		if (GetField_CString(hContext, "psp_id", &csPspId)) {
DEBUGLOG(("TxnParOnUsDPTPend::psp_id [%s]\n", csPspId));
		}

		hPspDetail = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hPspDetail,0);

		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBPspDetail","GetPspDetail");
			if (!(*DBObjPtr)(csPspId, hPspDetail)) {
				if (GetField_CString(hPspDetail,"psp_name",&csTmp)) {
                                	PutField_CString(hContext,"psp_name",csTmp);
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail psp_name = [%s]\n",csTmp));
                        	}

				if (GetField_CString(hPspDetail,"psp_merchant_id",&csTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail psp_merchant id = [%s]\n",csPtr));
					PutField_CString(hContext,"psp_merchant_id",csTmp);
                        	}

				if (GetField_CString(hPspDetail,"client_id",&csTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail client id = [%s]\n",csTmp));
					PutField_CString(hContext,"psp_client_id",csTmp);
                        	}

				if (GetField_CString(hPspDetail, "psp_channel_code", &csTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail psp_channel_code = [%s]\n",csTmp));
					PutField_CString(hContext,"psp_channel_code",csTmp);
				}

				if (GetField_CString(hPspDetail, "ccy", &csTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail ccy = [%s]\n",csTmp));
					PutField_CString(hContext,"psp_ccy",csTmp);
					PutField_CString(hContext,"dst_txn_ccy",csTmp);
				}

				/*				
				if (GetField_CString(hPspDetail,"status",&csTmp)) {
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail status = [%s]\n",csTmp));
					if(strcmp(csTmp,PD_ACC_OPEN)){
DEBUGLOG(("TxnParOnUsDPTPend::PspDetail.GetPspDetail psp account [%s] not opened\n",csPspId));
						iRet = INT_ACCOUNT_DISABLED;
					}
                        	}
				*/
                	}
        	}
		hash_destroy(hPspDetail);
		FREE_ME(hPspDetail);
	}

	if (iRet == PD_OK) {
		PutField_Int(hContext,"init_mode",PD_TRUE);

		// Call BOExchange.GetExchangeInfo
DEBUGLOG(("TxnParOnUsDPTPend:: Call BOExchange.GetExchangeInfo\n"));
		BOObjPtr = CreateObj(BOPtr,"BOExchange","GetExchangeInfo");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnParOnUsDPTPend:: Call BOExchange.GetExchangeInfo = [%d]\n",iRet));
	}

	
	if (iRet == PD_OK) {
DEBUGLOG(("TxnParOnUsDPTPend:: Call BOFee.GetTxnFee\n"));
		BOObjPtr = CreateObj(BOPtr,"BOFee","GetTxnFee");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
DEBUGLOG(("TxnParOnUsDPTPend:: Call BOFee.GetTxnFee result = [%d]\n",iRet));
	}

 	RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);


DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}
