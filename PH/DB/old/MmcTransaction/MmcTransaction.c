
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "MmcTransaction.pc"
};


static unsigned int sqlctx = 9981851;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,704,0,6,229,0,0,19,19,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
96,0,0,2,0,0,17,400,0,0,1,1,0,1,0,1,9,0,0,
115,0,0,2,0,0,21,401,0,0,0,0,0,1,0,
130,0,0,3,772,0,6,599,0,0,19,19,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,1,0,0,
1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/11/21              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MmcTransaction.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MmcTransaction(char    cdebug)
{
        cDebug = cdebug;
}

int AddHeader(const hash_t *hRls)
{
        char        	*csTmp;
        char           	cTmp;
	double		dTmp = 0.0;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short   	hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        
        /* varchar         hv_org_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_txn_id;
        
        /* varchar         hv_next_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_next_txn_id;
        
	/* varchar		hv_server_ref[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_server_ref;

        char            hv_status;
        char            hv_ar_ind;
        /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

        /* varchar         hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

        /* varchar         hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

 	/* varchar         hv_host_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_posting_date;

	/* varchar        	hv_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_tm_date;

        /* varchar        	hv_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_tm_time;

        /* varchar        	hv_local_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_local_tm_date;

        /* varchar        	hv_local_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_local_tm_time;
	
	/* varchar         hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

	double          hv_transaction_amount;
	/* varchar		hv_transaction_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_transaction_ccy;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



        short           ind_txn_id = -1;
        short           ind_org_txn_id = -1;
        short           ind_next_txn_id = -1;
	short		ind_server_ref = -1;
        short           ind_status = -1;
        short           ind_ar_ind = -1;
        short           ind_txn_code = -1;
        short           ind_process_type = -1;
        short           ind_process_code = -1;
 	short	        ind_host_posting_date = -1;
	short        	ind_tm_date = -1;
        short        	ind_tm_time = -1;
        short        	ind_local_tm_date = -1;
        short        	ind_local_tm_time = -1;
	short           ind_transmission_datetime = -1;
	short         	ind_transaction_amount = -1;
	short		ind_transaction_ccy = -1;
        short           ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddHeader: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddHeader:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
                hv_org_txn_id.len = strlen(csTmp);
                memcpy(hv_org_txn_id.arr,csTmp,hv_org_txn_id.len);
                ind_org_txn_id = 0;
DEBUGLOG(("AddHeader:org_txn_id = [%.*s]\n",hv_org_txn_id.len,hv_org_txn_id.arr));
        }

/* next txn_seq */
        if (GetField_CString(hRls,"next_txn_seq",&csTmp)) {
                hv_next_txn_id.len = strlen(csTmp);
                memcpy(hv_next_txn_id.arr,csTmp,hv_next_txn_id.len);
                ind_next_txn_id = 0;
DEBUGLOG(("AddHeader:next_txn_id = [%.*s]\n",hv_next_txn_id.len,hv_next_txn_id.arr));
        }
/* server_ref */
        if (GetField_CString(hRls,"server_ref",&csTmp)) {
                hv_server_ref.len = strlen(csTmp);
                memcpy(hv_server_ref.arr,csTmp,hv_server_ref.len);
                ind_server_ref = 0;
DEBUGLOG(("AddHeader:server_ref = [%.*s]\n",hv_server_ref.len,hv_server_ref.arr));
        }

/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddHeader:status = [%c]\n",hv_status));
        }

/* ar ind */ 
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
                hv_ar_ind = cTmp;
                ind_ar_ind = 0;
DEBUGLOG(("AddHeader:ar_ind = [%c]\n",hv_ar_ind));
        }

/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("AddHeader:txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
                hv_process_type.len = strlen(csTmp);
                memcpy(hv_process_type.arr,csTmp,hv_process_type.len);
                ind_process_type = 0;
DEBUGLOG(("AddHeader:process_type = [%.*s]\n",hv_process_type.len,hv_process_type.arr));
        }

/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
                hv_process_code.len = strlen(csTmp);
                memcpy(hv_process_code.arr,csTmp,hv_process_code.len);
                ind_process_code = 0;
DEBUGLOG(("AddHeader:process_code = [%.*s]\n",hv_process_code.len,hv_process_code.arr));
        }

/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
                hv_host_posting_date.len = strlen(csTmp);
                memcpy(hv_host_posting_date.arr,csTmp,hv_host_posting_date.len);
                ind_host_posting_date = 0;
DEBUGLOG(("AddHeader:host_posting_date = [%.*s]\n",hv_host_posting_date.len,hv_host_posting_date.arr));
        }

