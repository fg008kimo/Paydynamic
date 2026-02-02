
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
    "OLSmsTxnLog.pc"
};


static unsigned int sqlctx = 1292227;


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
   unsigned char  *sqhstv[27];
   unsigned long  sqhstl[27];
            int   sqhsts[27];
            short *sqindv[27];
            int   sqinds[27];
   unsigned long  sqharm[27];
   unsigned long  *sqharc[27];
   unsigned short  sqadto[27];
   unsigned short  sqtdso[27];
} sqlstm = {12,27};

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
5,0,0,1,884,0,6,366,0,0,27,27,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,
9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,
0,1,9,0,0,1,9,0,0,
128,0,0,2,167,0,4,458,0,0,4,3,0,1,0,2,3,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/09/09              David Wong
Add req_bank_second                                2017/03/10              David Wong
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlca.h>
#include <time.h>
#include "common.h"
#include "utilitys.h"
#include "dbutility.h"
#include "OLSmsTxnLog.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;

void OLSmsTxnLog(char cdebug) {
	cDebug = cdebug;
}

int Add(const hash_t* hTxn, const hash_t* hText) {
	char *csTmp;
	char *csReqStatus;
	char *csReqBankDate;
	char *csReqBankHour;
	char *csReqBankMinute;
	char *csReqBankSecond;
	time_t tNow;
	struct tm tStruct;
	char csBuf[PD_TMP_BUF_LEN];

	tNow = time(0);
	tStruct = *localtime(&tNow);

	/* EXEC SQL WHENEVER SQLERROR GOTO add_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar		hv_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } hv_txn_id;

		/* varchar		hv_sender[PD_SMS_SENDER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_sender;

		/* varchar		hv_text[PD_SMS_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[1601]; } hv_text;

		/* varchar		hv_scts[PD_SMS_SCTS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_scts;

		/* varchar		hv_tag[PD_SMS_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_tag;

		/* varchar		hv_has_missing_parts[PD_SMS_HAS_MISSING_PARTS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_has_missing_parts;

		/* varchar		hv_smsc[PD_SMS_SMSC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_smsc;

		/* varchar		hv_ref_num[PD_SMS_REF_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_ref_num;

		/* varchar		hv_sender_num_type[PD_SMS_SENDER_NUM_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_sender_num_type;

		/* varchar		hv_seq_num[PD_SMS_SEQ_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_seq_num;

		/* varchar		hv_total[PD_SMS_TOTAL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[6]; } hv_total;

		/* varchar		hv_req_bank_acc[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_req_bank_acc;

		/* varchar		hv_req_bank_year[PD_YYYY_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } hv_req_bank_year;

		/* varchar		hv_req_bank_month[PD_MM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_req_bank_month;

		/* varchar		hv_req_bank_day[PD_DD_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } hv_req_bank_day;

		/* varchar		hv_req_bank_time[PD_SMS_REQ_BANK_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_req_bank_time;

		/* varchar		hv_req_bank_amount[PD_SMS_BAL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_bank_amount;

		/* varchar		hv_req_payee[PD_SMS_REQ_PAYEE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_req_payee;

		/* varchar		hv_req_payer[PD_SMS_REQ_PAYER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_req_payer;

		/* varchar		hv_req_payer_acc[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } hv_req_payer_acc;

		/* varchar		hv_req_bank_bal[PD_SMS_BAL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_req_bank_bal;

		/* varchar		hv_req_bank_name[PD_SMS_REQ_BANK_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_req_bank_name;

		/* varchar		hv_req_bank_channel[PD_SMS_REQ_BANK_CHANNEL_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[101]; } hv_req_bank_channel;

		/* varchar		hv_req_status[PD_SMS_REQ_STATUS_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_req_status;

		/* varchar		hv_req_ip[PD_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } hv_req_ip;

		/* varchar		hv_create_user[PD_USER_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_create_user;


		short		ind_txn_id = -1;
		short		ind_sender = -1;
		short		ind_text = -1;
		short		ind_scts = -1;
		short		ind_tag = -1;
		short		ind_has_missing_parts = -1;
		short		ind_smsc = -1;
		short		ind_ref_num = -1;
		short		ind_sender_num_type = -1;
		short		ind_seq_num = -1;
		short		ind_total = -1;
		short		ind_req_bank_acc = -1;
		short		ind_req_bank_year = -1;
		short		ind_req_bank_month = -1;
		short		ind_req_bank_day = -1;
		short		ind_req_bank_time = -1;
		short		ind_req_bank_amount = -1;
		short		ind_req_payee = -1;
		short		ind_req_payer = -1;
		short		ind_req_payer_acc = -1;
		short		ind_req_bank_bal = -1;
		short		ind_req_bank_name = -1;
		short		ind_req_bank_channel = -1;
		short		ind_req_status = -1;
		short		ind_req_ip = -1;
		short		ind_create_user = -1;

		short		hv_return_value;
	/* EXEC SQL END DECLARE SECTION; */ 


DEBUGLOG(("Add: Begin\n"));

/* req status */
	if (GetField_CString(hText, "req_status", &csReqStatus)) {
		hv_req_status.len = strlen(csReqStatus);
		strncpy((char *)hv_req_status.arr, csReqStatus, hv_req_status.len);
		ind_req_status = 0;
DEBUGLOG(("Add: req_status = [%.*s]\n", hv_req_status.len, hv_req_status.arr));
	}

/* txn id */
	if (GetField_CString(hText, "stat_txn_id", &csTmp)) {
		hv_txn_id.len = strlen(csTmp);
		strncpy((char *)hv_txn_id.arr, csTmp, hv_txn_id.len);
		ind_txn_id = 0;
DEBUGLOG(("Add: txn_id = [%.*s]\n", hv_txn_id.len, hv_txn_id.arr));
	}

/* sender */
	if (GetField_CString(hTxn, "sender", &csTmp)) {
		hv_sender.len = strlen(csTmp);
		strncpy((char *)hv_sender.arr, csTmp, hv_sender.len);
		ind_sender = 0;
DEBUGLOG(("Add: sender = [%.*s]\n", hv_sender.len, hv_sender.arr));
	}

/* text */
	if (GetField_CString(hTxn, "text", &csTmp)) {
		hv_text.len = strlen(csTmp);
		strncpy((char *)hv_text.arr, csTmp, hv_text.len);
		ind_text = 0;
DEBUGLOG(("Add: text = [%.*s]\n", hv_text.len, hv_text.arr));
	}

/* scts */
	if (GetField_CString(hTxn, "scts", &csTmp)) {
		hv_scts.len = strlen(csTmp);
		strncpy((char *)hv_scts.arr, csTmp, hv_scts.len);
		ind_scts = 0;
DEBUGLOG(("Add: scts = [%.*s]\n", hv_scts.len, hv_scts.arr));
	}

/* tag */
	if (GetField_CString(hTxn, "tag", &csTmp)) {
		hv_tag.len = strlen(csTmp);
		strncpy((char *)hv_tag.arr, csTmp, hv_tag.len);
		ind_tag = 0;
DEBUGLOG(("Add: tag = [%.*s]\n", hv_tag.len, hv_tag.arr));
	}

/* has missing parts */
	if (GetField_CString(hTxn, "has_missing_parts", &csTmp)) {
		hv_has_missing_parts.len = strlen(csTmp);
		strncpy((char *)hv_has_missing_parts.arr, csTmp, hv_has_missing_parts.len);
		ind_has_missing_parts = 0;
DEBUGLOG(("Add: has_missing_parts = [%.*s]\n", hv_has_missing_parts.len, hv_has_missing_parts.arr));
	}

/* smsc */
	if (GetField_CString(hTxn, "smsc", &csTmp)) {
		hv_smsc.len = strlen(csTmp);
		strncpy((char *)hv_smsc.arr, csTmp, hv_smsc.len);
		ind_smsc = 0;
DEBUGLOG(("Add: smsc = [%.*s]\n", hv_smsc.len, hv_smsc.arr));
	}

/* ref num */
	if (GetField_CString(hTxn, "ref_num", &csTmp)) {
		hv_ref_num.len = strlen(csTmp);
		strncpy((char *)hv_ref_num.arr, csTmp, hv_ref_num.len);
		ind_ref_num = 0;
DEBUGLOG(("Add: ref_num = [%.*s]\n", hv_ref_num.len, hv_ref_num.arr));
	}

/* sender num type */
	if (GetField_CString(hTxn, "sender_num_type", &csTmp)) {
		hv_sender_num_type.len = strlen(csTmp);
		strncpy((char *)hv_sender_num_type.arr, csTmp, hv_sender_num_type.len);
		ind_sender_num_type = 0;
DEBUGLOG(("Add: sender_num_type = [%.*s]\n", hv_sender_num_type.len, hv_sender_num_type.arr));
	}

/* seq num */
	if (GetField_CString(hTxn, "seq_num", &csTmp)) {
		hv_seq_num.len = strlen(csTmp);
		strncpy((char *)hv_seq_num.arr, csTmp, hv_seq_num.len);
		ind_seq_num = 0;
DEBUGLOG(("Add: seq_num = [%.*s]\n", hv_seq_num.len, hv_seq_num.arr));
	}

/* total */
	if (GetField_CString(hTxn, "total", &csTmp)) {
		hv_total.len = strlen(csTmp);
		strncpy((char *)hv_total.arr, csTmp, hv_total.len);
		ind_total = 0;
DEBUGLOG(("Add: total = [%.*s]\n", hv_total.len, hv_total.arr));
	}

	if (strcmp(csReqStatus, "UPLOADED") == 0) {
		/* req bank acc */
		if (GetField_CString(hText, "req_bank_acc", &csTmp)) {
			hv_req_bank_acc.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_acc.arr, csTmp, hv_req_bank_acc.len);
			ind_req_bank_acc = 0;
DEBUGLOG(("Add: req_bank_acc = [%.*s]\n", hv_req_bank_acc.len, hv_req_bank_acc.arr));
		}

		if (GetField_CString(hText, "req_bank_date", &csReqBankDate)) {
DEBUGLOG(("Add: req_bank_date = [%s]\n", csReqBankDate));
			strncpy(csTmp, csReqBankDate, 4);
			csTmp[4] = '\0';
			hv_req_bank_year.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_year.arr, csTmp, hv_req_bank_year.len);
			ind_req_bank_year = 0;

			strncpy(csTmp, csReqBankDate + 4, 2);
			csTmp[2] = '\0';
			hv_req_bank_month.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_month.arr, csTmp, hv_req_bank_month.len);
			ind_req_bank_month = 0;

			strncpy(csTmp, csReqBankDate + 6, 2);
			csTmp[2] = '\0';
			hv_req_bank_day.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_day.arr, csTmp, hv_req_bank_day.len);
			ind_req_bank_day = 0;
		} else {
			/* req bank year */
			if (GetField_CString(hText, "req_bank_year", &csTmp)) {
				hv_req_bank_year.len = strlen(csTmp);
				strncpy((char *)hv_req_bank_year.arr, csTmp, hv_req_bank_year.len);
				ind_req_bank_year = 0;
			} else {
				// year-part of current date
				strftime(csBuf, sizeof(csBuf), "%Y", &tStruct);
				hv_req_bank_year.len = strlen(csBuf);
				strncpy((char *)hv_req_bank_year.arr, csBuf, hv_req_bank_year.len);
				ind_req_bank_year = 0;
			}
DEBUGLOG(("Add: req_bank_year = [%.*s]\n", hv_req_bank_year.len, hv_req_bank_year.arr));

			/* req bank month */
			if (GetField_CString(hText, "req_bank_month", &csTmp)) {
				hv_req_bank_month.len = strlen(csTmp);
				strncpy((char *)hv_req_bank_month.arr, csTmp, hv_req_bank_month.len);
				ind_req_bank_month = 0;
			} else {
				// month-part of current date
				strftime(csBuf, sizeof(csBuf), "%m", &tStruct);
				hv_req_bank_month.len = strlen(csBuf);
				strncpy((char *)hv_req_bank_month.arr, csBuf, hv_req_bank_month.len);
				ind_req_bank_month = 0;
			}
DEBUGLOG(("Add: req_bank_month = [%.*s]\n", hv_req_bank_month.len, hv_req_bank_month.arr));

			/* req bank day */
			if (GetField_CString(hText, "req_bank_day", &csTmp)) {
				hv_req_bank_day.len = strlen(csTmp);
				strncpy((char *)hv_req_bank_day.arr, csTmp, hv_req_bank_day.len);
				ind_req_bank_day = 0;
			} else {
				// day-part of current date
				strftime(csBuf, sizeof(csBuf), "%d", &tStruct);
				hv_req_bank_day.len = strlen(csBuf);
				strncpy((char *)hv_req_bank_day.arr, csBuf, hv_req_bank_day.len);
				ind_req_bank_day = 0;
			}
DEBUGLOG(("Add: req_bank_day = [%.*s]\n", hv_req_bank_day.len, hv_req_bank_day.arr));
		}

		/* req bank time */
		if (GetField_CString(hText, "req_bank_hour", &csReqBankHour)) {
DEBUGLOG(("Add: req_bank_hour = [%s]\n", csReqBankHour));
			if (GetField_CString(hText, "req_bank_minute", &csReqBankMinute)) {
DEBUGLOG(("Add: req_bank_minute = [%s]\n", csReqBankMinute));
				if (GetField_CString(hText, "req_bank_second", &csReqBankSecond)) {
DEBUGLOG(("Add: req_bank_second = [%s]\n", csReqBankSecond));
					sprintf(csTmp, "%s:%s:%s", csReqBankHour, csReqBankMinute, csReqBankSecond);
				} else {
					sprintf(csTmp, "%s:%s", csReqBankHour, csReqBankMinute);
				}
				hv_req_bank_time.len = strlen(csTmp);
				strncpy((char *)hv_req_bank_time.arr, csTmp, hv_req_bank_time.len);
				ind_req_bank_time = 0;
DEBUGLOG(("Add: req_bank_time = [%.*s]\n", hv_req_bank_time.len, hv_req_bank_time.arr));
			}
		}

		/* req bank amount */
		if (GetField_CString(hText, "req_bank_amount", &csTmp)) {
			hv_req_bank_amount.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_amount.arr, csTmp, hv_req_bank_amount.len);
			ind_req_bank_amount = 0;
