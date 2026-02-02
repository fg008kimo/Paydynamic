/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2017/04/18              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "WfqMsg.h"
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

#define PD_P0_CMD		"Buy"

OBJPTR(DB);
OBJPTR(BO);
char	cDebug;

void	WfqMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
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
		strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_WFQ_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));
		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_WFQ_TOKEN);
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
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_WFQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_WFQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_WFQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_WFQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_WFQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_WFQ_FIELD_TOKEN);
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


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr, *csDATA;
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	double	dTmp;
	csDATA = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csDATA, 0, sizeof(csDATA));

// orgCode
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("BuildAuthData:: orgCode = [%s]\n", csPtr));
		strcat((char*)csDATA, "orgCode");
		strcat((char*)csDATA, MY_WFQ_FIELD_TOKEN);
		strcat((char*)csDATA, csPtr);
		strcat((char*)csDATA, MY_WFQ_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: psp_merchant_id is missing!!\n"));
	}

// amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("BuildAuthData:: amt = [%s]\n", csTmpAmt));
		strcat((char*)csDATA, "amt");
		strcat((char*)csDATA, MY_WFQ_FIELD_TOKEN);
		strcat((char*)csDATA, (char*)csTmpAmt);
		strcat((char*)csDATA, MY_WFQ_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!\n"));
	}

// payType
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "WFQ", "CN", csOutBankCode)) {
			strcat((char*)csDATA, "payType");
			strcat((char*)csDATA, MY_WFQ_FIELD_TOKEN);
			strcat((char*)csDATA, csOutBankCode);
			strcat((char*)csDATA, MY_WFQ_TOKEN);
DEBUGLOG(("BuildAuthData:: payType = [%s]\n", csOutBankCode));
		}
	} else {
DEBUGLOG(("BuildAuthData:: bank_code is missing!!\n"));
	}

DEBUGLOG(("BuildAuthData:: DATA = [%s]\n", csDATA));
	PutField_CString(hIn, "auth_data", csDATA);

	FREE_ME(csDATA);
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
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_WFQ_TOKEN, MY_WFQ_FIELD_TOKEN) == PD_OK) {
/* orgCode */
		if (GetField_CString(hRec,"orgCode",&csPtr)) {
			PutField_CString(hOut,"psp_merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg:: orgCode:psp_merchant_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: orgCode:psp_merchant_id not found\n"));
		}

/* r0_Cmd */
		if (GetField_CString(hRec,"r0_Cmd",&csPtr)) {
			PutField_CString(hOut,"r0_Cmd",csPtr);
DEBUGLOG(("BreakDownMsg:: r0_Cmd = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r0_Cmd not found\n"));
		}

