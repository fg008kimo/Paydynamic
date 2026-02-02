/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/07/23		   Dirk Wong
Modify the structure of Email Template	  	   2014/11/11		   Elvis Wong
Remove the Email Alert Fail			   2015/02/12		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "myhash.h"
#include "myrecordset.h"
#include "internal.h"
#include "common.h"
#include "BOAlertEmail.h"

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

                                if ((iRet != INT_ERR) && (iToMatch & 1 << (iMatch+1))) {
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

	RecordSet_Destroy(rExclude);
      	FREE_ME(rExclude);

DEBUGLOG(("FunctExclude() Ret = [%d]\n",iRet));
        return iRet;
}

int GetFileContent(char *csFileName, char *csFilePath, char *csFileContent)
{
        int iRet = PD_OK;

        FILE *fp;

        char *csTmp;
        char csTag[PD_MAX_BUFFER + 1];

        csTmp = (char*) malloc (128);
        memset(csTag,0x00,PD_MAX_BUFFER+1);

        sprintf(csTmp,"%s/%s/%s",getenv("ALERT_TEMPLATE"),csFilePath,csFileName);

        fp = fopen(csTmp,"r");

        if (fp == NULL) {
		return INT_ERR;
        }

        while (!feof(fp))
        {
                fgets(&csTag[strlen(csTag)],PD_MAX_BUFFER,fp);
        }

        (void)fclose(fp);

        if (csTag[strlen(csTag)-1] == '\n') {
                csTag[strlen(csTag)-1] = '\0';
        }

        sprintf(csFileContent,csTag);

        FREE_ME(csTmp);

        return iRet;
}

int GetTemplateGlobalData(hash_t *hRls,int iTotalCnt,tpl_t *tpl)
{
        int iRet = PD_OK;

        int i = 0;

        char *csSection = NULL;
        char *csTagname = NULL;
        char *csType = NULL;
        int iValue = 0;
        double dValue = 0.0;
        char *csValue = NULL;

        char *csTmp;
        char csTag[PD_TAG_LEN+1];

        csTmp = (char*) malloc (128);

        for(i=0; i<iTotalCnt; i++) {

/* type */
		sprintf(csTag,"%d_type",i);
                if(GetField_CString(hRls,csTag,&csType)) {
DEBUGLOG(("GetTemplateGlobalData:: [%s] = [%s]\n",csTag,csType));
		}

/* tagname */ 
		sprintf(csTag,"%d_tagname",i);
               	if(GetField_CString(hRls,csTag,&csTagname)) {
DEBUGLOG(("GetTemplateGlobalData:: [%s] = [%s]\n",csTag,csTagname));
		}

/* section */
		sprintf(csTag,"%d_vsec",i);
             	if(GetField_CString(hRls,csTag,&csSection)) {
DEBUGLOG(("GetTemplateGlobalData:: [%s] = [%s]\n",csTag,csSection));
		}

/* value */
		if (!strcmp(csType,PD_TPL_GLOBAL_TYPE))	{
			if (!strcmp(csSection,PD_INT_TYPE)) {
                        	if(GetField_Int(hRls,csTagname,&iValue)){
                                	sprintf(csTmp,"%s",csTagname);
                                       	tpl_set_field_int_global(tpl, csTmp, iValue);
DEBUGLOG(("GetTemplateGlobalData(Fields):: [%s] = [%d]\n",csTagname,iValue));
                               	}
                     	}
                       	else if (!strcmp(csSection,PD_DOUBLE_TYPE)) {
                             	if(GetField_Double(hRls,csTagname,&dValue)){
                                     	sprintf(csTmp,"%s",csTagname);
                                      	tpl_set_field_double_global(tpl, csTmp, dValue);
DEBUGLOG(("GetTemplateGlobalData(Fields):: [%s] = [%lf]\n",csTagname,dValue));
                             	}
                     	}
                    	else if (!strcmp(csSection,PD_STRING_TYPE)) {
                            	if(GetField_CString(hRls,csTagname,&csValue)){
                                    	sprintf(csTmp,"%s",csTagname);
                                      	tpl_set_field_fmt_global(tpl, csTmp, "%s", csValue);
DEBUGLOG(("GetTemplateGlobalData(Fields):: [%s] = [%s]\n",csTagname,csValue));
                               	}
                   	}
		}

        }

        FREE_ME(csTmp);

        return iRet;
}

