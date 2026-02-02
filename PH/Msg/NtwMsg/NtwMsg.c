
/*
 * PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
 * of an authorized representative of PDProTech.
 *
 * Change Description                                 Change Date             Change By
 * -------------------------------                    ------------            --------------
 *  Init Version                                      2017/04/03              David Wong
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "NtwMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include <time.h>
#include "ObjPtr.h"
#include <json-c/json.h>

char	cDebug;

OBJPTR(DB);

void	NtwMsg(char cdebug)
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
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatMsg:: return_code is missing\n"));
	}

//code_url
	if (GetField_CString(hIn,"code_url",&csPtr)) {
DEBUGLOG(("FormatMsg:: code_url = [%s]\n",csPtr));


		strcat((char*)outMsg,"code_url");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		base64_encode((unsigned char *)csPtr,strlen((char*)csPtr),csCodeURL,PD_MAX_BUFFER);
		strcat((char*)outMsg,csCodeURL);
		strcat((char*)outMsg,MY_NTW_TOKEN);
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
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
				strcat((char*)outMsg,csPtr);
				strcat((char*)outMsg,MY_NTW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_init is missing\n"));
			}

//time_expire
			if (GetField_Int(hLog,"expiry",&iTmp)) {
				char csTimeExpire[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeExpire,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_expire = [%s]\n",csTimeExpire));
				strcat((char*)outMsg,"time_expire");
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeExpire);
				strcat((char*)outMsg,MY_NTW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_expire is missing\n"));
			}

//time_enable
			if (GetField_Int(hLog,"enable_button",&iTmp)) {
				char csTimeEnable[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeEnable,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_enable = [%s]\n",csTimeEnable));
				strcat((char*)outMsg,"time_enable");
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeEnable);
				strcat((char*)outMsg,MY_NTW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_enable is missing\n"));
			}

//time_auto_check
			if (GetField_Int(hLog,"auto_check_txn_status",&iTmp)) {
				char csTimeAutoCheck[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeAutoCheck,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_auto_check = [%s]\n",csTimeAutoCheck));
				strcat((char*)outMsg,"time_auto_check");
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeAutoCheck);
				strcat((char*)outMsg,MY_NTW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_auto_check is missing\n"));
			}

//time_redirect
			if (GetField_Int(hLog,"redirect",&iTmp)) {
				char csTimeRedirect[PD_TMP_BUF_LEN + 1];
				sprintf((char*)csTimeRedirect,"%d",iTmp);
DEBUGLOG(("FormatMsg:: time_redirect = [%s]\n",csTimeRedirect));
				strcat((char*)outMsg,"time_redirect");
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
				strcat((char*)outMsg,csTimeRedirect);
				strcat((char*)outMsg,MY_NTW_TOKEN);
			} else {
DEBUGLOG(("FormatMsg:: time_redirect is missing\n"));
			}

//time_curr
			if (GetField_CString(hLog,"qrcode_curr_timestamp",&csPtr)) {
DEBUGLOG(("FormatMsg:: time_curr = [%s]\n",csPtr));
				strcat((char*)outMsg,"time_db_local");
				strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
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

        if (Str2Cls(hRec,(char*)inMsg,MY_NTW_TOKEN,MY_NTW_FIELD_TOKEN) == PD_OK) {
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

DEBUGLOG(("BuildAuthData()\n"));
	memset(csDATA,0,sizeof(csDATA));

//business_id
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("BuildAuthData:: business_id = [%s]\n",csPtr));
		strcpy(csDATA,"business_id");
		strcat(csDATA,MY_NTW_FIELD_TOKEN);
		strcat(csDATA,csPtr);
		strcat(csDATA,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: business_id is missing\n"));
	}

//order_id
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("BuildAuthData:: order_id = [%s]\n",csPtr));
		strcat(csDATA,"order_id");
		strcat(csDATA,MY_NTW_FIELD_TOKEN);
		strcat(csDATA,csPtr);
		strcat(csDATA,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("BuildAuthData:: order_id is missing\n"));
	}

//amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("BuildAuthData:: amount = [%s]\n",csTmpAmt));
		strcat(csDATA,"amount");
		strcat(csDATA,MY_NTW_FIELD_TOKEN);
		strcat(csDATA,csTmpAmt);
		strcat(csDATA,MY_NTW_TOKEN);
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

DEBUGLOG(("BuildRspAuthData()\n"));
        memset(csDATA,0,sizeof(csDATA));

//return_code
	if (GetField_CString(hIn,"return_code",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: return_code = [%s]\n",csPtr));
		//business_id
		if (GetField_CString(hIn,"business_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: business_id = [%s]\n",csPtr));
			strcat(csDATA,"business_id");
			strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NTW_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: business_id is missing\n"));
		}

		//order_id
		if (GetField_CString(hIn,"order_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_id = [%s]\n",csPtr));
			strcat(csDATA,"order_id");
			strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NTW_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_id is missing\n"));
		}

		//amount
		if (GetField_CString(hIn,"amount",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: amount = [%s]\n",csPtr));
			strcat(csDATA,"amount");
			strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NTW_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: amount is missing\n"));
		}

		//trans_no
		if (GetField_CString(hIn,"trans_no",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: trans_no = [%s]\n",csPtr));
			strcat(csDATA,"trans_no");
			strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			strcat(csDATA,MY_NTW_TOKEN);
		} else {
DEBUGLOG(("BuildRspAuthData:: trans_no is missing\n"));
		}
	} else {
		//order_id
		if (GetField_CString(hIn,"txn_seq",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_id = [%s]\n",csPtr));
			//strcat(csDATA,"order_id");
			//strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NTW_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_id is missing\n"));
		}

		//stateCode
		if (GetField_CString(hIn,"status",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: stateCode = [%s]\n",csPtr));
			//strcat(csDATA,"stateCode");
			//strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NTW_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: stateCode is missing\n"));
		}

		//amount
		if (GetField_CString(hIn,"txn_amt",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: amount = [%s]\n",csPtr));
			//strcat(csDATA,"amount");
			//strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NTW_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: amount is missing\n"));
		}

		//order_no
		if (GetField_CString(hIn,"tid",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: order_no = [%s]\n",csPtr));
			//strcat(csDATA,"order_no");
			//strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NTW_TOKEN_SIGN);
		} else {
DEBUGLOG(("BuildRspAuthData:: order_no is missing\n"));
		}

		//business_id
		if (GetField_CString(hIn,"business_id",&csPtr)) {
DEBUGLOG(("BuildRspAuthData:: business_id = [%s]\n",csPtr));
			//strcat(csDATA,"business_id");
			//strcat(csDATA,MY_NTW_FIELD_TOKEN);
			strcat(csDATA,csPtr);
			//strcat(csDATA,MY_NTW_TOKEN_SIGN);
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


/*
int BuildInqAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char*   csPtr;
        char*   csBuf;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

DEBUGLOG(("BuildInqAuthData()\n"));
        memset(csBuf,0,MAX_MSG_SIZE);
        csBuf[0] = '\0';

// 1 input_charset
        strcat((char*)csBuf,"input_charset");
        strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
        strcat((char*)csBuf,"UTF-8");
        strcat((char*)csBuf,MY_NTW_TOKEN);

// 2 out_trade_no
        if (GetField_CString(hIn,"org_txn_seq",&csPtr)) {
                strcat((char*)csBuf,"out_trade_no");
                strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
                strcat((char*)csBuf,csPtr);
                strcat((char*)csBuf,MY_NTW_TOKEN);
DEBUGLOG(("BuildInqAuthData:: out_trade_no = [%s]\n",csPtr));
        }
        else {
DEBUGLOG(("BuildInqAuthData:: org_txn_seq is missing!!!\n"));
        }

// 3 partner
        if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
                strcat((char*)csBuf,"partner");
                strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
                strcat((char*)csBuf,csPtr);
                strcat((char*)csBuf,MY_NTW_TOKEN);
DEBUGLOG(("BuildInqAuthData:: partner = [%s]\n",csPtr));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("BuildInqAuthData:: ***psp_merchant_id is missing\n"));
        }

// 4 transaction_id
        if (GetField_CString(hIn,"tid",&csPtr)) {
                strcat((char*)csBuf,"transaction_id");
                strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
                strcat((char*)csBuf,csPtr);
                strcat((char*)csBuf,MY_NTW_TOKEN);
DEBUGLOG(("BuildInqAuthData:: transaction_id = [%s]\n",csPtr));
        }
        else {
DEBUGLOG(("BuildInqAuthData:: tid is missing!!!\n"));
        }

        PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildInqAuthData:: auth_data = [%s]\n",csBuf));
        FREE_ME(csBuf);

DEBUGLOG(("BuildInqAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
*/


