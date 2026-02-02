
/* Result Sets Interface */
#ifndef SQL_CRSR
#  define SQL_CRSR
  struct sql_cursor
  {
    unsigned int curocn;
    void *ptr1;
    void *ptr2;
    unsigned int magic;
  };
  typedef struct sql_cursor sql_cursor;
  typedef struct sql_cursor SQL_CURSOR;
#endif /* SQL_CRSR */

/* Thread Safety */
typedef void * sql_context;
typedef void * SQL_CONTEXT;

/* Object support */
struct sqltvn
{
  unsigned char *tvnvsn; 
  unsigned short tvnvsnl; 
  unsigned char *tvnnm;
  unsigned short tvnnml; 
  unsigned char *tvnsnm;
  unsigned short tvnsnml;
};
typedef struct sqltvn sqltvn;

struct sqladts
{
  unsigned int adtvsn; 
  unsigned short adtmode; 
  unsigned short adtnum;  
  sqltvn adttvn[1];       
};
typedef struct sqladts sqladts;

static struct sqladts sqladt = {
  1,1,0,
};

/* Binding to PL/SQL Records */
struct sqltdss
{
  unsigned int tdsvsn; 
  unsigned short tdsnum; 
  unsigned char *tdsval[1]; 
};
typedef struct sqltdss sqltdss;
static struct sqltdss sqltds =
{
  1,
  0,
};

/* File name & Package Name */
struct sqlcxp
{
  unsigned short fillen;
           char  filnam[29];
};
static struct sqlcxp sqlfpn =
{
    28,
    "offline_balance_migration.pc"
};


static unsigned int sqlctx = 1295514725;


static struct sqlexd {
   unsigned long  sqlvsn;
   unsigned int   arrsiz;
   unsigned int   iters;
   unsigned int   offset;
   unsigned short selerr;
   unsigned short sqlety;
   unsigned int   occurs;
            short *cud;
   unsigned char  *sqlest;
            char  *stmt;
   sqladts *sqladtp;
   sqltdss *sqltdsp;
   unsigned char  **sqphsv;
   unsigned long  *sqphsl;
            int   *sqphss;
            short **sqpind;
            int   *sqpins;
   unsigned long  *sqparm;
   unsigned long  **sqparc;
   unsigned short  *sqpadto;
   unsigned short  *sqptdso;
   unsigned int   sqlcmax;
   unsigned int   sqlcmin;
   unsigned int   sqlcincr;
   unsigned int   sqlctimeout;
   unsigned int   sqlcnowait;
            int   sqfoff;
   unsigned int   sqcmod;
   unsigned int   sqfmod;
   unsigned char  *sqhstv[1];
   unsigned long  sqhstl[1];
            int   sqhsts[1];
            short *sqindv[1];
            int   sqinds[1];
   unsigned long  sqharm[1];
   unsigned long  *sqharc[1];
   unsigned short  sqadto[1];
   unsigned short  sqtdso[1];
} sqlstm = {12,1};

/* SQLLIB Prototypes */
extern sqlcxt ( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlcx2t( void **, unsigned int *,
                   struct sqlexd *, struct sqlcxp * );
extern sqlbuft( void **, char * );
extern sqlgs2t( void **, char * );
extern sqlorat( void **, unsigned int *, void * );

/* Forms Interface */
static int IAPSUCC = 0;
static int IAPFAIL = 1403;
static int IAPFTL  = 535;
extern void sqliem( unsigned char *, signed int * );

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/03/09              Elvis Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define FILE_TITLE_ROW			1
#define FILE_START_ROW			2
#define FILE_END_ROW			1
#define REC_FIELD_DELIMITER   		"|"
#define PD_DEFAULT_DATE_FORMAT 		"%Y%m%d"
#define PD_DEFAULT_TIME_FORMAT      	"%H%M%S"

int 	INT_INVALID_RECORD[1024];
int 	INT_INVALID_FIELD[1024][28];
int 	INT_DUP_BANK_ACCT_NUM[1024];
int 	INT_INVALID_TXN_BKA[1024];
int 	INT_DUP_BAID[1024];
int 	INT_INVALID_TXN_BAI[1024];


int	i_action;
int	i_total_field;

char	cs_type[50 + 1];
char    cs_in_file_name[100 + 1];
char    cs_converted_file_name[100 + 1];

char    cDebug = 'Y';

OBJPTR(DB);
OBJPTR(BO);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);
int process_convert_file(hash_t* hRec);
int process_match_keyword(hash_t* hRec);
int check_title(const char *csLine, hash_t *hRls);
int check_detail(const char *csLine, hash_t *hRls);
int add_bank_acct_baid(hash_t *hRls);
int add_pid(hash_t *hRls);
int add_provider(hash_t *hRls);
int GetTitleName(int iField, char *csTitleName);
int strlen_content(char *s);
char *mystrtok_r(char *string, const char *seps, char **context);
char *_deleteCharacters(char *str, char *charSet);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

	hash_t *hRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRec, 0);

	iRet = parse_arg(argc,argv);
               
	if (iRet != SUCCESS) {
		printf("usage: -t type -i in_file_name -c converted_file_name -f total_field\n");
                return (iRet);
        } 

	if(iRet == PD_OK){
			
		//sprintf(cs_type, "%s", "bank_acct_baid");
		PutField_CString(hRec,"type",cs_type);
DEBUGLOG(("batch_proc:: type = [%s]\n", cs_type));
		
		//sprintf(cs_in_file_name, "%s", "/home/php3dev/offline_balance_migration/bank_acct_file.xls");
		PutField_CString(hRec,"in_file_name",cs_in_file_name);			
DEBUGLOG(("batch_proc:: in_file_name = [%s]\n", cs_in_file_name));

		//sprintf(cs_converted_file_name, "%s", "/home/php3dev/offline_balance_migration/bank_acct_file_converted.txt");	
		PutField_CString(hRec,"converted_file_name",cs_converted_file_name);	
DEBUGLOG(("batch_proc:: converted_file_name = [%s]\n", cs_converted_file_name));

		//i_total_field = 28;
		PutField_Int(hRec,"total_field",i_total_field);
DEBUGLOG(("batch_proc:: total_field = [%d]\n", i_total_field));

		PutField_Int(hRec,"action",i_action);
DEBUGLOG(("batch_proc:: action = [%d]\n", i_action));

                iRet = process_convert_file(hRec);
        }

        if(iRet == PD_OK){
                iRet = process_match_keyword(hRec);
        }

	if (iRet != PD_OK) {
		iRet = FAILURE;
	}

        hash_destroy(hRec);
        FREE_ME(hRec);

DEBUGLOG(("batch_proc:: iRet = [%d]\n", iRet));
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;

	i_action = 0;
	i_total_field = 0;
	strcpy(cs_type,"");
	strcpy(cs_in_file_name,"");
        strcpy(cs_converted_file_name,"");

	while ((c = getopt(argc,argv,"t:i:c:f:a:")) != EOF) {
                switch (c) {
                        case 't':
                                strcpy(cs_type, optarg);
                                break;
                        case 'i':
                                strcpy(cs_in_file_name, optarg);
				break;
                        case 'c':
                                strcpy(cs_converted_file_name, optarg);
                                break;
			case 'f':
				i_total_field = atoi(optarg);
				break;
			case 'a':
				i_action = atoi(optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_type, "") || !strcmp(cs_in_file_name, "") || !strcmp(cs_converted_file_name,"") || i_total_field == 0)
                return FAILURE;

        return SUCCESS;
}

int process_convert_file(hash_t* hRec)
{
	int iRet = PD_OK;

	int iStatus = 0;

	char *csInFileName = NULL;
	char *csConvertedFileName = NULL;

	char csSysCmd[PD_TMP_BUF_LEN*3] = "";

/* in_file_name */
        if (GetField_CString(hRec, "in_file_name", &csInFileName)) {
DEBUGLOG(("process_convert_file:: in_file_name = [%s]\n", csInFileName));
        }

/* converted_file_name */
        if (GetField_CString(hRec, "converted_file_name", &csConvertedFileName)) {
DEBUGLOG(("process_convert_file:: converted_file_name = [%s]\n", csConvertedFileName));
        }

/* do the conversion
example: ol_bal_mr_convert.sh "UTF-8" "UTF-8" "csInFileName" "csConvertedFileName"
*/

	snprintf(csSysCmd, sizeof(csSysCmd), "%s \"%s\" \"%s\" \"%s\" \"%s\"", "ol_bal_mr_convert.sh", "UTF-8", "UTF-8", csInFileName, csConvertedFileName);
DEBUGLOG(("process_convert_file:: call system command [%s][%d]\n", csSysCmd, strlen(csSysCmd)));

        iStatus = system(csSysCmd);
DEBUGLOG(("process_convert_file:: iStatus = [%d]\n", iStatus));

	iRet = WEXITSTATUS(iStatus);

        if (iRet != PD_OK) {
DEBUGLOG(("process_convert_file:: file conversion FAILURE!!!\n"));
ERRLOG("offline_balance_migration::process_convert_file:: file conversion FAILURE!!!\n");
       		iRet = PD_ERR;
        }

DEBUGLOG(("process_convert_file:: iRet = [%d]\n", iRet));
        return iRet;
}

