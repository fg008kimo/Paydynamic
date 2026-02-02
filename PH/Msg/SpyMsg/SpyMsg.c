/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2012/04/02              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "SpyMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"

char	cDebug;

void	SpyMsg(char cdebug)
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

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char *)outMsg,csPtr);
		strcat((char *)outMsg,"?");

/* Name */
		strcat((char*)outMsg,"Name");
		strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
		strcat((char*)outMsg,"B2CPayment");
		strcat((char*)outMsg,MY_SPY_TOKEN);

/* Version */
		strcat((char*)outMsg,"Version");
		strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
		strcat((char*)outMsg,MY_SPY_VERSION); 
		strcat((char*)outMsg,MY_SPY_TOKEN);

/* Charset */
		strcat((char*)outMsg,"Charset");
		strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
		strcat((char*)outMsg,"UTF-8"); //UTF-8
		strcat((char*)outMsg,MY_SPY_TOKEN);

/* MsgSender */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"MsgSender");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: merchantId = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

/* SendTime */
	        if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("FormatMsg:: local_tm_date = [%s]\n",csPtr));
                	char*   csPtr2;
                	char    csDateTime[PD_DATETIME_LEN * 2];
                	if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("FormatMsg:: local_tm_time = [%s]\n",csPtr2));
                        	sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("FormatMsg:: orderDatetime = [%s]\n",csDateTime));
                        	strcat((char*)outMsg,"SendTime");
                        	strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
                        	strcat((char*)outMsg,csDateTime);
                        	strcat((char*)outMsg,MY_SPY_TOKEN);
                	}
                	else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                	}
        	}
        	else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
        	}

/* OrderNo */
		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"OrderNo");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: OrderNo = [%s]\n",csTmp));
		}

/* OrderAmount */
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf(csTmpAmt,"%.2f",dTmp);
			strcat((char*)outMsg,"OrderAmount");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: orderAmount = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}

/* OrderTime */
                if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("FormatMsg:: local_tm_date = [%s]\n",csPtr));
                        char*   csPtr2;
                        char    csDateTime[PD_DATETIME_LEN * 2];
                        if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("FormatMsg:: local_tm_time = [%s]\n",csPtr2));
                                sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("FormatMsg:: orderDatetime = [%s]\n",csDateTime));
                                strcat((char*)outMsg,"OrderTime");
                                strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
                                strcat((char*)outMsg,csDateTime);
                                strcat((char*)outMsg,MY_SPY_TOKEN);
                        }
                        else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                        }
                }
                else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
                }

/* PayType */
		strcat((char*)outMsg,"PayType");
		strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
		strcat((char*)outMsg,"PT001");
		strcat((char*)outMsg,MY_SPY_TOKEN);

/* InstCode */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"InstCode");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: issuerId = [%s]\n",csTmp));
		}

/* PageUrl */
		if (GetField_CString(hIn,"fe_url",&csTmp)) {
		//if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"PageUrl");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: PageUrl = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** fe_url is missing\n"));
		}
/* NotifyUrl */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"NotifyUrl");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: NotifyUrl = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

		
/* SignType */
		strcat((char*)outMsg,"SignType");
		strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
		strcat((char*)outMsg,"MD5");
		strcat((char*)outMsg,MY_SPY_TOKEN);


/* SignMsg */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"SignMsg");
			strcat((char*)outMsg,MY_SPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_SPY_TOKEN);
