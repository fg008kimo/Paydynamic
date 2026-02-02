/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/17              Cody Chan
To handle deposit_bank_code and bank_code
    on UpdateTxnLog                                2013/11/12              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsTSD.h"
#include "myrecordset.h"

char cDebug;
OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(CHANNEL);

void TxnOmtByUsTSD(char    cdebug)
{
        cDebug = cdebug;
}

int     UpdateTxnLog(const hash_t* hContext,
			const hash_t* hRequest,
			const hash_t* hResponse);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
        int     iResend = PD_FALSE;
	char*	csOrgTxnSeq;
	char*	csOrgTxnCountry;
	char*   csServiceCode;
	char*	csPtr;
	char*	csClientId;
	char	cPtr;
	char*	csOrgMerchantId;
	double	dTmp;
	char	csOrgDateTime[PD_DATETIME_LEN +1];
	char*	csBankAcctNum;
	char*	csBankCode;
	char*   csDepositBankCode;


	hash_t	*hRec;

	recordset_t     *rRecordSet;   



DEBUGLOG(("TxnOmtByUsTSD::Authroize()\n"));

	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnSeq)) {
DEBUGLOG(("TxnOmtByUsTSD::from txn seq  = [%s]\n",csOrgTxnSeq));
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);

		PutField_CString(hContext,"org_txn_seq", csOrgTxnSeq);
	}
	else if (GetField_CString(hRequest,"enc_txn_seq",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::org encrypted txn seq  = [%s]\n",csPtr));
		BOObjPtr = CreateObj(BOPtr,"BOSecurity","Decrypt3DESTxnSeq");
		char* csTmpBuf;
		csTmpBuf = (char*) malloc (PD_EN_TXN_SEQ_LEN +1);
                (BOObjPtr)(csPtr,csTmpBuf);
		csOrgTxnSeq = strdup(csTmpBuf);
DEBUGLOG(("TxnOmtByUsTSD:org txn seq = [%s]\n",csOrgTxnSeq));
		PutField_CString(hContext,"from_txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"txn_seq",csOrgTxnSeq);
		PutField_CString(hResponse,"enc_txn_seq",csPtr);
		FREE_ME(csTmpBuf);


		PutField_CString(hContext,"org_txn_seq", csOrgTxnSeq);
	}
	else {
DEBUGLOG(("TxnOmtByUsTSD::org txn seq not found\n"));
		iRet = INT_ORG_TXN_NOT_FOUND;
	}

	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","MatchRespTxnReadOnly");
                if((unsigned long)(*DBObjPtr)(csOrgTxnSeq,PD_TO_PSP)==PD_FOUND){
			iResend = PD_TRUE;
DEBUGLOG(("TxnOmtByUsTSD::transaction already 'Pending'\n"));
		}
	}


	if (iRet == PD_OK) {
		rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        	recordset_init(rRecordSet,0);
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnHeader");
                	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnOmtByUsTSD::found record = [%s]\n",csOrgTxnSeq));
                		hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {
                        		if (GetField_Char(hRec,"status",&cPtr)){
DEBUGLOG(("TxnOmtByUsTSD::status = [%c]\n",cPtr));
		
						if (cPtr == PD_COMPLETE || cPtr == PD_REVERSED) {
							iResend = PD_TRUE;
						}

                                	}
                                 	if (GetField_CString(hRec,"service_code",&csServiceCode)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - service_code = [%s]\n",csServiceCode));
                                 		PutField_CString(hResponse,"service_code",csServiceCode);
                                 		PutField_CString(hContext,"org_service_code",csServiceCode);
                                 	}
                                 	if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
                                 		PutField_CString(hResponse,"local_tm_date",csPtr);
                                 	}
				 	if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
                                       	 PutField_CString(hResponse,"local_tm_time",csPtr);
                                 	}
                                 	if (GetField_CString(hRec,"txn_code",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_txn_code = [%s]\n",csPtr));
                                 		PutField_CString(hResponse,"org_txn_code",csPtr);
                                 		PutField_CString(hContext,"org_txn_code",csPtr);
                                 	}
                                 	if (GetField_CString(hRec,"client_id",&csClientId)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_client_id = [%s]\n",csClientId));
                                 		PutField_CString(hContext,"merchant_client_id",csClientId);
                                 		PutField_CString(hContext,"org_client_id",csClientId);
                                 	}
                                 	if (GetField_CString(hRec,"merchant_id",&csOrgMerchantId)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_merchant_id = [%s]\n",csOrgMerchantId));
                                 		PutField_CString(hContext,"merchant_id",csOrgMerchantId);
                                 		PutField_CString(hContext,"org_merchant_id",csOrgMerchantId);
                                 	}
                                 	if (GetField_CString(hRec,"channel_code",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_channel_code = [%s]\n",csPtr));
                                 		PutField_CString(hContext,"org_channel_code",csPtr);
                                 	}
                                 	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_txn_amt = [%lf]\n",dTmp));
                                 		PutField_Double(hContext,"org_txn_amt",dTmp);
                                 		PutField_Double(hResponse,"txn_amt",dTmp);
                                 	}
                                 	if (GetField_CString(hRec,"local_tm_date",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - local_tm_date = [%s]\n",csPtr));
						strcpy(csOrgDateTime,csPtr);
                                 	}
                                 	if (GetField_CString(hRec,"local_tm_time",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - local_tm_time = [%s]\n",csPtr));
						memcpy(&csOrgDateTime[PD_DATE_LEN],csPtr,PD_TIME_LEN);
						csOrgDateTime[PD_DATETIME_LEN] = '\0';
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - org_local_tm_datetime = [%s]\n",csOrgDateTime));
                                 		PutField_CString(hContext,"org_local_tm_datetime",csOrgDateTime);
                                 	}
                                 	if (iResend == PD_TRUE && GetField_Double(hRec,"display_amt",&dTmp)) {
						PutField_Double(hResponse,"display_amt",dTmp);
DEBUGLOG(("TxnOmtByUsTSD::GetTxnHeader - display_amt = [%lf]\n",dTmp));
                                 	}

                           	     hRec = RecordSet_GetNext(rRecordSet);
                        	}
                 	}
		}
 		RecordSet_Destroy(rRecordSet);

		if (iRet == PD_OK) {
        		recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","GetTxnDetail");
                	if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("TxnOmtByUsTSD::txn detail found record = [%s]\n",csOrgTxnSeq));
                		hRec = RecordSet_GetFirst(rRecordSet);
                        	while (hRec) {

                                 	if (GetField_CString(hRec,"txn_country",&csOrgTxnCountry)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - org_txn_country = [%s]\n",csOrgTxnCountry));
						PutField_CString(hContext,"org_txn_country",csOrgTxnCountry);
                                 	}

                                 	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - org_txn_ccy = [%s]\n",csPtr));
                                 		PutField_CString(hContext,"txn_ccy",csPtr);
                                 		PutField_CString(hContext,"org_txn_ccy",csPtr);
                                 	}
                                 	if (GetField_CString(hRec,"failure_url",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - org_failure_url = [%s]\n",csPtr));
                                 		PutField_CString(hResponse,"failure_url",csPtr);
				 	}
                                 	if (GetField_CString(hRec,"success_url",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - org_success_url = [%s]\n",csPtr));
                                 		PutField_CString(hResponse,"success_url",csPtr);
				 	}
                                 	if (GetField_CString(hRec,"language",&csPtr)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - org_language = [%s]\n",csPtr));
                                 		PutField_CString(hResponse,"org_language",csPtr);
				 	}

					if(iResend==PD_TRUE){
						if (GetField_CString(hRec,"bank_code",&csBankCode)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - bank_code = [%s]\n",csBankCode));
                                 			PutField_CString(hResponse,"int_bank_code",csBankCode);
						}
						if (GetField_CString(hRec,"bank_acct_num",&csBankAcctNum)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - bank_acct_num = [%s]\n",csBankAcctNum));
                                 			PutField_CString(hResponse,"bank_acct_num",csBankAcctNum);
						}
						if (GetField_CString(hRec,"deposit_bank_code", &csDepositBankCode)) {
DEBUGLOG(("TxnOmtByUsTSD::GetTxnDetail - deposit_bank_code = [%s]\n",csDepositBankCode));
		
							//PutField_CString(hResponse,"deposit_bank",csDepositBankCode);
							PutField_CString(hContext,"resp_deposit_bank",csDepositBankCode);

						}
					}

                                	hRec = RecordSet_GetNext(rRecordSet);
                        	}
                 	}
		}
 		RecordSet_Destroy(rRecordSet);

		if (iRet == PD_OK) {
			recordset_init(rRecordSet,0);
			DBObjPtr = CreateObj(DBPtr,"DBOLTxnPspDetail","GetTxnPspDetail");
			if ((*DBObjPtr)(csOrgTxnSeq,rRecordSet) == PD_OK) {
DEBUGLOG(("GetOLTxnPspDetail::found record = [%s]\n",csOrgTxnSeq));
				hRec = RecordSet_GetFirst(rRecordSet);
				while (hRec) {
               	                 	if (GetField_CString(hRec,"txn_ccy",&csPtr)) {
DEBUGLOG(("GetOLTxnPspDetail::psp_txn_ccy = [%s]\n",csPtr));
                                        	PutField_CString(hContext,"dst_txn_ccy",csPtr);
                                	}
                                	if (GetField_Double(hRec,"txn_amt",&dTmp)) {
                                        	PutField_Double(hContext,"dst_net_amt",dTmp);
DEBUGLOG(("GetOLTxnPspDetail::psp_txn_amt = [%lf]\n",dTmp));
                                	}
					hRec = RecordSet_GetNext(rRecordSet);
                        	}
                	}
		}
 		RecordSet_Destroy(rRecordSet);


