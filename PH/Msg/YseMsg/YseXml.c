/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/06/28              LokMan Chow
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "YseXml.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include <expat.h>
#include "b64.h"

#define PD_XML_HEADER           "<?xml version=\"1.0\" encoding=\"GBK\"?>"
#define PD_ROOT_ELEMENT         "yspay"
#define PD_HEAD_ELEMENT         "head"
#define PD_BODY_ELEMENT         "body"
#define PD_ORDER_ELEMENT	"Order"
#define PD_PAYEE_ELEMENT	"Payee"
#define PD_NOTICE_ELEMENT	"Notice"
#define	PD_CONCAT_STR		"."

#define	PD_VERSION		"1.0"
#define	PD_MSG_CODE		"S3001"
#define	PD_TIMEOUT		"10080"	/* 60x24x7 (default 7 days)*/
#define	PD_BANK_ACCT_TYPE	"11"	/* 11 - 借記卡; 12 - 信用卡 */
#define	PD_NOTE			"Payment"

#ifdef XML_LARGE_SIZE
#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
#define XML_FMT_INT_MOD "I64"
#else
#define XML_FMT_INT_MOD "ll"
#endif
#else
#define XML_FMT_INT_MOD "l"
#endif

	int	isNull;
	int 	iIsTag = 0;
	char	cDebug;

	char	csTmpTag[PD_TMP_BUF_LEN + 1];
	char	csD1TmpTag[PD_TMP_BUF_LEN + 1];
	char	csD2TmpTag[PD_TMP_BUF_LEN + 1];
	char	csD3TmpTag[PD_TMP_BUF_LEN + 1];
	char	csD4TmpTag[PD_TMP_BUF_LEN + 1];
	char*   csTag[PD_MAX_TAG];
	char*   csValue[PD_MAX_TAG];
	int	iTotal = 0;

void	YseXml(char cdebug)
{
	cDebug = cdebug;
}

/* track the current level in the xml tree */
static int      depth = 0;

static char    *last_content;

/* first when start element is encountered */
void
startElement(void *data, const char *element, const char **attribute)
{
    	int	i;
	char	csBuf[PD_TMP_BUF_LEN +1];
	

	isNull = PD_TRUE;
    for (i = 0; i < depth; i++) {
//DEBUGLOG((" \n"));
    }

	strcpy(csBuf,element);

	if (depth == 1) {
		strcpy(csD1TmpTag,csBuf);
		csD2TmpTag[0] = '\0';
		csD3TmpTag[0] = '\0';
		csD4TmpTag[0] = '\0';
		strcpy(csTmpTag,csD1TmpTag);
	}
	else if (depth == 2) {
		strcpy(csD2TmpTag,csBuf);
		csD3TmpTag[0] = '\0';
		csD4TmpTag[0] = '\0';
		strcpy(csTmpTag,csD1TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD2TmpTag);
	}
	else if (depth == 3) {
		strcpy(csD3TmpTag,csBuf);
		csD4TmpTag[0] = '\0';

		strcpy(csTmpTag,csD1TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD2TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD3TmpTag);
	}
	else if (depth == 4) {
		strcpy(csD4TmpTag,csBuf);
		strcpy(csTmpTag,csD1TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD2TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD3TmpTag);
		strcat(csTmpTag,PD_CONCAT_STR);
		strcat(csTmpTag,csD4TmpTag);
	}
	iIsTag=1;

   	for (i = 0; attribute[i]; i += 2) {
		if (!strcmp(attribute[i],"id") ){
			strcat(csTmpTag,PD_CONCAT_STR);
			strcat(csTmpTag,attribute[i+1]);
			if (depth == 1) {
				strcat(csD1TmpTag,PD_CONCAT_STR);
				strcat(csD1TmpTag,attribute[i+1]);
			}
			else if (depth == 2) {
				strcat(csD2TmpTag,PD_CONCAT_STR);
				strcat(csD2TmpTag,attribute[i+1]);
			}
			else if (depth == 3) {
				strcat(csD3TmpTag,PD_CONCAT_STR);
				strcat(csD3TmpTag,attribute[i+1]);
			}
			else if (depth == 4) {
				strcat(csD4TmpTag,PD_CONCAT_STR);
				strcat(csD4TmpTag,attribute[i+1]);
			}
		}
//DEBUGLOG(("***[%d] %s= '%s'\n",i, attribute[i], attribute[i + 1]));
   	}

//DEBUGLOG(("*START***[%s] [%s]\n", element,csTmpTag));
//DEBUGLOG(("*START*********************\n"));
//DEBUGLOG(("\n"));
    	depth++;
}

