
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
           char  filnam[19];
};
static struct sqlcxp sqlfpn =
{
    18,
    "OLPayoutRequest.pc"
};


static unsigned int sqlctx = 20414667;


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

 static char *sq0003 = 
"SELECT opr_aux_txn_id , opr_merchant_payout_grp , opr_psp_payout_grp , opr_\
request_currency , opr_request_amount , opr_payout_currency , opr_payout_amou\
nt , opr_member_fee_ccy , opr_member_fee , opr_merchant_fee_ccy , opr_merchan\
t_fee , opr_markup_ccy , opr_markup_amt , opr_status , opr_generated_file_id \
, opr_psp_id FROM ol_payout_request WHERE opr_txn_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,711,0,6,235,0,0,19,19,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,
1,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
96,0,0,2,0,0,17,469,0,0,1,1,0,1,0,1,9,0,0,
115,0,0,2,0,0,21,470,0,0,0,0,0,1,0,
130,0,0,3,376,0,9,557,0,2049,1,1,0,1,0,1,9,0,0,
149,0,0,3,0,0,13,559,0,0,16,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,3,0,0,2,3,0,0,
2,9,0,0,
228,0,0,3,0,0,15,692,0,0,0,0,0,1,0,
243,0,0,3,0,0,15,706,0,0,0,0,0,1,0,
258,0,0,4,97,0,4,731,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,3,0,0,
285,0,0,5,115,0,4,774,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,3,0,0,
312,0,0,2,0,0,17,1247,0,0,1,1,0,1,0,1,9,0,0,
331,0,0,2,0,0,21,1248,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/03/10              Dirk Wong
Refine Add & Update functions                      2017/03/14              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLPayoutRequest.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;


