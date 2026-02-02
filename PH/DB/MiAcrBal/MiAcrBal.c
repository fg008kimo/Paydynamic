
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
           char  filnam[12];
};
static struct sqlcxp sqlfpn =
{
    11,
    "MiAcrBal.pc"
};


static unsigned int sqlctx = 150859;


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
"SELECT ma_bank_bal , ma_rate FROM mi_acr_bal WHERE ma_from_ccy = :b0 AND ma\
_bank_ccy = :b1            ";

 static char *sq0003 = 
"SELECT ma_bank_bal , ma_rate FROM mi_acr_bal WHERE ma_from_ccy = :b0 AND ma\
_bank_ccy = :b1 FOR UPDATE ";

 static char *sq0004 = 
"select ma_from_ccy , ma_bank_bal , ma_rate , ratio , cnt_for_prorata from m\
i_acr_bal_view where ma_bank_ccy = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,188,0,6,99,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,
0,
44,0,0,2,102,0,9,181,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
67,0,0,2,0,0,13,183,0,0,2,0,0,1,0,2,4,0,0,2,4,0,0,
90,0,0,2,0,0,15,207,0,0,0,0,0,1,0,
105,0,0,2,0,0,15,223,0,0,0,0,0,1,0,
120,0,0,3,102,0,9,269,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
143,0,0,3,0,0,13,271,0,0,2,0,0,1,0,2,4,0,0,2,4,0,0,
166,0,0,3,0,0,15,294,0,0,0,0,0,1,0,
181,0,0,3,0,0,15,310,0,0,0,0,0,1,0,
196,0,0,4,125,0,9,355,0,2049,1,1,0,1,0,1,9,0,0,
215,0,0,4,0,0,13,357,0,0,5,0,0,1,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,3,0,0,
250,0,0,4,0,0,15,408,0,0,0,0,0,1,0,
265,0,0,4,0,0,15,425,0,0,0,0,0,1,0,
280,0,0,5,542,0,4,461,0,0,8,7,0,1,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/10/28              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MiAcrBal.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;
void MiAcrBal(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hRls)
{
	char            *csTmp;
	double          dTmp;


	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


	short           hv_return_value;

	/* varchar         hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

	/* varchar         hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;

	double          hv_bank_bal;
	double          hv_rate;
	/* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


	short           ind_from_ccy = -1;
	short           ind_bank_ccy = -1;
	short           ind_bank_bal = -1;
	short           ind_rate = -1;
	short           ind_add_user = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* from_ccy */
        if (GetField_CString(hRls,"from_ccy",&csTmp)) {
                hv_from_ccy.len = strlen(csTmp);
                memcpy(hv_from_ccy.arr,csTmp,hv_from_ccy.len);
                ind_from_ccy = 0;
DEBUGLOG(("Add:from_ccy = [%.*s]\n",hv_from_ccy.len,hv_from_ccy.arr));
        }

/* bank_ccy */
        if (GetField_CString(hRls,"bank_ccy",&csTmp)) {
                hv_bank_ccy.len = strlen(csTmp);
                memcpy(hv_bank_ccy.arr,csTmp,hv_bank_ccy.len);
                ind_bank_ccy = 0;
DEBUGLOG(("Add:bank_ccy = [%.*s]\n",hv_bank_ccy.len,hv_bank_ccy.arr));
        }


/* bank_bal   */
        if (GetField_Double(hRls,"bank_bal",&dTmp)) {
                hv_bank_bal= dTmp;
                ind_bank_bal = 0;
DEBUGLOG(("Add:bank_bal = [%f]\n",hv_bank_bal));
        }

/* rate   */
        if (GetField_Double(hRls,"rate",&dTmp)) {
                hv_rate= dTmp;
                ind_rate = 0;
DEBUGLOG(("Add:rate = [%f]\n",hv_rate));
        }

/* user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mi_acr_bal_insert(
					:hv_from_ccy:ind_from_ccy,
					:hv_bank_ccy:ind_bank_ccy,
					:hv_bank_bal:ind_bank_bal,
					:hv_rate:ind_rate,
					:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_acr_bal_insert ( :hv_from_c\
cy:ind_from_ccy , :hv_bank_ccy:ind_bank_ccy , :hv_bank_bal:ind_bank_bal , :hv\
_rate:ind_rate , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_from_ccy;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_bank_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_bank_bal;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_bank_bal;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_rate;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_rate;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[5] = (unsigned long )22;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}




DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MiAcrBal_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MiAcrBal_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MiAcrBal_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}



int GetOwnAcrBal(const hash_t *hRec, hash_t *hBal)
{
	int iRet = PD_NOT_FOUND;

	char *csTmp;
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getacrbal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

		/* varchar hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;


		double v_bank_bal;
		double v_rate;
		short ind_bank_bal = -1;
		short ind_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 



	if (GetField_CString(hRec, "from_ccy", &csTmp)) {
		hv_from_ccy.len = strlen(csTmp);
		strncpy((char *)hv_from_ccy.arr, csTmp, hv_from_ccy.len);
DEBUGLOG(("GetOwnAcrBal: from_ccy = [%.*s]\n", hv_from_ccy.len, hv_from_ccy.arr));
	}

	if (GetField_CString(hRec, "bank_ccy", &csTmp)) {
		hv_bank_ccy.len = strlen(csTmp);
		strncpy((char *)hv_bank_ccy.arr, csTmp, hv_bank_ccy.len);
DEBUGLOG(("GetOwnAcrBal: ccy = [%.*s]\n", hv_bank_ccy.len, hv_bank_ccy.arr));
	}

	/* EXEC SQL DECLARE c_getacrbal CURSOR FOR
		SELECT	ma_bank_bal,
			ma_rate
		FROM	mi_acr_bal
		WHERE	ma_from_ccy = :hv_from_ccy
		AND	ma_bank_ccy = :hv_bank_ccy; */ 



	/* EXEC SQL OPEN c_getacrbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )44;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getacrbal_error;
}


        do {
		/* EXEC SQL FETCH c_getacrbal
		INTO	:v_bank_bal:ind_bank_bal,
			:v_rate:ind_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )67;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_bal;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_bal;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_rate;
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
  if (sqlca.sqlcode < 0) goto getacrbal_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_bank_bal >= 0) {
			PutField_Double(hBal, "bank_bal", v_bank_bal);
DEBUGLOG(("GetOwnAcrBal bal = [%f]\n", v_bank_bal));
		}

		if (ind_rate >= 0) {
			PutField_Double(hBal, "rate", v_rate);
DEBUGLOG(("GetOwnAcrBal rate = [%f]\n", v_rate));
		}


		iCnt ++;
		iRet = PD_FOUND;

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_getacrbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getacrbal_error;
}



	if (iRet == PD_FOUND) {
DEBUGLOG(("GetOwnAcrBal: record found\n"));
	} else {
DEBUGLOG(("GetOwnAcrBal no record found\n"));
	}

DEBUGLOG(("GetOwnAcrBal Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getacrbal_error:
DEBUGLOG(("getacrbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAcrBal getacrbal_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getacrbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getacrbal_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetOwnAcrBalForUpdate(const hash_t *hRec, hash_t *hBal)
{
	int iRet = PD_NOT_FOUND;

	char *csTmp;
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO getacrbalforupd_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

		/* varchar hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;


		double v_bank_bal;
		double v_rate;
		short ind_bank_bal = -1;
		short ind_rate = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec, "from_ccy", &csTmp)) {
		hv_from_ccy.len = strlen(csTmp);
		strncpy((char *)hv_from_ccy.arr, csTmp, hv_from_ccy.len);
DEBUGLOG(("GetOwnAcrBalForUpdate: from_ccy = [%.*s]\n", hv_from_ccy.len, hv_from_ccy.arr));
	}

	if (GetField_CString(hRec, "bank_ccy", &csTmp)) {
		hv_bank_ccy.len = strlen(csTmp);
		strncpy((char *)hv_bank_ccy.arr, csTmp, hv_bank_ccy.len);
DEBUGLOG(("GetOwnAcrBalForUpdate: ccy = [%.*s]\n", hv_bank_ccy.len, hv_bank_ccy.arr));
	}

	/* EXEC SQL DECLARE c_getacrbalforupd CURSOR FOR
		SELECT	ma_bank_bal,
			ma_rate
		FROM	mi_acr_bal
		WHERE	ma_from_ccy = :hv_from_ccy
		AND	ma_bank_ccy = :hv_bank_ccy
		FOR UPDATE; */ 


	/* EXEC SQL OPEN c_getacrbalforupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getacrbalforupd_error;
}


        do {
		/* EXEC SQL FETCH c_getacrbalforupd
		INTO	:v_bank_bal:ind_bank_bal,
			:v_rate:ind_rate; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )143;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_bank_bal;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_bank_bal;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_rate;
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
  if (sqlca.sqlcode < 0) goto getacrbalforupd_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		if (ind_bank_bal >= 0) {
			PutField_Double(hBal, "bank_bal", v_bank_bal);
DEBUGLOG(("GetOwnAcrBalForUpdate bank_bal = [%f]\n", v_bank_bal));
		}

		if (ind_rate >= 0) {
			PutField_Double(hBal, "rate", v_rate);
DEBUGLOG(("GetOwnAcrBalForUpdate rate = [%f]\n", v_rate));
		}

		iCnt ++;
		iRet = PD_FOUND;

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_getacrbalforupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getacrbalforupd_error;
}



	if (iRet == PD_FOUND) {
DEBUGLOG(("GetOwnAcrBalForUpdate: record found\n"));
	} else {
DEBUGLOG(("GetOwnAcrBalForUpdate no record found\n"));
	}

DEBUGLOG(("GetOwnAcrBalForUpdate Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getacrbalforupd_error:
DEBUGLOG(("getacrbalforupd_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAcrBal getacrbalforupd_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL CLOSE c_getacrbalforupd; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )181;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getacrbalforupd_error;
}


	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetAllAcrBalByCcy(const char* csCcy,recordset_t* myRec)
{
	int     iRet = PD_OK;
	int     iCnt = 0;
	hash_t* myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO all_acr_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;


		/* varchar	v_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_from_ccy;

		double	v_bank_bal;
		double	v_rate;
		double	v_ratio;
		int	v_prorata_cnt;

		short	ind_from_ccy = -1;
		short	ind_bank_bal = -1;
		short	ind_rate = -1;
		short	ind_ratio= -1;
		short	ind_prorata_cnt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_bank_ccy.len = strlen(csCcy);
	memcpy(hv_bank_ccy.arr,csCcy,hv_bank_ccy.len);
DEBUGLOG(("GetAllAcrBalByCcy bank ccy = [%.*s]\n",hv_bank_ccy.len,hv_bank_ccy.arr));

	/* EXEC SQL DECLARE c_cursor_all_acr CURSOR FOR
		select  ma_from_ccy,
			ma_bank_bal,
			ma_rate,
			ratio,
			cnt_for_prorata
		from    mi_acr_bal_view
		where   ma_bank_ccy = :hv_bank_ccy; */ 


	/* EXEC SQL OPEN c_cursor_all_acr; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )196;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_ccy;
 sqlstm.sqhstl[0] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto all_acr_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_all_acr
		INTO
			:v_from_ccy:ind_from_ccy,
			:v_bank_bal:ind_bank_bal,
			:v_rate:ind_rate,
			:v_ratio:ind_ratio,
			:v_prorata_cnt:ind_prorata_cnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )215;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_from_ccy;
  sqlstm.sqhstl[0] = (unsigned long )5;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_from_ccy;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bank_bal;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_bank_bal;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_rate;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ratio;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ratio;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_prorata_cnt;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_prorata_cnt;
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
  if (sqlca.sqlcode < 0) goto all_acr_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash,0);

/* from_ccy */
                if(ind_from_ccy >= 0) {
                        PutField_CString(myHash,"from_ccy",(const char*)v_from_ccy.arr);
DEBUGLOG(("GetAllAcrBalByCcy v_from_ccy = [%.*s]\n",v_from_ccy.len,v_from_ccy.arr));
                }

/* bal */
                if (ind_bank_bal >= 0) {
                        PutField_Double(myHash,"bank_bal",v_bank_bal);
DEBUGLOG(("GetAllAcrBalByCcy bal = [%f]\n",v_bank_bal));
                }

/* rate */
                if (ind_rate >= 0) {
                        PutField_Double(myHash,"rate",v_rate);
DEBUGLOG(("GetAllAcrBalByCcy rate = [%f]\n",v_rate));
                }

/* ratio */
                if (ind_ratio >= 0) {
                        PutField_Double(myHash,"ratio",v_ratio);
DEBUGLOG(("GetAllAcrBalByCcy ratio = [%f]\n",v_ratio));
                }

/* prorata_cnt */
                if (ind_prorata_cnt >= 0) {
                        PutField_Int(myHash,"prorata_cnt",v_prorata_cnt);
DEBUGLOG(("GetAllAcrBalByCcy prorata_cnt = [%d]\n",v_prorata_cnt));
                }

                RecordSet_Add(myRec,myHash);
                iCnt ++;

        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_all_acr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )250;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto all_acr_error;
}



	if(iCnt>0){
DEBUGLOG(("GetAllAcrBalByCcy Normal Exit [%d]\n",iRet));
        }
        else{
                iRet = PD_ERR;
DEBUGLOG(("GetAllAcrBalByCcy Not found [%d]\n",iRet));
        }

        return  iRet;

