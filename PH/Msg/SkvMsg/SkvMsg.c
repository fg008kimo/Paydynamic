/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/01/23              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SkvMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#define __USE_XOPEN
#include <time.h>

char cDebug;


struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};

OBJPTR(DB);

void SkvMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csPtr = NULL;
	char	*csBuf;
	double	dTmp;
	char	*csMethod = NULL;
	char	cTmp;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");

// payKey
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "payKey");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("payKey = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

// orderPrice
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			//sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
			sprintf((char*)csTmpAmt, "%.2f", dTmp);
			strcat((char*)outMsg, "orderPrice");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("orderPrice = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
		}

// outTradeNo
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "outTradeNo");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("outTradeNo = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_seq is missing\n"));
		}

// productType
		strcat((char*)outMsg, "productType");
		strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
		strcat((char*)outMsg, MY_SKV_PRODUCT_TYPE);
		strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("productType = [%s]\n", MY_SKV_PRODUCT_TYPE));

// orderTime
		if (GetField_CString(hIn, "local_tm_date", &csTmp)) {
			char *csTmp2 = NULL;
			char csRaw[PD_DATETIME_LEN + 1];
			if (GetField_CString(hIn, "local_tm_time", &csTmp2)) {
				sprintf(csRaw, "%s%s", csTmp, csTmp2);
				strcat((char*)outMsg, "orderTime");
				strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
				strcat((char*)outMsg, csRaw);
				strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("orderTime = [%s]\n", csRaw));
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("***local_tm_time is missing\n"));
			}
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***local_tm_date is missing\n"));
		}

// productName
		if (GetField_CString(hIn, "psp_product_name", &csTmp)) {
			strcat((char*)outMsg, "productName");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("productName = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_product_name is missing\n"));
		}

// orderIp
		if (GetField_CString(hIn, "user_ip", &csTmp)) {
			strcat((char*)outMsg, "orderIp");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("orderIp = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***user_ip is missing\n"));
		}

// bankCode
		if (GetField_CString(hIn, "bank_code", &csTmp)) {
			strcat((char*)outMsg, "bankCode");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("bankCode = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***bank_code is missing\n"));
		}

// bankAccountType
		if (GetField_Char(hIn, "card_type", &cTmp)) {
DEBUGLOG(("card_type = [%c]\n", cTmp));
			if (cTmp == PD_DEPOSIT_CARD_TYPE_DEBIT) {
				strcat((char*)outMsg, "bankAccountType");
				strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
				strcat((char*)outMsg, MY_SKV_DEBIT_ACCT);
				strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("bankAccountType = [%s]\n", MY_SKV_DEBIT_ACCT));
			} else if (cTmp == PD_DEPOSIT_CARD_TYPE_CREDIT) {
				strcat((char*)outMsg, "bankAccountType");
				strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
				strcat((char*)outMsg, MY_SKV_CREDIT_ACCT);
				strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("bankAccountType = [%s]\n", MY_SKV_CREDIT_ACCT));
			}
		} else {
			strcat((char*)outMsg, "bankAccountType");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, MY_SKV_DEBIT_ACCT);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("DEFAULT bankAccountType = [%s]\n", MY_SKV_DEBIT_ACCT));
		}

// returnUrl
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "returnUrl");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("returnUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
		}

// notifyUrl
		if (GetField_CString(hIn, "return_url_only", &csTmp)) {
			strcat((char*)outMsg, "notifyUrl");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_SKV_TOKEN);