void OLPayoutRequest(char cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char *csTmp;
	double dTmp;
	int iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		short hv_return_value;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_aux_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_aux_txn_id;

		/* varchar		hv_merchant_payout_grp[PD_OFL_PAYOUT_GROUP_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_merchant_payout_grp;

		/* varchar		hv_psp_payout_grp[PD_OFL_PAYOUT_GROUP_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_psp_payout_grp;

		/* varchar		hv_request_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_request_currency;

		double		hv_request_amount;
		/* varchar		hv_payout_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_currency;

		double		hv_payout_amount;
		/* varchar		hv_member_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_member_fee_ccy;

		double		hv_member_fee;
		/* varchar		hv_merchant_fee_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_merchant_fee_ccy;

		double		hv_merchant_fee;
		/* varchar		hv_markup_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_markup_ccy;

		double		hv_markup_amt;
		int		hv_status;
		int		hv_generated_file_id;
		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short		ind_txn_id = -1;
		short		ind_aux_txn_id = -1;
		short		ind_merchant_payout_grp = -1;
		short		ind_psp_payout_grp = -1;
		short		ind_request_currency = -1;
		short		ind_request_amount = -1;
		short		ind_payout_currency = -1;
		short		ind_payout_amount = -1;
		short		ind_member_fee_ccy = -1;
		short		ind_member_fee = -1;
		short		ind_merchant_fee_ccy = -1;
		short		ind_merchant_fee = -1;
		short		ind_markup_ccy = -1;
		short		ind_markup_amt = -1;
		short		ind_status = -1;
		short		ind_generated_file_id = -1;
		short		ind_psp_id = -1;
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

// aux_txn_seq
	if (GetField_CString(hRls, "aux_txn_seq", &csTmp)) {
		hv_aux_txn_id.len = strlen(csTmp);
		memcpy(hv_aux_txn_id.arr, csTmp, hv_aux_txn_id.len);
		ind_aux_txn_id = 0;
DEBUGLOG(("Add: aux_txn_id = [%.*s][%d]\n", hv_aux_txn_id.len, hv_aux_txn_id.arr, hv_aux_txn_id.len));
	}

// merchant_payout_grp
	if (GetField_CString(hRls, "merchant_payout_grp", &csTmp)) {
		hv_merchant_payout_grp.len = strlen(csTmp);
		memcpy(hv_merchant_payout_grp.arr, csTmp, hv_merchant_payout_grp.len);
		ind_merchant_payout_grp = 0;
DEBUGLOG(("Add: merchant_payout_grp = [%.*s][%d]\n", hv_merchant_payout_grp.len, hv_merchant_payout_grp.arr, hv_merchant_payout_grp.len));
	}

// psp_payout_grp
	if (GetField_CString(hRls, "psp_payout_grp", &csTmp)) {
		hv_psp_payout_grp.len = strlen(csTmp);
		memcpy(hv_psp_payout_grp.arr, csTmp, hv_psp_payout_grp.len);
		ind_psp_payout_grp = 0;
DEBUGLOG(("Add: psp_payout_grp = [%.*s][%d]\n", hv_psp_payout_grp.len, hv_psp_payout_grp.arr, hv_psp_payout_grp.len));
	}

// request_currency
	if (GetField_CString(hRls, "request_currency", &csTmp)) {
		hv_request_currency.len = strlen(csTmp);
		memcpy(hv_request_currency.arr, csTmp, hv_request_currency.len);
		ind_request_currency = 0;
DEBUGLOG(("Add: request_currency = [%.*s][%d]\n", hv_request_currency.len, hv_request_currency.arr, hv_request_currency.len));
	}

// request_amount
	if (GetField_Double(hRls, "request_amount", &dTmp)) {
		hv_request_amount = dTmp;
	} else {
		hv_request_amount = 0.0;
	}
	ind_request_amount = 0;
DEBUGLOG(("Add: request_amount = [%f]\n", hv_request_amount));

// payout_currency
	if (GetField_CString(hRls, "payout_currency", &csTmp)) {
		hv_payout_currency.len = strlen(csTmp);
		memcpy(hv_payout_currency.arr, csTmp, hv_payout_currency.len);
		ind_payout_currency = 0;
DEBUGLOG(("Add: payout_currency = [%.*s][%d]\n", hv_payout_currency.len, hv_payout_currency.arr, hv_payout_currency.len));
	}

// payout_amount
	if (GetField_Double(hRls, "payout_amount", &dTmp)) {
		hv_payout_amount = dTmp;
	} else {
		hv_payout_amount = 0.0;
	}
	ind_payout_amount = 0;
DEBUGLOG(("Add: payout_amount = [%f]\n", hv_payout_amount));

// member_fee_ccy
	if (GetField_CString(hRls, "member_fee_ccy", &csTmp)) {
		hv_member_fee_ccy.len = strlen(csTmp);
		memcpy(hv_member_fee_ccy.arr, csTmp, hv_member_fee_ccy.len);
		ind_member_fee_ccy = 0;
DEBUGLOG(("Add: member_fee_ccy = [%.*s][%d]\n", hv_member_fee_ccy.len, hv_member_fee_ccy.arr, hv_member_fee_ccy.len));
	}

// member_fee
	if (GetField_Double(hRls, "member_fee", &dTmp)) {
		hv_member_fee = dTmp;
	} else {
		hv_member_fee = 0.0;
	}
	ind_member_fee = 0;
DEBUGLOG(("Add: member_fee = [%f]\n", hv_member_fee));

// merchant_fee_ccy
	if (GetField_CString(hRls, "merchant_fee_ccy", &csTmp)) {
		hv_merchant_fee_ccy.len = strlen(csTmp);
		memcpy(hv_merchant_fee_ccy.arr, csTmp, hv_merchant_fee_ccy.len);
		ind_merchant_fee_ccy = 0;
DEBUGLOG(("Add: merchant_fee_ccy = [%.*s][%d]\n", hv_merchant_fee_ccy.len, hv_merchant_fee_ccy.arr, hv_merchant_fee_ccy.len));
	}

// merchant_fee
	if (GetField_Double(hRls, "merchant_fee", &dTmp)) {
		hv_merchant_fee = dTmp;
	} else {
		hv_merchant_fee = 0.0;
	}
	ind_merchant_fee = 0;
DEBUGLOG(("Add: merchant_fee = [%f]\n", hv_merchant_fee));

// markup_ccy
	if (GetField_CString(hRls, "markup_ccy", &csTmp)) {
		hv_markup_ccy.len = strlen(csTmp);
		memcpy(hv_markup_ccy.arr, csTmp, hv_markup_ccy.len);
		ind_markup_ccy = 0;
DEBUGLOG(("Add: markup_ccy = [%.*s][%d]\n", hv_markup_ccy.len, hv_markup_ccy.arr, hv_markup_ccy.len));
	}

// markup_amt
	if (GetField_Double(hRls, "markup_amt", &dTmp)) {
		hv_markup_amt = dTmp;
	} else {
		hv_markup_amt = 0.0;
	}
	ind_markup_amt = 0;
DEBUGLOG(("Add: markup_amt = [%f]\n", hv_markup_amt));

// status
	if (GetField_Int(hRls, "status", &iTmp)) {
		hv_status = iTmp;
		ind_status = 0;
DEBUGLOG(("Add: status = [%d]\n", hv_status));
	}

// generated_file_id
	if (GetField_Int(hRls, "generated_file_id", &iTmp)) {
		hv_generated_file_id = iTmp;
		ind_generated_file_id = 0;
DEBUGLOG(("Add: generated_file_id = [%d]\n", hv_generated_file_id));
	}

// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
		hv_psp_id.len = strlen(csTmp);
		memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
DEBUGLOG(("Add: psp_id = [%.*s][%d]\n", hv_psp_id.len, hv_psp_id.arr, hv_psp_id.len));
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
			:hv_return_value := sp_ol_payout_request_insert(
									:hv_txn_id:ind_txn_id,
									:hv_aux_txn_id:ind_aux_txn_id,
									:hv_merchant_payout_grp:ind_merchant_payout_grp,
									:hv_psp_payout_grp:ind_psp_payout_grp,
									:hv_request_currency:ind_request_currency,
									:hv_request_amount:ind_request_amount,
									:hv_payout_currency:ind_payout_currency,
									:hv_payout_amount:ind_payout_amount,
									:hv_member_fee_ccy:ind_member_fee_ccy,
									:hv_member_fee:ind_member_fee,
									:hv_merchant_fee_ccy:ind_merchant_fee_ccy,
									:hv_merchant_fee:ind_merchant_fee,
									:hv_markup_ccy:ind_markup_ccy,
									:hv_markup_amt:ind_markup_amt,
									:hv_status:ind_status,
									:hv_generated_file_id:ind_generated_file_id,
									:hv_psp_id:ind_psp_id,
									:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_payout_request_insert ( :hv\
_txn_id:ind_txn_id , :hv_aux_txn_id:ind_aux_txn_id , :hv_merchant_payout_grp:\
ind_merchant_payout_grp , :hv_psp_payout_grp:ind_psp_payout_grp , :hv_request\
_currency:ind_request_currency , :hv_request_amount:ind_request_amount , :hv_\
payout_currency:ind_payout_currency , :hv_payout_amount:ind_payout_amount , :\
hv_member_fee_ccy:ind_member_fee_ccy , :hv_member_fee:ind_member_fee , :hv_me\
rchant_fee_ccy:ind_merchant_fee_ccy , :hv_merchant_fee:ind_merchant_fee , :hv\
_markup_ccy:ind_markup_ccy , :hv_markup_amt:ind_markup_amt , :hv_status:ind_s\
tatus , :hv_generated_file_id:ind_generated_file_id , :hv_psp_id:ind_psp_id ,\
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_aux_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_aux_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_payout_grp;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_merchant_payout_grp;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_psp_payout_grp;
 sqlstm.sqhstl[4] = (unsigned long )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_psp_payout_grp;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_request_currency;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_request_currency;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_request_amount;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_request_amount;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_payout_currency;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_payout_currency;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_payout_amount;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_payout_amount;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_member_fee_ccy;
 sqlstm.sqhstl[9] = (unsigned long )5;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_member_fee_ccy;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_member_fee;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_member_fee;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_merchant_fee_ccy;
 sqlstm.sqhstl[11] = (unsigned long )5;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_merchant_fee_ccy;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_merchant_fee;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_merchant_fee;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_markup_ccy;
 sqlstm.sqhstl[13] = (unsigned long )5;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_markup_ccy;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_markup_amt;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_markup_amt;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_status;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_generated_file_id;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_generated_file_id;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[17] = (unsigned long )12;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_psp_id;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLPayoutRequest_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLPayoutRequest_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLPayoutRequest_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}


int Update(const hash_t *hRls)
{
	char *csTmp;
	double dTmp;
	int iTmp;
	char *csBuf;
	char *csTxnId;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr, "update ol_payout_request set opr_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls, "txn_seq", &csTxnId);
DEBUGLOG(("Update: txn_id = [%s]\n", csTxnId));

// aux_txn_id
	if (GetField_CString(hRls, "aux_txn_id", &csTmp)) {
DEBUGLOG(("Update: aux_txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_aux_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// merchant_payout_grp
	if (GetField_CString(hRls, "merchant_payout_grp", &csTmp)) {
DEBUGLOG(("Update: merchant_payout_grp = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_merchant_payout_grp = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// psp_payout_grp
	if (GetField_CString(hRls, "psp_payout_grp", &csTmp)) {
DEBUGLOG(("Update: psp_payout_grp = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_psp_payout_grp = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// request_currency
	if (GetField_CString(hRls, "request_currency", &csTmp)) {
DEBUGLOG(("Update: request_currency = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_request_currency = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// request_amount
	if (GetField_Double(hRls, "request_amount", &dTmp)) {
DEBUGLOG(("Update: request_amount = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_request_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// payout_currency
	if (GetField_CString(hRls, "payout_currency", &csTmp)) {
DEBUGLOG(("Update: payout_currency = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_payout_currency = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// payout_amount
	if (GetField_Double(hRls, "payout_amount", &dTmp)) {
DEBUGLOG(("Update: payout_amount = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_payout_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// member_fee_ccy
	if (GetField_CString(hRls, "member_fee_ccy", &csTmp)) {
DEBUGLOG(("Update: member_fee_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_member_fee_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// member_fee
	if (GetField_Double(hRls, "member_fee", &dTmp)) {
DEBUGLOG(("Update: member_fee = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_member_fee = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// merchant_fee_ccy
	if (GetField_CString(hRls, "merchant_fee_ccy", &csTmp)) {
DEBUGLOG(("Update: merchant_fee_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_merchant_fee_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// merchant_fee
	if (GetField_Double(hRls, "merchant_fee", &dTmp)) {
DEBUGLOG(("Update: merchant_fee = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_merchant_fee = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// markup_ccy
	if (GetField_CString(hRls, "markup_ccy", &csTmp)) {
DEBUGLOG(("Update: markup_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_markup_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// markup_amt
	if (GetField_Double(hRls, "markup_amt", &dTmp)) {
DEBUGLOG(("Update: markup_amt = [%lf]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_markup_amt = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// status
	if (GetField_Int(hRls, "status", &iTmp)) {
DEBUGLOG(("Update: status = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_status = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// generated_file_id
	if (GetField_Int(hRls, "generated_file_id", &iTmp)) {
DEBUGLOG(("Update: generated_file_id = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", opr_generated_file_id = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// psp_id
	if (GetField_CString(hRls, "psp_id", &csTmp)) {
DEBUGLOG(("Update: psp_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_psp_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// update_user
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", opr_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char*)hv_dynstmt.arr, " where opr_txn_id = '");
	strcat((char*)hv_dynstmt.arr, csTxnId);
	strcat((char*)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

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
 if (sqlca.sqlcode < 0) goto update_error;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLPayoutRequest_Update: SP_INTERNAL_ERR\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR\n"));
	return PD_INTERNAL_ERR;
}


int GetOLPayoutRequest(const char *csTxnID, hash_t *myHash)
{
	int iCnt=0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getolpayoutrequest_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_aux_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_aux_txn_id;

		/* varchar		v_merchant_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_merchant_payout_grp;

		/* varchar		v_psp_payout_grp[PD_OFL_PAYOUT_GROUP_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_psp_payout_grp;

		/* varchar		v_request_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_currency;

		double		v_request_amount;
		/* varchar		v_payout_currency[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_currency;

		double		v_payout_amount;
		/* varchar		v_member_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_fee_ccy;

		double		v_member_fee;
		/* varchar		v_merchant_fee_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_fee_ccy;

		double		v_merchant_fee;
		/* varchar		v_markup_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double		v_markup_amt;
		int		v_status;
		int		v_generated_file_id;
		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;


		short		ind_aux_txn_id = -1;
		short		ind_merchant_payout_grp = -1;
		short		ind_psp_payout_grp = -1;
		short		ind_request_currency = -1;
		short		ind_request_amount = -1;
		short		ind_payout_currency = -1;
		short		ind_payout_amount = -1;
		short		ind_member_fee_ccy = -1;
		short		ind_member_fee = -1;
		short		ind_merchant_fee_ccy = -1;
		short		ind_merchant_fee = -1;
		short		ind_markup_ccy = -1;
		short		ind_markup_amt = -1;
		short		ind_status = -1;
		short		ind_generated_file_id = -1;
		short		ind_psp_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr, csTxnID, hv_txn_id.len);
DEBUGLOG(("GetOLPayoutRequest txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_getolpayoutrequest CURSOR FOR

		SELECT	opr_aux_txn_id,
			opr_merchant_payout_grp,
			opr_psp_payout_grp,
			opr_request_currency,
			opr_request_amount,
			opr_payout_currency,
			opr_payout_amount,
			opr_member_fee_ccy,
			opr_member_fee,
			opr_merchant_fee_ccy,
			opr_merchant_fee,
			opr_markup_ccy,
			opr_markup_amt,
			opr_status,
			opr_generated_file_id,
			opr_psp_id
		FROM	ol_payout_request
		WHERE	opr_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_getolpayoutrequest; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )130;
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
 if (sqlca.sqlcode < 0) goto getolpayoutrequest_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getolpayoutrequest
		INTO
			:v_aux_txn_id:ind_aux_txn_id,
			:v_merchant_payout_grp:ind_merchant_payout_grp,
			:v_psp_payout_grp:ind_psp_payout_grp,
			:v_request_currency:ind_request_currency,
			:v_request_amount:ind_request_amount,
			:v_payout_currency:ind_payout_currency,
			:v_payout_amount:ind_payout_amount,
			:v_member_fee_ccy:ind_member_fee_ccy,
			:v_member_fee:ind_member_fee,
			:v_merchant_fee_ccy:ind_merchant_fee_ccy,
			:v_merchant_fee:ind_merchant_fee,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt,
			:v_status:ind_status,
			:v_generated_file_id:ind_generated_file_id,
			:v_psp_id:ind_psp_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 19;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )149;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_aux_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_aux_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_payout_grp;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_payout_grp;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_psp_payout_grp;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_psp_payout_grp;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_request_currency;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_request_currency;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_request_amount;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_request_amount;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_payout_currency;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_payout_currency;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_payout_amount;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_payout_amount;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_member_fee_ccy;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_member_fee_ccy;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_member_fee;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_member_fee;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_merchant_fee_ccy;
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_merchant_fee_ccy;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_fee;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_merchant_fee;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_status;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_generated_file_id;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_generated_file_id;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[15] = (unsigned long )13;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_psp_id;
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
  if (sqlca.sqlcode < 0) goto getolpayoutrequest_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

// aux_txn_id
		if (ind_aux_txn_id >= 0) {
			v_aux_txn_id.arr[v_aux_txn_id.len] = '\0';
			PutField_CString(myHash, "aux_txn_id", (const char*)v_aux_txn_id.arr);
DEBUGLOG(("aux_txn_id = [%s]\n", v_aux_txn_id.arr));
		}

// merchant_payout_grp
		if (ind_merchant_payout_grp >= 0) {
			v_merchant_payout_grp.arr[v_merchant_payout_grp.len] = '\0';
			PutField_CString(myHash, "merchant_payout_grp", (const char*)v_merchant_payout_grp.arr);
DEBUGLOG(("merchant_payout_grp = [%s]\n", v_merchant_payout_grp.arr));
		}

// psp_payout_grp
		if (ind_psp_payout_grp >= 0) {
			v_psp_payout_grp.arr[v_psp_payout_grp.len] = '\0';
			PutField_CString(myHash, "psp_payout_grp", (const char*)v_psp_payout_grp.arr);
DEBUGLOG(("psp_payout_grp = [%s]\n", v_psp_payout_grp.arr));
		}

// request_currency
		if (ind_request_currency >= 0) {
			v_request_currency.arr[v_request_currency.len] = '\0';
			PutField_CString(myHash, "request_currency", (const char*)v_request_currency.arr);
DEBUGLOG(("request_currency = [%s]\n", v_request_currency.arr));
		}

// request_amount
		if (ind_request_amount >= 0) {
			PutField_Double(myHash, "request_amount", v_request_amount);
DEBUGLOG(("request_amount = [%f]\n", v_request_amount));
		}

// payout_currency
		if (ind_payout_currency >= 0) {
			v_payout_currency.arr[v_payout_currency.len] = '\0';
			PutField_CString(myHash, "payout_currency", (const char*)v_payout_currency.arr);
DEBUGLOG(("payout_currency = [%s]\n", v_payout_currency.arr));
		}

// payout_amount
		if (ind_payout_amount >= 0) {
			PutField_Double(myHash, "payout_amount", v_payout_amount);
DEBUGLOG(("payout_amount = [%f]\n", v_payout_amount));
		}

// member_fee_ccy
		if (ind_member_fee_ccy >= 0) {
			v_member_fee_ccy.arr[v_member_fee_ccy.len] = '\0';
			PutField_CString(myHash, "member_fee_ccy", (const char*)v_member_fee_ccy.arr);
DEBUGLOG(("member_fee_ccy = [%s]\n", v_member_fee_ccy.arr));
		}

// member_fee
		if (ind_member_fee >= 0) {
			PutField_Double(myHash, "member_fee", v_member_fee);
DEBUGLOG(("member_fee = [%f]\n", v_member_fee));
		}

// merchant_fee_ccy
		if (ind_merchant_fee_ccy >= 0) {
			v_merchant_fee_ccy.arr[v_merchant_fee_ccy.len] = '\0';
			PutField_CString(myHash, "merchant_fee_ccy", (const char*)v_merchant_fee_ccy.arr);
DEBUGLOG(("merchant_fee_ccy = [%s]\n", v_merchant_fee_ccy.arr));
		}

// merchant_fee
		if (ind_merchant_fee >= 0) {
			PutField_Double(myHash, "merchant_fee", v_merchant_fee);
DEBUGLOG(("merchant_fee = [%f]\n", v_merchant_fee));
		}

// markup_ccy
		if (ind_markup_ccy >= 0) {
			v_markup_ccy.arr[v_markup_ccy.len] = '\0';
			PutField_CString(myHash, "markup_ccy", (const char*)v_markup_ccy.arr);
DEBUGLOG(("markup_ccy = [%s]\n", v_markup_ccy.arr));
		}

// markup_amt
		if (ind_markup_amt >= 0) {
			PutField_Double(myHash, "markup_amt", v_markup_amt);
DEBUGLOG(("markup_amt = [%f]\n", v_markup_amt));
		}

// status
		if (ind_status >= 0) {
			PutField_Int(myHash, "status", v_status);
DEBUGLOG(("status = [%f]\n", v_status));
		}

// generated_file_id
		if (ind_generated_file_id >= 0) {
			PutField_Int(myHash, "generated_file_id", v_generated_file_id);
DEBUGLOG(("generated_file_id = [%f]\n", v_generated_file_id));
		}

// psp_id
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] = '\0';
			PutField_CString(myHash, "psp_id", (const char*)v_psp_id.arr);
DEBUGLOG(("psp_id = [%s]\n", v_psp_id.arr));
		}

	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getolpayoutrequest; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )228;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getolpayoutrequest_error;
}



	if (iCnt>0) {
DEBUGLOG(("GetOLPayoutRequest Normal Exit\n"));
		return PD_OK;
	} else {
DEBUGLOG(("GetOLPayoutRequest NOT FOUND!!!\n"));
		return PD_ERR;
	}

getolpayoutrequest_error:
DEBUGLOG(("getolpayoutrequest code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getolpayoutrequest; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 19;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )243;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int MatchOLPayoutRequestStatus(const char* csTxnId, const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchPayoutReqStatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int hv_status;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                short ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("MatchOLPayoutRequestStatus txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchOLPayoutRequestStatus status = [%d]\n", hv_status));

        /* EXEC SQL SELECT opr_txn_id
                INTO :v_txn_id:ind_txn_id
                FROM ol_payout_request
                WHERE opr_txn_id = :hv_txn_id
                AND opr_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select opr_txn_id INTO :b0:b1 FROM ol_payout_request\
 WHERE opr_txn_id = :b2 AND opr_status = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )258;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
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
        if (sqlca.sqlcode < 0) goto MatchPayoutReqStatus_error;
}



        if (ind_txn_id >= 0) {
DEBUGLOG(("MatchOLPayoutRequestStatus Found\n"));
                return PD_FOUND;
        } else {
DEBUGLOG(("MatchOLPayoutRequestStatus Not Found\n"));
                return PD_NOT_FOUND;
        }

MatchPayoutReqStatus_error:
DEBUGLOG(("MatchPayoutReqStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int MatchOLPayoutRequestStatus_ForUpdate(const char* csTxnId, const int iStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchPayoutReqStatus_ForUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int hv_status;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                short ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("MatchOLPayoutRequestStatus_ForUpdate txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        hv_status = iStatus;
DEBUGLOG(("MatchOLPayoutRequestStatus_ForUpdate status = [%d]\n", hv_status));

        /* EXEC SQL SELECT opr_txn_id
                INTO :v_txn_id:ind_txn_id
                FROM ol_payout_request
                WHERE opr_txn_id = :hv_txn_id
                AND opr_status = :hv_status
		FOR UPDATE NOWAIT; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 19;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select opr_txn_id INTO :b0:b1 FROM ol_payout_request\
 WHERE opr_txn_id = :b2 AND opr_status = :b3 FOR UPDATE NOWAIT ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )285;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
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
        if (sqlca.sqlcode < 0) goto MatchPayoutReqStatus_ForUpdate_error;
}



        if (ind_txn_id >= 0) {
DEBUGLOG(("MatchOLPayoutRequestStatus_ForUpdate Found\n"));
                return PD_FOUND;
        } else {
DEBUGLOG(("MatchOLPayoutRequestStatus_ForUpdate Not Found\n"));
                return PD_NOT_FOUND;
        }

MatchPayoutReqStatus_ForUpdate_error:
DEBUGLOG(("MatchPayoutReqStatus_ForUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


/*
 * Reserved
 *

int GetTxnPspDetailByBAID(const char *csBAID, recordset_t* myRec)
{
	int iCnt=0;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO gettxnpspdetailbybaid_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar		hv_baid[PD_BAID_LEN];

		varchar		v_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_psp_id[PD_PSP_ID_LEN + 1];
		varchar		v_txn_ccy[PD_CCY_ID_LEN + 1];
		double		v_txn_amount;
		varchar		v_txn_date[PD_DATE_LEN + 1];
		varchar		v_txn_time[PD_TIME_LEN + 1];
		varchar		v_txn_timestamp[PD_DATETIME_LEN + 1];
		varchar		v_bank_code[PD_BANK_CODE_LEN + 1];
		varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1];
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
		varchar		v_customer_text[PD_TFR_CUSTOMER_TEXT_LEN + 1];
		varchar		v_sender_name[PD_SENDER_NAME_LEN + 1];
		varchar		v_txn_ref_num[PD_TXN_REF_NUM_LEN + 1];
		int		v_charge_rule_id;
		char		v_charge_period_type;
		double		v_precal_charge;
		varchar		v_grp_tracking_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_tracking_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_report_date[PD_DATE_LEN + 1];
		varchar		v_settlement_date[PD_DATE_LEN + 1];
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

	EXEC SQL END DECLARE SECTION;

	hv_baid.len = strlen(csBAID);
	memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("GetTxnPspDetailByBAID baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	EXEC SQL DECLARE c_cursor_gettxnpspdetailbybaid CURSOR FOR
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
		order by otp_create_timestamp;

	EXEC SQL OPEN c_cursor_gettxnpspdetailbybaid;
	do {
		EXEC SQL FETCH c_cursor_gettxnpspdetailbybaid
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
			:v_manual_hold_recon:ind_manual_hold_recon;

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

	EXEC SQL CLOSE c_cursor_gettxnpspdetailbybaid;

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
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	EXEC SQL CLOSE c_cursor_gettxnpspdetailbybaid;
	return PD_ERR;
}


int GetTxnCountByBankAcct(const char* csBankCode, const char* csBankAcctNum)
{
        EXEC SQL WHENEVER SQLERROR GOTO getcnt_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;

		varchar hv_bank_code[PD_BANK_CODE_LEN];
		varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN];
                int     v_cnt;

        EXEC SQL END DECLARE SECTION;

	hv_bank_code.len = strlen(csBankCode);
        strncpy((char*)hv_bank_code.arr,csBankCode,hv_bank_code.len);
DEBUGLOG(("GetTxnCountByBankAcct bank_code = [%s]\n",csBankCode));

	hv_bank_acct_num.len = strlen(csBankAcctNum);
        strncpy((char*)hv_bank_acct_num.arr,csBankAcctNum,hv_bank_acct_num.len);
DEBUGLOG(("GetTxnCountByBankAcct bank_acct_num = [%s]\n",csBankAcctNum));

        EXEC SQL        SELECT  count(*)
                        INTO    :v_cnt
                        FROM    ol_txn_psp_detail
			WHERE	otp_bank_code = :hv_bank_code
			AND	otp_bank_acct_num = :hv_bank_acct_num;

DEBUGLOG(("GetTxnCountByBankAcct() Normal Exit! record found = [%d]\n", v_cnt));
        return v_cnt;

getcnt_error:
DEBUGLOG(("getcountbybaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
 	return PD_ERR; 
}
*/

int ResumeGeneratedFile(const char* csFileId, const char* csUser)
{
        char*   csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO resumegfile_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("ResumeGeneratedFile: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update ol_payout_request set opr_psp_id ='',opr_generated_file_id='', opr_status = 65 , opr_update_timestamp = sysdate ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, ",opr_update_user= '");
        strcat((char*)hv_dynstmt.arr, csUser);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        strcat((char*)hv_dynstmt.arr, " WHERE opr_generated_file_id = ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        strcat((char*)hv_dynstmt.arr, " AND opr_status = 70");
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
        sqlstm.offset = (unsigned int  )312;
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
        if (sqlca.sqlcode < 0) goto resumegfile_error;
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
        sqlstm.offset = (unsigned int  )331;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto resumegfile_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("ResumeGeneratedFile Normal Exit\n"));
        return PD_OK;

resumegfile_error:
DEBUGLOG(("resumefile_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLPayoutRequest_ResumeGeneratedFile: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
