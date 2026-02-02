/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/21              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMmcByUsIBL.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"

char cDebug;
OBJPTR(DB);
OBJPTR(BO);

void TxnMmcByUsIBL(char    cdebug)
{
	cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                  const hash_t* hRequest,
                        hash_t* hResponse)
{

	int	iRet = PD_OK;

	char	*csPartyType = NULL;
	char	*csPartyId = NULL;
	char	*csCcy = NULL;
	/*char	*csTmp = NULL;*/

	double	dBalance = 0.0;

DEBUGLOG(("TxnMmcByUsIBL::Authorize\n"));

/* party_type */
	if(GetField_CString(hRequest, "pty_type", &csPartyType)) {
DEBUGLOG(("Authorize::party_type= [%s]\n",csPartyType));

		if (strcmp(csPartyType, PD_MMS_PARTY_MB) && (strcmp(csPartyType, PD_MMS_PARTY_BANK))) {
DEBUGLOG(("Authorize::party_type invalid!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::party_type invalid!!\n");
			iRet=INT_INVALID_PARTY_TYPE;

		}
	}
	else {
DEBUGLOG(("Authorize::party_type not found!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::party_type not found!!\n");
		iRet=INT_PARTY_TYPE_NOT_FOUND;

	}

/*party_id */
	if(GetField_CString(hRequest, "pty_id", &csPartyId)) {
DEBUGLOG(("Authorize::party_id= [%s]\n",csPartyId));
	}
	else {
DEBUGLOG(("Authorize::party_id not found!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::party_id not found!!\n");
		iRet=INT_PARTY_ID_NOT_FOUND;
	}

/* ccy */
	if(GetField_CString(hRequest, "txn_ccy", &csCcy)) {
DEBUGLOG(("Authorize::ccy = [%s]\n",csCcy));
	}
	else {
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::ccy not found!!\n");
		iRet=INT_CURRENCY_CODE_NOT_FOUND;
	}

	/* if validation find error need to commit */
	if(iRet!=PD_OK){
		PutField_Int(hContext,"internal_error",iRet);
	}


	if (iRet == PD_OK) {
		if (!strcmp(csPartyType, PD_MMS_PARTY_MB)) {
		/* Get MB Balance */
DEBUGLOG(("Authorize::Call DBMmsMBBalance: GetBalance\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBMmsMBBalance","GetBalance");
	                if((unsigned long)((*DBObjPtr)(csPartyId, csCcy, hContext)) == PD_OK) {
				if (GetField_Double(hContext, "balance", &dBalance))  {
DEBUGLOG(("Authorize::DBMmsMBBlance:Bal=[%lf]\n", dBalance));
					PutField_Double(hResponse, "bal", dBalance);
				}
			}
			else {
DEBUGLOG(("Authorize::DBMmsMBBalance:GetBalance failed!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::DBMmsMBBalance:GetBalance failed!!\n");
				iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
			}
		}
		else if (!strcmp(csPartyType, PD_MMS_PARTY_BANK)) {
		/* Get Bank Balance */
DEBUGLOG(("Authorize::Call DBMmsBankBalance: GetBalance\n"));
                        DBObjPtr = CreateObj(DBPtr,"DBMmsBankBalance","GetBalance");
                        if((unsigned long)((*DBObjPtr)(csPartyId, csCcy, hContext)) == PD_OK) {
                                if (GetField_Double(hContext, "balance", &dBalance))  {
DEBUGLOG(("Authorize::DBMmsBankBlance:Bal=[%lf]\n", dBalance));
                                        PutField_Double(hResponse, "bal", dBalance);
                                }
                        }
                        else {
DEBUGLOG(("Authorize::DBMmsBankBalance:GetBalance failed!!\n"));
ERRLOG("TxnMmcByUsIBL::Authorize::DBMmsBankBalance:GetBalance failed!!\n");
                                iRet = INT_ERR;
				PutField_Int(hContext,"internal_error",iRet);
                        }
		}
	}



DEBUGLOG(("TxnMmcByUsIBL Normal Exit() iRet = [%d]\n",iRet));
	return iRet;
}
