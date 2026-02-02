/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/10/31              David Wong
Support EC					   2018/01/31		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DpyMsg.h"
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
OBJPTR(DB);


void DpyMsg(char cdebug)
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
	char	csTag[PD_TMP_BUF_LEN + 1];;
	char	csTmpBuf[PD_TMP_BUF_LEN + 1];
	int	iOpt = INT_ERR;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");

// merchant_code
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "merchant_code");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: merchant_code = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

// service_type
		strcat((char*)outMsg, "service_type");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_SERVICE_TYPE);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: service_type = [%s]\n", PD_SERVICE_TYPE));

// notify_url
		if (GetField_CString(hIn, "return_url_only", &csTmp)) {
			strcat((char*)outMsg, "notify_url");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: notify_url = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***return_url_only is missing\n"));
		}

// interface_version
		strcat((char*)outMsg, "interface_version");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_INTERFACE_VERSION);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: interface_version = [%s]\n", PD_INTERFACE_VERSION));

// input_charset
		strcat((char*)outMsg, "input_charset");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_INPUT_CHARSET);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: input_charset = [%s]\n", PD_INPUT_CHARSET));

// sign_type
		strcat((char*)outMsg, "sign_type");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_SIGN_TYPE);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: sign_type = [%s]\n", PD_SIGN_TYPE));

// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: sign = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***sign is missing\n"));
		}

// return_url
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "return_url");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: return_url = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***fe_url is missing\n"));
		}

// pay_type
		if (GetField_CString(hIn, "bank_code", &csTmp)) {
			strcat((char*)outMsg, "pay_type");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr, "DBMobBankMap", "IsMobileOption");
			iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if (iOpt == PD_FALSE && iOpt != INT_ERR) {
				strcat((char*)outMsg, PD_PAY_TYPE);
DEBUGLOG(("FormatMsg:: pay_type = [%s]\n", PD_PAY_TYPE));
			} else if (iOpt && iOpt != INT_ERR) {
				strcat((char*)outMsg, PD_PAY_TYPE_EC);
DEBUGLOG(("FormatMsg:: pay_type = [%s]\n", PD_PAY_TYPE_EC));
			}
			strcat((char*)outMsg, MY_DPY_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***bank_code is missing\n"));
		}

// order_no
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "order_no");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: order_no = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***txn_seq is missing\n"));
		}

// order_time
		if (GetField_CString(hIn, "local_tm_date", &csTmp)) {
			char *csTmp2 = NULL;
			char csRaw[PD_DATETIME_LEN * 2];
			char csConverted[PD_DATETIME_LEN * 2];
			struct tm tm;
			if (GetField_CString(hIn, "local_tm_time", &csTmp2)) {
				sprintf(csRaw, "%s%s", csTmp, csTmp2);
				strptime((const char*)csRaw, "%Y%m%d%H%M%S", &tm);
				strftime(csConverted, sizeof(csConverted), "%Y-%m-%d %H:%M:%S", &tm);
				strcat((char*)outMsg, "order_time");
				strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
				strcat((char*)outMsg, csConverted);
				strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: order_time = [%s]\n", csConverted));
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***local_tm_time is missing\n"));
			}
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***local_tm_date is missing\n"));
		}

// order_amount
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf(csTmpAmt, "%.2f", dTmp);
			strcat((char*)outMsg, "order_amount");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: order_amount = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_txn_amt is missing\n"));
		}

// bank_code
		if (GetField_CString(hIn, "bank_code", &csTmp)) {
			strcat((char*)outMsg, "bank_code");
			strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
			if (iOpt == PD_FALSE && iOpt != INT_ERR) {
				strcat((char*)outMsg, csTmp);
DEBUGLOG(("FormatMsg:: bank_code = [%s]\n", csTmp));
			} else if (iOpt && iOpt != INT_ERR) {
				strcat((char*)outMsg, PD_BANK_CODE_EC);
DEBUGLOG(("FormatMsg:: bank_code = [%s]\n", PD_BANK_CODE_EC));
			}
			strcat((char*)outMsg, MY_DPY_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***bank_code is missing\n"));
		}

// redo_flag
		strcat((char*)outMsg, "redo_flag");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_REDO_FLAG);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: redo_flag = [%s]\n", PD_REDO_FLAG));

