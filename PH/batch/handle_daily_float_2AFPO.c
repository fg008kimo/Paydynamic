
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
           char  filnam[28];
};
static struct sqlcxp sqlfpn =
{
    27,
    "handle_daily_float_2AFPO.pc"
};


static unsigned int sqlctx = 937983507;


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
   unsigned char  *sqhstv[5];
   unsigned long  sqhstl[5];
            int   sqhsts[5];
            short *sqindv[5];
            int   sqinds[5];
   unsigned long  sqharm[5];
   unsigned long  *sqharc[5];
   unsigned short  sqadto[5];
   unsigned short  sqtdso[5];
} sqlstm = {12,5};

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
"SELECT m_merchant_id , m_country_id , m_currency_id , m_service_code , ava_\
po FROM merchant_balance_view WHERE ava_po > 0 and m_service_code = :b0      \
      ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,180,0,9,122,0,2049,0,0,0,1,0,
20,0,0,1,0,0,13,124,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
43,0,0,1,0,0,15,167,0,0,0,0,0,1,0,
58,0,0,1,0,0,15,176,0,0,0,0,0,1,0,
73,0,0,2,0,0,32,177,0,0,0,0,0,1,0,
88,0,0,3,158,0,9,270,0,2049,1,1,0,1,0,1,9,0,0,
107,0,0,3,0,0,13,272,0,0,5,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
142,0,0,3,0,0,15,496,0,0,0,0,0,1,0,
157,0,0,3,0,0,15,513,0,0,0,0,0,1,0,
172,0,0,4,0,0,32,514,0,0,0,0,0,1,0,
187,0,0,5,71,0,4,560,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
Init Version                                       2012/08/27              Cody Chan
un-relate service and country			   2013/01/14		   LokMan Chow
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

char	cPreviewMode;
char    cDebug = 'Y';


OBJPTR(DB);

int parse_arg(int argc,char **argv);
int process_main(const char* csPostingDate);
int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod,int iSettReleasePeriod);
int CalReservedAmount(const char* csMerchantId,
			const char* csCountryId,
			const char* csCcy,
			const char* csServiceCode,
			const char* csDate,
			double	*dAmt);
int AddTxnLog(const hash_t* hVal);
int     GetClientId(const unsigned char* csMerchantId,
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
	int	iSettReleasePeriod = 0;

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



int parse_arg(int argc,char **argv)
{
        char    c;
        cPreviewMode = PD_YES;

        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                cPreviewMode =  optarg[0];
                                break;
                        default:
                                return FAILURE;
                }
        }

	if (cPreviewMode != 'N' && cPreviewMode != 'n' )
		cPreviewMode = PD_YES;
DEBUGLOG(("parse_arg previewmode = [%c]\n",cPreviewMode));

        return SUCCESS;
}



