
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
    "get_email_alert_to_admin.pc"
};


static unsigned int sqlctx = 1295206587;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,252,0,6,193,0,0,8,8,0,1,0,3,3,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,0,0,3,9,
0,0,3,9,0,0,3,9,0,0,
52,0,0,2,0,0,32,235,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2014. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/02/07              Virginia Yun
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

char	cs_txn_seq[PD_TXN_SEQ_LEN + 1];
char    cs_merchant_id[PD_MERCHANT_ID_LEN + 1];
char    cs_country[PD_COUNTRY_LEN + 1];
char    cs_service[PD_SERVICE_CODE_LEN + 1];
char    cs_currency[PD_CCY_ID_LEN + 1];
char    cs_funct[PD_CODE_LEN +1];

char    cDebug = 'Y';

OBJPTR(DB);
OBJPTR(Txn);

int parse_arg(int argc,char **argv);

int process_get_template(const char *csTxnSeq,
                         const char *csMerchantId, const char *csCountry, const char *csService, const char *csCcy,
                         const char *csFunction);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}




int batch_proc(int argc, char* argv[])
{
        int     iRet;

	iRet = parse_arg(argc,argv);
               
        if (iRet != SUCCESS) {
		printf("usage:  -t txn_id -m merchant_id -c country -s service -y currency -f function\n");
                return (iRet);
        }

	if(iRet==PD_OK){
		iRet = process_get_template(cs_txn_seq, cs_merchant_id, cs_country, cs_service, cs_currency, cs_funct);
	}

	if (iRet != PD_OK) {
		iRet = FAILURE;
	}
	return iRet;


}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;

	strcpy(cs_txn_seq,"");
	strcpy(cs_merchant_id,"");
	strcpy(cs_country, "");
	strcpy(cs_service, "");
	strcpy(cs_currency, "");
	strcpy(cs_funct,"");

	while ((c = getopt(argc,argv,"t:m:c:s:y:f:")) != EOF) {
		switch (c) {
			case 't':
				strcpy(cs_txn_seq, optarg);
				break;
			case 'm':
				strcpy(cs_merchant_id, optarg);
				break;
			case 'c':
				strcpy(cs_country, optarg);
				break;
			case 's':
				strcpy(cs_service, optarg);
				break;
			case 'y':
				strcpy(cs_currency, optarg);
				break;
			case 'f':
				strcpy(cs_funct, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_txn_seq, "") || 
            !strcmp(cs_merchant_id,"") || !strcmp(cs_country, "") || !strcmp(cs_service, "") || !strcmp(cs_currency, "") ||
            !strcmp(cs_funct,"") )
		return FAILURE;

	return SUCCESS;
}


int process_get_template(const char *csTxnSeq, 
                         const char *csMerchantId, const char *csCountry, const char *csService, const char *csCcy,
                         const char *csFunction)
{
        int     iRet = PD_OK;

DEBUGLOG(("--------------process_get_template--------------\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar	hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar	hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar	hv_service[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service;

		/* varchar	hv_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_currency;

		/* varchar	hv_funct[PD_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_funct;


		short	ind_txn_id = -1;
		short	ind_merchant_id = -1;
		short	ind_country = -1;
		short	ind_service = -1;
		short	ind_currency = -1;
		short	ind_funct = -1;

		/* varchar	v_template[PD_NOTE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[2001]; } v_template;

		short	ind_template = -1;

		short   hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
	ind_txn_id = 0;
DEBUGLOG(("process_get_template txn_seq = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
	ind_merchant_id = 0;
DEBUGLOG(("process_get_template merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_country.len = strlen(csCountry);
	memcpy(hv_country.arr,csCountry,hv_country.len);
	ind_country = 0;
DEBUGLOG(("process_get_template country = [%.*s]\n",hv_country.len,hv_country.arr));

	hv_service.len = strlen(csService);
	memcpy(hv_service.arr,csService,hv_service.len);
	ind_service = 0;
DEBUGLOG(("process_get_template service = [%.*s]\n",hv_service.len,hv_service.arr));

	hv_currency.len = strlen(csCcy);
	memcpy(hv_currency.arr,csCcy,hv_currency.len);
	ind_currency = 0;
DEBUGLOG(("process_get_template currency = [%.*s]\n",hv_currency.len,hv_currency.arr));

	hv_funct.len = strlen(csFunction);
	memcpy(hv_funct.arr,csFunction,hv_funct.len);
	ind_funct= 0;
DEBUGLOG(("process_get_template function = [%.*s]\n",hv_funct.len,hv_funct.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_get_email_adm_nty_template(:hv_txn_id:ind_txn_id,
									  :hv_merchant_id:ind_merchant_id,
									  :hv_country:ind_country,
									  :hv_service:ind_service,
									  :hv_currency:ind_currency,
									  :hv_funct:ind_funct,
									  :v_template:ind_template);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 8;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_get_email_adm_nty_templ\
ate ( :hv_txn_id:ind_txn_id , :hv_merchant_id:ind_merchant_id , :hv_country:i\
nd_country , :hv_service:ind_service , :hv_currency:ind_currency , :hv_funct:\
ind_funct , :v_template:ind_template ) ; END ;";
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_country;
        sqlstm.sqhstl[3] = (unsigned long )4;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_country;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_service;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_service;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_currency;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_currency;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_funct;
        sqlstm.sqhstl[6] = (unsigned long )12;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_funct;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&v_template;
        sqlstm.sqhstl[7] = (unsigned long )2003;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_template;
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




	if (hv_return_value == SP_OK) {
DEBUGLOG(("process_get_template: Found!\n"));
			
		if(ind_template >=0){
			v_template.arr[v_template.len] = '\0';
			printf("%s\n",v_template.arr);
DEBUGLOG(("process_get_template: template = [%s]\n",v_template.arr));

		}
		else {
			iRet = PD_ERR;
		}
	} else if (hv_return_value == SP_OTHER_ERR) {
DEBUGLOG(("process_get_template other error\n"));
ERRLOG("get_email_alert_to_admin::process_get_template:other error\n");
		iRet = PD_ERR;
	} else if (hv_return_value == SP_ERR) {
DEBUGLOG(("process_get_template error\n"));
ERRLOG("get_email_alert_to_admin::process_get_template:error\n");
		iRet = PD_ERR;
	}

	return	iRet;

sql_error:
DEBUGLOG(("process_get_template error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("get_email_alert_to_admin::process_get_template sql error %d\n", sqlca.sqlcode);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL ROLLBACK RELEASE; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 8;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )52;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}