int process_match_keyword(hash_t* hRec)
{
        int iRet = PD_OK;

	int iAction = 0;
	int iField = 0;
	int iTotalField = 0;
	int iTitleRow = 0;
	int iStartRow = 0;	
	int iEndRow = 0;
	int iCurrLine = 0;
	int iTotalLine = 0;
	int iSBlankLine = 0;
 	int iEBlankLine = 0;
	int iMatched = 0;	

	int iDtlLine = 0;

	char *csType = NULL;
	char *csConvertedFileName = NULL;
	char *csTmp = NULL;
	
	char csDelimiter[2] = "";	
	char cs_input_buf[PD_TMP_MSG_BUF_LEN] = "";
	char cs_tmp_input_buf[PD_TMP_MSG_BUF_LEN] = "";

	char csTag[PD_TAG_LEN];

	FILE *fin = NULL;

	hash_t *hFileTitleRec = (hash_t*) malloc (sizeof(hash_t));
       	hash_init(hFileTitleRec, 0);

      	hash_t *hFileDetailRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hFileDetailRec, 0);

/* action */
      	if (GetField_Int(hRec, "action", &iAction)) {
DEBUGLOG(("process_match_keyword:: action = [%d]\n",iAction));
             	PutField_Int(hFileDetailRec,"action",iAction);
	}

/* type */
        if (GetField_CString(hRec, "type", &csType)) {
DEBUGLOG(("process_match_keyword:: type = [%s]\n", csType));
        }

/* converted_file_name */
        if (GetField_CString(hRec, "converted_file_name", &csConvertedFileName)) {
DEBUGLOG(("process_match_keyword:: converted_file_name = [%s]\n", csConvertedFileName));
        }

/*
 * File Open
 */
        if (iRet == PD_OK) {
DEBUGLOG(("process_match_keyword:: Start Opening File...\n"));
                fin = fopen(csConvertedFileName, "r");
                if (fin == NULL) {
                        iRet = FAILURE;
DEBUGLOG(("process_match_keyword:: cannot open file [%s]!!!\n", csConvertedFileName));
ERRLOG("offline_balance_migration::process_match_keyword:: cannot open file [%s]!!!\n", csConvertedFileName);
                } else {

                        while (fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
                                if (strlen_content(cs_input_buf) == 0) {
                                        iSBlankLine++;
                                } else {
                                        break;
                                }
                        }
                        rewind(fin);
                        while (fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
                                if (strlen_content(cs_input_buf) == 0) {
                                        iEBlankLine++;
                                } else {
                                        iEBlankLine = 0;
                                }
                                iTotalLine++;
                        }
DEBUGLOG(("process_match_keyword:: total_line = [%d]\n",iTotalLine));
DEBUGLOG(("process_match_keyword:: starting_blank_line = [%d]\n",iSBlankLine));
DEBUGLOG(("process_match_keyword:: ending_blank_line = [%d]\n",iEBlankLine));
                }
        }

/*
 * File format
 */
        if (iRet == PD_OK) {
DEBUGLOG(("process_match_keyword:: Start Checking Format...\n"));

               	rewind(fin);
		iCurrLine = 0;
                iField = 0;

/* delimiter */
		sprintf(csDelimiter,"%s",REC_FIELD_DELIMITER);
DEBUGLOG(("process_match_keyword:: delimiter = [%s]\n",csDelimiter));

/* row_title */
		iTitleRow = FILE_TITLE_ROW + iSBlankLine;
DEBUGLOG(("process_match_keyword:: row_title = [%d]\n",iTitleRow));

/* row_start */
             	iStartRow = FILE_START_ROW + iSBlankLine;
DEBUGLOG(("process_match_keyword:: row_start = [%d]\n",iStartRow));

/* row_end */
          	iEndRow = FILE_END_ROW + iEBlankLine;
DEBUGLOG(("process_match_keyword:: row_end = [%d]\n",iEndRow));

/* total_field */
                if (GetField_Int(hRec, "total_field", &iTotalField)) {
DEBUGLOG(("process_match_keyword:: total_field = [%d]\n", iTotalField));
                }

/* count_field */
		while (fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
                	iCurrLine++;
                     	if (iCurrLine == iStartRow) {
                        	if (cs_input_buf[strlen(cs_input_buf)-1] == 0x0A) cs_input_buf[strlen(cs_input_buf)-1] = '\0';
                              	if (cs_input_buf[strlen(cs_input_buf)-1] == 0x0D) cs_input_buf[strlen(cs_input_buf)-1] = '\0';
                             	strcpy(cs_tmp_input_buf,cs_input_buf);
                               	csTmp = mystrtok(cs_tmp_input_buf, csDelimiter);
                            	while (csTmp != NULL) {
                                   	iField++;
                                    	csTmp = mystrtok(NULL, csDelimiter);
                            	}
// DEBUGLOG(("process_match_keyword:: line %03d count[%d]/total_field[%d] [%s]\n",iCurrLine,iField,iTotalField,cs_input_buf));
DEBUGLOG(("process_match_keyword:: count_field = [%d]\n",iField));
                                /* Total Field Matched */
                             	if (iField == iTotalField) {
                                   	iMatched = 1;
                               	}
                             	break; 
                     	}
          	}		
	}	
	
/*
 * Read File
 */
	if (iRet == PD_OK) {
DEBUGLOG(("process_match_keyword:: Start Reading File...\n"));

		rewind(fin);
                iCurrLine = 0;

		while (fgets(cs_input_buf, sizeof(cs_input_buf), fin) != NULL) {
                        iCurrLine++;

                        if (cs_input_buf[strlen(cs_input_buf)-1] == 0x0A) cs_input_buf[strlen(cs_input_buf)-1] = '\0';
                        if (cs_input_buf[strlen(cs_input_buf)-1] == 0x0D) cs_input_buf[strlen(cs_input_buf)-1] = '\0';

                	/* handle leading and trailing rows */
                        if (iCurrLine < iStartRow || iCurrLine > iTotalLine - iEndRow + 1) {
                                iDtlLine = 0;
                        } else {
                                iDtlLine++;
                        }

			/* ignore rows containing useless info */
                        if (strlen_content(cs_input_buf) == 0) {
                                if (iDtlLine == 0) {
// DEBUGLOG(("process_match_keyword:: line %03d ignore [%s]\n",iCurrLine,cs_input_buf));
                                } else {
// DEBUGLOG(("process_match_keyword:: line %03d ignore [%s]\n",iCurrLine,cs_input_buf));
                                }
                                continue;
                        }

			/* Check Title/Detail */
			if (iCurrLine == iTitleRow) {
				iRet = check_title(cs_input_buf, hFileTitleRec);
			} else if (iCurrLine > iTitleRow){
/* detail_tag */
				sprintf(csTag, "%d_detail", iCurrLine-iTitleRow);
				PutField_CString(hFileDetailRec,"detail_tag",csTag);

                        	iRet = check_detail(cs_input_buf, hFileDetailRec);
			}
		}

/* detail_total_rec */
		PutField_Int(hFileDetailRec,"detail_total_rec",iCurrLine-iTitleRow);
// DEBUGLOG(("process_match_keyword:: detail_total_rec = [%d]\n",iCurrLine-iTitleRow));

/* detail_total_field */
                PutField_Int(hFileDetailRec,"detail_total_field",iTotalField);
                PutField_Int(hFileTitleRec,"detail_total_field",iTotalField);
// DEBUGLOG(("process_match_keyword:: detail_total_field = [%d]\n",iTotalField));

	}

/*
 * File Close
 */
	
        if (iRet == PD_OK) {
DEBUGLOG(("process_match_keyword:: Start Closing File...\n"));

		if (fin) {
                	fclose(fin);
                	fin = NULL;
		}
        }

/*
 * Migrate Data
 */

        if (iRet == PD_OK) {
DEBUGLOG(("process_match_keyword:: Start Migrating Data...\n"));
		
		if (!strcmp(csType, "bank_acct_baid")) {
			iRet = add_bank_acct_baid(hFileDetailRec);	
		} else if (!strcmp(csType, "pid")) {
			iRet = add_pid(hFileDetailRec);
		} else if (!strcmp(csType, "provider")) {
			iRet = add_provider(hFileDetailRec);
		}
        }

	hash_destroy(hFileTitleRec);
       	FREE_ME(hFileTitleRec);

     	hash_destroy(hFileDetailRec);
      	FREE_ME(hFileDetailRec);

DEBUGLOG(("process_match_keyword:: iRet = [%d]\n", iRet));
        return iRet;
}

