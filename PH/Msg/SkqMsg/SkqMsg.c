/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/01/12		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SkqMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "ObjPtr.h"
#define __USE_XOPEN
#include <time.h>
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include <json-c/json.h>
#include <openssl/rsa.h>

#define PD_REMARK1		"PAY"
#define PD_REMARK2		"RESERVED"
#define PD_REMARK3		"RESERVED"
#define PD_SUCCESS_STATUS	"1000"

OBJPTR(DB);
OBJPTR(BO);
char cDebug;


struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};


void SkqMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csBuf;
	char	*csCodeURL;
	int	iTmp;
	int	iTmpRet;

	hash_t	*hLog;
	hLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hLog, 0);

DEBUGLOG(("FormatMsg()\n"));

	outMsg[0] = '\0';

/* return_code */
	if (GetField_CString(hIn, "return_code", &csPtr)) {
DEBUGLOG(("return_code = [%s]\n", csPtr));
		strcat((char*)outMsg, "return_code");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)csPtr, strlen((char*)csPtr), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
		FREE_ME(csCodeURL);
	} else {
DEBUGLOG(("code_url is missing\n"));
	}

/* txn_seq */
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("txn_seq = [%s]\n", csPtr));
		DBObjPtr = CreateObj(DBPtr, "DBTxnQrRequestLog", "GetByTxnId");
		iTmpRet = (unsigned long int)(*DBObjPtr)(csPtr, hLog);
		if (iTmpRet == PD_FOUND) {
/* time_init */
			if (GetField_CString(hLog, "qrcode_init_timestamp", &csPtr)) {
DEBUGLOG(("time_init = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_init");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_SKQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_SKQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_SKQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_SKQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_SKQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
			} else {
DEBUGLOG(("time_curr is missing\n"));
			}
		}
	} else {
DEBUGLOG(("txn_seq is missing\n"));
	}

DEBUGLOG(("outmsg = [%s]\n", outMsg));

	csBuf = (char*) malloc (PD_MAX_BUFFER + 1);
	memset(csBuf, 0, sizeof(csBuf));
	base64_encode(outMsg, strlen((char*)outMsg), csBuf, PD_MAX_BUFFER);
	outMsg[0] = '\0';
	strcat((char*)outMsg, "qr_parameter");
	strcat((char*)outMsg, "=");
	strcat((char*)outMsg, csBuf);
	FREE_ME(csBuf);
	*outLen = strlen((const char*)outMsg);

DEBUGLOG(("FormatMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatMsg() Exit\n"));

	FREE_ME(csPtr);
	hash_destroy(hLog);
	FREE_ME(hLog);

	return iRet;
}


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	double	dTmp;
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// notifyUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "notifyUrl");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("notifyUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

// orderIp
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)csBuf, "orderIp");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("orderIp = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("org_ip_addr is missing\n"));
	}

// orderPrice
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		//sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "orderPrice");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
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
			strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
			strcat((char*)csBuf, csRaw);
			strcat((char*)csBuf, MY_SKQ_TOKEN);
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
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, "outTradeNo");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("outTradeNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("order_num is missing\n"));
	}

// payKey
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "payKey");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("payKey = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// productName
	if (GetField_CString(hIn, "psp_product_name", &csPtr)) {
		strcat((char*)csBuf, "productName");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("productName = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_product_name is missing\n"));
	}

// productType
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)csBuf, "productType");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "SKQ", "CN", csOutBankCode)) {
DEBUGLOG(("productType = [%s]\n", csOutBankCode));
			strcat((char*)csBuf, csOutBankCode);
		} else {
			iRet = PD_ERR;
DEBUGLOG(("no bank code mapping\n"));
		}
		strcat((char*)csBuf, MY_SKQ_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
	}

// returnUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "returnUrl");
		strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_SKQ_TOKEN);
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


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_SKQ_TOKEN, MY_SKQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)inMsg);

// payKey
		if (GetField_CString(hRec, "payKey", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("payKey:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("payKey:psp_merchant_id not found\n"));
		}

// outTradeNo
		if (GetField_CString(hRec, "outTradeNo", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("outTradeNo:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("outTradeNo:txn_seq not found\n"));
		}

// orderPrice
		if (GetField_CString(hRec, "orderPrice", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("orderPrice:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderPrice:txn_amt not found\n"));
		}

// tradeStatus
		if (GetField_CString(hRec, "tradeStatus", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("tradeStatus:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("tradeStatus:status not found\n"));
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

DEBUGLOG(("BreakDownMsg() Exit\n"));
	return iRet;
}


int initReplyFromRequest(const hash_t *hRequest, hash_t *hResponse)
{
	int iRet = PD_OK;

	return iRet;
}


int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;
	double	dTmp;
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0] = '\0';

/* psp_url */
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("psp_url = [%s]\n", csURL));
DEBUGLOG(("request_function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);
DEBUGLOG(("psp_url = [%s]\n", csBuf));
		}

		sprintf((char*)outMsg, "%0*d", PD_WEB_HEADER_LEN_LEN, (int)strlen(csBuf));
DEBUGLOG(("outMsg = [%s]\n", outMsg));
		strcat((char*)outMsg, csBuf);
	}
	FREE_ME(csBuf);

// payKey
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)outMsg, "payKey");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("payKey = [%s]\n", csPtr));
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
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csTmpAmt);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("orderPrice = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
	}

