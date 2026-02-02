
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
    "OLAutoUploadStmtSetting.pc"
};


static unsigned int sqlctx = 876942291;


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
   unsigned char  *sqhstv[10];
   unsigned long  sqhstl[10];
            int   sqhsts[10];
            short *sqindv[10];
            int   sqinds[10];
   unsigned long  sqharm[10];
   unsigned long  *sqharc[10];
   unsigned short  sqadto[10];
   unsigned short  sqtdso[10];
} sqlstm = {12,10};

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

 static char *sq0003 = 
"select pm_client_name , pm_client_id , oaus_nature from psp_master , ol_aut\
o_upload_stmt_setting where oaus_provider_pathname = :b0 and oaus_nature_path\
 = :b1 and oaus_provider_id = pm_client_id and oaus_disabled = 0 group by pm_\
client_name , pm_client_id , oaus_nature            ";

 static char *sq0004 = 
"select oaus_provider_pathname , pm_client_name , pm_client_id , oaus_nature\
 from psp_master , ol_auto_upload_stmt_setting where oaus_nature_path = :b0 a\
nd oaus_provider_id = pm_client_id and oaus_disabled = 0 group by oaus_provid\
er_pathname , pm_client_name , pm_client_id , oaus_nature            ";

 static char *sq0005 = 
"SELECT OAUS_PROVIDER_PATHNAME , DECODE ( OAUS_PROCESS_BANK_CODE , '000' , '\
ALL' , ( SELECT BANK_ABBREV_NAME FROM BANK_DESC WHERE INTERNAL_BANK_CODE = OA\
US_PROCESS_BANK_CODE ) ) process_bank , OAUS_NATURE_PATH FROM OL_AUTO_UPLOAD_\
STMT_SETTING WHERE OAUS_SERVER_ID = :b0 AND OAUS_NATURE = :b1 AND OAUS_DISABL\
ED = 0 ORDER BY OAUS_PROVIDER_PATHNAME , OAUS_NATURE , OAUS_LEVEL DESC       \
     ";

 static char *sq0006 = 
"SELECT OAUS_NATURE_PATH FROM OL_AUTO_UPLOAD_STMT_SETTING WHERE OAUS_SERVER_\
ID = :b0 AND OAUS_NATURE = :b1 AND OAUS_DISABLED = 0 ORDER BY OAUS_PROVIDER_P\
ATHNAME , OAUS_NATURE , OAUS_LEVEL DESC            ";

 static char *sq0008 = 
"select oaus_provider_pathname , oaus_job_id from ol_auto_upload_stmt_settin\
g where oaus_provider_id = :b0 and oaus_nature = :b1            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,344,0,6,155,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
60,0,0,2,341,0,6,309,0,0,10,10,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
115,0,0,3,281,0,9,401,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
138,0,0,3,0,0,13,403,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
165,0,0,3,0,0,15,440,0,0,0,0,0,1,0,
180,0,0,3,0,0,15,457,0,0,0,0,0,1,0,
195,0,0,4,298,0,9,504,0,2049,1,1,0,1,0,1,9,0,0,
214,0,0,4,0,0,13,506,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
245,0,0,4,0,0,15,555,0,0,0,0,0,1,0,
260,0,0,4,0,0,15,572,0,0,0,0,0,1,0,
275,0,0,5,388,0,9,620,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
298,0,0,5,0,0,13,622,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
325,0,0,5,0,0,15,666,0,0,0,0,0,1,0,
340,0,0,5,0,0,15,674,0,0,0,0,0,1,0,
355,0,0,6,203,0,9,715,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
378,0,0,6,0,0,13,717,0,0,1,0,0,1,0,2,9,0,0,
397,0,0,6,0,0,15,741,0,0,0,0,0,1,0,
412,0,0,6,0,0,15,749,0,0,0,0,0,1,0,
427,0,0,7,182,0,6,825,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
462,0,0,8,139,0,9,909,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
485,0,0,8,0,0,13,911,0,0,2,0,0,1,0,2,9,0,0,2,68,0,0,
508,0,0,8,0,0,15,940,0,0,0,0,0,1,0,
523,0,0,8,0,0,15,958,0,0,0,0,0,1,0,
538,0,0,9,127,0,6,1005,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/10/12              [WMC]
Modify GetDetailByPathName			   2018/03/07		   [WMC]
Add GetDetailByNaturePath		     	   2018/07/05		   [WMC]
    GetProviderJob
    CheckProviderJobExists    	
