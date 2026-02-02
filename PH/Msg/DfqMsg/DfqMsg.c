/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/11/26		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DfqMsg.h"
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


void DfqMsg(char cdebug)
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
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		if (!strcmp(csPtr, MY_DFQ_SUCCESS_STATUS))
			strcat((char*)outMsg,"SUCCESS");
		else
			strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)(url_encode(csPtr)), strlen((char*)(url_encode(csPtr))), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
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
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_DFQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_DFQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_DFQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_DFQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_DFQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
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
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (GetField_Int(hIn, "is_init_req", &iTmp)) {
// amount
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
			strcat((char*)csBuf, "amount");
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
			strcat((char*)csBuf, csTmpAmt);
			strcat((char*)csBuf, MY_DFQ_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
		}
		else {
DEBUGLOG(("psp_txn_amt is missing\n"));
		}

// merchantCode
		if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
			strcat((char*)csBuf, "merchantCode");
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_DFQ_TOKEN);
DEBUGLOG(("merchantCode = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("psp_merchant_id is missing\n"));
		}

// noticeUrl
		if (GetField_CString(hIn, "return_url_only", &csPtr)) {
			strcat((char*)csBuf, "noticeUrl");
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_DFQ_TOKEN);
DEBUGLOG(("noticeUrl = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("return_url_only is missing\n"));
		}

// orderCreateTime
		if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
DEBUGLOG(("local_tm_date = [%s]\n", csPtr));
			char *csPtr2;
			char csDateTime[PD_DATETIME_LEN * 2];
			if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
DEBUGLOG(("local_tm_time = [%s]\n", csPtr2));
				sprintf(csDateTime, "%s%s", csPtr, csPtr2);
				strcat((char*)csBuf, "orderCreateTime");
				strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
				strcat((char*)csBuf, csDateTime);
				strcat((char*)csBuf, MY_DFQ_TOKEN);
DEBUGLOG(("orderCreateTime = [%s]\n", csDateTime));
			}
			else {
DEBUGLOG(("local_tm_time is missing\n"));
			}
		}
		else {
DEBUGLOG(("local_tm_date is missing\n"));
		}

// outOrderId
		if (GetField_CString(hIn, "order_num", &csPtr)) {
			strcat((char*)csBuf, "outOrderId");
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_DFQ_TOKEN);
DEBUGLOG(("outOrderId = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("order_num is missing\n"));
		}

// payChannel
		if (GetField_CString(hIn, "bank_code", &csPtr)) {
			strcat((char*)csBuf, "payChannel");
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
			if ((DBObjPtr)(csPtr, "DFQ", "CN", csOutBankCode)) {
				strcat((char*)csBuf, csOutBankCode);
DEBUGLOG(("payChannel = [%s]\n", csOutBankCode));
			}
			else {
DEBUGLOG(("no bank code mapping\n"));
			}
			strcat((char*)csBuf, MY_DFQ_TOKEN);
		}
		else {
DEBUGLOG(("bank_code is missing\n"));
		}
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

	if (Str2Cls(hRec, (char *)inMsg, MY_DFQ_TOKEN, MY_DFQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)inMsg);

// merchantCode
		if (GetField_CString(hRec, "merchantCode", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("merchantCode:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("merchantCode:psp_merchant_id not found\n"));
		}

// instructCode
		if (GetField_CString(hRec, "instructCode", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("instructCode:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("instructCode:tid not found\n"));
		}

// outOrderId
		if (GetField_CString(hRec, "outOrderId", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("outOrderId:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("outOrderId:txn_seq not found\n"));
		}

// transTime
		if (GetField_CString(hRec, "transTime", &csPtr)) {
			char csTxnDate[PD_DATE_LEN + 1];
			strncpy(csTxnDate, csPtr, PD_DATE_LEN);
			csTxnDate[PD_DATE_LEN] = '\0';

			PutField_CString(hOut, "fundin_date", csPtr);
			PutField_CString(hOut, "txn_date", csTxnDate);
DEBUGLOG(("transTime:fundin_date = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("transTime:fundin_date not found\n"));
		}

// totalAmount
		if (GetField_CString(hRec, "totalAmount", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("totalAmount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("totalAmount:txn_amt not found\n"));
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

// status
		PutField_CString(hOut, "status", MY_DFQ_SUCCESS_STATUS);
DEBUGLOG(("status = [%s]\n", MY_DFQ_SUCCESS_STATUS));
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
			strcat((char*)csBuf, MY_DFQ_FIELD_TOKEN);
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

// model
	strcat((char*)outMsg, "model");
	strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_DFQ_MODEL);
	strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("model = [%s]\n", MY_DFQ_MODEL));

// merchantCode
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)outMsg, "merchantCode");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("merchantCode = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
	}

// outOrderId
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)outMsg, "outOrderId");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("outOrderId = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***order_num is missing\n"));
	}

// deviceNo (optional)

// amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat((char*)outMsg, "amount");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, (char*)csTmpAmt);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
	}

// goodsName (optional)

// goodsExplain (optional)

// ext (optional)

// orderCreateTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
DEBUGLOG(("local_tm_date = [%s]\n", csPtr));
		char *csPtr2;
		char csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
DEBUGLOG(("local_tm_time = [%s]\n", csPtr2));
			sprintf(csDateTime, "%s%s", csPtr, csPtr2);
			strcat((char*)outMsg, "orderCreateTime");
			strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
			strcat((char*)outMsg, csDateTime);
			strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("orderCreateTime = [%s]\n", csDateTime));
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

// noticeUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "noticeUrl");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("noticeUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}

// goodsMark (optional)

// payChannel
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)outMsg, "payChannel");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "DFQ", "CN", csOutBankCode)) {
			strcat((char*)outMsg, csOutBankCode);
DEBUGLOG(("payChannel = [%s]\n", csOutBankCode));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***no bank code mapping\n"));
		}
		strcat((char*)outMsg, MY_DFQ_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***bank_code is missing\n"));
	}

