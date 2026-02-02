/*
PDProTech (c)2016. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2016/12/13              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "XjpMsg.h"
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

#define PD_DOUBLE_QUOTE		0x22
#define PD_OPEN_BRACKET_H	0x7b
#define PD_CLOSE_BRACKET_H	0x7d
#define PD_OPEN_BRACKET		'{'//0x7b
#define PD_CLOSE_BRACKET	'}'//0x7d
#define	PD_PRODUCT_NAME		"PAY"
#define PD_PRODUCT_QUANTITY	"1"
#define PD_CLIENT_IP		"127.0.0.1"
#define PD_TIMEOUT		"11"

#define PD_PRODUCT_CAT          "1"
#define PD_IDENTITY_TYPE        "2"
#define PD_TERMINAL_TYPE        "3"
#define PD_TERMINAL_ID          "T1"
#define PD_DEF_CUST_ID          "0001"

OBJPTR(DB);
OBJPTR(BO);
char	cDebug;
void remove_quote(const char* csValue, const int iType,char* csOut);

void	XjpMsg(char cdebug)
{
	cDebug = cdebug;
}



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
		strcat((char*)outMsg,MY_XJP_TOKEN);
		strcat((char*)outMsg,"url_method");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csMethod);
		strcat((char*)outMsg,MY_XJP_TOKEN);
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



int BuildData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr,*csDATA;
	char	csTmp[PD_AMOUNT_LEN];
        double  dTmp;
        csDATA = (char*) malloc (1024 * 2 +1);

DEBUGLOG(("BuildData()\n"));

        memset(csDATA,0,sizeof(csDATA));

// merchantId
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("BuildData:: merchantId = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: psp_merchant_id is missing!!\n"));
	}

// orderAmount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("BuildData:: psp_txn_amt = [%f]\n",dTmp));
		sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildData:: orderAmount = [%s]\n",csTmp));
		strcat((char*)csDATA,(char*)csTmp);
	} else {
DEBUGLOG(("BuildData:: psp_txn_amt is missing!!\n"));
	}

// orderCurrency
	strcat((char*)csDATA,PD_CCY_ISO_CNY);

// requestId
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("BuildData:: requestId = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: order_num is missing!!\n"));
	}

// notifyUrl
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("BuildData:: notifyUrl = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: return_url_only is missing!!\n"));
	}

// callbackUrl
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("BuildData:: callbackUrl = [%s]\n",csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: fe_url is missing!!\n"));
	}

// paymentModeCode
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
DEBUGLOG(("BuildData:: paymentModeCode = [%s]\n", csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: bank_code is missing!!\n"));
	}

// productDetails.name
	strcat((char*)csDATA,PD_PRODUCT_NAME);

// productDetails.quantity
	strcat((char*)csDATA,PD_PRODUCT_QUANTITY);

// productDetails.amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("BuildData:: psp_txn_amt = [%f]\n",dTmp));
		sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildData:: amount = [%s]\n",csTmp));
		strcat((char*)csDATA,(char*)csTmp);
	} else {
DEBUGLOG(("BuildData:: psp_txn_amt is missing!!\n"));
	}

// clientIp
	if (GetField_CString(hIn,"org_ip_addr",&csPtr)) {
DEBUGLOG(("BuildData:: clientIp = [%s]\n", csPtr));
		strcat((char*)csDATA,csPtr);
	} else {
DEBUGLOG(("BuildData:: org_ip_addr is missing!!\n"));
	}

	PutField_CString(hIn,"auth_data",csDATA);

DEBUGLOG(("BuildData:: DATA = [%s]\n",csDATA));

        FREE_ME(csDATA);
DEBUGLOG(("BuildData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}



int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	iRet = DEBlockXjpData(hOut, inMsg, inLen);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return iRet;
}



int DEBlockXjpData(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csDATA;
	char	csTag[PD_TAG_LEN + 1];
	char	*csPara = malloc(PD_MAX_BUFFER + 1);

	csTmp = (char*) malloc (PD_MAX_BUFFER + 1);
	csDATA = (char*) malloc (PD_MAX_BUFFER + 1);

	hash_t *hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	memcpy(csDATA, inMsg, inLen);
	csDATA[inLen] = '\0';
DEBUGLOG(("DEBlockData data=[%s]\n", csDATA));

	if (iRet == PD_OK) {
		csPara[0] = '\0';
		remove_quote(csDATA, PD_OPEN_BRACKET_H, csPara);
		strcpy(csDATA, csPara);

		csPara[0] = '\0';
		remove_quote(csDATA, PD_CLOSE_BRACKET_H, csPara);
		strcpy(csDATA, csPara);
	}
	if (iRet == PD_OK &&
		Str2Cls(hRec, (const char *)csDATA, MY_XJP_JSON_TOKEN, MY_XJP_JSON_FIELD_TOKEN) == PD_OK) {

		sprintf(csTag, "\"merchantId\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "mid", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"requestId\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "txn_seq", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"serialNumber\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "tid", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"totalRefundCount\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "totalRefundCount", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"totalRefundAmount\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "totalRefundAmount", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"orderCurrency\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "orderCurrency", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"orderAmount\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "txn_amt", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"status\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "status", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"completeDateTime\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "completeDateTime", csPara);

			char csTxnDate[PD_DATE_LEN + 1];
			sprintf(csTxnDate, "%.*s%.*s%.*s",
				PD_YYYY_LEN, csPara,
				PD_MM_LEN, &csPara[PD_YYYY_LEN + 1],
				PD_DD_LEN, &csPara[PD_YYYYMM_LEN + 2]);
			PutField_CString(hOut, "txn_date", csTxnDate);

			char csTxnDateTime[PD_DATETIME_LEN + 1];
			sprintf(csTxnDateTime, "%.*s%.*s%.*s%.*s%.*s%.*s",
				PD_YYYY_LEN, csPara,
				PD_MM_LEN, &csPara[PD_YYYY_LEN + 1],
				PD_DD_LEN, &csPara[PD_YYYYMM_LEN + 2],
				2, &csPara[11],
				2, &csPara[14],
				2, &csPara[17]);
			PutField_CString(hOut, "fundin_date", csTxnDateTime);

			PutField_CString(hOut, "completeDateTime", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
DEBUGLOG(("DBlockData [txn_date] = [%s]\n", csTxnDate));
DEBUGLOG(("DBlockData [fundin_date] = [%s]\n", csTxnDateTime));
		}

		sprintf(csTag, "\"remark\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "remark", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"hmac\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "sign", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}
	}

	FREE_ME(csPara);
	FREE_ME(csTmp);
	FREE_ME(csDATA);
	FREE_ME(hRec);
DEBUGLOG(("DBlockData Exit\n"));
	return iRet;
}



int DEBlockXjpInitData(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csDATA;
	char	csTag[PD_TAG_LEN + 1];
	char	*csPara = malloc(PD_MAX_BUFFER + 1);

	csTmp = (char*) malloc (PD_MAX_BUFFER + 1);
	csDATA = (char*) malloc (PD_MAX_BUFFER + 1);

	hash_t *hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	memcpy(csDATA, inMsg, inLen);
	csDATA[inLen] = '\0';
DEBUGLOG(("DEBlockData data=[%s]\n", csDATA));

	if (iRet == PD_OK) {
		csPara[0] = '\0';
		remove_quote(csDATA, PD_OPEN_BRACKET_H, csPara);
		strcpy(csDATA, csPara);

		csPara[0] = '\0';
		remove_quote(csDATA, PD_CLOSE_BRACKET_H, csPara);
		strcpy(csDATA, csPara);
	}
	if (iRet == PD_OK &&
		Str2Cls(hRec, (const char *)csDATA, MY_XJP_JSON_TOKEN, MY_XJP_JSON_FIELD_TOKEN) == PD_OK) {

		sprintf(csTag, "\"merchantId\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "merchantId", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"requestId\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0]= '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "requestId", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"status\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "status", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"redirectUrl\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "redirectUrl", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}

		sprintf(csTag, "\"hmac\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
			PutField_CString(hOut, "sign", csPara);
DEBUGLOG(("DBlockData [%s] = [%s]\n", csTag, csPara));
		}
	}

	FREE_ME(csPara);
	FREE_ME(csTmp);
	FREE_ME(csDATA);
	FREE_ME(hRec);
DEBUGLOG(("DBlockData Exit\n"));
	return iRet;
}



int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}



void remove_quote(const char* csValue, const int iType, char* csOut)
{
	int i = 0;
	int cnt = 0;
	for(i = 0; i < strlen(csValue); i++) {
//DEBUGLOG(("%x\n", csValue[i]));
		if (csValue[i] != iType) {
			csOut[cnt] = csValue[i];
			cnt++;
		}
		else {
		}
	}
	csOut[cnt] = '\0';
}



int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char	csTmp[PD_AMOUNT_LEN];
	char*	csPtr = NULL;
	char*   csURL = NULL;
	char*	csBuf;
	double	dTmp = 0.0;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));

// psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csURL));
DEBUGLOG(("FormatInitMsg:: request function = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_XJP_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csBuf));
		}

		strcat((char*)csBuf,MY_XJP_TOKEN);
		strcat((char*)csBuf,"CURLOPT_HTTPHEADER");
		strcat((char*)csBuf,MY_XJP_FIELD_TOKEN);
		strcat((char*)csBuf,"Content-Type: application/vnd.ehking-v1.0+json");

		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatInitMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
	}
	FREE_ME(csBuf);

	strcat((char*)outMsg,MY_XJP_JSON_START_TOKEN);

// merchantId
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: merchantId = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"merchantId\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** psp_merchant_id is missing\n"));
	}

// orderAmount
       	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
DEBUGLOG(("FormatInitMsg:: psp_txn_amt = [%f]\n",dTmp));
               	sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatInitMsg:: orderAmount = [%s]\n",csTmp));
               	strcat((char*)outMsg,"\"orderAmount\":\"");
               	strcat((char*)outMsg,(char*)csTmp);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
       	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** psp_txn_amt is missing\n"));
	}

// orderCurrency
DEBUGLOG(("FormatInitMsg:: orderAmount[DEFAULT] = [%s]\n",PD_CCY_ISO_CNY));
	strcat((char*)outMsg,"\"orderCurrency\":\"");
	strcat((char*)outMsg,PD_CCY_ISO_CNY);
	strcat((char*)outMsg,"\"");
	strcat((char*)outMsg,MY_XJP_JSON_TOKEN);

// requestId
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: requestId = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"requestId\":\"");
               	strcat((char*)outMsg,csPtr);
               	strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** order_num is missing\n"));
	}

// notifyUrl
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: notifyUrl = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"notifyUrl\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** return_url_only is missing\n"));
	}

// callbackUrl
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: callbackUrl = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"callbackUrl\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** fe_url is missing\n"));
	}

// paymentModeCode
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: paymentModeCode = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"paymentModeCode\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** bank_code is missing\n"));
	}

// start of productDetails
	strcat((char*)outMsg,"\"productDetails\":");
	strcat((char*)outMsg,MY_XJP_JSON_START_TOKEN_2);
	strcat((char*)outMsg,MY_XJP_JSON_START_TOKEN);

//// name
DEBUGLOG(("FormatInitMsg:: name[DEFAULT] = [%s]\n",PD_PRODUCT_NAME));
	strcat((char*)outMsg,"\"name\":\"");
	strcat((char*)outMsg,PD_PRODUCT_NAME);
	strcat((char*)outMsg,"\"");
	strcat((char*)outMsg,MY_XJP_JSON_TOKEN);

//// quantity
DEBUGLOG(("FormatInitMsg:: quantity[DEFAULT] = [%s]\n",PD_PRODUCT_QUANTITY));
	strcat((char*)outMsg,"\"quantity\":\"");
	strcat((char*)outMsg,PD_PRODUCT_QUANTITY);
	strcat((char*)outMsg,"\"");
	strcat((char*)outMsg,MY_XJP_JSON_TOKEN);

//// amount
	if (dTmp > 0.0) {
DEBUGLOG(("FormatInitMsg:: amount = [%s]\n",csTmp));
		strcat((char*)outMsg,"\"amount\":\"");
		strcat((char*)outMsg,(char*)csTmp);
		strcat((char*)outMsg,"\"");
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** psp_txn_amt is missing\n"));
	}

// end of productDetails
	strcat((char*)outMsg,MY_XJP_JSON_END_TOKEN);
	strcat((char*)outMsg,MY_XJP_JSON_END_TOKEN_2);
	strcat((char*)outMsg,MY_XJP_JSON_TOKEN);

// start of payer
	strcat((char*)outMsg,"\"payer\":");
	strcat((char*)outMsg,MY_XJP_JSON_START_TOKEN);

// end of payer
	strcat((char*)outMsg,MY_XJP_JSON_END_TOKEN);
	strcat((char*)outMsg,MY_XJP_JSON_TOKEN);

// clientIp
	if (GetField_CString(hIn,"org_ip_addr",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: clientIp = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"clientIp\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
		strcat((char*)outMsg,MY_XJP_JSON_TOKEN);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** org_ip_addr is missing\n"));
	}

// hmac
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: hmac = [%s]\n",csPtr));
		strcat((char*)outMsg,"\"hmac\":\"");
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"\"");
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatInitMsg:: *** sign is missing\n"));
	}

	strcat((char*)outMsg,MY_XJP_JSON_END_TOKEN);

DEBUGLOG(("FormatInitMsg:: outmsg = [%s]\n",outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return 	iRet;
}



int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;

DEBUGLOG(("BreakDownInitRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	iRet = DEBlockXjpInitData(hOut, inMsg, inLen);

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

/* merchantId */
	strcpy(csTag, "merchantId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	} else {
		strcpy(csTag, "mid");
		if (GetField_CString(hIn, csTag, &csPtr)) {
			strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
		}
	}

/* requestId */
	strcpy(csTag, "requestId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	} else {
		strcpy(csTag, "txn_seq");
		if (GetField_CString(hIn, csTag, &csPtr)) {
			strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
		}
	}

/* serialNumber */
	strcpy(csTag, "tid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* totalRefundCount */
	strcpy(csTag, "totalRefundCount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* totalRefundAmount */
	strcpy(csTag, "totalRefundAmount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* orderCurrency */
	strcpy(csTag, "orderCurrency");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* orderAmount */
	strcpy(csTag, "txn_amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* status */
	strcpy(csTag, "status");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* completeDateTime */
	strcpy(csTag, "completeDateTime");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* remark */
	strcpy(csTag, "remark");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

/* redirectUrl */
	strcpy(csTag, "redirectUrl");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n", csTag, csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