/* r1_Code */
		if (GetField_CString(hRec,"r1_Code",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: r1_Code:status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r1_Code:status not found\n"));
		}

/* r2_TrxId */
		if (GetField_CString(hRec,"r2_TrxId",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: r2_TrxId:tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r2_TrxId:tid not found\n"));
		}

/* r3_Amt */
		if (GetField_CString(hRec,"r3_Amt",&csPtr)) {
			PutField_CString(hOut,"psp_txn_amt",csPtr);
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: r3_Amt:txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r3_Amt:txn_amt not found\n"));
		}

/* r4_Cur */
		if (GetField_CString(hRec,"r4_Cur",&csPtr)) {
			PutField_CString(hOut,"psp_txn_ccy",csPtr);
DEBUGLOG(("BreakDownMsg:: r4_Cur:psp_txn_ccy = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r4_Cur:psp_txn_ccy not found\n"));
		}

/* r5_Pid */
		if (GetField_CString(hRec,"r5_Pid",&csPtr)) {
			PutField_CString(hOut,"r5_Pid",csPtr);
DEBUGLOG(("BreakDownMsg:: r5_Pid = [%s]\n",csPtr));
		}

/* r6_Order */
		if (GetField_CString(hRec,"r6_Order",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: r6_Order:txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r6_Order:txn_seq not found\n"));
		}

/* r8_MP */
		if (GetField_CString(hRec,"r8_MP",&csPtr)) {
			PutField_CString(hOut,"r8_MP",csPtr);
DEBUGLOG(("BreakDownMsg:: r8_MP = [%s]\n",csPtr));
		}

/* r9_BType */
		if (GetField_CString(hRec,"r9_BType",&csPtr)) {
			PutField_CString(hOut,"r9_BType",csPtr);
DEBUGLOG(("BreakDownMsg:: r9_BType = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r9_BType not found\n"));
		}

/* ro_BankOrderId */
		if (GetField_CString(hRec,"ro_BankOrderId",&csPtr)) {
			PutField_CString(hOut,"bank_bill_no",csPtr);
DEBUGLOG(("BreakDownMsg:: ro_BankOrderId:bank_bill_no = [%s]\n",csPtr));
		}

/* rp_PayDate */
		if (GetField_CString(hRec,"rp_PayDate",&csPtr)) {
			PutField_CString(hOut,"fundin_date",csPtr);
			PutField_CString(hOut,"txn_date",csPtr);
DEBUGLOG(("BreakDownMsg:: rp_PayDate:fundin_date = [%s]\n",csPtr));
		}

/* hmac */
		if (GetField_CString(hRec,"hmac",&csPtr)) {
			PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg:: hmac:sign = [%s]\n",csPtr));
		}
		else{
			PutField_CString(hOut,"sign"," ");
DEBUGLOG(("BreakDownMsg:: hmac:sign = [%s]\n"," "));
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
	int	iRet = PD_OK;

	return iRet;
}


int FormatInitMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
	char	*csURL = NULL;
	char	*csBuf;
	char	*csTmp;
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	double	dTmp;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	csTmp = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0] = '\0';
// psp_url
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n", csURL));
DEBUGLOG(("FormatInitMsg:: request_function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_WFQ_FIELD_TOKEN);
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

// orgCode
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: orgCode = [%s]\n", csPtr));
		strcat((char*)outMsg, "orgCode");
		strcat((char*)outMsg, MY_WFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_WFQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: orgCode is missing\n"));
	}

// serviceCode
DEBUGLOG(("FormatInitMsg:: serviceCode = [%s]\n", PD_SERVICE_CODE));
	strcat((char*)outMsg, "serviceCode");
	strcat((char*)outMsg, MY_WFQ_FIELD_TOKEN);
	strcat((char*)outMsg, PD_SERVICE_CODE);
	strcat((char*)outMsg, MY_WFQ_TOKEN);

// orgNo
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: orgNo = [%s]\n", csPtr));
		strcat((char*)outMsg, "orgNo");
		strcat((char*)outMsg, MY_WFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_WFQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: orgNo is missing\n"));
	}

	json_object *jobj = json_object_new_object();

// amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("FormatInitMsg:: amt = [%s]\n", csTmpAmt));
		json_object_object_add(jobj, "amt", json_object_new_string(csTmpAmt));
	} else {
DEBUGLOG(("FormatInitMsg:: amt is missing\n"));
	}

// payType
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "WFQ", "CN", csOutBankCode)) {
DEBUGLOG(("FormatInitMsg:: payType = [%s]\n", csOutBankCode));
			json_object_object_add(jobj, "payType", json_object_new_string(csOutBankCode));
		}
	} else {
DEBUGLOG(("FormatInitMsg:: bank_code is missing\n"));
	}

// subject
DEBUGLOG(("FormatInitMsg:: subject = [%s]\n", PD_SUBJECT));
	json_object_object_add(jobj, "subject", json_object_new_string(PD_SUBJECT));

// returnUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: returnUrl = [%s]\n", csPtr));
		json_object_object_add(jobj, "returnUrl", json_object_new_string(csPtr));
	} else {
DEBUGLOG(("FormatInitMsg:: returnUrl is missing\n"));
	}

	strcpy((char*)csTmp, json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN));
	strcat((char*)outMsg, "jsonData");
	strcat((char*)outMsg, MY_WFQ_FIELD_TOKEN);
	strcat((char*)outMsg, csTmp);
	strcat((char*)outMsg, MY_WFQ_TOKEN);

// sign
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("FormatInitMsg:: sign = [%s]\n", csPtr));
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_WFQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
	} else {
DEBUGLOG(("FormatInitMsg:: sign is missing\n"));
	}

	FREE_ME(csTmp);

