
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
           char  filnam[30];
};
static struct sqlcxp sqlfpn =
{
    29,
    "handle_remain_reserved_amt.pc"
};


static unsigned int sqlctx = 512590869;


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
   unsigned char  *sqhstv[6];
   unsigned long  sqhstl[6];
            int   sqhsts[6];
            short *sqindv[6];
            int   sqinds[6];
   unsigned long  sqharm[6];
   unsigned long  *sqharc[6];
   unsigned short  sqadto[6];
   unsigned short  sqtdso[6];
} sqlstm = {12,6};

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
"SELECT mr_merchant_id , mr_currency_id , mr_country_id , mr_service_code , \
mr_day_of_week , to_char ( mr_effect_date , 'YYYYMMDDHH24MISS' ) FROM merchan\
t_reserved_amt WHERE mr_type = 'D' AND mr_status = 'A' AND mr_day_of_week <= \
6 AND mr_reserved_amount != mr_remain_reserved_amount GROUP BY mr_merchant_id\
 , mr_currency_id , mr_country_id , mr_service_code , mr_day_of_week , to_cha\
r ( mr_effect_date , 'YYYYMMDDHH24MISS' ) ORDER BY mr_merchant_id , mr_curren\
cy_id , mr_country_id , mr_service_code , mr_day_of_week , to_char ( mr_effec\
t_date , 'YYYYMMDDHH24MISS' )            ";

 static char *sq0003 = 
"SELECT omr_merchant_id , omr_currency_id , omr_country_id , omr_service_cod\
e , omr_day_of_week , to_char ( omr_effect_date , 'YYYYMMDDHH24MISS' ) FROM o\
l_merchant_reserved_amt WHERE omr_type = 'D' AND omr_status = 'A' AND omr_day\
_of_week <= 6 AND omr_reserved_amount != omr_remain_reserved_amount GROUP BY \
omr_merchant_id , omr_currency_id , omr_country_id , omr_service_code , omr_d\
ay_of_week , to_char ( omr_effect_date , 'YYYYMMDDHH24MISS' ) ORDER BY omr_me\
rchant_id , omr_currency_id , omr_country_id , omr_service_code , omr_day_of_\
week , to_char ( omr_effect_date , 'YYYYMMDDHH24MISS' )            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,0,0,0,56,98,0,0,1,1,0,1,0,3,102,0,0,
24,0,0,1,578,0,9,113,0,2049,0,0,0,1,0,
39,0,0,1,0,0,13,115,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,
0,0,
78,0,0,1,0,0,15,208,0,0,0,0,0,1,0,
93,0,0,1,0,0,15,219,0,0,0,0,0,1,0,
108,0,0,2,0,0,32,220,0,0,0,0,0,1,0,
123,0,0,0,0,0,56,259,0,0,1,1,0,1,0,3,102,0,0,
142,0,0,3,604,0,9,274,0,2049,0,0,0,1,0,
157,0,0,3,0,0,13,276,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,
0,0,
196,0,0,1,0,0,15,369,0,0,0,0,0,1,0,
211,0,0,3,0,0,15,380,0,0,0,0,0,1,0,
226,0,0,4,0,0,32,381,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/09/27              Virginia Yun
Add Offline Daily Cap				   2014/01/27		   LokMan Chow
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"
#include "ObjPtr.h"
#include "dates.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug = 'Y';


OBJPTR(Txn);
OBJPTR(Channel);
OBJPTR(DB);

int handle_online_reserved();
int handle_offline_reserved();


int batch_init(int argc, char* argv[])
{

	return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;

	iRet = handle_online_reserved();

	if(iRet==SUCCESS){
		handle_offline_reserved();
	}
	
	return iRet;
}


