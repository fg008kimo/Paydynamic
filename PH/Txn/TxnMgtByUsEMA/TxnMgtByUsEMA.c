/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/06              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsEMA.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


char cDebug;
OBJPTR(DB);


void TxnMgtByUsEMA(char    cdebug)
{
        cDebug = cdebug;
}

int     Authorize(hash_t* hContext,
                        hash_t* hRequest,
                        hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csTmp = NULL;

	char	*csTxnSeq = NULL;
	char	*csMID = NULL;
	char	*csCountry = NULL;
	char	*csService = NULL;
	char	*csCcy = NULL;
	char	*csFunctType = NULL;

	char	cType;

	char    csCmd[PD_TMP_BUF_LEN*2 + 1];


	/*** For Email to Admin ***/
DEBUGLOG(("Authorize\n"));

	/** for indicate use which method, T-txn_Id; A-BalAcct **/
	if (GetField_CString(hRequest, "type", &csTmp)) {
		cType = csTmp[0];
DEBUGLOG(("Authorize:: type = [%c]\n", cType));
	} else {
		if (GetField_Char(hContext, "type", &cType)) {
DEBUGLOG(("Authorize:: type = [%c]\n", cType));
		} else {
DEBUGLOG(("Authorize ::get type fail\n"));
ERRLOG("TxnMgtByUsEMA:: Authorize:: get type fail!\n");
			iRet = INT_ERR;
			PutField_Int(hContext, "internal_error", iRet);
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hContext, "ema_funct_type", &csFunctType)) {
DEBUGLOG(("Authorize:: ema_funct_type = [%s]\n", csFunctType));
		} else {
			if (GetField_CString(hRequest, "ema_funct_type", &csFunctType)) {
DEBUGLOG(("Authorize:: ema_funct_type (hRequest) = [%s]\n", csFunctType));
			}
			else {
DEBUGLOG(("Authorize ::get email funct type fail\n"));
ERRLOG("TxnMgtByUsEMA:: Authorize:: get email funct type fail!\n");
				iRet = INT_ERR;
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	if (iRet == PD_OK) {
		if (cType == 'T') {
			if (GetField_CString(hRequest, "org_txn_seq", &csTxnSeq)) {
DEBUGLOG(("Authorize:: org_txn_seq = [%s]\n", csTxnSeq));
			} else {
        			if(GetField_CString(hContext,"txn_seq",&csTxnSeq)){
DEBUGLOG(("Authorize:: txn_seq = [%s]\n", csTxnSeq));
				} else {
DEBUGLOG(("Authorize ::get txn_seq fail\n"));
ERRLOG("TxnMgtByUsEMA:: Authorize:: get txn_seq fail!\n");
					iRet = INT_TXN_ID_MISSING;
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
			if (iRet == PD_OK) {
				sprintf(csCmd, "send_email_alert_to_admin.sh %s %s %s %s %s %s", csTxnSeq, 
												 PD_SYS_PARTY_ID,
												 "00",
												 PD_DEFAULT_SERVICE,
                       	                                					 PD_CCY_ISO_CNY,
												 csFunctType);
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
				system(csCmd);
			}

		} else if (cType == 'A') {

			if(GetField_CString(hRequest,"merchant_id",&csMID)) {
DEBUGLOG(("Authorize:: merchant_id = [%s]\n", csMID));
			} else {
DEBUGLOG(("Authorize ::get merchant_id fail\n"));
ERRLOG("TxnMgtByUsEMA:: Authorize:: get merchant_id fail!\n");
				iRet = INT_MERCHANT_ID_NOT_FOUND;
				PutField_Int(hContext, "internal_error", iRet);
			}

			if(GetField_CString(hRequest,"txn_country",&csCountry)){
DEBUGLOG(("Authorize:: country= [%s]\n",csCountry));
        		} else{
DEBUGLOG(("Authorize::country not found!!\n"));
ERRLOG("TxnMgtByUsEMA::Authorize::country not found!!\n");
				iRet=INT_TXN_COUNTRY_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if(GetField_CString(hRequest,"service_code",&csService)){
DEBUGLOG(("Authorize:: sevice= [%s]\n",csService));
			}
			else{
DEBUGLOG(("Authorize::service not found!!\n"));
ERRLOG("TxnMgtByUsEMA::Authorize::service not found!!\n");
		                iRet=INT_SERVICE_CODE_MISSING;
				PutField_Int(hContext,"internal_error",iRet);
			}		


			if (GetField_CString(hRequest, "txn_ccy", &csCcy)) {
DEBUGLOG(("Authorize:: txn_ccy = [%s]\n", csCcy));
			} else {
DEBUGLOG(("Authorize::ccy not found!!\n"));
ERRLOG("TxnMgtByUsRAU::Authorize::ccy not found!!\n");
				iRet=INT_CURRENCY_CODE_NOT_FOUND;
				PutField_Int(hContext,"internal_error",iRet);
			}

			if (iRet == PD_OK) {
				sprintf(csCmd, "send_email_alert_to_admin.sh %s %s %s %s %s %s", "0000000000000000", 
												 csMID,
												 csCountry,
												 csService,
                       	                                					 csCcy,
												 csFunctType);
DEBUGLOG(("Authorize:: command = [%s]\n", csCmd));
				system(csCmd);
			}
		}
	}


DEBUGLOG(("TxnMgtByUsEMA Normal Exit() iRet = [%d]\n",iRet));
        return iRet;
}


