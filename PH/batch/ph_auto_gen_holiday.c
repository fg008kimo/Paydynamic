
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
           char  filnam[23];
};
static struct sqlcxp sqlfpn =
{
    22,
    "ph_auto_gen_holiday.pc"
};


static unsigned int sqlctx = 332104755;


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

 static char *sq0001 = 
"SELECT CS_COUNTRY , CS_SERVICE_CODE FROM COUNTRY_SERVICE_MAP            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,72,0,9,141,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,144,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
43,0,0,1,0,0,15,177,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,190,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,191,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/04              Dirk Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "batchcommon.h"
#include "utilitys.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_DETAIL_TAG   "dt"
#define PD_HOLIDAY_ACTION_ADD "A"

char	cDebug = 'Y';
int     iExtMonth;
char	csCurDate[PD_DATE_LEN+1];
char	csMonthStart[PD_DATE_LEN+1];
char	csMonthEnd[PD_DATE_LEN+1];
char    csTmpDate[PD_DATE_LEN+1];
char    csTmp[PD_TMP_BUF_LEN+1];

OBJPTR(Txn);

int	add_holiday(const char* csDate, const char* csDesc);
int	parse_arg(int argc,char **argv);

int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int     iRet = parse_arg(argc,argv);
	int     iTmp = 0;

	if (iRet != SUCCESS) {
		return PD_ERR;
	}

	csCurDate[PD_DATE_LEN]='\0';
	csMonthStart[PD_DATE_LEN]='\0';
	csMonthEnd[PD_DATE_LEN]='\0';

DEBUGLOG(("batch_proc: ext_month = [%d]\n",iExtMonth));

DEBUGLOG(("batch_proc: curdate = [%s]\n", csCurDate));

	if (iExtMonth < 0)
		return FAILURE;

	iRet = addmonth(csCurDate,iExtMonth,csMonthEnd);
	if (iRet == PD_OK)
	{
		memcpy(csMonthStart,csMonthEnd,PD_DATE_LEN);
		csMonthStart[6]='0';
		csMonthStart[7]='1';
DEBUGLOG(("batch_proc: monthstart = [%s]\n", csMonthStart));
DEBUGLOG(("batch_proc: monthend = [%s]\n", csMonthEnd));

		memcpy(csTmpDate,csMonthStart,PD_DATE_LEN);

		while (PD_TRUE) {
			iTmp = day_of_week((const unsigned char *)csTmpDate);
			if (iTmp == 6) {
DEBUGLOG(("batch_proc: [%s] Saturday!\n",csTmpDate));
				iRet = add_holiday(csTmpDate,"Normal Saturday day-off");
			}
			if (iTmp == 0) {
DEBUGLOG(("batch_proc: [%s] Sunday!\n",csTmpDate));
				iRet = add_holiday(csTmpDate,"Normal Sunday day-off");
			}

			if (iRet != PD_OK) {
ERRLOG("ph_auto_gen_holiday::add_holiday fail\n");
				break;
			}

			if (!memcmp(csTmpDate,csMonthEnd,PD_DATE_LEN))
				break;

			iRet = addday(csTmpDate,1,csTmpDate);
			if (iRet != PD_OK) {
ERRLOG("ph_auto_gen_holiday::addday fail\n");
				break;
			}
		}
	} else {
ERRLOG("ph_auto_gen_holiday::addmonth fail\n");
	}

	if (iRet == PD_OK)
		return SUCCESS;
	else
		return iRet;
}

int batch_terminate(int argc, char* argv[])
{
    return SUCCESS;
}

int add_holiday(const char* csDate, const char* csDesc)
{
	int     iRet = SUCCESS;

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext,0);

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


		short	ind_country = -1;
		short	ind_service_code = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getservicelist CURSOR FOR
		SELECT	CS_COUNTRY,
			CS_SERVICE_CODE
		FROM	COUNTRY_SERVICE_MAP; */ 

	/* EXEC SQL OPEN c_cursor_getservicelist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 0;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



	do {
		/* EXEC SQL FETCH c_cursor_getservicelist
		INTO
			:v_country:ind_country,
			:v_service_code:ind_service_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )20;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_country;
  sqlstm.sqhstl[0] = (unsigned long )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_country;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		//Put Field into hash to API
		PutField_CString(hContext, "action", PD_HOLIDAY_ACTION_ADD);
		PutField_Int(hContext, "total_cnt", 1);
		sprintf(csTmp,"%.*s",v_country.len,v_country.arr);
		PutField_CString(hContext, "countries", csTmp);
		sprintf(csTmp,"%.*s",v_service_code.len, v_service_code.arr);
		PutField_CString(hContext, "services", csTmp);
		PutField_CString(hContext, "desc", csDesc);
		PutField_CString(hContext, "add_user", PD_UPDATE_USER);
		sprintf(csTmp, "%s_date_1", PD_DETAIL_TAG);
		PutField_CString(hContext, csTmp, csDate);

		TxnObjPtr = CreateObj(TxnPtr,"TxnMgtByUsHDI","Authorize");
		if((unsigned long)((*TxnObjPtr)(hContext,hContext,hContext) != PD_OK)){
			iRet = FAILURE;
DEBUGLOG(("add_holiday::TxnMgtByUsHDI Failure!\n"));
ERRLOG("ph_auto_gen_holiday add_holiday::TxnMgtByUsHDI Failure\n");
			break;
		}
		else {
DEBUGLOG(("add_holiday::TxnMgtByUsHDI success for [%.*s][%.*s] on [%s]\n", v_country.len,v_country.arr,v_service_code.len, v_service_code.arr,csDate));
		}

        } while(PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getservicelist; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )43;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	FREE_ME(hContext);

	if (iRet == PD_OK)
		return SUCCESS;
	else
		return iRet;

sql_error:
DEBUGLOG(("ph_auto_gen_holiday error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_getservicelist; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )58;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )73;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


int parse_arg(int argc,char **argv)
{
	char    c;

	if (argc < 2) {
		return PD_ERR;
	}

	while ((c = getopt(argc,argv,"m: d:")) != EOF) {
		switch (c) {
			case 'm':
				iExtMonth = atoi(optarg);
				break;
			case 'd':
				strcpy(csCurDate, optarg);
				//memcpy(csCurDate,argv[1],strlen(argv[1]));
				break;
			default:
				return PD_ERR;
		}
	}

	return SUCCESS;
} 
    
