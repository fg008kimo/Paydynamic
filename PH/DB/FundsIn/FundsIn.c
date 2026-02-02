
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
           char  filnam[11];
};
static struct sqlcxp sqlfpn =
{
    10,
    "FundsIn.pc"
};


static unsigned int sqlctx = 76795;


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

 static char *sq0003 = 
"select f_fundin_date , f_fundin_ccy , f_fundin_amount , f_bank_ccy , f_bank\
_amount from funds_in where f_id = :b0            ";

 static char *sq0004 = 
"select f_fundin_date , f_fundin_ccy , f_fundin_amount , f_bank_ccy , f_bank\
_amount from funds_in where f_id = :b0 and f_approval_user is NOT NULL and f_\
calculation_user is NULL            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,0,0,17,86,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,21,87,0,0,0,0,0,1,0,
39,0,0,2,280,0,6,183,0,0,8,8,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,
0,0,1,9,0,0,2,3,0,0,
86,0,0,1,0,0,17,263,0,0,1,1,0,1,0,1,9,0,0,
105,0,0,1,0,0,21,264,0,0,0,0,0,1,0,
120,0,0,3,125,0,9,314,0,2049,1,1,0,1,0,1,9,0,0,
139,0,0,3,0,0,13,316,0,0,5,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,
174,0,0,3,0,0,15,369,0,0,0,0,0,1,0,
189,0,0,3,0,0,15,379,0,0,0,0,0,1,0,
204,0,0,4,188,0,9,423,0,2049,1,1,0,1,0,1,3,0,0,
223,0,0,4,0,0,13,425,0,0,5,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,
258,0,0,4,0,0,15,475,0,0,0,0,0,1,0,
273,0,0,4,0,0,15,485,0,0,0,0,0,1,0,
};



/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/12              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "FundsIn.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void FundsIn(char    cdebug)
{
        cDebug = cdebug;
}



