/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/02/12		   LokMan Chow
API Changed					   2018/04/03		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PsvMsg.h"
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


OBJPTR(DB);
OBJPTR(BO);
char cDebug;

#define MY_PSV_PRODUCT_NAME	"Testing"
#define MY_PSV_ACTION		"pay_online"
#define MY_PSV_SUCCESS_STATUS	1

struct key_value_pair
{
	char key[PD_TMP_BUF_LEN];
	char value[PD_TMP_MSG_BUF_LEN];
};


void PsvMsg(char cdebug)
{
	cDebug = cdebug;
}


char *str_replace(char *orig, char *rep, char *with);


int FormatMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int     iRet = PD_OK;
	char*   csPtr = NULL;
	char*   csBuf;
	char*   csMethod = NULL;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg,csPtr);

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
		strcat((char*)outMsg,MY_PSV_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
		strcat((char*)outMsg,MY_PSV_TOKEN);
		strcat((char*)outMsg,"ret_status=0");

DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));

		*outLen = strlen((const char*)outMsg);
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}

	FREE_ME(csBuf);
	return  iRet;

}


int BuildAuthData(hash_t *hIn)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	*csBuf;
	//double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

//Action
	strcat((char*)csBuf, "Action");
	strcat((char*)csBuf, MY_PSV_FIELD_TOKEN);
	strcat((char*)csBuf, MY_PSV_ACTION);
	strcat((char*)csBuf, MY_PSV_TOKEN);
	PutField_CString(hIn,"psv_Action",MY_PSV_ACTION);

//Domain
	strcat((char*)csBuf, "Domain");
	strcat((char*)csBuf, MY_PSV_FIELD_TOKEN);
	strcat((char*)csBuf, "store.armyltd.com");
	strcat((char*)csBuf, MY_PSV_TOKEN);
	PutField_CString(hIn,"psv_Domain","store.armyltd.com");


// OId 
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, "OId");
		strcat((char*)csBuf, MY_PSV_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_PSV_TOKEN);
DEBUGLOG(("OId = [%s]\n", csPtr));
	}
	else {
DEBUGLOG(("OId is missing\n"));
	}

//timestamp
	time_t now;
	time(&now);
	char csTime[PD_DATETIME_LEN];
	sprintf(csTime,"%ld",now);
	strcat((char*)csBuf, "timestamp");
	strcat((char*)csBuf, MY_PSV_FIELD_TOKEN);
	strcat((char*)csBuf, csTime);
	strcat((char*)csBuf, MY_PSV_TOKEN);
	PutField_CString(hIn,"psv_timestamp",csTime);


	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;

DEBUGLOG(("BreakDownMsg() Exit\n"));
	return iRet;
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
	char	csData[MAX_MSG_SIZE + 1];

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0] = '\0';

/* psp_url */
	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
DEBUGLOG(("psp_url = [%s]\n", csURL));
DEBUGLOG(("request_function = [%s]\n", csPtr));
			strcat((char*)csBuf, MY_PSV_FIELD_TOKEN);
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

	json_object *jobj = json_object_new_object();


	if (GetField_CString(hIn, "psv_Domain", &csPtr)) {
DEBUGLOG(("Domain = [%s]\n", csPtr));
		json_object_object_add(jobj, "Domain", json_object_new_string(csPtr));
	}

	if (GetField_CString(hIn, "psv_Action", &csPtr)) {
DEBUGLOG(("Action = [%s]\n", csPtr));
		json_object_object_add(jobj, "Action", json_object_new_string(csPtr));
	}

	if (GetField_CString(hIn, "psv_timestamp", &csPtr)) {
DEBUGLOG(("timestamp = [%s]\n", csPtr));
		json_object_object_add(jobj, "timestamp", json_object_new_string(csPtr));
	}

// ReturnUrl
	if (GetField_CString(hIn, "fe_url", &csPtr)) {
DEBUGLOG(("ReturnUrl = [%s]\n", csPtr));
		json_object_object_add(jobj, "ReturnUrl", json_object_new_string(csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***fe_url is missing\n"));
	}

// NotifyUrl
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("NotifyUrl = [%s]\n", csPtr));
		json_object_object_add(jobj, "NotifyUrl", json_object_new_string(csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***return_url_only is missing\n"));
	}


// Amount
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("Amount = [%s]\n", csTmpAmt));
		json_object_object_add(jobj, "Amount", json_object_new_string(csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***psp_txn_amt is missing\n"));
	}

// Name
DEBUGLOG(("Name = [%s]\n", MY_PSV_PRODUCT_NAME));
	json_object_object_add(jobj, "Name", json_object_new_string(MY_PSV_PRODUCT_NAME));

// OId
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("OId = [%s]\n", csPtr));
		json_object_object_add(jobj, "OId", json_object_new_string(csPtr));
	}
	else {  
		iRet = PD_ERR;
DEBUGLOG(("***order_num is missing\n"));
	}