Add CheckDupProvPathname                           2021/06/23              [MIC]
	UpdateProvPathnameByProvId
	Add function
	GetByProvId
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "OLAutoUploadStmtSetting.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void OLAutoUploadStmtSetting(char    cdebug)
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

 		/* varchar		hv_server_id[PD_SERVER_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_server_id;

		/* varchar		hv_prov_pathname[PD_PROV_PATHNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_prov_pathname;

		/* varchar		hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

		int		hv_level;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		int		hv_disabled;
		/* varchar		hv_prov_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_prov_id;

		/* varchar		hv_nature_path[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_nature_path;

		/* varchar		hv_process_bank_code[PD_PROCESS_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_process_bank_code;

		

		short		ind_server_id = -1;
		short		ind_prov_pathname = -1;
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



	if (GetField_CString(hRec, "server_id", &csTmp))
	{
		hv_server_id.len = strlen(csTmp);
		strncpy((char*)hv_server_id.arr, csTmp, hv_server_id.len);
		ind_server_id = 0;
DEBUGLOG(("Add: server_id = [%.*s]\n", hv_server_id.len, hv_server_id.arr));
	}


	if (GetField_CString(hRec, "prov_pathname", &csTmp))
	{
		hv_prov_pathname.len = strlen(csTmp);
		strncpy((char*)hv_prov_pathname.arr, csTmp, hv_prov_pathname.len);
		ind_prov_pathname = 0;
DEBUGLOG(("Add: prov_pathname = [%.*s]\n", hv_prov_pathname.len, hv_prov_pathname.arr));
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
		:hv_return_value := sp_ol_auto_upl_setting_ins(
				:hv_server_id:ind_server_id,
				:hv_prov_pathname:ind_prov_pathname,
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
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_setting_ins ( :hv_\
server_id:ind_server_id , :hv_prov_pathname:ind_prov_pathname , :hv_nature:in\
d_nature , :hv_level:ind_level , :hv_disabled:ind_disabled , :hv_prov_id:ind_\
prov_id , :hv_nature_path:ind_nature_path , :hv_process_bank_code:ind_process\
_bank_code , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_server_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_server_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_prov_pathname;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_prov_pathname;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_nature;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_level;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_level;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_prov_id;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_prov_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_nature_path;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_nature_path;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_process_bank_code;
 sqlstm.sqhstl[8] = (unsigned long )12;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_process_bank_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_create_user;
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




int UpdateProvPathnameByProvId(const hash_t *hRec)
{
	int     iTmp;
	char    *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updateprovpathname_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

 		/* varchar		hv_server_id[PD_SERVER_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_server_id;

		/* varchar		hv_prov_pathname[PD_PROV_PATHNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_prov_pathname;

		/* varchar		hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

		int		hv_level;
		/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		int		hv_disabled;
		/* varchar		hv_prov_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_prov_id;

		/* varchar		hv_nature_path[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_nature_path;

		/* varchar		hv_process_bank_code[PD_PROCESS_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_process_bank_code;

		

		short		ind_server_id = -1;
		short		ind_prov_pathname = -1;
		short		ind_nature = -1;
		short		ind_level = -1;
		short		ind_update_user = -1;
		short		ind_disabled = -1;
		short		ind_prov_id = -1;
		short		ind_nature_path = -1;
		short		ind_process_bank_code = -1;


		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateProvPathnameByProvId: Begin\n"));

	if (GetField_CString(hRec, "server_id", &csTmp))
	{
		hv_server_id.len = strlen(csTmp);
		strncpy((char*)hv_server_id.arr, csTmp, hv_server_id.len);
		ind_server_id = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: server_id = [%.*s]\n", hv_server_id.len, hv_server_id.arr));
	}


	if (GetField_CString(hRec, "prov_pathname", &csTmp))
	{
		hv_prov_pathname.len = strlen(csTmp);
		strncpy((char*)hv_prov_pathname.arr, csTmp, hv_prov_pathname.len);
		ind_prov_pathname = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: hv_prov_pathname = [%.*s]\n", hv_prov_pathname.len, hv_prov_pathname.arr));
	}


	if (GetField_CString(hRec, "nature", &csTmp))
	{
		hv_nature.len = strlen(csTmp);
		strncpy((char*)hv_nature.arr, csTmp, hv_nature.len);
		ind_nature = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: nature = [%.*s]\n", hv_nature.len, hv_nature.arr));
	}


	if (GetField_Int(hRec, "level", &iTmp)) {
		hv_level = iTmp;
		ind_level= 0;
DEBUGLOG(("UpdateProvPathnameByProvId: level = [%d]\n", hv_level));
	}

	if (GetField_CString(hRec, "update_user", &csTmp))
	{
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: create_user = [%.*s]\n", hv_update_user.len, hv_update_user.arr));
	}


	if (GetField_Int(hRec, "disabled", &iTmp)) {
		hv_disabled = iTmp;
		ind_disabled= 0;
DEBUGLOG(("UpdateProvPathnameByProvId: disabled = [%d]\n", hv_disabled));
	}
	
	
	if (GetField_CString(hRec, "prov_id", &csTmp))
	{
		hv_prov_id.len = strlen(csTmp);
		strncpy((char*)hv_prov_id.arr, csTmp, hv_prov_id.len);
		ind_prov_id = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: prov_id = [%.*s]\n", hv_prov_id.len, hv_prov_id.arr));
	}
	
	if (GetField_CString(hRec, "nature_path", &csTmp))
	{
		hv_nature_path.len = strlen(csTmp);
		strncpy((char*)hv_nature_path.arr, csTmp, hv_nature_path.len);
		ind_nature_path = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: nature_path = [%.*s]\n", hv_nature_path.len, hv_nature_path.arr));
	}

	if (GetField_CString(hRec, "process_bank_code", &csTmp))
	{
		hv_process_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_process_bank_code.arr, csTmp, hv_process_bank_code.len);
		ind_process_bank_code = 0;
DEBUGLOG(("UpdateProvPathnameByProvId: process_bank_code = [%.*s]\n", hv_process_bank_code.len, hv_process_bank_code.arr));
	}

	/* EXEC SQL EXECUTE
                BEGIN

				:hv_return_value := sp_ol_auto_upl_path_upd(
					:hv_server_id:ind_server_id,
					:hv_prov_pathname:ind_prov_pathname,
					:hv_nature:ind_nature,
					:hv_level:ind_level,
					:hv_disabled:ind_disabled,
					:hv_prov_id:ind_prov_id,
					:hv_nature_path:ind_nature_path,
					:hv_process_bank_code:ind_process_bank_code,
					:hv_update_user:ind_update_user);

                 END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_path_upd ( :hv_ser\
ver_id:ind_server_id , :hv_prov_pathname:ind_prov_pathname , :hv_nature:ind_n\
ature , :hv_level:ind_level , :hv_disabled:ind_disabled , :hv_prov_id:ind_pro\
v_id , :hv_nature_path:ind_nature_path , :hv_process_bank_code:ind_process_ba\
nk_code , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )60;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_server_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_server_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_prov_pathname;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_prov_pathname;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_nature;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_level;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_level;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_prov_id;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_prov_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_nature_path;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_nature_path;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_process_bank_code;
 sqlstm.sqhstl[8] = (unsigned long )12;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_process_bank_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[9] = (unsigned long )22;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto updateprovpathname_error;
}



	DEBUGLOG(("UpdateProvPathnameByProvId:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("UpdateProvPathnameByProvId:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("OLAutoUploadStmtSetting_UpdateProvPathnameByProvId: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("UpdateProvPathnameByProvId: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAutoUploadStmtSetting_UpdateProvPathnameByProvId: SP_ERR TxnAbort\n");
                DEBUGLOG(("UpdateProvPathnameByProvId: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

updateprovpathname_error:
DEBUGLOG(("updateprovpathname_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_UpdateProvPathnameByProvId: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int GetDetailByPathName(const char* csProviderPath, 
			const char* csNaturePath, 
			char* csProviderName, 
			char* csProviderId, 
			char* csNature)
{
	int iRet = PD_NOT_FOUND;
	int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getprovider_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_provider_path[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_provider_path;

                /* varchar         hv_nature_path[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_nature_path;

	
		/* varchar         v_provider_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_provider_name;

                /* varchar         v_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_provider_id;

                /* varchar         v_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_nature;


                short           ind_provider_name= -1;
                short           ind_provider_id= -1;
                short           ind_nature= -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_provider_path.len = strlen(csProviderPath);
        memcpy(hv_provider_path.arr, csProviderPath, hv_provider_path.len);
DEBUGLOG(("GetDetailByPathName provider_path = [%.*s]\n", hv_provider_path.len, hv_provider_path.arr));

	hv_nature_path.len = strlen(csNaturePath);
        memcpy(hv_nature_path.arr, csNaturePath, hv_nature_path.len);
DEBUGLOG(("GetDetailByPathName nature_path = [%.*s]\n", hv_nature_path.len, hv_nature_path.arr));

        /* EXEC SQL DECLARE c_cursor_getprovider CURSOR FOR
                select  pm_client_name,
			pm_client_id,
			oaus_nature
                from    psp_master, ol_auto_upload_stmt_setting
                where   oaus_provider_pathname = :hv_provider_path
		and	oaus_nature_path = :hv_nature_path
		and 	oaus_provider_id = pm_client_id
		and	oaus_disabled = 0
		group by pm_client_name,
			 pm_client_id,
			 oaus_nature; */ 


        /* EXEC SQL OPEN c_cursor_getprovider; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )115;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_provider_path;
        sqlstm.sqhstl[0] = (unsigned long )53;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature_path;
        sqlstm.sqhstl[1] = (unsigned long )53;
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
        if (sqlca.sqlcode < 0) goto getprovider_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getprovider
                INTO
			:v_provider_name:ind_provider_name,
                        :v_provider_id:ind_provider_id,
                        :v_nature:ind_nature; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )138;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_provider_name;
                sqlstm.sqhstl[0] = (unsigned long )52;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_provider_name;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_id;
                sqlstm.sqhstl[1] = (unsigned long )12;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_provider_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_nature;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_nature;
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
                if (sqlca.sqlcode < 0) goto getprovider_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetDetailByPathName found record\n"));

/* provider_name */
                if (ind_provider_name >= 0) {
                        v_provider_name.arr[v_provider_name.len] = '\0';
                        strcpy(csProviderName,(const char*)v_provider_name.arr);
DEBUGLOG(("GetDetailByPathName provider_name = [%s]\n", v_provider_name.arr));
                }

