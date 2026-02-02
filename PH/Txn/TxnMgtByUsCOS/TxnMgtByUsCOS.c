/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/23              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCOS.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);

void TxnMgtByUsCOS(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp;
	char	*csCustomerGroup;
	char	*csCcy;
	char	*csCountry;
	char	*csServiceCode;
	char	*csUser;
	char	*csChannel = strdup("");
	char	cType;
	double	dAmt=0.0;
	double	dTmp=0.0;

	if(GetField_CString(hRequest,"cust_grp",&csCustomerGroup)){
DEBUGLOG(("Authorize::customer_group= [%s]\n",csCustomerGroup));
	}
	else{
DEBUGLOG(("Authorize::customer_group not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::customer_group not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	
	if(GetField_CString(hRequest,"add_user",&csUser)){
DEBUGLOG(("Authorize::add_user= [%s]\n",csUser));
	}

	if(GetField_CString(hRequest,"channel",&csChannel)){
DEBUGLOG(("Authorize::channel= [%s]\n",csChannel));
	}
	else{
		csChannel = strdup(PD_CHANNEL_WEB);
DEBUGLOG(("Authorize::channel (default)= [%s]\n",csChannel));
	}

	if(GetField_CString(hRequest,"txn_ccy",&csCcy)){
DEBUGLOG(("Authorize::txn_ccy= [%s]\n",csCcy));
	}
	else{
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"txn_country",&csCountry)){
DEBUGLOG(("Authorize::txn_country= [%s]\n",csCountry));
	}
	else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::country not found!!\n");
		iRet=INT_TXN_COUNTRY_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_CString(hRequest,"service_code",&csServiceCode)){
DEBUGLOG(("Authorize::sevice_code= [%s]\n",csServiceCode));
	}

	if(GetField_CString(hRequest,"type",&csTmp)){ ///Credit = 'C', Debit = 'D'
		cType = csTmp[0];
DEBUGLOG(("Authorize::type = [%c]\n",cType));
	}
	else{
DEBUGLOG(("Authorize:: type not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::type not found!!\n");
		iRet=INT_INVALID_TXN;
		PutField_Int(hContext,"internal_error",iRet);
	}

	if(GetField_Double(hContext,"txn_amt",&dTmp)){
		if(cType == PD_ADJ_TYPE_CREDIT)
			dAmt = dTmp;
		else
			dAmt = (-1)*dTmp;
DEBUGLOG(("Authorize::txn_amt= [%f]\n",dAmt));
	}
	else{
DEBUGLOG(("Authorize::txn_amt not found!!\n"));
ERRLOG("TxnMgtByUsCOS::Authorize::txn_amt not found!!\n");
		iRet=INT_PAY_AMOUNT_NOT_FOUND;
		PutField_Int(hContext,"internal_error",iRet);
	}


	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBCustomerGroupOffsetCount:OffsetCreate\n"));
		DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupOffsetCount","OffsetCreate");
		iRet = (unsigned long) (*DBObjPtr)(csCustomerGroup,
						   csCountry,
						   csChannel,
						   csServiceCode,
						   csCcy,
						   dAmt,
						   csUser);
	}

	if(iRet==PD_OK){
DEBUGLOG(("Authorize::Call DBCustomerGroupOffsetLog:Add\n"));
		DBObjPtr = CreateObj(DBPtr,"DBCustomerGroupOffsetLog","Add");
		iRet = (unsigned long) (*DBObjPtr)(csCustomerGroup,
						   csCountry,
						   csChannel,
						   csServiceCode,
						   csCcy,
						   dAmt,
						   csUser);
	}


	FREE_ME(csChannel);
DEBUGLOG(("TxnMgtByUsCOS Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
