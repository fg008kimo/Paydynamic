
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "MiDefArBal.pc"
};


static unsigned int sqlctx = 605515;


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
   unsigned char  *sqhstv[4];
   unsigned long  sqhstl[4];
            int   sqhsts[4];
            short *sqindv[4];
            int   sqinds[4];
   unsigned long  sqharm[4];
   unsigned long  *sqharc[4];
   unsigned short  sqadto[4];
   unsigned short  sqtdso[4];
} sqlstm = {12,4};

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

 static char *sq0001 = 
"SELECT ad_desc , ad_txn_code_map , ad_element_code , ad_amt_type FROM mi_de\
f_ar_bal WHERE ad_code = :b0            ";

 static char *sq0002 = 
"SELECT ad_code , ad_desc , ad_element_code , ad_amt_type FROM mi_def_ar_bal\
 WHERE ad_txn_code_map = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,115,0,9,68,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,71,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
55,0,0,1,0,0,15,112,0,0,0,0,0,1,0,
70,0,0,1,0,0,15,126,0,0,0,0,0,1,0,
85,0,0,2,115,0,9,168,0,2049,1,1,0,1,0,1,9,0,0,
104,0,0,2,0,0,13,171,0,0,4,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
135,0,0,2,0,0,15,212,0,0,0,0,0,1,0,
150,0,0,2,0,0,15,226,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/11/03              Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MiDefArBal.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MiDefArBal(char    cdebug)
{
        cDebug = cdebug;
}


