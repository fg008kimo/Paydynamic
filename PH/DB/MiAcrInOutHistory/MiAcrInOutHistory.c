
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
           char  filnam[21];
};
static struct sqlcxp sqlfpn =
{
    20,
    "MiAcrInOutHistory.pc"
};


static unsigned int sqlctx = 77599459;


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
   unsigned char  *sqhstv[20];
   unsigned long  sqhstl[20];
            int   sqhsts[20];
            short *sqindv[20];
            int   sqinds[20];
   unsigned long  sqharm[20];
   unsigned long  *sqharc[20];
   unsigned short  sqadto[20];
   unsigned short  sqtdso[20];
} sqlstm = {12,20};

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
"select txn_date , bank_id , from_ccy , from_amt , bank_ccy , bank_amt , old\
_rate , new_rate , org_bank_bal , bank_bal , txn_code , fund_type , txn_id FR\
OM mi_acr_inout_overview WHERE batch_id = :b0            ";

 static char *sq0005 = 
"select txn_date , bank_id , from_amt , bank_amt , old_rate , new_rate , org\
_bank_bal , bank_bal , txn_code , fund_type , acr_prorata , to_char ( time , \
'YYYYMMDDHH24MISS' ) FROM mi_acr_inout_overview WHERE from_ccy = :b0 AND bank\
_ccy = :b1 AND time > to_date ( to_char ( sysdate - ( :b2 - 1 ) , 'YYYYMMDD' \
) , 'YYYYMMDD' ) ORDER BY time            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,597,0,6,238,0,0,20,20,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
1,9,0,0,1,3,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
100,0,0,2,532,0,6,264,0,0,18,18,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,1,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,
187,0,0,3,209,0,9,376,0,2049,1,1,0,1,0,1,9,0,0,
206,0,0,3,0,0,13,378,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,1,0,0,2,9,0,0,
273,0,0,3,0,0,15,478,0,0,0,0,0,1,0,
288,0,0,3,0,0,15,492,0,0,0,0,0,1,0,
303,0,0,4,328,0,4,515,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
330,0,0,5,348,0,9,617,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,
357,0,0,5,0,0,13,619,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,1,0,0,2,3,0,0,2,9,0,0,
420,0,0,5,0,0,15,719,0,0,0,0,0,1,0,
435,0,0,5,0,0,15,733,0,0,0,0,0,1,0,
450,0,0,6,442,0,4,766,0,0,9,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/10/28              LokMan Chow
Add column					   2018/08/16		   LokMan Chow
Add function					   2018/08/20		   LokMan Chow 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MiAcrInOutHistory.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;
void MiAcrInOutHistory(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t* hRls)
{
	char cTmp;
	char *csTmp;
	double	dTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar		hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

		/* varchar		hv_bank_id[PD_MMS_OPB_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_bank_id;

		/* varchar		hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

		double		hv_from_amt;
		/* varchar		hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;

		double		hv_bank_amt;
		double		hv_org_bank_bal;
		double		hv_bank_bal;
		double		hv_old_rate;
		double		hv_new_rate;
		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char		hv_fund_type;
		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_time[PD_TIMESTAMP_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_time;

		/* varchar		hv_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_user;

		int		hv_acr_prorata;
		double		hv_numerator;
		double		hv_denominator;

		short           ind_batch_id = -1;
		short           ind_txn_date = -1;
		short           ind_bank_id = -1;
		short           ind_from_ccy = -1;
		short           ind_from_amt = -1;
		short           ind_bank_ccy = -1;
		short           ind_bank_amt = -1;
		short           ind_org_bank_bal = -1;
		short           ind_bank_bal = -1;
		short           ind_old_rate = -1;
		short           ind_new_rate = -1;
		short           ind_txn_code = -1;
		short           ind_fund_type = -1;
		short           ind_txn_id = -1;
		short           ind_time = -1;
		short           ind_user = -1;
		short           ind_acr_prorata = -1;
		short           ind_numerator = -1;
		short           ind_denominator = -1;

		short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


/* batch_id*/
	if(GetField_CString(hRls,"batch_id",&csTmp)){
		hv_batch_id.len = strlen(csTmp);
		memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
		ind_batch_id = 0;
DEBUGLOG(("Add:batch_id = [%.*s][%d]\n",hv_batch_id.len,hv_batch_id.arr,hv_batch_id.len));
	}

/* txn_date*/
	if(GetField_CString(hRls,"txn_date",&csTmp)){
		hv_txn_date.len = strlen(csTmp);
		memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
		ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s][%d]\n",hv_txn_date.len,hv_txn_date.arr,hv_txn_date.len));
	}

/* bank_id*/
	if(GetField_CString(hRls,"bank_id",&csTmp)){
		hv_bank_id.len = strlen(csTmp);
		memcpy(hv_bank_id.arr,csTmp,hv_bank_id.len);
		ind_bank_id = 0;
DEBUGLOG(("Add:bank_id = [%.*s][%d]\n",hv_bank_id.len,hv_bank_id.arr,hv_bank_id.len));
	}

/* from_ccy*/
	if(GetField_CString(hRls,"from_ccy",&csTmp)){
		hv_from_ccy.len = strlen(csTmp);
		memcpy(hv_from_ccy.arr,csTmp,hv_from_ccy.len);
		ind_from_ccy = 0;
DEBUGLOG(("Add:from_ccy = [%.*s][%d]\n",hv_from_ccy.len,hv_from_ccy.arr,hv_from_ccy.len));
	}

/* from_amt*/
	if(GetField_Double(hRls,"from_amt",&dTmp)){
		hv_from_amt = dTmp;
		ind_from_amt = 0;
DEBUGLOG(("Add:from_amt = [%lf]\n",hv_from_amt));
	}

