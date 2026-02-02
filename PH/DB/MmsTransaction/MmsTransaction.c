
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
"select mth_org_txn_id , mth_status , mth_ar_ind , mth_sub_status , mth_txn_\
code , mth_transaction_amount , mth_txn_ccy , mth_remaining_amount , mth_net_\
amount , mth_net_ccy , mth_transmission_datetime , mth_local_tm_date , mth_lo\
cal_tm_time , mth_tm_date , mth_tm_time , mth_internal_code , mth_response_co\
de , mth_host_posting_date , mth_process_code , mth_process_type , mth_input_\
channel , mth_client_ip , mth_apply_cost , mth_related_txn_id , mth_node_id ,\
 mth_node_ref from mms_txn_header where mth_txn_id = :b0            ";

 static char *sq0005 = 
"select mtd_entity_id , mtd_related_entity_id , mtd_open_acct_bal , mtd_open\
_intransit , mtd_open_lien , mtd_open_prepaid , mtd_curr_acct_bal , mtd_curr_\
intransit , mtd_curr_lien , mtd_curr_prepaid , mtd_provided_fx_rate , mtd_fx_\
rate , mtd_provided_cost_rate , mtd_provided_fixed_amount , mtd_provided_cost\
 , mtd_cost_rate , mtd_fixed_amount , mtd_cost , mtd_next_action_ccy , mtd_re\
mark from mms_txn_detail where mtd_txn_id = :b0            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1068,0,6,370,0,0,31,31,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
1,0,0,1,1,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,3,0,0,1,9,0,0,1,4,0,0,1,9,0,0,1,4,0,0,1,4,0,0,1,9,0,0,1,9,0,0,1,3,0,0,1,1,0,
0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
144,0,0,2,0,0,17,754,0,0,1,1,0,1,0,1,9,0,0,
163,0,0,2,0,0,21,755,0,0,0,0,0,1,0,
178,0,0,3,528,0,9,885,0,2049,1,1,0,1,0,1,9,0,0,
197,0,0,3,0,0,13,887,0,0,26,0,0,1,0,2,9,0,0,2,1,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,
4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,
316,0,0,3,0,0,15,1089,0,0,0,0,0,1,0,
331,0,0,3,0,0,15,1105,0,0,0,0,0,1,0,
346,0,0,4,900,0,6,1354,0,0,25,25,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,4,0,0,
1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,
0,1,4,0,0,1,4,0,0,1,4,0,0,1,4,0,0,1,1,0,0,1,9,0,0,1,1,0,0,1,4,0,0,1,9,0,0,1,9,
0,0,
461,0,0,2,0,0,17,1655,0,0,1,1,0,1,0,1,9,0,0,
480,0,0,2,0,0,21,1656,0,0,0,0,0,1,0,
495,0,0,5,442,0,9,1759,0,2049,1,1,0,1,0,1,9,0,0,
514,0,0,5,0,0,13,1761,0,0,20,0,0,1,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,
4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
609,0,0,5,0,0,15,1912,0,0,0,0,0,1,0,
624,0,0,5,0,0,15,1922,0,0,0,0,0,1,0,
639,0,0,6,88,0,6,1950,0,0,3,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,
666,0,0,2,0,0,17,2059,0,0,1,1,0,1,0,1,9,0,0,
685,0,0,2,0,0,45,2062,0,0,0,0,0,1,0,
700,0,0,2,0,0,13,2064,0,0,1,0,0,1,0,2,9,0,0,
719,0,0,7,91,0,4,2106,0,0,2,1,0,1,0,2,3,0,0,1,9,0,0,
};


/*
Partnerdelight (c)2015. All rights reserved. No part of this software may be reproduced in any form without written permission 
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/04/29              Cody Chan
Add MatchTxnStatus				   2015/06/29		   Cody Chan
Add ChkTxnCodeExist				   2015/06/30		   Elvis Wong
Remove TxnCountry				   2015/07/22		   Cody Chan
Add Allow Prepaid				   2015/07/23		   Cody Chan
Remove NatureDetail				   2015/08/04		   Cody Chan
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
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode
OBJPTR(DB);

char    cDebug;
void MmsTransaction(char    cdebug)
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
	
	/* varchar		hv_action_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_action_txn_id;
	
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

	/* varchar		hv_node_id[PD_MMS_NODE_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_node_id;

	/* varchar		hv_node_ref[PD_MMS_NODE_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_node_ref;

	/* varchar		hv_host_posting_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_posting_date;

	/* varchar		hv_transmission_datetime[PD_DATE_LEN + PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[14]; } hv_transmission_datetime;

	int		hv_internal_code;
	/* varchar		hv_response_code[PD_RESPONSE_CODE_LEN]; */ 
struct { unsigned short len; unsigned char arr[10]; } hv_response_code;

	double		hv_transaction_amt;
	/* varchar		hv_txn_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_txn_ccy;

	double		hv_remaining_amt;
	double		hv_net_amt;
	/* varchar		hv_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } hv_net_ccy;

	/* varchar		hv_local_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_local_tm_date;

	/* varchar		hv_local_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_local_tm_time;

	/* varchar		hv_tm_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_tm_date;

	/* varchar		hv_tm_time[PD_TIME_LEN]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_tm_time;

	/* varchar		hv_client_ip[PD_IP_LEN]; */ 
