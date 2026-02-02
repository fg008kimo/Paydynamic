/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2017/09/12              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UnwMsg.h"
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

void	UnwMsg(char cdebug)
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
		strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_UNW_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));


		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_UNW_TOKEN);
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
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_UNW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_UNW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_UNW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_UNW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_UNW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
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
	char*	csPtr;
	char*	csBuf;
	double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* 1 base64_memo */
// optional
	strcat((char*)csBuf,"base64_memo");
	strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
	strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);

/* 2 notify_url */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"notify_url");
		strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
		strcat((char*)csBuf,url_encode(csPtr));
		strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: notify_url = [%s]\n",url_encode(csPtr)));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** notify_url is missing\n"));
	}

/* 3 order_number */
	if (GetField_CString(hIn,"order_num",&csPtr)) {
		strcat((char*)csBuf,"order_number");
		strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: order_number = [%s]\n",csPtr));
	}

/* 4 pay_id */
	strcat((char*)csBuf,"pay_id");
	strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
	strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);

/* 5 gateway_type */
	strcat((char*)csBuf,"gateway_type");
	strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
	strcat((char*)csBuf,PD_GATEWAY_TYPE);
	strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: gateway_type = [%s]\n",PD_GATEWAY_TYPE));

/* 6 card_type */
	strcat((char*)csBuf,"card_type");
	strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
	strcat((char*)csBuf,PD_CARE_TYPE);
	strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: card_type = [%s]\n",PD_CARE_TYPE));

/* 7 return_url */
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
		strcat((char*)csBuf,"return_url");
		strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
		strcat((char*)csBuf,url_encode(csPtr));
		strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: return_url = [%s]\n",url_encode(csPtr)));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** return_url is missing\n"));
	}

/* 8 total_fee */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
		strcat((char*)csBuf,"total_fee");
		strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
		strcat((char*)csBuf,csTmpAmt);
		strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: total_fee = [%s]\n",csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** total_fee is missing\n"));
	}

