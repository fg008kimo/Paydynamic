
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
           char  filnam[24];
};
static struct sqlcxp sqlfpn =
{
    23,
    "get_ofl_deposit_info.pc"
};


static unsigned int sqlctx = 620699123;


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
   unsigned char  *sqhstv[17];
   unsigned long  sqhstl[17];
            int   sqhsts[17];
            short *sqindv[17];
            int   sqinds[17];
   unsigned long  sqharm[17];
   unsigned long  *sqharc[17];
   unsigned short  sqadto[17];
   unsigned short  sqtdso[17];
} sqlstm = {12,17};

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
"SELECT oth_txn_id , oth_txn_code , oth_merchant_ref , oth_merchant_id , oth\
_sub_status , oth_net_ccy , oth_deposit_amount , otd_bank_code , otd_bank_acc\
t_num , otd_cust_deposit_datetime , otd_deposit_bank_code , otd_deposit_ref ,\
 otd_deposit_flow , to_char ( oth_approval_timestamp , 'YYYYMMDD HH24:MI:SS.F\
F' ) oth_approval_timestamp , oth_dst_txn_id , to_char ( otp_txn_timestamp , \
'YYYYMMDD HH24:MI:SS' ) otp_txn_timestamp , otp_customer_text FROM ol_txn_hea\
der , ol_txn_detail , ol_txn_psp_detail WHERE oth_txn_id = otd_txn_id AND oth\
_dst_txn_id = otp_txn_id AND oth_txn_id = :b0 AND oth_ar_ind = 'A' AND NOT EX\
ISTS ( SELECT null FROM tmp_ofl_deposit_info WHERE oth_txn_id = tdi_txn_id ) \
           ";

typedef struct { unsigned short len; unsigned char arr[1]; } VARCHAR;
typedef struct { unsigned short len; unsigned char arr[1]; } varchar;

/* CUD (Compilation Unit Data) Array */
static short sqlcud0[] =
{12,4130,871,0,0,
5,0,0,1,702,0,9,206,0,2049,1,1,0,1,0,1,9,0,0,
24,0,0,1,0,0,13,208,0,0,17,0,0,1,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,
0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,1,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,
107,0,0,2,0,0,17,315,0,0,1,1,0,1,0,1,9,0,0,
126,0,0,2,0,0,21,316,0,0,0,0,0,1,0,
141,0,0,1,0,0,15,320,0,0,0,0,0,1,0,
156,0,0,1,0,0,15,330,0,0,0,0,0,1,0,
171,0,0,3,0,0,32,331,0,0,0,0,0,1,0,
};