/* bank acct info */
		if ((iRet == PD_OK) && (iResend!=PD_TRUE))  {
			if (GetField_CString(hRequest, "int_bank_code", &csDepositBankCode)) {
				PutField_CString(hContext, "deposit_bank_code", csDepositBankCode);


				if (!strcmp(csDepositBankCode, PD_OTHER_BANK_CODE)) {
DEBUGLOG(("Authorize() call SystemParameter Other Bank\n"));
					char*   csValueTmp;
					csValueTmp = (char*) malloc (PD_SP_LONG_VALUE_LEN);

					DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
					if ((unsigned long)(DBObjPtr)(PD_OFL_PAYPAGE_OTHER_BANK, csValueTmp) == FOUND) {
						PutField_CString(hContext, "deposit_bank", csValueTmp);
					}

					FREE_ME(csValueTmp);

				} else {
					hash_t * hTxn;
					hTxn  = (hash_t*) malloc (sizeof(hash_t));
					hash_init(hTxn,0);

					DBObjPtr = CreateObj(DBPtr,"DBBankDesc","GetBankDetail");
DEBUGLOG(("Authorize() call DBBankDesc ::GetBankDetail()\n"));
					if ((unsigned long)(*DBObjPtr)(csDepositBankCode,hTxn) == PD_OK) {
						if (GetField_CString(hTxn, "bank_name", &csPtr)) {
DEBUGLOG(("Authorize() call DBBankDesc ::GetBankDetail() deposit_bank [%s]\n", csPtr));
							PutField_CString(hContext, "deposit_bank", csPtr);
						}

						if (GetField_CString(hTxn, "bank_url", &csPtr)) {
DEBUGLOG(("Authorize() call DBBankDesc ::GetBankDetail() deposit_bank_url [%s]\n", csPtr));
							PutField_CString(hResponse, "deposit_bank_url", csPtr);
						}
					}
					FREE_ME(hTxn);
				}

				
			}

			BOObjPtr = CreateObj(BOPtr,"BOOLMerchant","GetDepositBankAcct");
                	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
		}

