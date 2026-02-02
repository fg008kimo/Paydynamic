
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
    "OLTxnEngine.pc"
};


static unsigned int sqlctx = 1297283;


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
   unsigned char  *sqhstv[19];
   unsigned long  sqhstl[19];
            int   sqhsts[19];
            short *sqindv[19];
            int   sqinds[19];
   unsigned long  sqharm[19];
   unsigned long  *sqharc[19];
   unsigned short  sqadto[19];
   unsigned short  sqtdso[19];
} sqlstm = {12,19};

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
"SELECT T1 . OTE_INPUT_BANK_STMT , T1 . OTE_INPUT_SYSTEM_TXN , T1 . OTE_ALLO\
W_PENDING_FUND , T1 . OTE_ALLOW_STMT_PARTIAL , T1 . OTE_ALLOW_TXN_PARTIAL , T\
1 . OTE_ACTION_ID , T1 . OTE_INCLUDE_BANK_CHARGE , T1 . OTE_INCLUDE_INTEREST \
, T2 . EAM_ACTION_SEQ , T2 . EAM_SPC_ACTION , T2 . EAM_BEFORE_STATUS_RULE , T\
2 . EAM_ACTION_DETAIL_ID , T3 . EAL_ACTION_DESC , T3 . EAL_ACTION_TYPE , T3 .\
 EAL_ACTION_LEVEL , T3 . EAL_AFTER_STATUS_RULE , T3 . EAL_BAL_RULE , T3 . EAL\
_TXN_AMT_TAG , T2 . EAM_LINKAGE FROM OL_TXN_ENGINE T1 , OL_TXN_ENGINE_ACTION_\
MAP T2 , OL_TXN_ENGINE_ACTION_LIST T3 WHERE T1 . OTE_BANK_STMT_TYPE = :b0 AND\
 T1 . OTE_ACTIVITY = :b1 AND T1 . OTE_CHANNEL = :b2 AND T1 . OTE_TRIGGER_TYPE\
 = :b3 AND T1 . OTE_RECON_TYPE = :b4 AND T1 . OTE_ACTION_ID = T2 . EAM_ACTION\
_ID AND T2 . EAM_ACTION_DETAIL_ID = T3 . EAL_ACTION_DETAIL_ID ORDER BY T2 . E\
AM_ACTION_SEQ            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,870,0,9,181,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,1,0,0,13,184,0,0,19,0,0,1,0,2,1,0,0,2,1,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,
0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
3,0,0,2,3,0,0,2,9,0,0,2,3,0,0,
131,0,0,1,0,0,15,330,0,0,0,0,0,1,0,
146,0,0,1,0,0,15,348,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/08              [WWK]
Field Added					   2014/12/22		   [MSN]
make debulog more clear				   2021/04/30		   [MSN]
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
#include "OLTxnEngine.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char    cDebug;

void OLTxnEngine(char cdebug)
{
        cDebug = cdebug;
}