// outTradeNo
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)outMsg, "outTradeNo");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("outTradeNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***order_num is missing\n"));
	}

// productType
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)outMsg, "productType");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "SKQ", "CN", csOutBankCode)) {
DEBUGLOG(("productType = [%s]\n", csOutBankCode));
			strcat((char*)outMsg, csOutBankCode);
		} else {
			iRet = PD_ERR;
DEBUGLOG(("no bank code mapping\n"));
		}
		strcat((char*)outMsg, MY_SKQ_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
	}

// orderTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN + 1];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat((char*)outMsg, "orderTime");
			strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
			strcat((char*)outMsg, csRaw);
			strcat((char*)outMsg, MY_SKQ_TOKEN);
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
	if (GetField_CString(hIn, "psp_product_name", &csPtr)) {
		strcat((char*)outMsg, "productName");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, url_encode(csPtr));
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("productName = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_product_name is missing\n"));
	}

// orderIp
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)outMsg, "orderIp");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("orderIp = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***org_ip_addr is missing\n"));
	}

// returnUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)outMsg, "returnUrl");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("returnUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
	}

// notifyUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "notifyUrl");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_SKQ_TOKEN);
DEBUGLOG(("notifyUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}

// sign
	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_SKQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
DEBUGLOG(("sign = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);

	return iRet;
}


int BreakDownInitRspMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csReturnCode;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	struct json_object *jobj;
	enum json_type type;

	jobj = json_tokener_parse((const char *)inMsg);
	if (jobj != NULL) {
		json_object_object_foreach(jobj, key, val) {
			type = json_object_get_type(val);
			switch (type) {
				case json_type_string:
					if (strlen(json_object_get_string(val)) > 0)
						PutField_CString(hRec, key, json_object_get_string(val));
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}

		if (GetField_CString(hRec, "resultCode", &csReturnCode)) {
			// resultCode
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "errMsg", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_SKQ_SUCCESS_STATUS)) {
				// payMessage
				if (GetField_CString(hRec, "payMessage", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("payMessage = [%s]\n", csPtr));
				}

				// sign
				if (GetField_CString(hRec, "sign", &csPtr)) {
					PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("sign = [%s]\n", csPtr));
				}
			}
		}
		else {
DEBUGLOG(("BreakDownInitRspMsg() Invalid Response\n"));
			iRet = PD_ERR;
		}
	} else {
DEBUGLOG(("BreakDownInitRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	json_object_put(jobj);

	hash_destroy(hRec);
	FREE_ME(hRec);
DEBUGLOG(("BreakDownInitRspMsg() Exit\n"));
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


int BuildRspAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	int	iIsInitReq = PD_FALSE;
	char	*csPtr;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	GetField_Int(hIn, "isInitReq", &iIsInitReq);
DEBUGLOG(("isInitReq = [%d]\n", iIsInitReq));

	if (iIsInitReq) {
// errMsg
		if (GetField_CString(hIn, "return_msg", &csPtr)) {
			strcat((char*)csBuf, "errMsg");
			strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("errMsg = [%s]\n", csPtr));
		}

// payMessage
		if (GetField_CString(hIn, "code_url", &csPtr)) {
			strcat((char*)csBuf, "payMessage");
			strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("payMessage = [%s]\n", csPtr));
		}

// resultCode
		if (GetField_CString(hIn, "return_code", &csPtr)) {
			strcat((char*)csBuf, "resultCode");
			strcat((char*)csBuf, MY_SKQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_SKQ_TOKEN);
DEBUGLOG(("resultCode = [%s]\n", csPtr));
		}
	} else {
		if (GetField_CString(hIn, "in_msg", &inMsg)) {
			if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_SKQ_TOKEN, MY_SKQ_FIELD_TOKEN) == PD_OK) {
				qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
				for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
					// exclude sign
					if (strcmp(k_v_pair[iTmp].key, "sign")) {
						strcat(csBuf, k_v_pair[iTmp].key);
						strcat(csBuf, MY_SKQ_FIELD_TOKEN);
						strcat(csBuf, k_v_pair[iTmp].value);
						strcat(csBuf, MY_SKQ_TOKEN);
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

