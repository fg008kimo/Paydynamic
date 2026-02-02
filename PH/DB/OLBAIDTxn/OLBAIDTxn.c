
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "OLBAIDTxn.pc"
};


static unsigned int sqlctx = 308875;


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
   unsigned char  *sqhstv[32];
   unsigned long  sqhstl[32];
            int   sqhsts[32];
            short *sqindv[32];
            int   sqinds[32];
   unsigned long  sqharm[32];
   unsigned long  *sqharc[32];
   unsigned short  sqadto[32];
   unsigned short  sqtdso[32];
} sqlstm = {12,32};

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
"SELECT OBT_ORG_TXN_ID , OBT_INPUT_CHANNEL , OBT_STATUS , OBT_AR_IND , OBT_S\
UB_STATUS , OBT_STAT_TXN_ID , OBT_TXN_CODE , OBT_PID , OBT_BAID , OBT_POSTING\
_DATE , OBT_TRANSMISSION_DATETIME , OBT_TXN_CCY , OBT_TXN_AMT , OBT_OPEN_BAL \
, OBT_CURR_BAL , OBT_DST_TXN_ID , OBT_BANK_CODE , OBT_BANK_ACCT_NUM , OBT_PID\
_TXN_HOLD_IND , OBT_PID_SYS_MATCH_IND , OBT_POSTED_IND , OBT_RECON_STATUS , O\
BT_CLASSIFIED_STATUS , OBT_HOLD_RECON , OBT_MANUAL_HOLD_RECON , OBT_EST_NET_A\
MOUNT FROM OL_BAID_TXN WHERE OBT_TXN_ID = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1115,0,6,361,0,0,32,32,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,
0,1,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,4,0,0,1,3,0,0,1,9,0,0,
148,0,0,2,517,0,9,533,0,2049,1,1,0,1,0,1,9,0,0,
167,0,0,2,0,0,13,535,0,0,26,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,3,0,0,2,1,0,0,2,1,0,0,2,3,0,0,2,3,0,
0,2,4,0,0,
286,0,0,2,0,0,15,714,0,0,0,0,0,1,0,
301,0,0,2,0,0,15,729,0,0,0,0,0,1,0,
316,0,0,3,0,0,17,902,0,0,1,1,0,1,0,1,9,0,0,
335,0,0,3,0,0,21,903,0,0,0,0,0,1,0,
350,0,0,3,0,0,17,1053,0,0,1,1,0,1,0,1,9,0,0,
369,0,0,3,0,0,21,1054,0,0,0,0,0,1,0,
384,0,0,4,108,0,4,1091,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
411,0,0,5,115,0,4,1133,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
438,0,0,6,112,0,4,1176,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
465,0,0,7,119,0,4,1218,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
492,0,0,8,387,0,4,1265,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
515,0,0,9,81,0,4,1313,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
538,0,0,10,0,0,17,1504,0,0,1,1,0,1,0,1,9,0,0,
557,0,0,10,0,0,45,1507,0,0,0,0,0,1,0,
572,0,0,10,0,0,13,1509,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,
599,0,0,10,0,0,15,1545,0,0,0,0,0,1,0,
614,0,0,10,0,0,15,1556,0,0,0,0,0,1,0,
629,0,0,11,144,0,4,1577,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
652,0,0,12,66,0,4,1618,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
675,0,0,13,0,0,17,1756,0,0,1,1,0,1,0,1,9,0,0,
694,0,0,13,0,0,45,1759,0,0,0,0,0,1,0,
709,0,0,13,0,0,13,1761,0,0,1,0,0,1,0,2,9,0,0,
728,0,0,13,0,0,15,1780,0,0,0,0,0,1,0,
743,0,0,13,0,0,15,1791,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/19              David Wong
Add MatchRespTxnNoWait                             2014/11/06              David Wong
Add CheckUnknownBaidTxn                            2014/12/11              Elvis Wong
Add recon and classified status			   2014/12/30		   LokMan Chow
Add new_txn_code for Update()                      2015/01/04              David Wong
Add hold_record & est_net_amount for GetBAIDTxn()  2015/01/19		   Dirk Wong
Add GetTxnIdForUpdate				   2015/01/22		   LokMan Chow
Modify GetSemiAutoReconBaidTxn()		   2015/09/08		   Elvis Wong	
Add Manual Hold Recon flag			   2015/09/08		   Dirk Wong
Add GetCountByBAID				   2016/08/09		   Dirk Wong
Add GetPayoutReconBaidTxn()                        2021/02/04              Michael Chow	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLBAIDTxn.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;

void OLBAIDTxn(char cdebug)
{
	cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char *csTmp;
	char cTmp;
	int iCommit = PD_TRUE;
	int iTmp;
	double dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short hv_return_value;

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar hv_org_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_txn_id;

		/* varchar hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		char hv_status;
		char hv_ar_ind;
		/* varchar hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		/* varchar hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

		/* varchar hv_org_voided_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_voided_txn_id;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar hv_pid[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_pid;

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_posting_date;

		/* varchar hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

		/* varchar hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		double hv_txn_amt;
		double hv_open_bal;
		double hv_curr_bal;
		/* varchar hv_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_approval_date;

		/* varchar hv_approval_timestamp[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_approval_timestamp;

		/* varchar hv_dst_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_dst_txn_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		int hv_pid_txn_hold_ind;
		int hv_pid_sys_match_ind;
		int hv_posted_ind;
		/* varchar hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		char	hv_recon_status;
		char	hv_classified_status;
		double hv_est_net_amount;
		int hv_hold_recon;
		/* varchar hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short ind_txn_id = -1;
		short ind_org_txn_id = -1;
		short ind_channel_code = -1;
		short ind_status = -1;
		short ind_ar_ind = -1;
		short ind_sub_status = -1;
		short ind_stat_txn_id = -1;
		short ind_org_voided_txn_id = -1;
		short ind_txn_code = -1;
		short ind_pid = -1;
		short ind_baid = -1;
		short ind_posting_date = -1;
		short ind_transmission_datetime = -1;
		short ind_txn_ccy = -1;
		short ind_txn_amt = -1;
		short ind_open_bal = -1;
		short ind_curr_bal = -1;
		short ind_approval_date = -1;
		short ind_approval_timestamp = -1;
		short ind_dst_txn_id = -1;
		short ind_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_pid_txn_hold_ind = -1;
		short ind_pid_sys_match_ind = -1;
		short ind_posted_ind = -1;
		short ind_remark = -1;
		short ind_recon_status = -1;
		short ind_classified_status = -1;
		short ind_est_net_amount = -1;
		short ind_hold_recon = -1;
		short ind_add_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_Int(hRls, "db_commit", &iCommit)) {
DEBUGLOG(("Add: db_commit = [%d]\n", iCommit));
	}

/* txn_seq */
	if (GetField_CString(hRls, "txn_seq", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));
	}

/* org_txn_seq */
	if (GetField_CString(hRls, "org_txn_seq", &csTmp)) {
		hv_org_txn_id.len = strlen(csTmp);
		memcpy(hv_org_txn_id.arr, csTmp, hv_org_txn_id.len);
		ind_org_txn_id = 0;
DEBUGLOG(("Add: org_txn_id = [%.*s]\n", hv_org_txn_id.len, hv_org_txn_id.arr));
	}

/* channel_code */
	if (GetField_CString(hRls, "channel_code", &csTmp)) {
		hv_channel_code.len = strlen(csTmp);
		memcpy(hv_channel_code.arr, csTmp, hv_channel_code.len);
		ind_channel_code = 0;
DEBUGLOG(("Add: channel_code = [%.*s]\n", hv_channel_code.len, hv_channel_code.arr));
	}

