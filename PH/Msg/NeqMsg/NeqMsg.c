
/*
 * PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PDProTech.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                      2019/03/26              David Wong
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "NeqMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include <time.h>
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

void	NeqMsg(char cdebug)
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
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));


		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
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
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_NEQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_NEQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_NEQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_NEQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_NEQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
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


int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t	*hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

        if (Str2Cls(hRec,(char*)inMsg,MY_NEQ_TOKEN,MY_NEQ_FIELD_TOKEN) == PD_OK) {
//inMsg
			PutField_CString(hOut,"in_msg",(char*)inMsg);

//order_id
			if (GetField_CString(hRec,"order_id",&csPtr)) {
				PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
			}

//stateCode
			if (GetField_CString(hRec,"stateCode",&csPtr)) {
				PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: status not found\n"));
			}

//amount
			if (GetField_CString(hRec,"amount",&csPtr)) {
				PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
			}

//order_no
			if (GetField_CString(hRec,"order_no",&csPtr)) {
				PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
			}

//business_id
			if (GetField_CString(hRec,"business_id",&csPtr)) {
				PutField_CString(hOut,"business_id",csPtr);
DEBUGLOG(("BreakDownMsg:: business_id = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: business_id not found\n"));
			}

//sign
			if (GetField_CString(hRec,"sign",&csPtr)) {
				PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n",csPtr));
			} else {
DEBUGLOG(("BreakDownMsg:: sign not found\n"));
			}

			PutField_Int(hOut,"isInitRsp",PD_FALSE);

	} else {
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

	char	*csTmp = NULL;
DEBUGLOG(("initReplyFromRequest()\n"));
	

/* order_num */
        if (GetField_CString(hRequest,"merchant_ref",&csTmp)) {
DEBUGLOG(("initReplyFromRequest: order_num = [%s]\n",csTmp));
                PutField_CString(hResponse,"order_num",csTmp);
        }


DEBUGLOG(("initReplyFromRequest() Exit\n"));
	FREE_ME(csTmp);
	return iRet;
}


int BuildAuthData(hash_t* hIn)
{
	int	iRet = PD_OK;
	char*	csPtr,*csDATA;
	char*	csBuf;
	double	dTmp;
	csDATA = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
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

	memset(csDATA,0,sizeof(csDATA));

//business_id
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("BuildAuthData:: business_id = [%s]\n",csPtr));
		strcpy(csDATA,"business_id");
		strcat(csDATA,MY_NEQ_FIELD_TOKEN);
		strcat(csDATA,csPtr);
		strcat(csDATA,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: business_id is missing\n"));
	}

//order_id
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("BuildAuthData:: order_id = [%s]\n",csPtr));
		strcat(csDATA,"order_id");
		strcat(csDATA,MY_NEQ_FIELD_TOKEN);
		strcat(csDATA,csPtr);
		strcat(csDATA,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: order_id is missing\n"));
	}

//amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("BuildAuthData:: amount = [%s]\n",csTmpAmt));
		strcat(csDATA,"amount");
		strcat(csDATA,MY_NEQ_FIELD_TOKEN);
		strcat(csDATA,csTmpAmt);
		strcat(csDATA,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: amount is missing\n"));
	}

	PutField_CString(hIn,"auth_data",csDATA);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n",csDATA));
	FREE_ME(csDATA);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n",iRet));
	return iRet;
}


int BuildRspAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr,*csDATA;
        csDATA = (char*) malloc (PD_TMP_MSG_BUF_LEN  +1);
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildRspAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);
	if (iForEnquiryRsp) {
		return BuildInqRspAuthData(hIn);
	}

        memset(csDATA,0,sizeof(csDATA));

