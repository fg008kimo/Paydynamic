
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
           char  filnam[15];
};
static struct sqlcxp sqlfpn =
{
    14,
    "TxnMiDetail.pc"
};


static unsigned int sqlctx = 1360427;


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
   unsigned char  *sqhstv[31];
   unsigned long  sqhstl[31];
            int   sqhsts[31];
            short *sqindv[31];
            int   sqinds[31];
   unsigned long  sqharm[31];
   unsigned long  *sqharc[31];
   unsigned short  sqadto[31];
   unsigned short  sqtdso[31];
} sqlstm = {12,31};

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

 static char *sq0003 = 
"select tm_entity_id , tm_party_type , tm_party_id , tm_txn_ccy , tm_txn_cou\
ntry , tm_txn_product , tm_open_acct_bal , tm_acct_bal , tm_open_intransit , \
tm_intransit , tm_open_ar_bal , tm_ar_bal , tm_txn_date , tm_report_date , tm\
_cost_rate , tm_actual_cost , tm_remittance_slip_date , tm_converted_ccy , tm\
_converted_amount , tm_remit_rate , tm_remark , tm_prev_grp_txn_id , tm_next_\
grp_txn_id , tm_acr_prorata , tm_entity_ccy , tm_entity_txn_amount , tm_entit\
y_acct_name , tm_open_lien_bal , tm_lien_bal from txn_mi_detail where tm_txn_\
id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1071,0,6,339,0,0,31,31,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,
1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,
144,0,0,2,0,0,17,715,0,0,1,1,0,1,0,1,9,0,0,
163,0,0,2,0,0,21,716,0,0,0,0,0,1,0,
178,0,0,3,557,0,9,844,0,2049,1,1,0,1,0,1,9,0,0,
197,0,0,3,0,0,13,846,0,0,29,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,4,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,
0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
328,0,0,3,0,0,15,1080,0,0,0,0,0,1,0,
343,0,0,3,0,0,15,1091,0,0,0,0,0,1,0,
358,0,0,2,0,0,17,1139,0,0,1,1,0,1,0,1,9,0,0,
377,0,0,2,0,0,21,1140,0,0,0,0,0,1,0,
392,0,0,2,0,0,17,1201,0,0,1,1,0,1,0,1,9,0,0,
411,0,0,2,0,0,21,1202,0,0,0,0,0,1,0,
426,0,0,4,145,0,6,1265,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version 			                   2015/11/05              [WMC]
Add entity acct name				   2016/04/27		   [WCS]
Add UpdateRemark				   2016/08/02		   [WWK]
PRD309 RSP lien function enhancement		   2021/04/13		   [ANC]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "TxnMiDetail.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

static char    cDebug;

void TxnMiDetail(char    cdebug)
{
        cDebug = cdebug;
}


int Add(const hash_t* hRls)
{
	char            *csTmp;
        double          dTmp;
	int		iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;
	
	/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

       	/* varchar         hv_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_entity_id;

     	/* varchar         hv_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_party_type;

   	/* varchar         hv_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_party_id;

     	/* varchar         hv_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_ccy;

   	/* varchar         hv_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_country;

      	/* varchar         hv_txn_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_txn_product;

      	double          hv_open_acct_bal;
      	double          hv_acct_bal;
      	double          hv_open_intransit;
     	double          hv_intransit;
     	double          hv_open_ar_bal;
     	double          hv_ar_bal;
      	/* varchar         hv_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_txn_date;

      	/* varchar         hv_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_report_date;

      	double          hv_cost_rate;
      	double          hv_actual_cost;
     	/* varchar         hv_remittance_slip_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } hv_remittance_slip_date;

       	/* varchar         hv_converted_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_converted_ccy;

     	double          hv_converted_amount;
     	double          hv_remit_rate;
     	/* varchar         hv_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } hv_remark;

        /* varchar         hv_prev_grp_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_prev_grp_txn_id;

     	/* varchar         hv_next_grp_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_next_grp_txn_id;

    	int             hv_acr_prorata;	
     	/* varchar         hv_entity_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_entity_ccy;

	double		hv_entity_txn_amount;
	/* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

     	double          hv_open_lien_bal;
     	double          hv_lien_bal;

     	short           ind_txn_id = -1;
       	short           ind_entity_id = -1;
    	short           ind_party_type = -1;
      	short           ind_party_id = -1;
   	short           ind_txn_ccy = -1;
    	short           ind_txn_country = -1;
      	short           ind_txn_product = -1;
    	short           ind_open_acct_bal = -1;
     	short           ind_acct_bal = -1;
      	short           ind_open_intransit = -1;
     	short           ind_intransit = -1;
      	short           ind_open_ar_bal = -1;
     	short           ind_ar_bal = -1;
     	short           ind_txn_date = -1;
      	short           ind_report_date = -1;
      	short           ind_cost_rate = -1;
     	short           ind_actual_cost = -1;
     	short           ind_remittance_slip_date = -1;
     	short           ind_converted_ccy = -1;
     	short           ind_converted_amount = -1;
     	short           ind_remit_rate = -1;
      	short           ind_remark = -1;
      	short           ind_prev_grp_txn_id = -1;
       	short           ind_next_grp_txn_id = -1;
     	short           ind_acr_prorata = -1;
	short		ind_entity_ccy = -1;
	short		ind_entity_txn_amount = -1;
     	short           ind_add_user = -1;
      	short           ind_open_lien_bal = -1;
     	short           ind_lien_bal = -1;
	
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }	

/* entity_id */
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                memcpy(hv_entity_id.arr,csTmp,hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("Add:entity_id = [%.*s][%d]\n",hv_entity_id.len,hv_entity_id.arr,hv_entity_id.len));
        }

