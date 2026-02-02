
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "OLBulkDetail.pc"
};


static unsigned int sqlctx = 2513451;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
"SELECT OBD_INT_BANK_CODE , OBD_BANK_ACCT_NUM , OBD_BANK_ACCT_ORG_STATUS , O\
BD_BANK_ACCT_NEW_STATUS , OBD_BAID , OBD_BAID_ORG_STATUS , OBD_BAID_NEW_STATU\
S , OBD_ADJ_TXN_CODE , OBD_ADJ_RPT_DATE , OBD_ADJ_REMARK , OBD_RET_CODE FROM \
OL_BULK_DETAIL WHERE OBD_BATCH_ID = :b0 AND OBD_SEQ = :b1            ";

 static char *sq0002 = 
"SELECT OBD_SEQ , OBD_INT_BANK_CODE , OBD_BANK_ACCT_NUM , OBD_BANK_ACCT_ORG_\
STATUS , OBD_BANK_ACCT_NEW_STATUS , OBD_BAID , OBD_BAID_ORG_STATUS , OBD_BAID\
_NEW_STATUS , OBD_ADJ_TXN_CODE , OBD_ADJ_RPT_DATE , OBD_ADJ_REMARK , OBD_RET_\
CODE , OBD_COUNTRY_ID , OBD_CURRENCY_ID , OBD_TXN_ID , OBD_ORG_HOLD_TYPE , OB\
D_HOLD_TYPE FROM OL_BULK_DETAIL WHERE OBD_BATCH_ID = :b0 ORDER BY OBD_SEQ    \
        ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,298,0,9,95,0,2049,2,2,0,1,0,1,68,0,0,1,3,0,0,
28,0,0,1,0,0,13,97,0,0,11,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
87,0,0,1,0,0,15,195,0,0,0,0,0,1,0,
102,0,0,1,0,0,15,212,0,0,0,0,0,1,0,
117,0,0,2,391,0,9,293,0,2049,1,1,0,1,0,1,68,0,0,
136,0,0,2,0,0,13,295,0,0,17,0,0,1,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,1,0,0,2,1,0,0,
219,0,0,2,0,0,15,443,0,0,0,0,0,1,0,
234,0,0,2,0,0,15,460,0,0,0,0,0,1,0,
249,0,0,3,0,0,17,580,0,0,1,1,0,1,0,1,9,0,0,
268,0,0,3,0,0,21,581,0,0,0,0,0,1,0,
283,0,0,3,0,0,17,652,0,0,1,1,0,1,0,1,9,0,0,
302,0,0,3,0,0,21,653,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2019/06/05              [ING]
Add country,currency in GetByBatchId		   2019/07/24		   [MIC]
Add txn_id, org_hold_type and hold_type 
    in GetByBatchId                                2020/05/05              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"
#include "OLBulkDetail.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void OLBulkDetail(char cdebug)
{
	cDebug = cdebug;
}

