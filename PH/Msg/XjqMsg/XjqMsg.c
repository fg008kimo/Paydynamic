/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2017/09/26		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "XjqMsg.h"
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

void XjqMsg(char cdebug)
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
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

/* code_url */
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		csCodeURL = (char*) malloc (PD_MAX_BUFFER + 1);
		memset(csCodeURL, 0, sizeof(csCodeURL));
		base64_encode((unsigned char*)csPtr, strlen((char*)csPtr), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
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
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

/* time_expire */
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

/* time_enable */
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

/* time_auto_check */
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

/* time_redirect */
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

/* time_curr */
			if (GetField_CString(hLog, "qrcode_curr_timestamp", &csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
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
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* merchantNo */
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("merchantNo = [%s]\n", csPtr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("*** merchantNo is missing\n"));
	}

/* requestNo */
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("requestNo = [%s]\n", csPtr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("*** requestNo is missing\n"));
	}

/* amount */
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		strcat((char*)csBuf, csTmpAmt);
		strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("*** amount is missing\n"));
	}

/* pageUrl */
	strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("pageUrl is optional\n"));

/* backUrl */
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("backUrl = [%s]\n", csPtr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("*** backUrl is missing\n"));
	}

/* payDate */
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
DEBUGLOG(("local_tm_date = [%s]\n", csPtr));
		char *csPtr2;
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
DEBUGLOG(("local_tm_time = [%s]\n", csPtr2));
			char csDateTime[PD_DATETIME_LEN + 1];
			struct tm tm;
			time_t epoch;
			char csEpoch[PD_TMP_BUF_LEN + 1];
			sprintf(csDateTime, "%s%s", csPtr, csPtr2);
			if (strptime((const char*)csDateTime, "%Y%m%d%H%M%S", &tm) != NULL) {
				epoch = mktime(&tm);
				sprintf((char*)csEpoch, "%ld", (long)epoch);
				strcat((char*)csBuf, csEpoch);
				strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("payDate = [%s]\n", csEpoch));
			} else {
				iRet = PD_ERR;
DEBUGLOG(("*** cannot convert datetime\n"));
			}
		} else {
			iRet = PD_ERR;
DEBUGLOG(("*** local_tm_time is missing\n"));
		}
	} else {
		iRet = PD_ERR;
DEBUGLOG(("*** local_tm_date is missing\n"));
	}

/* agencyCode */
	strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("agencyCode is optional\n"));

/* remark1 */
	strcat((char*)csBuf, PD_REMARK1);
	strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("remark1 = [%s]\n", PD_REMARK1));

/* remark2 */
	strcat((char*)csBuf, PD_REMARK2);
	strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("remark2 = [%s]\n", PD_REMARK2));

/* remark3 */
	strcat((char*)csBuf, PD_REMARK3);
	strcat((char*)csBuf, MY_XJQ_AUTH_TOKEN);
DEBUGLOG(("remark3 = [%s]\n", PD_REMARK3));

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int     iRet = PD_OK;
	int     iTmpRet = PD_OK;
	char    *csPtr, *csPspMerchantId, *csInfo, *csPspId, *csKeyFile, *csDecryptedInfo;
	csDecryptedInfo = (char*) malloc (PD_MAX_BUFFER);
	memset(csDecryptedInfo, 0, sizeof(csDecryptedInfo));
	hash_t  *hRec;
	hash_t  *hPspDetail;
	hash_t  *hKey;
	hash_t  *hDecrypted;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPspDetail, 0);

	hDecrypted = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hDecrypted, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char *)inMsg,MY_XJQ_TOKEN, MY_XJQ_FIELD_TOKEN) == PD_OK) {

// 1 partner
		if (GetField_CString(hRec, "partner", &csPspMerchantId)) {
DEBUGLOG(("partner = [%s]\n", csPspMerchantId));
		} else {
DEBUGLOG(("partner not found\n"));
			iRet = PD_ERR;
		}

// info
		if (iRet == PD_OK) {
			if (GetField_CString(hRec, "info", &csInfo)) {
DEBUGLOG(("info = [%s]\n", csInfo));
			} else {
DEBUGLOG(("info not found\n"));
				iRet = PD_ERR;
			}
		}

// get psp_id by channel and psp_merchant_id
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "GetPspDetailByChannelMerchId");
			iTmpRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_UNIPAY_WECHAT, csPspMerchantId, hPspDetail);
			if (iTmpRet != PD_OK) {
DEBUGLOG(("call DBPspDetail:GetPspDetailByChannelMerchId() failed\n"));
				iRet = PD_ERR;
			} else {
				if (GetField_CString(hPspDetail, "psp_id", &csPspId)) {
DEBUGLOG(("psp_id = [%s]\n", csPspId));
				}
				else {
DEBUGLOG(("psp_id not found\n"));
					iRet = PD_ERR;
				}
			}
		}