/* party_type */
        if (GetField_CString(hRls,"party_type",&csTmp)) {
                hv_party_type.len = strlen(csTmp);
                memcpy(hv_party_type.arr,csTmp,hv_party_type.len);
                ind_party_type = 0;
DEBUGLOG(("Add:party_type = [%.*s][%d]\n",hv_party_type.len,hv_party_type.arr,hv_party_type.len));
        }

/* party_id */
        if (GetField_CString(hRls,"party_id",&csTmp)) {
                hv_party_id.len = strlen(csTmp);
                memcpy(hv_party_id.arr,csTmp,hv_party_id.len);
                ind_party_id = 0;
DEBUGLOG(("Add:party_id = [%.*s][%d]\n",hv_party_id.len,hv_party_id.arr,hv_party_id.len));
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("Add:txn_ccy = [%.*s][%d]\n",hv_txn_ccy.len,hv_txn_ccy.arr,hv_txn_ccy.len));
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csTmp)) {
                hv_txn_country.len = strlen(csTmp);
                memcpy(hv_txn_country.arr,csTmp,hv_txn_country.len);
                ind_txn_country = 0;
DEBUGLOG(("Add:txn_country = [%.*s][%d]\n",hv_txn_country.len,hv_txn_country.arr,hv_txn_country.len));
        }

/* txn_product */
        if (GetField_CString(hRls,"txn_product",&csTmp)) {
                hv_txn_product.len = strlen(csTmp);
                memcpy(hv_txn_product.arr,csTmp,hv_txn_product.len);
                ind_txn_product = 0;
DEBUGLOG(("Add:txn_product = [%.*s][%d]\n",hv_txn_product.len,hv_txn_product.arr,hv_txn_product.len));
        }

/* open_acct_bal */
        if (GetField_Double(hRls,"open_acct_bal",&dTmp)) {
                hv_open_acct_bal= dTmp;
                ind_open_acct_bal = 0;
DEBUGLOG(("Add:open_acct_bal = [%f]\n",hv_open_acct_bal));
        }

/* acct_bal */
        if (GetField_Double(hRls,"acct_bal",&dTmp)) {
                hv_acct_bal= dTmp;
                ind_acct_bal = 0;
DEBUGLOG(("Add:acct_bal = [%f]\n",hv_acct_bal));
        }

/* open_intransit */
        if (GetField_Double(hRls,"open_intransit",&dTmp)) {
                hv_open_intransit= dTmp;
                ind_open_intransit = 0;
DEBUGLOG(("Add:open_intransit = [%f]\n",hv_open_intransit));
        }

/* intransit */
        if (GetField_Double(hRls,"intransit",&dTmp)) {
                hv_intransit= dTmp;
                ind_intransit = 0;
DEBUGLOG(("Add:intransit = [%f]\n",hv_intransit));
        }

/* open_ar_bal */
        if (GetField_Double(hRls,"open_ar_bal",&dTmp)) {
                hv_open_ar_bal= dTmp;
                ind_open_ar_bal = 0;
DEBUGLOG(("Add:open_ar_bal = [%f]\n",hv_open_ar_bal));
        }

/* ar_bal */
        if (GetField_Double(hRls,"ar_bal",&dTmp)) {
                hv_ar_bal= dTmp;
                ind_ar_bal = 0;
DEBUGLOG(("Add:ar_bal = [%f]\n",hv_ar_bal));
        }

/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
                ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s][%d]\n",hv_txn_date.len,hv_txn_date.arr,hv_txn_date.len));
        }

/* report_date */
        if (GetField_CString(hRls,"report_date",&csTmp)) {
                hv_report_date.len = strlen(csTmp);
                memcpy(hv_report_date.arr,csTmp,hv_report_date.len);
                ind_report_date = 0;
DEBUGLOG(("Add:report_date = [%.*s][%d]\n",hv_report_date.len,hv_report_date.arr,hv_report_date.len));
        }

/* cost_rate */
        if (GetField_Double(hRls,"cost_rate",&dTmp)) {
                hv_cost_rate= dTmp;
                ind_cost_rate = 0;
DEBUGLOG(("Add:cost_rate = [%f]\n",hv_cost_rate));
        }

/* actual_cost */
        if (GetField_Double(hRls,"actual_cost",&dTmp)) {
                hv_actual_cost= dTmp;
                ind_actual_cost = 0;
DEBUGLOG(("Add:actual_cost = [%f]\n",hv_actual_cost));
        }

/* remittance_slip_date */
        if (GetField_CString(hRls,"remittance_slip_date",&csTmp)) {
                hv_remittance_slip_date.len = strlen(csTmp);
                memcpy(hv_remittance_slip_date.arr,csTmp,hv_remittance_slip_date.len);
                ind_remittance_slip_date = 0;
DEBUGLOG(("Add:remittance_slip_date = [%.*s][%d]\n",hv_remittance_slip_date.len,hv_remittance_slip_date.arr,hv_remittance_slip_date.len));
        }

/* converted_ccy */
        if (GetField_CString(hRls,"converted_ccy",&csTmp)) {
                hv_converted_ccy.len = strlen(csTmp);
                memcpy(hv_converted_ccy.arr,csTmp,hv_converted_ccy.len);
                ind_converted_ccy = 0;
DEBUGLOG(("Add:converted_ccy = [%.*s][%d]\n",hv_converted_ccy.len,hv_converted_ccy.arr,hv_converted_ccy.len));
        }

