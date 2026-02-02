/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/05/31              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsOPS.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsOPS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	//char	*csPspId = NULL;
	//char    *csTxnCountry=strdup("");
	//char	*csTxnCcy = NULL;
	char	*csFromCcy = NULL;
	char	*csDate = NULL;
	char	*csTxnSeq= NULL;
	char	*csTmp = NULL;
	double	dAmt = 0.0;
	double	dSrcAmt = 0.0;

	//hash_t	*hRec;
	//recordset_t     *rRecordSet;
	//rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	//recordset_init(rRecordSet,0);


	
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}
	
	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
		PutField_CString(hContext,"remark",csTmp);
	}

	if(GetField_CString(hRequest,"bank_ccy",&csFromCcy)){
		PutField_CString(hContext,"txn_ccy",csFromCcy);
		PutField_CString(hContext,"net_ccy",csFromCcy);
DEBUGLOG(("Authorize::bank_ccy= [%s]\n",csFromCcy));
	}
	else{
DEBUGLOG(("Authorize::bank_ccy not found!!\n"));
ERRLOG("TxnMgtByUsOPS::Authorize::bank_ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"bank_amt",&csTmp)){
                int iCheck = PD_FALSE;
		char    *p = NULL;
                p = (char*)strchr(csTmp, '.');
                if (p == NULL){
                        iCheck = is_numeric(csTmp);
                        if(iCheck!=PD_FALSE){
                                if(sscanf(csTmp,"%lf",&dSrcAmt)==1){
					PutField_Double(hContext,"txn_amt",dSrcAmt);
					PutField_Double(hContext,"net_amt",dSrcAmt);
DEBUGLOG(("Authorize() src_txn_amt = [%f]\n",dSrcAmt));
                                }
                        }
                }
                else{
                        if(sscanf(csTmp,"%lf",&dSrcAmt)==1){
				PutField_Double(hContext,"txn_amt",dSrcAmt);
				PutField_Double(hContext,"net_amt",dSrcAmt);
DEBUGLOG(("Authorize() src_txn_amt = [%f]\n",dSrcAmt));
                                iCheck = PD_TRUE;
                        }
                }
                if(iCheck==PD_FALSE){
                        iRet =  INT_INVALID_PAY_AMOUNT;
                        PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()src_txn_amt Invalid[%s]\n",csTmp));
ERRLOG("TxnMgtByUsOPS::Authorize() src_txn_amt Invalid\n");
                }
        }
        else{
DEBUGLOG(("Authorize::src_txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsOPS::Authorize::src_txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }



//////debit SebBalance
	if(iRet==PD_OK){
		PutField_CString(hContext,"bank_ccy",csFromCcy);
		PutField_Double(hContext,"bank_bal",dSrcAmt);
DEBUGLOG(("Authorize::Call BOBalance:DebitSebBalance\n"));
		BOObjPtr = CreateObj(BOPtr,"BOBalance","DebitSebBalance");
		iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
		if(iRet==PD_ERR){
			iRet = INT_ERR;
DEBUGLOG(("Authorize::BOBalance:DebitSebBalance Error\n"));
ERRLOG("TxnMgtByUsOPS::Authorize::BOBalance:DebitSebBalance Error\n");
		}
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call Transaction:AddDetail\n"));
                DBObjPtr = CreateObj(DBPtr, "DBTransaction","AddDetail");
                if ((unsigned long)((*DBObjPtr)(hContext)) != PD_OK) {
                        iRet = INT_ERR;
                }
        }


	if (iRet == PD_OK) {
		// for add approve timestamp
		DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
		(*DBObjPtr)(hContext);
DEBUGLOG(("Authorize:: SystemControl::GetApprovalDT called\n"));
		if(!GetField_CString(hContext,"approval_date",&csDate)){
			GetField_CString(hContext,"PHDATE",&csDate);
		}
		PutField_CString(hContext, "sub_status", PD_APPROVED);
		
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
			PutField_CString(hResponse,"org_txn_seq",csTxnSeq);
		}
	}

/////Add to FundsOut table (for SEB balance)
	if(iRet==PD_OK){
		hash_t  *hTxn;
		hTxn = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hTxn,0);

		int	iId = 0;
		int	iCnt = 0;
		int	i = 0;
		double	dTmp = 0.0;
		char	csId[PD_TXN_SEQ_LEN+1];
		char	csTag[PD_TAG_LEN+1];

DEBUGLOG(("Authorize::call DBFundsOut->Add\n"));
		if(GetField_Double(hContext,"bal_after_fo",&dAmt)){
			PutField_Double(hTxn,"bank_bal",dAmt);
		}
		PutField_CString(hTxn,"txn_seq",csTxnSeq);
		PutField_Double(hTxn,"fundout_amt",dSrcAmt);
		PutField_CString(hTxn,"fundout_ccy",csFromCcy);
		PutField_CString(hTxn,"fundout_date",csDate);
		PutField_CString(hTxn,"add_user",csUser);
		DBObjPtr = CreateObj(DBPtr,"DBFundsOut","Add");
		if((unsigned long)(*DBObjPtr)(hTxn)==PD_OK){
			if(GetField_Int(hTxn,"fundsout_id",&iId)){
				sprintf(csId,"%d",iId);
				PutField_CString(hTxn,"td_batch_id",csId);

DEBUGLOG(("Authorize::call DBTransaction->UpdateDetail\n"));
				DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                                if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
DEBUGLOG(("Authorize::DBTransaction->UpdateDetail Failed\n"));
				}

				iCnt = 0;
				if(GetField_Int(hContext,"seb_ccy_cnt",&iCnt)){
DEBUGLOG(("Authorize::call DBFundsOutHistory insert [%d] record\n",iCnt));
				}

				for(i=0;i<iCnt;i++){
					dTmp = 0.0;
					sprintf(csTag,"from_ccy_%d",i);
					if(GetField_CString(hContext,csTag,&csTmp)){
						PutField_CString(hTxn,"from_ccy",csTmp);
					}
					sprintf(csTag,"fundout_amt_%d",i);
					if(GetField_Double(hContext,csTag,&dTmp)){
						PutField_Double(hTxn,"fundout_amt",dTmp);
					}
					sprintf(csTag,"old_bal_%d",i);
					if(GetField_Double(hContext,csTag,&dTmp)){
						PutField_Double(hTxn,"old_bal",dTmp);
					}
					sprintf(csTag,"new_bal_%d",i);
					if(GetField_Double(hContext,csTag,&dTmp)){
						PutField_Double(hTxn,"new_bal",dTmp);
					}
					DBObjPtr = CreateObj(DBPtr,"DBFundsOutHistory","Add");
					if((unsigned long)(*DBObjPtr)(hTxn)!=PD_OK){
DEBUGLOG(("Authorize::DBFundsOutHistory->Add Failed\n"));
					}
				}
			}

		}

		FREE_ME(hTxn);
	}


	//RecordSet_Destroy(rRecordSet);
	//FREE_ME(rRecordSet);
	//FREE_ME(csTxnCountry);

DEBUGLOG(("TxnMgtByUsOPS Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
