
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
    "FundsOutHistory.pc"
};


static unsigned int sqlctx = 19755747;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"select fo_funds_out_date , fo_funds_out_ccy , fo_funds_out_amt , fo_from_cc\
y , fo_old_bal , fo_new_bal from funds_out_history where fo_funds_out_id = :b\
0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,323,0,6,131,0,0,9,9,0,1,0,2,3,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,9,0,0,
56,0,0,2,165,0,9,217,0,2049,1,1,0,1,0,1,3,0,0,
75,0,0,2,0,0,13,219,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,
0,0,
114,0,0,2,0,0,15,275,0,0,0,0,0,1,0,
129,0,0,2,0,0,15,285,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/04/29              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "FundsOutHistory.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void FundsOutHistory(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char		*csTmp;
        double          dTmp;
	int		iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	int		hv_funds_out_id;
	/* varchar		hv_funds_out_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_funds_out_date;
	
	/* varchar		hv_funds_out_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_funds_out_ccy;

	double		hv_funds_out_amt;
	/* varchar		hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

	double		hv_new_bal;
	double		hv_old_bal;
	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



	short		ind_funds_out_id = -1;
	short		ind_funds_out_date = -1;
	short		ind_funds_out_ccy = -1;
	short		ind_funds_out_amt = -1;
	short		ind_from_ccy = -1;
	short		ind_old_bal = -1;
	short		ind_new_bal = -1;
	short		ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* funds_out_id */
        if (GetField_Int(hRls,"fundsout_id",&iTmp)) {
		hv_funds_out_id= iTmp;
                ind_funds_out_id = 0;
DEBUGLOG(("Add:funds_out_id = [%d]\n",hv_funds_out_id));
        }

/* funds_out_date */
        if (GetField_CString(hRls,"fundout_date",&csTmp)) {
                hv_funds_out_date.len = strlen(csTmp);
                memcpy(hv_funds_out_date.arr,csTmp,hv_funds_out_date.len);
                ind_funds_out_date = 0;
DEBUGLOG(("Add:funds_out_date = [%.*s][%d]\n",hv_funds_out_date.len,hv_funds_out_date.arr,hv_funds_out_date.len));
        }
/* funds_out_ccy */
        if (GetField_CString(hRls,"fundout_ccy",&csTmp)) {
                hv_funds_out_ccy.len = strlen(csTmp);
                memcpy(hv_funds_out_ccy.arr,csTmp,hv_funds_out_ccy.len);
                ind_funds_out_ccy = 0;
DEBUGLOG(("Add:funds_out_ccy = [%.*s][%d]\n",hv_funds_out_ccy.len,hv_funds_out_ccy.arr,hv_funds_out_ccy.len));
        }



/* funds_out_amt   */
        if (GetField_Double(hRls,"fundout_amt",&dTmp)) {
		hv_funds_out_amt= dTmp;
                ind_funds_out_amt = 0;
DEBUGLOG(("Add:funds_out_amt = [%f]\n",hv_funds_out_amt));
        }


/* from_ccy */
        if (GetField_CString(hRls,"from_ccy",&csTmp)) {
                hv_from_ccy.len = strlen(csTmp);
                memcpy(hv_from_ccy.arr,csTmp,hv_from_ccy.len);
                ind_from_ccy = 0;
DEBUGLOG(("Add:from_ccy = [%.*s][%d]\n",hv_from_ccy.len,hv_from_ccy.arr,hv_from_ccy.len));
        }


/* new_bal */
	if (GetField_Double(hRls,"new_bal", &dTmp)) {
		hv_new_bal= dTmp;
                ind_new_bal = 0;
DEBUGLOG(("Add:new_bal = [%f]\n",hv_new_bal));
	}