all_acr_error:
DEBUGLOG(("all_acr_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MiAcrBal_GetAllAcrBalByCcy: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_all_acr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )265;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int FindRateByDate(const char* csDateTime,
                   const char* csFromCcy,
                   const char* csBankCcy,
                   double * dRate)
{
        int     iRet = PD_NOT_FOUND;
        /* EXEC SQL WHENEVER SQLERROR GOTO find_rate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_from_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy;

                /* varchar         hv_bank_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_bank_ccy;

                /* varchar         hv_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_datetime;


                double          v_rate;

                short           ind_rate= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_from_ccy.len = strlen(csFromCcy);
        memcpy(hv_from_ccy.arr,csFromCcy,hv_from_ccy.len);
DEBUGLOG(("FindRateByDate from_ccy = [%.*s]\n",hv_from_ccy.len,hv_from_ccy.arr));

        hv_bank_ccy.len = strlen(csBankCcy);
        memcpy(hv_bank_ccy.arr,csBankCcy,hv_bank_ccy.len);
DEBUGLOG(("FindRateByDate bank_ccy = [%.*s]\n",hv_bank_ccy.len,hv_bank_ccy.arr));

        hv_datetime.len = strlen(csDateTime);
        memcpy(hv_datetime.arr,csDateTime,hv_datetime.len);
DEBUGLOG(("FindRateByDate datetime = [%.*s]\n",hv_datetime.len,hv_datetime.arr));

        /* EXEC SQL
                select nvl(new_rate,ma_rate) new_rate
                into    :v_rate:ind_rate
                from
                (select ma_from_ccy,ma_bank_ccy,ma_rate from mi_acr_bal
                where ma_from_ccy = :hv_from_ccy
                and ma_bank_ccy = :hv_bank_ccy) left join
                (
                select  from_ccy,bank_ccy,new_rate
                from    MI_ACR_INOUT_OVERVIEW
                where   bank_ccy = :hv_bank_ccy
                and     from_ccy = :hv_from_ccy
                and     new_rate is not null
                and     time = ( select max(time)
                                  from MI_ACR_INOUT_OVERVIEW
                                  where bank_ccy = :hv_bank_ccy
                                  and   from_ccy = :hv_from_ccy
                                  and   new_rate is not null
                                  and   time <= to_date(:hv_datetime,'YYYYMMDDHH24MISS')))
                on from_ccy = ma_from_ccy
                and bank_ccy = ma_bank_ccy; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( new_rate , ma_rate ) new_rate into :b0:\
b1 from ( select ma_from_ccy , ma_bank_ccy , ma_rate from mi_acr_bal where ma\
_from_ccy = :b2 and ma_bank_ccy = :b3 ) left join ( select from_ccy , bank_cc\
y , new_rate from MI_ACR_INOUT_OVERVIEW where bank_ccy = :b3 and from_ccy = :\
b2 and new_rate is not null and time = ( select max ( time ) from MI_ACR_INOU\
T_OVERVIEW where bank_ccy = :b3 and from_ccy = :b2 and new_rate is not null a\
nd time <= to_date ( :b8 , 'YYYYMMDDHH24MISS' ) ) ) on from_ccy = ma_from_ccy\
 and bank_ccy = ma_bank_ccy ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )280;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_rate;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_rate;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_ccy;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_ccy;
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
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_from_ccy;
        sqlstm.sqhstl[6] = (unsigned long )5;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_datetime;
        sqlstm.sqhstl[7] = (unsigned long )16;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)0;
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
        if (sqlca.sqlcode < 0) goto find_rate_error;
}



/* rate */
                if (ind_rate >= 0) {
                        *dRate = v_rate;
                        iRet = PD_FOUND;
DEBUGLOG(("FindRateByDate rate = [%lf]\n",*dRate));
                }


        if(iRet==PD_FOUND){
DEBUGLOG(("FindRateByDate Normal Exit\n"));
        }
        else{
DEBUGLOG(("FindRateByDate Not found\n"));
        }

        return  iRet;

find_rate_error:
DEBUGLOG(("find_rate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("SebBalance_FindRate: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

