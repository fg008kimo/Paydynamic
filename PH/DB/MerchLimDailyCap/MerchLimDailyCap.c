
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "MerchLimDailyCap.pc"
};


static unsigned int sqlctx = 39198667;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,173,0,4,73,0,0,5,3,0,1,0,2,3,0,0,2,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
40,0,0,2,253,0,6,252,0,0,7,7,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,3,
0,0,1,9,0,0,
83,0,0,3,149,0,4,395,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
114,0,0,4,162,0,6,403,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
145,0,0,5,0,0,17,430,0,0,1,1,0,1,0,1,9,0,0,
164,0,0,5,0,0,21,431,0,0,0,0,0,1,0,
179,0,0,6,162,0,6,436,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/09/08              Elvis Wong
Add GetRecord                                      2014/09/26              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MerchLimDailyCap.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MerchLimDailyCap(char    cdebug)
{
        cDebug = cdebug;
}

int GetRecord(hash_t* hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO getrecord_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		int v_disabled;
		double v_daily_cap;

		short ind_merchant_id = -1;
		short ind_service_code = -1;
		short ind_country = -1;
		short ind_disabled = -1;
		short ind_daily_cap = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "merchant_id", &csTmp)) {
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char*)hv_merchant_id.arr, csTmp, sizeof(hv_merchant_id.arr));
		ind_merchant_id = 0;
DEBUGLOG(("GetRecord: merchant_id = [%.*s]\n", hv_merchant_id.len, hv_merchant_id.arr));
	}

	if (GetField_CString(hRls, "service_code", &csTmp)) {
		hv_service_code.len = strlen(csTmp);
		strncpy((char*)hv_service_code.arr, csTmp, sizeof(hv_service_code.arr));
		ind_service_code = 0;
DEBUGLOG(("GetRecord: service_code = [%.*s]\n", hv_service_code.len, hv_service_code.arr));
	}

	if (GetField_CString(hRls, "country", &csTmp)) {
		hv_country.len = strlen(csTmp);
		strncpy((char*)hv_country.arr, csTmp, sizeof(hv_country.arr));
		ind_country = 0;
DEBUGLOG(("GetRecord: country = [%.*s]\n", hv_country.len, hv_country.arr));
	}

	/* EXEC SQL
		SELECT MLDC_DISABLED, MLDC_DAILY_CAP
		INTO :v_disabled:ind_disabled,
			:v_daily_cap:ind_daily_cap
		FROM MERCH_LIM_DAILY_CAP
		WHERE MLDC_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
		AND MLDC_SERVICE_CODE = :hv_service_code:ind_service_code
		AND MLDC_COUNTRY = :hv_country:ind_country; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 5;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select MLDC_DISABLED , MLDC_DAILY_CAP INTO :b0:b1 , :b2:b3 \
FROM MERCH_LIM_DAILY_CAP WHERE MLDC_MERCHANT_ID = :b4:b5 AND MLDC_SERVICE_COD\
E = :b6:b7 AND MLDC_COUNTRY = :b8:b9 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_disabled;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_disabled;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&v_daily_cap;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_daily_cap;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[2] = (unsigned long )17;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_service_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[4] = (unsigned long )4;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_country;
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
 if (sqlca.sqlcode < 0) goto getrecord_error;
}



	if (ind_disabled >= 0 && ind_daily_cap >= 0) {
		PutField_Int(hRls, "org_disabled", v_disabled);
		PutField_Double(hRls, "org_daily_cap", v_daily_cap);
		return FOUND;
	} else {
		return NOT_FOUND;
	}

getrecord_error:
DEBUGLOG(("getrecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

/*
int CheckRecord(const hash_t* hRls)
{
        int iRet = NOT_FOUND;
        char *csTmp;

        EXEC SQL WHENEVER SQLERROR GOTO checkrecord_error;
        EXEC SQL WHENEVER NOTFOUND CONTINUE;

        EXEC SQL BEGIN DECLARE SECTION;
		varchar	hv_merchant_id[PD_MERCHANT_ID_LEN];
		varchar	hv_service_code[PD_SERVICE_CODE_LEN];
		varchar	hv_country[PD_COUNTRY_LEN];
		int v_cnt;
		int v_disabled;

                short   ind_merchant_id = -1;
                short   ind_service_code = -1;
                short   ind_country = -1;

        EXEC SQL END DECLARE SECTION;

        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
                hv_merchant_id.len = strlen(csTmp);
                strncpy((char*)hv_merchant_id.arr,csTmp,sizeof(hv_merchant_id.arr));
                ind_merchant_id = 0;
DEBUGLOG(("CheckRecord: merchant_id = [%.*s](%d)\n",sizeof(hv_merchant_id.arr),hv_merchant_id.arr,hv_merchant_id.len));
        }

        if (GetField_CString(hRls,"service_code",&csTmp)) {
                hv_service_code.len = strlen(csTmp);
                strncpy((char*)hv_service_code.arr,csTmp,sizeof(hv_service_code.arr));
                ind_service_code = 0;
DEBUGLOG(("CheckRecord: service_code = [%.*s](%d)\n",sizeof(hv_service_code.arr),hv_service_code.arr,hv_service_code.len));
        }

        if (GetField_CString(hRls,"country",&csTmp)) {
                hv_country.len = strlen(csTmp);
                strncpy((char*)hv_country.arr,csTmp,sizeof(hv_country.arr));
                ind_country = 0;
DEBUGLOG(("CheckRecord: country = [%.*s](%d)\n",sizeof(hv_country.arr),hv_country.arr,hv_country.len));
        }

        EXEC SQL        SELECT  COUNT(*)
                        INTO    :v_cnt
                        FROM    MERCH_LIM_DAILY_CAP
                        WHERE   MLDC_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
                        AND     MLDC_SERVICE_CODE = :hv_service_code:ind_service_code
                        AND     MLDC_COUNTRY = :hv_country:ind_country;

        if (v_cnt>0) {
		EXEC SQL	SELECT	MLDC_DISABLED
				INTO	:v_disabled
				FROM	MERCH_LIM_DAILY_CAP
                        	WHERE   MLDC_MERCHANT_ID = :hv_merchant_id:ind_merchant_id
                        	AND     MLDC_SERVICE_CODE = :hv_service_code:ind_service_code
                        	AND     MLDC_COUNTRY = :hv_country:ind_country;

		if (v_disabled == 1) {
                	iRet = FOUND_DISABLED;
DEBUGLOG(("CheckRecord() FOUND_DISABLED\n"));
		} else {
			iRet = FOUND;
DEBUGLOG(("CheckRecord() FOUND\n"));
		}
        } else {
                iRet = NOT_FOUND;
DEBUGLOG(("CheckRecord() NOT FOUND\n"));
        }

DEBUGLOG(("CheckRecord() Normal Exit! iRet = [%d]\n", iRet));
        return iRet;

checkrecord_error:
DEBUGLOG(("checkrecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        EXEC SQL WHENEVER SQLERROR CONTINUE;
        return PD_ERR;
}
*/

