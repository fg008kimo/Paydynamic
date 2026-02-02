/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version					   2016/06/28              LokMan Chow
Add TLG logging					   2017/05/15		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "YseMsg.h"
#include "YseXml.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "b64.h"
#include "internal.h"
#include "ObjPtr.h"


#define PD_MSG_CODE	"S3001"
#define MSG_ID_LEN	32

char	cDebug;
OBJPTR(DB);

void	YseMsg(char cdebug)
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
	char*   csMethod = NULL;

	csBuf = (char*) malloc (MAX_MSG_SIZE + 1 );
	csTmpBuf = (char*) malloc (PD_TMP_BUF_LEN + 1 );
	csTag = (char*) malloc (PD_TAG_LEN + 1 );

	
	hash_t *hXml;
	hXml = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hXml,0);
	
	memset(outMsg,0,sizeof(outMsg));
	if (GetField_CString(hIn,"redirect_url",&csPtr)) {
DEBUGLOG(("FormatMsg here\n"));
		strcat((char*)outMsg,csPtr);
		strcat((char*)outMsg,"?");
/* src */
		if (GetField_CString(hIn,"psp_merchant_id",&csTmp)) {
			strcat((char*)outMsg,"src");
			strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_YSE_TOKEN);
DEBUGLOG(("FormatMsg:: src = [%s]\n",csTmp));
		}
		else {
			iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: ***psp_merchant_id is missing\n"));
		}
/* msgCode */
		strcat((char*)outMsg,"msgCode");
		strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
		strcat((char*)outMsg,PD_MSG_CODE);
		strcat((char*)outMsg,MY_YSE_TOKEN);
DEBUGLOG(("FormatMsg:: msgCode = [%s]\n",PD_MSG_CODE));

/* msgId*/
		if (GetField_CString(hIn,"txn_seq",&csTmp)) {
			strcat((char*)outMsg,"msgId");
			strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
			strcat((char*)outMsg,csTmp);
			strcat((char*)outMsg,MY_YSE_TOKEN);
DEBUGLOG(("FormatMsg:: msgId = [%s]\n",csTmp));
		}

/* check */
		if (GetField_CString(hIn,"sign",&csTmp)) {
			strcat((char*)outMsg,"check");
			strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
			strcat((char*)outMsg,url_encode(csTmp));
			strcat((char*)outMsg,MY_YSE_TOKEN);
DEBUGLOG(("FormatMsg:: check = [%s]\n",csTmp));
		}

/* msg */
		if (GetField_CString(hIn,"enc_xml_msg",&csTmp)) {
			strcat((char*)outMsg,"msg");
			strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
			strcat((char*)outMsg,url_encode(csTmp));
			strcat((char*)outMsg,MY_YSE_TOKEN);
DEBUGLOG(("FormatMsg:: msg = [%s]\n",csTmp));
		}


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
						strcat((char*)outMsg,MY_YSE_FIELD_TOKEN);
						strcat((char*)outMsg,csTmpBuf);
						strcat((char*)outMsg,MY_YSE_TOKEN);
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

DEBUGLOG(("FormatMsg:: outmsg = (url_encode) [%s]\n",outMsg));
			base64_encode(outMsg,strlen((char*)outMsg),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatMsg:: after encode\n"));
			outMsg[0] = '\0';
			strcat((char*)outMsg,"redirect_url");
			strcat((char*)outMsg,"=");
			strcat((char*)outMsg,csBuf);
			strcat((char*)outMsg,MY_YSE_TOKEN);
			strcat((char*)outMsg,"url_method");
			strcat((char*)outMsg,"=");
			strcat((char*)outMsg,csMethod);
			strcat((char*)outMsg,MY_YSE_TOKEN);
			strcat((char*)outMsg,"ret_status=0");
DEBUGLOG(("FormatMsg:: outMsg = [%s]\n",outMsg));

			*outLen = strlen((const char*)outMsg);
	
	}
	else {
		iRet = PD_ERR;
DEBUGLOG(("FormatMsg:: Redirct url not found\n"));
	}


DEBUGLOG(("FormatMsg:: normal exit iret =[%d]\n",iRet));
	FREE_ME(hXml);
	FREE_ME(csBuf);
	FREE_ME(csTmpBuf);
	FREE_ME(csTag);
	return 	iRet;
}



