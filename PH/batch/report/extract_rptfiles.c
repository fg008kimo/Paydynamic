
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
           char  filnam[20];
};
static struct sqlcxp sqlfpn =
{
    19,
    "extract_rptfiles.pc"
};


static unsigned int sqlctx = 40131395;


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
   unsigned char  *sqhstv[24];
   unsigned long  sqhstl[24];
            int   sqhsts[24];
            short *sqindv[24];
            int   sqinds[24];
   unsigned long  sqharm[24];
   unsigned long  *sqharc[24];
   unsigned short  sqadto[24];
   unsigned short  sqtdso[24];
} sqlstm = {12,24};

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
5,0,0,0,0,0,13,118,0,0,24,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
116,0,0,0,0,0,13,312,0,0,9,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,2,3,0,0,2,4,0,0,
167,0,0,0,0,0,13,418,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,
210,0,0,0,0,0,13,511,0,0,7,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,
9,0,0,2,4,0,0,
253,0,0,0,0,0,13,610,0,0,8,1,0,1,0,1,102,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,
9,0,0,2,9,0,0,2,4,0,0,
300,0,0,0,0,0,13,759,0,0,22,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,
0,2,4,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
403,0,0,0,0,0,13,989,0,0,19,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,
0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
494,0,0,0,0,0,13,1188,0,0,13,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,
561,0,0,0,0,0,13,1335,0,0,12,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,9,0,0,2,4,0,0,2,9,0,0,
624,0,0,0,0,0,13,1469,0,0,10,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,9,0,0,2,9,0,0,2,9,0,0,2,4,0,0,2,4,0,0,
679,0,0,0,0,0,13,1574,0,0,6,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,3,0,0,
718,0,0,0,0,0,13,1684,0,0,16,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,2,9,0,0,
797,0,0,0,0,0,13,1849,0,0,15,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,
872,0,0,0,0,0,13,2011,0,0,15,1,0,1,0,1,102,0,0,2,9,0,0,2,9,0,0,2,9,0,0,2,9,0,0,
2,4,0,0,2,9,0,0,2,4,0,0,2,4,0,0,2,9,0,0,2,9,0,0,2,3,0,0,2,9,0,0,2,9,0,0,2,9,0,
0,
};


/*
Partnerdelight (c)2012. All rights reserved. No part of this software may be reproduced in any form without written permission
of an authorized representative of Partnerdelight.

Change Description                                 Change Date             Change By
-------------------------------                    ------------            --------------
Init Version                                       2012/02/03              Cody Chan
                                                   2012/07/26              Gilbert Lum
Separate Ledger into  CB, SB, RB		   2012/12/28		   Stan Poon
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlca.h>
#include <sqlcpr.h>
#include "common.h"
#include "utilitys.h"
#include "batchcommon.h"

char	cDebug;
#define SQLCA_STORAGE_CLASS extern
#define SQLCODE sqlca.sqlcode


int Extract_RPT002(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
DEBUGLOG(("Extract_RPT002\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt002_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_txn_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;

		/* varchar	v_client_id[PD_CLIENT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_client_id;

		/* varchar	v_client_name[PD_CLIENT_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_client_name;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_psp_id[PD_PSP_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_host_posting_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_host_posting_date;

		/* varchar	v_transmission_datetime[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_transmission_datetime;

		/* varchar	v_txn_country[PD_COUNTRY_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_txn_country;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		double	v_net_amount;
		double	v_reserve_amount;
		double	v_ex_rate;
		/* varchar	v_sub_status[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status;

		/* varchar	v_status[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_create_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_date;

		/* varchar	v_update_date[PD_DATETIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_update_date;

		/* varchar	v_service_name[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_name;

		/* varchar	v_approval_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;
 


		short	ind_txn_id = -1;
		short	ind_txn_desc = -1;
		short	ind_client_id = -1;
		short	ind_client_name = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_merchant_ref = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_host_posting_date = -1;
		short	ind_transmission_datetime = -1;
		short	ind_txn_country = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_net_amount = -1;
		short	ind_reserve_amount = -1;
		short	ind_ex_rate = -1;
		short	ind_sub_status = -1;
		short	ind_status = -1;
		short	ind_create_date = -1;
		short	ind_update_date = -1;
		short	ind_service_name =-1;
		short	ind_approval_date = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Client ID");
	fprintf(fp,XLS_FL,"Client Name");
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Merchant Ref #");
	fprintf(fp,XLS_FL,"PSP ID");
	fprintf(fp,XLS_FL,"PSP Name");
	fprintf(fp,XLS_FL,"Host Posting Date");
	fprintf(fp,XLS_FL,"Transmission DateTime");
	fprintf(fp,XLS_FL,"Txn Country");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Transaction Amount");
	fprintf(fp,XLS_FL,"Net Amount");
	fprintf(fp,XLS_FL,"Reserve Amount");
	fprintf(fp,XLS_FL,"EX Rate");
	fprintf(fp,XLS_FL,"Sub Status");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Create DateTime");
	fprintf(fp,XLS_FL,"Update DateTime");
	fprintf(fp,XLS_FL,"Service Name");
	fprintf(fp,XLS_FL,"Approval Date");

	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_id:ind_txn_id,
			:v_txn_desc:ind_txn_desc,
			:v_client_id:ind_client_id,
			:v_client_name:ind_client_name,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_merchant_ref:ind_merchant_ref,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_host_posting_date:ind_host_posting_date,
			:v_transmission_datetime:ind_transmission_datetime,
			:v_txn_country:ind_txn_country,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_net_amount:ind_net_amount,
			:v_reserve_amount:ind_reserve_amount,
			:v_ex_rate:ind_ex_rate,
			:v_sub_status:ind_sub_status,
			:v_status:ind_status,
			:v_create_date:ind_create_date,
			:v_update_date:ind_update_date,
			:v_service_name:ind_service_name,
			:v_approval_date:ind_approval_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )5;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_desc;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_desc;
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
  sqlstm.sqhstv[4] = (unsigned char  *)&v_client_name;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_client_name;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_psp_id;
  sqlstm.sqhstl[8] = (unsigned long )13;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_psp_id;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_psp_name;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_host_posting_date;
  sqlstm.sqhstl[10] = (unsigned long )11;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_host_posting_date;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_transmission_datetime;
  sqlstm.sqhstl[11] = (unsigned long )17;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_transmission_datetime;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_country;
  sqlstm.sqhstl[12] = (unsigned long )5;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_txn_country;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_net_amount;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_net_amount;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_reserve_amount;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_reserve_amount;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_sub_status;
  sqlstm.sqhstl[18] = (unsigned long )53;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_sub_status;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[19] = (unsigned long )53;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_status;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_create_date;
  sqlstm.sqhstl[20] = (unsigned long )17;
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_create_date;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_update_date;
  sqlstm.sqhstl[21] = (unsigned long )17;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_update_date;
  sqlstm.sqinds[21] = (         int  )0;
  sqlstm.sqharm[21] = (unsigned long )0;
  sqlstm.sqadto[21] = (unsigned short )0;
  sqlstm.sqtdso[21] = (unsigned short )0;
  sqlstm.sqhstv[22] = (unsigned char  *)&v_service_name;
  sqlstm.sqhstl[22] = (unsigned long )53;
  sqlstm.sqhsts[22] = (         int  )0;
  sqlstm.sqindv[22] = (         short *)&ind_service_name;
  sqlstm.sqinds[22] = (         int  )0;
  sqlstm.sqharm[22] = (unsigned long )0;
  sqlstm.sqadto[22] = (unsigned short )0;
  sqlstm.sqtdso[22] = (unsigned short )0;
  sqlstm.sqhstv[23] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[23] = (unsigned long )11;
  sqlstm.sqhsts[23] = (         int  )0;
  sqlstm.sqindv[23] = (         short *)&ind_approval_date;
  sqlstm.sqinds[23] = (         int  )0;
  sqlstm.sqharm[23] = (unsigned long )0;
  sqlstm.sqadto[23] = (unsigned short )0;
  sqlstm.sqtdso[23] = (unsigned short )0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt002_error;
}


		fprintf(fp,XLS_NC);
/* txn ID */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* txn desc */
		v_txn_desc.arr[v_txn_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_desc.arr);
		
/* client id */
		v_client_id.arr[v_client_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_client_id.arr);

/* client name */
		v_client_name.arr[v_client_name.len] = '\0';
		fprintf(fp,XLS_FL,v_client_name.arr);

