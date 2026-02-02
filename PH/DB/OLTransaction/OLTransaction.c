
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
           char  filnam[17];
};
static struct sqlcxp sqlfpn =
{
    16,
    "OLTransaction.pc"
};


static unsigned int sqlctx = 5148571;


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
   unsigned char  *sqhstv[41];
   unsigned long  sqhstl[41];
            int   sqhsts[41];
            short *sqindv[41];
            int   sqinds[41];
   unsigned long  sqharm[41];
   unsigned long  *sqharc[41];
   unsigned short  sqadto[41];
   unsigned short  sqtdso[41];
} sqlstm = {12,41};

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

 static char *sq0009 = 
"select oth_org_txn_id , oth_client_id , oth_status , oth_ar_ind , oth_txn_c\
ode , oth_merchant_id , oth_merchant_ref , oth_transaction_amount , oth_net_a\
mount , oth_net_ccy , oth_transmission_datetime , oth_local_tm_date , oth_loc\
al_tm_time , oth_tm_date , oth_tm_time , oth_internal_code , oth_input_channe\
l , oth_response_code , oth_host_posting_date , oth_process_code , oth_proces\
s_type , oth_input_channel , oth_service_code , oth_client_ip , oth_ex_suppli\
er , oth_ex_rate , oth_sub_status , oth_display_amount , oth_deposit_amount ,\
 oth_dst_txn_id , oth_upload_channel , oth_multi_match_ind , oth_reserve_amou\
nt , oth_reserved_release_date , oth_recon_status from ol_txn_header where ot\
h_txn_id = :b0            ";

 static char *sq0010 = 
"select otd_txn_ccy , otd_txn_country , otd_pay_method , otd_bank_code , otd\
_language , otd_success_url , otd_failure_url , otd_success_callback_url , ot\
d_failure_callback_url , otd_encrypt_type , otd_bank_name , otd_branch_name ,\
 otd_account_id , otd_account_name , otd_batch_id , otd_identity_id , otd_rem\
ark , otd_selected_pay_method , otd_banner_logo , otd_echo_msg_1 , otd_echo_m\
sg_2 , otd_echo_msg_3 , otd_opt_1 , otd_opt_2 , otd_opt_3 , otd_bank_acct_num\
 , otd_cust_deposit_datetime , otd_bank_deposit_datetime , otd_deposit_bank ,\
 otd_deposit_bank_code , otd_deposit_ref , otd_province , otd_phone_no , otd_\
city from ol_txn_detail where otd_txn_id = :b0            ";

 static char *sq0013 = 
"select oth_display_amount FROM ( select oth_display_amount , oth_txn_id fro\
m ol_txn_header where oth_display_amount between :b0 and :b1 and oth_txn_code\
 = :b2 and oth_merchant_id = :b3 and oth_create_timestamp between sysdate - (\
 :b4 / 24 ) and sysdate ) group by oth_display_amount order by oth_display_am\
ount            ";

 static char *sq0014 = 
"select oth_display_amount FROM ( select oth_display_amount , oth_txn_id fro\
m ol_txn_header , ol_txn_psp_detail where oth_display_amount between :b0 and \
:b1 and oth_txn_code = :b2 and otp_baid = :b3 and oth_txn_id = otp_txn_id and\
 oth_create_timestamp between sysdate - ( :b4 / 24 ) and sysdate ) group by o\
th_display_amount order by oth_display_amount            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1177,0,6,400,0,0,33,33,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,1,3,0,0,
152,0,0,2,0,0,17,932,0,0,1,1,0,1,0,1,9,0,0,
171,0,0,2,0,0,21,933,0,0,0,0,0,1,0,
186,0,0,3,1379,0,6,1375,0,0,41,41,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,3,0,0,
365,0,0,2,0,0,17,1750,0,0,1,1,0,1,0,1,9,0,0,
384,0,0,2,0,0,21,1751,0,0,0,0,0,1,0,
399,0,0,4,201,0,6,1848,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,
9,0,0,
438,0,0,5,179,0,6,1957,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
473,0,0,6,350,0,6,2133,0,0,9,9,0,1,0,2,3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
524,0,0,7,437,0,6,2153,0,0,12,12,0,1,0,2,3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,9,0,0,1,9,0,0,
587,0,0,8,100,0,6,2222,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
614,0,0,9,717,0,9,2384,0,2049,1,1,0,1,0,1,9,0,0,
633,0,0,9,0,0,13,2386,0,0,35,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,
0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,3,0,0,2,3,0,0,2,4,0,0,2,9,0,0,2,1,
0,0,
788,0,0,9,0,0,15,2637,0,0,0,0,0,1,0,
803,0,0,9,0,0,15,2654,0,0,0,0,0,1,0,
818,0,0,10,672,0,9,2785,0,2049,1,1,0,1,0,1,9,0,0,
837,0,0,10,0,0,13,2787,0,0,34,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
988,0,0,10,0,0,15,3076,0,0,0,0,0,1,0,
1003,0,0,10,0,0,15,3086,0,0,0,0,0,1,0,
1018,0,0,11,115,0,4,3115,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
1045,0,0,12,104,0,4,3166,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
1072,0,0,13,322,0,9,3278,0,2049,5,5,0,1,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,3,
0,0,
1107,0,0,13,0,0,13,3280,0,0,1,0,0,1,0,2,4,0,0,
1126,0,0,13,0,0,15,3303,0,0,0,0,0,1,0,
1141,0,0,13,0,0,15,3312,0,0,0,0,0,1,0,
1156,0,0,14,363,0,9,3405,0,2049,5,5,0,1,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,3,
0,0,
1191,0,0,14,0,0,13,3407,0,0,1,0,0,1,0,2,4,0,0,
1210,0,0,14,0,0,15,3430,0,0,0,0,0,1,0,
1225,0,0,14,0,0,15,3439,0,0,0,0,0,1,0,
1240,0,0,15,404,0,4,3493,0,0,6,5,0,1,0,2,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,
1279,0,0,16,445,0,4,3570,0,0,6,5,0,1,0,2,4,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,
1318,0,0,17,0,0,17,3741,0,0,1,1,0,1,0,1,9,0,0,
1337,0,0,17,0,0,45,3744,0,0,0,0,0,1,0,
1352,0,0,17,0,0,13,3746,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,
1379,0,0,17,0,0,15,3781,0,0,0,0,0,1,0,
1394,0,0,17,0,0,15,3795,0,0,0,0,0,1,0,
1409,0,0,18,90,0,4,3817,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
1432,0,0,19,83,0,4,3862,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1455,0,0,20,90,0,4,3899,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1478,0,0,21,1123,0,4,4115,0,0,13,12,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,
0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,3,0,0,1,9,0,0,1,1,0,0,
1545,0,0,22,136,0,4,4185,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
1576,0,0,23,269,0,4,4230,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
1599,0,0,24,149,0,6,4290,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1630,0,0,25,136,0,4,4354,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,1,0,0,
1661,0,0,26,282,0,4,4410,0,0,6,5,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,1,0,0,
1,1,0,0,
1700,0,0,2,0,0,17,4483,0,0,1,1,0,1,0,1,9,0,0,
1719,0,0,2,0,0,21,4484,0,0,0,0,0,1,0,
1734,0,0,27,117,0,6,4530,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
1761,0,0,28,125,0,4,4582,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1784,0,0,29,132,0,4,4631,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
1815,0,0,30,145,0,6,4700,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1846,0,0,31,103,0,6,4758,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
1873,0,0,32,115,0,6,4813,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1904,0,0,33,136,0,4,4869,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,1,9,0,0,
1935,0,0,34,92,0,4,4912,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2013. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/13              Cody Chan
Add Unique Amount Checking                         2013/10/10              LokMan Chow
Add deposit ref in MatchStmt                       2014/03/20              David Wong
Add multi_match_ind                                2014/04/10              David Wong
Add CheckUnreconSms                                2014/06/11              David Wong
Get deposit_Bank_code for API Method 3             2014/09/02              Virginia Yun
Add functions for unique amount checking           2014/09/02              LokMan Chow
Add ChkNonReconTxnEsist                            2014/12/11              Dirk Wong
Add AddMiOLTxnLog                                  2015/11/04              Elvis Wong
Add GetTxnIdForUpdateWithStatus			   2015/12/23		   Elvis Wong
Add GetTxnIdForUpdateNoWaitWithStatus              2016/03/21              David Wong
Add UpdateTxnDetailRemark			   2016/08/02		   Dirk Wong
Add MatchPayoutMerchantRef			   2017/03/14		   David Wong
Add fields in GetTxnDetail			   2017/04/25		   Elvis Wong
Add IsPayoutAPITxn				   2017/05/04		   LokMan Chow
Add ReMatchPayoutMerchantRef			   2017/06/06		   LokMan Chow
Add Reason for Edit                                2018/10/23              Philip Yu
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "OLTransaction.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


/* char    cDebug; */
static char cDebug;
void OLTransaction(char    cdebug)
{
        cDebug = cdebug;
}

int Add(const hash_t *hRls)
{
        char		*csTmp;
        char        	cTmp;
	int		iCommit = PD_TRUE;
	int		iTmp;
	double		dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
	
	/* varchar		hv_org_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_txn_id;
	
	/* varchar		hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

	char		hv_status;
	char		hv_ar_ind;
	/* varchar		hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

	/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

	/* varchar		hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

	/* varchar		hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

	/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

	/* varchar		hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

	/* varchar		hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

	/* varchar		hv_host_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_posting_date;

	/* varchar		hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

	int		hv_internal_code;
	/* varchar		hv_response_code[PD_RESPONSE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_response_code;

	double		hv_transaction_amt;
	double		hv_deposit_amt;
	double		hv_display_amt;
	double		hv_net_amt;
	/* varchar		hv_filename[PD_UPLOAD_FILENAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_filename;

	/* varchar		hv_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_tm_date;

	/* varchar		hv_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_tm_time;

	/* varchar		hv_local_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_local_tm_date;

	/* varchar		hv_local_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_local_tm_time;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	/* varchar		hv_client_ip[PD_IP_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_client_ip;

	/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

	/* varchar		hv_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_approval_date;

	char		hv_upd_match_ts;
	int		hv_upload_channel;
	int		hv_multi_match_ind;


	short		ind_txn_id = -1;
	short		ind_org_txn_id = -1;
	short		ind_channel_code = -1;
	short		ind_status = -1;
	short		ind_ar_ind = -1;
	short		ind_sub_status = -1;
	short		ind_txn_code = -1;
	short		ind_process_type = -1;
	short		ind_process_code = -1;
	short		ind_merchant_id = -1;
	short		ind_merchant_ref = -1;
	short		ind_client_id = -1;
	short		ind_host_posting_date = -1;
	short		ind_transmission_datetime = -1;
	short		ind_internal_code = -1;
	short		ind_response_code = -1;
	short		ind_transaction_amt = -1;
	short		ind_deposit_amt = -1;
	short		ind_display_amt = -1;
	short		ind_net_amt = -1;
	short		ind_filename = -1;
	short		ind_tm_date = -1;
	short		ind_tm_time = -1;
	short		ind_local_tm_date = -1;
	short		ind_local_tm_time = -1;
	short		ind_add_user = -1;
	short		ind_client_ip= -1;
	short		ind_service_code = -1;
	short		ind_approval_date = -1;
	short		ind_upd_match_ts = -1;
	short		ind_upload_channel = -1;
	short		ind_multi_match_ind = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if (GetField_Int(hRls,"db_commit",&iCommit)) {
DEBUGLOG(("Add:db_commit = [%d]\n",iCommit));
	}

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }
/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
                hv_org_txn_id.len = strlen(csTmp);
                memcpy(hv_org_txn_id.arr,csTmp,hv_org_txn_id.len);
                ind_org_txn_id = 0;
DEBUGLOG(("Add:org_txn_id = [%.*s]\n",hv_org_txn_id.len,hv_org_txn_id.arr));
        }
/* Channel code */
        if (GetField_CString(hRls,"channel_code",&csTmp)) {
                hv_channel_code.len = strlen(csTmp);
                memcpy(hv_channel_code.arr,csTmp,hv_channel_code.len);
                ind_channel_code = 0;
DEBUGLOG(("Add:channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
        }


/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
		hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("Add:status = [%c]\n",hv_status));
        }

/* ar ind */ 
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
		hv_ar_ind = cTmp;
                ind_ar_ind = 0;
DEBUGLOG(("Add:ar_ind = [%c]\n",hv_ar_ind));
        }

/* Sub Status */ 
        if (GetField_CString(hRls,"sub_status",&csTmp)) {
                hv_sub_status.len = strlen(csTmp);
                memcpy(hv_sub_status.arr,csTmp,hv_sub_status.len);
                ind_sub_status = 0;
DEBUGLOG(("Add:sub_status = [%.*s]\n",hv_sub_status.len,hv_sub_status.arr));
        }

/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
                hv_txn_code.len = strlen(csTmp);
                memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
                ind_txn_code = 0;
DEBUGLOG(("Add:txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
                hv_process_type.len = strlen(csTmp);
                memcpy(hv_process_type.arr,csTmp,hv_process_type.len);
                ind_process_type = 0;
DEBUGLOG(("Add:process_type = [%.*s]\n",hv_process_type.len,hv_process_type.arr));
        }

/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
                hv_process_code.len = strlen(csTmp);
                memcpy(hv_process_code.arr,csTmp,hv_process_code.len);
                ind_process_code = 0;
DEBUGLOG(("Add:process_code = [%.*s]\n",hv_process_code.len,hv_process_code.arr));
        }

/* Merchant No */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
                hv_merchant_id.len = strlen(csTmp);
                memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
                ind_merchant_id = 0;
DEBUGLOG(("Add:merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
        }

/* Merchant ref */
        if (GetField_CString(hRls,"merchant_ref",&csTmp)) {
                hv_merchant_ref.len = strlen(csTmp);
                memcpy(hv_merchant_ref.arr,csTmp,hv_merchant_ref.len);
                ind_merchant_ref = 0;
DEBUGLOG(("Add:merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));
        }



/* Client ID */
        if (GetField_CString(hRls,"client_id",&csTmp)) {
                hv_client_id.len = strlen(csTmp);
                memcpy(hv_client_id.arr,csTmp,hv_client_id.len);
                ind_client_id = 0;
DEBUGLOG(("Add:client_id = [%.*s]\n",hv_client_id.len,hv_client_id.arr));
        }
/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
                hv_host_posting_date.len = strlen(csTmp);
                memcpy(hv_host_posting_date.arr,csTmp,hv_host_posting_date.len);
                ind_host_posting_date = 0;
DEBUGLOG(("Add:host_posting_date = [%.*s]\n",hv_host_posting_date.len,hv_host_posting_date.arr));
        }



/* internal code */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
		hv_internal_code = iTmp;
                ind_internal_code = 0;
DEBUGLOG(("Add:internal_code = [%d]\n",hv_internal_code));
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
                hv_response_code.len = strlen(csTmp);
                memcpy(hv_response_code.arr,csTmp,hv_response_code.len);
                ind_response_code = 0;
DEBUGLOG(("Add:response_code = [%.*s]\n",hv_response_code.len,hv_response_code.arr));
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
		hv_transaction_amt = dTmp;
                ind_transaction_amt = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_transaction_amt));
        }

/* deposit amt   */
        if (GetField_Double(hRls,"deposit_amt",&dTmp)) {
		hv_deposit_amt = dTmp;
                ind_deposit_amt = 0;
DEBUGLOG(("Add:deposit_amt = [%f]\n",hv_deposit_amt));
        }

/* display amt   */
        if (GetField_Double(hRls,"display_amt",&dTmp)) {
		hv_display_amt = dTmp;
                ind_display_amt = 0;
DEBUGLOG(("Add:display_amt = [%f]\n",hv_display_amt));
        }

/* net amt   */
        if (GetField_Double(hRls,"net_amt",&dTmp)) {
		hv_net_amt = dTmp;
                ind_net_amt = 0;
DEBUGLOG(("Add:net_amt = [%f]\n",hv_net_amt));
        }

/* filename */
        if (GetField_CString(hRls,"filename",&csTmp)) {
                hv_filename.len = strlen(csTmp);
                memcpy(hv_filename.arr,csTmp,hv_filename.len);
                ind_filename = 0;
DEBUGLOG(("Add:filename = [%.*s]\n",hv_filename.len,hv_filename.arr));
        }


/* transmission_datetime */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
                hv_transmission_datetime.len = strlen(csTmp);
                memcpy(hv_transmission_datetime.arr,csTmp,hv_transmission_datetime.len);
                ind_transmission_datetime = 0;
DEBUGLOG(("Add:transmission_datetime = [%.*s]\n",hv_transmission_datetime.len,hv_transmission_datetime.arr));
        }

/* tm date */
        if (GetField_CString(hRls,"tm_date",&csTmp)) {
                hv_tm_date.len = strlen(csTmp);
                memcpy(hv_tm_date.arr,csTmp,hv_tm_date.len);
                ind_tm_date = 0;
DEBUGLOG(("Add:tm_date = [%.*s]\n",hv_tm_date.len,hv_tm_date.arr));
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
                hv_tm_time.len = strlen(csTmp);
                memcpy(hv_tm_time.arr,csTmp,hv_tm_time.len);
                ind_tm_time = 0;
DEBUGLOG(("Add:tm_time = [%.*s]\n",hv_tm_time.len,hv_tm_time.arr));
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
                hv_local_tm_date.len = strlen(csTmp);
                memcpy(hv_local_tm_date.arr,csTmp,hv_local_tm_date.len);
                ind_local_tm_date = 0;
DEBUGLOG(("Add:local_tm_date = [%.*s]\n",hv_local_tm_date.len,hv_local_tm_date.arr));
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
                hv_local_tm_time.len = strlen(csTmp);
                memcpy(hv_local_tm_time.arr,csTmp,hv_local_tm_time.len);
                ind_local_tm_time = 0;
DEBUGLOG(("Add:local_tm_time = [%.*s]\n",hv_local_tm_time.len,hv_local_tm_time.arr));
        }



/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


/* client ip */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
		char *p;
		char    csTmpIP[PD_IP_LEN+1];
                p = strtok (csTmp,",");
                while (p != NULL)
                {
                        strcpy(csTmpIP,p);
                        csTmpIP[strlen(p)]='\0';
			break;
                }
                hv_client_ip.len = strlen(csTmpIP);
                memcpy(hv_client_ip.arr,csTmpIP,hv_client_ip.len);
                ind_client_ip = 0;
DEBUGLOG(("Add:client_ip = [%.*s]\n",hv_client_ip.len,hv_client_ip.arr));
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr,csTmp,hv_service_code.len);
                ind_service_code = 0;
DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

/* approval_date */
        if (GetField_CString(hRls,"approval_date",&csTmp)) {
                hv_approval_date.len = strlen(csTmp);
                memcpy(hv_approval_date.arr,csTmp,hv_approval_date.len);
                ind_approval_date = 0;
DEBUGLOG(("Add:approval_date = [%.*s]\n",hv_approval_date.len,hv_approval_date.arr));
        }

/* upd_match_ts */ 
		if (GetField_Char(hRls, "upd_match_ts", &cTmp)) {
			hv_upd_match_ts = cTmp;
			ind_upd_match_ts = 0;
DEBUGLOG(("Add: upd_match_ts = [%c]\n", hv_upd_match_ts));
		}


/* upload_channel */
        if (GetField_Int(hRls,"upload_channel",&iTmp)) {
		hv_upload_channel = iTmp;
                ind_upload_channel = 0;
DEBUGLOG(("Add:upload_channel = [%d]\n",hv_upload_channel));
        }

