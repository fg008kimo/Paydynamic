/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/04/027             Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "P2xMsg.h"
#include "common.h"
#include "utilitys.h"
#include "b64.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include "utilitys.h"
#include "blowfishp.h"
#define	KEY_PREFIX	"HIBRfhyjwehyfyu83u6y"
char	cDebug;

OBJPTR(Msg);

void	P2xMsg(char cdebug)
{
	cDebug = cdebug;
}

static char hexchar[] = {
        '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
        'A', 'B', 'C', 'D', 'E', 'F'
    };
int DeBlockWTBData(hash_t *hOut,const char* inMsg);
char*   AppendParam(const char* csID, const char* csValue)
{

        char    *csBuf;
        csBuf = (char*) malloc (1024 +1);
        if (csValue == NULL)
                sprintf(csBuf, "%s000",csID);
        else
                sprintf(csBuf, "%s%03d%s",csID,(int)strlen(csValue),csValue);
              return csBuf;
}


int FormatDeMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
        int     iRet = PD_OK;
        char*   csPtr = NULL;
        char*   csBuf;
        char*   csURL;

        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

        memset(outMsg,0,sizeof(outMsg));


DEBUGLOG(("FormatDeMsg::()\n"));
//psp_url
        if (GetField_CString(hIn,"psp_url",&csURL) && iRet == PD_OK) {
//request_function
                if (GetField_CString(hIn,"request_function",&csPtr)) {
                        strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatDeMsg:: psp_url = [%s]\n",csURL));
                        strcat((char*)csBuf,MY_CCT_FIELD_TOKEN);
                        strcat((char*)csBuf,csURL);
                        strcat((char*)csBuf,"/");
                        strcat((char*)csBuf,csPtr);
                        strcat((char*)csBuf,MY_CCT_TOKEN);
                }

                sprintf((char *)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
DEBUGLOG(("FormatDeMsg:: outMsg = [%s]\n",outMsg));
                strcat((char *)outMsg,csBuf);

                if (GetField_CString(hIn,"merchantid",&csPtr)) {
DEBUGLOG(("FormatDeMsg:: merchantid = [%s]\n",csPtr));
                        strcat((char*)outMsg,"merchantid");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csPtr);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
		}
                if (GetField_CString(hIn,"message",&csPtr)) {
DEBUGLOG(("FormatDeMsg:: message = [%s]\n",csPtr));
                        strcat((char*)outMsg,"message");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csPtr);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
		}

        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatDeMsg:: psp_url not found\n"));
        }
        FREE_ME(csBuf);

DEBUGLOG(("FormatDeMsg:: outmsg = [%s]\n",outMsg));
        *outLen = strlen((char *)outMsg);
                

DEBUGLOG(("FormatDeMsg:: iRet = [%d]\n",iRet));
        return  iRet;
}

int FormatEnMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
        int     iRet = PD_OK;
        char*   csPtr = NULL;
        char*   csMerchantKey = NULL;
	char	csKey[256 +1];;
	int	iCnt =0;

        memset(outMsg,0,sizeof(outMsg));


       	if (GetField_CString(hIn,"merchant_key",&csMerchantKey)) {
		
DEBUGLOG(("merchant key = [%d]\n",csMerchantKey));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("FormatEnMsg: merchant key is missing!!!\n"));
	}

/* 001 */
/* messageID */
	strcat((char*)outMsg,AppendParam("001","0100"));
	iCnt++;

/* 002 */
/* session_id */
       	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)outMsg,AppendParam("002",csPtr));
		iCnt++;
DEBUGLOG(("FormatMsg:: txn_seq = [%s]\n",csPtr));
       	}
       	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** txn_seq is missing\n"));
      	}
/* 008 */
/* merchant_id */
       	if (GetField_CString(hIn,"merchant_id",&csPtr)) {
		strcat((char*)outMsg,AppendParam("008",csPtr));
		iCnt++;
/* format key */
		sprintf(csKey,"%sQNE%s%s",KEY_PREFIX,csPtr,csMerchantKey);
DEBUGLOG(("FormatEnMsg:: KEY = [%s]\n",csKey));
		
DEBUGLOG(("FormatMsg:: merchant_id = [%s]\n",csPtr));
       	}
       	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** merchant_id is missing\n"));
      	}

/* 003 */
/* txn_seq */
	strcat((char*)outMsg,AppendParam("003","000000001"));