int handle_online_reserved()
{
        int     iRet = SUCCESS;

	double	dDailyCap = 0.0;
	double	dRemainDailyCap = 0.0;

	hash_t	*hTxn;
	hTxn = (hash_t *)malloc(sizeof(hash_t));

DEBUGLOG(("handle_online_reserved()\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_currency_id[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

		/* varchar		v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		int		v_day_of_week;
		/* varchar		v_effect_date[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_effect_date;


		short		ind_merchant_id = -1;
		short		ind_currency_id = -1;
		short		ind_country_id = -1;
		short		ind_service_code = -1;
		short		ind_day_of_week = -1;
		short		ind_effect_date = -1;

		SQL_CURSOR	ref_cur;

	/* EXEC SQL END DECLARE SECTION; */ 
	

	/* EXEC SQL ALLOCATE :ref_cur; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&ref_cur;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}



	/* EXEC SQL DECLARE c_cursor_reserved_amt CURSOR FOR
		SELECT mr_merchant_id, mr_currency_id, mr_country_id, mr_service_code, 
			mr_day_of_week, to_char(mr_effect_date, 'YYYYMMDDHH24MISS')
  		  FROM merchant_reserved_amt
                 WHERE mr_type = 'D'
                   AND mr_status = 'A'
		   AND mr_day_of_week <=6
                   AND mr_reserved_amount!= mr_remain_reserved_amount
              GROUP BY mr_merchant_id, mr_currency_id, mr_country_id, mr_service_code, 
			mr_day_of_week,to_char(mr_effect_date, 'YYYYMMDDHH24MISS') 
              ORDER BY mr_merchant_id, mr_currency_id, mr_country_id, mr_service_code, 
			mr_day_of_week, to_char(mr_effect_date, 'YYYYMMDDHH24MISS'); */ 


	/* EXEC SQL OPEN c_cursor_reserved_amt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )24;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_reserved_amt
                INTO
                        :v_merchant_id:ind_merchant_id,
			:v_currency_id:ind_currency_id,
                        :v_country_id:ind_country_id,
                        :v_service_code:ind_service_code,
                        :v_day_of_week:ind_day_of_week,
			:v_effect_date:ind_effect_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )39;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_currency_id;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_currency_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_country_id;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_day_of_week;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_day_of_week;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_effect_date;
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_effect_date;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
		} else {
			v_merchant_id.arr[0] = '\0';
		}

		if (ind_currency_id >= 0) {
			v_currency_id.arr[v_currency_id.len] = '\0';
		} else  {
			v_currency_id.arr[0] = '\0';
		}

		if (ind_country_id >= 0) {
			v_country_id.arr[v_country_id.len] = '\0';
		} else {
			v_country_id.arr[0] = '\0';
		}	
		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';
		} else {
			v_service_code.arr[0] = '\0';
		}

		if (ind_day_of_week < 0) {
			v_day_of_week = 0;
		}

		if (ind_effect_date >= 0) {
			v_effect_date.arr[v_effect_date.len] = '\0';
		} else {
			v_effect_date.arr[0] = '\0';
		}

DEBUGLOG(("merchant id = [%s] currency = [%s] country = [%s] service_code [%s] day_of_week [%d] effect_date [%s]\n",v_merchant_id.arr, v_currency_id.arr, v_country_id.arr, v_service_code.arr, v_day_of_week, v_effect_date.arr));


		DBObjPtr = CreateObj(DBPtr,"DBMerchantReservedAmt","GetSpecificDailyCapforUpdate");
		if((unsigned long) ((*DBObjPtr)(v_merchant_id.arr, v_country_id.arr, v_currency_id.arr, 
                                                v_service_code.arr, v_day_of_week, v_effect_date.arr,
                                                &dDailyCap, &dRemainDailyCap))==PD_OK) {

DEBUGLOG(("DailyCap [%lf] RemainDailyCap [%lf]\n", dDailyCap, dRemainDailyCap));
			if (dDailyCap != dRemainDailyCap) {

DEBUGLOG(("Prepare RESET \n"));

				hash_init(hTxn, 0);
			
				PutField_CString(hTxn, "merchant_id", (const char *) v_merchant_id.arr);
				PutField_CString(hTxn, "txn_ccy", (const char *) v_currency_id.arr);
				PutField_CString(hTxn, "txn_country", (const char *) v_country_id.arr);
				PutField_CString(hTxn, "service_code", (const char *) v_service_code.arr);
				PutField_Int(hTxn, "dow", v_day_of_week);
				PutField_Char(hTxn, "amt_type", PD_RES_AMT_DAILY_CAP);
				PutField_Char(hTxn, "status", PD_RES_AMT_STATUS_APPROVE);
				PutField_CString(hTxn, "effect_date", (const char *)v_effect_date.arr);
				PutField_Double(hTxn, "remain_daily_cap", dDailyCap); // as set dailyCap as Remaining
				PutField_CString(hTxn, "update_user", PD_UPDATE_USER);

				DBObjPtr = CreateObj(DBPtr,"DBMerchantReservedAmt","UpdateAmt");
				if((unsigned long) ((*DBObjPtr)(hTxn))==PD_OK) {
DEBUGLOG(("Prepare COMPLETE\n"));
					TxnCommit();
		
				} else {
DEBUGLOG(("UpdateAmt Failure\n"));
ERRLOG("handle_remain_reserved_amt: UpdateAmt Failure\n");
					iRet = FAILURE;
				}

			}

		}  else {
DEBUGLOG(("GetDailyCapforUpdate Failure\n"));
ERRLOG("handle_remain_reserved_amt: GetDailyCapforUpdate Failure\n");
			iRet = FAILURE;
		}

	} while (PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_reserved_amt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )78;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



DEBUGLOG(("handle_online_reserved iRet = [%d]\n",iRet));


	return iRet;

sql_error:
DEBUGLOG(("sql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_reserved_amt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )93;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL ROLLBACK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )108;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAILURE;
}


int handle_offline_reserved()
{
        int     iRet = SUCCESS;

	double	dDailyCap = 0.0;
	double	dRemainDailyCap = 0.0;

	hash_t	*hTxn;
	hTxn = (hash_t *)malloc(sizeof(hash_t));

DEBUGLOG(("handle_offline_reserved()\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO offsql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 
	
		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_currency_id[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

		/* varchar		v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		int		v_day_of_week;
		/* varchar		v_effect_date[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_effect_date;


		short		ind_merchant_id = -1;
		short		ind_currency_id = -1;
		short		ind_country_id = -1;
		short		ind_service_code = -1;
		short		ind_day_of_week = -1;
		short		ind_effect_date = -1;

		SQL_CURSOR	ref_cur;

	/* EXEC SQL END DECLARE SECTION; */ 
	

	/* EXEC SQL ALLOCATE :ref_cur; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )123;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&ref_cur;
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
 if (sqlca.sqlcode < 0) goto offsql_error;
}



	/* EXEC SQL DECLARE c_cursor_ofl_reserved_amt CURSOR FOR
		SELECT omr_merchant_id, omr_currency_id, omr_country_id, omr_service_code, 
			omr_day_of_week, to_char(omr_effect_date, 'YYYYMMDDHH24MISS')
  		  FROM ol_merchant_reserved_amt
                 WHERE omr_type = 'D'
                   AND omr_status = 'A'
		   AND omr_day_of_week <=6
                   AND omr_reserved_amount!= omr_remain_reserved_amount
              GROUP BY omr_merchant_id, omr_currency_id, omr_country_id, omr_service_code, 
			omr_day_of_week,to_char(omr_effect_date, 'YYYYMMDDHH24MISS') 
              ORDER BY omr_merchant_id, omr_currency_id, omr_country_id, omr_service_code, 
			omr_day_of_week, to_char(omr_effect_date, 'YYYYMMDDHH24MISS'); */ 


	/* EXEC SQL OPEN c_cursor_ofl_reserved_amt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )142;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto offsql_error;
}


        do {
		/* EXEC SQL FETCH c_cursor_ofl_reserved_amt
                INTO
                        :v_merchant_id:ind_merchant_id,
			:v_currency_id:ind_currency_id,
                        :v_country_id:ind_country_id,
                        :v_service_code:ind_service_code,
                        :v_day_of_week:ind_day_of_week,
			:v_effect_date:ind_effect_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 6;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )157;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_currency_id;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_currency_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_country_id;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_country_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_day_of_week;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_day_of_week;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_effect_date;
  sqlstm.sqhstl[5] = (unsigned long )17;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_effect_date;
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
  if (sqlca.sqlcode < 0) goto offsql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
		} else {
			v_merchant_id.arr[0] = '\0';
		}

		if (ind_currency_id >= 0) {
			v_currency_id.arr[v_currency_id.len] = '\0';
		} else  {
			v_currency_id.arr[0] = '\0';
		}

		if (ind_country_id >= 0) {
			v_country_id.arr[v_country_id.len] = '\0';
		} else {
			v_country_id.arr[0] = '\0';
		}	
		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';
		} else {
			v_service_code.arr[0] = '\0';
		}

		if (ind_day_of_week < 0) {
			v_day_of_week = 0;
		}

		if (ind_effect_date >= 0) {
			v_effect_date.arr[v_effect_date.len] = '\0';
		} else {
			v_effect_date.arr[0] = '\0';
		}

DEBUGLOG(("merchant id = [%s] currency = [%s] country = [%s] service_code [%s] day_of_week [%d] effect_date [%s]\n",v_merchant_id.arr, v_currency_id.arr, v_country_id.arr, v_service_code.arr, v_day_of_week, v_effect_date.arr));


		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantReservedAmt","GetSpecificDailyCapforUpdate");
		if((unsigned long) ((*DBObjPtr)(v_merchant_id.arr, v_country_id.arr, v_currency_id.arr, 
                                                v_service_code.arr, v_day_of_week, v_effect_date.arr,
                                                &dDailyCap, &dRemainDailyCap))==PD_OK) {

DEBUGLOG(("DailyCap [%lf] RemainDailyCap [%lf]\n", dDailyCap, dRemainDailyCap));
			if (dDailyCap != dRemainDailyCap) {

DEBUGLOG(("Prepare RESET \n"));

				hash_init(hTxn, 0);
			
				PutField_CString(hTxn, "merchant_id", (const char *) v_merchant_id.arr);
				PutField_CString(hTxn, "txn_ccy", (const char *) v_currency_id.arr);
				PutField_CString(hTxn, "txn_country", (const char *) v_country_id.arr);
				PutField_CString(hTxn, "service_code", (const char *) v_service_code.arr);
				PutField_Int(hTxn, "dow", v_day_of_week);
				PutField_Char(hTxn, "amt_type", PD_RES_AMT_DAILY_CAP);
				PutField_Char(hTxn, "status", PD_RES_AMT_STATUS_APPROVE);
				PutField_CString(hTxn, "effect_date", (const char *)v_effect_date.arr);
				PutField_Double(hTxn, "remain_daily_cap", dDailyCap); // as set dailyCap as Remaining
				PutField_CString(hTxn, "update_user", PD_UPDATE_USER);

				DBObjPtr = CreateObj(DBPtr,"DBOLMerchantReservedAmt","UpdateAmt");
				if((unsigned long) ((*DBObjPtr)(hTxn))==PD_OK) {
DEBUGLOG(("Prepare COMPLETE\n"));
					TxnCommit();
		
				} else {
DEBUGLOG(("UpdateAmt Failure\n"));
ERRLOG("handle_remain_reserved_amt: UpdateAmt Failure\n");
					iRet = FAILURE;
				}

			}

		}  else {
DEBUGLOG(("GetDailyCapforUpdate Failure\n"));
ERRLOG("handle_remain_reserved_amt: GetDailyCapforUpdate Failure\n");
			iRet = FAILURE;
		}

	} while (PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_reserved_amt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )196;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto offsql_error;
}



DEBUGLOG(("handle_offline_reserved iRet = [%d]\n",iRet));


	return iRet;

offsql_error:
DEBUGLOG(("offsql_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_ofl_reserved_amt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )211;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        /* EXEC SQL ROLLBACK RELEASE; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )226;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return FAILURE;
}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}




