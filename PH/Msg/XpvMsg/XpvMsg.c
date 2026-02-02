/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/09/21              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "XpvMsg.h"
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

OBJPTR(DB);


void XpvMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csPtr = NULL;
	char	*csBuf;
	char	*csMethod = NULL;
	char	*csTag;
	char	*csTmpBuf;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	csTag = (char*) malloc (PD_TAG_LEN + 1);
	csTmpBuf = (char*) malloc (PD_TMP_BUF_LEN + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");

// LP_MerId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "LP_MerId");
			strcat((char*)outMsg, MY_XPV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XPV_TOKEN);
DEBUGLOG(("LP_MerId = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

// LP_EncType
		strcat((char*)outMsg, "LP_EncType");
		strcat((char*)outMsg, MY_XPV_FIELD_TOKEN);
		strcat((char*)outMsg, MY_XPV_ENC_TYPE);
		strcat((char*)outMsg, MY_XPV_TOKEN);
DEBUGLOG(("LP_EncType = [%s]\n", MY_XPV_ENC_TYPE));

// LP_Data
		if (GetField_CString(hIn, "LP_Data", &csTmp)) {
			strcat((char*)outMsg, "LP_Data");
			strcat((char*)outMsg, MY_XPV_FIELD_TOKEN);
			base64_encode((unsigned char*)csTmp, strlen(csTmp), csBuf, PD_MAX_BUFFER);
			strcat((char*)outMsg, csBuf);
			strcat((char*)outMsg, MY_XPV_TOKEN);
DEBUGLOG(("LP_Data = [%s]\n", csTmp));
DEBUGLOG(("encoded LP_Data = [%s]\n", csBuf));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***LP_Data is missing\n"));
		}

// LP_Sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "LP_Sign");
			strcat((char*)outMsg, MY_XPV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XPV_TOKEN);
DEBUGLOG(("LP_Sign = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
		}

// TLG - Transaction Logging
		if (GetField_CString(hIn, "psp_id", &csTmp)) {
			int iDtlRet = PD_FALSE;
DEBUGLOG(("Call DBPspUrl:IsRedirectURL\n"));
			DBObjPtr = CreateObj(DBPtr, "DBPspUrl", "IsRedirectURL");
			iDtlRet = ((unsigned long)(DBObjPtr)(csTmp));
DEBUGLOG(("IsRedirectUrl = [%d]\n", iDtlRet));

			if (iDtlRet) {
				if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("Call DBDefTlgTagConvert:GetRandomTag\n"));
					DBObjPtr = CreateObj(DBPtr, "DBDefTlgTagConvert", "GetRandomTag");
					iDtlRet = ((unsigned long)(DBObjPtr)("txn_seq", csTag));

					if (iDtlRet == PD_OK) {
DEBUGLOG(("org_tag [%s], new_tag [%s]\n", "txn_seq", csTag));
						base64_encode((unsigned char*)csTmp, strlen(csTmp), csTmpBuf, PD_TMP_BUF_LEN);
						strcat((char*)outMsg, csTag);
						strcat((char*)outMsg, MY_XPV_FIELD_TOKEN);
						strcat((char*)outMsg, csTmpBuf);
						strcat((char*)outMsg, MY_XPV_TOKEN);
					} else {
DEBUGLOG(("Call DBDefTlgTagConvert:GetRandomTag failed! Skip insert TLG, iDtlRet = [%d]\n", iDtlRet));
					}
				} else {
DEBUGLOG(("txn_seq not found! Skip insert TLG\n"));
				}
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
		strcat((char*)outMsg, MY_XPV_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_XPV_TOKEN);
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
	FREE_ME(csTag);
	FREE_ME(csTmpBuf);
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

	if (Str2Cls(hRec, (char *)inMsg, MY_XPV_TOKEN, MY_XPV_FIELD_TOKEN) == PD_OK) {
// LP_MerId
		if (GetField_CString(hRec, "LP_MerId", &csPtr)) {
			PutField_CString(hOut, "LP_MerId", csPtr);
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("LP_MerId:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("LP_MerId:psp_merchant_id not found\n"));
		}

// LP_EncType
		if (GetField_CString(hRec, "LP_EncType", &csPtr)) {
			PutField_CString(hOut, "LP_EncType", csPtr);
DEBUGLOG(("LP_EncType = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("LP_EncType not found\n"));
		}

// LP_Data
		if (GetField_CString(hRec, "LP_Data", &csPtr)) {
DEBUGLOG(("LP_Data = [%s]\n", csPtr));
			char *csData;
			int iLen;
			char *p;

			csData = (char*) malloc (PD_MAX_BUFFER + 1);
			iLen = base64_decode(csPtr, (unsigned char *)csData, PD_MAX_BUFFER);
			csData[iLen] = '\0';
			PutField_CString(hOut, "LP_Data", csData);
DEBUGLOG(("decoded LP_Data = [%s]\n", csData));

			// BankOrderId
			p = strtok(csData, MY_XPV_SIGN_TOKEN);
			if (p) {
				PutField_CString(hOut, "tid", p);
DEBUGLOG(("BankOrderId:tid = [%s]\n", p));
			}

			// MerOrderId
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
				PutField_CString(hOut, "txn_seq", p);
DEBUGLOG(("MerOrderId:txn_seq = [%s]\n", p));
			}

			// MerDate
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
DEBUGLOG(("MerDate = [%s]\n", p));
			}

			// BankTime
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
				char csTxnDate[PD_DATE_LEN + 1];
				strncpy(csTxnDate, p, PD_DATE_LEN);
				csTxnDate[PD_DATE_LEN] = '\0';

				PutField_CString(hOut, "fundin_date", p);
				PutField_CString(hOut, "txn_date", csTxnDate);
DEBUGLOG(("BankTime:fundin_date = [%s]\n", p));
			}

			// Amount
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
				PutField_CString(hOut, "txn_amt", p);
DEBUGLOG(("Amount:txn_amt = [%s]\n", p));
			}

			// Currency
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
DEBUGLOG(("Currency = [%s]\n", p));
			}

			// PayStatus
			p = strtok(NULL, MY_XPV_SIGN_TOKEN);
			if (p) {
				PutField_CString(hOut, "status", p);
DEBUGLOG(("PayStatus:status = [%s]\n", p));
			}

			FREE_ME(csData);
		}
		else {
DEBUGLOG(("LP_Data not found\n"));
		}

// LP_Sign
		if (GetField_CString(hRec, "LP_Sign", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("LP_Sign:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("LP_Sign:sign not found\n"));
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
	int	iOpt = INT_ERR;
	char	*csPtr;
	char	*csBuf;
	char	*csData;
	double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	csData = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';
	memset(csData, 0, MAX_MSG_SIZE);
	csData[0] = '\0';

// LP_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("LP_MerId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// LP_EncType
	strcat((char*)csBuf, MY_XPV_ENC_TYPE);
	strcat((char*)csBuf, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("LP_EncType = [%s]\n", MY_XPV_ENC_TYPE));

// LP_Data
	// MerchantOrder
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csData, csPtr);
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("MerchantOrder = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

	// MerchantDate
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		strcat((char*)csData, csPtr);
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("MerchantDate = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("local_tm_date is missing\n"));
	}

	// PayAmount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat((char*)csData, csTmpAmt);
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("PayAmount = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

	// Currency
	strcat((char*)csData, MY_XPV_CURRENCY);
	strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("Currency = [%s]\n", MY_XPV_CURRENCY));

	// BankCode
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
DEBUGLOG(("bank_code = [%s]\n", csPtr));
		DBObjPtr = CreateObj(DBPtr, "DBMobBankMap", "IsMobileOption");
		iOpt = (unsigned long)(*DBObjPtr)(csPtr);
		if (iOpt == PD_FALSE && iOpt != INT_ERR) {
			strcat((char*)csData, csPtr);
DEBUGLOG(("BankCode = [%s]\n", csPtr));
		}
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
	}

	// BackendNotifyUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csData, csPtr);
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("BackendNotifyUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

	// FrontNotifyUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat((char*)csData, csPtr);
		strcat((char*)csData, MY_XPV_SIGN_TOKEN);
DEBUGLOG(("FrontNotifyUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("fe_url is missing\n"));
	}

	// userID (optional)
	strcat((char*)csData, MY_XPV_SIGN_TOKEN);

	// Remark (optional)

DEBUGLOG(("LP_Data = [%s]\n", csData));
	PutField_CString(hIn, "LP_Data", csData);

	strcat((char*)csBuf, csData);
	strcat((char*)csBuf, MY_XPV_SIGN_TOKEN);

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
	FREE_ME(csData);

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

// LP_MerId
	if (GetField_CString(hIn, "LP_MerId", &csPtr)) {
DEBUGLOG(("LP_MerId = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf,MY_XPV_SIGN_TOKEN);
	}

// LP_EncType
	if (GetField_CString(hIn, "LP_EncType", &csPtr)) {
DEBUGLOG(("LP_EncType = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf,MY_XPV_SIGN_TOKEN);
	}

// LP_Data
	if (GetField_CString(hIn, "LP_Data", &csPtr)) {
DEBUGLOG(("LP_Data = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf,MY_XPV_SIGN_TOKEN);
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

