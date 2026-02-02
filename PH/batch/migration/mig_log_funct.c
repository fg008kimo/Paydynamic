
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
    "mig_log_funct.pc"
};


static unsigned int sqlctx = 5006187;


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

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1078,0,6,351,0,0,30,30,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,1,0,0,1,
1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
140,0,0,2,0,0,17,810,0,0,1,1,0,1,0,1,9,0,0,
159,0,0,2,0,0,21,811,0,0,0,0,0,1,0,
174,0,0,3,198,0,6,908,0,0,6,6,0,1,0,2,3,0,0,1,9,0,0,1,1,0,0,1,1,0,0,1,9,0,0,1,
9,0,0,
213,0,0,4,1322,0,6,1356,0,0,40,40,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,
0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
388,0,0,2,0,0,17,1678,0,0,1,1,0,1,0,1,9,0,0,
407,0,0,2,0,0,21,1679,0,0,0,0,0,1,0,
422,0,0,5,684,0,6,1929,0,0,22,22,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,9,0,0,
525,0,0,2,0,0,17,2394,0,0,1,1,0,1,0,1,9,0,0,
544,0,0,2,0,0,21,2395,0,0,0,0,0,1,0,
559,0,0,6,176,0,6,2472,0,0,5,5,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/03/15              Virginia Yun

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "internal.h"
#include "utilitys.h"
#include "dbutility.h"
#include "../batchcommon.h"
#include "mig_funct.h"
#include "mig_bo_funct.h"
#include "mig_log_funct.h"
#include "ObjPtr.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

OBJPTR(DB);

int ml_Txn_Header_Add(const hash_t *hRls)
{
        char            *csTmp;
        char            cTmp;
        int             iCommit = PD_TRUE;
        int             iTmp;
        double          dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_org_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_org_txn_id;

        /* varchar         hv_channel_code[PD_CHANNEL_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_channel_code;

        char            hv_status;
        char            hv_ar_ind;
        /* varchar         hv_sub_status[PD_SUB_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_sub_status;

        /* varchar         hv_txn_code[PD_TXN_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_code;

        /* varchar         hv_process_type[PD_PROCESS_TYPE_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_process_type;

        /* varchar         hv_process_code[PD_PROCESS_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_process_code;

        /* varchar         hv_merchant_id[PD_MERCHANT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_merchant_id;

        /* varchar         hv_merchant_ref[PD_MERCHANT_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_merchant_ref;

        /* varchar         hv_client_id[PD_CLIENT_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_client_id;

        /* varchar         hv_host_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_posting_date;

        /* varchar         hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

        int             hv_internal_code;
        /* varchar         hv_response_code[PD_RESPONSE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_response_code;

        double          hv_transaction_amt;
        double          hv_net_amt;
        /* varchar         hv_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_net_ccy;

        /* varchar         hv_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_tm_date;

        /* varchar         hv_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_tm_time;

        /* varchar         hv_local_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_local_tm_date;

        /* varchar         hv_local_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_local_tm_time;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

        /* varchar         hv_client_ip[PD_IP_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_client_ip;

        /* varchar         hv_service_code[PD_SERVICE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_service_code;

        /* varchar         hv_approval_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_approval_date;


	/* varchar		hv_create_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_create_datetime;

	/* varchar		hv_update_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_update_datetime;



        short           ind_txn_id = -1;
        short           ind_org_txn_id = -1;
        short           ind_channel_code = -1;
        short           ind_status = -1;
        short           ind_ar_ind = -1;
        short           ind_sub_status = -1;
        short           ind_txn_code = -1;
        short           ind_process_type = -1;
        short           ind_process_code = -1;
        short           ind_merchant_id = -1;
        short           ind_merchant_ref = -1;
        short           ind_client_id = -1;
        short           ind_host_posting_date = -1;
        short           ind_transmission_datetime = -1;
        short           ind_internal_code = -1;
        short           ind_response_code = -1;
        short           ind_transaction_amt = -1;
        short           ind_net_amt = -1;
        short           ind_net_ccy = -1;
        short           ind_tm_date = -1;
        short           ind_tm_time = -1;
        short           ind_local_tm_date = -1;
        short           ind_local_tm_time = -1;
        short           ind_add_user = -1;
        short           ind_client_ip= -1;
        short           ind_service_code = -1;
        short           ind_approval_date = -1;

	short		ind_create_datetime = -1;
	short		ind_update_datetime = -1;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if (GetField_Int(hRls,"db_commit",&iCommit)) {
//DEBUGLOG(("Add:db_commit = [%d]\n",iCommit));
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
//DEBUGLOG(("Add:channel_code = [%.*s]\n",hv_channel_code.len,hv_channel_code.arr));
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
//DEBUGLOG(("Add:process_type = [%.*s]\n",hv_process_type.len,hv_process_type.arr));
        }

/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
                hv_process_code.len = strlen(csTmp);
                memcpy(hv_process_code.arr,csTmp,hv_process_code.len);
                ind_process_code = 0;
//DEBUGLOG(("Add:process_code = [%.*s]\n",hv_process_code.len,hv_process_code.arr));
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
//DEBUGLOG(("Add:settlement_date = [%d]\n",hv_internal_code));
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
                hv_response_code.len = strlen(csTmp);
                memcpy(hv_response_code.arr,csTmp,hv_response_code.len);
                ind_response_code = 0;
//DEBUGLOG(("Add:response_code = [%.*s]\n",hv_response_code.len,hv_response_code.arr));
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
//DEBUGLOG(("Add:tm_date = [%.*s]\n",hv_tm_date.len,hv_tm_date.arr));
        }

/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
                hv_tm_time.len = strlen(csTmp);
                memcpy(hv_tm_time.arr,csTmp,hv_tm_time.len);
                ind_tm_time = 0;
//DEBUGLOG(("Add:tm_time = [%.*s]\n",hv_tm_time.len,hv_tm_time.arr));
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
                hv_local_tm_date.len = strlen(csTmp);
                memcpy(hv_local_tm_date.arr,csTmp,hv_local_tm_date.len);
                ind_local_tm_date = 0;
//DEBUGLOG(("Add:local_tm_date = [%.*s]\n",hv_local_tm_date.len,hv_local_tm_date.arr));
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
                hv_local_tm_time.len = strlen(csTmp);
                memcpy(hv_local_tm_time.arr,csTmp,hv_local_tm_time.len);
                ind_local_tm_time = 0;
//DEBUGLOG(("Add:local_tm_time = [%.*s]\n",hv_local_tm_time.len,hv_local_tm_time.arr));
        }


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
//DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }


/* client ip */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
                hv_client_ip.len = strlen(csTmp);
                memcpy(hv_client_ip.arr,csTmp,hv_client_ip.len);
                ind_client_ip = 0;
//DEBUGLOG(("Add:client_ip = [%.*s]\n",hv_client_ip.len,hv_client_ip.arr));
        }