// product_name
		strcat((char*)outMsg, "product_name");
		strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
		strcat((char*)outMsg, PD_PRODUCT_NAME);
		strcat((char*)outMsg, MY_DPY_TOKEN);
DEBUGLOG(("FormatMsg:: product_name = [%s]\n", PD_PRODUCT_NAME));

// TLG - Transaction Logging
		if (GetField_CString(hIn, "psp_id", &csTmp)) {
			int iDtlRet = PD_FALSE;
DEBUGLOG(("Call DBPspUrl::IsRedirectURL\n"));
			DBObjPtr = CreateObj(DBPtr, "DBPspUrl", "IsRedirectURL");
			iDtlRet = (unsigned long)(DBObjPtr)(csTmp);
			if (iDtlRet) {
				if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("Call DBDefTlgTagConvert::GetRandomTag\n"));
					DBObjPtr = CreateObj(DBPtr, "DBDefTlgTagConvert", "GetRandomTag");
					iDtlRet = (unsigned long)(DBObjPtr)("txn_seq", csTag);
					if (iDtlRet == PD_OK) {
DEBUGLOG(("new_tag [%s]\n", csTag));
						base64_encode((unsigned char*)csTmp, strlen(csTmp), csTmpBuf, PD_TMP_BUF_LEN);
						strcat((char*)outMsg, csTag);
						strcat((char*)outMsg, MY_DPY_FIELD_TOKEN);
						strcat((char*)outMsg, csTmpBuf);
						strcat((char*)outMsg, MY_DPY_TOKEN);
					} else {
DEBUGLOG(("GetRandomTag FAILED!! Skip Insert TLG Log, iDtlRet = [%d]\n", iDtlRet));
					}
				} else {
DEBUGLOG(("txn_seq NOT FOUND!! Skip Insert TLG Log\n"));
				}
DEBUGLOG(("FormatMsg:: [%s] = [%s]\n", csTag, csTmp));
			}
		}

// url_method
		if (GetField_CString(hIn, "url_method", &csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n", csMethod));
		}
		else
			csMethod = strdup("");

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n", outMsg));
		base64_encode(outMsg, strlen((char*)outMsg), csBuf, PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: after encode\n"));
		outMsg[0] = '\0';
		strcat((char*)outMsg, "redirect_url");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csBuf);
		strcat((char*)outMsg, MY_DPY_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_DPY_TOKEN);
		strcat((char*)outMsg, "ret_status=0");
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n", outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***redirect_url is missing\n"));
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

	if (Str2Cls(hRec, (char *)inMsg, MY_DPY_TOKEN, MY_DPY_FIELD_TOKEN) == PD_OK) {
// merchant_code
		if (GetField_CString(hRec, "merchant_code", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("BreakDownMsg:: merchant_code:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: merchant_code:psp_merchant_id not found\n"));
		}

// notify_type
		if (GetField_CString(hRec, "notify_type", &csPtr)) {
			PutField_CString(hOut, "notify_type", csPtr);
DEBUGLOG(("BreakDownMsg:: notify_type = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: notify_type not found\n"));
		}

// notify_id
		if (GetField_CString(hRec, "notify_id", &csPtr)) {
			PutField_CString(hOut, "notify_id", csPtr);
DEBUGLOG(("BreakDownMsg:: notify_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: notify_id not found\n"));
		}

// interface_version
		if (GetField_CString(hRec, "interface_version", &csPtr)) {
			PutField_CString(hOut, "interface_version", csPtr);
DEBUGLOG(("BreakDownMsg:: interface_version = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: interface_version not found\n"));
		}

// sign_type
		if (GetField_CString(hRec, "sign_type", &csPtr)) {
			PutField_CString(hOut, "sign_type", csPtr);
DEBUGLOG(("BreakDownMsg:: sign_type = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: sign_type not found\n"));
		}

// sign
		if (GetField_CString(hRec, "sign", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("BreakDownMsg:: sign not found\n"));
		}

// order_no
		if (GetField_CString(hRec, "order_no", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("BreakDownMsg:: order_no:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: order_no:txn_seq not found\n"));
		}

// order_time
		if (GetField_CString(hRec, "order_time", &csPtr)) {
			PutField_CString(hOut, "order_time", csPtr);
DEBUGLOG(("BreakDownMsg:: order_time = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: order_time not found\n"));
		}

// order_amount
		if (GetField_CString(hRec, "order_amount", &csPtr)) {
			PutField_CString(hOut, "psp_txn_amt", csPtr);
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("BreakDownMsg:: order_amount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: order_amount:txn_amt not found\n"));
		}

