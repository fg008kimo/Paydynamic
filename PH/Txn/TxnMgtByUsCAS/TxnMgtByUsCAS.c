/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/21              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCAS.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Channel);

void TxnMgtByUsCAS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

        char    *csCustomerType = NULL;
        char    cCustomerType;
        char    *csTmp = NULL;
        char    *csUser = NULL;

        int     iMerchantType = NOT_FOUND;


DEBUGLOG(("Authorize\n"));


        if (GetField_CString(hRequest,"customer_type",&csCustomerType)) {
            cCustomerType = *csCustomerType;
DEBUGLOG(("Authorize::customer_type = [%c]\n", cCustomerType));
        } 
        else {
DEBUGLOG(("Authorize::customer_type not found!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::customer_type not found!!\n");
		iRet=INT_CUSTOMER_TYPE_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
        } 
	
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
		PutField_CString(hContext,"update_user",csUser);
	}


	if(GetField_CString(hRequest,"status",&csTmp)){
DEBUGLOG(("Authorize::status= [%s]\n",csTmp));
		PutField_CString(hContext,"status",csTmp);
	}
        else{
DEBUGLOG(("Authorize::status not found!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::status not found!!\n");
		iRet=INT_STATUS_NOT_FOUND;

		PutField_Int(hContext,"internal_error",iRet);
	}


	if(iRet==PD_OK){
                if (cCustomerType == PD_TYPE_CLIENT) {
                        // Client Account
                        if (GetField_CString(hRequest,"customer_id",&csTmp)) {
DEBUGLOG(("Authorize::client_id = [%s]\n", csTmp));
                                PutField_CString(hContext,"client_id",csTmp);
                        } 
                        else {
DEBUGLOG(("Authorize::client_id not found!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::client_id not found!!\n");
                                iRet=INT_CLIENT_ID_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
                        } 

                        if (iRet==PD_OK) { 
DEBUGLOG(("Authorize::Call Clients:Update\n")); 
                                DBObjPtr = CreateObj(DBPtr,"DBClients","Update");
                                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                        iRet = INT_ERR; 
                                }
                        }

                } 
                else if (cCustomerType == PD_TYPE_PSP) {
                        // PSP Account 
                        if(GetField_CString(hRequest,"customer_id",&csTmp)){
DEBUGLOG(("Authorize::psp_id = [%s]\n",csTmp));
                                PutField_CString(hContext,"psp_id",csTmp);
	                }
                        else{
DEBUGLOG(("Authorize::psp_id not found!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::psp_id not found!!\n");
                                iRet=INT_PSP_ID_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
	                }


                        if (iRet==PD_OK) { 
DEBUGLOG(("Authorize::Call PspDetail:Update\n")); 
                                DBObjPtr = CreateObj(DBPtr,"DBPspDetail","Update");
                                if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                        iRet = INT_ERR; 
                                }
                        }

                }
                else if (cCustomerType == PD_TYPE_MERCHANT) {
                        // Merchant Account  2 Type

                        if(GetField_CString(hRequest,"customer_id",&csTmp)){
DEBUGLOG(("Authorize::merchant_id = [%s]\n",csTmp));
                                PutField_CString(hContext,"merchant_id",csTmp);
	                }
                        else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::merchant_id not found!!\n");
                                iRet=INT_MERCHANT_ID_NOT_FOUND;

				PutField_Int(hContext,"internal_error",iRet);
	                }

                        if (iRet == PD_OK) {

                                if(GetField_CString(hRequest,"txn_ccy",&csTmp)){
DEBUGLOG(("Authorize::txn_ccy = [%s]\n",csTmp));
                                        PutField_CString(hContext,"ccy",csTmp);
                                        iMerchantType = FOUND;
                                }

                                if(GetField_CString(hRequest,"txn_country",&csTmp)){
DEBUGLOG(("Authorize::txn_country = [%s]\n",csTmp));
                                        PutField_CString(hContext,"country",csTmp);
                                        iMerchantType = FOUND;
                                }

                                if(GetField_CString(hRequest,"service_code",&csTmp)){
DEBUGLOG(("Authorize::service_code = [%s]\n",csTmp));
                                        PutField_CString(hContext,"service",csTmp);
                                        iMerchantType = FOUND;
                                }

                                if (iMerchantType == NOT_FOUND) {
DEBUGLOG(("Authorize::Call MerchDetail:UpdateMerchantStatus\n")); 
                                        DBObjPtr = CreateObj(DBPtr,"DBMerchDetail","UpdateMerchantStatus");
                                        if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                               iRet = INT_ERR; 
                                        }
                                }
                                else {
DEBUGLOG(("Authorize::Call MerchantBalAcct:UpdateMerchantBalAcctStatus\n")); 
                                        DBObjPtr = CreateObj(DBPtr,"DBMerchantBalAcct","UpdateMerchantBalAcctStatus");
                                        if((unsigned long) ((*DBObjPtr)(hContext))!=PD_OK){
                                               iRet = INT_ERR; 
                                        }
                                        

                                }
                        }
                } 
                else {
DEBUGLOG(("Authorize::customer_type invalid!!\n"));
ERRLOG("TxnMgtByUsCAS::Authorize::customer_type invalid!!\n");

			iRet = INT_ERR;
			PutField_Int(hContext,"internal_error",iRet);
                } 
        }

/*
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}
*/


DEBUGLOG(("TxnMgtByUsCAS Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