/* merchant id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_id.arr);

/* merchant name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* merchant ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* psp ID */
		v_psp_id.arr[v_psp_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_psp_id.arr);

/* psp desc */
		v_psp_name.arr[v_psp_name.len] = '\0';
		fprintf(fp,XLS_FL,v_psp_name.arr);

/* host posting date */
		v_host_posting_date.arr[v_host_posting_date.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_host_posting_date.arr,PD_MM_LEN,&v_host_posting_date.arr[PD_YYYY_LEN],PD_DD_LEN,&v_host_posting_date.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* transmission datetime */
		v_transmission_datetime.arr[v_transmission_datetime.len] = '\0';
		if (v_transmission_datetime.len > PD_DATE_LEN) {
			fprintf(fp,XLS_FL_DATETIME,4,v_transmission_datetime.arr,2,&v_transmission_datetime.arr[4],2,&v_transmission_datetime.arr[6],2,&v_transmission_datetime.arr[8],2,&v_transmission_datetime.arr[10],2,&v_transmission_datetime.arr[12]);
		}
		else {
			fprintf(fp,XLS_FL_DATE,4,v_transmission_datetime.arr,2,&v_transmission_datetime.arr[4],2,&v_transmission_datetime.arr[6]);
		}

/* txn country */
		v_txn_country.arr[v_txn_country.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_country.arr);

/* txn ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* transaction amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount);

/* net amount */
		if (ind_net_amount < 0 )
			v_net_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_net_amount);

/* reserve amount */
		if (ind_reserve_amount < 0 )
			v_reserve_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_reserve_amount);

/* ex rate */
		if (ind_ex_rate < 0 )
			v_ex_rate = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_ex_rate);

/* sub status */
		v_sub_status.arr[v_sub_status.len] = '\0';
		fprintf(fp,XLS_FL,v_sub_status.arr);

/* status */
		v_status.arr[v_status.len] = '\0';
		fprintf(fp,XLS_FL,v_status.arr);