int GetSectionFields(hash_t *hContext,int iTotalCnt,int iMultiple,char *csSection,tpl_t *tpl)
{
        int iRet = PD_OK;

        int i = 0;
        int j = 0;
        int k = 0;

        char *csSectionField = NULL;
        char *csTagname = NULL;
        char *csType = NULL;
        int iValue = 0;
        double dValue = 0.0;
        char *csValue = NULL;

        char *csTagnameCode = NULL;
        char *csTagnameIdx = NULL;
        int iTagnameIdx = 0;
        int iIdx = 0;

        char csTag[PD_TAG_LEN+1];

        csTagnameCode = (char*) malloc (128);
        csTagnameIdx = (char*) malloc (128);

/* tagname_code */
        sprintf(csTagnameCode,"%s",csSection);
        strtok(csTagnameCode,PD_TPL_TAG_NAME_DELIMIT_SYMBOL);
//DEBUGLOG(("GetSectionFields:: csSection = [%s], csTagnameCode[%d] = [%s]\n",csSection,strlen(csTagnameCode),csTagnameCode));

	tpl_select_section(tpl,csTagnameCode);
//DEBUGLOG(("GetSectionFields:: Select Section!!!!!!\n"));

	for(i=0; i<iMultiple; i++) {
//DEBUGLOG(("GetSectionFields:: i = [%d]\n",i));

		for (j=0; j<iTotalCnt; j++) {

/* type */
			sprintf(csTag,"%d_type",j);
                      	if(GetField_CString(hContext,csTag,&csType)) {
//DEBUGLOG(("GetSectionFields:: [%s] = [%s]\n",csTag,csType));			
			}

/* tagname */
			sprintf(csTag,"%d_tagname",j);
                        if(GetField_CString(hContext,csTag,&csTagname)) {
//DEBUGLOG(("GetSectionFields:: [%s] = [%s]\n",csTag,csTagname));
			}

/* section */ 
			sprintf(csTag,"%d_vsec",j);
                        if(GetField_CString(hContext,csTag,&csSectionField)) {
//DEBUGLOG(("GetSectionFields:: [%s] = [%s]\n",csTag,csTagname));
			}			

/* value */
			if ((!strcmp(csSectionField,csSection)) &&
			    (strcmp(csTagname,csSection)))
			{
				sprintf(csTag,"%s",csTagname);
                             	sprintf(csTagnameCode,"%s",csTagname);
                            	strtok(csTagnameCode,PD_TPL_TAG_NAME_DELIMIT_SYMBOL);
                               	sprintf(csTagnameIdx,"%s",&csTag[strlen(csTagnameCode)+1]);	
//DEBUGLOG(("GetSectionFields:: csTagname = [%s], csTagnameIdx[%d] = [%s]\n",csTagname,strlen(csTagnameIdx),csTagnameIdx));
	
				strtok(csTagnameIdx,PD_TPL_TAG_NAME_DELIMIT_SYMBOL);
//DEBUGLOG(("GetSectionFields:: csTag = [%s], csTagnameIdx = [%s]\n",csTag,csTagnameIdx));
			
				sprintf(csTag,"%s",csTagnameIdx);
                            	iIdx = 1;
                              	iTagnameIdx = 0;
                             	for (k=1; k<=strlen(csTag); k++) {
                                	iIdx *= 10;
                                      	iTagnameIdx += ((csTag[(strlen(csTag)-k)]-0x30)*(iIdx/10));
                            	}
//DEBUGLOG(("GetSectionFields:: iTagnameIdx = [%d]\n",iTagnameIdx));

                           	if (iTagnameIdx == i) {

                             		if (!strcmp(csType,PD_TPL_SECTION_TYPE))
                                      	{
DEBUGLOG(("GetSectionFields(SubSection):: [%s] [%s] = [%d]\n",csTagname,csTagnameCode,iValue));
DEBUGLOG(("GetSectionFields(SubSection):: Not Support SubSection!!!\n"));
						iRet = INT_ERR;
                                       	}
                                       	else
                                      	{
                                       		sprintf(csTag,"%d_value",j);
                                           	if (!strcmp(csType,PD_INT_TYPE)) {
                                               		if(GetField_Int(hContext,csTagname,&iValue)){
                                                        	tpl_set_field_int(tpl, csTagnameCode, iValue);
DEBUGLOG(("GetSectionFields(Fields):: [%s] [%s] = [%d]\n",csTagname,csTagnameCode,iValue));
                                                 	}
                                            	}
                                             	else if (!strcmp(csType,PD_DOUBLE_TYPE)) {
                                                   	if(GetField_Double(hContext,csTagname,&dValue)){
                                                           	tpl_set_field_double(tpl, csTagnameCode, dValue);
DEBUGLOG(("GetSectionFields(Fields):: [%s] [%s] = [%lf]\n",csTagname,csTagnameCode,dValue));
                                             		}
                                               	}
                                             	else if (!strcmp(csType,PD_STRING_TYPE)) {
                                                   	if(GetField_CString(hContext,csTagname,&csValue)){
                                                            	tpl_set_field_fmt(tpl, csTagnameCode, "%s", csValue);
DEBUGLOG(("GetSectionFields(Fields):: [%s] [%s] = [%s]\n",csTagname,csTagnameCode,csValue));
                                                     	}
                                             	}
                                    	}
                              	}
			}
                }

                tpl_append_section(tpl);
//DEBUGLOG(("GetSectionFields:: Append Section!!!!!!\n"));

	}

        tpl_deselect_section(tpl);
//DEBUGLOG(("GetSectionFields:: Deselect Section!!!!!!\n"));

	FREE_ME(csTagnameCode);
        FREE_ME(csTagnameIdx);

        return iRet;
}