/* converted_amount */
        if (GetField_Double(hRls,"converted_amount",&dTmp)) {
                hv_converted_amount= dTmp;
                ind_converted_amount = 0;
DEBUGLOG(("Add:converted_amount = [%f]\n",hv_converted_amount));
        }

/* remit_rate */
        if (GetField_Double(hRls,"remit_rate",&dTmp)) {
                hv_remit_rate= dTmp;
                ind_remit_rate = 0;
DEBUGLOG(("Add:remit_rate = [%f]\n",hv_remit_rate));
        }

/* remark */
        if (GetField_CString(hRls,"remark",&csTmp)) {
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr,csTmp,hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("Add:remark = [%.*s][%d]\n",hv_remark.len,hv_remark.arr,hv_remark.len));
        }

/* prev_grp_txn_id */
        if (GetField_CString(hRls,"prev_grp_txn_id",&csTmp)) {
                hv_prev_grp_txn_id.len = strlen(csTmp);
                memcpy(hv_prev_grp_txn_id.arr,csTmp,hv_prev_grp_txn_id.len);
                ind_prev_grp_txn_id = 0;
DEBUGLOG(("Add:prev_grp_txn_id = [%.*s][%d]\n",hv_prev_grp_txn_id.len,hv_prev_grp_txn_id.arr,hv_prev_grp_txn_id.len));
        }

/* next_grp_txn_id */
        if (GetField_CString(hRls,"next_grp_txn_id",&csTmp)) {
                hv_next_grp_txn_id.len = strlen(csTmp);
                memcpy(hv_next_grp_txn_id.arr,csTmp,hv_next_grp_txn_id.len);
                ind_next_grp_txn_id = 0;
DEBUGLOG(("Add:next_grp_txn_id = [%.*s][%d]\n",hv_next_grp_txn_id.len,hv_next_grp_txn_id.arr,hv_next_grp_txn_id.len));
        }

/* acr_prorata */
        if (GetField_Int(hRls,"acr_prorata",&iTmp)) {
                hv_acr_prorata= iTmp;
                ind_acr_prorata = 0;
DEBUGLOG(("Add:acr_prorata = [%d]\n",hv_acr_prorata));
        }

/* entity_ccy */
        if (GetField_CString(hRls,"entity_ccy",&csTmp)) {
                hv_entity_ccy.len = strlen(csTmp);
                memcpy(hv_entity_ccy.arr,csTmp,hv_entity_ccy.len);
                ind_entity_ccy = 0;
DEBUGLOG(("Add:entity_ccy = [%.*s][%d]\n",hv_entity_ccy.len,hv_entity_ccy.arr,hv_entity_ccy.len));
        }

/* entity_txn_amount */
        if (GetField_Double(hRls,"entity_txn_amount",&dTmp)) {
                hv_entity_txn_amount= dTmp;
                ind_entity_txn_amount = 0;
DEBUGLOG(("Add:entity_txn_amount = [%f]\n",hv_entity_txn_amount));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }
		
/* open_lien_bal */
        if (GetField_Double(hRls,"open_lien_bal",&dTmp)) {
                hv_open_lien_bal= dTmp;
                ind_open_lien_bal = 0;
DEBUGLOG(("Add:open_lien_bal = [%f]\n",hv_open_lien_bal));
        }

