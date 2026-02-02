
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "handle_daily_sett_float.pc"
};


static unsigned int sqlctx = 469047083;


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

 static char *sq0001 = 
"SELECT sc_code FROM def_service_code            ";

 static char *sq0003 = 
"SELECT mb_merchant_id , mb_currency_id , mb_country_id FROM merchant_bucket\
 WHERE mb_released_date is null AND mb_bucket_type = 'SF' AND mb_service_code\
 = :b0 GROUP BY mb_merchant_id , mb_currency_id , mb_country_id            ";

 static char *sq0004 = 
"SELECT settlement_process_period FROM merch_detail WHERE merchant_id = :b0 \
           ";

 static char *sq0006 = 
"SELECT mb_posting_date , SUM ( mb_bal ) AS mb_bal FROM merchant_bucket WHER\
E mb_bucket_type = 'SF' AND mb_released_date IS NULL AND mb_posting_date <= r\
elease_pkg . find_release_date ( :b0 , :b1 , :b2 , :b3 ) AND mb_merchant_id =\
 :b4 AND mb_service_code = :b2 AND mb_currency_id = :b6 AND mb_country_id = :\
b1 GROUP BY mb_posting_date            ";

 static char *sq0007 = 
"SELECT mb_psp_id , mb_bal FROM merchant_bucket WHERE mb_bucket_type = 'SF' \
AND mb_released_date IS NULL AND mb_posting_date = :b0 AND mb_merchant_id = :\
b1 AND mb_country_id = :b2 AND mb_currency_id = :b3 AND mb_service_code = :b4\
 for update ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,48,0,9,112,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,114,0,0,1,0,0,1,0,2,9,0,0,
39,0,0,1,0,0,15,146,0,0,0,0,0,1,0,
54,0,0,1,0,0,15,155,0,0,0,0,0,1,0,
69,0,0,2,0,0,32,156,0,0,0,0,0,1,0,
84,0,0,3,227,0,9,210,0,2049,1,1,0,1,0,1,9,0,0,
103,0,0,3,0,0,13,212,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
130,0,0,4,86,0,9,248,0,2049,1,1,0,1,0,1,9,0,0,
149,0,0,4,0,0,13,250,0,0,1,0,0,1,0,2,3,0,0,
168,0,0,3,0,0,15,272,0,0,0,0,0,1,0,
183,0,0,3,0,0,15,290,0,0,0,0,0,1,0,
198,0,0,4,0,0,15,291,0,0,0,0,0,1,0,
213,0,0,5,0,0,32,292,0,0,0,0,0,1,0,
228,0,0,6,345,0,9,375,0,2049,8,8,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,
275,0,0,6,0,0,13,377,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
298,0,0,7,241,0,9,448,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
333,0,0,7,0,0,13,450,0,0,2,0,0,1,0,2,9,0,0,2,4,0,0,
356,0,0,7,0,0,15,479,0,0,0,0,0,1,0,
371,0,0,6,0,0,15,545,0,0,0,0,0,1,0,
386,0,0,6,0,0,15,569,0,0,0,0,0,1,0,
401,0,0,8,0,0,32,570,0,0,0,0,0,1,0,
416,0,0,9,71,0,4,853,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/08/30              Cody Chan
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
int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csTxnCountry,const char* csMerchantId,const char* csCurrencyId,int iReleasePeriod);
//int process_merchant(const char* csPostingDate,const char* csServiceCode,const char* csTxnCountry);
int process_merchant(const char* csPostingDate,const char* csServiceCode);
//int is_holidays(const char* csCountry, const char* csDate);
int AddTxnLog(const hash_t* hVal);
int GetClientId(const unsigned char* csMerchantId,
                unsigned char* csClientId);

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

		short	ind_service_code = -1;
		//short	ind_txn_country = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


        /* EXEC SQL DECLARE c_cursor_get_service CURSOR FOR
		SELECT 	sc_code//,
			//sc_txn_country
 		  FROM  def_service_code; */ 


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
			v_service_code:ind_service_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 1;
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


			//v_txn_country:ind_txn_country;

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] = '\0';	
DEBUGLOG(("service code = [%s]\n",v_service_code.arr));
		}	