int GetTemplateData(hash_t *hContext,int iTotalCnt,tpl_t *tpl)
{
        int iRet = PD_OK;

        int i = 0;

        char *csSection = NULL;
        char *csTagname = NULL;
        char *csType = NULL;
        int iValue = 0;
        int iMultiple = 0;

        char csTag[PD_TAG_LEN+1];

        for(i=0; i<iTotalCnt; i++) {
		DEBUGLOG(("GetTemplateData:: i = [%d]\n",i));

/* type */
		sprintf(csTag,"%d_type",i);
                if(GetField_CString(hContext,csTag,&csType)) {
DEBUGLOG(("GetTemplateData:: [%s] = [%s]\n",csTag,csType));
		}

/* tagname */
		sprintf(csTag,"%d_tagname",i);
          	if(GetField_CString(hContext,csTag,&csTagname)) {
DEBUGLOG(("GetTemplateData:: [%s] = [%s]\n",csTag,csTagname));
		}

/* section */
		sprintf(csTag,"%d_vsec",i);
              	if(GetField_CString(hContext,csTag,&csSection)) {
DEBUGLOG(("GetTemplateData:: [%s] = [%s]\n",csTag,csSection));
		}

/* value */
		if ((!strcmp(csType,PD_TPL_SECTION_TYPE)) &&
	 	    (!strcmp(csTagname,csSection)))
		{
                  	sprintf(csTag,"%d_value",i);
                      	if(GetField_Int(hContext,csTagname,&iValue)) {

                       		if (iValue == 0)
                               	{
                                	iMultiple = 1;
                               	}
                                else
                               	{
                                     	iMultiple = iValue;
                               	}

DEBUGLOG(("GetTemplateFields:: [%s] = [%s]\n",csTag,csSection));
DEBUGLOG(("GetTemplateFields:: [%s] = [%d]\n",csTagname,iValue));
DEBUGLOG(("GetTemplateFields:: iMultiple = [%d]\n",iMultiple));

                             	GetSectionFields(hContext,iTotalCnt,iMultiple,csSection,tpl);
                      	}
		}

        }

        return iRet;
}

int GetEmailFunctionTemplate(hash_t *hRls)
{
        int     iRet = PD_OK;

	tpl_t 	*tpl = tpl_alloc();

	char 	*csHtmlContent = NULL;

	char    *content;
	
	int     iNextSeq = 0;
	
	char 	*csSource = NULL;
	char	*csFunct = NULL;

	char 	*csEmailSource = NULL;

	//char 	*csEmailTo = NULL;
	char 	*csEmailCc = NULL;
	char 	*csEmailBcc = NULL;
	char 	*csEmailFrom = NULL;
	char 	*csEmailSubject = NULL;
	
	char    *csEmailPrefix = NULL;
	char    *csEmailSuffix = NULL;
	char    *csEmailTime = NULL;
	char    *csEmailServer = NULL;	
	char    *csEmailDesc = NULL;	

/*
	char    *csEmailHeader = NULL;
	char    *csEmailCss = NULL;
	char    *csEmailBody = NULL;
	char    *csEmailFooter = NULL;
	char	*csEmailTemplate = NULL;	
*/

	char	csEmailHeader[PD_MAX_FILE_LEN + 1];	
	char	csEmailCss[PD_MAX_FILE_LEN + 1];	
	char	csEmailBody[PD_MAX_FILE_LEN + 1];	
	char	csEmailFooter[PD_MAX_FILE_LEN + 1];	
	char	csEmailTemplate[PD_MAX_FILE_LEN + 1];	

	int	i = 0;
	int 	iRecCnt = 0;

	int	iTmp = 0;
	
	char	cTmp;
        char    *csTmp;	
	char 	csTag[PD_MAX_FILE_LEN+1];

	csHtmlContent = (char*) malloc(PD_MAX_FILE_LEN + 1);

/*
	csEmailHeader = (char*) malloc(PD_MAX_FILE_LEN + 1);
	csEmailCss = (char*) malloc(PD_MAX_FILE_LEN + 1);
	csEmailBody = (char*) malloc(PD_MAX_FILE_LEN + 1);
	csEmailFooter = (char*) malloc(PD_MAX_FILE_LEN + 1);
	csEmailTemplate = (char*) malloc(PD_MAX_FILE_LEN + 1);
*/

	csEmailPrefix = (char*) malloc(PD_TAG_LEN + 1);
	csEmailSuffix = (char*) malloc(PD_TAG_LEN + 1);
	csEmailTime = (char*) malloc(PD_TAG_LEN + 1);
	csEmailServer = (char*) malloc(PD_TAG_LEN + 1);
	csEmailDesc = (char*) malloc(PD_TAG_LEN + 1);

	csTmp = (char*) malloc(PD_MAX_FILE_LEN + 1);

	hash_t  *hEmailTag = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hEmailTag,0);

	hash_t *hMailTo = NULL;

        recordset_t *rMailTo = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rMailTo, 0);

/* source */
        if (GetField_CString(hRls, "source", &csSource)) {
DEBUGLOG(("GetEmailFunctionTemplate:: source = [%s]\n", csSource));
        } else {
                iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: source NOT FOUND!!!\n"));
        }