int check_title(const char *csLine, hash_t *hRls)
{
        int iRet = PD_OK;

        char *csTag = (char*) malloc (64);
        char *csLineField = NULL; 
	char *csRemainField = NULL;

        char csDelimiter[2] = "";
        char csNewField[PD_TMP_MSG_BUF_LEN] = ""; 
	char csNewLine[PD_TMP_MSG_BUF_LEN] = "";
       
	int iField = 0;

//DEBUGLOG(("check_title:: start!!!\n"));	

/* delimiter */
	sprintf(csDelimiter,"%s",REC_FIELD_DELIMITER);
//DEBUGLOG(("check_title:: delimiter = [%s]\n",csDelimiter));

        strcpy(csNewLine, csLine);

        csLineField = mystrtok_r(csNewLine, csDelimiter, &csRemainField);
        while (csLineField != NULL && iRet == PD_OK) {
                strcpy(csNewField, TrimAll((const unsigned char*)csLineField, strlen(csLineField)));

                iField++;

		sprintf(csTag, "title_%d", iField);

                if (*csNewField == '\0') {
                        csLineField = mystrtok_r(NULL, csDelimiter, &csRemainField);
//DEBUGLOG(("check_title:: [%s] = []\n",csTag));
                        continue;
                }

		PutField_CString(hRls,csTag,csNewField);	
//DEBUGLOG(("check_title:: [%s] = [%s]\n",csTag,csNewField));

		csLineField = mystrtok_r(NULL, csDelimiter, &csRemainField);
        }

        FREE_ME(csTag);

//DEBUGLOG(("check_title:: end!!!\n"));	
    	return iRet;
}

int check_detail(const char *csLine, hash_t *hRls)
{
        int iRet = PD_OK;

        char *csTag = (char*) malloc (64);
	char *csDetailTag = NULL;
        char *csLineField = NULL;
        char *csRemainField = NULL;
        
	char csDelimiter[2] = "";
        char csNewField[PD_TMP_MSG_BUF_LEN] = "";
        char csNewLine[PD_TMP_MSG_BUF_LEN] = "";

        int iField = 0;

//DEBUGLOG(("check_detail:: start!!!\n"));	

/* detail_tag */
        if (GetField_CString(hRls, "detail_tag", &csDetailTag)) {
//DEBUGLOG(("process_convert_file:: detail_tag = [%s]\n", csDetailTag));
        }

/* delimiter */
        sprintf(csDelimiter,"%s",REC_FIELD_DELIMITER);
//DEBUGLOG(("check_detail:: delimiter = [%s]\n",csDelimiter));

        strcpy(csNewLine, csLine);

        csLineField = mystrtok_r(csNewLine, csDelimiter, &csRemainField);
        while (csLineField != NULL && iRet == PD_OK) {
                strcpy(csNewField, TrimAll((const unsigned char*)csLineField, strlen(csLineField)));

                iField++;

		sprintf(csTag, "%s_%d", csDetailTag, iField);

                if (*csNewField == '\0') {
                        csLineField = mystrtok_r(NULL, csDelimiter, &csRemainField);
//DEBUGLOG(("check_detail:: [%s] = []\n",csTag));
                        continue;
                }

		PutField_CString(hRls,csTag,csNewField);	
//DEBUGLOG(("check_detail:: [%s] = [%s]\n",csTag,csNewField));

                csLineField = mystrtok_r(NULL, csDelimiter, &csRemainField);
        }

        FREE_ME(csTag);

//DEBUGLOG(("check_detail:: end!!!\n"));	
        return iRet;
}

int add_bank_acct_baid(hash_t *hRls)
{
	int iRet = PD_OK;
	int iDtlRet = PD_OK;
	int iTmpRet = FOUND;
	
	int iAction = 0;
	int iTotalRec = 0;
	int iTotalField = 0;
	int i = 0, j = 0;
	int iCreateBaidSwitch = 0; 
	//int iTmp;
	
	int iTotalInvalidRec = 0;
	int iTotalValidRec = 0;
	int iTotalBankAcctRec = 0;
        int iTotalInvalidBankAcctRec = 0;
        int iTotalValidBankAcctRec = 0;
	int iTotalMobileRec = 0;
	int iTotalBaidRec = 0;
	int iTotalTxnBKARec = 0;
	int iTotalTxnBKASuccessRec = 0;
	int iTotalTxnBKAFailRec = 0;
	int iTotalTxnBAIRec = 0;
	int iTotalTxnBAISuccessRec = 0;
	int iTotalTxnBAIFailRec = 0;

	char *csProvider = NULL;
	char *csBankAbbrevName = NULL;
	char *csRemainField = NULL;
	char *csGetField = NULL;
	
	char *csPid = (char*) malloc (64);
	char *csPspId = (char*) malloc (64);
	char *csField = (char*) malloc (64);
	char *csYear = (char*) malloc (64);
	char *csMonth = (char*) malloc (64);
	char *csDay = (char*) malloc (64);
	char *csTime = (char*) malloc (64);
	char *csDateTime = (char*) malloc (64);
	char *csTag = (char*) malloc (64);
	char *csTmp = (char*) malloc (64);

	char *csBankAcctType = (char*) malloc (64);
	char *csBankAcctNum = (char*) malloc (64);
	//char *csBaid = (char*) malloc (64);

	//char csBankAcctType[PD_ACCT_TYPE_LEN + 1] = "";
	char csBankCode[PD_BANK_CODE_LEN + 1] = "";
	char csExtBankCode[PD_EXT_BANK_CODE_LEN + 1] = "";
	//char csBankAcctNum[PD_BANK_ACCT_NUM_LEN + 1] = "";
	char csRegMobileNum[20 + 1] = "";
	char csBaid[PD_BAID_LEN + 1] = "";
        char csCurrDate[PD_DATE_LEN + 1] = "";
        char csCurrTime[PD_TIME_LEN + 1] = "";
	char csTitleName[PD_TAG_LEN + 1] = "";
	char csProviderTag[PD_TAG_LEN + 1] = "";
	char csBankAbbrevNameTag[PD_TAG_LEN + 1] = "";
	char csBankAcctNumTag[PD_TAG_LEN + 1] = "";
	
        time_t  tNow = time(NULL);
        struct  tm tStruct = *localtime(&tNow);

	hash_t *hDeDupRec;
        hDeDupRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hDeDupRec, 0);

	hash_t *hBankRec;
	hBankRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBankRec, 0);

	hash_t *hBaidRec;
        hBaidRec = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBaidRec, 0);

	hash_t *hRequest;
        hRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hRequest, 0);

	hash_t *hBaidRequest;
        hBaidRequest = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hBaidRequest, 0);

/* action */
	if (GetField_Int(hRls, "action", &iAction)) {
DEBUGLOG(("add_bank_acct_baid:: action = [%d]\n", iAction));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: action Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid:: action Not Found!!!\n");
        }

/* detail_total_rec */
        if (GetField_Int(hRls, "detail_total_rec", &iTotalRec)) {
DEBUGLOG(("add_bank_acct_baid:: detail_total_rec = [%d]\n", iTotalRec));
        } else {
		iRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: detail_total_rec Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid:: detail_total_rec Not Found!!!\n");
	}

