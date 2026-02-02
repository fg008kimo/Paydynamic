
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
           char  filnam[29];
};
static struct sqlcxp sqlfpn =
{
    28,
    "check_bank_psp_txn_report.pc"
};


static unsigned int sqlctx = 1401811387;


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
   unsigned char  *sqhstv[9];
   unsigned long  sqhstl[9];
            int   sqhsts[9];
            short *sqindv[9];
            int   sqinds[9];
   unsigned long  sqharm[9];
   unsigned long  *sqharc[9];
   unsigned short  sqadto[9];
   unsigned short  sqtdso[9];
} sqlstm = {12,9};

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
"r_ind = th_ar_ind and dm_txn_code = \
th_txn_code and ds_sub_status = th_sub_status order by th_approval_timestamp \
desc            ";

 static char *sq0002 = 
"select th_client_ip , count ( 1 ) from ( select th_client_ip from txn_heade\
r where th_txn_code in ( 'DSI' ) and th_client_id not in ( select epm_party_i\
d from email_check_party_map where epm_name = 'CHECK_BANK_PSP' and epm_group \
= 'EXCLUDE' and epm_party_type = 'C' and epm_support_multi_entry = 1 ) and th\
_create_timestamp between to_date ( :b0 , 'DD-MON-YYYY HH24:MI:SS' ) and to_d\
ate ( :b1 , 'DD-MON-YYYY HH24:MI:SS' ) and exists ( select 1 from txn_detail \
where td_txn_id = th_txn_id and td_bank_code = :b2 ) and exists ( select 1 fr\
om txn_psp_detail where tp_txn_id = th_txn_id and tp_psp_id = :b3 ) and th_st\
atus = 'W' and th_ar_ind is null and th_sub_status = '102' order by th_create\
_timestamp desc ) where rownum <= :b4 group by th_client_ip order by count ( \
1 ) desc            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,1153,0,9,319,0,2049,4,4,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,
36,0,0,1,0,0,13,320,0,0,9,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,
87,0,0,1,0,0,15,391,0,0,0,0,0,1,0,
102,0,0,1,0,0,15,404,0,0,0,0,0,1,0,
117,0,0,2,788,0,9,529,0,2049,5,5,0,1,0,1,9,0,0,1,9,0,0,1,9,0,0,1,9,0,0,1,3,0,0,
152,0,0,2,0,0,13,531,0,0,2,0,0,1,0,2,9,0,0,2,3,0,0,
175,0,0,2,0,0,15,557,0,0,0,0,0,1,0,
190,0,0,2,0,0,15,631,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2016. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2016/08/04              David Wong
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <unistd.h>
#include "batchcommon.h"
#include "common.h"
#include "utilitys.h"
#include "myrecordset.h"
#include "ObjPtr.h"

#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode

char cDebug;
int iRptGenId = 0;
char csRptGenDatetime[PD_DATETIME_LEN + 1];
char csRptType[PD_PSP_REPORT_TYPE_LEN + 1];

OBJPTR(DB);

int parse_arg(int argc, char **argv);
int gen_additional_part(const int iRptGenId, const char* csRptGenDatetime, const char* csRptType);
int gen_last_approved_deposit_table(recordset_t *rRecordSet);
int gen_pending_count_table(recordset_t *rRecordSet, int iExactCntVal);

int batch_init(int argc, char* argv[])
{
	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int iRet;

	iRet = parse_arg(argc, argv);

	if (iRet != SUCCESS)
printf("usage: -i rpt_gen_id -d rpt_gen_datetime -t rpt_type\n");

	if (iRet == SUCCESS)
		iRet = gen_additional_part(iRptGenId, csRptGenDatetime, csRptType);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc, char **argv)
{
	if (argc < 7) {
		return PD_ERR;
	}

	char c;
	strcpy(csRptGenDatetime, "");
	strcpy(csRptType, "");

	while ((c = getopt(argc, argv, "i:d:t:")) != EOF) {
		switch (c) {
			case 'i':
				iRptGenId = atoi(optarg);
				break;
			case 'd':
				strcpy(csRptGenDatetime, optarg);
				break;
			case 't':
				strcpy(csRptType, optarg);
				break;
			default:
				return PD_ERR;
		}
	}

	if ((iRptGenId == 0) || !strcmp(csRptGenDatetime, "") || !strcmp(csRptType, ""))
		return PD_ERR;

	return SUCCESS;
}

