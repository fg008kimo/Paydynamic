#include <stdio.h>
#include <ctype.h>
#include "email.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "common.h"
#include "debug.h"
#include "freeme.h"
#include "dates.h"
#include "ascutility.h"

#define         DL      "&"
#define         FD      "="

char cDebug;
char* GetList(char* inList)
{
        char    *csBuf,*csTmpBuf;
        static char tmp[100];
        char    *p;

        csBuf = (char*) malloc (strlen(inList) +1);
        csTmpBuf = (char*) malloc (100 +1);
        strcpy(csBuf,inList);

        p = strtok(csBuf,",");
        if (p) {
                sprintf(tmp,"<%s>",p);
        }
        p = strtok(NULL,",");
        if (p) {
                sprintf(csTmpBuf,",<%s>",p);
                strcat(tmp,csTmpBuf);
        }


        FREE_ME(csBuf);
        FREE_ME(csTmpBuf);
        return tmp;
}

void addString(char** x,int *iIdx, const char *str)
{
        int i = *iIdx;
        x[i] = strdup(str);

        *iIdx = i +1;
}

int CovertStingToEmailBody(const char* DATA,int iLen,char** payload_text,int *iIdx)
{
	int	iRet = PD_OK;

	char	*csBuf;
	char	*p;


/* date */
	csBuf = (char*) malloc (128 +1);
	strcpy(csBuf,"Date: ");
        strcat(csBuf,get_RFC_2822_date());
        strcat(csBuf,"\n");
	addString(payload_text,iIdx,csBuf);

	FREE_ME(csBuf);
/* TO */
	p = GetField((unsigned char*)DATA,"TO",DL,FD);
	if (p) {
		csBuf = (char*) malloc (128 +1);
		strcpy(csBuf,"To: \"");
        	strcat(csBuf,GetList(p));
        	strcat(csBuf,"\"\n");
		addString(payload_text,iIdx,csBuf);
		FREE_ME(csBuf);
	}
/* From */
	p = GetField((unsigned char*)DATA,"FROM",DL,FD);
	if (p) {
		csBuf = (char*) malloc (128 +1);
		strcpy(csBuf,"From: \"");
        	strcat(csBuf,GetList(p));
        	strcat(csBuf,"\"\n");
		addString(payload_text,iIdx,csBuf);
		FREE_ME(csBuf);
	}
/* CC */
	p = GetField((unsigned char*)DATA,"CC",DL,FD);
	if (p) {
		csBuf = (char*) malloc (128 +1);
		strcpy(csBuf,"Cc: \"");
        	strcat(csBuf,GetList(p));
        	strcat(csBuf,"\"\n");
		addString(payload_text,iIdx,csBuf);
		FREE_ME(csBuf);
	}
/* message id */
        csBuf = (char*) malloc (128 +1);
	strcpy(csBuf,"Message-ID <");
        strcat(csBuf,jtime(getdatetime()));
        strcat(csBuf,random_gen(32));
        strcat(csBuf,"@testing.com>\n");
	addString(payload_text,iIdx,csBuf);
        FREE_ME(csBuf);

/* Subject */
        p = GetField((unsigned char*)DATA,"SUBJECT",DL,FD);
        if (p) {
                csBuf = (char*) malloc (128 +1);
                strcpy(csBuf,"Subject: ");
                strcat(csBuf,p);
                strcat(csBuf,"\n");
                addString(payload_text,iIdx,csBuf);
                FREE_ME(csBuf);
        }
/* Empty before body */
       addString(payload_text,iIdx," ");

/* MSG */
        p = GetField((unsigned char*)DATA,"MSG",DL,FD);
        if (p) {
DEBUGLOG(("p = [%s]\n",p));
                addString(payload_text,iIdx,p);
                FREE_ME(csBuf);
        }
	
	return iRet;
}