/* lien_bal */
        if (GetField_Double(hRls,"lien_bal",&dTmp)) {
                hv_lien_bal= dTmp;
                ind_lien_bal = 0;
DEBUGLOG(("Add:lien_bal = [%f]\n",hv_lien_bal));
        }

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_mi_detail_insert_new(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_entity_id:ind_entity_id,
                                        :hv_party_type:ind_party_type,
                                        :hv_party_id:ind_party_id,
                                        :hv_txn_ccy:ind_txn_ccy,
                                        :hv_txn_country:ind_txn_country,
                                        :hv_txn_product:ind_txn_product,
                                        :hv_open_acct_bal:ind_open_acct_bal,
                                        :hv_acct_bal:ind_acct_bal,
                                        :hv_open_intransit:ind_open_intransit,
                                        :hv_intransit:ind_intransit,
                                        :hv_open_ar_bal:ind_open_ar_bal,
                                        :hv_ar_bal:ind_ar_bal,
                                        :hv_txn_date:ind_txn_date,
                                        :hv_report_date:ind_report_date,
                                        :hv_cost_rate:ind_cost_rate,
                                        :hv_actual_cost:ind_actual_cost,
                                        :hv_remittance_slip_date:ind_remittance_slip_date,
                                        :hv_converted_ccy:ind_converted_ccy,
                                        :hv_converted_amount:ind_converted_amount,
                                        :hv_remit_rate:ind_remit_rate,
                                        :hv_remark:ind_remark,
                                        :hv_prev_grp_txn_id:ind_prev_grp_txn_id,
                                        :hv_next_grp_txn_id:ind_next_grp_txn_id,
                                        :hv_acr_prorata:ind_acr_prorata,
					:hv_entity_ccy:ind_entity_ccy,
					:hv_entity_txn_amount:ind_entity_txn_amount,
                                        :hv_add_user:ind_add_user,
                                        :hv_open_lien_bal:ind_open_lien_bal,
                                        :hv_lien_bal:ind_lien_bal);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_txn_mi_detail_insert_new ( :hv_txn_id:ind_t\
xn_id , :hv_entity_id:ind_entity_id , :hv_party_type:ind_party_type , :hv_pa\
rty_id:ind_party_id , :hv_txn_ccy:ind_txn_ccy , :hv_txn_country:ind_txn_coun\
try , :hv_txn_product:ind_txn_product , :hv_open_acct_bal:ind_open_acct_bal \
, :hv_acct_bal:ind_acct_bal , :hv_open_intransit:ind_open_intransit , :hv_in\
transit:ind_intransit , :hv_open_ar_bal:ind_open_ar_bal , :hv_ar_bal:ind_ar_\
bal , :hv_txn_date:ind_txn_date , :hv_report_date:ind_report_date , :hv_cost\
_rate:ind_cost_rate , :hv_actual_cost:ind_actual_cost , :hv_remittance_slip_\
date:ind_remittance_slip_date , :hv_converted_ccy:ind_converted_ccy , :hv_co\
nverted_amount:ind_converted_amount , :hv_remit_rate:ind_remit_rate , :hv_re\
mark:ind_remark , :hv_prev_grp_txn_id:ind_prev_grp_txn_id , :hv_next_grp_txn\
_id:ind_next_grp_txn_id , :hv_acr_prorata:ind_acr_prorata , :hv_entity_ccy:i\
nd_entity_ccy , :hv_entity_txn_amount:ind_entity_txn_amount , :hv_add_user:i\
nd_add_user , :hv_open_lien_bal:ind_open");
 sqlstm.stmt = "_lien_bal , :hv_lien_bal:ind_lien_bal ) ; END ;";
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_entity_id;
 sqlstm.sqhstl[2] = (unsigned long )23;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_entity_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_party_type;
 sqlstm.sqhstl[3] = (unsigned long )8;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_party_type;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_party_id;
 sqlstm.sqhstl[4] = (unsigned long )18;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_party_id;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[5] = (unsigned long )6;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_txn_country;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_txn_country;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_product;
 sqlstm.sqhstl[7] = (unsigned long )6;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_product;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_open_acct_bal;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_open_acct_bal;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_acct_bal;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_acct_bal;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_open_intransit;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_open_intransit;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_intransit;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_intransit;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_open_ar_bal;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_open_ar_bal;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_ar_bal;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_ar_bal;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_txn_date;
 sqlstm.sqhstl[14] = (unsigned long )11;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_txn_date;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_report_date;
 sqlstm.sqhstl[15] = (unsigned long )11;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_report_date;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_cost_rate;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_cost_rate;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_actual_cost;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_actual_cost;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_remittance_slip_date;
 sqlstm.sqhstl[18] = (unsigned long )11;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_remittance_slip_date;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_converted_ccy;
 sqlstm.sqhstl[19] = (unsigned long )6;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_converted_ccy;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_converted_amount;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_converted_amount;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_remit_rate;
 sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_remit_rate;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[22] = (unsigned long )258;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_remark;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_prev_grp_txn_id;
 sqlstm.sqhstl[23] = (unsigned long )19;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_prev_grp_txn_id;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_next_grp_txn_id;
 sqlstm.sqhstl[24] = (unsigned long )19;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_next_grp_txn_id;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_acr_prorata;
 sqlstm.sqhstl[25] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_acr_prorata;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_entity_ccy;
 sqlstm.sqhstl[26] = (unsigned long )6;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_entity_ccy;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_entity_txn_amount;
 sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_entity_txn_amount;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[28] = (unsigned long )22;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_add_user;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_open_lien_bal;
 sqlstm.sqhstl[29] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_open_lien_bal;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_lien_bal;
 sqlstm.sqhstl[30] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_lien_bal;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
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
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnMiDetail_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnMiDetail_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnMiDetail_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}	

int Update(const hash_t* hRls)
{
	char*   csTxnId;
	char*   csBuf;
	char*   csTmp;
        double  dTmp;
        int     iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update txn_mi_detail set tm_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));	
	