/* UniqueNumber */
		if ((iRet == PD_OK) && (iResend!=PD_TRUE))  {
			BOObjPtr = CreateObj(BOPtr,"BOUniqueNumber","GetUniqueAmt");
                	iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
		}

		if((iRet == PD_OK) && (iResend==PD_TRUE)){
DEBUGLOG(("Authorize() call DBOLBankAccts::GetBankAccts()\n"));
			hash_t * hTxn;
			hTxn  = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hTxn,0);
			DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","GetBankAccts");
			if ((unsigned long)(*DBObjPtr)(csBankCode,csBankAcctNum,hTxn) == PD_OK) {
				if(GetField_CString(hTxn,"owner_name",&csPtr)){
					PutField_CString(hResponse,"owner_name",csPtr);
				}
				if(GetField_CString(hTxn,"branch_name",&csPtr)){
					PutField_CString(hResponse,"branch_name",csPtr);
				}
			}

			hash_destroy(hTxn);
			hash_init(hTxn, 0);

			DBObjPtr = CreateObj(DBPtr,"DBBankDesc","GetBankDetail");
			if ((unsigned long)(*DBObjPtr)(csDepositBankCode,hTxn) == PD_OK) {
				if (GetField_CString(hTxn, "bank_url", &csPtr)) {
					PutField_CString(hResponse, "deposit_bank_url", csPtr);
				}
			}

			FREE_ME(hTxn);
		}

	}

	if (iRet == PD_OK) {
		iRet = UpdateTxnLog(hContext,hRequest,hResponse);

		if (GetField_CString(hContext,"resp_deposit_bank", &csDepositBankCode)) {
			PutField_CString(hResponse,"deposit_bank",csDepositBankCode);
		}
	}
	else {
		PutField_Int(hContext,"internal_error",iRet);
	}

