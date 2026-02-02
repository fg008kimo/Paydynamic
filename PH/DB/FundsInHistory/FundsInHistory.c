
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
    "FundsInHistory.pc"
};


static unsigned int sqlctx = 9853667;


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
   unsigned char  *sqhstv[13];
   unsigned long  sqhstl[13];
            int   sqhsts[13];
            short *sqindv[13];
            int   sqinds[13];
   unsigned long  sqharm[13];
   unsigned long  *sqharc[13];
   unsigned short  sqadto[13];
   unsigned short  sqtdso[13];
} sqlstm = {12,13};

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
"select fi_old_rate , fi_new_rate , fi_old_ratio , fi_new_ratio , fi_bank_ba\
l from funds_in_history where fi_funds_in_id = :b0 and fi_funds_in_ccy = :b1 \
and fi_bank_ccy = :b2            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,434,0,6,170,0,0,13,13,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
72,0,0,2,185,0,9,283,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
99,0,0,2,0,0,13,285,0,0,5,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
134,0,0,2,0,0,15,332,0,0,0,0,0,1,0,
149,0,0,2,0,0,15,342,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/13              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "FundsInHistory.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void FundsInHistory(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char		*csTmp;
        double          dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	/* varchar		hv_funds_in_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_funds_in_id;

	/* varchar		hv_funds_in_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_funds_in_date;
	
	/* varchar		hv_funds_in_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_funds_in_ccy;

	double		hv_funds_in_amt;
	/* varchar		hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;

	double		hv_bank_amt;
	double		hv_bank_bal;
	double		hv_old_rate;
	double		hv_new_rate;
	double		hv_old_ratio;
	double		hv_new_ratio;
	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;




	short		ind_funds_in_id = -1;
	short		ind_funds_in_date = -1;
	short		ind_funds_in_ccy = -1;
	short		ind_funds_in_amt = -1;
	short		ind_bank_ccy = -1;
	short		ind_bank_amt = -1;
	short		ind_bank_bal = -1;
	short		ind_old_rate = -1;
	short		ind_new_rate = -1;
	short		ind_old_ratio = -1;
	short		ind_new_ratio = -1;
	short		ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* funds_in_id */
        if (GetField_CString(hRls,"fundsin_id",&csTmp)) {
		hv_funds_in_id.len= strlen(csTmp);
                memcpy(hv_funds_in_id.arr,csTmp,hv_funds_in_id.len);
                ind_funds_in_id = 0;
DEBUGLOG(("Add:funds_in_id = [%d]\n",hv_funds_in_id));
        }

/* funds_in_date */
        if (GetField_CString(hRls,"fundin_date",&csTmp)) {
                hv_funds_in_date.len = strlen(csTmp);
                memcpy(hv_funds_in_date.arr,csTmp,hv_funds_in_date.len);
                ind_funds_in_date = 0;
DEBUGLOG(("Add:funds_in_date = [%.*s][%d]\n",hv_funds_in_date.len,hv_funds_in_date.arr,hv_funds_in_date.len));
        }
/* funds_in_ccy */
        if (GetField_CString(hRls,"fundin_ccy",&csTmp)) {
                hv_funds_in_ccy.len = strlen(csTmp);
                memcpy(hv_funds_in_ccy.arr,csTmp,hv_funds_in_ccy.len);
                ind_funds_in_ccy = 0;
DEBUGLOG(("Add:funds_in_ccy = [%.*s][%d]\n",hv_funds_in_ccy.len,hv_funds_in_ccy.arr,hv_funds_in_ccy.len));
        }



/* funds_in_amt   */
        if (GetField_Double(hRls,"fundin_amt",&dTmp)) {
		hv_funds_in_amt= dTmp;
                ind_funds_in_amt = 0;
DEBUGLOG(("Add:funds_in_amt = [%f]\n",hv_funds_in_amt));
        }


/* bank_ccy */
        if (GetField_CString(hRls,"bank_ccy",&csTmp)) {
                hv_bank_ccy.len = strlen(csTmp);
                memcpy(hv_bank_ccy.arr,csTmp,hv_bank_ccy.len);
                ind_bank_ccy = 0;
DEBUGLOG(("Add:bank_ccy = [%.*s][%d]\n",hv_bank_ccy.len,hv_bank_ccy.arr,hv_bank_ccy.len));
        }


