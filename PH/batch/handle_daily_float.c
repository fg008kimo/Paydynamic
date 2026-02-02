
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
    "handle_daily_float.pc"
};


static unsigned int sqlctx = 148873515;


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
"SELECT sc_code , rs_release_period FROM def_service_code , rule_service_rel\
ease_period WHERE sc_code = rs_service_code AND rs_disabled = 0 AND rs_releas\
e_type = 'AVAPO'            ";

 static char *sq0003 = 
"select mb_txn_type , mb_avai_po_percentage from merchant_bal_acct where mb_\
merchant_id = :b0 and mb_service_code = :b1 and mb_country = :b2 and mb_ccy_i\
d = :b3            ";

 static char *sq0004 = 
"select txn_type , mb_txn_type , mb_avai_po_percentage from psp_detail , mer\
chant_bal_acct where psp_id = :b0 and mb_merchant_id = :b1 and mb_service_cod\
e = :b2 and mb_country = :b3 and mb_ccy_id = :b4            ";

 static char *sq0006 = 
"SELECT mb_posting_date , mb_merchant_id , mb_country_id , mb_currency_id , \
mb_psp_id , mb_bucket_type , mb_service_code , mb_bal FROM merchant_bucket WH\
ERE mb_service_code = :b0 AND mb_bucket_type = 'FT' AND mb_posting_date <= re\
lease_pkg . find_release_date ( :b1 , mb_country_id , :b0 , :b3 ) AND mb_rele\
ased_date is null GROUP by mb_posting_date , mb_merchant_id , mb_country_id ,\
 mb_currency_id , mb_psp_id , mb_bucket_type , mb_service_code , mb_bal ORDER\
 BY mb_posting_date            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,180,0,9,126,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,128,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
43,0,0,1,0,0,15,171,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,180,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,181,0,0,0,0,0,1,0,
88,0,0,3,171,0,9,243,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
119,0,0,3,0,0,13,245,0,0,2,0,0,1,0,2,1,0,0,2,3,0,0,
142,0,0,3,0,0,15,267,0,0,0,0,0,1,0,
157,0,0,4,212,0,9,283,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
192,0,0,4,0,0,13,285,0,0,3,0,0,1,0,2,1,0,0,2,1,0,0,2,3,0,0,
219,0,0,4,0,0,15,310,0,0,0,0,0,1,0,
234,0,0,4,0,0,15,321,0,0,0,0,0,1,0,
249,0,0,3,0,0,15,322,0,0,0,0,0,1,0,
264,0,0,5,0,0,32,323,0,0,0,0,0,1,0,
279,0,0,6,491,0,9,418,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
310,0,0,6,0,0,13,420,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,4,0,0,
357,0,0,6,0,0,15,631,0,0,0,0,0,1,0,
372,0,0,6,0,0,15,654,0,0,0,0,0,1,0,
387,0,0,7,0,0,32,655,0,0,0,0,0,1,0,
402,0,0,8,71,0,4,1012,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/04/18              LokMan Chow
Change to use rule release period		   2012/08/24		   Cody Chan
Add MAPO element				   2012/09/03		   Cody Chan
un-relate service and country			   2013/01/14		   LokMan Chow
Bacause of payout refund case,
  PD_DEFAULT_PSP also allow payout		   2013/05/24		   LokMan Chow
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
int	avai_po_percentage = 0;

OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_main(const char* csPostingDate);
//int allow_payout(const char* csPspID);
int allow_payout(const char* csMerchantId,const char* csService,const char* csCcy,const char* csCountry,const char* csPspID);
//int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csCountry,int iReleasePeriod,int iSettReleasePeriod);
int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod,int iSettReleasePeriod);
int process_release(hash_t *myHash);
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

	//if (is_weekend(csPostingDate) != PD_TRUE) {
        	iRet = process_main(csPostingDate);
	//}
	//else {
//DEBUGLOG(("today is weekend.... skip....\n"));
//	}

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
	int     iSettReleasePeriod = 0;

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
                   AND rs_release_type = 'AVAPO'; */ 


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
DEBUGLOG(("service code = [%s]\n",v_service_code.arr));
		}	
