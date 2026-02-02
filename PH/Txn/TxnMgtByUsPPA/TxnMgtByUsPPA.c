/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/10/31              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsPPA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define       PD_DETAIL_TAG   "dt"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnMgtByUsPPA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csBatchId;
	//char	*csDate;
	char	*csTmp;
	char	*p;
	int	i= 0;
	int	iTmp= 0;
	int	iCnt= 0;
	int	iCheck= 0;
	int	iDtlRet = 0;
	//int	iDayOfWeek = 0;
	//int	iSeqNum= 0;
	double	dTmp;
	char	cInputInd;
	//char	cMode = PD_ACCEPTED;
	char	csTag[PD_TAG_LEN+1];
	int	iApproveId = 0;


DEBUGLOG(("Authorize\n"));

/* input ind*/
        if(GetField_CString(hRequest,"input_ind",&csTmp)){
                cInputInd = csTmp[0];
		PutField_Char(hContext,"input_ind",cInputInd);
DEBUGLOG(("Authorize::input_ind= [%c]\n",cInputInd));
        }

/* approval date 
	if(GetField_CString(hContext,"PHDATE",&csDate)){
DEBUGLOG(("Authorize::approval_date= [%s]\n",csDate));
		PutField_CString(hContext,"approval_date",csDate);
		PutField_CString(hContext,"posting_date",csDate);

		iDayOfWeek=day_of_week((const unsigned char *)csDate);
DEBUGLOG(("Authorize::day_of_week= [%d]\n",iDayOfWeek));
		PutField_Int(hContext,"day_of_week",iDayOfWeek);
	}
*/

/* user 
        if(GetField_CString(hRequest,"add_user",&csTmp)){
		PutField_CString(hContext,"update_user",csTmp);
		PutField_CString(hContext,"add_user",csTmp);
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
        }
*/

/* bank name */
        if(cInputInd == PD_BY_BANK){
		if(GetField_CString(hRequest,"batch_id",&csTmp)){
			PutField_CString(hContext,"batch_id",csTmp);
DEBUGLOG(("Authorize::batch_id= [%s]\n",csTmp));
		}
                if(GetField_CString(hRequest,"bank_name",&csTmp)){
			PutField_CString(hContext,"bank_name",csTmp);
DEBUGLOG(("Authorize::bank_name= [%s]\n",csTmp));
                }
		else{
DEBUGLOG(("Authorize::bank_name not found!!\n"));
ERRLOG("TxnMgtByUsPPA:Authorize::bank_name not found!!\n");
			iRet=INT_ERR;
		}

		if(GetField_CString(hRequest,"total_amt",&csTmp)){
			iCheck = PD_FALSE;
			p = (char*)strchr(csTmp, '.');
			if (p == NULL){
				iCheck = is_numeric(csTmp);
				if(iCheck!=PD_FALSE){
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					}
				}
			}
			else{
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					iCheck = PD_TRUE;
				}
			}
			if(iCheck==PD_FALSE){
				iRet =  INT_INVALID_PAY_AMOUNT;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()total_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnMgtByUsPPA::Authorize() total_amt Invalid\n");
			}
		}
        }

/* batch id */
	else if(cInputInd == PD_BY_BATCH){
		if(GetField_CString(hRequest,"batch_id",&csTmp)){
			PutField_CString(hContext,"batch_id",csTmp);
DEBUGLOG(("Authorize::batch_id= [%s]\n",csTmp));
		}
		else{
DEBUGLOG(("Authorize::batch_id not found!!\n"));
ERRLOG("TxnMgtByUsPPA:Authorize::batch_id not found!!\n");
			iRet=INT_ERR;
		}
	}

