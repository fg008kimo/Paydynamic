/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/04/16              LokMan Chow
Add deposit trace functions			   2018/12/18		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "OupMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#define __USE_XOPEN
#include <time.h>

static char cDebug;


struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};

OBJPTR(DB);

void OupMsg(char cdebug)
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

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");

// version
		if (GetField_CString(hIn, "version", &csTmp)) {
			strcat((char*)outMsg, "version");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("version = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***version is missing\n"));
		}

// encoding
		strcat((char*)outMsg, "encoding");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_ENCODING);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("encoding = [%s]\n", MY_OUP_ENCODING));

// certId
		if (GetField_CString(hIn, "cert_id", &csTmp)) {
			strcat((char*)outMsg, "certId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("certId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***cert_id is missing\n"));
		}

// signature
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "signature");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("signature = [%s]\n", url_encode(csTmp)));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
		}

// signMethod
		strcat((char*)outMsg, "signMethod");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg,  MY_OUP_SIGN_METHOD);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("signMethod = [%s]\n", MY_OUP_SIGN_METHOD));

// txnType
		strcat((char*)outMsg, "txnType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_TXN_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnType = [%s]\n", MY_OUP_TXN_TYPE));

// txnSubType
		strcat((char*)outMsg, "txnSubType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_TXN_SUB_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnSubType = [%s]\n", MY_OUP_TXN_SUB_TYPE));