DEBUGLOG(("Add: req_bank_amount = [%.*s]\n", hv_req_bank_amount.len, hv_req_bank_amount.arr));
		}

		/* req payee */
		if (GetField_CString(hText, "req_payee", &csTmp)) {
			hv_req_payee.len = strlen(csTmp);
			strncpy((char *)hv_req_payee.arr, csTmp, hv_req_payee.len);
			ind_req_payee = 0;
DEBUGLOG(("Add: req_payee = [%.*s]\n", hv_req_payee.len, hv_req_payee.arr));
		}

		/* req payer */
		if (GetField_CString(hText, "req_payer", &csTmp)) {
			hv_req_payer.len = strlen(csTmp);
			strncpy((char *)hv_req_payer.arr, csTmp, hv_req_payer.len);
			ind_req_payer = 0;
DEBUGLOG(("Add: req_payer = [%.*s]\n", hv_req_payer.len, hv_req_payer.arr));
		}

		/* req payer acc */
		if (GetField_CString(hText, "req_payer_acc", &csTmp)) {
			hv_req_payer_acc.len = strlen(csTmp);
			strncpy((char *)hv_req_payer_acc.arr, csTmp, hv_req_payer_acc.len);
			ind_req_payer_acc = 0;
DEBUGLOG(("Add: req_payer_acc = [%.*s]\n", hv_req_payer_acc.len, hv_req_payer_acc.arr));
		}

		/* req bank bal */
		if (GetField_CString(hText, "req_bank_bal", &csTmp)) {
			hv_req_bank_bal.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_bal.arr, csTmp, hv_req_bank_bal.len);
			ind_req_bank_bal = 0;