/* bank_amt */
	if (GetField_Double(hRls,"bank_amt", &dTmp)) {
		hv_bank_amt= dTmp;
                ind_bank_amt = 0;
DEBUGLOG(("Add:bank_amt = [%f]\n",hv_bank_amt));
	}

/* bank_bal */
	if (GetField_Double(hRls,"bank_bal", &dTmp)) {
		hv_bank_bal= dTmp;
                ind_bank_bal = 0;
DEBUGLOG(("Add:bank_bal = [%f]\n",hv_bank_bal));
	}

/* old_rate*/
	if (GetField_Double(hRls,"org_rate", &dTmp)) {
		hv_old_rate= dTmp;
                ind_old_rate= 0;
DEBUGLOG(("Add:old_rate = [%f]\n",hv_old_rate));
	}

/* new_rate*/
	if (GetField_Double(hRls,"rate", &dTmp)) {
		hv_new_rate= dTmp;
                ind_new_rate= 0;
DEBUGLOG(("Add:new_rate = [%f]\n",hv_new_rate));
	}

/* old_ratio*/
	if (GetField_Double(hRls,"org_ratio", &dTmp)) {
		hv_old_ratio= dTmp;
                ind_old_ratio= 0;
DEBUGLOG(("Add:old_ratio = [%f]\n",hv_old_ratio));
	}

