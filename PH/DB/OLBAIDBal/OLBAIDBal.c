
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
           char  filnam[13];
};
static struct sqlcxp sqlfpn =
{
    12,
    "OLBAIDBal.pc"
};


static unsigned int sqlctx = 307915;


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
   unsigned char  *sqhstv[7];
   unsigned long  sqhstl[7];
            int   sqhsts[7];
            short *sqindv[7];
            int   sqinds[7];
   unsigned long  sqharm[7];
   unsigned long  *sqharc[7];
   unsigned short  sqadto[7];
   unsigned short  sqtdso[7];
} sqlstm = {12,7};

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

 static char *sq0008 = 
"select obab_bal , obab_in_transit , obab_total_hold from ol_baid_bal where \
obab_baid = :b0 and obab_currency_id = :b1 and obab_country_id = :b2 for upda\
te ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,193,0,6,96,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,
0,
44,0,0,2,201,0,6,109,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,
83,0,0,3,192,0,6,210,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,
0,0,
122,0,0,4,191,0,6,221,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,
161,0,0,5,199,0,4,306,0,0,7,3,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,
204,0,0,6,210,0,4,397,0,0,7,3,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,
247,0,0,7,199,0,4,413,0,0,7,3,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,
290,0,0,8,155,0,9,513,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
317,0,0,8,0,0,13,515,0,0,3,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,
344,0,0,8,0,0,15,535,0,0,0,0,0,1,0,
359,0,0,8,0,0,15,544,0,0,0,0,0,1,0,
374,0,0,9,201,0,6,609,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,
413,0,0,10,207,0,6,716,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,
9,0,0,
452,0,0,11,92,0,6,790,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/11              LokMan Chow
Update to BAID Bal                                 2014/01/02              Stan Poon
Refine                                             2014/07/02              David Wong
Add DeleteBaidBal				   2016/08/10		   Dirk Wong
Add BOOLBalance(IsUpdatePayoutTempBAIDBal)	   2019/05/30		   Elvis Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLBAIDBal.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char cDebug;
OBJPTR(BO);

void OLBAIDBal(char cdebug)
{
	cDebug = cdebug;
}

