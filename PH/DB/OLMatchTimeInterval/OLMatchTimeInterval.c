
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
    "OLMatchTimeInterval.pc"
};


static unsigned int sqlctx = 323122635;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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
" . OMT_ID AND to_date ( :b10:b25 || \
:b12:b27 , 'yyyymmddhh24miss' ) >= to_date ( :b10:b29 || OFFUS_T . OMT_START_\
TIME , 'yyyymmddhh24miss' ) AND to_date ( :b10:b31 || :b12:b33 , 'yyyymmddhh2\
4miss' ) < to_date ( :b10:b35 || OFFUS_T . OMT_END_TIME , 'yyyymmddhh24miss' \
) + 1 / 24 / 60 ORDER BY DECODE ( MAIN . OMTI_LEVEL , 'G' , 1 , 'M' , 2 , 'A'\
 , 3 ) DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,2,163,0,6,145,0,0,4,4,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,3,90,0,4,160,0,0,2,1,0,1,0,1,9,0,0,2,9,0,0,
59,0,0,4,163,0,6,165,0,0,4,4,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
90,0,0,1,1391,0,9,187,0,2049,18,18,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,
177,0,0,1,0,0,13,190,0,0,5,0,0,1,0,2,1,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
212,0,0,1,0,0,15,222,0,0,0,0,0,1,0,
227,0,0,1,0,0,15,231,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/12/09              David Wong
Add service code to holiday pkg                    2014/09/24              David Wong
Change check time logic                            2015/07/13              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMatchTimeInterval.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLMatchTimeInterval(char cdebug)
{
	cDebug = cdebug;
}

