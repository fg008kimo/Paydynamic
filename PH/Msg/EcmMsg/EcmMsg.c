/*
Partnerdelight (c)2016. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2016/09/30              David Wong
Add TLG logging					   2017/05/15		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EcmMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include <zlib.h>
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"

char	cDebug;
OBJPTR(DB);

void	EcmMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char*   csTmp = NULL;
	char*   csPtr = NULL;
	char*   csBuf;
	char*	csTmpBuf;
	char*	csTag;
	double  dTmp;
	char*   csMethod = NULL;
	int     iOpt = PD_TRUE;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
	csTmpBuf = (char*) malloc (PD_TMP_BUF_LEN + 1 );
	csTag = (char*) malloc (PD_TAG_LEN +1 );

	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char *)outMsg,csPtr);
		strcat((char *)outMsg,"?");

/* MerNo */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"MerNo");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: MerNo = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}

/* BillNo */

		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"BillNo");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: BillNo = [%s]\n",csTmp));
		}

/* Amount */
		if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

			char    csTmpAmt[PD_TMP_BUF_LEN +1];
			sprintf(csTmpAmt,"%.2f",dTmp);
			strcat((char*)outMsg,"Amount");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmpAmt);
			strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: Amount = [%s]\n",csTmpAmt));
		}
		else {
DEBUGLOG(("FormatMsg:: psp_txn_amt is missing!!!\n"));
		}

/* ReturnURL */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"ReturnURL");
                        strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
                        strcat((char*)outMsg,csTmp);
                        strcat((char*)outMsg,"fe/");
                        strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: pickupUrl = [%s]\n",csTmp));
                }
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** fe_url is missing\n"));
		}
/* AdviceURL */
		if (GetField_CString(hIn,"return_url_only",&csTmp)) {
			strcat((char*)outMsg,"AdviceURL");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: AdviceURL = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: *** return_url_only is missing\n"));
		}

/* SignInfo */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"SignInfo");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_ECM_TOKEN);
DEBUGLOG(("FormatMsg:: signMsg = [%s]\n",csTmp));
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
                        	strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
                        	strcat((char*)outMsg,csDateTime);
                        	strcat((char*)outMsg,MY_ECM_TOKEN);
                	}
                	else {
DEBUGLOG(("FormatMsg:: local_tm_time is missing!!!\n"));
                	}
        	}
        	else {
DEBUGLOG(("FormatMsg:: local_tm_date is missing!!!\n"));
        	}

/* defaultBankNumber */
		if (GetField_CString(hIn,"bank_code",&csTmp)) {
			strcat((char*)outMsg,"defaultBankNumber");
			strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
			DBObjPtr = CreateObj(DBPtr,"DBMobBankMap","IsMobileOption");
			iOpt = (unsigned long)(*DBObjPtr)(csTmp);
			if(iOpt==PD_FALSE && iOpt!=INT_ERR){
				strcat((char*)outMsg,csTmp);
DEBUGLOG(("FormatMsg:: defaultBankNumber = [%s]\n",csTmp));
			} else if(iOpt && iOpt!=INT_ERR){
				strcat((char*)outMsg,"NOCARD");
DEBUGLOG(("FormatMsg:: defaultBankNumber = [NOCARD]\n"));
			}
			strcat((char*)outMsg,MY_ECM_TOKEN);
		}
/* payType */
		strcat((char*)outMsg,"payType");
		strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
		if (iOpt) {
			strcat((char*)outMsg,"noCard");
DEBUGLOG(("FormatMsg:: pay_type = [noCard]\n"));
		} else {
			strcat((char*)outMsg,"B2CDebit");
DEBUGLOG(("FormatMsg:: pay_type = [B2CDebit]\n"));
		}
		strcat((char*)outMsg,MY_ECM_TOKEN);

/* Remark */
		strcat((char*)outMsg,"Remark");
		strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
		strcat((char*)outMsg,MY_ECM_TOKEN);

/* products */
		strcat((char*)outMsg,"products");
		strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
		strcat((char*)outMsg,MY_ECM_TOKEN);


