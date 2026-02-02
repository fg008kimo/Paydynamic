/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/09/15              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsGAB.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(BO);
OBJPTR(DB);

void TxnMgtByUsGAB(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{

        int     iRet = PD_OK;

	char	*csTmp;
	char	*csMerchantId;
        //char	csTxnCountry[PD_COUNTRY_LEN+1];
        char	*csTxnCountry = NULL;
	char	*csTxnCcy;
	char	*csServiceCode;
        char    *csDate;
        int     iDayOfWeek;
	double	dAvalBal=0.0;
	double	dActualBal=0.0;
	double	dFeeRate=0.0;
	char	cType;

	if(GetField_CString(hRequest,"ps_ind",&csTmp)){
		cType = csTmp[0];
DEBUGLOG(("Authorize::ps_ind = [%c]\n",cType));
	}

	if(GetField_CString(hRequest,"merchant_id",&csMerchantId)){
DEBUGLOG(("Authorize::merchant_id= [%s]\n",csMerchantId));
		PutField_CString(hContext,"merchant_id",csMerchantId);
	}
	else{
DEBUGLOG(("Authorize::merchant_id not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::merchant_id not found!!\n");
		iRet=INT_MERCHANT_ID_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"txn_ccy",&csTxnCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csTxnCcy));
		PutField_CString(hContext,"txn_ccy",csTxnCcy);
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
		PutField_CString(hContext,"service_code",csServiceCode);
	}
        else{
DEBUGLOG(("Authorize::service_code not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::service_code not found!!\n");
		iRet=INT_SERVICE_CODE_MISSING;

        } 

	if(GetField_CString(hRequest,"txn_country",&csTxnCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csTxnCountry));
		PutField_CString(hContext,"txn_country",csTxnCountry);
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::country not found!!\n");
                iRet=INT_TXN_COUNTRY_NOT_FOUND;

                /*
		DBObjPtr = CreateObj(DBPtr,"DBService","FindCountryByService");
		if ((unsigned long)(DBObjPtr)(csServiceCode,csTxnCountry) == FOUND) {
DEBUGLOG(("Authorize::txn_country2= [%s]\n",csTxnCountry));
			PutField_CString(hContext,"txn_country",csTxnCountry);
		}
		else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::country not found!!\n");
			iRet=INT_TXN_COUNTRY_NOT_FOUND;
		}
                */ 
	}


        if(!GetField_CString(hRequest,"update_date",&csDate)){
	        if(!GetField_CString(hContext,"PHDATE",&csDate)){
DEBUGLOG(("Authorize::update_date not found!!\n"));
ERRLOG("TxnMgtByUsGAB::Authorize::update_date not found!!\n");
			iRet=INT_ERR;
	        }
	}
	if(iRet==PD_OK){
DEBUGLOG(("Authorize::update_date= [%s]\n",csDate));
                        iDayOfWeek = day_of_week((const unsigned char *)csDate);
DEBUGLOG(("Authorize::iDayOfWeek= [%i]\n",iDayOfWeek));
       			PutField_Int(hContext,"day_of_week",iDayOfWeek);
        }


	if(iRet==PD_OK){
		if(cType == PD_TYPE_PAYOUT){
DEBUGLOG(("Authorize::Call BOBalance: GetAvalPayoutBalance\n"));
			BOObjPtr = CreateObj(BOPtr,"BOBalance","GetAvalPayoutBalance");
			if((unsigned long) ((*BOObjPtr)(hContext,hRequest,
                        	                        &dActualBal,&dAvalBal))!=PD_OK)
                        	iRet = INT_ERR;
                
			else{
				PutField_Double(hResponse,"aval_balance", dAvalBal); 
				PutField_Double(hResponse,"actual_balance", dActualBal); 
				GetField_Double(hContext,"approximate_fee_rate",&dFeeRate);
				PutField_Double(hResponse,"fee_rate", dFeeRate);
			}
		}
              	else{
			/////TODO: GetAvalSettBalance
DEBUGLOG(("Authorize::Call DBMerchantBalance: GetSettAvalBalance\n"));
			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetSettAvalBalanceInq");
			if((unsigned long) ((*DBObjPtr)(csMerchantId,
							csTxnCcy,
							csTxnCountry,
							csServiceCode,
							&dAvalBal)) != PD_OK) 
				iRet = INT_ERR;
			else {
				PutField_Double(hResponse, "aval_balance", dAvalBal);
			}
		}
	}


DEBUGLOG(("TxnMgtByUsGAB Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
