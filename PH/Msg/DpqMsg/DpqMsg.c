/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2017/11/16              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "DpqMsg.h"
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

#define PD_DOUBLE_QUOTE		0x22
#define PD_OPEN_BRACKET_H	0x7b
#define PD_CLOSE_BRACKET_H	0x7d
#define PD_OPEN_BRACKET		'{'//0x7b
#define PD_CLOSE_BRACKET	'}'//0x7d
#define PD_P0_CMD		"Buy"
#define PD_GATEWAY_TYPE	"WECHAT_DIRECT"
#define PD_CARE_TYPE		"01"
#define PD_SUCC_RSP_CODE	"00"
#define PD_SUCC_RSP_DESC	"Success"


OBJPTR(DB);
OBJPTR(BO);
char	cDebug;

void	DpqMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;

	char*	csPtr = NULL;
	char*	csBuf;
	char*	csCodeURL= NULL;
	int	iTmp;
	int	iTmpRet;

	hash_t	*hLog;
	hLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hLog,0);

DEBUGLOG(("FormatMsg()\n"));

	csCodeURL = (char*) malloc (PD_TMP_MSG_BUF_LEN+1);
	memset(csCodeURL,0,sizeof(csCodeURL));

	outMsg[0]= '\0';

//return_code
	if (GetField_CString(hIn,"return_code",&csPtr)) {
DEBUGLOG(("FormatMsg:: return_code = [%s]\n",csPtr));
		strcat((char*)outMsg,"return_code");
		strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_DPQ_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));
		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
		base64_encode((unsigned char *)(url_encode(csPtr)),strlen(url_encode(csPtr)),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_DPQ_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: code_url is missing\n"));
	}

//txn_seq
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
DEBUGLOG(("FormatMsg:: txn_seq = [%s]\n",csPtr));
		DBObjPtr = CreateObj(DBPtr,"DBTxnQrRequestLog","GetByTxnId");
		iTmpRet = (unsigned long int)(*DBObjPtr)(csPtr,hLog);
		if (iTmpRet == PD_FOUND) {
//time_init
			if (GetField_CString(hLog,"qrcode_init_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_init = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_init");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_DPQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_DPQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_DPQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_DPQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_DPQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_DPQ_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
			} else {
DEBUGLOG(("FormatMsg:: time_curr is missing\n"));
			}
		}
	} else {
DEBUGLOG(("FormatMsg:: txn_seq is missing\n"));
	}

DEBUGLOG(("outmsg = [%s]\n",outMsg));

	csBuf = (char*) malloc (PD_MAX_BUFFER +1);
	base64_encode(outMsg,strlen((char*)outMsg),csBuf,PD_MAX_BUFFER);
	outMsg[0] = '\0';
	strcat((char*)outMsg,"qr_parameter");
	strcat((char*)outMsg,"=");
	strcat((char*)outMsg,csBuf);
	FREE_ME(csBuf);
	*outLen = strlen((const char*)outMsg);

DEBUGLOG(("FormatMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatMsg() Exit\n"));
	FREE_ME(csPtr);

	hash_destroy(hLog);
	FREE_ME(hLog);

	return 	iRet;
}


int BuildAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// client_ip
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
		strcat((char*)csBuf, "client_ip");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: client_ip = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: org_ip_addr is missing\n"));
	}

// interface_version
	strcat((char*)csBuf, "interface_version");
	strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
	strcat((char*)csBuf, PD_INTERFACE_VERSION);
	strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: interface_version = [%s]\n", PD_INTERFACE_VERSION));

// merchant_code
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merchant_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: merchant_code = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_merchant_id is missing\n"));
	}

// notify_url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, "notify_url");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: notify_url = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: return_url_only is missing\n"));
	}

// order_amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf(csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, "order_amount");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: order_amount = [%s]\n", csTmpAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing\n"));
	}

// order_no
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, "order_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: order_no = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: order_num is missing\n"));
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
			strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csConverted);
			strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: order_time = [%s]\n", csConverted));
		}
		else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing\n"));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing\n"));
	}

// product_name
	strcat((char*)csBuf, "product_name");
	strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
	strcat((char*)csBuf, PD_PRODUCT_NAME);
	strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: product_name = [%s]\n", PD_PRODUCT_NAME));

// service_type
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		char csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "DPQ", "CN", csOutBankCode)) {
			strcat((char*)csBuf, "service_type");
			strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csOutBankCode);
			//strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildAuthData:: service_type = [%s]\n", csOutBankCode));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: bank_code is missing\n"));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n", csBuf));
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

	if (Str2Cls(hRec, (char *)inMsg, MY_DPQ_TOKEN, MY_DPQ_FIELD_TOKEN) == PD_OK) {
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
	return  iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}


int FormatInitMsg(const hash_t* hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;
	double	dTmp;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0] = '\0';
//psp_url
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n", csURL));
DEBUGLOG(("FormatInitMsg:: request function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n", csBuf));
		}

		sprintf((char*)outMsg, "%0*d", PD_WEB_HEADER_LEN_LEN, (int)strlen(csBuf));
