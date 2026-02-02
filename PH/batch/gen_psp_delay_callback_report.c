
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
           char  filnam[33];
};
static struct sqlcxp sqlfpn =
{
    32,
    "gen_psp_delay_callback_report.pc"
};


static unsigned int sqlctx = 2128286277;


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
   unsigned char  *sqhstv[8];
   unsigned long  sqhstl[8];
            int   sqhsts[8];
            short *sqindv[8];
            int   sqinds[8];
   unsigned long  sqharm[8];
   unsigned long  *sqharc[8];
   unsigned short  sqadto[8];
   unsigned short  sqtdso[8];
} sqlstm = {12,8};

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
"SELECT psp_name , th_merchant_ref , th_txn_id , tp_txn_ccy , tp_txn_amount \
, to_char ( th_create_timestamp , 'mm/dd/yyyy hh24:mi:ss' ) , to_char ( th_ap\
proval_timestamp , 'mm/dd/yyyy hh24:mi:ss' ) , round ( ( to_date ( to_char ( \
th_approval_timestamp , 'yyyymmddhh24miss' ) , 'yyyymmddhh24miss' ) - th_crea\
te_timestamp ) * 24 , 2 ) \"callback time\" FROM txn_header , txn_psp_detail \
, psp_detail WHERE 1 = 1 AND th_merchant_id IN ( 'M8000016' , 'M8000017' ) AN\
D th_txn_code = 'DSI' AND th_status = 'C' AND th_ar_ind = 'A' AND round ( ( t\
o_date ( to_char ( th_approval_timestamp , 'yyyymmddhh24miss' ) , 'yyyymmddhh\
24miss' ) - th_create_timestamp ) * 24 , 2 ) >= 8 AND th_approval_timestamp >\
= to_date ( :b0 , 'yyyymmddhh24miss' ) AND th_approval_timestamp <= to_date (\
 :b1 , 'yyyymmddhh24miss' ) AND th_txn_id = tp_txn_id AND tp_psp_id = psp_id \
           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,854,0,9,175,0,2049,2,2,0,1,0,1,9,0,0,1,9,0,0,
28,0,0,1,0,0,13,177,0,0,8,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,
0,0,2,9,0,0,2,4,0,0,
75,0,0,1,0,0,15,233,0,0,0,0,0,1,0,
90,0,0,1,0,0,15,244,0,0,0,0,0,1,0,
105,0,0,2,0,0,32,245,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/08/01              David Wong
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

#define PD_OPEN_TAG             "<tr><td>"
#define PD_OPEN_TAG_CS          "<tr><td style='mso-number-format:\\@'>"
#define PD_NEXT_TAG             "</td><td>"
#define PD_NEXT_TAG_CS          "</td><td style='mso-number-format:\\@'>"
#define PD_END_TAG              "</td></tr>"

char cDebug = 'Y';
char csOutputFileName[PD_MAX_FILE_LEN + 1];
char csFullOutputFileName[PD_MAX_FILE_LEN + 1];
char csFromApprovalDatetime[PD_DATETIME_LEN + 1];
char csToApprovalDatetime[PD_DATETIME_LEN + 1];
FILE *fp;
time_t tNow;
struct tm tStruct;
char csBuf[PD_TMP_BUF_LEN];

int parse_arg(int argc, char **argv);
int process_main();

