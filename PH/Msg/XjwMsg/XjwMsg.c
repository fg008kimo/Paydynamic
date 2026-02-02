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
#include "XjwMsg.h"
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
#define PD_OPEN_BRACKET_H	0x7b
#define PD_CLOSE_BRACKET_H	0x7d
#define PD_OPEN_BRACKET		'{'//0x7b
#define PD_CLOSE_BRACKET	'}'//0x7d
#define PD_P0_CMD		"Buy"
#define PD_PAYMENT_WECHAT	"WEIXIN"
#define PD_PAYMENT_QQ		"QQ"
#define PD_PAYMENT_ALIPAY	"ALIPAY"
#define PD_PAYMENT_EC		"Nocard"

OBJPTR(DB);
OBJPTR(BO);
char	cDebug;

void	XjwMsg(char cdebug)
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
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_XJW_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));


		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_XJW_TOKEN);
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
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_XJW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_XJW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_XJW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_XJW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_XJW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
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
	char	*csPtr,*csDATA;
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];
	double	dTmp;
	csDATA = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csDATA,0,sizeof(csDATA));

// p0_Cmd
DEBUGLOG(("BuildAuthData:: p0_Cmd = [%s]\n", PD_P0_CMD));
	strcat((char*)csDATA, PD_P0_CMD);

// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("BuildAuthData:: p1_MerId = [%s]\n", csPtr));
		strcat((char*)csDATA, csPtr);
	} else {
DEBUGLOG(("BuildAuthData:: psp_merchant_id is missing!!\n"));
	}

// p2_Order
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("BuildAuthData:: p2_Order = [%s]\n", csPtr));
		strcat((char*)csDATA, csPtr);
	} else {
DEBUGLOG(("BuildAuthData:: order_num is missing!!\n"));
	}

// p3_Cur
DEBUGLOG(("BuildAuthData:: p3_Cur = [%s]\n", PD_CCY_ISO_CNY));
	strcat((char*)csDATA, PD_CCY_ISO_CNY);

// p4_Amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
DEBUGLOG(("BuildAuthData:: psp_txn_amt = [%f]\n", dTmp));
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("BuildAuthData:: p4_Amt = [%s]\n", csTmpAmt));
		strcat((char*)csDATA, (char*)csTmpAmt);
	} else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!\n"));
	}

// p8_Url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("BuildAuthData:: p8_Url = [%s]\n", csPtr));
		strcat((char*)csDATA, csPtr);
	} else {
DEBUGLOG(("BuildAuthData:: return_url_only is missing!!\n"));
	}

// pa_FrpId
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
/*
		if(!strcmp(csPtr,"086082")){
			strcat((char*)csDATA,PD_PAYMENT_QQ);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n", PD_PAYMENT_QQ));
		}
		else if(!strcmp(csPtr,"086081")){
			strcat((char*)csDATA,PD_PAYMENT_WECHAT);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n", PD_PAYMENT_WECHAT));
		}
		else if(!strcmp(csPtr,"086083")){
			strcat((char*)csDATA,PD_PAYMENT_ALIPAY);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n", PD_PAYMENT_ALIPAY));
		}
*/
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "XJW", "CN", csOutBankCode)) {
			strcat((char*)csDATA,csOutBankCode);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n", csOutBankCode));
		}
	}


	PutField_CString(hIn, "auth_data", csDATA);

DEBUGLOG(("BuildAuthData:: DATA = [%s]\n", csDATA));

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

	if (Str2Cls(hRec, (char *)inMsg, MY_XJW_TOKEN, MY_XJW_FIELD_TOKEN) == PD_OK) {
/* p1_MerId */
		if (GetField_CString(hRec,"p1_MerId",&csPtr)) {
			PutField_CString(hOut,"psp_merchant_id",csPtr);
DEBUGLOG(("BreakDownMsg:: p1_MerId:psp_merchant_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: p1_MerId:psp_merchant_id not found\n"));
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
	double	dTmp;
	char	csOutBankCode[PD_EXT_BANK_CODE_LEN + 1];

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0]= '\0';
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csURL));
DEBUGLOG(("FormatInitMsg:: request function = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_XJW_FIELD_TOKEN);
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

//p0_Cmd
DEBUGLOG(("FormatInitMsg:: p0_Cmd = [%s]\n", PD_P0_CMD));
	strcat((char*)outMsg,"p0_Cmd");
	strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
	strcat((char*)outMsg,PD_P0_CMD);
	strcat((char*)outMsg,MY_XJW_TOKEN);

//p1_MerId
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: p1_MerId = [%s]\n",csPtr));
		strcat((char*)outMsg,"p1_MerId");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_XJW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: p1_MerId is missing\n"));
	}

//p2_Order
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: p2_Order = [%s]\n",csPtr));
		strcat((char*)outMsg,"p2_Order");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_XJW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: p2_Order is missing\n"));
	}

