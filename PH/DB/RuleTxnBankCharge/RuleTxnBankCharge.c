
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "RuleTxnBankCharge.pc"
};


static unsigned int sqlctx = 85147571;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
5,0,0,0,0,0,56,116,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,233,0,6,117,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,2,102,0,0,
67,0,0,0,0,0,13,144,0,0,9,1,0,1,0,1,102,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,1,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
118,0,0,0,0,0,15,206,0,0,1,1,0,1,0,1,102,0,0,
137,0,0,0,0,0,78,207,0,0,1,1,0,1,0,3,102,0,0,
156,0,0,0,0,0,15,211,0,0,1,1,0,1,0,1,102,0,0,
175,0,0,0,0,0,78,212,0,0,1,1,0,1,0,3,102,0,0,
194,0,0,0,0,0,15,216,0,0,1,1,0,1,0,1,102,0,0,
213,0,0,0,0,0,78,217,0,0,1,1,0,1,0,3,102,0,0,
232,0,0,0,0,0,15,226,0,0,1,1,0,1,0,1,102,0,0,
251,0,0,0,0,0,78,227,0,0,1,1,0,1,0,3,102,0,0,
270,0,0,2,388,0,6,377,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
333,0,0,3,0,0,17,517,0,0,1,1,0,1,0,1,9,0,0,
352,0,0,3,0,0,21,518,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/16              Elvis Wong
Refine                                             2014/12/26              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "RuleTxnBankCharge.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void RuleTxnBankCharge(char cdebug)
{
	cDebug = cdebug;
}

int Find(hash_t* hRls, recordset_t* myRec)
{
	char *csTmp;
	hash_t *myHash;
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO find_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short hv_return_value;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		double v_tier_min_value;
		double v_tier_max_value;
		int v_rule_id;
		char v_type;
		double v_value;
		double v_add_value;
		double v_min_value;
		double v_max_value;

		short ind_bank_code = -1;
		short ind_country_id = -1;
		short ind_ccy = -1;
		short ind_channel_code = -1;
		short ind_txn_code = -1;

		short ind_tier_min_value = -1;
		short ind_tier_max_value = -1;
		short ind_rule_id = -1;
		short ind_type = -1;
		short ind_value = -1;
		short ind_add_value = -1;
		short ind_min_value = -1;
		short ind_max_value = -1;

		SQL_CURSOR c_cursor_ruletxnbankcharge;
	/* EXEC SQL END DECLARE SECTION; */ 


	// bank_code
	if (GetField_CString(hRls, "bank_code", &csTmp)) {
		hv_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_bank_code.arr, csTmp, sizeof(hv_bank_code.arr));
		ind_bank_code = 0;
DEBUGLOG(("Find: hv_bank_code = [%.*s](%d)\n", sizeof(hv_bank_code.arr), hv_bank_code.arr, hv_bank_code.len));
	}

	// country_id
	if (GetField_CString(hRls, "country_id", &csTmp)) {
		hv_country_id.len = strlen(csTmp);
		strncpy((char*)hv_country_id.arr, csTmp, sizeof(hv_country_id.arr));
		ind_country_id = 0;
DEBUGLOG(("Find: hv_country_id = [%.*s](%d)\n", sizeof(hv_country_id.arr), hv_country_id.arr, hv_country_id.len));
	}

	// ccy
	if (GetField_CString(hRls, "ccy", &csTmp)) {
		hv_ccy.len = strlen(csTmp);
		strncpy((char*)hv_ccy.arr, csTmp, sizeof(hv_ccy.arr));
		ind_ccy = 0;
DEBUGLOG(("Find: hv_ccy = [%.*s](%d)\n", sizeof(hv_ccy.arr), hv_ccy.arr, hv_ccy.len));
	}

	// channel_code
	if (GetField_CString(hRls, "channel_code", &csTmp)) {
		hv_channel_code.len = strlen(csTmp);
		strncpy((char*)hv_channel_code.arr, csTmp, sizeof(hv_channel_code.arr));
		ind_channel_code = 0;
DEBUGLOG(("Find: hv_channel_code = [%.*s](%d)\n", sizeof(hv_channel_code.arr), hv_channel_code.arr, hv_channel_code.len));
	}

	// txn_code
	if (GetField_CString(hRls, "txn_code", &csTmp)) {
		hv_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_txn_code.arr, csTmp, sizeof(hv_txn_code.arr));
		ind_txn_code = 0;
