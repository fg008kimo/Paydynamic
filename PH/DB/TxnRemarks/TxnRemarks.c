
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "TxnRemarks.pc"
};


static unsigned int sqlctx = 682723;


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

 static char *sq0002 = 
"select tr_status , tr_ar_ind , tr_sub_status , tr_exec_seq , tr_remark , ma\
xseq_td , nvl ( greatest ( ( select max ( tr_exec_seq ) as seq from txn_remar\
ks where tr_status = 'R' and tr_txn_id = :b0 ) , maxseq_td ) , maxseq_td ) as\
 maxseq_sd from txn_remarks t1 , ( select max ( seq ) as maxseq_td from ( sel\
ect min ( tr_exec_seq ) as seq from txn_remarks where tr_status = 'C' and tr_\
ar_ind = 'A' and tr_sub_status = 117 and tr_txn_id = :b0 union select tr_exec\
_seq as seq from txn_remarks where tr_status = 'C' and tr_ar_ind = 'A' and tr\
_sub_status = 116 and tr_txn_id = :b0 union select tr_exec_seq as seq from tx\
n_remarks where tr_status = 'P' and tr_txn_id = :b0 ) ) t2 where tr_txn_id = \
:b0 and tr_exec_seq = :b5            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,241,0,6,119,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,
52,0,0,2,728,0,9,217,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,
91,0,0,2,0,0,13,219,0,0,7,0,0,1,0,2,1,0,0,2,1,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,3,
0,0,2,3,0,0,
134,0,0,2,0,0,15,275,0,0,0,0,0,1,0,
149,0,0,2,0,0,15,290,0,0,0,0,0,1,0,
164,0,0,3,167,0,6,350,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/06/24              Virginia Yun
Add "Get"					   2016/08/03		   Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnRemarks.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void TxnRemarks(char    cdebug)
{
        cDebug = cdebug;
}



int Add(const hash_t *hRls)
{
	char            *csTmp;
	char		cTmp;
	//double          dTmp;


	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	short           hv_return_value;

	/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

	/* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	char            hv_status;
	char            hv_ar_ind;
	/* varchar         hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

        /* varchar         hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

	/* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


	short           ind_txn_id = -1;
	short		ind_txn_code = -1;
	short		ind_status = -1;
	short		ind_ar_ind = -1;
	short		ind_sub_status = -1;
        short		ind_remark = -1;
	short           ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

/* txn_seq */
	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
	}

