
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
           char  filnam[18];
};
static struct sqlcxp sqlfpn =
{
    17,
    "MmsTransaction.pc"
};


static unsigned int sqlctx = 10243995;


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
   unsigned char  *sqhstv[35];
   unsigned long  sqhstl[35];
            int   sqhsts[35];
            short *sqindv[35];
            int   sqinds[35];
   unsigned long  sqharm[35];
   unsigned long  *sqharc[35];
   unsigned short  sqadto[35];
   unsigned short  sqtdso[35];
} sqlstm = {12,35};

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

 static char *sq0005 = 
"select mth_org_txn_id , mth_service_code , mth_mmc_node_id , mth_client_ref\
 , mth_status , mth_ar_ind , mth_internal_code , mth_response_code , mth_txn_\
code , mth_process_type , mth_process_code , mth_host_posting_date , mth_tm_d\
ate , mth_tm_time , mth_local_tm_date , mth_local_tm_time , mth_transmission_\
datetime , mth_transaction_amount , mth_transaction_ccy from mms_txn_header w\
here mth_txn_id = :b0            ";

 static char *sq0006 = 
"select mtd_org_dtl_txn_id , mtd_init_channel , mtd_txn_code , mtd_isd_ind ,\
 mtd_merchant_id , mtd_psp_id , mtd_mb_id , mtd_bank_id , mtd_stl_bank_id , m\
td_party_node_id , mtd_service_code , mtd_src_party_type , mtd_dst_party_type\
 , mtd_carry_forward_ind , mtd_dc_type , mtd_status , mtd_transmission_dateti\
me , mtd_txn_amt , mtd_txn_ccy , mtd_adjustment , mtd_exchange_rate , mtd_pro\
cessing_cost , mtd_bank_charge , mtd_bank_charge_refund , mtd_filing_number ,\
 mtd_country , mtd_version_no , mtd_encrypt_type , mtd_internal_code , mtd_re\
sponse_code , mtd_prev_dtl_txn_id from mms_txn_detail where mtd_txn_id = :b0 \
and mtd_dtl_txn_id = :b1            ";

 static char *sq0009 = 
"select mtd_dtl_txn_id , mtd_org_dtl_txn_id , mtd_init_channel , mtd_txn_cod\
e , mtd_isd_ind , mtd_merchant_id , mtd_psp_id , mtd_mb_id , mtd_bank_id , mt\
d_stl_bank_id , mtd_party_node_id , mtd_service_code , mtd_src_party_type , m\
td_dst_party_type , mtd_carry_forward_ind , mtd_dc_type , mtd_status , mtd_tr\
ansmission_datetime , mtd_txn_amt , mtd_txn_ccy , mtd_adjustment , mtd_exchan\
ge_rate , mtd_processing_cost , mtd_bank_charge , mtd_bank_charge_refund , mt\
d_filing_number , mtd_country , mtd_version_no , mtd_encrypt_type , mtd_inter\
nal_code , mtd_response_code , mtd_prev_dtl_txn_id from mms_txn_detail where \
mtd_txn_id = :b0 and mtd_prev_dtl_txn_id = :b1 order by mtd_dtl_txn_id desc  \
          ";

 static char *sq0012 = 
"select mtd_dtl_txn_id , mtd_org_dtl_txn_id , mtd_init_channel , mtd_txn_cod\
e , mtd_isd_ind , mtd_merchant_id , mtd_psp_id , mtd_mb_id , mtd_bank_id , mt\
d_stl_bank_id , mtd_party_node_id , mtd_service_code , mtd_src_party_type , m\
td_dst_party_type , mtd_carry_forward_ind , mtd_dc_type , mtd_status , mtd_tr\
ansmission_datetime , mtd_txn_amt , mtd_txn_ccy , mtd_adjustment , mtd_exchan\
ge_rate , mtd_processing_cost , mtd_bank_charge , mtd_bank_charge_refund , mt\
d_filing_number , mtd_country , mtd_version_no , mtd_encrypt_type , mtd_inter\
nal_code , mtd_response_code , mtd_prev_dtl_txn_id from mms_txn_detail where \
mtd_txn_id = :b0 and mtd_batch_id = :b1 and mtd_dtl_txn_id < :b2 order by mtd\
_dtl_txn_id desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,740,0,6,247,0,0,20,20,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
100,0,0,2,0,0,17,437,0,0,1,1,0,1,0,1,9,0,0,
119,0,0,2,0,0,21,438,0,0,0,0,0,1,0,
134,0,0,3,1241,0,6,806,0,0,35,35,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,
0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,2,
9,0,0,
289,0,0,2,0,0,17,1213,0,0,1,1,0,1,0,1,9,0,0,
308,0,0,2,0,0,21,1214,0,0,0,0,0,1,0,
323,0,0,4,117,0,4,1253,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
346,0,0,5,416,0,9,1362,0,2049,1,1,0,1,0,1,9,0,0,
365,0,0,5,0,0,13,1364,0,0,19,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
1,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
456,0,0,5,0,0,15,1530,0,0,0,0,0,1,0,
471,0,0,5,0,0,15,1546,0,0,0,0,0,1,0,
486,0,0,6,650,0,9,1677,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
509,0,0,6,0,0,13,1679,0,0,31,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,
2,1,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
648,0,0,6,0,0,15,1941,0,0,0,0,0,1,0,
663,0,0,6,0,0,15,1957,0,0,0,0,0,1,0,
678,0,0,7,184,0,4,1993,0,0,5,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,9,0,0,1,9,0,0,
713,0,0,8,132,0,4,2052,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
744,0,0,9,701,0,9,2216,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
767,0,0,9,0,0,13,2218,0,0,32,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
2,9,0,0,2,1,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
910,0,0,9,0,0,15,2488,0,0,0,0,0,1,0,
925,0,0,9,0,0,15,2504,0,0,0,0,0,1,0,
940,0,0,0,0,0,56,2589,0,0,1,1,0,1,0,3,102,0,0,
959,0,0,10,136,0,6,2591,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,2,102,0,0,
990,0,0,0,0,0,13,2627,0,0,20,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,1,0,0,2,1,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
1085,0,0,0,0,0,15,2767,0,0,1,1,0,1,0,1,102,0,0,
1104,0,0,0,0,0,15,2772,0,0,1,1,0,1,0,1,102,0,0,
1123,0,0,0,0,0,15,2777,0,0,1,1,0,1,0,1,102,0,0,
1142,0,0,0,0,0,15,2781,0,0,1,1,0,1,0,1,102,0,0,
1161,0,0,0,0,0,15,2790,0,0,1,1,0,1,0,1,102,0,0,
1180,0,0,11,99,0,4,2812,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
1203,0,0,12,719,0,9,2971,0,2049,3,3,0,1,0,1,9,0,0,1,3,0,0,1,9,0,0,
1230,0,0,12,0,0,13,2973,0,0,32,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,
0,2,9,0,0,2,1,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,
1373,0,0,12,0,0,15,3235,0,0,0,0,0,1,0,
1388,0,0,12,0,0,15,3251,0,0,0,0,0,1,0,
1403,0,0,13,95,0,4,3275,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2011. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2011/10/19              Virginia Yun
Add AddDetail					   2011/11/17		   Cody Chan
Add GetMaxDetailSeq                                2011/11/28		   Virginia Yun
Add GetMmsTxnHeader, GetMmsTxnDetail               2011/11/29              Virginia Yun
Add GetMmsTxnDetailByPrevId                        2012/01/04              Virginia Yun
Add GetMmsTxnHeaderRec				   2012/02/15              Virginia Yun
Add CheckPendingTxnByTxnId			   2012/03/16		   Virginia Yun
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "MmsTransaction.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char    cDebug;

void MmsTransaction(char    cdebug)
{
        cDebug = cdebug;
}

int AddHeader(const hash_t *hRls)
{
        char        	*csTmp;
        char           	cTmp;
	double		dTmp = 0.0;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short   	hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        
        /* varchar         hv_org_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_txn_id;
        
	/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

	/* varchar		hv_mmc_node_id[PD_MMS_NODE_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_mmc_node_id;

	/* varchar		hv_client_ref[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_client_ref;

        char            hv_status;
        char            hv_ar_ind;
        /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

        /* varchar         hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

        /* varchar         hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

 	/* varchar         hv_host_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_posting_date;

	/* varchar        	hv_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_tm_date;

        /* varchar        	hv_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_tm_time;

        /* varchar        	hv_local_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_local_tm_date;

        /* varchar        	hv_local_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_local_tm_time;
	
	/* varchar         hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

	double          hv_transaction_amount;
	/* varchar		hv_transaction_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_transaction_ccy;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



        short           ind_txn_id = -1;
        short           ind_org_txn_id = -1;
	short		ind_service_code = -1;
	short		ind_mmc_node_id = -1;
	short		ind_client_ref = -1;
        short           ind_status = -1;
        short           ind_ar_ind = -1;
        short           ind_txn_code = -1;
        short           ind_process_type = -1;
        short           ind_process_code = -1;
 	short	        ind_host_posting_date = -1;
	short        	ind_tm_date = -1;
        short        	ind_tm_time = -1;
        short        	ind_local_tm_date = -1;
        short        	ind_local_tm_time = -1;
	short           ind_transmission_datetime = -1;
	short         	ind_transaction_amount = -1;
	short		ind_transaction_ccy = -1;
        short           ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddHeader: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddHeader:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
                hv_org_txn_id.len = strlen(csTmp);
                memcpy(hv_org_txn_id.arr,csTmp,hv_org_txn_id.len);
                ind_org_txn_id = 0;
DEBUGLOG(("AddHeader:org_txn_id = [%.*s]\n",hv_org_txn_id.len,hv_org_txn_id.arr));
        }


/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr,csTmp,hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("AddHeader:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

/* mmc_node_id */
        if (GetField_CString(hRls,"mmc_node_id",&csTmp)) {
                hv_mmc_node_id.len = strlen(csTmp);
                memcpy(hv_mmc_node_id.arr,csTmp,hv_mmc_node_id.len);
                ind_mmc_node_id = 0;
DEBUGLOG(("AddHeader:mmc_node_id = [%.*s]\n",hv_mmc_node_id.len,hv_mmc_node_id.arr));
        }

/* client_ref */
        if (GetField_CString(hRls,"client_ref",&csTmp)) {
                hv_client_ref.len = strlen(csTmp);
                memcpy(hv_client_ref.arr,csTmp,hv_client_ref.len);
                ind_client_ref = 0;
DEBUGLOG(("AddHeader:client_ref = [%.*s]\n",hv_client_ref.len,hv_client_ref.arr));
        }

/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddHeader:status = [%c]\n",hv_status));
        }

/* ar ind */ 
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
                hv_ar_ind = cTmp;
                ind_ar_ind = 0;
DEBUGLOG(("AddHeader:ar_ind = [%c]\n",hv_ar_ind));
        }

/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("AddHeader:txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
                hv_process_type.len = strlen(csTmp);
                memcpy(hv_process_type.arr,csTmp,hv_process_type.len);
                ind_process_type = 0;
DEBUGLOG(("AddHeader:process_type = [%.*s]\n",hv_process_type.len,hv_process_type.arr));
        }

/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
                hv_process_code.len = strlen(csTmp);
                memcpy(hv_process_code.arr,csTmp,hv_process_code.len);
                ind_process_code = 0;
DEBUGLOG(("AddHeader:process_code = [%.*s]\n",hv_process_code.len,hv_process_code.arr));
        }

/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
                hv_host_posting_date.len = strlen(csTmp);
                memcpy(hv_host_posting_date.arr,csTmp,hv_host_posting_date.len);
                ind_host_posting_date = 0;
DEBUGLOG(("AddHeader:host_posting_date = [%.*s]\n",hv_host_posting_date.len,hv_host_posting_date.arr));
        }

/* tm date */
        if (GetField_CString(hRls,"tm_date",&csTmp)) {
                hv_tm_date.len = strlen(csTmp);
                memcpy(hv_tm_date.arr,csTmp,hv_tm_date.len);
                ind_tm_date = 0;
DEBUGLOG(("AddHeader:tm_date = [%.*s]\n",hv_tm_date.len,hv_tm_date.arr));
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
                hv_tm_time.len = strlen(csTmp);
                memcpy(hv_tm_time.arr,csTmp,hv_tm_time.len);
                ind_tm_time = 0;
DEBUGLOG(("AddHeader:tm_time = [%.*s]\n",hv_tm_time.len,hv_tm_time.arr));
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
                hv_local_tm_date.len = strlen(csTmp);
                memcpy(hv_local_tm_date.arr,csTmp,hv_local_tm_date.len);
                ind_local_tm_date = 0;
DEBUGLOG(("AddHeader:local_tm_date = [%.*s]\n",hv_local_tm_date.len,hv_local_tm_date.arr));
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
                hv_local_tm_time.len = strlen(csTmp);
                memcpy(hv_local_tm_time.arr,csTmp,hv_local_tm_time.len);
                ind_local_tm_time = 0;
DEBUGLOG(("AddHeader:local_tm_time = [%.*s]\n",hv_local_tm_time.len,hv_local_tm_time.arr));
        }



/* transmission_datetime */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
                hv_transmission_datetime.len = strlen(csTmp);
                memcpy(hv_transmission_datetime.arr,csTmp,hv_transmission_datetime.len);
                ind_transmission_datetime = 0;
DEBUGLOG(("AddHeader:transmission_datetime = [%.*s]\n",hv_transmission_datetime.len,hv_transmission_datetime.arr));
        }


/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_transaction_amount = dTmp;
                ind_transaction_amount = 0;
DEBUGLOG(("AddHeader:txn_amt = [%f]\n",hv_transaction_amount));
        }
