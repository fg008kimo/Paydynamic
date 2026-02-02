
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "handle_daily_float_2_settfl.pc"
};


static unsigned int sqlctx = 1086047397;


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
"SELECT mb_posting_date , mb_merchant_id , mb_country_id , mb_currency_id , \
mb_service_code , SUM ( mb_bal ) - SUM ( mb_transfer_out_bal ) AS mb_bal FROM\
 merchant_bucket WHERE mb_bucket_type = 'AF' AND mb_released_date IS NULL AND\
 mb_posting_date <= release_pkg . find_release_date ( :b0 , mb_country_id , :\
b1 , :b2 ) AND mb_service_code = :b1 AND mb_bal > mb_transfer_out_bal GROUP B\
Y mb_posting_date , mb_merchant_id , mb_country_id , mb_currency_id , mb_serv\
ice_code ORDER BY mb_posting_date desc            ";

 static char *sq0004 = 
"SELECT mb_psp_id , mb_bal - mb_transfer_out_bal FROM merchant_bucket WHERE \
mb_bucket_type = 'AF' AND mb_released_date IS NULL AND mb_posting_date = :b0 \
AND mb_merchant_id = :b1 AND mb_country_id = :b2 AND mb_currency_id = :b3 AND\
 mb_service_code = :b4 order by ( mb_bal - mb_transfer_out_bal ) desc for upd\
ate ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,181,0,9,122,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,124,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
43,0,0,1,0,0,15,166,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,175,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,176,0,0,0,0,0,1,0,
88,0,0,3,510,0,9,270,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
119,0,0,3,0,0,13,272,0,0,6,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,
158,0,0,4,310,0,9,437,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
193,0,0,4,0,0,13,439,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
216,0,0,4,0,0,15,478,0,0,0,0,0,1,0,
231,0,0,3,0,0,15,559,0,0,0,0,0,1,0,
246,0,0,3,0,0,15,586,0,0,0,0,0,1,0,
261,0,0,4,0,0,15,587,0,0,0,0,0,1,0,
276,0,0,5,0,0,32,588,0,0,0,0,0,1,0,
291,0,0,6,71,0,4,957,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
314,0,0,7,148,0,4,1018,0,0,5,4,0,1,0,2,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
349,0,0,8,0,0,32,1043,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/30              [GOD]
un-relate service and country			   2013/01/14		   [MSN]
PRD275:Add sorting on the selected bucket record   2020/12/07		   [MSN]
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
    ERRLOG("handle_daily_float::process_main sql error %d\n", sqlca.sqlcode);
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
		SELECT mb_posting_date,
         		mb_merchant_id,
         		mb_country_id,
         		mb_currency_id,
         		mb_service_code,
         		SUM (mb_bal) - SUM(mb_transfer_out_bal) AS mb_bal
    		  FROM merchant_bucket
                 WHERE mb_bucket_type = 'AF'
                   AND mb_released_date IS NULL
                   AND mb_posting_date <=
			 release_pkg.find_release_date(:hv_ph_posting_date,mb_country_id,:hv_service_code,:hv_release_period)
                   AND mb_service_code = :hv_service_code
		   AND mb_bal > mb_transfer_out_bal
                 GROUP BY mb_posting_date,
         		mb_merchant_id,
         		mb_country_id,
         		mb_currency_id,
         		mb_service_code
		 ORDER BY mb_posting_date desc; */ 

		
                
        /* EXEC SQL OPEN c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 4;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_release_period;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
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
                sqlstm.offset = (unsigned int  )119;
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
				iSupportPayout = support_payout((const char *)v_merchant_id.arr,
					  (const char*)v_country_id.arr,
					  (const char*)v_currency_id.arr,
					  (const char*)v_service_code.arr);
			}
			else {
DEBUGLOG(("Process Bucket: Balance is zero skip!!!\n"));
				iRet = PD_SKIP_OK;
			}
		}
                if (iRet==PD_OK && !iSupportPayout){
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal));
			//check total hold balance with the lien bucket
			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
			iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
							 v_currency_id.arr,
							 v_country_id.arr,
							 v_service_code.arr,
							 hTxn);
			if(iRet==PD_OK){
				if(GetField_Double(hTxn,"total_hold",&dTotalHold)){
					dTotalHold = newround(dTotalHold,PD_DECIMAL_LEN);
DEBUGLOG(("Process Bucket: total_hold =[%f]\n",dTotalHold));
				}	
			}
			
			DBObjPtr = CreateObj(DBPtr,"DBMerchantLienBucket","GetLienAmount");
			iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
							 v_country_id.arr,
							 v_currency_id.arr,
							 v_service_code.arr,
							 &dLienAmt);

			if(iRet==PD_OK){
				dLienAmt = newround(dLienAmt,PD_DECIMAL_LEN);
DEBUGLOG(("Process Bucket: lien amount =[%f]\n",dLienAmt));
				if(dTotalHold > dLienAmt){
					dHoldAmt = dTotalHold - dLienAmt;
					dRemainHoldAmt = dHoldAmt;
				}
				else if (dTotalHold < dLienAmt){
					dReleaseAmt = dLienAmt - dTotalHold;
				}
			}

			if(iRet==PD_OK){
				if(dHoldAmt>0.0){
					if(v_bal>dHoldAmt)
						dAddLien = dHoldAmt;
					else
						dAddLien = v_bal;
				}
				else if(dReleaseAmt>0.0){
					dAddLien = (-1)*dReleaseAmt;
				}
				
				DBObjPtr = CreateObj(DBPtr,"DBMerchantLienBucket","UpdateLienAmount");
				iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
						v_country_id.arr,
						v_currency_id.arr,
						v_service_code.arr,
						dAddLien);

			}

		}
                if (iRet==PD_OK){
			/* EXEC SQL DECLARE c_cursor_get_bucket_psp CURSOR FOR
				SELECT mb_psp_id,
                       		       mb_bal - mb_transfer_out_bal
                       	          FROM merchant_bucket
                		 WHERE mb_bucket_type = 'AF'
                                   AND mb_released_date IS NULL
				   AND mb_posting_date = :v_posting_date
				   AND mb_merchant_id = :v_merchant_id
				   AND mb_country_id = :v_country_id
				   AND mb_currency_id = :v_currency_id
				   AND mb_service_code = :v_service_code
				  order by (mb_bal - mb_transfer_out_bal) desc
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
   sqlstm.offset = (unsigned int  )158;
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
    sqlstm.offset = (unsigned int  )193;
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
				DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","UpdateReleaseDetails");
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
          sqlstm.offset = (unsigned int  )216;
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
					DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValuesForUpdate");
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

                        		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","RlsAfterPOFloat2SettlementFloat");
                        		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
                        	        	v_country_id.arr,
                        	        	v_currency_id.arr,
                        	        	v_service_code.arr,
                        	        	v_bal-dHoldAmt+dReleaseAmt,
                        	        	PD_UPDATE_USER);

					if (iRet == PD_OK) {
						DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","CreditMerchantAmount");
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
ERRLOG("handle_daily_float_2_settfl:Process Bucket: call GetCurrentValuesForUpdate Error\n");
                		}
                		if (iRet == PD_OK) {
                        		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
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
        sqlstm.offset = (unsigned int  )231;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}




	if (iRet == PD_OK)  {

		TxnCommit();
		//check if there are any AF have been released and the balance account do not have balance in the bucket
		iRet = SUCCESS;
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
    ERRLOG("handle_daily_float::process_bucket sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_bucket; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )246;
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
    sqlstm.offset = (unsigned int  )261;
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
    sqlstm.offset = (unsigned int  )276;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



/*
int process_release(hash_t *myHash)
{
	int iRet = PD_OK;
	char	*csMerchantId;
	char	csClientId[PD_CLIENT_ID_LEN+1];
	char	*csCcyId;
	char	*csCountry;
	char	*csServiceCode;
	char	*csTmp;
	hash_t	*hTxn;
	double	dReleaseBal=0;

	hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

DEBUGLOG(("*****process_release start*****\n"));

	if(GetField_CString(myHash,"merchant_id",&csMerchantId)){
		PutField_CString(hTxn,"merchant_id",csMerchantId);
		if(GetClientId((const unsigned char *)csMerchantId,( unsigned char *)csClientId)==PD_OK){
			PutField_CString(hTxn,"client_id",csClientId);
		}
	}
	if(GetField_CString(myHash,"currency_id",&csCcyId)){
		PutField_CString(hTxn,"currency_id",csCcyId);
	}
	if(GetField_CString(myHash,"country_id",&csCountry)){
		PutField_CString(hTxn,"country_id",csCountry);
	}
	if(GetField_CString(myHash,"service_code",&csServiceCode)){
		PutField_CString(hTxn,"service_code",csServiceCode);
	}
	if(GetField_CString(myHash,"cutoff_date",&csTmp)){
		PutField_CString(hTxn,"cutoff_date",csTmp);
	}


	if(iRet==PD_OK){
		if(GetField_Double(myHash,"released_amt",&dReleaseBal)){
			PutField_Double(hTxn,"txn_amt",dReleaseBal);
		}
DEBUGLOG(("process_release DBMerchantBalance->ReleaseFloat\n"));
		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","ReleaseFloat");
		iRet = (unsigned long)(DBObjPtr)(csMerchantId,csCountry,csCcyId,csServiceCode,dReleaseBal,PD_UPDATE_USER);
	}

	
	if(iRet==PD_OK){
		PutField_Char(hTxn,"status",PD_COMPLETE);
		PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
		PutField_Int(hTxn,"internal_code",PD_OK);
		PutField_CString(hTxn,"response_code","0");

		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
		if ((*DBObjPtr)(csMerchantId,csCcyId,csCountry,csServiceCode,hTxn)!=PD_OK){
DEBUGLOG(("DBMerchantBalance::GetCurrentValues Failed\n"));
		}

		iRet = AddTxnLog(hTxn);
	}

	if(iRet==PD_OK){
DEBUGLOG(("process_release Normal Exit\n"));
	}	
	else{
DEBUGLOG(("process_release Error[%d]\n",iRet));
ERRLOG("handle_daily_float::process_release Error[%d]\n",iRet);
	}

	FREE_ME(hTxn);
	return iRet;
}
*/


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


	DBObjPtr = CreateObj(DBPtr,"DBTxnSeq","GetNextTxnSeq");
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
	PutField_CString(hTxn,"channel_code",PD_CHANNEL_WEB);
	PutField_CString(hTxn,"txn_code",PD_RELEASE_FLOAT_2_SETT_FLOAT);

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
	DBObjPtr = CreateObj(DBPtr,"DBTransaction","Add");
	iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	
	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","Update");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","AddDetail");
		iRet = (unsigned long) ((*DBObjPtr)(hTxn));
	}

	if(iRet==PD_OK){
		DBObjPtr = CreateObj(DBPtr,"DBTransaction","UpdateDetail");
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
			DBObjPtr = CreateObj(DBPtr,"DBTxnElements","Add");
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

	/* EXEC SQL SELECT client_id
		INTO	:v_client_id:ind_client_id
		FROM	merch_detail
		WHERE	merchant_id = :hv_merchant_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select client_id INTO :b0:b1 FROM merch_detail WHERE mercha\
nt_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )291;
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
                select	mb_txn_type
		into	:v_txn_type:ind_txn_type	
                from  merchant_bal_acct
                where mb_merchant_id = :hv_merchant_id
		and   mb_service_code = :hv_service_code
		and   mb_country = :hv_country
		and   mb_ccy_id = :hv_ccy; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 6;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select mb_txn_type into :b0:b1 from merchant_bal_acct where\
 mb_merchant_id = :b2 and mb_service_code = :b3 and mb_country = :b4 and mb_c\
cy_id = :b5 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )314;
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_ccy;
 sqlstm.sqhstl[4] = (unsigned long )5;
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
    ERRLOG("handle_daily_float_2_settlf::support_payout sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 6;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )349;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return iRet;
}