// get private key file by psp_id
		if (iRet == PD_OK) {
			recordset_t *rKeySet;
			rKeySet = (recordset_t*) malloc (sizeof(recordset_t));
			recordset_init(rKeySet, 0);
			DBObjPtr = CreateObj(DBPtr, "DBPspKeys", "GetPspKey");
			iTmpRet = (unsigned long)(*DBObjPtr)(csPspId, PD_PTK_KEY_NAME, rKeySet);
			if (iTmpRet != PD_OK) {
DEBUGLOG(("call DBPspKeys:GetPspKey() failed\n"));
				iRet = PD_ERR;
			} else {
				hKey = RecordSet_GetFirst(rKeySet);
				while (hKey) {
					if (GetField_CString(hKey, "privatepem", &csKeyFile)) {
DEBUGLOG(("private key file = [%s]\n", csKeyFile));
					} else {
DEBUGLOG(("private key file not found\n"));
						iRet = PD_ERR;
					}
					break;
				}
			}
			RecordSet_Destroy(rKeySet);
			FREE_ME(rKeySet);
		}

// RSA decrypt info
		if (iRet == PD_OK) {
			BOObjPtr = CreateObj(BOPtr, "BOSecurity", "RSAEncryptData_with_mode");
			iRet = (unsigned long)(*BOObjPtr)(csKeyFile, csInfo, csDecryptedInfo, PD_TRUE, PD_FALSE, RSA_PKCS1_OAEP_PADDING, 2048);
		}

// Break down decrypted info
		if (iRet == PD_OK) {
DEBUGLOG(("decrypted info = [%s]\n", csDecryptedInfo));
			if (Str2Cls(hDecrypted, csDecryptedInfo, MY_XJQ_TOKEN, MY_XJQ_FIELD_TOKEN) == PD_OK) {
                                // 2.1 partner
				if (GetField_CString(hDecrypted, "partner", &csPtr)) {
DEBUGLOG(("partner = [%s]\n", csPtr));
					PutField_CString(hOut, "partner", csPtr);
				}
				else {
DEBUGLOG(("partner not found\n"));
				}

				// 2.2 out_trade_no
				if (GetField_CString(hDecrypted, "out_trade_no", &csPtr)) {
DEBUGLOG(("txn_seq = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_seq", csPtr);
				}
				else {
DEBUGLOG(("txn_seq not found\n"));
				}

				// 2.3 pay_no
				if (GetField_CString(hDecrypted, "pay_no", &csPtr)) {
DEBUGLOG(("tid = [%s]\n", csPtr));
					PutField_CString(hOut, "tid", csPtr);
				}
				else {
DEBUGLOG(("tid not found\n"));
				}

				// 2.4 amount
				if (GetField_CString(hDecrypted, "amount", &csPtr)) {
DEBUGLOG(("txn_amt = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_amt", csPtr);
				}
				else {
DEBUGLOG(("txn_amt not found\n"));
				}

                                // 2.5 pay_result
				if (GetField_CString(hDecrypted, "pay_result", &csPtr)) {
DEBUGLOG(("status = [%s]\n", csPtr));
					PutField_CString(hOut, "status", csPtr);
				}
				else {
DEBUGLOG(("status not found\n"));
				}

				// 2.6 sett_date
				if (GetField_CString(hDecrypted, "sett_date", &csPtr)) {
DEBUGLOG(("txn_date = [%s]\n", csPtr));
					PutField_CString(hOut, "fundin_date", csPtr);
					PutField_CString(hOut, "txn_date", csPtr);
				}
				else {
DEBUGLOG(("txn_date not found\n"));
				}

				// 2.7 mdr_fee
				if (GetField_CString(hDecrypted, "mdr_fee", &csPtr)) {
DEBUGLOG(("mdr_fee = [%s]\n", csPtr));
					PutField_CString(hOut, "mdr_fee", csPtr);
				}
				else {
DEBUGLOG(("mdr_fee not found\n"));
				}
			} else {
DEBUGLOG(("BreakDownMsg() Error\n"));
				iRet = PD_ERR;
			}
		}
	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);
	hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hDecrypted);
	FREE_ME(hDecrypted);
	FREE_ME(csDecryptedInfo);

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
			strcat((char*)csBuf, MY_XJQ_FIELD_TOKEN);
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

/* merchantNo */
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("merchantNo = [%s]\n", csPtr));
		strcat((char*)outMsg, "merchantNo");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("merchantNo is missing\n"));
	}

/* requestNo */
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("requestNo = [%s]\n", csPtr));
		strcat((char*)outMsg, "requestNo");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("requestNo is missing\n"));
	}

/* amount */
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
DEBUGLOG(("amount = [%s]\n", csTmpAmt));
		strcat((char*)outMsg, "amount");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csTmpAmt);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("amount is missing\n"));
	}