int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	char	*csPtr;
	char	csTag[PD_TAG_LEN+1];
	char	msgId[MSG_ID_LEN+1];
	char	check[PD_TMP_BUF_LEN+1];
	char    *csTmpDATA;
	csTmpDATA = (char*) malloc (PD_TMP_MSG_BUF_LEN*2+1);
	int     iLen;
	hash_t  *hRec;
	hash_t  *hXml;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);
        hXml = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hXml,0);

DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char*)inMsg,MY_YSE_TOKEN, MY_YSE_FIELD_TOKEN) == PD_OK) {

/* src */
		if (GetField_CString(hRec,"src",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: src = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: src not found\n"));
		}
/* msgCode */
		if (GetField_CString(hRec,"msgCode",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: msgCode = [%s]\n",csPtr));
		}
		else{
DEBUGLOG(("BreakDownMsg:: msgCode not found\n"));
		}
/* msgId */
		if (GetField_CString(hRec,"msgId",&csPtr)) {
			strcpy(msgId,TrimAll((const unsigned char*)csPtr,strlen(csPtr)));
			msgId[strlen(msgId)]='\0';
DEBUGLOG(("BreakDownMsg:: msgId = [%s]\n",msgId));
		}
		else{
DEBUGLOG(("BreakDownMsg:: msgCode not found\n"));
		}
/* check */
		if (GetField_CString(hRec,"check",&csPtr)) {
			strcpy(check,TrimAll((const unsigned char*)csPtr,strlen(csPtr)));
                        check[strlen(check)]='\0';
			PutField_CString(hOut,"sign",check);
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n",check));
		}
		else{
                	PutField_CString(hOut,"sign"," ");
DEBUGLOG(("BreakDownMsg:: sign = [%s]\n"," "));
        	}

/* msg */
		if (GetField_CString(hRec,"msg",&csPtr)) {
DEBUGLOG(("BreakDownMsg:: msg = [%s]\n",csPtr));

			iLen = base64_decode((char *)csPtr,(unsigned char*)csTmpDATA,PD_TMP_MSG_BUF_LEN*2);
			if (iLen > 0 ){
				csTmpDATA[iLen]='\0';
				PutField_CString(hOut,"xml_msg",csTmpDATA);
DEBUGLOG(("BreakDownMsg:: xml_msg = [%s]\n",csTmpDATA));

				iRet = BreakDownXMLMsg(hXml,(const unsigned char *)csTmpDATA,strlen(csTmpDATA));
			}
			else{
				iRet = INT_BREAKDOWN_ERR;
			}

		}
		else{
DEBUGLOG(("BreakDownMsg:: msg not found\n"));
		}


	}
	else {
DEBUGLOG(("BreakDownMsg() Error\n"));
                iRet = PD_ERR;
        }


	if(iRet == PD_OK){
		sprintf(csTag,"head.Time");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"fundin_date",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Order.OrderId");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"txn_seq",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Order.ShopDate");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"txn_date",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Order.Cur");
		if(GetField_CString(hXml,csTag,&csPtr)){
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Order.Amount");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"txn_amt",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Order.Remark");
		if(GetField_CString(hXml,csTag,&csPtr)){
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Result.BusiState");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"status",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Result.Code");
		if(GetField_CString(hXml,csTag,&csPtr)){
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Result.Note");
		if(GetField_CString(hXml,csTag,&csPtr)){
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

		sprintf(csTag,"body.Result.TradeSN");
		if(GetField_CString(hXml,csTag,&csPtr)){
			PutField_CString(hOut,"tid",csPtr);
DEBUGLOG(("BreakDownMsg[XML]:: %s = [%s]\n",csTag,csPtr));
		}

	}

        FREE_ME(csTmpDATA);
        hash_destroy(hRec);
	FREE_ME(hRec);
        hash_destroy(hXml);
	FREE_ME(hXml);

DEBUGLOG(("BreakDownMsg Exit\n"));
	return	iRet;
}

int BuildRspAuthData(hash_t* hOut)
{
	int	iRet = PD_OK;

	//Do nothing
	
	return iRet;
}

int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
	int	iRet = PD_OK;

	return iRet;
}
