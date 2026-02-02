
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "check_dsi_callback.pc"
};


static unsigned int sqlctx = 145328323;


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
"SELECT th_txn_id , th_status , th_ar_ind , th_sub_status , ss . ds_name , t\
o_char ( th_approval_timestamp , 'YYYY-MM-DD HH24:MI:SS' ) FROM ( SELECT th_t\
xn_id , th_status , th_ar_ind , th_sub_status , th_approval_timestamp FROM tx\
n_header WHERE th_txn_code = 'DSI' AND th_create_timestamp >= trunc ( sysdate\
 ) - ( :b0 ) AND th_status in ( 'R' , 'C' ) AND th_ar_ind = 'A' AND th_approv\
al_timestamp < sysdate - ( :b1 ) / ( 60 * 24 ) and th_sub_status = '103' ) le\
ft join def_sub_status ss on ss . ds_sub_status = th_sub_status order by th_a\
pproval_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,566,0,9,109,0,2049,2,2,0,1,0,1,3,0,0,1,3,0,0,
28,0,0,1,0,0,13,111,0,0,6,0,0,1,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
67,0,0,1,0,0,15,164,0,0,0,0,0,1,0,
82,0,0,1,0,0,15,174,0,0,0,0,0,1,0,
97,0,0,2,0,0,32,175,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/05/12              Virginia Yun
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_CHECK_PREIOD_DAYS     7
#define PD_APPROVE_PERIOD_MINS   5

OBJPTR(DB);
char    cDebug;

int process_dsi_callback();


int batch_init(int argc, char* argv[])
{
        return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
        int     iRet = SUCCESS;

	iRet = process_dsi_callback();

	return iRet;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_dsi_callback()
{
	int	iRet = SUCCESS;

        /* EXEC SQL WHENEVER SQLERROR GOTO dsi_sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int	hv_create_period;
		int	hv_approval_period;

		/* varchar	v_txn_seq[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_seq;

		char	v_status;
		char	v_ar_ind;
		/* varchar	v_sub_status[PD_SUB_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		/* varchar	v_sub_status_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

		/* varchar	v_approval_timestamp[PD_DATETIME_LEN + 5 + 1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_approval_timestamp;


		short	ind_txn_seq = -1;
		short	ind_status = -1;
		short	ind_ar_ind = -1;
		short	ind_sub_status = -1;
		short	ind_sub_status_desc = -1;
		short	ind_approval_timestamp = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_create_period = PD_CHECK_PREIOD_DAYS;
	hv_approval_period = PD_APPROVE_PERIOD_MINS;

        /* EXEC SQL DECLARE c_cursor_get_dsi_list CURSOR FOR
		SELECT th_txn_id, th_status, th_ar_ind, 
                       th_sub_status, ss.ds_name, 
                       to_char(th_approval_timestamp, 'YYYY-MM-DD HH24:MI:SS')
		FROM (
			SELECT th_txn_id, th_status, th_ar_ind, 
                               th_sub_status,
			       th_approval_timestamp
			FROM txn_header
			WHERE th_txn_code = 'DSI'
		        AND th_create_timestamp >= trunc(sysdate) - (:hv_create_period)
		        AND th_status in ('R', 'C')
			AND th_ar_ind = 'A'
			AND th_approval_timestamp < sysdate - (:hv_approval_period) / (60* 24)
			and th_sub_status = '103'
		) 	 
		left join def_sub_status ss
		on ss.ds_sub_status = th_sub_status
		order by th_approval_timestamp; */ 



	/* EXEC SQL OPEN c_cursor_get_dsi_list; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_create_period;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_approval_period;
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
 if (sqlca.sqlcode < 0) goto dsi_sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_get_dsi_list
		INTO 
			v_txn_seq:ind_txn_seq,
                	v_status:ind_status,
                	v_ar_ind:ind_ar_ind,
                	v_sub_status:ind_sub_status,
                	v_sub_status_desc:ind_sub_status_desc,
			v_approval_timestamp:ind_approval_timestamp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_seq;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_txn_seq;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_status;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[2] = (unsigned long )1;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_ar_ind;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_sub_status;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_sub_status_desc;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_sub_status_desc;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_approval_timestamp;
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
  if (sqlca.sqlcode < 0) goto dsi_sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iRet = PD_FOUND;

		if (ind_txn_seq >= 0) {
                        v_txn_seq.arr[v_txn_seq.len]='\0';
DEBUGLOG(("check_dsi_callback: txn_seq =[%.*s]\n", v_txn_seq.len, v_txn_seq.arr));
		}

		if (ind_status >= 0) {
DEBUGLOG(("check_dsi_callback: status=[%c]\n", v_status));
		}

		if (ind_ar_ind >= 0) {
DEBUGLOG(("check_dsi_callback: ar_ind =[%c]\n", v_ar_ind));
		}

		if (ind_sub_status >= 0) {
                        v_sub_status.arr[v_sub_status.len]='\0';
DEBUGLOG(("check_dsi_callback: sub_status =[%.*s]\n", v_sub_status.len, v_sub_status.arr));
		}

		if (ind_sub_status_desc >= 0) {
                        v_sub_status_desc.arr[v_sub_status_desc.len]='\0';
DEBUGLOG(("check_dsi_callback: sub_status_desc =[%.*s]\n", v_sub_status_desc.len, v_sub_status_desc.arr));
		}


		if (ind_approval_timestamp >= 0) {
                        v_approval_timestamp.arr[v_approval_timestamp.len]='\0';
DEBUGLOG(("check_dsi_callback: approval_timestamp =[%.*s]\n", v_approval_timestamp.len, v_approval_timestamp.arr));
		}

		printf("<tr><td>%.*s</td><td>%.*s</td><td>%.*s</td><td>%.*s</td></tr>\n", 
			v_txn_seq.len, v_txn_seq.arr,
			v_sub_status.len, v_sub_status.arr,
			v_sub_status_desc.len, v_sub_status_desc.arr,
			v_approval_timestamp.len, v_approval_timestamp.arr);


	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get_dsi_list; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )67;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto dsi_sql_error;
}



        return  iRet;

dsi_sql_error:
    DEBUGLOG(("check_dsi_callback error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("check_dsi_callback::process_dsi_callback sql error %d\n", sqlca.sqlcode);

    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_dsi_list; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
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


    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )97;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;

}