/* transaction ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_transaction_ccy.len = strlen(csTmp);
                memcpy(hv_transaction_ccy.arr,csTmp,hv_transaction_ccy.len);
                ind_transaction_ccy = 0;
DEBUGLOG(("AddHeader:transaction_ccy = [%.*s]\n",hv_transaction_ccy.len,hv_transaction_ccy.arr));
        }
/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddHeader:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_txn_header_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_org_txn_id:ind_org_txn_id,
						:hv_service_code:ind_service_code,
						:hv_mmc_node_id:ind_mmc_node_id,
						:hv_client_ref:ind_client_ref,
                                                :hv_status:ind_status,
                                                :hv_ar_ind:ind_ar_ind,
                                                :hv_txn_code:ind_txn_code,
                                                :hv_process_type:ind_process_type,
                                                :hv_process_code:ind_process_code,
                                                :hv_host_posting_date:ind_host_posting_date,
                                                :hv_tm_date:ind_tm_date,
                                                :hv_tm_time:ind_tm_time,
                                                :hv_local_tm_date:ind_local_tm_date,
                                                :hv_local_tm_time:ind_local_tm_time,
                                                :hv_transmission_datetime:ind_transmission_datetime,
                                                :hv_transaction_amount:ind_transaction_amount,
                                                :hv_transaction_ccy:ind_transaction_ccy,
                                                :hv_add_user:ind_add_user,
                                                :hv_add_user:ind_add_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mms_txn_header_insert (\
 :hv_txn_id:ind_txn_id , :hv_org_txn_id:ind_org_txn_id , :hv_service_code:ind\
_service_code , :hv_mmc_node_id:ind_mmc_node_id , :hv_client_ref:ind_client_r\
ef , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_txn_code:ind_txn_cod\
e , :hv_process_type:ind_process_type , :hv_process_code:ind_process_code , :\
hv_host_posting_date:ind_host_posting_date , :hv_tm_date:ind_tm_date , :hv_tm\
_time:ind_tm_time , :hv_local_tm_date:ind_local_tm_date , :hv_local_tm_time:i\
nd_local_tm_time , :hv_transmission_datetime:ind_transmission_datetime , :hv_\
transaction_amount:ind_transaction_amount , :hv_transaction_ccy:ind_transacti\
on_ccy , :hv_add_user:ind_add_user , :hv_add_user:ind_add_user ) ; END ;";
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_org_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_org_txn_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_service_code;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_mmc_node_id;
        sqlstm.sqhstl[4] = (unsigned long )7;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_mmc_node_id;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_client_ref;
        sqlstm.sqhstl[5] = (unsigned long )18;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_client_ref;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_status;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_ar_ind;
        sqlstm.sqhstl[7] = (unsigned long )1;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_ar_ind;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[8] = (unsigned long )5;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_txn_code;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_process_type;
        sqlstm.sqhstl[9] = (unsigned long )6;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_process_type;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_process_code;
        sqlstm.sqhstl[10] = (unsigned long )8;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_process_code;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_host_posting_date;
        sqlstm.sqhstl[11] = (unsigned long )10;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_host_posting_date;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_tm_date;
        sqlstm.sqhstl[12] = (unsigned long )10;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_tm_date;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_tm_time;
        sqlstm.sqhstl[13] = (unsigned long )8;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_tm_time;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_local_tm_date;
        sqlstm.sqhstl[14] = (unsigned long )10;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_local_tm_date;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_local_tm_time;
        sqlstm.sqhstl[15] = (unsigned long )8;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_local_tm_time;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_transmission_datetime;
        sqlstm.sqhstl[16] = (unsigned long )16;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_transmission_datetime;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_transaction_amount;
        sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_transaction_amount;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_transaction_ccy;
        sqlstm.sqhstl[18] = (unsigned long )5;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_transaction_ccy;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[19] = (unsigned long )22;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_add_user;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto add_header_error;
}



DEBUGLOG(("AddHeader:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("AddHeader:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsTransaction_AddHeader: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsTransaction_AddHeader: SP_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_header_error:
DEBUGLOG(("add_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsTransaction_AddHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateHeader(const hash_t *hRls)
{

        char*   csTmp;
        char    cTmp;
        double  dTmp;
        int     iTmp;
        char*   csBuf;
        char*   csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_header_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateHeader: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update mms_txn_header set mth_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateHeader:txn_id = [%s]\n",csTxnId));

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateHeader:org_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_org_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* client txn_seq */
        if (GetField_CString(hRls,"client_ref",&csTmp)) {
DEBUGLOG(("UpdateHeader:client_ref = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_client_ref = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_code */
        if (GetField_CString(hRls,"sub_txn_code",&csTmp)) {
DEBUGLOG(("UpdateHeader:sub_txn_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_txn_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process_code */
        if (GetField_CString(hRls,"sub_process_code",&csTmp)) {
DEBUGLOG(("UpdateHeader:sub_process_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_process_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process_type */
        if (GetField_CString(hRls,"sub_process_type",&csTmp)) {
DEBUGLOG(("UpdateHeader:sub_process_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_process_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Status */
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("UpdateHeader:status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ar ind */
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
DEBUGLOG(("UpdateHeader:ar_ind = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_ar_ind = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("UpdateHeader:internal_code = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_internal_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("UpdateHeader:response_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_response_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateHeader:txn_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_transaction_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateHeader:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char *)hv_dynstmt.arr, " WHERE mth_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )100;
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
        if (sqlca.sqlcode < 0) goto update_header_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 20;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )119;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_header_error;
}



        FREE_ME(csBuf);


DEBUGLOG(("UpdateHeader Normal Exit\n"));
        return PD_OK;

update_header_error:
DEBUGLOG(("update_header_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("Transaction_UpdateHeader: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateHeader: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int AddDetail(hash_t *hRls)
{
        char        	*csTmp;
	char		cTmp;
	double		dTmp;
	int		iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short   	hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        
	/* varchar         hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;

	/* varchar         hv_org_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_org_dtl_txn_id;

	/* varchar		hv_init_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_init_channel;

        /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	char            hv_isd_ind;
        /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;
        
        /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;
        
        /* varchar         hv_mb_id[PD_MB_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_mb_id;
        
        /* varchar         hv_bank_id[PD_BANK_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_bank_id;
        
        /* varchar         hv_stl_bank_id[PD_BANK_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_stl_bank_id;
        
	/* varchar	        hv_party_node_id[PD_MMS_NODE_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_party_node_id;

	/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

	/* varchar		hv_src_party_type[PD_MMS_PARTY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_src_party_type;

	/* varchar		hv_dst_party_type[PD_MMS_PARTY_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_dst_party_type;

	int		hv_carry_forward_ind;
	/* varchar		hv_dc_type[PD_MMS_DC_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_dc_type;

        char            hv_status;
	/* varchar         hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

        double          hv_txn_amt;
	/* varchar         hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

        double          hv_adjustment;
        double          hv_exchange_rate;
        double          hv_processing_cost;
        double          hv_bank_charge;
        double          hv_bank_charge_refund;
        /* varchar         hv_filing_number[PD_MMS_FILING_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_filing_number;

        /* varchar         hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;
        
        /* varchar         hv_version_no[PD_VERSION_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_version_no;
        
	/* varchar		hv_encrypt_type[PD_ENCRYPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_encrypt_type;

	/* varchar		hv_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_prev_dtl_txn_id;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	int		hv_batch_id;


        short           ind_txn_id = -1;
        short		ind_dtl_txn_id = -1;
	short		ind_org_dtl_txn_id = -1;
        short		ind_init_channel = -1;
        short		ind_txn_code = -1;
	short		ind_isd_ind = -1;
	short		ind_merchant_id = -1;
	short		ind_psp_id = -1;
	short		ind_mb_id = -1;
	short		ind_bank_id = -1;
	short		ind_stl_bank_id = -1;
	short	        ind_party_node_id = -1;
	short		ind_service_code = -1;
	short		ind_src_party_type = -1;
	short		ind_dst_party_type = -1;
	short		ind_carry_forward_ind = -1;
	short		ind_dc_type = -1;
        short           ind_status = -1;
	short           ind_transmission_datetime = -1;
        short           ind_txn_amt = -1;
	short           ind_txn_ccy = -1;
        short           ind_adjustment = -1;
        short           ind_exchange_rate = -1;
        short           ind_processing_cost = -1;
        short           ind_bank_charge = -1;
        short           ind_bank_charge_refund = -1;
        short           ind_filing_number = -1;
	short		ind_txn_country = -1;
	short		ind_version_no = -1;
	short		ind_encrypt_type = -1;
	short		ind_prev_dtl_txn_id = -1;
        short           ind_add_user = -1;
	short		ind_batch_id = -1;

	/* varchar		v_rtn_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_rtn_dtl_txn_id;

	short		ind_rtn_dtl_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddDetail:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }

/* dtl_txn_seq */
        if (GetField_CString(hRls,"dtl_txn_seq",&csTmp)) {
                hv_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_dtl_txn_id.arr,csTmp,hv_dtl_txn_id.len);
                ind_dtl_txn_id = 0;
DEBUGLOG(("AddDetail:dtl_txn_id = [%.*s][%d]\n",hv_dtl_txn_id.len,hv_dtl_txn_id.arr,hv_dtl_txn_id.len));
        }

/* org_dtl_txn_seq */
        if (GetField_CString(hRls,"org_dtl_txn_seq",&csTmp)) {
                hv_org_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_org_dtl_txn_id.arr,csTmp,hv_org_dtl_txn_id.len);
                ind_org_dtl_txn_id = 0;
DEBUGLOG(("AddDetail:org_dtl_txn_id = [%.*s][%d]\n",hv_org_dtl_txn_id.len,hv_org_dtl_txn_id.arr,hv_org_dtl_txn_id.len));

        }

/* init_channel */
        if (GetField_CString(hRls,"init_channel",&csTmp)) {
                hv_init_channel.len = strlen(csTmp);
                memcpy(hv_init_channel.arr,csTmp,hv_init_channel.len);
                ind_init_channel= 0;
DEBUGLOG(("AddDetail:init_channel = [%.*s][%d]\n",hv_init_channel.len,hv_init_channel.arr,hv_init_channel.len));
        }



/* txn_code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("AddDetail:txn_code = [%.*s][%d]\n",hv_txn_code.len,hv_txn_code.arr,hv_txn_code.len));
        }

/* isd_ind */
	if (GetField_Char(hRls, "isd_ind", &cTmp)) {
		hv_isd_ind = cTmp;
		ind_isd_ind = 0;
DEBUGLOG(("AddDetail:isd_ind = [%c]\n",hv_isd_ind));
	}

/* merchant_id */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("AddDetail:merchant_id = [%.*s][%d]\n",hv_merchant_id.len,hv_merchant_id.arr,hv_merchant_id.len));
        }

/* psp_id */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("AddDetail:psp_id = [%.*s][%d]\n",hv_psp_id.len,hv_psp_id.arr,hv_psp_id.len));
        }

/* mb_id */
        if (GetField_CString(hRls,"mb_id",&csTmp)) {
                hv_mb_id.len = strlen(csTmp);
                memcpy(hv_mb_id.arr,csTmp,hv_mb_id.len);
                ind_mb_id = 0;
DEBUGLOG(("AddDetail:mb_id = [%.*s][%d]\n",hv_mb_id.len,hv_mb_id.arr,hv_mb_id.len));
        }

/* bank_id */
        if (GetField_CString(hRls,"bank_id",&csTmp)) {
                hv_bank_id.len = strlen(csTmp);
                memcpy(hv_bank_id.arr,csTmp,hv_bank_id.len);
                ind_bank_id = 0;
DEBUGLOG(("AddDetail:bank_id = [%.*s][%d]\n",hv_bank_id.len,hv_bank_id.arr,hv_bank_id.len));
        }

/* stl_bank_id */
        if (GetField_CString(hRls,"stl_bank_id",&csTmp)) {
                hv_stl_bank_id.len = strlen(csTmp);
                memcpy(hv_stl_bank_id.arr,csTmp,hv_stl_bank_id.len);
                ind_stl_bank_id = 0;
DEBUGLOG(("AddDetail:stl_bank_id = [%.*s][%d]\n",hv_stl_bank_id.len,hv_stl_bank_id.arr,hv_stl_bank_id.len));
        }

/* party_node_id */
        if (GetField_CString(hRls,"party_node_id",&csTmp)) {
                hv_party_node_id.len = strlen(csTmp);
                memcpy(hv_party_node_id.arr,csTmp,hv_party_node_id.len);
                ind_party_node_id = 0;
DEBUGLOG(("AddDetail:party_node_id = [%.*s][%d]\n",hv_party_node_id.len,hv_party_node_id.arr,hv_party_node_id.len));
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr,csTmp,hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("AddDetail:service_code = [%.*s][%d]\n",hv_service_code.len,hv_service_code.arr,hv_service_code.len));
        }

/* src_party_type */
        if (GetField_CString(hRls,"src_party_type",&csTmp)) {
                hv_src_party_type.len = strlen(csTmp);
                memcpy(hv_src_party_type.arr,csTmp,hv_src_party_type.len);
                ind_src_party_type = 0;
DEBUGLOG(("AddDetail:src_party_type = [%.*s][%d]\n",hv_src_party_type.len,hv_src_party_type.arr,hv_src_party_type.len));
        }

/* dst_party_type */
        if (GetField_CString(hRls,"dst_party_type",&csTmp)) {
                hv_dst_party_type.len = strlen(csTmp);
                memcpy(hv_dst_party_type.arr,csTmp,hv_dst_party_type.len);
                ind_dst_party_type = 0;
DEBUGLOG(("AddDetail:dst_party_type = [%.*s][%d]\n",hv_dst_party_type.len,hv_dst_party_type.arr,hv_dst_party_type.len));
        }

/* carry_forward_ind */
	if (GetField_Int(hRls, "carry_forward_ind", &iTmp)) {
		hv_carry_forward_ind = iTmp;
		ind_carry_forward_ind = 0;
DEBUGLOG(("AddDetail:carry_forward_ind = [%d]\n",hv_carry_forward_ind));
	}

/* dc_type */
        if (GetField_CString(hRls,"dc_type",&csTmp)) {
                hv_dc_type.len = strlen(csTmp);
                memcpy(hv_dc_type.arr,csTmp,hv_dc_type.len);
                ind_dc_type = 0;
DEBUGLOG(("AddDetail:dc_type = [%.*s][%d]\n",hv_dc_type.len,hv_dc_type.arr, hv_dc_type.len));
        }

/* status */
        if (GetField_Char(hRls,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddDetail:status = [%c]\n",hv_status));
        }



/* transmission_datetime */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
                hv_transmission_datetime.len = strlen(csTmp);
                memcpy(hv_transmission_datetime.arr,csTmp,hv_transmission_datetime.len);
                ind_transmission_datetime = 0;
DEBUGLOG(("AddDetail:transmission_datetime = [%.*s]\n",hv_transmission_datetime.len,hv_transmission_datetime.arr));
        }

/* txn_amt */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_txn_amt = dTmp;
                ind_txn_amt = 0;
DEBUGLOG(("AddDetail:txn_amt = [%lf]\n",hv_txn_amt));
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("AddDetail:txn_ccy = [%.*s][%d]\n",hv_txn_ccy.len,hv_txn_ccy.arr,hv_txn_ccy.len));
        }

/* adjustment */
        if (GetField_Double(hRls,"adjustment",&dTmp)) {
                hv_adjustment= dTmp;
                ind_adjustment= 0;
DEBUGLOG(("AddDetail:adjustment = [%lf]\n", hv_adjustment));
        }

/* exchange_rate */
        if (GetField_Double(hRls,"exchange_rate",&dTmp)) {
                hv_exchange_rate= dTmp;
                ind_exchange_rate= 0;
DEBUGLOG(("AddDetail:exchange_rate = [%lf]\n",hv_exchange_rate));
        }

/* processing_cost */
        if (GetField_Double(hRls,"processing_cost",&dTmp)) {
                hv_processing_cost= dTmp;
                ind_processing_cost= 0;
DEBUGLOG(("AddDetail:processing_cost = [%lf]\n",hv_processing_cost));
        }

/* bank_charge */
        if (GetField_Double(hRls,"bank_charge",&dTmp)) {
                hv_bank_charge= dTmp;
                ind_bank_charge= 0;
DEBUGLOG(("AddDetail:bank_charge = [%lf]\n",hv_bank_charge));
        }

/* bank_charge_refund */
        if (GetField_Double(hRls,"bank_charge_refund",&dTmp)) {
                hv_bank_charge_refund= dTmp;
                ind_bank_charge_refund= 0;
DEBUGLOG(("AddDetail:bank_charge_refund = [%lf]\n",hv_bank_charge_refund));
        }

/* filing_number */
        if (GetField_CString(hRls,"filing_number",&csTmp)) {
                hv_filing_number.len = strlen(csTmp);
                memcpy(hv_filing_number.arr,csTmp,hv_filing_number.len);
                ind_filing_number = 0;
DEBUGLOG(("AddDetail:filing_number = [%.*s][%d]\n",hv_filing_number.len,hv_filing_number.arr,hv_filing_number.len));
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csTmp)) {
                hv_txn_country.len = strlen(csTmp);
                memcpy(hv_txn_country.arr,csTmp,hv_txn_country.len);
                ind_txn_country = 0;
DEBUGLOG(("AddDetail:txn_country = [%.*s][%d]\n",hv_txn_country.len,hv_txn_country.arr,hv_txn_country.len));
        }
/* version_no */
        if (GetField_CString(hRls,"version_no",&csTmp)) {
                hv_version_no.len = strlen(csTmp);
                memcpy(hv_version_no.arr,csTmp,hv_version_no.len);
                ind_version_no = 0;
DEBUGLOG(("AddDetail:version_no = [%.*s][%d]\n",hv_version_no.len,hv_version_no.arr,hv_version_no.len));
        }

/* encrypt_type */
        if (GetField_CString(hRls,"encrypt_type",&csTmp)) {
                hv_encrypt_type.len = strlen(csTmp);
                memcpy(hv_encrypt_type.arr,csTmp,hv_encrypt_type.len);
                ind_encrypt_type = 0;
DEBUGLOG(("AddDetail:encrypt_type = [%.*s][%d]\n",hv_encrypt_type.len,hv_encrypt_type.arr,hv_encrypt_type.len));
        }


/* prev_dtl_txn_seq */
        if (GetField_CString(hRls,"prev_dtl_txn_seq",&csTmp)) {
                hv_prev_dtl_txn_id.len = strlen(csTmp);
                memcpy(hv_prev_dtl_txn_id.arr,csTmp,hv_prev_dtl_txn_id.len);
                ind_prev_dtl_txn_id = 0;
DEBUGLOG(("AddDetail:prev_dtl_txn_id = [%.*s][%d]\n",hv_prev_dtl_txn_id.len,hv_prev_dtl_txn_id.arr,hv_prev_dtl_txn_id.len));
        }

/* batch_id */
	if (GetField_Int(hRls, "batch_id", &iTmp)) {
		hv_batch_id = iTmp;
		ind_batch_id = 0;
DEBUGLOG(("AddDetail:batch_id = [%d]\n",hv_batch_id));
	}

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddDetail:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_txn_detail_insert(
                                                :hv_txn_id:ind_txn_id,
                                                :hv_dtl_txn_id:ind_dtl_txn_id,
						:hv_org_dtl_txn_id:ind_org_dtl_txn_id,
                                                :hv_init_channel:ind_init_channel,
                                                :hv_txn_code:ind_txn_code,
						:hv_isd_ind:ind_isd_ind,
						:hv_merchant_id:ind_merchant_id,
						:hv_psp_id:ind_psp_id,
						:hv_mb_id:ind_mb_id,
						:hv_bank_id:ind_bank_id,
						:hv_stl_bank_id:ind_stl_bank_id,
						:hv_party_node_id:ind_party_node_id,
						:hv_service_code:ind_service_code,
						:hv_src_party_type:ind_src_party_type,
						:hv_dst_party_type:ind_dst_party_type,
						:hv_carry_forward_ind:ind_carry_forward_ind,
						:hv_dc_type:ind_dc_type,
						:hv_status:ind_status,
                                                :hv_transmission_datetime:ind_transmission_datetime,
						:hv_txn_amt:ind_txn_amt,
                                                :hv_txn_ccy:ind_txn_ccy,
                                                :hv_adjustment:ind_adjustment,
                                                :hv_exchange_rate:ind_exchange_rate,
                                                :hv_processing_cost:ind_processing_cost,
                                                :hv_bank_charge:ind_bank_charge,
                                                :hv_bank_charge_refund:ind_bank_charge_refund,
                                                :hv_filing_number:ind_filing_number,
						:hv_txn_country:ind_txn_country,
						:hv_version_no:ind_version_no,
						:hv_encrypt_type:ind_encrypt_type,
						:hv_prev_dtl_txn_id:ind_prev_dtl_txn_id,
						:hv_batch_id:ind_batch_id,
                                                :hv_add_user:ind_add_user,
                                                :hv_add_user:ind_add_user,
						:v_rtn_dtl_txn_id:ind_rtn_dtl_txn_id);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "begin :hv_return_value := sp_mms_txn_detail_insert ( :hv_txn_id:i\
nd_txn_id , :hv_dtl_txn_id:ind_dtl_txn_id , :hv_org_dtl_txn_id:ind_org_dtl_t\
xn_id , :hv_init_channel:ind_init_channel , :hv_txn_code:ind_txn_code , :hv_\
isd_ind:ind_isd_ind , :hv_merchant_id:ind_merchant_id , :hv_psp_id:ind_psp_i\
d , :hv_mb_id:ind_mb_id , :hv_bank_id:ind_bank_id , :hv_stl_bank_id:ind_stl_\
bank_id , :hv_party_node_id:ind_party_node_id , :hv_service_code:ind_service\
_code , :hv_src_party_type:ind_src_party_type , :hv_dst_party_type:ind_dst_p\
arty_type , :hv_carry_forward_ind:ind_carry_forward_ind , :hv_dc_type:ind_dc\
_type , :hv_status:ind_status , :hv_transmission_datetime:ind_transmission_d\
atetime , :hv_txn_amt:ind_txn_amt , :hv_txn_ccy:ind_txn_ccy , :hv_adjustment\
:ind_adjustment , :hv_exchange_rate:ind_exchange_rate , :hv_processing_cost:\
ind_processing_cost , :hv_bank_charge:ind_bank_charge , :hv_bank_charge_refu\
nd:ind_bank_charge_refund , :hv_filing_number:ind_filing_number , :hv_txn_co\
untry:ind_txn_country , :hv_version_no:ind_vers");
        sqlstm.stmt = "ion_no , :hv_encrypt_type:ind_encrypt_type , :hv_pre\
v_dtl_txn_id:ind_prev_dtl_txn_id , :hv_batch_id:ind_batch_id , :hv_add_user:i\
nd_add_user , :hv_add_user:ind_add_user , :v_rtn_dtl_txn_id:ind_rtn_dtl_txn_i\
d ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )134;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_dtl_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )40;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_dtl_txn_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_org_dtl_txn_id;
        sqlstm.sqhstl[3] = (unsigned long )40;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_org_dtl_txn_id;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_init_channel;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_init_channel;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_code;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_isd_ind;
        sqlstm.sqhstl[6] = (unsigned long )1;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_isd_ind;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[7] = (unsigned long )17;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_merchant_id;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_psp_id;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_mb_id;
        sqlstm.sqhstl[9] = (unsigned long )17;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_mb_id;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_bank_id;
        sqlstm.sqhstl[10] = (unsigned long )17;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_bank_id;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_stl_bank_id;
        sqlstm.sqhstl[11] = (unsigned long )17;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_stl_bank_id;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_party_node_id;
        sqlstm.sqhstl[12] = (unsigned long )7;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_party_node_id;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_service_code;
        sqlstm.sqhstl[13] = (unsigned long )5;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_service_code;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_src_party_type;
        sqlstm.sqhstl[14] = (unsigned long )7;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_src_party_type;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_dst_party_type;
        sqlstm.sqhstl[15] = (unsigned long )7;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_dst_party_type;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_carry_forward_ind;
        sqlstm.sqhstl[16] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_carry_forward_ind;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_dc_type;
        sqlstm.sqhstl[17] = (unsigned long )4;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_dc_type;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[18] = (unsigned long )1;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_status;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_transmission_datetime;
        sqlstm.sqhstl[19] = (unsigned long )16;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_transmission_datetime;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_txn_amt;
        sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_txn_amt;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[21] = (unsigned long )5;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[21] = (         int  )0;
        sqlstm.sqharm[21] = (unsigned long )0;
        sqlstm.sqadto[21] = (unsigned short )0;
        sqlstm.sqtdso[21] = (unsigned short )0;
        sqlstm.sqhstv[22] = (unsigned char  *)&hv_adjustment;
        sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[22] = (         int  )0;
        sqlstm.sqindv[22] = (         short *)&ind_adjustment;
        sqlstm.sqinds[22] = (         int  )0;
        sqlstm.sqharm[22] = (unsigned long )0;
        sqlstm.sqadto[22] = (unsigned short )0;
        sqlstm.sqtdso[22] = (unsigned short )0;
        sqlstm.sqhstv[23] = (unsigned char  *)&hv_exchange_rate;
        sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[23] = (         int  )0;
        sqlstm.sqindv[23] = (         short *)&ind_exchange_rate;
        sqlstm.sqinds[23] = (         int  )0;
        sqlstm.sqharm[23] = (unsigned long )0;
        sqlstm.sqadto[23] = (unsigned short )0;
        sqlstm.sqtdso[23] = (unsigned short )0;
        sqlstm.sqhstv[24] = (unsigned char  *)&hv_processing_cost;
        sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[24] = (         int  )0;
        sqlstm.sqindv[24] = (         short *)&ind_processing_cost;
        sqlstm.sqinds[24] = (         int  )0;
        sqlstm.sqharm[24] = (unsigned long )0;
        sqlstm.sqadto[24] = (unsigned short )0;
        sqlstm.sqtdso[24] = (unsigned short )0;
        sqlstm.sqhstv[25] = (unsigned char  *)&hv_bank_charge;
        sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[25] = (         int  )0;
        sqlstm.sqindv[25] = (         short *)&ind_bank_charge;
        sqlstm.sqinds[25] = (         int  )0;
        sqlstm.sqharm[25] = (unsigned long )0;
        sqlstm.sqadto[25] = (unsigned short )0;
        sqlstm.sqtdso[25] = (unsigned short )0;
        sqlstm.sqhstv[26] = (unsigned char  *)&hv_bank_charge_refund;
        sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[26] = (         int  )0;
        sqlstm.sqindv[26] = (         short *)&ind_bank_charge_refund;
        sqlstm.sqinds[26] = (         int  )0;
        sqlstm.sqharm[26] = (unsigned long )0;
        sqlstm.sqadto[26] = (unsigned short )0;
        sqlstm.sqtdso[26] = (unsigned short )0;
        sqlstm.sqhstv[27] = (unsigned char  *)&hv_filing_number;
        sqlstm.sqhstl[27] = (unsigned long )52;
        sqlstm.sqhsts[27] = (         int  )0;
        sqlstm.sqindv[27] = (         short *)&ind_filing_number;
        sqlstm.sqinds[27] = (         int  )0;
        sqlstm.sqharm[27] = (unsigned long )0;
        sqlstm.sqadto[27] = (unsigned short )0;
        sqlstm.sqtdso[27] = (unsigned short )0;
        sqlstm.sqhstv[28] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[28] = (unsigned long )4;
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         short *)&ind_txn_country;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned long )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (unsigned char  *)&hv_version_no;
        sqlstm.sqhstl[29] = (unsigned long )4;
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         short *)&ind_version_no;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned long )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (unsigned char  *)&hv_encrypt_type;
        sqlstm.sqhstl[30] = (unsigned long )6;
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         short *)&ind_encrypt_type;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned long )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (unsigned char  *)&hv_prev_dtl_txn_id;
        sqlstm.sqhstl[31] = (unsigned long )40;
        sqlstm.sqhsts[31] = (         int  )0;
        sqlstm.sqindv[31] = (         short *)&ind_prev_dtl_txn_id;
        sqlstm.sqinds[31] = (         int  )0;
        sqlstm.sqharm[31] = (unsigned long )0;
        sqlstm.sqadto[31] = (unsigned short )0;
        sqlstm.sqtdso[31] = (unsigned short )0;
        sqlstm.sqhstv[32] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[32] = (         int  )0;
        sqlstm.sqindv[32] = (         short *)&ind_batch_id;
        sqlstm.sqinds[32] = (         int  )0;
        sqlstm.sqharm[32] = (unsigned long )0;
        sqlstm.sqadto[32] = (unsigned short )0;
        sqlstm.sqtdso[32] = (unsigned short )0;
        sqlstm.sqhstv[33] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[33] = (unsigned long )22;
        sqlstm.sqhsts[33] = (         int  )0;
        sqlstm.sqindv[33] = (         short *)&ind_add_user;
        sqlstm.sqinds[33] = (         int  )0;
        sqlstm.sqharm[33] = (unsigned long )0;
        sqlstm.sqadto[33] = (unsigned short )0;
        sqlstm.sqtdso[33] = (unsigned short )0;
        sqlstm.sqhstv[34] = (unsigned char  *)&v_rtn_dtl_txn_id;
        sqlstm.sqhstl[34] = (unsigned long )41;
        sqlstm.sqhsts[34] = (         int  )0;
        sqlstm.sqindv[34] = (         short *)&ind_rtn_dtl_txn_id;
        sqlstm.sqinds[34] = (         int  )0;
        sqlstm.sqharm[34] = (unsigned long )0;
        sqlstm.sqadto[34] = (unsigned short )0;
        sqlstm.sqtdso[34] = (unsigned short )0;
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
        if (sqlca.sqlcode < 0) goto add_detail_error;
}