/*
int FormatInqMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;

	char*	csPtr = NULL;
	char*	csURL = NULL;
	char* 	csBuf;

	//double	dTmp;
DEBUGLOG(("FormatInqMsg()\n"));

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	outMsg[0]= '\0';
//psp_url
	if (GetField_CString(hIn,"psp_url",&csURL)) {
		if (GetField_CString(hIn,"request_function",&csPtr)) {
			strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatInqMsg:: psp_url = [%s]\n",csURL));
DEBUGLOG(("FormatInqMsg:: request function  = [%s]\n",csPtr));
			strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
			strcat((char*)csBuf,"?");
DEBUGLOG(("FormatInqMsg:: psp_url = [%s]\n",csBuf));
		}	
	
		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatInqMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
DEBUGLOG(("FormatInqMsg:: outMsg = [%s]\n",outMsg));

	}
	FREE_ME(csBuf);

//input_charset
	strcat((char*)outMsg,"input_charset");
	strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
	strcat((char*)outMsg,"UTF-8");
	strcat((char*)outMsg,MY_NTW_TOKEN);
DEBUGLOG(("FormatInqMsg:: input_charset = [UTF-8]\n"));


//partner
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInqMsg:: partner = [%s]\n",csPtr));
		strcat((char*)outMsg,"partner");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	}
	else {
DEBUGLOG(("FormatInqMsg:: partner is missing\n"));
	}

//out_trade_no
	if (GetField_CString(hIn,"org_txn_seq",&csPtr)) {
DEBUGLOG(("FormatInqMsg:: out_trade_no = [%s]\n",csPtr));
		strcat((char*)outMsg,"out_trade_no");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	}
	else {
DEBUGLOG(("FormatInqMsg:: out_trade_no is missing\n"));
	}

//transaction_id
	if (GetField_CString(hIn,"tid",&csPtr)) {
DEBUGLOG(("FormatInqMsg:: transaction_id = [%s]\n",csPtr));
		strcat((char*)outMsg,"transaction_id");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	}
	else {
DEBUGLOG(("FormatInqMsg:: transaction_id is missing\n"));
	}

//sign
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInqMsg:: sign = [%s]\n",csPtr));
		strcat((char*)outMsg,"sign");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
//		strcat((char*)outMsg,MY_NTW_TOKEN);
	}	
	else {
DEBUGLOG(("FormatInqMsg:: sign not found!!!\n"));
	}


DEBUGLOG(("outmsg = [%s]\n",outMsg));

	*outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatInqMsg() [%s][%d]\n",outMsg,*outLen));
DEBUGLOG(("FormatInqMsg() Exit\n"));
	FREE_ME(csPtr);
	FREE_ME(csURL);
	return 	iRet;
}
*/


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
			strcat((char*)csBuf,MY_NTW_FIELD_TOKEN);
			strcat((char*)csBuf,csURL);
			strcat((char*)csBuf,"/");
			strcat((char*)csBuf,csPtr);
			//strcat((char*)csBuf,"?");