/* service_code */
        if (GetField_CString(hRls,"service_code",&csTmp)) {
                hv_service_code.len = strlen(csTmp);
                memcpy(hv_service_code.arr,csTmp,hv_service_code.len);
                ind_service_code = 0;
//DEBUGLOG(("Add:service_code = [%.*s]\n",hv_service_code.len,hv_service_code.arr));
        }

/* approval_date */
        if (GetField_CString(hRls,"approval_date",&csTmp)) {
                hv_approval_date.len = strlen(csTmp);
                memcpy(hv_approval_date.arr,csTmp,hv_approval_date.len);
                ind_approval_date = 0;
DEBUGLOG(("Add:approval_date = [%.*s]\n",hv_approval_date.len,hv_approval_date.arr));
        }


/* create_datetime for mig*/
        if (GetField_CString(hRls,"create_datetime",&csTmp)) {
                hv_create_datetime.len = strlen(csTmp);
                memcpy(hv_create_datetime.arr,csTmp,hv_create_datetime.len);
                ind_create_datetime = 0;
DEBUGLOG(("Add:create_datetime = [%.*s]\n",hv_create_datetime.len,hv_create_datetime.arr));
        }

/* update_datetime for mig*/
        if (GetField_CString(hRls,"update_datetime",&csTmp)) {
                hv_update_datetime.len = strlen(csTmp);
                memcpy(hv_update_datetime.arr,csTmp,hv_update_datetime.len);
                ind_update_datetime = 0;
DEBUGLOG(("Add:update_datetime = [%.*s]\n",hv_update_datetime.len,hv_update_datetime.arr));
        }

	// amend for sp_par_mig_txn_header_insert!!!

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_par_mig_txn_header_insert(
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
                                        :hv_approval_date:ind_approval_date,
					:hv_create_datetime:ind_create_datetime, 
                                        :hv_update_datetime:ind_update_datetime);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 30;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "begin :hv_return_value := sp_par_mig_txn_header_insert ( :hv_txn_\
id:ind_txn_id , :hv_org_txn_id:ind_org_txn_id , :hv_channel_code:ind_channel\
_code , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_sub_status:ind_s\
ub_status , :hv_txn_code:ind_txn_code , :hv_process_type:ind_process_type , \
:hv_process_code:ind_process_code , :hv_merchant_id:ind_merchant_id , :hv_me\
rchant_ref:ind_merchant_ref , :hv_client_id:ind_client_id , :hv_host_posting\
_date:ind_host_posting_date , :hv_transmission_datetime:ind_transmission_dat\
etime , :hv_internal_code:ind_internal_code , :hv_response_code:ind_response\
_code , :hv_transaction_amt:ind_transaction_amt , :hv_net_amt:ind_net_amt , \
:hv_net_ccy:ind_net_ccy , :hv_tm_date:ind_tm_date , :hv_tm_time:ind_tm_time \
, :hv_local_tm_date:ind_local_tm_date , :hv_local_tm_time:ind_local_tm_time \
, :hv_add_user:ind_add_user , :hv_add_user:ind_add_user , :hv_client_ip:ind_\
client_ip , :hv_service_code:ind_service_code , :hv_approval_date:ind_approv\
al_date , :hv_create_datetime:ind_create_dateti");
        sqlstm.stmt = "me , :hv_update_datetime:ind_update_datetime ) ; END\
 ;";
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
        sqlstm.sqhstv[28] = (unsigned char  *)&hv_create_datetime;
        sqlstm.sqhstl[28] = (unsigned long )17;
        sqlstm.sqhsts[28] = (         int  )0;
        sqlstm.sqindv[28] = (         short *)&ind_create_datetime;
        sqlstm.sqinds[28] = (         int  )0;
        sqlstm.sqharm[28] = (unsigned long )0;
        sqlstm.sqadto[28] = (unsigned short )0;
        sqlstm.sqtdso[28] = (unsigned short )0;
        sqlstm.sqhstv[29] = (unsigned char  *)&hv_update_datetime;
        sqlstm.sqhstl[29] = (unsigned long )17;
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         short *)&ind_update_datetime;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned long )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
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
        ml_Header_AddTxnStatusLog(hRls);

// update txn browser info
	//ml_Header_AddTxnBrowserInfo(hRls);

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

