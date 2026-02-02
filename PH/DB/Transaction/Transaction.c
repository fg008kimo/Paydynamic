
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
    "Transaction.pc"
};


static unsigned int sqlctx = 1314715;


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
   unsigned char  *sqhstv[40];
   unsigned long  sqhstl[40];
            int   sqhsts[40];
            short *sqindv[40];
            int   sqinds[40];
   unsigned long  sqharm[40];
   unsigned long  *sqharc[40];
   unsigned short  sqadto[40];
   unsigned short  sqtdso[40];
} sqlstm = {12,40};

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

 static char *sq0004 = 
"select th_org_txn_id , th_client_id , th_status , th_ar_ind , th_txn_code ,\
 th_merchant_id , th_merchant_ref , th_transaction_amount , th_net_amount , t\
h_net_ccy , th_transmission_datetime , th_local_tm_date , th_local_tm_time , \
th_tm_date , th_tm_time , th_internal_code , th_input_channel , th_response_c\
ode , th_host_posting_date , th_process_code , th_process_type , th_input_cha\
nnel , th_service_code , th_client_ip , th_ex_supplier , th_ex_rate , th_rese\
rve_amount , th_sub_status , th_reserved_release_date , th_ack_status , th_ap\
proval_date , th_ip_region from txn_header where th_txn_id = :b0            ";

 static char *sq0005 = 
"select td_txn_ccy , td_txn_country , td_pay_method , td_bank_code , td_show\
_paypage , td_language , td_success_url , td_failure_url , td_success_callbac\
k_url , td_failure_callback_url , td_encrypt_type , td_bank_name , td_branch_\
name , td_account_id , td_account_name , td_batch_id , td_identity_id , td_re\
mark , td_selected_pay_method , td_banner_logo , td_customer_tag , td_echo_ms\
g_1 , td_echo_msg_2 , td_echo_msg_3 , td_opt_1 , td_opt_2 , td_opt_3 , td_sel\
ected_pid , td_customer_tel , td_magic_num , td_magic_word , td_customer_id ,\
 td_customer_group , td_txn_gp_id from txn_detail where td_txn_id = :b0      \
      ";

 static char *sq0012 = 
"select th_txn_id , th_txn_code , th_merchant_id , th_client_id , th_service\
_code , tp_psp_id , td_txn_ccy , th_status , th_ar_ind , th_transaction_amoun\
t from txn_detail , ( txn_header left join txn_psp_detail on th_txn_id = tp_t\
xn_id ) where th_txn_id = td_txn_id and td_remark = :b0 and th_org_txn_id is \
null and th_status = 'C' and th_ar_ind = 'A'            ";

 static char *sq0018 = 
"select th_txn_id from ( select th_txn_id , th_host_posting_date , th_input_\
channel , th_transaction_amount from txn_header where th_merchant_id = :b0 an\
d th_service_code = :b1 and th_txn_code = 'DSI' and th_ar_ind = 'A' ) , ( sel\
ect td_txn_id from txn_detail where td_customer_tag = :b2 and td_customer_gro\
up = :b3 and td_txn_ccy = :b4 and td_txn_country = :b5 ) where th_txn_id = td\
_txn_id            ";

 static char *sq0025 = 
"select th_txn_id from txn_header , txn_detail where th_txn_id = td_txn_id a\
nd th_approval_date is not null and th_approval_date = :b0 and th_txn_code = \
'DSI' and th_status = 'C' and th_ar_ind = 'A' and ( td_open_bal is null or td\
_current_bal is null or td_total_float is null or td_total_reserved_amount is\
 null or td_total_hold is null or td_fundin_payout is null or td_reserved_pay\
out is null or td_total_float_after_payout is null or td_open_bal_settlement \
is null or td_current_bal_settlement is null or td_total_float_settlement is \
null or td_total_hold_settlement is null ) order by th_approval_timestamp , t\
h_txn_id            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,986,0,6,362,0,0,28,28,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,
132,0,0,2,0,0,17,846,0,0,1,1,0,1,0,1,9,0,0,
151,0,0,2,0,0,21,847,0,0,0,0,0,1,0,
166,0,0,3,1322,0,6,1301,0,0,40,40,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
341,0,0,2,0,0,17,1708,0,0,1,1,0,1,0,1,9,0,0,
360,0,0,2,0,0,21,1709,0,0,0,0,0,1,0,
375,0,0,4,613,0,9,1858,0,2049,1,1,0,1,0,1,9,0,0,
394,0,0,4,0,0,13,1860,0,0,32,0,0,1,0,2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,
0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
537,0,0,4,0,0,15,2101,0,0,0,0,0,1,0,
552,0,0,4,0,0,15,2117,0,0,0,0,0,1,0,
567,0,0,5,620,0,9,2251,0,2049,1,1,0,1,0,1,9,0,0,
586,0,0,5,0,0,13,2253,0,0,34,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,
737,0,0,5,0,0,15,2536,0,0,0,0,0,1,0,
752,0,0,5,0,0,15,2546,0,0,0,0,0,1,0,
767,0,0,6,97,0,6,2573,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
794,0,0,7,109,0,4,2622,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
821,0,0,8,129,0,4,2675,0,0,4,3,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,1,1,0,0,
852,0,0,9,163,0,4,2727,0,0,4,2,0,1,0,2,9,0,0,2,9,0,0,1,9,0,0,1,1,0,0,
883,0,0,10,86,0,4,2778,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
906,0,0,11,89,0,6,2830,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
933,0,0,12,362,0,9,2921,0,2049,1,1,0,1,0,1,9,0,0,
952,0,0,12,0,0,13,2923,0,0,10,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,1,0,0,2,1,0,0,2,4,0,0,
1007,0,0,12,0,0,15,3017,0,0,0,0,0,1,0,
1022,0,0,12,0,0,15,3032,0,0,0,0,0,1,0,
1037,0,0,13,198,0,6,3112,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,
1,9,0,0,
1076,0,0,14,178,0,6,3196,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1111,0,0,15,176,0,6,3311,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1146,0,0,16,98,0,4,3378,0,0,3,2,0,1,0,2,9,0,0,1,9,0,0,1,1,0,0,
1173,0,0,17,205,0,4,3429,0,0,4,3,0,1,0,2,3,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
1204,0,0,18,402,0,9,3539,0,2049,6,6,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,9,0,0,
1243,0,0,18,0,0,13,3541,0,0,1,0,0,1,0,2,9,0,0,
1262,0,0,18,0,0,15,3560,0,0,0,0,0,1,0,
1277,0,0,18,0,0,15,3576,0,0,0,0,0,1,0,
1292,0,0,19,0,0,17,3631,0,0,1,1,0,1,0,1,9,0,0,
1311,0,0,19,0,0,45,3634,0,0,0,0,0,1,0,
1326,0,0,19,0,0,13,3636,0,0,3,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,
1353,0,0,19,0,0,15,3673,0,0,0,0,0,1,0,
1368,0,0,19,0,0,15,3689,0,0,0,0,0,1,0,
1383,0,0,2,0,0,17,3735,0,0,1,1,0,1,0,1,9,0,0,
1402,0,0,2,0,0,21,3736,0,0,0,0,0,1,0,
1417,0,0,20,123,0,4,3775,0,0,4,2,0,1,0,2,1,0,0,2,97,0,0,1,9,0,0,1,1,0,0,
1448,0,0,21,114,0,6,3830,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
1475,0,0,22,85,0,4,3882,0,0,2,1,0,1,0,2,9,0,0,1,9,0,0,
1498,0,0,23,142,0,6,3949,0,0,4,4,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1529,0,0,24,117,0,4,4010,0,0,3,2,0,1,0,2,3,0,0,1,9,0,0,1,3,0,0,
1556,0,0,25,634,0,9,4084,0,2049,1,1,0,1,0,1,9,0,0,
1575,0,0,25,0,0,13,4087,0,0,1,0,0,1,0,2,9,0,0,
1594,0,0,25,0,0,15,4113,0,0,0,0,0,1,0,
1609,0,0,25,0,0,15,4128,0,0,0,0,0,1,0,
1624,0,0,26,506,0,4,4151,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
PDProtech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of PDProtech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2010/07/30              [GOD]
Add GetTxnHeader ph_posting-date		   2010/11/16		   [GOD]
Add encrpyt type				   2011/01/25		   [MSN]
Add ChkTxnCodeExist				   2011/12/06		   [SWK]
markup amt/rate/ccy deleted			   2012/02/01		   [MSN]
check duplicate MMS host ref			   2012/02/22		   [MSN]
Add substatus			   	           2012/04/13		   [GOD]
fields changes in merchant balance		   2012/08/09		   [MSN]
Add UpdateReleaseReserve Date			   2012/08/17		   [GOD]
Add ackstatus 			   		   2013/02/19		   [GOD]
Add TxnBrowserInfo				   2013/03/25		   [MSN]
Add magic_num and magic_word			   2013/08/20		   [MSN]
Add GetRecCntByCustID				   2013/09/18		   [SWK]
Add vp group id					   2013/10/16		   [MSN]
Modify GetTxnHeader, add ackstatus		   2014/11/13		   [WWK]
Add GetTxnHeader with Approval Date		   2015/06/10		   [GOD]
Add AddMiTxnLog					   2015/11/04		   [WMC]			
Add GetTxnIdForUpdateNoWait			   2015/12/23		   [MSN]
Add UpdateTxnDetailRemark			   2016/08/02		   [WWK]
Adc IsCreateTimeWithinRange			   2017/07/03		   [MSN]
PRD143 Increase to 50 row limit Delivery out       2018/10/31              [TNY]
Add MerchBalNullInTxnDtByAprvDate		   2020/03/17              [WMC]
Add MerchBalInTxnDetail				   2020/04/08		   [MSN]
PRD021 add field ip_region in 
 - Update
 - GetTxnHeader                                    2021/01/18              [ZBL]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <oraca.h>
#include <sqlca.h>
#include "Transaction.h"
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

/* char    cDebug; */
static char    cDebug;
void Transaction(char    cdebug)
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
	double		hv_net_amt;
	/* varchar		hv_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_net_ccy;

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
	short		ind_net_amt = -1;
	short		ind_net_ccy = -1;
	short		ind_tm_date = -1;
	short		ind_tm_time = -1;
	short		ind_local_tm_date = -1;
	short		ind_local_tm_time = -1;
	short		ind_add_user = -1;
	short		ind_client_ip= -1;
	short		ind_service_code = -1;
	short		ind_approval_date = -1;

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
DEBUGLOG(("Add:settlement_date = [%d]\n",hv_internal_code));
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

/* net amt   */
        if (GetField_Double(hRls,"net_amt",&dTmp)) {
		hv_net_amt = dTmp;
                ind_net_amt = 0;
DEBUGLOG(("Add:net_amt = [%f]\n",hv_net_amt));
        }

