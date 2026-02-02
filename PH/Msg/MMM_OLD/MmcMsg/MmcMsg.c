/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/21              Virginia Yun
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "MmcMsg.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include <expat.h>

#define PD_XML_HEADER		"<?xml version=\"1.0\" encoding=\"UTF-8\"?>"
#define PD_ROOT_ELEMENT		"PH"
#define	PD_ID_ELEMENT		"id"
#define	PD_DT_ELEMENT		"dt"

#ifdef XML_LARGE_SIZE
#if defined(XML_USE_MSC_EXTENSIONS) && _MSC_VER < 1400
#define XML_FMT_INT_MOD "I64"
#else
#define XML_FMT_INT_MOD "ll"
#endif
#else
#define XML_FMT_INT_MOD "l"
#endif


char	cDebug;


void	MmcMsg(char cdebug)
{
	cDebug = cdebug;
}

int     iTotal = 0;
int	iN;
char*   csTag[PD_MAX_TAG];
char*   csValue[PD_MAX_TAG];
char*   csName[PD_MAX_TAG];
char	*csAttr;
int	iAttr;


static void XMLCALL
startElement(void *userData, const char *name, const char **atts)
{
  	int *depthPtr = userData;

	int i;
	for(i = 0; atts[i]; i += 2) {
		if (!strcmp(atts[i],PD_ID_ELEMENT)) {
			if (csAttr != NULL) 
				FREE_ME(csAttr);
        		csAttr = (char*) malloc (PD_TMP_BUF_LEN +1 );
			strcpy(csAttr,atts[i +1]);
//DEBUGLOG(("att = [%s]\n",csAttr));
			iAttr++;
		}
	}
	if (strcmp(name,PD_ROOT_ELEMENT)) {
		if (csName[iN] != NULL) {
			char* csTmp;
        		csTmp = (char*) malloc (PD_TMP_BUF_LEN +1 );
			sprintf(csTmp,"%s_%s",csName[iN],name);
			FREE_ME(csName[iN]);
			csName[iN] = (char*)strdup(csTmp);
			FREE_ME(csTmp);
		}
		else {
			csName[iN]= (char*) strdup(name);
		}

//DEBUGLOG(("in = [%d]\n",iN));
		if (iN >= 1) {
			int i;
			char* csBuf;
			int	iLen=0;
        		csBuf = (char*) malloc (PD_TMP_BUF_LEN +1 );
			for (i = 0; i < iN; i++) {
				if (iLen > 0 ) {
					memcpy(&csBuf[iLen],"_",1);
					iLen++;
				}
				memcpy(&csBuf[iLen],csName[i],strlen(csName[i]));
				iLen += strlen(csName[i]);
				csBuf[iLen] = '\0';
			}
			
			if (iLen > 0 ) {
				memcpy(&csBuf[iLen],"_",1);
				iLen++;
			}
			memcpy(&csBuf[iLen],name,strlen(name));
			iLen += strlen(name);
			csBuf[iLen] = '\0';

			if (csAttr != NULL) {
				if (iLen > 0 ) {
					memcpy(&csBuf[iLen],"_",1);
					iLen++;
				}
				memcpy(&csBuf[iLen],csAttr,strlen(csAttr));
				iLen += strlen(csAttr);
				csBuf[iLen] = '\0';
			}
			if (csTag[iTotal] != NULL) 
				FREE_ME(csTag[iTotal]);

			csTag[iTotal] = (char*)strdup(csBuf);
			FREE_ME(csBuf);
		}
		else  {
			csTag[iTotal] = (char*)strdup(name);
		}

		iN++;
//DEBUGLOG(("T[%d][<%s>]\n",iN,csTag[iTotal]));
	}

  	*depthPtr += 1;
}

static void XMLCALL
endElement(void *userData, const char *name)
{
  int *depthPtr = userData;
  *depthPtr -= 1;
	iN--;
//DEBUGLOG(("FREE %s\n",csName[iN]));
	FREE_ME(csName[iN]);
//DEBUGLOG(("T[%d][%d][</%s>]\n",iN,iTotal,name));
}

static void XMLCALL
Chars(void *userData, const XML_Char *s, int len)
{
        char* csTmp;
        if (len > 1) {
                csTmp = (char*) malloc (len +1 );
                sprintf(csTmp,"%.*s",len,s);
//DEBUGLOG(("XMLCALL Chars [%s]\n",csTmp));
//DEBUGLOG(("value = [%s]\n",csTmp));
		csValue[iTotal] = strdup(csTmp);
                FREE_ME(csTmp);
        }
        else {
//DEBUGLOG(("XMLCALL Chars len !>1\n"));
                csTmp = (char*) malloc (2);
                sprintf(csTmp,"%c",s[0]);
//DEBUGLOG(("XMLCALL Chars***** [%s]\n",csTmp));
//DEBUGLOG(("value = [%s]\n",csTmp));
                csValue[iTotal] = strdup(csTmp);
		FREE_ME(csTmp);
        }
        iTotal ++;
}


