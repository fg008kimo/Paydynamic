/*
PDProTech (c)2018. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2018/05/03              LokMan Chow
Add deposit trace function			   2019/11/01              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EsqMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#define __USE_XOPEN
#include <time.h>
#include <json-c/json.h>


OBJPTR(DB);

static char	cDebug;

void	EsqMsg(char cdebug)
{
	cDebug = cdebug;
}


void remove_quote(const char *csValue, const int iType, char *csOut);

char *str_replace(char *orig, char *rep, char *with);

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
		strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_ESQ_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));


		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_ESQ_TOKEN);
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
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_ESQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_ESQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_ESQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_ESQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_ESQ_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
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
	char	*csPtr;
	char	*csBuf;
	double	dTmp;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	int	iForEnquiry = PD_FALSE;
	int	iForEnquiryCallback = PD_FALSE;

DEBUGLOG(("BuildAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_use", &iForEnquiry);
	if (iForEnquiry) {
		return BuildInqAuthData(hIn);
	}

	GetField_Int(hIn, "for_enquiry_callback_use", &iForEnquiryCallback);
	if (iForEnquiryCallback) {
		return BuildCallbackAuthData(hIn);
	}

	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';


// e_orderno
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildAuthData:: e_orderno = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: txn_seq is missing\n"));
	}

// e_no
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("BuildAuthData:: e_no = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: psp_merchant_id is missing\n"));
	}

// e_money
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		//sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, csTmpAmt);
DEBUGLOG(("BuildAuthData:: e_money = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing\n"));
	}


	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildAuthData:: auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildAuthData() Exit iRet = [%d]\n", iRet));
        return iRet;
}


int BreakDownMsg(hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	hash_t 	*hRec;
	char	csDate[PD_DATE_LEN+1];
	char	csDateTime[PD_DATETIME_LEN+1];

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	if (Str2Cls(hRec, (char *)inMsg, MY_ESQ_TOKEN, MY_ESQ_FIELD_TOKEN) == PD_OK) {
// str_ok
		if (GetField_CString(hRec, "str_ok", &csPtr)) {
			PutField_CString(hOut, "status", csPtr);
DEBUGLOG(("str_ok:status = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("str_ok:status not found\n"));
		}

// str_no
		if (GetField_CString(hRec, "str_no", &csPtr)) {
			PutField_CString(hOut, "tid", csPtr);
DEBUGLOG(("str_no:tid = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("str_no:tid not found\n"));
		}

// e_Cur
		if (GetField_CString(hRec, "e_Cur", &csPtr)) {
DEBUGLOG(("e_Cur = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("e_Cur not found\n"));
		}

// e_money
		if (GetField_CString(hRec, "e_money", &csPtr)) {
			PutField_CString(hOut, "psp_txn_amt", csPtr);
			PutField_CString(hOut, "txn_amt", csPtr);
DEBUGLOG(("e_money:txn_amt = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("e_money:txn_amt not found\n"));
		}

// e_orderno
		if (GetField_CString(hRec, "e_orderno", &csPtr)) {
			PutField_CString(hOut, "txn_seq", csPtr);
DEBUGLOG(("e_orderno:txn_seq = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("e_orderno:txn_seq not found\n"));
		}

// e_no
		if (GetField_CString(hRec, "e_no", &csPtr)) {
			PutField_CString(hOut, "psp_merchant_id", csPtr);
DEBUGLOG(("e_no:psp_merchant_id = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("e_no:psp_merchant_id not found\n"));
		}

// e_date
		if (GetField_CString(hRec, "e_date", &csPtr)) {
			sprintf(csDate, "%s", TrimAll((const unsigned char *)csPtr, strlen(csPtr)));
			PutField_CString(hOut, "txn_date", csDate);
DEBUGLOG(("e_date:txn_date = [%s]\n", csDate));


			if (GetField_CString(hRec, "e_time", &csPtr)) {
				sprintf(csDateTime, "%s%s", csDate, deleteCharacters(TrimAll((const unsigned char *)csPtr, strlen(csPtr)),":"));
				PutField_CString(hOut, "fundin_date", csDateTime);
DEBUGLOG(("+e_time:fundin_date = [%s]\n", csDateTime));
			}
			else{
DEBUGLOG(("e_time not found\n"));
			}
		}
		else{
DEBUGLOG(("e_date:txn_date not found\n"));
		}


// e_outlay
		if (GetField_CString(hRec, "e_outlay", &csPtr)) {
DEBUGLOG(("e_outlay:service_fee = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("e_outlay:service_fee not found\n"));
		}


// str_msg
		if (GetField_CString(hRec, "str_msg", &csPtr)) {
DEBUGLOG(("str_msg: error_msg = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("str_msg:error_msg not found\n"));
		}

// bstr_msg
		if (GetField_CString(hRec, "bstr_msg", &csPtr)) {
DEBUGLOG(("bstr_msg: bank_error_msg = [%s]\n", csPtr));
		}
		else {
DEBUGLOG(("bstr_msg:bank_error_msg not found\n"));
		}

// str_check
		if (GetField_CString(hRec, "str_check", &csPtr)) {
			PutField_CString(hOut, "sign", csPtr);
DEBUGLOG(("str_check:sign = [%s]\n", csPtr));
		}
		else {
			PutField_CString(hOut, "sign", " ");
DEBUGLOG(("str_check:sign not found\n"));
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
DEBUGLOG(("psp_url = [%s]\n",csURL));
DEBUGLOG(("request function = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_ESQ_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
DEBUGLOG(("psp_url = [%s]\n",csBuf));
		}

		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
	}
	FREE_ME(csBuf);


// e_orderno
	if (GetField_CString(hIn, "order_num", &csPtr)) {
DEBUGLOG(("e_orderno = [%s]\n", csPtr));
		strcat((char*)outMsg, "e_orderno");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	} else {
DEBUGLOG(("e_orderno is missing\n"));
	}

// e_url
	//if (GetField_CString(hIn, "fe_url", &csPtr)) {
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
		strcat((char*)outMsg, "e_url");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, "fe/");
		strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_url = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("e_url is missing\n"));
	}

// e_backend_url
	if (GetField_CString(hIn, "return_url_only", &csPtr)) {
DEBUGLOG(("e_backend_url = [%s]\n", csPtr));
		strcat((char*)outMsg, "e_backend_url");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	} else {
DEBUGLOG(("e_backend_url is missing\n"));
	}

//e_no
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("e_no = [%s]\n", csPtr));
		strcat((char*)outMsg, "e_no");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	} else {
DEBUGLOG(("e_no is missing\n"));
	}

// e_storename
		strcat((char*)outMsg, "e_storename");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, MY_ESQ_TOKEN);


// e_Lang
		strcat((char*)outMsg, "e_Lang");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, MY_ESQ_LANG);
		strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_Lang = [%s]\n", MY_ESQ_LANG));


//e_bank
	if (GetField_CString(hIn, "bank_code", &csPtr)) {
		strcat((char*)outMsg, "e_bank");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		DBObjPtr = CreateObj(DBPtr, "DBBankMapping", "i2eBankCodeMapping");
		if ((DBObjPtr)(csPtr, PD_CHANNEL_ESKY_QR, PD_CHINA, csOutBankCode)) {
			strcat((char*) outMsg, csOutBankCode);
DEBUGLOG(("e_bank = [%s]\n", csOutBankCode));
		}
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	}


// e_Cur
	if (GetField_CString(hIn, "psp_txn_ccy", &csPtr)) {
		strcat((char*)outMsg, "e_Cur");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		if(!strcmp(csPtr, PD_CCY_ISO_CNY)){
			strcat((char*)outMsg, PD_CCY_ISO_RMB);
DEBUGLOG(("e_Cur = [%s]\n", PD_CCY_ISO_RMB));
		}else{
			strcat((char*)outMsg, csPtr);
DEBUGLOG(("e_Cur = [%s]\n", csPtr));
		}
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	}


// e_money
	if (GetField_Double(hIn, "psp_txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		//sprintf((char*)csTmpAmt, "%ld", double2long(dTmp));
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
DEBUGLOG(("e_money = [%s]\n", csTmpAmt));
		strcat((char*)outMsg, "e_money");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, (char*)csTmpAmt);
		strcat((char*)outMsg, MY_ESQ_TOKEN);
	} else {
DEBUGLOG(("e_money is missing\n"));
	}

// e_depositTime
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
		char *csTmp2 = NULL;
		char csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn,"local_tm_time",&csTmp2)) {
			sprintf(csDateTime,"%s%s",csPtr,csTmp2);
			strcat((char*)outMsg,"e_depositTime");
			strcat((char*)outMsg,MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg,csDateTime);
			strcat((char*)outMsg,MY_ESQ_TOKEN);
DEBUGLOG(("e_depositTime = [%s]\n",csDateTime));
		}
		else {
DEBUGLOG(("local_tm_time is missing!!!\n"));
		}
	}
	else {
DEBUGLOG(("local_tm_date is missing!!!\n"));
	}


// str_check
	if (GetField_CString(hIn, "sign", &csPtr)) {
DEBUGLOG(("str_check = [%s]\n", csPtr));
		strcat((char*)outMsg, "str_check");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
	} else {
DEBUGLOG(("str_check is missing\n"));
	}


DEBUGLOG(("outmsg = [%s]\n", outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInitMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatInitMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return  iRet;
}


int BreakDownInitRspMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr = NULL;
	char	*csReturnCode= NULL;
	hash_t	*hRec;
	char    csMsg[PD_MAX_BUFFER + 1];
	
	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec,0);

	csMsg[0] = '\0';

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
                                        strcat((char*)csMsg, key);
                                        strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
                                        strcat((char*)csMsg, json_object_get_string(val));
                                        strcat((char*)csMsg, MY_ESQ_TOKEN);
                                break;
                                default:
DEBUGLOG(("unsupported type\n"));
                                break;
                        }
                }
        }


	if (Str2Cls(hRec, (char *)csMsg, MY_ESQ_TOKEN, MY_ESQ_FIELD_TOKEN) == PD_OK) {

		if (GetField_CString(hRec, "str_ok", &csReturnCode)) {
			// return_code
			PutField_CString(hOut, "return_code", csReturnCode);
			PutField_CString(hOut, "status", csReturnCode); //for BuildRspAuth
DEBUGLOG(("return_code = [%s]\n", csReturnCode));

			// return_msg
			if (GetField_CString(hRec, "str_msg", &csPtr)) {
				PutField_CString(hOut, "return_msg", csPtr);
DEBUGLOG(("return_msg = [%s]\n", csPtr));
			}

			if (!strcmp(csReturnCode, MY_ESQ_SUCCESS_STATUS)) {

				// str_no
				if (GetField_CString(hRec, "str_no", &csPtr)) {
					PutField_CString(hOut, "tid", csPtr); //for BuildRspAuth
DEBUGLOG(("str_no:tid = [%s]\n", csPtr));
				}

				// e_no
				if (GetField_CString(hRec, "e_no", &csPtr)) {
					PutField_CString(hOut, "psp_merchant_id", csPtr); //for BuildRspAuth
DEBUGLOG(("e_no:psp_merchant_id = [%s]\n", csPtr));
				}

				// e_orderno
				if (GetField_CString(hRec, "e_orderno", &csPtr)) {
					PutField_CString(hOut, "ret_txn_id", csPtr);
					PutField_CString(hOut, "txn_seq", csPtr); //for BuildRspAuth
DEBUGLOG(("e_orderno:ret_txn_id = [%s]\n", csPtr));
				}

				// e_money
				if (GetField_CString(hRec, "e_money", &csPtr)) {
					PutField_CString(hOut, "amount", csPtr);
					PutField_CString(hOut, "psp_txn_amt", csPtr); //for BuildRspAuth
DEBUGLOG(("e_money:amount = [%s]\n",csPtr));
				}

				// e_date e_time
				char	csDate[PD_DATE_LEN+1];
				char	csDateTime[PD_DATETIME_LEN+1];
				if (GetField_CString(hRec, "e_date", &csPtr)) {
					sprintf(csDate, "%s", TrimAll((const unsigned char *)csPtr, strlen(csPtr)));
DEBUGLOG(("e_date = [%s]\n", csDate));


					if (GetField_CString(hRec, "e_time", &csPtr)) {
						sprintf(csDateTime, "%s%s", csDate, deleteCharacters(TrimAll((const unsigned char *)csPtr, strlen(csPtr)),":"));
DEBUGLOG(("e_date + e_time = [%s]\n", csDateTime));
					}
				}

				// e_Remark
				if (GetField_CString(hRec, "e_Remark", &csPtr)) {
					PutField_CString(hOut, "org_code_url", csPtr); //for BuildRspAuth

					char csCodeUrl[PD_TMP_BUF_LEN];
					csCodeUrl[0] = '\0';
					strcpy((char*)csCodeUrl, str_replace((char*)csPtr, "\\/", "/"));
					PutField_CString(hOut, "code_url", csCodeUrl);
DEBUGLOG(("e_Remark:code_url = [%s]\n", csPtr));
				}

				//str_check
				if (GetField_CString(hRec,"str_check",&csPtr)) {
					PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("str_check:sign = [%s]\n",csPtr));
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
	char *csPtr;
	char *csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	int	iForEnquiryRsp = PD_FALSE;

DEBUGLOG(("BuildRspAuthData()\n"));

	GetField_Int(hIn, "for_enquiry_rsp_use", &iForEnquiryRsp);

	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

	if (!iForEnquiryRsp) {
// str_ok
		if (GetField_CString(hIn, "status", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: str_ok:status = [%s]\n", csPtr));
			strcat((char*)csBuf, csPtr);
		}
	}

// e_orderno
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: e_orderno:txn_seq = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}

// e_no
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: e_no:psp_merchant_id = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}

// e_money
	if (GetField_CString(hIn, "psp_txn_amt", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: e_money:psp_txn_amt = [%s]\n", csPtr));
		strcat((char*)csBuf, csPtr);
	}

	if (!iForEnquiryRsp) {
// str_no
		if (GetField_CString(hIn, "tid", &csPtr)) {
DEBUGLOG(("BuildRspAuthData:: str_no:tid = [%s]\n", csPtr));
			strcat((char*)csBuf, csPtr);
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


int FormatInqMsg(const hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int	iRet = PD_OK;
	char	*csBuf;
	char	*csURL = NULL;
	char	*csPtr = NULL;
	char	*csTmp = NULL;
	double	dTmp = 0.0;

DEBUGLOG(("FormatInqMsg() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "psp_url", &csURL)) {
		if (GetField_CString(hIn, "request_function", &csPtr)) {
			strcpy((char*)csBuf, "url");
			strcat((char*)csBuf, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csBuf, csURL);
			strcat((char*)csBuf, "/");
			strcat((char*)csBuf, csPtr);

			/* added for gw to identify the request */
			strcat((char*)csBuf, MY_ESQ_TOKEN);
			strcat((char*)csBuf, "enq");
			strcat((char*)csBuf, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csBuf, "1");

			strcat((char*)csBuf, MY_ESQ_TOKEN);
			strcat((char*)csBuf, "METHOD");
			strcat((char*)csBuf, MY_ESQ_FIELD_TOKEN);
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