/* status */
	if (GetField_Char(hRls, "status", &cTmp)) {
		hv_status = cTmp;
		ind_status = 0;
DEBUGLOG(("Add: status = [%c]\n", hv_status));
	}

/* ar_ind */
	if (GetField_Char(hRls, "ar_ind", &cTmp)) {
		hv_ar_ind = cTmp;
		ind_ar_ind = 0;
DEBUGLOG(("Add: ar_ind = [%c]\n", hv_ar_ind));
	}

/* sub_status */
	if (GetField_CString(hRls, "sub_status", &csTmp)) {
		hv_sub_status.len = strlen(csTmp);
		memcpy(hv_sub_status.arr, csTmp, hv_sub_status.len);
		ind_sub_status = 0;
DEBUGLOG(("Add: sub_status = [%.*s]\n", hv_sub_status.len, hv_sub_status.arr));
	}

/* stat_txn_id */
	if (GetField_CString(hRls, "stat_txn_id", &csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		memcpy(hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("Add: stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));
	}

/* org_voided_txn_id */
	if (GetField_CString(hRls, "org_voided_txn_id", &csTmp)) {
		hv_org_voided_txn_id.len = strlen(csTmp);
		memcpy(hv_org_voided_txn_id.arr, csTmp, hv_org_voided_txn_id.len);
		ind_org_voided_txn_id = 0;
DEBUGLOG(("Add: org_voided_txn_id = [%.*s]\n", hv_org_voided_txn_id.len, hv_org_voided_txn_id.arr));
	}

/* txn_code */
	if (GetField_CString(hRls, "txn_code", &csTmp)) {
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr, csTmp, hv_txn_code.len);
		ind_txn_code = 0;
DEBUGLOG(("Add: txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));
	}

/* pid */
	if (GetField_CString(hRls, "pid", &csTmp)) {
		hv_pid.len = strlen(csTmp);
		memcpy(hv_pid.arr, csTmp, hv_pid.len);
		ind_pid = 0;
DEBUGLOG(("Add: pid = [%.*s]\n", hv_pid.len, hv_pid.arr));
	}

/* baid */
	if (GetField_CString(hRls, "baid", &csTmp)) {
		hv_baid.len = strlen(csTmp);
		memcpy(hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("Add: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
        }

/* posting_date */
	if (GetField_CString(hRls, "posting_date", &csTmp)) {
		hv_posting_date.len = strlen(csTmp);
		memcpy(hv_posting_date.arr, csTmp, hv_posting_date.len);
		ind_posting_date = 0;
DEBUGLOG(("Add: posting_date = [%.*s]\n", hv_posting_date.len, hv_posting_date.arr));
	}

/* transmission_datetime */
	if (GetField_CString(hRls, "transmission_datetime", &csTmp)) {
		hv_transmission_datetime.len = strlen(csTmp);
		memcpy(hv_transmission_datetime.arr, csTmp, hv_transmission_datetime.len);
		ind_transmission_datetime = 0;
DEBUGLOG(("Add: transmission_datetime = [%.*s]\n", hv_transmission_datetime.len, hv_transmission_datetime.arr));
	}

/* txn_ccy */
	if (GetField_CString(hRls, "txn_ccy", &csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		memcpy(hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("Add: txn_ccy = [%.*s]\n", hv_txn_ccy.len, hv_txn_ccy.arr));
	}

/* txn_amt */
	if (GetField_Double(hRls, "txn_amt", &dTmp)) {
		hv_txn_amt = dTmp;
		ind_txn_amt = 0;
DEBUGLOG(("Add: txn_amt = [%f]\n", hv_txn_amt));
	}

/* open_bal */
	if (GetField_Double(hRls, "open_bal", &dTmp)) {
		hv_open_bal = dTmp;
		ind_open_bal = 0;
DEBUGLOG(("Add: open_bal = [%f]\n", hv_open_bal));
	}

/* curr_bal */
	if (GetField_Double(hRls, "curr_bal", &dTmp)) {
		hv_curr_bal = dTmp;
		ind_curr_bal = 0;
DEBUGLOG(("Add: curr_bal = [%f]\n", hv_curr_bal));
	}

/* approval_date */
	if (GetField_CString(hRls, "approval_date", &csTmp)) {
		hv_approval_date.len = strlen(csTmp);
		memcpy(hv_approval_date.arr, csTmp, hv_approval_date.len);
		ind_approval_date = 0;
DEBUGLOG(("Add: approval_date = [%.*s]\n", hv_approval_date.len, hv_approval_date.arr));
	}

/* approval_timestamp */
	if (GetField_CString(hRls, "approval_timestamp", &csTmp)) {
		hv_approval_timestamp.len = strlen(csTmp);
		memcpy(hv_approval_timestamp.arr, csTmp, hv_approval_timestamp.len);
		ind_approval_timestamp = 0;
DEBUGLOG(("Add: approval_timestamp = [%.*s]\n", hv_approval_timestamp.len, hv_approval_timestamp.arr));
	}

/* dst_txn_id */
	if (GetField_CString(hRls, "dst_txn_id", &csTmp)) {
		hv_dst_txn_id.len = strlen(csTmp);
		memcpy(hv_dst_txn_id.arr, csTmp, hv_dst_txn_id.len);
		ind_dst_txn_id = 0;
DEBUGLOG(("Add: dst_txn_id = [%.*s]\n", hv_dst_txn_id.len, hv_dst_txn_id.arr));
	}

/* bank_code */
	if (GetField_CString(hRls, "bank_code", &csTmp)) {
		hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
		ind_bank_code = 0;
DEBUGLOG(("Add: bank_code = [%.*s]\n", hv_bank_code.len, hv_bank_code.arr));
	}

/* bank_acct_num */
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("Add: bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

/* pid_txn_hold_ind */
	if (GetField_Int(hRls, "pid_txn_hold_ind", &iTmp)) {
		hv_pid_txn_hold_ind = iTmp;
		ind_pid_txn_hold_ind = 0;
DEBUGLOG(("Add: pid_txn_hold_ind = [%d]\n", hv_pid_txn_hold_ind));
	}

/* pid_sys_match_ind */
	if (GetField_Int(hRls, "pid_sys_match_ind", &iTmp)) {
		hv_pid_sys_match_ind = iTmp;
		ind_pid_sys_match_ind = 0;
DEBUGLOG(("Add: pid_sys_match_ind = [%d]\n", hv_pid_sys_match_ind));
	}

/* posted_ind */
	if (GetField_Int(hRls, "posted_ind", &iTmp)) {
		hv_posted_ind = iTmp;
		ind_posted_ind = 0;
DEBUGLOG(("Add: posted_ind = [%d]\n", hv_posted_ind));
	}

/* remark */
	if (GetField_CString(hRls, "remark", &csTmp)) {
		hv_remark.len = strlen(csTmp);
		memcpy(hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("Add: remark = [%.*s]\n", hv_remark.len, hv_remark.arr));
	}

/* recon status */
	if (GetField_Char(hRls, "recon_status", &cTmp)) {
		hv_recon_status = cTmp;
		ind_recon_status = 0;
DEBUGLOG(("Add: recon_status = [%c]\n", hv_recon_status));
	}

/* classified_status */
	if (GetField_Char(hRls, "classified_status", &cTmp)) {
		hv_classified_status = cTmp;
		ind_classified_status = 0;
DEBUGLOG(("Add: classified_status = [%c]\n", hv_classified_status));
	}

/* est_net_amount */
	if (GetField_Double(hRls, "est_net_amount", &dTmp)) {
		hv_est_net_amount = dTmp;
		ind_est_net_amount = 0;
DEBUGLOG(("Add: est_net_amount = [%f]\n", hv_est_net_amount));
	}

/* hold_recon */
	if (GetField_Int(hRls, "hold_recon", &iTmp)) {
		hv_hold_recon = iTmp;
		ind_hold_recon = 0;
DEBUGLOG(("Add: hold_recon = [%d]\n", hv_hold_recon));
	}

/* add_user */
	if (GetField_CString(hRls, "add_user", &csTmp)) {
		hv_add_user.len = strlen(csTmp);
		memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
		ind_add_user = 0;
DEBUGLOG(("Add: add_user = [%.*s]\n", hv_add_user.len, hv_add_user.arr));
	}

	/* EXEC SQL EXECUTE
	BEGIN
		:hv_return_value := sp_ol_baid_txn_insert(
			:hv_txn_id:ind_txn_id,
			:hv_org_txn_id:ind_org_txn_id,
			:hv_channel_code:ind_channel_code,
			:hv_status:ind_status,
			:hv_ar_ind:ind_ar_ind,
			:hv_sub_status:ind_sub_status,
			:hv_stat_txn_id:ind_stat_txn_id,
			:hv_org_voided_txn_id:ind_org_voided_txn_id,
			:hv_txn_code:ind_txn_code,
			:hv_pid:ind_pid,
			:hv_baid:ind_baid,
			:hv_posting_date:ind_posting_date,
			:hv_transmission_datetime:ind_transmission_datetime,
			:hv_txn_ccy:ind_txn_ccy,
			:hv_txn_amt:ind_txn_amt,
			:hv_open_bal:ind_open_bal,
			:hv_curr_bal:ind_curr_bal,
			:hv_approval_date:ind_approval_date,
			:hv_approval_timestamp:ind_approval_timestamp,
			:hv_dst_txn_id:ind_dst_txn_id,
			:hv_bank_code:ind_bank_code,
			:hv_bank_acct_num:ind_bank_acct_num,
			:hv_pid_txn_hold_ind:ind_pid_txn_hold_ind,
			:hv_pid_sys_match_ind:ind_pid_sys_match_ind,
			:hv_posted_ind:ind_posted_ind,
			:hv_remark:ind_remark,
			:hv_recon_status:ind_recon_status,
			:hv_classified_status:ind_classified_status,
			:hv_est_net_amount:ind_est_net_amount,
			:hv_hold_recon:ind_hold_recon,
			:hv_add_user:ind_add_user,
			:hv_add_user:ind_add_user);

	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_baid_txn_insert ( :hv_txn_id:ind_txn_id \
, :hv_org_txn_id:ind_org_txn_id , :hv_channel_code:ind_channel_code , :hv_st\
atus:ind_status , :hv_ar_ind:ind_ar_ind , :hv_sub_status:ind_sub_status , :h\
v_stat_txn_id:ind_stat_txn_id , :hv_org_voided_txn_id:ind_org_voided_txn_id \
, :hv_txn_code:ind_txn_code , :hv_pid:ind_pid , :hv_baid:ind_baid , :hv_post\
ing_date:ind_posting_date , :hv_transmission_datetime:ind_transmission_datet\
ime , :hv_txn_ccy:ind_txn_ccy , :hv_txn_amt:ind_txn_amt , :hv_open_bal:ind_o\
pen_bal , :hv_curr_bal:ind_curr_bal , :hv_approval_date:ind_approval_date , \
:hv_approval_timestamp:ind_approval_timestamp , :hv_dst_txn_id:ind_dst_txn_i\
d , :hv_bank_code:ind_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :hv_\
pid_txn_hold_ind:ind_pid_txn_hold_ind , :hv_pid_sys_match_ind:ind_pid_sys_ma\
tch_ind , :hv_posted_ind:ind_posted_ind , :hv_remark:ind_remark , :hv_recon_\
status:ind_recon_status , :hv_classified_status:ind_classified_status , :hv_\
est_net_amount:ind_est_net_amount , :hv_");
 sqlstm.stmt = "hold_recon:ind_hold_recon , :hv_add_user:ind_add_user , :hv\
_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_channel_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_status;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ar_ind;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_sub_status;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_stat_txn_id;
 sqlstm.sqhstl[7] = (unsigned long )18;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_stat_txn_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_org_voided_txn_id;
 sqlstm.sqhstl[8] = (unsigned long )18;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_org_voided_txn_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_txn_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_pid;
 sqlstm.sqhstl[10] = (unsigned long )12;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_pid;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_baid;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_posting_date;
 sqlstm.sqhstl[12] = (unsigned long )10;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_posting_date;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_transmission_datetime;
 sqlstm.sqhstl[13] = (unsigned long )16;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_transmission_datetime;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[14] = (unsigned long )5;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_txn_amt;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_open_bal;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_open_bal;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_curr_bal;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_curr_bal;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_approval_date;
 sqlstm.sqhstl[18] = (unsigned long )10;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_approval_date;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_approval_timestamp;
 sqlstm.sqhstl[19] = (unsigned long )22;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_approval_timestamp;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_dst_txn_id;
 sqlstm.sqhstl[20] = (unsigned long )18;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_dst_txn_id;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[21] = (unsigned long )12;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_bank_code;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[22] = (unsigned long )52;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_pid_txn_hold_ind;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_pid_txn_hold_ind;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_pid_sys_match_ind;
 sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_pid_sys_match_ind;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_posted_ind;
 sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_posted_ind;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[26] = (unsigned long )257;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_remark;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_recon_status;
 sqlstm.sqhstl[27] = (unsigned long )1;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_recon_status;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_classified_status;
 sqlstm.sqhstl[28] = (unsigned long )1;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_classified_status;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_est_net_amount;
 sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_est_net_amount;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_hold_recon;
 sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_hold_recon;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[31] = (unsigned long )22;
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_add_user;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
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

	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add: Normal Exit\n"));
		if (iCommit == PD_TRUE)
			TxnCommit();
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("Transaction_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("Transaction_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBAIDTxn_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int GetBaidTxn(const char *csBaidTxnId,
				hash_t *hRec)
{
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbaidtxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_baid_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_baid_txn_id;


		/* varchar		v_org_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_org_txn_id;

		/* varchar		v_input_channel[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_input_channel;

		char		v_status;
		char		v_ar_ind;
		/* varchar		v_sub_status[PD_SUB_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		/* varchar		v_stat_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_stat_txn_id;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar		v_pid[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_pid;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;

		/* varchar		v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double		v_txn_amt;
		double		v_open_bal;
		double		v_curr_bal;
		/* varchar		v_dst_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_dst_txn_id;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		int		v_pid_txn_hold_ind;
		int		v_pid_sys_match_ind;
		int		v_posted_ind;
		char		v_recon_status;
		char		v_classified_status;
		int		v_hold_recon;
		int		v_manual_hold_recon;
		double		v_est_net_amount;

		short		ind_org_txn_id = -1;
		short		ind_input_channel = -1;
		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_sub_status = -1;
		short		ind_stat_txn_id = -1;
		short		ind_txn_code = -1;
		short		ind_pid = -1;
		short		ind_baid = -1;
		short		ind_posting_date = -1;
		short		ind_transmission_datetime = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_amt = -1;
		short		ind_open_bal = -1;
		short		ind_curr_bal = -1;
		short		ind_dst_txn_id = -1;
		short		ind_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_pid_txn_hold_ind = -1;
		short		ind_pid_sys_match_ind = -1;
		short		ind_posted_ind = -1;
		short		ind_recon_status = -1;
		short		ind_classified_status = -1;
		short		ind_hold_recon = -1;
		short		ind_manual_hold_recon = -1;
		short		ind_est_net_amount = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid_txn_id.len = strlen(csBaidTxnId);
	memcpy(hv_baid_txn_id.arr, csBaidTxnId, hv_baid_txn_id.len);
DEBUGLOG(("GetBaidTxn baid_txn_id = [%.*s]\n", hv_baid_txn_id.len, hv_baid_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getbaidtxn CURSOR FOR
		SELECT OBT_ORG_TXN_ID,
			OBT_INPUT_CHANNEL,
			OBT_STATUS,
			OBT_AR_IND,
			OBT_SUB_STATUS,
			OBT_STAT_TXN_ID,
			OBT_TXN_CODE,
			OBT_PID,
			OBT_BAID,
			OBT_POSTING_DATE,
			OBT_TRANSMISSION_DATETIME,
			OBT_TXN_CCY,
			OBT_TXN_AMT,
			OBT_OPEN_BAL,
			OBT_CURR_BAL,
			OBT_DST_TXN_ID,
			OBT_BANK_CODE,
			OBT_BANK_ACCT_NUM,
			OBT_PID_TXN_HOLD_IND,
			OBT_PID_SYS_MATCH_IND,
			OBT_POSTED_IND,
			OBT_RECON_STATUS,
			OBT_CLASSIFIED_STATUS,
			OBT_HOLD_RECON,
			OBT_MANUAL_HOLD_RECON,
			OBT_EST_NET_AMOUNT
		FROM OL_BAID_TXN
		WHERE OBT_TXN_ID = :hv_baid_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getbaidtxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )148;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid_txn_id;
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
 if (sqlca.sqlcode < 0) goto getbaidtxn_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getbaidtxn
		INTO
			:v_org_txn_id:ind_org_txn_id,
			:v_input_channel:ind_input_channel,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_sub_status:ind_sub_status,
			:v_stat_txn_id:ind_stat_txn_id,
			:v_txn_code:ind_txn_code,
			:v_pid:ind_pid,
			:v_baid:ind_baid,
			:v_posting_date:ind_posting_date,
			:v_transmission_datetime:ind_transmission_datetime,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amt:ind_txn_amt,
			:v_open_bal:ind_open_bal,
			:v_curr_bal:ind_curr_bal,
			:v_dst_txn_id:ind_dst_txn_id,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_pid_txn_hold_ind:ind_pid_txn_hold_ind,
			:v_pid_sys_match_ind:ind_pid_sys_match_ind,
			:v_posted_ind:ind_posted_ind,
			:v_recon_status:ind_recon_status,
			:v_classified_status:ind_classified_status,
			:v_hold_recon:ind_hold_recon,
			:v_manual_hold_recon:ind_manual_hold_recon,
			:v_est_net_amount:ind_est_net_amount; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 32;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )167;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_org_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_org_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_input_channel;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_input_channel;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_sub_status;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_stat_txn_id;
  sqlstm.sqhstl[5] = (unsigned long )19;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_code;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_pid;
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_pid;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_baid;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_posting_date;
  sqlstm.sqhstl[9] = (unsigned long )11;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_posting_date;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_transmission_datetime;
  sqlstm.sqhstl[10] = (unsigned long )17;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_transmission_datetime;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_open_bal;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_curr_bal;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_curr_bal;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_dst_txn_id;
  sqlstm.sqhstl[15] = (unsigned long )19;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_dst_txn_id;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[16] = (unsigned long )13;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_bank_code;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[17] = (unsigned long )53;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_pid_txn_hold_ind;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_pid_txn_hold_ind;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_pid_sys_match_ind;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_pid_sys_match_ind;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_posted_ind;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_posted_ind;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_recon_status;
  sqlstm.sqhstl[21] = (unsigned long )1;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_recon_status;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_classified_status;
  sqlstm.sqhstl[22] = (unsigned long )1;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_classified_status;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_hold_recon;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_hold_recon;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_manual_hold_recon;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_manual_hold_recon;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_est_net_amount;
  sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_est_net_amount;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getbaidtxn_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_org_txn_id >= 0) {
			v_org_txn_id.arr[v_org_txn_id.len] = '\0';
			PutField_CString(hRec, "org_txn_id", (const char*)v_org_txn_id.arr);
DEBUGLOG(("GetBaidTxn org_txn_id = [%s]\n", v_org_txn_id.arr));
		}

		if (ind_input_channel >= 0) {
			v_input_channel.arr[v_input_channel.len] = '\0';
			PutField_CString(hRec, "input_channel", (const char*)v_input_channel.arr);
DEBUGLOG(("GetBaidTxn input_channel = [%s]\n", v_input_channel.arr));
		}

		if (ind_status >= 0) {
			PutField_Char(hRec, "status", v_status);
DEBUGLOG(("GetBaidTxn status = [%c]\n", v_status));
		}

		if (ind_ar_ind >= 0) {
			PutField_Char(hRec, "ar_ind", v_ar_ind);
DEBUGLOG(("GetBaidTxn ar_ind = [%c]\n", v_ar_ind));
		}

		if (ind_sub_status >= 0) {
			v_sub_status.arr[v_sub_status.len] = '\0';
			PutField_CString(hRec, "sub_status", (const char*)v_sub_status.arr);
DEBUGLOG(("GetBaidTxn sub_status = [%s]\n", v_sub_status.arr));
		}

		if (ind_stat_txn_id >= 0) {
			v_stat_txn_id.arr[v_stat_txn_id.len] = '\0';
			PutField_CString(hRec, "stat_txn_id", (const char*)v_stat_txn_id.arr);
DEBUGLOG(("GetBaidTxn stat_txn_id = [%s]\n", v_stat_txn_id.arr));
		}

		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(hRec, "txn_code", (const char*)v_txn_code.arr);
DEBUGLOG(("GetBaidTxn txn_code = [%s]\n", v_txn_code.arr));
		}

		if (ind_pid >= 0) {
			v_pid.arr[v_pid.len] = '\0';
			PutField_CString(hRec, "pid", (const char*)v_pid.arr);
DEBUGLOG(("GetBaidTxn pid = [%s]\n", v_pid.arr));
		}

		if (ind_baid >= 0) {
			v_baid.arr[v_baid.len] = '\0';
			PutField_CString(hRec, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetBaidTxn baid = [%s]\n", v_baid.arr));
		}

		if (ind_posting_date >= 0) {
			v_posting_date.arr[v_posting_date.len] = '\0';
			PutField_CString(hRec, "posting_date", (const char*)v_posting_date.arr);
DEBUGLOG(("GetBaidTxn posting_date = [%s]\n", v_posting_date.arr));
		}

		if (ind_transmission_datetime >= 0) {
			v_transmission_datetime.arr[v_transmission_datetime.len] = '\0';
			PutField_CString(hRec, "transmission_datetime", (const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetBaidTxn transmission_datetime = [%s]\n", v_transmission_datetime.arr));
		}

		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(hRec, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("GetBaidTxn txn_ccy = [%s]\n", v_txn_ccy.arr));
		}

		if (ind_txn_amt >= 0) {
			PutField_Double(hRec, "txn_amt", v_txn_amt);
DEBUGLOG(("GetBaidTxn txn_amt = [%f]\n", v_txn_amt));
		}

		if (ind_open_bal >= 0) {
			PutField_Double(hRec, "open_bal", v_open_bal);
DEBUGLOG(("GetBaidTxn open_bal = [%f]\n", v_open_bal));
		}

		if (ind_curr_bal >= 0) {
			PutField_Double(hRec, "curr_bal", v_curr_bal);
DEBUGLOG(("GetBaidTxn curr_bal = [%f]\n", v_curr_bal));
		}

		if (ind_dst_txn_id >= 0) {
			v_dst_txn_id.arr[v_dst_txn_id.len] = '\0';
			PutField_CString(hRec, "dst_txn_id", (const char*)v_dst_txn_id.arr);
DEBUGLOG(("GetBaidTxn dst_txn_id = [%s]\n", v_dst_txn_id.arr));
		}

		if (ind_bank_code >= 0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			PutField_CString(hRec, "bank_code", (const char*)v_bank_code.arr);
DEBUGLOG(("GetBaidTxn bank_code = [%s]\n", v_bank_code.arr));
		}

		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(hRec, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetBaidTxn bank_acct_num = [%s]\n", v_bank_acct_num.arr));
		}

		if (ind_pid_txn_hold_ind >= 0) {
			PutField_Int(hRec, "pid_txn_hold_ind", v_pid_txn_hold_ind);
DEBUGLOG(("GetBaidTxn pid_txn_hold_ind = [%d]\n", v_pid_txn_hold_ind));
		}

		if (ind_pid_sys_match_ind >= 0) {
			PutField_Int(hRec, "pid_sys_match_ind", v_pid_sys_match_ind);
DEBUGLOG(("GetBaidTxn pid_sys_match_ind = [%d]\n", v_pid_sys_match_ind));
		}

		if (ind_posted_ind >= 0) {
			PutField_Int(hRec, "posted_ind", v_posted_ind);
DEBUGLOG(("GetBaidTxn posted_ind = [%d]\n", v_posted_ind));
		}
		if (ind_recon_status >= 0) {
			PutField_Char(hRec, "recon_status", v_recon_status);
DEBUGLOG(("GetBaidTxn recon_status = [%c]\n", v_recon_status));
		}
		if (ind_classified_status >= 0) {
			PutField_Char(hRec, "classified_status", v_classified_status);
DEBUGLOG(("GetBaidTxn classified_status = [%c]\n", v_classified_status));
		}

		if (ind_hold_recon >= 0) {
			PutField_Int(hRec, "hold_recon", v_hold_recon);
DEBUGLOG(("GetBaidTxn hold_recon = [%d]\n", v_hold_recon));
		}

		if (ind_manual_hold_recon >= 0) {
			PutField_Int(hRec, "manual_hold_recon", v_manual_hold_recon);
DEBUGLOG(("GetBaidTxn manual_hold_recon = [%d]\n", v_manual_hold_recon));
		}

		if (ind_est_net_amount >= 0) {
			PutField_Double(hRec, "est_net_amount", v_est_net_amount);
DEBUGLOG(("GetBaidTxn est_net_amount = [%f]\n",v_est_net_amount));
		}


	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbaidtxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )286;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaidtxn_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetBaidTxn Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetBaidTxn Normal Exit, Not Found\n"));
		return PD_ERR;
	}

getbaidtxn_error:
DEBUGLOG(("getbaidtxn_error code %d\n", sqlca.sqlcode));
ERRLOG("OLBAIDTxn::getbaidtxn_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbaidtxn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )301;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int Update(const hash_t *hRls)
{
	char *csTxnId;
	char *csTmp;
	char cTmp;
	int iTmp;
	double dTmp;
	char *csBuf;
	csBuf = (char*) malloc (128);

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	strcpy((char*)hv_dynstmt.arr, "update ol_baid_txn set obt_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls, "txn_seq", &csTxnId);
DEBUGLOG(("Update: txn_id = [%s]\n", csTxnId));

	// update_user
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// dst_txn_id
	if (GetField_CString(hRls, "dst_txn_id", &csTmp)) {
DEBUGLOG(("Update: dst_txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_dst_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// pid_txn_hold_ind
	if (GetField_Int(hRls, "pid_txn_hold_ind", &iTmp)) {
DEBUGLOG(("Update: pid_txn_hold_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_pid_txn_hold_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// pid_sys_match_ind
	if (GetField_Int(hRls, "pid_sys_match_ind", &iTmp)) {
DEBUGLOG(("Update: pid_sys_match_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_pid_sys_match_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// posted_ind
	if (GetField_Int(hRls, "posted_ind", &iTmp)) {
DEBUGLOG(("Update: posted_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_posted_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// status
	if (GetField_Char(hRls, "status", &cTmp)) {
DEBUGLOG(("Update: status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// ar ind
	if (GetField_Char(hRls, "ar_ind", &cTmp)) {
DEBUGLOG(("Update: ar_ind = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_ar_ind = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// sub_status
	if (GetField_CString(hRls, "sub_status", &csTmp)) {
DEBUGLOG(("Update: sub_status = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_sub_status = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// remark
	if (GetField_CString(hRls, "remark", &csTmp)) {
DEBUGLOG(("Update: remark = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", obt_remark = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	// recon_status
	if (GetField_Char(hRls, "recon_status", &cTmp)) {
DEBUGLOG(("Update: recon_status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_recon_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// classified_status
	if (GetField_Char(hRls, "classified_status", &cTmp)) {
DEBUGLOG(("Update: classified_status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_classified_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// new_txn_code
	if (GetField_CString(hRls, "new_txn_code", &csTmp)) {
DEBUGLOG(("Update: new_txn_code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_txn_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// hold_recon
	if (GetField_Int(hRls, "hold_recon", &iTmp)) {
DEBUGLOG(("Update: hold_recon = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_hold_recon = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// manual_hold_recon
	if (GetField_Int(hRls, "manual_hold_recon", &iTmp)) {
DEBUGLOG(("Update: manual_hold_recon = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_manual_hold_recon = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// est_net_amount
	if (GetField_Double(hRls, "est_net_amount", &dTmp)) {
DEBUGLOG(("Update: est_net_amount = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_est_net_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " where obt_txn_id = '");
	strcat((char *)hv_dynstmt.arr, csTxnId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )316;
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
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )335;
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

ERRLOG("OLBAIDTxn_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int UpdateByDstTxnSeq(const hash_t *hRls)
{
	char *csTxnId;
	char *csTmp;
	char cTmp;
	int iTmp;
	char *csBuf;
	csBuf = (char*) malloc (128);

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateByDstTxnSeq: Begin\n"));
	strcpy((char*)hv_dynstmt.arr, "update ol_baid_txn set obt_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls, "txn_seq", &csTxnId);
DEBUGLOG(("UpdateByDstTxnSeq: txn_id = [%s]\n", csTxnId));

	// update_user
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// dst_txn_id
	if (GetField_CString(hRls, "dst_txn_id", &csTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: dst_txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_dst_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// pid_txn_hold_ind
	if (GetField_Int(hRls, "pid_txn_hold_ind", &iTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: pid_txn_hold_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_pid_txn_hold_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// pid_sys_match_ind
	if (GetField_Int(hRls, "pid_sys_match_ind", &iTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: pid_sys_match_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_pid_sys_match_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// posted_ind
	if (GetField_Int(hRls, "posted_ind", &iTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: posted_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_posted_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// status
	if (GetField_Char(hRls, "status", &cTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// ar ind
	if (GetField_Char(hRls, "ar_ind", &cTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: ar_ind = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_ar_ind = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// sub_status
	if (GetField_CString(hRls, "sub_status", &csTmp)) {
DEBUGLOG(("UpdateByDstTxnSeq: sub_status = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_sub_status = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// recon_status
	if (GetField_Char(hRls, "recon_status", &cTmp)) {
DEBUGLOG(("Update: recon_status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_recon_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// classified_status
	if (GetField_Char(hRls, "classified_status", &cTmp)) {
DEBUGLOG(("Update: classified_status = [%c]\n", cTmp));
		sprintf(csBuf, "%c", cTmp);
		strcat((char*)hv_dynstmt.arr, ", obt_classified_status = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


	// new_txn_code
	if (GetField_CString(hRls, "new_txn_code", &csTmp)) {
DEBUGLOG(("Update: new_txn_code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", obt_txn_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " where obt_dst_txn_id = '");
	strcat((char *)hv_dynstmt.arr, csTxnId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )350;
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
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )369;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("UpdateByDstTxnSeq Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLBAIDTxn_UpdateByDstTxnSeq: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateByDstTxnSeq: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int MatchRespTxn(const char* csTxnSeq,
					const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		/* varchar v_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;

		short ind_date = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("MatchRespTxn txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchRespTxn status = [%c]\n", hv_status));

	/* EXEC SQL SELECT obt_posting_date
			INTO :v_date:ind_date
			FROM ol_baid_txn
			WHERE obt_txn_id = :hv_txn_id
			AND obt_status = :hv_status
			FOR UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obt_posting_date INTO :b0:b1 FROM ol_baid_txn WHERE \
obt_txn_id = :b2 AND obt_status = :b3 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )384;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_date;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchRespTxn_error;
}



	if (ind_date >= 0) {
DEBUGLOG(("MatchRespTxn Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchRespTxn Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchRespTxn_error:
DEBUGLOG(("MatchRespTxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchRespTxnNoWait(const char* csTxnSeq,
					const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnNoWait_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		/* varchar v_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;

		short ind_date = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("MatchRespTxnNoWait txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchRespTxnNoWait status = [%c]\n", hv_status));

	/* EXEC SQL SELECT obt_posting_date
			INTO :v_date:ind_date
			FROM ol_baid_txn
			WHERE obt_txn_id = :hv_txn_id
			AND obt_status = :hv_status
			FOR UPDATE NOWAIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obt_posting_date INTO :b0:b1 FROM ol_baid_txn WHERE \
obt_txn_id = :b2 AND obt_status = :b3 FOR UPDATE NOWAIT ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )411;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_date;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchRespTxnNoWait_error;
}



	if (ind_date >= 0) {
DEBUGLOG(("MatchRespTxnNoWait Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchRespTxnNoWait Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchRespTxnNoWait_error:
DEBUGLOG(("MatchRespTxnNoWait_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int MatchRespTxnByDstTxnSeq(const char* csTxnSeq,
					const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnByDstTxnSeq_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		/* varchar v_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;

		short ind_date = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("MatchRespTxnByDstTxnSeq txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchRespTxnByDstTxnSeq status = [%c]\n", hv_status));

	/* EXEC SQL SELECT obt_posting_date
			INTO :v_date:ind_date
			FROM ol_baid_txn
			WHERE obt_dst_txn_id = :hv_txn_id
			AND obt_status = :hv_status
			FOR UPDATE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obt_posting_date INTO :b0:b1 FROM ol_baid_txn WHERE \
obt_dst_txn_id = :b2 AND obt_status = :b3 FOR UPDATE ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )438;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_date;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchRespTxnByDstTxnSeq_error;
}



	if (ind_date >= 0) {
DEBUGLOG(("MatchRespTxnByDstTxnSeq Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchRespTxnByDstTxnSeq Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchRespTxnByDstTxnSeq_error:
DEBUGLOG(("MatchRespTxnByDstTxnSeq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchRespTxnByDstTxnSeqNoWait(const char* csTxnSeq,
					const char cStatus)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnByDstTxnSeqNoWait_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		/* varchar v_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;

		short ind_date = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("MatchRespTxnByDstTxnSeqNoWait txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("MatchRespTxnByDstTxnSeqNoWait status = [%c]\n", hv_status));

	/* EXEC SQL SELECT obt_posting_date
			INTO :v_date:ind_date
			FROM ol_baid_txn
			WHERE obt_dst_txn_id = :hv_txn_id
			AND obt_status = :hv_status
			FOR UPDATE NOWAIT; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obt_posting_date INTO :b0:b1 FROM ol_baid_txn WHERE \
obt_dst_txn_id = :b2 AND obt_status = :b3 FOR UPDATE NOWAIT ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )465;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
 sqlstm.sqhstl[0] = (unsigned long )11;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_date;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto MatchRespTxnByDstTxnSeqNoWait_error;
}



	if (ind_date >= 0) {
DEBUGLOG(("MatchRespTxnByDstTxnSeqNoWait Found\n"));
		return PD_FOUND;
	} else {
DEBUGLOG(("MatchRespTxnByDstTxnSeqNoWait Not Found\n"));
		return PD_NOT_FOUND;
	}

MatchRespTxnByDstTxnSeqNoWait_error:
DEBUGLOG(("MatchRespTxnByDstTxnSeqNoWait_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int CheckUnknownBaidTxn(const hash_t* hRls)
{
	int iRet = PD_NOT_FOUND;

	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkunknownbaidtxn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		short	ind_baid = -1;

		int	v_cnt;
		short	ind_cnt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


// baid
	if (GetField_CString(hRls, "baid", &csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, sizeof(hv_baid.arr));
		ind_baid = 0;
DEBUGLOG(("CheckUnknownBaidTxn:: baid = [%.*s](%d)\n", sizeof(hv_baid.arr), hv_baid.arr, hv_baid.len));
	}

	/* EXEC SQL
		SELECT	COUNT(*)
		INTO	:v_cnt:ind_cnt
		FROM	OL_BAID_TXN OBT,
			OL_PSP_DETAIL OPD,
			OL_BAID_TXN_CODE_MAPPING OBTM
		WHERE	OBT.OBT_BAID = :hv_baid:ind_baid
		AND	OBT.OBT_STATUS = 'C'
		AND	OBT.OBT_AR_IND = 'A'
		AND	OPD.OPD_PSP_ID = OBT.OBT_PID
		AND	OPD.OPD_DISABLED = 0
		AND	OBTM.OBTM_BANK_ACCT_TYPE = OPD.OPD_BANK_ACCT_TYPE
		AND	OBTM.OBTM_CODE = OBT.OBT_TXN_CODE
		AND	OBTM.OBTM_REAL_TIME_POST = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select COUNT ( * ) INTO :b0:b1 FROM OL_BAID_TXN OBT , OL_PS\
P_DETAIL OPD , OL_BAID_TXN_CODE_MAPPING OBTM WHERE OBT . OBT_BAID = :b2:b3 AN\
D OBT . OBT_STATUS = 'C' AND OBT . OBT_AR_IND = 'A' AND OPD . OPD_PSP_ID = OB\
T . OBT_PID AND OPD . OPD_DISABLED = 0 AND OBTM . OBTM_BANK_ACCT_TYPE = OPD .\
 OPD_BANK_ACCT_TYPE AND OBTM . OBTM_CODE = OBT . OBT_TXN_CODE AND OBTM . OBTM\
_REAL_TIME_POST = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )492;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid;
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
 if (sqlca.sqlcode < 0) goto checkunknownbaidtxn_error;
}



	if (ind_cnt >= 0) {
		if (v_cnt > 0) {
DEBUGLOG(("CheckUnknownBaidTxn:: FOUND\n"));
			iRet = PD_FOUND;
		}
	}

DEBUGLOG(("CheckUnknownBaidTxn() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

checkunknownbaidtxn_error:
DEBUGLOG(("checkunknownbaidtxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetTxnIdForUpdate(const char* csTxnId) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdate txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL select obt_txn_id
                into :v_txn_id:ind_txn_id
                from ol_baid_txn
                where obt_txn_id = :hv_txn_id
                for update; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obt_txn_id into :b0:b1 from ol_baid_txn where obt_tx\
n_id = :b2 for update ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )515;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 if (sqlca.sqlcode < 0) goto gettxnidforupdate_error;
}



	if (ind_txn_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

gettxnidforupdate_error:
DEBUGLOG(("gettxnidforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetSemiAutoReconBaidTxn(const hash_t* hRls, recordset_t* myRec) {
	int iRet = PD_OK;

	hash_t *myHash;

	char cSRInd; // sender or recipient
	char cCSTsInd; // create or statement timestamp
	char *csTmp;
	double dTmp;
	char *csBuf;
	csBuf = (char*) malloc (128);

	/* EXEC SQL WHENEVER SQLERROR GOTO get_sar_baid_txn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		double v_est_net_amt;

		short ind_txn_id = -1;
		short ind_baid = -1;
		short ind_est_net_amt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetSemiAutoReconBaidTxn: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "select obt_txn_id, obt_baid, obt_est_net_amount \
from ol_baid_txn, ol_bank_acct_id, ol_psp_detail, ol_statement_detail \
where obt_input_channel = 'OMT' \
and obt_status = 'C' \
and obt_ar_ind = 'A' \
and obt_sub_status = '118' \
and obt_recon_status = 'U' \
and obt_classified_status = 'U' \
and obt_hold_recon <> 2 \
and nvl(obt_manual_hold_recon, 0) not in (1, 9) \
and obt_baid = obai_baid \
and obai_status = 'O' \
and obai_psp_id = opd_psp_id \
and opd_disabled = 0 \
and opd_status = 'O' \
and obt_stat_txn_id = olsd_stat_txn_id \
and obt_txn_id not in (select owrc_baid_txn_id_1 from ol_wait_recon_cfm_list) \
and obt_txn_id not in (select owrc_baid_txn_id_2 from ol_wait_recon_cfm_list)");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	// sender / recipient indicator
	if (GetField_Char(hRls, "s_r_ind", &cSRInd)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: s_r_ind = [%c]\n", cSRInd));
		if (cSRInd == 'S') {
			strcat((char*)hv_dynstmt.arr, " and obt_txn_code in ('UBD', 'USO')");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		} else if (cSRInd == 'R') {
			strcat((char*)hv_dynstmt.arr, " and obt_txn_code in ('UBC', 'USI')");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

	// create timestamp / statement timestamp
	if (GetField_CString(hRls, "create_ts_from", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: create_ts_from = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and obt_create_timestamp >= to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		if (GetField_CString(hRls, "create_ts_to", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: create_ts_to = [%s]\n", csTmp));
			strcat((char*)hv_dynstmt.arr, " and obt_create_timestamp < to_date('");
			strcat((char*)hv_dynstmt.arr, csTmp);
			strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

		cCSTsInd = 'C';
	} else if (GetField_CString(hRls, "stmt_ts_from", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: stmt_ts_from = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and olsd_statement_timestamp >= to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		if (GetField_CString(hRls, "stmt_ts_to", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: stmt_ts_to = [%s]\n", csTmp));
			strcat((char*)hv_dynstmt.arr, " and olsd_statement_timestamp < to_date('");
			strcat((char*)hv_dynstmt.arr, csTmp);
			strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

		cCSTsInd = 'S';
	}

	// provider id
	if (GetField_CString(hRls, "provider_id", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: provider_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and opd_client_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// psp id
	if (GetField_CString(hRls, "pid", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: pid = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and obai_psp_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// transaction amount
	// note: use obt_est_net_amount for sender
	if (GetField_CString(hRls, "txn_amt", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: txn_amt = [%s]\n", csTmp));
		if (cSRInd == 'S') {
			strcat((char*)hv_dynstmt.arr, " and obt_est_net_amount = ");
			strcat((char*)hv_dynstmt.arr, csTmp);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		} else {
			strcat((char*)hv_dynstmt.arr, " and obt_txn_amt = ");
			strcat((char*)hv_dynstmt.arr, csTmp);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

	// diff baid
	if (GetField_CString(hRls, "diff_baid", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: diff_baid = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and obt_baid <> '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// same baid
	if (GetField_CString(hRls, "same_baid", &csTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: same_baid = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and obt_baid = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	// net_amt
	if (cSRInd == 'R') {
		if (GetField_Double(hRls, "net_amt", &dTmp)) {
DEBUGLOG(("GetSemiAutoReconBaidTxn: net_amt = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, " and obt_txn_amt = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

	// order by
	if (cCSTsInd == 'C') {
		strcat((char*)hv_dynstmt.arr, " order by obt_create_timestamp asc");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	} else {
		strcat((char*)hv_dynstmt.arr, " order by olsd_statement_timestamp asc");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

DEBUGLOG(("GetSemiAutoReconBaidTxn: [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE s_get_sar_baid_txn FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )538;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )16394;
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
 if (sqlca.sqlcode < 0) goto get_sar_baid_txn_error;
}


	/* EXEC SQL DECLARE c_get_sar_baid_txn CURSOR FOR s_get_sar_baid_txn; */ 


	/* EXEC SQL OPEN c_get_sar_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )557;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_sar_baid_txn_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_get_sar_baid_txn
		INTO	:v_txn_id:ind_txn_id,
				:v_baid:ind_baid,
				:v_est_net_amt:ind_est_net_amt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 32;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )572;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_est_net_amt;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_est_net_amt;
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
  if (sqlca.sqlcode < 0) goto get_sar_baid_txn_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// txn_id
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash, "txn_id", (const char*)v_txn_id.arr);
DEBUGLOG(("GetSemiAutoReconBaidTxn: txn_id = [%s]\n", (const char*)v_txn_id.arr));
		}

		// baid
		if (ind_baid >= 0) {
			v_baid.arr[v_baid.len] = '\0';
			PutField_CString(myHash, "baid", (const char*)v_baid.arr);
DEBUGLOG(("GetSemiAutoReconBaidTxn: baid = [%s]\n", (const char*)v_baid.arr));
		}

		// net_amt
		if (cSRInd == 'S') {
			if (ind_est_net_amt >= 0) {
				PutField_Double(myHash, "net_amt", v_est_net_amt);
DEBUGLOG(("GetSemiAutoReconBaidTxn: net_amt = [%f]\n", v_est_net_amt));
			}
		}

		RecordSet_Add(myRec, myHash);
	}
	/* EXEC SQL CLOSE c_get_sar_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )599;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_sar_baid_txn_error;
}



DEBUGLOG(("GetSemiAutoReconBaidTxn Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

get_sar_baid_txn_error:
DEBUGLOG(("get_sar_baid_txn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDTxn get_sar_baid_txn_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_get_sar_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )614;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int GetBaidTxnIdByStatTxnId(const char* csStatTxnId, char* csBaidTxnId)
{
	int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO getbaidtxnidbystattxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_stat_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_stat_txn_id;

                /* varchar v_baid_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_baid_txn_id;

                short ind_baid_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_stat_txn_id.len = strlen(csStatTxnId);
        memcpy(hv_stat_txn_id.arr, csStatTxnId, hv_stat_txn_id.len);
DEBUGLOG(("GetBaidTxnIdByStatTxnId stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));

        /* EXEC SQL SELECT obt_txn_id
                        INTO :v_baid_txn_id:ind_baid_txn_id
                        FROM ol_baid_txn
                        WHERE obt_stat_txn_id = :hv_stat_txn_id
                        AND obt_status = 'C'
			AND obt_ar_ind = 'A'
			AND obt_sub_status = '118'; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 32;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select obt_txn_id INTO :b0:b1 FROM ol_baid_txn WHERE\
 obt_stat_txn_id = :b2 AND obt_status = 'C' AND obt_ar_ind = 'A' AND obt_sub_\
status = '118' ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )629;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_baid_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_baid_txn_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_stat_txn_id;
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
        if (sqlca.sqlcode < 0) goto getbaidtxnidbystattxnid_error;
}



	if (ind_baid_txn_id >= 0) {
		v_baid_txn_id.arr[v_baid_txn_id.len] = '\0';
DEBUGLOG(("GetBaidTxnIdByStatTxnId: baid_txn_id = [%s]\n", (const char*)v_baid_txn_id.arr));
		strcpy(csBaidTxnId, (const char*)v_baid_txn_id.arr);
	}

DEBUGLOG(("GetBaidTxnIdByStatTxnId Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getbaidtxnidbystattxnid_error:
DEBUGLOG(("getbaidtxnidbystattxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetCountByBAID(const char* csBAID)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getcountbybaid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                int     v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
        strncpy((char*)hv_baid.arr,csBAID,hv_baid.len);
DEBUGLOG(("GetCountByBAID baid = [%s]\n",csBAID));

        /* EXEC SQL        SELECT	count(*)
			INTO	:v_cnt
			FROM	ol_baid_txn
			WHERE	obt_baid = :hv_baid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 32;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_baid_txn WHERE o\
bt_baid = :b1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )652;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[1] = (unsigned long )22;
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
        if (sqlca.sqlcode < 0) goto getcountbybaid_error;
}



DEBUGLOG(("GetCountByBAID() Normal Exit! record found = [%d]\n", v_cnt));
        return v_cnt;

getcountbybaid_error:
DEBUGLOG(("getcountbybaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetPayoutReconBaidTxn(const hash_t* hRls, recordset_t* myRec) 
{
	int iRet = PD_OK;

	hash_t *myHash;

	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_prm_baid_txn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		/* varchar v_baid_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_baid_txn_id;


		short ind_baid_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetPayoutReconBaidTxn: Begin\n"));


	strcpy((char*)hv_dynstmt.arr, "select baid_txn_obt.obt_txn_id \
from ol_baid_txn baid_txn_obt \
left join ol_stmt_match_config \
on baid_txn_obt.obt_bank_code = osmc_int_bank_code \
and osmc_bank_acct_type = 'POA' \
and osmc_txn_code = 'OPG' \
and osmc_code = 'MATCH_CLIENT_NAME' \
and osmc_disabled = 0, \
ol_psp_detail baid_txn_opd, \
ol_statement_detail baid_txn_olsd, \
ol_txn_header psp_txn_oth, \
ol_txn_psp_detail psp_txn_otp, \
ol_psp_detail psp_txn_opd, \
ol_bank_acct_id psp_txn_obai, \
ol_payout_generated_file_dt gen_file_dt \
where 1 = 1 \
and baid_txn_obt.obt_pid = baid_txn_opd.opd_psp_id \
and baid_txn_obt.obt_txn_ccy = baid_txn_opd.opd_currency_id \
and baid_txn_opd.opd_disabled = 0 \
and baid_txn_opd.opd_status = 'O' \
and baid_txn_obt.obt_stat_txn_id = baid_txn_olsd.olsd_stat_txn_id \
and baid_txn_obt.obt_txn_code in ('UBD','USO') \
and baid_txn_obt.obt_recon_status = 'U' \
and psp_txn_oth.oth_txn_id = psp_txn_otp.otp_txn_id \
and psp_txn_otp.otp_psp_id = psp_txn_opd.opd_psp_id \
and psp_txn_otp.otp_txn_ccy = psp_txn_opd.opd_currency_id \
and psp_txn_opd.opd_disabled = 0 \
and psp_txn_opd.opd_status = 'O' \
and psp_txn_otp.otp_baid = psp_txn_obai.obai_baid \
and baid_txn_obt.obt_status = 'C' \
and baid_txn_obt.obt_ar_ind = 'A' \
and nvl(baid_txn_obt.obt_manual_hold_recon, 0) = 0 \
and psp_txn_otp.otp_tracking_txn_id = gen_file_dt.ofd_txn_id \
and ( \
(nvl(trim(osmc_val), '0') = '1' and baid_txn_olsd.olsd_sender_name = gen_file_dt.ofd_account_name) \
or \
nvl(trim(osmc_val), '0') = '0' \
) \
and baid_txn_obt.obt_input_channel = 'OMT' \
and baid_txn_opd.opd_client_id = psp_txn_opd.opd_client_id \
and baid_txn_opd.opd_bank_acct_type = psp_txn_opd.opd_bank_acct_type \
and baid_txn_obt.obt_txn_amt - 0.000000 = psp_txn_oth.oth_display_amount \
and baid_txn_obt.obt_txn_id not in (select owpc_baid_txn_id from ol_wait_payout_recon_cfm_list)");


/*
and baid_txn_opd.opd_psp_id = 'P9000220'
and psp_txn_opd.opd_psp_id = 'P9000220'
and psp_txn_oth.oth_txn_id = 'U000000000597898'
and psp_txn_oth.oth_approval_timestamp <= baid_txn_olsd.olsd_statement_timestamp + 0 
and psp_txn_oth.oth_approval_timestamp >= baid_txn_olsd.olsd_statement_timestamp - 4 
order by baid_txn_olsd.olsd_statement_timestamp asc");
*/


	// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
DEBUGLOG(("GetPayoutReconBaidTxn: psp_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and baid_txn_opd.opd_psp_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		strcat((char*)hv_dynstmt.arr, " and psp_txn_opd.opd_psp_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	// psp_txn_id
	if (GetField_CString(hRls, "psp_txn_id", &csTmp)) {
DEBUGLOG(("GetPayoutReconBaidTxn: psp_txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and psp_txn_oth.oth_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	
	// prev_stmt_date_diff
	if (GetField_CString(hRls, "prev_stmt_date_diff", &csTmp)) {
DEBUGLOG(("GetPayoutReconBaidTxn: prev_stmt_date_diff = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	// next_stmt_date_diff
	if (GetField_CString(hRls, "next_stmt_date_diff", &csTmp)) {
DEBUGLOG(("GetPayoutReconBaidTxn: next_stmt_date_diff = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and ");
		strcat((char*)hv_dynstmt.arr, csTmp);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
 
	// order by
	strcat((char*)hv_dynstmt.arr, " order by baid_txn_olsd.olsd_statement_timestamp asc");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		

DEBUGLOG(("GetPayoutReconBaidTxn: [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE s_get_prm_baid_txn FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )675;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )16394;
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
 if (sqlca.sqlcode < 0) goto get_prm_baid_txn_error;
}


	/* EXEC SQL DECLARE c_get_prm_baid_txn CURSOR FOR s_get_prm_baid_txn; */ 


	/* EXEC SQL OPEN c_get_prm_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )694;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_prm_baid_txn_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_get_prm_baid_txn
		INTO	:v_baid_txn_id:ind_baid_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 32;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )709;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_baid_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_baid_txn_id;
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
  if (sqlca.sqlcode < 0) goto get_prm_baid_txn_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// baid_txn_id
		if (ind_baid_txn_id >= 0) {
			v_baid_txn_id.arr[v_baid_txn_id.len] = '\0';
			PutField_CString(myHash, "baid_txn_id", (const char*)v_baid_txn_id.arr);
DEBUGLOG(("GetPayoutReconBaidTxn: baid_txn_id = [%s]\n", (const char*)v_baid_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	/* EXEC SQL CLOSE c_get_prm_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )728;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_prm_baid_txn_error;
}



DEBUGLOG(("GetPayoutReconBaidTxn Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

get_prm_baid_txn_error:
DEBUGLOG(("get_prm_baid_txn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDTxn get_prm_baid_txn_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_get_prm_baid_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 32;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )743;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;

}