int FormatDTMsg(const hash_t* hIn,unsigned char *outMsg, const int iCnt);

int FormatMultiMsg(const hash_t* hIn,unsigned char *outMsg, const int iCnt);

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int iRet = PD_OK;
	char*	csPtr;
	char*	csTxnCode;
	char*	csBuf,*csTag,*csTmp;
	double	dTmp;
	int	iTmp;

	csBuf = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);
	csTag = (char*) malloc (PD_TMP_BUF_LEN +1);
	csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);

        
	strcpy((char*)outMsg,PD_XML_HEADER);

/* Root Element */
	sprintf(csBuf,"<%s>",PD_ROOT_ELEMENT);
	strcat((char*)outMsg,csBuf);

/* reply_txn_code */
	strcpy(csTag,"reply_txn_code");
	if (GetField_CString(hIn,csTag,&csTxnCode)) {
		strcpy(csTag,"reply_tc");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csTxnCode));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csTxnCode,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* response_code */
	strcpy(csTag,"response_code");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcpy(csTag,"ret");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csPtr));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* txn_seq */
        strcpy(csTag,"txn_seq");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"txnid");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }



/* dtl_txn_seq */
	strcpy(csTag,"dtl_txn_seq");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcpy(csTag,"dtl_txnid");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csPtr));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* txn_amt */
	if (GetField_Double(hIn,"txn_amt",&dTmp)) {
		sprintf((char*)csTmp,"%.2f",dTmp);
		strcpy(csTag,"txnamt");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csTmp));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csTmp,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* fee */
	if (GetField_Double(hIn,"fee",&dTmp)) {
		sprintf((char*)csTmp,"%.2f",dTmp);
		strcpy(csTag,"fee");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csTmp));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csTmp,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* end_ind */
	strcpy(csTag,"end_ind");
	if (GetField_Int(hIn,csTag,&iTmp)) {
		strcpy(csTag, "end_ind");
DEBUGLOG(("FormatMsg <%s> = <%d>\n",csTag,iTmp));
		sprintf(csBuf,"<%s>%d</%s>",csTag,iTmp,csTag);
		strcat((char*)outMsg,csBuf);
	}


/* total_cnt */
	if (GetField_Int(hIn,"total_cnt",&iTmp)) {
		strcpy(csTag,"total_cnt");
DEBUGLOG(("FormatMsg <%s> = <%d>\n",csTag,iTmp));
		sprintf(csBuf,"<%s>%d</%s>",csTag,iTmp,csTag);
		strcat((char*)outMsg,csBuf);

		if (!strcmp(csTxnCode, "EOM")) {
			FormatDTMsg(hIn, outMsg, iTmp);
		} else {
			FormatMultiMsg(hIn,outMsg,iTmp);
		}
	}


/* service_fee */
	if (GetField_Double(hIn,"service_fee",&dTmp)) {
		sprintf((char*)csTmp,"%.2f",dTmp);
        	strcpy(csTag,"service_fee");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csTmp));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csTmp,csTag);
                strcat((char*)outMsg,csBuf);
	}

/* bal*/
	if (GetField_Double(hIn,"bal",&dTmp)) {
		sprintf((char*)csTmp,"%.2f",dTmp);
        	strcpy(csTag,"bal");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csTmp));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csTmp,csTag);
                strcat((char*)outMsg,csBuf);
	}

/* bank_acct */
	strcpy(csTag,"bank_acct");
	if (GetField_CString(hIn,csTag,&csPtr)) {
		strcpy(csTag,"bank_acct");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csPtr));
		sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
		strcat((char*)outMsg,csBuf);
	}

/* inq_id */
        strcpy(csTag,"inq_id");
        if (GetField_CString(hIn,csTag,&csPtr)) {
                strcpy(csTag,"inq_id");
DEBUGLOG(("FormatMsg <%s> = <%s>\n",csTag,csPtr));
                sprintf(csBuf,"<%s>%s</%s>",csTag,csPtr,csTag);
                strcat((char*)outMsg,csBuf);
        }



/* Root Element */
        sprintf(csBuf,"</%s>",PD_ROOT_ELEMENT);
        strcat((char*)outMsg,csBuf);
        *outLen = strlen((char*)outMsg);

	FREE_ME(csTag);
	FREE_ME(csBuf);
	FREE_ME(csTmp);
DEBUGLOG(("FormatMsg:: out = [%s]\n",outMsg));
DEBUGLOG(("FormatMsg:: iRet = [%d]\n",iRet));
	return iRet;
}

