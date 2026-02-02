/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2019/07/11		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "TpqMsg.h"
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


void TpqMsg(char cdebug)
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
		strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
		if (!strcmp(csPtr, MY_TPQ_SUCCESS_STATUS))
			strcat((char*)outMsg,"SUCCESS");
		else
			strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_TPQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)(url_encode(csPtr)), strlen((char*)(url_encode(csPtr))), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_TPQ_TOKEN);
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
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_TPQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_TPQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_TPQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_TPQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_TPQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
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
	int	iTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char	csDateTime[PD_DATETIME_LEN * 2];

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

	if (GetField_Int(hIn, "is_init_req", &iTmp)) {
// amount
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
			strcat((char*)csBuf, "amount");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csTmpAmt);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
		}

// bankId (optional)

// body
		strcat((char*)csBuf, "body");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_TPQ_BODY);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("body = [%s]\n", MY_TPQ_BODY));

// channel
		strcat((char*)csBuf, "channel");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_TPQ_CHANNEL_MOB);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("channel = [%s]\n", MY_TPQ_CHANNEL_MOB));

// expireTime
		if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
			char *csPtr2;
			if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
				sprintf(csDateTime, "%s%s", csPtr, csPtr2);
				if (GetField_CString(hIn, "psp_key_id", &csPtr)) {
					struct tm orig_tm;
					time_t epoch;
					struct tm *converted_tm;
					char csConverted[PD_DATETIME_LEN * 2];
					if (strptime((const char*)csDateTime, "%Y%m%d%H%M%S", &orig_tm) != NULL) {
						epoch = mktime(&orig_tm);
						epoch = epoch + atoi(csPtr);
						converted_tm = localtime(&epoch);
						strftime(csConverted, sizeof(csConverted), "%Y%m%d%H%M%S", converted_tm);
						strcat((char*)csBuf, "expireTime");
						strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
						strcat((char*)csBuf, csConverted);
						strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("expireTime = [%s]\n", csConverted));
					}
				}
				else {
					iRet = PD_ERR;
DEBUGLOG(("psp_key_id is missing\n"));
				}
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

// merId
		if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
			strcat((char*)csBuf, "merId");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("merId = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
		}

// notifyUrl
		if (GetField_CString(hIn, "return_url_only", &csPtr)) {
			strcat((char*)csBuf, "notifyUrl");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("notifyUrl = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
		}

// payType
		strcat((char*)csBuf, "payType");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_TPQ_PAYTYPE_QR);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("payType = [%s]\n", MY_TPQ_PAYTYPE_QR));

// returnUrl
		if (GetField_CString(hIn, "return_url_only", &csPtr)) {
			strcat((char*)csBuf, "returnUrl");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("returnUrl = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
		}

// seqId
		if (GetField_CString(hIn, "order_num", &csPtr)) {
			strcat((char*)csBuf, "seqId");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("seqId = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("order_num is missing\n"));
		}

// subject
		strcat((char*)csBuf, "subject");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_TPQ_SUBJECT);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("subject = [%s]\n", MY_TPQ_SUBJECT));

// transDate
		if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
			strcat((char*)csBuf, "transDate");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("transDate = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("local_tm_date is missing\n"));
		}

// transTime
		if (GetField_CString(hIn, "local_tm_time", &csPtr)) {
			strcat((char*)csBuf, "transTime");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_TPQ_TOKEN);
DEBUGLOG(("transTime = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("local_tm_time is missing\n"));
		}

// version
		strcat((char*)csBuf, "version");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_TPQ_VERSION);
