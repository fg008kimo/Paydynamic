
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
           char  filnam[16];
};
static struct sqlcxp sqlfpn =
{
    15,
    "ExchangeRate.pc"
};


static unsigned int sqlctx = 2416419;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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
"SELECT ex_rate , ex_bid , ex_max_ask , ex_med_ask , ex_min_ask , ex_max_bid\
 , ex_med_bid , ex_min_bid , ex_minmax_src2dst , ex_meanminmax_src2dst FROM e\
xchange_rate WHERE ex_from_ccy_id = :b0 AND ex_to_ccy_id = :b1 AND ex_effect_\
date = ( SELECT max ( ex_effect_date ) FROM exchange_rate WHERE ex_from_ccy_i\
d = :b0 AND ex_to_ccy_id = :b1 AND ex_effect_date <= sysdate )            ";

 static char *sq0003 = 
"SELECT ex_rate , ex_bid , ex_max_ask , ex_med_ask , ex_min_ask , ex_max_bid\
 , ex_med_bid , ex_min_bid , ex_minmax_src2dst , ex_meanminmax_src2dst FROM (\
 SELECT * FROM exchange_rate WHERE ex_from_ccy_id = :b0 AND ex_to_ccy_id = :b\
1 AND ex_effect_date < to_date ( :b2 , 'YYYYMMDD' ) + 1 ORDER BY ex_effect_da\
te DESC ) WHERE rownum < 2            ";

 static char *sq0004 = 
"SELECT ex_rate , ex_bid , ex_max_ask , ex_med_ask , ex_min_ask , ex_max_bid\
 , ex_med_bid , ex_min_bid , ex_minmax_src2dst , ex_meanminmax_src2dst FROM e\
xchange_rate WHERE ex_from_ccy_id = :b0 AND ex_to_ccy_id = :b1 AND ex_effect_\
date = ( SELECT max ( ex_effect_date ) FROM exchange_rate WHERE ex_from_ccy_i\
d = :b0 AND ex_to_ccy_id = :b1 AND ex_effect_date < to_date ( :b4 , 'YYYYMMDD\
HH24MISS' ) )            ";

 static char *sq0005 = 
"SELECT ex_from_ccy_id , ex_to_ccy_id , ex_rate , ex_bid , ex_max_ask , ex_m\
ed_ask , ex_min_ask , ex_max_bid , ex_med_bid , ex_min_bid , ex_minmax_src2ds\
t , ex_meanminmax_src2dst FROM ( SELECT ex_from_ccy_id , ex_to_ccy_id , ex_ra\
te , ex_bid , ex_max_ask , ex_med_ask , ex_min_ask , ex_max_bid , ex_med_bid \
, ex_min_bid , ex_minmax_src2dst , ex_meanminmax_src2dst , ex_effect_date , r\
ow_number ( ) over ( partition by ex_from_ccy_id , ex_to_ccy_id order by ex_e\
ffect_date desc ) xx FROM exchange_rate WHERE ex_effect_date < to_date ( :b0 \
, 'YYYYMMDD' ) + 1 ) WHERE xx = 1            ";

 static char *sq0006 = 
"SELECT ex_from_ccy_id , ex_to_ccy_id , effect_date , ex_rate , ex_bid , ex_\
max_ask , ex_med_ask , ex_min_ask , ex_max_bid , ex_med_bid , ex_min_bid , ex\
_minmax_src2dst , ex_meanminmax_src2dst FROM ( SELECT ex_from_ccy_id , ex_to_\
ccy_id , to_char ( ( ex_effect_date ) , 'MM-DD-YYYY HH24:MI:SS' ) as effect_d\
ate , ex_rate , ex_bid , ex_max_ask , ex_med_ask , ex_min_ask , ex_max_bid , \
ex_med_bid , ex_min_bid , ex_minmax_src2dst , ex_meanminmax_src2dst , row_num\
ber ( ) over ( partition by ex_from_ccy_id , ex_to_ccy_id order by ex_effect_\
date desc ) FROM exchange_rate WHERE ex_effect_date >= to_date ( :b0 , 'YYYYM\
MDD' ) AND ex_effect_date < to_date ( :b0 , 'YYYYMMDD' ) + 1 ) ORDER BY ex_fr\
om_ccy_id , ex_to_ccy_id , effect_date desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,477,0,6,190,0,0,15,15,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,
4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
80,0,0,2,380,0,9,305,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
111,0,0,2,0,0,13,307,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
166,0,0,2,0,0,15,398,0,0,0,0,0,1,0,
181,0,0,2,0,0,15,407,0,0,0,0,0,1,0,
196,0,0,3,344,0,9,504,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
223,0,0,3,0,0,13,506,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
278,0,0,3,0,0,15,597,0,0,0,0,0,1,0,
293,0,0,3,0,0,15,606,0,0,0,0,0,1,0,
308,0,0,4,408,0,9,681,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
343,0,0,4,0,0,13,683,0,0,10,0,0,1,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
398,0,0,4,0,0,15,774,0,0,0,0,0,1,0,
413,0,0,4,0,0,15,783,0,0,0,0,0,1,0,
428,0,0,5,582,0,9,864,0,2049,1,1,0,1,0,1,9,0,0,
447,0,0,5,0,0,13,866,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
510,0,0,5,0,0,15,979,0,0,0,0,0,1,0,
525,0,0,5,0,0,15,988,0,0,0,0,0,1,0,
540,0,0,6,746,0,9,1077,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
563,0,0,6,0,0,13,1079,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
630,0,0,6,0,0,15,1201,0,0,0,0,0,1,0,
645,0,0,6,0,0,15,1210,0,0,0,0,0,1,0,
660,0,0,7,110,0,6,1239,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/08/27              Cody Chan
Added "GetExchangeRateByDate"			   2011/07/15		   Simon Fung
Modify GetExchangeRateByDate SQL tuning		   2015/08/07		   Dirk Wong
    Added GetAllExchangeRateByDate
