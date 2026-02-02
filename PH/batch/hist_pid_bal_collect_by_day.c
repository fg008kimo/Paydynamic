
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "hist_pid_bal_collect_by_day.pc"
};


static unsigned int sqlctx = 804909773;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
5,0,0,1,97,0,6,177,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2019. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.
 
Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/04/29              [WMC]
Add TxnBalanceLog::IsCompleted Check               2020/03/24              [ZBL]
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
#include "internal.h"
#include "hist_pid_bal_collect_by_day.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_last_phdate[PD_TMP_BUF_LEN+1];

static char    cDebug='Y';

OBJPTR(DB);
OBJPTR(BO);

int parse_arg(int argc,char **argv);
int CollectFinData(hash_t *hData);
int CreateAlertEmailTpl(hash_t *hData);
int MapStringRetCode(int iRetCode, char *csRetCode);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	int     iDtlRet = PD_ERR;

	char    csLastPHDate[PD_DATE_LEN + 1];

	hash_t  *hData = NULL;
        hData = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hData,0);

DEBUGLOG(("batch_proc: Start!\n"));

	memset(csLastPHDate, 0, sizeof(csLastPHDate));

	iRet = parse_arg(argc,argv);
	if (iRet == SUCCESS) {
DEBUGLOG((" Last PHDate = [%s][%d]\n",cs_last_phdate,strlen(cs_last_phdate)));
	} else {
		printf("*usage: -d LAST_PHDATE\n");
		return FAILURE;
	}

	// Check Transaction Balance Log Is Completed Or Not
DEBUGLOG((" Calling DBTxnBalanceLog::IsCompleted\n"));

	DBObjPtr = CreateObj(DBPtr, "DBTxnBalanceLog", "IsCompleted");
	iDtlRet = (unsigned long)(DBObjPtr)(cs_last_phdate, PD_TYPE_PSP);

DEBUGLOG((" DBTxnBalanceLog::IsCompleted iRet = [%d]\n", iDtlRet));

	if (iDtlRet == PD_TRUE)
	{
		// Collect Fin Data
		// Get Last PHDate
		sprintf(csLastPHDate, cs_last_phdate);
		PutField_CString(hData, "LAST_PHDATE", csLastPHDate);

		iDtlRet = CollectFinData(hData);

		if (iDtlRet == PD_ERR)
			iRet = FAILURE;
	}
	else
	{
printf("%d\n", PD_RET_TXN_BAL_NOT_COMPLETED);

		PutField_Int(hData, "ret_code", PD_RET_TXN_BAL_NOT_COMPLETED);
	}

	// Create Alert Email Template
	if (iRet == SUCCESS)
	{
		// Alert Email Funct
		PutField_CString(hData, "funct", PD_EML_FUNCT_COL_FIN_DATA);
		iDtlRet = CreateAlertEmailTpl(hData);

		if (iDtlRet != PD_OK)
			iRet = FAILURE;
	}

	hash_destroy(hData);
        FREE_ME(hData);

DEBUGLOG(("batch_proc: normal exit!\n"));

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
        return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char	c;
	strcpy(cs_last_phdate,"");

	if (argc < 2) {
DEBUGLOG(("argc = [%d]\n",argc));
		return FAILURE;
	}

	while ((c = getopt(argc,argv,"d:")) != EOF) {
		switch (c) {
			case 'd':
                                strcpy(cs_last_phdate, optarg);
                                break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_last_phdate,""))
		return FAILURE;

        return SUCCESS;
}