/* bank_ccy*/
	if(GetField_CString(hRls,"bank_ccy",&csTmp)){
		hv_bank_ccy.len = strlen(csTmp);
		memcpy(hv_bank_ccy.arr,csTmp,hv_bank_ccy.len);
		ind_bank_ccy = 0;
DEBUGLOG(("Add:bank_ccy = [%.*s][%d]\n",hv_bank_ccy.len,hv_bank_ccy.arr,hv_bank_ccy.len));
	}

/* bank_amt*/
	if(GetField_Double(hRls,"bank_amt",&dTmp)){
		hv_bank_amt= dTmp;
		ind_bank_amt = 0;
DEBUGLOG(("Add:bank_amt = [%lf]\n",hv_bank_amt));
	}

/* old_rate*/
	if(GetField_Double(hRls,"old_rate",&dTmp)){
		hv_old_rate= dTmp;
		ind_old_rate = 0;
DEBUGLOG(("Add:old_rate = [%lf]\n",hv_old_rate));
	}

/* new_rate*/
	if(GetField_Double(hRls,"new_rate",&dTmp)){
		hv_new_rate= dTmp;
		ind_new_rate = 0;
DEBUGLOG(("Add:new_rate = [%lf]\n",hv_new_rate));
	}

/* org_bank_bal*/
	if(GetField_Double(hRls,"org_bank_bal",&dTmp)){
		hv_org_bank_bal= dTmp;
		ind_org_bank_bal = 0;
DEBUGLOG(("Add:org_bank_bal = [%lf]\n",hv_org_bank_bal));
	}

/* bank_bal*/
	if(GetField_Double(hRls,"bank_bal",&dTmp)){
		hv_bank_bal= dTmp;
		ind_bank_bal = 0;
DEBUGLOG(("Add:bank_bal = [%lf]\n",hv_bank_bal));
	}

