
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
           char  filnam[14];
};
static struct sqlcxp sqlfpn =
{
    13,
    "eod_glpost.pc"
};


static unsigned int sqlctx = 600651;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
5,0,0,1,0,0,17,225,0,0,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,45,230,0,0,0,0,0,1,0,
39,0,0,1,0,0,13,232,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,4,0,0,
90,0,0,1,0,0,15,306,0,0,0,0,0,1,0,
105,0,0,1,0,0,15,326,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/06/22              Cody Chan
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sqlca.h>
#include <sys/types.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "eod_glutility.h"
#include "eod_glposttxn.h"
#include "debug.h"
#include "ObjPtr.h"
#include "internal.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);
char	cs_date[PD_DATE_LEN +1];

char    cDebug = 'Y';
static int parse_arg(int argc,char **argv);
int     UpdateContext(hash_t* hContext);

int batch_init(int argc, char* argv[])
{
	if (argc < 1) {
        	return FAILURE;
    	}
    	else
        	return SUCCESS;
}

int init_data(rDATA_T *rRec) 
{
	rRec->total_count=10;
	int	i = 0;

	data_t	*pp,**pa;
	pa = malloc(rRec->total_count * sizeof (data_t*));

/*

	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_PSP_AMT);
	pp->ccyname = strdup("tp_txn_ccy");	
	pp->amtname = strdup("tp_txn_amount");	
	pp->chargetype = strdup("");	
	pa[0] = pp;

	

*/
/* reserve amount */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_RES_AMT);
	pp->ccyname = strdup("td_txn_ccy");	
	pp->amtname = strdup("th_reserve_amount");	
	pp->chargetype = strdup("");	
	pa[i++] = pp;
/* psp fee */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_PSP_FEE);
	pp->ccyname = strdup("tp_txn_ccy");	
	pp->amtname = strdup("tp_service_fee");	
	pp->chargetype = strdup("");	
	pa[i++] = pp;

	
/* txn amt */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_TXN_AMT);
	pp->ccyname = strdup("td_txn_ccy");	
	pp->amtname = strdup("th_transaction_amount");	
	pp->chargetype = strdup("");	
	pa[i++] = pp;

/* net amt */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_NET_AMT);
	pp->ccyname = strdup("td_txn_ccy");	
	pp->amtname = strdup("th_net_amount");	
	pp->chargetype = strdup("");	
	pa[i++] = pp;


/* merchant markup */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_M_MARKUP);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_MARKUP);	
	pp->custtype = PD_CHG_PARTY_MERCHANT;
	pa[i++] = pp;

/* customer markup */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_C_MARKUP);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_MARKUP);	
	pp->custtype = PD_CHG_PARTY_CUSTOMER;
	pa[i++] = pp;

/* merchant fee */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_M_FEE);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_FEE);	
	pp->custtype = PD_CHG_PARTY_MERCHANT;
	pa[i++] = pp;
	
/* customer fee */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_C_FEE);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_FEE);	
	pp->custtype = PD_CHG_PARTY_CUSTOMER;
	pa[i++] = pp;
	rRec->data = pa;

/* merchant fx markup  */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_M_XU);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_XU);	
	pp->custtype = PD_CHG_PARTY_MERCHANT;
	pa[i++] = pp;

/* customer fx markup  */
	pp = malloc(sizeof (data_t));
	pp->type = strdup(PD_TYPE_C_XU);
	pp->ccyname = strdup("tf_ccy");	
	pp->amtname = strdup("tf_fee");	
	pp->chargetype = strdup(PD_TXN_CHG_TYPE_XU);	
	pp->custtype = PD_CHG_PARTY_CUSTOMER;
	pa[i++] = pp;

	return PD_OK;
}

