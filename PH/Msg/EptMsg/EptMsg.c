/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2014/06/30              LokMan Chow
Support Unipay Mobile				   2015/04/17		   LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EptMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"

char	cDebug;
OBJPTR(DB);


void	EptMsg(char cdebug)
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
		strcat((char*)outMsg,MY_EPT_TOKEN);


/* 0 version*/
		strcat((char*)outMsg,"version");
		strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
		strcat((char*)outMsg,"1.0");
		strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: version = [1.0]\n"));
		
/* 1 sign_type */
		strcat((char*)outMsg,"sign_type");
		strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
		strcat((char*)outMsg,"MD5");
		strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: version = [MD5]\n"));


/* 2 mid */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"mid");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: mid = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

/* 3 return_url */
		if (GetField_CString(hIn,"fe_url",&csTmp)) {
			strcat((char*)outMsg,"return_url");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: return_url = [%s]\n",csTmp));
		}

/* 4 notify_url*/
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"notify_url");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: notify_url = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

/* 5 order_id*/

		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"order_id");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: order_id = [%s]\n",csTmp));
		}

/* 6 order_amount*/
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
			strcat((char*)outMsg,"order_amount");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_EPT_TOKEN);
DEBUGLOG(("FormatMsg:: order_amount = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}

/* 7 order_time */
		if (GetField_CString(hIn,"local_tm_date",&csTmp)) {
DEBUGLOG(("FormatMsg:: local_tm_date = [%s]\n",csTmp));
                        char*   csPtr2;
                        char    csDateTime[PD_DATETIME_LEN * 2];
                        if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("FormatMsg:: local_tm_time = [%s]\n",csPtr2));
                                sprintf(csDateTime,"%s%s",csTmp,csPtr2);
DEBUGLOG(("FormatMsg:: orderDatetime = [%s]\n",csDateTime));
                                strcat((char*)outMsg,"order_time");
                                strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
                                strcat((char*)outMsg,csDateTime);
                                strcat((char*)outMsg,MY_EPT_TOKEN);
                        }
                        else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                        }
                }
                else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
                }

/* 8 bank_id */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"bank_id");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
			int iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if(iOpt==PD_FALSE && iOpt!=INT_ERR){
				strcat((char*)outMsg,csTmp);
DEBUGLOG(("FormatMsg:: bank_id = [%s]\n",csTmp));
			}
			strcat((char*)outMsg,MY_EPT_TOKEN);
		}
		else {
DEBUGLOG(("FormatMsg:: bank_code is missing!!!\n"));
		}


/* 9 signature */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"signature");
			strcat((char*)outMsg,MY_EPT_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_EPT_TOKEN);
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
                strcat((char*)outMsg,MY_EPT_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_EPT_TOKEN);
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

	if (Str2Cls(hRec,(char *)inMsg,MY_EPT_TOKEN, MY_EPT_FIELD_TOKEN) == PD_OK) {

/* 1 order_id*/
		if (GetField_CString(hRec,"order_id",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
		}

/* 2 order_time*/
		if (GetField_CString(hRec,"order_time",&csPtr)) {
			PutField_CString(hOut,"order_time",csPtr);
DEBUGLOG(("BreakDownMsg:: order_time = [%s]\n",csPtr));
		}

/* 3 order_amount */
		if (GetField_CString(hRec,"order_amount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
		}

/* 4 deal_id */
		if (GetField_CString(hRec,"deal_id",&csPtr)) {
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg:: tid = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: tid not found\n"));
		}

/* 5 deal_time*/
		if (GetField_CString(hRec,"deal_time",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: txn_date = [%s]\n",csPtr));
			csPtr[PD_DATETIME_LEN] = '\0';
                        char csTxnDate[PD_DATE_LEN +1];
			sprintf(csTxnDate,"%.*s",PD_DATE_LEN,csPtr);

			PutField_CString(hOut,"fundin_date",csPtr);
			PutField_CString(hOut,"txn_date",csTxnDate);
		}

/* 6 pay_amount */
		if (GetField_CString(hRec,"pay_amount",&csPtr)) {
			PutField_CString(hOut,"pay_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: pay_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: pay_amt not found\n"));
		}

/* 7 pay_result*/
		if (GetField_CString(hRec,"pay_result",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}

/* 8 signature*/
                if (GetField_CString(hRec,"signature",&csPtr)) {
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
	
/*version*/
	strcat((char*)csBuf,"version=");
	strcat((char*)csBuf,"1.0");
	strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);

/*sign_type*/
	strcat((char*)csBuf,"sign_type=");
	strcat((char*)csBuf,"MD5");
	strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);

/* 2 mid */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,"mid=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: mid = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* 3 return_url */
	if (GetField_CString(hIn,"fe_url",&csPtr)) {
		strcat((char*)csBuf,"return_url=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: return_url = [%s]\n",csPtr));
	}

/* 4 notify_url*/
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"notify_url=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: notify_url = [%s]\n",csPtr));
	}

