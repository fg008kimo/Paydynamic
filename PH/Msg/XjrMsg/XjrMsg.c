/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2019/03/21		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "XjrMsg.h"
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


OBJPTR(DB);
OBJPTR(BO);
static char cDebug;


struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};


void XjrMsg(char cdebug)
{
	cDebug = cdebug;
}


char *str_replace(char *orig, char *rep, char *with);


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
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		if (!strcmp(csPtr, MY_XJR_SUCCESS_STATUS))
			strcat((char*)outMsg,"SUCCESS");
		else
			strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)(url_encode(csPtr)), strlen((char*)(url_encode(csPtr))), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_XJR_TOKEN);
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
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_XJR_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_XJR_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_XJR_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_XJR_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_XJR_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
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

// p0_Cmd
	strcat((char*)csBuf, PD_P0_CMD);
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD));

// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// p2_Order
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("p2_Order = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("order_num is missing\n"));
	}

// p3_Cur
	strcat((char*)csBuf, PD_CCY_ISO_CNY);
DEBUGLOG(("p3_Cur = [%s]\n", PD_CCY_ISO_CNY));

// p4_Amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, csTmpAmt);
DEBUGLOG(("p4_Amt = [%s]\n", csTmpAmt));
	}
	else {
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// p5_Pid
	strcat((char*)csBuf, PD_P5_PID);
DEBUGLOG(("p5_Pid = [%s]\n", PD_P5_PID));

// p6_Pcat
// optional

// p7_Pdesc
// optional

// p8_Url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("p8_Url = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("return_url_only is missing\n"));
	}

// p9_MP
// optional

// pa_FrpId
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "XJR", "CN", csOutBankCode)) {
			strcat((char*)csBuf, csOutBankCode);
DEBUGLOG(("pa_FrpId = [%s]\n", csOutBankCode));
		}
		else {
DEBUGLOG(("no bank code mapping\n"));
		}
	}
	else {
DEBUGLOG(("bank_code is missing\n"));
	}

// pg_BankCode
// not necessary

// ph_Ip
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)csBuf, csPtr); 
DEBUGLOG(("ph_Ip = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("org_ip_addr is missing\n"));
	}

// pi_Url
// same as p8_Url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("pi_Url = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("return_url_only is missing\n"));
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

	if (Str2Cls(hRec, (char *)inMsg, MY_XJR_TOKEN, MY_XJR_FIELD_TOKEN) == PD_OK) {
/* p1_MerId */
		if (GetField_CString(hRec, "p1_MerId", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("p1_MerId:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("p1_MerId:psp_merchant_id not found\n"));
		}

/* r0_Cmd */
		if (GetField_CString(hRec, "r0_Cmd", &csPtr)) {
			PutField_CString(hOut, "r0_Cmd", csPtr);
DEBUGLOG(("r0_Cmd = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r0_Cmd not found\n"));
		}

/* r1_Code */
		if (GetField_CString(hRec, "r1_Code", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("r1_Code:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r1_Code:status not found\n"));
		}

/* r2_TrxId */
		if (GetField_CString(hRec, "r2_TrxId", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("r2_TrxId:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r2_TrxId:tid not found\n"));
		}

/* r3_Amt */
		if (GetField_CString(hRec, "r3_Amt", &csPtr)) {
			PutField_CString(hOut, "psp_txn_amt", csPtr);
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("r3_Amt:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r3_Amt:txn_amt not found\n"));
		}

/* r4_Cur */
		if (GetField_CString(hRec, "r4_Cur", &csPtr)) {
			PutField_CString(hOut, "psp_txn_ccy", csPtr);
DEBUGLOG(("r4_Cur:psp_txn_ccy = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r4_Cur:psp_txn_ccy not found\n"));
		}

/* r5_Pid */
		if (GetField_CString(hRec, "r5_Pid", &csPtr)) {
			PutField_CString(hOut, "r5_Pid", csPtr);
DEBUGLOG(("r5_Pid = [%s]\n", csPtr));
		}

/* r6_Order */
		if (GetField_CString(hRec, "r6_Order", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("r6_Order:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r6_Order:txn_seq not found\n"));
		}

/* r8_MP */
		if (GetField_CString(hRec, "r8_MP", &csPtr)) {
			PutField_CString(hOut, "r8_MP", csPtr);
DEBUGLOG(("r8_MP = [%s]\n", csPtr));
		}

/* r9_BType */
		if (GetField_CString(hRec, "r9_BType", &csPtr)) {
			PutField_CString(hOut, "r9_BType", csPtr);
DEBUGLOG(("r9_BType = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r9_BType not found\n"));
		}

/* ro_BankOrderId */
		if (GetField_CString(hRec, "ro_BankOrderId", &csPtr)) {
			PutField_CString(hOut, "ro_BankOrderId", csPtr);
DEBUGLOG(("ro_BankOrderId = [%s]\n", csPtr));
		}

/* rp_PayDate */
		if (GetField_CString(hRec, "rp_PayDate", &csPtr)) {
			PutField_CString(hOut, "rp_PayDate", csPtr);
DEBUGLOG(("rp_PayDate = [%s]\n", csPtr));
		}

/* hmac */
		if (GetField_CString(hRec, "hmac", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("hmac:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("hmac:sign = [%s]\n", " "));
		}
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownMsg Exit\n"));
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
			strcat((char*)csBuf, MY_XJR_FIELD_TOKEN);
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

// p0_Cmd
	strcat((char*)outMsg, "p0_Cmd");
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P0_CMD);
	strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD));

// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)outMsg, "p1_MerId");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
	}

// p2_Order
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)outMsg, "p2_Order");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p2_Order = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***order_num is missing\n"));
	}

