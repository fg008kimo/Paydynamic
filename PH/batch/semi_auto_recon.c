
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "semi_auto_recon.pc"
};


static unsigned int sqlctx = 20508827;


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
   unsigned char  *sqhstv[2];
   unsigned long  sqhstl[2];
            int   sqhsts[2];
            short *sqindv[2];
            int   sqinds[2];
   unsigned long  sqharm[2];
   unsigned long  *sqharc[2];
   unsigned short  sqadto[2];
   unsigned short  sqtdso[2];
} sqlstm = {12,2};

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
"select opd1 . opd_psp_id , opd2 . opd_psp_id from ol_psp_detail opd1 , ol_p\
sp_detail opd2 where opd1 . opd_client_id = :b0 and opd2 . opd_client_id = :b\
1 and opd1 . opd_bank_acct_type in ( 'POA' , 'ITM' ) and opd2 . opd_bank_acct\
_type in ( 'POA' , 'ITM' ) order by opd1 . opd_bank_acct_type , opd2 . opd_ba\
nk_acct_type            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,330,0,9,206,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,208,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
51,0,0,1,0,0,15,236,0,0,0,0,0,1,0,
66,0,0,1,0,0,15,281,0,0,0,0,0,1,0,
81,0,0,2,0,0,32,282,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/02/13              David Wong
Support "Any" for PID                              2019/03/15              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "ObjPtr.h"
#include "internal.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "dbutility.h"
#include <curl/curl.h>
#include "queue_utility.h"
#include "mq_db.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cs_create_stmt_ts_ind[10 + 1];
char cs_s_ts_from[PD_DATE_LEN + PD_TIME_LEN + 1];
char cs_s_ts_to[PD_DATE_LEN + PD_TIME_LEN + 1];
char cs_s_provider_id[PD_CLIENT_ID_LEN + 1];
char cs_s_pid[PD_PSP_ID_LEN + 1];
char cs_s_txn_amt[20 + 1];
char cs_r_ts_from[PD_DATE_LEN + PD_TIME_LEN + 1];
char cs_r_ts_to[PD_DATE_LEN + PD_TIME_LEN + 1];
char cs_r_provider_id[PD_CLIENT_ID_LEN + 1];
char cs_r_pid[PD_PSP_ID_LEN + 1];
char cs_r_txn_amt[20 + 1];
char cs_add_user[PD_USER_LEN + 1];
int i_trigger_seq;

static char cDebug = 'Y';
OBJPTR(Txn);
OBJPTR(BO);
OBJPTR(DB);

int parse_arg(int argc, char **argv);

int batch_init(int argc, char* argv[])
{
	if (argc < 19) {
		printf("not enough input\n");
		return FAILURE;
	}
	else
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int iRet = SUCCESS;
	int iTmpRet;

	hash_t *hRequest;
	hRequest = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRequest, 0);

	hash_t *hContext;
	hContext = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hContext, 0);

	hash_t *hResponse;
	hResponse = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hResponse, 0);

	hash_t *hTriggerLog;
	hTriggerLog = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hTriggerLog, 0);

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
DEBUGLOG(("invalid input\n"));
ERRLOG("semi_auto_recon: invalid input\n");
		goto end_trigger;
	}

DEBUGLOG(("Start\n"));

DEBUGLOG(("cs_create_stmt_ts_ind = [%s]\n", cs_create_stmt_ts_ind));
DEBUGLOG(("cs_s_ts_from = [%s]\n", cs_s_ts_from));
DEBUGLOG(("cs_s_ts_to = [%s]\n", cs_s_ts_to));
	if (!strcmp(cs_create_stmt_ts_ind, "create")) {
		PutField_CString(hRequest, "s_create_ts_from", cs_s_ts_from);
		PutField_CString(hRequest, "s_create_ts_to", cs_s_ts_to);
	} else if (!strcmp(cs_create_stmt_ts_ind, "stmt")) {
		PutField_CString(hRequest, "s_stmt_ts_from", cs_s_ts_from);
		PutField_CString(hRequest, "s_stmt_ts_to", cs_s_ts_to);
	} else {
DEBUGLOG(("invalid input\n"));
ERRLOG("semi_auto_recon: invalid input - cs_create_stmt_ts_ind\n");
		iRet = FAILURE;
		goto end_trigger;
	}