/* 5 order_id*/
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"order_id=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: order_id = [%s]\n",csPtr));
	}

/* 6 order_amount*/
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {
		char    csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf((char*)csTmpAmt,"%ld",double2long(dTmp));
		strcat((char*)csBuf,"order_amount=");
		strcat((char*)csBuf,csTmpAmt);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: order_amount = [%s]\n",csTmpAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
	}

/* 7 order_time */
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
DEBUGLOG(("BuildAuthData:: local_tm_date = [%s]\n",csPtr));
		char*   csPtr2;
		char    csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
DEBUGLOG(("BuildAuthData:: local_tm_time = [%s]\n",csPtr2));
			sprintf(csDateTime,"%s%s",csPtr,csPtr2);
DEBUGLOG(("BuildAuthData:: orderDatetime = [%s]\n",csDateTime));
			strcat((char*)csBuf,"order_time=");
			strcat((char*)csBuf,csDateTime);
			strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
		}
		else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing!!!\n"));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing!!!\n"));
	}

/* 8 bank_id */
	if (GetField_CString(hIn,"bank_code",&csPtr)) {
		DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
		int iOpt = (unsigned long)(*DBObjPtr)(csPtr);
		if(iOpt==PD_FALSE && iOpt!=INT_ERR){
			strcat((char*)csBuf,"bank_id=");
			strcat((char*)csBuf,csPtr);
			strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildAuthData:: bank_id = [%s]\n",csPtr));
		}
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
	

/* 1 order_id */
	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"order_id=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_id = [%s]\n",csPtr));
	}

/* 2 order_time*/
	if (GetField_CString(hIn,"order_time",&csPtr)) {
		strcat((char*)csBuf,"order_time=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_time = [%s]\n",csPtr));
	}

/* 3 order_amount */
	if (GetField_CString(hIn,"txn_amt",&csPtr)) {
		strcat((char*)csBuf,"order_amount=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: order_amount = [%s]\n",csPtr));
	}

/* 4 deal_id*/
	if (GetField_CString(hIn,"tid",&csPtr)) {
		strcat((char*)csBuf,"deal_id=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: deal_id = [%s]\n",csPtr));
	}

/* 5 deal_time*/
	if (GetField_CString(hIn,"fundin_date",&csPtr)) {
		strcat((char*)csBuf,"deal_time=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: deal_time = [%s]\n",csPtr));
	}
	else{
		strcat((char*)csBuf,"deal_time=");
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: deal_time is NULL\n"));
	}

/* 6 pay_amount */
	if (GetField_CString(hIn,"pay_amt",&csPtr)) {
		strcat((char*)csBuf,"pay_amount=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: pay_amount = [%s]\n",csPtr));
	}

/* 7 pay_result*/
	if (GetField_CString(hIn,"status",&csPtr)) {
		strcat((char*)csBuf,"pay_result=");
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_EPT_AUTH_TOKEN);
DEBUGLOG(("BuildRspAuthData:: pay_result = [%s]\n",csPtr));
	}


	strcat((char*)csBuf,"key=");

	PutField_CString(hIn,"auth_data",csBuf);
DEBUGLOG(("BuildRspAuthData:: auth_data = [%s]\n",csBuf));
	FREE_ME(csBuf);
        
DEBUGLOG(("BuildRspAuthData() Exit iRet = [%d]\n",iRet));
        return  iRet;
}