/* funct */
        if (GetField_CString(hRls,"funct",&csFunct)) {
DEBUGLOG(("GetEmailFunctionTemplate:: funct = [%s]\n",csFunct));
        } else {
                iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: funct NOT FOUND!!!\n"));
        }

	if (iRet == PD_OK) {
/* Set Email Function Template for Send Alert */

		if ((!strcmp(csFunct, PD_EML_FUNCT_SETT_FAIL)) ||
		    (!strcmp(csFunct, PD_EML_FUNCT_SETT_SUCCESS)) ||
		    (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_FAIL)) ||
		    (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_SUCCESS)) ||
		    (!strcmp(csFunct, PD_EML_FUNCT_SETT_FAIL_MGT)) ||
		    (!strcmp(csFunct, PD_EML_FUNCT_SETT_SUCCESS_MGT))) 
		{
			sprintf(csEmailPrefix, "%s", "\0");
			sprintf(csEmailSuffix, "%s", "\0");
			sprintf(csEmailTime, "%s", "\0");
			sprintf(csEmailServer, "%s", "\0");
			sprintf(csEmailDesc, "%s", "\0");
		}

/* Get Email Function Template from DB */

DEBUGLOG(("GetEmailFunctionTemplate:: Call DBEmailFunctTemplate:: GetTemplate\n"));
        	DBObjPtr = CreateObj(DBPtr,"DBEmailFunctTemplate","GetTemplate");
        	if ((unsigned long)(*DBObjPtr)(hRls) == FOUND) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate:: found!!!\n"));
			
			if (GetField_CString(hRls,"mail_source",&csEmailSource)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_source = [%s]\n",csEmailSource));
                        }

/*
			if (GetField_CString(hRls,"mail_to",&csEmailTo)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_to = [%s]\n",csEmailTo));
                        }

			if (GetField_CString(hRls,"mail_cc",&csEmailCc)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_cc = [%s]\n",csEmailCc));
                        }

			if (GetField_CString(hRls,"mail_bcc",&csEmailBcc)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_bcc = [%s]\n",csEmailBcc));
                        }
*/

                	if (GetField_CString(hRls,"mail_from",&csEmailFrom)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_from = [%s]\n",csEmailFrom));
                	}

                	if (GetField_CString(hRls,"mail_subject",&csEmailSubject)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_subject = [%s]\n",csEmailSubject));
                	}

                	if (GetField_CString(hRls,"mail_header",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_header_tag = [%s]\n",csTmp));
				PutField_CString(hEmailTag,"email_header_tag",csTmp);
                	}

			if (GetField_CString(hRls,"mail_css",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_css_tag = [%s]\n",csTmp));
				PutField_CString(hEmailTag,"email_css_tag",csTmp);
                        }

			if (GetField_CString(hRls,"mail_body",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_body = [%s]\n",csTmp));
                                PutField_CString(hEmailTag,"email_body_tag",csTmp);
                        }

			if (GetField_CString(hRls,"mail_footer",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::email_footer_tag = [%s]\n",csTmp));
				PutField_CString(hEmailTag,"email_footer_tag",csTmp);
                        }

			if (GetField_Int(hRls,"next_seq",&iNextSeq)) {
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate::next_seq = [%d]\n",iNextSeq));
				PutField_Int(hRls,"next_seq",iNextSeq);
                        }

        	} else {
                	iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: GetTemplate:: template not found!!!\n"));
ERRLOG("BOAlertEmail::ValidateProcess::GetTemplate::template not found!!\n");
        	}
	}

	if (iRet == PD_OK) {

/* party_id */
        	if (GetField_CString(hRls,"party_id",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: party_id = [%s]\n",csTmp));
        	} else {
                	iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: party_id NOT FOUND!!!\n"));
        	}

/* party_type */
		if (!strcmp(csSource, PD_EML_SOURCE_MGT)) {
                	if (GetField_CString(hRls,"party_type",&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: party_type = [%s]\n",csTmp));
				cTmp = csTmp[0];
				RemoveField_CString(hRls,"party_type");
				PutField_Char(hRls,"party_type",cTmp);
                	} else {
                       		iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: party_type NOT FOUND!!!\n"));
                	}
	       	} else if ((!strcmp(csSource, PD_EML_SOURCE_CHANNEL)) ||
			  (!strcmp(csSource, PD_EML_SOURCE_BATCH)))
		{	
			if (GetField_Char(hRls,"party_type",&cTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: party_type = [%c]\n",cTmp));
                        } else {
                                iRet = INT_ERR;
DEBUGLOG(("GetEmailFunctionTemplate:: party_type NOT FOUND!!!\n"));
                        }
		}	
	
		if (iRet == PD_OK) {
/* Get Email To Recordset from DB*/

DEBUGLOG(("GetEmailFunctionTemplate:: Call DBEmailSetting:: GetNotifyList\n"));
                	DBObjPtr = CreateObj(DBPtr,"DBEmailSetting","GetNotifyList");
                	if ((unsigned long)(*DBObjPtr)(hRls,rMailTo) != FOUND) {
                	        iRet = INT_EML_EMAIL_ADDR_NOT_FOUND;
DEBUGLOG(("GetEmailFunctionTemplate::call DBEmailSetting::GetNotifyList() INT_EML_EMAIL_ADDR_NOT_FOUND!!\n"));
ERRLOG("BOAlertEmail::ValidateProcess::call DBEmailSetting::GetNotifyList() INT_EML_EMAIL_ADDR_NOT_FOUND!!\n");     
	           	}
		}

		if (iRet == PD_OK) {
/* Get Email To from Recordset */

			hMailTo = RecordSet_GetFirst(rMailTo);
                	while (hMailTo) {

				sprintf(csTag, "email_to_%d", iRecCnt);
				if (GetField_CString(hMailTo,csTag,&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: [%s] = [%s]\n",csTag,csTmp));

					PutField_CString(hRls,csTag,csTmp);
                        	}

				iRecCnt++;

                        	hMailTo = RecordSet_GetNext(rMailTo);
                	}
		}
		
		PutField_Int(hRls,"rec_cnt",iRecCnt);
DEBUGLOG(("GetEmailFunctionTemplate:: iRecCnt = [%d]\n",iRecCnt));
	}

	if (iRet == PD_OK) {
/* Get Email Function Template from text file */			

		if (GetField_CString(hEmailTag,"email_header_tag",&csTmp)) {
			if (GetFileContent(csTmp,PD_EML_EMAIL_STATIC_TEMPLATE_PATH,csEmailHeader) == PD_OK)
               		{
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailHeader) = [%s]\n", csEmailHeader));
              		} else {
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailHeader) Error!!!\n"));
                    		iRet = INT_ERR;
           		}
			sprintf(csEmailTemplate,"%s",csEmailHeader);
		} else {
DEBUGLOG(("GetEmailFunctionTemplate:: email_header_tag not found!!!\n"));			
			iRet = INT_ERR;
		}

		if (GetField_CString(hEmailTag,"email_css_tag",&csTmp)) {
			if (GetFileContent(csTmp,PD_EML_EMAIL_STATIC_TEMPLATE_PATH,csEmailCss) == PD_OK)
                	{
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailCss) = [%s]\n", csEmailCss));
               	 	} else {
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailCss) = [NULL]\n"));
                	}
			sprintf(csEmailTemplate,"%s\n%s",csEmailTemplate,csEmailCss);
		} else {
DEBUGLOG(("GetEmailFunctionTemplate:: email_css_tag not found!!!\n"));
		}

		if (GetField_CString(hEmailTag,"email_body_tag",&csTmp)) {
                	if (GetFileContent(csTmp,csEmailSource,csEmailBody) == PD_OK)
               	 	{
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailBody) = [%s]\n", csEmailBody));
                	} else {
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailBody) Error!!!\n"));
                        	iRet = INT_ERR;
                	}
			sprintf(csEmailTemplate,"%s\n%s",csEmailTemplate,csEmailBody);
		} else {
DEBUGLOG(("GetEmailFunctionTemplate:: email_body_tag not found!!!\n"));                              
                        iRet = INT_ERR;
		}	

		if (GetField_CString(hEmailTag,"email_footer_tag",&csTmp)) {
			if (GetFileContent(csTmp,PD_EML_EMAIL_STATIC_TEMPLATE_PATH,csEmailFooter) == PD_OK)
                	{
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailFooter) = [%s]\n", csEmailFooter));
                	} else {
DEBUGLOG(("GetEmailFunctionTemplate:: GetFileContent(csEmailFooter) = [NULL]\n"));
                	}
			sprintf(csEmailTemplate,"%s\n%s",csEmailTemplate,csEmailFooter);
		} else {
DEBUGLOG(("GetEmailFunctionTemplate:: email_footer_tag not found!!!\n"));
		}