int ml_Txn_Header_Update(const hash_t *hRls)
{
        char*   csTmp;
        char    cTmp;
        double  dTmp;
        int     iTmp;
        char*   csBuf;
        char*   csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
	////////// not user sysdate //////////
        //strcpy((char*)hv_dynstmt.arr,"update txn_header set th_update_timestamp  = sysdate");
        strcpy((char*)hv_dynstmt.arr,"update txn_header set "); 
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* update_datetime */
	GetField_CString(hRls, "update_datetime", &csTmp);
DEBUGLOG(("Update:update_datetime = [%s]\n",csTmp));
	strcat((char*)hv_dynstmt.arr, "th_update_timestamp = to_date('");
	strcat((char*)hv_dynstmt.arr, csTmp);
	strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS')");
	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	

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
//DEBUGLOG(("Update:channel_code = [%s]\n",csTmp));
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
//DEBUGLOG(("Update:txn_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_txn_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
//DEBUGLOG(("Update:process_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_process_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
//DEBUGLOG(("Update:process_code = [%s]\n",csTmp));
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
//DEBUGLOG(("Update:internal_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",th_internal_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
//DEBUGLOG(("Update:response_code = [%s]\n",csTmp));
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
//DEBUGLOG(("Update:tm_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_tm_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* tm time */
        if (GetField_CString(hRls,"tm_time",&csTmp)) {
//DEBUGLOG(("Update:tm_time = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_tm_time = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
//DEBUGLOG(("Update:local_tm_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_local_tm_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
//DEBUGLOG(("Update:local_tm_time = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_local_tm_time = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* ip_addr */
        if (GetField_CString(hRls,"ip_addr",&csTmp)) {
//DEBUGLOG(("Update:ip_addr = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_client_ip = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
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
/* approval timestamp */
//////////////// remark for mig ///////////////////
                //strcat((char*)hv_dynstmt.arr, ",th_approval_timestamp = systimestamp");
                //hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

	if (GetField_CString(hRls, "approval_timestamp", &csTmp)) {
DEBUGLOG(("Update:approval_timestamp = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_approval_timestamp = to_timestamp('");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "', 'YYYYMMDDHH24MISS.FF6')");
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
//DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_create_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
//DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
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
DEBUGLOG(("Update:net_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",th_inter_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
        strcat((char *)hv_dynstmt.arr, " WHERE th_txn_id = '");
        strcat((char *)hv_dynstmt.arr, csTxnId);
        strcat((char *)hv_dynstmt.arr, "'");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("SQL = [%.*s]\n",hv_dynstmt.len,hv_dynstmt.arr));

        /* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 30;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )140;
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
        sqlstm.arrsiz = 30;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )159;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto update_error;
}



        FREE_ME(csBuf);

// update txn sub status
        ml_Header_AddTxnStatusLog(hRls);

// update txn browser ino
	//ml_Header_AddTxnBrowserInfo(hRls);

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

int ml_Header_AddTxnStatusLog(const hash_t *hCon)
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
//DEBUGLOG(("AddTxnStatusLog:create_user = [%.*s]\n",hv_create_user.len,hv_create_user.arr));


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
        sqlstm.arrsiz = 30;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_status_log_insert (\
 :hv_txn_id:ind_txn_id , :hv_status:ind_status , :hv_ar_ind:ind_ar_ind , :hv_\
sub_status:ind_sub_status , :hv_create_user:ind_create_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )174;
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
ERRLOG("TxnCode_add_txnstatuslogerror: SP_INTERNAL_ERR TxnAbort\n");
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_INTERNAL_ERR;
}

int ml_Txn_Detail_AddDetail(const hash_t *hRls)
{
        char            *csTmp;
        char            cTmp;
        int             iTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO adddetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

        /* varchar         hv_txn_country[PD_COUNTRY_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_txn_country;

        /* varchar         hv_pay_method[PD_PAY_METHOD_LIST_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_pay_method;

        /* varchar         hv_bank_code[PD_AC_BANK_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_bank_code;

        /* varchar         hv_bank_name[PD_AC_BANK_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bank_name;

        /* varchar         hv_branch_name[PD_AC_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_branch_name;

        /* varchar         hv_account_id[PD_AC_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_account_id;

        /* varchar         hv_account_name[PD_AC_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_account_name;

        /* varchar         hv_identity_id[PD_IDENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_identity_id;

        /* varchar         hv_province[PD_PROVINCE_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_province;

        /* varchar         hv_phone_no[PD_PHONE_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_phone_no;

        /* varchar         hv_city[PD_CITY_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_city;

        /* varchar         hv_batch_id[PD_BATCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_batch_id;

        char            hv_show_paypage;
        /* varchar         hv_language[PD_LANGUAGE_LEN]; */ 
struct { unsigned short len; unsigned char arr[2]; } hv_language;

        /* varchar         hv_success_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_success_url;

        /* varchar         hv_failure_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_failure_url;

        /* varchar         hv_success_ck_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_success_ck_url;

        /* varchar         hv_failure_ck_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_failure_ck_url;

        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

        /* varchar         hv_update_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_update_user;

        /* varchar         hv_encrypt_type[PD_ENCRYPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_encrypt_type;

        int             hv_version_no;
        /* varchar         hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

        /* varchar         hv_selected_pay_method[PD_SELECTED_PAY_METHOD_LEN]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_selected_pay_method;

        /* varchar         hv_customer_tag[PD_CUSTOMER_TAG_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_customer_tag;

        /* varchar         hv_banner_logo[PD_BANNER_LOGO_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_banner_logo;

        /* varchar         hv_echo_msg_1[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_echo_msg_1;

        /* varchar         hv_echo_msg_2[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_echo_msg_2;

        /* varchar         hv_echo_msg_3[PD_ECHO_MSG_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_echo_msg_3;

        /* varchar         hv_opt_1[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_1;

        /* varchar         hv_opt_2[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_2;

        /* varchar         hv_opt_3[PD_OPT_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_opt_3;

        /* varchar         hv_customer_name[PD_CUSTOMER_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_name;

        /* varchar         hv_customer_family_name[PD_CUSTOMER_FAMILY_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_family_name;

        /* varchar         hv_customer_tel[PD_CUSTOMER_TEL_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_customer_tel;

        /* varchar         hv_customer_email[PD_CUSTOMER_EMAIL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_customer_email;

	/* varchar		hv_selected_pid[PD_PID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_selected_pid;


        short           ind_txn_id = -1;
        short           ind_txn_ccy = -1;
        short           ind_txn_country = -1;
        short           ind_pay_method = -1;
        short           ind_bank_code = -1;
        short           ind_bank_name = -1;
        short           ind_branch_name = -1;
        short           ind_account_id = -1;
        short           ind_account_name = -1;
        short           ind_identity_id = -1;
        short           ind_province = -1;
        short           ind_phone_no = -1;
        short           ind_city = -1;
        short           ind_batch_id = -1;
        short           ind_show_paypage = -1;
        short           ind_language = -1;
        short           ind_success_url = -1;
        short           ind_failure_url = -1;
        short           ind_success_ck_url = -1;
        short           ind_failure_ck_url = -1;
        short           ind_add_user = -1;
        short           ind_update_user = -1;
        short           ind_encrypt_type= -1;
        short           ind_version_no = -1;
        short           ind_remark = -1;
        short           ind_selected_pay_method = -1;
        short           ind_customer_tag= -1;
        short           ind_banner_logo= -1;
        short           ind_echo_msg_1= -1;
        short           ind_echo_msg_2= -1;
        short           ind_echo_msg_3= -1;
        short           ind_opt_1= -1;
        short           ind_opt_2= -1;
        short           ind_opt_3= -1;
        short           ind_customer_name = -1;
        short           ind_customer_family_name = -1;
        short           ind_customer_tel = -1;
        short           ind_customer_email = -1;
	short		ind_selected_pid = -1;

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
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlbuft((void **)0,
          "begin :hv_return_value := sp_txn_detail_insert ( :hv_txn_id:ind_t\
xn_id , :hv_txn_ccy:ind_txn_ccy , :hv_txn_country:ind_txn_country , :hv_pay_\
method:ind_pay_method , :hv_bank_code:ind_bank_code , :hv_bank_name:ind_bank\
_name , :hv_branch_name:ind_branch_name , :hv_account_id:ind_account_id , :h\
v_account_name:ind_account_name , :hv_identity_id:ind_identity_id , :hv_prov\
ince:ind_province , :hv_phone_no:ind_phone_no , :hv_city:ind_city , :hv_batc\
h_id:ind_batch_id , :hv_show_paypage:ind_show_paypage , :hv_language:ind_lan\
guage , :hv_success_url:ind_success_url , :hv_failure_url:ind_failure_url , \
:hv_success_ck_url:ind_success_ck_url , :hv_failure_ck_url:ind_failure_ck_ur\
l , :hv_add_user:ind_add_user , :hv_update_user:ind_update_user , :hv_encryp\
t_type:ind_encrypt_type , :hv_version_no:ind_version_no , :hv_remark:ind_rem\
ark , :hv_selected_pay_method:ind_selected_pay_method , :hv_banner_logo:ind_\
banner_logo , :hv_customer_tag:ind_customer_tag , :hv_echo_msg_1:ind_echo_ms\
g_1 , :hv_echo_msg_2:ind_echo_msg_2 , :hv_echo_");
        sqlstm.stmt = "msg_3:ind_echo_msg_3 , :hv_opt_1:ind_opt_1 , :hv_opt\
_2:ind_opt_2 , :hv_opt_3:ind_opt_3 , :hv_customer_name:ind_customer_name , :h\
v_customer_family_name:ind_customer_family_name , :hv_customer_tel:ind_custom\
er_tel , :hv_customer_email:ind_customer_email , :hv_selected_pid:ind_selecte\
d_pid ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )213;
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
        sqlstm.sqhstl[6] = (unsigned long )52;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_bank_name;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_branch_name;
        sqlstm.sqhstl[7] = (unsigned long )52;
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
        sqlstm.sqhstl[11] = (unsigned long )52;
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
        sqlstm.sqhstl[17] = (unsigned long )102;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_success_url;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_failure_url;
        sqlstm.sqhstl[18] = (unsigned long )102;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_failure_url;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_success_ck_url;
        sqlstm.sqhstl[19] = (unsigned long )102;
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_success_ck_url;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_failure_ck_url;
        sqlstm.sqhstl[20] = (unsigned long )102;
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
        sqlstm.sqhstl[29] = (unsigned long )52;
        sqlstm.sqhsts[29] = (         int  )0;
        sqlstm.sqindv[29] = (         short *)&ind_echo_msg_1;
        sqlstm.sqinds[29] = (         int  )0;
        sqlstm.sqharm[29] = (unsigned long )0;
        sqlstm.sqadto[29] = (unsigned short )0;
        sqlstm.sqtdso[29] = (unsigned short )0;
        sqlstm.sqhstv[30] = (unsigned char  *)&hv_echo_msg_2;
        sqlstm.sqhstl[30] = (unsigned long )52;
        sqlstm.sqhsts[30] = (         int  )0;
        sqlstm.sqindv[30] = (         short *)&ind_echo_msg_2;
        sqlstm.sqinds[30] = (         int  )0;
        sqlstm.sqharm[30] = (unsigned long )0;
        sqlstm.sqadto[30] = (unsigned short )0;
        sqlstm.sqtdso[30] = (unsigned short )0;
        sqlstm.sqhstv[31] = (unsigned char  *)&hv_echo_msg_3;
        sqlstm.sqhstl[31] = (unsigned long )52;
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

int ml_Txn_Detail_UpdateDetail(const hash_t *hRls)
{
        double  dTmp;
        char*   csPtr;
        char*   csBuf;
        char*   csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
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
//DEBUGLOG(("UpdateDetail:current_bal= [%f]\n",dTmp));
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
//DEBUGLOG(("UpdateDetail:total_float= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",td_total_float = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float_settlement*/
        if (GetField_Double(hRls,"total_float_settlement",&dTmp)) {
//DEBUGLOG(("UpdateDetail:total_float_settlement= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",td_total_float_settlement = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float_after_payout*/
        if (GetField_Double(hRls,"total_float_after_payout",&dTmp)) {
//DEBUGLOG(("UpdateDetail:total_float_after_payout= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",td_total_float_after_payout = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* total_reserved_amount*/
        if (GetField_Double(hRls,"total_reserved_amount",&dTmp)) {
//DEBUGLOG(("UpdateDetail:total_reserved_amount= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",td_total_reserved_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_hold*/
        if (GetField_Double(hRls,"total_hold",&dTmp)) {
//DEBUGLOG(("UpdateDetail:total_hold= [%f]\n",dTmp));
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
//DEBUGLOG(("UpdateDetail:fundin_payout= [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",td_fundin_payout = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/*reserved_payout*/
        if (GetField_Double(hRls,"reserved_payout",&dTmp)) {
//DEBUGLOG(("UpdateDetail:reserved_payout= [%f]\n",dTmp));
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
                strcat((char*)hv_dynstmt.arr, ",td_bank_name = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
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
//DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csPtr));
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
        sqlstm.offset = (unsigned int  )388;
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
        sqlstm.offset = (unsigned int  )407;
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


int ml_TxnPspDetail_Add(const hash_t *hRls)
{
        char            *csTmp;
        double          dTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO txnpspdetail_add_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_psp_id[PD_PSP_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_psp_id;

        double          hv_txn_amt;
        /* varchar         hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

        /* varchar         hv_txn_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_txn_date;

        /* varchar         hv_desc[PD_DESC_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_desc;

        /* varchar         hv_status[PD_PSP_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_status;

        /* varchar         hv_notice_status[PD_PSP_STATUS_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_notice_status;

        /* varchar         hv_error_code[PD_ERROR_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_error_code;

        /* varchar         hv_tid[PD_PSP_TID_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_tid;

        /* varchar         hv_url[PD_URL_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_url;

        /* varchar         hv_bank_code[PD_BANK_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_bank_code;

        /* varchar         hv_bank_branch[PD_BANK_BRANCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[100]; } hv_bank_branch;

        /* varchar         hv_account_name[PD_ACCOUNT_NAME_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_account_name;

        /* varchar         hv_account_no[PD_ACCOUNT_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[30]; } hv_account_no;

        /* varchar         hv_batch_id[PD_BATCH_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_batch_id;

        /* varchar         hv_fundin_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_fundin_date;

        /* varchar         hv_fundout_date[PD_DATETIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_fundout_date;

        double          hv_service_fee;
        /* varchar         hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;

        /* varchar         hv_bill_no[PD_BANK_BILL_NO_LEN]; */ 
struct { unsigned short len; unsigned char arr[50]; } hv_bill_no;


        short           ind_txn_id = -1;
        short           ind_psp_id = -1;
        short           ind_txn_amt = -1;
        short           ind_txn_ccy = -1;
        short           ind_txn_date = -1;
        short           ind_desc = -1;
        short           ind_status = -1;
        short           ind_notice_status = -1;
        short           ind_error_code = -1;
        short           ind_tid = -1;
        short           ind_url = -1;
        short           ind_bank_code = -1;
        short           ind_bank_branch = -1;
        short           ind_account_name = -1;
        short           ind_account_no = -1;
        short           ind_batch_id = -1;
        short           ind_fundin_date = -1;
        short           ind_fundout_date = -1;
        short           ind_service_fee = -1;
        short           ind_add_user = -1;
        short           ind_bill_no = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));


/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("Add:txn_id = [%.*s][%d]\n",hv_txn_id.len,hv_txn_id.arr,hv_txn_id.len));
        }
/* psp_id */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
                hv_psp_id.len = strlen(csTmp);
                memcpy(hv_psp_id.arr,csTmp,hv_psp_id.len);
                ind_psp_id = 0;
DEBUGLOG(("Add:psp_id = [%.*s][%d]\n",hv_psp_id.len,hv_psp_id.arr,hv_psp_id.len));
        }

/* txn_amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
                hv_txn_amt= dTmp;
                ind_txn_amt = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_txn_amt));
        }

/*      if (GetField_Double(hRls,"txn_amount",&dTmp)){
                hv_txn_amt = dTmp;
                ind_txn_amt = 0;
DEBUGLOG(("Add:txn_amt = [%f]\n",hv_txn_amt));
        }
*/
/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
                hv_txn_date.len = strlen(csTmp);
                memcpy(hv_txn_date.arr,csTmp,hv_txn_date.len);
                ind_txn_date = 0;
DEBUGLOG(("Add:txn_date = [%.*s][%d]\n",hv_txn_date.len,hv_txn_date.arr,hv_txn_date.len));
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("Add:txn_ccy = [%.*s][%d]\n",hv_txn_ccy.len,hv_txn_ccy.arr,hv_txn_ccy.len));
        }


/* desc */

        if (GetField_CString(hRls,"desc", &csTmp)) {
                hv_desc.len = strlen(csTmp);
                memcpy(hv_desc.arr,csTmp,hv_desc.len);
                ind_desc = 0;
DEBUGLOG(("Add:desc = [%.*s][%d]\n",hv_desc.len,hv_desc.arr,hv_desc.len));

        }

/* status */
        if (GetField_CString(hRls,"status", &csTmp)) {
                hv_status.len = strlen(csTmp);
                memcpy(hv_status.arr,csTmp,hv_status.len);
                ind_status = 0;
DEBUGLOG(("Add:status = [%.*s][%d]\n",hv_status.len,hv_status.arr,hv_status.len));
        }
/* notice_status */
        if (GetField_CString(hRls,"notice_status", &csTmp)) {
                hv_notice_status.len = strlen(csTmp);
                memcpy(hv_notice_status.arr,csTmp,hv_notice_status.len);
                ind_notice_status = 0;
DEBUGLOG(("Add:notice_status = [%.*s]\n",hv_notice_status.len,hv_notice_status.arr));
        }
/* error_code */
        if (GetField_CString(hRls,"error_code", &csTmp)) {
                hv_error_code.len = strlen(csTmp);
                memcpy(hv_error_code.arr,csTmp,hv_error_code.len);
                ind_error_code = 0;
DEBUGLOG(("Add:error_code = [%.*s]\n",hv_status.len,hv_error_code.arr));
        }

/* tid */
        if (GetField_CString(hRls,"tid", &csTmp)) {
                hv_tid.len = strlen(csTmp);
                memcpy(hv_tid.arr,csTmp,hv_tid.len);
                ind_tid = 0;
DEBUGLOG(("Add:tid = [%.*s][%d]\n",hv_tid.len,hv_tid.arr,hv_tid.len));
        }

/* url */
        if (GetField_CString(hRls,"deposit_url", &csTmp)) {
                hv_url.len = strlen(csTmp);
                memcpy(hv_url.arr,csTmp,hv_url.len);
                ind_url = 0;
DEBUGLOG(("Add:url = [%.*s][%d]\n",hv_url.len,hv_url.arr,hv_url.len));
        }
/* bank_code */
        if (GetField_CString(hRls,"bank_code", &csTmp)) {
                hv_bank_code.len = strlen(csTmp);
                memcpy(hv_bank_code.arr,csTmp,hv_bank_code.len);
                ind_bank_code = 0;
DEBUGLOG(("Add:bank_code = [%.*s][%d]\n",hv_bank_code.len,hv_bank_code.arr,hv_bank_code.len));
        }
/* bank_branch */
        if (GetField_CString(hRls,"bank_branch", &csTmp)) {
                hv_bank_branch.len = strlen(csTmp);
                memcpy(hv_bank_branch.arr,csTmp,hv_bank_branch.len);
                ind_bank_branch = 0;
DEBUGLOG(("Add:bank_branch = [%.*s][%d]\n",hv_bank_branch.len,hv_bank_branch.arr,hv_bank_branch.len));
        }

/* account_name */
        if (GetField_CString(hRls,"account_name", &csTmp)) {
                hv_account_name.len = strlen(csTmp);
                memcpy(hv_account_name.arr,csTmp,hv_account_name.len);
                ind_account_name = 0;
DEBUGLOG(("Add:account_name = [%.*s][%d]\n",hv_account_name.len,hv_account_name.arr,hv_account_name.len));
        }
/* account_no */
        if (GetField_CString(hRls,"account_no", &csTmp)) {
                hv_account_no.len = strlen(csTmp);
                memcpy(hv_account_no.arr,csTmp,hv_account_no.len);
                ind_account_no = 0;
DEBUGLOG(("Add:account_no = [%.*s][%d]\n",hv_account_no.len,hv_account_no.arr,hv_account_no.len));
        }
/* batch_id */
        if (GetField_CString(hRls,"batch_id", &csTmp)) {
                hv_batch_id.len = strlen(csTmp);
                memcpy(hv_batch_id.arr,csTmp,hv_batch_id.len);
                ind_batch_id = 0;
DEBUGLOG(("Add:batch_id = [%.*s][%d]\n",hv_batch_id.len,hv_batch_id.arr,hv_batch_id.len));
        }

/* fundin_date */
        if (GetField_CString(hRls,"fundin_date", &csTmp)) {
                hv_fundin_date.len = strlen(csTmp);
                memcpy(hv_fundin_date.arr,csTmp,hv_fundin_date.len);
                ind_fundin_date = 0;
DEBUGLOG(("Add:fundin_date = [%.*s]\n",hv_fundin_date.len,hv_fundin_date.arr));
        }

/* fundout_date */
        if (GetField_CString(hRls,"fundout_date", &csTmp)) {
                hv_fundout_date.len = strlen(csTmp);
                memcpy(hv_fundout_date.arr,csTmp,hv_fundout_date.len);
                ind_fundout_date = 0;
DEBUGLOG(("Add:fundout_date = [%.*s]\n",hv_fundout_date.len,hv_fundout_date.arr));
        }
/* serive_fee */
        if (GetField_Double(hRls,"service_fee", &dTmp)) {
                hv_service_fee = dTmp;
                ind_service_fee = 0;
DEBUGLOG(("Add:service_fee = [%f]\n",hv_service_fee));
        }

/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

/* bank bill no */
        if (GetField_CString(hRls,"bank_bill_no", &csTmp)) {
                hv_bill_no.len = strlen(csTmp);
                memcpy(hv_bill_no.arr,csTmp,hv_bill_no.len);
                ind_bill_no = 0;
DEBUGLOG(("Add:bank_bill_no = [%.*s][%d]\n",hv_bill_no.len,hv_bill_no.arr,hv_bill_no.len));
        }


        FREE_ME(csTmp);

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_txn_psp_detail_insert(
                                        :hv_txn_id:ind_txn_id,
                                        :hv_psp_id:ind_psp_id,
                                        :hv_txn_amt:ind_txn_amt,
                                        :hv_txn_date:ind_txn_date,
                                        :hv_txn_ccy:ind_txn_ccy,
                                        :hv_desc:ind_desc,
                                        :hv_status:ind_status,
                                        :hv_notice_status:ind_notice_status,
                                        :hv_error_code:ind_error_code,
                                        :hv_tid:ind_tid,
                                        :hv_url:ind_url,
                                        :hv_bank_code:ind_bank_code,
                                        :hv_bank_branch:ind_bank_branch,
                                        :hv_account_name:ind_account_name,
                                        :hv_account_no:ind_account_no,
                                        :hv_batch_id:ind_batch_id,
                                        :hv_fundin_date:ind_fundin_date,
                                        :hv_fundout_date:ind_fundout_date,
                                        :hv_service_fee:ind_service_fee,
                                        :hv_add_user:ind_add_user,
                                        :hv_add_user:ind_add_user,
                                        :hv_bill_no:ind_bill_no);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_txn_psp_detail_insert (\
 :hv_txn_id:ind_txn_id , :hv_psp_id:ind_psp_id , :hv_txn_amt:ind_txn_amt , :h\
v_txn_date:ind_txn_date , :hv_txn_ccy:ind_txn_ccy , :hv_desc:ind_desc , :hv_s\
tatus:ind_status , :hv_notice_status:ind_notice_status , :hv_error_code:ind_e\
rror_code , :hv_tid:ind_tid , :hv_url:ind_url , :hv_bank_code:ind_bank_code ,\
 :hv_bank_branch:ind_bank_branch , :hv_account_name:ind_account_name , :hv_ac\
count_no:ind_account_no , :hv_batch_id:ind_batch_id , :hv_fundin_date:ind_fun\
din_date , :hv_fundout_date:ind_fundout_date , :hv_service_fee:ind_service_fe\
e , :hv_add_user:ind_add_user , :hv_add_user:ind_add_user , :hv_bill_no:ind_b\
ill_no ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )422;
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
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_psp_id;
        sqlstm.sqhstl[2] = (unsigned long )12;
        sqlstm.sqhsts[2] = (         int  )0;
        sqlstm.sqindv[2] = (         short *)&ind_psp_id;
        sqlstm.sqinds[2] = (         int  )0;
        sqlstm.sqharm[2] = (unsigned long )0;
        sqlstm.sqadto[2] = (unsigned short )0;
        sqlstm.sqtdso[2] = (unsigned short )0;
        sqlstm.sqhstv[3] = (unsigned char  *)&hv_txn_amt;
        sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[3] = (         int  )0;
        sqlstm.sqindv[3] = (         short *)&ind_txn_amt;
        sqlstm.sqinds[3] = (         int  )0;
        sqlstm.sqharm[3] = (unsigned long )0;
        sqlstm.sqadto[3] = (unsigned short )0;
        sqlstm.sqtdso[3] = (unsigned short )0;
        sqlstm.sqhstv[4] = (unsigned char  *)&hv_txn_date;
        sqlstm.sqhstl[4] = (unsigned long )10;
        sqlstm.sqhsts[4] = (         int  )0;
        sqlstm.sqindv[4] = (         short *)&ind_txn_date;
        sqlstm.sqinds[4] = (         int  )0;
        sqlstm.sqharm[4] = (unsigned long )0;
        sqlstm.sqadto[4] = (unsigned short )0;
        sqlstm.sqtdso[4] = (unsigned short )0;
        sqlstm.sqhstv[5] = (unsigned char  *)&hv_txn_ccy;
        sqlstm.sqhstl[5] = (unsigned long )5;
        sqlstm.sqhsts[5] = (         int  )0;
        sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
        sqlstm.sqinds[5] = (         int  )0;
        sqlstm.sqharm[5] = (unsigned long )0;
        sqlstm.sqadto[5] = (unsigned short )0;
        sqlstm.sqtdso[5] = (unsigned short )0;
        sqlstm.sqhstv[6] = (unsigned char  *)&hv_desc;
        sqlstm.sqhstl[6] = (unsigned long )52;
        sqlstm.sqhsts[6] = (         int  )0;
        sqlstm.sqindv[6] = (         short *)&ind_desc;
        sqlstm.sqinds[6] = (         int  )0;
        sqlstm.sqharm[6] = (unsigned long )0;
        sqlstm.sqadto[6] = (unsigned short )0;
        sqlstm.sqtdso[6] = (unsigned short )0;
        sqlstm.sqhstv[7] = (unsigned char  *)&hv_status;
        sqlstm.sqhstl[7] = (unsigned long )12;
        sqlstm.sqhsts[7] = (         int  )0;
        sqlstm.sqindv[7] = (         short *)&ind_status;
        sqlstm.sqinds[7] = (         int  )0;
        sqlstm.sqharm[7] = (unsigned long )0;
        sqlstm.sqadto[7] = (unsigned short )0;
        sqlstm.sqtdso[7] = (unsigned short )0;
        sqlstm.sqhstv[8] = (unsigned char  *)&hv_notice_status;
        sqlstm.sqhstl[8] = (unsigned long )12;
        sqlstm.sqhsts[8] = (         int  )0;
        sqlstm.sqindv[8] = (         short *)&ind_notice_status;
        sqlstm.sqinds[8] = (         int  )0;
        sqlstm.sqharm[8] = (unsigned long )0;
        sqlstm.sqadto[8] = (unsigned short )0;
        sqlstm.sqtdso[8] = (unsigned short )0;
        sqlstm.sqhstv[9] = (unsigned char  *)&hv_error_code;
        sqlstm.sqhstl[9] = (unsigned long )8;
        sqlstm.sqhsts[9] = (         int  )0;
        sqlstm.sqindv[9] = (         short *)&ind_error_code;
        sqlstm.sqinds[9] = (         int  )0;
        sqlstm.sqharm[9] = (unsigned long )0;
        sqlstm.sqadto[9] = (unsigned short )0;
        sqlstm.sqtdso[9] = (unsigned short )0;
        sqlstm.sqhstv[10] = (unsigned char  *)&hv_tid;
        sqlstm.sqhstl[10] = (unsigned long )52;
        sqlstm.sqhsts[10] = (         int  )0;
        sqlstm.sqindv[10] = (         short *)&ind_tid;
        sqlstm.sqinds[10] = (         int  )0;
        sqlstm.sqharm[10] = (unsigned long )0;
        sqlstm.sqadto[10] = (unsigned short )0;
        sqlstm.sqtdso[10] = (unsigned short )0;
        sqlstm.sqhstv[11] = (unsigned char  *)&hv_url;
        sqlstm.sqhstl[11] = (unsigned long )102;
        sqlstm.sqhsts[11] = (         int  )0;
        sqlstm.sqindv[11] = (         short *)&ind_url;
        sqlstm.sqinds[11] = (         int  )0;
        sqlstm.sqharm[11] = (unsigned long )0;
        sqlstm.sqadto[11] = (unsigned short )0;
        sqlstm.sqtdso[11] = (unsigned short )0;
        sqlstm.sqhstv[12] = (unsigned char  *)&hv_bank_code;
        sqlstm.sqhstl[12] = (unsigned long )12;
        sqlstm.sqhsts[12] = (         int  )0;
        sqlstm.sqindv[12] = (         short *)&ind_bank_code;
        sqlstm.sqinds[12] = (         int  )0;
        sqlstm.sqharm[12] = (unsigned long )0;
        sqlstm.sqadto[12] = (unsigned short )0;
        sqlstm.sqtdso[12] = (unsigned short )0;
        sqlstm.sqhstv[13] = (unsigned char  *)&hv_bank_branch;
        sqlstm.sqhstl[13] = (unsigned long )102;
        sqlstm.sqhsts[13] = (         int  )0;
        sqlstm.sqindv[13] = (         short *)&ind_bank_branch;
        sqlstm.sqinds[13] = (         int  )0;
        sqlstm.sqharm[13] = (unsigned long )0;
        sqlstm.sqadto[13] = (unsigned short )0;
        sqlstm.sqtdso[13] = (unsigned short )0;
        sqlstm.sqhstv[14] = (unsigned char  *)&hv_account_name;
        sqlstm.sqhstl[14] = (unsigned long )32;
        sqlstm.sqhsts[14] = (         int  )0;
        sqlstm.sqindv[14] = (         short *)&ind_account_name;
        sqlstm.sqinds[14] = (         int  )0;
        sqlstm.sqharm[14] = (unsigned long )0;
        sqlstm.sqadto[14] = (unsigned short )0;
        sqlstm.sqtdso[14] = (unsigned short )0;
        sqlstm.sqhstv[15] = (unsigned char  *)&hv_account_no;
        sqlstm.sqhstl[15] = (unsigned long )32;
        sqlstm.sqhsts[15] = (         int  )0;
        sqlstm.sqindv[15] = (         short *)&ind_account_no;
        sqlstm.sqinds[15] = (         int  )0;
        sqlstm.sqharm[15] = (unsigned long )0;
        sqlstm.sqadto[15] = (unsigned short )0;
        sqlstm.sqtdso[15] = (unsigned short )0;
        sqlstm.sqhstv[16] = (unsigned char  *)&hv_batch_id;
        sqlstm.sqhstl[16] = (unsigned long )22;
        sqlstm.sqhsts[16] = (         int  )0;
        sqlstm.sqindv[16] = (         short *)&ind_batch_id;
        sqlstm.sqinds[16] = (         int  )0;
        sqlstm.sqharm[16] = (unsigned long )0;
        sqlstm.sqadto[16] = (unsigned short )0;
        sqlstm.sqtdso[16] = (unsigned short )0;
        sqlstm.sqhstv[17] = (unsigned char  *)&hv_fundin_date;
        sqlstm.sqhstl[17] = (unsigned long )16;
        sqlstm.sqhsts[17] = (         int  )0;
        sqlstm.sqindv[17] = (         short *)&ind_fundin_date;
        sqlstm.sqinds[17] = (         int  )0;
        sqlstm.sqharm[17] = (unsigned long )0;
        sqlstm.sqadto[17] = (unsigned short )0;
        sqlstm.sqtdso[17] = (unsigned short )0;
        sqlstm.sqhstv[18] = (unsigned char  *)&hv_fundout_date;
        sqlstm.sqhstl[18] = (unsigned long )16;
        sqlstm.sqhsts[18] = (         int  )0;
        sqlstm.sqindv[18] = (         short *)&ind_fundout_date;
        sqlstm.sqinds[18] = (         int  )0;
        sqlstm.sqharm[18] = (unsigned long )0;
        sqlstm.sqadto[18] = (unsigned short )0;
        sqlstm.sqtdso[18] = (unsigned short )0;
        sqlstm.sqhstv[19] = (unsigned char  *)&hv_service_fee;
        sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
        sqlstm.sqhsts[19] = (         int  )0;
        sqlstm.sqindv[19] = (         short *)&ind_service_fee;
        sqlstm.sqinds[19] = (         int  )0;
        sqlstm.sqharm[19] = (unsigned long )0;
        sqlstm.sqadto[19] = (unsigned short )0;
        sqlstm.sqtdso[19] = (unsigned short )0;
        sqlstm.sqhstv[20] = (unsigned char  *)&hv_add_user;
        sqlstm.sqhstl[20] = (unsigned long )22;
        sqlstm.sqhsts[20] = (         int  )0;
        sqlstm.sqindv[20] = (         short *)&ind_add_user;
        sqlstm.sqinds[20] = (         int  )0;
        sqlstm.sqharm[20] = (unsigned long )0;
        sqlstm.sqadto[20] = (unsigned short )0;
        sqlstm.sqtdso[20] = (unsigned short )0;
        sqlstm.sqhstv[21] = (unsigned char  *)&hv_bill_no;
        sqlstm.sqhstl[21] = (unsigned long )52;
        sqlstm.sqhsts[21] = (         int  )0;
        sqlstm.sqindv[21] = (         short *)&ind_bill_no;
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
        if (sqlca.sqlcode < 0) goto txnpspdetail_add_error;
}


DEBUGLOG(("Add:Ret = [%d]\n",hv_return_value));
        if (hv_return_value == SP_OK) {
DEBUGLOG(("Add:Normal Exit\n"));
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("TxnPspDetail_Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
                TxnAbort();
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("TxnPspDetail_Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                TxnAbort();
                return PD_ERR;
        }

txnpspdetail_add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("TxnPspDetail_Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}


int ml_TxnPspDetail_Update(const hash_t *hRls)
{

        char*   csTmp;
        double  dTmp;
        int     iTmp;
        char*   csBuf;
        char*   csTxnId;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[1024]; */ 
struct { unsigned short len; unsigned char arr[1024]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (128);
        strcpy((char*)hv_dynstmt.arr,"update txn_psp_detail set tp_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* psp_id  */
        if (GetField_CString(hRls,"psp_id",&csTmp)) {
DEBUGLOG(("Update:psp_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_psp_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
DEBUGLOG(("Update:txn_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_txn_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_date */
        if (GetField_CString(hRls,"txn_date",&csTmp)) {
DEBUGLOG(("Update:txn_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_txn_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* txn_time*/
        if (GetField_CString(hRls,"txn_time",&csTmp)) {
DEBUGLOG(("Update:txn_time = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_txn_time = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amount",&dTmp)) {
DEBUGLOG(("Update:txn_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_txn_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* desc */
        if (GetField_CString(hRls,"descorder_no",&csTmp)) {
DEBUGLOG(("Update:desc = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_desc = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* status */
        if (GetField_CString(hRls,"status",&csTmp)) {
DEBUGLOG(("Update:status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* notice_status */
        if (GetField_CString(hRls,"notice_status",&csTmp)) {
DEBUGLOG(("Update:notice_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_notice_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
DEBUGLOG(("Update:notice_status = [%s]\n",hv_dynstmt.arr));
        }
/* error_code */
        if (GetField_CString(hRls,"error_code",&csTmp)) {
DEBUGLOG(("Update:error_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_error_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* tid */
        if (GetField_CString(hRls,"tid",&csTmp)) {
DEBUGLOG(("Update:tid = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_tid = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* url */
        if (GetField_CString(hRls,"deposit_url",&csTmp)) {
DEBUGLOG(("Update:deposit_url = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_url = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank_code */
        if (GetField_CString(hRls,"bank_code",&csTmp)) {
DEBUGLOG(("Update:bank_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_bank_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* bank_branch */
        if (GetField_CString(hRls,"bank_branch",&csTmp)) {
DEBUGLOG(("Update:bank_branch = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_bank_branch = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* account_name */
        if (GetField_CString(hRls,"account_name",&csTmp)) {
DEBUGLOG(("Update:account_name = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_account_name = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* account_no */
        if (GetField_CString(hRls,"account_no",&csTmp)) {
DEBUGLOG(("Update:account_no = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_account_no = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* batch_id */
        if (GetField_CString(hRls,"batch_id",&csTmp)) {
DEBUGLOG(("Update:batch_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_batch_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* fundin_date */
        if (GetField_CString(hRls,"fundin_date",&csTmp)) {
//DEBUGLOG(("Update:fundin_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_fundin_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* limit_date */
        if (GetField_CString(hRls,"limit_date",&csTmp)) {
DEBUGLOG(("Update:limit_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_limit_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment_limit_date */
        if (GetField_CString(hRls,"payment_limit_date",&csTmp)) {
DEBUGLOG(("Update:payment_limit_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_payment_limit_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* payment notice id */
        if (GetField_CString(hRls,"payment_notice_id",&csTmp)) {
DEBUGLOG(("Update:payment_notice_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_payment_notice_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment type */
        if (GetField_CString(hRls,"payment_type",&csTmp)) {
DEBUGLOG(("Update:payment_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_payment_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* payment status */
        if (GetField_CString(hRls,"payment_status",&csTmp)) {
DEBUGLOG(("Update:payment_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_payment_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* pay_center_number */
        if (GetField_CString(hRls,"pay_center_number",&csTmp)) {
DEBUGLOG(("Update:pay_center_number = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_pay_center_number = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* customer_number */
        if (GetField_CString(hRls,"customer_number",&csTmp)) {
DEBUGLOG(("Update:customer_number = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_customer_number = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* conf_number */
        if (GetField_CString(hRls,"conf_number",&csTmp)) {
DEBUGLOG(("Update:conf_number = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_conf_number = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* receipt_number */
        if (GetField_CString(hRls,"receipt_number",&csTmp)) {
DEBUGLOG(("Update:receipt_number = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_receipt_number = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* store_id */
        if (GetField_CString(hRls,"store_id",&csTmp)) {
DEBUGLOG(("Update:store_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_store_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* convenience_store */
        if (GetField_CString(hRls,"convenience_store",&csTmp)) {
DEBUGLOG(("Update:convenience_store = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_convenience_store = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* sc */
        if (GetField_CString(hRls,"sc",&csTmp)) {
DEBUGLOG(("Update:sc = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_sc = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* fundout_date */
        if (GetField_CString(hRls,"fundout_date",&csTmp)) {
DEBUGLOG(("Update:fundout_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_fundout_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* service_fee   */
        if (GetField_Double(hRls,"service_fee",&dTmp)) {
DEBUGLOG(("Update:serive_fee = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_service_fee = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bank bill no*/
        if (GetField_CString(hRls,"bank_bill_no",&csTmp)) {
DEBUGLOG(("Update:bank_bill_no = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_bank_bill_no = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* bal */
        if (GetField_Double(hRls,"bal",&dTmp)) {
DEBUGLOG(("Update:current_balance = [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_bal = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_float */
        if (GetField_Double(hRls,"total_float",&dTmp)) {
DEBUGLOG(("Update:total_float = [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_total_float = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* total_hold */
        if (GetField_Double(hRls,"total_hold",&dTmp)) {
DEBUGLOG(("Update:total_hold = [%f]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_total_hold = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* fundin_date_short */
        if (GetField_CString(hRls,"fundin_date_short",&csTmp)) {
//DEBUGLOG(("Update:fundin_date_short = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_fundin_date_short = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* match_ind */
        if (GetField_Int(hRls,"match_ind",&iTmp)) {
DEBUGLOG(("Update:match_ind = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_match_ind = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* match_date */
        if (GetField_CString(hRls,"match_date",&csTmp)) {
DEBUGLOG(("Update:match_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_match_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* recon_ind */
        if (GetField_Int(hRls,"recon_ind",&iTmp)) {
DEBUGLOG(("Update:recon_ind = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",tp_recon_ind = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* recon_date */
        if (GetField_CString(hRls,"recon_date",&csTmp)) {
DEBUGLOG(("Update:recon_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_recon_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
DEBUGLOG(("Update:add_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_create_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",tp_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

        strcat((char *)hv_dynstmt.arr, " WHERE tp_txn_id = '");
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
        sqlstm.offset = (unsigned int  )525;
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
        sqlstm.arrsiz = 40;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )544;
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

ERRLOG("TxnPspDetail_Update: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Update: SP_INTERNAL_ERR TxnAbort\n"));
        TxnAbort();
        return PD_INTERNAL_ERR;
}

int ml_Header_AddTxnBrowserInfo(const hash_t *hRls)
{
        char            *csTmp;


        /* EXEC SQL WHENEVER SQLERROR GOTO addtxnbrowserinfo_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_user_agent[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_user_agent;

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
                hv_client_ip.len = strlen(csTmp);
                memcpy(hv_client_ip.arr,csTmp,hv_client_ip.len);
                ind_client_ip = 0;
DEBUGLOG(("AddTxnBrowserInfo:client_ip = [%.*s]\n",hv_client_ip.len,hv_client_ip.arr));
        }


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
        sqlstm.stmt = "begin :hv_return_value := sp_txn_browser_info_insert\
 ( :hv_txn_id:ind_txn_id , :hv_client_ip:ind_client_ip , :hv_user_agent:ind_u\
ser_agent , :hv_add_user:ind_add_user ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )559;
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
        sqlstm.sqhstl[3] = (unsigned long )257;
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

addtxnbrowserinfo_error:
DEBUGLOG(("addtxnbrowserinfo_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("Transaction_AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("AddTxnBrowserInfo: SP_INTERNAL_ERR TxnAbort\n"));
        return PD_INTERNAL_ERR;
}