// bizType
		strcat((char*)outMsg, "bizType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_BIZ_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("bizType = [%s]\n", MY_OUP_BIZ_TYPE));

// channelType
		strcat((char*)outMsg, "channelType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_CHANNEL_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("channelType = [%s]\n", MY_OUP_CHANNEL_TYPE));

// frontUrl
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "frontUrl");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("frontUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
		}

// backUrl
		if (GetField_CString(hIn, "return_url_only", &csTmp)) {
			strcat((char*)outMsg, "backUrl");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("backUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
		}

// accessType
		strcat((char*)outMsg, "accessType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_ACCESS_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("accessType = [%s]\n", MY_OUP_ACCESS_TYPE));

// merId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "merId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("merId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

// orderId
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "orderId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("orderId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_seq is missing\n"));
		}

// txnTime
		if (GetField_CString(hIn, "local_tm_date", &csTmp)) {
			char *csTmp2 = NULL;
			char csRaw[PD_DATETIME_LEN + 1];
			if (GetField_CString(hIn, "local_tm_time", &csTmp2)) {
				sprintf(csRaw, "%s%s", csTmp, csTmp2);
				strcat((char*)outMsg, "txnTime");
				strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
				strcat((char*)outMsg, csRaw);
				strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnTime = [%s]\n", csRaw));
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

// txnAmt
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
			//sprintf((char*)csTmpAmt, "%.2f", dTmp);
			strcat((char*)outMsg, "txnAmt");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnAmt = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
		}

// currencyCode
		strcat((char*)outMsg, "currencyCode");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_CCY_CODE);
		//strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("currencyCode = [%s]\n", MY_OUP_CCY_CODE));

/*
// frontFailUrl
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "frontFailUrl");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("frontFailUrl = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
		}
*/

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
		strcat((char*)outMsg, MY_OUP_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_OUP_TOKEN);
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

	if (Str2Cls(hRec, (char *)inMsg, MY_OUP_TOKEN, MY_OUP_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)inMsg);

// merId
		if (GetField_CString(hRec, "merId", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("merId:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("merId:psp_merchant_id not found\n"));
		}

// orderId
		if (GetField_CString(hRec, "orderId", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("orderId:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderId:txn_seq not found\n"));
		}

// queryId
		if (GetField_CString(hRec, "queryId", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("queryId:tid = [%s]\n", csPtr));
		}

// respCode
		if (GetField_CString(hRec, "respCode", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("respCode:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("respCode:status not found\n"));
		}

// respMsg (for deposit trace)
		if (GetField_CString(hRec, "respMsg", &csPtr)) {
			PutField_CString(hOut, "fail_reason", csPtr);
DEBUGLOG(("respMsg:fail_reason = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("respMsg:fail_reason not found\n"));
		}

// settleAmt
		if (GetField_CString(hRec, "settleAmt", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("settleAmt:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("settleAmt:txn_amt not found\n"));
		}

// origRespCode (for deposit trace: overwrite status)
		if (GetField_CString(hRec, "origRespCode", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("origRespCode:status = [%s]\n", csPtr));

// origRespMsg (for deposit trace: overwrite fail_reason)
			if (GetField_CString(hRec, "origRespMsg", &csPtr)) {
				PutField_CString(hOut, "fail_reason", csPtr);
DEBUGLOG(("origRespMsg:fail_reason = [%s]\n", csPtr));
			}

			if (strcmp(csPtr, MY_OUP_SUCCESS_STATUS_1) && strcmp(csPtr, MY_OUP_SUCCESS_STATUS_2)) {
// txnAmt (for deposit trace non-success status: overwrite txn_amt)
				if (GetField_CString(hRec, "txnAmt", &csPtr)) {
					PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("txnAmt:txn_amt = [%s]\n", csPtr));
				}
			}
		}

// sign
		if (GetField_CString(hRec, "signature", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("signature:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("signature:sign not found\n"));
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
	int	iForEnquiry = PD_FALSE;
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_use", &iForEnquiry);
	if (iForEnquiry) {
		return BuildInqAuthData(hIn);
	}

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildCallbackAuthData(hIn);
	}

	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// accessType
	strcat((char*)csBuf, "accessType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_ACCESS_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("accessType = [%s]\n", MY_OUP_ACCESS_TYPE));

// backUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "backUrl");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("backUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

// bizType
	strcat((char*)csBuf, "bizType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_BIZ_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("bizType = [%s]\n", MY_OUP_BIZ_TYPE));

// certId
	if (GetField_CString(hIn, "cert_id", &csPtr)) {
		strcat((char*)csBuf, "certId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("certId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("cert_id is missing\n"));
	}

// channelType
	strcat((char*)csBuf, "channelType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_CHANNEL_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("channelType = [%s]\n", MY_OUP_CHANNEL_TYPE));

// currencyCode
	strcat((char*)csBuf, "currencyCode");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_CCY_CODE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("currencyCode = [%s]\n", MY_OUP_CCY_CODE));

// encoding
	strcat((char*)csBuf, "encoding");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_ENCODING);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("encoding = [%s]\n", MY_OUP_ENCODING));

/*
// frontFailUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "frontFailUrl");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("frontFailUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
	}
*/

// frontUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csBuf, "frontUrl");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("frontUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
	}

// merId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("merId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// orderId
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "orderId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("orderId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

// signMethod
	strcat((char*)csBuf, "signMethod");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_SIGN_METHOD);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("signMethod = [%s]\n", MY_OUP_SIGN_METHOD));

// txnAmt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		//sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "txnAmt");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnAmt = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// txnSubType
	strcat((char*)csBuf, "txnSubType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_TXN_SUB_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnSubType = [%s]\n", MY_OUP_TXN_SUB_TYPE));

// txnTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN + 1];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat((char*)csBuf, "txnTime");
			strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
			strcat((char*)csBuf, csRaw);
			strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnTime = [%s]\n", csRaw));
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

// txnType
	strcat((char*)csBuf, "txnType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_TXN_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnType = [%s]\n", MY_OUP_TXN_TYPE));

// version
	if (GetField_CString(hIn, "version", &csPtr)) {
		strcat((char*)csBuf, "version");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		//strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("version = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("version is missing\n"));
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
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_OUP_TOKEN, MY_OUP_FIELD_TOKEN) == PD_OK) {
//DEBUGLOG(("iPairCnt = [%d]\n", iPairCnt));
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "signature")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_OUP_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_OUP_TOKEN);
				}
			}
		}
	}

	// special handling:
	// remove the last &
	csBuf[strlen(csBuf) - 1] = '\0';

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csBuf;
	char *csURL = NULL;
	char *csPtr = NULL;
	char *csTmp = NULL;