int process_bucket(const char* csPostingDate,const char* csServiceCode,int iReleasePeriod,int iSettReleasePeriod)
{
        int     iRet = SUCCESS;
        char    csClientId[PD_CLIENT_ID_LEN+1];
	char	csOrgPostingDate[PD_DATE_LEN +1];

        hash_t* hTxn;
        hTxn = (hash_t*) malloc (sizeof(hash_t));

DEBUGLOG(("*****Process Bucket Start*****\n"));

        /* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar hv_ph_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_ph_posting_date;

                /* varchar hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                short   hv_release_period;

                /* varchar v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar v_country_id[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country_id;

                /* varchar v_currency_id[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency_id;

                /* varchar v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                double  v_ava_po;

                short   ind_merchant_id = -1;
                short   ind_currency_id= -1;
                short   ind_country_id= -1;
                short   ind_service_code= -1;
                short   ind_ava_po= -1;



        /* EXEC SQL END DECLARE SECTION; */ 


        hv_ph_posting_date.len = strlen(csPostingDate);
        memcpy(hv_ph_posting_date.arr,csPostingDate,hv_ph_posting_date.len);
DEBUGLOG(("process_bucket ph posting date = [%.*s]\n",hv_ph_posting_date.len,hv_ph_posting_date.arr));

        hv_service_code.len = strlen(csServiceCode);
        memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("process_bucket service_code  = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

        hv_release_period = iReleasePeriod;
DEBUGLOG(("process_bucket release_period = [%d]\n",hv_release_period));

	if (cPreviewMode == PD_NO) {
          	DBObjPtr = CreateObj(DBPtr,"DBMerchantBucketPreview","DelAll");
       		iRet = (unsigned long)(DBObjPtr)();
	}

        /* EXEC SQL DECLARE c_cursor_get_bucket CURSOR FOR
		SELECT m_merchant_id,
			m_country_id,
       			m_currency_id,
       			m_service_code,
       			ava_po
 		   FROM merchant_balance_view
                  WHERE ava_po > 0
                    and m_service_code = :hv_service_code; */ 



        /* EXEC SQL OPEN c_cursor_get_bucket; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 2;
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
                /* EXEC SQL FETCH c_cursor_get_bucket
                INTO
                        v_merchant_id:ind_merchant_id,
                        v_country_id:ind_country_id,
                        v_currency_id:ind_currency_id,
                        v_service_code:ind_service_code,
                        v_ava_po:ind_ava_po; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 5;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )107;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_country_id;
                sqlstm.sqhstl[1] = (unsigned long )5;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_country_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_currency_id;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_currency_id;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_ava_po;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_ava_po;
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



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }


                iRet = PD_OK;

                hash_init(hTxn,0);

                PutField_CString(hTxn,"cutoff_date",csPostingDate);

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

/* ava po */
                if (ind_ava_po < 0 ){
			v_ava_po = 0.0;
		}
DEBUGLOG(("Process Bucket: aval for PO = [%f]\n",v_ava_po));

		if (v_ava_po > 0  &&
		    is_holidays((const char*)v_country_id.arr,csServiceCode,csPostingDate) != PD_TRUE) {
			double  dDailyReservedAmt = 0.0;
                        double  dTotalReservedAmt = 0.0;
                        double  dCurrentBal = 0.0;
                        double  dTotalHold = 0.0;
                        double  dFinPayout = 0.0;	
			double  dReleaseAmount = 0.0;
			double	dNewReservedAmt = 0.0;

			DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValuesForUpdate");
                       	iRet = (unsigned long)(DBObjPtr)((const char*) v_merchant_id.arr,
                       			(const char*)v_currency_id.arr,
                                        (const char*)v_country_id.arr,
                                        (const char*)v_service_code.arr,
                                        hTxn);	

			if (iRet == PD_OK) {
				if (!GetField_Double(hTxn,"total_reserved_amount",&dTotalReservedAmt)) {
                               		dTotalReservedAmt = 0.0;
                  		}
DEBUGLOG(("process bucket: total reserved amt = [%f]\n",dTotalReservedAmt));
                               	if (!GetField_Double(hTxn,"current_bal",&dCurrentBal)) {
                               		dCurrentBal = 0.0;
                                }
DEBUGLOG(("process bucket: current bal = [%f]\n",dCurrentBal));
                          	if (!GetField_Double(hTxn,"total_hold",&dTotalHold)) {
                               		dTotalHold = 0.0;
                            	}
DEBUGLOG(("process bucket: total hold = [%f]\n",dTotalHold));

                                if (!GetField_Double(hTxn,"fundin_payout",&dFinPayout)) {
                               		dFinPayout = 0.0;
                                }
DEBUGLOG(("process bucket: Fund in for Payout = [%f]\n",dFinPayout));
	
				iRet = CalReservedAmount((const char*)v_merchant_id.arr,
                                                        (const char*)v_country_id.arr,
                                                        (const char*)v_currency_id.arr,
                                                        (const char*)v_service_code.arr,
                                                        csPostingDate,
                                                        &dDailyReservedAmt);
				dReleaseAmount = v_ava_po;
DEBUGLOG(("process bucket: Release Amount = [%f]\n",dReleaseAmount));

				if(dReleaseAmount>dFinPayout)
					dReleaseAmount =  (double) (dReleaseAmount - dFinPayout);
				else
					dReleaseAmount = 0.0;
DEBUGLOG(("process bucket: Release Amount = [%f] after FinPayout\n",dReleaseAmount));

				dNewReservedAmt = dDailyReservedAmt;
DEBUGLOG(("process bucket: new ReservedAmt = [%f]\n",dNewReservedAmt));

				if (dNewReservedAmt  != 0.0) {
					if (dNewReservedAmt > dReleaseAmount) {
						dNewReservedAmt = dReleaseAmount;
						dReleaseAmount = 0.0;
					}
					else {
						dReleaseAmount = dReleaseAmount - dNewReservedAmt;
					}
				}
DEBUGLOG(("process bucket: new ReservedAmt = [%f] new Release Amount = [%f]\n",dNewReservedAmt,dReleaseAmount));
				dReleaseAmount = newround (dReleaseAmount, 2);
				if (dReleaseAmount > 0.0) {
					strcpy(csOrgPostingDate,FindPostingDate((const char*)v_country_id.arr,csServiceCode,csPostingDate,iReleasePeriod));
DEBUGLOG(("process bucket: Release to Sett Float date = [%s]\n",csOrgPostingDate));
/*** do release ***/
					if (cPreviewMode == PD_NO) {
						DBObjPtr = CreateObj(DBPtr,"DBMerchantBucket","CreditMerchantAmount");
                                		iRet = (unsigned long)(DBObjPtr)(csOrgPostingDate,
                                               		v_merchant_id.arr,
                                                	v_country_id.arr,
                                                	v_currency_id.arr,
                                                	v_service_code.arr,
                                                	PD_DEFAULT_PSP,
                                                	PD_BUCKET_TYPE_AFTER_PAYOUT_FLOAT,
                                                	dReleaseAmount,
                                                	PD_UPDATE_USER);
                                		if (iRet != PD_OK)  {
DEBUGLOG(("CreditMerchantAmount Failure\n"));
ERRLOG("handle_daily_float_2AFPO:process bucket CreditMerchantAmount Failure\n");
                                		}
						else {
							DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","RlsFloat2AfterPOFloat");
                                			iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
								v_country_id.arr,
								v_currency_id.arr,
								v_service_code.arr,
								dReleaseAmount,
								PD_UPDATE_USER);
						}
					}
				}

				if (iRet == PD_OK) {
/** update total reserved amount */
					if (cPreviewMode == PD_NO) {
						DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","UpdateReservedPO");
                                		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
								v_country_id.arr,
								v_currency_id.arr,
								v_service_code.arr,
								dNewReservedAmt,
								PD_UPDATE_USER);
                              		  	if (iRet != PD_OK)  {
DEBUGLOG(("UpdateResrevedPO Failure\n"));
ERRLOG("handle_daily_float_2AFPO:process bucket UpdateResrevedPO Failure\n");
                               		 	}
					}
				}

				if (iRet == PD_OK) {
					if (cPreviewMode == PD_NO) {
                                		DBObjPtr = CreateObj(DBPtr,"DBMerchantBalance","GetCurrentValues");
                                		iRet = (unsigned long)(DBObjPtr)(v_merchant_id.arr,
                                       	        	v_currency_id.arr,
                                                	v_country_id.arr,
                                                	v_service_code.arr,
                                                	hTxn);
                                		if (iRet == PD_OK && dReleaseAmount>0.0) {
							PutField_Double(hTxn,"txn_amt",dReleaseAmount);
                                        		PutField_Char(hTxn,"status",PD_COMPLETE);
                                        		PutField_Char(hTxn,"ar_ind",PD_ACCEPT);
                                       	 		PutField_Int(hTxn,"internal_code",PD_OK);
                                        		PutField_CString(hTxn,"response_code","0");
                                        		PutField_CString(hTxn,"sub_status",PD_APPROVED);
                                        		iRet = AddTxnLog(hTxn);
                                		}
					}
					else {
						if (dReleaseAmount > 0.0 ) {
/* create preview records */
DEBUGLOG(("Create Preview Record*****************************************\n"));
							DBObjPtr = CreateObj(DBPtr,"DBMerchantBucketPreview","AddPreviewAmount");
                                			iRet = (unsigned long)(DBObjPtr)(csOrgPostingDate,
                                               			v_merchant_id.arr,
                                                		v_country_id.arr,
                                                		v_currency_id.arr,
                                                		v_service_code.arr,
                                                		PD_DEFAULT_PSP,
                                                		PD_BUCKET_TYPE_AFTER_PAYOUT_FLOAT,
                                                		dReleaseAmount,
                                                		PD_UPDATE_USER);
DEBUGLOG(("iRet = [%d] from AddPreviewAmount\n"));
						}
					}
                        	}	

			}
        		if (iRet == PD_OK)  {
                		iRet = SUCCESS;
                		TxnCommit();
        		}
        		else
                		iRet = FAILURE;
		}
		else{
DEBUGLOG(("today is holiday for %s... skip....\n",v_country_id.arr));
		}

                hash_destroy(hTxn);
        }
        while(PD_TRUE);

 	/* EXEC SQL CLOSE c_cursor_get_bucket; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 5;
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
    sqlstm.arrsiz = 5;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )157;
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
    sqlstm.offset = (unsigned int  )172;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int CalReservedAmount(const char* csMerchantId,
			const char* csCountryId,
			const char* csCcy,
			const char* csServiceCode,
			const char* csDate,
			double* dAmt)
{
	int	iRet = PD_OK;
	double	dDailyAmt = 0.0;

	DBObjPtr = CreateObj(DBPtr,"DBMerchantReservedAmt","GetReservedAmtForDate");
	iRet = (unsigned long)(DBObjPtr)(csMerchantId,
                                                csCountryId,
                                                csCcy,
                                                csServiceCode,
						csDate,
                                                &dDailyAmt);
DEBUGLOG(("CalReservedAmount Reserved Amt for today is [%f]\n",dDailyAmt));
	*dAmt = dDailyAmt;

	return iRet;
}

int     GetClientId(const unsigned char* csMerchantId,
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
                INTO    :v_client_id:ind_client_id
                FROM    merch_detail
                WHERE   merchant_id = :hv_merchant_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 5;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select client_id INTO :b0:b1 FROM merch_detail WHERE\
 merchant_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )187;
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

int AddTxnLog(const hash_t* hVal)
{
        int     iRet = PD_OK;
        char    csTxnSeq[PD_TXN_SEQ_LEN+1];
        char    *csTmp;
        char    cTmp;
        double  dTmp;
        int     iTmp;
        char    csDateTime[PD_DATETIME_LEN +1];
        char    csDate[PD_DATE_LEN +1];
        char    csTime[PD_TIME_LEN +1];

        hash_t  *hTxn;
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
        PutField_CString(hTxn,"txn_code",PD_RELEASE_FLOAT_2_AFTER_FLOAT);


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
                PutField_CString(hEle,"txn_seq",csTxnSeq);


/* chg type */
                PutField_CString(hEle,"txn_element_type",PD_ELEMENT_MAPO_AMT);

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

