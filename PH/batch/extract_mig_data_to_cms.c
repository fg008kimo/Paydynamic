
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
           char  filnam[27];
};
static struct sqlcxp sqlfpn =
{
    26,
    "extract_mig_data_to_cms.pc"
};


static unsigned int sqlctx = 840685219;


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
   unsigned char  *sqhstv[15];
   unsigned long  sqhstl[15];
            int   sqhsts[15];
            short *sqindv[15];
            int   sqinds[15];
   unsigned long  sqharm[15];
   unsigned long  *sqharc[15];
   unsigned short  sqadto[15];
   unsigned short  sqtdso[15];
} sqlstm = {12,15};

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
" LEFT join txn_elements tmk on tmk .\
 te_txn_id = th_txn_id and tmk . te_txn_element_type = 'MAMT' LEFT join par_d\
sp_id_map on di_txn_nmb = th_txn_id            ";

 static char *sq0003 = 
"pe = 'TFEE' and tfee . te_party_type\
 = 'M' LEFT join txn_elements tmk on tmk . te_txn_id = th_txn_id and tmk . te\
_txn_element_type = 'MAMT'            ";

 static char *sq0005 = 
"ount , 0 ) , 'FM9,999,990.00' ) mark\
up_amount from ( select th_merchant_id , sd_txn_id , sd_request_ccy , sd_requ\
est_amt , sd_deliver_ccy , sd_deliver_amt , th_create_timestamp , th_approval\
_timestamp , sd_deliver_date , mn_username from ( select th_txn_id , th_merch\
ant_id , th_create_timestamp , th_approval_timestamp from txn_header where th\
_status in ( 'C' , 'R' ) and th_ar_ind = 'A' and th_txn_code = 'STR' ) , merc\
hant_settlement_detail , par_def_merch_nmb_map , par_merch_date_map where th_\
txn_id = sd_txn_id and sd_deliver_date = :b0 and th_merchant_id = mn_merchant\
_id and th_merchant_id = mdm_merchant_id and sd_deliver_date >= mdm_start_dat\
e and sd_deliver_date <= mdm_end_date ) left join txn_elements tfee on tfee .\
 te_txn_id = sd_txn_id and tfee . te_txn_element_type = 'TFEE' and tfee . te_\
party_type = 'M' left join txn_elements tmk on tmk . te_txn_id = sd_txn_id an\
d tmk . te_txn_element_type = 'MAMT'            ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,2208,0,9,252,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,254,0,0,15,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
99,0,0,1,0,0,15,393,0,0,0,0,0,1,0,
114,0,0,1,0,0,15,399,0,0,0,0,0,1,0,
129,0,0,2,0,0,32,400,0,0,0,0,0,1,0,
144,0,0,3,2199,0,9,548,0,2049,1,1,0,1,0,1,9,0,0,
163,0,0,3,0,0,13,550,0,0,15,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
238,0,0,3,0,0,15,693,0,0,0,0,0,1,0,
253,0,0,3,0,0,15,699,0,0,0,0,0,1,0,
268,0,0,4,0,0,32,700,0,0,0,0,0,1,0,
283,0,0,5,1955,0,9,825,0,2049,1,1,0,1,0,1,9,0,0,
302,0,0,5,0,0,13,827,0,0,13,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
369,0,0,5,0,0,15,945,0,0,0,0,0,1,0,
384,0,0,5,0,0,15,951,0,0,0,0,0,1,0,
399,0,0,6,0,0,32,952,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2013/04/22              Stan Poon
*/
#define _XOPEN_SOURCE

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

#define	PD_OPEN_TAG		"<tr><td>"
#define PD_OPEN_TAG_CS		"<tr><td style='mso-number-format:\\@'>"
#define	PD_NEXT_TAG		"</td><td>"
#define	PD_NEXT_TAG_CS		"</td><td style='mso-number-format:\\@'>"
#define	PD_END_TAG		"</td></tr>"
//"<style> .format{ mso-number-format:'\\@';} </style>"

#define PD_MIN_ARGC		7
char*	csDefaultCcy = "RMB";

char    cs_outfile[PD_MAX_FILE_LEN + 1];
char    cs_date[PD_DATE_LEN + 1];
char	cs_type[3 + 1];

char    cDebug='Y';

int process_txn_old_dsp(const char* csDate, int* iOldAcceptCount, double* dOldTxnAmt,
		FILE *fp);
int process_txn_dsp(const char* csDate,
		FILE *fp);
int process_txn_stt(const char* csDate,
		FILE *fp);

int batch_init(int argc, char* argv[])
{
	if (argc < PD_MIN_ARGC) {
		printf("***usage:  -o outputfile -d Date -t <dsp/stt>\n");
		return FAILURE;
	}

	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;
	strcpy(cs_outfile,"");
	strcpy(cs_date,"");
	strcpy(cs_type,"");

	while ((c = getopt(argc,argv,"o:d:t:")) != EOF) {
		switch (c) {
			case 'o':
				strcpy(cs_outfile, optarg);
				break;
			case 'd':
				strcpy(cs_date, optarg);
				break;
			case 't':
				strcpy(cs_type, optarg);
				break;
			default:
				return FAILURE;
		}
	}

	if (!strcmp(cs_outfile,"") || !strcmp(cs_date,"") || !strcmp(cs_type,""))
		return FAILURE;

	if (strlen(cs_date) > PD_DATE_LEN)
		return FAILURE;

	return SUCCESS;
}