DEBUGLOG(("version = [%s]\n", MY_TPQ_VERSION));

		PutField_CString(hIn, "outmsg_data", csBuf);
	} else {
		strcat((char*)csBuf, " ");
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

	if (Str2Cls(hRec, (char *)inMsg, MY_TPQ_TOKEN, MY_TPQ_FIELD_TOKEN) == PD_OK) {
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

// stat
		if (GetField_CString(hRec, "stat", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("stat:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("stat:status not found\n"));
		}

// seqId
		if (GetField_CString(hRec, "seqId", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("seqId:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("seqId:txn_seq not found\n"));
		}

// amount
		if (GetField_CString(hRec, "amount", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("amount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("amount:txn_amt not found\n"));
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
	char	*csTmp = NULL;
	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0] = '\0';

/* psp_url */
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("psp_url = [%s]\n", csURL));
DEBUGLOG(("request_function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
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

// outmsg_data
	if (GetField_CString(hIn, "outmsg_data", &csTmp)) {
		strcat((char*)outMsg, csTmp);
		strcat((char*)outMsg, MY_TPQ_TOKEN);
DEBUGLOG(("outmsg_data = [%s]\n", csTmp));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***outmsg_data is missing\n"));
	}

// sign
	if (GetField_CString(hIn, "sign", &csTmp)) {
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
		strcat((char*)outMsg, url_encode(csTmp));
DEBUGLOG(("sign = [%s]\n", csTmp));
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
	char	*csReturnCode = NULL;
	char	csMsg[PD_MAX_BUFFER + 1];
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

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
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_TPQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_TPQ_TOKEN);
				break;
				case json_type_int:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_TPQ_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%d", (char*)csMsg, json_object_get_int(val));
					strcat((char*)csMsg, MY_TPQ_TOKEN);
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}
	}

	if (Str2Cls(hRec, (char *)csMsg, MY_TPQ_TOKEN, MY_TPQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", csMsg);

		if (GetField_CString(hRec, "code", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("code:return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "msg", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("msg:return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_TPQ_SUCCESS_STATUS)) {
				// merId
				if (GetField_CString(hRec, "merId", &csPtr)) {
					PutField_CString(hOut, "merId", csPtr);
DEBUGLOG(("merId = [%s]\n", csPtr));
				}

				// seqId
				if (GetField_CString(hRec, "seqId", &csPtr)) {
					PutField_CString(hOut, "requestId", csPtr);
DEBUGLOG(("seqId:requestId = [%s]\n", csPtr));
				}

				// tradeNo
				if (GetField_CString(hRec, "tradeNo", &csPtr)) {
					PutField_CString(hOut, "tradeNo", csPtr);
DEBUGLOG(("tradeNo = [%s]\n", csPtr));
				}

				// amount
				if (GetField_CString(hRec, "amount", &csPtr)) {
					PutField_CString(hOut, "amount", csPtr);
DEBUGLOG(("amount = [%s]\n", csPtr));
				}

				// orderDate
				if (GetField_CString(hRec, "orderDate", &csPtr)) {
					PutField_CString(hOut, "orderDate", csPtr);
DEBUGLOG(("orderDate = [%s]\n", csPtr));
				}

				// stat
				if (GetField_CString(hRec, "stat", &csPtr)) {
					PutField_CString(hOut, "stat", csPtr);
DEBUGLOG(("stat = [%s]\n", csPtr));
				}

				// payResult
				if (GetField_CString(hRec, "payResult", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("payResult:code_url = [%s]\n", csPtr));
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
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
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
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_TPQ_TOKEN, MY_TPQ_FIELD_TOKEN) == PD_OK) {
//DEBUGLOG(("iPairCnt = [%d]\n", iPairCnt));
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_TPQ_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_TPQ_TOKEN);
				}
			}
		}
	}

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
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_TPQ_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_TPQ_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
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

// outmsg_data
		if (GetField_CString(hIn, "outmsg_data", &csTmp)) {
DEBUGLOG(("outmsg_data = [%s]\n", csTmp));
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_TPQ_TOKEN);
		}
		else {
DEBUGLOG(("***outmsg_data is missing\n"));
			iRet = PD_ERR;
		}

// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("sign = [%s]\n", csTmp));
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_TPQ_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
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

// merId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("merId = [%s]\n", csPtr));
		strcat((char*)csBuf, "merId");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
	}
	else {
DEBUGLOG(("psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

// seqId
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("seqId = [%s]\n", csPtr));
		strcat((char*)csBuf, "seqId");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
	}
	else {
DEBUGLOG(("txn_seq is missing\n"));
		iRet = PD_ERR;
	}

// transDate
	if (GetField_CString(hIn, "txn_date", &csPtr)) {
DEBUGLOG(("transDate = [%s]\n", csPtr));
		strcat((char*)csBuf, "transDate");
		strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_TPQ_TOKEN);
	}
	else {
DEBUGLOG(("txn_date is missing\n"));
		iRet = PD_ERR;
	}

// version
DEBUGLOG(("version = [%s]\n", MY_TPQ_VERSION));
	strcat((char*)csBuf, "version");
	strcat((char*)csBuf, MY_TPQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_TPQ_VERSION);

	PutField_CString(hIn, "outmsg_data", csBuf);

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
	char	*csReturnCode = NULL;
	char	csMsg[PD_MAX_BUFFER + 1];
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

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
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_TPQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_TPQ_TOKEN);
				break;
				case json_type_int:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_TPQ_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%d", (char*)csMsg, json_object_get_int(val));
					strcat((char*)csMsg, MY_TPQ_TOKEN);
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}
	}

	if (Str2Cls(hRec, (char *)csMsg, MY_TPQ_TOKEN, MY_TPQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", csMsg);

		if (GetField_CString(hRec, "code", &csReturnCode)) {
			// code
DEBUGLOG(("code = [%s]\n", csReturnCode));

			// msg
			if (GetField_CString(hRec, "msg", &csPtr)) {
DEBUGLOG(("msg:fail_reason = [%s]\n", csPtr));
				PutField_CString(hOut, "fail_reason", csPtr);
			}

			if (!strcmp(csReturnCode, MY_TPQ_SUCCESS_STATUS)) {
				RemoveField_CString(hOut, "fail_reason");

				// seqId
				if (GetField_CString(hRec, "seqId", &csPtr)) {
DEBUGLOG(("seqId:txn_seq = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_seq", csPtr);
				} else {
DEBUGLOG(("seqId:txn_seq not found\n"));
				}

				// amount
				if (GetField_CString(hRec, "amount", &csPtr)) {
DEBUGLOG(("amount:txn_amt = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_amt", csPtr);
				} else {
DEBUGLOG(("amount:txn_amt not found\n"));
				}

				// stat
				if (GetField_CString(hRec, "stat", &csPtr)) {
DEBUGLOG(("stat:status = [%s]\n", csPtr));
					PutField_CString(hOut, "status", csPtr);
				} else {
DEBUGLOG(("stat:status not found\n"));
				}

				// sign
				if (GetField_CString(hRec, "sign", &csPtr)) {
DEBUGLOG(("sign = [%s]\n", csPtr));
					PutField_CString(hOut, "sign", csPtr);
				}
				else {
DEBUGLOG(("sign not found\n"));
				}
			}
		}
		else {
DEBUGLOG(("BreakDownInitRspMsg() Invalid Response\n"));
			iRet = PD_ERR;
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
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char	*inMsg;
	int	iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildInqRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (GetField_CString(hIn, "in_msg", &inMsg)) {
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_TPQ_TOKEN, MY_TPQ_FIELD_TOKEN) == PD_OK) {
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_TPQ_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_TPQ_TOKEN);
				}
			}
		}
	}

	csBuf[strlen(csBuf) - 1] = '\0';

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;

DEBUGLOG(("BuildCallbackAuthData() Start\n"));
DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "in_msg", &csPtr)) {
		strcat((char*)outMsg, csPtr);
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit\n"));
	FREE_ME(csPtr);
	return iRet;
}