int batch_proc(int argc, char* argv[])
{
	int	iRet = PD_OK;
	int	i;
	hash_t	*hContext;

	unsigned char	csSQL[PD_MAX_BUFFER + 1];
	rDATA_T	rData;



	NODE *Nptr = NULL;
	Nptr = (NODE *)malloc(sizeof(NODE));
	Nptr->next = NULL;

	hContext = (hash_t*) malloc (sizeof(hash_t));
        hash_init(hContext,0);
   
	iRet = parse_arg(argc,argv);
        if (iRet != SUCCESS) {
        	printf("usage:  -d <date>\n");
                return (iRet);
        }
	
	PutField_CString(hContext,"txn_date",cs_date);
 	UpdateContext(hContext);

	/* EXEC SQL WHENEVER SQLERROR GOTO getrec_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_dynstmt[PD_MAX_BUFFER + 1]; */ 
struct { unsigned short len; unsigned char arr[16393]; } hv_dynstmt;


		/* varchar	v_txn_id[PD_TXN_SEQ_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_country[PD_COUNTRY_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_psp_id[PD_PSP_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_txn_type[20]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_txn_type;

		/* varchar	v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		double	v_amount;

		short	ind_txn_id = -1;
		short	ind_txn_code = -1;
		short	ind_txn_country = -1;
		short	ind_merchant_id = -1;
		short	ind_service_code = -1;
		short	ind_psp_id = -1;
		short	ind_txn_type = -1;
		short	ind_ccy = -1;
		short	ind_amount = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	
	memset(csSQL,0,PD_MAX_BUFFER);
	iRet = init_data(&rData);

//DEBUGLOG(("total = [%d]\n",rData.total_count));
	for (i = 0 ; i < rData.total_count;i++) {
		iRet = GenSQL(cs_date,rData.data[i],csSQL);
//DEBUGLOG(("len of SQL = [%d]\n",strlen(csSQL)));
	}

//DEBUGLOG(("[%s]\n",csSQL));
	strcpy(hv_dynstmt.arr,csSQL);
	hv_dynstmt.len = strlen(csSQL);

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )16395;
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
 if (sqlca.sqlcode < 0) goto getrec_error;
}



	/* EXEC SQL DECLARE c_cursor_getrec CURSOR FOR PS; */ 


	
        /* EXEC SQL OPEN c_cursor_getrec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 1;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )24;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getrec_error;
}


        do { 
                /* EXEC SQL FETCH c_cursor_getrec
                INTO 
			:v_txn_id:ind_txn_id,
			:v_txn_code:ind_txn_code,
			:v_txn_country:ind_txn_country,
			:v_merchant_id:ind_merchant_id,
			:v_service_code:ind_service_code,
			:v_psp_id:ind_psp_id,
			:v_txn_type:ind_txn_type,
			:v_ccy:ind_ccy,
			:v_amount:ind_amount; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 9;
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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_code;
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
                sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[3] = (unsigned long )18;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[5] = (unsigned long )13;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_psp_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_type;
                sqlstm.sqhstl[6] = (unsigned long )22;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_type;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_ccy;
                sqlstm.sqhstl[7] = (unsigned long )6;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_ccy;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_amount;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_amount;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getrec_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

/* txn id */
		if (ind_txn_id >= 0 ) {
			v_txn_id.arr[v_txn_id.len] = '\0';
//DEBUGLOG(("txn_id = [%s]\n",v_txn_id.arr));
		}

/* txn code */
		if (ind_txn_code >= 0 ) {
			v_txn_code.arr[v_txn_code.len] = '\0';
//DEBUGLOG(("txn_code = [%s]\n",v_txn_code.arr));
		}

/* txn country */
		if (ind_txn_country >= 0 ) {
			v_txn_country.arr[v_txn_country.len] = '\0';
//DEBUGLOG(("txn_country = [%s]\n",v_txn_country.arr));
		}

/* merchant id */
		if (ind_merchant_id >= 0 ) {
			v_merchant_id.arr[v_merchant_id.len] = '\0';
//DEBUGLOG(("merchant_id = [%s]\n",v_merchant_id.arr));
		}

/* psp id */
		if (ind_psp_id >= 0 ) {
			v_psp_id.arr[v_psp_id.len] = '\0';
//DEBUGLOG(("psp_id = [%s]\n",v_psp_id.arr));
		}

/* txn_type*/
		if (ind_txn_type >= 0 ) {
			v_txn_type.arr[v_txn_type.len] = '\0';
//DEBUGLOG(("txn_type = [%s]\n",v_txn_type.arr));
		}
/* ccy*/
		if (ind_ccy >= 0 ) {
			v_ccy.arr[v_ccy.len] = '\0';
//DEBUGLOG(("ccy = [%s]\n",v_ccy.arr));
		}
/* amount */
		if (ind_amount < 0 ) {
			v_amount = 0.0;
		}
//DEBUGLOG(("amount = [%lf]\n",v_amount));

		iRet = GroupRecs(Nptr,
				v_txn_code.arr,
				v_txn_country.arr,
				v_merchant_id.arr,
				v_psp_id.arr,
				v_service_code.arr,
				v_txn_type.arr,
				v_ccy.arr,
				v_amount);

	}
	while(PD_TRUE);
	/* EXEC SQL CLOSE c_cursor_getrec; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getrec_error;
}



	if (iRet == PD_OK) 
		iRet = PostTxn(hContext,Nptr);


	if (iRet == PD_OK)
		iRet = SUCCESS;
	else 
		iRet = FAILURE;
	FREE_ME(Nptr);

	FREE_ME(hContext);
//	iRet = FAILURE;
	return iRet;

getrec_error:
//DEBUGLOG(("getrec_error code %d\n", sqlca.sqlcode));
//DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getrec; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 9;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )105;
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

                                
static int parse_arg(int argc,char **argv)
{                               
        char    c;              
        strcpy(cs_date,"");
                                
        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
                                strcpy(cs_date, optarg);
                                break;
                        default:        
                                return FAILURE;
                }       
        }               
                                
        if (!strcmp(cs_date,""))
                return FAILURE;                 
                                                
        return SUCCESS;                 
}                        


int     UpdateContext(hash_t* hContext)
{
        int     iRet = PD_OK;
        hash_t  *hRec;
        char    *csCode;
        char    *csValue;
        recordset_t     *rRecordSet;
        rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
        recordset_init(rRecordSet,0);


        DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetAllCodes");
        if ((*DBObjPtr)(rRecordSet) == PD_OK) {
DEBUGLOG(("UpdateContext: return \n"));
                hRec = RecordSet_GetFirst(rRecordSet);
                while (hRec) {
                        if (GetField_CString(hRec,"code",&csCode)) {
                                if (GetField_CString(hRec,"value",&csValue)) {
                                        if (!strcmp(csCode,"CTPHDATE")) {
DEBUGLOG(("UpdateContext:Current Processor Hub Date= [%s]\n",csValue));
                                                PutField_CString(hContext,"PHDATE",csValue);
                                        }
                                }
                        }
                        hRec = RecordSet_GetNext(rRecordSet);
                }
        }
        else {
DEBUGLOG(("UpdateContext:NOT RECORD\n"));
                iRet = PD_ERR;
ERRLOG("Internal Error:WEB Channel:SystemControl Record Not Found\n");
        }

        if (iRet == PD_OK) {
                char*   csValueTmp;
                csValueTmp = (char*) malloc (128);
                DBObjPtr = CreateObj(DBPtr,"DBSystemParameter","FindCode");
                if ((unsigned long)(DBObjPtr)(PD_BASED_CCY,csValueTmp) == FOUND) {
DEBUGLOG(("based ccy  = [%s]\n",csValueTmp));
                        PutField_CString(hContext,"based_ccy",csValueTmp);
                }
                else {
                        iRet = INT_ERR;
ERRLOG("Unable to find based ccy\n");
                }
                FREE_ME(csValueTmp);
        }

        RecordSet_Destroy(rRecordSet);
        FREE_ME(rRecordSet);
        FREE_ME(csCode);
        FREE_ME(csValue);
DEBUGLOG(("iRet = [%d]\n",iRet));

        return iRet;
}
