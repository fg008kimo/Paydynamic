
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
    "chk_crr_approve_deposit.pc"
};


static unsigned int sqlctx = 502169579;


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
   unsigned char  *sqhstv[12];
   unsigned long  sqhstl[12];
            int   sqhsts[12];
            short *sqindv[12];
            int   sqinds[12];
   unsigned long  sqharm[12];
   unsigned long  *sqharc[12];
   unsigned short  sqadto[12];
   unsigned short  sqtdso[12];
} sqlstm = {12,12};

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
"select cr_txn_date , cr_country , cr_product , te_party_type , party_id , c\
r_currency , cr_jnl_type_id , cr_jnl_entry_type_id , cr_ind , cr_gl_id , txn_\
count , cr_amount from crr_apl_deposit_view where cr_txn_date = :b0:b1 and cr\
_country = :b2:b3 and cr_product = :b4:b5            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,282,0,9,189,0,2049,3,3,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,
32,0,0,1,0,0,13,191,0,0,12,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,
95,0,0,1,0,0,15,276,0,0,0,0,0,1,0,
110,0,0,1,0,0,15,285,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/10/31              Virginia Yun
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
#include "ObjPtr.h"
#include "dbutility.h"
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"


#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(Txn);
OBJPTR(DB);
OBJPTR(Channel);

char    cDebug;

char	csDate[PD_DATE_LEN + 1];

recordset_t *rRecordSet;

int parse_arg(int argc,char **argv);
int process_crr();

int batch_init(int argc, char* argv[])
{
	if (argc < 3) {
		printf("usage: -d date\n");
		return FAILURE;
	}
	else 
		return SUCCESS;
}


int batch_proc(int argc, char* argv[])
{
	int	iRet;

	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS) {
		printf("usage: -d date\n");
		return (iRet);
	}

	iRet = process_crr();

	return iRet;

}


int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}


                        
int parse_arg(int argc,char **argv)
{               
        char    c;

	strcpy(csDate, "");
                        
        while ((c = getopt(argc,argv,"d:")) != EOF) {
                switch (c) {
                        case 'd':
				//memset(csDate, 0, sizeof(csDate));
				strcpy(csDate, optarg);
                                break;

                        default:
                                return FAILURE;
                }
        }       
       
DEBUGLOG(("Date [%s]\n", csDate)); 
                
        return SUCCESS; 
}               