/* new_ratio*/
	if (GetField_Double(hRls,"ratio", &dTmp)) {
		hv_new_ratio= dTmp;
                ind_new_ratio= 0;
DEBUGLOG(("Add:new_ratio = [%f]\n",hv_new_ratio));
	}


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	FREE_ME(csTmp);

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_funds_in_history_insert(
					:hv_funds_in_id:ind_funds_in_id,
					:hv_funds_in_date:ind_funds_in_date,
					:hv_funds_in_ccy:ind_funds_in_ccy,
					:hv_funds_in_amt:ind_funds_in_amt,
					:hv_bank_ccy:ind_bank_ccy,
					:hv_bank_amt:ind_bank_amt,
					:hv_bank_bal:ind_bank_bal,
					:hv_old_rate:ind_old_rate,
					:hv_new_rate:ind_new_rate,
					:hv_old_ratio:ind_old_ratio,
					:hv_new_ratio:ind_new_ratio,
					:hv_add_user:ind_add_user);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 13;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_funds_in_history_insert ( :hv_\
funds_in_id:ind_funds_in_id , :hv_funds_in_date:ind_funds_in_date , :hv_funds\
_in_ccy:ind_funds_in_ccy , :hv_funds_in_amt:ind_funds_in_amt , :hv_bank_ccy:i\
nd_bank_ccy , :hv_bank_amt:ind_bank_amt , :hv_bank_bal:ind_bank_bal , :hv_old\
_rate:ind_old_rate , :hv_new_rate:ind_new_rate , :hv_old_ratio:ind_old_ratio \
, :hv_new_ratio:ind_new_ratio , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_funds_in_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_funds_in_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_funds_in_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_funds_in_date;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_funds_in_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_funds_in_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_funds_in_amt;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_funds_in_amt;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[5] = (unsigned long )5;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_amt;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bank_amt;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_bal;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_bank_bal;
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
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_old_ratio;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_old_ratio;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_new_ratio;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_new_ratio;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[12] = (unsigned long )22;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("FundsInHistory_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("FundsInHistory_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("FundsInHistory_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int GetFundsInHistory(const hash_t *hRls, recordset_t* myRec)
{
        hash_t *myHash;
	char	*csTmp;
	//double	dTmp;
        /* EXEC SQL WHENEVER SQLERROR GOTO gethistory_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_fundin_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_fundin_id;

                /* varchar         hv_fundin_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_fundin_ccy;

                /* varchar         hv_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_bank_ccy;


                //varchar         v_fundin_date[PD_DATE_LEN+1];
                //double          v_fundin_amt;
                //double          v_bank_amt;
                double          v_old_rate;
                double          v_new_rate;
                double          v_old_ratio;
                double          v_new_ratio;
                double          v_bank_bal;

                //short           ind_fundin_date= -1;
                //short           ind_fundin_amt= -1;
                //short           ind_bank_amt= -1;
                short           ind_old_rate= -1;
                short           ind_new_rate= -1;
                short           ind_old_ratio= -1;
                short           ind_new_ratio= -1;
                short           ind_bank_bal= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* fundin_id*/
        if (GetField_CString(hRls,"fundsin_id",&csTmp)) {
                hv_fundin_id.len = strlen(csTmp);
                memcpy(hv_fundin_id.arr,csTmp,hv_fundin_id.len);
DEBUGLOG(("GetFundsInHistory:fundin_id = [%.*s][%d]\n",hv_fundin_id.len,hv_fundin_id.arr,hv_fundin_id.len));
        }

/* fundin_ccy */
        if (GetField_CString(hRls,"fundin_ccy",&csTmp)) {
                hv_fundin_ccy.len = strlen(csTmp);
                memcpy(hv_fundin_ccy.arr,csTmp,hv_fundin_ccy.len);
DEBUGLOG(("GetFundsInHistory:fundin_ccy = [%.*s][%d]\n",hv_fundin_ccy.len,hv_fundin_ccy.arr,hv_fundin_ccy.len));
        }

/* bank_ccy */
        if (GetField_CString(hRls,"bank_ccy",&csTmp)) {
                hv_bank_ccy.len = strlen(csTmp);
                memcpy(hv_bank_ccy.arr,csTmp,hv_bank_ccy.len);
DEBUGLOG(("GetFundsInHistory:bank_ccy = [%.*s][%d]\n",hv_bank_ccy.len,hv_bank_ccy.arr,hv_bank_ccy.len));
        }

        /* EXEC SQL DECLARE c_cursor_gethistory CURSOR FOR
                select  fi_old_rate,
                        fi_new_rate,
                        fi_old_ratio,
                        fi_new_ratio,
                        fi_bank_bal
                from    funds_in_history
                where   fi_funds_in_id =:hv_fundin_id
		and	fi_funds_in_ccy = :hv_fundin_ccy
		and	fi_bank_ccy = :hv_bank_ccy; */ 


        /* EXEC SQL OPEN  c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )72;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_fundin_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_fundin_ccy;
        sqlstm.sqhstl[1] = (unsigned long )6;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_ccy;
        sqlstm.sqhstl[2] = (unsigned long )6;
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
        if (sqlca.sqlcode < 0) goto gethistory_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_gethistory
                INTO
                        :v_old_rate:ind_old_rate,
                        :v_new_rate:ind_new_rate,
                        :v_old_ratio:ind_old_ratio,
                        :v_new_ratio:ind_new_ratio,
                        :v_bank_bal:ind_bank_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 13;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )99;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_old_rate;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_old_rate;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_new_rate;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_new_rate;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_old_ratio;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_old_ratio;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_new_ratio;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_new_ratio;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_bal;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_bal;
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
                if (sqlca.sqlcode < 0) goto gethistory_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);


/*old_rate*/
                if(ind_old_rate>=0){
                        PutField_Double(myHash,"old_rate",v_old_rate);
DEBUGLOG(("GetFundsInHistory old_rate= [%lf]\n",v_old_rate));
                }
/*new_rate*/
                if(ind_new_rate>=0){
                        PutField_Double(myHash,"new_rate",v_new_rate);
DEBUGLOG(("GetFundsInHistory new_rate= [%lf]\n",v_new_rate));
                }
/*old_ratio*/
                if(ind_old_ratio>=0){
                        PutField_Double(myHash,"old_ratio",v_old_ratio);
DEBUGLOG(("GetFundsInHistory old_ratio= [%lf]\n",v_old_ratio));
                }
/*new_ratio*/
                if(ind_new_ratio>=0){
                        PutField_Double(myHash,"new_ratio",v_new_ratio);
DEBUGLOG(("GetFundsInHistory new_ratio= [%lf]\n",v_new_ratio));
                }
/*bank_bal*/
                if(ind_bank_bal>=0){
                        PutField_Double(myHash,"bank_bal",v_bank_bal);
DEBUGLOG(("GetFundsInHistory bank_bal= [%lf]\n",v_bank_bal));
                }


                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )134;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gethistory_error;
}



DEBUGLOG(("GetFundsInHistory Normal Exit\n"));
        return  PD_OK;

gethistory_error:
DEBUGLOG(("gethistory_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetFundsInHistory: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 13;
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
