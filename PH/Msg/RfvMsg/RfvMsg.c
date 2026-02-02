/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/03/28              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "RfvMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#define __USE_XOPEN
#include <time.h>

char cDebug;

OBJPTR(DB);

void RfvMsg(char cdebug)
{
	cDebug = cdebug;
}


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csTmp = NULL;
	char	*csPtr = NULL;
	char	*csBuf;
	double	dTmp;
	char	*csMethod = NULL;
	int	iOpt = PD_TRUE;
	int	iIsVnet = PD_FALSE;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	memset(outMsg, 0, sizeof(outMsg));
	if (GetField_CString(hIn, "redirect_url", &csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "?");

// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD));
		strcat((char*)outMsg, "p0_Cmd");
		strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
		strcat((char*)outMsg, PD_P0_CMD);
		strcat((char*)outMsg, MY_RFV_TOKEN);

// p1_MerId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("p1_MerId = [%s]\n", csTmp));
			strcat((char*)outMsg, "p1_MerId");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

// p2_Order
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("p2_Order = [%s]\n", csTmp));
			strcat((char*)outMsg, "p2_Order");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_seq is missing\n"));
		}

// p3_Cur
DEBUGLOG(("p3_Cur = [%s]\n", PD_CCY_ISO_CNY));
		strcat((char*)outMsg, "p3_Cur");
		strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
		strcat((char*)outMsg, PD_CCY_ISO_CNY);
		strcat((char*)outMsg, MY_RFV_TOKEN);

// p4_Amt
		if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
DEBUGLOG(("psp_txn_amt = [%f]\n", dTmp));
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf(csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("p4_Amt = [%s]\n", csTmpAmt));
			strcat((char*)outMsg, "p4_Amt");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
		}

// p5_Pid
DEBUGLOG(("p5_Pid = [%s]\n", PD_P5_PID));
		strcat((char*)outMsg, "p5_Pid");
		strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
		strcat((char*)outMsg, PD_P5_PID);
		strcat((char*)outMsg, MY_RFV_TOKEN);

// p8_Url
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
DEBUGLOG(("p8_Url = [%s]\n", csTmp));
			strcat((char*)outMsg, "p8_Url");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
		}

// pa_FrpId
		if (GetField_CString(hIn, "bank_code", &csTmp)) {
			strcat((char*)outMsg, "pa_FrpId");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr, "DBMobBankMap", "IsMobileOption");
			iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if (iOpt == PD_FALSE && iOpt != INT_ERR) {
DEBUGLOG(("pa_FrpId = [%s]\n", PD_PA_FRPID_VNET));
				strcat((char*)outMsg, PD_PA_FRPID_VNET);
				iIsVnet = PD_TRUE;
			} else if (iOpt && iOpt != INT_ERR) {
DEBUGLOG(("pa_FrpId = [%s]\n", PD_PA_FRPID_EC));
				strcat((char*)outMsg, PD_PA_FRPID_EC);
			}
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}

// pg_BankCode
		if (iIsVnet) {
			if (GetField_CString(hIn, "bank_code", &csTmp)) {
DEBUGLOG(("pg_BankCode = [%s]\n", csTmp));
				strcat((char*)outMsg, "pg_BankCode");
				strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
				strcat((char*)outMsg, csTmp);
				strcat((char*)outMsg, MY_RFV_TOKEN);
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("***bank_code is missing\n"));
			}
		}

// pi_Url
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
DEBUGLOG(("pi_Url = [%s]\n", csTmp));
			strcat((char*)outMsg, "pi_Url");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
		}

// hmac
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("hmac = [%s]\n", csTmp));
			strcat((char*)outMsg, "hmac");
			strcat((char*)outMsg, MY_RFV_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			//strcat((char*)outMsg, MY_RFV_TOKEN);
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***hmac is missing\n"));
		}


// url_method
		if (GetField_CString(hIn, "url_method", &csMethod)) {
DEBUGLOG(("url_method = [%s]\n", csMethod));
		}
		else
			csMethod = strdup("");

DEBUGLOG(("outmsg = [%s]\n", outMsg));
		base64_encode(outMsg, strlen((char*)outMsg), csBuf, PD_MAX_BUFFER);
DEBUGLOG(("after encode\n"));
		outMsg[0] = '\0';
		strcat((char*)outMsg, "redirect_url");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csBuf);
		strcat((char*)outMsg, MY_RFV_TOKEN);
		strcat((char*)outMsg, "url_method");
		strcat((char*)outMsg, "=");
		strcat((char*)outMsg, csMethod);
		strcat((char*)outMsg, MY_RFV_TOKEN);
		strcat((char*)outMsg, "ret_status=0");