DEBUGLOG(("GetEmailFunctionTemplate:: csEmailTemplate = [%s]\n", csEmailTemplate));

	}

	if (iRet == PD_OK) {
/* Load Tpl from a string */

        	if (tpl_from_string(tpl, csEmailTemplate, strlen(csEmailTemplate)) == TPL_OK) {
DEBUGLOG(("GetEmailFunctionTemplate:: Loading template file ok!!!\n"));
        	} else {
DEBUGLOG(("GetEmailFunctionTemplate:: Loading template file Error!!!\n"));
                	iRet = INT_ERR;	
		}

	}

	if (iRet == PD_OK) {
/* Set Tpl Global Parameters */

		// Email Cc
		tpl_set_field_fmt_global(tpl, "MAIL_CC", "%s", csEmailCc);
		
		// Email Bcc
		tpl_set_field_fmt_global(tpl, "MAIL_BCC", "%s", csEmailBcc);

		// Email From
		tpl_set_field_fmt_global(tpl, "MAIL_FROM", "%s", csEmailFrom);

		// Email Subject
		tpl_set_field_fmt_global(tpl, "MAIL_SUBJECT", "%s", csEmailSubject);		

		// Email Body
        	if(GetField_Int(hRls,"total_dyn",&iTmp)){
DEBUGLOG(("GetEmailFunctionTemplate:: total_dyn = [%d]\n",iTmp));
		
			// Get Template Global Data
			iRet = GetTemplateGlobalData(hRls, iTmp, tpl);
			
			if (iRet == PD_OK) {
				// Get Template Data
                        	iRet = GetTemplateData(hRls, iTmp, tpl);
			}
		}
		
		// Email Prefix
		tpl_set_field_fmt_global(tpl, "MAIL_PREFIX", "%s", csEmailPrefix);
			
		// Email Suffic
		tpl_set_field_fmt_global(tpl, "MAIL_SUFFIX", "%s", csEmailSuffix);

		// Email Time
		tpl_set_field_fmt_global(tpl, "TIME", "%s", csEmailTime);

		// Email Server
		tpl_set_field_fmt_global(tpl, "SERVER", "%s", csEmailServer);

		// Email Desc
		tpl_set_field_fmt_global(tpl, "DESC", "%s", csEmailDesc);
	}

	for (i=0; i<iRecCnt; i++) {

		if (iRet == PD_OK) {
/* Set Tpl Global Parameters (Email To) */

			// Email To
			sprintf(csTag, "email_to_%d", i);
               		if (GetField_CString(hRls,csTag,&csTmp)) {
DEBUGLOG(("GetEmailFunctionTemplate:: [%s] = [%s]\n",csTag,csTmp));
				tpl_set_field_fmt_global(tpl, "MAIL_TO", "%s", csTmp);
                	}

		}

		if (iRet == PD_OK) {	
/* Save file and Unload tpl */

                	content = malloc(tpl_length(tpl) + 1);
                	tpl_get_content(tpl, content);
                	(void)puts(content);
DEBUGLOG(("GetEmailFunctionTemplate:: content: \n[%s]\n",content));

			sprintf(csTag, "html_content_%d_%d", iNextSeq, i);
                	sprintf(csHtmlContent,"%s/%s",getenv("ALERT_TEMPLATE"),csTag);
		  	PutField_CString(hRls,csTag,csHtmlContent);	
                	tpl_save_as(tpl,csHtmlContent);
DEBUGLOG(("GetEmailFunctionTemplate:: csHtmlContent: \n[%s]\n",csHtmlContent));	

			FREE_ME(content);
		}

	}

	tpl_free(tpl);

	hash_destroy(hEmailTag);
        FREE_ME(hEmailTag);

	RecordSet_Destroy(rMailTo);
        FREE_ME(rMailTo);

	FREE_ME(csHtmlContent);