int UpdateCal(const hash_t *hRls)
{
//	char*	csFundInDate= strdup("");
//	char*	csFundInCcy= strdup("");
//	char*	csBankCcy= strdup("");
	char*	csId; 
	char*	csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO update_cal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        //GetField_CString(hRls,"fundin_date",&csFundInDate);
//DEBUGLOG(("Update:fundin_date = [%s]\n",csFundInDate));
        
//        GetField_CString(hRls,"fundin_ccy",&csFundInCcy);
//DEBUGLOG(("Update:fundin_ccy = [%s]\n",csFundInCcy));
        
//        GetField_CString(hRls,"bank_ccy",&csBankCcy);
//DEBUGLOG(("Update:bank_ccy = [%s]\n",csBankCcy));
        
	GetField_CString(hRls,"fundsin_id",&csId);
DEBUGLOG(("Update:fundsin_id = [%s]\n",csId));

        strcpy((char*)hv_dynstmt.arr,"update funds_in set f_calculation_timestamp=sysdate, f_update_timestamp=sysdate, ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
                


        if(GetField_CString(hRls,"cal_user",&csTmp)){
DEBUGLOG(("Update: calculation user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, "f_calculation_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char*)hv_dynstmt.arr, " WHERE f_id= '");
        strcat((char*)hv_dynstmt.arr, csId);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
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
        if (sqlca.sqlcode < 0) goto update_cal_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_cal_error;
}



DEBUGLOG(("UpdateCal Normal Exit\n"));
        return PD_OK;

update_cal_error:
DEBUGLOG(("update_cal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int Add(hash_t *hRls)
{
        char            *csTmp;
        double          dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_funds_in_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_funds_in_date;

        /* varchar         hv_funds_in_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_funds_in_ccy;

        double          hv_funds_in_amt;
        /* varchar         hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;

        double          hv_bank_amt;
        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	int		v_funds_in_id;


        short           ind_funds_in_date = -1;
        short           ind_funds_in_ccy = -1;
        short           ind_funds_in_amt = -1;
        short           ind_bank_ccy = -1;
        short           ind_bank_amt = -1;
        short           ind_add_user = -1;
        short           ind_funds_in_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


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
                        :hv_return_value := sp_fundsin_insert(
                                        :hv_funds_in_date:ind_funds_in_date,
                                        :hv_funds_in_ccy:ind_funds_in_ccy,
                                        :hv_funds_in_amt:ind_funds_in_amt,
                                        :hv_bank_ccy:ind_bank_ccy,
                                        :hv_bank_amt:ind_bank_amt,
                                        :hv_add_user:ind_add_user,
					:v_funds_in_id:ind_funds_in_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_fundsin_insert ( :hv_fu\
nds_in_date:ind_funds_in_date , :hv_funds_in_ccy:ind_funds_in_ccy , :hv_funds\
_in_amt:ind_funds_in_amt , :hv_bank_ccy:ind_bank_ccy , :hv_bank_amt:ind_bank_\
amt , :hv_add_user:ind_add_user , :v_funds_in_id:ind_funds_in_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )39;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_funds_in_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_funds_in_date;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_funds_in_ccy;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_funds_in_ccy;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_funds_in_amt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_funds_in_amt;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_ccy;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_bank_ccy;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_amt;
        sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_bank_amt;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[6] = (unsigned long )22;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_add_user;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&v_funds_in_id;
        sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_funds_in_id;
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
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		if(ind_funds_in_id>=0){
			PutField_Int(hRls,"fundsin_id",v_funds_in_id);
		}
                return PD_OK;
        }
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("FundsInHistory_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("FundsInHistory_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("FundsInHistory_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int UpdateApprove(const hash_t *hRls)
{
	char*	csTmp;
	char*	csId; 

	/* EXEC SQL WHENEVER SQLERROR GOTO update_approve_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateApprove: Begin\n"));
        strcpy((char*)hv_dynstmt.arr,"update funds_in set f_approval_timestamp=sysdate, f_update_timestamp=sysdate, ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
                
	GetField_CString(hRls,"fundsin_id",&csId);
DEBUGLOG(("Update:fundsin_id = [%s]\n",csId));

        if(GetField_CString(hRls,"approve_user",&csTmp)){
DEBUGLOG(("UpdateApprove: approve user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, "f_approval_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char*)hv_dynstmt.arr, " WHERE f_id= '");
        strcat((char*)hv_dynstmt.arr, csId);
        strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("UpdateApprove:SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )86;
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
        if (sqlca.sqlcode < 0) goto update_approve_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )105;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_approve_error;
}




DEBUGLOG(("UpdateApprove Normal Exit\n"));
        return PD_OK;

update_approve_error:
DEBUGLOG(("update_approve_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}


int GetFundsInDetail(const char	*csId, recordset_t* myRec)
{
        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getfundsin_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_id;


                /* varchar         v_fundin_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundin_ccy;

                /* varchar         v_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

                /* varchar         v_fundin_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundin_date;

                double          v_fundin_amt;
                double          v_bank_amt;

                short           ind_fundin_ccy= -1;
                short           ind_bank_ccy= -1;
                short           ind_fundin_amt= -1;
                short           ind_bank_amt= -1;
                short           ind_fundin_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_id.len = strlen(csId);
        memcpy(hv_id.arr,csId,hv_id.len);
DEBUGLOG(("GetFundsInDetail fundin_id = [%.*s]\n",hv_id.len,hv_id.arr));

        /* EXEC SQL DECLARE c_cursor_getfundsin CURSOR FOR
                select  f_fundin_date,
                        f_fundin_ccy,
                        f_fundin_amount,
                        f_bank_ccy,
                        f_bank_amount
                from    funds_in
                where   f_id =:hv_id; */ 


        /* EXEC SQL OPEN  c_cursor_getfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )120;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
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
        if (sqlca.sqlcode < 0) goto getfundsin_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getfundsin
                INTO
                        :v_fundin_date:ind_fundin_date,
                        :v_fundin_ccy:ind_fundin_ccy,
                        :v_fundin_amt:ind_fundin_amt,
                        :v_bank_ccy:ind_bank_ccy,
                        :v_bank_amt:ind_bank_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )139;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_fundin_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_fundin_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_fundin_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_fundin_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_amt;
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
                if (sqlca.sqlcode < 0) goto getfundsin_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*fundin_ccy*/
                if(ind_fundin_ccy>=0){
                        v_fundin_ccy.arr[v_fundin_ccy.len]='\0';
                        PutField_CString(myHash,"fundin_ccy",(const char*)v_fundin_ccy.arr);
DEBUGLOG(("GetFundsInDetail fundin_ccy=[%s]\n",v_fundin_ccy.arr));
                }

/*bank_ccy*/
                if(ind_bank_ccy>=0){
                        v_bank_ccy.arr[v_bank_ccy.len]='\0';
                        PutField_CString(myHash,"bank_ccy",(const char*)v_bank_ccy.arr);
DEBUGLOG(("GetFundsInDetail bank_ccy = [%s]\n",v_bank_ccy.arr));
                }

/*fundin_amt*/
                if(ind_fundin_amt>=0){
                        PutField_Double(myHash,"fundin_amt",v_fundin_amt);
DEBUGLOG(("GetFundsInDetail fundin_amt= [%lf]\n",v_fundin_amt));
                }

/*bank_amt*/
                if(ind_bank_amt>=0){
                        PutField_Double(myHash,"bank_amt",v_bank_amt);
DEBUGLOG(("GetFundsInDetail bank_amt= [%lf]\n",v_bank_amt));
                }


/*fundin_date*/
                if(ind_fundin_date>=0){
                        v_fundin_date.arr[v_fundin_date.len]='\0';
                        PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
DEBUGLOG(("GetFundsInDetail fundin_date = [%s]\n",v_fundin_date.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )174;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getfundsin_error;
}



DEBUGLOG(("GetFundsInDetail Normal Exit\n"));
        return  PD_OK;

getfundsin_error:
DEBUGLOG(("getfundsin_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MerchantUploadFileHeader_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )189;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int GetApprovedFundsInById(const int iId, hash_t* myHash)
{
	int iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO getappfundsin_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                int		hv_id;

                /* varchar         v_fundin_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fundin_ccy;

                /* varchar         v_bank_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bank_ccy;

                /* varchar         v_fundin_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_fundin_date;

                double          v_fundin_amt;
                double          v_bank_amt;

                short           ind_fundin_ccy= -1;
                short           ind_bank_ccy= -1;
                short           ind_fundin_amt= -1;
                short           ind_bank_amt= -1;
                short           ind_fundin_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_id = iId;
DEBUGLOG(("GetApprovedFundsInById fundin_id = [%d]\n",hv_id));

        /* EXEC SQL DECLARE c_cursor_getappfundsin CURSOR FOR
                select  f_fundin_date,
                        f_fundin_ccy,
                        f_fundin_amount,
                        f_bank_ccy,
                        f_bank_amount
                from    funds_in
                where   f_id =:hv_id
		and	f_approval_user is NOT NULL
		and	f_calculation_user is NULL; */ 


        /* EXEC SQL OPEN  c_cursor_getappfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )204;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_id;
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
        if (sqlca.sqlcode < 0) goto getappfundsin_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getappfundsin
                INTO
                        :v_fundin_date:ind_fundin_date,
                        :v_fundin_ccy:ind_fundin_ccy,
                        :v_fundin_amt:ind_fundin_amt,
                        :v_bank_ccy:ind_bank_ccy,
                        :v_bank_amt:ind_bank_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )223;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_fundin_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_fundin_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_fundin_ccy;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_fundin_ccy;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_fundin_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_fundin_amt;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_bank_amt;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_bank_amt;
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
                if (sqlca.sqlcode < 0) goto getappfundsin_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/*fundin_ccy*/
                if(ind_fundin_ccy>=0){
                        v_fundin_ccy.arr[v_fundin_ccy.len]='\0';
                        PutField_CString(myHash,"fundin_ccy",(const char*)v_fundin_ccy.arr);
DEBUGLOG(("GetApprovedFundsInById fundin_ccy=[%s]\n",v_fundin_ccy.arr));
                }

/*bank_ccy*/
                if(ind_bank_ccy>=0){
                        v_bank_ccy.arr[v_bank_ccy.len]='\0';
                        PutField_CString(myHash,"bank_ccy",(const char*)v_bank_ccy.arr);
DEBUGLOG(("GetApprovedFundsInById bank_ccy = [%s]\n",v_bank_ccy.arr));
                }

/*fundin_amt*/
                if(ind_fundin_amt>=0){
                        PutField_Double(myHash,"fundin_amt",v_fundin_amt);
DEBUGLOG(("GetApprovedFundsInById fundin_amt= [%lf]\n",v_fundin_amt));
                }

/*bank_amt*/
                if(ind_bank_amt>=0){
                        PutField_Double(myHash,"bank_amt",v_bank_amt);
DEBUGLOG(("GetApprovedFundsInById bank_amt= [%lf]\n",v_bank_amt));
                }


/*fundin_date*/
                if(ind_fundin_date>=0){
                        v_fundin_date.arr[v_fundin_date.len]='\0';
                        PutField_CString(myHash,"fundin_date",(const char*)v_fundin_date.arr);
DEBUGLOG(("GetApprovedFundsInById fundin_date = [%s]\n",v_fundin_date.arr));
                }

		iRet = PD_FOUND;

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getappfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )258;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getappfundsin_error;
}



DEBUGLOG(("GetApprovedFundsInById Normal Exit\n"));
        return  iRet;

getappfundsin_error:
DEBUGLOG(("getappfundsin_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("FundsIn: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getappfundsin; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )273;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}