DEBUGLOG(("Normal exit iret = [%d]\n",iRet));	
	return iRet;
}

int     UpdateTxnLog(const hash_t* hContext,
			const hash_t* hRequest,
			const hash_t* hResponse)
{
        int iRet = PD_OK;
        hash_t  *hCon;
        char*   csTmp;
	double	dTmp;
	char	csDepositDateTime[PD_DATETIME_LEN +1];

        hCon = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hCon,0);

/* deposit_datetime */
	strcpy(csDepositDateTime,getdatetime());
        PutField_CString(hCon,"deposit_datetime",csDepositDateTime);


        PutField_CString(hCon,"add_user",PD_UPDATE_USER);

/* status */
	PutField_Char(hCon,"status",PD_TO_PSP);
 	//PutField_CString(hCon,"sub_status",PD_SENT_TO_PSP);

/* txn_seq  */
        if (GetField_CString(hContext,"from_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: txn_seq = [%s]\n",csTmp));
                PutField_CString(hCon,"txn_seq",csTmp);
        }
/* IP ADDR  */
        if (GetField_CString(hRequest,"ip_addr",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: ip_addr = [%s]\n",csTmp));
                PutField_CString(hCon,"ip_addr",csTmp);
        }

/*display_amount  */
        if (GetField_Double(hResponse,"display_amt",&dTmp)) {
DEBUGLOG(("UpdateTxnLog:: display_amount = [%lf]\n",dTmp));
                PutField_Double(hCon,"display_amt",dTmp);
		PutField_Double(hCon,"deposit_amt",dTmp);
        }

/* bank_code  */
	if (GetField_CString(hResponse, "int_bank_code", &csTmp)) {
DEBUGLOG(("UpdateTxnLog:: bank_code = [%s]\n",csTmp));
                PutField_CString(hCon,"bank_code",csTmp);
        } 

/* deposit_bank_code */
	if (GetField_CString(hContext, "deposit_bank_code", &csTmp)) {
DEBUGLOG(("UpdateTxnLog:: deposit_bank_code = [%s]\n",csTmp));
                PutField_CString(hCon,"deposit_bank_code",csTmp);
        }

/* deposit_bank  */
        if (GetField_CString(hResponse,"deposit_bank",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: deposit_bank = [%s]\n",csTmp));
                PutField_CString(hCon,"deposit_bank",csTmp);
        } else {
		if (GetField_CString(hContext, "deposit_bank", &csTmp)) {
DEBUGLOG(("UpdateTxnLog:: deposit_bank (org) = [%s]\n",csTmp));
			PutField_CString(hCon,"deposit_bank",csTmp);
		}
	}

/* bank_acct_num  */
        if (GetField_CString(hResponse,"bank_acct_num",&csTmp)) {
DEBUGLOG(("UpdateTxnLog:: bank_acct_num = [%s]\n",csTmp));
                PutField_CString(hCon,"bank_acct_num",csTmp);
        }

        DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Update");
        iRet = (unsigned long)(*DBObjPtr)(hCon);

	if (iRet == PD_OK) {
        	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","UpdateDetail");
        	iRet = (unsigned long)(*DBObjPtr)(hCon);
	}
	else {
DEBUGLOG(("UpdateTxnLog:: UpdateTxnHeader Failed\n"));
	}

        hash_destroy(hCon);
        FREE_ME(hCon);

        return iRet;
};

