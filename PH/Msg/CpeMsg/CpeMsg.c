/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2017/12/21		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "CpeMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "ObjPtr.h"
#include <time.h>
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include <json-c/json.h>

#define PD_DOUBLE_QUOTE		0x22

OBJPTR(DB);
OBJPTR(BO);
char	cDebug;
void remove_quote(const char *csValue, const int iType, char *csOut);

void	CpeMsg(char cdebug)
{
	cDebug = cdebug;
}

struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csPtr = NULL;
	char*   csBuf;
	char*   csMethod = NULL;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg,csPtr);
		//strcat((char*)outMsg,"?");

// url_method
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
		}

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));

		base64_encode((unsigned char *)outMsg,strlen((const char*)outMsg),csBuf,PD_MAX_BUFFER);
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
		strcat((char*)outMsg,MY_CPE_TOKEN);
		strcat((char*)outMsg,"url_method");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csMethod);
		strcat((char*)outMsg,MY_CPE_TOKEN);
                strcat((char*)outMsg,"ret_status=0");

DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}

	FREE_ME(csBuf);
	return 	iRet;
}


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// server_no
	strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
	strcat((char*)csBuf, MY_CPE_SERVER_NO);
	strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
	strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("server_no = [%s]\n", MY_CPE_SERVER_NO));

// trans_time
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
			strcat((char*)csBuf, csRaw);
			strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
			strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("trans_time = [%s]\n", csRaw));
		}
		else {
DEBUGLOG(("local_tm_time is missing!!\n"));
		}
	}
	else {
DEBUGLOG(("local_tm_date is missing!!\n"));
	}

// account
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("account = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("psp_merchant_id is missing!!\n"));
	}

// amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
	}
	else {
DEBUGLOG(("psp_txn_amt is missing!!\n"));
	}

// pay_mode
	strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
	strcat((char*)csBuf, MY_CPE_PAY_MODE);
	strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
	strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("pay_mode = [%s]\n", MY_CPE_PAY_MODE));

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
	char    csContext[PD_TMP_MSG_BUF_LEN + 1];
	char    csBase64Context[PD_TMP_MSG_BUF_LEN + 1];
	char    csUrlSafeBase64Context[PD_TMP_MSG_BUF_LEN + 1];

	hash_t	*hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	hash_t  *hRec2;
	hRec2 = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec2, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_CPE_TOKEN, MY_CPE_FIELD_TOKEN) == PD_OK) {
// context
		if (GetField_CString(hRec, "context", &csPtr)) {
DEBUGLOG(("urlsafebase64 context = [%s]\n", csPtr));
			csUrlSafeBase64Context[0] = '\0';
			remove_quote(csPtr, PD_DOUBLE_QUOTE, csUrlSafeBase64Context);
			csUrlSafeBase64Context[strlen(csUrlSafeBase64Context)] = '\0';
DEBUGLOG(("urlsafebase64 context = [%s]\n", csUrlSafeBase64Context));

			int i;
			for (i = 0; i < strlen(csUrlSafeBase64Context); i++) {
				if (csUrlSafeBase64Context[i] == '-')  {
					csBase64Context[i] = '+';
				} else if (csUrlSafeBase64Context[i] == '_') {
					csBase64Context[i] = '/';
				} else {
					csBase64Context[i] = csUrlSafeBase64Context[i];
				}
			}
			csBase64Context[i] = '\0';

DEBUGLOG(("base64 context = [%s]\n", csBase64Context));

			int iLen;
			iLen = base64_decode(csBase64Context, (unsigned char *)csContext, PD_TMP_MSG_BUF_LEN);
			if (iLen > 0) {
				csContext[iLen] = '\0';
DEBUGLOG(("context = [%s]\n", csContext));

				if (Str2Cls(hRec2, csContext, MY_CPE_TOKEN, MY_CPE_FIELD_TOKEN) == PD_OK) {
					if (GetField_CString(hRec2, "trans_id", &csPtr)) {
						PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("trans_id:tid = [%s]\n", csPtr));
					}
					else {
DEBUGLOG(("trans_id:tid not found\n"));
					}

					if (GetField_CString(hRec2, "result", &csPtr)) {
						PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("result:status = [%s]\n", csPtr));
					}
					else {
DEBUGLOG(("result:status not found\n"));
					}

					if (GetField_CString(hRec2, "amount", &csPtr)) {
						PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("amount:txn_amt = [%s]\n", csPtr));
					}
					else {
DEBUGLOG(("amount:txn_amt not found\n"));
					}

					if (GetField_CString(hRec2, "app_id", &csPtr)) {
						PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("app_id:txn_seq = [%s]\n", csPtr));
					}
					else {
DEBUGLOG(("app_id:txn_seq not found\n"));
					}

					if (GetField_CString(hRec2, "signature", &csPtr)) {
						PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("signature:sign = [%s]\n", csPtr));
					}
					else {
DEBUGLOG(("signature:sign not found\n"));
					}
				}
				else {
DEBUGLOG(("BreakDownMsg() Str2Cls Failed\n"));
					iRet = PD_ERR;
				}
			}
			else {
DEBUGLOG(("BreakDownMsg() Decode Failed\n"));
				iRet = PD_ERR;
			}
		}
		else {
DEBUGLOG(("context not found\n"));
		}
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);
	hash_destroy(hRec2);
	FREE_ME(hRec2);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}