int Get(const char* csBatchId, 
	int iSeq, 
	hash_t *hRec)
{
	int     iRet = NOT_FOUND;
	int     iCnt=0;

        /* EXEC SQL WHENEVER SQLERROR GOTO get_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;
                int             hv_seq;

		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_bank_acct_org_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_org_status;

		/* varchar         v_bank_acct_new_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_new_status;

		/* varchar         v_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar         v_baid_org_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_org_status;

		/* varchar         v_baid_new_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_new_status;

		/* varchar         v_adj_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_adj_txn_code;

		/* varchar         v_adj_rpt_date[PD_YYYYMMDD_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_adj_rpt_date;

		/* varchar         v_adj_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_adj_remark;

                int             v_ret_code;

		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_bank_acct_org_status = -1;
		short		ind_bank_acct_new_status = -1;
		short		ind_baid = -1;
		short		ind_baid_org_status = -1;
		short		ind_baid_new_status = -1;
		short		ind_adj_txn_code = -1;
		short		ind_adj_rpt_date = -1;
		short		ind_adj_remark = -1;
                short           ind_ret_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


     	hv_batch_id = (unsigned long)ctol((const unsigned char*)csBatchId,strlen(csBatchId));
DEBUGLOG(("Get batch_id = [%ld]\n",hv_batch_id));

	hv_seq = iSeq;
DEBUGLOG(("Get seq = [%d]\n",hv_seq));

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		SELECT  OBD_INT_BANK_CODE,
			OBD_BANK_ACCT_NUM,
			OBD_BANK_ACCT_ORG_STATUS,
			OBD_BANK_ACCT_NEW_STATUS,
			OBD_BAID,
			OBD_BAID_ORG_STATUS,
			OBD_BAID_NEW_STATUS,
			OBD_ADJ_TXN_CODE,
			OBD_ADJ_RPT_DATE,
			OBD_ADJ_REMARK,
                        OBD_RET_CODE
                FROM    OL_BULK_DETAIL
                WHERE   OBD_BATCH_ID = :hv_batch_id
		AND	OBD_SEQ = :hv_seq; */ 


        /* EXEC SQL OPEN  c_cursor_get; */ 

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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto get_error;
}


	do{
                /* EXEC SQL FETCH c_cursor_get
                INTO
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_bank_acct_org_status:ind_bank_acct_org_status,
			:v_bank_acct_new_status:ind_bank_acct_new_status,
			:v_baid:ind_baid,
			:v_baid_org_status:ind_baid_org_status,
			:v_baid_new_status:ind_baid_new_status,
			:v_adj_txn_code:ind_adj_txn_code,
			:v_adj_rpt_date:ind_adj_rpt_date,
			:v_adj_remark:ind_adj_remark,
                        :v_ret_code:ind_ret_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 11;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_org_status;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_acct_org_status;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_new_status;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_acct_new_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_baid;
                sqlstm.sqhstl[4] = (unsigned long )23;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_baid;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_baid_org_status;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_baid_org_status;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_baid_new_status;
                sqlstm.sqhstl[6] = (unsigned long )5;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_baid_new_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_adj_txn_code;
                sqlstm.sqhstl[7] = (unsigned long )6;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_adj_txn_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_adj_rpt_date;
                sqlstm.sqhstl[8] = (unsigned long )11;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_adj_rpt_date;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_adj_remark;
                sqlstm.sqhstl[9] = (unsigned long )258;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_adj_remark;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_ret_code;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_ret_code;
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
                if (sqlca.sqlcode < 0) goto get_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* int_bank_code */
		if(ind_int_bank_code>=0){
                        v_int_bank_code.arr[v_int_bank_code.len]='\0';
                        PutField_CString(hRec,"int_bank_code",(const char*)v_int_bank_code.arr);
DEBUGLOG(("Get int_bank_code = [%s]\n",v_int_bank_code.arr));
                }	

/* bank_acct_num */
		if(ind_bank_acct_num>=0){
                        v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                        PutField_CString(hRec,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG(("Get bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                }
		
/* bank_acct_org_status */
		if(ind_bank_acct_org_status>=0){
                        v_bank_acct_org_status.arr[v_bank_acct_org_status.len]='\0';
                        PutField_CString(hRec,"bank_acct_org_status",(const char*)v_bank_acct_org_status.arr);
DEBUGLOG(("Get bank_acct_org_status = [%s]\n",v_bank_acct_org_status.arr));
                }

/*bank_acct_new_status */
		if(ind_bank_acct_new_status>=0){
                        v_bank_acct_new_status.arr[v_bank_acct_new_status.len]='\0';
                        PutField_CString(hRec,"bank_acct_new_status",(const char*)v_bank_acct_new_status.arr);
DEBUGLOG(("Get bank_acct_new_status = [%s]\n",v_bank_acct_new_status.arr));
                }

/* baid */
		if(ind_baid>=0){
                        v_baid.arr[v_baid.len]='\0';
                        PutField_CString(hRec,"baid",(const char*)v_baid.arr);
DEBUGLOG(("Get baid = [%s]\n",v_baid.arr));
                }

/* baid_org_status*/
		if(ind_baid_org_status>=0){
                        v_baid_org_status.arr[v_baid_org_status.len]='\0';
                        PutField_CString(hRec,"baid_org_status",(const char*)v_baid_org_status.arr);
DEBUGLOG(("Get baid_org_status = [%s]\n",v_baid_org_status.arr));
                }

/* baid_new_status */
		if(ind_baid_new_status>=0){
                        v_baid_new_status.arr[v_baid_new_status.len]='\0';
                        PutField_CString(hRec,"baid_new_status",(const char*)v_baid_new_status.arr);
DEBUGLOG(("Get baid_new_status = [%s]\n",v_baid_new_status.arr));
                }

/* adj_txn_code */
		if(ind_adj_txn_code>=0){
                        v_adj_txn_code.arr[v_adj_txn_code.len]='\0';
                        PutField_CString(hRec,"adj_txn_code",(const char*)v_adj_txn_code.arr);
DEBUGLOG(("Get adj_txn_code = [%s]\n",v_adj_txn_code.arr));
                }

/* adj_rpt_date */
		if(ind_adj_rpt_date>=0){
                        v_adj_rpt_date.arr[v_adj_rpt_date.len]='\0';
                        PutField_CString(hRec,"adj_rpt_date",(const char*)v_adj_rpt_date.arr);
DEBUGLOG(("Get adj_rpt_date = [%s]\n",v_adj_rpt_date.arr));
                }

/* adj_remark */
		if(ind_adj_remark>=0){
                        v_adj_remark.arr[v_adj_remark.len]='\0';
                        PutField_CString(hRec,"adj_remark",(const char*)v_adj_remark.arr);
DEBUGLOG(("Get adj_remark = [%s]\n",v_adj_remark.arr));
                }

/* ret_code */
                if(ind_ret_code>=0){
                        PutField_Int(hRec,"ret_code",v_ret_code);
DEBUGLOG(("Get ret_code= [%d]\n",v_ret_code));
                }

                iCnt++;

	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_get; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )87;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto get_error;
}



	if (iCnt > 0) {
DEBUGLOG(("Get Found\n"));
                iRet = FOUND;
        } else {
DEBUGLOG(("Get Not Found\n"));
        }

DEBUGLOG(("Get Normal Exit [%d]\n", iRet));
        return  iRet;

get_error:
DEBUGLOG(("get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBulkDetail_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_get; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )102;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetByBatchId(const char* csBatchId, 
		 recordset_t* myRec)
{
	int     iRet = NOT_FOUND;
	int     iCnt=0;

	hash_t 	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbybatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_batch_id;

                int             v_seq;
		/* varchar         v_int_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_int_bank_code;

		/* varchar         v_bank_acct_num[PD_BANK_ACCT_NUM_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar         v_bank_acct_org_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_org_status;

		/* varchar         v_bank_acct_new_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bank_acct_new_status;

		/* varchar         v_baid[PD_BAID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar         v_baid_org_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_org_status;

		/* varchar         v_baid_new_status[PD_ACCOUNT_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_baid_new_status;

		/* varchar         v_adj_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_adj_txn_code;

		/* varchar         v_adj_rpt_date[PD_YYYYMMDD_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_adj_rpt_date;

		/* varchar         v_adj_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_adj_remark;

		/* varchar		v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

		/* varchar		v_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

                int             v_ret_code;
		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		char		v_org_hold_type;
		char		v_hold_type;

                short           ind_seq = -1;
		short		ind_int_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_bank_acct_org_status = -1;
		short		ind_bank_acct_new_status = -1;
		short		ind_baid = -1;
		short		ind_baid_org_status = -1;
		short		ind_baid_new_status = -1;
		short		ind_adj_txn_code = -1;
		short		ind_adj_rpt_date = -1;
		short		ind_adj_remark = -1;
                short           ind_ret_code = -1;
		short		ind_country = -1;
		short		ind_currency = -1;
		short		ind_txn_id = -1;
		short		ind_org_hold_type = -1;
		short		ind_hold_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


     	hv_batch_id = (unsigned long)ctol((const unsigned char*)csBatchId,strlen(csBatchId));
DEBUGLOG(("GetByBatchId batch_id = [%ld]\n",hv_batch_id));

	/* EXEC SQL DECLARE c_cursor_getbybatchid CURSOR FOR
		SELECT  OBD_SEQ,
			OBD_INT_BANK_CODE,
                        OBD_BANK_ACCT_NUM,
                        OBD_BANK_ACCT_ORG_STATUS,
                        OBD_BANK_ACCT_NEW_STATUS,
                        OBD_BAID,
                        OBD_BAID_ORG_STATUS,
                        OBD_BAID_NEW_STATUS,
                        OBD_ADJ_TXN_CODE,
                        OBD_ADJ_RPT_DATE,
                        OBD_ADJ_REMARK,
                        OBD_RET_CODE,
			OBD_COUNTRY_ID,
			OBD_CURRENCY_ID,
			OBD_TXN_ID,
			OBD_ORG_HOLD_TYPE,
			OBD_HOLD_TYPE
                FROM    OL_BULK_DETAIL
                WHERE   OBD_BATCH_ID = :hv_batch_id
		ORDER BY OBD_SEQ; */ 


        /* EXEC SQL OPEN  c_cursor_getbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 11;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )117;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
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
        if (sqlca.sqlcode < 0) goto getbybatchid_error;
}


	do{
                /* EXEC SQL FETCH c_cursor_getbybatchid
                INTO
                        :v_seq:ind_seq,
			:v_int_bank_code:ind_int_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_bank_acct_org_status:ind_bank_acct_org_status,
			:v_bank_acct_new_status:ind_bank_acct_new_status,
			:v_baid:ind_baid,
			:v_baid_org_status:ind_baid_org_status,
			:v_baid_new_status:ind_baid_new_status,
			:v_adj_txn_code:ind_adj_txn_code,
			:v_adj_rpt_date:ind_adj_rpt_date,
			:v_adj_remark:ind_adj_remark,
			:v_ret_code:ind_ret_code,
			:v_country:ind_country,
			:v_currency:ind_currency,
			:v_txn_id:ind_txn_id,
			:v_org_hold_type:ind_org_hold_type,
			:v_hold_type:ind_hold_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 17;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )136;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_int_bank_code;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_int_bank_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_acct_org_status;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_acct_org_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_acct_new_status;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_acct_new_status;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_baid;
                sqlstm.sqhstl[5] = (unsigned long )23;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_baid;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_baid_org_status;
                sqlstm.sqhstl[6] = (unsigned long )5;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_baid_org_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_baid_new_status;
                sqlstm.sqhstl[7] = (unsigned long )5;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_baid_new_status;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_adj_txn_code;
                sqlstm.sqhstl[8] = (unsigned long )6;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_adj_txn_code;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_adj_rpt_date;
                sqlstm.sqhstl[9] = (unsigned long )11;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_adj_rpt_date;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_adj_remark;
                sqlstm.sqhstl[10] = (unsigned long )258;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_adj_remark;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_ret_code;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_ret_code;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[12] = (unsigned long )5;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_country;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_currency;
                sqlstm.sqhstl[13] = (unsigned long )6;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_currency;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[14] = (unsigned long )19;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_txn_id;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_org_hold_type;
                sqlstm.sqhstl[15] = (unsigned long )1;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_org_hold_type;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_hold_type;
                sqlstm.sqhstl[16] = (unsigned long )1;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_hold_type;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getbybatchid_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* seq */
                if(ind_seq>=0){
                        PutField_Int(myHash,"seq",v_seq);
DEBUGLOG(("GetByBatchId seq= [%d]\n",v_seq));
                }

/* int_bank_code */
		if(ind_int_bank_code>=0){
                        v_int_bank_code.arr[v_int_bank_code.len]='\0';
                        PutField_CString(myHash,"int_bank_code",(const char*)v_int_bank_code.arr);
DEBUGLOG(("GetByBatchId int_bank_code = [%s]\n",v_int_bank_code.arr));
                }	

/* bank_acct_num */
		if(ind_bank_acct_num>=0){
                        v_bank_acct_num.arr[v_bank_acct_num.len]='\0';
                        PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetByBatchId bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                }
		
/* bank_acct_org_status */
		if(ind_bank_acct_org_status>=0){
                        v_bank_acct_org_status.arr[v_bank_acct_org_status.len]='\0';
                        PutField_CString(myHash,"bank_acct_org_status",(const char*)v_bank_acct_org_status.arr);
DEBUGLOG(("GetByBatchId bank_acct_org_status = [%s]\n",v_bank_acct_org_status.arr));
                }

/*bank_acct_new_status */
		if(ind_bank_acct_new_status>=0){
                        v_bank_acct_new_status.arr[v_bank_acct_new_status.len]='\0';
                        PutField_CString(myHash,"bank_acct_new_status",(const char*)v_bank_acct_new_status.arr);
DEBUGLOG(("GetByBatchId bank_acct_new_status = [%s]\n",v_bank_acct_new_status.arr));
                }

/* baid */
		if(ind_baid>=0){
                        v_baid.arr[v_baid.len]='\0';
                        PutField_CString(myHash,"baid",(const char*)v_baid.arr);
DEBUGLOG(("GetByBatchId baid = [%s]\n",v_baid.arr));
                }

/* baid_org_status*/
		if(ind_baid_org_status>=0){
                        v_baid_org_status.arr[v_baid_org_status.len]='\0';
                        PutField_CString(myHash,"baid_org_status",(const char*)v_baid_org_status.arr);
DEBUGLOG(("GetByBatchId baid_org_status = [%s]\n",v_baid_org_status.arr));
                }

/* baid_new_status */
		if(ind_baid_new_status>=0){
                        v_baid_new_status.arr[v_baid_new_status.len]='\0';
                        PutField_CString(myHash,"baid_new_status",(const char*)v_baid_new_status.arr);
DEBUGLOG(("GetByBatchId baid_new_status = [%s]\n",v_baid_new_status.arr));
                }

/* adj_txn_code */
		if(ind_adj_txn_code>=0){
                        v_adj_txn_code.arr[v_adj_txn_code.len]='\0';
                        PutField_CString(myHash,"adj_txn_code",(const char*)v_adj_txn_code.arr);
DEBUGLOG(("GetByBatchId adj_txn_code = [%s]\n",v_adj_txn_code.arr));
                }

/* adj_rpt_date */
		if(ind_adj_rpt_date>=0){
                        v_adj_rpt_date.arr[v_adj_rpt_date.len]='\0';
                        PutField_CString(myHash,"adj_rpt_date",(const char*)v_adj_rpt_date.arr);
DEBUGLOG(("GetByBatchId adj_rpt_date = [%s]\n",v_adj_rpt_date.arr));
                }

/* adj_remark */
		if(ind_adj_remark>=0){
                        v_adj_remark.arr[v_adj_remark.len]='\0';
                        PutField_CString(myHash,"adj_remark",(const char*)v_adj_remark.arr);
DEBUGLOG(("GetByBatchId adj_remark = [%s]\n",v_adj_remark.arr));
                }

/* ret_code */
                if(ind_ret_code>=0){
                        PutField_Int(myHash,"ret_code",v_ret_code);
DEBUGLOG(("GetByBatchId ret_code= [%d]\n",v_ret_code));
                }

/* country */
		if(ind_country>=0){
			v_country.arr[v_country.len]='\0';
			PutField_CString(myHash,"country",(const char*)v_country.arr);
DEBUGLOG(("GetByBatchId country= [%s]\n",v_country.arr));
		}

/* currency */
		if(ind_currency>=0){
			v_currency.arr[v_currency.len]='\0';
			PutField_CString(myHash,"currency",(const char*)v_currency.arr);
DEBUGLOG(("GetByBatchId currency= [%s]\n",v_currency.arr));
		}

/* txn_id */
		if (ind_txn_id >= 0){
			v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash, "txn_id", (const char *)v_txn_id.arr);
DEBUGLOG(("GetByBatchId txn_id = [%s]\n", v_txn_id.arr));
		}

/* org_hold_type */
		if (ind_org_hold_type >= 0){
			PutField_Char(myHash, "org_hold_type", v_org_hold_type);
DEBUGLOG(("GetByBatchId org_hold_type = [%c]\n", v_org_hold_type));
		}

/* hold_type */
		if (ind_hold_type >= 0){
			PutField_Char(myHash, "hold_type", v_hold_type);
DEBUGLOG(("GetByBatchId hold_type = [%c]\n", v_hold_type));
		}

                iCnt++;
                RecordSet_Add(myRec,myHash);

	} while (PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )219;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getbybatchid_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetByBatchId Found\n"));
                iRet = FOUND;
        } else {
DEBUGLOG(("GetByBatchId Not Found\n"));
        }

DEBUGLOG(("GetByBatchId Normal Exit [%d]\n", iRet));
        return  iRet;

getbybatchid_error:
DEBUGLOG(("getbybatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBulkDetail_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )234;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int Update(const hash_t *hRec)
{
        int iSeq;
	int iTmp;

        char *csBatchId;
	char *csSeq = NULL;
        char *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
	csSeq = (char*)malloc(16);
        strcpy((char*)hv_dynstmt.arr,"update ol_bulk_detail set obd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"batch_id",&csBatchId)){
DEBUGLOG(("Update:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("Update batch_id not found\n"));
                return INT_ERR;
        }

        if(GetField_Int(hRec,"seq",&iSeq)){
		sprintf(csSeq, "%d", iSeq);
DEBUGLOG(("Update:seq = [%s]\n",csSeq));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("Update seq not found\n"));
                return INT_ERR;
        }

	if(GetField_CString(hRec,"bank_acct_org_status",&csBuf)){
DEBUGLOG(("Update: bank_acct_org_status = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_bank_acct_org_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"bank_acct_new_status",&csBuf)){
DEBUGLOG(("Update: bank_acct_new_status = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_bank_acct_new_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"baid_org_status",&csBuf)){
DEBUGLOG(("Update: baid_org_status = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_baid_org_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"baid_new_status",&csBuf)){
DEBUGLOG(("Update: baid_new_status = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_baid_new_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"adj_rpt_date",&csBuf)){
DEBUGLOG(("Update: adj_rpt_date = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_adj_rpt_date = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"adj_remark",&csBuf)){
DEBUGLOG(("Update: adj_remark = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_adj_remark = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


	if(GetField_Int(hRec,"ret_code",&iTmp)){
DEBUGLOG(("Update: return_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",obd_ret_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE obd_batch_id= ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        strcat((char*)hv_dynstmt.arr, " AND obd_seq= ");
        strcat((char*)hv_dynstmt.arr, csSeq);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )249;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )268;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csSeq);
        FREE_ME(csBuf);

DEBUGLOG(("Update: Normal Exit\n"));
        return PD_OK;

update_error:

DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBulkDetail_Update: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	FREE_ME(csSeq);
	FREE_ME(csBuf);
        return PD_INTERNAL_ERR;
}

int UpdateByBatchId(const hash_t *hRec)
{
	int iTmp;

        char *csBatchId;
        char *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebybatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_bulk_detail set obd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"batch_id",&csBatchId)){
DEBUGLOG(("Update:batch_id = [%s]\n",csBatchId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("Update batch_id not found\n"));
                return INT_ERR;
        }

	if(GetField_Int(hRec,"ret_code",&iTmp)){
DEBUGLOG(("Update: return_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",obd_ret_code = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("Update: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",obd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE obd_batch_id= ");
        strcat((char*)hv_dynstmt.arr, csBatchId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )283;
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
        if (sqlca.sqlcode < 0) goto updatebybatchid_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 17;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )302;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebybatchid_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("Update: Normal Exit\n"));
        return PD_OK;

updatebybatchid_error:

DEBUGLOG(("updatebybatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBulkDetail_UpdateByBatchId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