/* 9 version */
// optional
	strcat((char*)csBuf,"version");
	strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n",iRet));
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

	if (Str2Cls(hRec,(char *)inMsg,MY_UNW_TOKEN, MY_UNW_FIELD_TOKEN) == PD_OK) {

// 1 partner
		if (GetField_CString(hRec, "partner", &csPspMerchantId)) {
DEBUGLOG(("BreakDownMsg:: partner = [%s]\n", csPspMerchantId));
		} else {
DEBUGLOG(("BreakDownMsg:: partner not found\n"));
			iRet = PD_ERR;
		}

// info
		if (iRet == PD_OK) {
			if (GetField_CString(hRec, "info", &csInfo)) {
DEBUGLOG(("BreakDownMsg:: info = [%s]\n", csInfo));
			} else {
DEBUGLOG(("BreakDownMsg:: info not found\n"));
				iRet = PD_ERR;
			}
		}

// get psp_id by channel and psp_merchant_id
		if (iRet == PD_OK) {
			DBObjPtr = CreateObj(DBPtr, "DBPspDetail", "GetPspDetailByChannelMerchId");
			iTmpRet = (unsigned long)(*DBObjPtr)(PD_CHANNEL_UNIPAY_WECHAT, csPspMerchantId, hPspDetail);
			if (iTmpRet != PD_OK) {
DEBUGLOG(("BreakDownMsg:: call DBPspDetail:GetPspDetailByChannelMerchId() failed\n"));
				iRet = PD_ERR;
			} else {
				if (GetField_CString(hPspDetail, "psp_id", &csPspId)) {
DEBUGLOG(("BreakDownMsg:: psp_id = [%s]\n", csPspId));
				}
				else {
DEBUGLOG(("BreakDownMsg:: psp_id not found\n"));
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
DEBUGLOG(("BreakDownMsg:: call DBPspKeys:GetPspKey() failed\n"));
				iRet = PD_ERR;
			} else {
				hKey = RecordSet_GetFirst(rKeySet);
				while (hKey) {
					if (GetField_CString(hKey, "privatepem", &csKeyFile)) {
DEBUGLOG(("BreakDownMsg:: private key file = [%s]\n", csKeyFile));
					} else {
DEBUGLOG(("BreakDownMsg:: private key file not found\n"));
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
DEBUGLOG(("BreakDownMsg:: decrypted info = [%s]\n", csDecryptedInfo));
			if (Str2Cls(hDecrypted, csDecryptedInfo, MY_UNW_TOKEN, MY_UNW_FIELD_TOKEN) == PD_OK) {
                                // 2.1 partner
				if (GetField_CString(hDecrypted, "partner", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: partner = [%s]\n", csPtr));
					PutField_CString(hOut, "partner", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: partner not found\n"));
				}

				// 2.2 out_trade_no
				if (GetField_CString(hDecrypted, "out_trade_no", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_seq", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
				}

				// 2.3 pay_no
				if (GetField_CString(hDecrypted, "pay_no", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n", csPtr));
					PutField_CString(hOut, "tid", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
				}

				// 2.4 amount
				if (GetField_CString(hDecrypted, "amount", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n", csPtr));
					PutField_CString(hOut, "txn_amt", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
				}

                                // 2.5 pay_result
				if (GetField_CString(hDecrypted, "pay_result", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: status = [%s]\n", csPtr));
					PutField_CString(hOut, "status", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: status not found\n"));
				}

				// 2.6 sett_date
				if (GetField_CString(hDecrypted, "sett_date", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_date = [%s]\n", csPtr));
					PutField_CString(hOut, "fundin_date", csPtr);
					PutField_CString(hOut, "txn_date", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: txn_date not found\n"));
				}

				// 2.7 mdr_fee
				if (GetField_CString(hDecrypted, "mdr_fee", &csPtr)) {
DEBUGLOG(("BreakDownMsg:: mdr_fee = [%s]\n", csPtr));
					PutField_CString(hOut, "mdr_fee", csPtr);
				}
				else {
DEBUGLOG(("BreakDownMsg:: mdr_fee not found\n"));
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

	char*	csPtr = NULL;
	char*	csURL = NULL;
	char*	csBuf;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0]= '\0';
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csURL));
DEBUGLOG(("FormatInitMsg:: request function = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_UNW_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csBuf));
		}

		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatInitMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
	}
	FREE_ME(csBuf);

// 1 partner
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: partner = [%s]\n",csPtr));
		strcat((char*)outMsg,"partner");
		strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_UNW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: partner is missing\n"));
	}

// 2 info
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: info = [%s]\n",url_encode(csPtr)));
		strcat((char*)outMsg,"info");
		strcat((char*)outMsg,MY_UNW_FIELD_TOKEN);
		strcat((char*)outMsg,url_encode(csPtr));
	} else {
DEBUGLOG(("FormatInitMsg:: info is missing\n"));
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return  iRet;
}


int BreakDownXMLMsg(hash_t *hOut,const unsigned char *inMsg,int inLen);


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	int	iTmpRet = PD_OK;
	char	*csPtr, *csPspMerchantId, *csInfo, *csPspId, *csKeyFile, *csDecryptedInfo;
	csDecryptedInfo = (char*) malloc (PD_MAX_BUFFER);
	memset(csDecryptedInfo, 0, sizeof(csDecryptedInfo));
	char	*csReturnCode = NULL;
	char	*csReturnMsg = NULL;
	hash_t	*hPspDetail;
	hash_t	*hKey;
	hash_t	*hDecrypted;

	hPspDetail = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hPspDetail, 0);

	hDecrypted = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hDecrypted, 0);

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	hash_t *hXml;
	hXml = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hXml,0);
	iRet = BreakDownXMLMsg(hXml,inMsg,inLen);

	if (iRet == PD_OK) {
		if (GetField_CString(hXml, "resp_code", &csReturnCode) &&
		    GetField_CString(hXml, "resp_desc", &csReturnMsg)) {
			// return_code
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
DEBUGLOG(("return_msg = [%s]\n", csReturnMsg));

			if ((!strcmp(csReturnCode,PD_SUCC_RSP_CODE)) && (!strcmp(csReturnMsg,PD_SUCC_RSP_DESC))) {
				// partner
				if (GetField_CString(hXml, "partner", &csPspMerchantId)) {
DEBUGLOG(("partner = [%s]\n", csPspMerchantId));
				} else {
DEBUGLOG(("partner not found\n"));
					iRet = PD_ERR;
				}

				// info
				if (GetField_CString(hXml, "info", &csInfo)) {
DEBUGLOG(("info = [%s]\n", csInfo));
				} else {
DEBUGLOG(("info not found\n"));
					iRet = PD_ERR;
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
					if (Str2Cls(hDecrypted, csDecryptedInfo, MY_UNW_TOKEN, MY_UNW_FIELD_TOKEN) == PD_OK) {
						// order_number
						if (GetField_CString(hDecrypted, "order_number", &csPtr)) {
DEBUGLOG(("order_number = [%s]\n", csPtr));
							PutField_CString(hOut, "txn_seq", csPtr);
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
							PutField_CString(hOut, "return_msg", csPtr);
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
				PutField_CString(hOut,"return_code",csReturnCode);
				PutField_CString(hOut,"return_msg",csReturnMsg);
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
	hash_destroy(hPspDetail);
	FREE_ME(hPspDetail);
	hash_destroy(hDecrypted);
	FREE_ME(hDecrypted);
	FREE_ME(csDecryptedInfo);
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int BuildRspAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr;
        char*   csBuf;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

DEBUGLOG(("BuildRspAuthData()\n"));
        memset(csBuf,0,MAX_MSG_SIZE);
        csBuf[0] = '\0';


/* 1 amount */
        if (GetField_CString(hIn,"txn_amt",&csPtr)) {
                strcat((char*)csBuf,"amount=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: amount = [%s]\n",csPtr));
        }

/* 2 base64_memo*/
        if (GetField_CString(hIn,"remark",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"base64_memo=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: base64_memo = [%s]\n",csPtr));
        }
        else{
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"base64_memo=");
DEBUGLOG(("BuildRspAuthData:: base64_memo is null\n"));
        }

/* 3 out_trade_no */
        if (GetField_CString(hIn,"txn_seq",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"out_trade_no=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: out_trade_no = [%s]\n",csPtr));
        }

/* 4 partner*/
        if (GetField_CString(hIn,"partner",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"partner=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: partner = [%s]\n",csPtr));
        }

/* 5 pay_no*/
        if (GetField_CString(hIn,"tid",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"pay_no=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: pay_no = [%s]\n",csPtr));
        }

/* 6 pay_result*/
        if (GetField_CString(hIn,"status",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"pay_result=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: pay_result = [%s]\n",csPtr));
        }

/* 7 sett_date*/
        if (GetField_CString(hIn,"txn_date",&csPtr)) {
                strcat((char*)csBuf,MY_UNW_AUTH_TOKEN);
                strcat((char*)csBuf,"sett_date=");
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: sett_date = [%s]\n",csPtr));
        }

        PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
        FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}

