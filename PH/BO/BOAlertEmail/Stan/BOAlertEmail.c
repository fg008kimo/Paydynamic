/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/23		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOAlertEmail.h"
#include "time.h"

char    cDebug;
OBJPTR(DB);
OBJPTR(BO);

void BOAlertEmail(char    cdebug)
{
	cDebug = cdebug;
}


int FunctExclude(hash_t *hRls)
{
	int iRet = NOT_FOUND;
	int iDtlRet = PD_OK;

	int iMatch = 0, iToMatch = 0;
	char *csTagName = NULL, *csType = NULL, *csOperator = NULL, *csValue = NULL;
	char *csActualValue = NULL;
	double dActualValue = 0.0;
	int iActualValue = 0;

	hash_t *hExclude = NULL;

	recordset_t *rExclude = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rExclude, 0);

/* Get Email Function Exclude from DB */
	if (iRet == PD_OK) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBEmailFunctExclude","GetFunctExclude");
		iDtlRet = (unsigned long)(*DBObjPtr)(hRls, rExclude);
		if (iDtlRet == FOUND) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() Found\n"));

			hExclude = RecordSet_GetFirst(rExclude);
			while (hExclude) {

			/* tagname */
				if (GetField_CString(hExclude,"tagname",&csTagName)) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() tagname = [%s]\n",csTagName));
				}
			/* type */
				if (GetField_CString(hExclude,"type",&csType)) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() type = [%s]\n",csType));
				}
			/* operator */
				if (GetField_CString(hExclude,"operator",&csOperator)) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() operator = [%s]\n",csOperator));
				}
			/* value */
				if (GetField_CString(hExclude,"value",&csValue)) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() value = [%s]\n",csValue));
				}

			/* value - iMatch (GT:1, EQ:0, LT:-1) */
				if (!strcmp(csType, PD_STRING_TYPE)) {
					if (GetField_CString(hRls,csTagName,&csActualValue)) {
						iMatch = strcmp(csActualValue,csValue);
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_CString %s [%s]?[%s] iMatch[%d]\n",csTagName,csActualValue,csValue,iMatch));
					} else {
						iRet = INT_ERR;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_CString %s Not Found\n",csTagName));
					}

				} else if (!strcmp(csType, PD_DOUBLE_TYPE)) {
					if (GetField_Double(hRls,csTagName,&dActualValue)) {
						iMatch = (int)(dActualValue > atof(csValue) + 1E-6);
						if (iMatch == 0) iMatch = (int)(dActualValue + 1E-6 < atof(csValue)) * -1;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_Double %s [%.2lf]?[%.2lf] iMatch[%d]\n",csTagName,dActualValue,atof(csValue),iMatch));
					} else {
						iRet = INT_ERR;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_Double %s Not Found\n",csTagName));
					}

				} else if (!strcmp(csType, PD_INT_TYPE)) {
					if (GetField_Int(hRls,csTagName,&iActualValue)) {
						iMatch = (int)(iActualValue > atoi(csValue));
						if (iMatch == 0) iMatch = (int)(iActualValue < atoi(csValue)) * -1;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_Int %s [%d]?[%d] iMatch[%d]\n",csTagName,iActualValue,atoi(csValue),iMatch));
					} else {
						iRet = INT_ERR;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() GetField_Int %s Not Found\n",csTagName));
					}
				} 

			/* operator - iToMatch (GT:100, EQ:010, LT:001) */
				if (!strcmp(csOperator,PD_EML_OPERATOR_EQ1) ||
				    !strcmp(csOperator,PD_EML_OPERATOR_EQ2)) {
					iToMatch = 0b010;
				} else if (!strcmp(csOperator,PD_EML_OPERATOR_NE1) ||
					   !strcmp(csOperator,PD_EML_OPERATOR_NE2) ||
					   !strcmp(csOperator,PD_EML_OPERATOR_NE3)) {
					iToMatch = 0b101;
				} else if (!strcmp(csOperator,PD_EML_OPERATOR_GE)) {
					iToMatch = 0b110;
				} else if (!strcmp(csOperator,PD_EML_OPERATOR_LE)) {
					iToMatch = 0b011;
				} else if (!strcmp(csOperator,PD_EML_OPERATOR_GT)) {
					iToMatch = 0b100;
				} else if (!strcmp(csOperator,PD_EML_OPERATOR_LT)) {
					iToMatch = 0b001;
				} else {
					iRet = INT_ERR;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() operator %s Not Found\n",csOperator));
				}

DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() %d %d %d\n",iToMatch,1 << (iMatch+1),iToMatch & 1 << (iMatch+1)));

				if (iToMatch & 1 << (iMatch+1)) {
					iRet = FOUND;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() ** Matched\n"));
				}

				hExclude = RecordSet_GetNext(rExclude);
			}

		} else if (iDtlRet == NOT_FOUND) {
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() Not Found\n"));

		} else {
			iRet = INT_ERR;
DEBUGLOG(("FunctExclude() Call DBEmailFunctExclude::GetFunctExclude() FAILURE!!!\n"));
		}
	}

DEBUGLOG(("FunctExclude() Ret = [%d]\n",iRet));
	return iRet;
}

int PrepareTemplate(hash_t *hRls, tpl_t *tpl)
{
	int iRet = PD_OK;

	char *csFunct = NULL;
	char *csMailFrom = NULL, *csMailSubject = NULL, *csTemplate = NULL;

	hash_t *hRec = (hash_t*) malloc (sizeof(hRec));
	hash_init(hRec,0);

/* funct */
	if (GetField_CString(hRls,"funct",&csFunct)) {
		PutField_CString(hRec,"funct",csFunct);
DEBUGLOG(("PrepareTemplate() funct = [%s]\n",csFunct));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("PrepareTemplate() funct NOT FOUND!!!\n"));
	}

