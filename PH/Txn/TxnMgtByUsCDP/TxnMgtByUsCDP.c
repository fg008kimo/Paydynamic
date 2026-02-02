/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/07/28              [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "TxnMgtByUsCDP.h"
#include "myrecordset.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"
#include "dbutility.h"

static char cDebug;
OBJPTR(BO);
OBJPTR(DB);
OBJPTR(Txn);

void TxnMgtByUsCDP(char cdebug)
{
	cDebug = cdebug;
}

int Authorize(hash_t *hContext,
		const hash_t *hRequest,
		hash_t *hResponse)
{
	int	iRet = PD_OK;
	char	*csUser = NULL;
	char	*csCustomerTag = NULL;
	char	*csFrMerchantId = NULL;
	char	*csMerchantId = NULL;
	char	*csCustomerGroup = NULL;
	char	*csBlackList = NULL;
	int	iBlackList = PD_FALSE;

	hash_t *hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("Authorize::()\n"));

	if (GetField_CString(hRequest, "add_user", &csUser)) {
DEBUGLOG(("Authorize:: add_user = [%s]\n", csUser));
		PutField_CString(hRec, "create_user", csUser);
		PutField_CString(hRec, "update_user", csUser);
	} else {
		iRet = INT_USER_NOT_FOUND;
DEBUGLOG(("Authorize:: add_user not found!!!\n"));
ERRLOG("TxnMgtByUsCDP:: Authorize:: add_user not found!!!\n");
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (GetField_CString(hRequest, "fr_merchant_id", &csFrMerchantId)) {
DEBUGLOG(("Authorize:: From Merchant ID = [%s]\n", csFrMerchantId));
	} else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
DEBUGLOG(("Authorize:: From Merchant ID not found!!!\n"));
ERRLOG("TxnMgtByUsCDP:: Authorize:: From Merchant ID not found!!!\n");
		PutField_Int(hContext, "internal_error",iRet);
	}

	if (GetField_CString(hRequest, "merchant_id", &csMerchantId)) {
DEBUGLOG(("Authorize:: Merchant ID = [%s]\n", csMerchantId));
		PutField_CString(hRec, "merchant_id", csMerchantId);
	} else {
		iRet = INT_MERCHANT_ID_NOT_FOUND;
DEBUGLOG(("Authorize:: Merchant ID not found!!!\n"));
ERRLOG("TxnMgtByUsCDP:: Authorize:: Merchant ID not found!!!\n");
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (GetField_CString(hRequest, "cust_grp", &csCustomerGroup)) {
DEBUGLOG(("Authorize:: Customer Segment = [%s]\n", csCustomerGroup));
	} else {
		iRet = INT_CUSTOMER_SEGMENT_NOT_FOUND;
DEBUGLOG(("Authorize:: Customer Segment not found!!!\n"));
ERRLOG("TxnMgtByUsCDP:: Authorize:: Customer Segment not found!!!\n");
		PutField_Int(hContext, "internal_error", iRet);
	}

	if (iRet == PD_OK) {
		if (!GetField_CString(hRequest, "cust_tag", &csCustomerTag)) {
			iRet = INT_INVALID_TXN;
DEBUGLOG(("Authorize:: customer_tag not found!!!\n"));
DEBUGLOG(("TxnMgtByUsCDP:: Authorize:: customer_tag not found!!!\n"));
			PutField_Int(hContext, "internal_error", iRet);
		} else {
DEBUGLOG(("Authorize:: customer_tag = [%s]\n", csCustomerTag));
			DBObjPtr = CreateObj(DBPtr, "DBCustomerGroupMerchant", "FindMerchant");
			if ((unsigned long)(DBObjPtr)(csMerchantId) != FOUND) {
				iRet = INT_INVALID_MERCH_ID;
DEBUGLOG(("Authorize:: Merchant ID [%s] is invalid!!!\n", csMerchantId));
ERRLOG("TxnMgtByUsCDP:: Authorize:: Merchant ID [%s] is invalid!!!\n", csMerchantId);
				PutField_Int(hContext, "internal_error", iRet);
			}
		}
	}

	if (iRet == PD_OK) {
		if (GetField_CString(hRequest, "blacklist_enable", &csBlackList)) {
			iBlackList = atoi(csBlackList);
DEBUGLOG(("Authorize:: Blacklist Enable = [%d]\n", iBlackList));
			if (csBlackList != NULL) {
/* Check merchant_id blacklist control is open or not */
				DBObjPtr = CreateObj(DBPtr, "DBCustomerBlackList", "GetMerchBlklstCtl");
				if ((unsigned long)(DBObjPtr)(csMerchantId, csCustomerTag) != PD_TRUE) {
					iRet = INT_MERCH_ID_BLKLST_DISABLED;
DEBUGLOG(("Authorize:: The selected Merchant ID does not support blacklist setting!!!\n"));
ERRLOG("TxnMgtByUsCDP:: Authorize:: The selected Merchant ID does not support blacklist setting!!!\n");				
					PutField_Int(hContext, "internal_error", iRet);
				}
			}
		}			
	}

	if (iRet == PD_OK) {
		PutField_CString(hRec, "customer_group", csCustomerGroup);
		PutField_CString(hRec, "customer_tag", csCustomerTag);
DEBUGLOG(("Authorize:: new group [%s] for [%s][%s]\n", csCustomerGroup, csMerchantId, csCustomerTag));
		DBObjPtr = CreateObj(DBPtr, "DBCustomerGroupDetail", "Add");
		iRet = (unsigned long)(DBObjPtr)(hRec);
DEBUGLOG(("Authorize:: iRet = [%d] new group [%s] for [%s][%s]\n", iRet, csCustomerGroup, csMerchantId, csCustomerTag));
		if (iBlackList) {
			PutField_Int(hRec, "disabled", 0);
			DBObjPtr = CreateObj(DBPtr, "DBCustomerBlackList", "CustBlklstAdd");
			iRet = (unsigned long)(DBObjPtr)(hRec);
DEBUGLOG(("Authorize:: Customer Blacklist add succeed[%d]\n", iRet));
		}
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("Authorize:: Normal Exit() iRet = [%d]\n", iRet));
	return iRet;
}

