
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
    "OLTcBalTrfMap.pc"
};


static unsigned int sqlctx = 5078091;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
"select btm_txn_code , tc_ofl_allow_fe_init from ol_tc_bal_trf_map , ol_tc_b\
al_trf_cat_map , txn_code where btm_bal_trf_type = :b0:b1 and btm_fr_acct_typ\
e = :b2:b3 and btm_to_acct_type = :b4:b5 and btm_to_baid_cat_id = btcm_map_id\
 and btcm_baid_category = :b6:b7 and btm_txn_code_type = :b8:b9 and btm_txn_c\
ode = tc_code            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,331,0,9,127,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,1,0,0,13,129,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
63,0,0,1,0,0,15,154,0,0,0,0,0,1,0,
78,0,0,1,0,0,15,170,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/01/03              Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTcBalTrfMap.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void OLTcBalTrfMap(char    cdebug)
{
        cDebug = cdebug;
}

int	GetBalTransferTxnCode(hash_t *hRls)
{
	int	iRet = PD_NOT_FOUND;

	char	*csTmp;
	int	iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getbaltrftxncode_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_bal_trf_type[PD_BAL_TRF_TYPE_PLATF_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bal_trf_type;

		/* varchar	hv_from_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_acct_type;

		/* varchar	hv_to_acct_type[PD_ACCT_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_acct_type;

		/* varchar	hv_to_baid_category[PD_BAID_CATEGORY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_to_baid_category;

		/* varchar	hv_bal_trf_txn_code_type[PD_BAL_TRF_TC_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_bal_trf_txn_code_type;


		short	ind_bal_trf_type = -1;
		short	ind_from_acct_type = -1;
		short	ind_to_acct_type = -1;
		short	ind_to_baid_category = -1;
		short	ind_bal_trf_txn_code_type = -1;


		/* varchar	v_map_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_map_txn_code;

		int	v_allow_fe_init;

		short	ind_map_txn_code = -1;
		short	ind_allow_fe_init = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls, "bal_trf_type", &csTmp)) {
		hv_bal_trf_type.len = strlen(csTmp);
		strncpy((char *)hv_bal_trf_type.arr, csTmp, hv_bal_trf_type.len);
		ind_bal_trf_type = 0;
DEBUGLOG(("GetBalTransferTxnCode: bal_trf_type = [%.*s]\n", hv_bal_trf_type.len, hv_bal_trf_type.arr));
	} else {
DEBUGLOG(("GetBalTransferTxnCode: bal_trf_type NOT FOUND!!!\n"));
		return PD_ERR;
        }	

	if(GetField_CString(hRls, "from_acct_type", &csTmp)) {
		hv_from_acct_type.len = strlen(csTmp);
		strncpy((char *)hv_from_acct_type.arr, csTmp, hv_from_acct_type.len);
		ind_from_acct_type = 0;
DEBUGLOG(("GetBalTransferTxnCode: from_acct_type = [%.*s]\n", hv_from_acct_type.len, hv_from_acct_type.arr));
	} else {
DEBUGLOG(("GetBalTransferTxnCode: from_acct_type NOT FOUND!!!\n"));
		return PD_ERR;
        }	

	if(GetField_CString(hRls, "to_acct_type", &csTmp)) {
		hv_to_acct_type.len = strlen(csTmp);
		strncpy((char *)hv_to_acct_type.arr, csTmp, hv_to_acct_type.len);
		ind_to_acct_type = 0;
DEBUGLOG(("GetBalTransferTxnCode: to_acct_type = [%.*s]\n", hv_to_acct_type.len, hv_to_acct_type.arr));
	} else {
DEBUGLOG(("GetBalTransferTxnCode: to_acct_type NOT FOUND!!!\n"));
		return PD_ERR;
        }	

	if(GetField_CString(hRls, "to_baid_category", &csTmp)) {
		hv_to_baid_category.len = strlen(csTmp);
		strncpy((char *)hv_to_baid_category.arr, csTmp, hv_to_baid_category.len);
		ind_to_baid_category = 0;
DEBUGLOG(("GetBalTransferTxnCode: to_baid_category = [%.*s]\n", hv_to_baid_category.len, hv_to_baid_category.arr));
	} else {
DEBUGLOG(("GetBalTransferTxnCode: to_baid_category NOT FOUND!!!\n"));
		return PD_ERR;
        }	

	if(GetField_CString(hRls, "bal_trf_txn_code_type", &csTmp)) {
		hv_bal_trf_txn_code_type.len = strlen(csTmp);
		strncpy((char *)hv_bal_trf_txn_code_type.arr, csTmp, hv_bal_trf_txn_code_type.len);
		ind_bal_trf_txn_code_type = 0;
DEBUGLOG(("GetBalTransferTxnCode: bal_trf_txn_code_type = [%.*s]\n", hv_bal_trf_txn_code_type.len, hv_bal_trf_txn_code_type.arr));
	} else {
DEBUGLOG(("GetBalTransferTxnCode: bal_trf_txn_code_type NOT FOUND!!!\n"));
		return PD_ERR;
        }	


	/* EXEC SQL DECLARE c_cursor_getbaltrftxncode CURSOR FOR
		select	btm_txn_code, 
			tc_ofl_allow_fe_init
		from ol_tc_bal_trf_map, 
                     ol_tc_bal_trf_cat_map,
                     txn_code
		where btm_bal_trf_type = :hv_bal_trf_type:ind_bal_trf_type
		and btm_fr_acct_type = :hv_from_acct_type:ind_from_acct_type
		and btm_to_acct_type = :hv_to_acct_type:ind_to_acct_type
		and btm_to_baid_cat_id = btcm_map_id
		and btcm_baid_category = :hv_to_baid_category:ind_to_baid_category
		and btm_txn_code_type = :hv_bal_trf_txn_code_type:ind_bal_trf_txn_code_type
		and btm_txn_code = tc_code; */ 


        /* EXEC SQL OPEN c_cursor_getbaltrftxncode; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_bal_trf_type;
        sqlstm.sqhstl[0] = (unsigned long )12;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_bal_trf_type;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_acct_type;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_from_acct_type;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_acct_type;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_to_acct_type;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_baid_category;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_to_baid_category;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_bal_trf_txn_code_type;
        sqlstm.sqhstl[4] = (unsigned long )22;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_bal_trf_txn_code_type;
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
        if (sqlca.sqlcode < 0) goto getbaltrftxncode_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_getbaltrftxncode
		INTO 
			:v_map_txn_code:ind_map_txn_code,
			:v_allow_fe_init:ind_allow_fe_init; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )40;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_map_txn_code;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_map_txn_code;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_allow_fe_init;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_allow_fe_init;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getbaltrftxncode_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		iCnt++;

		if (ind_map_txn_code >= 0) {
			v_map_txn_code.arr[v_map_txn_code.len] = '\0';
                        PutField_CString(hRls,"map_txn_code",(const char*)v_map_txn_code.arr);
DEBUGLOG(("GetBalTransferTxnCode map_txn_code = [%s]\n", v_map_txn_code.arr));
		}

		if (ind_allow_fe_init >= 0) {
                        PutField_Int(hRls,"allow_fe_init", v_allow_fe_init);
DEBUGLOG(("GetBalTransferTxnCode allow_fe_init = [%d]\n", v_allow_fe_init));
                }

		break;
	} while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getbaltrftxncode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )63;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getbaltrftxncode_error;
}



	if (iCnt > 0) {
DEBUGLOG(("GetBalTransferTxnCode Normal Exit, Found\n"));
		iRet = PD_FOUND;
	} else {
DEBUGLOG(("GetBalTransferTxnCode Not Found\n"));
	}

	return iRet;

getbaltrftxncode_error:
DEBUGLOG(("getbaltrftxncode_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTcBalTrfMap.GetBalTransferTxnCode:SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getbaltrftxncode; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )78;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}



        return PD_INTERNAL_ERR;
}


