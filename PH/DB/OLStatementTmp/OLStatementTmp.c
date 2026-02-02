
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "OLStatementTmp.pc"
};


static unsigned int sqlctx = 10302059;


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
   unsigned char  *sqhstv[36];
   unsigned long  sqhstl[36];
            int   sqhsts[36];
            short *sqindv[36];
            int   sqinds[36];
   unsigned long  sqharm[36];
   unsigned long  *sqharc[36];
   unsigned short  sqadto[36];
   unsigned short  sqtdso[36];
} sqlstm = {12,36};

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

 static char *sq0006 = 
"SELECT OLST_FILE_ID , OLST_SEQ , OLST_VER , OLST_LATEST_VER , OLST_INT_BANK\
_CODE , OLST_BANK_ACCT_NUM , OLST_SYS_SEQ , OLST_USER_SEQ , OLST_SKIP , OLST_\
RAW_DATE , OLST_RAW_TIME , OLST_STATEMENT_DATE , OLST_STATEMENT_TIME , OLST_T\
FR_BANK_NAME , OLST_TFR_BANK_ACCT_NUM , OLST_TFR_TYPE , OLST_TFR_CHANNEL , OL\
ST_TFR_TEXT , OLST_TFR_CUSTOMER_TEXT , OLST_SENDER_NAME , OLST_TXN_REF_NUM , \
OLST_BALANCE , OLST_AMT_TYPE , OLST_TXN_AMOUNT , OLST_BANK_CHARGE , OLST_SEND\
ER_BAID_NAME , OLST_RECIPIENT_BAID_NAME , OLST_CLIENT_NAME , OLST_TXN_LOCATIO\
N , OLST_TXN_TYPE , OLST_TXN_REFERENCE FROM OL_STATEMENT_TMP WHERE OLST_FILE_\
ID = :b0 AND OLST_VER <= :b1 AND ( OLST_LATEST_VER >= :b1 or OLST_LATEST_VER \
IS NULL ) AND OLST_DISABLED = 0 ORDER BY OLST_USER_SEQ ASC            ";

 static char *sq0011 = 
"SELECT OLST_FILE_ID , OLST_SEQ , OLST_VER , OLST_LATEST_VER , OLST_DISABLED\
 , OLST_SYS_SEQ , OLST_USER_SEQ , OLST_INT_BANK_CODE , OLST_BANK_ACCT_NUM , O\
LST_CREATE_USER , TO_CHAR ( OLST_CREATE_TIMESTAMP , 'YYYYMMDD HH24MISS' ) FRO\
M OL_STATEMENT_TMP WHERE OLST_FILE_ID = :b0 AND OLST_DISABLED >= 0 ORDER BY O\
LST_SEQ ASC , OLST_VER ASC            ";

 static char *sq0012 = 
"SELECT OLST_FILE_ID , OLST_SEQ , OLST_VER , OLST_LATEST_VER , OLST_DISABLED\
 , OLST_SYS_SEQ , OLST_USER_SEQ , OLST_CREATE_USER , TO_CHAR ( OLST_CREATE_TI\
MESTAMP , 'YYYYMMDD HH24MISS' ) FROM OL_STATEMENT_TMP WHERE OLST_FILE_ID = :b\
0 AND OLST_SEQ = :b1 AND OLST_LATEST_VER IS NULL AND OLST_DISABLED >= 0 ORDER\
 BY OLST_VER ASC            ";

 static char *sq0013 = 
"SELECT OLST_FILE_ID , OLST_SEQ , OLST_VER , OLST_LATEST_VER , OLST_DISABLED\
 , OLST_SYS_SEQ , OLST_USER_SEQ , OLST_INT_BANK_CODE , OLST_BANK_ACCT_NUM , O\
LST_CREATE_USER , TO_CHAR ( OLST_CREATE_TIMESTAMP , 'YYYYMMDD HH24MISS' ) FRO\
M OL_STATEMENT_TMP WHERE OLST_FILE_ID = :b0 AND OLST_LATEST_VER IS NULL AND O\
LST_DISABLED >= 0 ORDER BY OLST_SEQ DESC , OLST_VER DESC            ";

 static char *sq0014 = 
"SELECT OLST_FILE_ID , OLST_SEQ , OLST_VER , OLST_LATEST_VER , OLST_DISABLED\
 , OLST_SYS_SEQ , OLST_USER_SEQ , OLST_SKIP , OLST_INT_BANK_CODE , OLST_BANK_\
ACCT_NUM , OLST_RAW_DATE , OLST_RAW_TIME , OLST_STATEMENT_DATE , OLST_STATEME\
NT_TIME , OLST_TFR_BANK_NAME , OLST_TFR_BANK_ACCT_NUM , OLST_TFR_TYPE , OLST_\
TFR_CHANNEL , OLST_TFR_TEXT , OLST_TFR_CUSTOMER_TEXT , OLST_SENDER_NAME , OLS\
T_TXN_REF_NUM , OLST_BALANCE , OLST_AMT_TYPE , OLST_TXN_AMOUNT , OLST_BANK_CH\
ARGE , OLST_SENDER_BAID_NAME , OLST_RECIPIENT_BAID_NAME , OLST_CLIENT_NAME , \
OLST_CREATE_USER , TO_CHAR ( OLST_CREATE_TIMESTAMP , 'YYYYMMDD HH24MISS' ) , \
OLST_TXN_LOCATION , OLST_TXN_TYPE , OLST_TXN_REFERENCE FROM OL_STATEMENT_TMP \
WHERE OLST_FILE_ID = :b0 AND OLST_SEQ = :b1 AND OLST_LATEST_VER IS NULL AND O\
LST_DISABLED >= 0 ORDER BY OLST_VER DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,364,0,4,124,0,0,9,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,
56,0,0,2,1145,0,6,475,0,0,34,34,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
207,0,0,3,1223,0,6,875,0,0,36,36,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,
366,0,0,4,250,0,6,1018,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,
413,0,0,5,74,0,5,1081,0,0,1,1,0,1,0,1,9,0,0,
432,0,0,6,761,0,9,1220,0,2049,3,3,0,1,0,1,9,0,0,1,3,0,0,1,3,0,0,
459,0,0,6,0,0,13,1222,0,0,31,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
598,0,0,6,0,0,15,1477,0,0,0,0,0,1,0,
613,0,0,6,0,0,15,1492,0,0,0,0,0,1,0,
628,0,0,7,185,0,6,1568,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,
667,0,0,8,272,0,6,1799,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,
3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
718,0,0,9,202,0,6,1904,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,
9,0,0,
757,0,0,10,178,0,6,2004,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,
796,0,0,11,344,0,9,2103,0,2049,1,1,0,1,0,1,9,0,0,
815,0,0,11,0,0,13,2105,0,0,11,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
874,0,0,11,0,0,15,2200,0,0,0,0,0,1,0,
889,0,0,11,0,0,15,2212,0,0,0,0,0,1,0,
904,0,0,12,334,0,9,2275,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
927,0,0,12,0,0,13,2277,0,0,9,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
978,0,0,12,0,0,15,2356,0,0,0,0,0,1,0,
993,0,0,12,0,0,15,2368,0,0,0,0,0,1,0,
1008,0,0,13,374,0,9,2432,0,2049,1,1,0,1,0,1,9,0,0,
1027,0,0,13,0,0,13,2434,0,0,11,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1086,0,0,13,0,0,15,2529,0,0,0,0,0,1,0,
1101,0,0,13,0,0,15,2541,0,0,0,0,0,1,0,
1116,0,0,14,820,0,9,2679,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
1139,0,0,14,0,0,13,2681,0,0,34,0,0,1,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1290,0,0,14,0,0,15,2960,0,0,0,0,0,1,0,
1305,0,0,14,0,0,15,2972,0,0,0,0,0,1,0,
1320,0,0,15,532,0,4,3064,0,0,10,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/08/01              Stan Poon
Add functions
UpdateRecDetail,
UpdateUserTimestampDetail,
UpdateUserSeqDetail,
GetFirstSeqRecDetail,
GetFirstVerRecDetail,
GetLastSeqRecDetail,
GetLastVerRecDetail				   2014/10/07		   Elvis Wong
Add sender_baid_name,
    recipient_baid_name
    and client name        			   2014/12/29              Elvis Wong
Add CheckTmpRecordByProvider			   2015/04/08		   Elvis Wong
Change type, channel, customer_text length	   2015/12/15		   Elvis Wong
Add txn location, txn type and txn reference       2016/11/04              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLStatementTmp.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char	cDebug;

void OLStatementTmp(char	cdebug)
{
	cDebug = cdebug;
}