// e_orderno
		if (GetField_CString(hIn, "txn_seq", &csTmp)) {
			strcat((char*)outMsg, "e_orderno");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_orderno = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_seq is missing\n"));
		}

// e_url
		if (GetField_CString(hIn, "fe_url", &csTmp)) {
			strcat((char*)outMsg, "e_url");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_url = [%s]\n", csTmp));
		}
		else {
DEBUGLOG(("***fe_url is missing\n"));
			strcat((char*)outMsg, "e_url");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, "not_applicable");
			strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("***default e_url\n"));
		}

// e_no
		if (GetField_CString(hIn, "psp_merchant_id", &csTmp)) {
			strcat((char*)outMsg, "e_no");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
			strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_no = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***psp_merchant_id is missing\n"));
		}

// e_money
		if (GetField_Double(hIn, "txn_amt", &dTmp)) {
			char csTmpAmt[PD_TMP_BUF_LEN + 1];
			sprintf((char*)csTmpAmt, "%.2f", dTmp);
			strcat((char*)outMsg, "e_money");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmpAmt);
			strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("e_money = [%s]\n", csTmpAmt));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***txn_amt is missing\n"));
		}

// str_check
		if (GetField_CString(hIn, "sign", &csTmp)) {
			strcat((char*)outMsg, "str_check");
			strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)outMsg, csTmp);
                        //strcat((char*)outMsg, MY_ESQ_TOKEN);
