
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
           char  filnam[33];
};
static struct sqlcxp sqlfpn =
{
    32,
    "handle_offline_float_2_settfl.pc"
};


static unsigned int sqlctx = 140786523;


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
"SELECT sc_code , rs_release_period FROM def_service_code , rule_service_rel\
ease_period WHERE sc_code = rs_service_code AND rs_disabled = 0 AND rs_releas\
e_type = 'SETTFT'            ";

 static char *sq0003 = 
"SELECT omb_posting_date , omb_merchant_id , omb_country_id , omb_currency_i\
d , omb_service_code , SUM ( omb_bal ) - SUM ( omb_transfer_out_bal ) AS mb_b\
al FROM ol_merchant_bucket WHERE omb_bucket_type = 'AF' AND omb_released_date\
 IS NULL AND omb_posting_date <= ol_release_pkg . find_release_date ( :b0 , o\
mb_country_id , omb_service_code , :b1 ) AND omb_service_code = :b2 AND omb_b\
al > omb_transfer_out_bal GROUP BY omb_posting_date , omb_merchant_id , omb_c\
ountry_id , omb_currency_id , omb_service_code            ";

 static char *sq0004 = 
"SELECT omb_psp_id , omb_bal - omb_transfer_out_bal FROM ol_merchant_bucket \
WHERE omb_bucket_type = 'AF' AND omb_released_date IS NULL AND omb_posting_da\
te = :b0 AND omb_merchant_id = :b1 AND omb_country_id = :b2 AND omb_currency_\
id = :b3 AND omb_service_code = :b4 order by ( omb_bal - omb_transfer_out_bal\
 ) desc for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,181,0,9,120,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,122,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
43,0,0,1,0,0,15,164,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,173,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,174,0,0,0,0,0,1,0,
88,0,0,3,518,0,9,267,0,2049,3,3,0,1,0,1,9,0,0,1,3,0,0,1,9,0,0,
115,0,0,3,0,0,13,269,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,
154,0,0,4,325,0,9,382,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
189,0,0,4,0,0,13,384,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
212,0,0,4,0,0,15,423,0,0,0,0,0,1,0,
227,0,0,3,0,0,15,504,0,0,0,0,0,1,0,
242,0,0,3,0,0,15,529,0,0,0,0,0,1,0,
257,0,0,4,0,0,15,530,0,0,0,0,0,1,0,
272,0,0,5,0,0,32,531,0,0,0,0,0,1,0,
287,0,0,6,80,0,4,826,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
310,0,0,7,314,0,4,887,0,0,4,3,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
341,0,0,8,0,0,32,917,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/01/27              LokMan Chow
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

//char    cs_cutoff_date[PD_DATE_LEN + 1];
char    cDebug = 'Y';


OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_main(const char* csPostingDate);
//int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csCountry,int iReleasePeriod);
int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod);
//int process_release(hash_t *myHash);
//int is_holidays(const char* csCountry, const char* csDate);
int AddTxnLog(const hash_t* hVal);
int GetClientId(const unsigned char* csMerchantId,
                unsigned char* csClientId);
int support_payout(const char* csMerchantId,const char* csCountry,const char* csCcy,const char* csService);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;
	char	csPostingDate[PD_DATE_LEN +1];

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
       // 	printf("usage:  -d cutoff_date\n");
                return (iRet);
        }
	GetCurrHostPostingDate((unsigned char*)csPostingDate);
DEBUGLOG(("today is [%s]\n",csPostingDate));
/*
	if (is_weekend(csPostingDate) != PD_TRUE) {
*/
        	iRet = process_main(csPostingDate);