/* create_date */
		v_create_date.arr[v_create_date.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_create_date.arr,PD_MM_LEN,&v_create_date.arr[PD_YYYY_LEN],PD_DD_LEN,&v_create_date.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* update_date */
		v_update_date.arr[v_update_date.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_update_date.arr,PD_MM_LEN,&v_update_date.arr[PD_YYYY_LEN],PD_DD_LEN,&v_update_date.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* service_name */
		v_service_name.arr[v_service_name.len] = '\0';
		fprintf(fp,XLS_FL,v_service_name.arr);

/* approval date */
		v_approval_date.arr[v_approval_date.len] = '\0';
		if (ind_approval_date >= 0 ) {
			fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_date.arr,PD_MM_LEN,&v_approval_date.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_date.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt002_error:
DEBUGLOG(("extract_rpt002 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT003(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT003\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt003_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar v_approval_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

		/* varchar	v_txn_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;

		/* varchar v_service_name[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_name;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		int	v_txn_count;
		double	v_avg_txn_amount;

		short	ind_approval_date = -1;
		short	ind_txn_desc = -1;
		short	ind_service_name = -1;
		short	ind_psp_name = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_txn_count = -1;
		short	ind_avg_txn_amount = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Service Name");
	fprintf(fp,XLS_FL,"PSP Name");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Transaction Amount");
	fprintf(fp,XLS_FL,"Transaction Count");
	fprintf(fp,XLS_FL,"Average Transaction Amount");

	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_approval_date:ind_approval_date,
			:v_txn_desc:ind_txn_desc,
			:v_service_name:ind_service_name,
			:v_psp_name:ind_psp_name,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_txn_count:ind_txn_count,
			:v_avg_txn_amount:ind_avg_txn_amount; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )116;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[1] = (unsigned long )11;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_approval_date;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_desc;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_desc;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_psp_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_count;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_txn_count;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_avg_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_avg_txn_amount;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt003_error;
}



		fprintf(fp,XLS_NC);

/* approval_date */
		v_approval_date.arr[v_approval_date.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_date.arr,PD_MM_LEN,&v_approval_date.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_date.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* txn desc */
		v_txn_desc.arr[v_txn_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_desc.arr);

/* service name */
		v_service_name.arr[v_service_name.len] = '\0';
		fprintf(fp,XLS_FL,v_service_name.arr);

/* psp name */
		v_psp_name.arr[v_psp_name.len] = '\0';
		fprintf(fp,XLS_FL,v_psp_name.arr);
		
/* txn ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* txn amount */
		if (ind_txn_amount < 0 )
			v_txn_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount); 

/* txn_count */
		if (ind_txn_count < 0) {
			v_txn_count = 0;
		}
		fprintf(fp, XLS_FL_INT, v_txn_count);

/* average txn amount */
		if (ind_avg_txn_amount < 0 )
			v_avg_txn_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE2,v_avg_txn_amount); 


		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt003_error:
DEBUGLOG(("extract_rpt003 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT004(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT004\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt004_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_service_name[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_name;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;
	
		double	v_total_fee;

		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_service_name = -1;
		short	ind_txn_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_total_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Service Name");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Amount Type");
	fprintf(fp,XLS_FL,"Total Fee");

	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_service_name:ind_service_name,
			:v_txn_ccy:ind_txn_ccy,
			:v_amt_type:ind_amt_type,
			:v_total_fee:ind_total_fee; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )167;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[4] = (unsigned long )6;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_amt_type;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_total_fee;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_total_fee;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt004_error;
}



		fprintf(fp,XLS_NC);

/* merchant id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_id.arr);

/* merchant name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* service name */
		v_service_name.arr[v_service_name.len] = '\0';
		fprintf(fp,XLS_FL,v_service_name.arr);

/* txn ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* amount type */
		v_amt_type.arr[v_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_amt_type.arr);

/* total fee*/
		if (ind_total_fee < 0 )
			v_total_fee = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_total_fee); 

		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt004_error:
DEBUGLOG(("extract_rpt004 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}



int Extract_RPT005(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT005\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt005_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_txn_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_desc;

		/* varchar	v_status[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		int	v_txn_count;
		/* varchar v_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_markup_amount;
	
		short	ind_txn_desc = -1;
		short	ind_status = -1;
		short	ind_txn_count = -1;
		short	ind_amt_type = -1;
		short	ind_txn_ccy = -1;
		short	ind_markup_amount = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Transaction Count");
	//fprintf(fp,XLS_FL,"Amount Type");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Markup Amount");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_desc:ind_txn_desc,
			:v_status:ind_status,
			:v_txn_count:ind_txn_count,
			:v_amt_type:ind_amt_type,
			:v_txn_ccy:ind_txn_ccy,
			:v_markup_amount:ind_markup_amount; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )210;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_desc;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_desc;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_status;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_count;
  sqlstm.sqhstl[3] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_count;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[4] = (unsigned long )5;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_amt_type;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[5] = (unsigned long )6;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_markup_amount;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_markup_amount;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt005_error;
}



		fprintf(fp,XLS_NC);

/* txn desc */
		v_txn_desc.arr[v_txn_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_desc.arr);
		
/* status */
		v_status.arr[v_status.len] = '\0';
		fprintf(fp,XLS_FL,v_status.arr);

/* txn_count */
		if (ind_txn_count < 0) {
			v_txn_count = 0;
		}
		fprintf(fp, XLS_FL_INT,v_txn_count);

/*amt_type */
		v_amt_type.arr[v_amt_type.len] = '\0';
		//fprintf(fp,XLS_FL,v_amt_type.arr);

/* txn ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* markup amount */
		if (ind_markup_amount < 0 )
			v_markup_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_markup_amount);

		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt005_error:
DEBUGLOG(("extract_rpt005 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}



int Extract_RPT006(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT006\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt006_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		int	v_count;
		/* varchar	v_member_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_member_ccy;

		/* varchar	v_member_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_member_amt_type;

		double	v_member_amount;
		/* varchar	v_merchant_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_merchant_ccy;

		/* varchar	v_merchant_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_merchant_amt_type;

		double	v_merchant_amount;

		short	ind_count = -1;
		short	ind_member_ccy = -1;
		short	ind_member_amt_type = -1;
		short	ind_member_amount = -1;
		short	ind_merchant_ccy = -1;
		short	ind_merchant_amt_type = -1;
		short	ind_merchant_amount = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn Count");
	fprintf(fp,XLS_FL,"Member Amount Type");
	fprintf(fp,XLS_FL,"Member Currency");
	fprintf(fp,XLS_FL,"Member Fee");
	fprintf(fp,XLS_FL,"Merchant Amount Type");
	fprintf(fp,XLS_FL,"Merchant Currency");
	fprintf(fp,XLS_FL,"Merchant Fee");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_count:ind_count,
			:v_member_amt_type:ind_member_amt_type,
			:v_member_ccy:ind_member_ccy,
			:v_member_amount:ind_member_amount,
			:v_merchant_amt_type:ind_merchant_amt_type,
			:v_merchant_ccy:ind_merchant_ccy,
			:v_merchant_amount:ind_merchant_amount; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )253;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_count;
  sqlstm.sqhstl[1] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_count;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_member_amt_type;
  sqlstm.sqhstl[2] = (unsigned long )5;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_member_amt_type;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_member_ccy;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_member_ccy;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_member_amount;
  sqlstm.sqhstl[4] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_member_amount;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_merchant_amt_type;
  sqlstm.sqhstl[5] = (unsigned long )5;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_merchant_amt_type;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_merchant_ccy;
  sqlstm.sqhstl[6] = (unsigned long )6;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_merchant_ccy;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_amount;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_merchant_amount;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt006_error;
}



		fprintf(fp,XLS_NC);
/*count*/
		if (ind_count < 0) {
			v_count = 0;
		}
		fprintf(fp, XLS_FL_INT, v_count);

/* member_amount_type */
		v_member_amt_type.arr[v_member_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_member_amt_type.arr);

/* member_ccy */
		v_member_ccy.arr[v_member_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_member_ccy.arr);

/* member_amount */
		if (ind_member_amount < 0) {
			v_member_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_member_amount);

/* merchant_amount_type */
		v_merchant_amt_type.arr[v_merchant_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_amt_type.arr);

/* merchant_ccy */
		v_merchant_ccy.arr[v_merchant_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_ccy.arr);

/* merchant_amount */
		if (ind_merchant_amount < 0) {
			v_merchant_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_merchant_amount);

		fprintf(fp,XLS_EC);
	}
/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt006_error:
DEBUGLOG(("extract_rpt006 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}



int Extract_RPT007(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT007\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt007_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_create_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_timestamp;

		/* varchar	v_update_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_update_timestamp;

		/* varchar	v_approval_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_timestamp;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_dm_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

		/* varchar	v_sub_status_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		double	v_net_amount;
		double	v_ex_rate;
		/* varchar	v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;

		double	v_fee;
		/* varchar	v_req_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_req_amt_ccy;

		double	v_requested_amount;
		/* varchar	v_psp_tid[PD_PSP_TID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_tid;

		/* varchar	v_markup_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_markup_ccy;

		double	v_markup;



		short	ind_create_timestamp = -1;
		short	ind_update_timestamp = -1;
		short	ind_approval_timestamp = -1;
		short	ind_txn_id = -1;
		short	ind_psp_name = -1;
		short	ind_merchant_ref = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_dm_status_desc = -1;
		short	ind_sub_status_desc = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_net_amount = -1;
		short	ind_ex_rate = -1;
		short	ind_fee_ccy = -1;
		short	ind_fee = -1;
		short	ind_req_amt_ccy = -1;
		short	ind_requested_amount = -1;
		short	ind_psp_tid = -1;
		short	ind_markup_ccy = -1;
		short	ind_markup = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Create Date");
	fprintf(fp,XLS_FL,"Last Update Date");
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"PSP Name");
	fprintf(fp,XLS_FL,"PSP Txn ID");
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Merchant Ref #");
	fprintf(fp,XLS_FL,"Substatus Desc");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Txn Amount");
	fprintf(fp,XLS_FL,"Net Amount");
	fprintf(fp,XLS_FL,"Exchange Rate");
	fprintf(fp,XLS_FL,"Fee Currency");
	fprintf(fp,XLS_FL,"Fee");
	fprintf(fp,XLS_FL,"Amount Currency");
	fprintf(fp,XLS_FL,"Requested Amount");
	fprintf(fp,XLS_FL,"Markup Currency");
	fprintf(fp,XLS_FL,"Markup");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_create_timestamp:ind_create_timestamp,
			:v_update_timestamp:ind_update_timestamp,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_txn_id:ind_txn_id,
			:v_psp_name:ind_psp_name,
			:v_psp_tid:ind_psp_tid,
			:v_merchant_ref:ind_merchant_ref,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_dm_status_desc:ind_dm_status_desc,
			:v_sub_status_desc:ind_sub_status_desc,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_net_amount:ind_net_amount,
			:v_ex_rate:ind_ex_rate,
			:v_fee:ind_fee,
			:v_fee_ccy:ind_fee_ccy,
			:v_requested_amount:ind_requested_amount,
			:v_req_amt_ccy:ind_req_amt_ccy,
			:v_markup:ind_markup,
			:v_markup_ccy:ind_markup_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )300;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_update_timestamp;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_update_timestamp;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[3] = (unsigned long )17;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_id;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_psp_name;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_tid;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_psp_tid;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_ref;
  sqlstm.sqhstl[7] = (unsigned long )53;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_merchant_ref;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[8] = (unsigned long )18;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_dm_status_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_dm_status_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_sub_status_desc;
  sqlstm.sqhstl[11] = (unsigned long )53;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_sub_status_desc;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[12] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[13] = (unsigned long )6;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_net_amount;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_net_amount;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_fee;
  sqlstm.sqhstl[16] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_fee;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_fee_ccy;
  sqlstm.sqhstl[17] = (unsigned long )6;
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_fee_ccy;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_requested_amount;
  sqlstm.sqhstl[18] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_requested_amount;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
  sqlstm.sqhstv[19] = (unsigned char  *)&v_req_amt_ccy;
  sqlstm.sqhstl[19] = (unsigned long )6;
  sqlstm.sqhsts[19] = (         int  )0;
  sqlstm.sqindv[19] = (         short *)&ind_req_amt_ccy;
  sqlstm.sqinds[19] = (         int  )0;
  sqlstm.sqharm[19] = (unsigned long )0;
  sqlstm.sqadto[19] = (unsigned short )0;
  sqlstm.sqtdso[19] = (unsigned short )0;
  sqlstm.sqhstv[20] = (unsigned char  *)&v_markup;
  sqlstm.sqhstl[20] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[20] = (         int  )0;
  sqlstm.sqindv[20] = (         short *)&ind_markup;
  sqlstm.sqinds[20] = (         int  )0;
  sqlstm.sqharm[20] = (unsigned long )0;
  sqlstm.sqadto[20] = (unsigned short )0;
  sqlstm.sqtdso[20] = (unsigned short )0;
  sqlstm.sqhstv[21] = (unsigned char  *)&v_markup_ccy;
  sqlstm.sqhstl[21] = (unsigned long )6;
  sqlstm.sqhsts[21] = (         int  )0;
  sqlstm.sqindv[21] = (         short *)&ind_markup_ccy;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt007_error;
}



		fprintf(fp,XLS_NC);

/* create_updatetime */
		v_create_timestamp.arr[v_create_timestamp.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_create_timestamp.arr,PD_MM_LEN,&v_create_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_create_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* last_updatetime */
		v_update_timestamp.arr[v_update_timestamp.len] = '\0';
		if (ind_update_timestamp >= 0 ) {
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_update_timestamp.arr,PD_MM_LEN,&v_update_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_update_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* approval_updatetime */
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		if (ind_approval_timestamp >= 0 ) {
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_timestamp.arr,PD_MM_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';
		fprintf(fp,XLS_FL,v_psp_name.arr);

/* PSP txn id */
		v_psp_tid.arr[v_psp_tid.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_psp_tid.arr);

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_id.arr);

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* sub_Status_desc */
		v_sub_status_desc.arr[v_sub_status_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_sub_status_desc.arr);

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_dm_status_desc.arr);

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* txn_amount */
		if (ind_txn_amount < 0 ) {
			v_txn_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount);

/* net_amount */
		if (ind_net_amount < 0 ) {
			//v_net_amount = 0.0;
			fprintf(fp, XLS_FL, " ");
		} else {
			fprintf(fp,XLS_FL_DOUBLE,v_net_amount);
		}

/* ex_rate */
		if (ind_ex_rate < 0 ) {
			v_ex_rate = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_ex_rate);

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_fee_ccy.arr);

/* fee */
		if (ind_fee < 0 ) {
			//v_fee = 0.0;
			fprintf(fp, XLS_FL, " ");
		} else {
			fprintf(fp,XLS_FL_DOUBLE,v_fee);
		}

/* req_amt_ccy */
		v_req_amt_ccy.arr[v_req_amt_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_req_amt_ccy.arr);

/* requested_amount */
		if (ind_requested_amount < 0 ) {
			v_requested_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_requested_amount);

/* markup_ccy */
		v_markup_ccy.arr[v_markup_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_markup_ccy.arr);

/* markup */
		if (ind_markup < 0 ) {
			v_markup = 0.0;
		} 
		fprintf(fp,XLS_FL_DOUBLE,v_markup);


		fprintf(fp,XLS_EC);
	}
/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt007_error:
DEBUGLOG(("extract_rpt007 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}



int Extract_RPT008(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT008\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt008_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_create_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_create_timestamp;

		/* varchar	v_update_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_update_timestamp;

		/* varchar	v_approval_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_timestamp;

		/* varchar	v_txn_id[PD_TXN_SEQ_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[17]; } v_txn_id;

		/* varchar	v_txn_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_dm_status_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_dm_status_desc;

		/* varchar	v_sub_status_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status_desc;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		double	v_net_amount;
		double	v_ex_rate;
		/* varchar	v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;

		double	v_fee;
		/* varchar	v_req_amt_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_req_amt_ccy;

		double	v_requested_amount;

		short	ind_create_timestamp = -1;
		short	ind_update_timestamp = -1;
		short	ind_approval_timestamp = -1;
		short	ind_txn_id = -1;
		short	ind_txn_code_desc = -1;
		short	ind_merchant_ref = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_dm_status_desc = -1;
		short	ind_sub_status_desc = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_net_amount = -1;
		short	ind_ex_rate = -1;
		short	ind_fee_ccy = -1;
		short	ind_fee = -1;
		short	ind_req_amt_ccy = -1;
		short	ind_requested_amount = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Create Date");
	fprintf(fp,XLS_FL,"Last Update Date");
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Txn Code Desc");
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Merchant Ref #");
	fprintf(fp,XLS_FL,"Substatus Desc");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Txn Amount");
	fprintf(fp,XLS_FL,"Net Amount");
	fprintf(fp,XLS_FL,"Exchange Rate");
	fprintf(fp,XLS_FL,"Fee Currency");
	fprintf(fp,XLS_FL,"Fee");
	fprintf(fp,XLS_FL,"Amount Currency");
	fprintf(fp,XLS_FL,"Requested Amount");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_create_timestamp:ind_create_timestamp,
			:v_update_timestamp:ind_update_timestamp,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_dm_status_desc:ind_dm_status_desc,
			:v_sub_status_desc:ind_sub_status_desc,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_net_amount:ind_net_amount,
			:v_ex_rate:ind_ex_rate,
			:v_fee:ind_fee,
			:v_fee_ccy:ind_fee_ccy,
			:v_requested_amount:ind_requested_amount,
			:v_req_amt_ccy:ind_req_amt_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )403;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_create_timestamp;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_create_timestamp;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_update_timestamp;
  sqlstm.sqhstl[2] = (unsigned long )17;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_update_timestamp;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[3] = (unsigned long )17;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[4] = (unsigned long )19;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_id;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[7] = (unsigned long )18;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[8] = (unsigned long )53;
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_dm_status_desc;
  sqlstm.sqhstl[9] = (unsigned long )53;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_dm_status_desc;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_sub_status_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_sub_status_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[12] = (unsigned long )6;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_net_amount;
  sqlstm.sqhstl[13] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_net_amount;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_ex_rate;
  sqlstm.sqhstl[14] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_ex_rate;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_fee;
  sqlstm.sqhstl[15] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_fee;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
  sqlstm.sqhstv[16] = (unsigned char  *)&v_fee_ccy;
  sqlstm.sqhstl[16] = (unsigned long )6;
  sqlstm.sqhsts[16] = (         int  )0;
  sqlstm.sqindv[16] = (         short *)&ind_fee_ccy;
  sqlstm.sqinds[16] = (         int  )0;
  sqlstm.sqharm[16] = (unsigned long )0;
  sqlstm.sqadto[16] = (unsigned short )0;
  sqlstm.sqtdso[16] = (unsigned short )0;
  sqlstm.sqhstv[17] = (unsigned char  *)&v_requested_amount;
  sqlstm.sqhstl[17] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[17] = (         int  )0;
  sqlstm.sqindv[17] = (         short *)&ind_requested_amount;
  sqlstm.sqinds[17] = (         int  )0;
  sqlstm.sqharm[17] = (unsigned long )0;
  sqlstm.sqadto[17] = (unsigned short )0;
  sqlstm.sqtdso[17] = (unsigned short )0;
  sqlstm.sqhstv[18] = (unsigned char  *)&v_req_amt_ccy;
  sqlstm.sqhstl[18] = (unsigned long )6;
  sqlstm.sqhsts[18] = (         int  )0;
  sqlstm.sqindv[18] = (         short *)&ind_req_amt_ccy;
  sqlstm.sqinds[18] = (         int  )0;
  sqlstm.sqharm[18] = (unsigned long )0;
  sqlstm.sqadto[18] = (unsigned short )0;
  sqlstm.sqtdso[18] = (unsigned short )0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt008_error;
}



		fprintf(fp,XLS_NC);

/* create_updatetime */
		v_create_timestamp.arr[v_create_timestamp.len] = '\0';
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_create_timestamp.arr,PD_MM_LEN,&v_create_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_create_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);

/* last_updatetime */
		v_update_timestamp.arr[v_update_timestamp.len] = '\0';
		if (ind_update_timestamp >= 0 ) {
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_update_timestamp.arr,PD_MM_LEN,&v_update_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_update_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* approval_updatetime */
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		if (ind_approval_timestamp >= 0 ) {
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_timestamp.arr,PD_MM_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_id.arr);

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* merchant_ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* sub_Status_desc */
		v_sub_status_desc.arr[v_sub_status_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_sub_status_desc.arr);

/* Status_desc */
		v_dm_status_desc.arr[v_dm_status_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_dm_status_desc.arr);

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* txn_amount */
		if (ind_txn_amount < 0 ) {
			v_txn_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount);

/* net_amount */
		if (ind_net_amount < 0 ) {
			//v_net_amount = 0.0;
			fprintf(fp, XLS_FL, " ");
		} else {
			fprintf(fp,XLS_FL_DOUBLE,v_net_amount);
		}

/* ex_rate */
		if (ind_ex_rate < 0 ) {
			v_ex_rate = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_ex_rate);

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_fee_ccy.arr);

/* fee */
		if (ind_fee < 0 ) {
			//v_fee = 0.0;
			fprintf(fp, XLS_FL, " ");
		} else {
			fprintf(fp,XLS_FL_DOUBLE,v_fee);
		}

/* req_amt_ccy */
		v_req_amt_ccy.arr[v_req_amt_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_req_amt_ccy.arr);

/* requested_amount */
		if (ind_requested_amount < 0 ) {
			v_requested_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_requested_amount);

		fprintf(fp,XLS_EC);
	}
/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt008_error:
DEBUGLOG(("extract_rpt008 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}



int Extract_RPT009(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT009\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt009_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_service_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_code_desc;

		/* varchar	v_approval_timestamp[PD_DATETIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_timestamp;

		double	v_float_bal;
		double	v_fundin_for_payout;
		double	v_current_bal;
		double	v_reserved_bal;
		double	v_holdback_bal;
		double	v_merchant_bal;
		/* varchar	v_mb_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_mb_ccy;

		/* varchar	v_ds_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_ds_desc;


		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_service_code_desc = -1;
		short	ind_approval_timestamp = -1;
		short	ind_float_bal;
		short	ind_fundin_for_payout;
		short	ind_current_bal;
		short	ind_reserved_bal;
		short	ind_holdback_bal;
		short	ind_merchant_bal;
		short	ind_mb_ccy = -1;
		short	ind_ds_desc = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Service Desc");
	fprintf(fp,XLS_FL,"Approval Date");
	/*fprintf(fp,XLS_FL,"Current Balance");
	fprintf(fp,XLS_FL,"Total Float");
	fprintf(fp,XLS_FL,"Total Reserved Amount");
	fprintf(fp,XLS_FL,"Total Hold");
	fprintf(fp,XLS_FL,"Settlement in Transit");*/
	fprintf(fp,XLS_FL,"Float Balance");
	fprintf(fp,XLS_FL,"Fund In for Payout");
	fprintf(fp,XLS_FL,"Current Balance");
	fprintf(fp,XLS_FL,"Reserved Balance");
	fprintf(fp,XLS_FL,"Holdback Balance");
	fprintf(fp,XLS_FL,"Merchant Balance");
	fprintf(fp,XLS_FL,"Currency");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_service_code_desc:ind_service_code_desc,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_float_bal:ind_float_bal,
			:v_fundin_for_payout:ind_fundin_for_payout,
			:v_current_bal:ind_current_bal,
			:v_reserved_bal:ind_reserved_bal,
			:v_holdback_bal:ind_holdback_bal,
			:v_merchant_bal:ind_merchant_bal,
			:v_mb_ccy:ind_mb_ccy,
			:v_ds_desc:ind_ds_desc; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )494;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[1] = (unsigned long )18;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[2] = (unsigned long )53;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_code_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_code_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[4] = (unsigned long )17;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_float_bal;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_float_bal;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_fundin_for_payout;
  sqlstm.sqhstl[6] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_fundin_for_payout;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_current_bal;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_current_bal;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_reserved_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_reserved_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_holdback_bal;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_holdback_bal;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_merchant_bal;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_merchant_bal;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_mb_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_mb_ccy;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_ds_desc;
  sqlstm.sqhstl[12] = (unsigned long )53;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_ds_desc;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt009_error;
}



		fprintf(fp,XLS_NC);

/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_id.arr);

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* service_desc */
		v_service_code_desc.arr[v_service_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_service_code_desc.arr);

/* approval_updatetime */
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		if (ind_approval_timestamp >= 0 ) {
		fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_timestamp.arr,PD_MM_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_timestamp.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* float_bal */
		if (ind_float_bal < 0)
			v_float_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_float_bal);

/* fundin_for_payout */
		if (ind_fundin_for_payout < 0)
			v_fundin_for_payout = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_fundin_for_payout);

/* current_bal */
		if (ind_current_bal < 0)
			v_current_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_current_bal);

/* reserved_bal */
		if (ind_reserved_bal < 0)
			v_reserved_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_reserved_bal);

/* holdback_bal */
		if (ind_holdback_bal < 0)
			v_holdback_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_holdback_bal);

/* merchant_bal */
		if (ind_merchant_bal < 0)
			v_merchant_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_merchant_bal);

/* mb_ccy */
		v_mb_ccy.arr[v_mb_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_mb_ccy.arr);

/* status */
		v_ds_desc.arr[v_ds_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_ds_desc.arr);

		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt009_error:
DEBUGLOG(("extract_rpt009 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT010(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT010\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt010_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_approval_datetime[PD_DATE_LEN + PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[15]; } v_approval_datetime;

		/* varchar	v_txn_id[PD_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_merchant_id[PD_MERCHANT_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[16]; } v_merchant_id;

		/* varchar	v_merchant_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_name;

		/* varchar	v_txn_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar	v_status[PD_NAME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		/* varchar	v_sub_status[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_sub_status;

		double	v_txn_amount;
		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_fee_amount;
		/* varchar	v_fee_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_fee_ccy;
	

		short	ind_approval_datetime = -1;
		short	ind_txn_id = -1;
		short	ind_merchant_id = -1;
		short	ind_merchant_name = -1;
		short	ind_txn_code_desc = -1;
		short	ind_status = -1;
		short	ind_sub_status = -1;
		short	ind_txn_amount = -1;
		short	ind_txn_ccy = -1;
		short	ind_fee_amount = -1;
		short	ind_fee_ccy = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Merchant ID");
	fprintf(fp,XLS_FL,"Merchant Name");
	fprintf(fp,XLS_FL,"Txn Type");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Sub Status");
	fprintf(fp,XLS_FL,"Txn Currency");
	fprintf(fp,XLS_FL,"Transaction Amount");
	fprintf(fp,XLS_FL,"Fee Currency");
	fprintf(fp,XLS_FL,"Fee Amount");

	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_approval_datetime:ind_approval_datetime,
			:v_txn_id:ind_txn_id,
			:v_merchant_id:ind_merchant_id,
			:v_merchant_name:ind_merchant_name,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_status:ind_status,
			:v_sub_status:ind_sub_status,
			:v_txn_amount:ind_txn_amount,
			:v_txn_ccy:ind_txn_ccy,
			:v_fee_amount:ind_fee_amount,
			:v_fee_ccy:ind_fee_ccy; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )561;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_approval_datetime;
  sqlstm.sqhstl[1] = (unsigned long )17;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_approval_datetime;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_merchant_id;
  sqlstm.sqhstl[3] = (unsigned long )18;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_merchant_id;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_merchant_name;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_merchant_name;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[5] = (unsigned long )53;
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_code_desc;
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
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[9] = (unsigned long )6;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_fee_amount;
  sqlstm.sqhstl[10] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_fee_amount;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_fee_ccy;
  sqlstm.sqhstl[11] = (unsigned long )6;
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_fee_ccy;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt010_error;
}



		fprintf(fp,XLS_NC);

/* approval datetime */
		v_approval_datetime.arr[v_approval_datetime.len] = '\0';
		if (ind_approval_datetime >= 0 ) {
			fprintf(fp,XLS_FL_DATE,PD_YYYY_LEN,v_approval_datetime.arr,PD_MM_LEN,&v_approval_datetime.arr[PD_YYYY_LEN],PD_DD_LEN,&v_approval_datetime.arr[PD_YYYY_LEN + PD_MM_LEN]);
		}
		else {
			fprintf(fp,XLS_FL," ");
		}

/* txn_id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);


/* merchant_id */
		v_merchant_id.arr[v_merchant_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_id.arr);

/* merchant_name */
		v_merchant_name.arr[v_merchant_name.len] = '\0';
		fprintf(fp,XLS_FL,v_merchant_name.arr);

/* txn_code_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);

/* status */
		v_status.arr[v_status.len] = '\0';
		fprintf(fp,XLS_FL,v_status.arr);

/* sub_status */
		v_sub_status.arr[v_sub_status.len] = '\0';
		fprintf(fp,XLS_FL,v_sub_status.arr);

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* txn_amount */
		if (ind_txn_amount < 0)
			v_txn_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount);

/* fee_ccy */
		v_fee_ccy.arr[v_fee_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_fee_ccy.arr);

/* fee_amount */
		if (ind_fee_amount < 0)
			v_fee_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_fee_amount);


		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt010_error:
DEBUGLOG(("extract_rpt010 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}


int Extract_RPT011(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT011\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt011_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 


		/* varchar	v_txn_id[PD_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar	v_txn_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_txn_date;

		/* varchar	v_psp_id[PD_PSP_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[11]; } v_psp_id;

		/* varchar	v_psp_name[PD_PSP_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_psp_name;

		/* varchar	v_txn_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_ccy;

		double	v_txn_amount;
		double	v_service_fee;

		short	ind_txn_id = -1;
		short	ind_txn_code = -1;
		short	ind_txn_code_desc = -1;
		short	ind_txn_date = -1;
		short	ind_psp_id = -1;
		short	ind_psp_name = -1;
		short	ind_txn_ccy = -1;
		short	ind_txn_amount = -1;
		short	ind_service_fee = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Txn Code");
	fprintf(fp,XLS_FL,"Txn Date");
	fprintf(fp,XLS_FL,"PSP ID");
	fprintf(fp,XLS_FL,"PSP Name");
	fprintf(fp,XLS_FL,"Currency");
	fprintf(fp,XLS_FL,"Txn Amount");
	fprintf(fp,XLS_FL,"Service Fee");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_id:ind_txn_id,
			:v_txn_code:ind_txn_code,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_txn_date:ind_txn_date,
			:v_psp_id:ind_psp_id,
			:v_psp_name:ind_psp_name,
			:v_txn_ccy:ind_txn_ccy,
			:v_txn_amount:ind_txn_amount,
			:v_service_fee:ind_service_fee; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )624;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_txn_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_date;
  sqlstm.sqhstl[4] = (unsigned long )11;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_date;
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
  sqlstm.sqhstv[6] = (unsigned char  *)&v_psp_name;
  sqlstm.sqhstl[6] = (unsigned long )53;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_psp_name;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_txn_ccy;
  sqlstm.sqhstl[7] = (unsigned long )6;
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_txn_ccy;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_txn_amount;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_txn_amount;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_service_fee;
  sqlstm.sqhstl[9] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_service_fee;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt011_error;
}



/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';

/* txn_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);

/*txn date */
		v_txn_date.arr[v_txn_date.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_date.arr);

/* psp id */
		v_psp_id.arr[v_psp_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_psp_id.arr);

/* psp_name */
		v_psp_name.arr[v_psp_name.len] = '\0';
		fprintf(fp,XLS_FL,v_psp_name.arr);

/* txn_ccy */
		v_txn_ccy.arr[v_txn_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_ccy.arr);

/* txn_amount */
		if (ind_txn_amount < 0) {
			v_txn_amount = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_txn_amount);

/* Service_fee */
		if (ind_service_fee < 0) {
			v_service_fee = 0.0;
		}
		fprintf(fp,XLS_FL_DOUBLE,v_service_fee);

		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);


DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt011_error:
DEBUGLOG(("extract_rpt011 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}


int Extract_RPT013(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
	
DEBUGLOG(("Extract_RPT013\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt013_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_txn_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		/* varchar	v_service_code[PD_SERVICE_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_service_code;

		/* varchar	v_service_name[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_service_name;

		/* varchar	v_status[PD_NAME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_status;

		int	v_txn_count;

		short	ind_txn_code_desc = -1;
		short	ind_service_code = -1;
		short	ind_service_name = -1;
		short	ind_status = -1;
		short	ind_txn_count = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn Type");
	fprintf(fp,XLS_FL,"Service Name");
	fprintf(fp,XLS_FL,"Status");
	fprintf(fp,XLS_FL,"Transaction Count");

	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_code_desc:ind_txn_code_desc,
			:v_service_code:ind_service_code,
			:v_service_name:ind_service_name,
			:v_status:ind_status,
			:v_txn_count:ind_txn_count; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )679;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[1] = (unsigned long )53;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[1] = (         int  )0;
  sqlstm.sqharm[1] = (unsigned long )0;
  sqlstm.sqadto[1] = (unsigned short )0;
  sqlstm.sqtdso[1] = (unsigned short )0;
  sqlstm.sqhstv[2] = (unsigned char  *)&v_service_code;
  sqlstm.sqhstl[2] = (unsigned long )6;
  sqlstm.sqhsts[2] = (         int  )0;
  sqlstm.sqindv[2] = (         short *)&ind_service_code;
  sqlstm.sqinds[2] = (         int  )0;
  sqlstm.sqharm[2] = (unsigned long )0;
  sqlstm.sqadto[2] = (unsigned short )0;
  sqlstm.sqtdso[2] = (unsigned short )0;
  sqlstm.sqhstv[3] = (unsigned char  *)&v_service_name;
  sqlstm.sqhstl[3] = (unsigned long )53;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_service_name;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_status;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_status;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_txn_count;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_txn_count;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt013_error;
}

 

		fprintf(fp,XLS_NC);

/* txn_code_desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_code_desc.arr);

/* service name*/
		v_service_name.arr[v_service_name.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_service_name.arr);

/* status */
		v_status.arr[v_status.len] = '\0';
		fprintf(fp,XLS_FL,v_status.arr);

/* txn_count */
		if (ind_txn_count < 0) {
			v_txn_count = 0;
		}
		fprintf(fp, XLS_FL_INT, v_txn_count);


		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt013_error:
DEBUGLOG(("extract_rpt013 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT015(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
DEBUGLOG(("Extract_RPT015\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt015_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_txn_id[PD_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_code_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		double	v_open_bal;
		/*double	v_current_bal;*/
		/* varchar	v_txn_element_type[PD_TXN_ELEMENT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_txn_element_type;

		/* varchar	v_txn_element_type_desc[PD_DESC_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_element_type_desc;

		int	v_exec_seq;
		double	v_amount;
		/* varchar	v_ccy[PD_CCY_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		double	v_bal;
		/* varchar	v_approval_timestamp[PD_TIME_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_approval_timestamp;

		/* varchar	v_approval_date[PD_DATE_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

		/* varchar	v_void_txn_id[PD_TXN_ID_LEN + 1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_void_txn_id;


		short	ind_txn_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_txn_code = -1;
		short	ind_txn_code_desc = -1;
		short	ind_open_bal = -1;
		/*short	ind_current_bal = -1;*/
		short	ind_txn_element_type = -1;
		short	ind_txn_element_type_desc = -1;
		short	ind_exec_seq = -1;
		short	ind_amount = -1;
		short	ind_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_bal = -1;
		short	ind_approval_timestamp= -1;
		short	ind_approval_date = -1;
		short	ind_void_txn_id = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Refund Txn ID");
	fprintf(fp,XLS_FL,"Merchant Ref");
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Opening Bal");
	/*fprintf(fp,XLS_FL,"Current Bal");*/
	fprintf(fp,XLS_FL,"Txn Element");
	fprintf(fp,XLS_FL,"Amount");
	fprintf(fp,XLS_FL,"Currency");
	fprintf(fp,XLS_FL,"Amount Type");
	fprintf(fp,XLS_FL,"Bal");
	fprintf(fp,XLS_FL,"Approval Timestamp");
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_code:ind_txn_code,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_open_bal:ind_open_bal,
			:v_amt_type:ind_amt_type,
			:v_amount:ind_amount,
			:v_bal:ind_bal,
			/o:v_current_bal:ind_current_bal,o/
			:v_txn_element_type:ind_txn_element_type,
			:v_txn_element_type_desc:ind_txn_element_type_desc,
			:v_exec_seq:ind_exec_seq,
			:v_ccy:ind_ccy,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_approval_date:ind_approval_date,
			:v_void_txn_id:ind_void_txn_id; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )718;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_open_bal;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_amt_type;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_amount;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_element_type;
  sqlstm.sqhstl[9] = (unsigned long )7;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_txn_element_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_element_type_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_txn_element_type_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_exec_seq;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_exec_seq;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[12] = (unsigned long )6;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_ccy;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_approval_date;
  sqlstm.sqinds[14] = (         int  )0;
  sqlstm.sqharm[14] = (unsigned long )0;
  sqlstm.sqadto[14] = (unsigned short )0;
  sqlstm.sqtdso[14] = (unsigned short )0;
  sqlstm.sqhstv[15] = (unsigned char  *)&v_void_txn_id;
  sqlstm.sqhstl[15] = (unsigned long )23;
  sqlstm.sqhsts[15] = (         int  )0;
  sqlstm.sqindv[15] = (         short *)&ind_void_txn_id;
  sqlstm.sqinds[15] = (         int  )0;
  sqlstm.sqharm[15] = (unsigned long )0;
  sqlstm.sqadto[15] = (unsigned short )0;
  sqlstm.sqtdso[15] = (unsigned short )0;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt015_error;
}



		fprintf(fp,XLS_NC);
/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* Void txn id */
		v_void_txn_id.arr[v_void_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_void_txn_id.arr);

/* merchant ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';
/* txn code desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);
/*open bal */
		if (ind_open_bal < 0) 
			v_open_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_open_bal);

/*current bal 
		if (ind_current_bal < 0) 
			v_current_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_current_bal);
*/
/*txn element */
		v_txn_element_type.arr[v_txn_element_type.len] = '\0';

/*txn element desc */
		v_txn_element_type_desc.arr[v_txn_element_type_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_element_type_desc.arr);

/*exec seq */
		if (ind_exec_seq < 0) 
			v_exec_seq = 0;
/* amount */
		if (ind_amount < 0)
			v_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_amount);

/*ccy */
		v_ccy.arr[v_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_ccy.arr);

/*amt_type */
		v_amt_type.arr[v_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_amt_type.arr);

/*bal */
		if (ind_bal < 0) 
			v_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_bal);
/* approval timestamp*/
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_timestamp.arr);
		
		fprintf(fp,XLS_EC);

/* approval date */
		v_approval_date.arr[v_approval_date.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_date.arr);
		
		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt015_error:
DEBUGLOG(("extract_rpt015 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT016(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
DEBUGLOG(("Extract_RPT016\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt016_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		double	v_open_bal;
		/*double	v_current_bal;*/
		/* varchar	v_txn_element_type[PD_TXN_ELEMENT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_txn_element_type;

		/* varchar	v_txn_element_type_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_element_type_desc;

		int	v_exec_seq;
		double	v_amount;
		/* varchar	v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		double	v_bal;
		/* varchar	v_approval_timestamp[PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_approval_timestamp;

		/* varchar	v_approval_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;

		/*varchar v_void_txn_id[PD_TXN_ID_LEN +1];*/

		short	ind_txn_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_txn_code = -1;
		short	ind_txn_code_desc = -1;
		short	ind_open_bal = -1;
		/*short	ind_current_bal = -1;*/
		short	ind_txn_element_type = -1;
		short	ind_txn_element_type_desc = -1;
		short	ind_exec_seq = -1;
		short	ind_amount = -1;
		short	ind_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_bal = -1;
		short	ind_approval_timestamp= -1;
		short	ind_approval_date = -1;
		/*short	ind_void_txn_id = -1;*/

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn ID");
	/*fprintf(fp,XLS_FL,"Refund Txn ID");*/
	fprintf(fp,XLS_FL,"Merchant Ref");
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Opening Bal");
	/*fprintf(fp,XLS_FL,"Current Bal");*/
	fprintf(fp,XLS_FL,"Txn Element");
	fprintf(fp,XLS_FL,"Amount");
	fprintf(fp,XLS_FL,"Currency");
	fprintf(fp,XLS_FL,"Amount Type");
	fprintf(fp,XLS_FL,"Bal");
	fprintf(fp,XLS_FL,"Approval Timestamp");
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_code:ind_txn_code,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_open_bal:ind_open_bal,
			:v_amt_type:ind_amt_type,
			:v_amount:ind_amount,
			:v_bal:ind_bal,
			/o:v_current_bal:ind_current_bal,o/
			:v_txn_element_type:ind_txn_element_type,
			:v_txn_element_type_desc:ind_txn_element_type_desc,
			:v_exec_seq:ind_exec_seq,
			:v_ccy:ind_ccy,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_approval_date:ind_approval_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )797;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_open_bal;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_amt_type;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_amount;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_element_type;
  sqlstm.sqhstl[9] = (unsigned long )7;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_txn_element_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_element_type_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_txn_element_type_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_exec_seq;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_exec_seq;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[12] = (unsigned long )6;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_ccy;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_approval_date;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt016_error;
}


			/*:v_void_txn_id:ind_void_txn_id;*/

		fprintf(fp,XLS_NC);
/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* Void txn id 
		v_void_txn_id.arr[v_void_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_void_txn_id.arr);*/

/* merchant ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';
/* txn code desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);
/*open bal */
		if (ind_open_bal < 0) 
			v_open_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_open_bal);

/*current bal 
		if (ind_current_bal < 0) 
			v_current_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_current_bal);
*/
/*txn element */
		v_txn_element_type.arr[v_txn_element_type.len] = '\0';

/*txn element desc */
		v_txn_element_type_desc.arr[v_txn_element_type_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_element_type_desc.arr);

/*exec seq */
		if (ind_exec_seq < 0) 
			v_exec_seq = 0;
/* amount */
		if (ind_amount < 0)
			v_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_amount);

/*ccy */
		v_ccy.arr[v_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_ccy.arr);

/*amt_type */
		v_amt_type.arr[v_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_amt_type.arr);

/*bal */
		if (ind_bal < 0) 
			v_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_bal);
/* approval timestamp*/
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_timestamp.arr);
		
		fprintf(fp,XLS_EC);

/* approval date */
		v_approval_date.arr[v_approval_date.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_date.arr);
		
		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt016_error:
DEBUGLOG(("extract_rpt016 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}

int Extract_RPT017(FILE* fp, SQL_CURSOR c_input_cursor)
{
	int	iRet = SUCCESS;
DEBUGLOG(("Extract_RPT017\n"));
	/* EXEC SQL WHENEVER SQLERROR GOTO extract_rpt017_error; */ 

	/* EXEC SQL WHENEVER NOTFOUND CONTINUE; */ 


	/* EXEC SQL BEGIN DECLARE SECTION; */ 

		/* varchar	v_txn_id[PD_TXN_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[21]; } v_txn_id;

		/* varchar	v_merchant_ref[PD_MERCHANT_REF_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_merchant_ref;

		/* varchar	v_txn_code[PD_TXN_CODE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_txn_code;

		/* varchar	v_txn_code_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_code_desc;

		double	v_open_bal;
		/*double	v_current_bal;*/
		/* varchar	v_txn_element_type[PD_TXN_ELEMENT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[5]; } v_txn_element_type;

		/* varchar	v_txn_element_type_desc[PD_DESC_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[51]; } v_txn_element_type_desc;

		int	v_exec_seq;
		double	v_amount;
		/* varchar	v_ccy[PD_CCY_ID_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[4]; } v_ccy;

		/* varchar	v_amt_type[PD_AMT_TYPE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[3]; } v_amt_type;

		double	v_bal;
		/* varchar	v_approval_timestamp[PD_TIME_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[7]; } v_approval_timestamp;

		/* varchar	v_approval_date[PD_DATE_LEN +1]; */ 
struct { unsigned short len; unsigned char arr[9]; } v_approval_date;


		short	ind_txn_id = -1;
		short	ind_merchant_ref = -1;
		short	ind_txn_code = -1;
		short	ind_txn_code_desc = -1;
		short	ind_open_bal = -1;
		/*short	ind_current_bal = -1;*/
		short	ind_txn_element_type = -1;
		short	ind_txn_element_type_desc = -1;
		short	ind_exec_seq = -1;
		short	ind_amount = -1;
		short	ind_ccy = -1;
		short	ind_amt_type = -1;
		short	ind_bal = -1;
		short	ind_approval_timestamp= -1;
		short	ind_approval_date = -1;

	/* EXEC SQL END DECLARE SECTION; */ 


/* hd */	
	fprintf(fp,XLS_HD);
	fprintf(fp,XLS_NC);
	fprintf(fp,XLS_FL,"Txn ID");
	fprintf(fp,XLS_FL,"Merchant Ref");
	fprintf(fp,XLS_FL,"Txn Desc");
	fprintf(fp,XLS_FL,"Opening Bal");
	/*fprintf(fp,XLS_FL,"Current Bal");*/
	fprintf(fp,XLS_FL,"Txn Element");
	fprintf(fp,XLS_FL,"Amount");
	fprintf(fp,XLS_FL,"Currency");
	fprintf(fp,XLS_FL,"Amount Type");
	fprintf(fp,XLS_FL,"Bal");
	fprintf(fp,XLS_FL,"Approval Timestamp");
	fprintf(fp,XLS_FL,"Approval Date");
	fprintf(fp,XLS_EC);

/* style */	
	fprintf(fp,XLS_SY);
	for (;;) {
		/* EXEC SQL WHENEVER NOTFOUND DO break; */ 

		/* EXEC SQL FETCH :c_input_cursor
		INTO
			:v_txn_id:ind_txn_id,
			:v_merchant_ref:ind_merchant_ref,
			:v_txn_code:ind_txn_code,
			:v_txn_code_desc:ind_txn_code_desc,
			:v_open_bal:ind_open_bal,
			:v_amt_type:ind_amt_type,
			:v_amount:ind_amount,
			:v_bal:ind_bal,
			/o:v_current_bal:ind_current_bal,o/
			:v_txn_element_type:ind_txn_element_type,
			:v_txn_element_type_desc:ind_txn_element_type_desc,
			:v_exec_seq:ind_exec_seq,
			:v_ccy:ind_ccy,
			:v_approval_timestamp:ind_approval_timestamp,
			:v_approval_date:ind_approval_date; */ 

{
  struct sqlexd sqlstm;
  sqlstm.sqlvsn = 12;
  sqlstm.arrsiz = 24;
  sqlstm.sqladtp = &sqladt;
  sqlstm.sqltdsp = &sqltds;
  sqlstm.iters = (unsigned int  )1;
  sqlstm.offset = (unsigned int  )872;
  sqlstm.selerr = (unsigned short)1;
  sqlstm.cud = sqlcud0;
  sqlstm.sqlest = (unsigned char  *)&sqlca;
  sqlstm.sqlety = (unsigned short)4352;
  sqlstm.occurs = (unsigned int  )0;
  sqlstm.sqfoff = (         int )0;
  sqlstm.sqfmod = (unsigned int )2;
  sqlstm.sqhstv[0] = (unsigned char  *)&c_input_cursor;
  sqlstm.sqhstl[0] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[0] = (         int  )0;
  sqlstm.sqindv[0] = (         short *)0;
  sqlstm.sqinds[0] = (         int  )0;
  sqlstm.sqharm[0] = (unsigned long )0;
  sqlstm.sqadto[0] = (unsigned short )0;
  sqlstm.sqtdso[0] = (unsigned short )0;
  sqlstm.sqhstv[1] = (unsigned char  *)&v_txn_id;
  sqlstm.sqhstl[1] = (unsigned long )23;
  sqlstm.sqhsts[1] = (         int  )0;
  sqlstm.sqindv[1] = (         short *)&ind_txn_id;
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
  sqlstm.sqhstv[3] = (unsigned char  *)&v_txn_code;
  sqlstm.sqhstl[3] = (unsigned long )6;
  sqlstm.sqhsts[3] = (         int  )0;
  sqlstm.sqindv[3] = (         short *)&ind_txn_code;
  sqlstm.sqinds[3] = (         int  )0;
  sqlstm.sqharm[3] = (unsigned long )0;
  sqlstm.sqadto[3] = (unsigned short )0;
  sqlstm.sqtdso[3] = (unsigned short )0;
  sqlstm.sqhstv[4] = (unsigned char  *)&v_txn_code_desc;
  sqlstm.sqhstl[4] = (unsigned long )53;
  sqlstm.sqhsts[4] = (         int  )0;
  sqlstm.sqindv[4] = (         short *)&ind_txn_code_desc;
  sqlstm.sqinds[4] = (         int  )0;
  sqlstm.sqharm[4] = (unsigned long )0;
  sqlstm.sqadto[4] = (unsigned short )0;
  sqlstm.sqtdso[4] = (unsigned short )0;
  sqlstm.sqhstv[5] = (unsigned char  *)&v_open_bal;
  sqlstm.sqhstl[5] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[5] = (         int  )0;
  sqlstm.sqindv[5] = (         short *)&ind_open_bal;
  sqlstm.sqinds[5] = (         int  )0;
  sqlstm.sqharm[5] = (unsigned long )0;
  sqlstm.sqadto[5] = (unsigned short )0;
  sqlstm.sqtdso[5] = (unsigned short )0;
  sqlstm.sqhstv[6] = (unsigned char  *)&v_amt_type;
  sqlstm.sqhstl[6] = (unsigned long )5;
  sqlstm.sqhsts[6] = (         int  )0;
  sqlstm.sqindv[6] = (         short *)&ind_amt_type;
  sqlstm.sqinds[6] = (         int  )0;
  sqlstm.sqharm[6] = (unsigned long )0;
  sqlstm.sqadto[6] = (unsigned short )0;
  sqlstm.sqtdso[6] = (unsigned short )0;
  sqlstm.sqhstv[7] = (unsigned char  *)&v_amount;
  sqlstm.sqhstl[7] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[7] = (         int  )0;
  sqlstm.sqindv[7] = (         short *)&ind_amount;
  sqlstm.sqinds[7] = (         int  )0;
  sqlstm.sqharm[7] = (unsigned long )0;
  sqlstm.sqadto[7] = (unsigned short )0;
  sqlstm.sqtdso[7] = (unsigned short )0;
  sqlstm.sqhstv[8] = (unsigned char  *)&v_bal;
  sqlstm.sqhstl[8] = (unsigned long )sizeof(double);
  sqlstm.sqhsts[8] = (         int  )0;
  sqlstm.sqindv[8] = (         short *)&ind_bal;
  sqlstm.sqinds[8] = (         int  )0;
  sqlstm.sqharm[8] = (unsigned long )0;
  sqlstm.sqadto[8] = (unsigned short )0;
  sqlstm.sqtdso[8] = (unsigned short )0;
  sqlstm.sqhstv[9] = (unsigned char  *)&v_txn_element_type;
  sqlstm.sqhstl[9] = (unsigned long )7;
  sqlstm.sqhsts[9] = (         int  )0;
  sqlstm.sqindv[9] = (         short *)&ind_txn_element_type;
  sqlstm.sqinds[9] = (         int  )0;
  sqlstm.sqharm[9] = (unsigned long )0;
  sqlstm.sqadto[9] = (unsigned short )0;
  sqlstm.sqtdso[9] = (unsigned short )0;
  sqlstm.sqhstv[10] = (unsigned char  *)&v_txn_element_type_desc;
  sqlstm.sqhstl[10] = (unsigned long )53;
  sqlstm.sqhsts[10] = (         int  )0;
  sqlstm.sqindv[10] = (         short *)&ind_txn_element_type_desc;
  sqlstm.sqinds[10] = (         int  )0;
  sqlstm.sqharm[10] = (unsigned long )0;
  sqlstm.sqadto[10] = (unsigned short )0;
  sqlstm.sqtdso[10] = (unsigned short )0;
  sqlstm.sqhstv[11] = (unsigned char  *)&v_exec_seq;
  sqlstm.sqhstl[11] = (unsigned long )sizeof(int);
  sqlstm.sqhsts[11] = (         int  )0;
  sqlstm.sqindv[11] = (         short *)&ind_exec_seq;
  sqlstm.sqinds[11] = (         int  )0;
  sqlstm.sqharm[11] = (unsigned long )0;
  sqlstm.sqadto[11] = (unsigned short )0;
  sqlstm.sqtdso[11] = (unsigned short )0;
  sqlstm.sqhstv[12] = (unsigned char  *)&v_ccy;
  sqlstm.sqhstl[12] = (unsigned long )6;
  sqlstm.sqhsts[12] = (         int  )0;
  sqlstm.sqindv[12] = (         short *)&ind_ccy;
  sqlstm.sqinds[12] = (         int  )0;
  sqlstm.sqharm[12] = (unsigned long )0;
  sqlstm.sqadto[12] = (unsigned short )0;
  sqlstm.sqtdso[12] = (unsigned short )0;
  sqlstm.sqhstv[13] = (unsigned char  *)&v_approval_timestamp;
  sqlstm.sqhstl[13] = (unsigned long )9;
  sqlstm.sqhsts[13] = (         int  )0;
  sqlstm.sqindv[13] = (         short *)&ind_approval_timestamp;
  sqlstm.sqinds[13] = (         int  )0;
  sqlstm.sqharm[13] = (unsigned long )0;
  sqlstm.sqadto[13] = (unsigned short )0;
  sqlstm.sqtdso[13] = (unsigned short )0;
  sqlstm.sqhstv[14] = (unsigned char  *)&v_approval_date;
  sqlstm.sqhstl[14] = (unsigned long )11;
  sqlstm.sqhsts[14] = (         int  )0;
  sqlstm.sqindv[14] = (         short *)&ind_approval_date;
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
  if (sqlca.sqlcode == 1403) break;
  if (sqlca.sqlcode < 0) goto extract_rpt017_error;
}



		fprintf(fp,XLS_NC);
/* txn id */
		v_txn_id.arr[v_txn_id.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_txn_id.arr);

/* merchant ref */
		v_merchant_ref.arr[v_merchant_ref.len] = '\0';
		fprintf(fp,XLS_FL_TEXT,v_merchant_ref.arr);

/* txn code */
		v_txn_code.arr[v_txn_code.len] = '\0';
/* txn code desc */
		v_txn_code_desc.arr[v_txn_code_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_code_desc.arr);
/*open bal */
		if (ind_open_bal < 0) 
			v_open_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_open_bal);

/*current bal 
		if (ind_current_bal < 0) 
			v_current_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_current_bal);
*/
/*txn element */
		v_txn_element_type.arr[v_txn_element_type.len] = '\0';

/*txn element desc */
		v_txn_element_type_desc.arr[v_txn_element_type_desc.len] = '\0';
		fprintf(fp,XLS_FL,v_txn_element_type_desc.arr);

/*exec seq */
		if (ind_exec_seq < 0) 
			v_exec_seq = 0;
/* amount */
		if (ind_amount < 0)
			v_amount = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_amount);

/*ccy */
		v_ccy.arr[v_ccy.len] = '\0';
		fprintf(fp,XLS_FL,v_ccy.arr);

/*amt_type */
		v_amt_type.arr[v_amt_type.len] = '\0';
		fprintf(fp,XLS_FL,v_amt_type.arr);

/*bal */
		if (ind_bal < 0) 
			v_bal = 0.0;
		fprintf(fp,XLS_FL_DOUBLE,v_bal);
/* approval timestamp*/
		v_approval_timestamp.arr[v_approval_timestamp.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_timestamp.arr);
		
		fprintf(fp,XLS_EC);

/* approval date */
		v_approval_date.arr[v_approval_date.len] = '\0';
		fprintf(fp,XLS_FL,v_approval_date.arr);
		
		fprintf(fp,XLS_EC);
	}

/* tailer */
	fprintf(fp,XLS_TR);

DEBUGLOG(("iRet = [%d]\n",iRet));
	return iRet;
extract_rpt017_error:
DEBUGLOG(("extract_rpt017 code %d\n", sqlca.sqlcode));
DEBUGLOG(("\n%.*s\n", sqlca.sqlerrm.sqlerrml, sqlca.sqlerrm.sqlerrmc));
	/* EXEC SQL WHENEVER SQLERROR CONTINUE; */ 

	return FAILURE;
}
