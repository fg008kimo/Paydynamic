
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
    "MmsInstantTxnInqDt.pc"
};


static unsigned int sqlctx = 162838683;


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
   unsigned char  *sqhstv[22];
   unsigned long  sqhstl[22];
            int   sqhsts[22];
            short *sqindv[22];
            int   sqinds[22];
   unsigned long  sqharm[22];
   unsigned long  *sqharc[22];
   unsigned short  sqadto[22];
   unsigned short  sqtdso[22];
} sqlstm = {12,22};

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
5,0,0,1,693,0,6,238,0,0,22,22,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
108,0,0,2,220,0,6,738,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,9,0,0,2,
9,0,0,
147,0,0,0,0,0,56,886,0,0,1,1,0,1,0,3,102,0,0,
166,0,0,3,176,0,6,888,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,2,102,0,0,
201,0,0,0,0,0,13,925,0,0,20,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,
296,0,0,0,0,0,15,1095,0,0,1,1,0,1,0,1,102,0,0,
315,0,0,0,0,0,15,1100,0,0,1,1,0,1,0,1,102,0,0,
334,0,0,0,0,0,15,1105,0,0,1,1,0,1,0,1,102,0,0,
353,0,0,0,0,0,15,1109,0,0,1,1,0,1,0,1,102,0,0,
372,0,0,0,0,0,15,1119,0,0,1,1,0,1,0,1,102,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/12/23              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sqlca.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "MmsInstantTxnInqDt.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


char    cDebug;