/* 004 */
/* merchant_ref */
	if (GetField_CString(hIn,"merchant_ref",&csPtr)) {
		strcat((char*)outMsg,AppendParam("004",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg:: merchant_ref = [%s]\n",csPtr));
	}
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** merchant_ref is missing\n"));
	}

/* 006 */
/* server_ip */
	if (GetField_CString(hIn,"server_ip",&csPtr)) {
		strcat((char*)outMsg,AppendParam("006",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg: server_ip = [%s]\n",csPtr));
	}
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** server_ip is missing\n"));
	}

/* 007 */
/* txn_datetime */
	if (GetField_CString(hIn,"transmission_datetime",&csPtr)) {
		strcat((char*)outMsg,AppendParam("007",csPtr));
		iCnt++;
DEBUGLOG(("FormatEnMsg: transmission_datetime = [%s]\n",csPtr));
	}
/* 009 */
/* language */
         if (GetField_CString(hIn,"language",&csPtr)) {
		char* csLang;
		csLang = (char*) malloc (strlen(csPtr) * 2 + 1 );
		if (!strcmp(csPtr,"ZH"))
			strcpy(csLang,"CHT");
		else
			strcpy(csLang,"ENG");
		strcat((char*)outMsg,AppendParam("009",csLang));
		iCnt++;
DEBUGLOG(("FormatEnMsg:: language = [%s]\n",csLang));
		FREE_ME(csLang);
        }
        else {
        	iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** language is missing\n"));
	}
/* 010 */
/* currency */
	if (GetField_CString(hIn,"txn_ccy",&csPtr)) {
DEBUGLOG(("FormatEnMsg:: currency = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("010",csPtr));
		iCnt++;
	}
        else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** currency is missing\n"));
	}

/* 011 */
/* NULL */
	strcat((char*)outMsg,AppendParam("011",NULL));
	iCnt++;

/* 012 */
/* NULL */
	strcat((char*)outMsg,AppendParam("012",NULL));
	iCnt++;

/* 014 */
/* success_url */
/* 015 */
/* failure_url */
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
DEBUGLOG(("FormatEnMsg: fe_url = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("014",csPtr));
		iCnt++;
		strcat((char*)outMsg,AppendParam("015",csPtr));
		iCnt++;
	}
	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** fe_url is missing\n"));
	}


/* 016 */
	if (GetField_CString(hIn,"txn_msg",&csPtr)) {
DEBUGLOG(("FormatEnMsg: txn_msg = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("016",csPtr));
		iCnt++;
	}
	else {
       		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** txn_msg is missing\n"));
	}
/* 026 */
/* paymentmethod */
	strcat((char*)outMsg,AppendParam("026","02"));
	iCnt++;

/* 028 */
/* NULL */
	strcat((char*)outMsg,AppendParam("028",NULL));
	iCnt++;

/* 029 */
/* NULL */
	strcat((char*)outMsg,AppendParam("029",NULL));
	iCnt++;

/* 030 */
/* NULL */
	strcat((char*)outMsg,AppendParam("030",NULL));
	iCnt++;
/* 031 */
/* NULL */
	strcat((char*)outMsg,AppendParam("031",NULL));
	iCnt++;

/* 032 */
/* NULL */
	strcat((char*)outMsg,AppendParam("032",NULL));
	iCnt++;

/* 022 */
/* txn_amt */
        if (GetField_CString(hIn,"txn_amt",&csPtr)) {
DEBUGLOG(("FormatEnMsg:: totCash  = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("022",csPtr));
		iCnt++;
        }
        else {
		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** totCash is missing\n"));
	}

/* 023 */
/* tot_token */

	if (GetField_CString(hIn,"tot_token",&csPtr)) {
DEBUGLOG(("FormatEnMsg: tot_token = [%s]\n",csPtr));
		strcat((char*)outMsg,AppendParam("023",csPtr));
		iCnt++;
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatEnMsg:: *** tot_token is missing\n"));
	}


/* 017 */
/* NULL */
	strcat((char*)outMsg,AppendParam("017","0"));
	iCnt++;
	
	unsigned char* csBuf;
	unsigned char* csBuf2;
	csBuf = (unsigned char*) malloc (strlen((const char*)outMsg) * 2+ 1);
	csBuf2 = (unsigned char*) malloc (strlen((const char*)outMsg) * 2+ 1);
	sprintf((char*)csBuf,"%03d%s",iCnt,outMsg);
DEBUGLOG(("FormatEnMsg: msg   = [%d][%s]\n",strlen((char*)csBuf),csBuf));

	strcpy((char*)csBuf2,(char*)attachMsgLenAndCheckSum(csBuf));
DEBUGLOG(("FormatEnMsg: Final = [%d][%s]\n",strlen((char*)csBuf2),csBuf2));

	iRet =  Encrypt((unsigned char*)csKey,strlen(csKey),csBuf2, strlen((char*)csBuf2),outMsg);
	*outLen = strlen((char *)outMsg);
DEBUGLOG(("FormatEnMsg:: outmsg = [%d][%s]\n",*outLen,outMsg));

	FREE_ME(csBuf);
	FREE_ME(csBuf2);

DEBUGLOG(("FormatEnMsg:: iRet = [%d]\n",iRet));
        return  iRet;
}



int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	char	*csPtr = NULL;
DEBUGLOG(("initReplyFromRequest()\n"));
	

	if (GetField_CString(hRequest,"success_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: success_url = [%s]\n",csPtr));
		PutField_CString(hResponse,"success_url",csPtr);
	}

	if (GetField_CString(hRequest,"failure_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: failure_url = [%s]\n",csPtr));
		PutField_CString(hResponse,"failure_url",csPtr);
	}

	if (GetField_CString(hRequest,"success_callback_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: success_callback_url = [%s]\n",csPtr));
		PutField_CString(hResponse,"success_callback_url",csPtr);
	}

	if (GetField_CString(hRequest,"failure_callback_url",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: failure_callback_url = [%s]\n",csPtr));
		PutField_CString(hResponse,"failure_callback_url",csPtr);
	}

	if (GetField_CString(hRequest,"transmission_datetime",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: transmission_datetime = [%s]\n",csPtr));
		PutField_CString(hResponse,"transmission_datetime",csPtr);
	}
	if (GetField_CString(hRequest,"merchant_id",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: merchant_id = [%s]\n",csPtr));
		PutField_CString(hResponse,"merchant_id",csPtr);
	}
	if (GetField_CString(hRequest,"remark",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: remark = [%s]\n",csPtr));
		PutField_CString(hResponse,"remark",csPtr);
	}
	if (GetField_CString(hRequest,"merchant_ref",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: merchant_ref = [%s]\n",csPtr));
		PutField_CString(hResponse,"merchant_ref",csPtr);
	}

	if (GetField_CString(hRequest,"txn_country",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: txn_country = [%s]\n",csPtr));
		PutField_CString(hResponse,"txn_country",csPtr);
	}
	//if (GetField_CString(hRequest,"txn_ccy",&csPtr)) {
//DEBUGLOG(("initReplyFromRequest: txn_ccy = [%s]\n",csPtr));
//		PutField_CString(hResponse,"txn_ccy",csPtr);
//	}
	if (GetField_CString(hRequest,"pay_method",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: pay_method = [%s]\n",csPtr));
		PutField_CString(hResponse,"pay_method",csPtr);
	}
	if (GetField_CString(hRequest,"language",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: language = [%s]\n",csPtr));
		PutField_CString(hResponse,"language",csPtr);
	}
	if (GetField_CString(hRequest,"process_code",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: proces_code = [%s]\n",csPtr));
		PutField_CString(hResponse,"process_code",csPtr);
	}
	if (GetField_CString(hRequest,"encrypt_type",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: encrypt_type = [%s]\n",csPtr));
		PutField_CString(hResponse,"encrypt_type",csPtr);
	}
	if (GetField_CString(hRequest,"txn_amt",&csPtr)) {
DEBUGLOG(("initReplyFromRequest: txn_amt = [%s]\n",csPtr));
		PutField_CString(hResponse,"txn_amt",csPtr);
	}



DEBUGLOG(("initReplyFromRequest() Exit\n"));
	return iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;

	char	*csTag;
	char	*csPtr;
	char	cTmp;
	hash_t	*hRec;
	

	
	hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

	csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

 	if (Str2Cls(hRec,(const char *)inMsg,MY_CCT_TOKEN, MY_CCT_FIELD_TOKEN) == PD_OK) {
/* hard code service_code  */
		PutField_CString(hOut,"service_code",PD_DEFAULT_SERVICE);


/* process type */
		if (GetField_CString(hRec,"process_type",&csPtr)) {
			strcpy(csTag,"process_type");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* process code */
		if (GetField_CString(hRec,"process_code",&csPtr)) {
			strcpy(csTag,"process_code");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* merchant no */
		if (GetField_CString(hRec,"mer_id",&csPtr)) {
			strcpy(csTag,"merchant_id");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* merchant ref */
		if (GetField_CString(hRec,"mer_ref",&csPtr)) {
			strcpy(csTag,"merchant_ref");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* merchant transaction date time */
		if (GetField_CString(hRec,"mer_txn_date",&csPtr)) {
			strcpy(csTag,"transmission_datetime");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));

			char*	csTmp;
			csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);
			memcpy(csTmp,csPtr,PD_DATE_LEN);
			csTmp[PD_DATE_LEN] = '\0';
			strcpy(csTag,"tm_date");
			PutField_CString(hOut,csTag,csTmp);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csTmp));
			memcpy(csTmp,&csPtr[PD_DATE_LEN],PD_TIME_LEN);
			csTmp[PD_TIME_LEN] = '\0';
			strcpy(csTag,"tm_time");
			PutField_CString(hOut,csTag,csTmp);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csTmp));
			FREE_ME(csTmp);
		}
/* pay method */
		if (GetField_CString(hRec,"pay_method",&csPtr)) {
			strcpy(csTag,"pay_method");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* txn amount */
		if (GetField_CString(hRec,"txn_amt",&csPtr)) {
			strcpy(csTag,"txn_amt");
                        PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		} 
/* currency */
		if (GetField_CString(hRec,"ccy",&csPtr)) {
			strcpy(csTag,"txn_ccy");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* country */
		if (GetField_CString(hRec,"country",&csPtr)) {
			strcpy(csTag,"txn_country");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* bank_code */
		if (GetField_CString(hRec,"bank_code",&csPtr)) {
			strcpy(csTag,"bank_code");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* bank_name */
		if (GetField_CString(hRec,"bank_name",&csPtr)) {
			strcpy(csTag,"bank_name");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* branch_name */
		if (GetField_CString(hRec,"branch_name",&csPtr)) {
			strcpy(csTag,"branch_name");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* account_id */
		if (GetField_CString(hRec,"account_id",&csPtr)) {
			strcpy(csTag,"account_id");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* account_name */
		if (GetField_CString(hRec,"account_name",&csPtr)) {
			strcpy(csTag,"account_name");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* identity_id */
		if (GetField_CString(hRec,"identify_id",&csPtr)) {
			strcpy(csTag,"identity_id");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* phone_no */
		if (GetField_CString(hRec,"phone_no",&csPtr)) {
			strcpy(csTag,"phone_no");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* province */
		if (GetField_CString(hRec,"province",&csPtr)) {
			strcpy(csTag,"province");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* batch_id */
		if (GetField_CString(hRec,"batch_id",&csPtr)) {
			strcpy(csTag,"batch_id");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}

/* show paypage */
		if (GetField_CString(hRec,"show_paypage",&csPtr)) {
			strcpy(csTag,"show_paypage");
			cTmp = csPtr[0];
			PutField_Char(hOut,csTag,cTmp);
DEBUGLOG(("BreakDownMsg:[%s] = [%c]\n",csTag,cTmp));
		}
		
/* language */
		if (GetField_CString(hRec,"lang",&csPtr)) {
			strcpy(csTag,"language");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
	
/* success url */
		if (GetField_CString(hRec,"success_url",&csPtr)) {
			strcpy(csTag,"success_url");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* success s2s url */
		if (GetField_CString(hRec,"success_s2s_url",&csPtr)) {
			strcpy(csTag,"success_callback_url");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
	
/* failure url */
		if (GetField_CString(hRec,"failure_url",&csPtr)) {
			strcpy(csTag,"failure_url");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* failure s2s url */
		if (GetField_CString(hRec,"failure_s2s_url",&csPtr)) {
			strcpy(csTag,"failure_callback_url");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* remark */
		if (GetField_CString(hRec,"remark",&csPtr)) {
			strcpy(csTag,"remark");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* echo_msg_1 */
		if (GetField_CString(hRec,"echo_msg_1",&csPtr)) {
			strcpy(csTag,"echo_msg_1");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* echo_msg_2 */
		if (GetField_CString(hRec,"echo_msg_2",&csPtr)) {
			strcpy(csTag,"echo_msg_2");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* echo_msg_3 */
		if (GetField_CString(hRec,"echo_msg_3",&csPtr)) {
			strcpy(csTag,"echo_msg_3");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* mac */
		if (GetField_CString(hRec,"signature",&csPtr)) {
			strcpy(csTag,"mac");
			PutField_CString(hOut,csTag,csPtr);
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* total */
		if (GetField_CString(hRec,"total",&csPtr)) {
			strcpy(csTag,"total");
			PutField_Int(hOut,csTag,ctos((const unsigned char *)csPtr,strlen(csPtr)));
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
		}
/* DATA */
		if (GetField_CString(hRec,"DATA",&csPtr)) {
			strcpy(csTag,"DATA");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hOut,csTag,csPtr);
		}
/* encrypt_type */
		if (GetField_CString(hRec,"enctype",&csPtr)) {
			strcpy(csTag,"encrypt_type");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
			PutField_CString(hOut,csTag,csPtr);
		}
	
/* ip_addr */
		if (GetField_CString(hRec,"ip_addr",&csPtr)) {
                        strcpy(csTag,"ip_addr");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }

/* service_code */
		if (GetField_CString(hRec,"service_code",&csPtr)) {
                        strcpy(csTag,"service_code");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }
/* encrypted order_num */
		if (GetField_CString(hRec,"sessionid",&csPtr)) {
                        strcpy(csTag,"org_encrypted_txn_seq");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
                }
/* verno */
		if (GetField_CString(hRec,"verno",&csPtr)) {
                        strcpy(csTag,"version_no");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
			int iVer;
			iVer = ctos((const unsigned char *)csPtr,strlen(csPtr));
                        PutField_Int(hOut,csTag,iVer);
                }
/* txn_id bounce back */
		if (GetField_CString(hRec,"txn_id",&csPtr)) {
                        strcpy(csTag,"org_txn_seq");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
		}
/* encrypt message */
		if (GetField_CString(hRec,"emsg",&csPtr)) {
                        strcpy(csTag,"emsg");
DEBUGLOG(("BreakDownMsg:[%s] = [%s]\n",csTag,csPtr));
                        PutField_CString(hOut,csTag,csPtr);
		}
	
	
	}

	FREE_ME(csTag);
	FREE_ME(hRec);
	iRet = BuildAuthData(hOut);

DEBUGLOG(("BreakDownMsg = [%d]\n",iRet));;
	return iRet;
}


int BreakDownAckMsg(hash_t *hOut)
{
        int     iRet = PD_OK;
	char	*csMessage;
	char	*csMerchantKey;
	char	*csMerchantID;
	char	csKey[256 +1];;

DEBUGLOG(("BreakDownAckMsg () \n"));

	if (GetField_CString(hOut,"message",&csMessage)) {
DEBUGLOG(("BreakDownAckMsg:message = [%s]\n",csMessage));
	}
	
	if (GetField_CString(hOut,"merchant_key",&csMerchantKey)) {
DEBUGLOG(("BreakDownAckMsg:merchant key = [%s]\n",csMerchantKey));
        }
        else {
                iRet = INT_ERR;
DEBUGLOG(("BreakDownAckMsg: merchant key is missing!!!\n"));
        }

	if (GetField_CString(hOut,"merchant_id",&csMerchantID)) {
DEBUGLOG(("BreakDownAckMsg:merchant id = [%s]\n",csMerchantID));
        }
        else {
                iRet = INT_ERR;
DEBUGLOG(("BreakDownAckMsg: merchant id is missing!!!\n"));
        }
	
	if (iRet == PD_OK) {
		sprintf(csKey,"%sQNE%s%s",KEY_PREFIX,csMerchantID,csMerchantKey);
DEBUGLOG(("BreakDownAckMsg:: KEY = [%s]\n",csKey));
		char	csMsg  [ 1024 * 2 +1 ];
		char	csMsg2 [ 1024 * 2 +1 ];
		char	csChkSum[2 + 1];
		iRet =  Decrypt(csKey,strlen(csKey),csMessage, strlen(csMessage),csMsg);
        	strcpy(csChkSum,(char*)genChecksum((unsigned char*)csMsg,strlen(csMsg) -2));
DEBUGLOG(("BreakDownAckMsg: clear text = [%d][%s]\n",strlen(csMsg),csMsg));
DEBUGLOG(("BreakDownAckMsg: checksum = [%s]\n",csChkSum));
		
		memcpy(csMsg2,&csMsg[4],strlen(csMsg) - 6);
        	csMsg2[strlen(csMsg) - 6] = '\0';
DEBUGLOG(("BreakDownAckMsg: real text = [%d][%s]\n",strlen(csMsg2),csMsg2));
		DeBlockParam(hOut,(const unsigned char*)csMsg2,strlen(csMsg2));
	}


DEBUGLOG(("BreakDownAckMsg: exit = [%d]\n",iRet));
	return iRet;
}

int FormatFEMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
        int     iRet = PD_OK;
        int     iTmp = 0;
        char    *csPtr;
        char    *csBuf;
        char    cStatus;
        char    cPtr;
DEBUGLOG(("FormatFEMsg()\n"));

        csBuf = (char*) malloc (1024 *2 +1);
        memset(csBuf,0,sizeof(csBuf));
        outMsg[0] = '\0';
        if (GetField_Char(hIn,"status",&cStatus)) {
DEBUGLOG(("FormatFEMsg:: status = [%c]\n",cStatus));
        }
        else {
DEBUGLOG(("FormatFEMsg:: status not found\n"));
        }
        if (cStatus == PD_TO_PSP) {
                if (GetField_CString(hIn,"failure_url",&csPtr)) {
                        strcat((char*)outMsg,csPtr);
                }
                strcat((char*)outMsg,"?");
                sprintf(csBuf,"error_code%s%d%s",MY_CCT_FIELD_TOKEN,INT_ACK_NOT_YET_RETURN,MY_CCT_TOKEN);
                strcat((char *)outMsg,csBuf);

                if (GetField_CString(hIn,"merchant_ref",&csPtr)) {
                        strcat((char*)outMsg,"MERORDERID");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csPtr);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
                }

DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));
                if (GetField_CString(hIn,"merchant_id",&csPtr)) {
                        strcat((char*)outMsg,"MERID");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csPtr);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
                }
DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));
                base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
                outMsg[0] = '\0';
                sprintf((char *)outMsg,"status=%c&",cStatus);
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));
                *outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatFEMsg:: ACK not yet return\n"));
                FREE_ME(csBuf);
                return iRet;
        }

        else {
                if (GetField_Char(hIn,"ar_ind",&cPtr)) {
                        if (cPtr == PD_ACCEPT) {
                                if (GetField_CString(hIn,"success_url",&csPtr)) {
                                        strcat((char*)outMsg,csPtr);
                                }
                        }
                        else {
                                if (GetField_CString(hIn,"failure_url",&csPtr)) {
                                        strcat((char*)outMsg,csPtr);
                                }
                        }

DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));
DEBUGLOG(("FormatFEMsg:: response_code = [%d]\n",iTmp));
                }
DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));
                base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
                outMsg[0] = '\0';
                sprintf((char *)outMsg,"status=%c&",cStatus);
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
DEBUGLOG(("FormatFEMsg:: outMsg = [%s]\n",outMsg));


                *outLen = strlen((const char*)outMsg);

                FREE_ME(csBuf);

                return iRet;
        }
}





int DeBlockWebBounceBackData(hash_t *hOut,const char* inMsg, const int inLen)
{
	int 	iRet = PD_OK;
	char*	csBuf;

//	unsigned char buf[PD_MAX_BUFFER + 1]={0};

	csBuf = (char*) malloc (1024 +1);
	memcpy(csBuf,inMsg,inLen);
	csBuf[inLen] = '\0';

DEBUGLOG(("DeBlockBounceBackDATA () [%s]\n",csBuf));

DEBUGLOG(("DeBlockBounceBackData Exit = [%d]\n",iRet));
	return iRet;
}


int BreakDownRespMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
        int     iRet = PD_OK;
        char    *csBuf;
        char    *p;

        csBuf = (char*) malloc (1024 +1);

        memcpy(csBuf,inMsg,inLen);
        csBuf[inLen] = '\0';
DEBUGLOG(("BreakDownRespMsg()\n"));
DEBUGLOG(("DATA = [%s]\n",inMsg));

/* merchantid */
        p = GetField((const unsigned char *)csBuf,"merchantid",MY_CCT_TOKEN,MY_CCT_FIELD_TOKEN);
        if (p) {
                PutField_CString(hOut,"merchantid",p);
DEBUGLOG(("BreakDownRespMsg:: merchantid= [%s]\n",p));
        }
/* message */
        p = GetField((const unsigned char *)csBuf,"message",MY_CCT_TOKEN,MY_CCT_FIELD_TOKEN);
        if (p) {
                PutField_CString(hOut,"message",p);
DEBUGLOG(("BreakDownRespMsg:: message= [%s]\n",p));
        }

        FREE_ME(csBuf);
DEBUGLOG(("BreakDownRespMsg Exit\n"));
        return  iRet;

}

int BuildAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char    *csVal;
        char    *csData;

        csData = (char*) malloc (PD_TMP_BUF_LEN +1);
	csData[0] = '\0';

        if (GetField_CString(hIn,"txn_amt",&csVal)) {
DEBUGLOG(("BuildAuthData txn_amt = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"txn_ccy",&csVal)) {
DEBUGLOG(("BuildAuthData txn_ccy = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_ref",&csVal)) {
DEBUGLOG(("BuildAuthData merchant_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }
/*
        if (GetField_CString(hIn,"merchant_id",&csVal)) {
DEBUGLOG(("BuildAuthData merchant_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }
*/
        if (GetField_CString(hIn,"transmission_datetime",&csVal)) {
DEBUGLOG(("BuildAuthData transmission_datetime = [%s]\n",csVal));
                strcat(csData,csVal);
        }
DEBUGLOG(("BuildAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

	FREE_ME(csData);
        return iRet;
}

int BuildRespAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char    *csVal;
        char    *csData;

        csData = (char*) malloc (PD_TMP_BUF_LEN * 4+1);
	csData[0] = '\0';

        if (GetField_CString(hIn,"response_code",&csVal)) {
DEBUGLOG(("BuildRespAuthData response_code = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"redirect_url",&csVal)) {
DEBUGLOG(("BuildRespAuthData redirect_url = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_ref",&csVal)) {
DEBUGLOG(("BuildRespAuthData merchant_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_id",&csVal)) {
DEBUGLOG(("BuildRespAuthData merchant_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }
DEBUGLOG(("BuildRespAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

DEBUGLOG(("BuildRespAuthData iRet = [%d]\n",iRet));
	FREE_ME(csData);
        return iRet;
}


int FormatAckMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{                               
        int     iRet = PD_OK;
        char*   csBuf;  
        char*   csPtr;  
        char    cStatus;
	char   	csTmp[PD_TMP_BUF_LEN + 1];
	double	dTmp;
        
DEBUGLOG(("FormatAckMsg()\n"));
        outMsg[0]= '\0'; 
        *outLen = 0;
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
                        
                                
        memset(csBuf,0,sizeof(csBuf));
        strcat((char*)csBuf,"url");
        strcat((char*)csBuf,MY_CCT_FIELD_TOKEN);
                        
        if (GetField_Char(hIn,"ar_ind",&cStatus)) {
DEBUGLOG(("FormatAckMsg txn_status = [%c]\n",cStatus));
        }       
        if (cStatus == PD_ACCEPT) {
                if (GetField_CString(hIn,"success_callback_url",&csPtr)) {
                        strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatAckMsg success_callback_url = [%s]\n",csPtr));
                }
        
        }
        else {  
                if (GetField_CString(hIn,"failure_callback_url",&csPtr)) {
                        strcat((char*)csBuf,csPtr);
DEBUGLOG(("FormatAckMsg failure_callback_url = [%s]\n",csPtr));
                }               
        }                       
        strcat((char*)csBuf,MY_CCT_TOKEN);

        sprintf((char *)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
        strcat((char *)outMsg,csBuf);

/*process_type*/
        if (GetField_CString(hIn,"process_type",&csPtr)){
DEBUGLOG(("FormatAckMsg:: process_type = [%s]\n",csPtr));
                strcat((char*)outMsg,"process_type");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: process_type is missing!!!\n"));
	}

/*process_code*/
        if (GetField_CString(hIn,"process_code",&csPtr)){
DEBUGLOG(("FormatAckMsg:: process_code = [%s]\n",csPtr));
                strcat((char*)outMsg,"process_code");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: process_type is missing!!!\n"));
	}

/* status */
        if (GetField_CString(hIn,"response_code",&csPtr)){
DEBUGLOG(("FormatAckMsg:: response code  = [%s]\n",csPtr));
        	strcat((char*)outMsg,"status");
        	strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
        	strcat((char*)outMsg,csPtr);
        	strcat((char*)outMsg,MY_CCT_TOKEN);
	}
	else {
DEBUGLOG(("FormatAckMsg:: response code is missing!!!\n"));
	}

/*txn_seq*/
        if (GetField_CString(hIn,"txn_seq",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_seq = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_id");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: txn_seq is missing!!!\n"));
	}

/*txn_date*/
        if (GetField_CString(hIn,"local_transmission_datetime",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_date = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_date");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: txn_date is missing!!!\n"));
	}

/*net_ccy*/
        if (GetField_CString(hIn,"net_ccy",&csPtr)){
DEBUGLOG(("FormatAckMsg:: net_ccy = [%s]\n",csPtr));
                strcat((char*)outMsg,"net_ccy");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: net_ccy is missing!!!\n"));
	}

/* net_amt */
        if (GetField_Double(hIn,"net_amt",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: NET AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: AMOUNT = [%s]\n",csTmp));
                strcat((char*)outMsg,"net_amt");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }

/* service_fee */
        if (GetField_Double(hIn,"service_fee",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: service_fee AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: service_fee = [%s]\n",csTmp));
                strcat((char*)outMsg,"service_fee");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_CCT_TOKEN);

		if (GetField_CString(hIn,"service_fee_ccy",&csPtr)) {
DEBUGLOG(("FormatAckMsg:: service_fee_ccy = [%s]\n",csPtr));
                	strcat((char*)outMsg,"service_fee_ccy");
                	strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                	strcat((char*)outMsg,csPtr);
                	strcat((char*)outMsg,MY_CCT_TOKEN);
		}
		else {
DEBUGLOG(("FormatAckMsg:: service_fee_ccy is missing!!!\n"));
		}
        }

/* txn_amt */
        if (GetField_Double(hIn,"txn_amt",&dTmp)) {
DEBUGLOG(("FormatAckMsg:: txn amt = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("FormatAckMsg:: txn amt = [%s]\n",csTmp));
                strcat((char*)outMsg,"txn_amt");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,(char*)csTmp);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: txn_amt is missing!!!\n"));
	}

/* txn_ccy */
        if (GetField_CString(hIn,"txn_ccy",&csPtr)){
DEBUGLOG(("FormatAckMsg:: txn_ccy = [%s]\n",csPtr));
                strcat((char*)outMsg,"txn_ccy");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: txn_ccy is missing!!!\n"));
	}



/*merchant_ref*/
        if (GetField_CString(hIn,"merchant_ref",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_ref = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_ref");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: merchant_ref is missing!!!\n"));
	}

/*mer_txn_date*/
        if (GetField_CString(hIn,"transmission_datetime",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_txn_date = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_txn_date");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: mer_txn_date is missing!!!\n"));
	}


/*merchant_id*/
        if (GetField_CString(hIn,"merchant_id",&csPtr)){
DEBUGLOG(("FormatAckMsg:: mer_id = [%s]\n",csPtr));
                strcat((char*)outMsg,"mer_id");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: merchant_id is missing!!!\n"));
	}

/*encrypt_type*/
        if (GetField_CString(hIn,"encrypt_type",&csPtr)){
DEBUGLOG(("FormatAckMsg:: enctype = [%s]\n",csPtr));
                strcat((char*)outMsg,"enctype");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: enctype is missing!!!\n"));
	}

/*sign*/
        if (GetField_CString(hIn,"mac",&csPtr)){
DEBUGLOG(("FormatAckMsg:: SIGN = [%s]\n",csPtr));
                strcat((char*)outMsg,"signature");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: sign is missing!!!\n"));
	}
/* remark */
        if (GetField_CString(hIn,"remark",&csPtr)){
DEBUGLOG(("FormatAckMsg:: remark = [%s]\n",csPtr));
                strcat((char*)outMsg,"remark");
                strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_CCT_TOKEN);
        }
	else {
DEBUGLOG(("FormatAckMsg:: sign is missing!!!\n"));
	}

        *outLen = strlen((const char*)outMsg);


        FREE_ME(csBuf);
DEBUGLOG(("FormatAckMsg:: outMsg = [%s]\n",outMsg));
DEBUGLOG(("FormatAckMsg() Exit iRet = [%d]\n",iRet));
        return  iRet;
}

int BuildAckAuthData(hash_t* hIn)
{
        int     iRet = PD_OK;
        char    *csVal;
        char    *csData;
	double	dTmp;
	

        csData = (char*) malloc (PD_TMP_BUF_LEN +1);
        csData[0] = '\0';

        if (GetField_CString(hIn,"response_code",&csVal)) {
DEBUGLOG(("BuildAckAuthData response_code = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"txn_seq",&csVal)) {
DEBUGLOG(("BuildAckAuthData txn_seq = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"local_transmission_datetime",&csVal)) {
DEBUGLOG(("BuildAckAuthData local_transmission_datetime = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"net_ccy",&csVal)) {
DEBUGLOG(("BuildAckAuthData net_ccy = [%s]\n",csVal));
                strcat(csData,csVal);
        }
	/* net_amt */
        if (GetField_Double(hIn,"net_amt",&dTmp)) {
		char*	csTmp;
		csTmp = (char*) malloc (PD_TMP_BUF_LEN + 1);	

DEBUGLOG(("BuildAckAuthData NET AMOUNT = [%f]\n",dTmp));
                sprintf((char*)csTmp,"%ld",double2long(dTmp));
DEBUGLOG(("BuildAckAuthData net_amt = [%s]\n",csTmp));
                strcat(csData,csTmp);
		FREE_ME(csTmp);
        }

        if (GetField_CString(hIn,"merchant_ref",&csVal)) {
DEBUGLOG(("BuildAckAuthData merchant_ref = [%s]\n",csVal));
                strcat(csData,csVal);
        }
        if (GetField_CString(hIn,"merchant_id",&csVal)) {
DEBUGLOG(("BuildAckAuthData merchant_id = [%s]\n",csVal));
                strcat(csData,csVal);
        }
DEBUGLOG(("BuildRespAuthData = [%s]\n",csData));
        PutField_CString(hIn,"auth_data",csData);

        FREE_ME(csData);
        return iRet;
}


int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
        int     iRet = PD_OK;
        char*   csTmp = NULL;
	char*	csURL;
        char*   csBuf;
        char*   csMethod = NULL;
	int	iIntErr = 0;

        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

        memset(outMsg,0,sizeof(outMsg));

        if (GetField_CString(hIn,"redirect_url",&csURL)) {
/*
		strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,"?");
*/

		strcpy((char*)csBuf,"url");
DEBUGLOG(("FormatMsg:: psp_url = [%s]\n",csURL));
		strcat((char*)csBuf,MY_CCT_FIELD_TOKEN);
                strcat((char*)csBuf,csURL);

		if (GetField_Int(hIn,"internal_error",&iIntErr)) {
DEBUGLOG(("FormatMsg:: internal_error = [%d]\n",iIntErr));
		}
		if (iIntErr == PD_OK) {
			sprintf((char*)outMsg,"%0*d",PD_WEB_HEADER_LEN_LEN,(int)strlen(csBuf));
                	strcat((char*)outMsg,csBuf);
		}
		else {
			char* csTmpStatus;
			csTmpStatus = (char*) malloc (PD_TMP_BUF_LEN +1);
			strcat((char*)outMsg,csURL);
DEBUGLOG(("FormatMsg:: psp_url = [%s]\n",csURL));
       	         	strcat((char*)outMsg,"?");

			sprintf(csTmpStatus,"%d",iIntErr);	
			strcat((char*)outMsg,"status");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmpStatus);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
			FREE_ME(csTmpStatus);
		}


/* merchant_id */
                if (GetField_CString(hIn,"merchant_id",&csTmp)) {
                        strcat((char*)outMsg,"merchantID");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,MY_CCT_TOKEN);
DEBUGLOG(("FormatMsg:: merchant_id = [%s]\n",csTmp));
                }
                else {
                        iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** merchant_id is missing\n"));
                }



/* encrypted message */
                if (GetField_CString(hIn,"emsg",&csTmp)) {
                        strcat((char*)outMsg,"message");
                        strcat((char*)outMsg,MY_CCT_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
DEBUGLOG(("FormatMsg:: redirectto  = [%s]\n",csTmp));
                }
                else {
//                        iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** redirectto is missing\n"));
		}
// url_method
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
                }
		else {
DEBUGLOG(("FormatMsg:: set url_method\n"));
			csMethod = strdup(PD_DEFAULT_METHOD);
		}

		if (GetField_Int(hIn,"internal_error",&iIntErr)) {
DEBUGLOG(("FormatMsg:: internal_error = [%d]\n",iIntErr));
		}

		if (iIntErr != PD_OK ) {
DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));
                	base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
                	outMsg[0] = '\0';
                	strcat((char*)outMsg,"redirect_url");
                	strcat((char*)outMsg,"=");
                	strcat((char*)outMsg,csBuf);
                	strcat((char*)outMsg,MY_CCT_TOKEN);
                	strcat((char*)outMsg,"url_method");
                	strcat((char*)outMsg,"=");
                	strcat((char*)outMsg,csMethod);

			FREE_ME(csMethod);

		}
                *outLen = strlen((const char*)outMsg);
DEBUGLOG(("FormatMsg:: outMsg = [%d][%s]\n",*outLen,outMsg));
        }
        else {
                iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
        }


        FREE_ME(csBuf);
DEBUGLOG(("FormatMsg:: iRet = [%d]\n",iRet));
        return  iRet;
}


int Encrypt(unsigned char* csKey,int iKeyLen,unsigned char* inBuf, int iBuffLen,unsigned char* outBuf) {

        blowfishp_context_t *ctx = (blowfishp_context_t *)malloc(sizeof(blowfishp_context_t));
        if(!ctx) {
ERRLOG("P2xMsg:Encrypt Could not allocate enough memory!\n");
DEBUGLOG(("Encrypt() Could not allocate enough memory!\n"));
                return INT_ERR;
        }
DEBUGLOG(("Encrypt() Key = [%s][%d]\n",csKey,iKeyLen));
        if(blowfishp_initiate(ctx, (unsigned char *)csKey, iKeyLen) == 0) {
DEBUGLOG(("Encrypt() Keys initiated\n"));
                int iLen = iBuffLen;
                iLen = ((iLen + 7 ) /8) * 2;

                char*   csTmp;
                csTmp = (char*) malloc (iLen * 4 +1);

                unsigned int hi = 1, lo = 2;
                int i = 0;
                int j = 0;
                int k = 0;

                for (; i < iLen; i +=2 ) {
                        unsigned int d = 0;
                        if (j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 0;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 8;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 16;

                        if(j < iBuffLen)
                                d |= ((unsigned int)inBuf[j++] & 0xff) << 24;
                        hi = d;

                        if(j < iBuffLen)
                                d = (inBuf[j++] & 0xff) << 0;
                        else
                                d = 0;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= (inBuf[j++] & 0xff) << 24;
                        lo = d;

                        blowfishp_encryptblock(ctx, &hi, &lo);

                        d = hi;
                        csTmp[k++] = (unsigned char)(d >> 0 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 8 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 16 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 24 & 0xff);

                        d = lo;
                        csTmp[k++] = (unsigned char)(d >> 0 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 8 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 16 & 0xff);
                        csTmp[k++] = (unsigned char)(d >> 24 & 0xff);
                }

		memset(outBuf,0,sizeof(outBuf));
                uxencode((char*)outBuf, (unsigned char*)csTmp, k);
		outBuf[k*2] = '\0';
                free(csTmp);

        }else {
ERRLOG("P2xMsg:Encrypt() Error initiating keys\n");
DEBUGLOG(("Encrypt() Error initiating keys\n"));
	}

DEBUGLOG(("Encrypt() Done!\n"));
        free(ctx);
        return 0;
}

int Decrypt(const char* csKey,int iKeyLen,const char* inBuf, int iBuffLen,char* outBuf) {
        blowfishp_context_t *ctx = (blowfishp_context_t *)malloc(sizeof(blowfishp_context_t));
        if(!ctx) {
ERRLOG("P2xMsg:Decrypt Could not allocate enough memory!\n");
DEBUGLOG(("Decrypt Could not allocate enough memory!\n"));
                return -1;
        }
        if(blowfishp_initiate(ctx, (unsigned char *)csKey, iKeyLen) == 0) {
DEBUGLOG(("Decrypt:Keys initiated\n"));
                int iLen = iBuffLen;
                iLen = ((iLen + 7 ) /8) * 2;

                char*   csTmp;
                csTmp = (char*) malloc (iLen * 4 +1);


                uxdecode(csTmp, (unsigned char*)inBuf, iBuffLen);

                unsigned int hi = 1, lo = 2;
                int i = 0;
                int j = 0;
                int k = 0;

                for (; i < iLen; i +=2 ) {
                        int d = 0;
                        if (j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 0;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 24;
                        hi = d;
                        if(j < iBuffLen)
                                d = ((unsigned int)csTmp[j++] & 0xff) << 0;
                        else
                                d = 0;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 8;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 16;
                        if(j < iBuffLen)
                                d |= ((unsigned int)csTmp[j++] & 0xff) << 24;
                        lo = d;

                        blowfishp_decryptblock(ctx, &hi, &lo);

                        d = hi;
                        outBuf[k++] = ((unsigned int)d >> 0 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 8 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 16 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 24 & 0xff);
                        d = lo;
                        outBuf[k++] = ((unsigned int)d >> 0 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 8 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 16 & 0xff);
                        outBuf[k++] = ((unsigned int)d >> 24 & 0xff);
                }

                free(csTmp);

        }else  {
ERRLOG("P2xMsg:Decrypt Error initiating keys\n");
DEBUGLOG(("Decrypt Error initiating keys\n"));
	}

        free(ctx);
DEBUGLOG(("Decrypt: Done!\n"));
        return 0;
}


unsigned char* calcMsgCheckSum(unsigned char* MsgLen, unsigned char* MsgBody, int seed)
{
        int i;
        for(i = 0; i < strlen((const char*) MsgLen);)
            seed ^= MsgLen[i++];

        for(i = 0; i < strlen((const char*)MsgBody);)
            seed ^= MsgBody[i++];

        seed &= 0xff;
        unsigned char* csResult;
        csResult = (unsigned char*) malloc (2 +1);
        csResult[0] = hexchar[(unsigned int)(seed & 0xf0) >> 4];
        csResult[1] = hexchar[seed & 0xf];
	csResult[2] = '\0';
        return csResult;
}


unsigned char* attachMsgLenAndCheckSum(const unsigned char* inBuf)
{
        unsigned char msgLen[] = "0000";
        unsigned char msgCheckSum[] = "00";
        sprintf((char*)msgLen,"%04d",(int)strlen((const char*)inBuf));
        strcpy((char*)msgCheckSum,(const char*)calcMsgCheckSum(msgLen, (unsigned char*) inBuf, 0));

        unsigned char* csTmp;
        csTmp = (unsigned char*) malloc (1024 +1 );
        sprintf((char*)csTmp,"%s%s%s",msgLen,inBuf,msgCheckSum);
        return csTmp;
}
unsigned char* genChecksum(unsigned char* inBuf, int len)
{
        int i = 0;
        int j = 0;
        unsigned char*  csResult;

        csResult = (unsigned char*) malloc ( 2 +1);
        memset(csResult,0,sizeof(csResult));

        for(j = 0; j < len;)
            i ^= inBuf[j++];

        i &= 0xff;

        csResult[0] = hexchar[(unsigned int)(i & 0xf0) >> 4];
        csResult[1] = hexchar[i & 0xf];

        return csResult;
}

void DeBlockParam(hash_t *hOut,const unsigned char* inBuf, int iLen)
{
DEBUGLOG(("DeBlockParam()\n"));
        char    csCnt[3 + 1];
        int     iCnt = 0,i = 0;
        unsigned char* csBuf;
        csBuf = (unsigned char*) malloc (iLen + 1);
        memcpy(csCnt,&inBuf[0],3);
        csCnt[3] = '\0';
        iCnt = atoi(csCnt);
DEBUGLOG(("DeBlockParam: total param = [%d]\n",iCnt));
        memcpy(csBuf,&inBuf[3],iLen -3 );
        printf("buf = [%s]\n",csBuf);
        unsigned char* p;
        p = csBuf;
        for (i = 0; i< iCnt; i++)
                p = ParseIt(hOut,p);

        free(csBuf);
DEBUGLOG(("DeBlockParam() exit\n"));
}

unsigned char* ParseIt(hash_t *hOut,unsigned char* inBuf)
{
        char    csF[3 +1];
        char    csL[3 +1];
        char    *csV;
        int     iLen = 0;
        int     iTotal = 0;
        memcpy(csF,&inBuf[0],3);
        csF[3] = '\0';

        memcpy(csL,&inBuf[3],3);
        csL[3] = '\0';
        iLen = atoi(csL);
        csV = (char*) malloc (iLen +1);
        memcpy(csV,&inBuf[3+3],iLen);
        csV[iLen] = '\0';

DEBUGLOG(("[%s] = [%s]\n",csF,csV));
	if (!strcmp(csF,"004"))
		PutField_CString(hOut,"merchant_ref",csV);
        iTotal = 3 + 3 + iLen;
        inBuf += iTotal;
        return inBuf;
}

int	GetResult(const unsigned char* inBuf, int iLen,unsigned char* outBuf,int* oLen)
{
	char	csResult[] = "SUCCESS";
	char	*p;
	int	iRet = PD_OK;
	char	*csBuf;
DEBUGLOG(("GetResult [%d][%s]\n",iLen,inBuf));

	csBuf = (char*) malloc (iLen + 1);
	strcpy(csBuf,(const char*)inBuf);

	p = strtok(csBuf,"|");
	if (p != NULL)
        {
		if (!memcmp(p,csResult,strlen(csResult))) {
			p = strtok(NULL,"|");
			strcpy((char*)outBuf,p);
			*oLen = strlen((char*)outBuf);
DEBUGLOG(("p = [%d][%s]\n",*oLen,outBuf));
		}
		else {
			iRet = INT_ERR;
		}
	}

	FREE_ME(csBuf);
	return	iRet;
}
