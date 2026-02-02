/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/02/12		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "HxqMsg.h"
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

#define PD_SUCCESS_STATUS	"10000"

OBJPTR(DB);
OBJPTR(BO);
char cDebug;

char *str_replace(char *orig, char *rep, char *with);

struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};


void HxqMsg(char cdebug)
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
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)csPtr, strlen((char*)csPtr), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
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
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_HXQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_HXQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_HXQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_HXQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_HXQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
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

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// bgUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "bgUrl");
		strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("bgUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("return_url_only is missing\n"));
	}

// curCode
	strcat((char*)csBuf, "curCode");
	strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_HXQ_CUR_CODE);
	strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("curCode = [%s]\n", MY_HXQ_CUR_CODE));

// merchantNo
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merchantNo");
		strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("merchantNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// orderAmount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat((char*)csBuf, "orderAmount");
		strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("orderAmount = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// orderNo
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, "orderNo");
		strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("orderNo = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

// orderSource
	strcat((char*)csBuf, "orderSource");
	strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_HXQ_ORDER_SRC);
	strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("orderSource = [%s]\n", MY_HXQ_ORDER_SRC));

// orderTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN + 1];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat((char*)csBuf, "orderTime");
			strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
			strcat((char*)csBuf, csRaw);
			strcat((char*)csBuf, MY_HXQ_TOKEN);
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

// payChannelCode
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
                strcat((char*)csBuf, "payChannelCode");
                strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
                DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
                if ((DBObjPtr)(csPtr,PD_CHANNEL_HXPAY_QR, PD_CHINA , csOutBankCode)) {
DEBUGLOG(("payChannelCode = [%s]\n", csOutBankCode));
                        strcat((char*)csBuf, csOutBankCode);
                } else {
                        iRet = PD_ERR;
DEBUGLOG(("no bank code mapping\n"));
                }
                strcat((char*)csBuf, MY_HXQ_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
	}

// service
	strcat((char*)csBuf, "service");
	strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_HXQ_SERVICE);
	strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("service = [%s]\n", MY_HXQ_SERVICE));

// signType
	strcat((char*)csBuf, "signType");
	strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_HXQ_SIGN_TYPE);
	strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("signType = [%s]\n", MY_HXQ_SIGN_TYPE));

//timeOutExpress
	if (GetField_Int(hIn, "time_expire", &iTmp)) {
		int iMinutes = (int)(iTmp/60);
		char csTimeOut[PD_DATETIME_LEN + 1];
		sprintf(csTimeOut,"%dm",iMinutes);
		strcat((char*)csBuf, "timeOutExpress");
		strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
		strcat((char*)csBuf, csTimeOut);
		strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("timeOutExpress = [%s]\n", csTimeOut));
	}

// version
	strcat((char*)csBuf, "version");
	strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
	strcat((char*)csBuf, MY_HXQ_VERSION);
	//strcat((char*)csBuf, MY_HXQ_TOKEN);
DEBUGLOG(("version = [%s]\n", MY_HXQ_VERSION));

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int     iRet = PD_OK;
	char	*csPtr;
	char    csMsg[PD_MAX_BUFFER + 1];
	hash_t 	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

DEBUGLOG(("BreakDownMsg()\n"));
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
					strcat((char*)csMsg, MY_HXQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_HXQ_TOKEN);
				break;
				default:
DEBUGLOG(("BreakDownMsg:: unsupported type\n"));
				break;
			}
		}
	}
		
	if (Str2Cls(hRec, (char *)csMsg, MY_HXQ_TOKEN, MY_HXQ_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)csMsg);