/* tm date */
        if (GetField_CString(hRls,"tm_date",&csTmp)) {
                hv_tm_date.len = strlen(csTmp);
                memcpy(hv_tm_date.arr,csTmp,hv_tm_date.len);
                ind_tm_date = 0;
DEBUGLOG(("AddHeader:tm_date = [%.*s]\n",hv_tm_date.len,hv_tm_date.arr));
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
                hv_tm_time.len = strlen(csTmp);
                memcpy(hv_tm_time.arr,csTmp,hv_tm_time.len);
                ind_tm_time = 0;
DEBUGLOG(("AddHeader:tm_time = [%.*s]\n",hv_tm_time.len,hv_tm_time.arr));
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
                hv_local_tm_date.len = strlen(csTmp);
                memcpy(hv_local_tm_date.arr,csTmp,hv_local_tm_date.len);
                ind_local_tm_date = 0;
DEBUGLOG(("AddHeader:local_tm_date = [%.*s]\n",hv_local_tm_date.len,hv_local_tm_date.arr));
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
                hv_local_tm_time.len = strlen(csTmp);
                memcpy(hv_local_tm_time.arr,csTmp,hv_local_tm_time.len);
                ind_local_tm_time = 0;
DEBUGLOG(("AddHeader:local_tm_time = [%.*s]\n",hv_local_tm_time.len,hv_local_tm_time.arr));
        }



/* transmission_datetime */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
                hv_transmission_datetime.len = strlen(csTmp);
                memcpy(hv_transmission_datetime.arr,csTmp,hv_transmission_datetime.len);
                ind_transmission_datetime = 0;
DEBUGLOG(("AddHeader:transmission_datetime = [%.*s]\n",hv_transmission_datetime.len,hv_transmission_datetime.arr));
        }


/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_transaction_amount = dTmp;
                ind_transaction_amount = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_transaction_amount));
        }
