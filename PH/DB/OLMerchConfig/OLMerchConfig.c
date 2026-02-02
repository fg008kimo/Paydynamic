
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "OLMerchConfig.pc"
};


static unsigned int sqlctx = 5057315;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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
"SELECT omc_match_fifo , omc_match_fifo_amt_limit , omc_min_settle_amt , omc\
_min_settle_amt_apply_admin , omc_max_auto_cb_amt , omc_preferred_settle_ccy \
, omc_preferred_acr_pool , omc_client_sett_bank_id FROM ol_merch_config WHERE\
 omc_merchant_id = :b0:b1 AND omc_country_id = :b2:b3 AND omc_currency_id = :\
b4:b5 AND omc_service_code = :b6:b7 AND omc_disabled = 0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,639,0,6,185,0,0,15,15,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,4,0,0,1,4,0,0,1,3,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,1,9,0,0,
80,0,0,2,0,0,17,383,0,0,1,1,0,1,0,1,9,0,0,
99,0,0,2,0,0,21,384,0,0,0,0,0,1,0,
114,0,0,3,374,0,9,469,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
145,0,0,3,0,0,13,472,0,0,8,0,0,1,0,2,3,0,0,2,4,0,0,2,4,0,0,2,3,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,3,0,0,
192,0,0,3,0,0,15,540,0,0,0,0,0,1,0,
207,0,0,3,0,0,15,550,0,0,0,0,0,1,0,
222,0,0,4,190,0,4,595,0,0,5,4,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
257,0,0,5,179,0,4,669,0,0,5,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/21              David Wong
Add client_sett_bank_id				   2014/11/14		   Elvis Wong 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLMerchConfig.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLMerchConfig(char cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hConfig)
{
	char *csTmp;
	int  iTmp;
	double dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_currency_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;

		/* varchar		hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		int		hv_match_fifo;
		double		hv_match_fifo_amt_limit;
		double		hv_min_settle_amt;
		int		hv_min_settle_amt_apply_admin;
		double		hv_max_auto_cb_amt;
		/* varchar		hv_preferred_settle_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_preferred_settle_ccy;

		int		hv_disabled;
		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar         hv_preferred_acr_pool[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_preferred_acr_pool;

		int         	hv_client_sett_bank_id;

		short		ind_merchant_id = -1;
		short		ind_currency_id = -1;
		short		ind_country_id = -1;
		short		ind_service_code = -1;
		short		ind_match_fifo = -1;
		short		ind_match_fifo_amt_limit = -1;
		short		ind_min_settle_amt = -1;
		short		ind_min_settle_amt_apply_admin = -1;
		short		ind_max_auto_cb_amt = -1;
		short		ind_preferred_settle_ccy = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
		short           ind_preferred_acr_pool = -1;
		short           ind_client_sett_bank_id = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if (GetField_CString(hConfig, "merchant_id", &csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
DEBUGLOG(("Add: merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));
	}

	if (GetField_CString(hConfig, "currency_id", &csTmp))
	{
		hv_currency_id.len = strlen(csTmp);
		strncpy((char *)hv_currency_id.arr, csTmp, hv_currency_id.len);
		ind_currency_id = 0;
DEBUGLOG(("Add: currency_id = [%.*s]\n", hv_currency_id.len, hv_currency_id.arr));
	}

	if (GetField_CString(hConfig, "country_id", &csTmp))
	{
		hv_country_id.len = strlen(csTmp);
		strncpy((char *)hv_country_id.arr, csTmp, hv_country_id.len);
		ind_country_id = 0;
DEBUGLOG(("Add: country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));
	}

	if (GetField_CString(hConfig, "service_code", &csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
DEBUGLOG(("Add: service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));
	}

	if (GetField_Int(hConfig, "match_fifo", &iTmp))
	{
		hv_match_fifo = iTmp;
		ind_match_fifo = 0;
DEBUGLOG(("Add: match_fifo = [%d]\n", hv_match_fifo));
	}

	if (GetField_Double(hConfig, "match_fifo_amt_limit", &dTmp))
	{
		hv_match_fifo_amt_limit = dTmp;
		ind_match_fifo_amt_limit = 0;
DEBUGLOG(("Add: match_fifo_amt_limit = [%f]\n", hv_match_fifo_amt_limit));
	}

	if (GetField_Double(hConfig, "min_settle_amt", &dTmp))
	{
		hv_min_settle_amt = dTmp;
		ind_min_settle_amt = 0;
DEBUGLOG(("Add: min_settle_amt = [%f]\n", hv_min_settle_amt));
	}

	if (GetField_Int(hConfig, "min_settle_amt_apply_admin", &iTmp))
	{
		hv_min_settle_amt_apply_admin = iTmp;
		ind_min_settle_amt_apply_admin = 0;
DEBUGLOG(("Add: min_settle_amt_apply_admin = [%d]\n", hv_min_settle_amt_apply_admin));
	}

	if (GetField_Double(hConfig, "max_auto_cb_amt", &dTmp))
	{
		hv_max_auto_cb_amt = dTmp;
		ind_max_auto_cb_amt = 0;
DEBUGLOG(("Add: max_auto_cb_amt = [%f]\n", hv_max_auto_cb_amt));
	}

	if (GetField_CString(hConfig, "preferred_settle_ccy", &csTmp))
	{
		hv_preferred_settle_ccy.len = strlen(csTmp);
		strncpy((char *)hv_preferred_settle_ccy.arr, csTmp, hv_preferred_settle_ccy.len);
		ind_preferred_settle_ccy = 0;
DEBUGLOG(("Add: preferred_settle_ccy = [%.*s]\n", hv_preferred_settle_ccy.len, hv_preferred_settle_ccy.arr));
	}

	if(GetField_CString(hConfig,"preferred_acr_pool",&csTmp)) {
                hv_preferred_acr_pool.len = strlen(csTmp);
                strncpy((char *)hv_preferred_acr_pool.arr, csTmp, hv_preferred_acr_pool.len);
                ind_preferred_acr_pool= 0;
DEBUGLOG(("Add: preferred_acr_pool = [%.*s]\n",hv_preferred_acr_pool.len,hv_preferred_acr_pool.arr));
        }

	if (GetField_Int(hConfig, "disabled", &iTmp))
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
DEBUGLOG(("Add: disabled = [%d]\n", hv_disabled));
	} else {
		hv_disabled = PD_FALSE;
		ind_disabled = 0;
DEBUGLOG(("Add: disabled = [%d]\n", hv_disabled));
	}

	if (GetField_Int(hConfig, "client_sett_bank_id", &iTmp))
        {
                hv_client_sett_bank_id = iTmp;
                ind_client_sett_bank_id = 0;
DEBUGLOG(("Add: client_sett_bank_id = [%d]\n", hv_client_sett_bank_id));
        }

	if (GetField_CString(hConfig, "create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_merch_config_insert(
								:hv_merchant_id:ind_merchant_id,
								:hv_currency_id:ind_currency_id,
								:hv_country_id:ind_country_id,
								:hv_service_code:ind_service_code,
								:hv_match_fifo:ind_match_fifo,
								:hv_match_fifo_amt_limit:ind_match_fifo_amt_limit,
								:hv_min_settle_amt:ind_min_settle_amt,
								:hv_min_settle_amt_apply_admin:ind_min_settle_amt_apply_admin,
								:hv_max_auto_cb_amt:ind_max_auto_cb_amt,
								:hv_preferred_settle_ccy:ind_preferred_settle_ccy,
								:hv_preferred_acr_pool:ind_preferred_acr_pool,
								:hv_disabled:ind_disabled,
								:hv_client_sett_bank_id:ind_client_sett_bank_id,
								:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_merch_config_insert ( :hv_m\
erchant_id:ind_merchant_id , :hv_currency_id:ind_currency_id , :hv_country_id\
:ind_country_id , :hv_service_code:ind_service_code , :hv_match_fifo:ind_matc\
h_fifo , :hv_match_fifo_amt_limit:ind_match_fifo_amt_limit , :hv_min_settle_a\
mt:ind_min_settle_amt , :hv_min_settle_amt_apply_admin:ind_min_settle_amt_app\
ly_admin , :hv_max_auto_cb_amt:ind_max_auto_cb_amt , :hv_preferred_settle_ccy\
:ind_preferred_settle_ccy , :hv_preferred_acr_pool:ind_preferred_acr_pool , :\
hv_disabled:ind_disabled , :hv_client_sett_bank_id:ind_client_sett_bank_id , \
:hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_currency_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_currency_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_service_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_match_fifo;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_match_fifo;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_match_fifo_amt_limit;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_match_fifo_amt_limit;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_min_settle_amt;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_min_settle_amt;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_min_settle_amt_apply_admin;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_min_settle_amt_apply_admin;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_max_auto_cb_amt;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_max_auto_cb_amt;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_preferred_settle_ccy;
 sqlstm.sqhstl[10] = (unsigned long )5;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_preferred_settle_ccy;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_preferred_acr_pool;
 sqlstm.sqhstl[11] = (unsigned long )5;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_preferred_acr_pool;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_disabled;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_client_sett_bank_id;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_client_sett_bank_id;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[14] = (unsigned long )22;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_create_user;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
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

	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)
	{
		ERRLOG("OLMerchConfig_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)
	{
		ERRLOG("OLMerchConfig_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchConfig_Add: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int Update(const hash_t *hRls)
{
	char *csTmp;
	char *csBuf;
	int iTmp;
	double dTmp;

	char *csMerchantId;
	char *csCurrencyId;
	char *csCountryId;
	char *csServiceCode;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;

	/* EXEC SQL END DECLARE SECTION; */ 


	csBuf = (char *) malloc (128);

DEBUGLOG(("Update: Begin\n"));

	strcpy((char*)hv_dynstmt.arr, "update ol_merch_config set omc_update_timestamp = sysdate");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	GetField_CString(hRls, "merchant_id", &csMerchantId);
DEBUGLOG(("Update: merchant_id = [%s]\n", csMerchantId));

	GetField_CString(hRls, "currency_id", &csCurrencyId);
DEBUGLOG(("Update: currency_id = [%s]\n", csCurrencyId));

	GetField_CString(hRls, "country_id", &csCountryId);
DEBUGLOG(("Update: country_id = [%s]\n", csCountryId));

	GetField_CString(hRls, "service_code", &csServiceCode);
DEBUGLOG(("Update: service_code = [%s]\n", csServiceCode));

// match_fifo
	if (GetField_Int(hRls, "match_fifo", &iTmp)) {
DEBUGLOG(("Update: match_fifo = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", omc_match_fifo = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// match_fifo_amt_limit
	if (GetField_Double(hRls, "match_fifo_amt_limit", &dTmp)) {
DEBUGLOG(("Update: match_fifo_amt_limit = [%f]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", omc_match_fifo_amt_limit = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// min_settle_amt
	if (GetField_Double(hRls, "min_settle_amt", &dTmp)) {
DEBUGLOG(("Update: min_settle_amt = [%f]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", omc_min_settle_amt = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// min_settle_amt_apply_admin
	if (GetField_Int(hRls, "min_settle_amt_apply_admin", &iTmp)) {
DEBUGLOG(("Update: min_settle_amt_apply_admin = [%d]\n", iTmp));
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, ", omc_min_settle_amt_apply_admin = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// max_auto_cb_amt
	if (GetField_Double(hRls, "max_auto_cb_amt", &dTmp)) {
DEBUGLOG(("Update: max_auto_cb_amt = [%f]\n", dTmp));
		sprintf(csBuf, "%f", dTmp);
		strcat((char*)hv_dynstmt.arr, ", omc_max_auto_cb_amt = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// preferred_settle_ccy
	if (GetField_CString(hRls, "preferred_settle_ccy", &csTmp)) {
DEBUGLOG(("Update: preferred_settle_ccy = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", omc_preferred_settle_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

//preferred_acr_pool
        if (GetField_CString(hRls,"preferred_acr_pool",&csTmp)) {
DEBUGLOG(("Update: preferred_acr_pool = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",omc_preferred_acr_pool = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

// client_sett_bank_id
        if (GetField_Int(hRls, "client_sett_bank_id", &iTmp)) {
DEBUGLOG(("Update: client_sett_bank_id = [%d]\n", iTmp));
		if (iTmp == -1) {
			strcat((char*)hv_dynstmt.arr, ", omc_client_sett_bank_id = '");
                	strcat((char*)hv_dynstmt.arr, "'");
                	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		} else {
                	sprintf(csBuf, "%d", iTmp);
                	strcat((char*)hv_dynstmt.arr, ", omc_client_sett_bank_id = ");
                	strcat((char*)hv_dynstmt.arr, csBuf);
                	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}	

// update_user
	if (GetField_CString(hRls, "update_user", &csTmp)) {
DEBUGLOG(("Update: update_user = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ", omc_update_user = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " where omc_merchant_id = '");
	strcat((char *)hv_dynstmt.arr, csMerchantId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " and omc_currency_id = '");
	strcat((char *)hv_dynstmt.arr, csCurrencyId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " and omc_country_id = '");
	strcat((char *)hv_dynstmt.arr, csCountryId);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	strcat((char *)hv_dynstmt.arr, " and omc_service_code = '");
	strcat((char *)hv_dynstmt.arr, csServiceCode);
	strcat((char *)hv_dynstmt.arr, "'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )80;
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
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
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

ERRLOG("MerantantBalAcct_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}


int GetMerchConfig(const char *csMerchantId, const char *csCountryId,
					const char *csCurrencyId, const char *csServiceCode,
					hash_t *hMerchCfg)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getmerchconfig_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_currency_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency_id;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		int v_match_fifo;
		double v_match_fifo_amt_limit;
		double v_min_settle_amt;
		int v_min_settle_amt_apply_admin;
		double v_max_auto_cb_amt;
		/* varchar v_preferred_settle_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_preferred_settle_ccy;

		/* varchar v_preferred_acr_pool[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_preferred_acr_pool;

		int v_client_sett_bank_id;

		short ind_merchant_id = -1;
		short ind_country_id = -1;
		short ind_currency_id = -1;
		short ind_service_code = -1;
		short ind_match_fifo = -1;
		short ind_match_fifo_amt_limit = -1;
		short ind_min_settle_amt = -1;
		short ind_min_settle_amt_apply_admin = -1;
		short ind_max_auto_cb_amt = -1;
		short ind_preferred_settle_ccy = -1;
		short ind_preferred_acr_pool = -1;
		short ind_client_sett_bank_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr, csMerchantId, hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("GetMerchConfig merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));

	hv_country_id.len = strlen(csCountryId);
	memcpy(hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("GetMerchConfig country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_currency_id.len = strlen(csCurrencyId);
	memcpy(hv_currency_id.arr, csCurrencyId, hv_currency_id.len);
	ind_currency_id = 0;
DEBUGLOG(("GetMerchConfig currency_id = [%.*s]\n", hv_currency_id.len, hv_currency_id.arr));

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr, csServiceCode, hv_service_code.len);
	ind_service_code = 0;
DEBUGLOG(("GetMerchConfig service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));

	/* EXEC SQL DECLARE c_cursor_getmerchconfig CURSOR FOR
		SELECT	omc_match_fifo, omc_match_fifo_amt_limit, omc_min_settle_amt, omc_min_settle_amt_apply_admin, omc_max_auto_cb_amt, omc_preferred_settle_ccy,
			omc_preferred_acr_pool, omc_client_sett_bank_id
		FROM	ol_merch_config
		WHERE	omc_merchant_id = :hv_merchant_id:ind_merchant_id
		AND	omc_country_id = :hv_country_id:ind_country_id
		AND	omc_currency_id = :hv_currency_id:ind_currency_id
		AND	omc_service_code = :hv_service_code:ind_service_code
		AND omc_disabled = 0; */ 


	/* EXEC SQL OPEN c_cursor_getmerchconfig; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )114;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[1] = (unsigned long )4;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_country_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_currency_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_currency_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_service_code;
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
 if (sqlca.sqlcode < 0) goto getmerchconfig_error;
}



	for (;;) {
		/* EXEC SQL FETCH c_cursor_getmerchconfig
		INTO	:v_match_fifo:ind_match_fifo,
			:v_match_fifo_amt_limit:ind_match_fifo_amt_limit,
			:v_min_settle_amt:ind_min_settle_amt,
			:v_min_settle_amt_apply_admin:ind_min_settle_amt_apply_admin,
			:v_max_auto_cb_amt:ind_max_auto_cb_amt,
			:v_preferred_settle_ccy:ind_preferred_settle_ccy,
			:v_preferred_acr_pool:ind_preferred_acr_pool,
			:v_client_sett_bank_id:ind_client_sett_bank_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )145;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_match_fifo;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_match_fifo;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_match_fifo_amt_limit;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_match_fifo_amt_limit;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_min_settle_amt;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_min_settle_amt;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_min_settle_amt_apply_admin;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_min_settle_amt_apply_admin;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_max_auto_cb_amt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_max_auto_cb_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_preferred_settle_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_preferred_settle_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_preferred_acr_pool;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_preferred_acr_pool;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_client_sett_bank_id;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_client_sett_bank_id;
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
  if (sqlca.sqlcode < 0) goto getmerchconfig_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_match_fifo >= 0) {
			PutField_Int(hMerchCfg, "match_fifo", v_match_fifo);
DEBUGLOG(("GetMerchConfig match_fifo = [%d]\n", v_match_fifo));
			if (!v_match_fifo) {
				if (ind_match_fifo_amt_limit >= 0) {
					PutField_Double(hMerchCfg, "match_fifo_amt_limit", v_match_fifo_amt_limit);
DEBUGLOG(("GetMerchConfig match_fifo_amt_limit = [%lf]\n", v_match_fifo_amt_limit));
				} else {
					PutField_Double(hMerchCfg, "match_fifo_amt_limit", 0);
DEBUGLOG(("GetMerchConfig (default) match_fifo_amt_limit = [%lf]\n", 0));
				}
			}
		} else {
			PutField_Int(hMerchCfg, "match_fifo", PD_TRUE);
DEBUGLOG(("GetMerchConfig (default) match_fifo = [%d]\n", PD_TRUE));
		}

		if (ind_min_settle_amt >= 0) {
			PutField_Double(hMerchCfg, "min_settle_amt", v_min_settle_amt);
DEBUGLOG(("GetMerchConfig min_settle_amt = [%lf]\n", v_min_settle_amt));
		}

		if (ind_min_settle_amt_apply_admin >= 0) {
			PutField_Int(hMerchCfg, "min_settle_amt_apply_admin", v_min_settle_amt_apply_admin);
DEBUGLOG(("GetMerchConfig min_settle_amt_apply_admin = [%lf]\n", v_min_settle_amt_apply_admin));
		}

		if (ind_max_auto_cb_amt >= 0) {
			PutField_Double(hMerchCfg, "max_auto_cb_amt", v_max_auto_cb_amt);
DEBUGLOG(("GetMerchConfig max_auto_cb_amt = [%lf]\n", v_max_auto_cb_amt));
		}

		if (ind_preferred_settle_ccy >= 0) {
			v_preferred_settle_ccy.arr[v_preferred_settle_ccy.len] = '\0';
			PutField_CString(hMerchCfg, "preferred_settle_ccy", (const char*)v_preferred_settle_ccy.arr);
DEBUGLOG(("GetMerchConfig preferred_settle_ccy = [%s]\n", (const char*)v_preferred_settle_ccy.arr));
		}

		if(ind_preferred_acr_pool>= 0){
                        v_preferred_acr_pool.arr[v_preferred_acr_pool.len]='\0';
                        PutField_CString(hMerchCfg,"preferred_acr_pool",(const char*)v_preferred_acr_pool.arr);
DEBUGLOG(("GetMerchConfig preferred acr pool =[%s]\n",v_preferred_acr_pool.arr));
                }
                else{
                        PutField_CString(hMerchCfg,"preferred_acr_pool",PD_CCY_UNKNOWN);
DEBUGLOG(("GetMerchConfig preferred acr pool (not found) =[%s]\n",PD_CCY_UNKNOWN));
                }

		if (ind_client_sett_bank_id >= 0) {
                        PutField_Int(hMerchCfg, "client_sett_bank_id", v_client_sett_bank_id);
DEBUGLOG(("GetMerchConfig client_sett_bank_id = [%d]\n", v_client_sett_bank_id));
                }
	}

	/* EXEC SQL CLOSE c_cursor_getmerchconfig; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )192;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchconfig_error;
}



DEBUGLOG(("GetMerchConfig Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getmerchconfig_error:
DEBUGLOG(("getmerchconfig_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLMerchConfig getmerchconfig_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_cursor_getmerchconfig; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )207;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchconfig_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetACRPool(const char* csMerchantID,
                const char* csCountry,
		const char* csCcy,
		const char* csServiceCode,
		char*	csACRPool)
{
	int iRet = PD_OK;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO acr_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
                /* varchar         v_preferred_acr_pool[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_preferred_acr_pool;


		short		ind_preferred_acr_pool = -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("GetACRPool merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("GetACRPool country = [%.*s]\n",hv_country.len,hv_country.arr));

        hv_ccy.len = strlen(csCcy);
        memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("GetACRPool ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetACRPool service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        

	/* EXEC SQL SELECT 
			omc_preferred_acr_pool
		INTO 
		     :v_preferred_acr_pool:ind_preferred_acr_pool
		FROM ol_merch_config
	       WHERE omc_merchant_id = :hv_merchant_id
		 AND omc_country_id = :hv_country
		 AND omc_currency_id = :hv_ccy
		 AND omc_service_code = :hv_service_code
		 AND omc_disabled = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select omc_preferred_acr_pool INTO :b0:b1 FROM ol_merch_con\
fig WHERE omc_merchant_id = :b2 AND omc_country_id = :b3 AND omc_currency_id \
= :b4 AND omc_service_code = :b5 AND omc_disabled = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )222;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_preferred_acr_pool;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_preferred_acr_pool;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto acr_error;
}




	if(ind_preferred_acr_pool>= 0){
		v_preferred_acr_pool.arr[v_preferred_acr_pool.len]='\0';
		strcpy((char*)csACRPool,(const char*)v_preferred_acr_pool.arr);
		csACRPool[PD_CCY_ID_LEN] = '\0';
DEBUGLOG(("GetACRPool preferred acr pool =[%s]\n",csACRPool));
	}
	else{
		strcpy((char*)csACRPool,PD_CCY_UNKNOWN);
		csACRPool[PD_CCY_ID_LEN] = '\0';
DEBUGLOG(("GetACRPool preferred acr pool (not found) =[%s]\n",csACRPool));
	}


DEBUGLOG(("GetACRPool Normal Exit [%d]\n",iRet));
	return iRet;

acr_error:
DEBUGLOG(("acr_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CheckConfig(const char* csMerchantID,
                const char* csCountry,
		const char* csCcy,
		const char* csServiceCode)
{
	int iRet = PD_NOT_FOUND;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO check_config_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                        
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

                /* varchar         hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                
		int		v_cnt;
		short		ind_cnt = -1;
        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_merchant_id.len = strlen(csMerchantID);
        memcpy(hv_merchant_id.arr,csMerchantID,hv_merchant_id.len);
DEBUGLOG(("CheckConfig merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        
        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("CheckConfig country = [%.*s]\n",hv_country.len,hv_country.arr));

        hv_ccy.len = strlen(csCcy);
        memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("CheckConfig ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("CheckConfig service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        

	/* EXEC SQL SELECT 
			count(1)
		INTO 
		     :v_cnt:ind_cnt
		FROM ol_merch_config
	       WHERE omc_merchant_id = :hv_merchant_id
		 AND omc_country_id = :hv_country
		 AND omc_currency_id = :hv_ccy
		 AND omc_service_code = :hv_service_code
		 AND omc_disabled = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_merch_config WHERE o\
mc_merchant_id = :b2 AND omc_country_id = :b3 AND omc_currency_id = :b4 AND o\
mc_service_code = :b5 AND omc_disabled = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )257;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[2] = (unsigned long )4;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto check_config_error;
}




	if(ind_cnt < 0){
		v_cnt = 0;
	}

	if(v_cnt > 0){
		iRet = PD_FOUND;
DEBUGLOG(("CheckConfig Config found\n"));
	}
	else{
DEBUGLOG(("CheckConfig Config not found\n"));
	}

	return iRet;

check_config_error:
DEBUGLOG(("check_config_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