/* detail_total_field */
        if (GetField_Int(hRls, "detail_total_field", &iTotalField)) {
DEBUGLOG(("add_bank_acct_baid:: detail_total_field = [%d]\n", iTotalField));
        } else {
		iRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: detail_total_field Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid:: detail_total_field Not Found!!!\n");
	}

	// bank_acct hRequest	
	PutField_CString(hRequest,"action", "A"); 
	PutField_CString(hRequest, "add_user", "SYSTEM");

	// baid hBaidRequest
	PutField_CString(hBaidRequest,"action", "A"); 
	PutField_CString(hBaidRequest, "add_user", "SYSTEM");
	PutField_CString(hBaidRequest, "status",  PD_BAID_STATUS_OPEN);
	
	if (iRet == PD_OK) {

		// Breakdown Data
		for (i=1; i<=iTotalRec; i++) {
DEBUGLOG(("add_bank_acct_baid:: ++++++++++++++++++++++++++++++++++++++++ Record[%d]:: Start ++++++++++++++++++++++++++++++++++++\n", i));
			
			iDtlRet = PD_OK;

			INT_INVALID_RECORD[i] = 0;	
			INT_DUP_BANK_ACCT_NUM[i] = 0;
			INT_INVALID_TXN_BKA[i] = 0;	
			INT_DUP_BAID[i] = 0;
			INT_INVALID_TXN_BAI[i] = 0;	

			for (j=1; j<=iTotalField; j++) {
				
				INT_INVALID_FIELD[i][j] = 0;

				sprintf(csTag, "%d_detail_%d", i, j);			
				if (GetField_CString(hRls, csTag, &csTmp)) {
DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csTmp));

					// 1 -22 bank acct fields
					// 23 - 30 baid fields
					if (j == 1) {
						sprintf(csProviderTag, "%d_%s", i, "prov");    
                                                PutField_CString(hBankRec, csProviderTag, csTmp);

DEBUGLOG(("add_bank_acct_baid:: Call DBPspMaster GetClientIdByClientName\n"));
        					DBObjPtr = CreateObj(DBPtr, "DBPspMaster","GetClientIdByClientName");
        					iRet = (unsigned long)(*DBObjPtr)(csTmp,csPid);
        					if (iRet == PD_OK) {
DEBUGLOG(("add_bank_acct_baid:: Call DBPspMaster GetClientIdByClientName SUCCESS!!!\n"));
DEBUGLOG(("add_bank_acct_baid:: Call DBPspMaster GetClientIdByClientName pid = [%s]\n", csPid));
        					} else {
                					iRet = FAILURE;
DEBUGLOG(("add_bank_acct_baid:: Call DBPspMaster GetClientIdByClientName FAILURE!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::Call DBPspMaster::GetClientIdByClientName Error!!!\n");
        					}

						PutField_CString(hRequest,"prov_id",csPid);	
					} else if (j == 2) {
						if (!strcmp(csTmp, "ECITIC")) {
							sprintf(csTmp, "%s", "CTB");
						}

						sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");      
                                                PutField_CString(hBankRec, csBankAbbrevNameTag, csTmp);

						PutField_CString(hRequest,"name",csTmp);	
	
//DEBUGLOG(("add_bank_acct_baid:: call BankDesc::FindBankCodeByBankAbbrevName()\n"));
                				DBObjPtr = CreateObj(DBPtr, "DBBankDesc", "FindBankCodeByBankAbbrevName");
                				iTmpRet = (unsigned long)(*DBObjPtr)(csTmp, csBankCode);
                				if(iTmpRet == FOUND){
//DEBUGLOG(("add_bank_acct_baid:: call BankDesc::FindBankCodeByBankAbbrevName() Found!!!\n"));
	
							PutField_CString(hRequest,"int_bank_code",csBankCode);											
							PutField_CString(hBaidRequest,"int_bank_code",csBankCode);
//DEBUGLOG(("add_bank_acct_baid:: call BankDesc::FindBankCodeByBankAbbrevName() int_bank_code = [%s]\n", csBankCode));
DEBUGLOG(("add_bank_acct_baid:: [%s][bank_code] = [%s]\n", csTag, csBankCode));	
                				} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: call BankDesc::FindBankCodeByBankAbbrevName() Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::call BankDesc::FindBankCodeByBankAbbrevName Fail!!!\n");
                				}		

					} else if (j == 3) {
						sprintf(csBankAcctNum, "%s", csTmp);

						sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");							
						PutField_CString(hBankRec, csBankAcctNumTag, csBankAcctNum);

                                        	PutField_CString(hRequest,"new_acct_num",csBankAcctNum);   
                                        	PutField_CString(hBaidRequest,"bank_acct_num",csBankAcctNum);   
                                	} else if (j == 4) {
						if (!strcmp(csTmp, "RMB")) {
                                        		PutField_CString(hRequest,"txn_ccy","CNY");
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = ccy Invalid!!!\n", csTag));
						}
					} else if (j == 5) {
                                	        PutField_CString(hRequest,"short_name",csTmp);
                               	 	} else if (j == 6) {
						sprintf(csBankAcctType, "%s", csTmp);

						if (!strcmp(csBankAcctType, "Deposit")) {
                                        		PutField_CString(hRequest,"acct_type","DSI");
						} else if (!strcmp(csBankAcctType, "Payout")) {
                                        		PutField_CString(hRequest,"acct_type","POA");
						} else if (!strcmp(csBankAcctType, "Intermediate")) {
                                        		PutField_CString(hRequest,"acct_type","ITM");
						} else if (!strcmp(csBankAcctType, "Pending Fund")) {
                                        		PutField_CString(hRequest,"acct_type","PDF");
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = acct_type Invalid!!!\n", csTag));
						}
                                	} else if (j == 7) {
						if (!strcmp(csTmp, "No")) {
                                        		PutField_CString(hRequest,"share","0");
						} else if (!strcmp(csTmp, "Yes")) {
                                        		PutField_CString(hRequest,"share","1");
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = share Invalid!!!\n, csTag"));
						}
                                	} else if (j == 8) {
						if (!strcmp(csTmp, "Disable")) {
                                	        	PutField_CString(hRequest,"sys_switch","0");
						} else if (!strcmp(csTmp, "Enable")) {
                                        		PutField_CString(hRequest,"sys_switch","1");
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = sys_switch Invalid!!!\n", csTag));
						}
                                	} else if (j == 9) {
						if (!strcmp(csTmp, "Disable")) {
                                                	PutField_CString(hRequest,"sms_stmt","0");
                                       	 	} else if (!strcmp(csTmp, "Enable")) {
                                         	       	PutField_CString(hRequest,"sms_stmt","1");
                                        	} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = sms_stmt Invalid!!!\n", csTag));
						}
                                	} else if (j == 10) {
						sprintf(csRegMobileNum, "%s", csTmp);
						if (strcmp(csRegMobileNum, "00000000000")) {
                                	        	PutField_CString(hRequest,"reg_mob_num",csRegMobileNum);
							iTotalMobileRec++;
						}
                                	} else if (j == 11) {
                                	        PutField_CString(hRequest,"owner_id",csTmp);
                                	} else if (j == 12) {
                                	        PutField_CString(hRequest,"owner",csTmp);
                                	} else if (j == 13) {
                                	        PutField_CString(hRequest,"branch_code",csTmp);
                                	} else if (j == 14) {
                                	        PutField_CString(hRequest,"province",csTmp);
                                	} else if (j == 15) {
                                	        PutField_CString(hRequest,"city",csTmp);
                                	} else if (j == 16) {
                                	        PutField_CString(hRequest,"branch",csTmp);
                                	} else if (j == 17) {
                                	        PutField_CString(hRequest,"swift_code",csTmp);
                                	} else if (j == 18) {
                                	        PutField_CString(hRequest,"remark",csTmp);
                                	} else if (j == 19) {
						if (!strcmp(csTmp, "Active")) {
                                        		PutField_CString(hRequest,"status_type","A");
				  		} else if (!strcmp(csTmp, "Not Yet Disposed")) {
                                        		PutField_CString(hRequest,"status_type","ND");
				  		} else if (!strcmp(csTmp, "Frozen")) {
                                        		PutField_CString(hRequest,"status_type","F");
				  		} else if (!strcmp(csTmp, "Not Yet Frozen")) {
                                        		PutField_CString(hRequest,"status_type","NF");
				  		} else if (!strcmp(csTmp, "Spare")) {
                                        		PutField_CString(hRequest,"status_type","S");
				  		} else if (!strcmp(csTmp, "Backup")) {
                                        		PutField_CString(hRequest,"status_type","B");
				  		} else if (!strcmp(csTmp, "New")) {
                                        		PutField_CString(hRequest,"status_type","N");	
				  		} else if (!strcmp(csTmp, "Disposed")) {
                                        		PutField_CString(hRequest,"status_type","D");
						} else {	
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;					
DEBUGLOG(("add_bank_acct_baid:: [%s] = status_type Invalid!!!\n", csTag));
						}
                                	} else if (j == 20) {
                                	        PutField_CString(hRequest,"rec_by",csTmp);
                                	} else if (j == 21) {
						sprintf(csField, "%s", csTmp);
						csGetField = mystrtok_r(csField, "-", &csRemainField);
						sprintf(csYear, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: year = [%s]\n", csYear));
					
						if (csRemainField != NULL) {	
							sprintf(csField, "%s", csRemainField);	
							csGetField = mystrtok_r(csField, "-", &csRemainField);
							sprintf(csMonth, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: month = [%s]\n", csMonth));
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
						}
	
						if (csRemainField != NULL) {					
							sprintf(csField, "%s", csRemainField);     
                                        		csGetField = mystrtok_r(csField, "-", &csRemainField);
							sprintf(csDay, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: day = [%s]\n", csDay));	
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
						}				

						//sprintf(csTime, "%s", "000000");
						//sprintf(csTime, "%s", "235959");
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csTime));					
						strftime(csCurrTime, sizeof(csCurrTime), PD_DEFAULT_TIME_FORMAT, &tStruct);
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csCurrTime));					
                                                sprintf(csTime, "%s", csCurrTime);
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csTime));					
	
						//sprintf(csDateTime, "%s%s%s%s", csYear, csMonth, csDay, csTime);
						sprintf(csDateTime, "%s%s%s", csYear, csMonth, csDay);
DEBUGLOG(("add_bank_acct_baid:: [%s][datetime] = [%s]\n", csTag, csDateTime));					

                                        	PutField_CString(hRequest,"rec_datetime",csDateTime);
                                	} else if (j == 22) {
						sprintf(csField, "%s", csTmp);
                                        	csGetField = mystrtok_r(csField, "-", &csRemainField);
                                        	sprintf(csYear, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: year = [%s]\n", csYear));

						if (csRemainField != NULL) {
                                        		sprintf(csField, "%s", csRemainField);
                                        		csGetField = mystrtok_r(csField, "-", &csRemainField);
                                        		sprintf(csMonth, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: month = [%s]\n", csMonth));
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
                                                        iDtlRet = PD_ERR;
                                                }

						if (csRemainField != NULL) {
							sprintf(csField, "%s", csRemainField);
                                        		csGetField = mystrtok_r(csField, "-", &csRemainField);
                                        		sprintf(csDay, "%s", csGetField);
//DEBUGLOG(("add_bank_acct_baid:: day = [%s]\n", csDay));
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
                                                        iDtlRet = PD_ERR;
                                                }

                                        	//sprintf(csTime, "%s", "000000");
                                        	//sprintf(csTime, "%s", "235959");
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csTime));
						strftime(csCurrTime, sizeof(csCurrTime), PD_DEFAULT_TIME_FORMAT, &tStruct);
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csCurrTime));
                                        	sprintf(csTime, "%s", csCurrTime);