DEBUGLOG(("Add: req_bank_bal = [%.*s]\n", hv_req_bank_bal.len, hv_req_bank_bal.arr));
		}

		/* req bank name */
		if (GetField_CString(hText, "req_bank_name", &csTmp)) {
			hv_req_bank_name.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_name.arr, csTmp, hv_req_bank_name.len);
			ind_req_bank_name = 0;
DEBUGLOG(("Add: req_bank_name = [%.*s]\n", hv_req_bank_name.len, hv_req_bank_name.arr));
		}

		/* req bank channel */
		if (GetField_CString(hText, "req_bank_channel", &csTmp)) {
			hv_req_bank_channel.len = strlen(csTmp);
			strncpy((char *)hv_req_bank_channel.arr, csTmp, hv_req_bank_channel.len);
			ind_req_bank_channel = 0;
DEBUGLOG(("Add: req_bank_channel = [%.*s]\n", hv_req_bank_channel.len, hv_req_bank_channel.arr));
		}
	}

/* req ip */
	if (GetField_CString(hTxn, "req_ip", &csTmp)) {
		hv_req_ip.len = strlen(csTmp);
		strncpy((char *)hv_req_ip.arr, csTmp, hv_req_ip.len);
		ind_req_ip = 0;
DEBUGLOG(("Add: req_ip = [%.*s]\n", hv_req_ip.len, hv_req_ip.arr));
	}

