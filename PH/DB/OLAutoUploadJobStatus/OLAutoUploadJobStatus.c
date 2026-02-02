
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
    "OLAutoUploadJobStatus.pc"
};


static unsigned int sqlctx = 1292947779;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
5,0,0,1,293,0,6,115,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,
0,0,1,1,0,0,1,9,0,0,
52,0,0,2,293,0,6,269,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,
0,0,1,1,0,0,1,9,0,0,
99,0,0,0,0,0,56,384,0,0,1,1,0,1,0,3,102,0,0,
118,0,0,3,163,0,6,385,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,2,
102,0,0,
157,0,0,0,0,0,13,407,0,0,3,1,0,1,0,1,102,0,0,2,3,0,0,2,1,0,0,
184,0,0,0,0,0,15,451,0,0,1,1,0,1,0,1,102,0,0,
203,0,0,0,0,0,78,452,0,0,1,1,0,1,0,3,102,0,0,
222,0,0,0,0,0,15,459,0,0,1,1,0,1,0,1,102,0,0,
241,0,0,0,0,0,78,460,0,0,1,1,0,1,0,3,102,0,0,
260,0,0,4,122,0,4,485,0,0,2,1,0,1,0,2,3,0,0,1,3,0,0,
283,0,0,5,63,0,4,526,0,0,1,0,0,1,0,2,3,0,0,
302,0,0,6,61,0,2,532,0,0,1,1,0,1,0,1,3,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2018/03/07              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "internal.h"
#include "OLAutoUploadJobStatus.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;