DEBUGLOG(("notifyUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
		}

// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_SKV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
DEBUGLOG(("sign = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
		}

// url_method
		if (GetField_CString(hIn, "url_method", &csMethod)) {
DEBUGLOG(("url_method = [%s]\n", csMethod));
		}
		else
			csMethod = strdup("");

DEBUGLOG(("outmsg = [%s]\n", outMsg));
		base64_encode(outMsg, strlen((char*)outMsg), csBuf, PD_MAX_BUFFER);
DEBUGLOG(("after encode\n"));
		outMsg[0] = '\0';
		strcat((char*)outMsg, "redirect_url");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csBuf);
		strcat((char*)outMsg, MY_SKV_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_SKV_TOKEN);
		strcat((char*)outMsg, "ret_status=0");
DEBUGLOG(("outMsg = [%s]\n", outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***redirect_url is missing\n"));
	}

DEBUGLOG(("FormatMsg:: normal exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t 	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_SKV_TOKEN, MY_SKV_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)inMsg);

// orderPrice
		if (GetField_CString(hRec, "orderPrice", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("orderPrice:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderPrice:txn_amt not found\n"));
		}

// outTradeNo
		if (GetField_CString(hRec, "outTradeNo", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("outTradeNo:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("outTradeNo:txn_seq not found\n"));
		}

// payKey
		if (GetField_CString(hRec, "payKey", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("payKey:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("payKey:psp_merchant_id not found\n"));
		}

// successTime
		if (GetField_CString(hRec, "successTime", &csPtr)) {
			char csTxnDate[PD_DATE_LEN + 1];
			strncpy(csTxnDate, csPtr, PD_DATE_LEN);
			csTxnDate[PD_DATE_LEN] = '\0';

			PutField_CString(hOut, "fundin_date", csPtr);
			PutField_CString(hOut, "txn_date", csTxnDate);
DEBUGLOG(("successTime:fundin_date = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("successTime:fundin_date not found\n"));
		}

// tradeStatus
		if (GetField_CString(hRec, "tradeStatus", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("tradeStatus:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("tradeStatus:status not found\n"));
		}

// trxNo
		if (GetField_CString(hRec, "trxNo", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("trxNo:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("trxNo:tid not found\n"));
		}

// sign
		if (GetField_CString(hRec, "sign", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("sign:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("sign:sign not found\n"));
		}
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return	iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	double	dTmp;
	char	cTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// bankAccountType
	if (GetField_Char(hIn, "card_type", &cTmp)) {
DEBUGLOG(("card_type = [%c]\n", cTmp));
		if (cTmp == PD_DEPOSIT_CARD_TYPE_DEBIT) {
			strcat((char*)csBuf, "bankAccountType");
			strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
			strcat((char*)csBuf, "PRIVATE_DEBIT_ACCOUNT");
			strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("bankAccountType = [%s]\n", "PRIVATE_DEBIT_ACCOUNT"));
		} else if (cTmp == PD_DEPOSIT_CARD_TYPE_CREDIT) {
			strcat((char*)csBuf, "bankAccountType");
			strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
			strcat((char*)csBuf, MY_SKV_CREDIT_ACCT);
			strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("bankAccountType = [%s]\n", MY_SKV_CREDIT_ACCT));
		} else {
			strcat((char*)csBuf, "bankAccountType");
			strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
			strcat((char*)csBuf, MY_SKV_DEBIT_ACCT);
			strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("DEFAULT bankAccountType = [%s]\n", MY_SKV_DEBIT_ACCT));
		}
	}

// bankCode
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)csBuf, "bankCode");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("bankCode = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
	}

// notifyUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "notifyUrl");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("notifyUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

// orderIp
	if (GetField_CString(hIn, "user_ip", &csPtr)) {
		strcat((char*)csBuf, "orderIp");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("orderIp = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("user_ip is missing\n"));
	}

// orderPrice
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		//sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "orderPrice");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("orderPrice = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// orderTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN + 1];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat((char*)csBuf, "orderTime");
			strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
			strcat((char*)csBuf, csRaw);
			strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("orderTime = [%s]\n", csRaw));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("local_tm_time is missing\n"));
		}
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("local_tm_date is missing\n"));
	}

// outTradeNo
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "outTradeNo");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("outTradeNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

// payKey
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "payKey");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("payKey = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// productName
	if (GetField_CString(hIn, "psp_product_name", &csPtr)) {
		strcat((char*)csBuf, "productName");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("productName = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_product_name is missing\n"));
	}

// productType
	strcat((char*)csBuf, "productType");
	strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
	strcat((char*)csBuf, MY_SKV_PRODUCT_TYPE);
	strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("productType = [%s]\n", MY_SKV_PRODUCT_TYPE));

// returnUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "returnUrl");
		strcat((char*)csBuf, MY_SKV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKV_TOKEN);
DEBUGLOG(("returnUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


void Insert2KVPair(struct key_value_pair k_v_pair[], int *iPairCnt, const char *inMsg, const char *FD)
{
	char *csTag;
	char *csValue;
	char *csTmp;
	char *p;

	csTmp = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
	strcpy(csTmp, inMsg);

	p = strstr(csTmp, FD);
	if (p) {
		if (strlen(p) > strlen(FD)) {
			csTag = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
			csValue = strdup(p + 1);
			memcpy(csTag, inMsg, strlen(inMsg) - strlen(p));
			csTag[strlen(inMsg) - strlen(p)] = '\0';
//DEBUGLOG(("Insert2KVPair:: iPairCnt = [%d], Tag = [%s], Value = [%s]\n", *iPairCnt, csTag, csValue));
			strcpy(k_v_pair[*iPairCnt].key, csTag);
			strcpy(k_v_pair[*iPairCnt].value, csValue);
			*iPairCnt = *iPairCnt + 1;
			free(csTag);
			csTag = NULL;
			free(csValue);
			csValue = NULL;
		}
	}
	free(csTmp);
	csTmp = NULL;
}


int Str2KVPair(struct key_value_pair k_v_pair[], int *iPairCnt, const char *inMsg, const char *DL, const char *FD)
{
	char *csBuf;
	char *p;

	int inLen = strlen(inMsg);
	csBuf = (char*) malloc (inLen + 1);
	memcpy(csBuf, inMsg, inLen);
	csBuf[inLen] = '\0';

	p = strtok(csBuf, DL);
	if (p != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d)
				p[strlen(p) - 1] = '\0';
			else
				p[strlen(p)] = '\0';
			Insert2KVPair(k_v_pair, iPairCnt, p, FD);
		}
	}

	while ((p = strtok(NULL, DL)) != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d)
				p[strlen(p) - 1] = '\0';
			else
				p[strlen(p)] = '\0';
			Insert2KVPair(k_v_pair, iPairCnt, p, FD);
		}
	}

//DEBUGLOG(("Str2KVPair:: iPairCnt = [%d]\n", *iPairCnt));

	free(csBuf);
	csBuf = NULL;
	return 0;
}


int string_sort_func(const void *a1, const void *b1)
{
	const char *a = (const char *)a1;
	const char *b = (const char *)b1;
	return(strcmp(a, b));
}


int BuildRspAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (GetField_CString(hIn, "in_msg", &inMsg)) {
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_SKV_TOKEN, MY_SKV_FIELD_TOKEN) == PD_OK) {
//DEBUGLOG(("iPairCnt = [%d]\n", iPairCnt));
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_SKV_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_SKV_TOKEN);
				}
			}
		}
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

