/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/07/14              David Wong
Support VNET                                       2018/01/26              David Wong
Support enquiry                                    2019/01/08              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "XjmMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#include <json-c/json.h>

static char	cDebug;
OBJPTR(DB);

void	XjmMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csTmp = NULL;
	char*   csPtr = NULL;
	char*   csBuf;
	double  dTmp;
	char*   csMethod = NULL;
	int	iOpt = PD_TRUE;
	int	iIsVnet = PD_FALSE;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char *)outMsg,csPtr);
		strcat((char *)outMsg,"?");

// p0_Cmd
		strcat((char*)outMsg,"p0_Cmd");
		strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg,PD_P0_CMD);
		strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p0_Cmd = [%s]\n",PD_P0_CMD));

// p1_MerId
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"p1_MerId");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p1_MerId = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

// p2_Order
		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"p2_Order");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p2_Order = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***txn_seq is missing\n"));
		}

// p3_Cur
		strcat((char*)outMsg,"p3_Cur");
		strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg,PD_CCY_ISO_CNY);
		strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p3_Cur = [%s]\n",PD_CCY_ISO_CNY));


// p4_Amt
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf(csTmpAmt,"%.2f",dTmp);
			strcat((char*)outMsg,"p4_Amt");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p4_Amt = [%s]\n",csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_txn_amt is missing!!!\n"));
		}

// p8_Url
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"p8_Url");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: p8_Url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

// pa_FrpId
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"pa_FrpId");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
			iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if(iOpt==PD_FALSE && iOpt!=INT_ERR){
				strcat((char*)outMsg,PD_PA_FRPID_VNET);
DEBUGLOG(("FormatMsg:: pa_FrpId = [%s]\n",PD_PA_FRPID_VNET));
				iIsVnet = PD_TRUE;
			} else if(iOpt && iOpt!=INT_ERR){
				strcat((char*)outMsg,PD_PA_FRPID_EC);
DEBUGLOG(("FormatMsg:: pa_FrpId = [%s]\n",PD_PA_FRPID_EC));
			}
			strcat((char*)outMsg,MY_XJM_TOKEN);
		}

// pg_BankCode
		if (iIsVnet) {
			if (GetField_CString(hIn,"bank_code",&csTmp)) {
				strcat((char*)outMsg,"pg_BankCode");
				strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
				strcat((char*)outMsg,csTmp);
				strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: pg_BankCode = [%s]\n",csTmp));
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** bank_code is missing\n"));
			}
		}

// pi_Url (same as p8_Url)
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"pi_Url");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: pi_Url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

// hmac
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"hmac");
			strcat((char*)outMsg,MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_XJM_TOKEN);
DEBUGLOG(("FormatMsg:: hmac = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***sign is missing\n"));
		}

// url_method
		if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
		}
		else 
			csMethod = strdup("");

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));
		base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: after encode\n"));
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
                strcat((char*)outMsg,MY_XJM_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_XJM_TOKEN);
		strcat((char*)outMsg,"ret_status=0");
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}


DEBUGLOG(("FormatMsg:: normal exit iret =[%d]\n",iRet));
	FREE_ME(csBuf);
	return 	iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t  *hRec;

	hRec = (hash_t*)  malloc (sizeof(hash_t));
	hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char *)inMsg,MY_XJM_TOKEN, MY_XJM_FIELD_TOKEN) == PD_OK) {
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
DEBUGLOG(("BreakDownMsg:: r0_Cmd:r0_Cmd = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r0_Cmd:r0_Cmd not found\n"));
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
DEBUGLOG(("BreakDownMsg:: r4_Cur:txn_ccy = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r4_Cur:txn_ccy not found\n"));
		}

/* r5_Pid */
		if (GetField_CString(hRec,"r5_Pid",&csPtr)) {
			PutField_CString(hOut,"r5_Pid",csPtr);
DEBUGLOG(("BreakDownMsg:: r5_Pid:r5_Pid = [%s]\n",csPtr));
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
DEBUGLOG(("BreakDownMsg:: r8_MP:r8_MP = [%s]\n",csPtr));
		}