int GetArBalParameter(const char* csCode, hash_t* hRec)
{
	int iRet = PD_ERR;

        int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmidefarbal_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_code[PD_MI_AR_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_code;


                /* varchar         v_desc[PD_MI_AR_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

                /* varchar         v_txn_code_map[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code_map;

                /* varchar         v_element_code[PD_TXN_ELEMENT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_element_code;

                /* varchar         v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;


                short           ind_desc = -1;
                short           ind_txn_code_map = -1;
                short           ind_element_code = -1;
                short           ind_amt_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// code
	hv_code.len = strlen(csCode);
        memcpy(hv_code.arr,csCode,hv_code.len);
DEBUGLOG(("GetArBalParameter code = [%.*s]\n",hv_code.len,hv_code.arr));

        /* EXEC SQL DECLARE c_cursor_getmidefarbal CURSOR FOR
                SELECT  ad_desc,
                        ad_txn_code_map,
                        ad_element_code,
                        ad_amt_type
                FROM    mi_def_ar_bal
                WHERE   ad_code = :hv_code; */ 


        /* EXEC SQL OPEN c_cursor_getmidefarbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0001;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )5;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_code;
        sqlstm.sqhstl[0] = (unsigned long )12;
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
        if (sqlca.sqlcode < 0) goto getmidefarbal_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getmidefarbal
                INTO    :v_desc:ind_desc,
                        :v_txn_code_map:ind_txn_code_map,
                        :v_element_code:ind_element_code,
                        :v_amt_type:ind_amt_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )24;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_desc;
                sqlstm.sqhstl[0] = (unsigned long )53;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_desc;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code_map;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_code_map;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_element_code;
                sqlstm.sqhstl[2] = (unsigned long )7;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_element_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_amt_type;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_amt_type;
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
                if (sqlca.sqlcode < 0) goto getmidefarbal_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

/* desc */
		if (ind_desc >= 0) {
                        v_desc.arr[v_desc.len] = '\0';
                        PutField_CString(hRec, "desc", (const char*)v_desc.arr);
DEBUGLOG(("GetArBalParameter desc = [%s]\n", (const char*)v_desc.arr));
                }		

/* txn_code_map */
		if (ind_txn_code_map >= 0) {
                        v_txn_code_map.arr[v_txn_code_map.len] = '\0';
                        PutField_CString(hRec, "txn_code_map", (const char*)v_txn_code_map.arr);
DEBUGLOG(("GetArBalParameter txn_code_map = [%s]\n", (const char*)v_txn_code_map.arr));
                }

/* element_code */
		if (ind_element_code >= 0) {
                        v_element_code.arr[v_element_code.len] = '\0';
                        PutField_CString(hRec, "element_code", (const char*)v_element_code.arr);
DEBUGLOG(("GetArBalParameter element_code = [%s]\n", (const char*)v_element_code.arr));
                }

/* amt_type */
		if (ind_amt_type >= 0) {
                        v_amt_type.arr[v_amt_type.len] = '\0';
                        PutField_CString(hRec, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetArBalParameter amt_type = [%s]\n", (const char*)v_amt_type.arr));
                }
	}

        /* EXEC SQL CLOSE c_cursor_getmidefarbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )55;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmidefarbal_error;
}



        if (iCnt > 0 ) {
                iRet = PD_OK;
        }

DEBUGLOG(("GetArBalParameter Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getmidefarbal_error:
DEBUGLOG(("getmidefarbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiDefArBal getmidefarbal_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getmidefarbal; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )70;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmidefarbal_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetArBalParameterByTxnCode(const char* csTxnCode, hash_t* hRec)
{
	int iRet = PD_ERR;

        int iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmidefarbalbytc_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_code;


                /* varchar         v_code[PD_MI_AR_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_code;

                /* varchar         v_desc[PD_MI_AR_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_desc;

                /* varchar         v_element_code[PD_TXN_ELEMENT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_element_code;

                /* varchar         v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;


		short		ind_code = -1;
                short           ind_desc = -1;
                short           ind_element_code = -1;
                short           ind_amt_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// code
	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr,csTxnCode,hv_txn_code.len);
DEBUGLOG(("GetArBalParameterByTxnCode txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL DECLARE c_cursor_getmidefarbalbytc CURSOR FOR
                SELECT  ad_code,
			ad_desc,
                        ad_element_code,
                        ad_amt_type
                FROM    mi_def_ar_bal
                WHERE   ad_txn_code_map = :hv_txn_code; */ 


        /* EXEC SQL OPEN c_cursor_getmidefarbalbytc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0002;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )85;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[0] = (unsigned long )6;
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
        if (sqlca.sqlcode < 0) goto getmidefarbalbytc_error;
}



	for (;;) {
                /* EXEC SQL FETCH c_cursor_getmidefarbalbytc
                INTO    :v_code:ind_code,
			:v_desc:ind_desc,
                        :v_element_code:ind_element_code,
                        :v_amt_type:ind_amt_type; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )104;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_code;
                sqlstm.sqhstl[0] = (unsigned long )12;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_desc;
                sqlstm.sqhstl[1] = (unsigned long )53;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_desc;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_element_code;
                sqlstm.sqhstl[2] = (unsigned long )7;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_element_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_amt_type;
                sqlstm.sqhstl[3] = (unsigned long )5;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_amt_type;
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
                if (sqlca.sqlcode < 0) goto getmidefarbalbytc_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

/* code */
                if (ind_code >= 0) {
                        v_code.arr[v_code.len] = '\0';
                        PutField_CString(hRec, "code", (const char*)v_code.arr);
DEBUGLOG(("GetArBalParameterByTxnCode code = [%s]\n", (const char*)v_code.arr));
                }

/* desc */
		if (ind_desc >= 0) {
                        v_desc.arr[v_desc.len] = '\0';
                        PutField_CString(hRec, "desc", (const char*)v_desc.arr);
DEBUGLOG(("GetArBalParameterByTxnCode desc = [%s]\n", (const char*)v_desc.arr));
                }		

/* element_code */
		if (ind_element_code >= 0) {
                        v_element_code.arr[v_element_code.len] = '\0';
                        PutField_CString(hRec, "element_code", (const char*)v_element_code.arr);
DEBUGLOG(("GetArBalParameterByTxnCode element_code = [%s]\n", (const char*)v_element_code.arr));
                }

/* amt_type */
		if (ind_amt_type >= 0) {
                        v_amt_type.arr[v_amt_type.len] = '\0';
                        PutField_CString(hRec, "amt_type", (const char*)v_amt_type.arr);
DEBUGLOG(("GetArBalParameterByTxnCode amt_type = [%s]\n", (const char*)v_amt_type.arr));
                }
	}

        /* EXEC SQL CLOSE c_cursor_getmidefarbalbytc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )135;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmidefarbalbytc_error;
}



        if (iCnt > 0 ) {
                iRet = PD_OK;
        }

DEBUGLOG(("GetArBalParameterByTxnCode Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

getmidefarbalbytc_error:
DEBUGLOG(("getmidefarbalbytc_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiDefArBal getmidefarbalbytc_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL CLOSE c_cursor_getmidefarbalbytc; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )150;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmidefarbalbytc_error;
}


        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