/* decrement the current level of the tree */
void
endElement(void *data, const char *el)
{
    	int             i;
    	for (i = 0; i < depth; i++) {
//        DEBUGLOG((" \n"));
    	}
	if (iIsTag ==1 ) {
		char *csTmp;
        	csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);
		csTag[iTotal] = strdup(csTmpTag);

		if (isNull == PD_TRUE) 
			csTmp[0] = '\0';
		else 
			sprintf(csTmp,"%s",last_content);
DEBUGLOG(("[%03d]<%s>%s</%s>\n",iTotal, csTmpTag, csTmp,csTmpTag));
		csValue[iTotal] = strdup(csTmp);
		iTotal++;
		FREE_ME(csTmp);
	}

	iIsTag--;
    	depth--;
}

void
handle_data(void *data, const char *content, int length)
{
    char           *tmp = malloc((length*2)+1);
    strncpy(tmp, content, length);
    tmp[length] = '\0';
DEBUGLOG(("handle_data length= [%d] tmp = [%s] \n",length, tmp));
    isNull = PD_FALSE;
    data = (void *) tmp;
    last_content = tmp;         /* TODO: concatenate the text nodes? */
}

int FormatXMLMsg(hash_t* hIn)
{
	int iRet = PD_OK;
	char*	csPtr;
	char*	csBuf,*csTag;
	unsigned char*	outMsg;
	double	dTmp;

        csBuf = (char*) malloc (PD_TMP_MSG_BUF_LEN+1);
        csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
        outMsg = (unsigned char*) malloc (PD_TMP_MSG_BUF_LEN*2);

        
        strcpy((char*)outMsg,PD_XML_HEADER);

/* Root Element Start*/
        sprintf(csBuf,"<%s>",PD_ROOT_ELEMENT);
        strcat((char*)outMsg,csBuf);

/* Head Element Start*/
        sprintf(csBuf,"<%s>",PD_HEAD_ELEMENT);
        strcat((char*)outMsg,csBuf);

/* Ver */
       	strcpy(csTag,"Ver");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_VERSION));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_VERSION,csTag);
	strcat((char*)outMsg,csBuf);

/* Src */
        strcpy(csTag,"psp_merchant_id");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"Src");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* MsgCode */
       	strcpy(csTag,"MsgCode");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_MSG_CODE));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_MSG_CODE,csTag);
	strcat((char*)outMsg,csBuf);

/* Time */
	if (GetField_CString(hIn,"local_tm_date",&csPtr)) {
                        char*   csPtr2;
                        char    csDateTime[PD_DATETIME_LEN * 2];
                        if (GetField_CString(hIn,"local_tm_time",&csPtr2)) {
                                sprintf(csDateTime,"%s%s",csPtr,csPtr2);
				strcpy(csTag,"Time");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csDateTime));
				sprintf(csBuf,"<%s>%s</%s>",csTag,csDateTime,csTag);
				strcat((char*)outMsg,csBuf);
                        }
                        else {
DEBUGLOG(("FormatXMLMsg:: local_tm_time is missing!!!\n"));
                        }
                }
                else {
DEBUGLOG(("FormatXMLMsg:: local_tm_date is missing!!!\n"));
                }

/* Head Element End*/
        sprintf(csBuf,"</%s>",PD_HEAD_ELEMENT);
        strcat((char*)outMsg,csBuf);

/* Body Element Start*/
        sprintf(csBuf,"<%s>",PD_BODY_ELEMENT);
        strcat((char*)outMsg,csBuf);


/*Order Start*/
        sprintf(csBuf,"<%s>",PD_ORDER_ELEMENT);
        strcat((char*)outMsg,csBuf);

/* OrderId */
        strcpy(csTag,"txn_seq");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"OrderId");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* BusiCode */
        strcpy(csTag,"psp_key_id");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"BusiCode");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* ShopDate */
        strcpy(csTag,"local_tm_date");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"ShopDate");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* Cur */
	strcpy(csTag,"Cur");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_CCY_ISO_CNY));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_CCY_ISO_CNY,csTag);
	strcat((char*)outMsg,csBuf);

/* Amount */
        strcpy(csTag,"psp_txn_amt");
        if (GetField_Double(hIn,csTag,&dTmp)) {
		char    csTmpAmt[PD_DIGIT_LEN+PD_DECIMAL_LEN+1];
		sprintf(csTmpAmt,"%ld",(long)(((dTmp*200)+1)/2));

                strcpy(csTag,"Amount");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csTmpAmt));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csTmpAmt,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* Note */
	strcpy(csTag,"Note");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_NOTE));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_NOTE,csTag);
	strcat((char*)outMsg,csBuf);

/* Timeout */
	strcpy(csTag,"Timeout");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_TIMEOUT));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_TIMEOUT,csTag);
	strcat((char*)outMsg,csBuf);

/* BankType */
        strcpy(csTag,"bank_code");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"BankType");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* BankAccountType */
	strcpy(csTag,"BankAccountType");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,PD_BANK_ACCT_TYPE));
	sprintf(csBuf,"<%s>%s</%s>",csTag,PD_BANK_ACCT_TYPE,csTag);
	strcat((char*)outMsg,csBuf);