//return_code
	if (GetField_CString(hIn,"return_code",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: return_code = [%s]\n",csPtr));
		//business_id
		if (GetField_CString(hIn,"business_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: business_id = [%s]\n",csPtr));
			strcat(csDATA,"business_id");
			strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NEQ_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: business_id is missing\n"));
		}

		//order_id
		if (GetField_CString(hIn,"order_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_id = [%s]\n",csPtr));
			strcat(csDATA,"order_id");
			strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NEQ_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_id is missing\n"));
		}

		//amount
		if (GetField_CString(hIn,"amount",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: amount = [%s]\n",csPtr));
			strcat(csDATA,"amount");
			strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NEQ_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: amount is missing\n"));
		}

		//trans_no
		if (GetField_CString(hIn,"trans_no",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: trans_no = [%s]\n",csPtr));
			strcat(csDATA,"trans_no");
			strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NEQ_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: trans_no is missing\n"));
		}
	} else {
		//order_id
		if (GetField_CString(hIn,"txn_seq",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_id = [%s]\n",csPtr));
			//strcat(csDATA,"order_id");
			//strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NEQ_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_id is missing\n"));
		}

		//stateCode
		if (GetField_CString(hIn,"status",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: stateCode = [%s]\n",csPtr));
			//strcat(csDATA,"stateCode");
			//strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NEQ_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: stateCode is missing\n"));
		}

		//amount
		if (GetField_CString(hIn,"txn_amt",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: amount = [%s]\n",csPtr));
			//strcat(csDATA,"amount");
			//strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NEQ_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: amount is missing\n"));
		}

		//order_no
		if (GetField_CString(hIn,"tid",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_no = [%s]\n",csPtr));
			//strcat(csDATA,"order_no");
			//strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NEQ_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_no is missing\n"));
		}

		//business_id
		if (GetField_CString(hIn,"business_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: business_id = [%s]\n",csPtr));
			//strcat(csDATA,"business_id");
			//strcat(csDATA,MY_NEQ_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NEQ_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: business_id is missing\n"));
		}
	}

	PutField_CString(hIn,"auth_data",csDATA);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csDATA));
	FREE_ME(csDATA);
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
	return iRet;
}


int FormatInitMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;

	char*	csPtr = NULL;
	char*	csURL = NULL;
	char*	csBuf;
	double	dTmp;
	int	iTmp;

DEBUGLOG(("FormatInitMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

	outMsg[0]= '\0';
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csURL));
DEBUGLOG(("FormatInitMsg:: request function = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_NEQ_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
			//strcat((char*)csBuf,"?");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csBuf));
		}

		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatInitMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
		//strcat((char*)outMsg,MY_NEQ_URL_END_TOKEN);
	}
	FREE_ME(csBuf);

//version
	if (GetField_CString(hIn,"version",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: version = [%s]\n",csPtr));
		strcat((char*)outMsg,"version");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: version is missing\n"));
	}

//business_id
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: business_id = [%s]\n",csPtr));
		strcat((char*)outMsg,"business_id");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: business_id is missing\n"));
	}

//order_id
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: order_id = [%s]\n",csPtr));
		strcat((char*)outMsg,"order_id");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: order_id is missing\n"));
	}

//amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("FormatInitMsg:: amount = [%s]\n",csTmpAmt));
		strcat((char*)outMsg,"amount");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csTmpAmt);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: amount is missing\n"));
	}

//sign
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: sign = [%s]\n",csPtr));
		strcat((char*)outMsg,"sign");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: sign is missing\n"));
	}

//notify_url
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: notify_url = [%s]\n",csPtr));
		strcat((char*)outMsg,"notify_url");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: notify_url is missing\n"));
	}

//validtime
	if (GetField_Int(hIn,"time_expire",&iTmp)) {
		char csTimeExpire[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTimeExpire,"%d",iTmp/60);
DEBUGLOG(("FormatInitMsg:: validtime = [%s]\n",csTimeExpire));
		strcat((char*)outMsg,"validtime");
		strcat((char*)outMsg,MY_NEQ_FIELD_TOKEN);
		strcat((char*)outMsg,csTimeExpire);
		//strcat((char*)outMsg,MY_NEQ_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: validtime is missing\n"));
	}