/* provider_id */
                if (ind_provider_id >= 0) {
                        v_provider_id.arr[v_provider_id.len] = '\0';
                        strcpy(csProviderId,(const char*)v_provider_id.arr);
DEBUGLOG(("GetDetailByPathName provider_id = [%s]\n", v_provider_id.arr));
	        }

/* nature */
                if (ind_nature >= 0) {
                        v_nature.arr[v_nature.len] = '\0';
                        strcpy(csNature,(const char*)v_nature.arr);
DEBUGLOG(("GetDetailByPathName nature = [%s]\n", v_nature.arr));
                }

		iCnt++;

        } while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getprovider; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )165;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getprovider_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetDetailByPathName Found\n"));
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetDetailByPathName Not Found\n"));
		iRet = PD_NOT_FOUND;	
	}

        return iRet;

getprovider_error:
DEBUGLOG(("getprovider_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_GetDetailByPathName: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getprovider; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )180;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetDetailByNaturePath(const char* csNaturePath,
			recordset_t* myRec) 
{
	int iRet = PD_NOT_FOUND;
	int iCnt = 0;
        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_nature_path[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_nature_path;


		/* varchar         v_provider_path[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_provider_path;
	
		/* varchar         v_provider_name[PD_CLIENT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_provider_name;

                /* varchar         v_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_provider_id;

                /* varchar         v_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_nature;


                short           ind_provider_path= -1;
                short           ind_provider_name= -1;
                short           ind_provider_id= -1;
                short           ind_nature= -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_nature_path.len = strlen(csNaturePath);
        memcpy(hv_nature_path.arr, csNaturePath, hv_nature_path.len);
DEBUGLOG(("GetDetailByNaturePath nature_path = [%.*s]\n", hv_nature_path.len, hv_nature_path.arr));

        /* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR
                select  oaus_provider_pathname,
			pm_client_name,
			pm_client_id,
			oaus_nature
                from    psp_master, ol_auto_upload_stmt_setting
                where   oaus_nature_path = :hv_nature_path
		and 	oaus_provider_id = pm_client_id
		and	oaus_disabled = 0
		group by oaus_provider_pathname,
			 pm_client_name,
			 pm_client_id,
			 oaus_nature; */ 


        /* EXEC SQL OPEN c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )195;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_nature_path;
        sqlstm.sqhstl[0] = (unsigned long )53;
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
        if (sqlca.sqlcode < 0) goto getdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getdetail
                INTO
			:v_provider_path:ind_provider_path,
			:v_provider_name:ind_provider_name,
                        :v_provider_id:ind_provider_id,
                        :v_nature:ind_nature; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )214;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_provider_path;
                sqlstm.sqhstl[0] = (unsigned long )52;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_provider_path;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_provider_name;
                sqlstm.sqhstl[1] = (unsigned long )52;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_provider_name;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_provider_id;
                sqlstm.sqhstl[2] = (unsigned long )12;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_provider_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_nature;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_nature;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}



		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetDetailByNaturePath found record\n"));

/* provider_path */
                if (ind_provider_path >= 0) {
                        v_provider_path.arr[v_provider_path.len] = '\0';
                        PutField_CString(myHash,"provider_path",(const char*)v_provider_path.arr);
DEBUGLOG(("GetDetailByNaturePath provider_path = [%s]\n", v_provider_path.arr));
                }

/* provider_name */
                if (ind_provider_name >= 0) {
                        v_provider_name.arr[v_provider_name.len] = '\0';
			PutField_CString(myHash,"provider_name",(const char*)v_provider_name.arr);
DEBUGLOG(("GetDetailByNaturePath provider_name = [%s]\n", v_provider_name.arr));
                }

/* provider_id */
                if (ind_provider_id >= 0) {
                        v_provider_id.arr[v_provider_id.len] = '\0';
			PutField_CString(myHash,"provider_id",(const char*)v_provider_id.arr);
DEBUGLOG(("GetDetailByNaturePath provider_id = [%s]\n", v_provider_id.arr));
	        }

/* nature */
                if (ind_nature >= 0) {
                        v_nature.arr[v_nature.len] = '\0';
			PutField_CString(myHash,"nature",(const char*)v_nature.arr);
DEBUGLOG(("GetDetailByNaturePath nature = [%s]\n", v_nature.arr));
                }

		RecordSet_Add(myRec,myHash);
		iCnt++;

        } while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )245;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetDetailByNaturePath Found\n"));
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetDetailByNaturePath Not Found\n"));
		iRet = PD_NOT_FOUND;	
	}

        return iRet;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_GetDetailByNaturePath: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )260;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetProviderJob(const char* csServerId, const char* csNature, recordset_t* myRec)
{
        int     iRet = PD_FOUND;
        int     iCnt = 0;
        hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getproviderjob_err; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

               	/* varchar hv_server_id[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_server_id;

                /* varchar hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;


                /* varchar v_prov_pathname[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_prov_pathname;

                /* varchar v_process_bank[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_process_bank;

                /* varchar v_nature_path[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_nature_path;


                short   ind_prov_pathname = -1;
                short   ind_process_bank = -1;
                short   ind_nature_path = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_server_id.len = strlen(csServerId);
        memcpy(hv_server_id.arr,csServerId,hv_server_id.len);
DEBUGLOG(("GetProviderJob hv_server_id = [%.*s]\n",hv_server_id.len,hv_server_id.arr));

        hv_nature.len = strlen(csNature);
        memcpy(hv_nature.arr,csNature,hv_nature.len);
DEBUGLOG(("GetProviderJob hv_nature = [%.*s]\n",hv_nature.len,hv_nature.arr));
	
        /* EXEC SQL DECLARE c_cursor_getproviderjob CURSOR FOR
                SELECT  OAUS_PROVIDER_PATHNAME,
                        DECODE(OAUS_PROCESS_BANK_CODE,'000','ALL',(SELECT BANK_ABBREV_NAME FROM BANK_DESC WHERE INTERNAL_BANK_CODE=OAUS_PROCESS_BANK_CODE)) process_bank,
                        OAUS_NATURE_PATH
                FROM    OL_AUTO_UPLOAD_STMT_SETTING
                WHERE   OAUS_SERVER_ID = :hv_server_id
                AND     OAUS_NATURE =:hv_nature
                AND     OAUS_DISABLED = 0
                ORDER BY
                        OAUS_PROVIDER_PATHNAME,
                        OAUS_NATURE,
                        OAUS_LEVEL DESC; */ 


        /* EXEC SQL OPEN c_cursor_getproviderjob; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )275;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_server_id;
        sqlstm.sqhstl[0] = (unsigned long )5;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature;
        sqlstm.sqhstl[1] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto getproviderjob_err;
}


	do {
                /* EXEC SQL FETCH c_cursor_getproviderjob
                INTO
                        :v_prov_pathname:ind_prov_pathname,
                        :v_process_bank:ind_process_bank,
                        :v_nature_path:ind_nature_path; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )298;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_prov_pathname;
                sqlstm.sqhstl[0] = (unsigned long )259;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_prov_pathname;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_process_bank;
                sqlstm.sqhstl[1] = (unsigned long )259;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_process_bank;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_nature_path;
                sqlstm.sqhstl[2] = (unsigned long )259;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_nature_path;
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
                if (sqlca.sqlcode < 0) goto getproviderjob_err;
}



                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_prov_pathname >= 0) {
                        v_prov_pathname.arr[v_prov_pathname.len]='\0';
                        PutField_CString(myHash,"provider_path",(const char*)v_prov_pathname.arr);
DEBUGLOG(("GetProviderJob prov_pathname = [%s]\n",v_prov_pathname.arr));
                }

                if (ind_process_bank >= 0) {
                        v_process_bank.arr[v_process_bank.len]='\0';
                        PutField_CString(myHash,"process_bank",(const char*)v_process_bank.arr);
DEBUGLOG(("GetProviderJob process_bank = [%s]\n",v_process_bank.arr));
                }

                if (ind_nature_path >= 0) {
                        v_nature_path.arr[v_nature_path.len]='\0';
                        PutField_CString(myHash,"nature_path",(const char*)v_nature_path.arr);
DEBUGLOG(("GetProviderJob nature_path = [%s]\n",v_nature_path.arr));
                }

                RecordSet_Add(myRec,myHash);
                iCnt++;
        }
        while(PD_TRUE);

        if (iCnt > 0) {
DEBUGLOG(("GetProviderJob Found!!\n"));
                iRet = PD_FOUND;
        } else {
DEBUGLOG(("GetProviderJob Not Found!!\n"));
                iRet = PD_NOT_FOUND;
        }

        /* EXEC SQL CLOSE c_cursor_getproviderjob; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 10;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )325;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getproviderjob_err;
}



	return iRet;

getproviderjob_err:
DEBUGLOG(("getproviderjob_err error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    	/* EXEC SQL CLOSE c_cursor_getproviderjob; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 10;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )340;
     sqlstm.cud = sqlcud0;
     sqlstm.sqlest = (unsigned char  *)&sqlca;
     sqlstm.sqlety = (unsigned short)4352;
     sqlstm.occurs = (unsigned int  )0;
     sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    	return PD_ERR;
}



int CheckProviderJobExists(const char* csServerId, const char* csNature, char* csNaturePath) 
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkproviderjob_err; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_server_id[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_server_id;

                /* varchar hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

        
		/* varchar v_nature_path[PD_TMP_BUF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[257]; } v_nature_path;


                short   ind_nature_path = -1;	
	/* EXEC SQL END DECLARE SECTION; */ 


        hv_server_id.len = strlen(csServerId);
        memcpy(hv_server_id.arr,csServerId,hv_server_id.len);
DEBUGLOG(("CheckProviderJobExists hv_server_id = [%.*s]\n",hv_server_id.len,hv_server_id.arr));

        hv_nature.len = strlen(csNature);
        memcpy(hv_nature.arr,csNature,hv_nature.len);
DEBUGLOG(("CheckProviderJobExists hv_nature = [%.*s]\n",hv_nature.len,hv_nature.arr));
	
        /* EXEC SQL DECLARE c_cursor_chkproviderjob CURSOR FOR
		SELECT  OAUS_NATURE_PATH
                FROM    OL_AUTO_UPLOAD_STMT_SETTING
                WHERE   OAUS_SERVER_ID = :hv_server_id
                AND     OAUS_NATURE = :hv_nature
                AND     OAUS_DISABLED = 0
                ORDER BY
                	OAUS_PROVIDER_PATHNAME,
                	OAUS_NATURE,
                	OAUS_LEVEL DESC; */ 

	
	/* EXEC SQL OPEN c_cursor_chkproviderjob; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )355;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_server_id;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[1] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto chkproviderjob_err;
}


        do {
                /* EXEC SQL FETCH c_cursor_chkproviderjob
                INTO
                        :v_nature_path:ind_nature_path; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 10;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )378;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_nature_path;
                sqlstm.sqhstl[0] = (unsigned long )259;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_nature_path;
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
                if (sqlca.sqlcode < 0) goto chkproviderjob_err;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_nature_path >= 0) {
                        v_nature_path.arr[v_nature_path.len]='\0';
			sprintf(csNaturePath,(const char*)v_nature_path.arr);
DEBUGLOG(("CheckProviderJobExists nature_path = [%s]\n",v_nature_path.arr));
                	iRet = PD_FOUND;
			break;
		}
        }
        while(PD_TRUE);

        if (iRet == PD_FOUND) {
DEBUGLOG(("CheckProviderJobExists Found!!\n"));
        } else {
DEBUGLOG(("CheckProviderJobExists Not Found!!\n"));
        }

	/* EXEC SQL CLOSE c_cursor_chkproviderjob; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )397;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto chkproviderjob_err;
}



	return iRet;

chkproviderjob_err:
DEBUGLOG(("chkproviderjob_err error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_chkproviderjob; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )412;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}

    	
	return PD_ERR;
}


int UpdateDisabledByProviderId(const hash_t *hRls)
{
	int     iTmp;
        char    *csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatedisabled_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

		/* varchar hv_provider_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_provider_id;

		int     hv_disabled;
		/* varchar hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


                short   ind_nature = -1;
                short   ind_provider_id = -1;
                short   ind_disabled = -1;
                short   ind_update_user = -1;

                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDisabledByProviderId: Begin\n"));

	if(GetField_CString(hRls,"nature",&csTmp))
        {
                hv_nature.len = strlen(csTmp);
                strncpy((char *)hv_nature.arr, csTmp, hv_nature.len);
                ind_nature = 0;
DEBUGLOG(("UpdateDisabledByProviderId:nature = [%.*s]\n",hv_nature.len,hv_nature.arr));
        } else {
DEBUGLOG(("UpdateDisabledByProviderId:nature is missing\n"));
ERRLOG("OLAutoUploadStmtSetting::UpdateDisabledByProviderId: nature is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"provider_id",&csTmp))
        {
                hv_provider_id.len = strlen(csTmp);
                strncpy((char *)hv_provider_id.arr, csTmp, hv_provider_id.len);
                ind_provider_id = 0;
DEBUGLOG(("UpdateDisabledByProviderId:provider_id = [%.*s]\n",hv_provider_id.len,hv_provider_id.arr));
        } else {
DEBUGLOG(("UpdateDisabledByProviderId:provider_id is missing\n"));
ERRLOG("OLAutoUploadStmtSetting::UpdateDisabledByProviderId: provider_id is missing\n");
                return PD_ERR;
        }

	if(GetField_Int(hRls,"disabled", &iTmp))
        {
                hv_disabled = iTmp;
                ind_disabled = 0;
DEBUGLOG(("UpdateDisabledByProviderId:disabled = [%d]\n",hv_disabled));
        } else {
DEBUGLOG(("UpdateDisabledByProviderId:disabled is missing\n"));
ERRLOG("OLAutoUploadStmtSetting::UpdateDisabledByProviderId: disabled is missing\n");
                return PD_ERR;
        }

	if(GetField_CString(hRls,"update_user",&csTmp))
        {
                hv_update_user.len = strlen(csTmp);
                strncpy((char *)hv_update_user.arr, csTmp, hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("UpdateDisabledByProviderId:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        } else {
DEBUGLOG(("UpdateDisabledByProviderId:update_user is missing\n"));
ERRLOG("OLAutoUploadStmtSetting::UpdateDisabledByProviderId: update_user is missing\n");
                return PD_ERR;
        }

	/* EXEC SQL EXECUTE
                BEGIN

                :hv_return_value := sp_ol_auto_upl_setting_upd(
                                        :hv_nature:ind_nature,
                                        :hv_provider_id:ind_provider_id,
                                        :hv_disabled:ind_disabled,
                                        :hv_update_user:ind_update_user);

                 END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_setting_upd ( :hv_\
nature:ind_nature , :hv_provider_id:ind_provider_id , :hv_disabled:ind_disabl\
ed , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )427;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_nature;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_provider_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_disabled;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto updatedisabled_error;
}



	DEBUGLOG(("UpdateDisabledByProviderId:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("UpdateDisabledByProviderId:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("OLAutoUploadStmtSetting_UpdateDisabledByProviderId: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("UpdateDisabledByProviderId: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAutoUploadStmtSetting_UpdateDisabledByProviderId: SP_ERR TxnAbort\n");
                DEBUGLOG(("UpdateDisabledByProviderId: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

updatedisabled_error:
DEBUGLOG(("updatedisabled_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_UpdateDisabledByProviderId: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}




int GetByProvId(const char* csProvId, const char* csNature, hash_t* hRec) 
{
	char csJobId[PD_JOB_ID_LEN];

	int  iCnt=0;
	int  iRet;
	/* EXEC SQL WHENEVER SQLERROR GOTO getbyprovid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_nature[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_nature;

		/* varchar		hv_prov_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_prov_id;


		/* varchar     v_prov_pathname[PD_PROV_PATHNAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_prov_pathname;

		
		unsigned long   v_job_id;
		
		short		ind_job_id = -1;
		short       ind_prov_pathname = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_nature.len = strlen(csNature);
	memcpy(hv_nature.arr,csNature,hv_nature.len);
DEBUGLOG(("GetByProvId nature = [%.*s]\n",hv_nature.len, hv_nature.arr));


	hv_prov_id.len = strlen(csProvId);
	memcpy(hv_prov_id.arr,csProvId,hv_prov_id.len);
DEBUGLOG(("GetByProvId prov_id = [%.*s]\n",hv_prov_id.len, hv_prov_id.arr));



	/* EXEC SQL DECLARE c_cursor_getbyprovid CURSOR FOR
		select	oaus_provider_pathname,
				oaus_job_id
		from	ol_auto_upload_stmt_setting
		where	oaus_provider_id = :hv_prov_id
		and	oaus_nature = :hv_nature; */ 


	/* EXEC SQL OPEN c_cursor_getbyprovid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )462;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_prov_id;
 sqlstm.sqhstl[0] = (unsigned long )12;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature;
 sqlstm.sqhstl[1] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto getbyprovid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbyprovid
		INTO	:v_prov_pathname:ind_prov_pathname,
				:v_job_id:ind_job_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 10;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )485;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_prov_pathname;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_prov_pathname;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_job_id;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_job_id;
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
  if (sqlca.sqlcode < 0) goto getbyprovid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}


DEBUGLOG(("GetByProvId found record\n"));

/*provider_path*/
		if (ind_prov_pathname >= 0) {
			v_prov_pathname.arr[v_prov_pathname.len]='\0';
			PutField_CString(hRec,"provider_path",(const char*)v_prov_pathname.arr);
DEBUGLOG(("GetProviderJob prov_pathname = [%s]\n",v_prov_pathname.arr));
		}
				
/* job_id */
		if (ind_job_id >= 0) {
			sprintf(csJobId, "%lu", v_job_id);
			PutField_CString(hRec,"job_id", csJobId);
DEBUGLOG(("GetByProvId job_id = [%s]\n", csJobId));
		}
		
		iCnt++;
	}
	while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbyprovid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )508;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbyprovid_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetByProvId Found\n"));
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetByProvId Not Found\n"));
		iRet = PD_NOT_FOUND;	
	}