/*
Partnerdelight (c)2010. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2015/07/07              Dirk Wong
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

#define PD_MAX_BUF	1024

char    cDebug;

char	cs_in_file[PD_MAX_FILE_LEN+1];
char	cs_out_file[PD_MAX_FILE_LEN+1];

OBJPTR(DB);

int parse_arg(int argc,char **argv);

int processTxn();

int batch_init(int argc, char* argv[])
{
	if (argc < 2) {
		printf("usage: -f input file -o ouputfile\n");
		return FAILURE;
	}
	else {
		return SUCCESS;
	}
}

int batch_proc(int argc, char* argv[])
{
	int     iRet;

	FILE    *fin,*fout;

	iRet = parse_arg(argc,argv);

	if(iRet != SUCCESS) {
ERRLOG("get_ofl_deposit_info:: Missing parameter: -f input file -o ouputfile\n");
		return iRet;
	}

	fin = fopen(cs_in_file, "r");
	if (fin == NULL){
ERRLOG("get_ofl_deposit_info:: unable to open input file %s\n",cs_in_file);
		return FAILURE;
	}

	fout = fopen(cs_out_file,"w");
	if (fout == NULL) {
ERRLOG("get_ofl_deposit_info:: Error Opefing file = [%s] for write\n",cs_out_file);	
		return FAILURE;
	}

	if(iRet == SUCCESS)
		iRet = processTxn(fin,fout);

	fclose(fin);
	fclose(fout);

	return iRet;
}

int batch_terminate(int argc, char* argv[])
{
	return SUCCESS;
}

int parse_arg(int argc,char **argv)
{
	char    c;
        strcpy(cs_in_file,"");
        strcpy(cs_out_file,"");

        while ((c = getopt(argc,argv,"i:o:")) != EOF) {
                switch (c) {
                        case 'i':
                                strcpy(cs_in_file, optarg);
                                break;
                        case 'o':
                                strcpy(cs_out_file, optarg);
                                break;
                        default:
                                return FAILURE;
                }
        }

        if (!strcmp(cs_in_file,"") ||!strcmp(cs_out_file,""))
                return FAILURE;

	return SUCCESS;
}

int processTxn(FILE *fin,FILE *fout)
{
	int	iRet = SUCCESS;

	int	iCnt = 0;
	char    *csBuf;

	char	cs_in_buf[PD_MAX_BUFFER + 1];

	char	*csTmp;
	csTmp = (char*) malloc (PD_MAX_BUFFER);

	while (fgets(cs_in_buf, PD_MAX_BUF, fin) != NULL) {

		if (cs_in_buf[strlen(cs_in_buf) - 1] == 0x0A || (cs_in_buf[strlen(cs_in_buf) - 1] == 0x0D))
			cs_in_buf[strlen(cs_in_buf) - 1] = '\0';

		/* EXEC SQL WHENEVER SQLERROR GOTO sql_error; */ 

		/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


		/* EXEC SQL BEGIN DECLARE SECTION; */ 

			/* varchar	hv_txn_id[PD_TXN_SEQ_LEN]; */ 
struct { unsigned short len; unsigned char arr[16]; } hv_txn_id;


			/* varchar	v_txn_id[PD_TXN_SEQ_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

			/* varchar	v_txn_code[PD_TXN_CODE_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

			/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

			/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

			/* varchar	v_sub_status[PD_SUB_STATUS_LEN+1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_sub_status;

			/* varchar	v_net_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_net_ccy;

			double	v_deposit_amt;
			/* varchar v_bank_code[PD_BANK_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_bank_code;

			/* varchar	v_bank_acct_num[PD_BANK_ACCT_NUM_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_bank_acct_num;

			/* varchar	v_cust_deposit_datetime[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_cust_deposit_datetime;

			/* varchar	v_deposit_bank_code[PD_AC_BANK_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_deposit_bank_code;

			/* varchar	v_deposit_ref[PD_DEPOSITOR_PROV_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[151]; } v_deposit_ref;

			char	v_deposit_flow;
			/* varchar	v_approval_timestamp[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_approval_timestamp;

			/* varchar	v_dst_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_dst_txn_id;

			/* varchar	v_txn_timestamp[PD_TAG_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[26]; } v_txn_timestamp;

			/* varchar v_customer_text[PD_TFR_CUSTOMER_TEXT_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[201]; } v_customer_text;


			short	ind_txn_id = -1;
			short	ind_txn_code = -1;
			short	ind_merchant_ref = -1;
			short	ind_merchant_id = -1;
			short	ind_sub_status = -1;
			short	ind_net_ccy = -1;
			short	ind_deposit_amt = -1;
			short	ind_bank_code = -1;
			short	ind_bank_acct_num = -1;
			short	ind_cust_deposit_datetime = -1;
			short	ind_deposit_bank_code = -1;
			short	ind_deposit_ref = -1;
			short	ind_deposit_flow = -1;
			short	ind_approval_timestamp = -1;
			short	ind_dst_txn_id = -1;
			short	ind_txn_timestamp = -1;
			short	ind_customer_text = -1;

			/* varchar	hv_dynstmt[PD_TMP_MSG_BUF_LEN]; */ 