// sign
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("sign = [%s]\n", csPtr));
		json_object_object_add(jobj, "sign", json_object_new_string(csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
	}

	strcpy((char*)csData, str_replace((char*)(json_object_to_json_string_ext(jobj, JSON_C_TO_STRING_PLAIN)), "\\/", "/"));
	strcat((char*)outMsg, csData);

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
	int	iReturnCode;
	char	csMsg[PD_MAX_BUFFER + 1];
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csMsg[0] = '\0';

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
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_PSV_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_PSV_TOKEN);
				break;
				case json_type_int:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_PSV_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%d", (char*)csMsg, json_object_get_int(val));
					strcat((char*)csMsg, MY_PSV_TOKEN);
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}
	}

DEBUGLOG(("response = [%s]\n", csMsg));

	if (Str2Cls(hRec, (char *)csMsg, MY_PSV_TOKEN, MY_PSV_FIELD_TOKEN) == PD_OK) {
// inMsg
		PutField_CString(hOut, "in_msg", (char *)csMsg);

		if (GetField_Int(hRec, "ret", &iReturnCode)) {
			// return_code
DEBUGLOG(("ret = [%d]\n", iReturnCode));

			PutField_Int(hOut, "ret", iReturnCode);
			if (iReturnCode == MY_PSV_SUCCESS_STATUS) {
				// url 
				if (GetField_CString(hRec, "url", &csPtr)) {
					PutField_CString(hOut, "redirect_url", csPtr);
DEBUGLOG(("msg:url = [%s]\n", csPtr));
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

	json_object_put(jobj);

	hash_destroy(hRec);
	FREE_ME(hRec);
DEBUGLOG(("BreakDownInitRspMsg() Exit\n"));
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

	free(csBuf);
	csBuf = NULL;
	return 0;
}


int string_sort_func(const void *a1, const void *b1)
{
	const char *a = (const char *)a1;
	const char *b = (const char *)b1;
	return(strcmp(a, b));
}


int BuildRspAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char	*csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	char *inMsg;
	int iTmp;

	struct key_value_pair k_v_pair[50];
	int iPairCnt = 0;

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (GetField_CString(hIn, "in_msg", &inMsg)) {
		if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_PSV_TOKEN, MY_PSV_FIELD_TOKEN) == PD_OK) {
			qsort(k_v_pair, iPairCnt, sizeof(struct key_value_pair), string_sort_func);
			for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
				// exclude sign
				if (strcmp(k_v_pair[iTmp].key, "sign")) {
					strcat(csBuf, k_v_pair[iTmp].key);
					strcat(csBuf, MY_PSV_FIELD_TOKEN);
					strcat(csBuf, k_v_pair[iTmp].value);
					strcat(csBuf, MY_PSV_TOKEN);
				}
			}
		}
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


char *str_replace(char *orig, char *rep, char *with) {
        char *result;   // the return string
        char *ins;      // the next insert point
        char *tmp;      // varies
        int len_rep;    // length of rep (the string to remove)
        int len_with;   // length of with (the string to replace rep with)
        int len_front;  // distance between rep and end of last rep
        int count;      // number of replacements

        if (!orig || !rep)
                return NULL;
        len_rep = strlen(rep);
        if (len_rep == 0)
                return NULL; // empty rep causes infinite loop during count
        if (!with)
                with = "";
        len_with = strlen(with);

        // count the number of replacements needed
        ins = orig;
        for (count = 0; (tmp = strstr(ins, rep)); ++count) {
                ins = tmp + len_rep;
        }

        tmp = result = malloc(strlen(orig) + (len_with - len_rep) * count + 1);

        if (!result)
                return NULL;

        // first time through the loop, all the variable are set correctly
        // from here on,
        //    tmp points to the end of the result string
        //    ins points to the next occurrence of rep in orig
        //    orig points to the remainder of orig after "end of rep"
        while (count--) {
                ins = strstr(orig, rep);
                len_front = ins - orig;
                tmp = strncpy(tmp, orig, len_front) + len_front;
                tmp = strcpy(tmp, with) + len_with;
                orig += len_front + len_rep; // move to next "end of rep"
        }
        strcpy(tmp, orig);
        return result;
}