// merchantNo
		if (GetField_CString(hRec, "merchantNo", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("merchantNo:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("merchantNo:psp_merchant_id not found\n"));
		}

// orderNo
		if (GetField_CString(hRec, "orderNo", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("orderNo:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderNo:txn_seq not found\n"));
		}

// cxOrderNo
		if (GetField_CString(hRec, "cxOrderNo", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("cxOrderNo:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("cxOrderNo:tid not found\n"));
		}

//version 
		if (GetField_CString(hRec, "version", &csPtr)) {
DEBUGLOG(("version = [%s]\n", csPtr));
		}

//payChannelCode
		if (GetField_CString(hRec, "payChannelCode", &csPtr)) {
DEBUGLOG(("payChannelCode = [%s]\n", csPtr));
		}

//productName 
		if (GetField_CString(hRec, "productName", &csPtr)) {
DEBUGLOG(("productName = [%s]\n", csPtr));
		}

// orderAmount
		if (GetField_CString(hRec, "orderAmount", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("orderAmount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("orderAmount:txn_amt not found\n"));
		}
//curCode
		if (GetField_CString(hRec, "curCode", &csPtr)) {
DEBUGLOG(("curCode = [%s]\n", csPtr));
		}

//orderTime
		if (GetField_CString(hRec, "orderTime", &csPtr)) {
DEBUGLOG(("orderTime= [%s]\n", csPtr));
		}

// dealTime
		if (GetField_CString(hRec, "dealTime", &csPtr)) {
			char csTxnDate[PD_DATE_LEN + 1];
			strncpy(csTxnDate, csPtr, PD_DATE_LEN);
			csTxnDate[PD_DATE_LEN] = '\0';

			PutField_CString(hOut, "fundin_date", csPtr);
			PutField_CString(hOut, "txn_date", csTxnDate);
DEBUGLOG(("dealTime:fundin_date = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("dealTime:fundin_date not found\n"));
		}

//ext1 
		if (GetField_CString(hRec, "ext1", &csPtr)) {
DEBUGLOG(("ext1 = [%s]\n", csPtr));
		}

//ext2 
		if (GetField_CString(hRec, "ext2", &csPtr)) {
DEBUGLOG(("ext2 = [%s]\n", csPtr));
		}

//fee 
		if (GetField_CString(hRec, "fee", &csPtr)) {
DEBUGLOG(("fee = [%s]\n", csPtr));
		}


// dealCode
		if (GetField_CString(hRec, "dealCode", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("dealCode:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("dealCode:status not found\n"));
		}

//dealMsg
		if (GetField_CString(hRec, "dealMsg", &csPtr)) {
DEBUGLOG(("dealMsg = [%s]\n", csPtr));
		}

//signType
		if (GetField_CString(hRec, "signType", &csPtr)) {
DEBUGLOG(("signType = [%s]\n", csPtr));
		}


// sign
		if (GetField_CString(hRec, "sign", &csPtr)) {
			char csDst[PD_TMP_MSG_BUF_LEN + 1];
			int iLen = 0;
			urldecode((const unsigned char*)csPtr, strlen(csPtr), (unsigned char *)csDst, &iLen);
			PutField_CString(hOut, "sign", csDst);
DEBUGLOG(("sign:sign = [%s]\n", csDst));
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
	return  iRet;
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
	int	iTmp = 0;
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
			strcat((char*)csBuf, MY_HXQ_FIELD_TOKEN);
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

/* service */
	strcat((char*)outMsg, "service");
	strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_HXQ_SERVICE);
	strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("service = [%s]\n", MY_HXQ_SERVICE));


/* merchantNo */
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("merchantNo = [%s]\n", csPtr));
		strcat((char*)outMsg, "merchantNo");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
	} else {
DEBUGLOG(("merchantNo is missing\n"));
	}

//bgUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "bgUrl");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("bgUrl = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}

//version
	strcat((char*)outMsg, "version");
	strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_HXQ_VERSION);
	strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("version = [%s]\n", MY_HXQ_VERSION));


//payChannelCode
        if (GetField_CString(hIn, "bank_code", &csPtr)) {
                strcat((char*)outMsg, "payChannelCode");
                strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
                DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
                if ((DBObjPtr)(csPtr,PD_CHANNEL_HXPAY_QR, PD_CHINA , csOutBankCode)) {
DEBUGLOG(("payChannelCode = [%s]\n", csOutBankCode));
                        strcat((char*)outMsg, csOutBankCode);
                } else {
                        iRet = PD_ERR;
DEBUGLOG(("no bank code mapping\n"));
                }
                strcat((char*)outMsg, MY_HXQ_TOKEN);
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("bank_code is missing\n"));
        }


/* orderNo */
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("orderNo = [%s]\n", csPtr));
		strcat((char*)outMsg, "orderNo");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
	} else {
DEBUGLOG(("orderNo is missing\n"));
	}

/* orderAmount */
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
DEBUGLOG(("orderAmount = [%s]\n", csTmpAmt));
		strcat((char*)outMsg, "orderAmount");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csTmpAmt);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
	} else {
DEBUGLOG(("orderAmount is missing\n"));
	}