DEBUGLOG(("FormatInitMsg:: psp_url = [%s]\n",csBuf));
		}

		sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatInitMsg:: outMsg = [%s]\n",outMsg));
		strcat((char*)outMsg,csBuf);
		//strcat((char*)outMsg,MY_NTW_URL_END_TOKEN);
	}
	FREE_ME(csBuf);

//version
	if (GetField_CString(hIn,"version",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: version = [%s]\n",csPtr));
		strcat((char*)outMsg,"version");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: version is missing\n"));
	}

//business_id
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: business_id = [%s]\n",csPtr));
		strcat((char*)outMsg,"business_id");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: business_id is missing\n"));
	}

//order_id
	if (GetField_CString(hIn,"order_num",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: order_id = [%s]\n",csPtr));
		strcat((char*)outMsg,"order_id");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: order_id is missing\n"));
	}

//amount
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char csTmpAmt[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTmpAmt,"%.2f",dTmp);
DEBUGLOG(("FormatInitMsg:: amount = [%s]\n",csTmpAmt));
		strcat((char*)outMsg,"amount");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csTmpAmt);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: amount is missing\n"));
	}

//sign
	if (GetField_CString(hIn,"sign",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: sign = [%s]\n",csPtr));
		strcat((char*)outMsg,"sign");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: sign is missing\n"));
	}

//notify_url
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
DEBUGLOG(("FormatInitMsg:: notify_url = [%s]\n",csPtr));
		strcat((char*)outMsg,"notify_url");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,MY_NTW_TOKEN);
	} else {
DEBUGLOG(("FormatInitMsg:: notify_url is missing\n"));
	}

//validtime
	if (GetField_Int(hIn,"time_expire",&iTmp)) {
		char csTimeExpire[PD_TMP_BUF_LEN + 1];
		sprintf((char*)csTimeExpire,"%d",iTmp/60);
DEBUGLOG(("FormatInitMsg:: validtime = [%s]\n",csTimeExpire));
		strcat((char*)outMsg,"validtime");
		strcat((char*)outMsg,MY_NTW_FIELD_TOKEN);
		strcat((char*)outMsg,csTimeExpire);
		//strcat((char*)outMsg,MY_NTW_TOKEN);
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