/*
	FREE_ME(csEmailHeader);
	FREE_ME(csEmailCss);
	FREE_ME(csEmailBody);
	FREE_ME(csEmailFooter);
	FREE_ME(csEmailTemplate);
*/

	FREE_ME(csEmailPrefix);
	FREE_ME(csEmailSuffix);
	FREE_ME(csEmailTime);
	FREE_ME(csEmailServer);
	FREE_ME(csEmailDesc);
	
        FREE_ME(csTmp);

        return iRet;
}

int SetFunctAlertType(int iSendEmail,hash_t *hRls)
{
	int iRet = PD_OK;
	
	char *csFunct = NULL;
	char *csPartyId = NULL;
	char cPartyType;
	
	csFunct = (char*) malloc(PD_TAG_LEN + 1);
	csPartyId = (char*) malloc(PD_TAG_LEN + 1);
	cPartyType = ' ';

/* funct */
        if (GetField_CString(hRls,"funct",&csFunct)) {
DEBUGLOG(("SetFunctAlertType:: funct = [%s]\n",csFunct));
        } else {
                iRet = INT_ERR;
DEBUGLOG(("SetFunctAlertType:: funct NOT FOUND!!!\n"));
        }

	if (iSendEmail == PD_EML_SEND_EMAIL_ALERT_FAIL) {
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Fail!!!\n"));	

		if (!strcmp(csFunct, PD_EML_FUNCT_SETT_ADMIN_MGT))
              	{
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Fail (MGT)!!!\n"));

			sprintf(csFunct, "%s", PD_EML_FUNCT_SETT_FAIL_MGT);
			sprintf(csPartyId, "%s", PD_EML_PARTY_ID_SETT_FAIL_MGT);
			cPartyType = PD_EML_PARTY_TYPE_SETT_FAIL_MGT;
            	}
              	else if ((!strcmp(csFunct, PD_EML_FUNCT_SETT_AUTO)) ||
                         (!strcmp(csFunct, PD_EML_FUNCT_SETT_MERCH)) ||
                         (!strcmp(csFunct, PD_EML_FUNCT_SETT_ADMIN)))
           	{
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Fail (Online)!!!\n"));

			sprintf(csFunct, "%s", PD_EML_FUNCT_SETT_FAIL);
                        sprintf(csPartyId, "%s", PD_EML_PARTY_ID_SETT_FAIL);
                        cPartyType = PD_EML_PARTY_TYPE_SETT_FAIL;
		}	
                else if ((!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_ADMIN)) ||
                         (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_MERCH)))
             	{
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Fail (Offline)!!!\n"));

			sprintf(csFunct, "%s", PD_EML_FUNCT_OL_SETT_FAIL);
                        sprintf(csPartyId, "%s", PD_EML_PARTY_ID_OL_SETT_FAIL);
                        cPartyType = PD_EML_PARTY_TYPE_OL_SETT_FAIL;
             	}
       	} else if (iSendEmail == PD_EML_SEND_EMAIL_ALERT_SUCCESS) {
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Success!!!\n"));	

		if (!strcmp(csFunct, PD_EML_FUNCT_SETT_ADMIN_MGT))
		{
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Success (MGT)!!!\n"));				
	
			sprintf(csFunct, "%s", PD_EML_FUNCT_SETT_SUCCESS_MGT);
                        sprintf(csPartyId, "%s", PD_EML_PARTY_ID_SETT_SUCCESS_MGT);
                        cPartyType = PD_EML_PARTY_TYPE_SETT_SUCCESS_MGT;
		}	
		else if ((!strcmp(csFunct, PD_EML_FUNCT_SETT_AUTO)) ||
			 (!strcmp(csFunct, PD_EML_FUNCT_SETT_MERCH)) ||
			 (!strcmp(csFunct, PD_EML_FUNCT_SETT_ADMIN)))
		{
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Success (Online)!!!\n"));	

			sprintf(csFunct, "%s", PD_EML_FUNCT_SETT_SUCCESS);
                        sprintf(csPartyId, "%s", PD_EML_PARTY_ID_SETT_SUCCESS);
                        cPartyType = PD_EML_PARTY_TYPE_SETT_SUCCESS;
		}
		else if ((!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_ADMIN)) ||
			 (!strcmp(csFunct, PD_EML_FUNCT_OL_SETT_MERCH)))
		{			
DEBUGLOG(("SetFunctAlertType:: Send Email Alert Success (Offline)!!!\n"));	

			sprintf(csFunct, "%s", PD_EML_FUNCT_OL_SETT_SUCCESS);
                        sprintf(csPartyId, "%s", PD_EML_PARTY_ID_OL_SETT_SUCCESS);
                        cPartyType = PD_EML_PARTY_TYPE_OL_SETT_SUCCESS;
		}
	}