int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;
	char	csContext[PD_TMP_MSG_BUF_LEN + 1];
	char	csBase64Context[PD_TMP_MSG_BUF_LEN + 1];
	char	csUrlSafeBase64Context[PD_TMP_MSG_BUF_LEN + 1];
	char	csSignature[MY_CPE_SIGNATURE_LEN + 1];
	char	*csSysCode;
	double	dTmp = 0.0;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	memset(outMsg, 0, sizeof(outMsg));

// psp_url
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("psp_url = [%s]\n", csURL));
DEBUGLOG(("request function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_CPE_FIELD_TOKEN);
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

// server_no
	strcpy(csContext, "server_no");
	strcat(csContext, MY_CPE_FIELD_TOKEN);
	strcat(csContext, MY_CPE_SERVER_NO);
	strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("server_no = [%s]\n", MY_CPE_SERVER_NO));

// trans_time
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2 = NULL;
		char csRaw[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			sprintf(csRaw, "%s%s", csPtr, csPtr2);
			strcat(csContext, "trans_time");
			strcat(csContext, MY_CPE_FIELD_TOKEN);
			strcat(csContext, csRaw);
			strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("trans_time = [%s]\n", csRaw));
		}
		else {
DEBUGLOG(("local_tm_time is missing!!\n"));
		}
	}
	else {
DEBUGLOG(("local_tm_date is missing!!\n"));
	}	

// account
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat(csContext, "account");
		strcat(csContext, MY_CPE_FIELD_TOKEN);
		strcat(csContext, csPtr);
		strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("account = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("psp_merchant_id is missing!!\n"));
	}

// amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat(csContext, "amount");
		strcat(csContext, MY_CPE_FIELD_TOKEN);
		strcat(csContext, csTmpAmt);
		strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
	}
	else {
DEBUGLOG(("psp_txn_amt is missing!!\n"));
	}

// pay_mode
	strcat(csContext, "pay_mode");
	strcat(csContext, MY_CPE_FIELD_TOKEN);
	strcat(csContext, MY_CPE_PAY_MODE);
	strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("pay_mode = [%s]\n", MY_CPE_PAY_MODE));

// aging
	strcat(csContext, "aging");
	strcat(csContext, MY_CPE_FIELD_TOKEN);
	strcat(csContext, MY_CPE_AGING);
	strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("aging = [%s]\n", MY_CPE_AGING));

// app_id
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat(csContext, "app_id");
		strcat(csContext, MY_CPE_FIELD_TOKEN);
		strcat(csContext, csPtr);
		strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("app_id = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("order_num is missing!!\n"));
	}

// callback_url
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
		strcat(csContext, "callback_url");
		strcat(csContext, MY_CPE_FIELD_TOKEN);
		strcat(csContext, csPtr);
		strcat(csContext, MY_CPE_TOKEN);