DEBUGLOG(("FormatInitMsg:: outMsg = [%s]\n", outMsg));
		strcat((char*)outMsg, csBuf);
	}
	FREE_ME(csBuf);

// merchant_code
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: merchant_code = [%s]\n", csPtr));
		strcat((char*)outMsg, "merchant_code");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: merchant_code is missing\n"));
	}

// service_type
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		char csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "DPQ", "CN", csOutBankCode)) {
DEBUGLOG(("FormatInitMsg:: service_type = [%s]\n", csOutBankCode));
			strcat((char*)outMsg, "service_type");
			strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
			strcat((char*)outMsg, csOutBankCode);
			strcat((char*)outMsg, MY_DPQ_TOKEN);
		}
	}
	else {
DEBUGLOG(("FormatInitMsg:: service_type is missing\n"));
	}

// notify_url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: notify_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "notify_url");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: notify_url is missing\n"));
	}

// interface_version
DEBUGLOG(("FormatInitMsg:: interface_version = [%s]\n", PD_INTERFACE_VERSION));
	strcat((char*)outMsg, "interface_version");
	strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_INTERFACE_VERSION);
	strcat((char*)outMsg, MY_DPQ_TOKEN);

// client_ip
	if (GetField_CString(hIn, "org_ip_addr", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: client_ip = [%s]\n", csPtr));
		strcat((char*)outMsg, "client_ip");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: client_ip is missing\n"));
	}

// sign_type
DEBUGLOG(("FormatInitMsg:: sign_type = [%s]\n", PD_SIGN_TYPE));
	strcat((char*)outMsg, "sign_type");
	strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_SIGN_TYPE);
	strcat((char*)outMsg, MY_DPQ_TOKEN);

// sign
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: sign = [%s]\n", csPtr));
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, url_encode(csPtr));
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: sign is missing\n"));
	}

// order_no
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: order_no = [%s]\n", csPtr));
		strcat((char*)outMsg, "order_no");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: order_no is missing\n"));
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
DEBUGLOG(("FormatInitMsg:: order_time = [%s]\n", csConverted));
			strcat((char*)outMsg, "order_time");
			strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
			strcat((char*)outMsg, csConverted);
			strcat((char*)outMsg, MY_DPQ_TOKEN);
		}
		else {
DEBUGLOG(("FormatInitMsg:: order_time is missing\n"));
		}
	}
	else {
DEBUGLOG(("FormatInitMsg:: order_time is missing\n"));
	}

// order_amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf(csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("FormatInitMsg:: order_amount = [%s]\n", csTmpAmt));
		strcat((char*)outMsg, "order_amount");
		strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
		strcat((char*)outMsg, csTmpAmt);
		strcat((char*)outMsg, MY_DPQ_TOKEN);
	}
	else {
DEBUGLOG(("FormatInitMsg:: order_amount is missing\n"));
	}

// product_name
DEBUGLOG(("FormatInitMsg:: product_name = [%s]\n", PD_PRODUCT_NAME));
	strcat((char*)outMsg, "product_name");
	strcat((char*)outMsg, MY_DPQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_PRODUCT_NAME);
	//strcat((char*)outMsg, MY_DPQ_TOKEN);

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return iRet;
}


int BreakDownXMLMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csReturnCode = NULL;

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	hash_t *hXml;
	hXml = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hXml, 0);
	iRet = BreakDownXMLMsg(hXml, inMsg, inLen);

	if (iRet == PD_OK) {
		if (GetField_CString(hXml, "resp_code", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
DEBUGLOG(("BreakDownInitRspMsg:: return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hXml, "resp_desc", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, PD_SUCCESS_STATUS)) {
				// result_code
				if (GetField_CString(hXml, "result_code", &csPtr)) {
					PutField_CString(hOut, "result_code", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: result_code = [%s]\n", csPtr));
				}

				// error_code
				if (GetField_CString(hXml, "error_code", &csPtr)) {
					PutField_CString(hOut, "error_code", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: error_code = [%s]\n", csPtr));
				}

				// result_desc
				if (GetField_CString(hXml, "result_desc", &csPtr)) {
					PutField_CString(hOut, "result_desc", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: result_desc = [%s]\n", csPtr));
				}

				// qrcode
				if (GetField_CString(hXml, "qrcode", &csPtr)) {
					PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: qrcode = [%s]\n", csPtr));
				}

				// order_no
				if (GetField_CString(hXml, "order_no", &csPtr)) {
					PutField_CString(hOut, "order_no", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: order_no = [%s]\n", csPtr));
				}

				// order_time
				if (GetField_CString(hXml, "order_time", &csPtr)) {
					PutField_CString(hOut, "order_time", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: order_time = [%s]\n", csPtr));
				}

				// order_amount
				if (GetField_CString(hXml, "order_amount", &csPtr)) {
					PutField_CString(hOut, "order_amount", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: order_amount = [%s]\n", csPtr));
				}

				// trade_no
				if (GetField_CString(hXml, "trade_no", &csPtr)) {
					PutField_CString(hOut, "trade_no", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: trade_no = [%s]\n", csPtr));
				}

				// trade_time
				if (GetField_CString(hXml, "trade_time", &csPtr)) {
					PutField_CString(hOut, "trade_time", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: trade_time = [%s]\n", csPtr));
				}

				// merchant_code
				if (GetField_CString(hXml, "merchant_code", &csPtr)) {
					PutField_CString(hOut, "merchant_code", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: merchant_code = [%s]\n", csPtr));
				}

				// interface_version
				if (GetField_CString(hXml, "interface_version", &csPtr)) {
					PutField_CString(hOut, "interface_version", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: interface_version = [%s]\n", csPtr));
				}

				// sign_type
				if (GetField_CString(hXml, "sign_type", &csPtr)) {
					PutField_CString(hOut, "sign_type", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: sign_type = [%s]\n", csPtr));
				}

				// sign
				if (GetField_CString(hXml, "sign", &csPtr)) {
					PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: sign = [%s]\n", csPtr));
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

	hash_destroy(hXml);
	FREE_ME(hXml);
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int BuildRspAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// bank_seq_no
	if (GetField_CString(hIn, "bank_seq_no", &csPtr)) {
		strcat((char*)csBuf, "bank_seq_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: bank_seq_no = [%s]\n", csPtr));
	}

// error_code
	if (GetField_CString(hIn, "error_code", &csPtr)) {
		strcat((char*)csBuf, "error_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: error_code = [%s]\n", csPtr));
	}

// interface_version
	if (GetField_CString(hIn, "interface_version", &csPtr)) {
		strcat((char*)csBuf, "interface_version");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: interface_version = [%s]\n", csPtr));
	}

// merchant_code
	if (GetField_CString(hIn, "merchant_code", &csPtr)) {
		strcat((char*)csBuf, "merchant_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: merchant_code = [%s]\n", csPtr));
	} else if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, "merchant_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: merchant_code = [%s]\n", csPtr));
	}

// notify_id
	if (GetField_CString(hIn, "notify_id", &csPtr)) {
		strcat((char*)csBuf, "notify_id");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: notify_id = [%s]\n", csPtr));
	}

// notify_type
	if (GetField_CString(hIn, "notify_type", &csPtr)) {
		strcat((char*)csBuf, "notify_type");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: notify_type = [%s]\n", csPtr));
	}

// order_amount
	if (GetField_CString(hIn, "order_amount", &csPtr)) {
		strcat((char*)csBuf, "order_amount");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_amount = [%s]\n", csPtr));
	} else if (GetField_CString(hIn, "psp_txn_amt", &csPtr)) {
		strcat((char*)csBuf, "order_amount");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_amount = [%s]\n", csPtr));
	}

// order_no
	if (GetField_CString(hIn, "order_no", &csPtr)) {
		strcat((char*)csBuf, "order_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_no = [%s]\n", csPtr));
	} else if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, "order_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_no = [%s]\n", csPtr));
	}

// order_time
	if (GetField_CString(hIn, "order_time", &csPtr)) {
		strcat((char*)csBuf, "order_time");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_time = [%s]\n", csPtr));
	}

// qrcode
	if (GetField_CString(hIn, "code_url", &csPtr)) {
		strcat((char*)csBuf, "qrcode");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: qrcode = [%s]\n", csPtr));
	}

// resp_code
	if (GetField_CString(hIn, "return_code", &csPtr)) {
		strcat((char*)csBuf, "resp_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: resp_code = [%s]\n", csPtr));
	}

// resp_desc
	if (GetField_CString(hIn, "return_msg", &csPtr)) {
		strcat((char*)csBuf, "resp_desc");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: resp_desc = [%s]\n", csPtr));
	}

// result_code
	if (GetField_CString(hIn, "result_code", &csPtr)) {
		strcat((char*)csBuf, "result_code");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: result_code = [%s]\n", csPtr));
	}

// result_desc
	if (GetField_CString(hIn, "result_desc", &csPtr)) {
		strcat((char*)csBuf, "result_desc");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: result_desc = [%s]\n", csPtr));
	}

// trade_no
	if (GetField_CString(hIn, "trade_no", &csPtr)) {
		strcat((char*)csBuf, "trade_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: trade_no = [%s]\n", csPtr));
	} else if (GetField_CString(hIn, "tid", &csPtr)) {
		strcat((char*)csBuf, "trade_no");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: trade_no = [%s]\n", csPtr));
	}

// trade_status
	if (GetField_CString(hIn, "status", &csPtr)) {
		strcat((char*)csBuf, "trade_status");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: trade_status:status = [%s]\n", csPtr));
	}

// trade_time
	if (GetField_CString(hIn, "trade_time", &csPtr)) {
		strcat((char*)csBuf, "trade_time");
		strcat((char*)csBuf, MY_DPQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		//strcat((char*)csBuf, MY_DPQ_TOKEN);
DEBUGLOG(("BuildRspAuthData:: trade_time = [%s]\n", csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