int Add(const hash_t *hMerchLimDailyCap)
{
	char            *csTmp;
	int		iTmp;
	double		dTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		double          hv_daily_cap;
		int		hv_disabled;
		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


		short		ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_country = -1;
		short		ind_daily_cap = -1;
		short		ind_disabled = -1;
		short		ind_create_user = -1;
		
		short           hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hMerchLimDailyCap,"merchant_id",&csTmp))
	{
		hv_merchant_id.len = strlen(csTmp);
		strncpy((char *)hv_merchant_id.arr, csTmp, hv_merchant_id.len);
		ind_merchant_id = 0;
	}
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	if(GetField_CString(hMerchLimDailyCap,"service_code",&csTmp))
	{
		hv_service_code.len = strlen(csTmp);
		strncpy((char *)hv_service_code.arr, csTmp, hv_service_code.len);
		ind_service_code = 0;
	}
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	if(GetField_CString(hMerchLimDailyCap,"country",&csTmp))
	{
		hv_country.len = strlen(csTmp);
		strncpy((char *)hv_country.arr, csTmp, hv_country.len);
		ind_country = 0;
	}
DEBUGLOG(("Add:country = [%.*s]\n",hv_country.len,hv_country.arr));

	if(GetField_Double(hMerchLimDailyCap,"daily_cap",&dTmp)) {
                hv_daily_cap = dTmp;
                ind_daily_cap= 0;
DEBUGLOG(("Add:daily_cap = [%lf]\n",hv_daily_cap));
        }

	if (GetField_Int(hMerchLimDailyCap,"disabled", &iTmp)) 
	{
		hv_disabled = iTmp;
		ind_disabled = 0;
	}