/*	}
	else {
DEBUGLOG(("today is weekend.... skip....\n"));
	}
*/
DEBUGLOG(("iRet = [%d]\n",iRet));

	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_main(const char* csPostingDate)
{
        int     iRet = SUCCESS;

DEBUGLOG(("process_main\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		//varchar	v_txn_country[PD_COUNTRY_LEN +1];
		short	v_release_period;

		short	ind_service_code = -1;
		//short	ind_txn_country = -1;
		short	ind_release_period = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_get_service CURSOR FOR
		SELECT 	sc_code,
			//sc_txn_country,
           		rs_release_period
 		  FROM  def_service_code,
         		rule_service_release_period
 		 WHERE sc_code = rs_service_code
                   AND rs_disabled = 0
                   AND rs_release_type = 'SETTFT'; */ 


        /* EXEC SQL OPEN c_cursor_get_service; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 0;
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
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_service
                INTO
			v_service_code:ind_service_code,
			//v_txn_country:ind_txn_country,
			v_release_period:ind_release_period; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 2;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )20;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_service_code;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_release_period;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_release_period;
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
                if (sqlca.sqlcode < 0) goto sql_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';	
DEBUGLOG(("process_main service code = [%s]\n",v_service_code.arr));
		}	
/*
		if (ind_txn_country >= 0) {
			v_txn_country.arr[v_txn_country.len] = '\0';	
DEBUGLOG(("process_main txn_country = [%s]\n",v_txn_country.arr));
		}	
*/
		if (ind_release_period >= 0) {
DEBUGLOG(("process_main release period = [%d]\n",v_release_period));
		}


		if (v_release_period > 0) {
			//if (is_holidays((const char*)v_txn_country.arr,csPostingDate) != PD_TRUE) {
                        	if (iRet == PD_OK) {
					//iRet = process_bucket(csPostingDate,(const char*)v_service_code.arr,(const char*) v_txn_country.arr,v_release_period);
					iRet = process_bucket(csPostingDate,(const char*)v_service_code.arr,v_release_period);
				}
			//}
			//else {
//DEBUGLOG(("process_main today is holiday for %s... skip....\n",v_txn_country.arr));
//			}
		}
		else {
DEBUGLOG(("release preiod is zero, skip!!!!\n"));
		}

	}while(PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_get_service; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )43;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



	return	iRet;

sql_error:
    DEBUGLOG(("process_main error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_offline_float_2_settlf::process_main sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_service; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )58;
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
    sqlstm.arrsiz = 2;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )73;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}




//int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csCountry,int iReleasePeriod)
int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod)
{               
        int     iRet = SUCCESS;
	char    csClientId[PD_CLIENT_ID_LEN+1];
	double	dTotalHold=0.0;
	double	dLienAmt=0.0;
	double	dHoldAmt=0.0;
	double	dRemainHoldAmt=0.0;
	double	dNetRelease=0.0;
	double	dReleaseAmt = 0.0;
	double	dAddLien = 0.0;
	int	iSupportPayout = PD_FALSE;

	hash_t*	hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("*****Process Bucket Start*****\n"));

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_ph_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_ph_posting_date;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		//varchar	hv_country[PD_COUNTRY_LEN];
		short	hv_release_period;

		/* varchar v_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

		/* varchar	v_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double	v_bal;
		double	v_psp_bal;

		short	ind_posting_date = -1;
		short	ind_merchant_id = -1;
		short	ind_currency_id= -1;
		short   ind_country_id= -1;
		short	ind_service_code= -1;
		short	ind_psp_id = -1;
		short	ind_bal= -1;
		short	ind_psp_bal= -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_ph_posting_date.len = strlen(csPostingDate);
	memcpy(hv_ph_posting_date.arr,csPostingDate,hv_ph_posting_date.len);
DEBUGLOG(("process_bucket ph posting date = [%.*s]\n",hv_ph_posting_date.len,hv_ph_posting_date.arr));

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("process_bucket service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
/*
	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("process_bucket country  = [%.*s]\n",hv_country.len,hv_country.arr));
*/
	hv_release_period = iReleasePeriod;
DEBUGLOG(("process_bucket release_period = [%d]\n",hv_release_period));

        /* EXEC SQL DECLARE c_cursor_get_bucket CURSOR FOR
		SELECT omb_posting_date,
         		omb_merchant_id,
         		omb_country_id,
         		omb_currency_id,
         		omb_service_code,
         		SUM (omb_bal) - SUM(omb_transfer_out_bal) AS mb_bal
    		  FROM ol_merchant_bucket
                 WHERE omb_bucket_type = 'AF'
                   AND omb_released_date IS NULL
                   AND omb_posting_date <=
			 ol_release_pkg.find_release_date(:hv_ph_posting_date,omb_country_id,omb_service_code,:hv_release_period)
                   AND omb_service_code = :hv_service_code
		   AND omb_bal > omb_transfer_out_bal
                 GROUP BY omb_posting_date,
         		omb_merchant_id,
         		omb_country_id,
         		omb_currency_id,
         		omb_service_code; */ 
	
		
                
        /* EXEC SQL OPEN c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )88;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_ph_posting_date;
        sqlstm.sqhstl[0] = (unsigned long )10;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_release_period;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_bucket
                INTO
			v_posting_date:ind_posting_date,
         		v_merchant_id:ind_merchant_id,
			v_country_id:ind_country_id,
         		v_currency_id:ind_currency_id,
         		v_service_code:ind_service_code,
         		v_bal:ind_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 6;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )115;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_posting_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_posting_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_currency_id;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_currency_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_service_code;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bal;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bal;
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


		iRet = PD_OK;

                hash_init(hTxn,0);

		PutField_CString(hTxn,"cutoff_date",csPostingDate);
		dTotalHold=0.0;
		dLienAmt=0.0;
		dHoldAmt=0.0;
		dRemainHoldAmt=0.0;
		dNetRelease=0.0;
		dReleaseAmt = 0.0;
		dAddLien = 0.0;


/* posting_date */
                if (ind_posting_date >= 0){
                        v_posting_date.arr[v_posting_date.len]='\0';
                        PutField_CString(hTxn,"posting_date",(const char*)v_posting_date.arr);
DEBUGLOG(("Process Bucket: posting_date =[%.*s]\n",v_posting_date.len,v_posting_date.arr));
                }

/* merchant_id */
		if (ind_merchant_id >= 0 ){
			v_merchant_id.arr[v_merchant_id.len]='\0';
			PutField_CString(hTxn,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("Process Bucket: merchant_id =[%.*s]\n",v_merchant_id.len,v_merchant_id.arr));
			if(GetClientId((const unsigned char *)v_merchant_id.arr,( unsigned char *)csClientId)==PD_OK){
	                        PutField_CString(hTxn,"client_id",csClientId);
       		        }
		}

/* country_id */
         	if (ind_country_id >= 0 ){
                	v_country_id.arr[v_country_id.len]='\0';
			PutField_CString(hTxn,"country_id",(const char*)v_country_id.arr);
DEBUGLOG(("Process Bucket: country_id =[%.*s]\n",v_country_id.len,v_country_id.arr));
		}

/* currency_id */
		if (ind_currency_id >= 0 ){
			v_currency_id.arr[v_currency_id.len]='\0';
			PutField_CString(hTxn,"currency_id",(const char*)v_currency_id.arr);
DEBUGLOG(("Process Bucket: currency_id =[%.*s]\n",v_currency_id.len,v_currency_id.arr));
		}


/* service_code */
		if (ind_service_code >= 0 ){
			v_service_code.arr[v_service_code.len]='\0';
			PutField_CString(hTxn,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("Process Bucket: service_code =[%.*s]\n",v_service_code.len,v_service_code.arr));
		}


/* release date */
		PutField_CString(hTxn,"released_date",csPostingDate);

		if (is_holidays((const char*)v_country_id.arr,csServiceCode,csPostingDate) == PD_TRUE) {
			iRet=PD_SKIP_OK;
DEBUGLOG(("Process Bucket: today is holiday for %s %s... skip....\n",v_country_id.arr,csServiceCode));
		}

/* bal */
/* release amount */
		if (ind_bal < 0) 
			v_bal = 0.0;

		if(iRet==PD_OK){
			if(v_bal > 0.0){  
				//check merchant support payout or not
				/*iSupportPayout = support_payout((const char *)v_merchant_id.arr,
					  (const char*)v_country_id.arr,
					  (const char*)v_currency_id.arr,
					  (const char*)v_service_code.arr);
				*/
			}
			else {
DEBUGLOG(("Process Bucket: Balance is zero skip!!!\n"));
				iRet = PD_SKIP_OK;
			}
		}
                if (iRet==PD_OK && !iSupportPayout){

		}
                if (iRet==PD_OK){
			/* EXEC SQL DECLARE c_cursor_get_bucket_psp CURSOR FOR
				SELECT omb_psp_id,
                       		       omb_bal - omb_transfer_out_bal
                       	          FROM ol_merchant_bucket
                		 WHERE omb_bucket_type = 'AF'
                                   AND omb_released_date IS NULL
				   AND omb_posting_date = :v_posting_date
				   AND omb_merchant_id = :v_merchant_id
				   AND omb_country_id = :v_country_id
				   AND omb_currency_id = :v_currency_id
				   AND omb_service_code = :v_service_code
				  order by (omb_bal - omb_transfer_out_bal) desc
				for update; */ 


			/* EXEC SQL open c_cursor_get_bucket_psp; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 6;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0004;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )154;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqcmod = (unsigned int )0;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_posting_date;
   sqlstm.sqhstl[0] = (unsigned long )11;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)0;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )18;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)0;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_country_id;
   sqlstm.sqhstl[2] = (unsigned long )5;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)0;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_currency_id;
   sqlstm.sqhstl[3] = (unsigned long )6;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_service_code;
   sqlstm.sqhstl[4] = (unsigned long )6;
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
   if (sqlca.sqlcode < 0) goto sql_error;
}


			do {
				/* EXEC SQL FETCH c_cursor_get_bucket_psp
				INTO 
					v_psp_id:ind_psp_id,
					v_psp_bal:ind_psp_bal; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )189;
    sqlstm.selerr = (unsigned short)1;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlstm.sqfoff = (         int )0;
    sqlstm.sqfmod = (unsigned int )2;
    sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_id;
    sqlstm.sqhstl[0] = (unsigned long )13;
    sqlstm.sqhsts[0] = (         int  )0;
    sqlstm.sqindv[0] = (         short *)&ind_psp_id;
    sqlstm.sqinds[0] = (         int  )0;
    sqlstm.sqharm[0] = (unsigned long )0;
    sqlstm.sqadto[0] = (unsigned short )0;
    sqlstm.sqtdso[0] = (unsigned short )0;
    sqlstm.sqhstv[1] = (unsigned char  *)&v_psp_bal;
    sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
    sqlstm.sqhsts[1] = (         int  )0;
    sqlstm.sqindv[1] = (         short *)&ind_psp_bal;
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
    if (sqlca.sqlcode < 0) goto sql_error;
}



				if (SQLCODE == SQL_NOT_FOUND) {
					break;
				}
// psp_id
				if (ind_psp_id >= 0 ){
					v_psp_id.arr[v_psp_id.len]='\0';
					PutField_CString(hTxn,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("Process Bucket: psp_id =[%.*s]\n",v_psp_id.len,v_psp_id.arr));
				}

				if (ind_psp_bal < 0) {
					v_psp_bal = 0.0;
				}
DEBUGLOG(("Process Bucket: psp_bal = [%f]\n",v_psp_bal));
				if ((v_psp_bal-dRemainHoldAmt)> 0.0) {
					dNetRelease = v_psp_bal-dRemainHoldAmt;

					if(dRemainHoldAmt>0.0){
						dRemainHoldAmt = 0.0;
					}
				}
				else if ((v_psp_bal-dRemainHoldAmt)<= 0.0) {
					dRemainHoldAmt = dRemainHoldAmt - v_psp_bal;
					dNetRelease = 0.0;
				}
				PutField_Double(hTxn,"released_amt",dNetRelease);
				PutField_CString(hTxn,"released_date",csPostingDate);
				PutField_CString(hTxn,"bucket_type",PD_BUCKET_TYPE_AFTER_PAYOUT_FLOAT);
				PutField_Int(hTxn,"release_to_af",0);
				DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBucket","UpdateReleaseDetails");
				iRet = (unsigned long)(DBObjPtr)(hTxn);

			}
			while(PD_TRUE && iRet == PD_OK);
	        	/* EXEC SQL CLOSE c_cursor_get_bucket_psp; */ 

{
          struct sqlexd sqlstm;
          sqlstm.sqlvsn = 12;
          sqlstm.arrsiz = 6;
          sqlstm.sqladtp = &sqladt;
          sqlstm.sqltdsp = &sqltds;
          sqlstm.iters = (unsigned int  )1;
          sqlstm.offset = (unsigned int  )212;
          sqlstm.cud = sqlcud0;
          sqlstm.sqlest = (unsigned char  *)&sqlca;
          sqlstm.sqlety = (unsigned short)4352;
          sqlstm.occurs = (unsigned int  )0;
          sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
          if (sqlca.sqlcode < 0) goto sql_error;
}



			if (dRemainHoldAmt==0.0) {

                		if (iRet == PD_OK) {
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal-dHoldAmt+dReleaseAmt));
					PutField_Double(hTxn,"txn_amt",v_bal-dHoldAmt+dReleaseAmt);
					DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetCurrentValuesForUpdate");
                			iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
                	        		v_currency_id.arr,
                	        		v_country_id.arr,
                	        		v_service_code.arr,
                	        		hTxn);
				}
                		if (iRet == PD_OK) {
                	       		double  dTmp;
                	        	if(GetField_Double(hTxn,"current_bal",&dTmp)){
                	               		PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("Process Bucket:: open_bal = [%f]\n",dTmp));
                	        	}

                	        	if(GetField_Double(hTxn,"current_bal_settlement",&dTmp)){
                           	    		PutField_Double(hTxn,"open_bal_settlement",dTmp);
DEBUGLOG(("Process Buket:: open_bal_settlement= [%f]\n",dTmp));
                        		}

                        		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","RlsAfterPOFloat2SettlementFloat");
                        		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
                        	        	v_country_id.arr,
                        	        	v_currency_id.arr,
                        	        	v_service_code.arr,
                        	        	v_bal-dHoldAmt+dReleaseAmt,
                        	        	PD_UPDATE_USER);

					if (iRet == PD_OK) {
						DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBucket","CreditMerchantAmount");
                               		 	iRet = (unsigned long)(DBObjPtr)(v_posting_date.arr,
                                	                v_merchant_id.arr,
                                	                v_country_id.arr,
                                                	v_currency_id.arr,
                                                	v_service_code.arr,
							PD_DEFAULT_PSP,
                                                	PD_BUCKET_TYPE_SETTLEMENT_FLOAT,
                                                	v_bal-dHoldAmt+dReleaseAmt,
                                                	PD_UPDATE_USER);
						if (iRet != PD_OK) {
DEBUGLOG(("Process Bucket: Insert Settlement Float Error\n"));
						}
					}
                		}
                		else {
DEBUGLOG(("Process Bucket: call GetCurrentValuesForUpdate Error\n"));
ERRLOG("handle_offline_float_2_settlf:Process Bucket: call GetCurrentValuesForUpdate Error\n");
                		}
                		if (iRet == PD_OK) {
                        		DBObjPtr = CreateObj(DBPtr,"DBOLMerchantBalance","GetCurrentValues");
                        		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
                        	                v_currency_id.arr,
                        	                v_country_id.arr,
                        	                v_service_code.arr,
                        	                hTxn);
                        		if (iRet == PD_OK) {
                        	       		PutField_Char(hTxn,"status",PD_COMPLETE);
                               	 		PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
                               			PutField_Int(hTxn,"internal_code",PD_OK);
                                		PutField_CString(hTxn,"response_code","0");
                                		PutField_CString(hTxn,"sub_status",PD_APPROVED);
                                		iRet = AddTxnLog(hTxn);
                        		}
                		}
			}
			
		}

		if(iRet==PD_SKIP_OK){
			iRet=PD_OK;
		}
		hash_destroy(hTxn);
 	}
	while(PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 6;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )227;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}




	if (iRet == PD_OK)  {
		iRet = SUCCESS;
		TxnCommit();
	}
	else  
		iRet = FAILURE;

	if(iRet==SUCCESS){
DEBUGLOG(("Process Bucket Normal Exit\n"));
	}
	else{
DEBUGLOG(("Process Bucket Error[%d]\n",iRet));
	}

	FREE_ME(hTxn);
        return iRet;

