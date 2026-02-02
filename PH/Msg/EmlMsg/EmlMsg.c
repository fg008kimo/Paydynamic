/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/01/27         	   Cody Chan
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "EmlMsg.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#include "b64.h"
char	cDebug;


void	EmlMsg(char cdebug)
{
	cDebug = cdebug;
}

int FormatMsg(const hash_t* hIn,unsigned char *outMsg,int *outLen)
{
	int	iRet = PD_OK;
	char	*csPtr;


DEBUGLOG(("FormatMsg()\n"));
	outMsg[0]= '\0';
        *outLen = 0;

/* from */
	if (GetField_CString(hIn,"from",&csPtr)) {
DEBUGLOG(("FormatMsg:: from = [%s]\n",csPtr));
		strcat((char*)outMsg,"FROM");
                strcat((char*)outMsg,MY_EML_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_EML_TOKEN);
	}

/* to */
	if (GetField_CString(hIn,"to",&csPtr)) {
DEBUGLOG(("FormatMsg:: to = [%s]\n",csPtr));
		strcat((char*)outMsg,"TO");
                strcat((char*)outMsg,MY_EML_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_EML_TOKEN);
	}

/* subject */
	if (GetField_CString(hIn,"subject",&csPtr)) {
DEBUGLOG(("FormatMsg:: subject = [%s]\n",csPtr));
		strcat((char*)outMsg,"SUBJECT");
                strcat((char*)outMsg,MY_EML_FIELD_TOKEN);
                strcat((char*)outMsg,csPtr);
                strcat((char*)outMsg,MY_EML_TOKEN);
	}
/* body */
	if (GetField_CString(hIn,"subject",&csPtr)) {
DEBUGLOG(("FormatMsg:: body = [%s]\n",csPtr));
		char*	csBuf;
		csBuf = (char*) malloc (PD_MAX_BUFFER + 1);
		base64_encode((unsigned char*)csPtr,strlen(csPtr),csBuf,PD_MAX_BUFFER);
		strcat((char*)outMsg,"BODY");
                strcat((char*)outMsg,MY_EML_FIELD_TOKEN);
                strcat((char*)outMsg,csBuf);
                strcat((char*)outMsg,MY_EML_TOKEN);
		FREE_ME(csBuf);
	}

DEBUGLOG(("FormatMsg() Exit\n"));
	return 	iRet;
}


int BreakDownMsg(hash_t *hOut,const unsigned char *inMsg,int inLen)
{
        int     iRet = PD_OK;
	char	*csPtr;
	int	iPtr;
	hash_t  *hRec;

        hRec = (hash_t*)  malloc (sizeof(hash_t));
        hash_init(hRec,0);
DEBUGLOG(("BreakDownMsg()\n"));
DEBUGLOG(("BreakDownMsg::DATA = [%s][%d]\n",inMsg,inLen));

	if (Str2Cls(hRec,(char*)inMsg,MY_EML_TOKEN, MY_EML_FIELD_TOKEN) == PD_OK) {
/* sender */		
		if (GetField_CString(hRec,"sender",&csPtr)) {
			PutField_CString(hOut,"sender",csPtr);
DEBUGLOG(("BreakDownMsg:: sender = [%s]\n",csPtr));
		}
/* text */		
		if (GetField_CString(hRec,"text",&csPtr)) {
			char	*csBuf;
			csBuf = (char*) malloc (strlen(csPtr) *2 +1);
			strcpy(csBuf,code_convert(PD_GB2312_CODE,PD_HOST_CODE,csPtr));
			PutField_CString(hOut,"mail_body",csBuf);
DEBUGLOG(("BreakDownMsg:: mail_body = [%s]\n",csPtr));
			FREE_ME(csBuf);
		}
/* ref_num */		
		if (GetField_CString(hRec,"ref_num",&csPtr)) {
			iPtr = ctos((const unsigned char*)csPtr,strlen(csPtr));
			PutField_Int(hOut,"ref_num",iPtr);
DEBUGLOG(("BreakDownMsg:: ref_num = [%d]\n",iPtr));
		}
/* seq_num */		
		if (GetField_CString(hRec,"seq_num",&csPtr)) {
			iPtr = ctos((const unsigned char*)csPtr,strlen(csPtr));
			PutField_Int(hOut,"seq_num",iPtr);
DEBUGLOG(("BreakDownMsg:: seq_num = [%d]\n",iPtr));
		}
/* total */		
		if (GetField_CString(hRec,"total",&csPtr)) {
			iPtr = ctos((const unsigned char*)csPtr,strlen(csPtr));
			PutField_Int(hOut,"total",iPtr);
DEBUGLOG(("BreakDownMsg:: total = [%d]\n",iPtr));
		}
/* scts */		
		if (GetField_CString(hRec,"scts",&csPtr)) {
			char	csTmpDatetime[PD_DATETIME_LEN +1];
			//yyyy
			memcpy(&csTmpDatetime[0],&csPtr[0],4);

			//mm
			memcpy(&csTmpDatetime[4],&csPtr[5],2);

			//dd
			memcpy(&csTmpDatetime[6],&csPtr[8],2);

			//HH
			memcpy(&csTmpDatetime[8],&csPtr[11],2);

			//MM
			memcpy(&csTmpDatetime[10],&csPtr[14],2);

			//SS
			memcpy(&csTmpDatetime[12],&csPtr[17],2);
			csTmpDatetime[PD_DATETIME_LEN] = '\0';
DEBUGLOG(("BreakDownMsg:: scts = [%s]\n",csPtr));
DEBUGLOG(("BreakDownMsg:: scts = [%s]\n",csTmpDatetime));
			strcpy(csTmpDatetime,UTC2Local(csTmpDatetime,PD_DESTZONE));
DEBUGLOG(("BreakDownMsg:: scts = [%s]\n",csTmpDatetime));
			PutField_CString(hOut,"send_datetime",csTmpDatetime);
		}
/* tag */		
		if (GetField_CString(hRec,"tag",&csPtr)) {
			PutField_CString(hOut,"tag",csPtr);
DEBUGLOG(("BreakDownMsg:: tag = [%s]\n",csPtr));
		}
/* has_missing_parts */		
		if (GetField_CString(hRec,"has_missing_parts",&csPtr)) {
			if (!strcmp(csPtr,"yes"))
				iPtr = 1;
			else 
				iPtr = 0;
			PutField_Int(hOut,"has_missing_parts",iPtr);
DEBUGLOG(("BreakDownMsg:: has_missing_parts = [%d]\n",iPtr));
		}
/* smsc */		
		if (GetField_CString(hRec,"smsc",&csPtr)) {
			PutField_CString(hOut,"smsc",csPtr);
DEBUGLOG(("BreakDownMsg:: smsc = [%s]\n",csPtr));
		}
/* sender_num_type */		
		if (GetField_CString(hRec,"sender_num_type",&csPtr)) {
			iPtr = ctos((const unsigned char*)csPtr,strlen(csPtr));
			PutField_Int(hOut,"sender_num_type",iPtr);
DEBUGLOG(("BreakDownMsg:: sender_num_type = [%d]\n",iPtr));
		}
	}

	hash_destroy(hRec);
        FREE_ME(hRec);
DEBUGLOG(("BreakDownMsg exit iRet = [%d]\n",iRet));
	return iRet;
}