/*
		if (ind_txn_country >= 0) {
			v_txn_country.arr[v_txn_country.len] = '\0';	
DEBUGLOG(("txn_country = [%s]\n",v_txn_country.arr));
		}	
*/

		//if (is_holidays((const char*)v_txn_country.arr,csPostingDate) != PD_TRUE) {
                //        if (iRet == PD_OK) {
				//iRet = process_merchant(csPostingDate,(const char*)v_service_code.arr,(const char*) v_txn_country.arr);
				iRet = process_merchant(csPostingDate,(const char*)v_service_code.arr);
		//	}
		//}
		//else {
//DEBUGLOG(("today is holiday for %s... skip....\n",v_txn_country.arr));
//		}

	}while(PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_get_service; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )39;
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
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )54;
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
    sqlstm.arrsiz = 1;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )69;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}



//int process_merchant(const char* csPostingDate,const char* csServiceCode,const char* csTxnCountry)
int process_merchant(const char* csPostingDate,const char* csServiceCode)
{
        int     iRet = SUCCESS;
        char    csClientId[PD_CLIENT_ID_LEN+1];

        hash_t* hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("*****Process Merchant Start*****\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;


		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_currency_id[PD_CURRENCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

		/* varchar	v_txn_country[PD_COUNTRY_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		
		short	v_release_period;

		short	ind_merchant_id = -1;
		short	ind_currency_id = -1;
		short	ind_txn_country = -1;

		short	ind_release_period = -1;
	/* EXEC SQL END DECLARE SECTION; */ 



	hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("process_merchant service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	/* EXEC SQL DECLARE c_cursor_get_merchant CURSOR FOR

		SELECT 	mb_merchant_id,
       			mb_currency_id,
			mb_country_id
 		  FROM merchant_bucket
 		 WHERE mb_released_date is null
   		   AND mb_bucket_type = 'SF'
   		   AND mb_service_code = :hv_service_code
 		GROUP BY mb_merchant_id,
          		mb_currency_id,mb_country_id; */ 


	/* EXEC SQL OPEN c_cursor_get_merchant; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )84;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_service_code;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


        do {   
                /* EXEC SQL FETCH c_cursor_get_merchant
                INTO
			v_merchant_id:ind_merchant_id,
			v_currency_id:ind_currency_id,
			v_txn_country:ind_txn_country; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 3;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )103;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[2] = (unsigned long )5;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_country;
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



	 	if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


/* merchant_id */
                if (ind_merchant_id >= 0 ){
                        v_merchant_id.arr[v_merchant_id.len]='\0';
DEBUGLOG(("Process Merchant: merchant_id =[%.*s]\n",v_merchant_id.len,v_merchant_id.arr));
                        if(GetClientId((const unsigned char *)v_merchant_id.arr,( unsigned char *)csClientId)==PD_OK){
                        }
                }

/* currency_id */
                if (ind_currency_id >= 0 ){
                        v_currency_id.arr[v_currency_id.len]='\0';
DEBUGLOG(("Process Merchant: currency_id =[%.*s]\n",v_currency_id.len,v_currency_id.arr));
                }

/* txn_country */
		if (ind_txn_country >= 0) {
			v_txn_country.arr[v_txn_country.len] = '\0';	
DEBUGLOG(("Process Merchant: txn_country = [%s]\n",v_txn_country.arr));
		}	

		/* EXEC SQL DECLARE c_cursor_get_merchant_detail CURSOR FOR
			SELECT settlement_process_period
                          FROM merch_detail
			 WHERE merchant_id = :v_merchant_id; */ 


		/* EXEC SQL OPEN c_cursor_get_merchant_detail; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 3;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0004;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )130;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[0] = (unsigned long )18;
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


        	do {
			/* EXEC SQL FETCH c_cursor_get_merchant_detail
			INTO		
				v_release_period:ind_release_period; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 3;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )149;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_release_period;
   sqlstm.sqhstl[0] = (unsigned long )sizeof(short);
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_release_period;
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


		 	if (SQLCODE == SQL_NOT_FOUND) {
                        	break;
                	}

			if (ind_release_period < 0)
				v_release_period = 0;
DEBUGLOG(("process_merchant release period = [%d]\n",v_release_period));
			if (v_release_period == 0 ) {
DEBUGLOG(("process_merchant SKIP!!!!!! release period is zero\n"));
			}
			else {
				iRet = process_bucket(csPostingDate,csServiceCode,(const char*)v_txn_country.arr,(const char*)v_merchant_id.arr,(const char*)v_currency_id.arr,v_release_period);
			}
		}
		while(PD_TRUE && iRet == PD_OK);

	}
	while(PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_get_merchant; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )168;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}



DEBUGLOG(("process_bucket iRet = [%d]\n",iRet));
	if (iRet == PD_OK)  {
                iRet = SUCCESS;
DEBUGLOG(("!!!!!!!!!!!!!!!!!!!!!!!COMMIT\n"));
                TxnCommit();
        }
        else
                iRet = FAILURE;

        return iRet;

sql_error:
    DEBUGLOG(("process_main error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_daily_sett_float::process_merchant sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_get_merchant; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )183;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL CLOSE c_cursor_get_merchant_detail; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )198;
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
    sqlstm.arrsiz = 3;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )213;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csTxnCountry,const char* csMerchantId,const char* csCurrencyId,int iReleasePeriod)
{               
        int     iRet = SUCCESS;
	char    csClientId[PD_CLIENT_ID_LEN+1];

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

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merchant_id;

		/* varchar	hv_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_currency_id;

		short	hv_release_period;


		/* varchar v_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;

		double	v_bal;
		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		double	v_psp_bal;

		short	ind_posting_date = -1;
		short	ind_bal= -1;
		short	ind_psp_id = -1;
		short	ind_psp_bal = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


	hv_ph_posting_date.len = strlen(csPostingDate);
	memcpy(hv_ph_posting_date.arr,csPostingDate,hv_ph_posting_date.len);
DEBUGLOG(("process_bucket ph posting date = [%.*s]\n",hv_ph_posting_date.len,hv_ph_posting_date.arr));

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("process_bucket service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_country.len = strlen(csTxnCountry);
	memcpy(hv_country.arr,csTxnCountry,hv_country.len);
DEBUGLOG(("process_bucket country  = [%.*s]\n",hv_country.len,hv_country.arr));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("process_bucket merchant_id  = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_currency_id.len = strlen(csCurrencyId);
	memcpy(hv_currency_id.arr,csCurrencyId,hv_currency_id.len);
DEBUGLOG(("process_bucket currency_id  = [%.*s]\n",hv_currency_id.len,hv_currency_id.arr));

	hv_release_period = iReleasePeriod;
DEBUGLOG(("process_bucket release_period = [%d]\n",hv_release_period));

	if(GetClientId((const unsigned char*)csMerchantId,( unsigned char *)csClientId)==PD_OK){
DEBUGLOG(("process_bucket client_id = [%s]\n",csClientId));
        }

        /* EXEC SQL DECLARE c_cursor_get_bucket CURSOR FOR
		SELECT mb_posting_date,
                        SUM (mb_bal) AS mb_bal
                  FROM merchant_bucket
                 WHERE mb_bucket_type = 'SF'
                   AND mb_released_date IS NULL
                   AND mb_posting_date <=
                         release_pkg.find_release_date(:hv_ph_posting_date,:hv_country,:hv_service_code,:hv_release_period)
		   AND mb_merchant_id = :hv_merchant_id
                   AND mb_service_code = :hv_service_code
		   AND mb_currency_id = :hv_currency_id
		   AND mb_country_id = :hv_country
                 GROUP BY mb_posting_date; */ 


		
                
        /* EXEC SQL OPEN c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )228;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[1] = (unsigned long )4;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_release_period;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(short);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )18;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)0;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_currency_id;
        sqlstm.sqhstl[6] = (unsigned long )6;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)0;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[7] = (unsigned long )4;
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
        if (sqlca.sqlcode < 0) goto sql_error;
}


        do {    
                /* EXEC SQL FETCH c_cursor_get_bucket
                INTO
			v_posting_date:ind_posting_date,
         		v_bal:ind_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )275;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_bal;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_bal;
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


		iRet = PD_OK;

                hash_init(hTxn,0);

		PutField_CString(hTxn, "client_id", csClientId);
		PutField_CString(hTxn,"cutoff_date",csPostingDate);


		PutField_CString(hTxn,"service_code",csServiceCode);
		PutField_CString(hTxn,"merchant_id",csMerchantId);
		PutField_CString(hTxn,"country_id",csTxnCountry);
		PutField_CString(hTxn,"currency_id",csCurrencyId);
/* posting_date */
                if (ind_posting_date >= 0){
                        v_posting_date.arr[v_posting_date.len]='\0';
                        PutField_CString(hTxn,"posting_date",(const char*)v_posting_date.arr);
DEBUGLOG(("Process Bucket: posting_date =[%.*s]\n",v_posting_date.len,v_posting_date.arr));
                }



/* release date */
		PutField_CString(hTxn,"released_date",csPostingDate);


/* bal */
/* release amount */
                if (ind_bal >= 0 ){
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal));
                        PutField_Double(hTxn,"released_amt",v_bal);
                }
		else {
			v_bal = 0.0;
		}


/* release date */
                PutField_CString(hTxn,"released_date",csPostingDate);

		if(is_holidays(csTxnCountry,csServiceCode,csPostingDate)== PD_TRUE){
			iRet = PD_SKIP_OK;
DEBUGLOG(("Process Bucket: today is holiday for %s %s... skip....\n",csTxnCountry,csServiceCode));
		}

/* bal */
/* release amount */
		if (iRet == PD_OK && v_bal > 0) {
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal));
			/* EXEC SQL DECLARE c_cursor_get_bucket_psp CURSOR FOR
                                SELECT mb_psp_id,
                                       mb_bal
                                  FROM merchant_bucket
                                 WHERE mb_bucket_type = 'SF'
                                   AND mb_released_date IS NULL
                                   AND mb_posting_date = :v_posting_date
                                   AND mb_merchant_id = :hv_merchant_id
                                   AND mb_country_id = :hv_country
                                   AND mb_currency_id = :hv_currency_id
                                   AND mb_service_code = :hv_service_code
                                  for update; */ 


			/* EXEC SQL open c_cursor_get_bucket_psp; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 8;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = sq0007;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )298;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
   sqlstm.sqhstl[1] = (unsigned long )18;
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
   sqlstm.sqhstv[3] = (unsigned char  *)&hv_currency_id;
   sqlstm.sqhstl[3] = (unsigned long )6;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)0;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&hv_service_code;
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


                        do {
                                /* EXEC SQL FETCH c_cursor_get_bucket_psp
                                INTO
                                        v_psp_id:ind_psp_id,
                                        v_psp_bal:ind_psp_bal; */ 

{
                                struct sqlexd sqlstm;
                                sqlstm.sqlvsn = 12;
                                sqlstm.arrsiz = 8;
                                sqlstm.sqladtp = &sqladt;
                                sqlstm.sqltdsp = &sqltds;
                                sqlstm.iters = (unsigned int  )1;
                                sqlstm.offset = (unsigned int  )333;
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
/* psp_id */
                                if (ind_psp_id >= 0 ){
                                        v_psp_id.arr[v_psp_id.len]='\0';
                                        PutField_CString(hTxn,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("Process Bucket: psp_id =[%.*s]\n",v_psp_id.len,v_psp_id.arr));
                                }

                                if (ind_psp_bal < 0) {
                                	v_psp_bal = 0.0;
				}
DEBUGLOG(("Process Bucket: psp_bal = [%f]\n",v_psp_bal));
                                if (v_psp_bal > 0) {
                                        PutField_Double(hTxn,"released_amt",v_psp_bal);
                                        PutField_CString(hTxn,"released_date",csPostingDate);
                                        PutField_Int(hTxn,"release_to_af",0);
					PutField_CString(hTxn,"bucket_type",PD_BUCKET_TYPE_SETTLEMENT_FLOAT);
                                        DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","UpdateReleaseDetails");
                                        iRet = (unsigned long)(DBObjPtr)(hTxn);
                                }
                        }
                        while(PD_TRUE && iRet == PD_OK);
                        /* EXEC SQL CLOSE c_cursor_get_bucket_psp; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 8;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )356;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
                        if (sqlca.sqlcode < 0) goto sql_error;
}


		}
		else {
DEBUGLOG(("Process Bucket: Balance is zero skip!!!\n"));
		}

                if (iRet == PD_OK && v_bal > 0) {
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal));
                        PutField_Double(hTxn,"txn_amt",v_bal);
                        DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValuesForUpdate");
                        iRet = (unsigned long)(DBObjPtr)(csMerchantId,
                                csCurrencyId,
				csTxnCountry,
				csServiceCode,
                                hTxn);
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

/***** release sett float to settlement */
                                DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","ReleaseSettFloat");
                                iRet = (unsigned long)(DBObjPtr)(csMerchantId,
					csTxnCountry,
					csCurrencyId,
					csServiceCode,
                                        v_bal,
                                        PD_UPDATE_USER);

                        }