/* funct */
       	PutField_CString(hRls,"funct",csFunct);
DEBUGLOG(("SetFunctAlertType:: funct = [%s]\n",csFunct));

/* party_id */
      	PutField_CString(hRls,"party_id",csPartyId);
DEBUGLOG(("SetFunctAlertType:: party_id = [%s]\n",csPartyId));

/* party_type */
      	PutField_Char(hRls,"party_type",cPartyType);
DEBUGLOG(("SetFunctAlertType:: party_type = [%c]\n",cPartyType));

	FREE_ME(csFunct);
	FREE_ME(csPartyId);

	return iRet;
}

int SendEmail(hash_t *hRls)
{
        int     iRet = PD_OK;

	int	iNextSeq = 0;

	int	i = 0;
	int	iRecCnt = 0;

	char	*csTmp;
        char    *csCmd;

	char 	csTag[PD_TAG_LEN+1];

        csTmp = (char*) malloc(PD_TAG_LEN + 1);
        csCmd = (char*) malloc(PD_MAX_FILE_LEN + 1);

	if (GetField_Int(hRls,"rec_cnt",&iRecCnt)) {
DEBUGLOG(("SendEmail:: rec_cnt = [%d]\n",iRecCnt));
	} else {
DEBUGLOG(("SendEmail:: (Default) rec_cnt = [%d]\n",iRecCnt));
	}
	
	if (GetField_Int(hRls,"next_seq",&iNextSeq)) {
DEBUGLOG(("SendEmail:: next_seq = [%d]\n",iNextSeq));
        } else {
		iRet = INT_ERR;
DEBUGLOG(("SendEmail:: next_seq not found!!!\n"));
ERRLOG("BOAlertEmail::SendEmail::next_seq not found!!\n");
	}

	if (iRet == PD_OK) { 
		for (i=0; i<iRecCnt; i++) {
			sprintf(csTag, "html_content_%d_%d", iNextSeq, i);
			if (GetField_CString(hRls,csTag,&csTmp)) {
DEBUGLOG(("SendEmail:: [%s] = [%s]\n",csTag,csTmp));
        			sprintf(csCmd,"%s/bin/batch/send_system_alert_email.sh %s",getenv("HOME"),csTmp);
DEBUGLOG(("SendEmail:: csCmd = [%s]\n",csCmd));
        			system(csCmd);
DEBUGLOG(("SendEmail:: Send Email [%d]!!!\n", i));
			}	
		}
	}

        FREE_ME(csTmp);
        FREE_ME(csCmd);

        return iRet;
}