/* TLG - Transaction Logging */
		if (GetField_CString(hIn,"psp_id",&csTmp)) {
			int iDtlRet = PD_FALSE;
DEBUGLOG(("Call DBPspUrl::IsRedirectURL\n"));
			//Call DBPspUrl::IsRedirectURL
			DBObjPtr = CreateObj(DBPtr,"DBPspUrl","IsRedirectURL");
			iDtlRet = ((unsigned long)(DBObjPtr)(csTmp));

			if (iDtlRet == PD_TRUE) {
DEBUGLOG(("  psp_id [%s] IsRedirectUrl = TRUE [%d]\n",csTmp,iDtlRet));

				if (GetField_CString(hIn,"txn_seq",&csTmp)) {
DEBUGLOG(("Call DBDefTlgTagConvert:GetRandomTag\n"));
					DBObjPtr = CreateObj(DBPtr,"DBDefTlgTagConvert","GetRandomTag");
					iDtlRet = ((unsigned long)(DBObjPtr)("txn_seq",csTag));

					if (iDtlRet == PD_OK) {
DEBUGLOG(("  org_tag [%s], new_tag [%s]\n","txn_seq",csTag));
						base64_encode((unsigned char*)csTmp,strlen(csTmp),csTmpBuf,PD_TMP_BUF_LEN);
						strcat((char*)outMsg,csTag);
						strcat((char*)outMsg,MY_ECM_FIELD_TOKEN);
						strcat((char*)outMsg,csTmpBuf);
						strcat((char*)outMsg,MY_ECM_TOKEN);
					} else {
DEBUGLOG(("  CALL FAILED!! Skip Insert TLG Log, iDtlRet = [%d]\n",iDtlRet));
					}
				} else {
DEBUGLOG(("txn_seq NOT FOUND!! Skip Insert TLG Log\n"));
				}


DEBUGLOG(("FormatMsg:: [%s] = [%s]\n",csTag,csTmp));
			} else {
DEBUGLOG(("  psp_id [%s] IsRedirectUrl = FALSE [%d]\n",csTmp,iDtlRet));
			}
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
                strcat((char*)outMsg,MY_ECM_TOKEN);
		strcat((char*)outMsg,"url_method");
		strcat((char*)outMsg,"=");
		strcat((char*)outMsg,csMethod);
                strcat((char*)outMsg,MY_ECM_TOKEN);
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
	FREE_ME(csTmpBuf);
	FREE_ME(csTag);
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

	if (Str2Cls(hRec,(char *)inMsg,MY_ECM_TOKEN, MY_ECM_FIELD_TOKEN) == PD_OK) {

/* MerNo */
		if (GetField_CString(hRec,"MerNo",&csPtr)) {
			PutField_CString(hOut,"mer_no",csPtr);
DEBUGLOG(("BreakDownMsg:: MerNo = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: MerNo not found\n"));
		}

/* BillNo */
		if (GetField_CString(hRec,"BillNo",&csPtr)) {
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_seq = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_seq not found\n"));
		}

/* OrderNo */
		if (GetField_CString(hRec,"OrderNo",&csPtr)) {
			PutField_CString(hOut,"order_no",csPtr);
DEBUGLOG(("BreakDownMsg:: OrderNo = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: OrderNo not found\n"));
		}

/* Amount */
		if (GetField_CString(hRec,"Amount",&csPtr)) {
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg:: txn_amt = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: txn_amt not found\n"));
		}

/* Succeed */
		if (GetField_CString(hRec,"Succeed",&csPtr)) {
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg:: status = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: status not found\n"));
		}

/* Result */
		if (GetField_CString(hRec,"Result",&csPtr)) {
//			PutField_CString(hOut,"error_code",csPtr);
DEBUGLOG(("BreakDownMsg:: result = [%s]\n",csPtr));
		}

/* SignInfo */
                if (GetField_CString(hRec,"SignInfo",&csPtr)) {
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
	

/* MerNo */
	if (GetField_CString(hIn,"psp_merchant_id",&csPtr)) {
		strcat((char*)csBuf,"MerNo");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: merchantId = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: ***psp_merchant_id is missing\n"));
	}

/* BillNo */

	if (GetField_CString(hIn,"txn_seq",&csPtr)) {
		strcat((char*)csBuf,"BillNo");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: orderNo = [%s]\n",csPtr));
	}

/* Amount */
	if (GetField_Double(hIn,"psp_txn_amt",&dTmp)) {

		char    csTmpAmt[PD_TMP_BUF_LEN +1];
		sprintf(csTmpAmt,"%.2f",dTmp);
		strcat((char*)csBuf,"Amount");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csTmpAmt);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: orderAmount = [%s]\n",csTmpAmt));
	}
	else {
DEBUGLOG(("BuildAuthData:: psp_txn_amt is missing!!!\n"));
	}

/* OrderTime */
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
		char*   csPtr2;
		char    csDateTime[PD_DATETIME_LEN * 2];
		if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
			sprintf(csDateTime,"%s%s",csPtr,csPtr2);
			strcat((char*)csBuf,"OrderTime");
			strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
			strcat((char*)csBuf,csDateTime);
			strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: OrderTime = [%s]\n",csDateTime));
		}
		else {
DEBUGLOG(("BuildAuthData:: local_tm_time is missing\n"));
		}
	}
	else {
DEBUGLOG(("BuildAuthData:: local_tm_date is missing\n"));
	}


/* ReturnURL */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"ReturnURL");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,"fe/");
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: pickupUrl = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: *** fe_url is missing\n"));
		}

/* AdviceURL */
	if (GetField_CString(hIn,"return_url_only",&csPtr)) {
		strcat((char*)csBuf,"AdviceURL");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildAuthData:: AdviceURL = [%s]\n",csPtr));
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("BuildAuthData:: AdviceURL is missing\n"));
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

/* MerNo */
	strcpy(csTag,"mer_no");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,"MerNo");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}

/* BillNo */
	strcpy(csTag,"txn_seq");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,"BillNo");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}

/* OrderNo */
	strcpy(csTag,"order_no");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,"OrderNo");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
	}

/* Amount */
        strcpy(csTag,"txn_amt");
        if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,"Amount");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
                strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
DEBUGLOG(("BuildRspAuthData:: %s = [%s]\n",csTag,csPtr));
        }
	else {
		//iRet = INT_ERR;
DEBUGLOG(("BuildRspAuthData:: ****[%s] is missing\n",csTag));
	}


/* Succeed */
	strcpy(csTag,"status");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcat((char*)csBuf,"Succeed");
		strcat((char*)csBuf,MY_ECM_FIELD_TOKEN);
		strcat((char*)csBuf,csPtr);
		strcat((char*)csBuf,MY_ECM_TOKEN);
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


