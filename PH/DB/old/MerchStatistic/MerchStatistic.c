
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
    "MerchStatistic.pc"
};


static unsigned int sqlctx = 9824771;


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
"select a.th_merchant_id ,a.th_host_posting_date ,a.th_transaction_amount ,b\
.td_txn_ccy ,d.country ,c.tp_psp_id  from txn_header a ,txn_detail b ,txn_psp\
_detail c ,psp_country d where (((th_txn_id=:b0 and td_txn_id=:b0) and tp_txn\
_id=:b0) and psp_id=tp_psp_id)           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,265,0,6,123,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,4,0,0,1,9,0,0,
52,0,0,2,270,0,9,226,0,0,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
79,0,0,2,0,0,13,228,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,
118,0,0,2,0,0,15,276,0,0,0,0,0,1,0,
133,0,0,3,259,0,6,280,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,4,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/01/19              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchStatistic.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchStatistic(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hMerchStatistic)
{
	char            *csTmp;
	double		dTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar 	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		/* varchar 	hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar		hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


		double		hv_amount;

		short		ind_psp_id = -1;
		short		ind_txn_date = -1;
		short		ind_update_user = -1;
		short		ind_txn_ccy= -1;
		short		ind_merchant_id = -1;
		short		ind_txn_country = -1;
		short		ind_amount = -1;


		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 



	DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hMerchStatistic,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy(hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id= 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
	}

	if(GetField_CString(hMerchStatistic,"psp_id",&csTmp))
	{
		hv_psp_id.len = strlen(csTmp);
		strncpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		ind_psp_id = 0;
DEBUGLOG(("Add:psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));
	}

	if(GetField_CString(hMerchStatistic,"txn_date",&csTmp))
	{
		hv_txn_date.len = strlen(csTmp);
		strncpy(hv_txn_date.arr, csTmp, hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s]\n",hv_txn_date.len,hv_txn_date.arr));
	}


	if(GetField_CString(hMerchStatistic,"update_user",&csTmp))
	{
		hv_update_user.len = strlen(csTmp);
		strncpy(hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("Add:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	if(GetField_CString(hMerchStatistic,"txn_ccy",&csTmp))
	{
		hv_txn_ccy.len = strlen(csTmp);
		strncpy(hv_txn_ccy.arr, csTmp, hv_txn_ccy.len);
		ind_txn_ccy= 0;
DEBUGLOG(("Add:txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));
	}

	if(GetField_CString(hMerchStatistic,"txn_country",&csTmp))
	{
		hv_txn_country.len = strlen(csTmp);
		strncpy(hv_txn_country.arr, csTmp, hv_txn_country.len);
		ind_txn_country= 0;
DEBUGLOG(("Add:txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));
	}

	if(GetField_Double(hMerchStatistic,"txn_amt",&dTmp))
	{
		hv_amount = dTmp;
		ind_amount= 0;
DEBUGLOG(("Add:amount = [%lf]\n",hv_amount));
	}

	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merch_statistic_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_txn_ccy:ind_txn_ccy,
				:hv_txn_country:ind_txn_country,
				:hv_txn_date:ind_txn_date,
				:hv_psp_id:ind_psp_id,
				:hv_amount:ind_amount,
				:hv_update_user:ind_update_user);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_statistic_insert ( :hv_m\
erchant_id:ind_merchant_id , :hv_txn_ccy:ind_txn_ccy , :hv_txn_country:ind_tx\
n_country , :hv_txn_date:ind_txn_date , :hv_psp_id:ind_psp_id , :hv_amount:in\
d_amount , :hv_update_user:ind_update_user ) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_country;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_psp_id;
 sqlstm.sqhstl[5] = (unsigned long )12;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_psp_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_amount;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_update_user;
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
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("MerchStatistic_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("MerchStatistic_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}



int AddByTxnId(const char *csTxnId)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO addbyid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar 	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

		/* varchar		v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_txn_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar 	v_txn_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar		v_txn_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;


		double		v_amount;

		short		ind_psp_id = -1;
		short		ind_txn_date = -1;
		short		ind_update_user = -1;
		short		ind_txn_ccy= -1;
		short		ind_merchant_id = -1;
		short		ind_txn_country = -1;
		short		ind_amount = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("AddByTxnId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_update_user.len = strlen("SYSTEM");
        memcpy(hv_update_user.arr,"SYSTEM",hv_update_user.len);
	ind_update_user = 0;
DEBUGLOG(("AddByTxnId update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));

	/* EXEC SQL DECLARE c_cursor_addbyid CURSOR FOR
		select	a.th_merchant_id,
			a.th_host_posting_date,
			a.th_transaction_amount,
			b.td_txn_ccy,
			d.country,
			c.tp_psp_id
		from	txn_header a,
			txn_detail b,
			txn_psp_detail c,
			psp_country d
		where	th_txn_id = :hv_txn_id
		and	td_txn_id = :hv_txn_id
		and	tp_txn_id = :hv_txn_id
		and	psp_id=tp_psp_id; */ 



        /* EXEC SQL OPEN c_cursor_addbyid; */ 

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
        if (sqlca.sqlcode < 0) goto addbyid_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_addbyid
                INTO
                        :v_merchant_id:ind_merchant_id,
                        :v_txn_date:ind_txn_date,
                        :v_amount:ind_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_country:ind_txn_country,
			:v_psp_id:ind_psp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )79;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_amount;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_country;
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
                if (sqlca.sqlcode < 0) goto addbyid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        iRet = SQL_NOT_FOUND;
                        break;
                }

		if(ind_merchant_id>=0){
			v_merchant_id.arr[v_merchant_id.len]='\0';
DEBUGLOG(("AddByTxnId:merchant_id = [%.*s]\n",v_merchant_id.len,v_merchant_id.arr));
		}

		if(ind_txn_date>=0){
			v_txn_date.arr[v_txn_date.len]='\0';
DEBUGLOG(("AddByTxnId:txn_date = [%.*s]\n",v_txn_date.len,v_txn_date.arr));
		}

		if(ind_amount>=0){
DEBUGLOG(("AddByTxnId:amount= [%lf]\n",v_amount));
		}

		if(ind_txn_ccy>=0){
			v_txn_ccy.arr[v_txn_ccy.len]='\0';
DEBUGLOG(("AddByTxnId:txn_ccy= [%.*s]\n",v_txn_ccy.len,v_txn_ccy.arr));
		}

		if(ind_txn_country>=0){
			v_txn_country.arr[v_txn_country.len]='\0';
DEBUGLOG(("AddByTxnId:txn_country= [%.*s]\n",v_txn_country.len,v_txn_country.arr));
		}

		if(ind_psp_id>=0){
			v_psp_id.arr[v_psp_id.len]='\0';
DEBUGLOG(("AddByTxnId:psp_id= [%.*s]\n",v_psp_id.len,v_psp_id.arr));
		}


		break;//only one set of record

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_addbyid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )118;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto addbyid_error;
}



