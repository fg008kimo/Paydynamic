
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
    "PspTxnCheckReportLog.pc"
};


static unsigned int sqlctx = 679883587;


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
   unsigned char  *sqhstv[16];
   unsigned long  sqhstl[16];
            int   sqhsts[16];
            short *sqindv[16];
            int   sqinds[16];
   unsigned long  sqharm[16];
   unsigned long  *sqharc[16];
   unsigned short  sqadto[16];
   unsigned short  sqtdso[16];
} sqlstm = {12,16};

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

 static char *sq0002 = 
"select pl_seq , pl_party_type , pl_party_id , pl_party_name , pl_bank_code \
, pl_bank_name , to_char ( pl_dur_start , 'DD-MON-YYYY HH24:MI:SS' ) , to_cha\
r ( pl_dur_end , 'DD-MON-YYYY HH24:MI:SS' ) , pl_succ_cnt , pl_pend_cnt , pl_\
total_cnt from psp_txn_check_rpt_log where pl_rpt_gen_id = :b0 and pl_rpt_gen\
_datetime = :b1 and pl_rpt_type = :b2 order by pl_seq asc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,515,0,6,199,0,0,16,16,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,3,0,0,
1,9,0,0,
84,0,0,2,375,0,9,330,0,2049,3,3,0,1,0,1,3,0,0,1,9,0,0,1,9,0,0,
111,0,0,2,0,0,13,332,0,0,11,0,0,1,0,2,3,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,
170,0,0,2,0,0,15,429,0,0,0,0,0,1,0,
185,0,0,2,0,0,15,444,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/07/28              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "PspTxnCheckReportLog.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void PspTxnCheckReportLog(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char  cTmp;
        char  *csTmp;
        int   iTmp;
	int   iCommit = PD_TRUE;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int         	hv_rpt_gen_id;
		/* varchar         hv_rpt_gen_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_rpt_gen_datetime;

                /* varchar         hv_rpt_type[PD_PSP_REPORT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_rpt_type;

                int         	hv_seq;
                char        	hv_party_type;
                /* varchar         hv_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_party_id;

		/* varchar		hv_party_name[PD_MMS_PARTY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_party_name;

                /* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar		hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

		/* varchar		hv_dur_start[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_dur_start;

		/* varchar		hv_dur_end[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_dur_end;

		int		hv_succ_cnt;
		int		hv_pend_cnt;
		int		hv_total_cnt;
                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_rpt_gen_id = -1;
                short           ind_rpt_gen_datetime = -1;
                short           ind_rpt_type = -1;
                short           ind_seq = -1;
                short           ind_party_type = -1;
                short           ind_party_id = -1;
                short           ind_party_name = -1;
                short           ind_bank_code = -1;
                short           ind_bank_name = -1;
                short           ind_dur_start = -1;
                short           ind_dur_end = -1;
                short           ind_succ_cnt = -1;
                short           ind_pend_cnt = -1;
                short           ind_total_cnt = -1;
                short           ind_create_user = -1;

                short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

// db_commit
        if (GetField_Int(hRls,"db_commit",&iCommit)) {
DEBUGLOG(("Add:db_commit = [%d]\n",iCommit));
        }

// rpt_gen_id
	if(GetField_Int(hRls, "rpt_gen_id", &iTmp)) {
                hv_rpt_gen_id = iTmp;
                ind_rpt_gen_id = 0;
DEBUGLOG(("Add:rpt_gen_id = [%d]\n",hv_rpt_gen_id));
	}

// rpt_gen_datetime
	if(GetField_CString(hRls,"rpt_gen_datetime",&csTmp)) {
                hv_rpt_gen_datetime.len = strlen(csTmp);
                strncpy((char*)hv_rpt_gen_datetime.arr, csTmp, hv_rpt_gen_datetime.len);
                ind_rpt_gen_datetime = 0;
DEBUGLOG(("Add:rpt_gen_datetime = [%.*s]\n",hv_rpt_gen_datetime.len, hv_rpt_gen_datetime.arr));
	}

// rpt_type
	if(GetField_CString(hRls,"rpt_type",&csTmp)) {
                hv_rpt_type.len = strlen(csTmp);
                strncpy((char*)hv_rpt_type.arr, csTmp, hv_rpt_type.len);
                ind_rpt_type = 0;
DEBUGLOG(("Add:rpt_type = [%.*s]\n",hv_rpt_type.len, hv_rpt_type.arr));	
	}

// seq
	if(GetField_Int(hRls, "seq", &iTmp)) {
                hv_seq = iTmp;
                ind_seq = 0;
DEBUGLOG(("Add:seq = [%d]\n",hv_seq));	
	}

// party_type
	if (GetField_Char(hRls, "party_type", &cTmp)) {
                hv_party_type = cTmp;
                ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%c]\n",hv_party_type));
	}

// party_id
	if(GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                strncpy((char*)hv_party_id.arr, csTmp, hv_party_id.len);
                ind_party_id = 0;
DEBUGLOG(("Add:party_id = [%.*s]\n",hv_party_id.len, hv_party_id.arr));
	}

// party_name
	if(GetField_CString(hRls,"party_name",&csTmp)) {
                hv_party_name.len = strlen(csTmp);
                strncpy((char*)hv_party_name.arr, csTmp, hv_party_name.len);
                ind_party_name = 0;
DEBUGLOG(("Add:party_name = [%.*s]\n",hv_party_name.len, hv_party_name.arr));
	}

// bank_code
        if(GetField_CString(hRls,"bank_code",&csTmp)) {
                hv_bank_code.len = strlen(csTmp);
                strncpy((char*)hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code = 0;
DEBUGLOG(("Add:bank_code = [%.*s]\n",hv_bank_code.len, hv_bank_code.arr));
	}

// bank_name
	if(GetField_CString(hRls,"bank_name",&csTmp)) {
                hv_bank_name.len = strlen(csTmp);
                strncpy((char*)hv_bank_name.arr, csTmp, hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s]\n",hv_bank_name.len, hv_bank_name.arr));
	}

// dur_start
	if(GetField_CString(hRls,"dur_start",&csTmp)) {
                hv_dur_start.len = strlen(csTmp);
                strncpy((char*)hv_dur_start.arr, csTmp, hv_dur_start.len);
                ind_dur_start = 0;
DEBUGLOG(("Add:dur_start = [%.*s]\n",hv_dur_start.len, hv_dur_start.arr));
	}

// dur_end
	if(GetField_CString(hRls,"dur_end",&csTmp)) {
                hv_dur_end.len = strlen(csTmp);
                strncpy((char*)hv_dur_end.arr, csTmp, hv_dur_end.len);
                ind_dur_end = 0;
DEBUGLOG(("Add:dur_end = [%.*s]\n",hv_dur_end.len, hv_dur_end.arr));
	}

// succ_cnt
	if(GetField_Int(hRls, "succ_cnt", &iTmp)) {
                hv_succ_cnt = iTmp;
                ind_succ_cnt = 0;
DEBUGLOG(("Add:succ_cnt = [%d]\n",hv_succ_cnt));          
	}

// pend_cnt
	if(GetField_Int(hRls, "pend_cnt", &iTmp)) {
                hv_pend_cnt = iTmp;
                ind_pend_cnt = 0;
DEBUGLOG(("Add:pend_cnt = [%d]\n",hv_pend_cnt));
	}

// total_cnt
	if(GetField_Int(hRls, "total_cnt", &iTmp)) {
                hv_total_cnt = iTmp;
                ind_total_cnt = 0;
DEBUGLOG(("Add:total_cnt = [%d]\n",hv_total_cnt));
	}

// create_user
        if(GetField_CString(hRls,"create_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_psp_txn_chk_rpt_log_insert(
                                                :hv_rpt_gen_id:ind_rpt_gen_id,
                                                :hv_rpt_gen_datetime:ind_rpt_gen_datetime,
                                                :hv_rpt_type:ind_rpt_type,
                                                :hv_seq:ind_seq,
                                                :hv_party_type:ind_party_type,
                                                :hv_party_id:ind_party_id,
                                                :hv_party_name:ind_party_name,
                                                :hv_bank_code:ind_bank_code,
                                                :hv_bank_name:ind_bank_name,
                                                :hv_dur_start:ind_dur_start,
                                                :hv_dur_end:ind_dur_end,
                                                :hv_succ_cnt:ind_succ_cnt,
                                                :hv_pend_cnt:ind_pend_cnt,
                                                :hv_total_cnt:ind_total_cnt,
                                                :hv_create_user:ind_create_user
                                                );
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 16;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_psp_txn_chk_rpt_log_ins\
ert ( :hv_rpt_gen_id:ind_rpt_gen_id , :hv_rpt_gen_datetime:ind_rpt_gen_dateti\
me , :hv_rpt_type:ind_rpt_type , :hv_seq:ind_seq , :hv_party_type:ind_party_t\
ype , :hv_party_id:ind_party_id , :hv_party_name:ind_party_name , :hv_bank_co\
de:ind_bank_code , :hv_bank_name:ind_bank_name , :hv_dur_start:ind_dur_start \
, :hv_dur_end:ind_dur_end , :hv_succ_cnt:ind_succ_cnt , :hv_pend_cnt:ind_pend\
_cnt , :hv_total_cnt:ind_total_cnt , :hv_create_user:ind_create_user ) ; END \
;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_rpt_gen_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_rpt_gen_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_rpt_gen_datetime;
        sqlstm.sqhstl[2] = (unsigned long )16;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_rpt_gen_datetime;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_rpt_type;
        sqlstm.sqhstl[3] = (unsigned long )52;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_rpt_type;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_seq;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_seq;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_party_type;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_party_type;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_party_id;
        sqlstm.sqhstl[6] = (unsigned long )17;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_party_id;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_party_name;
        sqlstm.sqhstl[7] = (unsigned long )52;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_party_name;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_bank_code;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_name;
        sqlstm.sqhstl[9] = (unsigned long )152;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_bank_name;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_dur_start;
        sqlstm.sqhstl[10] = (unsigned long )22;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_dur_start;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_dur_end;
        sqlstm.sqhstl[11] = (unsigned long )22;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_dur_end;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_succ_cnt;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_succ_cnt;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_pend_cnt;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_pend_cnt;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_total_cnt;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_total_cnt;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[15] = (unsigned long )22;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_create_user;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
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
		if (iCommit == PD_TRUE) {
                 	TxnCommit();
		}
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("PspTxnCheckReportLog_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("PspTxnCheckReportLog_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspTxnCheckReportLog_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetPspTxnCheckReportLog(hash_t *myHash, recordset_t *myRec)
{
	int 	iCnt = 0;
	int 	iTmp;
	char  	*csTmp;
	hash_t 	*hTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpsprptlog_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int             hv_rpt_gen_id;
                /* varchar         hv_rpt_gen_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_rpt_gen_datetime;

                /* varchar         hv_rpt_type[PD_PSP_REPORT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_rpt_type;

                
		int             v_seq;
                char            v_party_type;
                /* varchar         v_party_id[PD_MMS_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_party_id;

                /* varchar         v_party_name[PD_MMS_PARTY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } v_party_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_bank_code;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } v_bank_name;

                /* varchar         v_dur_start[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_dur_start;

                /* varchar         v_dur_end[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_dur_end;

                int             v_succ_cnt;
                int             v_pend_cnt;
                int             v_total_cnt;

                short           ind_seq = -1;
                short           ind_party_type = -1;
                short           ind_party_id = -1;
                short           ind_party_name = -1;
                short           ind_bank_code = -1;
                short           ind_bank_name = -1;
                short           ind_dur_start = -1;
                short           ind_dur_end = -1;
                short           ind_succ_cnt = -1;
                short           ind_pend_cnt = -1;
                short           ind_total_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// rpt_gen_id
	if (GetField_Int(myHash, "rpt_gen_id", &iTmp)) {
                hv_rpt_gen_id = iTmp;
DEBUGLOG(("GetPspTxnCheckReportLog rpt_gen_id = [%d]\n", hv_rpt_gen_id));
        }

// rpt_gen_datetime
	if (GetField_CString(myHash, "rpt_gen_datetime", &csTmp)) {
                hv_rpt_gen_datetime.len = strlen(csTmp);
                memcpy(hv_rpt_gen_datetime.arr, csTmp, hv_rpt_gen_datetime.len);
DEBUGLOG(("GetPspTxnCheckReportLog rpt_gen_datetime = [%.*s]\n", hv_rpt_gen_datetime.len, hv_rpt_gen_datetime.arr));
        }	

// rpt_type
	if (GetField_CString(myHash, "rpt_type", &csTmp)) {
                hv_rpt_type.len = strlen(csTmp);
                memcpy(hv_rpt_type.arr, csTmp, hv_rpt_type.len);
DEBUGLOG(("GetPspTxnCheckReportLog rpt_type = [%.*s]\n", hv_rpt_type.len, hv_rpt_type.arr));
        }

        /* EXEC SQL DECLARE c_cursor_getpsprptlog CURSOR FOR
		select pl_seq,
		       pl_party_type,
		       pl_party_id,
		       pl_party_name,
		       pl_bank_code,
		       pl_bank_name,
		       to_char(pl_dur_start,'DD-MON-YYYY HH24:MI:SS'),
		       to_char(pl_dur_end,'DD-MON-YYYY HH24:MI:SS'),	
		       pl_succ_cnt,
		       pl_pend_cnt,
		       pl_total_cnt
		  from psp_txn_check_rpt_log
		 where pl_rpt_gen_id = :hv_rpt_gen_id
		   and pl_rpt_gen_datetime = :hv_rpt_gen_datetime
		   and pl_rpt_type = :hv_rpt_type
		order by pl_seq asc; */ 


        /* EXEC SQL OPEN c_cursor_getpsprptlog; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 16;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )84;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_rpt_gen_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_rpt_gen_datetime;
        sqlstm.sqhstl[1] = (unsigned long )16;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_rpt_type;
        sqlstm.sqhstl[2] = (unsigned long )52;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getpsprptlog_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getpsprptlog
		INTO	:v_seq:ind_seq,
                        :v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_party_name:ind_party_name,
			:v_bank_code:ind_bank_code,
			:v_bank_name:ind_bank_name,
			:v_dur_start:ind_dur_start,
			:v_dur_end:ind_dur_end,
			:v_succ_cnt:ind_succ_cnt,
			:v_pend_cnt:ind_pend_cnt,
			:v_total_cnt:ind_total_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 16;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )111;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_seq;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_party_type;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_party_type;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_party_id;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_party_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_party_name;
  sqlstm.sqhstl[3] = (unsigned long )52;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_party_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[4] = (unsigned long )12;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_bank_code;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_name;
  sqlstm.sqhstl[5] = (unsigned long )152;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_bank_name;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_dur_start;
  sqlstm.sqhstl[6] = (unsigned long )22;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_dur_start;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_dur_end;
  sqlstm.sqhstl[7] = (unsigned long )22;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_dur_end;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_succ_cnt;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_succ_cnt;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_pend_cnt;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_pend_cnt;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_total_cnt;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_total_cnt;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getpsprptlog_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}	

		iCnt++;

		hTmp = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hTmp, 0);

/* seq */
                if (ind_seq >= 0) {
                        PutField_Int(hTmp, "seq", v_seq);
DEBUGLOG(("GetPspTxnCheckReportLog seq = [%d]\n", v_seq));
                }

