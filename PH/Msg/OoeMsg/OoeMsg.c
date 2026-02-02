/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/10/11              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OoeMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#define __USE_XOPEN
#include <time.h>
#include <json-c/json.h>

static char cDebug;


struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};

OBJPTR(DB);

void OoeMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csPtr = NULL;
	char	*csBuf;
	char	*csTmpBuf;
        char	*csTag;
        double	dTmp;
	char	*csMethod = NULL;

	char	csDateTime[PD_DATETIME_LEN * 2];
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	csTmpBuf = (char*) malloc (PD_TMP_BUF_LEN + 1);
        csTag = (char*) malloc (PD_TAG_LEN + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");
// inputCharset
		strcat((char*)outMsg, "inputCharset");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_INPUT_CHARSET);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("inputCharset = [%s]\n", MY_OOE_INPUT_CHARSET));

// pickupUrl
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "pickupUrl");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("pickupUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
		}

// receiveUrl
		if (GetField_CString(hIn, "return_url_only", &csTmp)) {
			strcat((char*)outMsg, "receiveUrl");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("receiveUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
		}

// version
		strcat((char*)outMsg, "version");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_VERSION);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("version = [%s]\n", MY_OOE_VERSION));

// language
		strcat((char*)outMsg, "language");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_LANGUAGE);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("language = [%s]\n", MY_OOE_LANGUAGE));

// signType
		strcat((char*)outMsg, "signType");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_SIGN_TYPE);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("signType = [%s]\n", MY_OOE_SIGN_TYPE));

// merchantId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "merchantId");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("merchantId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
		}

// orderNo
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "orderNo");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("orderNo = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
		}

// orderAmount
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
			//sprintf((char*)csTmpAmt, "%.2f", dTmp);
			strcat((char*)outMsg, "orderAmount");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("orderAmount = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
		}

// orderCurrency
		strcat((char*)outMsg, "orderCurrency");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_ORDER_CCY);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("orderCurrency = [%s]\n", MY_OOE_ORDER_CCY));

// orderDatetime
		if (GetField_CString(hIn, "local_tm_date", &csTmp)) {
			char *csTmp2 = NULL;
			if (GetField_CString(hIn, "local_tm_time", &csTmp2)) {
				sprintf(csDateTime, "%s%s", csTmp, csTmp2);
				strcat((char*)outMsg, "orderDatetime");
				strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
				strcat((char*)outMsg, csDateTime);
				strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("orderDatetime = [%s]\n", csDateTime));
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

// orderExpireDatetime
		if (GetField_CString(hIn, "psp_key_id", &csTmp)) {
			strcat((char*)outMsg, "orderExpireDatetime");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("orderExpireDatetime = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_key_id is missing\n"));
		}

// productName
		if (GetField_CString(hIn, "psp_key_uid", &csTmp)) {
			strcat((char*)outMsg, "productName");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("productName = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_key_uid is missing\n"));
		}

// productPrice
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			strcat((char*)outMsg, "productPrice");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("productPrice = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
		}

// productNum
		strcat((char*)outMsg, "productNum");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_PRODUCT_NUM);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("productNum = [%s]\n", MY_OOE_PRODUCT_NUM));

// payType
		strcat((char*)outMsg, "payType");
		strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OOE_PAYTYPE_EC);
		strcat((char*)outMsg, MY_OOE_TOKEN);
DEBUGLOG(("payType = [%s]\n", MY_OOE_PAYTYPE_EC));

// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
DEBUGLOG(("sign = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("sign is missing\n"));
		}

// TLG - Transaction Logging
		if (GetField_CString(hIn, "psp_id", &csTmp)) {
			int iDtlRet = PD_FALSE;
DEBUGLOG(("Call DBPspUrl::IsRedirectURL\n"));
			// Call DBPspUrl::IsRedirectURL
			DBObjPtr = CreateObj(DBPtr, "DBPspUrl", "IsRedirectURL");
			iDtlRet = ((unsigned long)(DBObjPtr)(csTmp));

			if (iDtlRet) {
DEBUGLOG(("  psp_id [%s] IsRedirectUrl = TRUE [%d]\n", csTmp, iDtlRet));

				if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("  Call DBDefTlgTagConvert:GetRandomTag\n"));
					DBObjPtr = CreateObj(DBPtr, "DBDefTlgTagConvert", "GetRandomTag");
					iDtlRet = ((unsigned long)(DBObjPtr)("txn_seq", csTag));

					if (iDtlRet == PD_OK) {
DEBUGLOG(("  org_tag [%s], new_tag [%s]\n", "txn_seq", csTag));
						base64_encode((unsigned char*)csTmp, strlen(csTmp), csTmpBuf, PD_TMP_BUF_LEN);
						strcat((char*)outMsg, MY_OOE_TOKEN);
						strcat((char*)outMsg, csTag);
						strcat((char*)outMsg, MY_OOE_FIELD_TOKEN);
						strcat((char*)outMsg, csTmpBuf);
					} else {
DEBUGLOG(("  Call FAILED!! Skip insert TLG log, iDtlRet = [%d]\n", iDtlRet));
					}
				} else {
DEBUGLOG(("  txn_seq NOT FOUND!! Skip insert TLG log\n"));
				}

DEBUGLOG(("  [%s] = [%s]\n", csTag, csTmp));
			} else {
DEBUGLOG(("  psp_id [%s] IsRedirectUrl = FALSE [%d]\n", csTmp, iDtlRet));
			}
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
		strcat((char*)outMsg, MY_OOE_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_OOE_TOKEN);
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
	FREE_ME(csTmpBuf);
	FREE_ME(csTag);
	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_OOE_TOKEN, MY_OOE_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)inMsg);

