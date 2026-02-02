/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/07/08              LokMan Chow
Call BOSettlement to handle			   2011/11/11		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsSTR.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);

void TxnMgtByUsSTR(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp;
	double	dAmt=0;

	if(GetField_CString(hContext,"txn_seq",&csTmp)){
DEBUGLOG(("Authorize::txn_seq= [%s]\n",csTmp));
		PutField_CString(hResponse,"org_txn_seq",csTmp);
		PutField_CString(hContext,"txn_seq",csTmp);
	}
	else{
DEBUGLOG(("Authorize::txnid not found!!\n"));
ERRLOG("TxnMgtByUsSTR::Authorize::txnid not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	
	if(GetField_CString(hRequest,"add_user",&csTmp)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csTmp));
	}

	if(GetField_CString(hRequest,"merchant_id",&csTmp)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csTmp));
		PutField_CString(hContext,"merchant_id",csTmp);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsSTR::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTmp));
		PutField_CString(hResponse,"txn_ccy",csTmp);
		PutField_CString(hContext,"request_ccy",csTmp);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsSTR::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTmp)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTmp));
		PutField_CString(hContext,"txn_country",csTmp);
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsSTR::Authorize::country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"service_code",&csTmp)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csTmp));
		PutField_CString(hContext,"service_code",csTmp);
	}

	if(GetField_Double(hContext,"txn_amt",&dAmt)){
		PutField_Double(hContext,"request_amt",dAmt);
		PutField_Double(hResponse,"txn_amt",dAmt);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsSTR::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}


	if(GetField_CString(hRequest,"remark",&csTmp)){
DEBUGLOG(("Authorize::remark= [%s]\n",csTmp));
		PutField_CString(hContext,"remark",csTmp);
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOSettlement:ProcessSettlementTxn\n"));
		BOObjPtr = CreateObj(BOPtr,"BOSettlement","ProcessSettlementTxn");
		iRet = (unsigned long) (*BOObjPtr)(hContext,hRequest,hResponse);
	}


	/*if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}*/


DEBUGLOG(("TxnMgtByUsSTR Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
