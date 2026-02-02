
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
    "OLPspTxnSpcAction.pc"
};


static unsigned int sqlctx = 82626459;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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
"SELECT OSA_ACTION , OSA_EXEC_SEQ , OSA_BANK_ACCT_TYPE , OSA_TRIGGER_TYPE , \
OSA_P1_TXN_ID_TYPE , OSA_P1_FIELD , OSA_P1_AMT_TYPE , OSA_P2_TXN_ID_TYPE , OS\
A_P2_FIELD , OSA_P2_AMT_TYPE , OSA_COMPARE_OPERATOR , OSA_RESULT_KEY , OSA_RE\
SULT_VALUE FROM OL_PSP_TXN_SPC_ACTION WHERE OSA_ACTION = :b0 AND OSA_DISABLED\
 = 0 ORDER BY OSA_EXEC_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,344,0,9,107,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,110,0,0,13,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
91,0,0,1,0,0,15,212,0,0,0,0,0,1,0,
106,0,0,1,0,0,15,231,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/10              Dirk Wong
Refined Table                                      2014/11/20              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "dbutility.h"
#include "OLPspTxnSpcAction.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLPspTxnSpcAction(char cdebug)
{
        cDebug = cdebug;
}

int GetPspTxnSpcAction(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	int iCnt;
	char *csTmp;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getpsptxnspcaction_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_action[PD_ENGINE_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_action;


		/* varchar	v_action[PD_ENGINE_ACTION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_action;

		int	v_exec_seq;
		/* varchar	v_bank_acct_type[PD_ACCT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_acct_type;

		/* varchar	v_trigger_type[PD_ENGINE_TRIGGER_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_trigger_type;

		/* varchar	v_p1_txn_id_type[PD_ENGINE_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_p1_txn_id_type;

		/* varchar	v_p1_field[PD_ENGINE_TXN_FIELD_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_p1_field;

                /* varchar	v_p1_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_p1_amt_type;

		/* varchar	v_p2_txn_id_type[PD_ENGINE_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_p2_txn_id_type;

		/* varchar	v_p2_field[PD_ENGINE_TXN_FIELD_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_p2_field;

                /* varchar	v_p2_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_p2_amt_type;

		/* varchar	v_compare_operator[PD_ENGINE_COMPARE_OPERATOR_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_compare_operator;

		/* varchar	v_result_key[PD_ENGINE_RESULT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_result_key;

		/* varchar	v_result_value[PD_ENGINE_RESULT_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_result_value;


		short	ind_action = -1;
		short	ind_exec_seq = -1;
		short	ind_bank_acct_type = -1;
		short	ind_trigger_type = -1;
		short	ind_p1_txn_id_type = -1;
		short	ind_p1_field = -1;
		short	ind_p1_amt_type = -1;
		short	ind_p2_txn_id_type = -1;
		short	ind_p2_field = -1;
		short	ind_p2_amt_type = -1;
		short	ind_compare_operator = -1;
		short	ind_result_key = -1;
		short	ind_result_value = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "spc_action", &csTmp)) {
		hv_action.len = strlen(csTmp);
		strncpy((char*)hv_action.arr, csTmp, hv_action.len);
DEBUGLOG(("GetPspTxnSpcAction action = [%s]\n", hv_action.len, (const char *)hv_action.arr));
	} else {
DEBUGLOG(("GetPspTxnSpcAction action_id not found!\n"));
		iRet = INT_ACTION_ID_NOT_FOUND;
	}

	/* EXEC SQL DECLARE c_getpsptxnspcaction CURSOR FOR
		SELECT	OSA_ACTION,
			OSA_EXEC_SEQ,
			OSA_BANK_ACCT_TYPE,
			OSA_TRIGGER_TYPE,
			OSA_P1_TXN_ID_TYPE,
			OSA_P1_FIELD,
			OSA_P1_AMT_TYPE,
			OSA_P2_TXN_ID_TYPE,
			OSA_P2_FIELD,
			OSA_P2_AMT_TYPE,
			OSA_COMPARE_OPERATOR,
			OSA_RESULT_KEY,
			OSA_RESULT_VALUE
		FROM	OL_PSP_TXN_SPC_ACTION
		WHERE	OSA_ACTION = :hv_action
		AND	OSA_DISABLED = 0
		ORDER BY OSA_EXEC_SEQ; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getpsptxnspcaction; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_action;
  sqlstm.sqhstl[0] = (unsigned long )52;
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
  if (sqlca.sqlcode < 0) goto getpsptxnspcaction_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getpsptxnspcaction
			INTO	:v_action:ind_action,
				:v_exec_seq:ind_exec_seq,
				:v_bank_acct_type:ind_bank_acct_type,
				:v_trigger_type:ind_trigger_type,
				:v_p1_txn_id_type:ind_p1_txn_id_type,
				:v_p1_field:ind_p1_field,
				:v_p1_amt_type:ind_p1_amt_type,
				:v_p2_txn_id_type:ind_p2_txn_id_type,
				:v_p2_field:ind_p2_field,
				:v_p2_amt_type:ind_p2_amt_type,
				:v_compare_operator:ind_compare_operator,
				:v_result_key:ind_result_key,
				:v_result_value:ind_result_value; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 13;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )24;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_action;
   sqlstm.sqhstl[0] = (unsigned long )53;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_action;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_exec_seq;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_exec_seq;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_type;
   sqlstm.sqhstl[2] = (unsigned long )6;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_bank_acct_type;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_trigger_type;
   sqlstm.sqhstl[3] = (unsigned long )13;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_trigger_type;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_p1_txn_id_type;
   sqlstm.sqhstl[4] = (unsigned long )13;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_p1_txn_id_type;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_p1_field;
   sqlstm.sqhstl[5] = (unsigned long )53;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_p1_field;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_p1_amt_type;
   sqlstm.sqhstl[6] = (unsigned long )5;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_p1_amt_type;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_p2_txn_id_type;
   sqlstm.sqhstl[7] = (unsigned long )13;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_p2_txn_id_type;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_p2_field;
   sqlstm.sqhstl[8] = (unsigned long )53;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_p2_field;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_p2_amt_type;
   sqlstm.sqhstl[9] = (unsigned long )5;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_p2_amt_type;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_compare_operator;
   sqlstm.sqhstl[10] = (unsigned long )23;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_compare_operator;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_result_key;
   sqlstm.sqhstl[11] = (unsigned long )53;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_result_key;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_result_value;
   sqlstm.sqhstl[12] = (unsigned long )53;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_result_value;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
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
   if (sqlca.sqlcode < 0) goto getpsptxnspcaction_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

			if (ind_action >= 0) {
				v_action.arr[v_action.len] = '\0';
				PutField_CString(myHash, "action", (const char*)v_action.arr);
DEBUGLOG(("GetPspTxnSpcAction action = [%s]\n", v_action.arr));
			}

			if (ind_exec_seq >= 0) {
				PutField_Int(myHash, "exec_seq", v_exec_seq);
DEBUGLOG(("GetPspTxnSpcAction exec_seq = [%d]\n", v_exec_seq));
			}

			if (ind_bank_acct_type >= 0) {
				v_bank_acct_type.arr[v_bank_acct_type.len] = '\0';
				PutField_CString(myHash, "bank_acct_type", (const char*)v_bank_acct_type.arr);
DEBUGLOG(("GetPspTxnSpcAction action = [%s]\n", v_bank_acct_type.arr));
			}

			if (ind_trigger_type >= 0) {
				v_trigger_type.arr[v_trigger_type.len] = '\0';
				PutField_CString(myHash, "trigger_type", (const char*)v_trigger_type.arr);
DEBUGLOG(("GetPspTxnSpcAction trigger_type = [%s]\n", v_trigger_type.arr));
			}

			if (ind_p1_txn_id_type >= 0) {
				v_p1_txn_id_type.arr[v_p1_txn_id_type.len] = '\0';
				PutField_CString(myHash, "p1_txn_id_type", (const char*)v_p1_txn_id_type.arr);
DEBUGLOG(("GetPspTxnSpcAction p1_txn_id_type = [%s]\n", v_p1_txn_id_type.arr));
			}

			if (ind_p1_field >= 0) {
				v_p1_field.arr[v_p1_field.len] = '\0';
				PutField_CString(myHash, "p1_field", (const char*)v_p1_field.arr);
DEBUGLOG(("GetPspTxnSpcAction p1_field = [%s]\n", v_p1_field.arr));
			}

			if (ind_p1_amt_type >= 0) {
				v_p1_amt_type.arr[v_p1_amt_type.len] = '\0';
				PutField_CString(myHash, "p1_amt_type", (const char*)v_p1_amt_type.arr);
DEBUGLOG(("GetPspTxnSpcAction p1_amt_type = [%s]\n", v_p1_amt_type.arr));
			}

			if (ind_p2_txn_id_type >= 0) {
				v_p2_txn_id_type.arr[v_p2_txn_id_type.len] = '\0';
				PutField_CString(myHash, "p2_txn_id_type", (const char*)v_p2_txn_id_type.arr);
DEBUGLOG(("GetPspTxnSpcAction p2_txn_id_type = [%s]\n", v_p2_txn_id_type.arr));
			}

			if (ind_p2_field >= 0) {
				v_p2_field.arr[v_p2_field.len] = '\0';
				PutField_CString(myHash, "p2_field", (const char*)v_p2_field.arr);
DEBUGLOG(("GetPspTxnSpcAction p2_field = [%s]\n", v_p2_field.arr));
			}

			if (ind_p2_amt_type >= 0) {
				v_p2_amt_type.arr[v_p2_amt_type.len] = '\0';
				PutField_CString(myHash, "p2_amt_type", (const char*)v_p2_amt_type.arr);
DEBUGLOG(("GetPspTxnSpcAction p2_amt_type = [%s]\n", v_p2_amt_type.arr));
			}

			if (ind_compare_operator >= 0) {
				v_compare_operator.arr[v_compare_operator.len] = '\0';
				PutField_CString(myHash, "compare_operator", (const char*)v_compare_operator.arr);
DEBUGLOG(("GetPspTxnSpcAction compare_operator = [%s]\n", v_compare_operator.arr));
			}

			if (ind_result_key >= 0) {
				v_result_key.arr[v_result_key.len] = '\0';
				PutField_CString(myHash, "result_key", (const char*)v_result_key.arr);
DEBUGLOG(("GetPspTxnSpcAction result_key = [%s]\n", v_result_key.arr));
			}

			if (ind_result_value >= 0) {
				v_result_value.arr[v_result_value.len] = '\0';
				PutField_CString(myHash, "result_value", (const char*)v_result_value.arr);
DEBUGLOG(("GetPspTxnSpcAction result_value = [%s]\n", v_result_value.arr));
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_getpsptxnspcaction; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 13;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )91;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getpsptxnspcaction_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetPspTxnSpcAction: hash added\n"));
		} else {
DEBUGLOG(("GetPspTxnSpcAction no record found\n"));
ERRLOG("OLPspTxnSpcAction: GetPspTxnSpcAction no record found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetPspTxnSpcAction Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getpsptxnspcaction_error:
DEBUGLOG(("getpsptxnspcaction_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPspTxnSpcAction getpsptxnspcaction_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getpsptxnspcaction; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )106;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpsptxnspcaction_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