/* party_type */
                if (ind_party_type >= 0) {
                        PutField_Char(hTmp, "party_type", v_party_type);
DEBUGLOG(("GetPspTxnCheckReportLog party_type = [%c]\n",v_party_type));
                }

/* party_id */
                if (ind_party_id >= 0) {
                        v_party_id.arr[v_party_id.len] = '\0';
                        PutField_CString(hTmp, "party_id", (const char *)v_party_id.arr);
DEBUGLOG(("GetPspTxnCheckReportLog party_id = [%s]\n",v_party_id.arr));
                }

/* party_name */
                if (ind_party_name >= 0) {
                        v_party_name.arr[v_party_name.len] = '\0';
                        PutField_CString(hTmp, "party_name", (const char *)v_party_name.arr);
DEBUGLOG(("GetPspTxnCheckReportLog party_name = [%s]\n",v_party_name.arr));
                }

/* bank_code */
                if (ind_bank_code >= 0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
                        PutField_CString(hTmp, "bank_code", (const char *)v_bank_code.arr);
DEBUGLOG(("GetPspTxnCheckReportLog bank_code = [%s]\n",v_bank_code.arr));
                }

/* bank_name */
                if (ind_bank_name >= 0) {
                        v_bank_name.arr[v_bank_name.len] = '\0';
                        PutField_CString(hTmp, "bank_name", (const char *)v_bank_name.arr);
DEBUGLOG(("GetPspTxnCheckReportLog bank_name = [%s]\n",v_bank_name.arr));
                }