// ip
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)outMsg, "ip");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DFQ_TOKEN);
DEBUGLOG(("ip = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***org_ip_addr is missing\n"));
	}

// sign
	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_DFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		//strcat((char*)outMsg, MY_DFQ_TOKEN);
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
	char	csMsg[PD_MAX_BUFFER + 1];
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	struct json_object *jobj;
	enum json_type type;
	enum json_type type2;

	jobj = json_tokener_parse((const char *)inMsg);
	if (jobj != NULL) {
		json_object_object_foreach(jobj, key, val) {
			type = json_object_get_type(val);
			switch (type) {
				case json_type_string:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_DFQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
//DEBUGLOG(("json_type_string = [%s]\n", json_object_get_string(val)));
					strcat((char*)csMsg, MY_DFQ_TOKEN);
				break;
				case json_type_object:
DEBUGLOG(("object type\n"));
					json_object_object_foreach(val, key2, val2) {
						type2 = json_object_get_type(val2);
						switch (type2) {
							case json_type_string:
								strcat((char*)csMsg, key2);
								strcat((char*)csMsg, MY_DFQ_FIELD_TOKEN);
								strcat((char*)csMsg, json_object_get_string(val2));
								strcat((char*)csMsg, MY_DFQ_TOKEN);
							break;
							default:
DEBUGLOG(("unsupported type\n"));
							break;
						}
					}
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}
	}

DEBUGLOG(("csMsg = [%s]\n", csMsg));

	if (Str2Cls(hRec, (char *)csMsg, MY_DFQ_TOKEN, MY_DFQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)csMsg);

		if (GetField_CString(hRec, "code", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("code:return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "msg", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("msg:return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_DFQ_SUCCESS_STATUS)) {
				// outOrderId
				if (GetField_CString(hRec, "outOrderId", &csPtr)) {
					PutField_CString(hOut, "requestId", csPtr);
DEBUGLOG(("outOrderId:requestId = [%s]\n", csPtr));
				}

				// url
				if (GetField_CString(hRec, "url", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("url:code_url = [%s]\n", csPtr));
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
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (GetField_CString(hIn, "in_msg", &inMsg)) {
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_DFQ_TOKEN, MY_DFQ_FIELD_TOKEN) == PD_OK) {
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude code, msg, sign
				if (strcmp(k_v_pair[iTmp].key, "code")
					&& strcmp(k_v_pair[iTmp].key, "msg")
					&& strcmp(k_v_pair[iTmp].key, "sign")
					&& strcmp(k_v_pair[iTmp].key, "ext")
				) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_DFQ_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_DFQ_TOKEN);
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


char *str_replace(char *orig, char *rep, char *with) {
        char *result;   // the return string
        char *ins;      // the next insert point
        char *tmp;      // varies
        int len_rep;    // length of rep (the string to remove)
        int len_with;   // length of with (the string to replace rep with)
        int len_front;  // distance between rep and end of last rep
        int count;      // number of replacements

        if (!orig || !rep)
                return NULL;
        len_rep = strlen(rep);
        if (len_rep == 0)
                return NULL; // empty rep causes infinite loop during count
        if (!with)
                with = "";
        len_with = strlen(with);

        // count the number of replacements needed
        ins = orig;
        for (count = 0; (tmp = strstr(ins, rep)); ++count) {
                ins = tmp + len_rep;
        }

        tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

        if (!result)
                return NULL;

        // first time through the loop, all the variable are set correctly
        // from here on,
        //    tmp points to the end of the result string
        //    ins points to the next occurrence of rep in orig
        //    orig points to the remainder of orig after "end of rep"
        while (count--) {
                ins = strstr(orig, rep);
                len_front = ins - orig;
                tmp = strncpy(tmp, orig, len_front) + len_front;
                tmp = strcpy(tmp, with) + len_with;
                orig += len_front + len_rep; // move to next "end of rep"
        }
        strcpy(tmp, orig);
        return result;
}

