
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
    "OLTxnEngineActionList.pc"
};


static unsigned int sqlctx = 1328563595;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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
"SELECT EAL_ACTION_DESC , EAL_ACTION_TYPE , EAL_ACTION_LEVEL , EAL_AFTER_STA\
TUS_RULE , EAL_BAL_RULE , EAL_TXN_AMT_TAG , EAL_LINKAGE FROM OL_TXN_ENGINE_AC\
TION_LIST WHERE EAL_ACTION_DETAIL_ID = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,206,0,9,71,0,2049,1,1,0,1,0,1,3,0,0,
24,0,0,1,0,0,13,73,0,0,7,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,9,0,
0,2,3,0,0,
67,0,0,1,0,0,15,129,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,139,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/12/03              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTxnEngineActionList.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;


void OLTxnEngineActionList(char cdebug)
{
	cDebug = cdebug;
}

int GetTxnEngineActionList(const int iActionDetailId, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnengineactionlist_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_action_detail_id;

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

		short	ind_action_desc = -1;
		short	ind_action_type = -1;
		short	ind_action_level = -1;
		short	ind_after_status_rule = -1;
		short	ind_bal_rule = -1;
		short	ind_txn_amt_tag = -1;
		short	ind_linkage = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_action_detail_id = iActionDetailId;
DEBUGLOG(("GetTxnEngineActionList action_detail_id = [%d]\n", hv_action_detail_id));

	/* EXEC SQL DECLARE c_cursor_getactionlist CURSOR FOR
		SELECT	EAL_ACTION_DESC,
			EAL_ACTION_TYPE,
			EAL_ACTION_LEVEL,
			EAL_AFTER_STATUS_RULE,
			EAL_BAL_RULE,
			EAL_TXN_AMT_TAG,
			EAL_LINKAGE
		FROM	OL_TXN_ENGINE_ACTION_LIST
		WHERE	EAL_ACTION_DETAIL_ID = :hv_action_detail_id; */ 


	/* EXEC SQL OPEN c_cursor_getactionlist; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_action_detail_id;
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
 if (sqlca.sqlcode < 0) goto gettxnengineactionlist_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getactionlist
		INTO
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
  sqlstm.arrsiz = 7;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_action_desc;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_action_desc;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_action_type;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_action_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_action_level;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_action_level;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_after_status_rule;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_after_status_rule;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_bal_rule;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_bal_rule;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_amt_tag;
  sqlstm.sqhstl[5] = (unsigned long )28;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_amt_tag;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_linkage;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_linkage;
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
  if (sqlca.sqlcode < 0) goto gettxnengineactionlist_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

DEBUGLOG(("GetTxnEngineActionList found record\n"));

		if (ind_action_desc >= 0) {
			v_action_desc.arr[v_action_desc.len] = '\0';
			PutField_CString(hRec, "action_desc", (const char*)v_action_desc.arr);
DEBUGLOG(("GetTxnEngineActionList cac = [%s]\n", v_action_desc.arr));
		}

                if (ind_action_type >= 0) {
                        PutField_Int(hRec,"action_type", v_action_type);
DEBUGLOG(("GetTxnEngineActionList action_type = [%d]\n",v_action_type));
                }

		if (ind_action_level >= 0) {
			v_action_level.arr[v_action_level.len] = '\0';
			PutField_CString(hRec, "action_level", (const char*)v_action_level.arr);
DEBUGLOG(("GetTxnEngineActionList action_level = [%s]\n", v_action_level.arr));
		}

                if (ind_after_status_rule >= 0) {
                        PutField_Int(hRec,"after_status_rule", v_after_status_rule);
DEBUGLOG(("GetTxnEngineActionList after_status_rule = [%d]\n",v_after_status_rule));
                }

                if (ind_bal_rule >= 0) {
                        PutField_Int(hRec,"bal_rule", v_bal_rule);
DEBUGLOG(("GetTxnEngineActionList bal_rule = [%d]\n",v_bal_rule));
                }

		if (ind_txn_amt_tag >= 0) {
			v_txn_amt_tag.arr[v_txn_amt_tag.len] = '\0';
			PutField_CString(hRec, "txn_amt_tag", (const char*)v_txn_amt_tag.arr);
DEBUGLOG(("GetTxnEngineActionList txn_amt_tag = [%s]\n", v_txn_amt_tag.arr));
		}

		if (ind_linkage >= 0) {
			PutField_Int(hRec, "linkage", v_linkage);
DEBUGLOG(("GetTxnEngineActionList linkage = [%d]\n", v_linkage));
		}

	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getactionlist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )67;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnengineactionlist_error;
}



DEBUGLOG(("GetTxnEngineActionList Normal Exit\n"));
	return PD_OK;

gettxnengineactionlist_error:
DEBUGLOG(("gettxnengineactionlist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getactionlist; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