/* r9_BType */
		if (GetField_CString(hRec,"r9_BType",&csPtr)) {
			PutField_CString(hOut,"r9_BType",csPtr);
DEBUGLOG(("BreakDownMsg:: r9_BType:r9_BType = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: r9_BType:r9_BType not found\n"));
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
	return	iRet;
}

int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}

int BuildAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr;
        char*   csBuf;
	double	dTmp;
	int	iOpt = PD_TRUE;
	int	iIsVnet = PD_FALSE;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
	int	iForEnquiry = PD_FALSE;
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_use", &iForEnquiry);
	if (iForEnquiry) {
		return BuildInqAuthData(hIn);
	}

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildCallbackAuthData(hIn);
	}

	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* p0_Cmd */
	strcat((char*)csBuf,PD_P0_CMD);
DEBUGLOG(("BuildAuthData:: p0_Cmd = [%s]\n", PD_P0_CMD));

/* p1_MerId */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: p1_MerId = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* p2_Order */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: p2_Order = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***txn_seq is missing\n"));
	}

/* p3_Cur */
	strcat((char*)csBuf,PD_CCY_ISO_CNY);
DEBUGLOG(("BuildAuthData:: p3_Cur = [%s]\n", PD_CCY_ISO_CNY));

/* p4_Amt */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf(csTmpAmt,"%.2f",dTmp);
		strcat((char*)csBuf,csTmpAmt);
DEBUGLOG(("BuildAuthData:: p4_Amt = [%s]\n",csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_txn_amt is missing\n"));
	}

/* p8_Url */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: p8_Url = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***return_url_only is missing\n"));
	}

/* pa_FrpId */
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
		iOpt = (unsigned long)(*DBObjPtr)(csPtr);
		if(iOpt==PD_FALSE && iOpt!=INT_ERR){
			strcat((char*)csBuf,PD_PA_FRPID_VNET);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n",PD_PA_FRPID_VNET));
			iIsVnet = PD_TRUE;
		} else if(iOpt && iOpt!=INT_ERR){
			strcat((char*)csBuf,PD_PA_FRPID_EC);
DEBUGLOG(("BuildAuthData:: pa_FrpId = [%s]\n",PD_PA_FRPID_EC));
		}
	}

/* pg_BankCode */
	if (iIsVnet) {
		if (GetField_CString(hIn,"bank_code",&csPtr)) {
			strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: pg_BankCode = [%s]\n",csPtr));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***bank_code is missing\n"));
		}
	}

/* pi_Url (same as p8_Url)*/
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: pi_Url = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***return_url_only is missing\n"));
	}

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}

int BuildRspAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr;
        char*   csBuf;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildRspAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildInqRspAuthData(hIn);
	}

	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';

