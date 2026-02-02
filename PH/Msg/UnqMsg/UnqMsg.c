
/*
 * PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PDProTech.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 * Init Version                                       2019/06/27              David Wong
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UnqMsg.h"
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

static char cDebug;

OBJPTR(BO);
OBJPTR(DB);

void UnqMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csBuf;
	char	*csCodeURL = NULL;
	int	iTmp;
	int	iTmpRet;

	hash_t	*hLog;
	hLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hLog, 0);

DEBUGLOG(("FormatMsg() Start\n"));

	csCodeURL = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
	memset(csCodeURL, 0, sizeof(csCodeURL));

	outMsg[0] = '\0';

// return_code
	if (GetField_CString(hIn, "return_code", &csPtr)) {
DEBUGLOG(("return_code = [%s]\n", csPtr));
		strcat((char*)outMsg, "return_code");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_UNQ_TOKEN);
	} else {
DEBUGLOG(("return_code is missing\n"));
	}

// code_url
	if (GetField_CString(hIn, "code_url", &csPtr)) {
DEBUGLOG(("code_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "code_url");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		base64_encode((unsigned char*)csPtr, strlen((char*)csPtr), csCodeURL, PD_MAX_BUFFER);
		strcat((char*)outMsg, csCodeURL);
		strcat((char*)outMsg, MY_UNQ_TOKEN);
	} else {
DEBUGLOG(("code_url is missing\n"));
	}

// txn_seq
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("txn_seq = [%s]\n", csPtr));
		DBObjPtr = CreateObj(DBPtr, "DBTxnQrRequestLog", "GetByTxnId");
		iTmpRet = (unsigned long int)(*DBObjPtr)(csPtr, hLog);
		if (iTmpRet == PD_FOUND) {
// time_init
			if (GetField_CString(hLog, "qrcode_init_timestamp", &csPtr)) {
DEBUGLOG(("time_init = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_init");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
				strcat((char*)outMsg, csPtr);
				strcat((char*)outMsg, MY_UNQ_TOKEN);
			} else {
DEBUGLOG(("time_init is missing\n"));
			}

// time_expire
			if (GetField_Int(hLog, "expiry", &iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire, "%d", iTmp);
DEBUGLOG(("time_expire = [%s]\n", csTimeExpire));
				strcat((char*)outMsg, "time_expire");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeExpire);
				strcat((char*)outMsg, MY_UNQ_TOKEN);
			} else {
DEBUGLOG(("time_expire is missing\n"));
			}

// time_enable
			if (GetField_Int(hLog, "enable_button", &iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable, "%d", iTmp);
DEBUGLOG(("time_enable = [%s]\n", csTimeEnable));
				strcat((char*)outMsg, "time_enable");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeEnable);
				strcat((char*)outMsg, MY_UNQ_TOKEN);
			} else {
DEBUGLOG(("time_enable is missing\n"));
			}

// time_auto_check
			if (GetField_Int(hLog, "auto_check_txn_status", &iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck, "%d", iTmp);
DEBUGLOG(("time_auto_check = [%s]\n", csTimeAutoCheck));
				strcat((char*)outMsg, "time_auto_check");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeAutoCheck);
				strcat((char*)outMsg, MY_UNQ_TOKEN);
			} else {
DEBUGLOG(("time_auto_check is missing\n"));
			}

// time_redirect
			if (GetField_Int(hLog, "redirect", &iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect, "%d", iTmp);
DEBUGLOG(("time_redirect = [%s]\n", csTimeRedirect));
				strcat((char*)outMsg, "time_redirect");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
				strcat((char*)outMsg, csTimeRedirect);
				strcat((char*)outMsg, MY_UNQ_TOKEN);
			} else {
DEBUGLOG(("time_redirect is missing\n"));
			}

// time_curr
			if (GetField_CString(hLog, "qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("time_curr = [%s]\n", csPtr));
				strcat((char*)outMsg, "time_db_local");
				strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
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
	base64_encode(outMsg, strlen((char*)outMsg), csBuf, PD_MAX_BUFFER);
	outMsg[0] = '\0';
	strcat((char*)outMsg, "qr_parameter");
	strcat((char*)outMsg, "=");
	strcat((char*)outMsg, csBuf);
	FREE_ME(csBuf);
	*outLen = strlen((const char*)outMsg);

DEBUGLOG(("[%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatMsg() Exit\n"));
	FREE_ME(csPtr);

	hash_destroy(hLog);
	FREE_ME(hLog);

	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;
	char	*csPtr, *csPspMerchantId, *csInfo, *csPspId, *csKeyFile, *csDecryptedInfo;
	csDecryptedInfo = (char*) malloc (PD_MAX_BUFFER);
	memset(csDecryptedInfo, 0, sizeof(csDecryptedInfo));
	hash_t	*hRec;
	hash_t	*hPspDetail;
	hash_t	*hKey;
	hash_t	*hDecrypted;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPspDetail, 0);

	hDecrypted = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hDecrypted, 0);

DEBUGLOG(("BreakDownMsg() Start\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char*)inMsg, MY_UNQ_TOKEN, MY_UNQ_FIELD_TOKEN) == PD_OK) {

// 1 partner
		if (GetField_CString(hRec, "partner", &csPspMerchantId)) {
DEBUGLOG(("partner = [%s]\n", csPspMerchantId));
		} else {
DEBUGLOG(("partner not found\n"));
			iRet = PD_ERR;
		}

// 2 info
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
			iTmpRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_UNIPAY_QR, csPspMerchantId, hPspDetail);
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
			if (Str2Cls(hDecrypted, csDecryptedInfo, MY_UNQ_TOKEN, MY_UNQ_FIELD_TOKEN) == PD_OK) {
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

				// 2.5 mdr_fee
				if (GetField_CString(hDecrypted, "mdr_fee", &csPtr)) {
DEBUGLOG(("mdr_fee = [%s]\n", csPtr));
					PutField_CString(hOut, "mdr_fee", csPtr);
				}
				else {
DEBUGLOG(("mdr_fee not found\n"));
				}

				// 2.6 pay_result
				if (GetField_CString(hDecrypted, "pay_result", &csPtr)) {
DEBUGLOG(("status = [%s]\n", csPtr));
					PutField_CString(hOut, "status", csPtr);
				}
				else {
DEBUGLOG(("status not found\n"));
				}

				// 2.7 sett_date
				if (GetField_CString(hDecrypted, "sett_date", &csPtr)) {
DEBUGLOG(("txn_date = [%s]\n", csPtr));
					PutField_CString(hOut, "fundin_date", csPtr);
					PutField_CString(hOut, "txn_date", csPtr);
				}
				else {
DEBUGLOG(("txn_date not found\n"));
				}
			} else {
DEBUGLOG(("Str2Cls() Error\n"));
				iRet = PD_ERR;
			}
		}
	}
	else {
DEBUGLOG(("Str2Cls Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hRec);
	FREE_ME(hRec);
	hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hDecrypted);
	FREE_ME(hDecrypted);
	FREE_ME(csDecryptedInfo);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return iRet;
}


int initReplyFromRequest(const hash_t *hRequest, hash_t *hResponse)
{
	int	iRet = PD_OK;

	char	*csTmp = NULL;

DEBUGLOG(("initReplyFromRequest() Start\n"));

// order_num
	if (GetField_CString(hRequest, "merchant_ref", &csTmp)) {
DEBUGLOG(("initReplyFromRequest: order_num = [%s]\n", csTmp));
		PutField_CString(hResponse, "order_num", csTmp);
	}

DEBUGLOG(("initReplyFromRequest() Exit\n"));
	FREE_ME(csTmp);
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
	int	iForEnquiry = PD_FALSE;
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildAuthData() Start\n"));

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
// 1 base64_memo
		strcat((char*)csBuf, "base64_memo");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_UNQ_TOKEN);

// 2 notify_url
		if (GetField_CString(hIn, "return_url_only", &csPtr)) {
			strcat((char*)csBuf, "notify_url");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, url_encode(csPtr));
			strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("notify_url = [%s]\n", url_encode(csPtr)));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("*** return_url_only is missing\n"));
		}

// 3 order_number
		if (GetField_CString(hIn, "order_num", &csPtr)) {
			strcat((char*)csBuf, "order_number");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, csPtr);
			strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("order_number = [%s]\n", csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("*** order_num is missing\n"));
		}

// 4 pay_id
		strcat((char*)csBuf, "pay_id");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_UNQ_TOKEN);

// 5 card_type
		strcat((char*)csBuf, "card_type");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, PD_UNQ_CARD_TYPE);
		strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("card_type = [%s]\n", PD_UNQ_CARD_TYPE));

// 6 return_url
		if (GetField_CString(hIn, "fe_url", &csPtr)) {
			strcat((char*)csBuf, "return_url");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, url_encode(csPtr));
			strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("return_url = [%s]\n", url_encode(csPtr)));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("*** fe_url is missing\n"));
		}

// 7 total_fee
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf((char*)csTmpAmt, "%.2f", dTmp);
			strcat((char*)csBuf, "total_fee");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, csTmpAmt);
			strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("total_fee = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("*** psp_txn_amt is missing\n"));
		}

// 8 version
		strcat((char*)csBuf, "version");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_UNQ_TOKEN);

// 9 order_timestamp
		if (GetField_CString(hIn, "local_tm_date", &csPtr)) {
			char *csPtr2 = NULL;
			char csRaw[PD_DATETIME_LEN * 2];
			char csConverted[PD_DATETIME_LEN * 2];
			struct tm tm;
			if (GetField_CString(hIn, "local_tm_time", &csPtr2)) {
				sprintf(csRaw, "%s%s", csPtr, csPtr2);
				strptime((const char*)csRaw, "%Y%m%d%H%M%S", &tm);
				strftime(csConverted, sizeof(csConverted), "%s", &tm);
				strcat((char*)csBuf, "order_timestamp");
				strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
				strcat((char*)csBuf, csConverted);
				strcat((char*)csBuf, MY_UNQ_TOKEN);
DEBUGLOG(("order_timestamp = [%s]\n", csConverted));
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("*** local_tm_time is missing\n"));
			}
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("*** local_tm_date is missing\n"));
		}

// 10 card_no
		strcat((char*)csBuf, "card_no");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, MY_UNQ_TOKEN);

// 11 gateway_type
		strcat((char*)csBuf, "gateway_type");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
	} else {
		strcat((char*)csBuf, " ");
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
DEBUGLOG(("BuildRspAuthData() Start\n"));
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;

DEBUGLOG(("FormatInitMsg() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	outMsg[0]= '\0';

// psp_url
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("psp_url = [%s]\n", csURL));
DEBUGLOG(("request function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
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

// 1 partner
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("partner = [%s]\n", csPtr));
		strcat((char*)outMsg, "partner");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_UNQ_TOKEN);
	} else {
DEBUGLOG(("psp_merchant_id:partner is missing\n"));
	}

// 2 info
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("info = [%s]\n", url_encode(csPtr)));
		strcat((char*)outMsg, "info");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		strcat((char*)outMsg, url_encode(csPtr));
	} else {
DEBUGLOG(("sign:info is missing\n"));
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
	int	iTmpRet = PD_OK;
	int	iLen;
	char	*csPtr, *csPspMerchantId, *csInfo, *csPspId, *csKeyFile, *csDecryptedInfo, *csTmpReturnMsg;
	csDecryptedInfo = (char*) malloc (PD_MAX_BUFFER);
	memset(csDecryptedInfo, 0, sizeof(csDecryptedInfo));
	csTmpReturnMsg = (char*) malloc (PD_TMP_MSG_BUF_LEN * 2 + 1);
	char	*csReturnCode = NULL;
	char	*csReturnMsg = NULL;
	hash_t	*hPspDetail;
	hash_t	*hKey;
	hash_t	*hDecrypted;

	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPspDetail, 0);

	hDecrypted = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hDecrypted, 0);

DEBUGLOG(("BreakDownInitRspMsg() Start\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	hash_t *hXml;
	hXml = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hXml, 0);
	iRet = BreakDownXMLMsg(hXml, inMsg, inLen);

	if (iRet == PD_OK) {
		if (GetField_CString(hXml, "resp_code", &csReturnCode) &&
		    GetField_CString(hXml, "resp_desc", &csReturnMsg)) {
			// return_code
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			urldecode((const unsigned char*)csReturnMsg, strlen((const char*)csReturnMsg), (unsigned char*)csTmpReturnMsg, &iLen);
DEBUGLOG(("return_msg = [%s]\n", csTmpReturnMsg));

			if (!strcmp(csReturnCode, PD_SUCCESS_STATUS) && !strcmp(csTmpReturnMsg, PD_SUCCESS_MSG)) {
				// partner
				if (GetField_CString(hXml, "partner", &csPspMerchantId)) {
DEBUGLOG(("partner = [%s]\n", csPspMerchantId));
				} else {
DEBUGLOG(("*** partner is missing\n"));
					iRet = PD_ERR;
                                }

				// info
				if (GetField_CString(hXml, "info", &csInfo)) {
DEBUGLOG(("info = [%s]\n", csInfo));
				} else {
DEBUGLOG(("*** info is missing\n"));
					iRet = PD_ERR;
				}

				// get psp_id by channel and psp_merchant_id
				if (iRet == PD_OK) {
					DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "GetPspDetailByChannelMerchId");
					iTmpRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_UNIPAY_QR, csPspMerchantId, hPspDetail);
					if (iTmpRet != PD_OK) {
DEBUGLOG(("call DBPspDetail:GetPspDetailByChannelMerchId() failed\n"));
						iRet = PD_ERR;
					} else {
						if (GetField_CString(hPspDetail, "psp_id", &csPspId)) {
DEBUGLOG(("psp_id = [%s]\n", csPspId));
						} else {
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
					if (Str2Cls(hDecrypted, csDecryptedInfo, MY_UNQ_TOKEN, MY_UNQ_FIELD_TOKEN) == PD_OK) {
						// order_number
						if (GetField_CString(hDecrypted, "order_number", &csPtr)) {
DEBUGLOG(("order_number = [%s]\n", csPtr));
							PutField_CString(hOut, "order_id", csPtr);
						} else {
DEBUGLOG(("order_number not found\n"));
							iRet = PD_ERR;
						}

						// success
						if (GetField_CString(hDecrypted, "success", &csPtr)) {
DEBUGLOG(("success = [%s]\n", csPtr));
							PutField_CString(hOut, "return_code", csPtr);
						} else {
DEBUGLOG(("success not found\n"));
							iRet = PD_ERR;
						}

						// remark
						if (GetField_CString(hDecrypted, "remark", &csPtr)) {
DEBUGLOG(("remark = [%s]\n", csPtr));
							urldecode((const unsigned char*)csPtr, strlen((const char*)csPtr), (unsigned char*)csTmpReturnMsg, &iLen);
DEBUGLOG(("remark = [%s]\n", csTmpReturnMsg));
							PutField_CString(hOut, "return_msg", csTmpReturnMsg);
						} else {
DEBUGLOG(("remark not found\n"));
						}

						// url
						if (GetField_CString(hDecrypted, "url", &csPtr)) {
DEBUGLOG(("url = [%s]\n", csPtr));
						} else {
DEBUGLOG(("url not found\n"));
						}

						// cut_url
						if (GetField_CString(hDecrypted, "cut_url", &csPtr)) {
DEBUGLOG(("cut_url = [%s]\n", csPtr));
							PutField_CString(hOut, "code_url", csPtr);
						} else {
DEBUGLOG(("cut_url not found\n"));
							iRet = PD_ERR;
						}
					} else {
DEBUGLOG(("BreakDownInitMsg() Error\n"));
						iRet = PD_ERR;
					}
				}
			} else {
				PutField_CString(hOut, "return_code", csReturnCode);
				PutField_CString(hOut, "return_msg", csTmpReturnMsg);
			}
		} else {
DEBUGLOG(("BreakDownInitRspMsg() Invalid Response\n"));
			iRet = PD_ERR;
		}
	} else {
DEBUGLOG(("BreakDownInitRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hXml);
	FREE_ME(hXml);
	hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hDecrypted);
	FREE_ME(hDecrypted);
	FREE_ME(csDecryptedInfo);
	FREE_ME(csTmpReturnMsg);
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csBuf;
	char	*csURL = NULL;
	char	*csPtr = NULL;
	char	*csTmp = NULL;

DEBUGLOG(("FormatInqMsg() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_UNQ_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_UNQ_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
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

		// partner
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("partner = [%s]\n", csTmp));
			strcat((char*)outMsg, "partner");
			strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_UNQ_TOKEN);
		}
		else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
			iRet = PD_ERR;
		}

		// info
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("info = [%s]\n", url_encode(csTmp)));
			strcat((char*)outMsg, "info");
			strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
			strcat((char*)outMsg, url_encode(csTmp));
			strcat((char*)outMsg, MY_UNQ_TOKEN);
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
	int	iRet = PD_OK;
	char	*csBuf;
	char	*csPtr;

DEBUGLOG(("BuildInqAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	// out_trade_no
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("out_trade_no = [%s]\n", csPtr));
		strcat((char*)csBuf, "out_trade_no");
		strcat((char*)csBuf, MY_UNQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
	}
	else {
DEBUGLOG(("***txn_seq is missing\n"));
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
	int	iTmpRet = PD_OK;
	int	iLen;
	char	*csPtr, *csPspMerchantId, *csInfo, *csPspId, *csKeyFile, *csDecryptedInfo, *csTmpReturnMsg;
	csDecryptedInfo = (char*) malloc (PD_MAX_BUFFER);
	memset(csDecryptedInfo, 0, sizeof(csDecryptedInfo));
	csTmpReturnMsg = (char*) malloc (PD_TMP_MSG_BUF_LEN * 2 + 1);
	char	*csReturnCode = NULL;
	char	*csReturnMsg = NULL;
	hash_t	*hPspDetail;
	hash_t	*hKey;
	hash_t	*hDecrypted;

	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPspDetail, 0);

	hDecrypted = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hDecrypted, 0);

DEBUGLOG(("BreakDownInqRspMsg() Start\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));
	PutField_CString(hOut, "fail_reason", (char*)inMsg);

	hash_t *hXml;
	hXml = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hXml, 0);
	iRet = BreakDownXMLMsg(hXml, inMsg, inLen);

	if (iRet == PD_OK) {
		if (GetField_CString(hXml, "resp_code", &csReturnCode) &&
		    GetField_CString(hXml, "resp_desc", &csReturnMsg)) {
			// return_code
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			urldecode((const unsigned char*)csReturnMsg, strlen((const char*)csReturnMsg), (unsigned char*)csTmpReturnMsg, &iLen);
DEBUGLOG(("return_msg = [%s]\n", csTmpReturnMsg));

			if (!strcmp(csReturnCode, PD_SUCCESS_STATUS) && !strcmp(csTmpReturnMsg, PD_SUCCESS_MSG)) {
				// partner
				if (GetField_CString(hXml, "partner", &csPspMerchantId)) {
DEBUGLOG(("partner = [%s]\n", csPspMerchantId));
					PutField_CString(hOut, "partner", csPspMerchantId);
				} else {
DEBUGLOG(("*** partner is missing\n"));
					iRet = PD_ERR;
				}

				// info
				if (GetField_CString(hXml, "info", &csInfo)) {
DEBUGLOG(("info = [%s]\n", csInfo));
					PutField_CString(hOut, "info", csInfo);
				} else {
DEBUGLOG(("*** info is missing\n"));
					iRet = PD_ERR;
				}

				// get psp_id by channel and psp_merchant_id
				if (iRet == PD_OK) {
					DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "GetPspDetailByChannelMerchId");
					iTmpRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_UNIPAY_QR, csPspMerchantId, hPspDetail);
					if (iTmpRet != PD_OK) {
DEBUGLOG(("call DBPspDetail:GetPspDetailByChannelMerchId() failed\n"));
						iRet = PD_ERR;
					} else {
						if (GetField_CString(hPspDetail, "psp_id", &csPspId)) {
DEBUGLOG(("psp_id = [%s]\n", csPspId));
						} else {
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
					if (Str2Cls(hDecrypted, csDecryptedInfo, MY_UNQ_TOKEN, MY_UNQ_FIELD_TOKEN) == PD_OK) {
						// out_trade_no
						if (GetField_CString(hDecrypted, "out_trade_no", &csPtr)) {
DEBUGLOG(("out_trade_no:txn_seq = [%s]\n", csPtr));
							PutField_CString(hOut, "txn_seq", csPtr);
						}
						else {
DEBUGLOG(("out_trade_no:txn_seq not found\n"));
						}

						// amount
						if (GetField_CString(hDecrypted, "amount", &csPtr)) {
DEBUGLOG(("amount:txn_amt = [%s]\n", csPtr));
							PutField_CString(hOut, "txn_amt", csPtr);
						}
						else {
DEBUGLOG(("amount:txn_amt not found\n"));
						}

						// pay_result
						if (GetField_CString(hDecrypted, "pay_result", &csPtr)) {
DEBUGLOG(("pay_result:status = [%s]\n", csPtr));
							PutField_CString(hOut, "status", csPtr);
						}
						else {
DEBUGLOG(("pay_result:status not found\n"));
						}
					} else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
						iRet = PD_ERR;
					}
				}
			} else {
				PutField_CString(hOut, "fail_reason", csTmpReturnMsg);
			}
		} else {
DEBUGLOG(("BreakDownInqRspMsg() Invalid Response\n"));
			iRet = PD_ERR;
		}
	} else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	hash_destroy(hXml);
	FREE_ME(hXml);
	hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hDecrypted);
	FREE_ME(hDecrypted);
	FREE_ME(csDecryptedInfo);
	FREE_ME(csTmpReturnMsg);
DEBUGLOG(("BreakDownInqRspMsg() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildInqRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
DEBUGLOG(("BuildInqRspAuthData() Start\n"));
DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildCallbackAuthData() Start\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	strcat((char*)csBuf, " ");

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "partner", &csPtr)) {
		strcat((char*)outMsg, "partner");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_UNQ_TOKEN);
DEBUGLOG(("partner = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("partner not found\n"));
	}

	if (GetField_CString(hIn, "info", &csPtr)) {
		strcat((char*)outMsg, "info");
		strcat((char*)outMsg, MY_UNQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
DEBUGLOG(("info = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("info not found\n"));
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit iRet = [%d]\n", iRet));
	return iRet;
}