int process_crr() 
{
//	int 	iRet = SUCCESS;

	hash_t *myHash;

	/* EXEC SQL WHENEVER SQLERROR GOTO process_crr_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_cr_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_cr_txn_date;

		short   ind_cr_txn_date = -1;

                /* varchar v_country[PD_COUNTRY_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                short   ind_country = -1;

                /* varchar v_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_product;

                short   ind_product = -1;

                //varchar v_party_type[PD_PARTY_TYPE_LEN + 1];
                /* varchar v_party_type[1 + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_party_type;

                short   ind_party_type = -1;

                //varchar v_party_id[PD_PARTY_ID_LEN + 1];
                /* varchar v_party_id[15 + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;

                short   ind_party_id = -1;

                /* varchar v_currency[PD_CURRENCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_currency;

                short   ind_currency = -1;

                int     v_jnl_type_id;
                short   ind_jnl_type_id = -1;

                /* varchar v_jnl_entry_type_id[PD_JNL_ENTRY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_jnl_entry_type_id;

                short   ind_jnl_entry_type_id = -1;

                /* varchar v_cr_ind[PD_CR_IND_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[2]; } v_cr_ind;

                short   ind_cr_ind = -1;

                int     v_gl_id;
                short   ind_gl_id = -1;

                int     v_txn_cnt;
                short   ind_txn_cnt = -1;

                double  v_txn_amt;
                short   ind_txn_amt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Begin...\n"));
        v_cr_txn_date.len = strlen(csDate);
        memcpy(v_cr_txn_date.arr,csDate,v_cr_txn_date.len);
        ind_cr_txn_date = 0;

        v_country.len = strlen("CN");
        memcpy(v_country.arr, "CN",v_country.len);
        ind_country = 0;

        v_product.len = strlen("HBD");
        memcpy(v_product.arr, "HBD",v_product.len);
        ind_product = 0;

DEBUGLOG(("date [%.*s]\n", v_cr_txn_date.len,v_cr_txn_date.arr));
DEBUGLOG(("country [%.*s]\n", v_country.len, v_country.arr));
DEBUGLOG(("product [%.*s]\n", v_product.len, v_product.arr));

	/* EXEC SQL DECLARE c_cursor_GetCrr CURSOR FOR
		select cr_txn_date, 
                       cr_country, 
                       cr_product, 
                       te_party_type, 
                       party_id, 
                       cr_currency, 
                       cr_jnl_type_id,
                       cr_jnl_entry_type_id, 
                       cr_ind, 
                       cr_gl_id, 
                       txn_count, 
                       cr_amount
                from crr_apl_deposit_view
                where cr_txn_date = :v_cr_txn_date:ind_cr_txn_date 
                  and cr_country = :v_country:ind_country 
                  and cr_product = :v_product:ind_product; */ 


        /* EXEC SQL OPEN c_cursor_GetCrr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 3;
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
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_country;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
        sqlstm.sqhstl[2] = (unsigned long )6;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_product;
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
        if (sqlca.sqlcode < 0) goto process_crr_error;
}


        do {   
                /* EXEC SQL FETCH c_cursor_GetCrr
                INTO
                        :v_cr_txn_date:ind_cr_txn_date,
                        :v_country:ind_country,
                        :v_product:ind_product,
                        :v_party_type:ind_party_type,
                        :v_party_id:ind_party_id,
                        :v_currency:ind_currency,
                        :v_jnl_type_id:ind_jnl_type_id,
                        :v_jnl_entry_type_id:ind_jnl_entry_type_id,
                        :v_cr_ind:ind_cr_ind,
                        :v_gl_id:ind_gl_id,
                        :v_txn_cnt:ind_txn_cnt,
                        :v_txn_amt:ind_txn_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 12;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )32;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_cr_txn_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_cr_txn_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[1] = (unsigned long )5;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_country;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_product;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_product;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_party_type;
                sqlstm.sqhstl[3] = (unsigned long )4;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_party_type;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_party_id;
                sqlstm.sqhstl[4] = (unsigned long )18;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_party_id;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_currency;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_currency;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_jnl_type_id;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_jnl_type_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_jnl_entry_type_id;
                sqlstm.sqhstl[7] = (unsigned long )23;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_jnl_entry_type_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_cr_ind;
                sqlstm.sqhstl[8] = (unsigned long )4;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_cr_ind;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_gl_id;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_gl_id;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_cnt;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_txn_cnt;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
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
                if (sqlca.sqlcode < 0) goto process_crr_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }

                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);


DEBUGLOG(("-------------------------\n"));

                        if (ind_cr_txn_date >= 0) {
                                v_cr_txn_date.arr[v_cr_txn_date.len] ='\0';
                                PutField_CString(myHash,"v_cr_txn_date",(const char*)v_cr_txn_date.arr);
DEBUGLOG(("v_cr_txn_date = [%s]\n",v_cr_txn_date.arr));
                        }
                        if (ind_country >= 0) {
                                v_country.arr[v_country.len] ='\0';
                                PutField_CString(myHash,"v_country",(const char*)v_country.arr);
DEBUGLOG(("v_country = [%s]\n",v_country.arr));
                        }
                        if (ind_product >= 0) {
                                v_product.arr[v_product.len] ='\0';
                                PutField_CString(myHash,"v_product",(const char*)v_product.arr);
DEBUGLOG(("v_product = [%s]\n",v_product.arr));
                        }
                        if (ind_party_type >= 0) {
                                v_party_type.arr[v_party_type.len] ='\0';
                                PutField_CString(myHash,"v_party_type",(const char*)v_party_type.arr);
DEBUGLOG(("v_party_type = [%s]\n",v_party_type.arr));
                        }
                        if (ind_party_id >= 0) {
                                v_party_id.arr[v_party_id.len] ='\0';
                                PutField_CString(myHash,"v_party_id",(const char*)v_party_id.arr);
DEBUGLOG(("v_party_id = [%s]\n",v_party_id.arr));
                        }
                        if (ind_currency >= 0) {
                                v_currency.arr[v_currency.len] ='\0';
                                PutField_CString(myHash,"v_currency",(const char*)v_currency.arr);
DEBUGLOG(("v_currency = [%s]\n",v_currency.arr));
                        }
                        if (ind_jnl_type_id >= 0) {
                                PutField_Int(myHash,"v_jnl_type_id",(int)v_jnl_type_id);
DEBUGLOG(("v_jnl_type_id = [%d]\n",v_jnl_type_id));
                        }
                        if (ind_jnl_entry_type_id >= 0) {
                                v_jnl_entry_type_id.arr[v_jnl_entry_type_id.len] ='\0';
                                PutField_CString(myHash,"v_jnl_entry_type_id",(const char*)v_jnl_entry_type_id.arr);
DEBUGLOG(("v_jnl_entry_type_id = [%s]\n",v_jnl_entry_type_id.arr));
                        }
                        if (ind_cr_ind >= 0) {
                                v_cr_ind.arr[v_cr_ind.len] ='\0';
                                PutField_CString(myHash,"v_cr_ind",(const char*)v_cr_ind.arr);
DEBUGLOG(("v_cr_ind = [%s]\n",v_cr_ind.arr));
                        }
                        if (ind_gl_id >= 0) {
                                PutField_Int(myHash,"v_gl_id",(int)v_gl_id);
DEBUGLOG(("v_gl_id = [%d]\n",v_gl_id));
                        }
                        if (ind_txn_cnt >= 0) {
                                PutField_Int(myHash,"v_txn_cnt",(int)v_txn_cnt);
DEBUGLOG(("v_txn_cnt = [%d]\n",v_txn_cnt));
                        }
                        if (ind_txn_amt >= 0) {
                                PutField_Double(myHash,"v_txn_amt",(double)v_txn_amt);
DEBUGLOG(("v_txn_amt = [%f]\n",v_txn_amt));
                        }

                }
                while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_GetCrr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )95;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto process_crr_error;
}



DEBUGLOG(("GetApprovedDeposit Normal Exit\n"));
        return  PD_OK;

process_crr_error:
DEBUGLOG(("GetApprovedDeposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_GetCrr; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 12;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )110;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


}