struct { unsigned short len; unsigned char arr[25]; } hv_client_ip;

	int		hv_apply_cost;
	char		hv_action;
	/* varchar		hv_related_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_related_txn_id;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;




	short		ind_txn_id = -1;
	short		ind_org_txn_id = -1;
	short		ind_action_txn_id = -1;
	short		ind_channel_code = -1;
	short		ind_status = -1;
	short		ind_ar_ind = -1;
	short		ind_sub_status = -1;
	short		ind_txn_code = -1;
	short		ind_process_type = -1;
	short		ind_process_code = -1;
	short		ind_node_id = -1;
	short		ind_node_ref = -1;
	short		ind_host_posting_date = -1;
	short		ind_transmission_datetime = -1;
	short		ind_internal_code = -1;
	short		ind_response_code = -1;
	short		ind_transaction_amt = -1;
	short		ind_txn_ccy = -1;
	short		ind_remaining_amt = -1;
	short		ind_net_amt = -1;
	short		ind_net_ccy = -1;
	short		ind_local_tm_date = -1;
	short		ind_local_tm_time = -1;
	short		ind_tm_date = -1;
	short		ind_tm_time = -1;
	short		ind_client_ip= -1;
	short		ind_apply_cost = -1;
	short		ind_action = -1;
	short		ind_related_txn_id = -1;
	short		ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

        if (GetField_Int(hRls,"db_commit",&iCommit)) {
DEBUGLOG(("Add:db_commit = [%d]\n",iCommit));
	}
	else {
DEBUGLOG(("Add:db_commit default true \n"));
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
/* action_txn_seq */
        if (GetField_CString(hRls,"action_txn_seq",&csTmp)) {
                hv_action_txn_id.len = strlen(csTmp);
                memcpy(hv_action_txn_id.arr,csTmp,hv_action_txn_id.len);
                ind_action_txn_id = 0;
DEBUGLOG(("Add:action_txn_id = [%.*s]\n",hv_action_txn_id.len,hv_action_txn_id.arr));
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

/* node_id */
        if (GetField_CString(hRls,"node_id",&csTmp)) {
                hv_node_id.len = strlen(csTmp);
                memcpy(hv_node_id.arr,csTmp,hv_node_id.len);
                ind_node_id = 0;
DEBUGLOG(("Add:node_id = [%.*s]\n",hv_node_id.len,hv_node_id.arr));
        }

/* node_ref */
        if (GetField_CString(hRls,"node_ref",&csTmp)) {
                hv_node_ref.len = strlen(csTmp);
                memcpy(hv_node_ref.arr,csTmp,hv_node_ref.len);
                ind_node_ref = 0;
DEBUGLOG(("Add:node_ref = [%.*s]\n",hv_node_ref.len,hv_node_ref.arr));
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
DEBUGLOG(("Add:internal code = [%d]\n",hv_internal_code));
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

/* txn_ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
                hv_txn_ccy.len = strlen(csTmp);
                memcpy(hv_txn_ccy.arr,csTmp,hv_txn_ccy.len);
                ind_txn_ccy = 0;
DEBUGLOG(("Add:txn_ccy = [%.*s]\n",hv_txn_ccy.len,hv_txn_ccy.arr));
        }
/* remaining amt   */
        if (GetField_Double(hRls,"remaining_amt",&dTmp)) {
		hv_remaining_amt = dTmp;
                ind_remaining_amt = 0;
DEBUGLOG(("Add:remaining_amt = [%f]\n",hv_remaining_amt));
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

/* apply cost   */
        if (GetField_Int(hRls,"apply_cost",&iTmp)) {
		hv_apply_cost = iTmp;
                ind_apply_cost = 0;
DEBUGLOG(("Add:apply_cost = [%d]\n",hv_apply_cost));
        }

/* action */
        if (GetField_Char(hRls,"action",&cTmp)) {
		hv_action = cTmp;
		ind_action = 0; 
DEBUGLOG(("Add:action = [%c]\n",hv_action));
        }


/* related_txn_id */
        if (GetField_CString(hRls,"related_txn_id",&csTmp)) {
                hv_related_txn_id.len = strlen(csTmp);
                memcpy(hv_related_txn_id.arr,csTmp,hv_related_txn_id.len);
                ind_related_txn_id = 0;
DEBUGLOG(("Add:related_txn_id = [%.*s]\n",hv_related_txn_id.len,hv_related_txn_id.arr));
        }
/* add user */
        if (GetField_CString(hRls,"add_user",&csTmp)) {
                hv_add_user.len = strlen(csTmp);
                memcpy(hv_add_user.arr,csTmp,hv_add_user.len);
                ind_add_user = 0;
DEBUGLOG(("Add:add_user = [%.*s]\n",hv_add_user.len,hv_add_user.arr));
        }

	/* EXEC SQL EXECUTE
                BEGIN
			:hv_return_value := sp_mms_txn_header_insert(
					:hv_txn_id:ind_txn_id,
					:hv_org_txn_id:ind_org_txn_id,
					:hv_action_txn_id:ind_action_txn_id,
					:hv_channel_code:ind_channel_code,
					:hv_status:ind_status,
					:hv_ar_ind:ind_ar_ind,
					:hv_sub_status:ind_sub_status,
					:hv_txn_code:ind_txn_code,
					:hv_process_type:ind_process_type,
					:hv_process_code:ind_process_code,
					:hv_node_id:ind_node_id,
					:hv_node_ref:ind_node_ref,
					:hv_host_posting_date:ind_host_posting_date,
					:hv_transmission_datetime:ind_transmission_datetime,
					:hv_internal_code:ind_internal_code,
					:hv_response_code:ind_response_code,
					:hv_transaction_amt:ind_transaction_amt,
					:hv_txn_ccy:ind_txn_ccy,
					:hv_remaining_amt:ind_remaining_amt,
					:hv_net_amt:ind_net_amt,
					:hv_net_ccy:ind_net_ccy,
					:hv_client_ip:ind_client_ip,
					:hv_apply_cost:ind_apply_cost,
					:hv_action:ind_action,
					:hv_related_txn_id:ind_related_txn_id,
					:hv_local_tm_date:ind_local_tm_date,
					:hv_local_tm_time:ind_local_tm_time,
					:hv_tm_date:ind_tm_date,
					:hv_tm_time:ind_tm_time,
					:hv_add_user:ind_add_user,
					:hv_add_user:ind_add_user);
	        END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "begin :hv_return_value := sp_mms_txn_header_insert ( :hv_txn_id:ind_txn_\
id , :hv_org_txn_id:ind_org_txn_id , :hv_action_txn_id:ind_action_txn_id , :\
hv_channel_code:ind_channel_code , :hv_status:ind_status , :hv_ar_ind:ind_ar\
_ind , :hv_sub_status:ind_sub_status , :hv_txn_code:ind_txn_code , :hv_proce\
ss_type:ind_process_type , :hv_process_code:ind_process_code , :hv_node_id:i\
nd_node_id , :hv_node_ref:ind_node_ref , :hv_host_posting_date:ind_host_post\
ing_date , :hv_transmission_datetime:ind_transmission_datetime , :hv_interna\
l_code:ind_internal_code , :hv_response_code:ind_response_code , :hv_transac\
tion_amt:ind_transaction_amt , :hv_txn_ccy:ind_txn_ccy , :hv_remaining_amt:i\
nd_remaining_amt , :hv_net_amt:ind_net_amt , :hv_net_ccy:ind_net_ccy , :hv_c\
lient_ip:ind_client_ip , :hv_apply_cost:ind_apply_cost , :hv_action:ind_acti\
on , :hv_related_txn_id:ind_related_txn_id , :hv_local_tm_date:ind_local_tm_\
date , :hv_local_tm_time:ind_local_tm_time , :hv_tm_date:ind_tm_date , :hv_t\
m_time:ind_tm_time , :hv_add_user:ind_ad");
 sqlstm.stmt = "d_user , :hv_add_user:ind_add_user ) ; END ;";
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
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_action_txn_id;
 sqlstm.sqhstl[3] = (unsigned long )18;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_action_txn_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_channel_code;
 sqlstm.sqhstl[4] = (unsigned long )5;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_channel_code;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_status;
 sqlstm.sqhstl[5] = (unsigned long )1;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_status;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_ar_ind;
 sqlstm.sqhstl[6] = (unsigned long )1;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_ar_ind;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_sub_status;
 sqlstm.sqhstl[7] = (unsigned long )5;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_sub_status;
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
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_node_id;
 sqlstm.sqhstl[11] = (unsigned long )7;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_node_id;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_node_ref;
 sqlstm.sqhstl[12] = (unsigned long )18;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_node_ref;
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
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_txn_ccy;
 sqlstm.sqhstl[18] = (unsigned long )5;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_txn_ccy;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_remaining_amt;
 sqlstm.sqhstl[19] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_remaining_amt;
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
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_net_ccy;
 sqlstm.sqhstl[21] = (unsigned long )6;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_net_ccy;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_client_ip;
 sqlstm.sqhstl[22] = (unsigned long )27;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_client_ip;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_apply_cost;
 sqlstm.sqhstl[23] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_apply_cost;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_action;
 sqlstm.sqhstl[24] = (unsigned long )1;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_action;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_related_txn_id;
 sqlstm.sqhstl[25] = (unsigned long )18;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_related_txn_id;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_local_tm_date;
 sqlstm.sqhstl[26] = (unsigned long )10;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_local_tm_date;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
 sqlstm.sqhstv[27] = (unsigned char  *)&hv_local_tm_time;
 sqlstm.sqhstl[27] = (unsigned long )8;
 sqlstm.sqhsts[27] = (         int  )0;
 sqlstm.sqindv[27] = (         short *)&ind_local_tm_time;
 sqlstm.sqinds[27] = (         int  )0;
 sqlstm.sqharm[27] = (unsigned long )0;
 sqlstm.sqadto[27] = (unsigned short )0;
 sqlstm.sqtdso[27] = (unsigned short )0;
 sqlstm.sqhstv[28] = (unsigned char  *)&hv_tm_date;
 sqlstm.sqhstl[28] = (unsigned long )10;
 sqlstm.sqhsts[28] = (         int  )0;
 sqlstm.sqindv[28] = (         short *)&ind_tm_date;
 sqlstm.sqinds[28] = (         int  )0;
 sqlstm.sqharm[28] = (unsigned long )0;
 sqlstm.sqadto[28] = (unsigned short )0;
 sqlstm.sqtdso[28] = (unsigned short )0;
 sqlstm.sqhstv[29] = (unsigned char  *)&hv_tm_time;
 sqlstm.sqhstl[29] = (unsigned long )8;
 sqlstm.sqhsts[29] = (         int  )0;
 sqlstm.sqindv[29] = (         short *)&ind_tm_time;
 sqlstm.sqinds[29] = (         int  )0;
 sqlstm.sqharm[29] = (unsigned long )0;
 sqlstm.sqadto[29] = (unsigned short )0;
 sqlstm.sqtdso[29] = (unsigned short )0;
 sqlstm.sqhstv[30] = (unsigned char  *)&hv_add_user;
 sqlstm.sqhstl[30] = (unsigned long )22;
 sqlstm.sqhsts[30] = (         int  )0;
 sqlstm.sqindv[30] = (         short *)&ind_add_user;
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
		if (iCommit == PD_TRUE)
			TxnCommit();
                return PD_OK;
        }

        if (hv_return_value == SP_OTHER_ERR)  {
ERRLOG("MmsTransaction_Add: SP_OTHER_ERR\n");
DEBUGLOG(("Add: SP_OTHER_ERR\n"));
                return PD_OTHER_ERR;
        }

        if (hv_return_value == SP_ERR)  {
ERRLOG("MmsTransaction_Add: SP_ERR\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
                return PD_ERR;
        }

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MmsTransaction_Add: SP_INTERNAL_ERR\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}


int Update(const hash_t *hRls)
{

        char*   csTmp;
        double  dTmp;
        int     iTmp;
        char*   csBuf;
        char*   csTxnId;
	char	cStatus;
	char	cArInd;
        /* EXEC SQL WHENEVER SQLERROR GOTO update_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Update: Begin\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);
        strcpy((char*)hv_dynstmt.arr,"update mms_txn_header set mth_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("Update:txn_id = [%s]\n",csTxnId));

/* org txn_seq */
        if (GetField_CString(hRls,"org_txn_seq",&csTmp)) {
DEBUGLOG(("Update:org_txn_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_org_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Channel code */
        if (GetField_CString(hRls,"channel_code",&csTmp)) {
DEBUGLOG(("Update:channel_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_input_channel = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Status */
        if (GetField_Char(hRls,"status",&cStatus)) {
DEBUGLOG(("Update:status = [%c]\n",cStatus));
                sprintf(csBuf,"%c",cStatus);
                strcat((char*)hv_dynstmt.arr, ",mth_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* ar ind */
        if (GetField_Char(hRls,"ar_ind",&cArInd)) {
DEBUGLOG(("Update:ar_ind = [%c]\n",cArInd));
                sprintf(csBuf,"%c",cArInd);
                strcat((char*)hv_dynstmt.arr, ",mth_ar_ind = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* Sub Status */
        if (GetField_CString(hRls,"sub_status",&csTmp)) {
DEBUGLOG(("Update:sub_status = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_sub_status = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* Txn Code */
        if (GetField_CString(hRls,"txn_code",&csTmp)) {
DEBUGLOG(("Update:txn_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_txn_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* process type */
        if (GetField_CString(hRls,"process_type",&csTmp)) {
DEBUGLOG(("Update:process_type = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_process_type = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* process code */
        if (GetField_CString(hRls,"process_code",&csTmp)) {
DEBUGLOG(("Update:process_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_process_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* req_node_id */
        if (GetField_CString(hRls,"req_node_id",&csTmp)) {
DEBUGLOG(("Update:req_node_id = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_node_id = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* node_ref */
        if (GetField_CString(hRls,"node_ref",&csTmp)) {
DEBUGLOG(("Update:node_ref = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_node_ref = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* host posting date */
        if (GetField_CString(hRls,"host_posting_date",&csTmp)) {
DEBUGLOG(("Update:host_posting_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_host_posting_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* transmission_datetime  */
        if (GetField_CString(hRls,"transmission_datetime",&csTmp)) {
DEBUGLOG(("Update:transmission_datetime = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_transmission_datetime = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* internal code  */
        if (GetField_Int(hRls,"internal_code",&iTmp)) {
DEBUGLOG(("Update:internal_code = [%d]\n",iTmp));
                sprintf(csBuf,"%d",iTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_internal_code = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* response code  */
        if (GetField_CString(hRls,"response_code",&csTmp)) {
DEBUGLOG(("Update:response_code = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_response_code = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* transaction amt   */
        if (GetField_Double(hRls,"txn_amt",&dTmp)) {
DEBUGLOG(("Update:txn_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_transaction_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* txn ccy */
        if (GetField_CString(hRls,"txn_ccy",&csTmp)) {
DEBUGLOG(("Update:txn_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_txn_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* remaining amt   */
        if (GetField_Double(hRls,"remaining_amt",&dTmp)) {
DEBUGLOG(("Update:remaining_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_remaining_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* net amt   */
        if (GetField_Double(hRls,"net_amt",&dTmp)) {
DEBUGLOG(("Update:net_amt = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mth_net_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* net ccy */
        if (GetField_CString(hRls,"net_ccy",&csTmp)) {
DEBUGLOG(("Update:net_ccy = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_net_ccy = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* local tm date */
        if (GetField_CString(hRls,"local_tm_date",&csTmp)) {
DEBUGLOG(("Update:local_tm_date = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_local_tm_date = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* local tm time */
        if (GetField_CString(hRls,"local_tm_time",&csTmp)) {
DEBUGLOG(("Update:local_tm_time = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_local_tm_time = '");
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
                strcat((char*)hv_dynstmt.arr, ",mth_client_ip = '");
                strcat((char*)hv_dynstmt.arr, csTmpIP);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* approval date */
	if (cStatus == PD_COMPLETE && cArInd == PD_ACCEPT) {
DEBUGLOG(("Update:update approval date time \n"));
		char *csApprovalDate;
                char *csApprovalTimeStamp;
		char csRptDate[PD_DATE_LEN + 1];
		char csRptTime[PD_DATE_LEN + 1];
		hash_t  *hRec;

		hRec = (hash_t*) malloc (sizeof(hash_t));
                hash_init(hRec,0);

		DBObjPtr = CreateObj(DBPtr,"DBSystemControl","GetApprovalDT");
		if ((unsigned long)(*DBObjPtr)(hRec) == PD_FOUND) {
			GetField_CString(hRec,"approval_date",&csApprovalDate);
			GetField_CString(hRec,"approval_timestamp",&csApprovalTimeStamp);
DEBUGLOG(("Update:update approval date =[%s]\n",csApprovalDate));
DEBUGLOG(("Update:update approval timestamp =[%s]\n",csApprovalTimeStamp));
		}

		memcpy(csRptDate,csApprovalTimeStamp,PD_DATE_LEN);
		csRptDate[PD_DATE_LEN] = '\0';
		memcpy(csRptTime,&csApprovalTimeStamp[PD_DATE_LEN],PD_DATE_LEN);
		csRptTime[PD_DATE_LEN] = '\0';
DEBUGLOG(("Update:update RPT approval date =[%s]\n",csRptDate));
DEBUGLOG(("Update:update RPT approval time =[%s]\n",csRptTime));
/*approval date */
		strcat((char*)hv_dynstmt.arr, ",mth_approval_date = '");
                strcat((char*)hv_dynstmt.arr, csApprovalDate);
                strcat((char*)hv_dynstmt.arr, "'");

/*approval timestmap */
		strcat((char*)hv_dynstmt.arr, ",mth_approval_timestamp = to_timestamp('");
                strcat((char*)hv_dynstmt.arr, csApprovalTimeStamp);
                strcat((char*)hv_dynstmt.arr, "','YYYYMMDDHH24MISSFF') ");

/*RPT approval date */
		strcat((char*)hv_dynstmt.arr, ",mth_rpt_approval_date = '");
                strcat((char*)hv_dynstmt.arr, csRptDate);
                strcat((char*)hv_dynstmt.arr, "'");

/*RPT approval time */
		strcat((char*)hv_dynstmt.arr, ",mth_rpt_approval_time = '");
                strcat((char*)hv_dynstmt.arr, csRptTime);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

		hash_destroy(hRec);
                FREE_ME(hRec);
	}

/* update user */
        if (GetField_CString(hRls,"update_user",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_update_user = '");
                strcat((char*)hv_dynstmt.arr, csTmp);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* related_txn_id */
        if (GetField_CString(hRls,"related_txn_id",&csTmp)) {
DEBUGLOG(("Update:update_user = [%s]\n",csTmp));
                strcat((char*)hv_dynstmt.arr, ",mth_related_txn_id = '");
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
        sqlstm.sqhstl[0] = (unsigned long )2050;
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

// update txn sub status
//        AddTxnStatusLog(hRls);

DEBUGLOG(("Update Normal Exit\n"));
        return PD_OK;

update_error:
DEBUGLOG(("update_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("MMS Transaction_Update: SP_INTERNAL_ERR \n");
DEBUGLOG(("Update: SP_INTERNAL_ERR \n"));
        return PD_INTERNAL_ERR;
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
		/* varchar         v_sub_status[PD_SUB_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

                /* varchar         v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

                double          v_txn_amt;
                /* varchar         v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

                double          v_remaining_amt;
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

                /* varchar         v_client_ip[PD_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_client_ip;

		int		v_apply_cost;
		/* varchar		v_related_txn_id[PD_TXN_SEQ_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_related_txn_id;

		/* varchar		v_node_id[PD_MMS_NODE_ID_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[6]; } v_node_id;

		/* varchar		v_node_ref[PD_MMS_NODE_REF_LEN +1 ]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_node_ref;

		

		short           ind_org_txn_id = -1;
                short           ind_client_id = -1;
                short           ind_status = -1;
                short           ind_ar_ind = -1;
                short           ind_sub_status = -1;
                short           ind_txn_code = -1;
                short           ind_txn_amt = -1;
                short           ind_txn_ccy = -1;
                short           ind_remaining_amt = -1;
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
                short           ind_client_ip = -1;
		short		ind_apply_cost = -1;
		short		ind_related_txn_id = -1;
		short		ind_node_id = -1;
		short		ind_node_ref = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnHeader txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxnheader CURSOR FOR
                select mth_org_txn_id,
                       mth_status,
                       mth_ar_ind,
                       mth_sub_status,
                       mth_txn_code,
                       mth_transaction_amount,
                       mth_txn_ccy,
                       mth_remaining_amount,
                       mth_net_amount,
                       mth_net_ccy,
                       mth_transmission_datetime,
                       mth_local_tm_date,
                       mth_local_tm_time,
                       mth_tm_date,
                       mth_tm_time,
                       mth_internal_code,
                       mth_response_code,
                       mth_host_posting_date,
                       mth_process_code,
                       mth_process_type,
                       mth_input_channel,
                       mth_client_ip,
		       mth_apply_cost,
		       mth_related_txn_id,
		       mth_node_id,
                       mth_node_ref
                  from mms_txn_header
                 where mth_txn_id = :hv_txn_id; */ 



        /* EXEC SQL OPEN c_cursor_gettxnheader; */ 

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
        if (sqlca.sqlcode < 0) goto gettxnheader_error;
}


        do {
                /* EXEC SQL FETCH c_cursor_gettxnheader
                INTO
                        :v_org_txn_id:ind_org_txn_id,
                        :v_status:ind_status,
                        :v_ar_ind:ind_ar_ind,
                        :v_sub_status:ind_sub_status,
                        :v_txn_code:ind_txn_code,
                        :v_txn_amt:ind_txn_amt,
                        :v_txn_ccy:ind_txn_ccy,
                        :v_remaining_amt:ind_remaining_amt,
                        :v_net_amt:ind_net_amt,
                        :v_net_ccy:ind_net_ccy,
                        :v_transmission_datetime:ind_transmission_datetime,
                        :v_local_tm_date:ind_local_tm_date,
                        :v_local_tm_time:ind_local_tm_time,
                        :v_tm_date:ind_tm_date,
                        :v_tm_time:ind_tm_time,
                        :v_internal_code:ind_internal_code,
                        :v_response_code:ind_response_code,
                        :v_host_posting_date:ind_host_posting_date,
                        :v_process_code:ind_process_code,
                        :v_process_type:ind_process_type,
                        :v_channel_code:ind_channel_code,
                        :v_client_ip:ind_client_ip,
			:v_apply_cost:ind_apply_cost,
			:v_related_txn_id:ind_related_txn_id,
			:v_node_id:ind_node_id,
			:v_node_ref:ind_node_ref; */ 

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
                sqlstm.sqhstv[0] = (unsigned char  *)&v_org_txn_id;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_org_txn_id;
                sqlstm.sqinds[0] = (         int  )0;
                sqlstm.sqharm[0] = (unsigned long )0;
                sqlstm.sqadto[0] = (unsigned short )0;
                sqlstm.sqtdso[0] = (unsigned short )0;
                sqlstm.sqhstv[1] = (unsigned char  *)&v_status;
                sqlstm.sqhstl[1] = (unsigned long )1;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_status;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_ar_ind;
                sqlstm.sqhstl[2] = (unsigned long )1;
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_ar_ind;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_sub_status;
                sqlstm.sqhstl[3] = (unsigned long )6;
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_sub_status;
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
                sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_amt;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_txn_amt;
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
                sqlstm.sqhstv[7] = (unsigned char  *)&v_remaining_amt;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_remaining_amt;
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
                sqlstm.sqhstv[16] = (unsigned char  *)&v_response_code;
                sqlstm.sqhstl[16] = (unsigned long )13;
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_response_code;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_host_posting_date;
                sqlstm.sqhstl[17] = (unsigned long )11;
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_host_posting_date;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_process_code;
                sqlstm.sqhstl[18] = (unsigned long )9;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_process_code;
                sqlstm.sqinds[18] = (         int  )0;
                sqlstm.sqharm[18] = (unsigned long )0;
                sqlstm.sqadto[18] = (unsigned short )0;
                sqlstm.sqtdso[18] = (unsigned short )0;
                sqlstm.sqhstv[19] = (unsigned char  *)&v_process_type;
                sqlstm.sqhstl[19] = (unsigned long )7;
                sqlstm.sqhsts[19] = (         int  )0;
                sqlstm.sqindv[19] = (         short *)&ind_process_type;
                sqlstm.sqinds[19] = (         int  )0;
                sqlstm.sqharm[19] = (unsigned long )0;
                sqlstm.sqadto[19] = (unsigned short )0;
                sqlstm.sqtdso[19] = (unsigned short )0;
                sqlstm.sqhstv[20] = (unsigned char  *)&v_channel_code;
                sqlstm.sqhstl[20] = (unsigned long )6;
                sqlstm.sqhsts[20] = (         int  )0;
                sqlstm.sqindv[20] = (         short *)&ind_channel_code;
                sqlstm.sqinds[20] = (         int  )0;
                sqlstm.sqharm[20] = (unsigned long )0;
                sqlstm.sqadto[20] = (unsigned short )0;
                sqlstm.sqtdso[20] = (unsigned short )0;
                sqlstm.sqhstv[21] = (unsigned char  *)&v_client_ip;
                sqlstm.sqhstl[21] = (unsigned long )28;
                sqlstm.sqhsts[21] = (         int  )0;
                sqlstm.sqindv[21] = (         short *)&ind_client_ip;
                sqlstm.sqinds[21] = (         int  )0;
                sqlstm.sqharm[21] = (unsigned long )0;
                sqlstm.sqadto[21] = (unsigned short )0;
                sqlstm.sqtdso[21] = (unsigned short )0;
                sqlstm.sqhstv[22] = (unsigned char  *)&v_apply_cost;
                sqlstm.sqhstl[22] = (unsigned long )sizeof(int);
                sqlstm.sqhsts[22] = (         int  )0;
                sqlstm.sqindv[22] = (         short *)&ind_apply_cost;
                sqlstm.sqinds[22] = (         int  )0;
                sqlstm.sqharm[22] = (unsigned long )0;
                sqlstm.sqadto[22] = (unsigned short )0;
                sqlstm.sqtdso[22] = (unsigned short )0;
                sqlstm.sqhstv[23] = (unsigned char  *)&v_related_txn_id;
                sqlstm.sqhstl[23] = (unsigned long )19;
                sqlstm.sqhsts[23] = (         int  )0;
                sqlstm.sqindv[23] = (         short *)&ind_related_txn_id;
                sqlstm.sqinds[23] = (         int  )0;
                sqlstm.sqharm[23] = (unsigned long )0;
                sqlstm.sqadto[23] = (unsigned short )0;
                sqlstm.sqtdso[23] = (unsigned short )0;
                sqlstm.sqhstv[24] = (unsigned char  *)&v_node_id;
                sqlstm.sqhstl[24] = (unsigned long )8;
                sqlstm.sqhsts[24] = (         int  )0;
                sqlstm.sqindv[24] = (         short *)&ind_node_id;
                sqlstm.sqinds[24] = (         int  )0;
                sqlstm.sqharm[24] = (unsigned long )0;
                sqlstm.sqadto[24] = (unsigned short )0;
                sqlstm.sqtdso[24] = (unsigned short )0;
                sqlstm.sqhstv[25] = (unsigned char  *)&v_node_ref;
                sqlstm.sqhstl[25] = (unsigned long )19;
                sqlstm.sqhsts[25] = (         int  )0;
                sqlstm.sqindv[25] = (         short *)&ind_node_ref;
                sqlstm.sqinds[25] = (         int  )0;
                sqlstm.sqharm[25] = (unsigned long )0;
                sqlstm.sqadto[25] = (unsigned short )0;
                sqlstm.sqtdso[25] = (unsigned short )0;
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

                if (ind_sub_status>= 0) {
                        v_sub_status.arr[v_sub_status.len] ='\0';
                        PutField_CString(myHash,"sub_status",(const char*)v_sub_status.arr);
DEBUGLOG(("GetTxnHeader sub_status = [%s]\n",v_sub_status.arr));
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

                if (ind_txn_amt < 0)
                        v_txn_amt = 0.0;
                PutField_Double(myHash,"txn_amt",v_txn_amt);
DEBUGLOG(("GetTxnHeader txn_amt = [%f]\n",v_txn_amt));

                if (ind_txn_ccy >= 0) {
                        v_txn_ccy.arr[v_txn_ccy.len] ='\0';
                        PutField_CString(myHash,"txn_ccy",(const char*)v_txn_ccy.arr);
DEBUGLOG(("GetTxnHeader txn_ccy = [%s]\n",v_txn_ccy.arr));
                }
                if (ind_remaining_amt < 0)
                        v_remaining_amt = 0.0;
                PutField_Double(myHash,"remaining_amt",v_remaining_amt);
DEBUGLOG(("GetTxnHeader remaining_amt = [%f]\n",v_remaining_amt));


                if (ind_net_amt < 0)
                        v_net_amt = 0.0;
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
                        v_tm_date.arr[v_local_tm_date.len] ='\0';
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


                if (ind_client_ip>= 0) {
                        v_client_ip.arr[v_client_ip.len] ='\0';
                        PutField_CString(myHash,"ip_addr",(const char*)v_client_ip.arr);
DEBUGLOG(("GetTxnHeader client_ip = [%s]\n",v_client_ip.arr));
                }

                if (ind_apply_cost < 0)
                        v_apply_cost = 0;
                PutField_Int(myHash,"apply_cost",v_apply_cost);
DEBUGLOG(("GetTxnHeader apply_cost = [%d]\n",v_apply_cost));

                if (ind_related_txn_id >= 0) {
                        v_related_txn_id.arr[v_related_txn_id.len] ='\0';
                        PutField_CString(myHash,"related_txn_id",(const char*)v_related_txn_id.arr);
DEBUGLOG(("GetTxnHeader related_txn_id = [%s]\n",v_related_txn_id.arr));
                }

/* node_id */
                if (ind_node_id >= 0) {
                        v_node_id.arr[v_node_id.len] ='\0';
                        PutField_CString(myHash,"node_id",(const char*)v_node_id.arr);
DEBUGLOG(("GetTxnHeader node_id = [%s]\n",v_node_id.arr));
                }
/* node_ref */
                if (ind_node_ref >= 0) {
                        v_node_ref.arr[v_node_ref.len] ='\0';
                        PutField_CString(myHash,"node_ref",(const char*)v_node_ref.arr);
DEBUGLOG(("GetTxnHeader node_ref = [%s]\n",v_node_ref.arr));
                }


                RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxnheader; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )316;
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
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )331;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int AddDetail(const hash_t *hRls)
{
        char            *csTmp;
	double		dTmp;
	char		cTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO adddetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        short           hv_return_value;

        /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;

        /* varchar         hv_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_entity_id;

        /* varchar         hv_related_entity_id[PD_MMS_ENTITY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_related_entity_id;

	double		hv_open_acct_bal;
	double		hv_open_intransit;
	double		hv_open_lien;
	double		hv_open_prepaid;
	double		hv_curr_acct_bal;
	double		hv_curr_intransit;
	double		hv_curr_lien;
	double		hv_curr_prepaid;
	double		hv_provided_fx_rate;
	double		hv_fx_rate;
	double		hv_provided_cost_rate;
	double		hv_provided_fixed_amount;
	double		hv_provided_cost;
	double		hv_cost_rate;
	double		hv_fixed_amount;
	double		hv_cost;
	char		hv_allow_prepaid;
	/* varchar		hv_next_action_ccy[PD_CCY_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_next_action_ccy;

	char		hv_fx_txn;
	/* varchar		hv_remark[PD_REMARK_LEN]; */ 
struct { unsigned short len; unsigned char arr[255]; } hv_remark;

	/* varchar		hv_add_user[PD_USER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_add_user;


	short           ind_txn_id = -1;
	short		ind_entity_id = -1;
	short		ind_related_entity_id = -1;
	short		ind_open_acct_bal = -1;
	short		ind_open_intransit = -1;
	short		ind_open_lien = -1;
	short		ind_open_prepaid = -1;
	short		ind_curr_acct_bal = -1;
	short		ind_curr_intransit = -1;
	short		ind_curr_lien = -1;
	short		ind_curr_prepaid = -1;
	short		ind_provided_fx_rate = -1;
	short		ind_fx_rate = -1;
	short		ind_provided_cost_rate = -1;
	short		ind_provided_fixed_amount = -1;
	short		ind_provided_cost = -1;
	short		ind_cost_rate = -1;
	short		ind_fixed_amount = -1;
	short		ind_allow_prepaid = -1;
	short		ind_next_action_ccy = -1;
	short		ind_fx_txn = -1;
	short		ind_cost = -1;
	short		ind_remark = -1;
	short		ind_add_user = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("AddDetail: Begin\n"));


/* txn_seq */
        if (GetField_CString(hRls,"txn_seq",&csTmp)) {
                hv_txn_id.len = strlen(csTmp);
                memcpy(hv_txn_id.arr,csTmp,hv_txn_id.len);
                ind_txn_id = 0;
DEBUGLOG(("AddDetail:txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));
        }

/* entity_id */
        if (GetField_CString(hRls,"entity_id",&csTmp)) {
                hv_entity_id.len = strlen(csTmp);
                memcpy(hv_entity_id.arr,csTmp,hv_entity_id.len);
                ind_entity_id = 0;
DEBUGLOG(("AddDetail:entity_id = [%.*s]\n",hv_entity_id.len,hv_entity_id.arr));
        }

/* related_entity_id */
        if (GetField_CString(hRls,"related_entity_id",&csTmp)) {
                hv_related_entity_id.len = strlen(csTmp);
                memcpy(hv_related_entity_id.arr,csTmp,hv_related_entity_id.len);
                ind_related_entity_id = 0;
DEBUGLOG(("AddDetail:related_entity_id = [%.*s]\n",hv_related_entity_id.len,hv_related_entity_id.arr));
        }

/* open_acct_bal   */
        if (GetField_Double(hRls,"open_acct_bal",&dTmp)) {
		hv_open_acct_bal = dTmp;
                ind_open_acct_bal = 0;
DEBUGLOG(("AddDetail:open_acct_bal = [%d]\n",hv_open_acct_bal));
	}

/* open_intransit   */
        if (GetField_Double(hRls,"open_intransit",&dTmp)) {
		hv_open_intransit = dTmp;
                ind_open_intransit = 0;
DEBUGLOG(("AddDetail:open_intransit = [%d]\n",hv_open_intransit));
	}

/* open_lien   */
        if (GetField_Double(hRls,"open_lien",&dTmp)) {
		hv_open_lien = dTmp;
                ind_open_lien = 0;
DEBUGLOG(("AddDetail:open_lien = [%d]\n",hv_open_lien));
	}

/* open_lien   */
        if (GetField_Double(hRls,"open_prepaid",&dTmp)) {
		hv_open_prepaid = dTmp;
                ind_open_prepaid = 0;
DEBUGLOG(("AddDetail:open_prepaid = [%d]\n",hv_open_prepaid));
	}

/* curr_acct_bal   */
        if (GetField_Double(hRls,"curr_acct_bal",&dTmp)) {
		hv_curr_acct_bal = dTmp;
                ind_curr_acct_bal = 0;
DEBUGLOG(("AddDetail:curr_acct_bal = [%d]\n",hv_curr_acct_bal));
	}

/* curr_intransit   */
        if (GetField_Double(hRls,"curr_intransit",&dTmp)) {
		hv_curr_intransit = dTmp;
                ind_curr_intransit = 0;
DEBUGLOG(("AddDetail:curr_intransit = [%d]\n",hv_curr_intransit));
	}

/* curr_lien   */
        if (GetField_Double(hRls,"curr_lien",&dTmp)) {
		hv_curr_lien = dTmp;
                ind_curr_lien = 0;
DEBUGLOG(("AddDetail:curr_lien = [%d]\n",hv_curr_lien));
	}

/* curr_lien   */
        if (GetField_Double(hRls,"curr_prepaid",&dTmp)) {
		hv_curr_prepaid = dTmp;
                ind_curr_prepaid = 0;
DEBUGLOG(("AddDetail:curr_prepaid = [%d]\n",hv_curr_prepaid));
	}

/* provided_fx_rate   */
        if (GetField_Double(hRls,"provided_fx_rate",&dTmp)) {
		hv_provided_fx_rate = dTmp;
                ind_provided_fx_rate = 0;
DEBUGLOG(("AddDetail:provided_fx_rate = [%d]\n",hv_provided_fx_rate));
	}

/* fx_rate   */
        if (GetField_Double(hRls,"fx_rate",&dTmp)) {
		hv_fx_rate = dTmp;
                ind_fx_rate = 0;
DEBUGLOG(("AddDetail:fx_rate = [%d]\n",hv_fx_rate));
	}

/* provided_cost_rate   */
        if (GetField_Double(hRls,"provided_cost_rate",&dTmp)) {
		hv_provided_cost_rate = dTmp;
                ind_provided_cost_rate = 0;
DEBUGLOG(("AddDetail:provided_cost_rate = [%d]\n",hv_provided_cost_rate));
	}

/* provided_fixed_amount   */
        if (GetField_Double(hRls,"provided_fixed_amount",&dTmp)) {
		hv_provided_fixed_amount = dTmp;
                ind_provided_fixed_amount = 0;
DEBUGLOG(("AddDetail:provided_fixed_amount = [%d]\n",hv_provided_fixed_amount));
	}

/* provided_cost   */
        if (GetField_Double(hRls,"provided_cost",&dTmp)) {
		hv_provided_cost = dTmp;
                ind_provided_cost = 0;
DEBUGLOG(("AddDetail:provided_cost = [%d]\n",hv_provided_cost));
	}

/* cost_rate   */
        if (GetField_Double(hRls,"cost_rate",&dTmp)) {
		hv_cost_rate = dTmp;
                ind_cost_rate = 0;
DEBUGLOG(("AddDetail:cost_rate = [%d]\n",hv_cost_rate));
	}

/* fixed_amount   */
        if (GetField_Double(hRls,"fixed_amount",&dTmp)) {
		hv_fixed_amount = dTmp;
                ind_fixed_amount = 0;
DEBUGLOG(("AddDetail:fixed_amount = [%d]\n",hv_fixed_amount));
	}

/* cost   */
        if (GetField_Double(hRls,"cost",&dTmp)) {
		hv_cost = dTmp;
                ind_cost = 0;
DEBUGLOG(("AddDetail:cost = [%d]\n",hv_cost));
	}

/* remark */
        if (GetField_CString(hRls,"remark",&csTmp)) {
                hv_remark.len = strlen(csTmp);
                memcpy(hv_remark.arr,csTmp,hv_remark.len);
                ind_remark = 0;
DEBUGLOG(("AddDetail:remark = [%.*s]\n",hv_remark.len,hv_remark.arr));
        }

/* allow_prepaid */
        if (GetField_Char(hRls,"allow_prepaid",&cTmp)) {
                hv_allow_prepaid = cTmp;
                ind_allow_prepaid = 0;
DEBUGLOG(("AddDetail:allow_prepaid = [%c]\n",hv_allow_prepaid));
        }
/* next_action_ccy  */
        if (GetField_CString(hRls,"next_action_ccy",&csTmp)) {
                hv_next_action_ccy.len = strlen(csTmp);
                memcpy(hv_next_action_ccy.arr,csTmp,hv_next_action_ccy.len);
                ind_next_action_ccy = 0;
DEBUGLOG(("AddDetail:next_action_ccy = [%.*s]\n",hv_next_action_ccy.len,hv_next_action_ccy.arr));
        }

/* fx_txn */
        if (GetField_Char(hRls,"fx_txn",&cTmp)) {
                hv_fx_txn = cTmp;
                ind_fx_txn = 0;
DEBUGLOG(("AddDetail:fx_txn = [%c]\n",hv_fx_txn));
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
					:hv_entity_id:ind_entity_id,
					:hv_related_entity_id:ind_related_entity_id,
					:hv_open_acct_bal:ind_open_acct_bal,
					:hv_open_intransit:ind_open_intransit,
					:hv_open_lien:ind_open_lien,
					:hv_open_prepaid:ind_open_prepaid,
					:hv_curr_acct_bal:ind_curr_acct_bal,
					:hv_curr_intransit:ind_curr_intransit,
					:hv_curr_lien:ind_curr_lien,
					:hv_curr_prepaid:ind_curr_prepaid,
					:hv_provided_fx_rate:ind_provided_fx_rate,
					:hv_fx_rate:ind_fx_rate,
					:hv_provided_cost_rate:ind_provided_cost_rate,
					:hv_provided_fixed_amount:ind_provided_fixed_amount,
					:hv_provided_cost:ind_provided_cost,
					:hv_cost_rate:ind_cost_rate,
					:hv_fixed_amount:ind_fixed_amount,
					:hv_allow_prepaid:ind_allow_prepaid,
					:hv_next_action_ccy:ind_next_action_ccy,
					:hv_fx_txn:ind_fx_txn,
					:hv_cost:ind_cost,
					:hv_remark:ind_remark,
					:hv_add_user:ind_add_user
					);
                END;
        END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_mms_txn_detail_insert ( :hv_tx\
n_id:ind_txn_id , :hv_entity_id:ind_entity_id , :hv_related_entity_id:ind_rel\
ated_entity_id , :hv_open_acct_bal:ind_open_acct_bal , :hv_open_intransit:ind\
_open_intransit , :hv_open_lien:ind_open_lien , :hv_open_prepaid:ind_open_pre\
paid , :hv_curr_acct_bal:ind_curr_acct_bal , :hv_curr_intransit:ind_curr_intr\
ansit , :hv_curr_lien:ind_curr_lien , :hv_curr_prepaid:ind_curr_prepaid , :hv\
_provided_fx_rate:ind_provided_fx_rate , :hv_fx_rate:ind_fx_rate , :hv_provid\
ed_cost_rate:ind_provided_cost_rate , :hv_provided_fixed_amount:ind_provided_\
fixed_amount , :hv_provided_cost:ind_provided_cost , :hv_cost_rate:ind_cost_r\
ate , :hv_fixed_amount:ind_fixed_amount , :hv_allow_prepaid:ind_allow_prepaid\
 , :hv_next_action_ccy:ind_next_action_ccy , :hv_fx_txn:ind_fx_txn , :hv_cost\
:ind_cost , :hv_remark:ind_remark , :hv_add_user:ind_add_user ) ; END ;";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )346;
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
 sqlstm.sqhstl[2] = (unsigned long )22;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_entity_id;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_related_entity_id;
 sqlstm.sqhstl[3] = (unsigned long )22;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_related_entity_id;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_open_acct_bal;
 sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_open_acct_bal;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_open_intransit;
 sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_open_intransit;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_open_lien;
 sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_open_lien;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_open_prepaid;
 sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_open_prepaid;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_curr_acct_bal;
 sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_curr_acct_bal;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_curr_intransit;
 sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_curr_intransit;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_curr_lien;
 sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_curr_lien;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_curr_prepaid;
 sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_curr_prepaid;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_provided_fx_rate;
 sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_provided_fx_rate;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_fx_rate;
 sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_fx_rate;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_provided_cost_rate;
 sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_provided_cost_rate;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_provided_fixed_amount;
 sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_provided_fixed_amount;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_provided_cost;
 sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_provided_cost;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_cost_rate;
 sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_cost_rate;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_fixed_amount;
 sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_fixed_amount;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_allow_prepaid;
 sqlstm.sqhstl[19] = (unsigned long )1;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_allow_prepaid;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_next_action_ccy;
 sqlstm.sqhstl[20] = (unsigned long )5;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_next_action_ccy;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_fx_txn;
 sqlstm.sqhstl[21] = (unsigned long )1;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_fx_txn;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_cost;
 sqlstm.sqhstl[22] = (unsigned long )sizeof(double);
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_cost;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_remark;
 sqlstm.sqhstl[23] = (unsigned long )257;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_remark;
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
        char*   csPtr;
        char*   csBuf;
	char	cTmp;
        char*   csTxnId;
	double	dTmp;

        /* EXEC SQL WHENEVER SQLERROR GOTO update_detail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 


        /* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("UpdateDetail: Begin\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);
        strcpy((char*)hv_dynstmt.arr,"update mms_txn_detail set mtd_update_timestamp  = sysdate");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

        GetField_CString(hRls,"txn_seq",&csTxnId);
DEBUGLOG(("UpdateDetail:txn_id = [%s]\n",csTxnId));

/* entity_id */
        if (GetField_CString(hRls,"entity_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:entity_id = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",mtd_entity_id = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* related_entity_id */
        if (GetField_CString(hRls,"related_entity_id",&csPtr)) {
DEBUGLOG(("UpdateDetail:related_entity_id = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",mtd_related_entity_id = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_acct_bal  */
        if (GetField_Double(hRls,"open_acct_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_acct_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_open_acct_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_intransit  */
        if (GetField_Double(hRls,"open_intransit",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_intransit = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_open_intransit = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_lien  */
        if (GetField_Double(hRls,"open_lien",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_lien = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_open_lien = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* open_prepaid  */
        if (GetField_Double(hRls,"open_prepaid",&dTmp)) {
DEBUGLOG(("UpdateDetail:open_prepaid = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_open_prepaid = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* curr_acct_bal  */
        if (GetField_Double(hRls,"curr_acct_bal",&dTmp)) {
DEBUGLOG(("UpdateDetail:curr_acct_bal = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_curr_acct_bal = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* curr_intransit  */
        if (GetField_Double(hRls,"curr_intransit",&dTmp)) {
DEBUGLOG(("UpdateDetail:curr_intransit = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_curr_intransit = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* curr_lien  */
        if (GetField_Double(hRls,"curr_lien",&dTmp)) {
DEBUGLOG(("UpdateDetail:curr_lien = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_curr_lien = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* curr_prepaid  */
        if (GetField_Double(hRls,"curr_prepaid",&dTmp)) {
DEBUGLOG(("UpdateDetail:curr_prepaid = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_curr_prepaid = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* provided_fx_rate  */
        if (GetField_Double(hRls,"provided_fx_rate",&dTmp)) {
DEBUGLOG(("UpdateDetail:provided_fx_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_provided_fx_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* fx_rate  */
        if (GetField_Double(hRls,"fx_rate",&dTmp)) {
DEBUGLOG(("UpdateDetail:fx_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_fx_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* provided_cost_rate  */
        if (GetField_Double(hRls,"provided_cost_rate",&dTmp)) {
DEBUGLOG(("UpdateDetail:provided_cost_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_provided_cost_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* provided_fixed_amount  */
        if (GetField_Double(hRls,"provided_fixed_amount",&dTmp)) {
DEBUGLOG(("UpdateDetail:provided_fixed_amount = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_provided_fixed_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* provided_cost  */
        if (GetField_Double(hRls,"provided_cost",&dTmp)) {
DEBUGLOG(("UpdateDetail:provided_cost = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_provided_cost = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* cost_rate  */
        if (GetField_Double(hRls,"cost_rate",&dTmp)) {
DEBUGLOG(("UpdateDetail:cost_rate = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_cost_rate = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* fixed_amount  */
        if (GetField_Double(hRls,"fixed_amount",&dTmp)) {
DEBUGLOG(("UpdateDetail:fixed_amount = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_fixed_amount = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* cost  */
        if (GetField_Double(hRls,"cost",&dTmp)) {
DEBUGLOG(("UpdateDetail:cost = [%lf]\n",dTmp));
                sprintf(csBuf,"%f",dTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_cost = ");
                strcat((char*)hv_dynstmt.arr, csBuf);
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* allow prepiad */
        if (GetField_Char(hRls,"allow_prepaid",&cTmp)) {
DEBUGLOG(("UpdateDetail:allow_prepaid = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_allow_prepaid = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* next_action_ccy */
        if (GetField_CString(hRls,"next_action_ccy",&csPtr)) {
DEBUGLOG(("UpdateDetail:unext_action_ccy = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",mtd_next_action_ccy = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* fx_txn */
        if (GetField_Char(hRls,"fx_txn",&cTmp)) {
DEBUGLOG(("UpdateDetail:fx_txn = [%c]\n",cTmp));
                sprintf(csBuf,"%c",cTmp);
                strcat((char*)hv_dynstmt.arr, ",mtd_fx_txn = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* remark  */
        if (GetField_CString(hRls,"remark",&csPtr)) {
DEBUGLOG(("UpdateDetail:remark = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",mtd_remark = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }

/* update user */
        if (GetField_CString(hRls,"update_user",&csPtr)) {
DEBUGLOG(("UpdateDetail:update_user = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, ",mtd_update_user = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


strcat((char *)hv_dynstmt.arr, " WHERE mtd_txn_id = '");
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
        sqlstm.offset = (unsigned int  )461;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
        sqlstm.sqhstl[0] = (unsigned long )2050;
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
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )480;
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

ERRLOG("MMS_Transaction_UpdateDetail: SP_INTERNAL_ERR\n");
DEBUGLOG(("UpdateDetail: SP_INTERNAL_ERR\n"));
        return PD_INTERNAL_ERR;
}


int GetTxnDetail(const char* csTxnID,
                recordset_t* myRec)
{

        hash_t *myHash;
        /* EXEC SQL WHENEVER SQLERROR GOTO gettxndetail_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar         hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


                /* varchar         v_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_entity_id;

                /* varchar         v_related_entity_id[PD_MMS_ENTITY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_related_entity_id;

		double		v_open_acct_bal;
		double		v_open_intransit;
		double		v_open_lien;
		double		v_open_prepaid;
		double		v_curr_acct_bal;
		double		v_curr_intransit;
		double		v_curr_lien;
		double		v_curr_prepaid;
		double		v_provided_fx_rate;
		double		v_fx_rate;
		double		v_provided_cost_rate;
		double		v_provided_fixed_amount;
		double		v_provided_cost;
		double		v_cost_rate;
		double		v_fixed_amount;
		double		v_cost;
		/* varchar		v_next_action_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_next_action_ccy;

		/* varchar		v_remark[PD_REMARK_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[256]; } v_remark;


		short		ind_entity_id;
		short		ind_related_entity_id;
		short		ind_open_acct_bal;
		short		ind_open_intransit;
		short		ind_open_lien;
		short		ind_open_prepaid;
		short		ind_curr_acct_bal;
		short		ind_curr_intransit;
		short		ind_curr_lien;
		short		ind_curr_prepaid;
		short		ind_provided_fx_rate;
		short		ind_fx_rate;
		short		ind_provided_cost_rate;
		short		ind_provided_fixed_amount;
		short		ind_provided_cost;
		short		ind_cost_rate;
		short		ind_fixed_amount;
		short		ind_cost;
		short		ind_next_action_ccy;
		short		ind_remark;


	/* EXEC SQL END DECLARE SECTION; */ 


        hv_txn_id.len = strlen(csTxnID);
        memcpy(hv_txn_id.arr,csTxnID,hv_txn_id.len);
DEBUGLOG(("GetTxnDetail txn_id = [%.*s]\n",hv_txn_id.len,hv_txn_id.arr));

        /* EXEC SQL DECLARE c_cursor_gettxndetail CURSOR FOR
                select
                        mtd_entity_id,
                        mtd_related_entity_id,
			mtd_open_acct_bal,
			mtd_open_intransit,
			mtd_open_lien,
			mtd_open_prepaid,
			mtd_curr_acct_bal,
			mtd_curr_intransit,
			mtd_curr_lien,
			mtd_curr_prepaid,
			mtd_provided_fx_rate,
			mtd_fx_rate,
			mtd_provided_cost_rate,
			mtd_provided_fixed_amount,
			mtd_provided_cost,
			mtd_cost_rate,
			mtd_fixed_amount,
			mtd_cost,
			mtd_next_action_ccy,
			mtd_remark
                  from mms_txn_detail
                 where mtd_txn_id = :hv_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_gettxndetail; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )495;
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
			:v_entity_id:ind_entity_id,
			:v_related_entity_id:ind_related_entity_id,
			:v_open_acct_bal:ind_open_acct_bal,
			:v_open_intransit:ind_open_intransit,
			:v_open_lien:ind_open_lien,
			:v_open_prepaid:ind_open_prepaid,
			:v_curr_acct_bal:ind_curr_acct_bal,
			:v_curr_intransit:ind_curr_intransit,
			:v_curr_lien:ind_curr_lien,
			:v_curr_prepaid:ind_curr_prepaid,
			:v_provided_fx_rate:ind_provided_fx_rate,
			:v_fx_rate:ind_fx_rate,
			:v_provided_cost_rate:ind_provided_cost_rate,
			:v_provided_fixed_amount:ind_provided_fixed_amount,
			:v_provided_cost:ind_provided_cost,
			:v_cost_rate:ind_cost_rate,
			:v_fixed_amount:ind_fixed_amount,
			:v_cost:ind_cost,
			:v_next_action_ccy:ind_next_action_ccy,
			:v_remark:ind_remark; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )514;
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
                sqlstm.sqhstv[1] = (unsigned char  *)&v_related_entity_id;
                sqlstm.sqhstl[1] = (unsigned long )23;
                sqlstm.sqhsts[1] = (         int  )0;
                sqlstm.sqindv[1] = (         short *)&ind_related_entity_id;
                sqlstm.sqinds[1] = (         int  )0;
                sqlstm.sqharm[1] = (unsigned long )0;
                sqlstm.sqadto[1] = (unsigned short )0;
                sqlstm.sqtdso[1] = (unsigned short )0;
                sqlstm.sqhstv[2] = (unsigned char  *)&v_open_acct_bal;
                sqlstm.sqhstl[2] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[2] = (         int  )0;
                sqlstm.sqindv[2] = (         short *)&ind_open_acct_bal;
                sqlstm.sqinds[2] = (         int  )0;
                sqlstm.sqharm[2] = (unsigned long )0;
                sqlstm.sqadto[2] = (unsigned short )0;
                sqlstm.sqtdso[2] = (unsigned short )0;
                sqlstm.sqhstv[3] = (unsigned char  *)&v_open_intransit;
                sqlstm.sqhstl[3] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[3] = (         int  )0;
                sqlstm.sqindv[3] = (         short *)&ind_open_intransit;
                sqlstm.sqinds[3] = (         int  )0;
                sqlstm.sqharm[3] = (unsigned long )0;
                sqlstm.sqadto[3] = (unsigned short )0;
                sqlstm.sqtdso[3] = (unsigned short )0;
                sqlstm.sqhstv[4] = (unsigned char  *)&v_open_lien;
                sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[4] = (         int  )0;
                sqlstm.sqindv[4] = (         short *)&ind_open_lien;
                sqlstm.sqinds[4] = (         int  )0;
                sqlstm.sqharm[4] = (unsigned long )0;
                sqlstm.sqadto[4] = (unsigned short )0;
                sqlstm.sqtdso[4] = (unsigned short )0;
                sqlstm.sqhstv[5] = (unsigned char  *)&v_open_prepaid;
                sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[5] = (         int  )0;
                sqlstm.sqindv[5] = (         short *)&ind_open_prepaid;
                sqlstm.sqinds[5] = (         int  )0;
                sqlstm.sqharm[5] = (unsigned long )0;
                sqlstm.sqadto[5] = (unsigned short )0;
                sqlstm.sqtdso[5] = (unsigned short )0;
                sqlstm.sqhstv[6] = (unsigned char  *)&v_curr_acct_bal;
                sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[6] = (         int  )0;
                sqlstm.sqindv[6] = (         short *)&ind_curr_acct_bal;
                sqlstm.sqinds[6] = (         int  )0;
                sqlstm.sqharm[6] = (unsigned long )0;
                sqlstm.sqadto[6] = (unsigned short )0;
                sqlstm.sqtdso[6] = (unsigned short )0;
                sqlstm.sqhstv[7] = (unsigned char  *)&v_curr_intransit;
                sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[7] = (         int  )0;
                sqlstm.sqindv[7] = (         short *)&ind_curr_intransit;
                sqlstm.sqinds[7] = (         int  )0;
                sqlstm.sqharm[7] = (unsigned long )0;
                sqlstm.sqadto[7] = (unsigned short )0;
                sqlstm.sqtdso[7] = (unsigned short )0;
                sqlstm.sqhstv[8] = (unsigned char  *)&v_curr_lien;
                sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[8] = (         int  )0;
                sqlstm.sqindv[8] = (         short *)&ind_curr_lien;
                sqlstm.sqinds[8] = (         int  )0;
                sqlstm.sqharm[8] = (unsigned long )0;
                sqlstm.sqadto[8] = (unsigned short )0;
                sqlstm.sqtdso[8] = (unsigned short )0;
                sqlstm.sqhstv[9] = (unsigned char  *)&v_curr_prepaid;
                sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[9] = (         int  )0;
                sqlstm.sqindv[9] = (         short *)&ind_curr_prepaid;
                sqlstm.sqinds[9] = (         int  )0;
                sqlstm.sqharm[9] = (unsigned long )0;
                sqlstm.sqadto[9] = (unsigned short )0;
                sqlstm.sqtdso[9] = (unsigned short )0;
                sqlstm.sqhstv[10] = (unsigned char  *)&v_provided_fx_rate;
                sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[10] = (         int  )0;
                sqlstm.sqindv[10] = (         short *)&ind_provided_fx_rate;
                sqlstm.sqinds[10] = (         int  )0;
                sqlstm.sqharm[10] = (unsigned long )0;
                sqlstm.sqadto[10] = (unsigned short )0;
                sqlstm.sqtdso[10] = (unsigned short )0;
                sqlstm.sqhstv[11] = (unsigned char  *)&v_fx_rate;
                sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[11] = (         int  )0;
                sqlstm.sqindv[11] = (         short *)&ind_fx_rate;
                sqlstm.sqinds[11] = (         int  )0;
                sqlstm.sqharm[11] = (unsigned long )0;
                sqlstm.sqadto[11] = (unsigned short )0;
                sqlstm.sqtdso[11] = (unsigned short )0;
                sqlstm.sqhstv[12] = (unsigned char  *)&v_provided_cost_rate;
                sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[12] = (         int  )0;
                sqlstm.sqindv[12] = (         short *)&ind_provided_cost_rate;
                sqlstm.sqinds[12] = (         int  )0;
                sqlstm.sqharm[12] = (unsigned long )0;
                sqlstm.sqadto[12] = (unsigned short )0;
                sqlstm.sqtdso[12] = (unsigned short )0;
                sqlstm.sqhstv[13] = (unsigned char  *)&v_provided_fixed_amount;
                sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[13] = (         int  )0;
                sqlstm.sqindv[13] = (         short *)&ind_provided_fixed_amount;
                sqlstm.sqinds[13] = (         int  )0;
                sqlstm.sqharm[13] = (unsigned long )0;
                sqlstm.sqadto[13] = (unsigned short )0;
                sqlstm.sqtdso[13] = (unsigned short )0;
                sqlstm.sqhstv[14] = (unsigned char  *)&v_provided_cost;
                sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[14] = (         int  )0;
                sqlstm.sqindv[14] = (         short *)&ind_provided_cost;
                sqlstm.sqinds[14] = (         int  )0;
                sqlstm.sqharm[14] = (unsigned long )0;
                sqlstm.sqadto[14] = (unsigned short )0;
                sqlstm.sqtdso[14] = (unsigned short )0;
                sqlstm.sqhstv[15] = (unsigned char  *)&v_cost_rate;
                sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[15] = (         int  )0;
                sqlstm.sqindv[15] = (         short *)&ind_cost_rate;
                sqlstm.sqinds[15] = (         int  )0;
                sqlstm.sqharm[15] = (unsigned long )0;
                sqlstm.sqadto[15] = (unsigned short )0;
                sqlstm.sqtdso[15] = (unsigned short )0;
                sqlstm.sqhstv[16] = (unsigned char  *)&v_fixed_amount;
                sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[16] = (         int  )0;
                sqlstm.sqindv[16] = (         short *)&ind_fixed_amount;
                sqlstm.sqinds[16] = (         int  )0;
                sqlstm.sqharm[16] = (unsigned long )0;
                sqlstm.sqadto[16] = (unsigned short )0;
                sqlstm.sqtdso[16] = (unsigned short )0;
                sqlstm.sqhstv[17] = (unsigned char  *)&v_cost;
                sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
                sqlstm.sqhsts[17] = (         int  )0;
                sqlstm.sqindv[17] = (         short *)&ind_cost;
                sqlstm.sqinds[17] = (         int  )0;
                sqlstm.sqharm[17] = (unsigned long )0;
                sqlstm.sqadto[17] = (unsigned short )0;
                sqlstm.sqtdso[17] = (unsigned short )0;
                sqlstm.sqhstv[18] = (unsigned char  *)&v_next_action_ccy;
                sqlstm.sqhstl[18] = (unsigned long )6;
                sqlstm.sqhsts[18] = (         int  )0;
                sqlstm.sqindv[18] = (         short *)&ind_next_action_ccy;
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


/* entity id */
                if (ind_entity_id  >=  0) {
                        v_entity_id.arr[v_entity_id.len] = '\0';
                        PutField_CString(myHash,"entity_id",(const char*)v_entity_id.arr);
DEBUGLOG(("GetTxnDetail entity_id = [%s]\n",v_entity_id.arr));
                }

/* related entity id */
                if (ind_related_entity_id  >=  0) {
                        v_related_entity_id.arr[v_related_entity_id.len] = '\0';
                        PutField_CString(myHash,"related_entity_id",(const char*)v_related_entity_id.arr);
DEBUGLOG(("GetTxnDetail related_entity_id = [%s]\n",v_related_entity_id.arr));
                }

/* open_acct_bal */
                if (ind_open_acct_bal < 0)
                        v_open_acct_bal = 0.0;
                PutField_Double(myHash,"open_acct_bal",v_open_acct_bal);
DEBUGLOG(("GetTxnDetail open_acct_bal = [%f]\n",v_open_acct_bal));

/* open_intransit */
                if (ind_open_intransit < 0)
                        v_open_intransit = 0.0;
                PutField_Double(myHash,"open_intransit",v_open_intransit);
DEBUGLOG(("GetTxnDetail open_intransit = [%f]\n",v_open_intransit));

/* open_lien */
                if (ind_open_lien < 0)
                        v_open_lien = 0.0;
                PutField_Double(myHash,"open_lien",v_open_lien);
DEBUGLOG(("GetTxnDetail open_lien = [%f]\n",v_open_lien));

/* open_prepaid */
                if (ind_open_prepaid < 0)
                        v_open_prepaid = 0.0;
                PutField_Double(myHash,"open_prepaid",v_open_prepaid);
DEBUGLOG(("GetTxnDetail open_prepaid = [%f]\n",v_open_prepaid));

/* curr_acct_bal */
                if (ind_curr_acct_bal < 0)
                        v_curr_acct_bal = 0.0;
                PutField_Double(myHash,"curr_acct_bal",v_curr_acct_bal);
DEBUGLOG(("GetTxnDetail curr_acct_bal = [%f]\n",v_curr_acct_bal));

/* curr_intransit */
                if (ind_curr_intransit < 0)
                        v_curr_intransit = 0.0;
                PutField_Double(myHash,"curr_intransit",v_curr_intransit);
DEBUGLOG(("GetTxnDetail curr_intransit = [%f]\n",v_curr_intransit));

/* curr_lien */
                if (ind_curr_lien < 0)
                        v_curr_lien = 0.0;
                PutField_Double(myHash,"curr_lien",v_curr_lien);
DEBUGLOG(("GetTxnDetail curr_lien = [%f]\n",v_curr_lien));

/* curr_prepaid */
                if (ind_curr_prepaid < 0)
                        v_curr_prepaid = 0.0;
                PutField_Double(myHash,"curr_prepaid",v_curr_prepaid);
DEBUGLOG(("GetTxnDetail curr_prepaid = [%f]\n",v_curr_prepaid));

/* provided_fx_rate */
                if (ind_provided_fx_rate < 0)
                        v_provided_fx_rate = 0.0;
                PutField_Double(myHash,"provided_fx_rate",v_provided_fx_rate);
DEBUGLOG(("GetTxnDetail provided_fx_rate = [%f]\n",v_provided_fx_rate));

/* fx_rate */
                if (ind_fx_rate < 0)
                        v_fx_rate = 0.0;
                PutField_Double(myHash,"fx_rate",v_fx_rate);
DEBUGLOG(("GetTxnDetail fx_rate = [%f]\n",v_fx_rate));

/* provided_cost_rate */
                if (ind_provided_cost_rate < 0)
                        v_provided_cost_rate = 0.0;
                PutField_Double(myHash,"provided_cost_rate",v_provided_cost_rate);
DEBUGLOG(("GetTxnDetail provided_cost_rate = [%f]\n",v_provided_cost_rate));

/* provided_fixed_amount */
                if (ind_provided_fixed_amount < 0)
                        v_provided_fixed_amount = 0.0;
                PutField_Double(myHash,"provided_fixed_amount",v_provided_fixed_amount);
DEBUGLOG(("GetTxnDetail provided_fixed_amount = [%f]\n",v_provided_fixed_amount));

/* provided_cost */
                if (ind_provided_cost < 0)
                        v_provided_cost = 0.0;
                PutField_Double(myHash,"provided_cost",v_provided_cost);
DEBUGLOG(("GetTxnDetail provided_cost = [%f]\n",v_provided_cost));

/* cost_rate */
                if (ind_cost_rate < 0)
                        v_cost_rate = 0.0;
                PutField_Double(myHash,"cost_rate",v_cost_rate);
DEBUGLOG(("GetTxnDetail cost_rate = [%f]\n",v_cost_rate));

/* fixed_amount */
                if (ind_fixed_amount < 0)
                        v_fixed_amount = 0.0;
                PutField_Double(myHash,"fixed_amount",v_fixed_amount);
DEBUGLOG(("GetTxnDetail fixed_amount = [%f]\n",v_fixed_amount));

/* cost */
                if (ind_cost < 0)
                        v_cost = 0.0;
                PutField_Double(myHash,"cost",v_cost);
DEBUGLOG(("GetTxnDetail cost = [%f]\n",v_cost));
/* next_action_ccy */
                if (ind_next_action_ccy  >=  0) {
                        v_next_action_ccy.arr[v_next_action_ccy.len] = '\0';
                        PutField_CString(myHash,"next_action_ccy",(const char*)v_next_action_ccy.arr);
DEBUGLOG(("GetTxnDetail next_action_ccy = [%s]\n",v_next_action_ccy.arr));
                }

		RecordSet_Add(myRec,myHash);
        }
        while(PD_TRUE);

        /* EXEC SQL CLOSE c_cursor_gettxndetail; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )609;
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
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )624;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


        return PD_ERR;
}



int MatchNodeRef(const char* csNodeID,
                     const char* csNodeRef)
{
        /* EXEC SQL WHENEVER SQLERROR GOTO matchnoderef_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                short           hv_return_value;
                /* varchar         hv_node_id[PD_MMS_NODE_ID_LEN]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_node_id;

                /* varchar         hv_node_ref[PD_MMS_NODE_REF_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_node_ref;


    
        /* EXEC SQL END DECLARE SECTION; */ 


        hv_node_id.len = strlen(csNodeID);
        memcpy(hv_node_id.arr,csNodeID,hv_node_id.len);
DEBUGLOG(("MatchNodeRef node_id = [%.*s]\n",hv_node_id.len,hv_node_id.arr));
    
        hv_node_ref.len = strlen(csNodeRef);
        memcpy(hv_node_ref.arr,csNodeRef,hv_node_ref.len);
DEBUGLOG(("MatchNodeRef merchant_ref = [%.*s]\n",hv_node_ref.len,hv_node_ref.arr));

        /* EXEC SQL EXECUTE
                BEGIN
                        :hv_return_value := sp_mms_txn_matchnoderef(:hv_node_id,
                                                                     :hv_node_ref);
                END;
        END-EXEC; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "begin :hv_return_value := sp_mms_txn_matchnoderef ( \
:hv_node_id , :hv_node_ref ) ; END ;";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )639;
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
        sqlstm.sqhstv[1] = (unsigned char  *)&hv_node_id;
        sqlstm.sqhstl[1] = (unsigned long )7;
        sqlstm.sqhsts[1] = (         int  )0;
        sqlstm.sqindv[1] = (         short *)0;
        sqlstm.sqinds[1] = (         int  )0;
        sqlstm.sqharm[1] = (unsigned long )0;
        sqlstm.sqadto[1] = (unsigned short )0;
        sqlstm.sqtdso[1] = (unsigned short )0;
        sqlstm.sqhstv[2] = (unsigned char  *)&hv_node_ref;
        sqlstm.sqhstl[2] = (unsigned long )18;
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
        if (sqlca.sqlcode < 0) goto matchnoderef_error;
}



        if (hv_return_value > 0)  {

DEBUGLOG(("MatchNodeRef Found\n"));
                return PD_FOUND;
        }
        else {
DEBUGLOG(("MatchNodeRef Not Found\n"));
                return PD_NOT_FOUND;
        }


matchnoderef_error:
DEBUGLOG(("matchnoderef_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_NOT_FOUND;
}

int MatchTxnStatusForUpdate(const hash_t* hReq)
{
	int	iRet = PD_NOT_FOUND;
	char	*csBuf;
	char	*csPtr;
	char	cPtr;
	int	iSubStatusCnt = 0,i;

        /* EXEC SQL WHENEVER SQLERROR GOTO matchtxnstatus_error; */ 

        /* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

    
        /* EXEC SQL BEGIN DECLARE SECTION; */ 

                /* varchar	        v_txn_seq[PD_TXN_SEQ_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_seq;

		/* varchar         hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;


		short		ind_txn_seq = -1;

        /* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("MatchTxnStatusForUpdate: Begin\n"));
        csBuf = (char*) malloc (PD_TMP_BUF_LEN);
        strcpy((char*)hv_dynstmt.arr,"select mth_txn_id from mms_txn_header where ");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

/* txn_seq */
        if (GetField_CString(hReq,"txn_seq",&csPtr)) {
DEBUGLOG(("MatchTxnStatusForUpdate:txn_id = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, " mth_txn_id = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }
/* txn_code */
        if (GetField_CString(hReq,"txn_code",&csPtr)) {
DEBUGLOG(("MatchTxnStatusForUpdate:txn_code = [%s]\n",csPtr));
                strcat((char*)hv_dynstmt.arr, " and  mth_txn_code = '");
                strcat((char*)hv_dynstmt.arr, csPtr);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
        }


/* status */
	if (GetField_Char(hReq,"status",&cPtr)) {
DEBUGLOG(("MatchTxnStatusForUpdate:status = [%c]\n",cPtr));
		sprintf(csBuf,"%c",cPtr);
                strcat((char*)hv_dynstmt.arr, " and mth_status = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

/* ar_ind */
	if (GetField_Char(hReq,"ar_ind",&cPtr)) {
DEBUGLOG(("MatchTxnStatusForUpdate:status = [%c]\n",cPtr));
		sprintf(csBuf,"%c",cPtr);
                strcat((char*)hv_dynstmt.arr, " and mth_ar_ind = '");
                strcat((char*)hv_dynstmt.arr, csBuf);
                strcat((char*)hv_dynstmt.arr, "'");
                hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
	}

	GetField_Int(hReq,"sub_status_cnt",&iSubStatusCnt);
DEBUGLOG(("MatchTxnStatusForUpdate:sub_status_cnt = [%d]\n",iSubStatusCnt));

	for (i = 0 ; i < iSubStatusCnt; i++) {
		sprintf(csBuf,"sub_status_%d",i);

		if (GetField_CString(hReq,csBuf,&csPtr)) {
DEBUGLOG(("MatchTxnStatusForUpdate: [%s] = [%s]\n",csBuf,csPtr));
			if (i  == 0) 
                		strcat((char*)hv_dynstmt.arr, "and mth_sub_status in ('");
			else 
                		strcat((char*)hv_dynstmt.arr, "','");
                	strcat((char*)hv_dynstmt.arr, csPtr);
			if (i  ==  (iSubStatusCnt -1)) 
                		strcat((char*)hv_dynstmt.arr, "')");
                	hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);
		}
	}
        strcat((char*)hv_dynstmt.arr, " for update");
        hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

DEBUGLOG(("MatchTxnStatusForUpdate [%s]\n",hv_dynstmt.arr));
	/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 31;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )666;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_dynstmt;
 sqlstm.sqhstl[0] = (unsigned long )2050;
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
 if (sqlca.sqlcode < 0) goto matchtxnstatus_error;
}


        /* EXEC SQL DECLARE C CURSOR FOR  PS; */ 


        /* EXEC SQL OPEN C; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )685;
        sqlstm.selerr = (unsigned short)1;
        sqlstm.cud = sqlcud0;
        sqlstm.sqlest = (unsigned char  *)&sqlca;
        sqlstm.sqlety = (unsigned short)4352;
        sqlstm.occurs = (unsigned int  )0;
        sqlstm.sqcmod = (unsigned int )0;
        sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
        if (sqlca.sqlcode < 0) goto matchtxnstatus_error;
}


        do {
                /* EXEC SQL FETCH C
                INTO
                        :v_txn_seq:ind_txn_seq; */ 

{
                struct sqlexd sqlstm;
                sqlstm.sqlvsn = 12;
                sqlstm.arrsiz = 31;
                sqlstm.sqladtp = &sqladt;
                sqlstm.sqltdsp = &sqltds;
                sqlstm.iters = (unsigned int  )1;
                sqlstm.offset = (unsigned int  )700;
                sqlstm.selerr = (unsigned short)1;
                sqlstm.cud = sqlcud0;
                sqlstm.sqlest = (unsigned char  *)&sqlca;
                sqlstm.sqlety = (unsigned short)4352;
                sqlstm.occurs = (unsigned int  )0;
                sqlstm.sqfoff = (         int )0;
                sqlstm.sqfmod = (unsigned int )2;
                sqlstm.sqhstv[0] = (unsigned char  *)&v_txn_seq;
                sqlstm.sqhstl[0] = (unsigned long )19;
                sqlstm.sqhsts[0] = (         int  )0;
                sqlstm.sqindv[0] = (         short *)&ind_txn_seq;
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
                if (sqlca.sqlcode < 0) goto matchtxnstatus_error;
}



                if (SQLCODE == SQL_NOT_FOUND) {
                        break;
                }

                if (ind_txn_seq >= 0 ) {
DEBUGLOG(("Find: recourd found\n"));
                       	iRet = FOUND;
                }
        }
        while(PD_TRUE);

	return iRet;
matchtxnstatus_error:
DEBUGLOG(("matchtxnstatus_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_NOT_FOUND;
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


/* txn_code */
        hv_txn_code.len = strlen(csTxnCode);
        memcpy(hv_txn_code.arr, csTxnCode, hv_txn_code.len);
DEBUGLOG(("ChkTxnCodeExist = [%.*s]\n",hv_txn_code.len,hv_txn_code.arr));

        /* EXEC SQL
                SELECT count(1)
                   INTO :v_no_of_record:ind_no_of_record
                   FROM mms_txn_header
                  WHERE mth_txn_code = :hv_txn_code
		    //AND mth_action is NULL
                    AND rownum = 1; */ 

{
        struct sqlexd sqlstm;
        sqlstm.sqlvsn = 12;
        sqlstm.arrsiz = 31;
        sqlstm.sqladtp = &sqladt;
        sqlstm.sqltdsp = &sqltds;
        sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM mms_txn_header W\
HERE mth_txn_code = :b2 AND rownum = 1 ";
        sqlstm.iters = (unsigned int  )1;
        sqlstm.offset = (unsigned int  )719;
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
ERRLOG("MmsTransaction ChkTxnCodeExist_error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
        /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

        return PD_ERR;
}