DEBUGLOG(("AddByTxnId: Begin\n"));

	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merch_statistic_insert(
				:v_merchant_id:ind_merchant_id,
				:v_txn_ccy:ind_txn_ccy,
				:v_txn_country:ind_txn_country,
				:v_txn_date:ind_txn_date,
				:v_psp_id:ind_psp_id,
				:v_amount:ind_amount,
				:hv_update_user:ind_update_user);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_statistic_insert ( :v_me\
rchant_id:ind_merchant_id , :v_txn_ccy:ind_txn_ccy , :v_txn_country:ind_txn_c\
ountry , :v_txn_date:ind_txn_date , :v_psp_id:ind_psp_id , :v_amount:ind_amou\
nt , :hv_update_user:ind_update_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )133;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_country;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_country;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_id;
 sqlstm.sqhstl[5] = (unsigned long )13;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_psp_id;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&v_amount;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_amount;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[7] = (unsigned long )22;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto addbyid_error;
}




	DEBUGLOG(("AddByTxnId:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
		DEBUGLOG(("AddByTxnId:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
		ERRLOG("MerchStatistic_AddByTxnId: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("AddByTxnId: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("MerchStatistic_AddByTxnId: SP_ERR TxnAbort\n");
		DEBUGLOG(("AddByTxnId: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

addbyid_error:
	DEBUGLOG(("addbyid_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;


}
