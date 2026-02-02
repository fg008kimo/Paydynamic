
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
    "OLTxnPspDetail.pc"
};


static unsigned int sqlctx = 10410027;


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
   unsigned char  *sqhstv[30];
   unsigned long  sqhstl[30];
            int   sqhsts[30];
            short *sqindv[30];
            int   sqinds[30];
   unsigned long  sqharm[30];
   unsigned long  *sqharc[30];
   unsigned short  sqadto[30];
   unsigned short  sqtdso[30];
} sqlstm = {12,30};

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
"select otp_psp_id , otp_baid , otp_txn_ccy , otp_txn_amount , otp_txn_date \
, otp_txn_time , to_char ( otp_txn_timestamp , 'yyyymmddhh24miss' ) , otp_ban\
k_code , otp_bank_acct_num , otp_cost , otp_open_bal , otp_total_hold , otp_b\
al , otp_prepaid , otp_open_in_transit , otp_in_transit , otp_pending_fund , \
otp_txn_hold_ind , otp_sys_match_ind , otp_customer_text , otp_sender_name , \
otp_txn_ref_num , otp_charge_rule_id , otp_charge_period_type , otp_pre_cal_c\
harge , otp_grp_tracking_txn_id , otp_tracking_txn_id , otp_report_date , otp\
_settlement_date , otp_manual_hold_recon from ol_txn_psp_detail where otp_txn\
_id = :b0            ";

 static char *sq0006 = 
"select otp_txn_id , otp_psp_id , otp_txn_ccy , otp_txn_amount , otp_txn_dat\
e , otp_txn_time , to_char ( otp_txn_timestamp , 'yyyymmddhh24miss' ) , otp_b\
ank_code , otp_bank_acct_num , otp_cost , otp_open_bal , otp_total_hold , otp\
_bal , otp_prepaid , otp_open_in_transit , otp_in_transit , otp_pending_fund \
, otp_txn_hold_ind , otp_sys_match_ind , otp_customer_text , otp_sender_name \
, otp_txn_ref_num , otp_charge_rule_id , otp_charge_period_type , otp_pre_cal\
_charge , otp_grp_tracking_txn_id , otp_tracking_txn_id , otp_report_date , o\
tp_settlement_date , otp_manual_hold_recon from ol_txn_psp_detail where otp_b\
aid = :b0 order by otp_create_timestamp            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1031,0,6,387,0,0,30,30,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,4,0,
0,1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
140,0,0,2,0,0,17,810,0,0,1,1,0,1,0,1,9,0,0,
159,0,0,2,0,0,21,811,0,0,0,0,0,1,0,
174,0,0,3,635,0,9,942,0,2049,1,1,0,1,0,1,9,0,0,
193,0,0,3,0,0,13,944,0,0,30,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,1,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
328,0,0,3,0,0,15,1182,0,0,0,0,0,1,0,
343,0,0,3,0,0,15,1196,0,0,0,0,0,1,0,
358,0,0,4,297,0,6,1304,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,2,9,0,0,
409,0,0,0,0,0,56,1380,0,0,1,1,0,1,0,3,102,0,0,
428,0,0,5,144,0,6,1381,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
459,0,0,0,0,0,13,1398,0,0,2,1,0,1,0,1,102,0,0,2,9,0,0,
482,0,0,0,0,0,15,1417,0,0,1,1,0,1,0,1,102,0,0,
501,0,0,0,0,0,78,1418,0,0,1,1,0,1,0,3,102,0,0,
520,0,0,0,0,0,15,1426,0,0,1,1,0,1,0,1,102,0,0,
539,0,0,0,0,0,78,1427,0,0,1,1,0,1,0,3,102,0,0,
558,0,0,6,665,0,9,1548,0,2049,1,1,0,1,0,1,9,0,0,
577,0,0,6,0,0,13,1550,0,0,30,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,3,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,1,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
712,0,0,6,0,0,15,1791,0,0,0,0,0,1,0,
727,0,0,6,0,0,15,1805,0,0,0,0,0,1,0,
742,0,0,7,105,0,4,1831,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
769,0,0,8,0,0,17,1931,0,0,1,1,0,1,0,1,9,0,0,
788,0,0,8,0,0,45,1934,0,0,0,0,0,1,0,
803,0,0,8,0,0,13,1936,0,0,1,0,0,1,0,2,9,0,0,
822,0,0,8,0,0,15,1955,0,0,0,0,0,1,0,
837,0,0,8,0,0,15,1966,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/09              David Wong
Add GetDepositTxnToHold                            2014/03/03              Stan Poon
Add 5 new fields				   2014/12/29		   Dirk Wong
Add report_date                                    2014/12/29              Virginia Yun
Add delivery_id                                    2015/01/13              Virginia Yun
Get psp precal charge info			   2014/01/23		   LokMan Chow
Add Grp Tracking and Tracking Txn ID               2015/02/25              Virginia Yun
Add Settlement Date                                2015/03/26              Virginia Yun
Add GetTxnPspDetailByBAID                          2015/06/25              David Wong
Add Manual Hold Recon Flag			   2015/09/08		   Dirk Wong
Add GetTxnCountByBankAcct			   2016/08/09		   Dirk Wong
Add BOOLBalance(IsUpdatePayoutTempBAIDBal)         2019/05/30              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTxnPspDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;
OBJPTR(BO);


void OLTxnPspDetail(char cdebug)
{
	cDebug = cdebug;
}


int perr01(const char *msg) {
	ERRLOG("Error occured when %s\n", msg);
	ERRLOG("{\n");
	ERRLOG(" sqlcaid = %s\n", sqlca.sqlcaid);
	ERRLOG(" sqlabc = %d\n", sqlca.sqlabc);
	ERRLOG(" sqlcode = %d\n", sqlca.sqlcode);
	ERRLOG(" sqlerrm.sqlerrml = %d\n", sqlca.sqlerrm.sqlerrml);
	ERRLOG(" sqlerrm.sqlerrmc = %s\n", sqlca.sqlerrm.sqlerrmc);
	ERRLOG(" sqlerrp = %s\n", sqlca.sqlerrp);
	ERRLOG(" sqlerrd = %d\n", sqlca.sqlerrd);
	ERRLOG(" sqlwarn = %s\n", sqlca.sqlwarn);
	ERRLOG(" sqlext = %s\n", sqlca.sqlext);
	ERRLOG("}\n");
	return 1;
}