DEBUGLOG(("outmsg = [%s]\n",outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return 	iRet;
}


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int     iRet = PD_OK;
	char    *csPtr = NULL;
	char    *csReturnCode = NULL;
	hash_t  *hRec;

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

		//determine which return message it is
		if (GetField_CString(hRec,"return_code",&csReturnCode)) {
//code_url return message
			//return_code
			PutField_CString(hOut,"return_code",csReturnCode);
DEBUGLOG(("BreakDownInitRspMsg:: return_code = [%s]\n",csReturnCode));

			//return_msg
			if (GetField_CString(hRec,"retmsg",&csPtr)) {
				PutField_CString(hOut,"return_msg",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: return_msg = [%s]\n",csPtr));
			}

			if (!strcmp(csReturnCode,PD_SUCCESS_STATUS)) {
				//business_id
				if (GetField_CString(hRec,"business_id",&csPtr)) {
					PutField_CString(hOut,"business_id",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: business_id = [%s]\n",csPtr));
				}

				//order_id
				if (GetField_CString(hRec,"order_id",&csPtr)) {
					PutField_CString(hOut,"order_id",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: order_id = [%s]\n",csPtr));
				}

				//amount
				if (GetField_CString(hRec,"amount",&csPtr)) {
					PutField_CString(hOut,"amount",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: amount = [%s]\n",csPtr));
				}

				//trans_no
				if (GetField_CString(hRec,"trans_no",&csPtr)) {
					PutField_CString(hOut,"trans_no",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: trans_no = [%s]\n",csPtr));
				}

				//code
				if (GetField_CString(hRec,"code",&csPtr)) {
					PutField_CString(hOut,"code_url",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: code = [%s]\n",csPtr));
				}

				//sign
				if (GetField_CString(hRec,"sign",&csPtr)) {
					PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownInitRspMsg:: sign = [%s]\n",csPtr));
				}

				PutField_Int(hOut,"isInitRsp",PD_TRUE);
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
			strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
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
			strcat((char*)outMsg, MY_NEQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEQ_TOKEN);
		}
		else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
			iRet = PD_ERR;
		}

		// order_id
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
DEBUGLOG(("order_id = [%s]\n", csTmp));
			strcat((char*)outMsg, "order_id");
			strcat((char*)outMsg, MY_NEQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEQ_TOKEN);
		}
		else {
DEBUGLOG(("***txn_seq is missing\n"));
			iRet = PD_ERR;
		}

		// sign
		if (GetField_CString(hIn, "sign", &csTmp)) {
DEBUGLOG(("sign = [%s]\n", csTmp));
			strcat((char*)outMsg, "sign");
			strcat((char*)outMsg, MY_NEQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_NEQ_TOKEN);
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
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
	}
	else {
DEBUGLOG(("***psp_merchant_id is missing\n"));
		iRet = PD_ERR;
	}

	// order_id
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("order_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_id");
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
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
	int     iRet = PD_OK;
	char    *csPtr;
	char    csMsg[PD_MAX_BUFFER + 1];
	hash_t  *hRec;

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
					strcat((char*)csMsg, MY_NEQ_FIELD_TOKEN);
					strcat((char*)csMsg, json_object_get_string(val));
					strcat((char*)csMsg, MY_NEQ_TOKEN);
				break;
				case json_type_int:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_NEQ_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%d", (char*)csMsg, json_object_get_int(val));
					strcat((char*)csMsg, MY_NEQ_TOKEN);
				break;
				case json_type_double:
					strcat((char*)csMsg, key);
					strcat((char*)csMsg, MY_NEQ_FIELD_TOKEN);
					sprintf((char*)csMsg, "%s%.2f", (char*)csMsg, json_object_get_double(val));
					strcat((char*)csMsg, MY_NEQ_TOKEN);
				break;
				default:
DEBUGLOG(("BreakDownInqRspMsg:: unsupported type\n"));
				break;
			}
		}
	}

	if (Str2Cls(hRec, (char *)csMsg, MY_NEQ_TOKEN, MY_NEQ_FIELD_TOKEN) == PD_OK) {
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
	int     iRet = PD_OK;
	char    *csPtr;
	char    *csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildInqRspAuthData()\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// business_id
	if (GetField_CString(hIn, "business_id", &csPtr)) {
DEBUGLOG(("business_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "business_id");
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
	}

// order_id
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("txn_seq:order_id = [%s]\n", csPtr));
		strcat((char*)csBuf, "order_id");
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
	}

// stateCode
	if (GetField_CString(hIn, "status", &csPtr)) {
DEBUGLOG(("status:stateCode = [%s]\n", csPtr));
		strcat((char*)csBuf, "stateCode");
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
	}

// amount
	if (GetField_CString(hIn, "txn_amt", &csPtr)) {
DEBUGLOG(("psp_txn_amt:amount = [%s]\n", csPtr));
		strcat((char*)csBuf, "amount");
		strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);
		strcat((char*)csBuf, csPtr);
		strcat((char*)csBuf, MY_NEQ_TOKEN);
	}

// sign tag
	strcat((char*)csBuf, "key");
	strcat((char*)csBuf, MY_NEQ_FIELD_TOKEN);

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
	if (Str2KVPair(k_v_pair, &iPairCnt, inMsg, MY_NEQ_TOKEN, MY_NEQ_FIELD_TOKEN) == PD_OK) {
		for (iTmp = 0; iTmp < iPairCnt; iTmp++) {
DEBUGLOG(("key = [%s], value = [%s]\n", k_v_pair[iTmp].key, k_v_pair[iTmp].value));
			// exclude sign
			if (strcmp(k_v_pair[iTmp].key, "sign")) {
				strcat((char*)outMsg, k_v_pair[iTmp].key);
				strcat((char*)outMsg, MY_NEQ_FIELD_TOKEN);
				strcat((char*)outMsg, k_v_pair[iTmp].value);
				strcat((char*)outMsg, MY_NEQ_TOKEN);
			}
		}
	}

// signature has to be regenerated due to the originial GeneratePspSign flow read the NEQ channel code and add "key="
	RemoveField_CString(hIn, "sign");
	GetField_CString(hContext, "psp_channel_code", &csPtr);
	PutField_CString(hContext, "psp_channel_code", "dummy");

	BOObjPtr = CreateObj(BOPtr, "BOSecurity", "GenerateMD5Sign");
	if ((*BOObjPtr)(hContext, hIn) == PD_OK) {
DEBUGLOG(("call BOSecurity:GenerateMD5Sign OK\n"));
	}
	else {
DEBUGLOG(("call BOSecurity:GenerateMD5Sign FAILED\n"));
	}

	PutField_CString(hContext, "psp_channel_code", csPtr);

	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "sign");
		strcat((char*)outMsg, MY_NEQ_FIELD_TOKEN);
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