/* total amt */
        else if(cInputInd == PD_BY_TOTAL_AMT){
		if(GetField_CString(hRequest,"batch_id",&csTmp)){
			PutField_CString(hContext,"batch_id",csTmp);
DEBUGLOG(("Authorize::batch_id= [%s]\n",csTmp));
		}
		if(GetField_CString(hRequest,"total_amt",&csTmp)){
			iCheck = PD_FALSE;
			p = (char*)strchr(csTmp, '.');
			if (p == NULL){
				iCheck = is_numeric(csTmp);
				if(iCheck!=PD_FALSE){
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					}
				}
			}
			else{
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					iCheck = PD_TRUE;
				}
			}
			if(iCheck==PD_FALSE){
				iRet =  INT_INVALID_PAY_AMOUNT;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()total_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnMgtByUsPPA::Authorize() total_amt Invalid\n");
			}
		}
		else{
DEBUGLOG(("Authorize::total_amt not found!!\n"));
ERRLOG("TxnMgtByUsPPA:Authorize::total_amt not found!!\n");
			iRet=INT_ERR;
		}
        }

/* min/max amt */
        else if(cInputInd == PD_BY_TXN_AMT){
		if(GetField_CString(hRequest,"batch_id",&csTmp)){
			PutField_CString(hContext,"batch_id",csTmp);
DEBUGLOG(("Authorize::batch_id= [%s]\n",csTmp));
		}
		for(i = 0; i < 2; i++){
			if(i==0)
				sprintf(csTag,"min_amt");
			else
				sprintf(csTag,"max_amt");

			if(GetField_CString(hRequest,csTag,&csTmp)){
				iCheck = PD_FALSE;
				p = (char*)strchr(csTmp, '.');
				if (p == NULL){
					iCheck = is_numeric(csTmp);
					if(iCheck!=PD_FALSE){
						if(sscanf(csTmp,"%lf",&dTmp)==1){
							PutField_Double(hContext,csTag,dTmp);
DEBUGLOG(("Authorize() %s = [%f]\n",csTag,dTmp));
						}
					}
				}
				else{
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,csTag,dTmp);
DEBUGLOG(("Authorize() %s = [%f]\n",csTag,dTmp));
						iCheck = PD_TRUE;
					}
				}
				if(iCheck==PD_FALSE){
					iRet =  INT_INVALID_PAY_AMOUNT;
					PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize() %s Invalid[%s]\n",csTag,csTmp));
ERRLOG("TxnMgtByUsPPA::Authorize() %s Invalid[%s]\n",csTag,csTmp);
				}
			}
			else{
DEBUGLOG(("Authorize:: %s not found\n",csTag));
ERRLOG("TxnMgtByUsPPA::Authorize:: %s not found\n",csTag);
				iRet = INT_ERR;
			}
		}

		if(GetField_CString(hRequest,"total_amt",&csTmp)){
			iCheck = PD_FALSE;
			p = (char*)strchr(csTmp, '.');
			if (p == NULL){
				iCheck = is_numeric(csTmp);
				if(iCheck!=PD_FALSE){
					if(sscanf(csTmp,"%lf",&dTmp)==1){
						PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					}
				}
			}
			else{
				if(sscanf(csTmp,"%lf",&dTmp)==1){
					PutField_Double(hContext,"total_amt",dTmp);
DEBUGLOG(("Authorize() total_amt = [%f]\n",dTmp));
					iCheck = PD_TRUE;
				}
			}
			if(iCheck==PD_FALSE){
				iRet =  INT_INVALID_PAY_AMOUNT;
				PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()total_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnMgtByUsPPA::Authorize() total_amt Invalid\n");
			}
		}
	}