//DEBUGLOG(("add_bank_acct_baid:: time = [%s]\n", csTime));

						//sprintf(csDateTime, "%s%s%s%s", csYear, csMonth, csDay, csTime);
                                        	sprintf(csDateTime, "%s%s%s", csYear, csMonth, csDay);
DEBUGLOG(("add_bank_acct_baid:: [%s][datetime] = [%s]\n",csTag,  csDateTime));

                                        	PutField_CString(hRequest,"key_expired_datetime",csDateTime);
					} else if (j == 23) {
						if (!strcmp(csTmp, "Yes")) {
							iCreateBaidSwitch = 1;
						} else if (!strcmp(csTmp, "No")) {
							iCreateBaidSwitch = 0;
						} else {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = create_baid_switch Invalid!!!\n", csTag));
						}
					} else if (j == 24) {
						if (iCreateBaidSwitch == 1) {
							sprintf(csBaid, "%s", csTmp);

							PutField_CString(hBaidRequest,"pre_assigned_baid",csBaid);
					
							iTotalBaidRec++;
						}
					} else if (j == 25) {
						if (iCreateBaidSwitch == 1) {
							PutField_CString(hBaidRequest,"init_bal",csTmp);
						}
                                	} else if (j == 26) {
						// provider
                                	} else if (j == 27) {
						if (iCreateBaidSwitch == 1) {
DEBUGLOG(("add_bank_acct_baid:: Call DBOLPspDetail GetPspIdByPspName\n"));
                                                	DBObjPtr = CreateObj(DBPtr, "DBOLPspDetail","GetPspIdByPspName");
                                                	iRet = (unsigned long)(*DBObjPtr)(csTmp,csPspId);
                                                	if (iRet == PD_OK) {
DEBUGLOG(("add_bank_acct_baid:: Call DBOLPspDetail GetPspIdByPspName SUCCESS!!!\n"));
DEBUGLOG(("add_bank_acct_baid:: Call DBOLPspDetail GetPspIdByPspName psp_id = [%s]\n", csPspId));
                                                	} else {
                                                        	iRet = FAILURE;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLPspDetail GetPspIdByPspName FAILURE!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::Call DBOLPspDetail::GetPspIdByPspName Error!!!\n");
                                                	}

							PutField_CString(hBaidRequest,"psp_id",csPspId);
						}
                                	} else if (j == 28) {
						// beneficiary bank name
                                	} else if (j == 29) {
						// bank account number
                                	} else if (j == 30) {
DEBUGLOG(("add_bank_acct_baid:: call OLDefSubProvider::GetSubProviderId()\n"));
                                                DBObjPtr = CreateObj(DBPtr, "DBOLDefSubProvider", "GetSubProviderId");
                                                iTmpRet = (unsigned long)(*DBObjPtr)(csTmp, hBaidRequest);
                                                if(iTmpRet == FOUND){
DEBUGLOG(("add_bank_acct_baid:: call OLDefSubProvider::GetSubProviderId() Found!!!\n"));

/* sub_provider_id */
							if (GetField_CString(hBaidRequest, "sub_provider_id", &csTmp)) {
DEBUGLOG(("add_bank_acct_baid:: call OLDefSubProvider::GetSubProviderId() sub_provider_id = [%s]\n", csTmp));

								PutField_CString(hRequest,"sub_provider",csTmp);
							}
DEBUGLOG(("add_bank_acct_baid:: [%s][sub_provider_id] = [%s]\n", csTag, csTmp));
						} else if (iTmpRet == NOT_FOUND) {
DEBUGLOG(("add_bank_acct_baid:: call OLDefSubProvider::GetSubProviderId() Not Found!!!\n"));

                                                } else {
                                                        iRet = FAILURE;
DEBUGLOG(("add_bank_acct_baid:: call OLDefSubProvider::GetSubProviderId() FAILURE!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::call OLDefSubProvider::GetSubProviderId FAILURE!!!\n");
                                                }
					}
                		} else {
					if (j == 1) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = prov_id Not Found!!!\n", csTag));
                                	} else if (j == 2) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;			
DEBUGLOG(("add_bank_acct_baid:: [%s] = name Not Found!!!\n", csTag));
					} else if (j == 3) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = new_acct_num Not Found!!!\n", csTag));
					} else if (j == 4) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: [%s] = txn_ccy Not Found!!!\n", csTag));
					} else if (j == 7) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: [%s] = share Not Found!!!\n", csTag));
					} else if (j == 8) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: [%s] = sys_switch Not Found!!!\n", csTag));
					} else if (j == 9) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;	
DEBUGLOG(("add_bank_acct_baid:: [%s] = sms_stmt Not Found!!!\n", csTag));
					} else if (j == 12) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = owner Not Found!!!\n", csTag));
					} else if (j == 14) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = province Not Found!!!\n", csTag));
					} else if (j == 15) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = city Not Found!!!\n", csTag));
					} else if (j == 16) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = branch Not Found!!!\n", csTag));
					} else if (j == 19) {
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = status_type Not Found!!!\n", csTag));
					} else if (j == 20) {	
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = rec_by Not Found!!!\n", csTag));
					} else if (j == 21) {
/*
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = rec_datetime Not Found!!!\n", csTag));
*/
						strftime(csCurrDate, sizeof(csCurrDate), PD_DEFAULT_DATE_FORMAT, &tStruct);
						PutField_CString(hRequest,"rec_datetime",csCurrDate);
DEBUGLOG(("add_bank_acct_baid:: date = [%s]\n", csCurrDate));						
					} else if (j == 23) {
/*
						INT_INVALID_RECORD[i] = i;
						INT_INVALID_FIELD[i][j] = j;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = create_baid_switch Not Found!!!\n", csTag));
*/
						iCreateBaidSwitch = 0;
DEBUGLOG(("add_bank_acct_baid:: [%s] = create_baid_switch [NULL]\n", csTag));
					} else if (j == 25) {
						if (iCreateBaidSwitch == 1) {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = init_bal Not Found!!!\n", csTag));
						}
					} else if (j == 27) {
						if (iCreateBaidSwitch == 1) {
							INT_INVALID_RECORD[i] = i;
							INT_INVALID_FIELD[i][j] = j;
							iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: [%s] = psp_id Not Found!!!\n", csTag));
						}
					}
				}	
			}

			if ((iRet == PD_OK) && (iDtlRet == PD_OK)) {
					iTotalBankAcctRec++;

                          	if (!strcmp(csBankAcctType, "Deposit")) {
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfDepositBankAccts, bank_acct_type = [%s]\n", csBankAcctType));
                                    	DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","ChkNumOfDepositBankAccts");
                                      	iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum);
                                    	if (iDtlRet < 1) {
						iDtlRet = PD_OK;
						iTotalValidBankAcctRec++;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfDepositBankAccts NOT FOUND, OK for Add!!!\n"));
                                    	} else {
						INT_DUP_BANK_ACCT_NUM[i] = i;	
						iTotalInvalidBankAcctRec++;
						//iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfDepositBankAccts DUPLICATED\n"));
//ERRLOG("offline_balance_migration::Authorize::DBOLBankAccts:ChkNumOfDepositBankAccts DUPLICATED!!!\n");
					}
                           	} else {
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfNotDepositBankAccts, bank_acct_type = [%s]\n", csBankAcctType));
                               		DBObjPtr = CreateObj(DBPtr,"DBOLBankAccts","ChkNumOfNotDepositBankAccts");
                                	iDtlRet = (unsigned long)(*DBObjPtr)(csBankCode, csBankAcctNum);
                                    	if (iDtlRet < 1) {
						iDtlRet = PD_OK;
						iTotalValidBankAcctRec++;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfNotDepositBankAccts NOT FOUND, OK for Add!!!\n"));
                                  	} else {
						INT_DUP_BANK_ACCT_NUM[i] = i;
						iTotalInvalidBankAcctRec++;
                                        	//iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAccts:ChkNumOfNotDepositBankAccts DUPLICATED\n"));
//ERRLOG("offline_balance_migration::Authorize::DBOLBankAccts:ChkNumOfNotDepositBankAccts DUPLICATED!!!\n");
                                     	}
                               	}
			}
				
			if (iAction > 0) {
                                if ((iRet == PD_OK) && (iDtlRet == PD_OK)) {
					iTotalTxnBKARec++;

DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBKA::Authorize()\n"));
        				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsBKA", "Authorize");
        				iDtlRet = (unsigned long)(*TxnObjPtr)(hRequest, hRequest, hRequest);
        				//iRet = (unsigned long)(*TxnObjPtr)(hRequest, hRequest, hRequest);
        				if(iDtlRet == PD_OK){
        				//if(iRet == PD_OK){
						iTotalTxnBKASuccessRec++;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBKA::Authorize() Success!!!\n"));
        				} else {
						INT_INVALID_TXN_BKA[i] = i;
						iTotalTxnBKAFailRec++;
						iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBKA::Authorize() Fail!!!\n"));
/*					
						iRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBKA::Authorize() Fail!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::call TxnOmtByUsBKA::Authorize Fail!!!\n");
*/
  	     				}
				}	

				if ((iRet == PD_OK) && (iDtlRet == PD_OK)) {
					if (iCreateBaidSwitch == 1) {
						iTotalTxnBAIRec++;

DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAcctId:GetBankAcctIdDtl, baid = [%s]\n", csBaid));
                				DBObjPtr = CreateObj(DBPtr,"DBOLBankAcctId","GetBankAcctIdDtl");
                				iDtlRet = (unsigned long)(*DBObjPtr)(csBaid, hBaidRec);
						if (iDtlRet != PD_OK) {
							//iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAcctId:GetBankAcctIdDtl Failed!!!\n"));
//ERRLOG("offline_balance_migration::Authorize::DBOLBankAcctId:GetBankAcctIdDtl Failed!!!\n");
                				} else {
                        	        		if (GetField_CString(hBaidRec, "org_baid", &csTmp)) {
								INT_DUP_BAID[i] = i;
								//iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAcctId:GetBankAcctIdDtl DUPLICATED!!!\n"));
//ERRLOG("offline_balance_migration::Authorize::DBOLBankAcctId:GetBankAcctIdDtl DUPLICATED!!!\n");
							} else {
DEBUGLOG(("add_bank_acct_baid:: Call DBOLBankAcctId:GetBankAcctIdDtl NOT FOUND, OK for Add!!!\n"));
							}
                        	        	}

DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBAI::Authorize()\n"));
                				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsBAI", "Authorize");
                				iDtlRet = (unsigned long)(*TxnObjPtr)(hBaidRequest, hBaidRequest, hBaidRequest);
                				//iRet = (unsigned long)(*TxnObjPtr)(hBaidRequest, hBaidRequest, hBaidRequest);
                				if(iDtlRet == PD_OK){
                				//if(iRet == PD_OK){
							iTotalTxnBAISuccessRec++;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBAI::Authorize() Success!!!\n"));
                				} else {
							INT_INVALID_TXN_BAI[i] = i;
							iTotalTxnBAIFailRec++;
                        	                	iDtlRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBAI::Authorize() Fail!!!\n"));
/*
                        				iRet = PD_ERR;
DEBUGLOG(("add_bank_acct_baid:: call TxnOmtByUsBAI::Authorize() Fail!!!\n"));
ERRLOG("offline_balance_migration::add_bank_acct_baid::call TxnOmtByUsBAI::Authorize Fail!!!\n");
*/        
	        				}
					}
				}
			}

                     	// Remove Fields
                      	RemoveField_CString(hRequest, "prov_id");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [1][prov_id]\n"));
                   	RemoveField_CString(hRequest, "name");
                     	RemoveField_CString(hRequest, "int_bank_code");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [2][name]\n"));
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [2][int_bank_code]\n"));
                     	RemoveField_CString(hRequest, "new_acct_num");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [3][new_acct_num]\n"));
                     	RemoveField_CString(hRequest, "txn_ccy");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [4][txn_ccy]\n"));
                     	RemoveField_CString(hRequest, "short_name");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [5][short_name]\n"));
                     	RemoveField_CString(hRequest, "acct_type");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [6][acct_type]\n"));
                      	RemoveField_CString(hRequest, "share");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [7][share]\n"));
                      	RemoveField_CString(hRequest, "sys_switch");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [8][sys_switch]\n"));
                     	RemoveField_CString(hRequest, "sms_stmt");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [9][sms_stmt]\n"));
                      	RemoveField_CString(hRequest, "reg_mob_num");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [10][reg_mob_num]\n"));
                     	RemoveField_CString(hRequest, "owner_id");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [11][owner_id]\n"));
                     	RemoveField_CString(hRequest, "owner");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [12][owner]\n"));
                      	RemoveField_CString(hRequest, "branch_code");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [13][branch_code]\n"));
                       	RemoveField_CString(hRequest, "province");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [14][province]\n"));
                     	RemoveField_CString(hRequest, "city");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [15][city]\n"));
                     	RemoveField_CString(hRequest, "branch");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [16][branch]\n"));
                     	RemoveField_CString(hRequest, "swift_code");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [17][swift_code]\n"));
                      	RemoveField_CString(hRequest, "remark");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [18][remark]\n"));
                      	RemoveField_CString(hRequest, "status_type");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [19][status_type]\n"));
                     	RemoveField_CString(hRequest, "rec_by");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [20][rec_by]\n"));
                     	RemoveField_CString(hRequest, "rec_datetime");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [21][rec_datetime]\n"));
                    	RemoveField_CString(hRequest, "key_expired_datetime");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [22][key_expired_datetime]\n"));
                  	RemoveField_CString(hRequest, "sub_provider");