// p3_Cur
	strcat((char*)outMsg, "p3_Cur");
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_CCY_ISO_CNY);
	strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p3_Cur = [%s]\n", PD_CCY_ISO_CNY));

// p4_Amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)outMsg, "p4_Amt");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csTmpAmt);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p4_Amt = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
	}

// p5_Pid
	strcat((char*)outMsg, "p5_Pid");
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P5_PID);
	strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p5_Pid = [%s]\n", PD_P5_PID));

// p6_Pcat
// optional

// p7_Pdesc
// optional

// p8_Url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "p8_Url");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("p8_Url = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}

// p9_MP
// optional

// pa_FrpId
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)outMsg, "pa_FrpId");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "XJR", "CN", csOutBankCode)) {
			strcat((char*)outMsg, csOutBankCode);
DEBUGLOG(("pa_FrpId = [%s]\n", csOutBankCode));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***no bank code mapping\n"));
		}
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***bank_code is missing\n"));
	}

// pg_BankCode
// not necessary

// ph_Ip
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)outMsg, "ph_Ip");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("ph_Ip = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***org_ip_addr is missing\n"));
	}

// pi_Url
// (same as p8_Url)
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "pi_Url");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("pi_Url = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}

// hmac
	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "hmac");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		//strcat((char*)outMsg, MY_XJR_TOKEN);
DEBUGLOG(("hmac = [%s]\n", csPtr));
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
					PutField_CString(hRec, key, json_object_get_string(val));
					break;
				default:
