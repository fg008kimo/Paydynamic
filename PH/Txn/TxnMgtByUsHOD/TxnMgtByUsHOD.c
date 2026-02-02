/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/12              LokMan Chow
split into 2 balance handling                      2012/08/15              Virginia Yun
add option: release to ava settlement directly	   2014/02/06		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsHOD.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsHOD(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csUser = NULL;
	char	*csMerchantId = NULL;
	//char	*csPspId = NULL;
	char    *csTxnCountry=strdup("");
	char	*csTxnCcy = NULL;
	char	*csServiceCode = NULL;
	char	*csTmp = NULL;
	char	cType;
	char	cHold;
	double	dAmt = 0.0;
	char	cMHind;
	//int	iTmp;

/*
	recordset_t     *rRecordSet;
	rRecordSet = (recordset_t *)malloc (sizeof(recordset_t));
	recordset_init(rRecordSet,0);
*/

	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}

	if(GetField_CString(hRequest,"hold_type",&csTmp)){
		cHold=csTmp[0];
		PutField_Char(hContext,"hold_type",cHold);
		if(cHold==PD_UNHOLD){
			PutField_CString(hContext,"new_txn_code",PD_UNHOLD_BALANCE);
		}
DEBUGLOG(("Authorize::hold_type= [%c]\n",cHold));
	}
	else{
DEBUGLOG(("Authorize::hold_type not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::hold_type not found!!\n");
                iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
	
	if(GetField_CString(hRequest,"party_type",&csTmp)){
		cType=csTmp[0];
		PutField_Char(hContext,"party_type",cType);
DEBUGLOG(("Authorize::party_type= [%c]\n",cType));

		if(cType==PD_TYPE_PSP){

			/** not support PSP, only support merchant **/
			iRet = INT_INVALID_PARTY_TYPE;
			PutField_Int(hContext,"internal_error",iRet);
		}
		else if(cType==PD_TYPE_MERCHANT){

        		if (GetField_CString(hRequest, "mh_ind", &csTmp)) {
				cMHind = csTmp[0];
				PutField_Char(hContext, "mh_ind",cMHind);
        		}
		        else {
DEBUGLOG(("Authorize::mh_ind not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::mh_ind not found!!\n");
                		iRet=INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
        		}
			
			if(GetField_CString(hRequest,"party_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
				PutField_CString(hContext,"merchant_id",csMerchantId);
				PutField_CString(hRequest,"merchant_id",csMerchantId);

				if(iRet==PD_OK){
//////get merchant_client_id
DEBUGLOG(("Authorize::Call BOMerchant:GetMerchantTxnInfo\n"));
					BOObjPtr = CreateObj(BOPtr,"BOMerchant","GetMerchantTxnInfo");
					iRet = (unsigned long)(*BOObjPtr)(hContext,hRequest);
				}
			}
			else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::merchant_id not found!!\n");
				iRet=INT_MERCHANT_ID_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
				PutField_CString(hContext,"service_code",csServiceCode);
			}
        		else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::service_code not found!!\n");
                		iRet=INT_SERVICE_CODE_MISSING;
				PutField_Int(hContext,"internal_error",iRet);
        		}
		}
		else{
DEBUGLOG(("Authorize::party_type invalid!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::party_type invalid!!\n");
                iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
		}
	}
	else{
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::party_type not found!!\n");
                iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
		PutField_CString(hContext,"net_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hContext,"txn_country",csTxnCountry);
	}
	else{
		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_Double(hContext,"txn_amt",&dAmt)){
		PutField_Double(hContext,"net_amt",dAmt);
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if (GetField_CString(hRequest, "rls_to_sett", &csTmp)) {
		PutField_Int(hContext,"rls_to_sett",atoi(csTmp));
DEBUGLOG(("Authorize::release to settlement = [%d]\n",atoi(csTmp)));
	}
/*
	if (GetField_Int(hContext, "allow_bal_negative", &iTmp)) {
DEBUGLOG(("Authorize::allow balance negative = [%d]\n",iTmp));
	}
	else {
DEBUGLOG(("Authorize::allow_bal_negative not found!!\n"));
ERRLOG("TxnMgtByUsHOD::Authorize::allow_bal_negative not found!!\n");

		iRet=INT_ERR;
		PutField_Int(hContext,"internal_error",iRet);
	}
*/

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call BOBalance: ProcessHold\n"));
                BOObjPtr = CreateObj(BOPtr,"BOBalance","ProcessHold");
                iRet = (unsigned long)((*BOObjPtr)(hContext,hRequest));
	
	}

	if(iRet==PD_OK){
/*
DEBUGLOG(("Authorize::Call DBTransaction:UpdateDetail\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
                	if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK)
                        	iRet = INT_ERR;
*/

DEBUGLOG(("Authorize::Call MGTChannel:UpdateTxnDetailLog\n"));
		ChannelObjPtr = CreateObj(ChannelPtr, "MGTChannel","UpdateTxnDetailLog");
		if ((unsigned long)((*ChannelObjPtr)(hContext, hRequest, hResponse)) != PD_OK) {
			iRet = INT_ERR;
		}


	}

	if (iRet == PD_OK) {
		GetField_CString(hContext, "PHDATE", &csTmp);

		// for add approve timestamp
		//PutField_CString(hContext, "approval_date", csTmp);
		PutField_CString(hContext, "sub_status", PD_APPROVED);
		
	}

	if(iRet==PD_OK){
		if(GetField_CString(hContext,"txn_seq",&csTmp)){
			PutField_CString(hResponse,"org_txn_seq",csTmp);
		}
	}

	/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
	*/

/*
	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);
*/

	FREE_ME(csTxnCountry);
DEBUGLOG(("TxnMgtByUsHOD Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