/* payMethod */
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)outMsg, "payMethod");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "XJQ", "CN", csOutBankCode)) {
DEBUGLOG(("payMethod = [%s]\n", csOutBankCode));
			strcat((char*)outMsg, csOutBankCode);
		} else {
DEBUGLOG(("no bank code mapping\n"));
		}
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("payMethod is missing\n"));
	}

/* pageUrl */
DEBUGLOG(("pageUrl is optional\n"));
	strcat((char*)outMsg, "pageUrl");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* backUrl */
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("backUrl = [%s]\n", csPtr));
		strcat((char*)outMsg, "backUrl");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJQ_TOKEN);
	} else {
DEBUGLOG(("backUrl is missing\n"));
	}

/* payDate */
	if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
		char *csPtr2;
		if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
			char csDateTime[PD_DATETIME_LEN + 1];
			struct tm tm;
			time_t epoch;
			char csEpoch[PD_TMP_BUF_LEN + 1];
			sprintf(csDateTime, "%s%s", csPtr, csPtr2);
			if (strptime((const char*)csDateTime, "%Y%m%d%H%M%S", &tm) != NULL) {
				epoch = mktime(&tm);
				sprintf((char*)csEpoch, "%ld", (long)epoch);
DEBUGLOG(("payDate = [%s]\n", csEpoch));
				strcat((char*)outMsg, "payDate");
				strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
				strcat((char*)outMsg, csEpoch);
				strcat((char*)outMsg, MY_XJQ_TOKEN);
			} else {
DEBUGLOG(("cannot convert datetime\n"));
			}
		} else {
DEBUGLOG(("payDate is missing\n"));
		}
	} else {
DEBUGLOG(("payDate is missing\n"));
	}

/* agencyCode */
DEBUGLOG(("agencyCode is optional\n"));
	strcat((char*)outMsg, "agencyCode");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* cashier */
DEBUGLOG(("cashier is optional\n"));
	strcat((char*)outMsg, "cashier");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* remark1 */
DEBUGLOG(("remark1 = [%s]\n", PD_REMARK1));
	strcat((char*)outMsg, "remark1");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_REMARK1);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* remark2 */
DEBUGLOG(("remark2 = [%s]\n", PD_REMARK2));
	strcat((char*)outMsg, "remark2");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_REMARK2);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* remark3 */
DEBUGLOG(("remark3 = [%s]\n", PD_REMARK3));
	strcat((char*)outMsg, "remark3");
	strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_REMARK3);
	strcat((char*)outMsg, MY_XJQ_TOKEN);

/* signature */
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("signature = [%s]\n", url_encode(csPtr)));
		strcat((char*)outMsg, "signature");
		strcat((char*)outMsg, MY_XJQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
	} else {
DEBUGLOG(("signature is missing\n"));
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
	int	iMissingField = PD_FALSE;
	char	*csPtr = NULL;
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

		/* backQrCodeUrl */
		if (GetField_CString(hRec, "backQrCodeUrl", &csPtr)) {
			PutField_CString(hOut, "code_url", csPtr);
DEBUGLOG(("backQrCodeUrl = [%s]\n", csPtr));
		} else {
DEBUGLOG(("backQrCodeUrl is missing\n"));
			iMissingField = PD_TRUE;
		}

		/* backOrderId */
		if (GetField_CString(hRec, "backOrderId", &csPtr)) {
			PutField_CString(hOut, "backOrderId", csPtr);
DEBUGLOG(("backOrderId = [%s]\n", csPtr));
		} else {
DEBUGLOG(("backOrderId is missing\n"));
			iMissingField = PD_TRUE;
		}

		/* sign */
		if (GetField_CString(hRec, "sign", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("sign = [%s]\n", csPtr));
		} else {
DEBUGLOG(("sign is missing\n"));
			iMissingField = PD_TRUE;
		}

		if (!iMissingField) {
			PutField_CString(hOut, "return_code", PD_SUCCESS_STATUS);
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


int BuildRspAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	int	iIsInitReq = PD_FALSE;
	char	*csPtr;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	struct json_object *jobj = json_object_new_object();

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	GetField_Int(hIn, "isInitReq", &iIsInitReq);
DEBUGLOG(("isInitReq = [%d]\n", iIsInitReq));

	if (iIsInitReq) {
/* backQrCodeUrl */
		if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("backQrCodeUrl = [%s]\n",csPtr));
			json_object_object_add(jobj, "backQrCodeUrl", json_object_new_string(csPtr));
		}

/* backOrderId */
		if (GetField_CString(hIn, "backOrderId", &csPtr)) {
DEBUGLOG(("backOrderId = [%s]\n",csPtr));
			json_object_object_add(jobj, "backOrderId", json_object_new_string(csPtr));
		}
	} else {
	}

	PutField_CString(hIn, "auth_data", json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN));
DEBUGLOG(("auth_data = [%s]\n", json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN)));
	json_object_put(jobj);
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