int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	int	userData = 0;
	int	done = 0;
	int	i;
	char	*csTmp;

	iTotal = 0;
	iN = 0;
	iAttr = 0;
	XML_Parser parser;

DEBUGLOG(("[%s]\n",inMsg));

	csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);
	parser = XML_ParserCreate((XML_Char *)"UTF-8");
	XML_SetUserData(parser, &userData);
	XML_SetElementHandler(parser, startElement, endElement);
	XML_SetCharacterDataHandler(parser,Chars);
	
	if (!XML_Parse(parser, (char*)inMsg, inLen, done)) {
DEBUGLOG(("%s at line %d\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser)));
		return 1;
	}	

	XML_ParserFree(parser);

//DEBUGLOG(("iTotal = [%d]\n",iTotal));
	for (i = 0; i < iTotal; i++) {
		U2L(csTag[i],strlen(csTag[i]),csTmp);
DEBUGLOG(("%s = [%s]\n",csTmp,csValue[i]));
		if (!strcmp(csTmp,"tc")) {
			PutField_CString(hOut,"txn_code",csValue[i]);
		}
		else if (!strcmp(csTmp,"txnid")) {
			PutField_CString(hOut,"txn_seq",csValue[i]);
		}
		else if (!strcmp(csTmp,"dtl_txnid")) {
			PutField_CString(hOut,"dtl_txn_seq",csValue[i]);
		}
		else if (!strcmp(csTmp,"user")) {
			PutField_CString(hOut,"add_user",csValue[i]);
		}
		else if (!strcmp(csTmp,"mid")) {
			PutField_CString(hOut,"merchant_id",csValue[i]);
		}
		else if (!strcmp(csTmp,"country")) {
			PutField_CString(hOut,"txn_country",csValue[i]);
		}
		else if (!strcmp(csTmp,"ccy")) {
			PutField_CString(hOut,"txn_ccy",csValue[i]);
		}
		else if (!strcmp(csTmp,"service")) {
			PutField_CString(hOut,"service_code",csValue[i]);
		}
		else if (!strcmp(csTmp,"txnamt")) {
			PutField_CString(hOut,"txn_amt",csValue[i]);
		}
		/* *************************
		else if (!strcmp(csTmp,"from_type")) {
			PutField_CString(hOut,"mms_from_type",csValue[i]);
		}
		else if (!strcmp(csTmp,"to_type")) {
			PutField_CString(hOut,"mms_to_type",csValue[i]);
                }
		else if (!strcmp(csTmp,"from_id")) {
			PutField_CString(hOut,"mms_from_id",csValue[i]);
                }
		else if (!strcmp(csTmp,"to_id")) {
			PutField_CString(hOut,"mms_to_id",csValue[i]);
                }
		else if (!strcmp(csTmp, "from_node")) {
			PutField_CString(hOut,"mms_from_node",csValue[i]);
		}
		else if (!strcmp(csTmp, "to_node")) {
			PutField_CString(hOut,"mms_to_node",csValue[i]);
		}
		else if (!strcmp(csTmp, "from_service")) {
			PutField_CString(hOut, "mms_from_service", csValue[i]);
		}
		else if (!strcmp(csTmp, "to_service")) {
			PutField_CString(hOut, "mms_to_service", csValue[i]);
		}
		else if (!strcmp(csTmp,"fno")) {
			PutField_CString(hOut,"filing_number",csValue[i]);
                }
		else if (!strcmp(csTmp, "txndate")) {
			PutField_CString(hOut,"transmission_datetime",csValue[i]);
		}
		************************ */
		else {
                	PutField_CString(hOut,csTmp,csValue[i]);
		}

	}

	FREE_ME(csTmp);
	FREE_ME(csAttr);

	return iRet;
}


int initReplyFromRequest(const hash_t* hRequest, hash_t* hResponse)
{
        int     iRet = PD_OK;

	char	*csPtr;

DEBUGLOG(("initReplyFromRequest()\n"));
	if (GetField_CString(hRequest,"txn_code",&csPtr)) {
DEBUGLOG(("initReplyFromRequest()txn_code = [%s]\n",csPtr));
		PutField_CString(hResponse,"reply_txn_code",csPtr);
	}
	if (GetField_CString(hRequest,"org_txn_seq",&csPtr)) {
DEBUGLOG(("initReplyFromRequest()txn_seq = [%s]\n",csPtr));
		PutField_CString(hResponse,"org_txn_seq",csPtr);
	}

DEBUGLOG(("initReplyFromRequest() ret = [%d]\n",iRet));
	return iRet;
}



int FormatDTMsg(const hash_t* hIn,unsigned char *outMsg, const int iCnt)
{
	int 	iRet = PD_OK;
	int 	i;
	int 	iPtr;
	char    csTag[PD_TAG_LEN +1];
	char*	csBuf;
	char*	csTmp;

	csBuf = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);
	csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);

	for(i=0;i<iCnt;i++){

		sprintf(csBuf,"<%s %s='%d'>",PD_DT_ELEMENT,PD_ID_ELEMENT,i+1);
		strcat((char*)outMsg,csBuf);

		sprintf(csTag,"ret_%d",i+1);
		if (GetField_Int(hIn,csTag,&iPtr)) {
DEBUGLOG(("FormatDTMsg <%s> = <%d>\n",csTag,iPtr));
			sprintf(csBuf,"<ret>%d</ret>",iPtr);
			strcat((char*)outMsg,csBuf);
		}
		sprintf(csBuf,"</%s>",PD_DT_ELEMENT);
		strcat((char*)outMsg,csBuf);
	}

	FREE_ME(csBuf);
	FREE_ME(csTmp);