/* specified records */
	else if(cInputInd == PD_BY_TXN){
                if (GetField_Int(hContext, "total_cnt", &iCnt)) {
DEBUGLOG(("Authorize::total_cnt = [%d]\n", iCnt));
                }
                else {
DEBUGLOG(("Authorize::total_cnt not found\n"));
ERRLOG("TxnMgtByUsPPA::Authorize::total_cnt not found\n");
                        iRet = INT_ERR;
                }

		if(GetField_CString(hRequest,"batch_id",&csBatchId)){
			PutField_CString(hContext,"batch_id",csBatchId);
DEBUGLOG(("Authorize::batch_id= [%s]\n",csBatchId));
		}
		else{
DEBUGLOG(("Authorize::batch_id not found!!\n"));
ERRLOG("TxnMgtByUsPPA:Authorize::batch_id not found!!\n");
			iRet=INT_ERR;
		}

                if (iRet == PD_OK) {
			iDtlRet = PD_OK;
                        for (i = 0; i < iCnt; i++) {
/* batch_id */
				sprintf(csTag, "batch_id_%d",i);
				PutField_CString(hContext,csTag,csBatchId);

/* seq_num */
                                sprintf(csTag, "%s_seq_num_%d", PD_DETAIL_TAG, i+1);
                                if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::() [%s] = [%s]\n", csTag, csTmp));
					sprintf(csTag, "seq_num_%d",i);
					PutField_CString(hContext,csTag,csTmp);
                                }
                                else {
DEBUGLOG(("Authorize::[%s] not found\n", csTag));
ERRLOG("TxnMgtByUsPPA::Authorize::[%s] not found\n", csTag);
                                        iDtlRet = INT_ERR;
                                }

                        }
			if(iDtlRet!=PD_OK){
                       		iRet = INT_ERR;
			}
                }
        }
	else{
DEBUGLOG(("Authorize::Invalid input ind!!!\n"));
ERRLOG("TxnMgtByUsPPA::Authorize::Invalid input ind!!!\n");
                        iRet = INT_ERR;
	}



	if(iRet==PD_OK){
		PutField_Int(hContext,"status",PAYOUT_MASTER_TRANSACTION_CONFIRMED);
DEBUGLOG(("Authorize::call BOPayout->GetPayoutRecordsByMode\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","GetPayoutRecordsByMode");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest,hResponse);
        }

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::call BOPayout->CheckAvalBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOPayout","CheckAvalBalance");
                iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
	}

	if(iRet==PD_OK){
		hash_t  *hTxn;
		hTxn= (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTxn,0);

DEBUGLOG(("Authorize::DBMerchantUploadFileDetail:GetNextPreApproveId\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","GetNextPreApproveId");
		if((unsigned long) ((*DBObjPtr)(&iApproveId))!=PD_OK){
			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::DBMerchantUploadFileDetail:GetNextPreApproveId Failed\n"));
		}
		else{
DEBUGLOG(("Authorize:::GetNextPreApproveId [%d]\n",iApproveId));
			PutField_Int(hTxn,"pre_approve_id",iApproveId);
			PutField_Int(hResponse,"approve_id",iApproveId);
		}

		iCnt = 0;
		if(GetField_Int(hContext,"total_cnt",&iCnt)){
DEBUGLOG(("Authorize::total count = [%d]\n",iCnt));
		}
		
		for(i=0;i<iCnt;i++){
			sprintf(csTag,"seq_num_%d",i);
			if(GetField_Int(hRequest,csTag,&iTmp)){
				PutField_Int(hContext,"seq_num",iTmp);
			}
			sprintf(csTag,"batch_id_%d",i);
			if(GetField_CString(hRequest,csTag,&csTmp)){
				PutField_CString(hContext,"batch_id",csTmp);
			}

			DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","UpdateDetailByBatchId");
			if ((*DBObjPtr)(csTmp,iTmp,hTxn) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("BOPayout::DBMerchantUploadFileDetail:UpdateDetailByBatchId Failed\n"));
				PutField_Int(hContext,"internal_error",iRet);
				break;
			}
		}
	
		FREE_ME(hTxn);	

	}
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBMerchantUploadFileDetail","ResumeUnusedPreApproveId");
		if ((*DBObjPtr)(iApproveId) != PD_OK) {
			iRet = INT_ERR;
DEBUGLOG(("BOPayout::DBMerchantUploadFileDetail:ResumeUnusedPreApproveId Failed\n"));
			PutField_Int(hContext,"internal_error",iRet);
		}
	}


DEBUGLOG(("TxnMgtByUsPPA Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
