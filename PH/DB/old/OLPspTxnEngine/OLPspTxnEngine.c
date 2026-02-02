
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
    "OLPspTxnEngine.pc"
};


static unsigned int sqlctx = 10324867;


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
   unsigned char  *sqhstv[20];
   unsigned long  sqhstl[20];
            int   sqhsts[20];
            short *sqindv[20];
            int   sqinds[20];
   unsigned long  sqharm[20];
   unsigned long  *sqharc[20];
   unsigned short  sqadto[20];
   unsigned short  sqtdso[20];
} sqlstm = {12,20};

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
"SELECT OTE_EXEC_SEQ , OTE_IN_BAID_TXN , OTE_IN_TXN , OTE_IN_POST_BAID_TXN ,\
 OTE_IN_POST_TXN , OTE_IN_AMT_TYPE , OTE_IN_AMT_TYPE_SIDE , OTE_ORG_BAID_TXN \
, OTE_ORG_TXN , OTE_POST_BAID_TXN , OTE_POST_TXN , OTE_TXN_ACTION , OTE_TO_PO\
ST_TXN_LEVEL , OTE_TO_POST_TXN_CODE , OTE_BAID_CATEGORY , OTE_BAL_RULE_ID , O\
TE_BF_STATUS_RULE_ID , OTE_AF_STATUS_RULE_ID , OTE_NEXT_ACTION , OTE_SPC_ACTI\
ON FROM OL_PSP_TXN_ENGINE WHERE OTE_ACTION = :b0 AND OTE_TRIGGER_TYPE = :b1 A\
ND OTE_BANK_ACCT_TYPE = :b2 AND OTE_TXN_CODE = :b3 AND OTE_INPUT_CHANNEL = :b\
4 AND OTE_DISABLED = 0 ORDER BY OTE_EXEC_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,593,0,9,172,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,1,0,0,13,175,0,0,20,0,0,1,0,2,3,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,9,
0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
135,0,0,1,0,0,15,316,0,0,0,0,0,1,0,
150,0,0,1,0,0,15,335,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/11/10              Dirk Wong
Refine table 					   2014/11/20              Virginia Yun
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
#include "OLPspTxnEngine.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void OLPspTxnEngine(char cdebug)
{
        cDebug = cdebug;
}