DEBUGLOG(("callback_url = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("fe_url is missing!!\n"));
	}

// notify_url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat(csContext, "notify_url");
		strcat(csContext, MY_CPE_FIELD_TOKEN);
		strcat(csContext, csPtr);
DEBUGLOG(("notify_url = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("return_url_only is missing!!\n"));
	}

// signature
	if (GetField_CString(hIn, "sign", &csPtr)) {
		sprintf(csSignature, "%.*s", MY_CPE_SIGNATURE_LEN, csPtr);
		csSignature[MY_CPE_SIGNATURE_LEN] = '\0';
DEBUGLOG(("signature = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("sign is missing!!\n"));
	}

// syscode
	if (GetField_CString(hIn, "psp_key_uid", &csSysCode)) {
DEBUGLOG(("syscode = [%s]\n", csSysCode));
	}
	else {
DEBUGLOG(("psp_key_uid is missing!!\n"));
	}

DEBUGLOG(("csContext = [%s]\n", csContext));
	base64_encode((unsigned char *)csContext, strlen(csContext), csBase64Context, PD_TMP_MSG_BUF_LEN);
DEBUGLOG(("base64 context = [%s]\n", csBase64Context));
	int i, j;
	j = 0;
	for (i = 0; i < strlen(csBase64Context); i++) {
		if (csBase64Context[i] == '+')  {
			csUrlSafeBase64Context[j] = '-';
			j++;
		} else if (csBase64Context[i] == '/') {
			csUrlSafeBase64Context[j] = '_';
			j++;
		} else if (csBase64Context[i] != '=') {
			csUrlSafeBase64Context[j] = csBase64Context[i];
			j++;
		}
	}
	csUrlSafeBase64Context[j] = '\0';
DEBUGLOG(("urlsafebase64 context = [%s]\n", csUrlSafeBase64Context));

	sprintf((char*)outMsg, "%ssyscode=%s&version=002&context=%s&signature=%s", outMsg, csSysCode, csUrlSafeBase64Context, csSignature);
DEBUGLOG(("outmsg = [%s]\n", outMsg));

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
	char	*csPtr;
	char	*csReturnCode;
	char	csContext[PD_TMP_MSG_BUF_LEN + 1];
	char	csBase64Context[PD_TMP_MSG_BUF_LEN + 1];
	char	*csUrlSafeBase64Context;
	char    csPayUrl[PD_TMP_MSG_BUF_LEN + 1];
	char	csBase64PayUrl[PD_TMP_MSG_BUF_LEN + 1];
	char	*csUrlSafeBase64PayUrl;

	hash_t	*hRec;
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	hash_t  *hRec2;
	hRec2 = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec2, 0);

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

		if (GetField_CString(hRec, "errorcode", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "errormessage", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_CPE_SUCCESS_STATUS)) {
				// context
				if (GetField_CString(hRec, "context", &csUrlSafeBase64Context)) {
DEBUGLOG(("urlsafebase64 context = [%s]\n", csUrlSafeBase64Context));

					int i;
					for (i = 0; i < strlen(csUrlSafeBase64Context); i++) {
						if (csUrlSafeBase64Context[i] == '-')  {
							csBase64Context[i] = '+';
						} else if (csUrlSafeBase64Context[i] == '_') {
							csBase64Context[i] = '/';
						} else {
							csBase64Context[i] = csUrlSafeBase64Context[i];
						}
					}
					csBase64Context[i] = '\0';

/*
					if ((i % 4) == 3) {
						strcat(csBase64Context, "=");
					} else if ((i % 4) == 2) {
						strcat(csBase64Context, "==");
					}
*/

DEBUGLOG(("base64 context = [%s]\n", csBase64Context));

					int iLen;
					iLen = base64_decode(csBase64Context, (unsigned char *)csContext, PD_TMP_MSG_BUF_LEN);
					if (iLen > 0) {
						csContext[iLen] = '\0';
DEBUGLOG(("context = [%s]\n", csContext));

						if (Str2Cls(hRec2, csContext, MY_CPE_TOKEN, MY_CPE_FIELD_TOKEN) == PD_OK) {
							if (GetField_CString(hRec2, "trans_id", &csPtr)) {
								PutField_CString(hOut, "trans_id", csPtr);
DEBUGLOG(("trans_id = [%s]\n", csPtr));
							} else {
DEBUGLOG(("trans_id not found\n"));
							}

							if (GetField_CString(hRec2, "app_id", &csPtr)) {
								PutField_CString(hOut, "app_id", csPtr);
DEBUGLOG(("app_id = [%s]\n", csPtr));
							} else {
DEBUGLOG(("app_id not found\n"));
							}

							if (GetField_CString(hRec2, "amount", &csPtr)) {
								PutField_CString(hOut, "amount", csPtr);
DEBUGLOG(("amount = [%s]\n", csPtr));
							} else {
DEBUGLOG(("amount not found\n"));
							}

							if (GetField_CString(hRec2, "pay_url", &csUrlSafeBase64PayUrl)) {
DEBUGLOG(("urlsafebase64 pay_url = [%s]\n", csUrlSafeBase64PayUrl));

								for (i = 0; i < strlen(csUrlSafeBase64PayUrl); i++) {
									if (csUrlSafeBase64PayUrl[i] == '-')  {
										csBase64PayUrl[i] = '+';
									} else if (csUrlSafeBase64PayUrl[i] == '_') {
										csBase64PayUrl[i] = '/';
									} else {
										csBase64PayUrl[i] = csUrlSafeBase64PayUrl[i];
									}
								}
								csBase64PayUrl[i] = '\0';

/*
								if ((i % 4) == 3) {
									strcat(csBase64PayUrl, "=");
								} else if ((i % 4) == 2) {
									strcat(csBase64PayUrl, "==");
								}
*/

DEBUGLOG(("base64 pay_url = [%s]\n", csBase64PayUrl));

								iLen = base64_decode(csBase64PayUrl, (unsigned char *)csPayUrl, PD_TMP_MSG_BUF_LEN);
								if (iLen > 0) {
									csPayUrl[iLen] = '\0';
DEBUGLOG(("pay_url = [%s]\n", csPayUrl));
									PutField_CString(hOut, "pay_url", csPayUrl);
									PutField_CString(hOut, "encoded_pay_url", csUrlSafeBase64PayUrl);
								} else {
DEBUGLOG(("BreakDownInitRspMsg() Decode Failed\n"));
									iRet = PD_ERR;
								}
							} else {
DEBUGLOG(("pay_url not found\n"));
							}
						} else {
DEBUGLOG(("BreakDownInitRspMsg() Str2Cls Failed\n"));
							iRet = PD_ERR;
						}
					} else {
DEBUGLOG(("BreakDownInitRspMsg() Decode Failed\n"));
						iRet = PD_ERR;
					}
				}

				// signature
				if (GetField_CString(hRec, "signature", &csPtr)) {
					PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("sign = [%s]\n", csPtr));
				}
			}
		} else {
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
	hash_destroy(hRec2);
	FREE_ME(hRec2);

DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	char	csTag[PD_TAG_LEN + 1];
	csBuf = (char *) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* trans_id */
	strcpy(csTag, "trans_id");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

/* amount */
	strcpy(csTag, "amount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

/* pay_url */
	strcpy(csTag, "encoded_pay_url");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

/* tid */
	strcpy(csTag, "tid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

/* status */
	strcpy(csTag, "status");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

/* txn_amt */
	strcpy(csTag, "txn_amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, MY_CPE_OPEN_BRACKET);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_CPE_CLOSE_BRACKET);
		strcat((char*)csBuf, MY_CPE_DATA_TOKEN);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


void remove_quote(const char *csValue, const int iType, char *csOut)
{
	int i = 0;
	int cnt = 0;
	for (i = 0; i < strlen(csValue); i++) {
		if (csValue[i] != iType) {
			csOut[cnt] = csValue[i];
			cnt++;
		}
		else {
		}
	}
	csOut[cnt] = '\0';
}