int batch_init(int argc, char* argv[])
{
	if (argc < 7) {
		printf("***usage:  -o [output file name] -f [from approval datetime] -t [to approval datetime]\n");
		return FAILURE;
	}

	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS) {
		printf("***usage:  -o [output file name] -f [from approval datetime] -t [to approval datetime]\n");
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
		fprintf(fp, "%s", "<table>\n");
		iRet = process_main();
DEBUGLOG(("batch_proc() iRet = [%d]\n", iRet));
	}

	fprintf(fp, "%s", "</table>\n");
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

	fprintf(fp, "<tr><td colspan=\"5\"><b>PSP Long Delay Callback Report</b></td></tr>\n");

	memset(&tStruct, 0, sizeof(struct tm));
	strptime(csFromApprovalDatetime, "%Y%m%d%H%M%S", &tStruct);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<tr><td><b>From</b></td><td style='mso-number-format:\\@'>%s</td></tr>\n", csBuf);

	memset(&tStruct, 0, sizeof(struct tm));
	strptime(csToApprovalDatetime, "%Y%m%d%H%M%S", &tStruct);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<tr><td><b>To</b></td><td style='mso-number-format:\\@'>%s</td></tr>\n", csBuf);

	tNow = time(0);
	tStruct = *localtime(&tNow);
	strftime(csBuf, sizeof(csBuf), "%m/%d/%Y %H:%M:%S", &tStruct);
	fprintf(fp, "<tr><td><b>Generated on</b></td><td style='mso-number-format:\\@'>%s</td></tr>\n", csBuf);

	fprintf(fp, "<tr></tr>\n<tr></tr>\n<tr><td><b>PSP</b></td><td><b>Merchant Ref.</b></td><td><b>Transaction Nmb</b></td><td><b>Currency</b></td><td><b>Amount</b></td><td><b>Request Date and Time</b></td><td><b>Complete Date and Time</b></td><td><b>callback time (in hour)</b></td></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_from_approval_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_from_approval_timestamp;

		/* varchar hv_to_approval_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } hv_to_approval_timestamp;


		/* varchar v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar v_txn_id[PD_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double v_txn_amount;
		/* varchar v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar v_approval_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;

		double v_callback_time;

		short ind_psp_name = -1;
		short ind_merchant_ref = -1;
		short ind_txn_id = -1;
		short ind_txn_ccy = -1;
		short ind_txn_amount = -1;
		short ind_create_timestamp = -1;
		short ind_approval_timestamp = -1;
		short ind_callback_time = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	hv_from_approval_timestamp.len = strlen(csFromApprovalDatetime);
	memcpy(hv_from_approval_timestamp.arr, csFromApprovalDatetime, hv_from_approval_timestamp.len);
DEBUGLOG(("process_main() from_approval_timestamp = [%.*s]\n", hv_from_approval_timestamp.len, hv_from_approval_timestamp.arr));

	hv_to_approval_timestamp.len = strlen(csToApprovalDatetime);
	memcpy(hv_to_approval_timestamp.arr, csToApprovalDatetime, hv_to_approval_timestamp.len);
DEBUGLOG(("process_main() hv_to_approval_timestamp = [%.*s]\n", hv_to_approval_timestamp.len, hv_to_approval_timestamp.arr));

	/* EXEC SQL DECLARE c_cursor CURSOR FOR
		SELECT	psp_name,
			th_merchant_ref,
			th_txn_id,
			tp_txn_ccy,
			tp_txn_amount,
			to_char(th_create_timestamp, 'mm/dd/yyyy hh24:mi:ss'),
			to_char(th_approval_timestamp, 'mm/dd/yyyy hh24:mi:ss'),
			round((to_date(to_char(th_approval_timestamp, 'yyyymmddhh24miss'), 'yyyymmddhh24miss') - th_create_timestamp) * 24, 2) "callback time"
		FROM	txn_header, txn_psp_detail, psp_detail
		WHERE	1 = 1
		AND	th_merchant_id IN ('M8000016', 'M8000017')
		AND	th_txn_code = 'DSI'
		AND	th_status = 'C'
		AND	th_ar_ind = 'A'
		AND	round((to_date(to_char(th_approval_timestamp, 'yyyymmddhh24miss'), 'yyyymmddhh24miss') - th_create_timestamp) * 24, 2) >= 8
		AND	th_approval_timestamp >= to_date(:hv_from_approval_timestamp, 'yyyymmddhh24miss')
		AND	th_approval_timestamp <= to_date(:hv_to_approval_timestamp, 'yyyymmddhh24miss')
		AND	th_txn_id = tp_txn_id
		AND	tp_psp_id = psp_id; */ 


	/* EXEC SQL OPEN c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 2;
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
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_from_approval_timestamp;
 sqlstm.sqhstl[0] = (unsigned long )17;
 sqlstm.sqhsts[0] = (         int  )0;
 sqlstm.sqindv[0] = (         short *)0;
 sqlstm.sqinds[0] = (         int  )0;
 sqlstm.sqharm[0] = (unsigned long )0;
 sqlstm.sqadto[0] = (unsigned short )0;
 sqlstm.sqtdso[0] = (unsigned short )0;
 sqlstm.sqhstv[1] = (unsigned char  *)&hv_to_approval_timestamp;
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
			:v_psp_name:ind_psp_name,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_id:ind_txn_id,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_create_timestamp:ind_create_timestamp,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_callback_time:ind_callback_time; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 8;
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
  sqlstm.sqhstv[0] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[0] = (unsigned long )53;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_psp_name;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_id;
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
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[5] = (unsigned long )23;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[6] = (unsigned long )23;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_callback_time;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_callback_time;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
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

			if (ind_psp_name >= 0) {
				v_psp_name.arr[v_psp_name.len] = '\0';
				fprintf(fp, "%s%.*s%s", PD_OPEN_TAG, v_psp_name.len, v_psp_name.arr, PD_NEXT_TAG_CS);
			}

			if (ind_merchant_ref >= 0) {
				v_merchant_ref.arr[v_merchant_ref.len] = '\0';
				fprintf(fp, "%.*s%s", v_merchant_ref.len, v_merchant_ref.arr, PD_NEXT_TAG_CS);
			}

			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
				fprintf(fp, "%.*s%s", v_txn_id.len, v_txn_id.arr, PD_NEXT_TAG);
			}

			if (ind_txn_ccy >= 0) {
				v_txn_ccy.arr[v_txn_ccy.len] = '\0';
				fprintf(fp, "%.*s%s", v_txn_ccy.len, v_txn_ccy.arr, PD_NEXT_TAG);
			}

			if (ind_txn_amount >= 0) {
				fprintf(fp, "%f%s", v_txn_amount, PD_NEXT_TAG_CS);
			}

			if (ind_create_timestamp >= 0) {
				v_create_timestamp.arr[v_create_timestamp.len] = '\0';
				fprintf(fp, "%.*s%s", v_create_timestamp.len, v_create_timestamp.arr, PD_NEXT_TAG_CS);
			}

			if (ind_approval_timestamp >= 0) {
				v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
				fprintf(fp, "%.*s%s", v_approval_timestamp.len, v_approval_timestamp.arr, PD_NEXT_TAG);
			}

			if (ind_callback_time >= 0) {
				fprintf(fp, "%f%s\n", v_callback_time, PD_END_TAG);
			}
	}
	while (PD_TRUE && iRet == SUCCESS);
	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )75;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}



DEBUGLOG(("process_main() rec cnt = [%d]\n", iCnt));
	fprintf(fp, "<tr></tr>\n<tr></tr>\n<tr><td colspan=\"5\"><b>Total long delay callback record count:</b> %d</td></tr>\n", iCnt);

	return iRet;

sql_error:
	DEBUGLOG(("process_main error code %d\n", sqlca.sqlcode));
	DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )90;
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
 sqlstm.arrsiz = 8;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )105;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	fprintf(fp, "<tr></tr>\n<tr></tr>\n<tr><td colspan=\"5\"><b>Total long delay callback record count:</b> %d</td></tr>\n", iCnt);
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
				strcpy(csFromApprovalDatetime, optarg);
				break;
			case 't':
				strcpy(csToApprovalDatetime, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(csOutputFileName, "") || !strcmp(csFromApprovalDatetime, "") || !strcmp(csToApprovalDatetime, ""))
		return FAILURE;

	return SUCCESS;
}