void OLAutoUploadJobStatus(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        int     iTmp;
        char    *csTmp;
        char    cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_nature_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_nature_path;

                /* varchar         hv_provider_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_provider_path;

                /* varchar         hv_process_bank[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_process_bank;

		int		hv_exclude_mode;
                int             hv_job_seq;
                char            hv_status;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_nature_path = -1;
                short           ind_provider_path = -1;
                short           ind_process_bank = -1;
                short           ind_exclude_mode = -1;
                short           ind_job_seq = -1;
                short           ind_status = -1;
                short           ind_create_user = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add:Begin\n"));

	if(GetField_CString(hRls,"nature_path",&csTmp))
        {
                hv_nature_path.len = strlen(csTmp);
                strncpy((char *)hv_nature_path.arr, csTmp, hv_nature_path.len);
                ind_nature_path = 0;
DEBUGLOG(("Add:nature_path = [%.*s]\n",hv_nature_path.len,hv_nature_path.arr));
        }

        if(GetField_CString(hRls,"provider_path",&csTmp))
        {
                hv_provider_path.len = strlen(csTmp);
                strncpy((char *)hv_provider_path.arr, csTmp, hv_provider_path.len);
                ind_provider_path = 0;
DEBUGLOG(("Add:provider_path = [%.*s]\n",hv_provider_path.len,hv_provider_path.arr));
        }

        if(GetField_CString(hRls,"process_bank",&csTmp))
        {
                hv_process_bank.len = strlen(csTmp);
                strncpy((char *)hv_process_bank.arr, csTmp, hv_process_bank.len);
                ind_process_bank = 0;
DEBUGLOG(("Add:process_bank = [%.*s]\n",hv_process_bank.len,hv_process_bank.arr));
        }

        if(GetField_Int(hRls,"exclude_mode", &iTmp))
        {
                hv_exclude_mode = iTmp;
                ind_exclude_mode = 0;
DEBUGLOG(("Add:exclude_mode = [%d]\n",hv_exclude_mode));
        }

        if(GetField_Int(hRls,"job_seq", &iTmp))
        {
                hv_job_seq = iTmp;
                ind_job_seq = 0;
DEBUGLOG(("Add:job_seq = [%d]\n",hv_job_seq));
        }

	if(GetField_Char(hRls, "status", &cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
        }

        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN

                :hv_return_value := sp_ol_auto_upl_job_status_ins(
                                        :hv_nature_path:ind_nature_path,
                                        :hv_provider_path:ind_provider_path,
                                        :hv_process_bank:ind_process_bank,
                                        :hv_exclude_mode:ind_exclude_mode,
                                        :hv_job_seq:ind_job_seq,
                                        :hv_status:ind_status,
                                        :hv_create_user:ind_create_user);

                 END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_job_status_ins ( :\
hv_nature_path:ind_nature_path , :hv_provider_path:ind_provider_path , :hv_pr\
ocess_bank:ind_process_bank , :hv_exclude_mode:ind_exclude_mode , :hv_job_seq\
:ind_job_seq , :hv_status:ind_status , :hv_create_user:ind_create_user ) ; EN\
D ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature_path;
 sqlstm.sqhstl[1] = (unsigned long )258;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_nature_path;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_path;
 sqlstm.sqhstl[2] = (unsigned long )258;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_provider_path;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_process_bank;
 sqlstm.sqhstl[3] = (unsigned long )258;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_process_bank;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_exclude_mode;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_exclude_mode;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_job_seq;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_job_seq;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_status;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_create_user;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
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
                ERRLOG("OLAutoUploadJobStatus_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAutoUploadJobStatus_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadJobStatus_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int UpdateStatus(const hash_t *hRls)
{
	int     iTmp;
        char    *csTmp;
        char    cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatestatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_nature_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_nature_path;

                /* varchar         hv_provider_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_provider_path;

                /* varchar         hv_process_bank[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_process_bank;

                int             hv_exclude_mode;
                int             hv_job_seq;
                char            hv_status;
                /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


                short           ind_nature_path = -1;
                short           ind_provider_path = -1;
                short           ind_process_bank = -1;
                short           ind_exclude_mode = -1;
                short           ind_job_seq = -1;
                short           ind_status = -1;
                short           ind_update_user = -1;

                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateStatus:Begin\n"));
	
        if(GetField_CString(hRls,"nature_path",&csTmp))
        {
                hv_nature_path.len = strlen(csTmp);
                strncpy((char *)hv_nature_path.arr, csTmp, hv_nature_path.len);
                ind_nature_path = 0;
DEBUGLOG(("UpdateStatus:nature_path = [%.*s]\n",hv_nature_path.len,hv_nature_path.arr));
        } else {
DEBUGLOG(("UpdateStatus:nature_path is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: nature_path is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"provider_path",&csTmp))
        {
                hv_provider_path.len = strlen(csTmp);
                strncpy((char *)hv_provider_path.arr, csTmp, hv_provider_path.len);
                ind_provider_path = 0;
DEBUGLOG(("UpdateStatus:provider_path = [%.*s]\n",hv_provider_path.len,hv_provider_path.arr));
        } else {
DEBUGLOG(("UpdateStatus:provider_path is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: provider_path is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"process_bank",&csTmp))
        {
                hv_process_bank.len = strlen(csTmp);
                strncpy((char *)hv_process_bank.arr, csTmp, hv_process_bank.len);
                ind_process_bank = 0;
DEBUGLOG(("UpdateStatus:process_bank = [%.*s]\n",hv_process_bank.len,hv_process_bank.arr));
        } else {
DEBUGLOG(("UpdateStatus:process_bank is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: process_bank is missing\n");
                return PD_ERR;
        }

        if(GetField_Int(hRls,"exclude_mode", &iTmp))
        {
                hv_exclude_mode = iTmp;
                ind_exclude_mode = 0;
DEBUGLOG(("UpdateStatus:exclude_mode = [%d]\n",hv_exclude_mode));
        } else {
DEBUGLOG(("UpdateStatus:exclude_mode is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: exclude_mode is missing\n");
                return PD_ERR;
	}

        if(GetField_Int(hRls,"job_seq", &iTmp))
        {
                hv_job_seq = iTmp;
                ind_job_seq = 0;
DEBUGLOG(("UpdateStatus:job_seq = [%d]\n",hv_job_seq));
        } else {
DEBUGLOG(("UpdateStatus:job_seq is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: job_seq is missing\n");
                return PD_ERR;
	}

        if(GetField_Char(hRls, "status", &cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("UpdateStatus:status = [%c]\n",hv_status));
        } else {
DEBUGLOG(("UpdateStatus:status is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: status is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"update_user",&csTmp))
        {
                hv_update_user.len = strlen(csTmp);
                strncpy((char *)hv_update_user.arr, csTmp, hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("UpdateStatus:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        } else {
DEBUGLOG(("UpdateStatus:update_user is missing\n"));
ERRLOG("OLAutoUploadJobStatus::UpdateStatus: update_user is missing\n");
                return PD_ERR;
        }

	
        /* EXEC SQL EXECUTE
                BEGIN

                :hv_return_value := sp_ol_auto_upl_job_status_upd(
                                        :hv_nature_path:ind_nature_path,
                                        :hv_provider_path:ind_provider_path,
                                        :hv_process_bank:ind_process_bank,
                                        :hv_exclude_mode:ind_exclude_mode,
                                        :hv_job_seq:ind_job_seq,
                                        :hv_status:ind_status,
                                        :hv_update_user:ind_update_user);

                 END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_job_status_\
upd ( :hv_nature_path:ind_nature_path , :hv_provider_path:ind_provider_path ,\
 :hv_process_bank:ind_process_bank , :hv_exclude_mode:ind_exclude_mode , :hv_\
job_seq:ind_job_seq , :hv_status:ind_status , :hv_update_user:ind_update_user\
 ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )52;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature_path;
        sqlstm.sqhstl[1] = (unsigned long )258;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_nature_path;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_path;
        sqlstm.sqhstl[2] = (unsigned long )258;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_provider_path;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_process_bank;
        sqlstm.sqhstl[3] = (unsigned long )258;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_process_bank;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_exclude_mode;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_exclude_mode;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_job_seq;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_job_seq;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_status;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_update_user;
        sqlstm.sqhstl[7] = (unsigned long )22;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_update_user;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto updatestatus_error;
}



        DEBUGLOG(("UpdateStatus:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("UpdateStatus:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("OLAutoUploadJobStatus_UpdateStatus: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("UpdateStatus: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAutoUploadJobStatus_UpdateStatus: SP_ERR TxnAbort\n");
                DEBUGLOG(("UpdateStatus: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

updatestatus_error:
DEBUGLOG(("updatestatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadJobStatus_UpdateStatus: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetStatus(hash_t *hRls)
{
	int     iCnt = 0;
       	int	iTmp = 0;
	char    *csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO getstatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_nature_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_nature_path;

                /* varchar         hv_provider_path[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_provider_path;

                /* varchar         hv_process_bank[PD_TMP_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_process_bank;

                int             hv_exclude_mode;

		short   	hv_return_value;

                int             v_job_seq;
                char            v_status;

                short           ind_job_seq = -1;
                short           ind_status = -1;

		SQL_CURSOR      c_cursor_getstatus;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetStatus:Begin\n"));
	
        if(GetField_CString(hRls,"nature_path",&csTmp))
        {
                hv_nature_path.len = strlen(csTmp);
                strncpy((char *)hv_nature_path.arr, csTmp, hv_nature_path.len);
DEBUGLOG(("GetStatus:nature_path = [%.*s]\n",hv_nature_path.len,hv_nature_path.arr));
        } else {
DEBUGLOG(("GetStatus:nature_path is missing\n"));
ERRLOG("OLAutoUploadJobStatus::GetStatus: nature_path is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"provider_path",&csTmp))
        {
                hv_provider_path.len = strlen(csTmp);
                strncpy((char *)hv_provider_path.arr, csTmp, hv_provider_path.len);
DEBUGLOG(("GetStatus:provider_path = [%.*s]\n",hv_provider_path.len,hv_provider_path.arr));
        } else {
DEBUGLOG(("GetStatus:provider_path is missing\n"));
ERRLOG("OLAutoUploadJobStatus::GetStatus: provider_path is missing\n");
                return PD_ERR;
        }

        if(GetField_CString(hRls,"process_bank",&csTmp))
        {
                hv_process_bank.len = strlen(csTmp);
                strncpy((char *)hv_process_bank.arr, csTmp, hv_process_bank.len);
DEBUGLOG(("GetStatus:process_bank = [%.*s]\n",hv_process_bank.len,hv_process_bank.arr));
        } else {
DEBUGLOG(("GetStatus:process_bank is missing\n"));
ERRLOG("OLAutoUploadJobStatus::GetStatus: process_bank is missing\n");
                return PD_ERR;
        }

        if(GetField_Int(hRls,"exclude_mode", &iTmp))
        {
                hv_exclude_mode = iTmp;
DEBUGLOG(("GetStatus:exclude_mode = [%d]\n",hv_exclude_mode));
        } else {
DEBUGLOG(("GetStatus:exclude_mode is missing\n"));
ERRLOG("OLAutoUploadJobStatus::GetStatus: exclude_mode is missing\n");
                return PD_ERR;
	}

	/* EXEC SQL ALLOCATE       :c_cursor_getstatus; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
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
 if (sqlca.sqlcode < 0) goto getstatus_error;
}

	
        /* EXEC SQL EXECUTE
                BEGIN

                :hv_return_value := sp_ol_auto_upl_job_status_get(
                                        :hv_nature_path,
                                        :hv_provider_path,
                                        :hv_process_bank,
                                        :hv_exclude_mode,
					:c_cursor_getstatus);

                 END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_auto_upl_job_status_\
get ( :hv_nature_path , :hv_provider_path , :hv_process_bank , :hv_exclude_mo\
de , :c_cursor_getstatus ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )118;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_nature_path;
        sqlstm.sqhstl[1] = (unsigned long )258;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_provider_path;
        sqlstm.sqhstl[2] = (unsigned long )258;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_process_bank;
        sqlstm.sqhstl[3] = (unsigned long )258;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_exclude_mode;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_getstatus;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getstatus_error;
}



DEBUGLOG(("GetStatus:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
		for (;;) {

                        ind_job_seq = -1;
                        ind_status = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_getstatus

                        INTO
                                :v_job_seq:ind_job_seq,
                                :v_status:ind_status; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 8;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )157;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_job_seq;
                        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_job_seq;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[2] = (unsigned long )1;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_status;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getstatus_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

/* job_seq */
                        if(ind_job_seq>=0){
                                PutField_Int(hRls,"job_seq",v_job_seq);
DEBUGLOG(("GetStatus:job_seq = [%d]\n",v_job_seq));
                        }

/* status */
                        if(ind_status>=0){
                                PutField_Char(hRls,"status",v_status);
DEBUGLOG(("GetStatus:status = [%c]\n",v_status));
                        }

                        iCnt++;
		}

                DEBUGLOG(("GetStatus:Found\n"));
                return PD_FOUND;
        }
	else if (hv_return_value == SP_NOT_FOUND)
        {
		DEBUGLOG(("GetStatus:Not Found\n"));
                return PD_NOT_FOUND;
        }
        else if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("OLAutoUploadJobStatus_GetStatus: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("GetStatus: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }
        else if (hv_return_value == SP_ERR)  {
                ERRLOG("OLAutoUploadJobStatus_GetStatus: SP_ERR TxnAbort\n");
                DEBUGLOG(("GetStatus: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

	/* EXEC SQL CLOSE :c_cursor_getstatus; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )184;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
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
 if (sqlca.sqlcode < 0) goto getstatus_error;
}


        /* EXEC SQL FREE :c_cursor_getstatus; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )203;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
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
        if (sqlca.sqlcode < 0) goto getstatus_error;
}



getstatus_error:
DEBUGLOG(("getstatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLAutoUploadJobStatus_GetStatus: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_getstatus; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )222;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
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


        /* EXEC SQL FREE :c_cursor_getstatus; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )241;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_getstatus;
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

int CheckAllJobFinish(int iJobSeq)
{
        int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkfinish_err; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_seq;
                //char  hv_status_1;
                //char  hv_status_2;
                int     v_cnt;
                short   ind_cnt = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_seq = iJobSeq;
DEBUGLOG(("CheckAllJobFinish hv_seq [%d]\n",iJobSeq));

        //hv_status_1 = PD_AUTO_UPL_JOB_STATUS_PENDING;
        //hv_status_2 = PD_AUTO_UPL_JOB_STATUS_INITIAL;

        /* EXEC SQL SELECT COUNT(*)
                   INTO :v_cnt:ind_cnt
                 FROM OL_AUTO_UPLOAD_JOB_STATUS
                 WHERE OAUJS_JOB_SEQ = :hv_seq
                 //AND OAUJ^BS_STATUS IN ('P');
                 AND OAUJS_STATUS IN ('I', 'P'); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select COUNT ( * ) INTO :b0:b1 FROM OL_AUTO_UPLOAD_J\
OB_STATUS WHERE OAUJS_JOB_SEQ = :b2 AND OAUJS_STATUS IN ( 'I' , 'P' ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )260;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cnt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto checkfinish_err;
}


                 //AND OAUJS_STATUS in (:hv_status_1, :hv_status_2);

        if (ind_cnt >= 0) {
                if (v_cnt == 0) {
                        iRet = PD_TRUE;
                }
        }

        if (iRet == PD_TRUE) {
DEBUGLOG(("CheckAllJobFinish TRUE\n"));
        } else {
DEBUGLOG(("CheckAllJobFinish FALSE\n"));
        }

        return iRet;

checkfinish_err:
DEBUGLOG(("checkfinish_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetNextJobSeq(int *iJobSeq)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getseq_err; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int     hv_seq;
                short   ind_seq = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


//DEBUGLOG(("GetNextJobSeq()\n"));
        /* EXEC SQL SELECT OL_AUTO_UPLOAD_STMT_SEQ.NEXTVAL
                   INTO :hv_seq:ind_seq
                 FROM dual; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select OL_AUTO_UPLOAD_STMT_SEQ . NEXTVAL INTO :b0:b1\
 FROM dual ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )283;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_seq;
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
        if (sqlca.sqlcode < 0) goto getseq_err;
}



        if (ind_seq >= 0)  {
                //Delete Old Log record in DB
                /* EXEC SQL DELETE FROM OL_AUTO_UPLOAD_ERR_LOG WHERE OAUEL_JOB_SEQ = :hv_seq; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "delete FROM OL_AUTO_UPLOAD_ERR_LOG WHERE OAU\
EL_JOB_SEQ = :b0 ";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )302;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&hv_seq;
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
                if (sqlca.sqlcode < 0) goto getseq_err;
}


		
		*iJobSeq = hv_seq;

                return PD_OK;
        }
        else
                return PD_ERR;

getseq_err:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
