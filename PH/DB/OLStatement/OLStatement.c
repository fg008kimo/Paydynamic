
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
   unsigned char  *sqhstv[34];
   unsigned long  sqhstl[34];
            int   sqhsts[34];
            short *sqindv[34];
            int   sqinds[34];
   unsigned long  sqharm[34];
   unsigned long  *sqharc[34];
   unsigned short  sqadto[34];
   unsigned short  sqtdso[34];
} sqlstm = {12,34};

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
TATEMENT_REF IS NOT NULL ORDER BY OLSD_FILE_ID DESC , OLSD_STATEMENT_SEQ DESC\
 ) WHERE rownum <= 2            ";

 static char *sq0005 = 
"select olsh_filename , olsh_int_bank_code , olsh_bank_acct_num , olsh_baid \
, olsh_sms_count , olsh_skip_count , olsh_hold_count , olsh_accept_count , ol\
sh_total_count , olsh_message_code , olsh_org_filename , olsh_format_id , ols\
h_ver , olsh_status , olsh_split_count , olsh_add_count , olsh_update_count ,\
 olsh_delete_count , olsh_file_count from ol_statement_header where olsh_file\
_id = :b0:b1            ";

 static char *sq0015 = 
"SELECT OLSH_FILENAME , OLSH_INT_BANK_CODE , OLSH_BANK_ACCT_NUM , OLSH_BAID \
, OLSH_ORG_FILENAME , OLSH_FORMAT_ID , OLSH_MESSAGE_CODE , OLSH_VER , OLSH_ST\
ATUS FROM OL_STATEMENT_HEADER WHERE OLSH_FILE_ID = :b0:b1            ";

 static char *sq0016 = 
"SELECT olsd_int_bank_code , olsd_bank_acct_num , olsd_statement_date , olsd\
_statement_time , to_char ( olsd_statement_timestamp , 'yyyymmddhh24miss' ) ,\
 olsd_tfr_bank_name , olsd_tfr_bank_acct_num , olsd_tfr_type , olsd_tfr_chann\
el , olsd_tfr_text , olsd_tfr_customer_text , olsd_sender_name , olsd_txn_ref\
_num , olsd_amt_type , to_char ( olsd_txn_amount ) , olsd_txn_ccy , olsd_stat\
ement_ref , olsd_sender_baid_name , olsd_recipient_baid_name , olsd_client_na\
me FROM ol_statement_detail WHERE olsd_stat_txn_id = :b0:b1            ";

 static char *sq0019 = 
"SELECT olsd_int_bank_code , olsd_bank_acct_num , olsd_statement_date , olsd\
_statement_time , to_char ( olsd_statement_timestamp , 'yyyymmddhh24miss' ) ,\
 olsd_tfr_bank_name , olsd_tfr_bank_acct_num , olsd_tfr_type , olsd_tfr_chann\
el , olsd_tfr_text , olsd_tfr_customer_text , olsd_sender_name , olsd_txn_ref\
_num , olsd_amt_type , to_char ( olsd_txn_amount ) , olsd_txn_ccy , olsd_stat\
ement_ref , olsd_sender_baid_name , olsd_recipient_baid_name , olsd_client_na\
me , olsh_format_id FROM ol_statement_detail LEFT JOIN ol_statement_header ON\
 olsd_file_id = olsh_file_id WHERE olsd_stat_txn_id = ( select obt_stat_txn_i\
d from ol_baid_txn where obt_txn_id = :b0:b1 )            ";

 static char *sq0020 = 
"SELECT OLSD_TXN_ID , OLSD_BALANCE , OLSD_STATEMENT_DATE , OLSD_STATEMENT_TI\
ME , OLSD_TXN_AMOUNT , OLSD_AMT_TYPE FROM ( SELECT * FROM OL_STATEMENT_DETAIL\
 WHERE OLSD_INT_BANK_CODE = :b0:b1 AND OLSD_BANK_ACCT_NUM = :b2:b3 AND OLSD_B\
AID = :b4:b5 AND OLSD_STATEMENT_REF IS NOT NULL ORDER BY OLSD_FILE_ID DESC , \
OLSD_STATEMENT_SEQ DESC ) WHERE rownum <= 2            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,338,0,9,107,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,109,0,0,6,0,0,1,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,
67,0,0,1,0,0,15,187,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,201,0,0,0,0,0,1,0,
97,0,0,2,353,0,4,293,0,0,10,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
152,0,0,3,109,0,4,344,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
175,0,0,4,135,0,4,392,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
202,0,0,5,407,0,9,497,0,2049,1,1,0,1,0,1,9,0,0,
221,0,0,5,0,0,13,500,0,0,19,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,1,0,0,2,3,0,0,
2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
312,0,0,5,0,0,15,646,0,0,0,0,0,1,0,
327,0,0,5,0,0,15,656,0,0,0,0,0,1,0,
342,0,0,6,725,0,6,873,0,0,22,22,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,
0,1,1,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
445,0,0,7,585,0,6,1094,0,0,18,18,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,
1,3,0,0,1,3,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,3,0,0,1,1,0,0,1,3,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,3,0,0,1,9,0,0,
532,0,0,8,1203,0,6,1465,0,0,34,34,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
683,0,0,9,0,0,17,1572,0,0,1,1,0,1,0,1,9,0,0,
702,0,0,9,0,0,21,1573,0,0,0,0,0,1,0,
717,0,0,10,434,0,6,1716,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
780,0,0,11,1092,0,6,2076,0,0,30,30,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,4,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
915,0,0,12,492,0,4,2290,0,0,11,9,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
974,0,0,13,338,0,4,2307,0,0,7,5,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,
1017,0,0,14,330,0,4,2323,0,0,7,5,0,1,0,2,9,0,0,2,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,
1060,0,0,15,221,0,9,2650,0,2049,1,1,0,1,0,1,9,0,0,
1079,0,0,15,0,0,13,2653,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,3,0,0,2,3,0,0,2,1,0,0,
1130,0,0,15,0,0,15,2731,0,0,0,0,0,1,0,
1145,0,0,15,0,0,15,2741,0,0,0,0,0,1,0,
1160,0,0,16,531,0,9,2828,0,2049,1,1,0,1,0,1,9,0,0,
1179,0,0,16,0,0,13,2831,0,0,20,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1274,0,0,16,0,0,15,2998,0,0,0,0,0,1,0,
1289,0,0,16,0,0,15,3008,0,0,0,0,0,1,0,
1304,0,0,17,78,0,4,3038,0,0,2,1,0,1,0,2,3,0,0,1,4,0,0,
1327,0,0,18,88,0,4,3083,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1350,0,0,19,672,0,9,3202,0,2049,1,1,0,1,0,1,9,0,0,
1369,0,0,19,0,0,13,3205,0,0,21,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
1468,0,0,19,0,0,15,3380,0,0,0,0,0,1,0,
1483,0,0,19,0,0,15,3390,0,0,0,0,0,1,0,
1498,0,0,20,361,0,9,3465,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
1525,0,0,20,0,0,13,3467,0,0,6,0,0,1,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,9,0,0,
1564,0,0,20,0,0,15,3545,0,0,0,0,0,1,0,
1579,0,0,20,0,0,15,3559,0,0,0,0,0,1,0,
1594,0,0,21,467,0,4,3660,0,0,11,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
1653,0,0,22,155,0,4,3723,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1684,0,0,23,100,0,4,3765,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1707,0,0,24,244,0,4,3808,0,0,5,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,3,0,0,
1742,0,0,25,154,0,6,3868,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
1773,0,0,26,133,0,6,3939,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/07/04              Stan Poon
Add error table                                    2013/09/17              Stan Poon
Cater sms / bank stmt matching                     2013/10/16              David Wong
Add GetHeader and CheckFileIdExist		   2014/10/08		   Elvis Wong	
Add GetStmtDtlByBAIDTxnId			   2014/12/24		   LokMan Chow
Add sender_baid_name, 
    recipient_baid_name
    and client name	   			   2014/12/29		   Elvis Wong
Modify GetStmtDtlByBAIDTxnId                       2015/02/10              Virginia Yun
Add GetLastBAIDBalance				   2015/02/16		   Elvis Wong
Add CheckBankStmtRecordByProvider		   2015/04/08		   Elvis Wong
Add CheckBAIDPendingExist			   2015/05/18		   Elvis Wong
Change type, channel, customer_text length         2015/12/15              Elvis Wong
Add GetCountByBankAcct       			   2016/08/09              Dirk Wong
Add txn location, txn type and txn reference       2016/11/04              David Wong
Add UpdateHeaderAutoUpload			   2018/01/30		   Elvis Wong
Add UpdateHeaderRenamedFilename			   2018/03/12		   Elvis Wong
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
				ORDER BY OLSD_FILE_ID DESC, OLSD_STATEMENT_SEQ DESC)
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


int CheckBankStmtRecord(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
	char *csTmp;

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
DEBUGLOG(("CheckBankStmtReocrd() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("CheckBankStmtReocrd() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("CheckBankStmtReocrd() statement_date = [%.*s]\n", hv_statement_date.len, hv_statement_date.arr));
	}

	if (GetField_CString(hRls,"TIME_FORMAT",&csTmp)) {
		if (GetField_CString(hRls,"statement_time",&csTmp)) {
			hv_statement_time.len = strlen(csTmp);
			strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
			ind_statement_time = 0;
DEBUGLOG(("CheckBankStmtReocrd() statement_time = [%.*s]\n", hv_statement_time.len, hv_statement_time.arr));
		}
	}

	if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		strncpy((char*)hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("CheckBankStmtReocrd() txn_ccy = [%.*s]\n",hv_txn_ccy.len, hv_txn_ccy.arr));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("CheckBankStmtReocrd() amt_type = [%.*s]\n",hv_amt_type.len,hv_amt_type.arr));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("CheckBankStmtReocrd() txn_amount = [%.2lf]\n", hv_txn_amount));
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
DEBUGLOG(("CheckBankStmtReocrd() balance = [%.2lf]\n", hv_balance));
	}

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_DETAIL
			WHERE	OLSD_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	OLSD_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
			AND	OLSD_STATEMENT_DATE = :hv_statement_date:ind_statement_date
			AND	(OLSD_STATEMENT_TIME = :hv_statement_time:ind_statement_time
				OR :ind_statement_time = -1)
			AND	OLSD_TXN_CCY = :hv_txn_ccy:ind_txn_ccy
			AND	OLSD_AMT_TYPE = :hv_amt_type:ind_amt_type
			AND	OLSD_TXN_AMOUNT = :hv_txn_amount:ind_txn_amount
			AND	OLSD_BALANCE = :hv_balance:ind_balance
			AND	OLSD_STATEMENT_REF IS NOT NULL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_DETAIL WHERE \
OLSD_INT_BANK_CODE = :b1:b2 AND OLSD_BANK_ACCT_NUM = :b3:b4 AND OLSD_STATEMEN\
T_DATE = :b5:b6 AND ( OLSD_STATEMENT_TIME = :b7:b8 OR :b9 = - 1 ) AND OLSD_TX\
N_CCY = :b10:b11 AND OLSD_AMT_TYPE = :b12:b13 AND OLSD_TXN_AMOUNT = :b14:b15 \
AND OLSD_BALANCE = :b16:b17 AND OLSD_STATEMENT_REF IS NOT NULL ";
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
 sqlstm.sqhstv[5] = (unsigned char  *)&ind_statement_time;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
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
DEBUGLOG(("CheckBankStmtReocrd() FOUND\n"));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckBankStmtReocrd() NOT FOUND\n"));
	}

DEBUGLOG(("CheckBankStmtReocrd() Normal Exit! iRet = [%d]\n", iRet));
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

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_filename.len = strlen(csFilename);
	strncpy((char*)hv_filename.arr,csFilename,hv_filename.len);
DEBUGLOG(("CheckFileExist filename = [%s]\n",csFilename));

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_HEADER
			WHERE	OLSH_ORG_FILENAME = :hv_filename
			AND	OLSH_MESSAGE_CODE = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_HEADER WHERE \
OLSH_ORG_FILENAME = :b1 AND OLSH_MESSAGE_CODE = 0 ";
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
 if (sqlca.sqlcode < 0) goto checkheader_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckFileExist() filename [%s] FOUND\n",csFilename));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckFileExist() filename [%s] NOT FOUND\n",csFilename));
	}