DEBUGLOG(("FormatDTMsg() ret = [%d]\n",iRet));
	return iRet;
}


int FormatMultiMsg(const hash_t* hIn,unsigned char *outMsg, const int iCnt)
{
	int iRet = PD_OK;
	int i /*, iTmp*/;
	double  dTmp;
	char*   csPtr;
	char    csTag[PD_TAG_LEN +1];
	char*   csBuf;
	char*   csTmp;
        char    cTmp;

	csBuf = (char*) malloc (PD_TMP_MSG_BUF_LEN +1);
	csTmp = (char*) malloc (PD_TMP_BUF_LEN +1);

	for(i=1;i<=iCnt;i++){
		sprintf(csTag,"mms_node_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			//strcpy(csTag,"mms_node_id");
			strcpy(csTag,"mmc_id");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"party_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			//strcpy(csTag,"party_id");
			strcpy(csTag,"pty_id");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"party_name_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			//strcpy(csTag,"party_name");
			strcpy(csTag,"pty_name");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"bank_acct_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"bank_acct");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"txn_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"txnid");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"dtl_txn_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"dtl_txnid");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"txn_code_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"txn_code");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"merchant_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"mid");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"psp_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"psp_id");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"mb_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"mb_id");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}
		
		sprintf(csTag,"bank_id_%d",i);
		if (GetField_CString(hIn,csTag,&csPtr)) {
			strcpy(csTag,"bank_id");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"txn_status_%d",i);
		if (GetField_Char(hIn,csTag,&cTmp)) {
                        sprintf((char*)csTmp,"%c",cTmp);
			strcpy(csTag,"txn_status");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
			strcat((char*)outMsg,csBuf);
		}

		sprintf(csTag,"ar_ind_%d",i);
		if (GetField_Char(hIn,csTag,&cTmp)) {
                        sprintf((char*)csTmp,"%c",cTmp);
			strcpy(csTag,"ar_ind");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
			sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
			strcat((char*)outMsg,csBuf);
		}

                sprintf(csTag,"isd_ind_%d",i);
                if (GetField_Char(hIn,csTag,&cTmp)) {
                        sprintf((char*)csTmp,"%c",cTmp);
                        strcpy(csTag,"isd_ind");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"txn_date_%d",i);
                if (GetField_CString(hIn,csTag,&csPtr)) {
                        strcpy(csTag,"txn_date");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"txn_amt_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"txnamt");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"txn_ccy_%d",i);
                if (GetField_CString(hIn,csTag,&csPtr)) {
                        strcpy(csTag,"ccy");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"adjustment_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"adjustment");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"exchange_rate_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"rate");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"processing_cost_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"pc");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"bank_charge_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"bk_chrg");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"bank_charge_refund_%d",i);
                if (GetField_Double(hIn,csTag,&dTmp)) {
                        sprintf((char*)csTmp,"%.2f",dTmp);
                        strcpy(csTag,"bk_chrg_refund");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csTmp));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csTmp,csTag);
                        strcat((char*)outMsg,csBuf);
                }

                sprintf(csTag,"filing_number_%d",i);
                if (GetField_CString(hIn,csTag,&csPtr)) {
                        strcpy(csTag,"filing_num");
DEBUGLOG(("FormatMsg <%s id='%d'> = <%s>\n",csTag,i,csPtr));
                        sprintf(csBuf,"<%s id='%d'>%s</%s>",csTag,i,csPtr,csTag);
                        strcat((char*)outMsg,csBuf);
                }


	}
	FREE_ME(csBuf);
	FREE_ME(csTmp);
DEBUGLOG(("FormatMultiMsg() ret = [%d]\n",iRet));
	return iRet;
}
