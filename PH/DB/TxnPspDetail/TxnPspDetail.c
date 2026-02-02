
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
    "TxnPspDetail.pc"
};


static unsigned int sqlctx = 2742315;


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
   unsigned char  *sqhstv[31];
   unsigned long  sqhstl[31];
            int   sqhsts[31];
            short *sqindv[31];
            int   sqinds[31];
   unsigned long  sqharm[31];
   unsigned long  *sqharc[31];
   unsigned short  sqadto[31];
   unsigned short  sqtdso[31];
} sqlstm = {12,31};

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
"select tp_psp_id , tp_tid , tp_txn_date , tp_txn_time , tp_fundin_date , tp\
_fundout_date , tp_notice_status , tp_error_code , tp_batch_id , tp_txn_amoun\
t , tp_service_fee , tp_bank_bill_no , tp_txn_ccy , tp_status , tp_bank_code \
, tp_bank_branch , tp_account_name , tp_account_no , tp_pay_center_number , t\
p_customer_number , tp_conf_number , tp_receipt_number , tp_store_id , tP_con\
venience_store , tp_url , tp_recon_ind , tp_sc , tp_pid_group , tp_cost_charg\
ing_method , tp_cost_txn_id , tp_paid_amount from txn_psp_detail where tp_txn\
_id = :b0            ";

 static char *sq0004 = 
"select tp_txn_id , tp_txn_amount , tp_paid_amount , tp_service_fee , tp_fun\
din_date_short from txn_psp_detail , txn_header where tp_txn_id = th_txn_id a\
nd tp_psp_id = :b0 and tp_txn_ccy = :b1 and th_txn_code in ( 'DSP' , 'DSI' ) \
and tp_match_date = :b2 and th_status = 'C' and th_ar_ind = 'A' and tp_match_\
ind = 1 and tp_recon_ind = 0 order by th_txn_id            ";

 static char *sq0005 = 
"select tp_txn_id , tp_txn_amount , tp_paid_amount , tp_service_fee , tp_fun\
din_date_short from txn_psp_detail , txn_header where tp_txn_id = th_txn_id a\
nd tp_psp_id = :b0 and tp_txn_ccy = :b1 and th_txn_code in ( 'DSP' , 'DSI' ) \
and tp_match_date = :b2 and th_status = 'C' and th_ar_ind = 'A' and tp_match_\
ind = 1 and tp_recon_ind = 0 for update ";

 static char *sq0009 = 
"select tp_report_date , tp_txn_date from txn_psp_detail where tp_txn_id = :\
b0            ";

 static char *sq0010 = 
"select th_txn_id from txn_header , txn_psp_detail where th_txn_id = tp_txn_\
id and th_approval_date is not null and th_approval_date = :b0 and th_txn_cod\
e = 'DSI' and th_status = 'C' and th_ar_ind = 'A' and ( tp_bal is null or tp_\
total_float is null or tp_total_hold is null ) order by th_approval_timestamp\
 , th_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,684,0,6,293,0,0,22,22,0,1,0,3,3,0,0,3,9,0,0,3,9,0,0,3,4,0,0,3,9,0,0,3,
9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,
3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,4,0,0,3,9,0,0,3,9,0,0,
108,0,0,2,0,0,17,825,0,0,1,1,0,1,0,1,9,0,0,
127,0,0,2,0,0,21,826,0,0,0,0,0,1,0,
142,0,0,3,558,0,9,964,0,2049,1,1,0,1,0,1,9,0,0,
161,0,0,3,0,0,13,966,0,0,31,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,3,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,4,0,0,
300,0,0,3,0,0,15,1217,0,0,0,0,0,1,0,
315,0,0,3,0,0,15,1227,0,0,0,0,0,1,0,
330,0,0,4,365,0,9,1294,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
357,0,0,4,0,0,13,1296,0,0,5,0,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,
392,0,0,4,0,0,15,1346,0,0,0,0,0,1,0,
407,0,0,4,0,0,15,1356,0,0,0,0,0,1,0,
422,0,0,5,346,0,9,1423,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
449,0,0,5,0,0,13,1425,0,0,5,0,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,
484,0,0,5,0,0,15,1475,0,0,0,0,0,1,0,
499,0,0,5,0,0,15,1485,0,0,0,0,0,1,0,
514,0,0,0,0,0,56,1541,0,0,1,1,0,1,0,3,102,0,0,
533,0,0,6,128,0,6,1542,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
564,0,0,0,0,0,13,1566,0,0,9,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
615,0,0,0,0,0,15,1642,0,0,1,1,0,1,0,1,102,0,0,
634,0,0,0,0,0,78,1643,0,0,1,1,0,1,0,3,102,0,0,
653,0,0,0,0,0,15,1651,0,0,1,1,0,1,0,1,102,0,0,
672,0,0,0,0,0,78,1652,0,0,1,1,0,1,0,3,102,0,0,
691,0,0,7,145,0,6,1699,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,
730,0,0,0,0,0,56,1768,0,0,1,1,0,1,0,3,102,0,0,
749,0,0,8,107,0,6,1769,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,2,102,0,0,
776,0,0,0,0,0,13,1785,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
799,0,0,0,0,0,15,1805,0,0,1,1,0,1,0,1,102,0,0,
818,0,0,0,0,0,78,1806,0,0,1,1,0,1,0,3,102,0,0,
837,0,0,0,0,0,15,1814,0,0,1,1,0,1,0,1,102,0,0,
856,0,0,0,0,0,78,1815,0,0,1,1,0,1,0,3,102,0,0,
875,0,0,9,89,0,9,1846,0,2049,1,1,0,1,0,1,9,0,0,
894,0,0,9,0,0,13,1848,0,0,2,0,0,1,0,2,9,0,0,2,9,0,0,
917,0,0,9,0,0,15,1872,0,0,0,0,0,1,0,
932,0,0,9,0,0,15,1882,0,0,0,0,0,1,0,
947,0,0,10,330,0,9,1923,0,2049,1,1,0,1,0,1,9,0,0,
966,0,0,10,0,0,13,1926,0,0,1,0,0,1,0,2,9,0,0,
985,0,0,10,0,0,15,1952,0,0,0,0,0,1,0,
1000,0,0,10,0,0,15,1967,0,0,0,0,0,1,0,
1015,0,0,11,157,0,4,1991,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/09/17              [GOD]
Update GetTxnPspDetailForRecon			   2012/11/13		   [MSN]
Add field and GetTxnPspDetailByDlvId		   2013/03/06		   [MSN]
Add pid_group					   2013/10/29		   [MSN]
Add CostChargingMethod, CostTxnId		   2015/05/28		   [WWK]
Add PspBalNullInTxnPspDtByAprvDate                 2020/03/17              [WMC]
Add PspBalInTxnPspDetail			   2020/04/08		   [MSN]
Add field paid_amount in			   2020/11/24		   [ANC]
	Add()
	Update() 
	GetTxnPspDetail()
	GetTxnPspDetailForRecon()
	GetTxnPspDetailForReconUpdate()	
Remove paid_amount in Add()			   2021/01/29		   [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnPspDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;

void TxnPspDetail(char    cdebug)
{
        cDebug = cdebug;
}
int perr01(const char * msg){
    ERRLOG("Error occured when %s\n", msg);
    ERRLOG("{\n");
    ERRLOG(" sqlcaid = %s\n",sqlca.sqlcaid);
    ERRLOG(" sqlabc = %d\n",sqlca.sqlabc);
    ERRLOG(" sqlcode = %d\n",sqlca.sqlcode);
    ERRLOG(" sqlerrm.sqlerrml = %d\n",sqlca.sqlerrm.sqlerrml);
    ERRLOG(" sqlerrm.sqlerrmc = %s\n",sqlca.sqlerrm.sqlerrmc);
    ERRLOG(" sqlerrp = %s\n",sqlca.sqlerrp);
    ERRLOG(" sqlerrd = %d\n",sqlca.sqlerrd);
    ERRLOG(" sqlwarn = %s\n",sqlca.sqlwarn);
    ERRLOG(" sqlext = %s\n",sqlca.sqlext);
    ERRLOG("}\n");
    return 1;
}

int Add(const hash_t *hRls)
{
        char		*csTmp;
        double          dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
	
	/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

	double		hv_txn_amt;
	/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

	/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

	/* varchar		hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

	/* varchar		hv_status[PD_PSP_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_status;

	/* varchar		hv_notice_status[PD_PSP_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_notice_status;

	/* varchar		hv_error_code[PD_ERROR_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_error_code;

	/* varchar		hv_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_tid;

	/* varchar		hv_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_url;

	/* varchar		hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

	/* varchar		hv_bank_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_branch;

	/* varchar		hv_account_name[PD_ACCOUNT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_account_name;

	/* varchar		hv_account_no[PD_ACCOUNT_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_account_no;

	/* varchar		hv_batch_id[PD_BATCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_batch_id;

	/* varchar		hv_fundin_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_fundin_date;

	/* varchar		hv_fundout_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_fundout_date;

	double		hv_service_fee;
	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	/* varchar		hv_bill_no[PD_BANK_BILL_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bill_no;



	short		ind_txn_id = -1;
	short		ind_psp_id = -1;
	short		ind_txn_amt = -1;
	short		ind_txn_ccy = -1;
	short		ind_txn_date = -1;
	short		ind_desc = -1;
	short		ind_status = -1;
	short		ind_notice_status = -1;
	short		ind_error_code = -1;
	short		ind_tid = -1;
	short		ind_url = -1;
	short		ind_bank_code = -1;
	short		ind_bank_branch = -1;
	short		ind_account_name = -1;
	short		ind_account_no = -1;
	short		ind_batch_id = -1;
	short		ind_fundin_date = -1;
	short		ind_fundout_date = -1;
	short		ind_service_fee = -1;
	short		ind_add_user = -1;
	short		ind_bill_no = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }
/* psp_id */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("Add:psp_id = [%.*s][%d]\n",hv_psp_id.len,hv_psp_id.arr,hv_psp_id.len));
        }