DEBUGLOG(("CheckFileExist() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CheckPendingExist(const char* csIntBankCode, const char* csBankAcctNum)
{
        int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkheader_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int	v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_int_bank_code.len = strlen(csIntBankCode);
	strncpy((char*)hv_int_bank_code.arr,csIntBankCode,hv_int_bank_code.len);
DEBUGLOG(("CheckPendingExist int_bank_code = [%s]\n",csIntBankCode));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
	strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
DEBUGLOG(("CheckPendingExist bank_acct_num = [%s]\n",csBankAcctNum));

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_HEADER
			WHERE	OLSH_INT_BANK_CODE = :hv_int_bank_code
			AND	OLSH_BANK_ACCT_NUM = :hv_bank_acct_num
			AND	OLSH_STATUS = 'W'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_HEADER WHERE \
OLSH_INT_BANK_CODE = :b1 AND OLSH_BANK_ACCT_NUM = :b2 AND OLSH_STATUS = 'W' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )175;
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
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[2] = (unsigned long )52;
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
 if (sqlca.sqlcode < 0) goto checkheader_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckPendingExist() FOUND\n"));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckPendingExist() NOT FOUND\n"));
	}

DEBUGLOG(("CheckPendingExist() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetHeader(const char* csFileId, hash_t* hRec)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;
	
		/* varchar         v_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_filename;

                /* varchar         v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

                /* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

                /* varchar         v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		int             v_sms_count;
                int             v_skip_count;
                int             v_hold_count;
                int             v_accept_count;
                int             v_total_count;
		int             v_message_code;
                /* varchar         v_org_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_org_filename;

                /* varchar         v_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_id;

                int             v_ver;
		char            v_status;
                int             v_split_count;
                int             v_add_count;
                int             v_update_count;
                int             v_delete_count;
                int             v_file_count;

		short           ind_file_id = -1;
		short           ind_filename = -1;
                short           ind_int_bank_code = -1;
                short           ind_bank_acct_num = -1;
                short           ind_baid = -1;
                short           ind_sms_count = -1;
                short           ind_skip_count = -1;
                short           ind_hold_count = -1;
                short           ind_accept_count = -1;
                short           ind_total_count = -1;
		short           ind_message_code = -1;
                short           ind_org_filename = -1;
                short           ind_format_id = -1;
                short           ind_ver = -1;
		short           ind_status = -1;
                short           ind_split_count = -1;
                short           ind_add_count = -1;
                short           ind_update_count = -1;
                short           ind_delete_count = -1;
                short           ind_file_count = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


// file_id
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,sizeof(hv_file_id.arr));
        ind_file_id = 0;
DEBUGLOG(("GetHeader: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));

	/* EXEC SQL DECLARE c_cursor_getheader CURSOR FOR
        	 select olsh_filename,
			olsh_int_bank_code,
			olsh_bank_acct_num,
			olsh_baid,
			olsh_sms_count,	
			olsh_skip_count,
                        olsh_hold_count,
                        olsh_accept_count,
                        olsh_total_count,
			olsh_message_code,
			olsh_org_filename,
			olsh_format_id,
                        olsh_ver,
			olsh_status,
                        olsh_split_count,
                        olsh_add_count,
                        olsh_update_count,
                        olsh_delete_count,
                        olsh_file_count
		 from   ol_statement_header
                 where  olsh_file_id = :hv_file_id:ind_file_id; */ 
	

	/* EXEC SQL OPEN c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )202;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
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
 if (sqlca.sqlcode < 0) goto getheader_error;
}



        for (;;) {
		 /* EXEC SQL FETCH c_cursor_getheader
                 into   :v_filename:ind_filename,	
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_baid:ind_baid,
			:v_sms_count:ind_sms_count,
			:v_skip_count:ind_skip_count,
                        :v_hold_count:ind_hold_count,
                        :v_accept_count:ind_accept_count,
                        :v_total_count:ind_total_count,
                        :v_message_code:ind_message_code,
                        :v_org_filename:ind_org_filename,
                        :v_format_id:ind_format_id,
                        :v_ver:ind_ver,
                        :v_status:ind_status,
                        :v_split_count:ind_split_count,
                        :v_add_count:ind_add_count,
                        :v_update_count:ind_update_count,
                        :v_delete_count:ind_delete_count,
                        :v_file_count:ind_file_count; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 19;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )221;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_filename;
   sqlstm.sqhstl[0] = (unsigned long )103;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_filename;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
   sqlstm.sqhstl[2] = (unsigned long )53;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_baid;
   sqlstm.sqhstl[3] = (unsigned long )23;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_baid;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_sms_count;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_sms_count;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_skip_count;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_skip_count;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_hold_count;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_hold_count;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_accept_count;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_accept_count;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_total_count;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_total_count;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_message_code;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_message_code;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_org_filename;
   sqlstm.sqhstl[10] = (unsigned long )103;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_org_filename;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_format_id;
   sqlstm.sqhstl[11] = (unsigned long )23;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_format_id;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_ver;
   sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_ver;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_status;
   sqlstm.sqhstl[13] = (unsigned long )1;
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_status;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_split_count;
   sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_split_count;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_add_count;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_add_count;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_update_count;
   sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_update_count;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_delete_count;
   sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_delete_count;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_file_count;
   sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_file_count;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto getheader_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

// filename
       		if (ind_filename >= 0) {
               		v_filename.arr[v_filename.len] = '\0';
             		PutField_CString(hRec, "filename", (const char*)v_filename.arr);
DEBUGLOG(("GetHeader filename = [%s]\n", (const char*)v_filename.arr));
      		}

// int_bank_code
       		if (ind_int_bank_code >= 0) {
        	       	v_int_bank_code.arr[v_int_bank_code.len] = '\0';
        	     	PutField_CString(hRec, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetHeader int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
      		}

// bank_acct_num
       		if (ind_bank_acct_num >= 0) {
        	       	v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
        	     	PutField_CString(hRec, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetHeader bank_acct_num = [%s]\n", (const char*)v_bank_acct_num.arr));
      		}

// baid
       		if (ind_baid >= 0) {
        	       	v_baid.arr[v_baid.len] = '\0';
        	     	PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetHeader baid = [%s]\n", (const char*)v_baid.arr));
      		}

// sms_count
        	if (ind_sms_count >= 0) {
        	        PutField_Int(hRec, "sms_count", v_sms_count);
DEBUGLOG(("GetHeader sms_count = [%d]\n", v_sms_count));
        	}

// skip_count
        	if (ind_skip_count >= 0) {
        	        PutField_Int(hRec, "skip_count", v_skip_count);
DEBUGLOG(("GetHeader skip_count = [%d]\n", v_skip_count));
        	}

// hold_count
        	if (ind_hold_count >= 0) {
        	        PutField_Int(hRec, "hold_count", v_hold_count);
DEBUGLOG(("GetHeader hold_count = [%d]\n", v_hold_count));
        	}

// accept_count
        	if (ind_accept_count >= 0) {
        	        PutField_Int(hRec, "accept_count", v_accept_count);
DEBUGLOG(("GetHeader accept_count = [%d]\n", v_accept_count));
        	}

// total_count
        	if (ind_total_count >= 0) {
        	        PutField_Int(hRec, "total_count", v_total_count);
DEBUGLOG(("GetHeader total_count = [%d]\n", v_total_count));
        	}

// message_code
        	if (ind_message_code >= 0) {
        	        PutField_Double(hRec, "message_code", v_message_code);
DEBUGLOG(("GetHeader message_code = [%.2f]\n", v_message_code));
        	}

// org_filename
       		if (ind_org_filename >= 0) {
        	       	v_org_filename.arr[v_org_filename.len] = '\0';
        	     	PutField_CString(hRec, "org_filename", (const char*)v_org_filename.arr);
DEBUGLOG(("GetHeader org_filename = [%s]\n", (const char*)v_org_filename.arr));
      		}
	
// format_id
       		if (ind_format_id >= 0) {
               		v_format_id.arr[v_format_id.len] = '\0';
        	     	PutField_CString(hRec, "format_id", (const char*)v_format_id.arr);
DEBUGLOG(("GetHeader format_id = [%s]\n", (const char*)v_format_id.arr));
      		}

// ver
        	if (ind_ver >= 0) {
        	        PutField_Int(hRec, "ver", v_ver);
DEBUGLOG(("GetHeader ver = [%d]\n", v_ver));
        	}

// status
        	if (ind_status >= 0) {
        	        PutField_Char(hRec, "status", v_status);
DEBUGLOG(("GetHeader status = [%d]\n", v_status));
        	}

// split_count
        	if (ind_split_count >= 0) {
        	        PutField_Int(hRec, "split_count", v_split_count);
DEBUGLOG(("GetHeader split_count = [%d]\n", v_split_count));
        	}

// add_count
        	if (ind_add_count >= 0) {
        	        PutField_Int(hRec, "add_count", v_add_count);
DEBUGLOG(("GetHeader add_count = [%d]\n", v_add_count));
        	}

// update_count
        	if (ind_update_count >= 0) {
        	        PutField_Int(hRec, "update_count", v_update_count);
DEBUGLOG(("GetHeader update_count = [%d]\n", v_update_count));
        	}

// delete_count
        	if (ind_delete_count >= 0) {
                	PutField_Int(hRec, "delete_count", v_delete_count);
DEBUGLOG(("GetHeader delete_count = [%d]\n", v_delete_count));
        	}

// file_count
        	if (ind_file_count >= 0) {
                	PutField_Int(hRec, "file_count", v_file_count);
DEBUGLOG(("GetHeader file_count = [%d]\n", v_file_count));
        	}
	}

	/* EXEC SQL CLOSE c_cursor_getheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )312;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getheader_error;
}



DEBUGLOG(("GetHeader Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getheader_error:
DEBUGLOG(("getheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getheader_error: SP_INTERNAL_ERR TxnAbort\n");
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )327;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getheader_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int AddHeader(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;
	char	cTmp;

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

		/* varchar		hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		int		hv_ver;
		char		hv_status;
		int		hv_split_count;
		int		hv_add_count;
		int		hv_update_count;
		int		hv_delete_count;
		int		hv_file_count;
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
		short		ind_format_id = -1;
		short		ind_ver = -1;
		short		ind_status = -1;
		short		ind_split_count = -1;
		short		ind_add_count = -1;
		short		ind_update_count = -1;
		short		ind_delete_count = -1;
		short		ind_file_count = -1;
		short		ind_create_user = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("AddHeader:file_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"new_file_name",&csTmp)) {
		hv_filename.len = strlen(csTmp);
		strncpy((char*)hv_filename.arr, csTmp, hv_filename.len);
		ind_filename = 0;
DEBUGLOG(("AddHeader:filename = [%.*s]\n",hv_filename.len, hv_filename.arr));
	} else {
DEBUGLOG(("AddHeader:filename NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddHeader:int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddHeader:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddHeader:baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	}

	hv_sms_count = 0;
	if (GetField_Int(hRls, "sms_count", &iTmp)) {
		hv_sms_count = iTmp;
DEBUGLOG(("AddHeader:sms_count = [%d]\n",hv_sms_count));
	}
	ind_sms_count = 0;

	hv_skip_count = 0;
	if (GetField_Int(hRls, "skip_count", &iTmp)) {
		hv_skip_count = iTmp;
DEBUGLOG(("AddHeader:skip_count = [%d]\n",hv_skip_count));
	}
	ind_skip_count = 0;

	hv_hold_count = 0;
	if (GetField_Int(hRls, "hold_count", &iTmp)) {
		hv_hold_count = iTmp;
DEBUGLOG(("AddHeader:hold_count = [%d]\n",hv_hold_count));
	}
	ind_hold_count = 0;

	hv_accept_count = 0;
	if (GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
DEBUGLOG(("AddHeader:accept_count = [%d]\n",hv_accept_count));
	}
	ind_accept_count = 0;

	hv_total_count = 0;
	if (GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
DEBUGLOG(("AddHeader:total_count = [%d]\n",hv_total_count));
	}
	ind_total_count = 0;

	if (GetField_Int(hRls, "message_code", &iTmp)) {
		hv_message_code = iTmp;
		ind_message_code = 0;
DEBUGLOG(("AddHeader:message_code = [%d]\n",hv_message_code));
	}

	if (GetField_CString(hRls,"in_file_name",&csTmp)) {
		hv_org_filename.len = strlen(csTmp);
		strncpy((char*)hv_org_filename.arr, csTmp, hv_org_filename.len);
		ind_org_filename = 0;
DEBUGLOG(("AddHeader:org_filename = [%.*s]\n",hv_org_filename.len, hv_org_filename.arr));
	} else {
DEBUGLOG(("AddHeader:org_filename NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"format_id",&csTmp)) {
		hv_format_id.len = strlen(csTmp);
		strncpy((char*)hv_format_id.arr, csTmp, hv_format_id.len);
		ind_format_id = 0;
DEBUGLOG(("AddHeader:format_id = [%.*s]\n",hv_format_id.len, hv_format_id.arr));
	}

	hv_ver = 0;
	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
DEBUGLOG(("AddHeader:ver = [%d]\n",hv_ver));
	}
	ind_ver = 0;

	if (GetField_Char(hRls, "status", &cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("AddHeader:status = [%c]\n",hv_status));
	}

	hv_split_count = 0;
	if (GetField_Int(hRls, "split_count", &iTmp)) {
		hv_split_count = iTmp;
DEBUGLOG(("AddHeader:split_count = [%d]\n",hv_split_count));
	}
	ind_split_count = 0;

	hv_add_count = 0;
	if (GetField_Int(hRls, "add_count", &iTmp)) {
		hv_add_count = iTmp;
DEBUGLOG(("AddHeader:add_count = [%d]\n",hv_add_count));
	}
	ind_add_count = 0;

	hv_update_count = 0;
	if (GetField_Int(hRls, "update_count", &iTmp)) {
		hv_update_count = iTmp;
DEBUGLOG(("AddHeader:update_count = [%d]\n",hv_update_count));
	}
	ind_update_count = 0;

	hv_delete_count = 0;
	if (GetField_Int(hRls, "delete_count", &iTmp)) {
		hv_delete_count = iTmp;
DEBUGLOG(("AddHeader:delete_count = [%d]\n",hv_delete_count));
	}
	ind_delete_count = 0;

	hv_file_count = 0;
	if (GetField_Int(hRls, "file_count", &iTmp)) {
		hv_file_count = iTmp;
DEBUGLOG(("AddHeader:file_count = [%d]\n",hv_file_count));
	}
	ind_file_count = 0;

	if (GetField_CString(hRls,"create_user",&csTmp))
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
			:hv_return_value := sp_ol_statement_header_ins_v2(
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
						:hv_format_id:ind_format_id,
						:hv_ver:ind_ver,
						:hv_status:ind_status,
						:hv_split_count:ind_split_count,
						:hv_add_count:ind_add_count,
						:hv_update_count:ind_update_count,
						:hv_delete_count:ind_delete_count,
						:hv_file_count:ind_file_count,
						:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_header_ins_v2 ( :\
hv_file_id:ind_file_id , :hv_filename:ind_filename , :hv_int_bank_code:ind_in\
t_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid , :hv_s\
ms_count:ind_sms_count , :hv_skip_count:ind_skip_count , :hv_hold_count:ind_h\
old_count , :hv_accept_count:ind_accept_count , :hv_total_count:ind_total_cou\
nt , :hv_message_code:ind_message_code , :hv_org_filename:ind_org_filename , \
:hv_format_id:ind_format_id , :hv_ver:ind_ver , :hv_status:ind_status , :hv_s\
plit_count:ind_split_count , :hv_add_count:ind_add_count , :hv_update_count:i\
nd_update_count , :hv_delete_count:ind_delete_count , :hv_file_count:ind_file\
_count , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )342;
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
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[13] = (unsigned long )22;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_format_id;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_ver;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[15] = (unsigned long )1;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_status;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_split_count;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_split_count;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_add_count;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_add_count;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_update_count;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_update_count;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_delete_count;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_delete_count;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_file_count;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_file_count;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[21] = (unsigned long )22;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto addheader_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("AddHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_AddHeader: SP_OTHER_ERR\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddHeader: SP_ERR\n");
DEBUGLOG(("AddHeader: SP_ERR\n"));
		return PD_ERR;
	}

addheader_error:
DEBUGLOG(("addheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement_AddHeader: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateHeader(const hash_t *hRls)
{
	int	iTmp;
	char	*csTmp;
	char	cTmp;

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
		/* varchar		hv_format_id[PD_FORMAT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_format_id;

		int		hv_ver;
		char		hv_status;
		int		hv_split_count;
		int		hv_add_count;
		int		hv_update_count;
		int		hv_delete_count;
		int		hv_file_count;
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
		short		ind_format_id = -1;
		short		ind_ver = -1;
		short		ind_status = -1;
		short		ind_split_count = -1;
		short		ind_add_count = -1;
		short		ind_update_count = -1;
		short		ind_delete_count = -1;
		short		ind_file_count = -1;
		short		ind_update_user = -1;

		short		hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("UpdateHeader:file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	} else {
DEBUGLOG(("UpdateHeader:file_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("UpdateHeader:baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	} else {
DEBUGLOG(("UpdateHeader:baid NOT FOUND!!!\n"));
	}

	if (GetField_Int(hRls, "sms_count", &iTmp)) {
		hv_sms_count = iTmp;
		ind_sms_count = 0;
DEBUGLOG(("UpdateHeader:sms_count = [%d]\n",hv_sms_count));
	}

	if (GetField_Int(hRls, "skip_count", &iTmp)) {
		hv_skip_count = iTmp;
		ind_skip_count = 0;
DEBUGLOG(("UpdateHeader:skip_count = [%d]\n",hv_skip_count));
	}

	if (GetField_Int(hRls, "hold_count", &iTmp)) {
		hv_hold_count = iTmp;
		ind_hold_count = 0;
DEBUGLOG(("UpdateHeader:hold_count = [%d]\n",hv_hold_count));
	}

	if (GetField_Int(hRls, "accept_count", &iTmp)) {
		hv_accept_count = iTmp;
		ind_accept_count = 0;
DEBUGLOG(("UpdateHeader:accept_count = [%d]\n",hv_accept_count));
	}

	if (GetField_Int(hRls, "total_count", &iTmp)) {
		hv_total_count = iTmp;
		ind_total_count = 0;
DEBUGLOG(("UpdateHeader:total_count = [%d]\n",hv_total_count));
	}

	if (GetField_Int(hRls, "message_code", &iTmp)) {
		hv_message_code = iTmp;
		ind_message_code = 0;
DEBUGLOG(("UpdateHeader:message_code = [%d]\n",hv_message_code));
	}

	if (GetField_CString(hRls,"format_id",&csTmp))
	{
		hv_format_id.len = strlen(csTmp);
		strncpy((char*)hv_format_id.arr, csTmp, hv_format_id.len);
		ind_format_id = 0;
DEBUGLOG(("UpdateHeader:format_id = [%.*s]\n",hv_format_id.len,hv_format_id.arr));
	} else {
DEBUGLOG(("UpdateHeader:format_id NOT FOUND!!!\n"));
	}

	if (GetField_Int(hRls, "ver", &iTmp)) {
		hv_ver = iTmp;
		ind_ver = 0;
DEBUGLOG(("UpdateHeader:ver = [%d]\n",hv_ver));
	}

	if (GetField_Char(hRls, "status", &cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("UpdateHeader:status = [%c]\n",hv_status));
	}

	if (GetField_Int(hRls, "split_count", &iTmp)) {
		hv_split_count = iTmp;
		ind_split_count = 0;
DEBUGLOG(("UpdateHeader:split_count = [%d]\n",hv_split_count));
	}

	if (GetField_Int(hRls, "add_count", &iTmp)) {
		hv_add_count = iTmp;
		ind_add_count = 0;
DEBUGLOG(("UpdateHeader:add_count = [%d]\n",hv_add_count));
	}

	if (GetField_Int(hRls, "update_count", &iTmp)) {
		hv_update_count = iTmp;
		ind_update_count = 0;
DEBUGLOG(("UpdateHeader:update_count = [%d]\n",hv_update_count));
	}

	if (GetField_Int(hRls, "delete_count", &iTmp)) {
		hv_delete_count = iTmp;
		ind_delete_count = 0;
DEBUGLOG(("UpdateHeader:delete_count = [%d]\n",hv_delete_count));
	}

	if (GetField_Int(hRls, "file_count", &iTmp)) {
		hv_file_count = iTmp;
		ind_file_count = 0;
DEBUGLOG(("UpdateHeader:file_count = [%d]\n",hv_file_count));
	}

	if (GetField_CString(hRls,"update_user",&csTmp))
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
			:hv_return_value := sp_ol_statement_header_upd_v2(
						:hv_file_id:ind_file_id,
						:hv_baid:ind_baid,
						:hv_sms_count:ind_sms_count,
						:hv_skip_count:ind_skip_count,
						:hv_hold_count:ind_hold_count,
						:hv_accept_count:ind_accept_count,
						:hv_total_count:ind_total_count,
						:hv_message_code:ind_message_code,
						:hv_format_id:ind_format_id,
						:hv_ver:ind_ver,
						:hv_status:ind_status,
						:hv_split_count:ind_split_count,
						:hv_add_count:ind_add_count,
						:hv_update_count:ind_update_count,
						:hv_delete_count:ind_delete_count,
						:hv_file_count:ind_file_count,
						:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_header_upd_v2 ( :\
hv_file_id:ind_file_id , :hv_baid:ind_baid , :hv_sms_count:ind_sms_count , :h\
v_skip_count:ind_skip_count , :hv_hold_count:ind_hold_count , :hv_accept_coun\
t:ind_accept_count , :hv_total_count:ind_total_count , :hv_message_code:ind_m\
essage_code , :hv_format_id:ind_format_id , :hv_ver:ind_ver , :hv_status:ind_\
status , :hv_split_count:ind_split_count , :hv_add_count:ind_add_count , :hv_\
update_count:ind_update_count , :hv_delete_count:ind_delete_count , :hv_file_\
count:ind_file_count , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )445;
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
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_format_id;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_format_id;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_ver;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_ver;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[11] = (unsigned long )1;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_status;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_split_count;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_split_count;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_add_count;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_add_count;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_update_count;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_update_count;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_delete_count;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_delete_count;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_file_count;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_file_count;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[17] = (unsigned long )22;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto update_header_error;
}



DEBUGLOG(("UpdateHeader:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("UpdateHeader:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateHeader: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateHeader: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateHeader: SP_ERR\n");
DEBUGLOG(("UpdateHeader: SP_ERR\n"));
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

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_customer_text;

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

		/* varchar		hv_raw_date[PD_STMT_RAW_DATE]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_raw_date;

		/* varchar		hv_raw_time[PD_STMT_RAW_TIME]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_raw_time;

		/* varchar		hv_sender_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_sender_baid_name;

		/* varchar		hv_recipient_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_recipient_baid_name;

		/* varchar		hv_client_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

		/* varchar		hv_txn_location[PD_TXN_LOCATION_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_location;

		/* varchar		hv_txn_type[PD_TXN_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_type;

		/* varchar		hv_txn_reference[PD_TXN_REFERENCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_reference;


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
		short		ind_raw_date = -1;
		short		ind_raw_time = -1;
		short		ind_sender_baid_name = -1;
		short		ind_recipient_baid_name = -1;
		short		ind_client_name = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"stat_txn_id",&csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("AddDetail: stat_txn_id = [%.*s]\n",hv_stat_txn_id.len, hv_stat_txn_id.arr));
	}

	if (GetField_CString(hRls,"file_id",&csTmp)) {
		hv_file_id.len = strlen(csTmp);
		strncpy((char*)hv_file_id.arr, csTmp, hv_file_id.len);
		ind_file_id = 0;
DEBUGLOG(("AddDetail: file_id = [%.*s]\n",hv_file_id.len, hv_file_id.arr));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("AddDetail: int_bank_code = [%.*s]\n",hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("AddDetail: bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("AddDetail: baid = [%.*s]\n",hv_baid.len, hv_baid.arr));
	}

	if (GetField_Int(hRls, "statement_seq", &iTmp)) {
		hv_statement_seq = iTmp;
		ind_statement_seq = 0;
DEBUGLOG(("AddDetail: statement_seq = [%d]\n",hv_statement_seq));
	}

	if (GetField_CString(hRls,"txn_id",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("AddDetail: txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));
	}

	if (GetField_CString(hRls,"statement_ref",&csTmp)) {
		hv_statement_ref.len = strlen(csTmp);
		strncpy((char*)hv_statement_ref.arr, csTmp, hv_statement_ref.len);
		ind_statement_ref = 0;
DEBUGLOG(("AddDetail: statement_ref = [%.*s]\n",hv_statement_ref.len, hv_statement_ref.arr));
	}

	if (GetField_CString(hRls,"input_channel",&csTmp)) {
		hv_input_channel.len = strlen(csTmp);
		strncpy((char*)hv_input_channel.arr, csTmp, hv_input_channel.len);
		ind_input_channel = 0;
DEBUGLOG(("AddDetail: input_channel = [%.*s]\n",hv_input_channel.len, hv_input_channel.arr));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("AddDetail: statement_date = [%.*s]\n",hv_statement_date.len, hv_statement_date.arr));
	}

	if (GetField_CString(hRls,"statement_time",&csTmp)) {
		hv_statement_time.len = strlen(csTmp);
		strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
		ind_statement_time = 0;
DEBUGLOG(("AddDetail: statement_time = [%.*s]\n",hv_statement_time.len, hv_statement_time.arr));
	}

	if (GetField_CString(hRls,"tfr_bank_name",&csTmp)) {
		hv_tfr_bank_name.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_name.arr, csTmp, hv_tfr_bank_name.len);
		ind_tfr_bank_name = 0;
DEBUGLOG(("AddDetail: tfr_bank_name = [%.*s]\n",hv_tfr_bank_name.len, hv_tfr_bank_name.arr));
	}

	if (GetField_CString(hRls,"tfr_bank_acct_num",&csTmp)) {
		hv_tfr_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_tfr_bank_acct_num.arr, csTmp, hv_tfr_bank_acct_num.len);
		ind_tfr_bank_acct_num = 0;
DEBUGLOG(("AddDetail: tfr_bank_acct_num = [%.*s]\n",hv_tfr_bank_acct_num.len, hv_tfr_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"tfr_type",&csTmp)) {
		hv_tfr_type.len = strlen(csTmp);
		strncpy((char*)hv_tfr_type.arr, csTmp, hv_tfr_type.len);
		ind_tfr_type = 0;
DEBUGLOG(("AddDetail: tfr_type = [%.*s]\n",hv_tfr_type.len, hv_tfr_type.arr));
	}

	if (GetField_CString(hRls,"tfr_channel",&csTmp)) {
		hv_tfr_channel.len = strlen(csTmp);
		strncpy((char*)hv_tfr_channel.arr, csTmp, hv_tfr_channel.len);
		ind_tfr_channel = 0;
DEBUGLOG(("AddDetail: tfr_channel = [%.*s]\n",hv_tfr_channel.len, hv_tfr_channel.arr));
	}

	if (GetField_CString(hRls,"tfr_text",&csTmp)) {
		hv_tfr_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_text.arr, csTmp, hv_tfr_text.len);
		ind_tfr_text = 0;
DEBUGLOG(("AddDetail: tfr_text = [%.*s]\n",hv_tfr_text.len, hv_tfr_text.arr));
	}

	if (GetField_CString(hRls,"tfr_customer_text",&csTmp)) {
		hv_tfr_customer_text.len = strlen(csTmp);
		strncpy((char*)hv_tfr_customer_text.arr, csTmp, hv_tfr_customer_text.len);
		ind_tfr_customer_text = 0;
DEBUGLOG(("AddDetail: tfr_customer_text = [%.*s]\n",hv_tfr_customer_text.len, hv_tfr_customer_text.arr));
	}

	if (GetField_CString(hRls,"sender_name",&csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		strncpy((char*)hv_sender_name.arr, csTmp, hv_sender_name.len);
		ind_sender_name = 0;
DEBUGLOG(("AddDetail: sender_name = [%.*s]\n",hv_sender_name.len, hv_sender_name.arr));
	}

	if (GetField_CString(hRls,"txn_ref_num",&csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		strncpy((char*)hv_txn_ref_num.arr, csTmp, hv_txn_ref_num.len);
		ind_txn_ref_num = 0;
DEBUGLOG(("AddDetail: txn_ref_num = [%.*s]\n",hv_txn_ref_num.len, hv_txn_ref_num.arr));
	}

	if (GetField_CString(hRls,"keywords_mapping",&csTmp)) {
		hv_keywords_mapping.len = strlen(csTmp);
		strncpy((char*)hv_keywords_mapping.arr, csTmp, hv_keywords_mapping.len);
		ind_keywords_mapping = 0;
DEBUGLOG(("AddDetail: keywords_mapping = [%.*s]\n",hv_keywords_mapping.len, hv_keywords_mapping.arr));
	}

	if (GetField_CString(hRls,"balance",&csTmp)) { /***/
		hv_balance = atof(csTmp);
		ind_balance = 0;
DEBUGLOG(("AddDetail: balance = [%.2f]\n",hv_balance));
	} else if (GetField_Double(hRls,"balance",&dTmp)) { /***/
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

	if (GetField_CString(hRls,"txn_amount",&csTmp)) { /***/
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: txn_amount = [%.2f]\n",hv_txn_amount));
	} else if (GetField_Double(hRls,"txn_amount",&dTmp)) { /***/
		hv_txn_amount = dTmp;
		ind_txn_amount = 0;
DEBUGLOG(("AddDetail: txn_amount = [%.2f]\n",hv_txn_amount));
	}

	if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		strncpy((char*)hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("AddDetail: txn_ccy = [%.*s]\n",hv_txn_ccy.len, hv_txn_ccy.arr));
	}

	if (GetField_CString(hRls,"create_user",&csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("AddDetail: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr, csTmp, hv_raw_date.len);
		ind_raw_date = 0;
DEBUGLOG(("AddDetail: raw_date = [%.*s]\n",hv_raw_date.len,hv_raw_date.arr));
	}

	if (GetField_CString(hRls,"raw_time",&csTmp)) {
		hv_raw_time.len = strlen(csTmp);
		strncpy((char*)hv_raw_time.arr, csTmp, hv_raw_time.len);
		ind_raw_time = 0;
DEBUGLOG(("AddDetail: raw_time = [%.*s]\n",hv_raw_time.len,hv_raw_time.arr));
	}

	if (GetField_CString(hRls,"sender_baid_name",&csTmp)) {
                hv_sender_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_sender_baid_name.arr, csTmp, hv_sender_baid_name.len);
                ind_sender_baid_name = 0;
DEBUGLOG(("AddDetail: sender_baid_name = [%.*s]\n",hv_sender_baid_name.len, hv_sender_baid_name.arr));
        }

        if (GetField_CString(hRls,"recipient_baid_name",&csTmp)) {
                hv_recipient_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_recipient_baid_name.arr, csTmp, hv_recipient_baid_name.len);
                ind_recipient_baid_name = 0;
DEBUGLOG(("AddDetail: recipient_baid_name = [%.*s]\n",hv_recipient_baid_name.len, hv_recipient_baid_name.arr));
        }

	if (GetField_CString(hRls,"client_name",&csTmp)) {
                hv_client_name.len = strlen(csTmp);
                strncpy((char*)hv_client_name.arr, csTmp, hv_client_name.len);
                ind_client_name = 0;
DEBUGLOG(("AddDetail: client_name = [%.*s]\n",hv_client_name.len, hv_client_name.arr));
        }

	if (GetField_CString(hRls, "txn_location", &csTmp)) {
		hv_txn_location.len = strlen(csTmp);
		strncpy((char*)hv_txn_location.arr, csTmp, hv_txn_location.len);
		ind_txn_location = 0;
DEBUGLOG(("AddDetail: txn_location = [%.*s]\n", hv_txn_location.len, hv_txn_location.arr));
	}

	if (GetField_CString(hRls, "txn_type", &csTmp)) {
		hv_txn_type.len = strlen(csTmp);
		strncpy((char*)hv_txn_type.arr, csTmp, hv_txn_type.len);
		ind_txn_type = 0;
DEBUGLOG(("AddDetail: txn_type = [%.*s]\n", hv_txn_type.len, hv_txn_type.arr));
	}

	if (GetField_CString(hRls, "txn_reference", &csTmp)) {
		hv_txn_reference.len = strlen(csTmp);
		strncpy((char*)hv_txn_reference.arr, csTmp, hv_txn_reference.len);
		ind_txn_reference = 0;
DEBUGLOG(("AddDetail: txn_reference = [%.*s]\n", hv_txn_reference.len, hv_txn_reference.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_detail_ins_v3(
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
						:hv_create_user:ind_create_user,
						:hv_raw_date:ind_raw_date,
						:hv_raw_time:ind_raw_time,
						:hv_sender_baid_name:ind_sender_baid_name,
						:hv_recipient_baid_name:ind_recipient_baid_name,
						:hv_client_name:ind_client_name,
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
   "begin :hv_return_value := sp_ol_statement_detail_ins_v3 ( :hv_stat_txn_i\
d:ind_stat_txn_id , :hv_file_id:ind_file_id , :hv_int_bank_code:ind_int_bank\
_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid , :hv_statem\
ent_seq:ind_statement_seq , :hv_txn_id:ind_txn_id , :hv_statement_ref:ind_st\
atement_ref , :hv_input_channel:ind_input_channel , :hv_statement_date:ind_s\
tatement_date , :hv_statement_time:ind_statement_time , :hv_tfr_bank_name:in\
d_tfr_bank_name , :hv_tfr_bank_acct_num:ind_tfr_bank_acct_num , :hv_tfr_type\
:ind_tfr_type , :hv_tfr_channel:ind_tfr_channel , :hv_tfr_text:ind_tfr_text \
, :hv_tfr_customer_text:ind_tfr_customer_text , :hv_sender_name:ind_sender_n\
ame , :hv_txn_ref_num:ind_txn_ref_num , :hv_keywords_mapping:ind_keywords_ma\
pping , :hv_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_txn_amount\
:ind_txn_amount , :hv_txn_ccy:ind_txn_ccy , :hv_create_user:ind_create_user \
, :hv_raw_date:ind_raw_date , :hv_raw_time:ind_raw_time , :hv_sender_baid_na\
me:ind_sender_baid_name , :hv_recipient_");
 sqlstm.stmt = "baid_name:ind_recipient_baid_name , :hv_client_name:ind_cli\
ent_name , :hv_txn_location:ind_txn_location , :hv_txn_type:ind_txn_type , :h\
v_txn_reference:ind_txn_reference ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )532;
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
 sqlstm.sqhstl[14] = (unsigned long )642;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[15] = (unsigned long )642;
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
 sqlstm.sqhstl[17] = (unsigned long )642;
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
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[26] = (unsigned long )52;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_raw_date;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[27] = (unsigned long )52;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_raw_time;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_sender_baid_name;
 sqlstm.sqhstl[28] = (unsigned long )152;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_sender_baid_name;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_recipient_baid_name;
 sqlstm.sqhstl[29] = (unsigned long )152;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_recipient_baid_name;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_client_name;
 sqlstm.sqhstl[30] = (unsigned long )52;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_client_name;
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
ERRLOG("OLStatement_AddDetail: SP_OTHER_ERR\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_AddDetail: SP_ERR\n");
DEBUGLOG(("AddDetail: SP_ERR\n"));
		return PD_ERR;
	}

addetail_error:
DEBUGLOG(("addetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement_AddDetail: SP_INTERNAL_ERR\n");
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
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )683;
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
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )702;
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
	if (GetField_CString(hText, "req_bank_bal", &csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
	} else {
		hv_balance = 0.0;
		ind_balance = 0;
	}
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
		ind_txn_amount = 0;
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
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_sms_insert_new ( \
:hv_stat_txn_id:ind_stat_txn_id , :hv_int_bank_code:ind_int_bank_code , :hv_b\
ank_acct_num:ind_bank_acct_num , :hv_baid:ind_baid , :hv_input_channel:ind_in\
put_channel , :hv_statement_date:ind_statement_date , :hv_statement_time:ind_\
statement_time , :hv_balance:ind_balance , :hv_amt_type:ind_amt_type , :hv_tx\
n_amount:ind_txn_amount , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )717;
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

		/* varchar		hv_tfr_type[PD_TFR_TYPE_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_type;

		/* varchar		hv_tfr_channel[PD_TFR_CHANNEL_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_channel;

		/* varchar		hv_tfr_text[PD_TFR_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_tfr_text;

		/* varchar		hv_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_tfr_customer_text;

		/* varchar		hv_sender_name[PD_SENDER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_TXN_REF_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_txn_ref_num;

		/* varchar		hv_keywords_mapping[PD_KEYWORDS_MAPPING_LEN]; */ 
struct { unsigned short len; unsigned char arr[401]; } hv_keywords_mapping;

		double		hv_balance;
		/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		/* varchar		hv_raw_date[PD_STMT_RAW_DATE]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_raw_date;

		/* varchar		hv_raw_time[PD_STMT_RAW_TIME]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_raw_time;

		/* varchar		hv_sender_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_sender_baid_name;

		/* varchar		hv_recipient_baid_name[PD_BAID_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_recipient_baid_name;

		/* varchar		hv_client_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_client_name;

		/* varchar		hv_txn_location[PD_TXN_LOCATION_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_location;

		/* varchar		hv_txn_type[PD_TXN_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_type;

		/* varchar		hv_txn_reference[PD_TXN_REFERENCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[640]; } hv_txn_reference;


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
		short		ind_raw_date = -1;
		short		ind_raw_time = -1;
		short		ind_sender_baid_name = -1;
		short		ind_recipient_baid_name = -1;
		short		ind_client_name = -1;
		short		ind_txn_location = -1;
		short		ind_txn_type = -1;
		short		ind_txn_reference = -1;

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
	if (GetField_Int(hRls, "statement_seq", &iTmp)) {
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

/* raw_date */
	if (GetField_CString(hRls,"raw_date",&csTmp)) {
		hv_raw_date.len = strlen(csTmp);
		strncpy((char*)hv_raw_date.arr, csTmp, hv_raw_date.len);
		ind_raw_date = 0;
DEBUGLOG(("AddDetail: raw_date = [%.*s]\n",hv_raw_date.len,hv_raw_date.arr));
	}

/* raw_time */
	if (GetField_CString(hRls,"raw_time",&csTmp)) {
		hv_raw_time.len = strlen(csTmp);
		strncpy((char*)hv_raw_time.arr, csTmp, hv_raw_time.len);
		ind_raw_time = 0;
DEBUGLOG(("AddDetail: raw_time = [%.*s]\n",hv_raw_time.len,hv_raw_time.arr));
	}

/* sender_baid_name */
        if (GetField_CString(hRls, "sender_baid_name", &csTmp)) {
                hv_sender_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_sender_baid_name.arr,csTmp,hv_sender_baid_name.len);
                ind_sender_baid_name = 0;
DEBUGLOG(("UpdateSmsDetail: sender_baid_name = [%.*s]\n", hv_sender_baid_name.len, hv_sender_baid_name.arr));
        }

/* recipient_baid_name */
        if (GetField_CString(hRls, "recipient_baid_name", &csTmp)) {
                hv_recipient_baid_name.len = strlen(csTmp);
                strncpy((char*)hv_recipient_baid_name.arr,csTmp,hv_recipient_baid_name.len);
                ind_recipient_baid_name = 0;
DEBUGLOG(("UpdateSmsDetail: recipient_baid_name = [%.*s]\n", hv_recipient_baid_name.len, hv_recipient_baid_name.arr));
        }

/* client_name */
        if (GetField_CString(hRls, "client_name", &csTmp)) {
                hv_client_name.len = strlen(csTmp);
                strncpy((char*)hv_client_name.arr,csTmp,hv_client_name.len);
                ind_client_name = 0;
DEBUGLOG(("UpdateSmsDetail: client_name = [%.*s]\n", hv_client_name.len, hv_client_name.arr));
        }

/* txn_location */
	if (GetField_CString(hRls, "txn_location", &csTmp)) {
		hv_txn_location.len = strlen(csTmp);
		strncpy((char*)hv_txn_location.arr, csTmp, hv_txn_location.len);
		ind_txn_location = 0;
DEBUGLOG(("UpdateSmsDetail: txn_location = [%.*s]\n", hv_txn_location.len, hv_txn_location.arr));
	}

/* txn_type */
	if (GetField_CString(hRls, "txn_type", &csTmp)) {
		hv_txn_type.len = strlen(csTmp);
		strncpy((char*)hv_txn_type.arr, csTmp, hv_txn_type.len);
		ind_txn_type = 0;
DEBUGLOG(("UpdateSmsDetail: txn_type = [%.*s]\n", hv_txn_type.len, hv_txn_type.arr));
	}

/* txn_reference */
	if (GetField_CString(hRls, "txn_reference", &csTmp)) {
		hv_txn_reference.len = strlen(csTmp);
		strncpy((char*)hv_txn_reference.arr, csTmp, hv_txn_reference.len);
		ind_txn_reference = 0;
DEBUGLOG(("UpdateSmsDetail: txn_reference = [%.*s]\n", hv_txn_reference.len, hv_txn_reference.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_statement_sms_upd_v3(
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
						:hv_update_user:ind_update_user,
						:hv_raw_date:ind_raw_date,
						:hv_raw_time:ind_raw_time,
						:hv_sender_baid_name:ind_sender_baid_name,
						:hv_recipient_baid_name:ind_recipient_baid_name,
						:hv_client_name:ind_client_name,
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
   "begin :hv_return_value := sp_ol_statement_sms_upd_v3 ( :hv_stat_txn_id:i\
nd_stat_txn_id , :hv_int_bank_code:ind_int_bank_code , :hv_bank_acct_num:ind\
_bank_acct_num , :hv_statement_date:ind_statement_date , :hv_amt_type:ind_am\
t_type , :hv_txn_amount:ind_txn_amount , :hv_file_id:ind_file_id , :hv_state\
ment_seq:ind_statement_seq , :hv_statement_ref:ind_statement_ref , :hv_state\
ment_time:ind_statement_time , :hv_tfr_bank_name:ind_tfr_bank_name , :hv_tfr\
_bank_acct_num:ind_tfr_bank_acct_num , :hv_tfr_type:ind_tfr_type , :hv_tfr_c\
hannel:ind_tfr_channel , :hv_tfr_text:ind_tfr_text , :hv_tfr_customer_text:i\
nd_tfr_customer_text , :hv_sender_name:ind_sender_name , :hv_txn_ref_num:ind\
_txn_ref_num , :hv_keywords_mapping:ind_keywords_mapping , :hv_balance:ind_b\
alance , :hv_update_user:ind_update_user , :hv_raw_date:ind_raw_date , :hv_r\
aw_time:ind_raw_time , :hv_sender_baid_name:ind_sender_baid_name , :hv_recip\
ient_baid_name:ind_recipient_baid_name , :hv_client_name:ind_client_name , :\
hv_txn_location:ind_txn_location , :hv_t");
 sqlstm.stmt = "xn_type:ind_txn_type , :hv_txn_reference:ind_txn_reference \
) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )780;
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
 sqlstm.sqhstl[13] = (unsigned long )642;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_tfr_type;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_tfr_channel;
 sqlstm.sqhstl[14] = (unsigned long )642;
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
 sqlstm.sqhstl[16] = (unsigned long )642;
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
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_raw_date;
 sqlstm.sqhstl[22] = (unsigned long )52;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_raw_date;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_raw_time;
 sqlstm.sqhstl[23] = (unsigned long )52;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_raw_time;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_sender_baid_name;
 sqlstm.sqhstl[24] = (unsigned long )152;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_sender_baid_name;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_recipient_baid_name;
 sqlstm.sqhstl[25] = (unsigned long )152;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_recipient_baid_name;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_client_name;
 sqlstm.sqhstl[26] = (unsigned long )52;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_client_name;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_txn_location;
 sqlstm.sqhstl[27] = (unsigned long )642;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_txn_location;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_txn_type;
 sqlstm.sqhstl[28] = (unsigned long )642;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_txn_type;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_txn_reference;
 sqlstm.sqhstl[29] = (unsigned long )642;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_txn_reference;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
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
ERRLOG("OLStatement_UpdateSmsDetail: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateSmsDetail: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateSmsDetail: SP_ERR\n");
DEBUGLOG(("UpdateSmsDetail: SP_ERR\n"));
		return PD_ERR;
	}

updatesmsdetail_error:
DEBUGLOG(("updatesmsdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_UpdateSmsDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateSmsDetail: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
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
DEBUGLOG(("MatchStmt int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

// amt_type
	if (GetField_CString(hRls, "amt_type", &csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("MatchStmt amt_type = [%.*s]\n", hv_amt_type.len, hv_amt_type.arr));
	}

//// common : end


//// for bank stmt search existing sms : start

// bank_acct_num
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("MatchStmt bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

// statement_date
	if (GetField_CString(hRls, "statement_date", &csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		strncpy((char*)hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("MatchStmt txn_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));

		iSearchChannel = 2;
	}

// statement_time
	if (GetField_CString(hRls, "statement_time", &csTmp)) {
		hv_txn_time.len = strlen(csTmp);
		strncpy((char*)hv_txn_time.arr, csTmp, hv_txn_time.len);
		ind_txn_time = 0;
DEBUGLOG(("MatchStmt txn_time = [%.*s]\n", hv_txn_time.len, hv_txn_time.arr));
	}

// sms_match_threshold
	if (GetField_Int(hRls, "sms_match_threshold", &iTmp)) {
		hv_sms_match_threshold = iTmp;
		ind_sms_match_threshold = 0;
DEBUGLOG(("MatchStmt sms_match_threshold = [%d] mins\n",hv_sms_match_threshold));

		iSearchChannel = 3;
	}

// SYS_DATE
	if (GetField_CString(hRls, "SYS_DATE", &csTmp)) {
		hv_sys_date.len = strlen(csTmp);
		strncpy((char*)hv_sys_date.arr, csTmp, hv_sys_date.len);
		ind_sys_date = 0;
DEBUGLOG(("MatchStmt sys_date = [%.*s]\n", hv_sys_date.len, hv_sys_date.arr));
	}

// SYS_TIME
	if (GetField_CString(hRls, "SYS_TIME", &csTmp)) {
		hv_sys_time.len = strlen(csTmp);
		strncpy((char*)hv_sys_time.arr, csTmp, hv_sys_time.len);
		ind_sys_time = 0;
DEBUGLOG(("MatchStmt sys_time = [%.*s]\n", hv_sys_time.len, hv_sys_time.arr));
	}

// txn_amount
	if (GetField_CString(hRls, "txn_amount", &csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("MatchStmt txn_amount = [%.2f]\n", hv_txn_amount));
	}

//// for bank stmt search existing sms : end



//// for sms search existing bank stmt : start

// req_bank_acc
	if (GetField_CString(hRls, "full_bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("MatchStmt bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

// req_bank_date
	if (GetField_CString(hRls, "req_bank_date", &csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		strncpy((char*)hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("MatchStmt txn_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));
	}

// req_bank_amount
	if (GetField_CString(hRls, "req_bank_amount", &csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("MatchStmt txn_amount = [%.2f]\n", hv_txn_amount));
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
				AND	olsd_statement_ref is null)
			WHERE ROWNUM = 1; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_timest\
amp >= to_date ( :b8:b9 || :b10:b11 , 'YYYYMMDDHH24MISS' ) - :b12:b13 / 1440 \
AND olsd_statement_timestamp <= to_date ( :b8:b15 || :b10:b17 , 'YYYYMMDDHH24\
MISS' ) AND olsd_int_bank_code = :b18:b19 AND olsd_bank_acct_num = :b20:b21 A\
ND olsd_statement_ref is null ) WHERE ROWNUM = 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )915;
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
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_date =\
 :b8:b9 AND olsd_int_bank_code = :b10:b11 AND olsd_bank_acct_num = :b12:b13 A\
ND olsd_statement_ref is null ) WHERE ROWNUM = 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )974;
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
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select olsd_stat_txn_id , olsd_txn_id into :b0:b1 , :b2:b3\
 FROM ( SELECT olsd_stat_txn_id , olsd_txn_id FROM ol_statement_detail WHERE \
olsd_txn_amount = :b4:b5 AND olsd_amt_type = :b6:b7 AND olsd_statement_date =\
 replace ( :b8:b9 , '-' , '' ) AND olsd_int_bank_code = :b10:b11 AND olsd_ban\
k_acct_num = :b12:b13 ) WHERE ROWNUM = 1 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1017;
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
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLStatement_MatchStmt: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("MatchStmt: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
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

int GetStmtHdr(const char* csFileId, hash_t* hStmtHdr)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmthdr_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar		v_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_filename;

		/* varchar		v_int_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_org_filename[PD_UPLOAD_FILENAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_org_filename;

		/* varchar		v_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_id;

		int		v_message_code;
		int		v_ver;
		char		v_status;

		short		ind_file_id = -1;
		short		ind_filename = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_baid = -1;
		short		ind_org_filename = -1;
		short		ind_format_id = -1;
		short		ind_message_code = -1;
		short		ind_ver = -1;
		short		ind_status = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	memcpy(hv_file_id.arr, csFileId, hv_file_id.len);
	ind_file_id = 0;
DEBUGLOG(("GetStmtHdr() file_id = [%.*s]\n", hv_file_id.len, hv_file_id.arr));

	/* EXEC SQL DECLARE c_cursor_getstmthdr CURSOR FOR
		SELECT	OLSH_FILENAME,
			OLSH_INT_BANK_CODE,
			OLSH_BANK_ACCT_NUM,
			OLSH_BAID,
			OLSH_ORG_FILENAME,
			OLSH_FORMAT_ID,
			OLSH_MESSAGE_CODE,
			OLSH_VER,
			OLSH_STATUS
		FROM	OL_STATEMENT_HEADER
		WHERE	OLSH_FILE_ID = :hv_file_id:ind_file_id; */ 


	/* EXEC SQL OPEN c_cursor_getstmthdr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0015;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1060;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
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
 if (sqlca.sqlcode < 0) goto getstmthdr_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getstmthdr
		INTO	:v_filename:ind_filename,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_baid:ind_baid,
			:v_org_filename:ind_org_filename,
			:v_format_id:ind_format_id,
			:v_message_code:ind_message_code,
			:v_ver:ind_ver,
			:v_status:ind_status; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1079;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_filename;
  sqlstm.sqhstl[0] = (unsigned long )103;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_filename;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_baid;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_org_filename;
  sqlstm.sqhstl[4] = (unsigned long )103;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_org_filename;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_format_id;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_format_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_message_code;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_message_code;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_ver;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_ver;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[8] = (unsigned long )1;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_status;
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
  if (sqlca.sqlcode < 0) goto getstmthdr_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		// filename
		if (ind_filename >= 0) {
			v_filename.arr[v_filename.len] = '\0';
			PutField_CString(hStmtHdr, "filename", (const char*)v_filename.arr);
			PutField_CString(hStmtHdr, "in_file_name", (const char*)v_filename.arr);
DEBUGLOG(("GetStmtHdr filename = [%s]\n", (const char*)v_filename.arr));
		}

		// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hStmtHdr, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetStmtHdr int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
		}

		// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hStmtHdr, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetStmtHdr bank_acct_num = [%s]\n", (const char*)v_bank_acct_num.arr));
		}

		// baid
		if (ind_baid >= 0) {
			v_baid.arr[v_baid.len] = '\0';
			PutField_CString(hStmtHdr, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetStmtHdr baid = [%s]\n", (const char*)v_baid.arr));
		}

		// org_filename
		if (ind_org_filename >= 0) {
			v_org_filename.arr[v_org_filename.len] = '\0';
			PutField_CString(hStmtHdr, "org_filename", (const char*)v_org_filename.arr);
DEBUGLOG(("GetStmtHdr org_filename = [%s]\n", (const char*)v_org_filename.arr));
		}

		// format_id
		if (ind_format_id >= 0) {
			v_format_id.arr[v_format_id.len] = '\0';
			PutField_CString(hStmtHdr, "format_id", (const char*)v_format_id.arr);
DEBUGLOG(("GetStmtHdr format_id = [%s]\n", (const char*)v_format_id.arr));
		}

		// message_code
		if (ind_message_code >= 0) {
			PutField_Int(hStmtHdr, "message_code", v_message_code);
DEBUGLOG(("GetStmtHdr message_code = [%d]\n", v_message_code));
		}

		// ver
		if (ind_ver >= 0) {
			PutField_Int(hStmtHdr, "ver", v_ver);
DEBUGLOG(("GetStmtHdr ver = [%d]\n", v_ver));
		}

		// status
		if (ind_status >= 0) {
			PutField_Char(hStmtHdr, "status", v_status);
DEBUGLOG(("GetStmtHdr status = [%c]\n", v_status));
		}

	}

	/* EXEC SQL CLOSE c_cursor_getstmthdr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1130;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmthdr_error;
}



DEBUGLOG(("GetStmtHdr() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmthdr_error:
DEBUGLOG(("getstmthdr_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getstmthdr_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getstmthdr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1145;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmthdr_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

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

		/* varchar v_tfr_type[PD_TFR_TYPE_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_type;

		/* varchar v_tfr_channel[PD_TFR_CHANNEL_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_channel;

		/* varchar v_tfr_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_text;

		/* varchar v_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_customer_text;

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

		/* varchar v_sender_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_sender_baid_name;

		/* varchar v_recipient_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_recipient_baid_name;

		/* varchar v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;


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
		short ind_sender_baid_name = -1;
		short ind_recipient_baid_name = -1;
		short ind_client_name = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_stmt_txn_id.len = strlen(csStmtTxnId);
	memcpy(hv_stmt_txn_id.arr, csStmtTxnId, hv_stmt_txn_id.len);
	ind_stmt_txn_id = 0;
DEBUGLOG(("GetStmtDtl() statement_txn_id = [%.*s]\n", hv_stmt_txn_id.len, hv_stmt_txn_id.arr));

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
                        olsd_statement_ref,
                        olsd_sender_baid_name,
                        olsd_recipient_baid_name,
                        olsd_client_name
		FROM	ol_statement_detail
		WHERE	olsd_stat_txn_id = :hv_stmt_txn_id:ind_stmt_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getstmtdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0016;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1160;
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
			:v_stmt_ref:ind_stmt_ref,
			:v_sender_baid_name:ind_sender_baid_name,
			:v_recipient_baid_name:ind_recipient_baid_name,
			:v_client_name:ind_client_name; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1179;
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
  sqlstm.sqhstl[7] = (unsigned long )643;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_tfr_type;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_tfr_channel;
  sqlstm.sqhstl[8] = (unsigned long )643;
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
  sqlstm.sqhstl[10] = (unsigned long )643;
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
  sqlstm.sqhstv[17] = (unsigned char  *)&v_sender_baid_name;
  sqlstm.sqhstl[17] = (unsigned long )153;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_sender_baid_name;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_recipient_baid_name;
  sqlstm.sqhstl[18] = (unsigned long )153;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_recipient_baid_name;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[19] = (unsigned long )53;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_client_name;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
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

		// sender_baid_name
                if (ind_sender_baid_name >= 0) {
                        v_sender_baid_name.arr[v_sender_baid_name.len] = '\0';
                        PutField_CString(hStmtDtl, "sender_baid_name", (const char*)v_sender_baid_name.arr);
DEBUGLOG(("GetStmtDtl sender_baid_name = [%s]\n", (const char*)v_sender_baid_name.arr));
                }

		// recipient_baid_name
                if (ind_recipient_baid_name >= 0) {
                        v_recipient_baid_name.arr[v_recipient_baid_name.len] = '\0';
                        PutField_CString(hStmtDtl, "recipient_baid_name", (const char*)v_recipient_baid_name.arr);
DEBUGLOG(("GetStmtDtl recipient_baid_name = [%s]\n", (const char*)v_recipient_baid_name.arr));
                }

		// client_name
                if (ind_client_name >= 0) {
                        v_client_name.arr[v_client_name.len] = '\0';
                        PutField_CString(hStmtDtl, "client_name", (const char*)v_client_name.arr);
DEBUGLOG(("GetStmtDtl client_name = [%s]\n", (const char*)v_client_name.arr));
                }
	}

	/* EXEC SQL CLOSE c_cursor_getstmtdtl; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1274;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmtdtl_error;
}



DEBUGLOG(("GetStmtDtl() Normal Exit! iRet = [%d]\n", iRet));
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
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1289;
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


int CheckFileIdExist(const char* csFileId)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                //varchar hv_file_id[PD_TXN_SEQ_LEN];
                double	v_file_id;
                int     v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


/*
        hv_file_id.len = strlen(csFileId);
        strncpy((char*)hv_file_id.arr,csFileId,hv_file_id.len);
DEBUGLOG(("CheckFileIdExist file_id = [%s]\n",csFileId));
*/

	v_file_id = atof(csFileId);
DEBUGLOG(("CheckFileIdExist file_id = [%s]\n",csFileId));

        /* EXEC SQL        SELECT  COUNT(*)
                        INTO    :v_cnt
                        FROM    OL_STATEMENT_HEADER
                        WHERE   OLSH_FILE_ID = :v_file_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_HEADER\
 WHERE OLSH_FILE_ID = :b1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1304;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&v_file_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
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
        if (sqlca.sqlcode < 0) goto checkheader_error;
}



        if (v_cnt>0) {
                iRet = FOUND;
DEBUGLOG(("CheckFileIdExist() file_id [%s] FOUND\n",csFileId));
        } else {
                iRet = NOT_FOUND;
DEBUGLOG(("CheckFileIdExist() file_id [%s] NOT FOUND\n",csFileId));
        }

DEBUGLOG(("CheckFileIdExist() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkheader_error:
DEBUGLOG(("checkheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetTxnIdByStatTxnId(hash_t *hRls)
{
	int iRet = PD_OK;
	char* csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnid_error; */ 

	/* ExEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_stat_txn_id = -1;
		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "stat_txn_id", &csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("GetTxnIdByStatTxnId() stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));
	}

	/* EXEC SQL
		SELECT	olsd_txn_id
		INTO	v_txn_id:ind_txn_id
		FROM	ol_statement_detail
		WHERE	olsd_stat_txn_id = :hv_stat_txn_id:ind_stat_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select olsd_txn_id INTO :b0:b1 FROM ol_statement_detail WHE\
RE olsd_stat_txn_id = :b2:b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1327;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 if (sqlca.sqlcode < 0) goto gettxnid_error;
}



	if (ind_txn_id >= 0) {
		v_txn_id.arr[v_txn_id.len] = '\0';
		PutField_CString(hRls, "txn_id", (char*)v_txn_id.arr);
DEBUGLOG(("GetTxnIdByStatTxnId() txn_id = [%s]\n", (char*)v_txn_id.arr));
	} else {
DEBUGLOG(("GetTxnIdByStatTxnId() txn_id not found\n"));
		iRet = PD_ERR;
	}

DEBUGLOG(("GetTxnIdByStatTxnId() Normal Exit iRet = [%d]\n", iRet));

	return iRet;

gettxnid_error:
DEBUGLOG(("gettxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement:: GetTxnIdByStatTxnId: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetStmtDtlByBAIDTxnId(const char* csBAIDTxnId, hash_t* hStmtDtl)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmtdtlbaid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id;


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

		/* varchar v_tfr_type[PD_TFR_TYPE_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_type;

		/* varchar v_tfr_channel[PD_TFR_CHANNEL_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_channel;

		/* varchar v_tfr_text[PD_TFR_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_tfr_text;

		/* varchar v_tfr_customer_text[PD_TFR_CUSTOMER_TEXT_LONG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[641]; } v_tfr_customer_text;

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

		/* varchar v_sender_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_sender_baid_name;

		/* varchar v_recipient_baid_name[PD_BAID_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_recipient_baid_name;

		/* varchar v_client_name[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar v_format_id[PD_FORMAT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_format_id;


		short ind_baid_txn_id = -1;
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
		short ind_sender_baid_name = -1;
		short ind_recipient_baid_name = -1;
		short ind_client_name = -1;
		short ind_format_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid_txn_id.len = strlen(csBAIDTxnId);
	memcpy(hv_baid_txn_id.arr, csBAIDTxnId, hv_baid_txn_id.len);
	ind_baid_txn_id = 0;
DEBUGLOG(("GetStmtDtlByBAIDTxnId() baid_txn_id = [%.*s]\n", hv_baid_txn_id.len, hv_baid_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getstmtdtlbaid CURSOR FOR
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
                        olsd_statement_ref,
			olsd_sender_baid_name,
			olsd_recipient_baid_name,
			olsd_client_name,
			olsh_format_id
		FROM	ol_statement_detail
		LEFT JOIN ol_statement_header
		ON	olsd_file_id = olsh_file_id
		WHERE	olsd_stat_txn_id = (select obt_stat_txn_id 
                                            from ol_baid_txn
                                            where obt_txn_id = :hv_baid_txn_id:ind_baid_txn_id
                                           ); */ 


	/* EXEC SQL OPEN c_cursor_getstmtdtlbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0019;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1350;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_baid_txn_id;
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
 if (sqlca.sqlcode < 0) goto getstmtdtlbaid_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getstmtdtlbaid
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
			:v_stmt_ref:ind_stmt_ref,
			:v_sender_baid_name:ind_sender_baid_name,
			:v_recipient_baid_name:ind_recipient_baid_name,
			:v_client_name:ind_client_name,
			:v_format_id:ind_format_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1369;
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
  sqlstm.sqhstl[7] = (unsigned long )643;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_tfr_type;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_tfr_channel;
  sqlstm.sqhstl[8] = (unsigned long )643;
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
  sqlstm.sqhstl[10] = (unsigned long )643;
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
  sqlstm.sqhstv[17] = (unsigned char  *)&v_sender_baid_name;
  sqlstm.sqhstl[17] = (unsigned long )153;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_sender_baid_name;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_recipient_baid_name;
  sqlstm.sqhstl[18] = (unsigned long )153;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_recipient_baid_name;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[19] = (unsigned long )53;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_client_name;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_format_id;
  sqlstm.sqhstl[20] = (unsigned long )23;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_format_id;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getstmtdtlbaid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		// int_bank_code
		if (ind_int_bank_code >= 0) {
			v_int_bank_code.arr[v_int_bank_code.len] = '\0';
			PutField_CString(hStmtDtl, "int_bank_code", (const char*)v_int_bank_code.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId int_bank_code = [%s]\n", (const char*)v_int_bank_code.arr));
		}

		// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hStmtDtl, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId bank_acct_num = [%s]\n", (const char*)v_bank_acct_num.arr));
		}

		// statement_date
		if (ind_stmt_date >= 0) {
			v_stmt_date.arr[v_stmt_date.len] = '\0';
			PutField_CString(hStmtDtl, "statement_date", (const char*)v_stmt_date.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId statement_date = [%s]\n", (const char*)v_stmt_date.arr));
		}

		// statement_time
		if (ind_stmt_time >= 0) {
			v_stmt_time.arr[v_stmt_time.len] = '\0';
			PutField_CString(hStmtDtl, "statement_time", (const char*)v_stmt_time.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId statement_time = [%s]\n", (const char*)v_stmt_time.arr));
		}

		// statement_timestamp
		if (ind_stmt_timestamp >= 0) {
			v_stmt_timestamp.arr[v_stmt_timestamp.len] = '\0';
			PutField_CString(hStmtDtl, "statement_timestamp", (const char*)v_stmt_timestamp.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId statement_timestamp = [%s]\n", (const char*)v_stmt_timestamp.arr));
		}

		// tfr_bank_name
		if (ind_tfr_bank_name >= 0) {
			v_tfr_bank_name.arr[v_tfr_bank_name.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_bank_name", (const char*)v_tfr_bank_name.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_bank_name = [%s]\n", (const char*)v_tfr_bank_name.arr));
		}

		// tfr_bank_acct_num
		if (ind_tfr_bank_acct_num >= 0) {
			v_tfr_bank_acct_num.arr[v_tfr_bank_acct_num.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_bank_acct_num", (const char*)v_tfr_bank_acct_num.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_bank_acct_num = [%s]\n", (const char*)v_tfr_bank_acct_num.arr));
		}

		// tfr_type
		if (ind_tfr_type >= 0) {
			v_tfr_type.arr[v_tfr_type.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_type", (const char*)v_tfr_type.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_type = [%s]\n", (const char*)v_tfr_type.arr));
		}

		// tfr_channel
		if (ind_tfr_channel >= 0) {
			v_tfr_channel.arr[v_tfr_channel.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_channel", (const char*)v_tfr_channel.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_channel = [%s]\n", (const char*)v_tfr_channel.arr));
		}

		// tfr_text
		if (ind_tfr_text >= 0) {
			v_tfr_text.arr[v_tfr_text.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_text", (const char*)v_tfr_text.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_text = [%s]\n", (const char*)v_tfr_text.arr));
		}

		// tfr_customer_text
		if (ind_tfr_customer_text >= 0) {
			v_tfr_customer_text.arr[v_tfr_customer_text.len] = '\0';
			PutField_CString(hStmtDtl, "tfr_customer_text", (const char*)v_tfr_customer_text.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId tfr_customer_text = [%s]\n", (const char*)v_tfr_customer_text.arr));
		}

		// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(hStmtDtl, "sender_name", (const char*)v_sender_name.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId sender_name = [%s]\n", (const char*)v_sender_name.arr));
		}

		// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(hStmtDtl, "txn_ref_num", (const char*)v_txn_ref_num.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId txn_ref_num = [%s]\n", (const char*)v_txn_ref_num.arr));
		}

		// amt_type
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			PutField_CString(hStmtDtl, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId amt_type = [%s]\n", (const char*)v_amt_type.arr));
		}

		// txn_amount
		if (ind_txn_amount >= 0) {
			v_txn_amount.arr[v_txn_amount.len] = '\0';
			PutField_CString(hStmtDtl, "txn_amount", (const char*)v_txn_amount.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId txn_amount = [%s]\n", (const char*)v_txn_amount.arr));
		}

		// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(hStmtDtl, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId txn_ccy = [%s]\n", (const char*)v_txn_ccy.arr));
		}

		// statement_ref
		if (ind_stmt_ref >= 0) {
			v_stmt_ref.arr[v_stmt_ref.len] = '\0';
			PutField_CString(hStmtDtl, "stmt_ref", (const char*)v_stmt_ref.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId stmt_ref= [%s]\n", (const char*)v_stmt_ref.arr));
		}
	
		// sender_baid_name
                if (ind_sender_baid_name >= 0) {
                        v_sender_baid_name.arr[v_sender_baid_name.len] = '\0';
                        PutField_CString(hStmtDtl, "sender_baid_name", (const char*)v_sender_baid_name.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId sender_baid_name = [%s]\n", (const char*)v_sender_baid_name.arr));
                }

		// recipient_baid_name
                if (ind_recipient_baid_name >= 0) {
                        v_recipient_baid_name.arr[v_recipient_baid_name.len] = '\0';
                        PutField_CString(hStmtDtl, "recipient_baid_name", (const char*)v_recipient_baid_name.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId recipient_baid_name = [%s]\n", (const char*)v_recipient_baid_name.arr));
                }

		// client_name
                if (ind_client_name >= 0) {
                        v_client_name.arr[v_client_name.len] = '\0';
                        PutField_CString(hStmtDtl, "client_name", (const char*)v_client_name.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId client_name = [%s]\n", (const char*)v_client_name.arr));
                }

		// format_id
		if (ind_format_id >= 0) {
			v_format_id.arr[v_format_id.len] = '\0';
			PutField_CString(hStmtDtl, "format_id", (const char*)v_format_id.arr);
DEBUGLOG(("GetStmtDtlByBAIDTxnId format_id= [%s]\n", (const char*)v_format_id.arr));
		}
	}

	/* EXEC SQL CLOSE c_cursor_getstmtdtlbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1468;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmtdtlbaid_error;
}



DEBUGLOG(("GetStmtDtlByBAIDTxnId() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmtdtlbaid_error:
DEBUGLOG(("getstmtdtlbaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getstmtdtlbaid_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getstmtdtlbaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1483;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getstmtdtlbaid_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetLastBAIDBalance(hash_t *hRls)
{
	int iRet = FOUND;
	int iCnt = 0;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getlastbaidbalance_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_baid;

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
		short	ind_baid = -1;
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
DEBUGLOG(("GetLastBAIDBalance() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("GetLastBAIDBalance() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"baid",&csTmp)) {
                hv_baid.len = strlen(csTmp);
                strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
                ind_baid = 0;
DEBUGLOG(("GetLastBAIDBalance() baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
        }

	/* EXEC SQL DECLARE getlastbaidbalance CURSOR FOR
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
				AND	OLSD_BAID = :hv_baid:ind_baid
				AND	OLSD_STATEMENT_REF IS NOT NULL
				ORDER BY OLSD_FILE_ID DESC, OLSD_STATEMENT_SEQ DESC)
			WHERE	rownum <= 2; */ 


	/* EXEC SQL OPEN getlastbaidbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0020;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1498;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[2] = (unsigned long )23;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_baid;
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
 if (sqlca.sqlcode < 0) goto getlastbaidbalance_error;
}


	for (;;) {
		/* EXEC SQL FETCH getlastbaidbalance
		INTO	:v_txn_id:ind_txn_id,
			:v_balance:ind_balance,
			:v_statement_date:ind_statement_date,
			:v_statement_time:ind_statement_time,
			:v_txn_amount:ind_txn_amount,
			:v_amt_type:ind_amt_type; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 34;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1525;
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
  if (sqlca.sqlcode < 0) goto getlastbaidbalance_error;
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
DEBUGLOG(("GetLastBAIDBalance %d txn_id = [%s]\n",iCnt,(char*)v_txn_id.arr));
		}
/* balance */
		if (ind_balance>=0) {
			if (iCnt == 1) {
				PutField_Double(hRls,"last_balance",v_balance);
			} else if (iCnt == 2) {
				PutField_Double(hRls,"2nd_last_balance",v_balance);
			}
DEBUGLOG(("GetLastBAIDBalance %d balance = [%.2f]\n",iCnt,v_balance));
		}

/* statement_date */
		if (ind_statement_date>=0) {
			v_statement_date.arr[v_statement_date.len]='\0';
			if (iCnt == 1) {
				PutField_CString(hRls,"last_statement_date",(char*)v_statement_date.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls,"2nd_last_statement_date",(char*)v_statement_date.arr);
			}
DEBUGLOG(("GetLastBAIDBalance %d statement_date = [%s]\n",iCnt,(char*)v_statement_date.arr));
		}

/* statement_time */
		if (ind_statement_time>=0) {
			v_statement_time.arr[v_statement_time.len]='\0';
			if (iCnt == 1) {
				PutField_CString(hRls,"last_statement_time",(char*)v_statement_time.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls,"2nd_last_statement_time",(char*)v_statement_time.arr);
			}
DEBUGLOG(("GetLastBAIDBalance %d statement_time = [%s]\n",iCnt,(char*)v_statement_time.arr));
		}

/* txn_amount */
		if (ind_txn_amount >= 0) {
			if (iCnt == 1) {
				PutField_Double(hRls, "last_txn_amount", v_txn_amount);
			} else if (iCnt == 2) {
				PutField_Double(hRls, "2nd_last_txn_amount", v_txn_amount);
			}
DEBUGLOG(("GetLastBAIDBalance %d txn_amount = [%lf]\n",iCnt,v_txn_amount));
		}

/* amt_type */
		if (ind_amt_type >= 0) {
			v_amt_type.arr[v_amt_type.len] = '\0';
			if (iCnt == 1) {
				PutField_CString(hRls, "last_amt_type", (const char*)v_amt_type.arr);
			} else if (iCnt == 2) {
				PutField_CString(hRls, "2nd_last_amt_type", (const char*)v_amt_type.arr);
			}
DEBUGLOG(("GetLastBAIDBalance %d amt_type = [%s]\n",iCnt,(const char*)v_amt_type.arr));
		}

	}
	/* EXEC SQL CLOSE getlastbaidbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1564;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getlastbaidbalance_error;
}



	if (iCnt > 0) {
		iRet = FOUND;
	} else {
		iRet = NOT_FOUND;
	}

DEBUGLOG(("GetLastBAIDBalance() Normal Exit iRet = [%d]\n",iRet));
	return iRet;

getlastbaidbalance_error:
DEBUGLOG(("getlastbaidbalance_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL CLOSE getlastbaidbalance; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1579;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getlastbaidbalance_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int CheckBankStmtRecordByProvider(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkbankstmtrecbypid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

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

		short	ind_provider_id = -1;
		short	ind_int_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_statement_date = -1;
		short	ind_statement_time = -1;
		short	ind_txn_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_txn_amount = -1;
		short	ind_balance = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls,"provider_id",&csTmp)) {
		hv_provider_id.len = strlen(csTmp);
		strncpy((char*)hv_provider_id.arr, csTmp, hv_provider_id.len);
		ind_provider_id = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() provider_id = [%.*s]\n", hv_provider_id.len, hv_provider_id.arr));
	}

	if (GetField_CString(hRls,"int_bank_code",&csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_CString(hRls,"statement_date",&csTmp)) {
		hv_statement_date.len = strlen(csTmp);
		strncpy((char*)hv_statement_date.arr, csTmp, hv_statement_date.len);
		ind_statement_date = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() statement_date = [%.*s]\n", hv_statement_date.len, hv_statement_date.arr));
	}

	if (GetField_CString(hRls,"TIME_FORMAT",&csTmp)) {
		if (GetField_CString(hRls,"statement_time",&csTmp)) {
			hv_statement_time.len = strlen(csTmp);
			strncpy((char*)hv_statement_time.arr, csTmp, hv_statement_time.len);
			ind_statement_time = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() statement_time = [%.*s]\n", hv_statement_time.len, hv_statement_time.arr));
		}
	}

	if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		strncpy((char*)hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() txn_ccy = [%.*s]\n",hv_txn_ccy.len, hv_txn_ccy.arr));
	}

	if (GetField_CString(hRls,"amt_type",&csTmp)) {
		hv_amt_type.len = strlen(csTmp);
		strncpy((char*)hv_amt_type.arr, csTmp, hv_amt_type.len);
		ind_amt_type = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() amt_type = [%.*s]\n",hv_amt_type.len,hv_amt_type.arr));
	}

	if (GetField_CString(hRls,"txn_amount",&csTmp)) {
		hv_txn_amount = atof(csTmp);
		ind_txn_amount = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() txn_amount = [%.2lf]\n", hv_txn_amount));
	}

	if (GetField_CString(hRls,"balance",&csTmp)) {
		hv_balance = atof(csTmp);
		ind_balance = 0;
DEBUGLOG(("CheckBankStmtRecordByProvider() balance = [%.2lf]\n", hv_balance));
	}

	/* EXEC SQL	SELECT	COUNT(*)
			INTO	:v_cnt
			FROM	OL_STATEMENT_DETAIL, OL_BANK_ACCT_ID, OL_PSP_DETAIL
			WHERE	OLSD_BAID = OBAI_BAID
			AND	OBAI_PSP_ID = OPD_PSP_ID
			AND	OPD_CLIENT_ID = : hv_provider_id
			AND	OLSD_INT_BANK_CODE = :hv_int_bank_code:ind_int_bank_code
			AND	OLSD_BANK_ACCT_NUM = :hv_bank_acct_num:ind_bank_acct_num
			AND	OLSD_STATEMENT_DATE = :hv_statement_date:ind_statement_date
			AND	(OLSD_STATEMENT_TIME = :hv_statement_time:ind_statement_time
				OR :ind_statement_time = -1)
			AND	OLSD_TXN_CCY = :hv_txn_ccy:ind_txn_ccy
			AND	OLSD_AMT_TYPE = :hv_amt_type:ind_amt_type
			AND	OLSD_TXN_AMOUNT = :hv_txn_amount:ind_txn_amount
			AND	OLSD_BALANCE = :hv_balance:ind_balance
			AND	OLSD_STATEMENT_REF IS NOT NULL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_DETAIL , OL_B\
ANK_ACCT_ID , OL_PSP_DETAIL WHERE OLSD_BAID = OBAI_BAID AND OBAI_PSP_ID = OPD\
_PSP_ID AND OPD_CLIENT_ID = :b1 AND OLSD_INT_BANK_CODE = :b2:b3 AND OLSD_BANK\
_ACCT_NUM = :b4:b5 AND OLSD_STATEMENT_DATE = :b6:b7 AND ( OLSD_STATEMENT_TIME\
 = :b8:b9 OR :b10 = - 1 ) AND OLSD_TXN_CCY = :b11:b12 AND OLSD_AMT_TYPE = :b1\
3:b14 AND OLSD_TXN_AMOUNT = :b15:b16 AND OLSD_BALANCE = :b17:b18 AND OLSD_STA\
TEMENT_REF IS NOT NULL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1594;
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
 sqlstm.sqhstl[4] = (unsigned long )10;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_statement_date;
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
 sqlstm.sqhstv[6] = (unsigned char  *)&ind_statement_time;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(short);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_amt_type;
 sqlstm.sqhstl[8] = (unsigned long )4;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_amt_type;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_balance;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_balance;
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
 if (sqlca.sqlcode < 0) goto chkbankstmtrecbypid_error;
}



	if (v_cnt>0) {
		iRet = FOUND;
DEBUGLOG(("CheckBankStmtRecordByProvider() FOUND\n"));
	} else {
		iRet = NOT_FOUND;
DEBUGLOG(("CheckBankStmtRecordByProvider() NOT FOUND\n"));
	}

DEBUGLOG(("CheckBankStmtRecordByProvider() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

chkbankstmtrecbypid_error:
DEBUGLOG(("chkbankstmtrecbypid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckBAIDPendingExist(const char* csIntBankCode, const char* csBankAcctNum, const char *csBAID)
{
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkbaidheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_int_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_int_bank_code;

                /* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                int     v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_int_bank_code.len = strlen(csIntBankCode);
        strncpy((char*)hv_int_bank_code.arr,csIntBankCode,hv_int_bank_code.len);
DEBUGLOG(("CheckBAIDPendingExist int_bank_code = [%s]\n",csIntBankCode));

        hv_bank_acct_num.len = strlen(csBankAcctNum);
        strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
DEBUGLOG(("CheckBAIDPendingExist bank_acct_num = [%s]\n",csBankAcctNum));

	hv_baid.len = strlen(csBAID);
        strncpy((char*)hv_baid.arr,csBAID,hv_baid.len);
DEBUGLOG(("CheckBAIDPendingExist baid = [%s]\n",csBAID));

        /* EXEC SQL        SELECT  COUNT(*)
                        INTO    :v_cnt
                        FROM    OL_STATEMENT_HEADER
                        WHERE   OLSH_INT_BANK_CODE = :hv_int_bank_code
                        AND     OLSH_BANK_ACCT_NUM = :hv_bank_acct_num
                        AND     OLSH_BAID = :hv_baid
                        AND     OLSH_STATUS = 'W'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0 FROM OL_STATEMENT_HEADER\
 WHERE OLSH_INT_BANK_CODE = :b1 AND OLSH_BANK_ACCT_NUM = :b2 AND OLSH_BAID = \
:b3 AND OLSH_STATUS = 'W' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1653;
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
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[3] = (unsigned long )22;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto checkbaidheader_error;
}



        if (v_cnt>0) {
                iRet = FOUND;
DEBUGLOG(("CheckBAIDPendingExist() FOUND\n"));
        } else {
                iRet = NOT_FOUND;
DEBUGLOG(("CheckBAIDPendingExist() NOT FOUND\n"));
        }

DEBUGLOG(("CheckBAIDPendingExist() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkbaidheader_error:
DEBUGLOG(("checkbaidheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetFileIdForUpdateNoWait(const char* csFileId) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getfileidforupdatenowait_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

		/* varchar v_file_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

		short ind_file_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_file_id.len = strlen(csFileId);
	memcpy(hv_file_id.arr, csFileId, hv_file_id.len);
DEBUGLOG(("GetFileIdForUpdateNoWait file_id = [%.*s]\n", hv_file_id.len, hv_file_id.arr));

	/* EXEC SQL select olsh_file_id
		into :v_file_id:ind_file_id
		from ol_statement_header
		where olsh_file_id = :hv_file_id
		for update nowait; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select olsh_file_id into :b0:b1 from ol_statement_header wh\
ere olsh_file_id = :b2 for update nowait ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1684;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_file_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
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
 if (sqlca.sqlcode < 0) goto getfileidforupdatenowait_error;
}



	if (ind_file_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

getfileidforupdatenowait_error:
DEBUGLOG(("getfileidforupdatenowait_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetCountByBankAcct(const char* csBankCode, const char* csBankAcctNum)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getcountbybankacct_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

                int     v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_code.len = strlen(csBankCode);
        strncpy((char*)hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetCountByBankAcct bank_code = [%s]\n",csBankCode));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
        strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
DEBUGLOG(("GetCountByBankAcct bank_acct_num = [%s]\n",csBankAcctNum));

        /* EXEC SQL        SELECT  (select count(*) from ol_statement_header where olsh_int_bank_code = :hv_bank_code and olsh_bank_acct_num = :hv_bank_acct_num) +
				(select count(*) from ol_statement_detail where olsd_int_bank_code = :hv_bank_code and olsd_bank_acct_num = :hv_bank_acct_num)
                        INTO    :v_cnt
                        FROM    dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 34;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select ( select count ( * ) from ol_statement_header\
 where olsh_int_bank_code = :b0 and olsh_bank_acct_num = :b1 ) + ( select cou\
nt ( * ) from ol_statement_detail where olsd_int_bank_code = :b0 and olsd_ban\
k_acct_num = :b1 ) INTO :b4 FROM dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1707;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[1] = (unsigned long )52;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_acct_num;
        sqlstm.sqhstl[3] = (unsigned long )52;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getcountbybankacct_error;
}



DEBUGLOG(("GetCountByBankAcct() Normal Exit! record found = [%d]\n", v_cnt));
        return v_cnt;

getcountbybankacct_error:
DEBUGLOG(("getcountbybankacct_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int UpdateHeaderAutoUpload(const hash_t *hRls)
{
        int     iTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatehdautoupload_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                /* varchar         hv_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_acct_type;

                int             hv_auto_upload;

                short           ind_file_id = -1;
                short           ind_acct_type = -1;
                short           ind_auto_upload = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


/* file_id */
        if (GetField_CString(hRls, "file_id", &csTmp)) {
                hv_file_id.len = strlen(csTmp);
                strncpy((char*)hv_file_id.arr,csTmp,hv_file_id.len);
                ind_file_id = 0;
DEBUGLOG(("UpdateHeaderAutoUpload: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
        }

/* acct_type */
        if (GetField_CString(hRls,"acct_type",&csTmp)) {
                hv_acct_type.len = strlen(csTmp);
                strncpy((char*)hv_acct_type.arr,csTmp,sizeof(hv_acct_type.arr));
                ind_acct_type = 0;
DEBUGLOG(("UpdateHeaderAutoUpload: acct_type = [%.*s](%d)\n",sizeof(hv_acct_type.arr),hv_acct_type.arr,hv_acct_type.len));
        }

/* auto_upload */
        if (GetField_Int(hRls, "auto_upload", &iTmp)) {
                hv_auto_upload = iTmp;
                ind_auto_upload = 0;
DEBUGLOG(("UpdateHeaderAutoUpload: auto_upload = [%d]\n",hv_auto_upload));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_statement_upd_auto_upl(
						:hv_file_id:ind_file_id,
                                                :hv_acct_type:ind_acct_type,
                                                :hv_auto_upload:ind_auto_upload);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_upd_auto_upl ( :h\
v_file_id:ind_file_id , :hv_acct_type:ind_acct_type , :hv_auto_upload:ind_aut\
o_upload ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1742;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_acct_type;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_acct_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_auto_upload;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_auto_upload;
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
 if (sqlca.sqlcode < 0) goto updatehdautoupload_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateHeaderAutoUpload: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateHeaderAutoUpload: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateHeaderAutoUpload: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateHeaderAutoUpload: SP_ERR\n");
DEBUGLOG(("UpdateHeaderAutoUpload: SP_ERR\n"));
                return PD_ERR;
        }

updatehdautoupload_error:
DEBUGLOG(("updatehdautoupload_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateHeaderAutoUpload: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatement_UpdateHeaderAutoUpload: SP_INTERNAL_ERR TxnAbort\n");
        TxnAbort();
        return PD_INTERNAL_ERR;
}
	
int UpdateHeaderRenamedFilename(const hash_t *hRls)
{
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatehdfilename_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                /* varchar         hv_renamed_filename[PD_RENAMED_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_renamed_filename;


                short           ind_file_id = -1;
                short           ind_renamed_filename = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


/* file_id */
        if (GetField_CString(hRls, "file_id", &csTmp)) {
                hv_file_id.len = strlen(csTmp);
                strncpy((char*)hv_file_id.arr,csTmp,hv_file_id.len);
                ind_file_id = 0;
DEBUGLOG(("UpdateHeaderRenamedFilename: file_id = [%.*s](%d)\n",sizeof(hv_file_id.arr),hv_file_id.arr,hv_file_id.len));
        }

/* renamed_filename */
        if (GetField_CString(hRls,"renamed_filename",&csTmp)) {
                hv_renamed_filename.len = strlen(csTmp);
                strncpy((char*)hv_renamed_filename.arr,csTmp,sizeof(hv_renamed_filename.arr));
                ind_renamed_filename = 0;
DEBUGLOG(("UpdateHeaderRenamedFilename: renamed_filename = [%.*s](%d)\n",sizeof(hv_renamed_filename.arr),hv_renamed_filename.arr,hv_renamed_filename.len));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_statement_upd_rn_file(
						:hv_file_id:ind_file_id,
                                                :hv_renamed_filename:ind_renamed_filename);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 34;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_statement_upd_rn_file ( :hv\
_file_id:ind_file_id , :hv_renamed_filename:ind_renamed_filename ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1773;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_renamed_filename;
 sqlstm.sqhstl[2] = (unsigned long )152;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_renamed_filename;
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
 if (sqlca.sqlcode < 0) goto updatehdfilename_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateHeaderRenamedFilename: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLStatement_UpdateHeaderRenamedFilename: SP_OTHER_ERR\n");
DEBUGLOG(("UpdateHeaderRenamedFilename: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR) {
ERRLOG("OLStatement_UpdateHeaderRenamedFilename: SP_ERR\n");
DEBUGLOG(("UpdateHeaderRenamedFilename: SP_ERR\n"));
                return PD_ERR;
        }

updatehdfilename_error:
DEBUGLOG(("updatehdfilename_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

DEBUGLOG(("UpdateHeaderRenamedFilename: SP_INTERNAL_ERR TxnAbort\n"));
ERRLOG("OLStatement_UpdateHeaderRenamedFilename: SP_INTERNAL_ERR TxnAbort\n");
        TxnAbort();
        return PD_INTERNAL_ERR;
}	