/* Get Email Function Template from DB */
	if (iRet == PD_OK) {
DEBUGLOG(("PrepareTemplate() Call DBEmailFunctTemplate::GetTemplate()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBEmailFunctTemplate","GetTemplate");
		if ((unsigned long)(*DBObjPtr)(hRec) == FOUND) {

			/* mail_from */
			if (GetField_CString(hRec,"mail_from",&csMailFrom)) {
DEBUGLOG(("PrepareTemplate() call DBEmailFunctTemplate::GetTemplate() mail_from = [%s]\n",csMailFrom));
			}

			/* mail_subject */
			if (GetField_CString(hRec,"mail_subject",&csMailSubject)) {
DEBUGLOG(("PrepareTemplate() call DBEmailFunctTemplate::GetTemplate() mail_subject = [%s]\n",csMailSubject));
			}

			/* template */
			if (GetField_CString(hRec,"template",&csTemplate)) {
// DEBUGLOG(("PrepareTemplate() call DBEmailFunctTemplate::GetTemplate() template = \n%s\n",csTemplate));
			}

		} else {
			iRet = INT_ERR;
DEBUGLOG(("PrepareTemplate() Call DBEmailFunctTemplate::GetTemplate() NOT FOUND!!!\n"));
ERRLOG("BOAlertEmail::PrepareTemplate() Call DBEmailFunctTemplate::GetTemplate() NOT FOUND!!!\n");
		}
	}

/* Load Tpl from String */
	if (iRet == PD_OK) {
		if (tpl_from_string(tpl, csTemplate, strlen(csTemplate)) != TPL_OK) {
			iRet = INT_ERR;
DEBUGLOG(("PrepareTemplate() Loading Template FAILURE!!!\n"));
ERRLOG("BOAlertEmail::PrepareTemplate() Loading Template FAILURE!!!\n");
		}
	}

/* Set Field in Tpl */
	if (iRet == PD_OK) {
	/* mail_from */
		tpl_set_field_fmt_global(tpl, "MAIL_FROM", "%s", csMailFrom);

	/* mail_subject */
		tpl_set_field_fmt_global(tpl, "MAIL_SUBJECT", "%s", csMailSubject);
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

DEBUGLOG(("PrepareTemplate() Ret = [%d]\n",iRet));
	return iRet;
}


int SendTemplate(hash_t *hRls, tpl_t *tpl)
{
	int iRet = PD_OK;

	char *csMailTo = NULL;
	char *content = NULL;

	char *csTmp;
	char cTmp;

	hash_t *hMailTo = NULL;

	recordset_t *rMailTo = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rMailTo, 0);

/* funct */
	if (GetField_CString(hRls,"funct",&csTmp)) {
DEBUGLOG(("SendTemplate() funct = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("SendTemplate() funct NOT FOUND!!!\n"));
	}

/* party_type */
	if (GetField_Char(hRls,"party_type",&cTmp)) {
DEBUGLOG(("SendTemplate() party_type = [%c]\n",cTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("SendTemplate() party_type NOT FOUND!!!\n"));
	}

/* party_id */
	if (GetField_CString(hRls,"party_id",&csTmp)) {
DEBUGLOG(("SendTemplate() party_id = [%s]\n",csTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("SendTemplate() party_id NOT FOUND!!!\n"));
	}

/* send_mail */
	if (GetField_Char(hRls,"send_mail",&cTmp)) {
DEBUGLOG(("SendTemplate() send_mail = [%c]\n",cTmp));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("SendTemplate() send_mail NOT FOUND!!!\n"));
	}

/* log_prefix */
	if (GetField_Char(hRls,"log_prefix",&csTmp)) {
DEBUGLOG(("SendTemplate() ** log_prefix = [%s]\n",csTmp));
	}

/* mail_to */
	if (GetField_CString(hRls,"mail_to",&csMailTo)) {
DEBUGLOG(("SendTemplate() ** mail_to = [%s]\n",csMailTo));
		hMailTo = (hash_t*) malloc (sizeof(hash_t));
		hash_init(hMailTo, 0);
		PutField_CString(hMailTo, "mail_to", csMailTo);
		RecordSet_Add(rMailTo, hMailTo);
	} else {
DEBUGLOG(("SendTemplate() Call DBEmailSetting::GetNotifyList()\n"));
		DBObjPtr = CreateObj(DBPtr,"DBEmailSetting","GetNotifyList");
		if ((unsigned long)(*DBObjPtr)(hRls,rMailTo) != FOUND) {
			iRet = INT_ERR;
DEBUGLOG(("SendTemplate() call DBEmailSetting::GetNotifyList() FAILURE!!\n"));
		}
	}

/* Send Email */
	if (iRet == PD_OK) {
		hMailTo = RecordSet_GetFirst(rMailTo);
		while (hMailTo) {
			/* mail_to */
			tpl_set_field_fmt_global(tpl, "MAIL_TO", "%s", csMailTo);

			content = (char*) malloc (tpl_length(tpl) + 1);

			tpl_get_content(tpl, content);

			if (SendEmail(hRls, content) != PD_OK) {
				iRet = INT_ERR;
DEBUGLOG(("SendTemplate() SendEmailString FAILURE!!!\n"));
				break;
			}

			FREE_ME(content);

			hMailTo = RecordSet_GetNext(rMailTo);
		}
	}

	RecordSet_Destroy(rMailTo);
	FREE_ME(rMailTo);

DEBUGLOG(("SendTemplate() Ret = [%d]\n",iRet));
	return iRet;
}


int SendEmail(hash_t *hRls, char *content)
{
	int iRet = PD_OK;

	char cSendMail = ' ';
	char *escapecontent = NULL;
	char *csLogPrefix = NULL, csLogFile[PD_TMP_BUF_LEN + 1];
	char csCmd[PD_TMP_BUF_LEN * 3 + 1];

	struct tm *tm;
	struct timespec tv;
	char csBuf[PD_TMP_BUF_LEN];
	FILE *stream = NULL;

/* send_mail */
	if (GetField_Char(hRls,"send_mail",&cSendMail)) {
// DEBUGLOG(("SendEmail() ** send_mail = [%c]\n",cSendMail));
	}

/* log_prefix */
	if (GetField_Char(hRls,"log_prefix",&csLogPrefix)) {
// DEBUGLOG(("SendEmail() log_prefix = [%s]\n",csLogPrefix));
	}


/* Valiate */
	if (iRet == PD_OK) {
		/* content */
DEBUGLOG(("SendEmail() content =\n%s\n",content));

		char *pch = strstr(content, DELIMITER);
		if (pch != NULL) {
			iRet = INT_ERR;
DEBUGLOG(("SendEmail() content NOT COMPLETED!!!\n"));
ERRLOG("BOAlertEmail::SendEmail() content NOT COMPLETED!!!\n");
		}
	}


/* Send */
	if (iRet == PD_OK) {
		clock_gettime(CLOCK_REALTIME, &tv);
		tm = localtime(&tv.tv_sec);
		/*
		sprintf(csBuf, "%04d%02d%02d.%02d%02d%02d%09ld.%ld",
			tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_nsec,
			(long)getpid());
		*/
		sprintf(csBuf, "%04d%02d%02d.%02d%09ld",
			tm->tm_year+1900, tm->tm_mon+1, tm->tm_mday,
			tm->tm_sec, tv.tv_nsec);
		if (csLogPrefix == NULL) {
			sprintf(csLogFile,"%s/%s-%s.log",getenv("LOGPATH"),"send_alert",csBuf);
		} else {
			sprintf(csLogFile,"%s/%s-%s.log",getenv("LOGPATH"), csLogPrefix,csBuf);
		}

		/* Save Content */
		if (cSendMail == 'Y') {
			stream = fopen(csLogFile, "wb"); 
			if (stream != NULL) {
				if (fwrite(content, strlen(content), 1, stream) == 1) {
DEBUGLOG(("SendEmail() Template Saved as [%s]\n",csLogFile));

				} else {
					// iRet = INT_ERR;
DEBUGLOG(("SendEmail() fwrite() error!!!\n"));
				}
				(void)fclose(stream);

			} else {
				// iRet = INT_ERR;
DEBUGLOG(("SendEmail() fopen() error!!!\n"));
			}
		}

		/* Escape Content */
		escapecontent = escapeshellarg(content);
		if (escapecontent != NULL) {

			if (strlen(escapecontent) > strlen(content) + 2) {
DEBUGLOG(("SendEmail() escapecontent = \n%s\n",escapecontent));
			}

			/* Send Content */
			if (cSendMail == 'Y') {
				sprintf(csCmd,"echo %s | /usr/sbin/sendmail -t &", escapecontent);
				system(csCmd);
printf("Email Sent\n");
DEBUGLOG(("SendEmail() Email Sent\n"));

			/* Do Not Send Content */
			} else {
				sprintf(csCmd,"echo %s", escapecontent);
				system(csCmd);
printf("Email Not Sent (Testing)\n");
DEBUGLOG(("SendEmail() Email Not Sent (Testing)\n"));

			}

			FREE_ME(escapecontent);

		} else {
			iRet = INT_ERR;
DEBUGLOG(("SendEmail() escapeshellarg error!!!\n"));
		}
	}

DEBUGLOG(("SendEmail() Ret = [%d]\n",iRet));
	return iRet;
}


char* GetTimeNowInFormat(char *csTemplate)
{
	static char csDateTime[PD_TMP_BUF_LEN + 1];
	time_t now;
	struct tm tStruct;

	time(&now);
	tStruct = *localtime(&now);
	strftime(csDateTime,sizeof(csDateTime),csTemplate,&tStruct);

	return csDateTime;
}