struct { unsigned short len; unsigned char arr[2048]; } hv_dynstmt;

		/* EXEC SQL END DECLARE SECTION; */ 



		hv_txn_id.len = strlen(cs_in_buf);
		memcpy(hv_txn_id.arr,cs_in_buf,hv_txn_id.len);

		/* EXEC SQL DECLARE c_cursor_gettxn CURSOR FOR
			SELECT	oth_txn_id,
			        oth_txn_code,
			        oth_merchant_ref,
			        oth_merchant_id,
			        oth_sub_status,
			        oth_net_ccy,
			        oth_deposit_amount,
			        otd_bank_code,
			        otd_bank_acct_num,
			        otd_cust_deposit_datetime,
			        otd_deposit_bank_code,
			        otd_deposit_ref,
			        otd_deposit_flow,
			        to_char(oth_approval_timestamp,'YYYYMMDD HH24:MI:SS.FF') oth_approval_timestamp,
			        oth_dst_txn_id,
			        to_char(otp_txn_timestamp,'YYYYMMDD HH24:MI:SS') otp_txn_timestamp,
			        otp_customer_text
			  FROM  ol_txn_header,
			        ol_txn_detail,
			        ol_txn_psp_detail
			 WHERE	oth_txn_id = otd_txn_id
			   AND	oth_dst_txn_id = otp_txn_id
			   AND	oth_txn_id = :hv_txn_id
			   AND	oth_ar_ind = 'A'
			   AND	NOT EXISTS (SELECT null FROM tmp_ofl_deposit_info
							WHERE oth_txn_id = tdi_txn_id); */ 


		/* EXEC SQL OPEN c_cursor_gettxn; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 1;
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
  if (sqlca.sqlcode < 0) goto sql_error;
}


		do {
			/* EXEC SQL FETCH c_cursor_gettxn
			INTO
				:v_txn_id:ind_txn_id,
	                	:v_txn_code:ind_txn_code,
	                	:v_merchant_ref:ind_merchant_ref,
	                	:v_merchant_id:ind_merchant_id,
	                	:v_sub_status:ind_sub_status,
	                	:v_net_ccy:ind_net_ccy,
	                	:v_deposit_amt:ind_deposit_amt,
	                	:v_bank_code:ind_bank_code,
	                	:v_bank_acct_num:ind_bank_acct_num,
	                	:v_cust_deposit_datetime:ind_cust_deposit_datetime,
	                	:v_deposit_bank_code:ind_deposit_bank_code,
	                	:v_deposit_ref:ind_deposit_ref,
	                	:v_deposit_flow:ind_deposit_flow,
	                	:v_approval_timestamp:ind_approval_timestamp,
	                	:v_dst_txn_id:ind_dst_txn_id,
	                	:v_txn_timestamp:ind_txn_timestamp,
	                	:v_customer_text:ind_customer_text; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
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
   sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_ref;
   sqlstm.sqhstl[2] = (unsigned long )53;
   sqlstm.sqhsts[2] = (         int  )0;
   sqlstm.sqindv[2] = (         short *)&ind_merchant_ref;
   sqlstm.sqinds[2] = (         int  )0;
   sqlstm.sqharm[2] = (unsigned long )0;
   sqlstm.sqadto[2] = (unsigned short )0;
   sqlstm.sqtdso[2] = (unsigned short )0;
   sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_id;
   sqlstm.sqhstl[3] = (unsigned long )18;
   sqlstm.sqhsts[3] = (         int  )0;
   sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
   sqlstm.sqinds[3] = (         int  )0;
   sqlstm.sqharm[3] = (unsigned long )0;
   sqlstm.sqadto[3] = (unsigned short )0;
   sqlstm.sqtdso[3] = (unsigned short )0;
   sqlstm.sqhstv[4] = (unsigned char  *)&v_sub_status;
   sqlstm.sqhstl[4] = (unsigned long )6;
   sqlstm.sqhsts[4] = (         int  )0;
   sqlstm.sqindv[4] = (         short *)&ind_sub_status;
   sqlstm.sqinds[4] = (         int  )0;
   sqlstm.sqharm[4] = (unsigned long )0;
   sqlstm.sqadto[4] = (unsigned short )0;
   sqlstm.sqtdso[4] = (unsigned short )0;
   sqlstm.sqhstv[5] = (unsigned char  *)&v_net_ccy;
   sqlstm.sqhstl[5] = (unsigned long )6;
   sqlstm.sqhsts[5] = (         int  )0;
   sqlstm.sqindv[5] = (         short *)&ind_net_ccy;
   sqlstm.sqinds[5] = (         int  )0;
   sqlstm.sqharm[5] = (unsigned long )0;
   sqlstm.sqadto[5] = (unsigned short )0;
   sqlstm.sqtdso[5] = (unsigned short )0;
   sqlstm.sqhstv[6] = (unsigned char  *)&v_deposit_amt;
   sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
   sqlstm.sqhsts[6] = (         int  )0;
   sqlstm.sqindv[6] = (         short *)&ind_deposit_amt;
   sqlstm.sqinds[6] = (         int  )0;
   sqlstm.sqharm[6] = (unsigned long )0;
   sqlstm.sqadto[6] = (unsigned short )0;
   sqlstm.sqtdso[6] = (unsigned short )0;
   sqlstm.sqhstv[7] = (unsigned char  *)&v_bank_code;
   sqlstm.sqhstl[7] = (unsigned long )13;
   sqlstm.sqhsts[7] = (         int  )0;
   sqlstm.sqindv[7] = (         short *)&ind_bank_code;
   sqlstm.sqinds[7] = (         int  )0;
   sqlstm.sqharm[7] = (unsigned long )0;
   sqlstm.sqadto[7] = (unsigned short )0;
   sqlstm.sqtdso[7] = (unsigned short )0;
   sqlstm.sqhstv[8] = (unsigned char  *)&v_bank_acct_num;
   sqlstm.sqhstl[8] = (unsigned long )53;
   sqlstm.sqhsts[8] = (         int  )0;
   sqlstm.sqindv[8] = (         short *)&ind_bank_acct_num;
   sqlstm.sqinds[8] = (         int  )0;
   sqlstm.sqharm[8] = (unsigned long )0;
   sqlstm.sqadto[8] = (unsigned short )0;
   sqlstm.sqtdso[8] = (unsigned short )0;
   sqlstm.sqhstv[9] = (unsigned char  *)&v_cust_deposit_datetime;
   sqlstm.sqhstl[9] = (unsigned long )17;
   sqlstm.sqhsts[9] = (         int  )0;
   sqlstm.sqindv[9] = (         short *)&ind_cust_deposit_datetime;
   sqlstm.sqinds[9] = (         int  )0;
   sqlstm.sqharm[9] = (unsigned long )0;
   sqlstm.sqadto[9] = (unsigned short )0;
   sqlstm.sqtdso[9] = (unsigned short )0;
   sqlstm.sqhstv[10] = (unsigned char  *)&v_deposit_bank_code;
   sqlstm.sqhstl[10] = (unsigned long )28;
   sqlstm.sqhsts[10] = (         int  )0;
   sqlstm.sqindv[10] = (         short *)&ind_deposit_bank_code;
   sqlstm.sqinds[10] = (         int  )0;
   sqlstm.sqharm[10] = (unsigned long )0;
   sqlstm.sqadto[10] = (unsigned short )0;
   sqlstm.sqtdso[10] = (unsigned short )0;
   sqlstm.sqhstv[11] = (unsigned char  *)&v_deposit_ref;
   sqlstm.sqhstl[11] = (unsigned long )153;
   sqlstm.sqhsts[11] = (         int  )0;
   sqlstm.sqindv[11] = (         short *)&ind_deposit_ref;
   sqlstm.sqinds[11] = (         int  )0;
   sqlstm.sqharm[11] = (unsigned long )0;
   sqlstm.sqadto[11] = (unsigned short )0;
   sqlstm.sqtdso[11] = (unsigned short )0;
   sqlstm.sqhstv[12] = (unsigned char  *)&v_deposit_flow;
   sqlstm.sqhstl[12] = (unsigned long )1;
   sqlstm.sqhsts[12] = (         int  )0;
   sqlstm.sqindv[12] = (         short *)&ind_deposit_flow;
   sqlstm.sqinds[12] = (         int  )0;
   sqlstm.sqharm[12] = (unsigned long )0;
   sqlstm.sqadto[12] = (unsigned short )0;
   sqlstm.sqtdso[12] = (unsigned short )0;
   sqlstm.sqhstv[13] = (unsigned char  *)&v_approval_timestamp;
   sqlstm.sqhstl[13] = (unsigned long )28;
   sqlstm.sqhsts[13] = (         int  )0;
   sqlstm.sqindv[13] = (         short *)&ind_approval_timestamp;
   sqlstm.sqinds[13] = (         int  )0;
   sqlstm.sqharm[13] = (unsigned long )0;
   sqlstm.sqadto[13] = (unsigned short )0;
   sqlstm.sqtdso[13] = (unsigned short )0;
   sqlstm.sqhstv[14] = (unsigned char  *)&v_dst_txn_id;
   sqlstm.sqhstl[14] = (unsigned long )19;
   sqlstm.sqhsts[14] = (         int  )0;
   sqlstm.sqindv[14] = (         short *)&ind_dst_txn_id;
   sqlstm.sqinds[14] = (         int  )0;
   sqlstm.sqharm[14] = (unsigned long )0;
   sqlstm.sqadto[14] = (unsigned short )0;
   sqlstm.sqtdso[14] = (unsigned short )0;
   sqlstm.sqhstv[15] = (unsigned char  *)&v_txn_timestamp;
   sqlstm.sqhstl[15] = (unsigned long )28;
   sqlstm.sqhsts[15] = (         int  )0;
   sqlstm.sqindv[15] = (         short *)&ind_txn_timestamp;
   sqlstm.sqinds[15] = (         int  )0;
   sqlstm.sqharm[15] = (unsigned long )0;
   sqlstm.sqadto[15] = (unsigned short )0;
   sqlstm.sqtdso[15] = (unsigned short )0;
   sqlstm.sqhstv[16] = (unsigned char  *)&v_customer_text;
   sqlstm.sqhstl[16] = (unsigned long )203;
   sqlstm.sqhsts[16] = (         int  )0;
   sqlstm.sqindv[16] = (         short *)&ind_customer_text;
   sqlstm.sqinds[16] = (         int  )0;
   sqlstm.sqharm[16] = (unsigned long )0;
   sqlstm.sqadto[16] = (unsigned short )0;
   sqlstm.sqtdso[16] = (unsigned short )0;
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

			if (ind_txn_id >= 0) {
				v_txn_id.arr[v_txn_id.len] = '\0';
			}
			if (ind_txn_code >= 0) {
				v_txn_code.arr[v_txn_code.len] = '\0';
			}
			if (ind_merchant_ref >= 0) {
				v_merchant_ref.arr[v_merchant_ref.len] = '\0';
			}
			if (ind_merchant_id >= 0) {
				v_merchant_id.arr[v_merchant_id.len] = '\0';
			}
			if (ind_sub_status >= 0) {
				v_sub_status.arr[v_sub_status.len] = '\0';
			}
			if (ind_net_ccy >= 0) {
				v_net_ccy.arr[v_net_ccy.len] = '\0';
			}
			if (ind_deposit_amt >= 0) {
			}
			if (ind_bank_code >= 0) {
				v_bank_code.arr[v_bank_code.len] = '\0';
			}
			if (ind_bank_acct_num >= 0) {
				v_bank_acct_num.arr[v_bank_acct_num.len] = '\0';
			}
			if (ind_cust_deposit_datetime >= 0) {
				v_cust_deposit_datetime.arr[v_cust_deposit_datetime.len] = '\0';
			}
			if (ind_deposit_bank_code >= 0) {
				v_deposit_bank_code.arr[v_deposit_bank_code.len] = '\0';
			}
			if (ind_deposit_ref >= 0) {
				v_deposit_ref.arr[v_deposit_ref.len] = '\0';
			}
			if (ind_deposit_flow >= 0) {
			}
			if (ind_approval_timestamp >= 0) {
				v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
			}
			if (ind_dst_txn_id >= 0) {
				v_dst_txn_id.arr[v_dst_txn_id.len] = '\0';
			}
			if (ind_txn_timestamp >= 0) {
				v_txn_timestamp.arr[v_txn_timestamp.len] = '\0';
			}
			if (ind_customer_text >= 0) {
				v_customer_text.arr[v_customer_text.len] = '\0';
			}

			fprintf(fout,"%.*s,%.*s,%.*s,%.*s,%.*s,%.*s,%.*s,%.f,%.*s,%.*s,%.*s,%.*s,%.*s,%c,%.*s,%.*s,%.*s,%.*s,\n",
					PD_DATETIME_LEN, getdatetime(),
					v_txn_id.len, v_txn_id.arr,
					v_txn_code.len, v_txn_code.arr,
					v_merchant_ref.len, v_merchant_ref.arr,
					v_merchant_id.len, v_merchant_id.arr,
					v_sub_status.len, v_sub_status.arr,
					v_net_ccy.len, v_net_ccy.arr,
					v_deposit_amt,
					v_bank_code.len, v_bank_code.arr,
					v_bank_acct_num.len, v_bank_acct_num.arr,
					v_cust_deposit_datetime.len, v_cust_deposit_datetime.arr,
					v_deposit_bank_code.len, v_deposit_bank_code.arr,
					v_deposit_ref.len, v_deposit_ref.arr,
					v_deposit_flow,
					v_approval_timestamp.len, v_approval_timestamp.arr,
					v_dst_txn_id.len, v_dst_txn_id.arr,
					v_txn_timestamp.len, v_txn_timestamp.arr,
					v_customer_text.len, v_customer_text.arr
				);
 
			csBuf = (char*) malloc (PD_TMP_BUF_LEN);

			//insert into tmp_ofl_deposit_info
			strcpy((char*)hv_dynstmt.arr,"INSERT INTO tmp_ofl_deposit_info (tdi_txn_id, tdi_merch_ref, tdi_create_timestamp) VALUES ('");
			strcat((char*)hv_dynstmt.arr,(char*)v_txn_id.arr);
			strcat((char*)hv_dynstmt.arr,"','");
			strcat((char*)hv_dynstmt.arr,(char*)v_merchant_ref.arr);
			strcat((char*)hv_dynstmt.arr,"',sysdate)");
			hv_dynstmt.len = strlen((const char*)hv_dynstmt.arr);

			/* EXEC SQL PREPARE PS FROM :hv_dynstmt; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )107;
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
   if (sqlca.sqlcode < 0) goto sql_error;
}


			/* EXEC SQL EXECUTE PS; */ 