// DEBUGLOG(("add_bank_acct_baid:: Remove hRequest Field [30][sub_provider]\n"));

                      	RemoveField_CString(hBaidRequest, "int_bank_code");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [2][int_bank_code]\n"));
                      	RemoveField_CString(hBaidRequest, "new_acct_num");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [3][new_acct_num]\n"));
                     	RemoveField_CString(hBaidRequest, "pre_assigned_baid");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [24][pre_assigned_baid]\n"));
                     	RemoveField_CString(hBaidRequest, "init_bal");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [25][init_bal]\n"));
                  	RemoveField_CString(hBaidRequest, "psp_id");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [27][psp_id]\n"));
                  	RemoveField_CString(hBaidRequest, "sub_provider_id");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRequest Field [30][sub_provider_id]\n"));

			RemoveField_CString(hBaidRec, "org_baid");
// DEBUGLOG(("add_bank_acct_baid:: Remove hBaidRec [org_baid]\n"));

DEBUGLOG(("add_bank_acct_baid:: ---------------------------------------- Record[%d]:: End ------------------------------------\n", i));
		}

DEBUGLOG(("add_bank_acct_baid:: ======================================== Input Data Record Summary:: Start ========================================\n"));
		// Total Number of Input Records		
DEBUGLOG(("add_bank_acct_baid:: Total Number of Input Records = [%d]\n", iTotalRec));

		// Total Number of InValid Input Records
		for (i=1; i<=iTotalRec; i++) {
                        if (INT_INVALID_RECORD[i] != 0) {
				iTotalInvalidRec++;
			}
		}		
DEBUGLOG(("add_bank_acct_baid:: Total Number of Invalid Input Records = [%d]\n", iTotalInvalidRec));
		
		// Total Number of Valid Input Record
		iTotalValidRec = iTotalRec - iTotalInvalidRec;
DEBUGLOG(("add_bank_acct_baid:: Total Number of Valid Input Records = [%d]\n", iTotalValidRec));

		// Error Record Log
		for (i=1; i<=iTotalRec; i++) {
			if (INT_INVALID_RECORD[i] != 0) {
/* rec */
DEBUGLOG(("add_bank_acct_baid:: Invalid Input Data Exists, rec = [%d]\n", i));

/* provider */
				sprintf(csProviderTag, "%d_%s", i, "prov");
                                if (GetField_CString(hBankRec, csProviderTag, &csProvider)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Input Data Exists, [%s] = [%s]\n", csProviderTag, csProvider));
                                }

/* bank_abbrev_name */
				sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");
                                if (GetField_CString(hBankRec, csBankAbbrevNameTag, &csBankAbbrevName)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Input Data Exists, [%s] = [%s]\n", csBankAbbrevNameTag, csBankAbbrevName));
                                }

/* bank_acct_num */
				sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");
				if (GetField_CString(hBankRec, csBankAcctNumTag, &csBankAcctNum)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Input Data Exists, [%s] = [%s]\n", csBankAcctNumTag, csBankAcctNum));
				}

				for (j=1; j<=iTotalField; j++) {
					if (INT_INVALID_FIELD[i][j] != 0) {
						if (GetTitleName(j, csTitleName) == PD_OK) {
DEBUGLOG(("add_bank_acct_baid:: Invalid Input Data Exists, field = [%s]\n", csTitleName));
						}
					}
				}
			}
		}
DEBUGLOG(("add_bank_acct_baid:: ======================================== Input Data Record Summary:: End ========================================\n"));

DEBUGLOG(("add_bank_acct_baid:: ======================================== Bank Acct Record File Duplicated Summary:: Start ========================================\n"));
		// Total Number of Input Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Bank Acct Records = [%d]\n", iTotalRec));

		for (i=1; i<=iTotalRec; i++) {

			sprintf(csTag, "%d_detail_%d", i, 3);
			if (GetField_CString(hRls, csTag, &csBankAcctNum)) {
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csBankAcctNum));
				
				for (j=1; j<=iTotalRec; j++) {

					sprintf(csTag, "%d_detail_%d", j, 3);
                        		if (GetField_CString(hRls, csTag, &csTmp)) {
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csTmp));

						if ((i!=j)
						    && (!strcmp(csBankAcctNum, csTmp))
						) 
						{

DEBUGLOG(("add_bank_acct_baid:: Duplicated Bank Acct Num Exists, rec[%d], rec[%d], bank_acct_num[%s]\n", i, j, csTmp));	
						}
					}
				}				
			}	
		}
DEBUGLOG(("add_bank_acct_baid:: ======================================== Bank Acct Record File Duplicated Summary:: End ========================================\n"));