DEBUGLOG(("AddDetail:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
		if (ind_rtn_dtl_txn_id >= 0) {

			v_rtn_dtl_txn_id.arr[v_rtn_dtl_txn_id.len] = '\0'; 
                        PutField_CString(hRls, "dtl_txn_seq", (const char *)v_rtn_dtl_txn_id.arr);
DEBUGLOG(("AddDetail dtl_txn_id (return) = [%s]\n",v_rtn_dtl_txn_id.arr));
		}

DEBUGLOG(("AddDetail:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsTransaction_AddDetail: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsTransaction_AddDetail: SP_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

add_detail_error:
DEBUGLOG(("add_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsTransaction_AddDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddDetail: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int UpdateDetail(const hash_t *hRls)
{

        char*   csTmp;
        char    cTmp;
        double  dTmp;
	int	iTmp;
        char*   csBuf;
        char*   csTxnId;
        char*   csDtlTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_dt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDetail: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update mms_txn_detail set mtd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateDetail:txn_id = [%s]\n",csTxnId));

        GetField_CString(hRls,"dtl_txn_seq",&csDtlTxnId);
DEBUGLOG(("UpdateDetail:dtl_txn_id = [%s]\n",csDtlTxnId));

/* org_dtl_txn_id */
	if (GetField_CString(hRls, "org_dtl_txn_seq", &csTmp)) {
DEBUGLOG(("UpdateDetail:org_dtl_txn_seq = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_org_dtl_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_code */
        if (GetField_CString(hRls,"sub_txn_code",&csTmp)) {
DEBUGLOG(("UpdateDetail:txn_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_txn_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* isd ind */
        if (GetField_Char(hRls,"isd_ind",&cTmp)) {
DEBUGLOG(("UpdateDetail:isd_ind = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_isd_ind = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* merchant_id */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:merchant_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_merchant_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* psp_id */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:psp_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_psp_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* mb_id */
        if (GetField_CString(hRls,"mb_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:mb_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_mb_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank_id */
        if (GetField_CString(hRls,"bank_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:bank_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_bank_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* stl_bank_id */
        if (GetField_CString(hRls,"stl_bank_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:stl_bank_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_stl_bank_id= '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* party_node_id */
        if (GetField_CString(hRls,"party_node_id",&csTmp)) {
DEBUGLOG(("UpdateDetail:party_node_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_party_node_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
DEBUGLOG(("UpdateDetail:service_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_service_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* src_party_type */
        if (GetField_CString(hRls,"src_party_type",&csTmp)) {
DEBUGLOG(("UpdateDetail:src_party_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_src_party_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* dst_party_type */
        if (GetField_CString(hRls,"dst_party_type",&csTmp)) {
DEBUGLOG(("UpdateDetail:dst_party_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_dst_party_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* carry_forward_ind */
        if (GetField_Int(hRls,"carry_forward_ind",&iTmp)) {
DEBUGLOG(("UpdateDetail:carry_forward_ind = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_carry_forward_ind = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* dc_type */
        if (GetField_CString(hRls,"dc_type",&csTmp)) {
DEBUGLOG(("UpdateDetail:dc_ind = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_dc_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* Status */
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("UpdateDetail:status = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("UpdateDetail:txn_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_txn_amt = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
DEBUGLOG(("UpdateDetail:txn_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_txn_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* adjustment */
        if (GetField_Double(hRls,"adjustment",&dTmp)) {
DEBUGLOG(("UpdateDetail:adjustment = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_adjustment = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* exchange_rate */
        if (GetField_Double(hRls,"exchange_rate",&dTmp)) {
DEBUGLOG(("UpdateDetail:exchange_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_exchange_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* processing_cost */
        if (GetField_Double(hRls,"processing_cost",&dTmp)) {
DEBUGLOG(("UpdateDetail:processing_cost = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_processing_cost = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank_charge */
        if (GetField_Double(hRls,"bank_charge",&dTmp)) {
DEBUGLOG(("UpdateDetail:bank_charge = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_bank_charge = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank_charge_refund */
        if (GetField_Double(hRls,"bank_charge_refund",&dTmp)) {
DEBUGLOG(("UpdateDetail:bank_charge_refund = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_bank_charge_refund = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* filing_number */
        if (GetField_CString(hRls,"filing_number",&csTmp)) {
DEBUGLOG(("UpdateDetail:filing_number = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_filing_number = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csTmp)) {
DEBUGLOG(("UpdateDetail:txn_country = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_country = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* version_no */
        if (GetField_CString(hRls,"version_no",&csTmp)) {
DEBUGLOG(("UpdateDetail:version_no = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_version_no = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* encrypt_type */
        if (GetField_CString(hRls,"encrypt_type",&csTmp)) {
DEBUGLOG(("UpdateDetail:encrypt_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_encrypt_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("UpdateDetail:internal_code = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_internal_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("UpdateDetail:response_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_response_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* prev_dtl_txn_id */
        if (GetField_CString(hRls,"prev_dtl_txn_seq",&csTmp)) {
DEBUGLOG(("UpdateDetail:prev_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_prev_dtl_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* batch_id */
        if (GetField_Int(hRls,"batch_id",&iTmp)) {
DEBUGLOG(("UpdateDetail:batch_id = [%d]\n",iTmp));
		sprintf(csBuf, "%d", iTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_batch_id = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mtd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


        strcat((char *)hv_dynstmt.arr, " WHERE mtd_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
	strcat((char *)hv_dynstmt.arr, " AND mtd_dtl_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csDtlTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )289;
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
        if (sqlca.sqlcode < 0) goto update_dt_error;
}


        /* EXEC SQL EXECUTE PS; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )308;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_dt_error;
}



        FREE_ME(csBuf);


DEBUGLOG(("UpdateDetail Normal Exit\n"));
        return PD_OK;

update_dt_error:
DEBUGLOG(("update_dt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("Transaction_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetMaxDetailSeq(const char *csTxnSeq,
                    char *csDtlTxnSeq)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO getmaxdetailseq_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
        

		/* varchar		v_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_dtl_txn_id;

                short           ind_dtl_txn_id = -1;


	/* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen((const char *)csTxnSeq);
        memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);

DEBUGLOG(("GetMaxDetailSeq: TxnSeq [%s]\n", csTxnSeq));

        /* EXEC SQL SELECT max(mtd_dtl_txn_id)
                  INTO :v_dtl_txn_id:ind_dtl_txn_id
                FROM mms_txn_detail 
                WHERE mtd_txn_id = :hv_txn_id
		  AND mtd_status in ('W', 'A'); */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select max ( mtd_dtl_txn_id ) INTO :b0:b1 FROM mms_t\
xn_detail WHERE mtd_txn_id = :b2 AND mtd_status in ( 'W' , 'A' ) ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )323;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_dtl_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )41;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_dtl_txn_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
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
        if (sqlca.sqlcode < 0) goto getmaxdetailseq_error;
}




	if (ind_dtl_txn_id >= 0) {
                v_dtl_txn_id.arr[v_dtl_txn_id.len] = '\0';
                strcpy((char*)csDtlTxnSeq,(const char*)v_dtl_txn_id.arr);
DEBUGLOG(("GetMaxDetailSeq: Max Dtl Seq  = [%s]\n",csDtlTxnSeq));
                return FOUND;
        }

DEBUGLOG(("GetMaxDetailSeq: Max Dtl Seq  NOT FOUND"));

	return NOT_FOUND;

getmaxdetailseq_error:
DEBUGLOG(("getmaxdetailseq_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetMmsTxnHeader(const char *csTxnID,
		    recordset_t *myRec)
{

	int	iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_org_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_org_txn_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_mmc_node_id[PD_MMS_NODE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_mmc_node_id;

		/* varchar		v_client_ref[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_client_ref;

		char		v_status;
		char		v_ar_ind;
		long		v_internal_code;
                /* varchar         v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

		/* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

        	/* varchar         v_process_type[PD_PROCESS_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

		/* varchar         v_process_code[PD_PROCESS_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;

        	/* varchar         v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar         v_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_tm_date;

		/* varchar         v_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_tm_time;

		/* varchar         v_local_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

		/* varchar         v_local_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_local_tm_time;

		/* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

		double          v_transaction_amount;
		/* varchar         v_transaction_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_transaction_ccy;


		short		ind_org_txn_id = -1;
		short		ind_service_code = -1;
		short		ind_mmc_node_id = -1;
		short		ind_client_ref = -1;
		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_internal_code = -1;
                short		ind_response_code = -1;
		short		ind_txn_code = -1;
        	short		ind_process_type = -1;
		short		ind_process_code = -1;
        	short		ind_host_posting_date = -1;
		short		ind_tm_date = -1;
		short           ind_tm_time = -1;
		short		ind_local_tm_date = -1;
		short		ind_local_tm_time = -1;
		short		ind_transmission_datetime = -1;
		short		ind_transaction_amount = -1;
		short		ind_transaction_ccy = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

		
	hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetMmsTxnHeader txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));


	/* EXEC SQL DECLARE c_cursor_gettxnheader CURSOR FOR
		select mth_org_txn_id,
		       mth_service_code,
		       mth_mmc_node_id,
		       mth_client_ref,
		       mth_status,
		       mth_ar_ind,
		       mth_internal_code,
		       mth_response_code,
		       mth_txn_code,
		       mth_process_type,
		       mth_process_code,
		       mth_host_posting_date,
		       mth_tm_date,
		       mth_tm_time,
		       mth_local_tm_date,
		       mth_local_tm_time,
		       mth_transmission_datetime,
		       mth_transaction_amount,
		       mth_transaction_ccy
		  from mms_txn_header
		 where mth_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_gettxnheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )346;
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
 if (sqlca.sqlcode < 0) goto gettxnheader_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_gettxnheader
		INTO 
			:v_org_txn_id:ind_org_txn_id,
			:v_service_code:ind_service_code,
			:v_mmc_node_id:ind_mmc_node_id,
			:v_client_ref:ind_client_ref,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_internal_code:ind_internal_code,
			:v_response_code:ind_response_code,
			:v_txn_code:ind_txn_code,
			:v_process_type:ind_process_type,
			:v_process_code:ind_process_code,
			:v_host_posting_date:ind_host_posting_date,
			:v_tm_date:ind_tm_date,
			:v_tm_time:ind_tm_time,
			:v_local_tm_date:ind_local_tm_date,
			:v_local_tm_time:ind_local_tm_time,
			:v_transmission_datetime:ind_transmission_datetime,
			:v_transaction_amount:ind_transaction_amount,
			:v_transaction_ccy:ind_transaction_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 35;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )365;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_org_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )19;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_org_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[1] = (unsigned long )6;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_service_code;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_mmc_node_id;
  sqlstm.sqhstl[2] = (unsigned long )8;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_mmc_node_id;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_client_ref;
  sqlstm.sqhstl[3] = (unsigned long )19;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_client_ref;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[4] = (unsigned long )1;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_status;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_ar_ind;
  sqlstm.sqhstl[5] = (unsigned long )1;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_ar_ind;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_internal_code;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_internal_code;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_response_code;
  sqlstm.sqhstl[7] = (unsigned long )7;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_response_code;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_code;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_process_type;
  sqlstm.sqhstl[9] = (unsigned long )7;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_process_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_process_code;
  sqlstm.sqhstl[10] = (unsigned long )9;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_process_code;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_host_posting_date;
  sqlstm.sqhstl[11] = (unsigned long )11;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_host_posting_date;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_tm_date;
  sqlstm.sqhstl[12] = (unsigned long )11;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_tm_date;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_tm_time;
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_tm_time;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_local_tm_date;
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_local_tm_date;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_local_tm_time;
  sqlstm.sqhstl[15] = (unsigned long )9;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_local_tm_time;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_transmission_datetime;
  sqlstm.sqhstl[16] = (unsigned long )17;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_transmission_datetime;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_transaction_amount;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_transaction_amount;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_transaction_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_transaction_ccy;
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
  if (sqlca.sqlcode < 0) goto gettxnheader_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* org_txn_seq */
		if (ind_org_txn_id >= 0) {
			v_org_txn_id.arr[v_org_txn_id.len] ='\0';
                        PutField_CString(myHash,"org_txn_seq",(const char*)v_org_txn_id.arr);
DEBUGLOG(("GetMmsTxnHeader org_txn_id = [%s]\n",v_org_txn_id.arr));
		}

/* service_code */
		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsTxnHeader service_code = [%s]\n",v_service_code.arr));
		}

/* mmc_node_id */
		if (ind_mmc_node_id >= 0) {
			v_mmc_node_id.arr[v_mmc_node_id.len] ='\0';
			PutField_CString(myHash,"mmc_node_id",(const char*)v_mmc_node_id.arr);
DEBUGLOG(("GetMmsTxnHeader mmc_node_id = [%s]\n",v_mmc_node_id.arr));
		}

/* client_ref */
		if (ind_client_ref >=0) {
			v_client_ref.arr[v_client_ref.len] ='\0';
			PutField_CString(myHash,"client_ref",(const char*)v_client_ref.arr);
DEBUGLOG(("GetMmsTxnHeader cleint_ref = [%s]\n",v_client_ref.arr));
		}

/* status */
		if (ind_status >= 0) {
DEBUGLOG(("GetMmsTxnHeader status = [%c]\n",v_status));
			PutField_Char(myHash,"status",v_status);
                }

/* ar_ind */
		if (ind_ar_ind >= 0) {
DEBUGLOG(("GetMmsTxnHeader ar_ind = [%c]\n",v_ar_ind));
			PutField_Char(myHash,"ar_ind", v_ar_ind);
                }

/* internal_code */
		if (ind_internal_code >= 0) {
			PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetMmsTxnHeader internal_code = [%d]\n",v_internal_code));
		}
	
/* response_code */
		if (ind_response_code >= 0) {
			v_response_code.arr[v_response_code.len] ='\0';
			PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetMmsTxnHeader response_code = [%s]\n",v_response_code.arr));
                }

/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] ='\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsTxnHeader txn_code = [%s]\n",v_txn_code.arr));
		}

/* process_type */
		if (ind_process_type >= 0) {
			v_process_type.arr[v_process_type.len] ='\0';
			PutField_CString(myHash,"process_type",(const char*)v_process_type.arr);
DEBUGLOG(("GetMmsTxnHeader process_type = [%s]\n",v_process_type.arr));
		}

/* process_code */
		if (ind_process_code >= 0) {
			v_process_code.arr[v_process_code.len] ='\0';
			PutField_CString(myHash,"process_code",(const char*)v_process_code.arr);
DEBUGLOG(("GetMmsTxnHeader process_code = [%s]\n",v_process_code.arr));
		}

/* host_posting_date */
		if (ind_host_posting_date >= 0) {
			v_host_posting_date.arr[v_host_posting_date.len] ='\0';
			PutField_CString(myHash,"host_posting_date",(const char*)v_host_posting_date.arr);
DEBUGLOG(("GetMmsTxnHeader host_posting_date = [%s]\n",v_host_posting_date.arr));
		}

/* tm_date */
		if (ind_tm_date >= 0) {
			v_tm_date.arr[v_tm_date.len] ='\0';
			PutField_CString(myHash,"tm_date",(const char*)v_tm_date.arr);
DEBUGLOG(("GetMmsTxnHeader tm_date = [%s]\n",v_tm_date.arr));
		}

/* tm_time */
                if (ind_tm_time >= 0) {
			v_tm_time.arr[v_tm_time.len] ='\0';
			PutField_CString(myHash,"tm_time",(const char*)v_tm_time.arr);
DEBUGLOG(("GetMmsTxnHeader tm_time = [%s]\n",v_tm_time.arr));
                }

/* local_tm_date */
                if (ind_local_tm_date >= 0) {
                        v_local_tm_date.arr[v_local_tm_date.len] ='\0';
                        PutField_CString(myHash,"local_tm_date",(const char*)v_local_tm_date.arr);
DEBUGLOG(("GetMmsTxnHeader local_tm_date = [%s]\n",v_local_tm_date.arr));
                }

/* local_tm_time */
                if (ind_local_tm_time >= 0) {
                        v_local_tm_time.arr[v_local_tm_time.len] ='\0';
                        PutField_CString(myHash,"local_tm_time",(const char*)v_local_tm_time.arr);
DEBUGLOG(("GetMmsTxnHeader local_tm_time = [%s]\n",v_local_tm_time.arr));
                }

/* transmission_datetime */
                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetMmsTxnHeader transmission_date_time = [%s]\n",v_transmission_datetime.arr));
                }

/* transaction_amount */
		if (ind_transaction_amount < 0) {
			v_transaction_amount = 0.0;
		}

		PutField_Double(myHash, "txn_amt", v_transaction_amount);
DEBUGLOG(("GetMmsTxnHeader txn_amt = [%f]\n",v_transaction_amount));
		
/* transaction_ccy */
                if (ind_transaction_ccy >= 0) {
                        v_transaction_ccy.arr[v_transaction_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_transaction_ccy.arr);
DEBUGLOG(("GetMmsTxnHeader txn_ccy = [%s]\n",v_transaction_ccy.arr));
                }

		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_gettxnheader; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )456;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxnheader_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetMmsTxnHeader Normal Exit\n"));
		return  PD_OK;
	}
	else {
DEBUGLOG(("GetMmsTxnHeader Normal Exit, Not Found\n"));
		return PD_ERR;
	}


gettxnheader_error:
DEBUGLOG(("gettxnheader_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )471;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetMmsTxnDetail(const char *csTxnID,
		    const char *csDtlTxnID,
		    recordset_t *myRec)
{

	int	iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;


		/* varchar		v_org_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } v_org_dtl_txn_id;

		/* varchar		v_init_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_init_channel;

		/* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		char		v_isd_ind;
		/* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar         v_mb_id[PD_MB_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mb_id;

		/* varchar         v_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_bank_id;

		/* varchar         v_stl_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_stl_bank_id;

		/* varchar		v_party_node_id[PD_MMS_NODE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_party_node_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_src_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_src_party_type;

		/* varchar		v_dst_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_dst_party_type;

		int		v_carry_forward_ind;
		/* varchar		v_dc_type[PD_MMS_DC_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_dc_type;

		char            v_status;
		/* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

		double          v_txn_amt;
		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double		v_adjustment;
		double		v_exchange_rate;
		double		v_processing_cost;
		double		v_bank_charge;
		double		v_bank_charge_refund;
		/* varchar		v_filing_number[PD_MMS_FILING_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_filing_number;

		/* varchar		v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar		v_version_no[PD_VERSION_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_version_no;

		/* varchar		v_encrypt_type[PD_ENCRYPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_encrypt_type;

		long		v_internal_code;
		/* varchar		v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

		/* varchar		v_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_prev_dtl_txn_id;


		short		ind_org_dtl_txn_id = -1;
		short		ind_init_channel = -1;
		short		ind_txn_code = -1;
		short		ind_isd_ind = -1;
		short		ind_merchant_id = -1;
		short		ind_psp_id = -1;
		short		ind_mb_id = -1;
		short		ind_bank_id = -1;
		short		ind_stl_bank_id = -1;
		short		ind_party_node_id = -1;
		short		ind_service_code = -1;
		short		ind_src_party_type = -1;
		short		ind_dst_party_type = -1;
		short		ind_carry_forward_ind = -1;
		short		ind_dc_type = -1;
		short		ind_status = -1;
		short		ind_transmission_datetime = -1;
		short		ind_txn_amt = -1;
		short		ind_txn_ccy = -1;
		short		ind_adjustment = -1;
		short		ind_exchange_rate = -1;
		short		ind_processing_cost = -1;
		short		ind_bank_charge = -1;
		short		ind_bank_charge_refund = -1;
		short		ind_filing_number = -1;
		short		ind_txn_country = -1;
		short		ind_version_no = -1;
		short		ind_encrypt_type = -1;
		short		ind_internal_code = -1;
		short		ind_response_code = -1;
		short		ind_prev_dtl_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 

		
	hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetMmsTxnDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_dtl_txn_id.len = strlen(csDtlTxnID);
        memcpy(hv_dtl_txn_id.arr,csDtlTxnID,hv_dtl_txn_id.len);
DEBUGLOG(("GetMmsTxnDetail dtl_txn_id = [%.*s]\n",hv_dtl_txn_id.len,hv_dtl_txn_id.arr));


	/* EXEC SQL DECLARE c_cursor_gettxndetail CURSOR FOR
		select mtd_org_dtl_txn_id,
		       mtd_init_channel,
		       mtd_txn_code,
		       mtd_isd_ind,
		       mtd_merchant_id,
		       mtd_psp_id,
	 	       mtd_mb_id,
		       mtd_bank_id,
		       mtd_stl_bank_id,
	               mtd_party_node_id,
		       mtd_service_code,
		       mtd_src_party_type,
		       mtd_dst_party_type,
		       mtd_carry_forward_ind,
		       mtd_dc_type,
		       mtd_status,
		       mtd_transmission_datetime,
		       mtd_txn_amt,
		       mtd_txn_ccy,
		       mtd_adjustment,
		       mtd_exchange_rate,
		       mtd_processing_cost,
		       mtd_bank_charge,
		       mtd_bank_charge_refund,
		       mtd_filing_number,
		       mtd_country,
		       mtd_version_no,
		       mtd_encrypt_type,
		       mtd_internal_code,
		       mtd_response_code,
		       mtd_prev_dtl_txn_id
		 from mms_txn_detail
		where mtd_txn_id = :hv_txn_id
		  and mtd_dtl_txn_id = :hv_dtl_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_gettxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0006;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )486;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_dtl_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )40;
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
 if (sqlca.sqlcode < 0) goto gettxndetail_error;
}


	do {
		/* EXEC SQL FETCH c_cursor_gettxndetail
		INTO 
			:v_org_dtl_txn_id:ind_org_dtl_txn_id, 
			:v_init_channel:ind_init_channel,
			:v_txn_code:ind_txn_code,
			:v_isd_ind:ind_isd_ind,
			:v_merchant_id:ind_merchant_id,
			:v_psp_id:ind_psp_id,
			:v_mb_id:ind_mb_id,
			:v_bank_id:ind_bank_id,
			:v_stl_bank_id:ind_stl_bank_id,
			:v_party_node_id:ind_party_node_id,
			:v_service_code:ind_service_code,
			:v_src_party_type:ind_src_party_type,
			:v_dst_party_type:ind_dst_party_type,
			:v_carry_forward_ind:ind_carry_forward_ind,
			:v_dc_type:ind_dc_type,
			:v_status:ind_status,
			:v_transmission_datetime:ind_transmission_datetime,
			:v_txn_amt:ind_txn_amt,
			:v_txn_ccy:ind_txn_ccy,
			:v_adjustment:ind_adjustment,
			:v_exchange_rate:ind_exchange_rate,
			:v_processing_cost:ind_processing_cost,
			:v_bank_charge:ind_bank_charge,
			:v_bank_charge_refund:ind_bank_charge_refund,
			:v_filing_number:ind_filing_number,
			:v_txn_country:ind_txn_country,
			:v_version_no:ind_version_no,
			:v_encrypt_type:ind_encrypt_type,
			:v_internal_code:ind_internal_code,
			:v_response_code :ind_response_code,
			:v_prev_dtl_txn_id:ind_prev_dtl_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 35;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )509;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_org_dtl_txn_id;
  sqlstm.sqhstl[0] = (unsigned long )40;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_org_dtl_txn_id;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_init_channel;
  sqlstm.sqhstl[1] = (unsigned long )5;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_init_channel;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_isd_ind;
  sqlstm.sqhstl[3] = (unsigned long )1;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_isd_ind;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[4] = (unsigned long )18;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_id;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&v_mb_id;
  sqlstm.sqhstl[6] = (unsigned long )18;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_mb_id;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_id;
  sqlstm.sqhstl[7] = (unsigned long )18;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_bank_id;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_stl_bank_id;
  sqlstm.sqhstl[8] = (unsigned long )18;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_stl_bank_id;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_party_node_id;
  sqlstm.sqhstl[9] = (unsigned long )8;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_party_node_id;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[10] = (unsigned long )6;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_service_code;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_src_party_type;
  sqlstm.sqhstl[11] = (unsigned long )8;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_src_party_type;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_dst_party_type;
  sqlstm.sqhstl[12] = (unsigned long )8;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_dst_party_type;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_carry_forward_ind;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_carry_forward_ind;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_dc_type;
  sqlstm.sqhstl[14] = (unsigned long )5;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_dc_type;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[15] = (unsigned long )1;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_status;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_transmission_datetime;
  sqlstm.sqhstl[16] = (unsigned long )17;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_transmission_datetime;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_adjustment;
  sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_adjustment;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_exchange_rate;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_exchange_rate;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_processing_cost;
  sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_processing_cost;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_bank_charge;
  sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_bank_charge;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_bank_charge_refund;
  sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_bank_charge_refund;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
  sqlstm.sqhstv[24] = (unsigned char  *)&v_filing_number;
  sqlstm.sqhstl[24] = (unsigned long )53;
  sqlstm.sqhsts[24] = (         int  )0;
  sqlstm.sqindv[24] = (         short *)&ind_filing_number;
  sqlstm.sqinds[24] = (         int  )0;
  sqlstm.sqharm[24] = (unsigned long )0;
  sqlstm.sqadto[24] = (unsigned short )0;
  sqlstm.sqtdso[24] = (unsigned short )0;
  sqlstm.sqhstv[25] = (unsigned char  *)&v_txn_country;
  sqlstm.sqhstl[25] = (unsigned long )5;
  sqlstm.sqhsts[25] = (         int  )0;
  sqlstm.sqindv[25] = (         short *)&ind_txn_country;
  sqlstm.sqinds[25] = (         int  )0;
  sqlstm.sqharm[25] = (unsigned long )0;
  sqlstm.sqadto[25] = (unsigned short )0;
  sqlstm.sqtdso[25] = (unsigned short )0;
  sqlstm.sqhstv[26] = (unsigned char  *)&v_version_no;
  sqlstm.sqhstl[26] = (unsigned long )5;
  sqlstm.sqhsts[26] = (         int  )0;
  sqlstm.sqindv[26] = (         short *)&ind_version_no;
  sqlstm.sqinds[26] = (         int  )0;
  sqlstm.sqharm[26] = (unsigned long )0;
  sqlstm.sqadto[26] = (unsigned short )0;
  sqlstm.sqtdso[26] = (unsigned short )0;
  sqlstm.sqhstv[27] = (unsigned char  *)&v_encrypt_type;
  sqlstm.sqhstl[27] = (unsigned long )7;
  sqlstm.sqhsts[27] = (         int  )0;
  sqlstm.sqindv[27] = (         short *)&ind_encrypt_type;
  sqlstm.sqinds[27] = (         int  )0;
  sqlstm.sqharm[27] = (unsigned long )0;
  sqlstm.sqadto[27] = (unsigned short )0;
  sqlstm.sqtdso[27] = (unsigned short )0;
  sqlstm.sqhstv[28] = (unsigned char  *)&v_internal_code;
  sqlstm.sqhstl[28] = (unsigned long )sizeof(long);
  sqlstm.sqhsts[28] = (         int  )0;
  sqlstm.sqindv[28] = (         short *)&ind_internal_code;
  sqlstm.sqinds[28] = (         int  )0;
  sqlstm.sqharm[28] = (unsigned long )0;
  sqlstm.sqadto[28] = (unsigned short )0;
  sqlstm.sqtdso[28] = (unsigned short )0;
  sqlstm.sqhstv[29] = (unsigned char  *)&v_response_code;
  sqlstm.sqhstl[29] = (unsigned long )7;
  sqlstm.sqhsts[29] = (         int  )0;
  sqlstm.sqindv[29] = (         short *)&ind_response_code;
  sqlstm.sqinds[29] = (         int  )0;
  sqlstm.sqharm[29] = (unsigned long )0;
  sqlstm.sqadto[29] = (unsigned short )0;
  sqlstm.sqtdso[29] = (unsigned short )0;
  sqlstm.sqhstv[30] = (unsigned char  *)&v_prev_dtl_txn_id;
  sqlstm.sqhstl[30] = (unsigned long )41;
  sqlstm.sqhsts[30] = (         int  )0;
  sqlstm.sqindv[30] = (         short *)&ind_prev_dtl_txn_id;
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
  if (sqlca.sqlcode < 0) goto gettxndetail_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* org_dtl_txn_id */
		if (ind_org_dtl_txn_id >= 0) {
			v_org_dtl_txn_id.arr[v_org_dtl_txn_id.len] ='\0';
			PutField_CString(myHash,"org_dtl_txn_id",(const char*)v_org_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetail org_dtl_txn_id = [%s]\n",v_org_dtl_txn_id.arr));
		}

/* init_channel */
		if (ind_init_channel >= 0) {
			v_init_channel.arr[v_init_channel.len] ='\0';
			PutField_CString(myHash,"init_channel",(const char*)v_init_channel.arr);
DEBUGLOG(("GetMmsTxnDetail init_channel = [%s]\n",v_init_channel.arr));
		}


/* txn_code */
		if (ind_txn_code >= 0) {
			v_txn_code.arr[v_txn_code.len] ='\0';
			PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsTxnDetail txn_code = [%s]\n",v_txn_code.arr));
		}

/* isd_ind */
		if (ind_isd_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetail isd_ind = [%c]\n",v_isd_ind));
			PutField_Char(myHash,"isd_ind",v_isd_ind);
		}

/* merchant_id */
		if (ind_merchant_id >= 0) {
			v_merchant_id.arr[v_merchant_id.len] ='\0';
			PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMmsTxnDetail merchant_id = [%s]\n",v_merchant_id.arr));
		}

/* psp_id */
		if (ind_psp_id >= 0) {
			v_psp_id.arr[v_psp_id.len] ='\0';
			PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetMmsTxnDetail psp_id = [%s]\n",v_psp_id.arr));
		}

/* mb_id */
		if (ind_mb_id >= 0) {
			v_mb_id.arr[v_mb_id.len] ='\0';
			PutField_CString(myHash,"mb_id",(const char*)v_mb_id.arr);
DEBUGLOG(("GetMmsTxnDetail mb_id = [%s]\n",v_mb_id.arr));
		}

/* bank_id */
		if (ind_bank_id >= 0) {
			v_bank_id.arr[v_bank_id.len] ='\0';
			PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetail bank_id = [%s]\n",v_bank_id.arr));
		}

/* stl_bank_id */
		if (ind_stl_bank_id >= 0) {
			v_stl_bank_id.arr[v_stl_bank_id.len] ='\0';
			PutField_CString(myHash,"stl_bank_id",(const char*)v_stl_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetail stl_bank_id = [%s]\n",v_stl_bank_id.arr));
		}
/* party_node_id */
		if (ind_party_node_id >= 0) {
			v_party_node_id.arr[v_party_node_id.len] ='\0';
			PutField_CString(myHash,"party_node_id",(const char*)v_party_node_id.arr);
DEBUGLOG(("GetMmsTxnDetail party_node_id = [%s]\n",v_party_node_id.arr));
		}

/* service_code */
		if (ind_service_code >= 0) {
			v_service_code.arr[v_service_code.len] ='\0';
			PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsTxnDetail service_code = [%s]\n",v_service_code.arr));
		}

/* src_party_type */
		if (ind_src_party_type >= 0) {
			v_src_party_type.arr[v_src_party_type.len] ='\0';
			PutField_CString(myHash,"src_party_type",(const char*)v_src_party_type.arr);
DEBUGLOG(("GetMmsTxnDetail src_party_type = [%s]\n",v_src_party_type.arr));
		}

/* dst_party_type */
		if (ind_dst_party_type >= 0) {
			v_dst_party_type.arr[v_dst_party_type.len] ='\0';
			PutField_CString(myHash,"dst_party_type",(const char*)v_dst_party_type.arr);
DEBUGLOG(("GetMmsTxnDetail dst_party_type = [%s]\n",v_dst_party_type.arr));
		}

/* carry_forward_ind */
		if (ind_carry_forward_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetail carry_forward_ind = [%d]\n",v_carry_forward_ind));
			PutField_Int(myHash,"carry_forward_ind",v_carry_forward_ind);
		}

/* dc_type */
		if (ind_dc_type >= 0) {
			v_dc_type.arr[v_dc_type.len] ='\0';
			PutField_CString(myHash,"dc_type",(const char*)v_dc_type.arr);
DEBUGLOG(("GetMmsTxnDetail dc_type = [%s]\n",v_dc_type.arr));
		}

/* status */
		if (ind_status >= 0) {
DEBUGLOG(("GetMmsTxnDetail status = [%c]\n",v_status));
			PutField_Char(myHash,"status",v_status);
                }

/* transmission_datetime */
                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetMmsTxnDetail transmission_date_time = [%s]\n",v_transmission_datetime.arr));
                }


/* txn_amt */
		if (ind_txn_amt < 0) {
			v_txn_amt = 0.0;
		}
		PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetMmsTxnDetail txn_amt = [%f]\n",v_txn_amt));
		
/* txn_ccy */
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetMmsTxnDetail txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

/* adjustment */
		if (ind_adjustment < 0) {
			v_adjustment = 0.0;
		}
		PutField_Double(myHash, "adjustment", v_adjustment);
DEBUGLOG(("GetMmsTxnDetail adjustment = [%f]\n",v_adjustment));

/* exchange_rate */
		if (ind_exchange_rate < 0) {
			v_exchange_rate = 1.0;
		}
		PutField_Double(myHash, "exchange_rate", v_exchange_rate);
DEBUGLOG(("GetMmsTxnDetail exchange_rate = [%f]\n",v_exchange_rate));

/* processing_cost */
		if (ind_processing_cost < 0) {
			v_processing_cost = 0.0;
		}
		PutField_Double(myHash, "processing_cost", v_processing_cost);
DEBUGLOG(("GetMmsTxnDetail processing_cost = [%f]\n",v_processing_cost));

/* bank_charge */
		if (ind_bank_charge < 0) {
			v_bank_charge = 0.0;
		}
		PutField_Double(myHash, "bank_charge", v_bank_charge);
DEBUGLOG(("GetMmsTxnDetail bank_charge = [%f]\n",v_bank_charge));

/* bank_charge_refund */
		if (ind_bank_charge_refund < 0) {
			v_bank_charge_refund = 0.0;
		}
		PutField_Double(myHash, "bank_charge_refund", v_bank_charge_refund);
DEBUGLOG(("GetMmsTxnDetail bank_charge_refund = [%f]\n",v_bank_charge_refund));

/* filing_number */
                if (ind_filing_number >= 0) {
                        v_filing_number.arr[v_filing_number.len] ='\0';
                        PutField_CString(myHash,"filing_number",(const char*)v_filing_number.arr);
DEBUGLOG(("GetMmsTxnDetail filing_number = [%s]\n",v_filing_number.arr));
                }

/* txn_country */
		if (ind_txn_country  >=  0) {
			v_txn_country.arr[v_txn_ccy.len] = '\0';
			PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetMmsTxnDetail txn_country = [%s]\n",v_txn_country.arr));
		}

/* version_no */
		if (ind_version_no >=  0) {
			v_version_no.arr[v_version_no.len] = '\0';
			PutField_CString(myHash,"version_no",(const char*)v_version_no.arr);
DEBUGLOG(("GetMmsTxnDetail version_no = [%s]\n",v_version_no.arr));
		}

/* encrypt_type */
		if (ind_encrypt_type >=  0) {
			v_encrypt_type.arr[v_encrypt_type.len] = '\0';
			PutField_CString(myHash,"encrypt_type",(const char*)v_encrypt_type.arr);
DEBUGLOG(("GetMmsTxnDetail encrypt_type = [%s]\n",v_encrypt_type.arr));
		}

/* internal_code */
		if (ind_internal_code >= 0) {
			PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetMmsTxnDetail internal_code = [%d]\n",v_internal_code));
		}

/* response_code */
		if (ind_response_code >= 0) {
			v_response_code.arr[v_response_code.len] ='\0';
			PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetMmsTxnDetail response_code = [%s]\n",v_response_code.arr));
                }

/* prev_dtl_txn_id */
		if (ind_prev_dtl_txn_id >= 0) {
			v_prev_dtl_txn_id.arr[v_prev_dtl_txn_id.len] ='\0';
			PutField_CString(myHash,"prev_dtl_txn_seq",(const char*)v_prev_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetail prev_dtl_txn_id = [%s]\n",v_prev_dtl_txn_id.arr));
                }


		RecordSet_Add(myRec, myHash);
	}
	while (PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_gettxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )648;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto gettxndetail_error;
}



	if (iCnt > 0 ) {
DEBUGLOG(("GetMmsTxnDetail Normal Exit\n"));
		return  PD_OK;
	}
	else {
DEBUGLOG(("GetMmsTxnDetail Normal Exit, Not Found\n"));
		return PD_ERR;
	}


gettxndetail_error:
DEBUGLOG(("gettxndetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )663;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int	ChkIsFirstProcessRecord(const char *csTxnSeq, const char *csDtlTxnSeq)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chkrec_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;

                /* varchar         hv_dtl_txn_seq[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_seq;

		char		hv_isd_ind;
		/* varchar		hv_init_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_init_channel;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_seq.len = strlen(csTxnSeq);
	memcpy(hv_txn_seq.arr, csTxnSeq, hv_txn_seq.len);
DEBUGLOG(("ChkFirstProcessRecord txn_seq = [%.*s]\n",hv_txn_seq.len,hv_txn_seq.arr));

	hv_dtl_txn_seq.len = strlen(csDtlTxnSeq);
	memcpy(hv_dtl_txn_seq.arr, csDtlTxnSeq, hv_dtl_txn_seq.len);
DEBUGLOG(("ChkFirstProcessRecord dtl_txn_seq = [%.*s]\n",hv_dtl_txn_seq.len,hv_dtl_txn_seq.arr));

	hv_init_channel.len = strlen(PD_CHANNEL_MMC);
	memcpy(hv_init_channel.arr, PD_CHANNEL_MMC, hv_init_channel.len);
DEBUGLOG(("ChkFirstProcessRecord init_channel = [%.*s]\n",hv_init_channel.len, hv_init_channel.arr));
	

	hv_isd_ind = 'I'; 

	/* EXEC SQL
		
		SELECT count(1)
		  INTO :v_no_of_record:ind_no_of_record
		  FROM mms_txn_detail
		 WHERE mtd_txn_id = :hv_txn_seq
		   AND mtd_isd_ind = :hv_isd_ind 
		   AND mtd_dtl_txn_id = :hv_dtl_txn_seq
	           AND mtd_init_channel != :hv_init_channel
                   AND mtd_dc_type in ('DR', 'CR') ; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM mms_txn_detail WHERE mt\
d_txn_id = :b2 AND mtd_isd_ind = :b3 AND mtd_dtl_txn_id = :b4 AND mtd_init_ch\
annel != :b5 AND mtd_dc_type in ( 'DR' , 'CR' ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )678;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_isd_ind;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_dtl_txn_seq;
 sqlstm.sqhstl[3] = (unsigned long )40;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_init_channel;
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
 if (sqlca.sqlcode < 0) goto chkrec_error;
}


			
	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("ChkNonFirstProcessRecod FOUND\n"));
			iRet = PD_FOUND;
		}
	}

	if (iRet != PD_FOUND) {
DEBUGLOG(("ChkNonFirstProcessRecod NOT FOUND\n"));
	}

	return iRet;

chkrec_error:
DEBUGLOG(("ChkNonFirstProcessRecord_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int	CheckTxnPending(const char *csTxnSeq, const char *csDtlTxnSeq)
{
        int     iRet = PD_ERR;

        /* EXEC SQL WHENEVER SQLERROR GOTO checkpending_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;

                /* varchar         hv_dtl_txn_seq[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_seq;

		char		hv_status;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;


		short		ind_txn_code = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_seq.len = strlen(csTxnSeq);
	memcpy(hv_txn_seq.arr, csTxnSeq, hv_txn_seq.len);
DEBUGLOG(("CheckTxnPending = [%.*s]\n",hv_txn_seq.len,hv_txn_seq.arr));

	hv_dtl_txn_seq.len = strlen(csDtlTxnSeq);
	memcpy(hv_dtl_txn_seq.arr, csDtlTxnSeq, hv_dtl_txn_seq.len);
DEBUGLOG(("CheckTxnPending = [%.*s]\n",hv_dtl_txn_seq.len,hv_dtl_txn_seq.arr));

	hv_status  = PD_MMC_PENDING;

	/* EXEC SQL
		/o
		SELECT mth_txn_code
		  INTO :v_txn_code:ind_txn_code
		  FROM mms_txn_header
		 WHERE mth_txn_id = :hv_txn_seq
		   AND mth_status = :hv_status
		   for update;
		o/

		SELECT mtd_txn_code
		  INTO :v_txn_code:ind_txn_code
		  FROM mms_txn_detail
		 WHERE mtd_txn_id = :hv_txn_seq
		   AND mtd_dtl_txn_id = :hv_dtl_txn_seq
		   AND mtd_status = :hv_status
		   for update; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select mtd_txn_code INTO :b0:b1 FROM mms_txn_detail WHERE m\
td_txn_id = :b2 AND mtd_dtl_txn_id = :b3 AND mtd_status = :b4 for update ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )713;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_code;
 sqlstm.sqhstl[0] = (unsigned long )6;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_code;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_seq;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_dtl_txn_seq;
 sqlstm.sqhstl[2] = (unsigned long )40;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[3] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto checkpending_error;
}


		  
			
	if (ind_txn_code>= 0) {
DEBUGLOG(("CheckTxnPending FOUND\n"));
		iRet = PD_OK;
	}

DEBUGLOG(("CheckTxnPending iRet=[%d]\n",iRet));
	return iRet;

checkpending_error:
DEBUGLOG(("Checkpending_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetMmsTxnDetailByPrevId(const char *csTxnID,
			    const char *csDtlTxnID,
		           recordset_t *myRec)	
{
        int     iCnt = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndetailbyprevid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;


                /* varchar         v_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_dtl_txn_id;

		/* varchar		v_org_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_org_dtl_txn_id;

		/* varchar		v_init_channel[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_init_channel;

                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		char		v_isd_ind;
                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_mb_id[PD_MB_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mb_id;

                /* varchar         v_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_bank_id;

                /* varchar         v_stl_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_stl_bank_id;

		/* varchar		v_party_node_id[PD_MMS_NODE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_party_node_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_src_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_src_party_type;

		/* varchar		v_dst_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_dst_party_type;

		int		v_carry_forward_ind;
		/* varchar		v_dc_type[PD_MMS_DC_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_dc_type;

                char            v_status;
                /* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

                double          v_txn_amt;
                /* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double          v_adjustment;
                double          v_exchange_rate;
                double          v_processing_cost;
                double          v_bank_charge;
                double          v_bank_charge_refund;
                /* varchar         v_filing_number[PD_MMS_FILING_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_filing_number;

                /* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_version_no[PD_VERSION_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_version_no;

                /* varchar         v_encrypt_type[PD_ENCRYPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_encrypt_type;

                long            v_internal_code;
                /* varchar         v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

		/* varchar		v_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_prev_dtl_txn_id;


                short           ind_dtl_txn_id = -1;
		short		ind_org_dtl_txn_id = -1;
		short		ind_init_channel = -1;
                short           ind_txn_code = -1;
		short		ind_isd_ind = -1;
                short           ind_merchant_id = -1;
                short           ind_psp_id = -1;
                short           ind_mb_id = -1;
                short           ind_bank_id = -1;
                short           ind_stl_bank_id = -1;
		short		ind_party_node_id = -1;
		short		ind_service_code = -1;
		short		ind_src_party_type = -1;
		short		ind_dst_party_type = -1;
		short		ind_carry_forward_ind = -1;
		short		ind_dc_type = -1;	
                short           ind_status = -1;
                short           ind_transmission_datetime = -1;
                short           ind_txn_amt = -1;
                short           ind_txn_ccy = -1;
                short           ind_adjustment = -1;
                short           ind_exchange_rate = -1;
                short           ind_processing_cost = -1;
                short           ind_bank_charge = -1;
                short           ind_bank_charge_refund = -1;
                short           ind_filing_number = -1;
                short           ind_txn_country = -1;
                short           ind_version_no = -1;
                short           ind_encrypt_type = -1;
                short           ind_internal_code = -1;
                short           ind_response_code = -1;
		short		ind_prev_dtl_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetMmsTxnDetailByPrevId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_dtl_txn_id.len = strlen(csDtlTxnID);
        memcpy(hv_dtl_txn_id.arr,csDtlTxnID,hv_dtl_txn_id.len);
DEBUGLOG(("GetMmsTxnDetailByPrevId dtl_txn_id = [%.*s]\n",hv_dtl_txn_id.len,hv_dtl_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxndetailbyprevid CURSOR FOR
                select mtd_dtl_txn_id,
		       mtd_org_dtl_txn_id,
		       mtd_init_channel,
                       mtd_txn_code,
		       mtd_isd_ind,
                       mtd_merchant_id,
                       mtd_psp_id,
                       mtd_mb_id,
                       mtd_bank_id,
                       mtd_stl_bank_id,
		       mtd_party_node_id,
		       mtd_service_code,
		       mtd_src_party_type,
		       mtd_dst_party_type,
		       mtd_carry_forward_ind,
		       mtd_dc_type,
                       mtd_status,
                       mtd_transmission_datetime,
                       mtd_txn_amt,
                       mtd_txn_ccy,
                       mtd_adjustment,
                       mtd_exchange_rate,
                       mtd_processing_cost,
                       mtd_bank_charge,
                       mtd_bank_charge_refund,
                       mtd_filing_number,
                       mtd_country,
                       mtd_version_no,
                       mtd_encrypt_type,
                       mtd_internal_code,
                       mtd_response_code,
		       mtd_prev_dtl_txn_id
                 from mms_txn_detail
                where mtd_txn_id = :hv_txn_id
		  and mtd_prev_dtl_txn_id = :hv_dtl_txn_id
		order by mtd_dtl_txn_id desc; */ 


        /* EXEC SQL OPEN c_cursor_gettxndetailbyprevid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )744;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_dtl_txn_id;
        sqlstm.sqhstl[1] = (unsigned long )40;
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
        if (sqlca.sqlcode < 0) goto gettxndetailbyprevid_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxndetailbyprevid
                INTO    :v_dtl_txn_id:ind_dtl_txn_id,
			:v_org_dtl_txn_id:ind_org_dtl_txn_id,
			:v_init_channel:ind_init_channel,
                        :v_txn_code:ind_txn_code,
			:v_isd_ind:ind_isd_ind,
                        :v_merchant_id:ind_merchant_id,
                        :v_psp_id:ind_psp_id,
                        :v_mb_id:ind_mb_id,
                        :v_bank_id:ind_bank_id,
                        :v_stl_bank_id:ind_stl_bank_id,
			:v_party_node_id:ind_party_node_id,
			:v_service_code:ind_service_code,
			:v_src_party_type:ind_src_party_type,
			:v_dst_party_type:ind_dst_party_type,
                        :v_carry_forward_ind:ind_carry_forward_ind,
                        :v_dc_type:ind_dc_type,
                        :v_status:ind_status,
                        :v_transmission_datetime:ind_transmission_datetime,
                        :v_txn_amt:ind_txn_amt,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_adjustment:ind_adjustment,
                        :v_exchange_rate:ind_exchange_rate,
                        :v_processing_cost:ind_processing_cost,
                        :v_bank_charge:ind_bank_charge,
                        :v_bank_charge_refund:ind_bank_charge_refund,
                        :v_filing_number:ind_filing_number,
                        :v_txn_country:ind_txn_country,
                        :v_version_no:ind_version_no,
                        :v_encrypt_type:ind_encrypt_type,
                        :v_internal_code:ind_internal_code,
                        :v_response_code :ind_response_code,
			:v_prev_dtl_txn_id:ind_prev_dtl_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 35;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )767;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_dtl_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )41;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_dtl_txn_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_org_dtl_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )41;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_org_dtl_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_init_channel;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_init_channel;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_isd_ind;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_isd_ind;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[5] = (unsigned long )18;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[6] = (unsigned long )13;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_psp_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_mb_id;
                sqlstm.sqhstl[7] = (unsigned long )18;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_mb_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_id;
                sqlstm.sqhstl[8] = (unsigned long )18;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_id;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_stl_bank_id;
                sqlstm.sqhstl[9] = (unsigned long )18;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_stl_bank_id;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_party_node_id;
                sqlstm.sqhstl[10] = (unsigned long )8;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_party_node_id;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[11] = (unsigned long )6;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_service_code;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_src_party_type;
                sqlstm.sqhstl[12] = (unsigned long )8;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_src_party_type;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_dst_party_type;
                sqlstm.sqhstl[13] = (unsigned long )8;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_dst_party_type;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_carry_forward_ind;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_carry_forward_ind;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_dc_type;
                sqlstm.sqhstl[15] = (unsigned long )5;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_dc_type;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[16] = (unsigned long )1;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_status;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_transmission_datetime;
                sqlstm.sqhstl[17] = (unsigned long )17;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_transmission_datetime;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[19] = (unsigned long )6;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_adjustment;
                sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_adjustment;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_exchange_rate;
                sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_exchange_rate;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_processing_cost;
                sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_processing_cost;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_bank_charge;
                sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_bank_charge;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_charge_refund;
                sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_bank_charge_refund;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_filing_number;
                sqlstm.sqhstl[25] = (unsigned long )53;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_filing_number;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[26] = (unsigned long )5;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_txn_country;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_version_no;
                sqlstm.sqhstl[27] = (unsigned long )5;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_version_no;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_encrypt_type;
                sqlstm.sqhstl[28] = (unsigned long )7;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_encrypt_type;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[29] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_internal_code;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[30] = (unsigned long )7;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_response_code;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_prev_dtl_txn_id;
                sqlstm.sqhstl[31] = (unsigned long )41;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_prev_dtl_txn_id;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gettxndetailbyprevid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

// dtl_txn_seq //
		if (ind_dtl_txn_id >= 0) {
                        v_dtl_txn_id.arr[v_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"dtl_txn_seq",(const char*)v_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId dtl_txn_seq = [%s]\n",v_dtl_txn_id.arr));
		}

// org_dtl_txn_seq //
		if (ind_org_dtl_txn_id >= 0) {
                        v_org_dtl_txn_id.arr[v_org_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"org_dtl_txn_seq",(const char*)v_org_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId org_dtl_txn_seq = [%s]\n",v_org_dtl_txn_id.arr));
		}

// init_channel //
		if (ind_init_channel >= 0) {
                        v_init_channel.arr[v_init_channel.len] ='\0';
                        PutField_CString(myHash,"init_channel",(const char*)v_init_channel.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId init_channel = [%s]\n",v_init_channel.arr));
		}

// txn_code //
                if (ind_txn_code >= 0) {
                        v_txn_code.arr[v_txn_code.len] ='\0';
                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId txn_code = [%s]\n",v_txn_code.arr));
                }

// isd_ind //
                if (ind_isd_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetailByPrevId isd_ind = [%c]\n",v_isd_ind));
                        PutField_Char(myHash,"isd_ind",v_isd_ind);
                }

// merchant_id //
                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId merchant_id = [%s]\n",v_merchant_id.arr));
                }

// psp_id //
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] ='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId psp_id = [%s]\n",v_psp_id.arr));
                }

// mb_id //
                if (ind_mb_id >= 0) {
                        v_mb_id.arr[v_mb_id.len] ='\0';
                        PutField_CString(myHash,"mb_id",(const char*)v_mb_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId mb_id = [%s]\n",v_mb_id.arr));
                }

// bank_id //
                if (ind_bank_id >= 0) {
                        v_bank_id.arr[v_bank_id.len] ='\0';
                        PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId bank_id = [%s]\n",v_bank_id.arr));
                }

// stl_bank_id //
                if (ind_stl_bank_id >= 0) {
                        v_stl_bank_id.arr[v_stl_bank_id.len] ='\0';
                        PutField_CString(myHash,"stl_bank_id",(const char*)v_stl_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId stl_bank_id = [%s]\n",v_stl_bank_id.arr));
                }
// party_node_id //
                if (ind_party_node_id >= 0) {
                        v_party_node_id.arr[v_party_node_id.len] ='\0';
                        PutField_CString(myHash,"party_node_id",(const char*)v_party_node_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId party_node_id = [%s]\n",v_party_node_id.arr));
                }

// service_code //
                if (ind_service_code >= 0) {
                        v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId service_code = [%s]\n",v_service_code.arr));
                }

// src_party_type //
                if (ind_src_party_type >= 0) {
                        v_src_party_type.arr[v_src_party_type.len] ='\0';
                        PutField_CString(myHash,"src_party_type",(const char*)v_src_party_type.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId src_party_type = [%s]\n",v_src_party_type.arr));
                }

// dst_party_type //
                if (ind_dst_party_type >= 0) {
                        v_dst_party_type.arr[v_dst_party_type.len] ='\0';
                        PutField_CString(myHash,"dst_party_type",(const char*)v_dst_party_type.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId dst_party_type = [%s]\n",v_dst_party_type.arr));
                }

// carry_forward_ind //
		if (ind_carry_forward_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetailByPrevId carry_forward_ind = [%d]\n",v_carry_forward_ind));
                        PutField_Int(myHash,"carry_forward_ind",v_carry_forward_ind);
		}

// dc_type //
                if (ind_dc_type >= 0) {
                        v_dc_type.arr[v_dc_type.len] ='\0';
                        PutField_CString(myHash,"dc_type",(const char*)v_dc_type.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId dc_type = [%s]\n",v_dc_type.arr));
                }

// status //
                if (ind_status >= 0) {
DEBUGLOG(("GetMmsTxnDetailByPrevId status = [%c]\n",v_status));
                        PutField_Char(myHash,"status",v_status);
                }


// transmission_datetime //
                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId transmission_date_time = [%s]\n",v_transmission_datetime.arr));
                }


// txn_amt //
                if (ind_txn_amt < 0) {
                        v_txn_amt = 0.0;
                }
                PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetMmsTxnDetailByPrevId txn_amt = [%f]\n",v_txn_amt));

// txn_ccy //
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

// adjustment //
                if (ind_adjustment < 0) {
                        v_adjustment = 0.0;
                }
                PutField_Double(myHash, "adjustment", v_adjustment);
DEBUGLOG(("GetMmsTxnDetailByPrevId adjustment = [%f]\n",v_adjustment));

// exchange_rate //
                if (ind_exchange_rate < 0) {
                        v_exchange_rate = 1.0;
                }
                PutField_Double(myHash, "exchange_rate", v_exchange_rate);
DEBUGLOG(("GetMmsTxnDetailByPrevId exchange_rate = [%f]\n",v_exchange_rate));

// processing_cost //
                if (ind_processing_cost < 0) {
                        v_processing_cost = 0.0;
                }
                PutField_Double(myHash, "processing_cost", v_processing_cost);
DEBUGLOG(("GetMmsTxnDetailByPrevId processing_cost = [%f]\n",v_processing_cost));

// bank_charge //
                if (ind_bank_charge < 0) {
                        v_bank_charge = 0.0;
                }
                PutField_Double(myHash, "bank_charge", v_bank_charge);
DEBUGLOG(("GetMmsTxnDetailByPrevId bank_charge = [%f]\n",v_bank_charge));

// bank_charge_refund //
                if (ind_bank_charge_refund < 0) {
                        v_bank_charge_refund = 0.0;
                }
                PutField_Double(myHash, "bank_charge_refund", v_bank_charge_refund);
DEBUGLOG(("GetMmsTxnDetailByPrevId bank_charge_refund = [%f]\n",v_bank_charge_refund));

// filing_number //
                if (ind_filing_number >= 0) {
                        v_filing_number.arr[v_filing_number.len] ='\0';
                        PutField_CString(myHash,"filing_number",(const char*)v_filing_number.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId filing_number = [%s]\n",v_filing_number.arr));
                }

// txn_country //
                if (ind_txn_country  >=  0) {
                        v_txn_country.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId txn_country = [%s]\n",v_txn_country.arr));
                }

// version_no //
                if (ind_version_no >=  0) {
                        v_version_no.arr[v_version_no.len] = '\0';
                        PutField_CString(myHash,"version_no",(const char*)v_version_no.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId version_no = [%s]\n",v_version_no.arr));
                }

// encrypt_type //
                if (ind_encrypt_type >=  0) {
                        v_encrypt_type.arr[v_encrypt_type.len] = '\0';
                        PutField_CString(myHash,"encrypt_type",(const char*)v_encrypt_type.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId encrypt_type = [%s]\n",v_encrypt_type.arr));
                }

// internal_code //
                if (ind_internal_code >= 0) {
                        PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetMmsTxnDetailByPrevId internal_code = [%d]\n",v_internal_code));
                }

// response_code //
                if (ind_response_code >= 0) {
                        v_response_code.arr[v_response_code.len] ='\0';
                        PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId response_code = [%s]\n",v_response_code.arr));
                }


// prev_dtl_txn_id //
                if (ind_prev_dtl_txn_id >= 0) {
                        v_prev_dtl_txn_id.arr[v_prev_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"prev_dtl_txn_id",(const char*)v_prev_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByPrevId prev_dtl_txn_id = [%s]\n",v_prev_dtl_txn_id.arr));
                }



                RecordSet_Add(myRec, myHash);
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_gettxndetailbyprevid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )910;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxndetailbyprevid_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetMmsTxnDetailByPrevId Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetMmsTxnDetailByPrevId Normal Exit, Not Found\n"));
                return PD_ERR;
        }


gettxndetailbyprevid_error:
DEBUGLOG(("gettxndetailbyprevid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxndetailbyprevid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )925;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int 	GetMmsTxnHeaderRec(const hash_t *hRec, recordset_t *myRec)
{
	int	iRet = PD_OK;
	int	iCnt = 0;

	char	*csTmp = NULL;
	char	cTmp;

	hash_t  *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmmstxnheaderrec_error; */ 
 
        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	        short           hv_return_value;

                /* varchar         hv_req_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_txn_id;

                char            hv_req_status;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                /* varchar         v_org_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_org_txn_id;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                /* varchar         v_mmc_node_id[PD_MMS_NODE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_mmc_node_id;

                char            v_status;
                char            v_ar_ind;
                long            v_internal_code;
                /* varchar         v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar         v_process_type[PD_PROCESS_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

                /* varchar         v_process_code[PD_PROCESS_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;

                /* varchar         v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

                /* varchar         v_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_tm_date;

                /* varchar         v_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_tm_time;

                /* varchar         v_local_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

                /* varchar         v_local_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_local_tm_time;

                /* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

                double          v_transaction_amount;
                /* varchar         v_transaction_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_transaction_ccy;



		short		ind_req_txn_id = -1;
		short		ind_req_status = -1;

                short           ind_txn_id = -1;
                short           ind_org_txn_id = -1;
                short           ind_service_code = -1;
                short           ind_mmc_node_id = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_internal_code = -1;
                short           ind_response_code = -1;
                short           ind_txn_code = -1;
                short           ind_process_type = -1;
                short           ind_process_code = -1;
                short           ind_host_posting_date = -1;
                short           ind_tm_date = -1;
                short           ind_tm_time = -1;
                short           ind_local_tm_date = -1;
                short           ind_local_tm_time = -1;
                short           ind_transmission_datetime = -1;
                short           ind_transaction_amount = -1;
                short           ind_transaction_ccy = -1;

		SQL_CURSOR 	c_cursor_id;

        /* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRec, "req_txn_seq", &csTmp)) {
                hv_req_txn_id.len = strlen(csTmp);
                memcpy(hv_req_txn_id.arr, csTmp, hv_req_txn_id.len);
                ind_req_txn_id = 0;
DEBUGLOG(("GetMmsTxnHeaderRec req_txn_id = [%d][%.*s]\n",hv_req_txn_id.len,hv_req_txn_id.len,hv_req_txn_id.arr));
	}

	if (GetField_Char(hRec, "req_txn_status", &cTmp)) {
                hv_req_status = cTmp;
                ind_req_status= 0;
DEBUGLOG(("GetMmsTxnHeaderRec req_status = [%c]\n", hv_req_status));
	}

	/* EXEC sQL ALLOCATE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )940;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}



	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_mms_txn_header_rec(:hv_req_txn_id:ind_req_txn_id,
							          :hv_req_status:ind_req_status,
								  :c_cursor_id);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_txn_header_rec ( :hv_req_t\
xn_id:ind_req_txn_id , :hv_req_status:ind_req_status , :c_cursor_id ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )959;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_req_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_req_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_req_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_req_status;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&c_cursor_id;
 sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
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
 if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}



	if (hv_return_value == SP_OK) {
DEBUGLOG(("GetMmsTxnHeaderRec found record\n"));
                for (;;) {
                        myHash = (hash_t*) malloc(sizeof(hash_t));
                        hash_init(myHash, 0);


			ind_txn_id = -1;
			ind_org_txn_id = -1;
			ind_service_code = -1;
			ind_mmc_node_id = -1;
			ind_status = -1;
			ind_ar_ind = -1;
			ind_internal_code = -1;
			ind_response_code = -1;
			ind_txn_code = -1;
			ind_process_type = -1;
			ind_process_code = -1;
			ind_host_posting_date = -1;
			ind_tm_date = -1;
			ind_tm_time = -1;
			ind_local_tm_date = -1;
			ind_local_tm_time = -1;
			ind_transmission_datetime = -1;
			ind_transaction_amount = -1;
			ind_transaction_ccy = -1;

                        /* EXEC SQL WHENEVER NOTFOUND DO break; */ 

                        /* EXEC SQL FETCH :c_cursor_id
                	INTO :v_txn_id:ind_txn_id,
			     :v_org_txn_id:ind_org_txn_id,
			     :v_service_code:ind_service_code,
			     :v_mmc_node_id:ind_mmc_node_id,
			     :v_status:ind_status,
			     :v_ar_ind:ind_ar_ind,
			     :v_internal_code:ind_internal_code,
		   	     :v_response_code:ind_response_code,
			     :v_txn_code:ind_txn_code,
			     :v_process_type:ind_process_type,
			     :v_process_code:ind_process_code,
			     :v_host_posting_date:ind_host_posting_date,
			     :v_tm_date:ind_tm_date,
			     :v_tm_time:ind_tm_time,
			     :v_local_tm_date:ind_local_tm_date,
			     :v_local_tm_time:ind_local_tm_time,
			     :v_transmission_datetime:ind_transmission_datetime,
			     :v_transaction_amount:ind_transaction_amount,
			     :v_transaction_ccy:ind_transaction_ccy; */ 

{
                        struct sqlexd sqlstm;
                        sqlstm.sqlvsn = 12;
                        sqlstm.arrsiz = 35;
                        sqlstm.sqladtp = &sqladt;
                        sqlstm.sqltdsp = &sqltds;
                        sqlstm.iters = (unsigned int  )1;
                        sqlstm.offset = (unsigned int  )990;
                        sqlstm.selerr = (unsigned short)1;
                        sqlstm.cud = sqlcud0;
                        sqlstm.sqlest = (unsigned char  *)&sqlca;
                        sqlstm.sqlety = (unsigned short)4352;
                        sqlstm.occurs = (unsigned int  )0;
                        sqlstm.sqfoff = (         int )0;
                        sqlstm.sqfmod = (unsigned int )2;
                        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
                        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
                        sqlstm.sqhsts[0] = (         int  )0;
                        sqlstm.sqindv[0] = (         short *)0;
                        sqlstm.sqinds[0] = (         int  )0;
                        sqlstm.sqharm[0] = (unsigned long )0;
                        sqlstm.sqadto[0] = (unsigned short )0;
                        sqlstm.sqtdso[0] = (unsigned short )0;
                        sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
                        sqlstm.sqhstl[1] = (unsigned long )19;
                        sqlstm.sqhsts[1] = (         int  )0;
                        sqlstm.sqindv[1] = (         short *)&ind_txn_id;
                        sqlstm.sqinds[1] = (         int  )0;
                        sqlstm.sqharm[1] = (unsigned long )0;
                        sqlstm.sqadto[1] = (unsigned short )0;
                        sqlstm.sqtdso[1] = (unsigned short )0;
                        sqlstm.sqhstv[2] = (unsigned char  *)&v_org_txn_id;
                        sqlstm.sqhstl[2] = (unsigned long )19;
                        sqlstm.sqhsts[2] = (         int  )0;
                        sqlstm.sqindv[2] = (         short *)&ind_org_txn_id;
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
                        sqlstm.sqhstv[4] = (unsigned char  *)&v_mmc_node_id;
                        sqlstm.sqhstl[4] = (unsigned long )8;
                        sqlstm.sqhsts[4] = (         int  )0;
                        sqlstm.sqindv[4] = (         short *)&ind_mmc_node_id;
                        sqlstm.sqinds[4] = (         int  )0;
                        sqlstm.sqharm[4] = (unsigned long )0;
                        sqlstm.sqadto[4] = (unsigned short )0;
                        sqlstm.sqtdso[4] = (unsigned short )0;
                        sqlstm.sqhstv[5] = (unsigned char  *)&v_status;
                        sqlstm.sqhstl[5] = (unsigned long )1;
                        sqlstm.sqhsts[5] = (         int  )0;
                        sqlstm.sqindv[5] = (         short *)&ind_status;
                        sqlstm.sqinds[5] = (         int  )0;
                        sqlstm.sqharm[5] = (unsigned long )0;
                        sqlstm.sqadto[5] = (unsigned short )0;
                        sqlstm.sqtdso[5] = (unsigned short )0;
                        sqlstm.sqhstv[6] = (unsigned char  *)&v_ar_ind;
                        sqlstm.sqhstl[6] = (unsigned long )1;
                        sqlstm.sqhsts[6] = (         int  )0;
                        sqlstm.sqindv[6] = (         short *)&ind_ar_ind;
                        sqlstm.sqinds[6] = (         int  )0;
                        sqlstm.sqharm[6] = (unsigned long )0;
                        sqlstm.sqadto[6] = (unsigned short )0;
                        sqlstm.sqtdso[6] = (unsigned short )0;
                        sqlstm.sqhstv[7] = (unsigned char  *)&v_internal_code;
                        sqlstm.sqhstl[7] = (unsigned long )sizeof(long);
                        sqlstm.sqhsts[7] = (         int  )0;
                        sqlstm.sqindv[7] = (         short *)&ind_internal_code;
                        sqlstm.sqinds[7] = (         int  )0;
                        sqlstm.sqharm[7] = (unsigned long )0;
                        sqlstm.sqadto[7] = (unsigned short )0;
                        sqlstm.sqtdso[7] = (unsigned short )0;
                        sqlstm.sqhstv[8] = (unsigned char  *)&v_response_code;
                        sqlstm.sqhstl[8] = (unsigned long )7;
                        sqlstm.sqhsts[8] = (         int  )0;
                        sqlstm.sqindv[8] = (         short *)&ind_response_code;
                        sqlstm.sqinds[8] = (         int  )0;
                        sqlstm.sqharm[8] = (unsigned long )0;
                        sqlstm.sqadto[8] = (unsigned short )0;
                        sqlstm.sqtdso[8] = (unsigned short )0;
                        sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_code;
                        sqlstm.sqhstl[9] = (unsigned long )6;
                        sqlstm.sqhsts[9] = (         int  )0;
                        sqlstm.sqindv[9] = (         short *)&ind_txn_code;
                        sqlstm.sqinds[9] = (         int  )0;
                        sqlstm.sqharm[9] = (unsigned long )0;
                        sqlstm.sqadto[9] = (unsigned short )0;
                        sqlstm.sqtdso[9] = (unsigned short )0;
                        sqlstm.sqhstv[10] = (unsigned char  *)&v_process_type;
                        sqlstm.sqhstl[10] = (unsigned long )7;
                        sqlstm.sqhsts[10] = (         int  )0;
                        sqlstm.sqindv[10] = (         short *)&ind_process_type;
                        sqlstm.sqinds[10] = (         int  )0;
                        sqlstm.sqharm[10] = (unsigned long )0;
                        sqlstm.sqadto[10] = (unsigned short )0;
                        sqlstm.sqtdso[10] = (unsigned short )0;
                        sqlstm.sqhstv[11] = (unsigned char  *)&v_process_code;
                        sqlstm.sqhstl[11] = (unsigned long )9;
                        sqlstm.sqhsts[11] = (         int  )0;
                        sqlstm.sqindv[11] = (         short *)&ind_process_code;
                        sqlstm.sqinds[11] = (         int  )0;
                        sqlstm.sqharm[11] = (unsigned long )0;
                        sqlstm.sqadto[11] = (unsigned short )0;
                        sqlstm.sqtdso[11] = (unsigned short )0;
                        sqlstm.sqhstv[12] = (unsigned char  *)&v_host_posting_date;
                        sqlstm.sqhstl[12] = (unsigned long )11;
                        sqlstm.sqhsts[12] = (         int  )0;
                        sqlstm.sqindv[12] = (         short *)&ind_host_posting_date;
                        sqlstm.sqinds[12] = (         int  )0;
                        sqlstm.sqharm[12] = (unsigned long )0;
                        sqlstm.sqadto[12] = (unsigned short )0;
                        sqlstm.sqtdso[12] = (unsigned short )0;
                        sqlstm.sqhstv[13] = (unsigned char  *)&v_tm_date;
                        sqlstm.sqhstl[13] = (unsigned long )11;
                        sqlstm.sqhsts[13] = (         int  )0;
                        sqlstm.sqindv[13] = (         short *)&ind_tm_date;
                        sqlstm.sqinds[13] = (         int  )0;
                        sqlstm.sqharm[13] = (unsigned long )0;
                        sqlstm.sqadto[13] = (unsigned short )0;
                        sqlstm.sqtdso[13] = (unsigned short )0;
                        sqlstm.sqhstv[14] = (unsigned char  *)&v_tm_time;
                        sqlstm.sqhstl[14] = (unsigned long )9;
                        sqlstm.sqhsts[14] = (         int  )0;
                        sqlstm.sqindv[14] = (         short *)&ind_tm_time;
                        sqlstm.sqinds[14] = (         int  )0;
                        sqlstm.sqharm[14] = (unsigned long )0;
                        sqlstm.sqadto[14] = (unsigned short )0;
                        sqlstm.sqtdso[14] = (unsigned short )0;
                        sqlstm.sqhstv[15] = (unsigned char  *)&v_local_tm_date;
                        sqlstm.sqhstl[15] = (unsigned long )11;
                        sqlstm.sqhsts[15] = (         int  )0;
                        sqlstm.sqindv[15] = (         short *)&ind_local_tm_date;
                        sqlstm.sqinds[15] = (         int  )0;
                        sqlstm.sqharm[15] = (unsigned long )0;
                        sqlstm.sqadto[15] = (unsigned short )0;
                        sqlstm.sqtdso[15] = (unsigned short )0;
                        sqlstm.sqhstv[16] = (unsigned char  *)&v_local_tm_time;
                        sqlstm.sqhstl[16] = (unsigned long )9;
                        sqlstm.sqhsts[16] = (         int  )0;
                        sqlstm.sqindv[16] = (         short *)&ind_local_tm_time;
                        sqlstm.sqinds[16] = (         int  )0;
                        sqlstm.sqharm[16] = (unsigned long )0;
                        sqlstm.sqadto[16] = (unsigned short )0;
                        sqlstm.sqtdso[16] = (unsigned short )0;
                        sqlstm.sqhstv[17] = (unsigned char  *)&v_transmission_datetime;
                        sqlstm.sqhstl[17] = (unsigned long )17;
                        sqlstm.sqhsts[17] = (         int  )0;
                        sqlstm.sqindv[17] = (         short *)&ind_transmission_datetime;
                        sqlstm.sqinds[17] = (         int  )0;
                        sqlstm.sqharm[17] = (unsigned long )0;
                        sqlstm.sqadto[17] = (unsigned short )0;
                        sqlstm.sqtdso[17] = (unsigned short )0;
                        sqlstm.sqhstv[18] = (unsigned char  *)&v_transaction_amount;
                        sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                        sqlstm.sqhsts[18] = (         int  )0;
                        sqlstm.sqindv[18] = (         short *)&ind_transaction_amount;
                        sqlstm.sqinds[18] = (         int  )0;
                        sqlstm.sqharm[18] = (unsigned long )0;
                        sqlstm.sqadto[18] = (unsigned short )0;
                        sqlstm.sqtdso[18] = (unsigned short )0;
                        sqlstm.sqhstv[19] = (unsigned char  *)&v_transaction_ccy;
                        sqlstm.sqhstl[19] = (unsigned long )6;
                        sqlstm.sqhsts[19] = (         int  )0;
                        sqlstm.sqindv[19] = (         short *)&ind_transaction_ccy;
                        sqlstm.sqinds[19] = (         int  )0;
                        sqlstm.sqharm[19] = (unsigned long )0;
                        sqlstm.sqadto[19] = (unsigned short )0;
                        sqlstm.sqtdso[19] = (unsigned short )0;
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
                        if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}



                        if (SQLCODE == SQL_NOT_FOUND) {
                                break;
                        }
		
			if (ind_txn_id >= 0) {
	                        v_txn_id.arr[v_txn_id.len] ='\0';
				PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] txn_id = [%.*s]\n",iCnt, v_txn_id.len, v_txn_id.arr));
			}

			if (ind_org_txn_id >= 0) {
	                        v_org_txn_id.arr[v_org_txn_id.len] ='\0';
				PutField_CString(myHash,"org_txn_seq",(const char*)v_org_txn_id.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] org_txn_id = [%.*s]\n",iCnt, v_org_txn_id.len, v_org_txn_id.arr));
			}

			if (ind_service_code >= 0) {
                        	v_service_code.arr[v_service_code.len] ='\0';
				PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] service_code = [%.*s]\n",iCnt, v_service_code.len, v_service_code.arr));
                	}

                	if (ind_mmc_node_id >= 0) {
				v_mmc_node_id.arr[v_mmc_node_id.len] ='\0';
	                        PutField_CString(myHash,"mmc_node_id",(const char*)v_mmc_node_id.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] mmc_node_id = [%.*s]\n",iCnt, v_mmc_node_id.len, v_mmc_node_id.arr));
			}

			if (ind_status >= 0) {
				PutField_Char(myHash,"status",v_status); 
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] status = [%c]\n",iCnt, v_status));
			}

                	if (ind_ar_ind >= 0) {
	                        PutField_Char(myHash,"ar_ind",v_ar_ind);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] ar_ind = [%c]\n",iCnt, v_ar_ind));
			}

                	if (ind_internal_code >= 0) {
	                        PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] internal_code = [%d]\n",v_internal_code));
                	}

                	if (ind_response_code >= 0) {
                        	v_response_code.arr[v_response_code.len] ='\0';
				PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] response_code = [%.*s]\n",iCnt, v_response_code.len, v_response_code.arr));
                	}

                	if (ind_txn_code >= 0) {
                        	v_txn_code.arr[v_txn_code.len] ='\0';
	                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] txn_code = [%.*s]\n", iCnt, v_txn_code.len, v_txn_code.arr));
                	}

                	if (ind_process_type >= 0) {
                        	v_process_type.arr[v_process_type.len] ='\0';
	                        PutField_CString(myHash,"process_type",(const char*)v_process_type.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] process_type = [%.*s]\n",iCnt, v_process_type.len, v_process_type.arr));
                	}

                	if (ind_process_code >= 0) {
                        	v_process_code.arr[v_process_code.len] ='\0';
				PutField_CString(myHash,"process_code",(const char*)v_process_code.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] process_code = [%.*s]\n",iCnt, v_process_code.len, v_process_code.arr));
                	}

                	if (ind_host_posting_date >= 0) {
                        	v_host_posting_date.arr[v_host_posting_date.len] ='\0';
				PutField_CString(myHash,"host_posting_date",(const char*)v_host_posting_date.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] host_posting_date = [%.*s]\n",iCnt, v_host_posting_date.len, v_host_posting_date.arr));
                	}

                	if (ind_tm_date >= 0) {
                        	v_tm_date.arr[v_tm_date.len] ='\0';
	                        PutField_CString(myHash,"tm_date",(const char*)v_tm_date.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] tm_date = [%.*s]\n",iCnt, v_tm_date.len, v_tm_date.arr));
                	}

                	if (ind_tm_time >= 0) {
                        	v_tm_time.arr[v_tm_time.len] ='\0';
	                        PutField_CString(myHash,"tm_time",(const char*)v_tm_time.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] tm_time = [%.*s]\n",iCnt, v_tm_time.len, v_tm_time.arr));
                	}

                	if (ind_local_tm_date >= 0) {
                        	v_local_tm_date.arr[v_local_tm_date.len] ='\0';
	                        PutField_CString(myHash,"local_tm_date",(const char*)v_local_tm_date.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] local_tm_date = [%.*s]\n",iCnt, v_local_tm_date.len, v_local_tm_date.arr));
                	}

                	if (ind_local_tm_time >= 0) {
                        	v_local_tm_time.arr[v_local_tm_time.len] ='\0';
	                        PutField_CString(myHash,"local_tm_time",(const char*)v_local_tm_time.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] local_tm_time = [%.*s]\n", iCnt, v_local_tm_time.len, v_local_tm_time.arr));
                	}

                	if (ind_transmission_datetime >= 0) {
                        	v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
	                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] transmission_date_time = [%.*s]\n",iCnt, v_transmission_datetime.len, v_transmission_datetime.arr));
                	}

                	if (ind_transaction_amount < 0) {
                        	v_transaction_amount = 0.0;
                	}
                	PutField_Double(myHash, "txn_amt", v_transaction_amount);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] txn_amt = [%f]\n",iCnt, v_transaction_amount));

                	if (ind_transaction_ccy >= 0) {
                        	v_transaction_ccy.arr[v_transaction_ccy.len] ='\0';
	                        PutField_CString(myHash,"txn_ccy",(const char*)v_transaction_ccy.arr);
DEBUGLOG(("GetMmsTxnHeaderRec [%05d] txn_ccy = [%.*s]\n",iCnt, v_transaction_ccy.len, v_transaction_ccy.arr));
                	}

			iCnt++;
                        RecordSet_Add(myRec, myHash);
		}

		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 35;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1085;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}


DEBUGLOG(("GetMmsTxnHeaderRec Normal Exit\n"));
		return iRet;
	} 
	else if (hv_return_value == SP_OTHER_ERR) {
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 35;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1104;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}


DEBUGLOG(("GetMmsTxnHeaderRec Exit with error\n"));
		return PD_ERR;
	}
	else {
		/* EXEC SQL CLOSE :c_cursor_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 35;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1123;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
  if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}


DEBUGLOG(("GetMmsTxnHeaderRec Normal Exit, no record found\n"));
		return PD_OK;
	}
	/* EXEC SQL CLOSE :c_cursor_id; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1142;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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
 if (sqlca.sqlcode < 0) goto getmmstxnheaderrec_error;
}


DEBUGLOG(("RET = [%d]\n", iRet));
	return iRet;

getmmstxnheaderrec_error:
DEBUGLOG(("getmmstxnheaderrec_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("MmsTransaction_GetMmsTxnHeaderRec: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE :c_cursor_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1161;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&c_cursor_id;
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

int	GetNextBatchId(const char *csTxnID,
			int	*iBatchID)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO getnextbatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		int	v_batch_id;
		short	ind_batch_id;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen((const char*)csTxnID);
        memcpy(hv_txn_id.arr, csTxnID, hv_txn_id.len);
DEBUGLOG(("GetNextBatchId txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));

        /* EXEC SQL SELECT NVL(max(mtd_batch_id), 0) + 1
                   INTO :v_batch_id:ind_batch_id
                FROM mms_txn_detail
                WHERE mtd_txn_id = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select NVL ( max ( mtd_batch_id ) , 0 ) + 1 INTO :b0\
:b1 FROM mms_txn_detail WHERE mtd_txn_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1180;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_batch_id;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_batch_id;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
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
        if (sqlca.sqlcode < 0) goto getnextbatchid_error;
}



        if (ind_batch_id >= 0) {
DEBUGLOG(("GetNextBatchId get batch_id\n"));
		*iBatchID = v_batch_id;
DEBUGLOG(("GetNextBatchId batch_id = [%d]\n",*iBatchID));
                return PD_OK;
        }
DEBUGLOG(("GEtNextBatchId not found\n"));
        return PD_ERR; 
getnextbatchid_error:
DEBUGLOG(("getnextbatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}


int GetMmsTxnDetailByBatchId(const char *csTxnId,
				const char *csDtlTxnId,
				const int  iBatchID,
				recordset_t *myRec)
{
        int     iCnt = 0;

        hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndetailbybatchid_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_dtl_txn_id[PD_MMS_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[38]; } hv_dtl_txn_id;

                int             hv_batch_id;

                /* varchar         v_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_dtl_txn_id;

                /* varchar         v_org_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_org_dtl_txn_id;

                /* varchar         v_init_channel[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_init_channel;

                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                char            v_isd_ind;
                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

                /* varchar         v_mb_id[PD_MB_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_mb_id;

                /* varchar         v_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_bank_id;

                /* varchar         v_stl_bank_id[PD_BANK_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_stl_bank_id;

                /* varchar         v_party_node_id[PD_MMS_NODE_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_party_node_id;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                /* varchar         v_src_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_src_party_type;

                /* varchar         v_dst_party_type[PD_MMS_PARTY_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_dst_party_type;

		int             v_carry_forward_ind;
                /* varchar         v_dc_type[PD_MMS_DC_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_dc_type;

                char            v_status;
                /* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

                double          v_txn_amt;
                /* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double          v_adjustment;
                double          v_exchange_rate;
                double          v_processing_cost;
                double          v_bank_charge;
                double          v_bank_charge_refund;
                /* varchar         v_filing_number[PD_MMS_FILING_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_filing_number;

                /* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_version_no[PD_VERSION_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_version_no;

                /* varchar         v_encrypt_type[PD_ENCRYPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_encrypt_type;

                long            v_internal_code;
                /* varchar         v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_response_code;

                /* varchar         v_prev_dtl_txn_id[PD_MMS_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[39]; } v_prev_dtl_txn_id;



                short           ind_dtl_txn_id = -1;
                short           ind_org_dtl_txn_id = -1;
                short           ind_init_channel = -1;
                short           ind_txn_code = -1;
                short           ind_isd_ind = -1;
                short           ind_merchant_id = -1;
                short           ind_psp_id = -1;
                short           ind_mb_id = -1;
                short           ind_bank_id = -1;
                short           ind_stl_bank_id = -1;
                short           ind_party_node_id = -1;
                short           ind_service_code = -1;
                short           ind_src_party_type = -1;
                short           ind_dst_party_type = -1;
                short           ind_carry_forward_ind = -1;
                short           ind_dc_type = -1;
                short           ind_status = -1;
                short           ind_transmission_datetime = -1;
                short           ind_txn_amt = -1;
                short           ind_txn_ccy = -1;
                short           ind_adjustment = -1;
                short           ind_exchange_rate = -1;
                short           ind_processing_cost = -1;
                short           ind_bank_charge = -1;
                short           ind_bank_charge_refund = -1;
                short           ind_filing_number = -1;
                short           ind_txn_country = -1;
                short           ind_version_no = -1;
                short           ind_encrypt_type = -1;
                short           ind_internal_code = -1;
                short           ind_response_code = -1;
                short           ind_prev_dtl_txn_id = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("START GetMmsTxnDetailByBatchId \n")); 

        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("GetMmsTxnDetailByBatchId txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_dtl_txn_id.len = strlen(csDtlTxnId);
        memcpy(hv_dtl_txn_id.arr,csDtlTxnId,hv_dtl_txn_id.len);
DEBUGLOG(("GetMmsTxnDetailByBatchId dtl_txn_id = [%.*s]\n",hv_dtl_txn_id.len,hv_dtl_txn_id.arr));

	hv_batch_id = iBatchID;
DEBUGLOG(("GetMmsTxnDetailByBatchId batch_id = [%d]\n", hv_batch_id)); 

        /* EXEC SQL DECLARE c_cursor_gettxndetailbybatchid CURSOR FOR
                select mtd_dtl_txn_id,
                       mtd_org_dtl_txn_id,
                       mtd_init_channel,
                       mtd_txn_code,
                       mtd_isd_ind,
                       mtd_merchant_id,
                       mtd_psp_id,
                       mtd_mb_id,
                       mtd_bank_id,
                       mtd_stl_bank_id,
                       mtd_party_node_id,
                       mtd_service_code,
                       mtd_src_party_type,
                       mtd_dst_party_type,
                       mtd_carry_forward_ind,
                       mtd_dc_type,
                       mtd_status,
                       mtd_transmission_datetime,
                       mtd_txn_amt,
                       mtd_txn_ccy,
                       mtd_adjustment,
                       mtd_exchange_rate,
                       mtd_processing_cost,
                       mtd_bank_charge,
                       mtd_bank_charge_refund,
                       mtd_filing_number,
                       mtd_country,
                       mtd_version_no,
                       mtd_encrypt_type,
                       mtd_internal_code,
                       mtd_response_code,
                       mtd_prev_dtl_txn_id
                 from mms_txn_detail
                where mtd_txn_id = :hv_txn_id
                  and mtd_batch_id = :hv_batch_id
		  and mtd_dtl_txn_id < :hv_dtl_txn_id
		order by mtd_dtl_txn_id desc; */ 
 

        /* EXEC SQL OPEN c_cursor_gettxndetailbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0012;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1203;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_dtl_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )40;
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
        if (sqlca.sqlcode < 0) goto gettxndetailbybatchid_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxndetailbybatchid
                INTO    :v_dtl_txn_id:ind_dtl_txn_id,
                        :v_org_dtl_txn_id:ind_org_dtl_txn_id,
                        :v_init_channel:ind_init_channel,
                        :v_txn_code:ind_txn_code,
                        :v_isd_ind:ind_isd_ind,
                        :v_merchant_id:ind_merchant_id,
                        :v_psp_id:ind_psp_id,
                        :v_mb_id:ind_mb_id,
                        :v_bank_id:ind_bank_id,
                        :v_stl_bank_id:ind_stl_bank_id,
                        :v_party_node_id:ind_party_node_id,
                        :v_service_code:ind_service_code,
                        :v_src_party_type:ind_src_party_type,
                        :v_dst_party_type:ind_dst_party_type,
                        :v_carry_forward_ind:ind_carry_forward_ind,
                        :v_dc_type:ind_dc_type,
                        :v_status:ind_status,
                        :v_transmission_datetime:ind_transmission_datetime,
                        :v_txn_amt:ind_txn_amt,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_adjustment:ind_adjustment,
                        :v_exchange_rate:ind_exchange_rate,
                        :v_processing_cost:ind_processing_cost,
                        :v_bank_charge:ind_bank_charge,
                        :v_bank_charge_refund:ind_bank_charge_refund,
                        :v_filing_number:ind_filing_number,
                        :v_txn_country:ind_txn_country,
                        :v_version_no:ind_version_no,
                        :v_encrypt_type:ind_encrypt_type,
                        :v_internal_code:ind_internal_code,
                        :v_response_code :ind_response_code,
                        :v_prev_dtl_txn_id:ind_prev_dtl_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 35;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1230;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_dtl_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )41;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_dtl_txn_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_org_dtl_txn_id;
                sqlstm.sqhstl[1] = (unsigned long )41;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_org_dtl_txn_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_init_channel;
                sqlstm.sqhstl[2] = (unsigned long )6;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_init_channel;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_txn_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_isd_ind;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_isd_ind;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[5] = (unsigned long )18;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_id;
                sqlstm.sqhstl[6] = (unsigned long )13;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_psp_id;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_mb_id;
                sqlstm.sqhstl[7] = (unsigned long )18;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_mb_id;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_id;
                sqlstm.sqhstl[8] = (unsigned long )18;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_bank_id;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_stl_bank_id;
                sqlstm.sqhstl[9] = (unsigned long )18;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_stl_bank_id;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_party_node_id;
                sqlstm.sqhstl[10] = (unsigned long )8;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_party_node_id;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_service_code;
                sqlstm.sqhstl[11] = (unsigned long )6;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_service_code;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_src_party_type;
                sqlstm.sqhstl[12] = (unsigned long )8;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_src_party_type;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_dst_party_type;
                sqlstm.sqhstl[13] = (unsigned long )8;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_dst_party_type;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_carry_forward_ind;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_carry_forward_ind;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_dc_type;
                sqlstm.sqhstl[15] = (unsigned long )5;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_dc_type;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[16] = (unsigned long )1;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_status;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_transmission_datetime;
                sqlstm.sqhstl[17] = (unsigned long )17;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_transmission_datetime;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[19] = (unsigned long )6;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_adjustment;
                sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_adjustment;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_exchange_rate;
                sqlstm.sqhstl[21] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_exchange_rate;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_processing_cost;
                sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_processing_cost;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_bank_charge;
                sqlstm.sqhstl[23] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_bank_charge;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_bank_charge_refund;
                sqlstm.sqhstl[24] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_bank_charge_refund;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_filing_number;
                sqlstm.sqhstl[25] = (unsigned long )53;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_filing_number;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[26] = (unsigned long )5;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_txn_country;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_version_no;
                sqlstm.sqhstl[27] = (unsigned long )5;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_version_no;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_encrypt_type;
                sqlstm.sqhstl[28] = (unsigned long )7;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_encrypt_type;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[29] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_internal_code;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[30] = (unsigned long )7;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_response_code;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_prev_dtl_txn_id;
                sqlstm.sqhstl[31] = (unsigned long )41;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_prev_dtl_txn_id;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto gettxndetailbybatchid_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* dtl_txn_seq */
                if (ind_dtl_txn_id >= 0) {
                        v_dtl_txn_id.arr[v_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"dtl_txn_seq",(const char*)v_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId dtl_txn_seq = [%s]\n",v_dtl_txn_id.arr));
                }
/* org_dtl_txn_seq */
                if (ind_org_dtl_txn_id >= 0) {
                        v_org_dtl_txn_id.arr[v_org_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"org_dtl_txn_seq",(const char*)v_org_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId org_dtl_txn_seq = [%s]\n",v_org_dtl_txn_id.arr));
                }

/* init_channel */
                if (ind_init_channel >= 0) {
                        v_init_channel.arr[v_init_channel.len] ='\0';
                        PutField_CString(myHash,"init_channel",(const char*)v_init_channel.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId init_channel = [%s]\n",v_init_channel.arr));
                }

/* txn_code */
                if (ind_txn_code >= 0) {
                        v_txn_code.arr[v_txn_code.len] ='\0';
                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId txn_code = [%s]\n",v_txn_code.arr));
                }

/* isd_ind */
                if (ind_isd_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetailByBatchId isd_ind = [%c]\n",v_isd_ind));
                        PutField_Char(myHash,"isd_ind",v_isd_ind);
                }
/* merchant_id */
                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId merchant_id = [%s]\n",v_merchant_id.arr));
                }

/* psp_id */
                if (ind_psp_id >= 0) {
                        v_psp_id.arr[v_psp_id.len] ='\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId psp_id = [%s]\n",v_psp_id.arr));
                }

/* mb_id */
                if (ind_mb_id >= 0) {
                        v_mb_id.arr[v_mb_id.len] ='\0';
                        PutField_CString(myHash,"mb_id",(const char*)v_mb_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId mb_id = [%s]\n",v_mb_id.arr));
                }

/* bank_id */
                if (ind_bank_id >= 0) {
                        v_bank_id.arr[v_bank_id.len] ='\0';
                        PutField_CString(myHash,"bank_id",(const char*)v_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId bank_id = [%s]\n",v_bank_id.arr));
                }
/* stl_bank_id */
                if (ind_stl_bank_id >= 0) {
                        v_stl_bank_id.arr[v_stl_bank_id.len] ='\0';
                        PutField_CString(myHash,"stl_bank_id",(const char*)v_stl_bank_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId stl_bank_id = [%s]\n",v_stl_bank_id.arr));
                }
/* party_node_id */
                if (ind_party_node_id >= 0) {
                        v_party_node_id.arr[v_party_node_id.len] ='\0';
                        PutField_CString(myHash,"party_node_id",(const char*)v_party_node_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId party_node_id = [%s]\n",v_party_node_id.arr));
                }

/* service_code */
                if (ind_service_code >= 0) {
                        v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId service_code = [%s]\n",v_service_code.arr));
                }

/* src_party_type */
                if (ind_src_party_type >= 0) {
                        v_src_party_type.arr[v_src_party_type.len] ='\0';
                        PutField_CString(myHash,"src_party_type",(const char*)v_src_party_type.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId src_party_type = [%s]\n",v_src_party_type.arr));
                }
/* dst_party_type */
                if (ind_dst_party_type >= 0) {
                        v_dst_party_type.arr[v_dst_party_type.len] ='\0';
                        PutField_CString(myHash,"dst_party_type",(const char*)v_dst_party_type.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId dst_party_type = [%s]\n",v_dst_party_type.arr));
                }

/* carry_forward_ind */
                if (ind_carry_forward_ind >= 0) {
DEBUGLOG(("GetMmsTxnDetailByBatchId carry_forward_ind = [%d]\n",v_carry_forward_ind));
                        PutField_Int(myHash,"carry_forward_ind",v_carry_forward_ind);
                }

/* dc_type */
                if (ind_dc_type >= 0) {
                        v_dc_type.arr[v_dc_type.len] ='\0';
                        PutField_CString(myHash,"dc_type",(const char*)v_dc_type.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId dc_type = [%s]\n",v_dc_type.arr));
                }

/* status */
                if (ind_status >= 0) {
DEBUGLOG(("GetMmsTxnDetailByBatchId status = [%c]\n",v_status));
                        PutField_Char(myHash,"status",v_status);
                }
/* transmission_datetime */
                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId transmission_date_time = [%s]\n",v_transmission_datetime.arr));
                }


/* txn_amt */
                if (ind_txn_amt < 0) {
                        v_txn_amt = 0.0;
                }
                PutField_Double(myHash, "txn_amt", v_txn_amt);
DEBUGLOG(("GetMmsTxnDetailByBatchId txn_amt = [%f]\n",v_txn_amt));

/* txn_ccy */
                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

/* adjustment */
                if (ind_adjustment < 0) {
                        v_adjustment = 0.0;
                }
                PutField_Double(myHash, "adjustment", v_adjustment);
DEBUGLOG(("GetMmsTxnDetailByBatchId adjustment = [%f]\n",v_adjustment));

/* exchange_rate */
                if (ind_exchange_rate < 0) {
                        v_exchange_rate = 1.0;
                }
                PutField_Double(myHash, "exchange_rate", v_exchange_rate);
DEBUGLOG(("GetMmsTxnDetailByBatchId exchange_rate = [%f]\n",v_exchange_rate));

/* processing_cost */
                if (ind_processing_cost < 0) {
                        v_processing_cost = 0.0;
                }
                PutField_Double(myHash, "processing_cost", v_processing_cost);
DEBUGLOG(("GetMmsTxnDetailByBatchId processing_cost = [%f]\n",v_processing_cost));

/* bank_charge */
                if (ind_bank_charge < 0) {
                        v_bank_charge = 0.0;
                }
                PutField_Double(myHash, "bank_charge", v_bank_charge);
DEBUGLOG(("GetMmsTxnDetailByBatchId bank_charge = [%f]\n",v_bank_charge));

/* bank_charge_refund */
                if (ind_bank_charge_refund < 0) {
                        v_bank_charge_refund = 0.0;
                }
                PutField_Double(myHash, "bank_charge_refund", v_bank_charge_refund);
DEBUGLOG(("GetMmsTxnDetailByBatchId bank_charge_refund = [%f]\n",v_bank_charge_refund));
/* filing_number */
                if (ind_filing_number >= 0) {
                        v_filing_number.arr[v_filing_number.len] ='\0';
                        PutField_CString(myHash,"filing_number",(const char*)v_filing_number.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId filing_number = [%s]\n",v_filing_number.arr));
                }

/* txn_country */
                if (ind_txn_country  >=  0) {
                        v_txn_country.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId txn_country = [%s]\n",v_txn_country.arr));
                }

/* version_no */
                if (ind_version_no >=  0) {
                        v_version_no.arr[v_version_no.len] = '\0';
                        PutField_CString(myHash,"version_no",(const char*)v_version_no.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId version_no = [%s]\n",v_version_no.arr));
                }

/* encrypt_type */
                if (ind_encrypt_type >=  0) {
                        v_encrypt_type.arr[v_encrypt_type.len] = '\0';
                        PutField_CString(myHash,"encrypt_type",(const char*)v_encrypt_type.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId encrypt_type = [%s]\n",v_encrypt_type.arr));
                }
/* internal_code */
                if (ind_internal_code >= 0) {
                        PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetMmsTxnDetailByBatchId internal_code = [%d]\n",v_internal_code));
                }

/* response_code */
                if (ind_response_code >= 0) {
                        v_response_code.arr[v_response_code.len] ='\0';
                        PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId response_code = [%s]\n",v_response_code.arr));
                }


/* prev_dtl_txn_id */
                if (ind_prev_dtl_txn_id >= 0) {
                        v_prev_dtl_txn_id.arr[v_prev_dtl_txn_id.len] ='\0';
                        PutField_CString(myHash,"prev_dtl_txn_id",(const char*)v_prev_dtl_txn_id.arr);
DEBUGLOG(("GetMmsTxnDetailByBatchId prev_dtl_txn_id = [%s]\n",v_prev_dtl_txn_id.arr));
                }



                RecordSet_Add(myRec, myHash);
        }
        while (PD_TRUE);
        /* EXEC SQL CLOSE c_cursor_gettxndetailbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1373;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxndetailbybatchid_error;
}



        if (iCnt > 0 ) {
DEBUGLOG(("GetMmsTxnDetailByBatchId Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetMmsTxnDetailByBatchId Normal Exit, Not Found\n"));
                return PD_ERR;
        }


gettxndetailbybatchid_error:
DEBUGLOG(("gettxndetailbybatchid_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxndetailbybatchid; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 35;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1388;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;

}

int CheckPendingTxnByTxnId(const char *csTxnId)
{
	int     iRet = PD_NOT_FOUND;


	/* EXEC SQL WHENEVER SQLERROR GOTO chkpendingtxnbytxnid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_seq[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_seq;


		int             v_no_of_record;
		short           ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_seq.len = strlen(csTxnId);
	memcpy(hv_txn_seq.arr, csTxnId, hv_txn_seq.len);
DEBUGLOG(("CheckPendingTxnByTxnId txn_seq = [%.*s]\n",hv_txn_seq.len,hv_txn_seq.arr));

	/* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM mms_txn_detail
		WHERE mtd_txn_id = :hv_txn_seq
		AND mtd_status = 'W'; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 35;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM mms_txn_detail WHERE mt\
d_txn_id = :b2 AND mtd_status = 'W' ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1403;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_no_of_record;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_no_of_record;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_seq;
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
 if (sqlca.sqlcode < 0) goto chkpendingtxnbytxnid_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("CheckPendingTxnByTxnId FOUND\n"));
			iRet = PD_FOUND;
		}
	}

	if (iRet != PD_FOUND) {
DEBUGLOG(("CheckPendingTxnByTxnId NOT FOUND\n"));
	}

	return iRet;

chkpendingtxnbytxnid_error:
DEBUGLOG(("CheckPendingTxnByTxnId_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;


}
			   
