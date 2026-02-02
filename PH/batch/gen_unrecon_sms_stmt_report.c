
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
           char  filnam[31];
};
static struct sqlcxp sqlfpn =
{
    30,
    "gen_unrecon_sms_stmt_report.pc"
};


static unsigned int sqlctx = 1623519675;


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
   unsigned char  *sqhstv[18];
   unsigned long  sqhstl[18];
            int   sqhsts[18];
            short *sqindv[18];
            int   sqinds[18];
   unsigned long  sqharm[18];
   unsigned long  *sqharc[18];
   unsigned short  sqadto[18];
   unsigned short  sqtdso[18];
} sqlstm = {12,18};

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
"hannel ORDER BY olsd_statement_times\
tamp DESC            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,2105,0,9,282,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,284,0,0,18,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,
115,0,0,1,0,0,15,454,0,0,0,0,0,1,0,
130,0,0,1,0,0,15,471,0,0,0,0,0,1,0,
145,0,0,2,0,0,32,472,0,0,0,0,0,1,0,
};


/*
PDProTech (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of PDProTech.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2014/03/31              David Wong
Mask bank acct num & bank owner name		   2019/05/02		   CheukFung Lee
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
#include "myhash.h"
#include "numutility.h"
#include "myrecordset.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

#define PD_OPEN_TAG               "<Row>\n<Cell><Data ss:Type=\"String\">"
#define PD_NEXT_TAG_STRING        "</Data></Cell>\n<Cell><Data ss:Type=\"String\">"
#define PD_NEXT_TAG_NUMBER        "</Data></Cell>\n<Cell><Data ss:Type=\"Number\">"
#define PD_END_TAG                "</Data></Cell>\n</Row>\n"

static char cDebug = 'Y';
char csOutputFileName[PD_MAX_FILE_LEN + 1];
char csFullOutputFileName[PD_MAX_FILE_LEN + 1];
char csFromStmtDatetime[PD_DATETIME_LEN + 1];
char csToStmtDatetime[PD_DATETIME_LEN + 1];
FILE *fp;
time_t tNow;
struct tm tStruct;
char csBuf[PD_TMP_BUF_LEN];

int parse_arg(int argc, char **argv);
int process_main();

int batch_init(int argc, char* argv[])
{
	if (argc < 7) {
		printf("***usage:  -o [output file name] -f [from statement datetime] -t [to statement datetime]\n");
		return FAILURE;
	}

	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("***usage:  -o [output file name] -f [from statement datetime] -t [to statement datetime]\n");
		return (iRet);
	}

	tNow = time(0);
	tStruct = *localtime(&tNow);
	strftime(csBuf, sizeof(csBuf), "%Y%m%d", &tStruct);
	CreateReportPathCustomized((unsigned char*)csFullOutputFileName, csBuf);
DEBUGLOG(("batch_proc() path = [%s]\n", csFullOutputFileName));
	sprintf(csFullOutputFileName, "%s/%s", csFullOutputFileName, csOutputFileName);
DEBUGLOG(("batch_proc() file = [%s]\n", csFullOutputFileName));

	fp = fopen(csFullOutputFileName, "w");
	if (fp == NULL) {
DEBUGLOG(("batch_proc() unable to open [%s]\n", csFullOutputFileName));
		return FAILURE;
	} else {
		iRet = process_main();
DEBUGLOG(("batch_proc() iRet = [%d]\n", iRet));
	}

	fclose(fp);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_main()
{
	int iRet = SUCCESS;
	int iCnt = 0;

	fprintf(fp, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
	fprintf(fp, "<Workbook xmlns=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:x=\"urn:schemas-microsoft-com:office:excel\" xmlns:ss=\"urn:schemas-microsoft-com:office:spreadsheet\" xmlns:html=\"http://www.w3.org/TR/REC-html40\">\n");
	fprintf(fp, "<Worksheet ss:Name=\"Un-reconcile SMS Statement\">\n");
	fprintf(fp, "<Table>\n");

	memset(&tStruct, 0, sizeof(struct tm));
	strptime(csFromStmtDatetime, "%Y%m%d%H%M%S", &tStruct);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<Row><Cell><Data ss:Type=\"String\">From</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell></Row>\n", csBuf);

	memset(&tStruct, 0, sizeof(struct tm));
	strptime(csToStmtDatetime, "%Y%m%d%H%M%S", &tStruct);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<Row><Cell><Data ss:Type=\"String\">To</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell></Row>\n", csBuf);

	tNow = time(0);
	tStruct = *localtime(&tNow);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<Row><Cell><Data ss:Type=\"String\">Generated on</Data></Cell><Cell><Data ss:Type=\"String\">%s</Data></Cell></Row>\n", csBuf);

	fprintf(fp, "<Row></Row>\n");
	fprintf(fp, "<Row></Row>\n");

	fprintf(fp, "<Row>\n\
<Cell><Data ss:Type=\"String\">Create Timestamp</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Last Update Timestamp</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Approval Timestamp</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Transaction Timestamp</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement Timestamp</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Merchant Short Name</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Merchant Reference</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Consumer Deposit Bank</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement Transaction Type</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Credit/Debit</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Consumer Paid Amount Currency</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Consumer Paid Amount</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement Input Channel</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement Balance</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Status</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Sub Status</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Beneficiary Bank Name</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Beneficiary Bank Account Number</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Account Provider</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Owner Name</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement File Name</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Provided Reference</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Statement ID</Data></Cell>\n\
<Cell><Data ss:Type=\"String\">Bank Remark/Bank Reference</Data></Cell>\n\
</Row>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_from_stmt_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_from_stmt_datetime;

		/* varchar hv_to_stmt_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_to_stmt_datetime;


		/* varchar v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar v_last_update_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_last_update_timestamp;

		/* varchar v_approval_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;

		/* varchar v_txn_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_timestamp;

		// Bank Stmt Timestamp
		/* varchar v_merch_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_merch_short_name;

		/* varchar v_merch_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merch_ref;

		// Consumer Deposit Bank
		/* varchar v_bank_stmt_txn_type[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_stmt_txn_type;

		/* varchar v_credit_debit[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_credit_debit;

		/* varchar v_con_paid_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_con_paid_amt_ccy;

		double v_con_paid_amt;
		double v_bank_stmt_bal;
		/* varchar v_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar v_sub_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status;

		/* varchar v_bene_bank_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bene_bank_name;

		/* varchar v_bene_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bene_bank_acct_num;

		/* varchar v_bank_acct_prov[PD_CLIENT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_prov;

		/* varchar v_bank_owner_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_owner_name;

		// Bank Stmt File Name
		// Bank Provided Ref
		// Bank Stmt ID
		// Bank Remark/Bank Ref
		/* varchar v_bank_stmt_input_channel[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_stmt_input_channel;


		short ind_create_timestamp = -1;
		short ind_last_update_timestamp = -1;
		short ind_approval_timestamp = -1;
		short ind_txn_timestamp = -1;
		short ind_merch_short_name = -1;
		short ind_merch_ref = -1;
		short ind_bank_stmt_txn_type = -1;
		short ind_credit_debit = -1;
		short ind_con_paid_amt_ccy = -1;
		short ind_con_paid_amt = -1;
		short ind_bank_stmt_bal = -1;
		short ind_status = -1;
		short ind_sub_status = -1;
		short ind_bene_bank_name = -1;
		short ind_bene_bank_acct_num = -1;
		short ind_bank_acct_prov = -1;
		short ind_bank_owner_name = -1;
		short ind_bank_stmt_input_channel = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_from_stmt_datetime.len = strlen(csFromStmtDatetime);
	memcpy(hv_from_stmt_datetime.arr, csFromStmtDatetime, hv_from_stmt_datetime.len);
DEBUGLOG(("process_main() from_stmt_datetime = [%.*s]\n", hv_from_stmt_datetime.len, hv_from_stmt_datetime.arr));

	hv_to_stmt_datetime.len = strlen(csToStmtDatetime);
	memcpy(hv_to_stmt_datetime.arr, csToStmtDatetime, hv_to_stmt_datetime.len);
DEBUGLOG(("process_main() to_stmt_datetime = [%.*s]\n", hv_to_stmt_datetime.len, hv_to_stmt_datetime.arr));

	/* EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT	TO_CHAR(olsd_create_timestamp, 'yyyy-mm-dd hh24:mi:ss'), // Create Timestamp
				TO_CHAR(olsd_update_timestamp, 'yyyy-mm-dd hh24:mi:ss'), // Last Update Timestamp
				TO_CHAR(ol_txn_header_merch.oth_approval_timestamp, 'yyyy-mm-dd hh24:mi:ss'), // Approval Timestamp
				TO_CHAR(otp_txn_timestamp, 'yyyy-mm-dd hh24:mi:ss'), // Txn Timestamp
				// Bank Stmt Timestamp
				md_short_name, // Merch Short Name
				ol_txn_header_merch.oth_merchant_ref, // Merch Ref
				// Consumer Deposit Bank
				obtc_desc, // Bank Stmt Txn Type
				da_desc, // Credit/Debit
				olsd_txn_ccy, // Consumer Paid Amount Currency
				olsd_txn_amount, // Consumer Paid Amt
				olsd_balance, // Bank Stmt Balance
				dm_status_desc, // Status
				ds_name, // Sub Status
				bank_name, // Beneficiary Bank Name
				sp_mask_bank_acct_num(otp_bank_code, otp_bank_acct_num), // Beneficiary Bank Acc Num
				pm_client_name, // Bank Acct Provider
				sp_mask_owner_name(ob_int_bank_code, ob_owner_name), // Bank Owner Name
				// Bank Stmt File Name
				// Bank Provided Ref
				// Bank Stmt ID
				// Bank Remark/Bank Ref
				di_desc // Bank Stmt Input Channel
		FROM 	(
					SELECT	oth_txn_id, dm_status_desc, ds_name
					FROM	ol_txn_header, def_txn_status_map, def_sub_status
					WHERE	oth_input_channel = 'OMT'
					AND		oth_status = 'C'
					AND		oth_ar_ind = 'A'
					AND		oth_txn_code = 'OBD'
					AND		oth_upload_channel = 0
					AND		dm_type = 'A'
					AND		oth_status = dm_status
					AND		(oth_ar_ind = dm_ar_ind OR oth_ar_ind IS NULL)
					AND		oth_txn_code = dm_txn_code
					AND		oth_sub_status = ds_sub_status
				) ol_txn_header_psp
				LEFT JOIN ol_txn_header ol_txn_header_merch
				ON ol_txn_header_psp.oth_txn_id = ol_txn_header_merch.oth_dst_txn_id
				LEFT JOIN ol_merch_detail
				ON ol_txn_header_merch.oth_merchant_id = md_merchant_id,
				ol_txn_psp_detail,
				ol_baid_txn,
				ol_statement_detail,
				ol_baid_txn_code,
				def_amt_type,
				bank_desc,
				ol_psp_detail,
				psp_master,
				ol_bank_accts,
				ol_def_input_channel,
				ol_stmt_txn_relation
		WHERE	ol_txn_header_psp.oth_txn_id = otp_txn_id
		// AND		ol_txn_header_psp.oth_txn_id = obt_dst_txn_id
		AND		ol_txn_header_psp.oth_txn_id = ostp_txn_id
		AND		ostp_stmt_txn_id = obt_txn_id
		AND		obt_stat_txn_id = olsd_stat_txn_id
		AND		olsd_statement_timestamp >= TO_DATE(:hv_from_stmt_datetime, 'yyyymmddhh24miss')
		AND		olsd_statement_timestamp < TO_DATE (:hv_to_stmt_datetime, 'yyyymmddhh24miss') + 1 / 24 / 60 / 60
		AND		olsd_statement_ref IS NULL
		AND		olsd_txn_amount > 0
		AND		obt_txn_code = obtc_code
		AND		olsd_amt_type = da_type
		AND		otp_bank_code = internal_bank_code
		AND		obt_pid = opd_psp_id
		AND		opd_client_id = pm_client_id
		AND		otp_bank_code = ob_int_bank_code
		AND		otp_bank_acct_num = ob_bank_acct_num
		AND		olsd_input_channel = di_input_channel
		ORDER BY olsd_statement_timestamp DESC; */ 


	/* EXEC SQL OPEN c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT TO_CHAR ( olsd_create_timestamp , 'yyyy-mm-dd hh24:mi:ss' ) , TO_\
CHAR ( olsd_update_timestamp , 'yyyy-mm-dd hh24:mi:ss' ) , TO_CHAR ( ol_txn_\
header_merch . oth_approval_timestamp , 'yyyy-mm-dd hh24:mi:ss' ) , TO_CHAR \
( otp_txn_timestamp , 'yyyy-mm-dd hh24:mi:ss' ) , md_short_name , ol_txn_hea\
der_merch . oth_merchant_ref , obtc_desc , da_desc , olsd_txn_ccy , olsd_txn\
_amount , olsd_balance , dm_status_desc , ds_name , bank_name , sp_mask_bank\
_acct_num ( otp_bank_code , otp_bank_acct_num ) , pm_client_name , sp_mask_o\
wner_name ( ob_int_bank_code , ob_owner_name ) , di_desc FROM ( SELECT oth_t\
xn_id , dm_status_desc , ds_name FROM ol_txn_header , def_txn_status_map , d\
ef_sub_status WHERE oth_input_channel = 'OMT' AND oth_status = 'C' AND oth_a\
r_ind = 'A' AND oth_txn_code = 'OBD' AND oth_upload_channel = 0 AND dm_type \
= 'A' AND oth_status = dm_status AND ( oth_ar_ind = dm_ar_ind OR oth_ar_ind \
IS NULL ) AND oth_txn_code = dm_txn_code AND oth_sub_status = ds_sub_status \
) ol_txn_header_psp LEFT JOIN ol_txn_hea");
 sqlbuft((void **)0,
   "der ol_txn_header_merch ON ol_txn_header_psp . oth_txn_id = ol_txn_heade\
r_merch . oth_dst_txn_id LEFT JOIN ol_merch_detail ON ol_txn_header_merch . \
oth_merchant_id = md_merchant_id , ol_txn_psp_detail , ol_baid_txn , ol_stat\
ement_detail , ol_baid_txn_code , def_amt_type , bank_desc , ol_psp_detail ,\
 psp_master , ol_bank_accts , ol_def_input_channel , ol_stmt_txn_relation WH\
ERE ol_txn_header_psp . oth_txn_id = otp_txn_id AND ol_txn_header_psp . oth_\
txn_id = ostp_txn_id AND ostp_stmt_txn_id = obt_txn_id AND obt_stat_txn_id =\
 olsd_stat_txn_id AND olsd_statement_timestamp >= TO_DATE ( :b0 , 'yyyymmddh\
h24miss' ) AND olsd_statement_timestamp < TO_DATE ( :b1 , 'yyyymmddhh24miss'\
 ) + 1 / 24 / 60 / 60 AND olsd_statement_ref IS NULL AND olsd_txn_amount > 0\
 AND obt_txn_code = obtc_code AND olsd_amt_type = da_type AND otp_bank_code \
= internal_bank_code AND obt_pid = opd_psp_id AND opd_client_id = pm_client_\
id AND otp_bank_code = ob_int_bank_code AND otp_bank_acct_num = ob_bank_acct\
_num AND olsd_input_channel = di_input_c");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_stmt_datetime;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_stmt_datetime;
 sqlstm.sqhstl[1] = (unsigned long )17;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {
		/* EXEC SQL FETCH c_cursor
		INTO
			:v_create_timestamp:ind_create_timestamp,
			:v_last_update_timestamp:ind_last_update_timestamp,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_txn_timestamp:ind_txn_timestamp,
			:v_merch_short_name:ind_merch_short_name,
			:v_merch_ref:ind_merch_ref,
			:v_bank_stmt_txn_type:ind_bank_stmt_txn_type,
			:v_credit_debit:ind_credit_debit,
			:v_con_paid_amt_ccy:ind_con_paid_amt_ccy,
			:v_con_paid_amt:ind_con_paid_amt,
			:v_bank_stmt_bal:ind_bank_stmt_bal,
			:v_status:ind_status,
			:v_sub_status:ind_sub_status,
			:v_bene_bank_name:ind_bene_bank_name,
			:v_bene_bank_acct_num:ind_bene_bank_acct_num,
			:v_bank_acct_prov:ind_bank_acct_prov,
			:v_bank_owner_name:ind_bank_owner_name,
			:v_bank_stmt_input_channel:ind_bank_stmt_input_channel; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 18;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )28;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_last_update_timestamp;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_last_update_timestamp;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_timestamp;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_timestamp;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merch_short_name;
  sqlstm.sqhstl[4] = (unsigned long )23;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merch_short_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merch_ref;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merch_ref;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_bank_stmt_txn_type;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_bank_stmt_txn_type;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_credit_debit;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_credit_debit;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_con_paid_amt_ccy;
  sqlstm.sqhstl[8] = (unsigned long )6;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_con_paid_amt_ccy;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_con_paid_amt;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_con_paid_amt;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_bank_stmt_bal;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_bank_stmt_bal;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[11] = (unsigned long )53;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_status;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[12] = (unsigned long )53;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_sub_status;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_bene_bank_name;
  sqlstm.sqhstl[13] = (unsigned long )53;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_bene_bank_name;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_bene_bank_acct_num;
  sqlstm.sqhstl[14] = (unsigned long )53;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_bene_bank_acct_num;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_bank_acct_prov;
  sqlstm.sqhstl[15] = (unsigned long )53;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_bank_acct_prov;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_bank_owner_name;
  sqlstm.sqhstl[16] = (unsigned long )53;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_bank_owner_name;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_bank_stmt_input_channel;
  sqlstm.sqhstl[17] = (unsigned long )53;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_bank_stmt_input_channel;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			iCnt++;

			if (ind_create_timestamp >= 0) {
				v_create_timestamp.arr[v_create_timestamp.len] = '\0';
				fprintf(fp, "%s%.*s%s", PD_OPEN_TAG, v_create_timestamp.len, v_create_timestamp.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s%s", PD_OPEN_TAG, PD_NEXT_TAG_STRING);
			}

			if (ind_last_update_timestamp >= 0) {
				v_last_update_timestamp.arr[v_last_update_timestamp.len] = '\0';
				fprintf(fp, "%.*s%s", v_last_update_timestamp.len, v_last_update_timestamp.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_approval_timestamp >= 0) {
				v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
				fprintf(fp, "%.*s%s", v_approval_timestamp.len, v_approval_timestamp.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_txn_timestamp >= 0) {
				v_txn_timestamp.arr[v_txn_timestamp.len] = '\0';
				fprintf(fp, "%.*s%s", v_txn_timestamp.len, v_txn_timestamp.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			// Bank Stmt Timestamp
			fprintf(fp, "%s", PD_NEXT_TAG_STRING);

			if (ind_merch_short_name >= 0) {
				v_merch_short_name.arr[v_merch_short_name.len] = '\0';
				fprintf(fp, "%.*s%s", v_merch_short_name.len, v_merch_short_name.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_merch_ref >= 0) {
				v_merch_ref.arr[v_merch_ref.len] = '\0';
				fprintf(fp, "%.*s%s", v_merch_ref.len, v_merch_ref.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			// Consumer Deposit Bank
			fprintf(fp, "%s", PD_NEXT_TAG_STRING);

			if (ind_bank_stmt_txn_type >= 0) {
				v_bank_stmt_txn_type.arr[v_bank_stmt_txn_type.len] = '\0';
				fprintf(fp, "%.*s%s", v_bank_stmt_txn_type.len, v_bank_stmt_txn_type.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_credit_debit >= 0) {
				v_credit_debit.arr[v_credit_debit.len] = '\0';
				fprintf(fp, "%.*s%s", v_credit_debit.len, v_credit_debit.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_con_paid_amt_ccy >= 0) {
				v_con_paid_amt_ccy.arr[v_con_paid_amt_ccy.len] = '\0';
				fprintf(fp, "%.*s%s", v_con_paid_amt_ccy.len, v_con_paid_amt_ccy.arr, PD_NEXT_TAG_NUMBER);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_NUMBER);
			}

			if (ind_con_paid_amt >= 0) {
				fprintf(fp, "%f%s", v_con_paid_amt, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_bank_stmt_input_channel >= 0) {
				v_bank_stmt_input_channel.arr[v_bank_stmt_input_channel.len] = '\0';
				fprintf(fp, "%.*s%s", v_bank_stmt_input_channel.len, v_bank_stmt_input_channel.arr, PD_NEXT_TAG_NUMBER);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_NUMBER);
			}

			if (ind_bank_stmt_bal >= 0) {
				fprintf(fp, "%f%s", v_bank_stmt_bal, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_status >= 0) {
				v_status.arr[v_status.len] = '\0';
				fprintf(fp, "%.*s%s", v_status.len, v_status.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_sub_status >= 0) {
				v_sub_status.arr[v_sub_status.len] = '\0';
				fprintf(fp, "%.*s%s", v_sub_status.len, v_sub_status.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_bene_bank_name >= 0) {
				v_bene_bank_name.arr[v_bene_bank_name.len] = '\0';
				fprintf(fp, "%.*s%s", v_bene_bank_name.len, v_bene_bank_name.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_bene_bank_acct_num >= 0) {
				v_bene_bank_acct_num.arr[v_bene_bank_acct_num.len] = '\0';
				fprintf(fp, "%.*s%s", v_bene_bank_acct_num.len, v_bene_bank_acct_num.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_bank_acct_prov >= 0) {
				v_bank_acct_prov.arr[v_bank_acct_prov.len] = '\0';
				fprintf(fp, "%.*s%s", v_bank_acct_prov.len, v_bank_acct_prov.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			if (ind_bank_owner_name >= 0) {
				v_bank_owner_name.arr[v_bank_owner_name.len] = '\0';
				fprintf(fp, "%.*s%s", v_bank_owner_name.len, v_bank_owner_name.arr, PD_NEXT_TAG_STRING);
			} else {
				fprintf(fp, "%s", PD_NEXT_TAG_STRING);
			}

			// Bank Stmt File Name
			fprintf(fp, "%s", PD_NEXT_TAG_STRING);

			// Bank Provided Ref
			fprintf(fp, "%s", PD_NEXT_TAG_STRING);

			// Bank Stmt ID
			fprintf(fp, "%s", PD_NEXT_TAG_STRING);

			// Bank Remark/Bank Ref
			fprintf(fp, "%s", PD_END_TAG);
	}
	while (PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )115;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



DEBUGLOG(("process_main() rec cnt = [%d]\n", iCnt));
	fprintf(fp, "<Row></Row>\n");
	fprintf(fp, "<Row></Row>\n");
	fprintf(fp, "<Row><Cell><Data ss:Type=\"String\">Total un-reconcile SMS statement record count:</Data></Cell><Cell><Data ss:Type=\"Number\">%d</Data></Cell></Row>\n", iCnt);

	fprintf(fp, "</Table>\n");
	fprintf(fp, "</Worksheet>\n");
	fprintf(fp, "</Workbook>");

	return iRet;

sql_error:
	DEBUGLOG(("process_main error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )130;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	/* EXEC SQL ROLLBACK RELEASE; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 18;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )145;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return FAILURE;
}

int parse_arg(int argc, char **argv)
{
	char c;

	while ((c = getopt(argc, argv, "o:f:t:")) != EOF) {
		switch (c) {
			case 'o':
				strcpy(csOutputFileName, optarg);
				break;
			case 'f':
				strcpy(csFromStmtDatetime, optarg);
				break;
			case 't':
				strcpy(csToStmtDatetime, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csOutputFileName, "") || !strcmp(csFromStmtDatetime, "") || !strcmp(csToStmtDatetime, ""))
		return FAILURE;

	return SUCCESS;
}
