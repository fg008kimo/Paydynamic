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
#include "TxnMifByUsEAC.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMifByUsEAC(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
		  hash_t* hRequest,
		  hash_t* hResponse)
{
        int	iRet = PD_OK;

	char	*csTmp = NULL;
	char	*csTxnId = NULL;
	char	*csCode = NULL;
	char	*csOrgTxnCode = NULL;

	char	*csEntityId = NULL;
	char	*csEntityType = NULL;
	char	*csTxnCountry = NULL;
	char	*csProductCode = NULL;
	char	*csFrCcy = NULL;
	char	*csNetCcy = NULL;
	char	*csUpdateUser = NULL;  
	double	dFrAmt=0.0;
	double	dAmt=0.0;
	int	iTmp;
	char	*csAmtType = NULL;

	recordset_t *rRecordSet;
	rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);

DEBUGLOG(("Authorize::Start\n"));
/* txn_seq */
        if(GetField_CString(hContext,"txn_seq",&csTxnId)){
DEBUGLOG(("Authorize::txn_seq = [%s]\n", csTxnId));
        }
        else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::txnid not found!!\n");
                iRet=INT_INVALID_TXN;
                PutField_Int(hContext,"internal_error",iRet);
        }

/* txn_code*/
        if(GetField_CString(hRequest,"txn_code",&csOrgTxnCode)){
DEBUGLOG(("Authorize::txn_code = [%s]\n",csOrgTxnCode));
        }
        else{
DEBUGLOG(("Authorize::txn_code not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::txn_code not found!!\n");
                iRet=INT_ERR;

                PutField_Int(hContext,"internal_error",iRet);
        }

/* add_user */
        if(GetField_CString(hContext,"add_user",&csUpdateUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUpdateUser));
        }

/* remark */
        if(GetField_CString(hContext,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark = [%s]\n",csTmp));
        }

/* entity_id */
        if(GetField_CString(hContext,"entity_id",&csEntityId)){
DEBUGLOG(("Authorize::entity_id = [%s]\n",csEntityId));
        }
	else {
DEBUGLOG(("Authorize::entity_id not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::entity_id not found!!\n");
		iRet = INT_MI_ENTITY_ID_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* entity_type */
        if(GetField_CString(hContext,"entity_type",&csEntityType)){
DEBUGLOG(("Authorize::ent_party_type = [%s]\n",csEntityType));
        }
	else {
DEBUGLOG(("Authorize::entity_type not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::entity_type not found!!\n");
		iRet = INT_MI_ENTITY_TYPE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* code */
        if(GetField_CString(hContext,"code",&csCode)){
DEBUGLOG(("Authorize::code = [%s]\n",csCode));
        } 
	else {
DEBUGLOG(("Authorize::code not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::code not found!!\n");
		iRet=INT_CODE_ERROR;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* txn_country */
	if(GetField_CString(hContext,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
        }
        else{
DEBUGLOG(("Authorize::txn_country not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::txn_country not found!!\n");
                iRet=INT_COUNTRY_PSP_NOT_AVABILE;
               	PutField_Int(hContext,"internal_error",iRet);
        }

/* product_code */
        if(GetField_CString(hContext,"product_code",&csProductCode)){
DEBUGLOG(("Authorize::product_code = [%s]\n",csProductCode));
        } 
	else {
DEBUGLOG(("Authorize::product_code not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::product_code not found!!\n");
		iRet=INT_MI_PRODUCT_CODE_NOT_FOUND;
                PutField_Int(hContext,"internal_error",iRet);
	}

/* fr_ccy */
        if(GetField_CString(hContext,"fr_ccy",&csFrCcy)){
DEBUGLOG(("Authorize::fr_ccy= [%s]\n",csFrCcy));
        }

/* net_ccy */
        if(GetField_CString(hContext,"net_ccy",&csNetCcy)){
DEBUGLOG(("Authorize::net_ccy= [%s]\n",csNetCcy));
        }
        else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::ccy not found!!\n");
                iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }


/* ft_txnamt */
        if(GetField_Double(hContext,"fr_txnamt",&dFrAmt)){
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dFrAmt));
        }

/* net_amt */
        if(GetField_Double(hContext,"net_amt",&dAmt)){
DEBUGLOG(("Authorize::net_amt= [%f]\n",dAmt));
        }
        else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMifByUsEAC::Authorize::txn_amt not found!!\n");
                iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
        }

/* report_date */
        if(GetField_CString(hContext,"report_date",&csTmp)){
DEBUGLOG(("Authorize::report_date = [%s]\n", csTmp)); 
	}

	PutField_CString(hRequest, "service_code", PD_DEFAULT_SERVICE);

        PutField_CString(hContext,"process_code","000000");
        PutField_CString(hContext,"process_type","0000");
	PutField_CString(hContext, "sub_status", PD_APPROVED);

	PutField_Char(hContext,"ex_party",PD_INT_EX);
	PutField_Double(hContext,"ex_rate",1);
	PutField_Char(hContext,"recon_status",PD_RECON_NOT_REQ);

	//Update Balance
        if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOOLMiAdjustment:ProcessPartyBalance\n"));
                BOObjPtr = CreateObj(BOPtr,"BOOLMiAdjustment","ProcessPartyBalance");
		iRet = (unsigned long)((*BOObjPtr)(hContext));

		if (iRet != PD_OK) {
DEBUGLOG(("Authorize::BOOLMiAdjustment:ProcessPartyBalance Failed Ret [%d]\n", iRet));
ERRLOG("TxnMifByUsEAC::BOOLMiADjustment::ProcesspartyBalance Failed [%d]\n", iRet);
		} else {
                        if (GetField_CString(hContext,"amt_type",&csAmtType)) {
DEBUGLOG(("Authorize::amt_type = [%s]\n", csAmtType));
                                PutField_CString(hContext, "amount_type", csAmtType);
                        }
                        else {
DEBUGLOG(("Authorize::BOOLMiAdjustment:ProcessPartyBalance Failed to get amt_type\n"));
ERRLOG("TxnMifByUsEAC::BOOLMiADjustment::ProcesspartyBalance Failed to get amt_type\n");
                                iRet = PD_ERR;
                        }

		}
        } 

       if(GetField_Int(hContext,"do_logging",&iTmp)){
DEBUGLOG(("Authorize::do_logging [%d]\n", iTmp));
                if(iTmp!=PD_ADD_LOG) {
                        /* nothing */
                }
                else {
        		if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBOLTxnMiDetail:Add\n"));
		                DBObjPtr = CreateObj(DBPtr,"DBOLTxnMiDetail","Add");
				if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
					iRet = INT_ERR;
        		}
		}
	}


	if(iRet!= PD_OK){
		RemoveField_CString(hContext, "sub_status");
		RemoveField_CString(hContext, "approval_date");
		RemoveField_CString(hContext, "approval_timestamp");
	}


	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

DEBUGLOG(("TxnMifByUsEAC Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}