int Add(const hash_t *hRls)
{
	char *csBAID;
	char *csTmp;
	char cTmp;
	double dTmp;
	int iTmp;
	int iIsUpdatePOTempBAIDBal = PD_TRUE;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short hv_return_value;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		double		hv_txn_amount;
		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_txn_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_txn_time;

		/* varchar		hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		double		hv_cost;
		double		hv_open_bal;
		double		hv_total_hold;
		double		hv_bal;
		double		hv_prepaid;
		double		hv_open_in_transit;
		double		hv_in_transit;
		double		hv_pending_fund;
		int		hv_txn_hold_ind;
		int		hv_sys_match_ind;
		/* varchar		hv_customer_text[PD_TFR_CUSTOMER_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_customer_text;

		/* varchar		hv_sender_name[PD_SENDER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_sender_name;

		/* varchar		hv_txn_ref_num[PD_TXN_REF_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[200]; } hv_txn_ref_num;

		char		hv_charge_period_type;
		double		hv_pre_cal_charge;
		int		hv_charge_txn_created;
		int		hv_charge_rule_id;
		/* varchar		hv_charge_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_charge_txn_id;

		/* varchar		hv_report_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_report_date;

		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short		ind_txn_id = -1;
		short		ind_psp_id = -1;
		short		ind_baid = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_amount = -1;
		short		ind_txn_date = -1;
		short		ind_txn_time = -1;
		short		ind_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_cost = -1;
		short		ind_open_bal = -1;
		short		ind_total_hold = -1;
		short		ind_bal = -1;
		short		ind_prepaid = -1;
		short		ind_open_in_transit = -1;
		short		ind_in_transit = -1;
		short		ind_pending_fund = -1;
		short		ind_txn_hold_ind = -1;
		short		ind_sys_match_ind = -1;
		short		ind_customer_text = -1;
		short		ind_sender_name = -1;
		short		ind_txn_ref_num = -1;
		short		ind_charge_period_type = -1;
		short		ind_pre_cal_charge = -1;
		short		ind_charge_txn_created = -1;
		short		ind_charge_rule_id = -1;
		short		ind_charge_txn_id = -1;
		short		ind_report_date = -1;
		short		ind_add_user = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

// txn_seq
	if (GetField_CString(hRls, "txn_seq", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%.*s][%d]\n", hv_txn_id.len, hv_txn_id.arr, hv_txn_id.len));
	}

// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
		hv_psp_id.len = strlen(csTmp);
		memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
DEBUGLOG(("Add: psp_id = [%.*s][%d]\n", hv_psp_id.len, hv_psp_id.arr, hv_psp_id.len));
	}

// baid
	if (GetField_CString(hRls, "baid", &csBAID)) {
		hv_baid.len = strlen(csBAID);
		memcpy(hv_baid.arr, csBAID, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("Add: baid = [%.*s][%d]\n", hv_baid.len, hv_baid.arr, hv_baid.len));

		// Is Update Payout Temp BAID Bal
                BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
                iIsUpdatePOTempBAIDBal = ((unsigned long)(*BOObjPtr)(csBAID));
DEBUGLOG(("Add: iIsUpdatePOTempBAIDBal = [%d]\n", iIsUpdatePOTempBAIDBal));
	}

// txn_ccy
	if (GetField_CString(hRls, "txn_ccy", &csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		memcpy(hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("Add: txn_ccy = [%.*s][%d]\n", hv_txn_ccy.len, hv_txn_ccy.arr, hv_txn_ccy.len));
	}

// txn_amount
	if (GetField_Double(hRls, "txn_amount", &dTmp)) {
		hv_txn_amount = dTmp;
		ind_txn_amount = 0;
DEBUGLOG(("Add: txn_amount = [%f]\n", hv_txn_amount));
	}

// txn_date
	if (GetField_CString(hRls, "txn_date", &csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("Add: txn_date = [%.*s][%d]\n", hv_txn_date.len, hv_txn_date.arr, hv_txn_date.len));
	}

// txn_time
	if (GetField_CString(hRls, "txn_time", &csTmp)) {
		hv_txn_time.len = strlen(csTmp);
		memcpy(hv_txn_time.arr, csTmp, hv_txn_time.len);
		ind_txn_time = 0;
DEBUGLOG(("Add: txn_time = [%.*s][%d]\n", hv_txn_time.len, hv_txn_time.arr, hv_txn_time.len));
	}

// bank_code
	if (GetField_CString(hRls, "bank_code", &csTmp)) {
		hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
		ind_bank_code = 0;
DEBUGLOG(("Add: bank_code = [%.*s][%d]\n", hv_bank_code.len, hv_bank_code.arr, hv_bank_code.len));
	}

// bank_acct_num
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("Add: bank_acct_num = [%.*s][%d]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr, hv_bank_acct_num.len));
	}

// cost
	hv_cost = 0;
	ind_cost = 0;
	if (GetField_Double(hRls, "cost", &dTmp)) {
		hv_cost = dTmp;
DEBUGLOG(("Add: cost = [%f]\n", hv_cost));
	}

	if (iIsUpdatePOTempBAIDBal == PD_TRUE) {

// bal
                hv_bal = 0;
                ind_bal = 0;
                if (GetField_Double(hRls, "bal", &dTmp)) {
                        hv_bal = dTmp;
                        ind_bal = 0;
DEBUGLOG(("Add: bal = [%f]\n", hv_bal));
                }

// total_hold
		hv_total_hold = 0;
		ind_total_hold = 0;
		if (GetField_Double(hRls, "total_hold", &dTmp)) {
			hv_total_hold = dTmp;
			ind_total_hold = 0;
DEBUGLOG(("Add: total_hold = [%f]\n", hv_total_hold));
		}

// open_bal
		hv_open_bal = 0;
                ind_open_bal = 0;
                if (GetField_Double(hRls, "open_bal", &dTmp)) {
                        hv_open_bal = dTmp;
                        ind_open_bal = 0;
DEBUGLOG(("Add: open_bal = [%f]\n", hv_open_bal));
                }

// prepaid
		hv_prepaid = 0;
		ind_prepaid = 0;
		if (GetField_Double(hRls, "prepaid", &dTmp)) {
			hv_prepaid = dTmp;
			ind_prepaid = 0;
DEBUGLOG(("Add: prepaid = [%f]\n", hv_prepaid));
		}

// open_in_transit
		hv_open_in_transit = 0;
		ind_open_in_transit = 0;
		if (GetField_Double(hRls, "open_in_transit", &dTmp)) {
			hv_open_in_transit = dTmp;
			ind_open_in_transit = 0;
DEBUGLOG(("Add: open_in_transit = [%f]\n", hv_open_in_transit));
		}

// in_transit
		hv_in_transit = 0;
		ind_in_transit = 0;
		if (GetField_Double(hRls, "in_transit", &dTmp)) {
			hv_in_transit = dTmp;
			ind_in_transit = 0;
DEBUGLOG(("Add: in_transit = [%f]\n", hv_in_transit));
		}

// pending_fund
		hv_pending_fund = 0;
		ind_pending_fund = 0;
		if (GetField_Double(hRls, "pending_fund", &dTmp)) {
			hv_pending_fund = dTmp;
			ind_pending_fund = 0;
DEBUGLOG(("Add: pending_fund = [%f]\n", hv_pending_fund));
		}
	}

// txn_hold_ind
	hv_txn_hold_ind = 0;
	ind_txn_hold_ind = 0;
	if (GetField_Int(hRls, "txn_hold_ind", &iTmp)) {
		hv_txn_hold_ind = iTmp;
		ind_txn_hold_ind = 0;
DEBUGLOG(("Add: txn_hold_ind = [%d]\n", hv_txn_hold_ind));
	}


// sys_match_ind
	hv_sys_match_ind = 0;
	ind_sys_match_ind = 0;
	if (GetField_Int(hRls, "sys_match_ind", &iTmp)) {
		hv_sys_match_ind = iTmp;
		ind_sys_match_ind = 0;
DEBUGLOG(("Add: sys_match_ind = [%d]\n", hv_sys_match_ind));
	}

// customer_text
	if (GetField_CString(hRls, "customer_text", &csTmp)) {
		hv_customer_text.len = strlen(csTmp);
		memcpy(hv_customer_text.arr, csTmp, hv_customer_text.len);
		ind_customer_text = 0;
DEBUGLOG(("Add: customer_text = [%.*s][%d]\n", hv_customer_text.len, hv_customer_text.arr, hv_customer_text.len));
	}

// sender_name
	if (GetField_CString(hRls, "sender_name", &csTmp)) {
		hv_sender_name.len = strlen(csTmp);
		memcpy(hv_sender_name.arr, csTmp, hv_sender_name.len);
		ind_sender_name = 0;
DEBUGLOG(("Add: sender_name = [%.*s][%d]\n", hv_sender_name.len, hv_sender_name.arr, hv_sender_name.len));
	}

// txn_ref_num
	if (GetField_CString(hRls, "txn_ref_num", &csTmp)) {
		hv_txn_ref_num.len = strlen(csTmp);
		memcpy(hv_txn_ref_num.arr, csTmp, hv_txn_ref_num.len);
		ind_txn_ref_num = 0;
DEBUGLOG(("Add: txn_ref_num = [%.*s][%d]\n", hv_txn_ref_num.len, hv_txn_ref_num.arr, hv_txn_ref_num.len));
	}

// charge_period_type
	if (GetField_Char(hRls, "charge_period_type", &cTmp)) {
		hv_charge_period_type = cTmp;
		ind_charge_period_type = 0;
DEBUGLOG(("Add: charge_period_type = [%c]\n",hv_charge_period_type));
	}

// pre_cal_charge
	if (GetField_Double(hRls, "pre_cal_charge", &dTmp)) {
		hv_pre_cal_charge = dTmp;
		ind_pre_cal_charge = 0;
DEBUGLOG(("Add: pre_cal_charge = [%f]\n",hv_pre_cal_charge));
	}

// charge_txn_created
	if (GetField_Int(hRls, "charge_txn_created", &iTmp)) {
		hv_charge_txn_created = iTmp;
		ind_charge_txn_created = 0;
DEBUGLOG(("Add: charge_txn_created = [%d]\n",hv_charge_txn_created));
	}

// charge_rule_id
	if (GetField_Int(hRls, "charge_rule_id",&iTmp)) {
		hv_charge_rule_id = iTmp;
		ind_charge_rule_id = 0;
DEBUGLOG(("Add: charge_rule_id = [%d]\n",hv_charge_rule_id));
	}

// charge_txn_id
	if (GetField_CString(hRls,"charge_txn_id",&csTmp)) {
		hv_charge_txn_id.len = strlen(csTmp);
		memcpy(hv_charge_txn_id.arr,csTmp,hv_charge_txn_id.len);
		ind_charge_txn_id = 0;
DEBUGLOG(("Add: charge_txn_id = [%.*s][%d]\n",hv_charge_txn_id.len,hv_charge_txn_id.arr,hv_charge_txn_id.len));
	}

// report_date
	if (GetField_CString(hRls,"report_date",&csTmp)) {
		hv_report_date.len = strlen(csTmp);
		memcpy(hv_report_date.arr,csTmp,hv_report_date.len);
		ind_report_date = 0;
DEBUGLOG(("Add: report_date = [%.*s][%d]\n",hv_report_date.len,hv_report_date.arr,hv_report_date.len));
	}

// add_user
	if (GetField_CString(hRls, "add_user", &csTmp)) {
		hv_add_user.len = strlen(csTmp);
		memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
		ind_add_user = 0;
DEBUGLOG(("Add: add_user = [%.*s]\n", hv_add_user.len, hv_add_user.arr));
	}

	FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_psp_detail_insert(
									:hv_txn_id:ind_txn_id,
									:hv_psp_id:ind_psp_id,
									:hv_baid:ind_baid,
									:hv_txn_ccy:ind_txn_ccy,
									:hv_txn_amount:ind_txn_amount,
									:hv_txn_date:ind_txn_date,
									:hv_txn_time:ind_txn_time,
									:hv_bank_code:ind_bank_code,
									:hv_bank_acct_num:ind_bank_acct_num,
									:hv_cost:ind_cost,
									:hv_open_bal:ind_open_bal,
									:hv_total_hold:ind_total_hold,
									:hv_bal:ind_bal,
									:hv_prepaid:ind_prepaid,
									:hv_open_in_transit:ind_open_in_transit,
									:hv_in_transit:ind_in_transit,
									:hv_pending_fund:ind_pending_fund,
									:hv_txn_hold_ind:ind_txn_hold_ind,
									:hv_sys_match_ind:ind_sys_match_ind,
									:hv_customer_text:ind_customer_text,
									:hv_sender_name:ind_sender_name,
									:hv_txn_ref_num:ind_txn_ref_num,
									:hv_charge_period_type:ind_charge_period_type,
									:hv_pre_cal_charge:ind_pre_cal_charge,
									:hv_charge_txn_created:ind_charge_txn_created,
									:hv_charge_rule_id:ind_charge_rule_id,
									:hv_charge_txn_id:ind_charge_txn_id,
									:hv_report_date:ind_report_date,
									:hv_add_user:ind_add_user,
									:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_txn_psp_detail_insert ( :hv_txn_id:ind_t\
xn_id , :hv_psp_id:ind_psp_id , :hv_baid:ind_baid , :hv_txn_ccy:ind_txn_ccy \
, :hv_txn_amount:ind_txn_amount , :hv_txn_date:ind_txn_date , :hv_txn_time:i\
nd_txn_time , :hv_bank_code:ind_bank_code , :hv_bank_acct_num:ind_bank_acct_\
num , :hv_cost:ind_cost , :hv_open_bal:ind_open_bal , :hv_total_hold:ind_tot\
al_hold , :hv_bal:ind_bal , :hv_prepaid:ind_prepaid , :hv_open_in_transit:in\
d_open_in_transit , :hv_in_transit:ind_in_transit , :hv_pending_fund:ind_pen\
ding_fund , :hv_txn_hold_ind:ind_txn_hold_ind , :hv_sys_match_ind:ind_sys_ma\
tch_ind , :hv_customer_text:ind_customer_text , :hv_sender_name:ind_sender_n\
ame , :hv_txn_ref_num:ind_txn_ref_num , :hv_charge_period_type:ind_charge_pe\
riod_type , :hv_pre_cal_charge:ind_pre_cal_charge , :hv_charge_txn_created:i\
nd_charge_txn_created , :hv_charge_rule_id:ind_charge_rule_id , :hv_charge_t\
xn_id:ind_charge_txn_id , :hv_report_date:ind_report_date , :hv_add_user:ind\
_add_user , :hv_add_user:ind");
 sqlstm.stmt = "_add_user ) ; END ;";
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_baid;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_amount;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_amount;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[6] = (unsigned long )10;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_date;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_time;
 sqlstm.sqhstl[7] = (unsigned long )8;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_time;
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
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[9] = (unsigned long )52;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_cost;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_cost;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_open_bal;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_open_bal;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_total_hold;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_total_hold;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_bal;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_bal;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_prepaid;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_prepaid;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_open_in_transit;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_open_in_transit;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_in_transit;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_in_transit;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_pending_fund;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_pending_fund;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_txn_hold_ind;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_txn_hold_ind;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_sys_match_ind;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_sys_match_ind;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_customer_text;
 sqlstm.sqhstl[20] = (unsigned long )202;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_customer_text;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_sender_name;
 sqlstm.sqhstl[21] = (unsigned long )202;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_sender_name;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_txn_ref_num;
 sqlstm.sqhstl[22] = (unsigned long )202;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_txn_ref_num;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_charge_period_type;
 sqlstm.sqhstl[23] = (unsigned long )1;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_charge_period_type;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_pre_cal_charge;
 sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_pre_cal_charge;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_charge_txn_created;
 sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_charge_txn_created;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_charge_rule_id;
 sqlstm.sqhstl[26] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_charge_rule_id;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_charge_txn_id;
 sqlstm.sqhstl[27] = (unsigned long )18;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_charge_txn_id;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[28] = (unsigned long )10;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_report_date;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[29] = (unsigned long )22;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_add_user;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
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
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLTxnPspDetail_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLTxnPspDetail_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTxnPspDetail_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
perr01("Add_oltxnpspdetail");
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int Update(const hash_t *hRls)
{
	char *csTmp;
	char *csTmp2;
	char cTmp;
	double dTmp;
	int iTmp;
	char *csBuf;
	char *csTxnId;
	char *csBAID;
	int iIsUpdatePOTempBAIDBal = PD_TRUE;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr, "update ol_txn_psp_detail set otp_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls, "txn_seq", &csTxnId);
DEBUGLOG(("Update: txn_id = [%s]\n", csTxnId));

// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
DEBUGLOG(("Update: psp_id = [%s]\n", csTmp));
                strcat((char*)hv_dynstmt.arr, ", otp_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

// baid
	if (GetField_CString(hRls, "baid", &csBAID)) {
DEBUGLOG(("Update: baid = [%s]\n", csBAID));
		strcat((char*)hv_dynstmt.arr, ", otp_baid = '");
                strcat((char*)hv_dynstmt.arr, csBAID);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		// Is Update Payout Temp BAID Bal
                BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
                iIsUpdatePOTempBAIDBal = ((unsigned long)(*BOObjPtr)(csBAID));
DEBUGLOG(("Update: iIsUpdatePOTempBAIDBal = [%d]\n", iIsUpdatePOTempBAIDBal));
	}

// txn_ccy
	if (GetField_CString(hRls, "txn_ccy", &csTmp)) {
DEBUGLOG(("Update: txn_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_txn_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// txn_amount
	if (GetField_Double(hRls, "txn_amount", &dTmp)) {
DEBUGLOG(("Update: txn_amt = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_txn_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// txn_date
	if (GetField_CString(hRls, "txn_date", &csTmp)) {
DEBUGLOG(("Update: txn_date = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_txn_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// txn_time
	if (GetField_CString(hRls, "txn_time", &csTmp)) {
DEBUGLOG(("Update: txn_time = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_txn_time = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// txn_timestamp
	// if (GetField_CString(hRls, "txn_date", &csTmp) && GetField_CString(hRls, "txn_time", &csTmp2)) {
	if (GetField_CString(hRls, "txn_date", &csTmp)) {
DEBUGLOG(("Update: txn_timestamp = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_txn_timestamp = to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		if (GetField_CString(hRls, "txn_time", &csTmp2)) {
DEBUGLOG(("Update: txn_timestamp = [%s%s]\n", csTmp, csTmp2));
			strcat((char*)hv_dynstmt.arr, csTmp2);
		}
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// bank_code
	if (GetField_CString(hRls, "bank_code", &csTmp)) {
DEBUGLOG(("Update: bank_code = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_bank_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// bank_acct_num
	if (GetField_CString(hRls, "bank_acct_num", &csTmp)) {
DEBUGLOG(("Update: bank_acct_num = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_bank_acct_num = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// cost
	if (GetField_Double(hRls, "cost", &dTmp)) {
DEBUGLOG(("Update: cost = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_cost = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	if (iIsUpdatePOTempBAIDBal == PD_TRUE) {

// open_bal
		if (GetField_Double(hRls, "open_bal", &dTmp)) {
DEBUGLOG(("Update: open_bal = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_open_bal = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// total_hold
		if (GetField_Double(hRls, "total_hold", &dTmp)) {
DEBUGLOG(("Update: total_hold = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_total_hold = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// bal
		if (GetField_Double(hRls, "bal", &dTmp)) {
DEBUGLOG(("Update: bal = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_bal = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// prepaid
		if (GetField_Double(hRls, "prepaid", &dTmp)) {
DEBUGLOG(("Update: prepaid = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_prepaid = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// open_in_transit
		if (GetField_Double(hRls, "open_in_transit", &dTmp)) {
DEBUGLOG(("Update: open_in_transit = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_open_in_transit = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// in_transit
		if (GetField_Double(hRls, "in_transit", &dTmp)) {
DEBUGLOG(("Update: in_transit = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_in_transit = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}

// pending_fund
		if (GetField_Double(hRls, "pending_fund", &dTmp)) {
DEBUGLOG(("Update: pending_fund = [%lf]\n", dTmp));
			sprintf(csBuf, "%f", dTmp);
			strcat((char*)hv_dynstmt.arr, ", otp_pending_fund = ");
			strcat((char*)hv_dynstmt.arr, csBuf);
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

// txn_hold_ind
	if (GetField_Int(hRls, "txn_hold_ind", &iTmp)) {
DEBUGLOG(("Update: txn_hold_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_txn_hold_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// sys_match_ind
	if (GetField_Int(hRls, "sys_match_ind", &iTmp)) {
DEBUGLOG(("Update: sys_match_ind = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_sys_match_ind = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// customer_text
	if (GetField_CString(hRls, "customer_text", &csTmp)) {
DEBUGLOG(("Update: customer_text = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_customer_text = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// sender_name
	if (GetField_CString(hRls, "sender_name", &csTmp)) {
DEBUGLOG(("Update: sender_name = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_sender_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// txn_ref_num
	if (GetField_CString(hRls, "txn_ref_num", &csTmp)) {
DEBUGLOG(("Update: txn_ref_num = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_txn_ref_num = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// charge_period_type
	if (GetField_Char(hRls, "charge_period_type", &cTmp)) {
DEBUGLOG(("Update: charge_period_type = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",otp_charge_period_type = '");
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// pre_cal_charge
	if (GetField_Double(hRls, "pre_cal_charge", &dTmp)) {
DEBUGLOG(("Update: pre_cal_charge = [%lf]\n",dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_pre_cal_charge = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// charge_txn_created
	if (GetField_Int(hRls, "charge_txn_created", &iTmp)) {
DEBUGLOG(("Update: charge_txn_created = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_charge_txn_created = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// charge_rule_id
	if (GetField_Int(hRls, "charge_rule_id", &iTmp)) {
DEBUGLOG(("Update: charge_rule_id = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_charge_rule_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// charge_period_type
	if (GetField_CString(hRls, "charge_txn_id", &csTmp)) {
DEBUGLOG(("Update: charge_txn_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_charge_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// report_date
	if (GetField_CString(hRls, "report_date", &csTmp)) {
DEBUGLOG(("Update: report_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_report_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* delivery id */
        if (GetField_CString(hRls,"delivery_id",&csTmp)) {
DEBUGLOG(("Update: delivery_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",otp_delivery_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Grp Tracking Txn id */
        if (GetField_CString(hRls,"grp_tracking_txn_seq", &csTmp)) {
DEBUGLOG(("Update: grp_tracking_txn_seq = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",otp_grp_tracking_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* Tracking Txn id */
        if (GetField_CString(hRls,"tracking_txn_seq", &csTmp)) {
DEBUGLOG(("Update: tracking_txn_seq = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",otp_tracking_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* Settlement Date */
	if (GetField_CString(hRls, "settlement_date", &csTmp)) {
DEBUGLOG(("Update: settlement_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_settlement_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// manual_hold_recon
	if (GetField_Int(hRls, "manual_hold_recon", &iTmp)) {
DEBUGLOG(("Update: manual_hold_recon = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", otp_manual_hold_recon = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}



// update user
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", otp_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " where otp_txn_id = '");
	strcat((char*)hv_dynstmt.arr, csTxnId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )140;
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
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )159;
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

ERRLOG("OLTxnPspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int GetTxnPspDetail(const char *csTxnID, hash_t *myHash)
{
	int iCnt=0;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnpspdetail_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_baid[PD_BAID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_baid;

		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double		v_txn_amount;
		/* varchar		v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar		v_txn_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_txn_time;

		/* varchar		v_txn_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_timestamp;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		double		v_cost;
		double		v_open_bal;
		double		v_total_hold;
		double		v_bal;
		double		v_prepaid;
		double		v_open_in_transit;
		double		v_in_transit;
		double		v_pending_fund;
		int		v_txn_hold_ind;
		int		v_sys_match_ind;
		/* varchar		v_customer_text[PD_TFR_CUSTOMER_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_customer_text;

		/* varchar		v_sender_name[PD_SENDER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_sender_name;

		/* varchar		v_txn_ref_num[PD_TXN_REF_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_txn_ref_num;

		int		v_charge_rule_id;
		char		v_charge_period_type;
		double		v_precal_charge;
		/* varchar		v_grp_tracking_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_grp_tracking_txn_id;

		/* varchar		v_tracking_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_tracking_txn_id;

		/* varchar		v_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_report_date;

		/* varchar		v_settlement_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_settlement_date;

		int		v_manual_hold_recon;


		short		ind_psp_id = -1;
		short		ind_baid = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_amount = -1;
		short		ind_txn_date = -1;
		short		ind_txn_time = -1;
		short		ind_txn_timestamp = -1;
		short		ind_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_cost = -1;
		short		ind_open_bal = -1;
		short		ind_total_hold = -1;
		short		ind_bal = -1;
		short		ind_prepaid = -1;
		short		ind_open_in_transit = -1;
		short		ind_in_transit = -1;
		short		ind_pending_fund = -1;
		short		ind_txn_hold_ind = -1;
		short		ind_sys_match_ind = -1;
		short		ind_customer_text = -1;
		short		ind_sender_name = -1;
		short		ind_txn_ref_num = -1;
		short		ind_charge_rule_id = -1;
		short		ind_charge_period_type = -1;
		short		ind_precal_charge= -1;
		short		ind_grp_tracking_txn_id = -1;
		short		ind_tracking_txn_id = -1;
		short		ind_report_date = -1;
		short		ind_settlement_date = -1;
		short		ind_manual_hold_recon = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr, csTxnID, hv_txn_id.len);
DEBUGLOG(("GetTxnPspDetail txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_gettxnpspdetail CURSOR FOR
		select otp_psp_id,
				otp_baid,
				otp_txn_ccy,
				otp_txn_amount,
				otp_txn_date,
				otp_txn_time,
				to_char(otp_txn_timestamp, 'yyyymmddhh24miss'),
				otp_bank_code,
				otp_bank_acct_num,
				otp_cost,
				otp_open_bal,
				otp_total_hold,
				otp_bal,
				otp_prepaid,
				otp_open_in_transit,
				otp_in_transit,
				otp_pending_fund,
				otp_txn_hold_ind,
				otp_sys_match_ind,
				otp_customer_text,
				otp_sender_name,
				otp_txn_ref_num,
				otp_charge_rule_id,
				otp_charge_period_type,
				otp_pre_cal_charge,
				otp_grp_tracking_txn_id,
				otp_tracking_txn_id,
				otp_report_date,
				otp_settlement_date,
				otp_manual_hold_recon
		from ol_txn_psp_detail
		where otp_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_gettxnpspdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )174;
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
			:v_baid:ind_baid,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_txn_date:ind_txn_date,
			:v_txn_time:ind_txn_time,
			:v_txn_timestamp:ind_txn_timestamp,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_cost:ind_cost,
			:v_open_bal:ind_open_bal,
			:v_total_hold:ind_total_hold,
			:v_bal:ind_bal,
			:v_prepaid:ind_prepaid,
			:v_open_in_transit:ind_open_in_transit,
			:v_in_transit:ind_in_transit,
			:v_pending_fund:ind_pending_fund,
			:v_txn_hold_ind:ind_txn_hold_ind,
			:v_sys_match_ind:ind_sys_match_ind,
			:v_customer_text:ind_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_charge_rule_id:ind_charge_rule_id,
			:v_charge_period_type:ind_charge_period_type,
			:v_precal_charge:ind_precal_charge,
			:v_grp_tracking_txn_id:ind_grp_tracking_txn_id,
			:v_tracking_txn_id:ind_tracking_txn_id,
			:v_report_date:ind_report_date,
			:v_settlement_date:ind_settlement_date,
			:v_manual_hold_recon:ind_manual_hold_recon; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )193;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_baid;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_date;
  sqlstm.sqhstl[4] = (unsigned long )11;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_date;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_time;
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_time;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_timestamp;
  sqlstm.sqhstl[6] = (unsigned long )17;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_timestamp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_code;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[8] = (unsigned long )53;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cost;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cost;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_open_bal;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_total_hold;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_bal;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_prepaid;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_prepaid;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_open_in_transit;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_open_in_transit;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_in_transit;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_in_transit;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_pending_fund;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_pending_fund;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_hold_ind;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_txn_hold_ind;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_sys_match_ind;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_sys_match_ind;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_customer_text;
  sqlstm.sqhstl[19] = (unsigned long )203;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_customer_text;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_sender_name;
  sqlstm.sqhstl[20] = (unsigned long )203;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_sender_name;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_txn_ref_num;
  sqlstm.sqhstl[21] = (unsigned long )203;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_txn_ref_num;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_charge_rule_id;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_charge_rule_id;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_charge_period_type;
  sqlstm.sqhstl[23] = (unsigned long )1;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_charge_period_type;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_precal_charge;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_precal_charge;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_grp_tracking_txn_id;
  sqlstm.sqhstl[25] = (unsigned long )19;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_grp_tracking_txn_id;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_tracking_txn_id;
  sqlstm.sqhstl[26] = (unsigned long )19;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_tracking_txn_id;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_report_date;
  sqlstm.sqhstl[27] = (unsigned long )11;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_report_date;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_settlement_date;
  sqlstm.sqhstl[28] = (unsigned long )11;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_settlement_date;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_manual_hold_recon;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_manual_hold_recon;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
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
			break;
		}

		iCnt++;

// psp_id
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(myHash, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("psp_id = [%s]\n", v_psp_id.arr));
		}

// baid
		if (ind_baid >= 0) {
			v_baid.arr[v_baid.len] = '\0';
			PutField_CString(myHash, "baid", (const char*)v_baid.arr);
DEBUGLOG(("baid = [%s]\n", v_baid.arr));
		}

// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(myHash, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("txn_ccy = [%s]\n", v_txn_ccy.arr));
		}

// txn_amount
		if (ind_txn_amount >= 0) {
			PutField_Double(myHash, "txn_amount", v_txn_amount);
DEBUGLOG(("txn_amount = [%f]\n", v_txn_amount));
		}

// txn_date
		if (ind_txn_date >= 0) {
			v_txn_date.arr[v_txn_date.len] = '\0';
			PutField_CString(myHash, "txn_date", (const char*)v_txn_date.arr);
DEBUGLOG(("txn_date = [%s]\n", v_txn_date.arr));
		}

// txn_time
		if (ind_txn_time >= 0) {
			v_txn_time.arr[v_txn_time.len] = '\0';
			PutField_CString(myHash, "txn_time", (const char*)v_txn_time.arr);
DEBUGLOG(("txn_time = [%s]\n", v_txn_time.arr));
		}

// txn_timestamp
		if (ind_txn_timestamp >= 0) {
			v_txn_timestamp.arr[v_txn_timestamp.len] = '\0';
			PutField_CString(myHash, "txn_timestamp", (const char*)v_txn_timestamp.arr);
DEBUGLOG(("txn_timestamp = [%s]\n", v_txn_timestamp.arr));
		}

// bank_code
		if (ind_bank_code >= 0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			PutField_CString(myHash, "bank_code", (const char*)v_bank_code.arr);
DEBUGLOG(("bank_code = [%s]\n", v_bank_code.arr));
		}

// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("bank_acct_num = [%s]\n", v_bank_acct_num.arr));
		}

// cost
		if (ind_cost >= 0) {
			PutField_Double(myHash, "cost", v_cost);
DEBUGLOG(("cost = [%f]\n", v_cost));
		}

// open_bal
		if (ind_open_bal >= 0) {
			PutField_Double(myHash, "open_bal", v_open_bal);
DEBUGLOG(("open_bal = [%f]\n", v_open_bal));
		}

// total_hold
		if (ind_total_hold >= 0) {
			PutField_Double(myHash, "total_hold", v_total_hold);
DEBUGLOG(("total_hold = [%f]\n", v_total_hold));
		}

// bal
		if (ind_bal >= 0) {
			PutField_Double(myHash, "bal", v_bal);
DEBUGLOG(("bal = [%f]\n", v_bal));
		}

// prepaid
		if (ind_prepaid >= 0) {
			PutField_Double(myHash, "prepaid", v_prepaid);
DEBUGLOG(("prepaid = [%f]\n", v_prepaid));
		}

// open_in_transit
		if (ind_open_in_transit >= 0) {
			PutField_Double(myHash, "open_in_transit", v_open_in_transit);
DEBUGLOG(("open_in_transit = [%f]\n", v_open_in_transit));
		}

// in_transit
		if (ind_in_transit >= 0) {
			PutField_Double(myHash, "in_transit", v_in_transit);
DEBUGLOG(("in_transit = [%f]\n", v_in_transit));
		}

// pending_fund
		if (ind_pending_fund >= 0) {
			PutField_Double(myHash, "pending_fund", v_pending_fund);
DEBUGLOG(("pending_fund = [%f]\n", v_pending_fund));
		}

// txn_hold_ind
		if (ind_txn_hold_ind >= 0) {
			PutField_Int(myHash, "txn_hold_ind", v_txn_hold_ind);
DEBUGLOG(("txn_hold_ind = [%d]\n", v_txn_hold_ind));
		}

// sys_match_ind
		if (ind_sys_match_ind >= 0) {
			PutField_Int(myHash, "sys_match_ind", v_sys_match_ind);
DEBUGLOG(("sys_match_ind = [%d]\n", v_sys_match_ind));
		}

// customer_text
		if (ind_customer_text >= 0) {
			v_customer_text.arr[v_customer_text.len] = '\0';
			PutField_CString(myHash, "customer_text", (const char*)v_customer_text.arr);
DEBUGLOG(("customer_text = [%s]\n", v_customer_text.arr));
		}

// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(myHash, "sender_name", (const char*)v_sender_name.arr);
DEBUGLOG(("sender_name = [%s]\n", v_sender_name.arr));
		}

// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(myHash, "txn_ref_num", (const char*)v_txn_ref_num.arr);
DEBUGLOG(("txn_ref_num = [%s]\n", v_txn_ref_num.arr));
		}

//charge_rule_id 
		if (ind_charge_rule_id>= 0) {
			PutField_Int(myHash, "charge_rule_id", v_charge_rule_id);
DEBUGLOG(("charge_rule_id = [%d]\n", v_charge_rule_id));
		}

// charge_period_type
		if (ind_charge_period_type>= 0) {
			PutField_Char(myHash, "charge_period_type", v_charge_period_type);
DEBUGLOG(("charge_period_type = [%c]\n", v_charge_period_type));
		}

// precal_charge
		if (ind_precal_charge>= 0) {
			PutField_Double(myHash, "pre_cal_charge", v_precal_charge);
DEBUGLOG(("precal_charge = [%f]\n", v_precal_charge));
		}

// grp_tracking_txn_id
		if (ind_grp_tracking_txn_id >= 0) {
			v_grp_tracking_txn_id.arr[v_grp_tracking_txn_id.len] = '\0';
			PutField_CString(myHash, "grp_tracking_txn_seq", (const char *)v_grp_tracking_txn_id.arr);
DEBUGLOG(("grp_tracking_txn_id = [%s]\n", v_grp_tracking_txn_id.arr));
		}

// tracking_txn_id
		if (ind_tracking_txn_id >= 0) {
			v_tracking_txn_id.arr[v_tracking_txn_id.len] = '\0';
			PutField_CString(myHash, "tracking_txn_seq", (const char *)v_tracking_txn_id.arr);
DEBUGLOG(("tracking_txn_id = [%s]\n", v_tracking_txn_id.arr));
		}

// report_date
		if (ind_report_date >= 0) {
			v_report_date.arr[v_report_date.len] = '\0';
			PutField_CString(myHash, "report_date", (const char *)v_report_date.arr);
DEBUGLOG(("report_date = [%s]\n", v_report_date.arr));
		}

// settlement_date
		if (ind_settlement_date >= 0) {
			v_settlement_date.arr[v_settlement_date.len] = '\0';
			PutField_CString(myHash, "settlement_date", (const char *)v_settlement_date.arr);
DEBUGLOG(("settlement_date = [%s]\n", v_settlement_date.arr));
		}

// manual_hold_recon 
		if (ind_manual_hold_recon >= 0) {
			PutField_Int(myHash, "manual_hold_recon", v_manual_hold_recon);
DEBUGLOG(("manual_hold_recon = [%d]\n", v_manual_hold_recon));
		}


	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_gettxnpspdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )328;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnpspdetail_error;
}



	if (iCnt>0) {
DEBUGLOG(("GetTxnPspDetail Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetTxnPspDetail NOT FOUND!!!\n"));
		return PD_ERR;
	}

gettxnpspdetail_error:
DEBUGLOG(("gettxnpspdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_gettxnpspdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )343;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetDepositTxnToHold(hash_t *myHash)
{
	int iRet = PD_OK;
	char *csTmp;
	double dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxntohold_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_stat_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_stat_txn_id;

		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		double		hv_txn_amount;
		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_txn_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_txn_time;

		/* varchar		hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short		ind_stat_txn_id = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_amount = -1;
		short		ind_txn_date = -1;
		short		ind_txn_time = -1;
		short		ind_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_txn_id = -1;

		short		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(myHash,"stat_txn_id",&csTmp)) {
		hv_stat_txn_id.len = strlen(csTmp);
		memcpy(hv_stat_txn_id.arr, csTmp, hv_stat_txn_id.len);
		ind_stat_txn_id = 0;
DEBUGLOG(("GetTransactionToHold stat_txn_id = [%.*s]\n", hv_stat_txn_id.len, hv_stat_txn_id.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold stat_txn_id NOT FOUND!!!\n"));
	}

	if (GetField_CString(myHash,"txn_ccy",&csTmp)) {
		hv_txn_ccy.len = strlen(csTmp);
		memcpy(hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy = 0;
DEBUGLOG(("GetTransactionToHold txn_ccy = [%.*s]\n", hv_txn_ccy.len, hv_txn_ccy.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold txn_ccy NOT FOUND!!!\n"));
	}

	if (GetField_Double(myHash,"txn_amount",&dTmp)) {
		hv_txn_amount = dTmp;
		ind_txn_amount = 0;
DEBUGLOG(("GetTransactionToHold txn_amount = [%.2lf]\n", hv_txn_amount));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold txn_amount NOT FOUND!!!\n"));
	}

	if (GetField_CString(myHash,"txn_date",&csTmp)) {
		hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("GetTransactionToHold txn_date = [%.*s]\n", hv_txn_date.len, hv_txn_date.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold txn_date NOT FOUND!!!\n"));
	}

	if (GetField_CString(myHash,"txn_time",&csTmp)) {
		hv_txn_time.len = strlen(csTmp);
		memcpy(hv_txn_time.arr, csTmp, hv_txn_time.len);
		ind_txn_time = 0;
DEBUGLOG(("GetTransactionToHold txn_time = [%.*s]\n", hv_txn_time.len, hv_txn_time.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold txn_time NOT FOUND!!!\n"));
	}

	if (GetField_CString(myHash,"bank_code",&csTmp)) {
		hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
		ind_bank_code = 0;
DEBUGLOG(("GetTransactionToHold bank_code = [%.*s]\n", hv_bank_code.len, hv_bank_code.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold bank_code NOT FOUND!!!\n"));
	}

	if (GetField_CString(myHash,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
DEBUGLOG(("GetTransactionToHold bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	} else {
		iRet = PD_ERR;
DEBUGLOG(("GetTransactionToHold bank_acct_num NOT FOUND!!!\n"));
	}

	if (iRet == PD_OK) {
		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_txn_deposit_hold(
							:hv_stat_txn_id:ind_stat_txn_id,
							:hv_txn_ccy:ind_txn_ccy,
							:hv_txn_amount:ind_txn_amount,
							:hv_txn_date:ind_txn_date,
							:hv_txn_time:ind_txn_time,
							:hv_bank_code:ind_bank_code,
							:hv_bank_acct_num:ind_bank_acct_num,
							:v_txn_id:ind_txn_id);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_deposit_hold ( :hv_sta\
t_txn_id:ind_stat_txn_id , :hv_txn_ccy:ind_txn_ccy , :hv_txn_amount:ind_txn_a\
mount , :hv_txn_date:ind_txn_date , :hv_txn_time:ind_txn_time , :hv_bank_code\
:ind_bank_code , :hv_bank_acct_num:ind_bank_acct_num , :v_txn_id:ind_txn_id )\
 ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )358;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_stat_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )19;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_stat_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_ccy;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_amount;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_amount;
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
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_time;
  sqlstm.sqhstl[5] = (unsigned long )8;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_time;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_code;
  sqlstm.sqhstl[6] = (unsigned long )12;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_code;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_num;
  sqlstm.sqhstl[7] = (unsigned long )52;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[8] = (unsigned long )19;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_id;
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
  if (sqlca.sqlcode < 0) goto gettxntohold_error;
}



		if (hv_return_value == SP_OK) {
			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
				PutField_CString(myHash,"txn_id",(char*)v_txn_id.arr);
				iRet = PD_OK;
DEBUGLOG(("GetTransactionToHold Found txn_id = [%s], Normal Exit\n",(char*)v_txn_id.arr));
			} else {
				iRet = PD_OK;
DEBUGLOG(("GetTransactionToHold Not Found, Normal Exit\n"));
			}
		} else {
DEBUGLOG(("GetTransactionToHold Ret = [%d] FAILURE!!!\n",hv_return_value));
			iRet = PD_ERR;
		}
	}

	return iRet;

gettxntohold_error:
DEBUGLOG(("gettxntohold_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetOLTxnPspDetailByDlvId(const unsigned char* csDlvId,
				const char *csCheckSubStatus,
                                recordset_t* myRec)
{
	int     iRet = PD_ERR;

	hash_t *myHash;
	/* EXEC SQL WHENEVER SQLERROR GOTO getoldtbydlvid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short           hv_return_value;
		/* varchar         hv_dlv_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_dlv_id;

		/* varchar		hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;


		/* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short           ind_txn_id = -1;
		short           ind_dlv_id = -1;
		short		ind_sub_status = -1;

		SQL_CURSOR      c_cursor_olpspdtbydlv;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_dlv_id.len = strlen((const char*)csDlvId);
	memcpy(hv_dlv_id.arr,csDlvId,hv_dlv_id.len);
DEBUGLOG(("GetOLTxnPspDetailByDlvId delivery_id = [%.*s]\n",hv_dlv_id.len,hv_dlv_id.arr));
	ind_dlv_id= 0;

	hv_sub_status.len = strlen((const char*) csCheckSubStatus);
	memcpy(hv_sub_status.arr, csCheckSubStatus, hv_sub_status.len);
DEBUGLOG(("GetOLTxnPspDetailByDlvId sub_status = [%.*s]\n",hv_sub_status.len,hv_sub_status.arr));
	ind_sub_status = 0;
	

	/* EXEC SQL ALLOCATE       :c_cursor_olpspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )409;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getoldtbydlvid_error;
}


	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_psp_dt_getbydlvid(:hv_dlv_id:ind_dlv_id,
							:hv_sub_status:ind_sub_status,
							:c_cursor_olpspdtbydlv);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_psp_dt_getbydlvid ( :hv\
_dlv_id:ind_dlv_id , :hv_sub_status:ind_sub_status , :c_cursor_olpspdtbydlv )\
 ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )428;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_sub_status;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getoldtbydlvid_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("GetOLTxnPspDetailByDlvId Found\n"));
		for (;;) {
			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

			ind_txn_id= -1;

			/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

			/* EXEC SQL FETCH :c_cursor_olpspdtbydlv
			INTO
				:v_txn_id:ind_txn_id; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 30;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )459;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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
   if (sqlca.sqlcode < 0) goto getoldtbydlvid_error;
}



/* txn_id */
			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
				PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetOLTxnPspDetailByDlvId txn_id = [%s]\n",v_txn_id.arr));
			}

			iRet=PD_OK;
			RecordSet_Add(myRec,myHash);
		}
	}
	else{
DEBUGLOG(("GetOLTxnPspDetailByDlvId Not Found\n"));
	}

	/* EXEC SQL CLOSE :c_cursor_olpspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )482;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getoldtbydlvid_error;
}


	/* EXEC SQL FREE :c_cursor_olpspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )501;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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
 if (sqlca.sqlcode < 0) goto getoldtbydlvid_error;
}



	return iRet;

getoldtbydlvid_error:
DEBUGLOG(("getoldtbydlvid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE :c_cursor_olpspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )520;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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


	/* EXEC SQL FREE :c_cursor_olpspdtbydlv; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )539;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_olpspdtbydlv;
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



int GetTxnPspDetailByBAID(const char *csBAID, recordset_t* myRec)
{
	int iCnt=0;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnpspdetailbybaid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;


		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double		v_txn_amount;
		/* varchar		v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar		v_txn_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_txn_time;

		/* varchar		v_txn_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_timestamp;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		/* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		double		v_cost;
		double		v_open_bal;
		double		v_total_hold;
		double		v_bal;
		double		v_prepaid;
		double		v_open_in_transit;
		double		v_in_transit;
		double		v_pending_fund;
		int		v_txn_hold_ind;
		int		v_sys_match_ind;
		/* varchar		v_customer_text[PD_TFR_CUSTOMER_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_customer_text;

		/* varchar		v_sender_name[PD_SENDER_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_sender_name;

		/* varchar		v_txn_ref_num[PD_TXN_REF_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_txn_ref_num;

		int		v_charge_rule_id;
		char		v_charge_period_type;
		double		v_precal_charge;
		/* varchar		v_grp_tracking_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_grp_tracking_txn_id;

		/* varchar		v_tracking_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_tracking_txn_id;

		/* varchar		v_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_report_date;

		/* varchar		v_settlement_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_settlement_date;

		int		v_manual_hold_recon;

		short		ind_txn_id = -1;
		short		ind_psp_id = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_amount = -1;
		short		ind_txn_date = -1;
		short		ind_txn_time = -1;
		short		ind_txn_timestamp = -1;
		short		ind_bank_code = -1;
		short		ind_bank_acct_num = -1;
		short		ind_cost = -1;
		short		ind_open_bal = -1;
		short		ind_total_hold = -1;
		short		ind_bal = -1;
		short		ind_prepaid = -1;
		short		ind_open_in_transit = -1;
		short		ind_in_transit = -1;
		short		ind_pending_fund = -1;
		short		ind_txn_hold_ind = -1;
		short		ind_sys_match_ind = -1;
		short		ind_customer_text = -1;
		short		ind_sender_name = -1;
		short		ind_txn_ref_num = -1;
		short		ind_charge_rule_id = -1;
		short		ind_charge_period_type = -1;
		short		ind_precal_charge= -1;
		short		ind_grp_tracking_txn_id = -1;
		short		ind_tracking_txn_id = -1;
		short		ind_report_date = -1;
		short		ind_settlement_date = -1;
		short		ind_manual_hold_recon = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("GetTxnPspDetailByBAID baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	/* EXEC SQL DECLARE c_cursor_gettxnpspdetailbybaid CURSOR FOR
		select otp_txn_id,
				otp_psp_id,
				otp_txn_ccy,
				otp_txn_amount,
				otp_txn_date,
				otp_txn_time,
				to_char(otp_txn_timestamp, 'yyyymmddhh24miss'),
				otp_bank_code,
				otp_bank_acct_num,
				otp_cost,
				otp_open_bal,
				otp_total_hold,
				otp_bal,
				otp_prepaid,
				otp_open_in_transit,
				otp_in_transit,
				otp_pending_fund,
				otp_txn_hold_ind,
				otp_sys_match_ind,
				otp_customer_text,
				otp_sender_name,
				otp_txn_ref_num,
				otp_charge_rule_id,
				otp_charge_period_type,
				otp_pre_cal_charge,
				otp_grp_tracking_txn_id,
				otp_tracking_txn_id,
				otp_report_date,
				otp_settlement_date,
				otp_manual_hold_recon
		from ol_txn_psp_detail
		where otp_baid = :hv_baid
		order by otp_create_timestamp; */ 


	/* EXEC SQL OPEN c_cursor_gettxnpspdetailbybaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )558;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[0] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto gettxnpspdetailbybaid_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_gettxnpspdetailbybaid
		INTO
			:v_txn_id:ind_txn_id,
			:v_psp_id:ind_psp_id,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_txn_date:ind_txn_date,
			:v_txn_time:ind_txn_time,
			:v_txn_timestamp:ind_txn_timestamp,
			:v_bank_code:ind_bank_code,
			:v_bank_acct_num:ind_bank_acct_num,
			:v_cost:ind_cost,
			:v_open_bal:ind_open_bal,
			:v_total_hold:ind_total_hold,
			:v_bal:ind_bal,
			:v_prepaid:ind_prepaid,
			:v_open_in_transit:ind_open_in_transit,
			:v_in_transit:ind_in_transit,
			:v_pending_fund:ind_pending_fund,
			:v_txn_hold_ind:ind_txn_hold_ind,
			:v_sys_match_ind:ind_sys_match_ind,
			:v_customer_text:ind_customer_text,
			:v_sender_name:ind_sender_name,
			:v_txn_ref_num:ind_txn_ref_num,
			:v_charge_rule_id:ind_charge_rule_id,
			:v_charge_period_type:ind_charge_period_type,
			:v_precal_charge:ind_precal_charge,
			:v_grp_tracking_txn_id:ind_grp_tracking_txn_id,
			:v_tracking_txn_id:ind_tracking_txn_id,
			:v_report_date:ind_report_date,
			:v_settlement_date:ind_settlement_date,
			:v_manual_hold_recon:ind_manual_hold_recon; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )577;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_psp_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_date;
  sqlstm.sqhstl[4] = (unsigned long )11;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_date;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_time;
  sqlstm.sqhstl[5] = (unsigned long )9;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_time;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_timestamp;
  sqlstm.sqhstl[6] = (unsigned long )17;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_timestamp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
  sqlstm.sqhstl[7] = (unsigned long )13;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_code;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
  sqlstm.sqhstl[8] = (unsigned long )53;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_cost;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_cost;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_open_bal;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_total_hold;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_bal;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_prepaid;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_prepaid;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_open_in_transit;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_open_in_transit;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_in_transit;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_in_transit;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_pending_fund;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_pending_fund;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_hold_ind;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_txn_hold_ind;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_sys_match_ind;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_sys_match_ind;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_customer_text;
  sqlstm.sqhstl[19] = (unsigned long )203;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_customer_text;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_sender_name;
  sqlstm.sqhstl[20] = (unsigned long )203;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_sender_name;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_txn_ref_num;
  sqlstm.sqhstl[21] = (unsigned long )203;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_txn_ref_num;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_charge_rule_id;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_charge_rule_id;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_charge_period_type;
  sqlstm.sqhstl[23] = (unsigned long )1;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_charge_period_type;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_precal_charge;
  sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_precal_charge;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_grp_tracking_txn_id;
  sqlstm.sqhstl[25] = (unsigned long )19;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_grp_tracking_txn_id;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_tracking_txn_id;
  sqlstm.sqhstl[26] = (unsigned long )19;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_tracking_txn_id;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_report_date;
  sqlstm.sqhstl[27] = (unsigned long )11;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_report_date;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_settlement_date;
  sqlstm.sqhstl[28] = (unsigned long )11;
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_settlement_date;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_manual_hold_recon;
  sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_manual_hold_recon;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto gettxnpspdetailbybaid_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		iCnt++;

// txn_id               
		if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash, "txn_id", (const char*)v_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_id = [%s]\n", v_txn_id.arr));
		}

// psp_id
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(myHash, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("GetTxnPspDetailByBAID psp_id = [%s]\n", v_psp_id.arr));
		}

// txn_ccy
		if (ind_txn_ccy >= 0) {
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
			PutField_CString(myHash, "txn_ccy", (const char*)v_txn_ccy.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_ccy = [%s]\n", v_txn_ccy.arr));
		}

// txn_amount
		if (ind_txn_amount >= 0) {
			PutField_Double(myHash, "txn_amount", v_txn_amount);
DEBUGLOG(("GetTxnPspDetailByBAID txn_amount = [%f]\n", v_txn_amount));
		}

// txn_date
		if (ind_txn_date >= 0) {
			v_txn_date.arr[v_txn_date.len] = '\0';
			PutField_CString(myHash, "txn_date", (const char*)v_txn_date.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_date = [%s]\n", v_txn_date.arr));
		}

// txn_time
		if (ind_txn_time >= 0) {
			v_txn_time.arr[v_txn_time.len] = '\0';
			PutField_CString(myHash, "txn_time", (const char*)v_txn_time.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_time = [%s]\n", v_txn_time.arr));
		}

// txn_timestamp
		if (ind_txn_timestamp >= 0) {
			v_txn_timestamp.arr[v_txn_timestamp.len] = '\0';
			PutField_CString(myHash, "txn_timestamp", (const char*)v_txn_timestamp.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_timestamp = [%s]\n", v_txn_timestamp.arr));
		}

// bank_code
		if (ind_bank_code >= 0) {
			v_bank_code.arr[v_bank_code.len] = '\0';
			PutField_CString(myHash, "bank_code", (const char*)v_bank_code.arr);
DEBUGLOG(("GetTxnPspDetailByBAID bank_code = [%s]\n", v_bank_code.arr));
		}

// bank_acct_num
		if (ind_bank_acct_num >= 0) {
			v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			PutField_CString(myHash, "bank_acct_num", (const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetTxnPspDetailByBAID bank_acct_num = [%s]\n", v_bank_acct_num.arr));
		}

// cost
		if (ind_cost >= 0) {
			PutField_Double(myHash, "cost", v_cost);
DEBUGLOG(("GetTxnPspDetailByBAID cost = [%f]\n", v_cost));
		}

// open_bal
		if (ind_open_bal >= 0) {
			PutField_Double(myHash, "open_bal", v_open_bal);
DEBUGLOG(("GetTxnPspDetailByBAID open_bal = [%f]\n", v_open_bal));
		}

// total_hold
		if (ind_total_hold >= 0) {
			PutField_Double(myHash, "total_hold", v_total_hold);
DEBUGLOG(("GetTxnPspDetailByBAID total_hold = [%f]\n", v_total_hold));
		}

// bal
		if (ind_bal >= 0) {
			PutField_Double(myHash, "bal", v_bal);
DEBUGLOG(("GetTxnPspDetailByBAID bal = [%f]\n", v_bal));
		}

// prepaid
		if (ind_prepaid >= 0) {
			PutField_Double(myHash, "prepaid", v_prepaid);
DEBUGLOG(("GetTxnPspDetailByBAID prepaid = [%f]\n", v_prepaid));
		}

// open_in_transit
		if (ind_open_in_transit >= 0) {
			PutField_Double(myHash, "open_in_transit", v_open_in_transit);
DEBUGLOG(("GetTxnPspDetailByBAID open_in_transit = [%f]\n", v_open_in_transit));
		}

// in_transit
		if (ind_in_transit >= 0) {
			PutField_Double(myHash, "in_transit", v_in_transit);
DEBUGLOG(("GetTxnPspDetailByBAID in_transit = [%f]\n", v_in_transit));
		}

// pending_fund
		if (ind_pending_fund >= 0) {
			PutField_Double(myHash, "pending_fund", v_pending_fund);
DEBUGLOG(("GetTxnPspDetailByBAID pending_fund = [%f]\n", v_pending_fund));
		}

// txn_hold_ind
		if (ind_txn_hold_ind >= 0) {
			PutField_Int(myHash, "txn_hold_ind", v_txn_hold_ind);
DEBUGLOG(("GetTxnPspDetailByBAID txn_hold_ind = [%d]\n", v_txn_hold_ind));
		}

// sys_match_ind
		if (ind_sys_match_ind >= 0) {
			PutField_Int(myHash, "sys_match_ind", v_sys_match_ind);
DEBUGLOG(("GetTxnPspDetailByBAID sys_match_ind = [%d]\n", v_sys_match_ind));
		}

// customer_text
		if (ind_customer_text >= 0) {
			v_customer_text.arr[v_customer_text.len] = '\0';
			PutField_CString(myHash, "customer_text", (const char*)v_customer_text.arr);
DEBUGLOG(("GetTxnPspDetailByBAID customer_text = [%s]\n", v_customer_text.arr));
		}

// sender_name
		if (ind_sender_name >= 0) {
			v_sender_name.arr[v_sender_name.len] = '\0';
			PutField_CString(myHash, "sender_name", (const char*)v_sender_name.arr);
DEBUGLOG(("GetTxnPspDetailByBAID sender_name = [%s]\n", v_sender_name.arr));
		}

// txn_ref_num
		if (ind_txn_ref_num >= 0) {
			v_txn_ref_num.arr[v_txn_ref_num.len] = '\0';
			PutField_CString(myHash, "txn_ref_num", (const char*)v_txn_ref_num.arr);
DEBUGLOG(("GetTxnPspDetailByBAID txn_ref_num = [%s]\n", v_txn_ref_num.arr));
		}

//charge_rule_id 
		if (ind_charge_rule_id>= 0) {
			PutField_Int(myHash, "charge_rule_id", v_charge_rule_id);
DEBUGLOG(("GetTxnPspDetailByBAID charge_rule_id = [%d]\n", v_charge_rule_id));
		}

// charge_period_type
		if (ind_charge_period_type>= 0) {
			PutField_Char(myHash, "charge_period_type", v_charge_period_type);
DEBUGLOG(("GetTxnPspDetailByBAID charge_period_type = [%c]\n", v_charge_period_type));
		}

// precal_charge
		if (ind_precal_charge>= 0) {
			PutField_Double(myHash, "pre_cal_charge", v_precal_charge);
DEBUGLOG(("GetTxnPspDetailByBAID precal_charge = [%f]\n", v_precal_charge));
		}

// grp_tracking_txn_id
		if (ind_grp_tracking_txn_id >= 0) {
			v_grp_tracking_txn_id.arr[v_grp_tracking_txn_id.len] = '\0';
			PutField_CString(myHash, "grp_tracking_txn_seq", (const char *)v_grp_tracking_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailByBAID grp_tracking_txn_id = [%s]\n", v_grp_tracking_txn_id.arr));
		}

// tracking_txn_id
		if (ind_tracking_txn_id >= 0) {
			v_tracking_txn_id.arr[v_tracking_txn_id.len] = '\0';
			PutField_CString(myHash, "tracking_txn_seq", (const char *)v_tracking_txn_id.arr);
DEBUGLOG(("GetTxnPspDetailByBAID tracking_txn_id = [%s]\n", v_tracking_txn_id.arr));
		}

// report_date
		if (ind_report_date >= 0) {
			v_report_date.arr[v_report_date.len] = '\0';
			PutField_CString(myHash, "report_date", (const char *)v_report_date.arr);
DEBUGLOG(("GetTxnPspDetailByBAID report_date = [%s]\n", v_report_date.arr));
		}

// settlement_date
		if (ind_settlement_date >= 0) {
			v_settlement_date.arr[v_settlement_date.len] = '\0';
			PutField_CString(myHash, "settlement_date", (const char *)v_settlement_date.arr);
DEBUGLOG(("GetTxnPspDetailByBAID settlement_date = [%s]\n", v_settlement_date.arr));
		}

// manual_hold_recon 
		if (ind_manual_hold_recon>= 0) {
			PutField_Int(myHash, "manual_hold_recon", v_manual_hold_recon);
DEBUGLOG(("GetTxnPspDetailByBAID manual_hold_recon = [%d]\n", v_manual_hold_recon));
		}

		RecordSet_Add(myRec,myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_gettxnpspdetailbybaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )712;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnpspdetailbybaid_error;
}



	if (iCnt>0) {
DEBUGLOG(("GetTxnPspDetailByBAID Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetTxnPspDetailByBAID NOT FOUND!!!\n"));
		return PD_ERR;
	}

gettxnpspdetailbybaid_error:
DEBUGLOG(("gettxnpspdetailbybaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_gettxnpspdetailbybaid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )727;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int GetTxnCountByBankAcct(const char* csBankCode, const char* csBankAcctNum)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getcnt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

		/* varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

                int     v_cnt;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_code.len = strlen(csBankCode);
        strncpy((char*)hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetTxnCountByBankAcct bank_code = [%s]\n",csBankCode));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
        strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
DEBUGLOG(("GetTxnCountByBankAcct bank_acct_num = [%s]\n",csBankAcctNum));

        /* EXEC SQL        SELECT  count(*)
                        INTO    :v_cnt
                        FROM    ol_txn_psp_detail
			WHERE	otp_bank_code = :hv_bank_code
			AND	otp_bank_acct_num = :hv_bank_acct_num; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 30;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( * ) INTO :b0 FROM ol_txn_psp_detail W\
HERE otp_bank_code = :b1 AND otp_bank_acct_num = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )742;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[1] = (unsigned long )12;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_acct_num;
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
        if (sqlca.sqlcode < 0) goto getcnt_error;
}



DEBUGLOG(("GetTxnCountByBankAcct() Normal Exit! record found = [%d]\n", v_cnt));
        return v_cnt;

getcnt_error:
DEBUGLOG(("getcountbybaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

 	return PD_ERR; 
}



int GetPayoutReconPspTxn(const hash_t* hRls, recordset_t* myRec) 
{
	int iRet = PD_OK;

	hash_t *myHash;

	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_prm_psp_txn_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		/* varchar v_psp_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_psp_txn_id;


		short ind_psp_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetPayoutReconPspTxn: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "select psp_txn_otp.otp_txn_id \
from ol_txn_header psp_txn_oth, \
ol_txn_psp_detail psp_txn_otp, \
ol_psp_detail psp_txn_opd \
where 1 = 1 \
and psp_txn_oth.oth_txn_id = psp_txn_otp.otp_txn_id \
and psp_txn_otp.otp_psp_id = psp_txn_opd.opd_psp_id \
and psp_txn_otp.otp_txn_ccy = psp_txn_opd.opd_currency_id \
and psp_txn_opd.opd_disabled = 0 \
and psp_txn_opd.opd_status = 'O' \
and psp_txn_oth.oth_status = 'C' \
and psp_txn_oth.oth_ar_ind = 'A' \
and nvl(psp_txn_otp.otp_manual_hold_recon, 0) = 0 \
and psp_txn_oth.oth_recon_status = 'U' \
and psp_txn_oth.oth_txn_code = 'OPG' \
and psp_txn_otp.otp_txn_id not in (select owpc_psp_txn_id from ol_wait_payout_recon_cfm_list)");


/*
and psp_txn_opd.opd_psp_id = 'P9000220'
and psp_txn_otp.otp_create_timestamp >= to_date('20210101', 'YYYYMMDD')
and psp_txn_otp.otp_create_timestamp <= to_date('20210131', 'YYYYMMDD')
order by psp_txn_oth.oth_create_timestamp asc
*/

	// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
DEBUGLOG(("GetPayoutReconPspTxn: psp_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and psp_txn_opd.opd_psp_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	
	//create_ts_from
	if (GetField_CString(hRls, "create_ts_from", &csTmp)) {
DEBUGLOG(("GetPayoutReconPspTxn: create_ts_from = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and psp_txn_otp.otp_create_timestamp >= to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
	//create_ts_to
	if (GetField_CString(hRls, "create_ts_to", &csTmp)) {
DEBUGLOG(("GetPayoutReconPspTxn: create_ts_to = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, " and psp_txn_otp.otp_create_timestamp <= to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24miss')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	
	// order by
	strcat((char*)hv_dynstmt.arr, " order by psp_txn_oth.oth_create_timestamp asc");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		

DEBUGLOG(("GetPayoutReconPspTxn: [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE s_get_prm_psp_txn FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )769;
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
 if (sqlca.sqlcode < 0) goto get_prm_psp_txn_error;
}


	/* EXEC SQL DECLARE c_get_prm_psp_txn CURSOR FOR s_get_prm_psp_txn; */ 


	/* EXEC SQL OPEN c_get_prm_psp_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )788;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_prm_psp_txn_error;
}


	for (;;) {
		/* EXEC SQL FETCH c_get_prm_psp_txn
		INTO	:v_psp_txn_id:ind_psp_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 30;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )803;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_psp_txn_id;
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
  if (sqlca.sqlcode < 0) goto get_prm_psp_txn_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// psp_txn_id
		if (ind_psp_txn_id >= 0) {
			v_psp_txn_id.arr[v_psp_txn_id.len] = '\0';
			PutField_CString(myHash, "psp_txn_id", (const char*)v_psp_txn_id.arr);
DEBUGLOG(("GetPayoutReconPspTxn: psp_txn_id = [%s]\n", (const char*)v_psp_txn_id.arr));
		}

		RecordSet_Add(myRec, myHash);
	}
	/* EXEC SQL CLOSE c_get_prm_psp_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )822;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto get_prm_psp_txn_error;
}



DEBUGLOG(("GetPayoutReconPspTxn Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

get_prm_psp_txn_error:
DEBUGLOG(("get_prm_psp_txn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTxnPspDetail get_prm_psp_txn_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_get_prm_psp_txn; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 30;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )837;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
	
}




