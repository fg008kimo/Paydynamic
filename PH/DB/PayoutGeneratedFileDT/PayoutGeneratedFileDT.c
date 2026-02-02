
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
           char  filnam[25];
};
static struct sqlcxp sqlfpn =
{
    24,
    "PayoutGeneratedFileDT.pc"
};


static unsigned int sqlctx = 1298553499;


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
   unsigned char  *sqhstv[28];
   unsigned long  sqhstl[28];
            int   sqhsts[28];
            short *sqindv[28];
            int   sqinds[28];
   unsigned long  sqharm[28];
   unsigned long  *sqharc[28];
   unsigned short  sqadto[28];
   unsigned short  sqtdso[28];
} sqlstm = {12,28};

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
"select fd_batch_id , fd_seq_num , fd_txn_id , fd_merchant_ref , fd_country \
, fd_identity_id , fd_account_num , fd_account_name , fd_bank_name , fd_bank_\
code , fd_branch , fd_phone_num , fd_province , fd_city , fd_payout_amount , \
fd_request_amount , fd_payout_currency , fd_request_currency , fd_upload_txn_\
id , ud_remark , uh_service_code from payout_generated_file_dt , merchant_upl\
oad_file_header , merchant_upload_file_detail where fd_file_id = :b0 and fd_b\
atch_id = ud_batch_id and ud_batch_id = uh_batch_id and fd_seq_num = ud_seq_n\
um and ud_status = :b1 order by fd_txn_id            ";

 static char *sq0005 = 
"select fd_file_id , fd_batch_id , fd_seq_num , fd_upload_txn_id , fd_mercha\
nt_ref , fd_country , fd_identity_id , fd_account_num , fd_account_name , fd_\
bank_name , fd_bank_code , fd_branch , fd_phone_num , fd_province , fd_city ,\
 fd_payout_amount , fd_request_amount , fd_payout_currency , fd_request_curre\
ncy , fd_status , fh_file_pid , uh_merchant_id , uh_service_code from payout_\
generated_file_dt , payout_generated_file_hd , merchant_upload_file_header , \
merchant_upload_file_detail where fd_txn_id = :b0 and fd_upload_txn_id = ud_t\
xn_id and fd_file_id = fh_file_id and uh_batch_id = ud_batch_id            ";

 static char *sq0006 = 
"select fd_batch_id , fd_seq_num , fd_txn_id , fd_merchant_ref , fd_country \
, fd_identity_id , fd_account_num , fd_account_name , fd_bank_name , fd_bank_\
code , fd_branch , fd_phone_num , fd_province , fd_city , fd_payout_amount , \
fd_request_amount , fd_payout_currency , fd_request_currency , fd_upload_txn_\
id from ( SELECT * FROM payout_generated_file_dt ORDER BY dbms_random . value\
 ) where fd_bank_name = :b0 and fd_status = :b1            ";

 static char *sq0007 = 
"select fd_batch_id , fd_seq_num , fd_txn_id , fd_merchant_ref , fd_country \
, fd_identity_id , fd_account_num , fd_account_name , fd_bank_name , fd_bank_\
code , fd_branch , fd_phone_num , fd_province , fd_city , fd_payout_amount , \
fd_request_amount , fd_payout_currency , fd_request_currency , fd_upload_txn_\
id from ( SELECT * FROM payout_generated_file_dt ORDER BY dbms_random . value\
 ) where fd_status = :b0            ";

 static char *sq0008 = 
"select fd_file_id , fd_batch_id , fd_seq_num , fd_txn_id , fd_merchant_ref \
, fd_country , fd_identity_id , fd_account_num , fd_account_name , fd_bank_na\
me , fd_bank_code , fd_branch , fd_phone_num , fd_province , fd_city , fd_pay\
out_amount , fd_request_amount , fd_payout_currency , fd_request_currency , f\
h_file_pid , uh_merchant_id , uh_service_code from payout_generated_file_dt ,\
 payout_generated_file_hd , merchant_upload_file_header , merchant_upload_fil\
e_detail where fd_upload_txn_id = :b0 and fd_upload_txn_id = ud_txn_id and fd\
_file_id = fh_file_id and uh_batch_id = ud_batch_id and fd_status = :b1      \
      ";

 static char *sq0010 = 
"select fd_txn_id from payout_generated_file_dt where fd_upload_txn_id in ( \
select fd_upload_txn_id from payout_generated_file_dt where fd_txn_id = :b0 )\
 and fd_txn_id <> :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,745,0,6,262,0,0,23,23,0,1,0,2,3,0,0,1,68,0,0,1,68,0,0,1,3,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,