DEBUGLOG(("FormatInqMsg() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
			strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_OUP_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_OUP_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
			if (GetField_CString(hIn, "url_method", &csPtr)) {
				strcat((char*)csBuf, csPtr);
			}
			else {
				strcat((char*)csBuf, PD_DEFAULT_METHOD);
			}
		}

		sprintf((char*)outMsg, "%0*d", PD_WEB_HEADER_LEN_LEN, (int)strlen(csBuf));
		strcat((char*)outMsg, csBuf);
DEBUGLOG(("outMsg = [%s]\n", outMsg));

		// version
		if (GetField_CString(hIn, "psp_key_uid", &csTmp)) {
			strcat((char*)outMsg, "version");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("version = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_key_uid is missing\n"));
		}

		// encoding
		strcat((char*)outMsg, "encoding");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_ENCODING);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("encoding = [%s]\n", MY_OUP_INQ_ENCODING));

		// certId
		if (GetField_CString(hIn, "psp_key_id", &csTmp)) {
			strcat((char*)outMsg, "certId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("certId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_key_id is missing\n"));
		}

		// signature
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "signature");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("signature = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
		}

		// signMethod
		strcat((char*)outMsg, "signMethod");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_SIGN_METHOD);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("signMethod = [%s]\n", MY_OUP_INQ_SIGN_METHOD));

		// txnType
		strcat((char*)outMsg, "txnType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_TXN_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnType = [%s]\n", MY_OUP_INQ_TXN_TYPE));

		// txnSubType
		strcat((char*)outMsg, "txnSubType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_TXN_SUB_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnSubType = [%s]\n", MY_OUP_INQ_TXN_SUB_TYPE));

		// bizType
		strcat((char*)outMsg, "bizType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_BIZ_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("bizType = [%s]\n", MY_OUP_INQ_BIZ_TYPE));

		// accessType
		strcat((char*)outMsg, "accessType");
		strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
		strcat((char*)outMsg, MY_OUP_INQ_ACCESS_TYPE);
		strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("accessType = [%s]\n", MY_OUP_INQ_ACCESS_TYPE));

		// acqInsCode (not necessary)

		// merId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "merId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("merId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

		// txnTime
		if (GetField_CString(hIn, "txn_datetime", &csTmp)) {
			strcat((char*)outMsg, "txnTime");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("txnTime = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_datetime is missing\n"));
		}

		// orderId
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "orderId");
			strcat((char*)outMsg, MY_OUP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			//strcat((char*)outMsg, MY_OUP_TOKEN);
DEBUGLOG(("orderId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_seq is missing\n"));
		}

		// reserved (optional)
	}
	else {
DEBUGLOG(("***psp_url is missing\n"));
		iRet = PD_ERR;
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInqMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatInqMsg() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int BuildInqAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csBuf;
	char *csPtr;

DEBUGLOG(("BuildInqAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	// accessType
	strcat((char*)csBuf, "accessType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_ACCESS_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("accessType = [%s]\n", MY_OUP_INQ_ACCESS_TYPE));

	// bizType
	strcat((char*)csBuf, "bizType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_BIZ_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("bizType = [%s]\n", MY_OUP_INQ_BIZ_TYPE));

	// certId
	if (GetField_CString(hIn, "psp_key_id", &csPtr)) {
		strcat((char*)csBuf, "certId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("certId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_key_id is missing\n"));
	}

	// encoding
	strcat((char*)csBuf, "encoding");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_ENCODING);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("encoding = [%s]\n", MY_OUP_INQ_ENCODING));

	// merId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("merId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

	// orderId
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "orderId");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("orderId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

	// signMethod
	strcat((char*)csBuf, "signMethod");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_SIGN_METHOD);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("signMethod = [%s]\n", MY_OUP_INQ_SIGN_METHOD));

	// txnSubType
	strcat((char*)csBuf, "txnSubType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_TXN_SUB_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnSubType = [%s]\n", MY_OUP_INQ_TXN_SUB_TYPE));

	// txnTime
	if (GetField_CString(hIn, "txn_datetime", &csPtr)) {
		strcat((char*)csBuf, "txnTime");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnTime = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_datetime is missing\n"));
	}

	// txnType
	strcat((char*)csBuf, "txnType");
	strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
	strcat((char*)csBuf, MY_OUP_INQ_TXN_TYPE);
	strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("txnType = [%s]\n", MY_OUP_INQ_TXN_TYPE));

	// version
	if (GetField_CString(hIn, "psp_key_uid", &csPtr)) {
		strcat((char*)csBuf, "version");
		strcat((char*)csBuf, MY_OUP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		//strcat((char*)csBuf, MY_OUP_TOKEN);
DEBUGLOG(("version = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_key_uid is missing\n"));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildInqAuthData() auth_data = [%s]\n", csBuf));
DEBUGLOG(("BuildInqAuthData() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int iRet = PD_OK;

DEBUGLOG(("BreakDownInqRspMsg() Start\n"));

	PutField_CString(hOut, "orig_msg", (const char *)inMsg);
DEBUGLOG(("BreakDownInqRspMsg() call BreakDownMsg()\n"));
	iRet = BreakDownMsg(hOut, inMsg, inLen);

DEBUGLOG(("BreakDownInqRspMsg() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildInqRspAuthData(hash_t *hIn)
{
	int iRet = PD_OK;

DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;

DEBUGLOG(("BuildCallbackAuthData() Start\n"));

	PutField_CString(hIn, "auth_data", "dummy");
DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	GetField_CString(hIn, "orig_msg", &csPtr);
	strcat((char*)outMsg, csPtr);

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit iRet = [%d]\n", iRet));
	return iRet;
}