DEBUGLOG(("Add:disabled = [%d]\n",hv_disabled));

	if(GetField_CString(hMerchLimDailyCap,"create_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
	    BEGIN

		:hv_return_value := sp_merch_lim_daily_cap_insert(
				:hv_merchant_id:ind_merchant_id,
				:hv_service_code:ind_service_code,
				:hv_country:ind_country,
				:hv_daily_cap:ind_daily_cap,
				:hv_disabled:ind_disabled,
				:hv_create_user:ind_create_user);


	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_merch_lim_daily_cap_insert ( :\
hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , :hv_coun\
try:ind_country , :hv_daily_cap:ind_daily_cap , :hv_disabled:ind_disabled , :\
hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )40;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_service_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_daily_cap;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_daily_cap;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_disabled;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_disabled;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[6] = (unsigned long )22;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto add_error;
}



DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("Add:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MerchLimDailyCap_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("MerchLimDailyCap_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int Update(const hash_t *hRls)
{
	char 	*csMid = NULL;
	char 	*csServiceCode = NULL;
	char 	*csCountry = NULL;
	
	char 	*csTmp = NULL;
	double	dTmp;
	int	iTmp;
		
        char    *csBuf;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar       	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		int	   	v_cnt;

		short		ind_merchant_id = -1;
		short		ind_service_code = -1;
		short		ind_country = -1;
		short 		hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char *)malloc(128);

        strcpy((char*)hv_dynstmt.arr,"update merch_lim_daily_cap set mldc_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/*daily_cap*/
        if (GetField_Double(hRls,"daily_cap",&dTmp)) {
DEBUGLOG(("Update:update_daily_cap = [%lf]\n",dTmp));
               	sprintf(csBuf,"%lf",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mldc_daily_cap = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*disabled*/
        if (GetField_Int(hRls,"disabled",&iTmp)) {
DEBUGLOG(("Update:update_disabled = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mldc_disabled = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*update_user*/
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mldc_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*Primary Key: merchant_id*/	
	GetField_CString(hRls,"merchant_id",&csMid);
DEBUGLOG(("Update:merchant_id = [%s]\n",csMid));
    	strcat((char*)hv_dynstmt.arr, " WHERE mldc_merchant_id = '");
     	strcat((char*)hv_dynstmt.arr, csMid);
       	strcat((char*)hv_dynstmt.arr, "'");
      	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	hv_merchant_id.len = strlen(csMid);
       	strncpy((char*)hv_merchant_id.arr, csMid, hv_merchant_id.len);
       	ind_merchant_id = 0;

/*Primary Key: service_code*/
	GetField_CString(hRls,"service",&csServiceCode);
DEBUGLOG(("Update:service = [%s]\n",csServiceCode));
       	strcat((char*)hv_dynstmt.arr, " AND mldc_service_code = '");
       	strcat((char*)hv_dynstmt.arr, csServiceCode);
       	strcat((char*)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	hv_service_code.len = strlen(csServiceCode);
       	strncpy((char*)hv_service_code.arr, csServiceCode, hv_service_code.len);
       	ind_service_code = 0;

/*Primary Key: country*/
	GetField_CString(hRls,"country",&csCountry);
DEBUGLOG(("Update:country = [%s]\n",csCountry));
       	strcat((char*)hv_dynstmt.arr, " AND mldc_country = '");
       	strcat((char*)hv_dynstmt.arr, csCountry);
       	strcat((char*)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

	hv_country.len = strlen(csCountry);
       	strncpy((char*)hv_country.arr, csCountry, hv_country.len);
       	ind_country = 0;
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

/* add into log */        
	/* EXEC SQL SELECT count(*)
                INTO :v_cnt
                FROM merch_lim_daily_cap_log
                WHERE mldcl_merchant_id = :hv_merchant_id:ind_merchant_id
		AND   mldcl_service_code = :hv_service_code:ind_service_code
		AND   mldcl_country = :hv_country:ind_country; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 7;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( * ) INTO :b0 FROM merch_lim_daily_cap_log WH\
ERE mldcl_merchant_id = :b1:b2 AND mldcl_service_code = :b3:b4 AND mldcl_coun\
try = :b5:b6 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )83;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_service_code;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_country;
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
 if (sqlca.sqlcode < 0) goto update_error;
}



        if (v_cnt == 0) {
                /* EXEC SQL EXECUTE
                        BEGIN
                                :hv_return_value := sp_merch_lim_dy_cap_log_insert(
                                        :hv_merchant_id:ind_merchant_id,
					:hv_service_code:ind_service_code,
					:hv_country:ind_country);
                        END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 7;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_merch_lim_dy_ca\
p_log_insert ( :hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service\
_code , :hv_country:ind_country ) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )114;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )17;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_service_code;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
                sqlstm.sqhstl[3] = (unsigned long )4;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_country;
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
                if (sqlca.sqlcode < 0) goto update_error;
}


	
		if (hv_return_value == SP_OK)
                {
DEBUGLOG(("Add Orig Log: Normal Exit\n"));
                }

                if (hv_return_value == SP_OTHER_ERR)
                {
DEBUGLOG(("Add Orig Log: SP_OTHER_ERR\n"));
                        return PD_OTHER_ERR;
                }

                if (hv_return_value == SP_ERR)
                {
DEBUGLOG(("Add Orig Log: SP_ERR\n"));
                        return PD_ERR;
                }
	}

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )145;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )164;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

/* update log */
        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_merch_lim_dy_cap_log_insert(
                                        :hv_merchant_id:ind_merchant_id,
					:hv_service_code:ind_service_code,
					:hv_country:ind_country);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 7;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_merch_lim_dy_cap_log_in\
sert ( :hv_merchant_id:ind_merchant_id , :hv_service_code:ind_service_code , \
:hv_country:ind_country ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )179;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_service_code;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_country;
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
        if (sqlca.sqlcode < 0) goto update_error;
}



        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Update: Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)
        {
DEBUGLOG(("Update: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)
        {
DEBUGLOG(("Update: SP_ERR\n"));
                return PD_ERR;
        }

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MerchLimDailyCap:Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