/* net ccy */
        if (GetField_CString(hRls,"net_ccy",&csTmp)) {
                hv_net_ccy.len = strlen(csTmp);
                memcpy(hv_net_ccy.arr,csTmp,hv_net_ccy.len);
                ind_net_ccy = 0;
DEBUGLOG(("Add:net_ccy = [%.*s]\n",hv_net_ccy.len,hv_net_ccy.arr));
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

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_txn_header_insert(
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
					:hv_net_amt:ind_net_amt,
					:hv_net_ccy:ind_net_ccy,
					:hv_tm_date:ind_tm_date,
					:hv_tm_time:ind_tm_time,
					:hv_local_tm_date:ind_local_tm_date,
					:hv_local_tm_time:ind_local_tm_time,
					:hv_add_user:ind_add_user,
					:hv_add_user:ind_add_user,
					:hv_client_ip:ind_client_ip,
					:hv_service_code:ind_service_code,
					:hv_approval_date:ind_approval_date);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_header_insert ( :hv_txn_id\
:ind_txn_id , :hv_org_txn_id:ind_org_txn_id , :hv_channel_code:ind_channel_co\
de , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_sub_status:ind_sub_s\
tatus , :hv_txn_code:ind_txn_code , :hv_process_type:ind_process_type , :hv_p\
rocess_code:ind_process_code , :hv_merchant_id:ind_merchant_id , :hv_merchant\
_ref:ind_merchant_ref , :hv_client_id:ind_client_id , :hv_host_posting_date:i\
nd_host_posting_date , :hv_transmission_datetime:ind_transmission_datetime , \
:hv_internal_code:ind_internal_code , :hv_response_code:ind_response_code , :\
hv_transaction_amt:ind_transaction_amt , :hv_net_amt:ind_net_amt , :hv_net_cc\
y:ind_net_ccy , :hv_tm_date:ind_tm_date , :hv_tm_time:ind_tm_time , :hv_local\
_tm_date:ind_local_tm_date , :hv_local_tm_time:ind_local_tm_time , :hv_add_us\
er:ind_add_user , :hv_add_user:ind_add_user , :hv_client_ip:ind_client_ip , :\
hv_service_code:ind_service_code , :hv_approval_date:ind_approval_date ) ; EN\
D ;";
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
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_net_amt;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_net_amt;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_net_ccy;
 sqlstm.sqhstl[19] = (unsigned long )6;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_net_ccy;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_tm_date;
 sqlstm.sqhstl[20] = (unsigned long )10;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_tm_date;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_tm_time;
 sqlstm.sqhstl[21] = (unsigned long )8;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_tm_time;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_local_tm_date;
 sqlstm.sqhstl[22] = (unsigned long )10;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_local_tm_date;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_local_tm_time;
 sqlstm.sqhstl[23] = (unsigned long )8;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_local_tm_time;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[24] = (unsigned long )22;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_add_user;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_client_ip;
 sqlstm.sqhstl[25] = (unsigned long )27;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_client_ip;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_service_code;
 sqlstm.sqhstl[26] = (unsigned long )5;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_service_code;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_approval_date;
 sqlstm.sqhstl[27] = (unsigned long )10;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_approval_date;
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

ERRLOG("Transaction_Add: SP_INTERNAL_ERR TxnAbort\n");
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
	strcpy((char*)hv_dynstmt.arr,"update txn_header set th_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
DEBUGLOG(("Update:org_txn_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_org_txn_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* Channel code */
        if (GetField_CString(hRls,"channel_code",&csTmp)) {
DEBUGLOG(("Update:channel_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_input_channel = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Status */ 
        if (GetField_Char(hRls,"status",&cTmp)) {
DEBUGLOG(("Update:status = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",th_status = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* ar ind */ 
        if (GetField_Char(hRls,"ar_ind",&cTmp)) {
DEBUGLOG(("Update:ar_ind = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",th_ar_ind = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Sub Status */
        if (GetField_CString(hRls,"sub_status",&csTmp)) {
DEBUGLOG(("Update:sub_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_sub_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ACK Status */
        if (GetField_CString(hRls,"ack_status",&csTmp)) {
DEBUGLOG(("Update:ack_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_ack_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
DEBUGLOG(("Update:txn_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_txn_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
DEBUGLOG(("Update:process_type = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_process_type = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
DEBUGLOG(("Update:process_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_process_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Merchant No */
        if (GetField_CString(hRls,"merchant_id",&csTmp)) {
DEBUGLOG(("Update:merchant_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_merchant_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Merchant Ref */
        if (GetField_CString(hRls,"merchant_ref",&csTmp)) {
DEBUGLOG(("Update:merchant_ref = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_merchant_ref = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Client ID */
        if (GetField_CString(hRls,"client_id",&csTmp)) {
DEBUGLOG(("Update:client_id = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_client_id = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
DEBUGLOG(("Update:host_posting_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_host_posting_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* transmission_datetime  */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
DEBUGLOG(("Update:transmission_datetime = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_transmission_datetime = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("Update:internal_code = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",th_internal_code = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("Update:response_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_response_code = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("Update:txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_transaction_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* net amt   */
        if (GetField_Double(hRls,"net_amt",&dTmp)) {
DEBUGLOG(("Update:net_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_net_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* net ccy */
        if (GetField_CString(hRls,"net_ccy",&csTmp)) {
DEBUGLOG(("Update:net_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_net_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* reserve amt   */
        if (GetField_Double(hRls,"reserve_amt",&dTmp)) {
DEBUGLOG(("Update:reserve_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_reserve_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* tm date */
        if (GetField_CString(hRls,"tm_date",&csTmp)) {
DEBUGLOG(("Update:tm_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_tm_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
DEBUGLOG(("Update:tm_time = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_tm_time = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
DEBUGLOG(("Update:local_tm_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_local_tm_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
DEBUGLOG(("Update:local_tm_time = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_local_tm_time = '");
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
		strcat((char*)hv_dynstmt.arr, ",th_client_ip = '");
        	strcat((char*)hv_dynstmt.arr, csTmpIP);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* approval date */
        if (GetField_CString(hRls,"approval_date",&csTmp)) {
DEBUGLOG(("Update:approval_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_approval_date = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* approval timestamp */
        if (GetField_CString(hRls,"approval_timestamp",&csTmp)) {
DEBUGLOG(("Update:approval_timestamp = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_approval_timestamp = to_timestamp('");
        	strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "','YYYYMMDDHH24MISSFF') ");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
DEBUGLOG(("Update:service_code = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_service_code= '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ex_supplier */ 
        if (GetField_Char(hRls,"ex_supplier",&cTmp)) {
DEBUGLOG(("Update:ex_supplier = [%c]\n",cTmp));
		sprintf(csBuf,"%c",cTmp);
		strcat((char*)hv_dynstmt.arr, ",th_ex_supplier = '");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*ex_rate*/
        if (GetField_Double(hRls,"ex_rate",&dTmp)) {
DEBUGLOG(("Update:ex_rate = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_ex_rate = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* markup ccy 
        if (GetField_CString(hRls,"markup_ccy",&csTmp)) {
DEBUGLOG(("Update:markup_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_markup_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/// markup rate
        if (GetField_Double(hRls,"markup_rate",&dTmp)) {
DEBUGLOG(("Update:markup_rate = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_markup_rate = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/// markup amount
        if (GetField_Double(hRls,"markup_amt",&dTmp)) {
DEBUGLOG(("Update:markup_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_markup_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
*/

/* settlement txn amount */
        if (GetField_Double(hRls,"settlement_txn_amt",&dTmp)) {
DEBUGLOG(("Update:settlement_txn_amt = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_settlement_txn_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_create_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* reserved_release_date */
        if (GetField_CString(hRls,"reserved_release_date",&csTmp)) {
DEBUGLOG(("Update:reserved_release_date = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_reserved_release_date= '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* inter ccy */
        if (GetField_CString(hRls,"inter_ccy",&csTmp)) {
DEBUGLOG(("Update:inter_ccy = [%s]\n",csTmp));
		strcat((char*)hv_dynstmt.arr, ",th_inter_ccy = '");
        	strcat((char*)hv_dynstmt.arr, csTmp);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/// inter rate
        if (GetField_Double(hRls,"inter_rate",&dTmp)) {
DEBUGLOG(("Update:inter_rate = [%lf]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",th_inter_rate = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* PRD021 Non-China IP */
/* ip_region */
	if (GetField_CString(hRls, "ip_region", &csTmp)) 
	{
DEBUGLOG(("Update:ip_region = [%s]\n", csTmp));

		strcat((char*)hv_dynstmt.arr, ", th_ip_region = '");
		strcat((char*)hv_dynstmt.arr, csTmp);
		strcat((char*)hv_dynstmt.arr, "'");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* End - PRD021 Non-China IP */

	strcat((char *)hv_dynstmt.arr, " WHERE th_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )132;
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
 sqlstm.arrsiz = 28;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )151;
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

ERRLOG("Transaction_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}

int AddDetail(const hash_t *hRls)
{
        char		*csTmp;
	char		cTmp;
	int		iTmp;

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

	char		hv_show_paypage;
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

	/* varchar		hv_selected_pay_method[PD_SELECTED_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_selected_pay_method;

	/* varchar         hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

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

	/* varchar		hv_customer_name[PD_CUSTOMER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_name;

	/* varchar		hv_customer_family_name[PD_CUSTOMER_FAMILY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_family_name;

	/* varchar		hv_customer_tel[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_customer_tel;

	/* varchar		hv_customer_email[PD_CUSTOMER_EMAIL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_email;

	/* varchar		hv_selected_pid[PD_PID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_selected_pid;

	//varchar		hv_magic_num[PD_MAGIC_NUM_LEN];
	//varchar		hv_magic_word[PD_MAGIC_WORD_LEN];


	short		ind_txn_id = -1;
	short		ind_txn_ccy = -1;
	short		ind_txn_country = -1;
	short		ind_pay_method = -1;
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
	short		ind_show_paypage = -1;
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
	short		ind_selected_pay_method = -1;
	short           ind_customer_tag= -1;
        short           ind_banner_logo= -1;
        short           ind_echo_msg_1= -1;
        short           ind_echo_msg_2= -1;
        short           ind_echo_msg_3= -1;
        short           ind_opt_1= -1;
        short           ind_opt_2= -1;
        short           ind_opt_3= -1;
	short		ind_customer_name = -1;
	short		ind_customer_family_name = -1;
	short		ind_customer_tel = -1;
	short		ind_customer_email = -1;
	short		ind_selected_pid = -1;
	//short		ind_magic_num = -1;
	//short		ind_magic_word = -1;

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


/* show paypage */
        if (GetField_Char(hRls,"show_paypage",&cTmp)) {
		hv_show_paypage = cTmp;
		ind_show_paypage = 0;
DEBUGLOG(("AddDetail:show_paypage = [%c]\n",hv_show_paypage));
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

/* selected_pay_method */
        if (GetField_CString(hRls,"selected_pay_method",&csTmp)) {
                hv_selected_pay_method.len = strlen(csTmp);
                memcpy(hv_selected_pay_method.arr,csTmp,hv_selected_pay_method.len);
                ind_selected_pay_method = 0;
DEBUGLOG(("AddDetail:selected_pay_method = [%.*s]\n",hv_selected_pay_method.len,hv_selected_pay_method.arr));
	}


/* customer tag*/
        if (GetField_CString(hRls,"customer_tag", &csTmp)) {
                hv_customer_tag.len = strlen(csTmp);
                memcpy(hv_customer_tag.arr,csTmp,hv_customer_tag.len);
                ind_customer_tag = 0;
DEBUGLOG(("AddDetail:customer_tag = [%.*s][%d]\n",hv_customer_tag.len,hv_customer_tag.arr,hv_customer_tag.len));
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

/* customer_name */
	if (GetField_CString(hRls, "customer_name", &csTmp)) {
		hv_customer_name.len = strlen(csTmp);
		memcpy(hv_customer_name.arr, csTmp, hv_customer_name.len);
		ind_customer_name = 0;
DEBUGLOG(("AddDetail:customer_name = [%.*s][%d]\n",hv_customer_name.len,hv_customer_name.arr,hv_customer_name.len));
        }

/* customer_family_name */
	if (GetField_CString(hRls, "customer_family_name", &csTmp)) {
		hv_customer_family_name.len = strlen(csTmp);
		memcpy(hv_customer_family_name.arr, csTmp, hv_customer_family_name.len);
		ind_customer_family_name = 0;
DEBUGLOG(("AddDetail:customer_family_name = [%.*s][%d]\n",hv_customer_family_name.len,hv_customer_family_name.arr,hv_customer_family_name.len));
        }

/* customer_tel */
	if (GetField_CString(hRls, "customer_tel", &csTmp)) {
		hv_customer_tel.len = strlen(csTmp);
		memcpy(hv_customer_tel.arr, csTmp, hv_customer_tel.len);
		ind_customer_tel = 0;
DEBUGLOG(("AddDetail:customer_tel = [%.*s][%d]\n",hv_customer_tel.len,hv_customer_tel.arr,hv_customer_tel.len));
        }

/* customer_email */
	if (GetField_CString(hRls, "customer_email", &csTmp)) {
		hv_customer_email.len = strlen(csTmp);
		memcpy(hv_customer_email.arr, csTmp, hv_customer_email.len);
		ind_customer_email = 0;
DEBUGLOG(("AddDetail:customer_email = [%.*s][%d]\n",hv_customer_email.len,hv_customer_email.arr,hv_customer_email.len));
        }

/* selected_pid */
	if (GetField_CString(hRls, "selected_pid", &csTmp)) {
		hv_selected_pid.len = strlen(csTmp);
		memcpy(hv_selected_pid.arr, csTmp, hv_selected_pid.len);
		ind_selected_pid = 0;
DEBUGLOG(("AddDetail:selected_pid = [%.*s][%d]\n",hv_selected_pid.len,hv_selected_pid.arr,hv_selected_pid.len));
        }
/*
// magic_num 
	if (GetField_CString(hRls, "magic_num", &csTmp)) {
		hv_magic_num.len = strlen(csTmp);
		memcpy(hv_magic_num.arr, csTmp, hv_magic_num.len);
		ind_magic_num = 0;
DEBUGLOG(("AddDetail:magic_num = [%.*s][%d]\n",hv_magic_num.len,hv_magic_num.arr,hv_magic_num.len));
	}

// magic_word
	if (GetField_CString(hRls, "magic_word", &csTmp)) {
		hv_magic_word.len = strlen(csTmp);
		memcpy(hv_magic_word.arr, csTmp, hv_magic_word.len);
		ind_magic_word = 0;
DEBUGLOG(("AddDetail:magic_word = [%.*s][%d]\n",hv_magic_word.len,hv_magic_word.arr,hv_magic_word.len));
	}
*/
	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_txn_detail_insert(
					:hv_txn_id:ind_txn_id,
					:hv_txn_ccy:ind_txn_ccy,
					:hv_txn_country:ind_txn_country,
					:hv_pay_method:ind_pay_method,
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
					:hv_show_paypage:ind_show_paypage,
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
					:hv_selected_pay_method:ind_selected_pay_method,
					:hv_banner_logo:ind_banner_logo,
                                        :hv_customer_tag:ind_customer_tag,
                                        :hv_echo_msg_1:ind_echo_msg_1,
                                        :hv_echo_msg_2:ind_echo_msg_2,
                                        :hv_echo_msg_3:ind_echo_msg_3,
                                        :hv_opt_1:ind_opt_1,
                                        :hv_opt_2:ind_opt_2,
                                        :hv_opt_3:ind_opt_3,
					:hv_customer_name:ind_customer_name,
					:hv_customer_family_name:ind_customer_family_name,
					:hv_customer_tel:ind_customer_tel,
					:hv_customer_email:ind_customer_email,
					:hv_selected_pid:ind_selected_pid);
					//:hv_magic_num:ind_magic_num,
					//:hv_magic_word:ind_magic_word);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_txn_detail_insert ( :hv_txn_id:ind_txn_id ,\
 :hv_txn_ccy:ind_txn_ccy , :hv_txn_country:ind_txn_country , :hv_pay_method:\
ind_pay_method , :hv_bank_code:ind_bank_code , :hv_bank_name:ind_bank_name ,\
 :hv_branch_name:ind_branch_name , :hv_account_id:ind_account_id , :hv_accou\
nt_name:ind_account_name , :hv_identity_id:ind_identity_id , :hv_province:in\
d_province , :hv_phone_no:ind_phone_no , :hv_city:ind_city , :hv_batch_id:in\
d_batch_id , :hv_show_paypage:ind_show_paypage , :hv_language:ind_language ,\
 :hv_success_url:ind_success_url , :hv_failure_url:ind_failure_url , :hv_suc\
cess_ck_url:ind_success_ck_url , :hv_failure_ck_url:ind_failure_ck_url , :hv\
_add_user:ind_add_user , :hv_update_user:ind_update_user , :hv_encrypt_type:\
ind_encrypt_type , :hv_version_no:ind_version_no , :hv_remark:ind_remark , :\
hv_selected_pay_method:ind_selected_pay_method , :hv_banner_logo:ind_banner_\
logo , :hv_customer_tag:ind_customer_tag , :hv_echo_msg_1:ind_echo_msg_1 , :\
hv_echo_msg_2:ind_echo_msg_2 , :hv_echo_");
 sqlstm.stmt = "msg_3:ind_echo_msg_3 , :hv_opt_1:ind_opt_1 , :hv_opt_2:ind_\
opt_2 , :hv_opt_3:ind_opt_3 , :hv_customer_name:ind_customer_name , :hv_custo\
mer_family_name:ind_customer_family_name , :hv_customer_tel:ind_customer_tel \
, :hv_customer_email:ind_customer_email , :hv_selected_pid:ind_selected_pid )\
 ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )166;
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
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_bank_code;
 sqlstm.sqhstl[5] = (unsigned long )27;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_bank_code;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_bank_name;
 sqlstm.sqhstl[6] = (unsigned long )152;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_bank_name;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_branch_name;
 sqlstm.sqhstl[7] = (unsigned long )152;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_branch_name;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_account_id;
 sqlstm.sqhstl[8] = (unsigned long )27;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_account_id;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_account_name;
 sqlstm.sqhstl[9] = (unsigned long )102;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_account_name;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_identity_id;
 sqlstm.sqhstl[10] = (unsigned long )27;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_identity_id;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_province;
 sqlstm.sqhstl[11] = (unsigned long )102;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_province;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_phone_no;
 sqlstm.sqhstl[12] = (unsigned long )32;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_phone_no;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_city;
 sqlstm.sqhstl[13] = (unsigned long )102;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_city;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_batch_id;
 sqlstm.sqhstl[14] = (unsigned long )22;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_batch_id;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_show_paypage;
 sqlstm.sqhstl[15] = (unsigned long )1;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_show_paypage;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_language;
 sqlstm.sqhstl[16] = (unsigned long )4;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_language;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_success_url;
 sqlstm.sqhstl[17] = (unsigned long )257;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_success_url;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_failure_url;
 sqlstm.sqhstl[18] = (unsigned long )257;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_failure_url;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_success_ck_url;
 sqlstm.sqhstl[19] = (unsigned long )257;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_success_ck_url;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_failure_ck_url;
 sqlstm.sqhstl[20] = (unsigned long )257;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_failure_ck_url;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[21] = (unsigned long )22;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_add_user;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_update_user;
 sqlstm.sqhstl[22] = (unsigned long )22;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_update_user;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_encrypt_type;
 sqlstm.sqhstl[23] = (unsigned long )6;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_encrypt_type;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_version_no;
 sqlstm.sqhstl[24] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_version_no;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[25] = (unsigned long )257;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_remark;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_selected_pay_method;
 sqlstm.sqhstl[26] = (unsigned long )6;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_selected_pay_method;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_banner_logo;
 sqlstm.sqhstl[27] = (unsigned long )257;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_banner_logo;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_customer_tag;
 sqlstm.sqhstl[28] = (unsigned long )12;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_customer_tag;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_echo_msg_1;
 sqlstm.sqhstl[29] = (unsigned long )257;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_echo_msg_1;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_echo_msg_2;
 sqlstm.sqhstl[30] = (unsigned long )257;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_echo_msg_2;
 sqlstm.sqinds[30] = (         int  )0;
 sqlstm.sqharm[30] = (unsigned long )0;
 sqlstm.sqadto[30] = (unsigned short )0;
 sqlstm.sqtdso[30] = (unsigned short )0;
 sqlstm.sqhstv[31] = (unsigned char  *)&hv_echo_msg_3;
 sqlstm.sqhstl[31] = (unsigned long )257;
 sqlstm.sqhsts[31] = (         int  )0;
 sqlstm.sqindv[31] = (         short *)&ind_echo_msg_3;
 sqlstm.sqinds[31] = (         int  )0;
 sqlstm.sqharm[31] = (unsigned long )0;
 sqlstm.sqadto[31] = (unsigned short )0;
 sqlstm.sqtdso[31] = (unsigned short )0;
 sqlstm.sqhstv[32] = (unsigned char  *)&hv_opt_1;
 sqlstm.sqhstl[32] = (unsigned long )52;
 sqlstm.sqhsts[32] = (         int  )0;
 sqlstm.sqindv[32] = (         short *)&ind_opt_1;
 sqlstm.sqinds[32] = (         int  )0;
 sqlstm.sqharm[32] = (unsigned long )0;
 sqlstm.sqadto[32] = (unsigned short )0;
 sqlstm.sqtdso[32] = (unsigned short )0;
 sqlstm.sqhstv[33] = (unsigned char  *)&hv_opt_2;
 sqlstm.sqhstl[33] = (unsigned long )52;
 sqlstm.sqhsts[33] = (         int  )0;
 sqlstm.sqindv[33] = (         short *)&ind_opt_2;
 sqlstm.sqinds[33] = (         int  )0;
 sqlstm.sqharm[33] = (unsigned long )0;
 sqlstm.sqadto[33] = (unsigned short )0;
 sqlstm.sqtdso[33] = (unsigned short )0;
 sqlstm.sqhstv[34] = (unsigned char  *)&hv_opt_3;
 sqlstm.sqhstl[34] = (unsigned long )52;
 sqlstm.sqhsts[34] = (         int  )0;
 sqlstm.sqindv[34] = (         short *)&ind_opt_3;
 sqlstm.sqinds[34] = (         int  )0;
 sqlstm.sqharm[34] = (unsigned long )0;
 sqlstm.sqadto[34] = (unsigned short )0;
 sqlstm.sqtdso[34] = (unsigned short )0;
 sqlstm.sqhstv[35] = (unsigned char  *)&hv_customer_name;
 sqlstm.sqhstl[35] = (unsigned long )102;
 sqlstm.sqhsts[35] = (         int  )0;
 sqlstm.sqindv[35] = (         short *)&ind_customer_name;
 sqlstm.sqinds[35] = (         int  )0;
 sqlstm.sqharm[35] = (unsigned long )0;
 sqlstm.sqadto[35] = (unsigned short )0;
 sqlstm.sqtdso[35] = (unsigned short )0;
 sqlstm.sqhstv[36] = (unsigned char  *)&hv_customer_family_name;
 sqlstm.sqhstl[36] = (unsigned long )102;
 sqlstm.sqhsts[36] = (         int  )0;
 sqlstm.sqindv[36] = (         short *)&ind_customer_family_name;
 sqlstm.sqinds[36] = (         int  )0;
 sqlstm.sqharm[36] = (unsigned long )0;
 sqlstm.sqadto[36] = (unsigned short )0;
 sqlstm.sqtdso[36] = (unsigned short )0;
 sqlstm.sqhstv[37] = (unsigned char  *)&hv_customer_tel;
 sqlstm.sqhstl[37] = (unsigned long )22;
 sqlstm.sqhsts[37] = (         int  )0;
 sqlstm.sqindv[37] = (         short *)&ind_customer_tel;
 sqlstm.sqinds[37] = (         int  )0;
 sqlstm.sqharm[37] = (unsigned long )0;
 sqlstm.sqadto[37] = (unsigned short )0;
 sqlstm.sqtdso[37] = (unsigned short )0;
 sqlstm.sqhstv[38] = (unsigned char  *)&hv_customer_email;
 sqlstm.sqhstl[38] = (unsigned long )102;
 sqlstm.sqhsts[38] = (         int  )0;
 sqlstm.sqindv[38] = (         short *)&ind_customer_email;
 sqlstm.sqinds[38] = (         int  )0;
 sqlstm.sqharm[38] = (unsigned long )0;
 sqlstm.sqadto[38] = (unsigned short )0;
 sqlstm.sqtdso[38] = (unsigned short )0;
 sqlstm.sqhstv[39] = (unsigned char  *)&hv_selected_pid;
 sqlstm.sqhstl[39] = (unsigned long )52;
 sqlstm.sqhsts[39] = (         int  )0;
 sqlstm.sqindv[39] = (         short *)&ind_selected_pid;
 sqlstm.sqinds[39] = (         int  )0;
 sqlstm.sqharm[39] = (unsigned long )0;
 sqlstm.sqadto[39] = (unsigned short )0;
 sqlstm.sqtdso[39] = (unsigned short )0;
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

ERRLOG("Transaction_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}

int UpdateDetail(const hash_t *hRls)
{
	double	dTmp;
	int	iTmp;
	char*	csPtr;
	char*	csBuf;
	char*	csTxnId;
	char* csQTmp[1024];

        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


	/* varchar 	hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDetail: Begin\n"));
	csBuf = (char*) malloc (128);
	strcpy((char*)hv_dynstmt.arr,"update txn_detail set td_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateDetail:txn_id = [%s]\n",csTxnId));

/* current_bal*/
        if (GetField_Double(hRls,"current_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:current_bal= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_current_bal = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* current_bal_settlement */
        if (GetField_Double(hRls,"current_bal_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:current_bal_settlement= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_current_bal_settlement = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* open_bal*/
        if (GetField_Double(hRls,"open_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_bal= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_open_bal = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* open_bal_settlement*/
        if (GetField_Double(hRls,"open_bal_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_bal_settlement= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_open_bal_settlement = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_float*/
        if (GetField_Double(hRls,"total_float",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_float= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_float = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_float_settlement*/
        if (GetField_Double(hRls,"total_float_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_float_settlement= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_float_settlement = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_float_after_payout*/
        if (GetField_Double(hRls,"total_float_after_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_float_after_payout= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_float_after_payout = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}


/* total_reserved_amount*/
        if (GetField_Double(hRls,"total_reserved_amount",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_reserved_amount= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_reserved_amount = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_hold*/
        if (GetField_Double(hRls,"total_hold",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_hold= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_hold = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* total_hold_settlement*/
        if (GetField_Double(hRls,"total_hold_settlement",&dTmp)) {
DEBUGLOG(("UpdateDetail:total_hold_settlement= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_total_hold_settlement = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*fundin_payout*/
        if (GetField_Double(hRls,"fundin_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:fundin_payout= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_fundin_payout = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/*reserved_payout*/
        if (GetField_Double(hRls,"reserved_payout",&dTmp)) {
DEBUGLOG(("UpdateDetail:reserved_payout= [%f]\n",dTmp));
		sprintf(csBuf,"%f",dTmp);
		strcat((char*)hv_dynstmt.arr, ",td_reserved_payout = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* txn_country */
        if (GetField_CString(hRls,"txn_country",&csPtr)) {
DEBUGLOG(("UpdateDetail:txn_country = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_txn_country = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank code */
        if (GetField_CString(hRls,"bank_code",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_code = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_bank_code = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* bank name*/
        if (GetField_CString(hRls,"bank_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:bank_name = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_bank_name = ");

		sprintf((char *)csQTmp, (char*)PD_Q_QUOTE_VALUE, csPtr);
DEBUGLOG(("Update: bank_name (q_quote) = [%s]\n", csQTmp));
                csQTmp[strlen(csPtr) + PD_Q_ADD_QUOTE_LEN] = '\0';

                strcat((char*)hv_dynstmt.arr, (char*) csQTmp);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* branch name*/
        if (GetField_CString(hRls,"branch",&csPtr)) {
DEBUGLOG(("UpdateDetail:branch = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_branch_name = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* account name*/
        if (GetField_CString(hRls,"account_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:account_name = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_account_name = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* account id*/
        if (GetField_CString(hRls,"account_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:account_id = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_account_id = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* pay_method */
        if (GetField_CString(hRls,"pay_method",&csPtr)) {
DEBUGLOG(("UpdateDetail:pay_method = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_pay_method = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* selected_pay_method */
        if (GetField_CString(hRls,"selected_pay_method",&csPtr)) {
DEBUGLOG(("UpdateDetail:selected_pay_method = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_selected_pay_method = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* update user */
        if (GetField_CString(hRls,"update_user",&csPtr)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_update_user = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* customer_name */
        if (GetField_CString(hRls,"customer_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_name = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",td_customer_name = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* customer_family_name */
        if (GetField_CString(hRls,"customer_family_name",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_family_name = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_customer_family_name = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* customer_tel */
        if (GetField_CString(hRls,"customer_tel",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_tel = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_customer_tel = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* customer_email*/
        if (GetField_CString(hRls,"customer_email",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_email = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_customer_email = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* batch_id */
        if (GetField_CString(hRls,"td_batch_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:td_batch_id = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_batch_id = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* magic num */
        if (GetField_CString(hRls,"magic_num",&csPtr)) {
DEBUGLOG(("UpdateDetail:magic_num = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_magic_num = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* magic word */
        if (GetField_CString(hRls,"magic_word",&csPtr)) {
DEBUGLOG(("UpdateDetail:magic_word = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_magic_word = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* customer id */
        if (GetField_CString(hRls,"customer_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_id = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_customer_id = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* customer group */
        if (GetField_CString(hRls,"customer_group",&csPtr)) {
DEBUGLOG(("UpdateDetail:customer_group = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_customer_group = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}
/* vp group id*/
        if (GetField_Int(hRls,"txn_gp_id",&iTmp)) {
DEBUGLOG(("UpdateDetail:txn_gp_id = [%d]\n",iTmp));
		sprintf(csBuf,"%d",iTmp);
		strcat((char*)hv_dynstmt.arr, ",td_txn_gp_id = ");
        	strcat((char*)hv_dynstmt.arr, csBuf);
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* remark */
        if (GetField_CString(hRls,"remark",&csPtr)) {
DEBUGLOG(("UpdateDetail:remark = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_remark = '");
		/* PRD143 handle delimitor */
        	/* strcat((char*)hv_dynstmt.arr, csPtr); */
        	strcat((char*)hv_dynstmt.arr, ESC_string(csPtr));
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* fe_domain */
        if (GetField_CString(hRls,"fe_domain",&csPtr)) {
DEBUGLOG(("UpdateDetail:fe_domain = [%s]\n",csPtr));
		strcat((char*)hv_dynstmt.arr, ",td_fe_domain = '");
        	strcat((char*)hv_dynstmt.arr, csPtr);
        	strcat((char*)hv_dynstmt.arr, "'");
        	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	strcat((char *)hv_dynstmt.arr, " WHERE td_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
       	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )341;
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
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )360;
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

ERRLOG("Transaction_UpdateDetail: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
        return PD_INTERNAL_ERR;
}


int GetTxnHeader(const char* csTxnID,
		recordset_t* myRec)
{

//	char	csTmp[PD_DIGIT_LEN + PD_DECIMAL_LEN + 2];
	char	csDate[PD_DATE_LEN +1];
	char	csTime[PD_TIME_LEN +1];
	char	csDateTime[PD_DATE_LEN + PD_TIME_LEN +1];
        hash_t *myHash;
	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO gettxnheader_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_org_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_org_txn_id;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		char		v_status;
		char		v_ar_ind;
		/* varchar		v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		double		v_txn_amt;
		double		v_net_amt;
		/* varchar		v_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_net_ccy;

		/* varchar		v_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

		/* varchar		v_local_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_local_tm_date;

		/* varchar		v_local_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_local_tm_time;

		/* varchar		v_tm_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_tm_date;

		/* varchar		v_tm_time[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_tm_time;

		long		v_internal_code;
		/* varchar		v_channel_code[PD_CHANNEL_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;

		/* varchar		v_response_code[PD_RESPONSE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_response_code;

		/* varchar		v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar		v_process_code[PD_PROCESS_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_process_code;

		/* varchar		v_process_type[PD_PROCESS_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_process_type;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_client_ip[PD_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;

		char		v_ex_supplier;
		double		v_ex_rate;
		double		v_reserve_amt;
		//double		v_markup_amt;
		/* varchar		v_sub_status[PD_SUB_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

		/* varchar		v_reserved_release_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_reserved_release_date;

		/* varchar		v_ack_status[PD_ACK_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ack_status;

		/* varchar		v_approval_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

		/* PRD021 Non-China IP */
		/* varchar		v_ip_region[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_ip_region;

		/* End - PRD021 Non-China IP */

		short		ind_org_txn_id = -1;
		short		ind_client_id = -1;
		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_txn_code = -1;
		short		ind_merchant_id = -1;
		short		ind_merchant_ref = -1;
		short		ind_txn_amt = -1;
		short		ind_net_amt = -1;
		short		ind_net_ccy = -1;
		short		ind_transmission_datetime = -1;
		short		ind_local_tm_date = -1;
		short		ind_local_tm_time = -1;
		short		ind_tm_date = -1;
		short		ind_tm_time = -1;
		short		ind_internal_code = -1;
		short		ind_channel_code = -1;
		short		ind_response_code = -1;
		short		ind_host_posting_date = -1;
		short		ind_process_code= -1;
		short		ind_process_type= -1;
		short		ind_service_code = -1;
		short		ind_client_ip = -1;
		short		ind_ex_supplier = -1;
		short		ind_ex_rate = -1;
		short		ind_reserve_amt = -1;
		//short		ind_markup_amt = -1;
		short		ind_sub_status = -1;
		short		ind_reserved_release_date = -1;
		short		ind_ack_status = -1;
		short		ind_approval_date = -1;
		short		ind_ip_region = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnHeader txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxnheader CURSOR FOR
		select th_org_txn_id, 
		       th_client_id,
		       th_status,
		       th_ar_ind,
		       th_txn_code,
       		       th_merchant_id,
       		       th_merchant_ref,
		       th_transaction_amount,
		       th_net_amount,
		       th_net_ccy,
		       th_transmission_datetime,
		       th_local_tm_date,
		       th_local_tm_time,
		       th_tm_date,
		       th_tm_time,
		       th_internal_code,
		       th_input_channel,
		       th_response_code,
		       th_host_posting_date,
		       th_process_code,
		       th_process_type,
		       th_input_channel,
		       th_service_code,
		       th_client_ip,
		       th_ex_supplier,
		       th_ex_rate,
		       th_reserve_amount,
		       th_sub_status,
		       th_reserved_release_date,
		       th_ack_status,
		       th_approval_date, 
		       /o PRD021 Non-China IP o/
		       th_ip_region 
		       /o End - PRD021 Non-China IP o/
                  from txn_header 
                 where th_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_gettxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0004;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )375;
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
			:v_reserve_amt:ind_reserve_amt,
			:v_sub_status:ind_sub_status,
			:v_reserved_release_date:ind_reserved_release_date,
			:v_ack_status:ind_ack_status,
			:v_approval_date:ind_approval_date, 
			/o PRD021 Non-China IP o/
			:v_ip_region:ind_ip_region; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )394;
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
                sqlstm.sqhstv[26] = (unsigned char  *)&v_reserve_amt;
                sqlstm.sqhstl[26] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_reserve_amt;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[27] = (unsigned long )6;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_sub_status;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_reserved_release_date;
                sqlstm.sqhstl[28] = (unsigned long )11;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_reserved_release_date;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_ack_status;
                sqlstm.sqhstl[29] = (unsigned long )6;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_ack_status;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_approval_date;
                sqlstm.sqhstl[30] = (unsigned long )11;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_approval_date;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_ip_region;
                sqlstm.sqhstl[31] = (unsigned long )5;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_ip_region;
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
                if (sqlca.sqlcode < 0) goto gettxnheader_error;
}


			/* End - PRD021 Non-China IP */

                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_org_txn_id >= 0) {
                        v_org_txn_id.arr[v_org_txn_id.len] ='\0';
                        PutField_CString(myHash,"org_txn_id",(const char*)v_org_txn_id.arr);
DEBUGLOG(("GetTxnHeader org_txn_id = [%s]\n",v_org_txn_id.arr)); 
                }

                if (ind_client_id >= 0) {
                        v_client_id.arr[v_client_id.len] ='\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetTxnHeader client_id = [%s]\n",v_client_id.arr)); 
                }
                if (ind_status >= 0) {
DEBUGLOG(("GetTxnHeader status = [%c]\n",v_status)); 
                        PutField_Char(myHash,"status",v_status);
		}

                if (ind_ar_ind >= 0) {
DEBUGLOG(("GetTxnHeader ar_ind = [%c]\n",v_ar_ind)); 
                        PutField_Char(myHash,"ar_ind",v_ar_ind);
		}

                if (ind_txn_code >= 0) {
                        v_txn_code.arr[v_txn_code.len] ='\0';
                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetTxnHeader txn_code = [%s]\n",v_txn_code.arr)); 
                }

                if (ind_process_code >= 0) {
                        v_process_code.arr[v_process_code.len] ='\0';
                        PutField_CString(myHash,"process_code",(const char*)v_process_code.arr);
DEBUGLOG(("GetTxnHeader process_code = [%s]\n",v_process_code.arr)); 
                }

                if (ind_process_type >= 0) {
                        v_process_type.arr[v_process_type.len] ='\0';
                        PutField_CString(myHash,"process_type",(const char*)v_process_type.arr);
DEBUGLOG(("GetTxnHeader process_type = [%s]\n",v_process_type.arr)); 
                }

                if (ind_merchant_id >= 0) {
                        v_merchant_id.arr[v_merchant_id.len] ='\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetTxnHeader merchant_id = [%s]\n",v_merchant_id.arr)); 
                }
                if (ind_merchant_ref >= 0) {
                        v_merchant_ref.arr[v_merchant_ref.len] ='\0';
                        PutField_CString(myHash,"merchant_ref",(const char*)v_merchant_ref.arr);
DEBUGLOG(("GetTxnHeader merchant_ref = [%s]\n",v_merchant_ref.arr)); 
                }

                if (ind_txn_amt < 0) 
			v_txn_amt = 0.0;
/*
		mydtoc(v_txn_amt,PD_DIGIT_LEN,PD_DECIMAL_LEN,csTmp);
		trim_leading_zero(csTmp,csTmp);
*/
                PutField_Double(myHash,"txn_amt",v_txn_amt);

/*DEBUGLOG(("GetTxnHeader txn_amt = [%s]\n",csTmp)); */
DEBUGLOG(("GetTxnHeader txn_amt = [%f]\n",v_txn_amt)); 

                if (ind_net_amt < 0) 
			v_net_amt = 0.0;	
/*
		mydtoc(v_net_amt,PD_DIGIT_LEN,PD_DECIMAL_LEN,csTmp);
		trim_leading_zero(csTmp,csTmp);
*/
		//PutField_CString(myHash,"net_amt",csTmp);
                PutField_Double(myHash,"net_amt",v_net_amt);
DEBUGLOG(("GetTxnHeader net_amt = [%f]\n",v_net_amt)); 

                if (ind_net_ccy >= 0) {
                        v_net_ccy.arr[v_net_ccy.len] ='\0';
                        PutField_CString(myHash,"net_ccy",(const char*)v_net_ccy.arr);
DEBUGLOG(("GetTxnHeader net_ccy = [%s]\n",v_net_ccy.arr)); 
                }

                if (ind_transmission_datetime >= 0) {
                        v_transmission_datetime.arr[v_transmission_datetime.len] ='\0';
                        PutField_CString(myHash,"transmission_datetime",(const char*)v_transmission_datetime.arr);
DEBUGLOG(("GetTxnHeader transmission_datetime = [%s]\n",v_transmission_datetime.arr)); 
                }
                if (ind_local_tm_date >= 0) {
                        v_local_tm_date.arr[v_local_tm_date.len] ='\0';
			strcpy(csDate,(char*)v_local_tm_date.arr);
                        PutField_CString(myHash,"local_tm_date",(const char*)v_local_tm_date.arr);
DEBUGLOG(("GetTxnHeader local_tm_date = [%s]\n",v_local_tm_date.arr)); 
                }
                if (ind_local_tm_time >= 0) {
                        v_local_tm_time.arr[v_local_tm_time.len] ='\0';
			strcpy(csTime,(char*)v_local_tm_time.arr);
                        PutField_CString(myHash,"local_tm_time",(const char*)v_local_tm_time.arr);
DEBUGLOG(("GetTxnHeader local_tm_time = [%s]\n",v_local_tm_time.arr)); 
                }
                if (ind_tm_date >= 0) {
                        v_tm_date.arr[v_tm_date.len] ='\0';
                        PutField_CString(myHash,"tm_date",(const char*)v_tm_date.arr);
DEBUGLOG(("GetTxnHeader tm_date = [%s]\n",v_tm_date.arr)); 
                }
                if (ind_tm_time >= 0) {
                        v_tm_time.arr[v_tm_time.len] ='\0';
                        PutField_CString(myHash,"tm_time",(const char*)v_tm_time.arr);
DEBUGLOG(("GetTxnHeader tm_time = [%s]\n",v_tm_time.arr)); 
                }
                if (ind_internal_code >= 0) {
                        PutField_Int(myHash,"internal_error",v_internal_code);
DEBUGLOG(("GetTxnHeader internal_code = [%d]\n",v_internal_code)); 
		}
                if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] ='\0';
                        PutField_CString(myHash,"channel_code",(const char*)v_channel_code.arr);
DEBUGLOG(("GetTxnHeader channel_code = [%s]\n",v_channel_code.arr)); 
                }
                if (ind_response_code >= 0) {
                        v_response_code.arr[v_response_code.len] ='\0';
                        PutField_CString(myHash,"response_code",(const char*)v_response_code.arr);
DEBUGLOG(("GetTxnHeader response_code = [%s]\n",v_response_code.arr)); 
                }
                if (ind_host_posting_date >= 0) {
                        v_host_posting_date.arr[v_host_posting_date.len] ='\0';
                        PutField_CString(myHash,"host_posting_date",(const char*)v_host_posting_date.arr);
DEBUGLOG(("GetTxnHeader host_posting_date = [%s]\n",v_host_posting_date.arr)); 
                }

DEBUGLOG(("GetTxnHeader formation local transmission_datetime\n"));
		strcpy(csDateTime,csDate);
		strcat(csDateTime,csTime);
DEBUGLOG(("GetTxnHeader local_transmission_datetime = [%s]\n",csDateTime));
		PutField_CString(myHash,"local_transmission_datetime",csDateTime);

                if (ind_service_code >= 0) {
                        v_service_code.arr[v_service_code.len] ='\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetTxnHeader service_code = [%s]\n",v_service_code.arr)); 
                }

                if (ind_client_ip>= 0) {
                        v_client_ip.arr[v_client_ip.len] ='\0';
                        PutField_CString(myHash,"ip_addr",(const char*)v_client_ip.arr);
DEBUGLOG(("GetTxnHeader client_ip = [%s]\n",v_client_ip.arr)); 
                }

                if (ind_ex_supplier>= 0) {
DEBUGLOG(("GetTxnHeader ex_supplier = [%c]\n",v_ex_supplier)); 
                        PutField_Char(myHash,"ex_supplier",v_ex_supplier);
		}

                if (ind_ex_rate < 0) 
			v_ex_rate = 0.0;
DEBUGLOG(("GetTxnHeader ex_rate = [%f]\n",v_ex_rate)); 
		PutField_Double(myHash,"ex_rate",v_ex_rate);
		
                if (ind_reserve_amt< 0) 
			v_reserve_amt= 0.0;
DEBUGLOG(("GetTxnHeader reserve_amt = [%f]\n",v_reserve_amt)); 
		PutField_Double(myHash,"reserve_amt",v_reserve_amt);
		
                if (ind_sub_status>= 0) {
                        v_sub_status.arr[v_sub_status.len] ='\0';
                        PutField_CString(myHash,"sub_status",(const char*)v_sub_status.arr);
DEBUGLOG(("GetTxnHeader sub_status = [%s]\n",v_sub_status.arr)); 
                }

                if (ind_reserved_release_date>= 0) {
                        v_reserved_release_date.arr[v_reserved_release_date.len] ='\0';
                        PutField_CString(myHash,"reserved_release_date",(const char*)v_reserved_release_date.arr);
DEBUGLOG(("GetTxnHeader reserved_release_date = [%s]\n",v_reserved_release_date.arr)); 
                }

		if (ind_ack_status >= 0) {
			v_ack_status.arr[v_ack_status.len] = '\0';
			PutField_CString(myHash, "ack_status", (const char*)v_ack_status.arr);
DEBUGLOG(("GetTxnHeader ack_status = [%s]\n",v_ack_status.arr));
		}

		if (ind_approval_date >= 0) {
			v_approval_date.arr[v_approval_date.len] = '\0';
			PutField_CString(myHash, "approval_date", (const char*)v_approval_date.arr);
DEBUGLOG(("GetTxnHeader approval_date = [%s]\n",v_approval_date.arr));
		}

		/* PRD021 Non-China IP */
		/* ip_region */
		if (ind_ip_region >= 0)
		{
			v_ip_region.arr[v_ip_region.len] = '\0';
			PutField_CString(myHash, "ip_region", (const char*)v_ip_region.arr);
DEBUGLOG(("GetTxnHeader ip_region = [%s]\n", v_ip_region.arr));
		}
		/* End - PRD021 Non-China IP */

		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )537;
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
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )552;
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
        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar		v_txn_country[PD_COUNTRY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar		v_pay_method[PD_PAY_METHOD_LIST_LEN+ 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_pay_method;

		/* varchar		v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

		char		v_show_paypage;
		/* varchar		v_language[PD_LANGUAGE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_language;

		/* varchar		v_success_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_success_url;

		/* varchar		v_failure_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_failure_url;

		/* varchar		v_success_ck_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_success_ck_url;

		/* varchar		v_failure_ck_url[PD_URL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_failure_ck_url;

		/* varchar		v_encrypt_type[PD_ENCRYPT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_encrypt_type;

		/* varchar		v_bank_name[PD_AC_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_bank_name;

		/* varchar		v_branch[PD_BANK_BRANCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_branch;

		/* varchar		v_account_id[PD_AC_NO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_account_id;

		/* varchar		v_account_name[PD_AC_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_account_name;

		/* varchar		v_batch_id[PD_BATCH_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_batch_id;

		/* varchar		v_identity_id[PD_IDENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_identity_id;

		/* varchar		v_remark[PD_REMARK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;

		/* varchar		v_selected_pay_method[PD_SELECTED_PAY_METHOD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_selected_pay_method;

		/* varchar         v_banner_logo[PD_BANNER_LOGO_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_banner_logo;

                /* varchar         v_customer_tag[PD_CUSTOMER_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_tag;

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

                /* varchar         v_selected_pid[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_selected_pid;

                /* varchar         v_customer_tel[PD_CUSTOMER_TEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_customer_tel;

                /* varchar         v_magic_num[PD_MAGIC_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_magic_num;

                /* varchar         v_magic_word[PD_MAGIC_WORD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_magic_word;

                /* varchar         v_customer_id[PD_MAGIC_CUST_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_customer_id;

                /* varchar         v_customer_group[PD_CUSTOMER_GROUP_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_customer_group;

                int		v_vp_txn_gp_id;

		short		ind_txn_ccy = -1;
		short		ind_txn_country = -1;
		short		ind_pay_method = -1;
		short		ind_bank_code = -1;
		short		ind_show_paypage = -1;
		short		ind_language = -1;
		short		ind_success_url = -1;
		short		ind_failure_url = -1;
		short		ind_success_ck_url = -1;
		short		ind_failure_ck_url = -1;
		short		ind_encrypt_type = -1;
		short		ind_bank_name = -1;
		short		ind_branch= -1;
		short		ind_account_id= -1;
		short		ind_account_name= -1;
		short		ind_batch_id= -1;
		short		ind_identity_id= -1;
		short		ind_remark = -1;
		short		ind_selected_pay_method = -1;
		short           ind_banner_logo = -1;
                short           ind_customer_tag = -1;
                short           ind_echo_msg_1 = -1;
                short           ind_echo_msg_2 = -1;
                short           ind_echo_msg_3 = -1;
                short           ind_opt_1 = -1;
                short           ind_opt_2 = -1;
                short           ind_opt_3 = -1;
                short           ind_selected_pid = -1;
                short           ind_customer_tel = -1;
                short           ind_magic_num = -1;
                short           ind_magic_word = -1;
                short           ind_customer_id = -1;
                short           ind_customer_group = -1;
                short           ind_vp_txn_gp_id = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_txn_id.len = strlen(csTxnID);
	memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxndetail CURSOR FOR
		select 
			td_txn_ccy,
			td_txn_country,
			td_pay_method,
			td_bank_code,
			td_show_paypage,
			td_language,
			td_success_url,
			td_failure_url,
			td_success_callback_url,
			td_failure_callback_url,
			td_encrypt_type,
			td_bank_name,
			td_branch_name,
			td_account_id,
			td_account_name,
			td_batch_id,
			td_identity_id,
			td_remark,
			td_selected_pay_method,
			td_banner_logo,
                        td_customer_tag,
                        td_echo_msg_1,
                        td_echo_msg_2,
                        td_echo_msg_3,
                        td_opt_1,
                        td_opt_2,
                        td_opt_3,
                        td_selected_pid,
			td_customer_tel,
			td_magic_num,
			td_magic_word,
			td_customer_id,
			td_customer_group,
			td_txn_gp_id
		  from txn_detail
		 where td_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_gettxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0005;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )567;
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
        if (sqlca.sqlcode < 0) goto gettxndetail_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxndetail
                INTO
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_country:ind_txn_country,
			:v_pay_method:ind_pay_method,
			:v_bank_code:ind_bank_code,
			:v_show_paypage:ind_show_paypage,
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
                        :v_customer_tag:ind_customer_tag,
                        :v_echo_msg_1:ind_echo_msg_1,
                        :v_echo_msg_2:ind_echo_msg_2,
                        :v_echo_msg_3:ind_echo_msg_3,
                        :v_opt_1:ind_opt_1,
                        :v_opt_2:ind_opt_2,
                        :v_opt_3:ind_opt_3,
			:v_selected_pid:ind_selected_pid,
			:v_customer_tel:ind_customer_tel,
			:v_magic_num:ind_magic_num,
			:v_magic_word:ind_magic_word,
			:v_customer_id:ind_customer_id,
			:v_customer_group:ind_customer_group,
			:v_vp_txn_gp_id:ind_vp_txn_gp_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )586;
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
                sqlstm.sqhstv[4] = (unsigned char  *)&v_show_paypage;
                sqlstm.sqhstl[4] = (unsigned long )1;
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_show_paypage;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_language;
                sqlstm.sqhstl[5] = (unsigned long )5;
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_language;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_success_url;
                sqlstm.sqhstl[6] = (unsigned long )258;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_success_url;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_failure_url;
                sqlstm.sqhstl[7] = (unsigned long )258;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_failure_url;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_success_ck_url;
                sqlstm.sqhstl[8] = (unsigned long )258;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_success_ck_url;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_failure_ck_url;
                sqlstm.sqhstl[9] = (unsigned long )258;
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_failure_ck_url;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_encrypt_type;
                sqlstm.sqhstl[10] = (unsigned long )7;
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_encrypt_type;
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
                sqlstm.sqhstv[12] = (unsigned char  *)&v_branch;
                sqlstm.sqhstl[12] = (unsigned long )153;
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_branch;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_account_id;
                sqlstm.sqhstl[13] = (unsigned long )28;
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_account_id;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_account_name;
                sqlstm.sqhstl[14] = (unsigned long )103;
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_account_name;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_batch_id;
                sqlstm.sqhstl[15] = (unsigned long )23;
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_batch_id;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_identity_id;
                sqlstm.sqhstl[16] = (unsigned long )28;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_identity_id;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_remark;
                sqlstm.sqhstl[17] = (unsigned long )258;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_remark;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_selected_pay_method;
                sqlstm.sqhstl[18] = (unsigned long )7;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_selected_pay_method;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_banner_logo;
                sqlstm.sqhstl[19] = (unsigned long )258;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_banner_logo;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_customer_tag;
                sqlstm.sqhstl[20] = (unsigned long )13;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_customer_tag;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_echo_msg_1;
                sqlstm.sqhstl[21] = (unsigned long )258;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_echo_msg_1;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_echo_msg_2;
                sqlstm.sqhstl[22] = (unsigned long )258;
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_echo_msg_2;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_echo_msg_3;
                sqlstm.sqhstl[23] = (unsigned long )258;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_echo_msg_3;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_opt_1;
                sqlstm.sqhstl[24] = (unsigned long )53;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_opt_1;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_opt_2;
                sqlstm.sqhstl[25] = (unsigned long )53;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_opt_2;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
                sqlstm.sqhstv[26] = (unsigned char  *)&v_opt_3;
                sqlstm.sqhstl[26] = (unsigned long )53;
                sqlstm.sqhsts[26] = (         int  )0;
                sqlstm.sqindv[26] = (         short *)&ind_opt_3;
                sqlstm.sqinds[26] = (         int  )0;
                sqlstm.sqharm[26] = (unsigned long )0;
                sqlstm.sqadto[26] = (unsigned short )0;
                sqlstm.sqtdso[26] = (unsigned short )0;
                sqlstm.sqhstv[27] = (unsigned char  *)&v_selected_pid;
                sqlstm.sqhstl[27] = (unsigned long )13;
                sqlstm.sqhsts[27] = (         int  )0;
                sqlstm.sqindv[27] = (         short *)&ind_selected_pid;
                sqlstm.sqinds[27] = (         int  )0;
                sqlstm.sqharm[27] = (unsigned long )0;
                sqlstm.sqadto[27] = (unsigned short )0;
                sqlstm.sqtdso[27] = (unsigned short )0;
                sqlstm.sqhstv[28] = (unsigned char  *)&v_customer_tel;
                sqlstm.sqhstl[28] = (unsigned long )23;
                sqlstm.sqhsts[28] = (         int  )0;
                sqlstm.sqindv[28] = (         short *)&ind_customer_tel;
                sqlstm.sqinds[28] = (         int  )0;
                sqlstm.sqharm[28] = (unsigned long )0;
                sqlstm.sqadto[28] = (unsigned short )0;
                sqlstm.sqtdso[28] = (unsigned short )0;
                sqlstm.sqhstv[29] = (unsigned char  *)&v_magic_num;
                sqlstm.sqhstl[29] = (unsigned long )23;
                sqlstm.sqhsts[29] = (         int  )0;
                sqlstm.sqindv[29] = (         short *)&ind_magic_num;
                sqlstm.sqinds[29] = (         int  )0;
                sqlstm.sqharm[29] = (unsigned long )0;
                sqlstm.sqadto[29] = (unsigned short )0;
                sqlstm.sqtdso[29] = (unsigned short )0;
                sqlstm.sqhstv[30] = (unsigned char  *)&v_magic_word;
                sqlstm.sqhstl[30] = (unsigned long )153;
                sqlstm.sqhsts[30] = (         int  )0;
                sqlstm.sqindv[30] = (         short *)&ind_magic_word;
                sqlstm.sqinds[30] = (         int  )0;
                sqlstm.sqharm[30] = (unsigned long )0;
                sqlstm.sqadto[30] = (unsigned short )0;
                sqlstm.sqtdso[30] = (unsigned short )0;
                sqlstm.sqhstv[31] = (unsigned char  *)&v_customer_id;
                sqlstm.sqhstl[31] = (unsigned long )53;
                sqlstm.sqhsts[31] = (         int  )0;
                sqlstm.sqindv[31] = (         short *)&ind_customer_id;
                sqlstm.sqinds[31] = (         int  )0;
                sqlstm.sqharm[31] = (unsigned long )0;
                sqlstm.sqadto[31] = (unsigned short )0;
                sqlstm.sqtdso[31] = (unsigned short )0;
                sqlstm.sqhstv[32] = (unsigned char  *)&v_customer_group;
                sqlstm.sqhstl[32] = (unsigned long )13;
                sqlstm.sqhsts[32] = (         int  )0;
                sqlstm.sqindv[32] = (         short *)&ind_customer_group;
                sqlstm.sqinds[32] = (         int  )0;
                sqlstm.sqharm[32] = (unsigned long )0;
                sqlstm.sqadto[32] = (unsigned short )0;
                sqlstm.sqtdso[32] = (unsigned short )0;
                sqlstm.sqhstv[33] = (unsigned char  *)&v_vp_txn_gp_id;
                sqlstm.sqhstl[33] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[33] = (         int  )0;
                sqlstm.sqindv[33] = (         short *)&ind_vp_txn_gp_id;
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
                if (sqlca.sqlcode < 0) goto gettxndetail_error;
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

/* show paypage */
                if (ind_show_paypage  >=  0) { 
                        PutField_Char(myHash,"show_paypage",v_show_paypage);
DEBUGLOG(("GetTxnDetail show_paypage = [%c]\n",v_show_paypage));
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

/* customer_tag*/
                if (ind_customer_tag>=  0) {
                        v_customer_tag.arr[v_customer_tag.len] = '\0';
                        PutField_CString(myHash,"customer_tag",(const char*)v_customer_tag.arr);
DEBUGLOG(("GetTxnDetail customer_tag = [%s]\n",v_customer_tag.arr));
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

/* selected_pid*/
                if (ind_selected_pid>=  0) {
                        v_selected_pid.arr[v_selected_pid.len] = '\0';
                        PutField_CString(myHash,"selected_pid",(const char*)v_selected_pid.arr);
DEBUGLOG(("GetTxnDetail selected_pid = [%s]\n",v_selected_pid.arr));
                }
/* customer_tel*/
                if (ind_customer_tel>=  0) {
                        v_customer_tel.arr[v_customer_tel.len] = '\0';
                        PutField_CString(myHash,"customer_tel",(const char*)v_customer_tel.arr);
DEBUGLOG(("GetTxnDetail customer_tel = [%s]\n",v_customer_tel.arr));
                }

/* magic_num*/
                if (ind_magic_num>=  0) {
                        v_magic_num.arr[v_magic_num.len] = '\0';
                        PutField_CString(myHash,"magic_num",(const char*)v_magic_num.arr);
DEBUGLOG(("GetTxnDetail magic_num = [%s]\n",v_magic_num.arr));
                }

/* magic_word */
                if (ind_magic_word>=  0) {
                        v_magic_word.arr[v_magic_word.len] = '\0';
                        PutField_CString(myHash,"magic_word",(const char*)v_magic_word.arr);
DEBUGLOG(("GetTxnDetail magic_word = [%s]\n",v_magic_word.arr));
                }

/* customer_id */
                if (ind_customer_id>=  0) {
                        v_customer_id.arr[v_customer_id.len] = '\0';
                        PutField_CString(myHash,"customer_id",(const char*)v_customer_id.arr);
DEBUGLOG(("GetTxnDetail customer_id = [%s]\n",v_customer_id.arr));
                }

/* customer_group */
                if (ind_customer_group>=  0) {
                        v_customer_group.arr[v_customer_group.len] = '\0';
                        PutField_CString(myHash,"customer_group",(const char*)v_customer_group.arr);
DEBUGLOG(("GetTxnDetail customer_group = [%s]\n",v_customer_group.arr));
                }

/* vp_txn_gp_id */
                if (ind_vp_txn_gp_id>=  0) {
                        PutField_Int(myHash,"txn_gp_id",v_vp_txn_gp_id);
DEBUGLOG(("GetTxnDetail txn_gp_id = [%d]\n",v_vp_txn_gp_id));
                }


		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )737;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto gettxndetail_error;
}




DEBUGLOG(("GetTxnDetail Normal Exit\n")); 
        return  PD_OK;

gettxndetail_error:
DEBUGLOG(("gettxndetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_gettxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )752;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
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

		/* varchar		hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
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
                        :hv_return_value := sp_transaction_matchmref(:hv_merchant_id,
                                                		     :hv_merchant_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_transaction_matchmref (\
 :hv_merchant_id , :hv_merchant_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )767;
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
                return PD_FOUND;
	}
	else {
DEBUGLOG(("MatchMerchantref Not Found\n"));
		return PD_NOT_FOUND;
	}
        

matchmerchantref_error:
DEBUGLOG(("matchmerchantref_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

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

		char		hv_status;
		
		/* varchar         v_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;


                short           ind_date = -1;
                        
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
                
	hv_status = cStatus;
DEBUGLOG(("MatchRespTxn status = [%c]\n",hv_status));

	/* EXEC SQL SELECT th_host_posting_date
                INTO    :v_date:ind_date
                FROM    txn_header
                WHERE   th_txn_id = :hv_txn_id
                and     th_status = :hv_status
                for update; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select th_host_posting_date INTO :b0:b1 FROM txn_header WHE\
RE th_txn_id = :b2 and th_status = :b3 for update ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )794;
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

int MatchRespTxnStatus(const char* csTxnSeq,
                     const char cStatus,
			const char cArInd)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnStatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_status;
		char		hv_ar_ind;
		
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

	/* EXEC SQL SELECT th_host_posting_date
                INTO    :v_host_posting_date:ind_host_posting_date
                FROM    txn_header
                WHERE   th_txn_id = :hv_txn_id
                and     th_status = :hv_status
                and     th_ar_ind = :hv_ar_ind
                for update; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select th_host_posting_date INTO :b0:b1 FROM txn_header WHE\
RE th_txn_id = :b2 and th_status = :b3 and th_ar_ind = :b4 for update ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )821;
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

int MatchRespTxnByRemark(const char* csRemark,
                     const char cStatus,
			char*	csOrgTxnId)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxnByRemark_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

                char            hv_status;
                 
                /* varchar         v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

                /* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

        
                short           ind_merchant_id = -1;
                short           ind_txn_id = -1;
                        
        /* EXEC SQL END DECLARE SECTION; */ 

        
        hv_remark.len = strlen(csRemark);
        memcpy(hv_remark.arr,csRemark,hv_remark.len);
DEBUGLOG(("MatchRespTxnByRemark remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
                        
        hv_status = cStatus;
DEBUGLOG(("MatchRespTxnByRemark status = [%c]\n",hv_status));
        
        /* EXEC SQL SELECT th_merchant_id,
			th_txn_id
                INTO    :v_merchant_id:ind_merchant_id,
			:v_txn_id:ind_txn_id
                  FROM txn_detail,
                       txn_header
                 WHERE td_remark = :hv_remark
                   AND td_txn_id = th_txn_id
                   AND th_status = :hv_status
       		   for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select th_merchant_id , th_txn_id INTO :b0:b1 , :b2:\
b3 FROM txn_detail , txn_header WHERE td_remark = :b4 AND td_txn_id = th_txn_\
id AND th_status = :b5 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )852;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_merchant_id;
        sqlstm.sqhstl[0] = (unsigned long )18;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_merchant_id;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_remark;
        sqlstm.sqhstl[2] = (unsigned long )257;
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
        if (sqlca.sqlcode < 0) goto MatchRespTxnByRemark_error;
}

 
        
        if(ind_merchant_id>=0){
        	if(ind_txn_id>=0){
                        v_txn_id.arr[v_txn_id.len] = '\0';
			strcpy(csOrgTxnId,(char*)v_txn_id.arr);
DEBUGLOG(("MatchRespTxnByRemark org_txn_id = [%s]\n",csOrgTxnId));
		}
DEBUGLOG(("MatchRespTxnByRemark Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchRespTxnByRemark Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchRespTxnByRemark_error:
DEBUGLOG(("MatchRespTxnByRemark_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int 	ChkTxnCodeExist(const char *csTxnCode)
{
	int 	iRet = PD_NOT_FOUND;

        /* EXEC SQL WHENEVER SQLERROR GOTO chktxncodeexist_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;


		int		v_no_of_record;
		short		ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 
	

	hv_txn_code.len = strlen(csTxnCode);
	memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("ChkTxnCodeExist = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

	/* EXEC SQL 
		SELECT count(1)
		   INTO :v_no_of_record:ind_no_of_record
		   FROM txn_header
		  WHERE th_txn_code = :hv_txn_code
		    and rownum = 1; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_header WHERE th_txn\
_code = :b2 and rownum = 1 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )883;
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


int MatchHostRef(const char* csChannelCode,
                 const char* csMmsHostRef)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO matchhostref_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	 	short           hv_return_value;
                /* varchar         hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

		/* varchar		hv_host_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_host_ref;


                        
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_channel_code.len = strlen(csChannelCode);
        memcpy(hv_channel_code.arr,csChannelCode,hv_channel_code.len);
DEBUGLOG(("MatchHostRef channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
                
        hv_host_ref.len = strlen(csMmsHostRef);
        memcpy(hv_host_ref.arr,csMmsHostRef,hv_host_ref.len);
DEBUGLOG(("MatchHostRef host_ref = [%.*s]\n",hv_host_ref.len,hv_host_ref.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_matchhostref(:hv_channel_code,
                                                		:hv_host_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_matchhostref ( :hv_\
channel_code , :hv_host_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )906;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_channel_code;
        sqlstm.sqhstl[1] = (unsigned long )5;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_host_ref;
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
        if (sqlca.sqlcode < 0) goto matchhostref_error;
}



        if (hv_return_value > 0)  {

DEBUGLOG(("MatchHostRef Found\n"));
                return PD_FOUND;
	}
	else {
DEBUGLOG(("MatchHostRef Not Found\n"));
		return PD_NOT_FOUND;
	}
        

matchhostref_error:
DEBUGLOG(("matchhostref_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int GetMmsDetail(const char* csMmsHostRef,
		  recordset_t* myRec)
{

        hash_t *myHash;
	int	iCnt = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmmsdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_host_ref[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_host_ref;


		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar		v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar		v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar		v_client_id[PD_CLIENT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar		v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar		v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar		v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		char		v_status;
		char		v_ar_ind;
		double		v_txn_amt;
		

		short		ind_txn_id= -1;
		short		ind_txn_code= -1;
		short		ind_merchant_id= -1;
		short		ind_client_id= -1;
		short		ind_service_code= -1;
		short		ind_psp_id= -1;
		short		ind_txn_ccy= -1;
		short		ind_status= -1;
		short		ind_ar_ind= -1;
		short		ind_txn_amt= -1;


        /* EXEC SQL END DECLARE SECTION; */ 


	hv_host_ref.len = strlen(csMmsHostRef);
	memcpy(hv_host_ref.arr,csMmsHostRef,hv_host_ref.len);
DEBUGLOG(("GetMmsDetail host_ref = [%.*s]\n",hv_host_ref.len,hv_host_ref.arr));

        /* EXEC SQL DECLARE c_cursor_getmmsdt CURSOR FOR
		select 
			th_txn_id,
			th_txn_code,
			th_merchant_id,
			th_client_id,
			th_service_code,
			tp_psp_id,
			td_txn_ccy,
			th_status,
			th_ar_ind,
			th_transaction_amount
		from	txn_detail,
			(txn_header
			left join txn_psp_detail
			on th_txn_id = tp_txn_id)
		where	th_txn_id=td_txn_id
		and	td_remark = :hv_host_ref
		and	th_org_txn_id is null
		and	th_status = 'C'
		and 	th_ar_ind = 'A'; */ 
  
 
        /* EXEC SQL OPEN c_cursor_getmmsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0012;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )933;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_host_ref;
        sqlstm.sqhstl[0] = (unsigned long )257;
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
        if (sqlca.sqlcode < 0) goto getmmsdt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getmmsdt
                INTO
			:v_txn_id:ind_txn_id,
			:v_txn_code:ind_txn_code,
			:v_merchant_id:ind_merchant_id,
			:v_client_id:ind_client_id,
			:v_service_code:ind_service_code,
			:v_psp_id:ind_psp_id,
			:v_txn_ccy:ind_txn_ccy,
			:v_status:ind_status,
			:v_ar_ind:ind_ar_ind,
			:v_txn_amt:ind_txn_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )952;
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
                sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_id;
                sqlstm.sqhstl[2] = (unsigned long )18;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_merchant_id;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_client_id;
                sqlstm.sqhstl[3] = (unsigned long )13;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_client_id;
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
                sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_ccy;
                sqlstm.sqhstl[6] = (unsigned long )6;
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_txn_ccy;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[7] = (unsigned long )1;
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_status;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[8] = (unsigned long )1;
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_txn_amt;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
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
                if (sqlca.sqlcode < 0) goto getmmsdt_error;
}




                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

/* txn id*/
                if (ind_txn_id>=  0) { 
			v_txn_id.arr[v_txn_id.len] = '\0';
                        PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("GetMmsDetail txn_id = [%s]\n",v_txn_id.arr));
		}

/* txn code */
                if (ind_txn_code>=  0) { 
			v_txn_code.arr[v_txn_code.len] = '\0';
                        PutField_CString(myHash,"txn_code",(const char*)v_txn_code.arr);
DEBUGLOG(("GetMmsDetail txn_code = [%s]\n",v_txn_code.arr));
		}

/* merchant id*/
                if (ind_merchant_id>=  0) { 
			v_merchant_id.arr[v_merchant_id.len] = '\0';
                        PutField_CString(myHash,"merchant_id",(const char*)v_merchant_id.arr);
DEBUGLOG(("GetMmsDetail merchant_id = [%s]\n",v_merchant_id.arr));
		}

/* client id*/
                if (ind_client_id>=  0) { 
			v_client_id.arr[v_client_id.len] = '\0';
                        PutField_CString(myHash,"client_id",(const char*)v_client_id.arr);
DEBUGLOG(("GetMmsDetail client_id = [%s]\n",v_client_id.arr));
		}

/* service_code */
                if (ind_service_code>=  0) { 
			v_service_code.arr[v_service_code.len] = '\0';
                        PutField_CString(myHash,"service_code",(const char*)v_service_code.arr);
DEBUGLOG(("GetMmsDetail service_code = [%s]\n",v_service_code.arr));
		}

/* psp id */
                if (ind_psp_id>=  0) { 
			v_psp_id.arr[v_psp_id.len] = '\0';
                        PutField_CString(myHash,"psp_id",(const char*)v_psp_id.arr);
DEBUGLOG(("GetMmsDetail psp_id = [%s]\n",v_psp_id.arr));
		}

/* txn ccy */
                if (ind_txn_ccy  >=  0) { 
			v_txn_ccy.arr[v_txn_ccy.len] = '\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetMmsDetail txn_ccy = [%s]\n",v_txn_ccy.arr));
		}

/* txn_amt */
                if (ind_txn_amt <  0)
			v_txn_amt = 0.0;
                        PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetMmsDetail txn_amt = [%lf]\n",v_txn_amt));


/* status */
                if (ind_status>=  0) { 
                        PutField_Char(myHash,"status",v_status);
DEBUGLOG(("GetMmsDetail status = [%c]\n",v_status));
		}

/* ar_ind */
                if (ind_ar_ind>=  0) { 
                        PutField_Char(myHash,"ar_ind",v_ar_ind);
DEBUGLOG(("GetMmsDetail ar_ind = [%c]\n",v_ar_ind));
		}

		iCnt ++;
		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getmmsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1007;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getmmsdt_error;
}



	if(iCnt>0){
DEBUGLOG(("GetMmsDetail Normal Exit\n")); 
        	return  PD_FOUND;
	}
	else{
DEBUGLOG(("GetMmsDetail Normal Exit, Not Found\n")); 
        	return  PD_NOT_FOUND;
	}

getmmsdt_error:
DEBUGLOG(("getmmsdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmmsdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1022;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;


	
}

int AddTxnStatusLog(const hash_t *hCon)
{
	char	*csTmp;
	char	cTmp;
	
	/* EXEC SQL WHENEVER SQLERROR GOTO add_txnstatuslogerror; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_status;
		char		hv_ar_ind;
		/* varchar		hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		/* varchar		hv_create_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_create_user;



		short		ind_txn_id = -1;
		short		ind_status = -1;
		short		ind_ar_ind = -1;
		short		ind_sub_status = -1;
		short		ind_create_user = -1;

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
			:hv_return_value := sp_txn_status_log_insert(
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
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_status_log_insert ( :hv_tx\
n_id:ind_txn_id , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_sub_sta\
tus:ind_sub_status , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1037;
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
ERRLOG("Transaction:AddTxnStatusLog: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction:AddTxnStatusLog: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_txnstatuslogerror:
DEBUGLOG(("add_txnstatuslogerror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("TxnCode_add_txnstatuslogerror: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}
int UpdateReleaseReserveDate(const char* csTxnId,const char* csReleaseDate,const char* csSubStatus,const char* csAddUser)
{
	/* EXEC SQL WHENEVER SQLERROR GOTO updatereleasereservedate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		/* varchar		hv_release_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_release_date;

		/* varchar		hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

		/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;



		short		ind_txn_id = -1;
		short		ind_release_date = -1;
		short		ind_sub_status = -1;
		short		ind_add_user = -1;
		short           hv_return_value;

        /* EXEC SQL END DECLARE SECTION; */ 



DEBUGLOG(("UpdateReleaseReserveDate: Begin\n"));


        hv_txn_id.len = strlen(csTxnId);
        strncpy((char *)hv_txn_id.arr, csTxnId, hv_txn_id.len);
        ind_txn_id = 0;
DEBUGLOG(("UpdateReleaseReserveDate:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_release_date.len = strlen(csReleaseDate);
        strncpy((char *)hv_release_date.arr, csReleaseDate, hv_release_date.len);
        ind_release_date = 0;
DEBUGLOG(("UpdateReleaseReserveDate:release_date = [%.*s]\n",hv_release_date.len,hv_release_date.arr));

        hv_sub_status.len = strlen(csSubStatus);
        strncpy((char *)hv_sub_status.arr, csSubStatus, hv_sub_status.len);
        ind_sub_status = 0;
DEBUGLOG(("UpdateReleaseReserveDate:sub_status = [%.*s]\n",hv_sub_status.len,hv_sub_status.arr));

        hv_add_user.len = strlen(csAddUser);
        strncpy((char *)hv_add_user.arr, csAddUser, hv_add_user.len);
        ind_add_user = 0;
DEBUGLOG(("UpdateReleaseReserveDate:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));

        /* EXEC SQL EXECUTE
            BEGIN

                :hv_return_value := sp_txn_upd_release_res(
				:hv_txn_id:ind_txn_id,
				:hv_release_date:ind_release_date,
				:hv_sub_status:ind_sub_status,
                                :hv_add_user:ind_add_user);

            END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_upd_release_res ( :\
hv_txn_id:ind_txn_id , :hv_release_date:ind_release_date , :hv_sub_status:ind\
_sub_status , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1076;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_sub_status;
        sqlstm.sqhstl[3] = (unsigned long )5;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_sub_status;
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
        if (sqlca.sqlcode < 0) goto updatereleasereservedate_error;
}




DEBUGLOG(("UpdateReleaseReserveDate:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("UpdateReleaseReserveDate:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction::UpdateReleaseReserveDate: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("UpdateReleaseReserveDate: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction::UpdateReleaseReserveDate: SP_ERR TxnAbort\n");
DEBUGLOG(("UpdateReleaseReserveDate: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

updatereleasereservedate_error:
DEBUGLOG(("updatereleasereservedate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
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
		if(strlen(csTmp)>(PD_REMARK_LEN*2)){
			hv_user_agent.len = (PD_REMARK_LEN*2);
		}
		else{
			hv_user_agent.len = strlen(csTmp);
		}
		memcpy(hv_user_agent.arr,csTmp,hv_user_agent.len);
		hv_user_agent.arr[hv_user_agent.len] = '\0';

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
                        :hv_return_value := sp_txn_browser_info_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_client_ip:ind_client_ip,
                                        :hv_user_agent:ind_user_agent,
                                        :hv_add_user:ind_add_user);
                END;
            END-EXEC; */ 

{
            struct sqlexd sqlstm;
            sqlstm.sqlvsn = 12;
            sqlstm.arrsiz = 40;
            sqlstm.sqladtp = &sqladt;
            sqlstm.sqltdsp = &sqltds;
            sqlstm.stmt = "begin :hv_return_value := sp_txn_browser_info_in\
sert ( :hv_txn_id:ind_txn_id , :hv_client_ip:ind_client_ip , :hv_user_agent:i\
nd_user_agent , :hv_add_user:ind_add_user ) ; END ;";
            sqlstm.iters = (unsigned int  )1;
            sqlstm.offset = (unsigned int  )1111;
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

ERRLOG("Transaction_AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}

int MatchRespTxn_ReadOnly(const char* csTxnSeq,
                     const char cStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchRespTxn_RO_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

                
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

	 	//short           hv_return_value;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

		char		hv_status;
		
		/* varchar         v_date[PD_DATE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_date;


                short           ind_date = -1;
                        
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchRespTxn_ReadOnly txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
                
	hv_status = cStatus;
DEBUGLOG(("MatchRespTxn_ReadOnly status = [%c]\n",hv_status));

	/* EXEC SQL SELECT th_host_posting_date
                INTO    :v_date:ind_date
                FROM    txn_header
                WHERE   th_txn_id = :hv_txn_id
                and     th_status = :hv_status; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select th_host_posting_date INTO :b0:b1 FROM txn_header WHE\
RE th_txn_id = :b2 and th_status = :b3 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1146;
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
 if (sqlca.sqlcode < 0) goto MatchRespTxn_RO_error;
}



        if(ind_date>=0){
DEBUGLOG(("MatchRespTxn_ReadOnly Found\n"));
                return PD_FOUND;
	}
	else {
DEBUGLOG(("MatchRespTxn_ReadOnly Not Found\n"));
		return PD_NOT_FOUND;
	}
        

MatchRespTxn_RO_error:
DEBUGLOG(("MatchRespTxn_RO_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}


int     GetRecCntByCustID(const char *csCustID, const char* csTxnCode, const double dDuration, int *iCnt)
{
	int     iRet = PD_OK;

	/* EXEC SQL WHENEVER SQLERROR GOTO getreccntbycustid_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_magic_cust_id[PD_MAGIC_CUST_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_magic_cust_id;

		/* varchar		hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

		double		hv_period;

		int             v_no_of_record;
		short           ind_no_of_record = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_magic_cust_id.len = strlen(csCustID);
        memcpy(hv_magic_cust_id.arr, csCustID, hv_magic_cust_id.len);
DEBUGLOG(("GetRecCntByCustID cust_id = [%.*s]\n",hv_magic_cust_id.len,hv_magic_cust_id.arr));

	hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("GetRecCntByCustID txn_code = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

	hv_period = dDuration;
DEBUGLOG(("GetRecCntByCustID period = [%lf]\n", hv_period)); 

        /* EXEC SQL
		SELECT count(1)
		INTO :v_no_of_record:ind_no_of_record
		FROM txn_detail,txn_header
		WHERE th_create_timestamp >= sysdate - (:hv_period / 24)
		AND th_txn_code = :hv_txn_code
		AND th_ar_ind = 'A'
		and th_txn_id = td_txn_id
		and td_customer_id = :hv_magic_cust_id; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_detail , txn\
_header WHERE th_create_timestamp >= sysdate - ( :b2 / 24 ) AND th_txn_code =\
 :b3 AND th_ar_ind = 'A' and th_txn_id = td_txn_id and td_customer_id = :b4 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1173;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_period;
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
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_magic_cust_id;
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
        if (sqlca.sqlcode < 0) goto getreccntbycustid_error;
}



        if (ind_no_of_record >= 0) {
DEBUGLOG(("GetRecCntByCustID FOUND\n"));
		*iCnt = v_no_of_record;
DEBUGLOG(("GetRecCntByCustID RecCnt [%d]\n", *iCnt));
	} else {
DEBUGLOG(("GetRecCntByCustID ERR\n"));
		iRet = PD_ERR;
	}

        return iRet;

getreccntbycustid_error:
DEBUGLOG(("GetRecCntByCustID_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;

}

int GetCustomerHistoryTxnList(const char *csMerchantId,
		       const char *csCountry,
		       const char *csServiceCode,
		       const char *csTxnCcy,
		       const char *csCustomerTag,
		       const char *csCustomerGroup,
		       hash_t *hTxn)
{
	int	iCnt = 0;
	char	csTag[PD_TAG_LEN+1];

        /* EXEC SQL WHENEVER SQLERROR GOTO getcusthis_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar		hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

		/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

		/* varchar		hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

		/* varchar		hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

                /* varchar         hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

                /* varchar         hv_customer_group[PD_CUSTOMER_GROUP_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_group;

		//varchar		hv_date[PD_DATE_LEN];

		/* varchar		v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


		short		ind_txn_id= -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	hv_merchant_id.len = strlen(csMerchantId);
	memcpy(hv_merchant_id.arr,csMerchantId,hv_merchant_id.len);
DEBUGLOG(("GetCustomerHistoryTxnList merchant_id = [%.*s]\n",hv_merchant_id.len,hv_merchant_id.arr));

	hv_txn_ccy.len = strlen(csTxnCcy);
	memcpy(hv_txn_ccy.arr,csTxnCcy,hv_txn_ccy.len);
DEBUGLOG(("GetCustomerHistoryTxnList txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));

	hv_txn_country.len = strlen(csCountry);
	memcpy(hv_txn_country.arr,csCountry,hv_txn_country.len);
DEBUGLOG(("GetCustomerHistoryTxnList txn_country = [%.*s]\n",hv_txn_country.len,hv_txn_country.arr));

	hv_service_code.len = strlen(csServiceCode);
	memcpy(hv_service_code.arr,csServiceCode,hv_service_code.len);
DEBUGLOG(("GetCustomerHistoryTxnList service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));

	hv_customer_tag.len = strlen(csCustomerTag);
	memcpy(hv_customer_tag.arr,csCustomerTag,hv_customer_tag.len);
DEBUGLOG(("GetCustomerHistoryTxnList customer_tag = [%.*s]\n",hv_customer_tag.len,hv_customer_tag.arr));

	hv_customer_group.len = strlen(csCustomerGroup);
	memcpy(hv_customer_group.arr,csCustomerGroup,hv_customer_group.len);
DEBUGLOG(("GetCustomerHistoryTxnList customer_group = [%.*s]\n",hv_customer_group.len,hv_customer_group.arr));
/*
	hv_date.len = strlen(csDate);
	memcpy(hv_date.arr,csDate,hv_date.len);
DEBUGLOG(("GetCustomerHistoryTxnList date = [%.*s]\n",hv_date.len,hv_date.arr));
*/
        /* EXEC SQL DECLARE c_cursor_getcusthis CURSOR FOR
		select  th_txn_id
		from 
			(select th_txn_id,
			 	th_host_posting_date,
				th_input_channel,
			 	th_transaction_amount
			from txn_header
			where th_merchant_id = :hv_merchant_id
			and th_service_code = :hv_service_code
			and th_txn_code = 'DSI'
			and th_ar_ind = 'A'),
			//and th_host_posting_date between TO_CHAR (TO_DATE (:hv_date,'YYYYMMDD') - 29,'YYYYMMDD') AND :hv_date),

			(select td_txn_id
		 	 from	txn_detail
			 where	td_customer_tag = :hv_customer_tag
			 and	td_customer_group = :hv_customer_group
			 and 	td_txn_ccy = :hv_txn_ccy
			 and	td_txn_country = :hv_txn_country
			)
		where th_txn_id = td_txn_id; */ 


        /* EXEC SQL OPEN c_cursor_getcusthis; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = sq0018;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1204;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_customer_tag;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)0;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_customer_group;
        sqlstm.sqhstl[3] = (unsigned long )12;
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)0;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[4] = (unsigned long )5;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)0;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_country;
        sqlstm.sqhstl[5] = (unsigned long )4;
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
        if (sqlca.sqlcode < 0) goto getcusthis_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcusthis
                INTO
			:v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1243;
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
                if (sqlca.sqlcode < 0) goto getcusthis_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_txn_id>= 0) {
                        v_txn_id.arr[v_txn_id.len] ='\0';
			sprintf(csTag,"txn_id_%d",iCnt);
                        PutField_CString(hTxn,csTag,(const char*)v_txn_id.arr);
DEBUGLOG(("GetCustomerHistoryTxnList txn_id = [%s]\n",v_txn_id.arr)); 
                }
		iCnt++;
		PutField_Int(hTxn,"txn_count",iCnt);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcusthis; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1262;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcusthis_error;
}




	if (iCnt > 0 ) {
DEBUGLOG(("GetCustomerHistoryTxnList Normal Exit\n")); 
        	return  PD_OK;
	}
	else {
DEBUGLOG(("GetCustomerHistoryTxnList Normal Exit, Not Found\n")); 
		return PD_ERR;
	}

getcusthis_error:
DEBUGLOG(("getcusthis_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcusthis; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1277;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int GetCustomerHistoryDetail(hash_t *hTxn,
		       recordset_t* myRec)
{
        hash_t *myHash;
	char	*csPtr;
	char	csTag[PD_TAG_LEN+1];
	int	iCnt = 0;
	int	iPtr = 0;
	int	i = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO getcusthisdt_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


		double		v_txn_amt;
		/* varchar		v_host_posting_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar		v_channel_code[PD_CHANNEL_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_channel_code;


		short		ind_txn_amt = -1;
		short		ind_host_posting_date = -1;
		short		ind_channel_code = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


	strcpy((char*)hv_dynstmt.arr,"select  th_host_posting_date,");
	strcat((char*)hv_dynstmt.arr,"th_input_channel,");
	strcat((char*)hv_dynstmt.arr,"sum(th_transaction_amount)");
	strcat((char*)hv_dynstmt.arr," from txn_header ");
	strcat((char*)hv_dynstmt.arr," where th_txn_id in (");
	if (GetField_Int(hTxn,"txn_count",&iPtr)) {
DEBUGLOG(("GetCustomerHistoryDetail = [%d]\n",iPtr));
        }
        for (i= 0 ; i < iPtr; i++) {
                sprintf(csTag,"txn_id_%d",i);
                if (GetField_CString(hTxn,csTag,&csPtr)) {
DEBUGLOG(("GetCustomerHistoryDetail [%s] = [%s]\n",csTag,csPtr));
                        if (i != 0 )
                                strcat((char*)hv_dynstmt.arr, ",");
                        strcat((char*)hv_dynstmt.arr, "'");
                        strcat((char*)hv_dynstmt.arr, csPtr);
                        strcat((char*)hv_dynstmt.arr, "'");
                }
        }
	strcat((char*)hv_dynstmt.arr,")");
	strcat((char*)hv_dynstmt.arr,"  group by th_host_posting_date,th_input_channel");
	strcat((char*)hv_dynstmt.arr," order by th_host_posting_date");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("GetCustomerHistoryDetail:[%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        /* EXEC SQL PREPARE s1 FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1292;
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
        if (sqlca.sqlcode < 0) goto getcusthisdt_error;
}


        /* EXEC SQL DECLARE c_cursor_getcusthisdt CURSOR FOR s1; */ 


        /* EXEC SQL OPEN c_cursor_getcusthisdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1311;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcusthisdt_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_getcusthisdt
                INTO
			:v_host_posting_date:ind_host_posting_date,
			:v_channel_code:ind_channel_code,
			:v_txn_amt:ind_txn_amt; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1326;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[0] = (unsigned long )11;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[1] = (unsigned long )6;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_channel_code;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_txn_amt;
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
                if (sqlca.sqlcode < 0) goto getcusthisdt_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		iCnt++;

                myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

                if (ind_host_posting_date >= 0) {
                        v_host_posting_date.arr[v_host_posting_date.len] ='\0';
                        PutField_CString(myHash,"host_posting_date",(const char*)v_host_posting_date.arr);
DEBUGLOG(("GetCustomerHistoryDetail host_posting_date = [%s]\n",v_host_posting_date.arr)); 
                }

                if (ind_channel_code >= 0) {
                        v_channel_code.arr[v_channel_code.len] ='\0';
                        PutField_CString(myHash,"channel_code",(const char*)v_channel_code.arr);
DEBUGLOG(("GetCustomerHistoryDetail channel_code = [%s]\n",v_channel_code.arr)); 
                }

                if (ind_txn_amt < 0) 
			v_txn_amt = 0.0;

                PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetCustomerHistoryDetail txn_amt = [%f]\n",v_txn_amt)); 

		RecordSet_Add(myRec,myHash);
	}
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_getcusthisdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1353;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto getcusthisdt_error;
}




	if (iCnt > 0 ) {
DEBUGLOG(("GetCustomerHistoryDetail Normal Exit\n")); 
        	return  PD_OK;
	}
	else {
DEBUGLOG(("GetCustomerHistoryDetail Normal Exit, Not Found\n")); 
		return PD_ERR;
	}

getcusthisdt_error:
DEBUGLOG(("getcusthisdt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getcusthisdt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1368;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int BatchUpdateCustomerGroup(hash_t *hTxn)
{
	char	*csPtr;
	char	*csCustomerGroup;
	char	csTag[PD_TAG_LEN+1];
	int	iPtr = 0;
	int	i = 0;

        /* EXEC SQL WHENEVER SQLERROR GOTO updcustgrp_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar         hv_dynstmt[PD_MAX_BUFFER]; */ 
struct { unsigned short len; unsigned char arr[16392]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


	if(GetField_CString(hTxn,"customer_group",&csCustomerGroup)){
DEBUGLOG(("BatchUpdateCustomerGroup customer_group = [%s]\n",csCustomerGroup));

		strcpy((char*)hv_dynstmt.arr,"update txn_detail");
		strcat((char*)hv_dynstmt.arr," set td_customer_group = '");
		strcat((char*)hv_dynstmt.arr, csCustomerGroup);
		strcat((char*)hv_dynstmt.arr,"'");
		strcat((char*)hv_dynstmt.arr," where td_txn_id in (");
		if (GetField_Int(hTxn,"txn_count",&iPtr)) {
DEBUGLOG(("BatchUpdateCustomerGroup = [%d]\n",iPtr));
        	}
        	for (i= 0 ; i < iPtr; i++) {
        	        sprintf(csTag,"txn_id_%d",i);
        	        if (GetField_CString(hTxn,csTag,&csPtr)) {
DEBUGLOG(("BatchUpdateCustomerGroup [%s] = [%s]\n",csTag,csPtr));
        	                if (i != 0 )
        	                        strcat((char*)hv_dynstmt.arr, ",");
        	                strcat((char*)hv_dynstmt.arr, "'");
        	                strcat((char*)hv_dynstmt.arr, csPtr);
       	                	strcat((char*)hv_dynstmt.arr, "'");
       	        	}
       		}
		strcat((char*)hv_dynstmt.arr,")");
		hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("BatchUpdateCustomerGroup:[%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));
        	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
         struct sqlexd sqlstm;
         sqlstm.sqlvsn = 12;
         sqlstm.arrsiz = 40;
         sqlstm.sqladtp = &sqladt;
         sqlstm.sqltdsp = &sqltds;
         sqlstm.stmt = "";
         sqlstm.iters = (unsigned int  )1;
         sqlstm.offset = (unsigned int  )1383;
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
         if (sqlca.sqlcode < 0) goto updcustgrp_error;
}


		/* EXEC SQL EXECUTE PS; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 40;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = "";
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )1402;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto updcustgrp_error;
}



	}
DEBUGLOG(("BatchUpdateCustomerGroup Normal Exit\n")); 
	return PD_OK;

updcustgrp_error:
DEBUGLOG(("updcustgrp_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int MatchTxnStatusforUpdate(const char* csTxnSeq,
                     const char cStatus)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO MatchTxnStatusforUpdate_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                //short           hv_return_value;
                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                char            hv_status;

		char		v_status;
		char		v_sub_status[PD_SUB_STATUS_LEN + 1];

                short           ind_status = -1;
		short		ind_sub_status = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MatchTxnStatusforUpdate txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_status = cStatus;
DEBUGLOG(("MatchTxnStatusforUpdate status = [%c]\n",hv_status));

        /* EXEC SQL SELECT th_status, th_sub_status
                INTO    :v_status:ind_status,
			:v_sub_status:ind_sub_status
                FROM    txn_header
                WHERE   th_txn_id = :hv_txn_id
                and     th_status = :hv_status
                for update; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select th_status , th_sub_status INTO :b0:b1 , :b2:b\
3 FROM txn_header WHERE th_txn_id = :b4 and th_status = :b5 for update ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1417;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_status;
        sqlstm.sqhstl[0] = (unsigned long )1;
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_status;
        sqlstm.sqinds[0] = (         int  )0;
        sqlstm.sqharm[0] = (unsigned long )0;
        sqlstm.sqadto[0] = (unsigned short )0;
        sqlstm.sqtdso[0] = (unsigned short )0;
        sqlstm.sqhstv[1] = (unsigned char  *)v_sub_status;
        sqlstm.sqhstl[1] = (unsigned long )4;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)&ind_sub_status;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_txn_id;
        sqlstm.sqhstl[2] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto MatchTxnStatusforUpdate_error;
}




        if(ind_status >= 0){
DEBUGLOG(("MatchTxnStatusforUpdate Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchTxnStatusforUpdate Not Found\n"));
                return PD_NOT_FOUND;
        }


MatchTxnStatusforUpdate_error:
DEBUGLOG(("MatchTxnStatusforUpdate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int AddMiTxnLog(const char* csTxnId)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO add_mitxnlogerror; */ 

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


DEBUGLOG(("AddMiTxnLog: Begin\n"));

// txn_id
	hv_txn_id.len = strlen(csTxnId);
        memcpy(hv_txn_id.arr,csTxnId,hv_txn_id.len);
	ind_txn_id = 0;
DEBUGLOG(("AddMiTxnLog txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

// user
	hv_create_user.len = strlen("SYSTEM");
        strncpy((char*)hv_create_user.arr,"SYSTEM", hv_create_user.len);
        ind_create_user = 0;
DEBUGLOG(("AddMiTxnLog user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));

	/* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mi_txn_log_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_create_user:ind_create_user);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mi_txn_log_insert ( :hv_txn_id\
:ind_txn_id , :hv_create_user:ind_create_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1448;
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
 if (sqlca.sqlcode < 0) goto add_mitxnlogerror;
}



DEBUGLOG(("AddMiTxnLog:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK)
        {
DEBUGLOG(("AddMiTxnLog:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("Transaction:AddMiTxnLog: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("AddMiTxnLog: SP_OTHER_ERR TxnAbort\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("Transaction:AddMiTxnLog: SP_ERR TxnAbort\n");
DEBUGLOG(("AddMiTxnLog: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }


add_mitxnlogerror:
DEBUGLOG(("add_mitxnlogerror code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("Transaction_add_mitxnlogerror: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
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

        /* EXEC SQL select th_txn_id
                into :v_txn_id:ind_txn_id
                from txn_header
                where th_txn_id = :hv_txn_id
                for update nowait; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select th_txn_id into :b0:b1 from txn_header where t\
h_txn_id = :b2 for update nowait ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1475;
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
			:hv_return_value := sp_txn_detail_upd_remark(
								:hv_txn_id:ind_txn_id,
								:hv_remark:ind_remark,
								:hv_update_user:ind_update_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_txn_detail_upd_remark ( :hv_tx\
n_id:ind_txn_id , :hv_remark:ind_remark , :hv_update_user:ind_update_user ) ;\
 END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1498;
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



int IsCreateTimeWithinRange(const char* csTxnSeq, const int iRange)
{
	int iRet = PD_FALSE;
        /* EXEC SQL WHENEVER SQLERROR GOTO IsCreateTimeWithinRange_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

                int		hv_range;

		int		v_cnt;

                short           ind_cnt = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("IsCreateTimeWithinRange txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        hv_range = iRange;
DEBUGLOG(("IsCreateTimeWithinRange Range (minutes) = [%d]\n",hv_range));

        /* EXEC SQL SELECT  count(1)
                INTO	:v_cnt:ind_cnt
                FROM    txn_header
                WHERE   th_txn_id = :hv_txn_id
                and     th_create_timestamp >= sysdate - :hv_range/1440; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_header WHERE\
 th_txn_id = :b2 and th_create_timestamp >= sysdate - :b3 / 1440 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1529;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&v_cnt;
        sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
        sqlstm.sqhsts[0] = (         int  )0;
        sqlstm.sqindv[0] = (         short *)&ind_cnt;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_range;
        sqlstm.sqhstl[2] = (unsigned long )sizeof(int);
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
        if (sqlca.sqlcode < 0) goto IsCreateTimeWithinRange_error;
}




        if(ind_cnt<0){
		v_cnt = 0;
	}

	if(v_cnt > 0){
		iRet = PD_TRUE;
DEBUGLOG(("IsCreateTimeWithinRange = TRUE\n"));
	}
	else{
DEBUGLOG(("IsCreateTimeWithinRange = FALSE\n"));
	}

	return iRet;

IsCreateTimeWithinRange_error:
DEBUGLOG(("IsCreateTimeWithinRange_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}

int MerchBalNullInTxnDtByAprvDate(const char* csAprvDate, recordset_t* myRec)
{
	int iCnt = 0;

	hash_t *myHash;

        /* EXEC SQL WHENEVER SQLERROR GOTO getmerchbalnull_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_aprv_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_aprv_date;


		/* varchar         v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;


                short           ind_txn_id = -1;
        /* EXEC SQL END DECLARE SECTION; */ 


/* date */
       	hv_aprv_date.len = strlen(csAprvDate);
     	memcpy(hv_aprv_date.arr, csAprvDate, hv_aprv_date.len);
DEBUGLOG(("MerchBalNullInTxnDtByAprvDate: aprv_date = [%.*s]\n", hv_aprv_date.len, hv_aprv_date.arr));

	/* EXEC SQL DECLARE c_cursor_getmerchbalnull CURSOR FOR
		select 	th_txn_id
		from	txn_header,
			txn_detail
		where	th_txn_id = td_txn_id
		and	th_approval_date is not null
		and	th_approval_date = :hv_aprv_date
		and	th_txn_code = 'DSI'
		and	th_status = 'C'
		and	th_ar_ind = 'A'
		and     (td_open_bal is null
                	or      td_current_bal is null
                	or      td_total_float is null
                	or      td_total_reserved_amount is null
                	or      td_total_hold is null
                	or      td_fundin_payout is null
                	or      td_reserved_payout is null
                	or      td_total_float_after_payout is null
                	or      td_open_bal_settlement is null
                	or      td_current_bal_settlement is null
                	or 	td_total_float_settlement is null
                	or	td_total_hold_settlement is null)
		order by th_approval_timestamp,
		 	 th_txn_id; */ 

	/* EXEC SQL OPEN c_cursor_getmerchbalnull; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0025;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1556;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_aprv_date;
 sqlstm.sqhstl[0] = (unsigned long )10;
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
 if (sqlca.sqlcode < 0) goto getmerchbalnull_error;
}



	do {
                /* EXEC SQL FETCH c_cursor_getmerchbalnull
                INTO
                        :v_txn_id:ind_txn_id; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 40;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )1575;
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
                if (sqlca.sqlcode < 0) goto getmerchbalnull_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

		myHash = (hash_t*) malloc (sizeof(hash_t));
                hash_init(myHash,0);

DEBUGLOG(("MerchBalNullInTxnDtByAprvDate: found record\n"));

/* txn_seq */
                if (ind_txn_id >= 0) {
			v_txn_id.arr[v_txn_id.len] ='\0';
                        PutField_CString(myHash,"txn_seq",(const char*)v_txn_id.arr);
DEBUGLOG(("MerchBalNullInTxnDtByAprvDate: txn_seq = [%s]\n",v_txn_id.arr));
                }

		iCnt++;		

		RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

	/* EXEC SQL CLOSE c_cursor_getmerchbalnull; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 40;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )1594;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto getmerchbalnull_error;
}



	if (iCnt > 0) {
DEBUGLOG(("MerchBalNullInTxnDtByAprvDate: Found\n"));
                return FOUND;
        } else {
DEBUGLOG(("MerchBalNullInTxnDtByAprvDate: Not Found\n"));
                return NOT_FOUND;
        }

getmerchbalnull_error:
DEBUGLOG(("getmerchbalnull_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
ERRLOG("Transaction_MerchBalNullInTxnDtByAprvDate: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        /* EXEC SQL CLOSE c_cursor_getmerchbalnull; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1609;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}

int MerchBalInTxnDetail(const char* csTxnSeq)
{
	int iRet = PD_FALSE;

        /* EXEC SQL WHENEVER SQLERROR GOTO MerchBalInTxnDetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


		int             v_no_of_record;
		short           ind_no_of_record = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnSeq);
        memcpy(hv_txn_id.arr,csTxnSeq,hv_txn_id.len);
DEBUGLOG(("MerchBalInTxnDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL SELECT count(1)
                INTO    :v_no_of_record:ind_no_of_record
                FROM   	txn_detail
                WHERE   td_txn_id = :hv_txn_id
		AND 	td_open_bal IS NOT NULL
		AND	td_current_bal IS NOT NULL
		AND	td_total_float IS NOT NULL
		AND 	td_total_reserved_amount IS NOT NULL
		AND	td_total_hold IS NOT NULL
		AND 	td_fundin_payout IS NOT NULL
		AND 	td_reserved_payout IS NOT NULL
		AND	td_total_float_after_payout IS NOT NULL
		AND	td_open_bal_settlement IS NOT NULL
		AND	td_current_bal_settlement IS NOT NULL
		AND	td_total_float_settlement IS NOT NULL
		AND 	td_total_hold_settlement IS NOT NULL
                ; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM txn_detail WHERE\
 td_txn_id = :b2 AND td_open_bal IS NOT NULL AND td_current_bal IS NOT NULL A\
ND td_total_float IS NOT NULL AND td_total_reserved_amount IS NOT NULL AND td\
_total_hold IS NOT NULL AND td_fundin_payout IS NOT NULL AND td_reserved_payo\
ut IS NOT NULL AND td_total_float_after_payout IS NOT NULL AND td_open_bal_se\
ttlement IS NOT NULL AND td_current_bal_settlement IS NOT NULL AND td_total_f\
loat_settlement IS NOT NULL AND td_total_hold_settlement IS NOT NULL ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )1624;
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
        if (sqlca.sqlcode < 0) goto MerchBalInTxnDetail_error;
}




        if(ind_no_of_record >= 0){
		if(v_no_of_record > 0){
			iRet = PD_TRUE;
		}
        }

	if(iRet == PD_TRUE){
DEBUGLOG((" merchant balance information exists in txn_detail\n"));
	}
	else{
DEBUGLOG((" merchant balance information NOT exists in txn_detail\n"));
	}

DEBUGLOG(("MerchBalInTxnDetail iRet = [%d]\n", iRet));
	return iRet;

MerchBalInTxnDetail_error:
DEBUGLOG(("MerchBalInTxnDetail_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