DEBUGLOG(("cs_s_provider_id = [%s]\n", cs_s_provider_id));
	if (strcmp(cs_s_provider_id, "")) {
		PutField_CString(hRequest, "s_provider_id", cs_s_provider_id);
	}

DEBUGLOG(("cs_s_pid = [%s]\n", cs_s_pid));
	PutField_CString(hRequest, "s_pid", cs_s_pid);

DEBUGLOG(("cs_s_txn_amt = [%s]\n", cs_s_txn_amt));
	if (strcmp(cs_s_txn_amt, "")) {
		PutField_CString(hRequest, "s_txn_amt", cs_s_txn_amt);
	}

DEBUGLOG(("cs_create_stmt_ts_ind = [%s]\n", cs_create_stmt_ts_ind));
DEBUGLOG(("cs_r_ts_from = [%s]\n", cs_r_ts_from));
DEBUGLOG(("cs_r_ts_to = [%s]\n", cs_r_ts_to));
	if (!strcmp(cs_create_stmt_ts_ind, "create")) {
		PutField_CString(hRequest, "r_create_ts_from", cs_r_ts_from);
		PutField_CString(hRequest, "r_create_ts_to", cs_r_ts_to);
	} else if (!strcmp(cs_create_stmt_ts_ind, "stmt")) {
		PutField_CString(hRequest, "r_stmt_ts_from", cs_r_ts_from);
		PutField_CString(hRequest, "r_stmt_ts_to", cs_r_ts_to);
	} else {
DEBUGLOG(("invalid input\n"));
ERRLOG("semi_auto_recon: invalid input - cs_create_stmt_ts_ind\n");
		iRet = FAILURE;
		goto end_trigger;
	}

DEBUGLOG(("cs_r_provider_id = [%s]\n", cs_r_provider_id));
	if (strcmp(cs_r_provider_id, "")) {
		PutField_CString(hRequest, "r_provider_id", cs_r_provider_id);
	}

DEBUGLOG(("cs_r_pid = [%s]\n", cs_r_pid));
	PutField_CString(hRequest, "r_pid", cs_r_pid);

DEBUGLOG(("cs_r_txn_amt = [%s]\n", cs_r_txn_amt));
	if (strcmp(cs_r_txn_amt, "")) {
		PutField_CString(hRequest, "r_txn_amt", cs_r_txn_amt);
	}

DEBUGLOG(("cs_add_user = [%s]\n", cs_add_user));
	PutField_CString(hRequest, "add_user", cs_add_user);

	PutField_Int(hRequest, "execute", PD_TRUE);