sql_error:
    DEBUGLOG(("process_bucket error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_offline_float_2_settlf::process_bucket sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_bucket; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )242;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL CLOSE c_cursor_get_bucket_psp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )257;
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
    sqlstm.offset = (unsigned int  )272;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}





int parse_arg(int argc,char **argv)
{
/*
        char    c;
	strcpy(cs_cutoff_date,"");

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_cutoff_date, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_cutoff_date,"")) 
                return FAILURE;

*/
        return SUCCESS;
}


int AddTxnLog(const hash_t* hVal)
{
	int 	iRet = PD_OK;
	char	csTxnSeq[PD_TXN_SEQ_LEN+1];
	char	*csTmp;
	char	cTmp;
	double	dTmp;
	int	iTmp;
	char	csDateTime[PD_DATETIME_LEN +1];
	char	csDate[PD_DATE_LEN +1];
	char	csTime[PD_TIME_LEN +1];

	hash_t	*hTxn;
	hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

	hash_t	*hEle;
	hEle = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hEle,0);


	DBObjPtr = CreateObj(DBPtr,"DBOLTxnSeq","GetNextOlnTxnSeq");
        strcpy(csTxnSeq,(*DBObjPtr)());
        csTxnSeq[strlen(csTxnSeq)]='\0';
	PutField_CString(hTxn,"txn_seq",csTxnSeq);
DEBUGLOG(("AddTxnLog:: txn_id = [%s]\n",csTxnSeq));
	

	strcpy(csDateTime,getdatetime());
	memcpy(csDate,&csDateTime[0],PD_DATE_LEN);
	csDate[PD_DATE_LEN] = '\0';

	memcpy(csTime,&csDateTime[PD_DATE_LEN],PD_TIME_LEN);
	csTime[PD_TIME_LEN] = '\0';

	if(GetField_CString(hVal,"cutoff_date",&csTmp)){
		//PutField_CString(hTxn,"approval_date",csTmp);
		PutField_CString(hTxn,"host_posting_date",csTmp);
		PutField_CString(hTxn,"transmission_datetime",csDateTime);
		PutField_CString(hTxn,"tm_date",csDate);
		PutField_CString(hTxn,"tm_time",csTime);
		PutField_CString(hTxn,"local_tm_date",csDate);
		PutField_CString(hTxn,"local_tm_time",csTime);
DEBUGLOG(("AddTxnLog:: host_posting_date = [%s]\n",csTmp));
	}

	DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
	(*DBObjPtr)(hTxn);

	if(GetField_CString(hVal,"merchant_id",&csTmp)){
		PutField_CString(hTxn,"merchant_id",csTmp);
DEBUGLOG(("AddTxnLog:: merchant_id = [%s]\n",csTmp));
	}

	if(GetField_CString(hVal,"client_id",&csTmp)){
		PutField_CString(hTxn,"client_id",csTmp);
DEBUGLOG(("AddTxnLog:: client_id = [%s]\n",csTmp));
	}


	PutField_CString(hTxn,"add_user",PD_UPDATE_USER);
	PutField_CString(hTxn,"process_type",PD_PROCESS_TYPE_DEF);
	PutField_CString(hTxn,"process_code",PD_PROCESS_CODE_DEF);
	PutField_CString(hTxn,"channel_code",PD_CHANNEL_OMT);
	PutField_CString(hTxn,"txn_code",PD_OFL_RELEASE_2_SETT_FLOAT);

	if(GetField_CString(hVal,"currency_id",&csTmp)){
		PutField_CString(hTxn,"txn_ccy",csTmp);
		PutField_CString(hTxn,"net_ccy",csTmp);
		PutField_CString(hEle,"ccy",csTmp);
DEBUGLOG(("AddTxnLog:: txn_ccy = [%s]\n",csTmp));
	}

	if(GetField_CString(hVal,"country_id",&csTmp)){
		PutField_CString(hTxn,"txn_country",csTmp);
DEBUGLOG(("AddTxnLog:: txn_country = [%s]\n",csTmp));
	}

	if(GetField_CString(hVal,"service_code",&csTmp)){
		PutField_CString(hTxn,"service_code",csTmp);
DEBUGLOG(("AddTxnLog:: service_code = [%s]\n",csTmp));
	}

	if(GetField_Char(hVal,"status",&cTmp)){
		PutField_Char(hTxn,"status",cTmp);
DEBUGLOG(("AddTxnLog:: status = [%c]\n",cTmp));
	}
	if(GetField_CString(hVal,"sub_status",&csTmp)){
		PutField_CString(hTxn,"sub_status",csTmp);
DEBUGLOG(("AddTxnLog:: sub status = [%s]\n",csTmp));
	}

	if(GetField_Char(hVal,"ar_ind",&cTmp)){
		PutField_Char(hTxn,"ar_ind",cTmp);
DEBUGLOG(("AddTxnLog:: ar_ind = [%c]\n",cTmp));
	}

	if(GetField_CString(hVal,"response_code",&csTmp)){
		PutField_CString(hTxn,"response_code",csTmp);
DEBUGLOG(("AddTxnLog:: response_code = [%s]\n",csTmp));
	}

	if(GetField_Int(hVal,"internal_code",&iTmp)){
		PutField_Int(hTxn,"internal_code",iTmp);
DEBUGLOG(("AddTxnLog:: internal_code = [%d]\n",iTmp));
	}

	if(GetField_Double(hVal,"txn_amt",&dTmp)){
		PutField_Double(hTxn,"txn_amt",dTmp);
		PutField_Double(hTxn,"net_amt",dTmp);
		PutField_Double(hEle,"amount",dTmp);
DEBUGLOG(("AddTxnLog:: txn_amt = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"open_bal_settlement",&dTmp)){
		PutField_Double(hTxn,"open_bal_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: open_bal_settlement = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"open_bal",&dTmp)){
		PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("AddTxnLog:: open_bal= [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"current_bal",&dTmp)){
		PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"net_bal",&dTmp)){
		PutField_Double(hTxn,"net_bal",dTmp);
DEBUGLOG(("AddTxnLog:: net_bal = [%f]\n",dTmp));
	}


	if(GetField_Double(hVal,"total_float",&dTmp)){
		PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("AddTxnLog:: total_float = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
		PutField_Double(hTxn,"total_float_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: total_float_settlement = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
		PutField_Double(hTxn,"total_float_after_payout",dTmp);
DEBUGLOG(("AddTxnLog:: total_float_after_payout = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
		PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("AddTxnLog:: total_reserved_amount = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_hold",&dTmp)){
		PutField_Double(hTxn,"total_hold",dTmp);
DEBUGLOG(("AddTxnLog:: total_hold = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_hold_settlement",&dTmp)){
		PutField_Double(hTxn,"total_hold_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: total_hold_settlement = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"fundin_payout",&dTmp)){
		PutField_Double(hTxn,"fundin_payout",dTmp);
DEBUGLOG(("AddTxnLog:: fundin_payout = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"reserved_payout",&dTmp)){
		PutField_Double(hTxn,"reserved_payout",dTmp);
DEBUGLOG(("AddTxnLog:: reserved_payout = [%f]\n",dTmp));
	}


	if(GetField_Double(hVal,"current_bal",&dTmp)){
		PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
		PutField_Double(hTxn,"current_bal_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal_settlement= [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"settlement_in_transit",&dTmp)){
		PutField_Double(hTxn,"settlement_in_transit",dTmp);
DEBUGLOG(("AddTxnLog:: settlement_in_transit = [%f]\n",dTmp));
	}



	PutField_Int(hTxn,"db_commit",PD_FALSE);
	DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Add");
	iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","Update");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","AddDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBOLTransaction","UpdateDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	}

	if (iRet == PD_OK) {

                PutField_CString(hEle,"txn_seq",csTxnSeq);
/* chg type */
                PutField_CString(hEle,"txn_element_type",PD_ELEMENT_SETTLEMENT_FLOAT);

/* party type */
                PutField_Char(hEle,"party_type",PD_TYPE_MERCHANT);


/* user */
                PutField_CString(hEle,"add_user",PD_UPDATE_USER);

/* amount type */
                PutField_CString(hEle,"amount_type",PD_CR);

		dTmp = 0.0;
                GetField_Double(hEle,"amount",&dTmp);
                if(dTmp>0.0){
			DBObjPtr = CreateObj(DBPtr,"DBOLTxnElements","Add");
			iRet = (unsigned long)(*DBObjPtr)(hEle);
		}
        }

DEBUGLOG(("AddTxnLog:: iRet = [%d]\n",iRet));

	FREE_ME(hTxn);
	FREE_ME(hEle);
	return iRet;
}


int	GetClientId(const unsigned char* csMerchantId,
		    unsigned char* csClientId)
{
	int iRet = PD_ERR;
	/* EXEC SQL WHENEVER SQLERROR GOTO getmerchant_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;


                /* varchar         v_client_id[PD_CLIENT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		short           ind_client_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen((const char*)csMerchantId);
        memcpy(hv_merchant_id.arr,(const char*)csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetMerchant merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	/* EXEC SQL SELECT md_client_id
		INTO	:v_client_id:ind_client_id
		FROM	ol_merch_detail
		WHERE	md_merchant_id = :hv_merchant_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select md_client_id INTO :b0:b1 FROM ol_merch_detail WHERE \
md_merchant_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )287;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_client_id;
 sqlstm.sqhstl[0] = (unsigned long )13;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_client_id;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto getmerchant_error;
}



	if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] = '\0';
			strcpy((char*)csClientId,(const char*)v_client_id.arr);
DEBUGLOG(("GetMerchant client_id = [%s]\n",csClientId));
			iRet=PD_OK;
                }

	return iRet;

getmerchant_error:
DEBUGLOG(("getmerchant_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;	
}


int support_payout(const char* csMerchantId,
		   const char* csCountry,
		   const char* csCcy,
		   const char* csService)
{
	int iRet = PD_FALSE;

DEBUGLOG(("support_payout\n"));
        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

                /* varchar hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;


                char    v_txn_type;
                short   ind_txn_type = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("support_payout merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

        hv_service_code.len = strlen(csService);
        memcpy(hv_service_code.arr,csService,hv_service_code.len);
DEBUGLOG(("support_payout service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_ccy.len = strlen(csCcy);
        memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("support_payout ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

        hv_country.len = strlen(csCountry);
        memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("support_payout country = [%.*s]\n",hv_country.len,hv_country.arr));

	/* EXEC SQL 
                select	distinct omb_txn_type
		into	:v_txn_type:ind_txn_type	
                from  ol_merchant_bank_acct,
		      ol_bank_accts
                where omb_merchant_id = :hv_merchant_id
		and   omb_service_code = :hv_service_code
		and   ob_acct_ccy = :hv_ccy
		and   ob_int_bank_code = omb_int_bank_code
		and   ob_bank_acct_num = omb_bank_acct_num
		and   omb_disabled = 0
		and   omb_status = 'O'
		and   omb_txn_type is not null; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select distinct omb_txn_type into :b0:b1 from ol_merchant_b\
ank_acct , ol_bank_accts where omb_merchant_id = :b2 and omb_service_code = :\
b3 and ob_acct_ccy = :b4 and ob_int_bank_code = omb_int_bank_code and ob_bank\
_acct_num = omb_bank_acct_num and omb_disabled = 0 and omb_status = 'O' and o\
mb_txn_type is not null ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )310;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_type;
 sqlstm.sqhstl[0] = (unsigned long )1;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_type;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[1] = (unsigned long )17;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}



		if (ind_txn_type >= 0) {
			if (v_txn_type == PD_TYPE_ALL || v_txn_type == PD_TYPE_PAYOUT){
				iRet = PD_TRUE;
			}
DEBUGLOG(("support_payout: Merchant[%c]\n",v_txn_type));
		}

DEBUGLOG(("support_payout: return iRet = [%d]\n",iRet));

	return iRet;

sql_error:
    DEBUGLOG(("support_payout error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_offline_float_2_settlf::support_payout sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )341;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return iRet;
}