//curCode
	strcat((char*)outMsg, "curCode");
	strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_HXQ_CUR_CODE);
	strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("curCode = [%s]\n", MY_HXQ_CUR_CODE));


//orderTime
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csTmp2 = NULL;
		char csRaw[PD_DATETIME_LEN + 1];
		if (GetField_CString(hIn, "local_tm_time", &csTmp2)) {
			sprintf(csRaw, "%s%s", csPtr, csTmp2);
			strcat((char*)outMsg, "orderTime");
			strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
			strcat((char*)outMsg, csRaw);
			strcat((char*)outMsg, MY_HXQ_TOKEN);
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

//timeOutExpress
	if (GetField_Int(hIn, "time_expire", &iTmp)) {
		int iMinutes = (int)(iTmp/60);
		char csTimeOut[PD_DATETIME_LEN + 1];
		sprintf(csTimeOut,"%dm",iMinutes);
		strcat((char*)outMsg, "timeOutExpress");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		strcat((char*)outMsg, csTimeOut);
		strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("timeOutExpress = [%s]\n", csTimeOut));
	}


//orderSource
	strcat((char*)outMsg, "orderSource");
	strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_HXQ_ORDER_SRC);
	strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("orderSource = [%s]\n", MY_HXQ_ORDER_SRC));

//signType
	strcat((char*)outMsg, "signType");
	strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_HXQ_SIGN_TYPE);
	strcat((char*)outMsg, MY_HXQ_TOKEN);
DEBUGLOG(("signType = [%s]\n", MY_HXQ_SIGN_TYPE));


/* sign */
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("origianl sign = [%s]\n", csPtr));
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_HXQ_FIELD_TOKEN);
		//strcat((char*)outMsg, url_encode(csPtr));
		strcat((char*)outMsg, str_replace(str_replace(str_replace(url_encode(csPtr),"%2f","%2F"),"%2b","%2B"),"%3d","%3D"));
DEBUGLOG(("sign = [%s]\n", str_replace(str_replace(str_replace(url_encode(csPtr),"%2f","%2F"),"%2b","%2B"),"%3d","%3D")));
	} else {
DEBUGLOG(("sign is missing\n"));
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
	char    *csReturnCode = NULL;
	char    csMsg[PD_MAX_BUFFER + 1];
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
					PutField_CString(hRec, key, json_object_get_string(val));

					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_HXQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_HXQ_TOKEN);
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}

		
		if (GetField_CString(hRec, "dealCode", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "dealMsg", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, PD_SUCCESS_STATUS)) {

				PutField_CString(hOut, "in_msg", (char *)csMsg);

				// codeUrl
				if (GetField_CString(hRec, "codeUrl", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("codeUrl = [%s]\n", csPtr));
				}
				//merchantNo 
				if (GetField_CString(hRec, "merchantNo", &csPtr)) {
					PutField_CString(hOut, "merchantNo", csPtr);
DEBUGLOG(("merchantNo = [%s]\n", csPtr));
				}

				// sign
				if (GetField_CString(hRec, "sign", &csPtr)) {
					int iLen = 0;
					char csSign[PD_TMP_MSG_BUF_LEN];
					urldecode((const unsigned char*)csPtr, strlen(csPtr), (unsigned char*)csSign, &iLen);
					csSign[iLen] = '\0';
					PutField_CString(hOut, "sign", csSign);
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


int BuildRspAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	//int	iIsInitReq = PD_FALSE;
	//char	*csPtr;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

/*
	GetField_Int(hIn, "isInitReq", &iIsInitReq);
DEBUGLOG(("isInitReq = [%d]\n", iIsInitReq));

*/
	if (GetField_CString(hIn, "in_msg", &inMsg)) {
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_HXQ_TOKEN, MY_HXQ_FIELD_TOKEN) == PD_OK) {
//DEBUGLOG(("iPairCnt = [%d]\n", iPairCnt));
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_HXQ_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_HXQ_TOKEN);
				}
			}
		}
	}
	if(strlen(csBuf)>1) csBuf[strlen(csBuf) - 1] = '\0';

	PutField_CString(hIn, "auth_data",csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
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