/* create user */
	if (GetField_CString(hTxn, "create_user", &csTmp)) {
		hv_create_user.len = strlen(csTmp);
		strncpy((char *)hv_create_user.arr, csTmp, hv_create_user.len);
		ind_create_user = 0;
DEBUGLOG(("Add: create_user = [%.*s]\n", hv_create_user.len, hv_create_user.arr));
	}

	/* EXEC SQL EXECUTE
		BEGIN
			:hv_return_value := sp_ol_sms_txn_log_insert(
					:hv_txn_id:ind_txn_id,
					:hv_sender:ind_sender,
					:hv_text:ind_text,
					:hv_scts:ind_scts,
					:hv_tag:ind_tag,
					:hv_has_missing_parts:ind_has_missing_parts,
					:hv_smsc:ind_smsc,
					:hv_ref_num:ind_ref_num,
					:hv_sender_num_type:ind_sender_num_type,
					:hv_seq_num:ind_seq_num,
					:hv_total:ind_total,
					:hv_req_bank_acc:ind_req_bank_acc,
					:hv_req_bank_year:ind_req_bank_year,
					:hv_req_bank_month:ind_req_bank_month,
					:hv_req_bank_day:ind_req_bank_day,
					:hv_req_bank_time:ind_req_bank_time,
					:hv_req_bank_amount:ind_req_bank_amount,
					:hv_req_payee:ind_req_payee,
					:hv_req_payer:ind_req_payer,
					:hv_req_payer_acc:ind_req_payer_acc,
					:hv_req_bank_bal:ind_req_bank_bal,
					:hv_req_bank_name:ind_req_bank_name,
					:hv_req_bank_channel:ind_req_bank_channel,
					:hv_req_status:ind_req_status,
					:hv_req_ip:ind_req_ip,
					:hv_create_user:ind_create_user);
		END;
	END-EXEC; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "begin :hv_return_value := sp_ol_sms_txn_log_insert ( :hv_tx\
n_id:ind_txn_id , :hv_sender:ind_sender , :hv_text:ind_text , :hv_scts:ind_sc\
ts , :hv_tag:ind_tag , :hv_has_missing_parts:ind_has_missing_parts , :hv_smsc\
:ind_smsc , :hv_ref_num:ind_ref_num , :hv_sender_num_type:ind_sender_num_type\
 , :hv_seq_num:ind_seq_num , :hv_total:ind_total , :hv_req_bank_acc:ind_req_b\
ank_acc , :hv_req_bank_year:ind_req_bank_year , :hv_req_bank_month:ind_req_ba\
nk_month , :hv_req_bank_day:ind_req_bank_day , :hv_req_bank_time:ind_req_bank\
_time , :hv_req_bank_amount:ind_req_bank_amount , :hv_req_payee:ind_req_payee\
 , :hv_req_payer:ind_req_payer , :hv_req_payer_acc:ind_req_payer_acc , :hv_re\
q_bank_bal:ind_req_bank_bal , :hv_req_bank_name:ind_req_bank_name , :hv_req_b\
ank_channel:ind_req_bank_channel , :hv_req_status:ind_req_status , :hv_req_ip\
:ind_req_ip , :hv_create_user:ind_create_user ) ; END ;";
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
 sqlstm.sqhstl[1] = (unsigned long )19;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)&ind_txn_id;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_sender;
 sqlstm.sqhstl[2] = (unsigned long )23;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)&ind_sender;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_text;
 sqlstm.sqhstl[3] = (unsigned long )1603;
 sqlstm.sqhsts[3] = (         int  )0;
 sqlstm.sqindv[3] = (         short *)&ind_text;
 sqlstm.sqinds[3] = (         int  )0;
 sqlstm.sqharm[3] = (unsigned long )0;
 sqlstm.sqadto[3] = (unsigned short )0;
 sqlstm.sqtdso[3] = (unsigned short )0;
 sqlstm.sqhstv[4] = (unsigned char  *)&hv_scts;
 sqlstm.sqhstl[4] = (unsigned long )23;
 sqlstm.sqhsts[4] = (         int  )0;
 sqlstm.sqindv[4] = (         short *)&ind_scts;
 sqlstm.sqinds[4] = (         int  )0;
 sqlstm.sqharm[4] = (unsigned long )0;
 sqlstm.sqadto[4] = (unsigned short )0;
 sqlstm.sqtdso[4] = (unsigned short )0;
 sqlstm.sqhstv[5] = (unsigned char  *)&hv_tag;
 sqlstm.sqhstl[5] = (unsigned long )23;
 sqlstm.sqhsts[5] = (         int  )0;
 sqlstm.sqindv[5] = (         short *)&ind_tag;
 sqlstm.sqinds[5] = (         int  )0;
 sqlstm.sqharm[5] = (unsigned long )0;
 sqlstm.sqadto[5] = (unsigned short )0;
 sqlstm.sqtdso[5] = (unsigned short )0;
 sqlstm.sqhstv[6] = (unsigned char  *)&hv_has_missing_parts;
 sqlstm.sqhstl[6] = (unsigned long )8;
 sqlstm.sqhsts[6] = (         int  )0;
 sqlstm.sqindv[6] = (         short *)&ind_has_missing_parts;
 sqlstm.sqinds[6] = (         int  )0;
 sqlstm.sqharm[6] = (unsigned long )0;
 sqlstm.sqadto[6] = (unsigned short )0;
 sqlstm.sqtdso[6] = (unsigned short )0;
 sqlstm.sqhstv[7] = (unsigned char  *)&hv_smsc;
 sqlstm.sqhstl[7] = (unsigned long )23;
 sqlstm.sqhsts[7] = (         int  )0;
 sqlstm.sqindv[7] = (         short *)&ind_smsc;
 sqlstm.sqinds[7] = (         int  )0;
 sqlstm.sqharm[7] = (unsigned long )0;
 sqlstm.sqadto[7] = (unsigned short )0;
 sqlstm.sqtdso[7] = (unsigned short )0;
 sqlstm.sqhstv[8] = (unsigned char  *)&hv_ref_num;
 sqlstm.sqhstl[8] = (unsigned long )53;
 sqlstm.sqhsts[8] = (         int  )0;
 sqlstm.sqindv[8] = (         short *)&ind_ref_num;
 sqlstm.sqinds[8] = (         int  )0;
 sqlstm.sqharm[8] = (unsigned long )0;
 sqlstm.sqadto[8] = (unsigned short )0;
 sqlstm.sqtdso[8] = (unsigned short )0;
 sqlstm.sqhstv[9] = (unsigned char  *)&hv_sender_num_type;
 sqlstm.sqhstl[9] = (unsigned long )13;
 sqlstm.sqhsts[9] = (         int  )0;
 sqlstm.sqindv[9] = (         short *)&ind_sender_num_type;
 sqlstm.sqinds[9] = (         int  )0;
 sqlstm.sqharm[9] = (unsigned long )0;
 sqlstm.sqadto[9] = (unsigned short )0;
 sqlstm.sqtdso[9] = (unsigned short )0;
 sqlstm.sqhstv[10] = (unsigned char  *)&hv_seq_num;
 sqlstm.sqhstl[10] = (unsigned long )8;
 sqlstm.sqhsts[10] = (         int  )0;
 sqlstm.sqindv[10] = (         short *)&ind_seq_num;
 sqlstm.sqinds[10] = (         int  )0;
 sqlstm.sqharm[10] = (unsigned long )0;
 sqlstm.sqadto[10] = (unsigned short )0;
 sqlstm.sqtdso[10] = (unsigned short )0;
 sqlstm.sqhstv[11] = (unsigned char  *)&hv_total;
 sqlstm.sqhstl[11] = (unsigned long )8;
 sqlstm.sqhsts[11] = (         int  )0;
 sqlstm.sqindv[11] = (         short *)&ind_total;
 sqlstm.sqinds[11] = (         int  )0;
 sqlstm.sqharm[11] = (unsigned long )0;
 sqlstm.sqadto[11] = (unsigned short )0;
 sqlstm.sqtdso[11] = (unsigned short )0;
 sqlstm.sqhstv[12] = (unsigned char  *)&hv_req_bank_acc;
 sqlstm.sqhstl[12] = (unsigned long )53;
 sqlstm.sqhsts[12] = (         int  )0;
 sqlstm.sqindv[12] = (         short *)&ind_req_bank_acc;
 sqlstm.sqinds[12] = (         int  )0;
 sqlstm.sqharm[12] = (unsigned long )0;
 sqlstm.sqadto[12] = (unsigned short )0;
 sqlstm.sqtdso[12] = (unsigned short )0;
 sqlstm.sqhstv[13] = (unsigned char  *)&hv_req_bank_year;
 sqlstm.sqhstl[13] = (unsigned long )7;
 sqlstm.sqhsts[13] = (         int  )0;
 sqlstm.sqindv[13] = (         short *)&ind_req_bank_year;
 sqlstm.sqinds[13] = (         int  )0;
 sqlstm.sqharm[13] = (unsigned long )0;
 sqlstm.sqadto[13] = (unsigned short )0;
 sqlstm.sqtdso[13] = (unsigned short )0;
 sqlstm.sqhstv[14] = (unsigned char  *)&hv_req_bank_month;
 sqlstm.sqhstl[14] = (unsigned long )5;
 sqlstm.sqhsts[14] = (         int  )0;
 sqlstm.sqindv[14] = (         short *)&ind_req_bank_month;
 sqlstm.sqinds[14] = (         int  )0;
 sqlstm.sqharm[14] = (unsigned long )0;
 sqlstm.sqadto[14] = (unsigned short )0;
 sqlstm.sqtdso[14] = (unsigned short )0;
 sqlstm.sqhstv[15] = (unsigned char  *)&hv_req_bank_day;
 sqlstm.sqhstl[15] = (unsigned long )5;
 sqlstm.sqhsts[15] = (         int  )0;
 sqlstm.sqindv[15] = (         short *)&ind_req_bank_day;
 sqlstm.sqinds[15] = (         int  )0;
 sqlstm.sqharm[15] = (unsigned long )0;
 sqlstm.sqadto[15] = (unsigned short )0;
 sqlstm.sqtdso[15] = (unsigned short )0;
 sqlstm.sqhstv[16] = (unsigned char  *)&hv_req_bank_time;
 sqlstm.sqhstl[16] = (unsigned long )13;
 sqlstm.sqhsts[16] = (         int  )0;
 sqlstm.sqindv[16] = (         short *)&ind_req_bank_time;
 sqlstm.sqinds[16] = (         int  )0;
 sqlstm.sqharm[16] = (unsigned long )0;
 sqlstm.sqadto[16] = (unsigned short )0;
 sqlstm.sqtdso[16] = (unsigned short )0;
 sqlstm.sqhstv[17] = (unsigned char  *)&hv_req_bank_amount;
 sqlstm.sqhstl[17] = (unsigned long )18;
 sqlstm.sqhsts[17] = (         int  )0;
 sqlstm.sqindv[17] = (         short *)&ind_req_bank_amount;
 sqlstm.sqinds[17] = (         int  )0;
 sqlstm.sqharm[17] = (unsigned long )0;
 sqlstm.sqadto[17] = (unsigned short )0;
 sqlstm.sqtdso[17] = (unsigned short )0;
 sqlstm.sqhstv[18] = (unsigned char  *)&hv_req_payee;
 sqlstm.sqhstl[18] = (unsigned long )53;
 sqlstm.sqhsts[18] = (         int  )0;
 sqlstm.sqindv[18] = (         short *)&ind_req_payee;
 sqlstm.sqinds[18] = (         int  )0;
 sqlstm.sqharm[18] = (unsigned long )0;
 sqlstm.sqadto[18] = (unsigned short )0;
 sqlstm.sqtdso[18] = (unsigned short )0;
 sqlstm.sqhstv[19] = (unsigned char  *)&hv_req_payer;
 sqlstm.sqhstl[19] = (unsigned long )53;
 sqlstm.sqhsts[19] = (         int  )0;
 sqlstm.sqindv[19] = (         short *)&ind_req_payer;
 sqlstm.sqinds[19] = (         int  )0;
 sqlstm.sqharm[19] = (unsigned long )0;
 sqlstm.sqadto[19] = (unsigned short )0;
 sqlstm.sqtdso[19] = (unsigned short )0;
 sqlstm.sqhstv[20] = (unsigned char  *)&hv_req_payer_acc;
 sqlstm.sqhstl[20] = (unsigned long )53;
 sqlstm.sqhsts[20] = (         int  )0;
 sqlstm.sqindv[20] = (         short *)&ind_req_payer_acc;
 sqlstm.sqinds[20] = (         int  )0;
 sqlstm.sqharm[20] = (unsigned long )0;
 sqlstm.sqadto[20] = (unsigned short )0;
 sqlstm.sqtdso[20] = (unsigned short )0;
 sqlstm.sqhstv[21] = (unsigned char  *)&hv_req_bank_bal;
 sqlstm.sqhstl[21] = (unsigned long )18;
 sqlstm.sqhsts[21] = (         int  )0;
 sqlstm.sqindv[21] = (         short *)&ind_req_bank_bal;
 sqlstm.sqinds[21] = (         int  )0;
 sqlstm.sqharm[21] = (unsigned long )0;
 sqlstm.sqadto[21] = (unsigned short )0;
 sqlstm.sqtdso[21] = (unsigned short )0;
 sqlstm.sqhstv[22] = (unsigned char  *)&hv_req_bank_name;
 sqlstm.sqhstl[22] = (unsigned long )23;
 sqlstm.sqhsts[22] = (         int  )0;
 sqlstm.sqindv[22] = (         short *)&ind_req_bank_name;
 sqlstm.sqinds[22] = (         int  )0;
 sqlstm.sqharm[22] = (unsigned long )0;
 sqlstm.sqadto[22] = (unsigned short )0;
 sqlstm.sqtdso[22] = (unsigned short )0;
 sqlstm.sqhstv[23] = (unsigned char  *)&hv_req_bank_channel;
 sqlstm.sqhstl[23] = (unsigned long )103;
 sqlstm.sqhsts[23] = (         int  )0;
 sqlstm.sqindv[23] = (         short *)&ind_req_bank_channel;
 sqlstm.sqinds[23] = (         int  )0;
 sqlstm.sqharm[23] = (unsigned long )0;
 sqlstm.sqadto[23] = (unsigned short )0;
 sqlstm.sqtdso[23] = (unsigned short )0;
 sqlstm.sqhstv[24] = (unsigned char  *)&hv_req_status;
 sqlstm.sqhstl[24] = (unsigned long )23;
 sqlstm.sqhsts[24] = (         int  )0;
 sqlstm.sqindv[24] = (         short *)&ind_req_status;
 sqlstm.sqinds[24] = (         int  )0;
 sqlstm.sqharm[24] = (unsigned long )0;
 sqlstm.sqadto[24] = (unsigned short )0;
 sqlstm.sqtdso[24] = (unsigned short )0;
 sqlstm.sqhstv[25] = (unsigned char  *)&hv_req_ip;
 sqlstm.sqhstl[25] = (unsigned long )28;
 sqlstm.sqhsts[25] = (         int  )0;
 sqlstm.sqindv[25] = (         short *)&ind_req_ip;
 sqlstm.sqinds[25] = (         int  )0;
 sqlstm.sqharm[25] = (unsigned long )0;
 sqlstm.sqadto[25] = (unsigned short )0;
 sqlstm.sqtdso[25] = (unsigned short )0;
 sqlstm.sqhstv[26] = (unsigned char  *)&hv_create_user;
 sqlstm.sqhstl[26] = (unsigned long )23;
 sqlstm.sqhsts[26] = (         int  )0;
 sqlstm.sqindv[26] = (         short *)&ind_create_user;
 sqlstm.sqinds[26] = (         int  )0;
 sqlstm.sqharm[26] = (unsigned long )0;
 sqlstm.sqadto[26] = (unsigned short )0;
 sqlstm.sqtdso[26] = (unsigned short )0;
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



DEBUGLOG(("Add: Ret = [%d]\n", hv_return_value));

	if (hv_return_value == SP_OK) {
DEBUGLOG(("Add: Normal Exit\n"));
		return PD_OK;
	}

	if (hv_return_value == SP_OTHER_ERR) {
ERRLOG("OLSmsTxnLog:: Add: SP_OTHER_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_OTHER_ERR TxnAbort\n"));
		TxnAbort();
		return PD_OTHER_ERR;
	}

	if (hv_return_value == SP_ERR) {
ERRLOG("OLSmsTxnLog:: Add: SP_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_ERR TxnAbort\n"));
		TxnAbort();
		return PD_ERR;
	}

add_error:
DEBUGLOG(("add_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

ERRLOG("OLSmsTxnLog:: Add: SP_INTERNAL_ERR TxnAbort\n");
DEBUGLOG(("Add: SP_INTERNAL_ERR TxnAbort\n"));
	TxnAbort();
	return PD_INTERNAL_ERR;
}

int CheckDuplicate(const char* csDedupTimeRange,
			const char* csSender,
			const char* csSmsText)
{
	int iRet = PD_ERR;

	/* EXEC SQL WHENEVER SQLERROR GOTO checkduplicate_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		int hv_dedup_time_range;
		/* varchar hv_sender[PD_SMS_SENDER_LEN]; */ 