int batch_proc(int argc, char* argv[])
{
	int     iRet = SUCCESS;
	char    cs_outfile_name[PD_MAX_FILE_LEN + 1];
	FILE    *fp;
	
	iRet = parse_arg(argc,argv);

	if (iRet != SUCCESS){
		printf("usage:  -o outputfile -d Date -t <dsp/stt>\n");
		return (iRet);
	}

	CreateReportPathCustomized((unsigned char*)cs_outfile_name,cs_date);
DEBUGLOG(("batch_proc:path [%s]\n",cs_outfile_name));
       	sprintf(cs_outfile_name, "%s/%s", cs_outfile_name, cs_outfile);
DEBUGLOG(("batch_proc:path [%s]\n",cs_outfile_name));

       	fp = fopen(cs_outfile_name,"w");
       	if (fp == NULL) {
DEBUGLOG(("batch_proc:unable to open [%s]\n",cs_outfile_name));
       	} else {
		if (!strcmp(cs_type,"dsp")) {
			iRet = process_txn_dsp(cs_date,fp);
DEBUGLOG(("process_txn_dsp: iRet [%d]\n",iRet));
		} else if (!strcmp(cs_type,"stt")) {
			iRet = process_txn_stt(cs_date,fp);
DEBUGLOG(("process_txn_stt: iRet [%d]\n",iRet));
		}
	}
	
       	fclose(fp);
	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int process_txn_old_dsp(const char* csDate, int* iOldAcceptCount, double* dOldTxnAmt,
		FILE *fp)
{	       
	int     iRet = SUCCESS;
	double	dTotalTxnAmt = 0.0;
	int	iAcceptCount = 0, iFailCount = 0;

	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;


		/* varchar	v_req_ref_num[10 +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_req_ref_num;

		/* varchar	v_txn_ref[10 +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_txn_ref;

		/* varchar	v_card_num[0 +1]; */ 
struct { unsigned short len; unsigned char arr[1]; } v_card_num;

		/* varchar	v_ewallet_id[PD_AC_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_ewallet_id;

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_req_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_req_datetime;

		/* varchar	v_comp_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_comp_datetime;

		/* varchar	v_status[9 +1]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_status;

		/* varchar v_tp_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_tp_txn_ccy;

		double	v_tp_txn_amount;
		/* varchar	v_txn_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_amt;

		/* varchar	v_com_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_com_amt;

		/* varchar	v_net_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_net_amt;

		/* varchar	v_markup_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_markup_amt;


		short	ind_req_ref_num = -1;
		short	ind_txn_ref = -1;
		short	ind_card_num = -1;
		short	ind_ewallet_id = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_req_datetime = -1;
		short	ind_comp_datetime = -1;
		short	ind_status = -1;
		short	ind_tp_txn_ccy = -1;
		short	ind_tp_txn_amount = -1;
		short	ind_txn_amt = -1;
		short	ind_com_amt = -1;
		short	ind_net_amt = -1;
		short	ind_markup_amt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen(csDate);
	memcpy(hv_host_date.arr,csDate,hv_host_date.len);
DEBUGLOG(("process_txn_old_dsp::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));

	/* EXEC SQL DECLARE c_cursor_gettxn_dsi CURSOR FOR
		SELECT case when length(di_order_id) <= 10 then th_txn_id
			else substr(di_order_id,1,4) || substr(di_order_id,-6,6) end req_ref_num,
			th_txn_id txn_ref,
			'' card_num,
			mn_username ewallet_id,
			th_merchant_id merchant_id,
			th_merchant_ref merchant_ref,
			to_char(th_create_timestamp, 'MM/DD/YYYY HH24:MI:SS') req_datetime,
			to_char(th_approval_timestamp, 'MM/DD/YYYY HH24:MI:SS') comp_datetime,
			'Completed' status,
			decode(tp_txn_ccy,'CNY','RMB',tp_txn_ccy) tp_txn_ccy,
			NVL(tp_txn_amount, 0) tp_txn_amount,
			decode(tp_txn_ccy,'CNY','RMB',tp_txn_ccy)
			   || to_char(NVL(tp_txn_amount, 0), 'FM9,999,990.00') txn_amt,
			decode(NVL(tfee.te_ccy, td_txn_ccy),'CNY','RMB',NVL(tfee.te_ccy, td_txn_ccy))
			   || to_char(NVL(tfee.te_amount,0), 'FM9,999,990.00') comm_amt,
			decode(td_txn_ccy,'CNY','RMB',td_txn_ccy)
			   || to_char(NVL(th_net_amount, 0), 'FM9,999,990.00') net_amt,
			decode(NVL(tmk.te_ccy, td_txn_ccy),'CNY','RMB',NVL(tmk.te_ccy, td_txn_ccy))
			   || to_char(NVL(tmk.te_amount, 0), 'FM9,999,990.00') markup_amt
		FROM
			(SELECT th_txn_id,
				th_merchant_id,
				th_merchant_ref,
				tp_txn_ccy,
				tp_txn_amount,
				td_txn_ccy,
				th_net_amount,
				th_create_timestamp,
				th_approval_timestamp,
				mn_username
			FROM
				(SELECT th_txn_id,
					th_merchant_id,
					th_merchant_ref,
					th_net_amount,
					th_create_timestamp,
					th_approval_timestamp
				FROM txn_header
				WHERE th_approval_date = :hv_host_date
				 and th_status in ('C','R')
				 and th_ar_ind = 'A'
				 and th_txn_code in ('DSI', 'MSI')
				 and th_vnc_ref_num is not null),
				txn_detail,
				txn_psp_detail,
				--par_merch_profile,
				par_def_merch_nmb_map,
				par_merch_date_map
			WHERE th_txn_id = td_txn_id
			 and th_txn_id = tp_txn_id
			 and th_merchant_id = mn_merchant_id
			 and th_merchant_id = mdm_merchant_id
			 and mn_country = 'CN'
			 and th_approval_timestamp >= to_date(mdm_start_date||mdm_start_time,'YYYYMMDDHH24:MI:SS'))
		LEFT join txn_elements tfee
		 on tfee.te_txn_id = th_txn_id
		 and tfee.te_txn_element_type = 'TFEE'
		 and tfee.te_party_type = 'M'
		LEFT join txn_elements tmk
		 on tmk.te_txn_id = th_txn_id
		 and tmk.te_txn_element_type = 'MAMT'
		LEFT join par_dsp_id_map
		 on di_txn_nmb = th_txn_id; */ 


	/* EXEC SQL OPEN c_cursor_gettxn_dsi; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 1;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT case when length ( di_order_id ) <= 10 then th_txn_id else substr\
 ( di_order_id , 1 , 4 ) || substr ( di_order_id , - 6 , 6 ) end req_ref_num\
 , th_txn_id txn_ref , '' card_num , mn_username ewallet_id , th_merchant_id\
 merchant_id , th_merchant_ref merchant_ref , to_char ( th_create_timestamp \
, 'MM/DD/YYYY HH24:MI:SS' ) req_datetime , to_char ( th_approval_timestamp ,\
 'MM/DD/YYYY HH24:MI:SS' ) comp_datetime , 'Completed' status , decode ( tp_\
txn_ccy , 'CNY' , 'RMB' , tp_txn_ccy ) tp_txn_ccy , NVL ( tp_txn_amount , 0 \
) tp_txn_amount , decode ( tp_txn_ccy , 'CNY' , 'RMB' , tp_txn_ccy ) || to_c\
har ( NVL ( tp_txn_amount , 0 ) , 'FM9,999,990.00' ) txn_amt , decode ( NVL \
( tfee . te_ccy , td_txn_ccy ) , 'CNY' , 'RMB' , NVL ( tfee . te_ccy , td_tx\
n_ccy ) ) || to_char ( NVL ( tfee . te_amount , 0 ) , 'FM9,999,990.00' ) com\
m_amt , decode ( td_txn_ccy , 'CNY' , 'RMB' , td_txn_ccy ) || to_char ( NVL \
( th_net_amount , 0 ) , 'FM9,999,990.00' ) net_amt , decode ( NVL ( tmk . te\
_ccy , td_txn_ccy ) , 'CNY' , 'RMB' , NV");
 sqlbuft((void **)0,
   "L ( tmk . te_ccy , td_txn_ccy ) ) || to_char ( NVL ( tmk . te_amount , 0\
 ) , 'FM9,999,990.00' ) markup_amt FROM ( SELECT th_txn_id , th_merchant_id \
, th_merchant_ref , tp_txn_ccy , tp_txn_amount , td_txn_ccy , th_net_amount \
, th_create_timestamp , th_approval_timestamp , mn_username FROM ( SELECT th\
_txn_id , th_merchant_id , th_merchant_ref , th_net_amount , th_create_times\
tamp , th_approval_timestamp FROM txn_header WHERE th_approval_date = :b0 an\
d th_status in ( 'C' , 'R' ) and th_ar_ind = 'A' and th_txn_code in ( 'DSI' \
, 'MSI' ) and th_vnc_ref_num is not null ) , txn_detail , txn_psp_detail , p\
ar_def_merch_nmb_map , par_merch_date_map WHERE th_txn_id = td_txn_id and th\
_txn_id = tp_txn_id and th_merchant_id = mn_merchant_id and th_merchant_id =\
 mdm_merchant_id and mn_country = 'CN' and th_approval_timestamp >= to_date \
( mdm_start_date || mdm_start_time , 'YYYYMMDDHH24:MI:SS' ) ) LEFT join txn_\
elements tfee on tfee . te_txn_id = th_txn_id and tfee . te_txn_element_type\
 = 'TFEE' and tfee . te_party_type = 'M'");
 sqlstm.stmt = sq0001;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )5;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_host_date;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {    
		/* EXEC SQL FETCH c_cursor_gettxn_dsi
		INTO
			:v_req_ref_num:ind_req_ref_num,
			:v_txn_ref:ind_txn_ref,
			:v_card_num:ind_card_num,
			:v_ewallet_id:ind_ewallet_id,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_req_datetime:ind_req_datetime,
			:v_comp_datetime:ind_comp_datetime,
			:v_status:ind_status,
			:v_tp_txn_ccy:ind_tp_txn_ccy,
			:v_tp_txn_amount:ind_tp_txn_amount,
			:v_txn_amt:ind_txn_amt,
			:v_com_amt:ind_com_amt,
			:v_net_amt:ind_net_amt,
			:v_markup_amt:ind_markup_amt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )24;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_req_ref_num;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_req_ref_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_ref;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_ref;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_card_num;
  sqlstm.sqhstl[2] = (unsigned long )3;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_card_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ewallet_id;
  sqlstm.sqhstl[3] = (unsigned long )103;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ewallet_id;
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
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_req_datetime;
  sqlstm.sqhstl[6] = (unsigned long )22;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_req_datetime;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_comp_datetime;
  sqlstm.sqhstl[7] = (unsigned long )22;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_comp_datetime;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[8] = (unsigned long )12;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_status;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_tp_txn_ccy;
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_tp_txn_ccy;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_tp_txn_amount;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_tp_txn_amount;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_com_amt;
  sqlstm.sqhstl[12] = (unsigned long )23;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_com_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_net_amt;
  sqlstm.sqhstl[13] = (unsigned long )23;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_net_amt;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[14] = (unsigned long )23;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
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

/* Field #0 req_ref_num */
		if (ind_req_ref_num < 0){
DEBUGLOG(("process_txn_old_dsp() ind_req_ref_num < 0   FAIL!!!\n"));
			iFailCount++;
			continue;
		}

/* tp_txn_ccy & tp_txn_amount */
		if (ind_tp_txn_ccy >=0) {
			v_tp_txn_ccy.arr[v_tp_txn_ccy.len] = '\0';
		} else {
			v_tp_txn_ccy.arr[0] = '\0';
		}
		if (ind_tp_txn_amount < 0) v_tp_txn_amount = 0.0;

		if (strcmp(csDefaultCcy,(char*)v_tp_txn_ccy.arr) && v_tp_txn_amount != 0.0) {
DEBUGLOG(("process_txn_old_dsp() NOT [%s]   FAIL!!!\n",csDefaultCcy));
			iFailCount++;
			continue;
		} else {
			dTotalTxnAmt += v_tp_txn_amount;
			iAcceptCount++;
		}

/* Field #0 req_ref_num */
		fprintf(fp,"%s%.*s%s",PD_OPEN_TAG_CS,v_req_ref_num.len,v_req_ref_num.arr,PD_NEXT_TAG_CS);

/* Field #1 txn_ref*/
		if (ind_txn_ref >=0 ) {
			v_txn_ref.arr[v_txn_ref.len] = '\0';
			fprintf(fp,"%.*s",v_txn_ref.len,v_txn_ref.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #2 card_num*/
		if (ind_card_num >=0 ) {
			v_card_num.arr[v_card_num.len] = '\0';
			fprintf(fp,"%.*s",v_card_num.len,v_card_num.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #3 ewallet_id*/
		if (ind_ewallet_id >=0 ) {
			v_ewallet_id.arr[v_ewallet_id.len] = '\0';
			fprintf(fp,"%.*s",v_ewallet_id.len,v_ewallet_id.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #4 merchant_ref*/
		if (ind_merchant_ref >=0 ) {
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			fprintf(fp,"%.*s",v_merchant_ref.len,v_merchant_ref.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #5 req_datetime*/
		if (ind_req_datetime >=0 ) {
			v_req_datetime.arr[v_req_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_req_datetime.len,v_req_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #6 comp_datetime*/
		if (ind_comp_datetime >=0 ) {
			v_comp_datetime.arr[v_comp_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_comp_datetime.len,v_comp_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #7 status*/
		if (ind_status >=0 ) {
			v_status.arr[v_status.len] = '\0';
			fprintf(fp,"%.*s",v_status.len,v_status.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #8 txn_amt*/
		if (ind_txn_amt >=0 ) {
			v_txn_amt.arr[v_txn_amt.len] = '\0';
			fprintf(fp,"%.*s",v_txn_amt.len,v_txn_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #9 com_amt*/
		if (ind_com_amt >=0 ) {
			v_com_amt.arr[v_com_amt.len] = '\0';
			fprintf(fp,"%.*s",v_com_amt.len,v_com_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #10 net_amt*/
		if (ind_net_amt >=0 ) {
			v_net_amt.arr[v_net_amt.len] = '\0';
			fprintf(fp,"%.*s",v_net_amt.len,v_net_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #11 markup_amt*/
		if (ind_markup_amt >=0 ) {
			v_markup_amt.arr[v_markup_amt.len] = '\0';
			fprintf(fp,"%.*s",v_markup_amt.len,v_markup_amt.arr);
		}
		fprintf(fp,"%s\n",PD_END_TAG);

 	}
	while(PD_TRUE && iRet == SUCCESS);

	if (iFailCount > 0) {
		printf("%d records fail",iFailCount);
DEBUGLOG(("process_txn_old_dsp() Total Fail [%d]\n",iFailCount));
	}

	*iOldAcceptCount = iAcceptCount;
	*dOldTxnAmt = dTotalTxnAmt;
DEBUGLOG(("process_txn_old_dsp() Total records [%d]\n",iAcceptCount));
DEBUGLOG(("process_txn_old_dsp() Total Amounts [%.2lf]\n",dTotalTxnAmt));

	/* EXEC SQL CLOSE c_cursor_gettxn_dsi; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )99;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	return iRet;
sql_error:
    DEBUGLOG(("process_txn_old_dsp error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn_dsi; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )114;
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
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )129;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int process_txn_dsp(const char* csDate,
		FILE *fp)
{	       
	int     iRet = SUCCESS;
	double	dTotalTxnAmt = 0.0;
	int	iAcceptCount = 0, iFailCount = 0;

	struct	tm tm;
	char	*sysdatetime = getdatetime();
	char	csFormatSysDateTime[21];
	char	csFormatDate[12];

	strptime(csDate, "%Y%m%d", &tm);
	strftime(csFormatDate, sizeof(csFormatDate), "%Y-%h-%d", &tm);
	strptime(sysdatetime, "%Y%m%d%H%M%S", &tm);
	strftime(csFormatSysDateTime, sizeof(csFormatSysDateTime), "%Y-%h-%d %T", &tm);

	//printf("%s to %s\n%s to %s\n",csDate,csFormatDate,sysdatetime,csFormatSysDateTime);

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%sAd Hoc ChinaPay Purchase Transaction Details Report (PTDR_CP)%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%sFrom%s%s 00:00:00%s\n",PD_OPEN_TAG,PD_NEXT_TAG,csFormatDate,PD_END_TAG);
	fprintf(fp,"%sTo%s%s 23:59:59%s\n",PD_OPEN_TAG,PD_NEXT_TAG,csFormatDate,PD_END_TAG);
	fprintf(fp,"%sGenerated On%s%s%s\n",PD_OPEN_TAG,PD_NEXT_TAG,csFormatSysDateTime,PD_END_TAG);
	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%sMerchant Wallet%sAll%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_END_TAG);
	fprintf(fp,"%sReq. Reference Number%sTransaction Reference%sCard Number%se_Wallet ID%sMerchant Ref.%sRequest Date and Time%sComplete Date and Time%sStatus%sTransaction Amount%sCommission Amount%sNet Amount%sMarkup Amount%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_END_TAG);

	iRet = process_txn_old_dsp(cs_date,&iAcceptCount,&dTotalTxnAmt,fp);


	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_host_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_host_date;


		/* varchar	v_req_ref_num[10 +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_req_ref_num;

		/* varchar	v_txn_ref[10 +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_txn_ref;

		/* varchar	v_card_num[0 +1]; */ 
struct { unsigned short len; unsigned char arr[1]; } v_card_num;

		/* varchar	v_ewallet_id[PD_AC_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_ewallet_id;

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_req_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_req_datetime;

		/* varchar	v_comp_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_comp_datetime;

		/* varchar	v_status[9 +1]; */ 
struct { unsigned short len; unsigned char arr[10]; } v_status;

		/* varchar v_tp_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_tp_txn_ccy;

		double	v_tp_txn_amount;
		/* varchar	v_txn_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_amt;

		/* varchar	v_com_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_com_amt;

		/* varchar	v_net_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_net_amt;

		/* varchar	v_markup_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_markup_amt;


		short	ind_req_ref_num = -1;
		short	ind_txn_ref = -1;
		short	ind_card_num = -1;
		short	ind_ewallet_id = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_req_datetime = -1;
		short	ind_comp_datetime = -1;
		short	ind_status = -1;
		short	ind_tp_txn_ccy = -1;
		short	ind_tp_txn_amount = -1;
		short	ind_txn_amt = -1;
		short	ind_com_amt = -1;
		short	ind_net_amt = -1;
		short	ind_markup_amt = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_host_date.len = strlen(csDate);
	memcpy(hv_host_date.arr,csDate,hv_host_date.len);
DEBUGLOG(("process_txn_dsp::host_date = [%.*s]\n",hv_host_date.len,hv_host_date.arr));

	/* EXEC SQL DECLARE c_cursor_gettxn_dsp CURSOR FOR
		SELECT case when length(th_txn_id) <= 10 then th_txn_id
			else substr(th_txn_id,-10,10) end req_ref_num,
			case when length(th_txn_id) <= 10 then th_txn_id
			else substr(th_txn_id,-10,10) end txn_ref,
			'' card_num,
			mn_username ewallet_id,
			th_merchant_id merchant_id,
			th_merchant_ref merchant_ref,
			to_char(th_create_timestamp, 'MM/DD/YYYY HH24:MI:SS') req_datetime,
			to_char(th_approval_timestamp, 'MM/DD/YYYY HH24:MI:SS') comp_datetime,
			'Completed' status,
			decode(tp_txn_ccy,'CNY','RMB',tp_txn_ccy) tp_txn_ccy,
			NVL(tp_txn_amount, 0) tp_txn_amount,
			decode(tp_txn_ccy,'CNY','RMB',tp_txn_ccy)
			   || to_char(NVL(tp_txn_amount, 0), 'FM9,999,990.00') txn_amt,
			decode(NVL(tfee.te_ccy, td_txn_ccy),'CNY','RMB',NVL(tfee.te_ccy, td_txn_ccy))
			   || to_char(NVL(tfee.te_amount,0), 'FM9,999,990.00') comm_amt,
			decode(td_txn_ccy,'CNY','RMB',td_txn_ccy)
			   || to_char(NVL(th_net_amount, 0), 'FM9,999,990.00') net_amt,
			decode(NVL(tmk.te_ccy, td_txn_ccy),'CNY','RMB',NVL(tmk.te_ccy, td_txn_ccy))
			   || to_char(NVL(tmk.te_amount, 0), 'FM9,999,990.00') markup_amt
		FROM
			(SELECT th_txn_id,
				th_merchant_id,
				th_merchant_ref,
				tp_txn_ccy,
				tp_txn_amount,
				td_txn_ccy,
				th_net_amount,
				th_create_timestamp,
				th_approval_timestamp,
				mn_username
			FROM
				(SELECT th_txn_id,
					th_merchant_id,
					th_merchant_ref,
					th_net_amount,
					th_create_timestamp,
					th_approval_timestamp,
					th_approval_date
				FROM txn_header
				WHERE th_approval_date = :hv_host_date
				 and th_status in ('C','R')
				 and th_ar_ind = 'A'
				 and th_txn_code in ('DSI', 'MSI')
				 and th_vnc_ref_num is null),
				txn_detail,
				txn_psp_detail,
				--par_merch_profile,
				par_def_merch_nmb_map,
				par_merch_date_map
			WHERE th_txn_id = td_txn_id
			 and th_txn_id = tp_txn_id
			 and th_merchant_id = mn_merchant_id
			 and th_merchant_id = mdm_merchant_id
			 and mn_country = 'CN'
			 and th_approval_date >= mdm_start_date and th_approval_date <= mdm_end_date)
		LEFT join txn_elements tfee
		 on tfee.te_txn_id = th_txn_id
		 and tfee.te_txn_element_type = 'TFEE'
		 and tfee.te_party_type = 'M'
		LEFT join txn_elements tmk
		 on tmk.te_txn_id = th_txn_id
		 and tmk.te_txn_element_type = 'MAMT'; */ 


	/* EXEC SQL OPEN c_cursor_gettxn_dsp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "SELECT case when length ( th_txn_id ) <= 10 then th_txn_id else substr (\
 th_txn_id , - 10 , 10 ) end req_ref_num , case when length ( th_txn_id ) <=\
 10 then th_txn_id else substr ( th_txn_id , - 10 , 10 ) end txn_ref , '' ca\
rd_num , mn_username ewallet_id , th_merchant_id merchant_id , th_merchant_r\
ef merchant_ref , to_char ( th_create_timestamp , 'MM/DD/YYYY HH24:MI:SS' ) \
req_datetime , to_char ( th_approval_timestamp , 'MM/DD/YYYY HH24:MI:SS' ) c\
omp_datetime , 'Completed' status , decode ( tp_txn_ccy , 'CNY' , 'RMB' , tp\
_txn_ccy ) tp_txn_ccy , NVL ( tp_txn_amount , 0 ) tp_txn_amount , decode ( t\
p_txn_ccy , 'CNY' , 'RMB' , tp_txn_ccy ) || to_char ( NVL ( tp_txn_amount , \
0 ) , 'FM9,999,990.00' ) txn_amt , decode ( NVL ( tfee . te_ccy , td_txn_ccy\
 ) , 'CNY' , 'RMB' , NVL ( tfee . te_ccy , td_txn_ccy ) ) || to_char ( NVL (\
 tfee . te_amount , 0 ) , 'FM9,999,990.00' ) comm_amt , decode ( td_txn_ccy \
, 'CNY' , 'RMB' , td_txn_ccy ) || to_char ( NVL ( th_net_amount , 0 ) , 'FM9\
,999,990.00' ) net_amt , decode ( NVL ( ");
 sqlbuft((void **)0,
   "tmk . te_ccy , td_txn_ccy ) , 'CNY' , 'RMB' , NVL ( tmk . te_ccy , td_tx\
n_ccy ) ) || to_char ( NVL ( tmk . te_amount , 0 ) , 'FM9,999,990.00' ) mark\
up_amt FROM ( SELECT th_txn_id , th_merchant_id , th_merchant_ref , tp_txn_c\
cy , tp_txn_amount , td_txn_ccy , th_net_amount , th_create_timestamp , th_a\
pproval_timestamp , mn_username FROM ( SELECT th_txn_id , th_merchant_id , t\
h_merchant_ref , th_net_amount , th_create_timestamp , th_approval_timestamp\
 , th_approval_date FROM txn_header WHERE th_approval_date = :b0 and th_stat\
us in ( 'C' , 'R' ) and th_ar_ind = 'A' and th_txn_code in ( 'DSI' , 'MSI' )\
 and th_vnc_ref_num is null ) , txn_detail , txn_psp_detail , par_def_merch_\
nmb_map , par_merch_date_map WHERE th_txn_id = td_txn_id and th_txn_id = tp_\
txn_id and th_merchant_id = mn_merchant_id and th_merchant_id = mdm_merchant\
_id and mn_country = 'CN' and th_approval_date >= mdm_start_date and th_appr\
oval_date <= mdm_end_date ) LEFT join txn_elements tfee on tfee . te_txn_id \
= th_txn_id and tfee . te_txn_element_ty");
 sqlstm.stmt = sq0003;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )144;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_host_date;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {    
		/* EXEC SQL FETCH c_cursor_gettxn_dsp
		INTO
			:v_req_ref_num:ind_req_ref_num,
			:v_txn_ref:ind_txn_ref,
			:v_card_num:ind_card_num,
			:v_ewallet_id:ind_ewallet_id,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_req_datetime:ind_req_datetime,
			:v_comp_datetime:ind_comp_datetime,
			:v_status:ind_status,
			:v_tp_txn_ccy:ind_tp_txn_ccy,
			:v_tp_txn_amount:ind_tp_txn_amount,
			:v_txn_amt:ind_txn_amt,
			:v_com_amt:ind_com_amt,
			:v_net_amt:ind_net_amt,
			:v_markup_amt:ind_markup_amt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )163;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_req_ref_num;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_req_ref_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_ref;
  sqlstm.sqhstl[1] = (unsigned long )13;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_ref;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_card_num;
  sqlstm.sqhstl[2] = (unsigned long )3;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_card_num;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_ewallet_id;
  sqlstm.sqhstl[3] = (unsigned long )103;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_ewallet_id;
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
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_req_datetime;
  sqlstm.sqhstl[6] = (unsigned long )22;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_req_datetime;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_comp_datetime;
  sqlstm.sqhstl[7] = (unsigned long )22;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_comp_datetime;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[8] = (unsigned long )12;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_status;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_tp_txn_ccy;
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_tp_txn_ccy;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_tp_txn_amount;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_tp_txn_amount;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amt;
  sqlstm.sqhstl[11] = (unsigned long )23;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_txn_amt;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_com_amt;
  sqlstm.sqhstl[12] = (unsigned long )23;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_com_amt;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_net_amt;
  sqlstm.sqhstl[13] = (unsigned long )23;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_net_amt;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[14] = (unsigned long )23;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_markup_amt;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
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

/* Field #0 req_ref_num */
		if (ind_req_ref_num < 0){
DEBUGLOG(("process_txn_dsp() ind_req_ref_num < 0   FAIL!!!\n"));
			iFailCount++;
			continue;
		}

/* tp_txn_ccy & tp_txn_amount */
		if (ind_tp_txn_ccy >=0) {
			v_tp_txn_ccy.arr[v_tp_txn_ccy.len] = '\0';
		} else {
			v_tp_txn_ccy.arr[0] = '\0';
		}
		if (ind_tp_txn_amount < 0) v_tp_txn_amount = 0.0;

		if (strcmp(csDefaultCcy,(char*)v_tp_txn_ccy.arr) && v_tp_txn_amount != 0.0) {
DEBUGLOG(("process_txn_dsp() NOT [%s]   FAIL!!!\n",csDefaultCcy));
			iFailCount++;
			continue;
		} else {
			dTotalTxnAmt += v_tp_txn_amount;
			iAcceptCount++;
		}

/* Field #0 req_ref_num */
		fprintf(fp,"%s%.*s%s",PD_OPEN_TAG_CS,v_req_ref_num.len,v_req_ref_num.arr,PD_NEXT_TAG_CS);

/* Field #1 txn_ref*/
		if (ind_txn_ref >=0 ) {
			v_txn_ref.arr[v_txn_ref.len] = '\0';
			fprintf(fp,"%.*s",v_txn_ref.len,v_txn_ref.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #2 card_num*/
		if (ind_card_num >=0 ) {
			v_card_num.arr[v_card_num.len] = '\0';
			fprintf(fp,"%.*s",v_card_num.len,v_card_num.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #3 ewallet_id*/
		if (ind_ewallet_id >=0 ) {
			v_ewallet_id.arr[v_ewallet_id.len] = '\0';
			fprintf(fp,"%.*s",v_ewallet_id.len,v_ewallet_id.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #4 merchant_ref*/
		if (ind_merchant_ref >=0 ) {
			v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			fprintf(fp,"%.*s",v_merchant_ref.len,v_merchant_ref.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #5 req_datetime*/
		if (ind_req_datetime >=0 ) {
			v_req_datetime.arr[v_req_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_req_datetime.len,v_req_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #6 comp_datetime*/
		if (ind_comp_datetime >=0 ) {
			v_comp_datetime.arr[v_comp_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_comp_datetime.len,v_comp_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #7 status*/
		if (ind_status >=0 ) {
			v_status.arr[v_status.len] = '\0';
			fprintf(fp,"%.*s",v_status.len,v_status.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #8 txn_amt*/
		if (ind_txn_amt >=0 ) {
			v_txn_amt.arr[v_txn_amt.len] = '\0';
			fprintf(fp,"%.*s",v_txn_amt.len,v_txn_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #9 com_amt*/
		if (ind_com_amt >=0 ) {
			v_com_amt.arr[v_com_amt.len] = '\0';
			fprintf(fp,"%.*s",v_com_amt.len,v_com_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #10 net_amt*/
		if (ind_net_amt >=0 ) {
			v_net_amt.arr[v_net_amt.len] = '\0';
			fprintf(fp,"%.*s",v_net_amt.len,v_net_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #11 markup_amt*/
		if (ind_markup_amt >=0 ) {
			v_markup_amt.arr[v_markup_amt.len] = '\0';
			fprintf(fp,"%.*s",v_markup_amt.len,v_markup_amt.arr);
		}
		fprintf(fp,"%s\n",PD_END_TAG);

 	}
	while(PD_TRUE && iRet == SUCCESS);

	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%sTotal Transaction%s%d%s\n",PD_OPEN_TAG,PD_NEXT_TAG,iAcceptCount,PD_END_TAG);
	fprintf(fp,"%sTotal Accepted Transaction%s%d%s\n",PD_OPEN_TAG,PD_NEXT_TAG,iAcceptCount,PD_END_TAG);
	fprintf(fp,"%sTotal Accepted Transaction Amount%s%s%.2lf%s\n",PD_OPEN_TAG,PD_NEXT_TAG,csDefaultCcy,dTotalTxnAmt,PD_END_TAG);
	fprintf(fp,"</table></body></html>");

	if (iFailCount > 0) {
		printf("%d records fail",iFailCount);
DEBUGLOG(("process_txn_dsp() Total Fail [%d]\n",iFailCount));
	}

DEBUGLOG(("process_txn_dsp() Total records [%d]\n",iAcceptCount));
DEBUGLOG(("process_txn_dsp() Total Amounts [%.2lf]\n",dTotalTxnAmt));

	/* EXEC SQL CLOSE c_cursor_gettxn_dsp; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )238;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	return iRet;
sql_error:
    DEBUGLOG(("process_txn_dsp error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn_dsp; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )253;
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
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )268;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

int process_txn_stt(const char* csDate,
		FILE *fp)
{	       
	int     iRet = SUCCESS;
	int	iAcceptCount = 0, iFailCount = 0;

	struct	tm tm;
	char	*sysdatetime = getdatetime();
	char	csFormatSysDateTime[21];
	char	csFormatDate[12];

	strptime(csDate, "%Y%m%d", &tm);
	strftime(csFormatDate, sizeof(csFormatDate), "%Y-%h-%d", &tm);
	strptime(sysdatetime, "%Y%m%d%H%M%S", &tm);
	strftime(csFormatSysDateTime, sizeof(csFormatSysDateTime), "%Y-%h-%d %T", &tm);

	//printf("%s to %s\n%s to %s\n",csDate,csFormatDate,sysdatetime,csFormatSysDateTime);

	fprintf(fp,"<html><body><table>\n");
	fprintf(fp,"%s%s(Accepted) Settlement Transaction Detail Report%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_END_TAG);
	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%s%s(complete_date) Start Date:%s%s 00:00:00%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_NEXT_TAG,csFormatDate,PD_END_TAG);
	fprintf(fp,"%s%s(complete_date) End Date:%s%s 23:59:59%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_NEXT_TAG,csFormatDate,PD_END_TAG);
	fprintf(fp,"%s%sGenerated Date:%s%s%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_NEXT_TAG,csFormatSysDateTime,PD_END_TAG);
	fprintf(fp,"%s%s\n",PD_OPEN_TAG,PD_END_TAG);
	fprintf(fp,"%sReq. Ref.%sWallet ID%s B.O. Amount%s%s(+) Comm.%s%sTot. Amount%s%sTran. Req. Date%sTran. Comp. Date%sMarkup Amount%s%s\n",PD_OPEN_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_NEXT_TAG,PD_END_TAG);


	/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 

	
	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		
		/* varchar	hv_deliver_date[PD_DATE_LEN]; */ 
struct { unsigned short len; unsigned char arr[8]; } hv_deliver_date;


		/* varchar	v_req_ref_num[10 +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_req_ref_num;

		/* varchar	v_ewallet_id[PD_AC_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[101]; } v_ewallet_id;

		/* varchar v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar v_bo_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_bo_ccy;

		/* varchar	v_bo_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_bo_amt;

		/* varchar v_com_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_com_ccy;

		/* varchar	v_com_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_com_amt;

		/* varchar v_tot_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_tot_ccy;

		/* varchar	v_tot_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_tot_amt;

		/* varchar	v_req_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_req_datetime;

		/* varchar	v_comp_datetime[19 +1]; */ 
struct { unsigned short len; unsigned char arr[20]; } v_comp_datetime;

		/* varchar v_markup_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		/* varchar	v_markup_amt[20 +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_markup_amt;


		short	ind_req_ref_num = -1;
		short	ind_ewallet_id = -1;
		short	ind_merchant_id = -1;
		short	ind_bo_ccy= -1;
		short	ind_bo_amt= -1;
		short	ind_com_ccy= -1;
		short	ind_com_amt= -1;
		short	ind_tot_ccy= -1;
		short	ind_tot_amt= -1;
		short	ind_req_datetime = -1;
		short	ind_comp_datetime = -1;
		short	ind_markup_ccy= -1;
		short	ind_markup_amt= -1;

	/* EXEC SQL END DECLARE SECTION; */ 


	hv_deliver_date.len = strlen(csDate);
	memcpy(hv_deliver_date.arr,csDate,hv_deliver_date.len);
DEBUGLOG(("process_txn_stt::host_date = [%.*s]\n",hv_deliver_date.len,hv_deliver_date.arr));

	/* EXEC SQL DECLARE c_cursor_gettxn_stt CURSOR FOR
		select case when length(sd_txn_id) <= 10 then sd_txn_id
			else substr(sd_txn_id,1,1) || substr(sd_txn_id,3,9) end req_ref_num,
			mn_username ewallet_id,
			th_merchant_id th_merchant_id,
			decode(sd_deliver_ccy,'CNY','RMB',sd_deliver_ccy) bo_ccy,
			to_char(NVL(sd_deliver_amt, 0), 'FM9,999,999,990.00') bo_amount,
			decode(NVL(tfee.te_ccy, sd_request_ccy),'CNY','RMB',NVL(tfee.te_ccy, sd_request_ccy)) com_ccy,
			to_char(NVL(tfee.te_amount,0), 'FM9,999,990.00') com_amount,
			decode(sd_request_ccy,'CNY','RMB',sd_request_ccy) tot_ccy,
			to_char(NVL(sd_request_amt, 0), 'FM9,999,999,990.00') tot_amount,
			to_char(NVL(th_approval_timestamp,th_create_timestamp), 'MM/DD/YYYY HH24:MI:SS') req_datetime,
			to_char(to_date(sd_deliver_date, 'YYYYMMDD'), 'MM/DD/YYYY') || ' 00:00:00' com_datetime,
			decode(NVL(tmk.te_ccy, sd_request_ccy),'CNY','RMB',NVL(tmk.te_ccy, sd_request_ccy)) markup_ccy,
			to_char(NVL(tmk.te_amount, 0), 'FM9,999,990.00') markup_amount
		from
			(select th_merchant_id,
				sd_txn_id,
				sd_request_ccy,
				sd_request_amt,
				sd_deliver_ccy,
				sd_deliver_amt,
				th_create_timestamp,
				th_approval_timestamp,
				sd_deliver_date,
				mn_username
			from
				(select th_txn_id,
					th_merchant_id,
					th_create_timestamp,
					th_approval_timestamp
					from txn_header
				where th_status in ('C','R')
				 and th_ar_ind = 'A'
				 and th_txn_code = 'STR'),
				merchant_settlement_detail,
				--par_merch_profile,
				par_def_merch_nmb_map,
				par_merch_date_map
			where th_txn_id = sd_txn_id
			 and sd_deliver_date = :hv_deliver_date
			 and th_merchant_id = mn_merchant_id
			 and th_merchant_id = mdm_merchant_id
			 and sd_deliver_date >= mdm_start_date and sd_deliver_date <= mdm_end_date)
		left join txn_elements tfee on
		 tfee.te_txn_id = sd_txn_id
		 and tfee.te_txn_element_type = 'TFEE'
		 and tfee.te_party_type = 'M'
		left join txn_elements tmk on
		 tmk.te_txn_id = sd_txn_id
		 and tmk.te_txn_element_type = 'MAMT'; */ 


	/* EXEC SQL OPEN c_cursor_gettxn_stt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlbuft((void **)0,
   "select case when length ( sd_txn_id ) <= 10 then sd_txn_id else substr (\
 sd_txn_id , 1 , 1 ) || substr ( sd_txn_id , 3 , 9 ) end req_ref_num , mn_us\
ername ewallet_id , th_merchant_id th_merchant_id , decode ( sd_deliver_ccy \
, 'CNY' , 'RMB' , sd_deliver_ccy ) bo_ccy , to_char ( NVL ( sd_deliver_amt ,\
 0 ) , 'FM9,999,999,990.00' ) bo_amount , decode ( NVL ( tfee . te_ccy , sd_\
request_ccy ) , 'CNY' , 'RMB' , NVL ( tfee . te_ccy , sd_request_ccy ) ) com\
_ccy , to_char ( NVL ( tfee . te_amount , 0 ) , 'FM9,999,990.00' ) com_amoun\
t , decode ( sd_request_ccy , 'CNY' , 'RMB' , sd_request_ccy ) tot_ccy , to_\
char ( NVL ( sd_request_amt , 0 ) , 'FM9,999,999,990.00' ) tot_amount , to_c\
har ( NVL ( th_approval_timestamp , th_create_timestamp ) , 'MM/DD/YYYY HH24\
:MI:SS' ) req_datetime , to_char ( to_date ( sd_deliver_date , 'YYYYMMDD' ) \
, 'MM/DD/YYYY' ) || ' 00:00:00' com_datetime , decode ( NVL ( tmk . te_ccy ,\
 sd_request_ccy ) , 'CNY' , 'RMB' , NVL ( tmk . te_ccy , sd_request_ccy ) ) \
markup_ccy , to_char ( NVL ( tmk . te_am");
 sqlstm.stmt = sq0005;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )283;
 sqlstm.selerr = (unsigned short)1;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlstm.sqcmod = (unsigned int )0;
 sqlstm.sqhstv[0] = (unsigned char  *)&hv_deliver_date;
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
 if (sqlca.sqlcode < 0) goto sql_error;
}


	do {    
		/* EXEC SQL FETCH c_cursor_gettxn_stt
		INTO
			:v_req_ref_num:ind_req_ref_num,
			:v_ewallet_id:ind_ewallet_id,
			:v_merchant_id:ind_merchant_id,
			:v_bo_ccy:ind_bo_ccy,
			:v_bo_amt:ind_bo_amt,
			:v_com_ccy:ind_com_ccy,
			:v_com_amt:ind_com_amt,
			:v_tot_ccy:ind_tot_ccy,
			:v_tot_amt:ind_tot_amt,
			:v_req_datetime:ind_req_datetime,
			:v_comp_datetime:ind_comp_datetime,
			:v_markup_ccy:ind_markup_ccy,
			:v_markup_amt:ind_markup_amt; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 15;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )302;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&v_req_ref_num;
  sqlstm.sqhstl[0] = (unsigned long )13;
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)&ind_req_ref_num;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_ewallet_id;
  sqlstm.sqhstl[1] = (unsigned long )103;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_ewallet_id;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_bo_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_bo_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_bo_amt;
  sqlstm.sqhstl[4] = (unsigned long )23;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_bo_amt;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_com_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_com_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_com_amt;
  sqlstm.sqhstl[6] = (unsigned long )23;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_com_amt;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_tot_ccy;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_tot_ccy;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_tot_amt;
  sqlstm.sqhstl[8] = (unsigned long )23;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_tot_amt;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_req_datetime;
  sqlstm.sqhstl[9] = (unsigned long )22;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_req_datetime;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_comp_datetime;
  sqlstm.sqhstl[10] = (unsigned long )22;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_comp_datetime;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_markup_ccy;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_markup_amt;
  sqlstm.sqhstl[12] = (unsigned long )23;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_markup_amt;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}



		if (SQLCODE == SQL_NOT_FOUND) {
			break;
		}

/* Field #0 req_ref_num */
		if (ind_req_ref_num < 0){
			iFailCount++;
			continue;
		}
		fprintf(fp,"%s%.*s%s",PD_OPEN_TAG_CS,v_req_ref_num.len,v_req_ref_num.arr,PD_NEXT_TAG);

/* Field #1 ewallet_id*/
		if (ind_ewallet_id >=0 ) {
			v_ewallet_id.arr[v_ewallet_id.len] = '\0';
			fprintf(fp,"%.*s",v_ewallet_id.len,v_ewallet_id.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #2 bo_ccy*/
		if (ind_bo_ccy >=0 ) {
			v_bo_ccy.arr[v_bo_ccy.len] = '\0';
			fprintf(fp,"%.*s",v_bo_ccy.len,v_bo_ccy.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #3 bo_amt*/
		if (ind_bo_amt >=0 ) {
			v_bo_amt.arr[v_bo_amt.len] = '\0';
			fprintf(fp,"%.*s",v_bo_amt.len,v_bo_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #4 com_ccy*/
		if (ind_com_ccy >=0 ) {
			v_com_ccy.arr[v_com_ccy.len] = '\0';
			fprintf(fp,"%.*s",v_com_ccy.len,v_com_ccy.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #5 com_amt*/
		if (ind_com_amt >=0 ) {
			v_com_amt.arr[v_com_amt.len] = '\0';
			fprintf(fp,"%.*s",v_com_amt.len,v_com_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #6 tot_ccy*/
		if (ind_tot_ccy >=0 ) {
			v_tot_ccy.arr[v_tot_ccy.len] = '\0';
			fprintf(fp,"%.*s",v_tot_ccy.len,v_tot_ccy.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #7 tot_amt*/
		if (ind_tot_amt >=0 ) {
			v_tot_amt.arr[v_tot_amt.len] = '\0';
			fprintf(fp,"%.*s",v_tot_amt.len,v_tot_amt.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #8 req_datetime*/
		if (ind_req_datetime >=0 ) {
			v_req_datetime.arr[v_req_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_req_datetime.len,v_req_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG_CS);

/* Field #9 comp_datetime*/
		if (ind_comp_datetime >=0 ) {
			v_comp_datetime.arr[v_comp_datetime.len] = '\0';
			fprintf(fp,"%.*s",v_comp_datetime.len,v_comp_datetime.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #10 markup_ccy*/
		if (ind_markup_ccy >=0 ) {
			v_markup_ccy.arr[v_markup_ccy.len] = '\0';
			fprintf(fp,"%.*s",v_markup_ccy.len,v_markup_ccy.arr);
		}
		fprintf(fp,"%s",PD_NEXT_TAG);

/* Field #11 markup_amt*/
		if (ind_markup_amt >=0 ) {
			v_markup_amt.arr[v_markup_amt.len] = '\0';
			fprintf(fp,"%.*s",v_markup_amt.len,v_markup_amt.arr);
		}
		fprintf(fp,"%s\n",PD_END_TAG);

		iAcceptCount++;

 	}
	while(PD_TRUE && iRet == SUCCESS);

	fprintf(fp,"</table></body></html>");

	if (iFailCount > 0) {
		printf("%d records fail",iFailCount);
DEBUGLOG(("process_txn_stt() Total Fail [%d]\n",iFailCount));
	}

DEBUGLOG(("process_txn_stt() Total records [%d]\n",iAcceptCount));

	/* EXEC SQL CLOSE c_cursor_gettxn_stt; */ 

{
 struct sqlexd sqlstm;
 sqlstm.sqlvsn = 12;
 sqlstm.arrsiz = 15;
 sqlstm.sqladtp = &sqladt;
 sqlstm.sqltdsp = &sqltds;
 sqlstm.iters = (unsigned int  )1;
 sqlstm.offset = (unsigned int  )369;
 sqlstm.cud = sqlcud0;
 sqlstm.sqlest = (unsigned char  *)&sqlca;
 sqlstm.sqlety = (unsigned short)4352;
 sqlstm.occurs = (unsigned int  )0;
 sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
 if (sqlca.sqlcode < 0) goto sql_error;
}


	return iRet;
sql_error:
    DEBUGLOG(("process_txn_stt error code %d\n", sqlca.sqlcode));
    DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn_stt; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )384;
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
    sqlstm.arrsiz = 15;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )399;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return FAILURE;
}