DEBUGLOG(("outMsg = [%s]\n", outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***redirect_url is missing\n"));
	}

DEBUGLOG(("FormatMsg:: normal exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
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

	if (Str2Cls(hRec, (char *)inMsg, MY_RFV_TOKEN, MY_RFV_FIELD_TOKEN) == PD_OK) {
// p1_MerId
		if (GetField_CString(hRec, "p1_MerId", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("p1_MerId:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("p1_MerId:psp_merchant_id not found\n"));
		}

// r0_Cmd
		if (GetField_CString(hRec, "r0_Cmd", &csPtr)) {
			PutField_CString(hOut, "r0_Cmd", csPtr);
DEBUGLOG(("r0_Cmd = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r0_Cmd not found\n"));
		}

// r1_Code
		if (GetField_CString(hRec, "r1_Code", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("r1_Code:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r1_Code:status not found\n"));
		}

// r2_TrxId
		if (GetField_CString(hRec, "r2_TrxId", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("r2_TrxId:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r2_TrxId:tid not found\n"));
		}

// r3_Amt
		if (GetField_CString(hRec, "r3_Amt", &csPtr)) {
			PutField_CString(hOut, "psp_txn_amt", csPtr);
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("r3_Amt:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r3_Amt:txn_amt not found\n"));
		}

// r4_Cur
		if (GetField_CString(hRec, "r4_Cur", &csPtr)) {
			PutField_CString(hOut, "psp_txn_ccy", csPtr);
DEBUGLOG(("r4_Cur:psp_txn_ccy = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r4_Cur:psp_txn_ccy not found\n"));
		}

// r5_Pid
		if (GetField_CString(hRec, "r5_Pid", &csPtr)) {
			PutField_CString(hOut, "r5_Pid", csPtr);
DEBUGLOG(("r5_Pid = [%s]\n", csPtr));
		}

// r6_Order
		if (GetField_CString(hRec, "r6_Order", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("r6_Order:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r6_Order:txn_seq not found\n"));
		}

// r8_MP
		if (GetField_CString(hRec, "r8_MP", &csPtr)) {
			PutField_CString(hOut, "r8_MP", csPtr);
DEBUGLOG(("r8_MP = [%s]\n", csPtr));
		}

// r9_BType
		if (GetField_CString(hRec, "r9_BType", &csPtr)) {
			PutField_CString(hOut, "r9_BType", csPtr);
DEBUGLOG(("r9_BType = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("r9_BType not found\n"));
		}

// ro_BankOrderId
		if (GetField_CString(hRec, "ro_BankOrderId", &csPtr)) {
			PutField_CString(hOut, "ro_BankOrderId", csPtr);
DEBUGLOG(("ro_BankOrderId = [%s]\n", csPtr));
		}

// rp_PayDate
		if (GetField_CString(hRec, "rp_PayDate", &csPtr)) {
			PutField_CString(hOut, "rp_PayDate", csPtr);
DEBUGLOG(("rp_PayDate = [%s]\n", csPtr));
		}

// hmac
		if (GetField_CString(hRec, "hmac", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("hmac:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("hmac:sign = [%s]\n", " "));
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


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr, *csBuf;
	char	csTmpAmt[PD_TMP_BUF_LEN + 1];
	double	dTmp;
	int	iOpt = PD_TRUE;
	int	iIsVnet = PD_FALSE;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD));
	strcat((char*)csBuf, PD_P0_CMD);

// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	} else {
DEBUGLOG(("psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

// p2_Order
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("p2_Order = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	} else {
DEBUGLOG(("txn_seq is missing\n"));
		iRet = PD_ERR;
	}

// p3_Cur
DEBUGLOG(("p3_Cur = [%s]\n", PD_CCY_ISO_CNY));
	strcat((char*)csBuf, PD_CCY_ISO_CNY);

// p4_Amt
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
DEBUGLOG(("psp_txn_amt = [%f]\n", dTmp));
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("p4_Amt = [%s]\n", csTmpAmt));
		strcat((char*)csBuf, (char*)csTmpAmt);
	} else {
DEBUGLOG(("psp_txn_amt is missing\n"));
		iRet = PD_ERR;
	}

// p5_Pid
DEBUGLOG(("p5_Pid = [%s]\n", PD_P5_PID));
	strcat((char*)csBuf, PD_P5_PID);

// p8_Url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("p8_Url = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	} else {
DEBUGLOG(("return_url_only is missing\n"));
		iRet = PD_ERR;
	}

// pa_FrpId
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		DBObjPtr = CreateObj(DBPtr, "DBMobBankMap", "IsMobileOption");
		iOpt = (unsigned long)(*DBObjPtr)(csPtr);
		if (iOpt == PD_FALSE && iOpt != INT_ERR) {
DEBUGLOG(("pa_FrpId = [%s]\n", PD_PA_FRPID_VNET));
			strcat((char*)csBuf, PD_PA_FRPID_VNET);
			iIsVnet = PD_TRUE;
		} else if (iOpt && iOpt != INT_ERR) {
DEBUGLOG(("pa_FrpId = [%s]\n", PD_PA_FRPID_EC));
			strcat((char*)csBuf, PD_PA_FRPID_EC);
		}
	}

// pg_BankCode
	if (iIsVnet) {
		if (GetField_CString(hIn, "bank_code", &csPtr)) {
DEBUGLOG(("pg_BankCode = [%s]\n", csPtr));
			strcat((char*)csBuf, csPtr);
		} else {
DEBUGLOG(("bank_code is missing\n"));
			iRet = PD_ERR;
		}
	}

// pi_Url
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
DEBUGLOG(("pi_Url = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	} else {
DEBUGLOG(("fe_url is missing\n"));
		iRet = PD_ERR;
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildRspAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csPtr;
	char *csBuf;
	char csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// p1_MerId
	strcpy(csTag, "psp_merchant_id");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r0_Cmd
	strcpy(csTag, "r0_Cmd");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r1_Code
	strcpy(csTag, "status");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r2_TrxId
	strcpy(csTag, "tid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r3_Amt
	strcpy(csTag, "psp_txn_amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r4_Cur
	strcpy(csTag, "psp_txn_ccy");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r5_Pid
	strcpy(csTag, "r5_Pid");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r6_Order
	strcpy(csTag, "txn_seq");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r8_MP
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// r9_BType
	strcpy(csTag, "r9_BType");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// ro_BankOrderId
	strcpy(csTag, "ro_BankOrderId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

// rp_PayDate
	strcpy(csTag, "rp_PayDate");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}