int gen_additional_part(const int iRptGenId, const char* csRptGenDatetime, const char* csRptType)
{
	int iRet = SUCCESS, iTmpRet;
	char *csTmp = NULL;
	char *csIsShow = NULL;
	int iExactCntVal = 0;

	hash_t *hRec = (hash_t*) malloc (sizeof(hash_t));
	hash_init(hRec, 0);

	recordset_t *rRecordSet = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRecordSet, 0);

	// check whether generate additional part
	PutField_CString(hRec, "rpt_type", csRptType);
	PutField_CString(hRec, "code", PD_PSP_REPORT_CODE_SHOW);

DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter\n"));
	DBObjPtr = CreateObj(DBPtr, "DBPspTxnCheckReportParameter", "GetPspTxnCheckReportParameter");
	iTmpRet = (unsigned long)(*DBObjPtr)(hRec);
	if (iTmpRet != PD_FOUND) {
DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter not found\n"));
ERRLOG("check_bank_psp_txn_report:: gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter not found\n");
		iRet = PD_ERR;
	} else {
		if (GetField_CString(hRec, "val", &csIsShow)) {
DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter:: val = [%s]\n", csIsShow));
		}
	}

	// get exact count value
	if ((iRet == SUCCESS) && (!strcmp(csIsShow, PD_PSP_REPORT_VAL_ON))) {
		hash_destroy(hRec);
		hash_init(hRec, 0);

		PutField_CString(hRec, "rpt_type", csRptType);
		PutField_CString(hRec, "code", PD_PSP_REPORT_CODE_EXACT_CNT_VALUE);

DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter\n"));
		DBObjPtr = CreateObj(DBPtr, "DBPspTxnCheckReportParameter", "GetPspTxnCheckReportParameter");
		iTmpRet = (unsigned long)(*DBObjPtr)(hRec);
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter not found\n"));
ERRLOG("check_bank_psp_txn_report:: gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter not found\n");
			iRet = PD_ERR;
		} else {
			if (GetField_CString(hRec, "val", &csTmp)) {
				iExactCntVal = atoi(csTmp);
DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportParameter:: GetPspTxnCheckReportParameter:: val = [%d]\n", iExactCntVal));
			}
		}
	}

	// generate additional part
	if ((iRet == SUCCESS) && (!strcmp(csIsShow, PD_PSP_REPORT_VAL_ON))) {
DEBUGLOG(("gen_additional_part:: Show additional part\n"));

		// get psp_txn_check_rpt_log
		hash_destroy(hRec);
		hash_init(hRec, 0);

		PutField_Int(hRec, "rpt_gen_id", iRptGenId);
		PutField_CString(hRec, "rpt_gen_datetime", csRptGenDatetime);
		PutField_CString(hRec, "rpt_type", csRptType);

DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog\n"));
		DBObjPtr = CreateObj(DBPtr, "DBPspTxnCheckReportLog", "GetPspTxnCheckReportLog");
		iTmpRet = (unsigned long)(*DBObjPtr)(hRec, rRecordSet);
		if (iTmpRet != PD_FOUND) {
DEBUGLOG(("gen_additional_part:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog not found\n"));
ERRLOG("check_bank_psp_txn_report:: gen_additional_part:: Call DBPspTxnCheckReportLog:: GetPspTxnCheckReportLog not found\n");
			iRet = PD_ERR;
		} else {
			iRet = gen_last_approved_deposit_table(rRecordSet);
			if (iRet == SUCCESS)
				iRet = gen_pending_count_table(rRecordSet, iExactCntVal);
		}
	} else {
DEBUGLOG(("gen_additional_part:: Do not show additional part\n"));
	}

	hash_destroy(hRec);
	FREE_ME(hRec);

	RecordSet_Destroy(rRecordSet);
	FREE_ME(rRecordSet);

	return iRet;
}