DEBUGLOG(("add_bank_acct_baid:: ======================================== Registered Mobile Number Record File Duplicated Summary:: Start ========================================\n"));
                // Total Number of Input Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Registered Mobile Number Records = [%d]\n", iTotalMobileRec));

                for (i=1; i<=iTotalRec; i++) {

			sprintf(csTag, "%d_detail_%d", i, 2);
			if (GetField_CString(hRls, csTag, &csTmp)) {
				sprintf(csExtBankCode, "%s", csTmp);
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csExtBankCode));
			}

                        sprintf(csTag, "%d_detail_%d", i, 10);
                        if (GetField_CString(hRls, csTag, &csTmp)) {
				sprintf(csRegMobileNum, "%s", csTmp);
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csRegMobileNum));

                                for (j=1; j<=iTotalRec; j++) {

					sprintf(csTag, "%d_detail_%d", j, 10);
					if (GetField_CString(hRls, csTag, &csTmp)) {			
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csTmp));

						if ((i!=j)
                                                    && (!strcmp(csRegMobileNum, csTmp))
						    && (strcmp(csRegMobileNum, "00000000000"))
                                                ) {
                                        		sprintf(csTag, "%d_detail_%d", j, 2);
                                        		if (GetField_CString(hRls, csTag, &csTmp)) {
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csTmp));

                                                		if (!strcmp(csExtBankCode, csTmp))
                                                		{
	
DEBUGLOG(("add_bank_acct_baid:: Duplicated Registered Mobile Num Exists, rec[%d], rec[%d], reg_mobile_num[%s], ext_bank_code[%s]\n", i, j, csRegMobileNum, csExtBankCode));
                                                		}
							}
						}
                                        }
                                }
                        }
                }
DEBUGLOG(("add_bank_acct_baid:: ======================================== Registered Mobile Number Record File Duplicated Summary:: End ========================================\n"));

DEBUGLOG(("add_bank_acct_baid:: ======================================== Baid Record File Duplicated Summary:: Start ========================================\n"));
		// Total Number of Input Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Baid Records = [%d]\n", iTotalBaidRec));

		for (i=1; i<=iTotalRec; i++) {

                        sprintf(csTag, "%d_detail_%d", i, 24);
                        if (GetField_CString(hRls, csTag, &csTmp)) {
				sprintf(csBaid, "%s", csTmp);
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csBaid));
				
				for (j=1; j<=iTotalRec; j++) {

                                        sprintf(csTag, "%d_detail_%d", j, 24);
                                        if (GetField_CString(hRls, csTag, &csTmp)) {
// DEBUGLOG(("add_bank_acct_baid:: [%s] = [%s]\n", csTag, csTmp));
			
						if ((i!=j)
                                                    && (!strcmp(csBaid, csTmp))
                                                )
                                                {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Baid Exists, rec[%d], rec[%d], baid[%s]\n", i, j, csTmp));
                                                }
                                        }
                                }
                        }
                }

DEBUGLOG(("add_bank_acct_baid:: ======================================== Baid Record File Duplicated Summary:: End ========================================\n"));

DEBUGLOG(("add_bank_acct_baid:: ======================================== Bank Acct Record DB Duplicated Summary:: Start ========================================\n"));
		// Total Number of Bank Acct Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Bank Acct Records = [%d]\n", iTotalBankAcctRec));

		// Total Number of Invalid Bank Acct Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Invalid Bank Acct Records = [%d]\n", iTotalInvalidBankAcctRec));

		// Total Number of Valid Bank Acct Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Valid Bank Acct Records = [%d]\n", iTotalValidBankAcctRec));

		// Duplicated Bank Acct Num Error Log
               	for (i=1; i<=iTotalRec; i++) {
                   	if (INT_DUP_BANK_ACCT_NUM[i] != 0) {
/* rec */
DEBUGLOG(("add_bank_acct_baid:: Duplicated Bank Acct Num Exists, rec = [%d]\n", i));

/* provider */
                            	sprintf(csProviderTag, "%d_%s", i, "prov");
                             	if (GetField_CString(hBankRec, csProviderTag, &csProvider)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Bank Acct Num Exists, [%s] = [%s]\n", csProviderTag, csProvider));
                             	}

/* bank_abbrev_name */
                           	sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");
                            	if (GetField_CString(hBankRec, csBankAbbrevNameTag, &csBankAbbrevName)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Bank Acct Num Exists, [%s] = [%s]\n", csBankAbbrevNameTag, csBankAbbrevName));
                           	}

/* bank_acct_num */
                            	sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");
                           	if (GetField_CString(hBankRec, csBankAcctNumTag, &csBankAcctNum)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Bank Acct Num Exists, [%s] = [%s]\n", csBankAcctNumTag, csBankAcctNum));
                             	}
                     	}
           	}

DEBUGLOG(("add_bank_acct_baid:: ======================================== Bank Acct Record DB Duplicated Summary:: End ========================================\n"));

		if (iAction > 0) {
DEBUGLOG(("add_bank_acct_baid:: ======================================== Txn BKA Summary:: Start ========================================\n"));
			// Total Number of Txn BKA Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Txn BKA Records = [%d]\n", iTotalTxnBKARec));

			// Total Number of Fail Txn BKA Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Fail Txn BKA Records = [%d]\n", iTotalTxnBKAFailRec));

			// Total Number of Success Txn BKA Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Success Txn BKA Records = [%d]\n", iTotalTxnBKASuccessRec));

			// TxnOmtByUsBKA Error Log
			for (i=1; i<=iTotalRec; i++) {
                	        if (INT_INVALID_TXN_BKA[i] != 0) {
/* rec */
DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BKA Exists, rec = [%d]\n", i));				

/* provider */
                                	sprintf(csProviderTag, "%d_%s", i, "prov");
                                	if (GetField_CString(hBankRec, csProviderTag, &csProvider)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BKA Exists, [%s] = [%s]\n", csProviderTag, csProvider));
                                	}

/* bank_abbrev_name */
                                	sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");
                                	if (GetField_CString(hBankRec, csBankAbbrevNameTag, &csBankAbbrevName)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BKA Exists, [%s] = [%s]\n", csBankAbbrevNameTag, csBankAbbrevName));
                                	}

/* bank_acct_num */
                                	sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");
					if (GetField_CString(hBankRec, csBankAcctNumTag, &csBankAcctNum)) {
                                
DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BKA Exists, [%s] = [%s]\n", csBankAcctNumTag, csBankAcctNum));
                                	}
				}
			}
DEBUGLOG(("add_bank_acct_baid:: ======================================== Txn BKA Summary:: End ========================================\n"));

DEBUGLOG(("add_bank_acct_baid:: ======================================== Txn BAI Summary:: Start ========================================\n"));
			// Total Number of Txn BAI Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Txn BAI Records = [%d]\n", iTotalTxnBAIRec));
				
			// Total Number of Fail Txn BAI Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Fail Txn BAI Records = [%d]\n", iTotalTxnBAIFailRec));

			// Total Number of Success Txn BAI Records
DEBUGLOG(("add_bank_acct_baid:: Total Number of Success Txn BAI Records = [%d]\n", iTotalTxnBAISuccessRec));

			// Duplicated Baid Error Log
                	for (i=1; i<=iTotalRec; i++) {
                	        if (INT_DUP_BAID[i] != 0) {
/* rec */
DEBUGLOG(("add_bank_acct_baid:: Duplicated Baid Exists, rec = [%d]\n", i));

/* provider */
                                	sprintf(csProviderTag, "%d_%s", i, "prov");
                                	if (GetField_CString(hBankRec, csProviderTag, &csProvider)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Baid Exists, [%s] = [%s]\n", csProviderTag, csProvider));
                                	}

/* bank_abbrev_name */
                                	sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");
                                	if (GetField_CString(hBankRec, csBankAbbrevNameTag, &csBankAbbrevName)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Baid Exists, [%s] = [%s]\n", csBankAbbrevNameTag, csBankAbbrevName));
                                	}

/* bank_acct_num */
                                	sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");
                                	if (GetField_CString(hBankRec, csBankAcctNumTag, &csBankAcctNum)) {

DEBUGLOG(("add_bank_acct_baid:: Duplicated Baid Exists, [%s] = [%s]\n", csBankAcctNumTag, csBankAcctNum));
                                	}
                        	}
                	}
	
			// TxnOmtByUsBAI Error Log
			for (i=1; i<=iTotalRec; i++) {
                	        if (INT_INVALID_TXN_BAI[i] != 0) {
/* rec */
DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BAI Exists, rec = [%d]\n", i));   

/* provider */
                                	sprintf(csProviderTag, "%d_%s", i, "prov");
                                	if (GetField_CString(hBankRec, csProviderTag, &csProvider)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BAI Exists, provider = [%s]\n", csProvider));
                                	}

/* bank_abbrev_name */
                                	sprintf(csBankAbbrevNameTag, "%d_%s", i, "name");
                                	if (GetField_CString(hBankRec, csBankAbbrevNameTag, &csBankAbbrevName)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BAI Exists, bank_abbrev_name = [%s]\n", csBankAbbrevName));
                                	}

/* bank_acct_num */
                                	sprintf(csBankAcctNumTag, "%d_%s", i, "bank_acct_num");
                                	if (GetField_CString(hBankRec, csBankAcctNumTag, &csBankAcctNum)) {

DEBUGLOG(("add_bank_acct_baid:: Invalid Txn BAI Exists, bank_acct_num = [%s]\n", csBankAcctNum));
                                	}
                        	}
                	}
DEBUGLOG(("add_bank_acct_baid:: ======================================== Txn BAI Summary:: End ========================================\n"));
		}
	}

	hash_destroy(hDeDupRec);
        FREE_ME(hDeDupRec);

	hash_destroy(hBankRec);
	FREE_ME(hBankRec);

	hash_destroy(hBaidRec);
        FREE_ME(hBaidRec);

	hash_destroy(hRequest);
	FREE_ME(hRequest);

	hash_destroy(hBaidRequest);
	FREE_ME(hBaidRequest);

	FREE_ME(csPid);
	FREE_ME(csPspId);
	FREE_ME(csTag);
	FREE_ME(csTmp);
	FREE_ME(csField);
	FREE_ME(csYear);
	FREE_ME(csMonth);
	FREE_ME(csDay);
	FREE_ME(csTime);
	FREE_ME(csDateTime);

	FREE_ME(csBankAcctType);
	FREE_ME(csBankAcctNum);
	//FREE_ME(csBaid);