else {
DEBUGLOG(("Process Bucket: call GetCurrentValuesForUpdate Error\n"));
ERRLOG("handle_daily_float_2_settfl:Process Bucket: call GetCurrentValuesForUpdate Error\n");
                        }
                        if (iRet == PD_OK) {
                                DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
                                iRet = (unsigned long)(DBObjPtr)(csMerchantId,
					csCurrencyId,
					csTxnCountry,
					csServiceCode,
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
		if(iRet==PD_SKIP_OK){
			iRet = PD_OK;
		}
		hash_destroy(hTxn);
 	}
	while(PD_TRUE && iRet == PD_OK);

        /* EXEC SQL CLOSE c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )371;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto sql_error;
}




DEBUGLOG(("iRet = [%d]\n",iRet));
	if (iRet == PD_OK)  {
DEBUGLOG(("!!!!!!!!!!!!!!!!!!!!!!!COMMIT 2\n"));
		TxnCommit();
	}

	if(iRet==PD_OK){
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
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )386;
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
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )401;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
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

	hash_t  *hEle;
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
	PutField_CString(hTxn,"txn_code",PD_RELEASE_SETT_FLOAT);

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

	if(GetField_Double(hVal,"current_bal",&dTmp)){
		PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"open_bal",&dTmp)){
		PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("AddTxnLog:: open_bal = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"open_bal_settlement",&dTmp)){
		PutField_Double(hTxn,"open_bal_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: open_bal_settlement = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_float",&dTmp)){
		PutField_Double(hTxn,"total_float",dTmp);
DEBUGLOG(("AddTxnLog:: total_float = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"total_float_settlement",&dTmp)){
		PutField_Double(hTxn,"total_float_settlement",dTmp);
DEBUGLOG(("AddTxnLog:: total_float_settlement = [%f]\n",dTmp));
	}
	if(GetField_Double(hVal,"total_reserved_amount",&dTmp)){
		PutField_Double(hTxn,"total_reserved_amount",dTmp);
DEBUGLOG(("AddTxnLog:: total_reserved_amount = [%f]\n",dTmp));
	}
	if(GetField_Double(hVal,"total_float_after_payout",&dTmp)){
                PutField_Double(hTxn,"total_float_after_payout",dTmp);
DEBUGLOG(("AddTxnLog:: total_float_after_payout = [%f]\n",dTmp));
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
DEBUGLOG(("AddTxnLog:: current_bal _settlement= [%f]\n",dTmp));
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
                PutField_CString(hEle,"amount_type",PD_DR);

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
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select client_id INTO :b0:b1 FROM merch_detail WHERE mercha\
nt_id = :b2 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )416;
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