int GetMatchTimeInterval(const char* csIntBankCode,
				const char* csMerchantId,
				const char* csBankAcctNum,
				const char* csCountry,
				const char* csServiceCode,
				const char* csDate,
				const char* csTime,
				recordset_t* myRec)
{
	int iRet = PD_OK;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmatchtimeinterval_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char hv_return_value;

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_curr_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_curr_date;

		/* varchar hv_prev_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_prev_date;

		/* varchar hv_day_type[PD_DAY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_day_type;

		/* varchar hv_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_time;

		char v_level;
		int v_onus_bf_mins;
		int v_onus_af_mins;
		int v_offus_bf_mins;
		int v_offus_af_mins;

		short ind_int_bank_code = -1;
		short ind_merchant_id = -1;
		short ind_bank_acct_num = -1;
		short ind_country = -1;
		short ind_service_code = -1;
		short ind_curr_date = -1;
		short ind_prev_date = -1;
		short ind_day_type = -1;
		short ind_time = -1;
		short ind_level = -1;
		short ind_onus_bf_mins = -1;
		short ind_onus_af_mins = -1;
		short ind_offus_bf_mins = -1;
		short ind_offus_af_mins = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetMatchTimeInterval int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetMatchTimeInterval merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	strncpy((char*)hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("GetMatchTimeInterval bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	hv_country.len = strlen(csCountry);
	strncpy((char*)hv_country.arr, csCountry, hv_country.len);
	ind_country = 0;
DEBUGLOG(("GetMatchTimeInterval country = [%.*s]\n", hv_country.len, hv_country.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char*)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetMatchTimeInterval service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	hv_curr_date.len = strlen(csDate);
	strncpy((char*)hv_curr_date.arr, csDate, hv_curr_date.len);
	ind_curr_date = 0;
DEBUGLOG(("GetMatchTimeInterval date = [%.*s]\n", hv_curr_date.len, hv_curr_date.arr));

	hv_time.len = strlen(csTime);
	strncpy((char*)hv_time.arr, csTime, hv_time.len);
	ind_time = 0;
DEBUGLOG(("GetMatchTimeInterval time = [%.*s]\n", hv_time.len, hv_time.arr));

	/* EXEC SQL DECLARE c_cursor_getmatchtimeinterval CURSOR FOR
		SELECT	MAIN.OMTI_LEVEL,
			ONUS.ODTG_BF_MINS,
			ONUS.ODTG_AF_MINS,
			OFFUS.ODTG_BF_MINS,
			OFFUS.ODTG_AF_MINS
		FROM	OL_MATCH_TIME_INTERVAL MAIN,
			OL_MATCH_DAY_TIME_GROUP ONUS,
			OL_MATCH_DAY_TIME_GROUP OFFUS,
			OL_DEF_MATCH_TIME ONUS_T,
			OL_DEF_MATCH_TIME OFFUS_T
		WHERE	MAIN.OMTI_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
		AND	MAIN.OMTI_SERVICE_CODE = :hv_service_code:ind_service_code
		AND	( (MAIN.OMTI_LEVEL = 'G') OR
			  (MAIN.OMTI_LEVEL = 'M' AND MAIN.OMTI_PARTY_ID = :hv_merchant_id:ind_merchant_id) OR
			  (MAIN.OMTI_LEVEL = 'A' AND MAIN.OMTI_PARTY_ID = :hv_bank_acct_num:ind_bank_acct_num) )
		AND	MAIN.OMTI_ONUS_GRP_ID = ONUS.ODTG_GRP_ID
		AND	ONUS.ODTG_DAY_TYPE = :hv_day_type:ind_day_type
		AND	ONUS.ODTG_TIME_ID = ONUS_T.OMT_ID
		AND	to_date(:hv_curr_date:ind_curr_date || :hv_time:ind_time, 'yyyymmddhh24miss') >= to_date(:hv_curr_date:ind_curr_date || ONUS_T.OMT_START_TIME, 'yyyymmddhh24miss')
		AND	to_date(:hv_curr_date:ind_curr_date || :hv_time:ind_time, 'yyyymmddhh24miss') < to_date(:hv_curr_date:ind_curr_date || ONUS_T.OMT_END_TIME, 'yyyymmddhh24miss') + 1 / 24 / 60
		AND	MAIN.OMTI_OFFUS_GRP_ID = OFFUS.ODTG_GRP_ID
		AND	OFFUS.ODTG_DAY_TYPE = :hv_day_type:ind_day_type
		AND	OFFUS.ODTG_TIME_ID = OFFUS_T.OMT_ID
		AND	to_date(:hv_curr_date:ind_curr_date || :hv_time:ind_time, 'yyyymmddhh24miss') >= to_date(:hv_curr_date:ind_curr_date || OFFUS_T.OMT_START_TIME, 'yyyymmddhh24miss')
		AND	to_date(:hv_curr_date:ind_curr_date || :hv_time:ind_time, 'yyyymmddhh24miss') < to_date(:hv_curr_date:ind_curr_date || OFFUS_T.OMT_END_TIME, 'yyyymmddhh24miss') + 1 / 24 / 60
		ORDER BY DECODE(MAIN.OMTI_LEVEL, 'G', 1, 'M', 2, 'A', 3) DESC; */ 


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := holiday_pkg.is_holiday_by_country(
						:hv_curr_date:ind_curr_date,
						:hv_country:ind_country,
						:hv_service_code:ind_service_code);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := holiday_pkg . is_holiday_by_count\
ry ( :hv_curr_date:ind_curr_date , :hv_country:ind_country , :hv_service_code\
:ind_service_code ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_curr_date;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_service_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



	if (hv_return_value == 'Y') {
		// non biz
		strcpy((char*)hv_day_type.arr, "NONBIZ");
		hv_day_type.len = strlen((const char*)hv_day_type.arr);
		ind_day_type = 0;
	} else {
		/* EXEC SQL
			SELECT	to_char(to_date(:hv_curr_date:ind_curr_date, 'yyyymmdd') - 1, 'yyyymmdd')
			INTO	:hv_prev_date:ind_prev_date
			FROM	dual; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char ( to_date ( :b0:b1 , 'yyyymmdd' ) - 1 , 'yy\
yymmdd' ) INTO :b2:b3 FROM dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )36;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_curr_date;
  sqlstm.sqhstl[0] = (unsigned long )10;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_curr_date;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_prev_date;
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prev_date;
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
  if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := holiday_pkg.is_holiday_by_country(
							:hv_prev_date:ind_prev_date,
							:hv_country:ind_country,
							:hv_service_code:ind_service_code);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := holiday_pkg . is_holiday_by_coun\
try ( :hv_prev_date:ind_prev_date , :hv_country:ind_country , :hv_service_cod\
e:ind_service_code ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )59;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_return_value;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_prev_date;
  sqlstm.sqhstl[1] = (unsigned long )10;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prev_date;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



		if (hv_return_value == 'Y') {
			// fst biz af non biz
			strcpy((char*)hv_day_type.arr, "FSTBIZ");
			hv_day_type.len = strlen((const char*)hv_day_type.arr);
			ind_day_type = 0;
		} else {
			// biz
			strcpy((char*)hv_day_type.arr, "BIZ");
			hv_day_type.len = strlen((const char*)hv_day_type.arr);
			ind_day_type = 0;
		}
	}

	/* EXEC SQL OPEN c_cursor_getmatchtimeinterval; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT MAIN . OMTI_LEVEL , ONUS . ODTG_BF_MINS , ONUS . ODTG_AF_MINS , O\
FFUS . ODTG_BF_MINS , OFFUS . ODTG_AF_MINS FROM OL_MATCH_TIME_INTERVAL MAIN \
, OL_MATCH_DAY_TIME_GROUP ONUS , OL_MATCH_DAY_TIME_GROUP OFFUS , OL_DEF_MATC\
H_TIME ONUS_T , OL_DEF_MATCH_TIME OFFUS_T WHERE MAIN . OMTI_BANK_CODE = :b0:\
b1 AND MAIN . OMTI_SERVICE_CODE = :b2:b3 AND ( ( MAIN . OMTI_LEVEL = 'G' ) O\
R ( MAIN . OMTI_LEVEL = 'M' AND MAIN . OMTI_PARTY_ID = :b4:b5 ) OR ( MAIN . \
OMTI_LEVEL = 'A' AND MAIN . OMTI_PARTY_ID = :b6:b7 ) ) AND MAIN . OMTI_ONUS_\
GRP_ID = ONUS . ODTG_GRP_ID AND ONUS . ODTG_DAY_TYPE = :b8:b9 AND ONUS . ODT\
G_TIME_ID = ONUS_T . OMT_ID AND to_date ( :b10:b11 || :b12:b13 , 'yyyymmddhh\
24miss' ) >= to_date ( :b10:b15 || ONUS_T . OMT_START_TIME , 'yyyymmddhh24mi\
ss' ) AND to_date ( :b10:b17 || :b12:b19 , 'yyyymmddhh24miss' ) < to_date ( \
:b10:b21 || ONUS_T . OMT_END_TIME , 'yyyymmddhh24miss' ) + 1 / 24 / 60 AND M\
AIN . OMTI_OFFUS_GRP_ID = OFFUS . ODTG_GRP_ID AND OFFUS . ODTG_DAY_TYPE = :b\
8:b23 AND OFFUS . ODTG_TIME_ID = OFFUS_T");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_service_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_day_type;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_day_type;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[5] = (unsigned long )10;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_curr_date;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_time;
 sqlstm.sqhstl[6] = (unsigned long )8;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_time;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[7] = (unsigned long )10;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_curr_date;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[8] = (unsigned long )10;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_curr_date;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_time;
 sqlstm.sqhstl[9] = (unsigned long )8;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_time;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[10] = (unsigned long )10;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_curr_date;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_day_type;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_day_type;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[12] = (unsigned long )10;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_curr_date;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_time;
 sqlstm.sqhstl[13] = (unsigned long )8;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_time;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[14] = (unsigned long )10;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_curr_date;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[15] = (unsigned long )10;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_curr_date;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_time;
 sqlstm.sqhstl[16] = (unsigned long )8;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_time;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_curr_date;
 sqlstm.sqhstl[17] = (unsigned long )10;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_curr_date;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



	do {
		/* EXEC SQL FETCH c_cursor_getmatchtimeinterval
		INTO
			:v_level:ind_level,
			:v_onus_bf_mins:ind_onus_bf_mins,
			:v_onus_af_mins:ind_onus_af_mins,
			:v_offus_bf_mins:ind_offus_bf_mins,
			:v_offus_af_mins:ind_offus_af_mins; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )177;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_level;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_level;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_onus_bf_mins;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_onus_bf_mins;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_onus_af_mins;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_onus_af_mins;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_offus_bf_mins;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_offus_bf_mins;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_offus_af_mins;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_offus_af_mins;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		if (ind_level >= 0 && ind_onus_bf_mins >= 0 && ind_onus_af_mins >= 0 && ind_offus_bf_mins >= 0 && ind_offus_af_mins >= 0) {
			PutField_Char(myHash, "level", v_level);
DEBUGLOG(("GetMatchTimeInterval level = [%c]\n", v_level));
			PutField_Int(myHash, "onus_bf_mins", v_onus_bf_mins);
DEBUGLOG(("GetMatchTimeInterval onus_bf_mins = [%d]\n", v_onus_bf_mins));
			PutField_Int(myHash, "onus_af_mins", v_onus_af_mins);
DEBUGLOG(("GetMatchTimeInterval onus_af_mins = [%d]\n", v_onus_af_mins));
			PutField_Int(myHash, "offus_bf_mins", v_offus_bf_mins);
DEBUGLOG(("GetMatchTimeInterval offus_bf_mins = [%d]\n", v_offus_bf_mins));
			PutField_Int(myHash, "offus_af_mins", v_offus_af_mins);
DEBUGLOG(("GetMatchTimeInterval offus_af_mins = [%d]\n", v_offus_af_mins));
		}

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getmatchtimeinterval; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )212;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmatchtimeinterval_error;
}



DEBUGLOG(("GetMatchTimeInterval Exit iRet = [%d]\n", iRet));
	return iRet;

getmatchtimeinterval_error:
DEBUGLOG(("getmatchtimeinterval_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getmatchtimeinterval; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )227;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