Added GetAllExchangeRateByExactDate,		   2018/06/14              Elvis Wong
      DeleteDuplicateExchangeRateByExactDate	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "ExchangeRate.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void ExchangeRate(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t *hExr)
{
	char            *csTmp;
	double          dTmp;
	//int		iDateTimeLen = strlen("yyyymmddhh:mi:ss");

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

		/* varchar 	hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;

		/* varchar 	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar 	hv_effect_date[21]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_effect_date;


		double		hv_rate;
		double 		hv_bid;
		double 		hv_max_bid;
		double 		hv_med_bid;
		double 		hv_min_bid;
		double 		hv_max_ask;
		double 		hv_med_ask;
		double 		hv_min_ask;
		double 		hv_min_max;
		double 		hv_mean_min_max;


		short 		ind_from_ccy_id = -1;
		short 		ind_to_ccy_id = -1;
		short 		ind_create_user = -1;
		short 		ind_effect_date = -1;
		short 		ind_hv_rate = -1;
		short 		ind_hv_bid = -1;
		short 		ind_hv_max_bid = -1;
		short 		ind_hv_med_bid = -1;
		short 		ind_hv_min_bid = -1;
		short 		ind_hv_max_ask = -1;
		short 		ind_hv_med_ask = -1;
		short 		ind_hv_min_ask = -1;
		short 		ind_hv_min_max = -1;
		short 		ind_hv_mean_min_max = -1;

		short 		hv_return_value;

	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

	if(GetField_CString(hExr,"from_ccy_id", &csTmp))
	{
		hv_from_ccy_id.len = strlen(csTmp);
		strncpy((char *)hv_from_ccy_id.arr, csTmp, hv_from_ccy_id.len);
		ind_from_ccy_id = 0;
DEBUGLOG(("Add:from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));
	}

	if(GetField_CString(hExr,"to_ccy_id", &csTmp))
	{
		hv_to_ccy_id.len = strlen(csTmp);
		strncpy((char *)hv_to_ccy_id.arr, csTmp, hv_to_ccy_id.len);
		ind_to_ccy_id = 0;
DEBUGLOG(("Add:to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));
	}

	if(GetField_CString(hExr,"effect_date", &csTmp))
	{
		hv_effect_date.len = strlen(csTmp);
		strncpy((char *)hv_effect_date.arr, csTmp, hv_effect_date.len);
		ind_effect_date = 0;
DEBUGLOG(("Add:effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));
	}

	if(GetField_CString(hExr,"create_user", &csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));
	}

	if(GetField_Double(hExr,"rate", &dTmp))
	{
		hv_rate = dTmp;
		ind_hv_rate = 0;
DEBUGLOG(("Add:rate = [%f]\n",hv_rate));
	}

	if(GetField_Double(hExr,"bid", &dTmp))
	{
		hv_bid = dTmp;
		ind_hv_bid = 0;
DEBUGLOG(("Add:bid = [%f]\n",hv_bid));
	}

	if(GetField_Double(hExr,"max_bid", &dTmp))
	{
		hv_max_bid = dTmp;
		ind_hv_max_bid = 0;
DEBUGLOG(("Add:max_bid = [%f]\n",hv_max_bid));
	}

	if(GetField_Double(hExr,"med_bid", &dTmp))
	{
		hv_med_bid = dTmp;
		ind_hv_med_bid = 0;
DEBUGLOG(("Add:med_bid = [%f]\n",hv_med_bid));
	}

	if(GetField_Double(hExr,"min_bid", &dTmp))
	{
		hv_min_bid = dTmp;
		ind_hv_min_bid = 0;
DEBUGLOG(("Add:min_bid = [%f]\n",hv_min_bid));
	}

	if(GetField_Double(hExr,"max_ask", &dTmp))
	{
		hv_max_ask = dTmp;
		ind_hv_max_ask = 0;
DEBUGLOG(("Add:max_ask = [%f]\n",hv_max_ask));
	}

	if(GetField_Double(hExr,"med_ask", &dTmp))
	{
		hv_med_ask = dTmp;
		ind_hv_med_ask = 0;
DEBUGLOG(("Add:med_ask = [%f]\n",hv_med_ask));
	}

	if(GetField_Double(hExr,"min_ask", &dTmp))
	{
		hv_min_ask = dTmp;
		ind_hv_min_ask = 0;
DEBUGLOG(("Add:min_ask = [%f]\n",hv_min_ask));
	}

	if(GetField_Double(hExr,"min_max", &dTmp))
	{
		hv_min_max = dTmp;
		ind_hv_min_max = 0;
DEBUGLOG(("Add:min_max = [%f]\n",hv_min_max));
	}

	if(GetField_Double(hExr,"mean_min_max", &dTmp))
	{
		hv_mean_min_max = dTmp;
		ind_hv_mean_min_max = 0;
DEBUGLOG(("Add:mean_min_max = [%f]\n",hv_mean_min_max));
	}

	FREE_ME(csTmp);


	/* EXEC SQL EXECUTE
	    BEGIN
		:hv_return_value := sp_exchange_rate_insert(
				:hv_from_ccy_id:ind_from_ccy_id,
				:hv_to_ccy_id:ind_to_ccy_id,
				:hv_rate:ind_hv_rate,
				:hv_bid:ind_hv_bid,
				:hv_max_ask:ind_hv_max_ask,
				:hv_med_ask:ind_hv_med_ask,
				:hv_min_ask:ind_hv_min_ask,
				:hv_max_bid:ind_hv_max_bid,
				:hv_med_bid:ind_hv_med_bid,
				:hv_min_bid:ind_hv_min_bid,
				:hv_mean_min_max:ind_hv_mean_min_max,
				:hv_min_max:ind_hv_min_max,
				:hv_effect_date:ind_effect_date,
				:hv_create_user:ind_create_user);

	    END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_exchange_rate_insert ( :hv_fro\
m_ccy_id:ind_from_ccy_id , :hv_to_ccy_id:ind_to_ccy_id , :hv_rate:ind_hv_rate\
 , :hv_bid:ind_hv_bid , :hv_max_ask:ind_hv_max_ask , :hv_med_ask:ind_hv_med_a\
sk , :hv_min_ask:ind_hv_min_ask , :hv_max_bid:ind_hv_max_bid , :hv_med_bid:in\
d_hv_med_bid , :hv_min_bid:ind_hv_min_bid , :hv_mean_min_max:ind_hv_mean_min_\
max , :hv_min_max:ind_hv_min_max , :hv_effect_date:ind_effect_date , :hv_crea\
te_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_from_ccy_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_ccy_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_to_ccy_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_rate;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_hv_rate;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bid;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_hv_bid;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_max_ask;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_hv_max_ask;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_med_ask;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_hv_med_ask;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_min_ask;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_hv_min_ask;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_max_bid;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_hv_max_bid;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_med_bid;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_hv_med_bid;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_min_bid;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_hv_min_bid;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_mean_min_max;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_hv_mean_min_max;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_min_max;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_hv_min_max;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[13] = (unsigned long )23;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_effect_date;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[14] = (unsigned long )22;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_create_user;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
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
		ERRLOG("ExchangeRate_Add: SP_OTHER_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
		ERRLOG("ExchangeRate_Add: SP_ERR TxnAbort\n");
		DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

add_error:
	DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;

}


int GetExchangeRate(const char* csFromCcyId, const char* csToCcyId, hash_t* hRec)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO getexchangerate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

		/* varchar		hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;



		double		v_rate;
		double		v_bid;
		double		v_max_bid;
                double          v_med_bid;
                double          v_min_bid;
                double          v_max_ask;
                double          v_med_ask;
                double          v_min_ask;
                double          v_min_max;
                double          v_mean_min_max;
	
		short           ind_v_rate = -1;
                short           ind_v_bid = -1;
                short           ind_v_max_bid = -1;
                short           ind_v_med_bid = -1;
                short           ind_v_min_bid = -1;
                short           ind_v_max_ask = -1;
                short           ind_v_med_ask = -1;
                short           ind_v_min_ask = -1;
                short           ind_v_min_max = -1;
                short           ind_v_mean_min_max = -1;

	/* EXEC SQL END DECLARE SECTION; */ 



	hv_from_ccy_id.len = strlen(csFromCcyId);
	memcpy(hv_from_ccy_id.arr, csFromCcyId, hv_from_ccy_id.len);
DEBUGLOG(("GetExchangeRate from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));

	hv_to_ccy_id.len = strlen(csToCcyId);
	memcpy(hv_to_ccy_id.arr, csToCcyId, hv_to_ccy_id.len);
DEBUGLOG(("GetExchangeRate to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));

	/* EXEC SQL DECLARE c_cursor_getexchangerate CURSOR FOR
		SELECT	ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		FROM	exchange_rate
		WHERE	ex_from_ccy_id = :hv_from_ccy_id
		AND	ex_to_ccy_id = :hv_to_ccy_id
		AND	ex_effect_date  = 
			(SELECT max(ex_effect_date)
                           FROM exchange_rate
                          WHERE ex_from_ccy_id = :hv_from_ccy_id
                            AND ex_to_ccy_id = :hv_to_ccy_id
                            AND ex_effect_date <= sysdate); */ 


	/* EXEC SQL OPEN c_cursor_getexchangerate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )80;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_ccy_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_ccy_id;
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
 if (sqlca.sqlcode < 0) goto getexchangerate_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getexchangerate

                INTO
			:v_rate:ind_v_rate,
			:v_bid:ind_v_bid,
			:v_max_ask:ind_v_max_ask,
			:v_med_ask:ind_v_med_ask,
			:v_min_ask:ind_v_min_ask,
			:v_max_bid:ind_v_max_bid,
			:v_med_bid:ind_v_med_bid,
			:v_min_bid:ind_v_min_bid,
			:v_min_max:ind_v_min_max,
			:v_mean_min_max:ind_v_mean_min_max; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )111;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_v_rate;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_v_bid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_max_ask;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_v_max_ask;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_med_ask;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_v_med_ask;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_ask;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_v_min_ask;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_bid;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_v_max_bid;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_med_bid;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_v_med_bid;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_min_bid;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_v_min_bid;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_max;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_v_min_max;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_mean_min_max;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_v_mean_min_max;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getexchangerate_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/*rate*/
		if(ind_v_rate>=0)
		{
			PutField_Double(hRec,"rate",v_rate);
DEBUGLOG(("GetExchangeRate rate = [%f]\n",v_rate));
		}

/*bid*/
		if(ind_v_bid>=0)
		{
			PutField_Double(hRec,"bid",v_bid);
DEBUGLOG(("GetExchangeRate bid = [%f]\n",v_bid));
		}

/*max_bid*/
		if(ind_v_max_bid>=0)
		{
			PutField_Double(hRec,"MAXBID",v_max_bid);
DEBUGLOG(("GetExchangeRate MAXBID = [%f]\n",v_max_bid));
		}

/*med_bid*/
		if(ind_v_med_bid>=0)
		{
			PutField_Double(hRec,"MEDBID",v_med_bid);
DEBUGLOG(("GetExchangeRate MEDBID = [%f]\n",v_med_bid));
		}

/*min_bid*/
		if(ind_v_min_bid>=0)
		{
			PutField_Double(hRec,"MINBID",v_min_bid);
DEBUGLOG(("GetExchangeRate MINBID = [%f]\n",v_min_bid));
		}

/*max_ask*/
		if(ind_v_max_ask>=0)
		{
			PutField_Double(hRec,"MAXASK",v_max_ask);
DEBUGLOG(("GetExchangeRate MAXASK = [%f]\n",v_max_ask));
		}

/*med_ask*/
		if(ind_v_med_ask>=0)
		{
			PutField_Double(hRec,"MEDASK",v_med_ask);
DEBUGLOG(("GetExchangeRate MEDASK = [%f]\n",v_med_ask));
		}

/*min_ask*/
		if(ind_v_min_ask>=0)
		{
			PutField_Double(hRec,"MINASK",v_min_ask);
DEBUGLOG(("GetExchangeRate MINASK = [%f]\n",v_min_ask));
		}

/*min_max*/
		if(ind_v_min_max>=0)
		{
			PutField_Double(hRec,"MINMAX",newround(v_min_max,5));
DEBUGLOG(("GetExchangeRate MINMAX = [%f]\n",newround(v_min_max,5)));
		}

/*mean_min_max*/
		if(ind_v_mean_min_max>=0)
		{
			PutField_Double(hRec,"MEANMINMAX",v_mean_min_max);
DEBUGLOG(("GetExchangeRate MEANMINMAX = [%f]\n",v_mean_min_max));
		}


	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getexchangerate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexchangerate_error;
}



DEBUGLOG(("GetExchangeRate Normal Exit\n"));
        return  PD_OK;

getexchangerate_error:
DEBUGLOG(("getexchangerate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getexchangerate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 15;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )181;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}

int GetExchangeRateByDate(const char* csEffectDate, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec)
{

	/* EXEC SQL WHENEVER SQLERROR GOTO getexchangeratebydate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

		/* varchar		hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;

		/* varchar		hv_effect_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effect_date;


		double		v_rate;
		double		v_bid;
		double		v_max_bid;
                double          v_med_bid;
                double          v_min_bid;
                double          v_max_ask;
                double          v_med_ask;
                double          v_min_ask;
                double          v_min_max;
                double          v_mean_min_max;
	
		short           ind_v_rate = -1;
                short           ind_v_bid = -1;
                short           ind_v_max_bid = -1;
                short           ind_v_med_bid = -1;
                short           ind_v_min_bid = -1;
                short           ind_v_max_ask = -1;
                short           ind_v_med_ask = -1;
                short           ind_v_min_ask = -1;
                short           ind_v_min_max = -1;
                short           ind_v_mean_min_max = -1;

	/* EXEC SQL END DECLARE SECTION; */ 



	hv_from_ccy_id.len = strlen(csFromCcyId);
	memcpy(hv_from_ccy_id.arr, csFromCcyId, hv_from_ccy_id.len);
DEBUGLOG(("GetExchangeRateByDate from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));

	hv_to_ccy_id.len = strlen(csToCcyId);
	memcpy(hv_to_ccy_id.arr, csToCcyId, hv_to_ccy_id.len);
DEBUGLOG(("GetExchangeRateByDate to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));

	hv_effect_date.len = strlen(csEffectDate);
	memcpy(hv_effect_date.arr, csEffectDate, hv_effect_date.len);
DEBUGLOG(("GetExchangeRateByDate effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));

	/* EXEC SQL DECLARE c_cursor_getexchangeratebydate CURSOR FOR

/o
		SELECT	ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		FROM	exchange_rate
		WHERE	ex_from_ccy_id = :hv_from_ccy_id
		AND	ex_to_ccy_id = :hv_to_ccy_id
		AND	ex_effect_date  = 
			(SELECT max(ex_effect_date)
                           FROM exchange_rate
                          WHERE ex_from_ccy_id = :hv_from_ccy_id
                            AND ex_to_ccy_id = :hv_to_ccy_id
                            AND ex_effect_date < to_date(:hv_effect_date,'YYYYMMDD') + 1);
o/
		SELECT	ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		  FROM	(SELECT	*
			   FROM	exchange_rate
			  WHERE	ex_from_ccy_id = :hv_from_ccy_id
			    AND	ex_to_ccy_id = :hv_to_ccy_id
			    AND ex_effect_date < to_date(:hv_effect_date,'YYYYMMDD') + 1
			 ORDER BY
				ex_effect_date DESC)
		 WHERE	rownum < 2; */ 



	/* EXEC SQL OPEN c_cursor_getexchangeratebydate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )196;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_ccy_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
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
 if (sqlca.sqlcode < 0) goto getexchangeratebydate_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getexchangeratebydate

                INTO
			:v_rate:ind_v_rate,
			:v_bid:ind_v_bid,
			:v_max_ask:ind_v_max_ask,
			:v_med_ask:ind_v_med_ask,
			:v_min_ask:ind_v_min_ask,
			:v_max_bid:ind_v_max_bid,
			:v_med_bid:ind_v_med_bid,
			:v_min_bid:ind_v_min_bid,
			:v_min_max:ind_v_min_max,
			:v_mean_min_max:ind_v_mean_min_max; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_v_rate;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_v_bid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_max_ask;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_v_max_ask;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_med_ask;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_v_med_ask;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_ask;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_v_min_ask;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_bid;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_v_max_bid;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_med_bid;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_v_med_bid;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_min_bid;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_v_min_bid;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_max;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_v_min_max;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_mean_min_max;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_v_mean_min_max;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getexchangeratebydate_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/*rate*/
		if(ind_v_rate>=0)
		{
			PutField_Double(hRec,"rate",v_rate);
DEBUGLOG(("GetExchangeRateByDate rate = [%f]\n",v_rate));
		}

/*bid*/
		if(ind_v_bid>=0)
		{
			PutField_Double(hRec,"bid",v_bid);
DEBUGLOG(("GetExchangeRateByDate bid = [%f]\n",v_bid));
		}

/*max_bid*/
		if(ind_v_max_bid>=0)
		{
			PutField_Double(hRec,"max_bid",v_max_bid);
DEBUGLOG(("GetExchangeRateByDate max_bid = [%f]\n",v_max_bid));
		}

/*med_bid*/
		if(ind_v_med_bid>=0)
		{
			PutField_Double(hRec,"med_bid",v_med_bid);
DEBUGLOG(("GetExchangeRateByDate med_bid = [%f]\n",v_med_bid));
		}

/*min_bid*/
		if(ind_v_min_bid>=0)
		{
			PutField_Double(hRec,"min_bid",v_min_bid);
DEBUGLOG(("GetExchangeRateByDate min_bid = [%f]\n",v_min_bid));
		}

/*max_ask*/
		if(ind_v_max_ask>=0)
		{
			PutField_Double(hRec,"max_ask",v_max_ask);
DEBUGLOG(("GetExchangeRateByDate max_ask = [%f]\n",v_max_ask));
		}

/*med_ask*/
		if(ind_v_med_ask>=0)
		{
			PutField_Double(hRec,"med_ask",v_med_ask);
DEBUGLOG(("GetExchangeRateByDate med_ask = [%f]\n",v_med_ask));
		}

/*min_ask*/
		if(ind_v_min_ask>=0)
		{
			PutField_Double(hRec,"min_ask",v_min_ask);
DEBUGLOG(("GetExchangeRateByDate min_ask = [%f]\n",v_min_ask));
		}

/*min_max*/
		if(ind_v_min_max>=0)
		{
			PutField_Double(hRec,"min_max",v_min_max);
DEBUGLOG(("GetExchangeRateByDate min_max = [%f]\n",v_min_max));
		}

/*mean_min_max*/
		if(ind_v_mean_min_max>=0)
		{
			PutField_Double(hRec,"mean_min_max",v_mean_min_max);
DEBUGLOG(("GetExchangeRateByDate mean_min_max = [%f]\n",v_mean_min_max));
		}


	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getexchangeratebydate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )278;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexchangeratebydate_error;
}



DEBUGLOG(("GetExchangeRateByDate Normal Exit\n"));
        return  PD_OK;

getexchangeratebydate_error:
DEBUGLOG(("getexchangeratebydate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getexchangeratebydate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 15;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )293;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}


int GetExchangeRateByDateTime(const char* csEffectDateTime, const char* csFromCcyId, const char* csToCcyId, hash_t* hRec)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getexratebydatetime_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

		/* varchar		hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;

		/* varchar		hv_effect_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_effect_date;


		double		v_rate;
		double		v_bid;
		double		v_max_bid;
                double          v_med_bid;
                double          v_min_bid;
                double          v_max_ask;
                double          v_med_ask;
                double          v_min_ask;
                double          v_min_max;
                double          v_mean_min_max;
	
		short           ind_v_rate = -1;
                short           ind_v_bid = -1;
                short           ind_v_max_bid = -1;
                short           ind_v_med_bid = -1;
                short           ind_v_min_bid = -1;
                short           ind_v_max_ask = -1;
                short           ind_v_med_ask = -1;
                short           ind_v_min_ask = -1;
                short           ind_v_min_max = -1;
                short           ind_v_mean_min_max = -1;

	/* EXEC SQL END DECLARE SECTION; */ 



	hv_from_ccy_id.len = strlen(csFromCcyId);
	memcpy(hv_from_ccy_id.arr, csFromCcyId, hv_from_ccy_id.len);
DEBUGLOG(("GetExchangeRateByDateTime from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));

	hv_to_ccy_id.len = strlen(csToCcyId);
	memcpy(hv_to_ccy_id.arr, csToCcyId, hv_to_ccy_id.len);
DEBUGLOG(("GetExchangeRateByDateTime to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));

	hv_effect_date.len = strlen(csEffectDateTime);
	memcpy(hv_effect_date.arr, csEffectDateTime, hv_effect_date.len);
DEBUGLOG(("GetExchangeRateByDateTime effect_date_time = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));

	/* EXEC SQL DECLARE c_cursor_getexratebydatetime CURSOR FOR
		SELECT	ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		FROM	exchange_rate
		WHERE	ex_from_ccy_id = :hv_from_ccy_id
		AND	ex_to_ccy_id = :hv_to_ccy_id
		AND	ex_effect_date  = 
			(SELECT max(ex_effect_date)
                           FROM exchange_rate
                          WHERE ex_from_ccy_id = :hv_from_ccy_id
                            AND ex_to_ccy_id = :hv_to_ccy_id
                            AND ex_effect_date < to_date(:hv_effect_date,'YYYYMMDDHH24MISS')); */ 


	/* EXEC SQL OPEN c_cursor_getexratebydatetime; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0004;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )308;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[0] = (unsigned long )5;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_ccy_id;
 sqlstm.sqhstl[1] = (unsigned long )5;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_ccy_id;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_ccy_id;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[4] = (unsigned long )16;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
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
 if (sqlca.sqlcode < 0) goto getexratebydatetime_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getexratebydatetime

                INTO
			:v_rate:ind_v_rate,
			:v_bid:ind_v_bid,
			:v_max_ask:ind_v_max_ask,
			:v_med_ask:ind_v_med_ask,
			:v_min_ask:ind_v_min_ask,
			:v_max_bid:ind_v_max_bid,
			:v_med_bid:ind_v_med_bid,
			:v_min_bid:ind_v_min_bid,
			:v_min_max:ind_v_min_max,
			:v_mean_min_max:ind_v_mean_min_max; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )343;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_v_rate;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_bid;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_v_bid;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_max_ask;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_v_max_ask;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_med_ask;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_v_med_ask;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_min_ask;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_v_min_ask;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_bid;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_v_max_bid;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_med_bid;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_v_med_bid;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_min_bid;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_v_min_bid;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_min_max;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_v_min_max;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_mean_min_max;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_v_mean_min_max;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getexratebydatetime_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/*rate*/
		if(ind_v_rate>=0)
		{
			PutField_Double(hRec,"rate",v_rate);
DEBUGLOG(("GetExchangeRateByDateTime rate = [%f]\n",v_rate));
		}

/*bid*/
		if(ind_v_bid>=0)
		{
			PutField_Double(hRec,"bid",v_bid);
DEBUGLOG(("GetExchangeRateByDateTime bid = [%f]\n",v_bid));
		}

/*max_bid*/
		if(ind_v_max_bid>=0)
		{
			PutField_Double(hRec,"MAXBID",v_max_bid);
DEBUGLOG(("GetExchangeRateByDateTime max_bid = [%f]\n",v_max_bid));
		}

/*med_bid*/
		if(ind_v_med_bid>=0)
		{
			PutField_Double(hRec,"MEDBID",v_med_bid);
DEBUGLOG(("GetExchangeRateByDateTime med_bid = [%f]\n",v_med_bid));
		}

/*min_bid*/
		if(ind_v_min_bid>=0)
		{
			PutField_Double(hRec,"MINBID",v_min_bid);
DEBUGLOG(("GetExchangeRateByDateTime min_bid = [%f]\n",v_min_bid));
		}

/*max_ask*/
		if(ind_v_max_ask>=0)
		{
			PutField_Double(hRec,"MAXASK",v_max_ask);
DEBUGLOG(("GetExchangeRateByDateTime max_ask = [%f]\n",v_max_ask));
		}

/*med_ask*/
		if(ind_v_med_ask>=0)
		{
			PutField_Double(hRec,"MEDASK",v_med_ask);
DEBUGLOG(("GetExchangeRateByDateTime med_ask = [%f]\n",v_med_ask));
		}

/*min_ask*/
		if(ind_v_min_ask>=0)
		{
			PutField_Double(hRec,"MINASK",v_min_ask);
DEBUGLOG(("GetExchangeRateByDateTime min_ask = [%f]\n",v_min_ask));
		}

/*min_max*/
		if(ind_v_min_max>=0)
		{
			PutField_Double(hRec,"MINMAX",newround(v_min_max,5));
DEBUGLOG(("GetExchangeRateByDateTime min_max = [%f]\n",newround(v_min_max,5)));
		}

/*mean_min_max*/
		if(ind_v_mean_min_max>=0)
		{
			PutField_Double(hRec,"MEANMINMAX",v_mean_min_max);
DEBUGLOG(("GetExchangeRateByDateTime mean_min_max = [%f]\n",v_mean_min_max));
		}


	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getexratebydatetime; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )398;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getexratebydatetime_error;
}



DEBUGLOG(("GetExchangeRateByDateTime Normal Exit\n"));
        return  PD_OK;

getexratebydatetime_error:
DEBUGLOG(("getexratebydatetime_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getexratebydatetime; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 15;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )413;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetAllExchangeRateByDate(const char* csEffectDate, recordset_t* rRS)
{

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getallexchangeratebydate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_effect_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effect_date;


		/* varchar		v_from_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_from_ccy;

		/* varchar		v_to_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_ccy;

		double		v_rate;
		double		v_bid;
		double		v_max_bid;
                double          v_med_bid;
                double          v_min_bid;
                double          v_max_ask;
                double          v_med_ask;
                double          v_min_ask;
                double          v_min_max;
                double          v_mean_min_max;

		short		ind_from_ccy = -1;
		short		ind_to_ccy = -1;
		short           ind_v_rate = -1;
                short           ind_v_bid = -1;
                short           ind_v_max_bid = -1;
                short           ind_v_med_bid = -1;
                short           ind_v_min_bid = -1;
                short           ind_v_max_ask = -1;
                short           ind_v_med_ask = -1;
                short           ind_v_min_ask = -1;
                short           ind_v_min_max = -1;
                short           ind_v_mean_min_max = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_effect_date.len = strlen(csEffectDate);
	memcpy(hv_effect_date.arr, csEffectDate, hv_effect_date.len);
DEBUGLOG(("GetAllExchangeRateByDate effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));

	/* EXEC SQL DECLARE c_cursor_getallratebydate CURSOR FOR

		SELECT	ex_from_ccy_id,
			ex_to_ccy_id,
			ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		FROM	(SELECT	ex_from_ccy_id,
				ex_to_ccy_id,
				ex_rate,
				ex_bid,
				ex_max_ask,
				ex_med_ask,
				ex_min_ask,
				ex_max_bid,
				ex_med_bid,
				ex_min_bid,
				ex_minmax_src2dst,
				ex_meanminmax_src2dst,
				ex_effect_date,
				row_number() over (partition by	ex_from_ccy_id,
								ex_to_ccy_id
							order by ex_effect_date desc) xx
			   FROM	exchange_rate
			  WHERE ex_effect_date < to_date(:hv_effect_date,'YYYYMMDD') + 1)
		WHERE	xx=1; */ 


	/* EXEC SQL OPEN c_cursor_getallratebydate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )428;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[0] = (unsigned long )10;
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
 if (sqlca.sqlcode < 0) goto getallexchangeratebydate_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getallratebydate

                INTO
			:v_from_ccy:ind_from_ccy,
			:v_to_ccy:ind_to_ccy,
			:v_rate:ind_v_rate,
			:v_bid:ind_v_bid,
			:v_max_ask:ind_v_max_ask,
			:v_med_ask:ind_v_med_ask,
			:v_min_ask:ind_v_min_ask,
			:v_max_bid:ind_v_max_bid,
			:v_med_bid:ind_v_med_bid,
			:v_min_bid:ind_v_min_bid,
			:v_min_max:ind_v_min_max,
			:v_mean_min_max:ind_v_mean_min_max; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )447;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_from_ccy;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_from_ccy;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_to_ccy;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_to_ccy;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_v_rate;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bid;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_v_bid;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_max_ask;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_v_max_ask;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_med_ask;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_v_med_ask;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_min_ask;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_v_min_ask;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_max_bid;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_v_max_bid;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_med_bid;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_v_med_bid;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_min_bid;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_v_min_bid;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_min_max;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_v_min_max;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_mean_min_max;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_v_mean_min_max;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getallexchangeratebydate_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(myHash, 0);

/*from_ccy*/
		if(ind_from_ccy>=0)
		{
			v_from_ccy.arr[v_from_ccy.len] = '\0';
			PutField_CString(myHash,"from_ccy",(const char*)v_from_ccy.arr);
DEBUGLOG(("GetAllExchangeRateByDate from_ccy = [%s]\n", v_from_ccy.arr));
		}

/*to_ccy*/
		if(ind_to_ccy>=0)
		{
			v_to_ccy.arr[v_to_ccy.len] = '\0';
			PutField_CString(myHash,"to_ccy",(const char*)v_to_ccy.arr);
DEBUGLOG(("GetAllExchangeRateByDate to_ccy = [%s]\n", v_to_ccy.arr));
		}

/*rate*/
		if(ind_v_rate>=0)
		{
			PutField_Double(myHash,"rate",v_rate);
DEBUGLOG(("GetAllExchangeRateByDate rate = [%f]\n",v_rate));
		}

/*bid*/
		if(ind_v_bid>=0)
		{
			PutField_Double(myHash,"bid",v_bid);
DEBUGLOG(("GetAllExchangeRateByDate bid = [%f]\n",v_bid));
		}

/*max_bid*/
		if(ind_v_max_bid>=0)
		{
			PutField_Double(myHash,"max_bid",v_max_bid);
DEBUGLOG(("GetAllExchangeRateByDate max_bid = [%f]\n",v_max_bid));
		}

/*med_bid*/
		if(ind_v_med_bid>=0)
		{
			PutField_Double(myHash,"med_bid",v_med_bid);
DEBUGLOG(("GetAllExchangeRateByDate med_bid = [%f]\n",v_med_bid));
		}

/*min_bid*/
		if(ind_v_min_bid>=0)
		{
			PutField_Double(myHash,"min_bid",v_min_bid);
DEBUGLOG(("GetAllExchangeRateByDate min_bid = [%f]\n",v_min_bid));
		}

/*max_ask*/
		if(ind_v_max_ask>=0)
		{
			PutField_Double(myHash,"max_ask",v_max_ask);
DEBUGLOG(("GetAllExchangeRateByDate max_ask = [%f]\n",v_max_ask));
		}

/*med_ask*/
		if(ind_v_med_ask>=0)
		{
			PutField_Double(myHash,"med_ask",v_med_ask);
DEBUGLOG(("GetAllExchangeRateByDate med_ask = [%f]\n",v_med_ask));
		}

/*min_ask*/
		if(ind_v_min_ask>=0)
		{
			PutField_Double(myHash,"min_ask",v_min_ask);
DEBUGLOG(("GetAllExchangeRateByDate min_ask = [%f]\n",v_min_ask));
		}

/*min_max*/
		if(ind_v_min_max>=0)
		{
			PutField_Double(myHash,"min_max",v_min_max);
DEBUGLOG(("GetAllExchangeRateByDate min_max = [%f]\n",v_min_max));
		}

/*mean_min_max*/
		if(ind_v_mean_min_max>=0)
		{
			PutField_Double(myHash,"mean_min_max",v_mean_min_max);
DEBUGLOG(("GetAllExchangeRateByDate mean_min_max = [%f]\n",v_mean_min_max));
		}

		RecordSet_Add(rRS, myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getallratebydate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )510;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallexchangeratebydate_error;
}



DEBUGLOG(("GetAllExchangeRateByDate Normal Exit\n"));
        return  PD_OK;

getallexchangeratebydate_error:
DEBUGLOG(("getallexchangeratebydate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getallratebydate; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 15;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )525;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}

int GetAllExchangeRateByExactDate(const char* csEffectDate, recordset_t* rRS)
{

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO getallexratebyexactdate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_effect_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effect_date;


		/* varchar		v_from_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_from_ccy;

		/* varchar		v_to_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_to_ccy;

		/* varchar         v_effect_date[PD_DATETIME_LEN*2]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_effect_date;

		double		v_rate;
		double		v_bid;
		double		v_max_bid;
                double          v_med_bid;
                double          v_min_bid;
                double          v_max_ask;
                double          v_med_ask;
                double          v_min_ask;
                double          v_min_max;
                double          v_mean_min_max;

		short		ind_from_ccy = -1;
		short		ind_to_ccy = -1;
		short		ind_effect_date = -1;
		short           ind_v_rate = -1;
                short           ind_v_bid = -1;
                short           ind_v_max_bid = -1;
                short           ind_v_med_bid = -1;
                short           ind_v_min_bid = -1;
                short           ind_v_max_ask = -1;
                short           ind_v_med_ask = -1;
                short           ind_v_min_ask = -1;
                short           ind_v_min_max = -1;
                short           ind_v_mean_min_max = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_effect_date.len = strlen(csEffectDate);
	memcpy(hv_effect_date.arr, csEffectDate, hv_effect_date.len);
DEBUGLOG(("GetAllExchangeRateByExactDate effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));

	/* EXEC SQL DECLARE c_cursor_getratebyexactdate CURSOR FOR

		SELECT	ex_from_ccy_id,
			ex_to_ccy_id,
			effect_date,
			//ex_effect_date,
			ex_rate,
			ex_bid,
			ex_max_ask,
			ex_med_ask,
			ex_min_ask,
			ex_max_bid,
			ex_med_bid,
			ex_min_bid,
			ex_minmax_src2dst,
			ex_meanminmax_src2dst
		FROM	(SELECT	ex_from_ccy_id,
				ex_to_ccy_id,
				to_char((ex_effect_date), 'MM-DD-YYYY HH24:MI:SS') as effect_date,
                                //ex_effect_date as effect_date,
				ex_rate,
				ex_bid,
				ex_max_ask,
				ex_med_ask,
				ex_min_ask,
				ex_max_bid,
				ex_med_bid,
				ex_min_bid,
				ex_minmax_src2dst,
				ex_meanminmax_src2dst,
				row_number() over (partition by	ex_from_ccy_id,
								ex_to_ccy_id
							order by ex_effect_date desc)
			   FROM	exchange_rate
			  WHERE ex_effect_date >= to_date(:hv_effect_date,'YYYYMMDD')
			    AND	ex_effect_date < to_date(:hv_effect_date,'YYYYMMDD') + 1)
		ORDER BY ex_from_ccy_id, ex_to_ccy_id, effect_date desc; */ 


	/* EXEC SQL OPEN c_cursor_getratebyexactdate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )540;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[0] = (unsigned long )10;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_effect_date;
 sqlstm.sqhstl[1] = (unsigned long )10;
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
 if (sqlca.sqlcode < 0) goto getallexratebyexactdate_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_getratebyexactdate

                INTO
			:v_from_ccy:ind_from_ccy,
			:v_to_ccy:ind_to_ccy,
			:v_effect_date:ind_effect_date,
			:v_rate:ind_v_rate,
			:v_bid:ind_v_bid,
			:v_max_ask:ind_v_max_ask,
			:v_med_ask:ind_v_med_ask,
			:v_min_ask:ind_v_min_ask,
			:v_max_bid:ind_v_max_bid,
			:v_med_bid:ind_v_med_bid,
			:v_min_bid:ind_v_min_bid,
			:v_min_max:ind_v_min_max,
			:v_mean_min_max:ind_v_mean_min_max; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )563;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_from_ccy;
  sqlstm.sqhstl[0] = (unsigned long )6;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_from_ccy;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_to_ccy;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_to_ccy;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_effect_date;
  sqlstm.sqhstl[2] = (unsigned long )22;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_effect_date;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_rate;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_v_rate;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_bid;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_v_bid;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_max_ask;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_v_max_ask;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_med_ask;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_v_med_ask;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_min_ask;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_v_min_ask;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_max_bid;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_v_max_bid;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_med_bid;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_v_med_bid;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_min_bid;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_v_min_bid;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_min_max;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_v_min_max;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_mean_min_max;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_v_mean_min_max;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto getallexratebyexactdate_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
        	hash_init(myHash, 0);

/*from_ccy*/
		if(ind_from_ccy>=0)
		{
			v_from_ccy.arr[v_from_ccy.len] = '\0';
			PutField_CString(myHash,"from_ccy",(const char*)v_from_ccy.arr);
DEBUGLOG(("GetAllExchangeRateByExactDate from_ccy = [%s]\n", v_from_ccy.arr));
		}

/*to_ccy*/
		if(ind_to_ccy>=0)
		{
			v_to_ccy.arr[v_to_ccy.len] = '\0';
			PutField_CString(myHash,"to_ccy",(const char*)v_to_ccy.arr);
DEBUGLOG(("GetAllExchangeRateByExactDate to_ccy = [%s]\n", v_to_ccy.arr));
		}

/*effect_date*/
                if(ind_effect_date>=0)
                {
                        v_effect_date.arr[v_effect_date.len] = '\0';
                        PutField_CString(myHash,"effect_date",(const char*)v_effect_date.arr);
DEBUGLOG(("GetAllExchangeRateByExactDate effect_date = [%s]\n", v_effect_date.arr));
                }

/*rate*/
		if(ind_v_rate>=0)
		{
			PutField_Double(myHash,"rate",v_rate);
DEBUGLOG(("GetAllExchangeRateByExactDate rate = [%f]\n",v_rate));
		}

/*bid*/
		if(ind_v_bid>=0)
		{
			PutField_Double(myHash,"bid",v_bid);
DEBUGLOG(("GetAllExchangeRateByExactDate bid = [%f]\n",v_bid));
		}

/*max_bid*/
		if(ind_v_max_bid>=0)
		{
			PutField_Double(myHash,"max_bid",v_max_bid);
DEBUGLOG(("GetAllExchangeRateByExactDate max_bid = [%f]\n",v_max_bid));
		}

/*med_bid*/
		if(ind_v_med_bid>=0)
		{
			PutField_Double(myHash,"med_bid",v_med_bid);
DEBUGLOG(("GetAllExchangeRateByExactDate med_bid = [%f]\n",v_med_bid));
		}

/*min_bid*/
		if(ind_v_min_bid>=0)
		{
			PutField_Double(myHash,"min_bid",v_min_bid);
DEBUGLOG(("GetAllExchangeRateByExactDate min_bid = [%f]\n",v_min_bid));
		}

/*max_ask*/
		if(ind_v_max_ask>=0)
		{
			PutField_Double(myHash,"max_ask",v_max_ask);
DEBUGLOG(("GetAllExchangeRateByExactDate max_ask = [%f]\n",v_max_ask));
		}

/*med_ask*/
		if(ind_v_med_ask>=0)
		{
			PutField_Double(myHash,"med_ask",v_med_ask);
DEBUGLOG(("GetAllExchangeRateByExactDate med_ask = [%f]\n",v_med_ask));
		}

/*min_ask*/
		if(ind_v_min_ask>=0)
		{
			PutField_Double(myHash,"min_ask",v_min_ask);
DEBUGLOG(("GetAllExchangeRateByExactDate min_ask = [%f]\n",v_min_ask));
		}

/*min_max*/
		if(ind_v_min_max>=0)
		{
			PutField_Double(myHash,"min_max",v_min_max);
DEBUGLOG(("GetAllExchangeRateByExactDate min_max = [%f]\n",v_min_max));
		}

/*mean_min_max*/
		if(ind_v_mean_min_max>=0)
		{
			PutField_Double(myHash,"mean_min_max",v_mean_min_max);
DEBUGLOG(("GetAllExchangeRateByExactDate mean_min_max = [%f]\n",v_mean_min_max));
		}

		RecordSet_Add(rRS, myHash);

	}while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getratebyexactdate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )630;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getallexratebyexactdate_error;
}



DEBUGLOG(("GetAllExchangeRateByExactDate Normal Exit\n"));
        return  PD_OK;

getallexratebyexactdate_error:
DEBUGLOG(("getallexratebyexactdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getratebyexactdate; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )645;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int DeleteDuplicateExchangeRateByExactDate(const char* csEffectDate, const char* csFromCcyId, const char* csToCcyId)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO deldupratebyexactdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar 	hv_effect_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_effect_date;

		/* varchar         hv_from_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_from_ccy_id;

                /* varchar         hv_to_ccy_id[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_to_ccy_id;


                short   	hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_effect_date.len = strlen(csEffectDate);
        memcpy(hv_effect_date.arr, csEffectDate, hv_effect_date.len);
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate effect_date = [%.*s]\n",hv_effect_date.len,hv_effect_date.arr));

	hv_from_ccy_id.len = strlen(csFromCcyId);
        memcpy(hv_from_ccy_id.arr, csFromCcyId, hv_from_ccy_id.len);
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate from_ccy_id = [%.*s]\n",hv_from_ccy_id.len,hv_from_ccy_id.arr));

	hv_to_ccy_id.len = strlen(csToCcyId);
        memcpy(hv_to_ccy_id.arr, csToCcyId, hv_to_ccy_id.len);
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate to_ccy_id = [%.*s]\n",hv_to_ccy_id.len,hv_to_ccy_id.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_del_dup_ex_rate_rec(
				:hv_effect_date,
				:hv_from_ccy_id,
				:hv_to_ccy_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 15;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_del_dup_ex_rate_rec ( :\
hv_effect_date , :hv_from_ccy_id , :hv_to_ccy_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )660;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_effect_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_from_ccy_id;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_to_ccy_id;
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
        if (sqlca.sqlcode < 0) goto deldupratebyexactdate_error;
}



DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_NOT_FOUND)
        {
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate: SP_NOT_FOUND\n"));
                return PD_NOT_FOUND;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("ExchangeRate_DeleteDuplicateExchangeRateByExactDate: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("ExchangeRate_DeleteDuplicateExchangeRateByExactDate: SP_ERR TxnAbort\n");
DEBUGLOG(("DeleteDuplicateExchangeRateByExactDate: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

deldupratebyexactdate_error:
        DEBUGLOG(("deldupratebyexactdate_error code %d\n", sqlca.sqlcode));
        DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
