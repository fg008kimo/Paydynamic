
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "OLStatement.pc"
};


static unsigned int sqlctx = 1287547;


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
   unsigned char  *sqhstv[26];
   unsigned long  sqhstl[26];
            int   sqhsts[26];
            short *sqindv[26];
            int   sqinds[26];
   unsigned long  sqharm[26];
   unsigned long  *sqharc[26];
   unsigned short  sqadto[26];
   unsigned short  sqtdso[26];
} sqlstm = {12,26};

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
"SELECT OLSD_TXN_ID , OLSD_BALANCE , OLSD_STATEMENT_DATE , OLSD_STATEMENT_TI\
ME , OLSD_TXN_AMOUNT , OLSD_AMT_TYPE FROM ( SELECT * FROM OL_STATEMENT_DETAIL\
 WHERE OLSD_INT_BANK_CODE = :b0:b1 AND OLSD_BANK_ACCT_NUM = :b2:b3 AND OLSD_S\
TATEMENT_REF IS NOT NULL ORDER BY OLSD_STATEMENT_REF DESC ) WHERE rownum <= 2\
            ";

 static char *sq0013 = 
"SELECT olsd_int_bank_code , olsd_bank_acct_num , olsd_statement_date , olsd\
_statement_time , to_char ( olsd_statement_timestamp , 'yyyymmddhh24miss' ) ,\
 olsd_tfr_bank_name , olsd_tfr_bank_acct_num , olsd_tfr_type , olsd_tfr_chann\
el , olsd_tfr_text , olsd_tfr_customer_text , olsd_sender_name , olsd_txn_ref\
_num , olsd_amt_type , to_char ( olsd_txn_amount ) , olsd_txn_ccy , olsd_stat\
ement_ref FROM ol_statement_detail WHERE olsd_stat_txn_id = :b0:b1           \
 ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,318,0,9,93,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,95,0,0,6,0,0,1,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,
0,
67,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,187,0,0,0,0,0,1,0,
97,0,0,2,324,0,4,469,0,0,10,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
152,0,0,3,112,0,4,521,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
175,0,0,4,485,0,6,686,0,0,14,14,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
246,0,0,5,345,0,6,830,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
301,0,0,6,917,0,6,1121,0,0,26,26,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,1,9,0,0,
420,0,0,7,0,0,17,1220,0,0,1,1,0,1,0,1,9,0,0,
439,0,0,7,0,0,21,1221,0,0,0,0,0,1,0,
454,0,0,8,434,0,6,1360,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
517,0,0,9,806,0,6,1640,0,0,22,22,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,4,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
620,0,0,10,522,0,4,1844,0,0,11,9,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
679,0,0,11,338,0,4,1862,0,0,7,5,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,
722,0,0,12,330,0,4,1878,0,0,7,5,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,
765,0,0,13,461,0,9,2228,0,2049,1,1,0,1,0,1,9,0,0,
784,0,0,13,0,0,13,2231,0,0,17,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,
867,0,0,13,0,0,15,2374,0,0,0,0,0,1,0,
882,0,0,13,0,0,15,2384,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/04              Stan Poon
Add error table                                    2013/09/17              Stan Poon
Cater sms / bank stmt matching                     2013/10/16              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLStatement.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void OLStatement(char	cdebug)
{
	cDebug = cdebug;
}


int GetLastBalance(hash_t *hRls)
{
	int iRet = FOUND;
	int iCnt = 0;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getlastbalance_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double	v_balance;
		/* varchar	v_statement_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_statement_date;

		/* varchar	v_statement_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_statement_time;

		double	v_txn_amount;
		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;


		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_txn_id = -1;
		short	ind_balance = -1;
		short	ind_statement_date = -1;
		short	ind_statement_time = -1;
		short	ind_txn_amount = -1;
		short	ind_amt_type = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("GetLastBalance() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("GetLastBalance() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	/* EXEC SQL DECLARE getlastbalance CURSOR FOR
			SELECT	OLSD_TXN_ID,
				OLSD_BALANCE,
				OLSD_STATEMENT_DATE,
				OLSD_STATEMENT_TIME,
				OLSD_TXN_AMOUNT,
				OLSD_AMT_TYPE
			FROM	(SELECT	*
				FROM	OL_STATEMENT_DETAIL
				WHERE	OLSD_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
				AND	OLSD_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
				AND	OLSD_STATEMENT_REF IS NOT NULL
				ORDER BY OLSD_STATEMENT_REF DESC)
			WHERE	rownum <= 2; */ 


	/* EXEC SQL OPEN getlastbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[1] = (unsigned long )52;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
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
 if (sqlca.sqlcode < 0) goto getlastbalance_error;
}


	for (;;) {
		/* EXEC SQL FETCH getlastbalance
		INTO	:v_txn_id:ind_txn_id,
			:v_balance:ind_balance,
			:v_statement_date:ind_statement_date,
			:v_statement_time:ind_statement_time,
			:v_txn_amount:ind_txn_amount,
			:v_amt_type:ind_amt_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_balance;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_balance;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_statement_date;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_statement_date;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_statement_time;
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_statement_time;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_amt_type;
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
  if (sqlca.sqlcode < 0) goto getlastbalance_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

/* txn_id */
		if (ind_txn_id>=0) {
			v_txn_id.arr[v_txn_id.len]='\0';
			if (iCnt == 1) {
				PutField_CString(hRls,"last_txn_id",(char*)v_txn_id.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls,"2nd_last_txn_id",(char*)v_txn_id.arr);
			}
DEBUGLOG(("GetLastBalance %d txn_id = [%s]\n",iCnt,(char*)v_txn_id.arr));
		}
/* balance */
		if (ind_balance>=0) {
			if (iCnt == 1) {
				PutField_Double(hRls,"last_balance",v_balance);
			} else if (iCnt == 2) {
				PutField_Double(hRls,"2nd_last_balance",v_balance);
			}
DEBUGLOG(("GetLastBalance %d balance = [%.2f]\n",iCnt,v_balance));
		}

/* statement_date */
		if (ind_statement_date>=0) {
			v_statement_date.arr[v_statement_date.len]='\0';
			if (iCnt == 1) {
				PutField_CString(hRls,"last_statement_date",(char*)v_statement_date.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls,"2nd_last_statement_date",(char*)v_statement_date.arr);
			}
DEBUGLOG(("GetLastBalance %d statement_date = [%s]\n",iCnt,(char*)v_statement_date.arr));
		}

/* statement_time */
		if (ind_statement_time>=0) {
			v_statement_time.arr[v_statement_time.len]='\0';
			if (iCnt == 1) {
				PutField_CString(hRls,"last_statement_time",(char*)v_statement_time.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls,"2nd_last_statement_time",(char*)v_statement_time.arr);
			}
DEBUGLOG(("GetLastBalance %d statement_time = [%s]\n",iCnt,(char*)v_statement_time.arr));
		}

/* txn_amount */
		if (ind_txn_amount >= 0) {
			if (iCnt == 1) {
				PutField_Double(hRls, "last_txn_amount", v_txn_amount);
			} else if (iCnt == 2) {
				PutField_Double(hRls, "2nd_last_txn_amount", v_txn_amount);
			}
DEBUGLOG(("GetLastBalance %d txn_amount = [%lf]\n",iCnt,v_txn_amount));
		}

/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			if (iCnt == 1) {
				PutField_CString(hRls, "last_amt_type", (const char*)v_amt_type.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls, "2nd_last_amt_type", (const char*)v_amt_type.arr);
			}
DEBUGLOG(("GetLastBalance %d amt_type = [%s]\n",iCnt,(const char*)v_amt_type.arr));
		}

	}
	/* EXEC SQL CLOSE getlastbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getlastbalance_error;
}



	if (iCnt > 0) {
		iRet = FOUND;
	} else {
		iRet = NOT_FOUND;
	}

DEBUGLOG(("GetLastBalance() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

getlastbalance_error:
DEBUGLOG(("getlastbalance_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getlastbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getlastbalance_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


/*
int GetExistingPastRecords(const hash_t* hRls, recordset_t* myRec, int* iRec)
{
	int	iRet;
	int	iCnt=0;
	char	*csTmp;
	char	*csTag = (char*) malloc (64);

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getpastrecord_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar	hv_int_bank_code[PD_BANK_CODE_LEN];
		varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN];
		varchar	hv_start_date[PD_DATE_LEN];
		varchar	hv_start_time[PD_TIME_LEN];
		varchar	hv_end_date[PD_DATE_LEN];
		varchar	hv_end_time[PD_TIME_LEN];
		varchar	v_stmt_date[PD_DATE_LEN + 1];
		varchar	v_stmt_time[PD_TIME_LEN + 1];
		varchar	v_txn_ccy[PD_CCY_ID_LEN + 1];
		varchar	v_amt_type[PD_AMT_TYPE_LEN + 1];
		double	v_txn_amount;
		double	v_balance;

		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_start_date = -1;
		short	ind_start_time = -1;
		short	ind_end_date = -1;
		short	ind_end_time = -1;
		short	ind_stmt_date = -1;
		short	ind_stmt_time = -1;
		short	ind_txn_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;
		short	ind_balance = -1;
	EXEC SQL END DECLARE SECTION;

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("GetExistingPastRecord() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("GetExistingPastRecord() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"start_date",&csTmp)) {
		hv_start_date.len = strlen(csTmp);
		strncpy((char*)hv_start_date.arr, csTmp, hv_start_date.len);
		ind_start_date = 0;
DEBUGLOG(("GetExistingPastRecord() fr_date = [%.*s]\n", hv_start_date.len, hv_start_date.arr));
	}

	if (GetField_CString(hRls,"start_time",&csTmp)) {
		hv_start_time.len = strlen(csTmp);
		strncpy((char*)hv_start_time.arr, csTmp, hv_start_time.len);
		ind_start_time = 0;
DEBUGLOG(("GetExistingPastRecord() fr_time = [%.*s]\n", hv_start_time.len, hv_start_time.arr));
	}

	if (GetField_CString(hRls,"end_date",&csTmp)) {
		hv_end_date.len = strlen(csTmp);
		strncpy((char*)hv_end_date.arr, csTmp, hv_end_date.len);
		ind_end_date = 0;
DEBUGLOG(("GetExistingPastRecord() to_date = [%.*s]\n", hv_end_date.len, hv_end_date.arr));
	}

	if (GetField_CString(hRls,"end_time",&csTmp)) {
		hv_end_time.len = strlen(csTmp);
		strncpy((char*)hv_end_time.arr, csTmp, hv_end_time.len);
		ind_end_time = 0;
DEBUGLOG(("GetExistingPastRecord() to_time = [%.*s]\n", hv_end_time.len, hv_end_time.arr));
	}

	EXEC SQL DECLARE getpastrecordcursor CURSOR FOR
		SELECT	OLSD_TXN_CCY,
			OLSD_AMT_TYPE,
			OLSD_TXN_AMOUNT,
			OLSD_BALANCE,
			OLSD_STATEMENT_DATE,
			OLSD_STATEMENT_TIME
		FROM	OL_STATEMENT_DETAIL
		WHERE	OLSD_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
		AND	OLSD_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
		AND	OLSD_STATEMENT_TIMESTAMP >= to_date(:hv_start_date:ind_start_date||:hv_start_time:ind_start_time,'YYYYMMDDHH24MISS')
		AND	OLSD_STATEMENT_TIMESTAMP <= to_date(:hv_end_date:ind_end_date||:hv_end_time:ind_end_time,'YYYYMMDDHH24MISS')
		AND	OLSD_STATEMENT_REF IS NOT NULL
		ORDER BY OLSD_STATEMENT_TIMESTAMP DESC, OLSD_STATEMENT_REF DESC;

	EXEC SQL OPEN getpastrecordcursor;
	for (;;) {
		EXEC SQL FETCH getpastrecordcursor
		INTO	:v_txn_ccy:ind_txn_ccy,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_balance:ind_balance,
			:v_stmt_date:ind_stmt_date,
			:v_stmt_time:ind_stmt_time;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;

// statement_date
		if (ind_stmt_date >= 0) {
			v_stmt_date.arr[v_stmt_date.len] = '\0';
			PutField_CString(myHash, "statement_date", (const char*)v_stmt_date.arr);
//DEBUGLOG(("GetExistingPastRecord statement_date = [%s]\n", (const char*)v_stmt_date.arr));
		}

// statement_time
		if (ind_stmt_time >= 0) {
			v_stmt_time.arr[v_stmt_time.len] = '\0';
			PutField_CString(myHash, "statement_time", (const char*)v_stmt_time.arr);
//DEBUGLOG(("GetExistingPastRecord statement_time = [%s]\n", (const char*)v_stmt_time.arr));
		}

// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(myHash, "txn_ccy", (const char*)v_txn_ccy.arr);
//DEBUGLOG(("GetExistingPastRecord txn_ccy = [%s]\n", (const char*)v_txn_ccy.arr));
		}

// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (const char*)v_amt_type.arr);
//DEBUGLOG(("GetExistingPastRecord amt_type = [%s]\n", (const char*)v_amt_type.arr));
		}

// txn_amount
		if (ind_txn_amount >= 0) {
			sprintf(csTag,"%.2lf",v_txn_amount);
			PutField_CString(myHash, "txn_amount", csTag);
//DEBUGLOG(("GetExistingPastRecord txn_amount = [%lf]\n", v_txn_amount));
		}

// balance
		if (ind_balance >= 0) {
			sprintf(csTag,"%.2lf",v_balance);
			PutField_CString(myHash, "balance", csTag);
//DEBUGLOG(("GetExistingPastRecord balance = [%lf]\n", v_balance));
		}

		RecordSet_Add(myRec, myHash);
	}
	EXEC SQL CLOSE getpastrecordcursor;


	if (iCnt > 0) {
		*iRec = iCnt;
DEBUGLOG(("GetExistingPastRecord() [%d] records FOUND\n",iCnt));
		iRet = FOUND;
	} else {
DEBUGLOG(("GetExistingPastRecord() NOT FOUND\n"));
		iRet = NOT_FOUND;
	}

DEBUGLOG(("GetExistingPastRecord Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getpastrecord_error:
DEBUGLOG(("getpastrecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtFormat getpastrecord_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE getpastrecordcursor;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;

}
*/