112,0,0,2,590,0,9,421,0,2049,2,2,0,1,0,1,68,0,0,1,3,0,0,
135,0,0,2,0,0,13,423,0,0,21,0,0,1,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
234,0,0,2,0,0,15,602,0,0,0,0,0,1,0,
249,0,0,2,0,0,15,612,0,0,0,0,0,1,0,
264,0,0,3,73,0,6,633,0,0,2,2,0,1,0,2,3,0,0,1,9,0,0,
287,0,0,4,0,0,17,723,0,0,1,1,0,1,0,1,9,0,0,
306,0,0,4,0,0,21,724,0,0,0,0,0,1,0,
321,0,0,4,0,0,17,801,0,0,1,1,0,1,0,1,9,0,0,
340,0,0,4,0,0,21,802,0,0,0,0,0,1,0,
355,0,0,5,612,0,9,917,0,2049,1,1,0,1,0,1,9,0,0,
374,0,0,5,0,0,13,919,0,0,23,0,0,1,0,2,68,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
481,0,0,5,0,0,15,1112,0,0,0,0,0,1,0,
496,0,0,5,0,0,15,1122,0,0,0,0,0,1,0,
511,0,0,6,442,0,9,1220,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
534,0,0,6,0,0,13,1222,0,0,19,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
625,0,0,6,0,0,15,1385,0,0,0,0,0,1,0,
640,0,0,7,419,0,9,1412,0,2049,1,1,0,1,0,1,3,0,0,
659,0,0,7,0,0,13,1414,0,0,19,0,0,1,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
750,0,0,7,0,0,15,1558,0,0,0,0,0,1,0,
765,0,0,8,620,0,9,1677,0,2049,2,2,0,1,0,1,9,0,0,1,3,0,0,
788,0,0,8,0,0,13,1679,0,0,22,0,0,1,0,2,9,0,0,2,68,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
891,0,0,8,0,0,15,1866,0,0,0,0,0,1,0,
906,0,0,8,0,0,15,1876,0,0,0,0,0,1,0,
921,0,0,4,0,0,17,1948,0,0,1,1,0,1,0,1,9,0,0,
940,0,0,4,0,0,21,1949,0,0,0,0,0,1,0,
955,0,0,0,0,0,56,2074,0,0,1,1,0,1,0,3,102,0,0,
974,0,0,9,207,0,6,2076,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,3,0,0,2,
102,0,0,
1013,0,0,0,0,0,13,2123,0,0,28,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,3,0,0,2,4,0,0,2,4,0,0,
1140,0,0,0,0,0,15,2342,0,0,1,1,0,1,0,1,102,0,0,
1159,0,0,0,0,0,78,2343,0,0,1,1,0,1,0,3,102,0,0,
1178,0,0,0,0,0,15,2353,0,0,1,1,0,1,0,1,102,0,0,
1197,0,0,0,0,0,78,2354,0,0,1,1,0,1,0,3,102,0,0,
1216,0,0,10,185,0,9,2389,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
1239,0,0,10,0,0,13,2391,0,0,1,0,0,1,0,2,9,0,0,
1258,0,0,10,0,0,15,2413,0,0,0,0,0,1,0,
1273,0,0,10,0,0,15,2423,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/10/19              LokMan Chow
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "PayoutGeneratedFileDT.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "internal.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void PayoutGeneratedFileDT(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRec)
{
	char            *csTmp;
        int             iTmp;
        double		dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_file_id;
                unsigned long   hv_batch_id;
                int             hv_seq_num;
                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

                /* varchar         hv_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_country;

		/* varchar		hv_identity_id[PD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_identity_id;

		/* varchar         hv_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } hv_account_num;

                /* varchar         hv_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_account_name;

                /* varchar         hv_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } hv_bank_name;

                /* varchar         hv_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_bank_code;

                /* varchar         hv_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } hv_branch;

                /* varchar         hv_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } hv_phone_num;

                /* varchar         hv_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_province;

                /* varchar         hv_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_city;

		/* varchar		hv_payout_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_payout_currency;

		double		hv_payout_amount;
		/* varchar		hv_request_currency[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_request_currency;

		double		hv_request_amount;
		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

		int		hv_status;
                
                short           ind_file_id= -1;
                short           ind_batch_id= -1;
                short           ind_seq_num= -1;
                short           ind_merchant_ref= -1;
                short           ind_country= -1;
                short           ind_identity_id= -1;
		short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code= -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_currency= -1;
                short           ind_payout_amount= -1;
                short           ind_request_currency= -1;
                short           ind_request_amount= -1;
                short           ind_add_user= -1;
                short           ind_txn_id= -1;
                short           ind_upload_txn_id= -1;
		short		ind_status= -1;                

                short           hv_return_value;
                /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/*txn_id*/
        if(GetField_CString(hRec,"txn_id",&csTmp)){
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id= 0;
DEBUGLOG(("Add:txn_id= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/*upload_txn_id*/
        if(GetField_CString(hRec,"upload_txn_id",&csTmp)){
                hv_upload_txn_id.len = strlen(csTmp);
                memcpy(hv_upload_txn_id.arr, csTmp, hv_upload_txn_id.len);
                ind_upload_txn_id= 0;
DEBUGLOG(("Add:upload_txn_id= [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));
        }

/*file_id*/
        if(GetField_CString(hRec,"file_id",&csTmp)){
                hv_file_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_file_id= 0;
DEBUGLOG(("Add:file_id= [%ld]\n",hv_file_id));
        }

/*batch_id*/
        if(GetField_CString(hRec,"batch_id",&csTmp)){
                hv_batch_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
                ind_batch_id= 0;
DEBUGLOG(("Add:batch_id= [%ld]\n",hv_batch_id));
        }

/*merchant_ref*/
        if(GetField_CString(hRec,"merchant_ref",&csTmp)){
                hv_merchant_ref.len = strlen(csTmp);
                memcpy(hv_merchant_ref.arr, csTmp, hv_merchant_ref.len);
                ind_merchant_ref= 0;
DEBUGLOG(("Add:merchant_ref= [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }

/*country*/
        if(GetField_CString(hRec,"txn_country",&csTmp)){
                hv_country.len = strlen(csTmp);
                memcpy(hv_country.arr, csTmp, hv_country.len);
                ind_country= 0;
DEBUGLOG(("Add:country= [%.*s]\n",hv_country.len,hv_country.arr));
        }

/*seq_num*/
        if(GetField_Int(hRec,"seq_num",&iTmp)){
                hv_seq_num = iTmp;
                ind_seq_num= 0;
DEBUGLOG(("Add:seq_num= [%d]\n",hv_seq_num));
        }

/*identity_id*/
        if(GetField_CString(hRec,"identity_id",&csTmp)){
                hv_identity_id.len = strlen(csTmp);
                memcpy(hv_identity_id.arr, csTmp, hv_identity_id.len);
                ind_identity_id= 0;
DEBUGLOG(("Add:identity_id= [%.*s]\n",hv_identity_id.len,hv_identity_id.arr));
        }

/*account_num*/
        if(GetField_CString(hRec,"account_num",&csTmp)){
                hv_account_num.len = strlen(csTmp);
                memcpy(hv_account_num.arr, csTmp, hv_account_num.len);
                ind_account_num = 0;
DEBUGLOG(("Add:account_num = [%.*s]\n",hv_account_num.len,hv_account_num.arr));
        }

/*account name*/
        if(GetField_CString(hRec,"account_name",&csTmp)){
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr, csTmp, hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
        }

/*bank_name*/
        if(GetField_CString(hRec,"bank_name",&csTmp)){
                hv_bank_name.len = strlen(csTmp);
                memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("Add:bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
        }

/*bank_code*/
        if(GetField_CString(hRec,"bank_code",&csTmp)){
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
                ind_bank_code= 0;
DEBUGLOG(("Add:bank_code= [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
        }

/*branch*/
        if(GetField_CString(hRec,"branch",&csTmp)){
                hv_branch.len = strlen(csTmp);
                memcpy(hv_branch.arr, csTmp, hv_branch.len);
                ind_branch = 0;
DEBUGLOG(("Add:branch = [%.*s]\n",hv_branch.len,hv_branch.arr));
        }

/*phone_num*/
        if(GetField_CString(hRec,"phone_num",&csTmp)){
                hv_phone_num.len = strlen(csTmp);
                memcpy(hv_phone_num.arr, csTmp, hv_phone_num.len);
                ind_phone_num = 0;
DEBUGLOG(("Add:phone_num = [%.*s]\n",hv_phone_num.len,hv_phone_num.arr));
        }

/*province*/
        if(GetField_CString(hRec,"province",&csTmp)){
                hv_province.len = strlen(csTmp);
                memcpy(hv_province.arr, csTmp, hv_province.len);
                ind_province = 0;
DEBUGLOG(("Add:province = [%.*s]\n",hv_province.len,hv_province.arr));
        }

/*city*/
        if(GetField_CString(hRec,"city",&csTmp)){
                hv_city.len = strlen(csTmp);
                memcpy(hv_city.arr, csTmp, hv_city.len);
                ind_city = 0;
DEBUGLOG(("Add:city = [%.*s]\n",hv_city.len,hv_city.arr));
        }

/*payout_currency*/
        if(GetField_CString(hRec,"payout_ccy",&csTmp)){
                hv_payout_currency.len = strlen(csTmp);
                memcpy(hv_payout_currency.arr, csTmp, hv_payout_currency.len);
                ind_payout_currency= 0;
DEBUGLOG(("Add:payout_currency= [%.*s]\n",hv_payout_currency.len,hv_payout_currency.arr));
        }

/*payout_amount*/
        if(GetField_Double(hRec,"payout_amount",&dTmp)){
                hv_payout_amount = dTmp;
                ind_payout_amount = 0;
DEBUGLOG(("Add:payout_amount= [%lf]\n",hv_payout_amount));
        }

/*request_currency*/
        if(GetField_CString(hRec,"request_ccy",&csTmp)){
                hv_request_currency.len = strlen(csTmp);
                memcpy(hv_request_currency.arr, csTmp, hv_request_currency.len);
                ind_request_currency= 0;
DEBUGLOG(("Add:request_currency= [%.*s]\n",hv_request_currency.len,hv_request_currency.arr));
        }

/*request_amount*/
        if(GetField_Double(hRec,"request_amount",&dTmp)){
                hv_request_amount = dTmp;
                ind_request_amount = 0;
DEBUGLOG(("Add:request_amount= [%lf]\n",hv_request_amount));
        }

/*status*/
        if(GetField_Int(hRec,"status",&iTmp)){
                hv_status= iTmp;
                ind_status= 0;
DEBUGLOG(("Add:status = [%d]\n",hv_status));
        }

/*user*/
        if(GetField_CString(hRec,"add_user",&csTmp)){
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr, csTmp, hv_add_user.len);
                ind_add_user= 0;
DEBUGLOG(("Add:add_user= [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_payout_gen_dt_insert(
                                        :hv_file_id:ind_file_id,
                                        :hv_batch_id:ind_batch_id,
                                        :hv_seq_num:ind_seq_num,
                                        :hv_merchant_ref:ind_merchant_ref,
                                        :hv_country:ind_country,
                                        :hv_identity_id:ind_identity_id,
                                        :hv_account_num:ind_account_num,
                                        :hv_account_name:ind_account_name,
                                        :hv_bank_name:ind_bank_name,
                                        :hv_bank_code:ind_bank_code,
                                        :hv_branch:ind_branch,
                                        :hv_phone_num:ind_phone_num,
                                        :hv_province:ind_province,
                                        :hv_city:ind_city,
                                        :hv_payout_amount:ind_payout_amount,
                                        :hv_request_amount:ind_request_amount,
                                        :hv_payout_currency:ind_payout_currency,
                                        :hv_request_currency:ind_request_currency,
					:hv_txn_id:ind_txn_id,
					:hv_upload_txn_id:ind_upload_txn_id,
					:hv_status:ind_status,
                                        :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 23;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_payout_gen_dt_insert ( :hv_fil\
e_id:ind_file_id , :hv_batch_id:ind_batch_id , :hv_seq_num:ind_seq_num , :hv_\
merchant_ref:ind_merchant_ref , :hv_country:ind_country , :hv_identity_id:ind\
_identity_id , :hv_account_num:ind_account_num , :hv_account_name:ind_account\
_name , :hv_bank_name:ind_bank_name , :hv_bank_code:ind_bank_code , :hv_branc\
h:ind_branch , :hv_phone_num:ind_phone_num , :hv_province:ind_province , :hv_\
city:ind_city , :hv_payout_amount:ind_payout_amount , :hv_request_amount:ind_\
request_amount , :hv_payout_currency:ind_payout_currency , :hv_request_curren\
cy:ind_request_currency , :hv_txn_id:ind_txn_id , :hv_upload_txn_id:ind_uploa\
d_txn_id , :hv_status:ind_status , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_file_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_batch_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_seq_num;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_seq_num;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_country;
 sqlstm.sqhstl[5] = (unsigned long )4;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_country;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_identity_id;
 sqlstm.sqhstl[6] = (unsigned long )52;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_identity_id;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_account_num;
 sqlstm.sqhstl[7] = (unsigned long )28;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_account_num;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[8] = (unsigned long )103;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_account_name;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[9] = (unsigned long )153;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_bank_name;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[10] = (unsigned long )13;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_bank_code;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_branch;
 sqlstm.sqhstl[11] = (unsigned long )153;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_branch;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_phone_num;
 sqlstm.sqhstl[12] = (unsigned long )28;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_phone_num;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[13] = (unsigned long )103;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_province;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[14] = (unsigned long )103;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_city;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_payout_amount;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_request_amount;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_request_amount;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_payout_currency;
 sqlstm.sqhstl[17] = (unsigned long )5;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_payout_currency;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_request_currency;
 sqlstm.sqhstl[18] = (unsigned long )5;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_request_currency;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[19] = (unsigned long )18;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_txn_id;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_upload_txn_id;
 sqlstm.sqhstl[20] = (unsigned long )18;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_upload_txn_id;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_status;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[22] = (unsigned long )22;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_add_user;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
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
ERRLOG("PayoutGeneratedFileDT_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("PayoutGeneratedFileDT_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Add: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetDetail(const hash_t* hRec,recordset_t* myRec)
{               
        hash_t *myHash;         
        char*   csTmp;          
	char	csBatchId[PD_TXN_SEQ_LEN+1];
	int	iTmp;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getdetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                unsigned long   hv_file_id;
		int		hv_status;
                
		unsigned long	v_batch_id;
		int		v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_upload_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_upload_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                double          v_payout_amount;
                double          v_request_amount;
		/* varchar         v_remark[PD_REMARK_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar         v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_txn_id = -1;
		short           ind_upload_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
		short           ind_remark = -1;
		short           ind_service_code= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hRec,"file_id",&csTmp)){
                hv_file_id = (unsigned long)ctol((const unsigned char*)csTmp,strlen(csTmp));
DEBUGLOG(("GetDetail file_id = [%ld]\n",hv_file_id));
        }

	if(GetField_Int(hRec,"status",&iTmp)){
		hv_status = iTmp;
DEBUGLOG(("GetDetail status = [%d]\n",hv_status));
	}
/* EXEC SQL DECLARE c_cursor_getdetail CURSOR FOR
                select
                        fd_batch_id,
                        fd_seq_num,
			fd_txn_id,
			fd_merchant_ref,
			fd_country,
			fd_identity_id,
			fd_account_num,
			fd_account_name,
			fd_bank_name,
			fd_bank_code,
			fd_branch,
			fd_phone_num,
			fd_province,
			fd_city,
			fd_payout_amount,
			fd_request_amount,
			fd_payout_currency,
			fd_request_currency,
			fd_upload_txn_id,
			ud_remark,
			uh_service_code
                from    payout_generated_file_dt,
			merchant_upload_file_header,
			merchant_upload_file_detail
                where   fd_file_id =:hv_file_id
		and	fd_batch_id = ud_batch_id
		and	ud_batch_id = uh_batch_id
		and	fd_seq_num = ud_seq_num
		and	ud_status = :hv_status
		order by fd_txn_id; */ 


	/* EXEC SQL OPEN  c_cursor_getdetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 23;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0002;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )112;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_file_id;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getdetail_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getdetail
                INTO
                        :v_batch_id:ind_batch_id,
                        :v_seq_num:ind_seq_num,
                        :v_txn_id:ind_txn_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_identity_id:ind_identity_id,
                        :v_account_num:ind_account_num,
                        :v_account_name:ind_account_name,
                        :v_bank_name:ind_bank_name,
                        :v_bank_code:ind_bank_code,
                        :v_branch:ind_branch,
                        :v_phone_num:ind_phone_num,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_payout_amount:ind_payout_amount,
                        :v_request_amount:ind_request_amount,
                        :v_payout_ccy:ind_payout_ccy,
                        :v_request_ccy:ind_request_ccy,
			:v_upload_txn_id:ind_upload_txn_id,
			:v_remark:ind_remark,
			:v_service_code:ind_service_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )135;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[2] = (unsigned long )19;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[3] = (unsigned long )53;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_country;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[5] = (unsigned long )28;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_identity_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[6] = (unsigned long )28;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_account_num;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[7] = (unsigned long )103;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_account_name;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[8] = (unsigned long )153;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[9] = (unsigned long )13;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_code;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[10] = (unsigned long )153;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_branch;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
                sqlstm.sqhstl[11] = (unsigned long )28;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_phone_num;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[12] = (unsigned long )103;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_province;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[13] = (unsigned long )103;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_city;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_request_amount;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[16] = (unsigned long )6;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
                sqlstm.sqhstl[17] = (unsigned long )6;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_upload_txn_id;
                sqlstm.sqhstl[18] = (unsigned long )19;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_upload_txn_id;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_remark;
                sqlstm.sqhstl[19] = (unsigned long )258;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_remark;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[20] = (unsigned long )6;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_service_code;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getdetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*batch_id*/
                if(ind_batch_id>=0){
                        sprintf(csBatchId,"%ld",v_batch_id);
                        PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetDetail batch_id= [%s]\n",csBatchId));
                }

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetail seq_num= [%d]\n",v_seq_num));
		}

/*txn_id*/
                if(ind_txn_id>=0){
                        v_txn_id.arr[v_txn_id.len]='\0';
                        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetail txn_id= [%s]\n",v_txn_id.arr));
                }

/*upload_txn_id*/
                if(ind_upload_txn_id>=0){
                        v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
                        PutField_CString(myHash,"upload_txn_id",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetDetail upload_txn_id= [%s]\n",v_upload_txn_id.arr));
                }

/*merchant_ref*/
                if(ind_merchant_ref>=0){
                        v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetail merchant_ref= [%s]\n",v_merchant_ref.arr));
                }

/*country*/
                if(ind_country>=0){
                        v_country.arr[v_country.len]='\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetail country= [%s]\n",v_country.arr));
                }

/*identity_id*/
                if(ind_identity_id>=0){
                        v_identity_id.arr[v_identity_id.len]='\0';
                        PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetail identity_id= [%s]\n",v_identity_id.arr));
                }

/*account_num*/
                if(ind_account_num>=0){
                        v_account_num.arr[v_account_num.len]='\0';
                        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetail account_num= [%s]\n",v_account_num.arr));
                }

/*account_name*/
                if(ind_account_name>=0){
                        v_account_name.arr[v_account_name.len]='\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetail account_name= [%s]\n",v_account_name.arr));
                }

/*bank_name*/
                if(ind_bank_name>=0){
                        v_bank_name.arr[v_bank_name.len]='\0';
                        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetail bank_name= [%s]\n",v_bank_name.arr));
        }

/*bank_code*/
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetail bank_code= [%s]\n",v_bank_code.arr));
                }

/*branch*/
                if(ind_branch>=0){
                        v_branch.arr[v_branch.len]='\0';
                        PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetail branch= [%s]\n",v_branch.arr));
                }

/*phone_num*/
                if(ind_phone_num>=0){
                        v_phone_num.arr[v_phone_num.len]='\0';
                        PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetail phone_num= [%s]\n",v_phone_num.arr));
                }

/*province*/
                if(ind_province>=0){
                        v_province.arr[v_province.len]='\0';
                        PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetail province= [%s]\n",v_province.arr));
                }

/*city*/
                if(ind_city>=0){
                        v_city.arr[v_city.len]='\0';
                        PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetail city= [%s]\n",v_city.arr));
                }

/*payout_currency*/
                if(ind_payout_ccy>=0){
                        v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetail payout_ccy= [%s]\n",v_payout_ccy.arr));
                }

/*request_currency*/
                if(ind_request_ccy>=0){
                        v_request_ccy.arr[v_request_ccy.len]='\0';
                        PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetail request_ccy= [%s]\n",v_request_ccy.arr));
                }

/*payout_amount*/
                if(ind_payout_amount>=0){
                        PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetail payout_amount = [%lf]\n",v_payout_amount));
                }

/*request_amount*/
                if(ind_request_amount>=0){
                        PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetail request_amount = [%lf]\n",v_request_amount));
                }

/*remark*/
                if(ind_remark>=0){
                        v_remark.arr[v_remark.len]='\0';
                        PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetDetail remark = [%s]\n",v_remark.arr));
                }

/*service_code*/
                if(ind_service_code>=0){
                        v_service_code.arr[v_service_code.len]='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetDetail service_code = [%s]\n",v_service_code.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )234;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetail_error;
}



DEBUGLOG(("GetDetail Normal Exit\n"));
        return  PD_OK;

getdetail_error:
DEBUGLOG(("getdetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
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


        return PD_ERR;

}


int Delete(const unsigned char* file_id)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO delete_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;


                short   hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_file_id.len = strlen((const char*)file_id);
        memcpy(hv_file_id.arr,file_id,hv_file_id.len);
DEBUGLOG(("Delete: file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_payout_gen_dt_delete(
                                :hv_file_id);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_payout_gen_dt_delete ( \
:hv_file_id ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )264;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
        sqlstm.sqhstl[1] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto delete_error;
}




DEBUGLOG(("Delete:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("Delete:Normal Exit\n"));
                return PD_OK;
        }
        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("PayoutGeneratedFileDT_Delete: SP_OTHER_ERR\n");
DEBUGLOG(("Delete: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("PayoutGeneratedFileDT_Delete: SP_ERR\n");
DEBUGLOG(("Delete: SP_ERR\n"));
                return PD_ERR;
        }
delete_error:
DEBUGLOG(("delete_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Delete: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int UpdateByFileId(const hash_t *hRec)
{
        char*   csBuf;
        char*   csFileId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByFileId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_dt set fd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"file_id",&csFileId)){
DEBUGLOG(("UpdateByFileId:file_id = [%s]\n",csFileId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByFileId file_id not found\n"));
                return INT_ERR;
        }

        if(GetField_Int(hRec,"status",&iTmp)){
DEBUGLOG(("UpdateByFileId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",fd_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("UpdateByFileId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE fd_file_id= ");
        strcat((char*)hv_dynstmt.arr, csFileId);
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )287;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto update_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )306;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByFileId Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_UpdateByFileId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int UpdateByGenId(const hash_t *hRec)
{
        char*   csBuf;
        char*   csGenId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatebygen_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByGenId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_dt set fd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"txn_id",&csGenId)){
DEBUGLOG(("UpdateByGenId:txn_id = [%s]\n",csGenId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByGenId txn_id not found\n"));
                return INT_ERR;
        }

        if(GetField_Int(hRec,"status",&iTmp)){
DEBUGLOG(("UpdateByGenId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",fd_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"aux_txn_id",&csBuf)){
DEBUGLOG(("UpdateByGenId: aux_txn_id = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_aux_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("UpdateByGenId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE fd_txn_id= '");
        strcat((char*)hv_dynstmt.arr, csGenId);
	strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )321;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )340;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatebygen_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByGenId Normal Exit\n"));
        return PD_OK;

updatebygen_error:
DEBUGLOG(("updatebygen_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_UpdateByGenId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetDetailByGenId(const char* csGenId,recordset_t* myRec)
{               
        hash_t *myHash;         
	char	csBatchId[PD_TXN_SEQ_LEN+1];
	char	csFileId[PD_TXN_SEQ_LEN+1];
        //char*   csTmp;          
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getdetailbygenid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_id;

                
		unsigned long	v_file_id;
		unsigned long	v_batch_id;
		int		v_seq_num;
                /* varchar         v_upload_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_upload_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                double          v_payout_amount;
                double          v_request_amount;
		int		v_status;
                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_upload_txn_id = -1;
		short           ind_file_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
                short           ind_status= -1;
                short           ind_psp_id= -1;
                short           ind_merchant_id= -1;
                short           ind_service_code= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csGenId);
	memcpy(hv_txn_id.arr,csGenId,hv_txn_id.len);
DEBUGLOG(("GetDetailByGenId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

/* EXEC SQL DECLARE c_cursor_getdetailbygenid CURSOR FOR
                select	fd_file_id,
                        fd_batch_id,
                        fd_seq_num,
			fd_upload_txn_id,
			fd_merchant_ref,
			fd_country,
			fd_identity_id,
			fd_account_num,
			fd_account_name,
			fd_bank_name,
			fd_bank_code,
			fd_branch,
			fd_phone_num,
			fd_province,
			fd_city,
			fd_payout_amount,
			fd_request_amount,
			fd_payout_currency,
			fd_request_currency,
			fd_status,
			fh_file_pid,
			uh_merchant_id,
			uh_service_code
                from    payout_generated_file_dt,
			payout_generated_file_hd,
			merchant_upload_file_header,
			merchant_upload_file_detail
                where   fd_txn_id=:hv_txn_id
		and	fd_upload_txn_id = ud_txn_id
		and	fd_file_id = fh_file_id
		and	uh_batch_id = ud_batch_id; */ 


	/* EXEC SQL OPEN  c_cursor_getdetailbygenid; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 23;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )355;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
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
 if (sqlca.sqlcode < 0) goto getdetailbygenid_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getdetailbygenid
                INTO	:v_file_id:ind_file_id,
                        :v_batch_id:ind_batch_id,
                        :v_seq_num:ind_seq_num,
                        :v_upload_txn_id:ind_upload_txn_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_identity_id:ind_identity_id,
                        :v_account_num:ind_account_num,
                        :v_account_name:ind_account_name,
                        :v_bank_name:ind_bank_name,
                        :v_bank_code:ind_bank_code,
                        :v_branch:ind_branch,
                        :v_phone_num:ind_phone_num,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_payout_amount:ind_payout_amount,
                        :v_request_amount:ind_request_amount,
                        :v_payout_ccy:ind_payout_ccy,
                        :v_request_ccy:ind_request_ccy,
			:v_status:ind_status,
			:v_psp_id:ind_psp_id,
			:v_merchant_id:ind_merchant_id,
			:v_service_code:ind_service_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )374;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_upload_txn_id;
                sqlstm.sqhstl[3] = (unsigned long )19;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_upload_txn_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_country;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[6] = (unsigned long )28;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_identity_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[7] = (unsigned long )28;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_account_num;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[8] = (unsigned long )103;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_account_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[9] = (unsigned long )153;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[10] = (unsigned long )13;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_bank_code;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[11] = (unsigned long )153;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_branch;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                sqlstm.sqhstl[12] = (unsigned long )28;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[13] = (unsigned long )103;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_province;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[14] = (unsigned long )103;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_city;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[17] = (unsigned long )6;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                sqlstm.sqhstl[18] = (unsigned long )6;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[19] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_status;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[20] = (unsigned long )13;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_psp_id;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[21] = (unsigned long )18;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[22] = (unsigned long )6;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_service_code;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getdetailbygenid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*file_id*/
                if(ind_file_id>=0){
                        sprintf(csFileId,"%ld",v_file_id);
                        PutField_CString(myHash,"file_id",csFileId);
DEBUGLOG(("GetDetailByGenId file_id= [%s]\n",csFileId));
                }

/*batch_id*/
                if(ind_batch_id>=0){
                        sprintf(csBatchId,"%ld",v_batch_id);
                        PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetDetailByGenId batch_id= [%s]\n",csBatchId));
                }

/*seq_num*/
		if(ind_seq_num>=0){
			PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByGenId seq_num= [%d]\n",v_seq_num));
		}

/*upload_txn_id*/
                if(ind_upload_txn_id>=0){
                        v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
                        PutField_CString(myHash,"upload_txn_id",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetDetailByGenId upload_txn_id= [%s]\n",v_upload_txn_id.arr));
                }

/*merchant_ref*/
                if(ind_merchant_ref>=0){
                        v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByGenId merchant_ref= [%s]\n",v_merchant_ref.arr));
                }

/*country*/
                if(ind_country>=0){
                        v_country.arr[v_country.len]='\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByGenId country= [%s]\n",v_country.arr));
                }

/*identity_id*/
                if(ind_identity_id>=0){
                        v_identity_id.arr[v_identity_id.len]='\0';
                        PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByGenId identity_id= [%s]\n",v_identity_id.arr));
                }

/*account_num*/
                if(ind_account_num>=0){
                        v_account_num.arr[v_account_num.len]='\0';
                        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByGenId account_num= [%s]\n",v_account_num.arr));
                }

/*account_name*/
                if(ind_account_name>=0){
                        v_account_name.arr[v_account_name.len]='\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByGenId account_name= [%s]\n",v_account_name.arr));
                }

/*bank_name*/
                if(ind_bank_name>=0){
                        v_bank_name.arr[v_bank_name.len]='\0';
                        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByGenId bank_name= [%s]\n",v_bank_name.arr));
        }

/*bank_code*/
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetailByGenId bank_code= [%s]\n",v_bank_code.arr));
                }

/*branch*/
                if(ind_branch>=0){
                        v_branch.arr[v_branch.len]='\0';
                        PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByGenId branch= [%s]\n",v_branch.arr));
                }

/*phone_num*/
                if(ind_phone_num>=0){
                        v_phone_num.arr[v_phone_num.len]='\0';
                        PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByGenId phone_num= [%s]\n",v_phone_num.arr));
                }

/*province*/
                if(ind_province>=0){
                        v_province.arr[v_province.len]='\0';
                        PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByGenId province= [%s]\n",v_province.arr));
                }

/*city*/
                if(ind_city>=0){
                        v_city.arr[v_city.len]='\0';
                        PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByGenId city= [%s]\n",v_city.arr));
                }

/*payout_currency*/
                if(ind_payout_ccy>=0){
                        v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByGenId payout_ccy= [%s]\n",v_payout_ccy.arr));
                }

/*request_currency*/
                if(ind_request_ccy>=0){
                        v_request_ccy.arr[v_request_ccy.len]='\0';
                        PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByGenId request_ccy= [%s]\n",v_request_ccy.arr));
                }

/*payout_amount*/
                if(ind_payout_amount>=0){
                        PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByGenId payout_amount = [%lf]\n",v_payout_amount));
                }

/*request_amount*/
                if(ind_request_amount>=0){
                        PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByGenId request_amount = [%lf]\n",v_request_amount));
                }

/*status*/
                if(ind_status>=0){
                        PutField_Int(myHash,"status",v_status);
DEBUGLOG(("GetDetailByGenId status = [%d]\n",v_status));
                }

/*psp_id*/
                if(ind_psp_id>=0){
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByGenId psp_id = [%s]\n",v_psp_id.arr));
                }

/*merchant_id*/
                if(ind_merchant_id>=0){
                        v_merchant_id.arr[v_merchant_id.len]='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetDetailByGenId merchant_id = [%s]\n",v_merchant_id.arr));
                }

/*service_code*/
                if(ind_service_code>=0){
                        v_service_code.arr[v_service_code.len]='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetDetailByGenId service_code = [%s]\n",v_service_code.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getdetailbygenid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )481;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getdetailbygenid_error;
}



DEBUGLOG(("GetDetailByGenId Normal Exit\n"));
        return  PD_OK;

getdetailbygenid_error:
DEBUGLOG(("getdetailbygenid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getdetailbygenid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )496;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int GetReGenDetailByRandom(const hash_t* hRec,recordset_t* myRec)
{               
        hash_t *myHash;         
        char*   csTmp;          
	int	iTmp;
	int	iBank=PD_FALSE;
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getregendetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		int		hv_status;
                /* varchar         hv_bank_name[PD_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

                
		/* varchar		v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

		int		v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_upload_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_upload_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                double          v_payout_amount;
                double          v_request_amount;

		short           ind_batch_id = -1;
		short           ind_seq_num = -1;
		short           ind_txn_id = -1;
		short           ind_upload_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        if(GetField_CString(hRec,"bank_name",&csTmp)){
		memcpy(hv_bank_name.arr, csTmp, hv_bank_name.len);
		iBank=PD_TRUE;
DEBUGLOG(("GetReGenDetailByRandom bank_name = [%*.s]\n",hv_bank_name.len,hv_bank_name.arr));
        }

	if(GetField_Int(hRec,"status",&iTmp)){
		hv_status = iTmp;
DEBUGLOG(("GetReGenDetailByRandom status = [%d]\n",hv_status));
	}

	if(iBank==PD_TRUE){
		/* EXEC SQL DECLARE c_cursor_getregenb CURSOR FOR
                  select fd_batch_id,
                        fd_seq_num,
			fd_txn_id,
			fd_merchant_ref,
			fd_country,
			fd_identity_id,
			fd_account_num,
			fd_account_name,
			fd_bank_name,
			fd_bank_code,
			fd_branch,
			fd_phone_num,
			fd_province,
			fd_city,
			fd_payout_amount,
			fd_request_amount,
			fd_payout_currency,
			fd_request_currency,
			fd_upload_txn_id
                  from    (SELECT * FROM payout_generated_file_dt ORDER BY dbms_random.value)
                  where   fd_bank_name =:hv_bank_name
		  and	fd_status = :hv_status; */ 


		/* EXEC SQL OPEN  c_cursor_getregenb; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 23;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0006;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )511;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_bank_name;
  sqlstm.sqhstl[0] = (unsigned long )152;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
  if (sqlca.sqlcode < 0) goto getregendetail_error;
}


        	do{
                	/* EXEC SQL FETCH c_cursor_getregenb
                	INTO
                	        :v_batch_id:ind_batch_id,
                        	:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_upload_txn_id:ind_upload_txn_id; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 23;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )534;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                 sqlstm.sqhstl[0] = (unsigned long )19;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                 sqlstm.sqinds[0] = (         int  )0;
                 sqlstm.sqharm[0] = (unsigned long )0;
                 sqlstm.sqadto[0] = (unsigned short )0;
                 sqlstm.sqtdso[0] = (unsigned short )0;
                 sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                 sqlstm.sqhsts[1] = (         int  )0;
                 sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                 sqlstm.sqinds[1] = (         int  )0;
                 sqlstm.sqharm[1] = (unsigned long )0;
                 sqlstm.sqadto[1] = (unsigned short )0;
                 sqlstm.sqtdso[1] = (unsigned short )0;
                 sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                 sqlstm.sqhstl[2] = (unsigned long )19;
                 sqlstm.sqhsts[2] = (         int  )0;
                 sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                 sqlstm.sqinds[2] = (         int  )0;
                 sqlstm.sqharm[2] = (unsigned long )0;
                 sqlstm.sqadto[2] = (unsigned short )0;
                 sqlstm.sqtdso[2] = (unsigned short )0;
                 sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
                 sqlstm.sqhstl[3] = (unsigned long )53;
                 sqlstm.sqhsts[3] = (         int  )0;
                 sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
                 sqlstm.sqinds[3] = (         int  )0;
                 sqlstm.sqharm[3] = (unsigned long )0;
                 sqlstm.sqadto[3] = (unsigned short )0;
                 sqlstm.sqtdso[3] = (unsigned short )0;
                 sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
                 sqlstm.sqhstl[4] = (unsigned long )5;
                 sqlstm.sqhsts[4] = (         int  )0;
                 sqlstm.sqindv[4] = (         short *)&ind_country;
                 sqlstm.sqinds[4] = (         int  )0;
                 sqlstm.sqharm[4] = (unsigned long )0;
                 sqlstm.sqadto[4] = (unsigned short )0;
                 sqlstm.sqtdso[4] = (unsigned short )0;
                 sqlstm.sqhstv[5] = (unsigned char  *)&v_identity_id;
                 sqlstm.sqhstl[5] = (unsigned long )28;
                 sqlstm.sqhsts[5] = (         int  )0;
                 sqlstm.sqindv[5] = (         short *)&ind_identity_id;
                 sqlstm.sqinds[5] = (         int  )0;
                 sqlstm.sqharm[5] = (unsigned long )0;
                 sqlstm.sqadto[5] = (unsigned short )0;
                 sqlstm.sqtdso[5] = (unsigned short )0;
                 sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                 sqlstm.sqhstl[6] = (unsigned long )28;
                 sqlstm.sqhsts[6] = (         int  )0;
                 sqlstm.sqindv[6] = (         short *)&ind_account_num;
                 sqlstm.sqinds[6] = (         int  )0;
                 sqlstm.sqharm[6] = (unsigned long )0;
                 sqlstm.sqadto[6] = (unsigned short )0;
                 sqlstm.sqtdso[6] = (unsigned short )0;
                 sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
                 sqlstm.sqhstl[7] = (unsigned long )103;
                 sqlstm.sqhsts[7] = (         int  )0;
                 sqlstm.sqindv[7] = (         short *)&ind_account_name;
                 sqlstm.sqinds[7] = (         int  )0;
                 sqlstm.sqharm[7] = (unsigned long )0;
                 sqlstm.sqadto[7] = (unsigned short )0;
                 sqlstm.sqtdso[7] = (unsigned short )0;
                 sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                 sqlstm.sqhstl[8] = (unsigned long )153;
                 sqlstm.sqhsts[8] = (         int  )0;
                 sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                 sqlstm.sqinds[8] = (         int  )0;
                 sqlstm.sqharm[8] = (unsigned long )0;
                 sqlstm.sqadto[8] = (unsigned short )0;
                 sqlstm.sqtdso[8] = (unsigned short )0;
                 sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_code;
                 sqlstm.sqhstl[9] = (unsigned long )13;
                 sqlstm.sqhsts[9] = (         int  )0;
                 sqlstm.sqindv[9] = (         short *)&ind_bank_code;
                 sqlstm.sqinds[9] = (         int  )0;
                 sqlstm.sqharm[9] = (unsigned long )0;
                 sqlstm.sqadto[9] = (unsigned short )0;
                 sqlstm.sqtdso[9] = (unsigned short )0;
                 sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
                 sqlstm.sqhstl[10] = (unsigned long )153;
                 sqlstm.sqhsts[10] = (         int  )0;
                 sqlstm.sqindv[10] = (         short *)&ind_branch;
                 sqlstm.sqinds[10] = (         int  )0;
                 sqlstm.sqharm[10] = (unsigned long )0;
                 sqlstm.sqadto[10] = (unsigned short )0;
                 sqlstm.sqtdso[10] = (unsigned short )0;
                 sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
                 sqlstm.sqhstl[11] = (unsigned long )28;
                 sqlstm.sqhsts[11] = (         int  )0;
                 sqlstm.sqindv[11] = (         short *)&ind_phone_num;
                 sqlstm.sqinds[11] = (         int  )0;
                 sqlstm.sqharm[11] = (unsigned long )0;
                 sqlstm.sqadto[11] = (unsigned short )0;
                 sqlstm.sqtdso[11] = (unsigned short )0;
                 sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
                 sqlstm.sqhstl[12] = (unsigned long )103;
                 sqlstm.sqhsts[12] = (         int  )0;
                 sqlstm.sqindv[12] = (         short *)&ind_province;
                 sqlstm.sqinds[12] = (         int  )0;
                 sqlstm.sqharm[12] = (unsigned long )0;
                 sqlstm.sqadto[12] = (unsigned short )0;
                 sqlstm.sqtdso[12] = (unsigned short )0;
                 sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
                 sqlstm.sqhstl[13] = (unsigned long )103;
                 sqlstm.sqhsts[13] = (         int  )0;
                 sqlstm.sqindv[13] = (         short *)&ind_city;
                 sqlstm.sqinds[13] = (         int  )0;
                 sqlstm.sqharm[13] = (unsigned long )0;
                 sqlstm.sqadto[13] = (unsigned short )0;
                 sqlstm.sqtdso[13] = (unsigned short )0;
                 sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
                 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                 sqlstm.sqhsts[14] = (         int  )0;
                 sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
                 sqlstm.sqinds[14] = (         int  )0;
                 sqlstm.sqharm[14] = (unsigned long )0;
                 sqlstm.sqadto[14] = (unsigned short )0;
                 sqlstm.sqtdso[14] = (unsigned short )0;
                 sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
                 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                 sqlstm.sqhsts[15] = (         int  )0;
                 sqlstm.sqindv[15] = (         short *)&ind_request_amount;
                 sqlstm.sqinds[15] = (         int  )0;
                 sqlstm.sqharm[15] = (unsigned long )0;
                 sqlstm.sqadto[15] = (unsigned short )0;
                 sqlstm.sqtdso[15] = (unsigned short )0;
                 sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
                 sqlstm.sqhstl[16] = (unsigned long )6;
                 sqlstm.sqhsts[16] = (         int  )0;
                 sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
                 sqlstm.sqinds[16] = (         int  )0;
                 sqlstm.sqharm[16] = (unsigned long )0;
                 sqlstm.sqadto[16] = (unsigned short )0;
                 sqlstm.sqtdso[16] = (unsigned short )0;
                 sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
                 sqlstm.sqhstl[17] = (unsigned long )6;
                 sqlstm.sqhsts[17] = (         int  )0;
                 sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
                 sqlstm.sqinds[17] = (         int  )0;
                 sqlstm.sqharm[17] = (unsigned long )0;
                 sqlstm.sqadto[17] = (unsigned short )0;
                 sqlstm.sqtdso[17] = (unsigned short )0;
                 sqlstm.sqhstv[18] = (unsigned char  *)&v_upload_txn_id;
                 sqlstm.sqhstl[18] = (unsigned long )19;
                 sqlstm.sqhsts[18] = (         int  )0;
                 sqlstm.sqindv[18] = (         short *)&ind_upload_txn_id;
                 sqlstm.sqinds[18] = (         int  )0;
                 sqlstm.sqharm[18] = (unsigned long )0;
                 sqlstm.sqadto[18] = (unsigned short )0;
                 sqlstm.sqtdso[18] = (unsigned short )0;
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
                 if (sqlca.sqlcode < 0) goto getregendetail_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

/////batch_id
                	if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetReGenDetailByRandom batch_id= [%s]\n",v_batch_id.arr));
			}

///seq_num
			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetReGenDetailByRandom seq_num= [%d]\n",v_seq_num));
			}

////txn_id
                	if(ind_txn_id>=0){
                        	v_txn_id.arr[v_txn_id.len]='\0';
                        	PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetReGenDetailByRandom txn_id= [%s]\n",v_txn_id.arr));
                	}

////upload_txn_id
                	if(ind_upload_txn_id>=0){
                        	v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
                        	PutField_CString(myHash,"upload_txn_id",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetReGenDetailByRandom upload_txn_id= [%s]\n",v_upload_txn_id.arr));
                	}

/////merchant_ref
                	if(ind_merchant_ref>=0){
                        	v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        	PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetReGenDetailByRandom merchant_ref= [%s]\n",v_merchant_ref.arr));
                	}

/////country
                	if(ind_country>=0){
                        	v_country.arr[v_country.len]='\0';
                        	PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetReGenDetailByRandom country= [%s]\n",v_country.arr));
                	}

/////identity_id
                	if(ind_identity_id>=0){
                        	v_identity_id.arr[v_identity_id.len]='\0';
                        	PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetReGenDetailByRandom identity_id= [%s]\n",v_identity_id.arr));
                	}

/////account_num
                	if(ind_account_num>=0){
                	        v_account_num.arr[v_account_num.len]='\0';
                	        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetReGenDetailByRandom account_num= [%s]\n",v_account_num.arr));
                	}

/////account_name
                	if(ind_account_name>=0){
                	        v_account_name.arr[v_account_name.len]='\0';
                	        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetReGenDetailByRandom account_name= [%s]\n",v_account_name.arr));
                	}

/////bank_name
                	if(ind_bank_name>=0){
                	        v_bank_name.arr[v_bank_name.len]='\0';
                        	PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetReGenDetailByRandom bank_name= [%s]\n",v_bank_name.arr));
        		}

/////bank_code
                	if(ind_bank_code>=0){
                        	v_bank_code.arr[v_bank_code.len]='\0';
                        	PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetReGenDetailByRandom bank_code= [%s]\n",v_bank_code.arr));
                	}

////branch
                	if(ind_branch>=0){
                        	v_branch.arr[v_branch.len]='\0';
                        	PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetReGenDetailByRandom branch= [%s]\n",v_branch.arr));
                	}

////phone_num
                	if(ind_phone_num>=0){
                        	v_phone_num.arr[v_phone_num.len]='\0';
                        	PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetReGenDetailByRandom phone_num= [%s]\n",v_phone_num.arr));
                	}

////province
                	if(ind_province>=0){
                        	v_province.arr[v_province.len]='\0';
                        	PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetReGenDetailByRandom province= [%s]\n",v_province.arr));
                	}

////city
                	if(ind_city>=0){
                        	v_city.arr[v_city.len]='\0';
                        	PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetReGenDetailByRandom city= [%s]\n",v_city.arr));
                	}

////payout_currency
                	if(ind_payout_ccy>=0){
                        	v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        	PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetReGenDetailByRandom payout_ccy= [%s]\n",v_payout_ccy.arr));
                	}

////request_currency
                	if(ind_request_ccy>=0){
                        	v_request_ccy.arr[v_request_ccy.len]='\0';
                        	PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetReGenDetailByRandom request_ccy= [%s]\n",v_request_ccy.arr));
                	}

////payout_amount
                	if(ind_payout_amount>=0){
                        	PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetReGenDetailByRandom payout_amount = [%lf]\n",v_payout_amount));
                	}

////request_amount
                	if(ind_request_amount>=0){
                        	PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetReGenDetailByRandom request_amount = [%lf]\n",v_request_amount));
                	}

                	RecordSet_Add(myRec,myHash);

        	}while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getregenb; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 23;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )625;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getregendetail_error;
}


	}
	else{
		/* EXEC SQL DECLARE c_cursor_getregendetail CURSOR FOR
                  select
                        fd_batch_id,
                        fd_seq_num,
			fd_txn_id,
			fd_merchant_ref,
			fd_country,
			fd_identity_id,
			fd_account_num,
			fd_account_name,
			fd_bank_name,
			fd_bank_code,
			fd_branch,
			fd_phone_num,
			fd_province,
			fd_city,
			fd_payout_amount,
			fd_request_amount,
			fd_payout_currency,
			fd_request_currency,
			fd_upload_txn_id
                  from    (SELECT * FROM payout_generated_file_dt ORDER BY dbms_random.value)
                  where	  fd_status = :hv_status; */ 


		/* EXEC SQL OPEN  c_cursor_getregendetail; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 23;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0007;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )640;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_status;
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
  if (sqlca.sqlcode < 0) goto getregendetail_error;
}


        	do{
                	/* EXEC SQL FETCH c_cursor_getregendetail
                	INTO
                	        :v_batch_id:ind_batch_id,
                        	:v_seq_num:ind_seq_num,
				:v_txn_id:ind_txn_id,
				:v_merchant_ref:ind_merchant_ref,
				:v_country:ind_country,
				:v_identity_id:ind_identity_id,
				:v_account_num:ind_account_num,
				:v_account_name:ind_account_name,
				:v_bank_name:ind_bank_name,
				:v_bank_code:ind_bank_code,
				:v_branch:ind_branch,
				:v_phone_num:ind_phone_num,
				:v_province:ind_province,
				:v_city:ind_city,
				:v_payout_amount:ind_payout_amount,
				:v_request_amount:ind_request_amount,
				:v_payout_ccy:ind_payout_ccy,
				:v_request_ccy:ind_request_ccy,
				:v_upload_txn_id:ind_upload_txn_id; */ 

{
                 struct sqlexd sqlstm;
                 sqlstm.sqlvsn = 12;
                 sqlstm.arrsiz = 23;
                 sqlstm.sqladtp = &sqladt;
                 sqlstm.sqltdsp = &sqltds;
                 sqlstm.iters = (unsigned int  )1;
                 sqlstm.offset = (unsigned int  )659;
                 sqlstm.selerr = (unsigned short)1;
                 sqlstm.cud = sqlcud0;
                 sqlstm.sqlest = (unsigned char  *)&sqlca;
                 sqlstm.sqlety = (unsigned short)4352;
                 sqlstm.occurs = (unsigned int  )0;
                 sqlstm.sqfoff = (         int )0;
                 sqlstm.sqfmod = (unsigned int )2;
                 sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
                 sqlstm.sqhstl[0] = (unsigned long )19;
                 sqlstm.sqhsts[0] = (         int  )0;
                 sqlstm.sqindv[0] = (         short *)&ind_batch_id;
                 sqlstm.sqinds[0] = (         int  )0;
                 sqlstm.sqharm[0] = (unsigned long )0;
                 sqlstm.sqadto[0] = (unsigned short )0;
                 sqlstm.sqtdso[0] = (unsigned short )0;
                 sqlstm.sqhstv[1] = (unsigned char  *)&v_seq_num;
                 sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
                 sqlstm.sqhsts[1] = (         int  )0;
                 sqlstm.sqindv[1] = (         short *)&ind_seq_num;
                 sqlstm.sqinds[1] = (         int  )0;
                 sqlstm.sqharm[1] = (unsigned long )0;
                 sqlstm.sqadto[1] = (unsigned short )0;
                 sqlstm.sqtdso[1] = (unsigned short )0;
                 sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
                 sqlstm.sqhstl[2] = (unsigned long )19;
                 sqlstm.sqhsts[2] = (         int  )0;
                 sqlstm.sqindv[2] = (         short *)&ind_txn_id;
                 sqlstm.sqinds[2] = (         int  )0;
                 sqlstm.sqharm[2] = (unsigned long )0;
                 sqlstm.sqadto[2] = (unsigned short )0;
                 sqlstm.sqtdso[2] = (unsigned short )0;
                 sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_ref;
                 sqlstm.sqhstl[3] = (unsigned long )53;
                 sqlstm.sqhsts[3] = (         int  )0;
                 sqlstm.sqindv[3] = (         short *)&ind_merchant_ref;
                 sqlstm.sqinds[3] = (         int  )0;
                 sqlstm.sqharm[3] = (unsigned long )0;
                 sqlstm.sqadto[3] = (unsigned short )0;
                 sqlstm.sqtdso[3] = (unsigned short )0;
                 sqlstm.sqhstv[4] = (unsigned char  *)&v_country;
                 sqlstm.sqhstl[4] = (unsigned long )5;
                 sqlstm.sqhsts[4] = (         int  )0;
                 sqlstm.sqindv[4] = (         short *)&ind_country;
                 sqlstm.sqinds[4] = (         int  )0;
                 sqlstm.sqharm[4] = (unsigned long )0;
                 sqlstm.sqadto[4] = (unsigned short )0;
                 sqlstm.sqtdso[4] = (unsigned short )0;
                 sqlstm.sqhstv[5] = (unsigned char  *)&v_identity_id;
                 sqlstm.sqhstl[5] = (unsigned long )28;
                 sqlstm.sqhsts[5] = (         int  )0;
                 sqlstm.sqindv[5] = (         short *)&ind_identity_id;
                 sqlstm.sqinds[5] = (         int  )0;
                 sqlstm.sqharm[5] = (unsigned long )0;
                 sqlstm.sqadto[5] = (unsigned short )0;
                 sqlstm.sqtdso[5] = (unsigned short )0;
                 sqlstm.sqhstv[6] = (unsigned char  *)&v_account_num;
                 sqlstm.sqhstl[6] = (unsigned long )28;
                 sqlstm.sqhsts[6] = (         int  )0;
                 sqlstm.sqindv[6] = (         short *)&ind_account_num;
                 sqlstm.sqinds[6] = (         int  )0;
                 sqlstm.sqharm[6] = (unsigned long )0;
                 sqlstm.sqadto[6] = (unsigned short )0;
                 sqlstm.sqtdso[6] = (unsigned short )0;
                 sqlstm.sqhstv[7] = (unsigned char  *)&v_account_name;
                 sqlstm.sqhstl[7] = (unsigned long )103;
                 sqlstm.sqhsts[7] = (         int  )0;
                 sqlstm.sqindv[7] = (         short *)&ind_account_name;
                 sqlstm.sqinds[7] = (         int  )0;
                 sqlstm.sqharm[7] = (unsigned long )0;
                 sqlstm.sqadto[7] = (unsigned short )0;
                 sqlstm.sqtdso[7] = (unsigned short )0;
                 sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_name;
                 sqlstm.sqhstl[8] = (unsigned long )153;
                 sqlstm.sqhsts[8] = (         int  )0;
                 sqlstm.sqindv[8] = (         short *)&ind_bank_name;
                 sqlstm.sqinds[8] = (         int  )0;
                 sqlstm.sqharm[8] = (unsigned long )0;
                 sqlstm.sqadto[8] = (unsigned short )0;
                 sqlstm.sqtdso[8] = (unsigned short )0;
                 sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_code;
                 sqlstm.sqhstl[9] = (unsigned long )13;
                 sqlstm.sqhsts[9] = (         int  )0;
                 sqlstm.sqindv[9] = (         short *)&ind_bank_code;
                 sqlstm.sqinds[9] = (         int  )0;
                 sqlstm.sqharm[9] = (unsigned long )0;
                 sqlstm.sqadto[9] = (unsigned short )0;
                 sqlstm.sqtdso[9] = (unsigned short )0;
                 sqlstm.sqhstv[10] = (unsigned char  *)&v_branch;
                 sqlstm.sqhstl[10] = (unsigned long )153;
                 sqlstm.sqhsts[10] = (         int  )0;
                 sqlstm.sqindv[10] = (         short *)&ind_branch;
                 sqlstm.sqinds[10] = (         int  )0;
                 sqlstm.sqharm[10] = (unsigned long )0;
                 sqlstm.sqadto[10] = (unsigned short )0;
                 sqlstm.sqtdso[10] = (unsigned short )0;
                 sqlstm.sqhstv[11] = (unsigned char  *)&v_phone_num;
                 sqlstm.sqhstl[11] = (unsigned long )28;
                 sqlstm.sqhsts[11] = (         int  )0;
                 sqlstm.sqindv[11] = (         short *)&ind_phone_num;
                 sqlstm.sqinds[11] = (         int  )0;
                 sqlstm.sqharm[11] = (unsigned long )0;
                 sqlstm.sqadto[11] = (unsigned short )0;
                 sqlstm.sqtdso[11] = (unsigned short )0;
                 sqlstm.sqhstv[12] = (unsigned char  *)&v_province;
                 sqlstm.sqhstl[12] = (unsigned long )103;
                 sqlstm.sqhsts[12] = (         int  )0;
                 sqlstm.sqindv[12] = (         short *)&ind_province;
                 sqlstm.sqinds[12] = (         int  )0;
                 sqlstm.sqharm[12] = (unsigned long )0;
                 sqlstm.sqadto[12] = (unsigned short )0;
                 sqlstm.sqtdso[12] = (unsigned short )0;
                 sqlstm.sqhstv[13] = (unsigned char  *)&v_city;
                 sqlstm.sqhstl[13] = (unsigned long )103;
                 sqlstm.sqhsts[13] = (         int  )0;
                 sqlstm.sqindv[13] = (         short *)&ind_city;
                 sqlstm.sqinds[13] = (         int  )0;
                 sqlstm.sqharm[13] = (unsigned long )0;
                 sqlstm.sqadto[13] = (unsigned short )0;
                 sqlstm.sqtdso[13] = (unsigned short )0;
                 sqlstm.sqhstv[14] = (unsigned char  *)&v_payout_amount;
                 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                 sqlstm.sqhsts[14] = (         int  )0;
                 sqlstm.sqindv[14] = (         short *)&ind_payout_amount;
                 sqlstm.sqinds[14] = (         int  )0;
                 sqlstm.sqharm[14] = (unsigned long )0;
                 sqlstm.sqadto[14] = (unsigned short )0;
                 sqlstm.sqtdso[14] = (unsigned short )0;
                 sqlstm.sqhstv[15] = (unsigned char  *)&v_request_amount;
                 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                 sqlstm.sqhsts[15] = (         int  )0;
                 sqlstm.sqindv[15] = (         short *)&ind_request_amount;
                 sqlstm.sqinds[15] = (         int  )0;
                 sqlstm.sqharm[15] = (unsigned long )0;
                 sqlstm.sqadto[15] = (unsigned short )0;
                 sqlstm.sqtdso[15] = (unsigned short )0;
                 sqlstm.sqhstv[16] = (unsigned char  *)&v_payout_ccy;
                 sqlstm.sqhstl[16] = (unsigned long )6;
                 sqlstm.sqhsts[16] = (         int  )0;
                 sqlstm.sqindv[16] = (         short *)&ind_payout_ccy;
                 sqlstm.sqinds[16] = (         int  )0;
                 sqlstm.sqharm[16] = (unsigned long )0;
                 sqlstm.sqadto[16] = (unsigned short )0;
                 sqlstm.sqtdso[16] = (unsigned short )0;
                 sqlstm.sqhstv[17] = (unsigned char  *)&v_request_ccy;
                 sqlstm.sqhstl[17] = (unsigned long )6;
                 sqlstm.sqhsts[17] = (         int  )0;
                 sqlstm.sqindv[17] = (         short *)&ind_request_ccy;
                 sqlstm.sqinds[17] = (         int  )0;
                 sqlstm.sqharm[17] = (unsigned long )0;
                 sqlstm.sqadto[17] = (unsigned short )0;
                 sqlstm.sqtdso[17] = (unsigned short )0;
                 sqlstm.sqhstv[18] = (unsigned char  *)&v_upload_txn_id;
                 sqlstm.sqhstl[18] = (unsigned long )19;
                 sqlstm.sqhsts[18] = (         int  )0;
                 sqlstm.sqindv[18] = (         short *)&ind_upload_txn_id;
                 sqlstm.sqinds[18] = (         int  )0;
                 sqlstm.sqharm[18] = (unsigned long )0;
                 sqlstm.sqadto[18] = (unsigned short )0;
                 sqlstm.sqtdso[18] = (unsigned short )0;
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
                 if (sqlca.sqlcode < 0) goto getregendetail_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash,0);

                	if(ind_batch_id>=0){
				v_batch_id.arr[v_batch_id.len]='\0';
				PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetReGenDetailByRandom batch_id= [%s]\n",v_batch_id.arr));
			}

			if(ind_seq_num>=0){
				PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetReGenDetailByRandom seq_num= [%d]\n",v_seq_num));
			}

                	if(ind_txn_id>=0){
                        	v_txn_id.arr[v_txn_id.len]='\0';
                        	PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetReGenDetailByRandom txn_id= [%s]\n",v_txn_id.arr));
                	}

                	if(ind_upload_txn_id>=0){
                        	v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
                        	PutField_CString(myHash,"upload_txn_id",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetReGenDetailByRandom upload_txn_id= [%s]\n",v_upload_txn_id.arr));
                	}

                	if(ind_merchant_ref>=0){
                        	v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        	PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetReGenDetailByRandom merchant_ref= [%s]\n",v_merchant_ref.arr));
                	}

                	if(ind_country>=0){
                        	v_country.arr[v_country.len]='\0';
                        	PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetReGenDetailByRandom country= [%s]\n",v_country.arr));
                	}

                	if(ind_identity_id>=0){
                        	v_identity_id.arr[v_identity_id.len]='\0';
                        	PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetReGenDetailByRandom identity_id= [%s]\n",v_identity_id.arr));
                	}

                	if(ind_account_num>=0){
                	        v_account_num.arr[v_account_num.len]='\0';
                	        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetReGenDetailByRandom account_num= [%s]\n",v_account_num.arr));
                	}

                	if(ind_account_name>=0){
                	        v_account_name.arr[v_account_name.len]='\0';
                	        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetReGenDetailByRandom account_name= [%s]\n",v_account_name.arr));
                	}

                	if(ind_bank_name>=0){
                	        v_bank_name.arr[v_bank_name.len]='\0';
                        	PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetReGenDetailByRandom bank_name= [%s]\n",v_bank_name.arr));
        		}

                	if(ind_bank_code>=0){
                        	v_bank_code.arr[v_bank_code.len]='\0';
                        	PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetReGenDetailByRandom bank_code= [%s]\n",v_bank_code.arr));
                	}

                	if(ind_branch>=0){
                        	v_branch.arr[v_branch.len]='\0';
                        	PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetReGenDetailByRandom branch= [%s]\n",v_branch.arr));
                	}

                	if(ind_phone_num>=0){
                        	v_phone_num.arr[v_phone_num.len]='\0';
                        	PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetReGenDetailByRandom phone_num= [%s]\n",v_phone_num.arr));
                	}

                	if(ind_province>=0){
                        	v_province.arr[v_province.len]='\0';
                        	PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetReGenDetailByRandom province= [%s]\n",v_province.arr));
                	}

                	if(ind_city>=0){
                        	v_city.arr[v_city.len]='\0';
                        	PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetReGenDetailByRandom city= [%s]\n",v_city.arr));
                	}

                	if(ind_payout_ccy>=0){
                        	v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        	PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetReGenDetailByRandom payout_ccy= [%s]\n",v_payout_ccy.arr));
                	}

                	if(ind_request_ccy>=0){
                        	v_request_ccy.arr[v_request_ccy.len]='\0';
                        	PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetReGenDetailByRandom request_ccy= [%s]\n",v_request_ccy.arr));
                	}

                	if(ind_payout_amount>=0){
                        	PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetReGenDetailByRandom payout_amount = [%lf]\n",v_payout_amount));
                	}

                	if(ind_request_amount>=0){
                        	PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetReGenDetailByRandom request_amount = [%lf]\n",v_request_amount));
                	}

                	RecordSet_Add(myRec,myHash);

        	}while(PD_TRUE);

        	/* EXEC SQL CLOSE c_cursor_getregendetail; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 23;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )750;
         sqlstm.cud = sqlcud0;
         sqlstm.sqlest = (unsigned char  *)&sqlca;
         sqlstm.sqlety = (unsigned short)4352;
         sqlstm.occurs = (unsigned int  )0;
         sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
         if (sqlca.sqlcode < 0) goto getregendetail_error;
}



	}
	

DEBUGLOG(("GetReGenDetailByRandom Normal Exit\n"));
        return  PD_OK;

getregendetail_error:
DEBUGLOG(("getregendetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}


int GetFileDetailByUploadTxnId(const hash_t *hTxn, recordset_t* myRec)
{
        hash_t *myHash;
        char    csBatchId[PD_TXN_SEQ_LEN+1];
        char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO getfiledetailbytxnid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_upload_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_upload_txn_id;

                int             hv_status;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_file_id;

                unsigned long   v_batch_id;
                int             v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

                double          v_payout_amount;
                double          v_request_amount;
                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;


                short           ind_file_id = -1;
                short           ind_batch_id = -1;
                short           ind_seq_num = -1;
                short           ind_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
                short           ind_psp_id= -1;
                short           ind_merchant_id= -1;
                short           ind_service_code= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_status = PAYOUT_MASTER_TRANSACTION_GENERATED;

        if(GetField_CString(hTxn,"upload_txn_id",&csTmp)){
                hv_upload_txn_id.len = strlen(csTmp);
                memcpy(hv_upload_txn_id.arr,csTmp,hv_upload_txn_id.len);
DEBUGLOG(("GetFileDetailByUploadTxnId upload_txn_id = [%.*s]\n",hv_upload_txn_id.len,hv_upload_txn_id.arr));
        }
/* EXEC SQL DECLARE c_cursor_getfiledetailbytxnid CURSOR FOR
                select	fd_file_id,
                        fd_batch_id,
                        fd_seq_num,
                        fd_txn_id,
                        fd_merchant_ref,
                        fd_country,
                        fd_identity_id,
                        fd_account_num,
                        fd_account_name,
                        fd_bank_name,
                        fd_bank_code,
                        fd_branch,
                        fd_phone_num,
                        fd_province,
                        fd_city,
                        fd_payout_amount,
                        fd_request_amount,
                        fd_payout_currency,
                        fd_request_currency,
                        fh_file_pid,
                        uh_merchant_id,
                        uh_service_code
                from    payout_generated_file_dt,
                        payout_generated_file_hd,
                        merchant_upload_file_header,
                        merchant_upload_file_detail
                where   fd_upload_txn_id=:hv_upload_txn_id
                and     fd_upload_txn_id = ud_txn_id
                and     fd_file_id = fh_file_id
                and     uh_batch_id = ud_batch_id
		and	fd_status =:hv_status; */ 


        /* EXEC SQL OPEN  c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0008;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )765;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_upload_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getfiledetailbytxnid
                INTO
                        :v_file_id:ind_file_id,
                        :v_batch_id:ind_batch_id,
                        :v_seq_num:ind_seq_num,
                        :v_txn_id:ind_txn_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_country:ind_country,
                        :v_identity_id:ind_identity_id,
                        :v_account_num:ind_account_num,
                        :v_account_name:ind_account_name,
                        :v_bank_name:ind_bank_name,
                        :v_bank_code:ind_bank_code,
                        :v_branch:ind_branch,
                        :v_phone_num:ind_phone_num,
                        :v_province:ind_province,
                        :v_city:ind_city,
                        :v_payout_amount:ind_payout_amount,
                        :v_request_amount:ind_request_amount,
                        :v_payout_ccy:ind_payout_ccy,
                        :v_request_ccy:ind_request_ccy,
                        :v_psp_id:ind_psp_id,
                        :v_merchant_id:ind_merchant_id,
                        :v_service_code:ind_service_code; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )788;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_file_id;
                sqlstm.sqhstl[0] = (unsigned long )18;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_file_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[1] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_batch_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_seq_num;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_seq_num;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_id;
                sqlstm.sqhstl[3] = (unsigned long )19;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_id;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[4] = (unsigned long )53;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_country;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_country;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[6] = (unsigned long )28;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_identity_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_account_num;
                sqlstm.sqhstl[7] = (unsigned long )28;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_account_num;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[8] = (unsigned long )103;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_account_name;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[9] = (unsigned long )153;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_bank_name;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[10] = (unsigned long )13;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_bank_code;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[11] = (unsigned long )153;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_branch;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_phone_num;
                sqlstm.sqhstl[12] = (unsigned long )28;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_phone_num;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[13] = (unsigned long )103;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_province;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[14] = (unsigned long )103;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_city;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_payout_amount;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_payout_amount;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_request_amount;
                sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_request_amount;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_ccy;
                sqlstm.sqhstl[17] = (unsigned long )6;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_payout_ccy;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_request_ccy;
                sqlstm.sqhstl[18] = (unsigned long )6;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_request_ccy;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[19] = (unsigned long )13;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_psp_id;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[20] = (unsigned long )18;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[21] = (unsigned long )6;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_service_code;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/*file_id*/
                if(ind_file_id>=0){
                        v_file_id.arr[v_file_id.len]='\0';
                        PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId file_id= [%s]\n",v_file_id.arr));
                }


/*batch_id*/
                if(ind_batch_id>=0){
                        sprintf(csBatchId,"%ld",v_batch_id);
                        PutField_CString(myHash,"batch_id",csBatchId);
DEBUGLOG(("GetFileDetailByUploadTxnId batch_id= [%s]\n",csBatchId));
                }

/*seq_num*/
                if(ind_seq_num>=0){
                        PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetFileDetailByUploadTxnId seq_num= [%d]\n",v_seq_num));
                }


/*txn_id*/
                if(ind_txn_id>=0){
                        v_txn_id.arr[v_txn_id.len]='\0';
                        PutField_CString(myHash,"txn_id",(const char*)v_txn_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId txn_id= [%s]\n",v_txn_id.arr));
                }

/*merchant_ref*/
                if(ind_merchant_ref>=0){
                        v_merchant_ref.arr[v_merchant_ref.len]='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId merchant_ref= [%s]\n",v_merchant_ref.arr));
                }

/*country*/
                if(ind_country>=0){
                        v_country.arr[v_country.len]='\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId country= [%s]\n",v_country.arr));
                }

/*identity_id*/
                if(ind_identity_id>=0){
                        v_identity_id.arr[v_identity_id.len]='\0';
                        PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId identity_id= [%s]\n",v_identity_id.arr));
                }

/*account_num*/
                if(ind_account_num>=0){
                        v_account_num.arr[v_account_num.len]='\0';
                        PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId account_num= [%s]\n",v_account_num.arr));
                }

/*account_name*/
                if(ind_account_name>=0){
                        v_account_name.arr[v_account_name.len]='\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId account_name= [%s]\n",v_account_name.arr));
                }

/*bank_name*/
                if(ind_bank_name>=0){
                        v_bank_name.arr[v_bank_name.len]='\0';
                        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId bank_name= [%s]\n",v_bank_name.arr));
        }

/*bank_code*/
                if(ind_bank_code>=0){
                        v_bank_code.arr[v_bank_code.len]='\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId bank_code= [%s]\n",v_bank_code.arr));
                }

/*branch*/
                if(ind_branch>=0){
                        v_branch.arr[v_branch.len]='\0';
                        PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId branch= [%s]\n",v_branch.arr));
                }

/*phone_num*/
                if(ind_phone_num>=0){
                        v_phone_num.arr[v_phone_num.len]='\0';
                        PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId phone_num= [%s]\n",v_phone_num.arr));
                }

/*province*/
                if(ind_province>=0){
                        v_province.arr[v_province.len]='\0';
                        PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId province= [%s]\n",v_province.arr));
                }

/*city*/
                if(ind_city>=0){
                        v_city.arr[v_city.len]='\0';
                        PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId city= [%s]\n",v_city.arr));
                }
/*payout_currency*/
                if(ind_payout_ccy>=0){
                        v_payout_ccy.arr[v_payout_ccy.len]='\0';
                        PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId payout_ccy= [%s]\n",v_payout_ccy.arr));
                }

/*request_currency*/
                if(ind_request_ccy>=0){
                        v_request_ccy.arr[v_request_ccy.len]='\0';
                        PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId request_ccy= [%s]\n",v_request_ccy.arr));
                }

/*payout_amount*/
                if(ind_payout_amount>=0){
                        PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetFileDetailByUploadTxnId payout_amount = [%lf]\n",v_payout_amount));
                }

/*request_amount*/
                if(ind_request_amount>=0){
                        PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetFileDetailByUploadTxnId request_amount = [%lf]\n",v_request_amount));
                }

/*psp_id*/
                if(ind_psp_id>=0){
                        v_psp_id.arr[v_psp_id.len]='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId psp_id = [%s]\n",v_psp_id.arr));
                }
/*merchant_id*/
                if(ind_merchant_id>=0){
                        v_merchant_id.arr[v_merchant_id.len]='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId merchant_id = [%s]\n",v_merchant_id.arr));
                }

/*service_code*/
                if(ind_service_code>=0){
                        v_service_code.arr[v_service_code.len]='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetFileDetailByUploadTxnId service_code = [%s]\n",v_service_code.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )891;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getfiledetailbytxnid_error;
}



DEBUGLOG(("GetFileDetailByUploadTxnId Normal Exit\n"));
        return  PD_OK;

getfiledetailbytxnid_error:
DEBUGLOG(("getfiledetailbytxnid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_Get: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getfiledetailbytxnid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )906;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}


int UpdateByFileNTxnId(const hash_t *hRec)
{
        char*   csBuf;
        char*   csFileId;
        char*   csTxnId;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updateft_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


                /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateByFileNTxnId: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update payout_generated_file_dt set fd_update_timestamp = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        if(GetField_CString(hRec,"file_id",&csFileId)){
DEBUGLOG(("UpdateByFileNTxnId:file_id = [%s]\n",csFileId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByFileNTxnId file_id not found\n"));
                return INT_ERR;
        }
        if(GetField_CString(hRec,"txn_id",&csTxnId)){
DEBUGLOG(("UpdateByFileNTxnId:txn_id = [%s]\n",csTxnId));
        }
        else{
                FREE_ME(csBuf);
DEBUGLOG(("UpdateByFileNTxnId txn_id not found\n"));
                return INT_ERR;
        }


        if(GetField_Int(hRec,"status",&iTmp)){
DEBUGLOG(("UpdateByFileNTxnId: status = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",fd_status = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if(GetField_CString(hRec,"update_user",&csBuf)){
DEBUGLOG(("UpdateByFileNTxnId: update_user = [%s]\n",csBuf));
                strcat((char*)hv_dynstmt.arr, ",fd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char*)hv_dynstmt.arr, " WHERE fd_file_id= ");
        strcat((char*)hv_dynstmt.arr, csFileId);
	strcat((char*)hv_dynstmt.arr, " AND fd_txn_id= '");
        strcat((char*)hv_dynstmt.arr, csTxnId);
	strcat((char*)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));


        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )921;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )1026;
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
        if (sqlca.sqlcode < 0) goto updateft_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )940;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updateft_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateByFileNTxnId Normal Exit\n"));
        return PD_OK;

updateft_error:
DEBUGLOG(("updateft_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_UpdateByFileNTxnId: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int GetDetailByCondition(hash_t *hTxn, recordset_t* myRec)
{
        hash_t *myHash;
        char    *csTmp;
        int     iTmp;
        int     iRet = PD_NOT_FOUND;
        /* EXEC SQL WHENEVER SQLERROR GOTO getdt_con_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;

                /* varchar         hv_file_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_file_id;

                /* varchar         hv_org_txn_id_list[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_org_txn_id_list;

                int             hv_upload_status;
                int             hv_status;

                SQL_CURSOR      c_cursor_dtcon;

                /* varchar         v_file_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_file_id;

                /* varchar         v_batch_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_batch_id;

                int             v_seq_num;
                /* varchar         v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_upload_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_upload_txn_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                /* varchar         v_country[PD_COUNTRY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_country;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_account_num[PD_AC_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_num;

                /* varchar         v_account_name[PD_ACC_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_bank_name[PD_BANK_NAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_phone_num[PD_MOBILE_NO_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_phone_num;

                /* varchar         v_province[PD_PROVINCE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_province;

                /* varchar         v_city[PD_CITY_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_city;

                /* varchar         v_payout_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_payout_ccy;

                /* varchar         v_request_ccy[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_request_ccy;

		double          v_payout_amount;
                double          v_request_amount;
                /* varchar         v_file_name[PD_FILENAME_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_file_name;

                /* varchar         v_psp_id[PD_PSP_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_psp_client_id[PD_CLIENT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_client_id;

                /* varchar         v_ccy_id[PD_CCY_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy_id;

		int		v_total_cnt;
		double		v_total_amt;
		double		v_psp_cost;


                short           ind_file_id = -1;
                short           ind_batch_id = -1;
                short           ind_seq_num = -1;
                short           ind_txn_id = -1;
                short           ind_upload_txn_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_country = -1;
                short           ind_identity_id = -1;
                short           ind_account_num = -1;
                short           ind_account_name = -1;
                short           ind_bank_name = -1;
                short           ind_bank_code = -1;
                short           ind_branch = -1;
                short           ind_phone_num = -1;
                short           ind_province = -1;
                short           ind_city = -1;
                short           ind_payout_ccy = -1;
                short           ind_request_ccy = -1;
                short           ind_payout_amount = -1;
                short           ind_request_amount = -1;
                short           ind_file_name = -1;
                short           ind_psp_id = -1;
                short           ind_psp_client_id = -1;
                short           ind_ccy_id= -1;
                short           ind_total_cnt= -1;
                short           ind_total_amt= -1;
                short           ind_psp_cost= -1;

                short           ind_in_file_id = -1;
                short           ind_status= -1;
                short           ind_upload_status= -1;
                short           ind_org_txn_id_list= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_Int(hTxn,"status",&iTmp)){
                hv_status= iTmp;
DEBUGLOG(("GetDetailByCondition status = [%d]\n",hv_status));
                ind_status= 0;
        }

	if(GetField_Int(hTxn,"upload_status",&iTmp)){
                hv_upload_status= iTmp;
DEBUGLOG(("GetDetailByCondition upload_status = [%d]\n",hv_upload_status));
                ind_upload_status= 0;
        }

        if(GetField_CString(hTxn,"file_id",&csTmp)){
                hv_file_id.len = strlen(csTmp);
                memcpy(hv_file_id.arr,csTmp,hv_file_id.len);
DEBUGLOG(("GetDetailByCondition file_id = [%.*s]\n",hv_file_id.len,hv_file_id.arr));
                ind_in_file_id= 0;
        }
	else if(GetField_CString(hTxn,"txn_list",&csTmp)){
		hv_org_txn_id_list.len = strlen(csTmp);
                memcpy(hv_org_txn_id_list.arr,csTmp,hv_org_txn_id_list.len);
DEBUGLOG(("GetDetailByCondition org_txn_id_list = [%.*s]\n",hv_org_txn_id_list.len,hv_org_txn_id_list.arr));
                ind_org_txn_id_list= 0;
	}

        /* EXEC SQL ALLOCATE       :c_cursor_dtcon; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 23;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )955;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
        if (sqlca.sqlcode < 0) goto getdt_con_error;
}



                /* EXEC SQL EXECUTE
                        BEGIN
                                :hv_return_value := sp_payout_gen_dt_get(
                                                                :hv_file_id:ind_in_file_id,
                                                                :hv_org_txn_id_list:ind_org_txn_id_list,
                                                                :hv_upload_status:ind_upload_status,
                                                                :hv_status:ind_status,
                                                                :c_cursor_dtcon);
                        END;
                END-EXEC; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 23;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.stmt = "begin :hv_return_value := sp_payout_gen_dt_g\
et ( :hv_file_id:ind_in_file_id , :hv_org_txn_id_list:ind_org_txn_id_list , :\
hv_upload_status:ind_upload_status , :hv_status:ind_status , :c_cursor_dtcon \
) ; END ;";
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )974;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&hv_file_id;
                sqlstm.sqhstl[1] = (unsigned long )18;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_in_file_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&hv_org_txn_id_list;
                sqlstm.sqhstl[2] = (unsigned long )2050;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_org_txn_id_list;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&hv_upload_status;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_upload_status;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_status;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&c_cursor_dtcon;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)0;
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
                if (sqlca.sqlcode < 0) goto getdt_con_error;
}



	if (hv_return_value > 0)  {
DEBUGLOG(("Find Found\n"));
                iRet = PD_FOUND;
                for (;;) {
                        myHash = (hash_t*) malloc (sizeof(hash_t));
                        hash_init(myHash,0);

                        ind_file_id = -1;
                        ind_batch_id = -1;
                        ind_seq_num = -1;
                        ind_txn_id = -1;
                        ind_upload_txn_id = -1;
                        ind_merchant_ref = -1;
                        ind_country = -1;
                        ind_identity_id = -1;
                        ind_account_num = -1;
                        ind_account_name = -1;
                        ind_bank_name = -1;
                        ind_bank_code = -1;
                        ind_branch = -1;
                        ind_phone_num = -1;
                        ind_province = -1;
                        ind_city = -1;
                        ind_payout_ccy = -1;
                        ind_request_ccy = -1;
                        ind_payout_amount = -1;
                        ind_request_amount = -1;
                        ind_file_name = -1;
                        ind_psp_id = -1;
                        ind_psp_client_id = -1;
                        ind_ccy_id= -1;
                        ind_total_cnt= -1;
			ind_total_amt= -1;
			ind_psp_cost= -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_dtcon
                        INTO
                                :v_file_id:ind_file_id,
                                :v_batch_id:ind_batch_id,
                                :v_seq_num:ind_seq_num,
                                :v_txn_id:ind_txn_id,
                                :v_upload_txn_id:ind_upload_txn_id,
                                :v_merchant_ref:ind_merchant_ref,
                                :v_country:ind_country,
                                :v_identity_id:ind_identity_id,
                                :v_account_num:ind_account_num,
                                :v_account_name:ind_account_name,
                                :v_bank_name:ind_bank_name,
                                :v_bank_code:ind_bank_code,
                                :v_branch:ind_branch,
                                :v_phone_num:ind_phone_num,
                                :v_province:ind_province,
                                :v_city:ind_city,
                                :v_payout_amount:ind_payout_amount,
                                :v_request_amount:ind_request_amount,
                                :v_payout_ccy:ind_payout_ccy,
                                :v_request_ccy:ind_request_ccy,
                                :v_file_name:ind_file_name,
                                :v_psp_id:ind_psp_id,
                                :v_psp_client_id:ind_psp_client_id,
				:v_ccy_id:ind_ccy_id,
                                :v_total_cnt:ind_total_cnt,
                                :v_total_amt:ind_total_amt,
				:v_psp_cost:ind_psp_cost; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 28;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )1013;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_file_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_file_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_batch_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_batch_id;
                        sqlstm.sqinds[2] = (         int  )0;
                        sqlstm.sqharm[2] = (unsigned long )0;
                        sqlstm.sqadto[2] = (unsigned short )0;
                        sqlstm.sqtdso[2] = (unsigned short )0;
                        sqlstm.sqhstv[3] = (unsigned char  *)&v_seq_num;
                        sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[3] = (         int  )0;
                        sqlstm.sqindv[3] = (         short *)&ind_seq_num;
                        sqlstm.sqinds[3] = (         int  )0;
                        sqlstm.sqharm[3] = (unsigned long )0;
                        sqlstm.sqadto[3] = (unsigned short )0;
                        sqlstm.sqtdso[3] = (unsigned short )0;
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[4] = (unsigned long )19;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_upload_txn_id;
                        sqlstm.sqhstl[5] = (unsigned long )19;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_upload_txn_id;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_ref;
                        sqlstm.sqhstl[6] = (unsigned long )53;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_merchant_ref;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_country;
                        sqlstm.sqhstl[7] = (unsigned long )5;
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_country;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_identity_id;
                        sqlstm.sqhstl[8] = (unsigned long )28;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_identity_id;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_account_num;
                        sqlstm.sqhstl[9] = (unsigned long )28;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_account_num;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_account_name;
                        sqlstm.sqhstl[10] = (unsigned long )103;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_account_name;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_bank_name;
                        sqlstm.sqhstl[11] = (unsigned long )153;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_bank_name;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_bank_code;
                        sqlstm.sqhstl[12] = (unsigned long )13;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_bank_code;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_branch;
                        sqlstm.sqhstl[13] = (unsigned long )153;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_branch;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_phone_num;
                        sqlstm.sqhstl[14] = (unsigned long )28;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_phone_num;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_province;
                        sqlstm.sqhstl[15] = (unsigned long )103;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_province;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_city;
                        sqlstm.sqhstl[16] = (unsigned long )103;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_city;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_payout_amount;
                        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_payout_amount;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_request_amount;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_request_amount;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_payout_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_payout_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
                        sqlstm.sqhstv[20] = (unsigned char  *)&v_request_ccy;
                        sqlstm.sqhstl[20] = (unsigned long )6;
                        sqlstm.sqhsts[20] = (         int  )0;
                        sqlstm.sqindv[20] = (         short *)&ind_request_ccy;
                        sqlstm.sqinds[20] = (         int  )0;
                        sqlstm.sqharm[20] = (unsigned long )0;
                        sqlstm.sqadto[20] = (unsigned short )0;
                        sqlstm.sqtdso[20] = (unsigned short )0;
                        sqlstm.sqhstv[21] = (unsigned char  *)&v_file_name;
                        sqlstm.sqhstl[21] = (unsigned long )53;
                        sqlstm.sqhsts[21] = (         int  )0;
                        sqlstm.sqindv[21] = (         short *)&ind_file_name;
                        sqlstm.sqinds[21] = (         int  )0;
                        sqlstm.sqharm[21] = (unsigned long )0;
                        sqlstm.sqadto[21] = (unsigned short )0;
                        sqlstm.sqtdso[21] = (unsigned short )0;
                        sqlstm.sqhstv[22] = (unsigned char  *)&v_psp_id;
                        sqlstm.sqhstl[22] = (unsigned long )13;
                        sqlstm.sqhsts[22] = (         int  )0;
                        sqlstm.sqindv[22] = (         short *)&ind_psp_id;
                        sqlstm.sqinds[22] = (         int  )0;
                        sqlstm.sqharm[22] = (unsigned long )0;
                        sqlstm.sqadto[22] = (unsigned short )0;
                        sqlstm.sqtdso[22] = (unsigned short )0;
                        sqlstm.sqhstv[23] = (unsigned char  *)&v_psp_client_id;
                        sqlstm.sqhstl[23] = (unsigned long )13;
                        sqlstm.sqhsts[23] = (         int  )0;
                        sqlstm.sqindv[23] = (         short *)&ind_psp_client_id;
                        sqlstm.sqinds[23] = (         int  )0;
                        sqlstm.sqharm[23] = (unsigned long )0;
                        sqlstm.sqadto[23] = (unsigned short )0;
                        sqlstm.sqtdso[23] = (unsigned short )0;
                        sqlstm.sqhstv[24] = (unsigned char  *)&v_ccy_id;
                        sqlstm.sqhstl[24] = (unsigned long )6;
                        sqlstm.sqhsts[24] = (         int  )0;
                        sqlstm.sqindv[24] = (         short *)&ind_ccy_id;
                        sqlstm.sqinds[24] = (         int  )0;
                        sqlstm.sqharm[24] = (unsigned long )0;
                        sqlstm.sqadto[24] = (unsigned short )0;
                        sqlstm.sqtdso[24] = (unsigned short )0;
                        sqlstm.sqhstv[25] = (unsigned char  *)&v_total_cnt;
                        sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[25] = (         int  )0;
                        sqlstm.sqindv[25] = (         short *)&ind_total_cnt;
                        sqlstm.sqinds[25] = (         int  )0;
                        sqlstm.sqharm[25] = (unsigned long )0;
                        sqlstm.sqadto[25] = (unsigned short )0;
                        sqlstm.sqtdso[25] = (unsigned short )0;
                        sqlstm.sqhstv[26] = (unsigned char  *)&v_total_amt;
                        sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[26] = (         int  )0;
                        sqlstm.sqindv[26] = (         short *)&ind_total_amt;
                        sqlstm.sqinds[26] = (         int  )0;
                        sqlstm.sqharm[26] = (unsigned long )0;
                        sqlstm.sqadto[26] = (unsigned short )0;
                        sqlstm.sqtdso[26] = (unsigned short )0;
                        sqlstm.sqhstv[27] = (unsigned char  *)&v_psp_cost;
                        sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[27] = (         int  )0;
                        sqlstm.sqindv[27] = (         short *)&ind_psp_cost;
                        sqlstm.sqinds[27] = (         int  )0;
                        sqlstm.sqharm[27] = (unsigned long )0;
                        sqlstm.sqadto[27] = (unsigned short )0;
                        sqlstm.sqtdso[27] = (unsigned short )0;
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
                        if (sqlca.sqlcode == 1403) break;
                        if (sqlca.sqlcode < 0) goto getdt_con_error;
}




/*file_id*/
                        if(ind_file_id>=0){
                                v_file_id.arr[v_file_id.len]='\0';
                                PutField_CString(myHash,"file_id",(const char*)v_file_id.arr);
DEBUGLOG(("GetDetailByCondition file_id=[%s]\n",v_file_id.arr));
                        }

/*seq_num*/
                        if(ind_seq_num>=0){
                                PutField_Int(myHash,"seq_num",v_seq_num);
DEBUGLOG(("GetDetailByCondition seq_num=[%d]\n",v_seq_num));
                        }

/*batch_id*/
                        if(ind_batch_id>=0){
                                v_batch_id.arr[v_batch_id.len]='\0';
                                PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetDetailByCondition batch_id=[%s]\n",v_batch_id.arr));
                        }

/*txn_id*/
                        if(ind_txn_id>=0){
                                v_txn_id.arr[v_txn_id.len]='\0';
                                PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetDetailByCondition txn_id=[%s]\n",v_txn_id.arr));
                        }

/*upload_txn_id*/
                        if(ind_upload_txn_id>=0){
                                v_upload_txn_id.arr[v_upload_txn_id.len]='\0';
                                PutField_CString(myHash,"upload_txn_seq",(const char*)v_upload_txn_id.arr);
DEBUGLOG(("GetDetailByCondition upload_txn_id=[%s]\n",v_upload_txn_id.arr));
                        }

/*merchant_ref*/
                        if(ind_merchant_ref>=0){
                                v_merchant_ref.arr[v_merchant_ref.len]='\0';
                                PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetDetailByCondition merchant_ref= [%s]\n",v_merchant_ref.arr));
                        }

/*country*/
                        if(ind_country>=0){
                                v_country.arr[v_country.len]='\0';
                                PutField_CString(myHash,"txn_country",(const char*)v_country.arr);
DEBUGLOG(("GetDetailByCondition country= [%s]\n",v_country.arr));
                        }

/*identity_id*/
                        if(ind_identity_id>=0){
                                v_identity_id.arr[v_identity_id.len]='\0';
                                PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetDetailByCondition identity_id= [%s]\n",v_identity_id.arr));
                        }

/*account_num*/
                        if(ind_account_num>=0){
                                v_account_num.arr[v_account_num.len]='\0';
                                PutField_CString(myHash,"account_num",(const char*)v_account_num.arr);
DEBUGLOG(("GetDetailByCondition account_num= [%s]\n",v_account_num.arr));
                        }

/*account_name*/
                        if(ind_account_name>=0){
                                v_account_name.arr[v_account_name.len]='\0';
                                PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetDetailByCondition account_name= [%s]\n",v_account_name.arr));
                        }

/*bank_name*/
                        if(ind_bank_name>=0){
                                v_bank_name.arr[v_bank_name.len]='\0';
                                PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetDetailByCondition bank_name= [%s]\n",v_bank_name.arr));
                        }

/*bank_code*/
                        if(ind_bank_code>=0){
                                v_bank_code.arr[v_bank_code.len]='\0';
                                PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetDetailByCondition bank_code= [%s]\n",v_bank_code.arr));
                        }

/*branch*/
                        if(ind_branch>=0){
                                v_branch.arr[v_branch.len]='\0';
                                PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetDetailByCondition branch= [%s]\n",v_branch.arr));
                        }

/*phone_num*/
                        if(ind_phone_num>=0){
                                v_phone_num.arr[v_phone_num.len]='\0';
                                PutField_CString(myHash,"phone_num",(const char*)v_phone_num.arr);
DEBUGLOG(("GetDetailByCondition phone_num= [%s]\n",v_phone_num.arr));
                        }

/*province*/
                        if(ind_province>=0){
                                v_province.arr[v_province.len]='\0';
                                PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetDetailByCondition province= [%s]\n",v_province.arr));
                        }

/*city*/
                        if(ind_city>=0){
                                v_city.arr[v_city.len]='\0';
                                PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetDetailByCondition city= [%s]\n",v_city.arr));
                        }

/*payout_currency*/
                        if(ind_payout_ccy>=0){
                                v_payout_ccy.arr[v_payout_ccy.len]='\0';
                                PutField_CString(myHash,"payout_ccy",(const char*)v_payout_ccy.arr);
DEBUGLOG(("GetDetailByCondition payout_ccy= [%s]\n",v_payout_ccy.arr));
                        }

/*request_currency*/
                        if(ind_request_ccy>=0){
                                v_request_ccy.arr[v_request_ccy.len]='\0';
                                PutField_CString(myHash,"request_ccy",(const char*)v_request_ccy.arr);
DEBUGLOG(("GetDetailByCondition request_ccy= [%s]\n",v_request_ccy.arr));
                        }

/*payout_amount*/
                        if(ind_payout_amount>=0){
                                PutField_Double(myHash,"payout_amount",v_payout_amount);
DEBUGLOG(("GetDetailByCondition payout_amount = [%lf]\n",v_payout_amount));
                        }

/*request_amount*/
                        if(ind_request_amount>=0){
                                PutField_Double(myHash,"request_amount",v_request_amount);
DEBUGLOG(("GetDetailByCondition request_amount = [%lf]\n",v_request_amount));
                        }

/*file_name*/
                        if(ind_file_name>=0){
                                v_file_name.arr[v_file_name.len]='\0';
                                PutField_CString(myHash,"file_name",(const char*)v_file_name.arr);
DEBUGLOG(("GetDetailByCondition file_name= [%s]\n",v_file_name.arr));
                        }

/*psp_id*/
                        if(ind_psp_id>=0){
                                v_psp_id.arr[v_psp_id.len]='\0';
                                PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetDetailByCondition psp_id= [%s]\n",v_psp_id.arr));
                        }

/*psp_client_id*/
                        if(ind_psp_client_id>=0){
                                v_psp_client_id.arr[v_psp_client_id.len]='\0';
                                PutField_CString(myHash,"client_id",(const char*)v_psp_client_id.arr);
DEBUGLOG(("GetDetailByCondition psp_client_id = [%s]\n",v_psp_client_id.arr));
                        }

/*ccy_id*/
                        if(ind_ccy_id>=0){
                                v_ccy_id.arr[v_ccy_id.len]='\0';
                                PutField_CString(myHash,"ccy_id",(const char*)v_ccy_id.arr);
DEBUGLOG(("GetDetailByCondition ccy_id = [%s]\n",v_ccy_id.arr));
                        }

/*total_cnt*/
                        if(ind_total_cnt>=0){
                                PutField_Int(myHash,"total_cnt",v_total_cnt);
DEBUGLOG(("GetDetailByCondition total_cnt = [%lf]\n",v_total_cnt));
                        }

/*total_amt*/
                        if(ind_total_amt>=0){
                                PutField_Double(myHash,"total_amt",v_total_amt);
DEBUGLOG(("GetDetailByCondition total_amt = [%lf]\n",v_total_amt));
                        }

/*psp_cost*/
                        if(ind_psp_cost>=0){
                                PutField_Double(myHash,"psp_cost",v_psp_cost);
DEBUGLOG(("GetDetailByCondition psp_cost = [%lf]\n",v_psp_cost));
                        }

                        RecordSet_Add(myRec,myHash);

                }
        }

        /* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1140;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
        if (sqlca.sqlcode < 0) goto getdt_con_error;
}


        /* EXEC SQL FREE :c_cursor_dtcon; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1159;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
        if (sqlca.sqlcode < 0) goto getdt_con_error;
}



DEBUGLOG(("GetDetailByCondition Normal Exit [%d]\n",iRet));
        return  iRet;

getdt_con_error:
DEBUGLOG(("getdt_con_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("DBMerchantUploadFileDetail GetDetailByCondition: SP_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_dtcon; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1178;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
}


        /* EXEC SQL FREE :c_cursor_dtcon; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1197;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_dtcon;
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
}


        return PD_ERR;
}


int GetGenIdPairs(const char* csGenId,recordset_t* myRec)
{               
        hash_t *myHash;         
                
        /* EXEC SQL WHENEVER SQLERROR GOTO getgenidpair_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_id;

                
                /* varchar         v_gen_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_gen_txn_id;


		short           ind_gen_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csGenId);
	memcpy(hv_txn_id.arr,csGenId,hv_txn_id.len);
DEBUGLOG(("GetGenIdPairs txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

/* EXEC SQL DECLARE c_cursor_getgenidpair CURSOR FOR
		select	fd_txn_id
		from	payout_generated_file_dt
		where 	fd_upload_txn_id in (
			select	fd_upload_txn_id 
				from	payout_generated_file_dt
				where	fd_txn_id = :hv_txn_id
			)
		and	fd_txn_id <> :hv_txn_id; */ 


	/* EXEC SQL OPEN  c_cursor_getgenidpair; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0010;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1216;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )19;
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
 if (sqlca.sqlcode < 0) goto getgenidpair_error;
}


        do{
                /* EXEC SQL FETCH c_cursor_getgenidpair
                INTO	:v_gen_txn_id:ind_gen_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 28;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1239;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_gen_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_gen_txn_id;
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
                if (sqlca.sqlcode < 0) goto getgenidpair_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);


/*gen_txn_id*/
                if(ind_gen_txn_id>=0){
                        v_gen_txn_id.arr[v_gen_txn_id.len]='\0';
                        PutField_CString(myHash,"gen_txn_id",(const char*)v_gen_txn_id.arr);
DEBUGLOG(("GetGenIdPairs gen_txn_id= [%s]\n",v_gen_txn_id.arr));
                }

                RecordSet_Add(myRec,myHash);

        }while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getgenidpair; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1258;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getgenidpair_error;
}



DEBUGLOG(("GetGenIdPairs Normal Exit\n"));
        return  PD_OK;

getgenidpair_error:
DEBUGLOG(("getgenidpair_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("PayoutGeneratedFileDT_GetGenIdPair: SP_INTERNAL_ERR\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getgenidpair; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 28;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1273;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}
