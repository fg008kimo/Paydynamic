/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/19              Elvis Wong
PRD143 increase to 50 rows limt for Delivery out   2018/10/26              Philip Yu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsDLI.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

#define PD_DETAIL_TAG   "dt"

/* char cDebug; */
static char cDebug;
OBJPTR(DB);
OBJPTR(Txn);

int     CheckStatus(const char* csTxnSeq);

void TxnMgtByUsDLI(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
        int	iRet = PD_OK;

	int	iSebCnt = 0;
	int	iAmtDiffCnt = 0;
	int 	iTotalCnt = 0;
	int	i = 0;
	int	iTmp = 0;

	double 	dTmp = 0.0;

	char    *csOrgTxnId = NULL;
	char	*csTmp = NULL;

	char    csTag[PD_TAG_LEN + 1];

	/* PRD143 increase to 50 rows limit for Delivery Out */
	int	iStep;
	hash_t *hTmp = NULL;
	recordset_t *rRec = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRec,0);
	/*End - PRD143 */
	
DEBUGLOG(("Authorize::TxnMgtByUsDLI Begin\n"));

/* txn_seq */
	if (GetField_CString(hContext,"txn_seq",&csTmp)) {
DEBUGLOG(("Authorize::txn_seq = [%s]\n",csTmp));
		//PutField_CString(hResponse, "txn_seq", csTmp);
     	} else {
DEBUGLOG(("Authorize::txn_seq not found!!\n"));
ERRLOG("TxnMgtByUsDLI:Authorize::txn_seq not found!!\n");
            	iRet=INT_INVALID_TXN;
              	PutField_Int(hContext,"internal_error",iRet);
      	}

/* org_txn_seq */
	if (GetField_CString(hRequest,"org_txn_seq",&csOrgTxnId)) {
DEBUGLOG(("Authorize::org_txn_id = [%s]\n",csOrgTxnId));
	      	if (CheckStatus(csOrgTxnId) != PD_OK) {
                    	iRet = INT_INVALID_TXN;
                       	PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize::Invalid txn selected\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::Invalid txn selected!!\n");
             	}
		PutField_CString(hContext,"org_txn_seq",csOrgTxnId);
     	} else {
DEBUGLOG(("Authorize::org_txn_id not found!!\n"));
ERRLOG("TxnMgtByUsDLI:Authorize::org_txn_id not found!!\n");
            	iRet=INT_INVALID_TXN;
              	PutField_Int(hContext,"internal_error",iRet);
      	}

