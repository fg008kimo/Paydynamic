
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "TxnExDetail.pc"
};


static unsigned int sqlctx = 1359915;


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
"SELECT tx_ref_ex_rate_type , tx_ref_ex_rate , tx_min_ref_tolerance , tx_max\
_ref_tolerance , tx_min_ref_ex_rate , tx_max_ref_ex_rate FROM txn_ex_detail W\
HERE tx_txn_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,365,0,6,122,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,9,0,0,
56,0,0,2,184,0,9,200,0,2049,1,1,0,1,0,1,9,0,0,
75,0,0,2,0,0,13,202,0,0,6,0,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,
114,0,0,2,0,0,15,242,0,0,0,0,0,1,0,
129,0,0,2,0,0,15,250,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2017. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2017/04/27              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnExDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;
void TxnExDetail(char cdebug)
{
	cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char *csTmp;
	double dTmp = 0.0;

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	short		hv_return_value;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

	/* varchar		hv_ref_ex_rate_type[PD_EX_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_ref_ex_rate_type;

	double		hv_ref_ex_rate;
	double		hv_min_ref_tolerance;
	double		hv_max_ref_tolerance;
	double		hv_min_ref_ex_rate;
	double		hv_max_ref_ex_rate;
	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


	short		ind_txn_id = -1;
	short		ind_ref_ex_rate_type = -1;
	short		ind_ref_ex_rate = -1;
	short		ind_min_ref_tolerance = -1;
	short		ind_max_ref_tolerance = -1;
	short		ind_min_ref_ex_rate = -1;
	short		ind_max_ref_ex_rate = -1;
	short		ind_add_user = -1;

	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("Add: Begin\n"));

/* txn_seq */
	if (GetField_CString(hRls, "txn_seq", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%.*s][%d]\n", hv_txn_id.len, hv_txn_id.arr, hv_txn_id.len));
	}

/* ref_ex_rate_type */
	if (GetField_CString(hRls, "ref_ex_rate_type", &csTmp)) {
		hv_ref_ex_rate_type.len = strlen(csTmp);
		memcpy(hv_ref_ex_rate_type.arr, csTmp, hv_ref_ex_rate_type.len);
		ind_ref_ex_rate_type = 0;
DEBUGLOG(("Add: ref_ex_rate_type = [%.*s][%d]\n", hv_ref_ex_rate_type.len, hv_ref_ex_rate_type.arr, hv_ref_ex_rate_type.len));
	}

/* ref_ex_rate */
	if (GetField_Double(hRls, "ref_ex_rate", &dTmp)) {
		hv_ref_ex_rate = dTmp;
		ind_ref_ex_rate = 0;
DEBUGLOG(("Add: ref_ex_rate = [%f]\n", hv_ref_ex_rate));
	}

/* min_ref_tolerance */
	if (GetField_Double(hRls, "min_ref_tolerance", &dTmp)) {
		hv_min_ref_tolerance = dTmp;
		ind_min_ref_tolerance = 0;
DEBUGLOG(("Add: min_ref_tolerance = [%f]\n", hv_min_ref_tolerance));
	}

/* max_ref_tolerance */
	if (GetField_Double(hRls, "max_ref_tolerance", &dTmp)) {
		hv_max_ref_tolerance = dTmp;
		ind_max_ref_tolerance = 0;
DEBUGLOG(("Add: max_ref_tolerance = [%f]\n", hv_max_ref_tolerance));
	}

/* min_ref_ex_rate */
	if (GetField_Double(hRls, "min_ref_ex_rate", &dTmp)) {
		hv_min_ref_ex_rate = dTmp;
		ind_min_ref_ex_rate = 0;
DEBUGLOG(("Add: min_ref_ex_rate = [%f]\n", hv_min_ref_ex_rate));
	}

/* max_ref_ex_rate */
	if (GetField_Double(hRls, "max_ref_ex_rate", &dTmp)) {
		hv_max_ref_ex_rate = dTmp;
		ind_max_ref_ex_rate = 0;
DEBUGLOG(("Add: max_ref_ex_rate = [%f]\n", hv_max_ref_ex_rate));
	}

/* add user */
	if (GetField_CString(hRls, "add_user", &csTmp)) {
		hv_add_user.len = strlen(csTmp);
		memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
		ind_add_user = 0;
DEBUGLOG(("Add: add_user = [%.*s][%d]\n", hv_add_user.len, hv_add_user.arr, hv_add_user.len));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_txn_ex_detail_insert(
                                        :hv_txn_id:ind_txn_id,
					:hv_ref_ex_rate_type:ind_ref_ex_rate_type,
					:hv_ref_ex_rate:ind_ref_ex_rate,
					:hv_min_ref_tolerance:ind_min_ref_tolerance,
					:hv_max_ref_tolerance:ind_max_ref_tolerance,
					:hv_min_ref_ex_rate:ind_min_ref_ex_rate,
					:hv_max_ref_ex_rate:ind_max_ref_ex_rate,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_ex_detail_insert ( :hv_txn\
_id:ind_txn_id , :hv_ref_ex_rate_type:ind_ref_ex_rate_type , :hv_ref_ex_rate:\
ind_ref_ex_rate , :hv_min_ref_tolerance:ind_min_ref_tolerance , :hv_max_ref_t\
olerance:ind_max_ref_tolerance , :hv_min_ref_ex_rate:ind_min_ref_ex_rate , :h\
v_max_ref_ex_rate:ind_max_ref_ex_rate , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_ref_ex_rate_type;
 sqlstm.sqhstl[2] = (unsigned long )8;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_ref_ex_rate_type;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ref_ex_rate;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_ref_ex_rate;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_min_ref_tolerance;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_min_ref_tolerance;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_max_ref_tolerance;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_max_ref_tolerance;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_min_ref_ex_rate;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_min_ref_ex_rate;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_max_ref_ex_rate;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_max_ref_ex_rate;
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

		

DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnExDetail_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnExDetail_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnExDetail_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}


int Get(const char *csTxnId, hash_t *hRec) {
	/* EXEC SQL WHENEVER SQLERROR GOTO Get_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_id;


		/* varchar v_ref_ex_rate_type[PD_EX_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_ref_ex_rate_type;

		double	v_ref_ex_rate;
		double	v_min_ref_tolerance;
		double	v_max_ref_tolerance;
		double	v_min_ref_ex_rate;
		double	v_max_ref_ex_rate;

		short	ind_ref_ex_rate_type = -1;
		short	ind_ref_ex_rate = -1;
		short	ind_min_ref_tolerance = -1;
		short	ind_max_ref_tolerance = -1;
		short	ind_min_ref_ex_rate = -1;
		short	ind_max_ref_ex_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen((const char*)csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("Get: txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL DECLARE c_cursor_get CURSOR FOR
		SELECT	tx_ref_ex_rate_type,
			tx_ref_ex_rate,
			tx_min_ref_tolerance,
			tx_max_ref_tolerance,
			tx_min_ref_ex_rate,
			tx_max_ref_ex_rate
		FROM	txn_ex_detail
		WHERE	tx_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_get; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
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
 if (sqlca.sqlcode < 0) goto Get_error;
}



	/* EXEC SQL FETCH c_cursor_get
	INTO
		:v_ref_ex_rate_type:ind_ref_ex_rate_type,
		:v_ref_ex_rate:ind_ref_ex_rate,
		:v_min_ref_tolerance:ind_min_ref_tolerance,
		:v_max_ref_tolerance:ind_max_ref_tolerance,
		:v_min_ref_ex_rate:ind_min_ref_ex_rate,
		:v_max_ref_ex_rate:ind_max_ref_ex_rate; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&v_ref_ex_rate_type;
 sqlstm.sqhstl[0] = (unsigned long )9;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_ref_ex_rate_type;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_ref_ex_rate;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_ref_ex_rate;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_min_ref_tolerance;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_min_ref_tolerance;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_max_ref_tolerance;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_max_ref_tolerance;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&v_min_ref_ex_rate;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_min_ref_ex_rate;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&v_max_ref_ex_rate;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_max_ref_ex_rate;
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
 if (sqlca.sqlcode < 0) goto Get_error;
}



	if (ind_ref_ex_rate_type >= 0) {
		v_ref_ex_rate_type.arr[v_ref_ex_rate_type.len] = '\0';
		PutField_CString(hRec, "ref_ex_rate_type", (const char*)v_ref_ex_rate_type.arr);
DEBUGLOG(("Get: ref_ex_rate_type = [%s]\n", v_ref_ex_rate_type.arr));
	}

	if (ind_ref_ex_rate >= 0) {
		PutField_Double(hRec, "ref_ex_rate", v_ref_ex_rate);
DEBUGLOG(("Get: ref_ex_rate = [%f]\n", v_ref_ex_rate));
	}

	if (ind_min_ref_tolerance >= 0) {
		PutField_Double(hRec, "min_ref_tolerance", v_min_ref_tolerance);
DEBUGLOG(("Get: min_ref_tolerance = [%f]\n", v_min_ref_tolerance));
	}

	if (ind_max_ref_tolerance >= 0) {
		PutField_Double(hRec, "max_ref_tolerance", v_max_ref_tolerance);
DEBUGLOG(("Get: max_ref_tolerance = [%f]\n", v_max_ref_tolerance));
	}

	if (ind_min_ref_ex_rate >= 0) {
		PutField_Double(hRec, "min_ref_ex_rate", v_min_ref_ex_rate);
DEBUGLOG(("Get: min_ref_ex_rate = [%f]\n", v_min_ref_ex_rate));
	}

	if (ind_max_ref_ex_rate >= 0) {
		PutField_Double(hRec, "max_ref_ex_rate", v_max_ref_ex_rate);
DEBUGLOG(("Get: max_ref_ex_rate [%f]\n", v_max_ref_ex_rate));
	}

	/* EXEC SQL CLOSE c_cursor_get; */ 

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
 if (sqlca.sqlcode < 0) goto Get_error;
}



	return PD_OK;

Get_error:
DEBUGLOG(("Get_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_get; */ 

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