/*Order End*/
        sprintf(csBuf,"</%s>",PD_ORDER_ELEMENT);
        strcat((char*)outMsg,csBuf);


/*Payee Start*/
        sprintf(csBuf,"<%s>",PD_PAYEE_ELEMENT);
        strcat((char*)outMsg,csBuf);

/* UserCode */
        strcpy(csTag,"psp_merchant_id");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"UserCode");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* Name */
        strcpy(csTag,"psp_merch_name");
        if (GetField_CString(hIn,csTag,&csPtr)) {
		strcpy(csTag,"Name");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
		sprintf(csBuf,"<%s>%s</%s>",csTag,code_convert(PD_HOST_CODE,PD_GB2312_CODE,csPtr),csTag);
		//sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
		strcat((char*)outMsg,csBuf);
	}

/*Payee End*/
        sprintf(csBuf,"</%s>",PD_PAYEE_ELEMENT);
        strcat((char*)outMsg,csBuf);


/*Notice Start*/
        sprintf(csBuf,"<%s>",PD_NOTICE_ELEMENT);
        strcat((char*)outMsg,csBuf);


/* PgUrl */
        strcpy(csTag,"return_url_only");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"PgUrl");
DEBUGLOG(("FormatXMLMsg <%s> = <%sfe/>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%sfe/</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }

/* BgUrl */
        strcpy(csTag,"return_url_only");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"BgUrl");
DEBUGLOG(("FormatXMLMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }


/*Notice End*/
        sprintf(csBuf,"</%s>",PD_NOTICE_ELEMENT);
        strcat((char*)outMsg,csBuf);


/* Body Element End*/
        sprintf(csBuf,"</%s>",PD_BODY_ELEMENT);
        strcat((char*)outMsg,csBuf);


/* Root Element */
        sprintf(csBuf,"</%s>",PD_ROOT_ELEMENT);
        strcat((char*)outMsg,csBuf);

DEBUGLOG(("FormatXMLMsg:: xml_msg = [%s]\n",outMsg));
	base64_encode(outMsg,strlen((char*)outMsg),csBuf,PD_MAX_BUFFER);
DEBUGLOG(("FormatXMLMsg:: enc_xml_msg = [%s]\n",csBuf));

	PutField_CString(hIn,"xml_msg",(const char*)outMsg);
	PutField_CString(hIn,"enc_xml_msg",csBuf);
	

	FREE_ME(csTag);
	FREE_ME(csBuf);
	FREE_ME(outMsg);
DEBUGLOG(("FormatXMLMsg:: iRet = [%d]\n",iRet));
	return iRet;
}

int BreakDownXMLMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	int	i;
	int     userData = 0;
	int     done = 0;
	unsigned char *utfMsg;
	utfMsg = (unsigned char*) malloc (PD_TMP_MSG_BUF_LEN*2);

	XML_Parser parser;

	strcpy((char*)utfMsg,code_convert(PD_GB2312_CODE,PD_HOST_CODE,(char *)inMsg));
	utfMsg[strlen((const char*)utfMsg)] = '\0';


	iTotal = 0;
DEBUGLOG(("BreakDownXMLMsg Alloced\n"));
DEBUGLOG(("BreakDownXMLMsg [%s][%d]\n",utfMsg,strlen((const char*)utfMsg)));
	iIsTag = 0;
DEBUGLOG(("BreakDownXMLMsg Total = [%d]\n",iTotal));

	parser = XML_ParserCreate((XML_Char *)"UTF-8");
	XML_SetUserData(parser, &userData);
	XML_SetElementHandler(parser, startElement, endElement);
	XML_SetCharacterDataHandler(parser,handle_data);
	
DEBUGLOG(("BreakDownXMLMsg try to parse\n"));
	if (!XML_Parse(parser, (char*)utfMsg, strlen((const char*)utfMsg), done)) {
DEBUGLOG(("BreakDownXMLMsg %s at line %d\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser)));
ERRLOG("YseXml::BreakDownXMLMsg %s at line %d\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser));
		return INT_BREAKDOWN_ERR;
	}	
DEBUGLOG(("BreakDownXMLMsg after try to parse\n"));

	XML_ParserFree(parser);

DEBUGLOG(("BreakDownXMLMsg Total Count = [%d]\n",iTotal));
	for (i = 0 ; i < iTotal; i++) {
DEBUGLOG(("BreakDownXMLMsg [%03d] %s=%s\n",i,csTag[i],csValue[i]));

		PutField_CString(hOut,csTag[i],csValue[i]);
	}

	FREE_ME(utfMsg);
DEBUGLOG(("BreakDownXMLMsg Normal Exit iRet = [%d]\n",iRet));
        return iRet;
}