int gen_last_approved_deposit_table(recordset_t *rRecordSet) {
	int iRet = SUCCESS;

	char *csTmp = NULL;

	int iSuccCnt = 0;
	char *csDurStart = NULL;
	char *csDurEnd = NULL;
	char *csPartyName = NULL;
	char *csBankName = NULL;

	hash_t *hTmp;

	printf("<br>\n");
	printf("<b>Last approved deposit</b>\n");
	printf("<table border=\"1\">\n");
	printf("<tr align=\"center\"><td><b>Duration Start</b></td><td><b>Duration End</b></td><td><b>PSP Account Name</b></td><td><b>Transaction ID</b></td><td><b>Last Update Date</b></td><td><b>Create Time</b></td><td><b>Merchant Short Name</b></td><td><b>Merchant Reference</b></td><td><b>Transaction Amount</b></td><td><b>Consumer Deposit Bank</b></td><td><b>Status</b></td><td><b>Sub Status</b></td><td><b>Approval Time</b></td></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO getlastappdsi_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_psp_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_bank_code;

		/* varchar hv_dur_start[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_start;

		/* varchar hv_dur_end[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_end;


		/* varchar v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar v_update_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_update_timestamp;

		/* varchar v_create_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_create_timestamp;

		/* varchar v_merch_short_name[PD_MERCH_SHORT_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_merch_short_name;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		double v_txn_amt;
		/* varchar v_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar v_sub_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status;

		/* varchar v_approval_timestamp[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_approval_timestamp;


		short ind_txn_id = -1;
		short ind_update_timestamp = -1;
		short ind_create_timestamp = -1;
		short ind_merch_short_name = -1;
		short ind_merchant_ref = -1;
		short ind_txn_amt = -1;
		short ind_status = -1;
		short ind_sub_status = -1;
		short ind_approval_timestamp = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getlastappdsi CURSOR FOR
		select th_txn_id,
			to_char(th_update_timestamp, 'DD/MM/YYYY HH24:MI'),
			to_char(th_create_timestamp, 'DD/MM/YYYY HH24:MI'),
			short_name,
			th_merchant_ref,
			th_net_amount,
			dm_status_desc,
			ds_name,
			to_char(th_approval_timestamp, 'DD/MM/YYYY HH24:MI')
		from txn_header, merch_detail, def_txn_status_map, def_sub_status
		where th_txn_code in ('DSI')
		and th_client_id not in (select epm_party_id
			from email_check_party_map
			where epm_name = 'CHECK_BANK_PSP'
			and epm_group = 'EXCLUDE'
			and epm_party_type = 'C'
			and epm_support_multi_entry = 1)
		and th_create_timestamp between to_date(:hv_dur_start, 'DD-MON-YYYY HH24:MI:SS') and to_date(:hv_dur_end, 'DD-MON-YYYY HH24:MI:SS')
		and exists (select 1
			from txn_detail
			where td_txn_id = th_txn_id
			and td_bank_code = :hv_bank_code)
		and exists (select 1
			from txn_psp_detail
			where tp_txn_id = th_txn_id
			and tp_psp_id = :hv_psp_id)
		and th_status = 'C'
		and th_ar_ind = 'A'
		and th_approval_timestamp is not null
		and merchant_id = th_merchant_id
		and dm_type = 'A'
		and dm_status = th_status
		and dm_ar_ind = th_ar_ind
		and dm_txn_code = th_txn_code
		and ds_sub_status = th_sub_status
		order by th_approval_timestamp desc; */ 


	hTmp = RecordSet_GetFirst(rRecordSet);
	while (hTmp) {
		// party_id
		if (GetField_CString(hTmp, "party_id", &csTmp)) {
DEBUGLOG(("gen_last_approved_deposit_table:: party_id = [%s]\n", csTmp));
			hv_psp_id.len = strlen(csTmp);
			memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		}

		// party_name
		if (GetField_CString(hTmp, "party_name", &csPartyName)) {
DEBUGLOG(("gen_last_approved_deposit_table:: party_name = [%s]\n", csPartyName));
		}

		// bank_code
		if (GetField_CString(hTmp, "bank_code", &csTmp)) {
DEBUGLOG(("gen_last_approved_deposit_table:: bank_code = [%s]\n", csTmp));
			hv_bank_code.len = strlen(csTmp);
			memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
		}

		// bank_name
		if (GetField_CString(hTmp, "bank_name", &csBankName)) {
DEBUGLOG(("gen_last_approved_deposit_table:: bank_name = [%s]\n", csBankName));
		}

		// dur_start
		if (GetField_CString(hTmp, "dur_start", &csDurStart)) {
DEBUGLOG(("gen_last_approved_deposit_table:: dur_start = [%s]\n", csDurStart));
			hv_dur_start.len = strlen(csDurStart);
			memcpy(hv_dur_start.arr, csDurStart, hv_dur_start.len);
		}

		// dur_end
		if (GetField_CString(hTmp, "dur_end", &csDurEnd)) {
DEBUGLOG(("gen_last_approved_deposit_table:: dur_end = [%s]\n", csDurEnd));
			hv_dur_end.len = strlen(csDurEnd);
			memcpy(hv_dur_end.arr, csDurEnd, hv_dur_end.len);
		}

		// succ_cnt
		if (GetField_Int(hTmp, "succ_cnt", &iSuccCnt)) {
DEBUGLOG(("gen_last_approved_deposit_table:: succ_cnt = [%d]\n", iSuccCnt));
		}

		if (iSuccCnt == 0) {
			hTmp = RecordSet_GetNext(rRecordSet);
			continue;
		}

		/* EXEC SQL OPEN c_cursor_getlastappdsi; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 4;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlbuft((void **)0,
    "select th_txn_id , to_char ( th_update_timestamp , 'DD/MM/YYYY HH24:MI'\
 ) , to_char ( th_create_timestamp , 'DD/MM/YYYY HH24:MI' ) , short_name , t\
h_merchant_ref , th_net_amount , dm_status_desc , ds_name , to_char ( th_app\
roval_timestamp , 'DD/MM/YYYY HH24:MI' ) from txn_header , merch_detail , de\
f_txn_status_map , def_sub_status where th_txn_code in ( 'DSI' ) and th_clie\
nt_id not in ( select epm_party_id from email_check_party_map where epm_name\
 = 'CHECK_BANK_PSP' and epm_group = 'EXCLUDE' and epm_party_type = 'C' and e\
pm_support_multi_entry = 1 ) and th_create_timestamp between to_date ( :b0 ,\
 'DD-MON-YYYY HH24:MI:SS' ) and to_date ( :b1 , 'DD-MON-YYYY HH24:MI:SS' ) a\
nd exists ( select 1 from txn_detail where td_txn_id = th_txn_id and td_bank\
_code = :b2 ) and exists ( select 1 from txn_psp_detail where tp_txn_id = th\
_txn_id and tp_psp_id = :b3 ) and th_status = 'C' and th_ar_ind = 'A' and th\
_approval_timestamp is not null and merchant_id = th_merchant_id and dm_type\
 = 'A' and dm_status = th_status and dm_a");
  sqlstm.stmt = sq0001;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_dur_start;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_dur_end;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
  sqlstm.sqhstl[3] = (unsigned long )13;
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
  if (sqlca.sqlcode < 0) goto getlastappdsi_error;
}


		/* EXEC SQL FETCH c_cursor_getlastappdsi
		INTO
			:v_txn_id:ind_txn_id,
			:v_update_timestamp:ind_update_timestamp,
			:v_create_timestamp:ind_create_timestamp,
			:v_merch_short_name:ind_merch_short_name,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_amt:ind_txn_amt,
			:v_status:ind_status,
			:v_sub_status:ind_sub_status,
			:v_approval_timestamp:ind_approval_timestamp; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )36;
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
  sqlstm.sqhstv[1] = (unsigned char  *)&v_update_timestamp;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_update_timestamp;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[2] = (unsigned long )23;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_merch_short_name;
  sqlstm.sqhstl[3] = (unsigned long )23;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_merch_short_name;
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
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_status;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_sub_status;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_approval_timestamp;
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
  if (sqlca.sqlcode < 0) goto getlastappdsi_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			// do nothing
		} else {
			// txn_id
			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: txn_id = [%s]\n", v_txn_id.arr));
			}

			// update_timestamp
			if (ind_update_timestamp >= 0) {
				v_update_timestamp.arr[v_update_timestamp.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: update_timestamp = [%s]\n", v_update_timestamp.arr));
			}

			// create_timestamp
			if (ind_create_timestamp >= 0) {
				v_create_timestamp.arr[v_create_timestamp.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: create_timestamp = [%s]\n", v_create_timestamp.arr));
			}

			// merch_short_name
			if (ind_merch_short_name >= 0) {
				v_merch_short_name.arr[v_merch_short_name.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: merch_short_name = [%s]\n", v_merch_short_name.arr));
			}

			// merchant_ref
			if (ind_merchant_ref >= 0) {
				v_merchant_ref.arr[v_merchant_ref.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: merchant_ref = [%s]\n", v_merchant_ref.arr));
			}

			// txn_amt
			if (ind_txn_amt >= 0) {
DEBUGLOG(("gen_last_approved_deposit_table:: txn_amt = [%lf]\n", v_txn_amt));
			}

			// status
			if (ind_status >= 0) {
				v_status.arr[v_status.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: status = [%s]\n", v_status.arr));
			}

			// sub_status
			if (ind_sub_status >= 0) {
				v_sub_status.arr[v_sub_status.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: sub_status = [%s]\n", v_sub_status.arr));
			}

			// approval_timestamp
			if (ind_approval_timestamp >= 0) {
				v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
DEBUGLOG(("gen_last_approved_deposit_table:: approval_timestamp = [%s]\n", v_approval_timestamp.arr));
			}

			printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%.2f</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>\n", csDurStart, csDurEnd, csPartyName, v_txn_id.arr, v_update_timestamp.arr, v_create_timestamp.arr, v_merch_short_name.arr, v_merchant_ref.arr, v_txn_amt, csBankName, v_status.arr, v_sub_status.arr, v_approval_timestamp.arr);
		}

		/* EXEC SQL CLOSE c_cursor_getlastappdsi; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )87;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getlastappdsi_error;
}



		hTmp = RecordSet_GetNext(rRecordSet);
	}

	printf("</table>\n");

	return iRet;

getlastappdsi_error:
DEBUGLOG(("getlastappdsi_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getlastappdsi; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )102;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}

int gen_pending_count_table(recordset_t *rRecordSet, int iExactCntVal) {
	int iRet = SUCCESS;

	char *csTmp = NULL;
	int iTmp = 0;
	int iCustCnt = 0;

	char *csDurStart = NULL;
	char *csDurEnd = NULL;
	char *csPartyName = NULL;
	char *csBankName = NULL;

	hash_t *hTmp;
	hash_t *hRec;

	recordset_t *rRec = (recordset_t*) malloc (sizeof(recordset_t));
	recordset_init(rRec, 0);

	printf("<br>\n");
	printf("<b>Customer pending count > %d</b>\n", iExactCntVal);
	printf("<table border=\"1\">\n");
	printf("<tr align=\"center\"><td><b>Duration Start</b></td><td><b>Duration End</b></td><td><b>PSP Account Name</b></td><td><b>Consumer Deposit Bank</b></td><td><b>Cust IP</b></td><td><b>Pending Count</b></td></tr>\n");

	/* EXEC SQL WHENEVER SQLERROR GOTO getpendingcnt_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar hv_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_psp_id;

		/* varchar hv_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } hv_bank_code;

		/* varchar hv_dur_start[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_start;

		/* varchar hv_dur_end[PD_TIMESTAMP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } hv_dur_end;

		int hv_total_pend_cnt;

		/* varchar v_cust_ip[PD_IP_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_cust_ip;

		int v_pend_cnt;

		short ind_cust_ip = -1;
		short ind_pend_cnt = -1;
	/* EXEC SQL END DECLARE SECTION; */ 


	/* EXEC SQL DECLARE c_cursor_getpendingcnt CURSOR FOR
		select th_client_ip,
			count(1)
		from (
			select th_client_ip
			from txn_header
			where th_txn_code in ('DSI')
			and th_client_id not in (select epm_party_id
				from email_check_party_map
				where epm_name = 'CHECK_BANK_PSP'
				and epm_group = 'EXCLUDE'
				and epm_party_type = 'C'
				and epm_support_multi_entry = 1)
			and th_create_timestamp between to_date(:hv_dur_start, 'DD-MON-YYYY HH24:MI:SS') and to_date(:hv_dur_end, 'DD-MON-YYYY HH24:MI:SS')
			and exists (select 1
				from txn_detail
				where td_txn_id = th_txn_id
				and td_bank_code = :hv_bank_code)
			and exists (select 1
				from txn_psp_detail
				where tp_txn_id = th_txn_id
				and tp_psp_id = :hv_psp_id)
			and th_status = 'W'
			and th_ar_ind is null
			and th_sub_status = '102'
			order by th_create_timestamp desc
		)
		where rownum <= :hv_total_pend_cnt
		group by th_client_ip
		order by count(1) desc; */ 


	hTmp = RecordSet_GetFirst(rRecordSet);
	while (hTmp) {
		// party_id
		if (GetField_CString(hTmp, "party_id", &csTmp)) {
DEBUGLOG(("gen_pending_count_table:: party_id = [%s]\n", csTmp));
			hv_psp_id.len = strlen(csTmp);
			memcpy(hv_psp_id.arr, csTmp, hv_psp_id.len);
		}

		// party_name
		if (GetField_CString(hTmp, "party_name", &csPartyName)) {
DEBUGLOG(("gen_pending_count_table:: party_name = [%s]\n", csPartyName));
		}

		// bank_code
		if (GetField_CString(hTmp, "bank_code", &csTmp)) {
DEBUGLOG(("gen_pending_count_table:: bank_code = [%s]\n", csTmp));
			hv_bank_code.len = strlen(csTmp);
			memcpy(hv_bank_code.arr, csTmp, hv_bank_code.len);
		}

		// bank_name
		if (GetField_CString(hTmp, "bank_name", &csBankName)) {
DEBUGLOG(("gen_pending_count_table:: bank_name = [%s]\n", csBankName));
		}

		// dur_start
		if (GetField_CString(hTmp, "dur_start", &csDurStart)) {
DEBUGLOG(("gen_pending_count_table:: dur_start = [%s]\n", csDurStart));
			hv_dur_start.len = strlen(csDurStart);
			memcpy(hv_dur_start.arr, csDurStart, hv_dur_start.len);
		}

		// dur_end
		if (GetField_CString(hTmp, "dur_end", &csDurEnd)) {
DEBUGLOG(("gen_pending_count_table:: dur_end = [%s]\n", csDurEnd));
			hv_dur_end.len = strlen(csDurEnd);
			memcpy(hv_dur_end.arr, csDurEnd, hv_dur_end.len);
		}

		// pend_cnt
		if (GetField_Int(hTmp, "pend_cnt", &iTmp)) {
DEBUGLOG(("gen_pending_count_table:: pend_cnt = [%d]\n", iTmp));
			hv_total_pend_cnt = iTmp;
		}

DEBUGLOG(("gen_pending_count_table:: exact_count_val = [%d]\n", iExactCntVal));

		iCustCnt = 0;

		/* EXEC SQL OPEN c_cursor_getpendingcnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.stmt = sq0002;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )117;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqcmod = (unsigned int )0;
  sqlstm.sqhstv[0] = (unsigned char  *)&hv_dur_start;
  sqlstm.sqhstl[0] = (unsigned long )23;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&hv_dur_end;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)0;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&hv_bank_code;
  sqlstm.sqhstl[2] = (unsigned long )13;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)0;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&hv_psp_id;
  sqlstm.sqhstl[3] = (unsigned long )13;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)0;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&hv_total_pend_cnt;
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
  if (sqlca.sqlcode < 0) goto getpendingcnt_error;
}


		do {
			/* EXEC SQL FETCH c_cursor_getpendingcnt
			INTO
				:v_cust_ip:ind_cust_ip,
				:v_pend_cnt:ind_pend_cnt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 9;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )152;
   sqlstm.selerr = (unsigned short)1;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlstm.sqfoff = (         int )0;
   sqlstm.sqfmod = (unsigned int )2;
   sqlstm.sqhstv[0] = (unsigned char  *)&v_cust_ip;
   sqlstm.sqhstl[0] = (unsigned long )28;
   sqlstm.sqhsts[0] = (         int  )0;
   sqlstm.sqindv[0] = (         short *)&ind_cust_ip;
   sqlstm.sqinds[0] = (         int  )0;
   sqlstm.sqharm[0] = (unsigned long )0;
   sqlstm.sqadto[0] = (unsigned short )0;
   sqlstm.sqtdso[0] = (unsigned short )0;
   sqlstm.sqhstv[1] = (unsigned char  *)&v_pend_cnt;
   sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
   sqlstm.sqhsts[1] = (         int  )0;
   sqlstm.sqindv[1] = (         short *)&ind_pend_cnt;
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
   if (sqlca.sqlcode < 0) goto getpendingcnt_error;
}



			if (SQLCODE == SQL_NOT_FOUND) {
				break;
			}

			// cust_ip
			if (ind_cust_ip >= 0) {
				v_cust_ip.arr[v_cust_ip.len] = '\0';
DEBUGLOG(("gen_pending_count_table:: cust_ip = [%s]\n", v_cust_ip.arr));
			}

			// pend_cnt
			if (ind_pend_cnt >= 0) {
DEBUGLOG(("gen_pending_count_table:: pend_cnt = [%d]\n", v_pend_cnt));
			}

			if (v_pend_cnt > iExactCntVal) {
				printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td></tr>\n", csDurStart, csDurEnd, csPartyName, csBankName, v_cust_ip.arr, v_pend_cnt);
			} else {
				iCustCnt++;
			}
		} while(PD_TRUE);
		/* EXEC SQL CLOSE c_cursor_getpendingcnt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 9;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )175;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto getpendingcnt_error;
}



		if (iCustCnt > 0) {
			hRec = (hash_t*) malloc (sizeof(hash_t));
			hash_init(hRec, 0);

			PutField_CString(hRec, "dur_start", csDurStart);
			PutField_CString(hRec, "dur_end", csDurEnd);
			PutField_CString(hRec, "party_name", csPartyName);
			PutField_CString(hRec, "bank_name", csBankName);
			PutField_Int(hRec, "cust_cnt", iCustCnt);

			RecordSet_Add(rRec, hRec);
		}

		hTmp = RecordSet_GetNext(rRecordSet);
	}

	printf("</table>\n");

	printf("<br>\n");
	if (iExactCntVal == 1)
		printf("<b>Number of customer with pending count = %d</b>\n", iExactCntVal);
	else
		printf("<b>Number of customer with pending count <= %d</b>\n", iExactCntVal);
	printf("<table border=\"1\">\n");
	if (iExactCntVal == 1)
		printf("<tr align=\"center\"><td><b>Duration Start</b></td><td><b>Duration End</b></td><td><b>PSP Account Name</b></td><td><b>Consumer Deposit Bank</b></td><td><b>#Cust with Pending = %d</b></td></tr>\n", iExactCntVal);
	else
		printf("<tr align=\"center\"><td><b>Duration Start</b></td><td><b>Duration End</b></td><td><b>PSP Account Name</b></td><td><b>Consumer Deposit Bank</b></td><td><b>#Cust with Pending <= %d</b></td></tr>\n", iExactCntVal);

	hTmp = RecordSet_GetFirst(rRec);
	while (hTmp) {
		// party_name
		if (GetField_CString(hTmp, "party_name", &csPartyName)) {
DEBUGLOG(("gen_pending_count_table:: party_name = [%s]\n", csPartyName));
		}

		// bank_name
		if (GetField_CString(hTmp, "bank_name", &csBankName)) {
DEBUGLOG(("gen_pending_count_table:: bank_name = [%s]\n", csBankName));
		}

		// dur_start
		if (GetField_CString(hTmp, "dur_start", &csDurStart)) {
DEBUGLOG(("gen_pending_count_table:: dur_start = [%s]\n", csDurStart));
		}

		// dur_end
		if (GetField_CString(hTmp, "dur_end", &csDurEnd)) {
DEBUGLOG(("gen_pending_count_table:: dur_end = [%s]\n", csDurEnd));
		}

		// cust_cnt
		if (GetField_Int(hTmp, "cust_cnt", &iCustCnt)) {
DEBUGLOG(("gen_pending_count_table:: cust_cnt = [%d]\n", iCustCnt));
		}

		printf("<tr align=\"center\"><td>%s</td><td>%s</td><td>%s</td><td>%s</td><td>%d</td></tr>\n", csDurStart, csDurEnd, csPartyName, csBankName, iCustCnt);

		hTmp = RecordSet_GetNext(rRec);
	}

	printf("</table>\n");

	RecordSet_Destroy(rRec);
	FREE_ME(rRec);

	return iRet;

getpendingcnt_error:
DEBUGLOG(("getpendingcnt_error code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	/* EXEC SQL CLOSE c_cursor_getpendingcnt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 9;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )190;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


	return PD_ERR;
}