DEBUGLOG(("str_check = [%s]\n", csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("***sign is missing\n"));
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
	char	*csPtr = NULL;
	double dTmp = 0.0;

DEBUGLOG(("BuildInqAuthData() Start\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// e_orderno
	if (GetField_CString(hIn, "txn_seq", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("e_orderno = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_seq is missing\n"));
	}

// e_no
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("e_no = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// e_money
	if (GetField_Double(hIn, "txn_amt", &dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt, "%.2f", dTmp);
		strcat((char*)csBuf, csTmpAmt);
DEBUGLOG(("e_money = [%s]\n", csTmpAmt));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("txn_amt is missing\n"));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("BuildInqAuthData() auth_data = [%s]\n", csBuf));
DEBUGLOG(("BuildInqAuthData() Exit iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;
}


int BreakDownInqRspMsg(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int iRet = PD_OK;
	char *csTmp = NULL;
	char csTag[PD_TAG_LEN + 1];
	char csOrigMsg[PD_MAX_BUFFER + 1];
	char csMsg[PD_MAX_BUFFER + 1];
	hash_t *hRec;

	hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	csOrigMsg[0] = '\0';
	csMsg[0] = '\0';

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
					if (!strcmp(key, "str_ok")) {
						strcat((char*)csOrigMsg, key);
						strcat((char*)csOrigMsg, MY_ESQ_FIELD_TOKEN);
						if (strlen(json_object_get_string(val)) == 0) {
							strcat((char*)csOrigMsg, MY_ESQ_PENDING_STATUS);
						} else {
							strcat((char*)csOrigMsg, json_object_get_string(val));
						}
						strcat((char*)csOrigMsg, MY_ESQ_TOKEN);
					} else if (!strcmp(key, "str_check")) {
						PutField_CString(hOut, "str_check", json_object_get_string(val));
						PutField_CString(hOut, "sign", json_object_get_string(val));
					} else {
						strcat((char*)csOrigMsg, key);
						strcat((char*)csOrigMsg, MY_ESQ_FIELD_TOKEN);
						strcat((char*)csOrigMsg, json_object_get_string(val));
						strcat((char*)csOrigMsg, MY_ESQ_TOKEN);
					}
				break;
				default:
DEBUGLOG(("unsupported type\n"));
				break;
			}
		}
	}

	PutField_CString(hOut, "in_msg", (const char *)csOrigMsg);

	if (Str2Cls(hRec, (const char *)csOrigMsg, MY_ESQ_TOKEN, MY_ESQ_FIELD_TOKEN) == PD_OK) {

		sprintf(csTag, "e_url");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_url", csTmp);
		} else {
DEBUGLOG(("e_url not found\n"));
		}

		sprintf(csTag, "str_ok");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "str_ok", csTmp);
			PutField_CString(hOut, "status", csTmp);
		} else {
DEBUGLOG(("str_ok not found\n"));
		}

		sprintf(csTag, "str_no");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "str_no", csTmp);
			PutField_CString(hOut, "tid", csTmp);
		} else {
DEBUGLOG(("str_no not found\n"));
		}

		sprintf(csTag, "e_Cur");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_Cur", csTmp);
		} else {
DEBUGLOG(("e_Cur not found\n"));
		}

		sprintf(csTag, "e_money");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_money", csTmp);
			PutField_CString(hOut, "txn_amt", csTmp);
			PutField_CString(hOut, "psp_txn_amt", csTmp);
		} else {
DEBUGLOG(("e_money not found\n"));
		}

		sprintf(csTag, "e_rmbrate");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_rmbrate", csTmp);
		} else {
DEBUGLOG(("e_rmbrate not found\n"));
		}

		sprintf(csTag, "e_rmbmoney");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_rmbmoney", csTmp);
		} else {
DEBUGLOG(("e_rmbmoney not found\n"));
		}

		sprintf(csTag, "e_orderno");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_orderno", csTmp);
			PutField_CString(hOut, "txn_seq", csTmp);
			PutField_CString(hOut, "order_num", csTmp);
		} else {
DEBUGLOG(("e_orderno not found\n"));
		}

		sprintf(csTag, "e_no");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_no", csTmp);
			PutField_CString(hOut, "psp_merchant_id", csTmp);
		} else {
DEBUGLOG(("e_no not found\n"));
		}

		sprintf(csTag, "e_date");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_date", csTmp);
		} else {
DEBUGLOG(("e_date not found\n"));
		}

		sprintf(csTag, "e_time");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_time", csTmp);
		} else {
DEBUGLOG(("e_time not found\n"));
		}

		sprintf(csTag, "re_date");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "re_date", csTmp);
		} else {
DEBUGLOG(("re_date not found\n"));
		}

		sprintf(csTag, "re_time");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "re_time", csTmp);
		} else {
DEBUGLOG(("re_time not found\n"));
		}

		sprintf(csTag, "e_outlay");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_outlay", csTmp);
		} else {
DEBUGLOG(("e_outlay not found\n"));
		}

		sprintf(csTag, "str_msg");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "str_msg", csTmp);
		} else {
DEBUGLOG(("str_msg not found\n"));
		}

		sprintf(csTag, "bstr_msg");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "bstr_msg", csTmp);
		} else {
DEBUGLOG(("bstr_msg not found\n"));
		}

		sprintf(csTag, "rstr_msg");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "rstr_msg", csTmp);
		} else {
DEBUGLOG(("rstr_msg not found\n"));
		}

		sprintf(csTag, "e_Remark");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_Remark", csTmp);
		} else {
DEBUGLOG(("e_Remark not found\n"));
		}

		sprintf(csTag, "e_bank");
		if (GetField_CString(hRec, csTag, &csTmp)) {
DEBUGLOG(("%s = [%s]\n", csTag, csTmp));
			PutField_CString(hOut, "e_bank", csTmp);
		} else {
DEBUGLOG(("e_bank not found\n"));
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


int BreakDownInqRspMsg_Old(hash_t *hContext, hash_t *hOut, const unsigned char *inMsg, int inLen)
{
	int iRet = PD_OK;
	char *csDATA = malloc (PD_MAX_BUFFER + 1);
	char *csPara = malloc (PD_MAX_BUFFER + 1);
	char *csTmp;
	char csTag[PD_TAG_LEN + 1];
	char csMsg[PD_MAX_BUFFER + 1];
	csMsg[0] = '\0';

	hash_t *hRec;
	hRec = (hash_t *) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	memcpy(csDATA, inMsg, inLen);
	csDATA[inLen] = '\0';

DEBUGLOG(("BreakDownInqRspMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n", inMsg, inLen));

	// remove '{'
	csPara[0] = '\0';
	remove_quote(csDATA, PD_OPEN_BRACKET_H, csPara);
	csPara[strlen(csPara)] = '\0';
	strcpy(csDATA, csPara);

	// remove '}'
	csPara[0] = '\0';
	remove_quote(csDATA, PD_CLOSE_BRACKET_H, csPara);
	csPara[strlen(csPara)] = '\0';
	strcpy(csDATA, csPara);

	if (Str2Cls(hRec, (const char *)csDATA, MY_ESQ_JSON_TOKEN, MY_ESQ_JSON_FIELD_TOKEN) == PD_OK) {

		sprintf(csTag, "\"e_url\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_url = [%s]\n", csPara));
			PutField_CString(hOut, "e_url", csPara);

			strcat((char*)csMsg, "e_url");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_url not found\n"));
		}

		sprintf(csTag, "\"str_ok\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';

			if (strlen(csPara) == 0) {
				strcpy(csPara, MY_ESQ_PENDING_STATUS);
DEBUGLOG(("str_ok is empty, default pending\n"));
			}

DEBUGLOG(("str_ok = [%s]\n", csPara));
			PutField_CString(hOut, "str_ok", csPara);
			PutField_CString(hOut, "status", csPara);

			strcat((char*)csMsg, "str_ok");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("str_ok not found\n"));
		}

		sprintf(csTag, "\"str_no\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("str_no = [%s]\n", csPara));
			PutField_CString(hOut, "str_no", csPara);
			PutField_CString(hOut, "tid", csPara);

			strcat((char*)csMsg, "str_no");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("str_no not found\n"));
		}

		sprintf(csTag, "\"e_Cur\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_Cur = [%s]\n", csPara));
			PutField_CString(hOut, "e_Cur", csPara);

			strcat((char*)csMsg, "e_Cur");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_Cur not found\n"));
		}

		sprintf(csTag, "\"e_money\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_money = [%s]\n", csPara));
			PutField_CString(hOut, "e_money", csPara);
			PutField_CString(hOut, "txn_amt", csPara);
			PutField_CString(hOut, "psp_txn_amt", csPara);

			strcat((char*)csMsg, "e_money");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_money not found\n"));
		}

		sprintf(csTag, "\"e_rmbrate\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_rmbrate = [%s]\n", csPara));
			PutField_CString(hOut, "e_rmbrate", csPara);

			strcat((char*)csMsg, "e_rmbrate");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_rmbrate not found\n"));
		}

		sprintf(csTag, "\"e_rmbmoney\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_rmbmoney = [%s]\n", csPara));
			PutField_CString(hOut, "e_rmbmoney", csPara);

			strcat((char*)csMsg, "e_rmbmoney");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_rmbmoney not found\n"));
		}

		sprintf(csTag, "\"e_orderno\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_orderno = [%s]\n", csPara));
			PutField_CString(hOut, "e_orderno", csPara);
			PutField_CString(hOut, "txn_seq", csPara);

			strcat((char*)csMsg, "e_orderno");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_orderno not found\n"));
		}

		sprintf(csTag, "\"e_no\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_no = [%s]\n", csPara));
			PutField_CString(hOut, "e_no", csPara);
			PutField_CString(hOut, "psp_merchant_id", csPara);

			strcat((char*)csMsg, "e_no");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_no not found\n"));
		}

		sprintf(csTag, "\"e_date\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_date = [%s]\n", csPara));
			PutField_CString(hOut, "e_date", csPara);

			strcat((char*)csMsg, "e_date");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_date not found\n"));
		}

		sprintf(csTag, "\"e_time\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_time = [%s]\n", csPara));
			PutField_CString(hOut, "e_time", csPara);

			strcat((char*)csMsg, "e_time");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_time not found\n"));
		}

		sprintf(csTag, "\"re_date\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("re_date = [%s]\n", csPara));
			PutField_CString(hOut, "re_date", csPara);

			strcat((char*)csMsg, "re_date");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("re_date not found\n"));
		}

		sprintf(csTag, "\"re_time\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("re_time = [%s]\n", csPara));
			PutField_CString(hOut, "re_time", csPara);

			strcat((char*)csMsg, "re_time");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("re_time not found\n"));
		}

		sprintf(csTag, "\"e_outlay\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_outlay = [%s]\n", csPara));
			PutField_CString(hOut, "e_outlay", csPara);

			strcat((char*)csMsg, "e_outlay");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_outlay not found\n"));
		}

		sprintf(csTag, "\"str_check\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("str_check = [%s]\n", csPara));
			PutField_CString(hOut, "str_check", csPara);
			PutField_CString(hOut, "sign", csPara);
		} else {
DEBUGLOG(("str_check not found\n"));
		}

		sprintf(csTag, "\"str_msg\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("str_msg = [%s]\n", csPara));
			PutField_CString(hOut, "str_msg", csPara);

			strcat((char*)csMsg, "str_msg");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("str_msg not found\n"));
		}

		sprintf(csTag, "\"bstr_msg\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("bstr_msg = [%s]\n", csPara));
			PutField_CString(hOut, "bstr_msg", csPara);

			strcat((char*)csMsg, "bstr_msg");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("bstr_msg not found\n"));
		}

		sprintf(csTag, "\"rstr_msg\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("rstr_msg = [%s]\n", csPara));
			PutField_CString(hOut, "rstr_msg", csPara);

			strcat((char*)csMsg, "rstr_msg");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("rstr_msg not found\n"));
		}

		sprintf(csTag, "\"e_Remark\"");
		if (GetField_CString(hRec, csTag, &csTmp)) {
			csPara[0] = '\0';
			remove_quote(csTmp, PD_DOUBLE_QUOTE, csPara);
			csPara[strlen(csPara)] = '\0';
DEBUGLOG(("e_Remark = [%s]\n", csPara));
			PutField_CString(hOut, "e_Remark", csPara);

			strcat((char*)csMsg, "e_Remark");
			strcat((char*)csMsg, MY_ESQ_FIELD_TOKEN);
			strcat((char*)csMsg, csPara);
			strcat((char*)csMsg, MY_ESQ_TOKEN);
		} else {
DEBUGLOG(("e_Remark not found\n"));
		}

		PutField_CString(hOut, "in_msg", csMsg);
	} else {
DEBUGLOG(("BreakDownInqRspMsg() Error\n"));
		iRet = PD_ERR;
	}

	FREE_ME(csDATA);
	FREE_ME(csPara);
	hash_destroy(hRec);
	FREE_ME(hRec);
