
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
    "OLRuleDepositMatching.pc"
};


static unsigned int sqlctx = 1319149395;


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
5,0,0,1,163,0,6,97,0,0,4,4,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,2,254,0,4,108,0,0,6,2,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,9,0,0,1,9,
0,0,
75,0,0,3,90,0,4,121,0,0,2,1,0,1,0,1,9,0,0,2,9,0,0,
98,0,0,4,163,0,6,126,0,0,4,4,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
129,0,0,5,266,0,4,137,0,0,6,2,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,9,0,0,1,
9,0,0,
168,0,0,6,238,0,4,151,0,0,6,2,0,1,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,1,9,0,0,1,
9,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/26              Stan Poon
Add biz, non-biz                                   2013/10/24              David Wong
Add first day after non-biz                        2013/11/05              David Wong
Add service code to holiday pkg                    2014/09/24              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLRuleDepositMatching.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;


void OLRuleDepositMatching(char cdebug)
{
	cDebug = cdebug;
}

int GetRuleDepositMatchingByDate(const char* csMerchantId,
				const char* csIntBankCode,
				const char* csCountry,
				const char* csServiceCode,
				const char* csDate,
				hash_t* hRec)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getruledepositmatchingbydate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		char hv_return_value;

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_curr_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_curr_date;

		/* varchar hv_prev_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_prev_date;

		int v_onus_bf_mins;
		int v_onus_af_mins;
		int v_offus_bf_mins;
		int v_offus_af_mins;

		short ind_merchant_id = -1;
		short ind_int_bank_code = -1;
		short ind_country = -1;
		short ind_service_code = -1;
		short ind_curr_date = -1;
		short ind_prev_date = -1;
		short ind_onus_bf_mins = -1;
		short ind_onus_af_mins = -1;
		short ind_offus_bf_mins = -1;
		short ind_offus_af_mins = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetRuleDepositMatchingByDate merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetRuleDepositMatchingByDate int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_country.len = strlen(csCountry);
	strncpy((char*)hv_country.arr, csCountry, hv_country.len);
	ind_country = 0;
DEBUGLOG(("GetRuleDepositMatchingByDate country = [%.*s]\n", hv_country.len, hv_country.arr));

	hv_service_code.len = strlen(csServiceCode);
	strncpy((char*)hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetRuleDepositMatchingByDate service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	hv_curr_date.len = strlen(csDate);
	strncpy((char*)hv_curr_date.arr, csDate, hv_curr_date.len);
	ind_curr_date = 0;
DEBUGLOG(("GetRuleDepositMatchingByDate date = [%.*s]\n", hv_curr_date.len, hv_curr_date.arr));

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
 if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
}



	if (hv_return_value == 'Y') {
		// non_biz
		/* EXEC SQL
			SELECT	ORDM_NON_BIZ_ONUS_BF_MINS,
				ORDM_NON_BIZ_ONUS_AF_MINS,
				ORDM_NON_BIZ_OFFUS_BF_MINS,
				ORDM_NON_BIZ_OFFUS_AF_MINS
			INTO	:v_onus_bf_mins:ind_onus_bf_mins,
				:v_onus_af_mins:ind_onus_af_mins,
				:v_offus_bf_mins:ind_offus_bf_mins,
				:v_offus_af_mins:ind_offus_af_mins
			FROM	OL_RULE_DEPOSIT_MATCHING
			WHERE	ORDM_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
			AND	ORDM_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select ORDM_NON_BIZ_ONUS_BF_MINS , ORDM_NON_BIZ_ONUS_AF_MI\
NS , ORDM_NON_BIZ_OFFUS_BF_MINS , ORDM_NON_BIZ_OFFUS_AF_MINS INTO :b0:b1 , :b\
2:b3 , :b4:b5 , :b6:b7 FROM OL_RULE_DEPOSIT_MATCHING WHERE ORDM_MERCHANT_ID =\
 :b8:b9 AND ORDM_INT_BANK_CODE = :b10:b11 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )36;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_onus_bf_mins;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_onus_bf_mins;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_onus_af_mins;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_onus_af_mins;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_offus_bf_mins;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_offus_bf_mins;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_offus_af_mins;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_offus_af_mins;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
  sqlstm.sqhstl[5] = (unsigned long )12;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_int_bank_code;
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
  if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
}


	} else {
		/* EXEC SQL
			SELECT	to_char(to_date(:hv_curr_date:ind_curr_date, 'yyyymmdd') - 1, 'yyyymmdd')
			INTO	:hv_prev_date:ind_prev_date
			FROM	dual; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select to_char ( to_date ( :b0:b1 , 'yyyymmdd' ) - 1 , 'yy\
yymmdd' ) INTO :b2:b3 FROM dual ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )75;
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
  if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
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
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := holiday_pkg . is_holiday_by_coun\
try ( :hv_prev_date:ind_prev_date , :hv_country:ind_country , :hv_service_cod\
e:ind_service_code ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )98;
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
  if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
}



		if (hv_return_value == 'Y') {
			// af_non_biz
			/* EXEC SQL
				SELECT	ORDM_AF_NON_BIZ_ONUS_BF_MINS,
					ORDM_AF_NON_BIZ_ONUS_AF_MINS,
					ORDM_AF_NON_BIZ_OFFUS_BF_MINS,
					ORDM_AF_NON_BIZ_OFFUS_AF_MINS
				INTO	:v_onus_bf_mins:ind_onus_bf_mins,
					:v_onus_af_mins:ind_onus_af_mins,
					:v_offus_bf_mins:ind_offus_bf_mins,
					:v_offus_af_mins:ind_offus_af_mins
				FROM	OL_RULE_DEPOSIT_MATCHING
				WHERE	ORDM_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
				AND	ORDM_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select ORDM_AF_NON_BIZ_ONUS_BF_MINS , ORDM_AF_NON_BIZ_ONU\
S_AF_MINS , ORDM_AF_NON_BIZ_OFFUS_BF_MINS , ORDM_AF_NON_BIZ_OFFUS_AF_MINS INT\
O :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 FROM OL_RULE_DEPOSIT_MATCHING WHERE ORDM_\
MERCHANT_ID = :b8:b9 AND ORDM_INT_BANK_CODE = :b10:b11 ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )129;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_onus_bf_mins;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_onus_bf_mins;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_onus_af_mins;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_onus_af_mins;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_offus_bf_mins;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_offus_bf_mins;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_offus_af_mins;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_offus_af_mins;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[4] = (unsigned long )17;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
   sqlstm.sqhstl[5] = (unsigned long )12;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_int_bank_code;
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
   if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
}


		} else {
			// biz
			/* EXEC SQL
				SELECT	ORDM_BIZ_ONUS_BF_MINS,
					ORDM_BIZ_ONUS_AF_MINS,
					ORDM_BIZ_OFFUS_BF_MINS,
					ORDM_BIZ_OFFUS_AF_MINS
				INTO	:v_onus_bf_mins:ind_onus_bf_mins,
					:v_onus_af_mins:ind_onus_af_mins,
					:v_offus_bf_mins:ind_offus_bf_mins,
					:v_offus_af_mins:ind_offus_af_mins
				FROM	OL_RULE_DEPOSIT_MATCHING
				WHERE	ORDM_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
				AND	ORDM_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "select ORDM_BIZ_ONUS_BF_MINS , ORDM_BIZ_ONUS_AF_MINS , OR\
DM_BIZ_OFFUS_BF_MINS , ORDM_BIZ_OFFUS_AF_MINS INTO :b0:b1 , :b2:b3 , :b4:b5 ,\
 :b6:b7 FROM OL_RULE_DEPOSIT_MATCHING WHERE ORDM_MERCHANT_ID = :b8:b9 AND ORD\
M_INT_BANK_CODE = :b10:b11 ";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )168;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_onus_bf_mins;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_onus_bf_mins;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_onus_af_mins;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_onus_af_mins;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_offus_bf_mins;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_offus_bf_mins;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_offus_af_mins;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_offus_af_mins;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[4] = (unsigned long )17;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_int_bank_code;
   sqlstm.sqhstl[5] = (unsigned long )12;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_int_bank_code;
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
   if (sqlca.sqlcode < 0) goto getruledepositmatchingbydate_error;
}


		}
	}

	if (ind_onus_bf_mins >= 0 && ind_onus_af_mins >= 0 && ind_offus_bf_mins >= 0 && ind_offus_af_mins >= 0) {
		PutField_Int(hRec, "onus_bf_mins", v_onus_bf_mins);
DEBUGLOG(("GetRuleDepositMatchingByDate onus_bf_mins = [%d]\n", v_onus_bf_mins));
		PutField_Int(hRec, "onus_af_mins", v_onus_af_mins);
DEBUGLOG(("GetRuleDepositMatchingByDate onus_af_mins = [%d]\n", v_onus_af_mins));
		PutField_Int(hRec, "offus_bf_mins", v_offus_bf_mins);
DEBUGLOG(("GetRuleDepositMatchingByDate offus_bf_mins = [%d]\n", v_offus_bf_mins));
		PutField_Int(hRec, "offus_af_mins", v_offus_af_mins);
DEBUGLOG(("GetRuleDepositMatchingByDate offus_af_mins = [%d]\n", v_offus_af_mins));
	} else {
DEBUGLOG(("GetRuleDepositMatchingByDate not found\n"));
ERRLOG("OLRuleDepositMatching:: GetRuleDepositMatchingByDate not found for [%s][%s][%s][%s]\n", csMerchantId, csIntBankCode, csCountry, csDate);
		iRet = PD_ERR;
	}

DEBUGLOG(("GetRuleDepositMatchingByDate Exit iRet = [%d]\n", iRet));
	return iRet;

getruledepositmatchingbydate_error:
DEBUGLOG(("getruledepositmatchingbydate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLRuleDepositMatching getruledepositmatchingbydate_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


/*
int GetRuleDepositMatching(const char* csMerchantId,
			const char* csIntBankCode,
			hash_t* hRec)
{
	int iRet = PD_OK;

	EXEC SQL WHENEVER SQLERROR GOTO getruledepositmatching_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_merchant_id[PD_MERCHANT_ID_LEN];
		varchar hv_int_bank_code[PD_BANK_CODE_LEN];
		int v_biz_onus_bf_mins;
		int v_biz_onus_af_mins;
		int v_biz_offus_bf_mins;
		int v_biz_offus_af_mins;
		int v_non_biz_onus_bf_mins;
		int v_non_biz_onus_af_mins;
		int v_non_biz_offus_bf_mins;
		int v_non_biz_offus_af_mins;
		int v_af_non_biz_onus_bf_mins;
		int v_af_non_biz_onus_af_mins;
		int v_af_non_biz_offus_bf_mins;
		int v_af_non_biz_offus_af_mins;

		short ind_merchant_id = -1;
		short ind_int_bank_code = -1;
		short ind_biz_onus_bf_mins = -1;
		short ind_biz_onus_af_mins = -1;
		short ind_biz_offus_bf_mins = -1;
		short ind_biz_offus_af_mins = -1;
		short ind_non_biz_onus_bf_mins = -1;
		short ind_non_biz_onus_af_mins = -1;
		short ind_non_biz_offus_bf_mins = -1;
		short ind_non_biz_offus_af_mins = -1;
		short ind_af_non_biz_onus_bf_mins = -1;
		short ind_af_non_biz_onus_af_mins = -1;
		short ind_af_non_biz_offus_bf_mins = -1;
		short ind_af_non_biz_offus_af_mins = -1;
	EXEC SQL END DECLARE SECTION;

	hv_merchant_id.len = strlen(csMerchantId);
	strncpy((char*)hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetRuleDepositMatching merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetRuleDepositMatching int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	EXEC SQL
		SELECT	ORDM_BIZ_ONUS_BF_MINS,
			ORDM_BIZ_ONUS_AF_MINS,
			ORDM_BIZ_OFFUS_BF_MINS,
			ORDM_BIZ_OFFUS_AF_MINS,
			ORDM_NON_BIZ_ONUS_BF_MINS,
			ORDM_NON_BIZ_ONUS_AF_MINS,
			ORDM_NON_BIZ_OFFUS_BF_MINS,
			ORDM_NON_BIZ_OFFUS_AF_MINS,
			ORDM_AF_NON_BIZ_ONUS_BF_MINS,
			ORDM_AF_NON_BIZ_ONUS_AF_MINS,
			ORDM_AF_NON_BIZ_OFFUS_BF_MINS,
			ORDM_AF_NON_BIZ_OFFUS_AF_MINS
		INTO	:v_biz_onus_bf_mins:ind_biz_onus_bf_mins,
			:v_biz_onus_af_mins:ind_biz_onus_af_mins,
			:v_biz_offus_bf_mins:ind_biz_offus_bf_mins,
			:v_biz_offus_af_mins:ind_biz_offus_af_mins,
			:v_non_biz_onus_bf_mins:ind_non_biz_onus_bf_mins,
			:v_non_biz_onus_af_mins:ind_non_biz_onus_af_mins,
			:v_non_biz_offus_bf_mins:ind_non_biz_offus_bf_mins,
			:v_non_biz_offus_af_mins:ind_non_biz_offus_af_mins,
			:v_af_non_biz_onus_bf_mins:ind_af_non_biz_onus_bf_mins,
			:v_af_non_biz_onus_af_mins:ind_af_non_biz_onus_af_mins,
			:v_af_non_biz_offus_bf_mins:ind_af_non_biz_offus_bf_mins,
			:v_af_non_biz_offus_af_mins:ind_af_non_biz_offus_af_mins
		FROM	OL_RULE_DEPOSIT_MATCHING
		WHERE	ORDM_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
		AND	ORDM_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code;

	if (ind_biz_onus_bf_mins >= 0) {
		PutField_Int(hRec, "biz_onus_bf_mins", v_biz_onus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching biz_onus_bf_mins = [%d]\n", v_biz_onus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_biz_onus_af_mins >= 0) {
		PutField_Int(hRec, "biz_onus_af_mins", v_biz_onus_af_mins);
DEBUGLOG(("GetRuleDepositMatching biz_onus_af_mins = [%d]\n", v_biz_onus_af_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_biz_offus_bf_mins >= 0) {
		PutField_Int(hRec, "biz_offus_bf_mins", v_biz_offus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching biz_offus_bf_mins = [%d]\n", v_biz_offus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_biz_offus_af_mins >= 0) {
		PutField_Int(hRec, "biz_offus_af_mins", v_biz_offus_af_mins);
DEBUGLOG(("GetRuleDepositMatching biz_offus_af_mins = [%d]\n", v_biz_offus_af_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_non_biz_onus_bf_mins >= 0) {
		PutField_Int(hRec, "non_biz_onus_bf_mins", v_non_biz_onus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching non_biz_onus_bf_mins = [%d]\n", v_non_biz_onus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_non_biz_onus_af_mins >= 0) {
		PutField_Int(hRec, "non_biz_onus_af_mins", v_non_biz_onus_af_mins);
DEBUGLOG(("GetRuleDepositMatching non_biz_onus_af_mins = [%d]\n", v_non_biz_onus_af_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_non_biz_offus_bf_mins >= 0) {
		PutField_Int(hRec, "non_biz_offus_bf_mins", v_non_biz_offus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching non_biz_offus_bf_mins = [%d]\n", v_non_biz_offus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_non_biz_offus_af_mins >= 0) {
		PutField_Int(hRec, "non_biz_offus_af_mins", v_non_biz_offus_af_mins);
DEBUGLOG(("GetRuleDepositMatching non_biz_offus_af_mins = [%d]\n", v_non_biz_offus_af_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_af_non_biz_onus_bf_mins >= 0) {
		PutField_Int(hRec, "af_non_biz_onus_bf_mins", v_af_non_biz_onus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching af_non_biz_onus_bf_mins = [%d]\n", v_af_non_biz_onus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_af_non_biz_onus_af_mins >= 0) {
		PutField_Int(hRec, "af_non_biz_onus_af_mins", v_af_non_biz_onus_af_mins);
DEBUGLOG(("GetRuleDepositMatching af_non_biz_onus_af_mins = [%d]\n", v_af_non_biz_onus_af_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_af_non_biz_offus_bf_mins >= 0) {
		PutField_Int(hRec, "af_non_biz_offus_bf_mins", v_af_non_biz_offus_bf_mins);
DEBUGLOG(("GetRuleDepositMatching af_non_biz_offus_bf_mins = [%d]\n", v_af_non_biz_offus_bf_mins));
	} else {
		iRet = PD_ERR;
	}

	if (ind_af_non_biz_offus_af_mins >= 0) {
		PutField_Int(hRec, "af_non_biz_offus_af_mins", v_af_non_biz_offus_af_mins);
DEBUGLOG(("GetRuleDepositMatching af_non_biz_offus_af_mins = [%d]\n", v_af_non_biz_offus_af_mins));
	} else {
		iRet = PD_ERR;
	}

DEBUGLOG(("GetRuleDepositMatching Exit iRet = [%d]\n", iRet));
	return iRet;

getruledepositmatching_error:
DEBUGLOG(("getruledepositmatching_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/