/* multi_match_ind */
        if (GetField_Int(hRls,"multi_match_ind",&iTmp)) {
		hv_multi_match_ind = iTmp;
                ind_multi_match_ind = 0;
DEBUGLOG(("Add:multi_match_ind = [%d]\n",hv_multi_match_ind));
        }

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_ol_txn_header_insert(
					:hv_txn_id:ind_txn_id,
					:hv_org_txn_id:ind_org_txn_id,
					:hv_channel_code:ind_channel_code,
					:hv_status:ind_status,
					:hv_ar_ind:ind_ar_ind,
					:hv_sub_status:ind_sub_status,
					:hv_txn_code:ind_txn_code,
					:hv_process_type:ind_process_type,
					:hv_process_code:ind_process_code,
					:hv_merchant_id:ind_merchant_id,
					:hv_merchant_ref:ind_merchant_ref,
					:hv_client_id:ind_client_id,
					:hv_host_posting_date:ind_host_posting_date,
					:hv_transmission_datetime:ind_transmission_datetime,
					:hv_internal_code:ind_internal_code,
					:hv_response_code:ind_response_code,
					:hv_transaction_amt:ind_transaction_amt,
					:hv_deposit_amt:ind_deposit_amt,
					:hv_display_amt:ind_display_amt,
					:hv_net_amt:ind_net_amt,
					:hv_filename:ind_filename,
					:hv_tm_date:ind_tm_date,
					:hv_tm_time:ind_tm_time,
					:hv_local_tm_date:ind_local_tm_date,
					:hv_local_tm_time:ind_local_tm_time,
					:hv_add_user:ind_add_user,
					:hv_add_user:ind_add_user,
					:hv_client_ip:ind_client_ip,
					:hv_service_code:ind_service_code,
					:hv_approval_date:ind_approval_date,
					:hv_upd_match_ts:ind_upd_match_ts,
					:hv_upload_channel:ind_upload_channel,
					:hv_multi_match_ind:ind_multi_match_ind);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 33;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_txn_header_insert ( :hv_txn_id:ind_txn_i\
d , :hv_org_txn_id:ind_org_txn_id , :hv_channel_code:ind_channel_code , :hv_\
status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_sub_status:ind_sub_status , \
:hv_txn_code:ind_txn_code , :hv_process_type:ind_process_type , :hv_process_\
code:ind_process_code , :hv_merchant_id:ind_merchant_id , :hv_merchant_ref:i\
nd_merchant_ref , :hv_client_id:ind_client_id , :hv_host_posting_date:ind_ho\
st_posting_date , :hv_transmission_datetime:ind_transmission_datetime , :hv_\
internal_code:ind_internal_code , :hv_response_code:ind_response_code , :hv_\
transaction_amt:ind_transaction_amt , :hv_deposit_amt:ind_deposit_amt , :hv_\
display_amt:ind_display_amt , :hv_net_amt:ind_net_amt , :hv_filename:ind_fil\
ename , :hv_tm_date:ind_tm_date , :hv_tm_time:ind_tm_time , :hv_local_tm_dat\
e:ind_local_tm_date , :hv_local_tm_time:ind_local_tm_time , :hv_add_user:ind\
_add_user , :hv_add_user:ind_add_user , :hv_client_ip:ind_client_ip , :hv_se\
rvice_code:ind_service_code , :hv_approv");
 sqlstm.stmt = "al_date:ind_approval_date , :hv_upd_match_ts:ind_upd_match_\
ts , :hv_upload_channel:ind_upload_channel , :hv_multi_match_ind:ind_multi_ma\
tch_ind ) ; END ;";
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_channel_code;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_status;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_ar_ind;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_sub_status;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_txn_code;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_process_type;
 sqlstm.sqhstl[8] = (unsigned long )6;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_process_type;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_process_code;
 sqlstm.sqhstl[9] = (unsigned long )8;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_process_code;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_merchant_id;
 sqlstm.sqhstl[10] = (unsigned long )17;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_merchant_id;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_merchant_ref;
 sqlstm.sqhstl[11] = (unsigned long )52;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_merchant_ref;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_client_id;
 sqlstm.sqhstl[12] = (unsigned long )12;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_client_id;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_host_posting_date;
 sqlstm.sqhstl[13] = (unsigned long )10;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_host_posting_date;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_transmission_datetime;
 sqlstm.sqhstl[14] = (unsigned long )16;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_transmission_datetime;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_internal_code;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_internal_code;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_response_code;
 sqlstm.sqhstl[16] = (unsigned long )12;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_response_code;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_transaction_amt;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_transaction_amt;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_deposit_amt;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_deposit_amt;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_display_amt;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_display_amt;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_net_amt;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_filename;
 sqlstm.sqhstl[21] = (unsigned long )102;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_filename;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_tm_date;
 sqlstm.sqhstl[22] = (unsigned long )10;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_tm_date;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_tm_time;
 sqlstm.sqhstl[23] = (unsigned long )8;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_tm_time;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_local_tm_date;
 sqlstm.sqhstl[24] = (unsigned long )10;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_local_tm_date;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_local_tm_time;
 sqlstm.sqhstl[25] = (unsigned long )8;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_local_tm_time;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[26] = (unsigned long )22;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_add_user;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_client_ip;
 sqlstm.sqhstl[27] = (unsigned long )27;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_client_ip;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[28] = (unsigned long )5;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_service_code;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_approval_date;
 sqlstm.sqhstl[29] = (unsigned long )10;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_approval_date;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_upd_match_ts;
 sqlstm.sqhstl[30] = (unsigned long )1;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_upd_match_ts;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_upload_channel;
 sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_upload_channel;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&hv_multi_match_ind;
 sqlstm.sqhstl[32] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&ind_multi_match_ind;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
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



// update txn sub status
        AddTxnStatusLog(hRls);
// update txn browser info  
        AddTxnBrowserInfo(hRls);


DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
		if (iCommit == PD_TRUE)
			TxnCommit();
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int Update(const hash_t *hRls)
{

	char*	csTmp;
	char	cTmp;
	double	dTmp;
	int	iTmp;
	char*	csBuf;
	char*	csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update ol_txn_header set oth_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
DEBUGLOG(("Update:org_txn_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_org_txn_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* Channel code */
        if (GetField_CString(hRls,"channel_code",&csTmp)) {
DEBUGLOG(("Update:channel_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_input_channel = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:status = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_status = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* ar ind */ 
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
DEBUGLOG(("Update:ar_ind = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_ar_ind = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Sub Status */
        if (GetField_CString(hRls,"sub_status",&csTmp)) {
DEBUGLOG(("Update:sub_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oth_sub_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ACK Status */
        if (GetField_CString(hRls,"ack_status",&csTmp)) {
DEBUGLOG(("Update:ack_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oth_ack_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
DEBUGLOG(("Update:txn_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_txn_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
DEBUGLOG(("Update:process_type = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_process_type = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
DEBUGLOG(("Update:process_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_process_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Merchant No */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
DEBUGLOG(("Update:merchant_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_merchant_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Merchant Ref */
        if (GetField_CString(hRls,"merchant_ref",&csTmp)) {
DEBUGLOG(("Update:merchant_ref = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_merchant_ref = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Client ID */
        if (GetField_CString(hRls,"client_id",&csTmp)) {
DEBUGLOG(("Update:client_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_client_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
DEBUGLOG(("Update:host_posting_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_host_posting_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* transmission_datetime  */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
DEBUGLOG(("Update:transmission_datetime = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_transmission_datetime = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("Update:internal_code = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_internal_code = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("Update:response_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_response_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("Update:txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_transaction_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* deposit amt   */
        if (GetField_Double(hRls,"deposit_amt",&dTmp)) {
DEBUGLOG(("Update:deposit_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_deposit_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* display amt   */
        if (GetField_Double(hRls,"display_amt",&dTmp)) {
DEBUGLOG(("Update:display_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_display_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* net amt   */
        if (GetField_Double(hRls,"net_amt",&dTmp)) {
DEBUGLOG(("Update:net_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_net_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* reserve amt */
	if (GetField_Double(hRls,"reserve_amt",&dTmp)) {
DEBUGLOG(("Update:reserve_amt = [%lf]\n", dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_reserve_amount = ");
		strcat((char*)hv_dynstmt.arr, csBuf);
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* tm date */
        if (GetField_CString(hRls,"tm_date",&csTmp)) {
DEBUGLOG(("Update:tm_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_tm_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
DEBUGLOG(("Update:tm_time = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_tm_time = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
DEBUGLOG(("Update:local_tm_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_local_tm_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
DEBUGLOG(("Update:local_tm_time = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_local_tm_time = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ip_addr */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
		char *p;
		char    csTmpIP[PD_IP_LEN+1];
                p = strtok (csTmp,",");
                while (p != NULL)
                {
                        strcpy(csTmpIP,p);
                        csTmpIP[strlen(p)]='\0';
			break;
                }
DEBUGLOG(("Update:ip_addr = [%s]\n",csTmpIP));
		strcat((char*)hv_dynstmt.arr, ",oth_client_ip = '");
        	strcat((char*)hv_dynstmt.arr, csTmpIP);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* approval date */
        if (GetField_CString(hRls,"approval_date",&csTmp)) {
DEBUGLOG(("Update:approval_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_approval_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* approval timestamp */
        if (GetField_CString(hRls,"approval_timestamp",&csTmp)) {
DEBUGLOG(("Update:approval_timestamp = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_approval_timestamp = to_timestamp('");
        	strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "','YYYYMMDDHH24MISSFF') ");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
DEBUGLOG(("Update:service_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_service_code= '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ex_supplier */ 
        if (GetField_Char(hRls,"ex_supplier",&cTmp)) {
DEBUGLOG(("Update:ex_supplier = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_ex_supplier = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*ex_rate*/
        if (GetField_Double(hRls,"ex_rate",&dTmp)) {
DEBUGLOG(("Update:ex_rate = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_ex_rate = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* settlement txn amount */
        if (GetField_Double(hRls,"settlement_txn_amt",&dTmp)) {
DEBUGLOG(("Update:settlement_txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_settlement_txn_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_create_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* reserved_release_date */
	if (GetField_CString(hRls,"reserved_release_date",&csTmp)) {
DEBUGLOG(("Update:reserved_release_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_reserved_release_date = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* inter ccy */
        if (GetField_CString(hRls,"inter_ccy",&csTmp)) {
DEBUGLOG(("Update:inter_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_inter_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/// inter rate
        if (GetField_Double(hRls,"inter_rate",&dTmp)) {
DEBUGLOG(("Update:inter_rate = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_inter_rate = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* net ccy */
        if (GetField_CString(hRls,"net_ccy",&csTmp)) {
DEBUGLOG(("Update:net_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",oth_net_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

// dst_txn_id
	if (GetField_CString(hRls, "dst_txn_id", &csTmp)) {
DEBUGLOG(("Update: dst_txn_id = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_dst_txn_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

// upd_match_ts
	if (GetField_Char(hRls, "upd_match_ts", &cTmp)) {
DEBUGLOG(("Update: upd_match_ts = [%c]\n", cTmp));
		if (cTmp == PD_YES) {
			strcat((char*)hv_dynstmt.arr, ",oth_matching_timestamp = sysdate");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}

// upload_channel
        if (GetField_Int(hRls,"upload_channel",&iTmp)) {
DEBUGLOG(("Update:upload_channel = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_upload_channel= ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

// multi_match_ind
        if (GetField_Int(hRls,"multi_match_ind",&iTmp)) {
DEBUGLOG(("Update:multi_match_ind = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_multi_match_ind = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* recon status */ 
        if (GetField_Char(hRls,"recon_status",&cTmp)) {
DEBUGLOG(("Update:recon_status = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",oth_recon_status = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

//recon_date 
	if (GetField_CString(hRls, "recon_date", &csTmp)) {
DEBUGLOG(("Update: recon_date = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_recon_date= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

//recon_time
	if (GetField_CString(hRls, "recon_time", &csTmp)) {
DEBUGLOG(("Update: recon_time = [%s]\n", csTmp));
		strcat((char*)hv_dynstmt.arr, ",oth_recon_time= '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


	strcat((char *)hv_dynstmt.arr, " WHERE oth_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 33;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )152;
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
 sqlstm.arrsiz = 33;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )171;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_error;
}



	FREE_ME(csBuf);

// update txn sub status 
	AddTxnStatusLog(hRls);

// update txn browser info  
        AddTxnBrowserInfo(hRls);

DEBUGLOG(("Update Normal Exit\n"));
	return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int AddDetail(const hash_t *hRls)
{
        char		*csTmp;
	int		iTmp;
	char		cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO adddetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short 		hv_return_value;

	/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;
	
	/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

	/* varchar		hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

	/* varchar		hv_pay_method[PD_PAY_METHOD_LIST_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_pay_method;

	/* varchar		hv_cust_deposit_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cust_deposit_datetime;

	/* varchar		hv_bank_deposit_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_bank_deposit_datetime;

	/* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

	/* varchar		hv_deposit_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_deposit_bank_code;

	/* varchar		hv_deposit_bank[PD_BANK_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_bank;

	/* varchar		hv_deposit_ref[PD_BANK_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_ref;

	/* varchar		hv_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_bank_code;

	/* varchar		hv_bank_name[PD_AC_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_bank_name;

	/* varchar		hv_branch_name[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_branch_name;

	/* varchar		hv_account_id[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_id;

	/* varchar		hv_account_name[PD_AC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_account_name;

	/* varchar		hv_identity_id[PD_IDENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_identity_id;

	/* varchar		hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_province;

	/* varchar		hv_phone_no[PD_PHONE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_phone_no;

	/* varchar		hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

	/* varchar		hv_batch_id[PD_BATCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_batch_id;

	/* varchar		hv_language[PD_LANGUAGE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_language;

	/* varchar		hv_success_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_success_url;

	/* varchar		hv_failure_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_failure_url;

	/* varchar		hv_success_ck_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_success_ck_url;

	/* varchar		hv_failure_ck_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_failure_ck_url;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

	/* varchar		hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

	/* varchar		hv_encrypt_type[PD_ENCRYPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_encrypt_type;

	int		hv_version_no;
	/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

        /* varchar         hv_banner_logo[PD_BANNER_LOGO_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_banner_logo;

        /* varchar         hv_echo_msg_1[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_echo_msg_1;

        /* varchar         hv_echo_msg_2[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_echo_msg_2;

        /* varchar         hv_echo_msg_3[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_echo_msg_3;

        /* varchar         hv_opt_1[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_1;

        /* varchar         hv_opt_2[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_2;

        /* varchar         hv_opt_3[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_3;

	/* varchar		hv_cust_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_cust_tag;

	char		hv_deposit_flow;
	int		hv_cust_deposit_dt_prov;


	short		ind_txn_id = -1;
	short		ind_txn_ccy = -1;
	short		ind_txn_country = -1;
	short		ind_pay_method = -1;
	short		ind_cust_deposit_datetime = -1;
	short		ind_bank_deposit_datetime = -1;
	short		ind_bank_acct_num = -1;
	short		ind_deposit_bank_code = -1;
	short		ind_deposit_bank = -1;
	short		ind_deposit_ref = -1;
	short		ind_bank_code = -1;
	short		ind_bank_name = -1;
	short		ind_branch_name = -1;
	short		ind_account_id = -1;
	short		ind_account_name = -1;
	short		ind_identity_id = -1;
	short		ind_province = -1;
	short		ind_phone_no = -1;
	short		ind_city = -1;
	short		ind_batch_id = -1;
	short		ind_language = -1;
	short		ind_success_url = -1;
	short		ind_failure_url = -1;
	short		ind_success_ck_url = -1;
	short		ind_failure_ck_url = -1;
	short		ind_add_user = -1;
	short		ind_update_user = -1;
	short		ind_encrypt_type= -1;
	short		ind_version_no = -1;
	short		ind_remark = -1;
        short           ind_banner_logo= -1;
        short           ind_echo_msg_1= -1;
        short           ind_echo_msg_2= -1;
        short           ind_echo_msg_3= -1;
        short           ind_opt_1= -1;
        short           ind_opt_2= -1;
        short           ind_opt_3= -1;
	short		ind_cust_tag= -1;
	short		ind_deposit_flow= -1;
	short		ind_cust_deposit_dt_prov = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));


/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddDetail:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("AddDetail:txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csTmp)) {
                hv_txn_country.len = strlen(csTmp);
                memcpy(hv_txn_country.arr,csTmp,hv_txn_country.len);
                ind_txn_country = 0;
DEBUGLOG(("AddDetail:txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));
        }
/* pay_method */
        if (GetField_CString(hRls,"pay_method",&csTmp)) {
                hv_pay_method.len = strlen(csTmp);
                memcpy(hv_pay_method.arr,csTmp,hv_pay_method.len);
                ind_pay_method = 0;
DEBUGLOG(("AddDetail:pay_method = [%.*s]\n",hv_pay_method.len,hv_pay_method.arr));
	}

/* cust_deposit_datetime */
        if (GetField_CString(hRls,"cust_deposit_datetime",&csTmp)) {
		if (strlen(csTmp) > 14) {
			csTmp[14] = '\0';
		}
                hv_cust_deposit_datetime.len = strlen(csTmp);
                memcpy(hv_cust_deposit_datetime.arr,csTmp,hv_cust_deposit_datetime.len);
                ind_cust_deposit_datetime = 0;
DEBUGLOG(("AddDetail:cust_deposit_datetime = [%.*s]\n",hv_cust_deposit_datetime.len,hv_cust_deposit_datetime.arr));
	}

/* bank_deposit_datetime */
        if (GetField_CString(hRls,"bank_deposit_datetime",&csTmp)) {
                hv_bank_deposit_datetime.len = strlen(csTmp);
                memcpy(hv_bank_deposit_datetime.arr,csTmp,hv_bank_deposit_datetime.len);
                ind_bank_deposit_datetime = 0;
DEBUGLOG(("AddDetail:bank_deposit_datetime = [%.*s]\n",hv_bank_deposit_datetime.len,hv_bank_deposit_datetime.arr));
	}
/* bank_acct_num */
        if (GetField_CString(hRls,"bank_acct_num",&csTmp)) {
                hv_bank_acct_num.len = strlen(csTmp);
                memcpy(hv_bank_acct_num.arr,csTmp,hv_bank_acct_num.len);
                ind_bank_acct_num = 0;
DEBUGLOG(("AddDetail:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
	}

/* deposit_bank_code */
        if (GetField_CString(hRls,"deposit_bank_code",&csTmp)) {
                hv_deposit_bank_code.len = strlen(csTmp);
                memcpy(hv_deposit_bank_code.arr,csTmp,hv_deposit_bank_code.len);
                ind_deposit_bank_code = 0;
DEBUGLOG(("AddDetail:deposit_bank_code = [%.*s]\n",hv_deposit_bank_code.len,hv_deposit_bank_code.arr));
	}

/* deposit_bank */
        if (GetField_CString(hRls,"deposit_bank",&csTmp)) {
                hv_deposit_bank.len = strlen(csTmp);
                memcpy(hv_deposit_bank.arr,csTmp,hv_deposit_bank.len);
                ind_deposit_bank = 0;
DEBUGLOG(("AddDetail:deposit_bank = [%.*s]\n",hv_deposit_bank.len,hv_deposit_bank.arr));
	}

/* deposit_ref */
        if (GetField_CString(hRls,"deposit_ref",&csTmp)) {
                hv_deposit_ref.len = strlen(csTmp);
                memcpy(hv_deposit_ref.arr,csTmp,hv_deposit_ref.len);
                ind_deposit_ref = 0;
DEBUGLOG(("AddDetail:deposit_ref = [%.*s]\n",hv_deposit_ref.len,hv_deposit_ref.arr));
	}

/* bank_code */
        if (GetField_CString(hRls,"bank_code",&csTmp)) {
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
                ind_bank_code = 0;
DEBUGLOG(("AddDetail:bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
	}

/* bank_name */
        if (GetField_CString(hRls,"bank_name",&csTmp)) {
                hv_bank_name.len = strlen(csTmp);
                memcpy(hv_bank_name.arr,csTmp,hv_bank_name.len);
                ind_bank_name = 0;
DEBUGLOG(("AddDetail:bank_name = [%.*s]\n",hv_bank_name.len,hv_bank_name.arr));
	}
/* branch_name */
        if (GetField_CString(hRls,"branch_name",&csTmp)) {
                hv_branch_name.len = strlen(csTmp);
                memcpy(hv_branch_name.arr,csTmp,hv_branch_name.len);
                ind_branch_name = 0;
DEBUGLOG(("AddDetail:branch_name = [%.*s]\n",hv_branch_name.len,hv_branch_name.arr));
	}

/* account_id */
        if (GetField_CString(hRls,"account_id",&csTmp)) {
                hv_account_id.len = strlen(csTmp);
                memcpy(hv_account_id.arr,csTmp,hv_account_id.len);
                ind_account_id = 0;
DEBUGLOG(("AddDetail:account_id = [%.*s]\n",hv_account_id.len,hv_account_id.arr));
	}

/* account_name */
        if (GetField_CString(hRls,"account_name",&csTmp)) {
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr,csTmp,hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("AddDetail:account_name = [%.*s]\n",hv_account_name.len,hv_account_name.arr));
	}


/* identity_id */
        if (GetField_CString(hRls,"identity_id",&csTmp)) {
                hv_identity_id.len = strlen(csTmp);
                memcpy(hv_identity_id.arr,csTmp,hv_identity_id.len);
                ind_identity_id = 0;
DEBUGLOG(("AddDetail:identity_id = [%.*s]\n",hv_identity_id.len,hv_identity_id.arr));
	}


/* province */
        if (GetField_CString(hRls,"province",&csTmp)) {
                hv_province.len = strlen(csTmp);
                memcpy(hv_province.arr,csTmp,hv_province.len);
                ind_province = 0;
DEBUGLOG(("AddDetail:province = [%.*s]\n",hv_province.len,hv_province.arr));
	}

/* phone_no */
        if (GetField_CString(hRls,"phone_no",&csTmp)) {
                hv_phone_no.len = strlen(csTmp);
                memcpy(hv_phone_no.arr,csTmp,hv_phone_no.len);
                ind_phone_no = 0;
DEBUGLOG(("AddDetail:phone_no = [%.*s]\n",hv_phone_no.len,hv_phone_no.arr));
	}

/* city */
        if (GetField_CString(hRls,"city",&csTmp)) {
                hv_city.len = strlen(csTmp);
                memcpy(hv_city.arr,csTmp,hv_city.len);
                ind_city = 0;
DEBUGLOG(("AddDetail:city = [%.*s]\n",hv_city.len,hv_city.arr));
	}
/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
                ind_batch_id = 0;
DEBUGLOG(("AddDetail:batch_id = [%.*s]\n",hv_batch_id.len,hv_batch_id.arr));
	}


/* language */
        if (GetField_CString(hRls,"language",&csTmp)) {
                hv_language.len = strlen(csTmp);
                memcpy(hv_language.arr,csTmp,hv_language.len);
                ind_language = 0;
DEBUGLOG(("AddDetail:language = [%.*s]\n",hv_language.len,hv_language.arr));
	}

/* success_url */
        if (GetField_CString(hRls,"success_url",&csTmp)) {
                hv_success_url.len = strlen(csTmp);
                memcpy(hv_success_url.arr,csTmp,hv_success_url.len);
                ind_success_url = 0;
DEBUGLOG(("AddDetail:success_url = [%.*s]\n",hv_success_url.len,hv_success_url.arr));
	}

/* failure_url */
        if (GetField_CString(hRls,"failure_url",&csTmp)) {
                hv_failure_url.len = strlen(csTmp);
                memcpy(hv_failure_url.arr,csTmp,hv_failure_url.len);
                ind_failure_url = 0;
DEBUGLOG(("AddDetail:failure_url = [%.*s]\n",hv_failure_url.len,hv_failure_url.arr));
	}

/* success_callback_url */
        if (GetField_CString(hRls,"success_callback_url",&csTmp)) {
                hv_success_ck_url.len = strlen(csTmp);
                memcpy(hv_success_ck_url.arr,csTmp,hv_success_ck_url.len);
                ind_success_ck_url = 0;
DEBUGLOG(("AddDetail:success_ck_url = [%.*s]\n",hv_success_ck_url.len,hv_success_ck_url.arr));
	}

/* failure_callback_url */
        if (GetField_CString(hRls,"failure_callback_url",&csTmp)) {
                hv_failure_ck_url.len = strlen(csTmp);
                memcpy(hv_failure_ck_url.arr,csTmp,hv_failure_ck_url.len);
                ind_failure_ck_url = 0;
DEBUGLOG(("AddDetail:failure_ck_url = [%.*s]\n",hv_failure_ck_url.len,hv_failure_ck_url.arr));
	}
	
	
/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen((const char*)csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddDetail:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
                hv_update_user.len = strlen((const char*)csTmp);
                memcpy(hv_update_user.arr,csTmp,hv_update_user.len);
                ind_update_user = 0;
DEBUGLOG(("AddDetail:update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
        }


/* encrypt_type */
        if (GetField_CString(hRls,"encrypt_type",&csTmp)) {
                hv_encrypt_type.len = strlen(csTmp);
                memcpy(hv_encrypt_type.arr,csTmp,hv_encrypt_type.len);
                ind_encrypt_type = 0;
DEBUGLOG(("AddDetail:encrypt_type = [%.*s]\n",hv_encrypt_type.len,hv_encrypt_type.arr));
        }

/* version_no */
	if (GetField_Int(hRls,"version_no",&iTmp)) {
		hv_version_no = iTmp;
		ind_version_no = 0;
DEBUGLOG(("AddDetail:version_no = [%d]\n",hv_version_no));
	}

/* remark */
        if (GetField_CString(hRls,"remark",&csTmp)) {
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr,csTmp,hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("AddDetail:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

/* banner_logo*/
        if (GetField_CString(hRls,"banner_logo", &csTmp)) {
                hv_banner_logo.len = strlen(csTmp);
                memcpy(hv_banner_logo.arr,csTmp,hv_banner_logo.len);
                ind_banner_logo= 0;
DEBUGLOG(("AddDetail:banner_logo = [%.*s][%d]\n",hv_banner_logo.len,hv_banner_logo.arr,hv_banner_logo.len));
        }

/* echo_msg*/
        if (GetField_CString(hRls,"echo_msg_1", &csTmp)) {
                hv_echo_msg_1.len = strlen(csTmp);
                memcpy(hv_echo_msg_1.arr,csTmp,hv_echo_msg_1.len);
                ind_echo_msg_1= 0;
DEBUGLOG(("AddDetail:echo_msg_1 = [%.*s][%d]\n",hv_echo_msg_1.len,hv_echo_msg_1.arr,hv_echo_msg_1.len));
        }

/* echo_msg*/
        if (GetField_CString(hRls,"echo_msg_2", &csTmp)) {
                hv_echo_msg_2.len = strlen(csTmp);
                memcpy(hv_echo_msg_2.arr,csTmp,hv_echo_msg_2.len);
                ind_echo_msg_2= 0;
DEBUGLOG(("AddDetail:echo_msg_2 = [%.*s][%d]\n",hv_echo_msg_2.len,hv_echo_msg_2.arr,hv_echo_msg_2.len));
        }

/* echo_msg*/
        if (GetField_CString(hRls,"echo_msg_3", &csTmp)) {
                hv_echo_msg_3.len = strlen(csTmp);
                memcpy(hv_echo_msg_3.arr,csTmp,hv_echo_msg_3.len);
                ind_echo_msg_3= 0;
DEBUGLOG(("AddDetail:echo_msg_3 = [%.*s][%d]\n",hv_echo_msg_3.len,hv_echo_msg_3.arr,hv_echo_msg_3.len));
        }

/* opt*/
        if (GetField_CString(hRls,"opt_1", &csTmp)) {
                hv_opt_1.len = strlen(csTmp);
                memcpy(hv_opt_1.arr,csTmp,hv_opt_1.len);
                ind_opt_1= 0;
DEBUGLOG(("AddDetail:opt_1 = [%.*s][%d]\n",hv_opt_1.len,hv_opt_1.arr,hv_opt_1.len));
        }

/* opt*/
        if (GetField_CString(hRls,"opt_2", &csTmp)) {
                hv_opt_2.len = strlen(csTmp);
                memcpy(hv_opt_2.arr,csTmp,hv_opt_2.len);
                ind_opt_2= 0;
DEBUGLOG(("AddDetail:opt_2 = [%.*s][%d]\n",hv_opt_2.len,hv_opt_2.arr,hv_opt_2.len));
        }

/* opt*/
        if (GetField_CString(hRls,"opt_3", &csTmp)) {
                hv_opt_3.len = strlen(csTmp);
                memcpy(hv_opt_3.arr,csTmp,hv_opt_3.len);
                ind_opt_3= 0;
DEBUGLOG(("AddDetail:opt_3 = [%.*s][%d]\n",hv_opt_3.len,hv_opt_3.arr,hv_opt_3.len));
        }

/* cust_tag*/
        if (GetField_CString(hRls,"cust_tag", &csTmp)) {
                hv_cust_tag.len = strlen(csTmp);
                memcpy(hv_cust_tag.arr,csTmp,hv_cust_tag.len);
                ind_cust_tag= 0;
DEBUGLOG(("AddDetail:cust_tag = [%.*s][%d]\n",hv_cust_tag.len,hv_cust_tag.arr,hv_cust_tag.len));
        }
/* deposit_flow*/
	if (GetField_Char(hRls,"deposit_flow", &cTmp)) {
		hv_deposit_flow = cTmp;
		ind_deposit_flow= 0;
DEBUGLOG(("AddDetail:deposit_flow = [%c]\n", hv_deposit_flow));
	}
/* cust_deposit_dt_prov */
	if (GetField_Int(hRls, "cust_deposit_dt_prov", &iTmp)) {
		hv_cust_deposit_dt_prov = iTmp;
		ind_cust_deposit_dt_prov = 0;
DEBUGLOG(("AddDetail: cust_deposit_dt_prov = [%d]\n", hv_cust_deposit_dt_prov));
	}

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_ol_txn_detail_insert(
					:hv_txn_id:ind_txn_id,
					:hv_txn_ccy:ind_txn_ccy,
					:hv_txn_country:ind_txn_country,
					:hv_pay_method:ind_pay_method,
					:hv_cust_deposit_datetime:ind_cust_deposit_datetime,
					:hv_bank_deposit_datetime:ind_bank_deposit_datetime,
					:hv_bank_acct_num:ind_bank_acct_num,
					:hv_deposit_bank_code:ind_deposit_bank_code,
					:hv_deposit_bank:ind_deposit_bank,
					:hv_deposit_ref:ind_deposit_ref,
					:hv_bank_code:ind_bank_code,
					:hv_bank_name:ind_bank_name,
					:hv_branch_name:ind_branch_name,
					:hv_account_id:ind_account_id,
					:hv_account_name:ind_account_name,
					:hv_identity_id:ind_identity_id,
					:hv_province:ind_province,
					:hv_phone_no:ind_phone_no,
					:hv_city:ind_city,
					:hv_batch_id:ind_batch_id,
					:hv_language:ind_language,
					:hv_success_url:ind_success_url,
					:hv_failure_url:ind_failure_url,
					:hv_success_ck_url:ind_success_ck_url,
					:hv_failure_ck_url:ind_failure_ck_url,
					:hv_add_user:ind_add_user,
					:hv_update_user:ind_update_user,
					:hv_encrypt_type:ind_encrypt_type,
					:hv_version_no:ind_version_no,
					:hv_remark:ind_remark,
					:hv_banner_logo:ind_banner_logo,
                                        :hv_echo_msg_1:ind_echo_msg_1,
                                        :hv_echo_msg_2:ind_echo_msg_2,
                                        :hv_echo_msg_3:ind_echo_msg_3,
                                        :hv_opt_1:ind_opt_1,
                                        :hv_opt_2:ind_opt_2,
                                        :hv_opt_3:ind_opt_3,
					:hv_cust_tag:ind_cust_tag,
					:hv_deposit_flow:ind_deposit_flow,
					:hv_cust_deposit_dt_prov:ind_cust_deposit_dt_prov);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_ol_txn_detail_insert ( :hv_txn_id:ind_txn_i\
d , :hv_txn_ccy:ind_txn_ccy , :hv_txn_country:ind_txn_country , :hv_pay_meth\
od:ind_pay_method , :hv_cust_deposit_datetime:ind_cust_deposit_datetime , :h\
v_bank_deposit_datetime:ind_bank_deposit_datetime , :hv_bank_acct_num:ind_ba\
nk_acct_num , :hv_deposit_bank_code:ind_deposit_bank_code , :hv_deposit_bank\
:ind_deposit_bank , :hv_deposit_ref:ind_deposit_ref , :hv_bank_code:ind_bank\
_code , :hv_bank_name:ind_bank_name , :hv_branch_name:ind_branch_name , :hv_\
account_id:ind_account_id , :hv_account_name:ind_account_name , :hv_identity\
_id:ind_identity_id , :hv_province:ind_province , :hv_phone_no:ind_phone_no \
, :hv_city:ind_city , :hv_batch_id:ind_batch_id , :hv_language:ind_language \
, :hv_success_url:ind_success_url , :hv_failure_url:ind_failure_url , :hv_su\
ccess_ck_url:ind_success_ck_url , :hv_failure_ck_url:ind_failure_ck_url , :h\
v_add_user:ind_add_user , :hv_update_user:ind_update_user , :hv_encrypt_type\
:ind_encrypt_type , :hv_version_no:ind_v");
 sqlstm.stmt = "ersion_no , :hv_remark:ind_remark , :hv_banner_logo:ind_ban\
ner_logo , :hv_echo_msg_1:ind_echo_msg_1 , :hv_echo_msg_2:ind_echo_msg_2 , :h\
v_echo_msg_3:ind_echo_msg_3 , :hv_opt_1:ind_opt_1 , :hv_opt_2:ind_opt_2 , :hv\
_opt_3:ind_opt_3 , :hv_cust_tag:ind_cust_tag , :hv_deposit_flow:ind_deposit_f\
low , :hv_cust_deposit_dt_prov:ind_cust_deposit_dt_prov ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )186;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_country;
 sqlstm.sqhstl[3] = (unsigned long )4;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_txn_country;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_pay_method;
 sqlstm.sqhstl[4] = (unsigned long )52;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_pay_method;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_cust_deposit_datetime;
 sqlstm.sqhstl[5] = (unsigned long )16;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_cust_deposit_datetime;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_deposit_datetime;
 sqlstm.sqhstl[6] = (unsigned long )16;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bank_deposit_datetime;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[7] = (unsigned long )52;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_deposit_bank_code;
 sqlstm.sqhstl[8] = (unsigned long )27;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_deposit_bank_code;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_deposit_bank;
 sqlstm.sqhstl[9] = (unsigned long )152;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_deposit_bank;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_deposit_ref;
 sqlstm.sqhstl[10] = (unsigned long )152;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_deposit_ref;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[11] = (unsigned long )27;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_bank_code;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[12] = (unsigned long )152;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_bank_name;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_branch_name;
 sqlstm.sqhstl[13] = (unsigned long )152;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_branch_name;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_account_id;
 sqlstm.sqhstl[14] = (unsigned long )27;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_account_id;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[15] = (unsigned long )102;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_account_name;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_identity_id;
 sqlstm.sqhstl[16] = (unsigned long )27;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_identity_id;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[17] = (unsigned long )102;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_province;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_phone_no;
 sqlstm.sqhstl[18] = (unsigned long )32;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_phone_no;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[19] = (unsigned long )102;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_city;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[20] = (unsigned long )22;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_batch_id;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_language;
 sqlstm.sqhstl[21] = (unsigned long )4;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_language;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_success_url;
 sqlstm.sqhstl[22] = (unsigned long )257;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_success_url;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_failure_url;
 sqlstm.sqhstl[23] = (unsigned long )257;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_failure_url;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_success_ck_url;
 sqlstm.sqhstl[24] = (unsigned long )257;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_success_ck_url;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_failure_ck_url;
 sqlstm.sqhstl[25] = (unsigned long )257;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_failure_ck_url;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[26] = (unsigned long )22;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_add_user;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[27] = (unsigned long )22;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_update_user;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_encrypt_type;
 sqlstm.sqhstl[28] = (unsigned long )6;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_encrypt_type;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_version_no;
 sqlstm.sqhstl[29] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_version_no;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[30] = (unsigned long )257;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_remark;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_banner_logo;
 sqlstm.sqhstl[31] = (unsigned long )257;
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_banner_logo;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&hv_echo_msg_1;
 sqlstm.sqhstl[32] = (unsigned long )257;
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&ind_echo_msg_1;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
 sqlstm.sqhstv[33] = (unsigned char  *)&hv_echo_msg_2;
 sqlstm.sqhstl[33] = (unsigned long )257;
 sqlstm.sqhsts[33] = (         int  )0;
 sqlstm.sqindv[33] = (         short *)&ind_echo_msg_2;
 sqlstm.sqinds[33] = (         int  )0;
 sqlstm.sqharm[33] = (unsigned long )0;
 sqlstm.sqadto[33] = (unsigned short )0;
 sqlstm.sqtdso[33] = (unsigned short )0;
 sqlstm.sqhstv[34] = (unsigned char  *)&hv_echo_msg_3;
 sqlstm.sqhstl[34] = (unsigned long )257;
 sqlstm.sqhsts[34] = (         int  )0;
 sqlstm.sqindv[34] = (         short *)&ind_echo_msg_3;
 sqlstm.sqinds[34] = (         int  )0;
 sqlstm.sqharm[34] = (unsigned long )0;
 sqlstm.sqadto[34] = (unsigned short )0;
 sqlstm.sqtdso[34] = (unsigned short )0;
 sqlstm.sqhstv[35] = (unsigned char  *)&hv_opt_1;
 sqlstm.sqhstl[35] = (unsigned long )52;
 sqlstm.sqhsts[35] = (         int  )0;
 sqlstm.sqindv[35] = (         short *)&ind_opt_1;
 sqlstm.sqinds[35] = (         int  )0;
 sqlstm.sqharm[35] = (unsigned long )0;
 sqlstm.sqadto[35] = (unsigned short )0;
 sqlstm.sqtdso[35] = (unsigned short )0;
 sqlstm.sqhstv[36] = (unsigned char  *)&hv_opt_2;
 sqlstm.sqhstl[36] = (unsigned long )52;
 sqlstm.sqhsts[36] = (         int  )0;
 sqlstm.sqindv[36] = (         short *)&ind_opt_2;
 sqlstm.sqinds[36] = (         int  )0;
 sqlstm.sqharm[36] = (unsigned long )0;
 sqlstm.sqadto[36] = (unsigned short )0;
 sqlstm.sqtdso[36] = (unsigned short )0;
 sqlstm.sqhstv[37] = (unsigned char  *)&hv_opt_3;
 sqlstm.sqhstl[37] = (unsigned long )52;
 sqlstm.sqhsts[37] = (         int  )0;
 sqlstm.sqindv[37] = (         short *)&ind_opt_3;
 sqlstm.sqinds[37] = (         int  )0;
 sqlstm.sqharm[37] = (unsigned long )0;
 sqlstm.sqadto[37] = (unsigned short )0;
 sqlstm.sqtdso[37] = (unsigned short )0;
 sqlstm.sqhstv[38] = (unsigned char  *)&hv_cust_tag;
 sqlstm.sqhstl[38] = (unsigned long )12;
 sqlstm.sqhsts[38] = (         int  )0;
 sqlstm.sqindv[38] = (         short *)&ind_cust_tag;
 sqlstm.sqinds[38] = (         int  )0;
 sqlstm.sqharm[38] = (unsigned long )0;
 sqlstm.sqadto[38] = (unsigned short )0;
 sqlstm.sqtdso[38] = (unsigned short )0;
 sqlstm.sqhstv[39] = (unsigned char  *)&hv_deposit_flow;
 sqlstm.sqhstl[39] = (unsigned long )1;
 sqlstm.sqhsts[39] = (         int  )0;
 sqlstm.sqindv[39] = (         short *)&ind_deposit_flow;
 sqlstm.sqinds[39] = (         int  )0;
 sqlstm.sqharm[39] = (unsigned long )0;
 sqlstm.sqadto[39] = (unsigned short )0;
 sqlstm.sqtdso[39] = (unsigned short )0;
 sqlstm.sqhstv[40] = (unsigned char  *)&hv_cust_deposit_dt_prov;
 sqlstm.sqhstl[40] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[40] = (         int  )0;
 sqlstm.sqindv[40] = (         short *)&ind_cust_deposit_dt_prov;
 sqlstm.sqinds[40] = (         int  )0;
 sqlstm.sqharm[40] = (unsigned long )0;
 sqlstm.sqadto[40] = (unsigned short )0;
 sqlstm.sqtdso[40] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto adddetail_error;
}



DEBUGLOG(("AddDetail:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("AddDetail:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction_AddDetail: SP_OTHER_ERR\n");
DEBUGLOG(("AddDetail: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction_Add: SP_ERR\n");
DEBUGLOG(("AddDetail: SP_ERR\n"));
                return PD_ERR;
        }

adddetail_error:
DEBUGLOG(("adddetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}

int UpdateDetail(const hash_t *hRls)
{
	double	dTmp;
	char*	csPtr;
	char*	csBuf;
	char*	csTxnId;
	int	iTmp;
	char* csQTmp[1024];
        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDetail: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update ol_txn_detail set otd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateDetail:txn_id = [%s]\n",csTxnId));

/* current_bal*/
        if (GetField_Double(hRls,"current_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:current_bal= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",otd_current_bal = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* current_bal_settlement */
        if (GetField_Double(hRls,"current_bal_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:current_bal_settlement= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_current_bal_settlement = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_bal*/
        if (GetField_Double(hRls,"open_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_bal= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",otd_open_bal = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* open_bal_settlement*/
        if (GetField_Double(hRls,"open_bal_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_bal_settlement= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_open_bal_settlement = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float_settlement*/
        if (GetField_Double(hRls,"total_float_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_float_settlement= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_total_float_settlement = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float_after_payout*/
        if (GetField_Double(hRls,"total_float_after_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_float_after_payout= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_total_float_after_payout = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* total_reserved_amount*/
        if (GetField_Double(hRls,"total_reserved_amount",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_reserved_amount= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_total_reserved_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_hold*/
        if (GetField_Double(hRls,"total_hold",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_hold= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",otd_total_hold = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_hold_settlement*/
        if (GetField_Double(hRls,"total_hold_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_hold_settlement= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_total_hold_settlement = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*fundin_payout*/
        if (GetField_Double(hRls,"fundin_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:fundin_payout= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_fundin_payout = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*reserved_payout*/
        if (GetField_Double(hRls,"reserved_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:reserved_payout= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_reserved_payout = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csPtr)) {
DEBUGLOG(("UpdateDetail:txn_country = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_txn_country = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* cust_deposit_datetime */
        if (GetField_CString(hRls,"cust_deposit_datetime",&csPtr)) {
DEBUGLOG(("UpdateDetail:cust_deposit_datetime = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_cust_deposit_datetime = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank_deposit_datetime */
        if (GetField_CString(hRls,"bank_deposit_datetime",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_deposit_datetime = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_bank_deposit_datetime = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* bank_acct_num */
        if (GetField_CString(hRls,"bank_acct_num",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_acct_num = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_bank_acct_num = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* deposit bank code */
        if (GetField_CString(hRls,"deposit_bank_code",&csPtr)) {
DEBUGLOG(("UpdateDetail:deposit_bank_code = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_deposit_bank_code = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* deposit_bank */
        if (GetField_CString(hRls,"deposit_bank",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_name = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_deposit_bank = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* deposit_ref */
        if (GetField_CString(hRls,"deposit_ref",&csPtr)) {
DEBUGLOG(("UpdateDetail:deposit_ref = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_deposit_ref = ");

                sprintf((char *)csQTmp, (char*)PD_Q_QUOTE_VALUE, csPtr);
                csQTmp[strlen(csPtr) + PD_Q_ADD_QUOTE_LEN] = '\0';
DEBUGLOG(("Update: deposit_ref (q_quote) = [%s]\n", csQTmp));

        	strcat((char*)hv_dynstmt.arr, (char *) csQTmp);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank code */
        if (GetField_CString(hRls,"bank_code",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_code = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_bank_code = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* bank name*/
        if (GetField_CString(hRls,"bank_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_name = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",otd_bank_name = ");

                sprintf((char *)csQTmp, (char*)PD_Q_QUOTE_VALUE, csPtr);
                csQTmp[strlen(csPtr) + PD_Q_ADD_QUOTE_LEN] = '\0';
DEBUGLOG(("Update: bank_name (q_quote) = [%s]\n", csQTmp));

                strcat((char*)hv_dynstmt.arr, (char*) csQTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* branch name*/
        if (GetField_CString(hRls,"branch",&csPtr)) {
DEBUGLOG(("UpdateDetail:branch = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_branch_name = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* account name*/
        if (GetField_CString(hRls,"account_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:account_name = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_account_name = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* account id*/
        if (GetField_CString(hRls,"account_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:account_id = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_account_id = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* pay_method */
        if (GetField_CString(hRls,"pay_method",&csPtr)) {
DEBUGLOG(("UpdateDetail:pay_method = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_pay_method = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* selected_pay_method */
        if (GetField_CString(hRls,"selected_pay_method",&csPtr)) {
DEBUGLOG(("UpdateDetail:selected_pay_method = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_selected_pay_method = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update user */
        if (GetField_CString(hRls,"update_user",&csPtr)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* batch_id */
        if (GetField_CString(hRls,"td_batch_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:td_batch_id = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_batch_id = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* fe_domain */
        if (GetField_CString(hRls,"fe_domain",&csPtr)) {
DEBUGLOG(("UpdateDetail:fe_domain = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",otd_fe_domain = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* cust_deposit_id_prov*/
        if (GetField_Int(hRls,"cust_deposit_dt_prov", &iTmp)) {
DEBUGLOG(("UpdateDetail:cust_deposit_id_prov = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",otd_cust_deposit_dt_prov = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char *)hv_dynstmt.arr, " WHERE otd_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )365;
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
 if (sqlca.sqlcode < 0) goto update_detail_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )384;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_detail_error;
}



	FREE_ME(csBuf);


DEBUGLOG(("UpdateDetail Normal Exit\n"));
	return PD_OK;

update_detail_error:
DEBUGLOG(("update_detail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}


int AddTxnStatusLog(const hash_t *hCon)
{
        char    *csTmp;
        char    cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO add_txnstatuslogerror; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_status;
                char            hv_ar_ind;
                /* varchar         hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



                short           ind_txn_id = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_sub_status = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("AddTxnStatusLog: Begin\n"));

        if (GetField_CString(hCon,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
                ind_txn_id = 0;
        }
DEBUGLOG(("AddTxnStatusLog:txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));

        if (GetField_Char(hCon,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddTxnStatusLog: status = [%c]\n",cTmp));
        }

        if (GetField_Char(hCon,"status",&cTmp)) {
                hv_status = cTmp;
                ind_status = 0;
DEBUGLOG(("AddTxnStatusLog: status = [%c]\n",cTmp));
        }

        if (GetField_Char(hCon,"ar_ind",&cTmp)) {
                hv_ar_ind = cTmp;
                ind_ar_ind = 0;
DEBUGLOG(("AddTxnStatusLog: ar_ind = [%c]\n",cTmp));
        }

        if(GetField_CString(hCon,"sub_status",&csTmp))
        {
                hv_sub_status.len = strlen(csTmp);
                strncpy((char*)hv_sub_status.arr, csTmp, hv_sub_status.len);
                ind_sub_status = 0;
DEBUGLOG(("AddTxnStatusLog:sub_status = [%.*s]\n",hv_sub_status.len,hv_sub_status.arr));
        }

        if(GetField_CString(hCon,"add_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
        else if(GetField_CString(hCon,"update_user",&csTmp))
        {
                hv_create_user.len = strlen(csTmp);
                strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
                ind_create_user = 0;
        }
        else{
                hv_create_user.len = strlen("SYSTEM");
                strncpy((char*)hv_create_user.arr,"SYSTEM", hv_create_user.len);
                ind_create_user = 0;
        }
DEBUGLOG(("AddTxnStatusLog:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_txn_status_log_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_status:ind_status,
                                        :hv_ar_ind:ind_ar_ind,
                                        :hv_sub_status:ind_sub_status,
                                        :hv_create_user:ind_create_user);

                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_status_log_inser\
t ( :hv_txn_id:ind_txn_id , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :\
hv_sub_status:ind_sub_status , :hv_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )399;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_status;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ar_ind;
        sqlstm.sqhstl[3] = (unsigned long )1;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_sub_status;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_sub_status;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[5] = (unsigned long )22;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_create_user;
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
        if (sqlca.sqlcode < 0) goto add_txnstatuslogerror;
}




DEBUGLOG(("AddTxnStatusLog:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("AddTxnStatusLog:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnCode_AddTxnStatusLog: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnCode_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_txnstatuslogerror:
DEBUGLOG(("add_txnstatuslogerror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTransaction_add_txnstatuslogerror: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int AddTxnBrowserInfo(const hash_t *hRls)
{
        char            *csTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO addtxnbrowserinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_user_agent[PD_REMARK_LEN*2]; */ 
struct { unsigned short len; unsigned char arr[510]; } hv_user_agent;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

        /* varchar         hv_client_ip[PD_IP_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_client_ip;


        short           ind_txn_id = -1;
        short           ind_user_agent = -1;
        short           ind_add_user = -1;
        short           ind_client_ip= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddTxnBrowserInfo: Begin\n"));

/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddTxnBrowserInfo:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }
/* user agent */
        if (GetField_CString(hRls,"user_agent",&csTmp)) {
                hv_user_agent.len = strlen(csTmp);
                memcpy(hv_user_agent.arr,csTmp,hv_user_agent.len);
                ind_user_agent = 0;
DEBUGLOG(("AddTxnBrowserInfo:user_agent = [%.*s]\n",hv_user_agent.len,hv_user_agent.arr));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("AddTxnBrowserInfo:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


/* client ip */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
                char *p;
                char    csTmpIP[PD_IP_LEN+1];
                p = strtok (csTmp,",");
                while (p != NULL)
                {
                        strcpy(csTmpIP,p);
                        csTmpIP[strlen(p)]='\0';
                        break;
                }
                hv_client_ip.len = strlen(csTmpIP);
                memcpy(hv_client_ip.arr,csTmpIP,hv_client_ip.len);
                ind_client_ip = 0;
DEBUGLOG(("AddTxnBrowserInfo:client_ip = [%.*s]\n",hv_client_ip.len,hv_client_ip.arr));
        }

        if(ind_user_agent == 0){
            /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_txn_browser_info_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_client_ip:ind_client_ip,
                                        :hv_user_agent:ind_user_agent,
                                        :hv_add_user:ind_add_user);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 41;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_browser_info\
_insert ( :hv_txn_id:ind_txn_id , :hv_client_ip:ind_client_ip , :hv_user_agen\
t:ind_user_agent , :hv_add_user:ind_add_user ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )438;
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
            sqlstm.sqhstv[2] = (unsigned char  *)&hv_client_ip;
            sqlstm.sqhstl[2] = (unsigned long )27;
            sqlstm.sqhsts[2] = (         int  )0;
            sqlstm.sqindv[2] = (         short *)&ind_client_ip;
            sqlstm.sqinds[2] = (         int  )0;
            sqlstm.sqharm[2] = (unsigned long )0;
            sqlstm.sqadto[2] = (unsigned short )0;
            sqlstm.sqtdso[2] = (unsigned short )0;
            sqlstm.sqhstv[3] = (unsigned char  *)&hv_user_agent;
            sqlstm.sqhstl[3] = (unsigned long )512;
            sqlstm.sqhsts[3] = (         int  )0;
            sqlstm.sqindv[3] = (         short *)&ind_user_agent;
            sqlstm.sqinds[3] = (         int  )0;
            sqlstm.sqharm[3] = (unsigned long )0;
            sqlstm.sqadto[3] = (unsigned short )0;
            sqlstm.sqtdso[3] = (unsigned short )0;
            sqlstm.sqhstv[4] = (unsigned char  *)&hv_add_user;
            sqlstm.sqhstl[4] = (unsigned long )22;
            sqlstm.sqhsts[4] = (         int  )0;
            sqlstm.sqindv[4] = (         short *)&ind_add_user;
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
            if (sqlca.sqlcode < 0) goto addtxnbrowserinfo_error;
}




DEBUGLOG(("AddTxnBrowserInfo:Ret = [%d]\n",hv_return_value));
                if (hv_return_value == SP_OK) {
DEBUGLOG(("AddTxnBrowserInfo:Normal Exit\n"));
                        return PD_OK;
                }

                if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction_AddTxnBrowserInfo: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_OTHER_ERR TxnAbort\n"));
                        return PD_OTHER_ERR;
                }

                if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction_AddTxnBrowserInfo: SP_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_ERR TxnAbort\n"));
                        return PD_ERR;
                }
        }
        else{
DEBUGLOG(("AddTxnBrowserInfo:user_agent not found. Skip adding\n"));
                        return PD_OK;
        }

addtxnbrowserinfo_error:
DEBUGLOG(("addtxnbrowserinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}


int TxnDepositEdit(hash_t *hCon)
{
	char	*csTmp;
	double	dTmp;
	int	iTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO edit_deposit_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		double	hv_amount;
		/* varchar	hv_cust_deposit_datetime[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_cust_deposit_datetime;

		/* varchar	hv_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_bank_code;

		/* varchar	hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

		/* varchar	hv_deposit_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_deposit_bank_code;

		/* varchar	hv_deposit_bank[PD_BANK_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_bank;

		/* varchar	hv_deposit_ref[PD_BANK_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[150]; } hv_deposit_ref;

		int	hv_match;
		/* varchar	hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;

		/* varchar hv_reason_edit[PD_REASONEDIT_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_reason_edit;


		short	ind_txn_id = -1;
		short	ind_amount = -1;
		short	ind_cust_deposit_datetime = -1;
		short	ind_bank_code = -1;
		short	ind_bank_acct_num = -1;
		short	ind_deposit_bank_code = -1;
		short	ind_deposit_bank = -1;
		short	ind_deposit_ref = -1;
		short	ind_match = -1;
		short	ind_create_user = -1;
		short	ind_reason_edit = -1;

		short	hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 

DEBUGLOG(("TxnDepositEdit: Begin\n"));

	if (GetField_CString(hCon,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
	}
DEBUGLOG(("TxnDepositEdit:txn_id = [%.*s]\n",hv_txn_id.len, hv_txn_id.arr));

	if (GetField_Double(hCon,"deposit_amount",&dTmp)) {
		hv_amount = dTmp;
		ind_amount = 0;
	}
DEBUGLOG(("TxnDepositEdit:deposit_amount = [%.2lf]\n",hv_amount));

	if (GetField_CString(hCon,"cust_deposit_datetime",&csTmp)) {
		hv_cust_deposit_datetime.len = strlen(csTmp);
		strncpy((char*)hv_cust_deposit_datetime.arr, csTmp, hv_cust_deposit_datetime.len);
		ind_cust_deposit_datetime = 0;
DEBUGLOG(("TxnDepositEdit:cust_deposit_datetime = [%.*s]\n",hv_cust_deposit_datetime.len, hv_cust_deposit_datetime.arr));
	}

	if (GetField_CString(hCon,"int_bank_code",&csTmp)) {
		hv_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_bank_code.arr, csTmp, hv_bank_code.len);
		ind_bank_code = 0;
	}
DEBUGLOG(("TxnDepositEdit:bank_code = [%.*s]\n",hv_bank_code.len, hv_bank_code.arr));

	if (GetField_CString(hCon,"bank_acct_num",&csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
	}
DEBUGLOG(("TxnDepositEdit:bank_acct_num = [%.*s]\n",hv_bank_acct_num.len, hv_bank_acct_num.arr));

	if (GetField_CString(hCon,"deposit_bank_code",&csTmp)) {
		hv_deposit_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_deposit_bank_code.arr, csTmp, hv_deposit_bank_code.len);
		ind_deposit_bank_code = 0;
	}
DEBUGLOG(("TxnDepositEdit:deposit_bank_code = [%.*s]\n",hv_deposit_bank_code.len, hv_deposit_bank_code.arr));

	if (GetField_CString(hCon,"deposit_bank",&csTmp)) {
		hv_deposit_bank.len = strlen(csTmp);
		strncpy((char*)hv_deposit_bank.arr, csTmp, hv_deposit_bank.len);
		ind_deposit_bank = 0;
DEBUGLOG(("TxnDepositEdit:deposit_bank = [%.*s]\n",hv_deposit_bank.len, hv_deposit_bank.arr));
	}

	if (GetField_CString(hCon,"deposit_ref",&csTmp)) {
		hv_deposit_ref.len = strlen(csTmp);
		strncpy((char*)hv_deposit_ref.arr, csTmp, hv_deposit_ref.len);
		ind_deposit_ref = 0;
DEBUGLOG(("TxnDepositEdit:deposit_ref = [%.*s]\n",hv_deposit_ref.len, hv_deposit_ref.arr));
	}

	hv_match = 0;
	if (GetField_Int(hCon,"match",&iTmp)) {
		hv_match = iTmp;
	}
	ind_match = 0;
DEBUGLOG(("TxnDepositEdit:match = [%d]\n",hv_match));

	if(GetField_CString(hCon,"add_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
	else if(GetField_CString(hCon,"update_user",&csTmp))
	{
		hv_create_user.len = strlen(csTmp);
		strncpy((char*)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
	}
	else{
		hv_create_user.len = strlen("SYSTEM");
		strncpy((char*)hv_create_user.arr,"SYSTEM", hv_create_user.len);
		ind_create_user = 0;
	}
DEBUGLOG(("TxnDepositEdit:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

/* PRD171 Add reason for edit */
	if(GetField_CString(hCon,"reason_edit",&csTmp))
	{
		hv_reason_edit.len = strlen(csTmp);
/* No delimitor needed for static sql
		strncpy((char*)hv_reason_edit.arr, ESC_string(csTmp), hv_reason_edit.len);
*/
		strncpy((char*)hv_reason_edit.arr, csTmp, hv_reason_edit.len);
		ind_reason_edit = 0;
DEBUGLOG(("TxnDepositEdit:reason_edit = [%.*s]\n",hv_reason_edit.len, hv_reason_edit.arr));
	}
/* End -  PRD171 Add reason for edit */

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_deposit_edit_check(
					:hv_txn_id:ind_txn_id,
					:hv_amount:ind_amount,
					:hv_cust_deposit_datetime:ind_cust_deposit_datetime,
					:hv_bank_code:ind_bank_code,
					:hv_bank_acct_num:ind_bank_acct_num,
					:hv_deposit_bank_code:ind_deposit_bank_code,
					:hv_deposit_bank:ind_deposit_bank,
					:hv_deposit_ref:ind_deposit_ref);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_deposit_edit_check ( :h\
v_txn_id:ind_txn_id , :hv_amount:ind_amount , :hv_cust_deposit_datetime:ind_c\
ust_deposit_datetime , :hv_bank_code:ind_bank_code , :hv_bank_acct_num:ind_ba\
nk_acct_num , :hv_deposit_bank_code:ind_deposit_bank_code , :hv_deposit_bank:\
ind_deposit_bank , :hv_deposit_ref:ind_deposit_ref ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )473;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_amount;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_cust_deposit_datetime;
 sqlstm.sqhstl[3] = (unsigned long )16;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_cust_deposit_datetime;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )27;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_deposit_bank_code;
 sqlstm.sqhstl[6] = (unsigned long )27;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_deposit_bank_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_deposit_bank;
 sqlstm.sqhstl[7] = (unsigned long )152;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_deposit_bank;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_deposit_ref;
 sqlstm.sqhstl[8] = (unsigned long )152;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_deposit_ref;
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
 if (sqlca.sqlcode < 0) goto edit_deposit_error;
}



	if (hv_return_value == SP_OK) {
		PutField_Int(hCon, "remove_pair", PD_TRUE);
	} else {
		PutField_Int(hCon, "remove_pair", PD_FALSE);
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_deposit_edit_v2(
					:hv_txn_id:ind_txn_id,
					:hv_amount:ind_amount,
					:hv_cust_deposit_datetime:ind_cust_deposit_datetime,
					:hv_bank_code:ind_bank_code,
					:hv_bank_acct_num:ind_bank_acct_num,
					:hv_deposit_bank_code:ind_deposit_bank_code,
					:hv_deposit_bank:ind_deposit_bank,
					:hv_deposit_ref:ind_deposit_ref,
					:hv_match:ind_match,
					:hv_reason_edit:ind_reason_edit,
					:hv_create_user:ind_create_user);

		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_deposit_edit_v2 ( :hv_t\
xn_id:ind_txn_id , :hv_amount:ind_amount , :hv_cust_deposit_datetime:ind_cust\
_deposit_datetime , :hv_bank_code:ind_bank_code , :hv_bank_acct_num:ind_bank_\
acct_num , :hv_deposit_bank_code:ind_deposit_bank_code , :hv_deposit_bank:ind\
_deposit_bank , :hv_deposit_ref:ind_deposit_ref , :hv_match:ind_match , :hv_r\
eason_edit:ind_reason_edit , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )524;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_amount;
 sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_amount;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_cust_deposit_datetime;
 sqlstm.sqhstl[3] = (unsigned long )16;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_cust_deposit_datetime;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[4] = (unsigned long )27;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_bank_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_acct_num;
 sqlstm.sqhstl[5] = (unsigned long )52;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_acct_num;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_deposit_bank_code;
 sqlstm.sqhstl[6] = (unsigned long )27;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_deposit_bank_code;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_deposit_bank;
 sqlstm.sqhstl[7] = (unsigned long )152;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_deposit_bank;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_deposit_ref;
 sqlstm.sqhstl[8] = (unsigned long )152;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_deposit_ref;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_match;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_match;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_reason_edit;
 sqlstm.sqhstl[10] = (unsigned long )32;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_reason_edit;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_create_user;
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
 if (sqlca.sqlcode < 0) goto edit_deposit_error;
}




DEBUGLOG(("TxnDepositEdit:Ret = [%d]\n",hv_return_value));
	if (hv_return_value == SP_OK)
	{
DEBUGLOG(("TxnDepositEdit:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnCode_TxnDepositEdit: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR)  {
ERRLOG("TxnCode_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}


edit_deposit_error:
DEBUGLOG(("edit_deposit_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTransaction_edit_deposit_error: SP_INTERNAL_ERR TxnAbort\n");
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_INTERNAL_ERR;
}

int MatchMerchantRef(const char* csMerchantId,
                     const char* csMerchantRef)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO matchmerchantref_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;
                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;


    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("MatchMerchantRef merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    
        hv_merchant_ref.len = strlen(csMerchantRef);
        memcpy(hv_merchant_ref.arr,csMerchantRef,hv_merchant_ref.len);
DEBUGLOG(("MatchMerchantRef merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_transaction_matchmref(:hv_merchant_id,
                                                                     :hv_merchant_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_transaction_matchmre\
f ( :hv_merchant_id , :hv_merchant_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )587;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto matchmerchantref_error;
}



        if (hv_return_value > 0)  {

DEBUGLOG(("MatchMerchantref Found\n"));
                return FOUND;
        }
        else {
DEBUGLOG(("MatchMerchantref Not Found\n"));
                return NOT_FOUND;
        }


matchmerchantref_error:
DEBUGLOG(("matchmerchantref_error code %d\n", sqlca.sqlcode));
ERRLOG("OLTransaction::matchmerchantref_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetTxnHeader(const char* csTxnID,
                recordset_t* myRec)
{

        char    csDate[PD_DATE_LEN +1];
        char    csTime[PD_TIME_LEN +1];
        char    csDateTime[PD_DATE_LEN + PD_TIME_LEN +1];
        hash_t *myHash;
        int     iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                /* varchar         v_org_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_org_txn_id;

                /* varchar         v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

                char            v_status;
                char            v_ar_ind;
                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

                double          v_txn_amt;
                double          v_net_amt;
                /* varchar         v_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_net_ccy;

                /* varchar         v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

                /* varchar         v_local_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

                /* varchar         v_local_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_local_tm_time;

                /* varchar         v_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_tm_date;

                /* varchar         v_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_tm_time;

                long            v_internal_code;
                /* varchar         v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

                /* varchar         v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_response_code;

                /* varchar         v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

                /* varchar         v_process_code[PD_PROCESS_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;

                /* varchar         v_process_type[PD_PROCESS_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

                /* varchar         v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

                /* varchar         v_client_ip[PD_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;

                char            v_ex_supplier;
                double          v_ex_rate;
                /* varchar         v_sub_status[PD_SUB_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

                double          v_display_amt;
		double		v_deposit_amt;
		/* varchar		v_dst_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_dst_txn_id;

		int		v_upload_channel;
		int		v_multi_match_ind;
		double		v_reserve_amt;
		/* varchar		v_reserved_release_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_reserved_release_date;

                char            v_recon_status;



                short           ind_org_txn_id = -1;
                short           ind_client_id = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_txn_code = -1;
                short           ind_merchant_id = -1;
                short           ind_merchant_ref = -1;
                short           ind_txn_amt = -1;
                short           ind_net_amt = -1;
                short           ind_net_ccy = -1;
                short           ind_transmission_datetime = -1;
                short           ind_local_tm_date = -1;
                short           ind_local_tm_time = -1;
                short           ind_tm_date = -1;
                short           ind_tm_time = -1;
                short           ind_internal_code = -1;
                short           ind_channel_code = -1;
                short           ind_response_code = -1;
                short           ind_host_posting_date = -1;
                short           ind_process_code= -1;
                short           ind_process_type= -1;
                short           ind_service_code = -1;
                short           ind_client_ip = -1;
                short           ind_ex_supplier = -1;
                short           ind_ex_rate = -1;
                short           ind_sub_status = -1;
                short           ind_display_amt = -1;
		short		ind_deposit_amt = -1;
		short		ind_dst_txn_id = -1;
		short		ind_upload_channel = -1;
		short		ind_multi_match_ind = -1;
		short		ind_reserve_amt = -1;
		short		ind_reserved_release_date = -1;
                short           ind_recon_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 



        hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnHeader txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_getoltxnheader CURSOR FOR
                select oth_org_txn_id,
                       oth_client_id,
                       oth_status,
                       oth_ar_ind,
                       oth_txn_code,
                       oth_merchant_id,
                       oth_merchant_ref,
                       oth_transaction_amount,
                       oth_net_amount,
                       oth_net_ccy,
                       oth_transmission_datetime,
                       oth_local_tm_date,
                       oth_local_tm_time,
                       oth_tm_date,
                       oth_tm_time,
                       oth_internal_code,
                       oth_input_channel,
                       oth_response_code,
                       oth_host_posting_date,
                       oth_process_code,
                       oth_process_type,
                       oth_input_channel,
                       oth_service_code,
                       oth_client_ip,
                       oth_ex_supplier,
                       oth_ex_rate,
                       oth_sub_status,
		       oth_display_amount,
		       oth_deposit_amount,
		       oth_dst_txn_id,
		       oth_upload_channel,
		       oth_multi_match_ind,
		       oth_reserve_amount,
		       oth_reserved_release_date,
		       oth_recon_status
                  from ol_txn_header
                 where oth_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_getoltxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0009;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )614;
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
                /* EXEC SQL FETCH c_cursor_getoltxnheader
                INTO
                        :v_org_txn_id:ind_org_txn_id,
                        :v_client_id:ind_client_id,
                        :v_status:ind_status,
                        :v_ar_ind:ind_ar_ind,
                        :v_txn_code:ind_txn_code,
                        :v_merchant_id:ind_merchant_id,
                        :v_merchant_ref:ind_merchant_ref,
                        :v_txn_amt:ind_txn_amt,
                        :v_net_amt:ind_net_amt,
                        :v_net_ccy:ind_net_ccy,
                        :v_transmission_datetime:ind_transmission_datetime,
                        :v_local_tm_date:ind_local_tm_date,
                        :v_local_tm_time:ind_local_tm_time,
                        :v_tm_date:ind_tm_date,
                        :v_tm_time:ind_tm_time,
                        :v_internal_code:ind_internal_code,
                        :v_channel_code:ind_channel_code,
                        :v_response_code:ind_response_code,
                        :v_host_posting_date:ind_host_posting_date,
                        :v_process_code:ind_process_code,
                        :v_process_type:ind_process_type,
                        :v_channel_code:ind_channel_code,
                        :v_service_code:ind_service_code,
                        :v_client_ip:ind_client_ip,
                        :v_ex_supplier:ind_ex_supplier,
                        :v_ex_rate:ind_ex_rate,
                        :v_sub_status:ind_sub_status,
                        :v_display_amt:ind_display_amt,
			:v_deposit_amt:ind_deposit_amt,
			:v_dst_txn_id:ind_dst_txn_id,
			:v_upload_channel:ind_upload_channel,
			:v_multi_match_ind:ind_multi_match_ind,
			:v_reserve_amt:ind_reserve_amt,
			:v_reserved_release_date:ind_reserved_release_date,
                        :v_recon_status:ind_recon_status; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 41;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )633;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[1] = (unsigned long )13;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_client_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_status;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[3] = (unsigned long )1;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code;
                sqlstm.sqhstl[4] = (unsigned long )6;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_txn_code;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_ref;
                sqlstm.sqhstl[6] = (unsigned long )53;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_merchant_ref;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_net_amt;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_net_amt;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_net_ccy;
                sqlstm.sqhstl[9] = (unsigned long )6;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_net_ccy;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_transmission_datetime;
                sqlstm.sqhstl[10] = (unsigned long )17;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_transmission_datetime;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_local_tm_date;
                sqlstm.sqhstl[11] = (unsigned long )11;
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_local_tm_date;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_local_tm_time;
                sqlstm.sqhstl[12] = (unsigned long )9;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_local_tm_time;
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
                sqlstm.sqhstv[15] = (unsigned char  *)&v_internal_code;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(long);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_internal_code;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[16] = (unsigned long )6;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_channel_code;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[17] = (unsigned long )13;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_response_code;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[18] = (unsigned long )11;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_process_code;
                sqlstm.sqhstl[19] = (unsigned long )9;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_process_code;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_process_type;
                sqlstm.sqhstl[20] = (unsigned long )7;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_process_type;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[21] = (unsigned long )6;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_channel_code;
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
                sqlstm.sqhstv[23] = (unsigned char  *)&v_client_ip;
                sqlstm.sqhstl[23] = (unsigned long )28;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_client_ip;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_ex_supplier;
                sqlstm.sqhstl[24] = (unsigned long )1;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_ex_supplier;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_ex_rate;
                sqlstm.sqhstl[25] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_ex_rate;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[26] = (unsigned long )6;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_sub_status;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_display_amt;
                sqlstm.sqhstl[27] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_display_amt;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_deposit_amt;
                sqlstm.sqhstl[28] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_deposit_amt;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_dst_txn_id;
                sqlstm.sqhstl[29] = (unsigned long )19;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_dst_txn_id;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_upload_channel;
                sqlstm.sqhstl[30] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_upload_channel;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_multi_match_ind;
                sqlstm.sqhstl[31] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_multi_match_ind;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
                sqlstm.sqhstv[32] = (unsigned char  *)&v_reserve_amt;
                sqlstm.sqhstl[32] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[32] = (         int  )0;
                sqlstm.sqindv[32] = (         short *)&ind_reserve_amt;
                sqlstm.sqinds[32] = (         int  )0;
                sqlstm.sqharm[32] = (unsigned long )0;
                sqlstm.sqadto[32] = (unsigned short )0;
                sqlstm.sqtdso[32] = (unsigned short )0;
                sqlstm.sqhstv[33] = (unsigned char  *)&v_reserved_release_date;
                sqlstm.sqhstl[33] = (unsigned long )11;
                sqlstm.sqhsts[33] = (         int  )0;
                sqlstm.sqindv[33] = (         short *)&ind_reserved_release_date;
                sqlstm.sqinds[33] = (         int  )0;
                sqlstm.sqharm[33] = (unsigned long )0;
                sqlstm.sqadto[33] = (unsigned short )0;
                sqlstm.sqtdso[33] = (unsigned short )0;
                sqlstm.sqhstv[34] = (unsigned char  *)&v_recon_status;
                sqlstm.sqhstl[34] = (unsigned long )1;
                sqlstm.sqhsts[34] = (         int  )0;
                sqlstm.sqindv[34] = (         short *)&ind_recon_status;
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
                if (sqlca.sqlcode < 0) goto gettxnheader_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_org_txn_id >= 0) {
                        v_org_txn_id.arr[v_org_txn_id.len] ='\0';
                        PutField_CString(myHash,"org_txn_id",(const char*)v_org_txn_id.arr);
DEBUGLOG(("org_txn_id = [%s]\n",v_org_txn_id.arr));
                }

                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] ='\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("client_id = [%s]\n",v_client_id.arr));
                }
                if (ind_status >= 0) {
DEBUGLOG(("status = [%c]\n",v_status));
                        PutField_Char(myHash,"status",v_status);
                }

                if (ind_ar_ind >= 0) {
DEBUGLOG(("ar_ind = [%c]\n",v_ar_ind));
                        PutField_Char(myHash,"ar_ind",v_ar_ind);
                }

                if (ind_txn_code >= 0) {
                        v_txn_code.arr[v_txn_code.len] ='\0';
                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("txn_code = [%s]\n",v_txn_code.arr));
                }

                if (ind_process_code >= 0) {
                        v_process_code.arr[v_process_code.len] ='\0';
                        PutField_CString(myHash,"process_code",(const char*)v_process_code.arr);
DEBUGLOG(("process_code = [%s]\n",v_process_code.arr));
                }

                if (ind_process_type >= 0) {
                        v_process_type.arr[v_process_type.len] ='\0';
                        PutField_CString(myHash,"process_type",(const char*)v_process_type.arr);
DEBUGLOG(("process_type = [%s]\n",v_process_type.arr));
                }


                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("merchant_id = [%s]\n",v_merchant_id.arr));
                }
                if (ind_merchant_ref >= 0) {
                        v_merchant_ref.arr[v_merchant_ref.len] ='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("merchant_ref = [%s]\n",v_merchant_ref.arr));
                }

                if (ind_txn_amt < 0)
                        v_txn_amt = 0.0;

                PutField_Double(myHash,"txn_amt",v_txn_amt);

DEBUGLOG(("txn_amt = [%f]\n",v_txn_amt));

                if (ind_net_amt < 0)
                        v_net_amt = 0.0;


                PutField_Double(myHash,"net_amt",v_net_amt);
DEBUGLOG(("net_amt = [%f]\n",v_net_amt));

                if (ind_net_ccy >= 0) {
                        v_net_ccy.arr[v_net_ccy.len] ='\0';
                        PutField_CString(myHash,"net_ccy",(const char*)v_net_ccy.arr);
DEBUGLOG(("net_ccy = [%s]\n",v_net_ccy.arr));
                }

                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("transmission_datetime = [%s]\n",v_transmission_datetime.arr));
                }
                if (ind_local_tm_date >= 0) {
                        v_local_tm_date.arr[v_local_tm_date.len] ='\0';
                        strcpy(csDate,(char*)v_local_tm_date.arr);
                        PutField_CString(myHash,"local_tm_date",(const char*)v_local_tm_date.arr);
DEBUGLOG(("local_tm_date = [%s]\n",v_local_tm_date.arr));
                }
                if (ind_local_tm_time >= 0) {
                        v_local_tm_time.arr[v_local_tm_time.len] ='\0';
                        strcpy(csTime,(char*)v_local_tm_time.arr);
                        PutField_CString(myHash,"local_tm_time",(const char*)v_local_tm_time.arr);
DEBUGLOG(("local_tm_time = [%s]\n",v_local_tm_time.arr));
                }
                if (ind_tm_date >= 0) {
                        v_tm_date.arr[v_tm_date.len] ='\0';
                        PutField_CString(myHash,"tm_date",(const char*)v_tm_date.arr);
DEBUGLOG(("tm_date = [%s]\n",v_tm_date.arr));
                }
                if (ind_tm_time >= 0) {
                        v_tm_time.arr[v_tm_time.len] ='\0';
                        PutField_CString(myHash,"tm_time",(const char*)v_tm_time.arr);
DEBUGLOG(("tm_time = [%s]\n",v_tm_time.arr));
                }
                if (ind_internal_code >= 0) {
                        PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("internal_code = [%d]\n",v_internal_code));
                }
                if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] ='\0';
                        PutField_CString(myHash,"channel_code",(const char*)v_channel_code.arr);
DEBUGLOG(("channel_code = [%s]\n",v_channel_code.arr));
                }


                if (ind_response_code >= 0) {
                        v_response_code.arr[v_response_code.len] ='\0';
                        PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("response_code = [%s]\n",v_response_code.arr));
                }
                if (ind_host_posting_date >= 0) {
                        v_host_posting_date.arr[v_host_posting_date.len] ='\0';
                        PutField_CString(myHash,"host_posting_date",(const char*)v_host_posting_date.arr);
DEBUGLOG(("host_posting_date = [%s]\n",v_host_posting_date.arr));
                }

DEBUGLOG(("formation local transmission_datetime\n"));
                strcpy(csDateTime,csDate);
                strcat(csDateTime,csTime);
DEBUGLOG(("local_transmission_datetime = [%s]\n",csDateTime));
                PutField_CString(myHash,"local_transmission_datetime",csDateTime);

                if (ind_service_code >= 0) {
                        v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("service_code = [%s]\n",v_service_code.arr));
                }

                if (ind_client_ip>= 0) {
                        v_client_ip.arr[v_client_ip.len] ='\0';
                        PutField_CString(myHash,"ip_addr",(const char*)v_client_ip.arr);
DEBUGLOG(("client_ip = [%s]\n",v_client_ip.arr));
                }

                if (ind_ex_supplier>= 0) {
DEBUGLOG(("ex_supplier = [%c]\n",v_ex_supplier));
                        PutField_Char(myHash,"ex_supplier",v_ex_supplier);
                }

                if (ind_ex_rate < 0)
                        v_ex_rate = 0.0;
DEBUGLOG(("ex_rate = [%f]\n",v_ex_rate));
                PutField_Double(myHash,"ex_rate",v_ex_rate);


                if (ind_sub_status>= 0) {
                        v_sub_status.arr[v_sub_status.len] ='\0';
                        PutField_CString(myHash,"sub_status",(const char*)v_sub_status.arr);
DEBUGLOG(("sub_status = [%s]\n",v_sub_status.arr));
                }

                if (ind_display_amt < 0)
                        v_display_amt = 0.0;
                PutField_Double(myHash,"display_amt",v_display_amt);
DEBUGLOG(("display_amt = [%f]\n",v_display_amt));


                if (ind_deposit_amt < 0)
                        v_deposit_amt = 0.0;
                PutField_Double(myHash,"deposit_amt",v_deposit_amt);
DEBUGLOG(("deposit_amt = [%f]\n",v_deposit_amt));


                if (ind_dst_txn_id >= 0) {
                        v_dst_txn_id.arr[v_dst_txn_id.len] ='\0';
                        PutField_CString(myHash,"dst_txn_id",(const char*)v_dst_txn_id.arr);
DEBUGLOG(("dst_txn_id = [%s]\n",v_dst_txn_id.arr));
                }

		if (ind_upload_channel >= 0) {
			PutField_Int(myHash, "upload_channel", v_upload_channel);
DEBUGLOG(("upload_channel = [%d]\n", v_upload_channel));
		}

		if (ind_multi_match_ind >= 0) {
			PutField_Int(myHash, "multi_match_ind", v_multi_match_ind);
DEBUGLOG(("multi_match_ind = [%d]\n", v_multi_match_ind));
		}

		if (ind_reserve_amt < 0)
			v_reserve_amt = 0.0;
DEBUGLOG(("reserve_amt = [%f]\n", v_reserve_amt));
		PutField_Double(myHash, "reserve_amt", v_reserve_amt);

		if (ind_reserved_release_date >= 0) {
			v_reserved_release_date.arr[v_reserved_release_date.len] = '\0';
			PutField_CString(myHash, "reserved_release_date", (const char*)v_reserved_release_date.arr);
DEBUGLOG(("reserved_release_date = [%s]\n", v_reserved_release_date.arr));
		}

                if (ind_recon_status >= 0) {
DEBUGLOG(("recon_status = [%c]\n",v_recon_status));
                        PutField_Char(myHash,"recon_status",v_recon_status);
                }


                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getoltxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )788;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxnheader_error;
}




        if (iCnt > 0 ) {
DEBUGLOG(("GetTxnHeader Normal Exit\n"));
                return  PD_OK;
        }
        else {
DEBUGLOG(("GetTxnHeader Normal Exit, Not Found\n"));
                return PD_ERR;
        }

gettxnheader_error:
DEBUGLOG(("gettxnheader_error code %d\n", sqlca.sqlcode));
ERRLOG("OLTransaction::gettxnheader_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getoltxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )803;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int GetTxnDetail(const char* csTxnID,
                recordset_t* myRec)
{

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO getoltxndetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                /* varchar         v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                /* varchar         v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

                /* varchar         v_pay_method[PD_PAY_METHOD_LIST_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pay_method;

                /* varchar         v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

                /* varchar         v_language[PD_LANGUAGE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_language;

                /* varchar         v_success_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_success_url;

                /* varchar         v_failure_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_failure_url;

                /* varchar         v_success_ck_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_success_ck_url;

                /* varchar         v_failure_ck_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_failure_ck_url;

                /* varchar         v_encrypt_type[PD_ENCRYPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_encrypt_type;

                /* varchar         v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

                /* varchar         v_branch[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

                /* varchar         v_account_id[PD_AC_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_id;

                /* varchar         v_account_name[PD_AC_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

                /* varchar         v_batch_id[PD_BATCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_batch_id;

                /* varchar         v_identity_id[PD_IDENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

                /* varchar         v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

                /* varchar         v_selected_pay_method[PD_SELECTED_PAY_METHOD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_selected_pay_method;

                /* varchar         v_banner_logo[PD_BANNER_LOGO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_banner_logo;

                /* varchar         v_echo_msg_1[PD_ECHO_MSG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_echo_msg_1;

                /* varchar         v_echo_msg_2[PD_ECHO_MSG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_echo_msg_2;

                /* varchar         v_echo_msg_3[PD_ECHO_MSG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_echo_msg_3;

                /* varchar         v_opt_1[PD_OPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_opt_1;

                /* varchar         v_opt_2[PD_OPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_opt_2;

                /* varchar         v_opt_3[PD_OPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_opt_3;

                /* varchar		v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

		/* varchar		v_cust_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cust_deposit_datetime;

		/* varchar		v_bank_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_bank_deposit_datetime;

		/* varchar		v_deposit_bank[PD_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_bank;

		/* varchar         v_deposit_bank_code[PD_AC_BANK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_deposit_bank_code;

		/* varchar		v_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_ref;

		/* varchar         v_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_province;

        	/* varchar         v_phone_no[PD_PHONE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } v_phone_no;

       	 	/* varchar         v_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } v_city;


                short           ind_txn_ccy = -1;
                short           ind_txn_country = -1;
                short           ind_pay_method = -1;
                short           ind_bank_code = -1;
                short           ind_language = -1;
                short           ind_success_url = -1;
                short           ind_failure_url = -1;
                short           ind_success_ck_url = -1;
                short           ind_failure_ck_url = -1;
                short           ind_encrypt_type = -1;
                short           ind_bank_name = -1;
                short           ind_branch= -1;
                short           ind_account_id= -1;
                short           ind_account_name= -1;
                short           ind_batch_id= -1;
                short           ind_identity_id= -1;
                short           ind_remark = -1;
                short           ind_selected_pay_method = -1;
                short           ind_banner_logo = -1;
                short           ind_echo_msg_1 = -1;
                short           ind_echo_msg_2 = -1;
                short           ind_echo_msg_3 = -1;
                short           ind_opt_1 = -1;
                short           ind_opt_2 = -1;
                short           ind_opt_3 = -1;
                short           ind_bank_acct_num = -1;
		short		ind_cust_deposit_datetime = -1;
		short		ind_bank_deposit_datetime = -1;
		short		ind_deposit_bank = -1;
		short		ind_deposit_bank_code = -1;
		short		ind_deposit_ref = -1;
		short           ind_province = -1;
		short           ind_phone_no = -1;
		short           ind_city = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_getoltxndetail CURSOR FOR
                select
                        otd_txn_ccy,
                        otd_txn_country,
                        otd_pay_method,
                        otd_bank_code,
                        otd_language,
                        otd_success_url,
                        otd_failure_url,
                        otd_success_callback_url,
                        otd_failure_callback_url,
                        otd_encrypt_type,
                        otd_bank_name,
                        otd_branch_name,
                        otd_account_id,
                        otd_account_name,
                        otd_batch_id,
                        otd_identity_id,
                        otd_remark,
                        otd_selected_pay_method,
                        otd_banner_logo,
                        otd_echo_msg_1,
                        otd_echo_msg_2,
                        otd_echo_msg_3,
                        otd_opt_1,
                        otd_opt_2,
                        otd_opt_3,
			otd_bank_acct_num,
			otd_cust_deposit_datetime,
			otd_bank_deposit_datetime,
			otd_deposit_bank,
                        otd_deposit_bank_code,
			otd_deposit_ref,
			otd_province,
			otd_phone_no,
			otd_city
                  from ol_txn_detail
                 where otd_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_getoltxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0010;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )818;
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
        if (sqlca.sqlcode < 0) goto getoltxndetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getoltxndetail
                INTO
                        :v_txn_ccy:ind_txn_ccy,
                        :v_txn_country:ind_txn_country,
                        :v_pay_method:ind_pay_method,
                        :v_bank_code:ind_bank_code,
                        :v_language:ind_language,
                        :v_success_url:ind_success_url,
                        :v_failure_url:ind_failure_url,
                        :v_success_ck_url:ind_success_ck_url,
                        :v_failure_ck_url:ind_failure_ck_url,
                        :v_encrypt_type:ind_encrypt_type,
                        :v_bank_name:ind_bank_name,
                        :v_branch:ind_branch,
                        :v_account_id:ind_account_id,
                        :v_account_name:ind_account_name,
                        :v_batch_id:ind_batch_id,
                        :v_identity_id:ind_identity_id,
                        :v_remark:ind_remark,
                        :v_selected_pay_method:ind_selected_pay_method,
                        :v_banner_logo:ind_banner_logo,
                        :v_echo_msg_1:ind_echo_msg_1,
                        :v_echo_msg_2:ind_echo_msg_2,
                        :v_echo_msg_3:ind_echo_msg_3,
                        :v_opt_1:ind_opt_1,
                        :v_opt_2:ind_opt_2,
                        :v_opt_3:ind_opt_3,
                        :v_bank_acct_num:ind_bank_acct_num,
			:v_cust_deposit_datetime:ind_cust_deposit_datetime,
			:v_bank_deposit_datetime:ind_bank_deposit_datetime,
			:v_deposit_bank:ind_deposit_bank,
			:v_deposit_bank_code:ind_deposit_bank_code,
			:v_deposit_ref:ind_deposit_ref,
			:v_province:ind_province,
			:v_phone_no:ind_phone_no,
			:v_city:ind_city; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 41;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )837;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[0] = (unsigned long )6;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_country;
                sqlstm.sqhstl[1] = (unsigned long )5;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_txn_country;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_pay_method;
                sqlstm.sqhstl[2] = (unsigned long )53;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_pay_method;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_bank_code;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_bank_code;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_language;
                sqlstm.sqhstl[4] = (unsigned long )5;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_language;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_success_url;
                sqlstm.sqhstl[5] = (unsigned long )258;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_success_url;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_failure_url;
                sqlstm.sqhstl[6] = (unsigned long )258;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_failure_url;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_success_ck_url;
                sqlstm.sqhstl[7] = (unsigned long )258;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_success_ck_url;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_failure_ck_url;
                sqlstm.sqhstl[8] = (unsigned long )258;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_failure_ck_url;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_encrypt_type;
                sqlstm.sqhstl[9] = (unsigned long )7;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_encrypt_type;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_name;
                sqlstm.sqhstl[10] = (unsigned long )153;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_bank_name;
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
                sqlstm.sqhstv[12] = (unsigned char  *)&v_account_id;
                sqlstm.sqhstl[12] = (unsigned long )28;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_account_id;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[13] = (unsigned long )103;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_account_name;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[14] = (unsigned long )23;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_batch_id;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[15] = (unsigned long )28;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_identity_id;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_remark;
                sqlstm.sqhstl[16] = (unsigned long )258;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_remark;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_selected_pay_method;
                sqlstm.sqhstl[17] = (unsigned long )7;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_selected_pay_method;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_banner_logo;
                sqlstm.sqhstl[18] = (unsigned long )258;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_banner_logo;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_echo_msg_1;
                sqlstm.sqhstl[19] = (unsigned long )258;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_echo_msg_1;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_echo_msg_2;
                sqlstm.sqhstl[20] = (unsigned long )258;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_echo_msg_2;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_echo_msg_3;
                sqlstm.sqhstl[21] = (unsigned long )258;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_echo_msg_3;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_opt_1;
                sqlstm.sqhstl[22] = (unsigned long )53;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_opt_1;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_opt_2;
                sqlstm.sqhstl[23] = (unsigned long )53;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_opt_2;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_opt_3;
                sqlstm.sqhstl[24] = (unsigned long )53;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_opt_3;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_bank_acct_num;
                sqlstm.sqhstl[25] = (unsigned long )53;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_bank_acct_num;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_cust_deposit_datetime;
                sqlstm.sqhstl[26] = (unsigned long )17;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_cust_deposit_datetime;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_bank_deposit_datetime;
                sqlstm.sqhstl[27] = (unsigned long )17;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_bank_deposit_datetime;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_deposit_bank;
                sqlstm.sqhstl[28] = (unsigned long )153;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_deposit_bank;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_deposit_bank_code;
                sqlstm.sqhstl[29] = (unsigned long )28;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_deposit_bank_code;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_deposit_ref;
                sqlstm.sqhstl[30] = (unsigned long )153;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_deposit_ref;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_province;
                sqlstm.sqhstl[31] = (unsigned long )102;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_province;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
                sqlstm.sqhstv[32] = (unsigned char  *)&v_phone_no;
                sqlstm.sqhstl[32] = (unsigned long )32;
                sqlstm.sqhsts[32] = (         int  )0;
                sqlstm.sqindv[32] = (         short *)&ind_phone_no;
                sqlstm.sqinds[32] = (         int  )0;
                sqlstm.sqharm[32] = (unsigned long )0;
                sqlstm.sqadto[32] = (unsigned short )0;
                sqlstm.sqtdso[32] = (unsigned short )0;
                sqlstm.sqhstv[33] = (unsigned char  *)&v_city;
                sqlstm.sqhstl[33] = (unsigned long )102;
                sqlstm.sqhsts[33] = (         int  )0;
                sqlstm.sqindv[33] = (         short *)&ind_city;
                sqlstm.sqinds[33] = (         int  )0;
                sqlstm.sqharm[33] = (unsigned long )0;
                sqlstm.sqadto[33] = (unsigned short )0;
                sqlstm.sqtdso[33] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getoltxndetail_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);


/* txn ccy */
                if (ind_txn_ccy  >=  0) {
                        v_txn_ccy.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetTxnDetail txn_ccy = [%s]\n",v_txn_ccy.arr));
                }

/* txn country */
                if (ind_txn_country  >=  0) {
                        v_txn_country.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_country",(const char*)v_txn_country.arr);
DEBUGLOG(("GetTxnDetail txn_country = [%s]\n",v_txn_country.arr));
                }

/* pay method */
                if (ind_pay_method  >=  0) {
                        v_pay_method.arr[v_pay_method.len] = '\0';
                        PutField_CString(myHash,"pay_method",(const char*)v_pay_method.arr);
DEBUGLOG(("GetTxnDetail pay_method = [%s]\n",v_pay_method.arr));
                }

/* bank code */
                if (ind_bank_code  >=  0) {
                        v_bank_code.arr[v_bank_code.len] = '\0';
                        PutField_CString(myHash,"bank_code",(const char*)v_bank_code.arr);
DEBUGLOG(("GetTxnDetail bank_code = [%s]\n",v_bank_code.arr));
                }

/* bank_acct_num */
                if (ind_bank_acct_num>=  0) {
                        v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
                        PutField_CString(myHash,"bank_acct_num",(const char*)v_bank_acct_num.arr);
DEBUGLOG(("GetTxnDetail bank_acct_num = [%s]\n",v_bank_acct_num.arr));
                }


/* language */
                if (ind_language  >=  0) {
                        v_language.arr[v_language.len] = '\0';
                        PutField_CString(myHash,"language",(const char*)v_language.arr);
DEBUGLOG(("GetTxnDetail language = [%s]\n",v_language.arr));
                }

/* success url */
                if (ind_success_url  >=  0) {
                        v_success_url.arr[v_success_url.len] = '\0';
                        PutField_CString(myHash,"success_url",(const char*)v_success_url.arr);
DEBUGLOG(("GetTxnDetail success_url = [%s]\n",v_success_url.arr));
                }

/* failure url */
                if (ind_failure_url  >=  0) {
                        v_failure_url.arr[v_failure_url.len] = '\0';
                        PutField_CString(myHash,"failure_url",(const char*)v_failure_url.arr);
DEBUGLOG(("GetTxnDetail failure_url = [%s]\n",v_failure_url.arr));
                }

/* success callback url */
                if (ind_success_ck_url  >=  0) {
                        v_success_ck_url.arr[v_success_ck_url.len] = '\0';
                        PutField_CString(myHash,"success_callback_url",(const char*)v_success_ck_url.arr);
DEBUGLOG(("GetTxnDetail success_callback_url = [%s]\n",v_success_ck_url.arr));
                }

/* failure callback_url */
                if (ind_failure_ck_url  >=  0) {
                        v_failure_ck_url.arr[v_failure_ck_url.len] = '\0';
                        PutField_CString(myHash,"failure_callback_url",(const char*)v_failure_ck_url.arr);
DEBUGLOG(("GetTxnDetail failure_ck_url = [%s]\n",v_failure_ck_url.arr));
                }

/* encrypt_type*/
                if (ind_encrypt_type >=  0) {
                        v_encrypt_type.arr[v_encrypt_type.len] = '\0';
                        PutField_CString(myHash,"encrypt_type",(const char*)v_encrypt_type.arr);
DEBUGLOG(("GetTxnDetail encrypt_type = [%s]\n",v_encrypt_type.arr));
                }

/* bank_name*/
                if (ind_bank_name >= 0) {
                        v_bank_name.arr[v_bank_name.len] = '\0';
                        PutField_CString(myHash,"bank_name",(const char*)v_bank_name.arr);
DEBUGLOG(("GetTxnDetail bank_name = [%s]\n",v_bank_name.arr));
                }

/* branch_name */
                if (ind_branch>=  0) {
                        v_branch.arr[v_branch.len] = '\0';
                        PutField_CString(myHash,"branch",(const char*)v_branch.arr);
DEBUGLOG(("GetTxnDetail branch= [%s]\n",v_branch.arr));
                }

/* account_id*/
                if (ind_account_id>=  0) {
                        v_account_id.arr[v_account_id.len] = '\0';
                        PutField_CString(myHash,"account_id",(const char*)v_account_id.arr);
DEBUGLOG(("GetTxnDetail account_id = [%s]\n",v_account_id.arr));
                }

/* account_name*/
                if (ind_account_name>=  0) {
                        v_account_name.arr[v_account_name.len] = '\0';
                        PutField_CString(myHash,"account_name",(const char*)v_account_name.arr);
DEBUGLOG(("GetTxnDetail account_name = [%s]\n",v_account_name.arr));
                }

/* batch_id*/
                if (ind_batch_id>=  0) {
                        v_batch_id.arr[v_batch_id.len] = '\0';
                        PutField_CString(myHash,"batch_id",(const char*)v_batch_id.arr);
DEBUGLOG(("GetTxnDetail batch_id = [%s]\n",v_batch_id.arr));
                }

/* identity_id*/
                if (ind_identity_id>=  0) {
                        v_identity_id.arr[v_identity_id.len] = '\0';
                        PutField_CString(myHash,"identity_id",(const char*)v_identity_id.arr);
DEBUGLOG(("GetTxnDetail identity_i d= [%s]\n",v_identity_id.arr));
                }


/* remark*/
                if (ind_remark>=  0) {
                        v_remark.arr[v_remark.len] = '\0';
                        PutField_CString(myHash,"remark",(const char*)v_remark.arr);
DEBUGLOG(("GetTxnDetail remark d= [%s]\n",v_remark.arr));
                }

/* selected pay method */
                if (ind_selected_pay_method  >=  0) {
                        v_selected_pay_method.arr[v_selected_pay_method.len] = '\0';
                        PutField_CString(myHash,"selected_pay_method",(const char*)v_selected_pay_method.arr);
DEBUGLOG(("GetTxnDetail selected_pay_method = [%s]\n",v_selected_pay_method.arr));
                }
/*banner_logo */
                if (ind_banner_logo>=  0) {
                        v_banner_logo.arr[v_banner_logo.len] = '\0';
                        PutField_CString(myHash,"banner_logo",(const char*)v_banner_logo.arr);
DEBUGLOG(("GetTxnDetail banner_logo = [%s]\n",v_banner_logo.arr));
                }

/* echo_msg*/
                if (ind_echo_msg_1>=  0) {
                        v_echo_msg_1.arr[v_echo_msg_1.len] = '\0';
                        PutField_CString(myHash,"echo_msg_1",(const char*)v_echo_msg_1.arr);
DEBUGLOG(("GetTxnDetail echo_msg_1 = [%s]\n",v_echo_msg_1.arr));
                }

/* echo_msg*/
                if (ind_echo_msg_2>=  0) {
                        v_echo_msg_2.arr[v_echo_msg_2.len] = '\0';
                        PutField_CString(myHash,"echo_msg_2",(const char*)v_echo_msg_2.arr);
DEBUGLOG(("GetTxnDetail echo_msg_2 = [%s]\n",v_echo_msg_2.arr));
                }


/* echo_msg*/
                if (ind_echo_msg_3>=  0) {
                        v_echo_msg_3.arr[v_echo_msg_3.len] = '\0';
                        PutField_CString(myHash,"echo_msg_3",(const char*)v_echo_msg_3.arr);
DEBUGLOG(("GetTxnDetail echo_msg_3 = [%s]\n",v_echo_msg_3.arr));
                }

/* opt*/
                if (ind_opt_1>=  0) {
                        v_opt_1.arr[v_opt_1.len] = '\0';
                        PutField_CString(myHash,"opt_1",(const char*)v_opt_1.arr);
DEBUGLOG(("GetTxnDetail opt_1 = [%s]\n",v_opt_1.arr));
                }

/* opt*/
                if (ind_opt_2>=  0) {
                        v_opt_2.arr[v_opt_2.len] = '\0';
                        PutField_CString(myHash,"opt_2",(const char*)v_opt_2.arr);
DEBUGLOG(("GetTxnDetail opt_2 = [%s]\n",v_opt_2.arr));
                }

/* opt*/
                if (ind_opt_3>=  0) {
                        v_opt_3.arr[v_opt_3.len] = '\0';
                        PutField_CString(myHash,"opt_3",(const char*)v_opt_3.arr);
DEBUGLOG(("GetTxnDetail opt_3 = [%s]\n",v_opt_3.arr));
                }

/* cust_deposit_datetime */
		if (ind_cust_deposit_datetime >= 0) {
			v_cust_deposit_datetime.arr[v_cust_deposit_datetime.len] = '\0';
			PutField_CString(myHash, "cust_deposit_datetime", (const char*)v_cust_deposit_datetime.arr);
DEBUGLOG(("GetTxnDetail cust_deposit_datetime = [%s]\n", v_cust_deposit_datetime.arr));
		}

/* bank_deposit_datetime */
		if (ind_bank_deposit_datetime >= 0) {
			v_bank_deposit_datetime.arr[v_bank_deposit_datetime.len] = '\0';
			PutField_CString(myHash, "bank_deposit_datetime", (const char*)v_bank_deposit_datetime.arr);
DEBUGLOG(("GetTxnDetail bank_deposit_datetime = [%s]\n", v_bank_deposit_datetime.arr));
		}

/* deposit_bank */
		if (ind_deposit_bank >= 0) {
			v_deposit_bank.arr[v_deposit_bank.len] = '\0';
			PutField_CString(myHash, "deposit_bank", (const char*)v_deposit_bank.arr);
DEBUGLOG(("GetTxnDetail deposit_bank = [%s]\n", v_deposit_bank.arr));
		}

/* deposit_bank_code */
		if (ind_deposit_bank_code >= 0) {
			v_deposit_bank_code.arr[v_deposit_bank_code.len] = '\0';
			PutField_CString(myHash, "deposit_bank_code", (const char*)v_deposit_bank_code.arr);
DEBUGLOG(("GetTxnDetail deposit_bank_code = [%s]\n", v_deposit_bank_code.arr));
		}

/* deposit_ref */
		if (ind_deposit_ref >= 0) {
			v_deposit_ref.arr[v_deposit_ref.len] = '\0';
			PutField_CString(myHash, "deposit_ref", (const char*)v_deposit_ref.arr);
DEBUGLOG(("GetTxnDetail deposit_ref = [%s]\n", v_deposit_ref.arr));
		}

/* province */
                if (ind_province >= 0) {
                        v_province.arr[v_province.len] = '\0';
                        PutField_CString(myHash,"province",(const char*)v_province.arr);
DEBUGLOG(("GetTxnDetail province = [%s]\n",v_province.arr));
                }

/* phone_no */
                if (ind_phone_no >= 0) {
                        v_phone_no.arr[v_phone_no.len] = '\0';
                        PutField_CString(myHash,"phone_no",(const char*)v_phone_no.arr);
DEBUGLOG(("GetTxnDetail phone_no = [%s]\n",v_phone_no.arr));
                }

/* city */
                if (ind_city >= 0) {
                        v_city.arr[v_city.len] = '\0';
                        PutField_CString(myHash,"city",(const char*)v_city.arr);
DEBUGLOG(("GetTxnDetail city = [%s]\n",v_city.arr));
                }

                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getoltxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )988;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getoltxndetail_error;
}




DEBUGLOG(("GetTxnDetail Normal Exit\n"));
        return  PD_OK;

getoltxndetail_error:
DEBUGLOG(("getoltxndetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getoltxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1003;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int MatchRespTxn(const char* csTxnSeq,
                     const char cStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                //short           hv_return_value;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_status;

                /* varchar         v_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;


                short           ind_date = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
    
        hv_status = cStatus;
DEBUGLOG(("MatchRespTxn status = [%c]\n",hv_status));

        /* EXEC SQL SELECT oth_host_posting_date
                INTO    :v_date:ind_date
                FROM    ol_txn_header
                WHERE   oth_txn_id = :hv_txn_id
                and     oth_status = :hv_status
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_host_posting_date INTO :b0:b1 FROM ol_txn\
_header WHERE oth_txn_id = :b2 and oth_status = :b3 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1018;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_date;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto MatchRespTxn_error;
}




        if(ind_date>=0){
DEBUGLOG(("MatchRespTxn Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxn Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchRespTxn_error:
DEBUGLOG(("MatchRespTxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}



int MatchRespTxnReadOnly(const char* csTxnSeq,
                     const char cStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnReadOnly_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                //short           hv_return_value;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_status;

                /* varchar         v_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;


                short           ind_date = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxnReadOnly txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = cStatus;
DEBUGLOG(("MatchRespTxnReadOnly status = [%c]\n",hv_status));

        /* EXEC SQL SELECT oth_host_posting_date
                INTO    :v_date:ind_date
                FROM    ol_txn_header
                WHERE   oth_txn_id = :hv_txn_id
                and     oth_status = :hv_status; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_host_posting_date INTO :b0:b1 FROM ol_txn\
_header WHERE oth_txn_id = :b2 and oth_status = :b3 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1045;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_date;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
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
        if (sqlca.sqlcode < 0) goto MatchRespTxnReadOnly_error;
}




        if(ind_date>=0){
DEBUGLOG(("MatchRespTxnReadOnly Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxnReadOnly Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchRespTxnReadOnly_error:
DEBUGLOG(("MatchRespTxnReadOnly_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int CheckUniqueAmt(hash_t* hRls,
		   recordset_t* myRec)
{
	char*	csTmp;
	double	dTmp;
	int	iTmp;
	int	iCnt = 0;
	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO CheckUniqueAmt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                /* varchar		hv_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_bank_code;

                /* varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_acct_num;

                double		hv_from_amt;
                double		hv_to_amt;
                int		hv_check_interval;

                double		v_have_amt;

                short           ind_have_amt = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"merchant_id",&csTmp)){
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
DEBUGLOG(("CheckUniqueAmt merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    	}
	
	if(GetField_CString(hRls,"txn_code",&csTmp)){
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
DEBUGLOG(("CheckUniqueAmt txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
    	}
	
	if(GetField_CString(hRls,"bank_code",&csTmp)){
		hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
DEBUGLOG(("CheckUniqueAmt bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
    	}
	
	if(GetField_CString(hRls,"bank_acct_num",&csTmp)){
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr,csTmp,hv_bank_acct_num.len);
DEBUGLOG(("CheckUniqueAmt bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
    	}
	
	if(GetField_Double(hRls,"from_amt",&dTmp)){
		hv_from_amt = dTmp;
DEBUGLOG(("CheckUniqueAmt from amount = [%lf]\n",hv_from_amt));
	}

	if(GetField_Double(hRls,"to_amt",&dTmp)){
		hv_to_amt = dTmp;
DEBUGLOG(("CheckUniqueAmt to amount = [%lf]\n",hv_to_amt));
	}

	if(GetField_Int(hRls,"check_interval",&iTmp)){
		hv_check_interval = iTmp;
DEBUGLOG(("CheckUniqueAmt check_interval = [%d]\n",iTmp));
	}

        /* EXEC SQL DECLARE c_cursor_checkunique CURSOR FOR
		select	oth_display_amount
                FROM	
			(select oth_display_amount,
				oth_txn_id
			from	ol_txn_header
			where	oth_display_amount between :hv_from_amt and :hv_to_amt
			and	oth_txn_code = :hv_txn_code
			and	oth_merchant_id = :hv_merchant_id
			and	oth_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate)//,
		/o	
			(select otd_txn_id
			from	ol_txn_detail
			where	otd_bank_code = :hv_bank_code
			and	otd_bank_acct_num = :hv_bank_acct_num
			and     otd_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate)
		WHERE	oth_txn_id = otd_txn_id
		o/
		group by oth_display_amount
		order by oth_display_amount; */ 


	
        /* EXEC SQL OPEN c_cursor_checkunique; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0013;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1072;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_amt;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[3] = (unsigned long )17;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_check_interval;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto CheckUniqueAmt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_checkunique
                INTO
                        :v_have_amt:ind_have_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 41;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1107;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_have_amt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_have_amt;
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
                if (sqlca.sqlcode < 0) goto CheckUniqueAmt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_have_amt < 0)
                        v_have_amt = 0.0;
                PutField_Double(myHash,"have_amt",v_have_amt);

		iCnt++;

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	PutField_Int(hRls,"count",iCnt);

	/* EXEC SQL CLOSE c_cursor_checkunique; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1126;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto CheckUniqueAmt_error;
}



DEBUGLOG(("CheckUniqueAmt Normal Exit [%d]\n",iCnt));
        return  PD_OK;

CheckUniqueAmt_error:
DEBUGLOG(("CheckUniqueAmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_checkunique; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1141;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int CheckPspUniqueAmt(hash_t* hRls,
		   recordset_t* myRec)
{
	char*	csTmp;
	double	dTmp;
	int	iTmp;
	int	iCnt = 0;
	hash_t	*myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO CheckPspUniqueAmt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                //varchar		hv_bank_code[PD_AC_BANK_LEN];
                //varchar		hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN];
                double		hv_from_amt;
                double		hv_to_amt;
                int		hv_check_interval;

                double		v_have_amt;

                short           ind_have_amt = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"baid",&csTmp)){
		hv_baid.len = strlen(csTmp);
		memcpy(hv_baid.arr,csTmp,hv_baid.len);
DEBUGLOG(("CheckPspUniqueAmt baid = [%.*s]\n",hv_baid.len,hv_baid.arr));
    	}
	
	if(GetField_CString(hRls,"txn_code",&csTmp)){
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
DEBUGLOG(("CheckPspUniqueAmt txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
    	}
/*	
	if(GetField_CString(hRls,"bank_code",&csTmp)){
		hv_bank_code.len = strlen(csTmp);
		memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
DEBUGLOG(("CheckPspUniqueAmt bank_code = [%.*s]\n",hv_bank_code.len,hv_bank_code.arr));
    	}
	
	if(GetField_CString(hRls,"bank_acct_num",&csTmp)){
		hv_bank_acct_num.len = strlen(csTmp);
		memcpy(hv_bank_acct_num.arr,csTmp,hv_bank_acct_num.len);
DEBUGLOG(("CheckPspUniqueAmt bank_acct_num = [%.*s]\n",hv_bank_acct_num.len,hv_bank_acct_num.arr));
    	}
*/	
	if(GetField_Double(hRls,"from_amt",&dTmp)){
		hv_from_amt = dTmp;
DEBUGLOG(("CheckPspUniqueAmt from amount = [%lf]\n",hv_from_amt));
	}

	if(GetField_Double(hRls,"to_amt",&dTmp)){
		hv_to_amt = dTmp;
DEBUGLOG(("CheckPspUniqueAmt to amount = [%lf]\n",hv_to_amt));
	}

	if(GetField_Int(hRls,"check_interval",&iTmp)){
		hv_check_interval = iTmp;
DEBUGLOG(("CheckPspUniqueAmt check_interval = [%d]\n",iTmp));
	}

        /* EXEC SQL DECLARE c_cursor_checkpspunique CURSOR FOR
		select	oth_display_amount
                FROM	
			(select oth_display_amount,
				oth_txn_id
			from	ol_txn_header,
				ol_txn_psp_detail
			where	oth_display_amount between :hv_from_amt and :hv_to_amt
			and	oth_txn_code = :hv_txn_code
			and	otp_baid = :hv_baid
			and	oth_txn_id = otp_txn_id
			and	oth_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate)//,
			
			/o(select otd_txn_id
			from	ol_txn_detail
			where	otd_bank_code = :hv_bank_code
			and	otd_bank_acct_num = :hv_bank_acct_num
			and     otd_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate)
		WHERE	oth_txn_id = otd_txn_ido/
		group by oth_display_amount
		order by oth_display_amount; */ 


	
        /* EXEC SQL OPEN c_cursor_checkpspunique; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0014;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1156;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)0;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_amt;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[2] = (unsigned long )5;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[3] = (unsigned long )22;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_check_interval;
        sqlstm.sqhstl[4] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto CheckPspUniqueAmt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_checkpspunique
                INTO
                        :v_have_amt:ind_have_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 41;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1191;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_have_amt;
                sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_have_amt;
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
                if (sqlca.sqlcode < 0) goto CheckPspUniqueAmt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_have_amt < 0)
                        v_have_amt = 0.0;
                PutField_Double(myHash,"have_amt",v_have_amt);

		iCnt++;

		RecordSet_Add(myRec,myHash);

	}while(PD_TRUE);

	PutField_Int(hRls,"count",iCnt);

	/* EXEC SQL CLOSE c_cursor_checkpspunique; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1210;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto CheckPspUniqueAmt_error;
}



DEBUGLOG(("CheckPspUniqueAmt Normal Exit\n"));
        return  PD_OK;

CheckPspUniqueAmt_error:
DEBUGLOG(("CheckPspUniqueAmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_checkpspunique; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1225;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}


int FindOldestUniqueAmt(hash_t* hRls)
{
	char*	csTmp;
	double	dTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO FindOldestUniqueAmt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                double		hv_from_amt;
                double		hv_to_amt;
                int		hv_check_interval;

                double		v_oldest_amt;

                short           ind_oldest_amt = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"merchant_id",&csTmp)){
		hv_merchant_id.len = strlen(csTmp);
		memcpy(hv_merchant_id.arr,csTmp,hv_merchant_id.len);
DEBUGLOG(("FindOldestUniqueAmt merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    	}
	
	if(GetField_CString(hRls,"txn_code",&csTmp)){
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
DEBUGLOG(("FindOldestUniqueAmt txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
    	}
	
	if(GetField_Double(hRls,"from_amt",&dTmp)){
		hv_from_amt = dTmp;
DEBUGLOG(("FindOldestUniqueAmt from amount = [%lf]\n",hv_from_amt));
	}

	if(GetField_Double(hRls,"to_amt",&dTmp)){
		hv_to_amt = dTmp;
DEBUGLOG(("FindOldestUniqueAmt to amount = [%lf]\n",hv_to_amt));
	}

	if(GetField_Int(hRls,"check_interval",&iTmp)){
		hv_check_interval = iTmp;
DEBUGLOG(("FindOldestUniqueAmt check_interval = [%d]\n",iTmp));
	}

        /* EXEC SQL select oth_display_amount
		 into	:v_oldest_amt:ind_oldest_amt
		 from
			(select	oth_display_amount, oth_create_timestamp, count(oth_txn_id) OVER (PARTITION BY oth_display_amount) cnt
                	FROM	ol_txn_header
			where	oth_display_amount between :hv_from_amt and :hv_to_amt
			and	oth_txn_code = :hv_txn_code
			and	oth_merchant_id = :hv_merchant_id
			and	oth_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate
			order by oth_create_timestamp)
		where	cnt = 1
		and	rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_display_amount into :b0:b1 from ( select \
oth_display_amount , oth_create_timestamp , count ( oth_txn_id ) OVER ( PARTI\
TION BY oth_display_amount ) cnt FROM ol_txn_header where oth_display_amount \
between :b2 and :b3 and oth_txn_code = :b4 and oth_merchant_id = :b5 and oth_\
create_timestamp between sysdate - ( :b6 / 24 ) and sysdate order by oth_crea\
te_timestamp ) where cnt = 1 and rownum = 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1240;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_oldest_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_oldest_amt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_amt;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_amt;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[4] = (unsigned long )17;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_check_interval;
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
        if (sqlca.sqlcode < 0) goto FindOldestUniqueAmt_error;
}



	
                if (ind_oldest_amt < 0)
                        v_oldest_amt = 0.0;
                PutField_Double(hRls,"oldest_amt",v_oldest_amt);

DEBUGLOG(("FindOldestUniqueAmt Normal Exit\n"));
        return  PD_OK;

FindOldestUniqueAmt_error:
DEBUGLOG(("FindOldestUniqueAmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int FindOldestPspUniqueAmt(hash_t* hRls)
{
	char*	csTmp;
	double	dTmp;
	int	iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO FindOldestPspUniqueAmt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar		hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

                /* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

                double		hv_from_amt;
                double		hv_to_amt;
                int		hv_check_interval;

                double		v_oldest_amt;

                short           ind_oldest_amt = -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hRls,"baid",&csTmp)){
		hv_baid.len = strlen(csTmp);
		memcpy(hv_baid.arr,csTmp,hv_baid.len);
DEBUGLOG(("FindOldestPspUniqueAmt baid = [%.*s]\n",hv_baid.len,hv_baid.arr));
    	}
	
	if(GetField_CString(hRls,"txn_code",&csTmp)){
		hv_txn_code.len = strlen(csTmp);
		memcpy(hv_txn_code.arr,csTmp,hv_txn_code.len);
DEBUGLOG(("FindOldestPspUniqueAmt txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));
    	}
	
	if(GetField_Double(hRls,"from_amt",&dTmp)){
		hv_from_amt = dTmp;
DEBUGLOG(("FindOldestPspUniqueAmt from amount = [%lf]\n",hv_from_amt));
	}

	if(GetField_Double(hRls,"to_amt",&dTmp)){
		hv_to_amt = dTmp;
DEBUGLOG(("FindOldestPspUniqueAmt to amount = [%lf]\n",hv_to_amt));
	}

	if(GetField_Int(hRls,"check_interval",&iTmp)){
		hv_check_interval = iTmp;
DEBUGLOG(("FindOldestPspUniqueAmt check_interval = [%d]\n",iTmp));
	}

        /* EXEC SQL select oth_display_amount
		 into	:v_oldest_amt:ind_oldest_amt
		 from
			(select	oth_display_amount, oth_create_timestamp, count(oth_txn_id) OVER (PARTITION BY oth_display_amount) cnt
                	FROM	ol_txn_header,ol_txn_psp_detail
			where	oth_display_amount between :hv_from_amt and :hv_to_amt
			and	oth_txn_id = otp_txn_id
			and	oth_txn_code = :hv_txn_code
			and	otp_baid = :hv_baid
			and	oth_create_timestamp between sysdate - (:hv_check_interval/24) and sysdate
			order by oth_create_timestamp)
		where	cnt = 1
		and	rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_display_amount into :b0:b1 from ( select \
oth_display_amount , oth_create_timestamp , count ( oth_txn_id ) OVER ( PARTI\
TION BY oth_display_amount ) cnt FROM ol_txn_header , ol_txn_psp_detail where\
 oth_display_amount between :b2 and :b3 and oth_txn_id = otp_txn_id and oth_t\
xn_code = :b4 and otp_baid = :b5 and oth_create_timestamp between sysdate - (\
 :b6 / 24 ) and sysdate order by oth_create_timestamp ) where cnt = 1 and row\
num = 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1279;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_oldest_amt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_oldest_amt;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_from_amt;
        sqlstm.sqhstl[1] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_to_amt;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_baid;
        sqlstm.sqhstl[4] = (unsigned long )22;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_check_interval;
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
        if (sqlca.sqlcode < 0) goto FindOldestPspUniqueAmt_error;
}



	
                if (ind_oldest_amt < 0)
                        v_oldest_amt = 0.0;
                PutField_Double(hRls,"oldest_amt",v_oldest_amt);

DEBUGLOG(("FindOldestPspUniqueAmt Normal Exit\n"));
        return  PD_OK;

FindOldestPspUniqueAmt_error:
DEBUGLOG(("FindOldestPspUniqueAmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int MatchStmt(const hash_t* hMatchValue, const hash_t* hMatchBfAf, recordset_t* rMatchResult)
{
	int iRet = PD_OK;

	hash_t *myHash;

	char *csTmp;
	char csTmp2[PD_DATETIME_LEN];
	int iTmp, iFieldCnt;
	char *csBuf = strdup("");
	int iCnt = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO matchstmt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_cust_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cust_deposit_datetime;

		/* varchar v_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_ref;


		short ind_txn_id = -1;
		short ind_cust_deposit_datetime = -1;
		short ind_deposit_ref = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("MatchStmt: Begin\n"));
	strcpy((char*)hv_dynstmt.arr, "select oth_txn_id, otd_cust_deposit_datetime, otd_deposit_ref from ol_txn_header, ol_txn_detail where oth_txn_id = otd_txn_id and oth_input_channel = 'OLN' and oth_status = 'W' and oth_txn_code = 'ODI'");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* merchant_id (compulsory) */
	if (GetField_CString(hMatchValue, "merchant_id", &csTmp)) {
		strcat((char*)hv_dynstmt.arr, " and oth_merchant_id = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* service_code (compulsory) */
	if (GetField_CString(hMatchValue, "service_code", &csTmp)) {
		strcat((char*)hv_dynstmt.arr, " and oth_service_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_ccy (compulsory) */
	if (GetField_CString(hMatchValue, "txn_ccy", &csTmp)) {
		strcat((char*)hv_dynstmt.arr, " and otd_txn_ccy = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_country (compulsory) */
	if (GetField_CString(hMatchValue, "txn_country", &csTmp)) {
		strcat((char*)hv_dynstmt.arr, " and otd_txn_country = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
			
/* customer_text */
	if (GetField_CString(hMatchValue, "customer_text", &csTmp)) {
		iCnt++;
		strcat((char*)hv_dynstmt.arr, " and otd_deposit_ref = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank_code */
	if (GetField_CString(hMatchValue, "bank_code", &csTmp)) {
		iCnt++;
		strcat((char*)hv_dynstmt.arr, " and otd_bank_code = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank_acct_num */
	if (GetField_CString(hMatchValue, "bank_acct_num", &csTmp)) {
		iCnt++;
		strcat((char*)hv_dynstmt.arr, " and otd_bank_acct_num = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_timestamp */
	if (GetField_CString(hMatchValue, "txn_timestamp", &csTmp)) {
		iCnt++;

		strncpy(csTmp2, csTmp, 12);
		csTmp2[12] = '\0';

		// onus
		strcat((char*)hv_dynstmt.arr, " and (((otd_deposit_bank_code = otd_bank_code) and (to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp2);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24mi') >= to_date(otd_cust_deposit_datetime, 'yyyymmddhh24mi') - ");
		GetField_Int(hMatchBfAf, "onus_bf_mins", &iTmp);
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, " / 60 / 24) and (to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp2);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24mi') <= to_date(otd_cust_deposit_datetime, 'yyyymmddhh24mi') + ");
		GetField_Int(hMatchBfAf, "onus_af_mins", &iTmp);
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, " / 60 / 24))");

		// offus
		strcat((char*)hv_dynstmt.arr, " or ((otd_deposit_bank_code <> otd_bank_code) and (to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp2);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24mi') >= to_date(otd_cust_deposit_datetime, 'yyyymmddhh24mi') - ");
		GetField_Int(hMatchBfAf, "offus_bf_mins", &iTmp);
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, " / 60 / 24) and (to_date('");
		strcat((char*)hv_dynstmt.arr, csTmp2);
		strcat((char*)hv_dynstmt.arr, "', 'yyyymmddhh24mi') <= to_date(otd_cust_deposit_datetime, 'yyyymmddhh24mi') + ");
		GetField_Int(hMatchBfAf, "offus_af_mins", &iTmp);
		sprintf(csBuf, "%d", iTmp);
		strcat((char*)hv_dynstmt.arr, csBuf);
		strcat((char*)hv_dynstmt.arr, " / 60 / 24)))");
	}

/* txn_amount */
	if (GetField_CString(hMatchValue, "txn_amount", &csTmp)) {
		iCnt++;
		strcat((char*)hv_dynstmt.arr, " and oth_deposit_amount = to_number('");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "')");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

DEBUGLOG(("MatchStmt: [%.*s]\n", hv_dynstmt.len, hv_dynstmt.arr));

	GetField_Int(hMatchValue, "field_cnt", &iFieldCnt);
	if (iCnt == iFieldCnt) {
DEBUGLOG(("MatchStmt enough match field\n"));
		/* EXEC SQL PREPARE s1 FROM :hv_dynstmt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1318;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
  sqlstm.sqhstl[0] = (unsigned long )16394;
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
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


		/* EXEC SQL DECLARE c_cursor CURSOR FOR s1; */ 


		/* EXEC SQL OPEN c_cursor; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1337;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


		for (;;) {
			/* EXEC SQL FETCH c_cursor
			INTO	:v_txn_id:ind_txn_id,
				:v_cust_deposit_datetime:ind_cust_deposit_datetime,
				:v_deposit_ref:ind_deposit_ref; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 41;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )1352;
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
   sqlstm.sqhstv[1] = (unsigned char  *)&v_cust_deposit_datetime;
   sqlstm.sqhstl[1] = (unsigned long )17;
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_cust_deposit_datetime;
   sqlstm.sqinds[1] = (         int  )0;
   sqlstm.sqharm[1] = (unsigned long )0;
   sqlstm.sqadto[1] = (unsigned short )0;
   sqlstm.sqtdso[1] = (unsigned short )0;
   sqlstm.sqhstv[2] = (unsigned char  *)&v_deposit_ref;
   sqlstm.sqhstl[2] = (unsigned long )153;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_deposit_ref;
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
   if (sqlca.sqlcode < 0) goto matchstmt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			myHash = (hash_t*) malloc (sizeof(hash_t));
			hash_init(myHash, 0);

			// txn_id
			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
				PutField_CString(myHash, "txn_id", (const char*)v_txn_id.arr);
DEBUGLOG(("MatchStmt: txn_id = [%s]\n", (const char*)v_txn_id.arr));
			}

			// cust_deposit_datetime
			if (ind_cust_deposit_datetime >= 0) {
				v_cust_deposit_datetime.arr[v_cust_deposit_datetime.len] = '\0';
				PutField_CString(myHash, "cust_deposit_datetime", (const char*)v_cust_deposit_datetime.arr);
DEBUGLOG(("MatchStmt: cust_deposit_datetime = [%s]\n", (const char*)v_cust_deposit_datetime.arr));
			}

			// deposit_ref
			if (ind_deposit_ref >= 0) {
				v_deposit_ref.arr[v_deposit_ref.len] = '\0';
				PutField_CString(myHash, "deposit_ref", (const char*)v_deposit_ref.arr);
DEBUGLOG(("MatchStmt: deposit_ref = [%s]\n", (const char*)v_deposit_ref.arr));
			}

			RecordSet_Add(rMatchResult, myHash);
		}
		/* EXEC SQL CLOSE c_cursor; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 41;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1379;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto matchstmt_error;
}


	} else {
DEBUGLOG(("MatchStmt not enough match field\n"));
	}

DEBUGLOG(("MatchStmt Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

matchstmt_error:
DEBUGLOG(("matchstmt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTransaction matchstmt_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1394;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int     ChkTxnCodeExist(const char *csTxnCode)
{
        int     iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chktxncodeexist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


                int             v_no_of_record;
                short           ind_no_of_record = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("ChkTxnCodeExist = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM ol_txn_header
                  WHERE oth_txn_code = :hv_txn_code
                    and rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_txn_header WH\
ERE oth_txn_code = :b2 and rownum = 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1409;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
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
        if (sqlca.sqlcode < 0) goto chktxncodeexist_error;
}



        if (ind_no_of_record >= 0) {
                if (v_no_of_record > 0) {
DEBUGLOG(("ChkTxnCodeExist FOUND\n"));
                        iRet = PD_FOUND;
                }
        }

        if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkTxnCodeExist NOT FOUND\n"));
        }


        return iRet;

chktxncodeexist_error:
DEBUGLOG(("ChkTxnCodeExist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetTxnIdForUpdate(const char* csTxnId) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdate txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL select oth_txn_id
		into :v_txn_id:ind_txn_id
		from ol_txn_header
		where oth_txn_id = :hv_txn_id
		for update; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oth_txn_id into :b0:b1 from ol_txn_header where oth_\
txn_id = :b2 for update ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1432;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 if (sqlca.sqlcode < 0) goto gettxnidforupdate_error;
}



	if (ind_txn_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

gettxnidforupdate_error:
DEBUGLOG(("gettxnidforupdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int GetTxnIdForUpdateNoWait(const char* csTxnId) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdatenowait_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdateNoWait txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	/* EXEC SQL select oth_txn_id
		into :v_txn_id:ind_txn_id
		from ol_txn_header
		where oth_txn_id = :hv_txn_id
		for update nowait; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oth_txn_id into :b0:b1 from ol_txn_header where oth_\
txn_id = :b2 for update nowait ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1455;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 if (sqlca.sqlcode < 0) goto gettxnidforupdatenowait_error;
}



	if (ind_txn_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

gettxnidforupdatenowait_error:
DEBUGLOG(("gettxnidforupdatenowait_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

/* hContext: int_bank_code, bank_acct_num, stmt_date_range */
/*
int GetUnallocatedRecords(const hash_t* hContext, recordset_t* rRecordSet)
{
	int iRet = PD_OK;

	char *csTmp;
	int iTmp;

	hash_t *myHash;

	EXEC SQL WHENEVER SQLERROR GOTO getunallocatedrecords_error;
	EXEC SQL WHENEVER NOTFOUND CONTINUE;

	EXEC SQL BEGIN DECLARE SECTION;
		varchar hv_input_channel[PD_CHANNEL_CODE_LEN];
		varchar hv_txn_code[PD_TXN_CODE_LEN];
		char	hv_status;
		char	hv_ar_ind;
		varchar hv_sub_status[PD_SUB_STATUS_LEN];

		varchar hv_int_bank_code[PD_BANK_CODE_LEN];
		varchar hv_bank_acct_num[PD_BANK_ACCT_NUM_LEN];
		int	hv_stmt_date_range;
		varchar v_stmt_txn_id[PD_STMT_REF_LEN + 1];

		short ind_int_bank_code = -1;
		short ind_bank_acct_num = -1;
		short ind_stmt_date_range = -1;
		short ind_stmt_txn_id = -1;
	EXEC SQL END DECLARE SECTION;

	hv_input_channel.len = strlen(PD_CHANNEL_OMT);
	memcpy(hv_input_channel.arr, PD_CHANNEL_OMT, hv_input_channel.len);

	hv_txn_code.len = strlen(PD_BANK_DEPOSIT_TXN_CODE);
	memcpy(hv_txn_code.arr, PD_BANK_DEPOSIT_TXN_CODE, hv_txn_code.len);

	hv_status = PD_COMPLETE;

	hv_ar_ind = PD_ACCEPT;

	hv_sub_status.len = strlen(PD_UNALLOCATED);
	memcpy(hv_sub_status.arr, PD_UNALLOCATED, hv_sub_status.len);

	if (GetField_CString(hContext, "int_bank_code", &csTmp)) {
		hv_int_bank_code.len = strlen(csTmp);
		strncpy((char*)hv_int_bank_code.arr, csTmp, hv_int_bank_code.len);
		ind_int_bank_code = 0;
// DEBUGLOG(("GetUnallocatedRecords int_bank_code = [%.*s]\n", hv_int_bank_code.len, hv_int_bank_code.arr));
	}

	if (GetField_CString(hContext, "bank_acct_num", &csTmp)) {
		hv_bank_acct_num.len = strlen(csTmp);
		strncpy((char*)hv_bank_acct_num.arr, csTmp, hv_bank_acct_num.len);
		ind_bank_acct_num = 0;
// DEBUGLOG(("GetUnallocatedRecords bank_acct_num = [%.*s]\n", hv_bank_acct_num.len, hv_bank_acct_num.arr));
	}

	if (GetField_Int(hContext, "stmt_date_range", &iTmp)) {
		hv_stmt_date_range = iTmp;
		ind_stmt_date_range = 0;
// DEBUGLOG(("GetUnallocatedRecords stmt_date_range = [%d]\n", hv_stmt_date_range));
	}

	EXEC SQL DECLARE c_cursor_getunallocatedrecords CURSOR FOR
		SELECT oth_txn_id
		FROM ol_txn_header, ol_txn_psp_detail
		WHERE oth_txn_id = otp_txn_id
		AND otp_bank_code = :hv_int_bank_code:ind_int_bank_code
		AND otp_bank_acct_num = :hv_bank_acct_num:ind_bank_acct_num
		AND oth_input_channel = :hv_input_channel
		AND oth_txn_code = :hv_txn_code
		AND oth_status = :hv_status
		AND oth_ar_ind = :hv_ar_ind
		AND oth_sub_status = :hv_sub_status
		AND oth_multi_match_ind = 0
		AND otp_txn_timestamp >= sysdate - :hv_stmt_date_range:ind_stmt_date_range
		AND otp_txn_hold_ind = 0
		AND otp_sys_match_ind = 1;

	EXEC SQL OPEN c_cursor_getunallocatedrecords;

	for (;;) {
		EXEC SQL FETCH c_cursor_getunallocatedrecords
		INTO	:v_stmt_txn_id:ind_stmt_txn_id;

		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

		myHash = (hash_t*) malloc (sizeof(hash_t));
		hash_init(myHash, 0);

		// stmt_txn_id
		if (ind_stmt_txn_id >= 0) {
			v_stmt_txn_id.arr[v_stmt_txn_id.len] = '\0';
			PutField_CString(myHash, "stmt_txn_id", (const char*)v_stmt_txn_id.arr);
// DEBUGLOG(("GetUnallocatedRecords stmt_txn_id = [%s]\n", (const char*)v_stmt_txn_id.arr));
		}

		RecordSet_Add(rRecordSet, myHash);
	}

	EXEC SQL CLOSE c_cursor_getunallocatedrecords;

// DEBUGLOG(("GetUnallocatedRecords Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

getunallocatedrecords_error:
DEBUGLOG(("getunallocatedrecords_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLStatement getunallocatedrecords_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
	EXEC SQL CLOSE c_cursor_getunallocatedrecords;
	EXEC SQL WHENEVER SQLERROR CONTINUE;
	return PD_ERR;
}
*/

int CheckBasicMatchingCriteria(const char* csPspTxnId, const char* csMerchTxnId, const int iOverrideAmt, const char cMatchingType)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkbasic_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_input_channel[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_input_channel;

		/* varchar hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char	hv_status;
		char	hv_ar_ind;
		/* varchar hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;


		/* varchar hv_psp_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_psp_txn_id;

		/* varchar hv_merch_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_merch_txn_id;

		int hv_override_amt;
		char hv_matching_type;
		/* varchar hv_action[PD_ACCT_ACTION_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_action;


		int v_no_of_record;
		short ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_input_channel.len = strlen(PD_CHANNEL_OMT);
	memcpy(hv_input_channel.arr, PD_CHANNEL_OMT, hv_input_channel.len);

	hv_txn_code.len = strlen(PD_BANK_DEPOSIT_TXN_CODE);
	memcpy(hv_txn_code.arr, PD_BANK_DEPOSIT_TXN_CODE, hv_txn_code.len);

	hv_status = PD_COMPLETE;

	hv_ar_ind = PD_ACCEPT;

	hv_sub_status.len = strlen(PD_UNALLOCATED);
	memcpy(hv_sub_status.arr, PD_UNALLOCATED, hv_sub_status.len);

	hv_psp_txn_id.len = strlen(csPspTxnId);
	strncpy((char*)hv_psp_txn_id.arr, csPspTxnId, hv_psp_txn_id.len);
DEBUGLOG(("CheckBasicMatchingCriteria psp_txn_id = [%.*s]\n", hv_psp_txn_id.len, hv_psp_txn_id.arr));

	hv_merch_txn_id.len = strlen(csMerchTxnId);
	strncpy((char*)hv_merch_txn_id.arr, csMerchTxnId, hv_merch_txn_id.len);
DEBUGLOG(("CheckBasicMatchingCriteria merch_txn_id = [%.*s]\n", hv_merch_txn_id.len, hv_merch_txn_id.arr));

	hv_override_amt = iOverrideAmt;
DEBUGLOG(("CheckBasicMatchingCriteria override_amt = [%d]\n", hv_override_amt));

	hv_matching_type = cMatchingType;
DEBUGLOG(("CheckBasicMatchingCriteria matching_type = [%c]\n", hv_matching_type));

	switch (cMatchingType)
	{
		case 'S':
			hv_action.len = strlen(PD_AC_ACTION_AUTO_MATCH);
			memcpy(hv_action.arr, PD_AC_ACTION_AUTO_MATCH, hv_action.len);
			break;
		case 'A':
			hv_action.len = strlen(PD_AC_ACTION_ADM_MAN_MATCH);
			memcpy(hv_action.arr, PD_AC_ACTION_ADM_MAN_MATCH, hv_action.len);
			break;
		case 'M':
			hv_action.len = strlen(PD_AC_ACTION_MERCH_MAN_MATCH);
			memcpy(hv_action.arr, PD_AC_ACTION_MERCH_MAN_MATCH, hv_action.len);
			break;
		case 'R':
			hv_action.len = strlen(PD_AC_ACTION_MERCH_MAN_MATCH);
			memcpy(hv_action.arr, PD_AC_ACTION_MERCH_MAN_MATCH, hv_action.len);
			break;
		default:
			hv_action.len = strlen("UNKNOWN");
			memcpy(hv_action.arr, "UNKNOWN", hv_action.len);
			break;
	}

	/* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM ol_txn_header psp_hdr, ol_txn_psp_detail psp_dtl,
			ol_txn_header merch_hdr, ol_txn_detail merch_dtl
		WHERE psp_hdr.oth_txn_id = :hv_psp_txn_id
		AND psp_hdr.oth_input_channel = :hv_input_channel
		AND psp_hdr.oth_txn_code = :hv_txn_code
		AND psp_hdr.oth_status = :hv_status
		AND psp_hdr.oth_ar_ind = :hv_ar_ind
		AND psp_hdr.oth_sub_status = :hv_sub_status
		AND psp_dtl.otp_txn_id = psp_hdr.oth_txn_id
		AND psp_dtl.otp_txn_hold_ind = 0
		AND merch_hdr.oth_txn_id = :hv_merch_txn_id
		AND merch_hdr.oth_input_channel = decode(:hv_matching_type, 'R', 'OMT', 'E', 'OMT', 'OLN')
		AND merch_hdr.oth_txn_code = decode(:hv_matching_type, 'R', 'MRN', 'E', 'OAE', 'ODI')
		AND merch_hdr.oth_status = 'W'
		AND merch_dtl.otd_txn_id = merch_hdr.oth_txn_id
		AND psp_hdr.oth_deposit_amount = decode(:hv_override_amt, 1, psp_hdr.oth_deposit_amount, merch_hdr.oth_deposit_amount)
		AND psp_dtl.otp_txn_ccy = merch_dtl.otd_txn_ccy
		AND psp_dtl.otp_bank_code = merch_dtl.otd_bank_code
		AND psp_dtl.otp_bank_acct_num = merch_dtl.otd_bank_acct_num
--		AND abs(psp_dtl.otp_txn_timestamp - to_date(merch_dtl.otd_cust_deposit_datetime, 'yyyymmddhh24miss'))
--			<= (SELECT to_number(sp_val) FROM system_parameter WHERE sp_code = 'OFL_MANUAL_MATCH_DATE_RANGE')
		AND sp_ol_get_allow_action(psp_dtl.otp_bank_code, psp_dtl.otp_bank_acct_num, :hv_action) = decode(:hv_matching_type, 'E', 0, 1)
		; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select count ( 1 ) INTO :b0:b1 FROM ol_txn_header psp_hdr , ol_txn_psp_d\
etail psp_dtl , ol_txn_header merch_hdr , ol_txn_detail merch_dtl WHERE psp_\
hdr . oth_txn_id = :b2 AND psp_hdr . oth_input_channel = :b3 AND psp_hdr . o\
th_txn_code = :b4 AND psp_hdr . oth_status = :b5 AND psp_hdr . oth_ar_ind = \
:b6 AND psp_hdr . oth_sub_status = :b7 AND psp_dtl . otp_txn_id = psp_hdr . \
oth_txn_id AND psp_dtl . otp_txn_hold_ind = 0 AND merch_hdr . oth_txn_id = :\
b8 AND merch_hdr . oth_input_channel = decode ( :b9 , 'R' , 'OMT' , 'E' , 'O\
MT' , 'OLN' ) AND merch_hdr . oth_txn_code = decode ( :b9 , 'R' , 'MRN' , 'E\
' , 'OAE' , 'ODI' ) AND merch_hdr . oth_status = 'W' AND merch_dtl . otd_txn\
_id = merch_hdr . oth_txn_id AND psp_hdr . oth_deposit_amount = decode ( :b1\
1 , 1 , psp_hdr . oth_deposit_amount , merch_hdr . oth_deposit_amount ) AND \
psp_dtl . otp_txn_ccy = merch_dtl . otd_txn_ccy AND psp_dtl . otp_bank_code \
= merch_dtl . otd_bank_code AND psp_dtl . otp_bank_acct_num = merch_dtl . ot\
d_bank_acct_num AND sp_ol_get_allow_acti");
 sqlstm.stmt = "on ( psp_dtl . otp_bank_code , psp_dtl . otp_bank_acct_num \
, :b12 ) = decode ( :b9 , 'E' , 0 , 1 ) ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1478;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_input_channel;
 sqlstm.sqhstl[2] = (unsigned long )5;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[3] = (unsigned long )5;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)0;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[6] = (unsigned long )5;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)0;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_merch_txn_id;
 sqlstm.sqhstl[7] = (unsigned long )18;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)0;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_matching_type;
 sqlstm.sqhstl[8] = (unsigned long )1;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)0;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_matching_type;
 sqlstm.sqhstl[9] = (unsigned long )1;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)0;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_override_amt;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)0;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[11] = (unsigned long )22;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)0;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_matching_type;
 sqlstm.sqhstl[12] = (unsigned long )1;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)0;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
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
 if (sqlca.sqlcode < 0) goto checkbasic_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
			iRet = PD_OK;
		}
	}

	return iRet;

checkbasic_error:
DEBUGLOG(("checkbasic_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int MatchRespTxnStatus(const char* csTxnSeq,
                     const char cStatus,
                        const char cArInd)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnStatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_status;
                char            hv_ar_ind;

                /* varchar         v_host_posting_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;


                short           ind_host_posting_date= -1;
    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxnStatus txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = cStatus;
DEBUGLOG(("MatchRespTxnStatus status = [%c]\n",hv_status));

        hv_ar_ind = cArInd;
DEBUGLOG(("MatchRespTxnStatus ar_ind = [%c]\n",hv_ar_ind));

        /* EXEC SQL SELECT oth_host_posting_date
                INTO    :v_host_posting_date:ind_host_posting_date
                FROM    ol_txn_header
                WHERE   oth_txn_id = :hv_txn_id
                and     oth_status = :hv_status
                and     oth_ar_ind = :hv_ar_ind
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_host_posting_date INTO :b0:b1 FROM ol_txn\
_header WHERE oth_txn_id = :b2 and oth_status = :b3 and oth_ar_ind = :b4 for \
update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1545;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_host_posting_date;
        sqlstm.sqhstl[0] = (unsigned long )11;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_host_posting_date;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[2] = (unsigned long )1;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_ar_ind;
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
        if (sqlca.sqlcode < 0) goto MatchRespTxnStatus_error;
}




        if(ind_host_posting_date>=0){
DEBUGLOG(("MatchRespTxn Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxnStatus Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchRespTxnStatus_error:
DEBUGLOG(("MatchRespTxnStatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int CheckUnreconSms(const char* csPspTxnId, int* iIsReconSms)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkunreconsms_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_psp_txn_id;


		int v_no_of_record;
		short ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_psp_txn_id.len = strlen(csPspTxnId);
	strncpy((char*)hv_psp_txn_id.arr, csPspTxnId, hv_psp_txn_id.len);
DEBUGLOG(("CheckUnreconSms psp_txn_id = [%.*s]\n", hv_psp_txn_id.len, hv_psp_txn_id.arr));

	/* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM ol_txn_header, ol_stmt_txn_relation, ol_baid_txn, ol_statement_detail
		WHERE oth_txn_id = :hv_psp_txn_id
		AND oth_txn_id = ostp_txn_id
		AND ostp_stmt_txn_id = obt_txn_id
		AND obt_stat_txn_id = olsd_stat_txn_id
		AND olsd_statement_ref IS NOT NULL; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_txn_header , ol_stmt\
_txn_relation , ol_baid_txn , ol_statement_detail WHERE oth_txn_id = :b2 AND \
oth_txn_id = ostp_txn_id AND ostp_stmt_txn_id = obt_txn_id AND obt_stat_txn_i\
d = olsd_stat_txn_id AND olsd_statement_ref IS NOT NULL ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1576;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_psp_txn_id;
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
 if (sqlca.sqlcode < 0) goto checkunreconsms_error;
}



	if (ind_no_of_record >= 0) {
		iRet = PD_OK;
		*iIsReconSms = v_no_of_record;
DEBUGLOG(("CheckUnreconSms iIsReconSms = [%d]\n", *iIsReconSms));
	}

	return iRet;

checkunreconsms_error:
DEBUGLOG(("checkunreconsms_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int UpdateReleaseReserveDate(const char* csTxnId,
				const char* csReleaseDate,
				const char* csAddUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO updatereleasereservedate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_release_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_release_date;

		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


		short		ind_txn_id = -1;
		short		ind_release_date = -1;
		short		ind_add_user = -1;
		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateReleaseReserveDate: Begin\n"));

	hv_txn_id.len = strlen(csTxnId);
	strncpy((char *)hv_txn_id.arr, csTxnId, hv_txn_id.len);
	ind_txn_id = 0;
DEBUGLOG(("UpdateReleaseReserveDate:txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_release_date.len = strlen(csReleaseDate);
	strncpy((char *)hv_release_date.arr, csReleaseDate, hv_release_date.len);
	ind_release_date = 0;
DEBUGLOG(("UpdateReleaseReserveDate:release_date = [%.*s]\n", hv_release_date.len, hv_release_date.arr));

	hv_add_user.len = strlen(csAddUser);
	strncpy((char *)hv_add_user.arr, csAddUser, hv_add_user.len);
	ind_add_user = 0;
DEBUGLOG(("UpdateReleaseReserveDate:add_user = [%.*s]\n", hv_add_user.len, hv_add_user.arr));

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_upd_release_res(
						:hv_txn_id:ind_txn_id,
						:hv_release_date:ind_release_date,
						:hv_add_user:ind_add_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_upd_release_res ( :hv_t\
xn_id:ind_txn_id , :hv_release_date:ind_release_date , :hv_add_user:ind_add_u\
ser ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1599;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_release_date;
 sqlstm.sqhstl[2] = (unsigned long )10;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_release_date;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_add_user;
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
 if (sqlca.sqlcode < 0) goto updatereleasereservedate_error;
}



DEBUGLOG(("UpdateReleaseReserveDate:Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateReleaseReserveDate:Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLTransaction::UpdateReleaseReserveDate: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateReleaseReserveDate: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLTransaction::UpdateReleaseReserveDate: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateReleaseReserveDate: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
        }

updatereleasereservedate_error:
DEBUGLOG(("updatereleasereservedate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int     ChkTxnExistsByOrgTxnSeq(const char *csTxnSeq, const char *csTxnCode, const char cStatus)
{
	int     iRet = PD_NOT_FOUND;

	/* EXEC SQL WHENEVER SQLERROR GOTO chkexistsorg_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		char            hv_status;

		int             v_no_of_record;
		short           ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnSeq);
	memcpy(hv_txn_id.arr, csTxnSeq, hv_txn_id.len);
DEBUGLOG(("ChkTxnExistsByOrgTxnSeq txn_seq= [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("ChkTxnExistsByOrgTxnSeq txn_code= [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

	hv_status = cStatus;
DEBUGLOG(("ChkTxnExistsByOrgTxnSeq status = [%c]\n", hv_status));

	/* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM ol_txn_header
		WHERE oth_org_txn_id = :hv_txn_id
		AND oth_txn_code = :hv_txn_code
		AND oth_status = :hv_status
		and rownum = 1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_txn_header WHERE oth\
_org_txn_id = :b2 AND oth_txn_code = :b3 AND oth_status = :b4 and rownum = 1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1630;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_txn_id;
 sqlstm.sqhstl[1] = (unsigned long )18;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_code;
 sqlstm.sqhstl[2] = (unsigned long )5;
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
 if (sqlca.sqlcode < 0) goto chkexistsorg_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("ChkTxnExistsByOrgTxnSeq FOUND\n"));
			iRet = PD_FOUND;
		}
	}

	if (iRet!= PD_FOUND) {
DEBUGLOG(("ChkTxnExistsByOrgTxnSeq NOT FOUND\n"));
	}

	return iRet;

chkexistsorg_error:
DEBUGLOG(("chkexistsorg_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int ChkNonReconTxnEsist(const hash_t* hRls) {
	int iRet = PD_NOT_FOUND;

	char *csTmp;

	/* EXEC SQL WHENEVER SQLERROR GOTO chknonrecontxnesist_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	hv_baid[PD_BAID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_baid;

		short	ind_baid = -1;
		char	hv_status = PD_COMPLETE;
		char	hv_ar_ind = PD_ACCEPT;
		char	hv_unrecon = PD_UNRECONCILED;
		char	hv_partial_recon = PD_PARTIAL_RECON;

		int	v_no_of_record;
		short	ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	if (GetField_CString(hRls, "baid", &csTmp)) {
		hv_baid.len = strlen(csTmp);
		strncpy((char*)hv_baid.arr, csTmp, hv_baid.len);
		ind_baid = 0;
DEBUGLOG(("ChkNonReconTxnEsist:: baid = [%.*s]\n", hv_baid.len, hv_baid.arr));
	}

	/* EXEC SQL
		SELECT	count(1)
		INTO	:v_no_of_record:ind_no_of_record
		FROM	OL_TXN_HEADER,
			TXN_CODE
		WHERE	OTH_TXN_CODE = TC_CODE
		AND	OTH_TXN_ID IN (SELECT OTP_TXN_ID FROM OL_TXN_PSP_DETAIL WHERE OTP_BAID = :hv_baid:ind_baid)
		AND	OTH_STATUS = :hv_status
		AND	OTH_AR_IND = :hv_ar_ind
		AND	OTH_RECON_STATUS IN (:hv_unrecon, :hv_partial_recon)
		AND	TC_OFL_IS_OFFSET = 0; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM OL_TXN_HEADER , TXN_COD\
E WHERE OTH_TXN_CODE = TC_CODE AND OTH_TXN_ID IN ( SELECT OTP_TXN_ID FROM OL_\
TXN_PSP_DETAIL WHERE OTP_BAID = :b2:b3 ) AND OTH_STATUS = :b4 AND OTH_AR_IND \
= :b5 AND OTH_RECON_STATUS IN ( :b6 , :b7 ) AND TC_OFL_IS_OFFSET = 0 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1661;
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
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_baid;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_baid;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[3] = (unsigned long )1;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)0;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_unrecon;
 sqlstm.sqhstl[4] = (unsigned long )1;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)0;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_partial_recon;
 sqlstm.sqhstl[5] = (unsigned long )1;
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
 if (sqlca.sqlcode < 0) goto chknonrecontxnesist_error;
}



	if (ind_no_of_record >= 0) {
		if (v_no_of_record > 0) {
DEBUGLOG(("ChkNonReconTxnExist:: FOUND\n"));
			iRet = PD_FOUND;
		}
	}

DEBUGLOG(("ChkNonReconTxnExist() Normal Exit! iRet = [%d]\n", iRet));
	return iRet;

chknonrecontxnesist_error:
DEBUGLOG(("chknonrecontxnesist_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}

int UpdateDetailRemark(const hash_t *hRls)
{
	char*	csPtr;
	char*	csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_remark_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDetailRemark: Begin\n"));
	strcpy((char*)hv_dynstmt.arr,"update ol_txn_detail set otd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateDetailRemark:txn_id = [%s]\n",csTxnId));

/* remark */
        if (GetField_CString(hRls,"remark",&csPtr)) {
DEBUGLOG(("UpdateDetailRemark:remark = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_remark = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update user */
        if (GetField_CString(hRls,"update_user",&csPtr)) {
DEBUGLOG(("UpdateDetailRemark:update_user = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",otd_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	strcat((char *)hv_dynstmt.arr, " WHERE otd_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1700;
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
 if (sqlca.sqlcode < 0) goto update_detail_remark_error;
}


	/* EXEC SQL EXECUTE PS; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1719;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto update_detail_remark_error;
}





DEBUGLOG(("UpdateDetailRemark Normal Exit\n"));
	return PD_OK;

update_detail_remark_error:
DEBUGLOG(("update_detail_remark_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLTransaction_UpdateDetailRemark: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetailRemark: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int AddMiOLTxnLog(const char* csTxnId)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO add_mioltxnlogerror; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;


                short           ind_txn_id = -1;
                short           ind_create_user = -1;

                short           hv_return_value;
        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddMiOLTxnLog: Begin\n"));

// txn_id
	hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
        ind_txn_id = 0;
DEBUGLOG(("AddMiOLTxnLog txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

// user
	hv_create_user.len = strlen("SYSTEM");
        strncpy((char*)hv_create_user.arr,"SYSTEM", hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("AddMiOLTxnLog user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mi_ol_txn_log_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mi_ol_txn_log_insert ( \
:hv_txn_id:ind_txn_id , :hv_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1734;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_create_user;
        sqlstm.sqhstl[2] = (unsigned long )22;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_create_user;
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
        if (sqlca.sqlcode < 0) goto add_mioltxnlogerror;
}



DEBUGLOG(("AddMiOLTxnLog:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("AddMiOLTxnLog:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("OLTransaction:AddMiOLTxnLog: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddMiOLTxnLog: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("OLTransaction:AddMiOLTxnLog: SP_ERR TxnAbort\n");
DEBUGLOG(("AddMiOLTxnLog: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_mioltxnlogerror:
DEBUGLOG(("add_mioltxnlogerror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("OLTransaction_add_mioltxnlogerror: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int GetTxnIdForUpdateWithStatus(const char* csTxnId) {
        int iRet = PD_OK;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdstt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

                short ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdateWithStatus txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

        /* EXEC SQL select oth_txn_id
                into :v_txn_id:ind_txn_id
                from ol_txn_header
                where oth_txn_id = :hv_txn_id
		and oth_status = 'C'
		and oth_ar_ind = 'A'
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select oth_txn_id into :b0:b1 from ol_txn_header whe\
re oth_txn_id = :b2 and oth_status = 'C' and oth_ar_ind = 'A' for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1761;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
        sqlstm.sqhstl[0] = (unsigned long )19;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
        if (sqlca.sqlcode < 0) goto gettxnidforupdstt_error;
}



        if (ind_txn_id >= 0) {
                iRet = PD_OK;
        } else {
                iRet = PD_ERR;
        }

        return iRet;

gettxnidforupdstt_error:
DEBUGLOG(("gettxnidforupdstt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int GetTxnIdForUpdateNoWaitWithStatus(const char* csTxnId,
		const char cStatus,
		const char cArInd) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdatenowaitwithstatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		char hv_ar_ind;
		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithStatus txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithStatus status = [%c]\n", hv_status));

	hv_ar_ind = cArInd;
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithStatus ar_ind = [%c]\n", hv_ar_ind));

	/* EXEC SQL select oth_txn_id
		into :v_txn_id:ind_txn_id
		from ol_txn_header
		where oth_txn_id = :hv_txn_id
		and oth_status = :hv_status
		and oth_ar_ind = :hv_ar_ind
		for update nowait; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oth_txn_id into :b0:b1 from ol_txn_header where oth_\
txn_id = :b2 and oth_status = :b3 and oth_ar_ind = :b4 for update nowait ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1784;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_ar_ind;
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
 if (sqlca.sqlcode < 0) goto gettxnidforupdatenowaitwithstatus_error;
}



	if (ind_txn_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

gettxnidforupdatenowaitwithstatus_error:
DEBUGLOG(("gettxnidforupdatenowaitwithstatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}


int UpdateTxnDetailRemark(hash_t* hRls)
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


DEBUGLOG(("UpdateTxnDetailRemark: Begin\n"));

//txn_id
	if (GetField_CString(hRls,"txn_seq",&csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char*)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("UpdateTxnDetailRemark txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
	}

//remark
	if (GetField_CString(hRls,"remark",&csTmp)) {
		hv_remark.len = strlen(csTmp);
		strncpy((char*)hv_remark.arr, csTmp, hv_remark.len);
		ind_remark = 0;
DEBUGLOG(("UpdateTxnDetailRemark remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
	}

//update_user
	if (GetField_CString(hRls,"update_user",&csTmp)) {
		hv_update_user.len = strlen(csTmp);
		strncpy((char*)hv_update_user.arr, csTmp, hv_update_user.len);
		ind_update_user = 0;
DEBUGLOG(("UpdateTxnDetailRemark update_user = [%.*s]\n",hv_update_user.len,hv_update_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_txn_detail_upd_remark(
								:hv_txn_id:ind_txn_id,
								:hv_remark:ind_remark,
								:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_txn_detail_upd_remark ( :hv\
_txn_id:ind_txn_id , :hv_remark:ind_remark , :hv_update_user:ind_update_user \
) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1815;
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



DEBUGLOG(("UpdateTxnDetailRemark Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("UpdateTxnDetailRemark Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("UpdateTxnDetailRemark: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateTxnDetailRemark: SP_OTHER_ERR TxnAbort\n"));	
                return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("UpdateTxnDetailRemark: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateTxnDetailRemark: SP_ERR TxnAbort\n"));
		return PD_ERR;
	}

updateremark_err:
DEBUGLOG(("updateremark_err code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("UpdateTxnDetailRemark: SP_ERR TxnAbort\n");
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    return PD_ERR;
}

int MatchPayoutMerchantRef(const char* csMerchantId,
                     const char* csMerchantRef)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO matchpayoutmerchantref_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;
                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;


    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("MatchPayoutMerchantRef merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    
        hv_merchant_ref.len = strlen(csMerchantRef);
        memcpy(hv_merchant_ref.arr,csMerchantRef,hv_merchant_ref.len);
DEBUGLOG(("MatchPayoutMerchantRef merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_transaction_po_matchmref(:hv_merchant_id,
                                                                     :hv_merchant_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_transaction_po_match\
mref ( :hv_merchant_id , :hv_merchant_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1846;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[1] = (unsigned long )17;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[2] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto matchpayoutmerchantref_error;
}



        if (hv_return_value > 0)  {

DEBUGLOG(("MatchPayoutMerchantRef Found\n"));
                return FOUND;
        }
        else {
DEBUGLOG(("MatchPayoutMerchantRef Not Found\n"));
                return NOT_FOUND;
        }


matchpayoutmerchantref_error:
DEBUGLOG(("matchpayoutmerchantref_error code %d\n", sqlca.sqlcode));
ERRLOG("OLTransaction::matchpayoutmerchantref_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int ReMatchPayoutMerchantRef(const char* csTxnId,
			const char* csMerchantId,
                     	const char* csMerchantRef)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO rematchpayoutmerchantref_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

                /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;


    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
DEBUGLOG(("ReMatchPayoutMerchantRef txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
    
        hv_merchant_id.len = strlen(csMerchantId);
        memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("ReMatchPayoutMerchantRef merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));
    
        hv_merchant_ref.len = strlen(csMerchantRef);
        memcpy(hv_merchant_ref.arr,csMerchantRef,hv_merchant_ref.len);
DEBUGLOG(("ReMatchPayoutMerchantRef merchant_ref = [%.*s]\n",hv_merchant_ref.len,hv_merchant_ref.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_ol_transaction_po_mthmrefs(:hv_txn_id,
								     :hv_merchant_id,
                                                                     :hv_merchant_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_ol_transaction_po_mthmr\
efs ( :hv_txn_id , :hv_merchant_id , :hv_merchant_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1873;
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
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_merchant_id;
        sqlstm.sqhstl[2] = (unsigned long )17;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_merchant_ref;
        sqlstm.sqhstl[3] = (unsigned long )52;
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
        if (sqlca.sqlcode < 0) goto rematchpayoutmerchantref_error;
}



        if (hv_return_value > 0)  {

DEBUGLOG(("ReMatchPayoutMerchantRef Found\n"));
                return FOUND;
        }
        else {
DEBUGLOG(("ReMatchPayoutMerchantRef Not Found\n"));
                return NOT_FOUND;
        }


rematchpayoutmerchantref_error:
DEBUGLOG(("rematchpayoutmerchantref_error code %d\n", sqlca.sqlcode));
ERRLOG("OLTransaction::rematchpayoutmerchantref_error code %d\n", sqlca.sqlcode);
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetTxnIdForUpdateNoWaitWithSubStatus(const char* csTxnId,
		const char cStatus,
		const char* csSubStatus) {
	int iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO gettxnidforupdatenowaitwithsubstatus_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char hv_status;
		/* varchar hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		short ind_txn_id = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnId);
	memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithSubStatus txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));

	hv_status = cStatus;
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithSubStatus status = [%c]\n", hv_status));

	hv_sub_status.len = strlen(csSubStatus);
	memcpy(hv_sub_status.arr, csSubStatus, hv_sub_status.len);
DEBUGLOG(("GetTxnIdForUpdateNoWaitWithSubStatus sub_status = [%.*s]\n", hv_sub_status.len, hv_sub_status.arr));

	/* EXEC SQL select oth_txn_id
		into :v_txn_id:ind_txn_id
		from ol_txn_header
		where oth_txn_id = :hv_txn_id
		and oth_status = :hv_status
		and oth_sub_status = :hv_sub_status
		for update nowait; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 41;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select oth_txn_id into :b0:b1 from ol_txn_header where oth_\
txn_id = :b2 and oth_status = :b3 and oth_sub_status = :b4 for update nowait ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1904;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_id;
 sqlstm.sqhstl[0] = (unsigned long )19;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_txn_id;
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
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[2] = (unsigned long )1;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_sub_status;
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
 if (sqlca.sqlcode < 0) goto gettxnidforupdatenowaitwithsubstatus_error;
}



	if (ind_txn_id >= 0) {
		iRet = PD_OK;
	} else {
		iRet = PD_ERR;
	}

	return iRet;

gettxnidforupdatenowaitwithsubstatus_error:
DEBUGLOG(("gettxnidforupdatenowaitwithsubstatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return PD_ERR;
}



int     IsPayoutAPITxn(const char *csTxnId)
{
        int     iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO ispayoutapi_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                int             v_is_api;
                short           ind_is_api = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr, csTxnId, hv_txn_id.len);
DEBUGLOG(("IsPayoutAPITxn = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL
                SELECT nvl(oth_upload_channel,0)
                   INTO :v_is_api:ind_is_api
                   FROM ol_txn_header
                  WHERE oth_txn_id = :hv_txn_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 41;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select nvl ( oth_upload_channel , 0 ) INTO :b0:b1 FR\
OM ol_txn_header WHERE oth_txn_id = :b2 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1935;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_is_api;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_is_api;
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
        if (sqlca.sqlcode < 0) goto ispayoutapi_error;
}




	if(ind_is_api<0)
		v_is_api = PD_FALSE;

DEBUGLOG(("IsPayoutAPITxn = [%d]\n",v_is_api));
	iRet = v_is_api;

        return iRet;

ispayoutapi_error:
DEBUGLOG(("IsPayoutAPITxn_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}