// trade_no
		if (GetField_CString(hRec, "trade_no", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("BreakDownMsg:: trade_no:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: trade_no:tid not found\n"));
		}

// trade_time
		if (GetField_CString(hRec, "trade_time", &csPtr)) {
			char csRaw[PD_DATETIME_LEN * 2];
			char csConverted[PD_DATETIME_LEN * 2];
			char csTxnDate[PD_DATE_LEN + 1];
			struct tm tm;
			strcpy(csRaw, csPtr);
			strptime((const char*)csRaw, "%Y-%m-%d %H:%M:%S", &tm);
			strftime(csConverted, sizeof(csConverted), "%Y%m%d%H%M%S", &tm);
			strncpy(csTxnDate, csConverted, PD_DATE_LEN);
			csTxnDate[PD_DATE_LEN] = '\0';

			PutField_CString(hOut, "fundin_date", csConverted);
			PutField_CString(hOut, "txn_date", csTxnDate);
			PutField_CString(hOut, "trade_time", csPtr);
DEBUGLOG(("BreakDownMsg:: trade_time:fundin_date = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: trade_time:fundin_date not found\n"));
		}

// trade_status
		if (GetField_CString(hRec, "trade_status", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("BreakDownMsg:: trade_status:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: trade_status:status not found\n"));
		}

// bank_seq_no
		if (GetField_CString(hRec, "bank_seq_no", &csPtr)) {
			PutField_CString(hOut, "bank_seq_no", csPtr);
DEBUGLOG(("BreakDownMsg:: bank_seq_no = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("BreakDownMsg:: bank_seq_no not found\n"));
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
	int	iOpt = INT_ERR;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// bank_code
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)csBuf, "bank_code");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBMobBankMap", "IsMobileOption");
		iOpt = (unsigned long)(*DBObjPtr)(csPtr);
		if (iOpt == PD_FALSE && iOpt != INT_ERR) {
			strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildAuthData:: bank_code = [%s]\n", csPtr));
		} else if (iOpt && iOpt != INT_ERR) {
			strcat((char*)csBuf, PD_BANK_CODE_EC);
DEBUGLOG(("BuildAuthData:: bank_code = [%s]\n", PD_BANK_CODE_EC));
		}
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: bank_code is missing\n"));
	}

// input_charset
	strcat((char*)csBuf, "input_charset");
	strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
	strcat((char*)csBuf, PD_INPUT_CHARSET);
	strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: input_charset = [%s]\n", PD_INPUT_CHARSET));

// interface_version
	strcat((char*)csBuf, "interface_version");
	strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
	strcat((char*)csBuf, PD_INTERFACE_VERSION);
	strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: interface_version = [%s]\n", PD_INTERFACE_VERSION));

// merchant_code
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merchant_code");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: merchant_code = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: psp_merchant_id is missing\n"));
	}

