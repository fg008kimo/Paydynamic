
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "OLStmtMatchRuleGroup.pc"
};


static unsigned int sqlctx = 662727755;


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

 static char *sq0001 = 
"SELECT OSMG_SUB_RULE_ID , OSMG_FIRST_BAID_TXN_CODE , OSMG_SECOND_BAID_TXN_C\
ODE , OSMG_NEXT_ENGINE_ACTION , OSMG_NEXT_ENGINE_TXN_CODE , OSMG_NEXT_ENGINE_\
RECON_TYPE FROM OL_STMT_MATCH_RULE_GROUP WHERE OSMG_RULE_ID = :b0 AND OSMG_DI\
SABLED = 0 ORDER BY OSMG_SUB_RULE_ID            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,277,0,9,86,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,89,0,0,6,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,
63,0,0,1,0,0,15,150,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,168,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/07              [WCS]
Reduce Log                                         2021/05/17              [WCS]
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
#include "OLStmtMatchRuleGroup.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


static char cDebug;

void OLStmtMatchRuleGroup(char cdebug)
{
	cDebug = cdebug;
}


int GetStmtMatchRule(const hash_t *hContext, recordset_t *myRec)
{
	int iRet = PD_OK;
	int iCnt = 0;
	int iTmp;

	hash_t *myHash;

DEBUGLOG(("GetStmtMatchRule Start\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmtmatchrule_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int hv_rule_id;

		int v_sub_rule_id;
		/* varchar v_first_baid_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_first_baid_txn_code;

		/* varchar v_second_baid_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_second_baid_txn_code;

		/* varchar v_next_engine_action[PD_ENGINE_ACTION_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_next_engine_action;

		/* varchar v_next_engine_txn_code[PD_TXN_GRP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_next_engine_txn_code;

		/* varchar v_next_engine_recon_type[PD_ENGINE_RECON_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_next_engine_recon_type;


		short ind_sub_rule_id = -1;
		short ind_first_baid_txn_code = -1;
		short ind_second_baid_txn_code = -1;
		short ind_next_engine_action = -1;
		short ind_next_engine_txn_code = -1;
		short ind_next_engine_recon_type = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_Int(hContext, "rule_id", &iTmp)) {
		hv_rule_id = iTmp;
DEBUGLOG(("rule_id = [%d]\n", hv_rule_id));
	} else {
DEBUGLOG(("rule_id not found!\n"));
		iRet = PD_ERR;
	}

	/* EXEC SQL DECLARE c_getstmtmatchrule CURSOR FOR
		SELECT	OSMG_SUB_RULE_ID,
			OSMG_FIRST_BAID_TXN_CODE,
			OSMG_SECOND_BAID_TXN_CODE,
			OSMG_NEXT_ENGINE_ACTION,
			OSMG_NEXT_ENGINE_TXN_CODE,
			OSMG_NEXT_ENGINE_RECON_TYPE
		FROM	OL_STMT_MATCH_RULE_GROUP
		WHERE	OSMG_RULE_ID = :hv_rule_id
		AND	OSMG_DISABLED = 0
		ORDER BY	OSMG_SUB_RULE_ID; */ 


	if (iRet == PD_OK) {
		/* EXEC SQL OPEN c_getstmtmatchrule; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_rule_id;
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
  if (sqlca.sqlcode < 0) goto getstmtmatchrule_error;
}



		for (;;) {
			/* EXEC SQL FETCH c_getstmtmatchrule
			INTO	:v_sub_rule_id:ind_sub_rule_id,
				:v_first_baid_txn_code:ind_first_baid_txn_code,
				:v_second_baid_txn_code:ind_second_baid_txn_code,
				:v_next_engine_action:ind_next_engine_action,
				:v_next_engine_txn_code:ind_next_engine_txn_code,
				:v_next_engine_recon_type:ind_next_engine_recon_type; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_sub_rule_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_sub_rule_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_first_baid_txn_code;
   sqlstm.sqhstl[1] = (unsigned long )6;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_first_baid_txn_code;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_second_baid_txn_code;
   sqlstm.sqhstl[2] = (unsigned long )6;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_second_baid_txn_code;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_next_engine_action;
   sqlstm.sqhstl[3] = (unsigned long )53;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_next_engine_action;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_next_engine_txn_code;
   sqlstm.sqhstl[4] = (unsigned long )53;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_next_engine_txn_code;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_next_engine_recon_type;
   sqlstm.sqhstl[5] = (unsigned long )13;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_next_engine_recon_type;
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
   if (sqlca.sqlcode < 0) goto getstmtmatchrule_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

			// sub_rule_id
			if (ind_sub_rule_id >= 0) {
				PutField_Int(myHash, "sub_rule_id", v_sub_rule_id);
DEBUGLOG(("  sub_rule_id = [%d]\n", v_sub_rule_id));
			}

			// first_baid_txn_code
			if (ind_first_baid_txn_code >= 0) {
				v_first_baid_txn_code.arr[v_first_baid_txn_code.len] = '\0';
				PutField_CString(myHash, "first_baid_txn_code", (const char*)v_first_baid_txn_code.arr);
DEBUGLOG(("    first_baid_txn_code = [%s]\n", (const char*)v_first_baid_txn_code.arr));
			}

			// second_baid_txn_code
			if (ind_second_baid_txn_code >= 0) {
				v_second_baid_txn_code.arr[v_second_baid_txn_code.len] = '\0';
				PutField_CString(myHash, "second_baid_txn_code", (const char*)v_second_baid_txn_code.arr);
DEBUGLOG(("    second_baid_txn_code = [%s]\n", (const char*)v_second_baid_txn_code.arr));
			}

			// next_engine_action
			if (ind_next_engine_action >= 0) {
				v_next_engine_action.arr[v_next_engine_action.len] = '\0';
				PutField_CString(myHash, "next_engine_action", (const char*)v_next_engine_action.arr);
DEBUGLOG(("    next_engine_action = [%s]\n", (const char*)v_next_engine_action.arr));
			}

			// next_engine_txn_code
			if (ind_next_engine_txn_code >= 0) {
				v_next_engine_txn_code.arr[v_next_engine_txn_code.len] = '\0';
				PutField_CString(myHash, "next_engine_txn_code", (const char*)v_next_engine_txn_code.arr);
DEBUGLOG(("    next_engine_txn_code = [%s]\n", (const char*)v_next_engine_txn_code.arr));
			}

			// next_engine_recon_type
			if (ind_next_engine_recon_type >= 0) {
				v_next_engine_recon_type.arr[v_next_engine_recon_type.len] = '\0';
				PutField_CString(myHash, "next_engine_recon_type", (const char*)v_next_engine_recon_type.arr);
DEBUGLOG(("    next_engine_recon_type = [%s]\n", (const char*)v_next_engine_recon_type.arr));
			}

			RecordSet_Add(myRec, myHash);
		}

		/* EXEC SQL CLOSE c_getstmtmatchrule; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )63;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getstmtmatchrule_error;
}



		if (iCnt == 0) {
DEBUGLOG(("not found\n"));
ERRLOG("OLStmtMatchRuleGroup:: GetStmtMatchRule not found\n");
			iRet = PD_ERR;
		}
	}

DEBUGLOG(("GetStmtMatchRule Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getstmtmatchrule_error:
DEBUGLOG(("getstmtmatchrule_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtMatchRuleGroup getstmtmatchrule_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_getstmtmatchrule; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )78;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