int ProcessTpl(hash_t *hRequest)
{
	int iRet = PD_OK;
	int iDtlRet = NOT_FOUND;

	char *csSource = NULL;
	char *csFunct = NULL;
	
	char *csTagname = NULL;
	char *csType = NULL;
	int iValue = 0;
	double dValue = 0.0;
	char *csValue = NULL;
	char *csSection = NULL;

	int iSendEmail = 0;

	int i = 0;
	int iTotalCnt = 0;

	char cTmp;	
	char *csTmp;
	char csTag[PD_TAG_LEN+1];

	csTmp = (char*) malloc(PD_MAX_FILE_LEN + 1);

/* source */
	if (GetField_CString(hRequest, "source", &csSource)) {
DEBUGLOG(("ProcessTpl:: source = [%s]\n", csSource));
        }

/* funct */
        if (GetField_CString(hRequest,"funct",&csFunct)){
DEBUGLOG(("ProcessTpl:: funct = [%s]\n",csFunct));
        }	

/* party_id */
       	if (GetField_CString(hRequest,"party_id",&csTmp)) {
DEBUGLOG(("ProcessTpl:: party_id = [%s]\n",csTmp));
      	}

/* party_type */
	if (!strcmp(csSource, PD_EML_SOURCE_MGT)) {
		if (GetField_CString(hRequest,"party_type",&csTmp)) {
DEBUGLOG(("ProcessTpl:: (CString) party_type = [%s]\n",csTmp));
                }
	} else if ((!strcmp(csSource, PD_EML_SOURCE_CHANNEL)) ||
		  (!strcmp(csSource, PD_EML_SOURCE_BATCH))) 
	{ 
		if (GetField_Char(hRequest,"party_type",&cTmp)) {
DEBUGLOG(("ProcessTpl:: (Char) party_type = [%c]\n",cTmp));
                }
	}

/* total_dyn */
	if(GetField_Int(hRequest,"total_dyn",&iTotalCnt)){
DEBUGLOG(("ProcessTpl:: total_dyn = [%d]\n",iTotalCnt));
        } else {
DEBUGLOG(("ProcessTpl:: (Default) total_dyn = [%d]\n",iTotalCnt));
        }

      	for(i=0; i<iTotalCnt; i++){

        	sprintf(csTag,"%d_tagname",i);
           	if(GetField_CString(hRequest,csTag,&csTagname)){
DEBUGLOG(("ProcessTpl:: [%s] = [%s]\n",csTag,csTagname));
          	}

           	sprintf(csTag,"%d_vsec",i);
              	if(GetField_CString(hRequest,csTag,&csSection)){
DEBUGLOG(("ProcessTpl:: [%s] = [%s]\n",csTag,csSection));
           	}

              	sprintf(csTag,"%d_type",i);
              	if(GetField_CString(hRequest,csTag,&csType)){
DEBUGLOG(("ProcessTpl:: [%s] = [%s]\n",csTag,csType));
            	}

             	sprintf(csTag,"%d_value",i);
             	if (!strcmp(csType,PD_INT_TYPE)) {
                     	if(GetField_Int(hRequest,csTag,&iValue)){
				PutField_Int(hRequest,csTagname,iValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%d]\n",csTag,csTagname,iValue));
                     	}
              	}
            	else if (!strcmp(csType,PD_DOUBLE_TYPE)) {
                   	if(GetField_Double(hRequest,csTag,&dValue)){
				PutField_Double(hRequest,csTagname,dValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%lf]\n",csTag,csTagname,dValue));
                    	}
             	}
             	else if (!strcmp(csType,PD_STRING_TYPE)) {
                 	if(GetField_CString(hRequest,csTag,&csValue)){
				PutField_CString(hRequest,csTagname,csValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%s]\n",csTag,csTagname,csValue));
			}
               	}
              	else if (!strcmp(csType,PD_TPL_SECTION_TYPE)) {
                      	if(GetField_Int(hRequest,csTag,&iValue)){
				PutField_Int(hRequest,csTagname,iValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%d]\n",csTag,csTagname,iValue));
                    	}
               	}
          	else if (!strcmp(csType,PD_TPL_GLOBAL_TYPE)) {
			if (!strcmp(csSection,PD_INT_TYPE)) {		
                               	if(GetField_Int(hRequest,csTag,&iValue)){
					PutField_Int(hRequest,csTagname,iValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%d]\n",csTag,csTagname,iValue));
				}
			}
                        else if (!strcmp(csSection,PD_DOUBLE_TYPE)) {
                               	if(GetField_Double(hRequest,csTag,&dValue)){
					PutField_Double(hRequest,csTagname,dValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%lf]\n",csTag,csTagname,dValue));
				}
			}
                        else if (!strcmp(csSection,PD_STRING_TYPE)) {
                                if(GetField_CString(hRequest,csTag,&csValue)){
					PutField_CString(hRequest,csTagname,csValue);
DEBUGLOG(("ProcessTpl:: [%s][%s] = [%s]\n",csTag,csTagname,csValue));
				}
			}
          	}
DEBUGLOG(("ProcessTpl:: iTotalCnt[%d]\n",i));
	}
	
	if (iRet == PD_OK) {
/* Check Funct Exclude */
               	iDtlRet = FunctExclude(hRequest);

		if (iDtlRet == NOT_FOUND) {
			iSendEmail = PD_EML_SEND_EMAIL;
		}
		else if (iDtlRet == FOUND) {
			//iSendEmail = PD_EML_SEND_EMAIL_ALERT_FAIL;
		}
		else {
			iRet = INT_ERR;
		}
	}

	if (iSendEmail == PD_EML_SEND_EMAIL) {
/* Get Email Function Template */
		iRet = GetEmailFunctionTemplate(hRequest);	

DEBUGLOG(("ProcessTpl:: iRet(GetEmailFunctionTemplate) = [%d]\n",iRet));
		if (iRet == PD_OK) {
/* Send Email */
                	iRet = SendEmail(hRequest);

			iSendEmail = PD_EML_SEND_EMAIL_ALERT_SUCCESS;
        	}
/* 
		else if (iRet == INT_EML_EMAIL_ADDR_NOT_FOUND) {

			iRet = PD_OK;			

			iSendEmail = PD_EML_SEND_EMAIL_ALERT_FAIL;
		}
*/
	} 

	if (iRet == PD_OK) {
		if ((iSendEmail > PD_EML_SEND_EMAIL) && 
	    	    (strcmp(csSource, PD_EML_SOURCE_BATCH)))
  		{
/* Set Funct Alert Type */
			SetFunctAlertType(iSendEmail,hRequest);

/* Get Email Function Template */
                	iRet = GetEmailFunctionTemplate(hRequest);

                	if (iRet == PD_OK) {
/* Send Email (SUCCESS or Fail Alert) */
                	        iRet = SendEmail(hRequest);
                	}
		}
	}

	FREE_ME(csTmp);

	return iRet;
}