// notify_url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "notify_url");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: notify_url = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: return_url_only is missing\n"));
	}

// order_amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf(csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "order_amount");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: order_amount = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing\n"));
	}

// order_no
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "order_no");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: order_no = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: txn_seq is missing\n"));
	}

// order_time
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN * 2];
		char csConverted[PD_DATETIME_LEN * 2];
		struct tm tm;
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strptime((const char*)csRaw, "%Y%m%d%H%M%S", &tm);
			strftime(csConverted, sizeof(csConverted), "%Y-%m-%d %H:%M:%S", &tm);
			strcat((char*)csBuf, "order_time");
			strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
			strcat((char*)csBuf, csConverted);
			strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: order_time = [%s]\n", csConverted));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: local_tm_time is missing\n"));
		}
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: local_tm_date is missing\n"));
	}

// pay_type
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)csBuf, "pay_type");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		if (iOpt == PD_FALSE && iOpt != INT_ERR) {
			strcat((char*)csBuf, PD_PAY_TYPE);
DEBUGLOG(("BuildAuthData:: pay_type = [%s]\n", PD_PAY_TYPE));
		} else if (iOpt && iOpt != INT_ERR) {
			strcat((char*)csBuf, PD_PAY_TYPE_EC);
DEBUGLOG(("BuildAuthData:: pay_type = [%s]\n", PD_PAY_TYPE_EC));
		}
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: bank_code is missing\n"));
	}

// product_name
	strcat((char*)csBuf, "product_name");
	strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
	strcat((char*)csBuf, PD_PRODUCT_NAME);
	strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: product_name = [%s]\n", PD_PRODUCT_NAME));

// redo_flag
	strcat((char*)csBuf, "redo_flag");
	strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
	strcat((char*)csBuf, PD_REDO_FLAG);
	strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: redo_flag = [%s]\n", PD_REDO_FLAG));

// return_url
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "return_url");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: return_url = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: fe_url is missing\n"));
	}

// service_type
	strcat((char*)csBuf, "service_type");
	strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
	strcat((char*)csBuf, PD_SERVICE_TYPE);
	//strcat((char*)csBuf, MY_DPY_TOKEN);
DEBUGLOG(("BuildAuthData:: service_type = [%s]\n", PD_SERVICE_TYPE));

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csPtr;
	char *csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// bank_seq_no
	if (GetField_CString(hIn, "bank_seq_no", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: bank_seq_no = [%s]\n", csPtr));
		strcat((char*)csBuf, "bank_seq_no");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// interface_version
	if (GetField_CString(hIn, "interface_version", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: interface_version = [%s]\n", csPtr));
		strcat((char*)csBuf, "interface_version");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// merchant_code
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: merchant_code:psp_merchant_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "merchant_code");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// notify_id
	if (GetField_CString(hIn, "notify_id", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: notify_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "notify_id");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// notify_type
	if (GetField_CString(hIn, "notify_type", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: notify_type = [%s]\n", csPtr));
		strcat((char*)csBuf, "notify_type");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// order_amount
	if (GetField_CString(hIn, "psp_txn_amt", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_amount:psp_txn_amt = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_amount");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// order_no
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_no:txn_seq = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_no");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// order_time
	if (GetField_CString(hIn, "order_time", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_time = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_time");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// trade_no
	if (GetField_CString(hIn, "tid", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: trade_no:tid = [%s]\n", csPtr));
		strcat((char*)csBuf, "trade_no");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// trade_status
	if (GetField_CString(hIn, "status", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: trade_status:status = [%s]\n", csPtr));
		strcat((char*)csBuf, "trade_status");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPY_TOKEN);
	}

// trade_time
	if (GetField_CString(hIn, "trade_time", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: trade_time = [%s]\n", csPtr));
		strcat((char*)csBuf, "trade_time");
		strcat((char*)csBuf, MY_DPY_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		//strcat((char*)csBuf, MY_DPY_TOKEN);
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