// Update trigger log to "Processing"
DEBUGLOG(("Call DBOLSemiAutoReconTriggerLog:Update()\n"));
	PutField_Int(hTriggerLog, "trigger_seq", i_trigger_seq);
	PutField_Char(hTriggerLog, "trigger_status", PD_PROCESSING);
	PutField_CString(hTriggerLog, "update_user", cs_add_user);
	DBObjPtr = CreateObj(DBPtr, "DBOLSemiAutoReconTriggerLog", "Update");
	iTmpRet = (unsigned long)(*DBObjPtr)(hTriggerLog);
	if (iTmpRet == PD_OK) {
DEBUGLOG(("Update trigger log to 'Processing' succcess\n"));
		TxnCommit();
	} else {
DEBUGLOG(("Update trigger log to 'Processing' failed\n"));
ERRLOG("semi_auto_recon: Update trigger log to 'Processing' failed\n");
		iRet = FAILURE;
		goto end_trigger;
	}

	if (!strcmp(cs_s_pid, PD_DEFAULT_PSP) && !strcmp(cs_r_pid, PD_DEFAULT_PSP)) {
		/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

		/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


		/* EXEC SQL BEGIN DECLARE SECTION; */ 

			/* varchar hv_s_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_s_provider_id;

			/* varchar hv_r_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_r_provider_id;


			/* varchar v_s_pid[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_s_pid;

			/* varchar v_r_pid[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_r_pid;

			short ind_s_pid = -1;
			short ind_r_pid = -1;
		/* EXEC SQL END DECLARE SECTION; */ 


		hv_s_provider_id.len = strlen(cs_s_provider_id);
		memcpy(hv_s_provider_id.arr, cs_s_provider_id, hv_s_provider_id.len);

		hv_r_provider_id.len = strlen(cs_r_provider_id);
		memcpy(hv_r_provider_id.arr, cs_r_provider_id, hv_r_provider_id.len);

		/* EXEC SQL DECLARE c_cursor_get_s_r_pid CURSOR FOR
			select opd1.opd_psp_id, opd2.opd_psp_id
			from ol_psp_detail opd1, ol_psp_detail opd2
			where opd1.opd_client_id = :hv_s_provider_id and opd2.opd_client_id = :hv_r_provider_id
			and opd1.opd_bank_acct_type in ('POA', 'ITM') and opd2.opd_bank_acct_type in ('POA', 'ITM')
			order by opd1.opd_bank_acct_type, opd2.opd_bank_acct_type; */ 


		/* EXEC SQL OPEN c_cursor_get_s_r_pid; */ 

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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_s_provider_id;
  sqlstm.sqhstl[0] = (unsigned long )12;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_r_provider_id;
  sqlstm.sqhstl[1] = (unsigned long )12;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}


		for (;;) {
			/* EXEC SQL FETCH c_cursor_get_s_r_pid
			INTO :v_s_pid:ind_s_pid,
				:v_r_pid:ind_r_pid; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 2;
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
   sqlstm.sqhstv[0] = (unsigned char  *)&v_s_pid;
   sqlstm.sqhstl[0] = (unsigned long )13;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_s_pid;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_r_pid;
   sqlstm.sqhstl[1] = (unsigned long )13;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_r_pid;
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
   if (sqlca.sqlcode < 0) goto sql_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			if (ind_s_pid >= 0 && ind_r_pid >= 0) {
				v_s_pid.arr[v_s_pid.len] = '\0';
				PutField_CString(hRequest, "s_pid", (const char*)v_s_pid.arr);
				v_r_pid.arr[v_r_pid.len] = '\0';
				PutField_CString(hRequest, "r_pid", (const char*)v_r_pid.arr);
DEBUGLOG(("s_pid = [%s], r_pid = [%s]\n", (const char*)v_s_pid.arr, (const char*)v_r_pid.arr));

DEBUGLOG(("Call TxnOmtByUsSAR:Authorize()\n"));
				TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsSAR", "Authorize");
				iTmpRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
				if (iTmpRet == PD_OK) {
DEBUGLOG(("Call TxnOmtByUsSAR:Authorize() return success\n"));
					TxnCommit();
				} else {
DEBUGLOG(("Call TxnOmtByUsSAR:Authorize() return failed\n"));
ERRLOG("semi_auto_recon: Call TxnOmtByUsSAR:Authorize() return failed\n");
					TxnAbort();
				}
			}
		}
		/* EXEC SQL CLOSE c_cursor_get_s_r_pid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 2;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )51;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}


	} else {
DEBUGLOG(("Call TxnOmtByUsSAR:Authorize()\n"));
		TxnObjPtr = CreateObj(TxnPtr, "TxnOmtByUsSAR", "Authorize");
		iTmpRet = (unsigned long)(*TxnObjPtr)(hContext, hRequest, hResponse);
		if (iTmpRet == PD_OK) {
DEBUGLOG(("Call TxnOmtByUsSAR:Authorize() return success\n"));
			TxnCommit();
		} else {
DEBUGLOG(("Call TxnOmtByUsSAR:Authorize() return failed\n"));
ERRLOG("semi_auto_recon: Call TxnOmtByUsSAR:Authorize() return failed\n");
			TxnAbort();
		}
	}

// Update trigger log to "Completed"
DEBUGLOG(("call DBOLSemiAutoReconTriggerLog:Update()\n"));
	PutField_Char(hTriggerLog, "trigger_status", PD_COMPLETE);
	DBObjPtr = CreateObj(DBPtr, "DBOLSemiAutoReconTriggerLog", "Update");
	iTmpRet = (unsigned long)(*DBObjPtr)(hTriggerLog);
	if (iTmpRet == PD_OK) {
DEBUGLOG(("Update trigger log to 'Completed' succcess\n"));
	} else {
DEBUGLOG(("Update trigger log to 'Completed' failed\n"));
ERRLOG("semi_auto_recon: Update trigger log to 'Completed' failed\n");
		iRet =  FAILURE;
	}

end_trigger:
DEBUGLOG(("semi_auto_recon Normal Exit() iRet = [%d]\n", iRet));
	hash_destroy(hRequest);
	hash_destroy(hContext);
	hash_destroy(hResponse);
	hash_destroy(hTriggerLog);
	FREE_ME(hRequest);
	FREE_ME(hContext);
	FREE_ME(hResponse);
	FREE_ME(hTriggerLog);
	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("semi_auto_recon:: sql error\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get_s_r_pid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )66;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )81;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	hash_destroy(hRequest);
	hash_destroy(hContext);
	hash_destroy(hResponse);
	hash_destroy(hTriggerLog);
	FREE_ME(hRequest);
	FREE_ME(hContext);
	FREE_ME(hResponse);
	FREE_ME(hTriggerLog);
	return FAILURE;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


int parse_arg(int argc, char **argv)
{
	char c;
	strcpy(cs_create_stmt_ts_ind, "");
	strcpy(cs_s_ts_from, "");
	strcpy(cs_s_ts_to, "");
	strcpy(cs_s_provider_id, "");
	strcpy(cs_s_pid, "");
	strcpy(cs_s_txn_amt, "");
	strcpy(cs_r_ts_from, "");
	strcpy(cs_r_ts_to, "");
	strcpy(cs_r_provider_id, "");
	strcpy(cs_r_pid, "");
	strcpy(cs_r_txn_amt, "");
	strcpy(cs_add_user, "");
	i_trigger_seq = 0;

	while ((c = getopt(argc, argv, "a:b:c:d:e:f:g:h:i:j:k:l:m:")) != EOF) {
		switch (c) {
			case 'a':
				strcpy(cs_create_stmt_ts_ind, optarg);
				break;
			case 'b':
				strcpy(cs_s_ts_from, optarg);
				break;
			case 'c':
				strcpy(cs_s_ts_to, optarg);
				break;
			case 'd':
				strcpy(cs_s_provider_id, optarg);
				break;
			case 'e':
				strcpy(cs_s_pid, optarg);
				break;
			case 'f':
				strcpy(cs_s_txn_amt, optarg);
				break;
			case 'g':
				strcpy(cs_r_ts_from, optarg);
				break;
			case 'h':
				strcpy(cs_r_ts_to, optarg);
				break;
			case 'i':
				strcpy(cs_r_provider_id, optarg);
				break;
			case 'j':
				strcpy(cs_r_pid, optarg);
				break;
			case 'k':
				strcpy(cs_r_txn_amt, optarg);
				break;
			case 'l':
				strcpy(cs_add_user, optarg);
				break;
			case 'm':
				i_trigger_seq = atoi(optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_create_stmt_ts_ind, "") ||
		!strcmp(cs_s_ts_from, "") || !strcmp(cs_s_ts_to, "") ||
		!strcmp(cs_s_pid, "") ||
		!strcmp(cs_r_ts_from, "") || !strcmp(cs_r_ts_to, "") ||
		!strcmp(cs_r_pid, "") ||
		!strcmp(cs_add_user, "") ||
		i_trigger_seq == 0)
		return FAILURE;

	return SUCCESS;
}