// p1_MerId
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: p1_MerId:psp_merchant_id = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r0_Cmd
	if (GetField_CString(hIn,"r0_Cmd",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r0_Cmd:r0_Cmd = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r1_Code
	if (GetField_CString(hIn,"status",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r1_Code:status = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r2_TrxId
	if (GetField_CString(hIn,"tid",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r2_TrxId:tid = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r3_Amt
	if (GetField_CString(hIn,"psp_txn_amt",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r3_Amt:psp_txn_amt = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r4_Cur
	if (GetField_CString(hIn,"psp_txn_ccy",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r4_Cur:psp_txn_ccy = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r5_Pid
	if (GetField_CString(hIn,"r5_Pid",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r5_Pid:r5_Pid = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r6_Order
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r6_Order:txn_seq = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r8_MP
	if (GetField_CString(hIn,"r8_MP",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r8_MP:r8_MP = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// r9_BType
	if (GetField_CString(hIn,"r9_BType",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: r9_BType:r9_BType = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// ro_BankOrderId
	if (GetField_CString(hIn,"bank_bill_no",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: ro_BankOrderId:bank_bill_no = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

// rp_PayDate
	if (GetField_CString(hIn,"fundin_date",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: rp_PayDate:fundin_date = [%s]\n",csPtr));
		strcat((char*)csBuf,csPtr);
	}

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}


int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csBuf;
	char *csURL = NULL;
	char *csPtr = NULL;
	char *csTmp = NULL;

DEBUGLOG(("FormatInqMsg() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
			strcat((char*)csBuf, MY_XJM_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_XJM_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_XJM_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_XJM_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_XJM_FIELD_TOKEN);
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

		// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD_INQ));
		strcat((char*)outMsg, "p0_Cmd");
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, PD_P0_CMD_INQ);
		strcat((char*)outMsg, MY_XJM_TOKEN);

		// p1_MerId
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("p1_MerId = [%s]\n", csTmp));
			strcat((char*)outMsg, "p1_MerId");
			strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJM_TOKEN);
		}
		else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
			iRet = PD_ERR;
		}

		// p2_Order
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("p2_Order = [%s]\n", csTmp));
			strcat((char*)outMsg, "p2_Order");
			strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJM_TOKEN);
		}
		else {
DEBUGLOG(("***txn_seq is missing\n"));
			iRet = PD_ERR;
		}

		// hmac
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("hmac = [%s]\n", csTmp));
			strcat((char*)outMsg, "hmac");
			strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_XJM_TOKEN);
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
	int iRet = PD_OK;
	char *csBuf;
	char *csPtr;

DEBUGLOG(("BuildInqAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	// p0_Cmd
DEBUGLOG(("p0_Cmd = [%s]\n", PD_P0_CMD_INQ));
	strcat((char*)csBuf, PD_P0_CMD_INQ);

	// p1_MerId
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("p1_MerId = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}
	else {
DEBUGLOG(("psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

	// p2_Order
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("p2_Order = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}
	else {
DEBUGLOG(("txn_seq is missing\n"));
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
	char	*csPtr = NULL;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownInqRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	struct json_object *jobj;
	enum json_type type;

	jobj = json_tokener_parse((const char *)inMsg);
	if (jobj != NULL) {
		json_object_object_foreach(jobj, key, val) {
			type = json_object_get_type(val);
			switch (type) {
				case json_type_string:
					PutField_CString(hOut, key, json_object_get_string(val));
					break;
				default:
DEBUGLOG(("BreakDownInqRspMsg:: unsupported type\n"));
					break;
			}
		}

		// r3_Amt
		if (GetField_CString(hOut, "r3_Amt", &csPtr)) {
DEBUGLOG(("r3_Amt:txn_amt = [%s]\n", csPtr));
			PutField_CString(hOut, "txn_amt", csPtr);
		}
		else {
DEBUGLOG(("r3_Amt:txn_amt not found\n"));
		}

		// r6_Order
		if (GetField_CString(hOut, "r6_Order", &csPtr)) {
DEBUGLOG(("r6_Order:txn_seq = [%s]\n", csPtr));
			PutField_CString(hOut, "txn_seq", csPtr);
		}
		else {
DEBUGLOG(("r6_Order:txn_seq not found\n"));
		}

		// rb_PayStatus
		if (GetField_CString(hOut, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("rb_PayStatus:status = [%s]\n", csPtr));
			PutField_CString(hOut, "status", csPtr);
		}
		else {
DEBUGLOG(("rb_PayStatus:status not found\n"));
		}

		// hmac
		if (GetField_CString(hOut, "hmac", &csPtr)) {
DEBUGLOG(("hmac:sign = [%s]\n", csPtr));
			PutField_CString(hOut, "sign", csPtr);
		}
		else {
DEBUGLOG(("hmac:sign not found\n"));
		}
	} else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	json_object_put(jobj);

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("BreakDownInqRspMsg Exit\n"));
	return iRet;
}


int BuildInqRspAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	char	csTag[PD_TAG_LEN + 1];
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildInqRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	/* r0_Cmd */
	strcpy(csTag, "r0_Cmd");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* p1_MerId */
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r1_Code */
	strcpy(csTag, "r1_Code");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r2_TrxId */
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r3_Amt */
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r4_Cur */
	strcpy(csTag, "r4_Cur");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r6_Order */
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* r8_MP */
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rb_PayStatus */
	strcpy(csTag, "rb_PayStatus");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rd_RefundAmt */
	strcpy(csTag, "rd_RefundAmt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	/* rc_RefundCount */
	strcpy(csTag, "rc_RefundCount");
	if (GetField_CString(hIn, csTag, &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csBuf;
	char *csPtr;
	char csTag[PD_TAG_LEN + 1];

DEBUGLOG(("BuildCallbackAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	// p1_MerId
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r0_Cmd
DEBUGLOG(("r0_Cmd = [%s]\n", PD_P0_CMD));
	strcat((char*)csBuf, PD_P0_CMD);

	// r1_Code (rb_PayStatus)
	if (GetField_CString(hIn, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("r1_Code = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r2_TrxId
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r3_Amt
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r4_Cur
DEBUGLOG(("r4_Cur = [%s]\n", PD_R4_CUR));
	strcat((char*)csBuf, PD_R4_CUR);

	// r5_Pid
DEBUGLOG(("r5_Pid = [%s]\n", PD_P5_PID));
	strcat((char*)csBuf, PD_P5_PID);

	// r6_Order
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r8_MP
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)csBuf, csPtr);
	}

	// r9_BType
DEBUGLOG(("r9_BType = [%s]\n", PD_R9_BTYPE));
	strcat((char*)csBuf, PD_R9_BTYPE);

	// ro_BankOrderId

	// rp_PayDate

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildCallbackAuthData() auth_data = [%s]\n", csBuf));
DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;
	char csTag[PD_TAG_LEN + 1];

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	// p1_MerId
	strcpy(csTag, "p1_MerId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r0_Cmd
	strcpy(csTag, "r0_Cmd");
DEBUGLOG(("%s = [%s]\n", csTag, PD_P0_CMD));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P0_CMD);
	strcat((char*)outMsg, MY_XJM_TOKEN);

	// r1_Code
	strcpy(csTag, "r1_Code");
	if (GetField_CString(hIn, "rb_PayStatus", &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r2_TrxId
	strcpy(csTag, "r2_TrxId");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r3_Amt
	strcpy(csTag, "r3_Amt");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r4_Cur
	strcpy(csTag, "r4_Cur");
DEBUGLOG(("%s = [%s]\n", csTag, PD_R4_CUR));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
	strcat((char*)outMsg, PD_R4_CUR);
	strcat((char*)outMsg, MY_XJM_TOKEN);

	// r5_Pid
	strcpy(csTag, "r5_Pid");
DEBUGLOG(("%s = [%s]\n", csTag, PD_P5_PID));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
	strcat((char*)outMsg, PD_P5_PID);
	strcat((char*)outMsg, MY_XJM_TOKEN);

	// r6_Order
	strcpy(csTag, "r6_Order");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r8_MP
	strcpy(csTag, "r8_MP");
	if (GetField_CString(hIn, csTag, &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	// r9_BType
	strcpy(csTag, "r9_BType");
DEBUGLOG(("%s = [%s]\n", csTag, PD_R9_BTYPE));
	strcat((char*)outMsg, csTag);
	strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
	strcat((char*)outMsg, PD_R9_BTYPE);
	strcat((char*)outMsg, MY_XJM_TOKEN);

	// ro_BankOrderId

	// rp_PayDate

	// hmac
	strcpy(csTag, "hmac");
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("%s = [%s]\n", csTag, csPtr));
		strcat((char*)outMsg, csTag);
		strcat((char*)outMsg, MY_XJM_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_XJM_TOKEN);
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit\n"));
	FREE_ME(csPtr);
	return iRet;
}