DEBUGLOG(("BreakDownInqRspMsg Exit\n"));
	return iRet;
}


int BuildInqRspAuthData(hash_t *hIn)
{
	int iRet = PD_OK;

DEBUGLOG(("BuildInqRspAuthData() Start\n"));
DEBUGLOG(("BuildInqRspAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int BuildCallbackAuthData(hash_t *hIn)
{
	int iRet = PD_OK;
	char *csPtr;
	char *csBuf;
	csBuf = (char*) malloc (MAX_MSG_SIZE + 1);

DEBUGLOG(("BuildCallbackAuthData() Start\n"));
	memset(csBuf, 0, MAX_MSG_SIZE);
	csBuf[0] = '\0';

// str_ok
	if (GetField_CString(hIn, "status", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("str_ok = [%s]\n", csPtr));
	}

// e_orderno
	if (GetField_CString(hIn, "order_num", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("e_orderno = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("order_num is missing\n"));
	}

// e_no
	if (GetField_CString(hIn, "psp_merchant_id", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("e_no = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_merchant_id is missing\n"));
	}

// e_money
	if (GetField_CString(hIn, "psp_txn_amt", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("e_money = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("psp_txn_amt is missing\n"));
	}

// str_no
	if (GetField_CString(hIn, "tid", &csPtr)) {
		strcat((char*)csBuf, csPtr);
DEBUGLOG(("str_no = [%s]\n", csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("tid is missing\n"));
	}

	PutField_CString(hIn, "auth_data", csBuf);
DEBUGLOG(("auth_data = [%s]\n", csBuf));
	FREE_ME(csBuf);

DEBUGLOG(("BuildCallbackAuthData() Exit iRet = [%d]\n", iRet));
	return iRet;
}


int FormatCallbackMsg(hash_t *hContext, hash_t *hIn, unsigned char *outMsg, int *outLen)
{
	int iRet = PD_OK;
	char *csPtr = NULL;

DEBUGLOG(("FormatCallbackMsg() Start\n"));

	memset(outMsg, 0, sizeof(outMsg));

	if (GetField_CString(hIn, "in_msg", &csPtr)) {
		strcat((char*)outMsg, csPtr);
	}

	if (GetField_CString(hIn, "sign", &csPtr)) {
		strcat((char*)outMsg, "str_check");
		strcat((char*)outMsg, MY_ESQ_FIELD_TOKEN);
		strcat((char*)outMsg, csPtr);
	}

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatCallbackMsg() [%s][%d]\n", outMsg, *outLen));
DEBUGLOG(("FormatCallbackMsg() Exit\n"));
	FREE_ME(csPtr);
	return iRet;
}


void remove_quote(const char *csValue, const int iType, char *csOut)
{
	int i = 0;
	int cnt = 0;
	for (i = 0; i < strlen(csValue); i++) {
		if (csValue[i] != iType) {
			csOut[cnt] = csValue[i];
			cnt++;
		} else {
		}
	}
	csOut[cnt] = '\0';
}

