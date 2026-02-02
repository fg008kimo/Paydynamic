/*
PDProTech (c)2016. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/05/10              LokMan Chow
Add FormatInqMsg				   2018/08/15		   David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "NepMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"
#include <json-c/json.h>

static char	cDebug;

struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};

OBJPTR(BO);
OBJPTR(DB);

void	NepMsg(char cdebug)
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

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char *)outMsg,csPtr);
		strcat((char *)outMsg,"?");

/* version */
		strcat((char*)outMsg,"version");
		strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
		strcat((char*)outMsg,MY_NEP_VERSION);
		strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: version = [%s]\n",MY_NEP_VERSION));


/* business_id */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"business_id");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: business_id = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

/* order_id */
		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"order_id");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: order_id = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***txn_seq is missing\n"));
		}

/* amount */
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf(csTmpAmt,"%.2f",dTmp);
			//sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
			strcat((char*)outMsg,"amount");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: amount = [%s]\n",csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_txn_amt is missing!!!\n"));
		}

/* orderDetails */
		strcat((char*)outMsg,"orderDetails");
		strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
		strcat((char*)outMsg,PD_ORDER_DETAILS);
		strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: orderDetails = [%s]\n",PD_ORDER_DETAILS));

/* org_code */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
			iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if(iOpt==PD_FALSE && iOpt!=INT_ERR){
				strcat((char*)outMsg,"org_code");
				strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
				strcat((char*)outMsg,csTmp);
				strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: org_code = [%s]\n",csTmp));
			}
		}
/*
		strcat((char*)outMsg,"org_code");
		strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
		strcat((char*)outMsg,"TestBank");
		strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: org_code = [TestBank]\n"));
*/

/* sign */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"sign");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: sign = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***sign is missing\n"));
		}

/* return_url */
		if (GetField_CString(hIn,"fe_url",&csTmp)) {
			strcat((char*)outMsg,"return_url");
                        strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: return_url = [%s]\n",csTmp));
                }
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***fe_url is missing\n"));
		}

/* notice_url */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"notify_url");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: notice_url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

/* order_datetime */
		if (GetField_CString(hIn,"local_tm_date",&csTmp)) {
			char *csTmp2 = NULL;
			char csDateTime[PD_DATETIME_LEN * 2];
			if (GetField_CString(hIn,"local_tm_time",&csTmp2)) {
				sprintf(csDateTime,"%s%s",csTmp,csTmp2);
				strcat((char*)outMsg,"order_datetime");
				strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
				strcat((char*)outMsg,csDateTime);
				strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: order_datetime = [%s]\n",csDateTime));
			}
			else {
				iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** local_tm_time is missing\n"));
			}
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** local_tm_date is missing\n"));
		}

/* order_expire_datetime */
		if (GetField_CString(hIn,"psp_key_id",&csTmp)) {
			strcat((char*)outMsg,"order_expire_datetime");
			strcat((char*)outMsg,MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_NEP_TOKEN);
DEBUGLOG(("FormatMsg:: order_expire_datetime = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** psp_key_id is missing\n"));
		}

