/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/09              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnOmtByUsEAC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(Txn);
OBJPTR(Channel);

void TxnOmtByUsEAC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
        int	iRet = PD_OK;

	int	iCheck = 0;
	char	*csTmp = NULL;
	char	*p = NULL;

	char	*csTxnId = NULL;
	char	*csCode = NULL;
	char	*csOrgTxnCode = NULL;

	char	*csEntityId = NULL;
	char	*csEntityType = NULL;
	char	*csTxnCountry = NULL;
	char	*csProductCode = NULL;
	char	*csFrCcy = NULL;
	char	*csTxnCcy = NULL;
	char	*csUpdateUser = NULL;  
	double	dFrAmt=0.0;
	double	dAmt=0.0;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize::Start\n"));
/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTxnId)){
		PutField_CString(hResponse,"org_txn_seq",csTxnId);
DEBUGLOG(("Authorize::txn_seq = [%s]\n", csTxnId));
                PutField_CString(hContext, "from_txn_seq", csTxnId);
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_code*/
        if(GetField_CString(hRequest,"txn_code",&csOrgTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csOrgTxnCode));
        }
        else{
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;

                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if(GetField_CString(hRequest,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
                PutField_CString(hContext,"add_user",csUpdateUser);
                PutField_CString(hContext,"update_user",csUpdateUser);
        }

/* remark */
        if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
                PutField_CString(hContext,"remark",csTmp);
        }


/* entity_id */
        if(GetField_CString(hRequest,"entity_id",&csEntityId)){
DEBUGLOG(("Authorize::entity_id = [%s]\n",csEntityId));
                PutField_CString(hContext,"entity_id",csEntityId);
        }
	else {
DEBUGLOG(("Authorize::entity_id not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::entity_id not found!!\n");
		iRet = INT_MI_ENTITY_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* ent_party_type */
        if(GetField_CString(hRequest,"ent_party_type",&csEntityType)){
DEBUGLOG(("Authorize::ent_party_type = [%s]\n",csEntityType));
                PutField_CString(hContext,"entity_type",csEntityType);
                PutField_CString(hContext,"party_type",csEntityType);
        }
	else {
DEBUGLOG(("Authorize::entity_type not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::entity_type not found!!\n");
		iRet = INT_MI_ENTITY_TYPE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* code */
        if(GetField_CString(hRequest,"code",&csCode)){
DEBUGLOG(("Authorize::code = [%s]\n",csCode));
                PutField_CString(hContext,"code",csCode);
DEBUGLOG(("Authorize::Assign new Txn code = [%s]\n",csCode));

		PutField_CString(hContext, "new_txn_code", csCode);
        } 
	else {
DEBUGLOG(("Authorize::code not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::code not found!!\n");
		iRet=INT_CODE_ERROR;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_country */
	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
                PutField_CString(hContext,"txn_country",csTxnCountry);
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
        }
        else{
		if (!strcmp(csEntityType,PD_MI_ENTITY_OPBANK)) {
			PutField_CString(hContext,"txn_country",PD_DEFAULT_COUNTRY);
		} else {
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::txn_country not found!!\n");
			iRet=INT_COUNTRY_PSP_NOT_AVABILE;
			PutField_Int(hContext,"internal_error",iRet);
		}
        }

/* product_code */
        if(GetField_CString(hRequest,"product_code",&csProductCode)){
DEBUGLOG(("Authorize::product_code = [%s]\n",csProductCode));
                PutField_CString(hContext,"product_code",csProductCode);
                PutField_CString(hContext,"txn_product",csProductCode);
        } 
	else {
DEBUGLOG(("Authorize::product_code not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::product_code not found!!\n");
		iRet=INT_MI_PRODUCT_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* fr_ccy */
        if(GetField_CString(hRequest,"fr_ccy",&csFrCcy)){
DEBUGLOG(("Authorize::fr_ccy= [%s]\n",csFrCcy));
                PutField_CString(hContext,"fr_ccy",csFrCcy);
        }

/* txn_ccy */
        if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
                PutField_CString(hContext,"ccy",csTxnCcy);
                PutField_CString(hContext,"txn_ccy",csTxnCcy);
                PutField_CString(hContext,"net_ccy",csTxnCcy);
                PutField_CString(hContext,"org_txn_ccy",csTxnCcy);
                PutField_CString(hContext,"entity_ccy",csTxnCcy);
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_amt */
        if(GetField_Double(hContext,"txn_amt",&dAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
                PutField_Double(hContext, "net_amt", dAmt);
                PutField_Double(hContext, "org_txn_amt", dAmt);
                PutField_Double(hContext, "entity_txn_amount", dAmt);
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnOmtByUsEAC::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* ft_txnamt */
	if(GetField_CString(hRequest,"fr_txnamt",&csTmp)){
		iCheck = PD_FALSE;
		p = (char*)strchr(csTmp, '.');
		if (p == NULL){
			iCheck = is_numeric(csTmp);
			if(iCheck!=PD_FALSE){
				if(sscanf(csTmp,"%lf",&dFrAmt)==1){
					PutField_Double(hContext,"fr_txnamt",dFrAmt);
DEBUGLOG(("Authorize: fr_txnamt = [%f]\n",dFrAmt));
				}
			}
		} else {
			if(sscanf(csTmp,"%lf",&dFrAmt)==1){
				PutField_Double(hContext,"fr_txnamt",dFrAmt);
DEBUGLOG(("Authorize: fr_txnamt = [%f]\n",dFrAmt));
				iCheck = PD_TRUE;
			}
		}
		if(iCheck==PD_FALSE){
			iRet =  INT_INVALID_PAY_AMOUNT;
			PutField_Int(hContext,"internal_error",iRet);
DEBUGLOG(("Authorize()fr_txnamt Invalid[%s]\n",csTmp));
ERRLOG("TxnOmtByUsEAC::Authorize() fr_txnamt Invalid\n");
		}
		PutField_Double(hContext,"txn_amt",dFrAmt);
	}

/* report_date */
        if(!GetField_CString(hRequest,"report_date",&csTmp)){
DEBUGLOG(("Authorize::report_date not found!!\n"));
                if(GetField_CString(hContext,"PHDATE",&csTmp)){
			PutField_CString(hContext, "report_date", csTmp);
			PutField_CString(hContext, "txn_date", csTmp);
DEBUGLOG(("Authorize::report_date (PH date) = [%s]\n", csTmp)); 
		}
        }
	else {
		PutField_CString(hContext, "report_date", csTmp);
		PutField_CString(hContext, "txn_date", csTmp);
DEBUGLOG(("Authorize::report_date = [%s]\n", csTmp)); 
	}

        PutField_CString(hContext,"mini_txn_type",PD_MI_TXN_TYPE_ADJUST);

DEBUGLOG(("Authorize::Call TxnOmtByUs2MiniMMM:Authorize\n"));
	TxnObjPtr = CreateObj(TxnPtr,"TxnOmtByUs2MiniMMM","Authorize");
	iRet = (unsigned long)((*TxnObjPtr)(hContext,hRequest,hResponse));
	if (iRet != PD_OK) {
DEBUGLOG(("Authorize::Call TxnOmtByUs2MiniMMM:Authorize FAILED, ret [%d]\n",iRet));
ERRLOG("TxnOmtByUsEAC::Authorize::Call TxnOmtByUs2MiniMMM:Authorize FAILED, ret [%d]\n",iRet);
	}

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnOmtByUsEAC Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