/* dur_start */
                if (ind_dur_start >= 0) {
                        v_dur_start.arr[v_dur_start.len] = '\0';
                        PutField_CString(hTmp, "dur_start", (const char *)v_dur_start.arr);
DEBUGLOG(("GetPspTxnCheckReportLog dur_start = [%s]\n",v_dur_start.arr));
                }

/* dur_end */
                if (ind_dur_end >= 0) {
                        v_dur_end.arr[v_dur_end.len] = '\0';
                        PutField_CString(hTmp, "dur_end", (const char *)v_dur_end.arr);
DEBUGLOG(("GetPspTxnCheckReportLog dur_end = [%s]\n",v_dur_end.arr));
                }

/* succ_cnt */
                if (ind_succ_cnt >= 0) {
                        PutField_Int(hTmp, "succ_cnt", v_succ_cnt);
DEBUGLOG(("GetPspTxnCheckReportLog succ_cnt = [%d]\n", v_succ_cnt));
                }

/* pend_cnt */
                if (ind_pend_cnt >= 0) {
                        PutField_Int(hTmp, "pend_cnt", v_pend_cnt);
DEBUGLOG(("GetPspTxnCheckReportLog pend_cnt = [%d]\n", v_pend_cnt));
                }

/* total_cnt */
                if (ind_total_cnt >= 0) {
                        PutField_Int(hTmp, "total_cnt", v_total_cnt);
DEBUGLOG(("GetPspTxnCheckReportLog total_cnt = [%d]\n", v_total_cnt));
                }

		RecordSet_Add(myRec, hTmp);
	}
	while (PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getpsprptlog; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 16;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )170;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getpsprptlog_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetPspTxnCheckReportLog Normal Exit, Found\n"));
                return  PD_FOUND;
        }
        else {
DEBUGLOG(("GetPspTxnCheckReportLog Normal Exit, Not Found\n"));
                return 	PD_NOT_FOUND;
        }

getpsprptlog_error:
DEBUGLOG(("getpsprptlog_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpsprptlog; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 16;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )185;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