/* url_method */
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
                strcat((char*)outMsg,MY_NEP_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_NEP_TOKEN);
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

	if (Str2Cls(hRec,(char *)inMsg,MY_NEP_TOKEN, MY_NEP_FIELD_TOKEN) == PD_OK) {

/* order_id */
		if (GetField_CString(hRec,"order_id",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: order_id not found\n"));
		}

/* stateCode */
		if (GetField_CString(hRec,"stateCode",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: stateCode not found\n"));
		}

/* amount */
		if (GetField_CString(hRec,"amount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: amount not found\n"));
		}

/* order_no */
		if (GetField_CString(hRec,"order_no",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: order_no not found\n"));
		}

/* business_id */
		if (GetField_CString(hRec,"business_id",&csPtr)) {
			PutField_CString(hOut,"business_id",csPtr);
DEBUGLOG(("BreakDownMsg:: business_id = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: business_id not found\n"));
		}

/* sign */
                if (GetField_CString(hRec,"sign",&csPtr)) {
                        PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n",csPtr));
                }
                else{
DEBUGLOG(("BreakDownMsg:: sign not found\n"));
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
	//int	iOpt = PD_TRUE;
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
	

/* business_id */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,"business_id");
		strcat((char*)csBuf,MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_NEP_TOKEN);
DEBUGLOG(("BuildAuthData:: business_id = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* order_id */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"order_id");
		strcat((char*)csBuf,MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_NEP_TOKEN);
DEBUGLOG(("BuildAuthData:: order_id = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***txn_seq is missing\n"));
	}

/* amount */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf(csTmpAmt,"%.2f",dTmp);
		//sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
		
		strcat((char*)csBuf,"amount");
		strcat((char*)csBuf,MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf,csTmpAmt);
		strcat((char*)csBuf,MY_NEP_TOKEN);
DEBUGLOG(("BuildAuthData:: amount = [%s]\n",csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_txn_amt is missing!!!\n"));
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
	char	csTag[PD_TAG_LEN +1];
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildRspAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildInqRspAuthData(hIn);
	}

	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';

/* order_id */
	strcpy(csTag,"txn_seq");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* stateCode */
	strcpy(csTag,"status");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* amount */
	strcpy(csTag,"txn_amt");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* order_no */
	strcpy(csTag,"tid");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* business_id */
	strcpy(csTag,"business_id");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
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
			strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);
		}

		sprintf((char*)outMsg, "%0*d", PD_WEB_HEADER_LEN_LEN, (int)strlen(csBuf));
		strcat((char*)outMsg, csBuf);
DEBUGLOG(("outMsg = [%s]\n", outMsg));

		// business_id
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
DEBUGLOG(("business_id = [%s]\n", csTmp));
			strcat((char*)outMsg, "business_id");
			strcat((char*)outMsg, MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEP_TOKEN);
		}
		else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
			iRet = PD_ERR;
		}

		// order_id
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("order_id = [%s]\n", csTmp));
			strcat((char*)outMsg, "order_id");
			strcat((char*)outMsg, MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEP_TOKEN);
		}
		else {
DEBUGLOG(("***txn_seq is missing\n"));
			iRet = PD_ERR;
		}

		// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("sign = [%s]\n", csTmp));
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_NEP_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEP_TOKEN);
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

	// business_id
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("business_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "business_id");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
	}
	else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

	// order_id
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("order_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_id");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
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
	char	*csPtr;
	char	csMsg[PD_MAX_BUFFER + 1];
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