DEBUGLOG(("unsupported type\n"));
					break;
			}
		}

		if (GetField_CString(hRec, "r1_Code", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "r7_Desc", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_XJR_SUCCESS_STATUS)) {
				// r0_Cmd
				if (GetField_CString(hRec, "r0_Cmd", &csPtr)) {
					PutField_CString(hOut, "r0_Cmd", csPtr);
DEBUGLOG(("r0_Cmd = [%s]\n", csPtr));
				}

				// p1_MerId
				if (GetField_CString(hRec, "p1_MerId", &csPtr)) {
					PutField_CString(hOut, "p1_MerId", csPtr);
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
				}

				// r2_TrxId
				if (GetField_CString(hRec, "r2_TrxId", &csPtr)) {
					PutField_CString(hOut, "r2_TrxId", csPtr);
DEBUGLOG(("r2_TrxId = [%s]\n", csPtr));
				}

				// r3_PayInfo
				if (GetField_CString(hRec, "r3_PayInfo", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("r3_PayInfo:code_url = [%s]\n", csPtr));
				}

				// r4_Amt
				if (GetField_CString(hRec, "r4_Amt", &csPtr)) {
					PutField_CString(hOut, "amount", csPtr);
DEBUGLOG(("r4_Amt:amount = [%s]\n", csPtr));
				}

				// r8_Order
				if (GetField_CString(hRec, "r8_Order", &csPtr)) {
					PutField_CString(hOut, "requestId", csPtr);
DEBUGLOG(("r8_Order:requestId = [%s]\n", csPtr));
				}

				// hmac
				if (GetField_CString(hRec, "hmac", &csPtr)) {
					PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("hmac:sign = [%s]\n", csPtr));
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
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	char	csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildRspAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildInqRspAuthData(hIn);
	}

	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	/* p1_MerId (result) */
	strcpy(csTag, "psp_merchant_id");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r0_Cmd (init & result) */
	strcpy(csTag, "r0_Cmd");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* p1_MerId (init) */
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r1_Code (result) */
	strcpy(csTag, "status");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r1_Code (init) */
	strcpy(csTag, "return_code");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r2_TrxId (result) */
	strcpy(csTag, "tid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r2_TrxId (init) */
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/***** result begin *****/

	/* r3_Amt */
	strcpy(csTag, "psp_txn_amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r4_Cur */
	strcpy(csTag, "psp_txn_ccy");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r5_Pid */
	strcpy(csTag, "r5_Pid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r6_Order */
	strcpy(csTag, "txn_seq");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r8_MP */
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r9_BType */
	strcpy(csTag, "r9_BType");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* ro_BankOrderId */
	strcpy(csTag, "ro_BankOrderId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rp_PayDate */
	strcpy(csTag, "rp_PayDate");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/***** result end *****/

	/***** init begin *****/

	/* r3_PayInfo */
	strcpy(csTag, "code_url");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r4_Amt */
	strcpy(csTag, "amount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r5_OpenId */
	strcpy(csTag, "r5_OpenId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r6_AuthCode */
	strcpy(csTag, "r6_AuthCode");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r7_Desc */
	strcpy(csTag, "return_msg");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r8_Order */
	strcpy(csTag, "requestId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/***** init end *****/

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
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
			strcat((char*)csBuf, MY_XJR_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_XJR_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_XJR_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_XJR_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_XJR_FIELD_TOKEN);
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

		// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD_INQ));
		strcat((char*)outMsg, "p0_Cmd");
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, PD_P0_CMD_INQ);
		strcat((char*)outMsg, MY_XJR_TOKEN);

		// p1_MerId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("p1_MerId = [%s]\n", csTmp));
			strcat((char*)outMsg, "p1_MerId");
			strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJR_TOKEN);
		}
		else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
			iRet = PD_ERR;
		}

		// p2_Order
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("p2_Order = [%s]\n", csTmp));
			strcat((char*)outMsg, "p2_Order");
			strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJR_TOKEN);
		}
		else {
DEBUGLOG(("***txn_seq is missing\n"));
			iRet = PD_ERR;
		}

		// hmac
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("hmac = [%s]\n", csTmp));
			strcat((char*)outMsg, "hmac");
			strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJR_TOKEN);
		}
		else {
DEBUGLOG(("***sign is missing\n"));
			iRet = PD_ERR;
		}
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

	// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD_INQ));
	strcat((char*)csBuf, PD_P0_CMD_INQ);

	// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}
	else {
DEBUGLOG(("psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

	// p2_Order
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("p2_Order = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}
	else {
DEBUGLOG(("txn_seq is missing\n"));
		iRet = PD_ERR;
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildInqAuthData() auth_data = [%s]\n", csBuf));
DEBUGLOG(("BuildInqAuthData() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownInqRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	struct json_object *jobj;
	enum json_type type;

	jobj = json_tokener_parse((const char *)inMsg);
	if (jobj != NULL) {
		json_object_object_foreach(jobj, key, val) {
			type = json_object_get_type(val);
			switch (type) {
				case json_type_string:
					PutField_CString(hOut, key, json_object_get_string(val));
					break;
				default:
DEBUGLOG(("BreakDownInqRspMsg:: unsupported type\n"));
					break;
			}
		}

		// r3_Amt
		if (GetField_CString(hOut, "r3_Amt", &csPtr)) {
DEBUGLOG(("r3_Amt:txn_amt = [%s]\n", csPtr));
			PutField_CString(hOut, "txn_amt", csPtr);
		}
		else {
DEBUGLOG(("r3_Amt:txn_amt not found\n"));
		}

		// r6_Order
		if (GetField_CString(hOut, "r6_Order", &csPtr)) {
DEBUGLOG(("r6_Order:txn_seq = [%s]\n", csPtr));
			PutField_CString(hOut, "txn_seq", csPtr);
		}
		else {
DEBUGLOG(("r6_Order:txn_seq not found\n"));
		}

		// rb_PayStatus
		if (GetField_CString(hOut, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("rb_PayStatus:status = [%s]\n", csPtr));
			PutField_CString(hOut, "status", csPtr);
		}
		else {
DEBUGLOG(("rb_PayStatus:status not found\n"));
		}

		// hmac
		if (GetField_CString(hOut, "hmac", &csPtr)) {
DEBUGLOG(("hmac:sign = [%s]\n", csPtr));
			PutField_CString(hOut, "sign", csPtr);
		}
		else {
DEBUGLOG(("hmac:sign not found\n"));
		}
	} else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	json_object_put(jobj);

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownInqRspMsg Exit\n"));
	return iRet;
}


int BuildInqRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	char	csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildInqRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	/* r0_Cmd */
	strcpy(csTag, "r0_Cmd");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* p1_MerId */
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r1_Code */
	strcpy(csTag, "r1_Code");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r2_TrxId */
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r3_Amt */
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r4_Cur */
	strcpy(csTag, "r4_Cur");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r6_Order */
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r8_MP */
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rb_PayStatus */
	strcpy(csTag, "rb_PayStatus");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rd_RefundAmt */
	strcpy(csTag, "rd_RefundAmt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rc_RefundCount */
	strcpy(csTag, "rc_RefundCount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csBuf;
	char *csPtr;
	char csTag[PD_TAG_LEN + 1];

DEBUGLOG(("BuildCallbackAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	// p1_MerId
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r0_Cmd
DEBUGLOG(("r0_Cmd = [%s]\n", PD_P0_CMD));
	strcat((char*)csBuf, PD_P0_CMD);

	// r1_Code (rb_PayStatus)
	if (GetField_CString(hIn, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("r1_Code = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r2_TrxId
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r3_Amt
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r4_Cur
DEBUGLOG(("r4_Cur = [%s]\n", PD_R4_CUR));
	strcat((char*)csBuf, PD_R4_CUR);

	// r5_Pid
DEBUGLOG(("r5_Pid = [%s]\n", PD_P5_PID));
	strcat((char*)csBuf, PD_P5_PID);

	// r6_Order
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r8_MP
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r9_BType
DEBUGLOG(("r9_BType = [%s]\n", PD_R9_BTYPE));
	strcat((char*)csBuf, PD_R9_BTYPE);

	// ro_BankOrderId

	// rp_PayDate

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildCallbackAuthData() auth_data = [%s]\n", csBuf));
DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;
	char csTag[PD_TAG_LEN + 1];

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	// p1_MerId
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r0_Cmd
	strcpy(csTag, "r0_Cmd");
DEBUGLOG(("%s = [%s]\n", csTag, PD_P0_CMD));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P0_CMD);
	strcat((char*)outMsg, MY_XJR_TOKEN);

	// r1_Code
	strcpy(csTag, "r1_Code");
	if (GetField_CString(hIn, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r2_TrxId
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r3_Amt
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r4_Cur
	strcpy(csTag, "r4_Cur");
DEBUGLOG(("%s = [%s]\n", csTag, PD_R4_CUR));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_R4_CUR);
	strcat((char*)outMsg, MY_XJR_TOKEN);

	// r5_Pid
	strcpy(csTag, "r5_Pid");
DEBUGLOG(("%s = [%s]\n", csTag, PD_P5_PID));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P5_PID);
	strcat((char*)outMsg, MY_XJR_TOKEN);

	// r6_Order
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r8_MP
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	// r9_BType
	strcpy(csTag, "r9_BType");
DEBUGLOG(("%s = [%s]\n", csTag, PD_R9_BTYPE));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
	strcat((char*)outMsg, PD_R9_BTYPE);
	strcat((char*)outMsg, MY_XJR_TOKEN);

	// ro_BankOrderId

	// rp_PayDate

	// hmac
	strcpy(csTag, "hmac");
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJR_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJR_TOKEN);
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit\n"));
	FREE_ME(csPtr);
	return iRet;
}

