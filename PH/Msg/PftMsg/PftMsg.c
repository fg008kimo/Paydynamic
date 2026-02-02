/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2013/12/09              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PftMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"

char	cDebug;

void	PftMsg(char cdebug)
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
		strcat((char *)outMsg,"?r=apik/pay");
		strcat((char*)outMsg,MY_PFT_TOKEN);


/* 1 backendUrl*/
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"backendUrl");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: backendUrl = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}


/* 2 orderNumber*/

		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"orderNumber");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: orderNumber = [%s]\n",csTmp));
		}

/* 3 frontendUrl */
		if (GetField_CString(hIn,"fe_url_only",&csTmp)) {
			strcat((char*)outMsg,"frontendUrl");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: frontendUrl = [%s]\n",csTmp));
		}


/* 4 orderAmount*/
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
			strcat((char*)outMsg,"orderAmount");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: orderAmount = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}

/* 5 orderTime */
		if (GetField_CString(hIn,"local_tm_date",&csTmp)) {
DEBUGLOG(("FormatMsg:: local_tm_date = [%s]\n",csTmp));
                        char*   csPtr2;
                        char    csDateTime[PD_DATETIME_LEN * 2];
                        if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("FormatMsg:: local_tm_time = [%s]\n",csPtr2));
                                sprintf(csDateTime,"%s%s",csTmp,csPtr2);
DEBUGLOG(("FormatMsg:: orderDatetime = [%s]\n",csDateTime));
                                strcat((char*)outMsg,"orderTime");
                                strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
                                strcat((char*)outMsg,csDateTime);
                                strcat((char*)outMsg,MY_PFT_TOKEN);
                        }
                        else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                        }
                }
                else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
                }

/* 6 bankId */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"bankId");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: bankId = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: bank_code is missing!!!\n"));
		}

/* 7 merchantId */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"merchantId");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: merchantId = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}


/* 8 signMsg */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"signMsg");
			strcat((char*)outMsg,MY_PFT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_PFT_TOKEN);
DEBUGLOG(("FormatMsg:: signMsg = [%s]\n",csTmp));
		}

/* url_method */
                if (GetField_CString(hIn,"url_method",&csMethod)) {
DEBUGLOG(("FormatMsg:: url_method = [%s]\n",csMethod));
                }

DEBUGLOG(("FormatMsg:: outmsg = [%s]\n",outMsg));
		base64_encode(outMsg,strlen((char *)outMsg),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: after encode\n"));
                outMsg[0] = '\0';
                strcat((char*)outMsg,"redirect_url");
                strcat((char*)outMsg,"=");
                strcat((char*)outMsg,csBuf);
                strcat((char*)outMsg,MY_PFT_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_PFT_TOKEN);
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

	if (Str2Cls(hRec,(char *)inMsg,MY_PFT_TOKEN, MY_PFT_FIELD_TOKEN) == PD_OK) {

/* 1 transType*/
		if (GetField_CString(hRec,"transType",&csPtr)) {
			PutField_CString(hOut,"trans_type",csPtr);
DEBUGLOG(("BreakDownMsg:: trans_type = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: trans_type not found\n"));
		}

/* 2 status*/
		if (GetField_CString(hRec,"status",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}

/* 3 paymentId */
		if (GetField_CString(hRec,"paymentId",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
		}

/* 4 orderNumber */
		if (GetField_CString(hRec,"orderNumber",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
		}

/* 5 payTime*/
		if (GetField_CString(hRec,"payTime",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_date = [%s]\n",csPtr));
			csPtr[PD_DATETIME_LEN] = '\0';
                        char csTxnDate[PD_DATE_LEN +1];
			sprintf(csTxnDate,"%.*s",PD_DATE_LEN,csPtr);

			PutField_CString(hOut,"fundin_date",csPtr);
			PutField_CString(hOut,"txn_date",csTxnDate);
		}

/* 6 orderAmount */
		if (GetField_CString(hRec,"orderAmount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
		}

/* 7 payAmount */
		if (GetField_CString(hRec,"payAmount",&csPtr)) {
			PutField_CString(hOut,"pay_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: pay_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: pay_amt not found\n"));
		}

/* 8 signMsg*/
                if (GetField_CString(hRec,"signMsg",&csPtr)) {
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
	

/* 1 backendUrl*/
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"backendUrl=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: backendUrl = [%s]\n",csPtr));
	}

/* 2 orderNumber*/
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"orderNumber=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: orderNumber = [%s]\n",csPtr));
	}

/* 3 frontendUrl */
	if (GetField_CString(hIn,"fe_url_only",&csPtr)) {
		strcat((char*)csBuf,"frontendUrl=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: frontendUrl = [%s]\n",csPtr));
	}

/* 4 orderAmount*/
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char    csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
		strcat((char*)csBuf,"orderAmount=");
		strcat((char*)csBuf,csTmpAmt);
DEBUGLOG(("BuildAuthData:: orderAmount = [%s]\n",csTmpAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
	}

/* 5 orderTime */
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildAuthData:: local_tm_date = [%s]\n",csPtr));
		char*   csPtr2;
		char    csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("BuildAuthData:: local_tm_time = [%s]\n",csPtr2));
			sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("BuildAuthData:: orderDatetime = [%s]\n",csDateTime));
			strcat((char*)csBuf,"orderTime=");
			strcat((char*)csBuf,csDateTime);
		}
		else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing!!!\n"));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing!!!\n"));
	}

/* 6 bankId */
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		strcat((char*)csBuf,"bankId=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: bankId = [%s]\n",csPtr));
	}

/* 7 merchantId */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,"merchantId=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: merchantId = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

	strcat((char*)csBuf,"key=");
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

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';
	

/* 1 transType*/
	if (GetField_CString(hIn,"trans_type",&csPtr)) {
		strcat((char*)csBuf,"transType=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: transType = [%s]\n",csPtr));
	}

/* 2 status*/
	if (GetField_CString(hIn,"status",&csPtr)) {
		strcat((char*)csBuf,"status=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: status = [%s]\n",csPtr));
	}

/* 3 paymentId */
	if (GetField_CString(hIn,"tid",&csPtr)) {
		strcat((char*)csBuf,"paymentId=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: paymentId = [%s]\n",csPtr));
	}

/* 4 orderNumber */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"orderNumber=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: orderNumber = [%s]\n",csPtr));
	}

/* 5 payTime*/
	if (GetField_CString(hIn,"fundin_date",&csPtr)) {
		strcat((char*)csBuf,"payTime=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: payTime = [%s]\n",csPtr));
	}

/* 6 orderAmount */
	if (GetField_CString(hIn,"txn_amt",&csPtr)) {
		strcat((char*)csBuf,"orderAmount=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: orderAmount = [%s]\n",csPtr));
	}

/* 7 payAmount */
	if (GetField_CString(hIn,"pay_amt",&csPtr)) {
		strcat((char*)csBuf,"payAmount=");
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: payAmount = [%s]\n",csPtr));
	}

	strcat((char*)csBuf,"key=");

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
