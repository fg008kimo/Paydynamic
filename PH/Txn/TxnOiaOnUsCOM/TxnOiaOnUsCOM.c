/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/11/21              LokMan Chow
Add checking
	- bank_acct_cnt
Add Error
	- REQ_DATETIME
	- BANK_CODE
	- ACCT_NUM				   2019/08/22		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOiaOnUsCOM.h"
#include "myrecordset.h"

static char cDebug;
OBJPTR(DB);
OBJPTR(BO);

#define MY_IND_NOTFOUND	1
#define MY_IND_INVALID	2

void TxnOiaOnUsCOM(char    cdebug)
{
        cDebug = cdebug;
}


int MapFieldErrCode(const char *csTag, const int iErrType);

int     Authorize(hash_t* hContext,
                        const hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;
	char	*csTxnCodePtr;
	char	*csChannelCodePtr;
	char	*csPtr;
	char	*csTag;

	int	iPtr = 0;
	int	iCnt = 0;

	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

	hash_t *hRec;

DEBUGLOG(("Authroize()\n"));


	if(GetField_CString(hContext,"txn_code",&csTxnCodePtr)){
DEBUGLOG((" txn_code [%s]\n",csTxnCodePtr));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" txn_code is missing!!\n"));
	}


	if(GetField_CString(hContext,"channel_code",&csChannelCodePtr)){
DEBUGLOG((" channel_code [%s]\n",csChannelCodePtr));
	}
	else{
		iRet = INT_ERR;
DEBUGLOG((" channel_code is missing!!\n"));
	}


	//TODO: check api version
	if (GetField_CString(hRequest, "version", &csPtr)) {
DEBUGLOG((" api version = [%s]\n", csPtr));
	}

	GetField_Int(hRequest,"p_list", &iCnt);
	if(iCnt > 0) PutField_Int(hResponse,"r_list", iCnt);

	if(iRet == PD_OK){

		int	i = 0;
		int	iChkMandatory = PD_TRUE;
		char	csListTag[PD_TAG_LEN +1];
		hash_t *hCheck;
		hCheck = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hCheck, 0);

		DBObjPtr = CreateObj(DBPtr,"DBTxnFieldCheck","FindParam");
		if((unsigned long)(DBObjPtr)(csChannelCodePtr, csTxnCodePtr, rRecordSet) == PD_OK) {
			hRec = RecordSet_GetFirst(rRecordSet);
			while (hRec && iRet == PD_OK) {

				hCheck = hRec;
				iChkMandatory = PD_TRUE;

				if(GetField_CString(hRec, "field_tag", &csTag)){

					if((!strcmp(csTag, "baid_cnt"))
					   || (!strcmp(csTag, "bank_acct_cnt"))
					)
					{
DEBUGLOG((" check %s\n", csTag));
						BOObjPtr = CreateObj(BOPtr,"BOCommChk","OiaRequest");
                                                if((unsigned long)(BOObjPtr)(hCheck, hContext) != PD_OK){
							iRet = INT_ERR;
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG((" %s invalid\n", csTag));
ERRLOG("TxnOiaOnUsCOM:Authorize() %s invalid\n", csTag);
                                                }
					} else {

						if(GetField_CString(hRequest, csTag, &csPtr)){
DEBUGLOG((" check %s:[%s]\n", csTag, csPtr));
							iChkMandatory = PD_FALSE;
							PutField_CString(hCheck, csTag, csPtr);

							if(!strcmp(csTag, "txn_amt")){
								if(GetField_CString(hRequest, "txn_ccy", &csPtr)){
									PutField_CString(hCheck, "ref_ccy", csPtr);
								}
							} 

							BOObjPtr = CreateObj(BOPtr,"BOCommChk","OiaRequest");
							if((unsigned long)(BOObjPtr)(hCheck, hContext) != PD_OK){
								iRet = MapFieldErrCode(csTag, MY_IND_INVALID);
								PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG((" %s invalid\n", csTag));
ERRLOG("TxnOiaOnUsCOM:Authorize() %s invalid\n", csTag);
							}
						}
						else{
							for(i = 0; i < iCnt; i++){
								sprintf(csListTag, "p_list.%d.%s", i, csTag);

								if (GetField_CString(hRequest, csListTag , &csPtr)) {
DEBUGLOG((" check %s:[%s]\n", csListTag, csPtr));
									iChkMandatory = PD_FALSE;
									PutField_CString(hCheck, csTag, csPtr);

									if(!strcmp(csTag, "txn_amt")){
										sprintf(csListTag, "p_list.%d.txn_ccy", i);

										if(GetField_CString(hRequest, "txn_ccy", &csPtr)){
											PutField_CString(hCheck, "ref_ccy", csPtr);
										}
										else if(GetField_CString(hRequest, csListTag, &csPtr)){
											PutField_CString(hCheck, "ref_ccy", csPtr);
										}
									}

									BOObjPtr = CreateObj(BOPtr,"BOCommChk","OiaRequest");
									if((unsigned long)(BOObjPtr)(hCheck, hContext)!= PD_OK){

										sprintf(csListTag, "r_list.%d.dt_err_code", i);
										if(!GetField_Int(hResponse, csListTag, &iPtr)){
											PutField_Int(hResponse, csListTag, MapFieldErrCode(csTag, MY_IND_INVALID));
DEBUGLOG((" [%s] check failed\n", csPtr));
										}
									}
								}
								else{
DEBUGLOG((" %s not found!\n", csListTag));
									iRet = INT_FORMAT_ERR;
									PutField_Int(hContext,"internal_error",iRet);
									iChkMandatory = PD_FALSE;
									break;
								}
							}
						}
					}

					if(iChkMandatory){
						iPtr = PD_FALSE;
						GetField_Int(hRec, "mandatory", &iPtr);
						if(iPtr == PD_TRUE){
							iRet = MapFieldErrCode(csTag, MY_IND_NOTFOUND);
							PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG((" %s not found\n", csTag));
ERRLOG("TxnOiaOnUsCOM:Authorize() %s not found\n", csTag);
						}
					}
				}


				hRec = RecordSet_GetNext(rRecordSet);
			}
		}
		hash_destroy(hCheck);
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("Authroize() iRet = [%d]\n",iRet));	
	return iRet;
}