DEBUGLOG(("BreakDownInqRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));
	PutField_CString(hOut, "fail_reason", (char *)inMsg);

	struct json_object *jobj;
	enum json_type type;

	jobj = json_tokener_parse((const char *)inMsg);
	if (jobj != NULL) {
		json_object_object_foreach(jobj, key, val) {
			type = json_object_get_type(val);
			switch (type) {
				case json_type_string:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_NEP_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_NEP_TOKEN);
				break;
				case json_type_int:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_NEP_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%d", (char*)csMsg, json_object_get_int(val));
					strcat((char*)csMsg, MY_NEP_TOKEN);
				break;
				case json_type_double:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_NEP_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%.2f", (char*)csMsg, json_object_get_double(val));
					strcat((char*)csMsg, MY_NEP_TOKEN);
				break;
				default:
DEBUGLOG(("BreakDownInqRspMsg:: unsupported type\n"));
				break;
			}
		}
	}

	if (Str2Cls(hRec, (char *)csMsg, MY_NEP_TOKEN, MY_NEP_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "orig_msg", (char *)csMsg);

// business_id
		if (GetField_CString(hRec, "business_id", &csPtr)) {
			PutField_CString(hOut, "business_id", csPtr);
DEBUGLOG(("business_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("business_id not found\n"));
		}

// order_id
		if (GetField_CString(hRec, "order_id", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("order_id:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("order_id:txn_seq not found\n"));
		}

// stateCode
		if (GetField_CString(hRec, "stateCode", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("stateCode:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("stateCode:status not found\n"));
		}

// amount
		if (GetField_CString(hRec, "amount", &csPtr)) {
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("amount:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("amount:txn_amt not found\n"));
		}

// sign
		if (GetField_CString(hRec, "sign", &csPtr)) {
			char csBuf[PD_TMP_MSG_BUF_LEN];
			U2L(csPtr, strlen(csPtr), csBuf);
			PutField_CString(hOut, "sign", csBuf);
DEBUGLOG(("sign = [%s]\n", csBuf));
		}
		else {
DEBUGLOG(("sign not found\n"));
		}
	}
	else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
		iRet = PD_ERR;
	}

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
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildInqRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// business_id
	if (GetField_CString(hIn, "business_id", &csPtr)) {
DEBUGLOG(("business_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "business_id");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
	}

// order_id
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("txn_seq:order_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_id");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
	}

// stateCode
	if (GetField_CString(hIn, "status", &csPtr)) {
DEBUGLOG(("status:stateCode = [%s]\n", csPtr));
		strcat((char*)csBuf, "stateCode");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
	}

// amount
	if (GetField_CString(hIn, "txn_amt", &csPtr)) {
DEBUGLOG(("psp_txn_amt:amount = [%s]\n", csPtr));
		strcat((char*)csBuf, "amount");
		strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEP_TOKEN);
	}

// sign tag
	strcat((char*)csBuf, "key");
	strcat((char*)csBuf, MY_NEP_FIELD_TOKEN);

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildInqRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;

DEBUGLOG(("BuildCallbackAuthData() Start\n"));

	RemoveField_Int(hIn, "for_enquiry_rsp_use");
DEBUGLOG(("BuildCallbackAuthData() call BuildRspAuthData()\n"));
	iRet = BuildRspAuthData(hIn);
	PutField_Int(hIn, "for_enquiry_rsp_use", PD_TRUE);

DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


void Insert2KVPair(struct key_value_pair k_v_pair[], int *iPairCnt, const char *inMsg, const char *FD)
{
	char *csTag;
	char *csValue;
	char *csTmp;
	char *p;

	csTmp = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
	strcpy(csTmp, inMsg);

	p = strstr(csTmp, FD);
	if (p) {
		if (strlen(p) > strlen(FD)) {
			csTag = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
			csValue = strdup(p + 1);
			memcpy(csTag, inMsg, strlen(inMsg) - strlen(p));
			csTag[strlen(inMsg) - strlen(p)] = '\0';
//DEBUGLOG(("Insert2KVPair:: iPairCnt = [%d], Tag = [%s], Value = [%s]\n", *iPairCnt, csTag, csValue));
			strcpy(k_v_pair[*iPairCnt].key, csTag);
			strcpy(k_v_pair[*iPairCnt].value, csValue);
			*iPairCnt = *iPairCnt + 1;
			free(csTag);
			csTag = NULL;
			free(csValue);
			csValue = NULL;
		}
	}
	free(csTmp);
	csTmp = NULL;
}


int Str2KVPair(struct key_value_pair k_v_pair[], int *iPairCnt, const char *inMsg, const char *DL, const char *FD)
{
	char *csBuf;
	char *p;

	int inLen = strlen(inMsg);
	csBuf = (char*) malloc (inLen + 1);
	memcpy(csBuf, inMsg, inLen);
	csBuf[inLen] = '\0';

	p = strtok(csBuf, DL);
	if (p != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d)
				p[strlen(p) - 1] = '\0';
			else
				p[strlen(p)] = '\0';
			Insert2KVPair(k_v_pair, iPairCnt, p, FD);
		}
	}

	while ((p = strtok(NULL, DL)) != NULL) {
		if (strlen(p) > 1) {
			if (p[strlen(p) - 1] == 0x0d)
				p[strlen(p) - 1] = '\0';
			else
				p[strlen(p)] = '\0';
			Insert2KVPair(k_v_pair, iPairCnt, p, FD);
		}
	}

//DEBUGLOG(("Str2KVPair:: iPairCnt = [%d]\n", *iPairCnt));

	free(csBuf);
	csBuf = NULL;
	return 0;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	GetField_CString(hIn, "orig_msg", &inMsg);
	if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_NEP_TOKEN, MY_NEP_FIELD_TOKEN) == PD_OK) {
		for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
			// exclude sign
			if (strcmp(k_v_pair[iTmp].key, "sign")) {
				strcat((char*)outMsg, k_v_pair[iTmp].key);
				strcat((char*)outMsg, MY_NEP_FIELD_TOKEN);
				strcat((char*)outMsg, k_v_pair[iTmp].value);
				strcat((char*)outMsg, MY_NEP_TOKEN);
			}
		}
	}

// signature has to be regenerated due to the originial GeneratePspSign flow read the NEP channel code and add "key="
	RemoveField_CString(hIn, "sign");
	GetField_CString(hContext, "psp_channel_code", &csPtr);
	PutField_CString(hContext, "psp_channel_code", "dummy");

	BOObjPtr = CreateObj(BOPtr, "BOSecurity", "GenerateMD5Sign");
	if ((*BOObjPtr)(hContext, hIn) == PD_OK) {
DEBUGLOG(("call BOSecurity:GenerateMD5Sign OK\n"));
	}
	else{
DEBUGLOG(("call BOSecurity:GenerateMD5Sign FAILED\n"));
	}

	PutField_CString(hContext, "psp_channel_code", csPtr);

	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_NEP_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
DEBUGLOG(("sign:sign = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("sign:sign not found\n"));
	}	

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit iRet = [%d]\n", iRet));
	return iRet;
}