//p3_Cur
DEBUGLOG(("FormatInitMsg:: p3_Cur = [%s]\n", PD_CCY_ISO_CNY));
	strcat((char*)outMsg,"p3_Cur");
	strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
	strcat((char*)outMsg,PD_CCY_ISO_CNY);
	strcat((char*)outMsg,MY_XJW_TOKEN);

//p4_Amt
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("FormatInitMsg:: p4_Amt = [%s]\n",csTmpAmt));
		strcat((char*)outMsg,"p4_Amt");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csTmpAmt);
		strcat((char*)outMsg,MY_XJW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: p4_Amt is missing\n"));
	}

//p8_Url
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: p8_Url = [%s]\n",csPtr));
		strcat((char*)outMsg,"p8_Url");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_XJW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: p8_Url is missing\n"));
	}

//pa_FrpId
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		strcat((char*)outMsg,"pa_FrpId");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
/*
		if(!strcmp(csPtr,"086082")){
			strcat((char*)outMsg,PD_PAYMENT_QQ);
DEBUGLOG(("FormatInitMsg:: pa_FrpId = [%s]\n", PD_PAYMENT_QQ));
		}
		else if(!strcmp(csPtr,"086081")){
			strcat((char*)outMsg,PD_PAYMENT_WECHAT);
DEBUGLOG(("FormatInitMsg:: pa_FrpId = [%s]\n", PD_PAYMENT_WECHAT));
		}
		else if(!strcmp(csPtr,"086083")){
			strcat((char*)outMsg,PD_PAYMENT_ALIPAY);
DEBUGLOG(("FormatInitMsg:: pa_FrpId = [%s]\n", PD_PAYMENT_ALIPAY));
		}
*/
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, "XJW", "CN", csOutBankCode)) {
			strcat((char*)outMsg,csOutBankCode);
DEBUGLOG(("FormatInitMsg:: pa_FrpId = [%s]\n", csOutBankCode));
		}
		strcat((char*)outMsg,MY_XJW_TOKEN);
	}

//hmac
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: hmac = [%s]\n",csPtr));
		strcat((char*)outMsg,"hmac");
		strcat((char*)outMsg,MY_XJW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
	} else {
DEBUGLOG(("FormatInitMsg:: hmac is missing\n"));
	}

DEBUGLOG(("outmsg = [%s]\n",outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return  iRet;
}


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csReturnCode;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

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
DEBUGLOG(("BreakDownInitRspMsg:: unsupported type\n"));
				break;
			}
		}

		if (GetField_CString(hRec,"r1_Code",&csReturnCode)) {
			//return_code
			PutField_CString(hOut,"return_code",csReturnCode);
DEBUGLOG(("BreakDownInitRspMsg:: return_code = [%s]\n",csReturnCode));

			//return_msg
			if (GetField_CString(hRec,"r7_Desc",&csPtr)) {
				PutField_CString(hOut,"return_msg",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: return_msg = [%s]\n",csPtr));
			}

			if (!strcmp(csReturnCode,"1")) {
				//r0_Cmd
				if (GetField_CString(hRec,"r0_Cmd",&csPtr)) {
					PutField_CString(hOut,"r0_Cmd",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r0_Cmd = [%s]\n",csPtr));
				}

				//p1_MerId
				if (GetField_CString(hRec,"p1_MerId",&csPtr)) {
					PutField_CString(hOut,"p1_MerId",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: p1_MerId = [%s]\n",csPtr));
				}

				//r2_TrxId
				if (GetField_CString(hRec,"r2_TrxId",&csPtr)) {
					PutField_CString(hOut,"r2_TrxId",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r2_TrxId = [%s]\n",csPtr));
				}

				//r3_PayInfo
				if (GetField_CString(hRec,"r3_PayInfo",&csPtr)) {
					PutField_CString(hOut,"code_url",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r3_PayInfo:code_url = [%s]\n",csPtr));
				}

				//r4_Amt
				if (GetField_CString(hRec,"r4_Amt",&csPtr)) {
					PutField_CString(hOut,"amount",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r4_Amt:amount = [%s]\n",csPtr));
				}

				//r5_OpenId
				if (GetField_CString(hRec,"r5_OpenId",&csPtr)) {
					PutField_CString(hOut,"r5_OpenId",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r5_OpenId = [%s]\n",csPtr));
				}

				//r6_AuthCode
				if (GetField_CString(hRec,"r6_AuthCode",&csPtr)) {
					PutField_CString(hOut,"r6_AuthCode",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r6_AuthCode = [%s]\n",csPtr));
				}

				//r8_Order
				if (GetField_CString(hRec,"r8_Order",&csPtr)) {
					PutField_CString(hOut,"requestId",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: r8_Order:requestId = [%s]\n",csPtr));
				}

				//hmac
				if (GetField_CString(hRec,"hmac",&csPtr)) {
					PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: hmac:sign = [%s]\n",csPtr));
				}
			}
		}
		else{
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


int BuildRspAuthData(hash_t* hIn)
{
	int     iRet = PD_OK;
	char*   csPtr;
	char*   csBuf;
	char    csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* p1_MerId (result) */
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

/* p1_MerId (init) */
	strcpy(csTag, "p1_MerId");
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