int CheckTmpRecord(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO checktmprecord_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_int_bank_code[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_bank_acct_num;

		/* varchar	hv_raw_date[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_raw_date;

		/* varchar	hv_raw_time[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_raw_time;

		/* varchar	hv_balance[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_balance;

		/* varchar	hv_amt_type[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_amt_type;

		/* varchar	hv_txn_amount[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_txn_amount;

		int	v_cnt;

		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_raw_date = -1;
		short	ind_raw_time = -1;
		short	ind_balance = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr,csTmp,sizeof(hv_int_bank_code.arr));
		ind_int_bank_code = 0;
DEBUGLOG(("CheckTmpRecord: int_bank_code = [%.*s](%d)\n",sizeof(hv_int_bank_code.arr),hv_int_bank_code.arr,hv_int_bank_code.len));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr,csTmp,sizeof(hv_bank_acct_num.arr));
		ind_bank_acct_num = 0;
DEBUGLOG(("CheckTmpRecord: bank_acct_num = [%.*s](%d)\n",sizeof(hv_bank_acct_num.arr),hv_bank_acct_num.arr,hv_bank_acct_num.len));
	}

	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr,csTmp,sizeof(hv_raw_date.arr));
		ind_raw_date = 0;
DEBUGLOG(("CheckTmpRecord: raw_date = [%.*s](%d)\n",sizeof(hv_raw_date.arr),hv_raw_date.arr,hv_raw_date.len));
	}

	if (GetField_CString(hRls,"TIME_FORMAT",&csTmp)) {
		if (GetField_CString(hRls,"raw_time",&csTmp)) {
			hv_raw_time.len = strlen(csTmp);
			strncpy((char*)hv_raw_time.arr,csTmp,sizeof(hv_raw_time.arr));
			ind_raw_time = 0;
DEBUGLOG(("CheckTmpRecord: raw_time = [%.*s](%d)\n",sizeof(hv_raw_time.arr),hv_raw_time.arr,hv_raw_time.len));
		}
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("CheckTmpRecord: balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr,csTmp,sizeof(hv_amt_type.arr));
		ind_amt_type = 0;
DEBUGLOG(("CheckTmpRecord: amt_type = [%.*s](%d)\n",sizeof(hv_amt_type.arr),hv_amt_type.arr,hv_amt_type.len));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("CheckTmpRecord: txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	}

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_TMP
			WHERE	OLST_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	OLST_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
			AND	OLST_RAW_DATE = :hv_raw_date:ind_raw_date
			AND	(OLST_RAW_TIME = :hv_raw_time:ind_raw_time
				or :ind_raw_time = -1)
			AND	OLST_BALANCE = :hv_balance:ind_balance
			AND	OLST_AMT_TYPE = :hv_amt_type:ind_amt_type
			AND	OLST_TXN_AMOUNT = :hv_txn_amount:ind_txn_amount
			AND	OLST_VER = 0
			AND	OLST_LATEST_VER IS NOT NULL
			AND	OLST_DISABLED = 0
			AND	OLST_SKIP = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_TMP WHERE OLS\
T_INT_BANK_CODE = :b1:b2 AND OLST_BANK_ACCT_NUM = :b3:b4 AND OLST_RAW_DATE = \
:b5:b6 AND ( OLST_RAW_TIME = :b7:b8 or :b9 = - 1 ) AND OLST_BALANCE = :b10:b1\
1 AND OLST_AMT_TYPE = :b12:b13 AND OLST_TXN_AMOUNT = :b14:b15 AND OLST_VER = \
0 AND OLST_LATEST_VER IS NOT NULL AND OLST_DISABLED = 0 AND OLST_SKIP = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 sqlstm.sqhstl[1] = (unsigned long )514;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )514;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[3] = (unsigned long )514;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_raw_date;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[4] = (unsigned long )514;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_raw_time;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&ind_raw_time;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[6] = (unsigned long )258;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_balance;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[7] = (unsigned long )258;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_amt_type;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[8] = (unsigned long )258;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto checktmprecord_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckTmpRecord() FOUND\n"));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckTmpRecord() NOT FOUND\n"));
	}

DEBUGLOG(("CheckTmpRecord() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checktmprecord_error:
DEBUGLOG(("checktmprecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int AddDetail(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO addetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq;
		int		hv_ver;
		int		hv_latest_ver;
		int		hv_disabled;
		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int		hv_sys_seq;
		int		hv_user_seq;
		int		hv_skip;
		/* varchar		hv_raw_date[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_raw_date;

		/* varchar		hv_raw_time[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_raw_time;

		/* varchar		hv_statement_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_statement_date;

		/* varchar		hv_statement_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_statement_time;

		/* varchar		hv_tfr_bank_name[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_bank_name;

		/* varchar		hv_tfr_bank_acct_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_bank_acct_num;

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_customer_text;

		/* varchar		hv_sender_name[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_txn_ref_num;

		/* varchar		hv_balance[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_balance;

		/* varchar		hv_amt_type[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_amt_type;

		/* varchar		hv_txn_amount[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_txn_amount;

		/* varchar		hv_bank_charge[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_bank_charge;

		/* varchar		hv_sender_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_sender_baid_name;

		/* varchar		hv_recipient_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_recipient_baid_name;

		/* varchar		hv_client_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar		hv_txn_location[PD_TXN_LOCATION_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_location;

		/* varchar		hv_txn_type[PD_TXN_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_type;

		/* varchar		hv_txn_reference[PD_TXN_REFERENCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_reference;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_latest_ver = -1;
		short		ind_disabled = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_sys_seq = -1;
		short		ind_user_seq = -1;
		short		ind_skip = -1;
		short		ind_raw_date = -1;
		short		ind_raw_time = -1;
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
		short		ind_balance = -1;
		short		ind_amt_type = -1;
		short		ind_txn_amount = -1;
		short		ind_bank_charge = -1;
		short		ind_sender_baid_name = -1;
		short		ind_recipient_baid_name = -1;
		short		ind_client_name = -1;
		short		ind_create_user = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


// file_id

	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("AddDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	if (GetField_Int(hRls, "seq", &iTmp)) {
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("AddDetail: seq = [%d]\n",hv_seq));
	}

	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("AddDetail: ver = [%d]\n",hv_ver));
	}

	if (GetField_Int(hRls, "latest_ver", &iTmp)) {
		hv_latest_ver = iTmp;
		ind_latest_ver = 0;
DEBUGLOG(("AddDetail: latest_ver = [%d]\n",hv_latest_ver));
	}

	if (GetField_Int(hRls, "disabled", &iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("AddDetail: disabled = [%d]\n",hv_disabled));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr,csTmp,sizeof(hv_int_bank_code.arr));
		ind_int_bank_code = 0;
DEBUGLOG(("AddDetail: int_bank_code = [%.*s](%d)\n",sizeof(hv_int_bank_code.arr),hv_int_bank_code.arr,hv_int_bank_code.len));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr,csTmp,sizeof(hv_bank_acct_num.arr));
		ind_bank_acct_num = 0;
DEBUGLOG(("AddDetail: bank_acct_num = [%.*s](%d)\n",sizeof(hv_bank_acct_num.arr),hv_bank_acct_num.arr,hv_bank_acct_num.len));
	}

	if (GetField_Int(hRls, "sys_seq", &iTmp)) {
		hv_sys_seq = iTmp;
		ind_sys_seq = 0;
DEBUGLOG(("AddDetail: sys_seq = [%d]\n",hv_sys_seq));
	}

	if (GetField_Int(hRls, "user_seq", &iTmp)) {
		hv_user_seq = iTmp;
		ind_user_seq = 0;
DEBUGLOG(("AddDetail: user_seq = [%d]\n",hv_user_seq));
	}

	if (GetField_Int(hRls, "skip", &iTmp)) {
		hv_skip = iTmp;
		ind_skip = 0;
DEBUGLOG(("AddDetail: skip = [%d]\n",hv_skip));
	}

	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr,csTmp,sizeof(hv_raw_date.arr));
		ind_raw_date = 0;
DEBUGLOG(("AddDetail: raw_date = [%.*s](%d)\n",sizeof(hv_raw_date.arr),hv_raw_date.arr,hv_raw_date.len));
	}

	if (GetField_CString(hRls,"raw_time",&csTmp)) {
		hv_raw_time.len = strlen(csTmp);
		strncpy((char*)hv_raw_time.arr,csTmp,sizeof(hv_raw_time.arr));
		ind_raw_time = 0;
DEBUGLOG(("AddDetail: raw_time = [%.*s](%d)\n",sizeof(hv_raw_time.arr),hv_raw_time.arr,hv_raw_time.len));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr,csTmp,sizeof(hv_statement_date.arr));
		ind_statement_date = 0;
DEBUGLOG(("AddDetail: statement_date = [%.*s](%d)\n",sizeof(hv_statement_date.arr),hv_statement_date.arr,hv_statement_date.len));
	}

	if (GetField_CString(hRls,"statement_time",&csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr,csTmp,sizeof(hv_statement_time.arr));
		ind_statement_time = 0;
DEBUGLOG(("AddDetail: statement_time = [%.*s](%d)\n",sizeof(hv_statement_time.arr),hv_statement_time.arr,hv_statement_time.len));
	}

	if (GetField_CString(hRls,"tfr_bank_name",&csTmp)) {
		hv_tfr_bank_name.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_name.arr,csTmp,sizeof(hv_tfr_bank_name.arr));
		ind_tfr_bank_name = 0;
DEBUGLOG(("AddDetail: tfr_bank_name = [%.*s](%d)\n",sizeof(hv_tfr_bank_name.arr),hv_tfr_bank_name.arr,hv_tfr_bank_name.len));
	}

	if (GetField_CString(hRls,"tfr_bank_acct_num",&csTmp)) {
		hv_tfr_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_acct_num.arr,csTmp,sizeof(hv_tfr_bank_acct_num.arr));
		ind_tfr_bank_acct_num = 0;
DEBUGLOG(("AddDetail: tfr_bank_acct_num = [%.*s](%d)\n",sizeof(hv_tfr_bank_acct_num.arr),hv_tfr_bank_acct_num.arr,hv_tfr_bank_acct_num.len));
	}

	if (GetField_CString(hRls,"tfr_type",&csTmp)) {
		hv_tfr_type.len = strlen(csTmp);
		strncpy((char*)hv_tfr_type.arr,csTmp,sizeof(hv_tfr_type.arr));
		ind_tfr_type = 0;
DEBUGLOG(("AddDetail: tfr_type = [%.*s](%d)\n",sizeof(hv_tfr_type.arr),hv_tfr_type.arr,hv_tfr_type.len));
	}

	if (GetField_CString(hRls,"tfr_channel",&csTmp)) {
		hv_tfr_channel.len = strlen(csTmp);
		strncpy((char*)hv_tfr_channel.arr,csTmp,sizeof(hv_tfr_channel.arr));
		ind_tfr_channel = 0;
DEBUGLOG(("AddDetail: tfr_channel = [%.*s](%d)\n",sizeof(hv_tfr_channel.arr),hv_tfr_channel.arr,hv_tfr_channel.len));
	}

	if (GetField_CString(hRls,"tfr_text",&csTmp)) {
		hv_tfr_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_text.arr,csTmp,sizeof(hv_tfr_text.arr));
		ind_tfr_text = 0;
DEBUGLOG(("AddDetail: tfr_text = [%.*s](%d)\n",sizeof(hv_tfr_text.arr),hv_tfr_text.arr,hv_tfr_text.len));
	}

	if (GetField_CString(hRls,"tfr_customer_text",&csTmp)) {
		hv_tfr_customer_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_customer_text.arr,csTmp,sizeof(hv_tfr_customer_text.arr));
		ind_tfr_customer_text = 0;
DEBUGLOG(("AddDetail: tfr_customer_text = [%.*s](%d)\n",sizeof(hv_tfr_customer_text.arr),hv_tfr_customer_text.arr,hv_tfr_customer_text.len));
	}

	if (GetField_CString(hRls,"sender_name",&csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		strncpy((char*)hv_sender_name.arr,csTmp,sizeof(hv_sender_name.arr));
		ind_sender_name = 0;
DEBUGLOG(("AddDetail: sender_name = [%.*s](%d)\n",sizeof(hv_sender_name.arr),hv_sender_name.arr,hv_sender_name.len));
	}

	if (GetField_CString(hRls,"txn_ref_num",&csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		strncpy((char*)hv_txn_ref_num.arr,csTmp,sizeof(hv_txn_ref_num.arr));
		ind_txn_ref_num = 0;
DEBUGLOG(("AddDetail: txn_ref_num = [%.*s](%d)\n",sizeof(hv_txn_ref_num.arr),hv_txn_ref_num.arr,hv_txn_ref_num.len));
	}

	if (GetField_CString(hRls,"org_balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("AddDetail: org_balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	} else if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("AddDetail: balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr,csTmp,sizeof(hv_amt_type.arr));
		ind_amt_type = 0;
DEBUGLOG(("AddDetail: amt_type = [%.*s](%d)\n",sizeof(hv_amt_type.arr),hv_amt_type.arr,hv_amt_type.len));
	}

	if (GetField_CString(hRls,"org_txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: org_txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	} else if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	}

	if (GetField_CString(hRls,"bank_charge",&csTmp)) {
		hv_bank_charge.len = strlen(csTmp);
		strncpy((char*)hv_bank_charge.arr,csTmp,sizeof(hv_bank_charge.arr));
		ind_bank_charge = 0;
DEBUGLOG(("AddDetail: bank_charge = [%.*s](%d)\n",sizeof(hv_bank_charge.arr),hv_bank_charge.arr,hv_bank_charge.len));
	}

	if (GetField_CString(hRls,"sender_baid_name",&csTmp)) {
                hv_sender_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_sender_baid_name.arr,csTmp,sizeof(hv_sender_baid_name.arr));
                ind_sender_baid_name = 0;
DEBUGLOG(("AddDetail: sender_baid_name = [%.*s](%d)\n",sizeof(hv_sender_baid_name.arr),hv_sender_baid_name.arr,hv_sender_baid_name.len));
        }

	if (GetField_CString(hRls,"recipient_baid_name",&csTmp)) {
                hv_recipient_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_recipient_baid_name.arr,csTmp,sizeof(hv_recipient_baid_name.arr));
                ind_recipient_baid_name = 0;
DEBUGLOG(("AddDetail: recipient_baid_name = [%.*s](%d)\n",sizeof(hv_recipient_baid_name.arr),hv_recipient_baid_name.arr,hv_recipient_baid_name.len));
        }

	if (GetField_CString(hRls,"client_name",&csTmp)) {
                hv_client_name.len = strlen(csTmp);
                strncpy((char*)hv_client_name.arr,csTmp,sizeof(hv_client_name.arr));
                ind_client_name = 0;
DEBUGLOG(("AddDetail: client_name = [%.*s](%d)\n",sizeof(hv_client_name.arr),hv_client_name.arr,hv_client_name.len));
        }

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr,csTmp,sizeof(hv_create_user.arr));
		ind_create_user = 0;
DEBUGLOG(("AddDetail: create_user = [%.*s](%d)\n",sizeof(hv_create_user.arr),hv_create_user.arr,hv_create_user.len));
	}

	if (GetField_CString(hRls, "txn_location", &csTmp)) {
		hv_txn_location.len = strlen(csTmp);
		strncpy((char*)hv_txn_location.arr, csTmp, sizeof(hv_txn_location.arr));
		ind_txn_location = 0;
DEBUGLOG(("AddDetail: txn_location = [%.*s](%d)\n", sizeof(hv_txn_location.arr), hv_txn_location.arr, hv_txn_location.len));
	}

	if (GetField_CString(hRls, "txn_type", &csTmp)) {
		hv_txn_type.len = strlen(csTmp);
		strncpy((char*)hv_txn_type.arr, csTmp, sizeof(hv_txn_type.arr));
		ind_txn_type = 0;
DEBUGLOG(("AddDetail: txn_type = [%.*s](%d)\n", sizeof(hv_txn_type.arr), hv_txn_type.arr, hv_txn_type.len));
	}

	if (GetField_CString(hRls, "txn_reference", &csTmp)) {
		hv_txn_reference.len = strlen(csTmp);
		strncpy((char*)hv_txn_reference.arr, csTmp, sizeof(hv_txn_reference.arr));
		ind_txn_reference = 0;
DEBUGLOG(("AddDetail: txn_reference = [%.*s](%d)\n", sizeof(hv_txn_reference.arr), hv_txn_reference.arr, hv_txn_reference.len));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_tmp_insert_v2(
						:hv_file_id:ind_file_id,
						:hv_seq:ind_seq,
						:hv_ver:ind_ver,
						:hv_latest_ver:ind_latest_ver,
						:hv_disabled:ind_disabled,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_sys_seq:ind_sys_seq,
						:hv_user_seq:ind_user_seq,
						:hv_skip:ind_skip,
						:hv_raw_date:ind_raw_date,
						:hv_raw_time:ind_raw_time,
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
						:hv_balance:ind_balance,
						:hv_amt_type:ind_amt_type,
						:hv_txn_amount:ind_txn_amount,
						:hv_bank_charge:ind_bank_charge,
						:hv_sender_baid_name:ind_sender_baid_name,
						:hv_recipient_baid_name:ind_recipient_baid_name,
						:hv_client_name:ind_client_name,
						:hv_create_user:ind_create_user,
						:hv_txn_location:ind_txn_location,
						:hv_txn_type:ind_txn_type,
						:hv_txn_reference:ind_txn_reference);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_statement_tmp_insert_v2 ( :hv_file_id:in\
d_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_latest_ver:ind_latest_ve\
r , :hv_disabled:ind_disabled , :hv_int_bank_code:ind_int_bank_code , :hv_ba\
nk_acct_num:ind_bank_acct_num , :hv_sys_seq:ind_sys_seq , :hv_user_seq:ind_u\
ser_seq , :hv_skip:ind_skip , :hv_raw_date:ind_raw_date , :hv_raw_time:ind_r\
aw_time , :hv_statement_date:ind_statement_date , :hv_statement_time:ind_sta\
tement_time , :hv_tfr_bank_name:ind_tfr_bank_name , :hv_tfr_bank_acct_num:in\
d_tfr_bank_acct_num , :hv_tfr_type:ind_tfr_type , :hv_tfr_channel:ind_tfr_ch\
annel , :hv_tfr_text:ind_tfr_text , :hv_tfr_customer_text:ind_tfr_customer_t\
ext , :hv_sender_name:ind_sender_name , :hv_txn_ref_num:ind_txn_ref_num , :h\
v_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_txn_amount:ind_txn_a\
mount , :hv_bank_charge:ind_bank_charge , :hv_sender_baid_name:ind_sender_ba\
id_name , :hv_recipient_baid_name:ind_recipient_baid_name , :hv_client_name:\
ind_client_name , :hv_create_user:ind_cr");
 sqlstm.stmt = "eate_user , :hv_txn_location:ind_txn_location , :hv_txn_typ\
e:ind_txn_type , :hv_txn_reference:ind_txn_reference ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )56;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ver;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_latest_ver;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_latest_ver;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_sys_seq;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_sys_seq;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_user_seq;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_user_seq;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_skip;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_skip;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[11] = (unsigned long )258;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_raw_date;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[12] = (unsigned long )258;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_raw_time;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[13] = (unsigned long )10;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_statement_date;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[14] = (unsigned long )8;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_statement_time;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_tfr_bank_name;
 sqlstm.sqhstl[15] = (unsigned long )514;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_tfr_bank_name;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_tfr_bank_acct_num;
 sqlstm.sqhstl[16] = (unsigned long )514;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_tfr_bank_acct_num;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_tfr_type;
 sqlstm.sqhstl[17] = (unsigned long )642;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[18] = (unsigned long )642;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_tfr_channel;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_tfr_text;
 sqlstm.sqhstl[19] = (unsigned long )514;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_tfr_text;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_tfr_customer_text;
 sqlstm.sqhstl[20] = (unsigned long )642;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_tfr_customer_text;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_sender_name;
 sqlstm.sqhstl[21] = (unsigned long )514;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_sender_name;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_txn_ref_num;
 sqlstm.sqhstl[22] = (unsigned long )514;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_txn_ref_num;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[23] = (unsigned long )258;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_balance;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[24] = (unsigned long )258;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_amt_type;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[25] = (unsigned long )258;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_bank_charge;
 sqlstm.sqhstl[26] = (unsigned long )258;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_bank_charge;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_sender_baid_name;
 sqlstm.sqhstl[27] = (unsigned long )152;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_sender_baid_name;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_recipient_baid_name;
 sqlstm.sqhstl[28] = (unsigned long )152;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_recipient_baid_name;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_client_name;
 sqlstm.sqhstl[29] = (unsigned long )52;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_client_name;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[30] = (unsigned long )22;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_create_user;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_txn_location;
 sqlstm.sqhstl[31] = (unsigned long )642;
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_txn_location;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[32] = (unsigned long )642;
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&ind_txn_type;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
 sqlstm.sqhstv[33] = (unsigned char  *)&hv_txn_reference;
 sqlstm.sqhstl[33] = (unsigned long )642;
 sqlstm.sqhsts[33] = (         int  )0;
 sqlstm.sqindv[33] = (         short *)&ind_txn_reference;
 sqlstm.sqinds[33] = (         int  )0;
 sqlstm.sqharm[33] = (unsigned long )0;
 sqlstm.sqadto[33] = (unsigned short )0;
 sqlstm.sqtdso[33] = (unsigned short )0;
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
ERRLOG("OLStatementTmp_AddDetail: SP_OTHER_ERR\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_AddDetail: SP_ERR\n");
DEBUGLOG(("AddDetail: SP_ERR\n"));
		return PD_ERR;
	}

addetail_error:
DEBUGLOG(("addetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("AddDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int UpdateDetail(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatedetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq;
		int		hv_ver;
		int		hv_latest_ver;
		int		hv_disabled;
		/* varchar		hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int		hv_sys_seq;
		int		hv_user_seq;
		int		hv_skip;
		/* varchar		hv_raw_date[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_raw_date;

		/* varchar		hv_raw_time[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_raw_time;

		/* varchar		hv_statement_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_statement_date;

		/* varchar		hv_statement_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_statement_time;

		/* varchar		hv_tfr_bank_name[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_bank_name;

		/* varchar		hv_tfr_bank_acct_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_bank_acct_num;

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_customer_text;

		/* varchar		hv_sender_name[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_txn_ref_num;

		/* varchar		hv_balance[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_balance;

		/* varchar		hv_amt_type[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_amt_type;

		/* varchar		hv_txn_amount[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_txn_amount;

		/* varchar		hv_bank_charge[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_bank_charge;

		/* varchar		hv_sender_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_sender_baid_name;

		/* varchar		hv_recipient_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_recipient_baid_name;

		/* varchar		hv_client_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar		hv_create_timestamp[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_timestamp;

		/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		/* varchar		hv_txn_location[PD_TXN_LOCATION_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_location;

		/* varchar		hv_txn_type[PD_TXN_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_type;

		/* varchar		hv_txn_reference[PD_TXN_REFERENCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_reference;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_latest_ver = -1;
		short		ind_disabled = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_sys_seq = -1;
		short		ind_user_seq = -1;
		short		ind_skip = -1;
		short		ind_raw_date = -1;
		short		ind_raw_time = -1;
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
		short		ind_balance = -1;
		short		ind_amt_type = -1;
		short		ind_txn_amount = -1;
		short		ind_bank_charge = -1;
		short		ind_sender_baid_name = -1;
		short		ind_recipient_baid_name = -1;
		short		ind_client_name = -1;
		short		ind_create_user = -1;
		short		ind_create_timestamp = -1;
		short		ind_update_user = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("UpdateDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	if (GetField_Int(hRls, "seq", &iTmp)) {
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("UpdateDetail: seq = [%d]\n",hv_seq));
	}

	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("UpdateDetail: ver = [%d]\n",hv_ver));
	}

	if (GetField_Int(hRls, "latest_ver", &iTmp)) {
		hv_latest_ver = iTmp;
		ind_latest_ver = 0;
DEBUGLOG(("UpdateDetail: latest_ver = [%d]\n",hv_latest_ver));
	}

	if (GetField_Int(hRls, "disabled", &iTmp)) {
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("UpdateDetail: disabled = [%d]\n",hv_disabled));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr,csTmp,sizeof(hv_int_bank_code.arr));
		ind_int_bank_code = 0;
DEBUGLOG(("UpdateDetail: int_bank_code = [%.*s](%d)\n",sizeof(hv_int_bank_code.arr),hv_int_bank_code.arr,hv_int_bank_code.len));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr,csTmp,sizeof(hv_bank_acct_num.arr));
		ind_bank_acct_num = 0;
DEBUGLOG(("UpdateDetail: bank_acct_num = [%.*s](%d)\n",sizeof(hv_bank_acct_num.arr),hv_bank_acct_num.arr,hv_bank_acct_num.len));
	}

	if (GetField_Int(hRls, "sys_seq", &iTmp)) {
		hv_sys_seq = iTmp;
		ind_sys_seq = 0;
DEBUGLOG(("UpdateDetail: sys_seq = [%d]\n",hv_sys_seq));
	}

	if (GetField_Int(hRls, "user_seq", &iTmp)) {
		hv_user_seq = iTmp;
		ind_user_seq = 0;
DEBUGLOG(("UpdateDetail: user_seq = [%d]\n",hv_user_seq));
	}

	if (GetField_Int(hRls, "skip", &iTmp)) {
		hv_skip = iTmp;
		ind_skip = 0;
DEBUGLOG(("UpdateDetail: skip = [%d]\n",hv_skip));
	}

	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr,csTmp,sizeof(hv_raw_date.arr));
		ind_raw_date = 0;
DEBUGLOG(("UpdateDetail: raw_date = [%.*s](%d)\n",sizeof(hv_raw_date.arr),hv_raw_date.arr,hv_raw_date.len));
	}

	if (GetField_CString(hRls,"raw_time",&csTmp)) {
		hv_raw_time.len = strlen(csTmp);
		strncpy((char*)hv_raw_time.arr,csTmp,sizeof(hv_raw_time.arr));
		ind_raw_time = 0;
DEBUGLOG(("UpdateDetail: raw_time = [%.*s](%d)\n",sizeof(hv_raw_time.arr),hv_raw_time.arr,hv_raw_time.len));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr,csTmp,sizeof(hv_statement_date.arr));
		ind_statement_date = 0;
DEBUGLOG(("UpdateDetail: statement_date = [%.*s](%d)\n",sizeof(hv_statement_date.arr),hv_statement_date.arr,hv_statement_date.len));
	}

	if (GetField_CString(hRls,"statement_time",&csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr,csTmp,sizeof(hv_statement_time.arr));
		ind_statement_time = 0;
DEBUGLOG(("UpdateDetail: statement_time = [%.*s](%d)\n",sizeof(hv_statement_time.arr),hv_statement_time.arr,hv_statement_time.len));
	}

	if (GetField_CString(hRls,"tfr_bank_name",&csTmp)) {
		hv_tfr_bank_name.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_name.arr,csTmp,sizeof(hv_tfr_bank_name.arr));
		ind_tfr_bank_name = 0;
DEBUGLOG(("UpdateDetail: tfr_bank_name = [%.*s](%d)\n",sizeof(hv_tfr_bank_name.arr),hv_tfr_bank_name.arr,hv_tfr_bank_name.len));
	}

	if (GetField_CString(hRls,"tfr_bank_acct_num",&csTmp)) {
		hv_tfr_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_acct_num.arr,csTmp,sizeof(hv_tfr_bank_acct_num.arr));
		ind_tfr_bank_acct_num = 0;
DEBUGLOG(("UpdateDetail: tfr_bank_acct_num = [%.*s](%d)\n",sizeof(hv_tfr_bank_acct_num.arr),hv_tfr_bank_acct_num.arr,hv_tfr_bank_acct_num.len));
	}

	if (GetField_CString(hRls,"tfr_type",&csTmp)) {
		hv_tfr_type.len = strlen(csTmp);
		strncpy((char*)hv_tfr_type.arr,csTmp,sizeof(hv_tfr_type.arr));
		ind_tfr_type = 0;
DEBUGLOG(("UpdateDetail: tfr_type = [%.*s](%d)\n",sizeof(hv_tfr_type.arr),hv_tfr_type.arr,hv_tfr_type.len));
	}

	if (GetField_CString(hRls,"tfr_channel",&csTmp)) {
		hv_tfr_channel.len = strlen(csTmp);
		strncpy((char*)hv_tfr_channel.arr,csTmp,sizeof(hv_tfr_channel.arr));
		ind_tfr_channel = 0;
DEBUGLOG(("UpdateDetail: tfr_channel = [%.*s](%d)\n",sizeof(hv_tfr_channel.arr),hv_tfr_channel.arr,hv_tfr_channel.len));
	}

	if (GetField_CString(hRls,"tfr_text",&csTmp)) {
		hv_tfr_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_text.arr,csTmp,sizeof(hv_tfr_text.arr));
		ind_tfr_text = 0;
DEBUGLOG(("UpdateDetail: tfr_text = [%.*s](%d)\n",sizeof(hv_tfr_text.arr),hv_tfr_text.arr,hv_tfr_text.len));
	}

	if (GetField_CString(hRls,"tfr_customer_text",&csTmp)) {
		hv_tfr_customer_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_customer_text.arr,csTmp,sizeof(hv_tfr_customer_text.arr));
		ind_tfr_customer_text = 0;
DEBUGLOG(("UpdateDetail: tfr_customer_text = [%.*s](%d)\n",sizeof(hv_tfr_customer_text.arr),hv_tfr_customer_text.arr,hv_tfr_customer_text.len));
	}

	if (GetField_CString(hRls,"sender_name",&csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		strncpy((char*)hv_sender_name.arr,csTmp,sizeof(hv_sender_name.arr));
		ind_sender_name = 0;
DEBUGLOG(("UpdateDetail: sender_name = [%.*s](%d)\n",sizeof(hv_sender_name.arr),hv_sender_name.arr,hv_sender_name.len));
	}

	if (GetField_CString(hRls,"txn_ref_num",&csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		strncpy((char*)hv_txn_ref_num.arr,csTmp,sizeof(hv_txn_ref_num.arr));
		ind_txn_ref_num = 0;
DEBUGLOG(("UpdateDetail: txn_ref_num = [%.*s](%d)\n",sizeof(hv_txn_ref_num.arr),hv_txn_ref_num.arr,hv_txn_ref_num.len));
	}

	if (GetField_CString(hRls,"org_balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("UpdateDetail: org_balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	} else if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("UpdateDetail: balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr,csTmp,sizeof(hv_amt_type.arr));
		ind_amt_type = 0;
DEBUGLOG(("UpdateDetail: amt_type = [%.*s](%d)\n",sizeof(hv_amt_type.arr),hv_amt_type.arr,hv_amt_type.len));
	}

	if (GetField_CString(hRls,"org_txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("UpdateDetail: org_txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	} else if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("UpdateDetail: txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	}

	if (GetField_CString(hRls,"bank_charge",&csTmp)) {
		hv_bank_charge.len = strlen(csTmp);
		strncpy((char*)hv_bank_charge.arr,csTmp,sizeof(hv_bank_charge.arr));
		ind_bank_charge = 0;
DEBUGLOG(("UpdateDetail: bank_charge = [%.*s](%d)\n",sizeof(hv_bank_charge.arr),hv_bank_charge.arr,hv_bank_charge.len));
	}

	if (GetField_CString(hRls,"sender_baid_name",&csTmp)) {
                hv_sender_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_sender_baid_name.arr,csTmp,sizeof(hv_sender_baid_name.arr));
                ind_sender_baid_name = 0;
DEBUGLOG(("UpdateDetail: sender_baid_name = [%.*s](%d)\n",sizeof(hv_sender_baid_name.arr),hv_sender_baid_name.arr,hv_sender_baid_name.len));
        }

	if (GetField_CString(hRls,"recipient_baid_name",&csTmp)) {
                hv_recipient_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_recipient_baid_name.arr,csTmp,sizeof(hv_recipient_baid_name.arr));
                ind_recipient_baid_name = 0;
DEBUGLOG(("UpdateDetail: recipient_baid_name = [%.*s](%d)\n",sizeof(hv_recipient_baid_name.arr),hv_recipient_baid_name.arr,hv_recipient_baid_name.len));
        }

	if (GetField_CString(hRls,"client_name",&csTmp)) {
                hv_client_name.len = strlen(csTmp);
                strncpy((char*)hv_client_name.arr,csTmp,sizeof(hv_client_name.arr));
                ind_client_name = 0;
DEBUGLOG(("UpdateDetail: client_name = [%.*s](%d)\n",sizeof(hv_client_name.arr),hv_client_name.arr,hv_client_name.len));
        }

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr,csTmp,sizeof(hv_create_user.arr));
		ind_create_user = 0;
DEBUGLOG(("UpdateDetail: create_user = [%.*s](%d)\n",sizeof(hv_create_user.arr),hv_create_user.arr,hv_create_user.len));
	}

	if (GetField_CString(hRls,"create_timestamp",&csTmp)) {
		hv_create_timestamp.len = strlen(csTmp);
		strncpy((char*)hv_create_timestamp.arr,csTmp,sizeof(hv_create_timestamp.arr));
		ind_create_timestamp = 0;
DEBUGLOG(("UpdateDetail: create_timestamp = [%.*s](%d)\n",sizeof(hv_create_timestamp.arr),hv_create_timestamp.arr,hv_create_timestamp.len));
	}

	if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr,csTmp,sizeof(hv_update_user.arr));
		ind_update_user = 0;
DEBUGLOG(("UpdateDetail: update_user = [%.*s](%d)\n",sizeof(hv_update_user.arr),hv_update_user.arr,hv_update_user.len));
	}

	if (GetField_CString(hRls, "txn_location", &csTmp)) {
		hv_txn_location.len = strlen(csTmp);
		strncpy((char*)hv_txn_location.arr, csTmp, sizeof(hv_txn_location.arr));
		ind_txn_location = 0;
DEBUGLOG(("UpdateDetail: txn_location = [%.*s](%d)\n", sizeof(hv_txn_location.arr), hv_txn_location.arr, hv_txn_location.len));
	}

	if (GetField_CString(hRls, "txn_type", &csTmp)) {
		hv_txn_type.len = strlen(csTmp);
		strncpy((char*)hv_txn_type.arr, csTmp, sizeof(hv_txn_type.arr));
		ind_txn_type = 0;
DEBUGLOG(("UpdateDetail: txn_type = [%.*s](%d)\n", sizeof(hv_txn_type.arr), hv_txn_type.arr, hv_txn_type.len));
	}

	if (GetField_CString(hRls, "txn_reference", &csTmp)) {
		hv_txn_reference.len = strlen(csTmp);
		strncpy((char*)hv_txn_reference.arr, csTmp, sizeof(hv_txn_reference.arr));
		ind_txn_reference = 0;
DEBUGLOG(("UpdateDetail: txn_reference = [%.*s](%d)\n", sizeof(hv_txn_reference.arr), hv_txn_reference.arr, hv_txn_reference.len));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_tmp_update_v2(
						:hv_file_id:ind_file_id,
						:hv_seq:ind_seq,
						:hv_ver:ind_ver,
						:hv_latest_ver:ind_latest_ver,
						:hv_disabled:ind_disabled,
						:hv_int_bank_code:ind_int_bank_code,
						:hv_bank_acct_num:ind_bank_acct_num,
						:hv_sys_seq:ind_sys_seq,
						:hv_user_seq:ind_user_seq,
						:hv_skip:ind_skip,
						:hv_raw_date:ind_raw_date,
						:hv_raw_time:ind_raw_time,
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
						:hv_balance:ind_balance,
						:hv_amt_type:ind_amt_type,
						:hv_txn_amount:ind_txn_amount,
						:hv_bank_charge:ind_bank_charge,
						:hv_sender_baid_name:ind_sender_baid_name,
						:hv_recipient_baid_name:ind_recipient_baid_name,
						:hv_client_name:ind_client_name,
						:hv_create_user:ind_create_user,
						:hv_create_timestamp:ind_create_timestamp,
						:hv_update_user:ind_update_user,
						:hv_txn_location:ind_txn_location,
						:hv_txn_type:ind_txn_type,
						:hv_txn_reference:ind_txn_reference);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_statement_tmp_update_v2 ( :hv_file_id:in\
d_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_latest_ver:ind_latest_ve\
r , :hv_disabled:ind_disabled , :hv_int_bank_code:ind_int_bank_code , :hv_ba\
nk_acct_num:ind_bank_acct_num , :hv_sys_seq:ind_sys_seq , :hv_user_seq:ind_u\
ser_seq , :hv_skip:ind_skip , :hv_raw_date:ind_raw_date , :hv_raw_time:ind_r\
aw_time , :hv_statement_date:ind_statement_date , :hv_statement_time:ind_sta\
tement_time , :hv_tfr_bank_name:ind_tfr_bank_name , :hv_tfr_bank_acct_num:in\
d_tfr_bank_acct_num , :hv_tfr_type:ind_tfr_type , :hv_tfr_channel:ind_tfr_ch\
annel , :hv_tfr_text:ind_tfr_text , :hv_tfr_customer_text:ind_tfr_customer_t\
ext , :hv_sender_name:ind_sender_name , :hv_txn_ref_num:ind_txn_ref_num , :h\
v_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_txn_amount:ind_txn_a\
mount , :hv_bank_charge:ind_bank_charge , :hv_sender_baid_name:ind_sender_ba\
id_name , :hv_recipient_baid_name:ind_recipient_baid_name , :hv_client_name:\
ind_client_name , :hv_create_user:ind_cr");
 sqlstm.stmt = "eate_user , :hv_create_timestamp:ind_create_timestamp , :hv\
_update_user:ind_update_user , :hv_txn_location:ind_txn_location , :hv_txn_ty\
pe:ind_txn_type , :hv_txn_reference:ind_txn_reference ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )207;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ver;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_latest_ver;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_latest_ver;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_sys_seq;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_sys_seq;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_user_seq;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_user_seq;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_skip;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_skip;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[11] = (unsigned long )258;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_raw_date;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[12] = (unsigned long )258;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_raw_time;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[13] = (unsigned long )10;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_statement_date;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[14] = (unsigned long )8;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_statement_time;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_tfr_bank_name;
 sqlstm.sqhstl[15] = (unsigned long )514;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_tfr_bank_name;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_tfr_bank_acct_num;
 sqlstm.sqhstl[16] = (unsigned long )514;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_tfr_bank_acct_num;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_tfr_type;
 sqlstm.sqhstl[17] = (unsigned long )642;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[18] = (unsigned long )642;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_tfr_channel;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_tfr_text;
 sqlstm.sqhstl[19] = (unsigned long )514;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_tfr_text;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_tfr_customer_text;
 sqlstm.sqhstl[20] = (unsigned long )642;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_tfr_customer_text;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_sender_name;
 sqlstm.sqhstl[21] = (unsigned long )514;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_sender_name;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_txn_ref_num;
 sqlstm.sqhstl[22] = (unsigned long )514;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_txn_ref_num;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[23] = (unsigned long )258;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_balance;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[24] = (unsigned long )258;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_amt_type;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[25] = (unsigned long )258;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_bank_charge;
 sqlstm.sqhstl[26] = (unsigned long )258;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_bank_charge;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_sender_baid_name;
 sqlstm.sqhstl[27] = (unsigned long )152;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_sender_baid_name;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_recipient_baid_name;
 sqlstm.sqhstl[28] = (unsigned long )152;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_recipient_baid_name;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_client_name;
 sqlstm.sqhstl[29] = (unsigned long )52;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_client_name;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[30] = (unsigned long )22;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_create_user;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_create_timestamp;
 sqlstm.sqhstl[31] = (unsigned long )22;
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_create_timestamp;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[32] = (unsigned long )22;
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&ind_update_user;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
 sqlstm.sqhstv[33] = (unsigned char  *)&hv_txn_location;
 sqlstm.sqhstl[33] = (unsigned long )642;
 sqlstm.sqhsts[33] = (         int  )0;
 sqlstm.sqindv[33] = (         short *)&ind_txn_location;
 sqlstm.sqinds[33] = (         int  )0;
 sqlstm.sqharm[33] = (unsigned long )0;
 sqlstm.sqadto[33] = (unsigned short )0;
 sqlstm.sqtdso[33] = (unsigned short )0;
 sqlstm.sqhstv[34] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[34] = (unsigned long )642;
 sqlstm.sqhsts[34] = (         int  )0;
 sqlstm.sqindv[34] = (         short *)&ind_txn_type;
 sqlstm.sqinds[34] = (         int  )0;
 sqlstm.sqharm[34] = (unsigned long )0;
 sqlstm.sqadto[34] = (unsigned short )0;
 sqlstm.sqtdso[34] = (unsigned short )0;
 sqlstm.sqhstv[35] = (unsigned char  *)&hv_txn_reference;
 sqlstm.sqhstl[35] = (unsigned long )642;
 sqlstm.sqhsts[35] = (         int  )0;
 sqlstm.sqindv[35] = (         short *)&ind_txn_reference;
 sqlstm.sqinds[35] = (         int  )0;
 sqlstm.sqharm[35] = (unsigned long )0;
 sqlstm.sqadto[35] = (unsigned short )0;
 sqlstm.sqtdso[35] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatedetail_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateDetail: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_UpdateDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateDetail: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_UpdateDetail: SP_ERR\n");
DEBUGLOG(("UpdateDetail: SP_ERR\n"));
		return PD_ERR;
	}

updatedetail_error:
DEBUGLOG(("updatedetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int UpdateSystemDetail(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updatesysdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq;
		int		hv_ver;
		int		hv_sys_seq;
		int		hv_skip;
		/* varchar		hv_statement_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_statement_date;

		/* varchar		hv_statement_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_statement_time;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_sys_seq = -1;
		short		ind_skip = -1;
		short		ind_statement_date = -1;
		short		ind_statement_time = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("UpdateSystemDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	if (GetField_Int(hRls, "seq", &iTmp)) {
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("UpdateSystemDetail: seq = [%d]\n",hv_seq));
	}

	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("UpdateSystemDetail: ver = [%d]\n",hv_ver));
	}

	if (GetField_Int(hRls, "sys_seq", &iTmp)) {
		hv_sys_seq = iTmp;
		ind_sys_seq = 0;
DEBUGLOG(("UpdateSystemDetail: sys_seq = [%d]\n",hv_sys_seq));
	}

	if (GetField_Int(hRls, "skip", &iTmp)) {
		hv_skip = iTmp;
		ind_skip = 0;
DEBUGLOG(("UpdateSystemDetail: skip = [%d]\n",hv_skip));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr,csTmp,sizeof(hv_statement_date.arr));
		ind_statement_date = 0;
DEBUGLOG(("UpdateSystemDetail: statement_date = [%.*s](%d)\n",sizeof(hv_statement_date.arr),hv_statement_date.arr,hv_statement_date.len));
	}

	if (GetField_CString(hRls,"statement_time",&csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr,csTmp,sizeof(hv_statement_time.arr));
		ind_statement_time = 0;
DEBUGLOG(("UpdateSystemDetail: statement_time = [%.*s](%d)\n",sizeof(hv_statement_time.arr),hv_statement_time.arr,hv_statement_time.len));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_tmp_sysupd(
						:hv_file_id:ind_file_id,
						:hv_seq:ind_seq,
						:hv_ver:ind_ver,
						:hv_sys_seq:ind_sys_seq,
						:hv_skip:ind_skip,
						:hv_statement_date:ind_statement_date,
						:hv_statement_time:ind_statement_time);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_tmp_sysupd ( :hv_\
file_id:ind_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_sys_seq:ind_sys\
_seq , :hv_skip:ind_skip , :hv_statement_date:ind_statement_date , :hv_statem\
ent_time:ind_statement_time ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )366;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ver;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sys_seq;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_sys_seq;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_skip;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_skip;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_statement_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_statement_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_statement_time;
 sqlstm.sqhstl[7] = (unsigned long )8;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_statement_time;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto updatesysdetail_error;
}



	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateSystemDetail: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_UpdateSystemDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateSystemDetail: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_UpdateSystemDetail: SP_ERR\n");
DEBUGLOG(("UpdateSystemDetail: SP_ERR\n"));
		return PD_ERR;
	}

updatesysdetail_error:
DEBUGLOG(("updatesysdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateSystemDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_UpdateSystemDetail: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int DisableAllDetail(const hash_t* hRls)
{
        int iRet = PD_OK;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO checktmprecord_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


		short		ind_file_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("DisableAllDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	/* EXEC SQL UPDATE OL_STATEMENT_TMP
		SET OLST_DISABLED = 1
		WHERE	OLST_FILE_ID = :hv_file_id:ind_file_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "update OL_STATEMENT_TMP SET OLST_DISABLED = 1 WHERE OLST_FI\
LE_ID = :b0:b1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )413;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_file_id;
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
 if (sqlca.sqlcode < 0) goto checktmprecord_error;
}



DEBUGLOG(("DisableAllDetail() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checktmprecord_error:
DEBUGLOG(("checktmprecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetDetail(const char* csFileId, int iVer, recordset_t* myRec)
{
	int	iRet = NOT_FOUND;

	int	iCnt = 0;
	hash_t	*myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_ver;

		/* varchar		v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		int		v_seq;
		int		v_ver;
		int		v_latest_ver;
		/* varchar		v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		int		v_sys_seq;
		int		v_user_seq;
		int		v_skip;
		/* varchar		v_raw_date[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_raw_date;

		/* varchar		v_raw_time[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_raw_time;

		/* varchar		v_statement_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_statement_date;

		/* varchar		v_statement_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_statement_time;

		/* varchar		v_tfr_bank_name[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_bank_name;

		/* varchar		v_tfr_bank_acct_num[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_bank_acct_num;

		/* varchar		v_tfr_type[PD_TFR_TYPE_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_type;

		/* varchar		v_tfr_channel[PD_TFR_CHANNEL_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_channel;

		/* varchar		v_tfr_text[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_text;

		/* varchar		v_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_customer_text;

		/* varchar		v_sender_name[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_sender_name;

		/* varchar		v_txn_ref_num[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_txn_ref_num;

		/* varchar		v_balance[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_balance;

		/* varchar		v_amt_type[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_amt_type;

		/* varchar		v_txn_amount[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_txn_amount;

		/* varchar		v_bank_charge[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_bank_charge;

		/* varchar		v_sender_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_sender_baid_name;

		/* varchar		v_recipient_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_recipient_baid_name;

		/* varchar		v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar		v_txn_location[PD_TXN_LOCATION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_location;

		/* varchar		v_txn_type[PD_TXN_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_type;

		/* varchar		v_txn_reference[PD_TXN_REFERENCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_reference;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_latest_ver = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_sys_seq = -1;
		short		ind_user_seq = -1;
		short		ind_skip = -1;
		short		ind_raw_date = -1;
		short		ind_raw_time = -1;
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
		short		ind_balance = -1;
		short		ind_amt_type = -1;
		short		ind_txn_amount = -1;
		short		ind_bank_charge = -1;
		short		ind_sender_baid_name = -1;
		short		ind_recipient_baid_name = -1;
		short		ind_client_name = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
DEBUGLOG(("GetDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

	hv_ver = iVer;
DEBUGLOG(("GetDetail: ver = [%d]\n", hv_ver));

	/* EXEC SQL DECLARE getpastrecordcursor CURSOR FOR
		SELECT	OLST_FILE_ID,
			OLST_SEQ,
			OLST_VER,
			OLST_LATEST_VER,
			OLST_INT_BANK_CODE,
			OLST_BANK_ACCT_NUM,
			OLST_SYS_SEQ,
			OLST_USER_SEQ,
			OLST_SKIP,
			OLST_RAW_DATE,
			OLST_RAW_TIME,
			OLST_STATEMENT_DATE,
			OLST_STATEMENT_TIME,
			OLST_TFR_BANK_NAME,
			OLST_TFR_BANK_ACCT_NUM,
			OLST_TFR_TYPE,
			OLST_TFR_CHANNEL,
			OLST_TFR_TEXT,
			OLST_TFR_CUSTOMER_TEXT,
			OLST_SENDER_NAME,
			OLST_TXN_REF_NUM,
			OLST_BALANCE,
			OLST_AMT_TYPE,
			OLST_TXN_AMOUNT,
			OLST_BANK_CHARGE,
			OLST_SENDER_BAID_NAME,
			OLST_RECIPIENT_BAID_NAME,
			OLST_CLIENT_NAME,
			OLST_TXN_LOCATION,
			OLST_TXN_TYPE,
			OLST_TXN_REFERENCE
		FROM	OL_STATEMENT_TMP
		WHERE	OLST_FILE_ID = :hv_file_id
		AND	OLST_VER <= :hv_ver
		AND	(OLST_LATEST_VER >= :hv_ver or OLST_LATEST_VER IS NULL)
		AND	OLST_DISABLED = 0
		ORDER BY OLST_USER_SEQ ASC; */ 


	/* EXEC SQL OPEN getpastrecordcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )432;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


	for (;;) {
		/* EXEC SQL FETCH getpastrecordcursor
		INTO	:v_file_id:ind_file_id,
			:v_seq:ind_seq,
			:v_ver:ind_ver,
			:v_latest_ver:ind_latest_ver,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_sys_seq:ind_sys_seq,
			:v_user_seq:ind_user_seq,
			:v_skip:ind_skip,
			:v_raw_date:ind_raw_date,
			:v_raw_time:ind_raw_time,
			:v_statement_date:ind_statement_date,
			:v_statement_time:ind_statement_time,
			:v_tfr_bank_name:ind_tfr_bank_name,
			:v_tfr_bank_acct_num:ind_tfr_bank_acct_num,
			:v_tfr_type:ind_tfr_type,
			:v_tfr_channel:ind_tfr_channel,
			:v_tfr_text:ind_tfr_text,
			:v_tfr_customer_text:ind_tfr_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_balance:ind_balance,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_bank_charge:ind_bank_charge,
			:v_sender_baid_name:ind_sender_baid_name,
			:v_recipient_baid_name:ind_recipient_baid_name,
			:v_client_name:ind_client_name,
			:v_txn_location:ind_txn_location,
			:v_txn_type:ind_txn_type,
			:v_txn_reference:ind_txn_reference; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 36;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )459;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_file_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_seq;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ver;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ver;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_latest_ver;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_latest_ver;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[4] = (unsigned long )13;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_sys_seq;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_sys_seq;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_user_seq;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_user_seq;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_skip;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_skip;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_raw_date;
  sqlstm.sqhstl[9] = (unsigned long )259;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_raw_date;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_raw_time;
  sqlstm.sqhstl[10] = (unsigned long )259;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_raw_time;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_statement_date;
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_statement_date;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_statement_time;
  sqlstm.sqhstl[12] = (unsigned long )9;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_statement_time;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_tfr_bank_name;
  sqlstm.sqhstl[13] = (unsigned long )515;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_tfr_bank_name;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_tfr_bank_acct_num;
  sqlstm.sqhstl[14] = (unsigned long )515;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_tfr_bank_acct_num;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_tfr_type;
  sqlstm.sqhstl[15] = (unsigned long )643;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_tfr_type;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_tfr_channel;
  sqlstm.sqhstl[16] = (unsigned long )643;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_tfr_channel;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_tfr_text;
  sqlstm.sqhstl[17] = (unsigned long )515;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_tfr_text;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_tfr_customer_text;
  sqlstm.sqhstl[18] = (unsigned long )643;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_tfr_customer_text;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_sender_name;
  sqlstm.sqhstl[19] = (unsigned long )515;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_sender_name;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_txn_ref_num;
  sqlstm.sqhstl[20] = (unsigned long )515;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_txn_ref_num;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_balance;
  sqlstm.sqhstl[21] = (unsigned long )259;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_balance;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[22] = (unsigned long )259;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_amt_type;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[23] = (unsigned long )259;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_charge;
  sqlstm.sqhstl[24] = (unsigned long )259;
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_bank_charge;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_sender_baid_name;
  sqlstm.sqhstl[25] = (unsigned long )153;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_sender_baid_name;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_recipient_baid_name;
  sqlstm.sqhstl[26] = (unsigned long )153;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_recipient_baid_name;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[27] = (unsigned long )53;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_client_name;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_txn_location;
  sqlstm.sqhstl[28] = (unsigned long )643;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_txn_location;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_txn_type;
  sqlstm.sqhstl[29] = (unsigned long )643;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_txn_type;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_txn_reference;
  sqlstm.sqhstl[30] = (unsigned long )643;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_txn_reference;
  sqlstm.sqinds[30] = (         int  )0;
  sqlstm.sqharm[30] = (unsigned long )0;
  sqlstm.sqadto[30] = (unsigned short )0;
  sqlstm.sqtdso[30] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getdetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		iCnt++;

// file_id
		if (ind_file_id >= 0) {
			v_file_id.arr[v_file_id.len] = '\0';
			PutField_CString(myHash, "file_id", (char*)v_file_id.arr);
 DEBUGLOG(("GetDetail file_id = [%s]\n", (char*)v_file_id.arr));
		}

// seq
		if (ind_seq >= 0) {
			PutField_Int(myHash, "seq", v_seq);
 DEBUGLOG(("GetDetail seq = [%d]\n", v_seq));
		}

// ver
		if (ind_ver >= 0) {
			PutField_Int(myHash, "ver", v_ver);
 DEBUGLOG(("GetDetail ver = [%d]\n", v_ver));
		}

// latest_ver
		if (ind_latest_ver >= 0) {
			PutField_Int(myHash, "latest_ver", v_latest_ver);
 DEBUGLOG(("GetDetail latest_ver = [%d]\n", v_latest_ver));
		}

// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(myHash, "int_bank_code", (char*)v_int_bank_code.arr);
 DEBUGLOG(("GetDetail int_bank_code = [%s]\n", (char*)v_int_bank_code.arr));
		}

// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "bank_acct_num", (char*)v_bank_acct_num.arr);
 DEBUGLOG(("GetDetail bank_acct_num = [%s]\n", (char*)v_bank_acct_num.arr));
		}

// sys_seq
		if (ind_sys_seq >= 0) {
			PutField_Int(myHash, "sys_seq", v_sys_seq);
 DEBUGLOG(("GetDetail sys_seq = [%d]\n", v_sys_seq));
		}

// user_seq
		if (ind_user_seq >= 0) {
			PutField_Int(myHash, "user_seq", v_user_seq);
 DEBUGLOG(("GetDetail user_seq = [%d]\n", v_user_seq));
		}

// skip
		if (ind_skip >= 0) {
			PutField_Int(myHash, "skip", v_skip);
 DEBUGLOG(("GetDetail skip = [%d]\n", v_skip));
		}

// raw_date
		if (ind_raw_date >= 0) {
			v_raw_date.arr[v_raw_date.len] = '\0';
			PutField_CString(myHash, "raw_date", (char*)v_raw_date.arr);
 DEBUGLOG(("GetDetail raw_date = [%s]\n", (char*)v_raw_date.arr));
		}

// raw_time
		if (ind_raw_time >= 0) {
			v_raw_time.arr[v_raw_time.len] = '\0';
			PutField_CString(myHash, "raw_time", (char*)v_raw_time.arr);
 DEBUGLOG(("GetDetail raw_time = [%s]\n", (char*)v_raw_time.arr));
		}

// statement_date
		if (ind_statement_date >= 0) {
			v_statement_date.arr[v_statement_date.len] = '\0';
			PutField_CString(myHash, "statement_date", (char*)v_statement_date.arr);
 DEBUGLOG(("GetDetail statement_date = [%s]\n", (char*)v_statement_date.arr));
		}

// statement_time
		if (ind_statement_time >= 0) {
			v_statement_time.arr[v_statement_time.len] = '\0';
			PutField_CString(myHash, "statement_time", (char*)v_statement_time.arr);
 DEBUGLOG(("GetDetail statement_time = [%s]\n", (char*)v_statement_time.arr));
		}

// tfr_bank_name
		if (ind_tfr_bank_name >= 0) {
			v_tfr_bank_name.arr[v_tfr_bank_name.len] = '\0';
			PutField_CString(myHash, "tfr_bank_name", (char*)v_tfr_bank_name.arr);
 DEBUGLOG(("GetDetail tfr_bank_name = [%s]\n", (char*)v_tfr_bank_name.arr));
		}

// tfr_bank_acct_num
		if (ind_tfr_bank_acct_num >= 0) {
			v_tfr_bank_acct_num.arr[v_tfr_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "tfr_bank_acct_num", (char*)v_tfr_bank_acct_num.arr);
 DEBUGLOG(("GetDetail tfr_bank_acct_num = [%s]\n", (char*)v_tfr_bank_acct_num.arr));
		}

// tfr_type
		if (ind_tfr_type >= 0) {
			v_tfr_type.arr[v_tfr_type.len] = '\0';
			PutField_CString(myHash, "tfr_type", (char*)v_tfr_type.arr);
 DEBUGLOG(("GetDetail tfr_type = [%s]\n", (char*)v_tfr_type.arr));
		}

// tfr_channel
		if (ind_tfr_channel >= 0) {
			v_tfr_channel.arr[v_tfr_channel.len] = '\0';
			PutField_CString(myHash, "tfr_channel", (char*)v_tfr_channel.arr);
 DEBUGLOG(("GetDetail tfr_channel = [%s]\n", (char*)v_tfr_channel.arr));
		}

// tfr_text
		if (ind_tfr_text >= 0) {
			v_tfr_text.arr[v_tfr_text.len] = '\0';
			PutField_CString(myHash, "tfr_text", (char*)v_tfr_text.arr);
 DEBUGLOG(("GetDetail tfr_text = [%s]\n", (char*)v_tfr_text.arr));
		}

// tfr_customer_text
		if (ind_tfr_customer_text >= 0) {
			v_tfr_customer_text.arr[v_tfr_customer_text.len] = '\0';
			PutField_CString(myHash, "tfr_customer_text", (char*)v_tfr_customer_text.arr);
 DEBUGLOG(("GetDetail tfr_customer_text = [%s]\n", (char*)v_tfr_customer_text.arr));
		}

// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(myHash, "sender_name", (char*)v_sender_name.arr);
 DEBUGLOG(("GetDetail sender_name = [%s]\n", (char*)v_sender_name.arr));
		}

// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(myHash, "txn_ref_num", (char*)v_txn_ref_num.arr);
 DEBUGLOG(("GetDetail txn_ref_num = [%s]\n", (char*)v_txn_ref_num.arr));
		}

// balance
		if (ind_balance >= 0) {
			v_balance.arr[v_balance.len] = '\0';
			PutField_CString(myHash, "balance", (char*)v_balance.arr);
 DEBUGLOG(("GetDetail balance = [%s]\n", (char*)v_balance.arr));
		}

// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(myHash, "amt_type", (char*)v_amt_type.arr);
 DEBUGLOG(("GetDetail amt_type = [%s]\n", (char*)v_amt_type.arr));
		}

// txn_amount
		if (ind_txn_amount >= 0) {
			v_txn_amount.arr[v_txn_amount.len] = '\0';
			PutField_CString(myHash, "txn_amount", (char*)v_txn_amount.arr);
 DEBUGLOG(("GetDetail txn_amount = [%s]\n", (char*)v_txn_amount.arr));
		}

// bank_charge
		if (ind_bank_charge >= 0) {
			v_bank_charge.arr[v_bank_charge.len] = '\0';
			PutField_CString(myHash, "bank_charge", (char*)v_bank_charge.arr);
 DEBUGLOG(("GetDetail bank_charge = [%s]\n", (char*)v_bank_charge.arr));
		}

// sender_baid_name
                if (ind_sender_baid_name >= 0) {
                        v_sender_baid_name.arr[v_sender_baid_name.len] = '\0';
                        PutField_CString(myHash, "sender_baid_name", (char*)v_sender_baid_name.arr);
 DEBUGLOG(("GetDetail sender_baid_name = [%s]\n", (char*)v_sender_baid_name.arr));
                }

// recipient_baid_name
                if (ind_recipient_baid_name >= 0) {
                        v_recipient_baid_name.arr[v_recipient_baid_name.len] = '\0';
                        PutField_CString(myHash, "recipient_baid_name", (char*)v_recipient_baid_name.arr);
 DEBUGLOG(("GetDetail recipient_baid_name = [%s]\n", (char*)v_recipient_baid_name.arr));
                }

// client_name
                if (ind_client_name >= 0) {
                        v_client_name.arr[v_client_name.len] = '\0';
                        PutField_CString(myHash, "client_name", (char*)v_client_name.arr);
 DEBUGLOG(("GetDetail client_name = [%s]\n", (char*)v_client_name.arr));
                }

// txn_location
		if (ind_txn_location >= 0) {
			v_txn_location.arr[v_txn_location.len] = '\0';
			PutField_CString(myHash, "txn_location", (char*)v_txn_location.arr);
DEBUGLOG(("GetDetail txn_location = [%s]\n", (char*)v_txn_location.arr));
		}

// txn_type
		if (ind_txn_type >= 0) {
			v_txn_type.arr[v_txn_type.len] = '\0';
			PutField_CString(myHash, "txn_type", (char*)v_txn_type.arr);
DEBUGLOG(("GetDetail txn_type = [%s]\n", (char*)v_txn_type.arr));
		}

// txn_reference
		if (ind_txn_reference >= 0) {
			v_txn_reference.arr[v_txn_reference.len] = '\0';
			PutField_CString(myHash, "txn_reference", (char*)v_txn_reference.arr);
DEBUGLOG(("GetDetail txn_reference = [%s]\n", (char*)v_txn_reference.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	/* EXEC SQL CLOSE getpastrecordcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )598;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetail_error;
}



	if (iCnt > 0) {
		iRet = FOUND;
DEBUGLOG(("GetDetail() FOUND\n"));
	}

DEBUGLOG(("GetDetail Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLSatementTmp getdetail_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE getpastrecordcursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )613;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}

int AddError(const hash_t *hRls)
{
	char	*csTmp;
	int	iResultCnt;
	int	iTmp;

	char	*csTag = (char*) malloc (64);

	/* EXEC SQL WHENEVER SQLERROR GOTO adderr_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		int		hv_seq;
		int		hv_ver;
		/* varchar		hv_result[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_result;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_result = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("AddError:file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	if(GetField_Int(hRls,"ver",&iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("AddError:ver = [%d]\n",hv_ver));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr,csTmp,sizeof(hv_create_user.arr));
		ind_create_user = 0;
DEBUGLOG(("AddError:create_user = [%.*s](%d)\n",sizeof(hv_create_user.arr),hv_create_user.arr,hv_create_user.len));
	}

	if (GetField_Int(hRls,"result_cnt",&iResultCnt)) {
DEBUGLOG(("AddError:result_cnt = [%d]\n",iResultCnt));
		int i;
		for (i=1;i<=iResultCnt;i++) {
			ind_seq = -1;
			ind_result = -1;

			sprintf(csTag,"seq_%d",i);
			if (GetField_Int(hRls,csTag,&iTmp)) {
				hv_seq = iTmp;
				ind_seq = 0;
			}
DEBUGLOG(("AddError: %s = [%d]\n",csTag,hv_seq));

			sprintf(csTag,"result_%d",i);
			if (GetField_CString(hRls,csTag,&csTmp)) {
				hv_result.len = strlen(csTmp);
				strncpy((char*)hv_result.arr,csTmp,sizeof(hv_result.arr));
				ind_result = 0;
			}
DEBUGLOG(("AddError: %s = %.*s\n",csTag,hv_result.len,hv_result.arr));

			/* EXEC SQL EXECUTE
				BEGIN
					:hv_return_value := sp_ol_statement_tmp_error_ins(
								:hv_file_id:ind_file_id,
								:hv_seq:ind_seq,
								:hv_ver:ind_ver,
								:hv_result:ind_result,
								:hv_create_user:ind_create_user);
				END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 36;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_tmp_error_ins (\
 :hv_file_id:ind_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_result:ind\
_result , :hv_create_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )628;
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
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_seq;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ver;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_result;
   sqlstm.sqhstl[4] = (unsigned long )258;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_result;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[5] = (unsigned long )22;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto adderr_error;
}



DEBUGLOG(("AddError: return = [%d]\n",hv_return_value));

			if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_AddError: SP_OTHER_ERR\n");
DEBUGLOG(("AddError: SP_OTHER_ERR\n"));
				return PD_OTHER_ERR;
			}

			if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_AddError: SP_ERR\n");
DEBUGLOG(("AddError: SP_ERR\n"));
				return PD_ERR;
			}
		}
	}


	FREE_ME(csTag);

DEBUGLOG(("AddError:Normal Exit\n"));
	return PD_OK;

adderr_error:
DEBUGLOG(("adderr_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("AddError: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_AddError: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	return PD_INTERNAL_ERR;
}

/*
int AddSplit(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;

	EXEC SQL WHENEVER SQLERROR GOTO addetail_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar		hv_file_id[PD_TXN_SEQ_LEN];
		int		hv_seq;
		int		hv_ver;
		varchar		hv_statement_ref[PD_TXN_SEQ_LEN];
		varchar		hv_create_user[PD_USER_LEN];

		short		ind_file_id = -1;
		short		ind_seq = -1;
		short		ind_ver = -1;
		short		ind_statement_ref = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	EXEC SQL END DECLARE SECTION;

	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
		ind_file_id = 0;
DEBUGLOG(("AddSplit: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
	}

	if (GetField_Int(hRls, "seq", &iTmp)) {
		hv_seq = iTmp;
		ind_seq = 0;
DEBUGLOG(("AddSplit: seq = [%d]\n",hv_seq));
	}

	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("AddSplit: ver = [%d]\n",hv_ver));
	}

	if (GetField_CString(hRls,"statement_ref",&csTmp)) {
		hv_statement_ref.len = strlen(csTmp);
		strncpy((char*)hv_statement_ref.arr,csTmp,sizeof(hv_statement_ref.arr));
		ind_statement_ref = 0;
DEBUGLOG(("AddSplit: statement_ref = [%.*s](%d)\n",sizeof(hv_statement_ref.arr),hv_statement_ref.arr,hv_statement_ref.len));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr,csTmp,sizeof(hv_create_user.arr));
		ind_create_user = 0;
DEBUGLOG(("AddSplit: create_user = [%.*s](%d)\n",sizeof(hv_create_user.arr),hv_create_user.arr,hv_create_user.len));
	}

	EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_tmp_split_ins(
						:hv_file_id:ind_file_id,
						:hv_seq:ind_seq,
						:hv_ver:ind_ver,
						:hv_statement_ref:ind_statement_ref,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC;

	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddSplit: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_AddSplit: SP_OTHER_ERR\n");
DEBUGLOG(("AddSplit: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_AddSplit: SP_ERR\n");
DEBUGLOG(("AddSplit: SP_ERR\n"));
		return PD_ERR;
	}

addetail_error:
DEBUGLOG(("addetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	EXEC SQL WHENEVER SQLERROR CONTINUE;
DEBUGLOG(("AddSplit: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_AddSplit: SP_INTERNAL_ERR TxnAbort\n");
	TxnAbort();
	return PD_INTERNAL_ERR;
}
*/

int UpdateRecDetail(const hash_t *hRls)
{
        int     iTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updaterecdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                int             hv_seq;
                int             hv_ver;
                int             hv_latest_ver;
		int             hv_disabled;
                int             hv_sys_seq;
                int             hv_user_seq;
                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_latest_ver = -1;
		short           ind_disabled = -1;
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;
                short           ind_update_user = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        if (GetField_CString(hRls,"file_id",&csTmp)) {
                hv_file_id.len = strlen(csTmp);
                strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
                ind_file_id = 0;
DEBUGLOG(("UpdateRecDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
        }

//seq
        if (GetField_Int(hRls, "seq", &iTmp)) {
                hv_seq = iTmp;
                ind_seq = 0;
DEBUGLOG(("UpdateRecDetail: seq = [%d]\n",hv_seq));
        }

// ver
        if (GetField_Int(hRls, "ver", &iTmp)) {
                hv_ver = iTmp;
                ind_ver = 0;
DEBUGLOG(("UpdateRecDetail: ver = [%d]\n",hv_ver));
        }

// latest_ver
        if (GetField_Int(hRls, "latest_ver", &iTmp)) {
                hv_latest_ver = iTmp;
                ind_latest_ver = 0;
DEBUGLOG(("UpdateRecDetail: latest_ver = [%d]\n",hv_latest_ver));
        }

// disabled
        if (GetField_Int(hRls, "disabled", &iTmp)) {
                hv_disabled = iTmp;
                ind_disabled = 0;
DEBUGLOG(("UpdateRecDetail: disabled = [%d]\n",hv_disabled));
        }

// sys_seq
        if (GetField_Int(hRls, "sys_seq", &iTmp)) {
                hv_sys_seq = iTmp;
                ind_sys_seq = 0;
DEBUGLOG(("UpdateRecDetail: sys_seq = [%d]\n",hv_sys_seq));
        }

// user_seq
        if (GetField_Int(hRls, "user_seq", &iTmp)) {
                hv_user_seq = iTmp;
                ind_user_seq = 0;
DEBUGLOG(("UpdateRecDetail: user_seq = [%d]\n",hv_user_seq));
        }

// update_user
        if (GetField_CString(hRls,"update_user",&csTmp)) {
                hv_update_user.len = strlen(csTmp);
                strncpy((char*)hv_update_user.arr,csTmp,sizeof(hv_update_user.arr));
                ind_update_user = 0;
DEBUGLOG(("UpdateRecDetail: update_user = [%.*s](%d)\n",sizeof(hv_update_user.arr),hv_update_user.arr,hv_update_user.len));
        }

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_statement_tmp_recupd(
                                                :hv_file_id:ind_file_id,
                                                :hv_seq:ind_seq,
                                                :hv_ver:ind_ver,
                                                :hv_latest_ver:ind_latest_ver,
						:hv_disabled:ind_disabled,
                                                :hv_sys_seq:ind_sys_seq,
                                                :hv_user_seq:ind_user_seq,
						:hv_update_user:ind_update_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_tmp_recupd\
 ( :hv_file_id:ind_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_latest_v\
er:ind_latest_ver , :hv_disabled:ind_disabled , :hv_sys_seq:ind_sys_seq , :hv\
_user_seq:ind_user_seq , :hv_update_user:ind_update_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )667;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_seq;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ver;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_latest_ver;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_latest_ver;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_disabled;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_sys_seq;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_sys_seq;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_user_seq;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_user_seq;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_update_user;
        sqlstm.sqhstl[8] = (unsigned long )22;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_update_user;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto updaterecdetail_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateRecDetail: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_UpdateRecDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateRecDetail: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_UpdateRecDetail: SP_ERR\n");
DEBUGLOG(("UpdateRecDetail: SP_ERR\n"));
                return PD_ERR;
        }

updaterecdetail_error:
DEBUGLOG(("updaterecdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateRecDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_UpdateRecDetail: SP_INTERNAL_ERR TxnAbort\n");
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateUserTimestampDetail(const hash_t *hRls)
{
        int     iTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updateusertimestampdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                int             hv_seq;
                int             hv_ver;
                /* varchar         hv_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_create_user;

                /* varchar         hv_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_create_timestamp;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_create_user = -1;
                short           ind_create_timestamp = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        if (GetField_CString(hRls,"file_id",&csTmp)) {
                hv_file_id.len = strlen(csTmp);
                strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
                ind_file_id = 0;
DEBUGLOG(("UpdateUserTimestampDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
        }

//seq
        if (GetField_Int(hRls, "seq", &iTmp)) {
                hv_seq = iTmp;
                ind_seq = 0;
DEBUGLOG(("UpdateUserTimestampDetail: seq = [%d]\n",hv_seq));
        }

// ver
        if (GetField_Int(hRls, "ver", &iTmp)) {
                hv_ver = iTmp;
                ind_ver = 0;
DEBUGLOG(("UpdateUserTimestampDetail: ver = [%d]\n",hv_ver));
        }

// create_user
        if (GetField_CString(hRls,"create_user",&csTmp)) {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr,csTmp,sizeof(hv_create_user.arr));
                ind_create_user = 0;
DEBUGLOG(("UpdateUserTimestampDetail: create_user = [%.*s](%d)\n",sizeof(hv_create_user.arr),hv_create_user.arr,hv_create_user.len));
        }

// create_timestamp
        if (GetField_CString(hRls,"create_timestamp",&csTmp)) {
                hv_create_timestamp.len = strlen(csTmp);
                strncpy((char*)hv_create_timestamp.arr,csTmp,sizeof(hv_create_timestamp.arr));
                ind_create_timestamp = 0;
DEBUGLOG(("UpdateUserTimestampDetail: create_timestamp = [%.*s](%d)\n",sizeof(hv_create_timestamp.arr),hv_create_timestamp.arr,hv_create_timestamp.len));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_statement_tmp_utsupd(
                                                :hv_file_id:ind_file_id,
                                                :hv_seq:ind_seq,
                                                :hv_ver:ind_ver,
                                                :hv_create_user:ind_create_user,
                                                :hv_create_timestamp:ind_create_timestamp);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_tmp_utsupd ( :hv_\
file_id:ind_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_create_user:ind\
_create_user , :hv_create_timestamp:ind_create_timestamp ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )718;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ver;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[4] = (unsigned long )23;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_create_user;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_timestamp;
 sqlstm.sqhstl[5] = (unsigned long )23;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_create_timestamp;
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
 if (sqlca.sqlcode < 0) goto updateusertimestampdetail_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateUserTimestampDetail: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_UpdateUserTimestampDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateUserTimestampDetail: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_UpdateUserTimestampDetail: SP_ERR\n");
DEBUGLOG(("UpdateUserTimestampDetail: SP_ERR\n"));
                return PD_ERR;
        }

updateusertimestampdetail_error:
DEBUGLOG(("updateusertimestampdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateUserTimestampDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_UpdateUserTimestampDetail: SP_INTERNAL_ERR TxnAbort\n");
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateSeqDetail(const hash_t *hRls)
{
        int     iTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updateseqdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                int             hv_seq;
                int             hv_ver;
                int         	hv_sys_seq;
                int         	hv_user_seq;

                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        if (GetField_CString(hRls,"file_id",&csTmp)) {
                hv_file_id.len = strlen(csTmp);
                strncpy((char*)hv_file_id.arr,csTmp,sizeof(hv_file_id.arr));
                ind_file_id = 0;
DEBUGLOG(("UpdateSeqDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
        }

// seq
        if (GetField_Int(hRls, "seq", &iTmp)) {
                hv_seq = iTmp;
                ind_seq = 0;
DEBUGLOG(("UpdateSeqDetail: seq = [%d]\n",hv_seq));
        }

// ver
        if (GetField_Int(hRls, "ver", &iTmp)) {
                hv_ver = iTmp;
                ind_ver = 0;
DEBUGLOG(("UpdateSeqDetail: ver = [%d]\n",hv_ver));
        }

// sys_seq
        if (GetField_Int(hRls, "sys_seq", &iTmp)) {
                hv_sys_seq = iTmp;
                ind_sys_seq = 0;
DEBUGLOG(("UpdateSeqDetail: sys_seq = [%d]\n",hv_sys_seq));
        }

// user_seq
        if (GetField_Int(hRls, "user_seq", &iTmp)) {
                hv_user_seq = iTmp;
                ind_user_seq = 0;
DEBUGLOG(("UpdateSeqDetail: user_seq = [%d]\n",hv_user_seq));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_statement_tmp_sequpd(
                                                :hv_file_id:ind_file_id,
                                                :hv_seq:ind_seq,
                                                :hv_ver:ind_ver,
                                                :hv_sys_seq:ind_sys_seq,
                                                :hv_user_seq:ind_user_seq);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_tmp_sequpd ( :hv_\
file_id:ind_file_id , :hv_seq:ind_seq , :hv_ver:ind_ver , :hv_sys_seq:ind_sys\
_seq , :hv_user_seq:ind_user_seq ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )757;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ver;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_sys_seq;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_sys_seq;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_user_seq;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_user_seq;
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
 if (sqlca.sqlcode < 0) goto updateseqdetail_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateSeqDetail: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatementTmp_UpdateSeqDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateSeqDetail: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OLStatementTmp_UpdateSeqDetail: SP_ERR\n");
DEBUGLOG(("UpdateSeqDetail: SP_ERR\n"));
                return PD_ERR;
        }

updateseqdetail_error:
DEBUGLOG(("updateseqdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateSeqDetail: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatementTmp_UpdateSeqDetail: SP_INTERNAL_ERR TxnAbort\n");
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int GetFirstSeqRecDetail(const char* csFileId, hash_t* hRec)
{
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getfirstseqrecdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


                /* varchar         v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                int             v_seq;
                int             v_ver;
                int             v_latest_ver;
		int             v_disabled;
                int             v_sys_seq;
                int             v_user_seq;
		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;

                /* varchar         v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_latest_ver = -1;
		short           ind_disabled = -1;
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;
		short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
                short           ind_create_user = -1;
                short           ind_create_timestamp = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
DEBUGLOG(("GetFirstSeqRecDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

	/* EXEC SQL DECLARE c_cursor_getfirstseqrecdetail CURSOR FOR
                SELECT  OLST_FILE_ID,
                        OLST_SEQ,
                        OLST_VER,
                        OLST_LATEST_VER,
			OLST_DISABLED,
                        OLST_SYS_SEQ,
                        OLST_USER_SEQ,
			OLST_INT_BANK_CODE,
                        OLST_BANK_ACCT_NUM,
                        OLST_CREATE_USER,
			//OLST_CREATE_TIMESTAMP
			TO_CHAR(OLST_CREATE_TIMESTAMP,'YYYYMMDD HH24MISS')
			//TO_CHAR(OLST_CREATE_TIMESTAMP,'MM/DD/YYYY HH12:MI:SS AM')
                FROM    OL_STATEMENT_TMP
                WHERE   OLST_FILE_ID = :hv_file_id
		AND     OLST_DISABLED >= 0
                ORDER BY OLST_SEQ ASC,
                         OLST_VER ASC; */ 


        /* EXEC SQL OPEN c_cursor_getfirstseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0011;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )796;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto getfirstseqrecdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getfirstseqrecdetail
                INTO    :v_file_id:ind_file_id,
                        :v_seq:ind_seq,
                        :v_ver:ind_ver,
                        :v_latest_ver:ind_latest_ver,
			:v_disabled:ind_disabled,
                        :v_sys_seq:ind_sys_seq,
                        :v_user_seq:ind_user_seq,
			:v_int_bank_code:ind_int_bank_code,
                        :v_bank_acct_num:ind_bank_acct_num,
                        :v_create_user:ind_create_user,
                        :v_create_timestamp:ind_create_timestamp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 36;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )815;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ver;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ver;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_latest_ver;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_latest_ver;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_disabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_sys_seq;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_sys_seq;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_user_seq;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user_seq;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_create_user;
                sqlstm.sqhstl[9] = (unsigned long )23;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_create_user;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[10] = (unsigned long )23;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_create_timestamp;
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
                if (sqlca.sqlcode < 0) goto getfirstseqrecdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;

// file_id
                if (ind_file_id >= 0) {
                        v_file_id.arr[v_file_id.len] = '\0';
                        PutField_CString(hRec, "file_id", (char*)v_file_id.arr);
DEBUGLOG(("GetFirstSeqRecDetail file_id = [%s]\n", (char*)v_file_id.arr));
                }

// seq
                if (ind_seq >= 0) {
                        PutField_Int(hRec, "seq", v_seq);
DEBUGLOG(("GetFirstSeqRecDetail seq = [%d]\n", v_seq));
                }

// ver
                if (ind_ver >= 0) {
                        PutField_Int(hRec, "ver", v_ver);
DEBUGLOG(("GetFirstSeqRecDetail ver = [%d]\n", v_ver));
                }

// latest_ver
                if (ind_latest_ver >= 0) {
                        PutField_Int(hRec, "latest_ver", v_latest_ver);
DEBUGLOG(("GetFirstSeqRecDetail latest_ver = [%d]\n", v_latest_ver));
                }

// disabled
                if (ind_disabled >= 0) {
                        PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("GetFirstSeqRecDetail disabled = [%d]\n", v_disabled));
                }

// sys_seq
                if (ind_sys_seq >= 0) {
                        PutField_Int(hRec, "sys_seq", v_sys_seq);
DEBUGLOG(("GetFirstSeqRecDetail sys_seq = [%d]\n", v_sys_seq));
                }

// user_seq
                if (ind_user_seq >= 0) {
                        PutField_Int(hRec, "user_seq", v_user_seq);
DEBUGLOG(("GetFirstSeqRecDetail user_seq = [%d]\n", v_user_seq));
                }

// int_bank_code
                if (ind_int_bank_code >= 0) {
                        v_int_bank_code.arr[v_int_bank_code.len] = '\0';
                        PutField_CString(hRec, "int_bank_code", (char*)v_int_bank_code.arr);
DEBUGLOG(("GetFirstSeqRecDetail int_bank_code = [%s]\n", (char*)v_int_bank_code.arr));
                }

// bank_acct_num
                if (ind_bank_acct_num >= 0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        PutField_CString(hRec, "bank_acct_num", (char*)v_bank_acct_num.arr);
DEBUGLOG(("GetFirstSeqRecDetail bank_acct_num = [%s]\n", (char*)v_bank_acct_num.arr));
                }

// create_user
                if (ind_create_user >= 0) {
                        v_create_user.arr[v_create_user.len] = '\0';
                        PutField_CString(hRec, "create_user", (char*)v_create_user.arr);
DEBUGLOG(("GetFirstSeqRecDetail create_user = [%s]\n", (char*)v_create_user.arr));
                }

// create_timestamp
                if (ind_create_timestamp >= 0) {
                        v_create_timestamp.arr[v_create_timestamp.len] = '\0';
                        PutField_CString(hRec, "create_timestamp", (char*)v_create_timestamp.arr);
DEBUGLOG(("GetFirstSeqRecDetail create_timestamp = [%s]\n", (char*)v_create_timestamp.arr));
                }
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getfirstseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )874;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getfirstseqrecdetail_error;
}



        if (iCnt >= 0 ) {
DEBUGLOG(("GetFirstSeqRecDetail Normal Exit\n"));
                return  PD_OK;
        }

getfirstseqrecdetail_error:
DEBUGLOG(("getfirstseqrecdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatementTmp getfirstseqrecdetail_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getfirstseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )889;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetFirstVerRecDetail(const char* csFileId, int iSeq, hash_t* hRec)
{
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getfirstverrecdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                int             hv_seq;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                int             v_seq;
                int             v_ver;
                int             v_latest_ver;
		int             v_disabled;
                int             v_sys_seq;
                int             v_user_seq;
                /* varchar         v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;

                /* varchar         v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_latest_ver = -1;
		short           ind_disabled = -1;
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;
                short           ind_create_user = -1;
                short           ind_create_timestamp = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
DEBUGLOG(("GetFirstVerRecDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

// seq
        hv_seq = iSeq;
DEBUGLOG(("GetFirstVerRecDetail: seq = [%d]\n", hv_seq));
	
/* EXEC SQL DECLARE c_cursor_getfirstverrecdetail CURSOR FOR
                SELECT  OLST_FILE_ID,
                        OLST_SEQ,
                        OLST_VER,
                        OLST_LATEST_VER,
			OLST_DISABLED,
                        OLST_SYS_SEQ,
                        OLST_USER_SEQ,
                        OLST_CREATE_USER,
                        //OLST_CREATE_TIMESTAMP
                        TO_CHAR(OLST_CREATE_TIMESTAMP,'YYYYMMDD HH24MISS')
                FROM    OL_STATEMENT_TMP
                WHERE   OLST_FILE_ID = :hv_file_id
                AND     OLST_SEQ = :hv_seq
                AND     OLST_LATEST_VER IS NULL
                AND     OLST_DISABLED >= 0
                ORDER BY OLST_VER ASC; */ 


        /* EXEC SQL OPEN c_cursor_getfirstverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0012;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )904;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getfirstverrecdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getfirstverrecdetail
                INTO    :v_file_id:ind_file_id,
                        :v_seq:ind_seq,
                        :v_ver:ind_ver,
                        :v_latest_ver:ind_latest_ver,
			:v_disabled:ind_disabled,
                        :v_sys_seq:ind_sys_seq,
                        :v_user_seq:ind_user_seq,
                        :v_create_user:ind_create_user,
                        :v_create_timestamp:ind_create_timestamp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 36;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )927;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ver;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ver;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_latest_ver;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_latest_ver;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_disabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_sys_seq;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_sys_seq;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_user_seq;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user_seq;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_create_user;
                sqlstm.sqhstl[7] = (unsigned long )23;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_create_user;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[8] = (unsigned long )23;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_create_timestamp;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getfirstverrecdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;

// file_id
                if (ind_file_id >= 0) {
                        v_file_id.arr[v_file_id.len] = '\0';
                        PutField_CString(hRec, "file_id", (char*)v_file_id.arr);
DEBUGLOG(("GetFirstVerRecDetail file_id = [%s]\n", (char*)v_file_id.arr));
                }

// seq
                if (ind_seq >= 0) {
                        PutField_Int(hRec, "seq", v_seq);
DEBUGLOG(("GetFirstVerRecDetail seq = [%d]\n", v_seq));
                }

// ver
                if (ind_ver >= 0) {
                        PutField_Int(hRec, "ver", v_ver);
DEBUGLOG(("GetFirstVerRecDetail ver = [%d]\n", v_ver));
                }

// latest_ver
                if (ind_latest_ver >= 0) {
                        PutField_Int(hRec, "latest_ver", v_latest_ver);
DEBUGLOG(("GetFirstVerRecDetail latest_ver = [%d]\n", v_latest_ver));
                }

// disabled
                if (ind_disabled >= 0) {
                        PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("GetFirstVerRecDetail disabled = [%d]\n", v_disabled));
                }

// sys_seq
                if (ind_sys_seq >= 0) {
                        PutField_Int(hRec, "sys_seq", v_sys_seq);
DEBUGLOG(("GetFirstVerRecDetail sys_seq = [%d]\n", v_sys_seq));
                }

// user_seq
                if (ind_user_seq >= 0) {
                        PutField_Int(hRec, "user_seq", v_user_seq);
DEBUGLOG(("GetFirstVerRecDetail user_seq = [%d]\n", v_user_seq));
                }

// create_user
                if (ind_create_user >= 0) {
                        v_create_user.arr[v_create_user.len] = '\0';
                        PutField_CString(hRec, "create_user", (char*)v_create_user.arr);
DEBUGLOG(("GetFirstVerRecDetail create_user = [%s]\n", (char*)v_create_user.arr));
                }

// create_timestamp
                if (ind_create_timestamp >= 0) {
                        v_create_timestamp.arr[v_create_timestamp.len] = '\0';
                        PutField_CString(hRec, "create_timestamp", (char*)v_create_timestamp.arr);
DEBUGLOG(("GetFirstVerRecDetail create_timestamp = [%s]\n", (char*)v_create_timestamp.arr));
                }
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getfirstverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )978;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getfirstverrecdetail_error;
}



        if (iCnt >= 0 ) {
DEBUGLOG(("GetFirstVerRecDetail Normal Exit\n"));
                return  PD_OK;
        }

getfirstverrecdetail_error:
DEBUGLOG(("getfirstverrecdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatementTmp getfirstverrecdetail_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getfirstverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )993;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetLastSeqRecDetail(const char* csFileId, hash_t* hRec)
{
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlastseqrecdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


                /* varchar         v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                int             v_seq;
                int             v_ver;
                int             v_latest_ver;
		int             v_disabled;
                int             v_sys_seq;
                int             v_user_seq;
		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;

                /* varchar         v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_latest_ver = -1;
		short           ind_disabled = -1;
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;
                short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
                short           ind_create_user = -1;
                short           ind_create_timestamp = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
DEBUGLOG(("GetLastSeqRecDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

/* EXEC SQL DECLARE c_cursor_getlastseqrecdetail CURSOR FOR
                SELECT  OLST_FILE_ID,
                        OLST_SEQ,
                        OLST_VER,
                        OLST_LATEST_VER,
			OLST_DISABLED,
                        OLST_SYS_SEQ,
                        OLST_USER_SEQ,
			OLST_INT_BANK_CODE,
			OLST_BANK_ACCT_NUM,
                        OLST_CREATE_USER,
                        //OLST_CREATE_TIMESTAMP
			TO_CHAR(OLST_CREATE_TIMESTAMP,'YYYYMMDD HH24MISS')
                FROM    OL_STATEMENT_TMP
                WHERE   OLST_FILE_ID = :hv_file_id
                AND     OLST_LATEST_VER IS NULL
                AND     OLST_DISABLED >= 0
                ORDER BY OLST_SEQ DESC,
                         OLST_VER DESC; */ 


        /* EXEC SQL OPEN c_cursor_getlastseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0013;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1008;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto getlastseqrecdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getlastseqrecdetail
                INTO    :v_file_id:ind_file_id,
                        :v_seq:ind_seq,
                        :v_ver:ind_ver,
                        :v_latest_ver:ind_latest_ver,
			:v_disabled:ind_disabled,
                        :v_sys_seq:ind_sys_seq,
                        :v_user_seq:ind_user_seq,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
                        :v_create_user:ind_create_user,
                        :v_create_timestamp:ind_create_timestamp; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 36;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1027;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ver;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ver;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_latest_ver;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_latest_ver;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_disabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_sys_seq;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_sys_seq;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_user_seq;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user_seq;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[7] = (unsigned long )13;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[8] = (unsigned long )53;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_create_user;
                sqlstm.sqhstl[9] = (unsigned long )23;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_create_user;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[10] = (unsigned long )23;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_create_timestamp;
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
                if (sqlca.sqlcode < 0) goto getlastseqrecdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }      

                iCnt++;

// file_id
                if (ind_file_id >= 0) {
                        v_file_id.arr[v_file_id.len] = '\0';
                        PutField_CString(hRec, "file_id", (char*)v_file_id.arr);
DEBUGLOG(("GetLastSeqRecDetail file_id = [%s]\n", (char*)v_file_id.arr));
                }

// seq
                if (ind_seq >= 0) {
                        PutField_Int(hRec, "seq", v_seq);
DEBUGLOG(("GetLastSeqRecDetail seq = [%d]\n", v_seq));
                }

// ver
                if (ind_ver >= 0) {
                        PutField_Int(hRec, "ver", v_ver);
DEBUGLOG(("GetLastSeqRecDetail ver = [%d]\n", v_ver));
                }

// latest_ver
                if (ind_latest_ver >= 0) {
                        PutField_Int(hRec, "latest_ver", v_latest_ver);
DEBUGLOG(("GetLastSeqRecDetail latest_ver = [%d]\n", v_latest_ver));
                }

// disabled
                if (ind_disabled >= 0) {
                        PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("GetLastSeqRecDetail disabled = [%d]\n", v_disabled));
                }

// sys_seq
                if (ind_sys_seq >= 0) {
                        PutField_Int(hRec, "sys_seq", v_sys_seq);
DEBUGLOG(("GetLastSeqRecDetail sys_seq = [%d]\n", v_sys_seq));
                }

// user_seq
                if (ind_user_seq >= 0) {
                        PutField_Int(hRec, "user_seq", v_user_seq);
DEBUGLOG(("GetLastSeqRecDetail user_seq = [%d]\n", v_user_seq));
                }

// int_bank_code
                if (ind_int_bank_code >= 0) {
                        v_int_bank_code.arr[v_int_bank_code.len] = '\0';
                        PutField_CString(hRec, "int_bank_code", (char*)v_int_bank_code.arr);
DEBUGLOG(("GetLastSeqRecDetail int_bank_code = [%s]\n", (char*)v_int_bank_code.arr));
                }

// bank_acct_num
                if (ind_bank_acct_num >= 0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        PutField_CString(hRec, "bank_acct_num", (char*)v_bank_acct_num.arr);
DEBUGLOG(("GetLastSeqRecDetail bank_acct_num = [%s]\n", (char*)v_bank_acct_num.arr));
                }

// create_user
                if (ind_create_user >= 0) {
                        v_create_user.arr[v_create_user.len] = '\0';
                        PutField_CString(hRec, "create_user", (char*)v_create_user.arr);
DEBUGLOG(("GetLastSeqRecDetail create_user = [%s]\n", (char*)v_create_user.arr));
                }

// create_timestamp
                if (ind_create_timestamp >= 0) {
                        v_create_timestamp.arr[v_create_timestamp.len] = '\0';
                        PutField_CString(hRec, "create_timestamp", (char*)v_create_timestamp.arr);
DEBUGLOG(("GetLastSeqRecDetail create_timestamp = [%s]\n", (char*)v_create_timestamp.arr));
                }
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getlastseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1086;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastseqrecdetail_error;
}



        if (iCnt >= 0 ) {
DEBUGLOG(("GetLastSeqRecDetail Normal Exit\n"));
                return  PD_OK;
        }

getlastseqrecdetail_error:
DEBUGLOG(("getlastseqrecdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatementTmp getlastseqrecdetail_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getlastseqrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1101;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetLastVerRecDetail(const char* csFileId, int iSeq, hash_t* hRec)
{
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getlastverrecdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                int             hv_seq;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                int             v_seq;
                int             v_ver;
                int             v_latest_ver;
		int		v_disabled;
                int             v_sys_seq;
                int             v_user_seq;
		int             v_skip;
		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_raw_date[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_raw_date;

		/* varchar         v_raw_time[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_raw_time;

		/* varchar		v_statement_date[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_statement_date;

		/* varchar		v_statement_time[PD_TMP_BUF_LEN  + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_statement_time;

		/* varchar		v_tfr_bank_name[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_bank_name;

		/* varchar		v_tfr_bank_acct_num[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_bank_acct_num;

		/* varchar		v_tfr_channel[PD_TFR_CHANNEL_LONG_LEN  + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_channel;

		/* varchar		v_tfr_type[PD_TFR_TYPE_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_type;

		/* varchar		v_tfr_text[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_tfr_text;

		/* varchar		v_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_customer_text;

		/* varchar		v_sender_name[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_sender_name;

		/* varchar		v_txn_ref_num[PD_STMT_TMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[513]; } v_txn_ref_num;

		/* varchar		v_amt_type[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_amt_type;

		/* varchar		v_txn_amount[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_txn_amount;

		/* varchar		v_bank_charge[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_bank_charge;

		/* varchar		v_balance[PD_TMP_BUF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_balance;

		/* varchar		v_sender_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_sender_baid_name;

		/* varchar		v_recipient_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_recipient_baid_name;

		/* varchar		v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

                /* varchar         v_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_user;

                /* varchar         v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar		v_txn_location[PD_TXN_LOCATION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_location;

		/* varchar		v_txn_type[PD_TXN_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_type;

		/* varchar		v_txn_reference[PD_TXN_REFERENCE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_txn_reference;


                short           ind_file_id = -1;
                short           ind_seq = -1;
                short           ind_ver = -1;
                short           ind_latest_ver = -1;
                short           ind_disabled = -1;	
                short           ind_sys_seq = -1;
                short           ind_user_seq = -1;
                short           ind_skip = -1;
		short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
		short           ind_raw_date = -1;
                short           ind_raw_time = -1;
		short         	ind_statement_date = -1;
                short 	        ind_statement_time = -1;
                short	        ind_tfr_bank_name = -1;
                short         	ind_tfr_bank_acct_num = -1;
                short           ind_tfr_channel = -1;
                short         	ind_tfr_type = -1;
                short         	ind_tfr_text = -1;
                short         	ind_tfr_customer_text = -1;
                short         	ind_sender_name = -1;
                short         	ind_txn_ref_num = -1;
                short         	ind_amt_type = -1;
                short         	ind_txn_amount = -1;
                short         	ind_bank_charge = -1;
                short         	ind_balance = -1;
                short         	ind_sender_baid_name = -1;
                short         	ind_recipient_baid_name = -1;
                short         	ind_client_name = -1;
                short           ind_create_user = -1;
                short           ind_create_timestamp = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
DEBUGLOG(("GetLastVerRecDetail: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

// seq
        hv_seq = iSeq;
DEBUGLOG(("GetLastVerRecDetail: seq = [%d]\n", hv_seq));

/* EXEC SQL DECLARE c_cursor_getlastverrecdetail CURSOR FOR
                SELECT  OLST_FILE_ID,
                        OLST_SEQ,
                        OLST_VER,
                        OLST_LATEST_VER,
			OLST_DISABLED,
                        OLST_SYS_SEQ,
                        OLST_USER_SEQ,
                        OLST_SKIP,
			OLST_INT_BANK_CODE,
			OLST_BANK_ACCT_NUM,
			OLST_RAW_DATE,
			OLST_RAW_TIME,
			OLST_STATEMENT_DATE,
			OLST_STATEMENT_TIME,
			OLST_TFR_BANK_NAME,
			OLST_TFR_BANK_ACCT_NUM,
			OLST_TFR_TYPE,
			OLST_TFR_CHANNEL,
			OLST_TFR_TEXT,
			OLST_TFR_CUSTOMER_TEXT,
			OLST_SENDER_NAME,
			OLST_TXN_REF_NUM,
			OLST_BALANCE,
			OLST_AMT_TYPE,
			OLST_TXN_AMOUNT,
			OLST_BANK_CHARGE,
			OLST_SENDER_BAID_NAME,
			OLST_RECIPIENT_BAID_NAME,
			OLST_CLIENT_NAME,
                        OLST_CREATE_USER,
                        //OLST_CREATE_TIMESTAMP
			TO_CHAR(OLST_CREATE_TIMESTAMP,'YYYYMMDD HH24MISS'),
			OLST_TXN_LOCATION,
			OLST_TXN_TYPE,
			OLST_TXN_REFERENCE
                FROM    OL_STATEMENT_TMP
                WHERE   OLST_FILE_ID = :hv_file_id
                AND     OLST_SEQ = :hv_seq
                AND     OLST_LATEST_VER IS NULL
                AND     OLST_DISABLED >= 0
                ORDER BY OLST_VER DESC; */ 


        /* EXEC SQL OPEN c_cursor_getlastverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0014;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1116;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getlastverrecdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getlastverrecdetail
                INTO    :v_file_id:ind_file_id,
                        :v_seq:ind_seq,
                        :v_ver:ind_ver,
                        :v_latest_ver:ind_latest_ver,
                        :v_disabled:ind_disabled,
                        :v_sys_seq:ind_sys_seq,
                        :v_user_seq:ind_user_seq,
                       	:v_skip:ind_skip,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_raw_date:ind_raw_date,
			:v_raw_time:ind_raw_time,
			:v_statement_date:ind_statement_date,
			:v_statement_time:ind_statement_time,
			:v_tfr_bank_name:ind_tfr_bank_name,
			:v_tfr_bank_acct_num:ind_tfr_bank_acct_num,
			:v_tfr_type:ind_tfr_type,
			:v_tfr_channel:ind_tfr_channel,
			:v_tfr_text:ind_tfr_text,
			:v_tfr_customer_text:ind_tfr_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_balance:ind_balance,
			:v_amt_type:ind_amt_type,
			:v_txn_amount:ind_txn_amount,
			:v_bank_charge:ind_bank_charge,
			:v_sender_baid_name:ind_sender_baid_name,
			:v_recipient_baid_name:ind_recipient_baid_name,
			:v_client_name:ind_client_name,
                        :v_create_user:ind_create_user,
                        :v_create_timestamp:ind_create_timestamp,
			:v_txn_location:ind_txn_location,
			:v_txn_type:ind_txn_type,
			:v_txn_reference:ind_txn_reference; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 36;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1139;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ver;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ver;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_latest_ver;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_latest_ver;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_disabled;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_disabled;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_sys_seq;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_sys_seq;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_user_seq;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_user_seq;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_skip;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_skip;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[8] = (unsigned long )13;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[9] = (unsigned long )53;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_raw_date;
                sqlstm.sqhstl[10] = (unsigned long )259;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_raw_date;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_raw_time;
                sqlstm.sqhstl[11] = (unsigned long )259;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_raw_time;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_statement_date;
                sqlstm.sqhstl[12] = (unsigned long )259;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_statement_date;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_statement_time;
                sqlstm.sqhstl[13] = (unsigned long )259;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_statement_time;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_tfr_bank_name;
                sqlstm.sqhstl[14] = (unsigned long )515;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_tfr_bank_name;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_tfr_bank_acct_num;
                sqlstm.sqhstl[15] = (unsigned long )515;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_tfr_bank_acct_num;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_tfr_type;
                sqlstm.sqhstl[16] = (unsigned long )643;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_tfr_type;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_tfr_channel;
                sqlstm.sqhstl[17] = (unsigned long )643;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_tfr_channel;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_tfr_text;
                sqlstm.sqhstl[18] = (unsigned long )515;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_tfr_text;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_tfr_customer_text;
                sqlstm.sqhstl[19] = (unsigned long )643;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_tfr_customer_text;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_sender_name;
                sqlstm.sqhstl[20] = (unsigned long )515;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_sender_name;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_txn_ref_num;
                sqlstm.sqhstl[21] = (unsigned long )515;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_txn_ref_num;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_balance;
                sqlstm.sqhstl[22] = (unsigned long )259;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_balance;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_amt_type;
                sqlstm.sqhstl[23] = (unsigned long )259;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_amt_type;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_txn_amount;
                sqlstm.sqhstl[24] = (unsigned long )259;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_txn_amount;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_bank_charge;
                sqlstm.sqhstl[25] = (unsigned long )259;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_bank_charge;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_sender_baid_name;
                sqlstm.sqhstl[26] = (unsigned long )153;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_sender_baid_name;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_recipient_baid_name;
                sqlstm.sqhstl[27] = (unsigned long )153;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_recipient_baid_name;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_client_name;
                sqlstm.sqhstl[28] = (unsigned long )53;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_client_name;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_create_user;
                sqlstm.sqhstl[29] = (unsigned long )23;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_create_user;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_create_timestamp;
                sqlstm.sqhstl[30] = (unsigned long )23;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_create_timestamp;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_txn_location;
                sqlstm.sqhstl[31] = (unsigned long )643;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_txn_location;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
                sqlstm.sqhstv[32] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[32] = (unsigned long )643;
                sqlstm.sqhsts[32] = (         int  )0;
                sqlstm.sqindv[32] = (         short *)&ind_txn_type;
                sqlstm.sqinds[32] = (         int  )0;
                sqlstm.sqharm[32] = (unsigned long )0;
                sqlstm.sqadto[32] = (unsigned short )0;
                sqlstm.sqtdso[32] = (unsigned short )0;
                sqlstm.sqhstv[33] = (unsigned char  *)&v_txn_reference;
                sqlstm.sqhstl[33] = (unsigned long )643;
                sqlstm.sqhsts[33] = (         int  )0;
                sqlstm.sqindv[33] = (         short *)&ind_txn_reference;
                sqlstm.sqinds[33] = (         int  )0;
                sqlstm.sqharm[33] = (unsigned long )0;
                sqlstm.sqadto[33] = (unsigned short )0;
                sqlstm.sqtdso[33] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getlastverrecdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (iCnt >= 1) {
                        break;
                }

                iCnt++;

// file_id
                if (ind_file_id >= 0) {
                        v_file_id.arr[v_file_id.len] = '\0';
                        PutField_CString(hRec, "file_id", (char*)v_file_id.arr);
DEBUGLOG(("GetLastVerRecDetail file_id = [%s]\n", (char*)v_file_id.arr));
                }

// seq
                if (ind_seq >= 0) {
                        PutField_Int(hRec, "seq", v_seq);
DEBUGLOG(("GetLastVerRecDetail seq = [%d]\n", v_seq));
                }

// ver
                if (ind_ver >= 0) {
                        PutField_Int(hRec, "ver", v_ver);
DEBUGLOG(("GetLastVerRecDetail ver = [%d]\n", v_ver));
                }

// latest_ver
                if (ind_latest_ver >= 0) {
                        PutField_Int(hRec, "latest_ver", v_latest_ver);
DEBUGLOG(("GetLastVerRecDetail latest_ver = [%d]\n", v_latest_ver));
                }

// disabled
                if (ind_disabled >= 0) {
                        PutField_Int(hRec, "disabled", v_disabled);
DEBUGLOG(("GetLastVerRecDetail disabled = [%d]\n", v_disabled));
                }

// sys_seq
                if (ind_sys_seq >= 0) {
                        PutField_Int(hRec, "sys_seq", v_sys_seq);
DEBUGLOG(("GetLastVerRecDetail sys_seq = [%d]\n", v_sys_seq));
                }

// user_seq
                if (ind_user_seq >= 0) {
                        PutField_Int(hRec, "user_seq", v_user_seq);
DEBUGLOG(("GetLastVerRecDetail user_seq = [%d]\n", v_user_seq));
                }

// skip
                if (ind_skip >= 0) {
                        PutField_Int(hRec, "skip", v_skip);
DEBUGLOG(("GetLastVerRecDetail skip = [%d]\n", v_skip));
                }

// int_bank_code
                if (ind_int_bank_code >= 0) {
                        v_int_bank_code.arr[v_int_bank_code.len] = '\0';
                        PutField_CString(hRec, "int_bank_code", (char*)v_int_bank_code.arr);
DEBUGLOG(("GetLastVerRecDetail int_bank_code = [%s]\n", (char*)v_int_bank_code.arr));
                }

// bank_acct_num
                if (ind_bank_acct_num >= 0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        PutField_CString(hRec, "bank_acct_num", (char*)v_bank_acct_num.arr);
DEBUGLOG(("GetLastVerRecDetail bank_acct_num = [%s]\n", (char*)v_bank_acct_num.arr));
                }

// raw_date
                if (ind_raw_date >= 0) {
                        v_raw_date.arr[v_raw_date.len] = '\0';
                        PutField_CString(hRec, "raw_date", (char*)v_raw_date.arr);
DEBUGLOG(("GetLastVerRecDetail raw_date = [%s]\n", (char*)v_raw_date.arr));
                }

// raw_time
                if (ind_raw_time >= 0) {
                        v_raw_time.arr[v_raw_time.len] = '\0';
                        PutField_CString(hRec, "raw_time", (char*)v_raw_time.arr);
DEBUGLOG(("GetLastVerRecDetail raw_time = [%s]\n", (char*)v_raw_time.arr));
                }

// statement_date
                if (ind_statement_date >= 0) {
                        v_statement_date.arr[v_statement_date.len] = '\0';
                        PutField_CString(hRec, "statement_date", (char*)v_statement_date.arr);
DEBUGLOG(("GetLastVerRecDetail statement_date = [%s]\n", (char*)v_statement_date.arr));
                }

// statement_time
                if (ind_statement_time >= 0) {
                        v_statement_time.arr[v_statement_time.len] = '\0';
                        PutField_CString(hRec, "statement_time", (char*)v_statement_time.arr);
DEBUGLOG(("GetLastVerRecDetail statement_time = [%s]\n", (char*)v_statement_time.arr));
                }

// tfr_bank_name
                if (ind_tfr_bank_name >= 0) {
                        v_tfr_bank_name.arr[v_tfr_bank_name.len] = '\0';
                        PutField_CString(hRec, "tfr_bank_name", (char*)v_tfr_bank_name.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_bank_name = [%s]\n", (char*)v_tfr_bank_name.arr));
                }

// tfr_bank_acct_num
                if (ind_tfr_bank_acct_num >= 0) {
                        v_tfr_bank_acct_num.arr[v_tfr_bank_acct_num.len] = '\0';
                        PutField_CString(hRec, "tfr_bank_acct_num", (char*)v_tfr_bank_acct_num.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_bank_acct_num = [%s]\n", (char*)v_tfr_bank_acct_num.arr));
                }

// tfr_channel
                if (ind_tfr_channel >= 0) {
                        v_tfr_channel.arr[v_tfr_channel.len] = '\0';
                        PutField_CString(hRec, "tfr_channel", (char*)v_tfr_channel.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_channel = [%s]\n", (char*)v_tfr_channel.arr));
                }

// tfr_type
                if (ind_tfr_type >= 0) {
                        v_tfr_type.arr[v_tfr_type.len] = '\0';
                        PutField_CString(hRec, "tfr_type", (char*)v_tfr_type.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_type = [%s]\n", (char*)v_tfr_type.arr));
                }

// tfr_text
                if (ind_tfr_text >= 0) {
                        v_tfr_text.arr[v_tfr_text.len] = '\0';
                        PutField_CString(hRec, "tfr_text", (char*)v_tfr_text.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_text = [%s]\n", (char*)v_tfr_text.arr));
                }

// tfr_customer_text
                if (ind_tfr_customer_text >= 0) {
                        v_tfr_customer_text.arr[v_tfr_customer_text.len] = '\0';
                        PutField_CString(hRec, "tfr_customer_text", (char*)v_tfr_customer_text.arr);
DEBUGLOG(("GetLastVerRecDetail tfr_customer_text = [%s]\n", (char*)v_tfr_customer_text.arr));
                }

// sender_name
                if (ind_sender_name >= 0) {
                        v_sender_name.arr[v_sender_name.len] = '\0';
                        PutField_CString(hRec, "sender_name", (char*)v_sender_name.arr);
DEBUGLOG(("GetLastVerRecDetail sender_name = [%s]\n", (char*)v_sender_name.arr));
                }

// txn_ref_num
                if (ind_txn_ref_num >= 0) {
                        v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
                        PutField_CString(hRec, "txn_ref_num", (char*)v_txn_ref_num.arr);
DEBUGLOG(("GetLastVerRecDetail txn_ref_num = [%s]\n", (char*)v_txn_ref_num.arr));
                }

// amt_type
                if (ind_amt_type >= 0) {
                        v_amt_type.arr[v_amt_type.len] = '\0';
                        PutField_CString(hRec, "amt_type", (char*)v_amt_type.arr);
DEBUGLOG(("GetLastVerRecDetail amt_type = [%s]\n", (char*)v_amt_type.arr));
                }

// txn_amount
                if (ind_txn_amount >= 0) {
                        v_txn_amount.arr[v_txn_amount.len] = '\0';
                        PutField_CString(hRec, "txn_amount", (char*)v_txn_amount.arr);
DEBUGLOG(("GetLastVerRecDetail txn_amount = [%s]\n", (char*)v_txn_amount.arr));
                }

// bank_charge
                if (ind_bank_charge >= 0) {
                        v_bank_charge.arr[v_bank_charge.len] = '\0';
                        PutField_CString(hRec, "bank_charge", (char*)v_bank_charge.arr);
DEBUGLOG(("GetLastVerRecDetail bank_charge = [%s]\n", (char*)v_bank_charge.arr));
                }

// balance
                if (ind_balance >= 0) {
                        v_balance.arr[v_balance.len] = '\0';
                        PutField_CString(hRec, "balance", (char*)v_balance.arr);
DEBUGLOG(("GetLastVerRecDetail balance = [%s]\n", (char*)v_balance.arr));
                }

// sender_baid_name
                if (ind_sender_baid_name >= 0) {
                        v_sender_baid_name.arr[v_sender_baid_name.len] = '\0';
                        PutField_CString(hRec, "sender_baid_name", (char*)v_sender_baid_name.arr);
DEBUGLOG(("GetLastVerRecDetail sender_baid_name = [%s]\n", (char*)v_sender_baid_name.arr));
                }

// recipient_baid_name
                if (ind_recipient_baid_name >= 0) {
                        v_recipient_baid_name.arr[v_recipient_baid_name.len] = '\0';
                        PutField_CString(hRec, "recipient_baid_name", (char*)v_recipient_baid_name.arr);
DEBUGLOG(("GetLastVerRecDetail recipient_baid_name = [%s]\n", (char*)v_recipient_baid_name.arr));
                }

// client_name
                if (ind_client_name >= 0) {
                        v_client_name.arr[v_client_name.len] = '\0';
                        PutField_CString(hRec, "client_name", (char*)v_client_name.arr);
DEBUGLOG(("GetLastVerRecDetail client_name = [%s]\n", (char*)v_client_name.arr));
                }

// create_user
                if (ind_create_user >= 0) {
                        v_create_user.arr[v_create_user.len] = '\0';
                        PutField_CString(hRec, "create_user", (char*)v_create_user.arr);
DEBUGLOG(("GetLastVerRecDetail create_user = [%s]\n", (char*)v_create_user.arr));
                }

// create_timestamp
                if (ind_create_timestamp >= 0) {
                        v_create_timestamp.arr[v_create_timestamp.len] = '\0';
                        PutField_CString(hRec, "create_timestamp", (char*)v_create_timestamp.arr);
DEBUGLOG(("GetLastVerRecDetail create_timestamp = [%s]\n", (char*)v_create_timestamp.arr));
                }

// txn_location
		if (ind_txn_location >= 0) {
			v_txn_location.arr[v_txn_location.len] = '\0';
			PutField_CString(hRec, "txn_location", (char*)v_txn_location.arr);
DEBUGLOG(("GetLastVerRecDetail txn_location = [%s]\n", (char*)v_txn_location.arr));
		}

// txn_type
		if (ind_txn_type >= 0) {
			v_txn_type.arr[v_txn_type.len] = '\0';
			PutField_CString(hRec, "txn_type", (char*)v_txn_type.arr);
DEBUGLOG(("GetLastVerRecDetail txn_type = [%s]\n", (char*)v_txn_type.arr));
		}

// txn_reference
		if (ind_txn_reference >= 0) {
			v_txn_reference.arr[v_txn_reference.len] = '\0';
			PutField_CString(hRec, "txn_reference", (char*)v_txn_reference.arr);
DEBUGLOG(("GetLastVerRecDetail txn_reference = [%s]\n", (char*)v_txn_reference.arr));
		}

        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_getlastverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1290;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getlastverrecdetail_error;
}



        if (iCnt >= 0 ) {
DEBUGLOG(("GetLastVerRecDetail Normal Exit\n"));
                return  PD_OK;
        }

getlastverrecdetail_error:
DEBUGLOG(("getlastverrecdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatementTmp getlastverrecdetail_error code %d\n", sqlca.sqlcode);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getlastverrecdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 36;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1305;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int CheckTmpRecordByProvider(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO chktmprecbypid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		/* varchar	hv_int_bank_code[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_bank_acct_num;

		/* varchar	hv_raw_date[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_raw_date;

		/* varchar	hv_raw_time[PD_STMT_TMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[512]; } hv_raw_time;

		/* varchar	hv_balance[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_balance;

		/* varchar	hv_amt_type[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_amt_type;

		/* varchar	hv_txn_amount[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_txn_amount;

		int	v_cnt;

		short   ind_provider_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_raw_date = -1;
		short	ind_raw_time = -1;
		short	ind_balance = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"provider_id",&csTmp)) {
		hv_provider_id.len = strlen(csTmp);
		strncpy((char*)hv_provider_id.arr,csTmp,sizeof(hv_provider_id.arr));
		ind_provider_id = 0;
DEBUGLOG(("CheckTmpRecordByProvider: provider_id = [%.*s](%d)\n",sizeof(hv_provider_id.arr),hv_provider_id.arr,hv_provider_id.len));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr,csTmp,sizeof(hv_int_bank_code.arr));
		ind_int_bank_code = 0;
DEBUGLOG(("CheckTmpRecordByProvider: int_bank_code = [%.*s](%d)\n",sizeof(hv_int_bank_code.arr),hv_int_bank_code.arr,hv_int_bank_code.len));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr,csTmp,sizeof(hv_bank_acct_num.arr));
		ind_bank_acct_num = 0;
DEBUGLOG(("CheckTmpRecordByProvider: bank_acct_num = [%.*s](%d)\n",sizeof(hv_bank_acct_num.arr),hv_bank_acct_num.arr,hv_bank_acct_num.len));
	}

	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr,csTmp,sizeof(hv_raw_date.arr));
		ind_raw_date = 0;
DEBUGLOG(("CheckTmpRecordByProvider: raw_date = [%.*s](%d)\n",sizeof(hv_raw_date.arr),hv_raw_date.arr,hv_raw_date.len));
	}

	if (GetField_CString(hRls,"TIME_FORMAT",&csTmp)) {
		if (GetField_CString(hRls,"raw_time",&csTmp)) {
			hv_raw_time.len = strlen(csTmp);
			strncpy((char*)hv_raw_time.arr,csTmp,sizeof(hv_raw_time.arr));
			ind_raw_time = 0;
DEBUGLOG(("CheckTmpRecordByProvider: raw_time = [%.*s](%d)\n",sizeof(hv_raw_time.arr),hv_raw_time.arr,hv_raw_time.len));
		}
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance.len = strlen(csTmp);
		strncpy((char*)hv_balance.arr,csTmp,sizeof(hv_balance.arr));
		ind_balance = 0;
DEBUGLOG(("CheckTmpRecordByProvider: balance = [%.*s](%d)\n",sizeof(hv_balance.arr),hv_balance.arr,hv_balance.len));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr,csTmp,sizeof(hv_amt_type.arr));
		ind_amt_type = 0;
DEBUGLOG(("CheckTmpRecordByProvider: amt_type = [%.*s](%d)\n",sizeof(hv_amt_type.arr),hv_amt_type.arr,hv_amt_type.len));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount.len = strlen(csTmp);
		strncpy((char*)hv_txn_amount.arr,csTmp,sizeof(hv_txn_amount.arr));
		ind_txn_amount = 0;
DEBUGLOG(("CheckTmpRecordByProvider: txn_amount = [%.*s](%d)\n",sizeof(hv_txn_amount.arr),hv_txn_amount.arr,hv_txn_amount.len));
	}

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_TMP, OL_STATEMENT_HEADER, OL_BANK_ACCT_ID, OL_PSP_DETAIL
			WHERE   OLST_FILE_ID = OLSH_FILE_ID
			AND	OLSH_BAID = OBAI_BAID
                        AND     OBAI_PSP_ID = OPD_PSP_ID
                        AND     OPD_CLIENT_ID = : hv_provider_id
			AND	OLST_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	OLST_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
			AND	OLST_RAW_DATE = :hv_raw_date:ind_raw_date
			AND	(OLST_RAW_TIME = :hv_raw_time:ind_raw_time
				or :ind_raw_time = -1)
			AND	OLST_BALANCE = :hv_balance:ind_balance
			AND	OLST_AMT_TYPE = :hv_amt_type:ind_amt_type
			AND	OLST_TXN_AMOUNT = :hv_txn_amount:ind_txn_amount
			AND	OLST_VER = 0
			AND	OLST_LATEST_VER IS NOT NULL
			AND	OLST_DISABLED = 0
			AND	OLST_SKIP = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 36;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_TMP , OL_STAT\
EMENT_HEADER , OL_BANK_ACCT_ID , OL_PSP_DETAIL WHERE OLST_FILE_ID = OLSH_FILE\
_ID AND OLSH_BAID = OBAI_BAID AND OBAI_PSP_ID = OPD_PSP_ID AND OPD_CLIENT_ID \
= :b1 AND OLST_INT_BANK_CODE = :b2:b3 AND OLST_BANK_ACCT_NUM = :b4:b5 AND OLS\
T_RAW_DATE = :b6:b7 AND ( OLST_RAW_TIME = :b8:b9 or :b10 = - 1 ) AND OLST_BAL\
ANCE = :b11:b12 AND OLST_AMT_TYPE = :b13:b14 AND OLST_TXN_AMOUNT = :b15:b16 A\
ND OLST_VER = 0 AND OLST_LATEST_VER IS NOT NULL AND OLST_DISABLED = 0 AND OLS\
T_SKIP = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1320;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_int_bank_code;
 sqlstm.sqhstl[2] = (unsigned long )514;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_int_bank_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[3] = (unsigned long )514;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[4] = (unsigned long )514;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_raw_date;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[5] = (unsigned long )514;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_raw_time;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&ind_raw_time;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[7] = (unsigned long )258;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_balance;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[8] = (unsigned long )258;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_amt_type;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[9] = (unsigned long )258;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_txn_amount;
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
 if (sqlca.sqlcode < 0) goto chktmprecbypid_error;
}



	if (v_cnt>0) {
                iRet = FOUND;
DEBUGLOG(("CheckTmpRecordByProvider() FOUND\n"));
        } else {
                iRet = NOT_FOUND;
DEBUGLOG(("CheckTmpRecordByProvider() NOT FOUND\n"));
        }

DEBUGLOG(("CheckTmpRecordByProvider() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

chktmprecbypid_error:
DEBUGLOG(("chktmprecbypid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