int UpdateBalance(const char* csBAID,
		const char* csCountryId,
		const char* csCcy,
		char cType,
		double dAmt,
		char* csUpdateUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double hv_balance;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short ind_baid = -1;
		short ind_country_id = -1;
		short ind_ccy_id = -1;
		short ind_balance = -1;
		short ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	strncpy((char*)hv_baid.arr, csBAID, hv_baid.len);
	ind_baid = 0;
DEBUGLOG(("UpdateBalance baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateBalance country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateBalance ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	if (cType == PD_IND_CREDIT) {
		hv_balance = dAmt;
DEBUGLOG(("UpdateBalance credit balance = [%f]\n", hv_balance));
	} else {
		hv_balance = (-1) * dAmt;
DEBUGLOG(("UpdateBalance debit balance = [%f]\n", (-1) * hv_balance));
	}
	ind_balance = 0;

	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateBalance create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	// Is Update Payout Temp BAID Bal
        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
        if ((unsigned long)(*BOObjPtr)(csBAID) == PD_TRUE) {
DEBUGLOG(("UpdateBalance IsUpdatePayoutTempBAIDBal = [True]\n"));

		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_baid_bal_update(
									:hv_baid:ind_baid,
									:hv_country_id:ind_country_id,
									:hv_ccy_id:ind_ccy_id,
									:hv_balance:ind_balance,
									:hv_create_user:ind_create_user);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_update ( :hv_baid\
:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :hv_balan\
ce:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_balance;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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


	} else {
DEBUGLOG(("UpdateBalance IsUpdatePayoutTempBAIDBal = [False]\n"));

		/* EXEC SQL EXECUTE
                        BEGIN
                                :hv_return_value := sp_ol_po_temp_baid_bal_insert(
                                                                        :hv_baid:ind_baid,
                                                                        :hv_country_id:ind_country_id,
                                                                        :hv_ccy_id:ind_ccy_id,
                                                                        :hv_balance:ind_balance,
                                                                        :hv_create_user:ind_create_user);
                        END;
                END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_po_temp_baid_bal_insert ( \
:hv_baid:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :\
hv_balance:ind_balance , :hv_create_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )44;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_balance;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_balance;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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


	}

DEBUGLOG(("UpdateBalance Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateBalance Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLBAIDBal_UpdateBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateBalance: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLBAIDBal_UpdateBalance: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateBalance: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_UpdateBalance: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int UpdateHoldBalance(const char* csBAID,
		const char* csCountryId,
		const char* csCcy,
		char cType,
		double dAmt,
		char* csUpdateUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO hold_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double hv_hold;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short ind_baid = -1;
		short ind_country_id = -1;
		short ind_ccy_id = -1;
		short ind_hold = -1;
		short ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateHoldBalance: Begin\n"));

	hv_baid.len = strlen(csBAID);
	strncpy((char*)hv_baid.arr, csBAID, hv_baid.len);
	ind_baid = 0;
DEBUGLOG(("UpdateHoldBalance baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateHoldBalance country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateHoldBalance ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	hv_hold = dAmt;
	ind_hold = 0;
DEBUGLOG(("UpdateHoldBalance hold = [%f]\n", hv_hold));

	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateHoldBalance create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	// Is Update Payout Temp BAID Bal
        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
        if ((unsigned long)(*BOObjPtr)(csBAID) == PD_TRUE) {
DEBUGLOG(("UpdateHoldBalance IsUpdatePayoutTempBAIDBal = [True]\n"));

		if (cType == PD_HOLD) {
			/* EXEC SQL EXECUTE
				BEGIN
					:hv_return_value := sp_ol_baid_bal_credit_hold(
										:hv_baid:ind_baid,
										:hv_country_id:ind_country_id,
										:hv_ccy_id:ind_ccy_id,
										:hv_hold:ind_hold,
										:hv_create_user:ind_create_user);
				END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_credit_hold ( :h\
v_baid:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :hv\
_hold:ind_hold , :hv_create_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )83;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
   sqlstm.sqhstl[1] = (unsigned long )22;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_baid;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_hold;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[5] = (unsigned long )22;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto hold_error;
}


		} else {
			/* EXEC SQL EXECUTE
				BEGIN
					:hv_return_value := sp_ol_baid_bal_debit_hold(
										:hv_baid:ind_baid,
										:hv_country_id:ind_country_id,
										:hv_ccy_id:ind_ccy_id,
										:hv_hold:ind_hold,
										:hv_create_user:ind_create_user);
				END;
			END-EXEC; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_debit_hold ( :hv\
_baid:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :hv_\
hold:ind_hold , :hv_create_user:ind_create_user ) ; END ;";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )122;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
   sqlstm.sqhstl[1] = (unsigned long )22;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_baid;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
   sqlstm.sqhstl[2] = (unsigned long )4;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_country_id;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
   sqlstm.sqhstl[3] = (unsigned long )5;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_hold;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_hold;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
   sqlstm.sqhstl[5] = (unsigned long )22;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
   if (sqlca.sqlcode < 0) goto hold_error;
}


		}
	} else {
DEBUGLOG(("UpdateHoldBalance IsUpdatePayoutTempBAIDBal = [False]\n"));

		hv_return_value = SP_OK;
	}

DEBUGLOG(("UpdateHoldBalance Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateHoldBalance Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLBAIDBal_UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLBAIDBal_UpdateHoldBalance: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateHoldBalance: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

hold_error:
DEBUGLOG(("hold_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_UpdateHoldBalance: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int GetBalance(const char* csBAID,
		const char* csCountryId,
		const char* csCurrencyId,
		hash_t *hVal)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_bal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double v_balance;
		double v_prepaid;
		double v_in_transit;
		double v_total_hold;

		short ind_balance = -1;
		short ind_prepaid = -1;
		short ind_in_transit = -1;
		short ind_total_hold = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("GetBalance baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	memcpy(hv_country_id.arr, csCountryId, hv_country_id.len);
DEBUGLOG(("GetBalance country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCurrencyId);
	memcpy(hv_ccy_id.arr, csCurrencyId, hv_ccy_id.len);
DEBUGLOG(("GetBalance ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	/* EXEC SQL select	obab_bal,
			obab_prepaid,
			obab_in_transit,
			obab_total_hold
		into :v_balance:ind_balance,
			:v_prepaid:ind_prepaid,
			:v_in_transit:ind_in_transit,
			:v_total_hold:ind_total_hold
		from ol_baid_bal
		where obab_baid = :hv_baid
		and obab_country_id = :hv_country_id
		and obab_currency_id = :hv_ccy_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select obab_bal , obab_prepaid , obab_in_transit , obab_tot\
al_hold into :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 from ol_baid_bal where obab_ba\
id = :b8 and obab_country_id = :b9 and obab_currency_id = :b10 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )161;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_balance;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_prepaid;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_prepaid;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&v_in_transit;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_in_transit;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_total_hold;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[4] = (unsigned long )22;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto get_bal_error;
}



	// balance
	if (ind_balance < 0)
		v_balance = 0;
	PutField_Double(hVal, "balance", v_balance);
DEBUGLOG(("GetBalance balance = [%f]\n", v_balance));

	// prepaid
	if (ind_prepaid < 0)
		v_prepaid = 0;
	PutField_Double(hVal, "prepaid", v_prepaid);
DEBUGLOG(("GetBalance prepaid = [%f]\n", v_prepaid));

	// in_transit
	if (ind_in_transit < 0)
		v_in_transit = 0;
	PutField_Double(hVal, "in_transit", v_in_transit);
DEBUGLOG(("GetBalance in_transit = [%f]\n", v_in_transit));

	// total_hold
	if (ind_total_hold < 0)
		v_total_hold = 0;
	PutField_Double(hVal, "total_hold", v_total_hold);
DEBUGLOG(("GetBalance total_hold = [%f]\n", v_total_hold));

DEBUGLOG(("GetBalance Normal Exit\n"));
	return iRet;

get_bal_error:
DEBUGLOG(("get_bal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int GetBalanceForUpdate(const char* csBAID,
		const char* csCountryId,
		const char* csCurrencyId,
                hash_t *hVal)
{
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO get_bal_update_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double v_balance;
		double v_prepaid;
		double v_in_transit;
		double v_total_hold;
		
		short ind_balance = -1;
		short ind_prepaid = -1;
		short ind_in_transit = -1;
		short ind_total_hold = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	memcpy(hv_baid.arr, csBAID, hv_baid.len);
DEBUGLOG(("GetBalanceForUpdate baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	memcpy(hv_country_id.arr, csCountryId, hv_country_id.len);
DEBUGLOG(("GetBalanceForUpdate country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCurrencyId);
	memcpy(hv_ccy_id.arr, csCurrencyId, hv_ccy_id.len);
DEBUGLOG(("GetBalanceForUpdate ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	// Is Update Payout Temp BAID Bal
        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
        if ((unsigned long)(*BOObjPtr)(csBAID) == PD_TRUE) {
DEBUGLOG(("GetBalanceForUpdate IsUpdatePayoutTempBAIDBal = [True]\n"));

		/* EXEC SQL select obab_bal,
				obab_prepaid,
				obab_in_transit,
				obab_total_hold
			into :v_balance:ind_balance,
				:v_prepaid:ind_prepaid,
				:v_in_transit:ind_in_transit,
				:v_total_hold:ind_total_hold
			from ol_baid_bal
			where obab_baid = :hv_baid
			and obab_country_id = :hv_country_id
			and obab_currency_id = :hv_ccy_id
			for update; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select obab_bal , obab_prepaid , obab_in_transit , obab_to\
tal_hold into :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 from ol_baid_bal where obab_b\
aid = :b8 and obab_country_id = :b9 and obab_currency_id = :b10 for update ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )204;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_balance;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prepaid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prepaid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_in_transit;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_in_transit;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_total_hold;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[4] = (unsigned long )22;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto get_bal_update_error;
}


	} else {
DEBUGLOG(("GetBalanceForUpdate IsUpdatePayoutTempBAIDBal = [False]\n"));

		/* EXEC SQL select obab_bal,
                	        obab_prepaid,
                	        obab_in_transit,
                	        obab_total_hold
                	into :v_balance:ind_balance,
                	        :v_prepaid:ind_prepaid,
                	        :v_in_transit:ind_in_transit,
                	        :v_total_hold:ind_total_hold
                	from ol_baid_bal
                	where obab_baid = :hv_baid
                	and obab_country_id = :hv_country_id
                	and obab_currency_id = :hv_ccy_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "select obab_bal , obab_prepaid , obab_in_transit , obab_to\
tal_hold into :b0:b1 , :b2:b3 , :b4:b5 , :b6:b7 from ol_baid_bal where obab_b\
aid = :b8 and obab_country_id = :b9 and obab_currency_id = :b10 ";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )247;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_balance;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_balance;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_prepaid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_prepaid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_in_transit;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_in_transit;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_total_hold;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[4] = (unsigned long )22;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[5] = (unsigned long )4;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)0;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto get_bal_update_error;
}


	}

	// balance
	if (ind_balance < 0)
		v_balance = 0;
	PutField_Double(hVal, "balance", v_balance);
DEBUGLOG(("GetBalanceForUpdate balance = [%f]\n", v_balance));

	// prepaid
	if (ind_prepaid < 0)
		v_prepaid = 0;
	PutField_Double(hVal, "prepaid", v_prepaid);
DEBUGLOG(("GetBalanceForUpdate prepaid = [%f]\n", v_prepaid));

	// in_transit
	if (ind_in_transit < 0)
		v_in_transit = 0;
	PutField_Double(hVal, "in_transit", v_in_transit);
DEBUGLOG(("GetBalanceForUpdate in_transit = [%f]\n", v_in_transit));

	// totol_hold
	if (ind_total_hold < 0)
		v_total_hold = 0;
        PutField_Double(hVal, "total_hold", v_total_hold);
DEBUGLOG(("GetBalanceForUpdate total_hold = [%f]\n", v_total_hold));

DEBUGLOG(("GetBalanceForUpdate Normal Exit\n"));
	return iRet;

get_bal_update_error:
DEBUGLOG(("get_bal_update error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_Get: SP_ERR\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetAvalBaidBal(const char *csBaid,
		const char *csCurrencyId,
		const char *csCountryId,
		double *dBal)
{
	*dBal = 0.0;
	int iRet = PD_OK;

	/* EXEC sQL WHENEVER SQLERROR GOTO getavalbaidbal_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;


		double v_current_bal;
		double v_in_transit;
		double v_total_hold;

		short ind_current_bal = -1;
		short ind_in_transit = -1;
		short ind_total_hold = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("GetAvalBaidBal csBaid = [%s]\n", csBaid));
DEBUGLOG(("GetAvalBaidBal csCurrencyId = [%s]\n", csCurrencyId));
DEBUGLOG(("GetAvalBaidBal csCountryId = [%s]\n", csCountryId));

	hv_baid.len = strlen(csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("GetAvalBaidBal baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_ccy_id.len = strlen(csCurrencyId);
	memcpy(hv_ccy_id.arr, csCurrencyId, hv_ccy_id.len);
DEBUGLOG(("GetAvalPidBal ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	hv_country_id.len = strlen(csCountryId);
	memcpy(hv_country_id.arr, csCountryId, hv_country_id.len);
DEBUGLOG(("GetAvalPidBal country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	/* EXEC SQL DECLARE c_cursor_getavalbaidbal CURSOR FOR
		select	obab_bal,
			obab_in_transit,
			obab_total_hold
		from	ol_baid_bal
		where	obab_baid = :hv_baid
		and	obab_currency_id = :hv_ccy_id
		and	obab_country_id = :hv_country_id
		for update; */ 


	/* EXEC SQL OPEN c_cursor_getavalbaidbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0008;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )290;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[0] = (unsigned long )22;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
 sqlstm.sqhstl[2] = (unsigned long )4;
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
 if (sqlca.sqlcode < 0) goto getavalbaidbal_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getavalbaidbal
		INTO
			:v_current_bal:ind_current_bal,
			:v_in_transit:ind_in_transit,
			:v_total_hold:ind_total_hold; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )317;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_current_bal;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_current_bal;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_in_transit;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_in_transit;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_total_hold;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_total_hold;
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
  if (sqlca.sqlcode < 0) goto getavalbaidbal_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		// balance
		if ((ind_current_bal < 0) || (ind_in_transit < 0) || (ind_total_hold < 0))
			*dBal = 0.0;
		else {
			*dBal = v_current_bal - v_in_transit - v_total_hold;
DEBUGLOG(("GetAvalBaidBal balance = [%f]\n", *dBal));
		}
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getavalbaidbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )344;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getavalbaidbal_error;
}



DEBUGLOG(("GetAvalBaidBal Normal Exit\n"));
	return iRet;

getavalbaidbal_error:
DEBUGLOG(("getavalbaidbal_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getavalbaidbal; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )359;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}


int UpdatePrepaid(const char* csBAID,
		const char* csCountryId,
		const char* csCcy,
		char cType,
		double dAmt,
		char* csUpdateUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO prepaid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double hv_prepaid;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short ind_baid = -1;
		short ind_country_id = -1;
		short ind_ccy_id = -1;
		short ind_prepaid = -1;
		short ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	strncpy((char*)hv_baid.arr, csBAID, hv_baid.len);
	ind_baid = 0;
DEBUGLOG(("UpdatePrepaid baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdatePrepaid country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdatePrepaid ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	if (cType == PD_IND_CREDIT) {
		hv_prepaid = dAmt;
DEBUGLOG(("UpdatePrepaid credit prepaid = [%f]\n", hv_prepaid));
	} else {
		hv_prepaid = (-1) * dAmt;
DEBUGLOG(("UpdatePrepaid debit prepaid = [%f]\n", (-1) * hv_prepaid));
	}
	ind_prepaid = 0;

	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdatePrepaid create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	// Is Update Payout Temp BAID Bal
        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
        if ((unsigned long)(*BOObjPtr)(csBAID) == PD_TRUE) {
DEBUGLOG(("UpdatePrepaid IsUpdatePayoutTempBAIDBal = [True]\n"));

		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_baid_bal_prepaid_update(
									:hv_baid:ind_baid,
									:hv_country_id:ind_country_id,
									:hv_ccy_id:ind_ccy_id,
									:hv_prepaid:ind_prepaid,
									:hv_create_user:ind_create_user);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_prepaid_update ( \
:hv_baid:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :\
hv_prepaid:ind_prepaid , :hv_create_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )374;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_prepaid;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_prepaid;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
  if (sqlca.sqlcode < 0) goto prepaid_error;
}


	} else {
DEBUGLOG(("UpdatePrepaid IsUpdatePayoutTempBAIDBal = [False]\n"));
		
		hv_return_value = SP_OK;
	}

DEBUGLOG(("UpdatePrepaid Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdatePrepaid Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLBAIDBal_UpdatePrepaid: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdatePrepaid: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLBAIDBal_UpdatePrepaid: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdatePrepaid: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

prepaid_error:
DEBUGLOG(("prepaid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_UpdatePrepaid: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int UpdateInTransit(const char* csBAID,
		const char* csCountryId,
		const char* csCcy,
		char cType,
		double dAmt,
		char* csUpdateUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO in_transit_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar hv_country_id[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country_id;

		/* varchar hv_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy_id;

		double hv_in_transit;
		/* varchar hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short ind_baid = -1;
		short ind_country_id = -1;
		short ind_ccy_id = -1;
		short ind_in_transit = -1;
		short ind_create_user = -1;

		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen(csBAID);
	strncpy((char*)hv_baid.arr, csBAID, hv_baid.len);
	ind_baid = 0;
DEBUGLOG(("UpdateInTransit baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country_id.len = strlen(csCountryId);
	strncpy((char*)hv_country_id.arr, csCountryId, hv_country_id.len);
	ind_country_id = 0;
DEBUGLOG(("UpdateInTransit country_id = [%.*s]\n", hv_country_id.len, hv_country_id.arr));

	hv_ccy_id.len = strlen(csCcy);
	strncpy((char*)hv_ccy_id.arr, csCcy, hv_ccy_id.len);
	ind_ccy_id = 0;
DEBUGLOG(("UpdateInTransit ccy_id = [%.*s]\n", hv_ccy_id.len, hv_ccy_id.arr));

	if (cType == PD_IND_CREDIT) {
		hv_in_transit = dAmt;
DEBUGLOG(("UpdateInTransit credit in_transit = [%f]\n", hv_in_transit));
	} else {
		hv_in_transit = (-1) * dAmt;
DEBUGLOG(("UpdateInTransit debit in_transit = [%f]\n", (-1) * hv_in_transit));
	}
	ind_in_transit = 0;

	hv_create_user.len = strlen(csUpdateUser);
	strncpy((char*)hv_create_user.arr, csUpdateUser, hv_create_user.len);
	ind_create_user = 0;
DEBUGLOG(("UpdateInTransit create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));

	// Is Update Payout Temp BAID Bal
        BOObjPtr = CreateObj(BOPtr,"BOOLBalance","IsUpdatePayoutTempBAIDBal");
        if ((unsigned long)(*BOObjPtr)(csBAID) == PD_TRUE) {
DEBUGLOG(("UpdateInTransit IsUpdatePayoutTempBAIDBal = [True]\n"));

		/* EXEC SQL EXECUTE
			BEGIN
				:hv_return_value := sp_ol_baid_bal_in_tran_update(
									:hv_baid:ind_baid,
									:hv_country_id:ind_country_id,
									:hv_ccy_id:ind_ccy_id,
									:hv_in_transit:ind_in_transit,
									:hv_create_user:ind_create_user);
			END;
		END-EXEC; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_in_tran_update ( \
:hv_baid:ind_baid , :hv_country_id:ind_country_id , :hv_ccy_id:ind_ccy_id , :\
hv_in_transit:ind_in_transit , :hv_create_user:ind_create_user ) ; END ;";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )413;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
  sqlstm.sqhstl[1] = (unsigned long )22;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_baid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_country_id;
  sqlstm.sqhstl[2] = (unsigned long )4;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_ccy_id;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ccy_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_in_transit;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_in_transit;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
  sqlstm.sqhstl[5] = (unsigned long )22;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
  if (sqlca.sqlcode < 0) goto in_transit_error;
}


	} else {
DEBUGLOG(("UpdateInTransit IsUpdatePayoutTempBAIDBal = [False]\n"));

		hv_return_value = SP_OK;	
	}

DEBUGLOG(("UpdateInTransit Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateInTransit Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLBAIDBal_UpdateInTransit: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateInTransit: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLBAIDBal_UpdateInTransit: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateInTransit: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

in_transit_error:
DEBUGLOG(("in_transit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBAIDBal_UpdateInTransit: SP_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	TxnAbort();
	return PD_ERR;
}


int DeleteBaidBal(const char *csBaid,
		const char *csCountryId,
		const char *csCurrencyId)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		/* varchar	hv_ccy[PD_CURRENCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;


		short hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_baid.len = strlen((const char*)csBaid);
	memcpy(hv_baid.arr, csBaid, hv_baid.len);
DEBUGLOG(("DeleteBaidBal: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));

	hv_country.len = strlen((const char*)csCountryId);
	memcpy(hv_country.arr, csCountryId, hv_country.len);
DEBUGLOG(("DeleteBaidBal: country_id = [%.*s]\n", hv_country.len, hv_country.arr));

	hv_ccy.len = strlen((const char*)csCurrencyId);
	memcpy(hv_ccy.arr, csCurrencyId, hv_ccy.len);
DEBUGLOG(("DeleteBaidBal: country_id = [%.*s]\n", hv_ccy.len, hv_ccy.arr));

	/* EXEC SQL EXECUTE
	BEGIN
		:hv_return_value := sp_ol_baid_bal_delete(:hv_baid,:hv_country,:hv_ccy);
	END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_baid_bal_delete ( :hv_baid \
, :hv_country , :hv_ccy ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )452;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
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
 if (sqlca.sqlcode < 0) goto delete_error;
}



DEBUGLOG(("DeleteBaidBal: Ret = [%d]\n", hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("DeleteBaidBal: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLBaidBal_DeleteBaidBal: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("DeleteBaidBal: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("OLBaidBal_DeleteBaidBal: SP_ERR TxnAbort\n");
DEBUGLOG(("DeleteBaidBal: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLBaidBal_DeleteBaidBal: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}