/*
		if (ind_txn_country >= 0) {
			v_txn_country.arr[v_txn_country.len] = '\0';	
DEBUGLOG(("txn_country = [%s]\n",v_txn_country.arr));
		}	
*/
		if (ind_release_period >= 0) {
DEBUGLOG(("release period = [%d]\n",v_release_period));
		}


		if (v_release_period > 0) {
			//if (is_holidays((const char*)v_txn_country.arr,csPostingDate) != PD_TRUE) {
				iRet = FindServiceReleasePeriod((const char*) v_service_code.arr,PD_RLS_TYPE_SETTFT,&iSettReleasePeriod);
DEBUGLOG(("sett release period = [%d]\n",iSettReleasePeriod));
                       		if (iRet == PD_OK) {
					iRet = process_bucket(csPostingDate,(const char*)v_service_code.arr,v_release_period,iSettReleasePeriod);
				}
			//}
			//else {
//DEBUGLOG(("today is holiday for %s... skip....\n",v_txn_country.arr));
//			}
		}
		else {
DEBUGLOG(("release period is zero, skip!!!!\n"));
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

int allow_payout(const char* csMerchantId,const char* csService,const char* csCcy,const char* csCountry,const char* csPspID)
{
        int     iRet = PD_FALSE;

DEBUGLOG(("allow_payout\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

		/* varchar	hv_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_ccy;

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;


		char	v_m_txn_type;
		char	v_p_txn_type;
		int	v_avai_po_percentage;
		short	ind_m_txn_type = -1;
		short	ind_p_txn_type = -1;
		short	ind_avai_po_percentage = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("allow_payout merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_service_code.len = strlen(csService);
	memcpy(hv_service_code.arr,csService,hv_service_code.len);
DEBUGLOG(("allow_payout service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_ccy.len = strlen(csCcy);
	memcpy(hv_ccy.arr,csCcy,hv_ccy.len);
DEBUGLOG(("allow_payout ccy = [%.*s]\n",hv_ccy.len,hv_ccy.arr));

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
DEBUGLOG(("allow_payout country = [%.*s]\n",hv_country.len,hv_country.arr));

	hv_psp_id.len = strlen(csPspID);
	memcpy(hv_psp_id.arr,csPspID,hv_psp_id.len);
DEBUGLOG(("allow_payout psp_id = [%.*s]\n",hv_psp_id.len,hv_psp_id.arr));


	if(!strcmp(csPspID,PD_DEFAULT_PSP)){
           /* EXEC SQL DECLARE c_cursor_allow_po_d CURSOR FOR
		 select 
			mb_txn_type,
			mb_avai_po_percentage
  		   from 
			merchant_bal_acct
                  where mb_merchant_id = :hv_merchant_id
		  and	mb_service_code = :hv_service_code
		  and	mb_country = :hv_country
		  and	mb_ccy_id = :hv_ccy; */ 


           /* EXEC SQL OPEN c_cursor_allow_po_d; */ 

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
           sqlstm.sqhstv[0] = (unsigned char  *)&hv_merchant_id;
           sqlstm.sqhstl[0] = (unsigned long )17;
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
           if (sqlca.sqlcode < 0) goto sql_error;
}


           do {    
                /* EXEC SQL FETCH c_cursor_allow_po_d
                INTO
			v_m_txn_type:ind_m_txn_type,
			v_avai_po_percentage:ind_avai_po_percentage; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 4;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_m_txn_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_m_txn_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_avai_po_percentage;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_avai_po_percentage;
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

		if (ind_m_txn_type >= 0) {
			if (v_m_txn_type == PD_TYPE_ALL || v_m_txn_type == PD_TYPE_PAYOUT){
				iRet = PD_TRUE;
			}
		}
		if(ind_avai_po_percentage >= 0){
			avai_po_percentage = v_avai_po_percentage;
DEBUGLOG(("allow_payout: available payout percentage = [%d]\n",avai_po_percentage));
		}

DEBUGLOG(("allow_payout: Merchant[%c]\n",v_m_txn_type));

	   }while(PD_TRUE);
           /* EXEC SQL CLOSE c_cursor_allow_po_d; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 12;
           sqlstm.arrsiz = 4;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )142;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) goto sql_error;
}


	}
	else{

           /* EXEC SQL DECLARE c_cursor_allow_po CURSOR FOR
		 select txn_type,
			mb_txn_type,
			mb_avai_po_percentage
  		   from psp_detail,
			merchant_bal_acct
                  where psp_id = :hv_psp_id
		  and	mb_merchant_id = :hv_merchant_id
		  and	mb_service_code = :hv_service_code
		  and	mb_country = :hv_country
		  and	mb_ccy_id = :hv_ccy; */ 


           /* EXEC SQL OPEN c_cursor_allow_po; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 12;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.stmt = sq0004;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )157;
           sqlstm.selerr = (unsigned short)1;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlstm.sqcmod = (unsigned int )0;
           sqlstm.sqhstv[0] = (unsigned char  *)&hv_psp_id;
           sqlstm.sqhstl[0] = (unsigned long )12;
           sqlstm.sqhsts[0] = (         int  )0;
           sqlstm.sqindv[0] = (         short *)0;
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


           do {    
                /* EXEC SQL FETCH c_cursor_allow_po
                INTO
			v_p_txn_type:ind_p_txn_type,
			v_m_txn_type:ind_m_txn_type,
			v_avai_po_percentage:ind_avai_po_percentage; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 5;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )192;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_p_txn_type;
                sqlstm.sqhstl[0] = (unsigned long )1;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_p_txn_type;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_m_txn_type;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_m_txn_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_avai_po_percentage;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_avai_po_percentage;
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

		if (ind_m_txn_type >= 0) {
			if (v_m_txn_type == PD_TYPE_ALL || v_m_txn_type == PD_TYPE_PAYOUT){
				if (ind_p_txn_type >= 0) {
					if (v_p_txn_type == PD_TYPE_ALL || v_p_txn_type == PD_TYPE_PAYOUT)
						iRet = PD_TRUE;
				}
			}
			if(ind_avai_po_percentage >= 0){
				avai_po_percentage = v_avai_po_percentage;
DEBUGLOG(("allow_payout: available payout percentage = [%d]\n",avai_po_percentage));
			}
		}
DEBUGLOG(("allow_payout: Merchant[%c] Psp[%c]\n",v_m_txn_type,v_p_txn_type));

	   }while(PD_TRUE);
           /* EXEC SQL CLOSE c_cursor_allow_po; */ 

{
           struct sqlexd sqlstm;
           sqlstm.sqlvsn = 12;
           sqlstm.arrsiz = 5;
           sqlstm.sqladtp = &sqladt;
           sqlstm.sqltdsp = &sqltds;
           sqlstm.iters = (unsigned int  )1;
           sqlstm.offset = (unsigned int  )219;
           sqlstm.cud = sqlcud0;
           sqlstm.sqlest = (unsigned char  *)&sqlca;
           sqlstm.sqlety = (unsigned short)4352;
           sqlstm.occurs = (unsigned int  )0;
           sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
           if (sqlca.sqlcode < 0) goto sql_error;
}


	}

DEBUGLOG(("allow_payout: return iRet = [%d]\n",iRet));
	return	iRet;

sql_error:
    DEBUGLOG(("allow_payout error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    ERRLOG("handle_daily_float::allow_payout sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_allow_po; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )234;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    /* EXEC SQL CLOSE c_cursor_allow_po_d; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )249;
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
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )264;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return iRet;
}



//int process_bucket(const char* csPostingDate,const char* csServiceCode,const char* csCountry,int iReleasePeriod,int iSettReleasePeriod)
int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod,int iSettReleasePeriod)
{               
        int     iRet = SUCCESS;
	int	iRelease2AF = PD_FALSE;
	int	iAllowPayout = PD_FALSE;
	double	dAPBal = 0.0;
	double	dAFBal = 0.0;
	double	dTmpAvaiPO = 0.0;
	double	dReleaseBal = 0.0;
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

		//varchar	hv_country[PD_COUNTRY_LEN];
		short	hv_release_period;

		/* varchar	v_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_posting_date;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

		/* varchar	v_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_bucket_type[PD_BUCKET_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_bucket_type;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		double	v_bal;

		short	ind_posting_date = -1;
		short	ind_merchant_id = -1;
		short	ind_bal= -1;
		short	ind_psp_id= -1;
		short	ind_currency_id= -1;
		short   ind_country_id= -1;
		short	ind_bucket_type= -1;
		short	ind_service_code= -1;


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
                        mb_psp_id,
                        mb_bucket_type,
                        mb_service_code,
                        mb_bal
                  FROM merchant_bucket
                 WHERE mb_service_code = :hv_service_code
                   AND mb_bucket_type = 'FT'
                   AND mb_posting_date <= release_pkg.find_release_date(:hv_ph_posting_date,mb_country_id,:hv_service_code,:hv_release_period)
                   AND mb_released_date is null
                GROUP by mb_posting_date,
                         mb_merchant_id,
                         mb_country_id,
                         mb_currency_id,
                         mb_psp_id,
                         mb_bucket_type,
                         mb_service_code,
                         mb_bal
                ORDER BY mb_posting_date; */ 

		
                
        /* EXEC SQL OPEN c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0006;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )279;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_ph_posting_date;
        sqlstm.sqhstl[1] = (unsigned long )10;
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
         		v_psp_id:ind_psp_id,
         		v_bucket_type:ind_bucket_type,
         		v_service_code:ind_service_code,
         		v_bal:ind_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 8;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )310;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[4] = (unsigned long )13;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_psp_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_bucket_type;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_bucket_type;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_service_code;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_bal;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_bal;
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



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


		iRet = PD_OK;

                hash_init(hTxn,0);

		PutField_CString(hTxn,"cutoff_date",csPostingDate);

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

/* psp_id */
		if (ind_psp_id >= 0 ){
			v_psp_id.arr[v_psp_id.len]='\0';
			PutField_CString(hTxn,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("Process Bucket: psp_id =[%.*s]\n",v_psp_id.len,v_psp_id.arr));
		}

/* bucket_type */
		if (ind_bucket_type >= 0 ){
			v_bucket_type.arr[v_bucket_type.len]='\0';
			PutField_CString(hTxn,"bucket_type",(const char*)v_bucket_type.arr);
DEBUGLOG(("Process Bucket: bucket_type =[%.*s]\n",v_bucket_type.len,v_bucket_type.arr));
		}

/* service_code */
		if (ind_service_code >= 0 ){
			v_service_code.arr[v_service_code.len]='\0';
			PutField_CString(hTxn,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("Process Bucket: service_code =[%.*s]\n",v_service_code.len,v_service_code.arr));
		}

		if (is_holidays((const char*)v_country_id.arr,csServiceCode,csPostingDate) == PD_TRUE) {
                        iRet=PD_SKIP_OK;
DEBUGLOG(("Process Bucket: today is holiday for %s %s... skip....\n",v_country_id.arr,csServiceCode));
                }

/* bal */
/* release amount */
		if (ind_bal >= 0 ){
			if(v_bal<0.0)
				v_bal = 0.0;
				dReleaseBal = v_bal;
DEBUGLOG(("Process Bucket: bal =[%f]\n",v_bal));
			PutField_Double(hTxn,"released_amt",v_bal);
			PutField_Double(hTxn,"txn_amt",v_bal);
		}


/* release date */
		PutField_CString(hTxn,"released_date",csPostingDate);

		if(iRet==PD_OK){

/* try to lock merchant balance record */
			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValuesForUpdate");
               		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
						v_currency_id.arr,
						v_country_id.arr,
						v_service_code.arr,
						hTxn);
			if (iRet == PD_OK) {
				iAllowPayout = allow_payout((const char*)v_merchant_id.arr,(const char*)v_service_code.arr,
                                                  (const char*)v_currency_id.arr,(const char*)v_country_id.arr,
                                                  (const char*)v_psp_id.arr) ;

				if (iAllowPayout == PD_TRUE && avai_po_percentage == 100) {
DEBUGLOG(("Allow payout....\n"));
					iRelease2AF = PD_FALSE;
					PutField_Double(hTxn,"amount",v_bal);
				}
				else {
					if(iAllowPayout == PD_FALSE){
						dAFBal = v_bal;
						iRelease2AF = PD_TRUE;
						RemoveField_Double(hTxn,"amount");
DEBUGLOG(("Do not allow payout....\n"));
					}
					else{
						iRelease2AF = PD_FALSE;
DEBUGLOG(("dReleaseBal*avai_po_percentage/100 = [%lf]\n",dReleaseBal*avai_po_percentage/100));
						dTmpAvaiPO = dReleaseBal*avai_po_percentage/100;
						dAPBal = newround(dTmpAvaiPO,PD_DECIMAL_LEN);
DEBUGLOG(("dAPBal = [%lf]\n",dAPBal));
						dAFBal = v_bal - dAPBal;
						PutField_Double(hTxn,"amount",dAPBal);
DEBUGLOG(("Only allow %d percent to avai payout[%lf], [%lf] to payout float\n",avai_po_percentage,dAPBal,dAFBal));
					}


					DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","CreditMerchantAmount");
                			iRet = (unsigned long)(DBObjPtr)(v_posting_date.arr,
							v_merchant_id.arr,
							v_country_id.arr,
							v_currency_id.arr,
							v_service_code.arr,
							v_psp_id.arr,
							PD_BUCKET_TYPE_AFTER_PAYOUT_FLOAT,
							dAFBal,
							PD_UPDATE_USER);
					if (iRet != PD_OK)  {
DEBUGLOG(("CreditMerchantAmount Failure\n"));
ERRLOG("handle_daily_float:process bucket CreditMerchantAmount Failure\n");
					}
					else {
						DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","UpdateAfterPOFloat");
                				iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
								v_country_id.arr,
								v_currency_id.arr,
								v_service_code.arr,
								dAFBal,
								PD_UPDATE_USER);
						if (iRet != PD_OK)  {
DEBUGLOG(("UpdateAfterPOFloat Failure\n"));
ERRLOG("handle_daily_float:process bucket UpdateAfterPOFloat Failure\n");
						}

					}
				}

				if (iRet == PD_OK) {
					PutField_Int(hTxn,"release_to_af",iRelease2AF);
					DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","UpdateReleaseDetails");
               				iRet = (unsigned long)(DBObjPtr)(hTxn);
					if (iRet != PD_OK)  {
DEBUGLOG(("UpdateReleaseDetails Failure\n"));
ERRLOG("handle_daily_float:process bucket UpdateReleaseDetails Failure\n");
					}
				}
				if (iRet == PD_OK) {
					DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","ReleaseFloat");
                			iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
							v_country_id.arr,
							v_currency_id.arr,
							v_service_code.arr,
							v_bal,
							PD_UPDATE_USER);
					if (iRet != PD_OK)  {
DEBUGLOG(("ReleaseFloat Failure\n"));
ERRLOG("handle_daily_float:process bucket ReleaseFloat Failure\n");
					}
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
        sqlstm.offset = (unsigned int  )357;
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
    sqlstm.offset = (unsigned int  )372;
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
    sqlstm.offset = (unsigned int  )387;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}




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
	hash_t	*hEle;

	hTxn = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hTxn,0);

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
	PutField_CString(hTxn,"txn_code",PD_RELEASE_FLOAT);

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
DEBUGLOG(("AddTxnLog:: txn_amt = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"current_bal",&dTmp)){
		PutField_Double(hTxn,"current_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal = [%f]\n",dTmp));
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
		PutField_Double(hTxn,"open_bal",dTmp);
DEBUGLOG(("AddTxnLog:: current_bal = [%f]\n",dTmp));
	}

	if(GetField_Double(hVal,"current_bal_settlement",&dTmp)){
		PutField_Double(hTxn,"current_bal_settlement",dTmp);
		PutField_Double(hTxn,"open_bal_settlement",dTmp);
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
		double	dTmp = 0.0;
		
		if (GetField_Double(hVal,"amount",&dTmp)) {
			if(dTmp>0.0){
				PutField_Double(hEle,"amount",dTmp);

				PutField_CString(hEle,"txn_seq",csTxnSeq);
		
/* chg type */
                		PutField_CString(hEle,"txn_element_type",PD_ELEMENT_MAPO_AMT);

/* party type */
                		PutField_Char(hEle,"party_type",PD_TYPE_MERCHANT);

/* user */            
	      			PutField_CString(hEle,"add_user",PD_UPDATE_USER);

/* amount type */
                		PutField_CString(hEle,"amount_type",PD_CR);

				DBObjPtr = CreateObj(DBPtr,"DBTxnElements","Add");
                		iRet = (unsigned long)(*DBObjPtr)(hEle);
			}
		}
	}

DEBUGLOG(("AddTxnLog:: iRet = [%d]\n",iRet));
        hash_destroy(hEle);
	FREE_ME(hEle);

	FREE_ME(hTxn);
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
 sqlstm.offset = (unsigned int  )402;
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