DEBUGLOG(("outmsg = [%s]\n", outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);

	json_object_put(jobj);

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

	if (Str2Cls(hRec, (char*)inMsg, MY_WFQ_TOKEN, MY_WFQ_FIELD_TOKEN) == PD_OK) {
		if (GetField_CString(hRec, "respCode", &csReturnCode)) {
			// respCode
DEBUGLOG(("BreakDownInitRspMsg:: return_code = [%s]\n", csReturnCode));
			PutField_CString(hOut, "return_code", csReturnCode);

			// respDesc
			if (GetField_CString(hRec, "respDesc", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: return_msg = [%s]\n", csPtr));
				PutField_CString(hOut, "return_msg", csPtr);
			}

			if (!strcmp(csReturnCode, PD_SUCCESS_STATUS)) {
				// orgCode
				if (GetField_CString(hRec, "orgCode", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: orgCode = [%s]\n", csPtr));
					PutField_CString(hOut, "orgCode", csPtr);
				}

				// serviceCode
				if (GetField_CString(hRec, "serviceCode", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: serviceCode = [%s]\n", csPtr));
					PutField_CString(hOut, "serviceCode", csPtr);
				}

				// orgNo
				if (GetField_CString(hRec, "orgNo", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: orgNo = [%s]\n", csPtr));
					PutField_CString(hOut, "orgNo", csPtr);
				}

				// bizId
				if (GetField_CString(hRec, "bizId", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: bizId = [%s]\n", csPtr));
					PutField_CString(hOut, "bizId", csPtr);
				}

				// jsonData
				if (GetField_CString(hRec, "jsonData", &csPtr)) {
					struct json_object *jobj;
					enum json_type type;

					jobj = json_tokener_parse((const char *)csPtr);
					if (jobj != NULL) {
						json_object_object_foreach(jobj, key, val) {
							type = json_object_get_type(val);
							switch (type) {
								case json_type_string:
									PutField_CString(hRec, key, json_object_get_string(val));
								break;
								default:
DEBUGLOG(("BreakDownInitRspMsg:: unsupported type\n"));
								break;
							}
						}
					}

					json_object_put(jobj);
				}

				// payUrl
				if (GetField_CString(hRec, "payUrl", &csPtr)) {
DEBUGLOG(("BreakDownInitRspMsg:: payUrl = [%s]\n", csPtr));
					PutField_CString(hOut, "code_url", csPtr);
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

	hash_destroy(hRec);
	FREE_ME(hRec);
DEBUGLOG(("BreakDownInitRspMsg Exit\n"));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int     iRet = PD_OK;
	char*   csPtr;
	char*   csBuf;
	char    csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* orgCode (result) */
	strcpy(csTag, "psp_merchant_id");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r0_Cmd (init & result) */
	strcpy(csTag, "r0_Cmd");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* orgCode (init) */
	strcpy(csTag, "orgCode");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r1_Code (result) */
	strcpy(csTag, "status");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r1_Code (init) */
	strcpy(csTag, "return_code");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r2_TrxId (result) */
	strcpy(csTag, "tid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r2_TrxId (init) */
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/***** result begin *****/

/* r3_Amt */
	strcpy(csTag, "psp_txn_amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r4_Cur */
	strcpy(csTag, "psp_txn_ccy");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r5_Pid */
	strcpy(csTag, "r5_Pid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r6_Order */
	strcpy(csTag, "txn_seq");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r8_MP */
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r9_BType */
	strcpy(csTag, "r9_BType");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* ro_BankOrderId */
	strcpy(csTag, "bank_bill_no");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* rp_PayDate */
	strcpy(csTag, "fundin_date");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/***** result end *****/

/***** init begin *****/

/* r3_PayInfo */
	strcpy(csTag, "code_url");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r4_Amt */
	strcpy(csTag, "amount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r5_OpenId */
	strcpy(csTag, "r5_OpenId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r6_AuthCode */
	strcpy(csTag, "r6_AuthCode");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r7_Desc */
	strcpy(csTag, "return_msg");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* r8_Order */
	strcpy(csTag, "requestId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/***** init end *****/

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