int GetTxnEngine(const hash_t *hRls, recordset_t *myRec)
{
	int iRet = PD_OK;
	int	iCnt = 0;

	char*	csTmp;
	char*	csBuf = (char*) malloc (PD_TMP_BUF_LEN +1);
	memset(csBuf, 0, sizeof(csBuf));

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnengine_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_activity[PD_ENGINE_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_activity;

		/* varchar	hv_bank_stmt_type[PD_TXN_GRP_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_stmt_type;

		/* varchar	hv_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel;

		/* varchar hv_trigger_type[PD_ENGINE_TRIGGER_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_trigger_type;

		/* varchar hv_recon_type[PD_ENGINE_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_recon_type;


		char	v_input_bank_stmt;
		char	v_input_system_txn;
		int	v_allow_pending_fund;
		int	v_allow_stmt_partial;
		int	v_allow_txn_partial;
		int	v_action_id;
		int	v_action_seq;
		int	v_spc_action;
		int	v_before_status_rule;
		int	v_action_detail_id;
		/* varchar	v_action_desc[PD_ENGINE_ACTION_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_action_desc;

		int	v_action_type;
		/* varchar	v_action_level[PD_ENGINE_TYPE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_action_level;

		int	v_after_status_rule;
		int	v_bal_rule;
		/* varchar	v_txn_amt_tag[PD_TAG_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_txn_amt_tag;

		int	v_linkage;
		int	v_include_bank_charge;
		int	v_include_interest;

		short	ind_input_bank_stmt=-1;
		short	ind_input_system_txn=-1;
		short	ind_allow_pending_fund=-1;
		short	ind_allow_stmt_partial=-1;
		short	ind_allow_txn_partial=-1;
		short	ind_action_id=-1;
		short	ind_action_seq=-1;
		short	ind_spc_action=-1;
		short	ind_before_status_rule=-1;
		short	ind_action_detail_id=-1;
		short	ind_action_desc=-1;
		short	ind_action_type=-1;
		short	ind_action_level=-1;
		short	ind_after_status_rule=-1;
		short	ind_bal_rule=-1;
		short	ind_txn_amt_tag=-1;
		short	ind_linkage=-1;
		short	ind_include_bank_charge=-1;
		short	ind_include_interest=-1;
		

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "activity", &csTmp)) {
		hv_activity.len = strlen(csTmp);
		memcpy(hv_activity.arr, csTmp, hv_activity.len);
DEBUGLOG(("OLTxnEngine activity = [%.*s]\n", hv_activity.len,hv_activity.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("OLTxnEngine activity NOT FOUND!\n"));
ERRLOG("GetTxnEngine::OLTxnEngine activity NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "bank_stmt_type", &csTmp)) {
		hv_bank_stmt_type.len = strlen(csTmp);
		memcpy(hv_bank_stmt_type.arr, csTmp, hv_bank_stmt_type.len);
DEBUGLOG(("OLTxnEngine bank_stmt_type = [%.*s]\n", hv_bank_stmt_type.len,hv_bank_stmt_type.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("OLTxnEngine bank_stmt_type NOT FOUND!\n"));
ERRLOG("GetTxnEngine::OLTxnEngine bank_stmt_type NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "channel", &csTmp)) {
		hv_channel.len = strlen(csTmp);
		memcpy(hv_channel.arr, csTmp, hv_channel.len);
DEBUGLOG(("OLTxnEngine channel = [%.*s]\n", hv_channel.len,hv_channel.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("OLTxnEngine channel NOT FOUND!\n"));
ERRLOG("GetTxnEngine::OLTxnEngine channel NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "trigger_type", &csTmp)) {
		hv_trigger_type.len = strlen(csTmp);
		memcpy(hv_trigger_type.arr, csTmp, hv_trigger_type.len);
DEBUGLOG(("OLTxnEngine trigger_type = [%.*s]\n", hv_trigger_type.len,hv_trigger_type.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("OLTxnEngine trigger_type NOT FOUND!\n"));
ERRLOG("GetTxnEngine::OLTxnEngine trigger_type NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "recon_type", &csTmp)) {
		hv_recon_type.len = strlen(csTmp);
		memcpy(hv_recon_type.arr, csTmp, hv_recon_type.len);
DEBUGLOG(("OLTxnEngine recon_type = [%.*s]\n", hv_recon_type.len,hv_recon_type.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("OLTxnEngine recon_type NOT FOUND!\n"));
ERRLOG("GetTxnEngine::OLTxnEngine recon_type NOT FOUND!\n");
	}

	if (iRet == PD_OK) {
	   /* EXEC SQL DECLARE c_gettxnengine CURSOR FOR
		SELECT	T1.OTE_INPUT_BANK_STMT,
			T1.OTE_INPUT_SYSTEM_TXN,
			T1.OTE_ALLOW_PENDING_FUND,
			T1.OTE_ALLOW_STMT_PARTIAL,
			T1.OTE_ALLOW_TXN_PARTIAL,
			T1.OTE_ACTION_ID,
			T1.OTE_INCLUDE_BANK_CHARGE,
			T1.OTE_INCLUDE_INTEREST,
			T2.EAM_ACTION_SEQ,
			T2.EAM_SPC_ACTION,
			T2.EAM_BEFORE_STATUS_RULE,
			T2.EAM_ACTION_DETAIL_ID,
			T3.EAL_ACTION_DESC,
			T3.EAL_ACTION_TYPE,
			T3.EAL_ACTION_LEVEL,
			T3.EAL_AFTER_STATUS_RULE,
			T3.EAL_BAL_RULE,
			T3.EAL_TXN_AMT_TAG,
			T2.EAM_LINKAGE
		FROM	OL_TXN_ENGINE T1,
			OL_TXN_ENGINE_ACTION_MAP T2,
			OL_TXN_ENGINE_ACTION_LIST T3
		WHERE	T1.OTE_BANK_STMT_TYPE = :hv_bank_stmt_type
		AND	T1.OTE_ACTIVITY = :hv_activity
		AND	T1.OTE_CHANNEL = :hv_channel
		AND	T1.OTE_TRIGGER_TYPE = :hv_trigger_type
		AND	T1.OTE_RECON_TYPE = :hv_recon_type
		AND	T1.OTE_ACTION_ID = T2.EAM_ACTION_ID
		AND	T2.EAM_ACTION_DETAIL_ID = T3.EAL_ACTION_DETAIL_ID
		ORDER BY T2.EAM_ACTION_SEQ; */ 


		/* EXEC SQL OPEN c_gettxnengine; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_stmt_type;
  sqlstm.sqhstl[0] = (unsigned long )52;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_activity;
  sqlstm.sqhstl[1] = (unsigned long )52;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_channel;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_trigger_type;
  sqlstm.sqhstl[3] = (unsigned long )12;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_recon_type;
  sqlstm.sqhstl[4] = (unsigned long )12;
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
  if (sqlca.sqlcode < 0) goto gettxnengine_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_gettxnengine
			INTO	:v_input_bank_stmt:ind_input_bank_stmt,
				:v_input_system_txn:ind_input_system_txn,
				:v_allow_pending_fund:ind_allow_pending_fund,
				:v_allow_stmt_partial:ind_allow_stmt_partial,
				:v_allow_txn_partial:ind_allow_txn_partial,
				:v_action_id:ind_action_id,
				:v_include_bank_charge:ind_include_bank_charge,
				:v_include_interest:ind_include_interest,
				:v_action_seq:ind_action_seq,
				:v_spc_action:ind_spc_action,
				:v_before_status_rule:ind_before_status_rule,
				:v_action_detail_id:ind_action_detail_id,
				:v_action_desc:ind_action_desc,
				:v_action_type:ind_action_type,
				:v_action_level:ind_action_level,
				:v_after_status_rule:ind_after_status_rule,
				:v_bal_rule:ind_bal_rule,
				:v_txn_amt_tag:ind_txn_amt_tag,
				:v_linkage:ind_linkage; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 19;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_input_bank_stmt;
   sqlstm.sqhstl[0] = (unsigned long )1;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_input_bank_stmt;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_input_system_txn;
   sqlstm.sqhstl[1] = (unsigned long )1;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_input_system_txn;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_allow_pending_fund;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_allow_pending_fund;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_allow_stmt_partial;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_allow_stmt_partial;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_allow_txn_partial;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_allow_txn_partial;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_action_id;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_action_id;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_include_bank_charge;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_include_bank_charge;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_include_interest;
   sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_include_interest;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_action_seq;
   sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_action_seq;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_spc_action;
   sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_spc_action;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_before_status_rule;
   sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_before_status_rule;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_action_detail_id;
   sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_action_detail_id;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_action_desc;
   sqlstm.sqhstl[12] = (unsigned long )53;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_action_desc;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_action_type;
   sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_action_type;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_action_level;
   sqlstm.sqhstl[14] = (unsigned long )13;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_action_level;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_after_status_rule;
   sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_after_status_rule;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_bal_rule;
   sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_bal_rule;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
   sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_amt_tag;
   sqlstm.sqhstl[17] = (unsigned long )28;
   sqlstm.sqhsts[17] = (         int  )0;
   sqlstm.sqindv[17] = (         short *)&ind_txn_amt_tag;
   sqlstm.sqinds[17] = (         int  )0;
   sqlstm.sqharm[17] = (unsigned long )0;
   sqlstm.sqadto[17] = (unsigned short )0;
   sqlstm.sqtdso[17] = (unsigned short )0;
   sqlstm.sqhstv[18] = (unsigned char  *)&v_linkage;
   sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[18] = (         int  )0;
   sqlstm.sqindv[18] = (         short *)&ind_linkage;
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
   if (sqlca.sqlcode < 0) goto gettxnengine_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			if(iCnt == 1){
				if (ind_input_bank_stmt >= 0) {
					PutField_Char(myHash, "input_bank_stmt", v_input_bank_stmt);
//DEBUGLOG(("GetTxnEngine input_bank_stmt = [%c]\n",v_input_bank_stmt));
				}

				if (ind_input_system_txn >= 0) {
					PutField_Char(myHash, "input_system_txn", v_input_system_txn);
//DEBUGLOG(("GetTxnEngine input_system_txn = [%c]\n",v_input_system_txn));
				}

				if (ind_allow_pending_fund >= 0) {
					PutField_Int(myHash, "allow_pending_fund", v_allow_pending_fund);
//DEBUGLOG(("GetTxnEngine allow_pending_fund = [%d]\n",v_allow_pending_fund));
				}

				if (ind_allow_stmt_partial >= 0) {
					PutField_Int(myHash, "allow_stmt_partial", v_allow_stmt_partial);
//DEBUGLOG(("GetTxnEngine allow_stmt_partial = [%d]\n",v_allow_stmt_partial));
				}

				if (ind_allow_txn_partial >= 0) {
					PutField_Int(myHash, "allow_txn_partial", v_allow_txn_partial);
//DEBUGLOG(("GetTxnEngine allow_txn_partial = [%d]\n",v_allow_txn_partial));
				}

				if (ind_include_bank_charge>= 0) {
					PutField_Int(myHash, "include_bank_charge", v_include_bank_charge);
//DEBUGLOG(("GetTxnEngine include_bank_charge = [%d]\n",v_include_bank_charge));
				}

				if (ind_include_interest>= 0) {
					PutField_Int(myHash, "include_interest", v_include_interest);
//DEBUGLOG(("GetTxnEngine include_interest = [%d]\n",v_include_interest));
				}

				if (ind_action_id >= 0) {
					PutField_Int(myHash, "action_id", v_action_id);
//DEBUGLOG(("GetTxnEngine action_id = [%d]\n",v_action_id));
				}

DEBUGLOG(("in_stmt[%c], in_txn[%c], allow_pf[%d], stmt_partial[%d], txn_partial[%d], bk_charge[%d], inst[%d], action_id[%d]\n",v_input_bank_stmt, v_input_system_txn, v_allow_pending_fund, v_allow_stmt_partial, v_allow_txn_partial, v_include_bank_charge, v_include_interest, v_action_id));
			}

			if (ind_action_seq >= 0) {
				PutField_Int(myHash, "action_seq", v_action_seq);
				sprintf(csBuf, "Seq[%d]:", v_action_seq);
//DEBUGLOG(("GetTxnEngine action_seq = [%d]\n",v_action_seq));
			}

			if (ind_spc_action >= 0) {
				PutField_Int(myHash, "spc_action", v_spc_action);
				sprintf(csBuf, "%s spc_act[%d] ", csBuf, v_spc_action);
//DEBUGLOG(("GetTxnEngine spc_action = [%d]\n",v_spc_action));
			}

			if (ind_before_status_rule >= 0) {
				PutField_Int(myHash, "bf_status_rule_id", v_before_status_rule);
				sprintf(csBuf, "%s bf_status[%d] ", csBuf, v_before_status_rule);
//DEBUGLOG(("GetTxnEngine before_status_rule = [%d]\n",v_before_status_rule));
			}

			if (ind_action_detail_id >= 0) {
				PutField_Int(myHash, "action_detail_id", v_action_detail_id);
				sprintf(csBuf, "%s act_dt[%d] ", csBuf, v_action_detail_id);
//DEBUGLOG(("GetTxnEngine action_detail_id = [%d]\n",v_action_detail_id));
			}

			if (ind_action_desc >= 0) {
				v_action_desc.arr[v_action_desc.len] = '\0';
				PutField_CString(myHash, "action_desc", (char*)v_action_desc.arr);
				sprintf(csBuf, "%s act[%s] ", csBuf, (char*)v_action_desc.arr);
//DEBUGLOG(("GetTxnEngine action_desc = [%s]\n",(char*)v_action_desc.arr));
			}

			if (ind_action_type >= 0) {
				PutField_Int(myHash, "action_type", v_action_type);
				sprintf(csBuf, "%s type[%d] ", csBuf, v_action_type);
//DEBUGLOG(("GetTxnEngine action_type = [%d]\n",v_action_type));
			}

			if (ind_action_level >= 0) {
				v_action_level.arr[v_action_level.len] = '\0';
				PutField_CString(myHash, "action_level", (char*)v_action_level.arr);
				sprintf(csBuf, "%s lv[%s] ", csBuf, (char*)v_action_level.arr);
//DEBUGLOG(("GetTxnEngine action_level = [%s]\n",(char*)v_action_level.arr));
			}

			if (ind_after_status_rule >= 0) {
				PutField_Int(myHash, "af_status_rule_id", v_after_status_rule);
				sprintf(csBuf, "%s af_status[%d] ", csBuf, v_after_status_rule);
//DEBUGLOG(("GetTxnEngine after_status_rule = [%d]\n",v_after_status_rule));
			}

			if (ind_bal_rule >= 0) {
				PutField_Int(myHash, "bal_rule_id", v_bal_rule);
				sprintf(csBuf, "%s bal[%d] ", csBuf, v_bal_rule);
//DEBUGLOG(("GetTxnEngine bal_rule = [%d]\n",v_bal_rule));
			}

			if (ind_txn_amt_tag >= 0) {
				v_txn_amt_tag.arr[v_txn_amt_tag.len] = '\0';
				PutField_CString(myHash, "txn_amt_tag", (char*)v_txn_amt_tag.arr);
				sprintf(csBuf, "%s amt[%s] ", csBuf, (char*)v_txn_amt_tag.arr);
//DEBUGLOG(("GetTxnEngine txn_amt_tag = [%s]\n",v_txn_amt_tag.arr));
			}

			if (ind_linkage >= 0) {
				PutField_Int(myHash, "linkage", v_linkage);
				sprintf(csBuf, "%s link[%d] ", csBuf, v_linkage);
//DEBUGLOG(("GetTxnEngine linkage = [%d]\n",v_linkage));
			}

DEBUGLOG((" %s\n", csBuf));
			RecordSet_Add(myRec, myHash);

		}
		/* EXEC SQL CLOSE c_gettxnengine; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 19;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )131;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto gettxnengine_error;
}



		if (iCnt <= 0) {
DEBUGLOG(("GetTxnEngine no record found\n"));
ERRLOG("OLTxnEngine: GetTxnEngine no record found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetTxnEngine Normal Exit! iRet = [%d]\n", iRet));
	FREE_ME(csBuf);
	return iRet;

gettxnengine_error:
DEBUGLOG(("gettxnengine_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnEngine getstmtrule_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_gettxnengine; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )146;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnengine_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

