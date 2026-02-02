
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
           char  filnam[22];
};
static struct sqlcxp sqlfpn =
{
    21,
    "MmsRuleCreditLimit.pc"
};


static unsigned int sqlctx = 163981483;


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

 static char *sq0001 = 
"SELECT MCL_AMOUNT_ID , MRA_TYPE , MRA_VALUE , MRA_ADD_VALUE , MRA_MIN_VALUE\
 , MRA_MAX_VALUE , MCL_CREDIT_LIMIT_MODE , MCL_EFFECT_DATE FROM MMS_RULE_CRED\
IT_LIMIT , MMS_RULE_AMOUNT WHERE MCL_AMOUNT_ID = MRA_ID AND MRA_DISABLED = 0 \
AND MCL_CREDIT_LIMIT_MODE = 'T' AND MCL_ENTITY_ID = :b0 AND MCL_CCY = :b1 AND\
 MCL_COUNTRY = :b2 AND MCL_TXN_CODE = :b3 AND MCL_DISABLED = 0 AND MCL_EFFECT\
_DATE < SYSDATE UNION SELECT MCL_AMOUNT_ID , MRA_TYPE , MRA_VALUE , MRA_ADD_V\
ALUE , MRA_MIN_VALUE , MRA_MAX_VALUE , MCL_CREDIT_LIMIT_MODE , MCL_EFFECT_DAT\
E FROM MMS_RULE_CREDIT_LIMIT , MMS_RULE_AMOUNT WHERE MCL_AMOUNT_ID = MRA_ID A\
ND MRA_DISABLED = 0 AND MCL_CREDIT_LIMIT_MODE = 'E' AND MCL_ENTITY_ID = :b0 A\
ND MCL_CCY = :b1 AND MCL_COUNTRY = :b2 AND MCL_DISABLED = 0 AND MCL_EFFECT_DA\
TE < SYSDATE ORDER BY MCL_CREDIT_LIMIT_MODE DESC , MCL_EFFECT_DATE DESC      \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,851,0,9,144,0,2049,7,7,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,
48,0,0,1,0,0,13,146,0,0,6,0,0,1,0,2,3,0,0,2,1,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,
87,0,0,1,0,0,15,188,0,0,0,0,0,1,0,
102,0,0,1,0,0,15,199,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/05/11              Dirk Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MmsRuleCreditLimit.h"
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MmsRuleCreditLimit(char    cdebug)
{
        cDebug = cdebug;
}