DEBUGLOG(("FormatMsg:: SignMsg = [%s]\n",csTmp));
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
                strcat((char*)outMsg,MY_SPY_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_SPY_TOKEN);
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
        char    csTxnDate[PD_DATE_LEN+1];
	hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char *)inMsg,MY_SPY_TOKEN, MY_SPY_FIELD_TOKEN) == PD_OK) {

/* Name */
		if (GetField_CString(hRec,"Name",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: name = [%s]\n",csPtr));
			PutField_CString(hOut,"name",csPtr);
		}
/* Version */
		if (GetField_CString(hRec,"Version",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: version = [%s]\n",csPtr));
			PutField_CString(hOut,"version",csPtr);
		}
/* language */
		if (GetField_CString(hRec,"Charset",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: language = [%s]\n",csPtr));
			PutField_CString(hOut,"language",csPtr);
		}
/* TraceNo */
		if (GetField_CString(hRec,"TraceNo",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: traceno = [%s]\n",csPtr));
			PutField_CString(hOut,"traceno",csPtr);
		}
/* MsgSender */
		if (GetField_CString(hRec,"MsgSender",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: msg_sender = [%s]\n",csPtr));
			PutField_CString(hOut,"msg_sender",csPtr);
		}
/* SendTime */
		if (GetField_CString(hRec,"SendTime",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: send_time = [%s]\n",csPtr));
			PutField_CString(hOut,"send_time",csPtr);
		}
/* InstCode */
		if (GetField_CString(hRec,"InstCode",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: bank_code = [%s]\n",csPtr));
			PutField_CString(hOut,"bank_code",csPtr);
		}

/* OrderNo */
		if (GetField_CString(hRec,"OrderNo",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
		}

/* OrderAmount */
		if (GetField_CString(hRec,"OrderAmount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
		}
/* TransNo */
		if (GetField_CString(hRec,"TransNo",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
		}
/* TransAmount */
		if (GetField_CString(hRec,"TransAmount",&csPtr)) {
			PutField_CString(hOut,"payAmount",csPtr);
DEBUGLOG(("BreakDownMsg:: payAmount = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: payAmount not found\n"));
		}
/* TransStatus */
		if (GetField_CString(hRec,"TransStatus",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}
/* TransType */
		if (GetField_CString(hRec,"TransType",&csPtr)) {
			PutField_CString(hOut,"trans_type",csPtr);
DEBUGLOG(("BreakDownMsg:: trans_type = [%s]\n",csPtr));
		}

/* TransTime */
                if (GetField_CString(hRec,"TransTime",&csPtr)) {
                        PutField_CString(hOut,"fundin_date",csPtr);
DEBUGLOG(("BreakDownMsg:: TransTime:fundin_date = [%s]\n",csPtr));

                        strcpy(csTxnDate,csPtr);
                        csTxnDate[PD_DATE_LEN]='\0';
                        PutField_CString(hOut,"txn_date",csTxnDate);
DEBUGLOG(("BreakDownMsg:: TransTime:txn_date = [%s]\n",csTxnDate));
                }
                else{
DEBUGLOG(("BreakDownMsg:: TransTime:fundin_date not found\n"));
                }
/* MerchantNo */
		if (GetField_CString(hRec,"MerchantNo",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: merchantId = [%s]\n",csPtr));
			PutField_CString(hOut,"merchant_id",csPtr);
		}
/* ErrorCode */
		if (GetField_CString(hRec,"ErrorCode",&csPtr)) {
			PutField_CString(hOut,"error_code",csPtr);
DEBUGLOG(("BreakDownMsg:: error_code = [%s]\n",csPtr));
		}
/* ErrorMsg */
		if (GetField_CString(hRec,"ErrorMsg",&csPtr)) {
			PutField_CString(hOut,"error_msg",csPtr);
DEBUGLOG(("BreakDownMsg:: error_msg = [%s]\n",csPtr));
		}
/* Ext1 */
		if (GetField_CString(hRec,"Ext1",&csPtr)) {
			PutField_CString(hOut,"ext1",csPtr);
DEBUGLOG(("BreakDownMsg:: ext1 = [%s]\n",csPtr));
		}

/* SignType */
		if (GetField_CString(hRec,"SignType",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: signType = [%s]\n",csPtr));
			PutField_CString(hOut,"sign_type",csPtr);
		}
/* signMsg */
                if (GetField_CString(hRec,"SignMsg",&csPtr)) {
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
        csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );

DEBUGLOG(("BuildAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';
	


/* Name */
        strcat(csBuf,"B2CPayment");

/* Version */
        strcat(csBuf,MY_SPY_VERSION);

/* Charset */
        strcat(csBuf,"UTF-8");

/* MsgSender */
       	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
        	strcat(csBuf,csPtr);
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_merchant_is is missing!!!\n"));
	}

/* SendTime */
        if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildAuthData:: local_tm_date = [%s]\n",csPtr));
		char*   csPtr2;
                char    csDateTime[PD_DATETIME_LEN * 2];
                if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("BuildAuthData:: local_tm_time = [%s]\n",csPtr2));
               		sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("BuildAuthData:: orderDatetime = [%s]\n",csDateTime));
                        strcat(csBuf,csDateTime);
		}
               else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing!!!\n"));
                        }
        }
       	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing!!!\n"));
        }

/* OrderNo */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
       		strcat(csBuf,csPtr);
	}
	else {
DEBUGLOG(("BuildAuthData:: txn_seq is missing!!!\n"));
	}

/* OrderAmount */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char    csTmpAmt[PD_TMP_BUF_LEN +1];
                sprintf(csTmpAmt,"%.2f",dTmp);
                strcat(csBuf,csTmpAmt);
DEBUGLOG(("BuildAuthData:: orderAmount = [%s]\n",csTmpAmt));
        }
        else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
        }

/* OrderTime */
        if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildAuthData:: local_tm_date = [%s]\n",csPtr));
        	char*   csPtr2;
                char    csDateTime[PD_DATETIME_LEN * 2];
                if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("BuildAuthData:: local_tm_time = [%s]\n",csPtr2));
                	sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("BuildAuthData:: orderDatetime = [%s]\n",csDateTime));
                                strcat(csBuf,csDateTime);
		}
                else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing!!!\n"));
                }
	}
        else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing!!!\n"));
        }

/* PayType */
	strcat(csBuf,"PT001");

/* InstCode */
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: bank_code = [%s]\n",csPtr));
	}

/* PageUrl */
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
	//if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: PageUrl = [%s]\n",csPtr));
        }
        else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** fe_url is missing\n"));
	}

/* NotifyUrl */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
        	strcat(csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: NotifyUrl = [%s]\n",csPtr));
	}
        else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** return_url_only is missing\n"));
	}


/* SignType */
        strcat(csBuf,"MD5");

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

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';
	

/* name */
	strcpy(csTag,"name");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* version */
	strcpy(csTag,"version");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* language */
	strcpy(csTag,"language");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* traceno */
	strcpy(csTag,"traceno");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* msg_sender */
	strcpy(csTag,"msg_sender");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* sendtime */
	strcpy(csTag,"send_time");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* bank_code */
	strcpy(csTag,"bank_code");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}
/* txn_seq */
	strcpy(csTag,"txn_seq");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* txn_amt */
	strcpy(csTag,"txn_amt");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* tid */
	strcpy(csTag,"tid");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* payAmount */
	strcpy(csTag,"payAmount");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* status */
	strcpy(csTag,"status");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* trans_type */
	strcpy(csTag,"trans_type");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}


/* fundin_date */
	strcpy(csTag,"fundin_date");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* merchant_id */
	strcpy(csTag,"merchant_id");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* error_code */
	strcpy(csTag,"error_code");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}

/* error_msg */
	strcpy(csTag,"error_msg");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}

/* ext1 */
	strcpy(csTag,"rror_msg");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}


/* sign_type */
	strcpy(csTag,"sign_type");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat(csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