/* entity_id */
      	if (GetField_CString(hRequest,"entity_id",&csTmp)) {
DEBUGLOG(("Authorize::entity_id = [%s]\n",csTmp));
            	PutField_CString(hContext,"entity_id",csTmp);
     	} else {
DEBUGLOG(("Authorize::entity_id not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::entity_id not found!!\n");
            	iRet = INT_MI_ENTITY_ID_NOT_FOUND;
            	PutField_Int(hContext,"internal_error",iRet);
    	}

/* product_code */
        if (GetField_CString(hRequest,"product_code",&csTmp)) {
DEBUGLOG(("Authorize::product_code = [%s]\n",csTmp));
                PutField_CString(hContext,"product_code",csTmp);
        } else {
DEBUGLOG(("Authorize::product_code not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::product_code not found!!\n");
                iRet = INT_MI_PRODUCT_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* ccy */
	if (GetField_CString(hRequest,"txn_ccy",&csTmp)) {
DEBUGLOG(("Authorize::txn_ccy = [%s]\n",csTmp));
                PutField_CString(hContext,"ccy",csTmp);
                PutField_CString(hContext,"txn_ccy",csTmp);
                PutField_CString(hContext,"net_ccy",csTmp);
                PutField_CString(hContext,"org_txn_ccy",csTmp);
                PutField_CString(hContext,"entity_ccy",csTmp);
        } else {
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* seb_cnt */
	if (GetField_CString(hRequest,"seb_cnt",&csTmp)) {
		iSebCnt = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
DEBUGLOG(("Authorize::seb_cnt = [%d]\n",iSebCnt));
                PutField_Int(hContext,"seb_cnt",iSebCnt);
		
		// Set Total Cnt
/*
		iTotalCnt = iSebCnt;
		PutField_Int(hContext,"total_cnt",iTotalCnt);
*/  	
	} else {
DEBUGLOG(("Authorize::seb_cnt not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::seb_cnt not found!!\n");
                iRet = INT_MI_SEB_CNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* amtdiff_cnt */
        if (GetField_CString(hRequest,"amtdiff_cnt",&csTmp)) {
		iAmtDiffCnt = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
DEBUGLOG(("Authorize::amtdiff_cnt = [%d]\n",iAmtDiffCnt));
                PutField_Int(hContext,"amtdiff_cnt",iAmtDiffCnt);
			
		// Check Amt Diff Cnt
/*
		if (iAmtDiffCnt > iSebCnt) {

			//Set Total Cnt
			iTotalCnt = iAmtDiffCnt;
			PutField_Int(hContext,"total_cnt",iTotalCnt);
		}
*/
        }

/* total_cnt */
        if (GetField_CString(hRequest,"total_cnt",&csTmp)) {
                iTotalCnt = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
DEBUGLOG(("Authorize::total_cnt = [%d]\n",iTotalCnt));
                PutField_Int(hContext,"total_cnt",iTotalCnt);
        } else {
DEBUGLOG(("Authorize::total_cnt not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::total_cnt not found!!\n");
                iRet = INT_MI_TOTAL_CNT_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* PRD143 increase to 50 rows limit for Delivery Out*/
/* batch_id */
	if (GetField_CString(hRequest,"batch_id",&csTmp)) {
DEBUGLOG(("Authorize::batch_id = [%s]\n",csTmp));
		DBObjPtr = CreateObj(DBPtr,"DBMiDeliveryOutBatch","GetDetailByBatchId");
		iRet = (unsigned long)(*DBObjPtr)(csTmp,rRec);
		if (iRet == PD_OK) {
			iStep = 0;
			hTmp = RecordSet_GetFirst(rRec);
			while ( hTmp ) {
/* txnamt */
				if (GetField_Double(hTmp,"txnamt",&dTmp)) {
					sprintf(csTag, "txnamt_%d", iStep+1);
                                	PutField_Double(hContext,csTag,dTmp);
DEBUGLOG(("Authorize::%s = [%f]\n",csTag,dTmp));
				} 

/* deliver_date */
				if (GetField_CString(hTmp,"deliver_date",&csTmp)) {
					sprintf(csTag, "deliver_date_%d", iStep+1);
					PutField_CString(hContext,csTag,csTmp);
DEBUGLOG(("Authorize::%s = [%s]\n",csTag,csTmp));
				} 

/* amtdiff_reason */
				if (GetField_CString(hTmp,"amtdiff_reason",&csTmp)) {
					sprintf(csTag, "amtdiff_reason_%d", iStep+1);
					PutField_CString(hContext,csTag,csTmp);
DEBUGLOG(("Authorize::%s = [%s]\n",csTag,csTmp));
				} 

/* amtdiff_ccy */
				if (GetField_CString(hTmp,"amtdiff_ccy",&csTmp)) {
					sprintf(csTag, "amtdiff_ccy_%d", iStep+1);
					PutField_CString(hContext,csTag,csTmp);
DEBUGLOG(("Authorize::%s = [%s]\n",csTag,csTmp));
				} 

/* amtdiff_amt */
				if (GetField_Double(hTmp,"amtdiff_amt",&dTmp)) {
					sprintf(csTag, "amtdiff_amt_%d", iStep+1);
                                	PutField_Double(hContext,csTag,dTmp);
DEBUGLOG(("Authorize::%s = [%f]\n",csTag,dTmp));
				} 
				

				hTmp = RecordSet_GetNext(rRec);
				iStep++;
			}

			RecordSet_Destroy(rRec);
			FREE_ME(rRec);

			/* Compare the record cout with Total count */
			if (iStep != iTotalCnt) {
DEBUGLOG(("Authorize::Total_cnt and Record count mismatched!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::Total_cnt and Record count mismatched!!\n");
                		iRet = INT_MI_TOTAL_CNT_MISMATCH;
                		PutField_Int(hContext,"internal_error",iRet);
			}
        	} else {
DEBUGLOG(("Authorize::batch_id not found!!\n"));
		}
	}
	else
	{
/* End - PRD143 increase to 50 rows limit for Delivery Out*/

		// total_cnt
       		for (i=0; i<iTotalCnt; i++){	
			if (iRet == PD_OK) {

/* txnamt */
				sprintf(csTag, "%s_txnamt_%d", PD_DETAIL_TAG, i+1);
                       		if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
					dTmp = string2double((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::[%s] = [%f]\n",csTag, dTmp));
                               		sprintf(csTag, "txnamt_%d", i+1);
                               		PutField_Double(hContext,csTag,dTmp);
/*
				} else {
DEBUGLOG(("Authorize::[%s] not found!!\n",csTag));
ERRLOG("TxnMgtByUsDLI::Authorize::[%s] not found!!\n",csTag);
                               		iRet = INT_PAY_AMOUNT_NOT_FOUND;
					PutField_Int(hContext,"internal_error",iRet);
*/
                       		}

/* deliver_date */
                       		sprintf(csTag, "%s_deliver_date_%d", PD_DETAIL_TAG, i+1);
                       		if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
                               		sprintf(csTag, "deliver_date_%d", i+1);
                               		PutField_CString(hContext,csTag,csTmp);
                       		}

/* amtdiff_reason */
                       		sprintf(csTag, "%s_amtdiff_reason_%d", PD_DETAIL_TAG, i+1);
                       		if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
                               		sprintf(csTag, "amtdiff_reason_%d", i+1);
                               		PutField_CString(hContext,csTag,csTmp);
                       		}

/* amtdiff_ccy */
                       		sprintf(csTag, "%s_amtdiff_ccy_%d", PD_DETAIL_TAG, i+1);
                       		if (GetField_CString(hRequest, csTag, &csTmp)) {
DEBUGLOG(("Authorize::[%s] = [%s]\n",csTag, csTmp));
                               		sprintf(csTag, "amtdiff_ccy_%d", i+1);
                               		PutField_CString(hContext,csTag,csTmp);
                       		}

/* amtdiff_amt */
                       		sprintf(csTag, "%s_amtdiff_amt_%d", PD_DETAIL_TAG, i+1);
                       		if (GetField_CString(hRequest, csTag, &csTmp)) {
                               		dTmp = string2double((const unsigned char *)csTmp);
DEBUGLOG(("Authorize::[%s] = [%f]\n",csTag, dTmp));
                               		sprintf(csTag, "amtdiff_amt_%d", i+1);
                               		PutField_Double(hContext,csTag,dTmp);
                       		}
			}
		}	
/* PRD143 increase to 50 rows limit for Delivery Out*/
	}
/* End - PRD143 increase to 50 rows limit for Delivery Out*/

/* remark */
        if (GetField_CString(hRequest,"remark",&csTmp)) {
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
                PutField_CString(hContext,"remark",csTmp);
        } else {
DEBUGLOG(("Authorize::remark not found!!\n"));
ERRLOG("TxnMgtByUsDLI::Authorize::remark not found!!\n");
                iRet = INT_MI_REMARK_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
        } 

/* skip_tol_check */
	if (GetField_CString(hRequest,"skip_tol_check",&csTmp)) {
		iTmp = ctos((const unsigned char*)csTmp,(strlen(csTmp)));
DEBUGLOG(("Authorize::skip_tol_check = [%d]\n",iTmp));
                PutField_Int(hContext,"skip_tol_check",iTmp);
        } else {
//DEBUGLOG(("Authorize::skip_tol_check not found!!\n"));
//ERRLOG("TxnMgtByUsDLI::Authorize::skip_tol_check not found!!\n");
                //iRet = INT_ERR;
                //PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
                PutField_CString(hContext,"add_user",csTmp);
                PutField_CString(hContext,"update_user",csTmp);
        } 

	// Pass to MiniMMM
	if (iRet == PD_OK) {

		// txn_type - PSP SETTLE
                PutField_CString(hContext,"mini_txn_type",PD_MI_TXN_TYPE_DELIV_IN);
DEBUGLOG(("Authorize::mini_txn_type = [%s]\n",PD_MI_TXN_TYPE_DELIV_IN));

DEBUGLOG(("Authorize::Call TxnMgtByUs2MiniMMM:Authorize\n"));
                TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUs2MiniMMM","Authorize");
                iRet = (unsigned long)((*TxnObjPtr)(hContext,hRequest,hResponse));
                if (iRet == PD_OK) {
DEBUGLOG(("Authorize::Call TxnMgtByUs2MiniMMM:Authorize SUCCESS, ret [%d]\n",iRet));
                } else {
DEBUGLOG(("Authorize::Call TxnMgtByUs2MiniMMM:Authorize FAILED, ret [%d]\n",iRet));
ERRLOG("TxnMgtByUsDLI::Authorize::Call TxnMgtByUs2MiniMMM:Authorize FAILED, ret [%d]\n",iRet);
                }
	}

DEBUGLOG(("TxnMgtByUsDLI Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}

int     CheckStatus(const char* csTxnSeq)
{
        int     iRet = PD_ERR;

        char    cStatus;
        char    cArInd;

        char    *csSubStatus;

        hash_t *hRec;

        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);

DEBUGLOG(("CheckStatus::Call DBTransaction::GetTxnHeader by txn_seq [%s]\n",csTxnSeq))
        DBObjPtr = CreateObj(DBPtr,"DBTransaction","GetTxnHeader");
        iRet = (unsigned long)(*DBObjPtr)(csTxnSeq,rRecordSet);
	if (iRet == PD_OK) {
DEBUGLOG(("CheckStatus::Call DBTransaction::GetTxnHeader Success\n"));

                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {

/* status */
                        if (GetField_Char(hRec,"status",&cStatus)) {
DEBUGLOG(("CheckStatus::Call DBTransaction::status = [%c]\n",cStatus));
                        }

/* ar_ind */
                        if (GetField_Char(hRec,"ar_ind",&cArInd)) {
DEBUGLOG(("CheckStatus::Call DBTransaction::ar_ind = [%c]\n",cArInd));
                        }

/* sub_status */
                        if(GetField_CString(hRec,"sub_status",&csSubStatus)){
DEBUGLOG(("CheckStatus::Call DBTransaction::sub status = [%s]\n",csSubStatus));
                        }

                        hRec = RecordSet_GetNext(rRecordSet);
                }

                if ((cStatus == PD_COMPLETE) 
		   && (cArInd==PD_ACCEPT) 
		   && (!strcmp(csSubStatus,PD_APPROVED))
		)
		{
                        iRet = PD_OK;
DEBUGLOG(("CheckStatus::Call DBTransaction::Valid txn[%s]: [%c][%c][%s]\n",csTxnSeq,cStatus,cArInd,csSubStatus));
                } else {
DEBUGLOG(("CheckStatus::Call DBTransaction::Invalid txn[%s]: [%c][%c][%s]\n",csTxnSeq,cStatus,cArInd,csSubStatus));
                }
        } else {
DEBUGLOG(("CheckStatus::Call DBTransaction::GetTxnHeader Failed\n"));
	}

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);

DEBUGLOG(("CheckStatus Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}