int GetPspTxnEngine(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;

	char *csTmp;
	int iCnt;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getpsptxnengine_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_action[PD_ENGINE_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_action;

		/* varchar hv_trigger_type[PD_ENGINE_TRIGGER_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_trigger_type;

		/* varchar hv_bank_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_acct_type;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar	hv_input_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_input_channel;


		int	v_exec_seq;
		char	v_in_baid_txn;
		char	v_in_txn;
		char	v_in_post_baid_txn;
		char	v_in_post_txn;
		/* varchar	v_in_amt_type[PD_ENGINE_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_in_amt_type;

		/* varchar	v_in_amt_type_side[PD_AMT_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_in_amt_type_side;

		int	v_org_baid_txn;
		int	v_org_txn;
		int	v_post_baid_txn;
		int	v_post_txn;
		int	v_txn_action;
		/* varchar	v_to_post_txn_level[PD_ENGINE_PARTY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_to_post_txn_level;

		/* varchar	v_to_post_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_post_txn_code;

		/* varchar	v_baid_category[PD_BAID_CAT_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_baid_category;

		int	v_bal_rule_id;
		int	v_bf_status_rule_id;
		int	v_af_status_rule_id;
		/* varchar	v_next_action[PD_ENGINE_ACTION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_next_action;

		/* varchar	v_spc_action[PD_ENGINE_ACTION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_spc_action;


		short	ind_exec_seq = -1;
		short	ind_in_baid_txn = -1;
		short	ind_in_txn = -1;
		short	ind_in_post_baid_txn = -1;
		short	ind_in_post_txn = -1;
		short	ind_in_amt_type = -1;
		short	ind_in_amt_type_side = -1;
		short	ind_org_baid_txn = -1;
		short	ind_org_txn = -1;
		short	ind_post_baid_txn = -1;
		short	ind_post_txn = -1;
		short	ind_txn_action = -1;
		short	ind_to_post_txn_level = -1;
		short	ind_to_post_txn_code = -1;
		short	ind_baid_category = -1;
		short	ind_bal_rule_id = -1;
		short	ind_bf_status_rule_id = -1;
		short	ind_af_status_rule_id = -1;
		short	ind_next_action = -1;
		short	ind_spc_action = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "action", &csTmp)) {
		hv_action.len = strlen(csTmp);
		strncpy((char*)hv_action.arr, csTmp, hv_action.len);
DEBUGLOG(("OLPspTxnEngine action = [%.*s]\n", hv_action.len, (const char*)hv_action.arr));
	} else {
DEBUGLOG(("OLPspTxnEngine action not found!\n"));
		iRet = INT_ACTION_NOT_FOUND;
	}

	if (GetField_CString(hRls, "trigger_type", &csTmp)) {
		hv_trigger_type.len = strlen(csTmp);
		strncpy((char*)hv_trigger_type.arr, csTmp, hv_trigger_type.len);
DEBUGLOG(("OLPspTxnEngine trigger_type = [%.*s]\n", hv_trigger_type.len, (const char*)hv_trigger_type.arr));
	} else {
DEBUGLOG(("OLPspTxnEngine trigger_type not found!\n"));
		iRet = INT_TRIGGER_TYPE_NOT_FOUND;
	}

	if (GetField_CString(hRls, "bank_acct_type", &csTmp)) {
		hv_bank_acct_type.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_type.arr, csTmp, hv_bank_acct_type.len);
DEBUGLOG(("OLPspTxnEngine bank_acct_type = [%.*s]\n", hv_bank_acct_type.len, (const char*)hv_bank_acct_type.arr));
	} else {
DEBUGLOG(("OLPspTxnEngine bank_acct_type not found!\n"));
		iRet = INT_AC_NATURE_NOT_FOUND;
	}

	if (GetField_CString(hRls, "txn_code", &csTmp)) {
		hv_txn_code.len = strlen(csTmp);
		strncpy((char*)hv_txn_code.arr, csTmp, hv_txn_code.len);
DEBUGLOG(("OLPspTxnEngine txn_code = [%.*s]\n", hv_txn_code.len, (const char*)hv_txn_code.arr));
	} else {
DEBUGLOG(("OLPspTxnEngine txn_code not found!\n"));
		iRet = INT_TXN_CODE_NOT_FOUND;
	}

	if (GetField_CString(hRls, "input_channel", &csTmp)) {
		hv_input_channel.len = strlen(csTmp);
		strncpy((char*)hv_input_channel.arr, csTmp, hv_input_channel.len);
DEBUGLOG(("OLPspTxnEngine input_channel = [%.*s]\n", hv_input_channel.len, (const char*)hv_input_channel.arr));
	} else {
DEBUGLOG(("OLPspTxnEngine input_channel not found!\n"));
		iRet = INT_INPUT_CHANNEL_NOT_FOUND;
	}

	/* EXEC SQL DECLARE c_getpsptxnengine CURSOR FOR
		SELECT	OTE_EXEC_SEQ,
			OTE_IN_BAID_TXN,
			OTE_IN_TXN,
			OTE_IN_POST_BAID_TXN,
			OTE_IN_POST_TXN,
			OTE_IN_AMT_TYPE,
			OTE_IN_AMT_TYPE_SIDE,
			OTE_ORG_BAID_TXN,
			OTE_ORG_TXN,
			OTE_POST_BAID_TXN,
			OTE_POST_TXN,
			OTE_TXN_ACTION,
			OTE_TO_POST_TXN_LEVEL,
			OTE_TO_POST_TXN_CODE,
			OTE_BAID_CATEGORY,
			OTE_BAL_RULE_ID,
			OTE_BF_STATUS_RULE_ID,
			OTE_AF_STATUS_RULE_ID,
			OTE_NEXT_ACTION,
			OTE_SPC_ACTION
		FROM	OL_PSP_TXN_ENGINE 
		WHERE	OTE_ACTION = :hv_action
		AND	OTE_TRIGGER_TYPE = :hv_trigger_type
		AND	OTE_BANK_ACCT_TYPE = :hv_bank_acct_type
		AND	OTE_TXN_CODE = :hv_txn_code
		AND	OTE_INPUT_CHANNEL = :hv_input_channel
		AND	OTE_DISABLED = 0
		ORDER BY OTE_EXEC_SEQ; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getpsptxnengine; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_trigger_type;
  sqlstm.sqhstl[1] = (unsigned long )12;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_type;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_input_channel;
  sqlstm.sqhstl[4] = (unsigned long )5;
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
  if (sqlca.sqlcode < 0) goto getpsptxnengine_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getpsptxnengine
			INTO	:v_exec_seq:ind_exec_seq,
				:v_in_baid_txn:ind_in_baid_txn,
				:v_in_txn:ind_in_txn,
				:v_in_post_baid_txn:ind_in_post_baid_txn,
				:v_in_post_txn:ind_in_post_txn,
				:v_in_amt_type:ind_in_amt_type,
				:v_in_amt_type_side:ind_in_amt_type_side,
				:v_org_baid_txn:ind_org_baid_txn,
				:v_org_txn:ind_org_txn,
				:v_post_baid_txn:ind_post_baid_txn,
				:v_post_txn:ind_post_txn,
				:v_txn_action:ind_txn_action,
				:v_to_post_txn_level:ind_to_post_txn_level,
				:v_to_post_txn_code:ind_to_post_txn_code,
				:v_baid_category:ind_baid_category,
				:v_bal_rule_id:ind_bal_rule_id,
				:v_bf_status_rule_id:ind_bf_status_rule_id,
				:v_af_status_rule_id:ind_af_status_rule_id,
				:v_next_action:ind_next_action,
				:v_spc_action:ind_spc_action; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 20;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )40;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_exec_seq;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_exec_seq;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_in_baid_txn;
   sqlstm.sqhstl[1] = (unsigned long )1;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_in_baid_txn;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_in_txn;
   sqlstm.sqhstl[2] = (unsigned long )1;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_in_txn;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_in_post_baid_txn;
   sqlstm.sqhstl[3] = (unsigned long )1;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_in_post_baid_txn;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_in_post_txn;
   sqlstm.sqhstl[4] = (unsigned long )1;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_in_post_txn;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_in_amt_type;
   sqlstm.sqhstl[5] = (unsigned long )23;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_in_amt_type;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_in_amt_type_side;
   sqlstm.sqhstl[6] = (unsigned long )5;
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_in_amt_type_side;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_org_baid_txn;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_org_baid_txn;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_org_txn;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_org_txn;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_post_baid_txn;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_post_baid_txn;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_post_txn;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_post_txn;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_action;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_txn_action;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_to_post_txn_level;
   sqlstm.sqhstl[12] = (unsigned long )13;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_to_post_txn_level;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_to_post_txn_code;
   sqlstm.sqhstl[13] = (unsigned long )6;
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_to_post_txn_code;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_baid_category;
   sqlstm.sqhstl[14] = (unsigned long )13;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_baid_category;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_bal_rule_id;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_bal_rule_id;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_bf_status_rule_id;
   sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_bf_status_rule_id;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_af_status_rule_id;
   sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_af_status_rule_id;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_next_action;
   sqlstm.sqhstl[18] = (unsigned long )53;
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_next_action;
   sqlstm.sqinds[18] = (         int  )0;
   sqlstm.sqharm[18] = (unsigned long )0;
   sqlstm.sqadto[18] = (unsigned short )0;
   sqlstm.sqtdso[18] = (unsigned short )0;
   sqlstm.sqhstv[19] = (unsigned char  *)&v_spc_action;
   sqlstm.sqhstl[19] = (unsigned long )53;
   sqlstm.sqhsts[19] = (         int  )0;
   sqlstm.sqindv[19] = (         short *)&ind_spc_action;
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
   if (sqlca.sqlcode < 0) goto getpsptxnengine_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);


			if (ind_exec_seq >= 0) {
				PutField_Int(myHash, "exec_seq", v_exec_seq);
DEBUGLOG(("GetPspTxnEngine exec_seq = [%d]\n", v_exec_seq));
			}

			if (ind_in_baid_txn >= 0) {
				PutField_Char(myHash, "in_baid_txn", v_in_baid_txn);
DEBUGLOG(("GetPspTxnEngine in_baid_txn = [%c]\n", v_in_baid_txn));
			}

			if (ind_in_txn >= 0) {
				PutField_Char(myHash, "in_txn", v_in_txn);
DEBUGLOG(("GetPspTxnEngine in_txn = [%c]\n", v_in_txn));
			}

			if (ind_in_post_baid_txn >= 0) {
				PutField_Char(myHash, "in_post_baid_txn", v_in_post_baid_txn);
DEBUGLOG(("GetPspTxnEngine in_post_baid_txn = [%c]\n", v_in_post_baid_txn));
			}

			if (ind_in_post_txn >= 0) {
				PutField_Char(myHash, "in_post_txn", v_in_post_txn);
DEBUGLOG(("GetPspTxnEngine in_post_txn = [%c]\n", v_in_post_txn));
			}

			if (ind_in_amt_type >= 0) {
				v_in_amt_type.arr[v_in_amt_type.len] = '\0';
				PutField_CString(myHash, "in_amt_type", (const char*)v_in_amt_type.arr);
DEBUGLOG(("GetPspTxnEngine in_amt_type = [%s]\n", v_in_amt_type.arr));
			}

			if (ind_in_amt_type_side >= 0) {
				v_in_amt_type_side.arr[v_in_amt_type_side.len] = '\0';
				PutField_CString(myHash, "in_amt_type_side", (const char*)v_in_amt_type_side.arr);
DEBUGLOG(("GetPspTxnEngine in_amt_type_side = [%s]\n", v_in_amt_type_side.arr));
			}

			if (ind_org_baid_txn >= 0) {
				PutField_Int(myHash, "org_baid_txn", v_org_baid_txn);
DEBUGLOG(("GetPspTxnEngine org_baid_txn = [%d]\n", v_org_baid_txn));
			}

			if (ind_org_txn >= 0) {
				PutField_Int(myHash, "org_txn", v_org_txn);
DEBUGLOG(("GetPspTxnEngine org_txn = [%d]\n", v_org_txn));
			}

			if (ind_post_baid_txn >= 0) {
				PutField_Int(myHash, "post_baid_txn", v_post_baid_txn);
DEBUGLOG(("GetPspTxnEngine post_baid_txn = [%d]\n", v_post_baid_txn));
			}

			if (ind_post_txn >= 0) {
				PutField_Int(myHash, "post_txn", v_post_txn);
DEBUGLOG(("GetPspTxnEngine post_txn = [%d]\n", v_post_txn));
			}

			if (ind_txn_action >= 0) {
				PutField_Int(myHash, "txn_action", v_txn_action);
DEBUGLOG(("GetPspTxnEngine txn_action = [%d]\n", v_txn_action));
			}

			if (ind_to_post_txn_level >= 0) {
				v_to_post_txn_level.arr[v_to_post_txn_level.len] = '\0';
				PutField_CString(myHash, "to_post_txn_level", (const char*)v_to_post_txn_level.arr);
DEBUGLOG(("GetPspTxnEngine to_post_txn_level = [%s]\n", v_to_post_txn_level.arr));
			}

			if (ind_to_post_txn_code >= 0) {
				v_to_post_txn_code.arr[v_to_post_txn_code.len] = '\0';
				PutField_CString(myHash, "to_post_txn_code", (const char*)v_to_post_txn_code.arr);
DEBUGLOG(("GetPspTxnEngine to_post_txn_code = [%s]\n", v_to_post_txn_code.arr));
			}

			if (ind_baid_category >= 0) {
				v_baid_category.arr[v_baid_category.len] = '\0';
				PutField_CString(myHash, "baid_category", (const char*)v_baid_category.arr);
DEBUGLOG(("GetPspTxnEngine baid_category = [%s]\n", v_baid_category.arr));
			}

			if (ind_bal_rule_id >= 0) {
				PutField_Int(myHash, "bal_rule_id", v_bal_rule_id);
DEBUGLOG(("GetPspTxnEngine bal_rule_id = [%d]\n", v_bal_rule_id));
			}

			if (ind_bf_status_rule_id >= 0) {
				PutField_Int(myHash, "bf_status_rule_id", v_bf_status_rule_id);
DEBUGLOG(("GetPspTxnEngine bf_status_rule_id = [%d]\n", v_bf_status_rule_id));
			}

			if (ind_af_status_rule_id >= 0) {
				PutField_Int(myHash, "af_status_rule_id", v_af_status_rule_id);
DEBUGLOG(("GetPspTxnEngine af_status_rule_id = [%d]\n", v_af_status_rule_id));
			}

			if (ind_next_action >= 0) {
				v_next_action.arr[v_next_action.len] = '\0';
				PutField_CString(myHash, "next_action", (const char*)v_next_action.arr);
DEBUGLOG(("GetPspTxnEngine next_action = [%s]\n", v_next_action.arr));
			}


			if (ind_spc_action >= 0) {
				v_spc_action.arr[v_spc_action.len] = '\0';
				PutField_CString(myHash, "spc_action", (const char*)v_spc_action.arr);
DEBUGLOG(("GetPspTxnEngine spc_action = [%s]\n", v_spc_action.arr));
			}

			RecordSet_Add(myRec, myHash);
		}
		/* EXEC SQL CLOSE c_getpsptxnengine; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 20;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )135;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getpsptxnengine_error;
}



		if (iCnt > 0) {
DEBUGLOG(("GetPspTxnEngine: hash added\n"));
		} else {
DEBUGLOG(("GetPspTxnEngine no record found\n"));
ERRLOG("OLPspTxnEngine: GetPspTxnEngine no record found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetPspTxnEngine Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getpsptxnengine_error:
DEBUGLOG(("getpsptxnengine_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPspTxnEngine getstmtrule_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getpsptxnengine; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )150;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpsptxnengine_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