/* old_bal */
	if (GetField_Double(hRls,"old_bal", &dTmp)) {
		hv_old_bal= dTmp;
                ind_old_bal= 0;
DEBUGLOG(("Add:old_bal = [%f]\n",hv_old_bal));
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
			:hv_return_value := sp_funds_out_history_insert(
					:hv_funds_out_id:ind_funds_out_id,
					:hv_funds_out_date:ind_funds_out_date,
					:hv_from_ccy:ind_from_ccy,
					:hv_funds_out_ccy:ind_funds_out_ccy,
					:hv_funds_out_amt:ind_funds_out_amt,
					:hv_old_bal:ind_old_bal,
					:hv_new_bal:ind_new_bal,
					:hv_add_user:ind_add_user);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_funds_out_history_insert ( :hv\
_funds_out_id:ind_funds_out_id , :hv_funds_out_date:ind_funds_out_date , :hv_\
from_ccy:ind_from_ccy , :hv_funds_out_ccy:ind_funds_out_ccy , :hv_funds_out_a\
mt:ind_funds_out_amt , :hv_old_bal:ind_old_bal , :hv_new_bal:ind_new_bal , :h\
v_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_funds_out_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_funds_out_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_funds_out_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_funds_out_date;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_from_ccy;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_funds_out_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_funds_out_ccy;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_funds_out_amt;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_funds_out_amt;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_old_bal;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_old_bal;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_new_bal;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_new_bal;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[8] = (unsigned long )22;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("FundsOutHistory_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("FundsOutHistory_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("FundsOutHistory_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int GetFundsOutHistory(const hash_t *hRls, recordset_t* myRec)
{
        hash_t *myHash;
	int	iTmp;
        /* EXEC SQL WHENEVER SQLERROR GOTO gethistory_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_fundout_id;

                /* varchar         v_fundout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundout_ccy;

                /* varchar         v_from_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_from_ccy;

                /* varchar         v_fundout_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundout_date;

                double          v_fundout_amt;
                double          v_old_bal;
                double          v_new_bal;

                short           ind_old_bal= -1;
                short           ind_new_bal= -1;
                short           ind_fundout_ccy= -1;
                short           ind_from_ccy= -1;
                short           ind_fundout_date= -1;
                short           ind_fundout_amt= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


/* fundout_id*/
        if (GetField_Int(hRls,"fundout_id",&iTmp)) {
                hv_fundout_id= iTmp;
DEBUGLOG(("GetFundsOutHistory:fundout_id = [%d]\n",hv_fundout_id));
        }

        /* EXEC SQL DECLARE c_cursor_gethistory CURSOR FOR
                select  fo_funds_out_date,
                        fo_funds_out_ccy,
			fo_funds_out_amt,
			fo_from_ccy,
                        fo_old_bal,
                        fo_new_bal
                from    funds_out_history
                where   fo_funds_out_id=:hv_fundout_id; */ 


        /* EXEC SQL OPEN  c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )56;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_fundout_id;
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
        if (sqlca.sqlcode < 0) goto gethistory_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_gethistory
                INTO
                        :v_fundout_date:ind_fundout_date,
                        :v_fundout_ccy:ind_fundout_ccy,
                        :v_fundout_amt:ind_fundout_amt,
                        :v_from_ccy:ind_from_ccy,
                        :v_old_bal:ind_old_bal,
                        :v_new_bal:ind_new_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )75;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundout_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundout_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_fundout_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_fundout_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_fundout_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_fundout_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_from_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_from_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_old_bal;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_old_bal;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_new_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_new_bal;
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
                if (sqlca.sqlcode < 0) goto gethistory_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*fundout_date*/
                if(ind_fundout_date>=0){
                        PutField_CString(myHash,"fundout_date",(const char*)v_fundout_date.arr);
DEBUGLOG(("GetFundsOutHistory fundout_date= [%s]\n",v_fundout_date.arr));
                }

/*fundout_ccy*/
                if(ind_fundout_ccy>=0){
                        PutField_CString(myHash,"fundout_ccy",(const char*)v_fundout_ccy.arr);
DEBUGLOG(("GetFundsOutHistory fundout_ccy = [%s]\n",v_fundout_ccy.arr));
                }

/*fundout_amt*/
                if(ind_fundout_amt>=0){
                        PutField_Double(myHash,"fundout_amt",v_fundout_amt);
DEBUGLOG(("GetFundsOutHistory fundout_amt = [%lf]\n",v_fundout_amt));
                }

/*from_ccy*/
                if(ind_from_ccy>=0){
                        PutField_CString(myHash,"from_ccy",(const char*)v_from_ccy.arr);
DEBUGLOG(("GetFundsOutHistory from_ccy = [%s]\n",v_from_ccy.arr));
                }

/*old_bal*/
                if(ind_old_bal>=0){
                        PutField_Double(myHash,"old_bal",v_old_bal);
DEBUGLOG(("GetFundsOutHistory old_bal= [%lf]\n",v_old_bal));
                }
/*new_bal*/
                if(ind_new_bal>=0){
                        PutField_Double(myHash,"new_bal",v_new_bal);
DEBUGLOG(("GetFundsOutHistory new_bal= [%lf]\n",v_new_bal));
                }


                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )114;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gethistory_error;
}



DEBUGLOG(("GetFundsOutHistory Normal Exit\n"));
        return  PD_OK;

gethistory_error:
DEBUGLOG(("gethistory_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("GetFundsOutHistory: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gethistory; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )129;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}