/* entity_id  */
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
DEBUGLOG(("Update:entity_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_entity_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* party_type */
        if (GetField_CString(hRls,"party_type",&csTmp)) {
DEBUGLOG(("Update:party_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_party_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* party_id */
        if (GetField_CString(hRls,"party_id",&csTmp)) {
DEBUGLOG(("Update:party_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_party_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
DEBUGLOG(("Update:txn_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_txn_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csTmp)) {
DEBUGLOG(("Update:txn_country = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_txn_country = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_product */
        if (GetField_CString(hRls,"txn_product",&csTmp)) {
DEBUGLOG(("Update:txn_product = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_txn_product = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_acct_bal */
        if (GetField_Double(hRls,"open_acct_bal",&dTmp)) {
DEBUGLOG(("Update:open_acct_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_open_acct_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* acct_bal */
        if (GetField_Double(hRls,"acct_bal",&dTmp)) {
DEBUGLOG(("Update:acct_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_acct_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_intransit */
        if (GetField_Double(hRls,"open_intransit",&dTmp)) {
DEBUGLOG(("Update:open_intransit = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_open_intransit = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* intransit */
        if (GetField_Double(hRls,"intransit",&dTmp)) {
DEBUGLOG(("Update:intransit = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_intransit = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_ar_bal */
        if (GetField_Double(hRls,"open_ar_bal",&dTmp)) {
DEBUGLOG(("Update:open_ar_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_open_ar_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ar_bal */
        if (GetField_Double(hRls,"ar_bal",&dTmp)) {
DEBUGLOG(("Update:ar_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_ar_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
DEBUGLOG(("Update:txn_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_txn_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* report_date*/
        if (GetField_CString(hRls,"report_date",&csTmp)) {
DEBUGLOG(("Update:report_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_report_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* cost_rate */
        if (GetField_Double(hRls,"cost_rate",&dTmp)) {
DEBUGLOG(("Update:cost_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_cost_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* actual_cost */
        if (GetField_Double(hRls,"actual_cost",&dTmp)) {
DEBUGLOG(("Update:actual_cost = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_actual_cost = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* remittance_slip_date */
        if (GetField_CString(hRls,"remittance_slip_date",&csTmp)) {
DEBUGLOG(("Update:remittance_slip_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_remittance_slip_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* converted_ccy */
        if (GetField_CString(hRls,"converted_ccy",&csTmp)) {
DEBUGLOG(("Update:converted_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_converted_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* converted_amount */
        if (GetField_Double(hRls,"converted_amount",&dTmp)) {
DEBUGLOG(("Update:converted_amount = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_converted_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* remit_rate */
        if (GetField_Double(hRls,"remit_rate",&dTmp)) {
DEBUGLOG(("Update:remit_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_remit_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* remark */
        if (GetField_CString(hRls,"remark",&csTmp)) {
DEBUGLOG(("Update:remark = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_remark = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* prev_grp_txn_id */
        if (GetField_CString(hRls,"prev_grp_txn_id",&csTmp)) {
DEBUGLOG(("Update:prev_grp_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_prev_grp_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* next_grp_txn_id */
        if (GetField_CString(hRls,"next_grp_txn_id",&csTmp)) {
DEBUGLOG(("Update:next_grp_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_next_grp_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* acr_prorata */
        if (GetField_Int(hRls,"acr_prorata",&iTmp)) {
DEBUGLOG(("Update:acr_prorata = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_acr_prorata = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_create_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* entity_ccy */
        if (GetField_CString(hRls,"entity_ccy",&csTmp)) {
DEBUGLOG(("Update:entity_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_entity_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* entity_amt */
        if (GetField_Double(hRls,"entity_txn_amount",&dTmp)) {
DEBUGLOG(("Update:entity_txn_amount = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_entity_txn_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* entity_acct_name */
	if (GetField_CString(hRls, "entity_acct_name", &csTmp)) {
DEBUGLOG(("Update:entity_acct_name = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ",tm_entity_acct_name = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
	
/* open_lien_bal */
        if (GetField_Double(hRls,"open_lien_bal",&dTmp)) {
DEBUGLOG(("Update:open_lien_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_open_lien_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* lien_bal */
        if (GetField_Double(hRls,"lien_bal",&dTmp)) {
DEBUGLOG(("Update:lien_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tm_lien_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE tm_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )144;
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
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )163;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnMiDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;	
}

int GetTxnMiDetail(const char* csTxnId, 
		recordset_t* myRec)
{
	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnmidetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar         v_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;
		
		/* varchar         v_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_party_type;
		
		/* varchar         v_party_id[PD_MMS_PARTY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_party_id;
		
		/* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;
		
		/* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;
		
		/* varchar         v_txn_product[PD_PRODUCT_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_product;
		
		double          v_open_acct_bal;
		double          v_acct_bal;
		double          v_open_intransit;
		double          v_intransit;
		double          v_open_ar_bal;
		double          v_ar_bal;
		/* varchar         v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar         v_report_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_report_date;
		
		double          v_cost_rate;
		double          v_actual_cost;
		/* varchar         v_remittance_slip_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_remittance_slip_date;

		/* varchar         v_converted_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_converted_ccy;

		double          v_converted_amount;
		double          v_remit_rate;
		/* varchar         v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar         v_prev_grp_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_prev_grp_txn_id;

		/* varchar         v_next_grp_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_next_grp_txn_id;

		int		v_acr_prorata;
		/* varchar		v_entity_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_entity_ccy;

		double		v_entity_txn_amount;
		/* varchar		v_entity_acct_name[PD_MMS_ENTITY_ACCT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_entity_acct_name;

		double          v_open_lien_bal;
		double          v_lien_bal;
		
		short		ind_entity_id = -1;
		short		ind_party_type = -1;
		short		ind_party_id = -1;
		short		ind_txn_ccy = -1;
		short		ind_txn_country = -1;
		short		ind_txn_product = -1;
		short		ind_open_acct_bal = -1;
		short		ind_acct_bal = -1;
		short		ind_open_intransit = -1;
		short		ind_intransit = -1;
		short		ind_open_ar_bal = -1;
		short		ind_ar_bal = -1;
		short		ind_txn_date = -1;
		short		ind_report_date = -1;
		short		ind_cost_rate = -1;
		short		ind_actual_cost = -1;
		short		ind_remittance_slip_date = -1;
		short		ind_converted_ccy = -1;
		short		ind_converted_amount = -1;
		short		ind_remit_rate = -1;
		short		ind_remark = -1;
		short		ind_prev_grp_txn_id = -1;
		short		ind_next_grp_txn_id = -1;
		short		ind_acr_prorata = -1;
		short		ind_entity_ccy = -1;
		short		ind_entity_txn_amount = -1;
		short		ind_entity_acct_name = -1;
		short		ind_open_lien_bal = -1;
		short		ind_lien_bal = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


// txn_id
        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetTxnMiDetail txn_id = [%d][%.*s]\n",hv_txn_id.len,hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxnmidetail CURSOR FOR
                select tm_entity_id,
		       tm_party_type,
		       tm_party_id,
		       tm_txn_ccy,
		       tm_txn_country,
		       tm_txn_product,
		       tm_open_acct_bal,
		       tm_acct_bal,
		       tm_open_intransit,
		       tm_intransit,
		       tm_open_ar_bal,
		       tm_ar_bal,
		       tm_txn_date,
		       tm_report_date,
		       tm_cost_rate,
		       tm_actual_cost,
		       tm_remittance_slip_date,
		       tm_converted_ccy,
		       tm_converted_amount,
		       tm_remit_rate,
		       tm_remark,
		       tm_prev_grp_txn_id,
		       tm_next_grp_txn_id,
		       tm_acr_prorata,
		       tm_entity_ccy,
		       tm_entity_txn_amount,
		       tm_entity_acct_name,
		       tm_open_lien_bal,
		       tm_lien_bal
                  from txn_mi_detail
                 where tm_txn_id = :hv_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_gettxnmidetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0003;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )178;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_txn_id;
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
        if (sqlca.sqlcode < 0) goto gettxnmidetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxnmidetail
                INTO
                        :v_entity_id:ind_entity_id,
			:v_party_type:ind_party_type,
			:v_party_id:ind_party_id,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_country:ind_txn_country,
			:v_txn_product:ind_txn_product,
			:v_open_acct_bal:ind_open_acct_bal,
			:v_acct_bal:ind_acct_bal,
			:v_open_intransit:ind_open_intransit,
			:v_intransit:ind_intransit,
			:v_open_ar_bal:ind_open_ar_bal,
			:v_ar_bal:ind_ar_bal,
			:v_txn_date:ind_txn_date,
			:v_report_date:ind_report_date,
			:v_cost_rate:ind_cost_rate,
			:v_actual_cost:ind_actual_cost,
			:v_remittance_slip_date:ind_remittance_slip_date,	
			:v_converted_ccy:ind_converted_ccy,
			:v_converted_amount:ind_converted_amount,
			:v_remit_rate:ind_remit_rate,
			:v_remark:ind_remark,
			:v_prev_grp_txn_id:ind_prev_grp_txn_id,
			:v_next_grp_txn_id:ind_next_grp_txn_id,
			:v_acr_prorata:ind_acr_prorata,
			:v_entity_ccy:ind_entity_ccy,
			:v_entity_txn_amount:ind_entity_txn_amount,
			:v_entity_acct_name:ind_entity_acct_name,
			:v_open_lien_bal:ind_open_lien_bal,
			:v_lien_bal:ind_lien_bal; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )197;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_entity_id;
                sqlstm.sqhstl[0] = (unsigned long )23;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_entity_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_party_type;
                sqlstm.sqhstl[1] = (unsigned long )8;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_party_type;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_party_id;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_party_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_country;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_product;
                sqlstm.sqhstl[5] = (unsigned long )6;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_product;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_open_acct_bal;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_open_acct_bal;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_acct_bal;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_acct_bal;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_open_intransit;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_open_intransit;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_intransit;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_intransit;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_open_ar_bal;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_open_ar_bal;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_ar_bal;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_ar_bal;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_date;
                sqlstm.sqhstl[12] = (unsigned long )11;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_txn_date;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_report_date;
                sqlstm.sqhstl[13] = (unsigned long )11;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_report_date;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_cost_rate;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_cost_rate;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_actual_cost;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_actual_cost;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_remittance_slip_date;
                sqlstm.sqhstl[16] = (unsigned long )11;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_remittance_slip_date;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_converted_ccy;
                sqlstm.sqhstl[17] = (unsigned long )6;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_converted_ccy;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_converted_amount;
                sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_converted_amount;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_remit_rate;
                sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_remit_rate;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_remark;
                sqlstm.sqhstl[20] = (unsigned long )258;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_remark;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_prev_grp_txn_id;
                sqlstm.sqhstl[21] = (unsigned long )19;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_prev_grp_txn_id;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_next_grp_txn_id;
                sqlstm.sqhstl[22] = (unsigned long )19;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_next_grp_txn_id;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_acr_prorata;
                sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_acr_prorata;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_entity_ccy;
                sqlstm.sqhstl[24] = (unsigned long )6;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_entity_ccy;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_entity_txn_amount;
                sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_entity_txn_amount;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_entity_acct_name;
                sqlstm.sqhstl[26] = (unsigned long )53;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_entity_acct_name;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_open_lien_bal;
                sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_open_lien_bal;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_lien_bal;
                sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_lien_bal;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gettxnmidetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

DEBUGLOG(("GetTxnMiDetail found record\n"));

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash, 0);

/* entity_id */
                if (ind_entity_id >= 0) {
                        v_entity_id.arr[v_entity_id.len] = '\0';
                        PutField_CString(myHash,"entity_id",(const char*)v_entity_id.arr);
DEBUGLOG(("GetTxnMiDetail entity_id = [%s]\n",v_entity_id.arr));
                }

/* party_type */
                if (ind_party_type >= 0) {
                        v_party_type.arr[v_party_type.len] = '\0';
                        PutField_CString(myHash,"party_type",(const char*)v_party_type.arr);
DEBUGLOG(("GetTxnMiDetail party_type = [%s]\n",v_party_type.arr));
                }

/* party_id */
                if (ind_party_id >= 0) {
                        v_party_id.arr[v_party_id.len] = '\0';
                        PutField_CString(myHash,"party_id",(const char*)v_party_id.arr);
DEBUGLOG(("GetTxnMiDetail party_id = [%s]\n",v_party_id.arr));
                }

/* txn_ccy */
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetTxnMiDetail txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

/* txn_country */
                if (ind_txn_country >= 0) {
                        v_txn_country.arr[v_txn_country.len] = '\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetTxnMiDetail txn_country = [%s]\n",v_txn_country.arr));
                }

/* txn_product */
                if (ind_txn_product >= 0) {
                        v_txn_product.arr[v_txn_product.len] = '\0';
                        PutField_CString(myHash,"txn_product",(const char*)v_txn_product.arr);
DEBUGLOG(("GetTxnMiDetail txn_product = [%s]\n",v_txn_product.arr));
                }

/* open_acct_bal */
                if(ind_open_acct_bal>=0){
                        PutField_Double(myHash,"open_acct_bal",v_open_acct_bal);
DEBUGLOG(("GetTxnMiDetail open_acct_bal = [%f]\n",v_open_acct_bal));
                }

/* acct_bal */
                if(ind_acct_bal>=0){
                        PutField_Double(myHash,"acct_bal",v_acct_bal);
DEBUGLOG(("GetTxnMiDetail acct_bal = [%f]\n",v_acct_bal));
                }

/* open_intransit */
                if(ind_open_intransit>=0){
                        PutField_Double(myHash,"open_intransit",v_open_intransit);
DEBUGLOG(("GetTxnMiDetail open_intransit = [%f]\n",v_open_intransit));
                }

/* intransit */
                if(ind_intransit>=0){
                        PutField_Double(myHash,"intransit",v_intransit);
DEBUGLOG(("GetTxnMiDetail intransit = [%f]\n",v_intransit));
                }

/* open_ar_bal */
                if(ind_open_ar_bal>=0){
                        PutField_Double(myHash,"open_ar_bal",v_open_ar_bal);
DEBUGLOG(("GetTxnMiDetail open_ar_bal = [%f]\n",v_open_ar_bal));
                }

/* ar_bal */
                if(ind_ar_bal>=0){
                        PutField_Double(myHash,"ar_bal",v_ar_bal);
DEBUGLOG(("GetTxnMiDetail ar_bal = [%f]\n",v_ar_bal));
                }

/* txn_date */
                if (ind_txn_date >= 0) {
                        v_txn_date.arr[v_txn_date.len] = '\0';
                        PutField_CString(myHash,"txn_date",(const char*)v_txn_date.arr);
DEBUGLOG(("GetTxnMiDetail txn_date = [%s]\n",v_txn_date.arr));
                }

/* report_date */
                if (ind_report_date >= 0) {
                        v_report_date.arr[v_report_date.len] = '\0';
                        PutField_CString(myHash,"report_date",(const char*)v_report_date.arr);
DEBUGLOG(("GetTxnMiDetail report_date = [%s]\n",v_report_date.arr));
                }

/* cost_rate */
                if(ind_cost_rate>=0){
                        PutField_Double(myHash,"cost_rate",v_cost_rate);
DEBUGLOG(("GetTxnMiDetail cost_rate = [%f]\n",v_cost_rate));
                }

/* actual_cost */
                if(ind_actual_cost>=0){
                        PutField_Double(myHash,"actual_cost",v_actual_cost);
DEBUGLOG(("GetTxnMiDetail actual_cost = [%f]\n",v_actual_cost));
                }

/* remittance_slip_date */
                if (ind_remittance_slip_date >= 0) {
                        v_remittance_slip_date.arr[v_remittance_slip_date.len] = '\0';
                        PutField_CString(myHash,"remittance_slip_date",(const char*)v_remittance_slip_date.arr);
DEBUGLOG(("GetTxnMiDetail remittance_slip_date = [%s]\n",v_remittance_slip_date.arr));
                }

/* converted_ccy */
                if (ind_converted_ccy >= 0) {
                        v_converted_ccy.arr[v_converted_ccy.len] = '\0';
                        PutField_CString(myHash,"converted_ccy",(const char*)v_converted_ccy.arr);
DEBUGLOG(("GetTxnMiDetail converted_ccy = [%s]\n",v_converted_ccy.arr));
                }

/* converted_amount */
                if(ind_converted_amount>=0){
                        PutField_Double(myHash,"converted_amount",v_converted_amount);
DEBUGLOG(("GetTxnMiDetail converted_amount = [%f]\n",v_converted_amount));
                }

/* remit_rate */
                if(ind_remit_rate>=0){
                        PutField_Double(myHash,"remit_rate",v_remit_rate);
DEBUGLOG(("GetTxnMiDetail remit_rate = [%f]\n",v_remit_rate));
                }

/* remark */
                if (ind_remark >= 0) {
                        v_remark.arr[v_remark.len] = '\0';
                        PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetTxnMiDetail remark = [%s]\n",v_remark.arr));
                }

/* prev_grp_txn_id */
                if (ind_prev_grp_txn_id >= 0) {
                        v_prev_grp_txn_id.arr[v_prev_grp_txn_id.len] = '\0';
                        PutField_CString(myHash,"prev_grp_txn_id",(const char*)v_prev_grp_txn_id.arr);
DEBUGLOG(("GetTxnMiDetail prev_grp_txn_id = [%s]\n",v_prev_grp_txn_id.arr));
                }

/* next_grp_txn_id */
                if (ind_next_grp_txn_id >= 0) {
                        v_next_grp_txn_id.arr[v_next_grp_txn_id.len] = '\0';
                        PutField_CString(myHash,"next_grp_txn_id",(const char*)v_next_grp_txn_id.arr);
DEBUGLOG(("GetTxnMiDetail next_grp_txn_id = [%s]\n",v_next_grp_txn_id.arr));
                }

/* acr_prorata */
                if(ind_acr_prorata>=0){
                        PutField_Int(myHash,"acr_prorata",v_acr_prorata);
DEBUGLOG(("GetTxnMiDetail acr_prorata = [%d]\n",v_acr_prorata));
                }

/* entity_ccy */
                if (ind_entity_ccy >= 0) {
                        v_entity_ccy.arr[v_entity_ccy.len] = '\0';
                        PutField_CString(myHash,"entity_ccy",(const char*)v_entity_ccy.arr);
DEBUGLOG(("GetTxnMiDetail entity_ccy = [%s]\n",v_entity_ccy.arr));
                }

/* entity_txn_amount */
                if(ind_entity_txn_amount>=0){
                        PutField_Double(myHash,"entity_txn_amount",v_entity_txn_amount);
DEBUGLOG(("GetTxnMiDetail entity_txn_amount = [%f]\n",v_entity_txn_amount));
                }

/* entity_acct_name */
		if (ind_entity_acct_name >= 0) {
			v_entity_acct_name.arr[v_entity_acct_name.len] = '\0';
			PutField_CString(myHash, "entity_acct_name", (const char*)v_entity_acct_name.arr);
DEBUGLOG(("GetTxnMiDetail entity_acct_name = [%s]\n", v_entity_acct_name.arr));
		}
		
/* open_lien_bal */
                if(ind_open_lien_bal>=0){
                        PutField_Double(myHash,"open_lien_bal",v_open_lien_bal);
DEBUGLOG(("GetTxnMiDetail open_lien_bal = [%f]\n",v_open_lien_bal));
                }

/* lien_bal */
                if(ind_lien_bal>=0){
                        PutField_Double(myHash,"lien_bal",v_lien_bal);
DEBUGLOG(("GetTxnMiDetail lien_bal = [%f]\n",v_lien_bal));
                }

		RecordSet_Add(myRec, myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxnmidetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )328;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnmidetail_error;
}




DEBUGLOG(("GetTxnMiDetail Normal Exit\n"));
        return  PD_OK;

gettxnmidetail_error:
DEBUGLOG(("gettxnmidetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnMiDetail_Get: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxnmidetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )343;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int UpdatePrevGrpTxnId2NULL(const hash_t* hRls)
{
	char*   csTxnId;
	char*   csBuf;
	char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updateprevnull_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdatePrevGrpTxnId2NULL: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update txn_mi_detail set tm_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdatePrevGrpTxnId2NULL:txn_id = [%s]\n",csTxnId));	
	
/* prev_grp_txn_id */
DEBUGLOG(("UpdatePrevGrpTxnId2NULL:prev_grp_txn_id = [%s]\n",csTxnId));
        strcat((char*)hv_dynstmt.arr, ",tm_prev_grp_txn_id = NULL");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdatePrevGrpTxnId2NULL:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE tm_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )358;
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
        if (sqlca.sqlcode < 0) goto updateprevnull_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )377;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updateprevnull_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdatePrevGrpTxnId2NULL Normal Exit\n"));
        return PD_OK;

updateprevnull_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnMiDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;	
}


int UpdateNextGrpTxnId2NULL(const hash_t* hRls)
{
	char*   csTxnId;
	char*   csBuf;
	char*   csTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO updatenextnull_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateNextGrpTxnId2NULL: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update txn_mi_detail set tm_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateNextGrpTxnId2NULL:txn_id = [%s]\n",csTxnId));	
	
/* next_grp_txn_id */
DEBUGLOG(("UpdateNextGrpTxnId2NULL:next_grp_txn_id = [%s]\n",csTxnId));
        strcat((char*)hv_dynstmt.arr, ",tm_next_grp_txn_id = NULL");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateNextGrpTxnId2NULL:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tm_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE tm_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )392;
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
        if (sqlca.sqlcode < 0) goto updatenextnull_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )411;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto updatenextnull_error;
}



        FREE_ME(csBuf);

DEBUGLOG(("UpdateNextGrpTxnId2NULL Normal Exit\n"));
        return PD_OK;

updatenextnull_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnMiDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;	
}


int UpdateRemark(hash_t* hRls)
{
	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO updateremark_err; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar	hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

		/* varchar	hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;


		short	ind_txn_id = -1;
		short	ind_remark = -1;
		short	ind_update_user = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateRemark: Begin\n"));

//txn_id
	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("UpdateRemark txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

//remark
	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char*)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("UpdateRemark remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
	}

//update_user
	if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateRemark update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_txn_mi_detail_upd_remark(
								:hv_txn_id:ind_txn_id,
								:hv_remark:ind_remark,
								:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_mi_detail_upd_remark ( :hv\
_txn_id:ind_txn_id , :hv_remark:ind_remark , :hv_update_user:ind_update_user \
) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )426;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[2] = (unsigned long )257;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_remark;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_update_user;
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
 if (sqlca.sqlcode < 0) goto updateremark_err;
}



DEBUGLOG(("UpdateRemark Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateRemark Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("UpdateRemark: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_OTHER_ERR TxnAbort\n"));	
                return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateRemark: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updateremark_err:
DEBUGLOG(("updateremark_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateRemark: SP_ERR TxnAbort\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}