int CheckBankStmtRecord(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
	char *csTmp;
	int iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkbankstmtrecord_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar	hv_statement_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_statement_date;

		/* varchar	hv_statement_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_statement_time;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar	hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		double	hv_txn_amount;
		double	hv_balance;
		int	v_cnt;

		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_statement_date = -1;
		short	ind_statement_time = -1;
		short	ind_txn_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;
		short	ind_balance = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
// DEBUGLOG(("CheckBankStmtReocrd() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
// DEBUGLOG(("CheckBankStmtReocrd() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
// DEBUGLOG(("CheckBankStmtReocrd() statement_date = [%.*s]\n", hv_statement_date.len, hv_statement_date.arr));
	}

	if (!GetField_Int(hRls,"new_stmt_time",&iTmp)) {
		if (GetField_CString(hRls,"statement_time",&csTmp)) {
			hv_statement_time.len = strlen(csTmp);
			strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
			ind_statement_time = 0;
// DEBUGLOG(("CheckBankStmtReocrd() statement_time = [%.*s]\n", hv_statement_time.len, hv_statement_time.arr));
		}
	}

	if(GetField_CString(hRls,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		strncpy((char*)hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
// DEBUGLOG(("CheckBankStmtReocrd() txn_ccy = [%.*s]\n",hv_txn_ccy.len, hv_txn_ccy.arr));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
// DEBUGLOG(("CheckBankStmtReocrd() amt_type = [%.*s]\n",hv_amt_type.len,hv_amt_type.arr));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
// DEBUGLOG(("CheckBankStmtReocrd() txn_amount = [%.2lf]\n", hv_txn_amount));
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
// DEBUGLOG(("CheckBankStmtReocrd() balance = [%.2lf]\n", hv_balance));
	}

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_DETAIL
			WHERE	OLSD_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	OLSD_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
			AND	OLSD_STATEMENT_DATE = :hv_statement_date:ind_statement_date
			AND	(OLSD_STATEMENT_TIME = :hv_statement_time:ind_statement_time
				OR :hv_statement_time:ind_statement_time is NULL)
			AND	OLSD_TXN_CCY = :hv_txn_ccy:ind_txn_ccy
			AND	OLSD_AMT_TYPE = :hv_amt_type:ind_amt_type
			AND	OLSD_TXN_AMOUNT = :hv_txn_amount:ind_txn_amount
			AND	OLSD_BALANCE = :hv_balance:ind_balance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_DETAIL WHERE \
OLSD_INT_BANK_CODE = :b1:b2 AND OLSD_BANK_ACCT_NUM = :b3:b4 AND OLSD_STATEMEN\
T_DATE = :b5:b6 AND ( OLSD_STATEMENT_TIME = :b7:b8 OR :b7:b10 is NULL ) AND O\
LSD_TXN_CCY = :b11:b12 AND OLSD_AMT_TYPE = :b13:b14 AND OLSD_TXN_AMOUNT = :b1\
5:b16 AND OLSD_BALANCE = :b17:b18 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )97;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[3] = (unsigned long )10;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_statement_date;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[4] = (unsigned long )8;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_statement_time;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[5] = (unsigned long )8;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_statement_time;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[7] = (unsigned long )4;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_amt_type;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_balance;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto checkbankstmtrecord_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
// DEBUGLOG(("CheckBankStmtReocrd() FOUND\n"));
	} else {
		iRet = NOT_FOUND;
// DEBUGLOG(("CheckBankStmtReocrd() NOT FOUND\n"));
	}

// DEBUGLOG(("CheckBankStmtReocrd() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkbankstmtrecord_error:
DEBUGLOG(("checkbankstmtrecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CheckFileExist(const char* csFilename)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		int	v_cnt;

		short	ind_filename = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_filename.len = strlen(csFilename);
	strncpy((char*)hv_filename.arr,csFilename,hv_filename.len);
	ind_filename = 0;
DEBUGLOG(("CheckFileExist() filename = [%s]\n",csFilename));

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_HEADER
			WHERE	OLSH_ORG_FILENAME = :hv_filename:ind_filename
			AND	OLSH_MESSAGE_CODE = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_HEADER WHERE \
OLSH_ORG_FILENAME = :b1:b2 AND OLSH_MESSAGE_CODE = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )152;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[1] = (unsigned long )102;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_filename;
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
 if (sqlca.sqlcode < 0) goto checkheader_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckFileExist filename [%s] FOUND (next:[%d])\n",csFilename,v_cnt));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckFileExist filename [%s] NOT FOUND\n",csFilename));
	}

DEBUGLOG(("CheckFileExist() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int AddHeader(const hash_t *hRls)
{
	char	*csTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO addheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		int		hv_sms_count;
		int		hv_skip_count;
		int		hv_hold_count;
		int		hv_accept_count;
		int		hv_total_count;
		int		hv_message_code;
		/* varchar		hv_org_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_org_filename;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_baid = -1;
		short		ind_sms_count = -1;
		short		ind_skip_count = -1;
		short		ind_hold_count = -1;
		short		ind_accept_count = -1;
		short		ind_total_count = -1;
		short		ind_message_code = -1;
		short		ind_org_filename = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("AddHeader:file_id NOT FOUND!!!\n"));
	}

	if(GetField_CString(hRls,"new_file_name",&csTmp)) {
		hv_filename.len = strlen(csTmp);
		strncpy((char*)hv_filename.arr, csTmp, hv_filename.len);
		ind_filename = 0;
DEBUGLOG(("AddHeader:filename = [%.*s]\n",hv_filename.len, hv_filename.arr));
	} else {
DEBUGLOG(("AddHeader:filename NOT FOUND!!!\n"));
	}

	if(GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddHeader:int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if(GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddHeader:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if(GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddHeader:baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	}

	hv_sms_count = 0;
	if(GetField_Int(hRls, "sms_count", &iTmp)) {
		hv_sms_count = iTmp;
DEBUGLOG(("AddHeader:sms_count = [%d]\n",hv_sms_count));
	}
	ind_sms_count = 0;

	hv_skip_count = 0;
	if(GetField_Int(hRls, "skip_count", &iTmp)) {
		hv_skip_count = iTmp;
DEBUGLOG(("AddHeader:skip_count = [%d]\n",hv_skip_count));
	}
	ind_skip_count = 0;

	hv_hold_count = 0;
	if(GetField_Int(hRls, "hold_count", &iTmp)) {
		hv_hold_count = iTmp;
DEBUGLOG(("AddHeader:hold_count = [%d]\n",hv_hold_count));
	}
	ind_hold_count = 0;

	hv_accept_count = 0;
	if(GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
DEBUGLOG(("AddHeader:accept_count = [%d]\n",hv_accept_count));
	}
	ind_accept_count = 0;

	hv_total_count = 0;
	if(GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
DEBUGLOG(("AddHeader:total_count = [%d]\n",hv_total_count));
	}
	ind_total_count = 0;

	if(GetField_Int(hRls, "message_code", &iTmp)) {
		hv_message_code = iTmp;
		ind_message_code = 0;
DEBUGLOG(("AddHeader:message_code = [%d]\n",hv_message_code));
	}

	if(GetField_CString(hRls,"in_file_name",&csTmp)) {
		hv_org_filename.len = strlen(csTmp);
		strncpy((char*)hv_org_filename.arr, csTmp, hv_org_filename.len);
		ind_org_filename = 0;
DEBUGLOG(("AddHeader:org_filename = [%.*s]\n",hv_org_filename.len, hv_org_filename.arr));
	} else {
DEBUGLOG(("AddHeader:org_filename NOT FOUND!!!\n"));
	}

	if(GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddHeader:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	} else {
DEBUGLOG(("AddHeader:create_user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_header_insert(
						:hv_file_id:ind_file_id,
						:hv_filename:ind_filename,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_baid:ind_baid,
						:hv_sms_count:ind_sms_count,
						:hv_skip_count:ind_skip_count,
						:hv_hold_count:ind_hold_count,
						:hv_accept_count:ind_accept_count,
						:hv_total_count:ind_total_count,
						:hv_message_code:ind_message_code,
						:hv_org_filename:ind_org_filename,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_header_insert ( :\
hv_file_id:ind_file_id , :hv_filename:ind_filename , :hv_int_bank_code:ind_in\
t_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid , :hv_s\
ms_count:ind_sms_count , :hv_skip_count:ind_skip_count , :hv_hold_count:ind_h\
old_count , :hv_accept_count:ind_accept_count , :hv_total_count:ind_total_cou\
nt , :hv_message_code:ind_message_code , :hv_org_filename:ind_org_filename , \
:hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )175;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[2] = (unsigned long )102;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_filename;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_baid;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sms_count;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_sms_count;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_skip_count;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_skip_count;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_hold_count;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_hold_count;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_accept_count;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_accept_count;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_total_count;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_total_count;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_message_code;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_message_code;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_org_filename;
 sqlstm.sqhstl[12] = (unsigned long )102;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_org_filename;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[13] = (unsigned long )22;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_create_user;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto addheader_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

addheader_error:
DEBUGLOG(("addheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement_AddHeader: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateHeader(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		int		hv_sms_count;
		int		hv_skip_count;
		int		hv_hold_count;
		int		hv_accept_count;
		int		hv_total_count;
		int		hv_message_code;
		/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short		ind_file_id = -1;
		short		ind_baid = -1;
		short		ind_sms_count = -1;
		short		ind_skip_count = -1;
		short		ind_hold_count = -1;
		short		ind_accept_count = -1;
		short		ind_total_count = -1;
		short		ind_message_code = -1;
		short		ind_update_user = -1;

		short		hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("UpdateHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("UpdateHeader:file_id NOT FOUND!!!\n"));
	}

	if(GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("UpdateHeader:baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	} else {
DEBUGLOG(("UpdateHeader:baid NOT FOUND!!!\n"));
	}

	if(GetField_Int(hRls, "sms_count", &iTmp)) {
		hv_sms_count = iTmp;
		ind_sms_count = 0;
DEBUGLOG(("UpdateHeader:sms_count = [%d]\n",hv_sms_count));
	}

	if(GetField_Int(hRls, "skip_count", &iTmp)) {
		hv_skip_count = iTmp;
		ind_skip_count = 0;
DEBUGLOG(("UpdateHeader:skip_count = [%d]\n",hv_skip_count));
	}

	if(GetField_Int(hRls, "hold_count", &iTmp)) {
		hv_hold_count = iTmp;
		ind_hold_count = 0;
DEBUGLOG(("UpdateHeader:hold_count = [%d]\n",hv_hold_count));
	}

	if(GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
		ind_accept_count = 0;
DEBUGLOG(("UpdateHeader:accept_count = [%d]\n",hv_accept_count));
	}

	if(GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
		ind_total_count = 0;
DEBUGLOG(("UpdateHeader:total_count = [%d]\n",hv_total_count));
	}

	if(GetField_Int(hRls, "message_code", &iTmp)) {
		hv_message_code = iTmp;
		ind_message_code = 0;
DEBUGLOG(("UpdateHeader:message_code = [%d]\n",hv_message_code));
	}

	if(GetField_CString(hRls,"update_user",&csTmp))
	{
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateHeader:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	} else {
DEBUGLOG(("UpdateHeader:update_user NOT FOUND!!!\n"));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_header_update(
						:hv_file_id:ind_file_id,
						:hv_baid:ind_baid,
						:hv_sms_count:ind_sms_count,
						:hv_skip_count:ind_skip_count,
						:hv_hold_count:ind_hold_count,
						:hv_accept_count:ind_accept_count,
						:hv_total_count:ind_total_count,
						:hv_message_code:ind_message_code,
						:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 14;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_header_update ( :\
hv_file_id:ind_file_id , :hv_baid:ind_baid , :hv_sms_count:ind_sms_count , :h\
v_skip_count:ind_skip_count , :hv_hold_count:ind_hold_count , :hv_accept_coun\
t:ind_accept_count , :hv_total_count:ind_total_count , :hv_message_code:ind_m\
essage_code , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )246;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_baid;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_sms_count;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_sms_count;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_skip_count;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_skip_count;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_hold_count;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_hold_count;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_accept_count;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_accept_count;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_total_count;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_total_count;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_message_code;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_message_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_update_user;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto update_header_error;
}



DEBUGLOG(("UpdateHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

update_header_error:
DEBUGLOG(("update_Header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_UpdateHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int AddDetail(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;
	double	dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO addetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		int		hv_statement_seq;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_statement_ref[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_statement_ref;

		/* varchar		hv_input_channel[PD_INPUT_CHANNEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_input_channel;

		/* varchar		hv_statement_date[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_date;

		/* varchar		hv_statement_time[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_time;

		/* varchar		hv_tfr_bank_name[PD_TFR_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_bank_name;

		/* varchar		hv_tfr_bank_acct_num[PD_TFR_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_bank_acct_num;

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_customer_text;

		/* varchar		hv_sender_name[PD_SENDER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_TXN_REF_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_txn_ref_num;

		/* varchar		hv_keywords_mapping[PD_KEYWORDS_MAPPING_LEN]; */ 
struct { unsigned short len; unsigned char arr[401]; } hv_keywords_mapping;

		double		hv_balance;
		/* varchar		hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		double		hv_txn_amount;
		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_stat_txn_id = -1;
		short		ind_file_id = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_baid = -1;
		short		ind_statement_seq = -1;
		short		ind_txn_id = -1;
		short		ind_statement_ref = -1;
		short		ind_input_channel = -1;
		short		ind_statement_date = -1;
		short		ind_statement_time = -1;
		short		ind_tfr_bank_name = -1;
		short		ind_tfr_bank_acct_num = -1;
		short		ind_tfr_type = -1;
		short		ind_tfr_channel = -1;
		short		ind_tfr_text = -1;
		short		ind_tfr_customer_text = -1;
		short		ind_sender_name = -1;
		short		ind_txn_ref_num = -1;
		short		ind_keywords_mapping = -1;
		short		ind_balance = -1;
		short		ind_amt_type = -1;
		short		ind_txn_amount = -1;
		short		ind_txn_ccy = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"stat_txn_id",&csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("AddDetail: stat_txn_id = [%.*s]\n",hv_stat_txn_id.len, hv_stat_txn_id.arr));
	}

	if(GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddDetail: file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	}

	if(GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddDetail: int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if(GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddDetail: bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if(GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddDetail: baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	}

	if(GetField_Int(hRls, "statement_seq", &iTmp)) {
		hv_statement_seq = iTmp;
		ind_statement_seq = 0;
DEBUGLOG(("AddDetail: statement_seq = [%d]\n",hv_statement_seq));
	}

	if(GetField_CString(hRls,"txn_id",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("AddDetail: txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));
	}

	if(GetField_CString(hRls,"statement_ref",&csTmp)) {
		hv_statement_ref.len = strlen(csTmp);
		strncpy((char*)hv_statement_ref.arr, csTmp, hv_statement_ref.len);
		ind_statement_ref = 0;
DEBUGLOG(("AddDetail: statement_ref = [%.*s]\n",hv_statement_ref.len, hv_statement_ref.arr));
	}

	if(GetField_CString(hRls,"input_channel",&csTmp)) {
		hv_input_channel.len = strlen(csTmp);
		strncpy((char*)hv_input_channel.arr, csTmp, hv_input_channel.len);
		ind_input_channel = 0;
DEBUGLOG(("AddDetail: input_channel = [%.*s]\n",hv_input_channel.len, hv_input_channel.arr));
	}

	if(GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("AddDetail: statement_date = [%.*s]\n",hv_statement_date.len, hv_statement_date.arr));
	}

	if(GetField_CString(hRls,"statement_time",&csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
		ind_statement_time = 0;
DEBUGLOG(("AddDetail: statement_time = [%.*s]\n",hv_statement_time.len, hv_statement_time.arr));
	}

	if(GetField_CString(hRls,"tfr_bank_name",&csTmp)) {
		hv_tfr_bank_name.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_name.arr, csTmp, hv_tfr_bank_name.len);
		ind_tfr_bank_name = 0;
DEBUGLOG(("AddDetail: tfr_bank_name = [%.*s]\n",hv_tfr_bank_name.len, hv_tfr_bank_name.arr));
	}

	if(GetField_CString(hRls,"tfr_bank_acct_num",&csTmp)) {
		hv_tfr_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_acct_num.arr, csTmp, hv_tfr_bank_acct_num.len);
		ind_tfr_bank_acct_num = 0;
DEBUGLOG(("AddDetail: tfr_bank_acct_num = [%.*s]\n",hv_tfr_bank_acct_num.len, hv_tfr_bank_acct_num.arr));
	}

	if(GetField_CString(hRls,"tfr_type",&csTmp)) {
		hv_tfr_type.len = strlen(csTmp);
		strncpy((char*)hv_tfr_type.arr, csTmp, hv_tfr_type.len);
		ind_tfr_type = 0;
DEBUGLOG(("AddDetail: tfr_type = [%.*s]\n",hv_tfr_type.len, hv_tfr_type.arr));
	}

	if(GetField_CString(hRls,"tfr_channel",&csTmp)) {
		hv_tfr_channel.len = strlen(csTmp);
		strncpy((char*)hv_tfr_channel.arr, csTmp, hv_tfr_channel.len);
		ind_tfr_channel = 0;
DEBUGLOG(("AddDetail: tfr_channel = [%.*s]\n",hv_tfr_channel.len, hv_tfr_channel.arr));
	}

	if(GetField_CString(hRls,"tfr_text",&csTmp)) {
		hv_tfr_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_text.arr, csTmp, hv_tfr_text.len);
		ind_tfr_text = 0;
DEBUGLOG(("AddDetail: tfr_text = [%.*s]\n",hv_tfr_text.len, hv_tfr_text.arr));
	}

	if(GetField_CString(hRls,"tfr_customer_text",&csTmp)) {
		hv_tfr_customer_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_customer_text.arr, csTmp, hv_tfr_customer_text.len);
		ind_tfr_customer_text = 0;
DEBUGLOG(("AddDetail: tfr_customer_text = [%.*s]\n",hv_tfr_customer_text.len, hv_tfr_customer_text.arr));
	}

	if(GetField_CString(hRls,"sender_name",&csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		strncpy((char*)hv_sender_name.arr, csTmp, hv_sender_name.len);
		ind_sender_name = 0;
DEBUGLOG(("AddDetail: sender_name = [%.*s]\n",hv_sender_name.len, hv_sender_name.arr));
	}

	if(GetField_CString(hRls,"txn_ref_num",&csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		strncpy((char*)hv_txn_ref_num.arr, csTmp, hv_txn_ref_num.len);
		ind_txn_ref_num = 0;
DEBUGLOG(("AddDetail: txn_ref_num = [%.*s]\n",hv_txn_ref_num.len, hv_txn_ref_num.arr));
	}

	if(GetField_CString(hRls,"keywords_mapping",&csTmp)) {
		hv_keywords_mapping.len = strlen(csTmp);
		strncpy((char*)hv_keywords_mapping.arr, csTmp, hv_keywords_mapping.len);
		ind_keywords_mapping = 0;
DEBUGLOG(("AddDetail: keywords_mapping = [%.*s]\n",hv_keywords_mapping.len, hv_keywords_mapping.arr));
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
DEBUGLOG(("AddDetail: balance = [%.2f]\n",hv_balance));
	} else if (GetField_Double(hRls,"balance",&dTmp)) {
		hv_balance = dTmp;
		ind_balance = 0;
DEBUGLOG(("AddDetail: balance = [%.2f]\n",hv_balance));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("AddDetail: amt_type = [%.*s]\n",hv_amt_type.len,hv_amt_type.arr));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: txn_amount = [%.2f]\n",hv_txn_amount));
	} else if (GetField_Double(hRls,"txn_amount",&dTmp)) {
		hv_txn_amount = dTmp;
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: txn_amount = [%.2f]\n",hv_txn_amount));
	}

	if(GetField_CString(hRls,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		strncpy((char*)hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("AddDetail: txn_ccy = [%.*s]\n",hv_txn_ccy.len, hv_txn_ccy.arr));
	}

	if(GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddDetail: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_detail_insert(
						:hv_stat_txn_id:ind_stat_txn_id,
						:hv_file_id:ind_file_id,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_baid:ind_baid,
						:hv_statement_seq:ind_statement_seq,
						:hv_txn_id:ind_txn_id,
						:hv_statement_ref:ind_statement_ref,
						:hv_input_channel:ind_input_channel,
						:hv_statement_date:ind_statement_date,
						:hv_statement_time:ind_statement_time,
						:hv_tfr_bank_name:ind_tfr_bank_name,
						:hv_tfr_bank_acct_num:ind_tfr_bank_acct_num,
						:hv_tfr_type:ind_tfr_type,
						:hv_tfr_channel:ind_tfr_channel,
						:hv_tfr_text:ind_tfr_text,
						:hv_tfr_customer_text:ind_tfr_customer_text,
						:hv_sender_name:ind_sender_name,
						:hv_txn_ref_num:ind_txn_ref_num,
						:hv_keywords_mapping:ind_keywords_mapping,
						:hv_balance:ind_balance,
						:hv_amt_type:ind_amt_type,
						:hv_txn_amount:ind_txn_amount,
						:hv_txn_ccy:ind_txn_ccy,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_detail_insert ( :\
hv_stat_txn_id:ind_stat_txn_id , :hv_file_id:ind_file_id , :hv_int_bank_code:\
ind_int_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid ,\
 :hv_statement_seq:ind_statement_seq , :hv_txn_id:ind_txn_id , :hv_statement_\
ref:ind_statement_ref , :hv_input_channel:ind_input_channel , :hv_statement_d\
ate:ind_statement_date , :hv_statement_time:ind_statement_time , :hv_tfr_bank\
_name:ind_tfr_bank_name , :hv_tfr_bank_acct_num:ind_tfr_bank_acct_num , :hv_t\
fr_type:ind_tfr_type , :hv_tfr_channel:ind_tfr_channel , :hv_tfr_text:ind_tfr\
_text , :hv_tfr_customer_text:ind_tfr_customer_text , :hv_sender_name:ind_sen\
der_name , :hv_txn_ref_num:ind_txn_ref_num , :hv_keywords_mapping:ind_keyword\
s_mapping , :hv_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_txn_amo\
unt:ind_txn_amount , :hv_txn_ccy:ind_txn_ccy , :hv_create_user:ind_create_use\
r ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )301;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stat_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_stat_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_file_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[3] = (unsigned long )12;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_baid;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_statement_seq;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_statement_seq;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[7] = (unsigned long )18;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_statement_ref;
 sqlstm.sqhstl[8] = (unsigned long )18;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_statement_ref;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_input_channel;
 sqlstm.sqhstl[9] = (unsigned long )12;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_input_channel;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[10] = (unsigned long )52;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_statement_date;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[11] = (unsigned long )52;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_statement_time;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_tfr_bank_name;
 sqlstm.sqhstl[12] = (unsigned long )202;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_tfr_bank_name;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_tfr_bank_acct_num;
 sqlstm.sqhstl[13] = (unsigned long )202;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_tfr_bank_acct_num;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_tfr_type;
 sqlstm.sqhstl[14] = (unsigned long )202;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[15] = (unsigned long )202;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_tfr_channel;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_tfr_text;
 sqlstm.sqhstl[16] = (unsigned long )202;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_tfr_text;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_tfr_customer_text;
 sqlstm.sqhstl[17] = (unsigned long )202;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_tfr_customer_text;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_sender_name;
 sqlstm.sqhstl[18] = (unsigned long )202;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_sender_name;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_txn_ref_num;
 sqlstm.sqhstl[19] = (unsigned long )202;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_txn_ref_num;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_keywords_mapping;
 sqlstm.sqhstl[20] = (unsigned long )403;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_keywords_mapping;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_balance;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[22] = (unsigned long )4;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_amt_type;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[24] = (unsigned long )5;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[25] = (unsigned long )22;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_create_user;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto addetail_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddDetail: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

addetail_error:
DEBUGLOG(("addetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateTxnId(const hash_t *hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatetxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


	strcpy((char*)hv_dynstmt.arr, "update ol_statement_detail set olsd_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* update_user */
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("UpdateTxnId: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", olsd_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_id */
	if (GetField_CString(hRls, "txn_id", &csTmp)) {
DEBUGLOG(("UpdateTxnId: txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", olsd_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (GetField_CString(hRls, "stat_txn_id", &csTmp)) {
		strcat((char*)hv_dynstmt.arr, " where olsd_stat_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");

		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

		/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )420;
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
  if (sqlca.sqlcode < 0) goto updatetxnid_error;
}


		/* EXEC SQL EXECUTE PS; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )439;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto updatetxnid_error;
}



DEBUGLOG(("UpdateTxnId Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("UpdateTxnId FAILURE!!!\n"));
		return PD_ERR;
	}

updatetxnid_error:
DEBUGLOG(("updatetxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_UpdateTxnId: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateTxnId: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int AddSmsDetail(const hash_t *hSms, const hash_t *hText)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO addsmsdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar	hv_input_channel[PD_INPUT_CHANNEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_input_channel;

		/* varchar	hv_statement_date[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_date;

		/* varchar	hv_statement_time[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_time;

		double	hv_balance;
		/* varchar	hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		//double	hv_txn_amount;
		/* varchar hv_txn_amount[PD_SMS_BAL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_amount;

		/* varchar	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short	ind_stat_txn_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_baid = -1;
		short	ind_input_channel = -1;
		short	ind_statement_date = -1;
		short	ind_statement_time = -1;
		short	ind_balance = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;
		short	ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


/* stat_txn_id */
	if (GetField_CString(hText, "stat_txn_id", &csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("AddSmsDetail: stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));
	}

/* int_bank_code */
	if (GetField_CString(hText, "int_bank_code", &csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddSmsDetail: int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

/* bank_acct_num */
	if (GetField_CString(hText, "full_bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddSmsDetail: bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

/* baid */
	if (GetField_CString(hText, "baid", &csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddSmsDetail: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
	}

/* input_channel */
	strcpy(csTmp, "SMS_STMT");
	hv_input_channel.len = strlen(csTmp);
	strncpy((char*)hv_input_channel.arr, csTmp, hv_input_channel.len);
	ind_input_channel = 0;
DEBUGLOG(("AddSmsDetail: input_channel = [%.*s]\n", hv_input_channel.len, hv_input_channel.arr));

/* statement_date */
	if (GetField_CString(hText, "req_bank_date", &csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("AddSmsDetail: statement_date = [%.*s]\n", hv_statement_date.len, hv_statement_date.arr));
	}

/* statement_time */
	if (GetField_CString(hText, "req_bank_time", &csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
		ind_statement_time = 0;
DEBUGLOG(("AddSmsDetail: statement_time = [%.*s]\n", hv_statement_time.len, hv_statement_time.arr));
	}

/* balance */
	hv_balance = 0.00;
	ind_balance = 0;
DEBUGLOG(("AddSmsDetail: balance = [%.2f]\n", hv_balance));

/* amt_type */
	strcpy(csTmp, "CR");
	hv_amt_type.len = strlen(csTmp);
	strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
	ind_amt_type = 0;
/* txn_amount */
	if (GetField_CString(hText, "req_bank_amount", &csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr, csTmp, hv_txn_amount.len);
//		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
//DEBUGLOG(("AddSmsDetail: txn_amount = [%.2f]\n", hv_txn_amount));
DEBUGLOG(("AddSmsDetail: txn_amount = [%.*s]\n", hv_txn_amount.len, hv_txn_amount.arr));
	}

/* create_user */
	if (GetField_CString(hSms, "create_user", &csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddSmsDetail: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_sms_insert_new(
						:hv_stat_txn_id:ind_stat_txn_id,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_baid:ind_baid,
						:hv_input_channel:ind_input_channel,
						:hv_statement_date:ind_statement_date,
						:hv_statement_time:ind_statement_time,
						:hv_balance:ind_balance,
						:hv_amt_type:ind_amt_type,
						:hv_txn_amount:ind_txn_amount,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_sms_insert_new ( \
:hv_stat_txn_id:ind_stat_txn_id , :hv_int_bank_code:ind_int_bank_code , :hv_b\
ank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid , :hv_input_channel:ind_in\
put_channel , :hv_statement_date:ind_statement_date , :hv_statement_time:ind_\
statement_time , :hv_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_tx\
n_amount:ind_txn_amount , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )454;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stat_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_stat_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_baid;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_input_channel;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_input_channel;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_statement_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_statement_time;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_balance;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[9] = (unsigned long )4;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_amt_type;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[10] = (unsigned long )18;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_create_user;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto addsmsdetail_error;
}



	if (hv_return_value == SP_OK) {
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddSmsDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddSmsDetail: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddSmsDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddSmsDetail: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

addsmsdetail_error:
DEBUGLOG(("addsmsdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_AddSmsDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddSmsDetail: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int UpdateSmsDetail(const hash_t *hRls)
{
	int iTmp;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatesmsdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		hv_statement_date[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_date;

		/* varchar		hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		double		hv_txn_amount;
		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_statement_seq;
		/* varchar		hv_statement_ref[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_statement_ref;

		/* varchar		hv_statement_time[PD_CONT_TEMPLATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_statement_time;

		/* varchar		hv_tfr_bank_name[PD_TFR_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_bank_name;

		/* varchar		hv_tfr_bank_acct_num[PD_TFR_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_bank_acct_num;

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_customer_text;

		/* varchar		hv_sender_name[PD_SENDER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_TXN_REF_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_txn_ref_num;

		/* varchar		hv_keywords_mapping[PD_KEYWORDS_MAPPING_LEN]; */ 
struct { unsigned short len; unsigned char arr[401]; } hv_keywords_mapping;

		double		hv_balance;
		/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short		ind_stat_txn_id = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_statement_date = -1;
		short		ind_amt_type = -1;
		short		ind_txn_amount = -1;
		short		ind_file_id = -1;
		short		ind_statement_seq = -1;
		short		ind_statement_ref = -1;
		short		ind_statement_time = -1;
		short		ind_tfr_bank_name = -1;
		short		ind_tfr_bank_acct_num = -1;
		short		ind_tfr_type = -1;
		short		ind_tfr_channel = -1;
		short		ind_tfr_text = -1;
		short		ind_tfr_customer_text = -1;
		short		ind_sender_name = -1;
		short		ind_txn_ref_num = -1;
		short		ind_keywords_mapping = -1;
		short		ind_balance = -1;
		short		ind_update_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


/* stat_txn_id */
	if (GetField_CString(hRls, "stat_txn_id", &csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stat_txn_id.arr,csTmp,hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("UpdateSmsDetail: stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));
	} else {
DEBUGLOG(("UpdateSmsDetail: stat_txn_id NOT FOUND!!!\n"));
	}

/* int_bank_code */
	if (GetField_CString(hRls, "int_bank_code", &csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr,csTmp,hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("UpdateSmsDetail: int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	} else {
DEBUGLOG(("UpdateSmsDetail: int_bank_code NOT FOUND!!!\n"));
	}

/* bank_acct_num */
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr,csTmp,hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("UpdateSmsDetail: bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	} else {
DEBUGLOG(("UpdateSmsDetail: bank_acct_num NOT FOUND!!!\n"));
	}

/* statement_date */
	if (GetField_CString(hRls, "statement_date", &csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr,csTmp,hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("UpdateSmsDetail: statement_date = [%.*s]\n", hv_statement_date.len, hv_statement_date.arr));
	} else {
DEBUGLOG(("UpdateSmsDetail: statement_date NOT FOUND!!!\n"));
	}

/* amt_type */
	if (GetField_CString(hRls, "amt_type", &csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr,csTmp,hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("UpdateSmsDetail: amt_type = [%.*s]\n", hv_amt_type.len, hv_amt_type.arr));
	} else {
DEBUGLOG(("UpdateSmsDetail: amt_type NOT FOUND!!!\n"));
	}

/* txn_amount */
	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("UpdateSmsDetail: txn_amount = [%.2f]\n",hv_txn_amount));
	} else {
DEBUGLOG(("UpdateSmsDetail: txn_amount NOT FOUND!!!\n"));
	}

/* file_id */
	if (GetField_CString(hRls, "file_id", &csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("UpdateSmsDetail: file_id = [%.*s]\n", hv_file_id.len, hv_file_id.arr));
	}

/* statement_seq */
	if(GetField_Int(hRls, "statement_seq", &iTmp)) {
		hv_statement_seq = iTmp;
		ind_statement_seq = 0;
DEBUGLOG(("UpdateSmsDetail: statement_seq = [%d]\n",hv_statement_seq));
	}

/* statement_ref */
	if (GetField_CString(hRls, "statement_ref", &csTmp)) {
		hv_statement_ref.len = strlen(csTmp);
		strncpy((char*)hv_statement_ref.arr,csTmp,hv_statement_ref.len);
		ind_statement_ref = 0;
DEBUGLOG(("UpdateSmsDetail: statement_ref = [%.*s]\n", hv_statement_ref.len, hv_statement_ref.arr));
	}

/* statement_time */
	if (GetField_CString(hRls, "statement_time", &csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr,csTmp,hv_statement_time.len);
		ind_statement_time = 0;
DEBUGLOG(("UpdateSmsDetail: statement_time = [%.*s]\n", hv_statement_time.len, hv_statement_time.arr));
	}

/* tfr_bank_name */
	if (GetField_CString(hRls, "tfr_bank_name", &csTmp)) {
		hv_tfr_bank_name.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_name.arr,csTmp,hv_tfr_bank_name.len);
		ind_tfr_bank_name = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_bank_name = [%.*s]\n", hv_tfr_bank_name.len, hv_tfr_bank_name.arr));
	}

/* tfr_bank_acct_num */
	if (GetField_CString(hRls, "tfr_bank_acct_num", &csTmp)) {
		hv_tfr_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_acct_num.arr,csTmp,hv_tfr_bank_acct_num.len);
		ind_tfr_bank_acct_num = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_bank_acct_num = [%.*s]\n", hv_tfr_bank_acct_num.len, hv_tfr_bank_acct_num.arr));
	}

/* tfr_type */
	if (GetField_CString(hRls, "tfr_type", &csTmp)) {
		hv_tfr_type.len = strlen(csTmp);
		strncpy((char*)hv_tfr_type.arr,csTmp,hv_tfr_type.len);
		ind_tfr_type = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_type = [%.*s]\n", hv_tfr_type.len, hv_tfr_type.arr));
	}

/* tfr_channel */
	if (GetField_CString(hRls, "tfr_channel", &csTmp)) {
		hv_tfr_channel.len = strlen(csTmp);
		strncpy((char*)hv_tfr_channel.arr,csTmp,hv_tfr_channel.len);
		ind_tfr_channel = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_channel = [%.*s]\n", hv_tfr_channel.len, hv_tfr_channel.arr));
	}

/* tfr_text */
	if (GetField_CString(hRls, "tfr_text", &csTmp)) {
		hv_tfr_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_text.arr,csTmp,hv_tfr_text.len);
		ind_tfr_text = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_text = [%.*s]\n", hv_tfr_text.len, hv_tfr_text.arr));
	}

/* tfr_customer_text */
	if (GetField_CString(hRls, "tfr_customer_text", &csTmp)) {
		hv_tfr_customer_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_customer_text.arr,csTmp,hv_tfr_customer_text.len);
		ind_tfr_customer_text = 0;
DEBUGLOG(("UpdateSmsDetail: tfr_customer_text = [%.*s]\n", hv_tfr_customer_text.len, hv_tfr_customer_text.arr));
	}

/* sender_name */
	if (GetField_CString(hRls, "sender_name", &csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		strncpy((char*)hv_sender_name.arr,csTmp,hv_sender_name.len);
		ind_sender_name = 0;
DEBUGLOG(("UpdateSmsDetail: sender_name = [%.*s]\n", hv_sender_name.len, hv_sender_name.arr));
	}

/* txn_ref_num */
	if (GetField_CString(hRls, "txn_ref_num", &csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		strncpy((char*)hv_txn_ref_num.arr,csTmp,hv_txn_ref_num.len);
		ind_txn_ref_num = 0;
DEBUGLOG(("UpdateSmsDetail: txn_ref_num = [%.*s]\n", hv_txn_ref_num.len, hv_txn_ref_num.arr));
	}

/* keywords_mapping */
	if (GetField_CString(hRls, "keywords_mapping", &csTmp)) {
		hv_keywords_mapping.len = strlen(csTmp);
		strncpy((char*)hv_keywords_mapping.arr,csTmp,hv_keywords_mapping.len);
		ind_keywords_mapping = 0;
DEBUGLOG(("UpdateSmsDetail: keywords_mapping = [%.*s]\n", hv_keywords_mapping.len, hv_keywords_mapping.arr));
	}

/* balance */
	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
DEBUGLOG(("UpdateSmsDetail: balance = [%.2f]\n",hv_balance));
	}

/* update_user */
	if (GetField_CString(hRls, "update_user", &csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr,csTmp,hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateSmsDetail: update_user = [%.*s]\n", hv_update_user.len, hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_sms_update(
						:hv_stat_txn_id:ind_stat_txn_id,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_statement_date:ind_statement_date,
						:hv_amt_type:ind_amt_type,
						:hv_txn_amount:ind_txn_amount,
						:hv_file_id:ind_file_id,
						:hv_statement_seq:ind_statement_seq,
						:hv_statement_ref:ind_statement_ref,
						:hv_statement_time:ind_statement_time,
						:hv_tfr_bank_name:ind_tfr_bank_name,
						:hv_tfr_bank_acct_num:ind_tfr_bank_acct_num,
						:hv_tfr_type:ind_tfr_type,
						:hv_tfr_channel:ind_tfr_channel,
						:hv_tfr_text:ind_tfr_text,
						:hv_tfr_customer_text:ind_tfr_customer_text,
						:hv_sender_name:ind_sender_name,
						:hv_txn_ref_num:ind_txn_ref_num,
						:hv_keywords_mapping:ind_keywords_mapping,
						:hv_balance:ind_balance,
						:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_sms_update ( :hv_\
stat_txn_id:ind_stat_txn_id , :hv_int_bank_code:ind_int_bank_code , :hv_bank_\
acct_num:ind_bank_acct_num , :hv_statement_date:ind_statement_date , :hv_amt_\
type:ind_amt_type , :hv_txn_amount:ind_txn_amount , :hv_file_id:ind_file_id ,\
 :hv_statement_seq:ind_statement_seq , :hv_statement_ref:ind_statement_ref , \
:hv_statement_time:ind_statement_time , :hv_tfr_bank_name:ind_tfr_bank_name ,\
 :hv_tfr_bank_acct_num:ind_tfr_bank_acct_num , :hv_tfr_type:ind_tfr_type , :h\
v_tfr_channel:ind_tfr_channel , :hv_tfr_text:ind_tfr_text , :hv_tfr_customer_\
text:ind_tfr_customer_text , :hv_sender_name:ind_sender_name , :hv_txn_ref_nu\
m:ind_txn_ref_num , :hv_keywords_mapping:ind_keywords_mapping , :hv_balance:i\
nd_balance , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )517;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stat_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_stat_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
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
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_statement_date;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_amt_type;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[7] = (unsigned long )18;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_file_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_statement_seq;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_statement_seq;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_statement_ref;
 sqlstm.sqhstl[9] = (unsigned long )18;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_statement_ref;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[10] = (unsigned long )52;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_statement_time;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_tfr_bank_name;
 sqlstm.sqhstl[11] = (unsigned long )202;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_tfr_bank_name;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_tfr_bank_acct_num;
 sqlstm.sqhstl[12] = (unsigned long )202;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_tfr_bank_acct_num;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_tfr_type;
 sqlstm.sqhstl[13] = (unsigned long )202;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[14] = (unsigned long )202;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_tfr_channel;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_tfr_text;
 sqlstm.sqhstl[15] = (unsigned long )202;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_tfr_text;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_tfr_customer_text;
 sqlstm.sqhstl[16] = (unsigned long )202;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_tfr_customer_text;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_sender_name;
 sqlstm.sqhstl[17] = (unsigned long )202;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_sender_name;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_txn_ref_num;
 sqlstm.sqhstl[18] = (unsigned long )202;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_txn_ref_num;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_keywords_mapping;
 sqlstm.sqhstl[19] = (unsigned long )403;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_keywords_mapping;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_balance;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[21] = (unsigned long )22;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_update_user;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatesmsdetail_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateSmsDetail: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateSmsDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateSmsDetail: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateSmsDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateSmsDetail: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updatesmsdetail_error:
DEBUGLOG(("updatesmsdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement_UpdateSmsDetail: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int MatchStmt(hash_t *hRls)
{
	int iRet = PD_NOT_FOUND;
	int iTmp;

	char *csTmp;
	int iSearchChannel = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO matchstmt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		double hv_txn_amount;
		/* varchar hv_amt_type[PD_AMT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_amt_type;

		/* varchar hv_txn_date[10]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_txn_date;

		/* varchar hv_txn_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_txn_time;

		/* varchar hv_sys_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_sys_date;

		/* varchar hv_sys_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_sys_time;

		int	hv_sms_match_threshold;
		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar v_stat_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stat_txn_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short ind_txn_amount = -1;
		short ind_amt_type = -1;
		short ind_txn_date = -1;
		short ind_txn_time = -1;
		short ind_sys_date = -1;
		short ind_sys_time = -1;
		short ind_sms_match_threshold = -1;
		short ind_bank_acct_num = -1;
		short ind_int_bank_code = -1;
		short ind_stat_txn_id = -1;
		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


//// common : start

// int_bank_code
	if (GetField_CString(hRls, "int_bank_code", &csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("MatchStmt() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

// amt_type
	if (GetField_CString(hRls, "amt_type", &csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("MatchStmt() amt_type = [%.*s]\n", hv_amt_type.len, hv_amt_type.arr));
	}

//// common : end


//// for bank stmt search existing sms : start

// bank_acct_num
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("MatchStmt() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

// statement_date
	if (GetField_CString(hRls, "statement_date", &csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		strncpy((char*)hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("MatchStmt() txn_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));

		iSearchChannel = 2;
	}

// statement_time
	if (GetField_CString(hRls, "statement_time", &csTmp)) {
		hv_txn_time.len = strlen(csTmp);
		strncpy((char*)hv_txn_time.arr, csTmp, hv_txn_time.len);
		ind_txn_time = 0;
DEBUGLOG(("MatchStmt() txn_time = [%.*s]\n", hv_txn_time.len, hv_txn_time.arr));
	}

// sms_match_threshold
	if (GetField_Int(hRls, "sms_match_threshold", &iTmp)) {
		hv_sms_match_threshold = iTmp;
		ind_sms_match_threshold = 0;
DEBUGLOG(("MatchStmt() sms_match_threshold = [%d] mins\n",hv_sms_match_threshold));

		iSearchChannel = 3;
	}

// SYS_DATE
	if (GetField_CString(hRls, "SYS_DATE", &csTmp)) {
		hv_sys_date.len = strlen(csTmp);
		strncpy((char*)hv_sys_date.arr, csTmp, hv_sys_date.len);
		ind_sys_date = 0;
DEBUGLOG(("MatchStmt() sys_date = [%.*s]\n", hv_sys_date.len, hv_sys_date.arr));
	}

// SYS_TIME
	if (GetField_CString(hRls, "SYS_TIME", &csTmp)) {
		hv_sys_time.len = strlen(csTmp);
		strncpy((char*)hv_sys_time.arr, csTmp, hv_sys_time.len);
		ind_sys_time = 0;
DEBUGLOG(("MatchStmt() sys_time = [%.*s]\n", hv_sys_time.len, hv_sys_time.arr));
	}

// txn_amount
	if (GetField_CString(hRls, "txn_amount", &csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("MatchStmt() txn_amount = [%.2f]\n", hv_txn_amount));
	}

//// for bank stmt search existing sms : end



//// for sms search existing bank stmt : start

// req_bank_acc
	if (GetField_CString(hRls, "full_bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("MatchStmt() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

// req_bank_date
	if (GetField_CString(hRls, "req_bank_date", &csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		strncpy((char*)hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("MatchStmt() txn_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));
	}

// req_bank_amount
	if (GetField_CString(hRls, "req_bank_amount", &csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("MatchStmt() txn_amount = [%.2f]\n", hv_txn_amount));
	}

//// for sms search existing bank stmt : end

	if (iSearchChannel == 3) {
		/* EXEC SQL
			SELECT	olsd_stat_txn_id,
				olsd_txn_id
			into	v_stat_txn_id:ind_stat_txn_id,
				v_txn_id:ind_txn_id
			FROM	(SELECT	olsd_stat_txn_id,
					olsd_txn_id
				FROM	ol_statement_detail
				WHERE	olsd_txn_amount = :hv_txn_amount:ind_txn_amount
				AND	olsd_amt_type = :hv_amt_type:ind_amt_type
				AND	olsd_statement_timestamp >= to_date(:hv_sys_date:ind_sys_date || :hv_sys_time:ind_sys_time,'YYYYMMDDHH24MISS') - :hv_sms_match_threshold:ind_sms_match_threshold / 1440
				AND	olsd_statement_timestamp <= to_date(:hv_sys_date:ind_sys_date || :hv_sys_time:ind_sys_time,'YYYYMMDDHH24MISS')
				AND	olsd_int_bank_code = :hv_int_bank_code:ind_int_bank_code
				AND	olsd_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
				AND	olsd_statement_ref is null
				ORDER BY olsd_stat_txn_id ASC)
			WHERE ROWNUM = 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_timest\
amp >= to_date ( :b8:b9 || :b10:b11 , 'YYYYMMDDHH24MISS' ) - :b12:b13 / 1440 \
AND olsd_statement_timestamp <= to_date ( :b8:b15 || :b10:b17 , 'YYYYMMDDHH24\
MISS' ) AND olsd_int_bank_code = :b18:b19 AND olsd_bank_acct_num = :b20:b21 A\
ND olsd_statement_ref is null ORDER BY olsd_stat_txn_id ASC ) WHERE ROWNUM = \
1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )620;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stat_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_amount;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt_type;
  sqlstm.sqhstl[3] = (unsigned long )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_amt_type;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_sys_date;
  sqlstm.sqhstl[4] = (unsigned long )10;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_sys_date;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_sys_time;
  sqlstm.sqhstl[5] = (unsigned long )8;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_sys_time;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_sms_match_threshold;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_sms_match_threshold;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&hv_sys_date;
  sqlstm.sqhstl[7] = (unsigned long )10;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_sys_date;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&hv_sys_time;
  sqlstm.sqhstl[8] = (unsigned long )8;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_sys_time;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&hv_int_bank_code;
  sqlstm.sqhstl[9] = (unsigned long )12;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[10] = (unsigned long )52;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_bank_acct_num;
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
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


	} else if (iSearchChannel == 2) {
		/* EXEC SQL
			SELECT	olsd_stat_txn_id,
				olsd_txn_id
			into	v_stat_txn_id:ind_stat_txn_id,
				v_txn_id:ind_txn_id
			FROM	(SELECT	olsd_stat_txn_id,
					olsd_txn_id
				FROM	ol_statement_detail
				WHERE	olsd_txn_amount = :hv_txn_amount:ind_txn_amount
				AND	olsd_amt_type = :hv_amt_type:ind_amt_type
				AND	olsd_statement_date = :hv_txn_date:ind_txn_date
				AND	olsd_int_bank_code = :hv_int_bank_code:ind_int_bank_code
				AND	olsd_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
				AND	olsd_statement_ref is null)
			WHERE ROWNUM = 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_date =\
 :b8:b9 AND olsd_int_bank_code = :b10:b11 AND olsd_bank_acct_num = :b12:b13 A\
ND olsd_statement_ref is null ) WHERE ROWNUM = 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )679;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stat_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_amount;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt_type;
  sqlstm.sqhstl[3] = (unsigned long )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_amt_type;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_date;
  sqlstm.sqhstl[4] = (unsigned long )12;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_date;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[6] = (unsigned long )52;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_acct_num;
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
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


	} else {
		/* EXEC SQL
			SELECT	olsd_stat_txn_id,
				olsd_txn_id
			into	v_stat_txn_id:ind_stat_txn_id,
				v_txn_id:ind_txn_id
			FROM	(SELECT	olsd_stat_txn_id,
					olsd_txn_id
				FROM	ol_statement_detail
				WHERE	olsd_txn_amount = :hv_txn_amount:ind_txn_amount
				AND	olsd_amt_type = :hv_amt_type:ind_amt_type
				AND	olsd_statement_date = replace(:hv_txn_date:ind_txn_date, '-', '')
				AND	olsd_int_bank_code = :hv_int_bank_code:ind_int_bank_code
				AND	olsd_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num)
			WHERE ROWNUM = 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_date =\
 replace ( :b8:b9 , '-' , '' ) AND olsd_int_bank_code = :b10:b11 AND olsd_ban\
k_acct_num = :b12:b13 ) WHERE ROWNUM = 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )722;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_stat_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_amount;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_amt_type;
  sqlstm.sqhstl[3] = (unsigned long )4;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_amt_type;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_date;
  sqlstm.sqhstl[4] = (unsigned long )12;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_date;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[6] = (unsigned long )52;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_acct_num;
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
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


	}

	if (ind_stat_txn_id >= 0) {
		v_stat_txn_id.arr[v_stat_txn_id.len] = '\0';
		PutField_CString(hRls,"stat_txn_id",(char*)v_stat_txn_id.arr);
DEBUGLOG(("MatchStmt() stat_txn_id = [%s]\n",(char*)v_stat_txn_id.arr));
		iRet = PD_FOUND;
	}

	if (ind_txn_id >= 0) {
		v_txn_id.arr[v_txn_id.len] = '\0';
		PutField_CString(hRls,"txn_id",(char*)v_txn_id.arr);
DEBUGLOG(("MatchStmt() txn_id = [%s]\n",(char*)v_txn_id.arr));
	}

DEBUGLOG(("MatchStmt() Normal Exit iRet = [%d]\n",iRet));

	return iRet;

matchstmt_error:
DEBUGLOG(("matchstmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement:: MatchStmt: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


/* hContext: int_bank_code, bank_acct_num, stmt_date_range */
/*
int GetUnallocatedRecords(const hash_t* hContext, recordset_t* rRecordSet)
{
	int iRet = PD_OK;

	char *csTmp;
	int iTmp;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getunallocatedrecords_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_int_bank_code[PD_BANK_CODE_LEN];
		varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN];
		int	hv_stmt_date_range;
		varchar v_stmt_ref[PD_STMT_REF_LEN + 1];

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_stmt_date_range = -1;
		short ind_stmt_ref = -1;
	EXEC SQL END DECLARE SECTION;

	if (GetField_CString(hContext, "int_bank_code", &csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("GetUnallocatedRecords int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hContext, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("GetUnallocatedRecords bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_Int(hContext, "stmt_date_range", &iTmp)) {
		hv_stmt_date_range = iTmp;
		ind_stmt_date_range = 0;
DEBUGLOG(("GetUnallocatedRecords stmt_date_range = [%d]\n", hv_stmt_date_range));
	}

	EXEC SQL DECLARE c_cursor_getunallocatedrecords CURSOR FOR
		SELECT	olsd_statement_ref
		FROM	ol_statement_detail
		WHERE	olsd_int_bank_code = :hv_int_bank_code:ind_int_bank_code
		AND	olsd_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
//		AND	olsd_process_group = 'S' // system match
//		AND	olsd_status in ('S', 'U', 'W') // sms_uploaded, uploaded, pending
//		AND	olsd_type = 'DSI' // deposit
		AND	olsd_statement_timestamp >= sysdate - :hv_stmt_date_range:ind_stmt_date_range;

	EXEC SQL OPEN c_cursor_getunallocatedrecords;

	for (;;) {
		EXEC SQL FETCH c_cursor_getunallocatedrecords
		INTO	:v_stmt_ref:ind_stmt_ref;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// statement_ref
		if (ind_stmt_ref >= 0) {
			v_stmt_ref.arr[v_stmt_ref.len] = '\0';
			PutField_CString(myHash, "statement_ref", (const char*)v_stmt_ref.arr);
DEBUGLOG(("GetUnallocatedRecords statement_ref = [%s]\n", (const char*)v_stmt_ref.arr));
		}

		RecordSet_Add(rRecordSet, myHash);
	}

	EXEC SQL CLOSE c_cursor_getunallocatedrecords;

DEBUGLOG(("GetUnallocatedRecords Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getunallocatedrecords_error:
DEBUGLOG(("getunallocatedrecords_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getunallocatedrecords_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE c_cursor_getunallocatedrecords;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/

/*
int GetUnallocatedRecords(const char* csIntBankCode, const char* csBankAcctNum, recordset_t* myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getunallocatedrecords_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_int_bank_code[PD_BANK_CODE_LEN + 1];
		varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1];
		varchar v_stmt_ref[PD_STMT_REF_LEN + 1];
		varchar v_stmt_date[PD_DATE_LEN + 1];
		varchar v_stmt_timestamp[PD_DATETIME_LEN + 1];
		varchar v_amt_type[PD_AMT_TYPE_LEN + 1];
		varchar v_txn_amount[20 + 1];
		varchar v_txn_ccy[PD_CCY_ID_LEN + 1];

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_stmt_ref = -1;
		short ind_stmt_date = -1;
		short ind_stmt_timestamp = -1;
		short ind_amt_type = -1;
		short ind_txn_amount = -1;
		short ind_txn_ccy = -1;
	EXEC SQL END DECLARE SECTION;

	hv_int_bank_code.len = strlen(csIntBankCode);
	memcpy(hv_int_bank_code.arr, csIntBankCode, hv_int_bank_code.len);
	ind_int_bank_code = 0;
DEBUGLOG(("GetUnallocatedRecords int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	memcpy(hv_bank_acct_num.arr, csBankAcctNum, hv_bank_acct_num.len);
	ind_bank_acct_num = 0;
DEBUGLOG(("GetUnallocatedRecords bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));

	EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT	olsd_statement_ref,
			olsd_statement_date,
			to_char(olsd_statement_timestamp, 'yyyymmddhh24miss'),
			olsd_amt_type,
			to_char(olsd_txn_amount),
			olsd_txn_ccy
		FROM	ol_statement_detail
		WHERE	olsd_int_bank_code = :hv_int_bank_code:ind_int_bank_code
		AND	olsd_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
		AND	olsd_process_group = 'S'
		AND	olsd_status = 'U'
		AND	olsd_type = 'DSI'
		ORDER BY olsd_statement_ref;

	EXEC SQL OPEN c_cursor;
	for (;;) {
		EXEC SQL FETCH c_cursor
		INTO	:v_stmt_ref:ind_stmt_ref,
			:v_stmt_date:ind_stmt_date,
			:v_stmt_timestamp:ind_stmt_timestamp,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;

		PutField_CString(myHash, "int_bank_code", csIntBankCode);
		PutField_CString(myHash, "bank_acct_num", csBankAcctNum);

		// statement_ref
		if (ind_stmt_ref >= 0) {
			v_stmt_ref.arr[v_stmt_ref.len] = '\0';
			PutField_CString(myHash, "statement_ref", (const char*)v_stmt_ref.arr);
DEBUGLOG(("GetUnallocatedRecords statement_ref = [%s]\n", (const char*)v_stmt_ref.arr));
		}

		// statement_date
		if (ind_stmt_date >= 0) {
			v_stmt_date.arr[v_stmt_date.len] = '\0';
			PutField_CString(myHash, "statement_date", (const char*)v_stmt_date.arr);
DEBUGLOG(("GetUnallocatedRecords statement_date = [%s]\n", (const char*)v_stmt_date.arr));
		}

		// statement_timestamp
		if (ind_stmt_timestamp >= 0) {
			v_stmt_timestamp.arr[v_stmt_timestamp.len] = '\0';
			PutField_CString(myHash, "statement_timestamp", (const char*)v_stmt_timestamp.arr);
DEBUGLOG(("GetUnallocatedRecords statement_timestamp = [%s]\n", (const char*)v_stmt_timestamp.arr));
		}

		// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetUnallocatedRecords amt_type = [%s]\n", (const char*)v_amt_type.arr));
		}

		// txn_amount
		if (ind_txn_amount >= 0) {
			v_txn_amount.arr[v_txn_amount.len] = '\0';
			PutField_CString(myHash, "txn_amount", (const char*)v_txn_amount.arr);
DEBUGLOG(("GetUnallocatedRecords txn_amount = [%s]\n", (const char*)v_txn_amount.arr));
		}

		// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(myHash, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("GetUnallocatedRecords txn_ccy = [%s]\n", (const char*)v_txn_ccy.arr));
		}

		RecordSet_Add(myRec, myHash);
	}

	EXEC SQL CLOSE c_cursor;

DEBUGLOG(("GetUnallocatedRecords Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getunallocatedrecords_error:
DEBUGLOG(("getunallocatedrecords_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getunallocatedrecords_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE c_cursor;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/


int GetStmtDtl(const char* csStmtTxnId, hash_t* hStmtDtl)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmtdtl_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_stmt_txn_id[PD_STMT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stmt_txn_id;

		/* varchar v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar v_stmt_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_stmt_date;

		/* varchar v_stmt_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_stmt_time;

		/* varchar v_stmt_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_stmt_timestamp;

		/* varchar v_tfr_bank_name[PD_TFR_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_bank_name;

		/* varchar v_tfr_bank_acct_num[PD_TFR_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_bank_acct_num;

		/* varchar v_tfr_type[PD_TFR_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_type;

		/* varchar v_tfr_channel[PD_TFR_CHANNEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_channel;

		/* varchar v_tfr_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_text;

		/* varchar v_tfr_customer_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_customer_text;

		/* varchar v_sender_name[PD_SENDER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_sender_name;

		/* varchar v_txn_ref_num[PD_TXN_REF_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_txn_ref_num;

		/* varchar v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		/* varchar v_txn_amount[PD_AMOUNT_LEN + 1 + 1]; */ 
struct { unsigned short len; unsigned char arr[14]; } v_txn_amount;

		/* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar	v_stmt_ref[PD_STMT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_ref;


		short ind_stmt_txn_id = -1;
		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_stmt_date = -1;
		short ind_stmt_time = -1;
		short ind_stmt_timestamp = -1;
		short ind_tfr_bank_name = -1;
		short ind_tfr_bank_acct_num = -1;
		short ind_tfr_type = -1;
		short ind_tfr_channel = -1;
		short ind_tfr_text = -1;
		short ind_tfr_customer_text = -1;
		short ind_sender_name = -1;
		short ind_txn_ref_num = -1;
		short ind_amt_type = -1;
		short ind_txn_amount = -1;
		short ind_txn_ccy = -1;
		short ind_stmt_ref = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_stmt_txn_id.len = strlen(csStmtTxnId);
	memcpy(hv_stmt_txn_id.arr, csStmtTxnId, hv_stmt_txn_id.len);
	ind_stmt_txn_id = 0;
DEBUGLOG(("GetStmtDtl statement_txn_id = [%.*s]\n", hv_stmt_txn_id.len, hv_stmt_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getstmtdtl CURSOR FOR
		SELECT	olsd_int_bank_code,
			olsd_bank_acct_num,
			olsd_statement_date,
			olsd_statement_time,
			to_char(olsd_statement_timestamp, 'yyyymmddhh24miss'),
			olsd_tfr_bank_name,
			olsd_tfr_bank_acct_num,
			olsd_tfr_type,
			olsd_tfr_channel,
			olsd_tfr_text,
			olsd_tfr_customer_text,
			olsd_sender_name,
			olsd_txn_ref_num,
			olsd_amt_type,
			to_char(olsd_txn_amount),
			olsd_txn_ccy,
                        olsd_statement_ref
		FROM	ol_statement_detail
		WHERE	olsd_stat_txn_id = :hv_stmt_txn_id:ind_stmt_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getstmtdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0013;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )765;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_stmt_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
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
 if (sqlca.sqlcode < 0) goto getstmtdtl_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getstmtdtl
		INTO	:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_stmt_date:ind_stmt_date,
			:v_stmt_time:ind_stmt_time,
			:v_stmt_timestamp:ind_stmt_timestamp,
			:v_tfr_bank_name:ind_tfr_bank_name,
			:v_tfr_bank_acct_num:ind_tfr_bank_acct_num,
			:v_tfr_type:ind_tfr_type,
			:v_tfr_channel:ind_tfr_channel,
			:v_tfr_text:ind_tfr_text,
			:v_tfr_customer_text:ind_tfr_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_stmt_ref:ind_stmt_ref; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 26;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )784;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_stmt_date;
  sqlstm.sqhstl[2] = (unsigned long )11;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_stmt_date;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_stmt_time;
  sqlstm.sqhstl[3] = (unsigned long )9;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_stmt_time;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_stmt_timestamp;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_stmt_timestamp;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_tfr_bank_name;
  sqlstm.sqhstl[5] = (unsigned long )203;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_tfr_bank_name;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_tfr_bank_acct_num;
  sqlstm.sqhstl[6] = (unsigned long )203;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_tfr_bank_acct_num;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_tfr_type;
  sqlstm.sqhstl[7] = (unsigned long )203;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_tfr_type;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_tfr_channel;
  sqlstm.sqhstl[8] = (unsigned long )203;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_tfr_channel;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_tfr_text;
  sqlstm.sqhstl[9] = (unsigned long )203;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_tfr_text;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_tfr_customer_text;
  sqlstm.sqhstl[10] = (unsigned long )203;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_tfr_customer_text;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_sender_name;
  sqlstm.sqhstl[11] = (unsigned long )203;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_sender_name;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_ref_num;
  sqlstm.sqhstl[12] = (unsigned long )203;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_txn_ref_num;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[13] = (unsigned long )5;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_amt_type;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[14] = (unsigned long )16;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[15] = (unsigned long )6;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_stmt_ref;
  sqlstm.sqhstl[16] = (unsigned long )19;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_stmt_ref;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getstmtdtl_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hStmtDtl, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetStmtDtl int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
		}

		// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hStmtDtl, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetStmtDtl bank_acct_num = [%s]\n", (const char*)v_bank_acct_num.arr));
		}

		// statement_date
		if (ind_stmt_date >= 0) {
			v_stmt_date.arr[v_stmt_date.len] = '\0';
			PutField_CString(hStmtDtl, "statement_date", (const char*)v_stmt_date.arr);
DEBUGLOG(("GetStmtDtl statement_date = [%s]\n", (const char*)v_stmt_date.arr));
		}

		// statement_time
		if (ind_stmt_time >= 0) {
			v_stmt_time.arr[v_stmt_time.len] = '\0';
			PutField_CString(hStmtDtl, "statement_time", (const char*)v_stmt_time.arr);
DEBUGLOG(("GetStmtDtl statement_time = [%s]\n", (const char*)v_stmt_time.arr));
		}

		// statement_timestamp
		if (ind_stmt_timestamp >= 0) {
			v_stmt_timestamp.arr[v_stmt_timestamp.len] = '\0';
			PutField_CString(hStmtDtl, "statement_timestamp", (const char*)v_stmt_timestamp.arr);
DEBUGLOG(("GetStmtDtl statement_timestamp = [%s]\n", (const char*)v_stmt_timestamp.arr));
		}

		// tfr_bank_name
		if (ind_tfr_bank_name >= 0) {
			v_tfr_bank_name.arr[v_tfr_bank_name.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_bank_name", (const char*)v_tfr_bank_name.arr);
DEBUGLOG(("GetStmtDtl tfr_bank_name = [%s]\n", (const char*)v_tfr_bank_name.arr));
		}

		// tfr_bank_acct_num
		if (ind_tfr_bank_acct_num >= 0) {
			v_tfr_bank_acct_num.arr[v_tfr_bank_acct_num.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_bank_acct_num", (const char*)v_tfr_bank_acct_num.arr);
DEBUGLOG(("GetStmtDtl tfr_bank_acct_num = [%s]\n", (const char*)v_tfr_bank_acct_num.arr));
		}

		// tfr_type
		if (ind_tfr_type >= 0) {
			v_tfr_type.arr[v_tfr_type.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_type", (const char*)v_tfr_type.arr);
DEBUGLOG(("GetStmtDtl tfr_type = [%s]\n", (const char*)v_tfr_type.arr));
		}

		// tfr_channel
		if (ind_tfr_channel >= 0) {
			v_tfr_channel.arr[v_tfr_channel.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_channel", (const char*)v_tfr_channel.arr);
DEBUGLOG(("GetStmtDtl tfr_channel = [%s]\n", (const char*)v_tfr_channel.arr));
		}

		// tfr_text
		if (ind_tfr_text >= 0) {
			v_tfr_text.arr[v_tfr_text.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_text", (const char*)v_tfr_text.arr);
DEBUGLOG(("GetStmtDtl tfr_text = [%s]\n", (const char*)v_tfr_text.arr));
		}

		// tfr_customer_text
		if (ind_tfr_customer_text >= 0) {
			v_tfr_customer_text.arr[v_tfr_customer_text.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_customer_text", (const char*)v_tfr_customer_text.arr);
DEBUGLOG(("GetStmtDtl tfr_customer_text = [%s]\n", (const char*)v_tfr_customer_text.arr));
		}

		// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(hStmtDtl, "sender_name", (const char*)v_sender_name.arr);
DEBUGLOG(("GetStmtDtl sender_name = [%s]\n", (const char*)v_sender_name.arr));
		}

		// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(hStmtDtl, "txn_ref_num", (const char*)v_txn_ref_num.arr);
DEBUGLOG(("GetStmtDtl txn_ref_num = [%s]\n", (const char*)v_txn_ref_num.arr));
		}

		// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hStmtDtl, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetStmtDtl amt_type = [%s]\n", (const char*)v_amt_type.arr));
		}

		// txn_amount
		if (ind_txn_amount >= 0) {
			v_txn_amount.arr[v_txn_amount.len] = '\0';
			PutField_CString(hStmtDtl, "txn_amount", (const char*)v_txn_amount.arr);
DEBUGLOG(("GetStmtDtl txn_amount = [%s]\n", (const char*)v_txn_amount.arr));
		}

		// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(hStmtDtl, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("GetStmtDtl txn_ccy = [%s]\n", (const char*)v_txn_ccy.arr));
		}

		// statement_ref
		if (ind_stmt_ref >= 0) {
			v_stmt_ref.arr[v_stmt_ref.len] = '\0';
			PutField_CString(hStmtDtl, "stmt_ref", (const char*)v_stmt_ref.arr);
DEBUGLOG(("GetStmtDtl stmt_ref= [%s]\n", (const char*)v_stmt_ref.arr));
		}
	}

	/* EXEC SQL CLOSE c_cursor_getstmtdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )867;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmtdtl_error;
}



DEBUGLOG(("GetStmtDtl Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmtdtl_error:
DEBUGLOG(("getstmtdtl_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getstmtdtl_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getstmtdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 26;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )882;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmtdtl_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int AuxUpdateStmt(const hash_t *hRls)
{
	int iRet = PD_OK;

	return iRet;
}

