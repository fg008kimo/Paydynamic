
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "OLRuleStatementPeriod.pc"
};


static unsigned int sqlctx = 1321570507;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
5,0,0,1,222,0,4,71,0,0,6,2,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,9,0,0,1,9,0,
0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/04              Stan Poon
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLRuleStatementPeriod.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char	cDebug;

void OLRuleStatementPeriod(char	cdebug)
{
	cDebug = cdebug;
}


int GetStatementPeriod(const char* csIntBankCode,
			const char* csBankAcctNum,
			int* iBFHour,
			int* iAFHour,
			int* iHolidayBFHour,
			int* iHolidayAFHour)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getacctccy_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int	v_bf_hour;
		int	v_af_hour;
		int	v_holiday_bf_hour;
		int	v_holiday_af_hour;

		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_bf_hour = -1;
		short	ind_af_hour = -1;
		short	ind_holiday_bf_hour = -1;
		short	ind_holiday_af_hour = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr,csIntBankCode,hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetStatementPeriod int_bank_code = [%.*s]\n",hv_int_bank_code.len,hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("GetStatementPeriod bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));

	/* EXEC SQL	SELECT	ORSP_BF_HOURS,
				ORSP_AF_HOURS,
				ORSP_HOLIDAY_BF_HOURS,
				ORSP_HOLIDAY_AF_HOURS
			INTO	:v_bf_hour:ind_bf_hour,
				:v_af_hour:ind_af_hour,
				:v_holiday_bf_hour:ind_holiday_bf_hour,
				:v_holiday_af_hour:ind_holiday_af_hour
			FROM	OL_RULE_STATEMENT_PERIOD
			WHERE	ORSP_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	ORSP_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ORSP_BF_HOURS , ORSP_AF_HOURS , ORSP_HOLIDAY_BF_HOUR\
S , ORSP_HOLIDAY_AF_HOURS INTO :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM OL_RULE\
_STATEMENT_PERIOD WHERE ORSP_INT_BANK_CODE = :b8:b9 AND ORSP_BANK_ACCT_NUM = \
:b10:b11 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_bf_hour;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_bf_hour;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_af_hour;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_af_hour;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_holiday_bf_hour;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_holiday_bf_hour;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_holiday_af_hour;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_holiday_af_hour;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )12;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getacctccy_error;
}



	if (ind_bf_hour>=0) {
		*iBFHour = v_bf_hour;
DEBUGLOG(("GetStatementPeriod bf_hour = [%d]\n",iBFHour));
	} else {
		iRet = PD_ERR;
	}

	if (ind_af_hour>=0) {
		*iAFHour = v_af_hour;
DEBUGLOG(("GetStatementPeriod af_hour = [%d]\n",iAFHour));
	} else {
		iRet = PD_ERR;
	}

	if (ind_holiday_bf_hour>=0) {
		*iHolidayBFHour = v_holiday_bf_hour;
DEBUGLOG(("GetStatementPeriod holiday_bf_hour = [%d]\n",iBFHour));
	} else {
		iRet = PD_ERR;
	}

	if (ind_holiday_af_hour>=0) {
		*iHolidayAFHour = v_holiday_af_hour;
DEBUGLOG(("GetStatementPeriod holiday_af_hour = [%d]\n",iAFHour));
	} else {
		iRet = PD_ERR;
	}

DEBUGLOG(("GetStatementPeriod Exit iRet = [%d]\n",iRet));
	return iRet;

getacctccy_error:
DEBUGLOG(("getacctccy_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