int CollectFinData(hash_t *hData)
{
	int iRet = PD_ERR;

	char *csTmp = NULL;

	/* EXEC SQL WHENEVER SQLERROR GOTO collectfindata_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_date;

		
		short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("CollectFinData: Begin\n"));
	
	// date
        if (GetField_CString(hData,"LAST_PHDATE",&csTmp)) {
                hv_date.len = strlen(csTmp);
                memcpy(hv_date.arr, csTmp, hv_date.len);
DEBUGLOG((" date = [%.*s]\n", hv_date.len, hv_date.arr));
        }

        /* EXEC SQL EXECUTE
                BEGIN
                                :hv_return_value := func_hist_pid_bal_collect(to_date(:hv_date, 'YYYYMMDD'));
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := func_hist_pid_bal_collect \
( to_date ( :hv_date , 'YYYYMMDD' ) ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqphsv = sqlstm.sqhstv;
        sqlstm.sqphsl = sqlstm.sqhstl;
        sqlstm.sqphss = sqlstm.sqhsts;
        sqlstm.sqpind = sqlstm.sqindv;
        sqlstm.sqpins = sqlstm.sqinds;
        sqlstm.sqparm = sqlstm.sqharm;
        sqlstm.sqparc = sqlstm.sqharc;
        sqlstm.sqpadto = sqlstm.sqadto;
        sqlstm.sqptdso = sqlstm.sqtdso;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto collectfindata_error;
}



DEBUGLOG((" hv_return_value = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK)
        {
                iRet = PD_RET_RECORD_FOUND;
        }
       	else if (hv_return_value == SP_ERR)
        {
                iRet = PD_RET_OTHER_ERROR;
        }
        else if (hv_return_value == SP_NOT_FOUND)
	{
                iRet = PD_RET_INPUT_DATE_ERROR;
        }
	else if (hv_return_value == SP_OVERFLOW)
        {
                iRet = PD_RET_INIT_BATCH_NOT_EXIST;
        }
	else if (hv_return_value == SP_OTHER_ERR)
        {
                iRet = PD_RET_OTHER_ERROR;
        }

	if (iRet != PD_ERR) {
		PutField_Int(hData, "ret_code", iRet);
		printf("%d\n", iRet);
	}

DEBUGLOG(("CollectFinData: iRet = [%d]\n", iRet));
	return iRet;

collectfindata_error:
DEBUGLOG(("collectfindata_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CreateAlertEmailTpl(hash_t *hData)
{
	int iRet = PD_OK;

	int iDynCnt = 0;
	int iRetCode = 0;

	char *csFunct = NULL;
	char *csTmp = NULL;

	char csAlertDateTime[PD_TIMESTAMP_LEN + 1];
	char csStatus[PD_TMP_BUF_LEN + 1];
	char csTmpBuf[PD_TMP_BUF_LEN + 1];

	time_t  tNow = time(NULL);
        struct  tm tStruct = *localtime(&tNow);

	hash_t *hTemplate;
       	hTemplate = (hash_t*) malloc (sizeof(hash_t));
       	hash_init(hTemplate,0);

DEBUGLOG(("CreateAlertEmailTpl: Begin\n"));

	memset(csAlertDateTime, 0, sizeof(csAlertDateTime));
	memset(csStatus, 0, sizeof(csStatus));
	memset(csTmpBuf, 0, sizeof(csTmpBuf));

/* funct */
      	if (GetField_CString(hData,"funct",&csFunct)) {
DEBUGLOG((" funct = [%s]\n",csFunct));
             	PutField_CString(hTemplate, "funct", csFunct);
     	} else {
DEBUGLOG((" funct not exists\n"));
           	iRet = INT_ERR;
     	}

	// Alert Date Time
	if (iRet == PD_OK) {
		strftime(csAlertDateTime, sizeof(csAlertDateTime), PD_ALERT_DATETIME_FORMAT, &tStruct);

       	 	iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "stimestamp-0", "SEC", "stimestamp-0", 0);
        	iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", csAlertDateTime);
		//iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "ftimestamp-0", "STR", "stimestamp-0", write_tpl_timestamp());
	}

	// Get Desc
	if (iRet == PD_OK) {
		DBObjPtr = CreateObj(DBPtr, "DBEmailFunct", "Get");
                if ((unsigned long)(DBObjPtr)(hTemplate) == FOUND) {
DEBUGLOG((" DBEmailFunct:Get Found\n"));

/* desc */
                        if (GetField_CString(hTemplate,"desc",&csTmp)) {
DEBUGLOG((" desc = [%s]\n",csTmp));
                                iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sdescription-0", "SEC", "sdescription-0", 0);
                                iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fdescription-0", "STR", "sdescription-0", csTmp);
                        } else {
DEBUGLOG((" desc not exists\n"));
                                iRet = INT_ERR;
                        }

                } else {
DEBUGLOG((" DBEmailFunct:Get Not Found\n"));
                        iRet = INT_ERR;
                }
	}

	// Return Status and Information
	if (iRet == PD_OK) {

/* ret_code */
		if (GetField_Int(hData,"ret_code",&iRetCode)) {
DEBUGLOG((" ret_code = [%d]\n",iRetCode));
       	 	} else {
DEBUGLOG((" ret_code not exists\n"));
			iRet = INT_ERR;
		}

		// Status
		if (iRet == PD_OK) {
			if (iRetCode != PD_RET_RECORD_FOUND) {
                                sprintf(csStatus, PD_RET_STATUS_FAILURE);
                        } else {
                                sprintf(csStatus, PD_RET_STATUS_SUCCESS);
                        }
DEBUGLOG((" status = [%s]\n",csStatus));

			iDynCnt = set_tpl_dyn_cstring(hTemplate,iDynCnt,"STATUS","GLO","STR",csStatus);
		
			iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sstatus-0", "SEC", "sstatus-0", 0);
                        iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "fstatus-0", "STR", "sstatus-0", csStatus);
		}

		// Information
		if (iRet == PD_OK) {
			if (iRetCode != PD_RET_RECORD_FOUND) {

				iRet = MapStringRetCode(iRetCode, csTmpBuf);
				if (iRet == PD_OK) {
DEBUGLOG((" info = [%s]\n",csTmpBuf));

					iDynCnt = set_tpl_dyn_int(hTemplate, iDynCnt, "sinformation-0", "SEC", "sinformation-0", 0);
					iDynCnt = set_tpl_dyn_cstring(hTemplate, iDynCnt, "finformation-0", "STR", "sinformation-0", csTmpBuf);
				}
			}
		}
	}

	// Process Alert Email Template
	if (iRet == PD_OK) {
    		PutField_CString(hTemplate, "source", PD_EML_SOURCE_BATCH);
  		PutField_Char(hTemplate, "party_type", PD_TYPE_GLOBAL);
    		PutField_CString(hTemplate, "party_id", PD_EML_PARTY_ID_BATCH);	
   		PutField_Int(hTemplate, "total_dyn", iDynCnt);

		BOObjPtr = CreateObj(BOPtr, "BOAlertEmail", "ProcessTpl");
		iRet = (unsigned long)((*BOObjPtr)(hTemplate));
            	if (iRet == PD_OK) {
DEBUGLOG((" BOAlertEmail:ProcessTpl Success\n"));
		} else {
DEBUGLOG((" BOAlertEmail:ProcessTpl Failed\n"));
                   	PutField_Int(hTemplate, "internal_error", iRet);
            	}	
	}

	hash_destroy(hTemplate);
      	FREE_ME(hTemplate);

DEBUGLOG(("CreateAlertEmailTpl: iRet = [%d]\n", iRet));
	return iRet;
}


int MapStringRetCode(int iRetCode, char *csRetCode)
{
        int iRet = PD_OK;

    	if (iRetCode == PD_RET_INPUT_DATE_ERROR) {
              	sprintf(csRetCode, "Error: The latest batch end date larger than input date!");
      	} else if (iRetCode == PD_RET_INIT_BATCH_NOT_EXIST) {
              	sprintf(csRetCode, "Error: Initial batch record not exists!");
      	} else if (iRetCode == PD_RET_OTHER_ERROR) {
             	sprintf(csRetCode, "Error: Unexpected error!");
	} else if (iRetCode == PD_RET_TXN_BAL_NOT_COMPLETED) {
		sprintf(csRetCode, "Error: Running Balance Patching Incomplete!");
     	} else {
           	iRet = INT_ERR;
        }

	return iRet;
}