// merchantId
		if (GetField_CString(hRec, "merchantId", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("merchantId:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("merchantId:psp_merchant_id not found\n"));
		}

// mchtOrderId
		if (GetField_CString(hRec, "mchtOrderId", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("mchtOrderId:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("mchtOrderId:tid not found\n"));
		}

// orderNo
		if (GetField_CString(hRec, "orderNo", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("orderNo:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderNo:txn_seq not found\n"));
		}

// orderAmount
		if (GetField_CString(hRec, "orderAmount", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("orderAmount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderAmount:txn_amt not found\n"));
		}

// payDatetime
		if (GetField_CString(hRec, "payDatetime", &csPtr)) {
			char csTxnDate[PD_DATE_LEN + 1];
			strncpy(csTxnDate, csPtr, PD_DATE_LEN);
			csTxnDate[PD_DATE_LEN] = '\0';
			PutField_CString(hOut, "fundin_date", csPtr);
			PutField_CString(hOut, "txn_date", csTxnDate);
DEBUGLOG(("payDatetime:fundin_date = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("payDatetime:fundin_date not found\n"));
		}

// payResult
		if (GetField_CString(hRec, "payResult", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("payResult:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("payResult:status not found\n"));
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
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char	csDateTime[PD_DATETIME_LEN * 2];
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// inputCharset
	strcat((char*)csBuf, "inputCharset");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_INPUT_CHARSET);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("inputCharset = [%s]\n", MY_OOE_INPUT_CHARSET));

// language
	strcat((char*)csBuf, "language");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_LANGUAGE);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("language = [%s]\n", MY_OOE_LANGUAGE));

// merchantId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merchantId");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("merchantId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// orderAmount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		//sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "orderAmount");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("orderAmount = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// orderCurrency
	strcat((char*)csBuf, "orderCurrency");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_ORDER_CCY);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("orderCurrency = [%s]\n", MY_OOE_ORDER_CCY));

// orderDatetime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csDateTime, "%s%s", csPtr, csPtr2);
			strcat((char*)csBuf, "orderDatetime");
			strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
			strcat((char*)csBuf, csDateTime);
			strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("orderDatetime = [%s]\n", csDateTime));
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

// orderExpireDatetime
	if (GetField_CString(hIn, "psp_key_id", &csPtr)) {
		strcat((char*)csBuf, "orderExpireDatetime");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("orderExpireDatetime = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_key_id is missing\n"));
	}

// orderNo
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "orderNo");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("orderNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

// payType
	strcat((char*)csBuf, "payType");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_PAYTYPE_EC);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("payType = [%s]\n", MY_OOE_PAYTYPE_EC));

// pickupUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "pickupUrl");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("pickupUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
	}

// productName
	if (GetField_CString(hIn, "psp_key_uid", &csPtr)) {
		strcat((char*)csBuf, "productName");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("productName = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_key_uid is missing\n"));
	}

// productNum
	strcat((char*)csBuf, "productNum");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_PRODUCT_NUM);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("productNum = [%s]\n", MY_OOE_PRODUCT_NUM));

// productPrice
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		strcat((char*)csBuf, "productPrice");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("productPrice = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// receiveUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "receiveUrl");
		strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("receiveUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

// signType
	strcat((char*)csBuf, "signType");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_SIGN_TYPE);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("signType = [%s]\n", MY_OOE_SIGN_TYPE));

// version
	strcat((char*)csBuf, "version");
	strcat((char*)csBuf, MY_OOE_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OOE_VERSION);
	strcat((char*)csBuf, MY_OOE_TOKEN);
DEBUGLOG(("version = [%s]\n", MY_OOE_VERSION));

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
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_OOE_TOKEN, MY_OOE_FIELD_TOKEN) == PD_OK) {
//DEBUGLOG(("iPairCnt = [%d]\n", iPairCnt));
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					// exclude null value
					if (strcmp(k_v_pair[iTmp].value, "null")) {
						strcat(csBuf, k_v_pair[iTmp].key);
						strcat(csBuf, MY_OOE_FIELD_TOKEN);
						strcat(csBuf, k_v_pair[iTmp].value);
						strcat(csBuf, MY_OOE_TOKEN);
					}
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

