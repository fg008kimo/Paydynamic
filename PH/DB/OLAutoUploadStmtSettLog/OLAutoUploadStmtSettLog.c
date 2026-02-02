
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "OLAutoUploadStmtSettLog.pc"
};


static unsigned int sqlctx = 876942403;


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
5,0,0,1,419,0,6,164,0,0,12,12,0,1,0,2,3,0,0,1,68,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
PDProTech (c)2021. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2021/06/22              [MIC]    	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "OLAutoUploadStmtSettLog.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void OLAutoUploadStmtSettLog(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRec)
{
	char *csTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		unsigned long	hv_job_id;
 		/* varchar		hv_server_id[PD_SERVER_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_server_id;

		/* varchar		hv_prov_pathname_fr[PD_PROV_PATHNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_prov_pathname_fr;

		/* varchar		hv_prov_pathname_to[PD_PROV_PATHNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_prov_pathname_to;

		/* varchar		hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

		int			hv_level;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		int			hv_disabled;
		/* varchar		hv_prov_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_prov_id;

		/* varchar		hv_nature_path[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_nature_path;

		/* varchar		hv_process_bank_code[PD_PROCESS_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_process_bank_code;

		

		short		ind_job_id = -1;
		short		ind_server_id = -1;
		short		ind_prov_pathname_fr = -1;
		short		ind_prov_pathname_to = -1;
		short		ind_nature = -1;
		short		ind_level = -1;
		short		ind_create_user = -1;
		short		ind_disabled = -1;
		short		ind_prov_id = -1;
		short		ind_nature_path = -1;
		short		ind_process_bank_code = -1;


		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRec, "job_id", &csTmp))
	{
		hv_job_id = (unsigned long)ctol((const unsigned char*)csTmp, strlen(csTmp));
		ind_job_id = 0;
DEBUGLOG(("Add: job_id = [%lu]\n", hv_job_id));
	}


	if (GetField_CString(hRec, "server_id", &csTmp))
	{
		hv_server_id.len = strlen(csTmp);
		strncpy((char*)hv_server_id.arr, csTmp, hv_server_id.len);
		ind_server_id = 0;
DEBUGLOG(("Add: server_id = [%.*s]\n", hv_server_id.len, hv_server_id.arr));
	}


	if (GetField_CString(hRec, "prov_pathname_fr", &csTmp))
	{
		hv_prov_pathname_fr.len = strlen(csTmp);
		strncpy((char*)hv_prov_pathname_fr.arr, csTmp, hv_prov_pathname_fr.len);
		ind_prov_pathname_fr = 0;
DEBUGLOG(("Add: prov_pathname_fr = [%.*s]\n", hv_prov_pathname_fr.len, hv_prov_pathname_fr.arr));
	}

	if (GetField_CString(hRec, "prov_pathname_to", &csTmp))
	{
		hv_prov_pathname_to.len = strlen(csTmp);
		strncpy((char*)hv_prov_pathname_to.arr, csTmp, hv_prov_pathname_to.len);
		ind_prov_pathname_to = 0;
DEBUGLOG(("Add: prov_pathname_to = [%.*s]\n", hv_prov_pathname_to.len, hv_prov_pathname_to.arr));
	}

	if (GetField_CString(hRec, "nature", &csTmp))
	{
		hv_nature.len = strlen(csTmp);
		strncpy((char*)hv_nature.arr, csTmp, hv_nature.len);
		ind_nature = 0;
DEBUGLOG(("Add: nature = [%.*s]\n", hv_nature.len, hv_nature.arr));
	}


	if (GetField_Int(hRec, "level", &iTmp)) {
		hv_level = iTmp;
		ind_level= 0;
DEBUGLOG(("Add: level = [%d]\n", hv_level));
	}

	if (GetField_CString(hRec, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}


	if (GetField_Int(hRec, "disabled", &iTmp)) {
		hv_disabled = iTmp;
		ind_disabled= 0;
DEBUGLOG(("Add: disabled = [%d]\n", hv_disabled));
	}
	
	
	if (GetField_CString(hRec, "prov_id", &csTmp))
	{
		hv_prov_id.len = strlen(csTmp);
		strncpy((char*)hv_prov_id.arr, csTmp, hv_prov_id.len);
		ind_prov_id = 0;
DEBUGLOG(("Add: prov_id = [%.*s]\n", hv_prov_id.len, hv_prov_id.arr));
	}
	
	if (GetField_CString(hRec, "nature_path", &csTmp))
	{
		hv_nature_path.len = strlen(csTmp);
		strncpy((char*)hv_nature_path.arr, csTmp, hv_nature_path.len);
		ind_nature_path = 0;
DEBUGLOG(("Add: nature_path = [%.*s]\n", hv_nature_path.len, hv_nature_path.arr));
	}

	if (GetField_CString(hRec, "process_bank_code", &csTmp))
	{
		hv_process_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_process_bank_code.arr, csTmp, hv_process_bank_code.len);
		ind_process_bank_code = 0;
DEBUGLOG(("Add: process_bank_code = [%.*s]\n", hv_process_bank_code.len, hv_process_bank_code.arr));
	}



	FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
	BEGIN
		:hv_return_value := sp_ol_auto_upl_sett_log_ins(
				:hv_job_id:ind_job_id,
				:hv_server_id:ind_server_id,
				:hv_prov_pathname_fr:ind_prov_pathname_fr,
				:hv_prov_pathname_to:ind_prov_pathname_to,
				:hv_nature:ind_nature,
				:hv_level:ind_level,
				:hv_disabled:ind_disabled,
				:hv_prov_id:ind_prov_id,
				:hv_nature_path:ind_nature_path,	
				:hv_process_bank_code:ind_process_bank_code,
				:hv_create_user:ind_create_user);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 12;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_sett_log_ins ( :hv\
_job_id:ind_job_id , :hv_server_id:ind_server_id , :hv_prov_pathname_fr:ind_p\
rov_pathname_fr , :hv_prov_pathname_to:ind_prov_pathname_to , :hv_nature:ind_\
nature , :hv_level:ind_level , :hv_disabled:ind_disabled , :hv_prov_id:ind_pr\
ov_id , :hv_nature_path:ind_nature_path , :hv_process_bank_code:ind_process_b\
ank_code , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_job_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_job_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_server_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_server_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_prov_pathname_fr;
 sqlstm.sqhstl[3] = (unsigned long )52;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_prov_pathname_fr;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_prov_pathname_to;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_prov_pathname_to;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_nature;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_level;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_level;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_disabled;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_prov_id;
 sqlstm.sqhstl[8] = (unsigned long )12;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_prov_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_nature_path;
 sqlstm.sqhstl[9] = (unsigned long )52;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_nature_path;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_process_bank_code;
 sqlstm.sqhstl[10] = (unsigned long )12;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_process_bank_code;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



	DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
		ERRLOG("OLAutoUploadStmtSettLog_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
		ERRLOG("OLAutoUploadStmtSettLog_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSettLog_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