DEBUGLOG(("Find: hv_txn_code = [%.*s](%d)\n", sizeof(hv_txn_code.arr), hv_txn_code.arr, hv_txn_code.len));
	}

	/* EXEC SQL ALLOCATE :c_cursor_ruletxnbankcharge; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto find_error;
}


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_rule_txn_bk_chr_find(:hv_bank_code:ind_bank_code,
									:hv_country_id:ind_country_id,
									:hv_ccy:ind_ccy,
									:hv_channel_code:ind_channel_code,
									:hv_txn_code:ind_txn_code,
									:c_cursor_ruletxnbankcharge);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_rule_txn_bk_chr_find ( :hv_ban\
k_code:ind_bank_code , :hv_country_id:ind_country_id , :hv_ccy:ind_ccy , :hv_\
channel_code:ind_channel_code , :hv_txn_code:ind_txn_code , :c_cursor_ruletxn\
bankcharge ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_bank_code;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_country_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_channel_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_code;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto find_error;
}



	if (hv_return_value == 1) {
DEBUGLOG(("Find Found\n"));
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

			ind_tier_min_value = -1;
			ind_tier_max_value = -1;
			ind_rule_id = -1;
			ind_type = -1;
			ind_value = -1;
			ind_add_value = -1;
			ind_min_value = -1;
			ind_max_value = -1;

			/* EXEC SQL FETCH :c_cursor_ruletxnbankcharge
			INTO	:v_tier_min_value:ind_tier_min_value,
					:v_tier_max_value:ind_tier_max_value,
					:v_rule_id:ind_rule_id,
					:v_type:ind_type,
					:v_value:ind_value,
					:v_add_value:ind_add_value,
					:v_min_value:ind_min_value,
					:v_max_value:ind_max_value; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )67;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_tier_min_value;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_tier_min_value;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_tier_max_value;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_tier_max_value;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_rule_id;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_rule_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_type;
   sqlstm.sqhstl[4] = (unsigned long )1;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_type;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_value;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_value;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_add_value;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_add_value;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_min_value;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_min_value;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_max_value;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_max_value;
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
   if (sqlca.sqlcode == 1403) break;
   if (sqlca.sqlcode < 0) goto find_error;
}



			iCnt++;

			// tier_min_value
			if (ind_tier_min_value >= 0) {
DEBUGLOG(("find[%d] tier_min_value = [%lf]\n", iCnt, v_tier_min_value));
				PutField_Double(myHash, "tier_min_value", v_tier_min_value);
			}

			// tier_max_value
			if (ind_tier_max_value >= 0) {
DEBUGLOG(("find[%d] tier_max_value = [%lf]\n", iCnt, v_tier_max_value));
				PutField_Double(myHash, "tier_max_value", v_tier_max_value);
			}

			// rule_id
			if (ind_rule_id >= 0) {
DEBUGLOG(("find[%d] rule_id = [%d]\n", iCnt, v_rule_id));
				PutField_Int(myHash, "rule_id", v_rule_id);
			}

			// type
			if (ind_type >= 0) {
DEBUGLOG(("find[%d] type = [%c]\n", iCnt, v_type));
				PutField_Char(myHash, "type", v_type);
			}

			// value
			if (ind_value >= 0) {
DEBUGLOG(("find[%d] value = [%lf]\n", iCnt, v_value));
				PutField_Double(myHash, "value", v_value);
			}

			// add_value
			if (ind_add_value >= 0) {
DEBUGLOG(("find[%d] add_value = [%lf]\n", iCnt, v_add_value));
				PutField_Double(myHash, "add_value", v_add_value);
			}

			// min_value
			if (ind_min_value >= 0) {
DEBUGLOG(("find[%d] min_value = [%lf]\n", iCnt, v_min_value));
				PutField_Double(myHash, "min_value", v_min_value);
			}

			// max_value
			if (ind_max_value >= 0) {
DEBUGLOG(("find[%d] max_value = [%lf]\n", iCnt, v_max_value));
				PutField_Double(myHash, "max_value", v_max_value);
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )118;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		/* EXEC SQL FREE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )137;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		return PD_FOUND;
	} else if (hv_return_value == 0) {
DEBUGLOG(("Find Not Found\n"));
		/* EXEC SQL CLOSE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )156;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		/* EXEC SQL FREE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )175;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		return PD_NOT_FOUND;
	} else {
DEBUGLOG(("Find Error\n"));
		/* EXEC SQL CLOSE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )194;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		/* EXEC SQL FREE :c_cursor_ruletxnbankcharge; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )213;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto find_error;
}


		return PD_ERR;
	}

find_error:
ERRLOG("RuleTxnBankCharge::find_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("find_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_ruletxnbankcharge; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )232;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	/* EXEC SQL FREE :c_cursor_ruletxnbankcharge; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )251;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_ruletxnbankcharge;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
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
}


	return PD_ERR;
}

int Add(const hash_t* hRls)
{
	int	iTmp = 0;
	double	dTmp = 0.0;
	char*	csTmp;

DEBUGLOG(("Add: Begin\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;

		/* varchar         hv_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_bank_code;

                /* varchar         hv_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_country_id;

                /* varchar         hv_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_ccy;

                /* varchar         hv_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_channel_code;

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;

		int		hv_amount_id;
		double		hv_min_value;
		double		hv_max_value;
		/* varchar		hv_effect_date[PD_EFFECT_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_effect_date;

		int		hv_disabled;
		/* varchar         hv_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_create_user;


                short           ind_bank_code = -1;
                short           ind_country_id = -1;
                short           ind_ccy = -1;
                short           ind_channel_code = -1;
                short           ind_txn_code = -1;
                short           ind_amount_id = -1;
                short           ind_min_value = -1;
                short           ind_max_value = -1;
                short           ind_effect_date = -1;
                short           ind_disabled = -1;
                short           ind_create_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* bank_code */
	if (GetField_CString(hRls,"bank_code",&csTmp)) {
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
DEBUGLOG(("Add bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
                ind_bank_code = 0;
        }else{
DEBUGLOG(("Add bank_code not found!!!"));
        }

/* country_id */
        if (GetField_CString(hRls,"country_id",&csTmp)) {
                hv_country_id.len = strlen(csTmp);
                memcpy(hv_country_id.arr,csTmp,hv_country_id.len);
DEBUGLOG(("Add country_id = [%.*s]\n",hv_country_id.len,hv_country_id.arr));
                ind_country_id = 0;
        }else{
DEBUGLOG(("Add country_id not found!!!"));
        }

/* ccy */
        if (GetField_CString(hRls,"ccy",&csTmp)) {
                hv_ccy.len = strlen(csTmp);
                memcpy(hv_ccy.arr,csTmp,hv_ccy.len);
DEBUGLOG(("Add ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));
                ind_ccy = 0;
        }else{
DEBUGLOG(("Add ccy not found!!!"));
        }

/* channel_code */
        if (GetField_CString(hRls,"channel_code",&csTmp)) {
                hv_channel_code.len = strlen(csTmp);
                memcpy(hv_channel_code.arr,csTmp,hv_channel_code.len);
DEBUGLOG(("Add channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
                ind_channel_code = 0;
        }else{
DEBUGLOG(("Add country_id not found!!!"));
        }

/* txn_code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
DEBUGLOG(("Add txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
                ind_txn_code = 0;
        }else{
DEBUGLOG(("Add txn_code not found!!!"));
        }

/* amount_id */
	if (GetField_Int(hRls,"amount_id",&iTmp)) {
                hv_amount_id = iTmp;
DEBUGLOG(("Add amount_id = [%d]\n",iTmp));
                ind_amount_id = 0;
        }else{
DEBUGLOG(("Add amount_id not found!!!"));
        }

/* min_value */
	if (GetField_Double(hRls,"min_value",&dTmp)) {
                hv_min_value = dTmp;
DEBUGLOG(("Add min_value = [%d]\n",dTmp));
                ind_min_value = 0;
        }else{
DEBUGLOG(("Add min_value not found!!!"));
        }

/* max_value */
        if (GetField_Double(hRls,"max_value",&dTmp)) {
                hv_max_value = dTmp;
DEBUGLOG(("Add max_value = [%d]\n",dTmp));
                ind_max_value = 0;
        }else{
DEBUGLOG(("Add max_value not found!!!"));
        }

/* effect_date */
        if (GetField_CString(hRls,"effect_date",&csTmp)) {
                hv_effect_date.len = strlen(csTmp);
                memcpy(hv_effect_date.arr,csTmp,hv_effect_date.len);
DEBUGLOG(("Add effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));
                ind_effect_date = 0;
        }else{
DEBUGLOG(("Add effect_date not found!!!"));
        }

/* disabled */
        if (GetField_Int(hRls,"disabled",&iTmp)) {
		hv_disabled = iTmp;
DEBUGLOG(("Add disabled = [%d]\n",iTmp));
		ind_disabled = 0;
	}else{
DEBUGLOG(("Add disabled not found!!!"));
	}

/* create_user */
        if (GetField_CString(hRls,"create_user",&csTmp)) {
        	hv_create_user.len = strlen(csTmp);
        	memcpy(hv_create_user.arr,csTmp,hv_create_user.len);
DEBUGLOG(("Add create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
		ind_create_user = 0;
	}else{
DEBUGLOG(("Add create_user not found!!!"));
	}

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_rule_txn_bk_chr_ins(:hv_bank_code:ind_bank_code,
								:hv_country_id:ind_country_id,
								:hv_ccy:ind_ccy,
								:hv_channel_code:ind_channel_code,
								:hv_txn_code:ind_txn_code,
								:hv_amount_id:ind_amount_id,
								:hv_min_value:ind_min_value,
								:hv_max_value:ind_max_value,
								:hv_effect_date:ind_effect_date,
								:hv_disabled:ind_disabled,
								:hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_rule_txn_bk_chr_ins ( :\
hv_bank_code:ind_bank_code , :hv_country_id:ind_country_id , :hv_ccy:ind_ccy \
, :hv_channel_code:ind_channel_code , :hv_txn_code:ind_txn_code , :hv_amount_\
id:ind_amount_id , :hv_min_value:ind_min_value , :hv_max_value:ind_max_value \
, :hv_effect_date:ind_effect_date , :hv_disabled:ind_disabled , :hv_create_us\
er:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )270;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )13;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_bank_code;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_country_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
        sqlstm.sqhstl[3] = (unsigned long )6;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ccy;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_channel_code;
        sqlstm.sqhstl[4] = (unsigned long )6;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_channel_code;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[5] = (unsigned long )6;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_code;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_amount_id;
        sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_amount_id;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_min_value;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_min_value;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_max_value;
        sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_max_value;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_effect_date;
        sqlstm.sqhstl[9] = (unsigned long )11;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_effect_date;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_disabled;
        sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_disabled;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[11] = (unsigned long )23;
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
        if (sqlca.sqlcode < 0) goto add_error;
}




        if (hv_return_value == 0)  {
DEBUGLOG(("Add Success\n"));
                return PD_OK;
        }
        else {
DEBUGLOG(("Add Fail\n"));
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("RuleTxnRes_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int Update(const hash_t *hRls)
{
	int	iTmp;
	char*	csBuf = (char*)malloc(128);

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        strcpy((char*)hv_dynstmt.arr,"update rule_txn_bank_charge set rtbc_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*amount_id*/
        if (GetField_Int(hRls,"amount_id",&iTmp)) {
DEBUGLOG(("Update:amount_id = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",rtbc_amount_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*min_value*/
        if (GetField_Double(hRls,"min_value",&iTmp)) {
DEBUGLOG(("Update:min_value = [%lf]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",rtbc_min_value = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*max_value*/
        if (GetField_Double(hRls,"max_value",&iTmp)) {
DEBUGLOG(("Update:max_value = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",rtbc_max_value = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*effect_date*/
        if (GetField_CString(hRls,"effect_date",&csBuf)) {
DEBUGLOG(("Update:update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",rtbc_effect_date= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*disabled*/
        if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:disabled = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",rtbc_disabled = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csBuf)) {
DEBUGLOG(("Update:update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",rtbc_update_user= '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

//bank_code
	strcat((char *)hv_dynstmt.arr, " WHERE rtbc_bank_code = '");
       	strcat((char *)hv_dynstmt.arr, csBuf);
       	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//country
	strcat((char *)hv_dynstmt.arr, " WHERE rtbc_country = '");
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//ccy
        strcat((char *)hv_dynstmt.arr, " WHERE rtbc_ccy = '");
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//channel_code
        strcat((char *)hv_dynstmt.arr, " WHERE rtbc_channel_code = '");
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

//txn_code
        strcat((char *)hv_dynstmt.arr, " WHERE rtbc_txn_code = '");
        strcat((char *)hv_dynstmt.arr, csBuf);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " AND rs_disabled = 0");

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )333;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )352;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;


update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("RuleTxnRes_Update: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