/* txn_code*/
	if(GetField_CString(hRls,"txn_code",&csTmp)){
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
		ind_txn_code = 0;
DEBUGLOG(("Add:txn_code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len));
	}

/* fund_type*/
	if(GetField_Char(hRls,"fund_type",&cTmp)){
		hv_fund_type = cTmp;
		ind_fund_type = 0;
DEBUGLOG(("Add:fund_type = [%c]\n",hv_fund_type));
	}

/* txn_id*/
	if(GetField_CString(hRls,"txn_id",&csTmp)){
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
	}

/* time*/
	if(GetField_CString(hRls,"time",&csTmp)){
		hv_time.len = PD_DATETIME_LEN;//strlen(csTmp);
		memcpy(hv_time.arr,csTmp,hv_time.len);
		ind_time = 0;
DEBUGLOG(("Add:time = [%.*s][%d]\n",hv_time.len,hv_time.arr,hv_time.len));
	}

/* acr_prorata*/
	if(GetField_Int(hRls,"is_prorata",&iTmp)){
		hv_acr_prorata = iTmp;
		ind_acr_prorata = 0;
DEBUGLOG(("Add:acr_prorata = [%d]\n",hv_acr_prorata));
	}
	else{
		hv_acr_prorata = PD_FALSE;
		ind_acr_prorata = 0;
DEBUGLOG(("Add:acr_prorata = [%d](default)\n",hv_acr_prorata));
	}

/* numerator */
	if(GetField_Double(hRls,"numerator",&dTmp)){
		hv_numerator = dTmp;
		ind_numerator = 0;
DEBUGLOG(("Add:numerator = [%lf]\n",hv_numerator));
	}

/* denominator */
	if(GetField_Double(hRls,"denominator",&dTmp)){
		hv_denominator = dTmp;
		ind_denominator = 0;
DEBUGLOG(("Add:denominator = [%lf]\n",hv_denominator));
	}

/* user*/
	if(GetField_CString(hRls,"add_user",&csTmp)){
		hv_user.len = strlen(csTmp);
		memcpy(hv_user.arr,csTmp,hv_user.len);
		ind_user = 0;
DEBUGLOG(("Add:user = [%.*s][%d]\n",hv_user.len,hv_user.arr,hv_user.len));
	}
	else{
		hv_user.len = strlen(PD_UPDATE_USER);
		memcpy(hv_user.arr,PD_UPDATE_USER,hv_user.len);
                ind_user = 0;
	}

	if(ind_numerator == 0 && ind_denominator == 0){
	    /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mi_acr_inout_his_insert2(
					:hv_batch_id:ind_batch_id,
					:hv_txn_date:ind_txn_date,
					:hv_bank_id:ind_bank_id,
					:hv_from_ccy:ind_from_ccy,
					:hv_from_amt:ind_from_amt,
					:hv_bank_ccy:ind_bank_ccy,
					:hv_bank_amt:ind_bank_amt,
					:hv_old_rate:ind_old_rate,
					:hv_new_rate:ind_new_rate,
					:hv_org_bank_bal:ind_org_bank_bal,
					:hv_bank_bal:ind_bank_bal,
					:hv_txn_code:ind_txn_code,
					:hv_fund_type:ind_fund_type,
					:hv_txn_id:ind_txn_id,
					:hv_time:ind_time,
					:hv_acr_prorata:ind_acr_prorata,
					:hv_user:ind_user,
					:hv_numerator:ind_numerator,
					:hv_denominator:ind_denominator);
                END;
	    END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 20;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_mi_acr_inout_his_insert2 (\
 :hv_batch_id:ind_batch_id , :hv_txn_date:ind_txn_date , :hv_bank_id:ind_bank\
_id , :hv_from_ccy:ind_from_ccy , :hv_from_amt:ind_from_amt , :hv_bank_ccy:in\
d_bank_ccy , :hv_bank_amt:ind_bank_amt , :hv_old_rate:ind_old_rate , :hv_new_\
rate:ind_new_rate , :hv_org_bank_bal:ind_org_bank_bal , :hv_bank_bal:ind_bank\
_bal , :hv_txn_code:ind_txn_code , :hv_fund_type:ind_fund_type , :hv_txn_id:i\
nd_txn_id , :hv_time:ind_time , :hv_acr_prorata:ind_acr_prorata , :hv_user:in\
d_user , :hv_numerator:ind_numerator , :hv_denominator:ind_denominator ) ; EN\
D ;";
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
     sqlstm.sqhstl[1] = (unsigned long )18;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)&ind_batch_id;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
     sqlstm.sqhstl[2] = (unsigned long )10;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)&ind_txn_date;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_id;
     sqlstm.sqhstl[3] = (unsigned long )22;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)&ind_bank_id;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)&hv_from_ccy;
     sqlstm.sqhstl[4] = (unsigned long )5;
     sqlstm.sqhsts[4] = (         int  )0;
     sqlstm.sqindv[4] = (         short *)&ind_from_ccy;
     sqlstm.sqinds[4] = (         int  )0;
     sqlstm.sqharm[4] = (unsigned long )0;
     sqlstm.sqadto[4] = (unsigned short )0;
     sqlstm.sqtdso[4] = (unsigned short )0;
     sqlstm.sqhstv[5] = (unsigned char  *)&hv_from_amt;
     sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)&ind_from_amt;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_ccy;
     sqlstm.sqhstl[6] = (unsigned long )5;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)&ind_bank_ccy;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_amt;
     sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[7] = (         int  )0;
     sqlstm.sqindv[7] = (         short *)&ind_bank_amt;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)&hv_old_rate;
     sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[8] = (         int  )0;
     sqlstm.sqindv[8] = (         short *)&ind_old_rate;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
     sqlstm.sqadto[8] = (unsigned short )0;
     sqlstm.sqtdso[8] = (unsigned short )0;
     sqlstm.sqhstv[9] = (unsigned char  *)&hv_new_rate;
     sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[9] = (         int  )0;
     sqlstm.sqindv[9] = (         short *)&ind_new_rate;
     sqlstm.sqinds[9] = (         int  )0;
     sqlstm.sqharm[9] = (unsigned long )0;
     sqlstm.sqadto[9] = (unsigned short )0;
     sqlstm.sqtdso[9] = (unsigned short )0;
     sqlstm.sqhstv[10] = (unsigned char  *)&hv_org_bank_bal;
     sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[10] = (         int  )0;
     sqlstm.sqindv[10] = (         short *)&ind_org_bank_bal;
     sqlstm.sqinds[10] = (         int  )0;
     sqlstm.sqharm[10] = (unsigned long )0;
     sqlstm.sqadto[10] = (unsigned short )0;
     sqlstm.sqtdso[10] = (unsigned short )0;
     sqlstm.sqhstv[11] = (unsigned char  *)&hv_bank_bal;
     sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[11] = (         int  )0;
     sqlstm.sqindv[11] = (         short *)&ind_bank_bal;
     sqlstm.sqinds[11] = (         int  )0;
     sqlstm.sqharm[11] = (unsigned long )0;
     sqlstm.sqadto[11] = (unsigned short )0;
     sqlstm.sqtdso[11] = (unsigned short )0;
     sqlstm.sqhstv[12] = (unsigned char  *)&hv_txn_code;
     sqlstm.sqhstl[12] = (unsigned long )5;
     sqlstm.sqhsts[12] = (         int  )0;
     sqlstm.sqindv[12] = (         short *)&ind_txn_code;
     sqlstm.sqinds[12] = (         int  )0;
     sqlstm.sqharm[12] = (unsigned long )0;
     sqlstm.sqadto[12] = (unsigned short )0;
     sqlstm.sqtdso[12] = (unsigned short )0;
     sqlstm.sqhstv[13] = (unsigned char  *)&hv_fund_type;
     sqlstm.sqhstl[13] = (unsigned long )1;
     sqlstm.sqhsts[13] = (         int  )0;
     sqlstm.sqindv[13] = (         short *)&ind_fund_type;
     sqlstm.sqinds[13] = (         int  )0;
     sqlstm.sqharm[13] = (unsigned long )0;
     sqlstm.sqadto[13] = (unsigned short )0;
     sqlstm.sqtdso[13] = (unsigned short )0;
     sqlstm.sqhstv[14] = (unsigned char  *)&hv_txn_id;
     sqlstm.sqhstl[14] = (unsigned long )18;
     sqlstm.sqhsts[14] = (         int  )0;
     sqlstm.sqindv[14] = (         short *)&ind_txn_id;
     sqlstm.sqinds[14] = (         int  )0;
     sqlstm.sqharm[14] = (unsigned long )0;
     sqlstm.sqadto[14] = (unsigned short )0;
     sqlstm.sqtdso[14] = (unsigned short )0;
     sqlstm.sqhstv[15] = (unsigned char  *)&hv_time;
     sqlstm.sqhstl[15] = (unsigned long )22;
     sqlstm.sqhsts[15] = (         int  )0;
     sqlstm.sqindv[15] = (         short *)&ind_time;
     sqlstm.sqinds[15] = (         int  )0;
     sqlstm.sqharm[15] = (unsigned long )0;
     sqlstm.sqadto[15] = (unsigned short )0;
     sqlstm.sqtdso[15] = (unsigned short )0;
     sqlstm.sqhstv[16] = (unsigned char  *)&hv_acr_prorata;
     sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[16] = (         int  )0;
     sqlstm.sqindv[16] = (         short *)&ind_acr_prorata;
     sqlstm.sqinds[16] = (         int  )0;
     sqlstm.sqharm[16] = (unsigned long )0;
     sqlstm.sqadto[16] = (unsigned short )0;
     sqlstm.sqtdso[16] = (unsigned short )0;
     sqlstm.sqhstv[17] = (unsigned char  *)&hv_user;
     sqlstm.sqhstl[17] = (unsigned long )22;
     sqlstm.sqhsts[17] = (         int  )0;
     sqlstm.sqindv[17] = (         short *)&ind_user;
     sqlstm.sqinds[17] = (         int  )0;
     sqlstm.sqharm[17] = (unsigned long )0;
     sqlstm.sqadto[17] = (unsigned short )0;
     sqlstm.sqtdso[17] = (unsigned short )0;
     sqlstm.sqhstv[18] = (unsigned char  *)&hv_numerator;
     sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[18] = (         int  )0;
     sqlstm.sqindv[18] = (         short *)&ind_numerator;
     sqlstm.sqinds[18] = (         int  )0;
     sqlstm.sqharm[18] = (unsigned long )0;
     sqlstm.sqadto[18] = (unsigned short )0;
     sqlstm.sqtdso[18] = (unsigned short )0;
     sqlstm.sqhstv[19] = (unsigned char  *)&hv_denominator;
     sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[19] = (         int  )0;
     sqlstm.sqindv[19] = (         short *)&ind_denominator;
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
     if (sqlca.sqlcode < 0) goto add_error;
}


	}
	else{
	    /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mi_acr_inout_his_insert(
					:hv_batch_id:ind_batch_id,
					:hv_txn_date:ind_txn_date,
					:hv_bank_id:ind_bank_id,
					:hv_from_ccy:ind_from_ccy,
					:hv_from_amt:ind_from_amt,
					:hv_bank_ccy:ind_bank_ccy,
					:hv_bank_amt:ind_bank_amt,
					:hv_old_rate:ind_old_rate,
					:hv_new_rate:ind_new_rate,
					:hv_org_bank_bal:ind_org_bank_bal,
					:hv_bank_bal:ind_bank_bal,
					:hv_txn_code:ind_txn_code,
					:hv_fund_type:ind_fund_type,
					:hv_txn_id:ind_txn_id,
					:hv_time:ind_time,
					:hv_acr_prorata:ind_acr_prorata,
					:hv_user:ind_user);
                END;
            END-EXEC; */ 

{
     struct sqlexd sqlstm;
     sqlstm.sqlvsn = 12;
     sqlstm.arrsiz = 20;
     sqlstm.sqladtp = &sqladt;
     sqlstm.sqltdsp = &sqltds;
     sqlstm.stmt = "begin :hv_return_value := sp_mi_acr_inout_his_insert ( \
:hv_batch_id:ind_batch_id , :hv_txn_date:ind_txn_date , :hv_bank_id:ind_bank_\
id , :hv_from_ccy:ind_from_ccy , :hv_from_amt:ind_from_amt , :hv_bank_ccy:ind\
_bank_ccy , :hv_bank_amt:ind_bank_amt , :hv_old_rate:ind_old_rate , :hv_new_r\
ate:ind_new_rate , :hv_org_bank_bal:ind_org_bank_bal , :hv_bank_bal:ind_bank_\
bal , :hv_txn_code:ind_txn_code , :hv_fund_type:ind_fund_type , :hv_txn_id:in\
d_txn_id , :hv_time:ind_time , :hv_acr_prorata:ind_acr_prorata , :hv_user:ind\
_user ) ; END ;";
     sqlstm.iters = (unsigned int  )1;
     sqlstm.offset = (unsigned int  )100;
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
     sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
     sqlstm.sqhstl[1] = (unsigned long )18;
     sqlstm.sqhsts[1] = (         int  )0;
     sqlstm.sqindv[1] = (         short *)&ind_batch_id;
     sqlstm.sqinds[1] = (         int  )0;
     sqlstm.sqharm[1] = (unsigned long )0;
     sqlstm.sqadto[1] = (unsigned short )0;
     sqlstm.sqtdso[1] = (unsigned short )0;
     sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_date;
     sqlstm.sqhstl[2] = (unsigned long )10;
     sqlstm.sqhsts[2] = (         int  )0;
     sqlstm.sqindv[2] = (         short *)&ind_txn_date;
     sqlstm.sqinds[2] = (         int  )0;
     sqlstm.sqharm[2] = (unsigned long )0;
     sqlstm.sqadto[2] = (unsigned short )0;
     sqlstm.sqtdso[2] = (unsigned short )0;
     sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_id;
     sqlstm.sqhstl[3] = (unsigned long )22;
     sqlstm.sqhsts[3] = (         int  )0;
     sqlstm.sqindv[3] = (         short *)&ind_bank_id;
     sqlstm.sqinds[3] = (         int  )0;
     sqlstm.sqharm[3] = (unsigned long )0;
     sqlstm.sqadto[3] = (unsigned short )0;
     sqlstm.sqtdso[3] = (unsigned short )0;
     sqlstm.sqhstv[4] = (unsigned char  *)&hv_from_ccy;
     sqlstm.sqhstl[4] = (unsigned long )5;
     sqlstm.sqhsts[4] = (         int  )0;
     sqlstm.sqindv[4] = (         short *)&ind_from_ccy;
     sqlstm.sqinds[4] = (         int  )0;
     sqlstm.sqharm[4] = (unsigned long )0;
     sqlstm.sqadto[4] = (unsigned short )0;
     sqlstm.sqtdso[4] = (unsigned short )0;
     sqlstm.sqhstv[5] = (unsigned char  *)&hv_from_amt;
     sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[5] = (         int  )0;
     sqlstm.sqindv[5] = (         short *)&ind_from_amt;
     sqlstm.sqinds[5] = (         int  )0;
     sqlstm.sqharm[5] = (unsigned long )0;
     sqlstm.sqadto[5] = (unsigned short )0;
     sqlstm.sqtdso[5] = (unsigned short )0;
     sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_ccy;
     sqlstm.sqhstl[6] = (unsigned long )5;
     sqlstm.sqhsts[6] = (         int  )0;
     sqlstm.sqindv[6] = (         short *)&ind_bank_ccy;
     sqlstm.sqinds[6] = (         int  )0;
     sqlstm.sqharm[6] = (unsigned long )0;
     sqlstm.sqadto[6] = (unsigned short )0;
     sqlstm.sqtdso[6] = (unsigned short )0;
     sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_amt;
     sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[7] = (         int  )0;
     sqlstm.sqindv[7] = (         short *)&ind_bank_amt;
     sqlstm.sqinds[7] = (         int  )0;
     sqlstm.sqharm[7] = (unsigned long )0;
     sqlstm.sqadto[7] = (unsigned short )0;
     sqlstm.sqtdso[7] = (unsigned short )0;
     sqlstm.sqhstv[8] = (unsigned char  *)&hv_old_rate;
     sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[8] = (         int  )0;
     sqlstm.sqindv[8] = (         short *)&ind_old_rate;
     sqlstm.sqinds[8] = (         int  )0;
     sqlstm.sqharm[8] = (unsigned long )0;
     sqlstm.sqadto[8] = (unsigned short )0;
     sqlstm.sqtdso[8] = (unsigned short )0;
     sqlstm.sqhstv[9] = (unsigned char  *)&hv_new_rate;
     sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[9] = (         int  )0;
     sqlstm.sqindv[9] = (         short *)&ind_new_rate;
     sqlstm.sqinds[9] = (         int  )0;
     sqlstm.sqharm[9] = (unsigned long )0;
     sqlstm.sqadto[9] = (unsigned short )0;
     sqlstm.sqtdso[9] = (unsigned short )0;
     sqlstm.sqhstv[10] = (unsigned char  *)&hv_org_bank_bal;
     sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[10] = (         int  )0;
     sqlstm.sqindv[10] = (         short *)&ind_org_bank_bal;
     sqlstm.sqinds[10] = (         int  )0;
     sqlstm.sqharm[10] = (unsigned long )0;
     sqlstm.sqadto[10] = (unsigned short )0;
     sqlstm.sqtdso[10] = (unsigned short )0;
     sqlstm.sqhstv[11] = (unsigned char  *)&hv_bank_bal;
     sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
     sqlstm.sqhsts[11] = (         int  )0;
     sqlstm.sqindv[11] = (         short *)&ind_bank_bal;
     sqlstm.sqinds[11] = (         int  )0;
     sqlstm.sqharm[11] = (unsigned long )0;
     sqlstm.sqadto[11] = (unsigned short )0;
     sqlstm.sqtdso[11] = (unsigned short )0;
     sqlstm.sqhstv[12] = (unsigned char  *)&hv_txn_code;
     sqlstm.sqhstl[12] = (unsigned long )5;
     sqlstm.sqhsts[12] = (         int  )0;
     sqlstm.sqindv[12] = (         short *)&ind_txn_code;
     sqlstm.sqinds[12] = (         int  )0;
     sqlstm.sqharm[12] = (unsigned long )0;
     sqlstm.sqadto[12] = (unsigned short )0;
     sqlstm.sqtdso[12] = (unsigned short )0;
     sqlstm.sqhstv[13] = (unsigned char  *)&hv_fund_type;
     sqlstm.sqhstl[13] = (unsigned long )1;
     sqlstm.sqhsts[13] = (         int  )0;
     sqlstm.sqindv[13] = (         short *)&ind_fund_type;
     sqlstm.sqinds[13] = (         int  )0;
     sqlstm.sqharm[13] = (unsigned long )0;
     sqlstm.sqadto[13] = (unsigned short )0;
     sqlstm.sqtdso[13] = (unsigned short )0;
     sqlstm.sqhstv[14] = (unsigned char  *)&hv_txn_id;
     sqlstm.sqhstl[14] = (unsigned long )18;
     sqlstm.sqhsts[14] = (         int  )0;
     sqlstm.sqindv[14] = (         short *)&ind_txn_id;
     sqlstm.sqinds[14] = (         int  )0;
     sqlstm.sqharm[14] = (unsigned long )0;
     sqlstm.sqadto[14] = (unsigned short )0;
     sqlstm.sqtdso[14] = (unsigned short )0;
     sqlstm.sqhstv[15] = (unsigned char  *)&hv_time;
     sqlstm.sqhstl[15] = (unsigned long )22;
     sqlstm.sqhsts[15] = (         int  )0;
     sqlstm.sqindv[15] = (         short *)&ind_time;
     sqlstm.sqinds[15] = (         int  )0;
     sqlstm.sqharm[15] = (unsigned long )0;
     sqlstm.sqadto[15] = (unsigned short )0;
     sqlstm.sqtdso[15] = (unsigned short )0;
     sqlstm.sqhstv[16] = (unsigned char  *)&hv_acr_prorata;
     sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
     sqlstm.sqhsts[16] = (         int  )0;
     sqlstm.sqindv[16] = (         short *)&ind_acr_prorata;
     sqlstm.sqinds[16] = (         int  )0;
     sqlstm.sqharm[16] = (unsigned long )0;
     sqlstm.sqadto[16] = (unsigned short )0;
     sqlstm.sqtdso[16] = (unsigned short )0;
     sqlstm.sqhstv[17] = (unsigned char  *)&hv_user;
     sqlstm.sqhstl[17] = (unsigned long )22;
     sqlstm.sqhsts[17] = (         int  )0;
     sqlstm.sqindv[17] = (         short *)&ind_user;
     sqlstm.sqinds[17] = (         int  )0;
     sqlstm.sqharm[17] = (unsigned long )0;
     sqlstm.sqadto[17] = (unsigned short )0;
     sqlstm.sqtdso[17] = (unsigned short )0;
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


	}

DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("Add: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetOverviewByBatchId(const char *csBatchId, recordset_t* myRec)
{
	int	iRet = PD_ERR;
        int     iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gethistory_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		/* varchar         v_txn_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar         v_bank_id[PD_MMS_OPB_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_id;

                /* varchar         v_from_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_from_ccy;

                double          v_from_amt;
                /* varchar         v_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

                double          v_bank_amt;
                double          v_org_bank_bal;
                double          v_bank_bal;
                double          v_old_rate;
                double          v_new_rate;
                /* varchar         v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                char            v_fund_type;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_txn_date = -1;
                short           ind_bank_id = -1;
                short           ind_from_ccy = -1;
                short           ind_from_amt = -1;
                short           ind_bank_ccy = -1;
                short           ind_bank_amt = -1;
                short           ind_org_bank_bal = -1;
                short           ind_bank_bal = -1;
                short           ind_old_rate = -1;
                short           ind_new_rate = -1;
                short           ind_txn_code = -1;
                short           ind_fund_type = -1;
                short           ind_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("GetOverviewByBatchId:batch_id = [%.*s][%d]\n",hv_batch_id.len,hv_batch_id.arr,hv_batch_id.len));

	/* EXEC SQL DECLARE c_cursor_gethistory CURSOR FOR
		select	txn_date,
			bank_id,
			from_ccy,
			from_amt,
			bank_ccy,
			bank_amt,
			old_rate,
			new_rate,
			org_bank_bal,
			bank_bal,
			txn_code,
			fund_type,
			txn_id
		FROM	mi_acr_inout_overview
		WHERE	batch_id = :hv_batch_id; */ 


	/* EXEC SQL OPEN c_cursor_gethistory; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )187;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_batch_id;
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
 if (sqlca.sqlcode < 0) goto gethistory_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gethistory
                INTO
			v_txn_date:ind_txn_date,
                        v_bank_id:ind_bank_id,
                        v_from_ccy:ind_from_ccy,
                        v_from_amt:ind_from_amt,
                        v_bank_ccy:ind_bank_ccy,
                        v_bank_amt:ind_bank_amt,
                        v_old_rate:ind_old_rate,
                        v_new_rate:ind_new_rate,
                        v_org_bank_bal:ind_org_bank_bal,
                        v_bank_bal:ind_bank_bal,
                        v_txn_code:ind_txn_code,
                        v_fund_type:ind_fund_type,
                        v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )206;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_id;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_from_ccy;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_from_ccy;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_from_amt;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_from_amt;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bank_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bank_amt;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_old_rate;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_old_rate;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_new_rate;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_new_rate;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_org_bank_bal;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_org_bank_bal;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_bal;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_bal;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[10] = (unsigned long )6;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_txn_code;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_fund_type;
                sqlstm.sqhstl[11] = (unsigned long )1;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_fund_type;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[12] = (unsigned long )19;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_txn_id;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gethistory_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if(ind_txn_date>=0){
			v_txn_date.arr[v_txn_date.len] = '\0';
			PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetOverviewByBatchId txn_date = [%s]\n",v_txn_date.arr));
		}

		if(ind_bank_id>=0){
			v_bank_id.arr[v_bank_id.len] = '\0';
			PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetOverviewByBatchId bank_id = [%s]\n",v_bank_id.arr));
		}

		if(ind_from_ccy>=0){
			v_from_ccy.arr[v_from_ccy.len] = '\0';
			PutField_CString(myHash,"from_ccy",(const char*)v_from_ccy.arr);
DEBUGLOG(("GetOverviewByBatchId from_ccy = [%s]\n",v_from_ccy.arr));
		}

		if(ind_from_amt>=0){
			PutField_Double(myHash,"from_amt",v_from_amt);
DEBUGLOG(("GetOverviewByBatchId from_amt = [%lf]\n",v_from_amt));
		}

		if(ind_bank_ccy>=0){
			v_bank_ccy.arr[v_bank_ccy.len] = '\0';
			PutField_CString(myHash,"bank_ccy",(const char*)v_bank_ccy.arr);
DEBUGLOG(("GetOverviewByBatchId bank_ccy = [%s]\n",v_bank_ccy.arr));
		}

		if(ind_bank_amt>=0){
			PutField_Double(myHash,"bank_amt",v_bank_amt);
DEBUGLOG(("GetOverviewByBatchId bank_amt = [%lf]\n",v_bank_amt));
		}

		if(ind_old_rate>=0){
			PutField_Double(myHash,"old_rate",v_old_rate);
DEBUGLOG(("GetOverviewByBatchId old_rate = [%lf]\n",v_old_rate));
		}

		if(ind_new_rate>=0){
			PutField_Double(myHash,"new_rate",v_new_rate);
DEBUGLOG(("GetOverviewByBatchId new_rate = [%lf]\n",v_new_rate));
		}

		if(ind_org_bank_bal>=0){
			PutField_Double(myHash,"org_bank_bal",v_org_bank_bal);
DEBUGLOG(("GetOverviewByBatchId org_bank_bal = [%lf]\n",v_org_bank_bal));
		}

		if(ind_bank_bal>=0){
			PutField_Double(myHash,"bank_bal",v_bank_bal);
DEBUGLOG(("GetOverviewByBatchId bank_bal = [%lf]\n",v_bank_bal));
		}

		if(ind_txn_code>=0){
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetOverviewByBatchId txn_code = [%s]\n",v_txn_code.arr));
		}

		if(ind_fund_type>=0){
			PutField_Char(myHash,"fund_type",v_fund_type);
DEBUGLOG(("GetOverviewByBatchId fund_type = [%c]\n",v_fund_type));
		}

		if(ind_txn_id>=0){
			v_txn_id.arr[v_txn_id.len] = '\0';
			PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetOverviewByBatchId txn_id = [%s]\n",v_txn_id.arr));
		}

		RecordSet_Add(myRec,myHash);
	}
	while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )273;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gethistory_error;
}



	if (iCnt > 0 ) {
		iRet = PD_OK;
        }

DEBUGLOG(("GetOverviewByBatchId Normal Exit\n"));
	return iRet;

gethistory_error:
DEBUGLOG(("gethistory_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PspDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )288;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int IsLastBatchInOverview(const char *csBatchId)
{
	int iRet = PD_FALSE;

	/* EXEC SQL WHENEVER SQLERROR GOTO is_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;


		int     v_last;
		short   ind_last = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("IsLastBatchInOverview: BatchId = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

	/* EXEC SQL
		SELECT CASE WHEN batch_time = max_time THEN 1 ELSE 0 END
		INTO :v_last:ind_last
		FROM (SELECT MAX (time) batch_time
			FROM mi_acr_inout_overview
			WHERE batch_id = :hv_batch_id),
		     (SELECT MAX (time) max_time
		        FROM mi_acr_inout_overview
			WHERE time >= (SELECT MAX (time) batch_time
					FROM mi_acr_inout_overview
					WHERE batch_id = :hv_batch_id))
		WHERE 1 = 1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CASE WHEN batch_time = max_time THEN 1 ELSE 0 END IN\
TO :b0:b1 FROM ( SELECT MAX ( time ) batch_time FROM mi_acr_inout_overview WH\
ERE batch_id = :b2 ) , ( SELECT MAX ( time ) max_time FROM mi_acr_inout_overv\
iew WHERE time >= ( SELECT MAX ( time ) batch_time FROM mi_acr_inout_overview\
 WHERE batch_id = :b2 ) ) WHERE 1 = 1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )303;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_last;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_last;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
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
 if (sqlca.sqlcode < 0) goto is_error;
}



	if (ind_last >= 0){
		iRet = v_last;
	}

DEBUGLOG(("IsLastBatchInOverview iRet = [%d]\n",iRet));
	return iRet;

is_error:
DEBUGLOG(("is_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_FALSE;
}



int GetOverviewHistory(const char *csFromCcy, const char *csBankCcy, const int iPeriod, recordset_t* myRec)
{
	int	iRet = PD_ERR;
        int     iCnt = 0;
	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO gethistory_overview_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_from_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_from_ccy;

                /* varchar         hv_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_bank_ccy;

		int		hv_period;

		/* varchar         v_txn_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

                /* varchar         v_bank_id[PD_MMS_OPB_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bank_id;

                double          v_from_amt;
                double          v_bank_amt;
                double          v_org_bank_bal;
                double          v_bank_bal;
                double          v_old_rate;
                double          v_new_rate;
                /* varchar         v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                char            v_fund_type;
		int		v_acr_prorata;
		/* varchar		v_time[PD_DATETIME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_time;


                short           ind_txn_date = -1;
                short           ind_bank_id = -1;
                short           ind_from_amt = -1;
                short           ind_bank_amt = -1;
                short           ind_org_bank_bal = -1;
                short           ind_bank_bal = -1;
                short           ind_old_rate = -1;
                short           ind_new_rate = -1;
                short           ind_txn_code = -1;
                short           ind_fund_type = -1;
                short           ind_acr_prorata = -1;
                short           ind_time = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_from_ccy.len = strlen(csFromCcy);
	memcpy(hv_from_ccy.arr,csFromCcy,hv_from_ccy.len);
DEBUGLOG(("GetOverviewHistory:from_ccy = [%.*s][%d]\n",hv_from_ccy.len,hv_from_ccy.arr,hv_from_ccy.len));

	hv_bank_ccy.len = strlen(csBankCcy);
	memcpy(hv_bank_ccy.arr,csBankCcy,hv_bank_ccy.len);
DEBUGLOG(("GetOverviewHistory:bank_ccy = [%.*s][%d]\n",hv_bank_ccy.len,hv_bank_ccy.arr,hv_bank_ccy.len));

	hv_period = iPeriod;
DEBUGLOG(("GetOverviewHistory:period = [%d]\n",hv_period));

DEBUGLOG((" - [txn_date], [bank_id], [from_ccy amt], [bank_ccy amt], [old_rate], [new_rate], [org_bank_bal], [bank_bal], [txn_code], [fund_type], [acr_prorata], [time]\n"));
	/* EXEC SQL DECLARE c_cursor_gethistory_overview CURSOR FOR
		select  txn_date,
			bank_id,
			from_amt,
			bank_amt,
			old_rate,
			new_rate,
			org_bank_bal,
			bank_bal,
			txn_code,
			fund_type,
			acr_prorata,
			to_char(time, 'YYYYMMDDHH24MISS')
		FROM	mi_acr_inout_overview
		WHERE	from_ccy = :hv_from_ccy
		AND	bank_ccy = :hv_bank_ccy
		AND	time > to_date(to_char(sysdate - (:hv_period - 1), 'YYYYMMDD'), 'YYYYMMDD')
		ORDER BY time; */ 


	/* EXEC SQL OPEN c_cursor_gethistory_overview; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )330;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[1] = (unsigned long )6;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_period;
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
 if (sqlca.sqlcode < 0) goto gethistory_overview_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gethistory_overview
                INTO
			v_txn_date:ind_txn_date,
                        v_bank_id:ind_bank_id,
                        v_from_amt:ind_from_amt,
                        v_bank_amt:ind_bank_amt,
                        v_old_rate:ind_old_rate,
                        v_new_rate:ind_new_rate,
                        v_org_bank_bal:ind_org_bank_bal,
                        v_bank_bal:ind_bank_bal,
                        v_txn_code:ind_txn_code,
                        v_fund_type:ind_fund_type,
                        v_acr_prorata:ind_acr_prorata,
			v_time:ind_time; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 20;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_id;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bank_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_from_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_from_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_amt;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_amt;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_old_rate;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_old_rate;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_new_rate;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_new_rate;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_org_bank_bal;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_org_bank_bal;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_bal;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bank_bal;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[8] = (unsigned long )6;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_txn_code;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_fund_type;
                sqlstm.sqhstl[9] = (unsigned long )1;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_fund_type;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_acr_prorata;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_acr_prorata;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_time;
                sqlstm.sqhstl[11] = (unsigned long )17;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_time;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gethistory_overview_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

		if(ind_txn_date>=0){
			v_txn_date.arr[v_txn_date.len] = '\0';
			PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
		}
		else{
			v_txn_date.arr[0] = '\0';
		}

		if(ind_bank_id>=0){
			v_bank_id.arr[v_bank_id.len] = '\0';
			PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
		}
		else{
			v_bank_id.arr[0] = '\0';
		}

		if(ind_from_amt>=0){
			PutField_Double(myHash,"from_amt",v_from_amt);
		}

		if(ind_bank_amt>=0){
			PutField_Double(myHash,"bank_amt",v_bank_amt);
		}

		if(ind_old_rate>=0){
			PutField_Double(myHash,"old_rate",v_old_rate);
		}

		if(ind_new_rate>=0){
			PutField_Double(myHash,"new_rate",v_new_rate);
		}

		if(ind_org_bank_bal>=0){
			PutField_Double(myHash,"org_bank_bal",v_org_bank_bal);
		}

		if(ind_bank_bal>=0){
			PutField_Double(myHash,"bank_bal",v_bank_bal);
		}

		if(ind_txn_code>=0){
			v_txn_code.arr[v_txn_code.len] = '\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
		}
		else{
			v_txn_code.arr[0] = '\0';
		}

		if(ind_fund_type>=0){
			PutField_Char(myHash,"fund_type",v_fund_type);
		}
		else{
			v_fund_type = '\0';
		}

		if(ind_acr_prorata>=0){
			PutField_Int(myHash,"acr_prorata",v_acr_prorata);
		}

		if(ind_time>=0){
			v_time.arr[v_time.len] = '\0';
			PutField_CString(myHash,"time",(const char*)v_time.arr);
		}
		else{
			v_time.arr[0] = '\0';
		}

DEBUGLOG((" - [%s], [%s], [%s %lf], [%s %lf], [%lf], [%lf], [%lf], [%lf], [%s], [%c], [%d], [%s]\n", 
		v_txn_date.arr, v_bank_id.arr, hv_from_ccy.arr, v_from_amt, hv_bank_ccy.arr, 
		v_bank_amt, v_old_rate, v_new_rate, v_org_bank_bal, v_bank_bal, 
		v_txn_code.arr, v_fund_type, v_acr_prorata, v_time.arr));

		RecordSet_Add(myRec,myHash);
	}
	while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gethistory_overview; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )420;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gethistory_overview_error;
}



	if (iCnt > 0 ) {
		iRet = PD_OK;
        }

DEBUGLOG(("GetOverviewHistory Normal Exit\n"));
	return iRet;

gethistory_overview_error:
DEBUGLOG(("gethistory_overview_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAcrInOutHistory_GetOverviewHistory: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_gethistory_overview; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )435;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int IsLastBatchInOverviewByCcy(const char *csBatchId, const char *csFromCcy, const char *csBankCcy)
{
	int iRet = PD_FALSE;

	/* EXEC SQL WHENEVER SQLERROR GOTO is_last_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_batch_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_batch_id;

		/* varchar hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

		/* varchar hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;


		int     v_last;
		short   ind_last = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_batch_id.len = strlen(csBatchId);
	memcpy(hv_batch_id.arr,csBatchId,hv_batch_id.len);
DEBUGLOG(("IsLastBatchInOverviewByCcy: BatchId = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));

	hv_from_ccy.len = strlen(csFromCcy);
	memcpy(hv_from_ccy.arr,csFromCcy,hv_from_ccy.len);
DEBUGLOG(("IsLastBatchInOverviewByCcy: FromCcy = [%.*s]\n",hv_from_ccy.len,hv_from_ccy.arr));

	hv_bank_ccy.len = strlen(csBankCcy);
	memcpy(hv_bank_ccy.arr,csBankCcy,hv_bank_ccy.len);
DEBUGLOG(("IsLastBatchInOverviewByCcy: BankCcy = [%.*s]\n",hv_bank_ccy.len,hv_bank_ccy.arr));

	/* EXEC SQL
		SELECT CASE WHEN batch_time = max_time THEN 1 ELSE 0 END
		INTO :v_last:ind_last
		FROM (SELECT MAX (time) batch_time
			FROM mi_acr_inout_overview
			WHERE batch_id = :hv_batch_id
			AND from_ccy = :hv_from_ccy
			AND bank_ccy = :hv_bank_ccy),
		     (SELECT MAX (time) max_time
		        FROM mi_acr_inout_overview
			WHERE from_ccy = :hv_from_ccy
			AND bank_ccy = :hv_bank_ccy
			AND time >= (SELECT MAX (time) batch_time
					FROM mi_acr_inout_overview
					WHERE batch_id = :hv_batch_id
					AND from_ccy = :hv_from_ccy
					AND bank_ccy = :hv_bank_ccy))
		WHERE 1 = 1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 20;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select CASE WHEN batch_time = max_time THEN 1 ELSE 0 END IN\
TO :b0:b1 FROM ( SELECT MAX ( time ) batch_time FROM mi_acr_inout_overview WH\
ERE batch_id = :b2 AND from_ccy = :b3 AND bank_ccy = :b4 ) , ( SELECT MAX ( t\
ime ) max_time FROM mi_acr_inout_overview WHERE from_ccy = :b3 AND bank_ccy =\
 :b4 AND time >= ( SELECT MAX ( time ) batch_time FROM mi_acr_inout_overview \
WHERE batch_id = :b2 AND from_ccy = :b3 AND bank_ccy = :b4 ) ) WHERE 1 = 1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )450;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_last;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_last;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[6] = (unsigned long )18;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[8] = (unsigned long )5;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto is_last_error;
}



	if (ind_last >= 0){
		iRet = v_last;
	}

DEBUGLOG(("IsLastBatchInOverviewByCcy iRet = [%d]\n",iRet));
	return iRet;

is_last_error:
DEBUGLOG(("is_last_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_FALSE;
}