int MapFieldErrCode(const char *csTag, const int iErrType)
{
	int iRet = PD_OK;

	if(iErrType == MY_IND_NOTFOUND){
		if(!strcmp(csTag, "baid"))
			iRet = INT_BANK_ACCT_ID_NOT_FOUND;
		else if(!strcmp(csTag, "to_baid"))
			iRet = INT_BANK_ACCT_ID_NOT_FOUND;
		else if(!strcmp(csTag, "req_ref"))
			iRet = INT_TXN_ID_NOT_FOUND;
		else if(!strcmp(csTag, "txn_ccy"))
			iRet = INT_CURRENCY_CODE_NOT_FOUND;
		else if(!strcmp(csTag, "txn_amt"))
			iRet = INT_PAY_AMOUNT_NOT_FOUND;
		else if(!strcmp(csTag, "bank_nature"))
			iRet = INT_NATURE_NOT_FOUND;
		else if(!strcmp(csTag, "rec_date"))
                        iRet = INT_SMS_CREATE_DATE_NOT_FOUND;
		else if(!strcmp(csTag, "auto_upload_ind"))
                        iRet = INT_AUTO_UPLOAD_IND_NOT_FOUND;
		else if(!strcmp(csTag, "bal_over_ind"))
                        iRet = INT_BAL_OVER_IND_NOT_FOUND;
		else if(!strcmp(csTag, "req_dt"))
                        iRet = INT_REQ_DATETIME_NOT_FOUND;
		else if(!strcmp(csTag, "bank_code"))
                        iRet = INT_BANK_CODE_NOT_FOUND;
		else if(!strcmp(csTag, "acct_num"))
                        iRet = INT_BANK_ACCT_NOT_FOUND;
		else
			iRet = INT_ERR;
	}
	else{
		if(!strcmp(csTag, "baid"))
			iRet = INT_INVALID_BAID;
		else if(!strcmp(csTag, "to_baid"))
			iRet = INT_INVALID_BAID;
		else if(!strcmp(csTag, "req_ref"))
			iRet = INT_INVALID_MERCHANT_REF;
		else if(!strcmp(csTag, "txn_ccy"))
			iRet = INT_INVALID_CURRENCY_CODE;
		else if(!strcmp(csTag, "txn_amt"))
			iRet = INT_INVALID_PAY_AMOUNT;
		else if(!strcmp(csTag, "bank_nature"))
			iRet = INT_INVALID_NATURE;
		else if(!strcmp(csTag, "rec_date"))
                        iRet = INT_INVALID_SMS_CREATE_DATE;
		else if(!strcmp(csTag, "auto_upload_ind"))
                        iRet = INT_INVALID_AUTO_UPLOAD_IND;
		else if(!strcmp(csTag, "bal_over_ind"))
                        iRet = INT_INVALID_BAL_OVER_IND;
		else if(!strcmp(csTag, "req_dt"))
                        iRet = INT_INVALID_REQ_DATETIME;
                else if(!strcmp(csTag, "bank_code"))
                        iRet = INT_INVALID_BANK_CODE;
                else if(!strcmp(csTag, "acct_num"))
                        iRet = INT_INVALID_BANK_ACCT;
		else
			iRet = INT_ERR;
	}

	return iRet;
}