{
   struct sqlexd sqlstm;
   sqlstm.sqlvsn = 12;
   sqlstm.arrsiz = 17;
   sqlstm.sqladtp = &sqladt;
   sqlstm.sqltdsp = &sqltds;
   sqlstm.stmt = "";
   sqlstm.iters = (unsigned int  )1;
   sqlstm.offset = (unsigned int  )126;
   sqlstm.cud = sqlcud0;
   sqlstm.sqlest = (unsigned char  *)&sqlca;
   sqlstm.sqlety = (unsigned short)4352;
   sqlstm.occurs = (unsigned int  )0;
   sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
   if (sqlca.sqlcode < 0) goto sql_error;
}



		}
		while (PD_TRUE);
		/* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 17;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )141;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
  if (sqlca.sqlcode < 0) goto sql_error;
}


	}

	return iRet;

sql_error:
ERRLOG("get_ofl_deposit_info:: SQL error!\n");
ERRLOG("get_ofl_deposit_info error code %d\n", sqlca.sqlcode);
ERRLOG("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc);
    /* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

    /* EXEC SQL CLOSE c_cursor_gettxn; */ 

{
    struct sqlexd sqlstm;
    sqlstm.sqlvsn = 12;
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )156;
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
    sqlstm.arrsiz = 17;
    sqlstm.sqladtp = &sqladt;
    sqlstm.sqltdsp = &sqltds;
    sqlstm.iters = (unsigned int  )1;
    sqlstm.offset = (unsigned int  )171;
    sqlstm.cud = sqlcud0;
    sqlstm.sqlest = (unsigned char  *)&sqlca;
    sqlstm.sqlety = (unsigned short)4352;
    sqlstm.occurs = (unsigned int  )0;
    sqlcxt((void **)0, &sqlctx, &sqlstm, &sqlfpn);
}


    return PD_ERR;
}


