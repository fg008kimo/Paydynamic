/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2012/09/20              Cody Chan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "IpyMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"

char	cDebug;

void	IpyMsg(char cdebug)
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

/*  merchantId */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"MerchantCode");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: merchantId = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}
/*  paymentId */
		strcat((char*)outMsg,"PaymentId");
		strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
		strcat((char*)outMsg,MY_IPY_MAYBANK2U); //maybank2u (MYR)
		strcat((char*)outMsg,MY_IPY_TOKEN);

/* txn_seq */

		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"RefNo");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: txn_seq = [%s]\n",csTmp));
		}

/* Amount */
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			strcpy(csTmpAmt,commaprintdouble(dTmp,PD_DECIMAL_LEN));
			strcat((char*)outMsg,"Amount");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: psp_txn_amount = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}

/* Currency */
		if (GetField_CString(hIn,"psp_txn_ccy",&csTmp)) {
			strcat((char*)outMsg,"Currency");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: psp_txn_ccy = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_ccy is missing!!!\n"));
		}

/* prod_desc */
		strcat((char*)outMsg,"ProdDesc");
		strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
		//strcat((char*)outMsg,"Product");
		strcat((char*)outMsg,"FREE/ZERO");
		strcat((char*)outMsg,MY_IPY_TOKEN);

/* customer_name */
		if (GetField_CString(hIn,"customer_name",&csTmp)) {
			strcat((char*)outMsg,"UserName");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg," ");
			if (GetField_CString(hIn,"customer_family_name",&csTmp)) {
				strcat((char*)outMsg,csTmp);
			}
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: customer_name = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: customer_name is missing!!!\n"));
		}

/* customer_email */
		if (GetField_CString(hIn,"customer_email",&csTmp)) {
			strcat((char*)outMsg,"UserEmail");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: customer_email = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: customer_email is missing!!!\n"));
		}
/* customer_tel */
		if (GetField_CString(hIn,"customer_tel",&csTmp)) {
			strcat((char*)outMsg,"UserContact");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: customer_tel = [%s]\n",csTmp));
		}
		else {
DEBUGLOG(("FormatMsg:: customer_tel is missing!!!\n"));
		}
/* remark */
		if (GetField_CString(hIn,"remark",&csTmp)) {
			strcat((char*)outMsg,"Remark");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: remark = [%s]\n",csTmp));
		}
/* language */
		if (GetField_CString(hIn,"language",&csTmp)) {
			strcat((char*)outMsg,"Lang");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp); 
			strcat((char*)outMsg,MY_IPY_TOKEN);
		}

/* sign */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"Signature");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: sign = [%s]\n",csTmp));
		}

/* fe_url */
		if (GetField_CString(hIn,"fe_url",&csTmp)) {
		//if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"ResponseURL");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: fe_url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** fe_url is missing\n"));
		}
/* return_url */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"BackendURL");
			strcat((char*)outMsg,MY_IPY_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_IPY_TOKEN);
DEBUGLOG(("FormatMsg:: receiveUrl = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
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
                strcat((char*)outMsg,MY_IPY_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_IPY_TOKEN);
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

	if (Str2Cls(hRec,(char *)inMsg,MY_IPY_TOKEN, MY_IPY_FIELD_TOKEN) == PD_OK) {

/* merchant_id */
		if (GetField_CString(hRec,"MerchantCode",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: merchant_id = [%s]\n",csPtr));
			PutField_CString(hOut,"merchant_id",csPtr);
		}
/* payment_id */
		if(GetField_CString(hRec,"PaymentId",&csPtr)){
			PutField_CString(hOut,"payment_id",csPtr);
DEBUGLOG(("BreakDownMsg:: payment_id = [%s]\n",csPtr));
		}
/* txn_seq */
		if (GetField_CString(hRec,"RefNo",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
		}

/* txn_amt */
		if (GetField_CString(hRec,"Amount",&csPtr)) {
			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			strcpy(csTmpAmt,TrimAllChar((const unsigned char *)csPtr,strlen(csPtr),','));
			PutField_CString(hOut,"txn_amt",csTmpAmt);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
		}

/* psp_txn_ccy */
		if (GetField_CString(hRec,"Currency",&csPtr)) {
			PutField_CString(hOut,"psp_txn_ccy",csPtr);
DEBUGLOG(("BreakDownMsg:: psp_txn_ccy = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: psp_txn_ccy not found\n"));
		}
/* Remark */
		if (GetField_CString(hRec,"Remark",&csPtr)) {
			PutField_CString(hOut,"remark",csPtr);
DEBUGLOG(("BreakDownMsg:: remark = [%s]\n",csPtr));
		}


/* tid */
		if (GetField_CString(hRec,"TransId",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}

/* bank_bill_no */
		if (GetField_CString(hRec,"AuthCode",&csPtr)) {
			PutField_CString(hOut,"bank_bill_no",csPtr);
DEBUGLOG(("BreakDownMsg:: bank_bill_no = [%s]\n",csPtr));
		}

/* status */
		if (GetField_CString(hRec,"Status",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}
/* error_desc */
		if (GetField_CString(hRec,"ErrDesc",&csPtr)) {
			PutField_CString(hOut,"error_desc",csPtr);
DEBUGLOG(("BreakDownMsg:: error_desc = [%s]\n",csPtr));
		}

/* sig */
                if (GetField_CString(hRec,"Signature",&csPtr)) {
                        PutField_CString(hOut,"sign",csPtr);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n",csPtr));
                }
                else{
DEBUGLOG(("BreakDownMsg:: sign not found\n"));
                }

/* fundin datetime use PH date */
		char csDateTime[PD_DATETIME_LEN+1];
		char csDate[PD_DATE_LEN+1];
		
		strcpy(csDateTime,getdatetime());
		sprintf(csDate,"%.*s",PD_DATE_LEN,csDateTime);
		PutField_CString(hOut,"fundin_date",csDateTime);
		PutField_CString(hOut,"txn_date",csDate);


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
	


/* merchant_id */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: merchantId = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* txn_seq */

	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: orderNo = [%s]\n",csPtr));
	}

/* psp_txn_amt */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

		char    csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf(csTmpAmt,"%ld",(long)(((dTmp*200)+1)/2));
		strcat((char*)csBuf,csTmpAmt);
DEBUGLOG(("BuildAuthData:: orderAmount = [%s]\n",csTmpAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
	}

/* psp_txn_ccy */
	if (GetField_CString(hIn,"psp_txn_ccy",&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildAuthData:: Currency = [%s]\n",csPtr));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_ccy is missing!!!\n"));
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

DEBUGLOG(("BuildRspAuthData()\n"));
	memset(csBuf,0,MAX_MSG_SIZE);
	csBuf[0] = '\0';
	


/* merchant_id */
	strcpy(csTag,"psp_merchant_id");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: [%s] = [%s]\n",csTag,csPtr));
	}
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* payment_id */
	strcpy(csTag,"payment_id");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}

/* txn_seq */
	strcpy(csTag,"txn_seq");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}


/* txn_amt */
        strcpy(csTag,"txn_amt");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
        }
	else {
		iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}

/* txn_ccy*/
        strcpy(csTag,"psp_txn_ccy");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
        }

/* status */
	strcpy(csTag,"status");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,csPtr);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
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