/* txn_code */
	if (GetField_CString(hRls,"txn_code",&csTmp)) {
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
		ind_txn_code = 0;
DEBUGLOG(("Add:txn_code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len));
	}

/* Status */
	if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
	}

/* ar ind */
	if (GetField_Char(hRls,"ar_ind",&cTmp)) {
		hv_ar_ind = cTmp;
		ind_ar_ind = 0;
DEBUGLOG(("Add:ar_ind = [%c]\n",hv_ar_ind));
	}

/* Sub Status */
	if (GetField_CString(hRls,"sub_status",&csTmp)) {
		hv_sub_status.len = strlen(csTmp);
		memcpy(hv_sub_status.arr,csTmp,hv_sub_status.len);
		ind_sub_status = 0;
DEBUGLOG(("Add:sub_status = [%.*s]\n",hv_sub_status.len,hv_sub_status.arr));
	}

/* remark */
        if (GetField_CString(hRls,"remark",&csTmp)) {
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr,csTmp,hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("Add:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

/* add user */
	if (GetField_CString(hRls,"add_user",&csTmp)) {
		hv_add_user.len = strlen(csTmp);
		memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
		ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s][%d]\n",hv_add_user.len,hv_add_user.arr,hv_add_user.len));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_txn_remarks_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_txn_code:ind_txn_code,
                                        :hv_status:ind_status,
                                        :hv_ar_ind:ind_ar_ind,
                                        :hv_sub_status:ind_sub_status,
					:hv_remark:ind_remark,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_remarks_insert ( :hv_txn_i\
d:ind_txn_id , :hv_txn_code:ind_txn_code , :hv_status:ind_status , :hv_ar_ind\
:ind_ar_ind , :hv_sub_status:ind_sub_status , :hv_remark:ind_remark , :hv_add\
_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_status;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_ar_ind;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_sub_status;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[6] = (unsigned long )257;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_remark;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_add_user;
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
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnRemarks_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnRemarks_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnElement_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}


int Get(const char* csTxnId, int iSeq, hash_t* hRls)
{
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		int		hv_seq;

		char		v_status;
		char		v_ar_ind;
		/* varchar		v_sub_status[PD_SUB_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		int		v_exec_seq;
		/* varchar		v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		int		v_maxseq_td;
		int		v_maxseq_sd;

		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_sub_status = -1;
		short		ind_exec_seq = -1;
		short		ind_remark = -1;
		short		ind_maxseq_td = -1;
		short		ind_maxseq_sd = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("Get txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_seq = iSeq;
DEBUGLOG(("Get seq = [%d]\n",hv_seq));

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		select	tr_status,
			tr_ar_ind,
			tr_sub_status, 
			tr_exec_seq,
			tr_remark,
			maxseq_td,
			nvl(greatest((select max(tr_exec_seq) as seq
				      from   txn_remarks
				      where  tr_status = 'R'
                                      and    tr_txn_id = :hv_txn_id),maxseq_td),maxseq_td) as maxseq_sd
		from	txn_remarks t1,
			(select max(seq) as maxseq_td from (select min(tr_exec_seq) as seq from txn_remarks where tr_status='C' and tr_ar_ind='A' and tr_sub_status=117 and tr_txn_id = :hv_txn_id
							    union
							    select tr_exec_seq as seq from txn_remarks where tr_status='C' and tr_ar_ind='A' and tr_sub_status=116 and tr_txn_id = :hv_txn_id
							    union
							    select tr_exec_seq as seq from txn_remarks where tr_status='P' and tr_txn_id = :hv_txn_id)
							   ) t2
		where	tr_txn_id = :hv_txn_id
		and	tr_exec_seq = :hv_seq; */ 


	/* EXEC SQL OPEN c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )52;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )18;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_seq;
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
 if (sqlca.sqlcode < 0) goto get_error;
}


	do{
		/* EXEC SQL FETCH c_cursor_get
		INTO
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_sub_status:ind_sub_status,
			:v_exec_seq:ind_exec_seq,
			:v_remark:ind_remark,
			:v_maxseq_td:ind_maxseq_td,
			:v_maxseq_sd:ind_maxseq_sd; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )91;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[0] = (unsigned long )1;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_status;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[1] = (unsigned long )1;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_ar_ind;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_sub_status;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_exec_seq;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_exec_seq;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_remark;
  sqlstm.sqhstl[4] = (unsigned long )258;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_remark;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_maxseq_td;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_maxseq_td;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_maxseq_sd;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_maxseq_sd;
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
  if (sqlca.sqlcode < 0) goto get_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		if (ind_status >= 0) {
			PutField_Char(hRls,"status",v_status);
DEBUGLOG(("Get status = [%c]\n",v_status));
		}

		if (ind_ar_ind >= 0) {
			PutField_Char(hRls,"ar_ind",v_ar_ind);
DEBUGLOG(("Get ar_ind = [%c]\n",v_ar_ind));
		}

		if (ind_sub_status >= 0) {
			v_sub_status.arr[v_sub_status.len] ='\0';
			PutField_CString(hRls,"sub_status",(const char*)v_sub_status.arr);
DEBUGLOG(("Get sub_status = [%s]\n",v_sub_status.arr));  
		}

		if (ind_exec_seq >= 0) {
			PutField_Int(hRls,"exec_seq",v_exec_seq);
DEBUGLOG(("Get exec_seq = [%d]\n",v_exec_seq));
		}

		if (ind_remark >= 0) {
			v_remark.arr[v_remark.len] ='\0';
			PutField_CString(hRls,"remark",(const char*)v_remark.arr);
DEBUGLOG(("Get remark = [%s]\n",v_remark.arr));  
		}

		if (ind_maxseq_td >= 0) {
			PutField_Int(hRls,"maxseq_td",v_maxseq_td);
DEBUGLOG(("Get maxseq_td = [%d]\n",v_maxseq_td));
		}

		if (ind_maxseq_sd >= 0) {
			PutField_Int(hRls,"maxseq_sd",v_maxseq_sd);
DEBUGLOG(("Get maxseq_sd = [%d]\n",v_maxseq_sd));
		}

	}while(PD_TRUE);


	/* EXEC SQL CLOSE c_cursor_get; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )134;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("Get Normal Exit\n")); 
		return  PD_OK;
	}
	else {  
DEBUGLOG(("Get Normal Exit, Not Found\n"));
		return PD_ERR;
	}

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )149;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdateRemark(hash_t* hRls)
{
	char *csTmp;
	int iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updateremark_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		int	hv_exec_seq;
		/* varchar	hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short	ind_txn_id = -1;
		short	ind_exec_seq = -1;
		short	ind_remark = -1;
		short	ind_update_user = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateRemark: Begin\n"));

//txn_id
	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("UpdateRemark txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

//exec_seq
	if (GetField_Int(hRls,"exec_seq",&iTmp)) {
		hv_exec_seq = iTmp;
		ind_exec_seq = 0;
DEBUGLOG(("UpdateRemark exec_seq = [%d]\n",hv_exec_seq));
	}

//remark
	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char*)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("UpdateRemark remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
	}

//update_user
	if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateRemark update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_txn_remarks_update(
								:hv_txn_id:ind_txn_id,
								:hv_exec_seq:ind_exec_seq,
								:hv_remark:ind_remark,
								:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_remarks_update ( :hv_txn_i\
d:ind_txn_id , :hv_exec_seq:ind_exec_seq , :hv_remark:ind_remark , :hv_update\
_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )164;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_exec_seq;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_exec_seq;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[3] = (unsigned long )257;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_remark;
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
 if (sqlca.sqlcode < 0) goto updateremark_err;
}



DEBUGLOG(("UpdateRemark Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateRemark Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("UpdateRemark: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_OTHER_ERR TxnAbort\n"));	
                return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updateremark_err:
DEBUGLOG(("updateremark_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
