
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
    "AcctLedgerDailyReport.pc"
};


static unsigned int sqlctx = 1131107771;


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
   unsigned char  *sqhstv[11];
   unsigned long  sqhstl[11];
            int   sqhsts[11];
            short *sqindv[11];
            int   sqinds[11];
   unsigned long  sqharm[11];
   unsigned long  *sqharc[11];
   unsigned short  sqadto[11];
   unsigned short  sqtdso[11];
} sqlstm = {12,11};

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
5,0,0,1,358,0,6,146,0,0,11,11,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
64,0,0,2,243,0,4,267,0,0,7,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,
0,0,1,9,0,0,
107,0,0,3,0,0,17,400,0,0,1,1,0,1,0,1,9,0,0,
126,0,0,3,0,0,21,401,0,0,0,0,0,1,0,
141,0,0,3,0,0,17,446,0,0,1,1,0,1,0,1,9,0,0,
160,0,0,3,0,0,21,447,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date   Change By
-------------------------------------------------  ------------  --------------
Init Version                                       2018/08/10    Elvis Wong
Add ALDR_LEDGER_TYPE, ALDR_DISABLED                2018/08/24    Philip Yu
Remove GetStatus                                   2018/08/28    Philip Yu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"
#include "AcctLedgerDailyReport.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;