void MmsInstantTxnInqDt(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
	char  cTmp;
	char  *csTmp;
        double	dTmp = 0.0;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

	 
		/* varchar		hv_inq_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_inq_id;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_dtl_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_dtl_txn_id;

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		/* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar         hv_mb_id[PD_MB_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_mb_id;

		/* varchar         hv_bank_id[PD_BANK_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_bank_id;

		char            hv_status;
		char            hv_ar_ind;
		char            hv_isd_ind;
		/* varchar         hv_txn_date[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_txn_date;

		double          hv_txn_amt;
		/* varchar         hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		double          hv_adjustment;
		double          hv_exchange_rate;
		double          hv_processing_cost;
		double          hv_bank_charge;
		double          hv_bank_charge_refund;
		/* varchar         hv_filing_number[PD_VERSION_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_filing_number;

		/* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short		ind_inq_id = -1;
		short		ind_txn_id = -1;
		short		ind_dtl_txn_id = -1;
		short		ind_txn_code = -1;
		short           ind_merchant_id = -1;
		short           ind_psp_id = -1;
		short           ind_mb_id = -1;
		short           ind_bank_id = -1;
		short           ind_status = -1;
		short           ind_ar_ind = -1;
		short           ind_isd_ind = -1;
		short           ind_txn_date = -1;
		short           ind_txn_amt = -1;
		short           ind_txn_ccy = -1;
		short           ind_adjustment = -1;
		short           ind_exchange_rate = -1;
		short           ind_processing_cost = -1;
		short           ind_bank_charge = -1;
		short           ind_bank_charge_refund = -1;
		short           ind_filing_number = -1;
		short		ind_add_user = -1;

		short		hv_return_value;	
		
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hRls, "inq_seq", &csTmp)) {
                hv_inq_id.len = strlen(csTmp);
                memcpy(hv_inq_id.arr, csTmp, hv_inq_id.len);
                ind_inq_id = 0;
DEBUGLOG(("AddDetail:inq_id = [%.*s][%d]\n",hv_inq_id.len, hv_inq_id.arr, hv_inq_id.len));
	}

        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddDetail:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

        if (GetField_CString(hRls,"dtl_txn_seq",&csTmp)) {
                hv_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_dtl_txn_id.arr,csTmp,hv_dtl_txn_id.len);
                ind_dtl_txn_id = 0;
DEBUGLOG(("AddDetail:dtl_txn_id = [%.*s][%d]\n",hv_dtl_txn_id.len, hv_dtl_txn_id.arr, hv_dtl_txn_id.len));
        }

        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("AddDetail:txn_code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len));
        }

        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("AddDetail:merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));
        }

        if (GetField_CString(hRls,"psp_id",&csTmp)) {
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("AddDetail:psp_id = [%.*s][%d]\n",hv_psp_id.len,hv_psp_id.arr,hv_psp_id.len));
        }


        if (GetField_CString(hRls,"mb_id",&csTmp)) {
                hv_mb_id.len = strlen(csTmp);
                memcpy(hv_mb_id.arr,csTmp,hv_mb_id.len);
                ind_mb_id = 0;
DEBUGLOG(("AddDetail:mb_id = [%.*s][%d]\n",hv_mb_id.len,hv_mb_id.arr,hv_mb_id.len));
        }

        if (GetField_CString(hRls,"bank_id",&csTmp)) {
                hv_bank_id.len = strlen(csTmp);
                memcpy(hv_bank_id.arr,csTmp,hv_bank_id.len);
                ind_bank_id = 0;
DEBUGLOG(("AddDetail:bank_id = [%.*s][%d]\n",hv_bank_id.len,hv_bank_id.arr,hv_bank_id.len));
        }


        if (GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddDetail:status = [%c]\n",hv_status));
        }

        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
                hv_ar_ind = cTmp;
                ind_ar_ind = 0;
DEBUGLOG(("AddDetail:ar_ind = [%c]\n",hv_ar_ind));
        }

        if (GetField_Char(hRls,"isd_ind",&cTmp)) {
                hv_isd_ind = cTmp;
                ind_isd_ind = 0;
DEBUGLOG(("AddDetail:isd_ind = [%c]\n",hv_isd_ind));
        }

        if (GetField_CString(hRls,"txn_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
                ind_txn_date = 0;
DEBUGLOG(("AddDetail:txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
        }

        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_txn_amt = dTmp;
                ind_txn_amt = 0;
DEBUGLOG(("AddDetail:txn_amt = [%lf]\n",hv_txn_amt));
	}

        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("AddDetail:txn_ccy = [%.*s][%d]\n",hv_txn_ccy.len,hv_txn_ccy.arr,hv_txn_ccy.len));
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

/* processing_cost */
        if (GetField_Double(hRls,"processing_cost",&dTmp)) {
                hv_processing_cost= dTmp;
                ind_processing_cost= 0;
DEBUGLOG(("AddDetail:processing_cost = [%lf]\n",hv_processing_cost));
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

/* filing_number */
        if (GetField_Double(hRls,"filing_number",&csTmp)) {
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
			:hv_return_value := sp_mms_instant_txn_inq_dt_ins(
						:hv_inq_id:ind_inq_id,
                                                :hv_txn_id:ind_txn_id,
                                                :hv_dtl_txn_id:ind_dtl_txn_id,
                                                :hv_txn_code:ind_txn_code,
                                                :hv_merchant_id:ind_merchant_id,
                                                :hv_psp_id:ind_psp_id,
                                                :hv_mb_id:ind_mb_id,
                                                :hv_bank_id:ind_bank_id,
                                                :hv_status:ind_status,
                                                :hv_ar_ind:ind_ar_ind,
                                                :hv_isd_ind:ind_isd_ind,
                                                :hv_txn_date:ind_txn_date, 
                                                :hv_txn_amt:ind_txn_amt,
                                                :hv_txn_ccy:ind_txn_ccy,
                                                :hv_adjustment:ind_adjustment,
                                                :hv_exchange_rate:ind_exchange_rate,
                                                :hv_processing_cost:ind_processing_cost,
                                                :hv_bank_charge:ind_bank_charge,
                                                :hv_bank_charge_refund:ind_bank_charge_refund,
                                                :hv_filing_number:ind_filing_number,
                                                :hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_txn_inq_dt_ins ( :\
hv_inq_id:ind_inq_id , :hv_txn_id:ind_txn_id , :hv_dtl_txn_id:ind_dtl_txn_id \
, :hv_txn_code:ind_txn_code , :hv_merchant_id:ind_merchant_id , :hv_psp_id:in\
d_psp_id , :hv_mb_id:ind_mb_id , :hv_bank_id:ind_bank_id , :hv_status:ind_sta\
tus , :hv_ar_ind:ind_ar_ind , :hv_isd_ind:ind_isd_ind , :hv_txn_date:ind_txn_\
date , :hv_txn_amt:ind_txn_amt , :hv_txn_ccy:ind_txn_ccy , :hv_adjustment:ind\
_adjustment , :hv_exchange_rate:ind_exchange_rate , :hv_processing_cost:ind_p\
rocessing_cost , :hv_bank_charge:ind_bank_charge , :hv_bank_charge_refund:ind\
_bank_charge_refund , :hv_filing_number:ind_filing_number , :hv_add_user:ind_\
add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_inq_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_inq_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_dtl_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_dtl_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_txn_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[5] = (unsigned long )17;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[6] = (unsigned long )12;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_psp_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_mb_id;
 sqlstm.sqhstl[7] = (unsigned long )17;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_mb_id;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_id;
 sqlstm.sqhstl[8] = (unsigned long )17;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_bank_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[9] = (unsigned long )1;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_status;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[10] = (unsigned long )1;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_ar_ind;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_isd_ind;
 sqlstm.sqhstl[11] = (unsigned long )1;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_isd_ind;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[12] = (unsigned long )16;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_txn_date;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_txn_amt;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_txn_amt;
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
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_adjustment;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_adjustment;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_exchange_rate;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_exchange_rate;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_processing_cost;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_processing_cost;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_bank_charge;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_bank_charge;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_bank_charge_refund;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_bank_charge_refund;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_filing_number;
 sqlstm.sqhstl[20] = (unsigned long )4;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_filing_number;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[21] = (unsigned long )22;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_add_user;
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
        if (hv_return_value == SP_OK)
        {
                DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
                ERRLOG("MmsInstantTxnInqDt_Add: SP_OTHER_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
                ERRLOG("MmsInstantTxnInqDt_Add: SP_ERR TxnAbort\n");
                DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }


add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsInstantTxnInqDt_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
        return PD_ERR;


}

/* **************************
int GetNextRecSeq(const char *csInqSeq,
		const char *csTxnSeq,
		const char *csDtlTxnSeq,
		char *csNextTxnSeq,
		char *csNextDtlTxnSeq)
{

        int iRet = PD_ERR;

        EXEC SQL WHENEVER SQLERROR GOTO getnextrecordseq_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		varchar		hv_inq_id[PD_TXN_SEQ_LEN];
		varchar		hv_txn_id[PD_TXN_SEQ_LEN];
		varchar		hv_dtl_txn_id[PD_TXN_SEQ_LEN];

		varchar		v_next_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_next_dtl_txn_id[PD_TXN_SEQ_LEN + 1];

		short		ind_next_txn_id = -1;
		short		ind_next_dtl_txn_id = -1;

        EXEC SQL END DECLARE SECTION;

	hv_inq_id.len = strlen(csInqSeq);
	memcpy(hv_inq_id.arr, csInqSeq, hv_inq_id.len);
DEBUGLOG(("GetNextRecSeq inq_id = [%d]][%.*s]\n", hv_inq_id.len, hv_inq_id.len, hv_inq_id.arr));

	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("GetNextRecSeq txn_id = [%d]][%.*s]\n", hv_txn_id.len, hv_txn_id.len, hv_txn_id.arr));

        hv_dtl_txn_id.len = strlen(csDtlTxnSeq);
        memcpy(hv_dtl_txn_id.arr, csDtlTxnSeq, hv_dtl_txn_id.len);
DEBUGLOG(("GetNextRecSeq dtl_txn_id = [%d][%.*s]\n", hv_dtl_txn_id.len, hv_dtl_txn_id.len, hv_dtl_txn_id.arr));

	EXEC SQL DECLARE c_cursor_getnextrecordseq CURSOR FOR
                select b.mid_txn_id, b.mid_dtl_txn_id
                from
                        (select a.mid_txn_id, a.mid_dtl_txn_id
			   from mms_instant_txn_inq_dt a
			  where a.mid_inq_id = :hv_inq_id
		            and ((a.mid_txn_id > :hv_txn_id) or 
			         (a.mid_txn_id >= :hv_txn_id) and (a.mid_dtl_txn_id > :hv_dtl_txn_id)
			        )	
			order by a.mid_txn_id, a.mid_dtl_txn_id
			) b
		where rownum = 1;

	EXEC SQL OPEN c_cursor_getnextrecordseq;

        EXEC SQL FETCH c_cursor_getnextrecordseq
        INTO
		:v_next_txn_id:ind_next_txn_id,
		:v_next_dtl_txn_id:ind_next_dtl_txn_id;


	if (SQLCODE == SQL_NOT_FOUND) {
DEBUGLOG(("GetNextRecordSeq not found\n"));
                iRet = PD_NOT_FOUND;
DEBUGLOG(("GetNextPartyId Normal Exit, no record found\n"));
	} 
	else {

		iRet = PD_OK;

		if (ind_next_txn_id >= 0) {
                	v_next_txn_id.arr[v_next_txn_id.len] = '\0';
                	strcpy(csNextTxnSeq, (const char*) v_next_txn_id.arr);
DEBUGLOG(("GetNextRecordSeq txn_seq = [%s]\n",csNextTxnSeq));
		}

		if (ind_next_dtl_txn_id >= 0) {
                	v_next_dtl_txn_id.arr[v_next_dtl_txn_id.len] = '\0';
                	strcpy(csNextDtlTxnSeq, (const char*) v_next_dtl_txn_id.arr);
DEBUGLOG(("GetNextRecordSeq dtl_txn_seq = [%s]\n",csNextDtlTxnSeq));
		}
DEBUGLOG(("GetNextPartyId Normal Exit\n"));
	}

        EXEC SQL CLOSE c_cursor_getnextrecordseq;

        return iRet;

getnextrecordseq_error:
DEBUGLOG(("getnextrecordseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        EXEC SQL CLOSE c_cursor_getnextrecordseq;
        return PD_ERR;


}
************************* */

/* *******************************************************
int GetDetailRec(const char *csInqSeq,
		const char *csTxnSeq,
		const char *csDtlTxnSeq,
		recordset_t *myRec)
{
        int     iCnt = 0;
        hash_t *myHash;

        EXEC SQL WHENEVER SQLERROR GOTO getdetailrec_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		varchar		hv_inq_id[PD_TXN_SEQ_LEN];
		varchar		hv_txn_id[PD_TXN_SEQ_LEN];
		varchar		hv_dtl_txn_id[PD_TXN_SEQ_LEN];


		varchar		v_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_dtl_txn_id[PD_TXN_SEQ_LEN + 1];
		varchar		v_txn_code[PD_TXN_CODE_LEN + 1];
                varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1];
                varchar         v_psp_id[PD_PSP_ID_LEN + 1];
                varchar         v_mb_id[PD_MB_ID_LEN + 1];
                varchar         v_bank_id[PD_BANK_ID_LEN + 1];
                char            v_status;
                char            v_ar_ind;
                char            v_isd_ind;
                varchar         v_txn_date[PD_DATE_LEN + PD_TIME_LEN + 1];
                double          v_txn_amt;
                varchar         v_txn_ccy[PD_CCY_ID_LEN + 1];
                double          v_adjustment;
                double          v_exchange_rate;
                double          v_processing_cost;
                double          v_bank_charge;
                double          v_bank_charge_refund;
                varchar         v_filing_number[PD_VERSION_NO_LEN + 1];

		short		ind_txn_id = -1;
		short		ind_dtl_txn_id = -1;
		short		ind_txn_code = -1;
		short		ind_merchant_id = -1;
		short		ind_psp_id = -1;
		short		ind_mb_id = -1;
		short		ind_bank_id = -1;
		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_isd_ind = -1;
		short		ind_txn_date = -1;
		short		ind_txn_amt = -1;
		short		ind_txn_ccy = -1;
		short		ind_adjustment = -1;
		short		ind_exchange_rate = -1;
		short		ind_processing_cost = -1;
		short		ind_bank_charge = -1;
		short		ind_bank_charge_refund = -1;
		short		ind_filing_number = -1;

	EXEC SQL END DECLARE SECTION;

	hv_inq_id.len = strlen(csInqSeq);
	memcpy(hv_inq_id.arr, csInqSeq, hv_inq_id.len);
DEBUGLOG(("GetDetailRec inq_id = [%.*s]\n",hv_inq_id.len, hv_inq_id.arr));

        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("GetDetailRec txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));

        hv_dtl_txn_id.len = strlen(csDtlTxnSeq);
        memcpy(hv_dtl_txn_id.arr, csDtlTxnSeq, hv_dtl_txn_id.len);
DEBUGLOG(("GetDetailRec dtl_txn_id = [%.*s]\n",hv_dtl_txn_id.len, hv_dtl_txn_id.arr));

        EXEC SQL DECLARE c_cursor_getdetailrec CURSOR FOR
                select mid_txn_id,
                       mid_dtl_txn_id,
                       mid_txn_code,
                       mid_merchant_id,
                       mid_psp_id,
                       mid_mb_id,
                       mid_bank_id,
                       mid_status,
                       mid_ar_ind,
                       mid_isd_ind,
                       mid_txn_date,
                       mid_txn_amt,
                       mid_txn_ccy,
                       mid_adjustment,
                       mid_exchange_rate,
                       mid_processing_cost,
                       mid_bank_charge,
                       mid_bank_charge_refund,
                       mid_filing_number
                  from mms_instant_txn_inq_dt
                 where mid_inq_id = :hv_inq_id
		   and (
			(mid_txn_id > :hv_txn_id) or
			(
			 (mid_txn_id >= :hv_txn_id) and 
                         (mid_dtl_txn_id >= decode(:hv_dtl_txn_id, '<NULL>', mid_dtl_txn_id, :hv_dtl_txn_id))
			)
		       )
                order by mid_txn_id, mid_dtl_txn_id;

	EXEC SQL OPEN c_cursor_getdetailrec;
	do {
		EXEC SQL FETCH c_cursor_getdetailrec
                INTO    :v_txn_id:ind_txn_id,
                        :v_dtl_txn_id:ind_dtl_txn_id,
                        :v_txn_code:ind_txn_code,
                        :v_merchant_id:ind_merchant_id,
                        :v_psp_id:ind_psp_id,
                        :v_mb_id:ind_mb_id,
                        :v_bank_id:ind_bank_id,
                        :v_status:ind_status,
                        :v_ar_ind:ind_ar_ind,
                        :v_isd_ind:ind_isd_ind,
                        :v_txn_date:ind_txn_date,
                        :v_txn_amt:ind_txn_amt,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_adjustment:ind_adjustment,
                        :v_exchange_rate:ind_exchange_rate,
                        :v_processing_cost:ind_processing_cost,
                        :v_bank_charge:ind_bank_charge,
                        :v_bank_charge_refund:ind_bank_charge_refund,
                        :v_filing_number:ind_filing_number;

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

// txn_id 
                if (ind_txn_id >= 0) {
                        v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash, "txn_seq", (const char *)v_txn_id.arr);
DEBUGLOG(("GetDetailRec txn_id = [%s]\n",v_txn_id.arr));
                }

// dtl_txn_id 
                if (ind_dtl_txn_id >= 0) {
                        v_dtl_txn_id.arr[v_dtl_txn_id.len] = '\0';
                        PutField_CString(myHash, "dtl_txn_seq", (const char *)v_dtl_txn_id.arr);
DEBUGLOG(("GetDetailRec dtl_txn_id = [%s]\n",v_dtl_txn_id.arr));
                }

// txn_code 
                if (ind_txn_code >= 0) {
                        v_txn_code.arr[v_txn_code.len] = '\0';
                        PutField_CString(myHash, "txn_code", (const char *)v_txn_code.arr);
DEBUGLOG(("GetDetailRec txn_code = [%s]\n",v_txn_code.arr));
                }

// merchant_id 
                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetDetailRec merchant_id = [%s]\n",v_merchant_id.arr));
                }

// psp_id 
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] ='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailRec psp_id = [%s]\n",v_psp_id.arr));
                }

// mb_id 
                if (ind_mb_id >= 0) {
                        v_mb_id.arr[v_mb_id.len] ='\0';
                        PutField_CString(myHash,"mb_id",(const char*)v_mb_id.arr);
DEBUGLOG(("GetDetailRec mb_id = [%s]\n",v_mb_id.arr));
                }

// bank_id 
                if (ind_bank_id >= 0) {
                        v_bank_id.arr[v_bank_id.len] ='\0';
                        PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetDetailRec bank_id = [%s]\n",v_bank_id.arr));
                }

// status 
                if (ind_status >= 0) {
                        PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetDetailRec status = [%c]\n",v_status));
                }

// ar_ind 
                if (ind_ar_ind >= 0) {
                        PutField_Char(myHash,"ar_ind",v_ar_ind);
DEBUGLOG(("GetDetailRec ar_ind = [%c]\n",v_ar_ind));
                }

// isd_ind 
                if (ind_isd_ind >= 0) {
                        PutField_Char(myHash,"isd_ind",v_isd_ind);
DEBUGLOG(("GetDetailRec isd_ind = [%c]\n",v_isd_ind));
                }

// txn_date 
                if (ind_txn_date >= 0) {
                        v_txn_date.arr[v_txn_date.len] ='\0';
                        PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetDetailRec txn_date = [%s]\n",v_txn_date.arr));
                }

// txn_amt 
                if (ind_txn_amt < 0) {
                        v_txn_amt = 0.0;
                }
                PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetDetailRec txn_amt = [%f]\n",v_txn_amt));

// txn_ccy 
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetDetailRec txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

// adjustment 
                if (ind_adjustment < 0) {
                        v_adjustment = 0.0;
                }
                PutField_Double(myHash, "adjustment", v_adjustment);
DEBUGLOG(("GetDetailRec adjustment = [%f]\n",v_adjustment));

// exchange_rate 
                if (ind_exchange_rate < 0) {
                        v_exchange_rate = 0.0;
                }
                PutField_Double(myHash, "exchange_rate", v_exchange_rate);
DEBUGLOG(("GetDetailRec exchange_rate = [%f]\n",v_exchange_rate));

// processing_cost 
                if (ind_processing_cost < 0) {
                        v_processing_cost = 0.0;
                }
                PutField_Double(myHash, "processing_cost", v_processing_cost);
DEBUGLOG(("GetDetailRec processing_cost = [%f]\n",v_processing_cost));

// bank_charge 
                if (ind_bank_charge < 0) {
                        v_bank_charge = 0.0;
                }
                PutField_Double(myHash, "bank_charge", v_bank_charge);
DEBUGLOG(("GetDetailRec bank_charge = [%f]\n",v_bank_charge));

// bank_charge_refund 
                if (ind_bank_charge_refund < 0) {
                        v_bank_charge_refund = 0.0;
                }
                PutField_Double(myHash, "bank_charge_refund", v_bank_charge_refund);
DEBUGLOG(("GetDetailRec bank_charge_refund = [%f]\n",v_bank_charge_refund));

// filing_number 
                if (ind_filing_number >= 0) {
                        v_filing_number.arr[v_filing_number.len] ='\0';
                        PutField_CString(myHash,"filing_number",(const char*)v_filing_number.arr);
DEBUGLOG(("GetDetailRec filing_number = [%s]\n",v_filing_number.arr));
                }

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

        EXEC SQL CLOSE c_cursor_getdetailrec;

        if (iCnt > 0 ) {
DEBUGLOG(("GetDetailRec Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetDetailRec Normal Exit, Not Found\n"));
                return PD_ERR;
        }


getdetailrec_error:
DEBUGLOG(("getdetailrec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        EXEC SQL CLOSE c_cursor_getdetailrec;
        return PD_ERR;

}

*************************************************** */

int GetNextRecSeq(const hash_t *hRec,
                 char *csNextTxnSeq,
                 char *csNextDtlTxnSeq)
{
	char *csTmp = NULL;

        /* EXEC SQL WHENEVER SQLERROR GOTO getnextrecordseq_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short		hv_return_value;

                /* varchar         hv_inq_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_inq_id;

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_dtl_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_dtl_txn_id;


                /* varchar         v_next_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_next_txn_id;

                /* varchar         v_next_dtl_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_next_dtl_txn_id;


		short		ind_inq_id = -1;
		short		ind_txn_id = -1;
		short		ind_dtl_txn_id = -1;

                short           ind_next_txn_id = -1;
                short           ind_next_dtl_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec, "inq_id", &csTmp)) {
        	hv_inq_id.len = strlen(csTmp);
	        memcpy(hv_inq_id.arr, csTmp, hv_inq_id.len);
		ind_inq_id = 0;
DEBUGLOG(("GetNextRecSeq inq_id = [%d][%.*s]\n", hv_inq_id.len, hv_inq_id.len, hv_inq_id.arr));
	}

	if (GetField_CString(hRec, "txn_id", &csTmp)) {
	        hv_txn_id.len = strlen(csTmp);
        	memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("GetNextRecSeq txn_id = [%d]][%.*s]\n", hv_txn_id.len, hv_txn_id.len, hv_txn_id.arr));
	}

	if (GetField_CString(hRec, "dtl_txn_id", &csTmp)) {
	        hv_dtl_txn_id.len = strlen(csTmp);
	        memcpy(hv_dtl_txn_id.arr, csTmp, hv_dtl_txn_id.len);
		ind_dtl_txn_id = 0;
DEBUGLOG(("GetNextRecSeq dtl_txn_id = [%d][%.*s]\n", hv_dtl_txn_id.len, hv_dtl_txn_id.len, hv_dtl_txn_id.arr));
	}

DEBUGLOG(("call sp_mms_instant_txn_inq_dt_next\n"));

	/* EXEC SQL EXECUTE
		BEGIN

			:hv_return_value := sp_mms_instant_txn_inq_dt_next(:hv_inq_id:ind_inq_id,
									   :hv_txn_id:ind_txn_id,
									   :hv_dtl_txn_id:ind_dtl_txn_id,
								           :v_next_txn_id:ind_next_txn_id,
								           :v_next_dtl_txn_id:ind_next_dtl_txn_id);	

									
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_txn_inq_dt_next ( \
:hv_inq_id:ind_inq_id , :hv_txn_id:ind_txn_id , :hv_dtl_txn_id:ind_dtl_txn_id\
 , :v_next_txn_id:ind_next_txn_id , :v_next_dtl_txn_id:ind_next_dtl_txn_id ) \
; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )108;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_inq_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_inq_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_dtl_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_dtl_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_next_txn_id;
 sqlstm.sqhstl[4] = (unsigned long )19;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_next_txn_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_next_dtl_txn_id;
 sqlstm.sqhstl[5] = (unsigned long )19;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_next_dtl_txn_id;
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
 if (sqlca.sqlcode < 0) goto getnextrecordseq_error;
}



DEBUGLOG(("hv_return_value [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
		if (ind_next_txn_id >= 0) {
	                v_next_txn_id.arr[v_next_txn_id.len] = '\0';
			strcpy(csNextTxnSeq, (const char*) v_next_txn_id.arr);
DEBUGLOG(("GetNextRecSeq next txn_id = [%.*s] [%s]\n", v_next_txn_id.len, v_next_txn_id.arr, csNextTxnSeq));
		}

		if (ind_next_dtl_txn_id >= 0) {
			v_next_dtl_txn_id.arr[v_next_dtl_txn_id.len] = '\0';
			strcpy(csNextDtlTxnSeq, (const char*) v_next_dtl_txn_id.arr);
DEBUGLOG(("GetNextRecSeq next dtl_txn_id = [%.*s] [%s]\n", v_next_dtl_txn_id.len, v_next_dtl_txn_id.arr, csNextDtlTxnSeq));
		}

DEBUGLOG(("GetNextRecSeq Normal Exit\n"));
                return PD_OK;
	}
        else if (hv_return_value == SP_OTHER_ERR) {
DEBUGLOG(("GetNextRecSeq Other error\n"));
                return PD_ERR;
        }
        else  {
DEBUGLOG(("GetNextRecSeq Normal Exit, no more next txn records\n"));
                return PD_NOT_FOUND;
        }

getnextrecordseq_error:
DEBUGLOG(("getnextrecordseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

//        EXEC SQL CLOSE c_cursor_getnextrecordseq;
        return PD_ERR;


}




int GetDetailbyRange(hash_t *hRec, 
                recordset_t *myRec)
{
	int	iRet = PD_OK;
        int     iCnt = 0;

        char    *csTmp = NULL;
        int     iRowNum = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getdetailbyrange_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		short		hv_return_value;

                /* varchar         hv_inq_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_inq_id;

                /* varchar         hv_req_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_txn_id;

                /* varchar         hv_req_dtl_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_dtl_txn_id;



                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_dtl_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_dtl_txn_id;

                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_mb_id[PD_MB_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mb_id;

                /* varchar         v_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_bank_id;

                char            v_status;
                char            v_ar_ind;
                char            v_isd_ind;
                /* varchar         v_txn_date[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_txn_date;

                double          v_txn_amt;
                /* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double          v_adjustment;
                double          v_exchange_rate;
                double          v_processing_cost;
                double          v_bank_charge;
                double          v_bank_charge_refund;
                /* varchar         v_filing_number[PD_VERSION_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_filing_number;


		short		ind_inq_id = -1;
		short		ind_req_txn_id = -1;
		short		ind_req_dtl_txn_id = -1;

                short           ind_txn_id = -1;
                short           ind_dtl_txn_id = -1;
                short           ind_txn_code = -1;
                short           ind_merchant_id = -1;
                short           ind_psp_id = -1;
                short           ind_mb_id = -1;
                short           ind_bank_id = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_isd_ind = -1;
                short           ind_txn_date = -1;
                short           ind_txn_amt = -1;
                short           ind_txn_ccy = -1;
                short           ind_adjustment = -1;
                short           ind_exchange_rate = -1;
                short           ind_processing_cost = -1;
                short           ind_bank_charge = -1;
                short           ind_bank_charge_refund = -1;
                short           ind_filing_number = -1;

		SQL_CURSOR	c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec, "inq_id", &csTmp)) {
        	hv_inq_id.len = strlen(csTmp);
	        memcpy(hv_inq_id.arr, csTmp, hv_inq_id.len);
		ind_inq_id = 0;
DEBUGLOG(("GetDetailbyRange inq_id = [%.*s]\n",hv_inq_id.len, hv_inq_id.arr));
	}

	if (GetField_CString(hRec, "start_txn_id", &csTmp)) {
        	hv_req_txn_id.len = strlen(csTmp);
	        memcpy(hv_req_txn_id.arr, csTmp, hv_req_txn_id.len);
		ind_req_txn_id = 0;
DEBUGLOG(("GetDetailbyRange start txn_id = [%.*s]\n",hv_req_txn_id.len, hv_req_txn_id.arr));
	}

	if (GetField_CString(hRec, "start_dtl_txn_id", &csTmp)) {
        	hv_req_dtl_txn_id.len = strlen(csTmp);
	        memcpy(hv_req_dtl_txn_id.arr, csTmp, hv_req_dtl_txn_id.len);
		ind_req_dtl_txn_id = 0;
DEBUGLOG(("GetDetailRec start dtl_txn_id = [%.*s]\n",hv_req_dtl_txn_id.len, hv_req_dtl_txn_id.arr));
	}

        if (GetField_Int(hRec, "max_rtn", &iRowNum)) {
DEBUGLOG(("GetDetailbyRange max_rtn = [%d]\n", iRowNum));
        }

	/* EXEC SQL ALLOCATE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )147;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}



	/* EXEC SQL EXECUTE
		BEGIN	
			:hv_return_value := sp_mms_instant_txn_inq_dt_rec(:hv_inq_id:ind_inq_id,
									  :hv_req_txn_id:ind_req_txn_id,
									  :hv_req_dtl_txn_id:ind_req_dtl_txn_id,
									  :c_cursor_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 22;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_instant_txn_inq_dt_rec ( :\
hv_inq_id:ind_inq_id , :hv_req_txn_id:ind_req_txn_id , :hv_req_dtl_txn_id:ind\
_req_dtl_txn_id , :c_cursor_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_inq_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_inq_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_req_txn_id;
 sqlstm.sqhstl[2] = (unsigned long )18;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_req_txn_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_req_dtl_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_req_dtl_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&c_cursor_id;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}




	if (hv_return_value == SP_OK) {
DEBUGLOG(("GetDetailbyRange found record\n"));
                for (;;) {
                	myHash = (hash_t*) malloc (sizeof(hash_t));
	                hash_init(myHash,0);

			ind_txn_id = -1;
			ind_dtl_txn_id = -1;
			ind_txn_code = -1;
			ind_merchant_id = -1;
			ind_psp_id = -1;
			ind_mb_id = -1;
			ind_bank_id = -1;
			ind_status = -1;
			ind_ar_ind = -1;
			ind_isd_ind = -1;
			ind_txn_date = -1;
			ind_txn_amt = -1;
			ind_txn_ccy = -1;
			ind_adjustment = -1;
			ind_exchange_rate = -1;
			ind_processing_cost = -1;
			ind_bank_charge = -1;
			ind_bank_charge_refund = -1;
			ind_filing_number = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                        INTO    :v_txn_id:ind_txn_id,
                        	:v_dtl_txn_id:ind_dtl_txn_id,
	                        :v_txn_code:ind_txn_code,
				:v_merchant_id:ind_merchant_id,
				:v_psp_id:ind_psp_id,
				:v_mb_id:ind_mb_id,
				:v_bank_id:ind_bank_id,
				:v_status:ind_status,
				:v_ar_ind:ind_ar_ind,
				:v_isd_ind:ind_isd_ind,
				:v_txn_date:ind_txn_date,
				:v_txn_amt:ind_txn_amt,
				:v_txn_ccy:ind_txn_ccy,
				:v_adjustment:ind_adjustment,
				:v_exchange_rate:ind_exchange_rate,
				:v_processing_cost:ind_processing_cost,
				:v_bank_charge:ind_bank_charge,
				:v_bank_charge_refund:ind_bank_charge_refund,
				:v_filing_number:ind_filing_number; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 22;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )201;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_dtl_txn_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_dtl_txn_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
                        sqlstm.sqhstl[3] = (unsigned long )6;
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_txn_code;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_id;
                        sqlstm.sqhstl[4] = (unsigned long )18;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[5] = (unsigned long )13;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_mb_id;
                        sqlstm.sqhstl[6] = (unsigned long )18;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_mb_id;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_id;
                        sqlstm.sqhstl[7] = (unsigned long )18;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_bank_id;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[8] = (unsigned long )1;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_status;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_ar_ind;
                        sqlstm.sqhstl[9] = (unsigned long )1;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_ar_ind;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_isd_ind;
                        sqlstm.sqhstl[10] = (unsigned long )1;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_isd_ind;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_date;
                        sqlstm.sqhstl[11] = (unsigned long )17;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_txn_date;
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
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_txn_ccy;
                        sqlstm.sqhstl[13] = (unsigned long )6;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_txn_ccy;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_adjustment;
                        sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_adjustment;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_exchange_rate;
                        sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_exchange_rate;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_processing_cost;
                        sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_processing_cost;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_bank_charge;
                        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_bank_charge;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_bank_charge_refund;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_bank_charge_refund;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_filing_number;
                        sqlstm.sqhstl[19] = (unsigned long )5;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_filing_number;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}
		
			if (iCnt < iRowNum + 1 || iRowNum == 0) {

				/* txn_id */
				if (ind_txn_id >= 0) {
		                        v_txn_id.arr[v_txn_id.len] = '\0';
					PutField_CString(myHash, "txn_seq", (const char *)v_txn_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] txn_id = [%*.s]\n",iCnt, v_txn_id.len, v_txn_id.arr));
				}

				/* dtl_txn_id */
                		if (ind_dtl_txn_id >= 0) {
					v_dtl_txn_id.arr[v_dtl_txn_id.len] = '\0';
					PutField_CString(myHash, "dtl_txn_seq", (const char *)v_dtl_txn_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] dtl_txn_id = [%.*s]\n",iCnt, v_dtl_txn_id.len, v_dtl_txn_id.arr));
				}

				/* txn_code */
				if (ind_txn_code >= 0) {
					v_txn_code.arr[v_txn_code.len] = '\0';
					PutField_CString(myHash, "txn_code", (const char *)v_txn_code.arr);
DEBUGLOG(("GetDetailbyRange [%05d] txn_code = [%.*s]\n",iCnt, v_txn_code.len, v_txn_code.arr));
                		}

				/* merchant_id */
				if (ind_merchant_id >= 0) {
					v_merchant_id.arr[v_merchant_id.len] ='\0';
					PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] merchant_id = [%.*s]\n",iCnt, v_merchant_id.len, v_merchant_id.arr));
                		}

				/* psp_id */
		                if (ind_psp_id >= 0) {
					v_psp_id.arr[v_psp_id.len] ='\0';
					PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] psp_id = [%.*s]\n",iCnt, v_psp_id.len, v_psp_id.arr));
                		}

				/* mb_id */
		                if (ind_mb_id >= 0) {
					v_mb_id.arr[v_mb_id.len] ='\0';
					PutField_CString(myHash,"mb_id",(const char*)v_mb_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] mb_id = [%.*s]\n",iCnt, v_mb_id.len, v_mb_id.arr));
                		}

				/* bank_id */
		                if (ind_bank_id >= 0) {
					v_bank_id.arr[v_bank_id.len] ='\0';
					PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetDetailbyRange [%05d] bank_id = [%.*s]\n",iCnt, v_bank_id.len, v_bank_id.arr));
                		}

				/* status */
				if (ind_status >= 0) {
					PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetDetailbyRange [%05d] status = [%c]\n",iCnt, v_status));
                		}

				/* ar_ind */
				if (ind_ar_ind >= 0) {
					PutField_Char(myHash,"ar_ind",v_ar_ind);
DEBUGLOG(("GetDetailbyRange [%05d] ar_ind = [%c]\n",iCnt, v_ar_ind));
                		}

				/* isd_ind */
				if (ind_isd_ind >= 0) {
					PutField_Char(myHash,"isd_ind",v_isd_ind);
DEBUGLOG(("GetDetailbyRange [%05d] isd_ind = [%c]\n",iCnt, v_isd_ind));
                		}

				/* txn_date */
				if (ind_txn_date >= 0) {
					if (v_txn_date.len > PD_DATE_LEN) {
						v_txn_date.arr[PD_DATE_LEN] = '\0';
						PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetDetailbyRange [%05d] txn_date = [%.*s]\n",iCnt, PD_DATE_LEN, v_txn_date.arr));
					} else {
						v_txn_date.arr[v_txn_date.len] ='\0';
						PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetDetailbyRange [%05d] txn_date = [%.*s]\n",iCnt, v_txn_date.len, v_txn_date.arr));
					}

                		}

				/* txn_amt */
				if (ind_txn_amt < 0) {
					v_txn_amt = 0.0;
				}
				PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetDetailbyRange [%05d] txn_amt = [%f]\n",iCnt, v_txn_amt));

				/* txn_ccy */
				if (ind_txn_ccy >= 0) {
					v_txn_ccy.arr[v_txn_ccy.len] ='\0';
					PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetDetailbyRange [%05d] txn_ccy = [%.*s]\n",iCnt, v_txn_ccy.len, v_txn_ccy.arr));
                		}

				/* adjustment */
				if (ind_adjustment < 0) {
					v_adjustment = 0.0;
				}
				PutField_Double(myHash, "adjustment", v_adjustment);
DEBUGLOG(("GetDetailbyRange [%05d] adjustment = [%f]\n",iCnt, v_adjustment));

				/* exchange_rate */
				if (ind_exchange_rate < 0) {
					v_exchange_rate = 0.0;
				}
				PutField_Double(myHash, "exchange_rate", v_exchange_rate);
DEBUGLOG(("GetDetailbyRange [%05d] exchange_rate = [%f]\n",iCnt, v_exchange_rate));

				/* processing_cost */
				if (ind_processing_cost < 0) {
					v_processing_cost = 0.0;
				}
				PutField_Double(myHash, "processing_cost", v_processing_cost);
DEBUGLOG(("GetDetailbyRange [%05d] processing_cost = [%f]\n",iCnt, v_processing_cost));

				/* bank_charge */
				if (ind_bank_charge < 0) {
					v_bank_charge = 0.0;
				}
				PutField_Double(myHash, "bank_charge", v_bank_charge);
DEBUGLOG(("GetDetailbyRange [%05d] bank_charge = [%f]\n",iCnt, v_bank_charge));

				/* bank_charge_refund */
				if (ind_bank_charge_refund < 0) {
					v_bank_charge_refund = 0.0;
				}
				PutField_Double(myHash, "bank_charge_refund", v_bank_charge_refund);
DEBUGLOG(("GetDetailbyRange [%05d] bank_charge_refund = [%f]\n",iCnt, v_bank_charge_refund));

				/* filing_number */
				if (ind_filing_number >= 0) {
					v_filing_number.arr[v_filing_number.len] ='\0';
					PutField_CString(myHash,"filing_number",(const char*)v_filing_number.arr);
DEBUGLOG(("GetDetailbyRange [%05d] filing_number = [%.*s]\n",iCnt, v_filing_number.len, v_filing_number.arr));
                		}

                		iCnt++;
				RecordSet_Add(myRec, myHash);

			}	
		
		}
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 22;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )296;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Normal Exit\n"));
                return iRet;
	}
        else if (hv_return_value == SP_OTHER_ERR) {
                /* EXEC SQL CLOSE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 22;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )315;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Exit with error\n"));
                return PD_ERR;
        }
        else {
                /* EXEC SQL CLOSE :c_cursor_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 22;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )334;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
                if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("GetDetailbyRange Normal Exit, no record found\n"));
                return PD_OK;
        }
        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )353;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
        if (sqlca.sqlcode < 0) goto getdetailbyrange_error;
}


DEBUGLOG(("RET = [%d]\n",iRet));
        return iRet;


getdetailbyrange_error:
DEBUGLOG(("getdetailbyrange_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MMSInstantTxnInqDt_GetDetailByRange: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 22;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )372;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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