struct { unsigned short len; unsigned char arr[20]; } hv_sender;

		/* varchar hv_sms_text[PD_SMS_TEXT_LEN]; */ 
struct { unsigned short len; unsigned char arr[1600]; } hv_sms_text;


		int v_dup_cnt;
		short ind_dup_cnt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_dedup_time_range = atoi(csDedupTimeRange);
DEBUGLOG(("CheckDuplicate:: dedup_time_range = [%d]\n", hv_dedup_time_range));

	hv_sender.len = strlen(csSender);
	memcpy(hv_sender.arr, csSender, hv_sender.len);
DEBUGLOG(("CheckDuplicate:: sender = [%.*s]\n", hv_sender.len, hv_sender.arr));

	hv_sms_text.len = strlen(csSmsText);
	memcpy(hv_sms_text.arr, csSmsText, hv_sms_text.len);
DEBUGLOG(("CheckDuplicate:: sms_text = [%.*s]\n", hv_sms_text.len, hv_sms_text.arr));

	/* EXEC SQL
		SELECT count(1)
		INTO :v_dup_cnt:ind_dup_cnt
		FROM ol_sms_txn_log
		WHERE ost_sender = :hv_sender
		AND ost_text = :hv_sms_text
		AND ost_req_status = 'UPLOADED'
		AND ost_create_timestamp >= sysdate - :hv_dedup_time_range; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 27;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.stmt = "select count ( 1 ) INTO :b0:b1 FROM ol_sms_txn_log WHERE os\
t_sender = :b2 AND ost_text = :b3 AND ost_req_status = 'UPLOADED' AND ost_cre\
ate_timestamp >= sysdate - :b4 ";
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )128;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&v_dup_cnt;
 sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)&ind_dup_cnt;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_sender;
 sqlstm.sqhstl[1] = (unsigned long )22;
 sqlstm.sqhsts[1] = (         int  )0;
 sqlstm.sqindv[1] = (         short *)0;
 sqlstm.sqinds[1] = (         int  )0;
 sqlstm.sqharm[1] = (unsigned long )0;
 sqlstm.sqadto[1] = (unsigned short )0;
 sqlstm.sqtdso[1] = (unsigned short )0;
 sqlstm.sqhstv[2] = (unsigned char  *)&hv_sms_text;
 sqlstm.sqhstl[2] = (unsigned long )1602;
 sqlstm.sqhsts[2] = (         int  )0;
 sqlstm.sqindv[2] = (         short *)0;
 sqlstm.sqinds[2] = (         int  )0;
 sqlstm.sqharm[2] = (unsigned long )0;
 sqlstm.sqadto[2] = (unsigned short )0;
 sqlstm.sqtdso[2] = (unsigned short )0;
 sqlstm.sqhstv[3] = (unsigned char  *)&hv_dedup_time_range;
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
 if (sqlca.sqlcode < 0) goto checkduplicate_error;
}



	if (ind_dup_cnt >= 0) {
DEBUGLOG(("CheckDuplicate:: dup_cnt = [%d]\n", v_dup_cnt));
		iRet = v_dup_cnt;
	} else {
DEBUGLOG(("CheckDuplicate:: check duplicate error\n"));
		iRet = PD_ERR;
	}

	return iRet;

checkduplicate_error:
DEBUGLOG(("checkduplicate_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 


	return PD_ERR;
}