void AcctLedgerDailyReport(char    cdebug)
{
	cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char *csTmp;
	char cTmp;
	int  iTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		char    hv_ledger_type;
		int     hv_disabled;
		/* varchar hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		/* varchar hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		char    hv_status;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		
		short   ind_merchant_id = -1;
		short   ind_ccy = -1;
		short   ind_country = -1;
		short   ind_service_code = -1;
		short   ind_ledger_type = -1;
		short   ind_disabled = -1;
		short   ind_report_date = -1;
		short   ind_filename = -1;
		short   ind_status = -1;
		short   ind_create_user = -1;
		
		short   hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add:Begin\n"));

	if(GetField_CString(hRls,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hRls,"ccy",&csTmp))
	{
	 	hv_ccy.len = strlen(csTmp);
	 	strncpy((char *)hv_ccy.arr, csTmp, hv_ccy.len);
	 	ind_ccy = 0;
DEBUGLOG(("Add:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
	}

	if(GetField_CString(hRls,"country",&csTmp))
	{
		hv_country.len = strlen(csTmp);
		strncpy((char *)hv_country.arr, csTmp, hv_country.len);
		ind_country = 0;
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len,hv_country.arr));
	}

	if(GetField_CString(hRls,"service_code",&csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}

	if(GetField_Char(hRls, "ledger_type", &cTmp)) {
		hv_ledger_type = cTmp;
		ind_ledger_type = 0;
DEBUGLOG(("Add:ledger_type = [%c]\n",hv_ledger_type));
	}

	if(GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
/*DEBUGLOG(("UpdateStatus:disabled = [%d]\n",hv_disabled));*/
	}

	if(GetField_CString(hRls,"report_date",&csTmp))
	{
		hv_report_date.len = strlen(csTmp);
		strncpy((char *)hv_report_date.arr, csTmp, hv_report_date.len);
		ind_report_date = 0;
DEBUGLOG(("Add:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
	}

	if(GetField_CString(hRls,"filename",&csTmp))
	{
		hv_filename.len = strlen(csTmp);
		strncpy((char *)hv_filename.arr, csTmp, hv_filename.len);
		ind_filename = 0;
/*DEBUGLOG(("Add:filename = [%.*s]\n",hv_filename.len,hv_filename.arr));*/
	}

	if(GetField_Char(hRls, "status", &cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
/*DEBUGLOG(("Add:status = [%c]\n",hv_status));*/
	}

	if(GetField_CString(hRls,"user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
/*DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));*/
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_acct_ldgr_daily_rpt_ins(
			    :hv_merchant_id:ind_merchant_id,
			    :hv_ccy:ind_ccy,
			    :hv_country:ind_country,
			    :hv_service_code:ind_service_code,
			    :hv_ledger_type:ind_ledger_type,
			    :hv_disabled:ind_disabled,
			    :hv_report_date:ind_report_date,
			    :hv_filename:ind_filename,
			    :hv_status:ind_status,
			    :hv_create_user:ind_create_user);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_acct_ldgr_daily_rpt_ins ( :hv_\
merchant_id:ind_merchant_id , :hv_ccy:ind_ccy , :hv_country:ind_country , :hv\
_service_code:ind_service_code , :hv_ledger_type:ind_ledger_type , :hv_disabl\
ed:ind_disabled , :hv_report_date:ind_report_date , :hv_filename:ind_filename\
 , :hv_status:ind_status , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ledger_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ledger_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_disabled;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[7] = (unsigned long )10;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_report_date;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[8] = (unsigned long )102;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_filename;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[9] = (unsigned long )1;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_status;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[10] = (unsigned long )22;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_create_user;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}
	
	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("AcctLedgerDailyReport_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}
	
	if (hv_return_value == SP_ERR)  {
ERRLOG("AcctLedgerDailyReport_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AcctLedgerDailyReport_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort(); 
	return PD_ERR;
}

int ChkExist(const hash_t *hRls)
{
	char *csTmp;
	char cTmp;
	int  iRecCnt;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO chkexist_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		char    hv_ledger_type;
		/* varchar hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		
		short   ind_merchant_id = -1;
		short   ind_ccy = -1;
		short   ind_country = -1;
		short   ind_service_code = -1;
		short   ind_ledger_type = -1;
		short   ind_report_date = -1;
		
		int     v_rec_cnt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("ChkExist:Begin\n"));

	if(GetField_CString(hRls,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("ChkExist:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hRls,"ccy",&csTmp))
	{
	 	hv_ccy.len = strlen(csTmp);
	 	strncpy((char *)hv_ccy.arr, csTmp, hv_ccy.len);
	 	ind_ccy = 0;
DEBUGLOG(("ChkExist:ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
	}

	if(GetField_CString(hRls,"country",&csTmp))
	{
		hv_country.len = strlen(csTmp);
		strncpy((char *)hv_country.arr, csTmp, hv_country.len);
		ind_country = 0;
DEBUGLOG(("ChkExist:country = [%.*s]\n",hv_country.len,hv_country.arr));
	}

	if(GetField_CString(hRls,"service_code",&csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("ChkExist:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
	}

	if(GetField_Char(hRls, "ledger_type", &cTmp)) {
		hv_ledger_type = cTmp;
		ind_ledger_type = 0;
DEBUGLOG(("ChkExist:ledger_type = [%c]\n",hv_ledger_type));
	}

	if(GetField_CString(hRls,"report_date",&csTmp))
	{
		hv_report_date.len = strlen(csTmp);
		strncpy((char *)hv_report_date.arr, csTmp, hv_report_date.len);
		ind_report_date = 0;
DEBUGLOG(("ChkExist:report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));
	}

	/* EXEC SQL 
		SELECT COUNT(1) INTO :v_rec_cnt
		FROM ACCT_LEDGER_DAILY_REPORT
		WHERE ALDR_MERCHANT_ID  = :hv_merchant_id:ind_merchant_id 
		AND   ALDR_CURRENCY_ID  = :hv_ccy:ind_ccy
		AND   ALDR_COUNTRY_ID   = :hv_country:ind_country
		AND   ALDR_SERVICE_CODE = :hv_service_code:ind_service_code
		AND   ALDR_LEDGER_TYPE  = :hv_ledger_type:ind_ledger_type
		AND   ALDR_REPORT_DATE  = :hv_report_date:ind_report_date
		; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( 1 ) INTO :b0 FROM ACCT_LEDGER_DAILY_REPORT W\
HERE ALDR_MERCHANT_ID = :b1:b2 AND ALDR_CURRENCY_ID = :b3:b4 AND ALDR_COUNTRY\
_ID = :b5:b6 AND ALDR_SERVICE_CODE = :b7:b8 AND ALDR_LEDGER_TYPE = :b9:b10 AN\
D ALDR_REPORT_DATE = :b11:b12 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )64;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_rec_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ledger_type;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ledger_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_report_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto chkexist_error;
}



	iRecCnt = v_rec_cnt;
DEBUGLOG(("ChkExist:rec_cnt = [%d]\n", v_rec_cnt));

DEBUGLOG(("ChkExist:Normal Exit\n"));
		return iRecCnt;
	
chkexist_error:
DEBUGLOG(("chkexist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("AcctLedgerDailyReport_ChkExist: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort(); 
	return PD_ERR;
}

int UpdateStatus(const hash_t *hRls)
{
	char *csMerchantId;
	char *csCcy;
	char *csCountry;
	char *csServiceCode;
	char cLedgerType;
	char *csReportDate;
	char *csFilename;
	char *csTmp;
	char cTmp;
	char csTmpBuffer[80];
	int  iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateStatus:Begin\n"));
        
	strcpy((char*)hv_dynstmt.arr,"UPDATE ACCT_LEDGER_DAILY_REPORT SET ALDR_UPDATE_TIMESTAMP  = SYSDATE");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls,"merchant_id",&csMerchantId);
DEBUGLOG(("UpdateStatus:merchant_id = [%s]\n",csMerchantId));

	GetField_CString(hRls,"ccy",&csCcy);
DEBUGLOG(("UpdateStatus:ccy = [%s]\n",csCcy));

	GetField_CString(hRls,"country",&csCountry);
DEBUGLOG(("UpdateStatus:country = [%s]\n",csCountry));

	GetField_CString(hRls,"service_code",&csServiceCode);
DEBUGLOG(("UpdateStatus:service_code = [%s]\n",csServiceCode));

	GetField_Char(hRls,"ledger_type",&cLedgerType);
DEBUGLOG(("UpdateStatus:ledger_type = [%c]\n",cLedgerType));

/* disabled */
	if (GetField_Int(hRls,"disabled",&iTmp)) {
/*DEBUGLOG(("UpdateStatus:disabled = [%d]\n",iTmp)); */
		sprintf(csTmpBuffer, ",ALDR_DISABLED = %d", iTmp);

		strcat((char*)hv_dynstmt.arr, csTmpBuffer);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	GetField_CString(hRls,"report_date",&csReportDate);
DEBUGLOG(("UpdateStatus:report_date = [%s]\n",csReportDate));

/* filename */
	if (GetField_CString(hRls,"filename",&csTmp)){
/*DEBUGLOG(("UpdateStatus:filename = [%s]\n",csTmp));*/
		strcat((char*)hv_dynstmt.arr, ",ALDR_FILENAME = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* status */
	if (GetField_Char(hRls,"status",&cTmp)) {
/*DEBUGLOG(("UpdateStatus:status = [%c]\n",cTmp));*/
		sprintf(csTmpBuffer, "%c", cTmp);

		strcat((char*)hv_dynstmt.arr, ",ALDR_STATUS = '");
		strcat((char*)hv_dynstmt.arr, csTmpBuffer);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update_user */
	if (GetField_CString(hRls,"user",&csTmp)){
/*DEBUGLOG(("UpdateStatus:update_user = [%s]\n",csTmp));*/
		strcat((char*)hv_dynstmt.arr, ",ALDR_UPDATE_USER= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE ALDR_MERCHANT_ID = '");
	strcat((char *)hv_dynstmt.arr, csMerchantId);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND ALDR_CURRENCY_ID = '");
	strcat((char *)hv_dynstmt.arr, csCcy);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND ALDR_COUNTRY_ID = '");
	strcat((char *)hv_dynstmt.arr, csCountry);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND ALDR_SERVICE_CODE = '");
	strcat((char *)hv_dynstmt.arr, csServiceCode);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND ALDR_LEDGER_TYPE = '");
	sprintf(csTmpBuffer, "%c", cLedgerType);
	strcat((char *)hv_dynstmt.arr, csTmpBuffer);
	strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND ALDR_REPORT_DATE = '");
	strcat((char *)hv_dynstmt.arr, csReportDate);
	strcat((char *)hv_dynstmt.arr, "'");

	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
/*DEBUGLOG(("UpdateStatus:hv_dynstmt = [%s]\n",hv_dynstmt.arr));*/

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )107;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )126;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto updatestatus_error;
}



DEBUGLOG(("UpdateStatus:Normal Exit\n"));
	return PD_OK;

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("AcctLedgerDailyReport_UpdateStatus: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateStatus: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort(); 
	return PD_INTERNAL_ERR;
}

int HkRecord(hash_t *hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO hkrecord_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("HkRecord:Begin\n"));
        
	strcpy((char*)hv_dynstmt.arr,"UPDATE ACCT_LEDGER_DAILY_REPORT SET ALDR_DISABLED = 1 WHERE ALDR_REPORT_DATE <= '");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* no_day */
	if (GetField_CString(hRls,"hk_day",&csTmp)){
/*DEBUGLOG(("HkRecord:no_day = [%s]\n",csTmp));*/
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char *)hv_dynstmt.arr, "'");

		strcat((char *)hv_dynstmt.arr, " AND ALDR_DISABLED = 0");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
DEBUGLOG(("HkRecord:hv_dynstmt = [%s]\n",hv_dynstmt.arr));


	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )141;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )1026;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto hkrecord_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 11;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )160;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto hkrecord_error;
}



	FREE_ME(csTmp);

DEBUGLOG(("HkRecord:Normal Exit\n"));
	return PD_OK;

hkrecord_error:
DEBUGLOG(("hkrecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("AcctLedgerDailyReport_HkRecord: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("HkRecord: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort(); 
	return PD_INTERNAL_ERR;
}
