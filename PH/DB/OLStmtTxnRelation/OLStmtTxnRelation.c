
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
    "OLStmtTxnRelation.pc"
};


static unsigned int sqlctx = 82990491;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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

 static char *sq0004 = 
"select ostp_txn_id into :b0:b1 from ol_stmt_txn_relation where ostp_stmt_tx\
n_id = :b2            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,158,0,6,75,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,2,86,0,4,129,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
59,0,0,3,86,0,4,177,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
82,0,0,4,97,0,9,233,0,2049,2,1,0,1,0,2,9,0,0,1,9,0,0,
105,0,0,4,0,0,13,236,0,0,1,0,0,1,0,2,9,0,0,
124,0,0,4,0,0,15,258,0,0,0,0,0,1,0,
139,0,0,4,0,0,15,276,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/09              Dirk Wong
Add GetMultiTxnIdByStmtTxnId			   2015/04/01		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLStmtTxnRelation.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLStmtTxnRelation(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_stmt_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stmt_txn_id;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_stmt_txn_id = -1;
		short		ind_txn_id = -1;
		short		ind_create_user = -1;

		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRls,"stmt_txn_id",&csTmp)) {
		hv_stmt_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_stmt_txn_id.arr, csTmp, hv_stmt_txn_id.len);
		ind_stmt_txn_id = 0;
DEBUGLOG(("Add: stmt_txn_id = [%s]\n",(char*)hv_stmt_txn_id.arr));
	}

	if (GetField_CString(hRls,"txn_id",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%s]\n",(char*)hv_txn_id.arr));
	}

	if(GetField_CString(hRls,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add: create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_stmt_txn_relation_insert(
						:hv_stmt_txn_id:ind_stmt_txn_id,
						:hv_txn_id:ind_txn_id,
                                                :hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_stmt_txn_relation_insert ( \
:hv_stmt_txn_id:ind_stmt_txn_id , :hv_txn_id:ind_txn_id , :hv_create_user:ind\
_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stmt_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_stmt_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



	DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLStmtTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	} 

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLStmtTxnRelation_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtTxnRelation_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetStmtTxnIdByTxnId(const unsigned char* csTxnId, unsigned char* csStmtTxnId)
{
	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO getstmttxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar v_stmt_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stmt_txn_id;

		short ind_stmt_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen((const char*)csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetStmtTxnIdByTxnId txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL
		select ostp_stmt_txn_id
		into :v_stmt_txn_id:ind_stmt_txn_id
		from ol_stmt_txn_relation
		where ostp_txn_id = :hv_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ostp_stmt_txn_id into :b0:b1 from ol_stmt_txn_relati\
on where ostp_txn_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )36;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_stmt_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_stmt_txn_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
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
 if (sqlca.sqlcode < 0) goto getstmttxnid_error;
}



	if (ind_stmt_txn_id >= 0) {
		v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
		strcpy((char*)csStmtTxnId, (const char*)v_stmt_txn_id.arr);
DEBUGLOG(("stmt_txn_id = [%s]\n", csStmtTxnId));
			iRet = PD_FOUND;
	}

	if (iRet == PD_FOUND) {
DEBUGLOG(("GetStmtTxnIdByTxnId success [%d]\n", iRet));
	} else {
DEBUGLOG(("GetStmtTxnIdByTxnId failed [%d]\n", iRet));
	}

	return iRet;

getstmttxnid_error:
DEBUGLOG(("getstmttxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtTxnRelation_GetStmtTxnIdByTxnId: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_NOT_FOUND;
}


int GetTxnIdByStmtTxnId(const unsigned char* csStmtTxnId, unsigned char* csTxnId)
{
	int iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_stmt_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stmt_txn_id;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_stmt_txn_id.len = strlen((const char*)csStmtTxnId);
	memcpy(hv_stmt_txn_id.arr, csStmtTxnId, hv_stmt_txn_id.len);
DEBUGLOG(("GetTxnIdByStmtTxnId stmt_txn_id = [%.*s]\n", hv_stmt_txn_id.len, hv_stmt_txn_id.arr));

	/* EXEC SQL
		select ostp_txn_id
		into :v_txn_id:ind_txn_id
		from ol_stmt_txn_relation
		where ostp_stmt_txn_id = :hv_stmt_txn_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select ostp_txn_id into :b0:b1 from ol_stmt_txn_relation wh\
ere ostp_stmt_txn_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )59;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stmt_txn_id;
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
 if (sqlca.sqlcode < 0) goto gettxnid_error;
}



	if (ind_txn_id >= 0) {
		v_txn_id.arr[v_txn_id.len] = '\0';
		strcpy((char*)csTxnId, (const char*)v_txn_id.arr);
DEBUGLOG(("txn_id = [%s]\n", csTxnId));
			iRet = PD_FOUND;
	}

	if (iRet == PD_FOUND) {
DEBUGLOG(("GetTxnIdByStmtTxnId success [%d]\n", iRet));
	} else {
DEBUGLOG(("GetTxnIdByStmtTxnId failed [%d]\n", iRet));
	}

	return iRet;

gettxnid_error:
DEBUGLOG(("gettxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtTxnRelation_GetTxnIdByStmtTxnId: SP_INTERNAL_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_NOT_FOUND;
}

int GetMultiTxnIdByStmtTxnId(const unsigned char* csStmtTxnId, recordset_t* rRecordSet)
{
        int iRet = PD_NOT_FOUND;

	int iCnt = 0;

	hash_t *myHash;
	
        /* EXEC SQL WHENEVER SQLERROR GOTO getmultitxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_stmt_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stmt_txn_id;


                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                short ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_stmt_txn_id.len = strlen((const char*)csStmtTxnId);
        memcpy(hv_stmt_txn_id.arr, csStmtTxnId, hv_stmt_txn_id.len);
DEBUGLOG(("GetMultiTxnIdByStmtTxnId stmt_txn_id = [%.*s]\n", hv_stmt_txn_id.len, hv_stmt_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_getmultitxnid CURSOR FOR
                select ostp_txn_id
                into :v_txn_id:ind_txn_id
                from ol_stmt_txn_relation
                where ostp_stmt_txn_id = :hv_stmt_txn_id; */ 

	/* EXEC SQL OPEN c_cursor_getmultitxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )82;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_stmt_txn_id;
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
 if (sqlca.sqlcode < 0) goto getmultitxnid_error;
}



	 for (;;) {
                /* EXEC SQL FETCH c_cursor_getmultitxnid
                INTO    :v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )105;
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
                if (sqlca.sqlcode < 0) goto getmultitxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);
		
		// txn_id
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash, "txn_id", (const char*)v_txn_id.arr);
DEBUGLOG(("GetMultiTxnIdByStmtTxnId: txn_id = [%s]\n", (const char*)v_txn_id.arr));
                }

		RecordSet_Add(rRecordSet, myHash);
        }

        /* EXEC SQL CLOSE c_cursor_getmultitxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )124;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmultitxnid_error;
}



	if (iCnt > 0) {
                iRet = PD_FOUND;
DEBUGLOG(("GetMultiTxnIdByStmtTxnId FOUND\n"));
        } else {
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetMultiTxnIdByStmtTxnId NOT FOUND!!!\n"));
        }

DEBUGLOG(("GetMultiTxnIdByStmtTxnId: Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getmultitxnid_error:
DEBUGLOG(("getmultitxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStmtTxnRelation_GetMultiTxnIdByStmtTxnId: SP_INTERNAL_ERR\n");
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getmultitxnid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 4;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )139;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmultitxnid_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_NOT_FOUND;
}