DEBUGLOG(("GetByProvId Normal Exit\n"));
	return iRet;

getbyprovid_error:
DEBUGLOG(("getbyprovid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_GetByProvId: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbyprovid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )523;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;



}


int CheckDupProvPathname(const char *csProvId, const char *csProvPathName)
{        

	/* EXEC SQL WHENEVER SQLERROR GOTO checkdupprovpathname_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_prov_pathname[PD_PROV_PATHNAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_prov_pathname;

		/* varchar		hv_prov_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_prov_id;

		
		short		ind_prov_id = -1;
		short		ind_prov_pathname = -1;



		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("CheckDupProvPathname: Begin\n"));
	
/* prov_id */
	if(csProvId == NULL){
		hv_prov_id.len = 0;
DEBUGLOG(("CheckDupProvPathname:prov_id = NULL\n"));
	} 
	else {
		hv_prov_id.len = strlen(csProvId);
		strncpy((char *)hv_prov_id.arr, csProvId, hv_prov_id.len);
DEBUGLOG(("CheckDupProvPathname:prov_id = [%.*s]\n",hv_prov_id.len,hv_prov_id.arr));
	}
	ind_prov_id = 0;
	
	
/* prov_pathname */
	hv_prov_pathname.len = strlen(csProvPathName);
	strncpy((char *)hv_prov_pathname.arr, csProvPathName, hv_prov_pathname.len);
	ind_prov_pathname = 0;
	DEBUGLOG(("CheckDupProvPathname:prov_pathname = [%.*s]\n",hv_prov_pathname.len,hv_prov_pathname.arr));
	
	/* EXEC SQL EXECUTE
                BEGIN

                :hv_return_value := sp_ol_auto_upl_dup_path_chk(
                                        :hv_prov_id:ind_prov_id,
                                        :hv_prov_pathname:ind_prov_pathname);

                 END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 10;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_dup_path_chk ( :hv\
_prov_id:ind_prov_id , :hv_prov_pathname:ind_prov_pathname ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )538;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_prov_id;
 sqlstm.sqhstl[1] = (unsigned long )12;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_prov_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_prov_pathname;
 sqlstm.sqhstl[2] = (unsigned long )52;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_prov_pathname;
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
 if (sqlca.sqlcode < 0) goto checkdupprovpathname_error;
}



DEBUGLOG(("CheckDupProvPathname:Ret = [%d]\n",hv_return_value));
		
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("CheckDupProvPathname:Normal Exit\n"));
		return PD_NOT_FOUND;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLAutoUploadStmtSetting_CheckDupProvPathname: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("CheckDupProvPathname: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLAutoUploadStmtSetting_CheckDupProvPathname: SP_ERR TxnAbort\n");
DEBUGLOG(("CheckDupProvPathname: SP_ERR TxnAbort\n"));
		return PD_FOUND;
	}
		
		

checkdupprovpathname_error:
DEBUGLOG(("checkdupprovpathname_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadStmtSetting_CheckDupProvPathname: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;



}