/* txn_amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
		hv_txn_amt= dTmp;
                ind_txn_amt = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_txn_amt));
        }

/*	if (GetField_Double(hRls,"txn_amount",&dTmp)){
		hv_txn_amt = dTmp;
		ind_txn_amt = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_txn_amt));
	}
*/
/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
                ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s][%d]\n",hv_txn_date.len,hv_txn_date.arr,hv_txn_date.len));
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("Add:txn_ccy = [%.*s][%d]\n",hv_txn_ccy.len,hv_txn_ccy.arr,hv_txn_ccy.len));
        }


/* desc */
	
	if (GetField_CString(hRls,"desc", &csTmp)) {
                hv_desc.len = strlen(csTmp);
                memcpy(hv_desc.arr,csTmp,hv_desc.len);
                ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s][%d]\n",hv_desc.len,hv_desc.arr,hv_desc.len));
		
	}

/* status */
	if (GetField_CString(hRls,"status", &csTmp)) {
                hv_status.len = strlen(csTmp);
                memcpy(hv_status.arr,csTmp,hv_status.len);
                ind_status = 0;
DEBUGLOG(("Add:status = [%.*s][%d]\n",hv_status.len,hv_status.arr,hv_status.len));
	}
/* notice_status */
	if (GetField_CString(hRls,"notice_status", &csTmp)) {
                hv_notice_status.len = strlen(csTmp);
                memcpy(hv_notice_status.arr,csTmp,hv_notice_status.len);
                ind_notice_status = 0;
DEBUGLOG(("Add:notice_status = [%.*s]\n",hv_notice_status.len,hv_notice_status.arr));
	}
/* error_code */
	if (GetField_CString(hRls,"error_code", &csTmp)) {
                hv_error_code.len = strlen(csTmp);
                memcpy(hv_error_code.arr,csTmp,hv_error_code.len);
                ind_error_code = 0;
DEBUGLOG(("Add:error_code = [%.*s]\n",hv_status.len,hv_error_code.arr));
	}

/* tid */
	if (GetField_CString(hRls,"tid", &csTmp)) {
                hv_tid.len = strlen(csTmp);
                memcpy(hv_tid.arr,csTmp,hv_tid.len);
                ind_tid = 0;
DEBUGLOG(("Add:tid = [%.*s][%d]\n",hv_tid.len,hv_tid.arr,hv_tid.len));
	}

/* url */
	if (GetField_CString(hRls,"deposit_url", &csTmp)) {
                hv_url.len = strlen(csTmp);
                memcpy(hv_url.arr,csTmp,hv_url.len);
                ind_url = 0;
DEBUGLOG(("Add:url = [%.*s][%d]\n",hv_url.len,hv_url.arr,hv_url.len));
	}
/* bank_code */
	if (GetField_CString(hRls,"bank_code", &csTmp)) {
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
                ind_bank_code = 0;
DEBUGLOG(("Add:bank_code = [%.*s][%d]\n",hv_bank_code.len,hv_bank_code.arr,hv_bank_code.len));
	}
/* bank_branch */
	if (GetField_CString(hRls,"bank_branch", &csTmp)) {
                hv_bank_branch.len = strlen(csTmp);
                memcpy(hv_bank_branch.arr,csTmp,hv_bank_branch.len);
                ind_bank_branch = 0;
DEBUGLOG(("Add:bank_branch = [%.*s][%d]\n",hv_bank_branch.len,hv_bank_branch.arr,hv_bank_branch.len));
	}
/* account_name */
	if (GetField_CString(hRls,"account_name", &csTmp)) {
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr,csTmp,hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s][%d]\n",hv_account_name.len,hv_account_name.arr,hv_account_name.len));
	}
/* account_no */
	if (GetField_CString(hRls,"account_no", &csTmp)) {
                hv_account_no.len = strlen(csTmp);
                memcpy(hv_account_no.arr,csTmp,hv_account_no.len);
                ind_account_no = 0;
DEBUGLOG(("Add:account_no = [%.*s][%d]\n",hv_account_no.len,hv_account_no.arr,hv_account_no.len));
	}