int GetMmsRuleCreditLimit(const hash_t* hRls, hash_t* myHash)
{
	int iRet = PD_NOT_FOUND;

	char	*csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO geterror; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_entity_id[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

		/* varchar	hv_ccy[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	hv_country[2]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar	hv_txn_code[3]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		int	v_amount_id;
		char	v_ra_type;
		double	v_ra_value;
		double	v_ra_add_value;
		double	v_ra_min_value;
		double	v_ra_max_value;

		short	ind_amount_id = -1;
		short	ind_ra_type = -1;
		short	ind_ra_value = -1;
		short	ind_ra_add_value = -1;
		short	ind_ra_min_value = -1;
		short	ind_ra_max_value = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "entity_id", &csTmp)) {
		hv_entity_id.len = strlen(csTmp);
		memcpy(hv_entity_id.arr,csTmp,hv_entity_id.len);
DEBUGLOG(("GetMmsRuleCreditLimit entity_id = [%.*s]\n", hv_entity_id.len, hv_entity_id.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetMmsRuleCreditLimit entity_id NOT FOUND!\n"));
ERRLOG("DBMmsRuleCreditLimit::GetMmsRuleCreditLimit entity_id NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "ccy", &csTmp)) {
		hv_ccy.len = strlen(csTmp);
		memcpy(hv_ccy.arr,csTmp,hv_ccy.len);
DEBUGLOG(("GetMmsRuleCreditLimit ccy = [%.*s]\n", hv_ccy.len, hv_ccy.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetMmsRuleCreditLimit ccy NOT FOUND!\n"));
ERRLOG("DBMmsRuleCreditLimit::GetMmsRuleCreditLimit ccy NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "country", &csTmp)) {
		hv_country.len = strlen(csTmp);
		memcpy(hv_country.arr,csTmp,hv_country.len);
DEBUGLOG(("GetMmsRuleCreditLimit country = [%.*s]\n", hv_country.len, hv_country.arr));
	} else {
		iRet = INT_ERR;
DEBUGLOG(("GetMmsRuleCreditLimit country NOT FOUND!\n"));
ERRLOG("DBMmsRuleCreditLimit::GetMmsRuleCreditLimit country NOT FOUND!\n");
	}

	if (GetField_CString(hRls, "txn_code", &csTmp)) {
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
	} else {
		hv_txn_code.len = strlen("000");
		memcpy(hv_txn_code.arr,"000",hv_txn_code.len);
	}
DEBUGLOG(("GetMmsRuleCreditLimit txn_code = [%.*s]\n", hv_txn_code.len, hv_txn_code.arr));

	if (iRet == PD_OK) {
		/* EXEC SQL DECLARE c_getamountid CURSOR FOR
			SELECT	MCL_AMOUNT_ID,
				MRA_TYPE,
				MRA_VALUE,
				MRA_ADD_VALUE,
				MRA_MIN_VALUE,
				MRA_MAX_VALUE,
				MCL_CREDIT_LIMIT_MODE,
				MCL_EFFECT_DATE
			FROM	MMS_RULE_CREDIT_LIMIT,
				MMS_RULE_AMOUNT
			WHERE	MCL_AMOUNT_ID = MRA_ID
			  AND   MRA_DISABLED = 0
			  AND	MCL_CREDIT_LIMIT_MODE = 'T'
			  AND	MCL_ENTITY_ID = :hv_entity_id
			  AND	MCL_CCY = :hv_ccy
			  AND	MCL_COUNTRY = :hv_country
			  AND	MCL_TXN_CODE = :hv_txn_code
			  AND	MCL_DISABLED = 0
			  AND	MCL_EFFECT_DATE < SYSDATE
			UNION
			SELECT	MCL_AMOUNT_ID,
				MRA_TYPE,
				MRA_VALUE,
				MRA_ADD_VALUE,
				MRA_MIN_VALUE,
				MRA_MAX_VALUE,
				MCL_CREDIT_LIMIT_MODE,
				MCL_EFFECT_DATE
			FROM	MMS_RULE_CREDIT_LIMIT,
				MMS_RULE_AMOUNT
			WHERE	MCL_AMOUNT_ID = MRA_ID
			  AND   MRA_DISABLED = 0
			  AND	MCL_CREDIT_LIMIT_MODE = 'E'
			  AND	MCL_ENTITY_ID = :hv_entity_id
			  AND	MCL_CCY = :hv_ccy
			  AND	MCL_COUNTRY = :hv_country
			  AND	MCL_DISABLED = 0
			  AND	MCL_EFFECT_DATE < SYSDATE
			ORDER BY
				MCL_CREDIT_LIMIT_MODE DESC,
				MCL_EFFECT_DATE DESC; */ 


		/* EXEC SQL OPEN c_getamountid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_entity_id;
  sqlstm.sqhstl[0] = (unsigned long )22;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_ccy;
  sqlstm.sqhstl[1] = (unsigned long )5;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )5;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_entity_id;
  sqlstm.sqhstl[4] = (unsigned long )22;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)0;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&hv_ccy;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)0;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&hv_country;
  sqlstm.sqhstl[6] = (unsigned long )4;
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
  if (sqlca.sqlcode < 0) goto geterror;
}


		for (;;) {
			/* EXEC SQL FETCH	c_getamountid
				 INTO	:v_amount_id:ind_amount_id,
					:v_ra_type:ind_ra_type,
					:v_ra_value:ind_ra_value,
					:v_ra_add_value:ind_ra_add_value,
					:v_ra_min_value:ind_ra_min_value,
					:v_ra_max_value:ind_ra_max_value; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 7;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )48;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_amount_id;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_amount_id;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_ra_type;
   sqlstm.sqhstl[1] = (unsigned long )1;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_ra_type;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_ra_value;
   sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_ra_value;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_ra_add_value;
   sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_ra_add_value;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_ra_min_value;
   sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_ra_min_value;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_ra_max_value;
   sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_ra_max_value;
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
   if (sqlca.sqlcode < 0) goto geterror;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
DEBUGLOG(("GetMmsRuleCreditLimit data NOT FOUND!\n"));
			}

			iRet = PD_FOUND;

			if (ind_amount_id >= 0) {
				PutField_Int(myHash, "amount_id", v_amount_id);
DEBUGLOG(("GetMmsRuleCreditLimit amount_id = [%d]\n",v_amount_id));
			}
			if (ind_ra_type >= 0) {
				PutField_Char(myHash, "ra_type", v_ra_type);
DEBUGLOG(("GetMmsRuleCreditLimit ra_type = [%d]\n",v_ra_type));
			}
			if (ind_ra_value >= 0) {
				PutField_Double(myHash, "ra_value", v_ra_value);
DEBUGLOG(("GetMmsRuleCreditLimit ra_value = [%.5f]\n",v_ra_value));
			}
			if (ind_ra_add_value >= 0) {
				PutField_Double(myHash, "ra_add_value", v_ra_add_value);
DEBUGLOG(("GetMmsRuleCreditLimit ra_add_value = [%.5f]\n",v_ra_add_value));
			}
			if (ind_ra_min_value >= 0) {
				PutField_Double(myHash, "ra_min_value", v_ra_min_value);
DEBUGLOG(("GetMmsRuleCreditLimit ra_min_value = [%.5f]\n",v_ra_min_value));
			}
			if (ind_ra_max_value >= 0) {
				PutField_Double(myHash, "ra_max_value", v_ra_max_value);
DEBUGLOG(("GetMmsRuleCreditLimit ra_max_value = [%.5f]\n",v_ra_max_value));
			}

			break; // as always return singal record
		}
		/* EXEC SQL CLOSE c_getamountid; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 7;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )87;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto geterror;
}


	}

DEBUGLOG(("GetMmsRuleCreditLimit Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

geterror:
DEBUGLOG(("getrulecreditlimiterror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsEntityFXBal getrulecreditlimiterror code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
    /* EXEC SQL CLOSE c_getamountid; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 7;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )102;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
    if (sqlca.sqlcode < 0) goto geterror;
}


    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