DEBUGLOG(("add_bank_acct_baid:: iRet = [%d]\n", iRet));
        return iRet;
}

int add_pid(hash_t *hRls)
{
	int iRet = PD_OK;
        //int iDtlRet = PD_OK;
        //int iTmpRet = FOUND;

	int iAction = 0;
        int iTotalRec = 0;
        int iTotalField = 0;
        //int i = 0, j = 0;

        //char *csTmp;

        //char *csTag = (char*) malloc (64);

        //hash_t *hRequest;
        //hRequest = (hash_t*) malloc (sizeof(hash_t));
        //hash_init(hRequest, 0);

/* action */
        if (GetField_Int(hRls, "action", &iAction)) {
DEBUGLOG(("add_pid:: action = [%d]\n", iAction));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_pid:: action Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_pid:: action Not Found!!!\n");
        }

/* detail_total_rec */
        if (GetField_Int(hRls, "detail_total_rec", &iTotalRec)) {
DEBUGLOG(("add_pid:: detail_total_rec = [%d]\n", iTotalRec));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_pid:: detail_total_rec Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_pid:: detail_total_rec Not Found!!!\n");
        }

/* detail_total_field */
        if (GetField_Int(hRls, "detail_total_field", &iTotalField)) {
DEBUGLOG(("add_pid:: detail_total_field = [%d]\n", iTotalField));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_pid:: detail_total_field Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_pid:: detail_total_field Not Found!!!\n");
        }

	//hash_destroy(hRequest);
        //FREE_ME(hRequest);

        //FREE_ME(csTag);

DEBUGLOG(("add_pid:: iRet = [%d]\n", iRet));
        return iRet;
}

int add_provider(hash_t *hRls)
{
        int iRet = PD_OK;
        //int iDtlRet = PD_OK;
        //int iTmpRet = FOUND;

	int iAction = 0;
        int iTotalRec = 0;
        int iTotalField = 0;
        //int i = 0, j = 0;

        //char *csTmp;

        //char *csTag = (char*) malloc (64);

        //hash_t *hRequest;
        //hRequest = (hash_t*) malloc (sizeof(hash_t));
        //hash_init(hRequest, 0);

/* action */
        if (GetField_Int(hRls, "action", &iAction)) {
DEBUGLOG(("add_provider:: action = [%d]\n", iAction));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_provider:: action Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_provider:: action Not Found!!!\n");
        }

/* detail_total_rec */
        if (GetField_Int(hRls, "detail_total_rec", &iTotalRec)) {
DEBUGLOG(("add_provider:: detail_total_rec = [%d]\n", iTotalRec));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_provider:: detail_total_rec Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_provider:: detail_total_rec Not Found!!!\n");
        }

/* detail_total_field */
        if (GetField_Int(hRls, "detail_total_field", &iTotalField)) {
DEBUGLOG(("add_provider:: detail_total_field = [%d]\n", iTotalField));
        } else {
                iRet = PD_ERR;
DEBUGLOG(("add_provider:: detail_total_field Not Found!!!\n"));
ERRLOG("offline_balance_migration::add_provider:: detail_total_field Not Found!!!\n");
        }

        //hash_destroy(hRequest);
        //FREE_ME(hRequest);

        //FREE_ME(csTag);

DEBUGLOG(("add_provider:: iRet = [%d]\n", iRet));
        return iRet;
}

int GetTitleName(int iField, char *csTitleName)
{
        int     iRet = PD_OK;

        if (iField == 1) {
                sprintf(csTitleName, "Intial Provider");
        } else if (iField == 2) {
                sprintf(csTitleName, "Bank Name");
        } else if (iField == 3) {
                sprintf(csTitleName, "Bank Account Number");
        } else if (iField == 4) {
                sprintf(csTitleName, "Currency");
        } else if (iField == 5) {
                sprintf(csTitleName, "Bank Account Short Name");
        } else if (iField == 6) {
                sprintf(csTitleName, "Bank Account Nature");
        } else if (iField == 7) {
                sprintf(csTitleName, "Share Account");
        } else if (iField == 8) {
                sprintf(csTitleName, "System Switch Enabled");
        } else if (iField == 9) {
                sprintf(csTitleName, "SMS System Enabled");
        } else if (iField == 10) {
                sprintf(csTitleName, "Registered Mobile Number");
        } else if (iField == 11) {
                sprintf(csTitleName, "Owner ID");
        } else if (iField == 12) {
                sprintf(csTitleName, "Owner Name");
        } else if (iField == 13) {
                sprintf(csTitleName, "Branch Code");
        } else if (iField == 14) {
                sprintf(csTitleName, "Province");
        } else if (iField == 15) {
                sprintf(csTitleName, "City");
        } else if (iField == 16) {
                sprintf(csTitleName, "Branch Name");
        } else if (iField == 17) {
                sprintf(csTitleName, "Swift Code");
        } else if (iField == 18) {
                sprintf(csTitleName, "Remarks");
        } else if (iField == 19) {
                sprintf(csTitleName, "Status");
        } else if (iField == 20) {
                sprintf(csTitleName, "Tested By");
        } else if (iField == 21) {
                sprintf(csTitleName, "Key/Account Received Date");
        } else if (iField == 22) {
                sprintf(csTitleName, "Key Expired Date");
        } else if (iField == 23) {
                sprintf(csTitleName, "BAID No.");
	} else if (iField == 24) {
                sprintf(csTitleName, "Pre-assigned BAID No.");
        } else if (iField == 25) {
                sprintf(csTitleName, "Initial BAID Balance");
        } else if (iField == 26) {
                sprintf(csTitleName, "Provider");
        } else if (iField == 27) {
                sprintf(csTitleName, "PID");
        } else if (iField == 28) {
                sprintf(csTitleName, "Beneficiary Bank Name");
        } else if (iField == 29) {
                sprintf(csTitleName, "Bank Account Nubmer");
        } else if (iField == 30) {
                sprintf(csTitleName, "Sub Provider");
        } else {
                sprintf(csTitleName, "%s", "\0");
        }

        return iRet;
}

int strlen_content(char *s)
{
        int j = 0;
        while (*s) {
                if ((*s & 0xc0) == 0x00 || (*s & 0xc0) == 0x40) {
                        if ((*s >= '0' && *s <= '9') ||
                            (*s >= 'A' && *s <= 'Z') ||
                            (*s >= 'a' && *s <= 'z')) {
                                j++;
                        }
                } else if ((*s & 0xc0) == 0xc0) {
                        j++;
                }
                s++;
        }
        return j;
}

char *mystrtok_r(char *string, const char *seps, char **context)
{
        char *head; /* Start of word */
        char *tail; /* End of word */

        /* If we're starting up, initialize context */
        if (string) {
                *context = string;
        }

        /* Get potential start of this next word */
        head = *context;
        if (head == NULL) {
                return NULL;
        }

        /* Skip any leading separators
        while (*head && strchr(seps, *head)) {
                head++;
        }*/

        /* Did we hit the end? */
        if (*head == 0) {
                /* Nothing left */
                *context = NULL;
                return NULL;
        }

        /* Skip over word */
        tail = head;
        while (*tail && !strchr(seps, *tail)) {
                tail++;
        }

        /* Save head for next time in context */
        if (*tail == 0) {
                *context = NULL;
        } else {
                *tail = 0;
                tail++;
                *context = tail;
        }

        /* Return current word */
        return head;
}

char *_deleteCharacters(char *str, char *charSet)
{
        int hash [256];
        int i;
        if(NULL == charSet)
                return str;

        for(i = 0; i < 256; i++) {
                hash[i] = 0;
        }

        for(i = 0; i < strlen(charSet); i++)
                hash[(unsigned char)charSet[i]] = 1;

        int currentIndex = 0;
        for(i = 0; i < strlen(str); i++)
        {
                if(!hash[(unsigned char)str[i]])
                str[currentIndex++] = str[i];
        }
        str[currentIndex] = '\0';
        return str;
}