/* transaction ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_transaction_ccy.len = strlen(csTmp);
                memcpy(hv_transaction_ccy.arr,csTmp,hv_transaction_ccy.len);
                ind_transaction_ccy = 0;
DEBUGLOG(("AddHeader:transaction_ccy = [%.*s]\n",hv_transaction_ccy.len,hv_transaction_ccy.arr));
        }
/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddHeader:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mmc_txn_header_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_org_txn_id:ind_org_txn_id,
                                                :hv_next_txn_id:ind_next_txn_id,
						:hv_server_ref:ind_server_ref,
                                                :hv_status:ind_status,
                                                :hv_ar_ind:ind_ar_ind,
                                                :hv_txn_code:ind_txn_code,
                                                :hv_process_type:ind_process_type,
                                                :hv_process_code:ind_process_code,
                                                :hv_host_posting_date:ind_host_posting_date,
                                                :hv_tm_date:ind_tm_date,
                                                :hv_tm_time:ind_tm_time,
                                                :hv_local_tm_date:ind_local_tm_date,
                                                :hv_local_tm_time:ind_local_tm_time,
                                                :hv_transmission_datetime:ind_transmission_datetime,
                                                :hv_transaction_amount:ind_transaction_amount,
                                                :hv_transaction_ccy:ind_transaction_ccy,
                                                :hv_add_user:ind_add_user,
                                                :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mmc_txn_header_insert (\
 :hv_txn_id:ind_txn_id , :hv_org_txn_id:ind_org_txn_id , :hv_next_txn_id:ind_\
next_txn_id , :hv_server_ref:ind_server_ref , :hv_status:ind_status , :hv_ar_\
ind:ind_ar_ind , :hv_txn_code:ind_txn_code , :hv_process_type:ind_process_typ\
e , :hv_process_code:ind_process_code , :hv_host_posting_date:ind_host_postin\
g_date , :hv_tm_date:ind_tm_date , :hv_tm_time:ind_tm_time , :hv_local_tm_dat\
e:ind_local_tm_date , :hv_local_tm_time:ind_local_tm_time , :hv_transmission_\
datetime:ind_transmission_datetime , :hv_transaction_amount:ind_transaction_a\
mount , :hv_transaction_ccy:ind_transaction_ccy , :hv_add_user:ind_add_user ,\
 :hv_add_user:ind_add_user ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_org_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_org_txn_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_next_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )18;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_next_txn_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_server_ref;
        sqlstm.sqhstl[4] = (unsigned long )18;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_server_ref;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[5] = (unsigned long )1;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_status;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_ar_ind;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_ar_ind;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[7] = (unsigned long )5;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_txn_code;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_process_type;
        sqlstm.sqhstl[8] = (unsigned long )6;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_process_type;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_process_code;
        sqlstm.sqhstl[9] = (unsigned long )8;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_process_code;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_host_posting_date;
        sqlstm.sqhstl[10] = (unsigned long )10;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_host_posting_date;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_tm_date;
        sqlstm.sqhstl[11] = (unsigned long )10;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_tm_date;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_tm_time;
        sqlstm.sqhstl[12] = (unsigned long )8;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_tm_time;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_local_tm_date;
        sqlstm.sqhstl[13] = (unsigned long )10;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_local_tm_date;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_local_tm_time;
        sqlstm.sqhstl[14] = (unsigned long )8;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_local_tm_time;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_transmission_datetime;
        sqlstm.sqhstl[15] = (unsigned long )16;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_transmission_datetime;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_transaction_amount;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_transaction_amount;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_transaction_ccy;
        sqlstm.sqhstl[17] = (unsigned long )5;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_transaction_ccy;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[18] = (unsigned long )22;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_add_user;
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
        if (sqlca.sqlcode < 0) goto add_header_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("AddHeader:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmcTransaction_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmcTransaction_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_header_error:
DEBUGLOG(("add_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmcTransaction_AddHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateHeader(const hash_t *hRls)
{

        char*   csTmp;
        char    cTmp;
        double  dTmp;
        int     iTmp;
        char*   csBuf;
        char*   csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update mmc_txn_header set mch_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateHeader:txn_id = [%s]\n",csTxnId));

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateHeader:org_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mch_org_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* next txn_seq */
        if (GetField_CString(hRls,"mch_next_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateHeader:org_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mch_org_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* server txn_seq */
        if (GetField_CString(hRls,"server_ref",&csTmp)) {
DEBUGLOG(("UpdateHeader:server_ref = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mch_server_ref = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Status */
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("UpdateHeader:status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mch_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ar ind */
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateHeader:ar_ind = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mch_ar_ind = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("UpdateHeader:internal_code = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mch_internal_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("UpdateHeader:response_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mch_response_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateHeader:txn_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mch_transaction_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateHeader:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mch_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char *)hv_dynstmt.arr, " WHERE mch_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )96;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto update_header_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )115;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_header_error;
}



        FREE_ME(csBuf);


DEBUGLOG(("UpdateHeader Normal Exit\n"));
        return PD_OK;

update_header_error:
DEBUGLOG(("update_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("Transaction_UpdateHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int AddDetail(const hash_t *hRls)
{
        char        	*csTmp;
	char		cTmp;
	double		dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short   	hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        
	char		hv_src_party_type;
	char		hv_dst_party_type;
        /* varchar         hv_src_party_id[PD_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_src_party_id;
        
        /* varchar         hv_dst_party_id[PD_PARTY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_dst_party_id;
        
        /* varchar         hv_src_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_src_txn_ccy;
        
	/* varchar		hv_dst_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_dst_txn_ccy;

	double		hv_src_txn_amt;
	double		hv_dst_txn_amt;
	double		hv_src_processing_cost;
	double		hv_dst_processing_cost;
	double		hv_exchange_rate;
	double		hv_bank_charge;
	double		hv_bank_charge_refund;
	double		hv_adjustment;
        /* varchar         hv_filing_number[PD_VERSION_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_filing_number;
        
	/* varchar         hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



        short           ind_txn_id = -1;
	short		ind_src_party_id = -1;
	short		ind_dst_party_id = -1;
	short		ind_src_party_type = -1;
	short		ind_dst_party_type = -1;
	short		ind_src_txn_ccy = -1;
	short		ind_dst_txn_ccy = -1;
	short		ind_src_txn_amt = -1;
	short		ind_dst_txn_amt = -1;
	short		ind_src_processing_cost = -1;
	short		ind_dst_processing_cost = -1;
	short		ind_exchange_rate = -1;
	short		ind_bank_charge = -1;
	short		ind_bank_charge_refund = -1;
	short		ind_adjustment = -1;
	short		ind_filing_number = -1;
	short           ind_transmission_datetime = -1;
        short           ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddDetail:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }
/* src_party_type */
        if (GetField_Char(hRls,"src_party_type",&cTmp)) {
                hv_src_party_type = cTmp;
                ind_src_party_type = 0;
DEBUGLOG(("AddDetail:src_party_type = [%c]\n",hv_src_party_type));
        }

/* dst_party_type */
        if (GetField_Char(hRls,"dst_party_type",&cTmp)) {
                hv_dst_party_type= cTmp;
                ind_dst_party_type = 0;
DEBUGLOG(("AddDetail:dst_party_type = [%c]\n",hv_dst_party_type));
        }

/* src_party_id */
        if (GetField_CString(hRls,"src_party_id",&csTmp)) {
                hv_src_party_id.len = strlen(csTmp);
                memcpy(hv_src_party_id.arr,csTmp,hv_src_party_id.len);
                ind_src_party_id = 0;
DEBUGLOG(("AddDetail:src_party_id = [%.*s][%d]\n",hv_src_party_id.len,hv_src_party_id.arr,hv_src_party_id.len));
        }

/* dst_party_id */
        if (GetField_CString(hRls,"dst_party_id",&csTmp)) {
                hv_dst_party_id.len = strlen(csTmp);
                memcpy(hv_dst_party_id.arr,csTmp,hv_dst_party_id.len);
                ind_dst_party_id = 0;
DEBUGLOG(("AddDetail:dst_party_id = [%.*s][%d]\n",hv_dst_party_id.len,hv_dst_party_id.arr,hv_dst_party_id.len));
        }

/* src_txn_ccy */
        if (GetField_CString(hRls,"src_txn_ccy",&csTmp)) {
                hv_src_txn_ccy.len = strlen(csTmp);
                memcpy(hv_src_txn_ccy.arr,csTmp,hv_src_txn_ccy.len);
                ind_src_txn_ccy = 0;
DEBUGLOG(("AddDetail:src_txn_ccy = [%.*s][%d]\n",hv_src_txn_ccy.len,hv_src_txn_ccy.arr,hv_src_txn_ccy.len));
        }
/* src_txn_amt */
        if (GetField_Double(hRls,"src_txn_amt",&dTmp)) {
                hv_src_txn_amt = dTmp;
                ind_src_txn_amt = 0;
DEBUGLOG(("AddDetail:src_txn_amt = [%lf]\n",hv_src_txn_amt));
        }
/* dst_txn_ccy */
        if (GetField_CString(hRls,"dst_txn_ccy",&csTmp)) {
                hv_dst_txn_ccy.len = strlen(csTmp);
                memcpy(hv_dst_txn_ccy.arr,csTmp,hv_dst_txn_ccy.len);
                ind_dst_txn_ccy = 0;
DEBUGLOG(("AddDetail:dst_txn_ccy = [%.*s][%d]\n",hv_dst_txn_ccy.len,hv_dst_txn_ccy.arr,hv_dst_txn_ccy.len));
        }
/* dst_txn_amt */
        if (GetField_Double(hRls,"dst_txn_amt",&dTmp)) {
                hv_dst_txn_amt = dTmp;
                ind_dst_txn_amt = 0;
DEBUGLOG(("AddDetail:dst_txn_amt = [%lf]\n",hv_dst_txn_amt));
        }
/* adjustment */
        if (GetField_Double(hRls,"adjustment",&dTmp)) {
                hv_adjustment= dTmp;
                ind_adjustment= 0;
DEBUGLOG(("AddDetail:adjustment = [%lf]\n", hv_adjustment));
        }
/* exchange_rate */
        if (GetField_Double(hRls,"exchange_rate",&dTmp)) {
                hv_exchange_rate= dTmp;
                ind_exchange_rate= 0;
DEBUGLOG(("AddDetail:exchange_rate = [%lf]\n",hv_exchange_rate));
        }
/* src_processing_cost */
        if (GetField_Double(hRls,"src_processing_cost",&dTmp)) {
                hv_src_processing_cost= dTmp;
                ind_src_processing_cost= 0;
DEBUGLOG(("AddDetail:src_processing_cost = [%lf]\n",hv_src_processing_cost));
        }
/* dst_processing_cost */
        if (GetField_Double(hRls,"dst_processing_cost",&dTmp)) {
                hv_dst_processing_cost= dTmp;
                ind_dst_processing_cost= 0;
DEBUGLOG(("AddDetail:dst_processing_cost = [%lf]\n",hv_dst_processing_cost));
        }
/* bank_charge */
        if (GetField_Double(hRls,"bank_charge",&dTmp)) {
                hv_bank_charge= dTmp;
                ind_bank_charge= 0;
DEBUGLOG(("AddDetail:bank_charge = [%lf]\n",hv_bank_charge));
        }
/* bank_charge_refund */
        if (GetField_Double(hRls,"bank_charge_refund",&dTmp)) {
                hv_bank_charge_refund= dTmp;
                ind_bank_charge_refund= 0;
DEBUGLOG(("AddDetail:bank_charge_refund = [%lf]\n",hv_bank_charge_refund));
        }

/* transmission_datetime */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
                hv_transmission_datetime.len = strlen(csTmp);
                memcpy(hv_transmission_datetime.arr,csTmp,hv_transmission_datetime.len);
                ind_transmission_datetime = 0;
DEBUGLOG(("AddDetail:transmission_datetime = [%.*s]\n",hv_transmission_datetime.len,hv_transmission_datetime.arr));
        }

/* filing_number */
        if (GetField_CString(hRls,"filing_number",&csTmp)) {
                hv_filing_number.len = strlen(csTmp);
                memcpy(hv_filing_number.arr,csTmp,hv_filing_number.len);
                ind_filing_number = 0;
DEBUGLOG(("AddDetail:filing_number = [%.*s][%d]\n",hv_filing_number.len,hv_filing_number.arr,hv_filing_number.len));
        }
/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddDetail:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mmc_txn_detail_insert(
                                                :hv_txn_id:ind_txn_id,
						:hv_src_party_type:ind_src_party_type,
						:hv_src_party_id:ind_src_party_id,
						:hv_dst_party_type:ind_dst_party_type,
						:hv_dst_party_id:ind_dst_party_id,
                                                :hv_transmission_datetime:ind_transmission_datetime,
						:hv_src_txn_amt:ind_src_txn_amt,
						:hv_src_txn_ccy:ind_src_txn_ccy,
						:hv_dst_txn_amt:ind_dst_txn_amt,
						:hv_dst_txn_ccy:ind_dst_txn_ccy,
						:hv_adjustment:ind_adjustment,
						:hv_exchange_rate:ind_exchange_rate,
						:hv_src_processing_cost:ind_src_processing_cost,
						:hv_dst_processing_cost:ind_dst_processing_cost,
						:hv_bank_charge:ind_bank_charge,
						:hv_bank_charge_refund:ind_bank_charge_refund,
						:hv_filing_number:ind_filing_number,
                                                :hv_add_user:ind_add_user,
                                                :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mmc_txn_detail_insert (\
 :hv_txn_id:ind_txn_id , :hv_src_party_type:ind_src_party_type , :hv_src_part\
y_id:ind_src_party_id , :hv_dst_party_type:ind_dst_party_type , :hv_dst_party\
_id:ind_dst_party_id , :hv_transmission_datetime:ind_transmission_datetime , \
:hv_src_txn_amt:ind_src_txn_amt , :hv_src_txn_ccy:ind_src_txn_ccy , :hv_dst_t\
xn_amt:ind_dst_txn_amt , :hv_dst_txn_ccy:ind_dst_txn_ccy , :hv_adjustment:ind\
_adjustment , :hv_exchange_rate:ind_exchange_rate , :hv_src_processing_cost:i\
nd_src_processing_cost , :hv_dst_processing_cost:ind_dst_processing_cost , :h\
v_bank_charge:ind_bank_charge , :hv_bank_charge_refund:ind_bank_charge_refund\
 , :hv_filing_number:ind_filing_number , :hv_add_user:ind_add_user , :hv_add_\
user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )130;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_src_party_type;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_src_party_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_src_party_id;
        sqlstm.sqhstl[3] = (unsigned long )17;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_src_party_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_dst_party_type;
        sqlstm.sqhstl[4] = (unsigned long )1;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_dst_party_type;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_dst_party_id;
        sqlstm.sqhstl[5] = (unsigned long )17;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_dst_party_id;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_transmission_datetime;
        sqlstm.sqhstl[6] = (unsigned long )16;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_transmission_datetime;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_src_txn_amt;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_src_txn_amt;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_src_txn_ccy;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_src_txn_ccy;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_dst_txn_amt;
        sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_dst_txn_amt;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_dst_txn_ccy;
        sqlstm.sqhstl[10] = (unsigned long )5;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_dst_txn_ccy;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_adjustment;
        sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_adjustment;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_exchange_rate;
        sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_exchange_rate;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_src_processing_cost;
        sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_src_processing_cost;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_dst_processing_cost;
        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_dst_processing_cost;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_bank_charge;
        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_bank_charge;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_bank_charge_refund;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_bank_charge_refund;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_filing_number;
        sqlstm.sqhstl[17] = (unsigned long )4;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_filing_number;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[18] = (unsigned long )22;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_add_user;
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
        if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("AddDetail:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmcTransaction_AddDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmcTransaction_AddDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmcTransaction_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