/* batch_id */
	if (GetField_CString(hRls,"batch_id", &csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
                ind_batch_id = 0;
DEBUGLOG(("Add:batch_id = [%.*s][%d]\n",hv_batch_id.len,hv_batch_id.arr,hv_batch_id.len));
	}

/* fundin_date */
	if (GetField_CString(hRls,"fundin_date", &csTmp)) {
                hv_fundin_date.len = strlen(csTmp);
                memcpy(hv_fundin_date.arr,csTmp,hv_fundin_date.len);
                ind_fundin_date = 0;
DEBUGLOG(("Add:fundin_date = [%.*s]\n",hv_fundin_date.len,hv_fundin_date.arr));
	}

/* fundout_date */
	if (GetField_CString(hRls,"fundout_date", &csTmp)) {
                hv_fundout_date.len = strlen(csTmp);
                memcpy(hv_fundout_date.arr,csTmp,hv_fundout_date.len);
                ind_fundout_date = 0;
DEBUGLOG(("Add:fundout_date = [%.*s]\n",hv_fundout_date.len,hv_fundout_date.arr));
	}
/* serive_fee */
	if (GetField_Double(hRls,"service_fee", &dTmp)) {
		hv_service_fee = dTmp;
                ind_service_fee = 0;
DEBUGLOG(("Add:service_fee = [%f]\n",hv_service_fee));
	}


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

/* bank bill no */
	if (GetField_CString(hRls,"bank_bill_no", &csTmp)) {
                hv_bill_no.len = strlen(csTmp);
                memcpy(hv_bill_no.arr,csTmp,hv_bill_no.len);
                ind_bill_no = 0;
DEBUGLOG(("Add:bank_bill_no = [%.*s][%d]\n",hv_bill_no.len,hv_bill_no.arr,hv_bill_no.len));
	}


	FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_txn_psp_detail_insert(
					:hv_txn_id:ind_txn_id,
					:hv_psp_id:ind_psp_id,
					:hv_txn_amt:ind_txn_amt,
					:hv_txn_date:ind_txn_date,
					:hv_txn_ccy:ind_txn_ccy,
					:hv_desc:ind_desc,
					:hv_status:ind_status,
					:hv_notice_status:ind_notice_status,
					:hv_error_code:ind_error_code,
					:hv_tid:ind_tid,
					:hv_url:ind_url,
					:hv_bank_code:ind_bank_code,
					:hv_bank_branch:ind_bank_branch,
					:hv_account_name:ind_account_name,
					:hv_account_no:ind_account_no,
					:hv_batch_id:ind_batch_id,
					:hv_fundin_date:ind_fundin_date,
					:hv_fundout_date:ind_fundout_date,
					:hv_service_fee:ind_service_fee,
					:hv_add_user:ind_add_user,
					:hv_add_user:ind_add_user,
					:hv_bill_no:ind_bill_no);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_psp_detail_insert ( :hv_tx\
n_id:ind_txn_id , :hv_psp_id:ind_psp_id , :hv_txn_amt:ind_txn_amt , :hv_txn_d\
ate:ind_txn_date , :hv_txn_ccy:ind_txn_ccy , :hv_desc:ind_desc , :hv_status:i\
nd_status , :hv_notice_status:ind_notice_status , :hv_error_code:ind_error_co\
de , :hv_tid:ind_tid , :hv_url:ind_url , :hv_bank_code:ind_bank_code , :hv_ba\
nk_branch:ind_bank_branch , :hv_account_name:ind_account_name , :hv_account_n\
o:ind_account_no , :hv_batch_id:ind_batch_id , :hv_fundin_date:ind_fundin_dat\
e , :hv_fundout_date:ind_fundout_date , :hv_service_fee:ind_service_fee , :hv\
_add_user:ind_add_user , :hv_add_user:ind_add_user , :hv_bill_no:ind_bill_no \
) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[2] = (unsigned long )12;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_psp_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_amt;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[4] = (unsigned long )10;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_date;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_desc;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_desc;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_status;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_notice_status;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_notice_status;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_error_code;
 sqlstm.sqhstl[9] = (unsigned long )8;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_error_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_tid;
 sqlstm.sqhstl[10] = (unsigned long )52;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_tid;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_url;
 sqlstm.sqhstl[11] = (unsigned long )257;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_url;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[12] = (unsigned long )12;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_bank_code;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_bank_branch;
 sqlstm.sqhstl[13] = (unsigned long )152;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_bank_branch;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[14] = (unsigned long )32;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_account_name;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_account_no;
 sqlstm.sqhstl[15] = (unsigned long )32;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_account_no;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[16] = (unsigned long )22;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_batch_id;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_fundin_date;
 sqlstm.sqhstl[17] = (unsigned long )16;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_fundin_date;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_fundout_date;
 sqlstm.sqhstl[18] = (unsigned long )16;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_fundout_date;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_service_fee;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_service_fee;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[20] = (unsigned long )22;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_add_user;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_bill_no;
 sqlstm.sqhstl[21] = (unsigned long )52;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_bill_no;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
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
ERRLOG("TxnPspDetail_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnPspDetail_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnPspDetail_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
perr01("Add_txnpspdetail");
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int Update(const hash_t *hRls)
{

	char*	csTmp; 
	char	cTmp;
	double	dTmp;
	int 	iTmp;
	char*	csBuf;
	char*	csTxnId; 
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update txn_psp_detail set tp_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* psp_id  */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
DEBUGLOG(("Update:psp_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_psp_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
DEBUGLOG(("Update:txn_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_txn_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
DEBUGLOG(("Update:txn_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_txn_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_time*/
        if (GetField_CString(hRls,"txn_time",&csTmp)) {
DEBUGLOG(("Update:txn_time = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_txn_time = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amount",&dTmp)) {
DEBUGLOG(("Update:txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_txn_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* desc */
        if (GetField_CString(hRls,"descorder_no",&csTmp)) {
DEBUGLOG(("Update:desc = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_desc = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* status */
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("Update:status = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_status = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* notice_status */
        if (GetField_CString(hRls,"notice_status",&csTmp)) {
DEBUGLOG(("Update:notice_status = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_notice_status = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("Update:notice_status = [%s]\n",hv_dynstmt.arr));
        }
/* error_code */
        if (GetField_CString(hRls,"error_code",&csTmp)) {
DEBUGLOG(("Update:error_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_error_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* tid */
        if (GetField_CString(hRls,"tid",&csTmp)) {
DEBUGLOG(("Update:tid = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_tid = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* url */
        if (GetField_CString(hRls,"deposit_url",&csTmp)) {
DEBUGLOG(("Update:deposit_url = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_url = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* bank_code */
        if (GetField_CString(hRls,"bank_code",&csTmp)) {
DEBUGLOG(("Update:bank_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_bank_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* bank_branch */
        if (GetField_CString(hRls,"bank_branch",&csTmp)) {
DEBUGLOG(("Update:bank_branch = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_bank_branch = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* account_name */
        if (GetField_CString(hRls,"account_name",&csTmp)) {
DEBUGLOG(("Update:account_name = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_account_name = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* account_no */
        if (GetField_CString(hRls,"account_no",&csTmp)) {
DEBUGLOG(("Update:account_no = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_account_no = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
DEBUGLOG(("Update:batch_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_batch_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* fundin_date */
        if (GetField_CString(hRls,"fundin_date",&csTmp)) {
DEBUGLOG(("Update:fundin_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_fundin_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* limit_date */
        if (GetField_CString(hRls,"limit_date",&csTmp)) {
DEBUGLOG(("Update:limit_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_limit_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment_limit_date */
        if (GetField_CString(hRls,"payment_limit_date",&csTmp)) {
DEBUGLOG(("Update:payment_limit_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_payment_limit_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* payment notice id */
        if (GetField_CString(hRls,"payment_notice_id",&csTmp)) {
DEBUGLOG(("Update:payment_notice_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_payment_notice_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment type */
        if (GetField_CString(hRls,"payment_type",&csTmp)) {
DEBUGLOG(("Update:payment_type = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_payment_type = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment status */
        if (GetField_CString(hRls,"payment_status",&csTmp)) {
DEBUGLOG(("Update:payment_status = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_payment_status = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* pay_center_number */
        if (GetField_CString(hRls,"pay_center_number",&csTmp)) {
DEBUGLOG(("Update:pay_center_number = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_pay_center_number = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* customer_number */
        if (GetField_CString(hRls,"customer_number",&csTmp)) {
DEBUGLOG(("Update:customer_number = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_customer_number = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* conf_number */
        if (GetField_CString(hRls,"conf_number",&csTmp)) {
DEBUGLOG(("Update:conf_number = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_conf_number = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* receipt_number */
        if (GetField_CString(hRls,"receipt_number",&csTmp)) {
DEBUGLOG(("Update:receipt_number = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_receipt_number = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* store_id */
        if (GetField_CString(hRls,"store_id",&csTmp)) {
DEBUGLOG(("Update:store_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_store_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* convenience_store */
        if (GetField_CString(hRls,"convenience_store",&csTmp)) {
DEBUGLOG(("Update:convenience_store = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_convenience_store = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* sc */
        if (GetField_CString(hRls,"sc",&csTmp)) {
DEBUGLOG(("Update:sc = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_sc = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }




/* fundout_date */
        if (GetField_CString(hRls,"fundout_date",&csTmp)) {
DEBUGLOG(("Update:fundout_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_fundout_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* service_fee   */
        if (GetField_Double(hRls,"service_fee",&dTmp)) {
DEBUGLOG(("Update:serive_fee = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_service_fee = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank bill no*/
        if (GetField_CString(hRls,"bank_bill_no",&csTmp)) {
DEBUGLOG(("Update:bank_bill_no = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_bank_bill_no = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bal */
        if (GetField_Double(hRls,"bal",&dTmp)) {
DEBUGLOG(("Update:current_balance = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_bal = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float */
        if (GetField_Double(hRls,"total_float",&dTmp)) {
DEBUGLOG(("Update:total_float = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_total_float = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_hold */
        if (GetField_Double(hRls,"total_hold",&dTmp)) {
DEBUGLOG(("Update:total_hold = [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_total_hold = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* fundin_date_short */
        if (GetField_CString(hRls,"fundin_date_short",&csTmp)) {
DEBUGLOG(("Update:fundin_date_short = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_fundin_date_short = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* match_ind */
        if (GetField_Int(hRls,"match_ind",&iTmp)) {
DEBUGLOG(("Update:match_ind = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_match_ind = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* match_date */
        if (GetField_CString(hRls,"match_date",&csTmp)) {
DEBUGLOG(("Update:match_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_match_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* recon_ind */
        if (GetField_Int(hRls,"recon_ind",&iTmp)) {
DEBUGLOG(("Update:recon_ind = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_recon_ind = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* recon_date */
        if (GetField_CString(hRls,"recon_date",&csTmp)) {
DEBUGLOG(("Update:recon_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_recon_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* delivery id */
        if (GetField_CString(hRls,"delivery_id",&csTmp)) {
DEBUGLOG(("Update:delivery_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_delivery_id= '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* report_date */
        if (GetField_CString(hRls,"report_date",&csTmp)) {
DEBUGLOG(("Update:report_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_report_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* pid_group */
        if (GetField_CString(hRls,"pid_group",&csTmp)) {
DEBUGLOG(("Update:pid_group = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_pid_group= '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ret_bank_code */
        if (GetField_CString(hRls,"ret_bank_code",&csTmp)) {
DEBUGLOG(("Update:ret_bank_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_ret_bank_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* cost_charging_method */
	if (GetField_Char(hRls,"cost_charging_method",&cTmp)) {
DEBUGLOG(("Update:cost_charging_method = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_cost_charging_method = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* cost_txn_id */
	if (GetField_CString(hRls,"cost_txn_id",&csTmp)) {
DEBUGLOG(("Update:cost_txn_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_cost_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* paid_amount   */
	if (GetField_Double(hRls,"paid_amount",&dTmp)) {
DEBUGLOG(("Update:paid_amount = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",tp_paid_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_create_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",tp_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char *)hv_dynstmt.arr, " WHERE tp_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )108;
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
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )127;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);


DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnPspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetTxnPspDetail(const char* csTxnID,
		recordset_t* myRec)
{

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnpspdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_tid[PD_PSP_TID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

		/* varchar		v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar		v_txn_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_txn_time;

		/* varchar		v_fundin_date[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

		/* varchar		v_fundout_date[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundout_date;

		/* varchar		v_notice_status[PD_PSP_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_notice_status;

		/* varchar		v_error_code[PD_ERROR_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_error_code;

		/* varchar		v_batch_id[PD_BATCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_batch_id;

		/* varchar		v_bill_no[PD_BANK_BILL_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bill_no;

		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar		v_status[PD_PSP_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_status;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar		v_bank_branch[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_branch;

		/* varchar		v_account_name[PD_ACCOUNT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_account_name;

		/* varchar		v_account_no[PD_ACCOUNT_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[31]; } v_account_no;

		/* varchar		v_pay_center_number[PD_PAY_CENTER_NUMBER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pay_center_number;

		/* varchar		v_customer_number[PD_CUSTOMER_NUMBER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_customer_number;

		/* varchar		v_conf_number[PD_CONF_NUMBER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_conf_number;

		/* varchar		v_receipt_number[PD_RECEIPT_NUMBER_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[33]; } v_receipt_number;

		/* varchar		v_store_id[PD_STORE_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[129]; } v_store_id;

		/* varchar		v_convenience_store[PD_CONVENIENCE_STORE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_convenience_store;

		/* varchar		v_url[PD_URL_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_url;

		/* varchar		v_sc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sc;

		/* varchar         v_pid_group[PD_CUSTOMER_GROUP_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid_group;

		char		v_cost_charging_method;
		/* varchar		v_cost_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_cost_txn_id;


		double		v_txn_amt;
		double		v_service_fee;
		int		v_recon_ind;
		double		v_paid_amount;

		short		ind_psp_id = -1;
		short		ind_tid = -1;
		short		ind_txn_date = -1;
		short		ind_txn_time = -1;
		short		ind_fundin_date = -1;
		short		ind_fundout_date = -1;
		short		ind_notice_status = -1;
		short		ind_error_code = -1;
		short		ind_batch_id = -1;
		short		ind_txn_amt = -1;
		short		ind_service_fee = -1;
		short		ind_bill_no = -1;
		short		ind_txn_ccy= -1;
		short		ind_status= -1;
		short		ind_bank_code= -1;
		short		ind_bank_branch= -1;
		short		ind_account_name= -1;
		short		ind_account_no= -1;
		short		ind_pay_center_number =-1;
		short		ind_customer_number =-1;
		short		ind_conf_number = -1;
		short		ind_receipt_number = -1;
		short		ind_store_id = -1;
		short		ind_convenience_store = -1;
		short		ind_url = -1;
		short		ind_recon_ind = -1;
		short		ind_sc = -1;
		short           ind_pid_group = -1;
		short		ind_cost_charging_method = -1;
		short		ind_cost_txn_id = -1;
		short		ind_paid_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnPspDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxnpspdetail CURSOR FOR
		select 
			tp_psp_id,
			tp_tid,
			tp_txn_date,
			tp_txn_time,
			tp_fundin_date,
			tp_fundout_date,
			tp_notice_status,
			tp_error_code,
			tp_batch_id,
			tp_txn_amount,
			tp_service_fee,
			tp_bank_bill_no,
			tp_txn_ccy,
			tp_status,
			tp_bank_code,
			tp_bank_branch,
			tp_account_name,
			tp_account_no,
		        tp_pay_center_number,
			tp_customer_number,
			tp_conf_number,
			tp_receipt_number,
			tp_store_id,
			tP_convenience_store,
			tp_url,
			tp_recon_ind,
			tp_sc,
                        tp_pid_group,
			tp_cost_charging_method,
			tp_cost_txn_id,
			tp_paid_amount
		  from txn_psp_detail
		 where tp_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_gettxnpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )142;
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
        if (sqlca.sqlcode < 0) goto gettxnpspdetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxnpspdetail
                INTO
			:v_psp_id:ind_psp_id,
			:v_tid:ind_tid,
			:v_txn_date:ind_txn_date,
			:v_txn_time:ind_txn_time,
			:v_fundin_date:ind_fundin_date,
			:v_fundout_date:ind_fundout_date,
			:v_notice_status:ind_notice_status,
			:v_error_code:ind_error_code,
			:v_batch_id:ind_batch_id,
			:v_txn_amt:ind_txn_amt,
			:v_service_fee:ind_service_fee,
			:v_bill_no:ind_bill_no,
			:v_txn_ccy:ind_txn_ccy,
			:v_status:ind_status,
			:v_bank_code:ind_bank_code,
			:v_bank_branch:ind_bank_branch,
			:v_account_name:ind_account_name,
			:v_account_no:ind_account_no,
			:v_pay_center_number:ind_pay_center_number,
			:v_customer_number:ind_customer_number,
			:v_conf_number:ind_conf_number,
			:v_receipt_number:ind_receipt_number,
			:v_store_id:ind_store_id,
			:v_convenience_store:ind_convenience_store,
			:v_url:ind_url,
			:v_recon_ind:ind_recon_ind,
			:v_sc:ind_sc,
                        :v_pid_group:ind_pid_group,
			:v_cost_charging_method:ind_cost_charging_method,
			:v_cost_txn_id:ind_cost_txn_id,
			:v_paid_amount:ind_paid_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )161;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[0] = (unsigned long )13;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_psp_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_tid;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[2] = (unsigned long )11;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_date;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_time;
                sqlstm.sqhstl[3] = (unsigned long )9;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_time;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )17;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_fundout_date;
                sqlstm.sqhstl[5] = (unsigned long )17;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_fundout_date;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_notice_status;
                sqlstm.sqhstl[6] = (unsigned long )23;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_notice_status;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_error_code;
                sqlstm.sqhstl[7] = (unsigned long )9;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_error_code;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[8] = (unsigned long )23;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_batch_id;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_service_fee;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_bill_no;
                sqlstm.sqhstl[11] = (unsigned long )53;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_bill_no;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[12] = (unsigned long )6;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[13] = (unsigned long )23;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_status;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[14] = (unsigned long )13;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_bank_code;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_bank_branch;
                sqlstm.sqhstl[15] = (unsigned long )153;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_bank_branch;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[16] = (unsigned long )33;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_account_name;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_account_no;
                sqlstm.sqhstl[17] = (unsigned long )33;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_account_no;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_pay_center_number;
                sqlstm.sqhstl[18] = (unsigned long )13;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_pay_center_number;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_customer_number;
                sqlstm.sqhstl[19] = (unsigned long )23;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_customer_number;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_conf_number;
                sqlstm.sqhstl[20] = (unsigned long )9;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_conf_number;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_receipt_number;
                sqlstm.sqhstl[21] = (unsigned long )35;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_receipt_number;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_store_id;
                sqlstm.sqhstl[22] = (unsigned long )131;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_store_id;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_convenience_store;
                sqlstm.sqhstl[23] = (unsigned long )13;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_convenience_store;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_url;
                sqlstm.sqhstl[24] = (unsigned long )258;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_url;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_recon_ind;
                sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_recon_ind;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_sc;
                sqlstm.sqhstl[26] = (unsigned long )53;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_sc;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_pid_group;
                sqlstm.sqhstl[27] = (unsigned long )13;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_pid_group;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_cost_charging_method;
                sqlstm.sqhstl[28] = (unsigned long )1;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_cost_charging_method;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_cost_txn_id;
                sqlstm.sqhstl[29] = (unsigned long )19;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_cost_txn_id;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_paid_amount;
                sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_paid_amount;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gettxnpspdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("GetTxnPspDetail Record Not Found\n"));
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* psp_id */
                if (ind_psp_id  >=  0) { 
			v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetTxnPspDetail psp_id = [%s]\n",v_psp_id.arr));
		}

/* tid */
                if (ind_tid  >=  0) { 
			v_tid.arr[v_tid.len] = '\0';
                        PutField_CString(myHash,"tid",(const char*)v_tid.arr);
DEBUGLOG(("GetTxnPspDetail tid = [%s]\n",v_tid.arr));
		}

/* txn_date */
                if (ind_txn_date  >=  0) { 
			v_txn_date.arr[v_txn_date.len] = '\0';
                        PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetTxnPspDetail txn_date = [%s]\n",v_txn_date.arr));
		}
/* txn_time */
                if (ind_txn_time  >=  0) { 
			v_txn_time.arr[v_txn_time.len] = '\0';
                        PutField_CString(myHash,"txn_time",(const char*)v_txn_time.arr);
DEBUGLOG(("GetTxnPspDetail txn_time = [%s]\n",v_txn_time.arr));
		}
/* fundin_date */
                if (ind_fundin_date  >=  0) { 
			v_fundin_date.arr[v_fundin_date.len] = '\0';
                        PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
DEBUGLOG(("GetTxnPspDetail fundin_date = [%s]\n",v_fundin_date.arr));
		}
/* fundout_date */
                if (ind_fundout_date  >=  0) { 
			v_fundout_date.arr[v_fundout_date.len] = '\0';
                        PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetTxnPspDetail fundout_date = [%s]\n",v_fundout_date.arr));
		}
/* notice_status */
                if (ind_notice_status  >=  0) { 
			v_notice_status.arr[v_notice_status.len] = '\0';
                        PutField_CString(myHash,"notice_status",(const char*)v_notice_status.arr);
DEBUGLOG(("GetTxnPspDetail notice_status = [%s]\n",v_notice_status.arr));
		}
/* status */
                if (ind_status  >=  0) { 
			v_status.arr[v_status.len] = '\0';
                        PutField_CString(myHash,"status",(const char*)v_status.arr);
DEBUGLOG(("GetTxnPspDetail status = [%s]\n",v_status.arr));
		}
/* error_code */
                if (ind_error_code  >=  0) { 
			v_error_code.arr[v_error_code.len] = '\0';
                        PutField_CString(myHash,"error_code",(const char*)v_error_code.arr);
DEBUGLOG(("GetTxnPspDetail error_code = [%s]\n",v_error_code.arr));
		}

/* batch_id */
                if (ind_batch_id  >=  0) { 
			v_batch_id.arr[v_batch_id.len] = '\0';
                        PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetTxnPspDetail batch_id = [%s]\n",v_batch_id.arr));
		}

/*txn_amt*/
		if(ind_txn_amt>=0){
			PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetTxnPspDetail txn_amt = [%f]\n",v_txn_amt));
		}

/*service_fee*/
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetTxnPspDetail service_fee = [%f]\n",v_service_fee));
		}

/* bank bill no*/
                if (ind_bill_no  >=  0) { 
			v_bill_no.arr[v_bill_no.len] = '\0';
                        PutField_CString(myHash,"bank_bill_no",(const char*)v_bill_no.arr);
DEBUGLOG(("GetTxnPspDetail bank_bill_no = [%s]\n",v_bill_no.arr));
		}

/* txn_ccy*/
                if (ind_txn_ccy >=  0) { 
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetTxnPspDetail txn_ccy = [%s]\n",v_txn_ccy.arr));
		}

/* bank_code*/
                if (ind_bank_code>=  0) { 
			v_bank_code.arr[v_bank_code.len] = '\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetTxnPspDetail bank_code = [%s]\n",v_bank_code.arr));
		}

/* bank_branch*/
                if (ind_bank_branch>=  0) { 
			v_bank_branch.arr[v_bank_branch.len] = '\0';
                        PutField_CString(myHash,"bank_branch",(const char*)v_bank_branch.arr);
DEBUGLOG(("GetTxnPspDetail bank_branch = [%s]\n",v_bank_branch.arr));
		}


/* account_name */
                if (ind_account_name >=  0) { 
			v_account_name.arr[v_account_name.len] = '\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetTxnPspDetail account_name = [%s]\n",v_account_name.arr));
		}


/* account_no*/
                if (ind_account_no>=  0) { 
			v_account_no.arr[v_account_no.len] = '\0';
                        PutField_CString(myHash,"account_no",(const char*)v_account_no.arr);
DEBUGLOG(("GetTxnPspDetail account_no = [%s]\n",v_account_no.arr));
		}

/* pay_center_number*/
                if (ind_pay_center_number>=  0) { 
			v_pay_center_number.arr[v_pay_center_number.len] = '\0';
                        PutField_CString(myHash,"pay_center_number",(const char*)v_pay_center_number.arr);
DEBUGLOG(("GetTxnPspDetail pay_center_number = [%s]\n",v_pay_center_number.arr));
		}

/* customer_number*/
                if (ind_customer_number>=  0) { 
			v_customer_number.arr[v_customer_number.len] = '\0';
                        PutField_CString(myHash,"customer_number",(const char*)v_customer_number.arr);
DEBUGLOG(("GetTxnPspDetail customer_number = [%s]\n",v_customer_number.arr));
		}

/* conf_number*/
                if (ind_conf_number>=  0) { 
			v_conf_number.arr[v_conf_number.len] = '\0';
                        PutField_CString(myHash,"conf_number",(const char*)v_conf_number.arr);
DEBUGLOG(("GetTxnPspDetail conf_number = [%s]\n",v_conf_number.arr));
		}

/* receipt_number*/
                if (ind_receipt_number>=  0) { 
			v_receipt_number.arr[v_receipt_number.len] = '\0';
                        PutField_CString(myHash,"receipt_number",(const char*)v_receipt_number.arr);
DEBUGLOG(("GetTxnPspDetail receipt_number = [%s]\n",v_receipt_number.arr));
		}

/* store_id*/
                if (ind_store_id>=  0) { 
			v_store_id.arr[v_store_id.len] = '\0';
                        PutField_CString(myHash,"store_id",(const char*)v_store_id.arr);
DEBUGLOG(("GetTxnPspDetail store_id = [%s]\n",v_store_id.arr));
		}
/* convenience_store*/
                if (ind_convenience_store>=  0) { 
			v_convenience_store.arr[v_convenience_store.len] = '\0';
                        PutField_CString(myHash,"convenience_store",(const char*)v_convenience_store.arr);
DEBUGLOG(("GetTxnPspDetail convenience_store = [%s]\n",v_convenience_store.arr));
		}
/* url*/
                if (ind_url>=  0) { 
			v_url.arr[v_url.len] = '\0';
                        PutField_CString(myHash,"url",(const char*)v_url.arr);
DEBUGLOG(("GetTxnPspDetail url = [%s]\n",v_url.arr));
		}

/* recon_ind */
		if(ind_recon_ind >=0){
			PutField_Int(myHash,"recon_ind",v_recon_ind);
DEBUGLOG(("GetTxnPspDetail recon_ind = [%d]\n",v_recon_ind));
		}
/*sc*/
		if(ind_sc>=0){
			v_sc.arr[v_sc.len] = '\0';
                        PutField_CString(myHash,"sc",(const char*)v_sc.arr);
DEBUGLOG(("GetTxnPspDetail sc = [%s]\n",v_sc.arr));
		}

/* pid_group */
                if (ind_pid_group >=  0) {
                        v_pid_group.arr[v_pid_group.len] = '\0';
                        PutField_CString(myHash,"pid_group",(const char*)v_pid_group.arr);
DEBUGLOG(("GetTxnPspDetail pid_group = [%s]\n",v_pid_group.arr));
                }

/* cost_charging_method */
		if (ind_cost_charging_method >= 0) {
			PutField_Char(myHash,"cost_charging_method",v_cost_charging_method);
DEBUGLOG(("GetTxnPspDetail cost_charging_method = [%c]\n",v_cost_charging_method));
		}

/* cost_txn_id */
		if (ind_cost_txn_id >= 0) {
			v_cost_txn_id.arr[v_cost_txn_id.len] = '\0';
			PutField_CString(myHash,"cost_txn_id",(const char*)v_cost_txn_id.arr);
DEBUGLOG(("GetTxnPspDetail cost_txn_id = [%s]\n",v_cost_txn_id.arr));
		}

/*paid_amount*/
		if(ind_paid_amount>=0){
			PutField_Double(myHash,"paid_amount",v_paid_amount);
DEBUGLOG(("GetTxnPspDetail paid_amount = [%f]\n",v_paid_amount));
		}

		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxnpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )300;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnpspdetail_error;
}




DEBUGLOG(("GetTxnPspDetail Normal Exit\n")); 
        return  PD_OK;

gettxnpspdetail_error:
DEBUGLOG(("gettxnpspdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxnpspdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )315;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetTxnPspDetailForRecon(const char* csPspId,
			    const char* csTxnCcy,
			    const char* csDate,
			    recordset_t* myRec)
{

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getrecondetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_psp_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_psp_txn_date;

		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;


		/* varchar		v_fundin_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundin_date;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double		v_txn_amt;
		double		v_paid_amt;
		double		v_service_fee;

		short		ind_txn_id = -1;
		short		ind_txn_amt = -1;
		short		ind_paid_amt = -1;
		short		ind_service_fee = -1;
		short		ind_fundin_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetTxnPspDetailForRecon psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr,csTxnCcy,hv_txn_ccy.len);
DEBUGLOG(("GetTxnPspDetailForRecon txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

	hv_psp_txn_date.len = strlen(csDate);
	memcpy(hv_psp_txn_date.arr,csDate,hv_psp_txn_date.len);
DEBUGLOG(("GetTxnPspDetailForRecon psp_txn_date = [%.*s]\n",hv_psp_txn_date.len,hv_psp_txn_date.arr));


        /* EXEC SQL DECLARE c_cursor_getrecondetail CURSOR FOR
		select	tp_txn_id,
			tp_txn_amount,
			tp_paid_amount,
			tp_service_fee,
			tp_fundin_date_short
		from	txn_psp_detail,
			txn_header
		where	tp_txn_id = th_txn_id
		and	tp_psp_id = :hv_psp_id
		and	tp_txn_ccy = :hv_txn_ccy
		and     th_txn_code in ('DSP','DSI')
		and	tp_match_date = :hv_psp_txn_date
		and	th_status = 'C'
		and	th_ar_ind = 'A'
		and	tp_match_ind = 1
		and	tp_recon_ind = 0 
		order by th_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_getrecondetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )330;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_txn_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
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
        if (sqlca.sqlcode < 0) goto getrecondetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getrecondetail
                INTO	:v_txn_id:ind_txn_id,
			:v_txn_amt:ind_txn_amt,
			:v_paid_amt:ind_paid_amt,
			:v_service_fee:ind_service_fee,
			:v_fundin_date:ind_fundin_date; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )357;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_paid_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_paid_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_fee;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )11;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
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
                if (sqlca.sqlcode < 0) goto getrecondetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* txn_id */
                if (ind_txn_id>=0) { 
			v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailForRecon txn_id = [%s]\n",v_txn_id.arr));
		}

/* fundin_date */
                if (ind_fundin_date>=0) { 
			v_fundin_date.arr[v_fundin_date.len] = '\0';
                        PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
DEBUGLOG(("GetTxnPspDetailForRecon fundin_date = [%s]\n",v_fundin_date.arr));
		}

/* txn_amt */
		if(ind_txn_amt>=0){
			PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetTxnPspDetailForRecon txn_amt = [%f]\n",v_txn_amt));
		}

/* paid_amt */
                if(ind_paid_amt>=0){
                        PutField_Double(myHash,"paid_amt",v_paid_amt);
DEBUGLOG(("GetTxnPspDetailForRecon paid_amt = [%f]\n",v_paid_amt));
                }

/* service_fee */
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetTxnPspDetailForRecon service_fee = [%f]\n",v_service_fee));
		}

		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getrecondetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )392;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrecondetail_error;
}




DEBUGLOG(("GetTxnPspDetailForRecon Normal Exit\n")); 
        return  PD_OK;

getrecondetail_error:
DEBUGLOG(("getrecondetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getrecondetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )407;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetTxnPspDetailForReconUpdate(const char* csPspId,
			    const char* csTxnCcy,
			    const char* csDate,
			    recordset_t* myRec)
{

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getrecondetailupdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_psp_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_psp_txn_date;

		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;


		/* varchar		v_fundin_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundin_date;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		double		v_txn_amt;
		double		v_paid_amt;
		double		v_service_fee;

		short		ind_txn_id = -1;
		short		ind_txn_amt = -1;
		short		ind_paid_amt = -1;
		short		ind_service_fee = -1;
		short		ind_fundin_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetTxnPspDetailForReconUpdate psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr,csTxnCcy,hv_txn_ccy.len);
DEBUGLOG(("GetTxnPspDetailForReconUpdate txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

	hv_psp_txn_date.len = strlen(csDate);
	memcpy(hv_psp_txn_date.arr,csDate,hv_psp_txn_date.len);
DEBUGLOG(("GetTxnPspDetailForReconUpdate psp_txn_date = [%.*s]\n",hv_psp_txn_date.len,hv_psp_txn_date.arr));


        /* EXEC SQL DECLARE c_cursor_getrecondetailupdate CURSOR FOR
		select	tp_txn_id,
			tp_txn_amount,
			tp_paid_amount,
			tp_service_fee,
			tp_fundin_date_short
		from	txn_psp_detail,
			txn_header
		where	tp_txn_id = th_txn_id
		and	tp_psp_id = :hv_psp_id
		and	tp_txn_ccy = :hv_txn_ccy
		and     th_txn_code in ('DSP','DSI')
		and	tp_match_date = :hv_psp_txn_date
		and	th_status = 'C'
		and	th_ar_ind = 'A'
		and     tp_match_ind = 1
		and	tp_recon_ind = 0 
		for update; */ 



        /* EXEC SQL OPEN c_cursor_getrecondetailupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )422;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_txn_date;
        sqlstm.sqhstl[2] = (unsigned long )10;
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
        if (sqlca.sqlcode < 0) goto getrecondetailupdate_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getrecondetailupdate
                INTO	:v_txn_id:ind_txn_id,
			:v_txn_amt:ind_txn_amt,
			:v_paid_amt:ind_paid_amt,
			:v_service_fee:ind_service_fee,
			:v_fundin_date:ind_fundin_date; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )449;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_paid_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_paid_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_service_fee;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_service_fee;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[4] = (unsigned long )11;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_fundin_date;
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
                if (sqlca.sqlcode < 0) goto getrecondetailupdate_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* txn_id */
                if (ind_txn_id>=0) { 
			v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailForReconUpdate txn_id = [%s]\n",v_txn_id.arr));
		}

/* fundin_date */
                if (ind_fundin_date>=0) { 
			v_fundin_date.arr[v_fundin_date.len] = '\0';
                        PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
//DEBUGLOG(("GetTxnPspDetailForReconUpdate fundin_date = [%s]\n",v_fundin_date.arr));
		}

/* txn_amt */
		if(ind_txn_amt>=0){
			PutField_Double(myHash,"txn_amt",v_txn_amt);
//DEBUGLOG(("GetTxnPspDetailForReconUpdate txn_amt = [%f]\n",v_txn_amt));
		}

/* paid_amt */
                if(ind_paid_amt>=0){
                        PutField_Double(myHash,"paid_amt",v_paid_amt);
//DEBUGLOG(("GetTxnPspDetailForReconUpdate paid_amt = [%f]\n",v_paid_amt));
                }		

/* service_fee */
		if(ind_service_fee>=0){
			PutField_Double(myHash,"service_fee",v_service_fee);
//DEBUGLOG(("GetTxnPspDetailForReconUpdate service_fee = [%f]\n",v_service_fee));
		}

		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getrecondetailupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )484;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrecondetailupdate_error;
}




DEBUGLOG(("GetTxnPspDetailForReconUpdate Normal Exit\n")); 
        return  PD_OK;

getrecondetailupdate_error:
DEBUGLOG(("getrecondetailupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getrecondetailupdate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )499;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int GetPspReportDetail(const unsigned char* csPspId,
		       const unsigned char* csTxnDate,
		       recordset_t* myRec)
{
	int	iRet = PD_ERR;

	hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getreportdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

                /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;


                /* varchar         v_tid[PD_PSP_TID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_tid;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_fundin_date[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_fundin_date;

                /* varchar         v_bank_bill_no[PD_BANK_BILL_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_bill_no;

		/* varchar		v_amount[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_amount;

		double		v_service_fee;
		/* varchar		v_customer_tel[PD_CUSTOMER_TEL_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_customer_tel;

		/* varchar		v_paid_amount[PD_AMOUNT_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[13]; } v_paid_amount;


                short           ind_txn_date= -1;
                short           ind_psp_id = -1;
                short           ind_tid= -1;
                short           ind_txn_id= -1;
                short           ind_fundin_date= -1;
                short           ind_bank_bill_no= -1;
                short           ind_amount= -1;
                short           ind_service_fee= -1;
                short           ind_customer_tel= -1;
                short           ind_paid_amount= -1;

                 SQL_CURSOR      c_cursor_pspdt;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_date.len = strlen((const char*)csTxnDate);
        memcpy(hv_txn_date.arr,csTxnDate,hv_txn_date.len);
DEBUGLOG(("GetPspReportDetail txn_date= [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
        ind_txn_date= 0;
	
        hv_psp_id.len = strlen((const char*)csPspId);
        memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("GetPspReportDetail psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
        ind_psp_id= 0;
	
	/* EXEC SQL ALLOCATE       :c_cursor_pspdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )514;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
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
 if (sqlca.sqlcode < 0) goto getreportdetail_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_psp_dt_getpspdt(:hv_txn_date:ind_txn_date,
                                                                 :hv_psp_id:ind_psp_id,
                                                                 :c_cursor_pspdt);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_psp_dt_getpspdt ( :\
hv_txn_date:ind_txn_date , :hv_psp_id:ind_psp_id , :c_cursor_pspdt ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )533;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_date;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_psp_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_pspdt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto getreportdetail_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("GetPspReportDetail Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_tid= -1;
			ind_txn_id= -1;
			ind_fundin_date= -1;
			ind_bank_bill_no= -1;
			ind_amount= -1;
			ind_service_fee= -1;
			ind_customer_tel= -1;
			ind_paid_amount= -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_pspdt
                        INTO
                                :v_tid:ind_tid,
                                :v_txn_id:ind_txn_id,
				:v_fundin_date:ind_fundin_date,
				:v_bank_bill_no:ind_bank_bill_no,
				:v_amount:ind_amount,
				:v_service_fee:ind_service_fee,
				:v_customer_tel:ind_customer_tel,
				:v_paid_amount:ind_paid_amount; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 31;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )564;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_tid;
                        sqlstm.sqhstl[1] = (unsigned long )53;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_tid;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_fundin_date;
                        sqlstm.sqhstl[3] = (unsigned long )17;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_fundin_date;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_bill_no;
                        sqlstm.sqhstl[4] = (unsigned long )53;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_bank_bill_no;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_amount;
                        sqlstm.sqhstl[5] = (unsigned long )15;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_amount;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_service_fee;
                        sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_service_fee;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_customer_tel;
                        sqlstm.sqhstl[7] = (unsigned long )23;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_customer_tel;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_paid_amount;
                        sqlstm.sqhstl[8] = (unsigned long )15;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_paid_amount;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getreportdetail_error;
}



/* tid */
                        if (ind_tid >= 0) {
                                v_tid.arr[v_tid.len] = '\0';
                                PutField_CString(myHash,"tid",(const char*)v_tid.arr);
DEBUGLOG(("GetPspReportDetail tid = [%s]\n",v_tid.arr));
                        }

/* txn_id */
                        if (ind_txn_id >= 0) {
                                v_txn_id.arr[v_txn_id.len] = '\0';
                                PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetPspReportDetail txn_id = [%s]\n",v_txn_id.arr));
                        }


/* fundin_date */
                        if (ind_fundin_date >= 0) {
                                v_fundin_date.arr[v_fundin_date.len] = '\0';
                                PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
DEBUGLOG(("GetPspReportDetail fundin_date = [%s]\n",v_fundin_date.arr));
                        }

/* bank_bill_no */
                        if (ind_bank_bill_no >= 0) {
                                v_bank_bill_no.arr[v_bank_bill_no.len] = '\0';
                                PutField_CString(myHash,"bank_bill_no",(const char*)v_bank_bill_no.arr);
DEBUGLOG(("GetPspReportDetail bank_bill_no = [%s]\n",v_bank_bill_no.arr));
                        }

/* amount */
                        if (ind_amount >= 0) {
                                v_amount.arr[v_amount.len] = '\0';
                                PutField_CString(myHash,"amount",(const char*)v_amount.arr);
DEBUGLOG(("GetPspReportDetail amount = [%s]\n",v_amount.arr));
                        }

/* service_fee */
                        if (ind_service_fee >= 0){
                                PutField_Double(myHash,"service_fee",v_service_fee);
DEBUGLOG(("GetPspReportDetail service_fee = [%lf]\n",v_service_fee));
                        }

/* customer_tel */
                        if (ind_customer_tel >= 0) {
                                v_customer_tel.arr[v_customer_tel.len] = '\0';
                                PutField_CString(myHash,"customer_tel",(const char*)v_customer_tel.arr);
DEBUGLOG(("GetPspReportDetail customer_tel = [%s]\n",v_customer_tel.arr));
                        }

/* paid_amount */
                        if (ind_paid_amount >= 0) {
                                v_paid_amount.arr[v_paid_amount.len] = '\0';
                                PutField_CString(myHash,"paid_amount",(const char*)v_paid_amount.arr);
DEBUGLOG(("GetPspReportDetail paid_amount = [%s]\n",v_paid_amount.arr));
                        }

			iRet=PD_OK;
			RecordSet_Add(myRec,myHash);
		}

	}
	else{
DEBUGLOG(("GetPspReportDetail Not Found\n"));
	}

	/* EXEC SQL CLOSE :c_cursor_pspdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )615;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
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
 if (sqlca.sqlcode < 0) goto getreportdetail_error;
}


	/* EXEC SQL FREE :c_cursor_pspdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )634;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
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
 if (sqlca.sqlcode < 0) goto getreportdetail_error;
}



	return iRet; 

getreportdetail_error:
DEBUGLOG(("getreportdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_pspdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )653;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
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


	/* EXEC SQL FREE :c_cursor_pspdt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )672;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdt;
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

int UpdateReconedTxnPspDetail(const char* csPspId,
			    const char* csTxnCcy,
			    const char* csDate,
			    const char* csReconDate,
			    const char* csReportDate)
{

        /* EXEC SQL WHENEVER SQLERROR GOTO updatereconed_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_psp_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_psp_txn_date;

		/* varchar	hv_recon_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_recon_date;

		/* varchar	hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		/* varchar	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;


		short	hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_id.len = strlen(csPspId);
	memcpy(hv_psp_id.arr,csPspId,hv_psp_id.len);
DEBUGLOG(("UpdateReconedTxnPspDetail psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));

	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr,csTxnCcy,hv_txn_ccy.len);
DEBUGLOG(("UpdateReconedTxnPspDetail txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

	hv_psp_txn_date.len = strlen(csDate);
	memcpy(hv_psp_txn_date.arr,csDate,hv_psp_txn_date.len);
DEBUGLOG(("UpdateReconedTxnPspDetail psp_txn_date = [%.*s]\n",hv_psp_txn_date.len,hv_psp_txn_date.arr));

	hv_recon_date.len = strlen(csReconDate);
	memcpy(hv_recon_date.arr,csReconDate,hv_recon_date.len);
DEBUGLOG(("UpdateReconedTxnPspDetail recon_date = [%.*s]\n",hv_recon_date.len,hv_recon_date.arr));

	hv_report_date.len = strlen(csReportDate);
	memcpy(hv_report_date.arr,csReportDate,hv_report_date.len);
DEBUGLOG(("UpdateReconedTxnPspDetail report_date = [%.*s]\n",hv_report_date.len,hv_report_date.arr));


/* EXEC SQL EXECUTE
                BEGIN
                :hv_return_value := sp_update_reconed_txn_psp_dt(
                                        :hv_psp_id,
                                        :hv_txn_ccy,
                                        :hv_psp_txn_date,
                                        :hv_recon_date,
					:hv_report_date);

                END;
        END-EXEC; */ 

{
struct sqlexd sqlstm;
sqlstm.sqlvsn = 12;
sqlstm.arrsiz = 31;
sqlstm.sqladtp = &sqladt;
sqlstm.sqltdsp = &sqltds;
sqlstm.stmt = "begin :hv_return_value := sp_update_reconed_txn_psp_dt ( :hv\
_psp_id , :hv_txn_ccy , :hv_psp_txn_date , :hv_recon_date , :hv_report_date )\
 ; END ;";
sqlstm.iters = (unsigned int  )1;
sqlstm.offset = (unsigned int  )691;
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
sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_id;
sqlstm.sqhstl[1] = (unsigned long )12;
sqlstm.sqhsts[1] = (         int  )0;
sqlstm.sqindv[1] = (         short *)0;
sqlstm.sqinds[1] = (         int  )0;
sqlstm.sqharm[1] = (unsigned long )0;
sqlstm.sqadto[1] = (unsigned short )0;
sqlstm.sqtdso[1] = (unsigned short )0;
sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_ccy;
sqlstm.sqhstl[2] = (unsigned long )5;
sqlstm.sqhsts[2] = (         int  )0;
sqlstm.sqindv[2] = (         short *)0;
sqlstm.sqinds[2] = (         int  )0;
sqlstm.sqharm[2] = (unsigned long )0;
sqlstm.sqadto[2] = (unsigned short )0;
sqlstm.sqtdso[2] = (unsigned short )0;
sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_txn_date;
sqlstm.sqhstl[3] = (unsigned long )10;
sqlstm.sqhsts[3] = (         int  )0;
sqlstm.sqindv[3] = (         short *)0;
sqlstm.sqinds[3] = (         int  )0;
sqlstm.sqharm[3] = (unsigned long )0;
sqlstm.sqadto[3] = (unsigned short )0;
sqlstm.sqtdso[3] = (unsigned short )0;
sqlstm.sqhstv[4] = (unsigned char  *)&hv_recon_date;
sqlstm.sqhstl[4] = (unsigned long )10;
sqlstm.sqhsts[4] = (         int  )0;
sqlstm.sqindv[4] = (         short *)0;
sqlstm.sqinds[4] = (         int  )0;
sqlstm.sqharm[4] = (unsigned long )0;
sqlstm.sqadto[4] = (unsigned short )0;
sqlstm.sqtdso[4] = (unsigned short )0;
sqlstm.sqhstv[5] = (unsigned char  *)&hv_report_date;
sqlstm.sqhstl[5] = (unsigned long )10;
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
if (sqlca.sqlcode < 0) goto updatereconed_error;
}



DEBUGLOG(("UpdateReconedTxnPspDetail: RET = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
                return PD_OK;
        }


        if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("TxnPspDetail:UpdateReconedTxnPspDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateReconedTxnPspDetail: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }


        if (hv_return_value == SP_ERR) {
ERRLOG("TxnPspDetail:UpdateReconedTxnPspDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateReconedTxnPspDetail: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

        return PD_OK;

updatereconed_error:
DEBUGLOG(("updatereconed_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int GetTxnPspDetailByDlvId(const unsigned char* csDlvId,
				recordset_t* myRec)
{
	int	iRet = PD_ERR;

	hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getdtbydlvid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;
                /* varchar         hv_dlv_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_dlv_id;


                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_txn_id = -1;
                short           ind_dlv_id = -1;

                 SQL_CURSOR      c_cursor_pspdtbydlv;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_dlv_id.len = strlen((const char*)csDlvId);
        memcpy(hv_dlv_id.arr,csDlvId,hv_dlv_id.len);
DEBUGLOG(("GetTxnPspDetailByDlvId delivery_id = [%.*s]\n",hv_dlv_id.len,hv_dlv_id.arr));
        ind_dlv_id= 0;
	
	/* EXEC SQL ALLOCATE       :c_cursor_pspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )730;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getdtbydlvid_error;
}


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_psp_dt_getbydlvid(:hv_dlv_id:ind_dlv_id,
                                                                 :c_cursor_pspdtbydlv);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_psp_dt_getbydlvid (\
 :hv_dlv_id:ind_dlv_id , :c_cursor_pspdtbydlv ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )749;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_dlv_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_dlv_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&c_cursor_pspdtbydlv;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getdtbydlvid_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("GetTxnPspDetailByDlvId Found\n"));
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

			ind_txn_id= -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_pspdtbydlv
                        INTO
                                :v_txn_id:ind_txn_id; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 31;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )776;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdtbydlvid_error;
}



/* txn_id */
                        if (ind_txn_id >= 0) {
                                v_txn_id.arr[v_txn_id.len] = '\0';
                                PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailByDlvId txn_id = [%s]\n",v_txn_id.arr));
                        }

			iRet=PD_OK;
			RecordSet_Add(myRec,myHash);
		}

	}
	else{
DEBUGLOG(("GetTxnPspDetailByDlvId Not Found\n"));
	}

	/* EXEC SQL CLOSE :c_cursor_pspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )799;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getdtbydlvid_error;
}


	/* EXEC SQL FREE :c_cursor_pspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )818;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getdtbydlvid_error;
}



	return iRet; 

getdtbydlvid_error:
DEBUGLOG(("getdtbydlvid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_pspdtbydlv; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )837;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
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


	/* EXEC SQL FREE :c_cursor_pspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )856;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_pspdtbydlv;
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


int GetDatesByTxnId(const char *csTxnId, hash_t* hRls)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getdates_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_report_date;

		/* varchar		v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;


		short		ind_report_date = -1;
		short		ind_txn_date = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetDatesByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_getdates CURSOR FOR
		select 
			tp_report_date,
			tp_txn_date
		  from txn_psp_detail
		 where tp_txn_id = :hv_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_getdates; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )875;
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
        if (sqlca.sqlcode < 0) goto getdates_error;
}



        /* EXEC SQL FETCH c_cursor_getdates
        INTO
		:v_report_date:ind_report_date,
		:v_txn_date:ind_txn_date; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )894;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqfoff = (         int )0;
        sqlstm.sqfmod = (unsigned int )2;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_report_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_report_date;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_date;
        sqlstm.sqhstl[1] = (unsigned long )11;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_date;
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
        if (sqlca.sqlcode < 0) goto getdates_error;
}



        if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("GetDatesByTxnId Record Not Found\n"));
//		return PD_NOT_FOUND;
        }

/* report_date */
        if (ind_report_date  >=  0) { 
		v_report_date.arr[v_report_date.len] = '\0';
                PutField_CString(hRls,"report_date",(const char*)v_report_date.arr);
DEBUGLOG(("GetDatesByTxnId report_date = [%s]\n",v_report_date.arr));
	}

/* txn_date */
        if (ind_txn_date  >=  0) { 
		v_txn_date.arr[v_txn_date.len] = '\0';
                PutField_CString(hRls,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetDatesByTxnId txn_date = [%s]\n",v_txn_date.arr));
	}

        /* EXEC SQL CLOSE c_cursor_getdates; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )917;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdates_error;
}




DEBUGLOG(("GetDatesByTxnId Normal Exit\n")); 
        return  PD_OK;

getdates_error:
DEBUGLOG(("getdatesbytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdates; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )932;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int PspBalNullInTxnPspDtByAprvDate(const char *csAprvDate, recordset_t* myRec)
{
        int iCnt = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getpspbalnull_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_aprv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_aprv_date;


                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* aprv_date */
      	hv_aprv_date.len = strlen(csAprvDate);
      	memcpy(hv_aprv_date.arr, csAprvDate, hv_aprv_date.len);
DEBUGLOG(("PspBalNullInTxnPspDtByAprvDate: aprv_date = [%.*s]\n", hv_aprv_date.len, hv_aprv_date.arr));

        /* EXEC SQL DECLARE c_cursor_getpspbalnull CURSOR FOR
                select  th_txn_id
                from    txn_header,
                        txn_psp_detail
                where   th_txn_id = tp_txn_id
                and     th_approval_date is not null
                and     th_approval_date = :hv_aprv_date
		and     th_txn_code = 'DSI'
                and     th_status = 'C'
                and     th_ar_ind = 'A'
		and     (tp_bal is null
               		or	tp_total_float is null
                	or	tp_total_hold is null)
                order by th_approval_timestamp,
                         th_txn_id; */ 

        /* EXEC SQL OPEN c_cursor_getpspbalnull; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )947;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_aprv_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
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
        if (sqlca.sqlcode < 0) goto getpspbalnull_error;
}



        do {
                /* EXEC SQL FETCH c_cursor_getpspbalnull
                INTO
                        :v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )966;
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
                if (sqlca.sqlcode < 0) goto getpspbalnull_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

DEBUGLOG(("PspBalNullInTxnPspDtByAprvDate: found record\n"));

/* txn_seq */
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] ='\0';
                        PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("PspBalNullInTxnPspDtByAprvDate: txn_seq = [%s]\n",v_txn_id.arr));
                }

		iCnt++;

                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getpspbalnull; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )985;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getpspbalnull_error;
}



        if (iCnt > 0) {
DEBUGLOG(("PspBalNullInTxnPspDtByAprvDate: Found\n"));
                return FOUND;
        } else {
DEBUGLOG(("PspBalNullInTxnPspDtByAprvDate: Not Found\n"));
                return NOT_FOUND;
        }

getpspbalnull_error:
DEBUGLOG(("getpspbalnull_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnPspDetail_PspBalNullInTxnPspDtByAprvDate: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getpspbalnull; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1000;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int PspBalInTxnPspDetail(const char* csTxnSeq)
{
	int	iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO PspBalInTxnPspDetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		int             v_no_of_record;
		short           ind_no_of_record = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("PspBalInTxnPspDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL SELECT count (1)
                INTO	:v_no_of_record:ind_no_of_record
                FROM	txn_psp_detail
                WHERE   tp_txn_id = :hv_txn_id
                AND     tp_bal IS NOT NULL
                AND     tp_total_float IS NOT NULL
                AND     tp_total_hold IS NOT NULL
                ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_psp_detail W\
HERE tp_txn_id = :b2 AND tp_bal IS NOT NULL AND tp_total_float IS NOT NULL AN\
D tp_total_hold IS NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1015;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
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
        if (sqlca.sqlcode < 0) goto PspBalInTxnPspDetail_error;
}



	if(ind_no_of_record >= 0){
		if(v_no_of_record > 0){
			iRet = PD_TRUE;
		}
	}

	if(iRet == PD_TRUE){
DEBUGLOG((" psp balance information exists in txn_psp_detail\n"));
	}
	else{
DEBUGLOG((" psp balance information NOT exists in txn_psp_detail\n"));
	}

DEBUGLOG(("PspBalInTxnPspDetail iRet = [%d]\n", iRet));
	return iRet;

PspBalInTxnPspDetail_error:
DEBUGLOG(("PspBalInTxnPspDetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
