/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/09/12              David Wong
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "UnwXml.h"
#include "common.h"
#include "utilitys.h"
#include "queue_defs.h"
#include "internal.h"
#include <zlib.h>
#include "ObjPtr.h"
#include <expat.h>
#include "b64.h"

#define	PD_CONCAT_STR		"."

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

void	UnwXml(char cdebug)
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
	char	csBuf[PD_TMP_BUF_LEN + 1];

	isNull = PD_TRUE;
DEBUGLOG(("depth = [%d]\n", depth));

DEBUGLOG(("element = [%s]\n", element));
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
	iIsTag = 1;

   	for (i = 0; attribute[i]; i += 2) {
		if (!strcmp(attribute[i],"id")) {
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
DEBUGLOG(("***[%d] %s = '%s'\n", i, attribute[i], attribute[i + 1]));
	}

DEBUGLOG(("*START***[%s] [%s]\n", element, csTmpTag));
DEBUGLOG(("*START*********************\n"));
DEBUGLOG(("\n"));
	depth++;
}

/* decrement the current level of the tree */
void
endElement(void *data, const char *el)
{
DEBUGLOG(("depth = [%d]\n", depth));
	if (iIsTag == 1) {
		char *csTmp;
		csTmp = (char*) malloc (PD_TMP_MSG_BUF_LEN + 1);
		csTag[iTotal] = strdup(csTmpTag);

		if (isNull == PD_TRUE) 
			csTmp[0] = '\0';
		else 
			sprintf(csTmp,"%s",last_content);
DEBUGLOG(("[%03d]<%s>%s</%s>\n", iTotal, csTmpTag, csTmp, csTmpTag));
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
	char *tmp = malloc((length*2)+1);
	strncpy(tmp, content, length);
	tmp[length] = '\0';
DEBUGLOG(("handle_data length = [%d] tmp = [%s]\n", length, tmp));
	isNull = PD_FALSE;
	data = (void *) tmp;
	last_content = tmp;	/* TODO: concatenate the text nodes? */
}

int BreakDownXMLMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
	int	iRet = PD_OK;
	int	i;
	int	userData = 0;
	int	done = 0;
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
	XML_SetCharacterDataHandler(parser, handle_data);

DEBUGLOG(("BreakDownXMLMsg try to parse\n"));
	if (!XML_Parse(parser, (char*)utfMsg, strlen((const char*)utfMsg), done)) {
DEBUGLOG(("BreakDownXMLMsg %s at line %d\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser)));
ERRLOG("UnwXml::BreakDownXMLMsg %s at line %d\n", XML_ErrorString(XML_GetErrorCode(parser)), XML_GetCurrentLineNumber(parser));
		return INT_BREAKDOWN_ERR;
	}
DEBUGLOG(("BreakDownXMLMsg after try to parse\n"));

	XML_ParserFree(parser);

DEBUGLOG(("BreakDownXMLMsg Total Count = [%d]\n",iTotal));
	for (i = 0; i < iTotal; i++) {
DEBUGLOG(("BreakDownXMLMsg [%03d] %s = %s\n",i,csTag[i],csValue[i]));
		PutField_CString(hOut,csTag[i],csValue[i]);
	}

	FREE_ME(utfMsg);
DEBUGLOG(("BreakDownXMLMsg Normal Exit iRet = [%d]\n",iRet));
	return iRet;
}

